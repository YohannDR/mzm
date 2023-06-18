#ifndef CHOZO_STATUE_H
#define CHOZO_STATUE_H

#include "types.h"
#include "oam.h"

extern const s16 sChozoStatueMultiSpriteData_Standing_Frame0[15];

extern const s16 sChozoStatueMultiSpriteData_Sitting_Frame0[15];

extern const s16 sChozoStatueMultiSpriteData_Sitting_Frame1[15];

extern const s16 sChozoStatueMultiSpriteData_Sitting_Frame2[15];

extern const s16 sChozoStatueMultiSpriteData_Sitting_Frame3[15];

extern const s16 sChozoStatueMultiSpriteData_Sitting_Frame5[15];

extern const s16 sChozoStatueMultiSpriteData_Sitting_Frame6[15];

extern const s16 sChozoStatueMultiSpriteData_Sitting_Frame7[15];

extern const s16 sChozoStatueMultiSpriteData_Sitting_Frame8[15];

extern const s16 sChozoStatueMultiSpriteData_Sitting_Frame9[15];

extern const s16 sChozoStatueMultiSpriteData_Seated_Frame0[15];

extern const struct FrameData sChozoStatueMultiSpriteData_Standing[2];

extern const struct FrameData sChozoStatueMultiSpriteData_Sitting[11];

extern const struct FrameData sChozoStatueMultiSpriteData_Seated[2];

extern const u8 sChozoStatueFlashingPaletteRows[4];

extern const u32 sChozoStatueLongBeamGfx[1335];
extern const u16 sChozoStatueLongBeamPAL[80];

extern const u16 sChozoStatuePartOAM_LegStanding_Frame0[16];

extern const u16 sChozoStatuePartOAM_LegSitting_Frame0[16];

extern const u16 sChozoStatuePartOAM_LegSitting_Frame1[16];

extern const u16 sChozoStatuePartOAM_LegSitting_Frame2[16];

extern const u16 sChozoStatuePartOAM_LegSitting_Frame3[16];

extern const u16 sChozoStatuePartOAM_LegSitting_Frame5[13];

extern const u16 sChozoStatuePartOAM_LegSitting_Frame6[16];

extern const u16 sChozoStatuePartOAM_LegSitting_Frame7[16];

extern const u16 sChozoStatuePartOAM_LegSitting_Frame8[16];

extern const u16 sChozoStatuePartOAM_LegSeated_Frame0[19];

extern const u16 sChozoStatueOAM_Idle_Frame0[13];

extern const u16 sChozoStatuePartOAM_EyeClosing_Frame0[4];

extern const u16 sChozoStatuePartOAM_EyeClosing_Frame1[4];

extern const u16 sChozoStatuePartOAM_EyeClosed_Frame0[4];

extern const u16 sChozoStatuePartOAM_ArmIdle_Frame0[13];

extern const u16 sChozoStatuePartOAM_ArmGlow_Frame1[19];

extern const u16 sChozoStatuePartOAM_ArmGlow_Frame2[19];

extern const u16 sChozoStatuePartOAM_ArmGlow_Frame3[19];

extern const u16 sChozoStatuePartOAM_ArmGlow_Frame4[19];

extern const u16 sChozoStatuePartOAM_ArmSamusGrabbed_Frame0[13];

extern const u16 sChozoBallOAM_NormalClosed_Frame0[10];

extern const u16 sChozoBallOAM_NormalClosed_Frame1[10];

extern const u16 sChozoBallOAM_NormalClosed_Frame3[10];

extern const u16 sChozoBallOAM_NormalRevealing_Frame0[16];

extern const u16 sChozoBallOAM_NormalRevealing_Frame1[16];

extern const u16 sChozoBallOAM_NormalRevealing_Frame2[16];

extern const u16 sChozoBallOAM_NormalRevealed_Frame0[7];

extern const u16 sChozoBallOAM_NormalRevealed_Frame1[7];

extern const u16 sChozoBallOAM_NormalRevealed_Frame2[7];

extern const u16 sChozoStatueRefillOAM_Frame0[13];

extern const u16 sChozoStatueRefillOAM_Frame2[13];

extern const u16 sChozoStatueRefillOAM_Frame4[13];

extern const u16 sChozoStatueRefillOAM_Frame10[13];

extern const u16 sChozoStatueRefillOAM_Frame12[13];

extern const u16 sChozoStatueRefillOAM_Frame18[13];

extern const u16 sChozoStatueRefillOAM_Frame20[13];

extern const u16 sChozoStatueRefillOAM_Frame26[13];

extern const u16 sChozoStatueRefillOAM_Frame28[13];

extern const u16 sChozoStatueRefillOAM_Frame34[13];

extern const u16 sChozoStatuePartOAM_EyeOpened_Frame0[4];

extern const u16 sChozoStatuePartOAM_GlowIdle_Frame0[7];

extern const u16 sChozoStatuePartOAM_GlowIdle_Frame4[13];

extern const u16 sChozoStatuePartOAM_GlowIdle_Frame8[19];

extern const u16 sChozoStatuePartOAM_GlowIdle_Frame12[25];

extern const u16 sChozoStatuePartOAM_GlowIdle_Frame16[31];

extern const u16 sChozoStatuePartOAM_GlowIdle_Frame20[37];

extern const u16 sChozoStatuePartOAM_GlowIdle_Frame24[37];

extern const u16 sChozoStatuePartOAM_GlowIdle_Frame28[31];

extern const u16 sChozoStatuePartOAM_GlowIdle_Frame32[25];

extern const u16 sChozoStatuePartOAM_GlowIdle_Frame36[13];

extern const struct FrameData sChozoStatuePartOAM_LegStanding[2];

extern const struct FrameData sChozoStatuePartOAM_LegSitting[10];

extern const struct FrameData sChozoStatuePartOAM_LegSeated[2];

extern const struct FrameData sChozoStatueOAM_Idle[2];

extern const struct FrameData sChozoStatuePartOAM_EyeOpened[2];

extern const struct FrameData sChozoStatuePartOAM_EyeClosing[3];

extern const struct FrameData sChozoStatuePartOAM_EyeOpening[3];

extern const struct FrameData sChozoStatuePartOAM_EyeClosed[2];

extern const struct FrameData sChozoStatuePartOAM_ArmIdle[2];

extern const struct FrameData sChozoStatuePartOAM_ArmGlow[9];

extern const struct FrameData sChozoStatuePartOAM_ArmSamusGrabbed[2];

extern const struct FrameData sChozoBallOAM_NormalClosed[5];

extern const struct FrameData sChozoBallOAM_NormalRevealing[4];

extern const struct FrameData sChozoBallOAM_NormalRevealed[5];

extern const struct FrameData sChozoStatueRefillOAM[41];

extern const struct FrameData sChozoStatuePartOAM_GlowIdle[41];

extern const u32 sChozoStatueIceBeamGfx[1335];
extern const u16 sChozoStatueIceBeamPAL[80];

extern const u32 sChozoStatueWaveBeamGfx[1335];
extern const u16 sChozoStatueWaveBeamPAL[80];

extern const u32 sChozoStatueBombsGfx[1339];
extern const u16 sChozoStatueBombsPAL[80];

extern const u32 sChozoStatueSpeedboosterGfx[1342];
extern const u16 sChozoStatueSpeedboosterPAL[80];

extern const u32 sChozoStatueHighJumpGfx[1372];
extern const u16 sChozoStatueHighJumpPAL[80];

extern const u32 sChozoStatueScrewAttackGfx[1378];
extern const u16 sChozoStatueScrewAttackPAL[80];

extern const u32 sChozoStatueVariaGfx[1348];
extern const u16 sChozoStatueVariaPAL[80];

#endif