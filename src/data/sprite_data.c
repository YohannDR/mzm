#ifndef SPRITE_DATA_C
#define SPRITE_DATA_C

#include "../types.h"

// 2b0c94

static const u8 sOamXFlipOffsets[3][4] = {
    { 1, 2, 4, 8 },
    { 2, 4, 4, 8 },
    { 1, 1, 2, 4 }
};

static const u8 sOamYFlipOffsets[3][4] = {
    { 1, 2, 4, 8 },
    { 1, 1, 2, 4 },
    { 2, 4, 4, 8 }
};

static const u8 sSpriteRandomNumberTable[56] = {
    13, 2, 6, 8, 7, 9, 14, 10, 2, 4, 14, 4, 12,
    15, 13, 12, 11, 1, 3, 15, 0, 6, 7, 8, 11, 5,
    0, 3, 5, 1, 9, 10, 10, 0, 3, 0, 1, 0, 10, 0,
    6, 0, 3, 0, 10, 0, 8, 0, 1, 0, 10, 0, 9, 0, 8, 0
};

static const i16 sSpritesFallingCeilingSpeed[16] = {
    -4, -4, -4, -4, -4, -4, -8, -8, -8, -12,
    -12, -12, -12, -12, -16, SHORT_MAX
};

static const i16 sSpritesFallingSpeed[16] = {
    4, 4, 4, 4, 8, 8, 8, 8, 12, 12, 12,
    16, 16, 16, 20, SHORT_MAX
};

static const i16 sSpritesFallingSpeed_Unused[8] = {
    4, 6, 8, 10, 12,
    14, 16, SHORT_MAX,
};

static const i16 sSpritesFallingSpeed_Unused2[16] = {
    1, 1, 2, 2, 3, 3, 4, 4, 5, 5,
    6, 6, 7, 7, 8, SHORT_MAX
};

static const i16 sWorkerRobotSleepingFallingSpeed[10] = {
    4, 8, 8, 12, 12, 16, 16, 20, 24, SHORT_MAX
};

#endif