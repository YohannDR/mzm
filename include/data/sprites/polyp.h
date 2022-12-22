#ifndef POLYP_DATA_H
#define POLYP_DATA_H

#include "types.h"
#include "oam.h"

extern const i16 sPolypProjectileYVelocity[44];

extern const u32 sPolypGFX[241];
extern const u16 sPolypPAL[16];

extern const u16 sPolypOAM_Idle_Frame0[13];

extern const u16 sPolypOAM_Idle_Frame1[13];

extern const u16 sPolypOAM_Idle_Frame2[13];

extern const u16 sPolypOAM_Warning_Frame3[13];

extern const u16 sPolypOAM_Warning_Frame2[13];

extern const u16 sPolypOAM_Warning_Frame1[13];

extern const u16 sPolypOAM_Warning_Frame0[13];

extern const u16 sPolypOAM_AfterSpitting_Frame2[16];

extern const u16 sPolypProjectileOAM_Right_Frame0[4];

extern const u16 sPolypProjectileOAM_Right_Frame1[4];

extern const u16 sPolypProjectileOAM_Right_Frame2[4];

extern const u16 sPolypProjectileOAM_Right_Frame3[4];

extern const u16 sPolypProjectileOAM_Left_Frame0[4];

extern const u16 sPolypProjectileOAM_Left_Frame1[4];

extern const u16 sPolypProjectileOAM_Left_Frame2[4];

extern const u16 sPolypProjectileOAM_Left_Frame3[4];

extern const u16 sPolypProjectileOAM_Exploding_Frame0[4];

extern const u16 sPolypProjectileOAM_Exploding_Frame1[4];

extern const u16 sPolypProjectileOAM_Exploding_Frame2[4];

extern const u16 sPolypProjectileOAM_Exploding_Frame3[4];

extern const struct FrameData sPolypOAM_Idle[5];

extern const struct FrameData sPolypOAM_Warning[5];

extern const struct FrameData sPolypOAM_Spitting[2];

extern const struct FrameData sPolypOAM_AfterSpitting[4];

extern const struct FrameData sPolypOAM_Retracting[3];

extern const struct FrameData sPolypProjectileOAM_Right[5];

extern const struct FrameData sPolypProjectileOAM_Left[5];

extern const struct FrameData sPolypProjectileOAM_Exploding[5];

#endif