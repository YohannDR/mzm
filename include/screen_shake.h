#ifndef SCREEN_SHAKE_H
#define SCREEN_SHAKE_H

#include "types.h"

struct ScreenShake {
    u8 timer;
    u8 loopCounter;
    u8 unknown; // intensity ?
    u8 unknown2;
};

u8 ScreenShakeStartVertical(u8 duration, u8 unk);
u8 ScreenShakeStartHorizontal(u8 duration, u8 unk);
u8 ScreenShakeStartHorizontal_Unused(u8 duration);
i32 ScreenShakeUpdateVertical(void);
i32 ScreenShakeUpdateHorizontal(void);

#endif /* SCREEN_SHAKE_H */