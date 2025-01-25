#include "data/sprites/rising_chozo_pillar.h"
#include "macros.h"

const u32 sRisingChozoPillarGfx[671] = INCBIN_U32("data/sprites/RisingChozoPillar.gfx.lz");
const u16 sRisingChozoPillarPal[64] = INCBIN_U16("data/sprites/RisingChozoPillar.pal");

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x210
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x214
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame6[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame7[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame8[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x120c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame9[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1210,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame10[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame11[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame12[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame13[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x220c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame14[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2210,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame15[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame16[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame17[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame18[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x320c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame19[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3210,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame20[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame21[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame22[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1e8, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x10, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2f4,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2f4
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame23[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1e8, OBJ_SPRITE_OAM | 0x299,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x10, OBJ_SPRITE_OAM | 0x299,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2d4,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2d4
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame24[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x280
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame25[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x284
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame26[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x288
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawned_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28c
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x244
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x248
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24c
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x250
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1240,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x254
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame6[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1244,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame7[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1248,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame8[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x124c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame9[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1250,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame10[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2240,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1254,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame11[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2244,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame12[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2248,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame13[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x224c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame14[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2250,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame15[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3240,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2254,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame16[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3244,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame17[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3248,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame18[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x324c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame19[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3250,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame20[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3254,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame21[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame22[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1e8, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x10, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2f4,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2f4
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame23[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1e8, OBJ_SPRITE_OAM | 0x299,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x10, OBJ_SPRITE_OAM | 0x299,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2d4,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2d4
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame24[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c0
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame25[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c4
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame26[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c8
};

const u16 sRisingChozoPillarPlatformOam_Spawned_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2cc
};

const u16 sRisingChozoPillarPlatformShadowOAM_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x290
};

const u16 sRisingChozoPillarPlatformShadowOAM_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x294
};

const u16 sRisingChozoPillarPlatformShadowOAM_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2b4
};

const struct FrameData sRisingChozoPillarPlatformOam_Slot0Spawning[28] = {
    [0] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame9,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame11,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [12] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame12,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame13,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [14] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame14,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [15] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame15,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [16] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame16,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [17] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame17,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [18] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame18,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [19] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame19,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [20] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame20,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [21] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame21,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [22] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame22,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [23] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame23,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [24] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame24,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [25] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame25,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [26] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame26,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [27] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRisingChozoPillarPlatformOam_Slot0Spawned[2] = {
    [0] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawned_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRisingChozoPillarPlatformOam_Spawning[28] = {
    [0] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame9,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame11,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [12] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame12,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame13,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [14] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame14,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [15] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame15,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [16] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame16,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [17] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame17,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [18] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame18,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [19] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame19,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [20] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame20,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [21] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame21,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [22] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame22,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [23] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame23,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [24] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame24,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [25] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame25,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [26] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame26,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [27] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRisingChozoPillarPlatformOam_Spawned[2] = {
    [0] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawned_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRisingChozoPillarPlatformShadowOAM[4] = {
    [0] = {
        .pFrame = sRisingChozoPillarPlatformShadowOAM_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sRisingChozoPillarPlatformShadowOAM_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sRisingChozoPillarPlatformShadowOAM_Frame2,
        .timer = UCHAR_MAX
    },
    [3] = FRAME_DATA_TERMINATOR
};
