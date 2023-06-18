#include "data/sprites/gunship.h"
#include "macros.h"

const s16 sGunshipTakingOffYVelocity[153] = {
0, 0, -1, 0, 0, -1, 0, 0, 0, -1, 0, -1, 0, -1, 0,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1,
-2, -1, -2, -1, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -3, -3, -3, -3, -4, -4, -4, -4, -2, -2, -2,
-2, -2, -2, -2, -2, -1, -2, -1, -2, -1, -2, -1,
-2, 0, -1, 0, -1, 0, -1, 0, -1, 0, 0, -1, 0, 0,
-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0,
1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0,
1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1,
0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,
-1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, SHORT_MAX
};

const s16 sGunshipFlyingYVelocity[22] = {
    -3, -3, -3, -3, -4, -4, -4, -4, -5, -5, -6, -6,
    -7, -7, -8, -12, -16, -20, -24, -28, -32, SHORT_MAX
};

const u32 sGunshipGfx[1027] = INCBIN_U32("data/sprites/Gunship.gfx.lz");
const u16 sGunshipPAL[48] = INCBIN_U16("data/sprites/Gunship.pal");
const u16 sGunshipFlashingPAL[8 * 16] = INCBIN_U16("data/sprites/GunshipFlashingPal.pal");

const u16 sGunshipOAM_Idle_Frame0[52] = {
    0x11,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x18d, OBJ_SPRITE_OAM | 0x1300,
    0xf4, 0x195, OBJ_SPRITE_OAM | 0x1301,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x8 | 0x19d, OBJ_SPRITE_OAM | 0x1302,
    0xef, 0x1bd, OBJ_SPRITE_OAM | 0x1306,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x6b, OBJ_SPRITE_OAM | 0x1300,
    0xf4, OBJ_X_FLIP | 0x63, OBJ_SPRITE_OAM | 0x1301,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x43, OBJ_SPRITE_OAM | 0x1302,
    0xef, OBJ_X_FLIP | 0x3b, OBJ_SPRITE_OAM | 0x1306,
    0xeb, OBJ_SIZE_16x16 | 0x1ca, OBJ_SPRITE_OAM | 0x1240,
    0xeb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x26, OBJ_SPRITE_OAM | 0x1240,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x1200,
    0xdb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x1204,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_64x32 | 0x180, OBJ_SPRITE_OAM | 0x280,
    0xcb, OBJ_SIZE_64x64 | 0x1c0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_64x32 | 0x40, OBJ_SPRITE_OAM | 0x280,
    0xcb, OBJ_X_FLIP | OBJ_SIZE_64x64 | 0x0, OBJ_SPRITE_OAM | 0x208
};

const u16 sGunshipOAM_Idle_Frame1[52] = {
    0x11,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x18d, OBJ_SPRITE_OAM | 0x1340,
    0xf4, 0x195, OBJ_SPRITE_OAM | 0x1341,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x8 | 0x19d, OBJ_SPRITE_OAM | 0x1342,
    0xef, 0x1bd, OBJ_SPRITE_OAM | 0x1346,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x6b, OBJ_SPRITE_OAM | 0x1340,
    0xf4, OBJ_X_FLIP | 0x63, OBJ_SPRITE_OAM | 0x1341,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x43, OBJ_SPRITE_OAM | 0x1342,
    0xef, OBJ_X_FLIP | 0x3b, OBJ_SPRITE_OAM | 0x1346,
    0xeb, OBJ_SIZE_16x16 | 0x1ca, OBJ_SPRITE_OAM | 0x1242,
    0xeb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x26, OBJ_SPRITE_OAM | 0x1242,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x1200,
    0xdb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x1204,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_64x32 | 0x180, OBJ_SPRITE_OAM | 0x280,
    0xcb, OBJ_SIZE_64x64 | 0x1c0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_64x32 | 0x40, OBJ_SPRITE_OAM | 0x280,
    0xcb, OBJ_X_FLIP | OBJ_SIZE_64x64 | 0x0, OBJ_SPRITE_OAM | 0x208
};

const u16 sGunshipOAM_Idle_Frame2[52] = {
    0x11,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x18d, OBJ_SPRITE_OAM | 0x1307,
    0xf4, 0x195, OBJ_SPRITE_OAM | 0x1308,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x8 | 0x19d, OBJ_SPRITE_OAM | 0x1309,
    0xef, 0x1bd, OBJ_SPRITE_OAM | 0x130d,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x6b, OBJ_SPRITE_OAM | 0x1307,
    0xf4, OBJ_X_FLIP | 0x63, OBJ_SPRITE_OAM | 0x1308,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x43, OBJ_SPRITE_OAM | 0x1309,
    0xef, OBJ_X_FLIP | 0x3b, OBJ_SPRITE_OAM | 0x130d,
    0xeb, OBJ_SIZE_16x16 | 0x1ca, OBJ_SPRITE_OAM | 0x1244,
    0xeb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x26, OBJ_SPRITE_OAM | 0x1244,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x1200,
    0xdb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x1204,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_64x32 | 0x180, OBJ_SPRITE_OAM | 0x280,
    0xcb, OBJ_SIZE_64x64 | 0x1c0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_64x32 | 0x40, OBJ_SPRITE_OAM | 0x280,
    0xcb, OBJ_X_FLIP | OBJ_SIZE_64x64 | 0x0, OBJ_SPRITE_OAM | 0x208
};

const u16 sGunshipOAM_Idle_Frame3[52] = {
    0x11,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x18d, OBJ_SPRITE_OAM | 0x1347,
    0xf4, 0x195, OBJ_SPRITE_OAM | 0x1348,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x8 | 0x19d, OBJ_SPRITE_OAM | 0x1349,
    0xef, 0x1bd, OBJ_SPRITE_OAM | 0x134d,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x6b, OBJ_SPRITE_OAM | 0x1347,
    0xf4, OBJ_X_FLIP | 0x63, OBJ_SPRITE_OAM | 0x1348,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x43, OBJ_SPRITE_OAM | 0x1349,
    0xef, OBJ_X_FLIP | 0x3b, OBJ_SPRITE_OAM | 0x134d,
    0xeb, OBJ_SIZE_16x16 | 0x1ca, OBJ_SPRITE_OAM | 0x1246,
    0xeb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x26, OBJ_SPRITE_OAM | 0x1246,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x1200,
    0xdb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x1204,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_64x32 | 0x180, OBJ_SPRITE_OAM | 0x280,
    0xcb, OBJ_SIZE_64x64 | 0x1c0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_64x32 | 0x40, OBJ_SPRITE_OAM | 0x280,
    0xcb, OBJ_X_FLIP | OBJ_SIZE_64x64 | 0x0, OBJ_SPRITE_OAM | 0x208
};

const u16 sGunshipPartOAM_EntranceFrontClosed_Frame0[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x210,
    0xcf, OBJ_SIZE_16x16 | 0x1e2, OBJ_SPRITE_OAM | 0x206,
    0xcf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xe, OBJ_SPRITE_OAM | 0x206
};

const u16 sGunshipPartOAM_EntranceFrontOpening_Frame0[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x210,
    0xce, OBJ_SIZE_16x16 | 0x1e1, OBJ_SPRITE_OAM | 0x206,
    0xce, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xf, OBJ_SPRITE_OAM | 0x206
};

const u16 sGunshipPartOAM_EntranceFrontOpening_Frame1[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x210,
    0xcd, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x206,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x206
};

const u16 sGunshipPartOAM_EntranceFrontOpening_Frame2[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x210,
    0xcd, OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x206,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x11, OBJ_SPRITE_OAM | 0x206
};

const u16 sGunshipPartOAM_EntranceFrontOpening_Frame3[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x210,
    0xcd, OBJ_SIZE_16x16 | 0x1dd, OBJ_SPRITE_OAM | 0x206,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x13, OBJ_SPRITE_OAM | 0x206
};

const u16 sGunshipPartOAM_EntranceFrontOpened_Frame0[19] = {
    0x6,
    0xd2, 0x1e6, OBJ_SPRITE_OAM | 0x121a,
    0xd2, OBJ_X_FLIP | 0x12, OBJ_SPRITE_OAM | 0x121a,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x210,
    0xcd, OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x206,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x206
};

const u16 sGunshipPartOAM_EntranceFrontOpened_Frame1[19] = {
    0x6,
    0xd2, 0x1e6, OBJ_SPRITE_OAM | 0x123a,
    0xd2, OBJ_X_FLIP | 0x12, OBJ_SPRITE_OAM | 0x123a,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x210,
    0xcd, OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x206,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x206
};

const u16 sGunshipPartOAM_EntranceFrontOpened_Frame2[19] = {
    0x6,
    0xd2, 0x1e6, OBJ_SPRITE_OAM | 0x125a,
    0xd2, OBJ_X_FLIP | 0x12, OBJ_SPRITE_OAM | 0x125a,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x210,
    0xcd, OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x206,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x206
};

const u16 sGunshipPartOAM_EntranceFrontOpened_Frame3[19] = {
    0x6,
    0xd2, 0x1e6, OBJ_SPRITE_OAM | 0x127a,
    0xd2, OBJ_X_FLIP | 0x12, OBJ_SPRITE_OAM | 0x127a,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x210,
    0xd0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x210,
    0xcd, OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x206,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x206
};

const u16 sGunshipPartOAM_EntranceBackCLosed_Frame0[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xcb, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x290,
    0xcb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x290,
    OBJ_SHAPE_HORIZONTAL | 0xcb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x250,
    0xcd, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2d8,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x2d8
};

const u16 sGunshipPartOAM_EntranceBackOpening_Frame0[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xca, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x290,
    0xca, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x290,
    OBJ_SHAPE_HORIZONTAL | 0xcb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x250,
    0xcd, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2d8,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x2d8
};

const u16 sGunshipPartOAM_EntranceBackOpening_Frame1[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xc8, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x290,
    0xc8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x290,
    OBJ_SHAPE_HORIZONTAL | 0xcb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x250,
    0xcd, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2d8,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x2d8
};

const u16 sGunshipPartOAM_EntranceBackOpening_Frame2[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xc6, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x290,
    0xc6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x290,
    OBJ_SHAPE_HORIZONTAL | 0xcb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x250,
    0xcd, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2d8,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x2d8
};

const u16 sGunshipPartOAM_EntranceBackOpening_Frame3[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xc4, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x290,
    0xc4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x290,
    OBJ_SHAPE_HORIZONTAL | 0xcb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x250,
    0xcd, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2d8,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x2d8
};

const u16 sGunshipPartOAM_EntranceBackOpening_Frame4[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xc5, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x290,
    0xc5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x290,
    OBJ_SHAPE_HORIZONTAL | 0xcb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x250,
    0xcd, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2d8,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x2d8
};

const u16 sGunshipPartOAM_EntranceBackOpening_Frame5[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xc3, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x2d0,
    0xc3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0xcb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x250,
    0xcd, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2d8,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x2d8
};

const u16 sGunshipPartOAM_EntranceBackOpening_Frame6[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xc3, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x214,
    0xc3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xcb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x250,
    0xcd, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2d8,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x2d8
};

const u16 sGunshipPartOAM_EntranceBackOpening_Frame7[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xc4, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x254,
    0xc4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x254,
    OBJ_SHAPE_HORIZONTAL | 0xcb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x250,
    0xcd, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2d8,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x2d8
};

const u16 sGunshipPartOAM_EntranceBackOpened_Frame0[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xc7, 0x1ef, OBJ_SPRITE_OAM | 0x1218,
    0xc7, 0x1fc, OBJ_SPRITE_OAM | 0x1219,
    OBJ_SHAPE_HORIZONTAL | 0xc7, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x1218,
    OBJ_SHAPE_HORIZONTAL | 0xc4, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x294,
    0xc4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_HORIZONTAL | 0xcb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x250,
    0xcd, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2d8,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x2d8
};

const u16 sGunshipPartOAM_EntranceBackOpened_Frame1[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xc7, 0x1ef, OBJ_SPRITE_OAM | 0x1238,
    0xc7, 0x1fc, OBJ_SPRITE_OAM | 0x1239,
    OBJ_SHAPE_HORIZONTAL | 0xc7, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x1238,
    OBJ_SHAPE_HORIZONTAL | 0xc4, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x294,
    0xc4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_HORIZONTAL | 0xcb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x250,
    0xcd, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2d8,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x2d8
};

const u16 sGunshipPartOAM_EntranceBackOpened_Frame2[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xc7, 0x1ef, OBJ_SPRITE_OAM | 0x1258,
    0xc7, 0x1fc, OBJ_SPRITE_OAM | 0x1259,
    OBJ_SHAPE_HORIZONTAL | 0xc7, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x1258,
    OBJ_SHAPE_HORIZONTAL | 0xc4, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x294,
    0xc4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_HORIZONTAL | 0xcb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x250,
    0xcd, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2d8,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x2d8
};

const u16 sGunshipPartOAM_EntranceBackOpened_Frame3[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xc7, 0x1ef, OBJ_SPRITE_OAM | 0x1278,
    0xc7, 0x1fc, OBJ_SPRITE_OAM | 0x1279,
    OBJ_SHAPE_HORIZONTAL | 0xc7, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x1278,
    OBJ_SHAPE_HORIZONTAL | 0xc4, OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x294,
    0xc4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_HORIZONTAL | 0xcb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x250,
    0xcd, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2d8,
    0xcd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x2d8
};

const u16 sGunshipPartOAM_Platform_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x1f0, OBJ_SPRITE_OAM | 0x12d4,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x12d4
};

const u16 sGunshipPartOAM_Platform_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x1f0, OBJ_SPRITE_OAM | 0x12f4,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x12f4
};

const u16 sGunshipPartOAM_Platform_Frame2[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x1f0, OBJ_SPRITE_OAM | 0x12d6,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x12d6
};

const u16 sGunshipPartOAM_Platform_Frame3[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x1f0, OBJ_SPRITE_OAM | 0x12f6,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x12f6
};

const u16 sGunshipOAM_Flying_Frame0[82] = {
    0x1b,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x18d, OBJ_SPRITE_OAM | 0x1300,
    0xf4, 0x195, OBJ_SPRITE_OAM | 0x1301,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x8 | 0x19d, OBJ_SPRITE_OAM | 0x1302,
    0xef, 0x1bd, OBJ_SPRITE_OAM | 0x1306,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x6b, OBJ_SPRITE_OAM | 0x1300,
    0xf4, OBJ_X_FLIP | 0x63, OBJ_SPRITE_OAM | 0x1301,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x43, OBJ_SPRITE_OAM | 0x1302,
    0xef, OBJ_X_FLIP | 0x3b, OBJ_SPRITE_OAM | 0x1306,
    0xeb, OBJ_SIZE_16x16 | 0x1ca, OBJ_SPRITE_OAM | 0x1240,
    0xeb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x26, OBJ_SPRITE_OAM | 0x1240,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x1200,
    0xdb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x1204,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x180, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1a0, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0xd3, OBJ_SIZE_64x32 | 0x1c0, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x180, OBJ_SPRITE_OAM | 0x230e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1a0, OBJ_SPRITE_OAM | 0x2312,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1c0, OBJ_SPRITE_OAM | 0x234e,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2352,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x60, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x40, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0xd3, OBJ_X_FLIP | OBJ_SIZE_64x32 | 0x0, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x60, OBJ_SPRITE_OAM | 0x230e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x40, OBJ_SPRITE_OAM | 0x2312,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x20, OBJ_SPRITE_OAM | 0x234e,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x2352
};

const u16 sGunshipOAM_Flying_Frame1[82] = {
    0x1b,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x18d, OBJ_SPRITE_OAM | 0x1340,
    0xf4, 0x195, OBJ_SPRITE_OAM | 0x1341,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x8 | 0x19d, OBJ_SPRITE_OAM | 0x1342,
    0xef, 0x1bd, OBJ_SPRITE_OAM | 0x1346,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x6b, OBJ_SPRITE_OAM | 0x1340,
    0xf4, OBJ_X_FLIP | 0x63, OBJ_SPRITE_OAM | 0x1341,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x43, OBJ_SPRITE_OAM | 0x1342,
    0xef, OBJ_X_FLIP | 0x3b, OBJ_SPRITE_OAM | 0x1346,
    0xeb, OBJ_SIZE_16x16 | 0x1ca, OBJ_SPRITE_OAM | 0x1242,
    0xeb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x26, OBJ_SPRITE_OAM | 0x1242,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x1200,
    0xdb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x1204,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x180, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1a0, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0xd3, OBJ_SIZE_64x32 | 0x1c0, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x180, OBJ_SPRITE_OAM | 0x230e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1a0, OBJ_SPRITE_OAM | 0x2312,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1c0, OBJ_SPRITE_OAM | 0x234e,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2352,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x60, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x40, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0xd3, OBJ_X_FLIP | OBJ_SIZE_64x32 | 0x0, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x60, OBJ_SPRITE_OAM | 0x230e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x40, OBJ_SPRITE_OAM | 0x2312,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x20, OBJ_SPRITE_OAM | 0x234e,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x2352
};

const u16 sGunshipOAM_Flying_Frame2[82] = {
    0x1b,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x18d, OBJ_SPRITE_OAM | 0x1307,
    0xf4, 0x195, OBJ_SPRITE_OAM | 0x1308,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x8 | 0x19d, OBJ_SPRITE_OAM | 0x1309,
    0xef, 0x1bd, OBJ_SPRITE_OAM | 0x130d,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x6b, OBJ_SPRITE_OAM | 0x1307,
    0xf4, OBJ_X_FLIP | 0x63, OBJ_SPRITE_OAM | 0x1308,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x43, OBJ_SPRITE_OAM | 0x1309,
    0xef, OBJ_X_FLIP | 0x3b, OBJ_SPRITE_OAM | 0x130d,
    0xeb, OBJ_SIZE_16x16 | 0x1ca, OBJ_SPRITE_OAM | 0x1244,
    0xeb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x26, OBJ_SPRITE_OAM | 0x1244,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x1200,
    0xdb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x1204,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x180, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1a0, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0xd3, OBJ_SIZE_64x32 | 0x1c0, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x180, OBJ_SPRITE_OAM | 0x230e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1a0, OBJ_SPRITE_OAM | 0x2312,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1c0, OBJ_SPRITE_OAM | 0x234e,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2352,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x60, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x40, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0xd3, OBJ_X_FLIP | OBJ_SIZE_64x32 | 0x0, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x60, OBJ_SPRITE_OAM | 0x230e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x40, OBJ_SPRITE_OAM | 0x2312,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x20, OBJ_SPRITE_OAM | 0x234e,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x2352
};

const u16 sGunshipOAM_Flying_Frame3[82] = {
    0x1b,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x18d, OBJ_SPRITE_OAM | 0x1347,
    0xf4, 0x195, OBJ_SPRITE_OAM | 0x1348,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x8 | 0x19d, OBJ_SPRITE_OAM | 0x1349,
    0xef, 0x1bd, OBJ_SPRITE_OAM | 0x134d,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x6b, OBJ_SPRITE_OAM | 0x1347,
    0xf4, OBJ_X_FLIP | 0x63, OBJ_SPRITE_OAM | 0x1348,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x43, OBJ_SPRITE_OAM | 0x1349,
    0xef, OBJ_X_FLIP | 0x3b, OBJ_SPRITE_OAM | 0x134d,
    0xeb, OBJ_SIZE_16x16 | 0x1ca, OBJ_SPRITE_OAM | 0x1246,
    0xeb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x26, OBJ_SPRITE_OAM | 0x1246,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x1200,
    0xdb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x1204,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x180, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1a0, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0xd3, OBJ_SIZE_64x32 | 0x1c0, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x180, OBJ_SPRITE_OAM | 0x230e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1a0, OBJ_SPRITE_OAM | 0x2312,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1c0, OBJ_SPRITE_OAM | 0x234e,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2352,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x60, OBJ_SPRITE_OAM | 0x280,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x40, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_HORIZONTAL | 0xd3, OBJ_X_FLIP | OBJ_SIZE_64x32 | 0x0, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x60, OBJ_SPRITE_OAM | 0x230e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x40, OBJ_SPRITE_OAM | 0x2312,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x20, OBJ_SPRITE_OAM | 0x234e,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x2352
};

const u16 sGunshipPartOAM_FlamesHorizontal_Frame0[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1a8, OBJ_SPRITE_OAM | 0x1356,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1c8, OBJ_SPRITE_OAM | 0x1356,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1a8, OBJ_SPRITE_OAM | 0x1356,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1c8, OBJ_SPRITE_OAM | 0x1356,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x28, OBJ_SPRITE_OAM | 0x1356,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x48, OBJ_SPRITE_OAM | 0x1356,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x1356,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x48, OBJ_SPRITE_OAM | 0x1356
};

const u16 sGunshipPartOAM_FlamesHorizontal_Frame1[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1a0, OBJ_SPRITE_OAM | 0x1316,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1a0, OBJ_SPRITE_OAM | 0x1316,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1c0, OBJ_SPRITE_OAM | 0x1316,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1c0, OBJ_SPRITE_OAM | 0x1316,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x20, OBJ_SPRITE_OAM | 0x1316,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x20, OBJ_SPRITE_OAM | 0x1316,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x40, OBJ_SPRITE_OAM | 0x1316,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x40, OBJ_SPRITE_OAM | 0x1316
};

const u16 sGunshipPartOAM_FlamesHorizontal_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x280
};

const u16 sGunshipPartOAM_FlamesVertical_Frame0[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1a2, OBJ_SPRITE_OAM | 0x12da,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1be, OBJ_SPRITE_OAM | 0x12da,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x3e, OBJ_SPRITE_OAM | 0x12da,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x22, OBJ_SPRITE_OAM | 0x12da
};

const u16 sGunshipPartOAM_FlamesVertical_Frame1[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xfc, OBJ_SIZE_16x32 | 0x1a6, OBJ_SPRITE_OAM | 0x131a,
    OBJ_SHAPE_VERTICAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1b6, OBJ_SPRITE_OAM | 0x131a,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x1c2, OBJ_SPRITE_OAM | 0x131a,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1d2, OBJ_SPRITE_OAM | 0x131a,
    OBJ_SHAPE_VERTICAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x4a, OBJ_SPRITE_OAM | 0x131a,
    OBJ_SHAPE_VERTICAL | 0xfc, OBJ_SIZE_8x32 | 0x42, OBJ_SPRITE_OAM | 0x131a,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x2e, OBJ_SPRITE_OAM | 0x131a,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x26, OBJ_SPRITE_OAM | 0x131a
};

const u16 sGunshipPartOAM_FlamesVertical_Frame2[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1aa, OBJ_SPRITE_OAM | 0x129e,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_SIZE_16x32 | 0x1aa, OBJ_SPRITE_OAM | 0x131e,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_SIZE_16x32 | 0x1c6, OBJ_SPRITE_OAM | 0x129e,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_SIZE_16x32 | 0x1c6, OBJ_SPRITE_OAM | 0x131e,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x46, OBJ_SPRITE_OAM | 0x129e,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x46, OBJ_SPRITE_OAM | 0x131e,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x2a, OBJ_SPRITE_OAM | 0x129e,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x2a, OBJ_SPRITE_OAM | 0x131e
};

const struct FrameData sGunshipOAM_Idle[7] = {
    sGunshipOAM_Idle_Frame0,
    0x10,
    sGunshipOAM_Idle_Frame1,
    0x10,
    sGunshipOAM_Idle_Frame2,
    0x10,
    sGunshipOAM_Idle_Frame3,
    0x10,
    sGunshipOAM_Idle_Frame2,
    0x10,
    sGunshipOAM_Idle_Frame1,
    0x10,
    NULL,
    0x0
};

const struct FrameData sGunshipOAM_Refilling[7] = {
    sGunshipOAM_Idle_Frame0,
    0x4,
    sGunshipOAM_Idle_Frame1,
    0x4,
    sGunshipOAM_Idle_Frame2,
    0x4,
    sGunshipOAM_Idle_Frame3,
    0x4,
    sGunshipOAM_Idle_Frame2,
    0x4,
    sGunshipOAM_Idle_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sGunshipPartOAM_EntranceFrontClosed[2] = {
    sGunshipPartOAM_EntranceFrontClosed_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sGunshipPartOAM_EntranceFrontOpening[5] = {
    sGunshipPartOAM_EntranceFrontOpening_Frame0,
    0x3,
    sGunshipPartOAM_EntranceFrontOpening_Frame1,
    0x3,
    sGunshipPartOAM_EntranceFrontOpening_Frame2,
    0x3,
    sGunshipPartOAM_EntranceFrontOpening_Frame3,
    0x3,
    NULL,
    0x0
};

const struct FrameData sGunshipPartOAM_EntranceFrontOpened[7] = {
    sGunshipPartOAM_EntranceFrontOpened_Frame0,
    0x10,
    sGunshipPartOAM_EntranceFrontOpened_Frame1,
    0x10,
    sGunshipPartOAM_EntranceFrontOpened_Frame2,
    0x10,
    sGunshipPartOAM_EntranceFrontOpened_Frame3,
    0x10,
    sGunshipPartOAM_EntranceFrontOpened_Frame2,
    0x10,
    sGunshipPartOAM_EntranceFrontOpened_Frame1,
    0x10,
    NULL,
    0x0
};

const struct FrameData sGunshipPartOAM_EntranceFrontClosing[6] = {
    sGunshipPartOAM_EntranceFrontOpened_Frame0,
    0x1C,
    sGunshipPartOAM_EntranceFrontOpening_Frame3,
    0x3,
    sGunshipPartOAM_EntranceFrontOpening_Frame2,
    0x3,
    sGunshipPartOAM_EntranceFrontOpening_Frame1,
    0x3,
    sGunshipPartOAM_EntranceFrontOpening_Frame0,
    0x3,
    NULL,
    0x0
};

const struct FrameData sGunshipPartOAM_EntranceBackClosed[2] = {
    sGunshipPartOAM_EntranceBackCLosed_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sGunshipPartOAM_EntranceBackOpening[9] = {
    sGunshipPartOAM_EntranceBackOpening_Frame0,
    0x3,
    sGunshipPartOAM_EntranceBackOpening_Frame1,
    0x3,
    sGunshipPartOAM_EntranceBackOpening_Frame2,
    0x3,
    sGunshipPartOAM_EntranceBackOpening_Frame3,
    0x3,
    sGunshipPartOAM_EntranceBackOpening_Frame4,
    0x10,
    sGunshipPartOAM_EntranceBackOpening_Frame5,
    0x4,
    sGunshipPartOAM_EntranceBackOpening_Frame6,
    0x4,
    sGunshipPartOAM_EntranceBackOpening_Frame7,
    0x4,
    NULL,
    0x0
};

const struct FrameData sGunshipPartOAM_EntranceBackOpened[7] = {
    sGunshipPartOAM_EntranceBackOpened_Frame0,
    0x10,
    sGunshipPartOAM_EntranceBackOpened_Frame1,
    0x10,
    sGunshipPartOAM_EntranceBackOpened_Frame2,
    0x10,
    sGunshipPartOAM_EntranceBackOpened_Frame3,
    0x10,
    sGunshipPartOAM_EntranceBackOpened_Frame2,
    0x10,
    sGunshipPartOAM_EntranceBackOpened_Frame1,
    0x10,
    NULL,
    0x0
};

const struct FrameData sGunshipPartOAM_EntranceBackClosing[9] = {
    sGunshipPartOAM_EntranceBackOpening_Frame7,
    0x4,
    sGunshipPartOAM_EntranceBackOpening_Frame6,
    0x4,
    sGunshipPartOAM_EntranceBackOpening_Frame5,
    0x4,
    sGunshipPartOAM_EntranceBackOpening_Frame4,
    0x10,
    sGunshipPartOAM_EntranceBackOpening_Frame3,
    0x3,
    sGunshipPartOAM_EntranceBackOpening_Frame2,
    0x3,
    sGunshipPartOAM_EntranceBackOpening_Frame1,
    0x3,
    sGunshipPartOAM_EntranceBackOpening_Frame0,
    0x3,
    NULL,
    0x0
};

const struct FrameData sGunshipPartOAM_Platform[5] = {
    sGunshipPartOAM_Platform_Frame0,
    0x2,
    sGunshipPartOAM_Platform_Frame1,
    0x2,
    sGunshipPartOAM_Platform_Frame2,
    0x2,
    sGunshipPartOAM_Platform_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sGunshipOAM_Flying[7] = {
    sGunshipOAM_Flying_Frame0,
    0x8,
    sGunshipOAM_Flying_Frame1,
    0x8,
    sGunshipOAM_Flying_Frame2,
    0x8,
    sGunshipOAM_Flying_Frame3,
    0x8,
    sGunshipOAM_Flying_Frame2,
    0x8,
    sGunshipOAM_Flying_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sGunshipPartOAM_FlamesHorizontal[4] = {
    sGunshipPartOAM_FlamesHorizontal_Frame0,
    0x2,
    sGunshipPartOAM_FlamesHorizontal_Frame1,
    0x2,
    sGunshipPartOAM_FlamesHorizontal_Frame2,
    0x1,
    NULL,
    0x0
};

const struct FrameData sGunshipPartOAM_FlamesVertical[4] = {
    sGunshipPartOAM_FlamesVertical_Frame0,
    0x2,
    sGunshipPartOAM_FlamesVertical_Frame1,
    0x2,
    sGunshipPartOAM_FlamesVertical_Frame2,
    0x2,
    NULL,
    0x0
};
