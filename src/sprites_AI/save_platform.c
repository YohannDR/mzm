#include "save_platform.h"
#include "../../data/data.h"
#include "../globals.h"

const u32 sSavePlatformGFX[603];
const u16 sSavePlatformPAL[64];

const u16 sSavePlatformOAM_Idle_Frame0[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x200,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x200,
    0xf0, OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x2c6,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x2c6,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xff, 0x1e8, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x208
};

const u16 sSavePlatformOAM_Idle_Frame1[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x240,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x240,
    0xf0, OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x2c6,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x2c6,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xff, 0x1e8, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x208
};

const u16 sSavePlatformOAM_Idle_Frame2[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x204,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x204,
    0xf0, OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x2c6,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x2c6,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xff, 0x1e8, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x208
};

const u16 sSavePlatformOAM_Idle_Frame3[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x244,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x244,
    0xf0, OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x2c6,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x2c6,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xff, 0x1e8, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x208
};

const u16 sSavePlatformOAM_Opening_Frame0[55] = {
    0x12,
    0xf8, 0x1f4, OBJ_SPRITE_OAM | 0x2a1,
    0xf8, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x2a1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2c2,
    0xf8, 0x1e8, OBJ_SPRITE_OAM | 0x2a0,
    0xf8, OBJ_X_FLIP | 0x10, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e8, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xff, 0x1e7, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | 0x9, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x286,
    0xf0, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x214,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x248,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x248,
    0xf0, OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x2c6,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x2c6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2e0
};

const u16 sSavePlatformOAM_Opening_Frame1[55] = {
    0x12,
    0xf8, 0x1f3, OBJ_SPRITE_OAM | 0x2a1,
    0xf8, OBJ_X_FLIP | 0x5, OBJ_SPRITE_OAM | 0x2a1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2c2,
    0xf8, 0x1e7, OBJ_SPRITE_OAM | 0x2a0,
    0xf8, OBJ_X_FLIP | 0x11, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e7, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x9, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xff, 0x1e6, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x286,
    0xf0, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x214,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x20c,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x20c,
    0xf0, OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x2c6,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x2c6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2e0
};

const u16 sSavePlatformOAM_Opening_Frame2[55] = {
    0x12,
    0xf9, 0x1f2, OBJ_SPRITE_OAM | 0x2a1,
    0xf9, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x2a1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2c2,
    0xf9, 0x1e6, OBJ_SPRITE_OAM | 0x2a0,
    0xf9, OBJ_X_FLIP | 0x12, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e6, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1e6, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x280,
    0xf1, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x214,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x286,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x24c,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x24c,
    0xf0, OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x2c6,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x2c6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2e0
};

const u16 sSavePlatformOAM_Opened_Frame0[55] = {
    0x12,
    0xfa, 0x1f2, OBJ_SPRITE_OAM | 0x2a1,
    0xfa, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x2a1,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2c2,
    0xfa, 0x1e6, OBJ_SPRITE_OAM | 0x2a0,
    0xfa, OBJ_X_FLIP | 0x12, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1e6, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1e6, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x280,
    0xf2, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x214,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x286,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x208,
    0xf0, OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x2c6,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x2c6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2e0
};

const u16 sSavePlatformOAM_Opened_Frame1[55] = {
    0x12,
    0xfa, 0x1f2, OBJ_SPRITE_OAM | 0x2a1,
    0xfa, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x2a1,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2c2,
    0xfa, 0x1e6, OBJ_SPRITE_OAM | 0x2a0,
    0xfa, OBJ_X_FLIP | 0x12, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1e6, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1e6, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x280,
    0xf2, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x254,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x254,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x286,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x208,
    0xf0, OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x2c6,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x2c6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2e0
};

const u16 sSavePlatformOAM_Opened_Frame2[55] = {
    0x12,
    0xfa, 0x1f2, OBJ_SPRITE_OAM | 0x2a1,
    0xfa, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x2a1,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2c2,
    0xfa, 0x1e6, OBJ_SPRITE_OAM | 0x2a0,
    0xfa, OBJ_X_FLIP | 0x12, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1e6, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1e6, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x280,
    0xf2, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x216,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x286,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x208,
    0xf0, OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x2c6,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x2c6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2e0
};

const u16 sSavePlatformOAM_Opened_Frame5[55] = {
    0x12,
    0xfa, 0x1f2, OBJ_SPRITE_OAM | 0x2a1,
    0xfa, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x2a1,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2c2,
    0xfa, 0x1e6, OBJ_SPRITE_OAM | 0x2a0,
    0xfa, OBJ_X_FLIP | 0x12, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1e6, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1e6, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x280,
    0xf2, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x256,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x286,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x208,
    0xf0, OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x2c6,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x2c6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2e0
};

const u16 sSavePlatformPartOAM_TopIdle_Frame0[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xea, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_Y_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_Y_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x2f2,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x2f2,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x28a,
    0xe0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x28e,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x28e
};

const u16 sSavePlatformPartOAM_TopExtending_Frame0[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_Y_FLIP | 0x1e7, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x9, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_Y_FLIP | 0x1e7, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | OBJ_Y_FLIP | 0x9, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x24, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x2f2,
    OBJ_SHAPE_HORIZONTAL | 0x24, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x2f2,
    0x4, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x28a,
    0xe4, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x28e,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x28e
};

const u16 sSavePlatformPartOAM_TopExtending_Frame1[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_Y_FLIP | 0x1e6, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_Y_FLIP | 0xa, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_Y_FLIP | 0x1e6, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | OBJ_Y_FLIP | 0xa, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x28, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x2f2,
    OBJ_SHAPE_HORIZONTAL | 0x28, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x2f2,
    0x8, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x28a,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x28e,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x28e
};

const u16 sSavePlatformPartOAM_TopExtending_Frame2[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_Y_FLIP | 0x1e5, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_Y_FLIP | 0xb, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_Y_FLIP | 0x1e5, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | OBJ_Y_FLIP | 0xb, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x2c, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x2f2,
    OBJ_SHAPE_HORIZONTAL | 0x2c, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x2f2,
    0xc, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x28a,
    0xec, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x28e,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x28e
};

const u16 sSavePlatformPartOAM_TopExtending_Frame3[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_Y_FLIP | 0x1e4, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_Y_FLIP | 0xc, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_Y_FLIP | 0x1e4, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | OBJ_Y_FLIP | 0xc, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x32, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x2f2,
    OBJ_SHAPE_HORIZONTAL | 0x32, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x2f2,
    0x12, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0x12, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x28a,
    0xf2, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x28e,
    OBJ_SHAPE_VERTICAL | 0xf2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x28e
};

const u16 sSavePlatformPartOAM_TopExtending_Frame4[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_Y_FLIP | 0x1e5, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_Y_FLIP | 0xb, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_Y_FLIP | 0x1e5, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | OBJ_Y_FLIP | 0xb, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x31, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x2f2,
    OBJ_SHAPE_HORIZONTAL | 0x31, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x2f2,
    0x11, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x28a,
    0xf1, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x28e,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x28e
};

const u16 sSavePlatformPartOAM_TopExtended_Frame0[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_Y_FLIP | 0x1e6, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_Y_FLIP | 0xa, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_Y_FLIP | 0x1e6, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | OBJ_Y_FLIP | 0xa, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x30, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x2f2,
    OBJ_SHAPE_HORIZONTAL | 0x30, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x2f2,
    0x10, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x28a,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x28e,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x28e
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame0[4] = {
    0x1,
    0xcc, 0x1fc, OBJ_SPRITE_OAM | 0x27f
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame2[4] = {
    0x1,
    0xcc, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame4[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame6[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xc4, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    0xd4, 0x1fc, OBJ_SPRITE_OAM | 0x258
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame8[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame10[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xbc, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x218,
    0xdc, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame12[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xd8, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame14[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xb4, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xcc, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame16[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame18[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1fb, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fb, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fd, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fd, OBJ_SPRITE_OAM | 0x219
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame20[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f7, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f7, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1, OBJ_SPRITE_OAM | 0x219
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame22[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f4, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f4, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x219
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame24[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f3, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f3, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x5, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x5, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f3, OBJ_SPRITE_OAM | 0x21f
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame26[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f2, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f2, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x21a
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame28[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f1, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f1, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x7, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x7, OBJ_SPRITE_OAM | 0x21a
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame32[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x8, OBJ_SPRITE_OAM | 0x21b
};

const u16 sSavePlatformPartOAM_Tube_Unused_Frame1[7] = {
    0x2,
    0xb0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x210
};

const u16 sSavePlatformPartOAM_TubeShadow_Frame0[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1ec, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1ec, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0xc, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0xc, OBJ_SPRITE_OAM | 0x21c
};

const u16 sSavePlatformPartOAM_TubeShadow_Frame2[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1ee, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1ee, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0xa, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0xa, OBJ_SPRITE_OAM | 0x21d
};

const u16 sSavePlatformPartOAM_TubeShadow_Frame4[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f1, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f1, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x7, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x7, OBJ_SPRITE_OAM | 0x21d
};

const u16 sSavePlatformPartOAM_TubeShadow_Frame6[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f5, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f5, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x3, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x3, OBJ_SPRITE_OAM | 0x21d
};

const u16 sSavePlatformPartOAM_TubeShadow_Frame8[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f9, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f9, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1ff, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1ff, OBJ_SPRITE_OAM | 0x21c
};

const u16 sSavePlatformPartOAM_TubeShadow_Frame10[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x21e
};

const u16 sSavePlatformPartOAM_TubeDespawning_Frame0[31] = {
    0xa,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xbe, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd2, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xbe, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd2, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b
};

const u16 sSavePlatformPartOAM_TubeDespawning_Frame2[31] = {
    0xa,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xbc, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd4, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xbc, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b
};

const u16 sSavePlatformPartOAM_TubeDespawning_Frame4[31] = {
    0xa,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xb8, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd8, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b
};

const u16 sSavePlatformPartOAM_TubeDespawning_Frame6[31] = {
    0xa,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xb4, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xdc, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xb4, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b
};

const u16 sSavePlatformPartOAM_TubeDespawning_Frame8[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b
};

const u16 sSavePlatformPartOAM_TubeDespawning_Frame10[37] = {
    0xc,
    0xb0, 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    0xb0, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    0xb0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    0xe8, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    0xe8, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    0xb8, 0x1f3, OBJ_SPRITE_OAM | 0x23f,
    0xb4, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    0xb4, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    0xe0, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x23f,
    0xe4, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    0xe4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b
};

const u16 sSavePlatformPartOAM_TubeDespawning_Frame12[19] = {
    0x6,
    0xb0, 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    0xb0, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    0xb0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    0xe8, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    0xe8, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b
};

const u16 sSavePlatformPartOAM_TubeDespawning_Frame14[19] = {
    0x6,
    0xac, 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    0xac, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    0xac, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    0xec, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    0xec, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    0xec, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b
};

const u16 sSavePlatformPartOAM_Ray_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x1296,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1296
};

const u16 sSavePlatformPartOAM_Ray_Frame2[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x12b6,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x12b6
};

const u16 sSavePlatformPartOAM_Ray_Frame4[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x12d6,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x12d6
};

const u16 sSavePlatformPartOAM_Ray_Frame6[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x12f6,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x12f6
};

const u16 sSavePlatformPartOAM_Empty[4] = {
    0x1,
    0xfc, 0x1fc, 0x25f
};

const struct FrameData sSavePlatformOAM_Idle[7] = {
    sSavePlatformOAM_Idle_Frame0,
    0xC,
    sSavePlatformOAM_Idle_Frame1,
    0xC,
    sSavePlatformOAM_Idle_Frame2,
    0xC,
    sSavePlatformOAM_Idle_Frame3,
    0xC,
    sSavePlatformOAM_Idle_Frame2,
    0xC,
    sSavePlatformOAM_Idle_Frame1,
    0xC,
    NULL,
    0x0
};

const struct FrameData sSavePlatformOAM_Opening[4] = {
    sSavePlatformOAM_Opening_Frame0,
    0x4,
    sSavePlatformOAM_Opening_Frame1,
    0x4,
    sSavePlatformOAM_Opening_Frame2,
    0x4,
    NULL,
    0x0
};

const struct FrameData sSavePlatformOAM_Opened[7] = {
    sSavePlatformOAM_Opened_Frame0,
    0xC,
    sSavePlatformOAM_Opened_Frame1,
    0xC,
    sSavePlatformOAM_Opened_Frame2,
    0xC,
    sSavePlatformOAM_Opened_Frame1,
    0xC,
    sSavePlatformOAM_Opened_Frame0,
    0xC,
    sSavePlatformOAM_Opened_Frame5,
    0xC,
    NULL,
    0x0
};

const struct FrameData sSavePlatformOAM_Saving[7] = {
    sSavePlatformOAM_Opened_Frame0,
    0x2,
    sSavePlatformOAM_Opened_Frame1,
    0x2,
    sSavePlatformOAM_Opened_Frame2,
    0x2,
    sSavePlatformOAM_Opened_Frame1,
    0x2,
    sSavePlatformOAM_Opened_Frame0,
    0x2,
    sSavePlatformOAM_Opened_Frame5,
    0x2,
    NULL,
    0x0
};

const struct FrameData sSavePlatformOAM_OpenedOff[2] = {
    sSavePlatformOAM_Opened_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sSavePlatformOAM_Closing[4] = {
    sSavePlatformOAM_Opening_Frame2,
    0x4,
    sSavePlatformOAM_Opening_Frame1,
    0x4,
    sSavePlatformOAM_Opening_Frame0,
    0x4,
    NULL,
    0x0
};

const struct FrameData sSavePlatformOAM_IdleOff[2] = {
    sSavePlatformOAM_Idle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sSavePlatformPartOAM_TopIdle[2] = {
    sSavePlatformPartOAM_TopIdle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sSavePlatformPartOAM_TopExtending[6] = {
    sSavePlatformPartOAM_TopExtending_Frame0,
    0x4,
    sSavePlatformPartOAM_TopExtending_Frame1,
    0x4,
    sSavePlatformPartOAM_TopExtending_Frame2,
    0x4,
    sSavePlatformPartOAM_TopExtending_Frame3,
    0x4,
    sSavePlatformPartOAM_TopExtending_Frame4,
    0x6,
    NULL,
    0x0
};

const struct FrameData sSavePlatformPartOAM_TopExtended[2] = {
    sSavePlatformPartOAM_TopExtended_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sSavePlatformPartOAM_TopRetracting[6] = {
    sSavePlatformPartOAM_TopExtending_Frame4,
    0x6,
    sSavePlatformPartOAM_TopExtending_Frame3,
    0x4,
    sSavePlatformPartOAM_TopExtending_Frame2,
    0x4,
    sSavePlatformPartOAM_TopExtending_Frame1,
    0x4,
    sSavePlatformPartOAM_TopExtending_Frame0,
    0x4,
    NULL,
    0x0
};

const struct FrameData sSavePlatformPartOAM_TubeSpawning[39] = {
    sSavePlatformPartOAM_TubeSpawning_Frame0,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame2,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame4,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame6,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame8,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame10,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame12,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame14,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame16,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame18,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame20,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame22,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame24,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame26,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame28,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame28,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame32,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame32,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame32,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    NULL,
    0x0
};

const struct FrameData sSavePlatformPartOAM_TubeShadow[13] = {
    sSavePlatformPartOAM_TubeShadow_Frame0,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeShadow_Frame2,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeShadow_Frame4,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeShadow_Frame6,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeShadow_Frame8,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeShadow_Frame10,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    NULL,
    0x0
};

const struct FrameData sSavePlatformPartOAM_TubeIdle[3] = {
    sSavePlatformPartOAM_TubeSpawning_Frame32,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    NULL,
    0x0
};

const struct FrameData sSavePlatformPartOAM_Tube_Unused[5] = {
    sSavePlatformPartOAM_TubeSpawning_Frame32,
    0x1,
    sSavePlatformPartOAM_Tube_Unused_Frame1,
    0x1,
    sSavePlatformPartOAM_TubeSpawning_Frame32,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    NULL,
    0x0
};

const struct FrameData sSavePlatformPartOAM_TubeDespawning[17] = {
    sSavePlatformPartOAM_TubeDespawning_Frame0,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeDespawning_Frame2,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeDespawning_Frame4,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeDespawning_Frame6,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeDespawning_Frame8,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeDespawning_Frame10,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeDespawning_Frame12,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_TubeDespawning_Frame14,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    NULL,
    0x0
};

const struct FrameData sSavePlatformPartOAM_Ray[9] = {
    sSavePlatformPartOAM_Ray_Frame0,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_Ray_Frame2,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_Ray_Frame4,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    sSavePlatformPartOAM_Ray_Frame6,
    0x1,
    sSavePlatformPartOAM_Empty,
    0x1,
    NULL,
    0x0
};


/**
 * @brief 1f9b0 | 38 | Checks if Samus is standing on a save platform
 * 
 * @return u8 1 if standing on, 0 otherwise
 */
u8 SavePlatformDetectSamus(void)
{
    u8 colliding;
    i32 samusY;
    i32 samusX;
    i32 spriteY;
    i32 spriteX;

    colliding = FALSE;
    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;

    if (samusY == spriteY - (BLOCK_SIZE - 1) && (spriteX - BLOCK_SIZE) < samusX && (spriteX + BLOCK_SIZE) > samusX)
        colliding = TRUE;

    return colliding;
}

/**
 * @brief 1f9e8 | 128 | Initializes a save platform sprite
 * 
 */
void SavePlatformInit(void)
{
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.yPositionSpawn = 0x0;
    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

    gCurrentSprite.hitboxTopOffset = -0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;

    if (gAlarmTimer != 0x0)
        gCurrentSprite.workVariable2 = TRUE;
    else
        gCurrentSprite.workVariable2 = FALSE;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.timer = 0xA;

    if (gCurrentSprite.workVariable2 || EscapeDetermineTimer() != ESCAPE_NONE)
    {
        gCurrentSprite.pOam = sSavePlatformOAM_OpenedOff;
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_OFF;
    }
    else if (gIsLoadingFile)
    {
        SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_PART, SAVE_PLATFORM_PART_TUBE, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

        gCurrentSprite.pOam = sSavePlatformOAM_IdleOff;
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_RELEASE_SAMUS;
        gCurrentSprite.yPositionSpawn = 0x154;
    }
    else
    {
        gCurrentSprite.pOam = sSavePlatformOAM_Idle;
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_IDLE;
    }

    gCurrentSprite.arrayOffset = SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_PART, SAVE_PLATFORM_PART_TOP,
        gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
        gCurrentSprite.yPosition - BLOCK_SIZE * 8, gCurrentSprite.xPosition, 0x0);
}

/**
 * @brief 1fb10 | 58 | Handles a save platform being idle
 * 
 */
void SavePlatformSamusDetection(void)
{
    if (SavePlatformDetectSamus() && !SpriteUtilCheckCrouchinOrMorphed())
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            gCurrentSprite.pose = SAVE_PLATFORM_POSE_OPENING;
            gCurrentSprite.pOam = sSavePlatformOAM_Opening;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            SoundPlay(0x112);
        }
    }
    else
        gCurrentSprite.timer = 0xA;
}

/**
 * @brief 1fb68 | 2c | Handles a save platform opening
 * 
 */
void SavePlatformCheckOpeningAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_OPENED;
        gCurrentSprite.pOam = sSavePlatformOAM_Opened;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 1fb94 | 80 | Handles a save platform being opened
 * 
 */
void SavePlatformSecondSamusDetection(void)
{
    if (SavePlatformDetectSamus())
    {
        if (!SpriteUtilCheckCrouchinOrMorphed())
        {
            gCurrentSprite.pose = SAVE_PLATFORM_POSE_SAVE_PROMPT;
            gCurrentSprite.timer = 0x4;
            gSamusData.xPosition = gCurrentSprite.xPosition;
            if (gSamusData.invincibilityTimer != 0x0)
                gSamusData.invincibilityTimer = 0x0;
            SamusSetPose(SPOSE_TURNING_FROM_FACING_THE_FOREGROUND);
            gSamusData.timer = 0x1;
            gDisablePause = TRUE;
        }
    }
    else
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_CLOSING;
        gCurrentSprite.pOam = sSavePlatformOAM_Closing;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        SoundPlay(0x113);
    }
}

/**
 * @brief 1fc14 | 30 | Handles a save platform closing
 * 
 */
void SavePlatformCheckClosingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_IDLE;
        gCurrentSprite.pOam = sSavePlatformOAM_Idle;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.timer = 0xA;
    }
}

/**
 * @brief 1fc44 | 34 | Handles a save platform releasing Samus
 * 
 */
void SavePlatformReleaseSamus(void)
{
    if (gCurrentSprite.yPositionSpawn != 0x0)
        gCurrentSprite.yPositionSpawn--;
    else
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_AFTER_SAVE;
        SamusSetPose(SPOSE_FACING_THE_FOREGROUND);
        gDisablePause = FALSE;
    }
}

/**
 * @brief 1fc78 | 38 | Handles a save platform after a save
 * 
 */
void SavePlatformSamusDetectionOut(void)
{
    if (!SavePlatformDetectSamus())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_CLOSING;
        gCurrentSprite.pOam = sSavePlatformOAM_Closing;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        SoundPlay(0x113);
    }
}

/**
 * @brief 1fcb0 | d0 | Handles a save platform during a save prompt
 * 
 */
void SavePlatformSavePrompt(void)
{
    u8 ramSlot;

    if (gCurrentSprite.timer != 0x0)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
            gCurrentSprite.workVariable = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_SAVE_PROMPT, 0x6,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
    else
    {
        // Item banner
        ramSlot = gCurrentSprite.workVariable;
        if (gSpriteData[ramSlot].pose == ITEM_BANNER_POSE_REMOVAL_ANIMATION)
        {
            if (gSpriteData[ramSlot].workVariable == TRUE)
            {
                gCurrentSprite.pOam = sSavePlatformOAM_Saving;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;

                gCurrentSprite.pose = SAVE_PLATFORM_POSE_SAVING;
                SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_PART, SAVE_PLATFORM_PART_TUBE, gCurrentSprite.spritesetGFXSlot,
                    gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

                gSpriteData[gCurrentSprite.arrayOffset].pose = SAVE_PLATFORM_PART_POSE_TOP_EXTENDING_INIT;
                gSamusData.invincibilityTimer = 0x0;
                SoundPlay(0x114);
            }
            else
            {
                gCurrentSprite.pose = SAVE_PLATFORM_POSE_DELAY_BEFORE_RELEASING;
                gCurrentSprite.timer = 0xA;
            }
        }
    }
}

/**
 * @brief 1fd80 | 40 | Handles a save platform saving
 * 
 */
void SavePlatformSaving(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.arrayOffset;
    if (gCurrentSprite.currentAnimationFrame & 0x1)
        gCurrentSprite.paletteRow = 0x0;
    else
        gCurrentSprite.paletteRow = 0x2;

    gSpriteData[ramSlot].paletteRow = gCurrentSprite.paletteRow;
}

/**
 * @brief 1fdc0 | 44 | Initializes a save platform to be opened (off)
 * 
 */
void SavePlatformOpenedOffInit(void)
{
    gCurrentSprite.pOam = sSavePlatformOAM_OpenedOff;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = SAVE_PLATFORM_POSE_SPAWN_SAVE_DONE_MESSAGE;
    gCurrentSprite.timer = 0x3C;
    gCurrentSprite.paletteRow = 0x0;
    gSpriteData[gCurrentSprite.arrayOffset].paletteRow = 0x0;
}

/**
 * @brief 1fe04 | 44 | Spawns the "save complete" message
 * 
 */
void SavePlatformSpawnSaveDoneMessage(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_WAIT_FOR_MESSAGE_OUT;
        gCurrentSprite.workVariable = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_SAVE_COMPLETE, 0x6,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 1fe48 | 38 | Handles a save platform waiting for the "Save complete" message to be done
 * 
 */
void SavePlatformCheckMessageBannerOut(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.workVariable;
    if (gSpriteData[ramSlot].pose == ITEM_BANNER_POSE_REMOVAL_ANIMATION)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_DELAY_BEFORE_RELEASING;
        gCurrentSprite.timer = 0xA;
    }
}

/**
 * @brief 1fe80 | 24 | Handles the delay before a save platform releases Samus
 * 
 */
void SavePlatformDelayBeforeReleasingSamus(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_RELEASE_SAMUS;
}

/**
 * @brief 1fea4 | 16c | Initializes a save platform part sprite
 * 
 */
void SavePlatformPartInit(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.hitboxTopOffset = -0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    switch (gCurrentSprite.roomSlot)
    {
        case SAVE_PLATFORM_PART_TUBE:
            gCurrentSprite.drawDistanceTopOffset = 0x50;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;
            if (gSpriteData[ramSlot].pose == SAVE_PLATFORM_POSE_RELEASE_SAMUS)
            {
                gCurrentSprite.pOam = sSavePlatformPartOAM_TubeIdle;
                gCurrentSprite.yPositionSpawn = 0x136;
                gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_IDLE;
            }
            else
            {
                gCurrentSprite.pOam = sSavePlatformPartOAM_TubeSpawning;
                gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_SPAWNING;
            }
            break;

        case SAVE_PLATFORM_PART_TUBE_SHADOW:
            gCurrentSprite.drawOrder = 0xC;
            gCurrentSprite.pOam = sSavePlatformPartOAM_TubeShadow;
            gCurrentSprite.drawDistanceTopOffset = 0x50;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;
            gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_SHADOW_IDLE;
            break;

        case SAVE_PLATFORM_PART_RAY:
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pOam = sSavePlatformPartOAM_Ray;
            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;
            gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_RAY_IDLE;
            gCurrentSprite.timer = 0x60;
            break;

        case SAVE_PLATFORM_PART_TOP:
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.drawDistanceTopOffset = 0x20;
            gCurrentSprite.drawDistanceBottomOffset = 0x40;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x20;
            gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TOP_IDLE;
            if (gSpriteData[ramSlot].pose == SAVE_PLATFORM_POSE_RELEASE_SAMUS)
                gCurrentSprite.pOam = sSavePlatformPartOAM_TopExtended;
            else
                gCurrentSprite.pOam = sSavePlatformPartOAM_TopIdle;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 20010 | 4 | Empty function
 * 
 */
void SavePlatformPart_Empty(void)
{
    return;
}

/**
 * @brief 20014 | 1c | Initializes the top part to be extending
 * 
 */
void SavePlatformPartExtendingInit(void)
{
    gCurrentSprite.pOam = sSavePlatformPartOAM_TopExtending;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TOP_EXTENDING;
}

/**
 * @brief 20030 | 2c | Handles the top part extending
 * 
 */
void SavePlatformPartTopExtending(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TOP_IDLE;
        gCurrentSprite.pOam = sSavePlatformPartOAM_TopExtended;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 2005c | 34 | Initializes the top part to be retracting
 * 
 */
void SavePlatformPartTopRetractingInit(void)
{
    gCurrentSprite.pOam = sSavePlatformPartOAM_TopRetracting;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TOP_RETRACTING;
    gSamusData.timer = 0x1;
    SoundPlay(0x115);
}

/**
 * @brief 20090 | 2c | Handles the top part retracting
 * 
 */
void SavePlatformPartTopRetracting(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TOP_IDLE;
        gCurrentSprite.pOam = sSavePlatformPartOAM_TopIdle;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 200bc | 50 | Handles the tube part spawning
 * 
 */
void SavePlatformPartTubeSpawning(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_CHECK_SHADOW_DISAPPEARED;
        gCurrentSprite.pOam = sSavePlatformPartOAM_TubeIdle;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.workVariable = SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_PART, SAVE_PLATFORM_PART_TUBE_SHADOW,
            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 2010c | 54 | Handles the tube part spawning the ray part
 * 
 */
void SavePlatformPartSpawnRay(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.workVariable;
    if (gSpriteData[ramSlot].status == 0x0)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_IDLE;
        gCurrentSprite.yPositionSpawn = 0x78;
        SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_PART, SAVE_PLATFORM_PART_RAY, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 20160 | 30 | Handles the tube part being idle
 * 
 */
void SavePlatformPartTubeIdle(void)
{
    gCurrentSprite.yPositionSpawn--;
    if (gCurrentSprite.yPositionSpawn == 0x0)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_DESPAWNING;
        gCurrentSprite.pOam = sSavePlatformPartOAM_TubeDespawning;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 20190 | 3c | handles the tube part despawning
 * 
 */
void SavePlatformPartTubeDespawning(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.status = 0x0;
        gSpriteData[gSpriteData[gCurrentSprite.primarySpriteRAMSlot].arrayOffset].pose = SAVE_PLATFORM_PART_POSE_TOP_RETRACTING_INIT;
    }
}

/**
 * @brief 201cc | 18 | Handles the tube shadow part being idle
 * 
 */
void SavePlatformPartTubeShadowIdle(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}

/**
 * @brief 201e4 | 44 | Handles the ray part being idle
 * 
 */
void SavePlatformPartRayIdle(void)
{
    gCurrentSprite.yPosition -= 0x4;
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gSpriteData[gCurrentSprite.primarySpriteRAMSlot].pose = SAVE_PLATFORM_POSE_OPENED_OFF_INIT;
        gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 20228 | 1a8 | Save platform AI
 * 
 */
void SavePlatform(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            SavePlatformInit();
            break;

        case SAVE_PLATFORM_POSE_IDLE:
            SavePlatformSamusDetection();
            break;

        case SAVE_PLATFORM_POSE_OPENING:
            SavePlatformCheckOpeningAnimEnded();
            break;

        case SAVE_PLATFORM_POSE_OPENED:
            SavePlatformSecondSamusDetection();
            break;

        case SAVE_PLATFORM_POSE_CLOSING:
            SavePlatformCheckClosingAnimEnded();
            break;

        case SAVE_PLATFORM_POSE_RELEASE_SAMUS:
            SavePlatformReleaseSamus();
            break;

        case SAVE_PLATFORM_POSE_AFTER_SAVE:
            SavePlatformSamusDetectionOut();
            break;

        case SAVE_PLATFORM_POSE_SAVE_PROMPT:
            SavePlatformSavePrompt();
            break;

        case SAVE_PLATFORM_POSE_SAVING:
            SavePlatformSaving();
            break;

        case SAVE_PLATFORM_POSE_OPENED_OFF_INIT:
            SavePlatformOpenedOffInit();
            break;

        case SAVE_PLATFORM_POSE_SPAWN_SAVE_DONE_MESSAGE:
            SavePlatformSpawnSaveDoneMessage();
            break;

        case SAVE_PLATFORM_POSE_WAIT_FOR_MESSAGE_OUT:
            SavePlatformCheckMessageBannerOut();
            break;

        case SAVE_PLATFORM_POSE_DELAY_BEFORE_RELEASING:
            SavePlatformDelayBeforeReleasingSamus();
    }
}

/**
 * @brief 203d0 | 194 | Save platform part AI
 * 
 */
void SavePlatformPart(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            SavePlatformPartInit();
            break;

        case SAVE_PLATFORM_PART_POSE_TUBE_SPAWNING:
            SavePlatformPartTubeSpawning();
            break;

        case SAVE_PLATFORM_PART_POSE_TUBE_CHECK_SHADOW_DISAPPEARED:
            SavePlatformPartSpawnRay();
            break;

        case SAVE_PLATFORM_PART_POSE_TUBE_IDLE:
            SavePlatformPartTubeIdle();
            break;

        case SAVE_PLATFORM_PART_POSE_TUBE_DESPAWNING:
            SavePlatformPartTubeDespawning();
            break;

        case SAVE_PLATFORM_PART_POSE_TUBE_SHADOW_IDLE:
            SavePlatformPartTubeShadowIdle();
            break;

        case SAVE_PLATFORM_PART_POSE_RAY_IDLE:
            SavePlatformPartRayIdle();
            break;

        case SAVE_PLATFORM_PART_POSE_TOP_IDLE:
            SavePlatformPart_Empty();
            break;

        case SAVE_PLATFORM_PART_POSE_TOP_EXTENDING_INIT:
            SavePlatformPartExtendingInit();
            break;

        case SAVE_PLATFORM_PART_POSE_TOP_EXTENDING:
            SavePlatformPartTopExtending();
            break;

        case SAVE_PLATFORM_PART_POSE_TOP_RETRACTING_INIT:
            SavePlatformPartTopRetractingInit();
            break;

        case SAVE_PLATFORM_PART_POSE_TOP_RETRACTING:
            SavePlatformPartTopRetracting();
    }
}