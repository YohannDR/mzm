#include "data/sprites/boss_statues.h"

#include "macros.h"

const u32 sBossStatuesGfx[2388] = INCBIN_U32("data/sprites/BossStatues.gfx.lz");
const u16 sBossStatuesPal[128] = INCBIN_U16("data/sprites/BossStatues.pal");

const u16 sKraidStatueOam_Idle_Frame0[OAM_DATA_SIZE(5)] = {
    0x5,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x25f,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOam_Activating_Frame0[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x30c,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x25f,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x21c,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOam_Activating_Frame1[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x30e,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x25f,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x21e,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOam_Activating_Frame2[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x32e,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x25f,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x296,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOam_Activating_Frame3[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x310,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x2b6,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x2bf,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOam_Activating_Frame4[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x330,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x2d6,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x2df,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOam_Activating_Frame5[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x312,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x2f6,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x31f,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOam_Activating_Frame6[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x332,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x2d8,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x33f,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOam_Activating_Frame7[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x314,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x2f8,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x2da,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOam_Activated_Frame5[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x40, OBJ_SPRITE_OAM | 0x334,
    0xc8, 0x50, OBJ_SPRITE_OAM | 0x2bf,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x48, OBJ_SPRITE_OAM | 0x2fa,
    0xb8, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf4, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOam_Opening_Frame8[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd7, 0x40, OBJ_SPRITE_OAM | 0x310,
    OBJ_SHAPE_HORIZONTAL | 0xcf, 0x48, OBJ_SPRITE_OAM | 0x2b6,
    0xc7, 0x50, OBJ_SPRITE_OAM | 0x2bf,
    0xb7, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_8x32 | 0x50, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd3, OBJ_SIZE_16x32 | 0x58, OBJ_SPRITE_OAM | 0x274,
    0xf3, 0x60, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOam_Opening_Frame11[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd6, 0x3f, OBJ_SPRITE_OAM | 0x310,
    OBJ_SHAPE_HORIZONTAL | 0xce, 0x47, OBJ_SPRITE_OAM | 0x2b6,
    0xc6, 0x4f, OBJ_SPRITE_OAM | 0x2bf,
    0xb6, OBJ_SIZE_64x64 | 0xf, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_8x32 | 0x4f, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd2, OBJ_SIZE_16x32 | 0x57, OBJ_SPRITE_OAM | 0x274,
    0xf2, 0x5f, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOam_Opening_Frame14[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd5, 0x3f, OBJ_SPRITE_OAM | 0x310,
    OBJ_SHAPE_HORIZONTAL | 0xcd, 0x47, OBJ_SPRITE_OAM | 0x2b6,
    0xc5, 0x4f, OBJ_SPRITE_OAM | 0x2bf,
    0xb5, OBJ_SIZE_64x64 | 0xf, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xcd, OBJ_SIZE_8x32 | 0x4f, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd1, OBJ_SIZE_16x32 | 0x57, OBJ_SPRITE_OAM | 0x274,
    0xf1, 0x5f, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOam_Opening_Frame17[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xd4, 0x3e, OBJ_SPRITE_OAM | 0x310,
    OBJ_SHAPE_HORIZONTAL | 0xcc, 0x46, OBJ_SPRITE_OAM | 0x2b6,
    0xc4, 0x4e, OBJ_SPRITE_OAM | 0x2bf,
    0xb4, OBJ_SIZE_64x64 | 0xe, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xcc, OBJ_SIZE_8x32 | 0x4e, OBJ_SPRITE_OAM | 0x273,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x56, OBJ_SPRITE_OAM | 0x274,
    0xf0, 0x5e, OBJ_SPRITE_OAM | 0x2f5
};

const u16 sKraidStatueOam_Opening_Frame20[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xbc, 0x7, OBJ_SPRITE_OAM | 0x3c1,
    0xb4, OBJ_SIZE_64x64 | 0xf, OBJ_SPRITE_OAM | 0x316,
    OBJ_SHAPE_VERTICAL | 0xbe, OBJ_SIZE_8x32 | 0x4f, OBJ_SPRITE_OAM | 0x31e,
    OBJ_SHAPE_VERTICAL | 0xbc, OBJ_SIZE_16x32 | 0x57, OBJ_SPRITE_OAM | 0x39e,
    OBJ_SHAPE_VERTICAL | 0xcf, 0x67, OBJ_SPRITE_OAM | 0x35f
};

const u16 sKraidStatueOam_Opening_Frame21[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xba, 0x6, OBJ_SPRITE_OAM | 0x3c1,
    0xb2, OBJ_SIZE_64x64 | 0xe, OBJ_SPRITE_OAM | 0x316,
    OBJ_SHAPE_VERTICAL | 0xbb, OBJ_SIZE_8x32 | 0x4e, OBJ_SPRITE_OAM | 0x31e,
    OBJ_SHAPE_VERTICAL | 0xb9, OBJ_SIZE_16x32 | 0x56, OBJ_SPRITE_OAM | 0x39e,
    OBJ_SHAPE_VERTICAL | 0xcc, 0x66, OBJ_SPRITE_OAM | 0x35f
};

const u16 sKraidStatueOam_Opening_Frame24[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xb7, 0x5, OBJ_SPRITE_OAM | 0x3c1,
    0xaf, OBJ_SIZE_64x64 | 0xd, OBJ_SPRITE_OAM | 0x316,
    OBJ_SHAPE_VERTICAL | 0xb7, OBJ_SIZE_8x32 | 0x4d, OBJ_SPRITE_OAM | 0x31e,
    OBJ_SHAPE_VERTICAL | 0xb4, OBJ_SIZE_16x32 | 0x55, OBJ_SPRITE_OAM | 0x39e,
    OBJ_SHAPE_VERTICAL | 0xc7, 0x65, OBJ_SPRITE_OAM | 0x35f
};

const u16 sKraidStatueOam_Opening_Frame27[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xb6, 0x4, OBJ_SPRITE_OAM | 0x3c1,
    0xae, OBJ_SIZE_64x64 | 0xc, OBJ_SPRITE_OAM | 0x316,
    OBJ_SHAPE_VERTICAL | 0xb6, OBJ_SIZE_8x32 | 0x4c, OBJ_SPRITE_OAM | 0x31e,
    OBJ_SHAPE_VERTICAL | 0xb3, OBJ_SIZE_16x32 | 0x54, OBJ_SPRITE_OAM | 0x39e,
    OBJ_SHAPE_VERTICAL | 0xc6, 0x64, OBJ_SPRITE_OAM | 0x35f
};

const u16 sKraidStatueOam_Opening_Frame30[OAM_DATA_SIZE(6)] = {
    0x6,
    0xab, OBJ_SIZE_64x64 | 0xe, OBJ_SPRITE_OAM | 0x302,
    OBJ_SHAPE_VERTICAL | 0xc3, 0x1fe, OBJ_SPRITE_OAM | 0x360,
    OBJ_SHAPE_VERTICAL | 0xbb, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x341,
    0xa5, 0x4e, OBJ_SPRITE_OAM | 0x2ea,
    OBJ_SHAPE_VERTICAL | 0xad, OBJ_SIZE_16x32 | 0x4e, OBJ_SPRITE_OAM | 0x30a,
    0xb5, OBJ_SIZE_16x16 | 0x5e, OBJ_SPRITE_OAM | 0x32c
};

const u16 sKraidStatueOam_Opening_Frame31[OAM_DATA_SIZE(6)] = {
    0x6,
    0xa9, OBJ_SIZE_64x64 | 0xd, OBJ_SPRITE_OAM | 0x302,
    OBJ_SHAPE_VERTICAL | 0xc1, 0x1fd, OBJ_SPRITE_OAM | 0x360,
    OBJ_SHAPE_VERTICAL | 0xb9, OBJ_SIZE_8x32 | 0x5, OBJ_SPRITE_OAM | 0x341,
    0xa2, 0x4d, OBJ_SPRITE_OAM | 0x2ea,
    OBJ_SHAPE_VERTICAL | 0xaa, OBJ_SIZE_16x32 | 0x4d, OBJ_SPRITE_OAM | 0x30a,
    0xb2, OBJ_SIZE_16x16 | 0x5d, OBJ_SPRITE_OAM | 0x32c
};

const u16 sKraidStatueOam_Opening_Frame32[OAM_DATA_SIZE(6)] = {
    0x6,
    0xa8, OBJ_SIZE_64x64 | 0xc, OBJ_SPRITE_OAM | 0x302,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x360,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x341,
    0xa0, 0x4c, OBJ_SPRITE_OAM | 0x2ea,
    OBJ_SHAPE_VERTICAL | 0xa8, OBJ_SIZE_16x32 | 0x4c, OBJ_SPRITE_OAM | 0x30a,
    0xb0, OBJ_SIZE_16x16 | 0x5c, OBJ_SPRITE_OAM | 0x32c
};

const u16 sKraidStatueOam_Opening_Frame41[OAM_DATA_SIZE(8)] = {
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

const u16 sKraidStatueOam_Opened_Frame0[OAM_DATA_SIZE(8)] = {
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

const u16 sRidleyStatueOam_Idle_Frame0[OAM_DATA_SIZE(8)] = {
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

const u16 sRidleyStatueOam_Activating_Frame0[OAM_DATA_SIZE(9)] = {
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

const u16 sRidleyStatueOam_Activating_Frame1[OAM_DATA_SIZE(9)] = {
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

const u16 sRidleyStatueOam_Activating_Frame2[OAM_DATA_SIZE(9)] = {
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

const u16 sRidleyStatueOam_Activating_Frame3[OAM_DATA_SIZE(9)] = {
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

const u16 sRidleyStatueOam_Activating_Frame4[OAM_DATA_SIZE(9)] = {
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

const u16 sRidleyStatueOam_Activating_Frame5[OAM_DATA_SIZE(9)] = {
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

const u16 sRidleyStatueOam_Activating_Frame6[OAM_DATA_SIZE(9)] = {
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

const u16 sRidleyStatueOam_Activating_Frame7[OAM_DATA_SIZE(9)] = {
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

const u16 sRidleyStatueOam_Activated_Frame5[OAM_DATA_SIZE(9)] = {
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

const u16 sRidleyStatueOam_Opening_Frame8[OAM_DATA_SIZE(9)] = {
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

const u16 sRidleyStatueOam_Opening_Frame11[OAM_DATA_SIZE(9)] = {
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

const u16 sRidleyStatueOam_Opening_Frame14[OAM_DATA_SIZE(9)] = {
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

const u16 sRidleyStatueOam_Opening_Frame17[OAM_DATA_SIZE(9)] = {
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

const u16 sRidleyStatueOam_Opening_Frame20[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xb7, OBJ_SIZE_64x32 | 0x1b2, OBJ_SPRITE_OAM | 0x34e,
    OBJ_SHAPE_HORIZONTAL | 0xd7, OBJ_SIZE_32x16 | 0x1b2, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xd7, OBJ_SIZE_32x16 | 0x1d2, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_VERTICAL | 0xbf, 0x1f2, OBJ_SPRITE_OAM | 0x3c0,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1a2, OBJ_SPRITE_OAM | 0x36c,
    OBJ_SHAPE_VERTICAL | 0xc9, OBJ_SIZE_16x32 | 0x192, OBJ_SPRITE_OAM | 0x38a
};

const u16 sRidleyStatueOam_Opening_Frame21[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xb5, OBJ_SIZE_64x32 | 0x1b3, OBJ_SPRITE_OAM | 0x34e,
    OBJ_SHAPE_HORIZONTAL | 0xd5, OBJ_SIZE_32x16 | 0x1b3, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xd5, OBJ_SIZE_32x16 | 0x1d3, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_VERTICAL | 0xbd, 0x1f3, OBJ_SPRITE_OAM | 0x3c0,
    OBJ_SHAPE_VERTICAL | 0xbe, OBJ_SIZE_16x32 | 0x1a3, OBJ_SPRITE_OAM | 0x36c,
    OBJ_SHAPE_VERTICAL | 0xc6, OBJ_SIZE_16x32 | 0x193, OBJ_SPRITE_OAM | 0x38a
};

const u16 sRidleyStatueOam_Opening_Frame24[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xb2, OBJ_SIZE_64x32 | 0x1b4, OBJ_SPRITE_OAM | 0x34e,
    OBJ_SHAPE_HORIZONTAL | 0xd2, OBJ_SIZE_32x16 | 0x1b4, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xd2, OBJ_SIZE_32x16 | 0x1d4, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_VERTICAL | 0xba, 0x1f4, OBJ_SPRITE_OAM | 0x3c0,
    OBJ_SHAPE_VERTICAL | 0xba, OBJ_SIZE_16x32 | 0x1a4, OBJ_SPRITE_OAM | 0x36c,
    OBJ_SHAPE_VERTICAL | 0xc2, OBJ_SIZE_16x32 | 0x194, OBJ_SPRITE_OAM | 0x38a
};

const u16 sRidleyStatueOam_Opening_Frame27[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xb1, OBJ_SIZE_64x32 | 0x1b5, OBJ_SPRITE_OAM | 0x34e,
    OBJ_SHAPE_HORIZONTAL | 0xd1, OBJ_SIZE_32x16 | 0x1b5, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xd1, OBJ_SIZE_32x16 | 0x1d5, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_VERTICAL | 0xb9, 0x1f5, OBJ_SPRITE_OAM | 0x3c0,
    OBJ_SHAPE_VERTICAL | 0xb9, OBJ_SIZE_16x32 | 0x1a5, OBJ_SPRITE_OAM | 0x36c,
    OBJ_SHAPE_VERTICAL | 0xc1, OBJ_SIZE_16x32 | 0x195, OBJ_SPRITE_OAM | 0x38a
};

const u16 sRidleyStatueOam_Opening_Frame30[OAM_DATA_SIZE(11)] = {
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

const u16 sRidleyStatueOam_Opening_Frame31[OAM_DATA_SIZE(11)] = {
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

const u16 sRidleyStatueOam_Opening_Frame32[OAM_DATA_SIZE(11)] = {
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

const u16 sRidleyStatueOam_Opening_Frame41[OAM_DATA_SIZE(12)] = {
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

const u16 sRidleyStatueOam_Opened_Frame0[OAM_DATA_SIZE(12)] = {
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

const struct FrameData sKraidStatueOam_Idle[2] = {
    [0] = {
        .pFrame = sKraidStatueOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKraidStatueOam_Activating[13] = {
    [0] = {
        .pFrame = sKraidStatueOam_Activating_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sKraidStatueOam_Activating_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sKraidStatueOam_Activating_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sKraidStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sKraidStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sKraidStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sKraidStatueOam_Activating_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [7] = {
        .pFrame = sKraidStatueOam_Activating_Frame7,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [8] = {
        .pFrame = sKraidStatueOam_Activating_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [9] = {
        .pFrame = sKraidStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [10] = {
        .pFrame = sKraidStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [11] = {
        .pFrame = sKraidStatueOam_Activating_Frame3,
        .timer = UCHAR_MAX
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKraidStatueOam_Activated[7] = {
    [0] = {
        .pFrame = sKraidStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sKraidStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sKraidStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sKraidStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = {
        .pFrame = sKraidStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sKraidStatueOam_Activated_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKraidStatueOam_Opening[43] = {
    [0] = {
        .pFrame = sKraidStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sKraidStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sKraidStatueOam_Activating_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sKraidStatueOam_Activating_Frame7,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sKraidStatueOam_Activating_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sKraidStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sKraidStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [7] = {
        .pFrame = sKraidStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(1.0f)
    },
    [8] = {
        .pFrame = sKraidStatueOam_Opening_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [9] = {
        .pFrame = sKraidStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = {
        .pFrame = sKraidStatueOam_Opening_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [11] = {
        .pFrame = sKraidStatueOam_Opening_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [12] = {
        .pFrame = sKraidStatueOam_Opening_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [13] = {
        .pFrame = sKraidStatueOam_Opening_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [14] = {
        .pFrame = sKraidStatueOam_Opening_Frame14,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [15] = {
        .pFrame = sKraidStatueOam_Opening_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [16] = {
        .pFrame = sKraidStatueOam_Opening_Frame14,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [17] = {
        .pFrame = sKraidStatueOam_Opening_Frame17,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [18] = {
        .pFrame = sKraidStatueOam_Opening_Frame14,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [19] = {
        .pFrame = sKraidStatueOam_Opening_Frame17,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [20] = {
        .pFrame = sKraidStatueOam_Opening_Frame20,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [21] = {
        .pFrame = sKraidStatueOam_Opening_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [22] = {
        .pFrame = sKraidStatueOam_Opening_Frame20,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [23] = {
        .pFrame = sKraidStatueOam_Opening_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [24] = {
        .pFrame = sKraidStatueOam_Opening_Frame24,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [25] = {
        .pFrame = sKraidStatueOam_Opening_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [26] = {
        .pFrame = sKraidStatueOam_Opening_Frame24,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [27] = {
        .pFrame = sKraidStatueOam_Opening_Frame27,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [28] = {
        .pFrame = sKraidStatueOam_Opening_Frame24,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [29] = {
        .pFrame = sKraidStatueOam_Opening_Frame27,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [30] = {
        .pFrame = sKraidStatueOam_Opening_Frame30,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [31] = {
        .pFrame = sKraidStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [32] = {
        .pFrame = sKraidStatueOam_Opening_Frame32,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [33] = {
        .pFrame = sKraidStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [34] = {
        .pFrame = sKraidStatueOam_Opening_Frame32,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [35] = {
        .pFrame = sKraidStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [36] = {
        .pFrame = sKraidStatueOam_Opening_Frame32,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [37] = {
        .pFrame = sKraidStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [38] = {
        .pFrame = sKraidStatueOam_Opening_Frame32,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [39] = {
        .pFrame = sKraidStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [40] = {
        .pFrame = sKraidStatueOam_Opening_Frame32,
        .timer = TWO_THIRD_SECOND
    },
    [41] = {
        .pFrame = sKraidStatueOam_Opening_Frame41,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [42] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKraidStatueOam_Opened[2] = {
    [0] = {
        .pFrame = sKraidStatueOam_Opened_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyStatueOam_Idle[2] = {
    [0] = {
        .pFrame = sRidleyStatueOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyStatueOam_Activating[13] = {
    [0] = {
        .pFrame = sRidleyStatueOam_Activating_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sRidleyStatueOam_Activating_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sRidleyStatueOam_Activating_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sRidleyStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sRidleyStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sRidleyStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sRidleyStatueOam_Activating_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [7] = {
        .pFrame = sRidleyStatueOam_Activating_Frame7,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [8] = {
        .pFrame = sRidleyStatueOam_Activating_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [9] = {
        .pFrame = sRidleyStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [10] = {
        .pFrame = sRidleyStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [11] = {
        .pFrame = sRidleyStatueOam_Activating_Frame3,
        .timer = UCHAR_MAX
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyStatueOam_Activated[7] = {
    [0] = {
        .pFrame = sRidleyStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sRidleyStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sRidleyStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sRidleyStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = {
        .pFrame = sRidleyStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sRidleyStatueOam_Activated_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyStatueOam_Opening[43] = {
    [0] = {
        .pFrame = sRidleyStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sRidleyStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sRidleyStatueOam_Activating_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sRidleyStatueOam_Activating_Frame7,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sRidleyStatueOam_Activating_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sRidleyStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sRidleyStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [7] = {
        .pFrame = sRidleyStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(1.0f)
    },
    [8] = {
        .pFrame = sRidleyStatueOam_Opening_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [9] = {
        .pFrame = sRidleyStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = {
        .pFrame = sRidleyStatueOam_Opening_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [11] = {
        .pFrame = sRidleyStatueOam_Opening_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [12] = {
        .pFrame = sRidleyStatueOam_Opening_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [13] = {
        .pFrame = sRidleyStatueOam_Opening_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [14] = {
        .pFrame = sRidleyStatueOam_Opening_Frame14,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [15] = {
        .pFrame = sRidleyStatueOam_Opening_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [16] = {
        .pFrame = sRidleyStatueOam_Opening_Frame14,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [17] = {
        .pFrame = sRidleyStatueOam_Opening_Frame17,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [18] = {
        .pFrame = sRidleyStatueOam_Opening_Frame14,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [19] = {
        .pFrame = sRidleyStatueOam_Opening_Frame17,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [20] = {
        .pFrame = sRidleyStatueOam_Opening_Frame20,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [21] = {
        .pFrame = sRidleyStatueOam_Opening_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [22] = {
        .pFrame = sRidleyStatueOam_Opening_Frame20,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [23] = {
        .pFrame = sRidleyStatueOam_Opening_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [24] = {
        .pFrame = sRidleyStatueOam_Opening_Frame24,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [25] = {
        .pFrame = sRidleyStatueOam_Opening_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [26] = {
        .pFrame = sRidleyStatueOam_Opening_Frame24,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [27] = {
        .pFrame = sRidleyStatueOam_Opening_Frame27,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [28] = {
        .pFrame = sRidleyStatueOam_Opening_Frame24,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [29] = {
        .pFrame = sRidleyStatueOam_Opening_Frame27,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [30] = {
        .pFrame = sRidleyStatueOam_Opening_Frame30,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [31] = {
        .pFrame = sRidleyStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [32] = {
        .pFrame = sRidleyStatueOam_Opening_Frame32,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [33] = {
        .pFrame = sRidleyStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [34] = {
        .pFrame = sRidleyStatueOam_Opening_Frame32,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [35] = {
        .pFrame = sRidleyStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [36] = {
        .pFrame = sRidleyStatueOam_Opening_Frame32,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [37] = {
        .pFrame = sRidleyStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [38] = {
        .pFrame = sRidleyStatueOam_Opening_Frame32,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [39] = {
        .pFrame = sRidleyStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [40] = {
        .pFrame = sRidleyStatueOam_Opening_Frame32,
        .timer = TWO_THIRD_SECOND
    },
    [41] = {
        .pFrame = sRidleyStatueOam_Opening_Frame41,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [42] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyStatueOam_Opened[2] = {
    [0] = {
        .pFrame = sRidleyStatueOam_Opened_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
