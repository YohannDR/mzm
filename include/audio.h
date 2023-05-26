#ifndef AUDIO_H
#define AUDIO_H

#include "types.h"
#include "structs/audio.h"

void UpdateMusic(void);
void UpdatePsgSounds(void);
void UpdateTrack(struct TrackData* pTrack);
void unk_1bf0(struct TrackVariables* pVariables);
void unk_1c18(struct TrackVariables* pVariables);
void unk_1c3c(struct TrackVariables* pVariables);
void unk_1ccc(struct TrackVariables* pVariables, i16 param_2);
void unk_1d5c(struct TrackVariables* pVariables);
void unk_1d78(struct TrackVariables* pVariables);
void unk_1ddc(struct TrackVariables* pVariables);
void unk_1de8(struct TrackVariables* pVariables);
void unk_1e2c(struct TrackData* pTrack, struct TrackVariables* pVariables);
void unk_1f3c(struct TrackData* pTrack, struct TrackVariables* pVariables);
void unk_1f90(struct TrackData* pTrack, struct TrackVariables* pVariables);
void unk_1fe0(struct TrackData* pTrack, struct TrackVariables* pVariables);
void unk_2030(struct PSGSoundData* pSound, struct TrackVariables* pVariables, u32 param_3);
void unk_20a4(struct SoundChannel* pChannel);
u16 GetNoteDelay(struct TrackVariables* pVariables, u8 param_2, u8 param_3);
void unk_2140(struct TrackData* pTrack, struct TrackVariables* pVariables);
void unk_21b0(struct TrackData* pTrack, struct TrackVariables* pVariables);
void unk_222c(struct TrackVariables* pVariables);
void unk_2264(struct TrackVariables* pVariables);
void unk_22a4(struct TrackVariables* pVariables);
void unk_22b4(struct TrackVariables* pVariables);
void unk_22cc(struct TrackData* pTrack, struct TrackVariables* pVariables);
void unk_238c(struct TrackVariables* pVariables);
void unk_23a0(struct TrackVariables* pVariables);
void unk_23b4(struct TrackVariables* pVariables);
void unk_23cc(struct TrackVariables* pVariables);
void unk_23e0(struct TrackVariables* pVariables);
void unk_23f0(struct TrackVariables* pVariables);
void unk_2400(struct TrackVariables* pVariables);
void unk_240c(struct TrackVariables* pVariables);
void unk_2418(struct TrackVariables* pVariables);
void unk_2430(struct TrackVariables* pVariables);
void unk_2460(struct TrackVariables* pVariables);
void Music_Empty(struct TrackVariables* pVariables);
void ClearRegistersForPsg(struct PSGSoundData* pSound, u8 channel);
void ClearRegistersForPsg_Unused(struct PSGSoundData* pSound, u8 channel);

#endif /* AUDIO_H */
