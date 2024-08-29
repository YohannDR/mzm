#include "data/projectile_data.h"
#include "structs/particle.h"
#include "macros.h"

const s16 sTumblingMissileSpeed[16] = {
    -12, -10, -8, -6,
     -4,  -2,  0,  0,
      1,   2,  4,  8,
     12,  16, 20,  SHORT_MAX
};

const u8 sProjectile_Array326cc8_Unused[64] = {
    24, 0, 16, 0, 8, 0, 4, 0, 4, 0, 8, 0, 16, 0, 24, 0,
    32, 0, 20, 0, 8, 0, 4, 0, 4, 0, 8, 0, 20, 0, 32, 0,
    24, 0, 20, 0, 16, 0, 12, 0, 12, 0, 8, 0, 4, 0, 0, 0,
    0, 0, 4, 0, 8, 0, 12, 0, 12, 0, 16, 0, 20, 0, 24, 0
};

static const u16 sBombOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, 0x414d
};

static const u16 sBombOam_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, 0x414e
};

static const u16 sBombOam_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, 0x414f
};

static const u16 sBombOam_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, 0x4150
};

static const u16 sPowerBombOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, 0x414b
};

static const u16 sPowerBombOam_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, 0x414c
};

static const u16 sPowerBombOam_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, 0x416b
};

const struct FrameData sBombOam_Slow[5] = {
    [0] = {
        .pFrame = sBombOam_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sBombOam_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sBombOam_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [3] = {
        .pFrame = sBombOam_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBombOam_Fast[5] = {
    [0] = {
        .pFrame = sBombOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sBombOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sBombOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sBombOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPowerBombOam_Slow[4] = {
    [0] = {
        .pFrame = sPowerBombOam_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sPowerBombOam_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sPowerBombOam_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPowerBombOam_Fast[4] = {
    [0] = {
        .pFrame = sPowerBombOam_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPowerBombOam_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = {
        .pFrame = sPowerBombOam_Frame2,
        .timer = CONVERT_SECONDS(.05f)
    },
    [3] = FRAME_DATA_TERMINATOR
};

static const u16 sMissileOam_Horizontal_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xfc, 0x3, 0x30d0,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, 0x4078
};

static const u16 sMissileOam_Horizontal_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xfc, 0x7, 0x30d1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, 0x4078
};

static const u16 sMissileOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0x1, 0x1, 0x30d0,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x405c
};

static const u16 sMissileOam_Diagonal_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x405c,
    0x3, 0x3, 0x30f0,
};

static const u16 sMissileOam_Vertical_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0x3, 0x1fc, 0x30d0,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4185
};

static const u16 sMissileOam_Vertical_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0x7, 0x1fc, 0x30f1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4185
};

static const u16 sSuperMissileOam_Horizontal_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x2, 0x30d3,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, 0x407a
};

static const u16 sSuperMissileOam_Horizontal_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, 0x407a,
    0xfc, 0x5, 0x30d1
};

static const u16 sSuperMissileOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xff, OBJ_SIZE_16x16 | 0x1ff, 0x30d3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x405e
};

static const u16 sSuperMissileOam_Diagonal_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x405e,
    0x3, 0x3, 0x30f0
};

static const u16 sSuperMissileOam_Vertical_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0x1, OBJ_SIZE_16x16 | 0x1f8, 0x30d3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4186
};

static const u16 sSuperMissileOam_Vertical_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4186,
    0x5, 0x1fc, 0x30f1
};

static const u16 sMissileOam_Tumbling_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, 0x4078
};

static const u16 sMissileOam_Tumbling_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x405c
};

static const u16 sMissileOam_Tumbling_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4185
};

static const u16 sMissileOam_Tumbling_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x405c
};

static const u16 sMissileOam_Tumbling_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1f8, 0x4078
};

static const u16 sMissileOam_Tumbling_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x405c
};

static const u16 sMissileOam_Tumbling_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_Y_FLIP | 0x1fc, 0x4185
};

static const u16 sMissileOam_Tumbling_Frame7[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x405c
};

static const u16 sSuperMissileOam_Tumbling_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, 0x407a
};

static const u16 sSuperMissileOam_Tumbling_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x405e
};

static const u16 sSuperMissileOam_Tumbling_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4186
};

static const u16 sSuperMissileOam_Tumbling_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x405e
};

static const u16 sSuperMissileOam_Tumbling_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1f8, 0x407a
};

static const u16 sSuperMissileOam_Tumbling_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x405e
};

static const u16 sSuperMissileOam_Tumbling_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_Y_FLIP | 0x1fc, 0x4186
};

static const u16 sSuperMissileOam_Tumbling_Frame7[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x405e
};

static const u16 sParticleMissileTrailOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x30d5
};

static const u16 sParticleMissileTrailOam_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x30f5
};

static const u16 sParticleMissileTrailOam_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x30f6
};

static const u16 sParticleSuperMissileTrailOam_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x4159
};

static const u16 sParticleMissileTrailOam_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, 0x1fc, 0x415a
};

static const u16 sParticleMissileTrailOam_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf7, 0x1fc, 0x415b
};

static const u16 sParticleMissileTrailOam_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf3, 0x1fc, 0x415c
};

static const u16 sParticleMissileTrailOam_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf1, 0x1fc, 0x415d
};

static const u16 sParticleSuperMissileTrailOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x30d0
};

const struct FrameData sMissileOam_Horizontal[3] = {
    [0] = {
        .pFrame = sMissileOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMissileOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMissileOam_Diagonal[3] = {
    [0] = {
        .pFrame = sMissileOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMissileOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMissileOam_Vertical[3] = {
    [0] = {
        .pFrame = sMissileOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMissileOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSuperMissileOam_Horizontal[3] = {
    [0] = {
        .pFrame = sSuperMissileOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSuperMissileOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSuperMissileOam_Diagonal[3] = {
    [0] = {
        .pFrame = sSuperMissileOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSuperMissileOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSuperMissileOam_Vertical[3] = {
    [0] = {
        .pFrame = sSuperMissileOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSuperMissileOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMissileOam_Tumbling[9] = {
    [0] = {
        .pFrame = sMissileOam_Tumbling_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sMissileOam_Tumbling_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = {
        .pFrame = sMissileOam_Tumbling_Frame2,
        .timer = CONVERT_SECONDS(.05f)
    },
    [3] = {
        .pFrame = sMissileOam_Tumbling_Frame3,
        .timer = CONVERT_SECONDS(.05f)
    },
    [4] = {
        .pFrame = sMissileOam_Tumbling_Frame4,
        .timer = CONVERT_SECONDS(.05f)
    },
    [5] = {
        .pFrame = sMissileOam_Tumbling_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [6] = {
        .pFrame = sMissileOam_Tumbling_Frame6,
        .timer = CONVERT_SECONDS(.05f)
    },
    [7] = {
        .pFrame = sMissileOam_Tumbling_Frame7,
        .timer = CONVERT_SECONDS(.05f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSuperMissileOam_Tumbling[9] = {
    [0] = {
        .pFrame = sSuperMissileOam_Tumbling_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sSuperMissileOam_Tumbling_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = {
        .pFrame = sSuperMissileOam_Tumbling_Frame2,
        .timer = CONVERT_SECONDS(.05f)
    },
    [3] = {
        .pFrame = sSuperMissileOam_Tumbling_Frame3,
        .timer = CONVERT_SECONDS(.05f)
    },
    [4] = {
        .pFrame = sSuperMissileOam_Tumbling_Frame4,
        .timer = CONVERT_SECONDS(.05f)
    },
    [5] = {
        .pFrame = sSuperMissileOam_Tumbling_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [6] = {
        .pFrame = sSuperMissileOam_Tumbling_Frame6,
        .timer = CONVERT_SECONDS(.05f)
    },
    [7] = {
        .pFrame = sSuperMissileOam_Tumbling_Frame7,
        .timer = CONVERT_SECONDS(.05f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleMissileTrailOam[8] = {
    [0] = {
        .pFrame = sParticleMissileTrailOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleMissileTrailOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleMissileTrailOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleMissileTrailOam_Frame3,
        .timer = CONVERT_SECONDS(.05f)
    },
    [4] = {
        .pFrame = sParticleMissileTrailOam_Frame4,
        .timer = CONVERT_SECONDS(.05f)
    },
    [5] = {
        .pFrame = sParticleMissileTrailOam_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [6] = {
        .pFrame = sParticleMissileTrailOam_Frame6,
        .timer = CONVERT_SECONDS(.05f)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSuperMissileTrailOam[9] = {
    [0] = {
        .pFrame = sParticleSuperMissileTrailOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleMissileTrailOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleMissileTrailOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleSuperMissileTrailOam_Frame3,
        .timer = CONVERT_SECONDS(.05f)
    },
    [4] = {
        .pFrame = sParticleMissileTrailOam_Frame3,
        .timer = CONVERT_SECONDS(.05f)
    },
    [5] = {
        .pFrame = sParticleMissileTrailOam_Frame4,
        .timer = CONVERT_SECONDS(.05f)
    },
    [6] = {
        .pFrame = sParticleMissileTrailOam_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [7] = {
        .pFrame = sParticleMissileTrailOam_Frame6,
        .timer = CONVERT_SECONDS(.05f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const u16 sBeamPal[16 * 6] = INCBIN_U16("data/weapons/Beams.pal");

const u8 sNormalBeamGfx_Top[512] = INCBIN_U8("data/weapons/NormalBeamTop.gfx");
const u8 sNormalBeamGfx_Bottom[512] = INCBIN_U8("data/weapons/NormalBeamBottom.gfx");
const u8 sNormalBeamGfx_Charged_Top[512] = INCBIN_U8("data/weapons/NormalBeamChargedTop.gfx");
const u8 sNormalBeamGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/NormalBeamChargedBottom.gfx");

static const u16 sNormalBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fa, 0x2080
};

static const u16 sNormalBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fa, 0x20a0
};

static const u16 sNormalBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x2082
};

static const u16 sNormalBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x2084
};

static const u16 sNormalBeamOam_Vertical_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1fc, 0x2086
};

static const u16 sNormalBeamOam_Vertical_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1fc, 0x2087
};

static const u16 sNormalBeamOam_Horizontal_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20a8
};

static const u16 sNormalBeamOam_Horizontal_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fd, 0x20a8
};

static const u16 sNormalBeamOam_Diagonal_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20a9
};

static const u16 sNormalBeamOam_Diagonal_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfd, 0x1fd, 0x20a9
};

static const u16 sNormalBeamOam_Vertical_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20aa
};

static const u16 sNormalBeamOam_Vertical_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfd, 0x1fc, 0x20aa
};

static const u16 sChargedNormalBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1fa, 0x20c0,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, 0x20c2
};

static const u16 sChargedNormalBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20c2,
    0xf8, OBJ_SIZE_16x16 | 0x1, 0x20c0,
    0xf8, OBJ_SIZE_16x16 | 0x9, 0x20c2
};

static const u16 sChargedNormalBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xfb, OBJ_SIZE_16x16 | 0x1fb, 0x20c4,
    0xfe, OBJ_SIZE_16x16 | 0x1fe, 0x20c6
};

static const u16 sChargedNormalBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfa, OBJ_SIZE_16x16 | 0x1fa, 0x20c6,
    0xff, OBJ_SIZE_16x16 | 0x1ff, 0x20c4,
    0x4, OBJ_SIZE_16x16 | 0x4, 0x20c6
};

static const u16 sChargedNormalBeamOam_Vertical_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xfa, OBJ_SIZE_16x16 | 0x1f8, 0x20c8,
    0xff, OBJ_SIZE_16x16 | 0x1f8, 0x20ca
};

static const u16 sChargedNormalBeamOam_Vertical_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20ca,
    0x1, OBJ_SIZE_16x16 | 0x1f8, 0x20c8,
    0x9, OBJ_SIZE_16x16 | 0x1f8, 0x20ca
};

static const u16 sChargedNormalBeamOam_Horizontal_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20ce
};

static const u16 sChargedNormalBeamOam_Horizontal_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20cf
};

static const u16 sChargedNormalBeamOam_Horizontal_Unused_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20ee
};

static const u16 sChargedNormalBeamOam_Horizontal_Unused_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20ef
};

const struct FrameData sNormalBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sNormalBeamOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        sNormalBeamOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNormalBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sNormalBeamOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        sNormalBeamOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNormalBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sNormalBeamOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        sNormalBeamOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNormalBeamOam_Horizontal_Unused[3] = {
    [0] = {
        .pFrame = sNormalBeamOam_Horizontal_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        sNormalBeamOam_Horizontal_Unused_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNormalBeamOam_Diagonal_Unused[3] = {
    [0] = {
        .pFrame = sNormalBeamOam_Diagonal_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        sNormalBeamOam_Diagonal_Unused_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNormalBeamOam_Vertical_Unused[3] = {
    [0] = {
        .pFrame = sNormalBeamOam_Vertical_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        sNormalBeamOam_Vertical_Unused_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedNormalBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sChargedNormalBeamOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedNormalBeamOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedNormalBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sChargedNormalBeamOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedNormalBeamOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedNormalBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sChargedNormalBeamOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedNormalBeamOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedNormalBeamOam_Horizontal_Unused[5] = {
    [0] = {
        .pFrame = sChargedNormalBeamOam_Horizontal_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sChargedNormalBeamOam_Horizontal_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sChargedNormalBeamOam_Horizontal_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sChargedNormalBeamOam_Horizontal_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const u8 sLongBeamGfx_Top[512] = INCBIN_U8("data/weapons/LongBeamTop.gfx");
const u8 sLongBeamGfx_Bottom[512] = INCBIN_U8("data/weapons/LongBeamBottom.gfx");
const u8 sLongBeamGfx_Charged_Top[512] = INCBIN_U8("data/weapons/LongBeamChargedTop.gfx");
const u8 sLongBeamGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/LongBeamChargedBottom.gfx");

static const u16 sLongBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fc, 0x2080
};

static const u16 sLongBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fc, 0x20a0
};

static const u16 sLongBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x20c0
};

static const u16 sLongBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x20c2
};

static const u16 sLongBeamOam_Vertical_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1fc, 0x2082
};

static const u16 sLongBeamOam_Vertical_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1fc, 0x2083
};

static const u16 sChargedLongBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1fa, 0x2086,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1, 0x20c6
};

static const u16 sChargedLongBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f8, 0x20c6,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x2, 0x2086,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0xb, 0x20c6
};

static const u16 sChargedLongBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x2084,
    0x2, OBJ_SIZE_16x16 | 0x2, 0x20c4
};

static const u16 sChargedLongBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfb, OBJ_SIZE_16x16 | 0x1fb, 0x20c4,
    0x1, OBJ_SIZE_16x16 | 0x1, 0x2084,
    0x8, OBJ_SIZE_16x16 | 0x8, 0x20c4
};

static const u16 sChargedLongBeamOam_Vertical_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xfa, OBJ_SIZE_16x32 | 0x1f8, 0x208a,
    OBJ_SHAPE_VERTICAL | 0x1, OBJ_SIZE_16x32 | 0x1f8, 0x208c
};

static const u16 sChargedLongBeamOam_Vertical_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x1f8, 0x208c,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_SIZE_16x32 | 0x1f8, 0x208a,
    OBJ_SHAPE_VERTICAL | 0xb, OBJ_SIZE_16x32 | 0x1f8, 0x208c
};

static const u16 sParticleChargedLongBeamTrailOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20ce
};

static const u16 sParticleChargedLongBeamTrailOam_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x208e
};

static const u16 sParticleChargedLongBeamTrailOam_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20cf
};

static const u16 sParticleChargedLongBeamTrailOam_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20ef
};

const struct FrameData sLongBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sLongBeamOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sLongBeamOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sLongBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sLongBeamOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sLongBeamOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sLongBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sLongBeamOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sLongBeamOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedLongBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sChargedLongBeamOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedLongBeamOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedLongBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sChargedLongBeamOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedLongBeamOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedLongBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sChargedLongBeamOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedLongBeamOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleChargedLongBeamTrailOam[5] = {
    [0] = {
        .pFrame = sParticleChargedLongBeamTrailOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleChargedLongBeamTrailOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleChargedLongBeamTrailOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleChargedLongBeamTrailOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const u8 sIceBeamGfx_Top[512] = INCBIN_U8("data/weapons/IceBeamTop.gfx");
const u8 sIceBeamGfx_Bottom[512] = INCBIN_U8("data/weapons/IceBeamBottom.gfx");
const u8 sIceBeamGfx_Charged_Top[512] = INCBIN_U8("data/weapons/IceBeamChargedTop.gfx");
const u8 sIceBeamGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/IceBeamChargedBottom.gfx");

static const u16 sIceBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1fb, 0x2080
};

static const u16 sIceBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1fc, 0x2082
};

static const u16 sIceBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfa, OBJ_SIZE_16x16 | 0x1f9, 0x2084
};

static const u16 sIceBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfb, OBJ_SIZE_16x16 | 0x1fa, 0x2086
};

static const u16 sIceBeamOam_Vertical_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfb, OBJ_SIZE_16x16 | 0x1f8, 0x2088
};

static const u16 sIceBeamOam_Vertical_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, OBJ_SIZE_16x16 | 0x1f8, 0x208a
};

static const u16 sIceBeamOam_Horizontal_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x208c
};

static const u16 sIceBeamOam_Horizontal_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fd, 0x208c
};

static const u16 sIceBeamOam_Diagonal_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x208d
};

static const u16 sIceBeamOam_Diagonal_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfd, 0x1fd, 0x208d
};

static const u16 sIceBeamOam_Vertical_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x208e
};

static const u16 sIceBeamOam_Vertical_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfd, 0x1fc, 0x208e
};

static const u16 sChargedIceBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1fa, 0x20c0,
    0xfc, 0xa, 0x20c2,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, 0x20c3,
    0xfc, 0xf, 0x20e2
};

static const u16 sChargedIceBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20c3,
    0xfc, 0x8, 0x20e2,
    0xf8, OBJ_SIZE_16x16 | 0x1, 0x20c0,
    0xfc, 0x11, 0x20c2,
    0xf8, OBJ_SIZE_16x16 | 0xa, 0x20c3,
    0xfc, 0x1a, 0x20e2
};

static const u16 sChargedIceBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xfb, OBJ_SIZE_16x16 | 0x1fb, 0x20c5,
    0xff, OBJ_SIZE_16x16 | 0x1ff, 0x20c7
};

static const u16 sChargedIceBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfa, OBJ_SIZE_16x16 | 0x1fa, 0x20c7,
    0xfe, OBJ_SIZE_16x16 | 0x1fe, 0x20c5,
    0x4, OBJ_SIZE_16x16 | 0x4, 0x20c7
};

static const u16 sChargedIceBeamOam_Vertical_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfa, OBJ_SIZE_16x16 | 0x1f8, 0x20c9,
    0xa, 0x1fc, 0x20cb,
    0xff, OBJ_SIZE_16x16 | 0x1f8, 0x20cc,
    0xf, 0x1fc, 0x20eb
};

static const u16 sChargedIceBeamOam_Vertical_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20cc,
    0x8, 0x1fc, 0x20eb,
    0x1, OBJ_SIZE_16x16 | 0x1f8, 0x20c9,
    0x11, 0x1fc, 0x20cb,
    0xa, OBJ_SIZE_16x16 | 0x1f8, 0x20cc,
    0x1a, 0x1fc, 0x20eb
};

static const u16 sParticleChargedIceBeamTrailOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x208c
};

static const u16 sParticleChargedIceBeamTrailOam_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20ce
};

static const u16 sParticleChargedIceBeamTrailOam_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20ae
};

static const u16 sParticleChargedIceBeamTrailOam_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20af
};

static const u16 sParticleChargedIceBeamTrailOam_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x208f
};

const struct FrameData sIceBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sIceBeamOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sIceBeamOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIceBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sIceBeamOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sIceBeamOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIceBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sIceBeamOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sIceBeamOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIceBeamOam_Horizontal_Unused[3] = {
    [0] = {
        .pFrame = sIceBeamOam_Horizontal_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sIceBeamOam_Horizontal_Unused_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIceBeamOam_Diagonal_Unused[3] = {
    [0] = {
        .pFrame = sIceBeamOam_Diagonal_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sIceBeamOam_Diagonal_Unused_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIceBeamOam_Vertical_Unused[3] = {
    [0] = {
        .pFrame = sIceBeamOam_Vertical_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sIceBeamOam_Vertical_Unused_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedIceBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sChargedIceBeamOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedIceBeamOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedIceBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sChargedIceBeamOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedIceBeamOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedIceBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sChargedIceBeamOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedIceBeamOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleChargedIceBeamTrailOam[6] = {
    [0] = {
        .pFrame = sParticleChargedIceBeamTrailOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleChargedIceBeamTrailOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleChargedIceBeamTrailOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleChargedIceBeamTrailOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sParticleChargedIceBeamTrailOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const u8 sWaveBeamGfx_Top[512] = INCBIN_U8("data/weapons/WaveBeamTop.gfx");
const u8 sWaveBeamGfx_Bottom[512] = INCBIN_U8("data/weapons/WaveBeamBottom.gfx");
const u8 sWaveBeamGfx_Charged_Top[512] = INCBIN_U8("data/weapons/WaveBeamChargedTop.gfx");
const u8 sWaveBeamGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/WaveBeamChargedBottom.gfx");

static const u16 sWaveBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fb, 0x2080
};

static const u16 sWaveBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x5, 0x20a0
};

static const u16 sWaveBeamOam_Horizontal_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0xd, 0x20a0
};

static const u16 sWaveBeamOam_Horizontal_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1fb, 0x2080
};

static const u16 sWaveBeamOam_Horizontal_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0x5, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xef, 0x1fb, 0x20a0,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1fb, 0x20a0
};

static const u16 sWaveBeamOam_Horizontal_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xf2, 0x1fb, 0x20a0,
    OBJ_SHAPE_HORIZONTAL | 0x6, 0x1fb, 0x20a0
};

static const u16 sWaveBeamOam_Horizontal_Frame6[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1fb, 0x20a0,
    OBJ_SHAPE_HORIZONTAL | 0x2, 0x1fb, 0x20a0
};

static const u16 sWaveBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x20c0
};

static const u16 sWaveBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf6, OBJ_SIZE_16x16 | 0x1fd, 0x20c0,
    0xfc, OBJ_SIZE_16x16 | 0x1f6, 0x20c0,
    0x0, OBJ_SIZE_16x16 | 0x1, 0x20c2
};

static const u16 sWaveBeamOam_Diagonal_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1ff, 0x20c0,
    0xfe, OBJ_SIZE_16x16 | 0x1f4, 0x20c0,
    0x5, OBJ_SIZE_16x16 | 0x5, 0x20c2
};

static const u16 sWaveBeamOam_Diagonal_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x2, 0x20c0,
    0x1, OBJ_SIZE_16x16 | 0x1f1, 0x20c0
};

static const u16 sWaveBeamOam_Diagonal_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf2, OBJ_SIZE_16x16 | 0x1ff, 0x20c0,
    0xff, OBJ_SIZE_16x16 | 0x1f3, 0x20c0,
    0xef, OBJ_SIZE_16x16 | 0x3, 0x20c2,
    0x2, OBJ_SIZE_16x16 | 0x1f0, 0x20c2
};

static const u16 sWaveBeamOam_Diagonal_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf6, OBJ_SIZE_16x16 | 0x1fc, 0x20c0,
    0xfb, OBJ_SIZE_16x16 | 0x1f7, 0x20c0,
    0xf2, OBJ_SIZE_16x16 | 0x1, 0x20c2,
    0x0, OBJ_SIZE_16x16 | 0x1f3, 0x20c2
};

static const u16 sWaveBeamOam_Diagonal_Frame6[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x20c0,
    0xf4, OBJ_SIZE_16x16 | 0x1fe, 0x20c2,
    0xfe, OBJ_SIZE_16x16 | 0x1f4, 0x20c2
};

static const u16 sWaveBeamOam_Vertical_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1fc, 0x2082
};

static const u16 sWaveBeamOam_Vertical_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x0, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1f8, 0x2082,
    OBJ_SHAPE_VERTICAL | 0x5, 0x1fc, 0x20c6
};

static const u16 sWaveBeamOam_Vertical_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x4, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1f4, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xd, 0x1fc, 0x20c6
};

static const u16 sWaveBeamOam_Vertical_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x8, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1f0, 0x2082
};

static const u16 sWaveBeamOam_Vertical_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x5, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1f3, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x9, 0x20c6,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1ef, 0x20c6
};

static const u16 sWaveBeamOam_Vertical_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x0, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1f8, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x6, 0x20c6,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1f2, 0x20c6
};

static const u16 sWaveBeamOam_Vertical_Frame6[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1fc, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x2, 0x20c6,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1f6, 0x20c6
};

static const u16 sWaveBeamOam_Horizontal_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, 0x20ee
};

static const u16 sWaveBeamOam_Horizontal_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, 0x20ee
};

static const u16 sWaveBeamOam_Horizontal_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0x1, 0x1fd, 0x2084,
    0xf7, 0x1fd, 0x2084,
    0xfc, 0x9, 0x2085,
    0xfc, 0x1fa, 0x2084
};

static const u16 sWaveBeamOam_Horizontal_Unused_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0x5, 0x0, 0x2084,
    0xf3, 0x0, 0x2084,
    0xf6, 0x1fd, 0x2084,
    0x2, 0x1fd, 0x2084
};

static const u16 sWaveBeamOam_Horizontal_Unused_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    0x7, 0x4, 0x2084,
    0xf1, 0x4, 0x2084,
    0xf2, 0x0, 0x2084,
    0x6, 0x0, 0x2084
};

static const u16 sWaveBeamOam_Horizontal_Unused_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf3, 0xd, 0x2084,
    0x5, 0xd, 0x2084,
    0x7, 0x8, 0x2084,
    0xf1, 0x8, 0x2084
};

static const u16 sWaveBeamOam_Horizontal_Unused_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf5, 0x10, 0x2084,
    0x3, 0x10, 0x2084,
    0xf8, 0x13, 0x2085,
    0x0, 0x13, 0x2085
};

static const u16 sWaveBeamOam_Diagonal_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20a4
};

static const u16 sWaveBeamOam_Diagonal_Unused_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfa, 0x1fc, 0x20a4,
    0xfc, 0x1fa, 0x20a4,
    0xff, 0x1ff, 0x20a5
};

static const u16 sWaveBeamOam_Diagonal_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, 0x1fd, 0x20a4,
    0xfd, 0x1f8, 0x20a4,
    0x1, 0x1, 0x20a5,
    0xf9, 0x1f9, 0x20a4
};

static const u16 sWaveBeamOam_Diagonal_Unused_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, 0x3, 0x20a4,
    0x3, 0x1f8, 0x20a4,
    0xf7, 0x1fe, 0x20a4,
    0xfe, 0x1f7, 0x20a4
};

static const u16 sWaveBeamOam_Diagonal_Unused_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf9, 0x7, 0x20a4,
    0x7, 0x1f9, 0x20a4,
    0xf6, 0x3, 0x20a4,
    0x3, 0x1f6, 0x20a4
};

static const u16 sWaveBeamOam_Diagonal_Unused_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    0x1, 0xc, 0x20a4,
    0xc, 0x1, 0x20a4,
    0xfc, 0xa, 0x20a4,
    0xa, 0x1fc, 0x20a4
};

static const u16 sWaveBeamOam_Diagonal_Unused_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    0x3, 0xe, 0x20a4,
    0xe, 0x3, 0x20a4,
    0xf, 0x8, 0x20a5,
    0x8, 0xf, 0x20a5
};

static const u16 sWaveBeamOam_Vertical_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20c4
};

static const u16 sWaveBeamOam_Vertical_Unused_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfd, 0x1fe, 0x20c4,
    0xfd, 0x1fa, 0x20c4,
    0x3, 0x1fc, 0x20c5
};

static const u16 sWaveBeamOam_Vertical_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfd, 0x1, 0x20c4,
    0xfd, 0x1f7, 0x20c4,
    0x9, 0x1fc, 0x20c5,
    0xfa, 0x1fc, 0x20c4
};

static const u16 sWaveBeamOam_Vertical_Unused_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0x0, 0x5, 0x20c4,
    0x0, 0x1f3, 0x20c4,
    0xfd, 0x2, 0x20c4,
    0xfd, 0x1f6, 0x20c4
};

static const u16 sWaveBeamOam_Vertical_Unused_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    0x4, 0x7, 0x20c4,
    0x4, 0x1f1, 0x20c4,
    0x0, 0x6, 0x20c4,
    0x0, 0x1f2, 0x20c4
};

static const u16 sWaveBeamOam_Vertical_Unused_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    0xd, 0x5, 0x20c4,
    0xd, 0x1f3, 0x20c4,
    0x8, 0x7, 0x20c4,
    0x8, 0x1f1, 0x20c4
};

static const u16 sWaveBeamOam_Vertical_Unused_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    0x10, 0x3, 0x20c4,
    0x10, 0x1f5, 0x20c4,
    0x13, 0x1f8, 0x20c5,
    0x13, 0x0, 0x20c5
};

static const u16 sChargedWaveBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f9, 0x2083
};

static const u16 sChargedWaveBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f7, 0x2083,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f7, 0x2083,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x4, 0x2086
};

static const u16 sChargedWaveBeamOam_Horizontal_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1f7, 0x2083,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1f7, 0x2083,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f3, 0x2083,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x10, 0x2086
};

static const u16 sChargedWaveBeamOam_Horizontal_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_32x16 | 0x1fb, 0x2083,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x16 | 0x1fb, 0x2083
};

static const u16 sChargedWaveBeamOam_Horizontal_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xea, OBJ_SIZE_32x16 | 0x1, 0x2083,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x1, 0x2083
};

static const u16 sChargedWaveBeamOam_Horizontal_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_32x16 | 0x8, 0x2083,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x16 | 0x8, 0x2083
};

static const u16 sChargedWaveBeamOam_Horizontal_Frame6[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0xc, 0x2086,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0xc, 0x2086
};

static const u16 sChargedWaveBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x20c4,
    0x4, 0x4, 0x20e7
};

static const u16 sChargedWaveBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf6, OBJ_SIZE_16x16 | 0x1f9, 0x20c4,
    0x1, 0x4, 0x20e7,
    0xf9, OBJ_SIZE_16x16 | 0x1f6, 0x20c4,
    0x4, 0x1, 0x20e7,
    0x1, OBJ_SIZE_16x16 | 0x1, 0x20c8,
    0xc, 0xc, 0x20e7
};

static const u16 sChargedWaveBeamOam_Diagonal_Frame2[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf3, OBJ_SIZE_16x16 | 0x1fc, 0x20c4,
    0xfe, 0x7, 0x20e7,
    0xfc, OBJ_SIZE_16x16 | 0x1f3, 0x20c4,
    0x7, 0x1fe, 0x20e7,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x20c4,
    0xff, 0x1ff, 0x20e7,
    0x7, OBJ_SIZE_16x16 | 0x7, 0x20c8,
    0x12, 0x12, 0x20e7
};

static const u16 sChargedWaveBeamOam_Diagonal_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf2, OBJ_SIZE_16x16 | 0x2, 0x20c4,
    0xfd, 0xd, 0x20e7,
    0x2, OBJ_SIZE_16x16 | 0x1f2, 0x20c4,
    0xd, 0x1fd, 0x20e7
};

static const u16 sChargedWaveBeamOam_Diagonal_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf3, OBJ_SIZE_16x16 | 0x6, 0x20c4,
    0xfe, 0x11, 0x20e7,
    0x6, OBJ_SIZE_16x16 | 0x1f3, 0x20c4,
    0x11, 0x1fe, 0x20e7
};

static const u16 sChargedWaveBeamOam_Diagonal_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfa, OBJ_SIZE_16x16 | 0xb, 0x20c4,
    0x5, 0x16, 0x20e7,
    0xa, OBJ_SIZE_16x16 | 0x1fb, 0x20c4,
    0x15, 0x6, 0x20e7
};

static const u16 sChargedWaveBeamOam_Diagonal_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    0x2, OBJ_SIZE_16x16 | 0xc, 0x20c8,
    0xd, 0x17, 0x20e7,
    0xb, OBJ_SIZE_16x16 | 0x3, 0x20c8,
    0x16, 0xe, 0x20e7
};

static const u16 sChargedWaveBeamOam_Vertical_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_16x32 | 0x1f8, 0x208a
};

static const u16 sChargedWaveBeamOam_Vertical_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_SIZE_16x32 | 0x1fa, 0x208a,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_SIZE_16x32 | 0x1f6, 0x208a,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_SIZE_16x32 | 0x1f8, 0x208c
};

static const u16 sChargedWaveBeamOam_Vertical_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_SIZE_16x32 | 0x1fe, 0x208a,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_SIZE_16x32 | 0x1f2, 0x208a,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_SIZE_16x32 | 0x1f8, 0x208a,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_SIZE_16x32 | 0x1f8, 0x208c
};

static const u16 sChargedWaveBeamOam_Vertical_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xfb, OBJ_SIZE_16x32 | 0x3, 0x208a,
    OBJ_SHAPE_VERTICAL | 0xfb, OBJ_SIZE_16x32 | 0x1ed, 0x208a
};

static const u16 sChargedWaveBeamOam_Vertical_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x1, OBJ_SIZE_16x32 | 0x6, 0x208a,
    OBJ_SHAPE_VERTICAL | 0x1, OBJ_SIZE_16x32 | 0x1ea, 0x208a
};

static const u16 sChargedWaveBeamOam_Vertical_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_16x32 | 0x3, 0x208a,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_16x32 | 0x1ed, 0x208a
};

static const u16 sChargedWaveBeamOam_Vertical_Frame6[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_SIZE_16x32 | 0x1ff, 0x208c,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_SIZE_16x32 | 0x1f1, 0x208c
};

static const u16 sParticleChargedWaveBeamTrailOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20c7
};

static const u16 sParticleChargedWaveBeamTrailOam_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, 0x208e,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f8, 0x208e
};

static const u16 sParticleChargedWaveBeamTrailOam_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20ae
};

static const u16 sParticleChargedWaveBeamTrailOam_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, 0x20ee,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f8, 0x20ee
};

const struct FrameData sWaveBeamOam_Horizontal[8] = {
    [0] = {
        .pFrame = sWaveBeamOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sWaveBeamOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sWaveBeamOam_Horizontal_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sWaveBeamOam_Horizontal_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sWaveBeamOam_Horizontal_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sWaveBeamOam_Horizontal_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sWaveBeamOam_Horizontal_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaveBeamOam_Diagonal[8] = {
    [0] = {
        .pFrame = sWaveBeamOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sWaveBeamOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sWaveBeamOam_Diagonal_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sWaveBeamOam_Diagonal_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sWaveBeamOam_Diagonal_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sWaveBeamOam_Diagonal_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sWaveBeamOam_Diagonal_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaveBeamOam_Vertical[8] = {
    [0] = {
        .pFrame = sWaveBeamOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sWaveBeamOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sWaveBeamOam_Vertical_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sWaveBeamOam_Vertical_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sWaveBeamOam_Vertical_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sWaveBeamOam_Vertical_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sWaveBeamOam_Vertical_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaveBeamOam_Horizontal_Unused[8] = {
    [0] = {
        .pFrame = sWaveBeamOam_Horizontal_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sWaveBeamOam_Horizontal_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sWaveBeamOam_Horizontal_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sWaveBeamOam_Horizontal_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sWaveBeamOam_Horizontal_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sWaveBeamOam_Horizontal_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sWaveBeamOam_Horizontal_Unused_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaveBeamOam_Diagonal_Unused[8] = {
    [0] = {
        .pFrame = sWaveBeamOam_Diagonal_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sWaveBeamOam_Diagonal_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sWaveBeamOam_Diagonal_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sWaveBeamOam_Diagonal_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sWaveBeamOam_Diagonal_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sWaveBeamOam_Diagonal_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sWaveBeamOam_Diagonal_Unused_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaveBeamOam_Vertical_Unused[8] = {
    [0] = {
        .pFrame = sWaveBeamOam_Vertical_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sWaveBeamOam_Vertical_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sWaveBeamOam_Vertical_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sWaveBeamOam_Vertical_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sWaveBeamOam_Vertical_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sWaveBeamOam_Vertical_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sWaveBeamOam_Vertical_Unused_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedWaveBeamOam_Horizontal[8] = {
    [0] = {
        .pFrame = sChargedWaveBeamOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sChargedWaveBeamOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sChargedWaveBeamOam_Horizontal_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sChargedWaveBeamOam_Horizontal_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sChargedWaveBeamOam_Horizontal_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sChargedWaveBeamOam_Horizontal_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sChargedWaveBeamOam_Horizontal_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedWaveBeamOam_Diagonal[8] = {
    [0] = {
        .pFrame = sChargedWaveBeamOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sChargedWaveBeamOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sChargedWaveBeamOam_Diagonal_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sChargedWaveBeamOam_Diagonal_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sChargedWaveBeamOam_Diagonal_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sChargedWaveBeamOam_Diagonal_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sChargedWaveBeamOam_Diagonal_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedWaveBeamOam_Vertical[8] = {
    [0] = {
        .pFrame = sChargedWaveBeamOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sChargedWaveBeamOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sChargedWaveBeamOam_Vertical_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sChargedWaveBeamOam_Vertical_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sChargedWaveBeamOam_Vertical_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sChargedWaveBeamOam_Vertical_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sChargedWaveBeamOam_Vertical_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleChargedWaveBeamTrailOam[5] = {
    [0] = {
        .pFrame = sParticleChargedWaveBeamTrailOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleChargedWaveBeamTrailOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleChargedWaveBeamTrailOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleChargedWaveBeamTrailOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const u8 sPlasmaBeamGfx_Top[512] = INCBIN_U8("data/weapons/PlasmaBeamTop.gfx");
const u8 sPlasmaBeamGfx_Bottom[512] = INCBIN_U8("data/weapons/PlasmaBeamBottom.gfx");
const u8 sPlasmaBeamGfx_Charged_Top[512] = INCBIN_U8("data/weapons/PlasmaBeamChargedTop.gfx");
const u8 sPlasmaBeamGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/PlasmaBeamChargedBottom.gfx");

static const u16 sPlasmaBeamOam_Horizontal_NoWave_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f8, 0x20e0
};

static const u16 sPlasmaBeamOam_Horizontal_NoWave_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f9, 0x20e4
};

static const u16 sPlasmaBeamOam_Diagonal_NoWave_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfb, OBJ_SIZE_16x16 | 0x1fb, 0x208e
};

static const u16 sPlasmaBeamOam_Diagonal_NoWave_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x20ce
};

static const u16 sPlasmaBeamOam_Vertical_NoWave_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1fc, 0x2083
};

static const u16 sPlasmaBeamOam_Vertical_NoWave_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_8x32 | 0x1fc, 0x2087
};

static const u16 sChargedPlasmaBeamOam_Horizontal_NoWave_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f8, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x0, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x0, 0x20ca
};

static const u16 sChargedPlasmaBeamOam_Horizontal_NoWave_Frame1[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f6, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x2, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x2, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0xc, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0xc, 0x20ca
};

static const u16 sChargedPlasmaBeamOam_Diagonal_NoWave_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfa, OBJ_SIZE_16x16 | 0x1fa, 0x2080,
    0x2, OBJ_SIZE_16x16 | 0x2, 0x20a1,
    0xff, OBJ_SIZE_16x16 | 0x1ff, 0x2084,
    0x7, OBJ_SIZE_16x16 | 0x7, 0x20a5
};

static const u16 sChargedPlasmaBeamOam_Diagonal_NoWave_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2080,
    0x0, OBJ_SIZE_16x16 | 0x0, 0x20a1,
    0x0, OBJ_SIZE_16x16 | 0x0, 0x2084,
    0x8, OBJ_SIZE_16x16 | 0x8, 0x20a5,
    0x8, OBJ_SIZE_16x16 | 0x8, 0x2084,
    0x10, OBJ_SIZE_16x16 | 0x10, 0x20a5
};

static const u16 sChargedPlasmaBeamOam_Vertical_NoWave_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x0, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x0, 0x2089,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2089
};

static const u16 sChargedPlasmaBeamOam_Vertical_NoWave_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_SIZE_8x32 | 0x0, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_SIZE_8x32 | 0x0, 0x2089,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2089,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_SIZE_8x32 | 0x0, 0x2089,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2089
};

static const u16 sPlasmaBeamOam_Horizontal_Wave_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x6, 0x20e4
};

static const u16 sPlasmaBeamOam_Horizontal_Wave_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x10, 0x20e4,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f8, 0x20e0
};

static const u16 sPlasmaBeamOam_Horizontal_Wave_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f9, 0x20e4
};

static const u16 sPlasmaBeamOam_Horizontal_Wave_Frame4[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x8 | 0x1f8, 0x20e4,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x8 | 0x1f8, 0x20e4,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f8, 0x20e0
};

static const u16 sPlasmaBeamOam_Horizontal_Wave_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x8 | 0x1f8, 0x20e4,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x8 | 0x1f8, 0x20e4
};

static const u16 sPlasmaBeamOam_Horizontal_Wave_Frame6[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x8 | 0x1f8, 0x20e4,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x8 | 0x1f8, 0x20e4
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1fd, 0x208e,
    0xfe, OBJ_SIZE_16x16 | 0x1f7, 0x208e,
    0x5, OBJ_SIZE_16x16 | 0x5, 0x20ce
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf5, OBJ_SIZE_16x16 | 0x1, 0x208e,
    0x1, OBJ_SIZE_16x16 | 0x1f5, 0x208e,
    0xc, OBJ_SIZE_16x16 | 0xc, 0x20ce,
    0xfb, OBJ_SIZE_16x16 | 0x1fb, 0x208e
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x4, 0x208e,
    0x4, OBJ_SIZE_16x16 | 0x1f2, 0x208e,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x20ce
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Frame4[OAM_DATA_SIZE(5)] = {
    0x5,
    0x2, OBJ_SIZE_16x16 | 0x1f4, 0x208e,
    0xf4, OBJ_SIZE_16x16 | 0x2, 0x208e,
    0x5, OBJ_SIZE_16x16 | 0x1f0, 0x20ce,
    0xf0, OBJ_SIZE_16x16 | 0x6, 0x20ce,
    0xfb, OBJ_SIZE_16x16 | 0x1fb, 0x208e
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfe, OBJ_SIZE_16x16 | 0x1f7, 0x208e,
    0xf8, OBJ_SIZE_16x16 | 0x1fd, 0x208e,
    0x2, OBJ_SIZE_16x16 | 0x1f3, 0x20ce,
    0xf3, OBJ_SIZE_16x16 | 0x3, 0x20ce
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Frame6[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfb, OBJ_SIZE_16x16 | 0x1fb, 0x208e,
    0xff, OBJ_SIZE_16x16 | 0x1f7, 0x20ce,
    0xf7, OBJ_SIZE_16x16 | 0x1ff, 0x20ce
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x0, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1f8, 0x2083,
    OBJ_SHAPE_VERTICAL | 0x6, OBJ_SIZE_8x32 | 0x1fc, 0x2087
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x4, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1f4, 0x2083,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_SIZE_8x32 | 0x1fc, 0x2087,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1fc, 0x2083
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x8, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1f0, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_8x32 | 0x1fc, 0x2087
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Frame4[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x5, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1f3, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x9, 0x2087,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1ef, 0x2087,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1fc, 0x2083
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x0, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1f8, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x5, 0x2087,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1f3, 0x2087
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Frame6[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1fc, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x2, 0x2087,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1f6, 0x2087
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Unused_Frame3[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf7, 0x3, 0x208e,
    0x3, 0x1f7, 0x208e,
    0xf6, 0x1fd, 0x208f,
    0xfd, 0x1f6, 0x208f,
    0x4, 0x4, 0x208f,
    0x1, 0x1, 0x208e
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Unused_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfb, 0x7, 0x208f,
    0x7, 0x1fb, 0x208f,
    0x5, 0x5, 0x208f,
    0xff, 0x1ff, 0x208e
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Unused_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfc, 0x1fe, 0x20c4,
    0xfc, 0x1fa, 0x20c4,
    0x0, 0x1fc, 0x2086
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Unused_Frame2[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf8, 0x1ff, 0x20c4,
    0xf8, 0x1f9, 0x20c4,
    0xfd, 0x4, 0x20c4,
    0xfd, 0x1f4, 0x20c4,
    0x1, 0x1fc, 0x20c4
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Unused_Frame3[OAM_DATA_SIZE(5)] = {
    0x5,
    0x1, 0x6, 0x20c4,
    0x1, 0x1f2, 0x20c4,
    0xfb, 0x2, 0x2086,
    0xfb, 0x1f6, 0x2086,
    0x7, 0x1fc, 0x2086
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Unused_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0x5, 0x6, 0x2086,
    0x5, 0x1f2, 0x2086,
    0xb, 0x1fc, 0x2086
};

static const u16 sChargedPlasmaBeamOam_Horizontal_Wave_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f9, 0x208a
};

static const u16 sChargedPlasmaBeamOam_Horizontal_Wave_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f7, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f7, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x4, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x4, 0x20ca
};

static const u16 sChargedPlasmaBeamOam_Horizontal_Wave_Frame2[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1f7, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1f7, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f3, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x10, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x10, 0x20ca
};

static const u16 sChargedPlasmaBeamOam_Horizontal_Wave_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_32x16 | 0x1fb, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x16 | 0x1fb, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x208a
};

static const u16 sChargedPlasmaBeamOam_Horizontal_Wave_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xea, OBJ_SIZE_32x16 | 0x1, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x1, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x0, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x0, 0x20ca
};

static const u16 sChargedPlasmaBeamOam_Horizontal_Wave_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_32x16 | 0x8, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x16 | 0x8, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x10, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x10, 0x20ca
};

static const u16 sChargedPlasmaBeamOam_Horizontal_Wave_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x8 | 0xc, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0xc, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0xc, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0xc, 0x20ca
};

static const u16 sChargedPlasmaBeamOam_Diagonal_Wave_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x2080,
    0x1, OBJ_SIZE_16x16 | 0x1, 0x20a1
};

static const u16 sChargedPlasmaBeamOam_Diagonal_Wave_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf6, OBJ_SIZE_16x16 | 0x1f9, 0x2080,
    0xfe, OBJ_SIZE_16x16 | 0x1, 0x20a1,
    0xf9, OBJ_SIZE_16x16 | 0x1f6, 0x2080,
    0x1, OBJ_SIZE_16x16 | 0x1fe, 0x20a1,
    0x1, OBJ_SIZE_16x16 | 0x1, 0x2084,
    0x9, OBJ_SIZE_16x16 | 0x9, 0x20a5
};

static const u16 sChargedPlasmaBeamOam_Diagonal_Wave_Frame2[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf3, OBJ_SIZE_16x16 | 0x1fc, 0x2080,
    0xfb, OBJ_SIZE_16x16 | 0x4, 0x20a1,
    0xfc, OBJ_SIZE_16x16 | 0x1f3, 0x2080,
    0x4, OBJ_SIZE_16x16 | 0x1fb, 0x20a1,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x2080,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x20a1,
    0x7, OBJ_SIZE_16x16 | 0x7, 0x2084,
    0xf, OBJ_SIZE_16x16 | 0xf, 0x20a5
};

static const u16 sChargedPlasmaBeamOam_Diagonal_Wave_Frame3[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf2, OBJ_SIZE_16x16 | 0x2, 0x2080,
    0xfa, OBJ_SIZE_16x16 | 0xa, 0x20a1,
    0x2, OBJ_SIZE_16x16 | 0x1f2, 0x2080,
    0xa, OBJ_SIZE_16x16 | 0x1fa, 0x20a1,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x2080,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20a1
};

static const u16 sChargedPlasmaBeamOam_Diagonal_Wave_Frame4[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf3, OBJ_SIZE_16x16 | 0x6, 0x2080,
    0xfb, OBJ_SIZE_16x16 | 0xe, 0x20a1,
    0x6, OBJ_SIZE_16x16 | 0x1f3, 0x2080,
    0xe, OBJ_SIZE_16x16 | 0x1fb, 0x20a1,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x2084,
    0x4, OBJ_SIZE_16x16 | 0x4, 0x20a5
};

static const u16 sPlasmaBeamOam_Horizontal_Wave_Unused_Frame3[OAM_DATA_SIZE(6)] = {
    0x6,
    0xfa, OBJ_SIZE_16x16 | 0xa, 0x2080,
    0x2, OBJ_SIZE_16x16 | 0x12, 0x20a1,
    0xa, OBJ_SIZE_16x16 | 0x1fa, 0x2080,
    0x12, OBJ_SIZE_16x16 | 0x2, 0x20a1,
    0x8, OBJ_SIZE_16x16 | 0x8, 0x2084,
    0x10, OBJ_SIZE_16x16 | 0x10, 0x20a5
};

static const u16 sPlasmaBeamOam_Horizontal_Wave_Unused_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    0x2, OBJ_SIZE_16x16 | 0xc, 0x2084,
    0xa, OBJ_SIZE_16x16 | 0x14, 0x20a5,
    0xc, OBJ_SIZE_16x16 | 0x2, 0x2084,
    0x14, OBJ_SIZE_16x16 | 0xa, 0x20a5
};

static const u16 sChargedPlasmaBeamOam_Vertical_Wave_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_8x32 | 0x0, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2088
};

static const u16 sChargedPlasmaBeamOam_Vertical_Wave_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_SIZE_8x32 | 0x2, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fa, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_SIZE_8x32 | 0x1fd, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f5, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_SIZE_8x32 | 0x0, 0x2089,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2089
};

static const u16 sChargedPlasmaBeamOam_Vertical_Wave_Frame2[OAM_DATA_SIZE(8)] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_SIZE_8x32 | 0x6, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fe, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_SIZE_8x32 | 0x1fa, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f2, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_SIZE_8x32 | 0x0, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_SIZE_8x32 | 0x0, 0x2089,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2089
};

static const u16 sChargedPlasmaBeamOam_Vertical_Wave_Frame3[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xfd, OBJ_SIZE_8x32 | 0xb, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xfd, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x3, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xfd, OBJ_SIZE_8x32 | 0x1f5, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xfd, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1ed, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x0, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2088
};

static const u16 sChargedPlasmaBeamOam_Vertical_Wave_Frame4[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0x1, OBJ_SIZE_8x32 | 0xe, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x1, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x6, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x1, OBJ_SIZE_8x32 | 0x1f2, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x1, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1ea, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x0, 0x2089,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2089
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Unused_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_8x32 | 0xb, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x3, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_8x32 | 0x1f5, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1ed, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_SIZE_8x32 | 0x0, 0x2089,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2089
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_SIZE_8x32 | 0x1f9, 0x2089,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f1, 0x2089,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_SIZE_8x32 | 0x7, 0x2089,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1ff, 0x2089
};

static const u16 sParticleChargedPlasmaBeamTrailOam_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, 0x1f8, 0x20ea,
    0xf8, OBJ_X_FLIP | 0x0, 0x20ea,
    0x0, OBJ_Y_FLIP | 0x1f8, 0x20ea,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, 0x20ea
};

static const u16 sParticleChargedFullBeamTrailOam_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf9, 0x1f9, 0x20ea,
    0xf9, OBJ_X_FLIP | 0x1ff, 0x20ea,
    0xff, OBJ_Y_FLIP | 0x1f9, 0x20ea,
    0xff, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ff, 0x20ea
};

static const u16 sParticleChargedPlasmaBeamTrailOam_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, 0x1f8, 0x20eb,
    0xf8, OBJ_X_FLIP | 0x0, 0x20eb,
    0x0, OBJ_Y_FLIP | 0x1f8, 0x20eb,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, 0x20eb
};

static const u16 sParticleChargedFullBeamTrailOam_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf9, 0x1f9, 0x20eb,
    0xf9, OBJ_X_FLIP | 0x1ff, 0x20eb,
    0xff, OBJ_Y_FLIP | 0x1f9, 0x20eb,
    0xff, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ff, 0x20eb
};

static const u16 sParticleChargedPlasmaBeamTrailOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20c0
};

static const u16 sParticleChargedFullBeamTrailOam_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x2082
};

static const u16 sParticleChargedFullBeamTrailOam_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20c4
};

static const u16 sParticleChargedPlasmaBeamTrailOam_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x2086
};

const struct FrameData sPlasmaBeamOam_Horizontal_NoWave[3] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Horizontal_NoWave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Horizontal_NoWave_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Diagonal_NoWave[3] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Diagonal_NoWave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Diagonal_NoWave_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Vertical_NoWave[3] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Vertical_NoWave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Vertical_NoWave_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Horizontal_NoWave_Unused[3] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame6,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Diagonal_NoWave_Unused[3] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame6,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Vertical_NoWave_Unused[3] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame6,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPlasmaBeamOam_Horizontal_NoWave[3] = {
    [0] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_NoWave_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_NoWave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPlasmaBeamOam_Diagonal_NoWave[3] = {
    [0] = {
        .pFrame = sChargedPlasmaBeamOam_Diagonal_NoWave_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedPlasmaBeamOam_Diagonal_NoWave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPlasmaBeamOam_Vertical_NoWave[3] = {
    [0] = {
        .pFrame = sChargedPlasmaBeamOam_Vertical_NoWave_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedPlasmaBeamOam_Vertical_NoWave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Horizontal_Wave[8] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Horizontal_NoWave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Diagonal_Wave[8] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Diagonal_NoWave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Vertical_Wave[8] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Vertical_NoWave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Horizontal_Wave_Unused[6] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Diagonal_Wave_Unused[6] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Vertical_Wave_Unused[6] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPlasmaBeamOam_Horizontal_Wave[8] = {
    [0] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPlasmaBeamOam_Diagonal_Wave[8] = {
    [0] = {
        .pFrame = sChargedPlasmaBeamOam_Diagonal_Wave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sChargedPlasmaBeamOam_Diagonal_Wave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sChargedPlasmaBeamOam_Diagonal_Wave_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sChargedPlasmaBeamOam_Diagonal_Wave_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sChargedPlasmaBeamOam_Diagonal_Wave_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPlasmaBeamOam_Vertical_Wave[8] = {
    [0] = {
        .pFrame = sChargedPlasmaBeamOam_Vertical_Wave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sChargedPlasmaBeamOam_Vertical_Wave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sChargedPlasmaBeamOam_Vertical_Wave_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sChargedPlasmaBeamOam_Vertical_Wave_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sChargedPlasmaBeamOam_Vertical_Wave_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleChargedPlasmaBeamTrailOam[5] = {
    [0] = {
        .pFrame = sParticleChargedPlasmaBeamTrailOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleChargedPlasmaBeamTrailOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleChargedPlasmaBeamTrailOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleChargedPlasmaBeamTrailOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleChargedFullBeamTrailOam[9] = {
    [0] = {
        .pFrame = sParticleChargedPlasmaBeamTrailOam_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sParticleChargedFullBeamTrailOam_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = {
        .pFrame = sParticleChargedPlasmaBeamTrailOam_Frame2,
        .timer = CONVERT_SECONDS(.05f)
    },
    [3] = {
        .pFrame = sParticleChargedFullBeamTrailOam_Frame3,
        .timer = CONVERT_SECONDS(.05f)
    },
    [4] = {
        .pFrame = sParticleChargedPlasmaBeamTrailOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sParticleChargedFullBeamTrailOam_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sParticleChargedFullBeamTrailOam_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sParticleChargedPlasmaBeamTrailOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const u8 sPistolGfx_Top[512] = INCBIN_U8("data/weapons/PistolTop.gfx");
const u8 sPistolGfx_Bottom[512] = INCBIN_U8("data/weapons/PistolBottom.gfx");
const u8 sPistolGfx_Charged_Top[512] = INCBIN_U8("data/weapons/PistolChargedTop.gfx");
const u8 sPistolGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/PistolChargedBottom.gfx");

static const u16 sPistolOam_Horizontal_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fa, 0x2080
};

static const u16 sPistolOam_Horizontal_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fa, 0x20a0
};

static const u16 sPistolOam_Diagonal_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x2082
};

static const u16 sPistolOam_Diagonal_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x2084
};

static const u16 sPitsolOam_Vertical_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1fc, 0x2086
};

static const u16 sPitsolOam_Vertical_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1fc, 0x2087
};

static const u16 sChargedPistolOam_Horizontal_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1fa, 0x20c0,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, 0x20c2
};

static const u16 sChargedPistolOam_Horizontal_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20c2,
    0xf8, OBJ_SIZE_16x16 | 0x1, 0x20c0,
    0xf8, OBJ_SIZE_16x16 | 0x9, 0x20c2
};

static const u16 sChargedPistolOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xfb, OBJ_SIZE_16x16 | 0x1fb, 0x20c4,
    0xfe, OBJ_SIZE_16x16 | 0x1fe, 0x20c6
};

static const u16 sChargedPistolOam_Diagonal_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfa, OBJ_SIZE_16x16 | 0x1fa, 0x20c6,
    0xff, OBJ_SIZE_16x16 | 0x1ff, 0x20c4,
    0x4, OBJ_SIZE_16x16 | 0x4, 0x20c6
};

static const u16 sChargedPistolOam_Vertical_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xfa, OBJ_SIZE_16x16 | 0x1f8, 0x20c8,
    0xff, OBJ_SIZE_16x16 | 0x1f8, 0x20ca
};

static const u16 sChargedPistolOam_Vertical_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20ca,
    0x1, OBJ_SIZE_16x16 | 0x1f8, 0x20c8,
    0x9, OBJ_SIZE_16x16 | 0x1f8, 0x20ca
};

static const u16 sParticleChargedPistolTrailOam_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20ce
};

static const u16 sParticleChargedPistolTrailOam_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20cf
};

static const u16 sParticleChargedPistolTrailOam_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20ee
};

static const u16 sParticleChargedPistolTrailOam_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x20ef
};

const struct FrameData sPistolOam_Horizontal[3] = {
    [0] = {
        .pFrame = sPistolOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPistolOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPistolOam_Diagonal[3] = {
    [0] = {
        .pFrame = sPistolOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPistolOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPistolOam_Vertical[3] = {
    [0] = {
        .pFrame = sPitsolOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPitsolOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPistolOam_Horizontal[3] = {
    [0] = {
        .pFrame = sChargedPistolOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedPistolOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPistolOam_Diagonal[3] = {
    [0] = {
        .pFrame = sChargedPistolOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedPistolOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPistolOam_Vertical[3] = {
    [0] = {
        .pFrame = sChargedPistolOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedPistolOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleChargedPistolTrailOam[5] = {
    [0] = {
        .pFrame = sParticleChargedPistolTrailOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleChargedPistolTrailOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleChargedPistolTrailOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleChargedPistolTrailOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleEscapeOam_Unused[2] = {
    [0] = {
        .pFrame = gParticleEscapeOamFrames,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSamusReflectionOam_Unused[2] = {
    [0] = {
        .pFrame = gParticleSamusReflectionOamFrames,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
