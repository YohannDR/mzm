#ifndef CHARGE_BEAM_DATA_H
#define CHARGE_BEAM_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sChargeBeamIdleYMovement[66];

extern const u32 sChargeBeamGfx[243];
extern const u16 sChargeBeamPAL[16];

extern const u16 sChargeBeamOAM_Visible_Frame0[4];

extern const u16 sChargeBeamOAM_Visible_Frame1[4];

extern const u16 sChargeBeamOAM_Visible_Frame2[7];

extern const u16 sChargeBeamGlowOAM_Idle_Frame0[10];

extern const u16 sChargeBeamGlowOAM_Idle_Frame2[10];

extern const u16 sChargeBeamGlowOAM_Idle_Frame4[10];

extern const u16 sChargeBeamGlowOAM_Idle_Frame6[10];

extern const u16 sChargeBeamGlowOAM_Idle_Frame1[4];

extern const u16 sChargeBeamOAM_Spawning_Frame0[13];

extern const u16 sChargeBeamOAM_Spawning_Frame1[28];

extern const u16 sChargeBeamOAM_Spawning_Frame2[28];

extern const u16 sChargeBeamOAM_Spawning_Frame3[40];

extern const u16 sChargeBeamOAM_Spawning_Frame4[43];

extern const u16 sChargeBeamOAM_Spawning_Frame8[49];

extern const u16 sChargeBeamOAM_Spawning_Frame9[49];

extern const u16 sChargeBeamOAM_Spawning_Frame10[52];

extern const u16 sChargeBeamOAM_Spawning_Frame11[4];

extern const struct FrameData sChargeBeamOAM_Visible[5];

extern const struct FrameData sChargeBeamOAM_Spawning[13];

extern const struct FrameData sChargeBeamGlowOAM_Idle[15];

#endif
