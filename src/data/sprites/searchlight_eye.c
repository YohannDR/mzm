#include "data/sprites/searchlight_eye.h"
#include "macros.h"

const u32 sSearchlightEyeGfx[177] = INCBIN_U32("data/sprites/SearchlightEye.gfx.lz");
const u16 sSearchlightEyePal[16] = INCBIN_U16("data/sprites/SearchlightEye.pal");

const u16 sSearchlightEyeOAM_Idle_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSearchlightEyeOAM_Idle_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x8, OBJ_SPRITE_OAM | 0x204,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sSearchlightEyeOAM_Idle_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x205,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSearchlightEyeOAM_Idle_Frame10[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x8, OBJ_SPRITE_OAM | 0x204,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x209,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20b
};

const u16 sSearchlightEyeBeamOAM_Idle_Frame0[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x21c
};

const u16 sSearchlightEyeBeamOAM_Idle_Frame2[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x21c
};

const u16 sSearchlightEyeBeamOAM_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sSearchlightEyeBeamOAM_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c
};

const u16 sSearchlightEyeProjectileOAM_Moving_Frame0[OAM_DATA_SIZE(8)] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x219,
    0xf8, 0x0, OBJ_SPRITE_OAM | 0x239,
    0x0, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x239,
    0xf8, 0x8, OBJ_SPRITE_OAM | 0x23a,
    0x0, OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x23a,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    0x0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x23b
};

const u16 sSearchlightEyeProjectileOAM_Moving_Frame2[OAM_DATA_SIZE(8)] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f7, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x219,
    0xf8, 0x3, OBJ_SPRITE_OAM | 0x239,
    0x0, OBJ_Y_FLIP | 0x3, OBJ_SPRITE_OAM | 0x239,
    0xf8, 0xb, OBJ_SPRITE_OAM | 0x23a,
    0x0, OBJ_Y_FLIP | 0xb, OBJ_SPRITE_OAM | 0x23a,
    0xf8, 0x1fe, OBJ_SPRITE_OAM | 0x23b,
    0x0, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x23b
};

const u16 sSearchlightEyeProjectileOAM_Moving_Frame4[OAM_DATA_SIZE(8)] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x219,
    0xf8, 0x7, OBJ_SPRITE_OAM | 0x239,
    0x0, OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x239,
    0xf8, 0x1fd, OBJ_SPRITE_OAM | 0x23a,
    0x0, OBJ_Y_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x23a,
    0xf8, 0x0, OBJ_SPRITE_OAM | 0x23b,
    0x0, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x23b
};

const u16 sSearchlightEyeProjectileOAM_Moving_Frame6[OAM_DATA_SIZE(8)] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f7, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x219,
    0xf8, 0x1fe, OBJ_SPRITE_OAM | 0x239,
    0x0, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x239,
    0xf8, 0x3, OBJ_SPRITE_OAM | 0x23a,
    0x0, OBJ_Y_FLIP | 0x3, OBJ_SPRITE_OAM | 0x23a,
    0xf8, 0xd, OBJ_SPRITE_OAM | 0x23b,
    0x0, OBJ_Y_FLIP | 0xd, OBJ_SPRITE_OAM | 0x23b
};

const u16 sSearchlightEyeOAM_Shooting_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x8, OBJ_SPRITE_OAM | 0x204,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20d,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20f
};

const u16 sSearchlightEyeOAM_Shooting_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x215,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x8, OBJ_SPRITE_OAM | 0x204
};

const struct FrameData sSearchlightEyeOAM_Idle[13] = {
    [0] = {
        .pFrame = sSearchlightEyeOAM_Idle_Frame0,
        .timer = ONE_THIRD_SECOND
    },
    [1] = {
        .pFrame = sSearchlightEyeOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sSearchlightEyeOAM_Idle_Frame2,
        .timer = ONE_THIRD_SECOND
    },
    [3] = {
        .pFrame = sSearchlightEyeOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = {
        .pFrame = sSearchlightEyeOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [5] = {
        .pFrame = sSearchlightEyeOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sSearchlightEyeOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [7] = {
        .pFrame = sSearchlightEyeOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [8] = {
        .pFrame = sSearchlightEyeOAM_Idle_Frame0,
        .timer = ONE_THIRD_SECOND
    },
    [9] = {
        .pFrame = sSearchlightEyeOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [10] = {
        .pFrame = sSearchlightEyeOAM_Idle_Frame10,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [11] = {
        .pFrame = sSearchlightEyeOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSearchlightEyeBeamOAM_Idle[5] = {
    [0] = {
        .pFrame = sSearchlightEyeBeamOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSearchlightEyeBeamOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSearchlightEyeBeamOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSearchlightEyeBeamOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSearchlightEyeBeamOAM_Unused[2] = {
    [0] = {
        .pFrame = sSearchlightEyeBeamOAM_Unused_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSearchlightEyeProjectileOAM_Moving[9] = {
    [0] = {
        .pFrame = sSearchlightEyeProjectileOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSearchlightEyeBeamOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSearchlightEyeProjectileOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSearchlightEyeBeamOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSearchlightEyeProjectileOAM_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSearchlightEyeBeamOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sSearchlightEyeProjectileOAM_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sSearchlightEyeBeamOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSearchlightEyeOAM_Shooting[4] = {
    [0] = {
        .pFrame = sSearchlightEyeOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sSearchlightEyeOAM_Shooting_Frame1,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [2] = {
        .pFrame = sSearchlightEyeOAM_Shooting_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};
