#ifndef RUINS_TEST_DATA_H
#define RUINS_TEST_DATA_H

#include "types.h"
#include "macros.h"
#include "oam.h"

extern const u32 sRuinsTestGFX[1951];
extern const u32 sRuinsTestGFX_SamusReflectionTurningRightTop[96];
extern const u32 sRuinsTestGFX_SamusReflectionTurningRightBottom[64];
extern const u32 sRuinsTestGFX_SamusReflectionTurningLeftTop[96];
extern const u32 sRuinsTestGFX_SamusReflectionTurningLeftBottom[64];
extern const u32 sRuinsTestGFX_SamusReflectionFullSuitTop[96];
extern const u32 sRuinsTestGFX_SamusReflectionFullSuitBottom[64];
extern const u32 sRuinsTestGFX_SamusReflectionSuitlessTop[96];
extern const u32 sRuinsTestGFX_SamusReflectionSuitlessBottom[64];
extern const u16 sRuinsTestPAL[128];
extern const u16 sRuinsTestPAL_SymbolShot_Frame1[8];
extern const u16 sRuinsTestPAL_SymbolShot_Frame2[8];
extern const u16 sRuinsTestPAL_SymbolShot_Frame3[8];
extern const u16 sRuinsTestPAL_SymbolShot_Frame4[8];
extern const u16 sRuinsTestPAL_SymbolShot_Frame5[8];
extern const u16 sRuinsTestPAL_SymbolShot_Frame6[8];
extern const u16 sRuinsTestPAL_SamusReflection[15 * 16];
extern const u16 sRuinsTestPAL_SamusReflectionFullSuit[15 * 16];

extern const u16 sRuinsTestSamusReflectionOAM_Frame0[10];

extern const u16 sRuinsTestGhostOAM_SymbolPlaced_Frame0[4];

extern const u16 sRuinsTestGhostOutline_Spawning_Frame0[37];

extern const u16 sRuinsTestGhostOutline_Spawning_Frame1[37];

extern const u16 sRuinsTestGhostOutline_Spawning_Frame2[37];

extern const u16 sRuinsTestGhostOutline_Spawning_Frame3[37];

extern const u16 sRuinsTestGhostOutline_Spawning_Frame4[37];

extern const u16 sRuinsTestGhostOAM_NotMoving_Frame0[76];

extern const u16 sRuinsTestGhostOAM_Moving_Frame1[58];

extern const u16 sRuinsTestGhostOAM_Moving_Frame2[76];

extern const u16 sRuinsTestGhostOAM_Moving_Frame3[76];

extern const u16 sRuinsTestSymbolOAM_FourSymbols_Frame0[13];

extern const u16 sRuinsTestSymbolOAM_FourSymbols_Frame1[37];

extern const u16 sRuinsTestSymbolOAM_FourSymbols_Frame2[37];

extern const u16 sRuinsTestSymbolOAM_FourSymbols_Frame3[37];

extern const u16 sRuinsTestSymbolOAM_FourSymbols_Frame4[37];

extern const u16 sRuinsTestSymbolOAM_FourSymbols_Frame5[37];

extern const u16 sRuinsTestSymbolOAM_FourSymbols_Frame6[37];

extern const u16 sRuinsTestSymbolOAM_FourSymbols_Frame7[37];

extern const u16 sRuinsTestSymbolOAM_FourSymbols_Frame10[49];

extern const u16 sRuinsTestSymbolOAM_FourSymbols_Frame11[61];

extern const u16 sRuinsTestSymbolOAM_FourSymbols_Frame12[73];

extern const u16 sRuinsTestSymbolOAM_Merging_Frame0[85];

extern const u16 sRuinsTestSymbolOAM_Merging_Frame1[85];

extern const u16 sRuinsTestSymbolOAM_Disappearing_Frame0[73];

extern const u16 sRuinsTestSymbolOAM_Disappearing_Frame1[61];

extern const u16 sRuinsTestSymbolOAM_Disappearing_Frame2[49];

extern const u16 sRuinsTestSymbolOAM_Disappearing_Frame3[25];

extern const u16 sRuinsTestSymbolOAM_Disappearing_Frame4[25];

extern const u16 sRuinsTestSymbolOAM_Disappearing_Frame5[25];

extern const u16 sRuinsTestOAM_TurningIntoReflection_Frame0[19];

extern const u16 sRuinsTestOAM_TurningIntoReflection_Frame1[19];

extern const u16 sRuinsTestOAM_TurningIntoReflection_Frame2[19];

extern const u16 sRuinsTestOAM_TurningIntoReflection_Frame3[19];

extern const u16 sRuinsTestOAM_TurningIntoReflection_Frame4[19];

extern const u16 sRuinsTestOAM_TurningIntoReflection_Frame5[40];

extern const u16 sRuinsTestOAM_TurningIntoReflection_Frame6[40];

extern const u16 sRuinsTestOAM_TurningIntoReflection_Frame7[13];

extern const u16 sRuinsTestOAM_TurningIntoReflection_Frame8[13];

extern const u16 sRuinsTestOAM_TurningIntoReflection_Frame9[13];

extern const u16 sRuinsTestOAM_TurningIntoReflection_Frame10[13];

extern const u16 sRuinsTestOAM_TurningIntoReflection_Frame11[13];

extern const u16 sRuinsTestReflectionCoverOAM_Frame0[16];

extern const u16 sRuinsTestReflectionCoverOAM_Frame1[4];

extern const u16 sRuinsTestOAM_Symbol_Frame0[13];

extern const u16 sRuinsTestOAM_Symbol_Frame1[13];

extern const u16 sRuinsTestOAM_Symbol_Frame2[13];

extern const u16 sRuinsTestOAM_Symbol_Frame3[13];

extern const u16 sRuinsTestShootableSymbolOAM_Spawning_Frame0[25];

extern const u16 sRuinsTestShootableSymbolOAM_Spawning_Frame1[25];

extern const u16 sRuinsTestShootableSymbolOAM_Spawning_Frame2[25];

extern const u16 sRuinsTestShootableSymbolOAM_Spawning_Frame3[25];

extern const u16 sRuinsTestShootableSymbolOAM_Spawning_Frame4[25];

extern const u16 sRuinsTestShootableSymbolOAM_Spawning_Frame5[25];

extern const u16 sRuinsTestShootableSymbolOAM_Spawning_Frame6[25];

extern const u16 sRuinsTestShootableSymbolOAM_TurningIntoSymbol_Frame3[13];

extern const u16 sRuinsTestShootableSymbolOAM_TurningIntoSymbol_Frame4[13];

extern const u16 sRuinsTestShootableSymbolOAM_TurningIntoSymbol_Frame5[10];

extern const u16 sRuinsTestShootableSymbolOAM_TurningIntoSymbol_Frame6[10];

extern const u16 sRuinsTestShootableSymbolOAM_TurningIntoSymbol_Frame7[10];

extern const u16 sRuinsTestGhostOAM_SymbolShot_Frame0[4];

extern const u16 sRuinsTestGhostOAM_SymbolPlacing_Frame3[10];

extern const u16 sRuinsTestGhostOAM_SymbolPlacing_Frame4[10];

extern const u16 sRuinsTestGhostOAM_SymbolPlacing_Frame5[10];

extern const u16 sRuinsTestGhostOAM_SymbolPlacing_Frame6[10];

extern const u16 sRuinsTestLightningOAM_InAir_Frame0[10];

extern const u16 sRuinsTestLightningOAM_InAir_Frame2[10];

extern const u16 sRuinsTestLightningOAM_InAir_Frame3[10];

extern const u16 sRuinsTestLightningOAM_InAir_Frame4[10];

extern const u16 sRuinsTestLightningOAM_InAir_Frame6[10];

extern const u16 sRuinsTestLightningOAM_InAir_Frame7[10];

extern const u16 sRuinsTestLightningOAM_InAir_Frame8[10];

extern const u16 sRuinsTestLightningOAM_InAir_Frame10[10];

extern const u16 sRuinsTestLightningOAM_InAir_Frame1[4];

extern const u16 sRuinsTestLightningOAM_GoingOnGround_Frame0[13];

extern const u16 sRuinsTestLightningOAM_GoingOnGround_Frame1[7];

extern const u16 sRuinsTestLightningOAM_GoingOnGround_Frame2[13];

extern const u16 sRuinsTestLightningOAM_GoingOnGround_Frame3[7];

extern const u16 sRuinsTestLightningOAM_GoingOnGround_Frame4[10];

extern const u16 sRuinsTestLightningOAM_GoingOnGround_Frame5[4];

extern const u16 sRuinsTestLightningOAM_GoingOnGround_Frame6[10];

extern const u16 sRuinsTestLightningOAM_GoingOnGround_Frame7[4];

extern const u16 sRuinsTestLightningOAM_OnGroundHorizontal_Frame0[7];

extern const u16 sRuinsTestLightningOAM_OnGroundHorizontal_Frame2[7];

extern const u16 sRuinsTestLightningOAM_OnGroundHorizontal_Frame4[7];

extern const u16 sRuinsTestLightningOAM_OnGroundHorizontal_Frame6[7];

extern const u16 sRuinsTestLightningOAM_OnGroundHorizontal_Frame8[7];

extern const u16 sRuinsTestLightningOAM_OnGroundHorizontal_Frame10[7];

extern const u16 sRuinsTestLightningOAM_OnGroundHorizontal_Frame12[7];

extern const u16 sRuinsTestLightningOAM_OnGroundHorizontal_Frame14[7];

extern const u16 sRuinsTestLightningOAM_OnGroundVertical_Frame0[7];

extern const u16 sRuinsTestLightningOAM_OnGroundVertical_Frame2[7];

extern const u16 sRuinsTestLightningOAM_OnGroundVertical_Frame4[7];

extern const u16 sRuinsTestLightningOAM_OnGroundVertical_Frame6[7];

extern const u16 sRuinsTestLightningOAM_OnGroundVertical_Frame8[7];

extern const u16 sRuinsTestLightningOAM_OnGroundVertical_Frame10[7];

extern const u16 sRuinsTestLightningOAM_OnGroundVertical_Frame12[7];

extern const u16 sRuinsTestLightningOAM_OnGroundVertical_Frame14[7];

extern const struct FrameData sRuinsTestSamusReflectionOAM[2];

extern const struct FrameData sRuinsTestGhostOutlineOAM_Spawning[9];

extern const struct FrameData sRuinsTestGhostOAM_NotMoving[2];

extern const struct FrameData sRuinsTestGhostOAM_Moving[7];

extern const struct FrameData sRuinsTestGhostOAM_SymbolPlaced[2];

extern const struct FrameData sRuinsTestSymbolOAM_FourSymbols[14];

extern const struct FrameData sRuinsTestSymbolOAM_Merging[3];

extern const struct FrameData sRuinsTestSymbolOAM_Disappearing[7];

extern const struct FrameData sRuinsTestOAM_TurningIntoReflection[13];

extern const struct FrameData sRuinsTestReflectionCoverOAM[3];

extern const struct FrameData sRuinsTestOAM_Symbol[5];

extern const struct FrameData sRuinsTestShootableSymbolOAM_Spawning[10];

extern const struct FrameData sRuinsTestShootableSymbolOAM_Spawned[7];

extern const struct FrameData sRuinsTestShootableSymbolOAM_Despawning[5];

extern const struct FrameData sRuinsTestShootableSymbolOAM_TurningIntoSymbol[9];

extern const struct FrameData sRuinsTestGhostOAM_SymbolShot[2];

extern const struct FrameData sRuinsTestGhostOAM_SymbolPlacing[14];

extern const struct FrameData sRuinsTestOAM_Despawn[6];

extern const struct FrameData sRuinsTestOAM_Unused[9];

extern const struct FrameData sRuinsTestOAM_Spawning[9];

extern const struct FrameData sRuinsTestLightningOAM_InAir[12];

extern const struct FrameData sRuinsTestLightningOAM_GoingOnGround[9];

extern const struct FrameData sRuinsTestLightningOAM_OnGroundHorizontal[17];

extern const struct FrameData sRuinsTestLightningOAM_OnGroundVertical[17];

extern const struct FrameData sRuinsTestGhostOutlineOAM_ShootingGroundLightning[9];

#endif