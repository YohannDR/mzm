#include "menus/pause_screen_map.h"
#include "menus/pause_screen.h"
#include "menus/status_screen.h"

#include "data/shortcut_pointers.h"
#include "data/block_data.h"
#include "data/menus/pause_screen_data.h"
#include "data/menus/pause_screen_map_data.h"
#include "data/menus/internal_pause_screen_data.h"

#include "constants/audio.h"
#include "constants/block.h"
#include "constants/connection.h"
#include "constants/minimap.h"
#include "constants/menus/pause_screen.h"

#include "structs/bg_clip.h"
#include "structs/minimap.h"
#include "structs/menus/pause_screen.h"

/**
 * @brief 6cef8 | 168 | Counts the number of tanks in the crrent area
 * 
 */
void PauseScreenCountTanksInArea(void)
{
    s32 i;
    struct ItemInfo* pItem;
    u32 type;

    // Reset current counters
    PAUSE_SCREEN_DATA.energyTankCurrent = 0;
    PAUSE_SCREEN_DATA.missileTankCurrent = 0;
    PAUSE_SCREEN_DATA.superMissileTankCurrent = 0;
    PAUSE_SCREEN_DATA.powerBombTankCurrent = 0;

    // Shouldn't this check for PAUSE_SCREEN_DATA.currentArea instead ? since that's what's used as an array indexer
    if (gCurrentArea >= MAX_AMOUNT_OF_AREAS)
    {
        // In invalid area, reset total counters
        PAUSE_SCREEN_DATA.energyTankTotal = 0;
        PAUSE_SCREEN_DATA.missileTankTotal = 0;
        PAUSE_SCREEN_DATA.superMissileTankTotal = 0;
        PAUSE_SCREEN_DATA.powerBombTankTotal = 0;
    }
    else
    {
        // Fetch max number of tanks for the currently viewed area
        PAUSE_SCREEN_DATA.energyTankTotal = sNumberOfTanksPerArea[PAUSE_SCREEN_DATA.currentArea].energy;
        PAUSE_SCREEN_DATA.missileTankTotal = sNumberOfTanksPerArea[PAUSE_SCREEN_DATA.currentArea].missile;
        PAUSE_SCREEN_DATA.superMissileTankTotal = sNumberOfTanksPerArea[PAUSE_SCREEN_DATA.currentArea].superMissile;
        PAUSE_SCREEN_DATA.powerBombTankTotal = sNumberOfTanksPerArea[PAUSE_SCREEN_DATA.currentArea].powerBomb;

        pItem = gItemsCollected[PAUSE_SCREEN_DATA.currentArea];
        i = 0;

        // Loop through every collected item of the current area and count each type
        while (i < MAX_AMOUNT_OF_ITEMS_PER_AREA && pItem->room != UCHAR_MAX)
        {
            type = (u8)pItem->type;
            if (type == ITEM_TYPE_MISSILE)
                PAUSE_SCREEN_DATA.missileTankCurrent++;
            else if (type == ITEM_TYPE_ENERGY)
                PAUSE_SCREEN_DATA.energyTankCurrent++;
            else if (type == ITEM_TYPE_SUPER_MISSILE)
                PAUSE_SCREEN_DATA.superMissileTankCurrent++;
            else if (type == ITEM_TYPE_POWER_BOMB)
                PAUSE_SCREEN_DATA.powerBombTankCurrent++;

            i++;
            pItem++;
        }
    }

    // Reset tank status
    PAUSE_SCREEN_DATA.tankStatus = 0;

    // Check has the max number of items for each type
    if (PAUSE_SCREEN_DATA.energyTankCurrent >= PAUSE_SCREEN_DATA.energyTankTotal)
        PAUSE_SCREEN_DATA.tankStatus |= 1;

    if (PAUSE_SCREEN_DATA.missileTankCurrent >= PAUSE_SCREEN_DATA.missileTankTotal)
        PAUSE_SCREEN_DATA.tankStatus |= 2;

    if (PAUSE_SCREEN_DATA.superMissileTankCurrent >= PAUSE_SCREEN_DATA.superMissileTankTotal)
        PAUSE_SCREEN_DATA.tankStatus |= 4;

    if (PAUSE_SCREEN_DATA.powerBombTankCurrent >= PAUSE_SCREEN_DATA.powerBombTankTotal)
        PAUSE_SCREEN_DATA.tankStatus |= 8;
}

/**
 * @brief 6d060 | 2d4 | Draws the in game time and tanks info on the map screen
 * 
 * @param param_1 
 * @param drawTanks Draw tanks or IGT info flag
 */
void PauseScreenDrawIgtAndTanks(u8 param_1, u8 drawTanks)
{
    s32 value;
    s32 i;

    if (!drawTanks)
    {
        // Always false
        if (param_1)
        {
            if (PAUSE_SCREEN_DATA.unk_34 == 1)
                PAUSE_SCREEN_DATA.unk_34 = 2;
            else
            {
                if (PAUSE_SCREEN_DATA.unk_34 != 2)
                    return;

                PAUSE_SCREEN_DATA.unk_34 = 1;
            }
        }
        else
        {
            PAUSE_SCREEN_DATA.unk_34 = 2;
        }

        // Hours tens
        value = gInGameTimer.hours / 10 % 10;
        DmaTransfer(3, VRAM_BASE + 0x17EA0 + value * HALF_BLOCK_SIZE,
            sPauseScreen_IgtAndTanksVramAddresses[IGT_AND_TANKS_VRAM_ADDRESS_TIME] + HALF_BLOCK_SIZE * 0, HALF_BLOCK_SIZE, 32);

        // Hours seconds
        value = gInGameTimer.hours % 10;
        DmaTransfer(3, VRAM_BASE + 0x17EA0 + value * HALF_BLOCK_SIZE,
            sPauseScreen_IgtAndTanksVramAddresses[IGT_AND_TANKS_VRAM_ADDRESS_TIME] + HALF_BLOCK_SIZE * 1, HALF_BLOCK_SIZE, 32);

        // Minutes tens
        value = gInGameTimer.minutes / 10 % 10;
        DmaTransfer(3, VRAM_BASE + 0x17EA0 + value * HALF_BLOCK_SIZE,
            sPauseScreen_IgtAndTanksVramAddresses[IGT_AND_TANKS_VRAM_ADDRESS_TIME] + HALF_BLOCK_SIZE * 3, HALF_BLOCK_SIZE, 32);

        // Minutes seconds
        value = gInGameTimer.minutes % 10;
        DmaTransfer(3, VRAM_BASE + 0x17EA0 + value * HALF_BLOCK_SIZE,
            sPauseScreen_IgtAndTanksVramAddresses[IGT_AND_TANKS_VRAM_ADDRESS_TIME] + HALF_BLOCK_SIZE * 4, HALF_BLOCK_SIZE, 32);

        // Seconds tens
        value = gInGameTimer.seconds / 10 % 10;
        DmaTransfer(3, VRAM_BASE + 0x17EA0 + value * HALF_BLOCK_SIZE,
            sPauseScreen_IgtAndTanksVramAddresses[IGT_AND_TANKS_VRAM_ADDRESS_TIME] + HALF_BLOCK_SIZE * 6, HALF_BLOCK_SIZE, 32);

        // Seconds seconds
        value = gInGameTimer.seconds % 10;
        DmaTransfer(3, VRAM_BASE + 0x17EA0 + value * HALF_BLOCK_SIZE,
            sPauseScreen_IgtAndTanksVramAddresses[IGT_AND_TANKS_VRAM_ADDRESS_TIME] + HALF_BLOCK_SIZE * 7, HALF_BLOCK_SIZE, 32);

        // Current energy tanks
        i = PAUSE_SCREEN_DATA.energyTankCurrent;
        if (i > 16)
            value = 16;
        else
            value = i;

        DmaTransfer(3, VRAM_BASE + 0x17C00 + value * HALF_BLOCK_SIZE,
            sPauseScreen_IgtAndTanksVramAddresses[IGT_AND_TANKS_VRAM_ADDRESS_ENERGY_TANKS] + HALF_BLOCK_SIZE * 0, HALF_BLOCK_SIZE, 32);

        // Total energy tanks
        i = PAUSE_SCREEN_DATA.energyTankTotal;
        if (i > 16)
            value = 16;
        else
            value = i;

        DmaTransfer(3, VRAM_BASE + 0x17C00 + value * HALF_BLOCK_SIZE,
            sPauseScreen_IgtAndTanksVramAddresses[IGT_AND_TANKS_VRAM_ADDRESS_ENERGY_TANKS] + HALF_BLOCK_SIZE * 2, HALF_BLOCK_SIZE, 32);
    }
    else
    {
        if (PAUSE_SCREEN_DATA.unk_34 == 0)
            return;

        // Current missile tanks tanks
        i = PAUSE_SCREEN_DATA.missileTankCurrent;
        if (i > 16)
            value = 16;
        else
            value = i;

        DmaTransfer(3, VRAM_BASE + 0x17C00 + value * HALF_BLOCK_SIZE,
            sPauseScreen_IgtAndTanksVramAddresses[IGT_AND_TANKS_VRAM_ADDRESS_MISSILE_TANKS] + HALF_BLOCK_SIZE * 0, HALF_BLOCK_SIZE, 32);

        // Total missile tanks tanks
        i = PAUSE_SCREEN_DATA.missileTankTotal;
        if (i > 16)
            value = 16;
        else
            value = i;

        DmaTransfer(3, VRAM_BASE + 0x17C00 + value * HALF_BLOCK_SIZE,
            sPauseScreen_IgtAndTanksVramAddresses[IGT_AND_TANKS_VRAM_ADDRESS_MISSILE_TANKS] + HALF_BLOCK_SIZE * 2, HALF_BLOCK_SIZE, 32);

        // Current super missile tanks tanks
        i = PAUSE_SCREEN_DATA.superMissileTankCurrent;
        if (i > 16)
            value = 16;
        else
            value = i;

        DmaTransfer(3, VRAM_BASE + 0x17C00 + value * HALF_BLOCK_SIZE,
            sPauseScreen_IgtAndTanksVramAddresses[IGT_AND_TANKS_VRAM_ADDRESS_SUPER_MISSILE_TANKS] + HALF_BLOCK_SIZE * 0, HALF_BLOCK_SIZE, 32);

        // Total super missile tanks tanks
        i = PAUSE_SCREEN_DATA.superMissileTankTotal;
        if (i > 16)
            value = 16;
        else
            value = i;

        DmaTransfer(3, VRAM_BASE + 0x17C00 + value * HALF_BLOCK_SIZE,
            sPauseScreen_IgtAndTanksVramAddresses[IGT_AND_TANKS_VRAM_ADDRESS_SUPER_MISSILE_TANKS] + HALF_BLOCK_SIZE * 2, HALF_BLOCK_SIZE, 32);

        // Current power bomb tanks tanks
        i = PAUSE_SCREEN_DATA.powerBombTankCurrent;
        if (i > 16)
            value = 16;
        else
            value = i;

        DmaTransfer(3, VRAM_BASE + 0x17C00 + value * HALF_BLOCK_SIZE,
            sPauseScreen_IgtAndTanksVramAddresses[IGT_AND_TANKS_VRAM_ADDRESS_POWER_BOMB_TANKS] + HALF_BLOCK_SIZE * 0, HALF_BLOCK_SIZE, 32);

        // Total power bomb tanks tanks
        i = PAUSE_SCREEN_DATA.powerBombTankTotal;
        if (i > 16)
            value = 16;
        else
            value = i;

        DmaTransfer(3, VRAM_BASE + 0x17C00 + value * HALF_BLOCK_SIZE,
            sPauseScreen_IgtAndTanksVramAddresses[IGT_AND_TANKS_VRAM_ADDRESS_POWER_BOMB_TANKS] + HALF_BLOCK_SIZE * 2, HALF_BLOCK_SIZE, 32);

        // Draw checkmarks when you have all of the tanks
        for (i = IGT_AND_TANKS_VRAM_ADDRESS_TANKS_END - 1; i >= IGT_AND_TANKS_VRAM_ADDRESS_ENERGY_TANKS; i--)
        {
            if ((PAUSE_SCREEN_DATA.tankStatus >> i) & 1)
            {
                // Checkmark
                DmaTransfer(3, VRAM_BASE + 0x17E00, sPauseScreen_IgtAndTanksVramAddresses[i] - HALF_BLOCK_SIZE * 3, HALF_BLOCK_SIZE, 32);
            }
            else
            {
                // No checkmark
                BitFill(3, 0, sPauseScreen_IgtAndTanksVramAddresses[i] - HALF_BLOCK_SIZE * 3, HALF_BLOCK_SIZE, 32);
            }
        }
    }
}

/**
 * @brief 6d334 | 114 | Initializes the map download
 * 
 */
void PauseScreenInitMapDownload(void)
{
    s32 i;
    u16* ptr_1;
    u16* ptr_2;

    // Force download type 0, type 1 and 2 exists but are unused
    PAUSE_SCREEN_DATA.mapDownloadType = 0;

    if (PAUSE_SCREEN_DATA.mapDownloadType == 1)
    {
        BitFill(3, 0x1E0, VRAM_BASE + 0xD800, 0x800, 16);
        DmaTransfer(3, sPauseScreen_40f4c4, sPauseScreen_7602a8, MINIMAP_SIZE, 16);
    }
    else if (PAUSE_SCREEN_DATA.mapDownloadType == 2)
    {
        for (i = 0; i < MINIMAP_SIZE; i++)
        {
            BitFill(3, 0x1E0 + i, VRAM_BASE + 0xD800 + i * MINIMAP_SIZE * 2, MINIMAP_SIZE * 2, 16);
        }

        for (i = 0; i < MINIMAP_SIZE; i++)
        {
            DmaTransfer(3, sPauseScreen_40f4c4, &sPauseScreen_7602a8[i * 8], MINIMAP_SIZE, 16);
        }
    }

    PAUSE_SCREEN_DATA.downloadTimer = 0;
    PAUSE_SCREEN_DATA.downloadStage = 0;
    PAUSE_SCREEN_DATA.currentDownloadedLine = 0;
    PAUSE_SCREEN_DATA.unk_4F = 0;

    if (PAUSE_SCREEN_DATA.mapDownloadType != 0)
    {
        ptr_1 = VRAM_BASE + 0xE000;
        ptr_2 = VRAM_BASE + 0xD800;
        for (i = 0; i < MINIMAP_SIZE * MINIMAP_SIZE; i++, ptr_2++, ptr_1++)
        {
            if ((*ptr_1 & 0x3FF) != 0xA0)
                *ptr_2 = 0xC0;
        }
    
        // 0x2034000 is gDecompressedMinimapVisitedTiles, direct address is required to match
        DMA_SET(3, 0x2034000, VRAM_BASE + 0xE000,
            C_32_2_16(DMA_ENABLE, ARRAY_SIZE(gDecompressedMinimapVisitedTiles)));
    }
}

/**
 * @brief 6d448 | 38 | Subroutine for the map download
 * 
 * @return u32 bool, ended
 */
u32 PauseScreenMapDownloadSubroutine(void)
{
    u32 ended;

    ended = FALSE;

    if (PAUSE_SCREEN_DATA.mapDownloadType == 0)
        ended = PauseScreenMapDownload();
    else if (PAUSE_SCREEN_DATA.mapDownloadType == 1)
        ended = PauseScreenMapDownloadInstant_Unused();
    else if (PAUSE_SCREEN_DATA.mapDownloadType == 2)
        ended = PauseScreenMapDownloadInstantWithLine_Unused();

    return ended;
}

/**
 * @brief 6d480 | a8 | Unused map download, download the entire map instantly
 * 
 * @return u32 bool, ended
 */
u32 PauseScreenMapDownloadInstant_Unused(void)
{
    s32 i;
    s32 j;
    s32 offset;
    const u32* ptr;

    if (PAUSE_SCREEN_DATA.unk_4F >= 16)
        return TRUE;

    PAUSE_SCREEN_DATA.downloadTimer++;
    
    switch (PAUSE_SCREEN_DATA.downloadStage)
    {
        case 0:
            if (PAUSE_SCREEN_DATA.downloadTimer > 16)
            {
                PAUSE_SCREEN_DATA.downloadStage = 1;
                PAUSE_SCREEN_DATA.downloadTimer = 0;
            }
            break;

        case 1:
            if (PAUSE_SCREEN_DATA.downloadTimer <= 3)
                break;

            PAUSE_SCREEN_DATA.downloadTimer = 0;
            ptr = sPauseScreen_40f4c4;
            PAUSE_SCREEN_DATA.unk_4F++;

            i = PAUSE_SCREEN_DATA.unk_4F;
            j = 0;

            while (i != 0)
            {
                offset = i;
                if (offset >= ARRAY_SIZE(sPauseScreen_7602b0))
                    offset = ARRAY_SIZE(sPauseScreen_7602b0) - 1;

                sPauseScreen_7602a8[j] = ptr[j] & sPauseScreen_7602b0[offset];

                i--;
                j++;
            }
            break;
    }

    return FALSE;
}

/**
 * @brief 6d528 | 158 | Unused map download, download the entire map instantly and has the line animation
 * 
 * @return u32 bool, ended
 */
u32 PauseScreenMapDownloadInstantWithLine_Unused(void)
{
    u32 ended;

    ended = FALSE;
    APPLY_DELTA_TIME_INC(PAUSE_SCREEN_DATA.downloadTimer);

    switch (PAUSE_SCREEN_DATA.downloadStage)
    {
        case 0:
            if (PAUSE_SCREEN_DATA.downloadTimer > CONVERT_SECONDS(2.f / 15))
            {
                // Setup line
                PAUSE_SCREEN_DATA.miscOam[2].oamID = MISC_OAM_ID_MAP_DOWNLOAD_LINE;
                PAUSE_SCREEN_DATA.miscOam[2].animationDurationCounter = 0;
                PAUSE_SCREEN_DATA.miscOam[2].currentAnimationFrame = 0;
                PAUSE_SCREEN_DATA.miscOam[2].xPosition = BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE;

                // Start a bit above the screen
                PAUSE_SCREEN_DATA.miscOam[2].yPosition = -HALF_BLOCK_SIZE;
                PAUSE_SCREEN_DATA.miscOam[2].priority = 1;
                PAUSE_SCREEN_DATA.miscOam[2].exists = TRUE;

                PAUSE_SCREEN_DATA.downloadStage++;
                PAUSE_SCREEN_DATA.downloadTimer = 0;
                PAUSE_SCREEN_DATA.currentDownloadedLine = (gBg3VOFS_NonGameplay & 0x3FF) / 4;
            }
            break;

        case 1:
            // Check reached bottom
            if (PAUSE_SCREEN_DATA.miscOam[2].yPosition > BLOCK_SIZE * 10 + HALF_BLOCK_SIZE + 8)
            {
                PAUSE_SCREEN_DATA.downloadStage = 2;
                break;
            }

            // Check on screen
            if (PAUSE_SCREEN_DATA.miscOam[2].yPosition >= -QUARTER_BLOCK_SIZE)
            {
                sPauseScreen_7602a8[PAUSE_SCREEN_DATA.currentDownloadedLine] = 0;
                PAUSE_SCREEN_DATA.currentDownloadedLine++;
            }

            // Move line down
            PAUSE_SCREEN_DATA.miscOam[2].yPosition += 4;
            break;

        case 2:
            // Kill line
            PAUSE_SCREEN_DATA.miscOam[2].exists = FALSE;
            PAUSE_SCREEN_DATA.downloadTimer = 0;
            PAUSE_SCREEN_DATA.downloadStage++;
            break;

        case 3:
            if (PAUSE_SCREEN_DATA.downloadTimer >= CONVERT_SECONDS(.5f))
            {
                PAUSE_SCREEN_DATA.downloadTimer = 0;
                PAUSE_SCREEN_DATA.downloadStage = 0;
                ended = TRUE;
            }
    }

    return ended;
}

/**
 * @brief 6d680 | 4d8 | 
 * 
 * @return u32 
 */
u32 PauseScreenMapDownload(void)
{
    u32 ended;
    s32 i;

    ended = FALSE;
    APPLY_DELTA_TIME_INC(PAUSE_SCREEN_DATA.downloadTimer);

    switch (PAUSE_SCREEN_DATA.downloadStage)
    {
        case 0:
            if (PAUSE_SCREEN_DATA.downloadTimer <= CONVERT_SECONDS(2.f / 15))
                break;

            // Setup line
            PAUSE_SCREEN_DATA.miscOam[2].oamID = MISC_OAM_ID_MAP_DOWNLOAD_LINE;
            PAUSE_SCREEN_DATA.miscOam[2].animationDurationCounter = 0;
            PAUSE_SCREEN_DATA.miscOam[2].currentAnimationFrame = 0;
            PAUSE_SCREEN_DATA.miscOam[2].xPosition = BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE;

            // Start a bit above the screen
            PAUSE_SCREEN_DATA.miscOam[2].yPosition = -HALF_BLOCK_SIZE;
            PAUSE_SCREEN_DATA.miscOam[2].priority = 1;
            PAUSE_SCREEN_DATA.miscOam[2].exists = TRUE;

            // Setup line trails
            for (i = 3; i >= 0; i--)
            {
                PAUSE_SCREEN_DATA.miscOam[sMapDownloadLineTrailOamOffsets[i]].oamID = 0;
                PAUSE_SCREEN_DATA.miscOam[sMapDownloadLineTrailOamOffsets[i]].animationDurationCounter = 0;
                PAUSE_SCREEN_DATA.miscOam[sMapDownloadLineTrailOamOffsets[i]].currentAnimationFrame = 0;
                PAUSE_SCREEN_DATA.miscOam[sMapDownloadLineTrailOamOffsets[i]].xPosition = BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE;
                PAUSE_SCREEN_DATA.miscOam[sMapDownloadLineTrailOamOffsets[i]].yPosition = -HALF_BLOCK_SIZE;
                PAUSE_SCREEN_DATA.miscOam[sMapDownloadLineTrailOamOffsets[i]].priority = 1;
                PAUSE_SCREEN_DATA.miscOam[sMapDownloadLineTrailOamOffsets[i]].objMode = 1;
                PAUSE_SCREEN_DATA.miscOam[sMapDownloadLineTrailOamOffsets[i]].exists = FALSE;
            }
            
            PAUSE_SCREEN_DATA.downloadStage++;
            PAUSE_SCREEN_DATA.downloadTimer = 0;
            PAUSE_SCREEN_DATA.unk_4F = 0;
            PAUSE_SCREEN_DATA.downloadLineTrailOamOffsetIndex = 0x80;
            break;

        case 1:
            PAUSE_SCREEN_DATA.currentDownloadedLine = 0;
            PAUSE_SCREEN_DATA.unk_4F = 0;

            if (gBg3VOFS_NonGameplay < BLOCK_SIZE * 32)
            {
                PAUSE_SCREEN_DATA.currentDownloadedLine = 0x3F - ((BLOCK_SIZE * 32 - gBg3VOFS_NonGameplay) >> 5);
            }
            else if (gBg3VOFS_NonGameplay > BLOCK_SIZE * 32)
            {
                PAUSE_SCREEN_DATA.currentDownloadedLine = (gBg3VOFS_NonGameplay - BLOCK_SIZE * 32) >> 5;
            }

            PAUSE_SCREEN_DATA.downloadStage++;
            PAUSE_SCREEN_DATA.downloadTimer = 0;
            break;

        case 2:
            i = TRUE;

            if (PAUSE_SCREEN_DATA.downloadTimer >= CONVERT_SECONDS(2.f / 15))
            {
                if (PAUSE_SCREEN_DATA.unk_4F < 21)
                {
                    if (PAUSE_SCREEN_DATA.currentDownloadedLine < MINIMAP_SIZE)
                    {
                        // "Draw" current line
                        DMA_SET(3, &gDecompressedMinimapVisitedTiles[PAUSE_SCREEN_DATA.currentDownloadedLine * MINIMAP_SIZE],
                            VRAM_BASE + 0xE000 + PAUSE_SCREEN_DATA.currentDownloadedLine * MINIMAP_SIZE * 2, DMA_ENABLE << 16 | MINIMAP_SIZE);   
                    }

                    PAUSE_SCREEN_DATA.unk_4F++;
                    PAUSE_SCREEN_DATA.currentDownloadedLine++;

                    if (PAUSE_SCREEN_DATA.currentDownloadedLine >= MINIMAP_SIZE * 2)
                        PAUSE_SCREEN_DATA.currentDownloadedLine = 0;

                    // Check reveal the boss icon of the area if the line is at the bottom of it (hence the + 2)
                    if (PAUSE_SCREEN_DATA.bossIconOam[0].oamID != 0 && PAUSE_SCREEN_DATA.currentDownloadedLine
                        == sBossIcons[PAUSE_SCREEN_DATA.currentArea][3] + 2)
                        PAUSE_SCREEN_DATA.bossIconOam[0].notDrawn = FALSE;
                }
                else
                {
                    PAUSE_SCREEN_DATA.downloadStage++;
                    i = FALSE;
                }

                PAUSE_SCREEN_DATA.downloadTimer = 0;
            }

            if (i)
            {
                // Move line
                PAUSE_SCREEN_DATA.miscOam[2].yPosition = ((PAUSE_SCREEN_DATA.unk_4F - 1) * 8 + PAUSE_SCREEN_DATA.downloadTimer) * 4;

                PAUSE_SCREEN_DATA.downloadLineTrailOamOffsetIndex++;
                if (PAUSE_SCREEN_DATA.downloadLineTrailOamOffsetIndex >= ARRAY_SIZE(sMapDownloadLineTrailOamOffsets))
                    PAUSE_SCREEN_DATA.downloadLineTrailOamOffsetIndex = 0;

                i = PAUSE_SCREEN_DATA.downloadLineTrailOamOffsetIndex;

                // Lag position slightly behind line
                PAUSE_SCREEN_DATA.miscOam[sMapDownloadLineTrailOamOffsets[i]].yPosition = PAUSE_SCREEN_DATA.miscOam[2].yPosition - 4;

                // Setup trail
                PAUSE_SCREEN_DATA.miscOam[sMapDownloadLineTrailOamOffsets[i]].oamID = MISC_OAM_ID_MAP_DOWNLOAD_LINE_TRAIL;
                PAUSE_SCREEN_DATA.miscOam[sMapDownloadLineTrailOamOffsets[i]].animationDurationCounter = 0;
                PAUSE_SCREEN_DATA.miscOam[sMapDownloadLineTrailOamOffsets[i]].currentAnimationFrame = 0;
                PAUSE_SCREEN_DATA.miscOam[sMapDownloadLineTrailOamOffsets[i]].exists = TRUE;
            }
            break;

        case 3:
            // Fully transfer everything
            DMA_SET(3, gDecompressedMinimapVisitedTiles, VRAM_BASE + 0xE000,
                C_32_2_16(DMA_ENABLE, ARRAY_SIZE(gDecompressedMinimapVisitedTiles)));

            PAUSE_SCREEN_DATA.downloadStage++;
            PAUSE_SCREEN_DATA.downloadTimer = 0;
            break;

        case 4:
            // Redraw minimap, so that the download also applies to in game
            for (i = MINIMAP_UPDATE_FLAG_END - 1; i > MINIMAP_UPDATE_FLAG_NONE; i--)
            {
                gUpdateMinimapFlag = i;
                MinimapDraw();
            }
            
            PAUSE_SCREEN_DATA.downloadStage++;
            PAUSE_SCREEN_DATA.downloadTimer = 0;
            break;

        case 5:
            // Kill line
            PAUSE_SCREEN_DATA.miscOam[2].oamID = 0;
            PAUSE_SCREEN_DATA.miscOam[2].animationDurationCounter = 0;
            PAUSE_SCREEN_DATA.miscOam[2].currentAnimationFrame = 0;
            PAUSE_SCREEN_DATA.miscOam[2].exists = FALSE;

            // Kill line trails
            for (i = ARRAY_SIZE(sMapDownloadLineTrailOamOffsets); i > 0; )
            {
                i--;
                PAUSE_SCREEN_DATA.miscOam[sMapDownloadLineTrailOamOffsets[i]].oamID = 0;
                PAUSE_SCREEN_DATA.miscOam[sMapDownloadLineTrailOamOffsets[i]].animationDurationCounter = 0;
                PAUSE_SCREEN_DATA.miscOam[sMapDownloadLineTrailOamOffsets[i]].currentAnimationFrame = 0;
                PAUSE_SCREEN_DATA.miscOam[sMapDownloadLineTrailOamOffsets[i]].exists = FALSE;
            }
            
            PAUSE_SCREEN_DATA.downloadTimer = 0;
            PAUSE_SCREEN_DATA.downloadStage++;
            break;

        case 6:
            if (PAUSE_SCREEN_DATA.downloadTimer >= CONVERT_SECONDS(.5f))
            {
                PAUSE_SCREEN_DATA.downloadTimer = 0;
                PAUSE_SCREEN_DATA.downloadStage = 0;
                ended = TRUE;
            }
    }

    return ended;
}

/**
 * @brief 6db58 | 238 | Sets the positions and boundaries of the map
 * 
 * @param spawnOption Where to spawn, 0 is close to chozo hint, 1 is normal, 2 is center
 */
void PauseScreenMapSetSpawnPosition(u8 spawnOption)
{
    u32 mapX;
    u32 mapY;
    s32 temp_1;
    s32 temp_2;

    PAUSE_SCREEN_DATA.canScrollRight = FALSE;
    PAUSE_SCREEN_DATA.canScrollLeft = FALSE;
    PAUSE_SCREEN_DATA.canScrollUp = FALSE;
    PAUSE_SCREEN_DATA.canScrollDown = FALSE;

    PAUSE_SCREEN_DATA.mapLeftBorder = MINIMAP_SIZE - 1;
    PAUSE_SCREEN_DATA.mapTopBorder = MINIMAP_SIZE - 1;
    PAUSE_SCREEN_DATA.mapRightBorder = 0;
    PAUSE_SCREEN_DATA.mapBottomBorder = 0;

    PauseScreenMapGetAbsoluteMapBordersPositions();
    PauseScreenMapUpdateMapBordersForTargets();

    if (PAUSE_SCREEN_DATA.mapLeftBorder > PAUSE_SCREEN_DATA.mapRightBorder)
        PAUSE_SCREEN_DATA.mapRightBorder = PAUSE_SCREEN_DATA.mapLeftBorder;

    if (PAUSE_SCREEN_DATA.mapTopBorder > PAUSE_SCREEN_DATA.mapBottomBorder)
        PAUSE_SCREEN_DATA.mapBottomBorder = PAUSE_SCREEN_DATA.mapTopBorder;

    PAUSE_SCREEN_DATA.absoluteMapRightBorder = PAUSE_SCREEN_DATA.mapRightBorder;
    PAUSE_SCREEN_DATA.absoluteMapLeftBorder = PAUSE_SCREEN_DATA.mapLeftBorder;
    PAUSE_SCREEN_DATA.absoluteMapTopBorder = PAUSE_SCREEN_DATA.mapTopBorder;
    PAUSE_SCREEN_DATA.absoluteMapBottomBorder = PAUSE_SCREEN_DATA.mapBottomBorder;

    // Leave map where it is
    if (spawnOption == 1)
    {
        mapX = PAUSE_SCREEN_DATA.mapX;
        mapY = PAUSE_SCREEN_DATA.mapY;
    }
    // Put map in the middle
    else if (spawnOption == 2)
    {
        mapX = DIV_SHIFT(PAUSE_SCREEN_DATA.mapLeftBorder + PAUSE_SCREEN_DATA.mapRightBorder, 2);
        mapY = DIV_SHIFT(PAUSE_SCREEN_DATA.mapTopBorder + PAUSE_SCREEN_DATA.mapBottomBorder, 2);
    }
    // Put map close to the chozo hint
    else
    {
        mapX = DIV_SHIFT(PAUSE_SCREEN_DATA.mapLeftBorder + PAUSE_SCREEN_DATA.mapRightBorder, 2);
        mapY = DIV_SHIFT(PAUSE_SCREEN_DATA.mapTopBorder + PAUSE_SCREEN_DATA.mapBottomBorder, 2);

        temp_1 = mapY + 5;
        temp_2 = mapY - 5;
        if (temp_1 < PAUSE_SCREEN_DATA.mapY)
        {
            mapY += PAUSE_SCREEN_DATA.mapY - temp_1; // mapY = PAUSE_SCREEN_DATA.mapY - 5
        }
        else if (temp_2 > PAUSE_SCREEN_DATA.mapY)
        {
            mapY -= temp_2 - PAUSE_SCREEN_DATA.mapY; // mapY = 5 - PAUSE_SCREEN_DATA.mapY
        }

        temp_1 = mapX + 6;
        temp_2 = mapX - 6;
        if (temp_1 < PAUSE_SCREEN_DATA.mapX)
        {
            mapX += PAUSE_SCREEN_DATA.mapX - temp_1; // mapX = PAUSE_SCREEN_DATA.mapX - 6
        }
        else if (temp_2 > PAUSE_SCREEN_DATA.mapX)
        {
            mapX -= temp_2 - PAUSE_SCREEN_DATA.mapX; // mapX = 6 - PAUSE_SCREEN_DATA.mapX
        }
    }

    PAUSE_SCREEN_DATA.mapViewX = mapX;
    PAUSE_SCREEN_DATA.mapViewY = mapY;

    if (DIV_SHIFT(PAUSE_SCREEN_DATA.mapBottomBorder - PAUSE_SCREEN_DATA.mapTopBorder, 2) > 5)
    {
        PAUSE_SCREEN_DATA.mapTopBorder += 5;
        PAUSE_SCREEN_DATA.mapBottomBorder -= 5;
    }
    else
    {
        PAUSE_SCREEN_DATA.mapTopBorder = PAUSE_SCREEN_DATA.mapBottomBorder =
            DIV_SHIFT(PAUSE_SCREEN_DATA.mapBottomBorder + PAUSE_SCREEN_DATA.mapTopBorder, 2);
    }

    if (DIV_SHIFT(PAUSE_SCREEN_DATA.mapRightBorder - PAUSE_SCREEN_DATA.mapLeftBorder, 2) > 6)
    {
        PAUSE_SCREEN_DATA.mapLeftBorder += 6;
        PAUSE_SCREEN_DATA.mapRightBorder -= 6;
    }
    else
    {
        PAUSE_SCREEN_DATA.mapLeftBorder = PAUSE_SCREEN_DATA.mapRightBorder =
            DIV_SHIFT(PAUSE_SCREEN_DATA.mapRightBorder + PAUSE_SCREEN_DATA.mapLeftBorder, 2);
    }

    if (PAUSE_SCREEN_DATA.mapViewX < PAUSE_SCREEN_DATA.mapLeftBorder)
        PAUSE_SCREEN_DATA.mapLeftBorder = PAUSE_SCREEN_DATA.mapViewX;
    else if (PAUSE_SCREEN_DATA.mapViewX > PAUSE_SCREEN_DATA.mapRightBorder)
        PAUSE_SCREEN_DATA.mapRightBorder = PAUSE_SCREEN_DATA.mapViewX;

    if (PAUSE_SCREEN_DATA.mapViewY < PAUSE_SCREEN_DATA.mapTopBorder)
        PAUSE_SCREEN_DATA.mapTopBorder = PAUSE_SCREEN_DATA.mapViewY;
    else if (PAUSE_SCREEN_DATA.mapViewY > PAUSE_SCREEN_DATA.mapBottomBorder)
        PAUSE_SCREEN_DATA.mapBottomBorder = PAUSE_SCREEN_DATA.mapViewY;

    // Middle of screen?
    gBg3HOFS_NonGameplay = (0x204 - (15 - PAUSE_SCREEN_DATA.mapViewX) * 8) * 4;
    gBg3VOFS_NonGameplay = (0x204 - (10 - PAUSE_SCREEN_DATA.mapViewY) * 8) * 4;
}

/**
 * @brief 6ddc0 | 110 | Gets the borders of the current area map
 * 
 */
void PauseScreenMapGetAbsoluteMapBordersPositions(void)
{
    s32 i;
    s32 j;
    u8 found;
    u16* pMap;

    if (PAUSE_SCREEN_DATA.currentArea < AREA_NORMAL_COUNT)
        j = PAUSE_SCREEN_DATA.currentArea;
    else
        j = AREA_DEBUG_1;

    // Fetch current map pointer
    pMap = PAUSE_SCREEN_DATA.mapsDataPointer[j];

    found = FALSE;
    // Iterate through the minimap, from top left to find the furthest non background tile
    for (i = 0; i < MINIMAP_SIZE && !found; i++)
    {
        for (j = 0; j < MINIMAP_SIZE; j++)
        {
            // Scan row by row
            if (pMap[i * MINIMAP_SIZE + j] != MINIMAP_TILE_BACKGROUND)
            {
                // Found non background tile, mark as new border and break
                PAUSE_SCREEN_DATA.mapTopBorder = i;
                found = TRUE;
                break;
            }
        }
    }

    // Same thing, but from bottom left
    for (i = MINIMAP_SIZE - 1, found = FALSE; i >= 0 && !found; i--)
    {
        for (j = 0; j < MINIMAP_SIZE; j++)
        {
            // Scan row by row
            if (pMap[i * MINIMAP_SIZE + j] != MINIMAP_TILE_BACKGROUND)
            {
                PAUSE_SCREEN_DATA.mapBottomBorder = i;
                found = TRUE;
                break;
            }
        }
    }
    
    found = FALSE;
    // Same thing, but from top left (iteration direction changed)
    for (i = 0; i < MINIMAP_SIZE && !found; i++)
    {
        for (j = 0; j < MINIMAP_SIZE; j++)
        {
            // Scan column by column
            if (pMap[i + j * MINIMAP_SIZE] != MINIMAP_TILE_BACKGROUND)
            {
                PAUSE_SCREEN_DATA.mapLeftBorder = i;
                found = TRUE;
                break;
            }
        }
    }

    // Same thing, but from top right (iteration direction changed)
    for (i = MINIMAP_SIZE - 1, found = FALSE; i >= 0 && !found; i--)
    {
        for (j = 0; j < MINIMAP_SIZE; j++)
        {
            // Scan column by column
            if (pMap[i + j * MINIMAP_SIZE] != MINIMAP_TILE_BACKGROUND)
            {
                PAUSE_SCREEN_DATA.mapRightBorder = i;
                found = TRUE;
                break;
            }
        }
    }
}

/**
 * @brief 6ded0 | b0 | Updates the absolute borders positions to allow scrolling to targets
 * 
 */
void PauseScreenMapUpdateMapBordersForTargets(void)
{
    struct MenuOamData* pOam;
    s32 i;
    u16 xPosition;
    u16 yPosition;

    pOam = PAUSE_SCREEN_DATA.targetsOam;
    for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.targetsOam); i++, pOam++)
    {
        if (!pOam->exists)
            continue;

        // Get tile X position
        if (pOam->xPosition < 0)
            xPosition = 0; // Lower limit
        else if (pOam->xPosition >= MINIMAP_SIZE * HALF_BLOCK_SIZE)
            xPosition = MINIMAP_SIZE - 1; // Upper limit
        else
            xPosition = DIV_SHIFT(pOam->xPosition, HALF_BLOCK_SIZE); // To tile (divided by HALF_BLOCK_SIZE)

        // Get tile Y position
        if (pOam->yPosition < 0)
            yPosition = 0; // Lower limit
        else if (pOam->yPosition >= MINIMAP_SIZE * HALF_BLOCK_SIZE)
            yPosition = MINIMAP_SIZE - 1; // Upper limit
        else
            yPosition = DIV_SHIFT(pOam->yPosition, HALF_BLOCK_SIZE); // To tile (divided by HALF_BLOCK_SIZE)

        // Check should update any border
        if (yPosition < PAUSE_SCREEN_DATA.mapTopBorder)
            PAUSE_SCREEN_DATA.mapTopBorder = yPosition;
        
        if (yPosition > PAUSE_SCREEN_DATA.mapBottomBorder)
            PAUSE_SCREEN_DATA.mapBottomBorder = yPosition;

        if (xPosition < PAUSE_SCREEN_DATA.mapLeftBorder)
            PAUSE_SCREEN_DATA.mapLeftBorder = xPosition;
        
        if (xPosition > PAUSE_SCREEN_DATA.mapRightBorder)
            PAUSE_SCREEN_DATA.mapRightBorder = xPosition;
    }
}

/**
 * @brief 6df80 | 7c | Gets all the minimap data
 * 
 * @param start Start minimap
 */
void PauseScreenGetAllMinimapData(u8 start)
{
    s32 size;
    s32 i;
    u8 area;

    if (start >= MAX_AMOUNT_OF_AREAS)
    {
        // Get everything
        i = 0;
        size = MAX_AMOUNT_OF_AREAS;
    }
    else
    {
        // Get the requested map only
        i = start;
        size = start + 1;
    }

    // Set pointer
    PAUSE_SCREEN_DATA.mapsDataPointer = PAUSE_SCREEN_EWRAM.mapTilemaps;

    for (; i < size; i++)
    {
        // Get area
        area = sMapScreenAreaIds[i];

        // Get minimap data and add the downloaded tiles
        PauseScreenGetMinimapData(area, PAUSE_SCREEN_DATA.mapsDataPointer[i]);
        MinimapSetDownloadedTiles(area, PAUSE_SCREEN_DATA.mapsDataPointer[i]);
    }
}

/**
 * @brief 6dffc | 50 | Checks which areas have at least one visited tile
 * 
 */
void PauseScreenMapCheckExploredAreas(void)
{
    u32 i;
    s32 j;

    // Clear
    PAUSE_SCREEN_DATA.areasWithVisitedTiles = 0;

    // Foreach area, except debug
    for (i = 0; i < AREA_NORMAL_COUNT; i++)
    {
        for (j = 0; j < MINIMAP_SIZE; j++)
        {
            // Check has visited bit
            if (sVisitedMinimapTilesPointer[i * MINIMAP_SIZE + j])
            {
                // Mark area as visited, exit the loop
                PAUSE_SCREEN_DATA.areasWithVisitedTiles |= (1 << i);
                break;
            }
        }
    }
}

/**
 * @brief 6e04c | 1a8 | Map screen subroutine
 * 
 */
void MapScreenSubroutine(void)
{
    u8 action;

    // Check update minimap switch
    if (PAUSE_SCREEN_DATA.changingMinimapStage)
    {
        MapScreenChangeMap();
        return;
    }

    action = 0;
    if (!(gButtonInput & KEY_A))
    {
        // Handle minimap scrolling movement
        if (gChangedInput & KEY_UP)
        {
            if (PAUSE_SCREEN_DATA.canScrollUp)
            {
                PAUSE_SCREEN_DATA.mapViewY--;
                action = 1;
            }
        }
        else if (gChangedInput & KEY_DOWN)
        {
            if (PAUSE_SCREEN_DATA.canScrollDown)
            {
                PAUSE_SCREEN_DATA.mapViewY++;
                action = 1;
            }
        }

        if (gChangedInput & KEY_LEFT)
        {
            if (PAUSE_SCREEN_DATA.canScrollLeft)
            {
                PAUSE_SCREEN_DATA.mapViewX--;
                action = 1;
            }
        }
        else if (gChangedInput & KEY_RIGHT)
        {
            if (PAUSE_SCREEN_DATA.canScrollRight)
            {
                PAUSE_SCREEN_DATA.mapViewX++;
                action = 1;
            }
        }

        // Update BG3 position
        gBg3HOFS_NonGameplay = (0x204 - (15 - PAUSE_SCREEN_DATA.mapViewX) * 8) * 4;
        gBg3VOFS_NonGameplay = (0x204 - (10 - PAUSE_SCREEN_DATA.mapViewY) * 8) * 4;

        if (action == 1)
        {
            // Play movement sound
            if (PAUSE_SCREEN_DATA.onWorldMap)
                SoundPlay(SOUND_MOVING_MAP_MUFFLED);
            else
                SoundPlay(SOUND_MOVING_MAP);
        }
        else if (action == 0)
        {
            // Check enter sub menu
            if (gChangedInput & KEY_R)
            {
                // Status screen
                PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_STATUS_SCREEN_INIT;
                action = 2;
            }
            else if (gChangedInput & KEY_L)
            {
                // Easy sleep
                SoundPlay(SOUND_OPENING_EASY_SLEEP_SCREEN);
                PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_EASY_SLEEP_INIT;
                action = 2;
            }
    
            if (action != 0)
            {
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;

                // Force qui world map
                MapScreenToggleWorldMap(TRUE);
            }
        }
    }

    if (action != 0)
        return;

    if (gChangedInput & (KEY_A | KEY_B))
    {
        // Switch world map
        MapScreenToggleWorldMap(FALSE);
        return;
    }

    // Check switch minimap
    if (gChangedInput & KEY_SELECT)
    {
        if (PAUSE_SCREEN_DATA.areasViewablesTotal > 1 && PAUSE_SCREEN_DATA.currentArea < AREA_NORMAL_COUNT)
            PAUSE_SCREEN_DATA.changingMinimapStage = 1;
    }
}

/**
 * @brief 6e1f4 | dc | Switches the world map on/off
 * 
 * @param forceOff bool, force closing
 */
void MapScreenToggleWorldMap(u8 forceOff)
{
    if (!forceOff)
    {
        // Toggle
        PAUSE_SCREEN_DATA.onWorldMap ^= TRUE;
    }
    else
    {
        // Already off, no need to do anything
        if (!PAUSE_SCREEN_DATA.onWorldMap)
            return;

        // Force off
        PAUSE_SCREEN_DATA.onWorldMap = FALSE;
    }

    if (PAUSE_SCREEN_DATA.onWorldMap)
    {
        // Apply world map overlay tilemap
        DmaTransfer(3, PAUSE_SCREEN_EWRAM.worldMapOverlayTilemap, VRAM_BASE + 0xD000,
            sizeof(PAUSE_SCREEN_EWRAM.worldMapOverlayTilemap), 16);

        // Don't overwrite first color in PALRAM
        DmaTransfer(3, sPauseScreen_3fd250 + 1, PALRAM_BASE + 2, sizeof(sPauseScreen_3fd250) - 2, 16);

        // Setup oam
        PauseScreenUpdateWorldMap(TRUE);
        SoundPlay(SOUND_OPENING_WORLD_MAP);
    }
    else
    {
        // Apply map screen tilemap
        DmaTransfer(3, PAUSE_SCREEN_EWRAM.mapScreenOverlayTilemap, VRAM_BASE + 0xD000,
            sizeof(PAUSE_SCREEN_EWRAM.mapScreenOverlayTilemap), 16);

        DmaTransfer(3, &sMinimapTilesPal[1], PALRAM_BASE + 2, sizeof(sMinimapTilesPal) - 2, 16);

        if (!forceOff)
            SoundPlay(SOUND_CLOSING_WORLD_MAP);
    }

    PauseScreenUpdateBottomVisorOverlay(1, 0);
}

/**
 * @brief 6e2d0 | 190 | Handles changing the currently viewed minimap
 * 
 */
void MapScreenChangeMap(void)
{
    u32 i;
    s32 j;
    u8 area;
    u8 viewables;
    struct MenuOamData* pOam;

    switch (PAUSE_SCREEN_DATA.changingMinimapStage)
    {
        case 1:
            // Get current area index
            for (i = 0; i < AREA_NORMAL_COUNT; i++)
            {
                if (PAUSE_SCREEN_DATA.currentArea == sMapScreenAreasViewOrder[i])
                    break;
            }
            
            // Leftover debug code?
            while (i >= AREA_DEBUG_1);

            while (TRUE)
            {
                // Pre increment i, no need to check for the current area
                i++;

                // Wrap around
                if (i >= AREA_DEBUG_1)
                    i = AREA_BRINSTAR;

                // Get viewables and area to test
                viewables = PAUSE_SCREEN_DATA.areasViewables;
                area = sMapScreenAreasViewOrder[i];

                // Check if the area can be viewed
                if ((viewables >> area) & 1)
                {
                    // Set as new area and exit
                    PAUSE_SCREEN_DATA.currentArea = area;
                    break;
                }
            }

            // Clear targets OAM
            pOam = PAUSE_SCREEN_DATA.targetsOam;
            for (j = 0; j < ARRAY_SIZE(PAUSE_SCREEN_DATA.targetsOam); j++, pOam++)
                pOam->exists = FALSE;

            // Disable samus icon
            PAUSE_SCREEN_DATA.samusIconOam[0].exists = FALSE;
            PAUSE_SCREEN_DATA.bg3cnt = PAUSE_SCREEN_DATA.unk_6E;
            SoundPlay(SOUND_MAP_SCREEN_CHANGE_MAP);
            PAUSE_SCREEN_DATA.changingMinimapStage++;
            break;

        case 2:
            // Transfer minimap data
            DmaTransfer(3, PAUSE_SCREEN_DATA.mapsDataPointer[PAUSE_SCREEN_DATA.currentArea],
                VRAM_BASE + 0xE000, sizeof(*PAUSE_SCREEN_DATA.mapsDataPointer), 16);

            // Update chozo hints
            ChozoStatueHintDeterminePath(TRUE);

            // Set where to put the map position
            PauseScreenMapSetSpawnPosition(PAUSE_SCREEN_DATA.currentArea != gCurrentArea ? 2 : 0);

            PAUSE_SCREEN_DATA.samusIconOam[0].exists = OAM_ID_CHANGED_FLAG;
            
            // Update highlight
            PauseScreenUpdateWorldMapHighlight(PAUSE_SCREEN_DATA.currentArea);

            // Update world map
            if (PAUSE_SCREEN_DATA.onWorldMap)
                PauseScreenUpdateWorldMap(TRUE);
            
            PAUSE_SCREEN_DATA.bg3cnt = PAUSE_SCREEN_DATA.unk_6C;

            // Update palette and boss icons
            LoadPauseScreenBgPalette();
            PauseScreenUpdateBossIcons();
            PAUSE_SCREEN_DATA.changingMinimapStage++;
            break;

        case 3:
            // Update IGT
            PauseScreenCountTanksInArea();
            PauseScreenDrawIgtAndTanks(FALSE, FALSE);
            PAUSE_SCREEN_DATA.changingMinimapStage++;

        case 4:
            // Update tanks
            PauseScreenDrawIgtAndTanks(FALSE, TRUE);
            PAUSE_SCREEN_DATA.changingMinimapStage = 0;
    }
}
