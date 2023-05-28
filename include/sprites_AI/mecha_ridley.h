#ifndef MECHA_RIDLEY_AI_H
#define MECHA_RIDLEY_AI_H

#include "types.h"

#define MECHA_RIDLEY_POSE_CRAWLING_INIT 0x1
#define MECHA_RIDLEY_POSE_DELAY_BEFORE_CRAWLING 0x2
#define MECHA_RIDLEY_POSE_CRAWLING 0x3
#define MECHA_RIDLEY_POSE_DELAY_BEFORE_IDLE 0x4
#define MECHA_RIDLEY_POSE_IDLE 0x9
#define MECHA_RIDLEY_POSE_CLAW_ATTACK 0x22
#define MECHA_RIDLEY_POSE_STANDING_UP 0x23
#define MECHA_RIDLEY_POSE_CURLED_UP 0x25
#define MECHA_RIDLEY_POSE_RETRACTING 0x27
#define MECHA_RIDLEY_POSE_CRAWLING_BACKWARDS 0x29
#define MECHA_RIDLEY_POSE_STANDING_FOR_FIREBALL_ATTACK_INIT 0x34
#define MECHA_RIDLEY_POSE_STANDING_FOR_FIREBALL_ATTACK 0x35
#define MECHA_RIDLEY_POSE_OPENING_MOUTH 0x37
#define MECHA_RIDLEY_POSE_FIREBALL_ATTACK 0x39
#define MECHA_RIDLEY_POSE_CLOSING_MOUTH 0x3B
#define MECHA_RIDLEY_POSE_RETRACTING_AFTER_FIREBALL_ATTACK 0x3D
#define MECHA_RIDLEY_POSE_DYING_INIT 0x62
#define MECHA_RIDLEY_POSE_DYING_GLOW_FADING 0x64
#define MECHA_RIDLEY_POSE_DYING_STANDING_UP 0x67
#define MECHA_RIDLEY_POSE_SPAWN_DROPS 0x68
#define MECHA_RIDLEY_POSE_FIRST_EYE_GLOW 0x69
#define MECHA_RIDLEY_POSE_SECOND_EYE_GLOW 0x6A

#define MECHA_RIDLEY_SAMUS_POSITION_LOW 0x0
#define MECHA_RIDLEY_SAMUS_POSITION_MIDDLE 0x1
#define MECHA_RIDLEY_SAMUS_POSITION_HIGH 0x2

// Mecha ridley part

#define MECHA_RIDLEY_PART_RIGHT_ARM 0x0
#define MECHA_RIDLEY_PART_EYE 0x1
#define MECHA_RIDLEY_PART_HEAD 0x2
#define MECHA_RIDLEY_PART_NECK 0x3
#define MECHA_RIDLEY_PART_COVER 0x4
#define MECHA_RIDLEY_PART_CORE 0x5
#define MECHA_RIDLEY_PART_TORSO 0x6
#define MECHA_RIDLEY_PART_WAISTBAND 0x7
#define MECHA_RIDLEY_PART_LEFT_ARM 0x8
#define MECHA_RIDLEY_PART_TAIL 0x9
#define MECHA_RIDLEY_PART_MISSILE_LAUNCHER 0xA

#define MECHA_RIDLEY_PART_POSE_RIGHT_ARM_IDLE 0x8
#define MECHA_RIDLEY_PART_POSE_LEFT_ARM_IDLE 0x22
#define MECHA_RIDLEY_PART_POSE_NECK_IDLE 0x24
#define MECHA_RIDLEY_PART_POSE_EYE_IDLE 0x26
#define MECHA_RIDLEY_PART_POSE_MISSILE_LAUNCHER_IDLE 0x28
#define MECHA_RIDLEY_PART_POSE_COVER_IDLE 0x2A
#define MECHA_RIDLEY_PART_POSE_HEAD_IDLE 0x2C
#define MECHA_RIDLEY_PART_IDLE 0x61
#define MECHA_RIDLEY_PART_POSE_COVER_DESTROYED 0x62
#define MECHA_RIDLEY_PART_POSE_COVER_BROKEN 0x67

// Eye part

#define LASER_DIRECTION_FORWARD 0
#define LASER_DIRECTION_SLIGHTLY_DOWN 1
#define LASER_DIRECTION_DOWN 2
#define LASER_DIRECTION_SLIGHTLY_UP 3
#define LASER_DIRECTION_UP 4

#define EYE_STATE_IDLE 0
#define EYE_STATE_BLINKING_INIT 1
#define EYE_STATE_LASER_ATTACK_INIT 2
#define EYE_STATE_LASER_ATTACK 3
#define EYE_STATE_LASER_SET_IDLE 4
#define EYE_STATE_LASER_SET_INACTIVE 5
#define EYE_STATE_LASER_SET_DYING 6

// Missile launcher part

#define MISSILE_LAUNCHER_STATE_IDLE 0
#define MISSILE_LAUNCHER_STATE_MISSILE_ATTACK_INIT 1
#define MISSILE_LAUNCHER_STATE_OPENING 2
#define MISSILE_LAUNCHER_STATE_OPENED 3
#define MISSILE_LAUNCHER_STATE_CLOSING 4

// Firenballs

#define FIREBALL_LOW 0
#define FIREBALL_HIGH 1



void MechaRidleySyncSubSprites(void);
void MechaRidleyPartGreenGlow(void);
void MechaRidleyLoadFireballsGfx(void);
void MechaRidleyLoadMissilesGfx(void);
u8 MechaRidleyUpdateHeight(void);
void MechaRidleyCrawlingBackwardsInit(u8 leftArmSlot);
void MechaRidleyClawAttackInit(u8 leftArmSlot);
void MechaRidleyInit(void);
void MechaRidleyStartWalking(void);
void MechaRidleyDelayBeforeCrawling(void);
void MechaRidleyCrawling(void);
void MechaRidleyStartBattle(void);
u8 MechaRidleyCheckStartFireballAttack(u8 ramSlot);
void MechaRidleyIdle(void);
void MechaRidleyClawAttack(void);
void MechaRidleyStandingUp(void);
void MechaRidleyCurledUp(void);
void MechaRidleyRetracting(void);
void MechaRidleyCrawlingBack(void);
void MechaRidleyStandingForFireballsInit(void);
void MechaRidleyStandingForFireballs(void);
void MechaRidleyCheckOpeningMouthAnimEnded(void);
void MechaRidleyFireballsAttack(void);
void MechaRidleyCheckClosingMouthAnimEnded(void);
void MechaRidleyRetractingAfterFireballAttack(void);
void MechaRidleyDyingInit(void);
void MechaRidleyDying(void);
void MechaRidleyGlowFading(void);
void MechaRidleySpawnDrops(void);
void MechaRidleyFirstEyeGlow(void);
void MechaRidleySecondEyeGlow(void);
void MechaRidleyPartInit(void);
void MechaRidleyPartHeadIdle(void);
void MechaRidleyPartCoverIdle(void);
void MechaRidleyPartCoreCoverExplosion(void);
void MechaRidleyPartMissileLauncherIdle(void);
void MechaRidleyPartEyeIdle(void);
void MechaRidleyPartRightArmIdle(void);
void MechaRidleyPartLeftArmIdle(void);
void MechaRidleyPartNeckIdle(void);
void MechaRidley(void);
void MechaRidleyPart(void);
void MechaRidleyLaser(void);
void MechaRidleyMissile(void);
void MechaRidleyFireball(void);

#endif /* MECHA_RIDLEY_AI_H */