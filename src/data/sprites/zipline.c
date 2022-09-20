#ifndef ZIPLINE_DATA_C
#define ZIPLINE_DATA_C

#include "../../types.h"
#include "../../oam.h"

static const u32 sZiplineGFX[264];
static const u16 sZiplinePAL[16];

static const u16 sZiplineOAM_OffIdle_Frame0[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x208
};

static const u16 sZiplineOAM_OffGrabbingSamus_Frame1[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

static const u16 sZiplineOAM_OffGrabbingSamus_Frame2[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sZiplineOAM_OnGrabbingSamus_Frame1[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

static const u16 sZiplineOAM_OnSamusGrabbed_Frame2[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

static const u16 sZiplineOAM_OnSamusGrabbed_Frame1[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

static const u16 sZiplineOAM_OnSamusGrabbed_Frame0[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

static const u16 sZiplineOAM_OnIdle_Frame3[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x208
};

static const u16 sZiplineOAM_OnGrabbingSamus_Frame2[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sZiplineOAM_OnIdle_Frame1[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x208
};

static const u16 sZiplineOAM_OnIdle_Frame2[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x208
};

static const u16 sZiplineButtonOAM_OffIdle_Frame0[7] = {
    0x2,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1f8, OBJ_SPRITE_OAM | 0x214
};

static const u16 sZiplineButtonOAM_OnIdle_Frame1[7] = {
    0x2,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1f8, OBJ_SPRITE_OAM | 0x234
};

static const u16 sZiplineButtonOAM_OnIdle_Frame2[7] = {
    0x2,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1f8, OBJ_SPRITE_OAM | 0x216
};

static const u16 sZiplineButtonOAM_OnIdle_Frame3[7] = {
    0x2,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1f8, OBJ_SPRITE_OAM | 0x236
};

static const struct FrameData sZiplineOAM_OffIdle[2] = {
    sZiplineOAM_OffIdle_Frame0,
    0xFF,
    NULL,
    0x0
};

static const struct FrameData sZiplineOAM_OffGrabbingSamus[4] = {
    sZiplineOAM_OffIdle_Frame0,
    0x2,
    sZiplineOAM_OffGrabbingSamus_Frame1,
    0x2,
    sZiplineOAM_OffGrabbingSamus_Frame2,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sZiplineOAM_OffSamusGrabbed[2] = {
    sZiplineOAM_OffGrabbingSamus_Frame1,
    0xFF,
    NULL,
    0x0
};

static const struct FrameData sZiplineOAM_OffReleasingSamus[4] = {
    sZiplineOAM_OffGrabbingSamus_Frame2,
    0x2,
    sZiplineOAM_OffGrabbingSamus_Frame1,
    0x2,
    sZiplineOAM_OffIdle_Frame0,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sZiplineOAM_OnIdle[7] = {
    sZiplineOAM_OffIdle_Frame0,
    0x8,
    sZiplineOAM_OnIdle_Frame1,
    0x8,
    sZiplineOAM_OnIdle_Frame2,
    0x8,
    sZiplineOAM_OnIdle_Frame3,
    0x8,
    sZiplineOAM_OnIdle_Frame2,
    0x8,
    sZiplineOAM_OnIdle_Frame1,
    0x8,
    NULL,
    0x0
};

static const struct FrameData sZiplineOAM_OnGrabbingSamus[4] = {
    sZiplineOAM_OnIdle_Frame3,
    0x2,
    sZiplineOAM_OnGrabbingSamus_Frame1,
    0x2,
    sZiplineOAM_OnGrabbingSamus_Frame2,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sZiplineOAM_OnSamusGrabbed[7] = {
    sZiplineOAM_OnSamusGrabbed_Frame0,
    0x8,
    sZiplineOAM_OnSamusGrabbed_Frame1,
    0x8,
    sZiplineOAM_OnSamusGrabbed_Frame2,
    0x8,
    sZiplineOAM_OnSamusGrabbed_Frame1,
    0x8,
    sZiplineOAM_OnSamusGrabbed_Frame2,
    0x8,
    sZiplineOAM_OnSamusGrabbed_Frame1,
    0x8,
    NULL,
    0x0
};

static const struct FrameData sZiplineOAM_OnReleasingSamus[4] = {
    sZiplineOAM_OnGrabbingSamus_Frame2,
    0x2,
    sZiplineOAM_OnGrabbingSamus_Frame1,
    0x2,
    sZiplineOAM_OnIdle_Frame3,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sZiplineButtonOAM_OffIdle[2] = {
    sZiplineButtonOAM_OffIdle_Frame0,
    0xFF,
    NULL,
    0x0
};

static const struct FrameData sZiplineButtonOAM_OnIdle[7] = {
    sZiplineButtonOAM_OffIdle_Frame0,
    0xC,
    sZiplineButtonOAM_OnIdle_Frame1,
    0xC,
    sZiplineButtonOAM_OnIdle_Frame2,
    0xC,
    sZiplineButtonOAM_OnIdle_Frame3,
    0xC,
    sZiplineButtonOAM_OnIdle_Frame2,
    0xC,
    sZiplineButtonOAM_OnIdle_Frame1,
    0xC,
    NULL,
    0x0
};

static const struct FrameData sZiplineButtonOAM_Active[7] = {
    sZiplineButtonOAM_OffIdle_Frame0,
    0x2,
    sZiplineButtonOAM_OnIdle_Frame1,
    0x2,
    sZiplineButtonOAM_OnIdle_Frame2,
    0x2,
    sZiplineButtonOAM_OnIdle_Frame3,
    0x4,
    sZiplineButtonOAM_OnIdle_Frame2,
    0x2,
    sZiplineButtonOAM_OnIdle_Frame1,
    0x2,
    NULL,
    0x0
};

#endif