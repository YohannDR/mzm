#ifndef MUSIC_WRAPPERS_H
#define MUSIC_WRAPPERS_H

#include "structs/audio.h"

void DMA2IntrCode(void);
void unk_33dc(void);
void unk_3458(void);
void unk_34ac(u8 param_1);
void unk_35d0(u8 param_1);
void CheckSetNewMusicTrack(u16 musicTrack);
void unk_378c(u16 musicTrack);
void CheckPlayTransitionMusicTrack(void);
void unk_38d8(void);
void UpdateMusicAfterAlarmDisable(void);
u16 DetermineNewMusicTrack(u16 musicTrack);
void unk_39c8(void);
void PlayMusic(u16 musicTrack, u8 priority);
void unk_3a6c(void);
void FadeMusic(u16 timer);
void FadeMusicForDemo(u16 timer);
void FadeCurrentMusicAndQueueNextMusic(u16 timer, u16 musicTrack, u8 priority);
void FadeCurrentInsertMusicQueueCurrent(u16 timer, u16 musicTrack, u8 priority);
void unk_3bd0(u16 musicTrack, u16 timer);
void CheckPlayFadingMusic(u16 musicTrack, u16 timer, u8 priority);
void InsertMusicAndQueueCurrent(u16 musicTrack, u8 param_2);
void ReplayQueuedMusic(u8 queueFlags);
void unk_3e24(u16 timer);
void UpdateMusicPriority(u8 priority);
void PlayCurrentMusicTrack(void);
void DecreaseMusicVolume(void);
void ResetMusicVolume(void);
void QueueSound(u16 sound, u16 timer);
void StopOrFadeSound(u16 sound, u16 timer);
void Music_Empty_1(void);
void Music_Empty_2(void);
void BackupTrackData2SoundChannels(void);
void RetrieveTrackData2SoundChannels(void);
void DelayMusicStart(struct TrackData* pTrack, u16 delay);
void PlaySoundTest(u16 musicTrack);
void ReplaySoundTest(u16 musicTrack);
void CheckReplayFileSelectMusic(u16 timer);
void unk_42bc(u16 musicTrack);

#endif /* MUSIC_WRAPPERS_H */