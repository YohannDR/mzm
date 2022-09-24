#ifndef FALLING_CHOZO_PILLAR_DATA_C
#define FALLING_CHOZO_PILLAR_DATA_C

#include "types.h"
#include "oam.h"

static const u8 sFallingChozoPillarGFX[876];
static const u16 sFallingChozoPillarPAL[16];

static const u16 sFallingChozoPillarOAM_Falling_Frame0[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x204
};

static const struct FrameData sFallingChozoPillarOAM_Falling[2] = {
    sFallingChozoPillarOAM_Falling_Frame0,
    0xFF,
    NULL,
    0x0
};

#endif