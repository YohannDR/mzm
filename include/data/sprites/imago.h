#ifndef IMAGO_DATA_H
#define IMAGO_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sImagoMultiSpriteData_Idle_Frame0[21];

extern const s16 sImagoMultiSpriteData_Growling_Unused_Frame0[21];

extern const s16 sImagoMultiSpriteData_ShootingNeedles_Frame0[21];

extern const s16 sImagoMultiSpriteData_ShootingNeedles_Frame1[21];

extern const s16 sImagoMultiSpriteData_RechargingNeedles_Frame0[21];

extern const s16 sImagoMultiSpriteData_Dying_Frame0[21];

extern const struct FrameData sImagoMultiSpriteData_Idle[2];

extern const struct FrameData sImagoMultiSpriteData_Growling_Unused[2];

extern const struct FrameData sImagoMultiSpriteData_ShootingNeedles[3];

extern const struct FrameData sImagoMultiSpriteData_RechargingNeedles[2];

extern const struct FrameData sImagoMultiSpriteData_Dying[2];

extern const s16 sImagoDamagedStingerFallingYVelocity[10];

extern const s16 sImagoAttackingXVelocity[49];

extern const u8 sImagoDynamicPaletteData[9][2];

extern const u32 sImagoGfx[1503];
extern const u16 sImagoPAL[96];

extern const u16 sImagoPartOAM_BodyIdle_Frame0[55];

extern const u16 sImagoPartOAM_BodyIdle_Frame1[55];

extern const u16 sImagoPartOAM_BodyIdle_Frame2[55];

extern const u16 sImagoPartOAM_BodyIdle_Frame4[55];

extern const u16 sImagoOAM_BrokenStinger_Frame0[13];

extern const u16 sImagoOAM_BrokenStinger_Frame1[16];

extern const u16 sImagoPartOAM_BodyIdle_Frame3[55];

extern const u16 sImagoPartOAM_BodyGrowling_Frame2[55];

extern const u16 sImagoPartOAM_BodyGrowling_Frame3[55];

extern const u16 sImagoPartOAM_BodyGrowling_Frame4[55];

extern const u16 sImagoPartOAM_LeftWingIdle_Frame0[7];

extern const u16 sImagoPartOAM_LeftWingIdle_Frame1[7];

extern const u16 sImagoPartOAM_LeftWingIdle_Frame2[7];

extern const u16 sImagoPartOAM_LeftWingIdle_Frame4[10];

extern const u16 sImagoPartOAM_LeftWingIdle_Frame3[7];

extern const u16 sImagoPartOAM_RightWingIdle_Frame0[7];

extern const u16 sImagoPartOAM_RightWingIdle_Frame1[7];

extern const u16 sImagoPartOAM_RightWingIdle_Frame2[7];

extern const u16 sImagoPartOAM_RightWingIdle_Frame4[10];

extern const u16 sImagoPartOAM_RightWingIdle_Frame3[7];

extern const u16 sImagoPartOAM_Core_Frame0[4];

extern const u16 sImagoPartOAM_Core_Frame1[25];

extern const u16 sImagoPartOAM_Core_Frame2[25];

extern const u16 sImagoOAM_Flying_Frame0[22];

extern const u16 sImagoOAM_Flying_Frame1[22];

extern const u16 sImagoOAM_Flying_Frame2[22];

extern const u16 sImagoOAM_Flying_Frame4[22];

extern const u16 sImagoOAM_Flying_Frame3[22];

extern const u16 sImagoOAM_ShootingNeedles_Frame2[22];

extern const u16 sImagoOAM_ShootingNeedles_Frame3[22];

extern const u16 sImagoOAM_ShootingNeedles_Frame4[22];

extern const u16 sImagoOAM_ShootingNeedles_Frame9[19];

extern const u16 sImagoNeedleOAM_Frame0[4];

extern const u16 sImagoOAM_RechargingNeedles_Frame0[25];

extern const u16 sImagoOAM_RechargingNeedles_Frame1[25];

extern const u16 sImagoOAM_RechargingNeedles_Frame2[25];

extern const u16 sImagoDamagedStingerOAM_Frame0[28];

extern const u16 sImagoEggOAM_Standing_Frame0[7];

extern const u16 sImagoEggOAM_Breaking_Frame1[10];

extern const u16 sImagoEggOAM_Breaking_Frame2[10];

extern const u16 sImagoEggOAM_Breaking_Frame3[10];

extern const u16 sImagoEggOAM_Breaking_Frame4[10];

extern const u16 sImagoEggOAM_Breaking_Frame5[10];

extern const u16 sImagoEggOAM_Breaking_Frame6[10];

extern const u16 sImagoEggOAM_Breaking_Frame7[10];

extern const u16 sImagoEggOAM_Breaking_Frame8[10];

extern const struct FrameData sImagoPartOAM_BodyIdle[8];

extern const struct FrameData sImagoPartOAM_BodyGrowling[16];

extern const struct FrameData sImagoOAM_BrokenStinger[3];

extern const struct FrameData sImagoPartOAM_LeftWingIdle[8];

extern const struct FrameData sImagoPartOAM_LeftWingShootingNeedles[6];

extern const struct FrameData sImagoPartOAM_LeftWingDying[7];

extern const struct FrameData sImagoPartOAM_RightWingIdle[8];

extern const struct FrameData sImagoPartOAM_RightWingShootingNeedles[6];

extern const struct FrameData sImagoPartOAM_RIghtWingDying[5];

extern const struct FrameData sImagoPartOAM_Core[9];

extern const struct FrameData simagoOAM_Flying[9];

extern const struct FrameData sImagoOAM_ShootingNeedles[11];

extern const struct FrameData sImagoOAM_RechargingNeedles[4];

extern const struct FrameData sImagoDamagedStingerOAM[2];

extern const struct FrameData sImagoNeedleOAM[2];

extern const struct FrameData sImagoDamagedStingerOAM_Unused[9];

extern const struct FrameData sImagoEggOAM_Breaking[10];

extern const struct FrameData sImagoEggOAM_Standing[2];

#endif