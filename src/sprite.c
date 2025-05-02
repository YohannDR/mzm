#include "sprite.h"
#include "sprite_debris.h"
#include "syscalls.h"
#include "gba.h"
#include "macros.h"
#include "fixed_point.h"

#include "data/generic_data.h"
#include "data/samus_sprites_pointers.h"
#include "data/sprite_data.h"

#include "constants/game_state.h"
#include "constants/connection.h"
#include "constants/sprite.h"
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
    rngParam2 = gFrameCounter16Bit / 16;

    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
    {
        // In normal gameplay

        SpriteDebrisProcessAll();

        if (!SpriteUtilCheckStopSpritesPose())
        {
            // Samus is able, update sprites normally

            // Check collision
            SpriteUtilSamusAndSpriteCollision();

            for (count = 0; count < MAX_AMOUNT_OF_SPRITES; count++)
            {
                if (!(gSpriteData[count].status & SPRITE_STATUS_EXISTS))
                    continue;

                // Transfer sprite to current
                DMA_SET(3, &gSpriteData[count], &gCurrentSprite, C_32_2_16(DMA_ENABLE, sizeof(struct SpriteData) / 2));

                // Update random number
                gSpriteRng = ARRAY_ACCESS(sSpriteRandomNumberTable, rngParam1 + count + rngParam2 + pCurrent->xPosition + pCurrent->yPosition);

                // Update stun timer
                SpriteUtilUpdateStunTimer(pCurrent);

                // Call AI
                if (pCurrent->properties & SP_SECONDARY_SPRITE)
                    sSecondarySpritesAIPointers[pCurrent->spriteId]();
                else
                    sPrimarySpritesAIPointers[pCurrent->spriteId]();

                // Check update sprite info if still alive
                if (pCurrent->status & SPRITE_STATUS_EXISTS)
                {
                    SpriteUtilSamusStandingOnSprite(pCurrent);
                    SpriteUpdateAnimation(pCurrent);
                    SpriteCheckOnScreen(pCurrent);
                }

                // Transfer current back to array
                DMA_SET(3, &gCurrentSprite, &gSpriteData[count], C_32_2_16(DMA_ENABLE, sizeof(struct SpriteData) / 2));
            }

            // Update alarm
            DecrementChozodiaAlarm();

            if (gParasiteRelated != 0)
                gParasiteRelated--;
        }
        else
        {
            // Samus isn't able, still update sprites but only on some conditions

            for (count = 0; count < MAX_AMOUNT_OF_SPRITES; count++)
            {
                if (!(gSpriteData[count].status & SPRITE_STATUS_EXISTS))
                    continue;

                if (gSpriteData[count].pose == SPRITE_POSE_UNINITIALIZED || gSpriteData[count].properties & SP_ALWAYS_ACTIVE)
                {
                    // Only update sprites to initialize them or if they have the always active flag

                    // Transfer sprite to current
                    DMA_SET(3, &gSpriteData[count], &gCurrentSprite, C_32_2_16(DMA_ENABLE, sizeof(struct SpriteData) / 2));
                    
                    // Update random number
                    gSpriteRng = ARRAY_ACCESS(sSpriteRandomNumberTable, rngParam1 + count + rngParam2 + pCurrent->xPosition + pCurrent->yPosition);

                    // Update stun timer
                    SpriteUtilUpdateStunTimer(pCurrent);

                    // Call AI
                    if (pCurrent->properties & SP_SECONDARY_SPRITE)
                        sSecondarySpritesAIPointers[pCurrent->spriteId]();
                    else
                        sPrimarySpritesAIPointers[pCurrent->spriteId]();

                    // Check update sprite info if still alive
                    if (pCurrent->status & SPRITE_STATUS_EXISTS)
                    {
                        SpriteUtilSamusStandingOnSprite(pCurrent);
                        SpriteUpdateAnimation(pCurrent);
                        SpriteCheckOnScreen(pCurrent);
                    }

                    // Transfer current back to array
                    DMA_SET(3, &gCurrentSprite, &gSpriteData[count], C_32_2_16(DMA_ENABLE, sizeof(struct SpriteData) / 2));
                }
                else
                {
                    // Only check if on screen

                    // Transfer sprite to current
                    DMA_SET(3, &gSpriteData[count], &gCurrentSprite, C_32_2_16(DMA_ENABLE, sizeof(struct SpriteData) / 2));

                    SpriteCheckOnScreen(pCurrent);

                    // Transfer current back to array
                    DMA_SET(3, &gCurrentSprite, &gSpriteData[count], C_32_2_16(DMA_ENABLE, sizeof(struct SpriteData) / 2));
                }
            }
        }
    }
    else if (gGameModeSub1 == SUB_GAME_MODE_NO_CLIP)
    {
        // In debug no-clip, update sprites normally but don't check for collision
        for (count = 0; count < MAX_AMOUNT_OF_SPRITES; count++)
        {
            if (!(gSpriteData[count].status & SPRITE_STATUS_EXISTS))
                continue;

            // Transfer sprite to current
            DMA_SET(3, &gSpriteData[count], &gCurrentSprite, C_32_2_16(DMA_ENABLE, sizeof(struct SpriteData) / 2));

            // Update random number
            gSpriteRng = ARRAY_ACCESS(sSpriteRandomNumberTable, rngParam1 + count + rngParam2 + pCurrent->xPosition + pCurrent->yPosition);
            
            // Update stun timer
            SpriteUtilUpdateStunTimer(pCurrent);

            // Call AI
            if (pCurrent->properties & SP_SECONDARY_SPRITE)
                sSecondarySpritesAIPointers[pCurrent->spriteId]();
            else
                sPrimarySpritesAIPointers[pCurrent->spriteId]();

            // Check update sprite info if still alive
            if (pCurrent->status & SPRITE_STATUS_EXISTS)
            {
                SpriteUtilSamusStandingOnSprite(pCurrent);
                SpriteUpdateAnimation(pCurrent);
                SpriteCheckOnScreen(pCurrent);
            }

            // Transfer current back to array
            DMA_SET(3, &gCurrentSprite, &gSpriteData[count], C_32_2_16(DMA_ENABLE, sizeof(struct SpriteData) / 2));
        }

        // Update alarm
        DecrementChozodiaAlarm();

        if (gParasiteRelated != 0)
            APPLY_DELTA_TIME_DEC(gParasiteRelated);
    }
    else
    {
        // Any other sub game mode
        for (count = 0; count < MAX_AMOUNT_OF_SPRITES; count++)
        {
            if (!(gSpriteData[count].status & SPRITE_STATUS_EXISTS))
                continue;

            // Transfer sprite to current
            DMA_SET(3, &gSpriteData[count], &gCurrentSprite, C_32_2_16(DMA_ENABLE, sizeof(struct SpriteData) / 2));

            // Update random number
            gSpriteRng = ARRAY_ACCESS(sSpriteRandomNumberTable, rngParam1 + count + rngParam2 + pCurrent->xPosition + pCurrent->yPosition);

            // Only call init code
            if (pCurrent->pose == SPRITE_POSE_UNINITIALIZED)
            {
                // Call AI
                if (pCurrent->properties & SP_SECONDARY_SPRITE)
                    sSecondarySpritesAIPointers[pCurrent->spriteId]();
                else
                    sPrimarySpritesAIPointers[pCurrent->spriteId]();
            }

            // Check update sprite info if still alive
            if (pCurrent->status & SPRITE_STATUS_EXISTS)
                SpriteCheckOnScreen(pCurrent);

            // Transfer current back to array
            DMA_SET(3, &gCurrentSprite, &gSpriteData[count], C_32_2_16(DMA_ENABLE, sizeof(struct SpriteData) / 2));
        }
    }
}

/**
 * d32c | 40 | Updates the animation related info of a sprite
 * 
 * @param pSprite Sprite data pointer
 */
void SpriteUpdateAnimation(struct SpriteData* pSprite)
{
    // Don't update the animation if freezed
    if (pSprite->freezeTimer != 0)
        return;

    // Update adc
    APPLY_DELTA_TIME_INC(pSprite->animationDurationCounter);

    // Check reached the end of the current frame
    if (pSprite->pOam[pSprite->currentAnimationFrame].timer < pSprite->animationDurationCounter)
    {
        // Advance to next frame
        pSprite->animationDurationCounter = 1;
        pSprite->currentAnimationFrame++;

        // Reached the end, set caf to 0 to loop back the animation
        if (pSprite->pOam[pSprite->currentAnimationFrame].timer == 0)
            pSprite->currentAnimationFrame = 0;
    }
}

/**
 * @brief d36c | c4 | Call draw sprite function, difference with the other is unknown
 * 
 */
void SpriteDrawAll_2(void)
{
    struct SpriteData* pSprite;
    s32 i;
    s32 drawOrder;
    u32 drawStatus;
    u32 checkStatus;
    u32 notPlaying;

    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
        notPlaying = FALSE;
    else
        notPlaying = TRUE;

    checkStatus = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN_10;
    drawStatus = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_UNKNOWN_10;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        // Sprite doesn't exists or isn't drawn
        if ((gSpriteData[i].status & checkStatus) != drawStatus)
        {
            gSpriteDrawOrder[i] = 0;
            continue;
        }

        // Check is lower draw order
        if (gSpriteData[i].drawOrder >= 9)
        {
            gSpriteDrawOrder[i] = 0;
            continue;
        }

        // Check is playing
        if (!notPlaying)
        {
            gSpriteDrawOrder[i] = gSpriteData[i].drawOrder;
            continue;
        }

        // Don't draw sprites that have an absolute position if not in game
        if (!(gSpriteData[i].properties & SP_ABSOLUTE_POSITION))
            gSpriteDrawOrder[i] = gSpriteData[i].drawOrder;
        else
            gSpriteDrawOrder[i] = 0;
    }

    // Apply draw order and draw sprites
    for (drawOrder = 1; drawOrder < 9; drawOrder++)
    {
        for (i = 0, pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; i++, pSprite++)
        {
            if (gSpriteDrawOrder[i] == drawOrder)
                SpriteDraw(pSprite, i);
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
    s32 i;
    s32 drawOrder;
    u32 drawStatus;
    u32 checkStatus;

    checkStatus = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN_10;
    drawStatus = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN;
    
    SpriteDebrisDrawAll();

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        // Sprite doesn't exists or isn't drawn
        if ((gSpriteData[i].status & checkStatus) != drawStatus)
        {
            gSpriteDrawOrder[i] = 0;
            continue;
        }

        // Check is lower draw order
        if (gSpriteData[i].drawOrder < 9)
            gSpriteDrawOrder[i] = gSpriteData[i].drawOrder;
        else
            gSpriteDrawOrder[i] = 0;
    }

    // Apply draw order and draw sprites
    for (drawOrder = 1; drawOrder < 9; drawOrder++)
    {
        for (i = 0, pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; i++, pSprite++)
        {
            if (gSpriteDrawOrder[i] == drawOrder)
                SpriteDraw(pSprite, i);
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
    s32 i;
    s32 drawOrder;
    u32 drawStatus;
    u32 checkStatus;

    checkStatus = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN_10;
    drawStatus = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        // Sprite doesn't exists or isn't drawn
        if ((gSpriteData[i].status & checkStatus) != drawStatus)
        {
            gSpriteDrawOrder[i] = 0;
            continue;
        }

        // Check is upper draw order
        if (gSpriteData[i].drawOrder >= 9)
            gSpriteDrawOrder[i] = gSpriteData[i].drawOrder;
        else
            gSpriteDrawOrder[i] = 0;
    }

    // Apply draw order and draw sprites
    for (drawOrder = 9; drawOrder < 17; drawOrder++)
    {
        for (i = 0, pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; i++, pSprite++)
        {
            if (gSpriteDrawOrder[i] == drawOrder)
                SpriteDraw(pSprite, i);
        }
    }
}

/**
 * @brief d544 | 890 | Draws a sprite
 * 
 * @param pSprite Sprite data pointer
 * @param slot Ram slot
 */
void SpriteDraw(struct SpriteData* pSprite, s32 slot)
{
    const u16* src;
    u16* dst;
    u8 prevSlot;
    u16 part1;
    u16 part2;

    u32 shape;
    u32 size;
    
    u16 dy;
    u16 dmy;

    s16 actualY;
    s16 actualX;
    s16 yScaling;
    s16 xScaling;
    s32 y;
    s32 x;
    s32 unk_2;
    s32 unk_3;
    s32 tmpX;
    s32 tmpY;
    s32 scaledX;
    s32 scaledY;

    u16 status_unk3;
    s32 i;
    u16 partCount;
    
    u32 yOffset;
    u32 xOffset;
    
    u16 xFlip;
    u16 doubleSize;
    u16 alphaBlending;
    u16 mosaic;
    u16 yFlip;
    u32 bgPriority;
    u32 paletteRow;
    u32 gfxOffset;
    u16 xPosition;
    u16 yPosition;
    u16 rotation;
    u16 scaling;

    u8 offset;

    prevSlot = gNextOamSlot;
    src = pSprite->pOam[pSprite->currentAnimationFrame].pFrame;
    partCount = *src++;

    if (partCount + prevSlot >= OAM_BUFFER_DATA_SIZE)
        return;

    dst = (u16*)(gOamData + prevSlot);
    yPosition = SUB_PIXEL_TO_PIXEL_(pSprite->yPosition) - SUB_PIXEL_TO_PIXEL(gBg1YPosition);
    xPosition = SUB_PIXEL_TO_PIXEL_(pSprite->xPosition) - SUB_PIXEL_TO_PIXEL(gBg1XPosition);

    // Shortcuts for status
    xFlip = pSprite->status & SPRITE_STATUS_X_FLIP;
    status_unk3 = pSprite->status & SPRITE_STATUS_UNKNOWN_80;
    doubleSize = pSprite->status & SPRITE_STATUS_DOUBLE_SIZE;
    alphaBlending = pSprite->status & SPRITE_STATUS_ALPHA_BLENDING;
    yFlip = pSprite->status & SPRITE_STATUS_Y_FLIP;

    // Get graphical data
    // Palette offset by spriteset slot
    paletteRow = pSprite->spritesetGfxSlot + pSprite->paletteRow;
    // Gfx slot, scale to 2 rows of 8x8 tiles in VRAM
    gfxOffset = pSprite->spritesetGfxSlot * 64;
    bgPriority = pSprite->bgPriority;

    if (gSamusOnTopOfBackgrounds && bgPriority != 0)
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
            // Raw copy
            part1 = *src++;
            *dst++ = part1;
            part2 = *src++;
            *dst++ = part2;
            *dst++ = *src++;

            // Apply position
            gOamData[prevSlot + i].split.y = part1 + yPosition;
            gOamData[prevSlot + i].split.x = part2 + xPosition;

            // Apply graphics
            gOamData[prevSlot + i].split.priority = bgPriority;
            // Add palette row and gfx offset
            gOamData[prevSlot + i].split.paletteNum += paletteRow;
            gOamData[prevSlot + i].split.tileNum += gfxOffset;

            if (xFlip)
            {
                // Enable X flip
                gOamData[prevSlot + i].split.xFlip ^= TRUE;

                shape = gOamData[prevSlot + i].split.shape;
                size = gOamData[prevSlot + i].split.size;
                offset = sOamXFlipOffsets[shape][size];

                // Properly offset x position
                gOamData[prevSlot + i].split.x = xPosition - (part2 + offset * 8);
            }

            if (yFlip)
            {
                // Enable Y flip
                gOamData[prevSlot + i].split.yFlip ^= TRUE;
                shape = gOamData[prevSlot + i].split.shape;
                size = gOamData[prevSlot + i].split.size;
                offset = sOamYFlipOffsets[shape][size];

                // Properly offset x position
                gOamData[prevSlot + i].split.y = yPosition - (part1 + offset * 8);
            }

            if (status_unk3)
            {
                if (doubleSize)
                {
                    // Rotation scaling and double size
                    gOamData[prevSlot + i].split.affineMode = 3;
                }
                else
                {
                    // Rotation scaling
                    gOamData[prevSlot + i].split.affineMode = 1;
                }

                // In this affine mode, X/Y flip are part of the matrix num, so this is just doing matrixNum = slot
                gOamData[prevSlot + i].split.yFlip = slot >> 4;
                gOamData[prevSlot + i].split.xFlip = slot >> 3;
                gOamData[prevSlot + i].split.matrixNum = slot;
            }

            if (alphaBlending)
            {
                // Semi transparent
                gOamData[prevSlot + i].split.objMode = OAM_OBJ_MODE_SEMI_TRANSPARENT;
            }

            dst++;
        }

        // Update next oam slot
        gNextOamSlot = partCount + prevSlot;

        if (status_unk3)
        {
            rotation = pSprite->rotation;
            scaling = pSprite->scaling;

            // Rotation matrix (column major mode) :
            // [ cos / scaling, -sin / scaling ]
            // [ sin / scaling,  cos / scaling ]

            // If x flipped, then negate scaling on the first column to manually flip the sprite since flipping
            // isn't supported by hardware when affine transformation is enabled
            if (xFlip)
            {
                gOamData[slot * 4 + 0].all.affineParam = FixedMultiplication(cos(rotation), FixedInverse(-scaling));
                gOamData[slot * 4 + 1].all.affineParam = FixedMultiplication(sin(rotation), FixedInverse(-scaling));
            }
            else
            {
                gOamData[slot * 4 + 0].all.affineParam = FixedMultiplication(cos(rotation), FixedInverse(scaling));
                gOamData[slot * 4 + 1].all.affineParam = FixedMultiplication(sin(rotation), FixedInverse(scaling));
            }
            
            gOamData[slot * 4 + 2].all.affineParam = FixedMultiplication(-sin(rotation), FixedInverse(scaling));
            gOamData[slot * 4 + 3].all.affineParam = FixedMultiplication(cos(rotation), FixedInverse(scaling));
        }
    }
    else
    {
        rotation = pSprite->rotation;
        scaling = pSprite->scaling;

        mosaic = pSprite->status & SPRITE_STATUS_MOSAIC;

        yPosition += BLOCK_SIZE;
        xPosition += BLOCK_SIZE;

        for (i = 0; i < partCount; i++)
        {
            // Raw copy
            part1 = *src++;
            *dst++ = part1;
            part2 = *src++;
            *dst++ = part2;
            *dst++ = *src++;

            // Apply graphics
            gOamData[prevSlot + i].split.priority = bgPriority;
            // Add palette row and gfx offset
            gOamData[prevSlot + i].split.paletteNum += paletteRow;
            gOamData[prevSlot + i].split.tileNum += gfxOffset;

            // Don't really know what maths are used here, but it seems to be directly applying rotation and scaling to the position
            shape = gOamData[prevSlot + i].split.shape;
            size = gOamData[prevSlot + i].split.size;
        
            yOffset = sOamYFlipOffsets[shape][size];
            yOffset = PIXEL_TO_SUB_PIXEL(yOffset);
            xOffset = sOamXFlipOffsets[shape][size];
            xOffset = PIXEL_TO_SUB_PIXEL(xOffset);

            // Get current positions
            y = (s16)MOD_AND(part1 + yPosition, 256);
            x = (s16)MOD_AND(part2 + xPosition, 512);
        
            tmpY = (s16)(y - yPosition + yOffset);
            tmpX = (s16)(x - xPosition + xOffset);

            // Apply scaling
            tmpX = (s16)(Q_8_8_TO_SHORT_DIV(tmpX * scaling) - tmpX);
            tmpY = (s16)(Q_8_8_TO_SHORT_DIV(tmpY * scaling) - tmpY);
        
            x = (s16)(x + tmpX);
            y = (s16)(y + tmpY);
        
            // Offset to 0;0 temporarly to apply the rotation
            unk_2 = (s16)(x - xPosition + xOffset);
            unk_3 = (s16)(y - yPosition + yOffset);
        
            // Rotation matrix
            x = Q_8_8_TO_SHORT(unk_2 * cos(rotation) - unk_3 * sin(rotation));
            y = Q_8_8_TO_SHORT(unk_2 * sin(rotation) + unk_3 * cos(rotation));
        
            if (doubleSize)
            {
                x = (s16)(x - xOffset * 2);
                y = (s16)(y - yOffset * 2);
            }
            else
            {
                x = (s16)(x - xOffset);
                y = (s16)(y - yOffset);
            }
        
            // Rotated position + position
            gOamData[prevSlot + i].split.y = MOD_AND(y + yPosition - BLOCK_SIZE, 256);
            gOamData[prevSlot + i].split.x = MOD_AND(x + xPosition - BLOCK_SIZE, 512);

            if (doubleSize)
            {
                // Rotation scaling and double size
                gOamData[prevSlot + i].split.affineMode = 3;
            }
            else
            {
                // Rotation scaling
                gOamData[prevSlot + i].split.affineMode = 1;
            }

            // Select proper matrix depending on mosaic and flipping?
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
            {
                // Semi transparent
                gOamData[prevSlot + i].split.objMode = OAM_OBJ_MODE_SEMI_TRANSPARENT;
            }

            dst++;
        }
        
        // Update next oam slot
        gNextOamSlot = partCount + prevSlot;

        // Setup matrices for normal and x flip
        
        // [ cos / scaling, -sin / scaling ]
        // [ sin / scaling,  cos / scaling ]
        // and
        // [ cos / -scaling, -sin / scaling ]
        // [ sin / -scaling,  cos / scaling ]
        dy = FixedMultiplication(-sin(rotation), FixedInverse(scaling));
        dmy = FixedMultiplication(cos(rotation), FixedInverse(scaling));

        if (mosaic)
        {
            gOamData[28 * 4 + 0].all.affineParam = FixedMultiplication(cos(rotation), FixedInverse(scaling));
            gOamData[28 * 4 + 1].all.affineParam = FixedMultiplication(sin(rotation), FixedInverse(scaling));
            gOamData[28 * 4 + 2].all.affineParam = dy;
            gOamData[28 * 4 + 3].all.affineParam = dmy;

            gOamData[29 * 4 + 0].all.affineParam = FixedMultiplication(cos(rotation), FixedInverse(-scaling));
            gOamData[29 * 4 + 1].all.affineParam = FixedMultiplication(sin(rotation), FixedInverse(-scaling));
            gOamData[29 * 4 + 2].all.affineParam = dy;
            gOamData[29 * 4 + 3].all.affineParam = dmy;
        }
        else
        {
            gOamData[30 * 4 + 0].all.affineParam = FixedMultiplication(cos(rotation), FixedInverse(scaling));
            gOamData[30 * 4 + 1].all.affineParam = FixedMultiplication(sin(rotation), FixedInverse(scaling));
            gOamData[30 * 4 + 2].all.affineParam = dy;
            gOamData[30 * 4 + 3].all.affineParam = dmy;

            gOamData[31 * 4 + 0].all.affineParam = FixedMultiplication(cos(rotation), FixedInverse(-scaling));
            gOamData[31 * 4 + 1].all.affineParam = FixedMultiplication(sin(rotation), FixedInverse(-scaling));
            gOamData[31 * 4 + 2].all.affineParam = dy;
            gOamData[31 * 4 + 3].all.affineParam = dmy;
        }
    }
}

/**
 * @brief ddd4 | 150 | Checks if a sprite is on screen
 * 
 * @param pSprite Sprite data pointer
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

    // Don't bother checking if the sprite has an absolute position
    if (pSprite->properties & SP_ABSOLUTE_POSITION)
        return;

    bgBaseY = gBg1YPosition;
    bgBaseX = gBg1XPosition;

    spriteY = pSprite->yPosition;
    spriteX = pSprite->xPosition;

    bgYRange = bgBaseY + BLOCK_TO_SUB_PIXEL(CEIL(SCREEN_SIZE_X_BLOCKS / 2));
    spriteYRange = spriteY + BLOCK_TO_SUB_PIXEL(CEIL(SCREEN_SIZE_X_BLOCKS / 2));
    spriteBottom = bgYRange - PIXEL_TO_SUB_PIXEL(pSprite->drawDistanceBottom);
    drawOffset = PIXEL_TO_SUB_PIXEL(pSprite->drawDistanceTop) + SCREEN_SIZE_Y_SUB_PIXEL;
    spriteTop = bgYRange + drawOffset;

    bgXRange = bgBaseX + BLOCK_TO_SUB_PIXEL(CEIL(SCREEN_SIZE_X_BLOCKS / 2));
    spriteXRange = spriteX + BLOCK_TO_SUB_PIXEL(CEIL(SCREEN_SIZE_X_BLOCKS / 2));
    spriteLeft = bgXRange - PIXEL_TO_SUB_PIXEL(pSprite->drawDistanceHorizontal);
    drawOffset = PIXEL_TO_SUB_PIXEL(pSprite->drawDistanceHorizontal) + SCREEN_SIZE_X_SUB_PIXEL;
    spriteRight = bgXRange + drawOffset;

    if (spriteLeft < spriteXRange && spriteXRange < spriteRight && spriteBottom < spriteYRange && spriteYRange < spriteTop)
    {
        pSprite->status |= SPRITE_STATUS_ONSCREEN;
        return;
    }

    pSprite->status &= ~SPRITE_STATUS_ONSCREEN;

    if (pSprite->properties & SP_KILL_OFF_SCREEN)
    {
        // todo: screen size
        bgYRange = bgBaseY + BLOCK_SIZE * 10;
        spriteYRange = spriteY + BLOCK_SIZE * 10;
        spriteBottom = bgYRange - BLOCK_SIZE * 9;
        spriteTop = bgYRange + BLOCK_SIZE * 19;

        bgXRange = bgBaseX + BLOCK_SIZE * 10;
        spriteXRange = spriteX + BLOCK_SIZE * 10;
        spriteLeft = bgXRange - BLOCK_SIZE * 9;
        spriteRight = bgXRange + BLOCK_SIZE * 24;

        if (spriteLeft >= spriteXRange || spriteXRange >= spriteRight || spriteBottom >= spriteYRange || spriteYRange >= spriteTop)
        {
            // Off range, kill sprite
            pSprite->status = 0;
        }
    }
}

/**
 * @brief df24 | 4c | Calls : ClearSpriteData, LoadSpriteset,
 * CheckReloadEscapeDigitsGraphics, LoadLocationText, LoadRoomSprite
 * and SpawnSpacePiratesWaiting
 * 
 */
void SpriteLoadAllData(void)
{
    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
    {
        // Don't load sprites if psf was active, this indirectly means that the room was already loaded before
        return;
    }

    // Check reset alarm timer
    if (gGameModeSub3 == 0 && !gIsLoadingFile)
        gAlarmTimer = 0;

    // Clear
    SpriteClearData();

    // Load spriteset
    SpriteLoadSpriteset();

    // Setup special sprites
    EscapeCheckReloadGraphics();
    SpriteUtilInitLocationText();

    // Load current room sprites
    SpriteLoadRoomSprites();
    SpawnWaitingPirates();

    gParasiteRelated = 0;
}

/**
 * @brief df84 | 100 | Loads a spriteset
 * 
 */
void SpriteLoadSpriteset(void)
{
    s32 i;
    s32 j;
    s32 spriteset;
    u32 spriteId;
    u32 gfxSlot;
    u32 prevGfxSlot;
    u16 nbrRows;

    s32 ctrl_1;
    s32 ctrl_2;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITE_TYPES; i++)
    {
        gSpritesetSpritesID[i] = PSPRITE_UNUSED16;
        gSpritesetGfxSlots[i] = 0;
    }

    prevGfxSlot = UCHAR_MAX;
    spriteset = gSpriteset;
    if (spriteset >= MAX_AMOUNT_OF_SPRITESET - 1)
    {
        if (gCurrentArea > AREA_DEBUG_1)
            spriteset = MAX_AMOUNT_OF_SPRITESET - 1;
        else
            spriteset = 0;
    }

    for (j = 0, i = 0; i < MAX_AMOUNT_OF_SPRITE_TYPES; i++)
    {
        const u32 * const *spritesetGraphicsPointers;

        spriteId = sSpritesetPointers[spriteset][j * 2 + 0];
        gfxSlot = sSpritesetPointers[spriteset][j * 2 + 1];

        j++;
        
        if (spriteId == PSPRITE_UNUSED0)
        {
            break;
            EMPTY_DO_WHILE // Needed to produce matching ASM.
        }

        gSpritesetSpritesID[i] = spriteId;
        gSpritesetGfxSlots[i] = MOD_AND(gfxSlot, 8);

        if (gfxSlot == prevGfxSlot)
            continue;

        prevGfxSlot = gfxSlot;
        if (gfxSlot == 8)
            continue;

        spriteId = PSPRITE_OFFSET_FOR_GRAPHICS(spriteId);

        spritesetGraphicsPointers = sSpritesGraphicsPointers; // Needed to produce matching ASM.
        LZ77UncompVRAM(spritesetGraphicsPointers[spriteId], VRAM_BASE + 0x14000 + gfxSlot * 2048);

        ctrl_1 = ((u8*)sSpritesGraphicsPointers[spriteId])[1];
        ctrl_2 = ((u8*)sSpritesGraphicsPointers[spriteId])[2] << 8;
        DMA_SET(3, sSpritesPalettePointers[spriteId], PALRAM_OBJ + 8 * PAL_ROW_SIZE + gfxSlot * 32, C_32_2_16(DMA_ENABLE, (ctrl_1 | ctrl_2) / 2048 << 4));
    }
}

/**
 * e084 | 2c | Loads the graphics in VRAM for a new sprite
 * 
 * @param spriteId Sprite ID
 * @param row Spriteset Graphics Row
 */
void SpriteLoadGfx(u8 spriteId, u8 row)
{
    spriteId = PSPRITE_OFFSET_FOR_GRAPHICS(spriteId);

    LZ77UncompVRAM(sSpritesGraphicsPointers[spriteId], VRAM_BASE + 0x14000 + (row * 0x800));
}

/**
 * e0b0 | 40 | Loads the palette in PALRAM for a new sprite
 * 
 * @param spriteId Sprite ID
 * @param row Palette Row
 * @param len Lenght (in rows)
 */
void SpriteLoadPal(u8 spriteId, u8 row, u8 len)
{
    spriteId = PSPRITE_OFFSET_FOR_GRAPHICS(spriteId);

    DMA_SET(3, sSpritesPalettePointers[spriteId], PALRAM_OBJ + 8 * PAL_ROW_SIZE + (row * 16 * sizeof(u16)), C_32_2_16(DMA_ENABLE, len * 16));
}

/**
 * @brief e0f0 | 44 | Clears the sprite data (including debris)
 * 
 */
void SpriteClearData(void)
{
    s32 i;

    // Clear sprites
    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        gSpriteData[i].status = 0;
        gSpriteData[i].standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;
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
        y = gCurrentRoomEntry.pEnemyRoomData[i * ENEMY_ROOM_DATA_SIZE + 0];

        // Terminator
        if (y == UCHAR_MAX)
            break;

        x = gCurrentRoomEntry.pEnemyRoomData[i * ENEMY_ROOM_DATA_SIZE + 1];
        slot = gCurrentRoomEntry.pEnemyRoomData[i * ENEMY_ROOM_DATA_SIZE + 2];
        SpriteInitPrimary(slot, y, x, i);
    }
}

/**
 * @brief e17c | dc | Initializes a primary sprite with the values in parameters
 * 
 * @param spritesetSlot Spriteset slot/properties
 * @param yPosition Y Position (blocks)
 * @param xPosition X Position (blocks)
 * @param roomSlot Room Slot
 */
void SpriteInitPrimary(u8 spritesetSlot, u16 yPosition, u16 xPosition, u8 roomSlot)
{
    u8 ramSlot;
    struct SpriteData* pSprite;

    // Try to find an empty slot
    for (ramSlot = 0, pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; ramSlot++, pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS)
            continue;

        // Found empty slot, mark exists
        pSprite->status = SPRITE_STATUS_EXISTS;

        // Get 7 first bits of the spriteset slot
        spritesetSlot = MOD_AND(spritesetSlot, 128);

        // A spriteset slot value that's above MAX_AMOUNT_OF_SPRITE_TYPES + 1 means the spriteset should be used
        if (spritesetSlot > MAX_AMOUNT_OF_SPRITE_TYPES + 1)
        {
            spritesetSlot--;

            // Modulo to not overflow the next array access
            spritesetSlot = MOD_AND(spritesetSlot, MAX_AMOUNT_OF_SPRITE_TYPES + 1);

            // Fetch the gfx slot and the sprite id
            pSprite->spritesetGfxSlot = gSpritesetGfxSlots[spritesetSlot];
            pSprite->spriteId = gSpritesetSpritesID[spritesetSlot];
        }
        else
        {
            // Don't use the spriteset, directly write to sprite id and use first gfx slot
            pSprite->spritesetGfxSlot = 0;
            pSprite->spriteId = spritesetSlot - 1;
        }

        pSprite->properties = 0;

        // Convert block position to sub pixel such that the new position is in the bottom middle of the block in sub pixels
        pSprite->yPosition = BLOCK_TO_SUB_PIXEL(yPosition) + BLOCK_SIZE;
        pSprite->xPosition = BLOCK_TO_SUB_PIXEL(xPosition) + HALF_BLOCK_SIZE;
        pSprite->roomSlot = roomSlot;

        pSprite->bgPriority = 2;
        pSprite->drawOrder = 4;
        pSprite->pose = SPRITE_POSE_UNINITIALIZED;
        pSprite->health = 0;
        pSprite->invincibilityStunFlashTimer = 0;

        pSprite->paletteRow = 0;
        pSprite->frozenPaletteRowOffset = 0;
        pSprite->absolutePaletteRow = 0;

        pSprite->ignoreSamusCollisionTimer = DELTA_TIME;
        pSprite->primarySpriteRamSlot = ramSlot;
        pSprite->freezeTimer = 0;
        pSprite->standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;
        break;
    }
}

/**
 * e258 | c4 | Spawns a new secondary sprite with the given parameters
 * 
 * @param spriteId The ID of the sprite to spawn
 * @param partNumber Part number
 * @param gfxSlot The sprite graphics slot (usually the same as the primary sprite)
 * @param ramSlot The RAM slot of the secondary sprite's parent
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param statusToAdd Additionnal status flags (default are Exists, On Screen and Not Drawn)
 * @return The assigned RAM slot of the spawned sprite, 0xFF is the sprite couldn't spawn
 */
u8 SpriteSpawnSecondary(u8 spriteId, u8 partNumber, u8 gfxSlot, u8 ramSlot, u16 yPosition, u16 xPosition, u16 statusToAdd)
{
    u8 newSlot;
    struct SpriteData* pSprite;

    // Try to find an empty slot
    for (newSlot = 0, pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; newSlot++, pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS)
            continue;

        pSprite->status = statusToAdd | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
        pSprite->properties = SP_SECONDARY_SPRITE;

        pSprite->spritesetGfxSlot = gfxSlot;
        pSprite->spriteId = spriteId;
        pSprite->yPosition = yPosition;
        pSprite->xPosition = xPosition;
        pSprite->roomSlot = partNumber;

        pSprite->bgPriority = 2;
        pSprite->drawOrder = 4;

        pSprite->pose = SPRITE_POSE_UNINITIALIZED;
        pSprite->health = 0;
        pSprite->invincibilityStunFlashTimer = 0;

        pSprite->paletteRow = 0;
        pSprite->frozenPaletteRowOffset = 0;
        pSprite->absolutePaletteRow = 0;

        pSprite->ignoreSamusCollisionTimer = 1 * DELTA_TIME;

        pSprite->primarySpriteRamSlot = ramSlot;

        pSprite->freezeTimer = 0;
        pSprite->standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;

        return newSlot;
    }

    return UCHAR_MAX;
}

/**
 * e31c | b8 | Spawns a new primary sprite with the given parameters
 * 
 * @param spriteId The ID of the sprite to spawn
 * @param partNumber Part number
 * @param gfxSlot The sprite graphics slot
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param statusToAdd Additionnal status flags (default are Exists, On Screen and Not Drawn)
 * @return The assigned RAM slot of the spawned sprite, 0xFF if the sprite couldn't spawn
 */
u8 SpriteSpawnPrimary(u8 spriteId, u8 partNumber, u8 gfxSlot, u16 yPosition, u16 xPosition, u16 statusToAdd)
{
    u8 newSlot;
    struct SpriteData* pSprite;

    // Try to find an empty slot
    for (newSlot = 0, pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; newSlot++, pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS)
            continue;

        pSprite->status = statusToAdd | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
        pSprite->properties = 0;

        pSprite->spritesetGfxSlot = gfxSlot;
        pSprite->spriteId = spriteId;
        pSprite->yPosition = yPosition;
        pSprite->xPosition = xPosition;
        pSprite->roomSlot = partNumber;

        pSprite->bgPriority = 2;
        pSprite->drawOrder = 4;

        pSprite->pose = SPRITE_POSE_UNINITIALIZED;
        pSprite->health = 0;
        pSprite->invincibilityStunFlashTimer = 0;

        pSprite->paletteRow = 0;
        pSprite->frozenPaletteRowOffset = 0;
        pSprite->absolutePaletteRow = 0;

        pSprite->ignoreSamusCollisionTimer = DELTA_TIME;

        pSprite->primarySpriteRamSlot = newSlot;

        pSprite->freezeTimer = 0;
        pSprite->standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;

        return newSlot;
    }

    return UCHAR_MAX;
}

/**
 * e3d4 | b8 | Spawns a new primary sprite with the given parameters (used only for the drops and the followers sprite)
 * 
 * @param spriteId The ID of the sprite to spawn
 * @param partNumber The room slot
 * @param gfxSlot The sprite graphics slot
 * @param ramSlot The RAM slot of the sprite's parent
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param statusToAdd Additionnal status flags (default are Exists, On Screen and Not Drawn)
 * @return The assigned RAM slot of the spawned sprite, 0xFF is the sprite couldn't spawn
 */
u8 SpriteSpawnDropFollowers(u8 spriteId, u8 partNumber, u8 gfxSlot, u8 ramSlot, u16 yPosition, u16 xPosition, u16 statusToAdd)
{
    u8 newSlot;
    struct SpriteData* pSprite;

    // Try to find an empty slot
    for (newSlot = 0, pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; newSlot++, pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS)
            continue;

        pSprite->status = statusToAdd | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
        pSprite->properties = 0;

        pSprite->spritesetGfxSlot = gfxSlot;
        pSprite->spriteId = spriteId;
        pSprite->yPosition = yPosition;
        pSprite->xPosition = xPosition;
        pSprite->roomSlot = partNumber;

        pSprite->bgPriority = 2;
        pSprite->drawOrder = 4;

        pSprite->pose = SPRITE_POSE_UNINITIALIZED;
        pSprite->health = 0;
        pSprite->invincibilityStunFlashTimer = 0;

        pSprite->paletteRow = 0;
        pSprite->frozenPaletteRowOffset = 0;
        pSprite->absolutePaletteRow = 0;

        pSprite->ignoreSamusCollisionTimer = DELTA_TIME;

        pSprite->primarySpriteRamSlot = ramSlot;

        pSprite->freezeTimer = 0;
        pSprite->standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;

        return newSlot;
    }

    return UCHAR_MAX;
}
