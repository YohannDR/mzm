#include "data/sprites/dragon.h"

#include "macros.h"

const s16 sDragonFireballYMovement[40] = {
    -12, -12, -12, -12, -10, -10, -10, -10, -8, -8, -8, -8,
    -6, -6, -6, -6, -5, -5, -4, -4, -3, -2, -1, 0, 1, 2, 3,
    4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16, 18, SHORT_MAX
};

const s16 sDragonFireballOamRotation[40] = {
    0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 6, 8, 10, 12, 14, 16, 16,
    20, 24, 28, 29, 30, 31, 32, 33, 34, 35, 36, 40, 44, 48,
    52, 56, 60, 64, 64, 64, 64, 64, SHORT_MAX
};

const u32 sDragonGfx[512] = INCBIN_U32("data/sprites/Dragon.gfx.lz");
const u16 sDragonPAL[32] = INCBIN_U16("data/sprites/Dragon.pal");

const u16 sDragonOAM_Spitting_Frame0[7] = {
    0x2,
    0xe6, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0x3, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20d
};

const u16 sDragonOAM_Spitting_Frame1[7] = {
    0x2,
    0xe5, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0x3, OBJ_SIZE_16x32 | 0x1f7, OBJ_SPRITE_OAM | 0x20d
};

const u16 sDragonOAM_Idle_Frame0[7] = {
    0x2,
    0x6, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x24b,
    0xe9, OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sDragonOAM_Idle_Frame1[7] = {
    0x2,
    0xea, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x207,
    0x4, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x24b
};

const u16 sDragonOAM_Idle_Frame2[13] = {
    0x4,
    0xe9, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xe9, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xf9, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x245,
    0x5, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x24b
};

const u16 sDragonOAM_TurningAround_Frame0[7] = {
    0x2,
    0xe9, OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20f,
    0x5, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x215
};

const u16 sDragonOAM_TurningAround_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_SIZE_16x32 | 0x1fa, OBJ_SPRITE_OAM | 0x213,
    0x5, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x255
};

const u16 sDragonOAM_Unused_0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x213,
    0x5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fc, OBJ_SPRITE_OAM | 0x255
};

const u16 sDragonOAM_Unused_1[7] = {
    0x2,
    0xe9, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1ec, OBJ_SPRITE_OAM | 0x20f,
    0x5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x215
};

const u16 sDragonFireballOAM_Moving_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25a
};

const u16 sDragonFireballOAM_Moving_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25c
};

const u16 sDragonFireballOAM_Moving_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25e
};

const u16 sDragonFireballOAM_Exploding_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a
};

const u16 sDragonFireballOAM_Exploding_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c
};

const u16 sDragonFireballOAM_Exploding_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21e
};

const u16 sDragonFireballOAM_Exploding_Frame3[4] = {
    0x1,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x121e
};

const struct FrameData sDragonOAM_Idle[4] = {
    sDragonOAM_Idle_Frame0,
    0xC,
    sDragonOAM_Idle_Frame1,
    0xC,
    sDragonOAM_Idle_Frame2,
    0xC,
    NULL,
    0x0
};

const struct FrameData sDragonOAM_Warning[3] = {
    sDragonOAM_Idle_Frame0,
    0x6,
    sDragonOAM_Idle_Frame1,
    0x6,
    NULL,
    0x0
};

const struct FrameData sDragonOAM_Spitting[3] = {
    sDragonOAM_Spitting_Frame0,
    0x4,
    sDragonOAM_Spitting_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sDragonOAM_TurningAround[3] = {
    sDragonOAM_TurningAround_Frame0,
    0x3,
    sDragonOAM_TurningAround_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sDragonOAM_TurningAroundPart2[3] = {
    sDragonOAM_TurningAround_Frame1,
    0x3,
    sDragonOAM_TurningAround_Frame0,
    0x3,
    NULL,
    0x0
};

const struct FrameData sDragonFireballOAM_Moving[4] = {
    sDragonFireballOAM_Moving_Frame0,
    0x1,
    sDragonFireballOAM_Moving_Frame1,
    0x4,
    sDragonFireballOAM_Moving_Frame2,
    0x4,
    NULL,
    0x0
};

const struct FrameData sDragonFireballOAM_Exploding[5] = {
    sDragonFireballOAM_Exploding_Frame0,
    0x4,
    sDragonFireballOAM_Exploding_Frame1,
    0x4,
    sDragonFireballOAM_Exploding_Frame2,
    0x4,
    sDragonFireballOAM_Exploding_Frame3,
    0x4,
    NULL,
    0x0
};
