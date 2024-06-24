#ifndef BARISTUTE_DATA_H
#define BARISTUTE_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sBaristuteFallingYVelocity[8];

extern const s16 sBaristuteJumpingYVelocity[10];

extern const u32 sBaristuteGfx[596];
extern const u16 sBaristutePal[80];

extern const u16 sBaristuteOam_Idle_Frame0[49];

extern const u16 sBaristuteOam_Walking_Frame1[52];

extern const u16 sBaristuteOam_Walking_Frame2[52];

extern const u16 sBaristuteOam_Walking_Frame3[52];

extern const u16 sBaristuteOam_Walking_Frame4[52];

extern const u16 sBaristuteOam_Walking_Frame5[49];

extern const u16 sBaristuteOam_Warning_Frame1[55];

extern const u16 sBaristuteOam_Warning_Frame2[55];

extern const u16 sBaristuteOam_Jumping_Frame0[49];

extern const u16 sBaristuteOam_Jumping_Frame1[49];

extern const u16 sBaristuteOam_Idle_Frame2[61];

extern const u16 sBaristuteOam_Idle_Frame1[55];

extern const struct FrameData sBaristuteOam_Idle[5];

extern const struct FrameData sBaristuteOam_Warning[4];

extern const struct FrameData sBaristuteOam_Jumping[3];

extern const struct FrameData sBaristuteOam_Landing[4];

extern const struct FrameData sBaristuteOam_WalkingSlow[7];

extern const struct FrameData sBaristuteOam_WalkingFast[7];

extern const struct FrameData sBaristuteOam_WalkingVeryFast[7];

extern const struct FrameData sBaristuteOam_WalkingExtremelyFast[7];

#endif