#include "data/sprites/ripper.h"
#include "macros.h"

const u32 sRipper2Gfx[212] = INCBIN_U32("data/sprites/Ripper2.gfx.lz");
const u16 sRipper2PAL[16] = INCBIN_U16("data/sprites/Ripper2.pal");

const u16 sRipper2Oam_Moving_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x200,
    0xf5, OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x212
};

const u16 sRipper2Oam_Moving_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0xc, OBJ_SPRITE_OAM | 0x20e
};

const u16 sRipper2Oam_Moving_Frame2[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0xc, OBJ_SPRITE_OAM | 0x20a
};

const u16 sRipper2Oam_TurningAround_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x204,
    0xf4, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x212
};

const u16 sRipper2Oam_TurningAround_Frame1[7] = {
    0x2,
    0xf3, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xf5, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x212
};

const struct FrameData sRipper2Oam_Moving[5] = {
    sRipper2Oam_Moving_Frame0,
    0x3,
    sRipper2Oam_Moving_Frame1,
    0x3,
    sRipper2Oam_Moving_Frame2,
    0x3,
    sRipper2Oam_Moving_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sRipper2Oam_TurningAround[3] = {
    sRipper2Oam_TurningAround_Frame0,
    0x3,
    sRipper2Oam_TurningAround_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sRipper2Oam_TurningAroundPart2[3] = {
    sRipper2Oam_TurningAround_Frame1,
    0x3,
    sRipper2Oam_TurningAround_Frame0,
    0x3,
    NULL,
    0x0
};
