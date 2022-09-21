#ifndef KRAID_AI_H
#define KRAID_AI_H

#include "types.h"

#define KRAID_POSE_GO_UP 0x1
#define KRAID_POSE_CHECK_FULLY_UP 0x2
#define KRAID_POSE_FIRST_STEP_INIT 0x8
#define KRAID_POSE_FIRST_STEP 0x9
#define KRAID_POSE_STANDING_INIT 0xE
#define KRAID_POSE_STANDING 0xF
#define KRAID_POSE_STANDING_BETWEEN_STEPS_INIT 0x10
#define KRAID_POSE_STANDING_BETWEEN_STEPS 0x11
#define KRAID_POSE_SECOND_STEP_INIT 0x22
#define KRAID_POSE_SECOND_STEP 0x23
#define KRAID_POSE_DYING_INIT 0x62
#define KRAID_POSE_DYING 0x67
#define KRAID_POSE_DEAD_STATIONARY 0x68

// Kraid part

#define KRAID_PART_POSE_IDLE 0xE
#define KRAID_PART_POSE_CHECK_ATTACK 0x12
#define KRAID_PART_POSE_CHECK_THROW_NAILS 0x10
#define KRAID_PART_POSE_CHECK_SPAWN_SPIKES 0x42
#define KRAID_PART_POSE_SPAWN_SPIKES 0x43
#define KRAID_PART_POSE_CHECK_PROJECTILES 0x44
#define KRAID_PART_POSE_DYING_INIT 0x62
#define KRAID_PART_POSE_ARM_DYING 0x67
#define KRAID_PART_POSE_DYING_STATIONNARY 0x68

#define KRAID_PART_BELLY 0x0
#define KRAID_PART_LEFT_ARM 0x1
#define KRAID_PART_TOP_HOLE_LEFT 0x2
#define KRAID_PART_TOP_HOLE_RIGHT 0x3
#define KRAID_PART_MIDDLE_HOLE_LEFT 0x4
#define KRAID_PART_MIDDLE_HOLE_RIGHT 0x5
#define KRAID_PART_KRAID 0x6
#define KRAID_PART_BOTTOM_HOLE_LEFT 0x7
#define KRAID_PART_BOTTOM_HOLE_RIGHT 0x8
#define KRAID_PART_LEFT_FEET 0x9
#define KRAID_PART_RIGHT_ARM 0xA
#define KRAID_PART_RIGHT_FEET 0xB

// Kraid spike

#define KRAID_SPIKE_POSE_DELAY_BEFORE_MOVING 0x9
#define KRAID_SPIKE_POSE_MOVING 0x23
#define KRAID_SPIKE_POSE_IN_WALL 0x25

void KraidSyncSubSprites(void);
void KraidCheckProjectilesCollidingWithBelly(void);
void KraidOpenCloseRoutineAndProjectileCollision(void);
void KraidRandomSpriteDebrisOnCeiling(u8 timer);
void KraidPartHitboxChange_1Unused(void);
void KraidPartUpdateRightArmIdlingHitbox(void);
void KraidPartUpdateRightArmAttackingHitbox(void);
void KraidPartHitboxChange_2Unused(void);
void KraidPartUpdateLeftArmIdlingHitbox(void);
void KraidPartUpdateLeftArmDyingHitbox(void);
void KraidPartUpdateLeftArmAttackingHitbox(void);
void KraidMoveBG2ToRight(u8 movement);
void KraidMoveBG2ToLeft(u8 movement);
void KraidInit(void);
u8 KraidMoveUp(void);
void KraidGoUp(void);
void KraidCheckFullyUp(void);
u8 KraidMoveFeet(void);
void KraidFirstStepInit(void);
void KraidFirstStep(void);
void KraidSecondStepInit(void);
void KraidSecondStep(void);
void KraidStandingInit(void);
void KraidStanding(void);
void KraidStandingBetweenStepsInit(void);
void KraidStandingBetweenSteps(void);
void KraidPreventSamusGoingThrough(void);
void KraidDyingInit(void);
void KraidDying(void);
void KraidBeforeDeath(void);
void KraidPartInit(void);
void KraidPartThrowNails(void);
void KraidPartCheckAttack(void);
void KraidPartCallKraidCheckProjectilesCollidingWithBelly(void);
void KraidPartCheckShouldSpawnSpike(void);
void KraidPartSpawnSpike(void);
void KraidPartDyingInit(void);
void KraidPartDyingSinking(void);
void KraidPartDyingStationary(void);
void KraidNailMovement(void);
void Kraid(void);
void KraidPart(void);
void KraidSpike(void);
void KraidNail(void);

#endif /* KRAID_AI_H */