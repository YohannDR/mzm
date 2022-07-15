#ifndef SPRITE_UTIL_H
#define SPRITE_UTIL_H

#include "sprite.h"
#include "samus.h"
#include "types.h"

#define NSLR_OUT_OF_RANGE 0x0
#define NSLR_LEFT 0x4
#define NSLR_RIGHT 0x8

#define NSAB_OUT_OF_RANGE 0x0
#define NSAB_ABOVE 0x1
#define NSAB_BELOW 0x2

#define DCT_NONE 0x0
#define DCT_SHINESPARK 0x1
#define DCT_SPEEDBOOSTER 0x2
#define DCT_SCREW_ATTACK 0x3
#define DCT_SUDO_SCREW 0x4

#define DEATH_NORMAL 0x0
#define DEATH_RESPAWNING 0x1
#define DEATH_NO_DEATH_OR_RESPAWNING_ALREADY_HAS_DROP 0x2

#define SPLASH_NONE 0x0
#define SPLASH_SMALL 0x1
#define SPLASH_BIG 0x2
#define SPLASH_HUGE 0x3

void SpriteUtilInitLocationText(void);
void SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(u16 y_position, u16 x_position);
void SpriteUtilCheckStopSamusAgainstSolidSpriteRight(u16 y_position, u16 x_position);
u8 SpriteUtilTakeDamageFromSprite(u8 kb_flag, struct SpriteData* pSprite, u16 dmg_mulitplier);
u8 SpriteUtilCheckObjectsTouching(u16 o1_top, u16 o1_bottom, u16 o1_left, u16 o1_right, u16 o2_top, u16 o2_bottom, u16 o2_left, u16 o2_right);
void SpriteUtilSamusAndSpriteCollision(void);
u32 SpriteUtilCheckVerticalCollisionAtPosition(u16 y_position, u16 x_position);
u32 SpriteUtilCheckVerticalCollisionAtPosition_slopes(u16 y_position, u16 x_position);
void unk_f594(void);
void unk_f608(void);
void SpriteUtilCheckCollisionAtPosition(u16 y_position, u16 x_position);
u32 SpriteUtilGetCollisionAtPosition(u16 y_position, u16 x_position);
void SpriteUtilCurrentSpriteFall(void);
void SpriteUtilChooseRandomXFlip(void);
void SpriteUtilChooseRandomXDirection(void);
void SpriteUtilChooseRandomXDirectionRoomSlot(u8 room_slot);
void SpriteUtilMakeSpriteFaceSamusXFlip(void);
void SpriteUtilMakeSpriteFaceSamusDirection(void);
void SpriteUtilMakeSpriteFaceAwawFromSamusXFlip(void);
void SpriteUtilMakeSpriteFaceAwawFromSamusDirection(void);
void unk_f978(i16 movement);
void unk_f9e7(i16 movement);
u8 SpriteUtilMakeSpriteFaceSamusRotation(u8 oam_rotation, u16 samus_y, u16 samus_x, u16 sprite_y, u16 sprite_x);
u8 SpriteUtillCheckEndCurrentSpriteAnim(void);
u8 SpriteUtilCheckNearEndCurrentSpriteAnim(void);
u8 SpriteUtilCheckEndSpriteAnim(u8 ram_slot);
u8 SpriteUtilCheckNearEndSpriteAnim(u8 ram_slot);
u8 SpriteUtilCheckEndSubSprite1Anim(void);
u8 SpriteUtilCheckNearEndSubSprite1Anim(void);
u8 SpriteUtilCheckEndSubSprite2Anim(void);
u8 SpriteUtilCheckEndSubSpriteAnim(struct SubSpriteData* pSub);
u8 SpriteUtilCheckNearEndSubSpriteAnim(struct SubSpriteData* pSub);
u8 SpriteUtilCheckSamusNearSpriteLeftRight(u16 y_range, u16 x_range);
u8 SpriteUtilCheckSamusNearSpriteAboveBelow(u16 y_range, u16 x_range);
u8 SpriteUtilCheckSamusNearSpriteFrontBehind(u16 y_range, u16 x_range_front, u16 x_range_behind);
void SpriteUtilSamusStandingOnSprite(struct SpriteData* pSprite);
void SpriteUtilUpdateFreezeTimer(void);
void SpriteUtilUnfreezeAnimEasy(void);
void SpriteUtilMetroidUnfreezeAnim(void);
void SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent(u8 sprite_id, u8 ram_slot);
void SpriteUtillUpdatePrimarySpriteFreezeTimerOfCurrent(void);
void SpriteUtilUnfreezeSecondarySprites(u8 sprite_id, u8 ram_slot);
u8 SpriteUtilRefillEnergy(void);
u8 SpriteUtilRefillMissiles(void);
u8 SpriteUtilRefillSuperMissiles(void);
u8 SpriteUtilRefillPowerBombs(void);
u8 SpriteUtilCheckCrouchinOrMorphed(void);
u8 SpriteUtilCheckCrouchinOrCrawling(void);
u8 SpriteUtilCheckMorphed(void);
u8 SpriteUtilCheckStopSpritesPose(void);
u8 SpriteUtilSpriteTakeDamageFromSamusContact(struct SpriteData* pSprite, struct SamusData* pData);
u8 SpriteUtilCheckPullingSeftUp(void);
u8 SpriteUtilCheckOnZipline(void);
u8 SpriteUtilCountPrimarySprites(u8 sprite_id);
u8 SpriteUtilCountSecondarySpritesWithCurrentSpriteRAMSlot(u8 sprite_id);
u8 SpriteUtilCountPrimarySpritesWithCurrentSpriteRAMSlot(u8 sprite_id);
u8 SpriteUtilFindPrimary(u8 sprite_id);
u8 SpriteUtilFindSecondaryWithRoomSlot(u8 sprite_id, u8 room_slot);
u8 SpriteUtilCheckHasDrops(void);
u8 SpriteUtilCountDrops(void);
void SpriteUtilMoveSpriteTowardsSamus(u16 samus_y, u16 samus_x, u8 y_speed, u8 x_speed, u8 speed_divisor);
void SpriteUtilRidleyFireballMove(u16 sprite_y, u16 samus_x, u8 y_speed, u8 x_speed, u8 speed_divisor);
void SpriteUtilUpdateStunTimer(struct SpriteData* pSprite);
void SpriteUtilRandomSpriteDebris(u8 cloud_type, u8 number, u16 y_position, u16 x_position);
u8 SpriteUtilGetAmmoDrop(u8 rng);
u8 SpriteUtilDetermineEnemyDrop(void);
void SpriteUtilSpriteDeath(u8 death_type, u16 y_position, u16 x_position, u8 play_sound, u8 effect);
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
void SpriteUtilSetSplashEffect(u16 y_position, u16 x_position, u8 size);
u8 SpriteUtilCheckOutOfRoomEffect(u16 old_y, u16 y_position, u16 x_position, u8 size);
u8 SpriteUtilCheckInRoomEffect(u16 old_y, u16 y_position, u16 x_position, u8 size);
u16 SpriteUtilGetFinalCompletionPercentage(void);

#endif /* SPRITE_UTIL_H */