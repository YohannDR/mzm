#ifndef SCREEN_SHAKE_STRUCT_H
#define SCREEN_SHAKE_STRUCT_H

#include "types.h"

struct ScreenShake {
    u8 timer;
    u8 delay;
    u8 intensity;
    u8 direction;
};

#define SWITCH_DIRECTION 1
#define SHAKE_UP -1
#define SHAKE_DOWN 1
#define SHAKE_LEFT -1
#define SHAKE_RIGHT 1

extern u8 gScreenShakeXOffset; // set but never read
extern u8 gScreenShakeYOffset; // set but never read
extern u16 gScreenShakeRelated; // set to 0 but never updated
extern struct ScreenShake gScreenShakeY;
extern struct ScreenShake gScreenShakeX;

#endif