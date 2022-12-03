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


#endif