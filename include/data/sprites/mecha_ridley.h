#ifndef MECHA_RIDLEY_DATA_H
#define MECHA_RIDLEY_DATA_H

#include "types.h"
#include "oam.h"

// Multi sprite data


static const u8 sMechaRidleyGreenGlowPaletteData[7][2] = {
    { 0, 16 },
    { 1, 10 },
    { 2, 10 },
    { 3, 10 },
    { 2, 10 },
    { 1, 10 },
    { SCHAR_MAX + 1, SCHAR_MAX + 1 },
};

static const u32 sMechaRidleyGFX[2525];
static const u32 sMechaRidleyWeaponsGFX[1024];
static const u32 sMechaRidleyDestroyedGFX[336];

static const u16 sMechaRidleyPAL[129];

static const u16 sMechaRidley_8323aaa_PAL[12];
static const u16 sMechaRidley_8323ac2_PAL[5 * 16];
static const u16 sMechaRidley_8323b62_PAL[3];

static const u16 sMechaRidleyFadingPAL[7 * 16];


static const u16 sMechaRidleyPartOAM_Tail_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x1d2, OBJ_SPRITE_OAM | 0x390,
    0xf0, OBJ_SIZE_32x32 | 0xe, OBJ_SPRITE_OAM | 0x391
};

static const u16 sMechaRidleyPartOAM_Ring_Frame0[10] = {
    0x3,
    0xf4, OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x2a4,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x324,
    OBJ_SHAPE_HORIZONTAL | 0xec, 0x8, OBJ_SPRITE_OAM | 0x342
};

static const u16 sMechaRidleyPartOAM_Cover_Frame0[4] = {
    0x1,
    0xf4, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x244
};

static const u16 sMechaRidleyPartOAM_Torso_Frame0[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x2ac,
    0xe4, OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x2cc,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x2d0,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1f8, OBJ_SPRITE_OAM | 0x34e
};

static const u16 sMechaRidleyOAM_Idle_Frame0[4] = {
    0x1,
    0xfc, 0x1fb, OBJ_SPRITE_OAM | 0x5374
};

static const u16 sMechaRidleyOAM_Idle_Frame1[4] = {
    0x1,
    0xfc, 0x1fb, OBJ_SPRITE_OAM | 0x52b0
};

static const u16 sMechaRidleyOAM_Idle_Frame2[4] = {
    0x1,
    0xfc, 0x1fb, OBJ_SPRITE_OAM | 0x52b1
};

static const u16 sMechaRidleyPartOAM_HeadIdle_Frame0[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_SIZE_8x32 | 0x1e1, OBJ_SPRITE_OAM | 0x29f,
    OBJ_SHAPE_VERTICAL | 0xfc, OBJ_SIZE_16x32 | 0x1e7, OBJ_SPRITE_OAM | 0x288,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_16x32 | 0x1f7, OBJ_SPRITE_OAM | 0x34c,
    0x4, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x3cc,
    0xdc, OBJ_SIZE_32x32 | 0x7, OBJ_SPRITE_OAM | 0x308,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x7, OBJ_SPRITE_OAM | 0x388
};

static const u16 sMechaRidleyPartOAM_HeadChargingFireballs_Frame0[25] = {
    0x8,
    0xdc, OBJ_SIZE_16x16 | 0x1d8, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1e3, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xe2, OBJ_SIZE_16x32 | 0x1f3, OBJ_SPRITE_OAM | 0x20c,
    0xe5, OBJ_SIZE_32x32 | 0x3, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x8 | 0x3, OBJ_SPRITE_OAM | 0x28e,
    OBJ_SHAPE_VERTICAL | 0xe6, OBJ_SIZE_16x32 | 0x23, OBJ_SPRITE_OAM | 0x272,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_SIZE_16x32 | 0x1f2, OBJ_SPRITE_OAM | 0x20a,
    0x3, OBJ_SIZE_16x16 | 0x1e2, OBJ_SPRITE_OAM | 0x248
};

static const u16 sMechaRidleyPartOAM_HeadChargingFireballs_Frame1[25] = {
    0x8,
    0xde, OBJ_SIZE_16x16 | 0x1d8, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xdb, OBJ_SIZE_16x32 | 0x1e3, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_SIZE_16x32 | 0x1f3, OBJ_SPRITE_OAM | 0x20c,
    0xe6, OBJ_SIZE_32x32 | 0x3, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x8 | 0x3, OBJ_SPRITE_OAM | 0x28e,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_16x32 | 0x23, OBJ_SPRITE_OAM | 0x272,
    OBJ_SHAPE_VERTICAL | 0xf5, OBJ_SIZE_16x32 | 0x1f2, OBJ_SPRITE_OAM | 0x20a,
    0x5, OBJ_SIZE_16x16 | 0x1e2, OBJ_SPRITE_OAM | 0x248
};

static const u16 sMechaRidleyPartOAM_HeadSpittingFireballs_Frame0[25] = {
    0x8,
    0xdf, OBJ_SIZE_16x16 | 0x1d8, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_16x32 | 0x1e3, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_16x32 | 0x1f3, OBJ_SPRITE_OAM | 0x20c,
    0xe6, OBJ_SIZE_32x32 | 0x3, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x8 | 0x3, OBJ_SPRITE_OAM | 0x28e,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_16x32 | 0x23, OBJ_SPRITE_OAM | 0x272,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_SIZE_16x32 | 0x1f2, OBJ_SPRITE_OAM | 0x20a,
    0x7, OBJ_SIZE_16x16 | 0x1e2, OBJ_SPRITE_OAM | 0x248
};

static const u16 sMechaRidleyPartOAM_HeadSpittingFireballs_Frame1[25] = {
    0x8,
    0xdf, OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_16x32 | 0x1e4, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x20c,
    0xe6, OBJ_SIZE_32x32 | 0x4, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x8 | 0x4, OBJ_SPRITE_OAM | 0x28e,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_16x32 | 0x24, OBJ_SPRITE_OAM | 0x272,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x1f3, OBJ_SPRITE_OAM | 0x20a,
    0x8, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x248
};

static const u16 sMechaRidleyPartOAM_HeadSpittingFireballs_Frame2[25] = {
    0x8,
    0xdf, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_16x32 | 0x1e5, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_16x32 | 0x1f5, OBJ_SPRITE_OAM | 0x20c,
    0xe6, OBJ_SIZE_32x32 | 0x5, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x8 | 0x5, OBJ_SPRITE_OAM | 0x28e,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_16x32 | 0x25, OBJ_SPRITE_OAM | 0x272,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x20a,
    0x8, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x248
};

static const u16 sMechaRidleyPartOAM_EyeIdle_Frame0[4] = {
    0x1,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x12d4
};

static const u16 sMechaRidleyPartOAM_EyeIdle_Frame1[4] = {
    0x1,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x12d5
};

static const u16 sMechaRidleyPartOAM_EyeIdle_Frame3[4] = {
    0x1,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x12d6
};

static const u16 sMechaRidleyPartOAM_EyeIdle_Frame4[4] = {
    0x1,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x12d7
};

static const u16 sMechaRidleyPartOAM_EyeGlowing_Frame0[4] = {
    0x1,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeGlowing_Frame1[4] = {
    0x1,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128d
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserForward_Frame0[7] = {
    0x2,
    0xfa, 0x1f8, OBJ_SPRITE_OAM | 0x53a0,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserForward_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfa, 0x1f0, OBJ_SPRITE_OAM | 0x53a4,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128d
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserForward_Frame2[7] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xfa, 0x1e8, OBJ_SPRITE_OAM | 0x53a0,
    0xfa, 0x1f8, OBJ_SPRITE_OAM | 0x53a2,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserForward_Frame3[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1e0, OBJ_SPRITE_OAM | 0x53a4,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128d
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserForward_Frame4[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x53a0,
    0xfa, 0x1f8, OBJ_SPRITE_OAM | 0x53a3,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserForward_Frame5[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x53a4,
    OBJ_SHAPE_HORIZONTAL | 0xfa, 0x1f0, OBJ_SPRITE_OAM | 0x53a6,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128d
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserForward_Frame6[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1ca, OBJ_SPRITE_OAM | 0x53a0,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1e0, OBJ_SPRITE_OAM | 0x53a0,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserSlightlyDown_Frame0[7] = {
    0x2,
    0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x53e0,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserSlightlyDown_Frame1[7] = {
    0x2,
    0xf7, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x53c4,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128d
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserSlightlyDown_Frame2[10] = {
    0x3,
    0xfb, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x53c0,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x53c2,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserSlightlyDown_Frame3[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x53c4,
    0xf9, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x53c7,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128d
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserSlightlyDown_Frame4[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x53c0,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x53c2,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserSlightlyDown_Frame5[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x1d2, OBJ_SPRITE_OAM | 0x53c4,
    0xf9, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x53c5,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x53c7,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128d
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserSlightlyDown_Frame6[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x16 | 0x1cc, OBJ_SPRITE_OAM | 0x53c0,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x53c0,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserDown_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1f8, OBJ_SPRITE_OAM | 0x53c8,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserDown_Frame1[10] = {
    0x3,
    0xfe, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x5204,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1f8, OBJ_SPRITE_OAM | 0x5206,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128d
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserDown_Frame2[10] = {
    0x3,
    0x4, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x53c8,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1f8, OBJ_SPRITE_OAM | 0x53ca,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserDown_Frame3[13] = {
    0x4,
    0xa, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x5204,
    0x3, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x5206,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1f8, OBJ_SPRITE_OAM | 0x5206,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128d
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserDown_Frame4[13] = {
    0x4,
    0xf, OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x53c8,
    0x4, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x53ca,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1f8, OBJ_SPRITE_OAM | 0x53ca,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserDown_Frame5[16] = {
    0x5,
    0x15, OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x5204,
    0x0, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x5206,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1f8, OBJ_SPRITE_OAM | 0x5206,
    0xb, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x5206,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128d
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserDown_Frame6[16] = {
    0x5,
    0x1a, OBJ_SIZE_16x16 | 0x1d4, OBJ_SPRITE_OAM | 0x53c8,
    0xf, OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x53ca,
    0x4, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x53ca,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1f8, OBJ_SPRITE_OAM | 0x53ca,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserSlightlyUp_Frame0[7] = {
    0x2,
    0xf9, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x53e0,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserSlightlyUp_Frame1[7] = {
    0x2,
    0xf5, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x53c4,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128d
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserSlightlyUp_Frame2[10] = {
    0x3,
    0xf1, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x53c0,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x53c2,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserSlightlyUp_Frame3[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x53c4,
    0xfb, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x53c7,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128d
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserSlightlyUp_Frame4[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xe9, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x53c0,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x53c2,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserSlightlyUp_Frame5[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xe6, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1d2, OBJ_SPRITE_OAM | 0x53c4,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x53c5,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x53c7,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128d
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserSlightlyUp_Frame6[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1cc, OBJ_SPRITE_OAM | 0x53c0,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x53c0,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserUp_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x53c8,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserUp_Frame1[10] = {
    0x3,
    0xee, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x5204,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x5206,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128d
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserUp_Frame2[10] = {
    0x3,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x53c8,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x53ca,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserUp_Frame3[13] = {
    0x4,
    0xe2, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x5204,
    0xe9, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x5206,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x5206,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128d
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserUp_Frame4[13] = {
    0x4,
    0xdd, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x53c8,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x53ca,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x53ca,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserUp_Frame5[16] = {
    0x5,
    0xd7, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x5204,
    0xec, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x5206,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x5206,
    0xe1, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x5206,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128d
};

static const u16 sMechaRidleyPartOAM_EyeShootingLaserUp_Frame6[16] = {
    0x5,
    0xd2, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d4, OBJ_SPRITE_OAM | 0x53c8,
    0xdd, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x53ca,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x53ca,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x53ca,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x128c
};

static const u16 sMechaRidleyPartOAM_EyeInactive_Frame0[4] = {
    0x1,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x1390
};

static const u16 sMechaRidleyPartOAM_EyeInactive_Frame1[4] = {
    0x1,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x1323
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame0[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1b9, OBJ_SPRITE_OAM | 0x2f2,
    0x22, OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2f6,
    0x19, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1e, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e6, OBJ_SPRITE_OAM | 0x2e0,
    0xf1, OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_VERTICAL | 0x11, 0x5, OBJ_SPRITE_OAM | 0x321
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame1[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1c8, OBJ_SPRITE_OAM | 0x2f2,
    0x22, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x2f6,
    0x1a, OBJ_SIZE_16x16 | 0xf, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1e, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f3, OBJ_SPRITE_OAM | 0x2e0,
    0xf1, OBJ_SIZE_32x32 | 0x1f9, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x11, 0x11, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame2[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1c9, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x2f6,
    0x19, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x2e0,
    0xf0, OBJ_SIZE_32x32 | 0x1fa, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x10, 0x12, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame3[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1c9, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x2f6,
    0x19, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x2e0,
    0xef, OBJ_SIZE_32x32 | 0x1fa, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xf, 0x12, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame4[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1c9, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x2f6,
    0x18, OBJ_SIZE_16x16 | 0xf, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1c, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f3, OBJ_SPRITE_OAM | 0x2e0,
    0xee, OBJ_SIZE_32x32 | 0x1f9, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe, 0x11, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame5[16] = {
    0x5,
    0x11, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x218,
    0x18, OBJ_SIZE_16x16 | 0xf, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_SIZE_32x16 | 0x1f3, OBJ_SPRITE_OAM | 0x2e0,
    0xee, OBJ_SIZE_32x32 | 0x1f9, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe, 0x11, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame6[16] = {
    0x5,
    0x10, OBJ_SIZE_32x32 | 0x1c8, OBJ_SPRITE_OAM | 0x218,
    0x17, OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x16 | 0x1e6, OBJ_SPRITE_OAM | 0x2e0,
    0xed, OBJ_SIZE_32x32 | 0x1ff, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_VERTICAL | 0xd, 0x7, OBJ_SPRITE_OAM | 0x321
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame7[16] = {
    0x5,
    0xd, OBJ_SIZE_32x32 | 0x1bb, OBJ_SPRITE_OAM | 0x218,
    0x14, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xf, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2e0,
    0xed, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fe, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xd, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame8[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_SIZE_32x16 | 0x1ae, OBJ_SPRITE_OAM | 0x25c,
    0x1d, OBJ_SIZE_16x16 | 0x1ce, OBJ_SPRITE_OAM | 0x361,
    0x16, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1b, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1db, OBJ_SPRITE_OAM | 0x2e0,
    0xef, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xf, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame9[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_SIZE_32x16 | 0x1ae, OBJ_SPRITE_OAM | 0x2f2,
    0x20, OBJ_SIZE_16x16 | 0x1ce, OBJ_SPRITE_OAM | 0x2f6,
    0x17, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1c, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1db, OBJ_SPRITE_OAM | 0x2e0,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame10[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1ae, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1ce, OBJ_SPRITE_OAM | 0x2f6,
    0x18, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1db, OBJ_SPRITE_OAM | 0x2e0,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingForward_Frame0[16] = {
    0x5,
    0x11, OBJ_SIZE_32x32 | 0x1cf, OBJ_SPRITE_OAM | 0x218,
    0x18, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_SIZE_32x16 | 0x1ed, OBJ_SPRITE_OAM | 0x2e0,
    0xee, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingForward_Frame1[16] = {
    0x5,
    0x10, OBJ_SIZE_32x32 | 0x1c2, OBJ_SPRITE_OAM | 0x218,
    0x17, OBJ_SIZE_16x16 | 0x1fc, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2e0,
    0xed, OBJ_SIZE_32x32 | 0x1f9, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_VERTICAL | 0xd, 0x1, OBJ_SPRITE_OAM | 0x321
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingForward_Frame2[16] = {
    0x5,
    0xd, OBJ_SIZE_32x32 | 0x1b5, OBJ_SPRITE_OAM | 0x218,
    0x14, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xf, OBJ_SIZE_32x16 | 0x1d3, OBJ_SPRITE_OAM | 0x2e0,
    0xed, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xd, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingForward_Frame3[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_SIZE_32x16 | 0x1a8, OBJ_SPRITE_OAM | 0x25c,
    0x1d, OBJ_SIZE_16x16 | 0x1c8, OBJ_SPRITE_OAM | 0x361,
    0x16, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1b, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1d5, OBJ_SPRITE_OAM | 0x2e0,
    0xef, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1f7, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xf, OBJ_X_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingForward_Frame4[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_SIZE_32x16 | 0x1a8, OBJ_SPRITE_OAM | 0x2f2,
    0x20, OBJ_SIZE_16x16 | 0x1c8, OBJ_SPRITE_OAM | 0x2f6,
    0x17, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1c, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1d5, OBJ_SPRITE_OAM | 0x2e0,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1f7, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_X_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingForward_Frame5[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1a8, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1c8, OBJ_SPRITE_OAM | 0x2f6,
    0x18, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1d5, OBJ_SPRITE_OAM | 0x2e0,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1f7, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingForward_Frame6[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1b3, OBJ_SPRITE_OAM | 0x2f2,
    0x22, OBJ_SIZE_16x16 | 0x1d3, OBJ_SPRITE_OAM | 0x2f6,
    0x19, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1e, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2e0,
    0xf1, OBJ_SIZE_32x32 | 0x1f7, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_VERTICAL | 0x11, 0x1ff, OBJ_SPRITE_OAM | 0x321
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingForward_Frame7[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1c2, OBJ_SPRITE_OAM | 0x2f2,
    0x22, OBJ_SIZE_16x16 | 0x1e2, OBJ_SPRITE_OAM | 0x2f6,
    0x1a, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1e, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ed, OBJ_SPRITE_OAM | 0x2e0,
    0xf1, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x11, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingForward_Frame8[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1c3, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x2f6,
    0x19, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x2e0,
    0xf0, OBJ_SIZE_32x32 | 0x1f4, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x10, 0xc, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingForward_Frame9[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1c3, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x2f6,
    0x19, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x2e0,
    0xef, OBJ_SIZE_32x32 | 0x1f4, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xf, 0xc, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingForward_Frame10[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1c3, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x2f6,
    0x18, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1c, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x2e0,
    0xee, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmHoldingUp_Frame0[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1af, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1cf, OBJ_SPRITE_OAM | 0x2f6,
    0x18, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1dc, OBJ_SPRITE_OAM | 0x2e0,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmHoldingUp_Frame1[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_SIZE_32x16 | 0x1af, OBJ_SPRITE_OAM | 0x2f2,
    0x20, OBJ_SIZE_16x16 | 0x1cf, OBJ_SPRITE_OAM | 0x2f6,
    0x17, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1c, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1dc, OBJ_SPRITE_OAM | 0x2e0,
    0xef, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xf, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmHoldingUp_Frame2[16] = {
    0x5,
    0xc, OBJ_SIZE_32x32 | 0x1bb, OBJ_SPRITE_OAM | 0x218,
    0x13, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xe, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2e0,
    0xed, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xd, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmHoldingUp_Frame3[19] = {
    0x6,
    0x2, OBJ_SIZE_32x32 | 0x1c3, OBJ_SPRITE_OAM | 0x218,
    0x14, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    0x5, OBJ_SIZE_16x16 | 0x1dd, OBJ_SPRITE_OAM | 0x21e,
    0xd, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x21c,
    0xee, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmHoldingUp_Frame4[19] = {
    0x6,
    0x3, OBJ_SIZE_32x32 | 0x1c3, OBJ_SPRITE_OAM | 0x218,
    0x15, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    0x6, OBJ_SIZE_16x16 | 0x1dd, OBJ_SPRITE_OAM | 0x21e,
    0xe, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x21c,
    0xef, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xf, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmHoldingUp_Frame0[16] = {
    0x5,
    0x11, OBJ_SIZE_32x32 | 0x1cf, OBJ_SPRITE_OAM | 0x218,
    0x18, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_SIZE_32x16 | 0x1ed, OBJ_SPRITE_OAM | 0x2e0,
    0xee, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmHoldingUp_Frame1[19] = {
    0x6,
    0x6, OBJ_SIZE_32x32 | 0x1d6, OBJ_SPRITE_OAM | 0x218,
    0x16, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    0x9, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21e,
    0x11, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21c,
    0xec, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xc, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmHoldingUp_Frame2[19] = {
    0x6,
    0x7, OBJ_SIZE_32x32 | 0x1d6, OBJ_SPRITE_OAM | 0x218,
    0x17, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    0xa, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21e,
    0x12, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21c,
    0xed, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xd, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmHoldingUp_Frame3[19] = {
    0x6,
    0x7, OBJ_SIZE_32x32 | 0x1d6, OBJ_SPRITE_OAM | 0x218,
    0x17, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    0xa, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21e,
    0x12, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21c,
    0xed, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xd, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmHoldingUp_Frame4[19] = {
    0x6,
    0x7, OBJ_SIZE_32x32 | 0x1d6, OBJ_SPRITE_OAM | 0x218,
    0x17, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    0xa, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21e,
    0x12, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21c,
    0xed, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xd, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmLayingDown_Frame0[19] = {
    0x6,
    0x2, OBJ_SIZE_32x32 | 0x1c3, OBJ_SPRITE_OAM | 0x218,
    0x14, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    0x5, OBJ_SIZE_16x16 | 0x1dd, OBJ_SPRITE_OAM | 0x21e,
    0xd, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x21c,
    0xee, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmLayingDown_Frame1[16] = {
    0x5,
    0xf, OBJ_SIZE_32x32 | 0x1bb, OBJ_SPRITE_OAM | 0x218,
    0x16, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x11, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2e0,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmLayingDown_Frame2[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1af, OBJ_SPRITE_OAM | 0x25c,
    0x22, OBJ_SIZE_16x16 | 0x1cf, OBJ_SPRITE_OAM | 0x361,
    0x1b, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1dc, OBJ_SPRITE_OAM | 0x2e0,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x13, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmLayingDown_Frame3[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x23, OBJ_SIZE_32x16 | 0x1af, OBJ_SPRITE_OAM | 0x2f2,
    0x23, OBJ_SIZE_16x16 | 0x1cf, OBJ_SPRITE_OAM | 0x2f6,
    0x1a, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1f, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1dc, OBJ_SPRITE_OAM | 0x2e0,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x12, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmLayingDown_Frame0[19] = {
    0x6,
    0x6, OBJ_SIZE_32x32 | 0x1d6, OBJ_SPRITE_OAM | 0x218,
    0x16, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    0x9, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21e,
    0x11, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21c,
    0xec, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xc, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmLayingDown_Frame1[16] = {
    0x5,
    0x11, OBJ_SIZE_32x32 | 0x1cf, OBJ_SPRITE_OAM | 0x218,
    0x18, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_SIZE_32x16 | 0x1ed, OBJ_SPRITE_OAM | 0x2e0,
    0xee, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmLayingDown_Frame2[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1c3, OBJ_SPRITE_OAM | 0x25c,
    0x22, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x361,
    0x1b, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1f, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x2e0,
    0xf1, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x11, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmLayingDown_Frame3[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1c3, OBJ_SPRITE_OAM | 0x2f2,
    0x22, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x2f6,
    0x19, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x2e0,
    0xef, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xf, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmTrembling_Frame0[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1af, OBJ_SPRITE_OAM | 0x2f2,
    0x22, OBJ_SIZE_16x16 | 0x1cf, OBJ_SPRITE_OAM | 0x2f6,
    0x19, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1e, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1dc, OBJ_SPRITE_OAM | 0x2e0,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmTrembling_Frame1[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1af, OBJ_SPRITE_OAM | 0x2f2,
    0x22, OBJ_SIZE_16x16 | 0x1cf, OBJ_SPRITE_OAM | 0x2f6,
    0x18, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1dc, OBJ_SPRITE_OAM | 0x2e0,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmTrembling_Frame2[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1af, OBJ_SPRITE_OAM | 0x2f2,
    0x22, OBJ_SIZE_16x16 | 0x1cf, OBJ_SPRITE_OAM | 0x2f6,
    0x16, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1c, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1dc, OBJ_SPRITE_OAM | 0x2e0,
    0xee, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmTrembling_Frame3[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1af, OBJ_SPRITE_OAM | 0x2f2,
    0x22, OBJ_SIZE_16x16 | 0x1cf, OBJ_SPRITE_OAM | 0x2f6,
    0x17, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1dc, OBJ_SPRITE_OAM | 0x2e0,
    0xef, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xf, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmTrembling_Frame5[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1af, OBJ_SPRITE_OAM | 0x2f2,
    0x22, OBJ_SIZE_16x16 | 0x1cf, OBJ_SPRITE_OAM | 0x2f6,
    0x19, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1e, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1dc, OBJ_SPRITE_OAM | 0x2e0,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmTrembling_Frame0[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1c3, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x2f6,
    0x18, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1c, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x2e0,
    0xee, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmTrembling_Frame1[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1c3, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x2f6,
    0x17, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1b, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x2e0,
    0xed, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xd, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmTrembling_Frame2[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1c3, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x2f6,
    0x15, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x2e0,
    0xeb, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xb, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmTrembling_Frame3[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1c3, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x2f6,
    0x16, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1b, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x2e0,
    0xec, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xc, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmTrembling_Frame5[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1c3, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x2f6,
    0x18, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1c, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x2e0,
    0xee, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmSwinging_Frame0[16] = {
    0x5,
    0xf0, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x218,
    0x14, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x1ee, OBJ_SPRITE_OAM | 0x326,
    0xee, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmSwinging_Frame1[16] = {
    0x5,
    0xdb, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x218,
    0x2, OBJ_SIZE_16x16 | 0x1dc, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xe6, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1e1, OBJ_SPRITE_OAM | 0x326,
    0xee, OBJ_SIZE_32x32 | 0x1f7, OBJ_SPRITE_OAM | 0x200,
    0xfe, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x332
};

static const u16 sMechaRidleyPartOAM_LeftArmSwinging_Frame2[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xcc, OBJ_SIZE_32x16 | 0x1c1, OBJ_SPRITE_OAM | 0x2f2,
    0xcc, OBJ_SIZE_16x16 | 0x1e1, OBJ_SPRITE_OAM | 0x2f6,
    0xf2, OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1dd, OBJ_SPRITE_OAM | 0x326,
    0xe5, OBJ_SIZE_32x32 | 0x1f5, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1e5, OBJ_SPRITE_OAM | 0x372
};

static const u16 sMechaRidleyPartOAM_LeftArmSwinging_Frame3[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xb5, OBJ_SIZE_32x16 | 0x1c6, OBJ_SPRITE_OAM | 0x25c,
    0xb5, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x361,
    0xdd, OBJ_SIZE_16x16 | 0x1dc, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xc2, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1e2, OBJ_SPRITE_OAM | 0x326,
    0xe4, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1f7, OBJ_SPRITE_OAM | 0x200,
    0xe4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x332
};

static const u16 sMechaRidleyPartOAM_LeftArmSwinging_Frame4[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xb6, OBJ_SIZE_32x16 | 0x1ae, OBJ_SPRITE_OAM | 0x25c,
    0xb6, OBJ_SIZE_16x16 | 0x1ce, OBJ_SPRITE_OAM | 0x361,
    0xde, OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xc3, OBJ_SIZE_16x32 | 0x1d5, OBJ_SPRITE_OAM | 0x326,
    0xe5, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1f6, OBJ_SPRITE_OAM | 0x200,
    0xe5, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x332
};

static const u16 sMechaRidleyPartOAM_LeftArmSwinging_Frame5[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xda, OBJ_SIZE_32x16 | 0x193, OBJ_SPRITE_OAM | 0x25c,
    0xda, OBJ_SIZE_16x16 | 0x1b3, OBJ_SPRITE_OAM | 0x361,
    0xf2, OBJ_SIZE_16x16 | 0x1d6, OBJ_SPRITE_OAM | 0x28a,
    0xe2, OBJ_SIZE_16x16 | 0x1bc, OBJ_SPRITE_OAM | 0x21e,
    0xea, OBJ_SIZE_16x16 | 0x1cc, OBJ_SPRITE_OAM | 0x21c,
    0xe5, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1e2, OBJ_SPRITE_OAM | 0x372
};

static const u16 sMechaRidleyPartOAM_LeftArmSwinging_Frame6[16] = {
    0x5,
    0xff, OBJ_SIZE_32x32 | 0x19e, OBJ_SPRITE_OAM | 0x218,
    0x5, OBJ_SIZE_16x16 | 0x1d8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1bc, OBJ_SPRITE_OAM | 0x2e0,
    0xf1, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x200,
    0x1, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x332
};

static const u16 sMechaRidleyPartOAM_LeftArmSwinging_Frame7[19] = {
    0x6,
    0x6, OBJ_SIZE_32x32 | 0x1c3, OBJ_SPRITE_OAM | 0x218,
    0x18, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    0x9, OBJ_SIZE_16x16 | 0x1dd, OBJ_SPRITE_OAM | 0x21e,
    0x11, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x21c,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x12, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_NeckLow_Frame0[16] = {
    0x5,
    0xa, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x28a,
    0xf9, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1dd, OBJ_SPRITE_OAM | 0x3ce,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0x3, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckRotateLow_Frame0[13] = {
    0x4,
    0xa, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1e4, OBJ_SPRITE_OAM | 0x320,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0x3, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckRotateLow_Frame1[16] = {
    0x5,
    0xa, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x28a,
    0xfe, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_Y_FLIP | 0x1d1, OBJ_SPRITE_OAM | 0x3ce,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0x3, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckRotateLow_Frame2[13] = {
    0x4,
    0xa, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x28a,
    0x2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d5, OBJ_SPRITE_OAM | 0x38e,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0x3, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckRotateLow_Frame3[13] = {
    0x4,
    0xa, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xe, OBJ_SIZE_32x8 | 0x1cc, OBJ_SPRITE_OAM | 0x3f8,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0x3, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckRotateLow_Frame4[13] = {
    0x4,
    0xa, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xe, OBJ_SIZE_32x8 | 0x1cb, OBJ_SPRITE_OAM | 0x3f8,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0x3, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckMiddleToLow_Frame1[16] = {
    0x5,
    0xa, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x28a,
    0xf8, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1de, OBJ_SPRITE_OAM | 0x3ce,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0x3, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckLowToMiddle_Frame0[16] = {
    0x5,
    0x0, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x28a,
    0xef, OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xff, 0x1d7, OBJ_SPRITE_OAM | 0x3ce,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1dc, OBJ_SPRITE_OAM | 0x294
};

static const u16 sMechaRidleyPartOAM_NeckLowToMiddle_Frame1[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x28a,
    0xe6, OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1d7, OBJ_SPRITE_OAM | 0x3ce,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e3, OBJ_SPRITE_OAM | 0x3f8
};

static const u16 sMechaRidleyPartOAM_NeckMiddle_Frame0[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x28a,
    0xe7, OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1d7, OBJ_SPRITE_OAM | 0x3ce,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e3, OBJ_SPRITE_OAM | 0x3f8
};

static const u16 sMechaRidleyPartOAM_NeckRotateMiddle_Frame0[13] = {
    0x4,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xe6, OBJ_SIZE_8x32 | 0x1de, OBJ_SPRITE_OAM | 0x320,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e3, OBJ_SPRITE_OAM | 0x3f8
};

static const u16 sMechaRidleyPartOAM_NeckRotateMiddle_Frame1[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x28a,
    0xec, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d3, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_Y_FLIP | 0x1cb, OBJ_SPRITE_OAM | 0x3ce,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e3, OBJ_SPRITE_OAM | 0x3f8
};

static const u16 sMechaRidleyPartOAM_NeckRotateMiddle_Frame2[13] = {
    0x4,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x28a,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1cf, OBJ_SPRITE_OAM | 0x38e,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e3, OBJ_SPRITE_OAM | 0x3f8
};

static const u16 sMechaRidleyPartOAM_NeckRotateMiddle_Frame3[13] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1c6, OBJ_SPRITE_OAM | 0x3f8,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e3, OBJ_SPRITE_OAM | 0x3f8
};

static const u16 sMechaRidleyPartOAM_NeckRotateMiddle_Frame4[13] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1c5, OBJ_SPRITE_OAM | 0x3f8,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e3, OBJ_SPRITE_OAM | 0x3f8
};

static const u16 sMechaRidleyPartOAM_NeckRotateMiddle_Frame8[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x28a,
    0xe6, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1d8, OBJ_SPRITE_OAM | 0x3ce,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e3, OBJ_SPRITE_OAM | 0x3f8
};

static const u16 sMechaRidleyPartOAM_NeckMiddleToHigh_Frame0[16] = {
    0x5,
    0xee, OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x28a,
    0xdd, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xed, 0x1d8, OBJ_SPRITE_OAM | 0x3ce,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1e2, OBJ_SPRITE_OAM | 0x294
};

static const u16 sMechaRidleyPartOAM_NeckMiddleToHigh_Frame1[16] = {
    0x5,
    0xe7, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x28a,
    0xd5, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xe5, 0x1e2, OBJ_SPRITE_OAM | 0x3ce,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckHigh_Frame0[16] = {
    0x5,
    0xe7, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x28a,
    0xd6, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xe6, 0x1e1, OBJ_SPRITE_OAM | 0x3ce,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckRotateHigh_Frame0[13] = {
    0x4,
    0xe7, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xd5, OBJ_SIZE_8x32 | 0x1e8, OBJ_SPRITE_OAM | 0x320,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckRotateHigh_Frame1[16] = {
    0x5,
    0xe7, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x28a,
    0xdb, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1dd, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xd3, OBJ_Y_FLIP | 0x1d5, OBJ_SPRITE_OAM | 0x3ce,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckRotateHigh_Frame2[13] = {
    0x4,
    0xe7, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x28a,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x38e,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckRotateHigh_Frame3[13] = {
    0x4,
    0xe7, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_SIZE_32x8 | 0x1d0, OBJ_SPRITE_OAM | 0x3f8,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckRotateHigh_Frame4[13] = {
    0x4,
    0xe7, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_SIZE_32x8 | 0x1cf, OBJ_SPRITE_OAM | 0x3f8,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckRotateHigh_Frame8[16] = {
    0x5,
    0xe7, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x28a,
    0xd5, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xe5, 0x1e2, OBJ_SPRITE_OAM | 0x3ce,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckLow_2_Frame0[16] = {
    0x5,
    0xb, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x28a,
    0xfa, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xa, 0x1dd, OBJ_SPRITE_OAM | 0x3ce,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0x4, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckMiddle_2_Frame0[16] = {
    0x5,
    0xf9, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x28a,
    0xe8, OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1d7, OBJ_SPRITE_OAM | 0x3ce,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_SIZE_32x8 | 0x1e3, OBJ_SPRITE_OAM | 0x3f8
};

static const u16 sMechaRidleyPartOAM_NeckHigh_2_Frame0[16] = {
    0x5,
    0xe8, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x28a,
    0xd7, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xe7, 0x1e1, OBJ_SPRITE_OAM | 0x3ce,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_MissileLauncherClosed_Frame0[13] = {
    0x4,
    0xe0, OBJ_SIZE_64x64 | 0x1e0, OBJ_SPRITE_OAM | 0x318,
    0xe4, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2ca,
    0xe9, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x3b8,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1ea, OBJ_SPRITE_OAM | 0x3ba
};

static const u16 sMechaRidleyPartOAM_MissileLauncherOpening_Frame0[16] = {
    0x5,
    0xe0, OBJ_SIZE_64x64 | 0x1e0, OBJ_SPRITE_OAM | 0x318,
    0xe5, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x2ca,
    0xea, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x3b8,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x1eb, OBJ_SPRITE_OAM | 0x3ba,
    0xe0, OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x335
};

static const u16 sMechaRidleyPartOAM_MissileLauncherOpening_Frame1[16] = {
    0x5,
    0xe0, OBJ_SIZE_64x64 | 0x1e0, OBJ_SPRITE_OAM | 0x318,
    0xe6, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x2ca,
    0xeb, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x3b8,
    OBJ_SHAPE_VERTICAL | 0xe7, 0x1ec, OBJ_SPRITE_OAM | 0x3ba,
    0xe0, OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x335
};

static const u16 sMechaRidleyPartOAM_MissileLauncherOpening_Frame2[16] = {
    0x5,
    0xe0, OBJ_SIZE_64x64 | 0x1e0, OBJ_SPRITE_OAM | 0x318,
    0xe8, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x2ca,
    0xed, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x3b8,
    OBJ_SHAPE_VERTICAL | 0xe9, 0x1ee, OBJ_SPRITE_OAM | 0x3ba,
    0xe0, OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x335
};

static const u16 sMechaRidleyPartOAM_MissileLauncherOpening_Frame3[16] = {
    0x5,
    0xe0, OBJ_SIZE_64x64 | 0x1e0, OBJ_SPRITE_OAM | 0x318,
    0xe7, OBJ_SIZE_16x16 | 0x1f3, OBJ_SPRITE_OAM | 0x2ca,
    0xec, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x3b8,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1ed, OBJ_SPRITE_OAM | 0x3ba,
    0xe0, OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x335
};

static const u16 sMechaRidleyPartOAM_MissileLauncherOpening_Frame4[16] = {
    0x5,
    0xe0, OBJ_SIZE_64x64 | 0x1e0, OBJ_SPRITE_OAM | 0x318,
    0xe6, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x2ca,
    0xee, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x3b8,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x1ec, OBJ_SPRITE_OAM | 0x3ba,
    0xe0, OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x335
};

static const u16 sMechaRidleyPartOAM_MissileLauncherOpening_Frame5[16] = {
    0x5,
    0xe0, OBJ_SIZE_64x64 | 0x1e0, OBJ_SPRITE_OAM | 0x318,
    0xe5, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x2ca,
    0xf0, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x3b8,
    OBJ_SHAPE_VERTICAL | 0xe4, 0x1eb, OBJ_SPRITE_OAM | 0x3ba,
    0xe0, OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x335
};

static const u16 sMechaRidleyPartOAM_MissileLauncherOpening_Frame6[13] = {
    0x4,
    0xe0, OBJ_SIZE_64x64 | 0x1e0, OBJ_SPRITE_OAM | 0x318,
    0xe4, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x2ca,
    0xf3, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x3b8,
    0xe0, OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x335
};

static const u16 sMechaRidleyPartOAM_MissileLauncherOpening_Frame7[7] = {
    0x2,
    0xe0, OBJ_SIZE_64x64 | 0x1e0, OBJ_SPRITE_OAM | 0x318,
    0xe0, OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x335
};

static const u16 sMechaRidleyPartOAM_MissileLauncherOpened_Frame1[7] = {
    0x2,
    0xe1, OBJ_SIZE_64x64 | 0x1e1, OBJ_SPRITE_OAM | 0x318,
    0xe1, OBJ_SIZE_32x32 | 0x1e9, OBJ_SPRITE_OAM | 0x335
};

static const u16 sMechaRidleyMissileOAM_Frame0[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x5214
};

static const u16 sMechaRidleyFireballOAM_Frame0[4] = {
    0x1,
    0xec, OBJ_SIZE_32x32 | 0x1f4, OBJ_SPRITE_OAM | 0x1214
};

static const u16 sMechaRidleyFireballOAM_Frame1[4] = {
    0x1,
    0xed, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x1214
};

static const u16 sMechaRidleyFireballOAM_Frame2[4] = {
    0x1,
    0xee, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x1214
};

static const u16 sMechaRidleyFireballOAM_Frame3[4] = {
    0x1,
    0xed, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x1214
};

static const u16 sMechaRidleyLaserOAM_Forward_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x5260
};

static const u16 sMechaRidleyLaserOAM_Forward_Frame0[4] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e1, OBJ_SPRITE_OAM | 0x53a4,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x1ff, OBJ_SPRITE_OAM | 0x53a4
};

static const u16 sMechaRidleyLaserOAM_Forward_Frame1[4] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e1, OBJ_SPRITE_OAM | 0x53a0,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x1ff, OBJ_SPRITE_OAM | 0x53a0
};

static const u16 sMechaRidleyLaserOAM_SlightlyDown_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x16 | 0x1e3, OBJ_SPRITE_OAM | 0x53c4,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1fb, OBJ_SPRITE_OAM | 0x53c4
};

static const u16 sMechaRidleyLaserOAM_SlightlyDown_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1e1, OBJ_SPRITE_OAM | 0x53c0,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1fb, OBJ_SPRITE_OAM | 0x53c0
};

static const u16 sMechaRidleyLaserOAM_Down_Frame0[13] = {
    0x4,
    0x8, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x5204,
    0xfe, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x5206,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x5204,
    0xf2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x5206
};

static const u16 sMechaRidleyLaserOAM_Down_Frame1[13] = {
    0x4,
    0x8, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x53c8,
    0xfe, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x53ca,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x53c8,
    0xf2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x53ca
};

static const u16 sMechaRidleyLaserOAM_SlightlyUp_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e3, OBJ_SPRITE_OAM | 0x53c4,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1fb, OBJ_SPRITE_OAM | 0x53c4
};

static const u16 sMechaRidleyLaserOAM_SlightlyUp_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e1, OBJ_SPRITE_OAM | 0x53c0,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1fb, OBJ_SPRITE_OAM | 0x53c0
};

static const u16 sMechaRidleyLaserOAM_Up_Frame0[13] = {
    0x4,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x5204,
    0xf2, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x5206,
    0x8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x5204,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x5206
};

static const u16 sMechaRidleyLaserOAM_Up_Frame1[13] = {
    0x4,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x53c8,
    0xf2, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x53ca,
    0x8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x53c8,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x53ca
};

static const u16 sMechaRidleyPartOAM_LeftArmDying_Frame0[19] = {
    0x6,
    0x5, OBJ_SIZE_32x32 | 0x1c3, OBJ_SPRITE_OAM | 0x218,
    0x17, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    0x8, OBJ_SIZE_16x16 | 0x1dd, OBJ_SPRITE_OAM | 0x21e,
    0x10, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x21c,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmDying_Frame1[19] = {
    0x6,
    0x9, OBJ_SIZE_32x32 | 0x1c3, OBJ_SPRITE_OAM | 0x218,
    0x1b, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    0xc, OBJ_SIZE_16x16 | 0x1dd, OBJ_SPRITE_OAM | 0x21e,
    0x14, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x21c,
    0xf5, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x15, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmDying_Frame2[19] = {
    0x6,
    0x7, OBJ_SIZE_32x32 | 0x1c3, OBJ_SPRITE_OAM | 0x218,
    0x19, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    0xa, OBJ_SIZE_16x16 | 0x1dd, OBJ_SPRITE_OAM | 0x21e,
    0x12, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x21c,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x13, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmDying_Frame3[16] = {
    0x5,
    0x14, OBJ_SIZE_32x32 | 0x1ba, OBJ_SPRITE_OAM | 0x218,
    0x1b, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x16, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x2e0,
    0xf5, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fc, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x15, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmDying_Frame4[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x27, OBJ_SIZE_32x16 | 0x1ae, OBJ_SPRITE_OAM | 0x25c,
    0x27, OBJ_SIZE_16x16 | 0x1ce, OBJ_SPRITE_OAM | 0x361,
    0x20, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x25, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1db, OBJ_SPRITE_OAM | 0x2e0,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fc, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmDying_Frame5[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x2a, OBJ_SIZE_32x16 | 0x1ad, OBJ_SPRITE_OAM | 0x2f2,
    0x2a, OBJ_SIZE_16x16 | 0x1cd, OBJ_SPRITE_OAM | 0x2f6,
    0x21, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x26, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1da, OBJ_SPRITE_OAM | 0x2e0,
    0xf9, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fb, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x19, OBJ_X_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmDying_Frame6[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x28, OBJ_SIZE_32x16 | 0x1ad, OBJ_SPRITE_OAM | 0x2f2,
    0x28, OBJ_SIZE_16x16 | 0x1cd, OBJ_SPRITE_OAM | 0x2f6,
    0x1f, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x24, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1da, OBJ_SPRITE_OAM | 0x2e0,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fb, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x17, OBJ_X_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmDying_Frame7[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x29, OBJ_SIZE_32x16 | 0x1ac, OBJ_SPRITE_OAM | 0x2f2,
    0x29, OBJ_SIZE_16x16 | 0x1cc, OBJ_SPRITE_OAM | 0x2f6,
    0x20, OBJ_SIZE_16x16 | 0x1f3, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x25, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2e0,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fa, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_X_FLIP | 0x1fa, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmDying_Frame8[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x29, OBJ_SIZE_32x16 | 0x1ac, OBJ_SPRITE_OAM | 0x2f2,
    0x29, OBJ_SIZE_16x16 | 0x1cc, OBJ_SPRITE_OAM | 0x2f6,
    0x20, OBJ_SIZE_16x16 | 0x1f3, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x25, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2e0,
    0xf9, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fa, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x19, OBJ_X_FLIP | 0x1fa, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmDying_Frame9[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x29, OBJ_SIZE_32x16 | 0x1ac, OBJ_SPRITE_OAM | 0x2f2,
    0x29, OBJ_SIZE_16x16 | 0x1cc, OBJ_SPRITE_OAM | 0x2f6,
    0x20, OBJ_SIZE_16x16 | 0x1f3, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x25, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2e0,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fa, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_X_FLIP | 0x1fa, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmDying_Frame0[19] = {
    0x6,
    0x9, OBJ_SIZE_32x32 | 0x1d6, OBJ_SPRITE_OAM | 0x218,
    0x19, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    0xc, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21e,
    0x14, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21c,
    0xef, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xf, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmDying_Frame1[19] = {
    0x6,
    0xd, OBJ_SIZE_32x32 | 0x1d6, OBJ_SPRITE_OAM | 0x218,
    0x1d, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    0x10, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21e,
    0x18, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21c,
    0xf3, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x13, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmDying_Frame2[19] = {
    0x6,
    0xb, OBJ_SIZE_32x32 | 0x1d6, OBJ_SPRITE_OAM | 0x218,
    0x1b, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    0xe, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21e,
    0x16, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x21c,
    0xf1, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x11, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmDying_Frame3[16] = {
    0x5,
    0x16, OBJ_SIZE_32x32 | 0x1ce, OBJ_SPRITE_OAM | 0x218,
    0x1d, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x2e0,
    0xf3, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x13, 0xa, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmDying_Frame4[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x28, OBJ_SIZE_32x16 | 0x1c1, OBJ_SPRITE_OAM | 0x25c,
    0x28, OBJ_SIZE_16x16 | 0x1e1, OBJ_SPRITE_OAM | 0x361,
    0x21, OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x25, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x2e0,
    0xf7, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x17, 0x9, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmDying_Frame5[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x2c, OBJ_SIZE_32x16 | 0x1c0, OBJ_SPRITE_OAM | 0x2f2,
    0x2c, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2f6,
    0x23, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x27, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1eb, OBJ_SPRITE_OAM | 0x2e0,
    0xf9, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x19, 0x8, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmDying_Frame6[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x2a, OBJ_SIZE_32x16 | 0x1c0, OBJ_SPRITE_OAM | 0x2f2,
    0x2a, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2f6,
    0x21, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x25, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1eb, OBJ_SPRITE_OAM | 0x2e0,
    0xf7, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x17, 0x8, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmDying_Frame7[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x2b, OBJ_SIZE_32x16 | 0x1c0, OBJ_SPRITE_OAM | 0x2f2,
    0x2b, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2f6,
    0x22, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x26, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1eb, OBJ_SPRITE_OAM | 0x2e0,
    0xf8, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x18, 0x8, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmDying_Frame8[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x2b, OBJ_SIZE_32x16 | 0x1c0, OBJ_SPRITE_OAM | 0x2f2,
    0x2b, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2f6,
    0x22, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x26, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1eb, OBJ_SPRITE_OAM | 0x2e0,
    0xf9, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x19, 0x8, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmDying_Frame9[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x2b, OBJ_SIZE_32x16 | 0x1c0, OBJ_SPRITE_OAM | 0x2f2,
    0x2b, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2f6,
    0x22, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x26, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1eb, OBJ_SPRITE_OAM | 0x2e0,
    0xf8, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x18, 0x8, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_NeckDying_Frame0[16] = {
    0x5,
    0xc, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x28a,
    0xfb, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0xb, 0x1e0, OBJ_SPRITE_OAM | 0x3ee,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0x4, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckDying_Frame1[13] = {
    0x4,
    0xf, OBJ_SIZE_16x16 | 0x1e2, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xfa, OBJ_SIZE_8x32 | 0x1e7, OBJ_SPRITE_OAM | 0x320,
    0xfc, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0x7, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckDying_Frame2[13] = {
    0x4,
    0xe, OBJ_SIZE_16x16 | 0x1e2, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_8x32 | 0x1e7, OBJ_SPRITE_OAM | 0x320,
    0xfb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x28a,
    0x6, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckDying_Frame3[13] = {
    0x4,
    0xf, OBJ_SIZE_16x16 | 0x1e1, OBJ_SPRITE_OAM | 0x28a,
    0x3, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x3ce,
    0xfc, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x28a,
    0x7, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckDying_Frame4[13] = {
    0x4,
    0x12, OBJ_SIZE_16x16 | 0x1e1, OBJ_SPRITE_OAM | 0x28a,
    0x9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1d7, OBJ_SPRITE_OAM | 0x38e,
    0xff, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x28a,
    0xa, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x38e
};

static const u16 sMechaRidleyPartOAM_NeckDying_Frame5[16] = {
    0x5,
    0x1a, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1d4, OBJ_SPRITE_OAM | 0x294,
    0x3, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    0x9, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0x19, 0x1ed, OBJ_SPRITE_OAM | 0x3ee
};

static const u16 sMechaRidleyPartOAM_NeckDying_Frame6[16] = {
    0x5,
    0x19, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x11, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1d3, OBJ_SPRITE_OAM | 0x294,
    0x1, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    0x8, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0x18, 0x1ed, OBJ_SPRITE_OAM | 0x3ee
};

static const u16 sMechaRidleyPartOAM_NeckDying_Frame7[16] = {
    0x5,
    0x19, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1e, OBJ_SIZE_32x8 | 0x1d3, OBJ_SPRITE_OAM | 0x3f8,
    0x2, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x28a,
    0x9, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0x19, 0x1ed, OBJ_SPRITE_OAM | 0x3ee
};

static const u16 sMechaRidleyPartOAM_NeckDying_Frame8[16] = {
    0x5,
    0x1e, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x23, OBJ_SIZE_32x16 | 0x1cf, OBJ_SPRITE_OAM | 0x294,
    0x5, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x28a,
    0xd, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0x1d, 0x1ed, OBJ_SPRITE_OAM | 0x3ee
};

static const u16 sMechaRidleyPartOAM_NeckDying_Frame9[16] = {
    0x5,
    0x1c, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x294,
    0x3, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x28a,
    0xc, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0x1c, 0x1ec, OBJ_SPRITE_OAM | 0x3ee
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame9[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1b9, OBJ_SPRITE_OAM | 0x2f2,
    0x22, OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2f6,
    0x19, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1e, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e6, OBJ_SPRITE_OAM | 0x2e0,
    0xf1, OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_VERTICAL | 0x11, 0x5, OBJ_SPRITE_OAM | 0x321
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame8[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1c8, OBJ_SPRITE_OAM | 0x2f2,
    0x22, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x2f6,
    0x1a, OBJ_SIZE_16x16 | 0xf, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1e, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f3, OBJ_SPRITE_OAM | 0x2e0,
    0xf1, OBJ_SIZE_32x32 | 0x1f9, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x11, 0x11, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame7[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1c9, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x2f6,
    0x19, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x2e0,
    0xf0, OBJ_SIZE_32x32 | 0x1fa, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x10, 0x12, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame6[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1c9, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x2f6,
    0x19, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x2e0,
    0xef, OBJ_SIZE_32x32 | 0x1fa, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xf, 0x12, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame5[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1c9, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x2f6,
    0x18, OBJ_SIZE_16x16 | 0xf, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1c, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f3, OBJ_SPRITE_OAM | 0x2e0,
    0xee, OBJ_SIZE_32x32 | 0x1f9, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe, 0x11, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame4[16] = {
    0x5,
    0x11, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x218,
    0x18, OBJ_SIZE_16x16 | 0xf, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_SIZE_32x16 | 0x1f3, OBJ_SPRITE_OAM | 0x2e0,
    0xee, OBJ_SIZE_32x32 | 0x1f9, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe, 0x11, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame3[16] = {
    0x5,
    0x10, OBJ_SIZE_32x32 | 0x1c8, OBJ_SPRITE_OAM | 0x218,
    0x17, OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x16 | 0x1e6, OBJ_SPRITE_OAM | 0x2e0,
    0xed, OBJ_SIZE_32x32 | 0x1ff, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_VERTICAL | 0xd, 0x7, OBJ_SPRITE_OAM | 0x321
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame2[16] = {
    0x5,
    0xd, OBJ_SIZE_32x32 | 0x1bb, OBJ_SPRITE_OAM | 0x218,
    0x14, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xf, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2e0,
    0xed, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fe, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xd, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame1[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_SIZE_32x16 | 0x1ae, OBJ_SPRITE_OAM | 0x25c,
    0x1d, OBJ_SIZE_16x16 | 0x1ce, OBJ_SPRITE_OAM | 0x361,
    0x16, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1b, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1db, OBJ_SPRITE_OAM | 0x2e0,
    0xef, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xf, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame0[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_SIZE_32x16 | 0x1ae, OBJ_SPRITE_OAM | 0x2f2,
    0x20, OBJ_SIZE_16x16 | 0x1ce, OBJ_SPRITE_OAM | 0x2f6,
    0x17, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1c, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1db, OBJ_SPRITE_OAM | 0x2e0,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame10[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1ae, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1ce, OBJ_SPRITE_OAM | 0x2f6,
    0x18, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1db, OBJ_SPRITE_OAM | 0x2e0,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame9[16] = {
    0x5,
    0x11, OBJ_SIZE_32x32 | 0x1cf, OBJ_SPRITE_OAM | 0x218,
    0x18, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_SIZE_32x16 | 0x1ed, OBJ_SPRITE_OAM | 0x2e0,
    0xee, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame8[16] = {
    0x5,
    0x10, OBJ_SIZE_32x32 | 0x1c2, OBJ_SPRITE_OAM | 0x218,
    0x17, OBJ_SIZE_16x16 | 0x1fc, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2e0,
    0xed, OBJ_SIZE_32x32 | 0x1f9, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_VERTICAL | 0xd, 0x1, OBJ_SPRITE_OAM | 0x321
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame7[16] = {
    0x5,
    0xd, OBJ_SIZE_32x32 | 0x1b5, OBJ_SPRITE_OAM | 0x218,
    0x14, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0xf, OBJ_SIZE_32x16 | 0x1d3, OBJ_SPRITE_OAM | 0x2e0,
    0xed, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xd, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame6[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_SIZE_32x16 | 0x1a8, OBJ_SPRITE_OAM | 0x25c,
    0x1d, OBJ_SIZE_16x16 | 0x1c8, OBJ_SPRITE_OAM | 0x361,
    0x16, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1b, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1d5, OBJ_SPRITE_OAM | 0x2e0,
    0xef, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1f7, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xf, OBJ_X_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame5[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_SIZE_32x16 | 0x1a8, OBJ_SPRITE_OAM | 0x2f2,
    0x20, OBJ_SIZE_16x16 | 0x1c8, OBJ_SPRITE_OAM | 0x2f6,
    0x17, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1c, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1d5, OBJ_SPRITE_OAM | 0x2e0,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1f7, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_X_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame4[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1a8, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1c8, OBJ_SPRITE_OAM | 0x2f6,
    0x18, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1d5, OBJ_SPRITE_OAM | 0x2e0,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1f7, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame3[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1b3, OBJ_SPRITE_OAM | 0x2f2,
    0x22, OBJ_SIZE_16x16 | 0x1d3, OBJ_SPRITE_OAM | 0x2f6,
    0x19, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1e, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2e0,
    0xf1, OBJ_SIZE_32x32 | 0x1f7, OBJ_SPRITE_OAM | 0x298,
    OBJ_SHAPE_VERTICAL | 0x11, 0x1ff, OBJ_SPRITE_OAM | 0x321
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame2[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1c2, OBJ_SPRITE_OAM | 0x2f2,
    0x22, OBJ_SIZE_16x16 | 0x1e2, OBJ_SPRITE_OAM | 0x2f6,
    0x1a, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1e, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ed, OBJ_SPRITE_OAM | 0x2e0,
    0xf1, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x11, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame1[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1c3, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x2f6,
    0x19, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x2e0,
    0xf0, OBJ_SIZE_32x32 | 0x1f4, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x10, 0xc, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame0[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1c3, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x2f6,
    0x19, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x2e0,
    0xef, OBJ_SIZE_32x32 | 0x1f4, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xf, 0xc, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame10[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x21, OBJ_SIZE_32x16 | 0x1c3, OBJ_SPRITE_OAM | 0x2f2,
    0x21, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x2f6,
    0x18, OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1c, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x2e0,
    0xee, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe, 0xb, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmSwingingAtGround_Frame6[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x18e, OBJ_SPRITE_OAM | 0x25c,
    0x5, OBJ_SIZE_16x16 | 0x1ae, OBJ_SPRITE_OAM | 0x361,
    0x5, OBJ_SIZE_16x16 | 0x1d8, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1bd, OBJ_SPRITE_OAM | 0x372,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1cd, OBJ_SPRITE_OAM | 0x372,
    0xf1, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x200,
    0x1, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x332
};

static const u16 sMechaRidleyPartOAM_LeftArmSwingingAtGround_Frame7[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x19c, OBJ_SPRITE_OAM | 0x25c,
    0x22, OBJ_SIZE_16x16 | 0x1bc, OBJ_SPRITE_OAM | 0x361,
    0xc, OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x28a,
    0x1b, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1c6, OBJ_SPRITE_OAM | 0x21e,
    0x13, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d6, OBJ_SPRITE_OAM | 0x21c,
    0xf5, OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0x5, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x332
};

static const u16 sMechaRidleyPartOAM_LeftArmSwingingAtGround_Frame8[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0x23, OBJ_SIZE_32x16 | 0x19c, OBJ_SPRITE_OAM | 0x2f2,
    0x23, OBJ_SIZE_16x16 | 0x1bc, OBJ_SPRITE_OAM | 0x2f6,
    0xa, OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x28a,
    0x19, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1c6, OBJ_SPRITE_OAM | 0x21e,
    0x11, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d6, OBJ_SPRITE_OAM | 0x21c,
    0xf4, OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0x4, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x332
};

static const u16 sMechaRidleyPartOAM_LeftArmSwingingAtGround_Frame9[16] = {
    0x5,
    0x10, OBJ_SIZE_32x32 | 0x1bd, OBJ_SPRITE_OAM | 0x218,
    0x18, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x14, OBJ_SIZE_32x16 | 0x1da, OBJ_SPRITE_OAM | 0x2e0,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x12, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_LeftArmSwingingAtCloseGround_Frame9[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x22, OBJ_SIZE_32x16 | 0x1a9, OBJ_SPRITE_OAM | 0x2f2,
    0x22, OBJ_SIZE_16x16 | 0x1c9, OBJ_SPRITE_OAM | 0x2f6,
    0x19, OBJ_SIZE_16x16 | 0x1f3, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x1f, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1d7, OBJ_SPRITE_OAM | 0x2e0,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1fc, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x334
};

static const u16 sMechaRidleyPartOAM_EyeDying_Frame0[7] = {
    0x2,
    0xf9, 0x1fe, OBJ_SPRITE_OAM | 0x1363,
    0xfa, 0x1fd, OBJ_SPRITE_OAM | 0x1383
};

static const struct FrameData sMechaRidleyPartOAM_Tail[2] = {
    sMechaRidleyPartOAM_Tail_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_Ring[2] = {
    sMechaRidleyPartOAM_Ring_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_Cover[2] = {
    sMechaRidleyPartOAM_Cover_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_Torso[2] = {
    sMechaRidleyPartOAM_Torso_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyOAM_Idle[5] = {
    sMechaRidleyOAM_Idle_Frame0,
    8,
    sMechaRidleyOAM_Idle_Frame1,
    8,
    sMechaRidleyOAM_Idle_Frame2,
    8,
    sMechaRidleyOAM_Idle_Frame1,
    8,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_HeadIdle[2] = {
    sMechaRidleyPartOAM_HeadIdle_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_HeadChargingFireballs[4] = {
    sMechaRidleyPartOAM_HeadChargingFireballs_Frame0,
    4,
    sMechaRidleyPartOAM_HeadChargingFireballs_Frame1,
    4,
    sMechaRidleyPartOAM_HeadChargingFireballs_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_HeadSpittingFireballs[4] = {
    sMechaRidleyPartOAM_HeadSpittingFireballs_Frame0,
    2,
    sMechaRidleyPartOAM_HeadSpittingFireballs_Frame1,
    2,
    sMechaRidleyPartOAM_HeadSpittingFireballs_Frame2,
    2,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_HeadDechargingFireballs[4] = {
    sMechaRidleyPartOAM_HeadSpittingFireballs_Frame0,
    4,
    sMechaRidleyPartOAM_HeadChargingFireballs_Frame1,
    4,
    sMechaRidleyPartOAM_HeadChargingFireballs_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_EyeIdle[7] = {
    sMechaRidleyPartOAM_EyeIdle_Frame0,
    UCHAR_MAX,
    sMechaRidleyPartOAM_EyeIdle_Frame1,
    6,
    sMechaRidleyPartOAM_EyeIdle_Frame0,
    6,
    sMechaRidleyPartOAM_EyeIdle_Frame3,
    6,
    sMechaRidleyPartOAM_EyeIdle_Frame4,
    16,
    sMechaRidleyPartOAM_EyeIdle_Frame3,
    4,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_EyeGlowing[5] = {
    sMechaRidleyPartOAM_EyeGlowing_Frame0,
    5,
    sMechaRidleyPartOAM_EyeGlowing_Frame1,
    5,
    sMechaRidleyPartOAM_EyeGlowing_Frame0,
    5,
    sMechaRidleyPartOAM_EyeIdle_Frame0,
    5,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_EyeShootingLaserForward[8] = {
    sMechaRidleyPartOAM_EyeShootingLaserForward_Frame0,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserForward_Frame1,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserForward_Frame2,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserForward_Frame3,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserForward_Frame4,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserForward_Frame5,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserForward_Frame6,
    2,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_EyeShootingLaserSlightlyDown[8] = {
    sMechaRidleyPartOAM_EyeShootingLaserSlightlyDown_Frame0,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserSlightlyDown_Frame1,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserSlightlyDown_Frame2,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserSlightlyDown_Frame3,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserSlightlyDown_Frame4,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserSlightlyDown_Frame5,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserSlightlyDown_Frame6,
    2,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_EyeShootingLaserDown[8] = {
    sMechaRidleyPartOAM_EyeShootingLaserDown_Frame0,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserDown_Frame1,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserDown_Frame2,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserDown_Frame3,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserDown_Frame4,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserDown_Frame5,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserDown_Frame6,
    2,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_EyeShootingLaserSlightlyUp[8] = {
    sMechaRidleyPartOAM_EyeShootingLaserSlightlyUp_Frame0,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserSlightlyUp_Frame1,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserSlightlyUp_Frame2,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserSlightlyUp_Frame3,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserSlightlyUp_Frame4,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserSlightlyUp_Frame5,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserSlightlyUp_Frame6,
    2,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_EyeShootingLaserUp[8] = {
    sMechaRidleyPartOAM_EyeShootingLaserUp_Frame0,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserUp_Frame1,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserUp_Frame2,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserUp_Frame3,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserUp_Frame4,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserUp_Frame5,
    2,
    sMechaRidleyPartOAM_EyeShootingLaserUp_Frame6,
    2,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_EyeInactive[3] = {
    sMechaRidleyPartOAM_EyeInactive_Frame0,
    6,
    sMechaRidleyPartOAM_EyeInactive_Frame1,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_LeftArmCrawlingForward[12] = {
    sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame0,
    8,
    sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame1,
    8,
    sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame2,
    8,
    sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame3,
    4,
    sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame4,
    4,
    sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame5,
    8,
    sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame6,
    8,
    sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame7,
    8,
    sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame8,
    4,
    sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame9,
    4,
    sMechaRidleyPartOAM_LeftArmCrawlingForward_Frame10,
    8,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_RightArmCrawlingForward[12] = {
    sMechaRidleyPartOAM_RightArmCrawlingForward_Frame0,
    8,
    sMechaRidleyPartOAM_RightArmCrawlingForward_Frame1,
    8,
    sMechaRidleyPartOAM_RightArmCrawlingForward_Frame2,
    8,
    sMechaRidleyPartOAM_RightArmCrawlingForward_Frame3,
    4,
    sMechaRidleyPartOAM_RightArmCrawlingForward_Frame4,
    4,
    sMechaRidleyPartOAM_RightArmCrawlingForward_Frame5,
    8,
    sMechaRidleyPartOAM_RightArmCrawlingForward_Frame6,
    8,
    sMechaRidleyPartOAM_RightArmCrawlingForward_Frame7,
    8,
    sMechaRidleyPartOAM_RightArmCrawlingForward_Frame8,
    4,
    sMechaRidleyPartOAM_RightArmCrawlingForward_Frame9,
    4,
    sMechaRidleyPartOAM_RightArmCrawlingForward_Frame10,
    8,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_LeftArmHoldingUp[6] = {
    sMechaRidleyPartOAM_LeftArmHoldingUp_Frame0,
    8,
    sMechaRidleyPartOAM_LeftArmHoldingUp_Frame1,
    8,
    sMechaRidleyPartOAM_LeftArmHoldingUp_Frame2,
    8,
    sMechaRidleyPartOAM_LeftArmHoldingUp_Frame3,
    8,
    sMechaRidleyPartOAM_LeftArmHoldingUp_Frame4,
    40,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_RightArmHoldingUp[6] = {
    sMechaRidleyPartOAM_RightArmHoldingUp_Frame0,
    8,
    sMechaRidleyPartOAM_RightArmHoldingUp_Frame1,
    8,
    sMechaRidleyPartOAM_RightArmHoldingUp_Frame2,
    8,
    sMechaRidleyPartOAM_RightArmHoldingUp_Frame3,
    8,
    sMechaRidleyPartOAM_RightArmHoldingUp_Frame4,
    40,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_LeftArmHeldUp[2] = {
    sMechaRidleyPartOAM_LeftArmHoldingUp_Frame4,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_RightArmHeldUp[2] = {
    sMechaRidleyPartOAM_RightArmHoldingUp_Frame4,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_LeftArmLayingDown[5] = {
    sMechaRidleyPartOAM_LeftArmLayingDown_Frame0,
    4,
    sMechaRidleyPartOAM_LeftArmLayingDown_Frame1,
    4,
    sMechaRidleyPartOAM_LeftArmLayingDown_Frame2,
    4,
    sMechaRidleyPartOAM_LeftArmLayingDown_Frame3,
    2,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_RightArmLayingDown[5] = {
    sMechaRidleyPartOAM_RightArmLayingDown_Frame0,
    4,
    sMechaRidleyPartOAM_RightArmLayingDown_Frame1,
    4,
    sMechaRidleyPartOAM_RightArmLayingDown_Frame2,
    4,
    sMechaRidleyPartOAM_RightArmLayingDown_Frame3,
    2,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_LeftArmTrembling[7] = {
    sMechaRidleyPartOAM_LeftArmTrembling_Frame0,
    40,
    sMechaRidleyPartOAM_LeftArmTrembling_Frame1,
    4,
    sMechaRidleyPartOAM_LeftArmTrembling_Frame2,
    4,
    sMechaRidleyPartOAM_LeftArmTrembling_Frame3,
    40,
    sMechaRidleyPartOAM_LeftArmTrembling_Frame1,
    4,
    sMechaRidleyPartOAM_LeftArmTrembling_Frame5,
    4,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_RightArmTrembling[7] = {
    sMechaRidleyPartOAM_RightArmTrembling_Frame0,
    40,
    sMechaRidleyPartOAM_RightArmTrembling_Frame1,
    4,
    sMechaRidleyPartOAM_RightArmTrembling_Frame2,
    4,
    sMechaRidleyPartOAM_RightArmTrembling_Frame3,
    40,
    sMechaRidleyPartOAM_RightArmTrembling_Frame1,
    4,
    sMechaRidleyPartOAM_RightArmTrembling_Frame5,
    4,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_LeftArmIdle[2] = {
    sMechaRidleyPartOAM_LeftArmTrembling_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_RightArmIdle[2] = {
    sMechaRidleyPartOAM_RightArmTrembling_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_LeftArmSwinging[9] = {
    sMechaRidleyPartOAM_LeftArmSwinging_Frame0,
    6,
    sMechaRidleyPartOAM_LeftArmSwinging_Frame1,
    6,
    sMechaRidleyPartOAM_LeftArmSwinging_Frame2,
    6,
    sMechaRidleyPartOAM_LeftArmSwinging_Frame3,
    20,
    sMechaRidleyPartOAM_LeftArmSwinging_Frame4,
    4,
    sMechaRidleyPartOAM_LeftArmSwinging_Frame5,
    4,
    sMechaRidleyPartOAM_LeftArmSwinging_Frame6,
    4,
    sMechaRidleyPartOAM_LeftArmSwinging_Frame7,
    4,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_NeckLow[2] = {
    sMechaRidleyPartOAM_NeckLow_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_NeckMiddle[2] = {
    sMechaRidleyPartOAM_NeckMiddle_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_NeckHigh[2] = {
    sMechaRidleyPartOAM_NeckHigh_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_NeckRotateLow[10] = {
    sMechaRidleyPartOAM_NeckRotateLow_Frame0,
    3,
    sMechaRidleyPartOAM_NeckRotateLow_Frame1,
    3,
    sMechaRidleyPartOAM_NeckRotateLow_Frame2,
    3,
    sMechaRidleyPartOAM_NeckRotateLow_Frame3,
    3,
    sMechaRidleyPartOAM_NeckRotateLow_Frame4,
    3,
    sMechaRidleyPartOAM_NeckRotateLow_Frame2,
    3,
    sMechaRidleyPartOAM_NeckRotateLow_Frame1,
    3,
    sMechaRidleyPartOAM_NeckRotateLow_Frame0,
    3,
    sMechaRidleyPartOAM_NeckMiddleToLow_Frame1,
    3,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_NeckRotateMiddle[10] = {
    sMechaRidleyPartOAM_NeckRotateMiddle_Frame0,
    3,
    sMechaRidleyPartOAM_NeckRotateMiddle_Frame1,
    3,
    sMechaRidleyPartOAM_NeckRotateMiddle_Frame2,
    3,
    sMechaRidleyPartOAM_NeckRotateMiddle_Frame3,
    3,
    sMechaRidleyPartOAM_NeckRotateMiddle_Frame4,
    3,
    sMechaRidleyPartOAM_NeckRotateMiddle_Frame2,
    3,
    sMechaRidleyPartOAM_NeckRotateMiddle_Frame1,
    3,
    sMechaRidleyPartOAM_NeckRotateMiddle_Frame0,
    3,
    sMechaRidleyPartOAM_NeckRotateMiddle_Frame8,
    3,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_NeckRotateHigh[10] = {
    sMechaRidleyPartOAM_NeckRotateHigh_Frame0,
    3,
    sMechaRidleyPartOAM_NeckRotateHigh_Frame1,
    3,
    sMechaRidleyPartOAM_NeckRotateHigh_Frame2,
    3,
    sMechaRidleyPartOAM_NeckRotateHigh_Frame3,
    3,
    sMechaRidleyPartOAM_NeckRotateHigh_Frame4,
    3,
    sMechaRidleyPartOAM_NeckRotateHigh_Frame2,
    3,
    sMechaRidleyPartOAM_NeckRotateHigh_Frame1,
    3,
    sMechaRidleyPartOAM_NeckRotateHigh_Frame0,
    3,
    sMechaRidleyPartOAM_NeckRotateHigh_Frame8,
    3,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_NeckLowToMiddle[3] = {
    sMechaRidleyPartOAM_NeckLowToMiddle_Frame0,
    3,
    sMechaRidleyPartOAM_NeckLowToMiddle_Frame1,
    3,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_NeckMiddleToHigh[3] = {
    sMechaRidleyPartOAM_NeckMiddleToHigh_Frame0,
    3,
    sMechaRidleyPartOAM_NeckMiddleToHigh_Frame1,
    3,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_NeckHighToMiddle[3] = {
    sMechaRidleyPartOAM_NeckMiddleToHigh_Frame0,
    3,
    sMechaRidleyPartOAM_NeckRotateMiddle_Frame8,
    3,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_NeckMiddleToLow[3] = {
    sMechaRidleyPartOAM_NeckLowToMiddle_Frame0,
    3,
    sMechaRidleyPartOAM_NeckMiddleToLow_Frame1,
    3,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_NeckLowToHigh[5] = {
    sMechaRidleyPartOAM_NeckLowToMiddle_Frame0,
    3,
    sMechaRidleyPartOAM_NeckMiddle_Frame0,
    3,
    sMechaRidleyPartOAM_NeckMiddleToHigh_Frame0,
    3,
    sMechaRidleyPartOAM_NeckMiddleToHigh_Frame1,
    3,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_NeckHighToLow[5] = {
    sMechaRidleyPartOAM_NeckMiddleToHigh_Frame0,
    3,
    sMechaRidleyPartOAM_NeckMiddle_Frame0,
    3,
    sMechaRidleyPartOAM_NeckLowToMiddle_Frame0,
    3,
    sMechaRidleyPartOAM_NeckLowToMiddle_Frame1,
    3,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_NeckLow_2[2] = {
    sMechaRidleyPartOAM_NeckLow_2_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_NeckMiddle_2[2] = {
    sMechaRidleyPartOAM_NeckMiddle_2_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_NeckHigh_2[2] = {
    sMechaRidleyPartOAM_NeckHigh_2_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_MissileLauncherClosed[2] = {
    sMechaRidleyPartOAM_MissileLauncherClosed_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_MissileLauncherOpening[9] = {
    sMechaRidleyPartOAM_MissileLauncherOpening_Frame0,
    3,
    sMechaRidleyPartOAM_MissileLauncherOpening_Frame1,
    3,
    sMechaRidleyPartOAM_MissileLauncherOpening_Frame2,
    3,
    sMechaRidleyPartOAM_MissileLauncherOpening_Frame3,
    16,
    sMechaRidleyPartOAM_MissileLauncherOpening_Frame4,
    3,
    sMechaRidleyPartOAM_MissileLauncherOpening_Frame5,
    3,
    sMechaRidleyPartOAM_MissileLauncherOpening_Frame6,
    3,
    sMechaRidleyPartOAM_MissileLauncherOpening_Frame7,
    16,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_MissileLauncherOpened[3] = {
    sMechaRidleyPartOAM_MissileLauncherOpening_Frame7,
    5,
    sMechaRidleyPartOAM_MissileLauncherOpened_Frame1,
    5,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_MissileLauncherClosing[9] = {
    sMechaRidleyPartOAM_MissileLauncherOpening_Frame7,
    16,
    sMechaRidleyPartOAM_MissileLauncherOpening_Frame6,
    3,
    sMechaRidleyPartOAM_MissileLauncherOpening_Frame5,
    3,
    sMechaRidleyPartOAM_MissileLauncherOpening_Frame4,
    3,
    sMechaRidleyPartOAM_MissileLauncherOpening_Frame3,
    16,
    sMechaRidleyPartOAM_MissileLauncherOpening_Frame2,
    3,
    sMechaRidleyPartOAM_MissileLauncherOpening_Frame1,
    3,
    sMechaRidleyPartOAM_MissileLauncherOpening_Frame0,
    3,
    NULL,
    0
};

static const struct FrameData sMechaRidleyMissileOAM[2] = {
    sMechaRidleyMissileOAM_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyFireballOAM[5] = {
    sMechaRidleyFireballOAM_Frame0,
    2,
    sMechaRidleyFireballOAM_Frame1,
    2,
    sMechaRidleyFireballOAM_Frame2,
    2,
    sMechaRidleyFireballOAM_Frame3,
    2,
    NULL,
    0
};

static const struct FrameData sMechaRidleyLaserOAM_Forward[4] = {
    sMechaRidleyLaserOAM_Forward_Frame0,
    3,
    sMechaRidleyLaserOAM_Forward_Frame1,
    3,
    sMechaRidleyLaserOAM_Forward_Frame2,
    1,
    NULL,
    0
};

static const struct FrameData sMechaRidleyLaserOAM_SlightlyDown[4] = {
    sMechaRidleyLaserOAM_SlightlyDown_Frame0,
    3,
    sMechaRidleyLaserOAM_SlightlyDown_Frame1,
    3,
    sMechaRidleyLaserOAM_Forward_Frame2,
    1,
    NULL,
    0
};

static const struct FrameData sMechaRidleyLaserOAM_Down[4] = {
    sMechaRidleyLaserOAM_Down_Frame0,
    3,
    sMechaRidleyLaserOAM_Down_Frame1,
    3,
    sMechaRidleyLaserOAM_Forward_Frame2,
    1,
    NULL,
    0
};

static const struct FrameData sMechaRidleyLaserOAM_SlightlyUp[4] = {
    sMechaRidleyLaserOAM_SlightlyUp_Frame0,
    3,
    sMechaRidleyLaserOAM_SlightlyUp_Frame1,
    3,
    sMechaRidleyLaserOAM_Forward_Frame2,
    1,
    NULL,
    0
};

static const struct FrameData sMechaRidleyLaserOAM_Up[4] = {
    sMechaRidleyLaserOAM_Up_Frame0,
    3,
    sMechaRidleyLaserOAM_Up_Frame1,
    3,
    sMechaRidleyLaserOAM_Forward_Frame2,
    1,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_LeftArmDying[11] = {
    sMechaRidleyPartOAM_LeftArmDying_Frame0,
    8,
    sMechaRidleyPartOAM_LeftArmDying_Frame1,
    8,
    sMechaRidleyPartOAM_LeftArmDying_Frame2,
    40,
    sMechaRidleyPartOAM_LeftArmDying_Frame3,
    8,
    sMechaRidleyPartOAM_LeftArmDying_Frame4,
    8,
    sMechaRidleyPartOAM_LeftArmDying_Frame5,
    8,
    sMechaRidleyPartOAM_LeftArmDying_Frame6,
    40,
    sMechaRidleyPartOAM_LeftArmDying_Frame7,
    8,
    sMechaRidleyPartOAM_LeftArmDying_Frame8,
    8,
    sMechaRidleyPartOAM_LeftArmDying_Frame9,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_RightArmDying[11] = {
    sMechaRidleyPartOAM_RightArmDying_Frame0,
    8,
    sMechaRidleyPartOAM_RightArmDying_Frame1,
    8,
    sMechaRidleyPartOAM_RightArmDying_Frame2,
    40,
    sMechaRidleyPartOAM_RightArmDying_Frame3,
    8,
    sMechaRidleyPartOAM_RightArmDying_Frame4,
    8,
    sMechaRidleyPartOAM_RightArmDying_Frame5,
    8,
    sMechaRidleyPartOAM_RightArmDying_Frame6,
    40,
    sMechaRidleyPartOAM_RightArmDying_Frame7,
    8,
    sMechaRidleyPartOAM_RightArmDying_Frame8,
    8,
    sMechaRidleyPartOAM_RightArmDying_Frame9,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_NeckDying[11] = {
    sMechaRidleyPartOAM_NeckDying_Frame0,
    8,
    sMechaRidleyPartOAM_NeckDying_Frame1,
    8,
    sMechaRidleyPartOAM_NeckDying_Frame2,
    40,
    sMechaRidleyPartOAM_NeckDying_Frame3,
    8,
    sMechaRidleyPartOAM_NeckDying_Frame4,
    8,
    sMechaRidleyPartOAM_NeckDying_Frame5,
    8,
    sMechaRidleyPartOAM_NeckDying_Frame6,
    40,
    sMechaRidleyPartOAM_NeckDying_Frame7,
    8,
    sMechaRidleyPartOAM_NeckDying_Frame8,
    8,
    sMechaRidleyPartOAM_NeckDying_Frame9,
    UCHAR_MAX,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_LeftArmCrawlingBackwards[12] = {
    sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame0,
    4,
    sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame1,
    4,
    sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame2,
    8,
    sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame3,
    8,
    sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame4,
    8,
    sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame5,
    4,
    sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame6,
    4,
    sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame7,
    4,
    sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame8,
    4,
    sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame9,
    4,
    sMechaRidleyPartOAM_LeftArmCrawlingBackwards_Frame10,
    4,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_RightArmCrawlingBackwards[12] = {
    sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame0,
    4,
    sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame1,
    4,
    sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame2,
    8,
    sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame3,
    8,
    sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame4,
    8,
    sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame5,
    4,
    sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame6,
    4,
    sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame7,
    4,
    sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame8,
    4,
    sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame9,
    4,
    sMechaRidleyPartOAM_RightArmCrawlingBackwards_Frame10,
    4,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_LeftArmSwingingAtGround[11] = {
    sMechaRidleyPartOAM_LeftArmSwinging_Frame0,
    6,
    sMechaRidleyPartOAM_LeftArmSwinging_Frame1,
    6,
    sMechaRidleyPartOAM_LeftArmSwinging_Frame2,
    6,
    sMechaRidleyPartOAM_LeftArmSwinging_Frame3,
    20,
    sMechaRidleyPartOAM_LeftArmSwinging_Frame4,
    6,
    sMechaRidleyPartOAM_LeftArmSwinging_Frame5,
    4,
    sMechaRidleyPartOAM_LeftArmSwingingAtGround_Frame6,
    4,
    sMechaRidleyPartOAM_LeftArmSwingingAtGround_Frame7,
    4,
    sMechaRidleyPartOAM_LeftArmSwingingAtGround_Frame8,
    30,
    sMechaRidleyPartOAM_LeftArmSwingingAtGround_Frame9,
    4,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_LeftArmSwingingAtCloseGround[11] = {
    sMechaRidleyPartOAM_LeftArmSwinging_Frame0,
    6,
    sMechaRidleyPartOAM_LeftArmSwinging_Frame1,
    6,
    sMechaRidleyPartOAM_LeftArmSwinging_Frame2,
    6,
    sMechaRidleyPartOAM_LeftArmSwinging_Frame3,
    20,
    sMechaRidleyPartOAM_LeftArmSwinging_Frame4,
    4,
    sMechaRidleyPartOAM_LeftArmSwinging_Frame5,
    4,
    sMechaRidleyPartOAM_LeftArmSwingingAtGround_Frame6,
    4,
    sMechaRidleyPartOAM_LeftArmSwingingAtGround_Frame7,
    4,
    sMechaRidleyPartOAM_LeftArmSwingingAtGround_Frame8,
    30,
    sMechaRidleyPartOAM_LeftArmSwingingAtGround_Frame9,
    4,
    NULL,
    0
};

static const struct FrameData sMechaRidleyPartOAM_EyeDying[3] = {
    sMechaRidleyPartOAM_EyeDying_Frame0,
    4,
    sMechaRidleyPartOAM_EyeInactive_Frame1,
    4,
    NULL,
    0
};

#endif