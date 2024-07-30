#include "data/sprites/charge_beam.h"

#include "macros.h"

const s16 sChargeBeamIdleYMovement[66] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, -1, -1, -1,
    -1, -1, -1, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0,
    0, SHORT_MAX
};

const u32 sChargeBeamGfx[243] = INCBIN_U32("data/sprites/ChargeBeam.gfx.lz");
const u16 sChargeBeamPal[16] = INCBIN_U16("data/sprites/ChargeBeam.pal");

static const u16 sChargeBeamOam_Visible_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x212
};

static const u16 sChargeBeamOam_Visible_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x214
};

static const u16 sChargeBeamOam_Visible_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, 0x1ff, OBJ_SPRITE_OAM | 0x216,
    0xf8, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x212
};

static const u16 sChargeBeamGlowOam_Idle_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x202,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x202
};

static const u16 sChargeBeamGlowOam_Idle_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x206
};

static const u16 sChargeBeamGlowOam_Idle_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sChargeBeamGlowOam_Idle_Frame6[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20e,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20e
};

static const u16 sChargeBeamGlowOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x9b
};

static const u16 sChargeBeamOam_Spawning_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x217,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x217,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x217,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x217
};

static const u16 sChargeBeamOam_Spawning_Frame1[OAM_DATA_SIZE(9)] = {
    0x9,
    0xef, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x217,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x217,
    0x1, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x217,
    0x1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1fb, OBJ_SPRITE_OAM | 0x218,
    0xfb, 0x1fb, OBJ_SPRITE_OAM | 0x238,
    OBJ_SHAPE_VERTICAL | 0x1, 0x1fb, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1ef, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1, OBJ_SPRITE_OAM | 0x237
};

static const u16 sChargeBeamOam_Spawning_Frame2[OAM_DATA_SIZE(9)] = {
    0x9,
    0xee, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x217,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x217,
    0x2, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x217,
    0x2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xed, 0x1fa, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0x3, OBJ_Y_FLIP | 0x1fa, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfa, 0x1ed, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_X_FLIP | 0x3, OBJ_SPRITE_OAM | 0x237,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x238
};

static const u16 sChargeBeamOam_Spawning_Frame3[OAM_DATA_SIZE(13)] = {
    0xd,
    0xed, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x217,
    0xed, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x217,
    0x3, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x217,
    0x3, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ec, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x237,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x238,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x218
};

static const u16 sChargeBeamOam_Spawning_Frame4[OAM_DATA_SIZE(14)] = {
    0xe,
    0xec, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x217,
    0xec, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x217,
    0x4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x217,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xeb, 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1eb, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x5, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0xeb, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1eb, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x5, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

static const u16 sChargeBeamOam_Spawning_Frame8[OAM_DATA_SIZE(16)] = {
    0x10,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x217,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x217,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x217,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_HORIZONTAL | 0xec, 0x1ec, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1ec, OBJ_SPRITE_OAM | 0x210,
    0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x210,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x10, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_Y_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_Y_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x210,
    0xfc, 0x1e8, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0xc, OBJ_SPRITE_OAM | 0x210,
    0x10, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x23b
};

static const u16 sChargeBeamOam_Spawning_Frame9[OAM_DATA_SIZE(16)] = {
    0x10,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x21e,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, OBJ_SPRITE_OAM | 0x21e,
    0xfc, 0x1e4, OBJ_SPRITE_OAM | 0x21d,
    0xe4, 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x14, OBJ_SPRITE_OAM | 0x21d,
    0x14, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1eb, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xeb, 0x1e8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | 0x5, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xeb, OBJ_X_FLIP | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_X_FLIP | OBJ_Y_FLIP | 0x5, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_X_FLIP | OBJ_Y_FLIP | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_Y_FLIP | 0x1eb, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_Y_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x210
};

static const u16 sChargeBeamOam_Spawning_Frame10[OAM_DATA_SIZE(17)] = {
    0x11,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1e1, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x17, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xe1, 0x1f8, OBJ_SPRITE_OAM | 0x23b,
    OBJ_SHAPE_HORIZONTAL | 0x17, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x23b,
    OBJ_SHAPE_HORIZONTAL | 0xe5, 0x1e8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1e5, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | 0x13, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x13, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_Y_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_Y_FLIP | 0x1e5, OBJ_SPRITE_OAM | 0x210,
    0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    0x18, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    0xfc, 0x1e0, OBJ_SPRITE_OAM | 0x21d,
    0xfc, OBJ_X_FLIP | 0x18, OBJ_SPRITE_OAM | 0x21d
};

static const u16 sChargeBeamOam_Spawning_Frame11[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x236
};

const struct FrameData sChargeBeamOam_Visible[5] = {
    [0] = {
        .pFrame = sChargeBeamOam_Visible_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sChargeBeamOam_Visible_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sChargeBeamOam_Visible_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sChargeBeamOam_Visible_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargeBeamOam_Spawning[13] = {
    [0] = {
        .pFrame = sChargeBeamOam_Spawning_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sChargeBeamOam_Spawning_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sChargeBeamOam_Spawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sChargeBeamOam_Spawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [4] = {
        .pFrame = sChargeBeamOam_Spawning_Frame4,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [5] = {
        .pFrame = sChargeBeamOam_Spawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [6] = {
        .pFrame = sChargeBeamOam_Spawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [7] = {
        .pFrame = sChargeBeamOam_Spawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [8] = {
        .pFrame = sChargeBeamOam_Spawning_Frame8,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [9] = {
        .pFrame = sChargeBeamOam_Spawning_Frame9,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [10] = {
        .pFrame = sChargeBeamOam_Spawning_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sChargeBeamOam_Spawning_Frame11,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargeBeamGlowOam_Idle[15] = {
    [0] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [2] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [4] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [6] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [8] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [10] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [12] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [14] = FRAME_DATA_TERMINATOR
};
