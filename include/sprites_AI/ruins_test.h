#ifndef RUINS_TEST_AI_H
#define RUINS_TEST_AI_H

#include "types.h"

#define RUINS_TEST_FIGHT_STAGE_ON_GOING 0x0
#define RUINS_TEST_FIGHT_STAGE_LAST_SYMBOL_HIT 0x1
#define RUINS_TEST_FIGHT_STAGE_GHOST_AT_CENTER 0x2
#define RUINS_TEST_FIGHT_STAGE_GHOST_FADING_BACK 0x3
#define RUINS_TEST_FIGHT_STAGE_GHOST_STARTING_TO_DISAPPEAR 0x4
#define RUINS_TEST_FIGHT_STAGE_STARTING_CUTSCENE_FADE 0x5
#define RUINS_TEST_FIGHT_STAGE_STARTING_CUTSCENE 0x6
#define RUINS_TEST_FIGHT_STAGE_STARTING_SUIT_ANIM 0x7
#define RUINS_TEST_FIGHT_STAGE_SUIT_ANIM_ENDED 0x8

#define RUINS_TEST_POSE_SPAWNING 0x1
#define RUINS_TEST_POSE_TURNING_INTO_REFLECTION 0x2
#define RUINS_TEST_POSE_FREE_SAMUS 0x3
#define RUINS_TEST_POSE_CHECK_SAMUS_NOT_FACING_BACKGROUND 0x4
#define RUINS_TEST_POSE_MOTIONLESS 0x8
#define RUINS_TEST_POSE_SPAWN_GHOST 0x9
#define RUINS_TEST_POSE_MOVING_INIT 0x22
#define RUINS_TEST_POSE_MOVING_CIRCLE_PATTERN 0x23
#define RUINS_TEST_POSE_MOVING_ATOM_PATTERN 0x25
#define RUINS_TEST_POSE_BACK_TO_CENTER 0x67
#define RUINS_TEST_POSE_CHECK_GHOST_DISAPPEARING 0x68
#define RUINS_TEST_POSE_DESPAWN 0x69
#define RUINS_TEST_POSE_DEAD 0x6A

// Ruins test ghost

#define RUINS_TEST_GHOST_PART_GHOST 0x0
#define RUINS_TEST_GHOST_PART_FIRST_SYMBOL 0x1
#define RUINS_TEST_GHOST_PART_SECOND_SYMBOL 0x2
#define RUINS_TEST_GHOST_PART_THIRD_SYMBOL 0x3
#define RUINS_TEST_GHOST_PART_FOURTH_SYMBOL 0x4

#define RUINS_TEST_GHOST_POSE_GHOST_SPAWN 0x8
#define RUINS_TEST_GHOST_POSE_GHOST_IDLE 0x9
#define RUINS_TEST_GHOST_POSE_SYMBOL_MOVING 0x23
#define RUINS_TEST_GHOST_POSE_SYMBOL_PLACING 0x25
#define RUINS_TEST_GHOST_POSE_SYMBOL_SET_GHOST_DISAPPEARING 0x26
#define RUINS_TEST_GHOST_POSE_SYMBOL_WAIT_FOR_END_OF_FIGHT 0x27
#define RUINS_TEST_GHOST_POSE_SYMBOL_DELAY_BEFORE_PLACING_END_OF_FIGHT 0x29
#define RUINS_TEST_GHOST_POSE_SYMBOL_PLACING_END_OF_FIGHT 0x2B
#define RUINS_TEST_GHOST_POSE_GHOST_DESPAWN 0x43
#define RUINS_TEST_GHOST_POSE_SYMBOL_DO_NOTHING 0x6C

// Ruins test symbol

#define RUINS_TEST_SYMBOL_POSE_DELAY_BEFORE_MUSIC 0x8
#define RUINS_TEST_SYMBOL_POSE_UPDATE_PALETTE 0x9
#define RUINS_TEST_SYMBOL_POSE_MERGING 0x23
#define RUINS_TEST_SYMBOL_POSE_DISAPPEARING 0x25

// Ruins test samus reflection start

#define RUINS_TEST_SAMUS_REFLECTION_START_POSE_UPDATE_GFX_PAL 0x8
#define RUINS_TEST_SAMUS_REFLECTION_START_POSE_SPAWN_PARTICLE 0x9

// Ruins test reflection cover

#define RUINS_TEST_REFLECTION_COVER_POSE_IDLE 0x8
#define RUINS_TEST_REFLECTION_COVER_POSE_KILL 0x9

// Ruins test ghost outline

#define RUINS_TEST_GHOST_OUTLINE_PART_OUTLINE 0x0
#define RUINS_TEST_GHOST_OUTLINE_PART_SHOOTING_GROUND_LIGHTNING 0x1
#define RUINS_TEST_GHOST_OUTLINE_PART_SHOOTING_LIGHTNING 0x2

// Ruins test shootable symbol

#define RUINS_TEST_SHOOTABLE_SYMBOL_POSE_SPAWNING 0x9
#define RUINS_TEST_SHOOTABLE_SYMBOL_POSE_SPAWNED 0x23
#define RUINS_TEST_SHOOTABLE_SYMBOL_POSE_DESPAWNING 0x25
#define RUINS_TEST_SHOOTABLE_SYMBOL_POSE_TURNING_INTO_SYMBOL 0x27

// Ruins test samus reflection end

#define RUINS_TEST_SAMUS_REFLECTION_END_POSE_SUITLESS 0x8
#define RUINS_TEST_SAMUS_REFLECTION_END_POSE_FULLSUIT 0x9
#define RUINS_TEST_SAMUS_REFLECTION_END_POSE_UPDATE_PALETTE 0x23
#define RUINS_TEST_SAMUS_REFLECTION_END_POSE_SET_FADING_STARTED 0x25

// Ruins test lightning

#define RUINS_TEST_LIGHTNING_PART_GROUND_RIGHT 0x0
#define RUINS_TEST_LIGHTNING_PART_GROUND 0x1
#define RUINS_TEST_LIGHTNING_PART_STATIC 0x2

#define RUINS_TEST_LIGHTNING_POSE_GOING_DOWN 0x9
#define RUINS_TEST_LIGHTNING_POSE_GOING_ON_GROUND 0x23
#define RUINS_TEST_LIGHTNING_POSE_ON_GROUND_HORIZONTAL 0x25
#define RUINS_TEST_LIGHTNING_POSE_ON_GROUND_VERTICAL 0x27

void RuinsTestCalculateDelay(u8 delay);
void RuinsTestChangeCCAA(u8 caa);
void RuinsTestMoveToPosition(u16 yTarget, u16 xTarget, u16 yPosition, u16 xPosition, u16 speedMultiplier, u16 speed);
u8 RuinsTestProjectileCollision(void);
u8 RuinsTestCheckHitByChargedPistol(void);
u8 RuinsTestCheckSymbolShooted(void);
u8 RuinsTestCheckSamusHurting(void);
u8 RuinsTestUpdateSymbol(void);
void RuinsTestGhostMove(u8 speed);
void RuinsTestInit(void);
void RuinsTestSpawning(void);
void RuinsTestTurningIntoReflection(void);
void RuinsTestFreeSamus(void);
void RuinsTestCheckSamusNotFacingBackground(void);
void RuinsTestMotionless(void);
void RuinsTestSpawnGhost(void);
void RuinsTestMovingInit(void);
void RuinsTestMoveCirclePattern(void);
void RuinsTestMoveAtomPattern(void);
void RuinsTestMoveToCenter(void);
void RuinsTestCheckIsGhostDisappearing(void);
void RuinsTestDespawn(void);
void RuinsTestGhostInit(void);
void RuinsTestGhostSpawn(void);
void RuinsTestGhostIdle(void);
void RuinsTestGhostDespawn(void);
void RuinsTestGhostMoveSymbolToPlace(void);
void RuinsTestGhostSymbolPlacing(void);
void RuinsTestGhostSymbolSetGhostDisappearing(void);
void RuinsTestGhostSymbolWaitForEndOfFight(void);
void RuinsTestGhostSymbolDelayBeforePlacingAtEndOfFight(void);
void RuinsTest(void);
void RuinsTestSymbol(void);
void RuinsTestSamusReflectionStart(void);
void RuinsTestReflectionCover(void);
void RuinsTestGhostOutline(void);
void RuinsTestShootableSymbol(void);
void RuinsTestGhost(void);
void RuinsTestSamusReflectionEnd(void);
void RuinsTestLightningOnGroundInit(void);
void RuinsTestLightning(void);

#endif /* RUINS_TEST_AI_H */