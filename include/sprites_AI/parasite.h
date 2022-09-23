#ifndef PARASITE_AI_H
#define PARASITE_AI_H

#include "types.h"
#include "structs/sprite.h"

#define PARASITE_POSE_IDLE_INIT 0x8
#define PARASITE_POSE_IDLE 0x9
#define PARASITE_POSE_TURNING_AROUND_INIT 0xA
#define PARASITE_POSE_TURNING_AROUND_FIRST_PART 0xB
#define PARASITE_POSE_TURNING_AROUND_SECOND_PART 0xC
#define PARASITE_POSE_LANDING_INIT 0xE
#define PARASITE_POSE_LANDING 0xF
#define PARASITE_POSE_FALLING_INIT 0x1E
#define PARASITE_POSE_FALLING 0x1F
#define PARASITE_POSE_SAMUS_GRABBED_INIT 0x42
#define PARASITE_POSE_SAMUS_GRABBED 0x43
#define PARASITE_POSE_EXPULSED_INIT 0x44
#define PARASITE_POSE_EXPULSED_UP 0x45
#define PARASITE_POSE_EXPULSED_DOWN 0x47
#define PARASITE_POSE_JUMPING_UP 0x49
#define PARASITE_POSE_JUMPING_DOWN 0x4B
#define PARASITE_POSE_GERON_GRABBED_INIT 0x4C
#define PARASITE_POSE_GERON_GRABBED 0x4D
#define PARASITE_POSE_DYING_INIT 0x62
#define PARASITE_POSE_DYING 0x67

u32 ParasiteCount(void);
void ParasiteInit(struct SpriteData* pSprite);
void ParasiteGrabSamus(struct SpriteData* pSprite);
void ParasiteSamusGrabbed(struct SpriteData* pSprite);
void ParasiteExpulsedInit(struct SpriteData* pSprite);
void ParasiteExpulsedUp(struct SpriteData* pSprite);
void ParasiteMultipleExpulsedUp(struct SpriteData* pSprite);
void ParasiteExpulsedDown(struct SpriteData* pSprite);
void ParasiteMultipleExpulsedDown(struct SpriteData* pSprite);
void ParasiteJumpingUp(struct SpriteData* pSprite);
void ParasiteMultipleJumpingUp(struct SpriteData* pSprite);
void ParasiteJumpingDown(struct SpriteData* pSprite);
void ParasiteMultipleJumpingDown(struct SpriteData* pSprite);
void ParasiteIdleInit(struct SpriteData* pSprite);
void ParasiteIdle(struct SpriteData* pSprite);
void ParasiteMultipleIdle(struct SpriteData* pSprite);
void ParasiteTurningAroundInit(struct SpriteData* pSprite);
void ParasiteTurningAroundFirstPart(struct SpriteData* pSprite);
void ParasiteTurningAroundSecondPart(struct SpriteData* pSprite);
void ParasiteLandingInit(struct SpriteData* pSprite);
void ParasiteLanding(struct SpriteData* pSprite);
void ParasiteFallingInit(struct SpriteData* pSprite);
void ParasiteFalling(struct SpriteData* pSprite);
void ParasiteDyingInit(struct SpriteData* pSprite);
void ParasiteDying(struct SpriteData* pSprite);
void ParasiteMultipleDying(struct SpriteData* pSprite);
void ParasiteGrabGeron(struct SpriteData* pSprite);
void ParasiteGeronGrabbed(struct SpriteData* pSprite);
void ParasiteProjectilesCollision(struct SpriteData* pSprite);
void ParasiteMultiple(void);
void Parasite(void);

#endif /* PARASITE_AI_H */