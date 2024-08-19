#include "data/sprites/dragon.h"

#include "macros.h"

const s16 sDragonFireballYMovement[40] = {
    -12, -12, -12, -12, -10, -10, -10, -10, -8, -8, -8, -8,
    -6, -6, -6, -6, -5, -5, -4, -4, -3, -2, -1, 0, 1, 2, 3,
    4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16, 18, SHORT_MAX
};

const s16 sDragonFireballOamRotation[40] = {
    0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 6, 8, 10, 12, 14, 16, 16,
    20, 24, 28, 29, 30, 31, 32, 33, 34, 35, 36, 40, 44, 48,
    52, 56, 60, 64, 64, 64, 64, 64, SHORT_MAX
};

const u32 sDragonGfx[512] = INCBIN_U32("data/sprites/Dragon.gfx.lz");
const u16 sDragonPal[16 * 2] = INCBIN_U16("data/sprites/Dragon.pal");

static const u16 sDragonOam_Spitting_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xe6, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0x3, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20d
};

static const u16 sDragonOam_Spitting_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xe5, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0x3, OBJ_SIZE_16x32 | 0x1f7, OBJ_SPRITE_OAM | 0x20d
};

static const u16 sDragonOam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0x6, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x24b,
    0xe9, OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

static const u16 sDragonOam_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xea, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x207,
    0x4, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x24b
};

static const u16 sDragonOam_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xe9, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xe9, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xf9, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x245,
    0x5, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x24b
};

static const u16 sDragonOam_TurningAround_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xe9, OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20f,
    0x5, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x215
};

static const u16 sDragonOam_TurningAround_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_SIZE_16x32 | 0x1fa, OBJ_SPRITE_OAM | 0x213,
    0x5, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x255
};

static const u16 sDragonOam_Unused_0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x213,
    0x5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fc, OBJ_SPRITE_OAM | 0x255
};

static const u16 sDragonOam_Unused_1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xe9, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1ec, OBJ_SPRITE_OAM | 0x20f,
    0x5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x215
};

static const u16 sDragonFireballOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25a
};

static const u16 sDragonFireballOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25c
};

static const u16 sDragonFireballOam_Moving_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25e
};

static const u16 sDragonFireballOam_Exploding_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a
};

static const u16 sDragonFireballOam_Exploding_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sDragonFireballOam_Exploding_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21e
};

static const u16 sDragonFireballOam_Exploding_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x121e
};

const struct FrameData sDragonOam_Idle[4] = {
    [0] = {
        .pFrame = sDragonOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(.2f)
    },
    [1] = {
        .pFrame = sDragonOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(.2f)
    },
    [2] = {
        .pFrame = sDragonOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(.2f)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDragonOam_Warning[3] = {
    [0] = {
        .pFrame = sDragonOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sDragonOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDragonOam_Spitting[3] = {
    [0] = {
        .pFrame = sDragonOam_Spitting_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sDragonOam_Spitting_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDragonOam_TurningAround[3] = {
    [0] = {
        .pFrame = sDragonOam_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sDragonOam_TurningAround_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDragonOam_TurningAroundPart2[3] = {
    [0] = {
        .pFrame = sDragonOam_TurningAround_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sDragonOam_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDragonFireballOam_Moving[4] = {
    [0] = {
        .pFrame = sDragonFireballOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sDragonFireballOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sDragonFireballOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDragonFireballOam_Exploding[5] = {
    [0] = {
        .pFrame = sDragonFireballOam_Exploding_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sDragonFireballOam_Exploding_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sDragonFireballOam_Exploding_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sDragonFireballOam_Exploding_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};
