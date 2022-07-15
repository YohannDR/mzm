#ifndef IMAGO_LARVA_AI_H
#define IMAGO_LARVA_AI_H

#include "../types.h"
#include "../sprite.h"

void ImagoLarvaSyncSubSprites(struct SubSpriteData* pSub);
void ImagoLarvaBellyFlashing(void);
void ImagoLarvaInit(struct SubSpriteData* pSub);
void ImagoLarvaDetectSamus(struct SubSpriteData* pSub);
void ImagoLarvaHittingWallGFXInit(struct SubSpriteData* pSub);
void ImagoLarvaCallBellyFlashing(void);
void ImagoLarvaGettingHit(struct SubSpriteData* pSub);
void ImagoLarvaRetreating(struct SubSpriteData* pSub);
void ImagoLarvaRetreatGFXInit(struct SubSpriteData* pSub);
void ImagoLarvaAttacking(struct SubSpriteData* pSub);
void ImagoLarvaTakingDamageGFXInit(struct SubSpriteData* pSub);
void ImagoLarvaCheckTakingDamageAnimEnded(void);
void ImagoLarvaBeforeDying(struct SubSpriteData* pSub);
void ImagoLarvaCheckDyingAnimEnded(void);
void ImagoLarvaDead(void);
void ImagoLarvaOutsideInit(void);
void ImagoLarvaOutsideRetracting(struct SubSpriteData* pSub);
void ImagoLarvaOutsideAttacking(struct SubSpriteData* pSub);
void ImagoLarvaOutsideRemoveOrbs(void);
void ImagoLarvaOutsideAttackingAnim(void);
void ImagoLarvaOutsideCheckAttackingAnimEnded(void);
void ImagoLarvaOutsideDead(void);
void ImagoLarva(void);
void ImagoLarvaOutside(void);

#endif /* IMAGO_LARVA_AI_H */