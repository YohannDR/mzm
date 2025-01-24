#ifndef SCREEN_SHAKE_H
#define SCREEN_SHAKE_H

#include "types.h"

u8 ScreenShakeStartVertical(u8 duration, u8 intensity);
u8 ScreenShakeStartHorizontal(u8 duration, u8 intensity);
u8 ScreenShakeStartHorizontal_Unused(u8 duration);
s32 ScreenShakeUpdateVertical(void);
s32 ScreenShakeUpdateHorizontal(void);

#endif /* SCREEN_SHAKE_H */