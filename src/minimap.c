#include "minimap.h"
#include "gba.h"
#include "macros.h"

#include "data/unsorted.h"
#include "data/shortcut_pointers.h"
#include "data/menus/pause_screen_data.h"
#include "data/menus/pause_screen_map_data.h"

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

void MinimapCheckSetAreaNameAsExplored(u8 afterTransition)
{
    // https://decomp.me/scratch/lc52R

    u32 set;
    i32 i;
    u32 area;
    u32 xPosition;
    u32 yPosition;
    u16* pMap;
    u32 actualX;
    u32 actualY;
    u32* ptr;

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

    xPosition--;
    gLastAreaNameVisited.mapX = xPosition;
    yPosition--;
    gLastAreaNameVisited.mapY = yPosition;

    pMap = (u16*)0x2034800 + (area * MINIMAP_SIZE + actualX + actualY);

    for (i = 0; i < MINIMAP_SIZE; i++)
    {
        if ((pMap[i] & 0x3FF) - 0x141 <= 0x1D)
        {
            sVisitedMinimapTilesPointer[area * MINIMAP_SIZE + yPosition] |= sExploredMinimapBitFlags[actualX + i];
        }
    }

    if (afterTransition)
    {
        sVisitedMinimapTilesPointer[area * MINIMAP_SIZE + gLastAreaNameVisited.mapY] |= sExploredMinimapBitFlags[gLastAreaNameVisited.mapX];
        gLastAreaNameVisited.flags = 0;
    }
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

    if (gUpdateMinimapFlag != MINIMAP_UPDATE_FLAG_NONE)
        return;

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
    samusX /= BLOCK_SIZE;
    samusY /= BLOCK_SIZE;

    samusX /= 15;
    samusY /= 10;

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
    tiles = (u16*)0x2034000 + offset; // gDecompressedMinimapVisitedTiles
    
    if (!(*tiles & 0xF000))
    {
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
            gLastAreaNameVisited.mapX = gMinimapX + 0x1;
            gLastAreaNameVisited.mapY = gMinimapY + 0x1;
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
    u16 tile;
    u8 palette;
    u32 flip;
    u16* src;
    u32 offset;
    u32 mask;

    if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_NONE)
        return;
    
    src = (u16*)0x2034000;
    dst = (u32*)0x2037e20 + (gUpdateMinimapFlag - 1) * 24;

    if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_LOWER_LINE)
        yOffset = 0x1;
    else if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_MIDDLE_LINE)
        yOffset = 0x0;
    else if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_UPPER_LINE)
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

        offset = yPosition * MINIMAP_SIZE + xPosition;
        flip = (src[offset] & 0xC00) >> 0xA;
        palette = src[offset] >> 0xC;
        tile = src[offset] & 0x3ff;
        
        if (gLanguage == LANGUAGE_HIRAGANA && tile > 0x140)
            tile += 0x20;

        tile <<= 0x5;
        sMinimapTilesCopyGFXFunctionPointers[flip](dst, &tile, palette);

        xOffset++;
        dst += 0x8;
    }
}

/**
 * @brief 6c6b4 | d8 | Copies the graphics of a map tile
 * 
 * @param dst Destination pointer
 * @param pTile Tile pointer
 * @param palette Palette
 */
void MinimapCopyTileGFX(u32* dst, u16* pTile, u8 palette)
{
    i32 i;
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
void MinimapCopyTileXFlippedGFX(u32* dst, u16* pTile, u8 palette)
{
    i32 i;
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
void MinimapCopyTileYFlippedGFX(u32* dst, u16* pTile, u8 palette)
{
    i32 i;
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
void MinimapCopyTileXYFlippedGFX(u32* dst, u16* pTile, u8 palette)
{
    i32 i;
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
    i32 i;
    i32 j;

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

void MinimapSetDownloadedTiles(u8 area, u16* dst)
{
    // https://decomp.me/scratch/oSyZP

    u32* pVisited;
    i32 i;
    i32 j;

    pVisited = &sVisitedMinimapTilesPointer[area * MINIMAP_SIZE];

    if ((gEquipment.downloadedMapStatus >> area) & 1 || (u8)(area - MAX_AMOUNT_OF_AREAS) <= 2)
    {
        for (i = 0; i < MINIMAP_SIZE; i++, pVisited++)
        {
            for (j = 0; j < MINIMAP_SIZE; j++, dst++)
            {
                if (sExploredMinimapBitFlags[j] & *pVisited)
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
                if (sExploredMinimapBitFlags[j] & *pVisited)
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
        itemX = (xPosition - 2) / 15 + gCurrentRoomEntry.mapX;
        itemY = (yPosition - 2) / 10 + gCurrentRoomEntry.mapY;

        offset = gCurrentArea * MINIMAP_SIZE;
        ptr = (u32*)(0x2033800) + offset; // gMinimapTilesWithObtainedItems
        ptr[itemY] |= sExploredMinimapBitFlags[itemX];

        
        itemX += itemY * MINIMAP_SIZE;
        ptrU = (u16*)0x2034000; // gDecompressedMinimapVisitedTiles
        ptrU[itemX]++;
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

/**
 * @brief 6cd84 | 174 | Updates a minimap chunk/boss icon
 * 
 * @param event Event linked
 */
void MinimapUpdateChunk(u8 event)
{
    i32 i;
    u16* pMinimap;
    u16* pVisited;
    u16* pMinimapLower;
    u16* pVisitedLower;
    u16* ptr;
    u32 mask;

    for (i = 0; i < ARRAY_SIZE(sBossIcons); i++)
    {
        if (event == sBossIcons[i][0])
            break;
    }

    if (i >= (int)ARRAY_SIZE(sBossIcons))
        return;

    if (i != gCurrentArea)
        return;

    i = sBossIcons[i][3] * MINIMAP_SIZE + sBossIcons[i][2];

    pMinimap = (u16*)0x2034800 + i;
    pVisited = (u16*)0x2034000 + i;

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
