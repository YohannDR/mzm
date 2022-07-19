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
    i32 x_pos;
    i32 xStart;

    x_pos = pCoords->x;
    xStart = pScroll->xStart;

    if (xStart + 0x1E0 <= x_pos)
        return xStart;
    else if (x_pos <= pScroll->xEnd - 0x1E0)
        return x_pos - 0x1E0;
    else
        return pScroll->xEnd - 0x3C0;
}

i32 ScrollProcessY(struct Scroll* pScroll, struct RawCoordsX* pCoords)
{
    i32 y_pos;
    i32 yStart;

    if (pScroll->within == 0x2)
    {
        y_pos = pCoords->y;
        yStart = pScroll->yStart;

        if (y_pos >= yStart + 0x180)
        {
            if (y_pos > pScroll->yEnd - 0x100)
            {
                if (pScroll->yEnd - 0x280 < yStart)
                    return yStart;
                return pScroll->yEnd - 0x280;
            }
            else
                return y_pos - 0x180;
        }
        else
            return yStart;
    }
    else
        return pScroll->yEnd - 0x280;
}

void ScrollLoad(void)
{

}

void ScrollUpdateCurrent(struct RawCoordsX* pCoords)
{
    /*struct Scroll* pScroll;
    struct Scroll* pScrollLimit;
    struct background_pointers_and_dimensions* pBG;
    u8* pData;
    u16 x_pos;
    u16 y_pos;
    u32 id;
    i32 bounds[0x4];
    i32 bound;
    i32 clip_limit;
    i32 bound_limit;

    pScroll = &gCurrentScrolls.first;
    pScrollLimit = pScroll;
    pScroll->within = FALSE;
    pScroll[0x1].within = FALSE;

    x_pos = pCoords->x >> 0x6;
    y_pos = (u16)(pCoords->y - 0x1 >> 0x6);

    id = gCurrentRoomScrollDataPointer[0x1]; // ID
    pData = gCurrentRoomScrollDataPointer + 0x2;

    if (id != 0x0)
    {
        pBG = &gBGPointersAndDimensions;
        while (id != 0x0)
        {
            if (pScroll == (pScrollLimit + 2))
                return;

            bounds[0x0] = 0x0;
            bounds[0x1] = 0x1;
            bounds[0x2] = 0x2;
            bounds[0x3] = 0x3;

            if (pData[0x4] != 0xFF && pData[0x7] != 0xFF)
            {
                if (pBG->pClipDecomp[pData[0x5] * pBG->clipdataWidth + pData[0x4]] == 0x0)
                {
                    if (pData[0x6] != 0xFF)
                        bounds[pData[0x6]] = 0x7;
                }
            }
            else
            {
                if (gSamusData.pose == SPOSE_USING_AN_ELEVATOR && pData[0x7] != 0xFF && (u8)(pData[0x6] - 0x2) < 0x2)
                    bounds[pData[0x6]] = 0x7;
            }

            if (pData[bounds[0x0]] <= x_pos && x_pos <= pData[bounds[0x1]] && pData[bounds[0x2]] <= y_pos && y_pos <= pData[bounds[0x3]] && pScroll->within == 0x0)
            {
                bound = pData[bounds[0x0]] << 0x6;
                if (0x80 >= bound)
                    bound = 0x80;
                pScroll->xStart = bound;

                // X end
                clip_limit = (pBG->clipdataWidth << 0x6) - 0x80;
                bound_limit = (pData[bounds[0x1]] + 0x1) << 0x6;
                if (bound_limit < clip_limit)
                    bound = bound_limit;
                else
                    bound = clip_limit;
                pScroll->xEnd = bound;

                bound = pData[bounds[0x2]] << 0x6;
                if (bound < 0x80)
                    bound = 0x80;
                pScroll->yStart = bound;

                // Y end
                clip_limit = (pBG->clipdataHeight << 0x6) - 0x80;
                bound_limit = (pData[bounds[0x3]] + 0x1) << 0x6;
                if (bound_limit < clip_limit)
                    bound = bound_limit;
                else
                    bound = clip_limit;
                pScroll->yEnd = bound;

                pScroll->within = 0x2;
                pScroll++;
            }

            pData += 0x8;
            id--;
        }
    }
    
    if (pScroll->within == FALSE && pScroll[0x1].within == FALSE)
    {
        pScroll->within = 0x0;
        pScroll->xEnd = 0x0;
        pScroll->xStart = 0x0;
        pScroll->yStart = 0x0;
        pScroll->yEnd = 0x0;
    }*/
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

}

void ScrollUpdateEffectAndHazePosition(struct RawCoordsX* pCoords)
{

}

void ScrollAutoBG0(void)
{

}

u32 ScrollGetBG3Scroll(void)
{
    u32 x_scroll;
    u32 y_scroll;

    y_scroll = 0x0;
    x_scroll = 0x0;

    switch (gCurrentRoomEntry.BG3Scrolling)
    {
        case 0x0:
            break;

        case 0x1:
            x_scroll = 0x2;
            y_scroll = 0x0;
            break;

        case 0x2:
            x_scroll = 0x0;
            y_scroll = 0x2;
            break;

        case 0x3:
            x_scroll = 0x2;
            y_scroll = 0x2;
            break;

        case 0x4:
            x_scroll = 0x1;
            y_scroll = 0x2;
            break;

        case 0x5:
            x_scroll = 0x2;
            y_scroll = 0x1;
            break;

        case 0x6:
        case 0xA:
            x_scroll = 0x1;
            y_scroll = 0x1;
            break;
        
        case 0x9:
            x_scroll = 0x3;
            y_scroll = 0x0;
            break;

        case 0x7:
            x_scroll = 0x1;
            y_scroll = 0x0;
    }

    return y_scroll << 0x10 | x_scroll;
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
    if (gBG3Movement.direction == 0x1 && (gBG3Movement.counter & 0x7) == 0x0)
        gBG3Movement.xOffset++;
    gBG3Movement.counter++;
}

void ScrollBG2(void)
{

}

void ScrollMaybeScrollBG1Related(struct RawCoordsX* pCoords)
{

}