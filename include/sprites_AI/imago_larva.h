#ifndef IMAGO_LARVA_AI_H
#define IMAGO_LARVA_AI_H

#include "types.h"
#include "structs/sprite.h"

#define IMAGO_LARVA_POSE_IDLE_INIT 0x8
#define IMAGO_LARVA_POSE_IDLE 0x9
#define IMAGO_LARVA_POSE_DETECT_SAMUS 0xF
#define IMAGO_LARVA_POSE_RETREATING_INIT 0x22
#define IMAGO_LARVA_POSE_RETREATING 0x23
#define IMAGO_LARVA_POSE_STUNNED_INIT 0x24
#define IMAGO_LARVA_POSE_STUNNED 0x25
#define IMAGO_LARVA_POSE_WARNING_INIT 0x26
#define IMAGO_LARVA_POSE_WARNING 0x27
#define IMAGO_LARVA_POSE_ATTACKING_INIT 0x28
#define IMAGO_LARVA_POSE_ATTACKING 0x29
#define IMAGO_LARVA_POSE_TAKING_DAMAGE_INIT 0x42
#define IMAGO_LARVA_POSE_TAKING_DAMAGE 0x43
#define IMAGO_LARVA_POSE_DYING_INIT 0x62
#define IMAGO_LARVA_POSE_DYING 0x67
#define IMAGO_LARVA_POSE_DEAD 0x68

// Imago larva part

#define IMAGO_LARVA_PART_POSE_DOT_IDLE 0x9
#define IMAGO_LARVA_PART_POSE_DOT_REMOVING 0x23
#define IMAGO_LARVA_PART_POSE_DOT_CHECK_REAPPEAR 0x25
#define IMAGO_LARVA_PART_POSE_DOT_REAPPEARING 0x27
#define IMAGO_LARVA_PART_POSE_SHELL_IDLE 0x42
#define IMAGO_LARVA_PART_POSE_CLAWS_IDLE 0x60
#define IMAGO_LARVA_PART_POSE_DEAD 0x67

#define IMAGO_LARVA_PART_CLAWS 0x0
#define IMAGO_LARVA_PART_RIGHT_DOT 0x1
#define IMAGO_LARVA_PART_MIDDLE_DOT 0x2
#define IMAGO_LARVA_PART_LEFT_DOT 0x3
#define IMAGO_LARVA_PART_SHELL 0x4
#define IMAGO_LARVA_PART_LARVA 0x5

#define IMAGO_LARVA_TAIL_HITBOX (BLOCK_SIZE * 2 - PIXEL_SIZE * 2)
#define IMAGO_LARVA_HEAD_HITBOX (BLOCK_SIZE + HALF_BLOCK_SIZE - PIXEL_SIZE * 2)
#define IMAGO_LARVA_SHELL_TAIL_HITBOX (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + PIXEL_SIZE * 2)
#define IMAGO_LARVA_SHELL_HEAD_HITBOX (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2)


void ImagoLarvaSyncSubSprites(struct SubSpriteData* pSub);
void ImagoLarvaUpdatePalette(void);
void ImagoLarvaInit(struct SubSpriteData* pSub);
void ImagoLarvaDetectSamus(struct SubSpriteData* pSub);
void ImagoLarvaIdleInit(struct SubSpriteData* pSub);
void ImagoLarvaIdle(struct SubSpriteData* pSub);
void ImagoLarvaRetreatingInit(struct SubSpriteData* pSub);
void ImagoLarvaRetreating(struct SubSpriteData* pSub);
void ImagoLarvaStunnedInit(struct SubSpriteData* pSub);
void ImagoLarvaStunned(struct SubSpriteData* pSub);
void ImagoLarvaWarningInit(struct SubSpriteData* pSub);
void ImagoLarvaCheckWarningAnimEnded(struct SubSpriteData* pSub);
void ImagoLarvaAttackingInit(struct SubSpriteData* pSub);
void ImagoLarvaAttacking(struct SubSpriteData* pSub);
void ImagoLarvaTakingDamageInit(struct SubSpriteData* pSub);
void ImagoLarvaTakingDamage(struct SubSpriteData* pSub);
void ImagoLarvaDyingInit(struct SubSpriteData* pSub);
void ImagoLarvaDying(struct SubSpriteData* pSub);
void ImagoLarvaDeath(struct SubSpriteData* pSub);
void ImagoLarvaPartInit(struct SubSpriteData* pSub);
void ImagoLarvaPartShellIdle(struct SubSpriteData* pSub);
void ImagoLarvaPartDotIdle(struct SubSpriteData* pSub);
void ImagoLarvaPartDotCheckDisappearingAnimEnded(struct SubSpriteData* pSub);
void ImagoLarvaPartDotCheckShouldReappear(struct SubSpriteData* pSub);
void ImagoLarvaPartDotCheckAppearingAnimEnded(struct SubSpriteData* pSub);
void ImagoLarvaPartDead(struct SubSpriteData* pSub);
void ImagoLarva(void);
void ImagoLarvaPart(void);

#endif /* IMAGO_LARVA_AI_H */
