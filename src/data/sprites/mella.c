#include "data/sprites/mella.h"
#include "macros.h"

const s16 sMellaIdleYMovement[65] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1,
    2, 2, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0, -1, 0, -1, 0, -1, 0,
    -1, -1, -1, -2, -2, -1, -1, -1, 0, -1, 0, -1,
    0, -1, 0, -1, 0, 0, 0, 0, SHORT_MAX
};

const s16 sMellaIdleXMovement[49] = {
    1, 0, 1, 0, 1, 1, 1, 2, 2, 1, 1, 1, 0, 1, 0,
    1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0,
    -1, 0, -1, 0, -1, 0, -1, -1, -1, -2, -2, -1,
    -1, -1, 0, -1, 0, -1, SHORT_MAX
};

const u16 sMellaGoingDownYMovement[6] = {
    1, 2, 3, 4, 5, 6
};

const u16 sMellaGoingUpYMovement[7] = {
    0, 1, 2, 3, 4, 5, 6
};

const u16 sMellaMovingXMovement[7] = {
    0, 1, 2, 3, 4, 5, 6 
};

const u32 sMellaGfx[162] = INCBIN_U32("data/sprites/Mella.gfx.lz");
const u16 sMellaPAL[16] = INCBIN_U16("data/sprites/Mella.pal");

const u16 sMellaOAM_Idle_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sMellaOAM_Idle_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sMellaOAM_Idle_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208
};

const u16 sMellaOAM_Idle_Frame3[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c
};

const u16 sMellaOAM_Idle_Frame4[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x210
};

const u16 sMellaOAM_Idle_Frame5[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x214
};

const u16 sMellaOAM_Idle_Frame6[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sMellaOAM_Idle_Frame7[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sMellaOAM_Moving_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sMellaOAM_Moving_Frame2[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sMellaOAM_Moving_Frame3[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x22c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sMellaOAM_Moving_Frame4[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208
};

const u16 sMellaOAM_Moving_Frame5[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x234,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208
};

const u16 sMellaOAM_Moving_Frame6[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x238,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x20c
};

const struct FrameData sMellaOAM_Idle[9] = {
    sMellaOAM_Idle_Frame0,
    0x6,
    sMellaOAM_Idle_Frame1,
    0x6,
    sMellaOAM_Idle_Frame2,
    0x6,
    sMellaOAM_Idle_Frame3,
    0x6,
    sMellaOAM_Idle_Frame4,
    0x6,
    sMellaOAM_Idle_Frame5,
    0x6,
    sMellaOAM_Idle_Frame6,
    0x6,
    sMellaOAM_Idle_Frame7,
    0x6,
    NULL,
    0x0
};

const struct FrameData sMelloOAM_Moving[9] = {
    sMellaOAM_Idle_Frame0,
    0x2,
    sMellaOAM_Moving_Frame1,
    0x2,
    sMellaOAM_Moving_Frame2,
    0x2,
    sMellaOAM_Moving_Frame3,
    0x2,
    sMellaOAM_Moving_Frame4,
    0x2,
    sMellaOAM_Moving_Frame5,
    0x2,
    sMellaOAM_Moving_Frame6,
    0x2,
    sMellaOAM_Idle_Frame7,
    0x2,
    NULL,
    0x0
};
