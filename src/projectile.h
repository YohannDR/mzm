#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "types.h"
#include "oam.h"
#include "particle.h"
#include "sprite.h"
#include "clipdata.h"
#include "samus.h"

// Globals

extern struct ProjectileData gProjectileData[16];
extern u16 gArmCannonY;
extern u16 gArmCannonX;


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

struct ProjectileData {
    u8 status;
    struct FrameData* oam_pointer;
    u16 y_position;
    u16 x_position;
    u16 curr_anim_frame;
    u8 anim_duration_counter;
    u8 type;
    u8 direction;
    u8 movement_stage;
    u8 draw_distance_offset;
    u8 timer;
    i16 hitbox_top_offset;
    i16 hitbox_bottom_offset;
    i16 hitbox_left_offset;
    i16 hitbox_right_offset;
};
struct PowerBomb {
    u8 animation_state;
    u8 stage;
    u8 semi_minor_axis;
    u8 unknown;
    u16 x_position;
    u16 y_position;
    i16 hitbox_left_offset;
    i16 hitbox_right_offset;
    i16 hitbox_top_offset;
    i16 hitbox_bottom_offset;
    u8 power_bomb_placed;
    u8 owner;
    u8 also_always_zero;
};

typedef (*ProjFunc_T)(struct ProjectileData*);

void ProjectileSetBeamParticleEffect(void);
u8 ProjectileCheckNumberOfProjectiles(u8 type, u8 limit);
u8 ProjectileInit(u8 type, u16 y_position, u16 x_position);
void ProjectileUpdate(void);
void ProjectileUpdateAnimation(struct ProjectileData* pProj);
void ProjectileDrawAllStatusFalse(void);
void ProjectileDrawAllStatusTrue(void);
void ProjectileDraw(struct ProjectileData* pProj);
void ProjectileCheckDespawn(struct ProjectileData* pProj);
void ProjectileLoadGraphics(void);
void ProjectileCallLoadGraphicsAndClearProjectiles(void);
void ProjectileMove(struct ProjectileData* pProj, u8 distance);
u8 ProjectileCheckHittingSolidBlock(u16 y_position, u16 x_position);
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
void ProjectileHitSprite(struct SpriteData* pSprite, u16 y_position, u16 x_position, u16 damage, u8 effect);
void ProjectileNonIceChargedHitSprite(struct SpriteData* pSprite, u16 y_position, u16 x_position, u16 damage, u8 effect);
void ProjectileFreezeSprite(struct SpriteData* pSprite, u8 freeze_timer);
void ProjectileIceBeamHittingSprite(struct SpriteData* pSprite, u16 y_position, u16 x_position, u16 damage, u8 effect);
void ProjectileChargedIceBeamHittingSprite(struct SpriteData* pSprite, u16 y_position, u16 x_position, u16 damage, u8 effect);
void ProjectileStartTumblingMissile(struct SpriteData* pSprite, struct ProjectileData* pProj, u8 type);
void ProjectileStartTumblingMissileCurrentSprite(struct ProjectileData* pProj, u8 type);
void ProjectileMissileHitSprite(struct SpriteData* pSprite, struct ProjectileData* pProj, u16 y_position, u16 x_position);
void ProjectileSuperMissileHitSprite(struct SpriteData* pSprite, struct ProjectileData* pProj, u16 y_position, u16 x_position);
void ProjectileBombMissileHitSprite(struct SpriteData* pSprite, u16 y_position, u16 x_position);
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