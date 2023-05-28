#include "data/sprites/save_platform.h"
#include "macros.h"

const u32 sSavePlatformGfx[603] = INCBIN_U32("data/sprites/SavePlatform.gfx.lz");
const u16 sSavePlatformPAL[64] = INCBIN_U16("data/sprites/SavePlatform.pal");

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
