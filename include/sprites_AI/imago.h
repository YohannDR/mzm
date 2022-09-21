#ifndef IMAGO_AI_H
#define IMAGO_AI_H

#include "types.h"

#define IMAGO_SIZE BLOCK_SIZE * 4

#define IMAGO_MOVEMENT_STAGE_MOVING_HORIZONTALLY 0x0
#define IMAGO_MOVEMENT_STAGE_GO_UP 0x2

#define IMAGO_POSE_WAIT_FOR_LAST_EGG 0x1
#define IMAGO_POSE_SPAWN 0x2
#define IMAGO_POSE_COMING_DOWN_INIT 0x8
#define IMAGO_POSE_COMING_DOWN 0x9
#define IMAGO_POSE_MOVE_HORIZONTALLY 0x23
#define IMAGO_POSE_GOING_UP 0x25
#define IMAGO_POSE_ATTACKING_INIT 0x26
#define IMAGO_POSE_ATTACKING_GOING_DOWN 0x27
#define IMAGO_POSE_ATTACKING_GOING_UP 0x29
#define IMAGO_POSE_DYING_INIT 0x62
#define IMAGO_POSE_CHECK_SAMUS_AT_SUPER_MISSILE 0x67
#define IMAGO_POSE_CHARGING_THROUGH_WALL 0x68
#define IMAGO_POSE_DESTROY_WALL 0x69
#define IMAGO_POSE_DYING 0x6A
#define IMAGO_POSE_SET_EVENT 0x6C

// Imago part

#define IMAGO_PART_POSE_BODY_SPAWN 0x1
#define IMAGO_PART_POSE_BODY_UPDATE_PALETTE 0x8
#define IMAGO_PART_POSE_CORE_SYNC_PALETTE 0xE
#define IMAGO_PART_POSE_IDLE 0x42

#define IMAGO_PART_LEFT_WING_INTERNAL 0x0
#define IMAGO_PART_LEFT_WING_EXTERNAL 0x1
#define IMAGO_PART_BODY 0x2
#define IMAGO_PART_RIGHT_WING_INTERNAL 0x3
#define IMAGO_PART_RIGHT_WING_EXTERNAL 0x4
#define IMAGO_PART_CORE 0x5
#define IMAGO_PART_IMAGO 0x6

// Imago needle

#define IMAGO_NEEDLE_POSE_MOVING 0x9
#define IMAGO_NEEDLE_POSE_EXPLODING 0x42

// Imago damaged stinger

#define IMAGO_DAMAGED_STINGER_POSE_FALLING 0x9
#define IMAGO_DAMAGED_STINGER_POSE_DISAPPEARING 0x23

// Imago egg

#define IMAGO_EGG_POSE_IDLE 0x9
#define IMAGO_EGG_POSE_BREAKING 0x23
#define IMAGO_EGG_POSE_DISAPPEARING 0x25

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
void ImagoMoveHorizontally(void);
void ImagoGoingUp(void);
void ImagoAttackingInit(void);
void ImagoAttackingGoingDown(void);
void ImagoAttackingGoingUp(void);
void ImagoDyingInit(void);
void ImagoCheckSamusAtSuperMissile(void);
void ImagoChargeThroughWall(void);
void ImagoDestroyWall(void);
void ImagoDying(void);
void ImagoSetEvent(void);
void ImagoPartSetBodySidesHitbox(void);
void ImagoPartInit(void);
void ImagoPartBodySpawn(void);
void ImagoPartUpdateBodyPalette(void);
void ImagoPartSyncPalette(void);
void Imago(void);
void ImagoPart(void);
void ImagoNeedle(void);
void ImagoDamagedStinger(void);
void ImagoEgg(void);

#endif /* IMAGO_AI_H */