#include "minimap.h"
#include "globals.h"
#include "data/unsorted.h"

void MinimapUpdate(void)
{
    
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
        (*sVisitedMinimapTilesPointer[0])[offset] |= sExploredMinimapBitFlags[gMinimapX];
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

void MinimapCheckOnTransition(void)
{

}

void MinimapUpdateForExploredTiles(void)
{

}

void MinimapDraw(void)
{

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

u32 MinimapCheckIsTileExplored(u8 xPosition, u8 yPosition)
{

}

void MinimapLoadTilesWithObtainedItems(void)
{

}

void MinimapUpdateChunk(u8 event)
{

}