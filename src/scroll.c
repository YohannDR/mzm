#include "scroll.h"
#include "globals.h"
#include "bg_clip.h"

void ScrollProcess(struct RawCoordsX* pCoords)
{
    u32 screen_x;
    u32 screen_y;
    u32 new_position;
    struct Scroll* pScroll;

    ScrollUpdateCurrent(pCoords);
    screen_x = gScreenPositionAndVelocity.xPosition;
    screen_y = gScreenPositionAndVelocity.yPosition;

    pScroll = gCurrentScrolls;
    if (pScroll->within)
    {
        screen_x = ScrollProcessX(pScroll, pCoords);
        screen_y = ScrollProcessY(pScroll, pCoords);
    }

    pScroll = gCurrentScrolls + 1;
    if (pScroll->within)
    {
        new_position = ScrollProcessX(pScroll, pCoords);
        screen_x = (i32)(screen_x + new_position) >> 0x1;
        new_position = ScrollProcessY(pScroll, pCoords);
        screen_y = (i32)(screen_y + new_position) >> 0x1;
    }

    ScrollScreen((u16)screen_x, (u16)screen_y);
}

void ScrollScreen(u16 screen_x, u16 screen_y)
{

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
        if (ppSrc[0][0] == gCurrentRoom)
        {
            // Found room, set pointer and flag
            gCurrentRoomScrollDataPointer = *ppSrc;
            gCurrentRoomEntry.scrollsFlag = 0x3;
            break;
        }
        else if (ppSrc[0][0] == 0xFF)
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

    struct Scroll* pScroll;
    u16 xPosition;
    u16 yPosition;
    u32 scrollID;
    u8* pData;
    i32 bounds[4];
    i32 bound;
    i32 limit;
    u8 direction;

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
        // Incorrect
        if (pScroll == gCurrentScrolls)
            return;

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
            pScroll->xStart = bound;

            limit = gBGPointersAndDimensions.clipdataWidth * BLOCK_SIZE - (BLOCK_SIZE * 2);
            bound = (pData[bounds[1]] + 1) * BLOCK_SIZE;

            if (bound < limit)
                bound = limit;
            pScroll->xEnd = bound;

            limit = BLOCK_SIZE * 2;
            bound = pData[bounds[2]] * BLOCK_SIZE;
            if (bound < limit)
                bound = limit;
            pScroll->yStart = bound;

            limit = gBGPointersAndDimensions.clipdataHeight * BLOCK_SIZE - (BLOCK_SIZE * 2);
            bound = (pData[bounds[3]] + 1) * BLOCK_SIZE;

            if (bound < limit)
                bound = limit;
            pScroll->yEnd = bound;

            pScroll->within = 0x2;
            
            pScroll++;
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

void ScrollProcessGeneral(void)
{

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

    gScreenPositionAndVelocity.xPosition = xOffset;

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

    gScreenPositionAndVelocity.xVelocity = xOffset;
    gBG1XPosition += xOffset;
}

void ScrollUpdateEffectAndHazePosition(struct RawCoordsX* pCoords)
{

}

void ScrollAutoBG0(void)
{

}

u32 ScrollGetBG3Scroll(void)
{
    u32 xScroll;
    u32 yScroll;

    yScroll = 0x0;
    xScroll = 0x0;

    switch (gCurrentRoomEntry.BG3Scrolling)
    {
        case 0x0:
            break;

        case 0x1:
            xScroll = 0x2;
            yScroll = 0x0;
            break;

        case 0x2:
            xScroll = 0x0;
            yScroll = 0x2;
            break;

        case 0x3:
            xScroll = 0x2;
            yScroll = 0x2;
            break;

        case 0x4:
            xScroll = 0x1;
            yScroll = 0x2;
            break;

        case 0x5:
            xScroll = 0x2;
            yScroll = 0x1;
            break;

        case 0x6:
        case 0xA:
            xScroll = 0x1;
            yScroll = 0x1;
            break;
        
        case 0x9:
            xScroll = 0x3;
            yScroll = 0x0;
            break;

        case 0x7:
            xScroll = 0x1;
            yScroll = 0x0;
    }

    return yScroll << 0x10 | xScroll;
}

void ScrollBG3(void)
{

}

void ScrollBG3Related(void)
{
    u32 x_scroll;

    x_scroll = ScrollGetBG3Scroll();
    x_scroll &= 0xFF;
    if (x_scroll == 0x0)
        gBG3XPosition = 0x0;
    else if (x_scroll == 0x2)
        gBG3XPosition = (gBG1XPosition - 0x80) >> 0x1;
    else if (x_scroll == 0x3)
        gBG3XPosition = (gBG1XPosition - 0x80) >> 0x2;
}

void ScrollAutoBG3(void)
{
    if (gBG3Movement.direction == 0x1 && !(gBG3Movement.counter & 0x7))
        gBG3Movement.xOffset++;
    gBG3Movement.counter++;
}

void ScrollBG2(void)
{

}

void ScrollMaybeScrollBG1Related(struct RawCoordsX* pCoords)
{

}