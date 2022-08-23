#include "mother_brain.h"
#include "../../data/data.h"
#include "../globals.h"

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
    { 80, 80 }
};

const u32 sMotherBrainGFX[1871];
const u16 sMotherBrainPAL[96];

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

/*asm("
.align 2, 0
.global MotherBrainSyncSubSpritesPosition
.thumb
.type MotherBrainSyncSubSpritesPosition, %function
MotherBrainSyncSubSpritesPosition: @ 0x0803c964
    push {r4, lr}
    ldr r4, lbl_0803c9c0 @ =0x0300070c
    ldrh r0, [r4, #4]
    ldr r1, [r4]
    lsl r0, r0, #3
    add r0, r0, r1
    ldr r3, [r0]
    ldr r2, lbl_0803c9c4 @ =0x03000738
    ldrb r1, [r2, #0x1e]
    lsl r0, r1, #1
    add r0, r0, r1
    lsl r0, r0, #1
    add r0, r0, r3
    ldrh r0, [r0]
    ldr r1, lbl_0803c9c8 @ =0x0875f774
    lsl r0, r0, #2
    add r0, r0, r1
    ldr r1, [r2, #0x18]
    ldr r0, [r0]
    cmp r1, r0
    beq lbl_0803c996
    str r0, [r2, #0x18]
    movs r0, #0
    strb r0, [r2, #0x1c]
    strh r0, [r2, #0x16]
lbl_0803c996:
    ldrb r1, [r2, #0x1e]
    lsl r0, r1, #1
    add r0, r0, r1
    lsl r0, r0, #1
    add r0, r0, r3
    ldrh r0, [r0, #2]
    ldrh r1, [r4, #6]
    add r0, r0, r1
    strh r0, [r2, #2]
    ldrb r1, [r2, #0x1e]
    lsl r0, r1, #1
    add r0, r0, r1
    lsl r0, r0, #1
    add r0, r0, r3
    ldrh r0, [r0, #4]
    ldrh r4, [r4, #8]
    add r0, r0, r4
    strh r0, [r2, #4]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803c9c0: .4byte 0x0300070c
lbl_0803c9c4: .4byte 0x03000738
lbl_0803c9c8: .4byte 0x0875f774");*/

/*void MotherBrainSyncSubSpritesPosition(void)
{
    // Function doesn't match without the necessary data (which isn't currently available)
    const u16 (*pFrame)[3];
    u32 offset;

    pFrame = (const u16 (*)[3])gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pFrame;
    offset = pFrame[gCurrentSprite.roomSlot][0]; // Frame data ID

    if (gCurrentSprite.pOam != ((const struct FrameData**)0x875f774)[offset])
    {
        gCurrentSprite.pOam = ((const struct FrameData**)0x875f774)[offset];
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pFrame[gCurrentSprite.roomSlot][1]; // Y offset
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pFrame[gCurrentSprite.roomSlot][2]; // X offset
}*/

/**
 * @brief 3c9cc | 80 | Updates the palette of mother brain when firing
 * 
 */
void MotherBrainUpdatePalette(void)
{
    u8 timer;
    u8 offset;
    u8 newTimer;

    if (gCurrentSprite.oamScaling != 0x0)
    {
        gCurrentSprite.oamScaling--;
        gCurrentSprite.paletteRow = sMotherBrainDynamicPaletteData[gCurrentSprite.oamRotation][0];
    }
    else
    {
        offset = gCurrentSprite.oamRotation++;
        timer = sMotherBrainDynamicPaletteData[offset][0];
        if (timer == 0x80)
        {
            gCurrentSprite.oamRotation = 0x1;
            offset = 0x0;
            timer = sMotherBrainDynamicPaletteData[offset][0];
        }

        newTimer = sMotherBrainDynamicPaletteData[offset][1];
        if (offset == 0x0 || offset == 0x6)
            SoundPlay(0x2BB);

        gCurrentSprite.paletteRow = timer;
        gCurrentSprite.oamScaling = newTimer;
    }
}

/**
 * @brief 3ca4c | 144 | Initializes mother brain
 * 
 */
void MotherBrainInit(void)
{
    u8 gfxSlot;
    u8 ramSlot;
    u16 yPosition;
    u16 xPosition;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ESCAPED_ZEBES) || EventFunction(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.xPosition += 0x20;
        gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

        yPosition = gSubSpriteData1.yPosition;
        xPosition = gSubSpriteData1.xPosition;
        gBossWork.work1 = yPosition;
        gBossWork.work2 = xPosition;
        gBossWork.work3 = 0x0;
        gBossWork.work4 = 0x0;
        gBossWork.work5 = 0x0;

        gCurrentSprite.drawDistanceTopOffset = 0x28;
        gCurrentSprite.drawDistanceBottomOffset = 0x20;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x30;

        gCurrentSprite.hitboxTopOffset = -0x70;
        gCurrentSprite.hitboxBottomOffset = 0x60;
        gCurrentSprite.hitboxLeftOffset = -0xA0;
        gCurrentSprite.hitboxRightOffset = 0x80;

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
        gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
        gCurrentSprite.timer = 0x0;
        gCurrentSprite.workVariable = 0x0;
        gCurrentSprite.oamScaling = 0x0;
        gCurrentSprite.oamRotation = 0x0;
        gCurrentSprite.workVariable2 = 0x0;
        
        gSubSpriteData1.pMultiOam = sMotherBrainMultiSpriteData;
        gSubSpriteData1.animationDurationCounter = 0x0;
        gSubSpriteData1.currentAnimationFrame = 0x0;
        gSubSpriteData1.workVariable3 = 0x0;

        gCurrentSprite.pose = MOTHER_BRAIN_POSE_WAITING_GLASS;
        gCurrentSprite.roomSlot = 0x1;

        gfxSlot = gCurrentSprite.spritesetGFXSlot;
        ramSlot = gCurrentSprite.primarySpriteRAMSlot;

        gSubSpriteData1.workVariable4 = SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_PART, MOTHER_BRAIN_PART_BEAM_SHOOTER,
            gfxSlot, ramSlot, yPosition, xPosition, 0x0);

        gSubSpriteData1.workVariable5 = SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_PART, MOTHER_BRAIN_PART_EYE,
            gfxSlot, ramSlot, yPosition, xPosition, 0x0);

        gSubSpriteData1.workVariable6 = SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_PART, MOTHER_BRAIN_PART_BOTTOM,
            gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    }
}

/**
 * @brief 3cb90 | 6c | Checks if the glass breaked, starts battle behaviors
 * 
 */
void MotherBrainCheckGlassBreaked(void)
{
    u8 eyeRamSlot;

    eyeRamSlot = gSubSpriteData1.workVariable5;
    if (gSubSpriteData1.workVariable3 == 0x1)
    {
        gCurrentSprite.pose = MOTHER_BRAIN_POSE_MAIN_LOOP;
        gSpriteData[eyeRamSlot].health = gCurrentSprite.health;
        gBossWork.work4 = gCurrentSprite.health;
        // Open eye
        gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOAM_EyeOpening;
        gSpriteData[eyeRamSlot].animationDurationCounter = 0x0;
        gSpriteData[eyeRamSlot].currentAnimationFrame = 0x0;
        SoundPlay(0x2B9); // Mother brain eye open
    }
}

/**
 * @brief 3cbfc | 3fc | Mother brain main behavior loop
 * 
 */
void MotherBrainMainLoop(void)
{
    u8 palette;
    u8 beamShooterRamSlot;
    u8 eyeRamSlot;
    u8 bottomRamSlot;
    u32 counter;

    beamShooterRamSlot = gSubSpriteData1.workVariable4;
    eyeRamSlot = gSubSpriteData1.workVariable5;
    bottomRamSlot = gSubSpriteData1.workVariable6;
    palette = gSpriteData[eyeRamSlot].paletteRow;
    
    gCurrentSprite.paletteRow = palette;
    gSpriteData[bottomRamSlot].paletteRow = palette;

    if (gSpriteData[eyeRamSlot].health == 0x0)
    {
        // Set dying behavior
        gCurrentSprite.pose = MOTHER_BRAIN_POSE_DYING;
        gCurrentSprite.pOam = sMotherBrainOAM_ChargingBeam;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.invicibilityStunFlashTimer = 0x78;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.health = 0x1;
        gCurrentSprite.paletteRow = 0x0;

        gSpriteData[eyeRamSlot].paletteRow = 0x0;
        gSpriteData[bottomRamSlot].paletteRow = 0x0;
               
        gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOAM_EyeDying;
        gSpriteData[eyeRamSlot].animationDurationCounter = 0x0;
        gSpriteData[eyeRamSlot].currentAnimationFrame = 0x0;
        gSpriteData[eyeRamSlot].samusCollision = SSC_NONE;

        gSpriteData[beamShooterRamSlot].status = 0x0;
        gSubSpriteData1.workVariable3 = 0x2;
        // Set event
        EventFunction(EVENT_ACTION_SETTING, EVENT_MOTHER_BRAIN_KILLED);
        SoundPlay(0x2BF); // Mother brain dying
        return;
    }

    if (gCurrentSprite.pOam == sMotherBrainOAM_ChargingBeam)
    {
        // delay before charging
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            gCurrentSprite.pOam = sMotherBrainOAM_Idle;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }
    else
    {
        if (gCurrentSprite.currentAnimationFrame == 0x1 && gCurrentSprite.animationDurationCounter == 0x1)
            SoundPlay(0x2BD); // Mother brain idle

        if ((gSpriteData[eyeRamSlot].invicibilityStunFlashTimer & 0x7F) == 0x10)
        {
            SoundPlay(0x2BE); // Mother brain hurt
            if (gSpriteData[eyeRamSlot].health < gBossWork.work4)
            {
                // Damage dealt, check should close eye
                // Add damage to counter
                gBossWork.work5 += (gBossWork.work4 - gSpriteData[eyeRamSlot].health);
                gBossWork.work4 = gSpriteData[eyeRamSlot].health;

                // Get counter threshold
                if (gDifficulty == DIFF_EASY)
                    counter = 0xC8;
                else if (gDifficulty == DIFF_HARD)
                    counter = 0x3C;
                else
                    counter = 0x64;

                if (gBossWork.work5 >= counter)
                {
                    // Set closing behavior
                    gBossWork.work5 = 0x0;
                    gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOAM_EyeClosing;
                    gSpriteData[eyeRamSlot].animationDurationCounter = 0x0;
                    gSpriteData[eyeRamSlot].currentAnimationFrame = 0x0;
                    gSpriteData[eyeRamSlot].properties |= SP_IMMUNE_TO_PROJECTILES;
                    SoundPlay(0x2BA); // Mother brain eye closing
                    gCurrentSprite.workVariable2 = 0x1;
                }
            }
        }
    }

    if (gSpriteData[eyeRamSlot].pOam == sMotherBrainPartOAM_EyeClosing)
    {
        // Check should close
        if (SpriteUtilCheckEndSpriteAnim(eyeRamSlot))
        {
            gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOAM_EyeClosed;
            gSpriteData[eyeRamSlot].animationDurationCounter = 0x0;
            gSpriteData[eyeRamSlot].currentAnimationFrame = 0x0;
        }
    }
    else if (gSpriteData[eyeRamSlot].pOam == sMotherBrainPartOAM_EyeClosed)
    {
        // Check should start charging beam
        if (gSubSpriteData1.yPosition + (BLOCK_SIZE * 2) >= gSamusData.yPosition)
        {
            gCurrentSprite.workVariable2--; // Delay
            if (gCurrentSprite.workVariable2 == 0x0)
            {
                // Set charging beam behavior
                gCurrentSprite.pOam = sMotherBrainOAM_ChargingBeam;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;

                gCurrentSprite.workVariable = 0x48;
                gCurrentSprite.timer = 0x48;
                gCurrentSprite.oamScaling = 0x0;
                gCurrentSprite.oamRotation = 0x0;
            }
        }
    }
    else if (gSpriteData[eyeRamSlot].pOam == sMotherBrainPartOAM_EyeOpening)
    {
        if (gCurrentSprite.workVariable == 0x0)
        {
            // Check should close eye
            if (gSubSpriteData1.yPosition + (BLOCK_SIZE * 2) < gSamusData.yPosition)
            {
                // Samus fell below the blocks, set closing behavior
                gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOAM_EyeClosing;
                gSpriteData[eyeRamSlot].animationDurationCounter = 0x0;
                gSpriteData[eyeRamSlot].currentAnimationFrame = 0x0;
                gSpriteData[eyeRamSlot].properties |= SP_IMMUNE_TO_PROJECTILES;
                SoundPlay(0x2BA); // Mother brain eye close
                gCurrentSprite.workVariable2 = 0x3C;
            }
            return;
        }
    }

    if (gCurrentSprite.workVariable == 0x0)
        return;
   
    // Shooting beam
    if (gCurrentSprite.workVariable-- == 0x1)
    {
        if (palette != 0xE)
        {
            // Set normal palette
            gCurrentSprite.paletteRow = 0x0;
            gSpriteData[eyeRamSlot].paletteRow = 0x0;
            gSpriteData[bottomRamSlot].paletteRow = 0x0;
        }
    }
    else
    {
        if (gCurrentSprite.workVariable == 0xC)
        {
            // Spawn beam
            SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_BEAM, 0x0, gCurrentSprite.spritesetGFXSlot,
                gCurrentSprite.primarySpriteRAMSlot, gSpriteData[beamShooterRamSlot].yPosition,
                gSpriteData[beamShooterRamSlot].xPosition + 0xCC, 0x0);

            // Hide beam shooter
            gSpriteData[beamShooterRamSlot].status |= SPRITE_STATUS_NOT_DRAWN;
        }
        else if (gCurrentSprite.workVariable == 0x14)
        {
            // Open eye
            gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOAM_EyeOpening;
            gSpriteData[eyeRamSlot].animationDurationCounter = 0x0;
            gSpriteData[eyeRamSlot].currentAnimationFrame = 0x0;
            // Make eye vulnerable
            gSpriteData[eyeRamSlot].properties &= ~SP_IMMUNE_TO_PROJECTILES;
            SoundPlay(0x2B9); // Mother brain eye open
        }
        else if (gCurrentSprite.workVariable == 0x18)
        {
            // Set beam shooter behavior
            gSpriteData[beamShooterRamSlot].pOam = sMotherBrainPartOAM_BeamSpawning;
            gSpriteData[beamShooterRamSlot].animationDurationCounter = 0x0;
            gSpriteData[beamShooterRamSlot].currentAnimationFrame = 0x0;
            gSpriteData[beamShooterRamSlot].status &= ~SPRITE_STATUS_NOT_DRAWN;
            SoundPlay(0x2BC);
        }

        if (palette != 0xE)
        {
            // Update palette
            MotherBrainUpdatePalette();
            gSpriteData[eyeRamSlot].paletteRow = gCurrentSprite.paletteRow;
            gSpriteData[bottomRamSlot].paletteRow = gCurrentSprite.paletteRow;
        }
    }
}

/**
 * @brief 3cff8 | cc | Handles the death of mother brain
 * 
 */
void MotherBrainDeath(void)
{
    u8 bottomRamSlot;
    u8 eyeRamSlot;

    eyeRamSlot = gSubSpriteData1.workVariable5;
    bottomRamSlot = gSubSpriteData1.workVariable6;

    if (gCurrentSprite.invicibilityStunFlashTimer != 0x0)
    {
        gSpriteData[eyeRamSlot].paletteRow = gCurrentSprite.paletteRow;
        gSpriteData[bottomRamSlot].paletteRow = gCurrentSprite.paletteRow;
        if (!(gCurrentSprite.invicibilityStunFlashTimer & 0x3F))
            make_background_flash(0x3); // Quick flash || Undefined
    }
    else
    {
        gSpriteData[eyeRamSlot].status = 0x0;
        gSpriteData[bottomRamSlot].status = 0x0;
        gCurrentSprite.pose = MOTHER_BRAIN_POSE_START_ESCAPE;
        gCurrentSprite.timer = 0x3C;
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        ParticleSet(gSubSpriteData1.yPosition + 0x46, gSubSpriteData1.xPosition - 0x3C, PE_MAIN_BOSS_DEATH);
        ParticleSet(gSubSpriteData1.yPosition + 0x3C, gSubSpriteData1.xPosition + 0x50, PE_MAIN_BOSS_DEATH);
        gInGameTimerAtBosses[1] = gInGameTimer;
        SoundPlay(0x2C0); // Mother brain death explosion
        make_background_flash(0x3); // Quick flash || Undefined
    }
}

/**
 * @brief 3d0c4 | 6c | Starts the escape
 * 
 */
void MotherBrainStartEscape(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        // Kill sprite
        gCurrentSprite.status = 0x0;
        // Spawn banner and effects
        SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_ZEBES_ESCAPE, 0x0, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        SpriteSpawnPrimary(PSPRITE_EXPLOSION_ZEBES_ESCAPE, 0x0, 0x0, gCurrentSprite.yPosition + (BLOCK_SIZE * 4), gCurrentSprite.xPosition, 0x0);
        MusicPlay(0x8, 0x40); // Escape
        SoundPlay(0x120);
        gSubSpriteData1.workVariable3 = 0x3;
    }
}

/**
 * @brief 3d130 | 158 | Initializes a mother brain part sprite
 * 
 */
void MotherBrainPartInit(void)
{
    u16 health;
    
    switch (gCurrentSprite.roomSlot)
    {
        case MOTHER_BRAIN_PART_BEAM_SHOOTER:
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x40;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4,
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.pose = 0x32;

            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.health = 0x1;
            break;

        case MOTHER_BRAIN_PART_EYE:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            gCurrentSprite.hitboxTopOffset = -0x28;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x4;
            
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pose = 0x8;
            break;

        case MOTHER_BRAIN_PART_BOTTOM:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x14;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

            gCurrentSprite.hitboxTopOffset = -0xF8;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = -0xB0;
            gCurrentSprite.hitboxRightOffset = 0xB0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x6;
            gCurrentSprite.pose = 0xE;
            health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.health = health;
            gBossWork.work3 = health;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 3d288 | a4 | Upates the hitbox of the mother brain eye
 * 
 */
void MotherBrainPartHitboxInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 0x1:
                gCurrentSprite.hitboxTopOffset = -0x10;
                gCurrentSprite.hitboxBottomOffset = 0x10;
                gCurrentSprite.hitboxLeftOffset = 0x20;
                gCurrentSprite.hitboxRightOffset = 0x60;
                break;

            case 0x2:
                gCurrentSprite.hitboxTopOffset = -0x20;
                gCurrentSprite.hitboxBottomOffset = 0x20;
                gCurrentSprite.hitboxLeftOffset = 0x40;
                gCurrentSprite.hitboxRightOffset = 0xA0;
                break;

            case 0x3:
                gCurrentSprite.hitboxTopOffset = -0x30;
                gCurrentSprite.hitboxBottomOffset = 0x30;
                gCurrentSprite.hitboxLeftOffset = 0xA0;
                gCurrentSprite.hitboxRightOffset = 0xE0;
                break;

            default:
                gCurrentSprite.hitboxTopOffset = -0x8;
                gCurrentSprite.hitboxBottomOffset = 0x8;
                gCurrentSprite.hitboxLeftOffset = -0x4;
                gCurrentSprite.hitboxRightOffset = 0x20;
        }
    }
}

/**
 * @brief 3d32c | 4 | Empty function
 * 
 */
void MotherBrainPart_Empty(void)
{
    return;
}

/**
 * @brief 3d330 | 74 | Spawns the mother brain block sprite if necessary
 * 
 */
void MotherBrainSpawnBlock(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gSubSpriteData1.yPosition - (BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
    xPosition = gSubSpriteData1.xPosition + (BLOCK_SIZE * 11 + HALF_BLOCK_SIZE);

    if (gSamusData.xPosition < (xPosition - 0x3C))
    {
        SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_BLOCK, 0x0, 0x6, gCurrentSprite.primarySpriteRAMSlot,
            yPosition, xPosition, 0x0);
        gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_STAGE_1;
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    }
}

/**
 * @brief 3d3a4 | 40 | First stage of the glass
 * 
 */
void MotherBrainPartGlassStage1(void)
{
    gCurrentSprite.invicibilityStunFlashTimer = 0x0;
    // 3/4 of health
    if (gCurrentSprite.health <= (gBossWork.work3 * 3) >> 2)
    {
        gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_STAGE_2;
        // Edit BG
        BGClipCallMotherBrainUpdateGlass(0x1);
        SoundPlay(0x2B5);
    }
}

/**
 * @brief 3d3e4 | 3c | Second stage of the glass
 * 
 */
void MotherBrainPartGlassStage2(void)
{
    gCurrentSprite.invicibilityStunFlashTimer = 0x0;
    // 2/4 of health
    if (gCurrentSprite.health <= gBossWork.work3 / 2)
    {
        gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_STAGE_3;
        // Edit BG
        BGClipCallMotherBrainUpdateGlass(0x2);
        SoundPlay(0x2B6);
    }
}

/**
 * @brief 3d420 | 3c | Third stage of the glass
 * 
 */
void MotherBrainPartGlassStage3(void)
{
    gCurrentSprite.invicibilityStunFlashTimer = 0x0;
    // 1/4 of health
    if (gCurrentSprite.health <= gBossWork.work3 / 4)
    {
        gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_BROKEN;
        // Edit BG
        BGClipCallMotherBrainUpdateGlass(0x3);
        SoundPlay(0x2B7);
    }
}

/**
 * @brief 3d45c | 10 | Sets the invicibility stun flash timer to 0
 * 
 */
void MotherBrainPartISFT(void)
{
    gCurrentSprite.invicibilityStunFlashTimer = 0x0;
}

/**
 * @brief 3d46c | 54 | Breaks the mother brain glass
 * 
 */
void MotherBrainPartSpawnGlassBreaking(void)
{
    gCurrentSprite.invicibilityStunFlashTimer = 0x0;
    gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_BROKEN;
    gSubSpriteData1.workVariable3 = 0x1;
    // Spawn glass
    SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_GLASS_BREAKING, 0x0, gCurrentSprite.spritesetGFXSlot,
        gCurrentSprite.primarySpriteRAMSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0x0);
    // Remove in BG
    BGClipCallMotherBrainUpdateGlass(0x4);
    SoundPlay(0x2B8);
}

/**
 * @brief 3d4c0 | e0 | Mother brain AI
 * 
 */
void MotherBrain(void)
{
    u8 mbSize;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            MotherBrainInit();
            break;

        case MOTHER_BRAIN_POSE_WAITING_GLASS:
            MotherBrainCheckGlassBreaked();
            break;

        case MOTHER_BRAIN_POSE_MAIN_LOOP:
            MotherBrainMainLoop();
            break;

        case MOTHER_BRAIN_POSE_DYING:
            MotherBrainDeath();
            break;

        case MOTHER_BRAIN_POSE_START_ESCAPE:
            MotherBrainStartEscape();
            break;
    }

    if (gCurrentSprite.pose < 0x8)
    {
        SpriteUtilUpdateSubSprite1Anim();
        MotherBrainSyncSubSpritesPosition();
    }
    else
    {
        SpriteUtilUpdateSubSprite1Anim();
        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    }

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && gSubSpriteData1.workVariable3 < 0x3
        && gSamusData.xPosition < (gSubSpriteData1.xPosition + (BLOCK_SIZE * 12)))
    {
        gLockScreen.lock = TRUE;
        gLockScreen.yPositionCenter = gBossWork.work1;
        gLockScreen.xPositionCenter = gSubSpriteData1.xPosition + (BLOCK_SIZE * 5);

        if (gSubSpriteData1.workVariable3 == 0x0)
            mbSize = 0xDC;
        else
            mbSize = 0xA0;

        if (gSamusData.xPosition < gBossWork.work2 + mbSize)
            gSamusData.xPosition = gBossWork.work2 + mbSize;
    }
    else
        gLockScreen.lock = FALSE;
}

/**
 * @brief 3d5a0 | a0 | Mother brain part AI
 * 
 */
void MotherBrainPart(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            MotherBrainPartInit();
            MotherBrainSyncSubSpritesPosition();
            return;

        case MOTHER_BRAIN_PART_POSE_UPDATE:
            MotherBrainPartHitboxInit();
            break;

        case MOTHER_BRAIN_PART_POSE_IDLE:
            MotherBrainPart_Empty();
            break;

        case MOTHER_BRAIN_PART_POSE_SPAWN_BLOCK:
            MotherBrainSpawnBlock();
            break;

        case MOTHER_BRAIN_PART_POSE_GLASS_STAGE_1:
            MotherBrainPartGlassStage1();
            break;

        case MOTHER_BRAIN_PART_POSE_GLASS_STAGE_2:
            MotherBrainPartGlassStage2();
            break;

        case MOTHER_BRAIN_PART_POSE_GLASS_STAGE_3:
            MotherBrainPartGlassStage3();
            break;

        case MOTHER_BRAIN_PART_POSE_GLASS_BROKEN:
            MotherBrainPartISFT();
            break;

        case MOTHER_BRAIN_PART_POSE_GLASS_BREAKING:
            if (gCurrentSprite.roomSlot == MOTHER_BRAIN_PART_BOTTOM)
                MotherBrainPartSpawnGlassBreaking();
            break;
    }

    if (gCurrentSprite.roomSlot == MOTHER_BRAIN_PART_BOTTOM)
        MotherBrainSyncSubSpritesPosition();
    else
        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
}

/**
 * @brief 3d640 | e4 | Mother brain beam AI
 * 
 */
void MotherBrainBeam(void)
{
    if (gSubSpriteData1.workVariable3 > 0x1)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.properties |= (SP_KILL_OFF_SCREEN | SP_IMMUNE_TO_PROJECTILES);

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x30;

            gCurrentSprite.hitboxTopOffset = -0x30;
            gCurrentSprite.hitboxBottomOffset = 0x30;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x20;

            gCurrentSprite.pOam = sMotherBrainBeamOAM_Moving;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = 0x9;
            gCurrentSprite.samusCollision = SSC_MOTHER_BRAIN_BEAM;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
            gCurrentSprite.health = 0x1;
            gCurrentSprite.timer = 0x10;

        case 0x9:
            gCurrentSprite.xPosition += 0xC;
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck != COLLISION_AIR)
            {
                ParticleSet(gCurrentSprite.yPosition + 0x1C, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_BIG);
                gCurrentSprite.status = 0x0;
                SoundPlay(0x2C3);
            }
    }
}

/**
 * @brief 3d724 | a8 | Mother brain block AI
 * 
 */
void MotherBrainBlock(void)
{
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.drawDistanceTopOffset = 0x10;
        gCurrentSprite.drawDistanceBottomOffset = 0x10;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

        gCurrentSprite.hitboxTopOffset = -0x20;
        gCurrentSprite.hitboxBottomOffset = 0x20;
        gCurrentSprite.hitboxLeftOffset = -0x20;
        gCurrentSprite.hitboxRightOffset = 0x20;

        gCurrentSprite.pOam = (struct FrameData*)0x82febfc;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;
    }
    else if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        else
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            
            gCurrentClipdataAffectingAction = CAA_MAKE_SOLID3;
            ClipdataProcess(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        }
    }
}

/**
 * @brief 3d7cc | 94 | Mother brain glass breaking AI
 * 
 */
void MotherBrainGlassBreaking(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.drawDistanceBottomOffset = 0x30;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x50;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.pOam = sMotherBrainGlassBreakingOAM_Breaking;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = 0x9;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
            break;

        case 0x9:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
                gCurrentSprite.status = 0x0;
    }
}