#ifndef SQUEEPT_DATA_C
#define SQUEEPT_DATA_C

#include "../../types.h"
#include "../../oam.h"

static const i16 sSqueeptRisingMovement[65] = {
    -18, -18, -18, -18, -16, -16, -16, -16, -14,
    -14, -14, -14, -12, -12, -12, -12, -12, -12,
    -12, -12, -11, -11, -11, -11, -10, -10, -10,
    -10, -9, -9, -9, -9, -8, -8, -8, -8, -8, -8,
    -8, -8, -7, -7, -7, -7, -6, -6, -6, -6, -5,
    -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -3,
    -2, -2, -2, -2, SHORT_MAX
};

static const i16 sSqueeptFallingMovement[16] = {
    4, 4, 4, 6, 6, 8, 8, 10, 10, 12, 12, 14,
    14, 16, 16, SHORT_MAX
};

static const u32 sSqueeptGFX[263];
static const u16 sSqueeptPAL[16];

static const u16 sSqueeptOAM_GoingUp_Frame0[25] = {
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

static const u16 sSqueeptOAM_GoingUp_Frame2[22] = {
    0x7,
    0xf2, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x202,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0xff, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x206,
    0xff, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0x2, 0x1fc, OBJ_SPRITE_OAM | 0x20f
};

static const u16 sSqueeptOAM_GoingUp_Frame4[22] = {
    0x7,
    0xf2, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0xff, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x206,
    0xff, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0x2, 0x1fc, OBJ_SPRITE_OAM | 0x20e
};

static const u16 sSqueeptOAM_GoingUp_Frame1[19] = {
    0x6,
    0xf3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1f1, OBJ_SPRITE_OAM | 0x206,
    0xff, 0x1f9, OBJ_SPRITE_OAM | 0x207,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x206,
    0xff, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSqueeptOAM_GoingUp_Frame3[19] = {
    0x6,
    0xf3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x202,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x206,
    0x0, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSqueeptOAM_GoingUp_Frame5[19] = {
    0x6,
    0xf3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x206,
    0x0, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSqueeptOAM_TurningAround_Frame0[13] = {
    0x4,
    0xf3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    0x3, 0x1f0, OBJ_SPRITE_OAM | 0x20d,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x208,
    0x3, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x20d
};

static const u16 sSqueeptOAM_TurningAround_Frame1[7] = {
    0x2,
    0xf4, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sSqueeptOAM_TurningAround_Frame2[7] = {
    0x2,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sSqueeptOAM_TurningAround_Frame3[13] = {
    0x4,
    0xf7, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    0xef, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x20d,
    0xf7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x208,
    0xef, OBJ_X_FLIP | OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x20d
};

static const u16 sSqueeptOAM_TurningAround_Frame4[19] = {
    0x6,
    0xfc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0xf7, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x206,
    0xf7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSqueeptOAM_GoingDown_Frame0[13] = {
    0x4,
    0xfd, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xfd, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x20c
};

static const u16 sSqueeptOAM_GoingDown_Frame1[13] = {
    0x4,
    0xfc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1f7, OBJ_SPRITE_OAM | 0x20c,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x20c
};

static const struct FrameData sSqueeptOAM_TurningAround[6] = {
    sSqueeptOAM_TurningAround_Frame0,
    0x5,
    sSqueeptOAM_TurningAround_Frame1,
    0x9,
    sSqueeptOAM_TurningAround_Frame2,
    0x7,
    sSqueeptOAM_TurningAround_Frame3,
    0x3,
    sSqueeptOAM_TurningAround_Frame4,
    0xA,
    NULL,
    0x0
};

static const struct FrameData sSqueeptOAM_TurningAround_Unused[6] = {
    sSqueeptOAM_TurningAround_Frame4,
    0x5,
    sSqueeptOAM_TurningAround_Frame3,
    0x4,
    sSqueeptOAM_TurningAround_Frame2,
    0x3,
    sSqueeptOAM_TurningAround_Frame1,
    0x2,
    sSqueeptOAM_TurningAround_Frame0,
    0x1,
    NULL,
    0x0
};

static const struct FrameData sSqueeptOAM_GoingDown[3] = {
    sSqueeptOAM_GoingDown_Frame0,
    0x4,
    sSqueeptOAM_GoingDown_Frame1,
    0x4,
    NULL,
    0x0
};

static const struct FrameData sSqueeptOAM_GoingUp[8] = {
    sSqueeptOAM_GoingUp_Frame0,
    0x2,
    sSqueeptOAM_GoingUp_Frame1,
    0x1,
    sSqueeptOAM_GoingUp_Frame2,
    0x2,
    sSqueeptOAM_GoingUp_Frame3,
    0x1,
    sSqueeptOAM_GoingUp_Frame4,
    0x2,
    sSqueeptOAM_GoingUp_Frame5,
    0x1,
    sSqueeptOAM_GoingUp_Frame3,
    0x2,
    NULL,
    0x0
};

#endif