#ifndef AUDIO_WRAPPERS_H
#define AUDIO_WRAPPERS_H

#include "structs/audio.h"

void InitializeAudio(void);
void DoSoundAction(u32 action);
void SetupSoundTransfer(void);
void SoundPlay(u16 sound);
void SoundStop(u16 sound);
void unk_2a38(struct TrackData* pTrack);
void StopAllMusicsAndSounds(void);
void unk_2a8c(void);
void FadeAllSounds(u16 timer);
void SoundPlayNotAlreadyPlaying(u16 sound);
void unk_2b64(u16 sound);
void unk_2bd4(u16 sound);
void unk_2c10(struct TrackData* pTrack);
void unk_2c4c(void);
void SoundFade(u16 sound, u16 timer);
void ApplyMusicSoundFading(struct TrackData* pTrack, u16 timer);
void ApplyRawMusicSoundFading(struct TrackData* pTrack, u16 timer);
void unk_2d2c(struct TrackData* pTrack);
void PlayFadingSound(u16 sound, u16 timer);
void InitFadingMusic(struct TrackData* pTrack, const u8* pHeader, u16 timer);
void unk_2e34(struct TrackData* pTrack, u16 timer);
void unk_2e6c(struct TrackData* pTrack);
void unk_2f00(u16 musicTrack1, u16 musicTrack2, u16 timer);
void unk_3028(struct TrackData* pTrack, u16 param_2);
void unk_3058(struct TrackData* pTrack, u16 variablesMask, u16 param_3);
void unk_30b4(struct TrackData* pTrack, u16 variablesMask, u16 param_3);
void unk_3110(struct TrackData* pTrack, u16 variablesMask, u8 param_3);
void unk_315c(struct TrackData* pTrack, u16 variablesMask, u8 param_3);
void unk_31a0(struct TrackData* pTrack, u16 variablesMask, u8 param_3);

#endif /* AUDIO_WRAPPERS_H */
