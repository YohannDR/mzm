#include "data/sprites/elevator_pad.h"
#include "macros.h"

const u32 sElevatorPadGfx[136] = INCBIN_U32("data/sprites/ElevatorPad.gfx.lz");
const u16 sElevatorPadPAL[16] = INCBIN_U16("data/sprites/ElevatorPad.pal");

const u16 sElevatorPadOAM_Moving_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sElevatorPadOAM_Moving_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208
};

const u16 sElevatorPadOAM_Moving_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

const u16 sElevatorPadOAM_Moving_Frame3[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x22a
};

const u16 sElevatorPadOAM_Idle_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220
};

const u16 sElevatorPadOAM_Idle_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sElevatorPadOAM_Idle_Frame3[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

const struct FrameData sElevatorPadOAM_Moving[5] = {
    sElevatorPadOAM_Moving_Frame0,
    0x1,
    sElevatorPadOAM_Moving_Frame1,
    0x2,
    sElevatorPadOAM_Moving_Frame2,
    0x1,
    sElevatorPadOAM_Moving_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sElevatorPadOAM_Idle[7] = {
    sElevatorPadOAM_Moving_Frame0,
    0x8,
    sElevatorPadOAM_Idle_Frame1,
    0x8,
    sElevatorPadOAM_Idle_Frame2,
    0x8,
    sElevatorPadOAM_Idle_Frame3,
    0x8,
    sElevatorPadOAM_Idle_Frame2,
    0x8,
    sElevatorPadOAM_Idle_Frame1,
    0x8,
    NULL,
    0x0
};
