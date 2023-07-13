#ifndef ACID_WORM_AI_H
#define ACID_WORM_AI_H

#include "types.h"

// Acid worm

#define ACID_WORM_POSE_CHECK_SAMUS_ON_ZIPLINE 0x1
#define ACID_WORM_POSE_IDLE_INIT 0x8
#define ACID_WORM_POSE_IDLE 0x9
#define ACID_WORM_POSE_EXTENDED 0xF
#define ACID_WORM_POSE_CHECK_WARNING_ENDED 0x23
#define ACID_WORM_POSE_EXTENDING 0x25
#define ACID_WORM_POSE_RETRACTING 0x27
#define ACID_WORM_POSE_RAISING_ACID 0x29
#define ACID_WORM_POSE_BRINGING_DOWN_ACID 0x2B
#define ACID_WORM_POSE_CHECK_SPAWN 0x42
#define ACID_WORM_POSE_SPAWN_EXTEND 0x43
#define ACID_WORM_POSE_SPAWN_ON_TOP 0x45
#define ACID_WORM_POSE_SPAWN_RETRACT 0x47
#define ACID_WORM_POSE_DYING_INIT 0x62
#define ACID_WORM_POSE_DYING_ANIM 0x67
#define ACID_WORM_POSE_DYING 0x68

// Acid worm body

#define ACID_WORM_BODY_PART_AROUND_MOUTH 0x1
#define ACID_WORM_BODY_PART_WEAK_POINT 0x2
#define ACID_WORM_BODY_PART_BELOW_WEAK_POINT 0x3
#define ACID_WORM_BODY_PART_ABOVE_SEGMENTS 0x4
#define ACID_WORM_BODY_PART_SEGMENT1 0x5
#define ACID_WORM_BODY_PART_SEGMENT2 0x6
#define ACID_WORM_BODY_PART_SEGMENT3 0x7
#define ACID_WORM_BODY_PART_SEGMENT4 0x8
#define ACID_WORM_BODY_PART_SEGMENT5 0x9

// Acid worm spit



#define ACID_WORM_SPAWN_RANGE (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE - PIXEL_SIZE)

void AcidWormHandleRotation(void);
void AcidWormRandomXMovement(void);
void AcidWormChangeTwoGroundCCAA(u8 caa, u16 yPosition, u16 xPosition);
void AcidWormChangeBigBlockDownCCAA(u8 caa);
void AcidWormChangeBigBlockMiddleCCAA(u8 caa);
void AcidWormChangeBigBlockTopCCAA(u8 caa);
void AcidWormPlayRetractingSound(void);
u8 AcidWormCollidingWithSamusWhenExtending(void);
void AcidWormInit(void);
void AcidWormCheckSamusOnZipline(void);
void AcidWormSpawnStart(void);
void AcidWormSpawnExtending(void);
void AcidWormSpawnStayingOnTop(void);
void AcidWormSpawnRetracting(void);
void AcidWormIdleInit(void);
void AcidWormIdle(void);
void AcidWormCheckWarningAnimEnded(void);
void AcidWormExtend(void);
void AcidWormExtended(void);
void AcidWormRetracting(void);
void AcidWormRaiseAcid(void);
void AcidWormAcidGoDown(void);
void AcidWormDeathGfxInit(void);
void AcidWormDeathFlashingAnim(void);
void AcidWormDying(void);
void AcidWormBodyInit(void);
void AcidWormBodyMove(void);
void AcidWormBodyMainLoop(void);
void AcidWormBodyDeath(void);
void AcidWormSpitInit(void);
void AcidWormSpitMove(void);
void AcidWormSpitExplodingGfxInit(void);
void AcidWormSpitCheckExplodingAnimEnded(void);
void AcidWormSpitCheckExplodingOnAcidAnimEnded(void);
void AcidWorm(void);
void AcidWormBody(void);
void AcidWormSpit(void);

#endif /* ACID_WORM_AI_H */