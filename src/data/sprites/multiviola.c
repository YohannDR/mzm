#include "data/sprites/multiviola.h"
#include "macros.h"

const u32 sMultiviolaGfx[221] = INCBIN_U32("data/sprites/Multiviola.gfx.lz");
const u16 sMultiviolaPal[16] = INCBIN_U16("data/sprites/Multiviola.pal");

const u16 sMultiviolaOAM_Moving_Frame0[OAM_DATA_SIZE(7)] = {
    0x7,
    0xee, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x212,
    0xff, 0x8, OBJ_SPRITE_OAM | 0x210,
    0x3, 0x4, OBJ_SPRITE_OAM | 0x230,
    0x5, 0x1fc, OBJ_SPRITE_OAM | 0x211,
    0x3, 0x1f4, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sMultiviolaOAM_Moving_Frame1[OAM_DATA_SIZE(7)] = {
    0x7,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    0xfa, 0x7, OBJ_SPRITE_OAM | 0x230,
    0xfe, 0x7, OBJ_SPRITE_OAM | 0x211,
    0x3, 0x2, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x2, OBJ_SPRITE_OAM | 0x210
};

const u16 sMultiviolaOAM_Moving_Frame2[OAM_DATA_SIZE(7)] = {
    0x7,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xf6, 0x1fc, OBJ_SPRITE_OAM | 0x210,
    0xf7, 0x2, OBJ_SPRITE_OAM | 0x230,
    0xfb, 0x7, OBJ_SPRITE_OAM | 0x211,
    0x2, 0x4, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame3[OAM_DATA_SIZE(6)] = {
    0x6,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    0xfa, 0x1f3, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf7, 0x1f7, OBJ_SPRITE_OAM | 0x230,
    0xf5, 0x1fe, OBJ_SPRITE_OAM | 0x211,
    0xf7, 0x5, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame4[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf2, 0x1f8, OBJ_SPRITE_OAM | 0x232,
    0xfd, 0x1ef, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf9, 0x1f3, OBJ_SPRITE_OAM | 0x230,
    0xf8, 0x1f7, OBJ_SPRITE_OAM | 0x211
};

const u16 sMultiviolaOAM_Moving_Frame5[OAM_DATA_SIZE(6)] = {
    0x6,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xff, 0x1f3, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xfc, 0x1f0, OBJ_SPRITE_OAM | 0x230,
    0xf9, 0x1f3, OBJ_SPRITE_OAM | 0x211
};

const u16 sMultiviolaOAM_Moving_Frame6[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf5, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214,
    0x0, 0x1fd, OBJ_SPRITE_OAM | 0x210,
    0x0, 0x1f7, OBJ_SPRITE_OAM | 0x230,
    0xfe, 0x1f2, OBJ_SPRITE_OAM | 0x211,
    0xfa, 0x1ef, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sMultiviolaOAM_Moving_Frame7[OAM_DATA_SIZE(6)] = {
    0x6,
    0xed, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214,
    0xfd, 0x6, OBJ_SPRITE_OAM | 0x210,
    0x0, 0x1, OBJ_SPRITE_OAM | 0x230,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x211,
    0xfe, 0x1f2, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

const u16 sMultiviolaOAM_Moving_Frame8[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1f8, OBJ_SPRITE_OAM | 0x232,
    0xfe, 0x7, OBJ_SPRITE_OAM | 0x230,
    0xfb, 0x9, OBJ_SPRITE_OAM | 0x210,
    0x0, 0x2, OBJ_SPRITE_OAM | 0x211,
    0x1, 0x1f9, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sMultiviolaOAM_Moving_Frame9[OAM_DATA_SIZE(7)] = {
    0x7,
    0xee, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xfc, 0x9, OBJ_SPRITE_OAM | 0x230,
    0x0, 0x5, OBJ_SPRITE_OAM | 0x211,
    0x2, 0x1fd, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf9, 0x5, OBJ_SPRITE_OAM | 0x210
};

const u16 sMultiviolaOAM_Moving_Frame10[OAM_DATA_SIZE(7)] = {
    0x7,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x2, OBJ_SPRITE_OAM | 0x210,
    0xfa, 0x7, OBJ_SPRITE_OAM | 0x230,
    0xff, 0x7, OBJ_SPRITE_OAM | 0x211,
    0x3, 0x2, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame11[OAM_DATA_SIZE(7)] = {
    0x7,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xf6, 0x1fc, OBJ_SPRITE_OAM | 0x210,
    0xf7, 0x2, OBJ_SPRITE_OAM | 0x230,
    0xfb, 0x7, OBJ_SPRITE_OAM | 0x211,
    0x1, 0x4, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame12[OAM_DATA_SIZE(6)] = {
    0x6,
    0xed, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xfd, 0x1f1, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf8, 0x1f4, OBJ_SPRITE_OAM | 0x230,
    0xf6, 0x1f9, OBJ_SPRITE_OAM | 0x211
};

const u16 sMultiviolaOAM_Moving_Frame13[OAM_DATA_SIZE(6)] = {
    0x6,
    0xea, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214,
    0x3, 0x1f5, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xfe, 0x1f1, OBJ_SPRITE_OAM | 0x230,
    0xf8, 0x1f4, OBJ_SPRITE_OAM | 0x211
};

const u16 sMultiviolaOAM_Moving_Frame14[OAM_DATA_SIZE(7)] = {
    0x7,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0x3, 0x1f5, OBJ_SPRITE_OAM | 0x230,
    0x3, 0x1fc, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0x0, 0x1f1, OBJ_SPRITE_OAM | 0x211,
    0xfb, 0x1f2, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame15[OAM_DATA_SIZE(6)] = {
    0x6,
    0x1, 0x4, OBJ_SPRITE_OAM | 0x210,
    0x3, 0x1ff, OBJ_SPRITE_OAM | 0x230,
    0x3, 0x1f9, OBJ_SPRITE_OAM | 0x211,
    0x0, 0x1f2, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    0xe5, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216
};

const u16 sMultiviolaOAM_Moving_Frame16[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f8, OBJ_SPRITE_OAM | 0x232,
    0xfc, 0x8, OBJ_SPRITE_OAM | 0x210,
    0x0, 0x6, OBJ_SPRITE_OAM | 0x230,
    0x3, 0x0, OBJ_SPRITE_OAM | 0x211,
    0x3, 0x1f6, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sMultiviolaOAM_Moving_Frame17[OAM_DATA_SIZE(8)] = {
    0x8,
    0xec, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0x1, 0x1, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0x2, 0x5, OBJ_SPRITE_OAM | 0x231,
    0xfe, 0x8, OBJ_SPRITE_OAM | 0x211,
    0xf9, 0x7, OBJ_SPRITE_OAM | 0x230,
    0xf6, 0x2, OBJ_SPRITE_OAM | 0x210
};

const u16 sMultiviolaOAM_Moving_Frame18[OAM_DATA_SIZE(7)] = {
    0x7,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xf4, 0x1fd, OBJ_SPRITE_OAM | 0x210,
    0xf5, 0x4, OBJ_SPRITE_OAM | 0x230,
    0xfa, 0x8, OBJ_SPRITE_OAM | 0x211,
    0x0, 0x6, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame19[OAM_DATA_SIZE(6)] = {
    0x6,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xf9, 0x1f3, OBJ_SPRITE_OAM | 0x210,
    0xf5, 0x1f7, OBJ_SPRITE_OAM | 0x230,
    0xf3, 0x1fe, OBJ_SPRITE_OAM | 0x211,
    0xf5, 0x6, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame20[OAM_DATA_SIZE(7)] = {
    0x7,
    0xea, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xfe, 0x1f0, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf8, 0x1f1, OBJ_SPRITE_OAM | 0x230,
    0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x211,
    0xf2, 0x2, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame21[OAM_DATA_SIZE(6)] = {
    0x6,
    0xe7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214,
    0x3, 0x1f4, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xfe, 0x1f0, OBJ_SPRITE_OAM | 0x230,
    0xf9, 0x1f3, OBJ_SPRITE_OAM | 0x211
};

const u16 sMultiviolaOAM_Moving_Frame22[OAM_DATA_SIZE(7)] = {
    0x7,
    0xe5, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    0x4, 0x1f7, OBJ_SPRITE_OAM | 0x230,
    0x5, 0x1fd, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0x0, 0x1f2, OBJ_SPRITE_OAM | 0x211,
    0xfb, 0x1f2, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame23[OAM_DATA_SIZE(6)] = {
    0x6,
    0xeb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214,
    0x2, 0x5, OBJ_SPRITE_OAM | 0x210,
    0x5, 0x0, OBJ_SPRITE_OAM | 0x230,
    0x5, 0x1f9, OBJ_SPRITE_OAM | 0x211,
    0x1, 0x1f3, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const struct FrameData sMultiviolaOAM_Moving[57] = {
    [0] = {
        .pFrame = sMultiviolaOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sMultiviolaOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sMultiviolaOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sMultiviolaOAM_Moving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sMultiviolaOAM_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sMultiviolaOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sMultiviolaOAM_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sMultiviolaOAM_Moving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = {
        .pFrame = sMultiviolaOAM_Moving_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [9] = {
        .pFrame = sMultiviolaOAM_Moving_Frame9,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = {
        .pFrame = sMultiviolaOAM_Moving_Frame10,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [11] = {
        .pFrame = sMultiviolaOAM_Moving_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [12] = {
        .pFrame = sMultiviolaOAM_Moving_Frame12,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [13] = {
        .pFrame = sMultiviolaOAM_Moving_Frame13,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [14] = {
        .pFrame = sMultiviolaOAM_Moving_Frame14,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [15] = {
        .pFrame = sMultiviolaOAM_Moving_Frame15,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [16] = {
        .pFrame = sMultiviolaOAM_Moving_Frame16,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [17] = {
        .pFrame = sMultiviolaOAM_Moving_Frame17,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [18] = {
        .pFrame = sMultiviolaOAM_Moving_Frame18,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [19] = {
        .pFrame = sMultiviolaOAM_Moving_Frame19,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [20] = {
        .pFrame = sMultiviolaOAM_Moving_Frame20,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [21] = {
        .pFrame = sMultiviolaOAM_Moving_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [22] = {
        .pFrame = sMultiviolaOAM_Moving_Frame22,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [23] = {
        .pFrame = sMultiviolaOAM_Moving_Frame23,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [24] = {
        .pFrame = sMultiviolaOAM_Moving_Frame16,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [25] = {
        .pFrame = sMultiviolaOAM_Moving_Frame17,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [26] = {
        .pFrame = sMultiviolaOAM_Moving_Frame18,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [27] = {
        .pFrame = sMultiviolaOAM_Moving_Frame19,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [28] = {
        .pFrame = sMultiviolaOAM_Moving_Frame20,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [29] = {
        .pFrame = sMultiviolaOAM_Moving_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [30] = {
        .pFrame = sMultiviolaOAM_Moving_Frame22,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [31] = {
        .pFrame = sMultiviolaOAM_Moving_Frame23,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [32] = {
        .pFrame = sMultiviolaOAM_Moving_Frame16,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [33] = {
        .pFrame = sMultiviolaOAM_Moving_Frame17,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [34] = {
        .pFrame = sMultiviolaOAM_Moving_Frame18,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [35] = {
        .pFrame = sMultiviolaOAM_Moving_Frame19,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [36] = {
        .pFrame = sMultiviolaOAM_Moving_Frame20,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [37] = {
        .pFrame = sMultiviolaOAM_Moving_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [38] = {
        .pFrame = sMultiviolaOAM_Moving_Frame22,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [39] = {
        .pFrame = sMultiviolaOAM_Moving_Frame23,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [40] = {
        .pFrame = sMultiviolaOAM_Moving_Frame16,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [41] = {
        .pFrame = sMultiviolaOAM_Moving_Frame17,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [42] = {
        .pFrame = sMultiviolaOAM_Moving_Frame18,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [43] = {
        .pFrame = sMultiviolaOAM_Moving_Frame19,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [44] = {
        .pFrame = sMultiviolaOAM_Moving_Frame12,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [45] = {
        .pFrame = sMultiviolaOAM_Moving_Frame13,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [46] = {
        .pFrame = sMultiviolaOAM_Moving_Frame14,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [47] = {
        .pFrame = sMultiviolaOAM_Moving_Frame15,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [48] = {
        .pFrame = sMultiviolaOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [49] = {
        .pFrame = sMultiviolaOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [50] = {
        .pFrame = sMultiviolaOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [51] = {
        .pFrame = sMultiviolaOAM_Moving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [52] = {
        .pFrame = sMultiviolaOAM_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [53] = {
        .pFrame = sMultiviolaOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [54] = {
        .pFrame = sMultiviolaOAM_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [55] = {
        .pFrame = sMultiviolaOAM_Moving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [56] = FRAME_DATA_TERMINATOR
};
