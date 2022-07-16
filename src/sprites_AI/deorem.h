#ifndef DEOREM_AI_H
#define DEOREM_AI_H

#include "../types.h"
#include "../clipdata.h"

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
void DeoremSegmentRighLeaving(void);
void DeoremSegmentRighLeavingEnd(void);
void DeoremSegmentSetTimerDying(void);
void DeoremSegmentDying(void);
void DeoremEyeInit(void);
void DeoremEyeSetPose9(void);
void DeoremEyeMove(void);
void DeoremEyeMainLoop(void);
void DeoremEyeDyingGFXInit(void);
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