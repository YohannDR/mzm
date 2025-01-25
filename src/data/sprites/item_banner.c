#include "data/sprites/item_banner.h"
#include "macros.h"

const u32 sItemBannerGfx[139] = INCBIN_U32("data/sprites/ItemBanner.gfx.lz");
const u16 sItemBannerPal[32] = INCBIN_U16("data/sprites/ItemBanner.pal");

const u16 sSaveYesNoCursorOAM_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x21e
};

const u16 sSaveYesNoCursorOAM_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fd, OBJ_SPRITE_OAM | 0x21e
};

const u16 sSaveYesNoCursorOAM_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fe, OBJ_SPRITE_OAM | 0x21e
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, OBJ_SPRITE_OAM | 0x25c
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, OBJ_SPRITE_OAM | 0x25c
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1c8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x28, OBJ_SPRITE_OAM | 0x25c
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame3[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1a8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1c8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x48, OBJ_SPRITE_OAM | 0x25c
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame4[OAM_DATA_SIZE(8)] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x188, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1a8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1c8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x48, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x68, OBJ_SPRITE_OAM | 0x25c
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame5[OAM_DATA_SIZE(16)] = {
    0x10,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x188, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x264,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x268,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x26c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x270,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x274,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x278,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21f
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame6[OAM_DATA_SIZE(16)] = {
    0x10,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x188, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x264,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x268,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x26c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x270,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x274,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x278,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21c
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame7[OAM_DATA_SIZE(20)] = {
    0x14,
    0xf6, 0x188, OBJ_SPRITE_OAM | 0x21c,
    0x2, 0x188, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x188, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x248,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24c,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x250,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x254,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x258,
    0xf6, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21c,
    0x2, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21d
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame8[OAM_DATA_SIZE(20)] = {
    0x14,
    0xf4, 0x188, OBJ_SPRITE_OAM | 0x21c,
    0x4, 0x188, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x188, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x248,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x250,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x254,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x258,
    0xf4, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21c,
    0x4, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21d
};

const u16 sItemBannerOAM_TwoLinesSpawn_Frame9[OAM_DATA_SIZE(20)] = {
    0x14,
    0xf2, 0x188, OBJ_SPRITE_OAM | 0x21c,
    0x6, 0x188, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x188, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x244,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x248,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x250,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x254,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x258,
    0xf2, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21c,
    0x6, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21d
};

const u16 sItemBannerOAM_TwoLinesStatic_Frame0[OAM_DATA_SIZE(10)] = {
    0xa,
    0xf0, 0x188, OBJ_SPRITE_OAM | 0x21c,
    0x8, 0x188, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x188, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x10, OBJ_SPRITE_OAM | 0x210,
    0xf0, OBJ_SIZE_32x32 | 0x50, OBJ_SPRITE_OAM | 0x218,
    0xf0, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21c,
    0x8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21d
};

const u16 sItemBannerOAM_OneLineSpawn_Frame5[OAM_DATA_SIZE(8)] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x188, OBJ_SPRITE_OAM | 0x27c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1a8, OBJ_SPRITE_OAM | 0x27c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1c8, OBJ_SPRITE_OAM | 0x27c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x27c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x27c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x27c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x48, OBJ_SPRITE_OAM | 0x27c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x68, OBJ_SPRITE_OAM | 0x27c
};

const u16 sItemBannerOAM_OneLineSpawn_Frame6[OAM_DATA_SIZE(18)] = {
    0x12,
    0xfa, 0x188, OBJ_SPRITE_OAM | 0x21f,
    0xfa, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x264,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x268,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x26c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x270,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x274,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x278,
    0xfe, 0x188, OBJ_SPRITE_OAM | 0x23f,
    0xfe, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x23f
};

const u16 sItemBannerOAM_OneLineSpawn_Frame7[OAM_DATA_SIZE(16)] = {
    0x10,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x188, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x224,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x22c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x234,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x238,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21f
};

const u16 sItemBannerOAM_OneLineStatic_Frame0[OAM_DATA_SIZE(16)] = {
    0x10,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x188, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x190, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1b0, OBJ_SPRITE_OAM | 0x224,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x22c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x234,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x50, OBJ_SPRITE_OAM | 0x238,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x70, OBJ_SPRITE_OAM | 0x21c
};

const struct FrameData sSaveYesNoCursorOAM_Idle[5] = {
    [0] = {
        .pFrame = sSaveYesNoCursorOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sSaveYesNoCursorOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sSaveYesNoCursorOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sSaveYesNoCursorOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sItemBannerOAM_TwoLinesSpawn[11] = {
    [0] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame9,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sItemBannerOAM_TwoLinesRemoving[11] = {
    [0] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame9,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sItemBannerOAM_TwoLinesStatic[2] = {
    [0] = {
        .pFrame = sItemBannerOAM_TwoLinesStatic_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sItemBannerOAM_OneLineSpawn[9] = {
    [0] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sItemBannerOAM_OneLineSpawn_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sItemBannerOAM_OneLineSpawn_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sItemBannerOAM_OneLineSpawn_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sItemBannerOAM_OneLineRemoving[9] = {
    [0] = {
        .pFrame = sItemBannerOAM_OneLineSpawn_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sItemBannerOAM_OneLineSpawn_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sItemBannerOAM_OneLineSpawn_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sItemBannerOAM_TwoLinesSpawn_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sItemBannerOAM_OneLineStatic[2] = {
    [0] = {
        .pFrame = sItemBannerOAM_OneLineStatic_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
