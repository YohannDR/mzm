#include "minimap.h"
#include "gba.h"
#include "macros.h"

#include "data/shortcut_pointers.h"
#include "data/engine_pointers.h"
#include "data/menus/pause_screen_data.h"
#include "data/menus/pause_screen_map_data.h"
#include "data/menus/internal_pause_screen_data.h"

#include "constants/connection.h"
#include "constants/game_state.h"
#include "constants/minimap.h"

#include "structs/bg_clip.h"
#include "structs/game_state.h"
#include "structs/minimap.h"
#include "structs/samus.h"
#include "structs/room.h"

/**
 * @brief 6c154 | 24 | Updates the minimap
 * 
 */
void MinimapUpdate(void)
{
    MinimapCheckForUnexploredTile();
    if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_LOWER_LINE)
    {
        MinimapSetTileAsExplored();
        MinimapUpdateForExploredTiles();
    }
    MinimapDraw();
}

/**
 * @brief 6c178 | 4c | Sets the current minimap tile to be explored
 * 
 */
void MinimapSetTileAsExplored(void)
{
    u32 offset;
    if (!gShipLandingFlag)
    {
        offset = gCurrentArea * MINIMAP_SIZE + gMinimapY; 
        sVisitedMinimapTilesPointer[offset] |= sExploredMinimapBitFlags[gMinimapX];
    }
}

#ifdef NON_MATCHING
void MinimapCheckSetAreaNameAsExplored(u8 afterTransition)
{
    // https://decomp.me/scratch/lc52R
    
    u32 set;
    s32 i;
    s32 j;
    u32 area;
    u32 xPosition;
    u32 yPosition;
    u16* pMap;
    u32 actualX;
    u32 actualY;
    u32 tile;
    u32 offset;

    if (gShipLandingFlag)
        return;

    if (gLastAreaNameVisited.flags == 0)
        return;

    set = 0;
    i = 0;

    if (afterTransition == TRUE)
    {
        if (gLastAreaNameVisited.flags & 0x80)
        {
            i = gLastAreaNameVisited.flags & 0x7F;
            if (sMinimapAreaNames[i].area1 == gAreaBeforeTransition)
                set = 1;
            else if (sMinimapAreaNames[i].area2 == gAreaBeforeTransition)
                set = 2;
        }
    }
    else
    {
        for (i = 0; sMinimapAreaNames[i].area1 != UCHAR_MAX; i++)
        {
            if (sMinimapAreaNames[i].area1 == gLastAreaNameVisited.area)
            {
                if (gLastAreaNameVisited.mapX == sMinimapAreaNames[i].mapX1 && gLastAreaNameVisited.mapY == sMinimapAreaNames[i].mapY1)
                    set = 1;
            }
            else if (sMinimapAreaNames[i].area2 == gLastAreaNameVisited.area)
            {
                if (gLastAreaNameVisited.mapX == sMinimapAreaNames[i].mapX2 && gLastAreaNameVisited.mapY == sMinimapAreaNames[i].mapY2)
                    set = 2;
            }

            if (set != 0)
                break;
        }

        if (set != 0)
            gLastAreaNameVisited.flags = i | 0x80;
    }

    if (set == 1)
    {
        area = sMinimapAreaNames[i].area1;
        xPosition = sMinimapAreaNames[i].mapX1;
        actualX = xPosition + sMinimapAreaNames[i].xOffset1 - 1;
        yPosition = sMinimapAreaNames[i].mapY1;
        actualY = yPosition + sMinimapAreaNames[i].yOffset1 - 1;
    }
    else if (set == 2)
    {
        area = sMinimapAreaNames[i].area2;
        xPosition = sMinimapAreaNames[i].mapX2;
        actualX = xPosition + sMinimapAreaNames[i].xOffset2 - 1;
        yPosition = sMinimapAreaNames[i].mapY2;
        actualY = yPosition + sMinimapAreaNames[i].yOffset2 - 1;
    }
    else
    {
        gLastAreaNameVisited.flags = 0;
        return;
    }

    do {
    gLastAreaNameVisited.mapX = --xPosition;
    }while(0);
    gLastAreaNameVisited.mapY = --yPosition;

    //pMap = &gDecompressedMinimapData[actualX + actualY * MINIMAP_SIZE];
    pMap = &((u16*)(0x02034800))[actualX + actualY * MINIMAP_SIZE];

    offset = area * MINIMAP_SIZE + actualY;

    for (j = 0, i = 0; i < MINIMAP_SIZE; i++, pMap++)
    {
        set = *pMap & 0x3FF;
        tile = set - 0x141;
        if (tile <= 0x1D)
        {
            sVisitedMinimapTilesPointer[offset] |= sExploredMinimapBitFlags[actualX + j];
            j++;
        }
        else
        {
            break;
        }
    }

    if (afterTransition)
    {
        offset = area * MINIMAP_SIZE + gLastAreaNameVisited.mapY;
        sVisitedMinimapTilesPointer[offset] |= sExploredMinimapBitFlags[gLastAreaNameVisited.mapX];
        gLastAreaNameVisited.flags = 0;
    }
}
#else
NAKED_FUNCTION
void MinimapCheckSetAreaNameAsExplored(u8 afterTransition)
{
    asm(" \n\
    push {r4, r5, r6, r7, lr} \n\
    mov r7, sl \n\
    mov r6, sb \n\
    mov r5, r8 \n\
    push {r5, r6, r7} \n\
    sub sp, #4 \n\
    lsl r0, r0, #0x18 \n\
    lsr r0, r0, #0x18 \n\
    str r0, [sp] \n\
    ldr r0, lbl_0806c21c @ =gShipLandingFlag \n\
    ldrb r0, [r0] \n\
    cmp r0, #0 \n\
    beq lbl_0806c1e0 \n\
    b lbl_0806c372 \n\
lbl_0806c1e0: \n\
    ldr r0, lbl_0806c220 @ =gLastAreaNameVisited \n\
    ldrb r1, [r0] \n\
    mov ip, r0 \n\
    cmp r1, #0 \n\
    bne lbl_0806c1ec \n\
    b lbl_0806c372 \n\
lbl_0806c1ec: \n\
    movs r4, #0 \n\
    movs r6, #0 \n\
    ldr r0, [sp] \n\
    cmp r0, #1 \n\
    bne lbl_0806c236 \n\
    movs r0, #0x80 \n\
    and r0, r1 \n\
    cmp r0, #0 \n\
    beq lbl_0806c2a6 \n\
    movs r6, #0x7f \n\
    and r6, r1 \n\
    ldr r1, lbl_0806c224 @ =sMinimapAreaNames \n\
    lsl r0, r6, #1 \n\
    add r0, r0, r6 \n\
    lsl r0, r0, #2 \n\
    add r3, r0, r1 \n\
    ldr r0, lbl_0806c228 @ =gAreaBeforeTransition \n\
    ldrb r1, [r3] \n\
    ldrb r2, [r0] \n\
    cmp r1, r2 \n\
    bne lbl_0806c22c \n\
    movs r4, #1 \n\
    b lbl_0806c2a6 \n\
    .align 2, 0 \n\
lbl_0806c21c: .4byte gShipLandingFlag \n\
lbl_0806c220: .4byte gLastAreaNameVisited \n\
lbl_0806c224: .4byte sMinimapAreaNames \n\
lbl_0806c228: .4byte gAreaBeforeTransition \n\
lbl_0806c22c: \n\
    ldrb r0, [r3, #5] \n\
    cmp r0, r2 \n\
    bne lbl_0806c2a6 \n\
    movs r4, #2 \n\
    b lbl_0806c2a6 \n\
lbl_0806c236: \n\
    ldr r1, lbl_0806c264 @ =sMinimapAreaNames \n\
    mov r8, r1 \n\
    ldrb r0, [r1] \n\
    cmp r0, #0xff \n\
    beq lbl_0806c294 \n\
    mov r5, ip \n\
    ldrb r2, [r5, #1] \n\
    movs r3, #0 \n\
lbl_0806c246: \n\
    ldrb r0, [r1] \n\
    cmp r0, r2 \n\
    bne lbl_0806c268 \n\
    mov r7, ip \n\
    ldrb r0, [r7, #2] \n\
    ldrb r7, [r1, #1] \n\
    cmp r0, r7 \n\
    bne lbl_0806c280 \n\
    ldrb r0, [r5, #3] \n\
    ldrb r7, [r1, #2] \n\
    cmp r0, r7 \n\
    bne lbl_0806c280 \n\
    movs r4, #1 \n\
    b lbl_0806c298 \n\
    .align 2, 0 \n\
lbl_0806c264: .4byte sMinimapAreaNames \n\
lbl_0806c268: \n\
    ldrb r0, [r1, #5] \n\
    cmp r0, r2 \n\
    bne lbl_0806c280 \n\
    ldrb r0, [r5, #2] \n\
    ldrb r7, [r1, #6] \n\
    cmp r0, r7 \n\
    bne lbl_0806c280 \n\
    ldrb r0, [r5, #3] \n\
    ldrb r7, [r1, #7] \n\
    cmp r0, r7 \n\
    bne lbl_0806c280 \n\
    movs r4, #2 \n\
lbl_0806c280: \n\
    cmp r4, #0 \n\
    bne lbl_0806c298 \n\
    add r3, #0xc \n\
    add r1, #0xc \n\
    add r6, #1 \n\
    mov r7, r8 \n\
    add r0, r3, r7 \n\
    ldrb r0, [r0] \n\
    cmp r0, #0xff \n\
    bne lbl_0806c246 \n\
lbl_0806c294: \n\
    cmp r4, #0 \n\
    beq lbl_0806c2a6 \n\
lbl_0806c298: \n\
    movs r0, #0x80 \n\
    neg r0, r0 \n\
    add r1, r0, #0 \n\
    add r0, r6, #0 \n\
    orr r0, r1 \n\
    mov r1, ip \n\
    strb r0, [r1] \n\
lbl_0806c2a6: \n\
    cmp r4, #1 \n\
    bne lbl_0806c2cc \n\
    ldr r0, lbl_0806c2c8 @ =sMinimapAreaNames \n\
    lsl r1, r6, #1 \n\
    add r1, r1, r6 \n\
    lsl r1, r1, #2 \n\
    add r1, r1, r0 \n\
    ldrb r5, [r1] \n\
    ldrb r3, [r1, #1] \n\
    movs r0, #3 \n\
    ldrsb r0, [r1, r0] \n\
    add r0, r3, r0 \n\
    sub r4, r0, #1 \n\
    ldrb r2, [r1, #2] \n\
    movs r0, #4 \n\
    ldrsb r0, [r1, r0] \n\
    b lbl_0806c2f4 \n\
    .align 2, 0 \n\
lbl_0806c2c8: .4byte sMinimapAreaNames \n\
lbl_0806c2cc: \n\
    cmp r4, #2 \n\
    beq lbl_0806c2d8 \n\
    movs r0, #0 \n\
    mov r1, ip \n\
    strb r0, [r1] \n\
    b lbl_0806c372 \n\
lbl_0806c2d8: \n\
    ldr r0, lbl_0806c384 @ =sMinimapAreaNames \n\
    lsl r1, r6, #1 \n\
    add r1, r1, r6 \n\
    lsl r1, r1, #2 \n\
    add r1, r1, r0 \n\
    ldrb r5, [r1, #5] \n\
    ldrb r3, [r1, #6] \n\
    movs r0, #8 \n\
    ldrsb r0, [r1, r0] \n\
    add r0, r3, r0 \n\
    sub r4, r0, #1 \n\
    ldrb r2, [r1, #7] \n\
    movs r0, #9 \n\
    ldrsb r0, [r1, r0] \n\
lbl_0806c2f4: \n\
    add r0, r2, r0 \n\
    sub r1, r0, #1 \n\
    sub r3, #1 \n\
    mov r7, ip \n\
    strb r3, [r7, #2] \n\
    sub r2, #1 \n\
    strb r2, [r7, #3] \n\
    lsl r0, r1, #5 \n\
    add r0, r4, r0 \n\
    lsl r0, r0, #1 \n\
    ldr r2, lbl_0806c388 @ =0x02034800 \n\
    add r3, r0, r2 \n\
    lsl r0, r5, #5 \n\
    add r5, r0, r1 \n\
    movs r6, #0 \n\
    mov sl, r0 \n\
    ldr r1, lbl_0806c38c @ =sExploredMinimapBitFlags \n\
    lsl r0, r4, #2 \n\
    add r7, r0, r1 \n\
    ldr r0, lbl_0806c390 @ =0xfffffebf \n\
    mov sb, r0 \n\
    ldr r1, lbl_0806c394 @ =sVisitedMinimapTilesPointer \n\
    mov r8, r1 \n\
lbl_0806c322: \n\
    ldrh r0, [r3] \n\
    ldr r4, lbl_0806c398 @ =0x000003ff \n\
    and r4, r0 \n\
    mov r2, sb \n\
    add r0, r4, r2 \n\
    cmp r0, #0x1d \n\
    bhi lbl_0806c348 \n\
    mov r1, r8 \n\
    ldr r0, [r1] \n\
    lsl r2, r5, #2 \n\
    add r2, r2, r0 \n\
    ldr r0, [r2] \n\
    ldm r7!, {r1} \n\
    orr r0, r1 \n\
    str r0, [r2] \n\
    add r6, #1 \n\
    add r3, #2 \n\
    cmp r6, #0x1f \n\
    ble lbl_0806c322 \n\
lbl_0806c348: \n\
    ldr r2, [sp] \n\
    cmp r2, #0 \n\
    beq lbl_0806c372 \n\
    mov r3, ip \n\
    ldrb r0, [r3, #3] \n\
    mov r7, sl \n\
    add r5, r7, r0 \n\
    ldr r0, lbl_0806c394 @ =sVisitedMinimapTilesPointer \n\
    ldr r0, [r0] \n\
    lsl r2, r5, #2 \n\
    add r2, r2, r0 \n\
    ldr r1, lbl_0806c38c @ =sExploredMinimapBitFlags \n\
    ldrb r0, [r3, #2] \n\
    lsl r0, r0, #2 \n\
    add r0, r0, r1 \n\
    ldr r1, [r2] \n\
    ldr r0, [r0] \n\
    orr r1, r0 \n\
    str r1, [r2] \n\
    movs r0, #0 \n\
    strb r0, [r3] \n\
lbl_0806c372: \n\
    add sp, #4 \n\
    pop {r3, r4, r5} \n\
    mov r8, r3 \n\
    mov sb, r4 \n\
    mov sl, r5 \n\
    pop {r4, r5, r6, r7} \n\
    pop {r0} \n\
    bx r0 \n\
    .align 2, 0 \n\
lbl_0806c384: .4byte sMinimapAreaNames \n\
lbl_0806c388: .4byte 0x02034800 \n\
lbl_0806c38c: .4byte sExploredMinimapBitFlags \n\
lbl_0806c390: .4byte 0xfffffebf \n\
lbl_0806c394: .4byte sVisitedMinimapTilesPointer \n\
lbl_0806c398: .4byte 0x000003ff \n\
    ");
}
#endif

/**
 * @brief 6c39c | d8 | Checks if Samus is on an unexplored minimap tile
 * 
 */
void MinimapCheckForUnexploredTile(void)
{
    u16 samusX;
    u16 samusY;
    u16 clipPosition;

    if (gUpdateMinimapFlag != MINIMAP_UPDATE_FLAG_NONE)
        return;

    samusX = gSamusData.xPosition - BLOCK_SIZE * 2;
    samusY = gSamusData.yPosition - BLOCK_SIZE * 2;

    if (samusX & 0x8000) // X < 0
        samusX = 0;
    else
    {
        clipPosition = gBgPointersAndDimensions.clipdataWidth * BLOCK_SIZE;
        clipPosition -= BLOCK_SIZE * 4;

        if (gSamusData.xPosition >= clipPosition)
            samusX = clipPosition - ONE_SUB_PIXEL;
    }

    if (samusY & 0x8000) // Y < 0
        samusY = 0;
    else
    {
        clipPosition = gBgPointersAndDimensions.clipdataHeight * BLOCK_SIZE;
        clipPosition -= BLOCK_SIZE * 4;

        if (gSamusData.yPosition >= clipPosition)
            samusY = clipPosition - ONE_SUB_PIXEL;
    }

    // Convert to block
    samusX /= BLOCK_SIZE;
    samusY /= BLOCK_SIZE;

    samusX /= SCREEN_SIZE_X_BLOCKS;
    samusY /= SCREEN_SIZE_Y_BLOCKS;

    // Check update X coords
    if (gMinimapX != samusX + gCurrentRoomEntry.mapX)
    {
        gMinimapX = samusX + gCurrentRoomEntry.mapX;
        gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_LOWER_LINE;
    }

    // Check update Y coords
    if (gMinimapY != samusY + gCurrentRoomEntry.mapY)
    {
        gMinimapY = samusY + gCurrentRoomEntry.mapY;
        gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_LOWER_LINE;
    }
}

/**
 * @brief 6c474 | a4 | Updates the minimap when taking a transition
 * 
 */
void MinimapCheckOnTransition(void)
{
    if (gAreaBeforeTransition != gCurrentArea)
    {
        // New area
        MinimapCheckSetAreaNameAsExplored(FALSE);

        // Get new minimap
        gAreaBeforeTransition = gCurrentArea;
        PauseScreenGetMinimapData(gAreaBeforeTransition, gDecompressedMinimapData); // Undefined

        DMA_SET(3, gDecompressedMinimapData, gDecompressedMinimapVisitedTiles, C_32_2_16(DMA_ENABLE, MINIMAP_SIZE * MINIMAP_SIZE));

        MinimapCheckSetAreaNameAsExplored(TRUE);
        MinimapSetDownloadedTiles(gAreaBeforeTransition, gDecompressedMinimapVisitedTiles);

        // Clear coords
        gMinimapX = UCHAR_MAX;
        gMinimapY = UCHAR_MAX;
    }

    // Check for transition tile
    gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_NONE;
    MinimapCheckForUnexploredTile();

    if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_LOWER_LINE)
    {
        MinimapSetTileAsExplored();
        MinimapUpdateForExploredTiles();
    }

    // Full redraw
    gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_UPPER_LINE;
    MinimapDraw();

    gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_MIDDLE_LINE;
    MinimapDraw();

    gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_LOWER_LINE;
    MinimapDraw();
}

/**
 * @brief 6c518 | 9c | Updates the minimap for the explored tiles
 * 
 */
void MinimapUpdateForExploredTiles(void)
{
    u32 offset;
    u32 tile;
    u16* map;
    u16* tiles;

    if (gShipLandingFlag)
        return;

    offset = gMinimapX + gMinimapY * MINIMAP_SIZE;
    // FIXME use symbol
    tiles = (u16*)0x2034000 + offset; // gDecompressedMinimapVisitedTiles
    
    if (!(*tiles & 0xF000))
    {
        // FIXME use symbol
        map = (u16*)0x2034800 + offset; // gDecompressedMinimapData
        if (*map & 0xF000)
            *tiles = *map;
        else
            *tiles = *map | 0x1000;

        tile = (*map & 0x3FF) - 0x141;
        if (tile < 0x4)
        {
            gLastAreaNameVisited.flags = TRUE;
            gLastAreaNameVisited.area = gCurrentArea;
            gLastAreaNameVisited.mapX = gMinimapX + 1;
            gLastAreaNameVisited.mapY = gMinimapY + 1;
        }
    }
}

#ifdef NON_MATCHING
void MinimapDraw(void)
{
    // https://decomp.me/scratch/EaJoP

    s32 yOffset;
    s32 xOffset;
    s32 xPosition;
    s32 yPosition;
    u32 limit;
    u32* dst;
    u16 rawTile;
    u16 tile;
    u8 palette;
    u32 flip;
    u16* src;
    u32 offset;

    if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_NONE)
        return;
    
    src = (u16*)0x2034000;
    dst = (u32*)0x2037e20 + (gUpdateMinimapFlag - 1) * 24;

    if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_LOWER_LINE)
        yOffset = 1;
    else if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_MIDDLE_LINE)
        yOffset = 0;
    else if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_UPPER_LINE)
        yOffset = -1;
    else
    {
        gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_NONE;
        return;
    }

    for (xOffset = -1; xOffset < 2; xOffset++, dst += 8)
    {
        limit = MINIMAP_SIZE - 1;

        xPosition = gMinimapX + xOffset;
        if (xPosition > limit)
            xPosition = -1;

        yPosition = gMinimapY + yOffset;
        if (yPosition > limit)
            yPosition = -1;

        if (yPosition < 0 || xPosition < 0)
        {
            xPosition = limit;
            yPosition = limit;
        }

        offset = yPosition * MINIMAP_SIZE + xPosition;
        flip = (src[offset] & 0xC00) >> 0xA;
        palette = src[offset] >> 0xC;
        tile = src[offset] & 0x3ff;
        
        if (gLanguage == LANGUAGE_HIRAGANA && tile > MINIMAP_TILE_BACKGROUND)
            tile += 0x20;

        tile <<= 0x5;
        sMinimapTilesCopyGfxFunctionPointers[flip](dst, &tile, palette);
    }
}
#else
NAKED_FUNCTION
void MinimapDraw(void)
{
    asm(" \n\
    push {r4, r5, r6, r7, lr} \n\
    mov r7, sb \n\
    mov r6, r8 \n\
    push {r6, r7} \n\
    sub sp, #4 \n\
    ldr r3, lbl_0806c5e4 @ =gUpdateMinimapFlag \n\
    ldrb r0, [r3] \n\
    cmp r0, #0 \n\
    beq lbl_0806c690 \n\
    ldr r0, lbl_0806c5e8 @ =0x02034000 \n\
    mov r8, r0 \n\
    ldrb r2, [r3] \n\
    sub r1, r2, #1 \n\
    lsl r0, r1, #1 \n\
    add r0, r0, r1 \n\
    lsl r0, r0, #5 \n\
    ldr r1, lbl_0806c5ec @ =0x02037e20 \n\
    add r6, r0, r1 \n\
    cmp r2, #3 \n\
    bne lbl_0806c5f0 \n\
    movs r7, #1 \n\
    mov sb, r7 \n\
    b lbl_0806c60a \n\
    .align 2, 0 \n\
lbl_0806c5e4: .4byte gUpdateMinimapFlag \n\
lbl_0806c5e8: .4byte 0x02034000 \n\
lbl_0806c5ec: .4byte 0x02037e20 \n\
lbl_0806c5f0: \n\
    cmp r2, #2 \n\
    bne lbl_0806c5fa \n\
    movs r0, #0 \n\
    mov sb, r0 \n\
    b lbl_0806c60a \n\
lbl_0806c5fa: \n\
    cmp r2, #1 \n\
    beq lbl_0806c604 \n\
    movs r0, #0 \n\
    strb r0, [r3] \n\
    b lbl_0806c690 \n\
lbl_0806c604: \n\
    movs r1, #1 \n\
    neg r1, r1 \n\
    mov sb, r1 \n\
lbl_0806c60a: \n\
    movs r5, #1 \n\
    neg r5, r5 \n\
    mov r4, sp \n\
lbl_0806c610: \n\
    ldr r0, lbl_0806c6a0 @ =gMinimapX \n\
    ldrb r0, [r0] \n\
    add r1, r0, r5 \n\
    cmp r1, #0x1f \n\
    bls lbl_0806c61e \n\
    movs r1, #1 \n\
    neg r1, r1 \n\
lbl_0806c61e: \n\
    ldr r0, lbl_0806c6a4 @ =gMinimapY \n\
    ldrb r0, [r0] \n\
    add r0, sb \n\
    cmp r0, #0x1f \n\
    bls lbl_0806c62c \n\
    movs r0, #1 \n\
    neg r0, r0 \n\
lbl_0806c62c: \n\
    cmp r0, #0 \n\
    blt lbl_0806c634 \n\
    cmp r1, #0 \n\
    bge lbl_0806c638 \n\
lbl_0806c634: \n\
    movs r1, #0x1f \n\
    movs r0, #0x1f \n\
lbl_0806c638: \n\
    lsl r0, r0, #5 \n\
    add r0, r0, r1 \n\
    lsl r0, r0, #1 \n\
    add r0, r8 \n\
    movs r7, #0xc0 \n\
    lsl r7, r7, #4 \n\
    add r2, r7, #0 \n\
    ldrh r1, [r0] \n\
    add r0, r1, #0 \n\
    and r0, r2 \n\
    lsr r3, r0, #0xa \n\
    lsr r2, r1, #0xc \n\
    ldr r7, lbl_0806c6a8 @ =0x000003ff \n\
    add r0, r7, #0 \n\
    and r1, r0 \n\
    strh r1, [r4] \n\
    ldr r0, lbl_0806c6ac @ =gLanguage \n\
    ldrb r0, [r0] \n\
    lsl r0, r0, #0x18 \n\
    asr r0, r0, #0x18 \n\
    cmp r0, #1 \n\
    bne lbl_0806c672 \n\
    movs r0, #0xa0 \n\
    lsl r0, r0, #1 \n\
    cmp r1, r0 \n\
    bls lbl_0806c672 \n\
    add r0, r1, #0 \n\
    add r0, #0x20 \n\
    strh r0, [r4] \n\
lbl_0806c672: \n\
    ldrh r0, [r4] \n\
    lsl r0, r0, #5 \n\
    strh r0, [r4] \n\
    ldr r1, lbl_0806c6b0 @ =sMinimapTilesCopyGfxFunctionPointers \n\
    lsl r0, r3, #2 \n\
    add r0, r0, r1 \n\
    ldr r3, [r0] \n\
    add r0, r6, #0 \n\
    mov r1, sp \n\
    bl _call_via_r3 \n\
    add r5, #1 \n\
    add r6, #0x20 \n\
    cmp r5, #1 \n\
    ble lbl_0806c610 \n\
lbl_0806c690: \n\
    add sp, #4 \n\
    pop {r3, r4} \n\
    mov r8, r3 \n\
    mov sb, r4 \n\
    pop {r4, r5, r6, r7} \n\
    pop {r0} \n\
    bx r0 \n\
    .align 2, 0 \n\
lbl_0806c6a0: .4byte gMinimapX \n\
lbl_0806c6a4: .4byte gMinimapY \n\
lbl_0806c6a8: .4byte 0x000003ff \n\
lbl_0806c6ac: .4byte gLanguage \n\
lbl_0806c6b0: .4byte sMinimapTilesCopyGfxFunctionPointers \n\
    ");
}
#endif

/**
 * @brief 6c6b4 | d8 | Copies the graphics of a map tile
 * 
 * @param dst Destination pointer
 * @param pTile Tile pointer
 * @param palette Palette
 */
void MinimapCopyTileGfx(u32* dst, u16* pTile, u8 palette)
{
    s32 i;
    u32 value;
    u32 tile;

    for (i = 0; i < 8; i++)
    {
        tile = sMinimapTilesGfx[*pTile];
        value = (sPauseScreen_40d74c[(tile / 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile % 16) + (palette << 4)]);
        (*pTile)++;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile / 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile % 16) + (palette << 4)]) << 8;
        (*pTile)++;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile / 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile % 16) + (palette << 4)]) << 16;
        (*pTile)++;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile / 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile % 16) + (palette << 4)]) << 24;
        (*pTile)++;

        *dst++ = value;
    }
}

/**
 * @brief 6c78c | ec | Copies the graphics of a map tile (X flipped)
 * 
 * @param dst Destination pointer
 * @param pTile Tile pointer
 * @param palette Palette
 */
void MinimapCopyTileXFlippedGfx(u32* dst, u16* pTile, u8 palette)
{
    s32 i;
    u32 value;
    u32 tile;

    for (i = 0; i < 8; i++)
    {
        *pTile += 3;

        tile = sMinimapTilesGfx[*pTile];
        value = (sPauseScreen_40d74c[(tile % 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile / 16) + (palette << 4)]);
        (*pTile)--;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile % 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile / 16) + (palette << 4)]) << 8;
        (*pTile)--;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile % 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile / 16) + (palette << 4)]) << 16;
        (*pTile)--;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile % 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile / 16) + (palette << 4)]) << 24;

        *dst++ = value;
        
        *pTile += 4;
    }
}

/**
 * @brief 6c878 | dc | Copies the graphics of a map tile (Y flipped)
 * 
 * @param dst Destination pointer
 * @param pTile Tile pointer
 * @param palette Palette
 */
void MinimapCopyTileYFlippedGfx(u32* dst, u16* pTile, u8 palette)
{
    s32 i;
    u32 value;
    u32 tile;
    
    *pTile += 28;
    
    for (i = 0; i < 8; i++)
    {
        tile = sMinimapTilesGfx[*pTile];
        value = (sPauseScreen_40d74c[(tile / 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile % 16) + (palette << 4)]);
        (*pTile)++;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile / 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile % 16) + (palette << 4)]) << 8;
        (*pTile)++;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile / 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile % 16) + (palette << 4)]) << 16;
        (*pTile)++;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile / 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile % 16) + (palette << 4)]) << 24;

        *dst++ = value;
        *pTile -= 7;
    }
}

/**
 * @brief 6c954 | f0 | Copies the graphics of a map tile (X/Y flipped)
 * 
 * @param dst Destination pointer
 * @param pTile Tile pointer
 * @param palette Palette
 */
void MinimapCopyTileXYFlippedGfx(u32* dst, u16* pTile, u8 palette)
{
    s32 i;
    u32 value;
    u32 tile;

    // Macro
    do{
        *pTile += 31;
    }while(0);
    
    for (i = 0; i < 8; i++)
    {
        tile = sMinimapTilesGfx[*pTile];
        value = (sPauseScreen_40d74c[(tile % 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile / 16) + (palette << 4)]);
        (*pTile)--;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile % 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile / 16) + (palette << 4)]) << 8;
        (*pTile)--;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile % 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile / 16) + (palette << 4)]) << 16;
        (*pTile)--;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile % 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile / 16) + (palette << 4)]) << 24;
        (*pTile)--;

        *dst++ = value;
        
    }
}

/**
 * @brief 6ca44 | 6c | Updates the tiles of a minimap with obtained items
 * 
 * @param area Area
 * @param dst Destination pointer
 */
void MinimapSetTilesWithObtainedItems(u8 area, u16* dst)
{
    u32* src;
    u32 tile;
    s32 i;
    s32 j;

    if (area >= MAX_AMOUNT_OF_AREAS)
        return;

    // 0x2033800 = gMinimapTilesWithObtainedItems
    src = (u32*)(0x2033800 + area * 512 / 4);

    for (i = 0; i < MINIMAP_SIZE; i++, src++)
    {
        if (!*src)
            continue;
        
        tile = *src;
        for (j = 0; j < MINIMAP_SIZE && tile; j++)
        {
            if (tile & sExploredMinimapBitFlags[j])
            {
                tile ^= sExploredMinimapBitFlags[j];
                dst[i * MINIMAP_SIZE + j]++;
            }
        }
    }
}

/**
 * @brief 6cab0 | 128 | Updates the tiles of a minimap with the downloaded tiles
 * 
 * @param area Area
 * @param dst Destination pointer
 */
void MinimapSetDownloadedTiles(u8 area, u16* dst)
{
    u32* pVisited;
    s32 i;
    s32 j;
    u32 tmp;
    u32 tmp2;

    pVisited = &sVisitedMinimapTilesPointer[area * MINIMAP_SIZE];

    if ((gEquipment.downloadedMapStatus >> area) & 1 || (u8)(area - MAX_AMOUNT_OF_AREAS) <= 2)
    {
        for (i = 0; i < MINIMAP_SIZE; i++, pVisited++)
        {
            for (j = 0; j < MINIMAP_SIZE; j++, dst++)
            {
                tmp2 = *pVisited;
                if (sExploredMinimapBitFlags[j] & tmp2)
                {
                    if (!(*dst & 0xF000))
                        *dst |= 0x1000;
                }
                else if (*dst >= 0x3000)
                {
                    *dst = 0x140;
                }
                else if (*dst & 0x3000)
                {
                    *dst &= 0xFFF;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < MINIMAP_SIZE; i++, pVisited++)
        {
            for (j = 0; j < MINIMAP_SIZE; j++, dst++)
            {
                tmp = *pVisited;
                if (sExploredMinimapBitFlags[j] & tmp)
                {
                    if (!(*dst & 0xF000))
                        *dst |= 0x1000;
                }
                else if (*dst & 0xF000)
                {
                    *dst = 0x140;
                }
            }
        }
    }
}

/**
 * @brief 6cbd8 | 90 | Updates the minimap for a collected item
 * 
 * @param xPosition X position
 * @param yPosition Y position
 */
void MinimapUpdateForCollectedItem(u8 xPosition, u8 yPosition)
{
    u32 itemX;
    u32 itemY;
    u32 offset;
    u32 offset2;
    u32* ptr;
    u16* ptrU;

    if (gCurrentArea < MAX_AMOUNT_OF_AREAS)
    {
        itemX = (xPosition - SCREEN_X_PADDING) / SCREEN_SIZE_X_BLOCKS + gCurrentRoomEntry.mapX;
        itemY = (yPosition - SCREEN_Y_PADDING) / SCREEN_SIZE_Y_BLOCKS + gCurrentRoomEntry.mapY;

        offset = gCurrentArea * MINIMAP_SIZE;
        // FIXME use symbol
        ptr = (u32*)(0x2033800) + offset; // gMinimapTilesWithObtainedItems
        ptr[itemY] |= sExploredMinimapBitFlags[itemX];

        
        itemX += itemY * MINIMAP_SIZE;
        // FIXME use symbol
        ptrU = (u16*)0x2034000; // gDecompressedMinimapVisitedTiles
        ptrU[itemX]++;
        // FIXME use symbol
        ptrU = (u16*)0x2034800; // gDecompressedMinimapData
        ptrU[itemX]++;

        gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_LOWER_LINE;
        MinimapDraw();
    }
}

/**
 * @brief 6cc68 | 64 | Checks if a minimap has been explored
 * 
 * @param xPosition X Position
 * @param yPosition Y Position
 * @return u32 Explored bit flag
 */
u32 MinimapCheckIsTileExplored(u8 xPosition, u8 yPosition)
{
    u32 mapX;
    u32 mapY;
    u32 offset;
    u32* ptr;
    u32 tileOffset;

    if (gCurrentArea >= MAX_AMOUNT_OF_AREAS)
        return 1;

    offset = gCurrentArea * MINIMAP_SIZE;
    mapX = (xPosition - SCREEN_X_PADDING) / SCREEN_SIZE_X_BLOCKS + gCurrentRoomEntry.mapX;
    mapY = (yPosition - SCREEN_Y_PADDING) / SCREEN_SIZE_Y_BLOCKS + gCurrentRoomEntry.mapY;

    tileOffset = mapY + offset;
    return sVisitedMinimapTilesPointer[tileOffset] & sExploredMinimapBitFlags[mapX];
}

/**
 * @brief 6cccc | b8 | Sets the minimap tiles with obtained items when loading a save file
 * 
 */
void MinimapLoadTilesWithObtainedItems(void)
{
    u8 i;
    s32 j;
    s32 yPosition;
    s32 xPosition;
    struct ItemInfo* pItem;
    u32* pTiles;
    u32 xOffset;
    u32 yOffset;

    // FIXME use symbol
    BitFill(3, 0, 0x2033800, sizeof(gMinimapTilesWithObtainedItems), 16);

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
    {
        // FIXME use symbol
        pItem = ((struct ItemInfo*)0x2036c00 + i * MAX_AMOUNT_OF_ITEMS_PER_AREA); // gItemsCollected
        pTiles = ((u32*)0x2033800 + i * MINIMAP_SIZE); // gMinimapTilesWithObtainedItems

        for (j = 0; j < MINIMAP_SIZE * 2; j++, pItem++)
        {
            if (pItem->room == UCHAR_MAX)
                break;

            xPosition = (pItem->xPosition - SCREEN_X_PADDING) / SCREEN_SIZE_X_BLOCKS;
            yPosition = (pItem->yPosition - SCREEN_Y_PADDING) / SCREEN_SIZE_Y_BLOCKS;

            xOffset = xPosition + sAreaRoomEntryPointers[i][pItem->room].mapX;
            yOffset = yPosition + sAreaRoomEntryPointers[i][pItem->room].mapY;

            pTiles[yOffset] |= sExploredMinimapBitFlags[xOffset];
        }
    }
}

/**
 * @brief 6cd84 | 174 | Updates a minimap chunk/boss icon
 * 
 * @param event Event linked
 */
void MinimapUpdateChunk(u8 event)
{
    s32 i;
    u16* pMinimap;
    u16* pVisited;
    u16* pMinimapLower;
    u16* pVisitedLower;
    u16* ptr;
    u32 mask;

    for (i = 0; i < (u32)ARRAY_SIZE(sBossIcons); i++)
    {
        if (event == sBossIcons[i][0])
            break;
    }

    if (i >= ARRAY_SIZE(sBossIcons))
        return;

    if (i != gCurrentArea)
        return;

    i = sBossIcons[i][3] * MINIMAP_SIZE + sBossIcons[i][2];

    // FIXME use symbol
    pMinimap = (u16*)0x2034800 + i; // gDecompressedMinimapData
    pVisited = (u16*)0x2034000 + i; // gDecompressedMinimapVisitedTiles

    if (gCurrentArea == AREA_CRATERIA)
    {
        if ((*pMinimap & 0x3FF) == sMapChunksToUpdate[2])
        {
            mask = 0xF000;
            ptr = pVisited;
            pVisitedLower = pMinimap;
            
            for (i = 2; i >= 0; i--)
            {
                (*pVisitedLower)++;
                if (mask & *ptr)
                    (*ptr)++;
                
                ptr++;
                pVisitedLower++;
            }

            i = FALSE;
        }
        else
            i = TRUE;
    }
    else if (gCurrentArea == AREA_KRAID)
    {
        if ((*pMinimap & 0x3FF) == sMapChunksToUpdate[0])
        {
            pVisitedLower = pVisited;
            pMinimapLower = pMinimap;

            for (i = 0; i < 2; i++)
            {
                (*pMinimapLower) += 0x20;
                (*pVisitedLower) += 0x20;
                
                pVisitedLower++;
                pMinimapLower++;
            }

            pVisitedLower = pVisited;
            pVisitedLower += MINIMAP_SIZE;
            pMinimapLower = pMinimap;
            pMinimapLower += MINIMAP_SIZE;

            for (i = 0; i < 2; i++)
            {
                (*pMinimapLower) += 0x20;
                (*pVisitedLower) += 0x20;
                
                pVisitedLower++;
                pMinimapLower++;
            }

            i = FALSE;
        }
        else
            i = TRUE;
    }
    else if (gCurrentArea == AREA_RIDLEY)
    {
        if ((*pMinimap & 0x3FF) == sMapChunksToUpdate[1])
        {
            pVisitedLower = pVisited;
            pMinimapLower = pMinimap;
            for (i = 0; i < 2; i++)
            {
                (*pMinimapLower) += 0x20;
                (*pVisitedLower) += 0x20;
                
                pVisitedLower++;
                pMinimapLower++;
            }

            pVisitedLower = pVisited;
            pVisitedLower += MINIMAP_SIZE;
            pMinimapLower = pMinimap;
            pMinimapLower += MINIMAP_SIZE;

            for (i = 0; i < 2; i++)
            {
                (*pMinimapLower) += 0x20;
                (*pVisitedLower) += 0x20;
                
                pVisitedLower++;
                pMinimapLower++;
            }

            i = FALSE;
        }
        else
            i = TRUE;
    }

    if (i)
        return;

    gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_LOWER_LINE;
    MinimapDraw();
}
