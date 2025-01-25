#include "data/sprites/elevator_pad.h"
#include "macros.h"

const u32 sElevatorPadGfx[136] = INCBIN_U32("data/sprites/ElevatorPad.gfx.lz");
const u16 sElevatorPadPal[16] = INCBIN_U16("data/sprites/ElevatorPad.pal");

const u16 sElevatorPadOAM_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sElevatorPadOAM_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208
};

const u16 sElevatorPadOAM_Moving_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

const u16 sElevatorPadOAM_Moving_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x22a
};

const u16 sElevatorPadOAM_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220
};

const u16 sElevatorPadOAM_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sElevatorPadOAM_Idle_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

const struct FrameData sElevatorPadOAM_Moving[5] = {
    [0] = {
        .pFrame = sElevatorPadOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sElevatorPadOAM_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sElevatorPadOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sElevatorPadOAM_Moving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sElevatorPadOAM_Idle[7] = {
    [0] = {
        .pFrame = sElevatorPadOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sElevatorPadOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sElevatorPadOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sElevatorPadOAM_Idle_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sElevatorPadOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sElevatorPadOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};
