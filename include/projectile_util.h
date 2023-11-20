#ifndef PROJECTILE_UTIL_H
#define PROJECTILE_UTIL_H

#include "types.h"
#include "oam.h"
#include "structs/projectile.h"
#include "structs/sprite.h"

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
u32 ProjectileCheckVerticalCollisionAtPosition(struct ProjectileData* pProj);
void ProjectileSetTrail(struct ProjectileData* pProj, u8 effect, u8 delay);
void ProjectileMoveTumbling(struct ProjectileData* pProj);
void ProjectileCheckHitBlock(struct ProjectileData* pProj, u8 caa, u8 effect);
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

#endif /* PROJECTILE_UTIL_H */
