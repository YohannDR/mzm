#ifndef IMAGO_AI_H
#define IMAGO_AI_H

#include "../types.h"

#define IMAGO_SIZE BLOCK_SIZE * 4

#define IMAGO_POSE_WAIT_FOR_LAST_EGG 0x1
#define IMAGO_POSE_SPAWN 0x2
#define IMAGO_POSE_COMING_DOWN_INIT 0x8
#define IMAGO_POSE_COMING_DOWN 0x9
#define IMAGO_POSE_MOVE_HORIZONTALLY 0x23
#define IMAGO_POSE_CHECK_SAMUS_AT_SUPER_MISSILE 0x67

// Imago part

#define IMAGO_PART_LEFT_WING_INTERNAL 0x0
#define IMAGO_PART_LEFT_WING_EXTERNAL 0x1
#define IMAGO_PART_BODY 0x2
#define IMAGO_PART_RIGHT_WING_INTERNAL 0x3
#define IMAGO_PART_RIGHT_WING_EXTERNAL 0x4
#define IMAGO_PART_CORE 0x5
#define IMAGO_PART_IMAGO 0x6

// Imago egg

#define IMAGO_EGG_PART_NORMAL 0x0
#define IMAGO_EGG_PART_LAST 0x80

void ImagoSyncSubSprites(void);
void ImagoShootNeedles(void);
void ImagoCoreFlashingAnim(void);
void ImagoSetSidesHitbox(void);
void ImagoInit(void);
void ImagoWaitForLastEgg(void);
void ImagoSpawn(void);
void ImagoComingDownInit(void);
void ImagoComingDown(void);
void ImagoMove(void);
void ImagoGoingUp(void);
void ImagoAttackingGFXInit(void);
void ImagoAttackingGoingDown(void);
void ImagoAttackingGoingUp(void);
void ImagoSpawnDamagedStinger(void);
void ImagoCheckSamusAtSuperMissile(void);
void ImagoChargeThroughWall(void);
void ImagoDestroyWall(void);
void ImagoDying(void);
void ImagoSetEvent(void);
void ImagoPartSetSidesHitbox(void);
void ImagoPartInit(void);
void ImagoPartBeforeSpawn(void);
void ImagoPartUpdatePalette(void);
void ImagoPartSyncPalette(void);
void Imago(void);
void ImagoPart(void);
void ImagoNeedle(void);
void ImagoDamagedStinger(void);
void ImagoEgg(void);

#endif /* IMAGO_AI_H */