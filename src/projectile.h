#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "types.h"
#include "oam.h"
#include "particle.h"
#include "sprite.h"
#include "clipdata.h"
#include "samus.h"

// Globals

#define MAX_AMOUNT_OF_PROJECTILES 16

extern struct ProjectileData gProjectileData[MAX_AMOUNT_OF_PROJECTILES];
extern u16 gArmCannonY;
extern u16 gArmCannonX;

// Defines

#define PROJECTILE_NONE 0x0
#define PROJECTILE_BEAM 0x1
#define PROJECTILE_MISSILE 0x2
#define PROJECTILE_SUPER_MISSILE 0x3
#define PROJECTILE_BOMB 0x4
#define PROJECTILE_POWER_BOMB 0x5
#define PROJECTILE_CHARGED_BEAM 0x6

#define PROJ_STATUS_NONE 0x0
#define PROJ_STATUS_EXISTS 0x1
#define PROJ_STATUS_ON_SCREEN 0x2
#define PROJ_STATUS_NOT_DRAWN 0x4
#define PROJ_STATUS_HIGH_PRIORITY 0x8
#define PROJ_STATUS_CAN_AFFECT_ENVIRONMENT 0x10
#define PROJ_STATUS_YFLIP 0x20
#define PROJ_STATUS_XFLIP 0x40
#define PROJ_STATUS_UNKNOWN 0x80

#define PROJ_TYPE_BEAM 0x0
#define PROJ_TYPE_LONG_BEAM 0x1
#define PROJ_TYPE_ICE_BEAM 0x2
#define PROJ_TYPE_WAVE_BEAM 0x3
#define PROJ_TYPE_PLASMA_BEAM 0x4
#define PROJ_TYPE_PISTOL 0x5
#define PROJ_TYPE_CHARGED_BEAM 0x6
#define PROJ_TYPE_CHARGED_LONG_BEAM 0x7
#define PROJ_TYPE_CHARGED_ICE_BEAM 0x8
#define PROJ_TYPE_CHARGED_WAVE_BEAM 0x9
#define PROJ_TYPE_CHARGED_PLASMA_BEAM 0xA
#define PROJ_TYPE_CHARGED_PISTOL 0xB
#define PROJ_TYPE_MISSILE 0xC
#define PROJ_TYPE_SUPER_MISSILE 0xD
#define PROJ_TYPE_BOMB 0xE
#define PROJ_TYPE_POWER_BOMB 0xF


#define BOMB_STAGE_INIT 0x0
#define BOMB_STAGE_FIRST_SPIN 0x1
#define BOMB_STAGE_FAST_SPIN 0x2
#define BOMB_STAGE_EXPLODING 0x3
#define BOMB_STAGE_PLACED_ON_LAUNCHER 0x4
#define BOMB_STAGE_FIRST_SPIN_ON_LAUNCHER 0x5
#define BOMB_STAGE_FAST_SPIN_ON_LAUNCHER 0x6
#define BOMB_STAGE_EXPLODING_ON_LAUNCHER 0x7

// Structs

struct ProjectileData {
    u8 status;
    struct FrameData* pOam;
    u16 yPosition;
    u16 xPosition;
    u16 currentAnimationFrame;
    u8 animationDurationCounter;
    u8 type;
    u8 direction;
    u8 movementStage;
    u8 draw_distance_offset;
    u8 timer;
    i16 hitboxTopOffset;
    i16 hitboxBottomOffset;
    i16 hitboxLeftOffset;
    i16 hitboxRightOffset;
};

// Typedef

typedef void (*ProjFunc_T)(struct ProjectileData*);

// Functions

void ProjectileSetBeamParticleEffect(void);
u8 ProjectileCheckNumberOfProjectiles(u8 type, u8 limit);
u8 ProjectileInit(u8 type, u16 yPosition, u16 xPosition);
void ProjectileUpdate(void);
void ProjectileUpdateAnimation(struct ProjectileData* pProj);
void ProjectileDrawAllStatusFalse(void);
void ProjectileDrawAllStatusTrue(void);
void ProjectileDraw(struct ProjectileData* pProj);
void ProjectileCheckDespawn(struct ProjectileData* pProj);
void ProjectileLoadGraphics(void);
void ProjectileCallLoadGraphicsAndClearProjectiles(void);
void ProjectileMove(struct ProjectileData* pProj, u8 distance);
u32 ProjectileCheckHittingSolidBlock(u32 yPosition, u32 xPosition);
u8 ProjectileCheckVerticalCollisionAtPosition(struct ProjectileData* pProj);
void ProjectileSetTrail(struct ProjectileData* pProj, u8 effect, u8 delay);
void ProjectileMoveTumbling(struct ProjectileData* pProj);
void ProjectileCheckHitBlock(struct ProjectileData* pProj, u8 ccaa, u8 effect);
void ProjectileCheckHittingSprite(void);
u16 ProjectileGetSpriteWeakness(struct SpriteData* pSprite);
u8 ProjectileIceBeamDealDamage(struct SpriteData* pSprite, u16 damage);
u8 ProjectileDealDamage(struct SpriteData* pSprite, u16 damage);
struct SpriteData* ProjectileHitSpriteImmuneToProjectiles(struct SpriteData* pSprite);
struct SpriteData* ProjectileHitSolidSprite(struct SpriteData* pSprite);
void ProjectilePowerBombDealDamage(struct SpriteData* pSprite);
void ProjectileHitSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition, u16 damage, u8 effect);
void ProjectileNonIceChargedHitSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition, u16 damage, u8 effect);
void ProjectileFreezeSprite(struct SpriteData* pSprite, u8 freezeTimer);
void ProjectileIceBeamHittingSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition, u16 damage, u8 effect);
void ProjectileChargedIceBeamHittingSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition, u16 damage, u8 effect);
void ProjectileStartTumblingMissile(struct SpriteData* pSprite, struct ProjectileData* pProj, u8 type);
void ProjectileStartTumblingMissileCurrentSprite(struct ProjectileData* pProj, u8 type);
void ProjectileMissileHitSprite(struct SpriteData* pSprite, struct ProjectileData* pProj, u16 yPosition, u16 xPosition);
void ProjectileSuperMissileHitSprite(struct SpriteData* pSprite, struct ProjectileData* pProj, u16 yPosition, u16 xPosition);
void ProjectileBombHitSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition);
void ProjectileProcessNormalBeam(struct ProjectileData* pProj);
void ProjectileProcessLongBeam(struct ProjectileData* pProj);
void ProjectileProcessIceBeam(struct ProjectileData* pProj);
u32 ProjectileCheckWaveBeamHittingBlocks(struct ProjectileData* pProj);
void ProjectileProcessWaveBeam(struct ProjectileData* pProj);
void ProjectileProcessPlasmaBeam(struct ProjectileData* pProj);
void ProjectileProcessPistol(struct ProjectileData* pProj);
void ProjectileProcessChargedNormalBeam(struct ProjectileData* pProj);
void ProjectileProcessChargedLongBeam(struct ProjectileData* pProj);
void ProjectileProcessChargedIceBeam(struct ProjectileData* pProj);
void ProjectileProcessChargedWaveBeam(struct ProjectileData* pProj);
void ProjectileProcessChargedPlasmaBeam(struct ProjectileData* pProj);
void ProjectileProcessChargedPistol(struct ProjectileData* pProj);
void ProjectileDecrementMissileCounter(struct ProjectileData* pProj);
void ProjectileProcessMissile(struct ProjectileData* pProj);
void ProjectileDecrementSuperMissileCounter(struct ProjectileData* pProj);
void ProjectileProcessSuperMissile(struct ProjectileData* pProj);
void ProjectileMorphballLauncherCheckLaunchSamus(struct ProjectileData* pProj);
void ProjectileCheckSamusBombBounce(struct ProjectileData* pProj);
void ProjectileProcessBomb(struct ProjectileData* pProj);
void ProjectileProcess_Empty(struct ProjectileData* pProj);
void ProjectileProcessPowerBomb(struct ProjectileData* pProj);

#endif /* PROJECTILE_H */