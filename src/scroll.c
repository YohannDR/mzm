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
        screenX = (s32)(screenX + newPosition) >> 0x1;
        newPosition = ScrollProcessY(pScroll, pCoords);
        screenY = (s32)(screenY + newPosition) >> 0x1;
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
    s32 velocity;

    gCamera.xPosition = screenX;
    gCamera.yPosition = screenY;

    if (gGameModeSub1 == 0)
        return;
    
    if (screenY != gBg1YPosition)
    {
        velocity = screenY - gBg1YPosition;

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
        gBg1YPosition += velocity;
    }
    else
        gCamera.yVelocity = 0;
    
    if (screenX != gBg1XPosition)
    {
        velocity = screenX - gBg1XPosition;

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
        gBg1XPosition += velocity;
    }
    else
        gCamera.xVelocity = 0;
}

/**
 * @brief 583e4 | 40 | Processes the X scrolling
 * 
 * @param pScroll Scroll pointer
 * @param pCoords Coordinates pointer
 * @return s32 Screen X
 */
s32 ScrollProcessX(struct Scroll* pScroll, struct RawCoordsX* pCoords)
{
    s32 xPosition;
    s32 xStart;

    xPosition = pCoords->x;
    xStart = pScroll->xStart;

    if (xStart + 0x1E0 <= xPosition)
        return xStart;
    else if (xPosition <= pScroll->xEnd - 0x1E0)
        return xPosition - 0x1E0;
    else
        return pScroll->xEnd - 0x3C0;
}

/**
 * @brief 58424 | 54 | Processes the Y scrolling
 * 
 * @param pScroll Scroll pointer
 * @param pCoords Coordinates pointer
 * @return s32 Screen Y
 */
s32 ScrollProcessY(struct Scroll* pScroll, struct RawCoordsX* pCoords)
{
    s32 yPosition;
    s32 yStart;

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
    const u8* const * ppSrc;

    ppSrc = sAreaScrollPointers[gCurrentArea];

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
        
        if (**ppSrc == UCHAR_MAX)
        {
            // Reached terminator
            gCurrentRoomScrollDataPointer = *ppSrc;
            break;
        }
    }
}

void ScrollUpdateCurrent(struct RawCoordsX* pCoords)
{
    // https://decomp.me/scratch/VHsfW

    u16 xPosition;
    u16 yPosition;
    const u8* src;
    const u8* data;
    s32 nbrScrolls;
    s32 i;
    s32 bounds[4];
    s32 bound;
    s32 bound2;
    s32 limit;
    s32 value;
    s32 position;
    
    gCurrentScrolls[0].within = FALSE;
    gCurrentScrolls[1].within = FALSE;

    xPosition = pCoords->x / BLOCK_SIZE;
    yPosition = (u32)(pCoords->y - 1) / BLOCK_SIZE;

    src = gCurrentRoomScrollDataPointer;
    src++;
    nbrScrolls = *src;
    data = src + 1;
    
    for (i = 0; nbrScrolls != 0; nbrScrolls--)
    {
        if (i == ARRAY_SIZE(gCurrentScrolls))
            return;
        
        bounds[0] = 0;
        bounds[1] = 1;
        bounds[2] = 2;
        bounds[3] = 3;

        if (data[4] != UCHAR_MAX && data[7] != UCHAR_MAX)
        {
            limit = data[5] * gBgPointersAndDimensions.clipdataWidth + data[4];
            if (gBgPointersAndDimensions.pClipDecomp[limit] == 0 && data[6] != UCHAR_MAX)
                bounds[data[6]] = 7;
        }
        else
        {
            if (gSamusData.pose == SPOSE_USING_AN_ELEVATOR && data[7] != UCHAR_MAX && (data[6] == 2 || data[6] == 3))
                bounds[data[6]] = 7;
        }

        if (data[bounds[0]] <= xPosition && xPosition <= data[bounds[1]] && data[bounds[2]] <= yPosition && yPosition <= data[bounds[3]] && !gCurrentScrolls[i].within)
        {
            limit = BLOCK_SIZE * 2;
            value = data[bounds[0]] * BLOCK_SIZE;
            if (value < limit)
                value = limit;

            gCurrentScrolls[i].xStart = value;

            limit = gBgPointersAndDimensions.clipdataWidth * BLOCK_SIZE - BLOCK_SIZE * 2;
            value = (data[bounds[1]] + 1) * BLOCK_SIZE;
            if (value < 0)
                value = 0;

            if (value < limit)
                bound = value;
            else
                bound = limit;
            
            gCurrentScrolls[i].xEnd = bound;
            
            limit = BLOCK_SIZE * 2;
            value = data[bounds[2]] * BLOCK_SIZE;
            if (value < 0)
                value = 0;
            else if (value < limit)
                value = limit;

            gCurrentScrolls[i].yStart = value;

            limit = gBgPointersAndDimensions.clipdataHeight * BLOCK_SIZE - BLOCK_SIZE * 2;
            value = (data[bounds[3]] + 1) * BLOCK_SIZE;
            if (value < 0)
                value = 0;

            if (value < limit)
                bound2 = value;
            else
                bound2 = limit;
            
            gCurrentScrolls[i].yEnd = bound2;
            
            gCurrentScrolls[i].within = 2;
            i++;
        }

        data += SCROLL_SUB_DATA_SIZE;
    }

    if (!gCurrentScrolls[0].within && !gCurrentScrolls[1].within)
    {
        gCurrentScrolls[0].within = FALSE;
        gCurrentScrolls[0].xEnd = 0;
        gCurrentScrolls[0].xStart = 0;
        gCurrentScrolls[0].yStart = 0;
        gCurrentScrolls[0].yEnd = 0;
    }
}

/**
 * @brief 58640 | 1f4 | Processes the general scrolling
 * 
 */
void ScrollProcessGeneral(void)
{
    struct RawCoordsX coords;
    s32 distance;

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

        if (gBG0Movement.type != 0 && gCurrentRoomEntry.Bg0Prop & BG_PROP_LZ77_COMPRESSED)
            ScrollAutoBG0();

        ScrollUpdateEffectAndHazePosition(&coords);
        ScrollBG3();
        if (gBG3Movement.direction != 0)
            ScrollAutoBG3();
    }
}

/**
 * @brief 58834 | 14 | Handles the automatic scrolling in a room with no scrolls
 * 
 * @param pCoords Coordinates pointer
 */
void ScrollWithNoScrolls(struct RawCoordsX* pCoords)
{
    ScrollWithNoScrollsX(pCoords);
    ScrollWithNoScrollsY(pCoords);
}

/**
 * @brief 58848 | 100 | Handles the automatic Y scrolling in a room with no scrolls
 * 
 * @param pCoords Coordinates pointer
 */
void ScrollWithNoScrollsY(struct RawCoordsX* pCoords)
{
    s32 yOffset;
    s32 clipPosition;
    s32 offsetY;
    s32 yPosition;
    s32 yMovement;

    if (!gLockScreen.lock)
        yMovement = gSamusData.yPosition - gPreviousYPosition;
    else
        yMovement = 0;

    if (gSamusData.pose == SPOSE_MORPH_BALL || gSamusData.pose == SPOSE_ROLLING || gSamusData.pose == SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL)
    {
        if (gScreenYOffset + 4 < HALF_BLOCK_SIZE)
            gScreenYOffset += 2;
        else
            gScreenYOffset = HALF_BLOCK_SIZE;
    }
    else if (yMovement < 0)
    {
        if (gScreenYOffset + yMovement > 0)
            gScreenYOffset += yMovement / 2;
        else
            gScreenYOffset = 0;
    }

    yPosition = pCoords->y;
    offsetY = gScreenYOffset;
    if (yPosition < BLOCK_SIZE * 8 - offsetY)
        yOffset = BLOCK_SIZE * 2;
    else
    {
        clipPosition = (gBgPointersAndDimensions.backgrounds[1].height * BLOCK_SIZE) - BLOCK_SIZE * 6;
        clipPosition -= offsetY;
        if (yPosition > clipPosition)
            clipPosition = clipPosition - BLOCK_SIZE * 6;
        else
            clipPosition = yPosition - BLOCK_SIZE * 6;
        yOffset = clipPosition + offsetY;
    }

    gCamera.yPosition = yOffset;

    yOffset -= gBg1YPosition;
    if (yOffset > 0)
    {
        if (gUnk_3005714.unk6 < yOffset)
            yOffset = gUnk_3005714.unk6;
    }
    else
    {
        if (yOffset < gUnk_3005714.unk4)
            yOffset = gUnk_3005714.unk4;
    }

    gCamera.yVelocity = yOffset;
    gBg1YPosition += yOffset;
}

/**
 * @brief 58948 | d0 | Handles the automatic X scrolling in a room with no scrolls
 * 
 * @param pCoords Coordinates pointer
 */
void ScrollWithNoScrollsX(struct RawCoordsX* pCoords)
{
    s32 xOffset;
    s32 clipPosition;
    s32 offsetX;
    s32 xPosition;

    xOffset = 0;
    if (!gLockScreen.lock && gSamusPhysics.standingStatus == STANDING_NOT_IN_CONTROL)
    {
        if (gSamusData.direction & KEY_RIGHT)
            xOffset = BLOCK_SIZE * 2;
        else if (gSamusData.direction & KEY_LEFT)
            xOffset = -(BLOCK_SIZE * 2);
    }

    gScreenXOffset = xOffset;
        
    xPosition = pCoords->x;
    offsetX = gScreenXOffset;
    if (xPosition < (BLOCK_SIZE * 9 + HALF_BLOCK_SIZE) - offsetX)
        xOffset = BLOCK_SIZE * 2;
    else
    {
        do {
            clipPosition = (gBgPointersAndDimensions.backgrounds[1].width * BLOCK_SIZE) - (BLOCK_SIZE * 9 + HALF_BLOCK_SIZE);
            clipPosition -= offsetX;
        }while(0);
        if (xPosition > clipPosition)
            clipPosition = clipPosition - (BLOCK_SIZE * 7 + HALF_BLOCK_SIZE);
        else
            clipPosition = xPosition - (BLOCK_SIZE * 7 + HALF_BLOCK_SIZE);
        xOffset = clipPosition + offsetX;
    }

    gCamera.xPosition = xOffset;

    xOffset -= gBg1XPosition;
    if (xOffset > 0)
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
    gBg1XPosition += xOffset;
}

/**
 * @brief 58a18 | 2a8 | Updates the haze and effect position
 * 
 * @param pCoords Coordinates pointer
 */
void ScrollUpdateEffectAndHazePosition(struct RawCoordsX* pCoords)
{
    u32 var_0;
    s32 position;
    s32 waterOffset;
    u16 temp;
    
    var_0 = FALSE;
    if (gCurrentRoomEntry.Bg0Prop & BG_PROP_RLE_COMPRESSED)
    {
        if (gCurrentRoomEntry.Bg0Prop == 0x11)
        {
            gBg0XPosition = gBg1XPosition / 2;
            gBg0YPosition = gBg1YPosition;
            
            var_0 = TRUE;
        }
    }
    else
    {
        if (gCurrentRoomEntry.effectY != USHORT_MAX)
        {
            gBg0XPosition = gBg1XPosition;
            position = (gCurrentRoomEntry.effectY + gEffectYPositionOffset - gBg1YPosition) >> 2;

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

            gBg0YPosition = -position * 4;
            var_0 = TRUE;
        }
        else
        {
            var_0 = TRUE;
            switch (gCurrentRoomEntry.Bg0Prop)
            {
                case BG_PROP_CLOSE_UP:
                    gBg0XPosition = 0;
                    gBg0YPosition = 0;
                    break;

                case 0x43:
                case BG_PROP_DARK_ROOM:
                    gBg0XPosition = gBg1XPosition - pCoords->x;
                    gBg0YPosition = gBg1YPosition - pCoords->y + BLOCK_SIZE;
                    break;

                case 0x44:
                    position = FALSE;

                    gBg0XPosition = (gBg1XPosition - gWaitingSpacePiratesPosition.x) + BLOCK_SIZE * 32;
                    gBg0YPosition = (gBg1YPosition - gWaitingSpacePiratesPosition.y) + BLOCK_SIZE * 17;

                    temp = (gBg1XPosition - gWaitingSpacePiratesPosition.x) + BLOCK_SIZE * 20;
                    if (temp > BLOCK_SIZE * 24)
                        position = TRUE;

                    temp = (gBg1YPosition - gWaitingSpacePiratesPosition.y) + BLOCK_SIZE * 13;
                    if (temp > BLOCK_SIZE * 12)
                        position = TRUE;

                    if (position)
                    {
                        gBg0XPosition = BLOCK_SIZE * 8;
                    }
                    break;

                default:
                    var_0 = FALSE;
            }
        }
    }

    if (!var_0)
    {
        gBg0YPosition = gBg1YPosition;
        gBg0XPosition = gBg1XPosition;
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

/**
 * @brief 58d20 | 80 | Gets the BG3 scrolling type
 * 
 * @return u32 Types (y << 16 | x)
 */
u32 ScrollGetBG3Scroll(void)
{
    u32 xScroll;
    u32 yScroll;

    yScroll = 0;
    xScroll = 0;

    switch (gCurrentRoomEntry.Bg3Scrolling)
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
    s32 yScrolling;
    s32 offset;
    s32 size;

    yScrolling = ScrollGetBG3Scroll();
    xScrolling = yScrolling & 0xFF;
    yScrolling = yScrolling >> 16;

    if (xScrolling != 0)
    {
        if (xScrolling == 1)
            gBg3XPosition = gBg1XPosition - BLOCK_SIZE * 2;
        else if (xScrolling == 2)
            gBg3XPosition = (gBg1XPosition - BLOCK_SIZE * 2) >> 1;
        else if (xScrolling == 3)
            gBg3XPosition = (gBg1XPosition - BLOCK_SIZE * 2) >> 2;
    }

    if (gCurrentRoomEntry.BG3FromBottomFlag)
    {
        size = (gBgPointersAndDimensions.clipdataHeight - 0xC) * BLOCK_SIZE;

        if (gCurrentRoomEntry.Bg3Size & 2)
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
            size -= gBg1YPosition;
        else
            size = (size - gBg1YPosition) >> 2;
        
        if (offset - size > 0)
            gBg3YPosition = offset - size;
        else
            gBg3YPosition = 0;
    }
    else
    {
        if (yScrolling == 0)
            gBg3YPosition = 0;
        else if (yScrolling == 1)
            gBg3YPosition = gBg1YPosition - BLOCK_SIZE * 2;
        else if (yScrolling == 2)
            gBg3YPosition = (gBg1YPosition - BLOCK_SIZE * 2) >> 1;
        else
            gBg3YPosition = (gBg1YPosition - BLOCK_SIZE * 2) >> 2;
    }
}

/**
 * @brief 58ec4 | 50 | To document
 * 
 */
void ScrollBG3Related(void)
{
    u32 xScroll;

    xScroll = ScrollGetBG3Scroll();
    xScroll &= 0xFF;
    if (xScroll == 0x0)
        gBg3XPosition = 0x0;
    else if (xScroll == 0x2)
        gBg3XPosition = (gBg1XPosition - 0x80) >> 0x1;
    else if (xScroll == 0x3)
        gBg3XPosition = (gBg1XPosition - 0x80) >> 0x2;
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

/**
 * @brief 58f40 | c8 | Scrolls the BG2
 * 
 * @param pCoords Coordinates pointer
 */
void ScrollBG2(struct RawCoordsX* pCoords)
{
    s32 size;
    s32 position;
    u32 temp;
    u8 temp2;

    gCurrentRoomEntry.Bg2Prop = gCurrentRoomEntry.Bg2Prop;
    if (gCurrentRoomEntry.Bg2Prop & BG_PROP_RLE_COMPRESSED)
    {
        if (gCurrentRoomEntry.Bg2Prop & 0x20)
        {
            if (gCurrentRoomEntry.Bg2Prop == BG_PROP_MOVING)
            {
                position = gBg1XPosition + gBG2Movement.xOffset;
                if (position < 0)
                    position = 0;
                else
                {
                    size = (gBgPointersAndDimensions.backgrounds[2].width - 0xF) * BLOCK_SIZE;
                    if (size < position)
                        position = size;
                }

                gBg2XPosition = position;

                position = gBg1YPosition + gBG2Movement.yOffset;
                if (position < 0)
                    position = 0;
                else
                {
                    size = (gBgPointersAndDimensions.backgrounds[2].height - 0xA) * BLOCK_SIZE;
                    if (size < position)
                        position = size;
                }

                gBg2YPosition = position;
                return;
            }
        }

        gBg2XPosition = gBg1XPosition;
        gBg2YPosition = gBg1YPosition;
    }
    else
    {
        gBg2XPosition = 0;
        gBg2YPosition = 0;
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
        gBg1XPosition = 0;
    }
    else if (pCoords->x > gBgPointersAndDimensions.backgrounds[1].width * BLOCK_SIZE - (BLOCK_SIZE * 7 + HALF_BLOCK_SIZE))
    {
        gBg1XPosition = gBgPointersAndDimensions.backgrounds[1].width * BLOCK_SIZE - ((BLOCK_SIZE * 7 + HALF_BLOCK_SIZE) * 2);
    }
    else
    {
        gBg1XPosition = pCoords->x - (BLOCK_SIZE * 7 + HALF_BLOCK_SIZE);
    }

    if (pCoords->y < BLOCK_SIZE * 6)
    {
        gBg1YPosition = 0;
    }
    else if (pCoords->y > gBgPointersAndDimensions.backgrounds[1].height * BLOCK_SIZE - (BLOCK_SIZE * 3))
    {
        gBg1YPosition = gBgPointersAndDimensions.backgrounds[1].height * BLOCK_SIZE - (BLOCK_SIZE * 9);
    }
    else
    {
        gBg1YPosition = pCoords->y - (BLOCK_SIZE * 6);
    }
}
