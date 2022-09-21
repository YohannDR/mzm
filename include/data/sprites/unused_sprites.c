#ifndef UNUSED_SPRITES_DATA_C
#define UNUSED_SPRITES_DATA_C

#include "types.h"
#include "oam.h"

static const u16 sUnusedSpritesOAM_Idle_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x3151
};

static const u16 sUnusedSpritesOAM_Idle_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, 0x3150
};

static const struct FrameData sUnusedSpritesOAM_Idle[3] = {
    sUnusedSpritesOAM_Idle_Frame0,
    0x1E,
    sUnusedSpritesOAM_Idle_Frame1,
    0x1E,
    NULL,
    0x0
};

static const struct FrameData sUnusedSpritesOAM_Unused[3] = {
    sUnusedSpritesOAM_Idle_Frame0,
    0x1E,
    NULL,
    0x0
};

static const u32 sUnusedSpritesGFX[6];
static const u16 sUnusedSpritesPAL[16];

#endif