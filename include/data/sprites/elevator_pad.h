#ifndef ELEVATOR_PAD_DATA_C
#define ELEVATOR_PAD_DATA_C

#include "types.h"
#include "oam.h"

static const u32 sElevatorPadGFX[136];
static const u16 sElevatorPadPAL[16];

static const u16 sElevatorPadOAM_Moving_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

static const u16 sElevatorPadOAM_Moving_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208
};

static const u16 sElevatorPadOAM_Moving_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

static const u16 sElevatorPadOAM_Moving_Frame3[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x22a
};

static const u16 sElevatorPadOAM_Idle_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220
};

static const u16 sElevatorPadOAM_Idle_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

static const u16 sElevatorPadOAM_Idle_Frame3[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

static const struct FrameData sElevatorPadOAM_Moving[5] = {
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

static const struct FrameData sElevatorPadOAM_Idle[7] = {
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

#endif