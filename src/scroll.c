#include "scroll.h"
#include "gba.h"

#include "data/clipdata_data.h"
#include "data/engine_pointers.h"

#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/room.h"

#include "structs/bg_clip.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/color_effects.h"
#include "structs/samus.h"
#include "structs/room.h"

/**
 * @brief 582c4 | 64 | Processes the current scrolls
 * 
 * @param pCoords Coordinates pointer
 */
void ScrollProcess(struct RawCoordsX* pCoords)
{
    u32 screenX;
    u32 screenY;
    u32 newPosition;
    struct Scroll* pScroll;

    ScrollUpdateCurrent(pCoords);
    screenX = gCamera.xPosition;
    screenY = gCamera.yPosition;

    pScroll = gCurrentScrolls;
    if (pScroll->within)
    {
        screenX = ScrollProcessX(pScroll, pCoords);
        screenY = ScrollProcessY(pScroll, pCoords);
    }

    pScroll = gCurrentScrolls + 1;
    if (pScroll->within)
    {
        newPosition = ScrollProcessX(pScroll, pCoords);
        screenX = (i32)(screenX + newPosition) >> 0x1;
        newPosition = ScrollProcessY(pScroll, pCoords);
        screenY = (i32)(screenY + newPosition) >> 0x1;
    }

    ScrollScreen(screenX, screenY);
}

/**
 * @brief 58328 | bc | Scrolls the screen to the provided position
 * 
 * @param screenX Screen Y
 * @param screenY Screen X
 */
void ScrollScreen(u16 screenX, u16 screenY)
{
    i32 velocity;

    gCamera.xPosition = screenX;
    gCamera.yPosition = screenY;

    if (gGameModeSub1 == 0)
        return;
    
    if (screenY != gBG1YPosition)
    {
        velocity = screenY - gBG1YPosition;

        if (velocity > 0)
        {
            if (gUnk_3005714.unk6 < velocity)
                velocity = gUnk_3005714.unk6;
        }
        else
        {
            if (gUnk_3005714.unk4 > velocity)
                velocity = gUnk_3005714.unk4;
        }

        gCamera.yVelocity = velocity;
        gBG1YPosition += velocity;
    }
    else
        gCamera.yVelocity = 0;
    
    if (screenX != gBG1XPosition)
    {
        velocity = screenX - gBG1XPosition;

        if (velocity > 0)
        {
            if (gUnk_3005714.unk2 < velocity)
                velocity = gUnk_3005714.unk2;
        }
        else
        {
            if (gUnk_3005714.unk0 > velocity)
                velocity = gUnk_3005714.unk0;
        }

        gCamera.xVelocity = velocity;
        gBG1XPosition += velocity;
    }
    else
        gCamera.xVelocity = 0;
}

i32 ScrollProcessX(struct Scroll* pScroll, struct RawCoordsX* pCoords)
{
    i32 xPosition;
    i32 xStart;

    xPosition = pCoords->x;
    xStart = pScroll->xStart;

    if (xStart + 0x1E0 <= xPosition)
        return xStart;
    else if (xPosition <= pScroll->xEnd - 0x1E0)
        return xPosition - 0x1E0;
    else
        return pScroll->xEnd - 0x3C0;
}

i32 ScrollProcessY(struct Scroll* pScroll, struct RawCoordsX* pCoords)
{
    i32 yPosition;
    i32 yStart;

    if (pScroll->within == 0x2)
    {
        yPosition = pCoords->y;
        yStart = pScroll->yStart;

        if (yPosition >= yStart + 0x180)
        {
            if (yPosition > pScroll->yEnd - 0x100)
            {
                if (pScroll->yEnd - 0x280 < yStart)
                    return yStart;
                return pScroll->yEnd - 0x280;
            }
            else
                return yPosition - 0x180;
        }
        else
            return yStart;
    }
    else
        return pScroll->yEnd - 0x280;
}

/**
 * @brief 58478 | 60 | Loads the scrolls for the current room
 * 
 */
void ScrollLoad(void)
{
    u8** ppSrc;

    // ppSrc = sAreaScrollPointers[gCurrentArea];

    // Loop through every scroll of the area
    for (; ; ppSrc++)
    {
        if (**ppSrc == gCurrentRoom)
        {
            // Found room, set pointer and flag
            gCurrentRoomScrollDataPointer = *ppSrc;
            gCurrentRoomEntry.scrollsFlag = ROOM_SCROLLS_FLAG_HAS_SCROLLS;
            break;
        }
        else if (**ppSrc == UCHAR_MAX)
        {
            // Reached terminator
            gCurrentRoomScrollDataPointer = *ppSrc;
            break;
        }
    }
}

void ScrollUpdateCurrent(struct RawCoordsX* pCoords)
{
    struct Scroll* pScroll;
    u16 xPosition;
    u16 yPosition;
    u32 scrollID;
    u8* pData;
    i32 bounds[4];
    i32 bound;
    i32 limit;
    u8 direction;
    i32 i;

    i = 0;
    pScroll = gCurrentScrolls;
    gCurrentScrolls[0].within = FALSE;
    gCurrentScrolls[1].within = FALSE;

    xPosition = pCoords->x;
    xPosition /= BLOCK_SIZE;
    yPosition = pCoords->y - 1;
    yPosition /= BLOCK_SIZE;

    pData = gCurrentRoomScrollDataPointer;
    pData++;
    scrollID = *pData++;

    for (; scrollID != 0x0; scrollID--)
    {
        // cond
        
        bounds[0] = 0x0;
        bounds[1] = 0x1;
        bounds[2] = 0x2;
        bounds[3] = 0x3;

        if (pData[4] != 0xFF && pData[7] != 0xFF)
        {
            if (gBGPointersAndDimensions.pClipDecomp[pData[5] * gBGPointersAndDimensions.clipdataWidth + pData[4]] == 0x0 && pData[6] != 0xFF)
                bounds[pData[6]] = 0x7;
        }
        else
        {
            if (gSamusData.pose == SPOSE_USING_AN_ELEVATOR && pData[7] != 0xFF && (u8)(pData[6] - 0x2) < 0x2)
                bounds[pData[6]] = 0x7;
        }

        if (pData[bounds[0]] <= xPosition && xPosition <= pData[bounds[1]] && pData[bounds[2]] <= yPosition && yPosition <= pData[bounds[3]] && !pScroll->within)
        {
            limit = BLOCK_SIZE * 2;
            bound = pData[bounds[0]] * BLOCK_SIZE;
            if (bound < limit)
                bound = limit;
            pScroll[i].xStart = bound;

            limit = gBGPointersAndDimensions.clipdataWidth * BLOCK_SIZE - (BLOCK_SIZE * 2);
            bound = (pData[bounds[1]] + 1) * BLOCK_SIZE;

            if (bound < limit)
                bound = limit;
            pScroll[i].xEnd = bound;

            limit = BLOCK_SIZE * 2;
            bound = pData[bounds[2]] * BLOCK_SIZE;
            if (bound < limit)
                bound = limit;
            pScroll[i].yStart = bound;

            limit = gBGPointersAndDimensions.clipdataHeight * BLOCK_SIZE - (BLOCK_SIZE * 2);
            bound = (pData[bounds[3]] + 1) * BLOCK_SIZE;

            if (bound < limit)
                bound = limit;
            pScroll[i].yEnd = bound;

            pScroll[i].within = 0x2;
            
            i++;
        }

        pData += 0x8;
    }

    if (!gCurrentScrolls[0].within && !gCurrentScrolls[1].within)
    {
        gCurrentScrolls[0].within = FALSE;
        gCurrentScrolls[0].xEnd = 0x0;
        gCurrentScrolls[0].xStart = 0x0;
        gCurrentScrolls[0].yStart = 0x0;
        gCurrentScrolls[0].yEnd = 0x0;
    }
}

/**
 * @brief 58640 | 1f4 | Processes the general scrolling
 * 
 */
void ScrollProcessGeneral(void)
{
    struct RawCoordsX coords;
    i32 distance;

    u32 x;
    u32 y;

    if (gColorFading.stage != 0)
        return;

    if (gLockScreen.lock == FALSE)
    {
        coords.x = gSamusData.xPosition;
        coords.y = gSamusData.yPosition + 1;

        if (gSamusData.pose == SPOSE_HANGING_ON_LEDGE || gSamusData.pose == SPOSE_GRABBING_A_LEDGE_SUITLESS)
            gSlowScrollingTimer = 1;
        else if (gSamusData.pose == SPOSE_PULLING_YOURSELF_UP_FROM_HANGING || gSamusData.pose == SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING)
            gSlowScrollingTimer = 8;
        else if (gSamusData.pose == SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL)
            gSlowScrollingTimer = 20;
        else if (gSlowScrollingTimer != 0)
            gSlowScrollingTimer--;
    }
    else if (gLockScreen.lock == TRUE)
    {
        coords.x = gLockScreen.xPositionCenter;
        coords.y = gLockScreen.yPositionCenter;
    }
    else
    {
        x = gSamusData.xPosition + gLockScreen.xPositionCenter;
        y = gSamusData.yPosition + 1 + gLockScreen.yPositionCenter;

        coords.x = x / 2;
        coords.y = y / 2;
    }

    if (coords.y & 0x8000)
        coords.y = 0;

    gUnk_3005714 = sUnk_8345988[0];

    if (!gLockScreen.lock)
    {
        if (gSlowScrollingTimer == 0)
        {
            distance = gSamusData.xPosition - gPreviousXPosition;

            if (distance > 0)
            {
                if (distance >= gUnk_3005714.unk2)
                    gUnk_3005714.unk2 = distance + 4;
            }
            else if (distance < 0 && distance <= gUnk_3005714.unk0)
                gUnk_3005714.unk0 = distance - 4;

            distance = gSamusData.yPosition - gPreviousYPosition;

            if (distance > 0)
            {
                if (distance >= gUnk_3005714.unk6)
                    gUnk_3005714.unk6 = distance + 4;
            }
            else if (distance < 0 && distance <= gUnk_3005714.unk4)
                gUnk_3005714.unk4 = distance - 4;

        }
        else
            gUnk_3005714 = sUnk_8345988[1];
    }

    if (!gDisableScrolling)
    {
        if (gUnk_300007f != 0 && gGameModeSub1 == 6)
            ScrollMaybeScrollBG1Related(&coords);
        else if (gCurrentRoomEntry.scrollsFlag == ROOM_SCROLLS_FLAG_HAS_SCROLLS)
            ScrollProcess(&coords);
        else
            ScrollWithNoScrolls(&coords);

        ScrollBG2(&coords);

        if (gBG0Movement.type != 0 && gCurrentRoomEntry.BG0Prop & BG_PROP_LZ77_COMPRESSED)
            ScrollAutoBG0();

        ScrollUpdateEffectAndHazePosition(&coords);
        ScrollBG3();
        if (gBG3Movement.direction != 0)
            ScrollAutoBG3();
    }
}

void ScrollWithNoScrolls(struct RawCoordsX* pCoords)
{
    ScrollWithNoScrollsX(pCoords);
    ScrollWithNoScrollsY(pCoords);
}

void ScrollWithNoScrollsY(struct RawCoordsX* pCoords)
{

}

void ScrollWithNoScrollsX(struct RawCoordsX* pCoords)
{
    // https://decomp.me/scratch/yaHOg

    i32 xOffset;
    u16 xPosition;
    i32 clipPosition;

    xOffset = 0x0;
    if (!gLockScreen.lock && gSamusPhysics.standingStatus == STANDING_NOT_IN_CONTROL)
    {
        if (gSamusData.direction & KEY_RIGHT)
            xOffset = BLOCK_SIZE * 2;
        else if (gSamusData.direction & KEY_LEFT)
            xOffset = -(BLOCK_SIZE * 2);
    }

    gScreenXOffset = xOffset;

    xPosition = pCoords->x;
    if (xPosition < 0x260 - gScreenXOffset)
        xOffset = BLOCK_SIZE * 2;
    else
    {
        clipPosition = (0x260 + gBGPointersAndDimensions.backgrounds[1].width * BLOCK_SIZE) - gScreenXOffset;
        if (xPosition > clipPosition)        
            xOffset = gScreenXOffset + (clipPosition - 0x1E0);
        else
            xOffset = gScreenXOffset + (clipPosition - 0x1E0);
    }

    gCamera.xPosition = xOffset;

    xOffset -= gBG1XPosition;
    if (xOffset > 0x0)
    {
        if (gUnk_3005714.unk2 < xOffset)
            xOffset = gUnk_3005714.unk2;
    }
    else
    {
        if (xOffset < gUnk_3005714.unk0)
            xOffset = gUnk_3005714.unk0;
    }

    gCamera.xVelocity = xOffset;
    gBG1XPosition += xOffset;
}

/**
 * @brief 58a18 | 2a8 | Updates the haze and effect position
 * 
 * @param pCoords Coordinates pointer
 */
void ScrollUpdateEffectAndHazePosition(struct RawCoordsX* pCoords)
{
    u32 var_0;
    i32 position;
    i32 waterOffset;
    u16 temp;
    
    var_0 = FALSE;
    if (gCurrentRoomEntry.BG0Prop & BG_PROP_RLE_COMPRESSED)
    {
        if (gCurrentRoomEntry.BG0Prop == 0x11)
        {
            gBG0XPosition = gBG1XPosition / 2;
            gBG0YPosition = gBG1YPosition;
            
            var_0 = TRUE;
        }
    }
    else
    {
        if (gCurrentRoomEntry.effectY != USHORT_MAX)
        {
            gBG0XPosition = gBG1XPosition;
            position = (gCurrentRoomEntry.effectY + gEffectYPositionOffset - gBG1YPosition) >> 2;

            if (gWaterMovement.moving == TRUE)
            {
                if (gPreventMovementTimer == 0)
                {
                    if (gWaterMovement.loopCounter != 0)
                        gWaterMovement.loopCounter--;
                    else
                    {
                        gWaterMovement.stage++;
                        if (gWaterMovement.stage > 7)
                            gWaterMovement.stage = 0;

                        gWaterMovement.loopCounter = sWaterLoopCounterArray[gWaterMovement.stage][1];
                    }
                }
                waterOffset = sWaterLoopCounterArray[gWaterMovement.stage][0];
            }
            else
                waterOffset = 0;

            gWaterMovement.yOffset = (waterOffset - 8) * 4;
            position += waterOffset;

            if (position < 0)
            {
                if (gIoRegistersBackup.unk_12 & 0xC000 && gIoRegistersBackup.BG0CNT & 0xC000)
                {
                    gIoRegistersBackup.unk_12 &= ~0xC000;
                    write16(REG_BG0CNT, gIoRegistersBackup.unk_12);
                }
            }
            else
            {
                if (!(gIoRegistersBackup.unk_12 & 0xC000) && gIoRegistersBackup.BG0CNT & 0xC000)
                {
                    gIoRegistersBackup.unk_12 |= (gIoRegistersBackup.BG0CNT & 0xC000);
                    write16(REG_BG0CNT, read16(REG_BG0CNT) | gIoRegistersBackup.unk_12);
                }
            }

            if (position > BLOCK_SIZE * 4)
                position = BLOCK_SIZE * 4;

            gBG0YPosition = -position * 4;
            var_0 = TRUE;
        }
        else
        {
            var_0 = TRUE;
            switch (gCurrentRoomEntry.BG0Prop)
            {
                case BG_PROP_CLOSE_UP:
                    gBG0XPosition = 0;
                    gBG0YPosition = 0;
                    break;

                case 0x43:
                case BG_PROP_DARK_ROOM:
                    gBG0XPosition = gBG1XPosition - pCoords->x;
                    gBG0YPosition = gBG1YPosition - pCoords->y + BLOCK_SIZE;
                    break;

                case 0x44:
                    position = FALSE;

                    gBG0XPosition = (gBG1XPosition - gWaitingSpacePiratesPosition.x) + BLOCK_SIZE * 32;
                    gBG0YPosition = (gBG1YPosition - gWaitingSpacePiratesPosition.y) + BLOCK_SIZE * 17;

                    temp = (gBG1XPosition - gWaitingSpacePiratesPosition.x) + BLOCK_SIZE * 20;
                    if (temp > BLOCK_SIZE * 24)
                        position = TRUE;

                    temp = (gBG1YPosition - gWaitingSpacePiratesPosition.y) + BLOCK_SIZE * 13;
                    if (temp > BLOCK_SIZE * 12)
                        position = TRUE;

                    if (position)
                    {
                        gBG0XPosition = BLOCK_SIZE * 8;
                    }
                    break;

                default:
                    var_0 = FALSE;
            }
        }
    }

    if (!var_0)
    {
        gBG0YPosition = gBG1YPosition;
        gBG0XPosition = gBG1XPosition;
    }

    if (gCurrentRoomEntry.effectY == USHORT_MAX)
    {
        gEffectYPosition = 0;
        gEffectYPositionOffset = 0;
    }
    else
    {
        position = gCurrentRoomEntry.effectY + gWaterMovement.yOffset + gEffectYPositionOffset;

        if (position < 0)
            position = 0;

        gEffectYPosition = position;
    }
}

/**
 * @brief 58cc0 | 60 | Handles the automatic scrolling of the background 0
 * 
 */
void ScrollAutoBG0(void)
{
    if (gBG0Movement.type == BG0_MOVEMENT_WATER_CLOUDS)
    {
        if (!(gBG0Movement.yOffset & 7))
            gBG0Movement.xOffset++;
    }
    else if (gBG0Movement.type == 2)
    {
        if (!(gBG0Movement.yOffset & 3))
            gBG0Movement.xOffset++;
    }
    else if (gBG0Movement.type == 3)
    {
        if (!(gBG0Movement.yOffset & 7))
            gBG0Movement.snowflakesRelated++;
    }
    else if (gBG0Movement.type == BG0_MOVEMENT_SNOWFLAKES)
    {
        if (!(gBG0Movement.yOffset & 7))
            gBG0Movement.snowflakesRelated--;
    }

    gBG0Movement.yOffset++;
}

u32 ScrollGetBG3Scroll(void)
{
    u32 xScroll;
    u32 yScroll;

    yScroll = 0;
    xScroll = 0;

    switch (gCurrentRoomEntry.BG3Scrolling)
    {
        case 0:
            break;

        case 1:
            xScroll = 2;
            yScroll = 0;
            break;

        case 2:
            xScroll = 0;
            yScroll = 2;
            break;

        case 3:
            xScroll = 2;
            yScroll = 2;
            break;

        case 4:
            xScroll = 1;
            yScroll = 2;
            break;

        case 5:
            xScroll = 2;
            yScroll = 1;
            break;

        case 6:
        case 10:
            xScroll = 1;
            yScroll = 1;
            break;
        
        case 9:
            xScroll = 3;
            yScroll = 0;
            break;

        case 7:
            xScroll = 1;
            yScroll = 0;
    }

    return yScroll << 16 | xScroll;
}

/**
 * @brief 58da0 | 124 | Scrolls the background 3
 * 
 */
void ScrollBG3(void)
{
    u32 xScrolling;
    i32 yScrolling;
    i32 offset;
    i32 size;

    yScrolling = ScrollGetBG3Scroll();
    xScrolling = yScrolling & 0xFF;
    yScrolling = yScrolling >> 16;

    if (xScrolling != 0)
    {
        if (xScrolling == 1)
            gBG3XPosition = gBG1XPosition - BLOCK_SIZE * 2;
        else if (xScrolling == 2)
            gBG3XPosition = (gBG1XPosition - BLOCK_SIZE * 2) >> 1;
        else if (xScrolling == 3)
            gBG3XPosition = (gBG1XPosition - BLOCK_SIZE * 2) >> 2;
    }

    if (gCurrentRoomEntry.BG3FromBottomFlag)
    {
        size = (gBGPointersAndDimensions.clipdataHeight - 0xC) * BLOCK_SIZE;

        if (gCurrentRoomEntry.BG3Size & 2)
            offset = 0x800;
        else
            offset = 0x400;

        offset -= 0x280;

        if (yScrolling == 0)
        {
            offset = 0;
            size = 0;
        }
        else if (yScrolling == 1)
            size -= gBG1YPosition;
        else
            size = (size - gBG1YPosition) >> 2;
        
        if (offset - size > 0)
            gBG3YPosition = offset - size;
        else
            gBG3YPosition = 0;
    }
    else
    {
        if (yScrolling == 0)
            gBG3YPosition = 0;
        else if (yScrolling == 1)
            gBG3YPosition = gBG1YPosition - BLOCK_SIZE * 2;
        else if (yScrolling == 2)
            gBG3YPosition = (gBG1YPosition - BLOCK_SIZE * 2) >> 1;
        else
            gBG3YPosition = (gBG1YPosition - BLOCK_SIZE * 2) >> 2;
    }
}

void ScrollBG3Related(void)
{
    u32 xScroll;

    xScroll = ScrollGetBG3Scroll();
    xScroll &= 0xFF;
    if (xScroll == 0x0)
        gBG3XPosition = 0x0;
    else if (xScroll == 0x2)
        gBG3XPosition = (gBG1XPosition - 0x80) >> 0x1;
    else if (xScroll == 0x3)
        gBG3XPosition = (gBG1XPosition - 0x80) >> 0x2;
}

/**
 * @brief 58f14 | 2c | Handles the automatic scrolling of the background 3
 * 
 */
void ScrollAutoBG3(void)
{
    if (gBG3Movement.direction == 0x1)
    {
        if (!(gBG3Movement.counter & 0x7))
            gBG3Movement.xOffset++;
    }

    gBG3Movement.counter++;
}

void ScrollBG2(struct RawCoordsX* pCoords)
{
    // https://decomp.me/scratch/zdm9e

    i32 size;
    i32 position;

    if (gCurrentRoomEntry.BG2Prop & BG_PROP_RLE_COMPRESSED)
    {
        if (gCurrentRoomEntry.BG2Prop & 0x20)
        {
            if (gCurrentRoomEntry.BG2Prop == BG_PROP_MOVING)
            {
                position = gBG1XPosition + gBG2Movement.xOffset;
                if (position < 0)
                    position = 0;
                else
                {
                    size = (gBGPointersAndDimensions.backgrounds[2].width - 0xF) * BLOCK_SIZE;
                    if (size < position)
                        position = size;
                }

                gBG2XPosition = position;

                position = gBG1YPosition + gBG2Movement.yOffset;
                if (position < 0)
                    position = 0;
                else
                {
                    size = (gBGPointersAndDimensions.backgrounds[2].height - 0xA) * BLOCK_SIZE;
                    if (size < position)
                        position = size;
                }

                gBG2YPosition = position;
                return;
            }
        }

        gBG2XPosition = gBG1XPosition;
        gBG2YPosition = gBG1YPosition;
    }
    else
    {
        gBG2XPosition = 0;
        gBG2YPosition = 0;
    }
}

/**
 * @brief 59008 | a8 | To document
 * 
 * @param pCoords Coords pointer
 */
void ScrollMaybeScrollBG1Related(struct RawCoordsX* pCoords)
{
    if (pCoords->x < BLOCK_SIZE * 7 + HALF_BLOCK_SIZE)
    {
        gBG1XPosition = 0;
    }
    else if (pCoords->x > gBGPointersAndDimensions.backgrounds[1].width * BLOCK_SIZE - (BLOCK_SIZE * 7 + HALF_BLOCK_SIZE))
    {
        gBG1XPosition = gBGPointersAndDimensions.backgrounds[1].width * BLOCK_SIZE - ((BLOCK_SIZE * 7 + HALF_BLOCK_SIZE) * 2);
    }
    else
    {
        gBG1XPosition = pCoords->x - (BLOCK_SIZE * 7 + HALF_BLOCK_SIZE);
    }

    if (pCoords->y < BLOCK_SIZE * 6)
    {
        gBG1YPosition = 0;
    }
    else if (pCoords->y > gBGPointersAndDimensions.backgrounds[1].height * BLOCK_SIZE - (BLOCK_SIZE * 3))
    {
        gBG1YPosition = gBGPointersAndDimensions.backgrounds[1].height * BLOCK_SIZE - (BLOCK_SIZE * 9);
    }
    else
    {
        gBG1YPosition = pCoords->y - (BLOCK_SIZE * 6);
    }
}
