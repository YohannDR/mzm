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
void unk_1ccc(struct TrackVariables* pVariables, s16 param_2);
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
void AudioCommand_Fine(struct TrackData* pTrack, struct TrackVariables* pVariables);
void unk_21b0(struct TrackData* pTrack, struct TrackVariables* pVariables);
void AudioCommand_PatternEnd(struct TrackVariables* pVariables);
void AudioCommand_Repeat(struct TrackVariables* pVariables);
void AudioCommand_Priority(struct TrackVariables* pVariables);
void AudioCommand_KeyShift(struct TrackVariables* pVariables);
void AudioCommand_Voice(struct TrackData* pTrack, struct TrackVariables* pVariables);
void AudioCommand_Volume(struct TrackVariables* pVariables);
void AudioCommand_PanPot(struct TrackVariables* pVariables);
void AudioCommand_PitchBend(struct TrackVariables* pVariables);
void AudioCommand_BendRange(struct TrackVariables* pVariables);
void AudioCommand_LfoSpeed(struct TrackVariables* pVariables);
void AudioCommand_LfoDelay(struct TrackVariables* pVariables);
void AudioCommand_ModulationDepth(struct TrackVariables* pVariables);
void AudioCommand_ModulationType(struct TrackVariables* pVariables);
void AudioCommand_Tune(struct TrackVariables* pVariables);
void AudioCommand_ExtendCommand(struct TrackVariables* pVariables);
void AudioCommand_EndOfTie(struct TrackVariables* pVariables);
void Music_EmptyCommand(struct TrackVariables* pVariables);
void ClearRegistersForPsg(struct PSGSoundData* pSound, u8 channel);
void ClearRegistersForPsg_Unused(struct PSGSoundData* pSound, u8 channel);

#endif /* AUDIO_H */
