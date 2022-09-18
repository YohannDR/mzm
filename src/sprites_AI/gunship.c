#include "gunship.h"
#include "../hud.h"
#include "../../data/data.h"
#include "../globals.h"

const i16 sGunshipTakingOffYVelocity[153] = {
    0, 0, -1, 0, 0, -1, 0, 0, 0, -1, 0, -1, 0, -1, 0, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -2, -1,
    -2, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -3, -3,
    -3, -3, -4, -4, -4, -4, -2, -2, -2,-2, -2, -2, -2,
    -2, -2, -1, -2, -1, -2, -1, -2, -1, -2, 0, -1, 0, -1,
    0, -1, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0-1, 0, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, SPRITE_ARRAY_TERMINATOR
};

const i16 sGunshipFlyingYVelocity[22] = {
    -3, -3, -3, -3, -4, -4, -4, -4, -5, -5, -6, -6, -7,
    -7, -8, -12, -16, -20, -24, -28, -32, SPRITE_ARRAY_TERMINATOR
};

const u32 sGunshipGFX[1027];
const u16 sGunshipPAL[48];
const u16 sGunshipFlashingPAL[8][16];

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


/**
 * @brief 44c24 | 84 | Updates the flames palette
 * 
 */
void GunshipFlickerFlames(void)
{
    u8 flag;
    u8 row;
    u8 offset;
    
    if (!(gCurrentSprite.status & SPRITE_STATUS_MOSAIC) && gCurrentSprite.workVariable2 == 0x4)
    {
        row = gCurrentSprite.oamScaling;
        flag = 0x80;

        // Update palette row
        if (row & flag)
        {
            if (row > 0x80)
                gCurrentSprite.oamScaling--;

            if (gCurrentSprite.oamScaling == 0x80)
                gCurrentSprite.oamScaling = 0x0;
        }
        else
        {
            if (row < 0x2)
                gCurrentSprite.oamScaling++;

            if (gCurrentSprite.oamScaling == 0x2)
                gCurrentSprite.oamScaling |= flag;
        }

        // Transfer palette
        offset = gCurrentSprite.oamScaling & 0x7F;
        dma_set(3, sGunshipFlashingPAL[offset],
            (PALRAM_BASE + 0x340), (DMA_ENABLE << 0x10) | 0x10);
    }
}

/**
 * @brief 44ca8 | b0 | Updates the entrance palette
 * 
 */
void GunshipEntranceFlashingAnim(void)
{
    u8 flag;
    u8 row;
    u8 offset;
    
    if (!(gCurrentSprite.status & SPRITE_STATUS_MOSAIC) && --gCurrentSprite.workVariable2 == 0x0)
    {
        if (gCurrentSprite.pOam == sGunshipOAM_Refilling)
            gCurrentSprite.workVariable2 = 0x2;
        else if (gCurrentSprite.pOam == sGunshipOAM_Flying)
            gCurrentSprite.workVariable2 = 0x4;
        else
            gCurrentSprite.workVariable2 = 0x8;

        row = gCurrentSprite.workVariable;

        // Update palette row
        if (row & 0x80)
        {
            if (gCurrentSprite.workVariable > 0x80)
                gCurrentSprite.workVariable--;

            if (gCurrentSprite.workVariable == 0x80)
                gCurrentSprite.workVariable = 0x0;
        }
        else
        {
            if (gCurrentSprite.workVariable < 0x4)
                gCurrentSprite.workVariable++;

            if (gCurrentSprite.workVariable == 0x4)
                gCurrentSprite.workVariable |= 0x80;
        }

        // Transfer palette
        offset = gCurrentSprite.workVariable & 0x7F;
        dma_set(3, sGunshipFlashingPAL[offset],
            (PALRAM_BASE + 0x330), (DMA_ENABLE << 0x10) | 0x8);
    }
}

/**
 * @brief 44d58 | 64 | Checks if samus is entering the gunship
 * 
 * @return u8 1 if entering, 0 otherwise
 */
u8 GunshipCheckSamusEnter(void)
{
    u16 samusX;
    
    if (!SpriteUtilCheckCrouchingOrMorphed())
    {
        samusX = gSamusData.xPosition;
        if (gCurrentSprite.xPosition - 0x30 < samusX && gCurrentSprite.xPosition + 0x30 > samusX)
        {
            SamusSetPose(SPOSE_TURNING_FROM_FACING_THE_FOREGROUND);
            gSamusData.timer = 0x1;
            gSamusData.standingStatus = STANDING_ENEMY;
            gSamusData.xPosition = gCurrentSprite.xPosition;

            gCurrentSprite.timer = 0x38;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.standingOnSprite = FALSE;
            gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_ON_TOP;
            return TRUE;
        }
    }
    
    return FALSE;
}

/**
 * @brief 44dbc | 1e0 | Initializes a gunship sprite
 * 
 */
void GunshipInit(void)
{
    u8 introCutscene;

    introCutscene = FALSE;

    // Check if landing
    if (gLastDoorUsed == 0x0)
    {
        introCutscene = TRUE;
        gCurrentSprite.yPosition -= BLOCK_SIZE * 6;
        SoundPlay(0x232);
    }

    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;

    gCurrentSprite.hitboxTopOffset = -0xC4;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = -0x40;
    gCurrentSprite.hitboxRightOffset = 0x40;

    gCurrentSprite.drawDistanceTopOffset = 0x30;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x78;

    gCurrentSprite.pOam = sGunshipOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.workVariable2 = 0x8;
    gCurrentSprite.workVariable = 0x0;
    gCurrentSprite.timer = 0x0;
    gCurrentSprite.arrayOffset = 0x0;

    gSubSpriteData1.workVariable3 = FALSE;

    // Spawn entrance
    SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_FRONT, gCurrentSprite.spritesetGFXSlot,
        gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_BACK, gCurrentSprite.spritesetGFXSlot,
        gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

    if (gSamusData.pose == SPOSE_SAVING_LOADING_GAME)
    {
        // Loading game from gunship
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_LEAVE;
        gCurrentSprite.timer = 0x1E;

        gSamusData.timer = 0x0;
        gSamusData.lastWallTouchedMidAir = 0x1;
        gCurrentSprite.yPositionSpawn = 0x154;
        gSubSpriteData1.workVariable3 = TRUE;

        SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_PLATFORM, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
    else if (introCutscene)
    {
        // Landing
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = GUNSHIP_POSE_LANDING;
        gCurrentSprite.timer = -0x40;

        SamusSetPose(SPOSE_SAVING_LOADING_GAME);
        gSamusData.timer = 0x1;
        gSamusData.lastWallTouchedMidAir = 0x1;

        SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_FLAMES_VERTICAL, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

        MusicUpdatePriority(0x0);
        gHideHud = TRUE;
    }
    else
    {
        // Idle
        SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_PLATFORM, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition - BLOCK_SIZE * 3 + HALF_BLOCK_SIZE, gCurrentSprite.xPosition, 0x0);
        
        gCurrentSprite.yPositionSpawn = 0x0;
        gCurrentSprite.samusCollision = SSC_ESCAPE_SHIP;
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
            gCurrentSprite.pose = GUNSHIP_POSE_CHECK_ESCAPE;
        else
            gCurrentSprite.pose = GUNSHIP_POSE_IDLE;
        gCurrentSprite.drawOrder = 0xC;
    }
}

/**
 * @brief 44f9c | 48 | Handles the gunship landing during the intro
 * 
 */
void GunshipLanding(void)
{
    if (gCurrentSprite.timer != 0x0)
    {
        gCurrentSprite.timer--;
        gCurrentSprite.yPosition += 0x2;
        gSamusData.yPosition = gCurrentSprite.yPosition - 0x4;
        gSamusData.xPosition = gCurrentSprite.xPosition;

        if (gCurrentSprite.timer == 0x1E)
        {
            // Start intro
            start_effect_for_cutscene(0x7); // Undefined
            gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
        }
    }
}

/**
 * @brief 44fe4 | 40 | Handles the gunship being idle
 * 
 */
void GunshipIdle(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP)
    {
        // Check samus entering
        gCurrentSprite.drawOrder = 0x4;
        if (GunshipCheckSamusEnter())
            gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_ENTERING;
    }
    else
        gCurrentSprite.drawOrder = 0xC;
}

/**
 * @brief 45024 | cc | Handles Samus entering the gunship
 * 
 */
void GunshipSamusEntering(void)
{
    u8 ramSlot;

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = GUNSHIP_POSE_REFILL;
        gCurrentSprite.timer = 0x41;

        // Check close entrance
        ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_FRONT);
        if (ramSlot != 0xFF)
        {
            gSpriteData[ramSlot].pOam = sGunshipPartOAM_EntranceFrontClosing;
            gSpriteData[ramSlot].animationDurationCounter = 0x0;
            gSpriteData[ramSlot].currentAnimationFrame = 0x0;
            gSpriteData[ramSlot].pose = GUNSHIP_PART_POSE_ENTRANCE_FRONT_OPENING_CLOSING;

            ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_BACK);
            if (ramSlot != 0xFF)
            {
                gSpriteData[ramSlot].pOam = sGunshipPartOAM_EntranceBackClosing;
                gSpriteData[ramSlot].animationDurationCounter = 0x0;
                gSpriteData[ramSlot].currentAnimationFrame = 0x0;
                gSpriteData[ramSlot].pose = GUNSHIP_PART_POSE_ENTRANCE_BACK_OPENING_CLOSING;

                SoundPlay(0x119); // Gunship closing
                SoundFade(0x11A, 0xA); // Gunship platform moving 
            }
        }
    }
    else if (gCurrentSprite.timer < 0x2C)
        gSamusData.yPosition += 0x4; // move samus
    else if (gCurrentSprite.timer == 0x2C)
        SoundPlay(0x11A); // Gunship platform moving 
}

/**
 * @brief 450f0 | 15c | Handles the gunship refilling Samus
 * 
 */
void GunshipRefill(void)
{
    if (gCurrentSprite.timer > 0x6)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x6)
        {
            gCurrentSprite.pOam = sGunshipOAM_Refilling;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            SoundPlay(0x21E);
        }
    }
    else if (gCurrentSprite.timer == 0x5)
    {
        // Refill energy
        if (!SpriteUtilRefillEnergy())
        {
            gCurrentSprite.timer--;
            gEnergyRefillAnimation = 0xD;
        }
    }
    else if (gCurrentSprite.timer == 0x4)
    {
        // Refill missiles
        if (gEnergyRefillAnimation != 0x0)
            gEnergyRefillAnimation--;
        else if (!SpriteUtilRefillMissiles())
        {
            gCurrentSprite.timer--;
            if (gEquipment.maxMissiles != 0x0)
                gMissileRefillAnimation = 0xD;
        }
    }
    else if (gCurrentSprite.timer == 0x3)
    {
        // Refill super missiles
        if (gMissileRefillAnimation != 0x0)
            gMissileRefillAnimation--;
        else if (!SpriteUtilRefillSuperMissiles())
        {
            gCurrentSprite.timer--;
            if (gEquipment.maxSuperMissiles != 0x0)
                gSuperMissileRefillAnimation = 0xD;
        }
    }
    else if (gCurrentSprite.timer == 0x2)
    {
        // Refill power bombs
        if (gSuperMissileRefillAnimation != 0x0)
            gSuperMissileRefillAnimation--;
        else if (!SpriteUtilRefillPowerBombs())
        {
            gCurrentSprite.timer--;
            if (gEquipment.maxPowerBombs != 0x0)
                gPowerBombRefillAnimation = 0xD;
        }
    }
    else if (gPowerBombRefillAnimation != 0x0)
        gPowerBombRefillAnimation--;
    else if (gCurrentSprite.timer != 0x0)
        gCurrentSprite.timer--;
    else
    {
        // Spawn item banner
        gCurrentSprite.pose = GUNSHIP_POSE_AFTER_REFILL;
        gCurrentSprite.timer = 0x1E;

        gCurrentSprite.oamRotation = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_WEAPONS_AND_ENERGY_RESTORED,
            0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        SoundFade(0x21E, 0xF);
    }
}

/**
 * @brief 4524c | 90 | Handles the behavior of the gunship after a refill
 * 
 */
void GunshipAfterRefill(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.oamRotation;
    if (gSpriteData[ramSlot].pose == ITEM_BANNER_POSE_REMOVAL_ANIMATION)
    {
        if (gCurrentSprite.timer != 0x0)
        {
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                // Spawn save prompt
                gCurrentSprite.oamRotation = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_SAVE_PROMPT,
                    0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
            }
        }
        else
        {
            // Check is save prompt
            if (gSpriteData[ramSlot].workVariable == TRUE)
            {
                // Saving
                gCurrentSprite.pose = GUNSHIP_POSE_SAVING;
                gCurrentSprite.timer = 0x1E;
                SoundPlay(0x21F);
            }
            else
            {
                // Not saving
                gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_LEAVE;
                gCurrentSprite.timer = 0x1E;
            }
        }
    }
}

/**
 * @brief 452dc | 44 | Handles the gunship saving
 * 
 */
void GunshipSaving(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = GUNSHIP_POSE_AFTER_SAVE;
        gCurrentSprite.oamRotation = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_SAVE_COMPLETE,
            0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 45320 | 38 | Handles the behavior of the gunship after saving
 * 
 */
void GunshipAfterSave(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.oamRotation;
    if (gSpriteData[ramSlot].pose == ITEM_BANNER_POSE_REMOVAL_ANIMATION)
    {
        // Eject samus
        gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_LEAVE;
        gCurrentSprite.timer = 0x1E;
    }
}

/**
 * @brief 45358 | b8 | Handles the gunship starting to eject samus
 * 
 */
void GunshipSamusLeave(void)
{
    u8 ramSlot;

    if (--gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_LEAVING;
        gCurrentSprite.timer = 0x2C;
        SoundPlay(0x11A); // Gunship platform moving
    }
    else if (gCurrentSprite.timer == 0xA)
    {
        // Check open entrance
        ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_FRONT);
        if (ramSlot != 0xFF)
        {
            gSpriteData[ramSlot].pOam = sGunshipPartOAM_EntranceFrontOpening;
            gSpriteData[ramSlot].animationDurationCounter = 0x0;
            gSpriteData[ramSlot].currentAnimationFrame = 0x0;

            ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_BACK);
            if (ramSlot != 0xFF)
            {
                gSpriteData[ramSlot].pOam = sGunshipPartOAM_EntranceBackOpening;
                gSpriteData[ramSlot].animationDurationCounter = 0x0;
                gSpriteData[ramSlot].currentAnimationFrame = 0x0;

                gCurrentSprite.pOam = sGunshipOAM_Idle;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;

                SoundPlay(0x118); // Gunship opening
            }
        }
    }
}

/**
 * @brief 45410 | 28 | Handles samus leaving the gunship
 * 
 */
void GunshipSamusLeaving(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        if (gHideHud)
        {
            gCurrentSprite.pose = GUNSHIP_POSE_DO_NOTHING;
            gCurrentSprite.timer = 0x32;
        }
        else
            gCurrentSprite.pose = GUNSHIP_POSE_RELEASE_SAMUS;
        SoundFade(0x11A, 0xA);
    }
    else
        gSamusData.yPosition -= 0x4;
}

/**
 * @brief 45468 | 24 | Handles the gunship releasing samus
 * 
 */
void GunshipReleaseSamus(void)
{
    if (gCurrentSprite.yPositionSpawn == 0x0)
    {
        SamusSetPose(SPOSE_FACING_THE_FOREGROUND);
        gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_RELEASED;
    }
}

/**
 * @brief 4548c | 28 | Called after samus is released
 * 
 */
void GunshipSamusReleased(void)
{
    if (gSamusData.pose != SPOSE_FACING_THE_FOREGROUND)
    {
        gCurrentSprite.pose = GUNSHIP_POSE_CHECK_SAMUS_ON_TOP_AFTER_RELEASED;
        gCurrentSprite.samusCollision = SSC_ESCAPE_SHIP;
    }
}

/**
 * @brief 454b4 | 28 | Checks if samus is still on the gunship after being released
 * 
 */
void GunshipCheckSamusOnTopAfterLeaving(void)
{
    if (!(gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP))
    {
        gCurrentSprite.drawOrder = 0xC;
        gCurrentSprite.pose = GUNSHIP_POSE_IDLE;
    }
}

/**
 * @brief 454dc | 50 | Checks if samus should escape
 * 
 */
void GunshipCheckEscapeZebes(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP && GunshipCheckSamusEnter())
    {
        // Samus entering ship

        gCurrentSprite.drawOrder = 0x4;
        gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_ENTERING_WHEN_ESCAPING;

        // Set event and update minimap
        EventFunction(EVENT_ACTION_SETTING, EVENT_ESCAPED_ZEBES);
        MinimapUpdateChunk(EVENT_ESCAPED_ZEBES);
        SoundFade(0x120, 0x3C);
        MusicUpdatePriority(0x0);
    }
}

/**
 * @brief 4552c | e4 | Handles samus entering the gunship when escaping
 * 
 */
void GunshipSamusEnteringWhenEscaping(void)
{
    u8 ramSlot;

    if (--gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = GUNSHIP_POSE_START_ESCAPING;
        gCurrentSprite.timer = 0x78;

        // Check close entrance
        ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_FRONT);
        if (ramSlot != 0xFF)
        {
            gSpriteData[ramSlot].pOam = sGunshipPartOAM_EntranceFrontClosing;
            gSpriteData[ramSlot].animationDurationCounter = 0x0;
            gSpriteData[ramSlot].currentAnimationFrame = 0x0;
            gSpriteData[ramSlot].pose = GUNSHIP_PART_POSE_ENTRANCE_FRONT_OPENING_CLOSING;

            ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_BACK);
            if (ramSlot != 0xFF)
            {
                gSpriteData[ramSlot].pOam = sGunshipPartOAM_EntranceBackClosing;
                gSpriteData[ramSlot].animationDurationCounter = 0x0;
                gSpriteData[ramSlot].currentAnimationFrame = 0x0;
                gSpriteData[ramSlot].pose = GUNSHIP_PART_POSE_ENTRANCE_BACK_OPENING_CLOSING;

                ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_PLATFORM);
                if (ramSlot != 0xFF)
                {
                    gSpriteData[ramSlot].status = 0x0;

                    SoundPlay(0x119); // Gunship closing
                    SoundFade(0x11A, 0xA); // Gunship platform moving
                }
            }
        }
    }
    else if (gCurrentSprite.timer < 0x2C)
        gSamusData.yPosition += 0x4;
    else if (gCurrentSprite.timer == 0x2C)
        SoundPlay(0x11A); // Gunship platform moving 
}

/**
 * @brief 45610 | 78 | Handles the gunship starting to escape
 * 
 */
void GunshipStartEscaping(void)
{
    if (--gCurrentSprite.timer == 0x0)
    {
        // Set taking off
        gCurrentSprite.pose = GUNSHIP_POSE_TAKING_OFF;
        gCurrentSprite.timer = 0x98;
        gCurrentSprite.arrayOffset = 0x0;
        gCurrentSprite.oamScaling = 0x0;

        // Spawn flames
        SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_FLAMES_HORIZONTAL, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
    else if (gCurrentSprite.timer == 0x4)
    {
        gCurrentSprite.pOam = sGunshipOAM_Flying;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        SoundPlay(0x234);
    }
}

/**
 * @brief 45688 | 80 | Handles the gunship taking off before flying
 * 
 */
void GunshipTakingOff(void)
{
    // https://decomp.me/scratch/RUB2J

    u8 offset;
    i32 movement;

    GunshipFlickerFlames();

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
        do {
            gCurrentSprite.pose = GUNSHIP_POSE_FLYING;
            gCurrentSprite.timer = 0xA0;
            gCurrentSprite.arrayOffset = 0x0;
        } while (0);
    else
    {
        offset = gCurrentSprite.arrayOffset;
        movement = sGunshipTakingOffYVelocity[offset];
        if (movement == SPRITE_ARRAY_TERMINATOR)
        {
            movement = sGunshipTakingOffYVelocity[offset - 1];
            gCurrentSprite.yPosition += movement;
            gSamusData.yPosition += movement;
            
        }
        else
        {
            gCurrentSprite.arrayOffset++;
            gCurrentSprite.yPosition += movement;
            gSamusData.yPosition += movement;
        }
    }
}

/**
 * @brief 45708 | 8c | Handles the ship flying when escaping
 * 
 */
void GunshipFlying(void)
{
    u8 offset;
    i32 movement;

    gCurrentSprite.timer--;

    if (gCurrentSprite.timer == 0x0)
        gCurrentSprite.pose = GUNSHIP_POSE_DO_NOTHING_ESCAPE;
    else
    {
        if (gCurrentSprite.timer == 0x32)
        {
            start_effect_for_cutscene(0x3); // Undefined
            gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
        }

        GunshipFlickerFlames();

        offset = gCurrentSprite.arrayOffset;
        movement = sGunshipFlyingYVelocity[offset];
        if (movement == SPRITE_ARRAY_TERMINATOR)
        {
            movement = sGunshipFlyingYVelocity[offset - 1];
            gCurrentSprite.yPosition += movement;
            gSamusData.yPosition += movement;
            
        }
        else
        {
            gCurrentSprite.arrayOffset = offset + 0x1;
            gCurrentSprite.yPosition += movement;
            gSamusData.yPosition += movement;
        }
    }
}

/**
 * @brief 45794 | 1a0 | Initializes a gunship part sprite
 * 
 */
void GunshipPartInit(void)
{
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    gCurrentSprite.hitboxTopOffset = 0x0;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = 0x0;
    gCurrentSprite.hitboxRightOffset = 0x0;

    switch (gCurrentSprite.roomSlot)
    {
        case GUNSHIP_PART_ENTRANCE_FRONT:
            gCurrentSprite.drawDistanceTopOffset = 0x38;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x28;
            
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontClosed;

            if (gSamusData.pose == SPOSE_SAVING_LOADING_GAME)
                gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_FRONT_OPENING_CLOSING;
            else
                gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_FRONT_IDLE;
            break;

        case GUNSHIP_PART_ENTRANCE_BACK:
            gCurrentSprite.drawDistanceTopOffset = 0x40;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

            gCurrentSprite.drawOrder = 0xE;
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackClosed;

            if (gSamusData.pose == SPOSE_SAVING_LOADING_GAME)
                gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_BACK_OPENING_CLOSING;
            else
                gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_BACK_IDLE;
            break;

        case GUNSHIP_PART_PLATFORM:
            gCurrentSprite.drawDistanceTopOffset = 0x0;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.drawOrder = 0xD;
            gCurrentSprite.pOam = sGunshipPartOAM_Platform;

            if (gSamusData.pose == SPOSE_SAVING_LOADING_GAME)
            {
                gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_DOWN;
                gCurrentSprite.yPosition += -0x18;
            }
            else
                gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_UP;
            break;

        case GUNSHIP_PART_FLAMES_HORIZONTAL:
            gCurrentSprite.drawDistanceTopOffset = 0x18;
            gCurrentSprite.drawDistanceBottomOffset = 0x30;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x60;

            gCurrentSprite.drawOrder = 0xF;
            gCurrentSprite.pOam = sGunshipPartOAM_FlamesHorizontal;
            gCurrentSprite.pose = GUNSHIP_PART_POSE_CHECK_SET_VERTICAL_FLAMES;
            break;

        case GUNSHIP_PART_FLAMES_VERTICAL:
            gCurrentSprite.drawDistanceTopOffset = 0x18;
            gCurrentSprite.drawDistanceBottomOffset = 0x30;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x60;

            gCurrentSprite.drawOrder = 0xF;
            gCurrentSprite.pOam = sGunshipPartOAM_FlamesVertical;
            gCurrentSprite.pose = GUNSHIP_PART_POSE_CHECK_SET_HORIZONTAL_FLAMES;
            gCurrentSprite.timer = 0x50;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 45934 | 40 | Checks if the horizontal flames should become the vertical flames
 * 
 */
void GunshipPartCheckSetVerticalFlames(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gSpriteData[ramSlot].pose == GUNSHIP_POSE_FLYING)
    {
        gCurrentSprite.pOam = sGunshipPartOAM_FlamesVertical;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = GUNSHIP_PART_POSE_VERTICAL_FLAME_IDLE;
    }
}

/**
 * @brief 45974 | 38 | Checks if the vertical flames should become the horizontal flames
 * 
 */
void GunshipPartCheckSetHorizontalFlames(void)
{
    if (gCurrentSprite.timer != 0x0)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            gCurrentSprite.pOam = sGunshipPartOAM_FlamesVertical;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.timer = 0xF;
            gCurrentSprite.pose = GUNSHIP_PART_POSE_CHECK_SET_VERTICAL_FLAMES_BEFORE_LANDING;
        }
    }
}

/**
 * @brief 459ac | 38 | Checks if the horizontal flames should become the vertical flames (before landing)
 * 
 */
void GunshipPartCheckSetVerticalFlamesBeforeLanding(void)
{
    if (gCurrentSprite.timer != 0x0)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            gCurrentSprite.pOam = sGunshipPartOAM_FlamesVertical;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.timer = 0xA;
            gCurrentSprite.pose = GUNSHIP_PART_POSE_CHECK_SET_HORIZONTAL_FLAMES_BEFORE_LANDING;
        }
    }
}

/**
 * @brief 459e4 | 5c | Checks if the vertical flames should become the horizontal flames (before landing)
 * 
 */
void GunshipPartCheckSetHorizontalFlamesBeforeLanding(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    if (gCurrentSprite.timer != 0x0)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            gCurrentSprite.pOam = sGunshipPartOAM_FlamesHorizontal;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }

    if (gSpriteData[ramSlot].pose == GUNSHIP_POSE_UNKNOWN)
    {
        gCurrentSprite.pose = GUNSHIP_PART_POSE_FLICKER_FLAMES_UNUSED;
        gCurrentSprite.timer = 0x3C;
    }
}

/**
 * @brief 45a40 | 28 | Flickers the flames, unused
 * 
 */
void GunshipPartFlickFlames_Unused(void)
{
    gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
        gCurrentSprite.status = 0x0;
}

/**
 * @brief 45a68 | a8 | Handles the front part of the entrance being idle
 * 
 */
void GunshipPartEntranceFrontIdle(void)
{
    if (gSubSpriteData1.workVariable3 == TRUE)
    {
        if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceFrontClosed)
        {
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontOpening;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
        else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceFrontOpening)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontOpened;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
            }
        }
        else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceFrontClosing)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontOpening;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
            }
        }
    }
    else
    {
        if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceFrontOpened)
        {
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontClosing;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
        else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceFrontClosing)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontClosed;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
            }
        }
        else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceFrontOpening)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontClosing;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
            }            
        }
    }
}

/**
 * @brief 45b10 | 5c | Handles the front part of the entrance opening/closing
 * 
 */
void GunshipPartEntranceFrontOpenClose(void)
{
    if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceFrontClosing)
    {
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontClosed;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }
    else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceFrontOpening)
    {
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontOpened;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_FRONT_IDLE;
        }
    }
}

/**
 * @brief 45b6c | f8 | Handles the back part of the entrance being idle
 * 
 */
void GunshipPartEntranceBackIdle(void)
{
    if (gSubSpriteData1.workVariable3 == TRUE)
    {
        if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceBackClosed)
        {
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackOpening;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(0x118); // Ship opening
        }
        else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceBackOpening)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackOpened;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
            }
        }
        else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceBackClosing)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackOpening;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                SoundPlay(0x118); // Ship opening
            }
        }
    }
    else
    {
        if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceBackOpened)
        {
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackClosing;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            SoundPlay(0x119); // Ship closing
        }
        else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceBackClosing)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackClosed;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
            }
        }
        else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceBackOpening)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackClosing;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                SoundPlay(0x119); // Ship closing
            }
        }
    }
}

/**
 * @brief 45c64 | 5c | Handles the back part of the entrance opening/closing
 * 
 */
void GunshipPartEntranceBackOpenClose(void)
{
    if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceBackClosing)
    {
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackClosed;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }
    else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceBackOpening)
    {
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackOpened;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_BACK_IDLE;
        }
    }
}

/**
 * @brief 45cc0 | 54 | Checks if the platform should go up
 * 
 */
void GunshipPartCheckPlatformGoUp(void)
{
    u8 ramSlot;

    ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_BACK);
    if (ramSlot != 0xFF && gSubSpriteData1.workVariable3 == TRUE && gSpriteData[ramSlot].pOam == sGunshipPartOAM_EntranceBackOpening)
    {
        gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_GO_UP;
        gCurrentSprite.timer = 0x8;
    }
}

/**
 * @brief 45d14 | 50 | Handles the platform moving up
 * 
 */
void GunshipPartPlatformGoUp(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    if (gCurrentSprite.timer != 0x0)
        gCurrentSprite.timer--;
    else
    {
        if (gSpriteData[ramSlot].yPosition - (BLOCK_SIZE * 3 + 4) > gCurrentSprite.yPosition)
        {
            gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - (BLOCK_SIZE * 3 + 4);
            gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_DOWN;
        }
        else
            gCurrentSprite.yPosition -= 0x4;
    }
}

/**
 * @brief 45d64 | 98 | Checks if the platform should go down
 * 
 */
void GunshipPartCheckPlatformGoDown(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    if (!gSubSpriteData1.workVariable3)
    {
        gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_GO_DOWN;
        gCurrentSprite.timer = 0x8;
    }
    else if (gSpriteData[ramSlot].pose == GUNSHIP_POSE_SAMUS_ENTERING && gSpriteData[ramSlot].timer < 0x2C)
        gCurrentSprite.yPosition += 0x4;
    else if (gSpriteData[ramSlot].pose == GUNSHIP_POSE_SAMUS_LEAVING && gSpriteData[ramSlot].timer < 0x2C)
        gCurrentSprite.yPosition -= 0x4;
    else if (gSpriteData[ramSlot].pose == GUNSHIP_POSE_SAMUS_ENTERING_WHEN_ESCAPING && gSpriteData[ramSlot].timer < 0x2C)
        gCurrentSprite.yPosition += 0x4;
}

/**
 * @brief 45dfc | 50 | Handles the platform moving down 
 * 
 */
void GunshipPartPlatformGoDown(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    if (gCurrentSprite.timer != 0x0)
        gCurrentSprite.timer--;
    else
    {
        if (gSpriteData[ramSlot].yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE) < gCurrentSprite.yPosition)
        {
            gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition -  (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_UP;
        }
        else
            gCurrentSprite.yPosition += 0x4;
    }
}

/**
 * @brief 45e4c | 24c | Gunship AI
 * 
 */
void Gunship(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            GunshipInit();
            break;

        case GUNSHIP_POSE_IDLE:
            GunshipIdle();
            break;

        case GUNSHIP_POSE_SAMUS_ENTERING:
            GunshipSamusEntering();
            break;

        case GUNSHIP_POSE_REFILL:
            GunshipRefill();
            break;

        case GUNSHIP_POSE_AFTER_REFILL:
            GunshipAfterRefill();
            break;

        case GUNSHIP_POSE_SAMUS_LEAVE:
            GunshipSamusLeave();
            break;

        case GUNSHIP_POSE_SAMUS_LEAVING:
            GunshipSamusLeaving();
            break;

        case GUNSHIP_POSE_RELEASE_SAMUS:
            GunshipReleaseSamus();
            break;

        case GUNSHIP_POSE_SAMUS_RELEASED:
            GunshipSamusReleased();
            break;

        case GUNSHIP_POSE_CHECK_SAMUS_ON_TOP_AFTER_RELEASED:
            GunshipCheckSamusOnTopAfterLeaving();
            break;

        case GUNSHIP_POSE_SAVING:
            GunshipSaving();
            break;

        case GUNSHIP_POSE_AFTER_SAVE:
            GunshipAfterSave();
            break;

        case GUNSHIP_POSE_CHECK_ESCAPE:
            GunshipCheckEscapeZebes();
            break;

        case GUNSHIP_POSE_SAMUS_ENTERING_WHEN_ESCAPING:
            GunshipSamusEnteringWhenEscaping();
            break;

        case GUNSHIP_POSE_START_ESCAPING:
            GunshipStartEscaping();
            break;

        case GUNSHIP_POSE_TAKING_OFF:
            GunshipTakingOff();
            break;

        case GUNSHIP_POSE_FLYING:
            GunshipFlying();
            break;

        case GUNSHIP_POSE_LANDING:
            GunshipLanding();
            break;
    }

    // Check set samus near flag
    if (!gSubSpriteData1.workVariable3)
    {
        // Check set
        if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 20, BLOCK_SIZE * 7) != NSLR_OUT_OF_RANGE)
            gSubSpriteData1.workVariable3 = TRUE;
    }
    else
    {
        // Check remove
        if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 20, BLOCK_SIZE * 9) == NSLR_OUT_OF_RANGE)
            gSubSpriteData1.workVariable3 = FALSE;
    }

    GunshipEntranceFlashingAnim();

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ESCAPED_ZEBES) && gCurrentSprite.yPositionSpawn != 0x0)
    {
        gCurrentSprite.yPositionSpawn--;
        if (gCurrentSprite.yPositionSpawn == 0x0)
            gDisablePause = FALSE;
    }
}

/**
 * @brief 46098 | 1e4 | Gunship part AI
 * 
 */
void GunshipPart(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    if (gCurrentSprite.roomSlot == GUNSHIP_PART_ENTRANCE_FRONT)
    {
        if (gSpriteData[ramSlot].drawOrder == 0x4)
            gCurrentSprite.drawOrder = 0x3;
        else
            gCurrentSprite.drawOrder = 0xB;
    }

    if (gCurrentSprite.roomSlot != GUNSHIP_PART_PLATFORM)
    {
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
        gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            GunshipPartInit();
            break;

        case GUNSHIP_PART_POSE_ENTRANCE_FRONT_IDLE:
            GunshipPartEntranceFrontIdle();
            break;

        case GUNSHIP_PART_POSE_ENTRANCE_FRONT_OPENING_CLOSING:
            GunshipPartEntranceFrontOpenClose();
            break;

        case GUNSHIP_PART_POSE_ENTRANCE_BACK_IDLE:
            GunshipPartEntranceBackIdle();
            break;

        case GUNSHIP_PART_POSE_ENTRANCE_BACK_OPENING_CLOSING:
            GunshipPartEntranceBackOpenClose();
            break;

        case GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_UP:
            GunshipPartCheckPlatformGoUp();
            break;

        case GUNSHIP_PART_POSE_PLATFORM_GO_UP:
            GunshipPartPlatformGoUp();
            break;

        case GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_DOWN:
            GunshipPartCheckPlatformGoDown();
            break;

        case GUNSHIP_PART_POSE_PLATFORM_GO_DOWN:
            GunshipPartPlatformGoDown();
            break;

        case GUNSHIP_PART_POSE_CHECK_SET_VERTICAL_FLAMES:
            GunshipPartCheckSetVerticalFlames();
            break;

        case GUNSHIP_PART_POSE_CHECK_SET_HORIZONTAL_FLAMES:
            GunshipPartCheckSetHorizontalFlames();
            break;

        case GUNSHIP_PART_POSE_CHECK_SET_VERTICAL_FLAMES_BEFORE_LANDING:
            GunshipPartCheckSetVerticalFlamesBeforeLanding();
            break;

        case GUNSHIP_PART_POSE_CHECK_SET_HORIZONTAL_FLAMES_BEFORE_LANDING:
            GunshipPartCheckSetHorizontalFlamesBeforeLanding();
            break;

        case GUNSHIP_PART_POSE_FLICKER_FLAMES_UNUSED:
            GunshipPartFlickFlames_Unused();
            break;
    }
}