#ifndef TRACK_INTERNAL_H
#define TRACK_INTERNAL_H

#include "structs/audio.h"

u8 InitTrack(struct TrackData* pTrack, const u32* pHeader);
void StopMusicOrSound(struct TrackData* pTrack);
void ResetTrack(struct TrackData* pTrack);
u32 unk_4cfc(struct TrackData* pTrack);
void unk_4d1c(struct TrackData* pTrack, struct TrackVariables* pVariables);
void UpdateAudio(void);
void unk_4e10(struct TrackVariables* pVariables);
void unk_4eb4(struct TrackVariables* pVariables);
void unk_4f10(struct TrackVariables* pVariables);
void unk_4f8c(struct SoundChannel* pChannel, struct TrackVariables* pVariables, s32 param_3);
void AudioCommand_Goto(struct TrackVariables* pVariables);
void AudioCommand_PatternPlay(struct TrackVariables* pVariables);
void UploadSampleToWaveRAM(const u32* pSample);
void unk_5104(struct PSGSoundData* pSound);

#endif /* TRACK_INTERNAL_H */
