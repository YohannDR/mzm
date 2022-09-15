#ifndef CHOZO_STATUE_AI_H
#define CHOZO_STATUE_AI_H

#include "../types.h"

#define CHOZO_STATUE_BEHAVIOR_ITEM 0x0
#define CHOZO_STATUE_BEHAVIOR_REFILL 0x1
#define CHOZO_STATUE_BEHAVIOR_HINT 0x2
#define CHOZO_STATUE_BEHAVIOR_HINT_TAKEN 0x3

#define CHOZO_STATUE_POSE_IDLE 0x9
#define CHOZO_STATUE_POSE_DO_NOTHING 0xF
#define CHOZO_STATUE_POSE_REGISTER_HINT 0x22
#define CHOZO_STATUE_POSE_HINT_FLASHING 0x23
#define CHOZO_STATUE_POSE_SITTING_INIT 0x24
#define CHOZO_STATUE_POSE_SITTING 0x25
#define CHOZO_STATUE_POSE_DELAY_AFTER_SITTING 0x27
#define CHOZO_STATUE_POSE_WAIT_FOR_ITEM_TO_BE_COLLECTED 0x29
#define CHOZO_STATUE_POSE_TIMER_AFTER_ITEM 0x2B
#define CHOZO_STATUE_POSE_REFILL_INIT 0x2E
#define CHOZO_STATUE_POSE_REFILL 0x2F
#define CHOZO_STATUE_POSE_SLEEPING_INIT 0x30
#define CHOZO_STATUE_POSE_SLEEPING 0x31

// Chozo statue part

#define CHOZO_STATUE_HAND_X_OFFSET 0x38
#define CHOZO_STATUE_HAND_Y_OFFSET 0x11

#define CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_HINT 0x9
#define CHOZO_STATUE_PART_POSE_LEG_IDLE 0xF
#define CHOZO_STATUE_PART_POSE_ARM_SITTING 0x23
#define CHOZO_STATUE_PART_POSE_ARM_SEATED 0x24
#define CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_REFILL 0x25
#define CHOZO_STATUE_PART_POSE_ARM_REFILL 0x27
#define CHOZO_STATUE_PART_POSE_ARM_SLEEPING_INIT 0x29
#define CHOZO_STATUE_PART_POSE_ARM_SLEEPING 0x2B
#define CHOZO_STATUE_PART_POSE_EYE_OPENING_INIT 0x42
#define CHOZO_STATUE_PART_POSE_EYE_OPENING 0x43
#define CHOZO_STATUE_PART_POSE_EYE_CLOSING_INIT 0x44
#define CHOZO_STATUE_PART_POSE_EYE_CLOSING 0x45
#define CHOZO_STATUE_PART_POSE_GLOW_IDLE 0x4F
#define CHOZO_STATUE_PART_POSE_DO_NOTHING 0x61

#define CHOZO_STATUE_PART_ARM 0x0
#define CHOZO_STATUE_PART_GLOW 0x1
#define CHOZO_STATUE_PART_EYE 0x2
#define CHOZO_STATUE_PART_LEG 0x3
#define CHOZO_STATUE_PART_HEAD 0x4

// Chozo ball

#define CHOZO_BALL_POSE_DO_NOTHING 0x8
#define CHOZO_BALL_POSE_IDLE 0x9
#define CHOZO_BALL_POSE_GETTING 0x23
#define CHOZO_BALL_POSE_REVEALING 0x67


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



void ChozoStatueSyncSubSprites(void);
void ChozoStatueRegisterItem(u8 spriteID);
void ChozoStatueSetDirection(void);
u8 ChozoStatueGetBehavior(u8 spriteID);
void ChozoStatueInit(void);
void ChozoStatue_Empty(void);
void ChozoStatueRegisterHint(void);
void ChozoStatueHintFlashing(void);
void ChozoStatueSittingInit(void);
void ChozoStatueSitting(void);
void ChozoStatueDelayBeforeRefillAfterHint(void);
void ChozoStatueWaitForItemToBeCollected(void);
void ChozoStatueTimerAfterItemGrabbed(void);
void ChozoStatueRefillInit(void);
void ChozoStatueRefillSamus(void);
void ChozoStatueSleepingInit(void);
void ChozoStatueSleeping(void);
void ChozoStatuePartInit(void);
void ChozoStatuePartGlowIdle(void);
void ChozoStatuePartArmCheckGrabSamusHint(void);
void ChozoStatuePartSyncSamusPosition(void);
void ChozoStatuePartArmSitting(void);
void ChozoStatuePartArmSeated(void);
void ChozoStatuePartArmCheckGrabSamusRefill(void);
void ChozoStatuePartArmRefill(void);
void ChozoStatuePart_Empty(void);
void ChozoStatuePartSleepingInit(void);
void ChozoStatuePartArmSleeping(void);
void ChozoStatuePartEyeOpeningInit(void);
void ChozoStatuePartEyeOpening(void);
void ChozoStatuePartEyeClosingInit(void);
void ChozoStatuePartEyeClosing(void);
void ChozoStatuePartLegIdle(void);
void ChozoStatue(void);
void ChozoStatuePart(void);
void ChozoStatueRefill(void);

#endif /* CHOZO_STATUE_AI_H */