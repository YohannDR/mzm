#include "atomic.h"
#include "../../data/data.h"
#include "../globals.h"

const i16 sAtomicIdleYMovement[65] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 2,
    2, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, -1,
    -1, -1, -1, -1, -1, -1, 0, -1, 0, -1, 0, -1, 0,
    -1, 0, 0, 0, 0, SPRITE_ARRAY_TERMINATOR
};

const i16 sAtomicIdleXMovement[81] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1,
    1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1,
    0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1,
    0, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, 0, -1, 0,
    -1, 0, -1, 0, 0, 0, 0, SPRITE_ARRAY_TERMINATOR
};

const u32 sAtomicGFX[752];
const u16 sAtomicPAL[64];

const u16 sAtomicOAM_Idle_Frame0[13] = {
    0x4,
    0xf4, 0x1fc, OBJ_SPRITE_OAM | 0x292,
    0xfc, 0x4, OBJ_SPRITE_OAM | 0x291,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a,
    0x1, 0x1f7, OBJ_SPRITE_OAM | 0x293
};

const u16 sAtomicOAM_Idle_Frame1[10] = {
    0x3,
    0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x293,
    0x0, 0x1, OBJ_SPRITE_OAM | 0x293,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c
};

const u16 sAtomicOAM_Idle_Frame2[13] = {
    0x4,
    0xfc, 0x1f4, OBJ_SPRITE_OAM | 0x291,
    0x3, 0x1fe, OBJ_SPRITE_OAM | 0x292,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xf7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1, OBJ_SPRITE_OAM | 0x293
};

const u16 sAtomicOAM_Idle_Frame3[13] = {
    0x4,
    0xf8, 0x0, OBJ_SPRITE_OAM | 0x293,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0xfb, 0x1f5, OBJ_SPRITE_OAM | 0x291,
    0x3, 0x1fc, OBJ_SPRITE_OAM | 0x292
};

const u16 sAtomicOAM_Idle_Frame4[13] = {
    0x4,
    0xfd, 0x1fe, OBJ_SPRITE_OAM | 0x293,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a,
    0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x291,
    0x3, 0x1fa, OBJ_SPRITE_OAM | 0x292
};

const u16 sAtomicOAM_Idle_Frame5[13] = {
    0x4,
    0x1, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x293,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x218,
    0xf5, OBJ_X_FLIP | 0x1f9, OBJ_SPRITE_OAM | 0x292,
    0xff, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x291
};

const u16 sAtomicOAM_Idle_Frame6[13] = {
    0x4,
    0xf4, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x292,
    0xfc, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x291,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a,
    0x1, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x293
};

const u16 sAtomicOAM_Idle_Frame7[10] = {
    0x3,
    0xf8, OBJ_X_FLIP | 0x2, OBJ_SPRITE_OAM | 0x293,
    0x0, OBJ_X_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x293,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c
};

const u16 sAtomicOAM_Idle_Frame8[13] = {
    0x4,
    0xfc, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x291,
    0x3, OBJ_X_FLIP | 0x1fa, OBJ_SPRITE_OAM | 0x292,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xf7, OBJ_Y_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x293
};

const u16 sAtomicOAM_Idle_Frame9[13] = {
    0x4,
    0xf8, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x293,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0xfb, OBJ_X_FLIP | 0x3, OBJ_SPRITE_OAM | 0x291,
    0x3, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x292
};

const u16 sAtomicOAM_Idle_Frame10[13] = {
    0x4,
    0xfd, OBJ_X_FLIP | 0x1fa, OBJ_SPRITE_OAM | 0x293,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a,
    0xf8, OBJ_X_FLIP | 0x2, OBJ_SPRITE_OAM | 0x291,
    0x3, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x292
};

const u16 sAtomicOAM_Idle_Frame11[13] = {
    0x4,
    0x1, 0x1f7, OBJ_SPRITE_OAM | 0x293,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x218,
    0xf5, 0x1ff, OBJ_SPRITE_OAM | 0x292,
    0xff, 0x2, OBJ_SPRITE_OAM | 0x291
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1215,
    OBJ_SHAPE_HORIZONTAL | 0x20, 0x1f8, OBJ_SPRITE_OAM | 0x1295
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1217,
    0x20, 0x1fc, OBJ_SPRITE_OAM | 0x1297
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x1215,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x1295
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame5[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1217,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1297
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame6[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1215,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x1295
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame7[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1217,
    0x20, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1297
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame9[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1215,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x1295
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame10[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1217,
    0x0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1297
};

const u16 sAtomicElectricityOAM_MovingVertical_Unused_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1258
};

const u16 sAtomicElectricityOAM_MovingVertical_Unused_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1258
};

const u16 sAtomicElectricityOAM_MovingVertical_Unused_Frame2[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1279
};

const u16 sAtomicElectricityOAM_MovingVertical_Unused_Frame3[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x1279
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Frame0[4] = {
    0x1,
    0x0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1280
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Frame1[4] = {
    0x1,
    0x0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1284
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Frame3[4] = {
    0x1,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1280
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Frame5[4] = {
    0x1,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1284
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Frame6[4] = {
    0x1,
    0x0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1288
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Frame7[4] = {
    0x1,
    0x0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x128c
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Frame9[4] = {
    0x1,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1288
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Frame10[4] = {
    0x1,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x128c
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Unused_Frame0[4] = {
    0x1,
    0x10, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x129a
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Unused_Frame1[4] = {
    0x1,
    0x10, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x129a
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Unused_Frame2[4] = {
    0x1,
    0x10, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x12da
};

const u16 sAtomicElectricityOAM_MovingDiagonal_Unused_Frame3[4] = {
    0x1,
    0x10, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x12da
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x12b0,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x12b4
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x12f0,
    0xfc, 0x1f8, OBJ_SPRITE_OAM | 0x12f4
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Frame3[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x12b0,
    OBJ_SHAPE_VERTICAL | 0xfb, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1d8, OBJ_SPRITE_OAM | 0x12b4
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Frame5[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e0, OBJ_SPRITE_OAM | 0x12f0,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1d8, OBJ_SPRITE_OAM | 0x12f4
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Frame6[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x12b0,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x12b4
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Frame7[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x12f0,
    0xfc, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x12f4
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Frame9[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x12b0,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1d8, OBJ_SPRITE_OAM | 0x12b4
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Frame10[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x1e0, OBJ_SPRITE_OAM | 0x12f0,
    0xfc, OBJ_X_FLIP | 0x1d8, OBJ_SPRITE_OAM | 0x12f4
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Unused_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x12b5
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Unused_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x12b5
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Unused_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x12d6
};

const u16 sAtomicElectricityOAM_MovingHorizontal_Unused_Frame3[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x12d6
};

const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x1290
};

const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12dc
};

const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame2[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x1210
};

const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame3[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x120c
};

const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame4[13] = {
    0x4,
    0xe0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1208,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1208,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1208,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1208
};

const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame5[25] = {
    0x8,
    0xdf, OBJ_SIZE_16x16 | 0x11, OBJ_SPRITE_OAM | 0x129a,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x129a,
    0x11, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x11, OBJ_SPRITE_OAM | 0x129a,
    0x11, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x129a,
    0xe0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1204,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1204,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1204,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1204
};

const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame6[25] = {
    0x8,
    0xdb, OBJ_SIZE_16x16 | 0x15, OBJ_SPRITE_OAM | 0x12da,
    0xdb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x12da,
    0x15, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x15, OBJ_SPRITE_OAM | 0x12da,
    0x15, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x12da,
    0xe0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1200,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1200,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1200,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1200
};

const u16 sAtomicElectricityOAM_ExplodingDiagonal_Frame3[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x120c
};

const u16 sAtomicElectricityOAM_ExplodingDiagonal_Frame4[13] = {
    0x4,
    0xe0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1208,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1208,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1208,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1208
};

const u16 sAtomicElectricityOAM_ExplodingDiagonal_Frame5[37] = {
    0xc,
    0xe0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1204,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1204,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1204,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1204,
    OBJ_SHAPE_VERTICAL | 0xd8, 0x1fc, OBJ_SPRITE_OAM | 0x1258,
    0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x1298,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1d8, OBJ_SPRITE_OAM | 0x12b5,
    0xfc, 0x1e8, OBJ_SPRITE_OAM | 0x12b7,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1258,
    0x10, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1298,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x18, OBJ_SPRITE_OAM | 0x12b5,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x10, OBJ_SPRITE_OAM | 0x12b7
};

const u16 sAtomicElectricityOAM_ExplodingDiagonal_Frame6[37] = {
    0xc,
    0xe0, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1200,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1200,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1200,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x1279,
    0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x12b9,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1d0, OBJ_SPRITE_OAM | 0x12d6,
    0xfc, 0x1e0, OBJ_SPRITE_OAM | 0x12d8,
    OBJ_SHAPE_VERTICAL | 0x20, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x1279,
    0x18, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x12b9,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x20, OBJ_SPRITE_OAM | 0x12d6,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x18, OBJ_SPRITE_OAM | 0x12d8
};

const u16 sAtomicElectricityOAM_MovingVertical_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x1204
};

const u16 sAtomicElectricityOAM_Charging_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x125f
};

const u16 sAtomicElectricityOAM_Charging_Frame1[4] = {
    0x1,
    0xfb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12de
};

const u16 sAtomicElectricityOAM_Charging_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x125b
};

const u16 sAtomicElectricityOAM_Charging_Frame4[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x125f
};

const u16 sAtomicElectricityOAM_Charging_Frame5[4] = {
    0x1,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x12de
};

const u16 sAtomicElectricityOAM_Charging_Frame7[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x125b
};

const struct FrameData sAtomicOAM_Idle[13] = {
    sAtomicOAM_Idle_Frame0,
    0x8,
    sAtomicOAM_Idle_Frame1,
    0x8,
    sAtomicOAM_Idle_Frame2,
    0x8,
    sAtomicOAM_Idle_Frame3,
    0x8,
    sAtomicOAM_Idle_Frame4,
    0x8,
    sAtomicOAM_Idle_Frame5,
    0x8,
    sAtomicOAM_Idle_Frame6,
    0x8,
    sAtomicOAM_Idle_Frame7,
    0x8,
    sAtomicOAM_Idle_Frame8,
    0x8,
    sAtomicOAM_Idle_Frame9,
    0x8,
    sAtomicOAM_Idle_Frame10,
    0x8,
    sAtomicOAM_Idle_Frame11,
    0x8,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_MovingVertical[13] = {
    sAtomicElectricityOAM_MovingVertical_Frame0,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame1,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingVertical_Frame3,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingVertical_Frame5,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame6,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame7,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingVertical_Frame9,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame10,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_MovingVertical_Unused[5] = {
    sAtomicElectricityOAM_MovingVertical_Unused_Frame0,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Unused_Frame1,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Unused_Frame2,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Unused_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_MovingDiagonal[13] = {
    sAtomicElectricityOAM_MovingDiagonal_Frame0,
    0x2,
    sAtomicElectricityOAM_MovingDiagonal_Frame1,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingDiagonal_Frame3,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingDiagonal_Frame5,
    0x2,
    sAtomicElectricityOAM_MovingDiagonal_Frame6,
    0x2,
    sAtomicElectricityOAM_MovingDiagonal_Frame7,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingDiagonal_Frame9,
    0x2,
    sAtomicElectricityOAM_MovingDiagonal_Frame10,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_MovingDiagonal_Unused[5] = {
    sAtomicElectricityOAM_MovingDiagonal_Unused_Frame0,
    0x2,
    sAtomicElectricityOAM_MovingDiagonal_Unused_Frame1,
    0x2,
    sAtomicElectricityOAM_MovingDiagonal_Unused_Frame2,
    0x2,
    sAtomicElectricityOAM_MovingDiagonal_Unused_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_MovingHorizontal[13] = {
    sAtomicElectricityOAM_MovingHorizontal_Frame0,
    0x2,
    sAtomicElectricityOAM_MovingHorizontal_Frame1,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingHorizontal_Frame3,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingHorizontal_Frame5,
    0x2,
    sAtomicElectricityOAM_MovingHorizontal_Frame6,
    0x2,
    sAtomicElectricityOAM_MovingHorizontal_Frame7,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    sAtomicElectricityOAM_MovingHorizontal_Frame9,
    0x2,
    sAtomicElectricityOAM_MovingHorizontal_Frame10,
    0x2,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_MovingHorizontal_Unused[5] = {
    sAtomicElectricityOAM_MovingHorizontal_Unused_Frame0,
    0x2,
    sAtomicElectricityOAM_MovingHorizontal_Unused_Frame1,
    0x2,
    sAtomicElectricityOAM_MovingHorizontal_Unused_Frame2,
    0x2,
    sAtomicElectricityOAM_MovingHorizontal_Unused_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_ExplodingNonDiagonal[8] = {
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame0,
    0x3,
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame1,
    0x3,
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame2,
    0x3,
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame3,
    0x3,
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame5,
    0x4,
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame6,
    0x4,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_ExplodingDiagonal[8] = {
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame0,
    0x3,
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame1,
    0x3,
    sAtomicElectricityOAM_ExplodingNonDiagonal_Frame2,
    0x3,
    sAtomicElectricityOAM_ExplodingDiagonal_Frame3,
    0x3,
    sAtomicElectricityOAM_ExplodingDiagonal_Frame4,
    0x3,
    sAtomicElectricityOAM_ExplodingDiagonal_Frame5,
    0x4,
    sAtomicElectricityOAM_ExplodingDiagonal_Frame6,
    0x4,
    NULL,
    0x0
};

const struct FrameData sAtomicElectricityOAM_Charging[12] = {
    sAtomicElectricityOAM_Charging_Frame0,
    0x3,
    sAtomicElectricityOAM_Charging_Frame1,
    0x3,
    sAtomicElectricityOAM_Charging_Frame2,
    0x3,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1E,
    sAtomicElectricityOAM_Charging_Frame4,
    0x3,
    sAtomicElectricityOAM_Charging_Frame5,
    0x3,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1E,
    sAtomicElectricityOAM_Charging_Frame7,
    0x3,
    sAtomicElectricityOAM_MovingVertical_Frame2,
    0x1E,
    sAtomicElectricityOAM_Charging_Frame0,
    0x3,
    sAtomicElectricityOAM_Charging_Frame4,
    0x3,
    NULL,
    0x0
};


void AtomicSmoothMovement(void)
{
    // https://decomp.me/scratch/g2eKp

    u16 dstY;
    u16 dstX;
    u16 speedDivisor;
    u8 hittingSolidX;
    u8 hittingSolidY;
    u16 spriteY;
    u16 spriteX;
    u8 flip;
    u32 limit;

    speedDivisor = 0x2;
    dstY = gArmCannonY;
    dstX = gArmCannonX;
    hittingSolidX = FALSE;
    hittingSolidY = FALSE;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (SpriteUtilGetCollisionAtPosition(spriteY, spriteX + (BLOCK_SIZE / 2)) != COLLISION_AIR)
            hittingSolidX++;
        else
        {
            if (SpriteUtilGetCollisionAtPosition(spriteY + (BLOCK_SIZE / 2), spriteX + (BLOCK_SIZE / 2)) != COLLISION_AIR)
                hittingSolidX++;
            else
            {
                if (SpriteUtilGetCollisionAtPosition(spriteY - (BLOCK_SIZE / 2), spriteX + (BLOCK_SIZE / 2)) != COLLISION_AIR)
                    hittingSolidX++;
            }
        }
    }
    else
    {
        if (SpriteUtilGetCollisionAtPosition(spriteY, spriteX - (BLOCK_SIZE / 2)) != COLLISION_AIR)
            hittingSolidX++;
        else
        {
            if (SpriteUtilGetCollisionAtPosition(spriteY + (BLOCK_SIZE / 2), spriteX - (BLOCK_SIZE / 2)) != COLLISION_AIR)
                hittingSolidX++;
            else
            {
                if (SpriteUtilGetCollisionAtPosition(spriteY - (BLOCK_SIZE / 2), spriteX - (BLOCK_SIZE / 2)) != COLLISION_AIR)
                    hittingSolidX++;
            }
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (SpriteUtilGetCollisionAtPosition(spriteY + (BLOCK_SIZE / 2), spriteX) != COLLISION_AIR)
            hittingSolidY++;
        else
        {
            if (SpriteUtilGetCollisionAtPosition(spriteY + (BLOCK_SIZE / 2), spriteX + (BLOCK_SIZE / 2)) != COLLISION_AIR)
                hittingSolidY++;
            else
            {
                if (SpriteUtilGetCollisionAtPosition(spriteY + (BLOCK_SIZE / 2), spriteX - (BLOCK_SIZE / 2)) != COLLISION_AIR)
                    hittingSolidY++;
            }
        }
    }
    else
    {
        if (SpriteUtilGetCollisionAtPosition(spriteY - (BLOCK_SIZE / 2), spriteX) != COLLISION_AIR)
            hittingSolidY++;
        else
        {
            if (SpriteUtilGetCollisionAtPosition(spriteY - (BLOCK_SIZE / 2), spriteX + (BLOCK_SIZE / 2)) != COLLISION_AIR)
                hittingSolidY++;
            else
            {
                if (SpriteUtilGetCollisionAtPosition(spriteY - (BLOCK_SIZE / 2), spriteX - (BLOCK_SIZE / 2)) != COLLISION_AIR)
                    hittingSolidY++;
            }
        }
    }

    flip = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (!hittingSolidX)
        {
            if (gCurrentSprite.workVariable == 0x0)
            {
                if (gCurrentSprite.xPosition <= (dstX - 0x4))
                {
                    limit = 0x14;
                    if (gCurrentSprite.workVariable2 < limit)
                        gCurrentSprite.workVariable2++;

                    gCurrentSprite.xPosition += (gCurrentSprite.workVariable2 >> speedDivisor);
                }
                else
                    gCurrentSprite.workVariable = gCurrentSprite.workVariable2;
            }
            else
            {
                gCurrentSprite.workVariable--;
                if (gCurrentSprite.workVariable != 0x0)
                    gCurrentSprite.xPosition += (gCurrentSprite.workVariable >> speedDivisor);
                else
                    flip = TRUE;
            }
        }
        else
            flip = TRUE;
    }
    else
    {
        if (!hittingSolidX)
        {
            if (gCurrentSprite.workVariable == 0x0)
            {
                if (gCurrentSprite.xPosition < (dstX + 0x4))
                    gCurrentSprite.workVariable = gCurrentSprite.workVariable2;
                else
                {
                    limit = 0x14;
                    if (gCurrentSprite.workVariable2 < limit)
                        gCurrentSprite.workVariable2++;

                    gCurrentSprite.xPosition -= (gCurrentSprite.workVariable2 >> speedDivisor);
                }
            }
            else
            {
                gCurrentSprite.workVariable--;
                if (gCurrentSprite.workVariable != 0x0)
                    gCurrentSprite.xPosition -= (gCurrentSprite.workVariable >> speedDivisor);
                else
                    flip = TRUE;
            }
        }
        else
            flip = TRUE;
    }

    if (flip)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.workVariable2 = 0x1;
    }

    
    flip = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (!hittingSolidY)
        {
            if (gCurrentSprite.timer == 0x0)
            {
                if (gCurrentSprite.yPosition <= (dstY - 0x4))
                {
                    limit = 0x14;
                    if (gCurrentSprite.arrayOffset < limit)
                        gCurrentSprite.arrayOffset++;

                    gCurrentSprite.yPosition += (gCurrentSprite.arrayOffset >> speedDivisor);
                }
                else
                    gCurrentSprite.timer = gCurrentSprite.arrayOffset;
            }
            else
            {
                gCurrentSprite.timer--;
                if (gCurrentSprite.timer != 0x0)
                    gCurrentSprite.yPosition += (gCurrentSprite.timer >> speedDivisor);
                else
                    flip = TRUE;
            }
        }
        else
            flip = TRUE;
    }
    else
    {
        if (!hittingSolidY)
        {
            if (gCurrentSprite.timer == 0x0)
            {
                if (gCurrentSprite.yPosition < (dstY + 0x4))
                    gCurrentSprite.timer = gCurrentSprite.arrayOffset;
                else
                {
                    limit = 0x14;
                    if (gCurrentSprite.arrayOffset < limit)
                        gCurrentSprite.arrayOffset++;

                    gCurrentSprite.yPosition -= (gCurrentSprite.arrayOffset >> speedDivisor);
                }
            }
            else
            {
                gCurrentSprite.timer--;
                if (gCurrentSprite.timer != 0x0)
                    gCurrentSprite.yPosition -= (gCurrentSprite.timer >> speedDivisor);
                else
                    flip = TRUE;
            }
        }
        else
            flip = TRUE;
    }

    if (flip)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_UNKNOWN2;
        gCurrentSprite.arrayOffset = 0x1;
    }
}

/**
 * @brief 3bb98 | 9c | Updates the direction of an atomic to flee samus if in range
 * 
 */
void AtomicUpdateDirectionToFleeSamus(void)
{
    u16 spriteY;
    u16 spriteX;
    u16 samusY;
    u16 samusX;
    i32 range;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    samusY = gSamusData.yPosition - 0x48;
    samusX = gSamusData.xPosition;

    range = (BLOCK_SIZE * 5);
    // Check samus in range
    if (spriteY > (samusY - range) &&
        spriteY < (samusY + range) &&
        spriteX > (samusX - range) &&
        spriteX < (samusX + range))
    {
        // Set opposite vertical direction
        if (spriteY > samusY)
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;

        // Set opposite horizontal direction
        if (spriteX > samusX)
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;

        // Set moving behavior
        gCurrentSprite.pose = ATOMIC_POSE_MOVE;
        gCurrentSprite.arrayOffset = 0x4;
        gCurrentSprite.timer = 0x0;
    }
}

void AtomicCheckShootElectricity(void)
{

}

/**
 * @brief 3bcec | 90 | Initializes an atomic sprite
 * 
 */
void AtomicInit(void)
{
    if (gDifficulty == DIFF_EASY)
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.drawDistanceTopOffset = 0xC;
        gCurrentSprite.drawDistanceBottomOffset = 0xC;
        gCurrentSprite.drawDistanceHorizontalOffset = 0xC;

        gCurrentSprite.hitboxTopOffset = -0x20;
        gCurrentSprite.hitboxBottomOffset = 0x20;
        gCurrentSprite.hitboxLeftOffset = -0x20;
        gCurrentSprite.hitboxRightOffset = 0x20;

        gCurrentSprite.pOam = sAtomicOAM_Idle;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        gCurrentSprite.pose = ATOMIC_POSE_IDLE_INIT;

        gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
        gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
        gCurrentSprite.oamScaling = gSpriteRNG * 16;
    }
}

/**
 * @brief 3bd7c | 2c | Initializes an atomic to be idle
 * 
 */
void AtomicIdleInit(void)
{
    gCurrentSprite.pose = ATOMIC_POSE_IDLE;
    gCurrentSprite.pOam = sAtomicOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.workVariable2 = 0x0;
}

/**
 * @brief 3bda8 | 90 | Handles an atomic being idle
 * 
 */
void AtomicIdle(void)
{
    u8 offset;
    i32 movement;

    if (gSamusWeaponInfo.chargeCounter >= 0x40)
    {
        // Set chasing if samus has a charged beam
        gCurrentSprite.pose = ATOMIC_POSE_CHASING_SAMUS_INIT;
    }
    else
    {
        // Y movement
        offset = gCurrentSprite.arrayOffset;
        movement = sAtomicIdleYMovement[offset];
        if (movement == SPRITE_ARRAY_TERMINATOR)
        {
            movement = sAtomicIdleYMovement[0]; // 0
            offset = 0x0;
        }
        gCurrentSprite.arrayOffset = offset + 0x1;
        gCurrentSprite.yPosition += movement;

        // X movement
        offset = gCurrentSprite.workVariable2;
        movement = sAtomicIdleXMovement[offset];
        if (movement == SPRITE_ARRAY_TERMINATOR)
        {
            movement = sAtomicIdleXMovement[0]; // 0
            offset = 0x0;
        }
        gCurrentSprite.workVariable2 = offset + 0x1;
        gCurrentSprite.xPosition += movement;

        AtomicUpdateDirectionToFleeSamus();
        AtomicCheckShootElectricity();
    }
}

/**
 * @brief 3be38 | 144 | Handles the atomic moving (fleeing samus)
 * 
 */
void AtomicMove(void)
{
    u16 yPosition;
    u16 xPosition;
    u16 movement;

    if (gSamusWeaponInfo.chargeCounter >= 0x40)
    {
        // Set chasing if samus has a charged beam
        gCurrentSprite.pose = ATOMIC_POSE_CHASING_SAMUS_INIT;
    }
    else
    {
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;

        // Timer for how long to move
        if (++gCurrentSprite.timer > 0x50)
            gCurrentSprite.pose = ATOMIC_POSE_MOVE_BACK_IDLE;
        else
        {
            // Gradually decrease speed
            if (!(gCurrentSprite.timer & 0xF) && gCurrentSprite.arrayOffset != 0x0)
                gCurrentSprite.arrayOffset--;

            movement = gCurrentSprite.arrayOffset;
            if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
            {
                // Move down
                SpriteUtilCheckCollisionAtPosition(yPosition + (BLOCK_SIZE / 2), xPosition);
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    gCurrentSprite.yPosition += movement;
                else
                    gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
            }
            else
            {
                // Move up
                SpriteUtilCheckCollisionAtPosition(yPosition - (BLOCK_SIZE / 2), xPosition);
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    gCurrentSprite.yPosition -= movement;
                else
                    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            }

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                // Move right
                SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + (BLOCK_SIZE / 2));
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    gCurrentSprite.xPosition += movement;
                else
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            }
            else
            {
                // Move left
                SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - (BLOCK_SIZE / 2));
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    gCurrentSprite.xPosition -= movement;
                else
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            }

            AtomicUpdateDirectionToFleeSamus();
            AtomicCheckShootElectricity();
        }
    }
}

/**
 * @brief 3bf7c | 16c | Handles an atomic moving back to an idle position
 * 
 */
void AtomicMaybeMoveBackToIdle(void)
{
    u16 ySpawn;
    u16 xSpawn;
    u16 yPosition;
    u16 xPosition;
    u16 mask;
    u16 movement;

    if (gSamusWeaponInfo.chargeCounter >= 0x40)
    {
        // Set chasing if samus has a charged beam
        gCurrentSprite.pose = ATOMIC_POSE_CHASING_SAMUS_INIT;
    }
    else
    {
        mask = 0xFFFC; // Remove a bit of precision
        ySpawn = gCurrentSprite.yPositionSpawn;
        xSpawn = gCurrentSprite.xPositionSpawn;
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;

        // Set directions
        if ((ySpawn & mask) < (yPosition & mask))
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
        else if ((ySpawn & mask) > (yPosition & mask))
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;

        if ((xSpawn & mask) < (xPosition & mask))
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        else if ((xSpawn & mask) > (xPosition & mask))
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;

        // Move
        movement = 0x2;
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + (BLOCK_SIZE / 2), xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
                gCurrentSprite.yPosition += 0x2;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition - (BLOCK_SIZE / 2), xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
                gCurrentSprite.yPosition -= 0x2;
        }

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + (BLOCK_SIZE / 2));
            if (gPreviousCollisionCheck == COLLISION_AIR)
                gCurrentSprite.xPosition += movement;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - (BLOCK_SIZE / 2));
            if (gPreviousCollisionCheck == COLLISION_AIR)
                gCurrentSprite.xPosition -= movement;
        }

        if ((gCurrentSprite.yPosition & mask) == (ySpawn & mask) && (gCurrentSprite.xPosition & mask) == (xSpawn & mask))
        {
            // Made it to spawn position, set idle
            gCurrentSprite.pose = ATOMIC_POSE_IDLE_INIT;
        }
        else
        {
            AtomicUpdateDirectionToFleeSamus();
            AtomicCheckShootElectricity();
        }
    }
}

/**
 * @brief 3c0e8 | 30 | Initializes an atomic to be chasing samus
 * 
 */
void AtomicChasingSamusInit(void)
{
    gCurrentSprite.pose = ATOMIC_POSE_CHASING_SAMUS;
    gCurrentSprite.absolutePaletteRow = 0x0;
    gCurrentSprite.paletteRow = 0x0;
    gCurrentSprite.workVariable = 0x0;
    gCurrentSprite.workVariable2 = 0x1;
    gCurrentSprite.timer = 0x0;
    gCurrentSprite.arrayOffset = 0x1;
}

void AtomicChaseSamus(void)
{
    if (gSamusWeaponInfo.chargeCounter == 0x0)
    {
        gCurrentSprite.pose = ATOMIC_POSE_IDLE_INIT;
        if (gCurrentSprite.oamScaling == 0x0)
        {
            gCurrentSprite.workVariable = 0x0;
            gCurrentSprite.oamRotation = 0x1;
        }
    }
    else
        AtomicSmoothMovement();
}

/**
 * @brief 3c150 | 30 | Checks if the sprite in the provided RAM slot is an atomic and is alive
 * 
 * @param ramSlot RAM slot
 * @return u8 1 if alive, 0 otherwise
 */
u8 AtomicElectricityCheckAtomicDead(u8 ramSlot)
{
    if (!(gSpriteData[ramSlot].status & SPRITE_STATUS_EXISTS) || gSpriteData[ramSlot].spriteID != PSPRITE_ATOMIC)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief 3c180 | 7c | Initializes an atomic electricity sprite
 * 
 */
void AtomicElectriciytInit(void)
{
    u8 checks;

    checks = AtomicElectricityCheckAtomicDead(gCurrentSprite.primarySpriteRAMSlot);
    if (checks)
        gCurrentSprite.status = 0x0; // Kill if atomic is dead
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        gCurrentSprite.drawDistanceTopOffset = 0x30;
        gCurrentSprite.drawDistanceBottomOffset = 0x30;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x30;

        gCurrentSprite.hitboxTopOffset = -0x4;
        gCurrentSprite.hitboxBottomOffset = 0x4;
        gCurrentSprite.hitboxLeftOffset = -0x4;
        gCurrentSprite.hitboxRightOffset = 0x4;

        gCurrentSprite.pOam = sAtomicElectricityOAM_Charging;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.drawOrder = 0x3;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = ATOMIC_ELECTRICITY_POSE_SPAWN;
    }
}

/**
 * @brief 3c1fc | 1ac | 
 * 
 */
void AtomicElectricitySpawn(void)
{
    u8 check;
    u8 ramSlot;
    u16 spriteY;
    u16 spriteX;
    u16 samusY;
    u16 samusX;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    check = AtomicElectricityCheckAtomicDead(ramSlot);
    if (check)
    {
        gCurrentSprite.status = 0x0;
        return;
    }
    
    // Sync position
    gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
    gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;
    if (gSpriteData[ramSlot].oamScaling == 0xC8)
    {
        // Charging done, set moving behavior
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x261);

        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.samusCollision = SSC_ATOMIC_DISCHARGE;
        gCurrentSprite.pose = ATOMIC_ELECTRICITY_POSE_MOVE;

        spriteY = gCurrentSprite.yPosition;
        spriteX = gCurrentSprite.xPosition;
        samusY = gSamusData.yPosition - 0x48;
        samusX = gSamusData.xPosition;

        // Set direction
        if (spriteX <= samusX)
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;

        if (spriteY > samusY)
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
        else
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;

        if ((spriteY + BLOCK_SIZE) > samusY && (spriteY - BLOCK_SIZE) < samusY)
        {
            // Shooting horizontally
            gCurrentSprite.pOam = sAtomicElectricityOAM_MovingHorizontal;
            gCurrentSprite.workVariable = 0x1; // Direction
            gCurrentSprite.hitboxTopOffset = -0x1C;
            gCurrentSprite.hitboxBottomOffset = 0x1C;
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            {
                gCurrentSprite.hitboxLeftOffset = 0x0;
                gCurrentSprite.hitboxRightOffset = 0xA0;
            }
            else
            {
                gCurrentSprite.hitboxLeftOffset = -0xA0;
                gCurrentSprite.hitboxRightOffset = 0x0;
            }
        }
        else if ((spriteX + BLOCK_SIZE) > samusX && (spriteX - BLOCK_SIZE) < samusX)
        {
            // Shooting vertically
            gCurrentSprite.pOam = sAtomicElectricityOAM_MovingVertical;
            gCurrentSprite.workVariable = 0x2; // Direction
            gCurrentSprite.hitboxLeftOffset = -0x1C;
            gCurrentSprite.hitboxRightOffset = 0x1C;
            if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
            {
                gCurrentSprite.hitboxTopOffset = 0x0;
                gCurrentSprite.hitboxBottomOffset = 0xA0;
            }
            else
            {
                gCurrentSprite.hitboxTopOffset = -0xA0;
                gCurrentSprite.hitboxBottomOffset = 0x0;
            }
        }
        else
        {
            // Shooting diagonally
            gCurrentSprite.pOam = sAtomicElectricityOAM_MovingDiagonal;
            gCurrentSprite.workVariable = 0x0; // Direction

            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            {
                gCurrentSprite.hitboxLeftOffset = 0x20;
                gCurrentSprite.hitboxRightOffset = 0x60;
            }
            else
            {
                gCurrentSprite.hitboxLeftOffset = -0x60;
                gCurrentSprite.hitboxRightOffset = -0x20;
            }

            if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
            {
                gCurrentSprite.hitboxTopOffset = 0x60;
                gCurrentSprite.hitboxBottomOffset = 0x20;
            }
            else
            {
                gCurrentSprite.hitboxTopOffset = -0x20;
                gCurrentSprite.hitboxBottomOffset = -0x60;
            }
        }
    }
}

/**
 * @brief 3c3a8 | c8 | Handles an atomic electricity moving
 * 
 */
void AtomicElectricityMove(void)
{
    u16 speed;

    speed = 0x14;
    // Check move Y
    if (!(gCurrentSprite.workVariable & 0x1))
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
            gCurrentSprite.yPosition += speed;
        else
            gCurrentSprite.yPosition -= speed;
    }

    // Check move X
    if (!(gCurrentSprite.workVariable & 0x2))
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            gCurrentSprite.xPosition += speed;
        else
            gCurrentSprite.xPosition -= speed;
    }

    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
    {
        // Colliding with solid, set exploding behavior
        gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
        gCurrentSprite.pose = ATOMIC_ELECTRICITY_POSE_EXPLODING;

        gCurrentSprite.hitboxTopOffset = -0x60;
        gCurrentSprite.hitboxBottomOffset = 0x60;
        gCurrentSprite.hitboxLeftOffset = -0x60;
        gCurrentSprite.hitboxRightOffset = 0x60;

        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        if (gCurrentSprite.workVariable != 0x0)
            gCurrentSprite.pOam = sAtomicElectricityOAM_ExplodingNonDiagonal;
        else
            gCurrentSprite.pOam = sAtomicElectricityOAM_ExplodingDiagonal;

        SoundPlay(0x262);
    }
}

/**
 * @brief 3c470 | 54 | Handles an atomic discharge exploding
 * 
 */
void AtomicElectricityExploding(void)
{
    if (gCurrentSprite.currentAnimationFrame < 0x4)
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.hitboxTopOffset = -0x10;
        gCurrentSprite.hitboxBottomOffset = 0x10;
        gCurrentSprite.hitboxLeftOffset = -0x10;
        gCurrentSprite.hitboxRightOffset = 0x10;
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        gCurrentSprite.pOam = sAtomicElectricityOAM_Charging;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 3c4c4 | 18 | Checks if the on ground animation ended
 * 
 */
void AtomicElectricityCheckOnGroundAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0; // Kill sprite
}

/**
 * @brief 3c4dc | 150 | Atomic AI
 * 
 */
void Atomic(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x263);
    }

    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;

        switch (gCurrentSprite.pose)
        {
            case 0x0:
                AtomicInit();
                break;

            case ATOMIC_POSE_IDLE_INIT:
                AtomicIdleInit();
                break;

            case ATOMIC_POSE_IDLE:
                AtomicIdle();
                break;

            case ATOMIC_POSE_MOVE:
                AtomicMove();
                break;

            case ATOMIC_POSE_MOVE_BACK_IDLE:
                AtomicMaybeMoveBackToIdle();
                break;

            case ATOMIC_POSE_CHASING_SAMUS_INIT:
                AtomicChasingSamusInit();

            case ATOMIC_POSE_CHASING_SAMUS:
                AtomicChaseSamus();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
        }
    }
}

/**
 * @brief 3c62c | d8 | Atomic electricity AI
 * 
 */
void AtomicElectricity(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            AtomicElectriciytInit();
            break;

        case ATOMIC_ELECTRICITY_POSE_SPAWN:
            AtomicElectricitySpawn();
            break;

        case ATOMIC_ELECTRICITY_POSE_MOVE:
            AtomicElectricityMove();
            break;

        case ATOMIC_ELECTRICITY_POSE_EXPLODING:
            AtomicElectricityExploding();
            break;

        case ATOMIC_ELECTRICITY_POSE_ON_GROUND:
            AtomicElectricityCheckOnGroundAnimEnded();
    }
}