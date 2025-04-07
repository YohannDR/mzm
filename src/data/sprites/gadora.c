#include "data/sprites/gadora.h"
#include "macros.h"

const u32 sGadoraGfx[585] = INCBIN_U32("data/sprites/Gadora.gfx.lz");
const u16 sGadoraPal[32] = INCBIN_U16("data/sprites/Gadora.pal");

const u16 sGadoraOAM_EyeClosed_Frame2[OAM_DATA_SIZE(7)] = {
    0x7,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x24f,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x24f
};

const u16 sGadoraOAM_EyeClosed_Frame0[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x24f,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x24f
};

const u16 sGadoraOAM_EyeClosed_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x24f,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x24f
};

const u16 sGadoraOAM_Warning_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x202,
    0xd8, 0x1ff, OBJ_SPRITE_OAM | 0x24f,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x24f
};

const u16 sGadoraOAM_Warning_Frame2[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x205,
    0xd8, 0x1ff, OBJ_SPRITE_OAM | 0x24f,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_OpeningEye_Frame5[OAM_DATA_SIZE(7)] = {
    0x7,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x257,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x205,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_EyeOpened_Frame0[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x208,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_EyeOpened_Frame1[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20b,
    0x0, OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x266,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x208,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_EyeOpened_Frame2[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_EyeOpened_Frame3[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_EyeOpened_Frame4[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20b,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_EyeOpened_Frame5[OAM_DATA_SIZE(8)] = {
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

const u16 sGadoraOAM_Frame_Unused[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x6, OBJ_SPRITE_OAM | 0x20b,
    0xd8, 0x1fe, OBJ_SPRITE_OAM | 0x250,
    0x20, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x250
};

const u16 sGadoraOAM_EyeMoving_Frame4[OAM_DATA_SIZE(8)] = {
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

const u16 sGadoraOAM_EyeMoving_Frame3[OAM_DATA_SIZE(8)] = {
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

const u16 sGadoraOAM_EyeMoving_Frame0[OAM_DATA_SIZE(8)] = {
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

const u16 sGadoraOAM_EyeMoving_Frame1[OAM_DATA_SIZE(8)] = {
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

const u16 sGadoraOAM_Death_Frame1[OAM_DATA_SIZE(8)] = {
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

const u16 sGadoraOAM_Death_Frame2[OAM_DATA_SIZE(8)] = {
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

const u16 sGadoraBeamOAM_Moving_Frame0[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0xf0, 0x6, OBJ_SPRITE_OAM | 0x21b,
    0xf9, 0x4, OBJ_SPRITE_OAM | 0x23b,
    0x9, OBJ_Y_FLIP | 0x6, OBJ_SPRITE_OAM | 0x21b,
    0x0, OBJ_Y_FLIP | 0x4, OBJ_SPRITE_OAM | 0x23b
};

const u16 sGadoraBeamOAM_Moving_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21e
};

const u16 sGadoraBeamOAM_Moving_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf1, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x25c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x25c
};

const u16 sGadoraBeamOAM_Moving_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25e,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25e
};


const struct FrameData sGadoraOAM_EyeClosed[5] = {
    [0] = {
        .pFrame = sGadoraOAM_EyeClosed_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sGadoraOAM_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sGadoraOAM_EyeClosed_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sGadoraOAM_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOAM_Warning[7] = {
    [0] = {
        .pFrame = sGadoraOAM_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGadoraOAM_Warning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sGadoraOAM_Warning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sGadoraOAM_Warning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sGadoraOAM_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sGadoraOAM_EyeClosed_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOAM_OpeningEye[7] = {
    [0] = {
        .pFrame = sGadoraOAM_EyeClosed_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGadoraOAM_EyeClosed_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sGadoraOAM_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sGadoraOAM_Warning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sGadoraOAM_Warning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sGadoraOAM_OpeningEye_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraBeamOAM_Moving[5] = {
    [0] = {
        .pFrame = sGadoraBeamOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGadoraBeamOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sGadoraBeamOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sGadoraBeamOAM_Moving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOAM_EyeMoving[7] = {
    [0] = {
        .pFrame = sGadoraOAM_EyeMoving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sGadoraOAM_EyeMoving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sGadoraOAM_EyeMoving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sGadoraOAM_EyeMoving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sGadoraOAM_EyeMoving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sGadoraOAM_EyeMoving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOAM_ClosingEye[5] = {
    [0] = {
        .pFrame = sGadoraOAM_OpeningEye_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sGadoraOAM_Warning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sGadoraOAM_Warning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sGadoraOAM_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOAM_Death[5] = {
    [0] = {
        .pFrame = sGadoraOAM_EyeMoving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sGadoraOAM_Death_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sGadoraOAM_Death_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sGadoraOAM_Death_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOAM_EyeOpened[7] = {
    [0] = {
        .pFrame = sGadoraOAM_EyeOpened_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGadoraOAM_EyeOpened_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sGadoraOAM_EyeOpened_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sGadoraOAM_EyeOpened_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sGadoraOAM_EyeOpened_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sGadoraOAM_EyeOpened_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOAM_BeforeClosing[5] = {
    [0] = {
        .pFrame = sGadoraOAM_EyeOpened_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sGadoraOAM_EyeOpened_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sGadoraOAM_EyeOpened_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sGadoraOAM_EyeOpened_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};
