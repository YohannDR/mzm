#ifndef VIOLA_DATA_C
#define VIOLA_DATA_C

#include "../../types.h"
#include "../../oam.h"

static const u32 sViolaBlueGFX[302];
static const u16 sViolaBluePAL[16];
static const u32 sViolaOrangeGFX[305];
static const u16 sViolaOrangePAL[16];

static const u16 sViolaOAM_Moving_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

static const u16 sViolaOAM_Moving_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

static const u16 sViolaOAM_Moving_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

static const u16 sViolaOAM_Moving_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

static const u16 sViolaOAM_Moving_Frame4[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

static const u16 sViolaOAM_Moving_Frame5[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sViolaOAM_Moving_Frame6[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

static const u16 sViolaOAM_Moving_Frame7[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

static const u16 sViolaOAM_Moving_Frame8[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

static const u16 sViolaOAM_MovingOffsetUp_Frame0[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

static const u16 sViolaOAM_MovingOffsetUp_Frame1[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

static const u16 sViolaOAM_MovingOffsetUp_Frame2[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

static const u16 sViolaOAM_MovingOffsetUp_Frame3[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

static const u16 sViolaOAM_MovingOffsetUp_Frame4[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

static const u16 sViolaOAM_MovingOffsetUp_Frame5[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sViolaOAM_MovingOffsetUp_Frame6[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

static const u16 sViolaOAM_MovingOffsetUp_Frame7[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

static const u16 sViolaOAM_MovingOffsetUp_Frame8[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

static const u16 sViolaOAM_MovingOffsetRight_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x200
};

static const u16 sViolaOAM_MovingOffsetRight_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x202
};

static const u16 sViolaOAM_MovingOffsetRight_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x204
};

static const u16 sViolaOAM_MovingOffsetRight_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x206
};

static const u16 sViolaOAM_MovingOffsetRight_Frame4[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x208
};

static const u16 sViolaOAM_MovingOffsetRight_Frame5[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sViolaOAM_MovingOffsetRight_Frame6[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x20c
};

static const u16 sViolaOAM_MovingOffsetRight_Frame7[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x20e
};

static const u16 sViolaOAM_MovingOffsetRight_Frame8[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0xf8, OBJ_SPRITE_OAM | 0x210
};

static const u16 sViolaOAM_MovingOffsetDown_Frame0[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

static const u16 sViolaOAM_MovingOffsetDown_Frame1[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

static const u16 sViolaOAM_MovingOffsetDown_Frame2[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

static const u16 sViolaOAM_MovingOffsetDown_Frame3[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

static const u16 sViolaOAM_MovingOffsetDown_Frame4[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

static const u16 sViolaOAM_MovingOffsetDown_Frame5[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sViolaOAM_MovingOffsetDown_Frame6[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

static const u16 sViolaOAM_MovingOffsetDown_Frame7[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

static const u16 sViolaOAM_MovingOffsetDown_Frame8[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

static const struct FrameData sViolaOAM_Moving[17] = {
    sViolaOAM_Moving_Frame0,
    0xA,
    sViolaOAM_Moving_Frame1,
    0xA,
    sViolaOAM_Moving_Frame2,
    0xA,
    sViolaOAM_Moving_Frame3,
    0xA,
    sViolaOAM_Moving_Frame4,
    0xA,
    sViolaOAM_Moving_Frame5,
    0xA,
    sViolaOAM_Moving_Frame6,
    0xA,
    sViolaOAM_Moving_Frame7,
    0xA,
    sViolaOAM_Moving_Frame8,
    0xA,
    sViolaOAM_Moving_Frame7,
    0xA,
    sViolaOAM_Moving_Frame6,
    0xA,
    sViolaOAM_Moving_Frame5,
    0xA,
    sViolaOAM_Moving_Frame4,
    0xA,
    sViolaOAM_Moving_Frame3,
    0xA,
    sViolaOAM_Moving_Frame2,
    0xA,
    sViolaOAM_Moving_Frame1,
    0xA,
    NULL,
    0x0
};

static const struct FrameData sViolaOAM_MovingOffsetUp[17] = {
    sViolaOAM_MovingOffsetUp_Frame0,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame1,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame2,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame3,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame4,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame5,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame6,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame7,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame8,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame7,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame6,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame5,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame4,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame3,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame2,
    0xA,
    sViolaOAM_MovingOffsetUp_Frame1,
    0xA,
    NULL,
    0x0
};

static const struct FrameData sViolaOAM_MovingOffsetRight[17] = {
    sViolaOAM_MovingOffsetRight_Frame0,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame1,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame2,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame3,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame4,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame5,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame6,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame7,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame8,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame7,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame6,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame5,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame4,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame3,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame2,
    0xA,
    sViolaOAM_MovingOffsetRight_Frame1,
    0xA,
    NULL,
    0x0
};

static const struct FrameData sViolaOAM_MovingOffsetDown[17] = {
    sViolaOAM_MovingOffsetDown_Frame0,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame1,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame2,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame3,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame4,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame5,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame6,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame7,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame8,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame7,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame6,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame5,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame4,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame3,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame2,
    0xA,
    sViolaOAM_MovingOffsetDown_Frame1,
    0xA,
    NULL,
    0x0
};

#endif