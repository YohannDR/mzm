#include "data/sprites/mother_brain.h"
#include "macros.h"

const u16 sMotherBrainMultiSpriteData_Part0[12] = {
    0x8, 0x18, 0x9C, 0x0, 0x0, 0x0, 0x2, 0x18, 0x9C, 0x7, 0x60, 0x18
};

const u16 sMotherBrainMultiSpriteData_Part1[12] = {
    0x8, 0x1C, 0x9C, 0x0, 0x4, 0x0, 0x2, 0x1C, 0x9C, 0x7, 0x60, 0x18
};

const u16 sMotherBrainMultiSpriteData_Part2[12] = {
    0x8, 0x20, 0x9C, 0x0, 0x8, 0x0, 0x2, 0x20, 0x9C, 0x7, 0x60, 0x18
};

const u16 sMotherBrainMultiSpriteData_Part3[12] = {
    0x8, 0x24, 0x9C, 0x0, 0xC, 0x0, 0x2, 0x24, 0x9C, 0x7, 0x60, 0x18
};

const struct FrameData sMotherBrainMultiSpriteData[7] = {
    sMotherBrainMultiSpriteData_Part0,
    0xE,
    sMotherBrainMultiSpriteData_Part1,
    0xE,
    sMotherBrainMultiSpriteData_Part2,
    0x8,
    sMotherBrainMultiSpriteData_Part3,
    0x6,
    sMotherBrainMultiSpriteData_Part2,
    0x8,
    sMotherBrainMultiSpriteData_Part1,
    0xE,
    NULL,
    0x0
};

const u8 sMotherBrainDynamicPaletteData[19][2] = {
    { 2, 6 },
    { 3, 6 },
    { 4, 6 },
    { 3, 6 },
    { 2, 6 },
    { 0, 2 },
    { 2, 6 },
    { 3, 6 },
    { 4, 6 },
    { 3, 6 },
    { 2, 6 },
    { 0, 2 },
    { 2, 3 },
    { 3, 3 },
    { 4, 3 },
    { 3, 3 },
    { 2, 3 },
    { 0, 1 },
    { SCHAR_MAX + 1, SCHAR_MAX + 1 }
};

const u32 sMotherBrainGfx[1871] = INCBIN_U32("data/sprites/MotherBrain.gfx.lz");
const u16 sMotherBrainPal[96] = INCBIN_U16("data/sprites/MotherBrain.pal");

const u16 sMotherBrainOAM_Idle_Frame0[58] = {
    0x13,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1d7, OBJ_SPRITE_OAM | 0x65a,
    0xf9, OBJ_SIZE_16x16 | 0x1d8, OBJ_SPRITE_OAM | 0x750,
    0x6, OBJ_SIZE_16x16 | 0x1dc, OBJ_SPRITE_OAM | 0x752,
    OBJ_SHAPE_VERTICAL | 0xdf, 0xf, OBJ_SPRITE_OAM | 0x61b,
    OBJ_SHAPE_VERTICAL | 0xdb, 0x1fb, OBJ_SPRITE_OAM | 0x619,
    0xe4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1dd, OBJ_SPRITE_OAM | 0x74c,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_SIZE_8x32 | 0x1d8, OBJ_SPRITE_OAM | 0x600,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0x601,
    0xa, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x681,
    0xe2, 0x1e8, OBJ_SPRITE_OAM | 0x6a7,
    0xe2, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x603,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x683,
    OBJ_SHAPE_VERTICAL | 0xe2, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0x607,
    0x2, 0x10, OBJ_SPRITE_OAM | 0x687,
    OBJ_SHAPE_VERTICAL | 0xef, 0x20, OBJ_SPRITE_OAM | 0x688,
    0xe0, OBJ_SIZE_16x16 | 0x16, OBJ_SPRITE_OAM | 0x74e,
    OBJ_SHAPE_VERTICAL | 0xd8, 0xa, OBJ_SPRITE_OAM | 0x61b,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_X_FLIP | 0x1ed, OBJ_SPRITE_OAM | 0x61b,
    0xe9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d5, OBJ_SPRITE_OAM | 0x74c
};

const u16 sMotherBrainOAM_Idle_Frame1[58] = {
    0x13,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1d6, OBJ_SPRITE_OAM | 0x65a,
    0xfa, OBJ_SIZE_16x16 | 0x1d8, OBJ_SPRITE_OAM | 0x750,
    0x7, OBJ_SIZE_16x16 | 0x1dc, OBJ_SPRITE_OAM | 0x752,
    0xdf, OBJ_SIZE_16x16 | 0xd, OBJ_SPRITE_OAM | 0x74e,
    OBJ_SHAPE_VERTICAL | 0xdb, 0x1fb, OBJ_SPRITE_OAM | 0x61a,
    0xe3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x74e,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_SIZE_8x32 | 0x1d8, OBJ_SPRITE_OAM | 0x680,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0x609,
    0xa, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x689,
    0xe2, 0x1e8, OBJ_SPRITE_OAM | 0x6af,
    0xe2, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x60b,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x68b,
    OBJ_SHAPE_VERTICAL | 0xe2, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0x60f,
    0x2, 0x10, OBJ_SPRITE_OAM | 0x68f,
    OBJ_SHAPE_VERTICAL | 0xef, 0x20, OBJ_SPRITE_OAM | 0x690,
    0xe1, OBJ_SIZE_16x16 | 0x18, OBJ_SPRITE_OAM | 0x74c,
    OBJ_SHAPE_VERTICAL | 0xd9, 0xb, OBJ_SPRITE_OAM | 0x61b,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_X_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x61a,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d6, OBJ_SPRITE_OAM | 0x74c
};

const u16 sMotherBrainOAM_Idle_Frame2[58] = {
    0x13,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1d6, OBJ_SPRITE_OAM | 0x65a,
    0xfa, OBJ_SIZE_16x16 | 0x1d7, OBJ_SPRITE_OAM | 0x750,
    0x8, OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x752,
    0xe0, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x74c,
    OBJ_SHAPE_VERTICAL | 0xdb, 0x1fc, OBJ_SPRITE_OAM | 0x61b,
    0xe2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x74e,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_SIZE_8x32 | 0x1d8, OBJ_SPRITE_OAM | 0x700,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0x611,
    0xa, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x691,
    0xe2, 0x1e8, OBJ_SPRITE_OAM | 0x6b7,
    0xe2, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x613,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x693,
    OBJ_SHAPE_VERTICAL | 0xe2, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0x617,
    0x2, 0x10, OBJ_SPRITE_OAM | 0x697,
    OBJ_SHAPE_VERTICAL | 0xef, 0x20, OBJ_SPRITE_OAM | 0x659,
    0xe2, OBJ_SIZE_16x16 | 0x18, OBJ_SPRITE_OAM | 0x74c,
    0xd9, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x74e,
    OBJ_SHAPE_VERTICAL | 0xda, 0x1ee, OBJ_SPRITE_OAM | 0x619,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d6, OBJ_SPRITE_OAM | 0x74e
};

const u16 sMotherBrainPartOAM_EyeClosed_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_X_FLIP | 0x1f2, OBJ_SPRITE_OAM | 0x6c1,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1e2, OBJ_SPRITE_OAM | 0x6c3
};

const u16 sMotherBrainPartOAM_EyeClosed_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf2, 0x1f2, OBJ_SPRITE_OAM | 0x6e1,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1e2, OBJ_SPRITE_OAM | 0x6c6
};

const u16 sMotherBrainPartOAM_EyeClosed_Frame2[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_X_FLIP | 0x1f2, OBJ_SPRITE_OAM | 0x701,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1e2, OBJ_SPRITE_OAM | 0x703
};

const u16 sMotherBrainPartOAM_EyeOpening_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf2, 0x1f2, OBJ_SPRITE_OAM | 0x721,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1e2, OBJ_SPRITE_OAM | 0x706
};

const u16 sMotherBrainPartOAM_EyeOpening_Frame2[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_X_FLIP | 0x1f2, OBJ_SPRITE_OAM | 0x741,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1e2, OBJ_SPRITE_OAM | 0x743
};

const u16 sMotherBrainPartOAM_EyeOpening_Frame3[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf2, 0x1f2, OBJ_SPRITE_OAM | 0x761,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1e2, OBJ_SPRITE_OAM | 0x746
};

const u16 sMotherBrainPartOAM_Bottom_Frame0[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_SIZE_16x32 | 0x1f5, OBJ_SPRITE_OAM | 0x61c,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1fe, OBJ_SPRITE_OAM | 0x61e,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_SIZE_16x32 | 0x4, OBJ_SPRITE_OAM | 0x61c,
    0xf4, OBJ_SIZE_16x16 | 0xe, OBJ_SPRITE_OAM | 0x74a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x6ca
};

const u16 sMotherBrainPartOAM_Bottom_Frame1[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_SIZE_16x32 | 0x1f5, OBJ_SPRITE_OAM | 0x61c,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1fe, OBJ_SPRITE_OAM | 0x61e,
    OBJ_SHAPE_VERTICAL | 0xf2, OBJ_SIZE_16x32 | 0x4, OBJ_SPRITE_OAM | 0x61c,
    0xf5, OBJ_SIZE_16x16 | 0xe, OBJ_SPRITE_OAM | 0x74a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x6ca
};

const u16 sMotherBrainPartOAM_Bottom_Frame2[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf2, OBJ_SIZE_16x32 | 0x1f5, OBJ_SPRITE_OAM | 0x61c,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_SIZE_16x32 | 0x1fe, OBJ_SPRITE_OAM | 0x61e,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_SIZE_16x32 | 0x4, OBJ_SPRITE_OAM | 0x61c,
    0xf6, OBJ_SIZE_16x16 | 0xe, OBJ_SPRITE_OAM | 0x74a,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x6ca
};

const u16 sMotherBrainPartOAM_Bottom_Frame3[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf2, OBJ_SIZE_16x32 | 0x1f5, OBJ_SPRITE_OAM | 0x61c,
    OBJ_SHAPE_VERTICAL | 0xf2, OBJ_SIZE_16x32 | 0x1fe, OBJ_SPRITE_OAM | 0x61e,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_SIZE_16x32 | 0x4, OBJ_SPRITE_OAM | 0x61c,
    0xf7, OBJ_SIZE_16x16 | 0xe, OBJ_SPRITE_OAM | 0x74a,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x6ca
};

const u16 sMotherBrainPartOAM_BeamSpawning_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x129e,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1fc, OBJ_SPRITE_OAM | 0x12fe
};

const u16 sMotherBrainPartOAM_BeamSpawning_Frame1[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x14, OBJ_SPRITE_OAM | 0x129e,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x14, OBJ_SPRITE_OAM | 0x12fe,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x4, OBJ_SPRITE_OAM | 0x12ba,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x4, OBJ_SPRITE_OAM | 0x12da,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x12b8
};

const u16 sMotherBrainPartOAM_BeamSpawning_Frame2[10] = {
    0x3,
    0xf0, OBJ_SIZE_32x32 | 0x10, OBJ_SPRITE_OAM | 0x131c,
    0xf5, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x1338,
    0xfb, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x1338
};

const u16 sMotherBrainPartOAM_BeamSpawning_Frame3[10] = {
    0x3,
    0xf0, OBJ_SIZE_32x32 | 0x20, OBJ_SPRITE_OAM | 0x129c,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x14, OBJ_SPRITE_OAM | 0x129a,
    0xf8, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x12b8
};

const u16 sMotherBrainBeamOAM_Moving_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x1d0, OBJ_SPRITE_OAM | 0x1298
};

const u16 sMotherBrainBeamOAM_Moving_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x1cc, OBJ_SPRITE_OAM | 0x1318
};

const u16 sMotherBrainGlassBreakingOAM_Breaking_Frame0[70] = {
    0x17,
    OBJ_SHAPE_VERTICAL | 0xcb, OBJ_SIZE_16x32 | 0x1d7, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1ec, OBJ_SPRITE_OAM | 0x12d4,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0xfe, OBJ_Y_FLIP | 0x1e4, OBJ_SPRITE_OAM | 0x12d4,
    0xf2, OBJ_SIZE_16x16 | 0x1d3, OBJ_SPRITE_OAM | 0x1312,
    0xe2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0x1312,
    OBJ_SHAPE_VERTICAL | 0x1, OBJ_SIZE_8x32 | 0x1ed, OBJ_SPRITE_OAM | 0x1314,
    0xf0, OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1315,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x15, OBJ_SPRITE_OAM | 0x1314,
    0xd0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x10, OBJ_SPRITE_OAM | 0x1315,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x28, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0xd8, 0x30, OBJ_SPRITE_OAM | 0x12d4,
    0x10, 0x28, OBJ_SPRITE_OAM | 0x127a,
    0xf8, 0x20, OBJ_SPRITE_OAM | 0x127b,
    0xd4, OBJ_SIZE_16x16 | 0x1fd, OBJ_SPRITE_OAM | 0x1312,
    0xc4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x1312,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x10, OBJ_SPRITE_OAM | 0x1315,
    0xf0, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x12d5,
    0xce, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x12d5,
    0xe3, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d5,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x1312,
    0xe0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x13, OBJ_SPRITE_OAM | 0x1312,
    0xc0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1da, OBJ_SPRITE_OAM | 0x1315
};

const u16 sMotherBrainGlassBreakingOAM_Breaking_Frame2[70] = {
    0x17,
    OBJ_SHAPE_VERTICAL | 0xc9, OBJ_SIZE_16x32 | 0x1d4, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0xdf, 0x1eb, OBJ_SPRITE_OAM | 0x12d4,
    OBJ_SHAPE_VERTICAL | 0xfa, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1cd, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_Y_FLIP | 0x1e2, OBJ_SPRITE_OAM | 0x12d4,
    0xf1, OBJ_SIZE_16x16 | 0x1d1, OBJ_SPRITE_OAM | 0x1312,
    0xe1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ce, OBJ_SPRITE_OAM | 0x1312,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_SIZE_8x32 | 0x1eb, OBJ_SPRITE_OAM | 0x1314,
    0xf2, OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1315,
    OBJ_SHAPE_VERTICAL | 0xeb, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x16, OBJ_SPRITE_OAM | 0x1314,
    0xce, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x12, OBJ_SPRITE_OAM | 0x1315,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x2c, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0xd7, 0x33, OBJ_SPRITE_OAM | 0x12d4,
    0x12, 0x2c, OBJ_SPRITE_OAM | 0x127a,
    0xf7, 0x22, OBJ_SPRITE_OAM | 0x127b,
    0xd1, OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x1312,
    0xc1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x1312,
    0x1, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x12, OBJ_SPRITE_OAM | 0x1315,
    0xf1, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x12d5,
    0xcc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xd, OBJ_SPRITE_OAM | 0x12d5,
    0xe2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d5,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x1312,
    0xde, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x15, OBJ_SPRITE_OAM | 0x1312,
    0xbe, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x1315
};

const u16 sMotherBrainGlassBreakingOAM_Breaking_Frame4[70] = {
    0x17,
    OBJ_SHAPE_VERTICAL | 0xcd, OBJ_SIZE_16x32 | 0x1cc, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1e5, OBJ_SPRITE_OAM | 0x12d4,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1c7, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_Y_FLIP | 0x1de, OBJ_SPRITE_OAM | 0x12d4,
    0xf2, OBJ_SIZE_16x16 | 0x1cd, OBJ_SPRITE_OAM | 0x1312,
    0xe2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ca, OBJ_SPRITE_OAM | 0x1312,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_SIZE_8x32 | 0x1e8, OBJ_SPRITE_OAM | 0x1314,
    0xf8, OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1315,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1b, OBJ_SPRITE_OAM | 0x1314,
    0xcc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x15, OBJ_SPRITE_OAM | 0x1315,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x30, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0xdb, 0x36, OBJ_SPRITE_OAM | 0x12d4,
    0x1a, 0x2d, OBJ_SPRITE_OAM | 0x127a,
    0xfb, 0x24, OBJ_SPRITE_OAM | 0x127b,
    0xd1, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x1312,
    0xc1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x1312,
    0x5, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x13, OBJ_SPRITE_OAM | 0x1315,
    0xf3, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x12d5,
    0xca, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x12d5,
    0xe5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d5,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x13, OBJ_SPRITE_OAM | 0x1312,
    0xe0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x16, OBJ_SPRITE_OAM | 0x1312,
    0xc0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1d1, OBJ_SPRITE_OAM | 0x1315
};

const u16 sMotherBrainGlassBreakingOAM_Breaking_Frame6[70] = {
    0x17,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1c8, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e0, OBJ_SPRITE_OAM | 0x12d4,
    OBJ_SHAPE_VERTICAL | 0x14, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1c2, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0x12, OBJ_Y_FLIP | 0x1d9, OBJ_SPRITE_OAM | 0x12d4,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1cb, OBJ_SPRITE_OAM | 0x1312,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1c8, OBJ_SPRITE_OAM | 0x1312,
    OBJ_SHAPE_VERTICAL | 0xf, OBJ_SIZE_8x32 | 0x1e6, OBJ_SPRITE_OAM | 0x1314,
    0x7, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1315,
    OBJ_SHAPE_VERTICAL | 0x3, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x20, OBJ_SPRITE_OAM | 0x1314,
    0xda, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1b, OBJ_SPRITE_OAM | 0x1315,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x38, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x40, OBJ_SPRITE_OAM | 0x12d4,
    0x33, 0x31, OBJ_SPRITE_OAM | 0x127a,
    0x10, 0x28, OBJ_SPRITE_OAM | 0x127b,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x1312,
    0xd0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1312,
    0x1e, OBJ_SIZE_32x32 | 0x17, OBJ_SPRITE_OAM | 0x1315,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x12d5,
    0xd0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1b, OBJ_SPRITE_OAM | 0x12d5,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d5,
    0xfa, OBJ_SIZE_16x16 | 0x15, OBJ_SPRITE_OAM | 0x1312,
    0xea, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x1312,
    0xc8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1cd, OBJ_SPRITE_OAM | 0x1315
};

const u16 sMotherBrainGlassBreakingOAM_Breaking_Frame8[70] = {
    0x17,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_SIZE_16x32 | 0x1c5, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1da, OBJ_SPRITE_OAM | 0x12d4,
    OBJ_SHAPE_VERTICAL | 0x27, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1c0, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0x2a, OBJ_Y_FLIP | 0x1d4, OBJ_SPRITE_OAM | 0x12d4,
    0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1c4, OBJ_SPRITE_OAM | 0x1312,
    0x18, OBJ_SIZE_16x16 | 0x1c7, OBJ_SPRITE_OAM | 0x1312,
    OBJ_SHAPE_VERTICAL | 0x2c, OBJ_SIZE_8x32 | 0x1e3, OBJ_SPRITE_OAM | 0x1314,
    0x20, OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1315,
    OBJ_SHAPE_VERTICAL | 0x20, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x24, OBJ_SPRITE_OAM | 0x1314,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x20, OBJ_SPRITE_OAM | 0x1315,
    OBJ_SHAPE_VERTICAL | 0x1d, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x3b, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0xb, 0x45, OBJ_SPRITE_OAM | 0x12d4,
    0x40, 0x34, OBJ_SPRITE_OAM | 0x127a,
    0x20, 0x2b, OBJ_SPRITE_OAM | 0x127b,
    0xf8, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x1312,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x1312,
    0x31, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x18, OBJ_SPRITE_OAM | 0x1315,
    0x10, OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x12d5,
    0xe1, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x23, OBJ_SPRITE_OAM | 0x12d5,
    0x3, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d5,
    0x10, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x14, OBJ_SPRITE_OAM | 0x1312,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x17, OBJ_SPRITE_OAM | 0x1312,
    0xd8, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1c8, OBJ_SPRITE_OAM | 0x1315
};

const u16 sMotherBrainGlassBreakingOAM_Breaking_Frame10[46] = {
    0xf,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1c2, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0x16, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1d8, OBJ_SPRITE_OAM | 0x12d4,
    0x1b, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1c5, OBJ_SPRITE_OAM | 0x1312,
    0x2b, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1c2, OBJ_SPRITE_OAM | 0x1312,
    0x9, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x24, OBJ_SPRITE_OAM | 0x1315,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_Y_FLIP | 0x48, OBJ_SPRITE_OAM | 0x12d4,
    0x31, 0x2e, OBJ_SPRITE_OAM | 0x127b,
    0x11, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x1312,
    0x1, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x1312,
    0x25, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x12d5,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x27, OBJ_SPRITE_OAM | 0x12d5,
    0x19, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d5,
    0x21, OBJ_SIZE_16x16 | 0x18, OBJ_SPRITE_OAM | 0x1312,
    0x11, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x15, OBJ_SPRITE_OAM | 0x1312,
    0xec, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1c8, OBJ_SPRITE_OAM | 0x1315
};

const u16 sMotherBrainGlassBreakingOAM_Breaking_Frame12[37] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0x1f, OBJ_SIZE_16x32 | 0x1c0, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0x30, 0x1d6, OBJ_SPRITE_OAM | 0x12d4,
    0x28, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x25, OBJ_SPRITE_OAM | 0x1315,
    0x28, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x1312,
    0x18, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x1312,
    0x33, OBJ_SIZE_16x16 | 0x1dd, OBJ_SPRITE_OAM | 0x12d5,
    0x16, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x2c, OBJ_SPRITE_OAM | 0x12d5,
    0x2f, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d5,
    0x38, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x18, OBJ_SPRITE_OAM | 0x1312,
    0x28, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1b, OBJ_SPRITE_OAM | 0x1312,
    0x5, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1c8, OBJ_SPRITE_OAM | 0x1315,
    OBJ_SHAPE_VERTICAL | 0x30, 0x48, OBJ_SPRITE_OAM | 0x12d4
};

const u16 sMotherBrainGlassBreakingOAM_Breaking_Frame14[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0x31, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1c0, OBJ_SPRITE_OAM | 0x12d2,
    0x3a, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x1312,
    0x2a, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x1312,
    0x28, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x2c, OBJ_SPRITE_OAM | 0x12d5,
    0x41, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d5,
    0x20, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1c7, OBJ_SPRITE_OAM | 0x1315
};

const u16 sMotherBrainGlassBreakingOAM_Breaking_Frame16[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0x40, OBJ_SIZE_16x32 | 0x1c0, OBJ_SPRITE_OAM | 0x12d2,
    0x40, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x1312,
    0x50, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x1312,
    0x40, OBJ_SIZE_16x16 | 0x2d, OBJ_SPRITE_OAM | 0x12d5,
    0x50, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d5,
    0x38, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x1315
};

const u16 sMotherBrainGlassBreakingOAM_Breaking_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x1298
};

const struct FrameData sMotherBrainOAM_Idle[12] = {
    sMotherBrainOAM_Idle_Frame0,
    0x32,
    sMotherBrainOAM_Idle_Frame1,
    0x8,
    sMotherBrainOAM_Idle_Frame2,
    0x8,
    sMotherBrainOAM_Idle_Frame1,
    0x3,
    sMotherBrainOAM_Idle_Frame0,
    0x3,
    sMotherBrainOAM_Idle_Frame2,
    0x5,
    sMotherBrainOAM_Idle_Frame1,
    0x3,
    sMotherBrainOAM_Idle_Frame0,
    0x1E,
    sMotherBrainOAM_Idle_Frame1,
    0x2,
    sMotherBrainOAM_Idle_Frame2,
    0x4,
    sMotherBrainOAM_Idle_Frame1,
    0x2
};

const struct FrameData sMotherBrainOAM_ChargingBeam[5] = {
    sMotherBrainOAM_Idle_Frame0,
    0x3,
    sMotherBrainOAM_Idle_Frame1,
    0x3,
    sMotherBrainOAM_Idle_Frame2,
    0x3,
    sMotherBrainOAM_Idle_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sMotherBrainPartOAM_EyeClosed[12] = {
    sMotherBrainPartOAM_EyeClosed_Frame0,
    0x32,
    sMotherBrainPartOAM_EyeClosed_Frame1,
    0x8,
    sMotherBrainPartOAM_EyeClosed_Frame2,
    0x8,
    sMotherBrainPartOAM_EyeClosed_Frame1,
    0x3,
    sMotherBrainPartOAM_EyeClosed_Frame0,
    0x3,
    sMotherBrainPartOAM_EyeClosed_Frame2,
    0x5,
    sMotherBrainPartOAM_EyeClosed_Frame1,
    0x3,
    sMotherBrainPartOAM_EyeClosed_Frame0,
    0x1E,
    sMotherBrainPartOAM_EyeClosed_Frame1,
    0x2,
    sMotherBrainPartOAM_EyeClosed_Frame2,
    0x4,
    sMotherBrainPartOAM_EyeClosed_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sMotherBrainPartOAM_2fa934[5] = {
    sMotherBrainPartOAM_EyeClosed_Frame0,
    0x3,
    sMotherBrainPartOAM_EyeClosed_Frame1,
    0x3,
    sMotherBrainPartOAM_EyeClosed_Frame2,
    0x3,
    sMotherBrainPartOAM_EyeClosed_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sMotherBrainPartOAM_EyeOpening[5] = {
    sMotherBrainPartOAM_EyeClosed_Frame1,
    0x6,
    sMotherBrainPartOAM_EyeOpening_Frame1,
    0x6,
    sMotherBrainPartOAM_EyeOpening_Frame2,
    0x4,
    sMotherBrainPartOAM_EyeOpening_Frame3,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sMotherBrainPartOAM_2fa984[8] = {
    sMotherBrainPartOAM_EyeOpening_Frame2,
    0x2,
    sMotherBrainPartOAM_EyeOpening_Frame1,
    0x1,
    sMotherBrainPartOAM_EyeClosed_Frame1,
    0x1,
    sMotherBrainPartOAM_EyeClosed_Frame0,
    0x1,
    sMotherBrainPartOAM_EyeClosed_Frame1,
    0x1,
    sMotherBrainPartOAM_EyeOpening_Frame1,
    0x1,
    sMotherBrainPartOAM_EyeOpening_Frame2,
    0x1,
    NULL,
    0x0
};

const struct FrameData sMotherBrainPartOAM_EyeDying[5] = {
    sMotherBrainPartOAM_EyeOpening_Frame3,
    0x3,
    sMotherBrainPartOAM_EyeOpening_Frame2,
    0x3,
    sMotherBrainPartOAM_EyeOpening_Frame1,
    0x3,
    sMotherBrainPartOAM_EyeOpening_Frame2,
    0x3,
    NULL,
    0x0
};

const struct FrameData sMotherBrainPartOAM_Bottom[7] = {
    sMotherBrainPartOAM_Bottom_Frame0,
    0xE,
    sMotherBrainPartOAM_Bottom_Frame1,
    0xE,
    sMotherBrainPartOAM_Bottom_Frame2,
    0x8,
    sMotherBrainPartOAM_Bottom_Frame3,
    0x6,
    sMotherBrainPartOAM_Bottom_Frame2,
    0x8,
    sMotherBrainPartOAM_Bottom_Frame1,
    0xE,
    NULL,
    0x0
};

const struct FrameData sMotherBrainPartOAM_BeamSpawning[5] = {
    sMotherBrainPartOAM_BeamSpawning_Frame0,
    0x6,
    sMotherBrainPartOAM_BeamSpawning_Frame1,
    0x6,
    sMotherBrainPartOAM_BeamSpawning_Frame2,
    0x6,
    sMotherBrainPartOAM_BeamSpawning_Frame3,
    0x6,
    NULL,
    0x0
};

const struct FrameData sMotherBrainBeamOAM_Moving[3] = {
    sMotherBrainBeamOAM_Moving_Frame0,
    0x3,
    sMotherBrainBeamOAM_Moving_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sMotherBrainGlassBreakingOAM_Breaking[18] = {
    sMotherBrainGlassBreakingOAM_Breaking_Frame0,
    0x4,
    sMotherBrainGlassBreakingOAM_Breaking_Frame1,
    0x1,
    sMotherBrainGlassBreakingOAM_Breaking_Frame2,
    0x4,
    sMotherBrainGlassBreakingOAM_Breaking_Frame1,
    0x1,
    sMotherBrainGlassBreakingOAM_Breaking_Frame4,
    0x4,
    sMotherBrainGlassBreakingOAM_Breaking_Frame1,
    0x1,
    sMotherBrainGlassBreakingOAM_Breaking_Frame6,
    0x4,
    sMotherBrainGlassBreakingOAM_Breaking_Frame1,
    0x1,
    sMotherBrainGlassBreakingOAM_Breaking_Frame8,
    0x4,
    sMotherBrainGlassBreakingOAM_Breaking_Frame1,
    0x1,
    sMotherBrainGlassBreakingOAM_Breaking_Frame10,
    0x3,
    sMotherBrainGlassBreakingOAM_Breaking_Frame1,
    0x1,
    sMotherBrainGlassBreakingOAM_Breaking_Frame12,
    0x3,
    sMotherBrainGlassBreakingOAM_Breaking_Frame1,
    0x1,
    sMotherBrainGlassBreakingOAM_Breaking_Frame14,
    0x3,
    sMotherBrainGlassBreakingOAM_Breaking_Frame1,
    0x1,
    sMotherBrainGlassBreakingOAM_Breaking_Frame16,
    0x3,
    NULL,
    0x0
};

const struct FrameData sMotherBrainPartOAM_EyeClosing[4] = {
    sMotherBrainPartOAM_EyeOpening_Frame2,
    0x4,
    sMotherBrainPartOAM_EyeOpening_Frame1,
    0x6,
    sMotherBrainPartOAM_EyeClosed_Frame1,
    0x6,
    NULL,
    0x0
};
