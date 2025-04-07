#include "data/sprites/squeept.h"
#include "macros.h"

const s16 sSqueeptRisingMovement[65] = {
    -18, -18, -18, -18, -16, -16, -16, -16, -14,
    -14, -14, -14, -12, -12, -12, -12, -12, -12,
    -12, -12, -11, -11, -11, -11, -10, -10, -10,
    -10, -9, -9, -9, -9, -8, -8, -8, -8, -8, -8,
    -8, -8, -7, -7, -7, -7, -6, -6, -6, -6, -5,
    -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -3,
    -2, -2, -2, -2, SHORT_MAX
};

const s16 sSqueeptFallingMovement[16] = {
    4, 4, 4, 6, 6, 8, 8, 10, 10, 12, 12, 14,
    14, 16, 16, SHORT_MAX
};

const u32 sSqueeptGfx[263] = INCBIN_U32("data/sprites/Squeept.gfx.lz");
const u16 sSqueeptPal[16] = INCBIN_U16("data/sprites/Squeept.pal");

const u16 sSqueeptOam_GoingUp_Frame0[OAM_DATA_SIZE(8)] = {
    0x8,
    0x3, 0x1f8, OBJ_SPRITE_OAM | 0x22d,
    0x3, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x22d,
    0xf3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1f1, OBJ_SPRITE_OAM | 0x206,
    0xff, 0x1f9, OBJ_SPRITE_OAM | 0x207,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x206,
    0xff, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x207
};

const u16 sSqueeptOam_GoingUp_Frame2[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf2, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x202,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0xff, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x206,
    0xff, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0x2, 0x1fc, OBJ_SPRITE_OAM | 0x20f
};

const u16 sSqueeptOam_GoingUp_Frame4[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf2, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0xff, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x206,
    0xff, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0x2, 0x1fc, OBJ_SPRITE_OAM | 0x20e
};

const u16 sSqueeptOam_GoingUp_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1f1, OBJ_SPRITE_OAM | 0x206,
    0xff, 0x1f9, OBJ_SPRITE_OAM | 0x207,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x206,
    0xff, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x207
};

const u16 sSqueeptOam_GoingUp_Frame3[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x202,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x206,
    0x0, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x207
};

const u16 sSqueeptOam_GoingUp_Frame5[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x206,
    0x0, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x207
};

const u16 sSqueeptOam_TurningAround_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    0x3, 0x1f0, OBJ_SPRITE_OAM | 0x20d,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x208,
    0x3, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x20d
};

const u16 sSqueeptOam_TurningAround_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf4, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20a
};

const u16 sSqueeptOam_TurningAround_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20a
};

const u16 sSqueeptOam_TurningAround_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf7, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    0xef, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x20d,
    0xf7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x208,
    0xef, OBJ_X_FLIP | OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x20d
};

const u16 sSqueeptOam_TurningAround_Frame4[OAM_DATA_SIZE(6)] = {
    0x6,
    0xfc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0xf7, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x206,
    0xf7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x207
};

const u16 sSqueeptOam_GoingDown_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfd, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xfd, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x20c
};

const u16 sSqueeptOam_GoingDown_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1f7, OBJ_SPRITE_OAM | 0x20c,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x20c
};

const struct FrameData sSqueeptOam_TurningAround[6] = {
    [0] = {
        .pFrame = sSqueeptOam_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [1] = {
        .pFrame = sSqueeptOam_TurningAround_Frame1,
        .timer = CONVERT_SECONDS(0.15f)
    },
    [2] = {
        .pFrame = sSqueeptOam_TurningAround_Frame2,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [3] = {
        .pFrame = sSqueeptOam_TurningAround_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sSqueeptOam_TurningAround_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSqueeptOam_TurningAround_Unused[6] = {
    [0] = {
        .pFrame = sSqueeptOam_TurningAround_Frame4,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [1] = {
        .pFrame = sSqueeptOam_TurningAround_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sSqueeptOam_TurningAround_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sSqueeptOam_TurningAround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSqueeptOam_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSqueeptOam_GoingDown[3] = {
    [0] = {
        .pFrame = sSqueeptOam_GoingDown_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sSqueeptOam_GoingDown_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSqueeptOam_GoingUp[8] = {
    [0] = {
        .pFrame = sSqueeptOam_GoingUp_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSqueeptOam_GoingUp_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSqueeptOam_GoingUp_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSqueeptOam_GoingUp_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSqueeptOam_GoingUp_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSqueeptOam_GoingUp_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sSqueeptOam_GoingUp_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = FRAME_DATA_TERMINATOR
};
