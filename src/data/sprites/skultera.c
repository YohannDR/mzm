#include "data/sprites/skultera.h"
#include "macros.h"

const u32 sSkulteraGfx[285] = INCBIN_U32("data/sprites/Skultera.gfx.lz");
const u16 sSkulteraPal[16] = INCBIN_U16("data/sprites/Skultera.pal");

const u16 sSkulteraOam_Idle_Frame0[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_SIZE_32x16 | 0x1ef, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x8 | 0x1ef, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x233,
    0xf1, 0x1, OBJ_SPRITE_OAM | 0x200,
    0xf4, OBJ_Y_FLIP | 0x5, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xef, 0xb, OBJ_SPRITE_OAM | 0x206
};

const u16 sSkulteraOam_Idle_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_SIZE_32x16 | 0x1e6, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1e7, OBJ_SPRITE_OAM | 0x236,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x216,
    0xf2, 0x1ff, OBJ_SPRITE_OAM | 0x201,
    0xf5, 0x6, OBJ_SPRITE_OAM | 0x202,
    0xf3, 0xa, OBJ_SPRITE_OAM | 0x225
};

const u16 sSkulteraOam_Idle_Frame2[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_SIZE_32x16 | 0x1e6, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1e6, OBJ_SPRITE_OAM | 0x216,
    0xf5, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x201,
    0xf3, 0x7, OBJ_SPRITE_OAM | 0x200,
    0xf3, 0xb, OBJ_SPRITE_OAM | 0x205
};

const u16 sSkulteraOam_Idle_Frame3[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x213,
    0xf5, 0x1, OBJ_SPRITE_OAM | 0x202,
    0xf3, 0x5, OBJ_SPRITE_OAM | 0x201,
    0xf2, OBJ_Y_FLIP | 0xa, OBJ_SPRITE_OAM | 0x225
};

const u16 sSkulteraOam_TurningAround_Frame0[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_SIZE_32x16 | 0x1e6, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1e7, OBJ_SPRITE_OAM | 0x236,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x216,
    0xf1, 0x0, OBJ_SPRITE_OAM | 0x201,
    0xf3, 0x6, OBJ_SPRITE_OAM | 0x202,
    0xf4, OBJ_Y_FLIP | 0xb, OBJ_SPRITE_OAM | 0x225
};

const u16 sSkulteraOam_TurningAround_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    0xe1, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x20e,
    0xf1, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x21a,
    0xf9, 0x2, OBJ_SPRITE_OAM | 0x232,
    0xf2, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    0xf4, 0x1, OBJ_SPRITE_OAM | 0x202,
    0xf2, 0x6, OBJ_SPRITE_OAM | 0x204
};

const u16 sSkulteraOam_TurningAround_Frame2[OAM_DATA_SIZE(5)] = {
    0x5,
    0xe1, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x210,
    0xf1, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x0, OBJ_SPRITE_OAM | 0x21e,
    0xf1, 0x1fe, OBJ_SPRITE_OAM | 0x200,
    0xf2, 0x3, OBJ_SPRITE_OAM | 0x205
};

const u16 sSkulteraOam_TurningAround_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xe1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20e,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21a,
    0xf1, OBJ_X_FLIP | 0x1ed, OBJ_SPRITE_OAM | 0x200,
    0xf3, 0x1fd, OBJ_SPRITE_OAM | 0x203
};

const u16 sSkulteraOam_TurningAround_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x216,
    0xf1, OBJ_X_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x201
};

const u16 sSkulteraOam_TurningAround_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1eb, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1eb, OBJ_SPRITE_OAM | 0x213,
    0xf4, OBJ_X_FLIP | 0x1f1, OBJ_SPRITE_OAM | 0x202,
    0xf1, OBJ_X_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x200
};

const u16 sSkulteraOam_TurningAround_Frame6[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x1ee, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x1ed, OBJ_SPRITE_OAM | 0x233,
    0xf1, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x200,
    0xf4, OBJ_X_FLIP | 0x1ef, OBJ_SPRITE_OAM | 0x202,
    0xf2, OBJ_X_FLIP | 0x1ed, OBJ_SPRITE_OAM | 0x204
};

const u16 sSkulteraOam_TurningAround_Frame7[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1fa, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x1f9, OBJ_SPRITE_OAM | 0x236,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x1fa, OBJ_SPRITE_OAM | 0x216,
    0xf4, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xf1, OBJ_X_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x200,
    0xf2, OBJ_X_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x205
};


const struct FrameData sSkulteraOam_Idle[5] = {
    [0] = {
        .pFrame = sSkulteraOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sSkulteraOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sSkulteraOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sSkulteraOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkulteraOam_TurningAround[9] = {
    [0] = {
        .pFrame = sSkulteraOam_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(13.f / 60)
    },
    [1] = {
        .pFrame = sSkulteraOam_TurningAround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sSkulteraOam_TurningAround_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sSkulteraOam_TurningAround_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sSkulteraOam_TurningAround_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sSkulteraOam_TurningAround_Frame5,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sSkulteraOam_TurningAround_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [7] = {
        .pFrame = sSkulteraOam_TurningAround_Frame7,
        .timer = CONVERT_SECONDS(13.f / 60)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkulteraOam_ChasingSamus[5] = {
    [0] = {
        .pFrame = sSkulteraOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sSkulteraOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sSkulteraOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sSkulteraOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};
