#include "data/sprites/imago_cocoon.h"
#include "macros.h"

const s16 sImagoCocoonMultiSpriteData_Idle_Frame0[30] = {
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

const s16 sImagoCocoonMultiSpriteData_Idle_Frame1[30] = {
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

const s16 sImagoCocoonMultiSpriteData_Dying_Frame0[30] = {
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

const s16 sImagoCocoonMultiSpriteData_Dying_Frame1[30] = {
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

const s16 sImagoCocoonMultiSpriteData_Dying_Frame3[30] = {
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

const s16 sImagoCocoonMultiSpriteData_Dying_Frame4[30] = {
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

const s16 sImagoCocoonMultiSpriteData_Dying_Frame5[30] = {
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

const s16 sImagoCocoonMultiSpriteData_Dying_Frame6[30] = {
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

const s16 sImagoCocoonMultiSpriteData_Dying_Frame7[30] = {
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

const s16 sImagoCocoonMultiSpriteData_Dying_Frame8[30] = {
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

const s16 sImagoCocoon_ArrayUnused1[36] = {
    -8, -8, -6, -6, -5, -5, -4, -4, -3, -3, -2, -2, -1,
    -1, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 14, 16, 18, SHORT_MAX
};

const s16 sImagoCocoon_ArrayUnused2[48] = {
    0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 4, 4, 4, 4, 2, 2, 2, 2,
    1, 1, 1, 1, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0,
    0, 0, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2
};

const u32 sImagoCocoonGfx[1758] = INCBIN_U32("data/sprites/ImagoCocoon.gfx.lz");
const u16 sImagoCocoonPal[96] = INCBIN_U16("data/sprites/ImagoCocoon.pal");

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

const struct FrameData sImagoCocoonVineOAM_RightMiddle[5] = {
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
    0x80,
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
