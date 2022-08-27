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
#define CHOZO_STATUE_POSE_DELAY_BEFORE_ITEM_BANNER 0x2B
#define CHOZO_STATUE_POSE_REFILL_INIT 0x2E
#define CHOZO_STATUE_POSE_REFILL 0x2F
#define CHOZO_STATUE_POSE_SLEEPING_INIT 0x30
#define CHOZO_STATUE_POSE_SLEEPING 0x31

// Chozo statue part

#define CHOZO_STATUE_PART_ARM 0x0
#define CHOZO_STATUE_PART_GLOW 0x1
#define CHOZO_STATUE_PART_EYE 0x2
#define CHOZO_STATUE_PART_LEG 0x3
#define CHOZO_STATUE_PART_HEAD 0x4

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
void ChozoStatueItemBeforeBanner(void);
void ChozoStatueRefillInit(void);
void ChozoStatueRefill(void);
void ChozoStatueSleepingInit(void);
void ChozoStatueSleeping(void);
void ChozoStatuePartInit(void);
void ChozoStatuePartHandRefillAnim(void);
void ChozoStatuePartGrabSamus(void);
void ChozoStatuePartSyncSamusPosition(void);
void ChozoStatuePartSyncSamusPositionWhileSitting(void);
void ChozoStatuePartSyncSamusPositionAfterSitting(void);
void ChozoStatuePartDetectSamus(void);
void ChozoStatuePartRefill(void);
void ChozoStatuePart_Empty(void);
void ChozoStatuePartEndRefill(void);
void ChozoStatuePartReleaseSamus(void);
void ChozoStatuePartInitHintGFX(void);
void ChozoStatuePartCheckEyeOpenedHint(void);
void ChozoStatueItemAfterBanner(void);
void ChozoStatuePartCheckEyeClosedRefill(void);
void ChozoStatuePartSetSittingPose(void);
void ChozoStatue(void);
void ChozoStatuePart(void);
void ChozoStatueRefill(void);

void UnknownItemChozoStatueSyncSubSprites(void);
void UnknownItemChozoStatueRegisterItem(void);
void UnknownItemChozoStatueHintFlashing_Unused(void);
void UnknownItemChozoStatueSittingInit_Unused(void);
void UnknownItemChozoStatueSitting_Unused(void);
void UnknownItemChozoStatueDelayBeforeRefillAfterHint_Unused(void);
void UnknownItemChozoStatueWaitForItemToBeCollected(void);
void UnknownItemChozoStatueCheckItemBannerSpawned(void);
void UnknownItemChozoStatueRefillInit(void);
void UnknownItemChozoStatueRefill(void);
void UnknownItemChozoStatueSleepingInit(void);
void UnknownItemChozoStatueSleeping(void);
void UnknownItemChozoStatuePartInit(void);
void UnknownItemChozoStatuePartHandRefillAnim(void);
void UnknownItemChozoStatuePartGrabSamus(void);
void UnknownItemChozoStatuePartSyncSamus(void);
void UnknownItemChozoStatuePartSyncSamusPositionWhileSitting(void);
void UnknownItemChozoStatuePartSyncSamusPositionAfterSitting(void);
void UnknownItemChozoStatuePartDetectSamus(void);
void UnknownItemChozoStatuePartRefill(void);
void UnknownItemChozoStatuePartEmpty(void);
void UnknownItemChozoStatuePartEndRefill(void);
void UnknownItemChozoStatuePartReleaseSamus(void);
void UnknownItemChozoStatuePartInitHintGFX_Unused(void);
void UnknownItemChozoStatuePartCheckEyeOpenedHint_Unused(void);
void UnknownItemChozoStatueItemAfterBanner(void);
void UnknownItemChozoStatuePartCheckEyeClosedRefill(void);
void UnknownItemChozoStatuePartSetSittingPose(void);
void UnknownItemChozoStatue(void);
void UnknownItemChozoStatuePart(void);
void UnknownItemChozoStatueRefill(void);
void ChozoStatueHintChangeCCAA(u8 caa1, u8 caa2);
void ChozoStatueSittingChangeCCAA(u8 caa1);

void ChozoBallSpawnItemBanner(u8 spriteID);
void ChozoBallSetOAMPointer(u8 spriteID);
void ChozoBallRevealingSetOAMPointer(u8 spriteID);
void ChozoBallRevealedSetOAMPointer(u8 spriteID);
void ChozoBallInit(void);
void ChozoBallEmpty(void);
void ChozoBallRevealing(void);
void ChozoBallCheckRevealingAnimEnded(void);
void ChozoBallRegisterItem(void);
void ChozoBallFlashAnimation(void);
void ChozoBall(void);

#endif /* CHOZO_STATUE_AI_H */