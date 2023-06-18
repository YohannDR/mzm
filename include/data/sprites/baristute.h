#ifndef BARISTUTE_DATA_H
#define BARISTUTE_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sBaristuteFallingYVelocity[8];

extern const s16 sBaristuteJumpingYVelocity[10];

extern const u32 sBaristuteGfx[596];
extern const u16 sBaristutePAL[80];

extern const u16 sBaristuteOAM_Idle_Frame0[49];

extern const u16 sBaristuteOAM_Walking_Frame1[52];

extern const u16 sBaristuteOAM_Walking_Frame2[52];

extern const u16 sBaristuteOAM_Walking_Frame3[52];

extern const u16 sBaristuteOAM_Walking_Frame4[52];

extern const u16 sBaristuteOAM_Walking_Frame5[49];

extern const u16 sBaristuteOAM_Warning_Frame1[55];

extern const u16 sBaristuteOAM_Warning_Frame2[55];

extern const u16 sBaristuteOAM_Jumping_Frame0[49];

extern const u16 sBaristuteOAM_Jumping_Frame1[49];

extern const u16 sBaristuteOAM_Idle_Frame2[61];

extern const u16 sBaristuteOAM_Idle_Frame1[55];

extern const struct FrameData sBaristuteOAM_Idle[5];

extern const struct FrameData sBaristuteOAM_Warning[4];

extern const struct FrameData sBaristuteOAM_Jumping[3];

extern const struct FrameData sBaristuteOAM_Landing[4];

extern const struct FrameData sBaristuteOAM_WalkingSlow[7];

extern const struct FrameData sBaristuteOAM_WalkingFast[7];

extern const struct FrameData sBaristuteOAM_WalkingVeryFast[7];

extern const struct FrameData sBaristuteOAM_WalkingExtremelyFast[7];

#endif