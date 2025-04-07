#include "data/sprites/save_platform.h"
#include "macros.h"

const u32 sSavePlatformGfx[603] = INCBIN_U32("data/sprites/SavePlatform.gfx.lz");
const u16 sSavePlatformPal[64] = INCBIN_U16("data/sprites/SavePlatform.pal");

const u16 sSavePlatformOAM_Idle_Frame0[OAM_DATA_SIZE(9)] = {
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

const u16 sSavePlatformOAM_Idle_Frame1[OAM_DATA_SIZE(9)] = {
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

const u16 sSavePlatformOAM_Idle_Frame2[OAM_DATA_SIZE(9)] = {
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

const u16 sSavePlatformOAM_Idle_Frame3[OAM_DATA_SIZE(9)] = {
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

const u16 sSavePlatformOAM_Opening_Frame0[OAM_DATA_SIZE(18)] = {
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

const u16 sSavePlatformOAM_Opening_Frame1[OAM_DATA_SIZE(18)] = {
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

const u16 sSavePlatformOAM_Opening_Frame2[OAM_DATA_SIZE(18)] = {
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

const u16 sSavePlatformOAM_Opened_Frame0[OAM_DATA_SIZE(18)] = {
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

const u16 sSavePlatformOAM_Opened_Frame1[OAM_DATA_SIZE(18)] = {
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

const u16 sSavePlatformOAM_Opened_Frame2[OAM_DATA_SIZE(18)] = {
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

const u16 sSavePlatformOAM_Opened_Frame5[OAM_DATA_SIZE(18)] = {
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

const u16 sSavePlatformPartOAM_TopIdle_Frame0[OAM_DATA_SIZE(12)] = {
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

const u16 sSavePlatformPartOAM_TopExtending_Frame0[OAM_DATA_SIZE(12)] = {
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

const u16 sSavePlatformPartOAM_TopExtending_Frame1[OAM_DATA_SIZE(12)] = {
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

const u16 sSavePlatformPartOAM_TopExtending_Frame2[OAM_DATA_SIZE(12)] = {
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

const u16 sSavePlatformPartOAM_TopExtending_Frame3[OAM_DATA_SIZE(12)] = {
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

const u16 sSavePlatformPartOAM_TopExtending_Frame4[OAM_DATA_SIZE(12)] = {
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

const u16 sSavePlatformPartOAM_TopExtended_Frame0[OAM_DATA_SIZE(12)] = {
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

const u16 sSavePlatformPartOAM_TubeSpawning_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xcc, 0x1fc, OBJ_SPRITE_OAM | 0x27f
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xcc, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame6[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xc4, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    0xd4, 0x1fc, OBJ_SPRITE_OAM | 0x258
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame8[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame10[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xbc, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x218,
    0xdc, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame12[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xd8, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame14[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xb4, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xcc, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame16[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame18[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1fb, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fb, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fd, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fd, OBJ_SPRITE_OAM | 0x219
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame20[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f7, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f7, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1, OBJ_SPRITE_OAM | 0x219
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame22[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f4, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f4, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x219
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame24[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f3, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f3, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x5, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x5, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f3, OBJ_SPRITE_OAM | 0x21f
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame26[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f2, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f2, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x21a
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame28[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f1, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f1, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x7, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x7, OBJ_SPRITE_OAM | 0x21a
};

const u16 sSavePlatformPartOAM_TubeSpawning_Frame32[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x8, OBJ_SPRITE_OAM | 0x21b
};

const u16 sSavePlatformPartOAM_Tube_Unused_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xb0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x210
};

const u16 sSavePlatformPartOAM_TubeShadow_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1ec, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1ec, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0xc, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0xc, OBJ_SPRITE_OAM | 0x21c
};

const u16 sSavePlatformPartOAM_TubeShadow_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1ee, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1ee, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0xa, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0xa, OBJ_SPRITE_OAM | 0x21d
};

const u16 sSavePlatformPartOAM_TubeShadow_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f1, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f1, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x7, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x7, OBJ_SPRITE_OAM | 0x21d
};

const u16 sSavePlatformPartOAM_TubeShadow_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f5, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f5, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x3, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x3, OBJ_SPRITE_OAM | 0x21d
};

const u16 sSavePlatformPartOAM_TubeShadow_Frame8[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1f9, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1f9, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1ff, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1ff, OBJ_SPRITE_OAM | 0x21c
};

const u16 sSavePlatformPartOAM_TubeShadow_Frame10[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x21e
};

const u16 sSavePlatformPartOAM_TubeDespawning_Frame0[OAM_DATA_SIZE(10)] = {
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

const u16 sSavePlatformPartOAM_TubeDespawning_Frame2[OAM_DATA_SIZE(10)] = {
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

const u16 sSavePlatformPartOAM_TubeDespawning_Frame4[OAM_DATA_SIZE(10)] = {
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

const u16 sSavePlatformPartOAM_TubeDespawning_Frame6[OAM_DATA_SIZE(10)] = {
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

const u16 sSavePlatformPartOAM_TubeDespawning_Frame8[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xb0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b
};

const u16 sSavePlatformPartOAM_TubeDespawning_Frame10[OAM_DATA_SIZE(12)] = {
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

const u16 sSavePlatformPartOAM_TubeDespawning_Frame12[OAM_DATA_SIZE(6)] = {
    0x6,
    0xb0, 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    0xb0, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    0xb0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    0xe8, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    0xe8, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b
};

const u16 sSavePlatformPartOAM_TubeDespawning_Frame14[OAM_DATA_SIZE(6)] = {
    0x6,
    0xac, 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    0xac, 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    0xac, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b,
    0xec, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21f,
    0xec, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    0xec, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21b
};

const u16 sSavePlatformPartOAM_Ray_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x1296,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1296
};

const u16 sSavePlatformPartOAM_Ray_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x12b6,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x12b6
};

const u16 sSavePlatformPartOAM_Ray_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x12d6,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x12d6
};

const u16 sSavePlatformPartOAM_Ray_Frame6[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x12f6,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x12f6
};

const u16 sSavePlatformPartOAM_Empty[4] = {
    0x1,
    0xfc, 0x1fc, 0x25f
};

const struct FrameData sSavePlatformOAM_Idle[7] = {
    [0] = {
        .pFrame = sSavePlatformOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sSavePlatformOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sSavePlatformOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sSavePlatformOAM_Idle_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = {
        .pFrame = sSavePlatformOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sSavePlatformOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformOAM_Opening[4] = {
    [0] = {
        .pFrame = sSavePlatformOAM_Opening_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sSavePlatformOAM_Opening_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sSavePlatformOAM_Opening_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformOAM_Opened[7] = {
    [0] = {
        .pFrame = sSavePlatformOAM_Opened_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sSavePlatformOAM_Opened_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sSavePlatformOAM_Opened_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sSavePlatformOAM_Opened_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = {
        .pFrame = sSavePlatformOAM_Opened_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sSavePlatformOAM_Opened_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformOAM_Saving[7] = {
    [0] = {
        .pFrame = sSavePlatformOAM_Opened_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSavePlatformOAM_Opened_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSavePlatformOAM_Opened_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSavePlatformOAM_Opened_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSavePlatformOAM_Opened_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSavePlatformOAM_Opened_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformOAM_OpenedOff[2] = {
    [0] = {
        .pFrame = sSavePlatformOAM_Opened_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformOAM_Closing[4] = {
    [0] = {
        .pFrame = sSavePlatformOAM_Opening_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sSavePlatformOAM_Opening_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sSavePlatformOAM_Opening_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformOAM_IdleOff[2] = {
    [0] = {
        .pFrame = sSavePlatformOAM_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOAM_TopIdle[2] = {
    [0] = {
        .pFrame = sSavePlatformPartOAM_TopIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOAM_TopExtending[6] = {
    [0] = {
        .pFrame = sSavePlatformPartOAM_TopExtending_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sSavePlatformPartOAM_TopExtending_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sSavePlatformPartOAM_TopExtending_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sSavePlatformPartOAM_TopExtending_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sSavePlatformPartOAM_TopExtending_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOAM_TopExtended[2] = {
    [0] = {
        .pFrame = sSavePlatformPartOAM_TopExtended_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOAM_TopRetracting[6] = {
    [0] = {
        .pFrame = sSavePlatformPartOAM_TopExtending_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sSavePlatformPartOAM_TopExtending_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sSavePlatformPartOAM_TopExtending_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sSavePlatformPartOAM_TopExtending_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sSavePlatformPartOAM_TopExtending_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOAM_TubeSpawning[39] = {
    [0] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame8,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame10,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [11] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame12,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [13] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [14] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame14,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [15] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [16] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame16,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [17] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [18] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame18,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [19] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [20] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame20,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [21] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [22] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame22,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [23] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [24] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame24,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [25] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [26] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame26,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [27] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [28] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame28,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [29] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [30] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame28,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [31] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [32] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame32,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [33] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [34] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame32,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [35] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [36] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame32,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [37] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [38] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOAM_TubeShadow[13] = {
    [0] = {
        .pFrame = sSavePlatformPartOAM_TubeShadow_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSavePlatformPartOAM_TubeShadow_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSavePlatformPartOAM_TubeShadow_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sSavePlatformPartOAM_TubeShadow_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sSavePlatformPartOAM_TubeShadow_Frame8,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sSavePlatformPartOAM_TubeShadow_Frame10,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [11] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOAM_TubeIdle[3] = {
    [0] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame32,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOAM_Tube_Unused[5] = {
    [0] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame32,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSavePlatformPartOAM_Tube_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSavePlatformPartOAM_TubeSpawning_Frame32,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOAM_TubeDespawning[17] = {
    [0] = {
        .pFrame = sSavePlatformPartOAM_TubeDespawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSavePlatformPartOAM_TubeDespawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSavePlatformPartOAM_TubeDespawning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sSavePlatformPartOAM_TubeDespawning_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sSavePlatformPartOAM_TubeDespawning_Frame8,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sSavePlatformPartOAM_TubeDespawning_Frame10,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [11] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = {
        .pFrame = sSavePlatformPartOAM_TubeDespawning_Frame12,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [13] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [14] = {
        .pFrame = sSavePlatformPartOAM_TubeDespawning_Frame14,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [15] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOAM_Ray[9] = {
    [0] = {
        .pFrame = sSavePlatformPartOAM_Ray_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSavePlatformPartOAM_Ray_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSavePlatformPartOAM_Ray_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sSavePlatformPartOAM_Ray_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sSavePlatformPartOAM_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = FRAME_DATA_TERMINATOR
};
