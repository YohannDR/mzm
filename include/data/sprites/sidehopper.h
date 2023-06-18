#ifndef SIDEHOPPER_DATA_H
#define SIDEHOPPER_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sSidehopperHighJumpVelocity[10];

extern const s16 sSidehopperLowJumpVelocity[10];

extern const u32 sSidehopperGfx[303];
extern const u16 sSidehopperPAL[16];

extern const u16 sSidehopperOAM_Idle_Frame0[19];

extern const u16 sSidehopperOAM_Idle_Frame1[19];

extern const u16 sSidehopperOAM_Idle_Frame2[19];

extern const u16 sSidehopperOAM_JumpWarning_Frame0[19];

extern const u16 sSidehopperOAM_JumpWarning_Frame1[19];

extern const u16 sSidehopperOAM_JumpWarning_Frame2[19];

extern const u16 sSidehopperOAM_JumpWarning_Frame3[19];

extern const u16 sSidehopperOAM_JumpWarning_Frame4[19];

extern const u16 sSidehopperOAM_Jumping_Frame0[25];

extern const u16 sSidehopperOAM_Jumping_Frame1[25];

extern const u16 sSidehopperOAM_Jumping_Frame2[25];

extern const u16 sSidehopperOAM_Landing_Frame0[25];

extern const u16 sSidehopperOAM_ShakingHead_Frame0[19];

extern const u16 sSidehopperOAM_ShakingHead_Frame1[19];

extern const u16 sSidehopperOAM_ShakingHead_Frame2[19];

extern const struct FrameData sSidehopperOAM_Idle[5];

extern const struct FrameData sSidehopperOAM_ShakingHead[9];

extern const struct FrameData sSidehopperOAM_JumpWarning[6];

extern const struct FrameData sSidehopperOAM_Jumping[4];

extern const struct FrameData sSidehopperOAM_Landing[7];

#endif
