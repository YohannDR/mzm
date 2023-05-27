#ifndef SCREEN_SHAKE_STRUCT_H
#define SCREEN_SHAKE_STRUCT_H

#include "types.h"

struct ScreenShake {
    u8 timer;
    u8 loopCounter;
    u8 unk_2; // intensity ?
    u8 direction;
};

extern u8 gScreenShakeXOffset;
extern u8 gScreenShakeYOffset;
extern u16 gScreenShakeRelated;
extern struct ScreenShake gScreenShakeY;
extern struct ScreenShake gScreenShakeX;

#endif