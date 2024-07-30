#ifndef MECHA_RIDLEY_DATA_H
#define MECHA_RIDLEY_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

enum MechaRidleyOam {
    MECHA_RIDLEY_OAM_TAIL,
    MECHA_RIDLEY_OAM_RING,
    MECHA_RIDLEY_OAM_COVER,
    MECHA_RIDLEY_OAM_TORSO,
    MECHA_RIDLEY_OAM_CORE_IDLE,
    MECHA_RIDLEY_OAM_HEAD_IDLE,
    MECHA_RIDLEY_OAM_HEAD_OPENING_MOUTH,
    MECHA_RIDLEY_OAM_HEAD_SPITTING_FIREBALLS,
    MECHA_RIDLEY_OAM_HEAD_CLOSING_MOUTH,
    MECHA_RIDLEY_OAM_EYE_IDLE,
    MECHA_RIDLEY_OAM_EYE_GLOWING,
    MECHA_RIDLEY_OAM_EYE_SHOOTING_LASER_FORWARD,
    MECHA_RIDLEY_OAM_EYE_SHOOTING_LASER_SLIGHTLY_DOWN,
    MECHA_RIDLEY_OAM_EYE_SHOOTING_LASER_DOWN,
    MECHA_RIDLEY_OAM_EYE_SHOOTING_LASER_SLIGHTLY_UP,
    MECHA_RIDLEY_OAM_EYE_SHOOTING_LASER_UP,
    MECHA_RIDLEY_OAM_EYE_INACTIVE,
    MECHA_RIDLEY_OAM_LEFT_ARM_CRAWLING_FORWARD,
    MECHA_RIDLEY_OAM_RIGHT_ARM_CRAWLING_FORWARD,
    MECHA_RIDLEY_OAM_LEFT_ARM_HOLDING_UP,
    MECHA_RIDLEY_OAM_RIGHT_ARM_HOLDING_UP,
    MECHA_RIDLEY_OAM_LEFT_ARM_HELD_UP,
    MECHA_RIDLEY_OAM_RIGHT_ARM_HELD_UP,
    MECHA_RIDLEY_OAM_LEFT_ARM_LAYING_DOWN,
    MECHA_RIDLEY_OAM_RIGHT_ARM_LAYING_DOWN,
    MECHA_RIDLEY_OAM_LEFT_ARM_TREMBLING,
    MECHA_RIDLEY_OAM_RIGHT_ARM_TREMBLING,
    MECHA_RIDLEY_OAM_LEFT_ARM_IDLE,
    MECHA_RIDLEY_OAM_RIGHT_ARM_IDLE,
    MECHA_RIDLEY_OAM_LEFT_ARM_SWINGING,
    MECHA_RIDLEY_OAM_NECK_LOW,
    MECHA_RIDLEY_OAM_NECK_MIDDLE,
    MECHA_RIDLEY_OAM_NECK_HIGH,
    MECHA_RIDLEY_OAM_NECK_ROTATE_LOW,
    MECHA_RIDLEY_OAM_NECK_ROTATE_MIDDLE,
    MECHA_RIDLEY_OAM_NECK_ROTATE_HIGH,
    MECHA_RIDLEY_OAM_NECK_LOW_TO_MIDDLE,
    MECHA_RIDLEY_OAM_NECK_MIDDLE_TO_HIGH,
    MECHA_RIDLEY_OAM_NECK_HIGH_TO_MIDDLE,
    MECHA_RIDLEY_OAM_NECK_MIDDLE_TO_LOW,
    MECHA_RIDLEY_OAM_NECK_LOW_TO_HIGH,
    MECHA_RIDLEY_OAM_NECK_HIGH_TO_LOW,
    MECHA_RIDLEY_OAM_NECK_LOW_2,
    MECHA_RIDLEY_OAM_NECK_MIDDLE_2,
    MECHA_RIDLEY_OAM_NECK_HIGH_2,
    MECHA_RIDLEY_OAM_MISSILE_LAUNCHER_CLOSED,
    MECHA_RIDLEY_OAM_MISSILE_LAUNCHER_OPENING,
    MECHA_RIDLEY_OAM_MISSILE_LAUNCHER_OPENED,
    MECHA_RIDLEY_OAM_MISSILE_LAUNCHER_CLOSING,
    MECHA_RIDLEY_OAM_MISSILE,
    MECHA_RIDLEY_OAM_FIREBALL,
    MECHA_RIDLEY_OAM_LASER_FORWARD,
    MECHA_RIDLEY_OAM_LASER_SLIGHTLY_DOWN,
    MECHA_RIDLEY_OAM_LASER_DOWN,
    MECHA_RIDLEY_OAM_LASER_SLIGHTLY_UP,
    MECHA_RIDLEY_OAM_LASER_UP,
    MECHA_RIDLEY_OAM_LEFT_ARM_DYING,
    MECHA_RIDLEY_OAM_RIGHT_ARM_DYING,
    MECHA_RIDLEY_OAM_NECK_DYING,
    MECHA_RIDLEY_OAM_LEFT_ARM_CRAWLING_BACKWARDS,
    MECHA_RIDLEY_OAM_RIGHT_ARM_CRAWLING_BACKWARDS,
    MECHA_RIDLEY_OAM_LEFT_ARM_SWINGING_AT_GROUND,
    MECHA_RIDLEY_OAM_LEFT_ARM_SWINGING_AT_CLOSE_GROUND,

    MECHA_RIDLEY_OAM_END
};

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_CrawlingForwardLow[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_CrawlingForwardMiddle[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_CrawlingForwardHigh[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_Crawling_Unused1[2];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_Crawling_Unused2[2];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_Crawling_Unused3[2];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_DyingStandingLow[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_DyingStandingMiddle[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_DyingStandingHigh[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_RaisingArmLow[4];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_RaisingArmMiddle[4];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_RaisingArmHigh[4];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_StandingLow[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_StandingMiddle[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_StandingHigh[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_SmallSwipeLow[6];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_SmallSwipeMiddle[6];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_SmallSwipeHigh[6];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_ShakingHeadLow[10];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_ShakingHeadMiddle[10];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_ShakingHeadHigh[10];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_LowToMiddle[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_MiddleToHigh[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_HighToMiddle[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_MiddleToLow[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_LowToHigh[5];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_HighToLow[5];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_OpeningMouthLow[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_SpittingFireballsLow[4];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_ClosingMouthLow[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_OpeningMouthMiddle[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_SpittingFireballsMiddle[4];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_ClosingMouthMiddle[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_OpeningMouthHigh[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_SpittingFireballsHigh[4];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_ClosingMouthHigh[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_FiringMissilesArmsUpLow[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_FiringMissilesArmsUpMiddle[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_FiringMissilesArmsUpHigh[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_FiringMissilesLow[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_FiringMissilesMiddle[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_FiringMissilesHigh[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_Dying[11];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_CrawlingBackwardsLow[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_CrawlingBackwardsMiddle[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_CrawlingBackwardsHigh[7];

extern const u8 sMechaRidleyGreenGlowPaletteData[7][2];

extern const u32 sMechaRidleyGfx[2525];
extern const u32 sMechaRidleyWeaponsGfx[1024];
extern const u32 sMechaRidleyDestroyedGfx[336];

extern const u16 sMechaRidleyPal[129];

extern const u16 sMechaRidley_8323aaa_Pal[12];
extern const u16 sMechaRidleyGreenGlowPal[4 * 16];
extern const u16 sMechaRidley_8323b42_Pal[4];
extern const u16 sMechaRidley_8323b4a_Pal[12];
extern const u16 sMechaRidley_8323b62_Pal[3];

extern const u16 sMechaRidleyFadingPal[7 * 16];


extern const u16 sMechaRidleyPartOam_Tail_Frame0[7];

extern const u16 sMechaRidleyPartOam_Ring_Frame0[10];

extern const u16 sMechaRidleyPartOam_Cover_Frame0[4];

extern const u16 sMechaRidleyPartOam_Torso_Frame0[13];

extern const u16 sMechaRidleyOam_Idle_Frame0[4];

extern const u16 sMechaRidleyOam_Idle_Frame1[4];

extern const u16 sMechaRidleyOam_Idle_Frame2[4];

extern const u16 sMechaRidleyPartOam_HeadIdle_Frame0[19];

extern const u16 sMechaRidleyPartOam_HeadOpeningMouth_Frame0[25];

extern const u16 sMechaRidleyPartOam_HeadOpeningMouth_Frame1[25];

extern const u16 sMechaRidleyPartOam_HeadSpittingFireballs_Frame0[25];

extern const u16 sMechaRidleyPartOam_HeadSpittingFireballs_Frame1[25];

extern const u16 sMechaRidleyPartOam_HeadSpittingFireballs_Frame2[25];

extern const u16 sMechaRidleyPartOam_EyeIdle_Frame0[4];

extern const u16 sMechaRidleyPartOam_EyeIdle_Frame1[4];

extern const u16 sMechaRidleyPartOam_EyeIdle_Frame3[4];

extern const u16 sMechaRidleyPartOam_EyeIdle_Frame4[4];

extern const u16 sMechaRidleyPartOam_EyeGlowing_Frame0[4];

extern const u16 sMechaRidleyPartOam_EyeGlowing_Frame1[4];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserForward_Frame0[7];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserForward_Frame1[7];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserForward_Frame2[10];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserForward_Frame3[7];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserForward_Frame4[10];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserForward_Frame5[10];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserForward_Frame6[10];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserSlightlyDown_Frame0[7];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserSlightlyDown_Frame1[7];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserSlightlyDown_Frame2[10];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserSlightlyDown_Frame3[10];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserSlightlyDown_Frame4[10];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserSlightlyDown_Frame5[13];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserSlightlyDown_Frame6[10];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserDown_Frame0[7];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserDown_Frame1[10];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserDown_Frame2[10];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserDown_Frame3[13];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserDown_Frame4[13];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserDown_Frame5[16];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserDown_Frame6[16];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserSlightlyUp_Frame0[7];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserSlightlyUp_Frame1[7];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserSlightlyUp_Frame2[10];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserSlightlyUp_Frame3[10];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserSlightlyUp_Frame4[10];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserSlightlyUp_Frame5[13];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserSlightlyUp_Frame6[10];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserUp_Frame0[7];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserUp_Frame1[10];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserUp_Frame2[10];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserUp_Frame3[13];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserUp_Frame4[13];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserUp_Frame5[16];

extern const u16 sMechaRidleyPartOam_EyeShootingLaserUp_Frame6[16];

extern const u16 sMechaRidleyPartOam_EyeInactive_Frame0[4];

extern const u16 sMechaRidleyPartOam_EyeInactive_Frame1[4];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingForwardLow_Frame0[19];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingForwardLow_Frame1[19];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingForwardLow_Frame2[19];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingForwardLow_Frame3[19];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingForwardLow_Frame4[19];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingForwardLow_Frame5[16];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingForwardLow_Frame6[16];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingForwardLow_Frame7[16];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingForwardLow_Frame8[19];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingForwardLow_Frame9[19];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingForwardLow_Frame10[19];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingForwardLow_Frame0[16];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingForwardLow_Frame1[16];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingForwardLow_Frame2[16];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingForwardLow_Frame3[19];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingForwardLow_Frame4[19];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingForwardLow_Frame5[19];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingForwardLow_Frame6[19];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingForwardLow_Frame7[19];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingForwardLow_Frame8[19];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingForwardLow_Frame9[19];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingForwardLow_Frame10[19];

extern const u16 sMechaRidleyPartOam_LeftArmHoldingUp_Frame0[19];

extern const u16 sMechaRidleyPartOam_LeftArmHoldingUp_Frame1[19];

extern const u16 sMechaRidleyPartOam_LeftArmHoldingUp_Frame2[16];

extern const u16 sMechaRidleyPartOam_LeftArmHoldingUp_Frame3[19];

extern const u16 sMechaRidleyPartOam_LeftArmHoldingUp_Frame4[19];

extern const u16 sMechaRidleyPartOam_RightArmHoldingUp_Frame0[16];

extern const u16 sMechaRidleyPartOam_RightArmHoldingUp_Frame1[19];

extern const u16 sMechaRidleyPartOam_RightArmHoldingUp_Frame2[19];

extern const u16 sMechaRidleyPartOam_RightArmHoldingUp_Frame3[19];

extern const u16 sMechaRidleyPartOam_RightArmHoldingUp_Frame4[19];

extern const u16 sMechaRidleyPartOam_LeftArmLayingDown_Frame0[19];

extern const u16 sMechaRidleyPartOam_LeftArmLayingDown_Frame1[16];

extern const u16 sMechaRidleyPartOam_LeftArmLayingDown_Frame2[19];

extern const u16 sMechaRidleyPartOam_LeftArmLayingDown_Frame3[19];

extern const u16 sMechaRidleyPartOam_RightArmLayingDown_Frame0[19];

extern const u16 sMechaRidleyPartOam_RightArmLayingDown_Frame1[16];

extern const u16 sMechaRidleyPartOam_RightArmLayingDown_Frame2[19];

extern const u16 sMechaRidleyPartOam_RightArmLayingDown_Frame3[19];

extern const u16 sMechaRidleyPartOam_LeftArmTrembling_Frame0[19];

extern const u16 sMechaRidleyPartOam_LeftArmTrembling_Frame1[19];

extern const u16 sMechaRidleyPartOam_LeftArmTrembling_Frame2[19];

extern const u16 sMechaRidleyPartOam_LeftArmTrembling_Frame3[19];

extern const u16 sMechaRidleyPartOam_LeftArmTrembling_Frame5[19];

extern const u16 sMechaRidleyPartOam_RightArmTrembling_Frame0[19];

extern const u16 sMechaRidleyPartOam_RightArmTrembling_Frame1[19];

extern const u16 sMechaRidleyPartOam_RightArmTrembling_Frame2[19];

extern const u16 sMechaRidleyPartOam_RightArmTrembling_Frame3[19];

extern const u16 sMechaRidleyPartOam_RightArmTrembling_Frame5[19];

extern const u16 sMechaRidleyPartOam_LeftArmSwinging_Frame0[16];

extern const u16 sMechaRidleyPartOam_LeftArmSwinging_Frame1[16];

extern const u16 sMechaRidleyPartOam_LeftArmSwinging_Frame2[19];

extern const u16 sMechaRidleyPartOam_LeftArmSwinging_Frame3[19];

extern const u16 sMechaRidleyPartOam_LeftArmSwinging_Frame4[19];

extern const u16 sMechaRidleyPartOam_LeftArmSwinging_Frame5[22];

extern const u16 sMechaRidleyPartOam_LeftArmSwinging_Frame6[16];

extern const u16 sMechaRidleyPartOam_LeftArmSwinging_Frame7[19];

extern const u16 sMechaRidleyPartOam_NeckLow_Frame0[16];

extern const u16 sMechaRidleyPartOam_NeckRotateLow_Frame0[13];

extern const u16 sMechaRidleyPartOam_NeckRotateLow_Frame1[16];

extern const u16 sMechaRidleyPartOam_NeckRotateLow_Frame2[13];

extern const u16 sMechaRidleyPartOam_NeckRotateLow_Frame3[13];

extern const u16 sMechaRidleyPartOam_NeckRotateLow_Frame4[13];

extern const u16 sMechaRidleyPartOam_NeckMiddleToLow_Frame1[16];

extern const u16 sMechaRidleyPartOam_NeckLowToMiddle_Frame0[16];

extern const u16 sMechaRidleyPartOam_NeckLowToMiddle_Frame1[16];

extern const u16 sMechaRidleyPartOam_NeckMiddle_Frame0[16];

extern const u16 sMechaRidleyPartOam_NeckRotateMiddle_Frame0[13];

extern const u16 sMechaRidleyPartOam_NeckRotateMiddle_Frame1[16];

extern const u16 sMechaRidleyPartOam_NeckRotateMiddle_Frame2[13];

extern const u16 sMechaRidleyPartOam_NeckRotateMiddle_Frame3[13];

extern const u16 sMechaRidleyPartOam_NeckRotateMiddle_Frame4[13];

extern const u16 sMechaRidleyPartOam_NeckRotateMiddle_Frame8[16];

extern const u16 sMechaRidleyPartOam_NeckMiddleToHigh_Frame0[16];

extern const u16 sMechaRidleyPartOam_NeckMiddleToHigh_Frame1[16];

extern const u16 sMechaRidleyPartOam_NeckHigh_Frame0[16];

extern const u16 sMechaRidleyPartOam_NeckRotateHigh_Frame0[13];

extern const u16 sMechaRidleyPartOam_NeckRotateHigh_Frame1[16];

extern const u16 sMechaRidleyPartOam_NeckRotateHigh_Frame2[13];

extern const u16 sMechaRidleyPartOam_NeckRotateHigh_Frame3[13];

extern const u16 sMechaRidleyPartOam_NeckRotateHigh_Frame4[13];

extern const u16 sMechaRidleyPartOam_NeckRotateHigh_Frame8[16];

extern const u16 sMechaRidleyPartOam_NeckLow_2_Frame0[16];

extern const u16 sMechaRidleyPartOam_NeckMiddle_2_Frame0[16];

extern const u16 sMechaRidleyPartOam_NeckHigh_2_Frame0[16];

extern const u16 sMechaRidleyPartOam_MissileLauncherClosed_Frame0[13];

extern const u16 sMechaRidleyPartOam_MissileLauncherOpening_Frame0[16];

extern const u16 sMechaRidleyPartOam_MissileLauncherOpening_Frame1[16];

extern const u16 sMechaRidleyPartOam_MissileLauncherOpening_Frame2[16];

extern const u16 sMechaRidleyPartOam_MissileLauncherOpening_Frame3[16];

extern const u16 sMechaRidleyPartOam_MissileLauncherOpening_Frame4[16];

extern const u16 sMechaRidleyPartOam_MissileLauncherOpening_Frame5[16];

extern const u16 sMechaRidleyPartOam_MissileLauncherOpening_Frame6[13];

extern const u16 sMechaRidleyPartOam_MissileLauncherOpening_Frame7[7];

extern const u16 sMechaRidleyPartOam_MissileLauncherOpened_Frame1[7];

extern const u16 sMechaRidleyMissileOam_Frame0[4];

extern const u16 sMechaRidleyFireballOam_Frame0[4];

extern const u16 sMechaRidleyFireballOam_Frame1[4];

extern const u16 sMechaRidleyFireballOam_Frame2[4];

extern const u16 sMechaRidleyFireballOam_Frame3[4];

extern const u16 sMechaRidleyLaserOam_Forward_Frame2[4];

extern const u16 sMechaRidleyLaserOam_Forward_Frame0[7];

extern const u16 sMechaRidleyLaserOam_Forward_Frame1[7];

extern const u16 sMechaRidleyLaserOam_SlightlyDown_Frame0[7];

extern const u16 sMechaRidleyLaserOam_SlightlyDown_Frame1[7];

extern const u16 sMechaRidleyLaserOam_Down_Frame0[13];

extern const u16 sMechaRidleyLaserOam_Down_Frame1[13];

extern const u16 sMechaRidleyLaserOam_SlightlyUp_Frame0[7];

extern const u16 sMechaRidleyLaserOam_SlightlyUp_Frame1[7];

extern const u16 sMechaRidleyLaserOam_Up_Frame0[13];

extern const u16 sMechaRidleyLaserOam_Up_Frame1[13];

extern const u16 sMechaRidleyPartOam_LeftArmDying_Frame0[19];

extern const u16 sMechaRidleyPartOam_LeftArmDying_Frame1[19];

extern const u16 sMechaRidleyPartOam_LeftArmDying_Frame2[19];

extern const u16 sMechaRidleyPartOam_LeftArmDying_Frame3[16];

extern const u16 sMechaRidleyPartOam_LeftArmDying_Frame4[19];

extern const u16 sMechaRidleyPartOam_LeftArmDying_Frame5[19];

extern const u16 sMechaRidleyPartOam_LeftArmDying_Frame6[19];

extern const u16 sMechaRidleyPartOam_LeftArmDying_Frame7[19];

extern const u16 sMechaRidleyPartOam_LeftArmDying_Frame8[19];

extern const u16 sMechaRidleyPartOam_LeftArmDying_Frame9[19];

extern const u16 sMechaRidleyPartOam_RightArmDying_Frame0[19];

extern const u16 sMechaRidleyPartOam_RightArmDying_Frame1[19];

extern const u16 sMechaRidleyPartOam_RightArmDying_Frame2[19];

extern const u16 sMechaRidleyPartOam_RightArmDying_Frame3[16];

extern const u16 sMechaRidleyPartOam_RightArmDying_Frame4[19];

extern const u16 sMechaRidleyPartOam_RightArmDying_Frame5[19];

extern const u16 sMechaRidleyPartOam_RightArmDying_Frame6[19];

extern const u16 sMechaRidleyPartOam_RightArmDying_Frame7[19];

extern const u16 sMechaRidleyPartOam_RightArmDying_Frame8[19];

extern const u16 sMechaRidleyPartOam_RightArmDying_Frame9[19];

extern const u16 sMechaRidleyPartOam_NeckDying_Frame0[16];

extern const u16 sMechaRidleyPartOam_NeckDying_Frame1[13];

extern const u16 sMechaRidleyPartOam_NeckDying_Frame2[13];

extern const u16 sMechaRidleyPartOam_NeckDying_Frame3[13];

extern const u16 sMechaRidleyPartOam_NeckDying_Frame4[13];

extern const u16 sMechaRidleyPartOam_NeckDying_Frame5[16];

extern const u16 sMechaRidleyPartOam_NeckDying_Frame6[16];

extern const u16 sMechaRidleyPartOam_NeckDying_Frame7[16];

extern const u16 sMechaRidleyPartOam_NeckDying_Frame8[16];

extern const u16 sMechaRidleyPartOam_NeckDying_Frame9[16];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingBackwards_Frame9[19];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingBackwards_Frame8[19];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingBackwards_Frame7[19];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingBackwards_Frame6[19];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingBackwards_Frame5[19];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingBackwards_Frame4[16];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingBackwards_Frame3[16];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingBackwards_Frame2[16];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingBackwards_Frame1[19];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingBackwards_Frame0[19];

extern const u16 sMechaRidleyPartOam_LeftArmCrawlingBackwards_Frame10[19];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingBackwards_Frame9[16];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingBackwards_Frame8[16];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingBackwards_Frame7[16];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingBackwards_Frame6[19];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingBackwards_Frame5[19];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingBackwards_Frame4[19];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingBackwards_Frame3[19];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingBackwards_Frame2[19];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingBackwards_Frame1[19];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingBackwards_Frame0[19];

extern const u16 sMechaRidleyPartOam_RightArmCrawlingBackwards_Frame10[19];

extern const u16 sMechaRidleyPartOam_LeftArmSwingingAtGround_Frame6[22];

extern const u16 sMechaRidleyPartOam_LeftArmSwingingAtGround_Frame7[22];

extern const u16 sMechaRidleyPartOam_LeftArmSwingingAtGround_Frame8[22];

extern const u16 sMechaRidleyPartOam_LeftArmSwingingAtGround_Frame9[16];

extern const u16 sMechaRidleyPartOam_LeftArmSwingingAtCloseGround_Frame9[19];

extern const u16 sMechaRidleyPartOam_EyeDying_Frame0[7];

extern const struct FrameData sMechaRidleyPartOam_Tail[2];

extern const struct FrameData sMechaRidleyPartOam_Ring[2];

extern const struct FrameData sMechaRidleyPartOam_Cover[2];

extern const struct FrameData sMechaRidleyPartOam_Torso[2];

extern const struct FrameData sMechaRidleyOam_Idle[5];

extern const struct FrameData sMechaRidleyPartOam_HeadIdle[2];

extern const struct FrameData sMechaRidleyPartOam_HeadOpeningMouth[4];

extern const struct FrameData sMechaRidleyPartOam_HeadSpittingFireballs[4];

extern const struct FrameData sMechaRidleyPartOam_HeadClosingMouth[4];

extern const struct FrameData sMechaRidleyPartOam_EyeIdle[7];

extern const struct FrameData sMechaRidleyPartOam_EyeGlowing[5];

extern const struct FrameData sMechaRidleyPartOam_EyeShootingLaserForward[8];

extern const struct FrameData sMechaRidleyPartOam_EyeShootingLaserSlightlyDown[8];

extern const struct FrameData sMechaRidleyPartOam_EyeShootingLaserDown[8];

extern const struct FrameData sMechaRidleyPartOam_EyeShootingLaserSlightlyUp[8];

extern const struct FrameData sMechaRidleyPartOam_EyeShootingLaserUp[8];

extern const struct FrameData sMechaRidleyPartOam_EyeInactive[3];

extern const struct FrameData sMechaRidleyPartOam_LeftArmCrawlingForward[12];

extern const struct FrameData sMechaRidleyPartOam_RightArmCrawlingForward[12];

extern const struct FrameData sMechaRidleyPartOam_LeftArmHoldingUp[6];

extern const struct FrameData sMechaRidleyPartOam_RightArmHoldingUp[6];

extern const struct FrameData sMechaRidleyPartOam_LeftArmHeldUp[2];

extern const struct FrameData sMechaRidleyPartOam_RightArmHeldUp[2];

extern const struct FrameData sMechaRidleyPartOam_LeftArmLayingDown[5];

extern const struct FrameData sMechaRidleyPartOam_RightArmLayingDown[5];

extern const struct FrameData sMechaRidleyPartOam_LeftArmTrembling[7];

extern const struct FrameData sMechaRidleyPartOam_RightArmTrembling[7];

extern const struct FrameData sMechaRidleyPartOam_LeftArmIdle[2];

extern const struct FrameData sMechaRidleyPartOam_RightArmIdle[2];

extern const struct FrameData sMechaRidleyPartOam_LeftArmSwinging[9];

extern const struct FrameData sMechaRidleyPartOam_NeckLow[2];

extern const struct FrameData sMechaRidleyPartOam_NeckMiddle[2];

extern const struct FrameData sMechaRidleyPartOam_NeckHigh[2];

extern const struct FrameData sMechaRidleyPartOam_NeckRotateLow[10];

extern const struct FrameData sMechaRidleyPartOam_NeckRotateMiddle[10];

extern const struct FrameData sMechaRidleyPartOam_NeckRotateHigh[10];

extern const struct FrameData sMechaRidleyPartOam_NeckLowToMiddle[3];

extern const struct FrameData sMechaRidleyPartOam_NeckMiddleToHigh[3];

extern const struct FrameData sMechaRidleyPartOam_NeckHighToMiddle[3];

extern const struct FrameData sMechaRidleyPartOam_NeckMiddleToLow[3];

extern const struct FrameData sMechaRidleyPartOam_NeckLowToHigh[5];

extern const struct FrameData sMechaRidleyPartOam_NeckHighToLow[5];

extern const struct FrameData sMechaRidleyPartOam_NeckLow_2[2];

extern const struct FrameData sMechaRidleyPartOam_NeckMiddle_2[2];

extern const struct FrameData sMechaRidleyPartOam_NeckHigh_2[2];

extern const struct FrameData sMechaRidleyPartOam_MissileLauncherClosed[2];

extern const struct FrameData sMechaRidleyPartOam_MissileLauncherOpening[9];

extern const struct FrameData sMechaRidleyPartOam_MissileLauncherOpened[3];

extern const struct FrameData sMechaRidleyPartOam_MissileLauncherClosing[9];

extern const struct FrameData sMechaRidleyMissileOam[2];

extern const struct FrameData sMechaRidleyFireballOam[5];

extern const struct FrameData sMechaRidleyLaserOam_Forward[4];

extern const struct FrameData sMechaRidleyLaserOam_SlightlyDown[4];

extern const struct FrameData sMechaRidleyLaserOam_Down[4];

extern const struct FrameData sMechaRidleyLaserOam_SlightlyUp[4];

extern const struct FrameData sMechaRidleyLaserOam_Up[4];

extern const struct FrameData sMechaRidleyPartOam_LeftArmDying[11];

extern const struct FrameData sMechaRidleyPartOam_RightArmDying[11];

extern const struct FrameData sMechaRidleyPartOam_NeckDying[11];

extern const struct FrameData sMechaRidleyPartOam_LeftArmCrawlingBackwards[12];

extern const struct FrameData sMechaRidleyPartOam_RightArmCrawlingBackwards[12];

extern const struct FrameData sMechaRidleyPartOam_LeftArmSwingingAtGround[11];

extern const struct FrameData sMechaRidleyPartOam_LeftArmSwingingAtCloseGround[11];

extern const struct FrameData sMechaRidleyPartOam_EyeDying[3];

#endif /* MECHA_RIDLEY_DATA_H */
