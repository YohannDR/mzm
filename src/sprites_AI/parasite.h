#ifndef PARASITE_AI_H
#define PARASITE_AI_H

#include "../types.h"
#include "../sprite.h"

u8 ParasiteCount(void);
void ParasiteInit(struct SpriteData* pSprite);
void ParasiteGrabSamus(struct SpriteData* pSprite);
void ParasiteSamusGrabbed(struct SpriteData* pSprite);
void ParasiteExpulsedGFXInit(struct SpriteData* pSprite);
void ParasiteExpulsed(struct SpriteData* pSprite);
void ParasiteExpulsedAfterGrabbingObject(struct SpriteData* pSprite);
void ParasiteFalling(struct SpriteData* pSprite);
void ParasiteJumping(struct SpriteData* pSprite);
void ParasiteMultipleJumping(struct SpriteData* pSprite);
void ParasiteJumpingSecondPart(struct SpriteData* pSprite);
void ParasiteMultipleJumpingSecondPart(struct SpriteData* pSprite);
void ParasiteCrouchingGFXInit(struct SpriteData* pSprite);
void ParasiteWalking(struct SpriteData* pSprite);
void ParasiteMultipleWalking(struct SpriteData* pSprite);
void ParasiteUncrouchingGFXInit(struct SpriteData* pSprite);
void ParasiteCheckTurningAroundAnimEnded(struct SpriteData* pSprite);
void ParasiteCheckTurningAroundAnimNearEnded(struct SpriteData* pSprite);
void ParasiteLandingGFXInit(struct SpriteData* pSprite);
void ParasiteLanding(struct SpriteData* pSprite);
void ParasiteNormalFallingInit(struct SpriteData* pSprite);
void ParasiteNormalFalling(struct SpriteData* pSprite);
void ParasiteDyingGFXInit(struct SpriteData* pSprite);
void ParasiteCheckDyingAnimEnded(struct SpriteData* pSprite);
void ParasiteCheckEvent(struct SpriteData* pSprite);
void ParasiteGrabGeron(struct SpriteData* pSprite);
void ParasiteGeronGrabbed(struct SpriteData* pSprite);
void ParasiteBombCollision(struct SpriteData* pSprite);
void ParasiteMultiple(void);
void Parasite(void);

#endif /* PARASITE_AI_H */