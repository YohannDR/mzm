#include "sprite.h"
#include "escape.h"
#include "sprite_debris.h"
#include "sprite_util.h"
#include "syscalls.h"
#include "gba.h"
#include "data/pointers.c"
#include "../data/data.h"
#include "globals.h"

/**
 * cf00 | 42c | Main routine that updates all the sprites
 * 
 */
void SpriteUpdate(void)
{
    u16 rngParam1;
    u16 rngParam2;
    u8 count;
    struct SpriteData* pCurrent;

    pCurrent = &gCurrentSprite;
    rngParam1 = gFrameCounter8Bit;
    rngParam2 = (gFrameCounter16Bit >> 0x4); // Incorrect stack

    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
    {
        SpriteDebrisProcessAll();
        if (!SpriteUtilCheckStopSpritesPose())
        {
            SpriteUtilSamusAndSpriteCollision();
            for (count = 0x0; count < 0x18; count++)
            {
                if (gSpriteData[count].status & SPRITE_STATUS_EXISTS)
                {
                    dma_set(3, &gSpriteData[count], &gCurrentSprite, 0x8000001c); // Transfer sprite to current
                    gSpriteRNG = sSpriteRandomNumberTable[(rngParam1 + count + rngParam2 + pCurrent->xPosition + pCurrent->yPosition) & 0x1F];
                    SpriteUtilUpdateStunTimer(pCurrent);
                    if (pCurrent->properties & SP_SECONDARY_SPRITE) // Call AI
                        sSecondarySpritesAIPointers[pCurrent->spriteID]();
                    else
                        sPrimarySpritesAIPointers[pCurrent->spriteID]();
                    if (pCurrent->status & SPRITE_STATUS_EXISTS)
                    {
                        SpriteUtilSamusStandingOnSprite(pCurrent);
                        SpriteUpdateAnimation(pCurrent);
                        SpriteCheckOnScreen(pCurrent);
                    }
                    dma_set(3, &gCurrentSprite, &gSpriteData[count], 0x8000001c); // Transfer current back to array
                }
            }
            DecrementChozodiaAlarm();
            if (gParasiteRelated != 0x0)
                gParasiteRelated--;
        }
        else
        {
            for (count = 0x0; count < 0x18; count++)
            {
                if (gSpriteData[count].status & SPRITE_STATUS_EXISTS)
                {
                    if (gSpriteData[count].pose == 0x0 || gSpriteData[count].properties & SP_ALWAYS_ACTIVE)
                    {
                        dma_set(3, &gSpriteData[count], &gCurrentSprite, 0x8000001c); // Incorrect ldr
                        gSpriteRNG = sSpriteRandomNumberTable[(rngParam1 + count + rngParam2 + pCurrent->xPosition + pCurrent->yPosition) & 0x1F];
                        SpriteUtilUpdateStunTimer(pCurrent);
                        if (pCurrent->properties & SP_SECONDARY_SPRITE) // Call AI
                            sSecondarySpritesAIPointers[pCurrent->spriteID]();
                        else
                            sPrimarySpritesAIPointers[pCurrent->spriteID]();

                        if (pCurrent->status & SPRITE_STATUS_EXISTS)
                        {
                            SpriteUtilSamusStandingOnSprite(pCurrent);
                            SpriteUpdateAnimation(pCurrent);
                            SpriteCheckOnScreen(pCurrent);
                        }
                        dma_set(3, &gCurrentSprite, &gSpriteData[count], 0x8000001c);
                    }
                    else
                    {
                        dma_set(3, &gSpriteData[count], &gCurrentSprite, 0x8000001c);
                        SpriteCheckOnScreen(pCurrent);
                        dma_set(3, &gCurrentSprite, &gSpriteData[count], 0x8000001c);
                    }
                }
            }
            return;
        }
    }
    else if (gGameModeSub1 == 0x6)
    {
        for (count = 0x0; count < 0x18; count++)
        {
            if (gSpriteData[count].status & SPRITE_STATUS_EXISTS)
            {
                dma_set(3, &gSpriteData[count], &gCurrentSprite, 0x8000001c);
                gSpriteRNG = sSpriteRandomNumberTable[(rngParam1 + count + rngParam2 + pCurrent->xPosition + pCurrent->yPosition) & 0x1F];
                SpriteUtilUpdateStunTimer(pCurrent);
                if (pCurrent->properties & SP_SECONDARY_SPRITE)
                    sSecondarySpritesAIPointers[pCurrent->spriteID]();
                else
                    sPrimarySpritesAIPointers[pCurrent->spriteID]();

                if (pCurrent->status & SPRITE_STATUS_EXISTS)
                {
                    SpriteUtilSamusStandingOnSprite(pCurrent);
                    SpriteUpdateAnimation(pCurrent);
                    SpriteCheckOnScreen(pCurrent);
                }
                dma_set(3, &gCurrentSprite, &gSpriteData[count], 0x8000001c);
            }
        }
        DecrementChozodiaAlarm();
        if (gParasiteRelated != 0x0)
            gParasiteRelated--;
    }
    else
    {
        count = 0x0;
        for (count = 0x0; count < 0x18; count++)
        {
            if (gSpriteData[count].status & SPRITE_STATUS_EXISTS)
            {
                dma_set(3, &gSpriteData[count], &gCurrentSprite, 0x8000001c);
                gSpriteRNG = sSpriteRandomNumberTable[(rngParam1 + count + rngParam2 + pCurrent->xPosition + pCurrent->yPosition) & 0x1F];
                
                if (pCurrent->pose == 0x0)
                {
                    if (pCurrent->properties & SP_SECONDARY_SPRITE)
                        sSecondarySpritesAIPointers[pCurrent->spriteID]();
                    else
                        sPrimarySpritesAIPointers[pCurrent->spriteID]();
                }
                if (pCurrent->status & SPRITE_STATUS_EXISTS)
                    SpriteCheckOnScreen(pCurrent);
                dma_set(3, &gCurrentSprite, &gSpriteData[count], 0x8000001c);
            }
        }
    }
}

/**
 * d32c | 40 | Updates the animation related info of a sprite
 * 
 * @param pSprite Sprite Data Pointer to the concerned sprite
 */
void SpriteUpdateAnimation(struct SpriteData* pSprite)
{
    u32 adc;

    if (pSprite->freezeTimer == 0x0)
    {
        adc = pSprite->animationDurationCounter + 0x1;
        pSprite->animationDurationCounter = adc;
        if (pSprite->pOam[pSprite->currentAnimationFrame].timer < (u8)adc)
        {
            pSprite->animationDurationCounter = 0x1;
            pSprite->currentAnimationFrame++;
            if (pSprite->pOam[pSprite->currentAnimationFrame].timer == 0x0)
                pSprite->currentAnimationFrame = 0x0;
        }
    }
}

void SpriteDrawAll_2(void)
{

}

void SpriteDrawAll(void)
{
    /*struct SpriteData* pSprite1;
    struct SpriteData* pSprite2;
    u16 status_flag;
    u16 status_check;
    u8* drawOrder;
    u8* g_drawOrder;
    u32 ramSlot;
    int i;
    u32 unk;
    i32 unk2;
    u8 zero;

    status_flag = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN;
    status_check = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN;
    SpriteDebrisDrawAll();
    pSprite1 = gSpriteData;
    zero = 0x0;
    g_drawOrder = gSpriteDrawOrder;
    drawOrder = &gSpriteData[0].drawOrder;
    //ramSlot = 0x17;

    for (i = 0x17; i >= 0x0; i--)
    {
        if ((pSprite1->status & status_flag) == status_check && *drawOrder < 0x9)
            *g_drawOrder = *drawOrder;
        else
            *g_drawOrder = zero;
        g_drawOrder += 0x1;
        drawOrder += 0x38;
        pSprite1++;
    }
    
    unk = 0x1;
    
    do
    {
        ramSlot = 0x0;
        pSprite2 = gSpriteData;
        unk2 = unk + 0x1;

        while (pSprite2 < gSpriteData + MAX_AMOUNT_OF_SPRITES)
        {
            if (gSpriteDrawOrder[ramSlot] == unk)
            {
                SpriteDraw(pSprite2, ramSlot);
            }
            ramSlot++;
            pSprite2++;
        }
        unk = unk2;
    } while (unk2 < 0x9);*/
}

void SpriteDrawAll_3(void)
{

}

void SpriteDraw(struct SpriteData* pSprite, u32 slot)
{

}

void SpriteCheckOnScreen(struct SpriteData* pSprite)
{
    // /!\ Maths hell wtf
    /*u16 bg_y;
    u16 bg_x;
    u16 spriteY;
    u16 spriteX;
    u16 yOffset;
    u16 xOffset;
    u16 bg_x_offset;
    u16 bg_y_offset;
    u16 screen_top;
    u16 screen_bottom;
    u16 screen_right;
    u16 screen_left;

    if (!(pSprite->properties & SP_ABSOLUTE_POSITION))
    {
        bg_y = gBG1YPosition;
        bg_x = gBG1XPosition;
        spriteY = pSprite->yPosition;
        spriteX = pSprite->xPosition;
        yOffset = spriteY + 0x200;
        xOffset = spriteX + 0x200;
        screen_bottom = bg_y - (pSprite->drawDistanceBottomOffset * 0x4) + 0x200;
        screen_top = bg_y + 0x200 + (pSprite->drawDistanceTopOffset * 0x4 + 0x280);
        screen_left = bg_x - (pSprite->drawDistanceHorizontalOffset * 0x4) + 0x200;
        screen_right = bg_x + 0x200;
        screen_right += (pSprite->drawDistanceHorizontalOffset * 0x4 + 0x3C0);

        if (screen_left < xOffset && xOffset < screen_right && screen_bottom < yOffset && yOffset < screen_top)
            pSprite->status |= SPRITE_STATUS_ONSCREEN;
        else
        {
            pSprite->status &= ~SPRITE_STATUS_ONSCREEN;
            if (pSprite->properties & SP_KILL_OFF_SCREEN)
            {
                xOffset = spriteX + 0x280;
                yOffset = spriteY + 0x280;
                screen_left = bg_x + 0x40;
                screen_right = bg_x + 0x880;
                screen_bottom = bg_y + 0x40;
                screen_top = bg_y + 0x740;

                if (screen_left >= xOffset || xOffset >= screen_right || yOffset < screen_bottom || screen_top < yOffset)
                    pSprite->status = 0x0;
            }
        }
    }*/
}

void SpriteLoadAllData(void)
{
    if (gPauseScreenFlag == PAUSE_SCREEN_NONE)
    {
        if (gGameModeSub3 == 0x0 && !gIsLoadingFile)
            gAlarmTimer = 0x0;
        SpriteClearData();
        SpriteLoadSpriteset();
        EscapeCheckReloadGraphics();
        SpriteUtilInitLocationText();
        SpriteLoadRoomSprites();
        SpawnWaitingPirates();
        gParasiteRelated = 0x0;
    }
}

void SpriteLoadSpriteset(void)
{

}

/**
 * e084 | 2c | 
 * Loads the graphics in VRAM for a new sprite
 * 
 * @param spriteID Sprite ID
 * @param gfx_row Spriteset Graphics Row
 */
void SpriteLoadGFX(u8 spriteID, u8 gfx_row)
{
    spriteID -= 0x10;
    LZ77UncompVRAM(sSpritesGraphicsPointers[spriteID], VRAM_BASE + 0x14000 + (gfx_row * 0x800));
}

/**
 * e0b0 | 40 | 
 * Loads the palette in PALRAM for a new sprite
 * 
 * @param spriteID Sprite ID
 * @param row Palette Row
 * @param len Lenght (in rows)
 */
void SpriteLoadPAL(u8 spriteID, u8 row, u8 len)
{
    spriteID -= 0x10;

    dma_set(3, sSpritesPalettePointers[spriteID], PALRAM_BASE + 0x300 + (row * 0x20), DMA_ENABLE | len << 0x4);
}

void SpriteClearData(void)
{
    // https://decomp.me/scratch/wqJL5
}

void SpriteLoadRoomSprites(void)
{
    // Most likely a fake match, need to do this function again

    u8 roomSlot;
    u8 y_pos;
    u8 x_pos;

    roomSlot = 0x0;
    y_pos = (gCurrentRoomEntry.pEnemyRoomData)->yPosition;
    if (y_pos == 0xFF) return;
    while (1)
    {
        x_pos = gCurrentRoomEntry.pEnemyRoomData[roomSlot].xPosition;
        SpriteInitPrimary(gCurrentRoomEntry.pEnemyRoomData[roomSlot].spritesetSlot, y_pos, x_pos, roomSlot);
        roomSlot++;
        if (roomSlot > 0x17) return;
        y_pos = gCurrentRoomEntry.pEnemyRoomData[roomSlot].yPosition;
        if (y_pos == 0xFF) return;
    }
}

/**
 * @brief e17c | dc | Initializes a primary sprite with the values in parameters
 * 
 * @param spritesetSlot Spriteset slot/properties
 * @param yPosition Y Position (tiles)
 * @param xPosition X Position (tiles)
 * @param roomSlot Room Slot
 */
void SpriteInitPrimary(u8 spritesetSlot, u16 yPosition, u16 xPosition, u8 roomSlot)
{
    u8 ramSlot;
    struct SpriteData* pSprite;

    ramSlot = 0x0;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (!(pSprite->status & SPRITE_STATUS_EXISTS))
        {
            pSprite->status = SPRITE_STATUS_EXISTS;
            spritesetSlot &= 0x7F;
            if (spritesetSlot >= 0x11)
            {
                spritesetSlot--;
                spritesetSlot &= 0xF;

                pSprite->spritesetGFXSlot = gSpritesetGFXSlots[spritesetSlot];
                pSprite->spriteID = gSpritesetSpritesID[spritesetSlot];
            }
            else
            {
                pSprite->spritesetGFXSlot = 0x0;
                pSprite->spriteID = spritesetSlot - 0x1;
            }

            pSprite->properties = 0x0;
            pSprite->yPosition = (yPosition * BLOCK_SIZE) + BLOCK_SIZE;
            pSprite->xPosition = (xPosition * BLOCK_SIZE) + (HALF_BLOCK_SIZE);
            pSprite->roomSlot = roomSlot;
            pSprite->bgPriority = 0x2;
            pSprite->drawOrder = 0x4;
            pSprite->pose = 0x0;
            pSprite->health = 0x0;
            pSprite->invicibilityStunFlashTimer = 0x0;
            pSprite->paletteRow = 0x0;
            pSprite->frozenPaletteRowOffset = 0x0;
            pSprite->absolutePaletteRow = 0x0;
            pSprite->ignoreSamusCollisionTimer = 0x1;
            pSprite->primarySpriteRAMSlot = ramSlot;
            pSprite->freezeTimer = 0x0;
            pSprite->standingOnSprite = FALSE;
            return;
        }

        ramSlot++;
    }
}

/**
 * e258 | c4 | 
 * Spawns a new secondary sprite with the given parameters
 * 
 * @param spriteID The ID of the sprite to spawn
 * @param roomSlot The room slot
 * @param gfxSlot The sprite graphics slot (usually the same as the primary sprite)
 * @param ramSlot The RAM slot of the secondary sprite's parent
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param statusToAdd Additionnal status flags (default are Exists, On Screen and Not Drawn)
 * @return The assigned RAM slot of the spawned sprite, 0xFF is the sprite couldn't spawn
 */
u8 SpriteSpawnSecondary(u8 spriteID, u8 roomSlot, u8 gfxSlot, u8 ramSlot, u16 yPosition, u16 xPosition, u16 statusToAdd)
{
    u8 new_ramSlot;
    struct SpriteData* pSprite;
    u16 status;

    new_ramSlot = 0x0;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES)
    {
        status = pSprite->status & SPRITE_STATUS_EXISTS;
        if (status == 0x0)
        {
            pSprite->status = statusToAdd | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            pSprite->properties = SP_SECONDARY_SPRITE;
            pSprite->spritesetGFXSlot = gfxSlot;
            pSprite->spriteID = spriteID;
            pSprite->yPosition = yPosition;
            pSprite->xPosition = xPosition;
            pSprite->roomSlot = roomSlot;
            pSprite->bgPriority = 0x2;
            pSprite->drawOrder = 0x4;
            pSprite->pose = 0x0;
            pSprite->health = status;
            pSprite->invicibilityStunFlashTimer = 0x0;
            pSprite->paletteRow = 0x0;
            pSprite->frozenPaletteRowOffset = 0x0;
            pSprite->absolutePaletteRow = 0x0;
            pSprite->ignoreSamusCollisionTimer = 0x1;
            pSprite->primarySpriteRAMSlot = ramSlot;
            pSprite->freezeTimer = 0x0;
            pSprite->standingOnSprite = FALSE;

            return new_ramSlot;
        }

        new_ramSlot += 0x1;
        pSprite += 0x1;
    }

    return 0xFF;
}

/**
 * e31c | b8 | 
 * Spawns a new primary sprite with the given parameters
 * 
 * @param spriteID The ID of the sprite to spawn
 * @param roomSlot The room slot
 * @param gfxSlot The sprite graphics slot
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param statusToAdd Additionnal status flags (default are Exists, On Screen and Not Drawn)
 * @return The assigned RAM slot of the spawned sprite, 0xFF if the sprite couldn't spawn
 */
u8 SpriteSpawnPrimary(u8 spriteID, u8 roomSlot, u8 gfxSlot, u16 yPosition, u16 xPosition, u16 statusToAdd)
{
    u8 new_ramSlot;
    struct SpriteData* pSprite;
    u16 status;

    new_ramSlot = 0x0;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES)
    {
        status = pSprite->status & SPRITE_STATUS_EXISTS;
        if (status == 0x0)
        {
            pSprite->status = statusToAdd | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            pSprite->properties = 0x0;
            pSprite->spritesetGFXSlot = gfxSlot;
            pSprite->spriteID = spriteID;
            pSprite->yPosition = yPosition;
            pSprite->xPosition = xPosition;
            pSprite->roomSlot = roomSlot;
            pSprite->bgPriority = 0x2;
            pSprite->drawOrder = 0x4;
            pSprite->pose = 0x0;
            pSprite->health = status;
            pSprite->invicibilityStunFlashTimer = 0x0;
            pSprite->paletteRow = 0x0;
            pSprite->frozenPaletteRowOffset = 0x0;
            pSprite->absolutePaletteRow = 0x0;
            pSprite->ignoreSamusCollisionTimer = 0x1;
            pSprite->primarySpriteRAMSlot = new_ramSlot;
            pSprite->freezeTimer = 0x0;
            pSprite->standingOnSprite = FALSE;

            return new_ramSlot;
        }

        new_ramSlot += 0x1;
        pSprite += 0x1;
    }

    return 0xFF;
}

/**
 * e31c | b8 | 
 * Spawns a new primary sprite with the given parameters (used only for the drops and the followers sprite)
 * 
 * @param spriteID The ID of the sprite to spawn
 * @param roomSlot The room slot
 * @param gfxSlot The sprite graphics slot
 * @param ramSlot The RAM slot of the sprite's parent
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param statusToAdd Additionnal status flags (default are Exists, On Screen and Not Drawn)
 * @return The assigned RAM slot of the spawned sprite, 0xFF is the sprite couldn't spawn
 */
u8 SpriteSpawnDropFollowers(u8 spriteID, u8 roomSlot, u8 gfxSlot, u8 ramSlot, u16 yPosition, u16 xPosition, u16 statusToAdd)
{
    u8 new_ramSlot;
    struct SpriteData* pSprite;
    u16 status;

    new_ramSlot = 0x0;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES)
    {
        status = pSprite->status & SPRITE_STATUS_EXISTS;
        if (status == 0x0)
        {
            pSprite->status = statusToAdd | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            pSprite->properties = 0x0;
            pSprite->spritesetGFXSlot = gfxSlot;
            pSprite->spriteID = spriteID;
            pSprite->yPosition = yPosition;
            pSprite->xPosition = xPosition;
            pSprite->roomSlot = roomSlot;
            pSprite->bgPriority = 0x2;
            pSprite->drawOrder = 0x4;
            pSprite->pose = 0x0;
            pSprite->health = status;
            pSprite->invicibilityStunFlashTimer = 0x0;
            pSprite->paletteRow = 0x0;
            pSprite->frozenPaletteRowOffset = 0x0;
            pSprite->absolutePaletteRow = 0x0;
            pSprite->ignoreSamusCollisionTimer = 0x1;
            pSprite->primarySpriteRAMSlot = ramSlot;
            pSprite->freezeTimer = 0x0;
            pSprite->standingOnSprite = FALSE;

            return new_ramSlot;
        }

        new_ramSlot++;
        pSprite++;
    }

    return 0xFF;
}