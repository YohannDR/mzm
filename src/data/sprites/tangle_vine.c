#include "data/sprites/tangle_vine.h"
#include "macros.h"

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

const u32 sTangleVineGFX[1298] = INCBIN_U32("data/sprites/TangleVine.gfx.lz");
const u16 sTangleVinePAL[80] = INCBIN_U16("data/sprites/TangleVine.pal");

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
    sTangleVineShortOAM_OnGround_Frame0,
    0x8,
    sTangleVineShortOAM_OnGround_Frame1,
    0x8,
    sTangleVineShortOAM_OnGround_Frame2,
    0x8,
    sTangleVineShortOAM_OnGround_Frame3,
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
    0x6,
    sTangleVineCurvedOAM_OnGround_Frame3,
    0x6,
    sTangleVineCurvedOAM_OnGround_Frame2,
    0x6,
    sTangleVineCurvedOAM_OnGround_Frame1,
    0x6,
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
