#ifndef SEARCHLIGHT_EYE_DATA_H
#define SEARCHLIGHT_EYE_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sSearchlightEyeGfx[177];
extern const u16 sSearchlightEyePAL[16];

extern const u16 sSearchlightEyeOAM_Idle_Frame0[10];

extern const u16 sSearchlightEyeOAM_Idle_Frame1[10];

extern const u16 sSearchlightEyeOAM_Idle_Frame2[10];

extern const u16 sSearchlightEyeOAM_Idle_Frame10[10];

extern const u16 sSearchlightEyeBeamOAM_Idle_Frame0[22];

extern const u16 sSearchlightEyeBeamOAM_Idle_Frame2[22];

extern const u16 sSearchlightEyeBeamOAM_Idle_Frame1[4];

extern const u16 sSearchlightEyeBeamOAM_Unused_Frame0[4];

extern const u16 sSearchlightEyeProjectileOAM_Moving_Frame0[25];

extern const u16 sSearchlightEyeProjectileOAM_Moving_Frame2[25];

extern const u16 sSearchlightEyeProjectileOAM_Moving_Frame4[25];

extern const u16 sSearchlightEyeProjectileOAM_Moving_Frame6[25];

extern const u16 sSearchlightEyeOAM_Shooting_Frame1[10];

extern const u16 sSearchlightEyeOAM_Shooting_Frame2[10];

extern const struct FrameData sSearchlightEyeOAM_Idle[13];

extern const struct FrameData sSearchlightEyeBeamOAM_Idle[5];

extern const struct FrameData sSearchlightEyeBeamOAM_Unused[2];

extern const struct FrameData sSearchlightEyeProjectileOAM_Moving[9];

extern const struct FrameData sSearchlightEyeOAM_Shooting[4];

#endif
