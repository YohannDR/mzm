#ifndef CROCOMIRE_DATA_H
#define CROCOMIRE_DATA_H

#include "types.h"
#include "oam.h"

extern const i16 sCrocomireMultiSpriteData_Idle_Frame0[18];

extern const i16 sCrocomireMultiSpriteData_Idle_Frame1[18];

extern const i16 sCrocomireMultiSpriteData_Screaming_Frame0[18];

extern const i16 sCrocomireMultiSpriteData_Screaming_Frame1[18];

extern const i16 sCrocomireMultiSpriteData_WalkingForward_Frame0[18];

extern const i16 sCrocomireMultiSpriteData_WalkingForward_Frame1[18];

extern const i16 sCrocomireMultiSpriteData_WalkingBackwards_Frame0[18];

extern const i16 sCrocomireMultiSpriteData_WalkingBackwards_Frame1[18];

extern const i16 sCrocomireMultiSpriteData_Dying_Frame0[18];

extern const i16 sCrocomireMultiSpriteData_Angry_Frame0[18];

extern const struct FrameData sCrocomireMultiSpriteData_Idle[3];

extern const struct FrameData sCrocomireMultiSpriteData_WalkingForward[3];

extern const struct FrameData sCrocomireMultiSpriteData_WalkingBackwards[3];

extern const struct FrameData sCrocomireMultiSpriteData_Screaming[3];

extern const struct FrameData sCrocomireMultiSpriteData_Dying[2];

extern const struct FrameData sCrocomireMultiSpriteData_Angry[2];

extern const u32 sCrocomireGFX[1954];
extern const u16 sCrocomirePAL[128];

extern const u16 sCrocomireOAM_Screaming_Frame1[22];

extern const u16 sCrocomireOAM_Screaming_Frame2[22];

extern const u16 sCrocomireOAM_Screaming_Frame0[19];

extern const u16 sCrocomireOAM_Idle_Frame0[25];

extern const u16 sCrocomireOAM_Idle_Frame1[25];

extern const u16 sCrocomireOAM_Idle_Frame2[25];

extern const u16 sCrocomirePartOAM_BodyIdle_Frame0[19];

extern const u16 sCrocomirePartOAM_BodyIdle_Frame1[25];

extern const u16 sCrocomirePartOAM_BodyIdle_Frame2[25];

extern const u16 sCrocomirePartOAM_Tongue_Frame0[7];

extern const u16 sCrocomirePartOAM_Tongue_Frame1[7];

extern const u16 sCrocomirePartOAM_Tongue_Frame2[7];

extern const u16 sCrocomirePartoAM_LeftArmScreaming_Frame1[19];

extern const u16 sCrocomirePartoAM_LeftArmScreaming_Frame0[19];

extern const u16 sCrocomirePartOAM_LeftArmWalkingForward_Frame6[19];

extern const u16 sCrocomirePartOAM_LeftArmWalkingForward_Frame5[19];

extern const u16 sCrocomirePartOAM_LeftArmWalkingForward_Frame4[19];

extern const u16 sCrocomirePartOAM_LeftArmWalkingForward_Frame3[19];

extern const u16 sCrocomirePartOAM_LeftArmWalkingForward_Frame2[19];

extern const u16 sCrocomirePartOAM_LeftArmWalkingForward_Frame1[19];

extern const u16 sCrocomirePartOAM_LeftArmIdle_Frame2[19];

extern const u16 sCrocomirePartOAM_LeftArmWalkingForward_Frame16[19];

extern const u16 sCrocomirePartOAM_LeftArmIdle_Frame1[19];

extern const u16 sCrocomirePartOAM_LeftArmIdle_Frame0[19];

extern const u16 sCrocomirePartOAM_LeftArmWalkingForward_Frame13[19];

extern const u16 sCrocomirePartOAM_LeftArmWalkingForward_Frame12[19];

extern const u16 sCrocomirePartOAM_LeftArmWalkingForward_Frame11[19];

extern const u16 sCrocomirePartOAM_LeftArmWalkingForward_Frame10[19];

extern const u16 sCrocomirePartOAM_LeftArmWalkingForward_Frame9[19];

extern const u16 sCrocomirePartOAM_LegsDying_Frame0[43];

extern const u16 sCrocomirePartOAM_LegsDying_Frame1[43];

extern const u16 sCrocomirePartOAM_LegsDying_Frame2[43];

extern const u16 sCrocomirePartOAM_LegsDying_Frame3[43];

extern const u16 sCrocomirePartOAM_LegsDying_Frame4[43];

extern const u16 sCrocomirePartOAM_LegsIdle_Frame1[43];

extern const u16 sCrocomirePartOAM_LegsIdle_Frame0[43];

extern const u16 sCrocomirePartOAM_LegsWalkingForward_Frame1[43];

extern const u16 sCrocomirePartOAM_LegsWalkingForward_Frame2[43];

extern const u16 sCrocomirePartOAM_LegsWalkingForward_Frame3[43];

extern const u16 sCrocomirePartOAM_LegsWalkingForward_Frame4[43];

extern const u16 sCrocomirePartOAM_LegsWalkingForward_Frame5[43];

extern const u16 sCrocomirePartOAM_LegsWalkingForward_Frame6[43];

extern const u16 sCrocomirePartOAM_LegsWalkingBackwards_Frame0[43];

extern const u16 sCrocomirePartOAM_LegsWalkingBackwards_Frame1[43];

extern const u16 sCrocomirePartOAM_LegsWalkingBackwards_Frame2[43];

extern const u16 sCrocomirePartOAM_LegsWalkingBackwards_Frame3[43];

extern const u16 sCrocomirePartOAM_LegsWalkingBackwards_Frame4[43];

extern const u16 sCrocomirePartOAM_LegsWalkingBackwards_Frame5[43];

extern const u16 sCrocomirePartOAM_LegsWalkingBackwards_Frame6[43];

extern const u16 sCrocomirePartOAM_LegsWalkingBackwards_Frame7[43];

extern const u16 sCrocomireProjectileOAM_Frame0[4];

extern const struct FrameData sCrocomirePartOAM_BodyIdle[5];

extern const struct FrameData sCrocomirePartOAM_BodyAngry[5];

extern const struct FrameData sCrocomireOAM_Idle[5];

extern const struct FrameData sCrocomireOAM_Screaming[9];

extern const struct FrameData sCrocomireOAM_Dying[3];

extern const struct FrameData sCrocomirePartOAM_RightArmIdle[5];

extern const struct FrameData sCrocomirePartOAM_LeftArmIdle[5];

extern const struct FrameData sCrocomirePartOAM_LeftArmScreaming[3];

extern const struct FrameData sCrocomirePartOAM_RightArmWalkingForward[18];

extern const struct FrameData sCrocomirePartOAM_LeftArmWalkingForward[18];

extern const struct FrameData sCrocomirePartOAM_RightArmWalkingBackwards[18];

extern const struct FrameData sCrocomirePartOAM_LeftArmWalkingBackwards[18];

extern const struct FrameData sCrocomirePartOAM_RightArmDying[3];

extern const struct FrameData sCrocomirePartOAM_LeftArmDying[3];

extern const struct FrameData sCrocomirePartOAM_LegsIdle[3];

extern const struct FrameData sCrocomirePartOAM_LegsWalkingForward[8];

extern const struct FrameData sCrocomirePartOAM_LegsWalkingBackwards[9];

extern const struct FrameData sCrocomirePartOAM_LegsDying[7];

extern const struct FrameData sCrocomirePartOAM_Tongue[5];

extern const struct FrameData sCrocomirePartOAM_TongueDying[5];

extern const struct FrameData sCrocomireProjectileOAM[2];

extern const struct FrameData sCrocomirePartOAM_307028[6];

extern const struct FrameData sCrocomirePartOAM_307058[6];

extern const struct FrameData sCrocomirePartOAM_307088[6];

extern const struct FrameData sCrocomirePartOAM_3070b8[6];

#endif