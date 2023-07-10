#include "data/sprites/zipline.h"
#include "macros.h"

const u32 sZiplineGfx[264] = INCBIN_U32("data/sprites/Zipline.gfx.lz");
const u16 sZiplinePAL[16] = INCBIN_U16("data/sprites/Zipline.pal");

const u16 sZiplineOam_OffIdle_Frame0[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sZiplineOam_OffGrabbingSamus_Frame1[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

const u16 sZiplineOam_OffGrabbingSamus_Frame2[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sZiplineOam_OnGrabbingSamus_Frame1[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

const u16 sZiplineOam_OnSamusGrabbed_Frame2[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

const u16 sZiplineOam_OnSamusGrabbed_Frame1[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

const u16 sZiplineOam_OnSamusGrabbed_Frame0[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

const u16 sZiplineOam_OnIdle_Frame3[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sZiplineOam_OnGrabbingSamus_Frame2[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sZiplineOam_OnIdle_Frame1[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sZiplineOam_OnIdle_Frame2[7] = {
    0x2,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sZiplineButtonOAM_OffIdle_Frame0[7] = {
    0x2,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1f8, OBJ_SPRITE_OAM | 0x214
};

const u16 sZiplineButtonOAM_OnIdle_Frame1[7] = {
    0x2,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1f8, OBJ_SPRITE_OAM | 0x234
};

const u16 sZiplineButtonOAM_OnIdle_Frame2[7] = {
    0x2,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1f8, OBJ_SPRITE_OAM | 0x216
};

const u16 sZiplineButtonOAM_OnIdle_Frame3[7] = {
    0x2,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1f8, OBJ_SPRITE_OAM | 0x236
};

const struct FrameData sZiplineOam_OffIdle[2] = {
    sZiplineOam_OffIdle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sZiplineOam_OffGrabbingSamus[4] = {
    sZiplineOam_OffIdle_Frame0,
    0x2,
    sZiplineOam_OffGrabbingSamus_Frame1,
    0x2,
    sZiplineOam_OffGrabbingSamus_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sZiplineOam_OffSamusGrabbed[2] = {
    sZiplineOam_OffGrabbingSamus_Frame1,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sZiplineOam_OffReleasingSamus[4] = {
    sZiplineOam_OffGrabbingSamus_Frame2,
    0x2,
    sZiplineOam_OffGrabbingSamus_Frame1,
    0x2,
    sZiplineOam_OffIdle_Frame0,
    0x2,
    NULL,
    0x0
};

const struct FrameData sZiplineOam_OnIdle[7] = {
    sZiplineOam_OffIdle_Frame0,
    0x8,
    sZiplineOam_OnIdle_Frame1,
    0x8,
    sZiplineOam_OnIdle_Frame2,
    0x8,
    sZiplineOam_OnIdle_Frame3,
    0x8,
    sZiplineOam_OnIdle_Frame2,
    0x8,
    sZiplineOam_OnIdle_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sZiplineOam_OnGrabbingSamus[4] = {
    sZiplineOam_OnIdle_Frame3,
    0x2,
    sZiplineOam_OnGrabbingSamus_Frame1,
    0x2,
    sZiplineOam_OnGrabbingSamus_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sZiplineOam_OnSamusGrabbed[7] = {
    sZiplineOam_OnSamusGrabbed_Frame0,
    0x8,
    sZiplineOam_OnSamusGrabbed_Frame1,
    0x8,
    sZiplineOam_OnSamusGrabbed_Frame2,
    0x8,
    sZiplineOam_OnGrabbingSamus_Frame1,
    0x8,
    sZiplineOam_OnSamusGrabbed_Frame2,
    0x8,
    sZiplineOam_OnSamusGrabbed_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sZiplineOam_OnReleasingSamus[4] = {
    sZiplineOam_OnGrabbingSamus_Frame2,
    0x2,
    sZiplineOam_OnGrabbingSamus_Frame1,
    0x2,
    sZiplineOam_OnIdle_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sZiplineButtonOAM_OffIdle[2] = {
    sZiplineButtonOAM_OffIdle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sZiplineButtonOAM_OnIdle[7] = {
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

const struct FrameData sZiplineButtonOAM_Active[7] = {
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
