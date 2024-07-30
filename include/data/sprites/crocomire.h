#ifndef CROCOMIRE_DATA_H
#define CROCOMIRE_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

enum CrocomireOam {
    CROCOMIRE_OAM_PART_BODY_IDLE,
    CROCOMIRE_OAM_PART_BODY_ANGRY,
    CROCOMIRE_OAM_IDLE,
    CROCOMIRE_OAM_SCREAMING,
    CROCOMIRE_OAM_DYING,
    CROCOMIRE_OAM_PART_RIGHT_ARM_IDLE,
    CROCOMIRE_OAM_PART_LEFT_ARM_IDLE,
    CROCOMIRE_OAM_PART_LEFT_ARM_SCREAMING,
    CROCOMIRE_OAM_PART_RIGHT_ARM_WALKING_FORWARD,
    CROCOMIRE_OAM_PART_LEFT_ARM_WALKING_FORWARD,
    CROCOMIRE_OAM_PART_RIGHT_ARM_WALKING_BACKWARDS,
    CROCOMIRE_OAM_PART_LEFT_ARM_WALKING_BACKWARDS,
    CROCOMIRE_OAM_PART_RIGHT_ARM_DYING,
    CROCOMIRE_OAM_PART_LEFT_ARM_DYING,
    CROCOMIRE_OAM_PART_LEGS_IDLE,
    CROCOMIRE_OAM_PART_LEGS_WALKING_FORWARD,
    CROCOMIRE_OAM_PART_LEGS_WALKING_BACKWARDS,
    CROCOMIRE_OAM_PART_LEGS_DYING,
    CROCOMIRE_OAM_PART_TONGUE,
    CROCOMIRE_OAM_PART_TONGUE_DYING,
    CROCOMIRE_OAM_PROJECTILE,
    CROCOMIRE_OAM_PART_307028,
    CROCOMIRE_OAM_PART_307058,
    CROCOMIRE_OAM_PART_307088,
    CROCOMIRE_OAM_PART_3070b8,

    CROCOMIRE_OAM_END
};

extern const struct MultiSpriteData sCrocomireMultiSpriteData_Idle[3];

extern const struct MultiSpriteData sCrocomireMultiSpriteData_WalkingForward[3];

extern const struct MultiSpriteData sCrocomireMultiSpriteData_WalkingBackwards[3];

extern const struct MultiSpriteData sCrocomireMultiSpriteData_Screaming[3];

extern const struct MultiSpriteData sCrocomireMultiSpriteData_Dying[2];

extern const struct MultiSpriteData sCrocomireMultiSpriteData_Angry[2];

extern const u32 sCrocomireGfx[1954];
extern const u16 sCrocomirePal[128];

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