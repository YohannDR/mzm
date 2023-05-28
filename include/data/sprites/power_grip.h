#ifndef POWER_GRIP_DATA_H
#define POWER_GRIP_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sPowerGripGfx[279];
extern const u16 sPowerGripPAL[32];

extern const u16 sPowerGripOAM_Idle_Frame0[4];

extern const u16 sPowerGripOAM_Idle_Frame1[4];

extern const u16 sPowerGripOAM_Idle_Frame2[4];

extern const u16 sPowerGripGlowOAM_Idle_Frame0[10];

extern const u16 sPowerGripGlowOAM_Idle_Frame2[10];

extern const u16 sPowerGripGlowOAM_Idle_Frame4[10];

extern const u16 sPowerGripGlowOAM_Idle_Frame6[10];

extern const u16 sPowerGripGlowOAM_Idle_Frame1[4];

extern const struct FrameData sPowerGripOAM_Idle[5];

extern const struct FrameData sPowerGripGlowOAM_Idle[15];

#endif