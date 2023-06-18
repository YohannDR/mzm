#include "data/sprites/metroid.h"
#include "macros.h"

const s16 sMetroidSpawningYMovement[65] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 2, 2, 1,
    1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, -1, 0, -1, 0, -1, 0, -1, -1, -1, -2, -2, -1,
    -1, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0, SHORT_MAX
};

const s16 sMetroidSpawningXMovement[81] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, -1, 0, -1, 0,
    -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -1, -1, -1,
    -1, -1, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0, SHORT_MAX 
};

const u32 sMetroidGfx[793] = INCBIN_U32("data/sprites/Metroid.gfx.lz");
const u16 sMetroidPAL[80] = INCBIN_U16("data/sprites/Metroid.pal");
const u16 sMetroidPAL_SamusGrabbed[80] = INCBIN_U16("data/sprites/MetroidSamusGrabbed.pal");

const u16 sMetroidShellOAM_Idle_Frame0[7] = {
    0x2,
    0xef, OBJ_SIZE_32x32 | 0x1ec, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_SIZE_8x32 | 0xc, OBJ_SPRITE_OAM | 0x208
};

const u16 sMetroidShellOAM_Idle_Frame1[7] = {
    0x2,
    0xef, OBJ_SIZE_32x32 | 0x1ec, OBJ_SPRITE_OAM | 0x284,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_SIZE_8x32 | 0xc, OBJ_SPRITE_OAM | 0x288
};

const u16 sMetroidOAM_Moving_Frame6[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x240,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x304,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x304
};

const u16 sMetroidOAM_Moving_Frame5[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x300,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x306,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x306
};

const u16 sMetroidOAM_Moving_Frame0[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2a0,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x308,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x308
};

const u16 sMetroidOAM_Moving_Frame1[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2a0,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x308,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x308
};

const u16 sMetroidOAM_Moving_Frame2[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x24a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x260,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2a0,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x308,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x308
};

const u16 sMetroidOAM_Moving_Frame9[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x28a,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x2ca,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x300,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x306,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x306
};

const u16 sMetroidOAM_Moving_Frame10[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2ea,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x32a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x300,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x306,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x306
};

const u16 sMetroidOAM_Spawning_Frame0[4] = {
    0x1,
    0xdf, OBJ_SIZE_64x64 | 0x1e0, OBJ_SPRITE_OAM | 0x210
};

const u16 sMetroidOAM_Spawning_Frame1[4] = {
    0x1,
    0xdf, OBJ_SIZE_64x64 | 0x1e0, OBJ_SPRITE_OAM | 0x218
};

const u16 sMetroidOAM_SamusGrabbed_Frame5[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4240,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4304,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x4304
};

const u16 sMetroidOAM_SamusGrabbed_Frame4[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x42c0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4300,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4306,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x4306
};

const u16 sMetroidOAM_SamusGrabbed_Frame7[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4260,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x42a0,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4308,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x4308
};

const u16 sMetroidOAM_SamusGrabbed_Frame0[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x420a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4260,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x42a0,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4308,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x4308
};

const u16 sMetroidOAM_SamusGrabbed_Frame1[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x424a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4260,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x42a0,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4308,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x4308
};

const u16 sMetroidOAM_SamusGrabbed_Frame8[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x428a,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x42ca,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x42c0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4300,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4306,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x4306
};

const u16 sMetroidOAM_SamusGrabbed_Frame9[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x42ea,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x432a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x42c0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4300,
    0x3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4306,
    0x3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x4306
};

const struct FrameData sMetroidShellOAM_Idle[3] = {
    sMetroidShellOAM_Idle_Frame0,
    0x1,
    sMetroidShellOAM_Idle_Frame1,
    0x1,
    NULL,
    0x0
};

const struct FrameData sMetroidOAM_Moving[17] = {
    sMetroidOAM_Moving_Frame0,
    0x4,
    sMetroidOAM_Moving_Frame1,
    0x2,
    sMetroidOAM_Moving_Frame2,
    0x2,
    sMetroidOAM_Moving_Frame1,
    0x2,
    sMetroidOAM_Moving_Frame2,
    0x2,
    sMetroidOAM_Moving_Frame5,
    0xC,
    sMetroidOAM_Moving_Frame6,
    0xC,
    sMetroidOAM_Moving_Frame5,
    0xC,
    sMetroidOAM_Moving_Frame0,
    0xC,
    sMetroidOAM_Moving_Frame9,
    0x2,
    sMetroidOAM_Moving_Frame10,
    0x2,
    sMetroidOAM_Moving_Frame9,
    0x2,
    sMetroidOAM_Moving_Frame10,
    0x2,
    sMetroidOAM_Moving_Frame5,
    0x4,
    sMetroidOAM_Moving_Frame6,
    0xC,
    sMetroidOAM_Moving_Frame5,
    0xC,
    NULL,
    0x0
};

const struct FrameData sMetroidOAM_SamusGrabbed[15] = {
    sMetroidOAM_SamusGrabbed_Frame0,
    0x2,
    sMetroidOAM_SamusGrabbed_Frame1,
    0x2,
    sMetroidOAM_SamusGrabbed_Frame0,
    0x2,
    sMetroidOAM_SamusGrabbed_Frame1,
    0x2,
    sMetroidOAM_SamusGrabbed_Frame4,
    0x8,
    sMetroidOAM_SamusGrabbed_Frame5,
    0x8,
    sMetroidOAM_SamusGrabbed_Frame4,
    0x8,
    sMetroidOAM_SamusGrabbed_Frame7,
    0x8,
    sMetroidOAM_SamusGrabbed_Frame8,
    0x2,
    sMetroidOAM_SamusGrabbed_Frame9,
    0x2,
    sMetroidOAM_SamusGrabbed_Frame8,
    0x2,
    sMetroidOAM_SamusGrabbed_Frame9,
    0x2,
    sMetroidOAM_SamusGrabbed_Frame5,
    0x8,
    sMetroidOAM_SamusGrabbed_Frame4,
    0x8,
    NULL,
    0x0
};

const struct FrameData sMetroidOAM_Spanwing[3] = {
    sMetroidOAM_Spawning_Frame0,
    0x1,
    sMetroidOAM_Spawning_Frame1,
    0x1,
    NULL,
    0x0
};
