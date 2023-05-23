#include "music_wrappers.h"
#include "audio_wrappers.h"
#include "syscalls.h"
#include "gba.h"

#include "data/audio.h"

#include "constants/audio.h"

/**
 * @brief 3380 | 5c | DMA 2 interrupt callback
 * 
 */
void DMA2IntrCode(void)
{
    gMusicInfo.sampleRate++;
    if (gMusicInfo.sampleRate == gMusicInfo.unknown_E)
    {
        write32(REG_DMA1_CNT, (DMA_DEST_FIXED | DMA_32BIT | DMA_ENABLE) << 16 | 4);
        write32(REG_DMA2_CNT, (DMA_DEST_FIXED | DMA_32BIT | DMA_ENABLE) << 16 | 4);

        write16(REG_DMA1_CNT + 2, DMA_SRC_FIXED | DMA_32BIT);
        write16(REG_DMA2_CNT + 2, DMA_SRC_FIXED | DMA_32BIT);

        write16(REG_DMA1_CNT + 2, DMA_REPEAT | DMA_32BIT | DMA_START_VBLANK | DMA_START_HBLANK | DMA_ENABLE);
        write16(REG_DMA2_CNT + 2, DMA_REPEAT | DMA_32BIT | DMA_START_VBLANK | DMA_START_HBLANK | DMA_INTR_ENABLE | DMA_ENABLE);

        gMusicInfo.sampleRate = 0;
    }
}

/**
 * @brief 33dc | 7c | To document
 * 
 */
void unk_33dc(void)
{
    u32 value;

    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    write16(REG_SOUND1CNT_X, SOUNDCNT_RESTART_SOUND);

    write8(REG_SOUND2CNT_L + 1, 0x8);
    write16(REG_SOUND2CNT_H, 0x8000);

    write8(REG_SOUND3CNT_L, 0);

    write8(REG_SOUND4CNT_L + 1, 0x8);
    write16(REG_SOUND4CNT_H, SOUNDCNT_RESTART_SOUND);

    write32(REG_DMA1_CNT, (DMA_DEST_FIXED | DMA_32BIT | DMA_ENABLE) << 16 | 4);
    write32(REG_DMA2_CNT, (DMA_DEST_FIXED | DMA_32BIT | DMA_ENABLE) << 16 | 4);
    write16(REG_DMA1_CNT + 2, DMA_SRC_FIXED | DMA_32BIT);
    write16(REG_DMA2_CNT + 2, DMA_SRC_FIXED | DMA_32BIT);

    value = 0;
    CpuSet(&value, gMusicInfo.soundRawData, (CPU_SET_SRC_FIXED | CPU_SET_32BIT) << 16 | 0x300);
    write8(0x4000084, 0);

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3458 | 54 | To document
 * 
 */
void unk_3458(void)
{
    u32 value;

    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    write32(REG_DMA1_CNT, (DMA_DEST_FIXED | DMA_32BIT | DMA_ENABLE) << 16 | 4);
    write32(REG_DMA2_CNT, (DMA_DEST_FIXED | DMA_32BIT | DMA_ENABLE) << 16 | 4);
    write16(REG_DMA1_CNT + 2, DMA_SRC_FIXED | DMA_32BIT);
    write16(REG_DMA2_CNT + 2, DMA_SRC_FIXED | DMA_32BIT);

    value = 0;
    CpuSet(&value, gMusicInfo.soundRawData, (CPU_SET_SRC_FIXED | CPU_SET_32BIT) << 16 | 0x300);

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 34ac | 124 | To document
 * 
 * @param param_1 To document
 */
void unk_34ac(u8 param_1)
{
    u8 i;
    u8 start;
    u8 j;
    u8 currChannel;
    struct TrackData* pTrack;
    struct TrackVariables* pVariables;
    struct SoundChannel* pChannel;
    struct SoundChannel* pChannelNext;

    currChannel = 0;
    if (param_1 == FALSE)
        start = 2;
    else
        start = 1;

    for (i = start; i < (u16)gNumMusicPlayers; i++)
    {
        if ((i == 2 && param_1 == FALSE) || (0x14A >> i) & 1)
        {
            pTrack = sMusicTrackDataROM[i].pTrack;
            if (pTrack->occupied)
                continue;

            pTrack->occupied = TRUE;

            if (!(pTrack->unknown_1E & TRUE) && pTrack->flags & 2)
            {
                pTrack->unknown_1E = TRUE;

                for (j = 0, pVariables = pTrack->pVariables; j < pTrack->amountOfTracks; j++, pVariables++)
                {
                    if (!(pVariables->channel & 0xC0))
                    {
                        if (pVariables->pSoundPSG != NULL)
                        {
                            clear_registers_for_psg(pVariables->pSoundPSG, (u8)((pVariables->channel & 7) - 1));
                        }

                        if (pVariables->pChannel == NULL)
                            continue;
                        
                        for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pChannelNext)
                        {
                            gSoundChannelBackup[currChannel].pChannel = pChannel;
                            gSoundChannelBackup[currChannel].channel = *pChannel;
                            currChannel++;

                            pChannel->unknown_0 = 0;
                            pChannel->pVariables = NULL;
                            pChannelNext = pChannel->pChannel2;
                            pChannel->pChannel2 = NULL;
                            pChannel->pChannel1 = NULL;
                        }
                    }
                }
            }

            pTrack->occupied = FALSE;
        }
    }
}

/**
 * @brief 35d0 | 100 | To document
 * 
 * @param param_1 To document
 */
void unk_35d0(u8 param_1)
{
    u8 i;
    u8 start;
    u8 j;
    u8 currChannel;
    struct TrackData* pTrack;
    struct TrackVariables* pVariables;
    struct SoundChannel* pChannel;

    currChannel = 0;
    if (param_1 == FALSE)
        start = 2;
    else
        start = 1;

    for (i = start; i < (u16)gNumMusicPlayers; i++)
    {
        if ((i == 2 && param_1 == FALSE) || (0x14A >> i) & 1)
        {
            pTrack = sMusicTrackDataROM[i].pTrack;
            if (pTrack->occupied)
                continue;

            pTrack->occupied = TRUE;

            if (pTrack->unknown_1E & TRUE)
            {
                pTrack->unknown_1E &= ~TRUE;

                for (j = 0, pVariables = pTrack->pVariables; j < pTrack->amountOfTracks; j++, pVariables++)
                {
                    if (!(pVariables->channel & 0xC0))
                    {
                        if (pVariables->pChannel == NULL)
                            continue;
                        
                        for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pChannel->pChannel2)
                        {
                            unk_20a4(pChannel);
                            *pChannel = gSoundChannelBackup[currChannel].channel;
                            currChannel++;
                        }
                    }
                }
            }

            pTrack->occupied = FALSE;
        }
    }
}

void CheckSetNewMusicTrack(u16 musicTrack)
{
    // https://decomp.me/scratch/LDIqE

    struct TrackData* pTrack;
    u32 newTrack;

    if (!(gMusicInfo.priority & 4))
    {
        if (gMusicInfo.priority & 0x70)
        {
            unk_378c(musicTrack);
            return;
        }
        
        if (gMusicInfo.priority == 0 && !gMusicInfo.occupied)
        {
            gMusicInfo.occupied = TRUE;

            ApplyMusicSoundFading(sMusicTrackDataROM[6].pTrack, 10);
            ApplyMusicSoundFading(sMusicTrackDataROM[8].pTrack, 10);

            if (gSoundQueue[6].exists & 3)
                gSoundQueue[6].exists = 0;

            if (gSoundQueue[8].exists & 3)
                gSoundQueue[8].exists = 0;

            pTrack = sMusicTrackDataROM[0].pTrack;

            if (musicTrack == 0)
                musicTrack = 0xA9;

            newTrack = DetermineNewMusicTrack(musicTrack);

            if (sSoundDataEntries[newTrack].pHeader != pTrack->pHeader)
            {
                ApplyMusicSoundFading(pTrack, 30);
                gMusicInfo.musicTrackOnTransition = newTrack;
            }
            
            gMusicInfo.occupied = FALSE;
        }
    }
}

void unk_378c(u16 musicTrack)
{
    // https://decomp.me/scratch/ETNx6

    u16 newTrack;
    struct TrackData* pTrack;

    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    ApplyMusicSoundFading(sMusicTrackDataROM[6].pTrack, 10);
    ApplyMusicSoundFading(sMusicTrackDataROM[8].pTrack, 10);

    if (gSoundQueue[6].exists & 3)
        gSoundQueue[6].exists = 0;
        
    if (gSoundQueue[8].exists & 3)
        gSoundQueue[8].exists = 0;

    if (gMusicInfo.priority & 0x30)
    {
        newTrack = gMusicInfo.musicTrack - 0x5A;
        if (newTrack < 10)
        {
            newTrack = musicTrack - 0x5A;
            if (newTrack >= 10)
            {
                if (gMusicInfo.priority & 0x10)
                    musicTrack = MUSIC_STEALTH;
                else
                    musicTrack = MUSIC_CHOZODIA_DETECTED;
            }
        }
        else
        {
            newTrack = musicTrack - 0x5A;
            if (newTrack < 10)
            {
                return;
            }
        }
    }
    else if (gMusicInfo.priority & 0x40)
    {
        newTrack = musicTrack - 0x5A;
        if (newTrack < 10)
        {
            gMusicInfo.musicTrackOnTransition = musicTrack;
        }
        return;
    }

    pTrack = sMusicTrackDataROM[0].pTrack;
    if (sSoundDataEntries[DetermineNewMusicTrack(musicTrack)].pHeader != pTrack->pHeader)
    {
        ApplyMusicSoundFading(pTrack, 30);
        gMusicInfo.musicTrackOnTransition = musicTrack;
    }

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3878 | 60 | Checks if the music track on transition should play
 * 
 */
void CheckPlayTransitionMusicTrack(void)
{
    if (!(gMusicInfo.priority & 4))
    {
        if (gMusicInfo.priority & 0x70)
        {
            unk_38d8();
            return;
        }
        
        if (gMusicInfo.priority == 0 && gMusicInfo.musicTrackOnTransition != MUSIC_NONE)
        {
            init_track(sMusicTrackDataROM[0].pTrack, sSoundDataEntries[gMusicInfo.musicTrackOnTransition].pHeader);

            gMusicInfo.unknown_20 = 0;
            gMusicInfo.musicTrack = gMusicInfo.musicTrackOnTransition;
            gMusicInfo.musicTrackOnTransition = MUSIC_NONE;
        }
    }
}

/**
 * @brief 38d8 | 58 | To document
 * 
 */
void unk_38d8(void)
{
    if (!(gMusicInfo.priority & 0x40) && gMusicInfo.musicTrackOnTransition != MUSIC_NONE)
    {
        init_track(sMusicTrackDataROM[0].pTrack,
            sSoundDataEntries[DetermineNewMusicTrack(gMusicInfo.musicTrackOnTransition)].pHeader);
        gMusicInfo.unknown_20 = 0;
        gMusicInfo.musicTrack = gMusicInfo.musicTrackOnTransition;
    }

    gMusicInfo.musicTrackOnTransition = MUSIC_NONE;
}

/**
 * @brief 3930 | 51 | Updates the music after the alarm got disabled
 * 
 */
void UpdateMusicAfterAlarmDisable(void)
{
    u16 musicTrack;

    gMusicInfo.priority = 0x20;
    
    if (gMusicInfo.musicTrackOnTransition == MUSIC_NONE)
    {
        FadeCurrentMusicAndQueueNextMusic(5, MUSIC_CHOZODIA_DETECTED, 0x20);
        return;
    }

    musicTrack = gMusicInfo.musicTrackOnTransition - 0x5A;
    if (musicTrack < 10)
        ApplyMusicSoundFading(sMusicTrackDataROM[0].pTrack, 5);
    else
        FadeCurrentMusicAndQueueNextMusic(5, MUSIC_CHOZODIA_DETECTED, 0x20);
}

/**
 * @brief 3980 | 48 | Determines a new music track based on something?
 * 
 * @param musicTrack Music track
 * @return u16 New music track
 */
u16 DetermineNewMusicTrack(u16 musicTrack)
{
    switch (musicTrack)
    {
        case MUSIC_CHOZODIA_SURFACE:
            musicTrack = MUSIC_CHOZO_RUINS;
            break;

        case MUSIC_MAP_ROOM_2:
            musicTrack = MUSIC_MAP_ROOM;
            break;

        case MUSIC_SAVE_ELEVATOR_ROOM_2:
            musicTrack = MUSIC_SAVE_ELEVATOR_ROOM;
            break;

        case MUSIC_BEFORE_RUINS_TEST_ROOM:
            musicTrack = MUSIC_BEFORE_RUINS_TEST_UNUSED;
            break;

        case MUSIC_STEALTH_2:
            musicTrack = MUSIC_STEALTH;
            break;
    }

    return musicTrack;
}

/**
 * @brief 39c8 | 2c | To document
 * 
 */
void unk_39c8(void)
{
    if (gMusicInfo.priority == 0)
    {
        ApplyMusicSoundFading(sMusicTrackDataROM[6].pTrack, 10);
        ApplyMusicSoundFading(sMusicTrackDataROM[8].pTrack, 10);
    }
}

/**
 * @brief 39f4 | 78 | Plays a music track
 * 
 * @param musicTrack Music track
 * @param priority Priority
 */
void PlayMusic(u16 musicTrack, u8 priority)
{
    const u8* pHeader;
    struct TrackData* pTrack;

    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    if (!(gMusicInfo.priority & 0x84))
    {
        gMusicInfo.priority = (gMusicInfo.priority & 0x80) | priority;

        pHeader = sSoundDataEntries[musicTrack].pHeader;
        pTrack = sMusicTrackDataROM[0].pTrack;

        if (pHeader != pTrack->pHeader || !(pTrack->flags & 2))
        {
            gMusicInfo.unknown_20 = 0;
            gMusicInfo.musicTrack = musicTrack;
            gMusicInfo.occupied = FALSE;
            init_track(pTrack, pHeader);
        }
    }

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3a6c | 2c | To document
 * 
 */
void unk_3a6c(void)
{
    struct TrackData* pTrack;

    if (gMusicInfo.unknown_20 == 0)
        pTrack = sMusicTrackDataROM[0].pTrack;
    else
        pTrack = sMusicTrackDataROM[1].pTrack;

    stop_music_or_sound(pTrack);
}

/**
 * @brief 3a98 | 4c | Fades out the current music
 * 
 * @param timer Fading timer
 */
void FadeMusic(u16 timer)
{
    struct TrackData* pTrack;

    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    if (!(gMusicInfo.priority & 0x84))
    {
        pTrack = sMusicTrackDataROM[0].pTrack;
        if (timer != 0)
            ApplyMusicSoundFading(pTrack, timer);
        else
            stop_music_or_sound(pTrack);
    }

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3ae4 | 4c | Fades out the current music for demos
 * 
 * @param timer Fading timer
 */
void FadeMusicForDemo(u16 timer)
{
    struct TrackData* pTrack;

    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    if (!(gMusicInfo.priority & 0x80))
    {
        pTrack = sMusicTrackDataROM[0].pTrack;
        if (timer != 0)
            ApplyMusicSoundFading(pTrack, timer);
        else
            stop_music_or_sound(pTrack);
    }

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3b30 | 4c | Fades the current music and queues another music track to be played after
 * 
 * @param timer Fading timer
 * @param musicTrack Music track
 * @param priority Priority
 */
void FadeCurrentMusicAndQueueNextMusic(u16 timer, u16 musicTrack, u8 priority)
{
    struct TrackData* pTrack;

    if (!(gMusicInfo.priority & 0x84))
    {
        if (timer == 0)
            PlayMusic(musicTrack, priority);
        else
        {
            pTrack = sMusicTrackDataROM[0].pTrack;

            pTrack->musicTrack = musicTrack;
            pTrack->priority = priority;
            ApplyMusicSoundFading(pTrack, timer);
        }
    }
}

/**
 * @brief 3b7c | 54 | Fades the current music, inserts another music track, and replays the current music back after
 * 
 * @param timer Fading timer
 * @param musicTrack Music track
 * @param priority Priority
 */
void FadeCurrentInsertMusicQueueCurrent(u16 timer, u16 musicTrack, u8 priority)
{
    struct TrackData* pTrack;

    if (!(gMusicInfo.priority & 0x84))
    {
        if (timer == 0)
            PlayMusic(musicTrack, priority);
        else
        {
            pTrack = sMusicTrackDataROM[0].pTrack;

            pTrack->musicTrack = musicTrack | 0x8000;
            pTrack->priority = priority;
            ApplyRawMusicSoundFading(pTrack, timer);
        }
    }
}

/**
 * @brief 3bd0 | 50 | To document
 * 
 * @param musicTrack Music track
 * @param timer Fading timer
 */
void unk_3bd0(u16 musicTrack, u16 timer)
{
    struct TrackData* pTrack;

    if (!(gMusicInfo.priority & 0x84))
    {
        pTrack = sMusicTrackDataROM[sSoundDataEntries[musicTrack].trackGroundNumber].pTrack;

        if (sSoundDataEntries[musicTrack].pHeader == pTrack->pHeader)
            unk_2e34(pTrack, timer);
    }
}

/**
 * @brief 3c20 | 80 | Plays a fading music
 * 
 * @param musicTrack 
 * @param timer 
 * @param priority 
 */
void CheckPlayFadingMusic(u16 musicTrack, u16 timer, u8 priority)
{
    const u8* pHeader;
    struct TrackData* pTrack;

    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    if (!(gMusicInfo.priority & 0x84))
    {
        gMusicInfo.priority = (gMusicInfo.priority & 0x80) | priority;

        pHeader = sSoundDataEntries[musicTrack].pHeader;
        pTrack = sMusicTrackDataROM[0].pTrack;

        if ((pTrack->flags & (0x2 | 0x8 | 0x10)) != 0x2 || pHeader != pTrack->pHeader)
        {
            gMusicInfo.unknown_20 = 0;
            gMusicInfo.musicTrack = musicTrack;
            gMusicInfo.occupied = FALSE;
            InitFadingMusic(pTrack, pHeader, timer);
        }
    }

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3ca0 | ac | Queues the current music and inserts a new music track
 * 
 * @param musicTrack Music track
 * @param param_2 Unknown
 */
void InsertMusicAndQueueCurrent(u16 musicTrack, u8 param_2)
{
    const u8* pHeader;
    struct TrackData* pTrack;

    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    if (!(gMusicInfo.priority & 0x84))
    {
        pHeader = sSoundDataEntries[musicTrack].pHeader;
        pTrack = sMusicTrackDataROM[0].pTrack;

        if ((pTrack->flags & (0x2 | 0x8 | 0x10)) != 0x2 || pHeader != pTrack->pHeader)
        {
            if (param_2 == 0)
            {
                stop_music_or_sound(sMusicTrackDataROM[3].pTrack);
                unk_34ac(TRUE);
                unk_2a8c();
                pTrack->queueFlags |= 0x80;
            }
            else if (param_2 == 1)
            {
                unk_2a8c();
                pTrack->queueFlags |= 0x40;
                pTrack->queueFlags |= 0x80;
            }

            gMusicInfo.unknown_20 = 1;
            gMusicInfo.occupied = FALSE;
            init_track(pTrack, pHeader);
        }
    }

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3d4c | d8 | Replays the current music that was queue'd
 * 
 * @param queueFlags Queue flags
 */
void ReplayQueuedMusic(u8 queueFlags)
{
    u16 music;
    struct TrackData* pTrack;
    const u8* pHeader;

    if (gMusicInfo.occupied)
        return;
    
    gMusicInfo.occupied = TRUE;

    if (!(queueFlags & 0x40))
        unk_35d0(TRUE);

    pTrack = sMusicTrackDataROM[0].pTrack;

    gMusicInfo.unknown_20 = 0;
    if ((u16)(gMusicInfo.musicTrack - 0x5A) < 0xA)
        music = DetermineNewMusicTrack(gMusicInfo.musicTrack);
    else
        music = gMusicInfo.musicTrack;

    pHeader = sSoundDataEntries[music].pHeader;
    gMusicInfo.occupied = FALSE;
    init_track(pTrack, pHeader);

    if (queueFlags & 0x40)
        DelayMusicStart(pTrack, 60);

    if (gMusicInfo.volumeDownFlag & (1 << 7))
    {
        unk_3058(sMusicTrackDataROM[0].pTrack, USHORT_MAX, (u16)gUnk_Audio0x50);
        unk_3058(sMusicTrackDataROM[1].pTrack, USHORT_MAX, (u16)gUnk_Audio0x50);
        unk_3058(sMusicTrackDataROM[7].pTrack, USHORT_MAX, (u16)gUnk_Audio0x50);
    }

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3e24 | 3c | To document
 * 
 * @param timer Fading timer
 */
void unk_3e24(u16 timer)
{
    struct TrackData* pTrack;

    if (gMusicInfo.unknown_20 == 0)
        pTrack = sMusicTrackDataROM[0].pTrack;
    else
        pTrack = sMusicTrackDataROM[1].pTrack;

    if (timer != 0)
        ApplyMusicSoundFading(pTrack, timer);
    else
        stop_music_or_sound(pTrack);
}

/**
 * @brief 3e60 | 58 | Updates the music priority
 * 
 * @param priority Priority
 */
void UpdateMusicPriority(u8 priority)
{
    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    if (priority == 0x80)
        gMusicInfo.priority |= priority;
    else if (priority == UCHAR_MAX)
        gMusicInfo.priority &= ~0x80;
    else
        gMusicInfo.priority = (gMusicInfo.priority & 0x80) | priority;

    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3eb8 | 68 | Plays the current music track
 * 
 */
void PlayCurrentMusicTrack(void)
{
    struct TrackData* pTrack;
    const u8* pHeader;
    u16 musicTrack;
    u16 currTrack;

    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    pTrack = sMusicTrackDataROM[0].pTrack;
    gMusicInfo.unknown_20 = 0;

    currTrack = gMusicInfo.musicTrack;
    musicTrack = currTrack - 0x5A;
    if (musicTrack < 10)
        pHeader = sSoundDataEntries[DetermineNewMusicTrack(currTrack)].pHeader;
    else
        pHeader = sSoundDataEntries[currTrack].pHeader;

    gMusicInfo.occupied = FALSE;
    init_track(pTrack, pHeader);
    gMusicInfo.occupied = FALSE;
}

/**
 * @brief 3f20 | 4c | Decreases the music volume when paused
 * 
 */
void DecreaseMusicVolume(void)
{
    SoundPlay(0x63);
    unk_34ac(FALSE);

    gMusicInfo.volumeDownFlag |= (1 << 7);
    
    unk_3058(sMusicTrackDataROM[0].pTrack, USHORT_MAX, (u16)gUnk_Audio0x50);
    unk_3058(sMusicTrackDataROM[1].pTrack, USHORT_MAX, (u16)gUnk_Audio0x50);
}

/**
 * @brief 3f6c | 40 | Resets the music volume after it'd been decreased
 * 
 */
void ResetMusicVolume(void)
{
    unk_3058(sMusicTrackDataROM[0].pTrack, USHORT_MAX, 0x100);
    unk_3058(sMusicTrackDataROM[1].pTrack, USHORT_MAX, 0x100);

    gMusicInfo.volumeDownFlag &= ~(1 << 7);
    unk_35d0(FALSE);
}

/**
 * @brief 3fac | 68 | Adds a sound in the sound queue
 * 
 * @param sound Sound ID
 * @param timer Fading timer
 */
void QueueSound(u16 sound, u16 timer)
{
    u8 trackGroup;
    const u8* pHeader;

    trackGroup = sSoundDataEntries[sound].trackGroundNumber; 
    pHeader = sSoundDataEntries[sound].pHeader;

    if (sArray_808cee2[trackGroup] == 0 || !(gSoundQueue[trackGroup].exists & 3) || gSoundQueue[trackGroup].priority <= pHeader[2])
    {
        if (timer == 0)
        {
            gSoundQueue[trackGroup].exists = 1;
            gSoundQueue[trackGroup].fadingTimer = 0;
        }
        else
        {
            gSoundQueue[trackGroup].exists = 2;
            gSoundQueue[trackGroup].fadingTimer = timer;
        }

        gSoundQueue[trackGroup].priority = pHeader[2];
        gSoundQueue[trackGroup].pHeader = pHeader;
    }
}

/**
 * @brief 4014 | 70 | Fades or stops a sound
 * 
 * @param sound Sound ID
 * @param timer Fading timer (0 to stop)
 */
void StopOrFadeSound(u16 sound, u16 timer)
{
    u8 trackGroup;
    const u8* pHeader;
    struct TrackData* pTrack;

    trackGroup = sSoundDataEntries[sound].trackGroundNumber; 
    pHeader = sSoundDataEntries[sound].pHeader;

    if (gSoundQueue[trackGroup].exists & 3 && pHeader == gSoundQueue[trackGroup].pHeader)
        gSoundQueue[trackGroup].exists = 0;
    else
    {
        pTrack = sMusicTrackDataROM[trackGroup].pTrack;
        if (pHeader == pTrack->pHeader)
        {
            if (timer == 0)
                stop_music_or_sound(pTrack);
            else
                ApplyMusicSoundFading(pTrack, timer);
        }
    }
}

/**
 * @brief 4084 | 4 | Empty function
 * 
 */
void Music_Empty_1(void)
{
    return;
}

/**
 * @brief 4088 | 4 | Empty function
 * 
 */
void Music_Empty_2(void)
{
    return;
}

/**
 * @brief 408c | c4 | Makes a backup of the track data 2 sound channels
 * 
 */
void BackupTrackData2SoundChannels(void)
{
    u8 trackID;
    u8 i;
    struct TrackData* pTrack;
    struct TrackVariables* pVariables;
    struct SoundChannel* pChannel;
    struct SoundChannel* pChannel2;

    i = 0;
    pTrack = sMusicTrackDataROM[2].pTrack;

    if (!pTrack->occupied)
    {
        pTrack->occupied = TRUE;
        if (!(pTrack->unknown_1E & 1) && pTrack->flags & 2)
        {
            pTrack->unknown_1E = 1;

            trackID = 0;
            pVariables  = pTrack->pVariables;

            while (trackID < pTrack->amountOfTracks)
            {
                if (!(pVariables->channel & 0xC0))
                {
                    if (pVariables->pSoundPSG)
                        clear_registers_for_psg(pVariables->pSoundPSG, (pVariables->channel & 7) - 1); // Undefined, definition required

                    if (pVariables->pChannel)
                    {
                        pChannel = pVariables->pChannel;
                        while (pChannel)
                        {
                            gSoundChannelTrack2Backup[i].pChannel = pChannel;
                            gSoundChannelTrack2Backup[i].channel = *pChannel;

                            i++;
                            pChannel->unknown_0 = 0;
                            pChannel->pVariables = NULL;

                            pChannel2 = pChannel->pChannel2;
                            pChannel->pChannel2 = NULL;
                            pChannel->pChannel1 = NULL;
                            pChannel = pChannel2;
                        }
                    }
                }

                trackID++;
                pVariables++;
            }
        }
    }

    pTrack->occupied = FALSE;
}

/**
 * @brief 4150 | 9c | Retrieves the track data 2 sound channels
 * 
 */
void RetrieveTrackData2SoundChannels(void)
{
    u8 i;
    u8 trackID;
    struct TrackData* pTrack;
    struct TrackVariables* pVariables;
    struct SoundChannel* pChannel;

    i = 0;
    pTrack = sMusicTrackDataROM[2].pTrack;

    if (!pTrack->occupied)
    {
        pTrack->occupied = TRUE;

        if (pTrack->unknown_1E & 1)
        {
            pTrack->unknown_1E &= ~1;
            trackID = 0;
            pVariables = pTrack->pVariables;

            while (trackID < pTrack->amountOfTracks)
            {
                if (!(pVariables->channel & 0xC0))
                {
                    if (pVariables->pChannel)
                    {
                        pChannel = pVariables->pChannel;
                        while (pChannel)
                        {
                            unk_20a4(pChannel);

                            *pChannel = gSoundChannelTrack2Backup[i].channel;
                            i++;

                            pChannel = pChannel->pChannel2;
                        }
                    }
                }

                trackID++;
                pVariables++;
            }
        }
    }

    pTrack->occupied = FALSE;
}

/**
 * @brief 41ec | 3c | Adds a delay before a music starts
 * 
 * @param pTrack Track data pointer
 * @param delay Delay (in frames)
 */
void DelayMusicStart(struct TrackData* pTrack, u16 delay)
{
    struct TrackVariables* pVariables;
    u8 trackID;

    if (!pTrack->occupied)
    {
        pTrack->occupied = TRUE;
        
        trackID = 0;
        pVariables = pTrack->pVariables;
        while (trackID < pTrack->amountOfTracks)
        {
            if (pVariables->unknown_0 != 0)
                pVariables->maybe_delayBeforeStart += delay;

            trackID++;
            pVariables++;
        }
    }

    pTrack->occupied = FALSE;
}

/**
 * @brief 4228 | 383 | Plays a sound test
 * 
 * @param musicTrack Music track
 */
void PlaySoundTest(u16 musicTrack)
{
    struct TrackData* pTrack;

    if (musicTrack != gMusicInfo.musicTrack)
    {
        pTrack = sMusicTrackDataROM[0].pTrack;
        stop_music_or_sound(pTrack);
        PlayMusic(musicTrack, 0x8);
        DelayMusicStart(pTrack, 30);
    }
}

/**
 * @brief 4260 | 1c | Replays a sound test
 * 
 * @param musicTrack Music track
 */
void ReplaySoundTest(u16 musicTrack)
{
    SoundPlay(musicTrack);
    DelayMusicStart(sMusicTrackDataROM[0].pTrack, 30);
}

/**
 * @brief 427c | 40 | Replays the file select music
 * 
 * @param timer Fading timer
 */
void CheckReplayFileSelectMusic(u16 timer)
{
    struct TrackData* pTrack;
    const u8* pHeader;

    pTrack = sMusicTrackDataROM[0].pTrack;
    pHeader = sSoundDataEntries[MUSIC_FILE_SELECT].pHeader;

    if (pTrack->flags & 2 && pHeader == pTrack->pHeader)
        UpdateMusicPriority(0x2);
    else
        FadeCurrentMusicAndQueueNextMusic(timer, MUSIC_FILE_SELECT, 0x2);
}

/**
 * @brief 42bc | 54 | To document
 * 
 * @param musicTrack Music track
 */
void unk_42bc(u16 musicTrack)
{
    if (gMusicInfo.occupied)
        return;

    gMusicInfo.occupied = TRUE;

    gMusicInfo.priority &= 0x80;
    if (musicTrack == MUSIC_NONE)
        musicTrack = 0x12B;

    init_track(sMusicTrackDataROM[0].pTrack, sSoundDataEntries[musicTrack].pHeader);
    
    gMusicInfo.unknown_20 = 0;
    gMusicInfo.musicTrack = musicTrack;

    // Doesn't remove the occupied flag
}
