#ifndef MECHA_RIDLEY_AI_H
#define MECHA_RIDLEY_AI_H

#include "types.h"

#define MECHA_RIDLEY_POSE_CRAWLING_INIT 0x1
#define MECHA_RIDLEY_POSE_DELAY_BEFORE_CRAWLING 0x2
#define MECHA_RIDLEY_POSE_CRAWLING 0x3
#define MECHA_RIDLEY_POSE_DELAY_BEFORE_IDLE 0x4
#define MECHA_RIDLEY_POSE_IDLE 0x9
#define MECHA_RIDLEY_POSE_FIREBALL_ATTACK_INIT 0x34
#define MECHA_RIDLEY_POSE_DYING_INIT 0x62
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

// Cover

#define MECHA_RIDLEY_PART_COVER_POSE_BROKEN 0x67




void MechaRidleySyncSubSprites(void);
void MechaRidleyPartGreeGlow(void);
void MechaRidleyPartLoadWeaponsGFX(void);
void unk_4bc2c(void);
u8 unk_4bcd0(void);
void unk_4bdf8(u8 ramSlot);
void unk_4beb4(u8 ramSlot);
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
void MechaRidleyCheckRetractingHeadBeforeMovingBackAnimEnded(void);
void MechaRidleyMovingBack(void);
void MechaRidleyBeforeFireballs(void);
void MechaRidleyCheckExtendingHeadBeforeFireballsAnimEnded(void);
void MechaRidleyCheckOpeningMouthAnimEnded(void);
void MechaRidleyFireballsAttack(void);
void MechaRidleyCheckClosingMouthAnimEnded(void);
void MechaRidleyCheckRetractingHeadAfterFireballsAnimEnded(void);
void MechaRidleyStartDying(void);
void MechaRidleyDying(void);
void MechaRidleyGlowFading(void);
void MechaRidleySpawnDrops(void);
void MechaRidleyFirstEyeGlow(void);
void MechaRidleySecondEyeGlow(void);
void MechaRidleyPartInit(void);
void MechaRidleyPartHeadIdle(void);
void MechaRidleyPartCoverIdle(void);
void MechaRidleyPartCoreCoverExplosion(void);
void MechaRidleyPartMissileAttack(void);
void MechaRidleyPartLaserAttack(void);
void MechaRidleyPartUpdateHitboxOf_Unk(void);
void MechaRidleyPartUpdateFrontClawHitbox(void);
void MechaRidleyPartUpdateHitboxOf_Unk2(void);
void MechaRidley(void);
void MechaRidleyPart(void);
void MechaRidleyLaser(void);
void MechaRidleyMissile(void);
void MechaRidleyFireball(void);

#endif /* MECHA_RIDLEY_AI_H */