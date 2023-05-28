#include "data/sprites/viola.h"
#include "macros.h"

const u32 sViolaBlueGfx[302] = INCBIN_U32("data/sprites/ViolaBlue.gfx.lz");
const u16 sViolaBluePAL[16] = INCBIN_U16("data/sprites/ViolaBlue.pal");
const u32 sViolaOrangeGfx[305] = INCBIN_U32("data/sprites/ViolaOrange.gfx.lz");
const u16 sViolaOrangePAL[16] = INCBIN_U16("data/sprites/ViolaOrange.pal");

const u16 sViolaOAM_Moving_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sViolaOAM_Moving_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sViolaOAM_Moving_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sViolaOAM_Moving_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sViolaOAM_Moving_Frame4[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sViolaOAM_Moving_Frame5[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sViolaOAM_Moving_Frame6[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

const u16 sViolaOAM_Moving_Frame7[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

const u16 sViolaOAM_Moving_Frame8[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

const u16 sViolaOAM_MovingOffsetUp_Frame0[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sViolaOAM_MovingOffsetUp_Frame1[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sViolaOAM_MovingOffsetUp_Frame2[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sViolaOAM_MovingOffsetUp_Frame3[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sViolaOAM_MovingOffsetUp_Frame4[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sViolaOAM_MovingOffsetUp_Frame5[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sViolaOAM_MovingOffsetUp_Frame6[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

const u16 sViolaOAM_MovingOffsetUp_Frame7[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

const u16 sViolaOAM_MovingOffsetUp_Frame8[4] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

const u16 sViolaOAM_MovingOffsetRight_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x200
};

const u16 sViolaOAM_MovingOffsetRight_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x202
};

const u16 sViolaOAM_MovingOffsetRight_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x204
};

const u16 sViolaOAM_MovingOffsetRight_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x206
};

const u16 sViolaOAM_MovingOffsetRight_Frame4[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x208
};

const u16 sViolaOAM_MovingOffsetRight_Frame5[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x20a
};

const u16 sViolaOAM_MovingOffsetRight_Frame6[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x20c
};

const u16 sViolaOAM_MovingOffsetRight_Frame7[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x20e
};

const u16 sViolaOAM_MovingOffsetRight_Frame8[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16, OBJ_SPRITE_OAM | 0x210
};

const u16 sViolaOAM_MovingOffsetDown_Frame0[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sViolaOAM_MovingOffsetDown_Frame1[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sViolaOAM_MovingOffsetDown_Frame2[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sViolaOAM_MovingOffsetDown_Frame3[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sViolaOAM_MovingOffsetDown_Frame4[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sViolaOAM_MovingOffsetDown_Frame5[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sViolaOAM_MovingOffsetDown_Frame6[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

const u16 sViolaOAM_MovingOffsetDown_Frame7[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

const u16 sViolaOAM_MovingOffsetDown_Frame8[4] = {
    0x1,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

const struct FrameData sViolaOAM_Moving[17] = {
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

const struct FrameData sViolaOAM_MovingOffsetUp[17] = {
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

const struct FrameData sViolaOAM_MovingOffsetRight[17] = {
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

const struct FrameData sViolaOAM_MovingOffsetDown[17] = {
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
