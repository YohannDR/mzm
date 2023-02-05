#include "minimap.h"
#include "gba.h"
#include "macros.h"

#include "data/unsorted.h"
#include "data/shortcut_pointers.h"

#include "constants/connection.h"
#include "constants/game_state.h"
#include "constants/minimap.h"

#include "structs/bg_clip.h"
#include "structs/game_state.h"
#include "structs/minimap.h"
#include "structs/samus.h"
#include "structs/room.h"

extern const u8 sBossIcons[7][5];
extern const u16 sMapChunksToUpdate[3];

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
        offset = gCurrentArea * 32 + gMinimapY; 
        sVisitedMinimapTilesPointer[offset] |= sExploredMinimapBitFlags[gMinimapX];
    }
}

void MinimapCheckSetAreaNameAsExplored(u8 afterTransition)
{

}

/**
 * @brief 6c39c | d8 | Checks if Samus is on an unexplored minimap tile
 * 
 */
void MinimapCheckForUnexploredTile(void)
{
    u16 samusX;
    u16 samusY;
    u16 clipPosition;

    if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_NONE)
    {
        samusX = gSamusData.xPosition - BLOCK_SIZE * 2;
        samusY = gSamusData.yPosition - BLOCK_SIZE * 2;

        if (samusX & 0x8000)
            samusX = 0x0;
        else
        {
            clipPosition = gBGPointersAndDimensions.clipdataWidth * BLOCK_SIZE;
            clipPosition -= BLOCK_SIZE * 4;

            if (gSamusData.xPosition >= clipPosition)
                samusX = clipPosition - 0x1;
        }

        if (samusY & 0x8000)
            samusY = 0x0;
        else
        {
            clipPosition = gBGPointersAndDimensions.clipdataHeight * BLOCK_SIZE;
            clipPosition -= BLOCK_SIZE * 4;

            if (gSamusData.yPosition >= clipPosition)
                samusY = clipPosition - 0x1;
        }

        // Convert to block
        samusX >>= 0x6;
        samusY >>= 0x6;

        samusX /= 0xF;
        samusY /= 0xA;

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
        get_minimap_data(gAreaBeforeTransition, gDecompressedMinimapData); // Undefined

        dma_set(3, gDecompressedMinimapData, gDecompressedMinimapVisitedTiles, (DMA_ENABLE << 16) | MINIMAP_SIZE * MINIMAP_SIZE);

        MinimapCheckSetAreaNameAsExplored(TRUE);
        MinimapSetDownloadedTiles(gAreaBeforeTransition, gDecompressedMinimapVisitedTiles);

        // Clear coords
        gMinimapX = 0xFF;
        gMinimapY = 0xFF;
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

void MinimapUpdateForExploredTiles(void)
{
    // https://decomp.me/scratch/adSdZ

    u32 offset;
    u32 tile;
    u16* map;
    u16* tiles;

    if (!gShipLandingFlag)
    {
        offset = gMinimapX + gMinimapY * MINIMAP_SIZE;
        tiles = gDecompressedMinimapVisitedTiles + offset;
        
        if (!(*tiles & 0xF000))
        {
            map = gDecompressedMinimapData + offset;
            if (*map & 0xF000)
                *tiles = *map;
            else
                *tiles = *map | 0x1000;

            tile = (*map & 0x3FF) - 0x141;
            if (tile < 0x4)
            {
                gLastAreaNameVisited.flags = TRUE;
                gLastAreaNameVisited.area = gCurrentArea;
                gLastAreaNameVisited.mapX = gMinimapX + 0x1;
                gLastAreaNameVisited.mapY = gMinimapY + 0x1;
            }
        }
    }
}

void MinimapDraw(void)
{
    // https://decomp.me/scratch/DE4B1

    i32 yOffset;
    i32 xOffset;
    i32 xPosition;
    i32 yPosition;
    u32 limit;
    u32* dst;
    u16 rawTile;
    u8 flag;
    u16 tile;
    u8 palette;
    u32 flip;
    u16* src;

    if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_NONE)
        return;
    
    src = gDecompressedMinimapVisitedTiles;
    flag = gUpdateMinimapFlag;
    dst = gMinimapTilesGFX + (flag - 1) * 24;

    if (flag == MINIMAP_UPDATE_FLAG_LOWER_LINE)
        yOffset = 0x1;
    else if (flag == MINIMAP_UPDATE_FLAG_MIDDLE_LINE)
        yOffset = 0x0;
    else if (flag == MINIMAP_UPDATE_FLAG_UPPER_LINE)
        yOffset = -0x1;
    else
    {
        gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_NONE;
        return;
    }

    for (xOffset = -0x1; xOffset < 0x2;)
    {
        limit = 0x1F;
        xPosition = gMinimapX + xOffset;
        if (xPosition > limit)
            xPosition = -0x1;

        yPosition = gMinimapY + yOffset;
        if (yPosition > limit)
            yPosition = -0x1;

        if (yPosition < 0x0 || xPosition < 0x0)
        {
            xPosition = limit;
            yPosition = limit;
        }

        rawTile = src[yPosition * MINIMAP_SIZE + xPosition];
        flip = (rawTile & 0xC00) >> 0xA;
        palette = rawTile >> 0xC;
        tile = rawTile & 0x3ff;
        
        if (gLanguage == LANGUAGE_HIRAGANA && tile > 0x140)
            tile += 0x20;

        tile <<= 0x5;
        sMinimapTilesCopyGFXFunctionPointers[flip](dst, &tile, palette);

        xOffset++;
        dst += 0x8;
    }
}

void MinimapCopyTileGFX(u32* dst, u16* pTile, u8 palette)
{

}

void MinimapCopyTileXFlippedGFX(u32* dst, u16* pTile, u8 palette)
{

}

void MinimapCopyTileYFlippedGFX(u32* dst, u16* pTile, u8 palette)
{

}

void MinimapCopyTileXYFlippedGFX(u32* dst, u16* pTile, u8 palette)
{

}

void MinimapSetTilesWithObtainedItems(u8 area, u16* dst)
{
    // https://decomp.me/scratch/Eree5

    u32* src;
    u32* src2;
    u16* pDecomp;
    u32 tile;
    u32 tempTile;
    i32 i;
    i32 j;
    u32 temp;

    if (area >= MAX_AMOUNT_OF_AREAS)
        return;

    src = gMinimapTilesWithObtainedItems + area * MINIMAP_SIZE;

    for (i = 0; i < MINIMAP_SIZE;)
    {
        tile = *src++;
        temp = i + 1;
        src2 = src;
        if (tile)
        {
            tempTile = tile;
            for (j = 0; j < MINIMAP_SIZE && tempTile; j++)
            {
                if (tempTile & sExploredMinimapBitFlags[j])
                {
                    tempTile ^= sExploredMinimapBitFlags[j];
                    dst[i * MINIMAP_SIZE + j]++;
                }
            }
        }
        i = temp;
        src = src2;
    }
}

void MinimapSetDownloadedTiles(u8 area, u16* dst)
{

}

void MinimapUpdateForCollectedItem(u8 xPosition, u8 yPosition)
{
    // https://decomp.me/scratch/pFd7R

    u32 itemX;
    u32 itemY;
    u32 offset;
    u32 offset2;
    u32* ptr;
    u16* ptrU;

    if (gCurrentArea < MAX_AMOUNT_OF_AREAS)
    {
        itemX = (xPosition - 0x2) / 0xF + gCurrentRoomEntry.mapX;
        itemY = (yPosition - 0x2) / 0xA + gCurrentRoomEntry.mapY;

        offset = gCurrentArea * MINIMAP_SIZE;
        ptr = gMinimapTilesWithObtainedItems + offset;
        ptr[itemY] |= sExploredMinimapBitFlags[itemX];

        
        itemX += itemY * MINIMAP_SIZE;
        ptrU = gDecompressedMinimapVisitedTiles + itemX;
        (*ptrU)++;
        ptrU = gDecompressedMinimapData;
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
    else
    {
        offset = gCurrentArea * MINIMAP_SIZE;
        mapX = (xPosition - 0x2) / 0xF + gCurrentRoomEntry.mapX;
        mapY = (yPosition - 0x2) / 0xA + gCurrentRoomEntry.mapY;

        tileOffset = mapY + offset;
        return sVisitedMinimapTilesPointer[tileOffset] & sExploredMinimapBitFlags[mapX];
    }
}

void MinimapLoadTilesWithObtainedItems(void)
{

}

void MinimapUpdateChunk(u8 event)
{
    // https://decomp.me/scratch/J8b8P

    i32 i;
    u16* pMinimap;
    u16* pVisited;
    register u16* pMinimapLower asm("r2");
    u16* pVisitedLower;
    u16* ptr;
    u32 mask;

    for (i = 0; i < ARRAY_SIZE(sBossIcons); i++)
    {
        if (event == sBossIcons[i][0])
            break;
    }

    if (i >= 7)//ARRAY_SIZE(sBossIcons))
        return;

    if (i != gCurrentArea)
        return;

    i = sBossIcons[i][3] * MINIMAP_SIZE + sBossIcons[i][2];

    pMinimap = &gDecompressedMinimapData[i];
    pVisited = &gDecompressedMinimapVisitedTiles[i];

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
            
            for (i = 1; i >= 0; i--)
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

            for (i = 1; i >= 0; i--)
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
            for (i = 1; i >= 0; i--)
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

            for (i = 1; i >= 0; i--)
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
