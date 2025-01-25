#include "data/sprites/zipline.h"
#include "macros.h"

const u32 sZiplineGfx[264] = INCBIN_U32("data/sprites/Zipline.gfx.lz");
const u16 sZiplinePal[16] = INCBIN_U16("data/sprites/Zipline.pal");

const u16 sZiplineOam_OffIdle_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sZiplineOam_OffGrabbingSamus_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

const u16 sZiplineOam_OffGrabbingSamus_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sZiplineOam_OnGrabbingSamus_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

const u16 sZiplineOam_OnSamusGrabbed_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

const u16 sZiplineOam_OnSamusGrabbed_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

const u16 sZiplineOam_OnSamusGrabbed_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

const u16 sZiplineOam_OnIdle_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sZiplineOam_OnGrabbingSamus_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sZiplineOam_OnIdle_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sZiplineOam_OnIdle_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sZiplineButtonOAM_OffIdle_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1f8, OBJ_SPRITE_OAM | 0x214
};

const u16 sZiplineButtonOAM_OnIdle_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1f8, OBJ_SPRITE_OAM | 0x234
};

const u16 sZiplineButtonOAM_OnIdle_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1f8, OBJ_SPRITE_OAM | 0x216
};

const u16 sZiplineButtonOAM_OnIdle_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1f8, OBJ_SPRITE_OAM | 0x236
};

const struct FrameData sZiplineOam_OffIdle[2] = {
    [0] = {
        .pFrame = sZiplineOam_OffIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineOam_OffGrabbingSamus[4] = {
    [0] = {
        .pFrame = sZiplineOam_OffIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZiplineOam_OffGrabbingSamus_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZiplineOam_OffGrabbingSamus_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineOam_OffSamusGrabbed[2] = {
    [0] = {
        .pFrame = sZiplineOam_OffGrabbingSamus_Frame1,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineOam_OffReleasingSamus[4] = {
    [0] = {
        .pFrame = sZiplineOam_OffGrabbingSamus_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZiplineOam_OffGrabbingSamus_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZiplineOam_OffIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineOam_OnIdle[7] = {
    [0] = {
        .pFrame = sZiplineOam_OffIdle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sZiplineOam_OnIdle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sZiplineOam_OnIdle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sZiplineOam_OnIdle_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sZiplineOam_OnIdle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sZiplineOam_OnIdle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineOam_OnGrabbingSamus[4] = {
    [0] = {
        .pFrame = sZiplineOam_OnIdle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZiplineOam_OnGrabbingSamus_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZiplineOam_OnGrabbingSamus_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineOam_OnSamusGrabbed[7] = {
    [0] = {
        .pFrame = sZiplineOam_OnSamusGrabbed_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sZiplineOam_OnSamusGrabbed_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sZiplineOam_OnSamusGrabbed_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sZiplineOam_OnGrabbingSamus_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sZiplineOam_OnSamusGrabbed_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sZiplineOam_OnSamusGrabbed_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineOam_OnReleasingSamus[4] = {
    [0] = {
        .pFrame = sZiplineOam_OnGrabbingSamus_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZiplineOam_OnGrabbingSamus_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZiplineOam_OnIdle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineButtonOAM_OffIdle[2] = {
    [0] = {
        .pFrame = sZiplineButtonOAM_OffIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineButtonOAM_OnIdle[7] = {
    [0] = {
        .pFrame = sZiplineButtonOAM_OffIdle_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sZiplineButtonOAM_OnIdle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sZiplineButtonOAM_OnIdle_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sZiplineButtonOAM_OnIdle_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = {
        .pFrame = sZiplineButtonOAM_OnIdle_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sZiplineButtonOAM_OnIdle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineButtonOAM_Active[7] = {
    [0] = {
        .pFrame = sZiplineButtonOAM_OffIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZiplineButtonOAM_OnIdle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZiplineButtonOAM_OnIdle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sZiplineButtonOAM_OnIdle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sZiplineButtonOAM_OnIdle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sZiplineButtonOAM_OnIdle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = FRAME_DATA_TERMINATOR
};
