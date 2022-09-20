#ifndef GAMET_DATA_C
#define GAMET_DATA_C

#include "../../types.h"
#include "../../oam.h"

static const u32 sGametBlueGFX[168];
static const u32 sGametBluePAL[16];
static const u32 sGametRedGFX[168];
static const u32 sGametRedPAL[16];

static const u16 sGametOAM_Idle_Frame0[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x201,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x200
};

static const u16 sGametOAM_Idle_Frame1[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x203,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x200
};

static const u16 sGametOAM_Idle_Frame2[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x205,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x200
};

static const u16 sGametOAM_Moving_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x201,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x209
};

static const u16 sGametOAM_Moving_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x203,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x209
};

static const u16 sGametOAM_Moving_Frame0[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x205,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f0, OBJ_SPRITE_OAM | 0x200
};

static const struct FrameData sGametOAM_Idle[5] = {
    sGametOAM_Idle_Frame0,
    0x4,
    sGametOAM_Idle_Frame1,
    0x3,
    sGametOAM_Idle_Frame2,
    0x4,
    sGametOAM_Idle_Frame1,
    0x3,
    NULL,
    0x0
};

static const struct FrameData sGametOAM_Moving[5] = {
    sGametOAM_Moving_Frame0,
    0x2,
    sGametOAM_Moving_Frame1,
    0x1,
    sGametOAM_Moving_Frame2,
    0x3,
    sGametOAM_Moving_Frame1,
    0x1,
    NULL,
    0x0
};

#endif