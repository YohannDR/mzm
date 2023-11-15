#ifndef AUDIO_DATA_H
#define AUDIO_DATA_H

#include "structs/audio.h"

extern const u16 sUnk_808cad0[128];
extern const u8 sDelayNoteLengthTable[49];
extern const u8 sUnk_808cc01[60];
extern const u8 sUnk_808cc3d[16];
extern const u8 sUnk_808cc4d[19];

extern const u32 sNativeSampleRate[13];
extern const u32 sMusicPitchData[13];
extern const u16 sAudio_8ccc8[13];

extern const u8 sArray_808cce2[512];
extern const u8 sArray_808cee2[10];

extern void* const sDma1ControlPointer;
extern const u32 sDma1ControlValue;

extern const MusicFunc_T sMusicCommandFunctionPointers[30];

extern const struct TrackGroupROMData sMusicTrackDataRom[9];

extern const struct SoundEntry sSoundDataEntries[708];

#endif /* AUDIO_DATA_H */
