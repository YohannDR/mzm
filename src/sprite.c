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
#include "structs/room.h"
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

void SpriteDraw(struct SpriteData* pSprite, i32 slot)
{
    // https://decomp.me/scratch/7FvMo

    /*
        Stack order :

        0 ramSlot
        4 i
        8 part count
        c Y offset
        10 X offset
        14 xflip
        18 double
        1c alpha
        20 mosaic
        24 facing down
        28 bgPriority
        2c palette
        30 gfxRow
        34 xPos
        38 yPos
        3c rotation
        40 scaling
        44 bgPriority (shifter, optimisation)
        48 partCount + prevSlot
    */
    
    const u16* src;
    u16* dst;
    u8 prevSlot;
    u16 part1;
    u16 part2;
    u8 part3;
    


    u32 shape;
    u32 size;
    

    u16 dy;
    u16 dmy;

    i16 actualY;
    i16 actualX;
    i16 yScaling;
    i16 xScaling;
    u32 m11;
    u32 m12;
    u32 m21;
    u32 m22;
    u32 y;
    u32 x;

    u16 yFlip;
    i32 i;
    u16 partCount;
    u32 yOffset;
    u32 xOffset;
    u16 xFlip;
    u16 doubleSize;
    u16 alphaBlending;
    u16 mosaic;
    u16 facingDown;
    u32 bgPriority;
    u32 paletteRow;
    u32 gfxOffset;
    u16 xPosition;
    u16 yPosition;
    u16 rotation;
    u16 scaling;

    prevSlot = gNextOAMSlot;
    src = pSprite->pOam[pSprite->currentAnimationFrame].pFrame;
    partCount = *src++;

    if (partCount + prevSlot >= 0x80)
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
            *dst++ = *src++; // Copy source and save part 1 and 2

            gOamData[prevSlot + i].split.y = part1 + yPosition;
            gOamData[prevSlot + i].split.x = part2 + xPosition;
            gOamData[prevSlot + i].split.priority = bgPriority;
            gOamData[prevSlot + i].split.paletteNum += paletteRow;
            gOamData[prevSlot + i].split.tileNum += gfxOffset;

            if (xFlip)
            {
                gOamData[prevSlot + i].split.xFlip ^= TRUE;
                shape = gOamData[prevSlot + i].split.shape;
                size = gOamData[prevSlot + i].split.size;
                gOamData[prevSlot + i].split.x = xPosition - (part1 + sOamXFlipOffsets[shape][size] * 8);
            }

            if (facingDown)
            {
                gOamData[prevSlot + i].split.yFlip ^= TRUE;
                shape = gOamData[prevSlot + i].split.shape;
                size = gOamData[prevSlot + i].split.size;
                gOamData[prevSlot + i].split.y = yPosition - (part2 + sOamYFlipOffsets[shape][size] * 8);
            }

            if (yFlip)
            {
                if (doubleSize)
                    gOamData[prevSlot + i].split.affineMode = 3;
                else
                    gOamData[prevSlot + i].split.affineMode = 1;

                gOamData[prevSlot + i].split.yFlip = slot >> 4;
                gOamData[prevSlot + i].split.xFlip = slot >> 3;
                gOamData[prevSlot + i].split.matrixNum = slot;
            }

            if (alphaBlending)
                gOamData[prevSlot + i].split.objMode = 1; // Semi transparent

            dst++;
        }

        gNextOAMSlot = partCount + prevSlot;

        if (yFlip)
        {
            rotation = pSprite->oamRotation;
            scaling = pSprite->oamScaling;

            if (xFlip)
            {
                gOamData[slot * 4].all.affineParam = FixedMultiplication(cos(rotation), FixedInverse(-scaling));
                gOamData[slot * 4 + 1].all.affineParam = FixedMultiplication(sin(rotation), FixedInverse(-scaling));
            }
            else
            {
                gOamData[slot * 4].all.affineParam = FixedMultiplication(cos(rotation), FixedInverse(scaling));
                gOamData[slot * 4 + 1].all.affineParam = FixedMultiplication(sin(rotation), FixedInverse(scaling));
            }
            
            gOamData[slot * 4 + 2].all.affineParam = FixedMultiplication(-sin(rotation), FixedInverse(scaling));
            gOamData[slot * 4 + 3].all.affineParam = FixedMultiplication(cos(rotation), FixedInverse(scaling));
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
            part3 = *dst++ = *src++; // Copy source and save part 1, 2 and 3

            gOamData[prevSlot + i].split.priority = bgPriority;
            gOamData[prevSlot + i].split.paletteNum += paletteRow;

            gOamData[prevSlot + i].split.tileNum += gfxOffset;

            shape = gOamData[prevSlot + i].split.shape;
            size = gOamData[prevSlot + i].split.size;

            yOffset = sOamYFlipOffsets[shape][size] * 4;
            xOffset = sOamXFlipOffsets[shape][size] * 4;

            actualY = (part1 + yPosition) & 0xFF;
            actualX = (part2 + xPosition) & 0x1FF;

            part1 = actualY - yPosition + yOffset;
            part2 = actualX - xPosition + xOffset;

            yScaling = part1 * scaling / 256 - part1;
            xScaling = part2 * scaling / 256 - part2;
            
            actualY = actualY + yScaling - yOffset;
            actualX = actualX + xScaling - xOffset;

            m11 = actualX * cos(rotation);
            m12 = actualY * sin(rotation);
            m21 = actualX * sin(rotation);
            m22 = actualY * cos(rotation);

            y = (m21 + m22) / 8;
            x = (m11 - m12) / 8;

            if (doubleSize)
            {
                x -= xOffset * 2;
                y -= yOffset * 2;
            }
            else
            {
                x -= xOffset;
                y -= yOffset;
            }

            gOamData[prevSlot + i].split.y = y + yPosition - BLOCK_SIZE;
            gOamData[prevSlot + i].split.x = x + xPosition - BLOCK_SIZE;

            if (doubleSize)
                gOamData[prevSlot + i].split.affineMode = 3;
            else
                gOamData[prevSlot + i].split.affineMode = 1;

            if (mosaic)
            {
                if (gOamData[prevSlot + i].split.xFlip)
                {
                    gOamData[prevSlot + i].split.x--;
                    gOamData[prevSlot + i].split.yFlip = TRUE;
                    gOamData[prevSlot + i].split.xFlip = TRUE;
                    gOamData[prevSlot + i].split.matrixNum = 5;
                }
                else
                {
                    gOamData[prevSlot + i].split.yFlip = TRUE;
                    gOamData[prevSlot + i].split.xFlip = TRUE;
                    gOamData[prevSlot + i].split.matrixNum = 4;
                }
            }
            else
            {
                if (gOamData[prevSlot + i].split.xFlip)
                {
                    gOamData[prevSlot + i].split.x--;
                    gOamData[prevSlot + i].split.yFlip = TRUE;
                    gOamData[prevSlot + i].split.xFlip = TRUE;
                    gOamData[prevSlot + i].split.matrixNum = 7;
                }
                else
                {
                    gOamData[prevSlot + i].split.yFlip = TRUE;
                    gOamData[prevSlot + i].split.xFlip = TRUE;
                    gOamData[prevSlot + i].split.matrixNum = 6;
                }
            }

            if (alphaBlending)
                gOamData[prevSlot + i].split.objMode = 1; // Semi transparent

            dst++;
        }
        
        gNextOAMSlot = partCount + prevSlot;

        dy = FixedMultiplication(-sin(rotation), FixedInverse(scaling));
        dmy = FixedMultiplication(cos(rotation), FixedInverse(scaling));

        if (mosaic)
        {
            gOamData[112].all.affineParam = FixedMultiplication(cos(rotation), FixedInverse(scaling));
            gOamData[113].all.affineParam = FixedMultiplication(sin(rotation), FixedInverse(scaling));
            gOamData[114].all.affineParam = dy;
            gOamData[115].all.affineParam = dmy;

            gOamData[116].all.affineParam = FixedMultiplication(cos(rotation), FixedInverse(-scaling));
            gOamData[117].all.affineParam = FixedMultiplication(sin(rotation), FixedInverse(-scaling));
            gOamData[118].all.affineParam = dy;
            gOamData[119].all.affineParam = dmy;
        }
        else
        {
            gOamData[120].all.affineParam = FixedMultiplication(cos(rotation), FixedInverse(scaling));
            gOamData[121].all.affineParam = FixedMultiplication(sin(rotation), FixedInverse(scaling));
            gOamData[122].all.affineParam = dy;
            gOamData[123].all.affineParam = dmy;

            gOamData[124].all.affineParam = FixedMultiplication(cos(rotation), FixedInverse(-scaling));
            gOamData[125].all.affineParam = FixedMultiplication(sin(rotation), FixedInverse(-scaling));
            gOamData[126].all.affineParam = dy;
            gOamData[127].all.affineParam = dmy;
        }
    }
}

/**
 * @brief ddd4 | 150 | Checks if a sprite is on screen
 * 
 * @param pSprite Sprite Data Pointer
 */
void SpriteCheckOnScreen(struct SpriteData* pSprite)
{
    u16 bgBaseY;
    u16 bgBaseX;
    u16 bgXRange;
    u16 bgYRange;

    u16 spriteY;
    u16 spriteX;
    u16 spriteYRange;
    u16 spriteXRange;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;

    u32 drawOffset;

    if (!(pSprite->properties & SP_ABSOLUTE_POSITION))
    {
        bgBaseY = gBG1YPosition;
        bgBaseX = gBG1XPosition;

        spriteY = pSprite->yPosition;
        spriteX = pSprite->xPosition;

        bgYRange = bgBaseY + BLOCK_SIZE * 8;
        spriteYRange = spriteY + BLOCK_SIZE * 8;
        spriteBottom = bgYRange - pSprite->drawDistanceBottomOffset * 4;
        drawOffset = pSprite->drawDistanceTopOffset * 4 + BLOCK_SIZE * 10;
        spriteTop = bgYRange + drawOffset;

        bgXRange = bgBaseX + BLOCK_SIZE * 8;
        spriteXRange = spriteX + BLOCK_SIZE * 8;
        spriteLeft = bgXRange - pSprite->drawDistanceHorizontalOffset * 4;
        drawOffset = pSprite->drawDistanceHorizontalOffset * 4 + BLOCK_SIZE * 15;
        spriteRight = bgXRange + drawOffset;

        if (spriteLeft < spriteXRange && spriteXRange < spriteRight && spriteBottom < spriteYRange && spriteYRange < spriteTop)
            pSprite->status |= SPRITE_STATUS_ONSCREEN;
        else
        {
            pSprite->status &= ~SPRITE_STATUS_ONSCREEN;
            if (pSprite->properties & SP_KILL_OFF_SCREEN)
            {
                bgYRange = bgBaseY + BLOCK_SIZE * 10;
                spriteYRange = spriteY + BLOCK_SIZE * 10;
                spriteBottom = bgYRange - BLOCK_SIZE * 9;
                spriteTop = bgYRange + BLOCK_SIZE * 19;

                bgXRange = bgBaseX + BLOCK_SIZE * 10;
                spriteXRange = spriteX + BLOCK_SIZE * 10;
                spriteLeft = bgXRange - BLOCK_SIZE * 9;
                spriteRight = bgXRange + BLOCK_SIZE * 24;

                if (spriteLeft >= spriteXRange || spriteXRange >= spriteRight || spriteBottom >= spriteYRange || spriteYRange >= spriteTop)
                    pSprite->status = 0;
            }
        }
    }
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
    // https://decomp.me/scratch/59czd

    i32 i;
    i32 j;
    i32 spriteset;
    u32 spriteID;
    u32 gfxSlot;
    u32 prevGfxSlot;
    u16 nbrRows;

    i32 ctrl_1;
    i32 ctrl_2;

    for (i = 0; i < 15; i++)
    {
        gSpritesetSpritesID[i] = PSPRITE_UNUSED16;
        gSpritesetGFXSlots[i] = 0;
    }

    prevGfxSlot = UCHAR_MAX;
    spriteset = gSpriteset;
    if (spriteset >= MAX_AMOUNT_OF_SPRITESET - 1)
    {
        if (gCurrentArea > AREA_INVALID)
            spriteset = MAX_AMOUNT_OF_SPRITESET - 1;
        else
            spriteset = 0;
    }

    j = 0;
    for (i = 0; i < 15; i++)
    {
        spriteID = sSpritesetPointers[spriteset][j * 2];
        gfxSlot = sSpritesetPointers[spriteset][j * 2 + 1];

        j++;
        
        if (spriteID == PSPRITE_UNUSED0)
            break;

        gSpritesetSpritesID[i] = spriteID;
        gSpritesetGFXSlots[i] = gfxSlot & 7;

        if (gfxSlot != prevGfxSlot)
        {
            prevGfxSlot = gfxSlot;
            if (gfxSlot != 8)
            {
                spriteID -= 0x10;

                LZ77UncompVRAM(sSpritesGraphicsPointers[spriteID], VRAM_BASE + 0x14000 + (gfxSlot * 2048));

                ctrl_1 = ((u8*)sSpritesGraphicsPointers[spriteID])[1];
                ctrl_2 = ((u8*)sSpritesGraphicsPointers[spriteID])[2] << 8;
                dma_set(3, sSpritesPalettePointers[spriteID], PALRAM_BASE + 0x300 + gfxSlot * 32,
                    (DMA_ENABLE << 16) | (ctrl_1 | ctrl_2) / 2048 << 4);
            }
        }
    }
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

/**
 * @brief e0f0 | 44 | Clears the sprite data (including debris)
 * 
 */
void SpriteClearData(void)
{
    i32 i;

    // Clear sprites
    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        gSpriteData[i].status = 0;
        gSpriteData[i].standingOnSprite = FALSE;
        gSpriteData[i].roomSlot = UCHAR_MAX;
    }

    // Clear debris
    for (i = 0; i < MAX_AMOUNT_OF_SPRITE_DEBRIS; i++)
        gSpriteDebris[i].exists = FALSE;
}

/**
 * @brief e134 | 48 | Loads the sprites of the current room
 * 
 */
void SpriteLoadRoomSprites(void)
{
    u8 i;
    u8 y;
    u8 x;
    u8 slot;
    
    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        /*
            0 | Y position
            1 | X position
            2 | Spriteset slot
        */
        y = gCurrentRoomEntry.pEnemyRoomData[i * 3];

        // Terminator
        if (y == 0xFF)
            break;

        x = gCurrentRoomEntry.pEnemyRoomData[i * 3 + 1];
        slot = gCurrentRoomEntry.pEnemyRoomData[i * 3 + 2];
        SpriteInitPrimary(slot, y, x, i);
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