#include "boss_statues.h"
#include "../../data/data.h"
#include "../globals.h"

const u8 sBossStatuesGFX[9552];
const u16 sBossStatuesPAL[128];

const u16 sKraidStatueOAM_Idle_Frame0[16] = {
    0x5,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x25f,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOAM_Activating_Frame0[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x30c,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x25f,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x21c,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOAM_Activating_Frame1[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x30e,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x25f,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x21e,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOAM_Activating_Frame2[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x32e,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x25f,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x296,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOAM_Activating_Frame3[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x310,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x2b6,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x2bf,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOAM_Activating_Frame4[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x330,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x2d6,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x2df,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOAM_Activating_Frame5[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x312,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x2f6,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x31f,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOAM_Activating_Frame6[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x332,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x2d8,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x33f,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOAM_Activating_Frame7[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x314,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x2f8,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x2da,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOAM_Activated_Frame5[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x334,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x2bf,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x2fa,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOAM_Opening_Frame8[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd7, 0x40, OBJ_SPRITE_OAM | 0x310,
    OBJ_SHAPE_HORIZONTAL | 0xcf, 0x48, OBJ_SPRITE_OAM | 0x2b6,
    0xc7, 0x50, OBJ_SPRITE_OAM | 0x2bf,
    0xb7, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd3, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf3, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOAM_Opening_Frame11[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd6, 0x3f, OBJ_SPRITE_OAM | 0x310,
    OBJ_SHAPE_HORIZONTAL | 0xce, 0x47, OBJ_SPRITE_OAM | 0x2b6,
    0xc6, 0x4f, OBJ_SPRITE_OAM | 0x2bf,
    0xb6, OBJ_SIZE_64x64 | 0xf, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_8x32 | 0x4f, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd2, OBJ_SIZE_16x32 | 0x57, OBJ_SPRITE_OAM | 0x274,
    0xf2, 0x5f, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOAM_Opening_Frame14[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd5, 0x3f, OBJ_SPRITE_OAM | 0x310,
    OBJ_SHAPE_HORIZONTAL | 0xcd, 0x47, OBJ_SPRITE_OAM | 0x2b6,
    0xc5, 0x4f, OBJ_SPRITE_OAM | 0x2bf,
    0xb5, OBJ_SIZE_64x64 | 0xf, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xcd, OBJ_SIZE_8x32 | 0x4f, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd1, OBJ_SIZE_16x32 | 0x57, OBJ_SPRITE_OAM | 0x274,
    0xf1, 0x5f, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOAM_Opening_Frame17[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd4, 0x3e, OBJ_SPRITE_OAM | 0x310,
    OBJ_SHAPE_HORIZONTAL | 0xcc, 0x46, OBJ_SPRITE_OAM | 0x2b6,
    0xc4, 0x4e, OBJ_SPRITE_OAM | 0x2bf,
    0xb4, OBJ_SIZE_64x64 | 0xe, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xcc, OBJ_SIZE_8x32 | 0x4e, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x56, OBJ_SPRITE_OAM | 0x274,
    0xf0, 0x5e, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOAM_Opening_Frame20[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xbc, 0x7, OBJ_SPRITE_OAM | 0x3c1,
    0xb4, OBJ_SIZE_64x64 | 0xf, OBJ_SPRITE_OAM | 0x316,
    OBJ_SHAPE_VERTICAL | 0xbe, OBJ_SIZE_8x32 | 0x4f, OBJ_SPRITE_OAM | 0x31e,
    OBJ_SHAPE_VERTICAL | 0xbc, OBJ_SIZE_16x32 | 0x57, OBJ_SPRITE_OAM | 0x39e,
    OBJ_SHAPE_VERTICAL | 0xcf, 0x67, OBJ_SPRITE_OAM | 0x35f
};

const u16 sKraidStatueOAM_Opening_Frame21[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xba, 0x6, OBJ_SPRITE_OAM | 0x3c1,
    0xb2, OBJ_SIZE_64x64 | 0xe, OBJ_SPRITE_OAM | 0x316,
    OBJ_SHAPE_VERTICAL | 0xbb, OBJ_SIZE_8x32 | 0x4e, OBJ_SPRITE_OAM | 0x31e,
    OBJ_SHAPE_VERTICAL | 0xb9, OBJ_SIZE_16x32 | 0x56, OBJ_SPRITE_OAM | 0x39e,
    OBJ_SHAPE_VERTICAL | 0xcc, 0x66, OBJ_SPRITE_OAM | 0x35f
};

const u16 sKraidStatueOAM_Opening_Frame24[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xb7, 0x5, OBJ_SPRITE_OAM | 0x3c1,
    0xaf, OBJ_SIZE_64x64 | 0xd, OBJ_SPRITE_OAM | 0x316,
    OBJ_SHAPE_VERTICAL | 0xb7, OBJ_SIZE_8x32 | 0x4d, OBJ_SPRITE_OAM | 0x31e,
    OBJ_SHAPE_VERTICAL | 0xb4, OBJ_SIZE_16x32 | 0x55, OBJ_SPRITE_OAM | 0x39e,
    OBJ_SHAPE_VERTICAL | 0xc7, 0x65, OBJ_SPRITE_OAM | 0x35f
};

const u16 sKraidStatueOAM_Opening_Frame27[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xb6, 0x4, OBJ_SPRITE_OAM | 0x3c1,
    0xae, OBJ_SIZE_64x64 | 0xc, OBJ_SPRITE_OAM | 0x316,
    OBJ_SHAPE_VERTICAL | 0xb6, OBJ_SIZE_8x32 | 0x4c, OBJ_SPRITE_OAM | 0x31e,
    OBJ_SHAPE_VERTICAL | 0xb3, OBJ_SIZE_16x32 | 0x54, OBJ_SPRITE_OAM | 0x39e,
    OBJ_SHAPE_VERTICAL | 0xc6, 0x64, OBJ_SPRITE_OAM | 0x35f
};

const u16 sKraidStatueOAM_Opening_Frame30[19] = {
    0x6,
    0xab, OBJ_SIZE_64x64 | 0xe, OBJ_SPRITE_OAM | 0x302,
    OBJ_SHAPE_VERTICAL | 0xc3, 0x1fe, OBJ_SPRITE_OAM | 0x360,
    OBJ_SHAPE_VERTICAL | 0xbb, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x341,
    0xa5, 0x4e, OBJ_SPRITE_OAM | 0x2ea,
    OBJ_SHAPE_VERTICAL | 0xad, OBJ_SIZE_16x32 | 0x4e, OBJ_SPRITE_OAM | 0x30a,
    0xb5, OBJ_SIZE_16x16 | 0x5e, OBJ_SPRITE_OAM | 0x32c
};

const u16 sKraidStatueOAM_Opening_Frame31[19] = {
    0x6,
    0xa9, OBJ_SIZE_64x64 | 0xd, OBJ_SPRITE_OAM | 0x302,
    OBJ_SHAPE_VERTICAL | 0xc1, 0x1fd, OBJ_SPRITE_OAM | 0x360,
    OBJ_SHAPE_VERTICAL | 0xb9, OBJ_SIZE_8x32 | 0x5, OBJ_SPRITE_OAM | 0x341,
    0xa2, 0x4d, OBJ_SPRITE_OAM | 0x2ea,
    OBJ_SHAPE_VERTICAL | 0xaa, OBJ_SIZE_16x32 | 0x4d, OBJ_SPRITE_OAM | 0x30a,
    0xb2, OBJ_SIZE_16x16 | 0x5d, OBJ_SPRITE_OAM | 0x32c
};

const u16 sKraidStatueOAM_Opening_Frame32[19] = {
    0x6,
    0xa8, OBJ_SIZE_64x64 | 0xc, OBJ_SPRITE_OAM | 0x302,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x360,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x341,
    0xa0, 0x4c, OBJ_SPRITE_OAM | 0x2ea,
    OBJ_SHAPE_VERTICAL | 0xa8, OBJ_SIZE_16x32 | 0x4c, OBJ_SPRITE_OAM | 0x30a,
    0xb0, OBJ_SIZE_16x16 | 0x5c, OBJ_SPRITE_OAM | 0x32c
};

const u16 sKraidStatueOAM_Opening_Frame41[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xaa, 0x34, OBJ_SPRITE_OAM | 0x2fc,
    OBJ_SHAPE_HORIZONTAL | 0xb8, 0x34, OBJ_SPRITE_OAM | 0x3ec,
    0xa8, OBJ_SIZE_64x64 | 0xc, OBJ_SPRITE_OAM | 0x302,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x360,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x341,
    0xa0, 0x4c, OBJ_SPRITE_OAM | 0x2ea,
    OBJ_SHAPE_VERTICAL | 0xa8, OBJ_SIZE_16x32 | 0x4c, OBJ_SPRITE_OAM | 0x30a,
    0xb0, OBJ_SIZE_16x16 | 0x5c, OBJ_SPRITE_OAM | 0x32c
};

const u16 sKraidStatueOAM_Opened_Frame0[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xaa, 0x34, OBJ_SPRITE_OAM | 0x2fe,
    OBJ_SHAPE_HORIZONTAL | 0xb8, 0x34, OBJ_SPRITE_OAM | 0x2f3,
    0xa8, OBJ_SIZE_64x64 | 0xc, OBJ_SPRITE_OAM | 0x302,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x360,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x341,
    0xa0, 0x4c, OBJ_SPRITE_OAM | 0x2ea,
    OBJ_SHAPE_VERTICAL | 0xa8, OBJ_SIZE_16x32 | 0x4c, OBJ_SPRITE_OAM | 0x30a,
    0xb0, OBJ_SIZE_16x16 | 0x5c, OBJ_SPRITE_OAM | 0x32c
};

const u16 sRidleyStatueOAM_Idle_Frame0[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_64x32 | 0x1b1, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x283,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1d1, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_HORIZONTAL | 0xec, 0x1b1, OBJ_SPRITE_OAM | 0x2c3,
    0xd4, 0x1a9, OBJ_SPRITE_OAM | 0x262,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_8x32 | 0x1a9, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_16x32 | 0x199, OBJ_SPRITE_OAM | 0x2a0,
    0xdc, 0x1a1, OBJ_SPRITE_OAM | 0x281
};

const u16 sRidleyStatueOAM_Activating_Frame0[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xd2, 0x1b8, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_64x32 | 0x1b1, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x283,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1d1, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_HORIZONTAL | 0xec, 0x1b1, OBJ_SPRITE_OAM | 0x2c3,
    0xd4, 0x1a9, OBJ_SPRITE_OAM | 0x262,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_8x32 | 0x1a9, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_16x32 | 0x199, OBJ_SPRITE_OAM | 0x2a0,
    0xdc, 0x1a1, OBJ_SPRITE_OAM | 0x281
};

const u16 sRidleyStatueOAM_Activating_Frame1[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xd2, 0x1b8, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_64x32 | 0x1b1, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x283,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1d1, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_HORIZONTAL | 0xec, 0x1b1, OBJ_SPRITE_OAM | 0x2c3,
    0xd4, 0x1a9, OBJ_SPRITE_OAM | 0x262,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_8x32 | 0x1a9, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_16x32 | 0x199, OBJ_SPRITE_OAM | 0x2a0,
    0xdc, 0x1a1, OBJ_SPRITE_OAM | 0x281
};

const u16 sRidleyStatueOAM_Activating_Frame2[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xd2, 0x1b8, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_64x32 | 0x1b1, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x283,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1d1, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_HORIZONTAL | 0xec, 0x1b1, OBJ_SPRITE_OAM | 0x2c3,
    0xd4, 0x1a9, OBJ_SPRITE_OAM | 0x262,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_8x32 | 0x1a9, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_16x32 | 0x199, OBJ_SPRITE_OAM | 0x2a0,
    0xdc, 0x1a1, OBJ_SPRITE_OAM | 0x281
};

const u16 sRidleyStatueOAM_Activating_Frame3[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xd2, 0x1b8, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_64x32 | 0x1b1, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x283,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1d1, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_HORIZONTAL | 0xec, 0x1b1, OBJ_SPRITE_OAM | 0x2c3,
    0xd4, 0x1a9, OBJ_SPRITE_OAM | 0x262,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_8x32 | 0x1a9, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_16x32 | 0x199, OBJ_SPRITE_OAM | 0x2a0,
    0xdc, 0x1a1, OBJ_SPRITE_OAM | 0x281
};

const u16 sRidleyStatueOAM_Activating_Frame4[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xd2, 0x1b8, OBJ_SPRITE_OAM | 0x2e3,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_64x32 | 0x1b1, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x283,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1d1, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_HORIZONTAL | 0xec, 0x1b1, OBJ_SPRITE_OAM | 0x2c3,
    0xd4, 0x1a9, OBJ_SPRITE_OAM | 0x262,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_8x32 | 0x1a9, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_16x32 | 0x199, OBJ_SPRITE_OAM | 0x2a0,
    0xdc, 0x1a1, OBJ_SPRITE_OAM | 0x281
};

const u16 sRidleyStatueOAM_Activating_Frame5[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xd2, 0x1b8, OBJ_SPRITE_OAM | 0x2c5,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_64x32 | 0x1b1, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x283,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1d1, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_HORIZONTAL | 0xec, 0x1b1, OBJ_SPRITE_OAM | 0x2c3,
    0xd4, 0x1a9, OBJ_SPRITE_OAM | 0x262,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_8x32 | 0x1a9, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_16x32 | 0x199, OBJ_SPRITE_OAM | 0x2a0,
    0xdc, 0x1a1, OBJ_SPRITE_OAM | 0x281
};

const u16 sRidleyStatueOAM_Activating_Frame6[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xd2, 0x1b8, OBJ_SPRITE_OAM | 0x2e5,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_64x32 | 0x1b1, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x283,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1d1, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_HORIZONTAL | 0xec, 0x1b1, OBJ_SPRITE_OAM | 0x2c3,
    0xd4, 0x1a9, OBJ_SPRITE_OAM | 0x262,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_8x32 | 0x1a9, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_16x32 | 0x199, OBJ_SPRITE_OAM | 0x2a0,
    0xdc, 0x1a1, OBJ_SPRITE_OAM | 0x281
};

const u16 sRidleyStatueOAM_Activating_Frame7[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xd2, 0x1b8, OBJ_SPRITE_OAM | 0x2c7,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_64x32 | 0x1b1, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x283,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1d1, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_HORIZONTAL | 0xec, 0x1b1, OBJ_SPRITE_OAM | 0x2c3,
    0xd4, 0x1a9, OBJ_SPRITE_OAM | 0x262,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_8x32 | 0x1a9, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_16x32 | 0x199, OBJ_SPRITE_OAM | 0x2a0,
    0xdc, 0x1a1, OBJ_SPRITE_OAM | 0x281
};

const u16 sRidleyStatueOAM_Activated_Frame5[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xd2, 0x1b8, OBJ_SPRITE_OAM | 0x2e7,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_64x32 | 0x1b1, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x283,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x16 | 0x1d1, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_HORIZONTAL | 0xec, 0x1b1, OBJ_SPRITE_OAM | 0x2c3,
    0xd4, 0x1a9, OBJ_SPRITE_OAM | 0x262,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_8x32 | 0x1a9, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_16x32 | 0x199, OBJ_SPRITE_OAM | 0x2a0,
    0xdc, 0x1a1, OBJ_SPRITE_OAM | 0x281
};

const u16 sRidleyStatueOAM_Opening_Frame8[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xd1, 0x1b8, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0xbb, OBJ_SIZE_64x32 | 0x1b1, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x283,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_SIZE_32x16 | 0x1d1, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_HORIZONTAL | 0xeb, 0x1b1, OBJ_SPRITE_OAM | 0x2c3,
    0xd3, 0x1a9, OBJ_SPRITE_OAM | 0x262,
    OBJ_SHAPE_VERTICAL | 0xdb, OBJ_SIZE_8x32 | 0x1a9, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_SIZE_16x32 | 0x199, OBJ_SPRITE_OAM | 0x2a0,
    0xdb, 0x1a1, OBJ_SPRITE_OAM | 0x281
};

const u16 sRidleyStatueOAM_Opening_Frame11[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x1b9, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0xba, OBJ_SIZE_64x32 | 0x1b2, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_HORIZONTAL | 0xda, OBJ_SIZE_32x16 | 0x1b2, OBJ_SPRITE_OAM | 0x283,
    OBJ_SHAPE_HORIZONTAL | 0xda, OBJ_SIZE_32x16 | 0x1d2, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_HORIZONTAL | 0xea, 0x1b2, OBJ_SPRITE_OAM | 0x2c3,
    0xd2, 0x1aa, OBJ_SPRITE_OAM | 0x262,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x1aa, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xe2, OBJ_SIZE_16x32 | 0x19a, OBJ_SPRITE_OAM | 0x2a0,
    0xda, 0x1a2, OBJ_SPRITE_OAM | 0x281
};

const u16 sRidleyStatueOAM_Opening_Frame14[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xcf, 0x1b9, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0xb9, OBJ_SIZE_64x32 | 0x1b2, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_HORIZONTAL | 0xd9, OBJ_SIZE_32x16 | 0x1b2, OBJ_SPRITE_OAM | 0x283,
    OBJ_SHAPE_HORIZONTAL | 0xd9, OBJ_SIZE_32x16 | 0x1d2, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_HORIZONTAL | 0xe9, 0x1b2, OBJ_SPRITE_OAM | 0x2c3,
    0xd1, 0x1aa, OBJ_SPRITE_OAM | 0x262,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_SIZE_8x32 | 0x1aa, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_16x32 | 0x19a, OBJ_SPRITE_OAM | 0x2a0,
    0xd9, 0x1a2, OBJ_SPRITE_OAM | 0x281
};

const u16 sRidleyStatueOAM_Opening_Frame17[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xce, 0x1ba, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0xb8, OBJ_SIZE_64x32 | 0x1b3, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x16 | 0x1b3, OBJ_SPRITE_OAM | 0x283,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x16 | 0x1d3, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1b3, OBJ_SPRITE_OAM | 0x2c3,
    0xd0, 0x1ab, OBJ_SPRITE_OAM | 0x262,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1ab, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x19b, OBJ_SPRITE_OAM | 0x2a0,
    0xd8, 0x1a3, OBJ_SPRITE_OAM | 0x281
};

const u16 sRidleyStatueOAM_Opening_Frame20[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xb7, OBJ_SIZE_64x32 | 0x1b2, OBJ_SPRITE_OAM | 0x34e,
    OBJ_SHAPE_HORIZONTAL | 0xd7, OBJ_SIZE_32x16 | 0x1b2, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xd7, OBJ_SIZE_32x16 | 0x1d2, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_VERTICAL | 0xbf, 0x1f2, OBJ_SPRITE_OAM | 0x3c0,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1a2, OBJ_SPRITE_OAM | 0x36c,
    OBJ_SHAPE_VERTICAL | 0xc9, OBJ_SIZE_16x32 | 0x192, OBJ_SPRITE_OAM | 0x38a
};

const u16 sRidleyStatueOAM_Opening_Frame21[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xb5, OBJ_SIZE_64x32 | 0x1b3, OBJ_SPRITE_OAM | 0x34e,
    OBJ_SHAPE_HORIZONTAL | 0xd5, OBJ_SIZE_32x16 | 0x1b3, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xd5, OBJ_SIZE_32x16 | 0x1d3, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_VERTICAL | 0xbd, 0x1f3, OBJ_SPRITE_OAM | 0x3c0,
    OBJ_SHAPE_VERTICAL | 0xbe, OBJ_SIZE_16x32 | 0x1a3, OBJ_SPRITE_OAM | 0x36c,
    OBJ_SHAPE_VERTICAL | 0xc6, OBJ_SIZE_16x32 | 0x193, OBJ_SPRITE_OAM | 0x38a
};

const u16 sRidleyStatueOAM_Opening_Frame24[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xb2, OBJ_SIZE_64x32 | 0x1b4, OBJ_SPRITE_OAM | 0x34e,
    OBJ_SHAPE_HORIZONTAL | 0xd2, OBJ_SIZE_32x16 | 0x1b4, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xd2, OBJ_SIZE_32x16 | 0x1d4, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_VERTICAL | 0xba, 0x1f4, OBJ_SPRITE_OAM | 0x3c0,
    OBJ_SHAPE_VERTICAL | 0xba, OBJ_SIZE_16x32 | 0x1a4, OBJ_SPRITE_OAM | 0x36c,
    OBJ_SHAPE_VERTICAL | 0xc2, OBJ_SIZE_16x32 | 0x194, OBJ_SPRITE_OAM | 0x38a
};

const u16 sRidleyStatueOAM_Opening_Frame27[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xb1, OBJ_SIZE_64x32 | 0x1b5, OBJ_SPRITE_OAM | 0x34e,
    OBJ_SHAPE_HORIZONTAL | 0xd1, OBJ_SIZE_32x16 | 0x1b5, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xd1, OBJ_SIZE_32x16 | 0x1d5, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_VERTICAL | 0xb9, 0x1f5, OBJ_SPRITE_OAM | 0x3c0,
    OBJ_SHAPE_VERTICAL | 0xb9, OBJ_SIZE_16x32 | 0x1a5, OBJ_SPRITE_OAM | 0x36c,
    OBJ_SHAPE_VERTICAL | 0xc1, OBJ_SIZE_16x32 | 0x195, OBJ_SPRITE_OAM | 0x38a
};

const u16 sRidleyStatueOAM_Opening_Frame30[34] = {
    0xb,
    OBJ_SHAPE_HORIZONTAL | 0xb0, OBJ_SIZE_32x8 | 0x19f, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xaf, OBJ_SIZE_32x8 | 0x1bf, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xb8, OBJ_SIZE_32x16 | 0x197, OBJ_SPRITE_OAM | 0x233,
    0xb7, OBJ_SIZE_16x16 | 0x1b7, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xc7, 0x1af, OBJ_SPRITE_OAM | 0x276,
    OBJ_SHAPE_VERTICAL | 0xc6, 0x1bf, OBJ_SPRITE_OAM | 0x278,
    0xb6, OBJ_SIZE_32x32 | 0x1c7, OBJ_SPRITE_OAM | 0x239,
    OBJ_SHAPE_HORIZONTAL | 0xd6, 0x1c7, OBJ_SPRITE_OAM | 0x2b9,
    OBJ_SHAPE_HORIZONTAL | 0xd6, OBJ_SIZE_32x16 | 0x1d7, OBJ_SPRITE_OAM | 0x2bb,
    OBJ_SHAPE_VERTICAL | 0xb6, OBJ_SIZE_16x32 | 0x1e7, OBJ_SPRITE_OAM | 0x23d,
    OBJ_SHAPE_VERTICAL | 0xc6, 0x1f7, OBJ_SPRITE_OAM | 0x27f
};

const u16 sRidleyStatueOAM_Opening_Frame31[34] = {
    0xb,
    OBJ_SHAPE_HORIZONTAL | 0xad, OBJ_SIZE_32x8 | 0x1a0, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xac, OBJ_SIZE_32x8 | 0x1c0, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xb5, OBJ_SIZE_32x16 | 0x198, OBJ_SPRITE_OAM | 0x233,
    0xb4, OBJ_SIZE_16x16 | 0x1b8, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xc4, 0x1b0, OBJ_SPRITE_OAM | 0x276,
    OBJ_SHAPE_VERTICAL | 0xc4, 0x1c0, OBJ_SPRITE_OAM | 0x278,
    0xb4, OBJ_SIZE_32x32 | 0x1c8, OBJ_SPRITE_OAM | 0x239,
    OBJ_SHAPE_HORIZONTAL | 0xd4, 0x1c8, OBJ_SPRITE_OAM | 0x2b9,
    OBJ_SHAPE_HORIZONTAL | 0xd4, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x2bb,
    OBJ_SHAPE_VERTICAL | 0xb4, OBJ_SIZE_16x32 | 0x1e8, OBJ_SPRITE_OAM | 0x23d,
    OBJ_SHAPE_VERTICAL | 0xc4, 0x1f8, OBJ_SPRITE_OAM | 0x27f
};

const u16 sRidleyStatueOAM_Opening_Frame32[37] = {
    0xb,
    OBJ_SHAPE_HORIZONTAL | 0xab, OBJ_SIZE_32x8 | 0x1a1, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xab, OBJ_SIZE_32x8 | 0x1c1, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xb3, OBJ_SIZE_32x16 | 0x199, OBJ_SPRITE_OAM | 0x233,
    0xb3, OBJ_SIZE_16x16 | 0x1b9, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xc3, 0x1b1, OBJ_SPRITE_OAM | 0x276,
    OBJ_SHAPE_VERTICAL | 0xc3, 0x1c1, OBJ_SPRITE_OAM | 0x278,
    0xb3, OBJ_SIZE_32x32 | 0x1c9, OBJ_SPRITE_OAM | 0x239,
    OBJ_SHAPE_HORIZONTAL | 0xd3, 0x1c9, OBJ_SPRITE_OAM | 0x2b9,
    OBJ_SHAPE_HORIZONTAL | 0xd3, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2bb,
    OBJ_SHAPE_VERTICAL | 0xb3, OBJ_SIZE_16x32 | 0x1e9, OBJ_SPRITE_OAM | 0x23d,
    OBJ_SHAPE_VERTICAL | 0xc3, 0x1f9, OBJ_SPRITE_OAM | 0x27f
};

const u16 sRidleyStatueOAM_Opening_Frame41[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xb7, 0x1c6, OBJ_SPRITE_OAM | 0x2c9,
    OBJ_SHAPE_HORIZONTAL | 0xab, OBJ_SIZE_32x8 | 0x1a1, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xab, OBJ_SIZE_32x8 | 0x1c1, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xb3, OBJ_SIZE_32x16 | 0x199, OBJ_SPRITE_OAM | 0x233,
    0xb3, OBJ_SIZE_16x16 | 0x1b9, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xc3, 0x1b1, OBJ_SPRITE_OAM | 0x276,
    OBJ_SHAPE_VERTICAL | 0xc3, 0x1c1, OBJ_SPRITE_OAM | 0x278,
    0xb3, OBJ_SIZE_32x32 | 0x1c9, OBJ_SPRITE_OAM | 0x239,
    OBJ_SHAPE_HORIZONTAL | 0xd3, 0x1c9, OBJ_SPRITE_OAM | 0x2b9,
    OBJ_SHAPE_HORIZONTAL | 0xd3, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2bb,
    OBJ_SHAPE_VERTICAL | 0xb3, OBJ_SIZE_16x32 | 0x1e9, OBJ_SPRITE_OAM | 0x23d,
    OBJ_SHAPE_VERTICAL | 0xc3, 0x1f9, OBJ_SPRITE_OAM | 0x27f
};

const u16 sRidleyStatueOAM_Opened_Frame0[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xb7, 0x1c6, OBJ_SPRITE_OAM | 0x320,
    OBJ_SHAPE_HORIZONTAL | 0xab, OBJ_SIZE_32x8 | 0x1a1, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xab, OBJ_SIZE_32x8 | 0x1c1, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xb3, OBJ_SIZE_32x16 | 0x199, OBJ_SPRITE_OAM | 0x233,
    0xb3, OBJ_SIZE_16x16 | 0x1b9, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xc3, 0x1b1, OBJ_SPRITE_OAM | 0x276,
    OBJ_SHAPE_VERTICAL | 0xc3, 0x1c1, OBJ_SPRITE_OAM | 0x278,
    0xb3, OBJ_SIZE_32x32 | 0x1c9, OBJ_SPRITE_OAM | 0x239,
    OBJ_SHAPE_HORIZONTAL | 0xd3, 0x1c9, OBJ_SPRITE_OAM | 0x2b9,
    OBJ_SHAPE_HORIZONTAL | 0xd3, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2bb,
    OBJ_SHAPE_VERTICAL | 0xb3, OBJ_SIZE_16x32 | 0x1e9, OBJ_SPRITE_OAM | 0x23d,
    OBJ_SHAPE_VERTICAL | 0xc3, 0x1f9, OBJ_SPRITE_OAM | 0x27f
};

const struct FrameData sKraidStatueOAM_Idle[2] = {
    sKraidStatueOAM_Idle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sKraidStatueOAM_Activating[13] = {
    sKraidStatueOAM_Activating_Frame0,
    0x4,
    sKraidStatueOAM_Activating_Frame1,
    0x4,
    sKraidStatueOAM_Activating_Frame2,
    0x4,
    sKraidStatueOAM_Activating_Frame3,
    0x4,
    sKraidStatueOAM_Activating_Frame4,
    0x6,
    sKraidStatueOAM_Activating_Frame5,
    0x6,
    sKraidStatueOAM_Activating_Frame6,
    0x6,
    sKraidStatueOAM_Activating_Frame7,
    0x6,
    sKraidStatueOAM_Activating_Frame6,
    0x6,
    sKraidStatueOAM_Activating_Frame5,
    0x6,
    sKraidStatueOAM_Activating_Frame4,
    0x6,
    sKraidStatueOAM_Activating_Frame3,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sKraidStatueOAM_Activated[7] = {
    sKraidStatueOAM_Activating_Frame3,
    0xC,
    sKraidStatueOAM_Activating_Frame4,
    0xC,
    sKraidStatueOAM_Activating_Frame5,
    0xC,
    sKraidStatueOAM_Activating_Frame4,
    0xC,
    sKraidStatueOAM_Activating_Frame3,
    0xC,
    sKraidStatueOAM_Activated_Frame5,
    0xC,
    NULL,
    0x0
};

const struct FrameData sKraidStatueOAM_Opening[43] = {
    sKraidStatueOAM_Activating_Frame4,
    0x6,
    sKraidStatueOAM_Activating_Frame5,
    0x6,
    sKraidStatueOAM_Activating_Frame6,
    0x6,
    sKraidStatueOAM_Activating_Frame7,
    0x6,
    sKraidStatueOAM_Activating_Frame6,
    0x6,
    sKraidStatueOAM_Activating_Frame5,
    0x6,
    sKraidStatueOAM_Activating_Frame4,
    0x6,
    sKraidStatueOAM_Activating_Frame3,
    0x3C,
    sKraidStatueOAM_Opening_Frame8,
    0x4,
    sKraidStatueOAM_Activating_Frame3,
    0x4,
    sKraidStatueOAM_Opening_Frame8,
    0x4,
    sKraidStatueOAM_Opening_Frame11,
    0x4,
    sKraidStatueOAM_Opening_Frame14,
    0x4,
    sKraidStatueOAM_Opening_Frame11,
    0x4,
    sKraidStatueOAM_Opening_Frame14,
    0x4,
    sKraidStatueOAM_Opening_Frame17,
    0x4,
    sKraidStatueOAM_Opening_Frame14,
    0x4,
    sKraidStatueOAM_Opening_Frame17,
    0x4,
    sKraidStatueOAM_Opening_Frame20,
    0x4,
    sKraidStatueOAM_Opening_Frame21,
    0x4,
    sKraidStatueOAM_Opening_Frame20,
    0x4,
    sKraidStatueOAM_Opening_Frame21,
    0x4,
    sKraidStatueOAM_Opening_Frame24,
    0x4,
    sKraidStatueOAM_Opening_Frame21,
    0x4,
    sKraidStatueOAM_Opening_Frame24,
    0x4,
    sKraidStatueOAM_Opening_Frame27,
    0x4,
    sKraidStatueOAM_Opening_Frame24,
    0x4,
    sKraidStatueOAM_Opening_Frame27,
    0x4,
    sKraidStatueOAM_Opening_Frame30,
    0x4,
    sKraidStatueOAM_Opening_Frame31,
    0x4,
    sKraidStatueOAM_Opening_Frame32,
    0x4,
    sKraidStatueOAM_Opening_Frame31,
    0x4,
    sKraidStatueOAM_Opening_Frame32,
    0x4,
    sKraidStatueOAM_Opening_Frame31,
    0x4,
    sKraidStatueOAM_Opening_Frame32,
    0x6,
    sKraidStatueOAM_Opening_Frame31,
    0x6,
    sKraidStatueOAM_Opening_Frame32,
    0x6,
    sKraidStatueOAM_Opening_Frame31,
    0x6,
    sKraidStatueOAM_Opening_Frame32,
    0x28,
    sKraidStatueOAM_Opening_Frame41,
    0x6,
    NULL,
    0x0
};

const struct FrameData sKraidStatueOAM_Opened[2] = {
    sKraidStatueOAM_Opened_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRidleyStatueOAM_Idle[2] = {
    sRidleyStatueOAM_Idle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRidleyStatueOAM_Activating[13] = {
    sRidleyStatueOAM_Activating_Frame0,
    0x4,
    sRidleyStatueOAM_Activating_Frame1,
    0x4,
    sRidleyStatueOAM_Activating_Frame2,
    0x4,
    sRidleyStatueOAM_Activating_Frame3,
    0x4,
    sRidleyStatueOAM_Activating_Frame4,
    0x6,
    sRidleyStatueOAM_Activating_Frame5,
    0x6,
    sRidleyStatueOAM_Activating_Frame6,
    0x6,
    sRidleyStatueOAM_Activating_Frame7,
    0x6,
    sRidleyStatueOAM_Activating_Frame6,
    0x6,
    sRidleyStatueOAM_Activating_Frame5,
    0x6,
    sRidleyStatueOAM_Activating_Frame4,
    0x6,
    sRidleyStatueOAM_Activating_Frame3,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRidleyStatueOAM_Activated[7] = {
    sRidleyStatueOAM_Activating_Frame3,
    0xC,
    sRidleyStatueOAM_Activating_Frame4,
    0xC,
    sRidleyStatueOAM_Activating_Frame5,
    0xC,
    sRidleyStatueOAM_Activating_Frame4,
    0xC,
    sRidleyStatueOAM_Activating_Frame3,
    0xC,
    sRidleyStatueOAM_Activated_Frame5,
    0xC,
    NULL,
    0x0
};

const struct FrameData sRidleyStatueOAM_Opening[43] = {
    sRidleyStatueOAM_Activating_Frame4,
    0x6,
    sRidleyStatueOAM_Activating_Frame5,
    0x6,
    sRidleyStatueOAM_Activating_Frame6,
    0x6,
    sRidleyStatueOAM_Activating_Frame7,
    0x6,
    sRidleyStatueOAM_Activating_Frame6,
    0x6,
    sRidleyStatueOAM_Activating_Frame5,
    0x6,
    sRidleyStatueOAM_Activating_Frame4,
    0x6,
    sRidleyStatueOAM_Activating_Frame3,
    0x3C,
    sRidleyStatueOAM_Opening_Frame8,
    0x4,
    sRidleyStatueOAM_Activating_Frame3,
    0x4,
    sRidleyStatueOAM_Opening_Frame8,
    0x4,
    sRidleyStatueOAM_Opening_Frame11,
    0x4,
    sRidleyStatueOAM_Opening_Frame14,
    0x4,
    sRidleyStatueOAM_Opening_Frame11,
    0x4,
    sRidleyStatueOAM_Opening_Frame14,
    0x4,
    sRidleyStatueOAM_Opening_Frame17,
    0x4,
    sRidleyStatueOAM_Opening_Frame14,
    0x4,
    sRidleyStatueOAM_Opening_Frame17,
    0x4,
    sRidleyStatueOAM_Opening_Frame20,
    0x4,
    sRidleyStatueOAM_Opening_Frame21,
    0x4,
    sRidleyStatueOAM_Opening_Frame20,
    0x4,
    sRidleyStatueOAM_Opening_Frame21,
    0x4,
    sRidleyStatueOAM_Opening_Frame24,
    0x4,
    sRidleyStatueOAM_Opening_Frame21,
    0x4,
    sRidleyStatueOAM_Opening_Frame24,
    0x4,
    sRidleyStatueOAM_Opening_Frame27,
    0x4,
    sRidleyStatueOAM_Opening_Frame24,
    0x4,
    sRidleyStatueOAM_Opening_Frame27,
    0x4,
    sRidleyStatueOAM_Opening_Frame30,
    0x4,
    sRidleyStatueOAM_Opening_Frame31,
    0x4,
    sRidleyStatueOAM_Opening_Frame32,
    0x4,
    sRidleyStatueOAM_Opening_Frame31,
    0x4,
    sRidleyStatueOAM_Opening_Frame32,
    0x4,
    sRidleyStatueOAM_Opening_Frame31,
    0x4,
    sRidleyStatueOAM_Opening_Frame32,
    0x6,
    sRidleyStatueOAM_Opening_Frame31,
    0x6,
    sRidleyStatueOAM_Opening_Frame32,
    0x6,
    sRidleyStatueOAM_Opening_Frame31,
    0x6,
    sRidleyStatueOAM_Opening_Frame32,
    0x28,
    sRidleyStatueOAM_Opening_Frame41,
    0x6,
    NULL,
    0x0
};

const struct FrameData sRidleyStatueOAM_Opened[2] = {
    sRidleyStatueOAM_Opened_Frame0,
    0xFF,
    NULL,
    0x0
};


void BossStatueVerticalLignChangeCCAA(u8 caa)
{
    // https://decomp.me/scratch/RnGpx

    /*u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - (BLOCK_SIZE / 2);
    xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 8); // /!\ Weird maths
    gCurrentClipdataAffectingAction = caa;
    
    ClipdataProcess(yPosition, xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 2), xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 3), xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 4), xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 5), xPosition);*/
}

void KraidStatueHorizontalLignThreeChangeCCAA(u8 caa)
{

}

void KraidStatueHorizontalLignHeightChangeCCAA(u8 caa)
{

}

/**
 * @brief 49314 | 28 | Initializes the kraid statue to be opened
 * 
 */
void KraidStatueOpenedInit(void)
{
    gCurrentSprite.pOam = sKraidStatueOAM_Opened;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.pose = BOSS_STATUE_POSE_IDLE;
    KraidStatueHorizontalLignThreeChangeCCAA(CCAA_MAKE_SOLID3);
}

/**
 * @brief 4933c | c8 | Initializes a kraid statue sprite
 * 
 */
void KraidStatueInit(void)
{
    gCurrentSprite.xPosition -= 0x20;

    gCurrentSprite.drawDistanceTopOffset = 0x60;
    gCurrentSprite.drawDistanceBottomOffset = 0x0;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x70;

    gCurrentSprite.hitboxTopOffset = 0x0;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = 0x0;
    gCurrentSprite.hitboxRightOffset = 0x0;

    gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
    gCurrentSprite.drawOrder = 0x1;
    gCurrentSprite.samusCollision = SSC_NONE;

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_VIEWED_STATUE_ROOM))
        EventFunction(EVENT_ACTION_SETTING, EVENT_VIEWED_STATUE_ROOM); // Set viewed statue room event if not set

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_STATUE_OPENED))
        KraidStatueOpenedInit(); // Set opened
    else
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_KILLED))
        {
            // Set ready to open
            gCurrentSprite.pOam = sKraidStatueOAM_Activated;
            gCurrentSprite.pose = BOSS_STATUE_POSE_CHECK_START_OPEN;
            gDoorUnlockTimer = 0x1;
        }
        else
        {
            // Kraid not dead, set idle
            gCurrentSprite.pOam = sKraidStatueOAM_Idle;
            gCurrentSprite.pose = BOSS_STATUE_POSE_IDLE;
        }
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        KraidStatueHorizontalLignHeightChangeCCAA(CCAA_MAKE_SOLID3);
    }
}

/**
 * @brief 49404 | 70 | Checks if the background is locked
 * 
 */
void KraidStatueCheckBackgroundLocked(void)
{
    u16 spriteX;
    u16 bgX;

    if (gCurrentSprite.currentAnimationFrame == 0x0 && gCurrentSprite.animationDurationCounter == 0x1)
        SoundPlay(0x12A);

    spriteX = gCurrentSprite.xPosition + 0x20;
    spriteX /= 4;

    bgX = gBG1XPosition / 4;

    if ((u16)(spriteX - bgX) == 0x78) // Sprite is 0x78 pixels from lock screen center
    {
        // Set opening behavior
        gCurrentSprite.pose = BOSS_STATUE_POSE_OPENING;
        gCurrentSprite.pOam = sKraidStatueOAM_Opening;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.workVariable = 0x0;
        gCurrentSprite.workVariable2 = 0x0;
        SoundPlay(0x12B);
        BossStatueVerticalLignChangeCCAA(CCAA_MAKE_SOLID3);
    }
}

void KraidStatueOpening(void)
{

}

void RidleyStatueChangeThreeCCAA(u8 caa)
{

}

void RidleyStatueChangeFourCCAA(u8 caa)
{

}

/**
 * @brief 49714 | 28 | Initializes the ridley statue to be opened
 * 
 */
void RidleyStatueOpenedInit(void)
{
    gCurrentSprite.pOam = sRidleyStatueOAM_Opened;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.pose = BOSS_STATUE_POSE_IDLE;
    RidleyStatueChangeThreeCCAA(CCAA_MAKE_SOLID3);
}

/**
 * @brief 4973c | b4 | Initializes a ridley statue sprite
 * 
 */
void RidleyStatueInit(void)
{
    gCurrentSprite.xPosition += (BLOCK_SIZE / 2);

    gCurrentSprite.drawDistanceTopOffset = 0x58;
    gCurrentSprite.drawDistanceBottomOffset = 0x0;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x70;

    gCurrentSprite.hitboxTopOffset = 0x0;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = 0x0;
    gCurrentSprite.hitboxRightOffset = 0x0;

    gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
    gCurrentSprite.drawOrder = 0x1;
    gCurrentSprite.samusCollision = SSC_NONE;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_STATUE_OPENED))
        RidleyStatueOpenedInit(); // Set opened
    else
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_KILLED))
        {
            // Set ready to open
            gCurrentSprite.pOam = sRidleyStatueOAM_Activated;
            gCurrentSprite.pose = BOSS_STATUE_POSE_CHECK_START_OPEN;
            gDoorUnlockTimer = 0x1;
        }
        else
        {
            // Ridley not dead, set idle
            gCurrentSprite.pOam = sRidleyStatueOAM_Idle;
            gCurrentSprite.pose = BOSS_STATUE_POSE_IDLE;
        }
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        RidleyStatueChangeFourCCAA(CCAA_MAKE_SOLID3);
    }
}

/**
 * @brief 497f0 | 54 | Checks if the background is locked
 * 
 */
void RidleyStatueCheckBackgroundLocked(void)
{
    u16 spriteX;
    u16 bgX;

    if (gCurrentSprite.currentAnimationFrame == 0x0 && gCurrentSprite.animationDurationCounter == 0x1)
        SoundPlay(0x12A);

    spriteX = gCurrentSprite.xPosition + 0x20;
    spriteX /= 4;

    bgX = gBG1XPosition / 4;

    if ((u16)(spriteX - bgX) == 0x78) // Sprite is 0x78 pixels from lock screen center
    {
        // Set opening behavior
        gCurrentSprite.pose = BOSS_STATUE_POSE_OPENING;
        gCurrentSprite.timer = 0x3C;
        BossStatueVerticalLignChangeCCAA(CCAA_MAKE_SOLID3);
    }
}

void RidleyStatueOpening(void)
{
    // https://decomp.me/scratch/VKylc

    /*u8 rngParam1;
    u8 rngParam2;
    u32 rngParam3;
    u16 yPosition;
    u16 xPosition;
    u32 temp;

    if (gSamusData.xPosition > gCurrentSprite.xPosition + 0x220)
        BossStatueVerticalLignChangeCCAA(CCAA_REMOVE_SOLID);
    
    if (gCurrentSprite.timer != 0x0)
    {
        if (gCurrentSprite.currentAnimationFrame == 0x0 && gCurrentSprite.animationDurationCounter == 0x1)
            SoundPlay(0x12A);

        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            gCurrentSprite.pOam = sRidleyStatueOAM_Opening;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.workVariable = 0x0;
            gCurrentSprite.workVariable2 = 0x0;
            SoundPlay(0x21C);
        }
    }
    else
    {
        if (gCurrentSprite.currentAnimationFrame == 0x1D && gCurrentSprite.animationDurationCounter == 0x1)
            RidleyStatueChangeFourCCAA(CCAA_REMOVE_SOLID);

        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            RidleyStatueOpenedInit();
            EventFunction(EVENT_ACTION_SETTING, EVENT_RIDLEY_STATUE_OPENED);
            gDoorUnlockTimer = -0x14;
            BossStatueVerticalLignChangeCCAA(CCAA_REMOVE_SOLID);
        }
        else if ((u16)(gCurrentSprite.currentAnimationFrame - 0x9) < 0x1F)
        {
            gCurrentSprite.workVariable2++;
            if (!(gCurrentSprite.workVariable++ & 0x1F))
                ScreenShakeStartVertical(0xA, 0x81);

            rngParam1 = gCurrentSprite.workVariable;
            rngParam2 = gCurrentSprite.workVariable2;

            yPosition = gBG1YPosition - BLOCK_SIZE;
            xPosition = gBG1XPosition + 0x190;

            rngParam3 = gSpriteRNG;

            if (!(rngParam2 & 0x1F))
            {
                if (rngParam2 & 0x20)
                {
                    temp = rngParam3 * 0x10 - 0x78;
                    SpriteDebrisInit(0x0, 0x5, yPosition, xPosition - temp);
                    temp = rngParam3 * 0x8 - 0x190;
                    SpriteDebrisInit(0x0, 0x8, yPosition, xPosition + temp);
                }
                else
                {
                    temp = rngParam3 * 0x10 + 0xA0;
                    SpriteDebrisInit(0x0, 0x7, yPosition, xPosition - temp);
                    temp = rngParam3 * 0x8 - 0x12C;
                    SpriteDebrisInit(0x0, 0x5, yPosition, xPosition + temp);
                }
            }

            if (!(rngParam1 & 0xF))
            {
                if (rngParam3 > 0x7)
                {
                    temp = rngParam3 * 0x20 - 0x1C2;
                    SpriteDebrisInit(0x0, 0x8, yPosition, xPosition + temp);
                    temp = rngParam3 * 0x20 - 0x24E;
                    SpriteDebrisInit(0x0, 0x6, yPosition, xPosition - temp);
                }
                else
                {
                    temp = rngParam3 * 0x20 - 0x17C;
                    SpriteDebrisInit(0x0, 0x6, yPosition, xPosition - temp);
                    temp = rngParam3 * 0x8 - 0x278;
                    SpriteDebrisInit(0x0, 0x8, yPosition, xPosition + temp);
                }
            }
        }
    }*/
}

/**
 * @brief 49a38 | 118 | Kraid statue AI
 * 
 */
void KraidStatue(void)
{
    struct ProjectileData* pProj;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            KraidStatueInit();
            break;

        case BOSS_STATUE_POSE_CHECK_START_OPEN:
            KraidStatueCheckBackgroundLocked();
            break;

        case BOSS_STATUE_POSE_OPENING:
            KraidStatueOpening();
            break;
    }

    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
    {
        if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 10, BLOCK_SIZE * 13) != NSLR_OUT_OF_RANGE)
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN;
    }

    for (pProj = gProjectileData; pProj < gProjectileData + 16; pProj++)
    {
        if (pProj->status & PROJ_STATUS_EXISTS)
            pProj->status |= PROJ_STATUS_UNKNOWN;
    }

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_STATUE_OPENED) && EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_STATUE_OPENED))
    {
        if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 10, 0x190) == NSLR_OUT_OF_RANGE)
            gLockScreen.lock = FALSE;
        else
        {
            gLockScreen.lock = TRUE;
            gLockScreen.xPositionCenter = gCurrentSprite.xPosition + (BLOCK_SIZE / 2);
            gLockScreen.yPositionCenter = gCurrentSprite.yPosition;
        }
    }
    else
    {
        if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 10, 0x1F0) != NSLR_RIGHT)
            gLockScreen.lock = FALSE;
        else
        {
            gLockScreen.lock = TRUE;
            gLockScreen.xPositionCenter = gCurrentSprite.xPosition + (BLOCK_SIZE / 2);
            gLockScreen.yPositionCenter = gCurrentSprite.yPosition;
        }
    }
}

/**
 * @brief 49b50 | 80 | Ridley statue AI
 * 
 */
void RidleyStatue(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            RidleyStatueInit();
            break;

        case BOSS_STATUE_POSE_CHECK_START_OPEN:
            RidleyStatueCheckBackgroundLocked();
            break;

        case BOSS_STATUE_POSE_OPENING:
            RidleyStatueOpening();
            break;
    }

    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
    {
        if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 10, BLOCK_SIZE * 13) != NSLR_OUT_OF_RANGE)
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN;
    }
}