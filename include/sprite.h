#ifndef SPRITE_H
#define SPRITE_H

#include "types.h"
#include "oam.h"
#include "structs/sprite.h"

void SpriteUpdate(void);
void SpriteUpdateAnimation(struct SpriteData* pSprite);
void SpriteDrawAll_2(void);
void SpriteDrawAll(void);
void SpriteDrawAll_Upper(void);
void SpriteDraw(struct SpriteData* pSprite, s32 slot);
void SpriteCheckOnScreen(struct SpriteData* pSprite);
void SpriteLoadAllData(void);
void SpriteLoadSpriteset(void);
void SpriteLoadGfx(u8 spriteId, u8 row);
void SpriteLoadPal(u8 spriteId, u8 row, u8 len);
void SpriteClearData(void);
void SpriteLoadRoomSprites(void);
void SpriteInitPrimary(u8 spritesetSlot, u16 yPosition, u16 xPosition, u8 roomSlot);
u8 SpriteSpawnSecondary(u8 spriteId, u8 partNumber, u8 gfxSlot, u8 ramSlot, u16 yPosition, u16 xPosition, u16 statusToAdd);
u8 SpriteSpawnPrimary(u8 spriteId, u8 partNumber, u8 gfxSlot, u16 yPosition, u16 xPosition, u16 statusToAdd);
u8 SpriteSpawnDropFollowers(u8 spriteId, u8 partNumber, u8 gfxSlot, u8 ramSlot, u16 yPosition, u16 xPosition, u16 statusToAdd);

#endif /* SPRITE_H */