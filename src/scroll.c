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
    s32 screenX;
    s32 screenY;
    struct Scroll* pScroll;

    // Update scrolls
    ScrollUpdateCurrent(pCoords);

    // Get current screen coords
    screenX = gCamera.xPosition;
    screenY = gCamera.yPosition;

    // Check for first scroll
    pScroll = gCurrentScrolls;
    if (pScroll->within != SCROLL_NOT_WITHIN_FLAG)
    {
        // Get positions
        screenX = ScrollProcessX(pScroll, pCoords);
        screenY = ScrollProcessY(pScroll, pCoords);
    }

    // Check for second scroll
    pScroll++;
    if (pScroll->within != SCROLL_NOT_WITHIN_FLAG)
    {
        // Get positions, compute middle between previous and new positions
        // This merges the results of this scroll with the previous one
        screenX = DIV_SHIFT(screenX + ScrollProcessX(pScroll, pCoords), 2);
        screenY = DIV_SHIFT(screenY + ScrollProcessY(pScroll, pCoords), 2);
    }

    // Apply new positions
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

    // Set wanted position
    gCamera.xPosition = screenX;
    gCamera.yPosition = screenY;

    if (gGameModeSub1 == 0)
        return;

    // Check needs to scroll
    if (screenY != gBg1YPosition)
    {
        // Compute Y difference
        velocity = screenY - gBg1YPosition;

        // Apply velocity caps
        if (velocity > 0)
        {
            if (gScrollingVelocityCaps.downCap < velocity)
                velocity = gScrollingVelocityCaps.downCap;
        }
        else
        {
            if (gScrollingVelocityCaps.upCap > velocity)
                velocity = gScrollingVelocityCaps.upCap;
        }

        // Set velocity and apply it
        gCamera.yVelocity = velocity;
        gBg1YPosition += velocity;
    }
    else
    {
        // Already at position
        gCamera.yVelocity = 0;
    }
    
    if (screenX != gBg1XPosition)
    {
        // Compute X difference
        velocity = screenX - gBg1XPosition;

        // Apply velocity caps
        if (velocity > 0)
        {
            if (gScrollingVelocityCaps.rightCap < velocity)
                velocity = gScrollingVelocityCaps.rightCap;
        }
        else
        {
            if (gScrollingVelocityCaps.leftCap > velocity)
                velocity = gScrollingVelocityCaps.leftCap;
        }

        // Set velocity and apply it
        gCamera.xVelocity = velocity;
        gBg1XPosition += velocity;
    }
    else
    {
        // Already at position
        gCamera.xVelocity = 0;
    }
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
    // Check is on the far left of the scroll, i.e. if the distance between the start and the coords X is smaller than the anchor
    if (pCoords->x < pScroll->xStart + SCROLL_X_ANCHOR)
    {
        // Screen should be at the left limit of the scroll then
        return pScroll->xStart;
    }

    // Check isn't on the far right of the scroll, i.e. if the distance between the end and the coords X is smaller than the anchor
    if (pCoords->x <= pScroll->xEnd - SCROLL_X_ANCHOR)
    {
        // In the middle of the scroll otherwhise, set the position to the coords - anchor
        return pCoords->x - SCROLL_X_ANCHOR;
    }

    // Screen should "stop" before the right limit, so set it to right - screen size
    return pScroll->xEnd - SCREEN_SIZE_X_SUB_PIXEL;
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
    if (pScroll->within == SCROLL_WITHIN_FLAG)
    {
        // Check is above the scroll Y anchor, i.e. the distance between the start and the coords Y is smaller than the anchor
        if (pCoords->y < pScroll->yStart + SCROLL_Y_ANCHOR)
        {
            // Stop the screen at the top of the scroll
            return pScroll->yStart;
        }

        // Check is below the scroll Y anchor, i.e. the distance between the end and the coords Y is smaller than the difference between the total size and the anchor
        if (pCoords->y > pScroll->yEnd - (SCREEN_SIZE_Y_SUB_PIXEL - SCROLL_Y_ANCHOR))
        {
            if (pScroll->yEnd - SCREEN_SIZE_Y_SUB_PIXEL < pScroll->yStart)
                return pScroll->yStart;

            // Stop the screen at the bottom of the scroll
            return pScroll->yEnd - SCREEN_SIZE_Y_SUB_PIXEL;
        }

        // In the middle of the scroll otherwhise, set the position to the coords - anchor
        return pCoords->y - SCROLL_Y_ANCHOR;
    }

    return pScroll->yEnd - SCREEN_SIZE_Y_SUB_PIXEL;
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

#ifdef NON_MATCHING
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
    
    gCurrentScrolls[0].within = SCROLL_NOT_WITHIN_FLAG;
    gCurrentScrolls[1].within = SCROLL_NOT_WITHIN_FLAG;

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

        if (data[bounds[0]] <= xPosition && xPosition <= data[bounds[1]] && data[bounds[2]] <= yPosition && yPosition <= data[bounds[3]] && gCurrentScrolls[i].within == SCROLL_NOT_WITHIN_FLAG)
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
            
            gCurrentScrolls[i].within = SCROLL_WITHIN_FLAG;
            i++;
        }

        data += SCROLL_SUB_DATA_SIZE;
    }

    if (gCurrentScrolls[0].within == SCROLL_NOT_WITHIN_FLAG && gCurrentScrolls[1].within == SCROLL_NOT_WITHIN_FLAG)
    {
        gCurrentScrolls[0].within = SCROLL_NOT_WITHIN_FLAG;
        gCurrentScrolls[0].xEnd = 0;
        gCurrentScrolls[0].xStart = 0;
        gCurrentScrolls[0].yStart = 0;
        gCurrentScrolls[0].yEnd = 0;
    }
}
#else
NAKED_FUNCTION
void ScrollUpdateCurrent(struct RawCoordsX* pCoords)
{
    asm(" \n\
    push {r4, r5, r6, r7, lr} \n\
    mov r7, sb \n\
    mov r6, r8 \n\
    push {r6, r7} \n\
    sub sp, #0x10 \n\
    ldr r2, lbl_08058554 @ =gCurrentScrolls \n\
    movs r1, #0 \n\
    strb r1, [r2] \n\
    strb r1, [r2, #0xc] \n\
    ldrh r1, [r0] \n\
    lsr r1, r1, #6 \n\
    mov r8, r1 \n\
    ldrh r0, [r0, #2] \n\
    sub r0, #1 \n\
    lsl r0, r0, #0xa \n\
    lsr r0, r0, #0x10 \n\
    mov ip, r0 \n\
    ldr r0, lbl_08058558 @ =gCurrentRoomScrollDataPointer \n\
    ldr r0, [r0] \n\
    add r0, #1 \n\
    ldrb r5, [r0] \n\
    add r4, r0, #1 \n\
    add r7, r2, #0 \n\
    cmp r5, #0 \n\
    bne lbl_0805850c \n\
    b lbl_08058616 \n\
lbl_0805850c: \n\
    ldr r6, lbl_0805855c @ =gBgPointersAndDimensions \n\
    mov sb, r7 \n\
lbl_08058510: \n\
    mov r0, sb \n\
    add r0, #0x18 \n\
    cmp r2, r0 \n\
    bne lbl_0805851a \n\
    b lbl_0805862c \n\
lbl_0805851a: \n\
    movs r0, #0 \n\
    str r0, [sp] \n\
    movs r0, #1 \n\
    str r0, [sp, #4] \n\
    movs r0, #2 \n\
    str r0, [sp, #8] \n\
    movs r0, #3 \n\
    str r0, [sp, #0xc] \n\
    ldrb r0, [r4, #4] \n\
    cmp r0, #0xff \n\
    beq lbl_08058560 \n\
    ldrb r0, [r4, #7] \n\
    cmp r0, #0xff \n\
    beq lbl_08058560 \n\
    ldrb r1, [r4, #5] \n\
    ldrh r0, [r6, #0x1c] \n\
    mul r0, r1, r0 \n\
    ldrb r1, [r4, #4] \n\
    add r3, r0, r1 \n\
    ldr r1, [r6, #0x18] \n\
    lsl r0, r3, #1 \n\
    add r0, r0, r1 \n\
    ldrh r0, [r0] \n\
    cmp r0, #0 \n\
    bne lbl_08058586 \n\
    ldrb r0, [r4, #6] \n\
    cmp r0, #0xff \n\
    beq lbl_08058586 \n\
    b lbl_0805857c \n\
    .align 2, 0 \n\
lbl_08058554: .4byte gCurrentScrolls \n\
lbl_08058558: .4byte gCurrentRoomScrollDataPointer \n\
lbl_0805855c: .4byte gBgPointersAndDimensions \n\
lbl_08058560: \n\
    ldr r0, lbl_0805863c @ =gSamusData \n\
    ldrb r0, [r0] \n\
    cmp r0, #0x1d \n\
    bne lbl_08058586 \n\
    ldrb r0, [r4, #7] \n\
    cmp r0, #0xff \n\
    beq lbl_08058586 \n\
    ldrb r0, [r4, #6] \n\
    sub r0, #2 \n\
    lsl r0, r0, #0x18 \n\
    lsr r0, r0, #0x18 \n\
    cmp r0, #1 \n\
    bhi lbl_08058586 \n\
    ldrb r0, [r4, #6] \n\
lbl_0805857c: \n\
    lsl r0, r0, #2 \n\
    mov r3, sp \n\
    add r1, r3, r0 \n\
    movs r0, #7 \n\
    str r0, [r1] \n\
lbl_08058586: \n\
    ldr r0, [sp] \n\
    add r0, r4, r0 \n\
    ldrb r1, [r0] \n\
    cmp r1, r8 \n\
    bhi lbl_0805860c \n\
    ldr r0, [sp, #4] \n\
    add r0, r4, r0 \n\
    ldrb r0, [r0] \n\
    cmp r8, r0 \n\
    bhi lbl_0805860c \n\
    ldr r0, [sp, #8] \n\
    add r0, r4, r0 \n\
    ldrb r0, [r0] \n\
    cmp r0, ip \n\
    bhi lbl_0805860c \n\
    ldr r0, [sp, #0xc] \n\
    add r0, r4, r0 \n\
    ldrb r0, [r0] \n\
    cmp ip, r0 \n\
    bhi lbl_0805860c \n\
    ldrb r0, [r2] \n\
    cmp r0, #0 \n\
    bne lbl_0805860c \n\
    lsl r0, r1, #6 \n\
    cmp r0, #0x80 \n\
    bge lbl_080585bc \n\
    movs r0, #0x80 \n\
lbl_080585bc: \n\
    strh r0, [r2, #4] \n\
    ldrh r0, [r6, #0x1c] \n\
    lsl r0, r0, #6 \n\
    add r3, r0, #0 \n\
    sub r3, #0x80 \n\
    ldr r0, [sp, #4] \n\
    add r0, r4, r0 \n\
    ldrb r0, [r0] \n\
    add r0, #1 \n\
    lsl r0, r0, #6 \n\
    add r1, r3, #0 \n\
    cmp r0, r3 \n\
    bge lbl_080585d8 \n\
    add r1, r0, #0 \n\
lbl_080585d8: \n\
    strh r1, [r2, #2] \n\
    ldr r0, [sp, #8] \n\
    add r0, r4, r0 \n\
    ldrb r0, [r0] \n\
    lsl r0, r0, #6 \n\
    cmp r0, #0x80 \n\
    bge lbl_080585e8 \n\
    movs r0, #0x80 \n\
lbl_080585e8: \n\
    strh r0, [r2, #6] \n\
    ldrh r0, [r6, #0x1e] \n\
    lsl r0, r0, #6 \n\
    add r3, r0, #0 \n\
    sub r3, #0x80 \n\
    ldr r0, [sp, #0xc] \n\
    add r0, r4, r0 \n\
    ldrb r0, [r0] \n\
    add r0, #1 \n\
    lsl r0, r0, #6 \n\
    add r1, r3, #0 \n\
    cmp r0, r3 \n\
    bge lbl_08058604 \n\
    add r1, r0, #0 \n\
lbl_08058604: \n\
    strh r1, [r2, #8] \n\
    movs r0, #2 \n\
    strb r0, [r2] \n\
    add r2, #0xc \n\
lbl_0805860c: \n\
    add r4, #8 \n\
    sub r5, #1 \n\
    cmp r5, #0 \n\
    beq lbl_08058616 \n\
    b lbl_08058510 \n\
lbl_08058616: \n\
    ldrb r0, [r7] \n\
    cmp r0, #0 \n\
    bne lbl_0805862c \n\
    ldrb r0, [r7, #0xc] \n\
    cmp r0, #0 \n\
    bne lbl_0805862c \n\
    strb r0, [r7] \n\
    strh r0, [r7, #2] \n\
    strh r0, [r7, #4] \n\
    strh r0, [r7, #6] \n\
    strh r0, [r7, #8] \n\
lbl_0805862c: \n\
    add sp, #0x10 \n\
    pop {r3, r4} \n\
    mov r8, r3 \n\
    mov sb, r4 \n\
    pop {r4, r5, r6, r7} \n\
    pop {r0} \n\
    bx r0 \n\
    .align 2, 0 \n\
lbl_0805863c: .4byte gSamusData \n\
    ");
}
#endif

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

    // Don't scroll if a color fading is active
    if (gColorFading.stage != 0)
        return;

    // Get coordinates for the center of the scroll
    if (gLockScreen.lock == LOCK_SCREEN_TYPE_NONE)
    {
        // No lock screen, use samus position
        coords.x = gSamusData.xPosition;
        coords.y = gSamusData.yPosition + ONE_SUB_PIXEL;

        // Update slow scrolling timer
        if (gSamusData.pose == SPOSE_HANGING_ON_LEDGE || gSamusData.pose == SPOSE_GRABBING_A_LEDGE_SUITLESS)
        {
            // Hanging on ledge, slow scroll a little bit
            gSlowScrollingTimer = 1;
        }
        else if (gSamusData.pose == SPOSE_PULLING_YOURSELF_UP_FROM_HANGING || gSamusData.pose == SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING)
        {
            // Pulling self up, slow scroll during the animation
            gSlowScrollingTimer = 8;
        }
        else if (gSamusData.pose == SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL)
        {
            // Pulling self up and morphing, slow scroll during the animation
            gSlowScrollingTimer = 20;
        }
        else if (gSlowScrollingTimer != 0)
        {
            // Decrement timer
            gSlowScrollingTimer--;
        }
    }
    else if (gLockScreen.lock == LOCK_SCREEN_TYPE_POSITION)
    {
        // Lock screen active (position type), use lock screen position
        coords.x = gLockScreen.xPositionCenter;
        coords.y = gLockScreen.yPositionCenter;
    }
    else
    {
        // Lock screen active (middle type), use middle position between samus and lock screen position
        x = gSamusData.xPosition + gLockScreen.xPositionCenter;
        y = gSamusData.yPosition + ONE_SUB_PIXEL + gLockScreen.yPositionCenter;

        coords.x = x / 2;
        coords.y = y / 2;
    }

    // Check for sign bit
    if (coords.y & 0x8000)
        coords.y = 0;

    // Set default velocity caps
    gScrollingVelocityCaps = sScrollVelocityCaps[SCROLL_VELOCITY_CAP_SET_DEFAULT];

    if (gLockScreen.lock == LOCK_SCREEN_TYPE_NONE)
    {
        if (gSlowScrollingTimer == 0)
        {
            // Compute new velocity caps to accomodate for samus movements
            distance = gSamusData.xPosition - gPreviousXPosition;

            if (distance > 0)
            {
                if (distance >= gScrollingVelocityCaps.rightCap)
                    gScrollingVelocityCaps.rightCap = distance + PIXEL_SIZE;
            }
            else if (distance < 0)
            {
                if (distance <= gScrollingVelocityCaps.leftCap)
                    gScrollingVelocityCaps.leftCap = distance - PIXEL_SIZE;
            }

            distance = gSamusData.yPosition - gPreviousYPosition;

            if (distance > 0)
            {
                if (distance >= gScrollingVelocityCaps.downCap)
                    gScrollingVelocityCaps.downCap = distance + PIXEL_SIZE;
            }
            else if (distance < 0)
            {
                if (distance <= gScrollingVelocityCaps.upCap)
                    gScrollingVelocityCaps.upCap = distance - PIXEL_SIZE;
            }
        }
        else
        {
            // Use slow velocity caps since slow scrolling is active
            gScrollingVelocityCaps = sScrollVelocityCaps[SCROLL_VELOCITY_CAP_SET_SLOW];
        }
    }

    if (!gDisableScrolling)
    {
        // Process scrolling
        if (gFreeMovementLockCamera && gGameModeSub1 == SUB_GAME_MODE_FREE_MOVEMENT)
        {
            // Update camera lock movement
            ScrollFreeMovementDebugCameraLock(&coords);
        }
        else if (gCurrentRoomEntry.scrollsFlag == ROOM_SCROLLS_FLAG_HAS_SCROLLS)
        {
            // Process with scrolls in the room
            ScrollProcess(&coords);
        }
        else
        {
            // Process without scrolls in the room
            ScrollWithNoScrolls(&coords);
        }

        // Scroll bg2
        ScrollBg2(&coords);

        // Check auto scroll bg0
        if (gBg0Movement.type != 0 && gCurrentRoomEntry.Bg0Prop & BG_PROP_LZ77_COMPRESSED)
            ScrollAutoBg0();

        // Update effect and haze
        ScrollUpdateEffectAndHazePosition(&coords);

        // Scroll bg3
        ScrollBg3();

        // Check auto scroll bg3
        if (gBg3Movement.active != 0)
            ScrollAutoBg3();
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

    if (gLockScreen.lock == LOCK_SCREEN_TYPE_NONE)
        yMovement = gSamusData.yPosition - gPreviousYPosition;
    else
        yMovement = 0;

    if (gSamusData.pose == SPOSE_MORPH_BALL || gSamusData.pose == SPOSE_ROLLING || gSamusData.pose == SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL)
    {
        if (gScreenYOffset + PIXEL_SIZE < HALF_BLOCK_SIZE)
            gScreenYOffset += PIXEL_SIZE / 2;
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
        clipPosition = (gBgPointersAndDimensions.backgrounds[1].height * BLOCK_SIZE) - SCROLL_Y_ANCHOR;
        clipPosition -= offsetY;
        if (yPosition > clipPosition)
            clipPosition = clipPosition - SCROLL_Y_ANCHOR;
        else
            clipPosition = yPosition - SCROLL_Y_ANCHOR;
        yOffset = clipPosition + offsetY;
    }

    gCamera.yPosition = yOffset;

    yOffset -= gBg1YPosition;
    if (yOffset > 0)
    {
        if (gScrollingVelocityCaps.downCap < yOffset)
            yOffset = gScrollingVelocityCaps.downCap;
    }
    else
    {
        if (yOffset < gScrollingVelocityCaps.upCap)
            yOffset = gScrollingVelocityCaps.upCap;
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
    if (gLockScreen.lock == LOCK_SCREEN_TYPE_NONE && gSamusPhysics.standingStatus == STANDING_NOT_IN_CONTROL)
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
            clipPosition = clipPosition - SCROLL_X_ANCHOR;
        else
            clipPosition = xPosition - SCROLL_X_ANCHOR;
        xOffset = clipPosition + offsetX;
    }

    gCamera.xPosition = xOffset;

    xOffset -= gBg1XPosition;
    if (xOffset > 0)
    {
        if (gScrollingVelocityCaps.rightCap < xOffset)
            xOffset = gScrollingVelocityCaps.rightCap;
    }
    else
    {
        if (xOffset < gScrollingVelocityCaps.leftCap)
            xOffset = gScrollingVelocityCaps.leftCap;
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
void ScrollAutoBg0(void)
{
    if (gBg0Movement.type == BG0_MOVEMENT_WATER_CLOUDS)
    {
        if (MOD_AND(gBg0Movement.counter, 8) == 0)
            gBg0Movement.xOffset++;
    }
    else if (gBg0Movement.type == 2)
    {
        if (MOD_AND(gBg0Movement.counter, 4) == 0)
            gBg0Movement.xOffset++;
    }
    else if (gBg0Movement.type == 3)
    {
        if (MOD_AND(gBg0Movement.counter, 8) == 0)
            gBg0Movement.yOffset++;
    }
    else if (gBg0Movement.type == BG0_MOVEMENT_SNOWFLAKES)
    {
        if (MOD_AND(gBg0Movement.counter, 8) == 0)
            gBg0Movement.yOffset--;
    }

    gBg0Movement.counter++;
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

    yScroll = BG3_SCROLLING_TYPE_NONE;
    xScroll = BG3_SCROLLING_TYPE_NONE;

    switch (gCurrentRoomEntry.Bg3Scrolling)
    {
        case 0:
            break;

        case 1:
            xScroll = BG3_SCROLLING_TYPE_HALVED;
            yScroll = BG3_SCROLLING_TYPE_NONE;
            break;

        case 2:
            xScroll = BG3_SCROLLING_TYPE_NONE;
            yScroll = BG3_SCROLLING_TYPE_HALVED;
            break;

        case 3:
            xScroll = BG3_SCROLLING_TYPE_HALVED;
            yScroll = BG3_SCROLLING_TYPE_HALVED;
            break;

        case 4:
            xScroll = BG3_SCROLLING_TYPE_NORMAL;
            yScroll = BG3_SCROLLING_TYPE_HALVED;
            break;

        case 5:
            xScroll = BG3_SCROLLING_TYPE_HALVED;
            yScroll = BG3_SCROLLING_TYPE_NORMAL;
            break;

        case 6:
        case 10:
            xScroll = BG3_SCROLLING_TYPE_NORMAL;
            yScroll = BG3_SCROLLING_TYPE_NORMAL;
            break;
        
        case 9:
            xScroll = BG3_SCROLLING_TYPE_QUARTERED;
            yScroll = BG3_SCROLLING_TYPE_NONE;
            break;

        case 7:
        case 8:
            xScroll = BG3_SCROLLING_TYPE_NORMAL;
            yScroll = BG3_SCROLLING_TYPE_NONE;
    }

    return C_32_2_16(yScroll, xScroll);
}

/**
 * @brief 58da0 | 124 | Scrolls the background 3
 * 
 */
void ScrollBg3(void)
{
    s32 xScrolling;
    s32 yScrolling;
    s32 offset;
    s32 size;

    // Get scrolling values
    yScrolling = ScrollGetBG3Scroll();
    xScrolling = LOW_BYTE(yScrolling);
    yScrolling = HIGH_SHORT(yScrolling);

    if (xScrolling != BG3_SCROLLING_TYPE_NONE)
    {
        if (xScrolling == BG3_SCROLLING_TYPE_NORMAL)
            gBg3XPosition = gBg1XPosition - BLOCK_SIZE * 2;
        else if (xScrolling == BG3_SCROLLING_TYPE_HALVED)
            gBg3XPosition = DIV_SHIFT(gBg1XPosition - BLOCK_SIZE * 2, 2);
        else if (xScrolling == BG3_SCROLLING_TYPE_QUARTERED)
            gBg3XPosition = DIV_SHIFT(gBg1XPosition - BLOCK_SIZE * 2, 4);
    }

    if (gCurrentRoomEntry.BG3FromBottomFlag)
    {
        size = BLOCK_TO_SUB_PIXEL(gBgPointersAndDimensions.clipdataHeight - (SCREEN_SIZE_Y_BLOCKS + 2));

        if (gCurrentRoomEntry.Bg3Size & 2)
            offset = 0x800;
        else
            offset = 0x400;

        offset -= 0x280;

        if (yScrolling == BG3_SCROLLING_TYPE_NONE)
        {
            offset = 0;
            size = 0;
        }
        else if (yScrolling == BG3_SCROLLING_TYPE_NORMAL)
            size -= gBg1YPosition;
        else
            size = DIV_SHIFT(size - gBg1YPosition, 4);
        
        if (offset - size > 0)
            gBg3YPosition = offset - size;
        else
            gBg3YPosition = 0;
    }
    else
    {
        if (yScrolling == BG3_SCROLLING_TYPE_NONE)
            gBg3YPosition = 0;
        else if (yScrolling == BG3_SCROLLING_TYPE_NORMAL)
            gBg3YPosition = gBg1YPosition - BLOCK_SIZE * 2;
        else if (yScrolling == BG3_SCROLLING_TYPE_HALVED)
            gBg3YPosition = DIV_SHIFT(gBg1YPosition - BLOCK_SIZE * 2, 2);
        else
            gBg3YPosition = DIV_SHIFT(gBg1YPosition - BLOCK_SIZE * 2, 4);
    }
}

/**
 * @brief 58ec4 | 50 | To document
 * 
 */
void ScrollBg3Related(void)
{
    u32 xScroll;

    xScroll = LOW_BYTE(ScrollGetBG3Scroll());

    if (xScroll == BG3_SCROLLING_TYPE_NONE)
        gBg3XPosition = 0;
    else if (xScroll == BG3_SCROLLING_TYPE_HALVED)
        gBg3XPosition = DIV_SHIFT(gBg1XPosition - BLOCK_SIZE * 2, 2);
    else if (xScroll == BG3_SCROLLING_TYPE_QUARTERED)
        gBg3XPosition = DIV_SHIFT(gBg1XPosition - BLOCK_SIZE * 2, 4);
}

/**
 * @brief 58f14 | 2c | Handles the automatic scrolling of the background 3
 * 
 */
void ScrollAutoBg3(void)
{
    if (gBg3Movement.active == TRUE)
    {
        if (MOD_AND(gBg3Movement.counter, 8) == 0)
            gBg3Movement.xOffset++;
    }

    gBg3Movement.counter++;
}

/**
 * @brief 58f40 | c8 | Scrolls the BG2
 * 
 * @param pCoords Coordinates pointer
 */
void ScrollBg2(struct RawCoordsX* pCoords)
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
                position = gBg1XPosition + gBg2Movement.xOffset;
                if (position < 0)
                    position = 0;
                else
                {
                    size = (gBgPointersAndDimensions.backgrounds[2].width - SCREEN_SIZE_X_BLOCKS) * BLOCK_SIZE;
                    if (size < position)
                        position = size;
                }

                gBg2XPosition = position;

                position = gBg1YPosition + gBg2Movement.yOffset;
                if (position < 0)
                    position = 0;
                else
                {
                    size = (gBgPointersAndDimensions.backgrounds[2].height - SCREEN_SIZE_Y_BLOCKS) * BLOCK_SIZE;
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
 * @brief 59008 | a8 | Handle the free movement camera lock functionality
 * 
 * @param pCoords Coords pointer
 */
void ScrollFreeMovementDebugCameraLock(struct RawCoordsX* pCoords)
{
    if (pCoords->x < BLOCK_SIZE * 7 + HALF_BLOCK_SIZE)
    {
        gBg1XPosition = 0;
    }
    else if (pCoords->x > BLOCK_TO_SUB_PIXEL(gBgPointersAndDimensions.backgrounds[1].width) - SCROLL_X_ANCHOR)
    {
        gBg1XPosition = BLOCK_TO_SUB_PIXEL(gBgPointersAndDimensions.backgrounds[1].width) - SCREEN_SIZE_X_SUB_PIXEL;
    }
    else
    {
        gBg1XPosition = pCoords->x - SCROLL_X_ANCHOR;
    }

    if (pCoords->y < SCROLL_Y_ANCHOR)
    {
        gBg1YPosition = 0;
    }
    else if (pCoords->y > BLOCK_TO_SUB_PIXEL(gBgPointersAndDimensions.backgrounds[1].height) - SCROLL_Y_ANCHOR / 2)
    {
        gBg1YPosition = BLOCK_TO_SUB_PIXEL(gBgPointersAndDimensions.backgrounds[1].height) - (BLOCK_SIZE * 9);
    }
    else
    {
        gBg1YPosition = pCoords->y - SCROLL_Y_ANCHOR;
    }
}
