#include "audio_wrappers.h"
#include "data/audio.h"

void InitializeAudio(void)
{

}

void UpdateSOUNDCNT_H(u32 action)
{

}

void SetupSoundTransfer(void)
{

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
    if (!(pTrack->unknown_1E & 1) && (pTrack->flags & 2)) {
        pTrack->flags = 1;
    }
}

/**
 * @brief 2a58 | 34 | Stops every music/sound currently playing
 * 
 */
void StopAllMusicsAndSounds(void)
{
    i32 i;
    
    for (i = (u16)gNumMusicPlayers - 1; i >= 0; i--)
        stop_music_or_sound(sMusicTrackDataROM[i].pTrack);
}

/**
 * @brief 2a8c | 40 | To document
 * 
 */
void unk_2a8c(void)
{
    i32 i;
    
    for (i = (u16)gNumMusicPlayers - 1; i >= 0; i--)
    {
        if (!(sMusicTrackDataROM[i].pTrack->unknown_1E & 1))
            stop_music_or_sound(sMusicTrackDataROM[i].pTrack);
    }
}

/**
 * @brief 2acc | 54 | Fades every single sound
 * 
 * @param timer Fading timer
 */
void FadeAllSounds(u16 timer)
{
    ApplyMusicSoundFading(sMusicTrackDataROM[1].pTrack, timer);
    ApplyMusicSoundFading(sMusicTrackDataROM[2].pTrack, timer);
    ApplyMusicSoundFading(sMusicTrackDataROM[3].pTrack, timer);
    ApplyMusicSoundFading(sMusicTrackDataROM[4].pTrack, timer);
    ApplyMusicSoundFading(sMusicTrackDataROM[5].pTrack, timer);
    ApplyMusicSoundFading(sMusicTrackDataROM[6].pTrack, timer);
    ApplyMusicSoundFading(sMusicTrackDataROM[7].pTrack, timer);
    ApplyMusicSoundFading(sMusicTrackDataROM[8].pTrack, timer);
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

    pTrack = sMusicTrackDataROM[sSoundDataEntries[sound].trackGroundNumber].pTrack;
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

    pTrack = sMusicTrackDataROM[sSoundDataEntries[sound].trackGroundNumber].pTrack;

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

    pTrack = sMusicTrackDataROM[sSoundDataEntries[sound].trackGroundNumber].pTrack;

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
    i32 i;
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
                pVariables->unknown_5 = 0x40;
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
    i32 i;
    
    for (i = (u16)gNumMusicPlayers - 1; i >= 0; i--)
        unk_2c10(sMusicTrackDataROM[i].pTrack);
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

void ApplyMusicSoundFading(struct TrackData* pTrack, u16 timer)
{
    i32 volume;

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

void ApplyRawMusicSoundFading(struct TrackData* pTrack, u16 timer)
{
    i32 volume;

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
 * @param pTrack 
 */
void unk_2d2c(struct TrackData* pTrack)
{
    i32 i;
    struct TrackVariables* pVariables;

    pVariables = pTrack->pVariables;

    if (pTrack->maybe_volume - pTrack->fadingTimer >= 0)
    {
        pTrack->maybe_volume -= pTrack->fadingTimer;
        if (pTrack->flags & 0x80)
        {
            pTrack->unknown_24 += pTrack->unknown_26;
            if ((u16)(pTrack->unknown_24 >> 0xc) != 0)
            {
                pTrack->maxSoundChannels--;
                pTrack->unknown_24 &= 0xFFF;
            }

            pTrack->unknown_23 = 0;
        }

        i = pTrack->amountOfTracks;
        while (i > 0)
        {
            if (pVariables->unknown_0 != 0)
            {
                pVariables->unknown_5 = pTrack->maybe_volume / 1024;
                pVariables->unknown_0 |= 4;
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
    init_track(pTrack, pHeader);

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
    i32 i;
    struct TrackVariables* pVariables;

    pVariables = pTrack->pVariables;

    if (pTrack->maybe_volume + pTrack->fadingTimer <= USHORT_MAX)
    {
        pTrack->maybe_volume += pTrack->fadingTimer;
        if (pTrack->flags & 0x40)
        {
            pTrack->unknown_24 += pTrack->unknown_26;
            if ((u16)(pTrack->unknown_24 >> 0xc) != 0)
            {
                pTrack->maxSoundChannels++;
                pTrack->unknown_24 &= 0xFFF;
            }

            pTrack->unknown_23 = 0;
        }

        i = pTrack->amountOfTracks;
        while (i > 0)
        {
            pVariables->unknown_5 = pTrack->maybe_volume / 1024;
            pVariables->unknown_0 |= 4;

            i--;
            pVariables++;
        }
    }
    else
    {
        i = pTrack->amountOfTracks;
        while (i > 0)
        {
            pVariables->unknown_5 = 0x40;
            pVariables->unknown_0 |= 4;

            i--;
            pVariables++;
        }

        pTrack->flags = 0x2;
    }
}

void unk_2f00(u16 musicTrack1, u16 musicTrack2, u16 timer)
{
    // https://decomp.me/scratch/cXPYE

    struct TrackData* pTrack1;
    struct TrackData* pTrack2;
    const u8* pHeader;

    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    pTrack1 = sMusicTrackDataROM[sSoundDataEntries[musicTrack1].trackGroundNumber].pTrack;
    pTrack2 = sMusicTrackDataROM[sSoundDataEntries[musicTrack2].trackGroundNumber].pTrack;

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
                        if (pTrack1->unknown_3 > pHeader[2])
                        {
                            //pTrack1->occupied = FALSE;
                            //pTrack2->occupied = FALSE;
                            //gMusicInfo.occupied = FALSE;
                            return;
                        }
                        else
                            reset_track(pTrack1);
                    }
        
                    pTrack2->flags |= 0x80;
                    pTrack2->maybe_volume = USHORT_MAX;
                    pTrack2->fadingTimer = USHORT_MAX / timer;
                    pTrack2->unknown_26 = (gMusicInfo.maxSoundChannels * 4096) / timer;
                    pTrack2->unknown_24 = 0;
                    pTrack2->maxSoundChannels = gMusicInfo.maxSoundChannels;
        
                    init_track(pTrack1, pHeader);
                    pTrack1->flags = 0x40 | 0x2;
                    pTrack1->maybe_volume = 0;
                    pTrack1->fadingTimer = pTrack2->fadingTimer;
                    pTrack1->unknown_26 = pTrack2->unknown_26;
                    pTrack1->unknown_24 = 0;
                    pTrack1->maxSoundChannels = 0;
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

        unk = param_2 / 256 * pTrack->unknown_A;
        pTrack->unknown_C = unk * 256 / 150;

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
    i32 i;

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
                    pVariables->unknown_5 = param_3;
                    pVariables->unknown_0 |= 4;
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
    i32 i;

    if (!pTrack->occupied)
    {
        pTrack->occupied = TRUE;

        pVariables = pTrack->pVariables;
        i = pTrack->amountOfTracks;

        while (i > 0)
        {
            if ((variablesMask >> i) & 1)
            {
                pVariables->unknown_1D = (i16)param_3 >> 8;
                pVariables->unknown_1F = param_3;
                pVariables->unknown_0 |= 8;
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
    i32 i;

    if (!pTrack->occupied)
    {
        pTrack->occupied = TRUE;

        pVariables = pTrack->pVariables;
        i = pTrack->amountOfTracks;

        while (i > 0)
        {
            if ((variablesMask >> i) & 1)
            {
                pVariables->unknown_7 = (i8)param_3 >> 1;
                pVariables->unknown_0 |= 4;
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
    i32 i;

    if (!pTrack->occupied)
    {
        pTrack->occupied = TRUE;

        pVariables = pTrack->pVariables;
        param_3 &= 0x7F;
        i = pTrack->amountOfTracks;

        while (i > 0)
        {
            if ((variablesMask >> i) & 1)
                pVariables->unknown_11 = param_3;

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
    i32 i;

    if (!pTrack->occupied)
    {
        pTrack->occupied = TRUE;

        pVariables = pTrack->pVariables;
        param_3 &= 0x7F;
        i = pTrack->amountOfTracks;

        while (i > 0)
        {
            if ((variablesMask >> i) & 1)
                pVariables->unknown_10 = param_3;

            i--;
            pVariables++;
        }

        pTrack->occupied = FALSE;
    }
}
