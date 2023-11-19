#ifndef DEOREM_AI_H
#define DEOREM_AI_H

#include "types.h"

#define DEOREM_POSE_SPAWN_GOING_DOWN 0x8
#define DEOREM_POSE_SPAWN_GOING_UP 0x22
#define DEOREM_POSE_SPAWN_HEAD_BODY 0x24
#define DEOREM_POSE_AFTER_SPAWN 0x25
#define DEOREM_POSE_MAIN 0x26
#define DEOREM_POSE_RETRACTING 0x27
#define DEOREM_POSE_THORNS_1 0x28
#define DEOREM_POSE_THORNS_2 0x29
#define DEOREM_POSE_AFTER_THORNS 0x2A
#define DEOREM_POSE_LEAVING 0x43
#define DEOREM_POSE_LEAVING_ANIM 0x44
#define DEOREM_POSE_LEAVING_IN_GROUND 0x45
#define DEOREM_POSE_CALL_SPAWN_CHARGE_BEAM 0x60
#define DEOREM_POSE_DYING 0x62
#define DEOREM_POSE_DYING_GOING_DOWN 0x67
#define DEOREM_POSE_DEATH 0x68

void DeoremChangeLeftCCAA(u8 caa);
void DeoremChangeRightCCAA(u8 caa);
void DeoremMoveDiagonaly(u8 velocity, u16 dstPosition);
void DeoremRandomSpriteDebris(u8 rng);
void DeoremSpriteDebrisSpawn(u16 yPosition, u16 xPosition, u8 timer);
u8 DeoremCheckLeaving(u8 ramSlot);
void DeoremSpawnChargeBeam(u16 yPosition, u16 xPosition);
void DeoremSetEyeOpeningTimer(void);
void DeoremCallSpawnChargeBeam(void);
void DeoremInit(void);
void DeoremSpawnGoingDown(void);
void DeoremSpawnGoingDownAnim(void);
void DeoremSpawnGoingUp(void);
void DeoremSpawnGoingUpAnim(void);
void DeoremSpawnHeadBody(void);
void DeoremAfterSpawn(void);
void DeoremMainLoop(void);
void DeoremRetracting(void);
void DeoremThrowingThorns(void);
void DeoremAfterThorns(void);
void DeoremDying(void);
void DeoremDyingGoingDown(void);
void DeoremDeath(void);
void DeoremCheckLeavingCeilingAnimEnded(void);
void DeoremLeaving(void);
void DeoremLeavingAnim(void);
void DeoremLeavingInGroundDebris(void);
void DeoremSegmentInit(void);
void DeoremSegmentSpawnGoingDown(void);
void DeoremSegmentSpawnGoingDownAfter(void);
void DeoremSegmentSpawnGoingUp(void);
void DeoremSegmentSpawnGoingUpAfter(void);
void DeoremSegmentRightIdleAnim(void);
void DeoremSegmentLeftIdleAnim(void);
void DeoremSegmentGoingDown(void);
void DeoremSegmentGoingUp(void);
void DeoremSegmentAboveHeadMovement(void);
void DeoremSegmentLeftLeaving(void);
void DeoremSegmentLeftLeavingEnd(void);
void DeoremSegmentMiddleLeavingEnd(void);
void DeoremSegmentMiddleLeaving(void);
void DeoremSegmentRightLeaving(void);
void DeoremSegmentRightLeavingEnd(void);
void DeoremSegmentSetTimerDying(void);
void DeoremSegmentDying(void);
void DeoremEyeInit(void);
void DeoremEyeSetPose9(void);
void DeoremEyeMove(void);
void DeoremEyeMainLoop(void);
void DeoremEyeDyingGfxInit(void);
void DeoremEyeDyingSpinningAnim(void);
void DeoremEyeDyingMovingAnim(void);
void DeoremThornInit(void);
void DeoremThornSpawning(void);
void DeoremThornMovement(void);
void Deorem(void);
void DeoremSegment(void);
void DeoremEye(void);
void DeoremThorn(void);

#endif /* DEOREM_AI_H */