#include "data/sprites/escape_gate.h"

#include "macros.h"

const u8 sEscapeGateAndTimerGfx[2048] = INCBIN_U8("data/sprites/EscapeGateAndTimer.gfx");
const u16 sEscapeGateAndTimerPAL[16] = INCBIN_U16("data/sprites/EscapeGateAndTimer.pal");
const u16 sEscapeGateFlashingPAL[96] = INCBIN_U16("data/sprites/EscapeGateFlashing.pal");

const u16 sEscapeGateOAM_Closed_Frame0[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7,
    OBJ_SHAPE_HORIZONTAL | 0xda, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73db
};

const u16 sEscapeGateOAM_Opening_Frame1[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7,
    OBJ_SHAPE_HORIZONTAL | 0xda, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73fb
};

const u16 sEscapeGateOAM_Opening_Frame2[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame4[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xbe, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xce, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame3[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xbd, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xcd, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame5[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xcc, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame6[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xba, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xca, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame7[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73eb,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame8[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xea, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7,
    OBJ_SHAPE_HORIZONTAL | 0xbe, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73eb
};

const u16 sEscapeGateOAM_Opening_Frame9[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc4, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73eb,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame10[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xba, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73eb,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame11[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xb8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73eb,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame12[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xbe, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3
};

const u16 sEscapeGateOAM_Opening_Frame13[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3
};

const u16 sEscapeGateOAM_Opening_Frame14[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xba, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3
};

const u16 sEscapeGateOAM_Opening_Frame15[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xb8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3
};

const u16 sEscapeGateOAM_Opening_Frame16[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xbe, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73ef,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3
};

const struct FrameData sEscapeGateOAM_Closed[2] = {
    sEscapeGateOAM_Closed_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sEscapeGateOAM_Opening[18] = {
    sEscapeGateOAM_Closed_Frame0,
    0x32,
    sEscapeGateOAM_Opening_Frame1,
    0xC,
    sEscapeGateOAM_Opening_Frame2,
    0x32,
    sEscapeGateOAM_Opening_Frame3,
    0x4,
    sEscapeGateOAM_Opening_Frame4,
    0xA,
    sEscapeGateOAM_Opening_Frame5,
    0x1,
    sEscapeGateOAM_Opening_Frame6,
    0x1,
    sEscapeGateOAM_Opening_Frame7,
    0x1,
    sEscapeGateOAM_Opening_Frame8,
    0x1,
    sEscapeGateOAM_Opening_Frame9,
    0x1,
    sEscapeGateOAM_Opening_Frame10,
    0x1,
    sEscapeGateOAM_Opening_Frame11,
    0x1,
    sEscapeGateOAM_Opening_Frame12,
    0x1,
    sEscapeGateOAM_Opening_Frame13,
    0x1,
    sEscapeGateOAM_Opening_Frame14,
    0x1,
    sEscapeGateOAM_Opening_Frame15,
    0x1,
    sEscapeGateOAM_Opening_Frame16,
    0x1,
    NULL,
    0x0
};

const struct FrameData sEscapeGateOAM_Opened[2] = {
    sEscapeGateOAM_Opening_Frame16,
    0xFF,
    NULL,
    0x0
};
