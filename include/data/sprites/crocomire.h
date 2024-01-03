#ifndef CROCOMIRE_DATA_H
#define CROCOMIRE_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sCrocomireMultiSpriteData_Idle_Frame0[18];

extern const s16 sCrocomireMultiSpriteData_Idle_Frame1[18];

extern const s16 sCrocomireMultiSpriteData_Screaming_Frame0[18];

extern const s16 sCrocomireMultiSpriteData_Screaming_Frame1[18];

extern const s16 sCrocomireMultiSpriteData_WalkingForward_Frame0[18];

extern const s16 sCrocomireMultiSpriteData_WalkingForward_Frame1[18];

extern const s16 sCrocomireMultiSpriteData_WalkingBackwards_Frame0[18];

extern const s16 sCrocomireMultiSpriteData_WalkingBackwards_Frame1[18];

extern const s16 sCrocomireMultiSpriteData_Dying_Frame0[18];

extern const s16 sCrocomireMultiSpriteData_Angry_Frame0[18];

extern const struct FrameData sCrocomireMultiSpriteData_Idle[3];

extern const struct FrameData sCrocomireMultiSpriteData_WalkingForward[3];

extern const struct FrameData sCrocomireMultiSpriteData_WalkingBackwards[3];

extern const struct FrameData sCrocomireMultiSpriteData_Screaming[3];

extern const struct FrameData sCrocomireMultiSpriteData_Dying[2];

extern const struct FrameData sCrocomireMultiSpriteData_Angry[2];

extern const u32 sCrocomireGfx[1954];
extern const u16 sCrocomirePal[128];

extern const u16 sCrocomireOam_Screaming_Frame1[22];

extern const u16 sCrocomireOam_Screaming_Frame2[22];

extern const u16 sCrocomireOam_Screaming_Frame0[19];

extern const u16 sCrocomireOam_Idle_Frame0[25];

extern const u16 sCrocomireOam_Idle_Frame1[25];

extern const u16 sCrocomireOam_Idle_Frame2[25];

extern const u16 sCrocomirePartOam_BodyIdle_Frame0[19];

extern const u16 sCrocomirePartOam_BodyIdle_Frame1[25];

extern const u16 sCrocomirePartOam_BodyIdle_Frame2[25];

extern const u16 sCrocomirePartOam_Tongue_Frame0[7];

extern const u16 sCrocomirePartOam_Tongue_Frame1[7];

extern const u16 sCrocomirePartOam_Tongue_Frame2[7];

extern const u16 sCrocomirePartOam_LeftArmScreaming_Frame1[19];

extern const u16 sCrocomirePartOam_LeftArmScreaming_Frame0[19];

extern const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame6[19];

extern const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame5[19];

extern const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame4[19];

extern const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame3[19];

extern const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame2[19];

extern const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame1[19];

extern const u16 sCrocomirePartOam_LeftArmIdle_Frame2[19];

extern const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame16[19];

extern const u16 sCrocomirePartOam_LeftArmIdle_Frame1[19];

extern const u16 sCrocomirePartOam_LeftArmIdle_Frame0[19];

extern const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame13[19];

extern const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame12[19];

extern const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame11[19];

extern const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame10[19];

extern const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame9[19];

extern const u16 sCrocomirePartOam_LegsDying_Frame0[43];

extern const u16 sCrocomirePartOam_LegsDying_Frame1[43];

extern const u16 sCrocomirePartOam_LegsDying_Frame2[43];

extern const u16 sCrocomirePartOam_LegsDying_Frame3[43];

extern const u16 sCrocomirePartOam_LegsDying_Frame4[43];

extern const u16 sCrocomirePartOam_LegsIdle_Frame1[43];

extern const u16 sCrocomirePartOam_LegsIdle_Frame0[43];

extern const u16 sCrocomirePartOam_LegsWalkingForward_Frame1[43];

extern const u16 sCrocomirePartOam_LegsWalkingForward_Frame2[43];

extern const u16 sCrocomirePartOam_LegsWalkingForward_Frame3[43];

extern const u16 sCrocomirePartOam_LegsWalkingForward_Frame4[43];

extern const u16 sCrocomirePartOam_LegsWalkingForward_Frame5[43];

extern const u16 sCrocomirePartOam_LegsWalkingForward_Frame6[43];

extern const u16 sCrocomirePartOam_LegsWalkingBackwards_Frame0[43];

extern const u16 sCrocomirePartOam_LegsWalkingBackwards_Frame1[43];

extern const u16 sCrocomirePartOam_LegsWalkingBackwards_Frame2[43];

extern const u16 sCrocomirePartOam_LegsWalkingBackwards_Frame3[43];

extern const u16 sCrocomirePartOam_LegsWalkingBackwards_Frame4[43];

extern const u16 sCrocomirePartOam_LegsWalkingBackwards_Frame5[43];

extern const u16 sCrocomirePartOam_LegsWalkingBackwards_Frame6[43];

extern const u16 sCrocomirePartOam_LegsWalkingBackwards_Frame7[43];

extern const u16 sCrocomireProjectileOAM_Frame0[4];

extern const struct FrameData sCrocomirePartOam_BodyIdle[5];

extern const struct FrameData sCrocomirePartOam_BodyAngry[5];

extern const struct FrameData sCrocomireOam_Idle[5];

extern const struct FrameData sCrocomireOam_Screaming[9];

extern const struct FrameData sCrocomireOam_Dying[3];

extern const struct FrameData sCrocomirePartOam_RightArmIdle[5];

extern const struct FrameData sCrocomirePartOam_LeftArmIdle[5];

extern const struct FrameData sCrocomirePartOam_LeftArmScreaming[3];

extern const struct FrameData sCrocomirePartOam_RightArmWalkingForward[18];

extern const struct FrameData sCrocomirePartOam_LeftArmWalkingForward[18];

extern const struct FrameData sCrocomirePartOam_RightArmWalkingBackwards[18];

extern const struct FrameData sCrocomirePartOam_LeftArmWalkingBackwards[18];

extern const struct FrameData sCrocomirePartOam_RightArmDying[3];

extern const struct FrameData sCrocomirePartOam_LeftArmDying[3];

extern const struct FrameData sCrocomirePartOam_LegsIdle[3];

extern const struct FrameData sCrocomirePartOam_LegsWalkingForward[8];

extern const struct FrameData sCrocomirePartOam_LegsWalkingBackwards[9];

extern const struct FrameData sCrocomirePartOam_LegsDying[7];

extern const struct FrameData sCrocomirePartOam_Tongue[5];

extern const struct FrameData sCrocomirePartOam_TongueDying[5];

extern const struct FrameData sCrocomireProjectileOAM[2];

extern const struct FrameData sCrocomirePartOam_307028[6];

extern const struct FrameData sCrocomirePartOam_307058[6];

extern const struct FrameData sCrocomirePartOam_307088[6];

extern const struct FrameData sCrocomirePartOam_3070b8[6];

#endif