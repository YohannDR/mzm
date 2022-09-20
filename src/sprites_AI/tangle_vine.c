#include "tangle_vine.h"
#include "../../data/data.h"
#include "../data/pointers.c"
#include "../globals.h"

const i16 sTangleVineGerutaMultiSpriteData_Idle_Frame0[9] = {
    8, 0, -8,
    12, -200, 32,
    9, 0, 0
};

const i16 sTangleVineGerutaMultiSpriteData_Idle_Frame1[9] = {
    8, 0, 0,
    12, -196, 28,
    9, 0, 0
};

const i16 sTangleVineGerutaMultiSpriteData_Idle_Frame2[9] = {
    8, 0, 0,
    12, -192, 28,
    9, 0, 0
};

const i16 sTangleVineGerutaMultiSpriteData_Idle_Frame3[9] = {
    8, 0, 8,
    12, -188, 40,
    9, 0, 0
};

const struct FrameData sTangleVineGerutaMultiSpriteData_Idle[5] = {
    sTangleVineGerutaMultiSpriteData_Idle_Frame0,
    0xA,
    sTangleVineGerutaMultiSpriteData_Idle_Frame1,
    0xA,
    sTangleVineGerutaMultiSpriteData_Idle_Frame2,
    0xA,
    sTangleVineGerutaMultiSpriteData_Idle_Frame3,
    0xA,
    NULL,
    0x0
};

const u32 sTangleVineGFX[1298];
const u16 sTangleVinePAL[80];

const u16 sTangleVineTallOAM_OnGround_Frame3[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fa, OBJ_SPRITE_OAM | 0x1248,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fa, OBJ_SPRITE_OAM | 0x12c8,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x1258,
    0xdc, 0x1f5, OBJ_SPRITE_OAM | 0x1310
};

const u16 sTangleVineTallOAM_OnGround_Frame2[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x124a,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x12ca,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x1259,
    0xdb, 0x1f4, OBJ_SPRITE_OAM | 0x1310
};

const u16 sTangleVineTallOAM_OnGround_Frame1[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x124c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x12cc,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x125a,
    0xdc, 0x1f4, OBJ_SPRITE_OAM | 0x1310
};

const u16 sTangleVineTallOAM_OnGround_Frame0[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x124e,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x12ce,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f5, OBJ_SPRITE_OAM | 0x125b,
    0xdc, 0x1f3, OBJ_SPRITE_OAM | 0x1310
};

const u16 sTangleVineTallOAM_OnCeiling_Frame0[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x20, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x124c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x12cc,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x125a,
    0x1c, OBJ_Y_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x1310
};

const u16 sTangleVineTallOAM_OnCeiling_Frame1[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x20, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x124e,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x12ce,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f5, OBJ_SPRITE_OAM | 0x125b,
    0x1c, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x1310
};

const u16 sTangleVineTallOAM_OnCeiling_Frame2[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x20, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f9, OBJ_SPRITE_OAM | 0x1248,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f9, OBJ_SPRITE_OAM | 0x12c8,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f5, OBJ_SPRITE_OAM | 0x1258,
    0x1c, OBJ_Y_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x1310
};

const u16 sTangleVineTallOAM_OnCeiling_Frame3[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x20, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x124a,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x12ca,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x1259,
    0x1d, OBJ_Y_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x1310
};

const u16 sTangleVineMediumOAM_OnGround_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1250,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12d0,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125e
};

const u16 sTangleVineMediumOAM_OnGround_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1252,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125f
};

const u16 sTangleVineMediumOAM_OnGround_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1254,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12d4,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125c
};

const u16 sTangleVineMediumOAM_OnGround_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x1256,
    0xf0, OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x12d6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125d
};

const u16 sTangleVineMediumOAM_OnCeiling_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1252,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12d2,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f5, OBJ_SPRITE_OAM | 0x125c
};

const u16 sTangleVineMediumOAM_OnCeiling_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1254,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12d4,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f7, OBJ_SPRITE_OAM | 0x125d
};

const u16 sTangleVineMediumOAM_OnCeiling_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1256,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, OBJ_SPRITE_OAM | 0x12d6,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fa, OBJ_SPRITE_OAM | 0x125c
};

const u16 sTangleVineMediumOAM_OnCeiling_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1250,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12d0,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125d
};

const u16 sTangleVineShortOAM_OnGround_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1258,
    0xdd, 0x1fb, OBJ_SPRITE_OAM | 0x1310,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x125c
};

const u16 sTangleVineShortOAM_OnGround_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1259,
    0xdc, 0x1fb, OBJ_SPRITE_OAM | 0x1310,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x125d
};

const u16 sTangleVineShortOAM_OnGround_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x125a,
    0xde, 0x1fa, OBJ_SPRITE_OAM | 0x1310,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x125e
};

const u16 sTangleVineShortOAM_OnGround_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1fd, OBJ_SPRITE_OAM | 0x125b,
    0xdd, 0x1fa, OBJ_SPRITE_OAM | 0x1310,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x125f
};

const u16 sTangleVineShortOAM_OnCeiling_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1258,
    0x14, 0x0, OBJ_SPRITE_OAM | 0x1311,
    0x1b, 0x1fd, OBJ_SPRITE_OAM | 0x1312
};

const u16 sTangleVineShortOAM_OnCeiling_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1259,
    0x14, 0x1, OBJ_SPRITE_OAM | 0x1311,
    0x1b, 0x1fa, OBJ_SPRITE_OAM | 0x1312
};

const u16 sTangleVineShortOAM_OnCeiling_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x125a,
    0x15, 0x0, OBJ_SPRITE_OAM | 0x1311,
    0x1a, 0x1fb, OBJ_SPRITE_OAM | 0x1312
};

const u16 sTangleVineShortOAM_OnCeiling_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x125b,
    0x14, 0x1ff, OBJ_SPRITE_OAM | 0x1311,
    0x1c, 0x1fb, OBJ_SPRITE_OAM | 0x1312
};

const u16 sTangleVineCurvedOAM_OnGround_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x125c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125e,
    0xdf, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x1312
};

const u16 sTangleVineCurvedOAM_OnGround_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x125d,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125f,
    0xdd, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x1312
};

const u16 sTangleVineCurvedOAM_OnGround_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x125e,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125c,
    0xdc, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x1312
};

const u16 sTangleVineCurvedOAM_OnGround_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x125f,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125d,
    0xdb, OBJ_X_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x1312
};

const u16 sTangleVineCurvedOAM_OnCeiling_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fa, OBJ_SPRITE_OAM | 0x125c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fe, OBJ_SPRITE_OAM | 0x125e,
    0x1c, 0x1f7, OBJ_SPRITE_OAM | 0x1311
};

const u16 sTangleVineCurvedOAM_OnCeiling_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fa, OBJ_SPRITE_OAM | 0x125d,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fe, OBJ_SPRITE_OAM | 0x125f,
    0x1d, 0x1f8, OBJ_SPRITE_OAM | 0x1311
};

const u16 sTangleVineCurvedOAM_OnCeiling_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fa, OBJ_SPRITE_OAM | 0x125e,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fe, OBJ_SPRITE_OAM | 0x125c,
    0x1d, 0x1fa, OBJ_SPRITE_OAM | 0x1311
};

const u16 sTangleVineCurvedOAM_OnCeiling_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fa, OBJ_SPRITE_OAM | 0x125f,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fe, OBJ_SPRITE_OAM | 0x125d,
    0x1d, 0x1fc, OBJ_SPRITE_OAM | 0x1311
};

const u16 sTangleVineOAM_Unused_Frame[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x1240
};

const u16 sTangleVineGerutaPartOAM_Grip_Frame2[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xbf, OBJ_SIZE_16x32 | 0x1fd, OBJ_SPRITE_OAM | 0x1242
};

const u16 sTangleVineGerutaPartOAM_Grip_Frame4[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xc1, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1244
};

const u16 sTangleVineGerutaPartOAM_Grip_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xc3, OBJ_SIZE_16x32 | 0x1, OBJ_SPRITE_OAM | 0x1246
};

const u16 sTangleVineGerutaPartOAM_Grip_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x1240
};

const u16 sTangleVineGerutaPartOAM_Grip_Frame3[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xbf, OBJ_SIZE_16x32 | 0x1fd, OBJ_SPRITE_OAM | 0x1242
};

const u16 sTangleVineGerutaPartOAM_Grip_Frame5[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xc1, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1244
};

const u16 sTangleVineGerutaPartOAM_Grip_Frame7[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xc3, OBJ_SIZE_16x32 | 0x1, OBJ_SPRITE_OAM | 0x1246
};

const u16 sTangleVineGerutaOAM_Full_Frame0[13] = {
    0x4,
    0xd0, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x1288,
    OBJ_SHAPE_VERTICAL | 0xc1, OBJ_SIZE_16x32 | 0x1fd, OBJ_SPRITE_OAM | 0x1240,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f9, OBJ_SPRITE_OAM | 0x12c8,
    0xc8, 0x1ff, OBJ_SPRITE_OAM | 0x1261
};

const u16 sTangleVineGerutaOAM_Full_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xbf, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1242,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fa, OBJ_SPRITE_OAM | 0x124a,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fa, OBJ_SPRITE_OAM | 0x12ca
};

const u16 sTangleVineGerutaOAM_Full_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xc1, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1244,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x124c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x12cc
};

const u16 sTangleVineGerutaOAM_Full_Frame3[13] = {
    0x4,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x128e,
    OBJ_SHAPE_VERTICAL | 0xc1, OBJ_SIZE_16x32 | 0x1fd, OBJ_SPRITE_OAM | 0x1246,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x12ce,
    OBJ_SHAPE_HORIZONTAL | 0xc8, 0x1f8, OBJ_SPRITE_OAM | 0x126e
};

const u16 sTangleVineGerutaOAM_Root_Frame0[10] = {
    0x3,
    0xc7, 0x1ff, OBJ_SPRITE_OAM | 0x1261,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f9, OBJ_SPRITE_OAM | 0x12c8,
    0xd0, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x1288
};

const u16 sTangleVineGerutaOAM_Root_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x124a,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x12ca
};

const u16 sTangleVineGerutaOAM_Root_Frame4[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x124c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x12cc
};

const u16 sTangleVineGerutaOAM_Root_Frame6[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x12ce,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x128e
};

const u16 sTangleVineGerutaOAM_Root_Frame1[10] = {
    0x3,
    0xc7, 0x1ff, OBJ_SPRITE_OAM | 0x1261,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f9, OBJ_SPRITE_OAM | 0x12c8,
    0xd0, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x1288
};

const u16 sTangleVineGerutaOAM_Root_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x124a,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x12ca
};

const u16 sTangleVineGerutaOAM_Root_Frame5[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x124c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x12cc
};

const u16 sTangleVineGerutaOAM_Root_Frame7[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x12ce,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x128e
};

const u16 sTangleVineRedGerutaOAM_Frame0[28] = {
    0x9,
    OBJ_SHAPE_VERTICAL | 0xbb, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f5, OBJ_SPRITE_OAM | 0x22c2,
    OBJ_SHAPE_HORIZONTAL | 0xd5, 0x1fa, OBJ_SPRITE_OAM | 0x2316,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1f7, OBJ_SPRITE_OAM | 0x22d8,
    0xd5, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x2202,
    0xd3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x2208,
    0xd4, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x2208,
    0xd9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x2212,
    0xd9, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x2212,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x22c0
};

const u16 sTangleVineRedGerutaOAM_Frame1[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xd5, 0x1fb, OBJ_SPRITE_OAM | 0x2316,
    OBJ_SHAPE_VERTICAL | 0xbb, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x22c4,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1f9, OBJ_SPRITE_OAM | 0x22da,
    0xd5, OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x2202,
    0xd3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x2208,
    0xd4, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x2208,
    0xd9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x2212,
    0xd9, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2212,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x22c2
};

const u16 sTangleVineRedGerutaOAM_Frame2[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xd7, 0x1fa, OBJ_SPRITE_OAM | 0x2316,
    OBJ_SHAPE_VERTICAL | 0xbc, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f3, OBJ_SPRITE_OAM | 0x22c6,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f7, OBJ_SPRITE_OAM | 0x22dc,
    0xd7, OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x2202,
    0xd5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x2208,
    0xd6, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x2208,
    0xdb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x2212,
    0xdb, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2212,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x22c4
};

const u16 sTangleVineRedGerutaOAM_Frame3[28] = {
    0x9,
    OBJ_SHAPE_VERTICAL | 0xbb, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f5, OBJ_SPRITE_OAM | 0x22c0,
    OBJ_SHAPE_HORIZONTAL | 0xd6, 0x1fa, OBJ_SPRITE_OAM | 0x2316,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1f7, OBJ_SPRITE_OAM | 0x22da,
    0xd6, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x2202,
    0xd4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x2208,
    0xd5, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x2208,
    0xda, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x2212,
    0xda, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x2212,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x22c6
};

const u16 sTangleVineGerutaPartOAM_Geruta_Frame0[16] = {
    0x5,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x208,
    0xf6, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x208,
    0xfa, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x212,
    0xfb, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212
};

const u16 sTangleVineGerutaPartOAM_Geruta_Frame2[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x204,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x212,
    0xfc, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x212
};

const u16 sTangleVineGerutaPartOAM_Geruta_Frame4[16] = {
    0x5,
    0xf5, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x20a,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x204,
    0xfd, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x210,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x210
};

const u16 sTangleVineGerutaPartOAM_Geruta_Frame6[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x204,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x212,
    0xfc, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x212
};

const u16 sTangleVineGerutaPartOAM_Geruta_Frame1[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x202,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x212,
    0xfc, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212
};

const u16 sTangleVineGerutaPartOAM_Geruta_Frame3[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x202,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x212,
    0xfc, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212
};

const u16 sTangleVineGerutaPartOAM_Geruta_Frame5[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x202,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x208,
    0xf7, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x208,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x212,
    0xfc, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212
};

const u16 sTangleVineGerutaPartOAM_Geruta_Frame7[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x200,
    0xf9, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x208,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x208,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x212,
    0xfd, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212
};

const u16 sTangleVineLarvaRightOAM_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x22c0,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fb, OBJ_SPRITE_OAM | 0x2313,
    OBJ_SHAPE_VERTICAL | 0xc8, OBJ_Y_FLIP | 0x3, OBJ_SPRITE_OAM | 0x2313
};

const u16 sTangleVineLarvaRightOAM_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x22c2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fb, OBJ_SPRITE_OAM | 0x2313,
    OBJ_SHAPE_VERTICAL | 0xc9, OBJ_Y_FLIP | 0x1, OBJ_SPRITE_OAM | 0x2313
};

const u16 sTangleVineLarvaRightOAM_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x22c4,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fb, OBJ_SPRITE_OAM | 0x2313,
    OBJ_SHAPE_VERTICAL | 0xc9, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x2313
};

const u16 sTangleVineLarvaRightOAM_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x22c6,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fb, OBJ_SPRITE_OAM | 0x2313,
    OBJ_SHAPE_VERTICAL | 0xc8, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x2313
};

const u16 sTangleVineLarvaLeftOAM_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x22c0,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x2313,
    OBJ_SHAPE_VERTICAL | 0xc9, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x2313
};

const u16 sTangleVineLarvaLeftOAM_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x22c2,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x2313,
    OBJ_SHAPE_VERTICAL | 0xcb, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x2313
};

const u16 sTangleVineLarvaLeftOAM_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f5, OBJ_SPRITE_OAM | 0x22c4,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x2313,
    OBJ_SHAPE_VERTICAL | 0xcb, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x2313
};

const u16 sTangleVineLarvaLeftOAM_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f5, OBJ_SPRITE_OAM | 0x22c6,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x2313,
    OBJ_SHAPE_VERTICAL | 0xc9, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f9, OBJ_SPRITE_OAM | 0x2313
};

const struct FrameData sTangleVineTallOAM_OnGround[5] = {
    sTangleVineTallOAM_OnGround_Frame0,
    0xC,
    sTangleVineTallOAM_OnGround_Frame1,
    0xC,
    sTangleVineTallOAM_OnGround_Frame2,
    0xC,
    sTangleVineTallOAM_OnGround_Frame3,
    0xC,
    NULL,
    0x0
};

const struct FrameData sTangleVineMediumOAM_OnGround[5] = {
    sTangleVineMediumOAM_OnGround_Frame0,
    0xA,
    sTangleVineMediumOAM_OnGround_Frame1,
    0xA,
    sTangleVineMediumOAM_OnGround_Frame2,
    0xA,
    sTangleVineMediumOAM_OnGround_Frame3,
    0xA,
    NULL,
    0x0
};

const struct FrameData sTangleVineShortOAM_OnGround[5] = {
    sTangleVineTallOAM_OnGround_Frame0,
    0x8,
    sTangleVineTallOAM_OnGround_Frame1,
    0x8,
    sTangleVineTallOAM_OnGround_Frame2,
    0x8,
    sTangleVineTallOAM_OnGround_Frame3,
    0x8,
    NULL,
    0x0
};

const struct FrameData sTangleVineCurvedOAM_OnGround[7] = {
    sTangleVineCurvedOAM_OnGround_Frame0,
    0xA,
    sTangleVineCurvedOAM_OnGround_Frame1,
    0xA,
    sTangleVineCurvedOAM_OnGround_Frame2,
    0xA,
    sTangleVineCurvedOAM_OnGround_Frame3,
    0xA,
    sTangleVineCurvedOAM_OnGround_Frame2,
    0xA,
    sTangleVineCurvedOAM_OnGround_Frame1,
    0xA,
    NULL,
    0x0
};

const struct FrameData sTangleVineTallOAM_OnCeiling[5] = {
    sTangleVineTallOAM_OnCeiling_Frame0,
    0xD,
    sTangleVineTallOAM_OnCeiling_Frame1,
    0xD,
    sTangleVineTallOAM_OnCeiling_Frame2,
    0xD,
    sTangleVineTallOAM_OnCeiling_Frame3,
    0xD,
    NULL,
    0x0
};

const struct FrameData sTangleVineMediumOAM_OnCeiling[5] = {
    sTangleVineMediumOAM_OnCeiling_Frame0,
    0xB,
    sTangleVineMediumOAM_OnCeiling_Frame1,
    0xB,
    sTangleVineMediumOAM_OnCeiling_Frame2,
    0xB,
    sTangleVineMediumOAM_OnCeiling_Frame3,
    0xB,
    NULL,
    0x0
};

const struct FrameData sTangleVineShortOAM_OnCeiling[5] = {
    sTangleVineShortOAM_OnCeiling_Frame0,
    0x7,
    sTangleVineShortOAM_OnCeiling_Frame1,
    0x7,
    sTangleVineShortOAM_OnCeiling_Frame2,
    0x7,
    sTangleVineShortOAM_OnCeiling_Frame3,
    0x7,
    NULL,
    0x0
};

const struct FrameData sTangleVineCurvedOAM_OnCeiling[5] = {
    sTangleVineCurvedOAM_OnCeiling_Frame0,
    0x5,
    sTangleVineCurvedOAM_OnCeiling_Frame1,
    0x5,
    sTangleVineCurvedOAM_OnCeiling_Frame2,
    0x5,
    sTangleVineCurvedOAM_OnCeiling_Frame3,
    0x5,
    NULL,
    0x0
};

const struct FrameData sTangleVineGerutaPartOAM_Grip[9] = {
    sTangleVineGerutaPartOAM_Grip_Frame0,
    0x4,
    sTangleVineGerutaPartOAM_Grip_Frame1,
    0x6,
    sTangleVineGerutaPartOAM_Grip_Frame2,
    0x4,
    sTangleVineGerutaPartOAM_Grip_Frame3,
    0x6,
    sTangleVineGerutaPartOAM_Grip_Frame4,
    0x4,
    sTangleVineGerutaPartOAM_Grip_Frame5,
    0x6,
    sTangleVineGerutaPartOAM_Grip_Frame0,
    0x4,
    sTangleVineGerutaPartOAM_Grip_Frame7,
    0x6,
    NULL,
    0x0
};

const struct FrameData sTangleVineGerutaOAM_Root[9] = {
    sTangleVineGerutaOAM_Root_Frame0,
    0x4,
    sTangleVineGerutaOAM_Root_Frame1,
    0x6,
    sTangleVineGerutaOAM_Root_Frame2,
    0x4,
    sTangleVineGerutaOAM_Root_Frame3,
    0x6,
    sTangleVineGerutaOAM_Root_Frame4,
    0x4,
    sTangleVineGerutaOAM_Root_Frame5,
    0x6,
    sTangleVineGerutaOAM_Root_Frame6,
    0x4,
    sTangleVineGerutaOAM_Root_Frame7,
    0x6,
    NULL,
    0x0
};

const struct FrameData sTangleVineGerutaOAM_Full[5] = {
    sTangleVineGerutaOAM_Full_Frame0,
    0xC,
    sTangleVineGerutaOAM_Full_Frame1,
    0xC,
    sTangleVineGerutaOAM_Full_Frame2,
    0xC,
    sTangleVineGerutaOAM_Full_Frame3,
    0xC,
    NULL,
    0x0
};

const struct FrameData sTangleVineRedGerutaOAM[5] = {
    sTangleVineRedGerutaOAM_Frame0,
    0xC,
    sTangleVineRedGerutaOAM_Frame1,
    0xC,
    sTangleVineRedGerutaOAM_Frame2,
    0xC,
    sTangleVineRedGerutaOAM_Frame3,
    0xC,
    NULL,
    0x0
};

const struct FrameData sTangleVineGerutaPartOAM_Geruta[9] = {
    sTangleVineGerutaPartOAM_Geruta_Frame0,
    0x4,
    sTangleVineGerutaPartOAM_Geruta_Frame1,
    0x6,
    sTangleVineGerutaPartOAM_Geruta_Frame2,
    0x4,
    sTangleVineGerutaPartOAM_Geruta_Frame3,
    0x6,
    sTangleVineGerutaPartOAM_Geruta_Frame4,
    0x4,
    sTangleVineGerutaPartOAM_Geruta_Frame5,
    0x6,
    sTangleVineGerutaPartOAM_Geruta_Frame6,
    0x4,
    sTangleVineGerutaPartOAM_Geruta_Frame7,
    0x6,
    NULL,
    0x0
};

const struct FrameData sTangleVineLarvaRightOAM[5] = {
    sTangleVineLarvaRightOAM_Frame0,
    0xC,
    sTangleVineLarvaRightOAM_Frame1,
    0xC,
    sTangleVineLarvaRightOAM_Frame2,
    0xC,
    sTangleVineLarvaRightOAM_Frame3,
    0xC,
    NULL,
    0x0
};

const struct FrameData sTangleVineLarvaLeftOAM[5] = {
    sTangleVineLarvaLeftOAM_Frame0,
    0x8,
    sTangleVineLarvaLeftOAM_Frame1,
    0x8,
    sTangleVineLarvaLeftOAM_Frame2,
    0x8,
    sTangleVineLarvaLeftOAM_Frame3,
    0x8,
    NULL,
    0x0
};


/**
 * @brief 413c4 | 88 | Synchronize the sub sprites of a tangle vine
 * 
 */
void TangleVineSyncSprites(void)
{
    u16 (*pData)[3];
    u32 offset;

    pData = (u16(*)[3])gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pFrame;
    offset = pData[gCurrentSprite.roomSlot][0];
    
    if (gCurrentSprite.pOam != sTangleVineFrameDataPointers[offset])
    {
        gCurrentSprite.pOam = sTangleVineFrameDataPointers[offset];
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][1];

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition - pData[gCurrentSprite.roomSlot][2];
    else
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][2];
}

/**
 * @brief 4144c | 1a0 | Tangle vine (geruta) AI
 * 
 */
void TangleVineGeruta(void)
{
    u8 gfxSlot;
    u32 ramSlot;
    u16 yPosition;
    u16 xPosition;
    u8 newRamSlot;
    u8 counter;

    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x264);
    }

    counter = 0x0;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.drawDistanceTopOffset = 0x40;
        gCurrentSprite.drawDistanceBottomOffset = 0x0;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

        gCurrentSprite.hitboxTopOffset = -0xE0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = -0x1C;
        gCurrentSprite.hitboxRightOffset = 0x1C;

        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;
        gCurrentSprite.pose = 0x9;

        gCurrentSprite.pOam = sTangleVineGerutaOAM_Root;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gSubSpriteData1.pMultiOam = sTangleVineGerutaMultiSpriteData_Idle;
        gSubSpriteData1.animationDurationCounter = 0x0;
        gSubSpriteData1.currentAnimationFrame = 0x0;

        gSubSpriteData1.health = TANGLE_VINE_GERUTA_STATUS_VINE_DEAD;
        gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

        gCurrentSprite.frozenPaletteRowOffset = 0x1;
        gCurrentSprite.drawOrder = 0x5;
        gCurrentSprite.roomSlot = TANGLE_VINE_GERUTA_PART_ROOT;

        yPosition = gSubSpriteData1.yPosition;
        xPosition = gSubSpriteData1.xPosition;
        gfxSlot = gCurrentSprite.spritesetGFXSlot;
        ramSlot = gCurrentSprite.primarySpriteRAMSlot;

        newRamSlot = SpriteSpawnSecondary(SSPRITE_TANGLE_VINE_GERUTA_PART, TANGLE_VINE_GERUTA_PART_GRIP, gfxSlot,
            ramSlot, yPosition, xPosition, 0x0);

        if (newRamSlot >= MAX_AMOUNT_OF_SPRITES)
            counter = TRUE;

        newRamSlot = SpriteSpawnSecondary(SSPRITE_TANGLE_VINE_GERUTA_PART, TANGLE_VINE_GERUTA_PART_GERUTA, gfxSlot,
            ramSlot, yPosition, xPosition, 0x0);

        if (newRamSlot >= MAX_AMOUNT_OF_SPRITES)
            counter++;

        if (counter != 0x0)
            gCurrentSprite.status = 0x0;
        else
            gSubSpriteData1.health = TANGLE_VINE_GERUTA_STATUS_FULL;
    }
    else 
    {
        if (gCurrentSprite.pose > 0x61)
        {
            gSubSpriteData1.health = TANGLE_VINE_GERUTA_STATUS_VINE_DEAD;
            ParticleSet(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - 0x92, gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE, TRUE, PE_SPRITE_EXPLOSION_BIG);
            return;
        }

        if (gCurrentSprite.pose == 0x9 && gSubSpriteData1.health == TANGLE_VINE_GERUTA_STATUS_GERUTA_DEAD)
        {
            gCurrentSprite.pOam = sTangleVineGerutaOAM_Full;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = 0x23;
        }
    }

    SpriteUtilUpdateSubSprite1Anim();
    SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOAM();
}

/**
 * @brief 415ec | 130 | Tangle vine (geruta) part AI
 * 
 */
void TangleVineGerutaPart(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.pose = 0xF;

        if (gCurrentSprite.roomSlot == TANGLE_VINE_GERUTA_PART_GRIP)
        {
            gCurrentSprite.drawDistanceTopOffset = 0x40;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.health = 0x0;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x3;
        }
        else if (gCurrentSprite.roomSlot == TANGLE_VINE_GERUTA_PART_GERUTA)
        {
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            gCurrentSprite.hitboxTopOffset = -0x20;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = -0x40;
            gCurrentSprite.hitboxRightOffset = 0x40;

            gCurrentSprite.health = 0x1;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        }
        else
            gCurrentSprite.status = 0x0;
    }

    if (gCurrentSprite.roomSlot == TANGLE_VINE_GERUTA_PART_GRIP)
    {
        if (gSubSpriteData1.health != TANGLE_VINE_GERUTA_STATUS_FULL)
        {
            gCurrentSprite.status = 0x0;
            return;
        }
        else
            gCurrentSprite.paletteRow = gSpriteData[ramSlot].paletteRow;
    }
    else if (gCurrentSprite.roomSlot == TANGLE_VINE_GERUTA_PART_GERUTA)
    {
        if (gCurrentSprite.health == 0x0)
        {
            gSubSpriteData1.health = TANGLE_VINE_GERUTA_STATUS_GERUTA_DEAD;
            ParticleSet(gCurrentSprite.yPosition + 0x8, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
            SoundPlay(0x12D);
            gCurrentSprite.status = 0x0;
            return;
        }
        
        if (gSubSpriteData1.health == TANGLE_VINE_GERUTA_STATUS_VINE_DEAD)
        {
            SpriteSpawnPrimary(PSPRITE_GERUTA_RED, 0x80, 0x5, gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition, 0x0);
            gCurrentSprite.status = 0x0;
            return;
        }
    }

    TangleVineSyncSprites();
}

/**
 * @brief 417ac | cc | Tangle vine (red geruta) AI
 * 
 */
void TangleVineRedGeruta(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x264);
    }

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.drawDistanceTopOffset = 0x48;
        gCurrentSprite.drawDistanceBottomOffset = 0x0;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

        gCurrentSprite.hitboxTopOffset = -0x110;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = -0x24;
        gCurrentSprite.hitboxRightOffset = 0x24;

        gCurrentSprite.pOam = sTangleVineRedGerutaOAM;
        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x2;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        ParticleSet(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE,
            PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - 0x92,
            gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}

/**
 * @brief 417e8 | d0 | Tangle vine (imago right) AI
 * 
 */
void TangleVineLarvaRight(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x264);
    }

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.yPosition -= QUARTER_BLOCK_SIZE;

        gCurrentSprite.drawDistanceTopOffset = 0x38;
        gCurrentSprite.drawDistanceBottomOffset = 0x8;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

        gCurrentSprite.hitboxTopOffset = -0xC0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = 0x0;
        gCurrentSprite.hitboxRightOffset = 0x24;

        gCurrentSprite.pOam = sTangleVineLarvaRightOAM;
        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x2;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        ParticleSet(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE, PE_SPRITE_EXPLOSION_BIG);
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - 0x78,
            gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}

/**
 * @brief 418b8 | d4 | Tangle vine (imago left) AI
 * 
 */
void TangleVineLarvaLeft(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x264);
    }

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.xPosition -= QUARTER_BLOCK_SIZE;

        gCurrentSprite.drawDistanceTopOffset = 0x38;
        gCurrentSprite.drawDistanceBottomOffset = 0x8;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

        gCurrentSprite.hitboxTopOffset = -0xC0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = -0x24;
        gCurrentSprite.hitboxRightOffset = 0x0;

        gCurrentSprite.pOam = sTangleVineLarvaLeftOAM;
        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x2;
        gCurrentSprite.drawOrder = 0x5;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        ParticleSet(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE, PE_SPRITE_EXPLOSION_BIG);
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - 0x78,
            gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}

/**
 * @brief 4198c | 130 | Tangle vine (tall) AI
 * 
 */
void TangleVineTall(void)
{
    u16 yPosition;

    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x264);
    }

    if (gCurrentSprite.pose == 0x0)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.drawDistanceTopOffset = 0x40;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0xF8;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = -0x18;
            gCurrentSprite.hitboxRightOffset = 0x18;

            gCurrentSprite.pOam = sTangleVineTallOAM_OnGround;
        }
        else
        {
            gCurrentSprite.drawDistanceTopOffset = 0x0;
            gCurrentSprite.drawDistanceBottomOffset = 0x40;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0xF8;
            gCurrentSprite.hitboxLeftOffset = -0x18;
            gCurrentSprite.hitboxRightOffset = 0x18;

            gCurrentSprite.pOam = sTangleVineTallOAM_OnCeiling;

            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }

        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;

        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x1;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
            yPosition = gCurrentSprite.yPosition + 0x64;
        else
            yPosition = gCurrentSprite.yPosition - BLOCK_SIZE;

        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}

/**
 * @brief 41abc | 130 | Tangle vine (medium) AI
 * 
 */
void TangleVineMedium(void)
{
    u16 yPosition;

    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x264);
    }

    if (gCurrentSprite.pose == 0x0)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0xB8;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = -0x18;
            gCurrentSprite.hitboxRightOffset = 0x18;

            gCurrentSprite.pOam = sTangleVineMediumOAM_OnGround;
        }
        else
        {
            gCurrentSprite.drawDistanceTopOffset = 0x0;
            gCurrentSprite.drawDistanceBottomOffset = 0x30;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0xB8;
            gCurrentSprite.hitboxLeftOffset = -0x18;
            gCurrentSprite.hitboxRightOffset = 0x18;

            gCurrentSprite.pOam = sTangleVineMediumOAM_OnCeiling;

            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }

        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;

        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x1;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
            yPosition = gCurrentSprite.yPosition + 0x70;
        else
            yPosition = gCurrentSprite.yPosition - 0x30;

        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
    }
}

/**
 * @brief 41bec | 130 | Tangle vine (curved) AI
 * 
 */
void TangleVineCurved(void)
{
    u16 yPosition;

    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x264);
    }

    if (gCurrentSprite.pose == 0x0)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.drawDistanceTopOffset = 0x28;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = -0x80;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.pOam = sTangleVineCurvedOAM_OnGround;
        }
        else
        {
            gCurrentSprite.drawDistanceTopOffset = 0x0;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x80;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.pOam = sTangleVineCurvedOAM_OnCeiling;

            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }

        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;

        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x1;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
            yPosition = gCurrentSprite.yPosition + 0x48;
        else
            yPosition = gCurrentSprite.yPosition - 0x28;

        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
    }
}

/**
 * @brief 41d1c | 130 | Tangle vine (short) AI
 * 
 */
void TangleVineShort(void)
{
    u16 yPosition;

    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x264);
    }

    if (gCurrentSprite.pose == 0x0)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.drawDistanceTopOffset = 0x28;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = -0x88;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.pOam = sTangleVineShortOAM_OnGround;
        }
        else
        {
            gCurrentSprite.drawDistanceTopOffset = 0x0;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x88;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.pOam = sTangleVineShortOAM_OnCeiling;

            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }

        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;

        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x1;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
            yPosition = gCurrentSprite.yPosition + BLOCK_SIZE;
        else
            yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;

        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}