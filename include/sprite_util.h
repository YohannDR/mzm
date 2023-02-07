#ifndef SPRITE_UTIL_H
#define SPRITE_UTIL_H

#include "types.h"
#include "structs/sprite.h"
#include "structs/samus.h"

void SpriteUtilInitLocationText(void);
void SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(u16 yPosition, u16 xPosition);
void SpriteUtilCheckStopSamusAgainstSolidSpriteRight(u16 yPosition, u16 xPosition);
u8 SpriteUtilTakeDamageFromSprite(u8 kbFlag, struct SpriteData* pSprite, u16 dmgMultiplier);
u32 SpriteUtilCheckObjectsTouching(u16 o1Top, u16 o1Bottom, u16 o1Left, u16 o1Right, u16 o2Top, u16 o2Bottom, u16 o2Left, u16 o2Right);
void SpriteUtilSamusAndSpriteCollision(void);
u32 SpriteUtilCheckVerticalCollisionAtPosition(u16 yPosition, u16 xPosition);
u32 SpriteUtilCheckVerticalCollisionAtPositionSlopes(u16 yPosition, u16 xPosition);
void unk_f594(void);
void unk_f608(void);
void SpriteUtilCheckCollisionAtPosition(u32 yPosition, u32 xPosition);
u32 SpriteUtilGetCollisionAtPosition(u32 yPosition, u32 xPosition);
void SpriteUtilCurrentSpriteFall(void);
void SpriteUtilChooseRandomXFlip(void);
void SpriteUtilChooseRandomXDirection(void);
void SpriteUtilChooseRandomXDirectionRoomSlot(u8 roomSlot);
void SpriteUtilMakeSpriteFaceSamusXFlip(void);
void SpriteUtilMakeSpriteFaceSamusDirection(void);
void SpriteUtilMakeSpriteFaceAwawFromSamusXFlip(void);
void SpriteUtilMakeSpriteFaceAwawFromSamusDirection(void);
void unk_f978(i16 movement);
void unk_f9e7(i16 movement);
u8 SpriteUtilMakeSpriteFaceSamusRotation(i16 oamRotation, i16 samusY, i16 samusX, i16 spriteY, i16 spriteX);
u32 SpriteUtilCheckEndCurrentSpriteAnim(void);
u32 SpriteUtilCheckNearEndCurrentSpriteAnim(void);
u8 SpriteUtilCheckEndSpriteAnim(u8 ramSlot);
u8 SpriteUtilCheckNearEndSpriteAnim(u8 ramSlot);
u8 SpriteUtilCheckEndSubSprite1Anim(void);
u8 SpriteUtilCheckNearEndSubSprite1Anim(void);
u8 SpriteUtilCheckEndSubSprite2Anim(void);
u8 SpriteUtilCheckEndSubSpriteAnim(struct SubSpriteData* pSub);
u8 SpriteUtilCheckNearEndSubSpriteAnim(struct SubSpriteData* pSub);
u8 SpriteUtilCheckSamusNearSpriteLeftRight(u16 yRange, u16 xRange);
u8 SpriteUtilCheckSamusNearSpriteAboveBelow(u16 yRange, u16 xRange);
u32 SpriteUtilCheckSamusNearSpriteFrontBehind(u16 yRange, u16 xRangeFront, u16 xRangeBehind);
void SpriteUtilSamusStandingOnSprite(struct SpriteData* pSprite);
void SpriteUtilUpdateFreezeTimer(void);
void SpriteUtilUnfreezeAnimEasy(void);
void SpriteUtilMetroidUnfreezeAnim(void);
void SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent(u8 spriteID, u8 ramSlot);
void SpriteUtillUpdatePrimarySpriteFreezeTimerOfCurrent(void);
void SpriteUtilUnfreezeSecondarySprites(u8 spriteID, u8 ramSlot);
u8 SpriteUtilRefillEnergy(void);
u8 SpriteUtilRefillMissiles(void);
u8 SpriteUtilRefillSuperMissiles(void);
u8 SpriteUtilRefillPowerBombs(void);
u8 SpriteUtilCheckCrouchingOrMorphed(void);
u8 SpriteUtilCheckCrouchingOrCrawling(void);
u32 SpriteUtilCheckMorphed(void);
u32 SpriteUtilCheckStopSpritesPose(void);
u32 SpriteUtilSpriteTakeDamageFromSamusContact(struct SpriteData* pSprite, struct SamusData* pData);
u32 SpriteUtilCheckPullingSelfUp(void);
u32 SpriteUtilCheckOnZipline(void);
u8 SpriteUtilCountPrimarySprites(u8 spriteID);
u8 SpriteUtilCountSecondarySpritesWithCurrentSpriteRAMSlot(u8 spriteID);
u8 SpriteUtilCountPrimarySpritesWithCurrentSpriteRAMSlot(u8 spriteID);
u8 SpriteUtilFindPrimary(u8 spriteID);
u8 SpriteUtilFindSecondaryWithRoomSlot(u8 spriteID, u8 roomSlot);
u8 SpriteUtilCheckHasDrops(void);
u8 SpriteUtilCountDrops(void);
void SpriteUtilMoveSpriteTowardsSamus(u16 samusY, u16 samusX, u8 ySpeed, u8 xSpeed, u8 speedDivisor);
void SpriteUtilRidleyFireballMove(u16 spriteY, u16 samusX, u8 ySpeed, u8 xSpeed, u8 speedDivisor);
void SpriteUtilUpdateStunTimer(struct SpriteData* pSprite);
void SpriteUtilRandomSpriteDebris(u8 cloudType, u8 number, u16 yPosition, u16 xPosition);
u8 SpriteUtilGetAmmoDrop(u8 rng);
u8 SpriteUtilDetermineEnemyDrop(void);
void SpriteUtilSpriteDeath(u8 deathType, u16 yPosition, u16 xPosition, u8 playSound, u8 effect);
u8 SpriteUtilIsSpriteStunned(void);
u8 SpriteUtilIsSpriteOnScreenAndScreenShake(void);
void SpriteUtilUpdateSubSprite1Timer(void);
void SpriteUtilUpdateSubSprite1Anim(void);
void SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position(void);
void SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOAM(void);
void SpriteUtilUpdateSubSprite2Anim(void);
void SpriteUtilSyncCurrentSpritePositionWithSubSpriteData2PositionAndOAM(void);
void SpriteUtilUpdateSubSpriteAnim(struct SubSpriteData* pSub);
void SpriteUtilSyncCurrentSpritePositionWithSubSpritePosition(struct SubSpriteData* pSub);
void SpriteUtilSyncCurrentSpritePositionWithSubSpritePositionAndOAM(struct SubSpriteData* pSub);
u8 SpriteCheckCollidingWithSamusDrawing(void);
void SpriteUtilSetSplashEffect(u16 yPosition, u16 xPosition, u8 size);
u32 SpriteUtilCheckOutOfRoomEffect(u16 oldY, u16 yPosition, u16 xPosition, u8 size);
u32 SpriteUtilCheckInRoomEffect(u16 oldY, u16 yPosition, u16 xPosition, u8 size);
u32 SpriteUtilGetFinalCompletionPercentage(void);

#endif /* SPRITE_UTIL_H */