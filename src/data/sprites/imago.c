#include "data/sprites/imago.h"
#include "macros.h"

const i16 sImagoMultiSpriteData_Idle_Frame0[21] = {
    3, 0, 0,
    3, -16, 36,
    0, 8, 0,
    6, 0, 0,
    6, -28, 28,
    9, 0, 0,
    10, 0, 0
};

const i16 sImagoMultiSpriteData_Growling_Unused_Frame0[21] = {
    3, 0, 0,
    3, -16, 36,
    1, 0, 0,
    6, 0, 0,
    6, -28, 28,
    9, 0, 0,
    10, 0, 0
};

const i16 sImagoMultiSpriteData_ShootingNeedles_Frame0[21] = {
    3, 0, 0,
    3, -16, 36,
    0, 8, 0,
    6, 0, 0,
    6, -28, 28,
    9, 0, 0,
    11, 0, 0
};

const i16 sImagoMultiSpriteData_ShootingNeedles_Frame1[21] = {
    4, 0, 0,
    4, -16, 36,
    0, 8, 0,
    7, 0, 0,
    7, -28, 28,
    9, 0, 0,
    11, 0, 0
};

const i16 sImagoMultiSpriteData_RechargingNeedles_Frame0[21] = {
    3, 0, 0,
    3, -16, 36,
    0, 8, 0,
    6, 0, 0,
    6, -28, 28,
    9, 0, 0,
    12, 0, 0
};

const i16 sImagoMultiSpriteData_Dying_Frame0[21] = {
    5, 0, 0,
    4, -24, 36,
    0, 0, 0,
    8, -16, 12,
    8, -36, 48,
    9, 0, 0,
    2, 0, 0
};

const struct FrameData sImagoMultiSpriteData_Idle[2] = {
    sImagoMultiSpriteData_Idle_Frame0,
    0x4,
    NULL,
    0x0
};

const struct FrameData sImagoMultiSpriteData_Growling_Unused[2] = {
    sImagoMultiSpriteData_Growling_Unused_Frame0,
    0x4,
    NULL,
    0x0
};

const struct FrameData sImagoMultiSpriteData_ShootingNeedles[3] = {
    sImagoMultiSpriteData_ShootingNeedles_Frame0,
    0x14,
    sImagoMultiSpriteData_ShootingNeedles_Frame1,
    0x11,
    NULL,
    0x0
};

const struct FrameData sImagoMultiSpriteData_RechargingNeedles[2] = {
    sImagoMultiSpriteData_RechargingNeedles_Frame0,
    0x4,
    NULL,
    0x0
};

const struct FrameData sImagoMultiSpriteData_Dying[2] = {
    sImagoMultiSpriteData_Dying_Frame0,
    0x4,
    NULL,
    0x0
};

const i16 sImagoDamagedStingerFallingYVelocity[10] = {
    0, 1, 2, 4, 8, 12, 16, 20, 24, SHORT_MAX
};

const i16 sImagoAttackingXVelocity[49] = {
    -1, -1, -1, -1, -2, -2, -2, -2, -3, -3, -4, -5,
    -6, -5, -4, -3, -2, -2, -2, -2, -1, -1, -1, -1,
    1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 5, 6, 5, 4, 3,
    2, 2, 2, 2, 1, 1, 1, 1, SHORT_MAX
};

const u8 sImagoDynamicPaletteData[9][2] = {
    { 2, 12 },
    { 1, 6 },
    { 0, 8 },
    { 1, 4 },
    { 2, 22 },
    { 1, 6 },
    { 0, 8 },
    { 1, 4 },
    { 128, 128 }
};

const u32 sImagoGfx[1503] = INCBIN_U32("data/sprites/Imago.gfx.lz");
const u16 sImagoPAL[96] = INCBIN_U16("data/sprites/Imago.pal");

const u16 sImagoPartOAM_BodyIdle_Frame0[55] = {
    0x12,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x20c,
    0xdd, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x210,
    0xed, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x24f,
    OBJ_SHAPE_VERTICAL | 0xed, 0x1, OBJ_SPRITE_OAM | 0x251,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x1f1, OBJ_SPRITE_OAM | 0x28f,
    0xfd, 0x1, OBJ_SPRITE_OAM | 0x291,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x16 | 0x1ce, OBJ_SPRITE_OAM | 0x206,
    0xe3, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x8 | 0x1ce, OBJ_SPRITE_OAM | 0x246,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1ee, OBJ_SPRITE_OAM | 0x24a,
    0xfb, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x26a,
    0xf2, OBJ_SIZE_32x32 | 0x1c8, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf2, OBJ_SIZE_16x32 | 0x1e8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x1c8, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x12, 0x1e8, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1d1, OBJ_SPRITE_OAM | 0x2a0,
    0xd9, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f2, OBJ_SPRITE_OAM | 0x292
};

const u16 sImagoPartOAM_BodyIdle_Frame1[55] = {
    0x12,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x20c,
    0xdc, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x210,
    0xec, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x24f,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1, OBJ_SPRITE_OAM | 0x251,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f1, OBJ_SPRITE_OAM | 0x28f,
    0xfc, 0x1, OBJ_SPRITE_OAM | 0x291,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x16 | 0x1cd, OBJ_SPRITE_OAM | 0x206,
    0xe2, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x8 | 0x1cd, OBJ_SPRITE_OAM | 0x246,
    OBJ_SHAPE_HORIZONTAL | 0xf2, 0x1ed, OBJ_SPRITE_OAM | 0x24a,
    0xfa, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x26a,
    0xf0, OBJ_SIZE_32x32 | 0x1c7, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1e7, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x8 | 0x1c7, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1e7, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x2a0,
    0xda, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x292
};

const u16 sImagoPartOAM_BodyIdle_Frame2[55] = {
    0x12,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x20c,
    0xdd, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210,
    0xed, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24f,
    OBJ_SHAPE_VERTICAL | 0xed, 0x0, OBJ_SPRITE_OAM | 0x251,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x1f0, OBJ_SPRITE_OAM | 0x28f,
    0xfd, 0x0, OBJ_SPRITE_OAM | 0x291,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x16 | 0x1cd, OBJ_SPRITE_OAM | 0x206,
    0xe3, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x8 | 0x1cd, OBJ_SPRITE_OAM | 0x246,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1ed, OBJ_SPRITE_OAM | 0x24a,
    0xfb, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x26a,
    0xf2, OBJ_SIZE_32x32 | 0x1c7, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf2, OBJ_SIZE_16x32 | 0x1e7, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x1c7, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x12, 0x1e7, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x2a0,
    0xda, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x292
};

const u16 sImagoPartOAM_BodyIdle_Frame4[55] = {
    0x12,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x20c,
    0xdd, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210,
    0xed, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24f,
    OBJ_SHAPE_VERTICAL | 0xed, 0x0, OBJ_SPRITE_OAM | 0x251,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x1f0, OBJ_SPRITE_OAM | 0x28f,
    0xfd, 0x0, OBJ_SPRITE_OAM | 0x291,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x16 | 0x1cd, OBJ_SPRITE_OAM | 0x206,
    0xe3, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x8 | 0x1cd, OBJ_SPRITE_OAM | 0x246,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1ed, OBJ_SPRITE_OAM | 0x24a,
    0xfb, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x26a,
    0xf2, OBJ_SIZE_32x32 | 0x1c7, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf2, OBJ_SIZE_16x32 | 0x1e7, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x1c7, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x12, 0x1e7, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1cf, OBJ_SPRITE_OAM | 0x2a0,
    0xdb, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x292
};

const u16 sImagoOAM_BrokenStinger_Frame0[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1f9, OBJ_SPRITE_OAM | 0x2330,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x8 | 0x1f9, OBJ_SPRITE_OAM | 0x2370,
    0x0, 0x10, OBJ_SPRITE_OAM | 0x2288,
    0x8, 0x8, OBJ_SPRITE_OAM | 0x2268
};

const u16 sImagoOAM_BrokenStinger_Frame1[16] = {
    0x5,
    0xfa, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x2354,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x10, OBJ_SPRITE_OAM | 0x2356,
    0x8, 0x10, OBJ_SPRITE_OAM | 0x2268,
    0x8, 0x10, OBJ_SPRITE_OAM | 0x2288,
    0xb, 0xb, OBJ_SPRITE_OAM | 0x2268
};

const u16 sImagoPartOAM_BodyIdle_Frame3[55] = {
    0x12,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x20c,
    0xdd, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210,
    0xed, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24f,
    OBJ_SHAPE_VERTICAL | 0xed, 0x0, OBJ_SPRITE_OAM | 0x251,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x1f0, OBJ_SPRITE_OAM | 0x28f,
    0xfd, 0x0, OBJ_SPRITE_OAM | 0x291,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x16 | 0x1cd, OBJ_SPRITE_OAM | 0x206,
    0xe3, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x8 | 0x1cd, OBJ_SPRITE_OAM | 0x246,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1ed, OBJ_SPRITE_OAM | 0x24a,
    0xfb, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x26a,
    0xf2, OBJ_SIZE_32x32 | 0x1c7, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf2, OBJ_SIZE_16x32 | 0x1e7, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x1c7, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x12, 0x1e7, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x2a0,
    0xda, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x292
};

const u16 sImagoPartOAM_BodyGrowling_Frame2[55] = {
    0x12,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x20c,
    0xdc, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x210,
    0xec, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x24f,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1, OBJ_SPRITE_OAM | 0x251,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f1, OBJ_SPRITE_OAM | 0x28f,
    0xfc, 0x1, OBJ_SPRITE_OAM | 0x291,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x16 | 0x1cd, OBJ_SPRITE_OAM | 0x206,
    0xe2, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x8 | 0x1cd, OBJ_SPRITE_OAM | 0x246,
    OBJ_SHAPE_HORIZONTAL | 0xf2, 0x1ed, OBJ_SPRITE_OAM | 0x24a,
    0xfa, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x26a,
    0xf0, OBJ_SIZE_32x32 | 0x1c7, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1e7, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x8 | 0x1c7, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1e7, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x2a0,
    0xda, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x292
};

const u16 sImagoPartOAM_BodyGrowling_Frame3[55] = {
    0x12,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x20c,
    0xdd, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210,
    0xed, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24f,
    OBJ_SHAPE_VERTICAL | 0xed, 0x0, OBJ_SPRITE_OAM | 0x251,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x1f0, OBJ_SPRITE_OAM | 0x28f,
    0xfd, 0x0, OBJ_SPRITE_OAM | 0x291,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x16 | 0x1cd, OBJ_SPRITE_OAM | 0x206,
    0xe3, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x8 | 0x1cd, OBJ_SPRITE_OAM | 0x246,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1ed, OBJ_SPRITE_OAM | 0x24a,
    0xfb, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x26a,
    0xf2, OBJ_SIZE_32x32 | 0x1c7, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf2, OBJ_SIZE_16x32 | 0x1e7, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x1c7, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x12, 0x1e7, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x2a0,
    0xda, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x292
};

const u16 sImagoPartOAM_BodyGrowling_Frame4[55] = {
    0x12,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x20c,
    0xdd, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210,
    0xed, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24f,
    OBJ_SHAPE_VERTICAL | 0xed, 0x0, OBJ_SPRITE_OAM | 0x251,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x1f0, OBJ_SPRITE_OAM | 0x28f,
    0xfd, 0x0, OBJ_SPRITE_OAM | 0x291,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x16 | 0x1cd, OBJ_SPRITE_OAM | 0x206,
    0xe2, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x8 | 0x1cd, OBJ_SPRITE_OAM | 0x246,
    OBJ_SHAPE_HORIZONTAL | 0xf2, 0x1ed, OBJ_SPRITE_OAM | 0x24a,
    0xfa, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x26a,
    0xf0, OBJ_SIZE_32x32 | 0x1c7, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1e7, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x8 | 0x1c7, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1e7, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x16 | 0x1cf, OBJ_SPRITE_OAM | 0x2a0,
    0xdb, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x292
};

const u16 sImagoPartOAM_LeftWingIdle_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f7, OBJ_SPRITE_OAM | 0x2d7,
    0xf5, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x17, OBJ_SPRITE_OAM | 0x2db
};

const u16 sImagoPartOAM_LeftWingIdle_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x8 | 0x1f6, OBJ_SPRITE_OAM | 0x317,
    OBJ_SHAPE_HORIZONTAL | 0xf2, 0x16, OBJ_SPRITE_OAM | 0x31b
};

const u16 sImagoPartOAM_LeftWingIdle_Frame2[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xe9, OBJ_SIZE_32x16 | 0x1f5, OBJ_SPRITE_OAM | 0x2d7,
    0xe9, OBJ_SIZE_16x16 | 0x15, OBJ_SPRITE_OAM | 0x2db
};

const u16 sImagoPartOAM_LeftWingIdle_Frame4[10] = {
    0x3,
    0xd9, OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x24d,
    0xe1, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x26c,
    0xe9, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x266
};

const u16 sImagoPartOAM_LeftWingIdle_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xc9, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x2dd,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x35d
};

const u16 sImagoPartOAM_RightWingIdle_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1cc, OBJ_SPRITE_OAM | 0x2d7,
    0xf1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1bc, OBJ_SPRITE_OAM | 0x2db
};

const u16 sImagoPartOAM_RightWingIdle_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x1ce, OBJ_SPRITE_OAM | 0x317,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_X_FLIP | 0x1be, OBJ_SPRITE_OAM | 0x31b
};

const u16 sImagoPartOAM_RightWingIdle_Frame2[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xe6, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1ce, OBJ_SPRITE_OAM | 0x2d7,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1be, OBJ_SPRITE_OAM | 0x2db
};

const u16 sImagoPartOAM_RightWingIdle_Frame4[10] = {
    0x3,
    0xd7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1c9, OBJ_SPRITE_OAM | 0x24d,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d1, OBJ_SPRITE_OAM | 0x26c,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x266
};

const u16 sImagoPartOAM_RightWingIdle_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xc9, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1d9, OBJ_SPRITE_OAM | 0x2dd,
    0xe9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x35d
};

const u16 sImagoPartOAM_Core_Frame0[4] = {
    0x1,
    0xeb, OBJ_SIZE_32x32 | 0x1e6, OBJ_SPRITE_OAM | 0x12e0
};

const u16 sImagoPartOAM_Core_Frame1[25] = {
    0x8,
    0xfb, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x1320,
    0xea, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x12e0,
    0xfb, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x1322,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12e2,
    0xfb, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x1321,
    0xf2, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x1300,
    0xf0, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x1302,
    0xf0, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x1301
};

const u16 sImagoPartOAM_Core_Frame2[25] = {
    0x8,
    0xf9, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x1320,
    0xe8, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x12e0,
    0xf9, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x1322,
    0xe6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12e2,
    0xf9, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x1321,
    0xef, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x1300,
    0xee, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x1302,
    0xee, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1301
};

const u16 sImagoOAM_Flying_Frame0[22] = {
    0x7,
    0x12, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x1337,
    0xe4, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x12a8,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x1328,
    0xec, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x12ac,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x132c,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x136c,
    0x1, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x1304
};

const u16 sImagoOAM_Flying_Frame1[22] = {
    0x7,
    0x13, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x1337,
    0xe3, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x12a8,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x1328,
    0xec, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x12ac,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f2, OBJ_SPRITE_OAM | 0x132c,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f2, OBJ_SPRITE_OAM | 0x136c,
    0x1, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x1304
};

const u16 sImagoOAM_Flying_Frame2[22] = {
    0x7,
    0x14, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x1337,
    0xe2, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x12a8,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x8 | 0x1f2, OBJ_SPRITE_OAM | 0x1328,
    0xeb, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x12ac,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x132c,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f4, OBJ_SPRITE_OAM | 0x136c,
    0x2, OBJ_SIZE_32x32 | 0x1f4, OBJ_SPRITE_OAM | 0x1304
};

const u16 sImagoOAM_Flying_Frame4[22] = {
    0x7,
    0x12, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x1337,
    0xe2, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x12a8,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x1328,
    0xea, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x12ac,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f3, OBJ_SPRITE_OAM | 0x132c,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1f3, OBJ_SPRITE_OAM | 0x136c,
    0x0, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x1304
};

const u16 sImagoOAM_Flying_Frame3[22] = {
    0x7,
    0x13, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x1337,
    0xe5, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x12a8,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x1328,
    0xec, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x12ac,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x132c,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x136c,
    0x2, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x1304
};

const u16 sImagoOAM_ShootingNeedles_Frame2[22] = {
    0x7,
    0x15, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x1337,
    0xe5, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x12a8,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x1328,
    0xec, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x12ac,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f3, OBJ_SPRITE_OAM | 0x132c,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f3, OBJ_SPRITE_OAM | 0x136c,
    0x3, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x1304
};

const u16 sImagoOAM_ShootingNeedles_Frame3[22] = {
    0x7,
    0x13, OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x1339,
    0xe4, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x12a8,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x8 | 0x1f2, OBJ_SPRITE_OAM | 0x1328,
    0xeb, OBJ_SIZE_32x32 | 0x1f5, OBJ_SPRITE_OAM | 0x12ac,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f7, OBJ_SPRITE_OAM | 0x132c,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f7, OBJ_SPRITE_OAM | 0x136c,
    0x2, OBJ_SIZE_32x32 | 0x1f7, OBJ_SPRITE_OAM | 0x1304
};

const u16 sImagoOAM_ShootingNeedles_Frame4[22] = {
    0x7,
    0x11, OBJ_SIZE_16x16 | 0x1fc, OBJ_SPRITE_OAM | 0x133b,
    0xe3, OBJ_SIZE_32x32 | 0x1f4, OBJ_SPRITE_OAM | 0x12a8,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x8 | 0x1f4, OBJ_SPRITE_OAM | 0x1328,
    0xe8, OBJ_SIZE_32x32 | 0x1f6, OBJ_SPRITE_OAM | 0x12ac,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x16 | 0x1f8, OBJ_SPRITE_OAM | 0x132c,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x136c,
    0xfe, OBJ_SIZE_32x32 | 0x1f9, OBJ_SPRITE_OAM | 0x1304
};

const u16 sImagoOAM_ShootingNeedles_Frame9[19] = {
    0x6,
    0xe4, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x12a8,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x1328,
    0xec, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x12ac,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x132c,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x136c,
    0x1, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x1304
};

const u16 sImagoNeedleOAM_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12d5
};

const u16 sImagoOAM_RechargingNeedles_Frame0[25] = {
    0x8,
    0xe4, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x12a8,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x1328,
    0xec, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x12ac,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x132c,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x136c,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x12c4,
    0xe, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x1337,
    OBJ_SHAPE_HORIZONTAL | 0x11, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x1344
};

const u16 sImagoOAM_RechargingNeedles_Frame1[25] = {
    0x8,
    0xe4, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x12a8,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x1328,
    0xec, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x12ac,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x132c,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x136c,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x12c4,
    0x10, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x1337,
    OBJ_SHAPE_HORIZONTAL | 0x11, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x1344
};

const u16 sImagoOAM_RechargingNeedles_Frame2[25] = {
    0x8,
    0xe4, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x12a8,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x1328,
    0xec, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x12ac,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x132c,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x136c,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x12c4,
    0x13, OBJ_SIZE_16x16 | 0x1f3, OBJ_SPRITE_OAM | 0x1337,
    OBJ_SHAPE_HORIZONTAL | 0x11, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x1344
};

const u16 sImagoDamagedStingerOAM_Frame0[28] = {
    0x9,
    0xe2, OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x12b0,
    0xe4, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x12a8,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x1328,
    0xec, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x12ac,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x132c,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f1, OBJ_SPRITE_OAM | 0x136c,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x12c4,
    0x13, OBJ_SIZE_16x16 | 0x1f3, OBJ_SPRITE_OAM | 0x1337,
    OBJ_SHAPE_HORIZONTAL | 0x11, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x1344
};

const u16 sImagoEggOAM_Standing_Frame0[7] = {
    0x2,
    0xe8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x1277,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x12b7
};

const u16 sImagoEggOAM_Breaking_Frame1[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x12b7,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1f8, OBJ_SPRITE_OAM | 0x1217,
    0xe8, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sImagoEggOAM_Breaking_Frame2[10] = {
    0x3,
    0xec, OBJ_SIZE_16x16 | 0x1f3, OBJ_SPRITE_OAM | 0x123e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x12b7,
    0xea, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x1218
};

const u16 sImagoEggOAM_Breaking_Frame3[10] = {
    0x3,
    0xef, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x127e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x12b7,
    0xeb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x123e
};

const u16 sImagoEggOAM_Breaking_Frame4[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x123a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x121b,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1ea, OBJ_SPRITE_OAM | 0x121e
};

const u16 sImagoEggOAM_Breaking_Frame5[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x125a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x121b,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e9, OBJ_SPRITE_OAM | 0x121e
};

const u16 sImagoEggOAM_Breaking_Frame6[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x121b,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x127a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e9, OBJ_SPRITE_OAM | 0x121e
};

const u16 sImagoEggOAM_Breaking_Frame7[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x121b,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x129a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e9, OBJ_SPRITE_OAM | 0x121e
};

const u16 sImagoEggOAM_Breaking_Frame8[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x121b,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x12ba,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e9, OBJ_SPRITE_OAM | 0x121e
};

const struct FrameData sImagoPartOAM_BodyIdle[8] = {
    sImagoPartOAM_BodyIdle_Frame0,
    0x1,
    sImagoPartOAM_BodyIdle_Frame1,
    0x2,
    sImagoPartOAM_BodyIdle_Frame2,
    0x2,
    sImagoPartOAM_BodyIdle_Frame3,
    0x1,
    sImagoPartOAM_BodyIdle_Frame4,
    0x1,
    sImagoPartOAM_BodyIdle_Frame2,
    0x2,
    sImagoPartOAM_BodyIdle_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sImagoPartOAM_BodyGrowling[16] = {
    sImagoPartOAM_BodyIdle_Frame0,
    0xC,
    sImagoPartOAM_BodyIdle_Frame3,
    0x8,
    sImagoPartOAM_BodyGrowling_Frame2,
    0x4,
    sImagoPartOAM_BodyGrowling_Frame3,
    0x4,
    sImagoPartOAM_BodyGrowling_Frame4,
    0x4,
    sImagoPartOAM_BodyGrowling_Frame3,
    0x4,
    sImagoPartOAM_BodyGrowling_Frame4,
    0x4,
    sImagoPartOAM_BodyGrowling_Frame3,
    0x4,
    sImagoPartOAM_BodyGrowling_Frame4,
    0x3,
    sImagoPartOAM_BodyGrowling_Frame3,
    0x3,
    sImagoPartOAM_BodyGrowling_Frame4,
    0x3,
    sImagoPartOAM_BodyGrowling_Frame3,
    0x3,
    sImagoPartOAM_BodyGrowling_Frame2,
    0x4,
    sImagoPartOAM_BodyIdle_Frame3,
    0x8,
    sImagoPartOAM_BodyIdle_Frame0,
    0xC,
    NULL,
    0x0
};

const struct FrameData sImagoOAM_BrokenStinger[3] = {
    sImagoOAM_BrokenStinger_Frame0,
    0xC,
    sImagoOAM_BrokenStinger_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sImagoPartOAM_LeftWingIdle[8] = {
    sImagoPartOAM_LeftWingIdle_Frame0,
    0x2,
    sImagoPartOAM_LeftWingIdle_Frame1,
    0x3,
    sImagoPartOAM_LeftWingIdle_Frame2,
    0x3,
    sImagoPartOAM_LeftWingIdle_Frame3,
    0x2,
    sImagoPartOAM_LeftWingIdle_Frame4,
    0x2,
    sImagoPartOAM_LeftWingIdle_Frame2,
    0x3,
    sImagoPartOAM_LeftWingIdle_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sImagoPartOAM_LeftWingShootingNeedles[6] = {
    sImagoPartOAM_LeftWingIdle_Frame0,
    0x1,
    sImagoPartOAM_LeftWingIdle_Frame2,
    0x1,
    sImagoPartOAM_LeftWingIdle_Frame3,
    0x1,
    sImagoPartOAM_LeftWingIdle_Frame4,
    0x1,
    sImagoPartOAM_LeftWingIdle_Frame1,
    0x1,
    NULL,
    0x0
};

const struct FrameData sImagoPartOAM_LeftWingDying[7] = {
    sImagoPartOAM_LeftWingIdle_Frame0,
    0x8,
    sImagoPartOAM_LeftWingIdle_Frame1,
    0xC,
    sImagoPartOAM_LeftWingIdle_Frame2,
    0x10,
    sImagoPartOAM_LeftWingIdle_Frame0,
    0x8,
    sImagoPartOAM_LeftWingIdle_Frame1,
    0x4,
    sImagoPartOAM_LeftWingIdle_Frame1,
    0x6,
    NULL,
    0x0
};

const struct FrameData sImagoPartOAM_RightWingIdle[8] = {
    sImagoPartOAM_RightWingIdle_Frame0,
    0x2,
    sImagoPartOAM_RightWingIdle_Frame1,
    0x2,
    sImagoPartOAM_RightWingIdle_Frame2,
    0x3,
    sImagoPartOAM_RightWingIdle_Frame3,
    0x3,
    sImagoPartOAM_RightWingIdle_Frame4,
    0x2,
    sImagoPartOAM_RightWingIdle_Frame2,
    0x3,
    sImagoPartOAM_RightWingIdle_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sImagoPartOAM_RightWingShootingNeedles[6] = {
    sImagoPartOAM_RightWingIdle_Frame0,
    0x1,
    sImagoPartOAM_RightWingIdle_Frame2,
    0x1,
    sImagoPartOAM_RightWingIdle_Frame3,
    0x1,
    sImagoPartOAM_RightWingIdle_Frame4,
    0x1,
    sImagoPartOAM_RightWingIdle_Frame1,
    0x1,
    NULL,
    0x0
};

const struct FrameData sImagoPartOAM_RIghtWingDying[5] = {
    sImagoPartOAM_RightWingIdle_Frame0,
    0x8,
    sImagoPartOAM_RightWingIdle_Frame1,
    0x10,
    sImagoPartOAM_RightWingIdle_Frame2,
    0xA,
    sImagoPartOAM_RightWingIdle_Frame1,
    0x6,
    NULL,
    0x0
};

const struct FrameData sImagoPartOAM_Core[9] = {
    sImagoPartOAM_Core_Frame0,
    0xC,
    sImagoPartOAM_Core_Frame1,
    0x6,
    sImagoPartOAM_Core_Frame2,
    0x8,
    sImagoPartOAM_Core_Frame1,
    0x4,
    sImagoPartOAM_Core_Frame0,
    0x16,
    sImagoPartOAM_Core_Frame1,
    0x6,
    sImagoPartOAM_Core_Frame2,
    0x8,
    sImagoPartOAM_Core_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData simagoOAM_Flying[9] = {
    sImagoOAM_Flying_Frame0,
    0x1,
    sImagoOAM_Flying_Frame1,
    0x1,
    sImagoOAM_Flying_Frame2,
    0x2,
    sImagoOAM_Flying_Frame3,
    0x2,
    sImagoOAM_Flying_Frame4,
    0x1,
    sImagoOAM_Flying_Frame0,
    0x1,
    sImagoOAM_Flying_Frame1,
    0x2,
    sImagoOAM_Flying_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sImagoOAM_ShootingNeedles[11] = {
    sImagoOAM_Flying_Frame0,
    0x2,
    sImagoOAM_Flying_Frame3,
    0x4,
    sImagoOAM_ShootingNeedles_Frame2,
    0x6,
    sImagoOAM_ShootingNeedles_Frame3,
    0x8,
    sImagoOAM_ShootingNeedles_Frame4,
    0xA,
    sImagoOAM_ShootingNeedles_Frame3,
    0x2,
    sImagoOAM_ShootingNeedles_Frame2,
    0x1,
    sImagoOAM_Flying_Frame3,
    0x1,
    sImagoOAM_Flying_Frame0,
    0x1,
    sImagoOAM_ShootingNeedles_Frame9,
    0x2,
    NULL,
    0x0
};

const struct FrameData sImagoOAM_RechargingNeedles[4] = {
    sImagoOAM_RechargingNeedles_Frame0,
    0xA,
    sImagoOAM_RechargingNeedles_Frame1,
    0x8,
    sImagoOAM_RechargingNeedles_Frame2,
    0x6,
    NULL,
    0x0
};

const struct FrameData sImagoDamagedStingerOAM[2] = {
    sImagoDamagedStingerOAM_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sImagoNeedleOAM[2] = {
    sImagoNeedleOAM_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sImagoDamagedStingerOAM_Unused[9] = {
    sImagoOAM_Flying_Frame0,
    0xC,
    sImagoOAM_Flying_Frame1,
    0x6,
    sImagoOAM_Flying_Frame2,
    0x8,
    sImagoOAM_Flying_Frame1,
    0x4,
    sImagoOAM_Flying_Frame0,
    0x16,
    sImagoOAM_Flying_Frame1,
    0x6,
    sImagoOAM_Flying_Frame2,
    0x8,
    sImagoOAM_Flying_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sImagoEggOAM_Breaking[10] = {
    sImagoEggOAM_Standing_Frame0,
    0x2,
    sImagoEggOAM_Breaking_Frame1,
    0x2,
    sImagoEggOAM_Breaking_Frame2,
    0x2,
    sImagoEggOAM_Breaking_Frame3,
    0x4,
    sImagoEggOAM_Breaking_Frame4,
    0x6,
    sImagoEggOAM_Breaking_Frame5,
    0x8,
    sImagoEggOAM_Breaking_Frame6,
    0xA,
    sImagoEggOAM_Breaking_Frame7,
    0xE,
    sImagoEggOAM_Breaking_Frame8,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sImagoEggOAM_Standing[2] = {
    sImagoEggOAM_Standing_Frame0,
    0xFF,
    NULL,
    0x0
};
