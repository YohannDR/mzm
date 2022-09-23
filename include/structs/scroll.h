#ifndef SCROLL_STRUCT_H
#define SCROLL_STRUCT_H

#include "types.h"

struct Scroll {
    u8 within;
    u16 xEnd;
    u16 xStart;
    u16 yStart;
    u16 yEnd;
};

struct Camera {
    u16 xPosition;
    u16 yPosition;
    i8 xVelocity;
    i8 yVelocity;
};

struct LockScreen {
    u8 lock;
    u16 xPositionCenter;
    u16 yPositionCenter;
};

struct Unk_3005714 {
    i16 unk0;
    i16 unk2;
    i16 unk4;
    i16 unk6;
};

extern u8 gDisableScrolling;
extern u16 gSlowScrollingTimer;
extern u8 gSkipDoorTransition;
extern struct Scroll gCurrentScrolls[2];
extern struct Camera gCamera;
extern struct LockScreen gLockScreen;
extern i8 gScreenYOffset;
extern i16 gScreenXOffset;
extern struct Unk_3005714 gUnk_3005714;
extern u8* gCurrentRoomScrollDataPointer;

#endif