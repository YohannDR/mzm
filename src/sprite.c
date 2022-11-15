#include "sprite.h"
#include "sprite_debris.h"
#include "syscalls.h"
#include "gba.h"
#include "fixed_point.h"

#include "data/generic_data.h"
#include "data/pointers.h"
#include "data/sprite_data.h"

#include "constants/game_state.h"
#include "constants/particle.h"

#include "structs/bg_clip.h"
#include "structs/game_state.h"
#include "structs/samus.h"

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
    rngParam2 = (gFrameCounter16Bit >> 0x4);

    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
    {
        SpriteDebrisProcessAll();
        if (!SpriteUtilCheckStopSpritesPose())
        {
            SpriteUtilSamusAndSpriteCollision();
            for (count = 0x0; count < MAX_AMOUNT_OF_SPRITES; count++)
            {
                if (gSpriteData[count].status & SPRITE_STATUS_EXISTS)
                {
                    dma_set(3, &gSpriteData[count], &gCurrentSprite, DMA_ENABLE << 16 | (sizeof(struct SpriteData) * 2)); // Transfer sprite to current
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
                    dma_set(3, &gCurrentSprite, &gSpriteData[count], DMA_ENABLE << 16 | (sizeof(struct SpriteData) * 2)); // Transfer current back to array
                }
            }
            DecrementChozodiaAlarm();
            if (gParasiteRelated != 0x0)
                gParasiteRelated--;
        }
        else
        {
            for (count = 0x0; count < MAX_AMOUNT_OF_SPRITES; count++)
            {
                if (gSpriteData[count].status & SPRITE_STATUS_EXISTS)
                {
                    if (gSpriteData[count].pose == 0x0 || gSpriteData[count].properties & SP_ALWAYS_ACTIVE)
                    {
                        dma_set(3, &gSpriteData[count], &gCurrentSprite, DMA_ENABLE << 16 | (sizeof(struct SpriteData) * 2));
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
                        dma_set(3, &gCurrentSprite, &gSpriteData[count], DMA_ENABLE << 16 | (sizeof(struct SpriteData) * 2));
                    }
                    else
                    {
                        dma_set(3, &gSpriteData[count], &gCurrentSprite, DMA_ENABLE << 16 | (sizeof(struct SpriteData) * 2));
                        SpriteCheckOnScreen(pCurrent);
                        dma_set(3, &gCurrentSprite, &gSpriteData[count], DMA_ENABLE << 16 | (sizeof(struct SpriteData) * 2));
                    }
                }
            }
            return;
        }
    }
    else if (gGameModeSub1 == 0x6)
    {
        for (count = 0x0; count < MAX_AMOUNT_OF_SPRITES; count++)
        {
            if (gSpriteData[count].status & SPRITE_STATUS_EXISTS)
            {
                dma_set(3, &gSpriteData[count], &gCurrentSprite, DMA_ENABLE << 16 | (sizeof(struct SpriteData) * 2));
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
                dma_set(3, &gCurrentSprite, &gSpriteData[count], DMA_ENABLE << 16 | (sizeof(struct SpriteData) * 2));
            }
        }
        DecrementChozodiaAlarm();
        if (gParasiteRelated != 0x0)
            gParasiteRelated--;
    }
    else
    {
        for (count = 0x0; count < MAX_AMOUNT_OF_SPRITES; count++)
        {
            if (gSpriteData[count].status & SPRITE_STATUS_EXISTS)
            {
                dma_set(3, &gSpriteData[count], &gCurrentSprite, DMA_ENABLE << 16 | (sizeof(struct SpriteData) * 2));
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
                dma_set(3, &gCurrentSprite, &gSpriteData[count], DMA_ENABLE << 16 | (sizeof(struct SpriteData) * 2));
            }
        }
    }
}

/**
 * d32c | 40 | Updates the animation related info of a sprite
 * 
 * @param pSprite Sprite Data Pointer
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

/**
 * @brief d36c | c4 | Call draw sprite function, difference with the other is unknown
 * 
 */
void SpriteDrawAll_2(void)
{
    struct SpriteData* pSprite;
    i32 i;
    i32 drawOrder;
    u32 drawStatus;
    u32 checkStatus;
    u32 modeCheck;

    if (gGameModeSub1 ^ 2)
        modeCheck = TRUE;
    else
        modeCheck = FALSE;

    checkStatus = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN;
    drawStatus = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_UNKNOWN;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if ((gSpriteData[i].status & checkStatus) == drawStatus && gSpriteData[i].drawOrder < 9)
        {
            if (modeCheck)
            {
                if (gSpriteData[i].properties & SP_ABSOLUTE_POSITION)
                    gSpriteDrawOrder[i] = 0;
                else
                    gSpriteDrawOrder[i] = gSpriteData[i].drawOrder;
            }
            else
                gSpriteDrawOrder[i] = gSpriteData[i].drawOrder;
        }
        else
        {
            u8 d = 0;
            gSpriteDrawOrder[i] = d;
        }
    }

    for (drawOrder = 1; drawOrder < 9; drawOrder++)
    {
        i = 0;
        for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
        {
            if (gSpriteDrawOrder[i] == drawOrder)
                SpriteDraw(pSprite, i);
            i++;
        }
    }
}

/**
 * @brief d430 | 8c | Draws the sprites based on the draw order
 * 
 */
void SpriteDrawAll(void)
{
    struct SpriteData* pSprite;
    i32 i;
    i32 drawOrder;
    u32 drawStatus;
    u32 checkStatus;

    checkStatus = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN;
    drawStatus = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN;
    
    SpriteDebrisDrawAll();

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if ((gSpriteData[i].status & checkStatus) == drawStatus && gSpriteData[i].drawOrder < 9)
            gSpriteDrawOrder[i] = gSpriteData[i].drawOrder;
        else
        {
            u8 d = 0;
            gSpriteDrawOrder[i] = d;
        }
    }

    for (drawOrder = 1; drawOrder < 9; drawOrder++)
    {
        i = 0;
        for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
        {
            if (gSpriteDrawOrder[i] == drawOrder)
                SpriteDraw(pSprite, i);
            i++;
        }
    }
}

/**
 * @brief d4bc | 88 | Draws the sprites that have a draw order between 9 and 16
 * 
 */
void SpriteDrawAll_Upper(void)
{
    struct SpriteData* pSprite;
    i32 i;
    i32 drawOrder;
    u32 drawStatus;
    u32 checkStatus;

    checkStatus = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN;
    drawStatus = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if ((gSpriteData[i].status & checkStatus) == drawStatus && gSpriteData[i].drawOrder > 8)
            gSpriteDrawOrder[i] = gSpriteData[i].drawOrder;
        else {
            u8 d = 0;
            gSpriteDrawOrder[i] = d;
        }
    }

    for (drawOrder = 9; drawOrder < 17; drawOrder++)
    {
        i = 0;
        for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
        {
            if (gSpriteDrawOrder[i] == drawOrder)
                SpriteDraw(pSprite, i);
            i++;
        }
    }
}

void SpriteDraw(struct SpriteData* pSprite, u32 slot)
{
    // https://decomp.me/scratch/7FvMo

    const u16* src;
    u16* dst;
    u16 partCount;
    u32 currSlot;
    u8 prevSlot;
    u16 part1;
    u16 part2;
    u8 part3;
    u32 i;

    u16 xFlip;
    u16 yFlip;
    u16 doubleSize;
    u16 alphaBlending;
    u16 facingDown;
    u16 mosaic;

    u16 yPosition;
    u16 xPosition;
    u32 paletteRow;
    u32 gfxOffset;
    u32 bgPriority;
    u32 shape;
    u32 size;
    u16 rotation;
    u16 scaling;

    i16 sine;
    u16 dy;
    u16 dmy;

    u32 yOffset;
    u32 xOffset;
    u32 tempY;
    u32 tempX;
    i16 yParam;
    i16 xParam;
    u32 m11;
    u32 m12;
    u32 m21;
    u32 m22;

    prevSlot = gNextOAMSlot;
    src = pSprite->pOam[pSprite->currentAnimationFrame].pFrame;
    partCount = *src++;

    if (prevSlot + partCount >= 0x80)
        return;

    dst = (u16*)(gOamData + prevSlot);
    yPosition = pSprite->yPosition / 4 - gBG1YPosition / 4;
    xPosition = pSprite->xPosition / 4 - gBG1XPosition / 4;

    xFlip = pSprite->status & SPRITE_STATUS_XFLIP;
    yFlip = pSprite->status & SPRITE_STATUS_YFLIP;
    doubleSize = pSprite->status & SPRITE_STATUS_DOUBLE_SIZE;
    alphaBlending = pSprite->status & SPRITE_STATUS_ALPHA_BLENDING;
    facingDown = pSprite->status & SPRITE_STATUS_FACING_DOWN;

    paletteRow = pSprite->spritesetGFXSlot + pSprite->paletteRow;
    gfxOffset = pSprite->spritesetGFXSlot * 0x40;
    bgPriority = pSprite->bgPriority;

    if (gSamusOnTopOfBackgrounds && bgPriority)
        bgPriority--;

    if (pSprite->properties & SP_ABSOLUTE_POSITION)
    {
        yPosition = pSprite->yPosition;
        xPosition = pSprite->xPosition;
    }

    if (!(pSprite->status & SPRITE_STATUS_ROTATION_SCALING))
    {     
        for (i = 0; i < partCount; i++)
        {
            part1 = *src++;
            *dst++ = part1;
            part2 = *src++;
            *dst++ = part2;
            *dst = *src++; // Copy source and save part 1 and 2

            currSlot = prevSlot + i;
            gOamData[currSlot].split.y = part1 + yPosition;
            gOamData[currSlot].split.x = part2 + xPosition;
            gOamData[currSlot].split.priority = bgPriority;
            gOamData[currSlot].split.paletteNum = paletteRow;
            gOamData[currSlot].split.tileNum += gfxOffset;

            if (xFlip)
            {
                gOamData[currSlot].split.xFlip ^= TRUE;
                shape = gOamData[currSlot].split.shape;
                size = gOamData[currSlot].split.size;
                gOamData[currSlot].split.x = xPosition - (part1 + sOamXFlipOffsets[shape][size] * 8);
            }

            if (facingDown)
            {
                gOamData[currSlot].split.yFlip ^= TRUE;
                shape = gOamData[currSlot].split.shape;
                size = gOamData[currSlot].split.size;
                gOamData[currSlot].split.y = yPosition - (part2 + sOamYFlipOffsets[shape][size] * 8);
            }

            if (yFlip)
            {
                if (doubleSize)
                    gOamData[currSlot].split.affineMode = 3;
                else
                    gOamData[currSlot].split.affineMode = 1;

                // .
            }

            if (alphaBlending)
                gOamData[currSlot].split.objMode = 1; // Semi transparent

            dst++;
        }

        gNextOAMSlot = prevSlot + partCount;

        if (yFlip)
        {
            rotation = pSprite->oamRotation;
            scaling = pSprite->oamScaling;

            if (xFlip)
            {
                sine = sSineYValues[rotation + 0x40];
                gOamData[slot * 4].all.affineParam = FixedMultiplication(sine, FixedInverse(scaling));
                sine = sSineYValues[rotation];
                gOamData[slot * 4 + 1].all.affineParam = FixedMultiplication(sine, FixedInverse(scaling));
            }
            else
            {
                sine = sSineYValues[rotation + 0x40];
                gOamData[slot * 4].all.affineParam = FixedMultiplication(sine, FixedInverse(-scaling));
                sine = sSineYValues[rotation];
                gOamData[slot * 4 + 1].all.affineParam = FixedMultiplication(sine, FixedInverse(-scaling));
            }
            
            sine = sSineYValues[rotation];
            gOamData[slot * 4 + 2].all.affineParam = FixedMultiplication(-sine, FixedInverse(scaling));
            sine = sSineYValues[rotation + 0x40];
            gOamData[slot * 4 + 3].all.affineParam = FixedMultiplication(sine, FixedInverse(scaling));
        }
    }
    else
    {
        rotation = pSprite->oamRotation;
        scaling = pSprite->oamScaling;

        mosaic = pSprite->status & SPRITE_STATUS_MOSAIC;

        yPosition += BLOCK_SIZE;
        xPosition += BLOCK_SIZE;

        for (i = 0; i < partCount; i++)
        {
            part1 = *src++;
            *dst++ = part1;
            part2 = *src++;
            *dst++ = part2;
            part3 = *dst = *src++; // Copy source and save part 1, 2 and 3

            gOamData[currSlot].split.priority = bgPriority;
            gOamData[currSlot].split.paletteNum = paletteRow;

            gOamData[currSlot].split.tileNum += gfxOffset;

            shape = gOamData[currSlot].split.shape;
            size = gOamData[currSlot].split.size;

            yOffset = sOamYFlipOffsets[shape][size] * 4;
            xOffset = sOamXFlipOffsets[shape][size];

            tempY = (part2 + yPosition) & 0xFF;
            tempX = (part1 + xPosition) & 0x1FF;

            yParam = (tempY - yPosition) + yOffset;
            xParam = (tempX - xPosition) + xOffset;

            yParam = tempY + (yParam * scaling - yParam);
            xParam = tempX + (xParam * scaling - xParam);

            m11 = sSineYValues[rotation + 0x40] * xParam;
            m12 = sSineYValues[rotation] * yParam;
            m21 = sSineYValues[rotation + 0x40] * yParam;
            m22 = sSineYValues[rotation] * xParam;

            if (doubleSize)
            {

            }
            else
            {

            }

            gOamData[currSlot].split.y = m11 - m12 - yOffset + (yPosition - BLOCK_SIZE);
            gOamData[currSlot].split.x = m21 - m22 - xOffset + (xPosition - BLOCK_SIZE);

            if (doubleSize)
                gOamData[currSlot].split.affineMode = 3;
            else
                gOamData[currSlot].split.affineMode = 1;

            // . Mosaic

            if (alphaBlending)
                gOamData[currSlot].split.objMode = 1; // Semi transparent

            dst++;
        }
        
        gNextOAMSlot = prevSlot + partCount;

        sine = sSineYValues[rotation];
        dy = FixedMultiplication(-sine, FixedInverse(scaling));
        sine = sSineYValues[rotation + 0x40];
        dmy = FixedMultiplication(sine, FixedInverse(scaling));

        if (mosaic)
        {
            gOamData[112].all.affineParam = FixedMultiplication(sine, FixedInverse(scaling));
            gOamData[113].all.affineParam = FixedMultiplication(sSineYValues[rotation], FixedInverse(scaling));
            gOamData[114].all.affineParam = dy;
            gOamData[115].all.affineParam = dmy;

            gOamData[116].all.affineParam = FixedMultiplication(sine, FixedInverse(-scaling));
            gOamData[117].all.affineParam = FixedMultiplication(sSineYValues[rotation], FixedInverse(-scaling));
            gOamData[118].all.affineParam = dy;
            gOamData[119].all.affineParam = dmy;
        }
        else
        {
            gOamData[120].all.affineParam = FixedMultiplication(sine, FixedInverse(scaling));
            gOamData[121].all.affineParam = FixedMultiplication(sSineYValues[rotation], FixedInverse(scaling));
            gOamData[122].all.affineParam = dy;
            gOamData[123].all.affineParam = dmy;

            gOamData[124].all.affineParam = FixedMultiplication(sine, FixedInverse(-scaling));
            gOamData[125].all.affineParam = FixedMultiplication(sSineYValues[rotation], FixedInverse(-scaling));
            gOamData[126].all.affineParam = dy;
            gOamData[127].all.affineParam = dmy;
        }
    }
}

void SpriteCheckOnScreen(struct SpriteData* pSprite)
{

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
    // https://decomp.me/scratch/N5TjC
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
    u8 newSlot;
    struct SpriteData* pSprite;
    u16 status;

    newSlot = 0x0;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
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

            return newSlot;
        }

        newSlot++;
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
    u8 newSlot;
    struct SpriteData* pSprite;
    u16 status;

    newSlot = 0x0;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
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
            pSprite->primarySpriteRAMSlot = newSlot;
            pSprite->freezeTimer = 0x0;
            pSprite->standingOnSprite = FALSE;

            return newSlot;
        }

        newSlot++;
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
    u8 newSlot;
    struct SpriteData* pSprite;
    u16 status;

    newSlot = 0x0;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
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

            return newSlot;
        }

        newSlot++;
    }

    return 0xFF;
}