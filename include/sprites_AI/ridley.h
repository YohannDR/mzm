#ifndef RIDLEY_AI_H
#define RIDLEY_AI_H

#include "types.h"

#define RIDLEY_GROUND_POSITION (BLOCK_SIZE * 18 - ONE_SUB_PIXEL)

#define RIDLEY_POSE_CHECK_PLAY_CUTSCENE 0x1
#define RIDLEY_POSE_SPAWNING 0x2
#define RIDLEY_POSE_IDLE_INIT 0x8
#define RIDLEY_POSE_IDLE 0x9
#define RIDLEY_POSE_TURNING_AROUND_INIT 0xA
#define RIDLEY_POSE_TURNING_AROUND_FIRST_PART 0xB
#define RIDLEY_POSE_TURNING_AROUND_SECOND_PART 0xC
#define RIDLEY_POSE_SMALL_FIREBALLS_ATTACK_INIT 0x22
#define RIDLEY_POSE_SMALL_FIREBALLS_ATTACK 0x23
#define RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK_INIT 0x2A
#define RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK 0x2B
#define RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT 0x2C
#define RIDLEY_POSE_BIG_FIREBALLS_ATTACK 0x2D
#define RIDLEY_POSE_TAIL_ATTACKS_INIT 0x34
#define RIDLEY_POSE_TAIL_ATTACKS 0x35
#define RIDLEY_POSE_DYING 0x67

// Spawning 
#define RIDLEY_SPAWNING_ACTION_GOING_DOWN 0x0
#define RIDLEY_SPAWNING_ACTION_DELAY_BEFORE_OPENING_MOUTH 0x1
#define RIDLEY_SPAWNING_ACTION_OPENING_MOUTH 0x2
#define RIDLEY_SPAWNING_ACTION_SPITTING_FIREBALLS 0x3
#define RIDLEY_SPAWNING_ACTION_CLOSING_MOUTH 0x4
#define RIDLEY_SPAWNING_ACTION_TURNING_AROUND_INIT 0x5
#define RIDLEY_SPAWNING_ACTION_TURNING_AROUND_FIRST_PART 0x6
#define RIDLEY_SPAWNING_ACTION_TURNING_AROUND_SECOND_PART 0x7
#define RIDLEY_SPAWNING_ACTION_TAKING_OFF 0x8
#define RIDLEY_SPAWNING_ACTION_UNKNOWN 0x9

// Samus grabbed
#define RIDLEY_SAMUS_GRABBED_ACTION_NONE 0x0
#define RIDLEY_SAMUS_GRABBED_ACTION_CARRYING_SAMUS 0x1
#define RIDLEY_SAMUS_GRABBED_ACTION_LIFTING_SAMUS 0x2
#define RIDLEY_SAMUS_GRABBED_ACTION_SAMUS_LIFTED 0x3
#define RIDLEY_SAMUS_GRABBED_ACTION_OPENING_MOUTH 0x4
#define RIDLEY_SAMUS_GRABBED_ACTION_SPITTING_FIREBALLS 0x5
#define RIDLEY_SAMUS_GRABBED_ACTION_RELEASING_SAMUS 0x6


// Small fireball attack
#define RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_GOING_DOWN 0x0
#define RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_DELAY_BEFORE_OPENING_MOUTH 0x1
#define RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_OPENING_MOUTH 0x2
#define RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_SPITTING_FIREBALLS 0x3
#define RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_CLOSING_MOUTH 0x4
#define RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_TAKING_OFF 0x8

// Ridley tail

#define RIDLEY_TAIL_POSE_IDLE 0x9
#define RIDLEY_TAIL_POSE_MOVE_TO_ATTACK 0x43
#define RIDLEY_TAIL_POSE_SETTING_UP_ATTACK 0x45
#define RIDLEY_TAIL_POSE_CHARGING_ATTACK 0x47
#define RIDLEY_TAIL_POSE_FIRST_VERTICAL_ATTACK 0x49
#define RIDLEY_TAIL_POSE_VERTICAL_ATTACK 0x4B
#define RIDLEY_TAIL_POSE_LAST_VERTICAL_ATTACK 0x4D
#define RIDLEY_TAIL_POSE_DIAGONAL_ATTACK 0x4F
#define RIDLEY_TAIL_POSE_BACK_TO_IDLE 0x51
#define RIDLEY_TAIL_POSE_DEAD 0x62

#define RIDLEY_TAIL_PART_BODY_ATTACHMENT 0x0
#define RIDLEY_TAIL_PART_RIGHT_LEFT 0x1
#define RIDLEY_TAIL_PART_RIGHT_MIDDLE 0x2
#define RIDLEY_TAIL_PART_RIGHT_MOST 0x3
#define RIDLEY_TAIL_PART_LEFT_RIGHT 0x4
#define RIDLEY_TAIL_PART_LEFT_MIDDLE 0x5
#define RIDLEY_TAIL_PART_LEFT_MOST 0x6
#define RIDLEY_TAIL_PART_TIP 0x7

// Ridley part

#define RIDLEY_PART_POSE_IDLE 0x9
#define RIDLEY_PART_POSE_DYING 0x62

#define RIDLEY_PART_LEFT_WING 0x0
#define RIDLEY_PART_HEAD 0x1
#define RIDLEY_PART_BODY 0x2
#define RIDLEY_PART_CLAW 0x3
#define RIDLEY_PART_TAIL 0x4
#define RIDLEY_PART_RIGHT_WING 0x5

// Ridley fireball

#define RIDLEY_FIREBALL_PART_TOP 0x0
#define RIDLEY_FIREBALL_PART_MIDDLE_TOP 0x1
#define RIDLEY_FIREBALL_PART_MIDDLE 0x2
#define RIDLEY_FIREBALL_PART_MIDDLE_BOTTOM 0x3
#define RIDLEY_FIREBALL_PART_BOTTOM 0x4
#define RIDLEY_FIREBALL_PART_FLOATING_PATTERN 0x80
#define RIDLEY_FIREBALL_PART_SAMUS_GRABBED 0x88

#define RIDLEY_FIREBALL_POSE_MOVE_DESCENDING_PATTERN 0x9
#define RIDLEY_FIREBALL_POSE_MOVE_ASCENDING_PATTERN 0x23
#define RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL_INIT 0x24
#define RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL 0x25
#define RIDLEY_FIREBALL_POSE_MOVE_FLOATING_PATTERN 0x27
#define RIDLEY_FIREBALL_POSE_MOVE_DIAGONAL_PATTERN 0x29
#define RIDLEY_FIREBALL_POSE_DESTROY 0x42


void RidleySyncSubSprites(void);
void RidleyTailSyncSubSprites(void);
void RidleyIdleYFloatingMovement(void);
void RidleySpawnSpittingFireballsYFloatingMovement(void);
void RidleyUpdateHealth(void);
u32 RidleyCheckGrabbing(u16 yPosition, u16 xPosition);
void RidleyPartClawIdle(u8 ramSlot);
void RidleyTailCheckStartScreenShakeVerticalTailAttack(void);
u8 RidleyTailAttacksXMove(u16 movement);
void RidleyTailAttacksYMove(u16 movement);
void RidleySpawnAscendingFireball(u16 timer);
void RidleyInit(void);
void RidleyCheckPlayCutscene(void);
void RidleySpawning(void);
void RidleyIdleInit(void);
void RidleyIdle(void);
void RidleyTurningAroundInit(void);
void RidleyTurningAroundFirstPart(void);
void RidleyTurningAroundSecondPart(void);
void RidleySmallFireballsAttackInit(void);
void RidleySmallFireballsAttack(void);
void RidleyTailAttacksInit(void);
void Ridley_Empty(void);
void RidleyBigFireballsAttackInit(void);
void RidleyBigFireballsAttack(void);
void RidleyDying(void);
void RidleyPartInit(void);
void RidleyPartWingPlaySound(u8 ramSlot);
void RidleyPartWingSetPaletteOffset(void);
void RidleyPartSyncPalette(u8 ramSlot);
void RidleyPartClawUpdateSidesHitbox(void);
void RidleyTailDead(void);
void RidleyTailInit(void);
void RidleyTailIdle(void);
void RidleyTailCheckMovingToAttackAnimEnded(void);
void RidleyTailSettingUpAttack(void);
void RidleyTailChargingAttack(void);
void RidleyTailFirstVerticalAttack(void);
void RidleyTailVerticalAttack(void);
void RidleyTailLastVerticalAttack(void);
void RidleyTailDiagonalAttack(void);
void RidleyTailCheckBackToIdleAnimEnded(void);
void RidleyFireballCheckSlideOnWall(void);
void RidleyFireballInit(void);
void RidleyFireballMoveDiagonalPattern(void);
void RidleyFireballMoveFloatingPattern(void);
void RidleyFireballMoveDescendingPattern(void);
void RidleyFireballMoveAscendingPattern(void);
void RidleyFireballSlideOnWallInit(void);
void RidleyFireballSlideOnWall(void);
void Ridley(void);
void RidleyTail(void);
void RidleyPart(void);
void RidleyFireball(void);

#endif /* RIDLEY_AI_H */