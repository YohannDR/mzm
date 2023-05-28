#ifndef ELEVATOR_PAD_DATA_H
#define ELEVATOR_PAD_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sElevatorPadGfx[136];
extern const u16 sElevatorPadPAL[16];

extern const u16 sElevatorPadOAM_Moving_Frame0[4];

extern const u16 sElevatorPadOAM_Moving_Frame1[4];

extern const u16 sElevatorPadOAM_Moving_Frame2[4];

extern const u16 sElevatorPadOAM_Moving_Frame3[4];

extern const u16 sElevatorPadOAM_Idle_Frame1[4];

extern const u16 sElevatorPadOAM_Idle_Frame2[4];

extern const u16 sElevatorPadOAM_Idle_Frame3[4];

extern const struct FrameData sElevatorPadOAM_Moving[5];

extern const struct FrameData sElevatorPadOAM_Idle[7];

#endif