#include "data/sprites/rising_chozo_pillar.h"
#include "macros.h"

const u32 sRisingChozoPillarGfx[671] = INCBIN_U32("data/sprites/RisingChozoPillar.gfx.lz");
const u16 sRisingChozoPillarPAL[64] = INCBIN_U16("data/sprites/RisingChozoPillar.pal");

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame4[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x210
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame5[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x214
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame6[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame7[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame8[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x120c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame9[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1210,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame10[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame11[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame12[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame13[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x220c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame14[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2210,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame15[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame16[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame17[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame18[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x320c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame19[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3210,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame20[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame21[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3218
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame22[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1e8, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x10, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2f4,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2f4
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame23[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1e8, OBJ_SPRITE_OAM | 0x299,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x10, OBJ_SPRITE_OAM | 0x299,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2d4,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2d4
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame24[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x280
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame25[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x284
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame26[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x288
};

const u16 sRisingChozoPillarPlatformOam_Slot0Spawned_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28c
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x244
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x248
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame3[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24c
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame4[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x250
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame5[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1240,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x254
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame6[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1244,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame7[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1248,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame8[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x124c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame9[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1250,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame10[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2240,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1254,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame11[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2244,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame12[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2248,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame13[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x224c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame14[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2250,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame15[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3240,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2254,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame16[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3244,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame17[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3248,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame18[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x324c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame19[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3250,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame20[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3254,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame21[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3258
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame22[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1e8, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x10, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2f4,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2f4
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame23[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1e8, OBJ_SPRITE_OAM | 0x299,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x10, OBJ_SPRITE_OAM | 0x299,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2d4,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2d4
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame24[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c0
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame25[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c4
};

const u16 sRisingChozoPillarPlatformOam_Spawning_Frame26[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c8
};

const u16 sRisingChozoPillarPlatformOam_Spawned_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2cc
};

const u16 sRisingChozoPillarPlatformShadowOAM_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x290
};

const u16 sRisingChozoPillarPlatformShadowOAM_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x294
};

const u16 sRisingChozoPillarPlatformShadowOAM_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2b4
};

const struct FrameData sRisingChozoPillarPlatformOam_Slot0Spawning[28] = {
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame0,
    0x4,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame1,
    0x4,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame2,
    0x4,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame3,
    0x4,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame4,
    0x4,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame5,
    0x3,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame6,
    0x3,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame7,
    0x3,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame8,
    0x3,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame9,
    0x3,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame10,
    0x2,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame11,
    0x2,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame12,
    0x2,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame13,
    0x2,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame14,
    0x2,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame15,
    0x1,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame16,
    0x1,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame17,
    0x1,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame18,
    0x1,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame19,
    0x1,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame20,
    0x1,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame21,
    0x1,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame22,
    0x3,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame23,
    0x3,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame24,
    0x8,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame25,
    0x8,
    sRisingChozoPillarPlatformOam_Slot0Spawning_Frame26,
    0x8,
    NULL,
    0x0
};

const struct FrameData sRisingChozoPillarPlatformOam_Slot0Spawned[2] = {
    sRisingChozoPillarPlatformOam_Slot0Spawned_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRisingChozoPillarPlatformOam_Spawning[28] = {
    sRisingChozoPillarPlatformOam_Spawning_Frame0,
    0x4,
    sRisingChozoPillarPlatformOam_Spawning_Frame1,
    0x4,
    sRisingChozoPillarPlatformOam_Spawning_Frame2,
    0x4,
    sRisingChozoPillarPlatformOam_Spawning_Frame3,
    0x4,
    sRisingChozoPillarPlatformOam_Spawning_Frame4,
    0x4,
    sRisingChozoPillarPlatformOam_Spawning_Frame5,
    0x3,
    sRisingChozoPillarPlatformOam_Spawning_Frame6,
    0x3,
    sRisingChozoPillarPlatformOam_Spawning_Frame7,
    0x3,
    sRisingChozoPillarPlatformOam_Spawning_Frame8,
    0x3,
    sRisingChozoPillarPlatformOam_Spawning_Frame9,
    0x3,
    sRisingChozoPillarPlatformOam_Spawning_Frame10,
    0x2,
    sRisingChozoPillarPlatformOam_Spawning_Frame11,
    0x2,
    sRisingChozoPillarPlatformOam_Spawning_Frame12,
    0x2,
    sRisingChozoPillarPlatformOam_Spawning_Frame13,
    0x2,
    sRisingChozoPillarPlatformOam_Spawning_Frame14,
    0x2,
    sRisingChozoPillarPlatformOam_Spawning_Frame15,
    0x1,
    sRisingChozoPillarPlatformOam_Spawning_Frame16,
    0x1,
    sRisingChozoPillarPlatformOam_Spawning_Frame17,
    0x1,
    sRisingChozoPillarPlatformOam_Spawning_Frame18,
    0x1,
    sRisingChozoPillarPlatformOam_Spawning_Frame19,
    0x1,
    sRisingChozoPillarPlatformOam_Spawning_Frame20,
    0x1,
    sRisingChozoPillarPlatformOam_Spawning_Frame21,
    0x1,
    sRisingChozoPillarPlatformOam_Spawning_Frame22,
    0x3,
    sRisingChozoPillarPlatformOam_Spawning_Frame23,
    0x3,
    sRisingChozoPillarPlatformOam_Spawning_Frame24,
    0x8,
    sRisingChozoPillarPlatformOam_Spawning_Frame25,
    0x8,
    sRisingChozoPillarPlatformOam_Spawning_Frame26,
    0x8,
    NULL,
    0x0
};

const struct FrameData sRisingChozoPillarPlatformOam_Spawned[2] = {
    sRisingChozoPillarPlatformOam_Spawned_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRisingChozoPillarPlatformShadowOAM[4] = {
    sRisingChozoPillarPlatformShadowOAM_Frame0,
    0x4,
    sRisingChozoPillarPlatformShadowOAM_Frame1,
    0x3,
    sRisingChozoPillarPlatformShadowOAM_Frame2,
    0xFF,
    NULL,
    0x0
};
