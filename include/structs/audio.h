#ifndef AUDIO_STRUCT_H
#define AUDIO_STRUCT_H

#include "types.h"

// Structs

struct MusicTrackInfo {
    u16 currentRoomTrack;
    u8 pauseScreenFlag;
    u8 takingNormalTransition;
    i8 unk;
};

extern u8 gStereoFlag;
extern struct MusicTrackInfo gMusicTrackInfo;

#endif