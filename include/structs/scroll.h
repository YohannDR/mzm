#ifndef SCROLL_STRUCT_H
#define SCROLL_STRUCT_H

#include "types.h"
#include "macros.h"

#define SCROLL_SUB_DATA_SIZE 8
#define SCROLL_DATA_SIZE(nbrScrolls) (2 + SCROLL_SUB_DATA_SIZE * nbrScrolls)

#define SCROLL_NOT_WITHIN_FLAG 0
#define SCROLL_WITHIN_FLAG 2

#define LOCK_SCREEN_TYPE_NONE 0
#define LOCK_SCREEN_TYPE_POSITION 1
#define LOCK_SCREEN_TYPE_MIDDLE 2

#define SCROLL_X_ANCHOR (SCREEN_SIZE_X_SUB_PIXEL / 2)
#define SCROLL_Y_ANCHOR (FRACT_MUL(SCREEN_SIZE_Y_SUB_PIXEL, 3, 5))

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
    s8 xVelocity;
    s8 yVelocity;
};

struct LockScreen {
    u8 lock;
    u16 xPositionCenter;
    u16 yPositionCenter;
};

struct Unk_3005714 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
};


extern u8 gDisableScrolling;
extern u16 gSlowScrollingTimer;
extern u8 gSkipDoorTransition;
extern struct Scroll gCurrentScrolls[2];
extern struct Camera gCamera;
extern struct LockScreen gLockScreen;
extern s8 gScreenYOffset;
extern s16 gScreenXOffset;

extern u8 gFreeMovementLockCamera;
extern struct Unk_3005714 gUnk_3005714;
extern const u8* gCurrentRoomScrollDataPointer;

#endif
