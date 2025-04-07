#include "audio_wrappers.h"
#include "data/audio.h"

#include "gba.h"
#include "macros.h"

extern void call_soundcode_a(void);
extern void call_soundcode_b(void);
extern void call_soundcode_c(void);

/**
 * @brief 2564 | 294 | Initializes the audio
 * 
 */
void InitializeAudio(void)
{
    vu16 zero;
    u8 i;

    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    write16(REG_IE, read16(REG_IE) | IF_DMA2);
    write8(REG_SOUNDCNT_X, 0x80); // Enable PSG and FIFO
    write16(REG_SOUNDCNT_H, 0xA90E); // 100% volume, reset and enable/disable DMA sound A right/left and DMA sound B left/right

    write8(REG_SOUNDBIAS + 1, (read8(REG_SOUNDBIAS + 1) & 0x3F) | 0x40);

    write8(REG_SOUND1CNT_H + 1, HIGH_BYTE(SOUNDCNT_ENVELOPE_INCREASE));
    write8(REG_SOUND1CNT_X + 1, HIGH_BYTE(SOUNDCNT_RESTART_SOUND));
    write8(REG_SOUND2CNT_L + 1, HIGH_BYTE(SOUNDCNT_ENVELOPE_INCREASE));
    write8(REG_SOUND2CNT_H + 1, HIGH_BYTE(SOUNDCNT_RESTART_SOUND));
    write8(REG_SOUND4CNT_L + 1, HIGH_BYTE(SOUNDCNT_ENVELOPE_INCREASE));
    write8(REG_SOUND4CNT_H + 1, HIGH_BYTE(SOUNDCNT_RESTART_SOUND));

    write8(REG_SOUND3CNT_L, 0x0);
    write8(REG_SOUNDCNT_L, 0x77); // Sound 1-4 master volume left/right 100%

    gSoundCodeAPointer = (SoundCodeAFunc_T)(gSoundCodeA + 1);
    DMA_SET(3, call_soundcode_a, gSoundCodeA, C_32_2_16(DMA_ENABLE, sizeof(gSoundCodeA) / 2));

    gSoundCodeBPointer = (SoundCodeBFunc_T)(gSoundCodeB + 1);
    DMA_SET(3, call_soundcode_b, gSoundCodeB, C_32_2_16(DMA_ENABLE, sizeof(gSoundCodeB) / 2));

    gSoundCodeCPointer = (SoundCodeCFunc_T)(gSoundCodeC + 1);
    DMA_SET(3, call_soundcode_c, gSoundCodeC, C_32_2_16(DMA_ENABLE, sizeof(gSoundCodeC) / 2));

    zero = 0;
    DMA_SET(3, &zero, &gMusicInfo, C_32_2_16((DMA_ENABLE | DMA_SRC_FIXED), 0xE));

    gMusicInfo.unk_9 = (u8)gUnk_Audio0x64;

    for (i = 0; i < ARRAY_SIZE(gPsgSounds); i++)
    {
        zero = 0;
        DMA_SET(3, &zero, &gPsgSounds[i], C_32_2_16((DMA_ENABLE | DMA_SRC_FIXED), sizeof(struct PSGSoundData) / 2));
    }

    for (i = 0; i < (u16)gNumMusicPlayers; i++)
    {
        zero = 0;
        DMA_SET(3, &zero, sMusicTrackDataRom[i].pTrack, C_32_2_16((DMA_ENABLE | DMA_SRC_FIXED), 0x16));
    }

    for (i = 0; i < (u16)gNumMusicPlayers; i++)
    {
        sMusicTrackDataRom[i].pTrack->pVariables = sMusicTrackDataRom[i].pVariables;
        sMusicTrackDataRom[i].pTrack->maxAmountOfTracks = sMusicTrackDataRom[i].maxAmountOfTracks;
        sMusicTrackDataRom[i].pTrack->unk_1D = sMusicTrackDataRom[i].unknonw_A;
    }

    DoSoundAction((u32)gUnk_Audio0x194F700); // SOUND_ACTION_DISABLE_STEREO | SOUND_ACTION_PWM(9) | SOUND_ACTION_FREQ_INDEX(SOUND_MODE_FREQ_13379) | SOUND_ACTION_VOLUME(15) | SOUND_ACTION_MAX_CHANNELS(7)

    for (i = 0; i < gMusicInfo.maxSoundChannels; i++)
    {
        zero = 0;
        DMA_SET(3, &zero, &gMusicInfo.soundChannels[i], C_32_2_16((DMA_ENABLE | DMA_SRC_FIXED), sizeof(struct SoundChannel) / 2));
    }

    for (i = 0; i < ARRAY_SIZE(gSoundChannelBackup); i++)
    {
        zero = 0;
        DMA_SET(3, &zero, &gSoundChannelBackup[i], C_32_2_16((DMA_ENABLE | DMA_SRC_FIXED), sizeof(struct SoundChannelBackup) / 2));
    }

    for (i = 0; i < (u16)gNumMusicPlayers; i++)
    {
        zero = 0;
        DMA_SET(3, &zero, &gSoundQueue[i], C_32_2_16((DMA_ENABLE | DMA_SRC_FIXED), sizeof(struct SoundQueue) / 2));
    }

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 27f8 | fc | Performs a sound action
 * 
 * @param action Action
 */
void DoSoundAction(u32 action)
{
    s8 i;
    u32 control;

    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    if (action & SOUND_ACTION_ENABLE_REVERB)
        gMusicInfo.reverb = action + SOUND_ACTION_ENABLE_REVERB;

    if (action & SOUND_ACTION_MAX_CHANNELS_FLAG)
    {
        gMusicInfo.maxSoundChannels = (action & SOUND_ACTION_MAX_CHANNELS_FLAG) >> SOUND_ACTION_MAX_CHANNELS_SHIFT;
        for (i = ARRAY_SIZE(gMusicInfo.soundChannels); i >= 0 ; i--)
        {
            gMusicInfo.soundChannels[i].unk_0 = 0;
        }
    }

    if (action & SOUND_ACTION_VOLUME_FLAG)
        gMusicInfo.volume = (action & SOUND_ACTION_VOLUME_FLAG) >> SOUND_ACTION_VOLUME_SHIFT;

    if (action & SOUND_ACTION_FREQ_INDEX_FLAG)
    {
        gMusicInfo.freqIndex = (action & SOUND_ACTION_FREQ_INDEX_FLAG) >> SOUND_ACTION_FREQ_INDEX_SHIFT;
        if (gMusicInfo.freqIndex != 0)
            SetupSoundTransfer();
    }

    // Set PWM amplitude control
    if (action & SOUND_ACTION_PWM_FLAG)
    {
        // Set amplitude resolution/sampling cycle to bits 28-29 of action
        write8(REG_SOUNDBIAS + 1, (read8(REG_SOUNDBIAS + 1) & 0x3F) | (action & SOUND_ACTION_PWM_FLAG) >> 14);
    }

    control = action & SOUND_ACTION_STEREO_FLAG;
    if (control)
    {
        // Enable stereo
        if (control == SOUND_ACTION_ENABLE_STEREO)
        {
            // Set sound volume to 50%, disable DMA sound A left and sound B right
            write16(REG_SOUNDCNT_H, read16(REG_SOUNDCNT_H) & 0xE10D);
            write16(REG_SOUNDCNT_H, read16(REG_SOUNDCNT_H) | 0x1);
        }
        // Disable stereo
        else if (control == SOUND_ACTION_DISABLE_STEREO)
        {
            // Set sound volume to 100% and enable DMA sound A/B left/right
            write16(REG_SOUNDCNT_H, read16(REG_SOUNDCNT_H) & ~0x1);
            write16(REG_SOUNDCNT_H, read16(REG_SOUNDCNT_H) | 0x3302);
        }
    }

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 28f4 | 124 | Sets up the DMA transfers to the fifo channels
 * 
 */
void SetupSoundTransfer(void)
{
    u32 buffer;
    u16 samplesPerFrame;
    u16 unk_1;
    u32 unk_2;

    write32(REG_DMA1_CNT, C_32_2_16((DMA_ENABLE | DMA_32BIT | DMA_DEST_FIXED), sizeof(u32)));
    write32(REG_DMA2_CNT, C_32_2_16((DMA_ENABLE | DMA_32BIT | DMA_DEST_FIXED), sizeof(u32)));
    write16(REG_DMA1_CNT + 2, DMA_32BIT);
    write16(REG_DMA2_CNT + 2, DMA_32BIT);

    buffer = 0;
    CpuFastSet(&buffer, gMusicInfo.soundRawData, C_32_2_16(CPU_SET_SRC_FIXED, sizeof(gMusicInfo.soundRawData) / sizeof(u32)));

    gMusicInfo.sampleRate = sNativeSampleRate[gMusicInfo.freqIndex];
    gMusicInfo.pitch = sMusicPitchData[gMusicInfo.freqIndex];
    samplesPerFrame = gPcmSamplesPerVBlankTable[gMusicInfo.freqIndex];
    gMusicInfo.unk_14 = samplesPerFrame;

    unk_1 = samplesPerFrame / 16;
    gMusicInfo.unk_C = unk_1; // samplesPerFrame / 16
    unk_2 = 96 / gMusicInfo.unk_C;
    gMusicInfo.unk_D = unk_2;  // PCM_DMA_BUF_SIZE / samplesPerFrame, number of frames to process sample?
    gMusicInfo.unk_E = unk_2 * unk_1;  // 96
    gMusicInfo.unk_10 = gMusicInfo.unk_E - 1; // 95
    gMusicInfo.unk_11 = unk_1 * 2; // (samplesPerFrame / 16) * 2

    // First half of raw sound data goes into FIFO A, second half into FIF0 B
    write32(REG_DMA1_SRC, (u32)&gMusicInfo.soundRawData[0]);
    write32(REG_DMA2_SRC, (u32)&gMusicInfo.soundRawData[sizeof(gMusicInfo.soundRawData) / 2]);

    write32(REG_DMA1_DST, (u32)REG_FIFO_A);
    write32(REG_DMA2_DST, (u32)REG_FIFO_B);

    write16(REG_DMA1_CNT + 2, DMA_ENABLE | DMA_START_HBLANK | DMA_START_VBLANK | DMA_32BIT | DMA_REPEAT);
    write16(REG_DMA2_CNT + 2, DMA_ENABLE | DMA_INTR_ENABLE | DMA_START_HBLANK | DMA_START_VBLANK | DMA_32BIT | DMA_REPEAT);

    write16(REG_TM0CNT_H, 0);
    write16(REG_TM0CNT_L, -(FRAME_DRAW_CYCLES / samplesPerFrame)); // cycle time to play each sample

    // Wait for VBLANK
    while (read8(REG_VCOUNT) == (SCREEN_SIZE_Y - 1)) {}
    while (read8(REG_VCOUNT) != (SCREEN_SIZE_Y - 1)) {}

    write16(REG_TM0CNT_H, 0x80); // start timer 0
}

/**
 * @brief 2a18 | 10 | Plays a sound
 * 
 * @param sound Sound ID
 */
void SoundPlay(u16 sound)
{
    QueueSound(sound, 0);
}

/**
 * @brief 2a28 | 10 | Stops a sound
 * 
 * @param sound Sound ID
 */
void SoundStop(u16 sound)
{
    StopOrFadeSound(sound, 0);
}

/**
 * @brief 2a38 | 20 | To document
 * 
 * @param pTrack Track data pointer
 */
void unk_2a38(struct TrackData* pTrack)
{
    if (!(pTrack->unk_1E & TRUE) && (pTrack->flags & 2)) {
        pTrack->flags = 1;
    }
}

/**
 * @brief 2a58 | 34 | Stops every music/sound currently playing
 * 
 */
void StopAllMusicsAndSounds(void)
{
    s32 i;
    
    for (i = (u16)gNumMusicPlayers - 1; i >= 0; i--)
        stop_music_or_sound(sMusicTrackDataRom[i].pTrack);
}

/**
 * @brief 2a8c | 40 | To document
 * 
 */
void unk_2a8c(void)
{
    s32 i;
    
    for (i = (u16)gNumMusicPlayers - 1; i >= 0; i--)
    {
        if (!(sMusicTrackDataRom[i].pTrack->unk_1E & TRUE))
            stop_music_or_sound(sMusicTrackDataRom[i].pTrack);
    }
}

/**
 * @brief 2acc | 54 | Fades every single sound
 * 
 * @param timer Fading timer
 */
void FadeAllSounds(u16 timer)
{
    ApplyMusicSoundFading(sMusicTrackDataRom[1].pTrack, timer);
    ApplyMusicSoundFading(sMusicTrackDataRom[2].pTrack, timer);
    ApplyMusicSoundFading(sMusicTrackDataRom[3].pTrack, timer);
    ApplyMusicSoundFading(sMusicTrackDataRom[4].pTrack, timer);
    ApplyMusicSoundFading(sMusicTrackDataRom[5].pTrack, timer);
    ApplyMusicSoundFading(sMusicTrackDataRom[6].pTrack, timer);
    ApplyMusicSoundFading(sMusicTrackDataRom[7].pTrack, timer);
    ApplyMusicSoundFading(sMusicTrackDataRom[8].pTrack, timer);
}

/**
 * @brief 2b20 | 44 | Plays a sound only if it isn't already playing
 * 
 * @param sound Sound ID
 */
void SoundPlayNotAlreadyPlaying(u16 sound)
{
    struct TrackData* pTrack;
    const u8* pHeader;

    pTrack = sMusicTrackDataRom[sSoundDataEntries[sound].trackGroundNumber].pTrack;
    pHeader = sSoundDataEntries[sound].pHeader;

    if (!(pTrack->flags & 2) || pHeader != pTrack->pHeader)
        QueueSound(sound, 0);
}

/**
 * @brief 2b64 | 6e | To document
 * 
 * @param sound Sound ID
 */
void unk_2b64(u16 sound)
{
    struct TrackData* pTrack;

    pTrack = sMusicTrackDataRom[sSoundDataEntries[sound].trackGroundNumber].pTrack;

    if (pTrack->flags & 2)
    {
        if (sSoundDataEntries[sound].pHeader != pTrack->pHeader)
            QueueSound(sound, 0);
    }
    else
    {
        if (pTrack->flags & 1)
        {
            if (sSoundDataEntries[sound].pHeader == pTrack->pHeader)
                unk_2c10(pTrack);
            else
                QueueSound(sound, 0);
        }
        else if (pTrack->flags == 0)
            QueueSound(sound, 0);
    }
}

/**
 * @brief 2bd4 | 3c | To document
 * 
 * @param sound Sound ID
 */
void unk_2bd4(u16 sound)
{
    struct TrackData* pTrack;

    pTrack = sMusicTrackDataRom[sSoundDataEntries[sound].trackGroundNumber].pTrack;

    if (pTrack->flags & 1 && sSoundDataEntries[sound].pHeader == pTrack->pHeader)
        unk_2c10(pTrack);
}

/**
 * @brief 2c10 | 3c | To document
 * 
 * @param pTrack Track data pointer
 */
void unk_2c10(struct TrackData* pTrack)
{
    s32 i;
    struct TrackVariables* pVariables;

    if (!pTrack->occupied)
    {
        pTrack->occupied = TRUE;

        if (pTrack->flags & 1)
        {
            pTrack->flags = 2;

            i = 0;
            pVariables = pTrack->pVariables;

            while (i < pTrack->amountOfTracks)
            {
                pVariables->unk_5 = 0x40;
                i++;
                pVariables++;
            }
        }

        pTrack->occupied = FALSE;
    }
}

/**
 * @brief 2c4c | 34 | To document
 * 
 */
void unk_2c4c(void)
{
    s32 i;
    
    for (i = (u16)gNumMusicPlayers - 1; i >= 0; i--)
        unk_2c10(sMusicTrackDataRom[i].pTrack);
}

/**
 * @brief 2c80 | 14 | Fades out a sound
 * 
 * @param sound Sound ID
 * @param timer Fade timer
 */
void SoundFade(u16 sound, u16 timer)
{
    StopOrFadeSound(sound, timer);
}

/**
 * @brief 2c94 | 54 | Apply fading to music or sound
 * 
 * @param pTrack Track data pointer
 * @param timer Fade timer
*/
void ApplyMusicSoundFading(struct TrackData* pTrack, u16 timer)
{
    s32 volume;

    if (timer == 0)
        stop_music_or_sound(pTrack); // Undefined
    else if (!pTrack->occupied)
    {
        pTrack->occupied = TRUE;

        if (pTrack->flags & 2)
        {
            if (pTrack->flags & 0xF8)
                reset_track(pTrack); // Undefined
            else
            {
                pTrack->flags |= 8;

                volume = USHORT_MAX;
                pTrack->maybe_volume = volume;
                pTrack->fadingTimer = volume / timer;
            }
        }
        
        pTrack->occupied = FALSE;
    }
}

/**
 * @brief 2ce8 | 44 | Apply raw(?) fading to music or sound
 * 
 * @param pTrack Track data pointer
 * @param timer Fade timer
*/
void ApplyRawMusicSoundFading(struct TrackData* pTrack, u16 timer)
{
    s32 volume;

    if (!pTrack->occupied)
    {
        pTrack->occupied = TRUE;

        if (pTrack->flags & 2)
        {
            if (!(pTrack->flags & 0xF8))
            {
                pTrack->flags |= 0x10;

                volume = USHORT_MAX;
                pTrack->maybe_volume = volume;
                pTrack->fadingTimer = volume / timer;
            }
        }
        
        pTrack->occupied = FALSE;
    }
}

/**
 * @brief 2d2c | bc | To document
 * 
 * @param pTrack Track data pointer
 */
void unk_2d2c(struct TrackData* pTrack)
{
    s32 i;
    struct TrackVariables* pVariables;

    pVariables = pTrack->pVariables;

    if (pTrack->maybe_volume - pTrack->fadingTimer >= 0)
    {
        pTrack->maybe_volume -= pTrack->fadingTimer;
        if (pTrack->flags & 0x80)
        {
            pTrack->unk_24 += pTrack->unk_26;
            if ((u16)(pTrack->unk_24 >> 0xc) != 0)
            {
                pTrack->maxSoundChannels--;
                pTrack->unk_24 &= 0xFFF;
            }

            pTrack->unk_23 = 0;
        }

        i = pTrack->amountOfTracks;
        while (i > 0)
        {
            if (pVariables->unk_0 != 0)
            {
                pVariables->unk_5 = pTrack->maybe_volume / 1024;
                pVariables->unk_0 |= 4;
            }

            i--;
            pVariables++;
        }
    }
    else
    {
        reset_track(pTrack);

        if (pTrack->flags & 8)
            pTrack->flags = 0;
        else if (pTrack->flags & 0x10)
            pTrack->flags = 1;

        if (pTrack->musicTrack != 0)
        {
            if (pTrack->musicTrack & 0x8000)
                pTrack->queueFlags |= 4;
            else
                pTrack->queueFlags |= 1;
        }
    }
}

/**
 * @brief 2de8 | 14 | Plays a fading in sound
 * 
 * @param sound Sound ID
 * @param timer Fading timer
 */
void PlayFadingSound(u16 sound, u16 timer)
{
    QueueSound(sound, timer);
}

/**
 * @brief 2dfc | 38 | Initializes a music that fades in
 * 
 * @param pTrack Track data pointer
 * @param pHeader Sound header pointer
 * @param timer Fading timer
 */
void InitFadingMusic(struct TrackData* pTrack, const u8* pHeader, u16 timer)
{
    InitTrack(pTrack, pHeader);

    if (timer != 0 && !pTrack->occupied)
    {
        pTrack->occupied = TRUE;
        pTrack->flags = 0x20 | 2;
        pTrack->maybe_volume = 0;
        pTrack->fadingTimer = USHORT_MAX / timer;

        pTrack->occupied = FALSE;
    }
}

/**
 * @brief 2e34 | 38 | To document
 * 
 * @param pTrack Track data pointer
 * @param timer Fading timer
 */
void unk_2e34(struct TrackData* pTrack, u16 timer)
{    
    if (!pTrack->occupied)
    {
        pTrack->occupied = TRUE;
        if (pTrack->flags & 1)
        {
            pTrack->flags = 0x20 | 2;
            pTrack->maybe_volume = 0;
            pTrack->fadingTimer = USHORT_MAX / timer;
        }

        pTrack->occupied = FALSE;
    }
}

/**
 * @brief 2e6c | 94 | To document
 * 
 * @param pTrack Track data pointer
 */
void unk_2e6c(struct TrackData* pTrack)
{
    s32 i;
    struct TrackVariables* pVariables;

    pVariables = pTrack->pVariables;

    if (pTrack->maybe_volume + pTrack->fadingTimer <= USHORT_MAX)
    {
        pTrack->maybe_volume += pTrack->fadingTimer;
        if (pTrack->flags & 0x40)
        {
            pTrack->unk_24 += pTrack->unk_26;
            if ((u16)(pTrack->unk_24 >> 0xc) != 0)
            {
                pTrack->maxSoundChannels++;
                pTrack->unk_24 &= 0xFFF;
            }

            pTrack->unk_23 = 0;
        }

        i = pTrack->amountOfTracks;
        while (i > 0)
        {
            pVariables->unk_5 = pTrack->maybe_volume / 1024;
            pVariables->unk_0 |= 4;

            i--;
            pVariables++;
        }
    }
    else
    {
        i = pTrack->amountOfTracks;
        while (i > 0)
        {
            pVariables->unk_5 = 0x40;
            pVariables->unk_0 |= 4;

            i--;
            pVariables++;
        }

        pTrack->flags = 0x2;
    }
}

/**
 * @brief 2f00 | 128 | To document
 * 
 * @param musicTrack1 First music track
 * @param musicTrack2 Second music track
 * @param timer Timer
 */
void unk_2f00(u16 musicTrack1, u16 musicTrack2, u16 timer)
{
    struct TrackData* pTrack1;
    struct TrackData* pTrack2;
    const u8* pHeader;
    s32 var_0;
    u32 var_1;

    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    pTrack1 = sMusicTrackDataRom[sSoundDataEntries[musicTrack1].trackGroundNumber].pTrack;
    pTrack2 = sMusicTrackDataRom[sSoundDataEntries[musicTrack2].trackGroundNumber].pTrack;

    if (!pTrack1->occupied && !pTrack2->occupied)
    {
        pTrack1->occupied = TRUE;
        pTrack2->occupied = TRUE;

        if (pTrack2->flags & 2)
        {
            if (!(pTrack2->flags & 0xF8))
            {
                pHeader = sSoundDataEntries[musicTrack1].pHeader;
        
                // Amount of tracks
                if (pHeader[0] == 0)
                    reset_track(pTrack1);
                else
                {
                    if (pTrack1->flags & 2)
                    {
                        // Priority
                        if (pTrack1->unk_3 > pHeader[2])
                        {
                            //pTrack1->occupied = FALSE;
                            //pTrack2->occupied = FALSE;
                            //gMusicInfo.occupied = FALSE;
                            var_0 = FALSE;
                        }
                        else
                        {
                            reset_track(pTrack1);
                            var_0 = TRUE;
                        }
                    }
                    else
                        var_0 = TRUE;

                    if (var_0)
                    {
                        var_1 = pTrack2->flags;
                        pTrack2->flags = var_1 | 0x80;
                        pTrack2->maybe_volume = USHORT_MAX;
                        pTrack2->fadingTimer = USHORT_MAX / timer;
                        pTrack2->unk_26 = (gMusicInfo.maxSoundChannels * 4096) / timer;
                        pTrack2->unk_24 = 0;
                        pTrack2->maxSoundChannels = gMusicInfo.maxSoundChannels;
            
                        InitTrack(pTrack1, pHeader);
                        pTrack1->flags = 0x40 | 0x2;
                        pTrack1->maybe_volume = 0;
                        pTrack1->fadingTimer = pTrack2->fadingTimer;
                        pTrack1->unk_26 = pTrack2->unk_26;
                        pTrack1->unk_24 = 0;
                        pTrack1->maxSoundChannels = 0;
                    }
                }
            }
        }

        pTrack1->occupied = FALSE;
        pTrack2->occupied = FALSE;
    }

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3028 | 30 | To document
 * 
 * @param pTrack Track data pointer
 * @param param_2 Unknown
 */
void unk_3028(struct TrackData* pTrack, u16 param_2)
{
    u16 unk;

    if (!pTrack->occupied)
    {
        pTrack->occupied = TRUE;

        unk = param_2 / 256 * pTrack->unk_A;
        pTrack->unk_C = unk * 256 / 150;

        pTrack->occupied = FALSE;
    }
}

/**
 * @brief 3058 | 5c | To document
 * 
 * @param pTrack Track data pointer
 * @param variablesMask Track data variables mask
 * @param param_3 Unknown
 */
void unk_3058(struct TrackData* pTrack, u16 variablesMask, u16 param_3)
{
    struct TrackVariables* pVariables;
    s32 i;

    if (!pTrack->occupied)
    {
        pTrack->occupied = TRUE;

        if (!(pTrack->flags & (0x80|0x40|0x20|0x10|0x8)))
        {
            pVariables = pTrack->pVariables;
            param_3 = (param_3 & 0x3FC) / 4;
            i = pTrack->amountOfTracks - 1;

            while (i >= 0)
            {
                if ((variablesMask >> i) & 1)
                {
                    pVariables->unk_5 = param_3;
                    pVariables->unk_0 |= 4;
                }

                i--;
                pVariables++;
            }
        }

        pTrack->occupied = FALSE;
    }
}

/**
 * @brief 30b4 | 5c | To document
 * 
 * @param pTrack Track data pointer
 * @param variablesMask Track data variables mask
 * @param param_3 Unknown
 */
void unk_30b4(struct TrackData* pTrack, u16 variablesMask, u16 param_3)
{
    struct TrackVariables* pVariables;
    s32 i;

    if (!pTrack->occupied)
    {
        pTrack->occupied = TRUE;

        pVariables = pTrack->pVariables;
        i = pTrack->amountOfTracks;

        while (i > 0)
        {
            if ((variablesMask >> i) & 1)
            {
                pVariables->unk_1D = (s16)param_3 >> 8;
                pVariables->unk_1F = param_3;
                pVariables->unk_0 |= 8;
            }

            i--;
            pVariables++;
        }

        pTrack->occupied = FALSE;
    }
}

/**
 * @brief 3110 | 4c | To document
 * 
 * @param pTrack Track data pointer
 * @param variablesMask Track data variables mask
 * @param param_3 Unknown
 */
void unk_3110(struct TrackData* pTrack, u16 variablesMask, u8 param_3)
{
    struct TrackVariables* pVariables;
    s32 i;

    if (!pTrack->occupied)
    {
        pTrack->occupied = TRUE;

        pVariables = pTrack->pVariables;
        i = pTrack->amountOfTracks;

        while (i > 0)
        {
            if ((variablesMask >> i) & 1)
            {
                pVariables->unk_7 = (s8)param_3 >> 1;
                pVariables->unk_0 |= 4;
            }

            i--;
            pVariables++;
        }

        pTrack->occupied = FALSE;
    }
}

/**
 * @brief 315c | 44 | To document
 * 
 * @param pTrack Track data pointer
 * @param variablesMask Track data variables mask
 * @param param_3 Unknown
 */
void unk_315c(struct TrackData* pTrack, u16 variablesMask, u8 param_3)
{
    struct TrackVariables* pVariables;
    s32 i;

    if (!pTrack->occupied)
    {
        pTrack->occupied = TRUE;

        pVariables = pTrack->pVariables;
        param_3 &= 0x7F;
        i = pTrack->amountOfTracks;

        while (i > 0)
        {
            if ((variablesMask >> i) & 1)
                pVariables->modulationDepth = param_3;

            i--;
            pVariables++;
        }

        pTrack->occupied = FALSE;
    }
}

/**
 * @brief 31a0 | 44 | To document
 * 
 * @param pTrack Track data pointer
 * @param variablesMask Track data variables mask
 * @param param_3 Unknown
 */
void unk_31a0(struct TrackData* pTrack, u16 variablesMask, u8 param_3)
{
    struct TrackVariables* pVariables;
    s32 i;

    if (!pTrack->occupied)
    {
        pTrack->occupied = TRUE;

        pVariables = pTrack->pVariables;
        param_3 &= 0x7F;
        i = pTrack->amountOfTracks;

        while (i > 0)
        {
            if ((variablesMask >> i) & 1)
                pVariables->lfoSpeed = param_3;

            i--;
            pVariables++;
        }

        pTrack->occupied = FALSE;
    }
}
