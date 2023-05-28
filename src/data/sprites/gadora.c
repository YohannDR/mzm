#include "data/sprites/gadora.h"
#include "macros.h"

const u32 sGadoraGfx[585] = INCBIN_U32("data/sprites/Gadora.gfx.lz");
const u16 sGadoraPAL[32] = INCBIN_U16("data/sprites/Gadora.pal");

const u16 sGadoraOAM_EyeClosed_Frame2[22] = {
    0x7,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x24f,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x24f
};

const u16 sGadoraOAM_EyeClosed_Frame0[22] = {
    0x7,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x24f,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x24f
};

const u16 sGadoraOAM_EyeClosed_Frame1[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x24f,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x24f
};

const u16 sGadoraOAM_Warning_Frame1[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0x1ff, OBJ_SPRITE_OAM | 0x24f,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x24f
};

const u16 sGadoraOAM_Warning_Frame2[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x205,
    0xd8, 0x1ff, OBJ_SPRITE_OAM | 0x24f,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_OpeningEye_Frame5[22] = {
    0x7,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x257,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x205,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_EyeOpened_Frame0[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x208,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_EyeOpened_Frame1[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20b,
    0x0, OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x266,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x208,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_EyeOpened_Frame2[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_EyeOpened_Frame3[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_EyeOpened_Frame4[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20b,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_EyeOpened_Frame5[25] = {
    0x8,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x211,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_Frame_Unused[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20b,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_EyeMoving_Frame4[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f6, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_EyeMoving_Frame3[25] = {
    0x8,
    0xf0, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x211,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_EyeMoving_Frame0[25] = {
    0x8,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x251,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x251,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_EyeMoving_Frame1[25] = {
    0x8,
    0xf0, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x253,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x253,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_Death_Frame1[25] = {
    0x8,
    0xf0, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x253,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x253,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_Death_Frame2[25] = {
    0x8,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x253,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x253,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20b,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraBeamOAM_Moving_Frame0[19] = {
    0x6,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0xf0, 0x6, OBJ_SPRITE_OAM | 0x21b,
    0xf9, 0x4, OBJ_SPRITE_OAM | 0x23b,
    0x9, OBJ_Y_FLIP | 0x6, OBJ_SPRITE_OAM | 0x21b,
    0x0, OBJ_Y_FLIP | 0x4, OBJ_SPRITE_OAM | 0x23b
};

const u16 sGadoraBeamOAM_Moving_Frame1[7] = {
    0x2,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21e
};

const u16 sGadoraBeamOAM_Moving_Frame2[7] = {
    0x2,
    0xf1, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x25c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x25c
};

const u16 sGadoraBeamOAM_Moving_Frame3[7] = {
    0x2,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25e,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25e
};


const struct FrameData sGadoraOAM_EyeClosed[5] = {
    sGadoraOAM_EyeClosed_Frame0,
    0x8,
    sGadoraOAM_EyeClosed_Frame1,
    0x8,
    sGadoraOAM_EyeClosed_Frame2,
    0x8,
    sGadoraOAM_EyeClosed_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sGadoraOAM_Warning[7] = {
    sGadoraOAM_EyeClosed_Frame1,
    0x4,
    sGadoraOAM_Warning_Frame1,
    0x4,
    sGadoraOAM_Warning_Frame2,
    0x4,
    sGadoraOAM_Warning_Frame1,
    0x4,
    sGadoraOAM_EyeClosed_Frame1,
    0x4,
    sGadoraOAM_EyeClosed_Frame0,
    0x4,
    NULL,
    0x0
};

const struct FrameData sGadoraOAM_OpeningEye[7] = {
    sGadoraOAM_EyeClosed_Frame2,
    0x4,
    sGadoraOAM_EyeClosed_Frame0,
    0x4,
    sGadoraOAM_EyeClosed_Frame1,
    0x4,
    sGadoraOAM_Warning_Frame1,
    0x4,
    sGadoraOAM_Warning_Frame2,
    0x4,
    sGadoraOAM_OpeningEye_Frame5,
    0x4,
    NULL,
    0x0
};

const struct FrameData sGadoraBeamOAM_Moving[5] = {
    sGadoraBeamOAM_Moving_Frame0,
    0x4,
    sGadoraBeamOAM_Moving_Frame1,
    0x4,
    sGadoraBeamOAM_Moving_Frame2,
    0x4,
    sGadoraBeamOAM_Moving_Frame3,
    0x4,
    NULL,
    0x0
};

const struct FrameData sGadoraOAM_EyeMoving[7] = {
    sGadoraOAM_EyeMoving_Frame0,
    0x2,
    sGadoraOAM_EyeMoving_Frame1,
    0x4,
    sGadoraOAM_EyeMoving_Frame0,
    0x2,
    sGadoraOAM_EyeMoving_Frame3,
    0x2,
    sGadoraOAM_EyeMoving_Frame4,
    0x4,
    sGadoraOAM_EyeMoving_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sGadoraOAM_ClosingEye[5] = {
    sGadoraOAM_OpeningEye_Frame5,
    0x2,
    sGadoraOAM_Warning_Frame2,
    0x2,
    sGadoraOAM_Warning_Frame1,
    0x2,
    sGadoraOAM_EyeClosed_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sGadoraOAM_Death[5] = {
    sGadoraOAM_EyeMoving_Frame1,
    0x2,
    sGadoraOAM_Death_Frame1,
    0x2,
    sGadoraOAM_Death_Frame2,
    0x2,
    sGadoraOAM_Death_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sGadoraOAM_EyeOpened[7] = {
    sGadoraOAM_EyeOpened_Frame0,
    0x4,
    sGadoraOAM_EyeOpened_Frame1,
    0x4,
    sGadoraOAM_EyeOpened_Frame2,
    0x4,
    sGadoraOAM_EyeOpened_Frame3,
    0x4,
    sGadoraOAM_EyeOpened_Frame4,
    0x4,
    sGadoraOAM_EyeOpened_Frame5,
    0x4,
    NULL,
    0x0
};

const struct FrameData sGadoraOAM_BeforeClosing[5] = {
    sGadoraOAM_EyeOpened_Frame3,
    0x2,
    sGadoraOAM_EyeOpened_Frame2,
    0x2,
    sGadoraOAM_EyeOpened_Frame1,
    0x2,
    sGadoraOAM_EyeOpened_Frame0,
    0x2,
    NULL,
    0x0
};
