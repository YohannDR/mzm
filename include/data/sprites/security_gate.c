#ifndef SECURITY_GATE_DATA_C
#define SECURITY_GATE_DATA_C

#include "types.h"
#include "oam.h"

static const u32 sSecurityGateGFX[122];
static const u16 sSecurityGatePAL[16];

static const u16 sSecurityGateOAM_Opened_Frame0[4] = {
    0x1,
    0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x22c
};

static const u16 sSecurityGateOAM_Closing_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x222
};

static const u16 sSecurityGateOAM_Closing_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x226
};

static const u16 sSecurityGateOAM_Closing_Frame2[4] = {
    0x1,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

static const u16 sSecurityGateOAM_Closing_Frame3[4] = {
    0x1,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

static const u16 sSecurityGateOAM_Closing_Frame4[7] = {
    0x2,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x220
};

static const u16 sSecurityGateOAM_Closing_Frame5[7] = {
    0x2,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

static const u16 sSecurityGateOAM_Closing_Frame6[7] = {
    0x2,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityGateOAM_Closing_Frame7[7] = {
    0x2,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

static const u16 sSecurityGateOAM_Closing_Frame8[10] = {
    0x3,
    0xd8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

static const u16 sSecurityGateOAM_Closing_Frame9[10] = {
    0x3,
    0xd8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityGateOAM_Closing_Frame10[10] = {
    0x3,
    0xe0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

static const u16 sSecurityGateOAM_Closing_Frame11[10] = {
    0x3,
    0xe0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

static const u16 sSecurityGateOAM_Closing_Frame12[13] = {
    0x4,
    0xe8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xd8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityGateOAM_Closing_Frame13[13] = {
    0x4,
    0xe8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xd8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x220
};

static const u16 sSecurityGateOAM_Closing_Frame14[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xe0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

static const u16 sSecurityGateOAM_Closing_Frame15[16] = {
    0x5,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xe0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xc8, 0x1f8, OBJ_SPRITE_OAM | 0x220
};

static const u16 sSecurityGateOAM_Closing_Frame16[16] = {
    0x5,
    0xfb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xeb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xdb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xcb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xbb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sSecurityGateOAM_Closed_Frame0[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xe8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xd8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x22a
};

static const u16 sSecurityGateOAM_Closed_Frame1[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xe8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xd8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x22a
};

static const u16 sSecurityGateOAM_Closed_Frame2[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xe8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214,
    0xd8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x22a
};

static const struct FrameData sSecurityGateOAM_Opened[2] = {
    sSecurityGateOAM_Opened_Frame0,
    0xFF,
    NULL,
    0x0
};

static const struct FrameData sSecurityGateOAM_Closing[18] = {
    sSecurityGateOAM_Closing_Frame0,
    0x1,
    sSecurityGateOAM_Closing_Frame1,
    0x1,
    sSecurityGateOAM_Closing_Frame2,
    0x1,
    sSecurityGateOAM_Closing_Frame3,
    0x1,
    sSecurityGateOAM_Closing_Frame4,
    0x1,
    sSecurityGateOAM_Closing_Frame5,
    0x1,
    sSecurityGateOAM_Closing_Frame6,
    0x1,
    sSecurityGateOAM_Closing_Frame7,
    0x1,
    sSecurityGateOAM_Closing_Frame8,
    0x1,
    sSecurityGateOAM_Closing_Frame9,
    0x1,
    sSecurityGateOAM_Closing_Frame10,
    0x1,
    sSecurityGateOAM_Closing_Frame11,
    0x1,
    sSecurityGateOAM_Closing_Frame12,
    0x1,
    sSecurityGateOAM_Closing_Frame13,
    0x1,
    sSecurityGateOAM_Closing_Frame14,
    0x1,
    sSecurityGateOAM_Closing_Frame15,
    0x1,
    sSecurityGateOAM_Closing_Frame16,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sSecurityGateOAM_Closed[4] = {
    sSecurityGateOAM_Closed_Frame0,
    0x4,
    sSecurityGateOAM_Closed_Frame1,
    0x4,
    sSecurityGateOAM_Closed_Frame2,
    0x4,
    NULL,
    0x0
};

static const struct FrameData sSceurityGateOAM_Opened[18] = {
    sSecurityGateOAM_Closing_Frame16,
    0x2,
    sSecurityGateOAM_Closing_Frame15,
    0x1,
    sSecurityGateOAM_Closing_Frame14,
    0x1,
    sSecurityGateOAM_Closing_Frame13,
    0x1,
    sSecurityGateOAM_Closing_Frame12,
    0x1,
    sSecurityGateOAM_Closing_Frame11,
    0x1,
    sSecurityGateOAM_Closing_Frame10,
    0x1,
    sSecurityGateOAM_Closing_Frame9,
    0x1,
    sSecurityGateOAM_Closing_Frame8,
    0x1,
    sSecurityGateOAM_Closing_Frame7,
    0x1,
    sSecurityGateOAM_Closing_Frame6,
    0x1,
    sSecurityGateOAM_Closing_Frame5,
    0x1,
    sSecurityGateOAM_Closing_Frame4,
    0x1,
    sSecurityGateOAM_Closing_Frame3,
    0x1,
    sSecurityGateOAM_Closing_Frame2,
    0x1,
    sSecurityGateOAM_Closing_Frame1,
    0x1,
    sSecurityGateOAM_Closing_Frame0,
    0x1,
    NULL,
    0x0
};

#endif