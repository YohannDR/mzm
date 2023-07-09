#ifndef POLYP_DATA_H
#define POLYP_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sPolypProjectileYVelocity[44];

extern const u32 sPolypGfx[241];
extern const u16 sPolypPAL[16];

extern const u16 sPolypOam_Idle_Frame0[13];

extern const u16 sPolypOam_Idle_Frame1[13];

extern const u16 sPolypOam_Idle_Frame2[13];

extern const u16 sPolypOam_Warning_Frame3[13];

extern const u16 sPolypOam_Warning_Frame2[13];

extern const u16 sPolypOam_Warning_Frame1[13];

extern const u16 sPolypOam_Warning_Frame0[13];

extern const u16 sPolypOam_AfterSpitting_Frame2[16];

extern const u16 sPolypProjectileOam_Right_Frame0[4];

extern const u16 sPolypProjectileOam_Right_Frame1[4];

extern const u16 sPolypProjectileOam_Right_Frame2[4];

extern const u16 sPolypProjectileOam_Right_Frame3[4];

extern const u16 sPolypProjectileOam_Left_Frame0[4];

extern const u16 sPolypProjectileOam_Left_Frame1[4];

extern const u16 sPolypProjectileOam_Left_Frame2[4];

extern const u16 sPolypProjectileOam_Left_Frame3[4];

extern const u16 sPolypProjectileOam_Exploding_Frame0[4];

extern const u16 sPolypProjectileOam_Exploding_Frame1[4];

extern const u16 sPolypProjectileOam_Exploding_Frame2[4];

extern const u16 sPolypProjectileOam_Exploding_Frame3[4];

extern const struct FrameData sPolypOam_Idle[5];

extern const struct FrameData sPolypOam_Warning[5];

extern const struct FrameData sPolypOam_Spitting[2];

extern const struct FrameData sPolypOam_AfterSpitting[4];

extern const struct FrameData sPolypOam_Retracting[3];

extern const struct FrameData sPolypProjectileOam_Right[5];

extern const struct FrameData sPolypProjectileOam_Left[5];

extern const struct FrameData sPolypProjectileOam_Exploding[5];

#endif