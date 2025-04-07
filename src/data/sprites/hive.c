#include "data/sprites/hive.h"
#include "macros.h"

const s16 sMellowIdleYVelocity[65] = {
    0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
    2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1,
    -2, -2, -2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2,
    -1, -1, -1, -1, 0, 0, 0, 0, SHORT_MAX
};

const s16 sMellowIdleXVelocity[81] = {
    0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7,
    7, 7, 6, 6, 6, 5, 5, 5, 4, 4, 4, 3, 3, 2, 2, 1, 1, 0, 0, 0, 0,
    -1, -1, -2, -2, -3, -3, -4, -4, -4, -5, -5, -5, -6, -6, -6, -7,
    -7, -7, -7, -7, -7, -6, -6, -6, -5, -5, -5, -4, -4, -4, -3, -3,
    -2, -2, -1, -1, 0, 0, SHORT_MAX
};

const u32 sHiveGfx[1799] = INCBIN_U32("data/sprites/Hive.gfx.lz");
const u16 sHivePal[96] = INCBIN_U16("data/sprites/Hive.pal");

const u16 sMellowOAM_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sMellowOAM_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220
};

const u16 sMellowOAM_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sMellowOAM_Idle_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

const u16 sHiveOAM_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x1210
};

const u16 sHiveOAM_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x1214
};

const u16 sHiveOAM_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sHiveOAM_Idle_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x121c
};

const u16 sHiveRootsOAM_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_VERTICAL | 0x11, 0x1ef, OBJ_SPRITE_OAM | 0x1245,
    0x17, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x1244,
    0x17, 0x1f5, OBJ_SPRITE_OAM | 0x1246
};

const u16 sHiveRootsOAM_Idle_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x11, 0x1ef, OBJ_SPRITE_OAM | 0x1246,
    0x17, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x1244,
    0x17, 0x1f5, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x1247
};

const u16 sHiveRootsOAM_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x1244,
    OBJ_SHAPE_VERTICAL | 0x11, 0x1ef, OBJ_SPRITE_OAM | 0x1247,
    0x17, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x1245,
    0x17, 0x1f3, OBJ_SPRITE_OAM | 0x1245
};

const u16 sHiveOAM_Phase2_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x2208
};

const u16 sHiveOAM_Phase2_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x220c
};

const u16 sHiveOAM_Phase2_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xdf, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x2308,
    0xff, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x2310
};

const u16 sHiveOAM_Phase2_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xdf, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x230c,
    0xff, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x2314
};

const u16 sHiveOAM_Phase3_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xff, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x3300,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x3318
};

const u16 sHiveOAM_Phase3_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xff, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x3304,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x331a
};

const u16 sHiveOAM_Phase3_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xff, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x3284,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x3318
};

const u16 sHiveOAM_Dying_Frame8[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xf, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4344,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4304,
    OBJ_SHAPE_HORIZONTAL | 0xfa, 0x1f8, OBJ_SPRITE_OAM | 0x4378,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f8, OBJ_SPRITE_OAM | 0x4358,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x4338,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1f8, OBJ_SPRITE_OAM | 0x4318,
    0xe0, 0x1fb, OBJ_SPRITE_OAM | 0x4242
};

const u16 sHiveOAM_Dying_Frame9[OAM_DATA_SIZE(10)] = {
    0xa,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x4378,
    OBJ_SHAPE_HORIZONTAL | 0xfa, 0x1f8, OBJ_SPRITE_OAM | 0x4358,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f8, OBJ_SPRITE_OAM | 0x4338,
    OBJ_SHAPE_HORIZONTAL | 0xed, 0x1f8, OBJ_SPRITE_OAM | 0x4318,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4344,
    OBJ_SHAPE_HORIZONTAL | 0x17, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4364,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4324,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4304,
    0xe5, 0x1fb, OBJ_SPRITE_OAM | 0x4242,
    0xe2, 0x1fb, OBJ_SPRITE_OAM | 0x4243
};

const u16 sHiveOAM_Dying_Frame10[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x42c0,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x4209,
    0xf0, 0x1fb, OBJ_SPRITE_OAM | 0x4242,
    0xe8, 0x1fb, OBJ_SPRITE_OAM | 0x4243,
    0xf8, 0x1fb, OBJ_SPRITE_OAM | 0x4241
};

const u16 sHiveOAM_Dying_Frame11[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4280,
    0xa, 0x1fb, OBJ_SPRITE_OAM | 0x4242,
    0x2, 0x1fb, OBJ_SPRITE_OAM | 0x4243,
    0xe7, 0x1fb, OBJ_SPRITE_OAM | 0x3243
};

const u16 sHiveOAM_Dying_Frame12[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x431c
};

const u16 sHiveOAM_Dying_Frame13[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x433c
};

const u16 sHiveOAM_Dying_Frame14[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x435c
};

const u16 sHiveOAM_Dying_Frame30[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x337c
};

const struct FrameData sMellowOAM_Idle[6] = {
    [0] = {
        .pFrame = sMellowOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sMellowOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sMellowOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMellowOAM_Idle_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sMellowOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMellowOAM_SamusDetected[6] = {
    [0] = {
        .pFrame = sMellowOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMellowOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sMellowOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sMellowOAM_Idle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMellowOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHiveOAM_Idle[19] = {
    [0] = {
        .pFrame = sHiveOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sHiveOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(11.f / 60)
    },
    [2] = {
        .pFrame = sHiveOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sHiveOAM_Idle_Frame3,
        .timer = CONVERT_SECONDS(11.f / 60)
    },
    [4] = {
        .pFrame = sHiveOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sHiveOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [6] = {
        .pFrame = sHiveOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [7] = {
        .pFrame = sHiveOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [8] = {
        .pFrame = sHiveOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [9] = {
        .pFrame = sHiveOAM_Idle_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [10] = {
        .pFrame = sHiveOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [11] = {
        .pFrame = sHiveOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [12] = {
        .pFrame = sHiveOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [13] = {
        .pFrame = sHiveOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [14] = {
        .pFrame = sHiveOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [15] = {
        .pFrame = sHiveOAM_Idle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [16] = {
        .pFrame = sHiveOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [17] = {
        .pFrame = sHiveOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [18] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHiveRootsOAM_Idle[4] = {
    [0] = {
        .pFrame = sHiveRootsOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sHiveRootsOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sHiveRootsOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHiveOAM_Phase2[12] = {
    [0] = {
        .pFrame = sHiveOAM_Phase2_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sHiveOAM_Phase2_Frame1,
        .timer = CONVERT_SECONDS(0.15f)
    },
    [2] = {
        .pFrame = sHiveOAM_Phase2_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sHiveOAM_Phase2_Frame3,
        .timer = CONVERT_SECONDS(0.15f)
    },
    [4] = {
        .pFrame = sHiveOAM_Phase2_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sHiveOAM_Phase2_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sHiveOAM_Phase2_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [7] = {
        .pFrame = sHiveOAM_Phase2_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [8] = {
        .pFrame = sHiveOAM_Phase2_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [9] = {
        .pFrame = sHiveOAM_Phase2_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [10] = {
        .pFrame = sHiveOAM_Phase2_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHiveOAM_Phase3[13] = {
    [0] = {
        .pFrame = sHiveOAM_Phase3_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sHiveOAM_Phase3_Frame1,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [2] = {
        .pFrame = sHiveOAM_Phase3_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sHiveOAM_Phase3_Frame1,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [4] = {
        .pFrame = sHiveOAM_Phase3_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sHiveOAM_Phase3_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sHiveOAM_Phase3_Frame2,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [7] = {
        .pFrame = sHiveOAM_Phase3_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = {
        .pFrame = sHiveOAM_Phase3_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sHiveOAM_Phase3_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sHiveOAM_Phase3_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [11] = {
        .pFrame = sHiveOAM_Phase3_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHiveOAM_Dying[32] = {
    [0] = {
        .pFrame = sHiveOAM_Phase3_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sHiveOAM_Phase3_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sHiveOAM_Phase3_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sHiveOAM_Phase3_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sHiveOAM_Phase3_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sHiveOAM_Phase3_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sHiveOAM_Phase3_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sHiveOAM_Phase3_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sHiveOAM_Dying_Frame8,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sHiveOAM_Dying_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = {
        .pFrame = sHiveOAM_Dying_Frame10,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [11] = {
        .pFrame = sHiveOAM_Dying_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [12] = {
        .pFrame = sHiveOAM_Dying_Frame12,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [13] = {
        .pFrame = sHiveOAM_Dying_Frame13,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [14] = {
        .pFrame = sHiveOAM_Dying_Frame14,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [15] = {
        .pFrame = sHiveOAM_Dying_Frame13,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [16] = {
        .pFrame = sHiveOAM_Dying_Frame12,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [17] = {
        .pFrame = sHiveOAM_Dying_Frame13,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [18] = {
        .pFrame = sHiveOAM_Dying_Frame14,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [19] = {
        .pFrame = sHiveOAM_Dying_Frame13,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [20] = {
        .pFrame = sHiveOAM_Dying_Frame12,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [21] = {
        .pFrame = sHiveOAM_Dying_Frame13,
        .timer = CONVERT_SECONDS(0.15f)
    },
    [22] = {
        .pFrame = sHiveOAM_Dying_Frame14,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [23] = {
        .pFrame = sHiveOAM_Dying_Frame13,
        .timer = CONVERT_SECONDS(0.15f)
    },
    [24] = {
        .pFrame = sHiveOAM_Dying_Frame12,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [25] = {
        .pFrame = sHiveOAM_Dying_Frame13,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [26] = {
        .pFrame = sHiveOAM_Dying_Frame14,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [27] = {
        .pFrame = sHiveOAM_Dying_Frame13,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [28] = {
        .pFrame = sHiveOAM_Dying_Frame12,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [29] = {
        .pFrame = sHiveOAM_Dying_Frame13,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [30] = {
        .pFrame = sHiveOAM_Dying_Frame30,
        .timer = UCHAR_MAX
    },
    [31] = FRAME_DATA_TERMINATOR
};
