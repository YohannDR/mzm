#include "data/sprites/reo.h"
#include "macros.h"

const s16 sReoIdleYMovement[65] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1,
    2, 2, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0, -1, 0, -1, 0, -1, 0,
    -1, -1, -1, -2, -2, -1, -1, -1, 0, -1, 0, -1,
    0, -1, 0, -1, 0, 0, 0, 0, SHORT_MAX
};

const s16 sReoIdleXMovement[81] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1,
    1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 1,
    0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1,
    0, -1, 0, -1, 0, -1, 0, -1, -1, -1, -1, -1,
    -1, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1,
    0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0, SHORT_MAX
};

const u32 sReoGreenWingsGfx[277] = INCBIN_U32("data/sprites/ReoGreenWings.gfx.lz");
const u16 sReoGreenWingsPal[16] = INCBIN_U16("data/sprites/ReoGreenWings.pal");
const u32 sReoPurpleWingsGfx[277] = INCBIN_U32("data/sprites/ReoPurpleWings.gfx.lz");
const u16 sReoPurpleWingsPal[16] = INCBIN_U16("data/sprites/ReoPurpleWings.pal");

const u16 sReoOAM_Idle_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_Idle_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    0xee, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x204,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ea, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_Moving_Unused_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_Moving_Unused_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    0xee, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x204,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_Moving_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1eb, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x5, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_UnusedFrame[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1eb, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x5, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_Idle_Unused_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sReoOAM_Idle_Unused_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xef, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x204,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_Idle_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ea, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_Idle_Unused_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sReoOAM_Idle_Unused_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xef, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x204,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sReoOAM_Idle_Unused_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ea, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sReoOAM_Moving_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0xfe, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x210,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x210
};

const u16 sReoOAM_Moving_Frame1[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xee, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x204,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x204,
    0xfd, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x210,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x210
};

const u16 sReoOAM_Moving_Frame2[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e9, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x226,
    0xfd, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x210,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x210
};

const u16 sReoOAM_Moving_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x214
};

const u16 sReoOAM_Moving_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf0, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x204,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x214
};

const u16 sReoOAM_Moving_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ea, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x214
};

const struct FrameData sReoOAM_Unused1[5] = {
    [0] = {
        .pFrame = sReoOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sReoOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sReoOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sReoOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sReoOAM_Idle[5] = {
    [0] = {
        .pFrame = sReoOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sReoOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sReoOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sReoOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sReoOAM_Idle_Unused[9] = {
    [0] = {
        .pFrame = sReoOAM_Idle_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sReoOAM_Idle_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sReoOAM_Idle_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sReoOAM_Idle_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sReoOAM_Idle_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sReoOAM_Idle_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sReoOAM_Idle_Unused_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sReoOAM_Idle_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sReoOAM_Moving[13] = {
    [0] = {
        .pFrame = sReoOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sReoOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sReoOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sReoOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sReoOAM_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sReoOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sReoOAM_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sReoOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sReoOAM_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sReoOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sReoOAM_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [11] = {
        .pFrame = sReoOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sReoOAM_Unused2[21] = {
    [0] = {
        .pFrame = sReoOAM_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sReoOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sReoOAM_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sReoOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sReoOAM_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sReoOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sReoOAM_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sReoOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sReoOAM_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sReoOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sReoOAM_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [11] = {
        .pFrame = sReoOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = {
        .pFrame = sReoOAM_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sReoOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [14] = {
        .pFrame = sReoOAM_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [15] = {
        .pFrame = sReoOAM_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [16] = {
        .pFrame = sReoOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [17] = {
        .pFrame = sReoOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [18] = {
        .pFrame = sReoOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [19] = {
        .pFrame = sReoOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [20] = FRAME_DATA_TERMINATOR
};

const struct FrameData sReoOAM_Unused3[9] = {
    [0] = {
        .pFrame = sReoOAM_Idle_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sReoOAM_Idle_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sReoOAM_Idle_Unused_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sReoOAM_Idle_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sReoOAM_Idle_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sReoOAM_Idle_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sReoOAM_Idle_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sReoOAM_Idle_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sReoOAM_Moving_Unused[5] = {
    [0] = {
        .pFrame = sReoOAM_Moving_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sReoOAM_Moving_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sReoOAM_Moving_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sReoOAM_Moving_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};
