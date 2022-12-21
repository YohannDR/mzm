#include "music_wrappers.h"
#include "audio_wrappers.h"

#include "data/audio.h"

#include "constants/audio.h"

void DMA2IntrCode(void)
{

}

void unk_33dc(void)
{

}

void unk_3458(void)
{

}

void unk_34ac(u8 param_1)
{

}

void unk_35d0(u8 param_1)
{

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

void unk_38d8(void)
{

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

void ReplayQueuedMusic(u8 queueFlags)
{

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

void PlayCurrentMusicTrack(void)
{

}

void DecreaseMusicVolume(void)
{

}

void ResetMusicVolume(void)
{

}

void QueueSound(u16 sound, u16 timer)
{

}

void stop_or_fade_sound(u16 sound, u16 timer)
{

}

void Music_Empty_1(void)
{

}

void Music_Empty_2(void)
{

}

void BackupTrackData2SoundChannels(void)
{

}

void RetrieveTrackData2SoundChannels(void)
{

}

void DelayMusicStart(struct TrackData* pTrack)
{

}

void PlaySoundTest(u16 musicTrack)
{

}

void ReplaySoundTest(u16 musicTrack)
{

}

void CheckReplayFileSelectMusic(u16 timer)
{

}

void unk_42bc(u16 musicTrack)
{

}
