#include "data/projectile_data.h"
#include "structs/particle.h"
#include "macros.h"

// 326ca8

const s16 sTumblingMissileSpeed[16] = {
    -12, -10, -8, -6, -4, -2, 0, 0, 1, 2, 4, 8, 12, 16, 20, SHORT_MAX
};

const u8 sProjectile_Array326cc8_Unused[64] = {
    24, 0, 16, 0, 8, 0, 4, 0, 4, 0, 8, 0, 16, 0, 24, 0,
    32, 0, 20, 0, 8, 0, 4, 0, 4, 0, 8, 0, 20, 0, 32, 0,
    24, 0, 20, 0, 16, 0, 12, 0, 12, 0, 8, 0, 4, 0, 0, 0,
    0, 0, 4, 0, 8, 0, 12, 0, 12, 0, 16, 0, 20, 0, 24, 0
};

const u16 sBombOAM_Frame0[4] = {
    0x1,
    0xf8, 0x1fc, 0x414d
};

const u16 sBombOAM_Frame1[4] = {
    0x1,
    0xf8, 0x1fc, 0x414e
};

const u16 sBombOAM_Frame2[4] = {
    0x1,
    0xf8, 0x1fc, 0x414f
};

const u16 sBombOAM_Frame3[4] = {
    0x1,
    0xf8, 0x1fc, 0x4150
};

const u16 sPowerBombOAM_Frame0[4] = {
    0x1,
    0xf8, 0x1fc, 0x414b
};

const u16 sPowerBombOAM_Frame1[4] = {
    0x1,
    0xf8, 0x1fc, 0x414c
};

const u16 sPowerBombOAM_Frame2[4] = {
    0x1,
    0xf8, 0x1fc, 0x416b
};

const struct FrameData sBombOAM_Slow[5] = {
    sBombOAM_Frame0,
    0x6,
    sBombOAM_Frame1,
    0x6,
    sBombOAM_Frame2,
    0x6,
    sBombOAM_Frame3,
    0x6,
    NULL,
    0x0
};

const struct FrameData sBombOAM_Fast[5] = {
    sBombOAM_Frame0,
    0x2,
    sBombOAM_Frame1,
    0x2,
    sBombOAM_Frame2,
    0x2,
    sBombOAM_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sPowerBombOAM_Slow[4] = {
    sPowerBombOAM_Frame0,
    0x6,
    sPowerBombOAM_Frame1,
    0x6,
    sPowerBombOAM_Frame2,
    0x6,
    NULL,
    0x0
};

const struct FrameData sPowerBombOAM_Fast[4] = {
    sPowerBombOAM_Frame0,
    0x3,
    sPowerBombOAM_Frame1,
    0x3,
    sPowerBombOAM_Frame2,
    0x3,
    NULL,
    0x0
};

const u16 sMissileOAM_Horizontal_Frame0[7] = {
    0x2,
    0xfc, 0x3, 0x30d0,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, 0x4078
};

const u16 sMissileOAM_Horizontal_Frame1[7] = {
    0x2,
    0xfc, 0x7, 0x30d1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, 0x4078
};

const u16 sMissileOAM_Diagonal_Frame0[7] = {
    0x2,
    0x1, 0x1, 0x30d0,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x405c
};

const u16 sMissileOAM_Diagonal_Frame1[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x405c,
    0x3, 0x3, 0x30f0,
};

const u16 sMissileOAM_Vertical_Frame0[7] = {
    0x2,
    0x3, 0x1fc, 0x30d0,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4185
};

const u16 sMissileOAM_Vertical_Frame1[7] = {
    0x2,
    0x7, 0x1fc, 0x30f1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4185
};

const u16 sSuperMissileOAM_Horizontal_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x2, 0x30d3,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, 0x407a
};

const u16 sSuperMissileOAM_Horizontal_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, 0x407a,
    0xfc, 0x5, 0x30d1
};

const u16 sSuperMissileOAM_Diagonal_Frame0[7] = {
    0x2,
    0xff, OBJ_SIZE_16x16 | 0x1ff, 0x30d3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x405e
};

const u16 sSuperMissileOAM_Diagonal_Frame1[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x405e,
    0x3, 0x3, 0x30f0
};

const u16 sSuperMissileOAM_Vertical_Frame0[7] = {
    0x2,
    0x1, OBJ_SIZE_16x16 | 0x1f8, 0x30d3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4186
};

const u16 sSuperMissileOAM_Vertical_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4186,
    0x5, 0x1fc, 0x30f1
};

const u16 sMissileOAM_Tumbling_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, 0x4078
};

const u16 sMissileOAM_Tumbling_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x405c
};

const u16 sMissileOAM_Tumbling_Frame2[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4185
};

const u16 sMissileOAM_Tumbling_Frame3[4] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x405c
};

const u16 sMissileOAM_Tumbling_Frame4[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1f8, 0x4078
};

const u16 sMissileOAM_Tumbling_Frame5[4] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x405c
};

const u16 sMissileOAM_Tumbling_Frame6[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_Y_FLIP | 0x1fc, 0x4185
};

const u16 sMissileOAM_Tumbling_Frame7[4] = {
    0x1,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x405c
};

const u16 sSuperMissileOAM_Tumbling_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, 0x407a
};

const u16 sSuperMissileOAM_Tumbling_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x405e
};

const u16 sSuperMissileOAM_Tumbling_Frame2[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4186
};

const u16 sSuperMissileOAM_Tumbling_Frame3[4] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x405e
};

const u16 sSuperMissileOAM_Tumbling_Frame4[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1f8, 0x407a
};

const u16 sSuperMissileOAM_Tumbling_Frame5[4] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x405e
};

const u16 sSuperMissileOAM_Tumbling_Frame6[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_Y_FLIP | 0x1fc, 0x4186
};

const u16 sSuperMissileOAM_Tumbling_Frame7[4] = {
    0x1,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x405e
};

const u16 sParticleMissileTrailOam_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x30d5
};

const u16 sParticleMissileTrailOam_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, 0x30f5
};

const u16 sParticleMissileTrailOam_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, 0x30f6
};

const u16 sParticleSuperMissileTrailOam_Frame3[4] = {
    0x1,
    0xfc, 0x1fc, 0x4159
};

const u16 sParticleMissileTrailOam_Frame3[4] = {
    0x1,
    0xf9, 0x1fc, 0x415a
};

const u16 sParticleMissileTrailOam_Frame4[4] = {
    0x1,
    0xf7, 0x1fc, 0x415b
};

const u16 sParticleMissileTrailOam_Frame5[4] = {
    0x1,
    0xf3, 0x1fc, 0x415c
};

const u16 sParticleMissileTrailOam_Frame6[4] = {
    0x1,
    0xf1, 0x1fc, 0x415d
};

const u16 sParticleSuperMissileTrailOam_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x30d0
};

const struct FrameData sMissileOAM_Horizontal[3] = {
    sMissileOAM_Horizontal_Frame0,
    0x2,
    sMissileOAM_Horizontal_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sMissileOAM_Diagonal[3] = {
    sMissileOAM_Diagonal_Frame0,
    0x2,
    sMissileOAM_Diagonal_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sMissileOAM_Vertical[3] = {
    sMissileOAM_Vertical_Frame0,
    0x2,
    sMissileOAM_Vertical_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sSuperMissileOAM_Horizontal[3] = {
    sSuperMissileOAM_Horizontal_Frame0,
    0x2,
    sSuperMissileOAM_Horizontal_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sSuperMissileOAM_Diagonal[3] = {
    sSuperMissileOAM_Diagonal_Frame0,
    0x2,
    sSuperMissileOAM_Diagonal_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sSuperMissileOAM_Vertical[3] = {
    sSuperMissileOAM_Vertical_Frame0,
    0x2,
    sSuperMissileOAM_Vertical_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sMissileOAM_Tumbling[9] = {
    sMissileOAM_Tumbling_Frame0,
    0x3,
    sMissileOAM_Tumbling_Frame1,
    0x3,
    sMissileOAM_Tumbling_Frame2,
    0x3,
    sMissileOAM_Tumbling_Frame3,
    0x3,
    sMissileOAM_Tumbling_Frame4,
    0x3,
    sMissileOAM_Tumbling_Frame5,
    0x3,
    sMissileOAM_Tumbling_Frame6,
    0x3,
    sMissileOAM_Tumbling_Frame7,
    0x3,
    NULL,
    0x0
};

const struct FrameData sSuperMissileOAM_Tumbling[9] = {
    sSuperMissileOAM_Tumbling_Frame0,
    0x3,
    sSuperMissileOAM_Tumbling_Frame1,
    0x3,
    sSuperMissileOAM_Tumbling_Frame2,
    0x3,
    sSuperMissileOAM_Tumbling_Frame3,
    0x3,
    sSuperMissileOAM_Tumbling_Frame4,
    0x3,
    sSuperMissileOAM_Tumbling_Frame5,
    0x3,
    sSuperMissileOAM_Tumbling_Frame6,
    0x3,
    sSuperMissileOAM_Tumbling_Frame7,
    0x3,
    NULL,
    0x0
};

const struct FrameData sParticleMissileTrailOam[8] = {
    sParticleMissileTrailOam_Frame0,
    0x4,
    sParticleMissileTrailOam_Frame1,
    0x4,
    sParticleMissileTrailOam_Frame2,
    0x4,
    sParticleMissileTrailOam_Frame3,
    0x3,
    sParticleMissileTrailOam_Frame4,
    0x3,
    sParticleMissileTrailOam_Frame5,
    0x3,
    sParticleMissileTrailOam_Frame6,
    0x3,
    NULL,
    0x0
};

const struct FrameData sParticleSuperMissileTrailOam[9] = {
    sParticleSuperMissileTrailOam_Frame0,
    0x4,
    sParticleMissileTrailOam_Frame1,
    0x4,
    sParticleMissileTrailOam_Frame2,
    0x4,
    sParticleSuperMissileTrailOam_Frame3,
    0x3,
    sParticleMissileTrailOam_Frame3,
    0x3,
    sParticleMissileTrailOam_Frame4,
    0x3,
    sParticleMissileTrailOam_Frame5,
    0x3,
    sParticleMissileTrailOam_Frame6,
    0x3,
    NULL,
    0x0
};

const u16 sBeamPAL[96] = INCBIN_U16("data/weapons/Beams.pal");

const u8 sNormalBeamGfx_Top[512] = INCBIN_U8("data/weapons/NormalBeamTop.gfx");
const u8 sNormalBeamGfx_Bottom[512] = INCBIN_U8("data/weapons/NormalBeamBottom.gfx");
const u8 sNormalBeamGfx_Charged_Top[512] = INCBIN_U8("data/weapons/NormalBeamChargedTop.gfx");
const u8 sNormalBeamGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/NormalBeamChargedBottom.gfx");

const u16 sNormalBeamOAM_Horizontal_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fa, 0x2080
};

const u16 sNormalBeamOAM_Horizontal_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fa, 0x20a0
};

const u16 sNormalBeamOAM_Diagonal_Frame0[4] = {
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x2082
};

const u16 sNormalBeamOAM_Diagonal_Frame1[4] = {
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x2084
};

const u16 sNormalBeamOAM_Vertical_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1fc, 0x2086
};

const u16 sNormalBeamOAM_Vertical_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1fc, 0x2087
};

const u16 sNormalBeamOAM_Horizontal_Unused_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x20a8
};

const u16 sNormalBeamOAM_Horizontal_Unused_Frame1[4] = {
    0x1,
    0xfc, 0x1fd, 0x20a8
};

const u16 sNormalBeamOAM_Diagonal_Unused_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x20a9
};

const u16 sNormalBeamOAM_Diagonal_Unused_Frame1[4] = {
    0x1,
    0xfd, 0x1fd, 0x20a9
};

const u16 sNormalBeamOAM_Vertical_Unused_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x20aa
};

const u16 sNormalBeamOAM_Vertical_Unused_Frame1[4] = {
    0x1,
    0xfd, 0x1fc, 0x20aa
};

const u16 sChargedNormalBeamOAM_Horizontal_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1fa, 0x20c0,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, 0x20c2
};

const u16 sChargedNormalBeamOAM_Horizontal_Frame1[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20c2,
    0xf8, OBJ_SIZE_16x16 | 0x1, 0x20c0,
    0xf8, OBJ_SIZE_16x16 | 0x9, 0x20c2
};

const u16 sChargedNormalBeamOAM_Diagonal_Frame0[7] = {
    0x2,
    0xfb, OBJ_SIZE_16x16 | 0x1fb, 0x20c4,
    0xfe, OBJ_SIZE_16x16 | 0x1fe, 0x20c6
};

const u16 sChargedNormalBeamOAM_Diagonal_Frame1[10] = {
    0x3,
    0xfa, OBJ_SIZE_16x16 | 0x1fa, 0x20c6,
    0xff, OBJ_SIZE_16x16 | 0x1ff, 0x20c4,
    0x4, OBJ_SIZE_16x16 | 0x4, 0x20c6
};

const u16 sChargedNormalBeamOAM_Vertical_Frame0[7] = {
    0x2,
    0xfa, OBJ_SIZE_16x16 | 0x1f8, 0x20c8,
    0xff, OBJ_SIZE_16x16 | 0x1f8, 0x20ca
};

const u16 sChargedNormalBeamOAM_Vertical_Frame1[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20ca,
    0x1, OBJ_SIZE_16x16 | 0x1f8, 0x20c8,
    0x9, OBJ_SIZE_16x16 | 0x1f8, 0x20ca
};

const u16 sChargedNormalBeamOAM_Horizontal_Unused_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x20ce
};

const u16 sChargedNormalBeamOAM_Horizontal_Unused_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, 0x20cf
};

const u16 sChargedNormalBeamOAM_Horizontal_Unused_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, 0x20ee
};

const u16 sChargedNormalBeamOAM_Horizontal_Unused_Frame3[4] = {
    0x1,
    0xfc, 0x1fc, 0x20ef
};

const struct FrameData sNormalBeamOAM_Horizontal[3] = {
    sNormalBeamOAM_Horizontal_Frame0,
    0x3,
    sNormalBeamOAM_Horizontal_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sNormalBeamOAM_Diagonal[3] = {
    sNormalBeamOAM_Diagonal_Frame0,
    0x3,
    sNormalBeamOAM_Diagonal_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sNormalBeamOAM_Vertical[3] = {
    sNormalBeamOAM_Vertical_Frame0,
    0x3,
    sNormalBeamOAM_Vertical_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sNormalBeamOAM_Horizontal_Unused[3] = {
    sNormalBeamOAM_Horizontal_Unused_Frame0,
    0x3,
    sNormalBeamOAM_Horizontal_Unused_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sNormalBeamOAM_Diagonal_Unused[3] = {
    sNormalBeamOAM_Diagonal_Unused_Frame0,
    0x3,
    sNormalBeamOAM_Diagonal_Unused_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sNormalBeamOAM_Vertical_Unused[3] = {
    sNormalBeamOAM_Vertical_Unused_Frame0,
    0x3,
    sNormalBeamOAM_Vertical_Unused_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sChargedNormalBeamOAM_Horizontal[3] = {
    sChargedNormalBeamOAM_Horizontal_Frame0,
    0x2,
    sChargedNormalBeamOAM_Horizontal_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sChargedNormalBeamOAM_Diagonal[3] = {
    sChargedNormalBeamOAM_Diagonal_Frame0,
    0x2,
    sChargedNormalBeamOAM_Diagonal_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sChargedNormalBeamOAM_Vertical[3] = {
    sChargedNormalBeamOAM_Vertical_Frame0,
    0x2,
    sChargedNormalBeamOAM_Vertical_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sChargedNormalBeamOAM_Horizontal_Unused[5] = {
    sChargedNormalBeamOAM_Horizontal_Unused_Frame0,
    0x4,
    sChargedNormalBeamOAM_Horizontal_Unused_Frame1,
    0x4,
    sChargedNormalBeamOAM_Horizontal_Unused_Frame2,
    0x4,
    sChargedNormalBeamOAM_Horizontal_Unused_Frame3,
    0x4,
    NULL,
    0x0
};

const u8 sLongBeamGfx_Top[512] = INCBIN_U8("data/weapons/LongBeamTop.gfx");
const u8 sLongBeamGfx_Bottom[512] = INCBIN_U8("data/weapons/LongBeamBottom.gfx");
const u8 sLongBeamGfx_Charged_Top[512] = INCBIN_U8("data/weapons/LongBeamChargedTop.gfx");
const u8 sLongBeamGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/LongBeamChargedBottom.gfx");

const u16 sLongBeamOAM_Horizontal_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fc, 0x2080
};

const u16 sLongBeamOAM_Horizontal_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fc, 0x20a0
};

const u16 sLongBeamOAM_Diagonal_Frame0[4] = {
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x20c0
};

const u16 sLongBeamOAM_Diagonal_Frame1[4] = {
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x20c2
};

const u16 sLongBeamOAM_Vertical_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1fc, 0x2082
};

const u16 sLongBeamOAM_Vertical_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1fc, 0x2083
};

const u16 sChargedLongBeamOAM_Horizontal_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1fa, 0x2086,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1, 0x20c6
};

const u16 sChargedLongBeamOAM_Horizontal_Frame1[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f8, 0x20c6,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x2, 0x2086,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0xb, 0x20c6
};

const u16 sChargedLongBeamOAM_Diagonal_Frame0[7] = {
    0x2,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x2084,
    0x2, OBJ_SIZE_16x16 | 0x2, 0x20c4
};

const u16 sChargedLongBeamOAM_Diagonal_Frame1[10] = {
    0x3,
    0xfb, OBJ_SIZE_16x16 | 0x1fb, 0x20c4,
    0x1, OBJ_SIZE_16x16 | 0x1, 0x2084,
    0x8, OBJ_SIZE_16x16 | 0x8, 0x20c4
};

const u16 sChargedLongBeamOAM_Vertical_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xfa, OBJ_SIZE_16x32 | 0x1f8, 0x208a,
    OBJ_SHAPE_VERTICAL | 0x1, OBJ_SIZE_16x32 | 0x1f8, 0x208c
};

const u16 sChargedLongBeamOAM_Vertical_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x1f8, 0x208c,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_SIZE_16x32 | 0x1f8, 0x208a,
    OBJ_SHAPE_VERTICAL | 0xb, OBJ_SIZE_16x32 | 0x1f8, 0x208c
};

const u16 sParticleChargedLongBeamTrailOam_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x20ce
};

const u16 sParticleChargedLongBeamTrailOam_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x208e
};

const u16 sParticleChargedLongBeamTrailOam_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, 0x20cf
};

const u16 sParticleChargedLongBeamTrailOam_Frame3[4] = {
    0x1,
    0xfc, 0x1fc, 0x20ef
};

const struct FrameData sLongBeamOAM_Horizontal[3] = {
    sLongBeamOAM_Horizontal_Frame0,
    0x3,
    sLongBeamOAM_Horizontal_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sLongBeamOAM_Diagonal[3] = {
    sLongBeamOAM_Diagonal_Frame0,
    0x3,
    sLongBeamOAM_Diagonal_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sLongBeamOAM_Vertical[3] = {
    sLongBeamOAM_Vertical_Frame0,
    0x3,
    sLongBeamOAM_Vertical_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sChargedLongBeamOAM_Horizontal[3] = {
    sChargedLongBeamOAM_Horizontal_Frame0,
    0x2,
    sChargedLongBeamOAM_Horizontal_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sChargedLongBeamOAM_Diagonal[3] = {
    sChargedLongBeamOAM_Diagonal_Frame0,
    0x2,
    sChargedLongBeamOAM_Diagonal_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sChargedLongBeamOAM_Vertical[3] = {
    sChargedLongBeamOAM_Vertical_Frame0,
    0x2,
    sChargedLongBeamOAM_Vertical_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sParticleChargedLongBeamTrailOam[5] = {
    sParticleChargedLongBeamTrailOam_Frame0,
    0x4,
    sParticleChargedLongBeamTrailOam_Frame1,
    0x4,
    sParticleChargedLongBeamTrailOam_Frame2,
    0x4,
    sParticleChargedLongBeamTrailOam_Frame3,
    0x4,
    NULL,
    0x0
};

const u8 sIceBeamGfx_Top[512] = INCBIN_U8("data/weapons/IceBeamTop.gfx");
const u8 sIceBeamGfx_Bottom[512] = INCBIN_U8("data/weapons/IceBeamBottom.gfx");
const u8 sIceBeamGfx_Charged_Top[512] = INCBIN_U8("data/weapons/IceBeamChargedTop.gfx");
const u8 sIceBeamGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/IceBeamChargedBottom.gfx");

const u16 sIceBeamOAM_Horizontal_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1fb, 0x2080
};

const u16 sIceBeamOAM_Horizontal_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1fc, 0x2082
};

const u16 sIceBeamOAM_Diagonal_Frame0[4] = {
    0x1,
    0xfa, OBJ_SIZE_16x16 | 0x1f9, 0x2084
};

const u16 sIceBeamOAM_Diagonal_Frame1[4] = {
    0x1,
    0xfb, OBJ_SIZE_16x16 | 0x1fa, 0x2086
};

const u16 sIceBeamOAM_Vertical_Frame0[4] = {
    0x1,
    0xfb, OBJ_SIZE_16x16 | 0x1f8, 0x2088
};

const u16 sIceBeamOAM_Vertical_Frame1[4] = {
    0x1,
    0xfc, OBJ_SIZE_16x16 | 0x1f8, 0x208a
};

const u16 sIceBeamOAM_Horizontal_Unused_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x208c
};

const u16 sIceBeamOAM_Horizontal_Unused_Frame1[4] = {
    0x1,
    0xfc, 0x1fd, 0x208c
};

const u16 sIceBeamOAM_Diagonal_Unused_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x208d
};

const u16 sIceBeamOAM_Diagonal_Unused_Frame1[4] = {
    0x1,
    0xfd, 0x1fd, 0x208d
};

const u16 sIceBeamOAM_Vertical_Unused_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x208e
};

const u16 sIceBeamOAM_Vertical_Unused_Frame1[4] = {
    0x1,
    0xfd, 0x1fc, 0x208e
};

const u16 sChargedIceBeamOAM_Horizontal_Frame0[13] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1fa, 0x20c0,
    0xfc, 0xa, 0x20c2,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, 0x20c3,
    0xfc, 0xf, 0x20e2
};

const u16 sChargedIceBeamOAM_Horizontal_Frame1[19] = {
    0x6,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20c3,
    0xfc, 0x8, 0x20e2,
    0xf8, OBJ_SIZE_16x16 | 0x1, 0x20c0,
    0xfc, 0x11, 0x20c2,
    0xf8, OBJ_SIZE_16x16 | 0xa, 0x20c3,
    0xfc, 0x1a, 0x20e2
};

const u16 sChargedIceBeamOAM_Diagonal_Frame0[7] = {
    0x2,
    0xfb, OBJ_SIZE_16x16 | 0x1fb, 0x20c5,
    0xff, OBJ_SIZE_16x16 | 0x1ff, 0x20c7
};

const u16 sChargedIceBeamOAM_Diagonal_Frame1[10] = {
    0x3,
    0xfa, OBJ_SIZE_16x16 | 0x1fa, 0x20c7,
    0xfe, OBJ_SIZE_16x16 | 0x1fe, 0x20c5,
    0x4, OBJ_SIZE_16x16 | 0x4, 0x20c7
};

const u16 sChargedIceBeamOAM_Vertical_Frame0[13] = {
    0x4,
    0xfa, OBJ_SIZE_16x16 | 0x1f8, 0x20c9,
    0xa, 0x1fc, 0x20cb,
    0xff, OBJ_SIZE_16x16 | 0x1f8, 0x20cc,
    0xf, 0x1fc, 0x20eb
};

const u16 sChargedIceBeamOAM_Vertical_Frame1[19] = {
    0x6,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20cc,
    0x8, 0x1fc, 0x20eb,
    0x1, OBJ_SIZE_16x16 | 0x1f8, 0x20c9,
    0x11, 0x1fc, 0x20cb,
    0xa, OBJ_SIZE_16x16 | 0x1f8, 0x20cc,
    0x1a, 0x1fc, 0x20eb
};

const u16 sParticleChargedIceBeamTrailOam_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x208c
};

const u16 sParticleChargedIceBeamTrailOam_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20ce
};

const u16 sParticleChargedIceBeamTrailOam_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, 0x20ae
};

const u16 sParticleChargedIceBeamTrailOam_Frame3[4] = {
    0x1,
    0xfc, 0x1fc, 0x20af
};

const u16 sParticleChargedIceBeamTrailOam_Frame4[4] = {
    0x1,
    0xfc, 0x1fc, 0x208f
};

const struct FrameData sIceBeamOAM_Horizontal[3] = {
    sIceBeamOAM_Horizontal_Frame0,
    0x3,
    sIceBeamOAM_Horizontal_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sIceBeamOAM_Diagonal[3] = {
    sIceBeamOAM_Diagonal_Frame0,
    0x3,
    sIceBeamOAM_Diagonal_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sIceBeamOAM_Vertical[3] = {
    sIceBeamOAM_Vertical_Frame0,
    0x3,
    sIceBeamOAM_Vertical_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sIceBeamOAM_Horizontal_Unused[3] = {
    sIceBeamOAM_Horizontal_Unused_Frame0,
    0x3,
    sIceBeamOAM_Horizontal_Unused_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sIceBeamOAM_Diagonal_Unused[3] = {
    sIceBeamOAM_Diagonal_Unused_Frame0,
    0x3,
    sIceBeamOAM_Diagonal_Unused_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sIceBeamOAM_Vertical_Unused[3] = {
    sIceBeamOAM_Vertical_Unused_Frame0,
    0x3,
    sIceBeamOAM_Vertical_Unused_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sChargedIceBeamOAM_Horizontal[3] = {
    sChargedIceBeamOAM_Horizontal_Frame0,
    0x2,
    sChargedIceBeamOAM_Horizontal_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sChargedIceBeamOAM_Diagonal[3] = {
    sChargedIceBeamOAM_Diagonal_Frame0,
    0x2,
    sChargedIceBeamOAM_Diagonal_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sChargedIceBeamOAM_Vertical[3] = {
    sChargedIceBeamOAM_Vertical_Frame0,
    0x2,
    sChargedIceBeamOAM_Vertical_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sParticleChargedIceBeamTrailOam[6] = {
    sParticleChargedIceBeamTrailOam_Frame0,
    0x4,
    sParticleChargedIceBeamTrailOam_Frame1,
    0x4,
    sParticleChargedIceBeamTrailOam_Frame2,
    0x4,
    sParticleChargedIceBeamTrailOam_Frame3,
    0x4,
    sParticleChargedIceBeamTrailOam_Frame4,
    0x4,
    NULL,
    0x0
};

const u8 sWaveBeamGfx_Top[512] = INCBIN_U8("data/weapons/WaveBeamTop.gfx");
const u8 sWaveBeamGfx_Bottom[512] = INCBIN_U8("data/weapons/WaveBeamBottom.gfx");
const u8 sWaveBeamGfx_Charged_Top[512] = INCBIN_U8("data/weapons/WaveBeamChargedTop.gfx");
const u8 sWaveBeamGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/WaveBeamChargedBottom.gfx");

const u16 sWaveBeamOAM_Horizontal_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fb, 0x2080
};

const u16 sWaveBeamOAM_Horizontal_Frame1[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x5, 0x20a0
};

const u16 sWaveBeamOAM_Horizontal_Frame2[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0xd, 0x20a0
};

const u16 sWaveBeamOAM_Horizontal_Frame3[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1fb, 0x2080
};

const u16 sWaveBeamOAM_Horizontal_Frame4[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0x5, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xef, 0x1fb, 0x20a0,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1fb, 0x20a0
};

const u16 sWaveBeamOAM_Horizontal_Frame5[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xf2, 0x1fb, 0x20a0,
    OBJ_SHAPE_HORIZONTAL | 0x6, 0x1fb, 0x20a0
};

const u16 sWaveBeamOAM_Horizontal_Frame6[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fb, 0x2080,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1fb, 0x20a0,
    OBJ_SHAPE_HORIZONTAL | 0x2, 0x1fb, 0x20a0
};

const u16 sWaveBeamOAM_Diagonal_Frame0[4] = {
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x20c0
};

const u16 sWaveBeamOAM_Diagonal_Frame1[10] = {
    0x3,
    0xf6, OBJ_SIZE_16x16 | 0x1fd, 0x20c0,
    0xfc, OBJ_SIZE_16x16 | 0x1f6, 0x20c0,
    0x0, OBJ_SIZE_16x16 | 0x1, 0x20c2
};

const u16 sWaveBeamOAM_Diagonal_Frame2[10] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1ff, 0x20c0,
    0xfe, OBJ_SIZE_16x16 | 0x1f4, 0x20c0,
    0x5, OBJ_SIZE_16x16 | 0x5, 0x20c2
};

const u16 sWaveBeamOAM_Diagonal_Frame3[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x2, 0x20c0,
    0x1, OBJ_SIZE_16x16 | 0x1f1, 0x20c0
};

const u16 sWaveBeamOAM_Diagonal_Frame4[13] = {
    0x4,
    0xf2, OBJ_SIZE_16x16 | 0x1ff, 0x20c0,
    0xff, OBJ_SIZE_16x16 | 0x1f3, 0x20c0,
    0xef, OBJ_SIZE_16x16 | 0x3, 0x20c2,
    0x2, OBJ_SIZE_16x16 | 0x1f0, 0x20c2
};

const u16 sWaveBeamOAM_Diagonal_Frame5[13] = {
    0x4,
    0xf6, OBJ_SIZE_16x16 | 0x1fc, 0x20c0,
    0xfb, OBJ_SIZE_16x16 | 0x1f7, 0x20c0,
    0xf2, OBJ_SIZE_16x16 | 0x1, 0x20c2,
    0x0, OBJ_SIZE_16x16 | 0x1f3, 0x20c2
};

const u16 sWaveBeamOAM_Diagonal_Frame6[10] = {
    0x3,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x20c0,
    0xf4, OBJ_SIZE_16x16 | 0x1fe, 0x20c2,
    0xfe, OBJ_SIZE_16x16 | 0x1f4, 0x20c2
};

const u16 sWaveBeamOAM_Vertical_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1fc, 0x2082
};

const u16 sWaveBeamOAM_Vertical_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x0, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1f8, 0x2082,
    OBJ_SHAPE_VERTICAL | 0x5, 0x1fc, 0x20c6
};

const u16 sWaveBeamOAM_Vertical_Frame2[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x4, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1f4, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xd, 0x1fc, 0x20c6
};

const u16 sWaveBeamOAM_Vertical_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x8, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1f0, 0x2082
};

const u16 sWaveBeamOAM_Vertical_Frame4[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x5, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1f3, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x9, 0x20c6,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1ef, 0x20c6
};

const u16 sWaveBeamOAM_Vertical_Frame5[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x0, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1f8, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x6, 0x20c6,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1f2, 0x20c6
};

const u16 sWaveBeamOAM_Vertical_Frame6[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1fc, 0x2082,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x2, 0x20c6,
    OBJ_SHAPE_VERTICAL | 0xfb, 0x1f6, 0x20c6
};

const u16 sWaveBeamOAM_Horizontal_Unused_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, 0x20ee
};

const u16 sWaveBeamOAM_Horizontal_Unused_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, 0x20ee
};

const u16 sWaveBeamOAM_Horizontal_Unused_Frame2[13] = {
    0x4,
    0x1, 0x1fd, 0x2084,
    0xf7, 0x1fd, 0x2084,
    0xfc, 0x9, 0x2085,
    0xfc, 0x1fa, 0x2084
};

const u16 sWaveBeamOAM_Horizontal_Unused_Frame3[13] = {
    0x4,
    0x5, 0x0, 0x2084,
    0xf3, 0x0, 0x2084,
    0xf6, 0x1fd, 0x2084,
    0x2, 0x1fd, 0x2084
};

const u16 sWaveBeamOAM_Horizontal_Unused_Frame4[13] = {
    0x4,
    0x7, 0x4, 0x2084,
    0xf1, 0x4, 0x2084,
    0xf2, 0x0, 0x2084,
    0x6, 0x0, 0x2084
};

const u16 sWaveBeamOAM_Horizontal_Unused_Frame5[13] = {
    0x4,
    0xf3, 0xd, 0x2084,
    0x5, 0xd, 0x2084,
    0x7, 0x8, 0x2084,
    0xf1, 0x8, 0x2084
};

const u16 sWaveBeamOAM_Horizontal_Unused_Frame6[13] = {
    0x4,
    0xf5, 0x10, 0x2084,
    0x3, 0x10, 0x2084,
    0xf8, 0x13, 0x2085,
    0x0, 0x13, 0x2085
};

const u16 sWaveBeamOAM_Diagonal_Unused_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x20a4
};

const u16 sWaveBeamOAM_Diagonal_Unused_Frame1[10] = {
    0x3,
    0xfa, 0x1fc, 0x20a4,
    0xfc, 0x1fa, 0x20a4,
    0xff, 0x1ff, 0x20a5
};

const u16 sWaveBeamOAM_Diagonal_Unused_Frame2[13] = {
    0x4,
    0xf8, 0x1fd, 0x20a4,
    0xfd, 0x1f8, 0x20a4,
    0x1, 0x1, 0x20a5,
    0xf9, 0x1f9, 0x20a4
};

const u16 sWaveBeamOAM_Diagonal_Unused_Frame3[13] = {
    0x4,
    0xf8, 0x3, 0x20a4,
    0x3, 0x1f8, 0x20a4,
    0xf7, 0x1fe, 0x20a4,
    0xfe, 0x1f7, 0x20a4
};

const u16 sWaveBeamOAM_Diagonal_Unused_Frame4[13] = {
    0x4,
    0xf9, 0x7, 0x20a4,
    0x7, 0x1f9, 0x20a4,
    0xf6, 0x3, 0x20a4,
    0x3, 0x1f6, 0x20a4
};

const u16 sWaveBeamOAM_Diagonal_Unused_Frame5[13] = {
    0x4,
    0x1, 0xc, 0x20a4,
    0xc, 0x1, 0x20a4,
    0xfc, 0xa, 0x20a4,
    0xa, 0x1fc, 0x20a4
};

const u16 sWaveBeamOAM_Diagonal_Unused_Frame6[13] = {
    0x4,
    0x3, 0xe, 0x20a4,
    0xe, 0x3, 0x20a4,
    0xf, 0x8, 0x20a5,
    0x8, 0xf, 0x20a5
};

const u16 sWaveBeamOAM_Vertical_Unused_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x20c4
};

const u16 sWaveBeamOAM_Vertical_Unused_Frame1[10] = {
    0x3,
    0xfd, 0x1fe, 0x20c4,
    0xfd, 0x1fa, 0x20c4,
    0x3, 0x1fc, 0x20c5
};

const u16 sWaveBeamOAM_Vertical_Unused_Frame2[13] = {
    0x4,
    0xfd, 0x1, 0x20c4,
    0xfd, 0x1f7, 0x20c4,
    0x9, 0x1fc, 0x20c5,
    0xfa, 0x1fc, 0x20c4
};

const u16 sWaveBeamOAM_Vertical_Unused_Frame3[13] = {
    0x4,
    0x0, 0x5, 0x20c4,
    0x0, 0x1f3, 0x20c4,
    0xfd, 0x2, 0x20c4,
    0xfd, 0x1f6, 0x20c4
};

const u16 sWaveBeamOAM_Vertical_Unused_Frame4[13] = {
    0x4,
    0x4, 0x7, 0x20c4,
    0x4, 0x1f1, 0x20c4,
    0x0, 0x6, 0x20c4,
    0x0, 0x1f2, 0x20c4
};

const u16 sWaveBeamOAM_Vertical_Unused_Frame5[13] = {
    0x4,
    0xd, 0x5, 0x20c4,
    0xd, 0x1f3, 0x20c4,
    0x8, 0x7, 0x20c4,
    0x8, 0x1f1, 0x20c4
};

const u16 sWaveBeamOAM_Vertical_Unused_Frame6[13] = {
    0x4,
    0x10, 0x3, 0x20c4,
    0x10, 0x1f5, 0x20c4,
    0x13, 0x1f8, 0x20c5,
    0x13, 0x0, 0x20c5
};

const u16 sChargedWaveBeamOAM_Horizontal_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f9, 0x2083
};

const u16 sChargedWaveBeamOAM_Horizontal_Frame1[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f7, 0x2083,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f7, 0x2083,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x4, 0x2086
};

const u16 sChargedWaveBeamOAM_Horizontal_Frame2[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1f7, 0x2083,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1f7, 0x2083,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f3, 0x2083,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x10, 0x2086
};

const u16 sChargedWaveBeamOAM_Horizontal_Frame3[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_32x16 | 0x1fb, 0x2083,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x16 | 0x1fb, 0x2083
};

const u16 sChargedWaveBeamOAM_Horizontal_Frame4[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xea, OBJ_SIZE_32x16 | 0x1, 0x2083,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x1, 0x2083
};

const u16 sChargedWaveBeamOAM_Horizontal_Frame5[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_32x16 | 0x8, 0x2083,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x16 | 0x8, 0x2083
};

const u16 sChargedWaveBeamOAM_Horizontal_Frame6[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0xc, 0x2086,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0xc, 0x2086
};

const u16 sChargedWaveBeamOAM_Diagonal_Frame0[7] = {
    0x2,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x20c4,
    0x4, 0x4, 0x20e7
};

const u16 sChargedWaveBeamOAM_Diagonal_Frame1[19] = {
    0x6,
    0xf6, OBJ_SIZE_16x16 | 0x1f9, 0x20c4,
    0x1, 0x4, 0x20e7,
    0xf9, OBJ_SIZE_16x16 | 0x1f6, 0x20c4,
    0x4, 0x1, 0x20e7,
    0x1, OBJ_SIZE_16x16 | 0x1, 0x20c8,
    0xc, 0xc, 0x20e7
};

const u16 sChargedWaveBeamOAM_Diagonal_Frame2[25] = {
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

const u16 sChargedWaveBeamOAM_Diagonal_Frame3[13] = {
    0x4,
    0xf2, OBJ_SIZE_16x16 | 0x2, 0x20c4,
    0xfd, 0xd, 0x20e7,
    0x2, OBJ_SIZE_16x16 | 0x1f2, 0x20c4,
    0xd, 0x1fd, 0x20e7
};

const u16 sChargedWaveBeamOAM_Diagonal_Frame4[13] = {
    0x4,
    0xf3, OBJ_SIZE_16x16 | 0x6, 0x20c4,
    0xfe, 0x11, 0x20e7,
    0x6, OBJ_SIZE_16x16 | 0x1f3, 0x20c4,
    0x11, 0x1fe, 0x20e7
};

const u16 sChargedWaveBeamOAM_Diagonal_Frame5[13] = {
    0x4,
    0xfa, OBJ_SIZE_16x16 | 0xb, 0x20c4,
    0x5, 0x16, 0x20e7,
    0xa, OBJ_SIZE_16x16 | 0x1fb, 0x20c4,
    0x15, 0x6, 0x20e7
};

const u16 sChargedWaveBeamOAM_Diagonal_Frame6[13] = {
    0x4,
    0x2, OBJ_SIZE_16x16 | 0xc, 0x20c8,
    0xd, 0x17, 0x20e7,
    0xb, OBJ_SIZE_16x16 | 0x3, 0x20c8,
    0x16, 0xe, 0x20e7
};

const u16 sChargedWaveBeamOAM_Vertical_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_16x32 | 0x1f8, 0x208a
};

const u16 sChargedWaveBeamOAM_Vertical_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_SIZE_16x32 | 0x1fa, 0x208a,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_SIZE_16x32 | 0x1f6, 0x208a,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_SIZE_16x32 | 0x1f8, 0x208c
};

const u16 sChargedWaveBeamOAM_Vertical_Frame2[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_SIZE_16x32 | 0x1fe, 0x208a,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_SIZE_16x32 | 0x1f2, 0x208a,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_SIZE_16x32 | 0x1f8, 0x208a,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_SIZE_16x32 | 0x1f8, 0x208c
};

const u16 sChargedWaveBeamOAM_Vertical_Frame3[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xfb, OBJ_SIZE_16x32 | 0x3, 0x208a,
    OBJ_SHAPE_VERTICAL | 0xfb, OBJ_SIZE_16x32 | 0x1ed, 0x208a
};

const u16 sChargedWaveBeamOAM_Vertical_Frame4[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x1, OBJ_SIZE_16x32 | 0x6, 0x208a,
    OBJ_SHAPE_VERTICAL | 0x1, OBJ_SIZE_16x32 | 0x1ea, 0x208a
};

const u16 sChargedWaveBeamOAM_Vertical_Frame5[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_16x32 | 0x3, 0x208a,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_16x32 | 0x1ed, 0x208a
};

const u16 sChargedWaveBeamOAM_Vertical_Frame6[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_SIZE_16x32 | 0x1ff, 0x208c,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_SIZE_16x32 | 0x1f1, 0x208c
};

const u16 sParticleChargedWaveBeamTrailOam_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x20c7
};

const u16 sParticleChargedWaveBeamTrailOam_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, 0x208e,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f8, 0x208e
};

const u16 sParticleChargedWaveBeamTrailOam_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20ae
};

const u16 sParticleChargedWaveBeamTrailOam_Frame3[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, 0x20ee,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f8, 0x20ee
};

const struct FrameData sWaveBeamOAM_Horizontal[8] = {
    sWaveBeamOAM_Horizontal_Frame0,
    0x3,
    sWaveBeamOAM_Horizontal_Frame1,
    0x2,
    sWaveBeamOAM_Horizontal_Frame2,
    0x2,
    sWaveBeamOAM_Horizontal_Frame3,
    0x1,
    sWaveBeamOAM_Horizontal_Frame4,
    0x1,
    sWaveBeamOAM_Horizontal_Frame5,
    0x1,
    sWaveBeamOAM_Horizontal_Frame6,
    0x1,
    NULL,
    0x0
};

const struct FrameData sWaveBeamOAM_Diagonal[8] = {
    sWaveBeamOAM_Diagonal_Frame0,
    0x3,
    sWaveBeamOAM_Diagonal_Frame1,
    0x2,
    sWaveBeamOAM_Diagonal_Frame2,
    0x2,
    sWaveBeamOAM_Diagonal_Frame3,
    0x1,
    sWaveBeamOAM_Diagonal_Frame4,
    0x1,
    sWaveBeamOAM_Diagonal_Frame5,
    0x1,
    sWaveBeamOAM_Diagonal_Frame6,
    0x1,
    NULL,
    0x0
};

const struct FrameData sWaveBeamOAM_Vertical[8] = {
    sWaveBeamOAM_Vertical_Frame0,
    0x3,
    sWaveBeamOAM_Vertical_Frame1,
    0x2,
    sWaveBeamOAM_Vertical_Frame2,
    0x2,
    sWaveBeamOAM_Vertical_Frame3,
    0x1,
    sWaveBeamOAM_Vertical_Frame4,
    0x1,
    sWaveBeamOAM_Vertical_Frame5,
    0x1,
    sWaveBeamOAM_Vertical_Frame6,
    0x1,
    NULL,
    0x0
};

const struct FrameData sWaveBeamOAM_Horizontal_Unused[8] = {
    sWaveBeamOAM_Horizontal_Unused_Frame0,
    0x3,
    sWaveBeamOAM_Horizontal_Unused_Frame1,
    0x2,
    sWaveBeamOAM_Horizontal_Unused_Frame2,
    0x2,
    sWaveBeamOAM_Horizontal_Unused_Frame3,
    0x1,
    sWaveBeamOAM_Horizontal_Unused_Frame4,
    0x1,
    sWaveBeamOAM_Horizontal_Unused_Frame5,
    0x1,
    sWaveBeamOAM_Horizontal_Unused_Frame6,
    0x1,
    NULL,
    0x0
};

const struct FrameData sWaveBeamOAM_Diagonal_Unused[8] = {
    sWaveBeamOAM_Diagonal_Unused_Frame0,
    0x3,
    sWaveBeamOAM_Diagonal_Unused_Frame1,
    0x2,
    sWaveBeamOAM_Diagonal_Unused_Frame2,
    0x2,
    sWaveBeamOAM_Diagonal_Unused_Frame3,
    0x1,
    sWaveBeamOAM_Diagonal_Unused_Frame4,
    0x1,
    sWaveBeamOAM_Diagonal_Unused_Frame5,
    0x1,
    sWaveBeamOAM_Diagonal_Unused_Frame6,
    0x1,
    NULL,
    0x0
};

const struct FrameData sWaveBeamOAM_Vertical_Unused[8] = {
    sWaveBeamOAM_Vertical_Unused_Frame0,
    0x3,
    sWaveBeamOAM_Vertical_Unused_Frame1,
    0x2,
    sWaveBeamOAM_Vertical_Unused_Frame2,
    0x2,
    sWaveBeamOAM_Vertical_Unused_Frame3,
    0x1,
    sWaveBeamOAM_Vertical_Unused_Frame4,
    0x1,
    sWaveBeamOAM_Vertical_Unused_Frame5,
    0x1,
    sWaveBeamOAM_Vertical_Unused_Frame6,
    0x1,
    NULL,
    0x0
};

const struct FrameData sChargedWaveBeamOAM_Horizontal[8] = {
    sChargedWaveBeamOAM_Horizontal_Frame0,
    0x3,
    sChargedWaveBeamOAM_Horizontal_Frame1,
    0x2,
    sChargedWaveBeamOAM_Horizontal_Frame2,
    0x2,
    sChargedWaveBeamOAM_Horizontal_Frame3,
    0x1,
    sChargedWaveBeamOAM_Horizontal_Frame4,
    0x1,
    sChargedWaveBeamOAM_Horizontal_Frame5,
    0x1,
    sChargedWaveBeamOAM_Horizontal_Frame6,
    0x1,
    NULL,
    0x0
};

const struct FrameData sChargedWaveBeamOAM_Diagonal[8] = {
    sChargedWaveBeamOAM_Diagonal_Frame0,
    0x3,
    sChargedWaveBeamOAM_Diagonal_Frame1,
    0x2,
    sChargedWaveBeamOAM_Diagonal_Frame2,
    0x2,
    sChargedWaveBeamOAM_Diagonal_Frame3,
    0x1,
    sChargedWaveBeamOAM_Diagonal_Frame4,
    0x1,
    sChargedWaveBeamOAM_Diagonal_Frame5,
    0x1,
    sChargedWaveBeamOAM_Diagonal_Frame6,
    0x1,
    NULL,
    0x0
};

const struct FrameData sChargedWaveBeamOAM_Vertical[8] = {
    sChargedWaveBeamOAM_Vertical_Frame0,
    0x3,
    sChargedWaveBeamOAM_Vertical_Frame1,
    0x2,
    sChargedWaveBeamOAM_Vertical_Frame2,
    0x2,
    sChargedWaveBeamOAM_Vertical_Frame3,
    0x1,
    sChargedWaveBeamOAM_Vertical_Frame4,
    0x1,
    sChargedWaveBeamOAM_Vertical_Frame5,
    0x1,
    sChargedWaveBeamOAM_Vertical_Frame6,
    0x1,
    NULL,
    0x0
};

const struct FrameData sParticleChargedWaveBeamTrailOam[5] = {
    sParticleChargedWaveBeamTrailOam_Frame0,
    0x4,
    sParticleChargedWaveBeamTrailOam_Frame1,
    0x4,
    sParticleChargedWaveBeamTrailOam_Frame2,
    0x4,
    sParticleChargedWaveBeamTrailOam_Frame3,
    0x4,
    NULL,
    0x0
};

const u8 sPlasmaBeamGfx_Top[512] = INCBIN_U8("data/weapons/PlasmaBeamTop.gfx");
const u8 sPlasmaBeamGfx_Bottom[512] = INCBIN_U8("data/weapons/PlasmaBeamBottom.gfx");
const u8 sPlasmaBeamGfx_Charged_Top[512] = INCBIN_U8("data/weapons/PlasmaBeamChargedTop.gfx");
const u8 sPlasmaBeamGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/PlasmaBeamChargedBottom.gfx");

const u16 sPlasmaBeamOAM_Horizontal_NoWave_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f8, 0x20e0
};

const u16 sPlasmaBeamOAM_Horizontal_NoWave_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f9, 0x20e4
};

const u16 sPlasmaBeamOAM_Diagonal_NoWave_Frame0[4] = {
    0x1,
    0xfb, OBJ_SIZE_16x16 | 0x1fb, 0x208e
};

const u16 sPlasmaBeamOAM_Diagonal_NoWave_Frame1[4] = {
    0x1,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x20ce
};

const u16 sPlasmaBeamOAM_Vertical_NoWave_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1fc, 0x2083
};

const u16 sPlasmaBeamOAM_Vertical_NoWave_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_8x32 | 0x1fc, 0x2087
};

const u16 sChargedPlasmaBeamOAM_Horizontal_NoWave_Frame0[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f8, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x0, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x0, 0x20ca
};

const u16 sChargedPlasmaBeamOAM_Horizontal_NoWave_Frame1[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f6, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x2, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x2, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0xc, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0xc, 0x20ca
};

const u16 sChargedPlasmaBeamOAM_Diagonal_NoWave_Frame0[13] = {
    0x4,
    0xfa, OBJ_SIZE_16x16 | 0x1fa, 0x2080,
    0x2, OBJ_SIZE_16x16 | 0x2, 0x20a1,
    0xff, OBJ_SIZE_16x16 | 0x1ff, 0x2084,
    0x7, OBJ_SIZE_16x16 | 0x7, 0x20a5
};

const u16 sChargedPlasmaBeamOAM_Diagonal_NoWave_Frame1[19] = {
    0x6,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x2080,
    0x0, OBJ_SIZE_16x16 | 0x0, 0x20a1,
    0x0, OBJ_SIZE_16x16 | 0x0, 0x2084,
    0x8, OBJ_SIZE_16x16 | 0x8, 0x20a5,
    0x8, OBJ_SIZE_16x16 | 0x8, 0x2084,
    0x10, OBJ_SIZE_16x16 | 0x10, 0x20a5
};

const u16 sChargedPlasmaBeamOAM_Vertical_NoWave_Frame0[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x0, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x0, 0x2089,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2089
};

const u16 sChargedPlasmaBeamOAM_Vertical_NoWave_Frame1[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_SIZE_8x32 | 0x0, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf6, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_SIZE_8x32 | 0x0, 0x2089,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2089,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_SIZE_8x32 | 0x0, 0x2089,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2089
};

const u16 sPlasmaBeamOAM_Horizontal_Wave_Frame1[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x6, 0x20e4
};

const u16 sPlasmaBeamOAM_Horizontal_Wave_Frame2[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x10, 0x20e4,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f8, 0x20e0
};

const u16 sPlasmaBeamOAM_Horizontal_Wave_Frame3[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f9, 0x20e4
};

const u16 sPlasmaBeamOAM_Horizontal_Wave_Frame4[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x8 | 0x1f8, 0x20e4,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x8 | 0x1f8, 0x20e4,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f8, 0x20e0
};

const u16 sPlasmaBeamOAM_Horizontal_Wave_Frame5[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x8 | 0x1f8, 0x20e4,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x8 | 0x1f8, 0x20e4
};

const u16 sPlasmaBeamOAM_Horizontal_Wave_Frame6[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f8, 0x20e0,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x8 | 0x1f8, 0x20e4,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x8 | 0x1f8, 0x20e4
};

const u16 sPlasmaBeamOAM_Diagonal_Wave_Frame1[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1fd, 0x208e,
    0xfe, OBJ_SIZE_16x16 | 0x1f7, 0x208e,
    0x5, OBJ_SIZE_16x16 | 0x5, 0x20ce
};

const u16 sPlasmaBeamOAM_Diagonal_Wave_Frame2[13] = {
    0x4,
    0xf5, OBJ_SIZE_16x16 | 0x1, 0x208e,
    0x1, OBJ_SIZE_16x16 | 0x1f5, 0x208e,
    0xc, OBJ_SIZE_16x16 | 0xc, 0x20ce,
    0xfb, OBJ_SIZE_16x16 | 0x1fb, 0x208e
};

const u16 sPlasmaBeamOAM_Diagonal_Wave_Frame3[10] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x4, 0x208e,
    0x4, OBJ_SIZE_16x16 | 0x1f2, 0x208e,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x20ce
};

const u16 sPlasmaBeamOAM_Diagonal_Wave_Frame4[16] = {
    0x5,
    0x2, OBJ_SIZE_16x16 | 0x1f4, 0x208e,
    0xf4, OBJ_SIZE_16x16 | 0x2, 0x208e,
    0x5, OBJ_SIZE_16x16 | 0x1f0, 0x20ce,
    0xf0, OBJ_SIZE_16x16 | 0x6, 0x20ce,
    0xfb, OBJ_SIZE_16x16 | 0x1fb, 0x208e
};

const u16 sPlasmaBeamOAM_Diagonal_Wave_Frame5[13] = {
    0x4,
    0xfe, OBJ_SIZE_16x16 | 0x1f7, 0x208e,
    0xf8, OBJ_SIZE_16x16 | 0x1fd, 0x208e,
    0x2, OBJ_SIZE_16x16 | 0x1f3, 0x20ce,
    0xf3, OBJ_SIZE_16x16 | 0x3, 0x20ce
};

const u16 sPlasmaBeamOAM_Diagonal_Wave_Frame6[10] = {
    0x3,
    0xfb, OBJ_SIZE_16x16 | 0x1fb, 0x208e,
    0xff, OBJ_SIZE_16x16 | 0x1f7, 0x20ce,
    0xf7, OBJ_SIZE_16x16 | 0x1ff, 0x20ce
};

const u16 sPlasmaBeamOAM_Vertical_Wave_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x0, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1f8, 0x2083,
    OBJ_SHAPE_VERTICAL | 0x6, OBJ_SIZE_8x32 | 0x1fc, 0x2087
};

const u16 sPlasmaBeamOAM_Vertical_Wave_Frame2[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x4, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1f4, 0x2083,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_SIZE_8x32 | 0x1fc, 0x2087,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1fc, 0x2083
};

const u16 sPlasmaBeamOAM_Vertical_Wave_Frame3[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x8, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1f0, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_8x32 | 0x1fc, 0x2087
};

const u16 sPlasmaBeamOAM_Vertical_Wave_Frame4[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x5, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1f3, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x9, 0x2087,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1ef, 0x2087,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1fc, 0x2083
};

const u16 sPlasmaBeamOAM_Vertical_Wave_Frame5[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x0, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1f8, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x5, 0x2087,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1f3, 0x2087
};

const u16 sPlasmaBeamOAM_Vertical_Wave_Frame6[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1fc, 0x2083,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x2, 0x2087,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1f6, 0x2087
};

const u16 sPlasmaBeamOAM_Diagonal_Wave_Unused_Frame3[19] = {
    0x6,
    0xf7, 0x3, 0x208e,
    0x3, 0x1f7, 0x208e,
    0xf6, 0x1fd, 0x208f,
    0xfd, 0x1f6, 0x208f,
    0x4, 0x4, 0x208f,
    0x1, 0x1, 0x208e
};

const u16 sPlasmaBeamOAM_Diagonal_Wave_Unused_Frame4[13] = {
    0x4,
    0xfb, 0x7, 0x208f,
    0x7, 0x1fb, 0x208f,
    0x5, 0x5, 0x208f,
    0xff, 0x1ff, 0x208e
};

const u16 sPlasmaBeamOAM_Vertical_Wave_Unused_Frame1[10] = {
    0x3,
    0xfc, 0x1fe, 0x20c4,
    0xfc, 0x1fa, 0x20c4,
    0x0, 0x1fc, 0x2086
};

const u16 sPlasmaBeamOAM_Vertical_Wave_Unused_Frame2[16] = {
    0x5,
    0xf8, 0x1ff, 0x20c4,
    0xf8, 0x1f9, 0x20c4,
    0xfd, 0x4, 0x20c4,
    0xfd, 0x1f4, 0x20c4,
    0x1, 0x1fc, 0x20c4
};

const u16 sPlasmaBeamOAM_Vertical_Wave_Unused_Frame3[16] = {
    0x5,
    0x1, 0x6, 0x20c4,
    0x1, 0x1f2, 0x20c4,
    0xfb, 0x2, 0x2086,
    0xfb, 0x1f6, 0x2086,
    0x7, 0x1fc, 0x2086
};

const u16 sPlasmaBeamOAM_Vertical_Wave_Unused_Frame4[10] = {
    0x3,
    0x5, 0x6, 0x2086,
    0x5, 0x1f2, 0x2086,
    0xb, 0x1fc, 0x2086
};

const u16 sChargedPlasmaBeamOAM_Horizontal_Wave_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f9, 0x208a
};

const u16 sChargedPlasmaBeamOAM_Horizontal_Wave_Frame1[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f7, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f7, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x4, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x4, 0x20ca
};

const u16 sChargedPlasmaBeamOAM_Horizontal_Wave_Frame2[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1f7, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1f7, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f3, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x10, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x10, 0x20ca
};

const u16 sChargedPlasmaBeamOAM_Horizontal_Wave_Frame3[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_32x16 | 0x1fb, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x16 | 0x1fb, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x208a
};

const u16 sChargedPlasmaBeamOAM_Horizontal_Wave_Frame4[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xea, OBJ_SIZE_32x16 | 0x1, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x1, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x0, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x0, 0x20ca
};

const u16 sChargedPlasmaBeamOAM_Horizontal_Wave_Frame5[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_32x16 | 0x8, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x16 | 0x8, 0x208a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x10, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x10, 0x20ca
};

const u16 sChargedPlasmaBeamOAM_Horizontal_Wave_Frame6[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x8 | 0xc, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0xc, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0xc, 0x20ca,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0xc, 0x20ca
};

const u16 sChargedPlasmaBeamOAM_Diagonal_Wave_Frame0[7] = {
    0x2,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x2080,
    0x1, OBJ_SIZE_16x16 | 0x1, 0x20a1
};

const u16 sChargedPlasmaBeamOAM_Diagonal_Wave_Frame1[19] = {
    0x6,
    0xf6, OBJ_SIZE_16x16 | 0x1f9, 0x2080,
    0xfe, OBJ_SIZE_16x16 | 0x1, 0x20a1,
    0xf9, OBJ_SIZE_16x16 | 0x1f6, 0x2080,
    0x1, OBJ_SIZE_16x16 | 0x1fe, 0x20a1,
    0x1, OBJ_SIZE_16x16 | 0x1, 0x2084,
    0x9, OBJ_SIZE_16x16 | 0x9, 0x20a5
};

const u16 sChargedPlasmaBeamOAM_Diagonal_Wave_Frame2[25] = {
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

const u16 sChargedPlasmaBeamOAM_Diagonal_Wave_Frame3[19] = {
    0x6,
    0xf2, OBJ_SIZE_16x16 | 0x2, 0x2080,
    0xfa, OBJ_SIZE_16x16 | 0xa, 0x20a1,
    0x2, OBJ_SIZE_16x16 | 0x1f2, 0x2080,
    0xa, OBJ_SIZE_16x16 | 0x1fa, 0x20a1,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x2080,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20a1
};

const u16 sChargedPlasmaBeamOAM_Diagonal_Wave_Frame4[19] = {
    0x6,
    0xf3, OBJ_SIZE_16x16 | 0x6, 0x2080,
    0xfb, OBJ_SIZE_16x16 | 0xe, 0x20a1,
    0x6, OBJ_SIZE_16x16 | 0x1f3, 0x2080,
    0xe, OBJ_SIZE_16x16 | 0x1fb, 0x20a1,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x2084,
    0x4, OBJ_SIZE_16x16 | 0x4, 0x20a5
};

const u16 sPlasmaBeamOAM_Horizontal_Wave_Unused_Frame3[19] = {
    0x6,
    0xfa, OBJ_SIZE_16x16 | 0xa, 0x2080,
    0x2, OBJ_SIZE_16x16 | 0x12, 0x20a1,
    0xa, OBJ_SIZE_16x16 | 0x1fa, 0x2080,
    0x12, OBJ_SIZE_16x16 | 0x2, 0x20a1,
    0x8, OBJ_SIZE_16x16 | 0x8, 0x2084,
    0x10, OBJ_SIZE_16x16 | 0x10, 0x20a5
};

const u16 sPlasmaBeamOAM_Horizontal_Wave_Unused_Frame4[13] = {
    0x4,
    0x2, OBJ_SIZE_16x16 | 0xc, 0x2084,
    0xa, OBJ_SIZE_16x16 | 0x14, 0x20a5,
    0xc, OBJ_SIZE_16x16 | 0x2, 0x2084,
    0x14, OBJ_SIZE_16x16 | 0xa, 0x20a5
};

const u16 sChargedPlasmaBeamOAM_Vertical_Wave_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_8x32 | 0x0, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2088
};

const u16 sChargedPlasmaBeamOAM_Vertical_Wave_Frame1[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_SIZE_8x32 | 0x2, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1fa, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_SIZE_8x32 | 0x1fd, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f5, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_SIZE_8x32 | 0x0, 0x2089,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2089
};

const u16 sChargedPlasmaBeamOAM_Vertical_Wave_Frame2[25] = {
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

const u16 sChargedPlasmaBeamOAM_Vertical_Wave_Frame3[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xfd, OBJ_SIZE_8x32 | 0xb, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xfd, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x3, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xfd, OBJ_SIZE_8x32 | 0x1f5, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xfd, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1ed, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x0, 0x2088,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2088
};

const u16 sChargedPlasmaBeamOAM_Vertical_Wave_Frame4[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0x1, OBJ_SIZE_8x32 | 0xe, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x1, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x6, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x1, OBJ_SIZE_8x32 | 0x1f2, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x1, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1ea, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x0, 0x2089,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2089
};

const u16 sPlasmaBeamOAM_Diagonal_Wave_Unused_Frame1[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_8x32 | 0xb, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x3, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_8x32 | 0x1f5, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1ed, 0x2088,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_SIZE_8x32 | 0x0, 0x2089,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f8, 0x2089
};

const u16 sPlasmaBeamOAM_Diagonal_Wave_Unused_Frame2[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_SIZE_8x32 | 0x1f9, 0x2089,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1f1, 0x2089,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_SIZE_8x32 | 0x7, 0x2089,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x1ff, 0x2089
};

const u16 sParticleChargedPlasmaBeamTrailOam_Frame1[13] = {
    0x4,
    0xf8, 0x1f8, 0x20ea,
    0xf8, OBJ_X_FLIP | 0x0, 0x20ea,
    0x0, OBJ_Y_FLIP | 0x1f8, 0x20ea,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, 0x20ea
};

const u16 sParticleChargedFullBeamTrailOam_Frame1[13] = {
    0x4,
    0xf9, 0x1f9, 0x20ea,
    0xf9, OBJ_X_FLIP | 0x1ff, 0x20ea,
    0xff, OBJ_Y_FLIP | 0x1f9, 0x20ea,
    0xff, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ff, 0x20ea
};

const u16 sParticleChargedPlasmaBeamTrailOam_Frame2[13] = {
    0x4,
    0xf8, 0x1f8, 0x20eb,
    0xf8, OBJ_X_FLIP | 0x0, 0x20eb,
    0x0, OBJ_Y_FLIP | 0x1f8, 0x20eb,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, 0x20eb
};

const u16 sParticleChargedFullBeamTrailOam_Frame3[13] = {
    0x4,
    0xf9, 0x1f9, 0x20eb,
    0xf9, OBJ_X_FLIP | 0x1ff, 0x20eb,
    0xff, OBJ_Y_FLIP | 0x1f9, 0x20eb,
    0xff, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ff, 0x20eb
};

const u16 sParticleChargedPlasmaBeamTrailOam_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x20c0
};

const u16 sParticleChargedFullBeamTrailOam_Frame5[4] = {
    0x1,
    0xfc, 0x1fc, 0x2082
};

const u16 sParticleChargedFullBeamTrailOam_Frame6[4] = {
    0x1,
    0xfc, 0x1fc, 0x20c4
};

const u16 sParticleChargedPlasmaBeamTrailOam_Frame3[4] = {
    0x1,
    0xfc, 0x1fc, 0x2086
};

const struct FrameData sPlasmaBeamOAM_Horizontal_NoWave[3] = {
    sPlasmaBeamOAM_Horizontal_NoWave_Frame0,
    0x3,
    sPlasmaBeamOAM_Horizontal_NoWave_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sPlasmaBeamOAM_Diagonal_NoWave[3] = {
    sPlasmaBeamOAM_Diagonal_NoWave_Frame0,
    0x3,
    sPlasmaBeamOAM_Diagonal_NoWave_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sPlasmaBeamOAM_Vertical_NoWave[3] = {
    sPlasmaBeamOAM_Vertical_NoWave_Frame0,
    0x3,
    sPlasmaBeamOAM_Vertical_NoWave_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sPlasmaBeamOAM_Horizontal_NoWave_Unused[3] = {
    sPlasmaBeamOAM_Horizontal_Wave_Frame5,
    0x3,
    sPlasmaBeamOAM_Horizontal_Wave_Frame6,
    0x3,
    NULL,
    0x0
};

const struct FrameData sPlasmaBeamOAM_Diagonal_NoWave_Unused[3] = {
    sPlasmaBeamOAM_Diagonal_Wave_Frame5,
    0x3,
    sPlasmaBeamOAM_Diagonal_Wave_Frame6,
    0x3,
    NULL,
    0x0
};

const struct FrameData sPlasmaBeamOAM_Vertical_NoWave_Unused[3] = {
    sPlasmaBeamOAM_Vertical_Wave_Frame5,
    0x3,
    sPlasmaBeamOAM_Vertical_Wave_Frame6,
    0x3,
    NULL,
    0x0
};

const struct FrameData sChargedPlasmaBeamOAM_Horizontal_NoWave[3] = {
    sChargedPlasmaBeamOAM_Horizontal_NoWave_Frame0,
    0x2,
    sChargedPlasmaBeamOAM_Horizontal_NoWave_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sChargedPlasmaBeamOAM_Diagonal_NoWave[3] = {
    sChargedPlasmaBeamOAM_Diagonal_NoWave_Frame0,
    0x2,
    sChargedPlasmaBeamOAM_Diagonal_NoWave_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sChargedPlasmaBeamOAM_Vertical_NoWave[3] = {
    sChargedPlasmaBeamOAM_Vertical_NoWave_Frame0,
    0x2,
    sChargedPlasmaBeamOAM_Vertical_NoWave_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sPlasmaBeamOAM_Horizontal_Wave[8] = {
    sPlasmaBeamOAM_Horizontal_NoWave_Frame0,
    0x3,
    sPlasmaBeamOAM_Horizontal_Wave_Frame1,
    0x2,
    sPlasmaBeamOAM_Horizontal_Wave_Frame2,
    0x2,
    sPlasmaBeamOAM_Horizontal_Wave_Frame3,
    0x1,
    sPlasmaBeamOAM_Horizontal_Wave_Frame4,
    0x1,
    sPlasmaBeamOAM_Horizontal_Wave_Frame5,
    0x1,
    sPlasmaBeamOAM_Horizontal_Wave_Frame6,
    0x1,
    NULL,
    0x0
};

const struct FrameData sPlasmaBeamOAM_Diagonal_Wave[8] = {
    sPlasmaBeamOAM_Diagonal_NoWave_Frame0,
    0x3,
    sPlasmaBeamOAM_Diagonal_Wave_Frame1,
    0x2,
    sPlasmaBeamOAM_Diagonal_Wave_Frame2,
    0x2,
    sPlasmaBeamOAM_Diagonal_Wave_Frame3,
    0x1,
    sPlasmaBeamOAM_Diagonal_Wave_Frame4,
    0x1,
    sPlasmaBeamOAM_Diagonal_Wave_Frame5,
    0x1,
    sPlasmaBeamOAM_Diagonal_Wave_Frame6,
    0x1,
    NULL,
    0x0
};

const struct FrameData sPlasmaBeamOAM_Vertical_Wave[8] = {
    sPlasmaBeamOAM_Vertical_NoWave_Frame0,
    0x3,
    sPlasmaBeamOAM_Vertical_Wave_Frame1,
    0x2,
    sPlasmaBeamOAM_Vertical_Wave_Frame2,
    0x2,
    sPlasmaBeamOAM_Vertical_Wave_Frame3,
    0x1,
    sPlasmaBeamOAM_Vertical_Wave_Frame4,
    0x1,
    sPlasmaBeamOAM_Vertical_Wave_Frame5,
    0x1,
    sPlasmaBeamOAM_Vertical_Wave_Frame6,
    0x1,
    NULL,
    0x0
};

const struct FrameData sPlasmaBeamOAM_Horizontal_Wave_Unused[6] = {
    sPlasmaBeamOAM_Horizontal_Wave_Frame5,
    0x3,
    sChargedPlasmaBeamOAM_Horizontal_Wave_Frame5,
    0x2,
    sChargedPlasmaBeamOAM_Horizontal_Wave_Frame6,
    0x2,
    sPlasmaBeamOAM_Horizontal_Wave_Unused_Frame3,
    0x1,
    sPlasmaBeamOAM_Horizontal_Wave_Unused_Frame4,
    0x1,
    NULL,
    0x0
};

const struct FrameData sPlasmaBeamOAM_Diagonal_Wave_Unused[6] = {
    sPlasmaBeamOAM_Diagonal_Wave_Frame5,
    0x3,
    sPlasmaBeamOAM_Diagonal_Wave_Unused_Frame1,
    0x2,
    sPlasmaBeamOAM_Diagonal_Wave_Unused_Frame2,
    0x2,
    sPlasmaBeamOAM_Diagonal_Wave_Unused_Frame3,
    0x1,
    sPlasmaBeamOAM_Diagonal_Wave_Unused_Frame4,
    0x1,
    NULL,
    0x0
};

const struct FrameData sPlasmaBeamOAM_Vertical_Wave_Unused[6] = {
    sPlasmaBeamOAM_Vertical_Wave_Frame5,
    0x3,
    sPlasmaBeamOAM_Vertical_Wave_Unused_Frame1,
    0x2,
    sPlasmaBeamOAM_Vertical_Wave_Unused_Frame2,
    0x2,
    sPlasmaBeamOAM_Vertical_Wave_Unused_Frame3,
    0x1,
    sPlasmaBeamOAM_Vertical_Wave_Unused_Frame4,
    0x1,
    NULL,
    0x0
};

const struct FrameData sChargedPlasmaBeamOAM_Horizontal_Wave[8] = {
    sChargedPlasmaBeamOAM_Horizontal_Wave_Frame0,
    0x3,
    sChargedPlasmaBeamOAM_Horizontal_Wave_Frame1,
    0x2,
    sChargedPlasmaBeamOAM_Horizontal_Wave_Frame2,
    0x2,
    sChargedPlasmaBeamOAM_Horizontal_Wave_Frame3,
    0x1,
    sChargedPlasmaBeamOAM_Horizontal_Wave_Frame4,
    0x1,
    sChargedPlasmaBeamOAM_Horizontal_Wave_Frame5,
    0x1,
    sChargedPlasmaBeamOAM_Horizontal_Wave_Frame6,
    0x1,
    NULL,
    0x0
};

const struct FrameData sChargedPlasmaBeamOAM_Diagonal_Wave[8] = {
    sChargedPlasmaBeamOAM_Diagonal_Wave_Frame0,
    0x3,
    sChargedPlasmaBeamOAM_Diagonal_Wave_Frame1,
    0x2,
    sChargedPlasmaBeamOAM_Diagonal_Wave_Frame2,
    0x2,
    sChargedPlasmaBeamOAM_Diagonal_Wave_Frame3,
    0x1,
    sChargedPlasmaBeamOAM_Diagonal_Wave_Frame4,
    0x1,
    sPlasmaBeamOAM_Horizontal_Wave_Unused_Frame3,
    0x1,
    sPlasmaBeamOAM_Horizontal_Wave_Unused_Frame4,
    0x1,
    NULL,
    0x0
};

const struct FrameData sChargedPlasmaBeamOAM_Vertical_Wave[8] = {
    sChargedPlasmaBeamOAM_Vertical_Wave_Frame0,
    0x3,
    sChargedPlasmaBeamOAM_Vertical_Wave_Frame1,
    0x2,
    sChargedPlasmaBeamOAM_Vertical_Wave_Frame2,
    0x2,
    sChargedPlasmaBeamOAM_Vertical_Wave_Frame3,
    0x1,
    sChargedPlasmaBeamOAM_Vertical_Wave_Frame4,
    0x1,
    sPlasmaBeamOAM_Diagonal_Wave_Unused_Frame1,
    0x1,
    sPlasmaBeamOAM_Diagonal_Wave_Unused_Frame2,
    0x1,
    NULL,
    0x0
};

const struct FrameData sParticleChargedPlasmaBeamTrailOam[5] = {
    sParticleChargedPlasmaBeamTrailOam_Frame0,
    0x4,
    sParticleChargedPlasmaBeamTrailOam_Frame1,
    0x4,
    sParticleChargedPlasmaBeamTrailOam_Frame2,
    0x4,
    sParticleChargedPlasmaBeamTrailOam_Frame3,
    0x4,
    NULL,
    0x0
};

const struct FrameData sParticleChargedFullBeamTrailOam[9] = {
    sParticleChargedPlasmaBeamTrailOam_Frame1,
    0x3,
    sParticleChargedFullBeamTrailOam_Frame1,
    0x3,
    sParticleChargedPlasmaBeamTrailOam_Frame2,
    0x3,
    sParticleChargedFullBeamTrailOam_Frame3,
    0x3,
    sParticleChargedPlasmaBeamTrailOam_Frame0,
    0x4,
    sParticleChargedFullBeamTrailOam_Frame5,
    0x4,
    sParticleChargedFullBeamTrailOam_Frame6,
    0x4,
    sParticleChargedPlasmaBeamTrailOam_Frame3,
    0x4,
    NULL,
    0x0
};

const u8 sPistolGfx_Top[512] = INCBIN_U8("data/weapons/PistolTop.gfx");
const u8 sPistolGfx_Bottom[512] = INCBIN_U8("data/weapons/PistolBottom.gfx");
const u8 sPistolGfx_Charged_Top[512] = INCBIN_U8("data/weapons/PistolChargedTop.gfx");
const u8 sPistolGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/PistolChargedBottom.gfx");

const u16 sPistolOAM_Horizontal_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fa, 0x2080
};

const u16 sPistolOAM_Horizontal_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fa, 0x20a0
};

const u16 sPistolOAM_Diagonal_Frame0[4] = {
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x2082
};

const u16 sPistolOAM_Diagonal_Frame1[4] = {
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f9, 0x2084
};

const u16 sPitsolOAM_Vertical_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1fc, 0x2086
};

const u16 sPitsolOAM_Vertical_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1fc, 0x2087
};

const u16 sChargedPistolOAM_Horizontal_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1fa, 0x20c0,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, 0x20c2
};

const u16 sChargedPistolOAM_Horizontal_Frame1[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20c2,
    0xf8, OBJ_SIZE_16x16 | 0x1, 0x20c0,
    0xf8, OBJ_SIZE_16x16 | 0x9, 0x20c2
};

const u16 sChargedPistolOAM_Diagonal_Frame0[7] = {
    0x2,
    0xfb, OBJ_SIZE_16x16 | 0x1fb, 0x20c4,
    0xfe, OBJ_SIZE_16x16 | 0x1fe, 0x20c6
};

const u16 sChargedPistolOAM_Diagonal_Frame1[10] = {
    0x3,
    0xfa, OBJ_SIZE_16x16 | 0x1fa, 0x20c6,
    0xff, OBJ_SIZE_16x16 | 0x1ff, 0x20c4,
    0x4, OBJ_SIZE_16x16 | 0x4, 0x20c6
};

const u16 sChargedPistolOAM_Vertical_Frame0[7] = {
    0x2,
    0xfa, OBJ_SIZE_16x16 | 0x1f8, 0x20c8,
    0xff, OBJ_SIZE_16x16 | 0x1f8, 0x20ca
};

const u16 sChargedPistolOAM_Vertical_Frame1[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x20ca,
    0x1, OBJ_SIZE_16x16 | 0x1f8, 0x20c8,
    0x9, OBJ_SIZE_16x16 | 0x1f8, 0x20ca
};

const u16 sParticleChargedPistolTrailOam_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x20ce
};

const u16 sParticleChargedPistolTrailOam_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, 0x20cf
};

const u16 sParticleChargedPistolTrailOam_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, 0x20ee
};

const u16 sParticleChargedPistolTrailOam_Frame3[4] = {
    0x1,
    0xfc, 0x1fc, 0x20ef
};

const struct FrameData sPistolOAM_Horizontal[3] = {
    sPistolOAM_Horizontal_Frame0,
    0x3,
    sPistolOAM_Horizontal_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sPistolOAM_Diagonal[3] = {
    sPistolOAM_Diagonal_Frame0,
    0x3,
    sPistolOAM_Diagonal_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sPistolOAM_Vertical[3] = {
    sPitsolOAM_Vertical_Frame0,
    0x3,
    sPitsolOAM_Vertical_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sChargedPistolOAM_Horizontal[3] = {
    sChargedPistolOAM_Horizontal_Frame0,
    0x2,
    sChargedPistolOAM_Horizontal_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sChargedPistolOAM_Diagonal[3] = {
    sChargedPistolOAM_Diagonal_Frame0,
    0x2,
    sChargedPistolOAM_Diagonal_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sChargedPistolOAM_Vertical[3] = {
    sChargedPistolOAM_Vertical_Frame0,
    0x2,
    sChargedPistolOAM_Vertical_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sParticleChargedPistolTrailOam[5] = {
    sParticleChargedPistolTrailOam_Frame0,
    0x4,
    sParticleChargedPistolTrailOam_Frame1,
    0x4,
    sParticleChargedPistolTrailOam_Frame2,
    0x4,
    sParticleChargedPistolTrailOam_Frame3,
    0x4,
    NULL,
    0x0
};

const struct FrameData sParticleEscapeOam_Unused[2] = {
    gParticleEscapeOamFrames,
    UCHAR_MAX,
    NULL,
    0x0
};

const struct FrameData sParticleSamusReflectionOAM_Unused[2] = {
    gParticleSamusReflectionOamFrames,
    UCHAR_MAX,
    NULL,
    0x0
};

// 32ba08
