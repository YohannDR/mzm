#include "gadora.h"
#include "../../data/data.h"
#include "../globals.h"

const u8 sGadoraGFX[2340];
const u16 sGadoraPAL[32];

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
    0x2,
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


/**
 * @brief 49eb8 | 134 | Initializes a gadora sprite
 * 
 */
void GadoraInit(void)
{
    u16 yPosition;
    u16 xPosition;

    // Check isn't already dead
    if (gCurrentSprite.spriteID == PSPRITE_GADORA_KRAID)
    {
        if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_GADORA_KILLED))
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN;
        else
        {
            gCurrentSprite.status = 0x0;
            return;
        }
    }
    else if (gCurrentSprite.spriteID == PSPRITE_GADORA_RIDLEY && EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_GADORA_KILLED))
    {
        gCurrentSprite.status = 0x0;
        return;
    }

    gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
    gCurrentSprite.xPosition += 0xC;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    // Disable hatch
    gadora_hatch_update(xPosition, yPosition, FALSE); // Undefined

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        xPosition += 0x10;
    else
        xPosition -= 0x10;

    if (SpriteSpawnSecondary(SSPRITE_GADORA_EYE, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.primarySpriteRAMSlot, yPosition, xPosition, 0x0) == 0xFF)
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.pose = GADORA_POSE_IDLE_INIT;

        gCurrentSprite.drawDistanceTopOffset = 0x28;
        gCurrentSprite.drawDistanceBottomOffset = 0x28;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

        gCurrentSprite.hitboxTopOffset = -0x78;
        gCurrentSprite.hitboxBottomOffset = 0x78;
        gCurrentSprite.hitboxLeftOffset = -0x14;
        gCurrentSprite.hitboxRightOffset = 0x14;

        gCurrentSprite.pOam = sGadoraOAM_EyeClosed;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        gCurrentSprite.drawOrder = 0x5;
        gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0x0];

        // Change palette if ridley gadora
        if (gCurrentSprite.spriteID == PSPRITE_GADORA_RIDLEY)
        {
            gCurrentSprite.absolutePaletteRow = 0x1;
            gCurrentSprite.paletteRow = 0x1;
        }
    }
}

/**
 * @brief 49fec | 30 | Initializes a gadora to be idle
 * 
 */
void GadoraIdleInit(void)
{
    gCurrentSprite.pose = GADORA_POSE_SAMUS_DETECTION;
    gCurrentSprite.pOam = sGadoraOAM_EyeClosed;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.timer = gSpriteRNG * 0x4 + 0x3D;
}

/**
 * @brief 4a01c | 54 | Checks if samus is in range to open the eye
 * 
 */
void GadoraSamusDetection(void)
{
    gCurrentSprite.timer--; // Timer before checking for samus
    if (gCurrentSprite.timer == 0x0)
    {
        // Check if samus in front
        if (SpriteUtilCheckSamusNearSpriteFrontBehind(BLOCK_SIZE * 0x2, BLOCK_SIZE * 0x7, 0x0) == NSAB_IN_FRONT)
        {
            gCurrentSprite.pose = GADORA_POSE_CHECK_WARNING_ENDED;
            gCurrentSprite.pOam = sGadoraOAM_Warning;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
        else
            gCurrentSprite.timer = gSpriteRNG * 0x4 + 0x3D; // Reset timer
    }
}

/**
 * @brief 4a070 | 34 | Checks if the warning animation ended
 * 
 */
void GadoraCheckWarningAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = GADORA_POSE_CHECK_OPENING_EYE_ENDED;
        gCurrentSprite.pOam = sGadoraOAM_OpeningEye;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        SoundPlay(0x25A);
    }
}

/**
 * @brief 4a0a4 | 38 | Checks if the opening eye animation ended
 * 
 */
void GadoraCheckOpeningEyeAnimEnded(void)
{
    u16 xPosition;
    u16 status;
    
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = GADORA_POSE_EYE_OPENED;
        gCurrentSprite.pOam = sGadoraOAM_EyeOpened;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.timer = 0x3C; // Timer for how long to stay open
        if (gCurrentSprite.spriteID == PSPRITE_GADORA_RIDLEY)
        {
            gCurrentSprite.timer = 0x58; // Longer timer because of beam
            // Spawn beam
            xPosition = gCurrentSprite.xPosition + 0x10;
            status = SPRITE_STATUS_XFLIP;
            SpriteSpawnSecondary(SSPRITE_GADORA_BEAM, 0x0, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                gCurrentSprite.yPosition, xPosition, status);
        }
    }
}

/**
 * @brief 4a10c | 74 | Handles the gadora having its eye opened
 * 
 */
void GadoraEyeOpened(void)
{
    if (gCurrentSprite.timer == 0x0)
    {
        // Timer done, close eye
        gCurrentSprite.pose = GADORA_POSE_CHECK_CLOSING_EYE_ENDED;
        gCurrentSprite.pOam = sGadoraOAM_ClosingEye;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        SoundPlay(0x25B);
    }
    else
    {
        gCurrentSprite.timer--; // Timer fow how long it stays open
        // Check set the eye moving OAM
        if (gCurrentSprite.pOam == sGadoraOAM_EyeOpened)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sGadoraOAM_EyeMoving;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
            }
        }
        else if (gCurrentSprite.timer == 0x7)
        {
            // Eye will soon close, set before closing OAM
            gCurrentSprite.pOam = sGadoraOAM_BeforeClosing;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }
}

/**
 * @brief 4a180 | 1c | Checks if the closing eye animation almost ended
 * 
 */
void GadoraCheckClosingEyeAnimNearEnded(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = GADORA_POSE_IDLE_INIT; // Set idle
}

/**
 * @brief 4a19c | 30 | Initializes a gadara to be dying
 * 
 */
void GadoraDeathGFXInit(void)
{
    gCurrentSprite.pose = GADORA_POSE_DEATH;
    gCurrentSprite.pOam = sGadoraOAM_Death;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.timer = 0x28; // Death animation timer
    gCurrentSprite.samusCollision = SSC_NONE;
}

/**
 * @brief 4a1cc | d4 | Handles the death of a gadora
 * 
 */
void GadoraDeath(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 rng;
    u8 drop;
    u8 timer;
    u32 yOffset;
    
    timer = --gCurrentSprite.timer;
    if (!(timer & 0x3))
    {
        if (timer & 0x4)
            // Set stun (white) palette
            gCurrentSprite.paletteRow = 0xE - (gCurrentSprite.spritesetGFXSlot + gCurrentSprite.frozenPaletteRowOffset);
        else
        {
            // Set normal palette
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
            if (timer == 0x0)
            {
                yPosition = gCurrentSprite.yPosition;
                xPosition = gCurrentSprite.xPosition;

                // Re-enable hatch
                gadora_hatch_update(xPosition, yPosition, TRUE); // Undefiend

                // Set event
                if (gCurrentSprite.spriteID == PSPRITE_GADORA_KRAID)
                    EventFunction(EVENT_ACTION_SETTING, EVENT_KRAID_GADORA_KILLED);
                else if (gCurrentSprite.spriteID == PSPRITE_GADORA_RIDLEY)
                    EventFunction(EVENT_ACTION_SETTING, EVENT_RIDLEY_GADORA_KILLED);

                rng = gSpriteRNG;
                xPosition += 0x10;
                yOffset = rng - 0x48;

                // Kill sprite
                SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition - yOffset, xPosition - rng, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);

                // Create additional drop if the gadora spawned a drop
                if (gCurrentSprite.status)
                {
                    if (rng & 0x1)
                        drop = PSPRITE_LARGE_ENERGY_DROP;
                    else
                        drop = PSPRITE_MISSILE_DROP;

                    SpriteSpawnDropFollowers(drop, gCurrentSprite.roomSlot, 0x0, gCurrentSprite.primarySpriteRAMSlot, yPosition, xPosition, 0x0);
                }
            }
        }
    }
}

/**
 * @brief 4a2a0 | 78 | Gadora AI
 * 
 */
void Gadora(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            GadoraInit();
            break;

        case GADORA_POSE_IDLE_INIT:
            GadoraIdleInit();

        case GADORA_POSE_SAMUS_DETECTION:
            GadoraSamusDetection();
            break;

        case GADORA_POSE_CHECK_WARNING_ENDED:
            GadoraCheckWarningAnimEnded();
            break;

        case GADORA_POSE_CHECK_OPENING_EYE_ENDED:
            GadoraCheckOpeningEyeAnimEnded();
            break;

        case GADORA_POSE_EYE_OPENED:
            GadoraEyeOpened();
            break;

        case GADORA_POSE_CHECK_CLOSING_EYE_ENDED:
            GadoraCheckClosingEyeAnimNearEnded();
            break;

        case GADORA_POSE_DEATH:
            GadoraDeath();
            break;

        default:
            GadoraDeathGFXInit();
    }
}

/**
 * @brief 4a318 | 1d0 | Gadora eye AI
 * 
 */
void GadoraEye(void)
{
    u8 ramSlot;
    u32 rng;
    u32 yOffset;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(0x25E);
    }

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gCurrentSprite.health != 0x0)
        gSpriteData[ramSlot].paletteRow = gCurrentSprite.paletteRow;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;

            if (gSpriteData[ramSlot].spriteID == PSPRITE_GADORA_KRAID)
                gCurrentSprite.health = 0x1;
            else
            {
                gCurrentSprite.absolutePaletteRow = 0x1;
                gCurrentSprite.paletteRow = 0x1;
                gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0x0];
            }

            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = -0x28;
            gCurrentSprite.hitboxBottomOffset = 0x28;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.pOam = large_energy_drop_oam; // No graphics
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = 0x9;
            break;

        case 0x62: // Killed
            gSpriteData[ramSlot].pose = 0x62;
            gSpriteData[ramSlot].ignoreSamusCollisionTimer = 0x1;
            gSpriteData[ramSlot].health = 0x0;
            gCurrentSprite.pose = GADORA_EYE_POSE_DEATH;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
            gCurrentSprite.timer = 0x28; // Death timer
            break;

        case GADORA_EYE_POSE_DEATH:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                rng = gSpriteRNG;
                yOffset = rng - 0x44;
                rng += 0x10;
                
                SpriteUtilSpriteDeath(DEATH_NORMAL, yOffset + gCurrentSprite.yPosition,
                    rng + gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            }
            break;

        default:
            if (gSpriteData[ramSlot].pose == GADORA_POSE_EYE_OPENED)
            {
                // Make vulnerable
                gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN3;
                if ((gCurrentSprite.invicibilityStunFlashTimer & 0x7F) == 0x10)
                    gSpriteData[ramSlot].timer = 0x0; // Force close eye if hit
            }
            else
                gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3; // Make un-vulnerable
    }
}

/**
 * @brief 4a4e8 | fc | Gadora beam AI
 * 
 */
void GadoraBeam(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x30;
            gCurrentSprite.hitboxBottomOffset = 0x30;

            gCurrentSprite.pOam = sGadoraBeamOAM_Moving;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = GADORA_BEAM_POSE_MOVING;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
            gCurrentSprite.health = 0x1;
            gCurrentSprite.timer = 0x10; // Delay before it starts actually moving
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x18;

        case GADORA_BEAM_POSE_MOVING:
            if (gCurrentSprite.timer != 0x0)
            {
                gCurrentSprite.timer--;
                if (gCurrentSprite.timer == 0x0)
                    SoundPlay(0x25C);
            }
            else
            {
                gCurrentSprite.xPosition += 0xC;
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
                if (gPreviousCollisionCheck != COLLISION_AIR)
                {
                    ParticleSet(gCurrentSprite.yPosition + 0x1C, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_BIG);
                    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                        SoundPlay(0x25D);
                    gCurrentSprite.status = 0x0;
                }
            }
    }
}