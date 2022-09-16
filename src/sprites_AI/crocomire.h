#ifndef CROCOMIRE_AI_H
#define CROCOMIRE_AI_H

#include "../types.h"

#define CROCOMIRE_POSE_IDLE_INIT 0x8
#define CROCOMIRE_POSE_IDLE 0x9

// Crocomire part

#define CROCOMIRE_PART_RIGHT_ARM 0x0
#define CROCOMIRE_PART_HEAD 0x1
#define CROCOMIRE_PART_LEGS 0x2
#define CROCOMIRE_PART_BODY 0x3
#define CROCOMIRE_PART_TONGUE 0x4
#define CROCOMIRE_PART_LEFT_ARM 0x5

#define CROCOMIRE_PART_POSE_IDLE 0x9
#define CROCOMIRE_PART_POSE_DYING 0x67


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


void CrocomireSyncSubSprites(void);
void CrocomireInit(void);
void CrocomireIdleInit(void);
void Crocomire_Empty(void);
void CrocomirePartInit(void);
void Crocomire(void);
void CrocomirePart(void);

#endif /* CROCOMIRE_AI_H */