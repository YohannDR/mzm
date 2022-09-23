#ifndef SCREEN_SHAKE_STRUCT_H
#define SCREEN_SHAKE_STRUCT_H

#include "types.h"

struct ScreenShake {
    u8 timer;
    u8 loopCounter;
    u8 unknown; // intensity ?
    u8 unknown2;
};

extern u8 gScreenShakeXRelated;
extern u8 gScreenShakeYRelated;
extern u16 gScreenShakeRelated;
extern struct ScreenShake gScreenShakeY;
extern struct ScreenShake gScreenShakeX;

#endif