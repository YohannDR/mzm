#include "data/sprites/rinka.h"
#include "macros.h"

const u32 sRinkaOrangeGfx[242] = INCBIN_U32("data/sprites/RinkaOrange.gfx.lz");
const u16 sRinkaOrangePAL[16] = INCBIN_U16("data/sprites/RinkaOrange.pal");
const u32 sRinkaGreenGfx[242] = INCBIN_U32("data/sprites/RinkaGreen.gfx.lz");
const u16 sRinkaGreenPAL[16] = INCBIN_U16("data/sprites/RinkaGreen.pal");

const u16 sRinkaOrangeOAM_Moving_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sRinkaOrangeOAM_Moving_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sRinkaOrangeOAM_Moving_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sRinkaOrangeOAM_Spawning_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20b
};

const u16 sRinkaOrangeOAM_Spawning_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20d
};

const u16 sRinkaOrangeOAM_Spawning_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20f
};

const u16 sRinkaOrangeOAM_Spawning_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x211
};

const u16 sRinkaOrangeOAM_Spawning_Frame4[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x233
};

const u16 sRinkaOrangeOAM_Spawning_Frame5[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x213
};

const struct FrameData sRinkaOrangeOAM_Spawning[16] = {
    sRinkaOrangeOAM_Spawning_Frame0,
    0x4,
    sRinkaOrangeOAM_Spawning_Frame1,
    0x4,
    sRinkaOrangeOAM_Spawning_Frame2,
    0x4,
    sRinkaOrangeOAM_Spawning_Frame3,
    0x4,
    sRinkaOrangeOAM_Spawning_Frame4,
    0x4,
    sRinkaOrangeOAM_Spawning_Frame5,
    0x4,
    sRinkaOrangeOAM_Spawning_Frame3,
    0x8,
    sRinkaOrangeOAM_Moving_Frame0,
    0x6,
    sRinkaOrangeOAM_Moving_Frame1,
    0x6,
    sRinkaOrangeOAM_Moving_Frame2,
    0x6,
    sRinkaOrangeOAM_Moving_Frame1,
    0x8,
    sRinkaOrangeOAM_Moving_Frame0,
    0x7,
    sRinkaOrangeOAM_Moving_Frame1,
    0x7,
    sRinkaOrangeOAM_Moving_Frame2,
    0x7,
    sRinkaOrangeOAM_Moving_Frame1,
    0x7,
    NULL,
    0x0
};

const struct FrameData sRinkaOrangeOAM_Moving[5] = {
    sRinkaOrangeOAM_Moving_Frame0,
    0xC,
    sRinkaOrangeOAM_Moving_Frame1,
    0xC,
    sRinkaOrangeOAM_Moving_Frame2,
    0xC,
    sRinkaOrangeOAM_Moving_Frame1,
    0xC,
    NULL,
    0x0
};


const u16 sRinkaGreenOAM_Moving_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sRinkaGreenOAM_Moving_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sRinkaGreenOAM_Moving_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sRinkaGreenOAM_Spawning_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20b
};

const u16 sRinkaGreenOAM_Spawning_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20d
};

const u16 sRinkaGreenOAM_Spawning_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20f
};

const u16 sRinkaGreenOAM_Spawning_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x211
};

const u16 sRinkaGreenOAM_Spawning_Frame4[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x233
};

const u16 sRinkaGreenOAM_Spawning_Frame5[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x213
};

const struct FrameData sRinkaGreenOAM_Spawning[16] = {
    sRinkaGreenOAM_Spawning_Frame0,
    0x2,
    sRinkaGreenOAM_Spawning_Frame1,
    0x2,
    sRinkaGreenOAM_Spawning_Frame2,
    0x2,
    sRinkaGreenOAM_Spawning_Frame3,
    0x2,
    sRinkaGreenOAM_Spawning_Frame4,
    0x2,
    sRinkaGreenOAM_Spawning_Frame5,
    0x2,
    sRinkaGreenOAM_Spawning_Frame3,
    0x5,
    sRinkaGreenOAM_Moving_Frame0,
    0x3,
    sRinkaGreenOAM_Moving_Frame1,
    0x3,
    sRinkaGreenOAM_Moving_Frame2,
    0x3,
    sRinkaGreenOAM_Moving_Frame1,
    0x5,
    sRinkaGreenOAM_Moving_Frame0,
    0x4,
    sRinkaGreenOAM_Moving_Frame1,
    0x4,
    sRinkaGreenOAM_Moving_Frame2,
    0x4,
    sRinkaGreenOAM_Moving_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sRinkaGreenOAM_Moving[5] = {
    sRinkaGreenOAM_Moving_Frame0,
    0x8,
    sRinkaGreenOAM_Moving_Frame1,
    0x8,
    sRinkaGreenOAM_Moving_Frame2,
    0x8,
    sRinkaGreenOAM_Moving_Frame1,
    0x8,
    NULL,
    0x0
};
