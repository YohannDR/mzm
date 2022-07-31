#include "rising_chozo_pillar.h"
#include "../../data/data.h"
#include "../globals.h"

const u8 sRisingChozoPillarGFX[2684];
const u16 sRisingChozoPillarPAL[64];

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame4[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x210
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame5[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x214
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame6[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame7[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame8[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x120c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame9[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1210,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame10[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame11[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame12[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame13[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x220c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame14[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2210,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame15[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame16[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2218
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame17[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2218
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame18[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x320c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2218
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame19[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3210,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2218
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame20[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2218
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame21[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3218
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame22[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1e8, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x10, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2f4,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2f4
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame23[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1e8, OBJ_SPRITE_OAM | 0x299,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x10, OBJ_SPRITE_OAM | 0x299,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2d4,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2d4
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame24[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x280
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame25[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x284
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame26[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x288
};

const u16 sRisingChozoPillarPlatformOAM_Slot0Spawned_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28c
};


const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x244
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x248
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame3[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24c
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame4[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x250
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame5[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1240,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x254
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame6[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1244,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x258
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame7[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1248,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x258
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame8[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x124c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x258
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame9[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1250,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x258
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame10[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2240,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1254,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x258
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame11[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2244,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1258
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame12[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2248,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1258
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame13[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x224c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1258
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame14[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2250,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1258
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame15[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3240,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2254,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x1258
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame16[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3244,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2258
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame17[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3248,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2258
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame18[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x324c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2258
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame19[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3250,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2258
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame20[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3254,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2258
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame21[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3258
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame22[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1e8, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x10, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2f4,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2f4
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame23[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1e8, OBJ_SPRITE_OAM | 0x299,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x10, OBJ_SPRITE_OAM | 0x299,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2d4,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2d4
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame24[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c0
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame25[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c4
};

const u16 sRisingChozoPillarPlatformOAM_Spawning_Frame26[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c8
};

const u16 sRisingChozoPillarPlatformOAM_Spawned_Frame0[4] = {
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

const struct FrameData sRisingChozoPillarPlatformOAM_Slot0Spawning[28] = {
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame0,
    0x4,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame1,
    0x4,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame2,
    0x4,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame3,
    0x4,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame4,
    0x4,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame5,
    0x3,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame6,
    0x3,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame7,
    0x3,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame8,
    0x3,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame9,
    0x3,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame10,
    0x2,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame11,
    0x2,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame12,
    0x2,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame13,
    0x2,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame14,
    0x2,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame15,
    0x1,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame16,
    0x1,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame17,
    0x1,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame18,
    0x1,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame19,
    0x0,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame20,
    0x1,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame21,
    0x1,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame22,
    0x3,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame23,
    0x3,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame24,
    0x8,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame25,
    0x8,
    sRisingChozoPillarPlatformOAM_Slot0Spawning_Frame26,
    0x8,
    NULL,
    0x0
};

const struct FrameData sRisingChozoPillarPlatformOAM_Slot0Spawned[2] = {
    sRisingChozoPillarPlatformOAM_Slot0Spawned_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sRisingChozoPillarPlatformOAM_Spawning[28] = {
    sRisingChozoPillarPlatformOAM_Spawning_Frame0,
    0x4,
    sRisingChozoPillarPlatformOAM_Spawning_Frame1,
    0x4,
    sRisingChozoPillarPlatformOAM_Spawning_Frame2,
    0x4,
    sRisingChozoPillarPlatformOAM_Spawning_Frame3,
    0x4,
    sRisingChozoPillarPlatformOAM_Spawning_Frame4,
    0x4,
    sRisingChozoPillarPlatformOAM_Spawning_Frame5,
    0x3,
    sRisingChozoPillarPlatformOAM_Spawning_Frame6,
    0x3,
    sRisingChozoPillarPlatformOAM_Spawning_Frame7,
    0x3,
    sRisingChozoPillarPlatformOAM_Spawning_Frame8,
    0x3,
    sRisingChozoPillarPlatformOAM_Spawning_Frame9,
    0x3,
    sRisingChozoPillarPlatformOAM_Spawning_Frame10,
    0x2,
    sRisingChozoPillarPlatformOAM_Spawning_Frame11,
    0x2,
    sRisingChozoPillarPlatformOAM_Spawning_Frame12,
    0x2,
    sRisingChozoPillarPlatformOAM_Spawning_Frame13,
    0x2,
    sRisingChozoPillarPlatformOAM_Spawning_Frame14,
    0x2,
    sRisingChozoPillarPlatformOAM_Spawning_Frame15,
    0x1,
    sRisingChozoPillarPlatformOAM_Spawning_Frame16,
    0x1,
    sRisingChozoPillarPlatformOAM_Spawning_Frame17,
    0x1,
    sRisingChozoPillarPlatformOAM_Spawning_Frame18,
    0x1,
    sRisingChozoPillarPlatformOAM_Spawning_Frame19,
    0x0,
    sRisingChozoPillarPlatformOAM_Spawning_Frame20,
    0x1,
    sRisingChozoPillarPlatformOAM_Spawning_Frame21,
    0x1,
    sRisingChozoPillarPlatformOAM_Spawning_Frame22,
    0x3,
    sRisingChozoPillarPlatformOAM_Spawning_Frame23,
    0x3,
    sRisingChozoPillarPlatformOAM_Spawning_Frame24,
    0x8,
    sRisingChozoPillarPlatformOAM_Spawning_Frame25,
    0x8,
    sRisingChozoPillarPlatformOAM_Spawning_Frame26,
    0x8,
    NULL,
    0x0
};

const struct FrameData sRisingChozoPillarPlatformOAM_Spawned[2] = {
    sRisingChozoPillarPlatformOAM_Spawned_Frame0,
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


/**
 * 4854c | a8 | 
 * Spawns random sprite debris depending on the parameters
 * 
 * @param yPosition Y Position
 * @param xPosition X Position 
 * @param rng Set of debris to use
 */
void RisingChozoPillarRandomSpriteDebris(u16 yPosition, u16 xPosition, u8 rng)
{
    switch (rng)
    {
        case 0x1:
            SpriteDebrisInit(0x0, 0x11, yPosition - 0x28, xPosition);
            SpriteDebrisInit(0x0, 0x12, yPosition - 0x10, xPosition + 0x46);
            break;
        case 0x3:
            SpriteDebrisInit(0x0, 0x13, yPosition - 0x14, xPosition - 0x5C);
            SpriteDebrisInit(0x0, 0x4, yPosition - 0xA, xPosition + 0x1E);
            break;
        case 0x7:
            SpriteDebrisInit(0x0, 0x11, yPosition - 0x8, xPosition - 0x32);
            SpriteDebrisInit(0x0, 0x12, yPosition - 0x34, xPosition + 0x78);
            break;
        case 0xC:
            SpriteDebrisInit(0x0, 0x13, yPosition - 0x20, xPosition + 0x1E);
            SpriteDebrisInit(0x0, 0x4, yPosition - 0x4, xPosition - 0x6E);
    }
}

/**
 * 485f4 | ac | 
 * Spawns random particles depending on the parameters
 * 
 * @param yPosition Y Position
 * @param xPosition X Position 
 * @param rng Set of particles to use
 */
void RisingChozoPillarRandomParticles(u16 yPosition, u16 xPosition, u8 rng)
{
    switch (rng)
    {
        case 0x1:
            ParticleSet(yPosition, xPosition - 0x28, PE_TWO_MEDIUM_DUST);
            break;
        case 0x10:
            ParticleSet(yPosition, xPosition + 0x3C, PE_SECOND_MEDIUM_DUST);
            break;
        case 0x21:
            ParticleSet(yPosition, xPosition - 0x3C, PE_SECOND_MEDIUM_DUST);
            break;
        case 0x32:
            ParticleSet(yPosition, xPosition + 0x14, PE_MEDIUM_DUST);
            break;
        case 0x42:
            ParticleSet(yPosition, xPosition - 0x50, PE_TWO_MEDIUM_DUST);
            break;
        case 0x54:
            ParticleSet(yPosition, xPosition + 0x50, PE_SECOND_MEDIUM_DUST);
            ParticleSet(yPosition, xPosition, PE_SECOND_TWO_MEDIUM_DUST);
            break;
        case 0x64:
            ParticleSet(yPosition, xPosition - 0x14, PE_SECOND_TWO_MEDIUM_DUST);
            break;
        case 0x6E:
            ParticleSet(yPosition, xPosition + 0x28, PE_MEDIUM_DUST);
    }
}

/**
 * @brief 486a0 | e4 | 
 * Spawns three platforms and sets the collision for them
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param caa Clipdata Affecting Action
 */
void RisingChozoPillarSpawnThreePlatforms(u16 yPosition, u16 xPosition, u8 caa)
{
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 3), xPosition + (BLOCK_SIZE * 3));
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 3), xPosition + (BLOCK_SIZE * 4));
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 11), xPosition + (BLOCK_SIZE * 3));

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 11), xPosition + (BLOCK_SIZE * 4));
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 19), xPosition + (BLOCK_SIZE * 3));

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 19), xPosition + (BLOCK_SIZE * 4));

    // Spawn platforms
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x1, gCurrentSprite.spritesetGFXSlot,
        gCurrentSprite.primarySpriteRAMSlot, yPosition - (BLOCK_SIZE * 3),  xPosition + (BLOCK_SIZE * 3 + BLOCK_SIZE / 2), 0x0);
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x1, gCurrentSprite.spritesetGFXSlot,
        gCurrentSprite.primarySpriteRAMSlot, yPosition - (BLOCK_SIZE * 11),  xPosition + (BLOCK_SIZE * 3 + BLOCK_SIZE / 2), 0x0);
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x1, gCurrentSprite.spritesetGFXSlot,
        gCurrentSprite.primarySpriteRAMSlot, yPosition - (BLOCK_SIZE * 19), xPosition + (BLOCK_SIZE * 3 + BLOCK_SIZE / 2), 0x0);
}

/**
 * 48784 | b8 | 
 * Spawns two platforms and sets the collision for them
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param caa Clipdata Affecting Action
 */
void RisingChozoPillarSpawnTwoPlatforms(u16 yPosition, u16 xPosition, u8 caa)
{
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - 0x1C0, xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - 0x1C0, xPosition + 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - 0x7c0, xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - 0x7c0, xPosition + 0x40);
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x0, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, yPosition - 0x1C0, xPosition + 0x20, 0x0);
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x0, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, yPosition - 0x7c0, xPosition + 0x20, 0x0);
}

/**
 * 4883c | 68 | 
 * Spawns one platform and sets the collision for it
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param caa Clipdata Affecting Action
 */
void RisingChozoPillarSpawnOnePlatform(u16 yPosition, u16 xPosition, u8 caa)
{
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - 0x3C0, xPosition + 0x180);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - 0x3C0, xPosition + 0x1C0);
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x0, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, yPosition - 0x3C0, xPosition + 0x1A0, 0x0);
}

/**
 * 488a4 | 248 | Rising Chozo Pillar AI
 * 
 */
void RisingChozoPillar(void)
{
    u8 caa;
    u16 yPosition;
    u16 y_pos;
    u16 xPosition;
    u16 x_pos;

    caa = CAA_MAKE_SOLID_GRIPPABLE;
    yPosition = gCurrentSprite.yPosition - 0x20;
    xPosition = gCurrentSprite.xPosition;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED))
            {
                RisingChozoPillarSpawnThreePlatforms(yPosition, xPosition, caa);
                RisingChozoPillarSpawnTwoPlatforms(yPosition, xPosition, caa);
                RisingChozoPillarSpawnOnePlatform(yPosition, xPosition, caa);
                gCurrentSprite.status = 0x0;
            }
            else
            {
                gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
                gCurrentSprite.samusCollision = SSC_NONE;
                gCurrentSprite.drawDistanceTopOffset = 0x1;
                gCurrentSprite.drawDistanceBottomOffset = 0x1;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x1;
                gCurrentSprite.hitboxTopOffset = 0x0;
                gCurrentSprite.hitboxBottomOffset = 0x0;
                gCurrentSprite.hitboxLeftOffset = 0x0;
                gCurrentSprite.hitboxRightOffset = 0x0;
                gCurrentSprite.pOam = large_energy_drop_oam;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.pose = 0x8;
            }
            break;
        case 0x8:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_POWER_GRIP_OBTAINED))
            {
                gCurrentSprite.pose = 0x9;
                gCurrentSprite.oamScaling = 0x2C0;
                SoundPlay(0x125);
            }
            break;
        case 0x9:
            if ((gCurrentSprite.oamScaling & 0x1F) == 0x0)
                ScreenShakeStartVertical(0x1E, 0x81);
            gCurrentSprite.oamScaling--;
            if (gCurrentSprite.oamScaling != 0x0)
                gBG2Movement.yOffset += 0x2;
            else
            {
                gCurrentSprite.pose = 0x22;
                SoundFade(0x125, 0xA);
            }
            y_pos = yPosition + 0x20;
            x_pos = xPosition + 0xE0;
            RisingChozoPillarRandomSpriteDebris(y_pos, x_pos, gCurrentSprite.oamScaling & 0xF);
            RisingChozoPillarRandomParticles(y_pos, x_pos, gCurrentSprite.oamScaling & 0x7F);
            break;
        case 0x22:
            gCurrentSprite.pose = 0x23;
            RisingChozoPillarSpawnThreePlatforms(yPosition, xPosition, caa);
            break;
        case 0x23:
            gCurrentSprite.pose = 0x24;
            RisingChozoPillarSpawnTwoPlatforms(yPosition, xPosition, caa);
            break;
        case 0x24:
            gCurrentSprite.pose = 0x25;
            RisingChozoPillarSpawnOnePlatform(yPosition, xPosition, caa);
            break;
        case 0x25:
            gCurrentSprite.pose = 0x26;
            break;
        case 0x26:
            EventFunction(EVENT_ACTION_SETTING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED);
            gCurrentSprite.status = 0x0;
    }
}

/**
 * 48aec | 124 | Chozo Pillar Platform AI 
 * 
 */
void ChozoPillarPlatform(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.yPosition += 0x4;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED))
            {
                gCurrentSprite.pose = 0x9;
                if (gCurrentSprite.roomSlot != 0x0)
                {
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOAM_Spawned;
                    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM_SHADOW, 0x0, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
                }
                else
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOAM_Slot0Spawned;
            }
            else
            {
                gCurrentSprite.pose = 0x8;
                if (gCurrentSprite.roomSlot != 0x0)
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOAM_Slot0Spawning;
                else
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOAM_Spawning;
                SoundPlay(0x126);
            }
            break;

        case 0x8:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pose = 0x9;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                if (gCurrentSprite.roomSlot != 0x0)
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOAM_Spawned;
                else
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOAM_Slot0Spawned;
            }
            else
            {
                if (gCurrentSprite.roomSlot != 0x0 && gCurrentSprite.currentAnimationFrame == 0x15 && gCurrentSprite.animationDurationCounter == 0x1)
                    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM_SHADOW, 0x0, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
            }
    }
}

/**
 * 48c10 | 6c | Chozo Pillar Platform Shadow AI
 * 
 */
void ChozoPillarPlatformShadow(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawDistanceTopOffset = 0x0;
        gCurrentSprite.drawDistanceBottomOffset = 0x10;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
        gCurrentSprite.hitboxTopOffset = 0x0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = 0x0;
        gCurrentSprite.hitboxRightOffset = 0x0;
        gCurrentSprite.pose = 0x8;
        gCurrentSprite.pOam = sRisingChozoPillarPlatformShadowOAM;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.drawOrder = 0xC;
    }
}