#include "imago_cocoon.h"
#include "../../data/data.h"
#include "../globals.h"

const i16 sImagoCocoonMultiSpriteData_Idle_Frame0[30] = {
    3, 320, 0,
    5, 104, -68,
    6, 56, 68,
    0, 0, 0,
    11, 320, 0,
    4, 320, 0,
    8, 72, 128,
    9, 64, -116,
    10, 68, 52,
    7, 76, -40
};

const i16 sImagoCocoonMultiSpriteData_Idle_Frame1[30] = {
    3, 316, 0,
    5, 104, -68,
    6, 56, 68,
    0, 0, 0,
    11, 316, 0,
    4, 316, 0,
    8, 72, 128,
    9, 64, -116,
    10, 68, 52,
    7, 76, -40
};

const i16 sImagoCocoonMultiSpriteData_Dying_Frame0[30] = {
    3, 312, 0,
    5, 104, -68,
    6, 56, 68,
    1, 0, 0,
    11, 312, 0,
    4, 312, 0,
    8, 72, 128,
    9, 64, -116,
    10, 68, 52,
    7, 76, -40
};

const i16 sImagoCocoonMultiSpriteData_Dying_Frame1[30] = {
    3, 316, 0,
    5, 104, -68,
    6, 56, 68,
    1, 0, 0,
    11, 316, 0,
    4, 316, 0,
    8, 72, 128,
    9, 64, -116,
    10, 68, 52,
    7, 76, -40
};

const i16 sImagoCocoonMultiSpriteData_Dying_Frame3[30] = {
    3, 324, 0,
    5, 104, -68,
    6, 56, 68,
    1, 0, 0,
    11, 324, 0,
    4, 324, 0,
    8, 72, 128,
    9, 64, -116,
    10, 68, 52,
    7, 76, -40
};

const i16 sImagoCocoonMultiSpriteData_Dying_Frame4[30] = {
    3, 328, 0,
    5, 104, -68,
    6, 56, 68,
    1, 0, 0,
    11, 328, 0,
    4, 328, 0,
    8, 72, 128,
    9, 64, -116,
    10, 68, 52,
    7, 76, -40
};

const i16 sImagoCocoonMultiSpriteData_Dying_Frame5[30] = {
    3, 332, 0,
    5, 104, -68,
    6, 56, 68,
    1, 0, 0,
    11, 332, 0,
    4, 332, 0,
    8, 72, 128,
    9, 64, -116,
    10, 68, 52,
    7, 76, -40
};

const i16 sImagoCocoonMultiSpriteData_Dying_Frame6[30] = {
    3, 340, 0,
    5, 104, -68,
    6, 56, 68,
    1, 0, 0,
    11, 340, 0,
    4, 340, 0,
    8, 72, 128,
    9, 64, -116,
    10, 68, 52,
    7, 76, -40
};

const i16 sImagoCocoonMultiSpriteData_Dying_Frame7[30] = {
    3, 368, 0,
    5, 104, -68,
    6, 56, 68,
    1, 0, 0,
    11, 368, 0,
    4, 368, 0,
    8, 72, 128,
    9, 64, -116,
    10, 68, 52,
    7, 76, -40
};

const i16 sImagoCocoonMultiSpriteData_Dying_Frame8[30] = {
    3, 388, 0,
    5, 104, -68,
    6, 56, 68,
    1, 0, 0,
    11, 388, 0,
    4, 388, 0,
    8, 72, 128,
    9, 64, -116,
    10, 68, 52,
    7, 76, -40
};

const struct FrameData sImagoCocoonMultiSpriteData_Idle[5] = {
    sImagoCocoonMultiSpriteData_Idle_Frame0,
    0x20,
    sImagoCocoonMultiSpriteData_Idle_Frame1,
    0x80,
    sImagoCocoonMultiSpriteData_Idle_Frame0,
    0x80,
    sImagoCocoonMultiSpriteData_Idle_Frame1,
    0x40,
    NULL,
    0x0
};

const struct FrameData sImagoCocoonMultiSpriteData_Dying[10] = {
    sImagoCocoonMultiSpriteData_Dying_Frame0,
    0x20,
    sImagoCocoonMultiSpriteData_Dying_Frame1,
    0x20,
    sImagoCocoonMultiSpriteData_Dying_Frame0,
    0x16,
    sImagoCocoonMultiSpriteData_Dying_Frame3,
    0x14,
    sImagoCocoonMultiSpriteData_Dying_Frame4,
    0x10,
    sImagoCocoonMultiSpriteData_Dying_Frame5,
    0xC,
    sImagoCocoonMultiSpriteData_Dying_Frame6,
    0x8,
    sImagoCocoonMultiSpriteData_Dying_Frame7,
    0x6,
    sImagoCocoonMultiSpriteData_Dying_Frame8,
    0xFF,
    NULL,
    0x0
};

const i16 sImagoCocoon_ArrayUnused1[36] = {
    -8, -8, -6, -6, -5, -5, -4, -4, -3, -3, -2, -2, -1,
    -1, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 14, 16, 18, SPRITE_ARRAY_TERMINATOR
};

const i16 sImagoCocoon_ArrayUnused2[48] = {
    0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 4, 4, 4, 4, 2, 2, 2, 2,
    1, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0,
    0, 0, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2
};

const u32 sImagoCocoonGFX[1758];
const u16 sImagoCocoonPAL[96];

const u16 sImagoCocoonOAM_Idle_Frame0[4] = {
    0x1,
    0xd0, OBJ_SIZE_64x64 | 0x1e1, OBJ_SPRITE_OAM | 0x1218
};

const u16 sImagoCocoonOAM_Idle_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1e1, OBJ_SPRITE_OAM | 0x12b8,
    0xcf, OBJ_SIZE_64x64 | 0x1e1, OBJ_SPRITE_OAM | 0x1218
};

const u16 sImagoCocoonOAM_Static_Frame0[37] = {
    0xc,
    0xd0, 0x2, OBJ_SPRITE_OAM | 0x2229,
    0xda, 0x16, OBJ_SPRITE_OAM | 0x2229,
    0xd0, 0x13, OBJ_SPRITE_OAM | 0x220b,
    0xde, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x2200,
    0xd8, 0x1e4, OBJ_SPRITE_OAM | 0x1229,
    OBJ_SHAPE_VERTICAL | 0xce, 0x17, OBJ_SPRITE_OAM | 0x1229,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1dc, OBJ_SPRITE_OAM | 0x122c,
    0xd0, OBJ_SIZE_64x64 | 0x1e1, OBJ_SPRITE_OAM | 0x3218,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1212,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x1212,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x12cb,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0xb, OBJ_SPRITE_OAM | 0x12cd
};

const u16 sImagoCocoonOAM_CeilingVineMotionless_Frame0[19] = {
    0x6,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x520e,
    0x8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x524e,
    0x18, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x528e,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x520d,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x5290,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x5290
};

const u16 sImagoCocoonOAM_CeilingVineMotionless_Frame1[19] = {
    0x6,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x520e,
    0x8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x524e,
    0x17, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x528e,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x520d,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x5290,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x5290
};

const u16 sImagoCocoonOAM_CeilingVineMoving_Frame2[22] = {
    0x7,
    0xa, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x5210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x520e,
    0x8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x524e,
    0x19, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x528e,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x520d,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x5290,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x5290
};

const u16 sImagoCocoonOAM_CeilingVineMoving_Frame3[22] = {
    0x7,
    0xa, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x5210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x520e,
    0x8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x524e,
    0x1a, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x528e,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x520d,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x5290,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x5290
};

const u16 sImagoCocoonOAM_CeilingVineMoving_Frame4[22] = {
    0x7,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x520e,
    0xe, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x5250,
    0x8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x524e,
    0x1c, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x528e,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x520d,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x5290,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x5290
};

const u16 sImagoCocoonOAM_CeilingVineMoving_Frame5[25] = {
    0x8,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x520e,
    0xe, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x5250,
    0x8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x524e,
    0x1e, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x528e,
    0x12, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x539e,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x520d,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x5290,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x5290
};

const u16 sImagoCocoonOAM_CeilingVineMoving_Frame6[25] = {
    0x8,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x520e,
    0xe, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x5250,
    0x8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x524e,
    0x21, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x528e,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x520d,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x5290,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x5290,
    0x16, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x52d2
};

const u16 sImagoCocoonOAM_CeilingVineMoving_Frame7[25] = {
    0x8,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x520e,
    0xe, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x5250,
    0x8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x524e,
    0x25, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x528e,
    0x16, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x52d2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x520d,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x5290,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x5290
};

const u16 sImagoCocoonOAM_CeilingVineMoving_Frame8[10] = {
    0x3,
    0x28, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x528e,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x5233,
    0x10, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x5273
};

const u16 sImagoCocoonOAM_CeilingVineMoving_Frame_Unused[10] = {
    0x3,
    0x3c, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x528e,
    OBJ_SHAPE_VERTICAL | 0x2c, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x5233,
    0x24, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x5273
};

const u16 sImagoCocoonOAM_CeilingVineBroken_Frame0[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0x14, 0x1fd, OBJ_SPRITE_OAM | 0x5252,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x520e,
    0x8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x524e,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x520d,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x5290,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x5290
};

const u16 sImagoCocoonOAM_DecorativeVinesLeft_Frame0[22] = {
    0x7,
    0xd0, 0x2, OBJ_SPRITE_OAM | 0x229,
    0xda, 0x16, OBJ_SPRITE_OAM | 0x2229,
    0xd0, 0x13, OBJ_SPRITE_OAM | 0x20b,
    0xde, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x200,
    0xcd, 0x1f4, OBJ_SPRITE_OAM | 0x2ef,
    OBJ_SHAPE_VERTICAL | 0xd4, 0x1f4, OBJ_SPRITE_OAM | 0x309,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1df, OBJ_SPRITE_OAM | 0x5212
};

const u16 sImagoCocoonOAM_DecorativeVinesLeft_Frame1[28] = {
    0x9,
    0xd0, 0x2, OBJ_SPRITE_OAM | 0x220b,
    0xda, 0x16, OBJ_SPRITE_OAM | 0x2ef,
    0xd0, 0x13, OBJ_SPRITE_OAM | 0x20b,
    0xe3, 0x1ec, OBJ_SPRITE_OAM | 0x22f0,
    0xde, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x2200,
    0xcd, 0x1f5, OBJ_SPRITE_OAM | 0x2ee,
    OBJ_SHAPE_VERTICAL | 0xd4, 0x1f4, OBJ_SPRITE_OAM | 0x308,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1df, OBJ_SPRITE_OAM | 0x5212,
    0xdf, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x200
};

const u16 sImagoCocoonOAM_DecorativeVinesLeft_Frame2[34] = {
    0xb,
    0xd0, 0x2, OBJ_SPRITE_OAM | 0x220b,
    0xd0, 0x13, OBJ_SPRITE_OAM | 0x20b,
    0xe3, 0x1ec, OBJ_SPRITE_OAM | 0x2f1,
    0xde, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x200,
    0xcd, 0x1f4, OBJ_SPRITE_OAM | 0x2ef,
    OBJ_SHAPE_VERTICAL | 0xd4, 0x1f4, OBJ_SPRITE_OAM | 0x2ca,
    0xd5, OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1e7, OBJ_SPRITE_OAM | 0x5213,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1e0, OBJ_SPRITE_OAM | 0x5252,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1e0, OBJ_SPRITE_OAM | 0x5212,
    0xdf, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x200
};

const u16 sImagoCocoonOAM_DecorativeVinesLeft_Frame3[34] = {
    0xb,
    0xd0, 0x2, OBJ_SPRITE_OAM | 0x220b,
    0xd0, 0x13, OBJ_SPRITE_OAM | 0x229,
    0xe3, 0x1ec, OBJ_SPRITE_OAM | 0x2ce,
    0xde, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x200,
    0xcd, 0x1f3, OBJ_SPRITE_OAM | 0x2ee,
    OBJ_SHAPE_VERTICAL | 0xd4, 0x1f4, OBJ_SPRITE_OAM | 0x30a,
    0xda, 0x17, OBJ_SPRITE_OAM | 0x2f0,
    0xd5, OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1df, OBJ_SPRITE_OAM | 0x5212,
    0x9, 0x1e7, OBJ_SPRITE_OAM | 0x5273,
    0xdf, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x200
};

const u16 sImagoCocoonOAM_DecorativeVinesLeft_Frame4[28] = {
    0x9,
    0xd0, 0x2, OBJ_SPRITE_OAM | 0x220b,
    0xda, 0x16, OBJ_SPRITE_OAM | 0x2ef,
    0xd0, 0x13, OBJ_SPRITE_OAM | 0x220b,
    0xe3, 0x1ec, OBJ_SPRITE_OAM | 0x2f1,
    0xde, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x200,
    0xcd, 0x1f4, OBJ_SPRITE_OAM | 0x2ef,
    OBJ_SHAPE_VERTICAL | 0xd4, 0x1f4, OBJ_SPRITE_OAM | 0x309,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1df, OBJ_SPRITE_OAM | 0x5212,
    0xdf, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x200
};

const u16 sImagoCocoonOAM_DecorativeVinesRight_Frame0[25] = {
    0x8,
    0xd8, OBJ_X_FLIP | 0x1e4, OBJ_SPRITE_OAM | 0x2229,
    OBJ_SHAPE_VERTICAL | 0xcd, OBJ_X_FLIP | 0x17, OBJ_SPRITE_OAM | 0x20b,
    0xd9, 0x1db, OBJ_SPRITE_OAM | 0x22cf,
    OBJ_SHAPE_VERTICAL | 0xd9, 0x1db, OBJ_SPRITE_OAM | 0x222c,
    OBJ_SHAPE_VERTICAL | 0xe9, 0x1dc, OBJ_SPRITE_OAM | 0x226c,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x5212,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_SIZE_16x32 | 0x1fd, OBJ_SPRITE_OAM | 0x52cb,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_SIZE_8x32 | 0xd, OBJ_SPRITE_OAM | 0x52cd
};

const u16 sImagoCocoonOAM_DecorativeVinesRight_Frame1[22] = {
    0x7,
    0xd8, OBJ_X_FLIP | 0x1e5, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_VERTICAL | 0xcd, OBJ_X_FLIP | 0x16, OBJ_SPRITE_OAM | 0x2229,
    0xd8, 0x1dc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1dc, OBJ_SPRITE_OAM | 0x22c,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x5212,
    OBJ_SHAPE_VERTICAL | 0xf5, OBJ_SIZE_16x32 | 0x1fd, OBJ_SPRITE_OAM | 0x52cb,
    OBJ_SHAPE_VERTICAL | 0xf5, OBJ_SIZE_8x32 | 0xd, OBJ_SPRITE_OAM | 0x52cd
};

const u16 sImagoCocoonOAM_DecorativeVinesRight_Frame2[22] = {
    0x7,
    0xd8, OBJ_X_FLIP | 0x1e5, OBJ_SPRITE_OAM | 0x2d1,
    OBJ_SHAPE_VERTICAL | 0xcc, OBJ_X_FLIP | 0x16, OBJ_SPRITE_OAM | 0x229,
    0xd9, 0x1dc, OBJ_SPRITE_OAM | 0x2cf,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_SIZE_8x32 | 0x1dc, OBJ_SPRITE_OAM | 0x22c,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x5212,
    OBJ_SHAPE_VERTICAL | 0xf5, OBJ_SIZE_16x32 | 0x1fd, OBJ_SPRITE_OAM | 0x52cb,
    OBJ_SHAPE_VERTICAL | 0xf5, OBJ_SIZE_8x32 | 0xd, OBJ_SPRITE_OAM | 0x52cd
};

const u16 sImagoCocoonOAM_DecorativeVinesRight_Frame3[19] = {
    0x6,
    0xd8, OBJ_X_FLIP | 0x1e5, OBJ_SPRITE_OAM | 0x2cf,
    OBJ_SHAPE_VERTICAL | 0xcd, OBJ_X_FLIP | 0x17, OBJ_SPRITE_OAM | 0x229,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1dc, OBJ_SPRITE_OAM | 0x222c,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x5212,
    OBJ_SHAPE_VERTICAL | 0xf5, OBJ_SIZE_16x32 | 0x1fd, OBJ_SPRITE_OAM | 0x52cb,
    OBJ_SHAPE_VERTICAL | 0xf5, OBJ_SIZE_8x32 | 0xd, OBJ_SPRITE_OAM | 0x52cd
};

const u16 sImagoCocoonOAM_DecorativeVinesRight_Frame4[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xcd, OBJ_X_FLIP | 0x17, OBJ_SPRITE_OAM | 0x229,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_SIZE_8x32 | 0x1dc, OBJ_SPRITE_OAM | 0x222c,
    0xd8, OBJ_X_FLIP | 0x1e5, OBJ_SPRITE_OAM | 0x1229,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x5212,
    OBJ_SHAPE_VERTICAL | 0xf5, OBJ_SIZE_16x32 | 0x1fd, OBJ_SPRITE_OAM | 0x52cb,
    OBJ_SHAPE_VERTICAL | 0xf5, OBJ_SIZE_8x32 | 0xd, OBJ_SPRITE_OAM | 0x52cd
};

const u16 sImagoCocoonSporeOAM_Spawning_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x204
};

const u16 sImagoCocoonSporeOAM_Spawning_Frame1[10] = {
    0x3,
    0xfb, 0x1fb, OBJ_SPRITE_OAM | 0x204,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x204,
    0xfd, 0x1fc, OBJ_SPRITE_OAM | 0x204
};

const u16 sImagoCocoonSporeOAM_Spawning_Frame2[16] = {
    0x5,
    0xfd, 0x1f9, OBJ_SPRITE_OAM | 0x204,
    0xfb, 0x1fd, OBJ_SPRITE_OAM | 0x205,
    0xf9, 0x1ff, OBJ_SPRITE_OAM | 0x204,
    0xfe, 0x1fe, OBJ_SPRITE_OAM | 0x204,
    0xf8, 0x1fa, OBJ_SPRITE_OAM | 0x204
};

const u16 sImagoCocoonSporeOAM_Spawning_Frame3[16] = {
    0x5,
    0xfd, OBJ_X_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x205,
    0xfc, 0x1fb, OBJ_SPRITE_OAM | 0x206,
    0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xff, 0x1, OBJ_SPRITE_OAM | 0x205,
    0xf8, 0x0, OBJ_SPRITE_OAM | 0x204
};

const u16 sImagoCocoonSporeOAM_Nest_Frame0[22] = {
    0x7,
    0xf5, 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xf7, 0x1, OBJ_SPRITE_OAM | 0x205,
    0xfb, 0x4, OBJ_SPRITE_OAM | 0x204,
    0xff, OBJ_X_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x205,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x206,
    0x1, 0x0, OBJ_SPRITE_OAM | 0x204,
    0xfb, 0x1f6, OBJ_SPRITE_OAM | 0x204
};

const u16 sImagoCocoonSporeOAM_Nest_Frame1[28] = {
    0x9,
    0xfb, 0x6, OBJ_SPRITE_OAM | 0x205,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x207,
    0xf8, 0x0, OBJ_SPRITE_OAM | 0x206,
    0x0, 0x0, OBJ_SPRITE_OAM | 0x206,
    0xff, 0x1f9, OBJ_SPRITE_OAM | 0x206,
    0xf9, 0x1f7, OBJ_SPRITE_OAM | 0x206,
    0x4, 0x1fc, OBJ_SPRITE_OAM | 0x204,
    0xfc, 0x1f4, OBJ_SPRITE_OAM | 0x204,
    0xf3, 0x1fc, OBJ_SPRITE_OAM | 0x204
};

const u16 sImagoCocoonSporeOAM_Nest_Frame2[28] = {
    0x9,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x207,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f9, OBJ_SPRITE_OAM | 0x206,
    0xf9, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fa, OBJ_SPRITE_OAM | 0x206,
    0xf9, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x206,
    0xff, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x206,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x205,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x204,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x5, OBJ_SPRITE_OAM | 0x204,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x204
};

const u16 sImagoCocoonSporeOAM_Moving_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x207
};

const u16 sImagoCocoonSporeOAM_Moving_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x206
};

const u16 sImagoCocoonSporeOAM_Moving_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x207
};

const u16 sImagoCocoonVineOAM_LeftMiddle_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x246,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x30e
};

const u16 sImagoCocoonVineOAM_LeftMiddle_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x30e
};

const u16 sImagoCocoonVineOAM_LeftMiddle_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f9, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x30e
};

const u16 sImagoCocoonVineOAM_LeftMiddle_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x30e
};

const u16 sImagoCocoonVineOAM_Unused_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f5, OBJ_SPRITE_OAM | 0x246,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_X_FLIP | 0x1f9, OBJ_SPRITE_OAM | 0x30e,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x30e
};

const u16 sImagoCocoonVineOAM_Unused_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_X_FLIP | 0x1f9, OBJ_SPRITE_OAM | 0x30e,
    OBJ_SHAPE_VERTICAL | 0xe9, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x30e
};

const u16 sImagoCocoonVineOAM_Unused_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x30e,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x30e
};

const u16 sImagoCocoonVineOAM_Unused_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_X_FLIP | 0x1f9, OBJ_SPRITE_OAM | 0x30e,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x30e
};

const u16 sImagoCocoonVineOAM_RightMiddle_Frame0[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x24a,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fd, OBJ_SPRITE_OAM | 0x248,
    0x14, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x2c8,
    0xe8, OBJ_Y_FLIP | 0x4, OBJ_SPRITE_OAM | 0x2c8
};

const u16 sImagoCocoonVineOAM_RightMiddle_Frame1[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x249,
    OBJ_SHAPE_VERTICAL | 0xf5, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fd, OBJ_SPRITE_OAM | 0x248,
    0x15, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x2c8,
    0xe8, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x2c8
};

const u16 sImagoCocoonVineOAM_RightMiddle_Frame2[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x248,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x248,
    0x14, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x2c8,
    0xe8, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x2c8
};

const u16 sImagoCocoonVineOAM_RightMiddle_Frame3[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf5, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x249,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x249,
    0x15, OBJ_X_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x2c8,
    0xe8, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x2c8
};

const u16 sImagoCocoonVineOAM_LeftRight_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1fe, OBJ_SPRITE_OAM | 0x249,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1fa, OBJ_SPRITE_OAM | 0x244
};

const u16 sImagoCocoonVineOAM_LeftRight_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1fd, OBJ_SPRITE_OAM | 0x24a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f9, OBJ_SPRITE_OAM | 0x246
};

const u16 sImagoCocoonVineOAM_LeftRight_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1fe, OBJ_SPRITE_OAM | 0x24b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1fa, OBJ_SPRITE_OAM | 0x240
};

const u16 sImagoCocoonVineOAM_LeftRight_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1fe, OBJ_SPRITE_OAM | 0x248,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f9, OBJ_SPRITE_OAM | 0x246
};

const u16 sImagoCocoonVineOAM_RightRight_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xe, 0x1f8, OBJ_SPRITE_OAM | 0x30e
};

const u16 sImagoCocoonVineOAM_RightRight_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_VERTICAL | 0xe, 0x1f8, OBJ_SPRITE_OAM | 0x30e
};

const u16 sImagoCocoonVineOAM_RightRight_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x246,
    OBJ_SHAPE_VERTICAL | 0xe, 0x1f8, OBJ_SPRITE_OAM | 0x30e
};

const u16 sImagoCocoonVineOAM_RightRight_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_VERTICAL | 0xd, 0x1f9, OBJ_SPRITE_OAM | 0x30e
};

const u16 sImagoCocoonVineOAM_LeftLeft_Frame0[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_SIZE_8x32 | 0x1fd, OBJ_SPRITE_OAM | 0x24a,
    0x5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x300,
    OBJ_SHAPE_VERTICAL | 0xe9, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f1, OBJ_SPRITE_OAM | 0x2c4,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x249,
    OBJ_SHAPE_VERTICAL | 0x14, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x30e
};

const u16 sImagoCocoonVineOAM_LeftLeft_Frame1[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0x1, OBJ_SIZE_8x32 | 0x1fd, OBJ_SPRITE_OAM | 0x24a,
    0x5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x300,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f2, OBJ_SPRITE_OAM | 0x2c6,
    OBJ_SHAPE_VERTICAL | 0xe5, OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x248,
    OBJ_SHAPE_VERTICAL | 0x14, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x30e
};

const u16 sImagoCocoonVineOAM_LeftLeft_Frame2[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xfe, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x24a,
    0x4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x300,
    OBJ_SHAPE_VERTICAL | 0xe9, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f3, OBJ_SPRITE_OAM | 0x2c6,
    OBJ_SHAPE_VERTICAL | 0xe5, OBJ_SIZE_8x32 | 0x1ff, OBJ_SPRITE_OAM | 0x248,
    OBJ_SHAPE_VERTICAL | 0x14, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x30e
};

const u16 sImagoCocoonVineOAM_RightLeft_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x24b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x244
};

const u16 sImagoCocoonVineOAM_RightLeft_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x24a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x246
};

const u16 sImagoCocoonVineOAM_RightLeft_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x249,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x240
};

const u16 sImagoCocoonVineOAM_RightLeft_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x248,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x242
};

const u16 sWingedRipperOAM_TurningAround_Frame2[10] = {
    0x3,
    0xf5, 0x6, OBJ_SPRITE_OAM | 0x431c,
    0xf5, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x4314,
    0xf9, OBJ_Y_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x431c
};

const u16 sWingedRipperOAM_TurningAround_Frame1[10] = {
    0x3,
    0xf5, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x4314,
    0xf6, 0x6, OBJ_SPRITE_OAM | 0x431d,
    0xf6, OBJ_X_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x431d
};

const u16 sWingedRipperOAM_TurningAround_Frame0[10] = {
    0x3,
    0xfd, OBJ_Y_FLIP | 0x6, OBJ_SPRITE_OAM | 0x431c,
    0xf5, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x4314,
    0xfd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x431c
};

const u16 sWingedRipperOAM_Moving_Frame8[7] = {
    0x2,
    0xf6, 0x1ff, OBJ_SPRITE_OAM | 0x431c,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4310
};

const u16 sWingedRipperOAM_Moving_Frame2[7] = {
    0x2,
    0xf6, 0x1ff, OBJ_SPRITE_OAM | 0x431c,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4310
};

const u16 sWingedRipperOAM_Moving_Frame1[10] = {
    0x3,
    0xf7, 0x1ff, OBJ_SPRITE_OAM | 0x431d,
    0xf5, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4316,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4310
};

const u16 sWingedRipperOAM_Moving_Frame0[10] = {
    0x3,
    0xfe, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x431c,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4310,
    0xf5, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4318
};

const u16 sDefeatedImagoCocoonOAM_Frame0[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xdd, 0x1e4, OBJ_SPRITE_OAM | 0x5a08,
    0xdd, 0x1f4, OBJ_SPRITE_OAM | 0x5a0a,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_Y_FLIP | 0x1e4, OBJ_SPRITE_OAM | 0x5a08,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e1, OBJ_SPRITE_OAM | 0x3a54,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e2, OBJ_SPRITE_OAM | 0x3a74,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e1, OBJ_SPRITE_OAM | 0x3a14,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e2, OBJ_SPRITE_OAM | 0x3ab4,
    OBJ_SHAPE_HORIZONTAL | 0xe7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e2, OBJ_SPRITE_OAM | 0x3a94,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e2, OBJ_SPRITE_OAM | 0x3ad4
};

const u16 sDefeatedImagoCocoonOAM_Frame1[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xdc, 0x1e4, OBJ_SPRITE_OAM | 0x5a08,
    0xdc, 0x1f4, OBJ_SPRITE_OAM | 0x5a0a,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_Y_FLIP | 0x1e4, OBJ_SPRITE_OAM | 0x5a08,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e2, OBJ_SPRITE_OAM | 0x3a74,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e2, OBJ_SPRITE_OAM | 0x3a54,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e2, OBJ_SPRITE_OAM | 0x3a14,
    OBJ_SHAPE_HORIZONTAL | 0xe7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e2, OBJ_SPRITE_OAM | 0x3a94,
    OBJ_SHAPE_HORIZONTAL | 0xdf, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e2, OBJ_SPRITE_OAM | 0x3ab4,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e2, OBJ_SPRITE_OAM | 0x3ad4
};

const u16 sDefeatedImagoCocoonOAM_Frame2[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xdc, 0x1e4, OBJ_SPRITE_OAM | 0x5a08,
    0xdc, 0x1f4, OBJ_SPRITE_OAM | 0x5a0a,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_Y_FLIP | 0x1e4, OBJ_SPRITE_OAM | 0x5a08,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e2, OBJ_SPRITE_OAM | 0x3a74,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e2, OBJ_SPRITE_OAM | 0x3a54,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e2, OBJ_SPRITE_OAM | 0x3a14,
    OBJ_SHAPE_HORIZONTAL | 0xe7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e2, OBJ_SPRITE_OAM | 0x3a94,
    OBJ_SHAPE_HORIZONTAL | 0xdf, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1e2, OBJ_SPRITE_OAM | 0x3ab4,
    OBJ_SHAPE_HORIZONTAL | 0xcf, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e2, OBJ_SPRITE_OAM | 0x3ad4
};

const struct FrameData sImagoCocoonOAM_CeilingVineMotionless[5] = {
    sImagoCocoonOAM_CeilingVineMotionless_Frame0,
    0x20,
    sImagoCocoonOAM_CeilingVineMotionless_Frame1,
    0x80,
    sImagoCocoonOAM_CeilingVineMotionless_Frame0,
    0x80,
    sImagoCocoonOAM_CeilingVineMotionless_Frame1,
    0x40,
    NULL,
    0x0    
};

const struct FrameData sImagoCocoonOAM_CeilingVineMoving[10] = {
    sImagoCocoonOAM_CeilingVineMotionless_Frame1,
    0x20,
    sImagoCocoonOAM_CeilingVineMotionless_Frame0,
    0x20,
    sImagoCocoonOAM_CeilingVineMoving_Frame2,
    0x16,
    sImagoCocoonOAM_CeilingVineMoving_Frame3,
    0x14,
    sImagoCocoonOAM_CeilingVineMoving_Frame4,
    0x10,
    sImagoCocoonOAM_CeilingVineMoving_Frame5,
    0xC,
    sImagoCocoonOAM_CeilingVineMoving_Frame6,
    0x8,
    sImagoCocoonOAM_CeilingVineMoving_Frame7,
    0x6,
    sImagoCocoonOAM_CeilingVineMoving_Frame8,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sImagoCocoonOAM_CeilingVineBroken[2] = {
    sImagoCocoonOAM_CeilingVineBroken_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sImagoCocoonOAM_DecorativeVinesLeft[6] = {
    sImagoCocoonOAM_DecorativeVinesLeft_Frame0,
    0xC,
    sImagoCocoonOAM_DecorativeVinesLeft_Frame1,
    0xC,
    sImagoCocoonOAM_DecorativeVinesLeft_Frame2,
    0xC,
    sImagoCocoonOAM_DecorativeVinesLeft_Frame3,
    0xC,
    sImagoCocoonOAM_DecorativeVinesLeft_Frame4,
    0xC,
    NULL,
    0x0
};

const struct FrameData sImagoCocoonOAM_DecorativeVinesRight[6] = {
    sImagoCocoonOAM_DecorativeVinesRight_Frame0,
    0x6,
    sImagoCocoonOAM_DecorativeVinesRight_Frame1,
    0x6,
    sImagoCocoonOAM_DecorativeVinesRight_Frame2,
    0x6,
    sImagoCocoonOAM_DecorativeVinesRight_Frame3,
    0x6,
    sImagoCocoonOAM_DecorativeVinesRight_Frame4,
    0x6,
    NULL,
    0x0
};

const struct FrameData sImagoCocoonVineOAM_LeftMiddle[5] = {
    sImagoCocoonVineOAM_LeftMiddle_Frame0,
    0xC,
    sImagoCocoonVineOAM_LeftMiddle_Frame1,
    0xC,
    sImagoCocoonVineOAM_LeftMiddle_Frame2,
    0xC,
    sImagoCocoonVineOAM_LeftMiddle_Frame3,
    0xC,
    NULL,
    0x0
};

const struct FrameData sImagoCocoonVineOAM_RIghtMiddle[5] = {
    sImagoCocoonVineOAM_RightMiddle_Frame0,
    0x6,
    sImagoCocoonVineOAM_RightMiddle_Frame1,
    0x6,
    sImagoCocoonVineOAM_RightMiddle_Frame2,
    0x6,
    sImagoCocoonVineOAM_RightMiddle_Frame3,
    0x6,
    NULL,
    0x0
};

const struct FrameData sImagoCocoonVineOAM_LeftRight[5] = {
    sImagoCocoonVineOAM_LeftRight_Frame0,
    0x6,
    sImagoCocoonVineOAM_LeftRight_Frame1,
    0x6,
    sImagoCocoonVineOAM_LeftRight_Frame2,
    0x6,
    sImagoCocoonVineOAM_LeftRight_Frame3,
    0x6,
    NULL,
    0x0
};

const struct FrameData sImagoCocoonVineOAM_RightRight[5] = {
    sImagoCocoonVineOAM_RightRight_Frame0,
    0x6,
    sImagoCocoonVineOAM_RightRight_Frame1,
    0x6,
    sImagoCocoonVineOAM_RightRight_Frame2,
    0x6,
    sImagoCocoonVineOAM_RightRight_Frame3,
    0x6,
    NULL,
    0x0
};

const struct FrameData sImagoCocoonVineOAM_LeftLeft[5] = {
    sImagoCocoonVineOAM_LeftLeft_Frame0,
    0xC,
    sImagoCocoonVineOAM_LeftLeft_Frame1,
    0x4,
    sImagoCocoonVineOAM_LeftLeft_Frame2,
    0x2,
    sImagoCocoonVineOAM_LeftLeft_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sImagoCocoonVineOAM_RightLeft[5] = {
    sImagoCocoonVineOAM_RightLeft_Frame0,
    0x10,
    sImagoCocoonVineOAM_RightLeft_Frame1,
    0x10,
    sImagoCocoonVineOAM_RightLeft_Frame2,
    0x10,
    sImagoCocoonVineOAM_RightLeft_Frame3,
    0x10,
    NULL,
    0x0
};

const struct FrameData sImagoCocoonOAM_Idle[5] = {
    sImagoCocoonOAM_Idle_Frame0,
    0x20,
    sImagoCocoonOAM_Idle_Frame1,
    0x80,
    sImagoCocoonOAM_Idle_Frame0,
    80,
    sImagoCocoonOAM_Idle_Frame1,
    0x40,
    NULL,
    0x0
};

const struct FrameData sImagoCocoonOAM_2e0bb0[2] = {
    sImagoCocoonOAM_Idle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sImagoCocoonOAM_Static[2] = {
    sImagoCocoonOAM_Static_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sImagoCocoonSporeOAM_Spawning[5] = {
    sImagoCocoonSporeOAM_Spawning_Frame0,
    0x4,
    sImagoCocoonSporeOAM_Spawning_Frame1,
    0x4,
    sImagoCocoonSporeOAM_Spawning_Frame2,
    0x4,
    sImagoCocoonSporeOAM_Spawning_Frame3,
    0x4,
    NULL,
    0x0
};

const struct FrameData sImagoCocoonSpore_Nest[4] = {
    sImagoCocoonSporeOAM_Nest_Frame0,
    0x4,
    sImagoCocoonSporeOAM_Nest_Frame1,
    0x4,
    sImagoCocoonSporeOAM_Nest_Frame2,
    0x4,
    NULL,
    0x0
};

const struct FrameData sImagoCocoonSpore_Moving[4] = {
    sImagoCocoonSporeOAM_Moving_Frame0,
    0x2,
    sImagoCocoonSporeOAM_Moving_Frame1,
    0x2,
    sImagoCocoonSporeOAM_Moving_Frame2,
    0x1,
    NULL,
    0x0
};

const struct FrameData sImagoCocoonSpore_Exploding[5] = {
    sImagoCocoonSporeOAM_Spawning_Frame3,
    0x4,
    sImagoCocoonSporeOAM_Spawning_Frame2,
    0x3,
    sImagoCocoonSporeOAM_Spawning_Frame1,
    0x2,
    sImagoCocoonSporeOAM_Spawning_Frame0,
    0x2,
    NULL,
    0x0
};

const struct FrameData sWingedRipperOAM_Moving[10] = {
    sWingedRipperOAM_Moving_Frame0,
    0x1,
    sWingedRipperOAM_Moving_Frame1,
    0x2,
    sWingedRipperOAM_Moving_Frame2,
    0x1,
    sWingedRipperOAM_Moving_Frame0,
    0x2,
    sWingedRipperOAM_Moving_Frame1,
    0x3,
    sWingedRipperOAM_Moving_Frame2,
    0x2,
    sWingedRipperOAM_Moving_Frame0,
    0x3,
    sWingedRipperOAM_Moving_Frame1,
    0x2,
    sWingedRipperOAM_Moving_Frame8,
    0x1,
    NULL,
    0x0
};

const struct FrameData sWingedRipperOAM_TurningAround[10] = {
    sWingedRipperOAM_TurningAround_Frame0,
    0x1,
    sWingedRipperOAM_TurningAround_Frame1,
    0x2,
    sWingedRipperOAM_TurningAround_Frame2,
    0x1,
    sWingedRipperOAM_TurningAround_Frame0,
    0x1,
    sWingedRipperOAM_TurningAround_Frame1,
    0x2,
    sWingedRipperOAM_TurningAround_Frame2,
    0x1,
    sWingedRipperOAM_TurningAround_Frame0,
    0x3,
    sWingedRipperOAM_TurningAround_Frame1,
    0x2,
    sWingedRipperOAM_TurningAround_Frame2,
    0x1,
    NULL,
    0x0
};

const struct FrameData sDefeatedImagoCocoonOAM[9] = {
    sDefeatedImagoCocoonOAM_Frame0,
    0x14,
    sDefeatedImagoCocoonOAM_Frame1,
    0x18,
    sDefeatedImagoCocoonOAM_Frame2,
    0x1C,
    sDefeatedImagoCocoonOAM_Frame1,
    0x18,
    sDefeatedImagoCocoonOAM_Frame0,
    0x28,
    sDefeatedImagoCocoonOAM_Frame1,
    0x2C,
    sDefeatedImagoCocoonOAM_Frame2,
    0x30,
    sDefeatedImagoCocoonOAM_Frame1,
    0x2C,
    NULL,
    0x0
};


void ImagoCocoonSyncSprites(void)
{
    
}

/**
 * 26ca0 | 40 | Updates the clipdata of the middle block of the ground when falling
 * 
 * @param caa Clipdata Affecting Action
 */
void ImagoCocoonChangeOneCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 11;
    xPosition = gSubSpriteData1.xPosition;
    gCurrentClipdataAffectingAction = caa;
    yPosition -= 0x20;
    ClipdataProcess(yPosition, xPosition);
    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_HUGE);
}

/**
 * 26ce0 | 70 | Updates the clipdata of the 2 blocks around the middle of the ground when falling
 * 
 * @param caa Clipdata Affecting Action
 */
void ImagoCocoonChangeTwoMiddleCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 11;
    xPosition = gSubSpriteData1.xPosition;
    
    // Right block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (HALF_BLOCK_SIZE), xPosition + BLOCK_SIZE);
    
    // Left block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (HALF_BLOCK_SIZE), xPosition - BLOCK_SIZE);

    ParticleSet(yPosition, xPosition + 0x48, PE_SPRITE_EXPLOSION_HUGE);
    ParticleSet(yPosition, xPosition - 0x48, PE_SPRITE_EXPLOSION_HUGE);
}

/**
 * @brief 26d50 | 7c | Updates the clipdata of the 2 blocks at the edge of the ground when falling
 * 
 * @param caa Clipdata Affecting Action
 */
void ImagoCocoonChangeTwoAroundCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 11;
    xPosition = gSubSpriteData1.xPosition;

    // Right block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - 0x20, xPosition + BLOCK_SIZE * 2);

    // Left block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - 0x20, xPosition - BLOCK_SIZE * 2);

    ParticleSet(yPosition, xPosition + BLOCK_SIZE * 2, PE_SPRITE_EXPLOSION_HUGE);
    ParticleSet(yPosition, xPosition - BLOCK_SIZE * 2, PE_SPRITE_EXPLOSION_HUGE);
}

/**
 * 26dcc | 5c | Updates the current clipdata affecting action and applies it, removes the 2 blocks that block the passage
 * 
 * @param caa Clipdata Affecting Action
 */
void ImagoCocoonChangeTwoBlockingCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 13;
    xPosition = gSubSpriteData1.xPosition;

    // Top block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + HALF_BLOCK_SIZE, xPosition + BLOCK_SIZE * 9);
    
    // Bottom block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE + HALF_BLOCK_SIZE, xPosition + BLOCK_SIZE * 9);
}

/**
 * 26e28 | 54 | Changes the oam scaling of the imago cocoon (growing or shrinking)
 * 
 * @param limit The limit of the scaling
 * @param value The value to increment/decrement the scaling
 */
void ImagoCocoonChangeOAMScaling(u16 limit, u16 value)
{
    if (gCurrentSprite.workVariable2) // Check growing/shrinking
    {
        if (gCurrentSprite.oamScaling > (0x100 - limit))
            gCurrentSprite.oamScaling -= value;
        else
            gCurrentSprite.workVariable2 = FALSE; // Set growing
    }
    else
    {
        if (gCurrentSprite.oamScaling < (limit + 0x100))
            gCurrentSprite.oamScaling += value;
        else
            gCurrentSprite.workVariable2 = TRUE; // Set shrinking
    }
}

/**
 * @brief 26e7c | 2ac | Initializes an Imago cocoon sprite
 * 
 */
void ImagoCocoonInit(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;
    u8 newRamSlot;

    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_IMAGO_COCOON_KILLED))
    {
        SpriteSpawnSecondary(SSPRITE_IMAGO_CEILING_VINE, 0x0, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.primarySpriteRAMSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0x0);

        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ENTER_RIDLEY_DEMO_PLAYED))
            gCurrentSprite.status = 0x0;
        else
        {
            // Set in tunnel

            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;

            gCurrentSprite.drawDistanceTopOffset = 0x38;
            gCurrentSprite.drawDistanceBottomOffset = 0x18;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.drawOrder = 0x4;
            gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING;
            gCurrentSprite.oamScaling = 0x100;
            gCurrentSprite.oamRotation = 0x0;
            gCurrentSprite.roomSlot = IMAGO_COCOON_PART_IMAGO_COCOON;

            gSubSpriteData1.pMultiOam = sImagoCocoonMultiSpriteData_Idle;
            gSubSpriteData1.animationDurationCounter = 0x0;
            gSubSpriteData1.currentAnimationFrame = 0x0;

            gCurrentSprite.pOam = sImagoCocoonOAM_Static;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = IMAGO_COCOON_POSE_IN_GROUND;
            gSubSpriteData1.yPosition += BLOCK_SIZE * 15;
        }
    }
    else
    {
        yPosition = gSubSpriteData1.yPosition;
        xPosition = gSubSpriteData1.xPosition;
        gCurrentSprite.yPositionSpawn = yPosition;

        gCurrentSprite.drawDistanceTopOffset = 0x38;
        gCurrentSprite.drawDistanceBottomOffset = 0x18;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

        gCurrentSprite.hitboxTopOffset = -0xA0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = -0x60;
        gCurrentSprite.hitboxRightOffset = 0x60;

        gCurrentSprite.drawOrder = 0x6;
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
        gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING;

        gCurrentSprite.oamScaling = 0x100;
        gCurrentSprite.oamRotation = 0x0;
        gCurrentSprite.workVariable2 = FALSE;

        gSubSpriteData1.pMultiOam = sImagoCocoonMultiSpriteData_Idle;
        gSubSpriteData1.animationDurationCounter = 0x0;
        gSubSpriteData1.currentAnimationFrame = 0x0;
        
        gSubSpriteData1.workVariable2 = 0x0;
        gSubSpriteData1.workVariable1 = 0x0;
        // Number of vines alive
        gSubSpriteData1.health = 0x6;

        gDoorUnlockTimer = 0x1;
        gCurrentSprite.pose = IMAGO_COCOON_POSE_IDLE;
        gCurrentSprite.roomSlot = IMAGO_COCOON_PART_IMAGO_COCOON;

        gfxSlot = gCurrentSprite.spritesetGFXSlot;
        ramSlot = gCurrentSprite.primarySpriteRAMSlot;

        // Spawn vines
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_LEFT_MIDDLE, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_RIGHT_MIDDLE, gfxSlot, ramSlot, yPosition, xPosition, 0x0);

        // Save RAM slot of self for the spores
        newRamSlot = SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_LEFT_VINE_DECORATIONS,
            gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        gSpriteData[newRamSlot].workVariable = newRamSlot;

        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_CEILING_VINE, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_RIGHT_VINE_DECORATIONS, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_RIGHT_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_LEFT_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_RIGHT_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_LEFT_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        
        // Spawn winged ripper
        newRamSlot = SpriteSpawnSecondary(SSPRITE_WINGED_RIPPER, 0x0, gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 4, xPosition, SPRITE_STATUS_XFLIP);
        // Set destination of winged ripper
        gSpriteData[newRamSlot].yPositionSpawn = yPosition + BLOCK_SIZE * 6;
        gSpriteData[newRamSlot].xPositionSpawn = xPosition - BLOCK_SIZE * 3;

        gBossWork.work1 = IMAGO_COCOON_MUSIC_STAGE_WAITING_TO_FADE;
    }
}

/**
 * 27128 | 2c | Handles the movement of the Imago cocoon falling
 * 
 */
void ImagoCocoonFallingMovement(void)
{
    u32 increment;

    if (gCurrentSprite.arrayOffset < 0x30)
        gCurrentSprite.arrayOffset++;

    increment = (gCurrentSprite.arrayOffset >> 0x2) + 0x8;
    gSubSpriteData1.yPosition += increment;
}

/**
 * @brief 27154 | 130 | Handles the Imago cocoon being idle
 * 
 */
void ImagoCocoonIdle(void)
{
    u16 caf;
    
    // Update music
    if (gBossWork.work1 != IMAGO_COCOON_MUSIC_STAGE_STARTED_MUSIC)
    {
        if (gBossWork.work1 == IMAGO_COCOON_MUSIC_STAGE_WAITING_TO_FADE)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && gSubSpriteData1.yPosition < gSamusData.yPosition &&
                gSamusData.yPosition - gSubSpriteData1.yPosition > BLOCK_SIZE * 8)
            {
                MusicFade(0x50);
                gBossWork.work1 = IMAGO_COCOON_MUSIC_STAGE_STARTED_FADING;
            }
        }
        else if (gBossWork.work1 == IMAGO_COCOON_MUSIC_STAGE_STARTED_FADING)
        {
            if (gSubSpriteData1.xPosition < gSamusData.xPosition && gSamusData.xPosition - gSubSpriteData1.xPosition < BLOCK_SIZE * 7)
            {
                MusicPlay(0x3F, 0x0); // Imago cocoon battle
                gBossWork.work1 = IMAGO_COCOON_MUSIC_STAGE_STARTED_MUSIC;
            }
        }
    }

    // Check play idle sound
    caf = gCurrentSprite.currentAnimationFrame;
    if (gCurrentSprite.animationDurationCounter == 0x1)
    {
        switch (caf)
        {
            case 0x0:
            case 0x2:
                SoundPlay(0x19F);
        }
    }

    // Check change palette
    if (gSubSpriteData1.health < 0x4)
    {
        gCurrentSprite.paletteRow = 0x1;
        gCurrentSprite.absolutePaletteRow = 0x1;
        if (!(gFrameCounter8Bit & 0x3F))
            ImagoCocoonChangeOAMScaling(0x1, 0x1);
    }

    // Check should fall
    if (gSubSpriteData1.health == 0x0)
    {
        // All vines dead, set falling
        gCurrentSprite.paletteRow = 0x2;
        gCurrentSprite.absolutePaletteRow = 0x2;

        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_NONE;

        gSubSpriteData1.pMultiOam = sImagoCocoonMultiSpriteData_Dying;
        gSubSpriteData1.animationDurationCounter = 0x0;
        gSubSpriteData1.currentAnimationFrame = 0x0;

        gCurrentSprite.timer = 0x0;
        gCurrentSprite.arrayOffset = 0x0;
        gCurrentSprite.pose = IMAGO_COCOON_POSE_FALLING_BEFORE_BLOCKS;

        // Set falling
        EventFunction(EVENT_ACTION_SETTING, EVENT_IMAGO_COCOON_KILLED);
        SoundPlay(0x1A3);
    }
}

/**
 * 27284 | 174 | Handles imago cocoon falling before the blocks are destroyed
 * 
 */
void ImagoCocoonFallingBeforeBlocks(void)
{
    u16 yPosition;
    u32 xPosition;
    u32 rng;
    u8 timer;

    if (!(gFrameCounter8Bit & 0x1F))
        ImagoCocoonChangeOAMScaling(0x1, 0x1);

    if (gSubSpriteData1.currentAnimationFrame > 0x7)
    {
        ImagoCocoonFallingMovement();
        yPosition = gSubSpriteData1.yPosition + BLOCK_SIZE * 6;
        xPosition = gSubSpriteData1.xPosition;
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition);
        if (gPreviousCollisionCheck & 0xF0) // Check for solid collision
        {
            ImagoCocoonChangeOneCCAA(CAA_REMOVE_SOLID); // Remove middile block

            // Set falling after blocks
            gCurrentSprite.pose = IMAGO_COCOON_POSE_FALLING_AFTER_BLOCKS;
            gCurrentSprite.timer = 0x0;
            ScreenShakeStartVertical(0x28, 0x81);
            SoundPlay(0x1A4);
        }
    }
    else
    {
        if (gSubSpriteData1.currentAnimationFrame == 0x7 && gSubSpriteData1.animationDurationCounter == 0x6)
        {
            SpriteSpawnSecondary(SSPRITE_IMAGO_CEILING_VINE, 0x0, gCurrentSprite.spritesetGFXSlot,
                gCurrentSprite.primarySpriteRAMSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0x0);
        }

        yPosition = gBG1YPosition - BLOCK_SIZE;
        xPosition = gSubSpriteData1.xPosition;
        rng = gSpriteRNG;
        
        timer = ++gCurrentSprite.timer;
        if (!(timer & 0x1F))
        {
            if (timer & 0x20)
                SpriteDebrisInit(0x0, 0x5, yPosition, xPosition + 0x5A - (rng * 0x8));
            else
                SpriteDebrisInit(0x0, 0x7, yPosition, xPosition - 0x46 + (rng * 0x8));
        }
        
        if (gSubSpriteData1.currentAnimationFrame > 0x3 && !(timer & 0x1))
        {
            if (rng > 0x7)
            {
                SpriteDebrisInit(0x0, 0x8, yPosition, xPosition - 0x96 + (rng * 0x4));
                SpriteDebrisInit(0x0, 0x6, yPosition, xPosition + 0x20 - (rng * 0x4));
            }
            else
            {
                SpriteDebrisInit(0x0, 0x6, yPosition, xPosition + 0x82 - (rng * 0x4));
                SpriteDebrisInit(0x0, 0x8, yPosition, xPosition - 0x20 + (rng * 0x4));
            }
        }
    }
}

/**
 * @brief 273f8 | fc | Handles imago cocoon falling after the blocks are destroyed
 * 
 */
void ImagoCocoonFallingAfterBlocks(void)
{
    u16 yPosition;
    u16 xPosition;
    u32 topEdge;

    // Scale and move
    if (!(gFrameCounter8Bit & 0x1))
        ImagoCocoonChangeOAMScaling(0x1, 0x1);

    ImagoCocoonFallingMovement();
    yPosition = gSubSpriteData1.yPosition + IMAGO_COCOON_SIZE;
    xPosition = gSubSpriteData1.xPosition;

    // Destroy ground/set effects
    gCurrentSprite.timer++;
    if (gCurrentSprite.timer == 0x4)
        ImagoCocoonChangeTwoMiddleCCAA(CAA_REMOVE_SOLID);
    else if (gCurrentSprite.timer == 0x8)
        ImagoCocoonChangeTwoAroundCCAA(CAA_REMOVE_SOLID);
    else if (gCurrentSprite.timer == 0xF)
    {
        ParticleSet(yPosition + 0xC0, xPosition + 0x64, PE_TWO_MEDIUM_DUST);
        ParticleSet(yPosition + 0xC0, xPosition - 0x64, PE_TWO_MEDIUM_DUST);
        ParticleSet(yPosition + 0xC0, xPosition, PE_SPRITE_EXPLOSION_HUGE);
    }

    topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(yPosition, xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        // Touched ground
        gCurrentSprite.pOam = sImagoCocoonOAM_Static;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        
        gCurrentSprite.paletteRow = 0x0;
        gCurrentSprite.absolutePaletteRow = 0x0;

        gSubSpriteData1.yPosition = topEdge - IMAGO_COCOON_SIZE;
        gCurrentSprite.pose = IMAGO_COCOON_POSE_UNLOCK_PASSAGE;
        gCurrentSprite.timer = 0x5A;

        ScreenShakeStartVertical(0x28, 0x81);
        SoundPlay(0x1A5);

        gCurrentSprite.oamScaling = 0x100;
        gCurrentSprite.workVariable2 = FALSE;

        MusicFade(0x55);
    }
}

/**
 * 274f4 | 48 | Checks if the passage should be unlocked, and unlocks it if yes
 * 
 */
void ImagoCocoonUnlockPassage(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            gCurrentSprite.pose = IMAGO_COCOON_POSE_IN_GROUND;
            ImagoCocoonChangeTwoBlockingCCAA(CAA_REMOVE_SOLID); // Remove blocking collision

            gDoorUnlockTimer = -0x3C;
            MusicPlay(0xB, 0x0); // Boss killed
        }
    }
}

/**
 * @brief 2753c | 70 | Handles Imago cocoon being in the ground
 * 
 */
void ImagoCocoonInGround(void)
{
    if (!(gFrameCounter8Bit & 0x3))
    {
        if (gCurrentSprite.workVariable2)
        {
            // Scale up
            if (gCurrentSprite.oamScaling > 0xFC)
            {
                gCurrentSprite.oamScaling--;
                gSubSpriteData1.yPosition--;
            }
            else
            {
                gCurrentSprite.workVariable2 = FALSE;
                SoundPlay(0x1A6);
            }
        }
        else
        {
            // Scale down
            if (gCurrentSprite.oamScaling < 0x104)
            {
                gCurrentSprite.oamScaling++;
                gSubSpriteData1.yPosition++;
            }
            else
                gCurrentSprite.workVariable2 = TRUE;
        }
    }
}

/**
 * @brief 275ac | 320 | Initializes an Imago cocoon vine sprite
 * 
 */
void ImagoCocoonVineInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    switch (gCurrentSprite.roomSlot)
    {
        case IMAGO_COCOON_PART_VINE_LEFT_MIDDLE:
            gCurrentSprite.drawDistanceTopOffset = 0x20;
            gCurrentSprite.drawDistanceBottomOffset = 0x20;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = 0x40;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x4;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_RIGHT_MIDDLE:
            gCurrentSprite.drawDistanceTopOffset = 0x18;
            gCurrentSprite.drawDistanceBottomOffset = 0x20;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = 0x60;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x4;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_RIGHT_RIGHT:
            gCurrentSprite.drawDistanceTopOffset = 0x18;
            gCurrentSprite.drawDistanceBottomOffset = 0x20;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x40;
            gCurrentSprite.hitboxBottomOffset = 0x60;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x4;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_LEFT_LEFT:
            gCurrentSprite.drawDistanceTopOffset = 0x20;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = 0x80;
            gCurrentSprite.hitboxLeftOffset = -0x18;
            gCurrentSprite.hitboxRightOffset = 0x18;

            gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x4;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_RIGHT_LEFT:
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x38;
            gCurrentSprite.hitboxBottomOffset = 0x38;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x7;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_LEFT_RIGHT:
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = -0x38;
            gCurrentSprite.hitboxBottomOffset = 0x38;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x7;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_LEFT_VINE_DECORATIONS:
            gCurrentSprite.drawDistanceTopOffset = 0x38;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            // Set spawning spores behavior
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_SPAWN_SPORES;
            gCurrentSprite.yPositionSpawn = 0x0;
            break;

        case IMAGO_COCOON_PART_VINE_RIGHT_VINE_DECORATIONS:
            gCurrentSprite.drawDistanceTopOffset = 0x38;
            gCurrentSprite.drawDistanceBottomOffset = 0x18;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            // Set spawning spores behavior
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x8;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_SPAWN_SPORES;
            break;

        case IMAGO_COCOON_PART_CEILING_VINE:
            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

            gCurrentSprite.hitboxTopOffset = -0x20;
            gCurrentSprite.hitboxBottomOffset = 0xA0;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x20;

            gCurrentSprite.health = 0x1;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_CEILING_VINE_IDLE;

            gCurrentSprite.frozenPaletteRowOffset = 0x5;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 278cc | 38 | Checks if the damaged sound should play
 * 
 */
void ImagoCocoonVineCheckPlayDamagedSound(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x1A2);
    }
}

/**
 * 27904 | 88 | Called when a vine dies, plays a particle effect and decrements the health of the boss 
 * 
 */
void ImagoCocoonVineDeath(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    switch (gCurrentSprite.roomSlot)
    {
        case IMAGO_COCOON_PART_VINE_LEFT_MIDDLE:
            break;
        
        case IMAGO_COCOON_PART_VINE_RIGHT_MIDDLE:
        case IMAGO_COCOON_PART_VINE_RIGHT_RIGHT:
        case IMAGO_COCOON_PART_VINE_LEFT_LEFT:
            yPosition += HALF_BLOCK_SIZE;
            break;
            
        case IMAGO_COCOON_PART_VINE_RIGHT_LEFT:
        case IMAGO_COCOON_PART_VINE_LEFT_RIGHT:
            yPosition += QUARTER_BLOCK_SIZE;
            break;

        default:
            gCurrentSprite.status = 0x0;
            return;
    }

    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_HUGE);

    // Decrement number of vines alive
    if (gSubSpriteData1.health != 0x0)
        gSubSpriteData1.health--;
    gCurrentSprite.status = 0x0;
}

/**
 * 2798c | 160 | Handles the vines spawning the spores
 * 
 */
void ImagoCocoonVineSpawnSpore(void)
{
    u8 slot;
    u8 ramSlot;
    u8 gfxSlot;
    u16 status;
    u16 yPosition;
    u16 xPosition;

    slot = gCurrentSprite.primarySpriteRAMSlot;

    if (gSpriteData[slot].pose == IMAGO_COCOON_POSE_UNLOCK_PASSAGE)
    {
        yPosition = gCurrentSprite.yPosition;
        if (gCurrentSprite.roomSlot == IMAGO_COCOON_PART_VINE_LEFT_VINE_DECORATIONS)
            xPosition = gCurrentSprite.xPosition + BLOCK_SIZE;
        else
            xPosition = gCurrentSprite.xPosition - BLOCK_SIZE;

        ParticleSet(yPosition - 0x64, xPosition, PE_TWO_MEDIUM_DUST);
        gCurrentSprite.status = 0x0;
    }
    else if (gSubSpriteData1.health != 0x0 && gCurrentSprite.roomSlot == 0x0)
    {
        gCurrentSprite.yPositionSpawn++;
        if ((gCurrentSprite.yPositionSpawn & 0xFF) == 0x0)
        {
            if (gCurrentSprite.yPositionSpawn & 0x100)
            {
                // Spore on the left
                yPosition = gCurrentSprite.yPosition - IMAGO_COCOON_SPORE_LEFT_Y_OFFSET;
                xPosition = gCurrentSprite.xPosition - IMAGO_COCOON_SPORE_LEFT_X_OFFSET;
                status = SPRITE_STATUS_NONE;
            }
            else
            {
                // Spore on the right
                yPosition = gCurrentSprite.yPosition - IMAGO_COCOON_SPORE_RIGHT_Y_OFFSET;
                xPosition = gCurrentSprite.xPosition + IMAGO_COCOON_SPORE_RIGHT_X_OFFSET;
                status = SPRITE_STATUS_XFLIP;
            }

            // Spawn spores
            gfxSlot = gCurrentSprite.spritesetGFXSlot;
            ramSlot = gCurrentSprite.workVariable;
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, IMAGO_COCOON_SPORE_PART_DOWN, gfxSlot,
                ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, IMAGO_COCOON_SPORE_PART_DIAG_RIGHT_UP, gfxSlot,
                ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, IMAGO_COCOON_SPORE_PART_RIGHT, gfxSlot,
                ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, IMAGO_COCOON_SPORE_PART_DIAG_RIGHT_DOWN, gfxSlot,
                ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, IMAGO_COCOON_SPORE_PART_UP, gfxSlot,
                ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, IMAGO_COCOON_SPORE_PART_DIAG_LEFT_DOWN, gfxSlot,
                ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, IMAGO_COCOON_SPORE_PART_LEFT, gfxSlot,
                ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, IMAGO_COCOON_SPORE_PART_DIAG_LEFT_UP, gfxSlot,
                ramSlot, yPosition, xPosition, status);
        }
    }
}

/**
 * 27aec | 44 | Handles the Imago cocoon ceilig vine being idle
 * 
 */
void ImagoCocoonCeilingVineIdle(void)
{
    if (gSubSpriteData1.health == 0x0 && gSubSpriteData1.currentAnimationFrame > 0x7)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_CEILING_VINE_DEATH;
    }
}

/**
 * 27b30 | 44 | Handles the animation of the removal of the hanging vine when imago cocoon dies
 * 
 */
void ImagoCocoonCeilingVineDeath(void)
{
    u8 ramSlot;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gSpriteData[ramSlot].pose == IMAGO_COCOON_POSE_UNLOCK_PASSAGE)
    {
        ParticleSet(gCurrentSprite.yPosition + BLOCK_SIZE * 2 + HALF_BLOCK_SIZE, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_HUGE);
        gCurrentSprite.status = 0x0;
    }
}

/**
 * 27b74 | 54 | Synchronizes the spore position with the imago cocoon position
 * 
 */
void ImagoCocoonSporeSyncPosition(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - IMAGO_COCOON_SPORE_LEFT_Y_OFFSET;
        gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition + IMAGO_COCOON_SPORE_LEFT_X_OFFSET;
    }
    else
    {
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - IMAGO_COCOON_SPORE_RIGHT_Y_OFFSET;
        gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition + IMAGO_COCOON_SPORE_RIGHT_X_OFFSET;
    }
}

/**
 * 27bc8 | a8 | Initialize an imago cocoon spore sprite
 * 
 */
void ImagoCocoonSporeInit(void)
{
    // Only display the first spore for the nest
    if (gCurrentSprite.roomSlot == IMAGO_COCOON_SPORE_PART_DOWN)
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.drawDistanceTopOffset = 0xC;
    gCurrentSprite.drawDistanceBottomOffset = 0xC;
    gCurrentSprite.drawDistanceHorizontalOffset = 0xC;

    gCurrentSprite.hitboxTopOffset = -0x8;
    gCurrentSprite.hitboxBottomOffset = 0x8;
    gCurrentSprite.hitboxLeftOffset = -0x8;
    gCurrentSprite.hitboxRightOffset = 0x5;

    gCurrentSprite.pOam = sImagoCocoonSporeOAM_Spawning;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_SPAWNING;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawOrder = 0x3;
    gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;

    gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    ImagoCocoonSporeSyncPosition();
}

/**
 * 27c70 | 74 | Handles an imago cocoon spore spawning
 * 
 */
void ImagoCocoonSporeSpawning(void)
{
    ImagoCocoonSporeSyncPosition();
    if (gSubSpriteData1.health == 0x0)
        gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_EXPLODING_INIT; // If imago cocoon is dead, kill the spores
    else
    {
        if (gCurrentSprite.roomSlot == 0x0 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN &&
            gCurrentSprite.currentAnimationFrame == 0x0 && gCurrentSprite.animationDurationCounter == 0x1)
            SoundPlay(0x1A0);

        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            // Set nest
            gCurrentSprite.pOam = sImagoCocoonSpore_Nest;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_NEST;
            gCurrentSprite.timer = 0x3C;
        }
    }
}

/**
 * 27ce4 | 8c | Handles an Imago cocoon spore being a nest 
 * 
 */
void ImagoCocoonSporeNest(void)
{
    ImagoCocoonSporeSyncPosition();
    if (gSubSpriteData1.health == 0x0)
        gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_EXPLODING_INIT; // If imago cocoon is dead, kill the spores
    else
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);

            gCurrentSprite.pOam = sImagoCocoonSpore_Moving;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
            gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_MOVING;

            if (gCurrentSprite.roomSlot == IMAGO_COCOON_SPORE_PART_DOWN && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(0x1A1);
        }
    }
}

/**
 * @brief 27d70 | 114 | Handles the movement of an Imago cocoon spore
 * 
 */
void ImagoCocoonSporeMove(void)
{
    u16 movement;

    movement = 0x4;
    switch (gCurrentSprite.roomSlot)
    {
        case IMAGO_COCOON_SPORE_PART_DIAG_RIGHT_UP:
            movement *= 0.8;
            gCurrentSprite.yPosition -= movement;
            gCurrentSprite.xPosition += movement;
            break;
        
        case IMAGO_COCOON_SPORE_PART_DIAG_RIGHT_DOWN:
            movement *= 0.8;
            gCurrentSprite.yPosition += movement;
            gCurrentSprite.xPosition += movement;
            break;
        
        case IMAGO_COCOON_SPORE_PART_RIGHT:
            gCurrentSprite.xPosition += movement;
            break;
        
        case IMAGO_COCOON_SPORE_PART_UP:
            gCurrentSprite.yPosition -= movement;
            break;
        
        case IMAGO_COCOON_SPORE_PART_DIAG_LEFT_DOWN:
            movement *= 0.8;
            gCurrentSprite.yPosition += movement;
            gCurrentSprite.xPosition -= movement;
            break;
        
        case IMAGO_COCOON_SPORE_PART_DIAG_LEFT_UP:
            movement *= 0.8;
            gCurrentSprite.yPosition -= movement;
            gCurrentSprite.xPosition -= movement;
            break;
        
        case IMAGO_COCOON_SPORE_PART_LEFT:
            gCurrentSprite.xPosition -= movement;
            break;

        default:
            gCurrentSprite.yPosition += movement;
    }

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousCollisionCheck & 0xF0)
        gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_EXPLODING_INIT;
}

/**
 * 27e84 | 34 | Initializes an Imago cocoon spore to b exploding
 * 
 */
void ImagoCocoonSporeExplodingInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    
    gCurrentSprite.pOam = sImagoCocoonSpore_Exploding;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_EXPLODING;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
}

/**
 * 27eb8 | 24 | Checks if the explosion animation has ended, if yes kills the sprite
 * 
 */
void ImagoCocoonSporeCheckExplodingAnimEnded(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}

/**
 * @brief 27edc | c4 | Checks if the winged ripper and the falling Imago cocoon are colliding 
 * 
 * @return u8 1 if colliding, 0 otherwise
 */
u8 WingedRipperImagoCollision(void)
{
    u8 colliding;
    u8 ramSlot;
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u16 imagoY;
    u16 imagoX;
    u16 imagoTop;
    u16 imagoBottom;
    u16 imagoLeft;
    u16 imagoRight;

    colliding = FALSE;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    if (gSpriteData[ramSlot].pose == IMAGO_COCOON_POSE_FALLING_BEFORE_BLOCKS && gSpriteData[ramSlot].arrayOffset > 0x10)
    {
        spriteY = gCurrentSprite.yPosition;
        spriteX = gCurrentSprite.xPosition;
        spriteTop = spriteY + gCurrentSprite.hitboxTopOffset;
        spriteBottom = spriteY + gCurrentSprite.hitboxBottomOffset;
        spriteLeft = spriteX + gCurrentSprite.hitboxLeftOffset;
        spriteRight = spriteX + gCurrentSprite.hitboxRightOffset;
        
        imagoY = gSpriteData[ramSlot].yPosition;
        imagoX = gSpriteData[ramSlot].xPosition;
        imagoTop = imagoY + gSpriteData[ramSlot].hitboxTopOffset;
        imagoBottom = imagoY + gSpriteData[ramSlot].hitboxBottomOffset;
        imagoLeft = imagoX + gSpriteData[ramSlot].hitboxLeftOffset;
        imagoRight = imagoX + gSpriteData[ramSlot].hitboxRightOffset;

        if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, imagoTop, imagoBottom, imagoLeft, imagoRight))
        {
            gCurrentSprite.pose = 0x62;
            colliding = TRUE;
        }
    }

    return colliding;
}

/**
 * @brief 27fa0 | a0 | Initializes a winged ripper sprite
 * 
 * @return * void 
 */
void WingedRipperInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.hitboxTopOffset = -0x20;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x20;
    gCurrentSprite.hitboxRightOffset = 0x20;

    gCurrentSprite.drawDistanceTopOffset = 0xC;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

    gCurrentSprite.pOam = sWingedRipperOAM_Moving;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.drawOrder = 0x8;

    gCurrentSprite.pose = WINGED_RIPPER_POSE_MOVING_INIT;
    gCurrentSprite.oamScaling = 0xC0;
    gCurrentSprite.workVariable = 0x80;

    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.frozenPaletteRowOffset = 0x4;
}

/**
 * @brief 28040 | 20 | Initializes a winged ripper to be moving
 * 
 */
void WingedRipperMovingInit(void)
{
    gCurrentSprite.pose = WINGED_RIPPER_POSE_MOVING;
    gCurrentSprite.pOam = sWingedRipperOAM_Moving;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
}

/**
 * @brief 28060 | 224 | Handles the movement of a winged ripper
 * 
 */
void WingedRipperMove(void)
{
    i32 multiplier;
    u8 offset;
    i32 previousY;
    i32 previousX;
    i32 currentY;
    i32 currentX;

    // Check turning around
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.workVariable == 0x0)
        {
            gCurrentSprite.xPositionSpawn += BLOCK_SIZE * 6;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.workVariable = 0x7F;
        }
        else if (gCurrentSprite.workVariable == 0x80)
        {
            if (gCurrentSprite.pOam != sWingedRipperOAM_TurningAround)
            {
                gCurrentSprite.pOam = sWingedRipperOAM_TurningAround;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
            }
        }
        else if (gCurrentSprite.pOam == sWingedRipperOAM_TurningAround && SpriteUtilCheckEndCurrentSpriteAnim())
        {
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            {
                gCurrentSprite.pOam = sWingedRipperOAM_Moving;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
            }
            else
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
        }
    }
    else
    {
        if (gCurrentSprite.workVariable == 0x80)
        {
            gCurrentSprite.xPositionSpawn -= BLOCK_SIZE * 6;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.workVariable = 0x1;
        }
        else if (gCurrentSprite.workVariable == 0x0)
        {
            if (gCurrentSprite.pOam != sWingedRipperOAM_TurningAround)
            {
                gCurrentSprite.pOam = sWingedRipperOAM_TurningAround;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
            }
        }
        else if (gCurrentSprite.pOam == sWingedRipperOAM_TurningAround && SpriteUtilCheckEndCurrentSpriteAnim())
        {
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            else
            {
                gCurrentSprite.pOam = sWingedRipperOAM_Moving;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
            }
        }
    }

    // Update sine offset
    if (gCurrentSprite.arrayOffset & 0x1)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.workVariable++;
        else
            gCurrentSprite.workVariable--;
    }

    multiplier = (i16)gCurrentSprite.oamScaling;
    offset = gCurrentSprite.workVariable;

    // Update Y position
    currentY = sSineYValues[offset];
    previousY = (i16)gCurrentSprite.yPosition;

    if (currentY < 0x0)
    {
        currentY = (i16)(-currentY * multiplier / 256);
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn - currentY;
    }
    else
    {
        currentY = (i16)(currentY * multiplier / 256);
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn + currentY;
    }

    // Update X position
    currentX = sSineYValues[offset + 0x40];
    previousX = (i16)gCurrentSprite.xPosition;

    if (currentX < 0x0)
    {
        currentX = (i16)(-currentX * multiplier / 256);
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn - currentX;
    }
    else
    {
        currentX = (i16)(currentX * multiplier / 256);
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn + currentX;
    }

    currentY = (i16)gCurrentSprite.yPosition;
    currentX = (i16)gCurrentSprite.xPosition;
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP)
    {
        // Update samus standing on the winged ripper
        if (currentY > previousY)
        {
            previousY = (i16)(currentY - previousY);
            gSamusData.yPosition += previousY;
        }
        else
        {
            previousY = (i16)(previousY - currentY);
            gSamusData.yPosition -= previousY;
        }

        if (currentX > previousX)
        {
            previousX = (i16)(currentX - previousX);
            gSamusData.xPosition += previousX;
        }
        else
        {
            previousX = (i16)(previousX - currentX);
            gSamusData.xPosition -= previousX;
        }
    }

    WingedRipperImagoCollision();
}

/**
 * @brief 28284 | 44 | Handles the winged ripper death
 * 
 */
void WingedRipperDeath(void)
{
    if (gCurrentSprite.standingOnSprite)
    {
        if (gSamusData.standingStatus == STANDING_ENEMY)
            gSamusData.standingStatus = STANDING_MIDAIR;
        gCurrentSprite.standingOnSprite = FALSE;
    }

    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition + 0x8, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
}

/**
 * @brief 282c8 | 104 | Imago cocoon AI
 * 
 */
void ImagoCocoon(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ImagoCocoonInit();
            break;

        case IMAGO_COCOON_POSE_IDLE:
            ImagoCocoonIdle();
            break;

        case IMAGO_COCOON_POSE_FALLING_BEFORE_BLOCKS:
            ImagoCocoonFallingBeforeBlocks();
            break;

        case IMAGO_COCOON_POSE_FALLING_AFTER_BLOCKS:
            ImagoCocoonFallingAfterBlocks();
            break;

        case IMAGO_COCOON_POSE_UNLOCK_PASSAGE:
            ImagoCocoonUnlockPassage();
            break;

        case IMAGO_COCOON_POSE_IN_GROUND:
            ImagoCocoonInGround();
    }

    SpriteUtilUpdateSubSprite1Anim();
    if (gCurrentSprite.pose >= IMAGO_COCOON_POSE_UNLOCK_PASSAGE)
        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    else
        ImagoCocoonSyncSprites();
}

/**
 * @brief 283cc | 70 | Imago cocoon vine AI
 * 
 */
void ImagoCocoonVine(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ImagoCocoonVineInit();
            break;

        case 0x62:
            ImagoCocoonVineDeath();

        case IMAGO_COCOON_VINE_POSE_IDLE:
            ImagoCocoonVineCheckPlayDamagedSound();
            break;

        case IMAGO_COCOON_VINE_POSE_SPAWN_SPORES:
            ImagoCocoonVineSpawnSpore();
            break;
            
        case IMAGO_COCOON_VINE_POSE_CEILING_VINE_IDLE:
            ImagoCocoonCeilingVineIdle();
            break;

        case IMAGO_COCOON_VINE_POSE_CEILING_VINE_DEATH:
            ImagoCocoonCeilingVineDeath();
    }

    if (gCurrentSprite.pose == 0x67)
        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    else
        ImagoCocoonSyncSprites();
}

/**
 * @brief 2843c | 8c | Imago cocoon spore AI
 * 
 */
void ImagoCocoonSpore(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ImagoCocoonSporeInit();
            break;

        case IMAGO_COCOON_SPORE_POSE_SPAWNING:
            ImagoCocoonSporeBeforeSpawning();
            break;

        case IMAGO_COCOON_SPORE_POSE_NEST:
            ImagoCocoonSporeNest();
            break;

        case IMAGO_COCOON_SPORE_POSE_MOVING:
            ImagoCocoonSporeMove();
            break;

        case IMAGO_COCOON_SPORE_POSE_EXPLODING_INIT:
            ImagoCocoonSporeExplodingInit();
            break;

        case IMAGO_COCOON_SPORE_POSE_EXPLODING:
            ImagoCocoonSporeCheckExplodingAnimEnded();
            break;
        default:
            // Kill sprite
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);

            if (gCurrentSprite.status & SPRITE_STATUS_EXISTS && SpriteUtilCountDrops() > 0x1)
                gCurrentSprite.status = 0x0; // Anti lag measure
    }
}

/**
 * @brief 284c8 | 6c | Winged ripper AI
 * 
 */
void WingedRipper(void)
{
    if (gCurrentSprite.freezeTimer != 0x0)
    {
        SpriteUtilUnfreezeAnimEasy();
        if (!(WingedRipperImagoCollision()))
            return;
    }

    if (SpriteUtilIsSpriteStunned())
        return;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            WingedRipperInit();
            break;

        case WINGED_RIPPER_POSE_MOVING_INIT:
            WingedRipperMovingInit();

        case WINGED_RIPPER_POSE_MOVING:
            WingedRipperMove();
            break;

        default:
            WingedRipperDeath();
    }

    // Increment sine offset timer
    gCurrentSprite.arrayOffset++;
}

/**
 * @brief 28534 | 78 | Defeated Imago cocoon AI
 * 
 */
void DefeatedImagoCocoon(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        gCurrentSprite.drawDistanceTopOffset = 0xC;
        gCurrentSprite.drawDistanceBottomOffset = 0x28;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x30;

        gCurrentSprite.hitboxTopOffset = -0x4;
        gCurrentSprite.hitboxBottomOffset = 0x4;
        gCurrentSprite.hitboxLeftOffset = -0x4;
        gCurrentSprite.hitboxRightOffset = 0x4;

        gCurrentSprite.pOam = sDefeatedImagoCocoonOAM;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x5;
    }
}

/**
 * @brief 285ac | 7c | Imago cocoon ceiling vine AI
 * 
 */
void ImagoCocoonCeilingVine(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        gCurrentSprite.drawDistanceTopOffset = 0xC;
        gCurrentSprite.drawDistanceBottomOffset = 0x28;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x30;

        gCurrentSprite.hitboxTopOffset = -0x4;
        gCurrentSprite.hitboxBottomOffset = 0x4;
        gCurrentSprite.hitboxLeftOffset = -0x4;
        gCurrentSprite.hitboxRightOffset = 0x4;

        gCurrentSprite.pOam = sImagoCocoonOAM_CeilingVineBroken;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawOrder = 0x5;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x5;
    }
}

/**
 * @brief 28628 | 90 | Event trigger (discovered Imago passage) AI
 * 
 */
void EventTriggerDiscoveredImagoPassage(void)
{
    if (gCurrentSprite.pose == 0x0)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_IMAGO_TUNNEL_DISCOVERED))
        {
            gCurrentSprite.status = 0x0;
            return;
        }
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;

        gCurrentSprite.drawDistanceTopOffset = 0x10;
        gCurrentSprite.drawDistanceBottomOffset = 0x0;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

        gCurrentSprite.hitboxTopOffset = -0x40;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = -0x20;
        gCurrentSprite.hitboxRightOffset = 0x20;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.pOam = sEnemyDropOAM_LargeEnergy;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        // Set event
        gCurrentSprite.status = 0x0;
        EventFunction(EVENT_ACTION_SETTING, EVENT_IMAGO_TUNNEL_DISCOVERED);
    }
}

/**
 * @brief 286b8 | 74 | Imago cocoon after fight AI
 * 
 */
void ImagoCocoonAfterFight(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.drawDistanceTopOffset = 0x30;
        gCurrentSprite.drawDistanceBottomOffset = 0x10;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

        gCurrentSprite.hitboxTopOffset = -0x4;
        gCurrentSprite.hitboxBottomOffset = 0x4;
        gCurrentSprite.hitboxLeftOffset = -0x4;
        gCurrentSprite.hitboxRightOffset = 0x4;

        gCurrentSprite.pOam = sDefeatedImagoCocoonOAM;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = 0x9;
    }

    if (gCurrentSprite.animationDurationCounter == 0x1)
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 0x1:
            case 0x4:
                SoundPlay(0x212);
        }
    }
}