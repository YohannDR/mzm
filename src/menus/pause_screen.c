#include "menus/pause_screen.h"
#include "temp_globals.h"
#include "gba.h"
#include "macros.h"
#include "oam_id.h"
#include "event.h"

#include "data/shortcut_pointers.h"
#include "data/menus/pause_screen_data.h"
#include "data/menus/internal_pause_screen_data.h"

#include "constants/connection.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/menus/pause_screen.h"

#include "structs/menus/pause_screen.h"
#include "structs/display.h"
#include "structs/game_state.h"

u8 unk_68168(u16 param_1, u8 param_2, u8 param_3)
{

}

u8 unk_681c8(void)
{

}

u32 PauseScreenUpdateOrStartFading(u8 stage)
{

}

/**
 * @brief 685b8 | 98 | Copies palram to ewram, unused
 * 
 * @param param_1 To document
 */
void PauseScreenCopyPalramToEwram_Unused(u8 param_1)
{
    if (!param_1)
    {
        DMATransfer(3, PALRAM_BASE, sEwramPointer + 0x6800, PALRAM_SIZE, 16);
        BitFill(3, 0, PALRAM_BASE, PALRAM_SIZE, 16);
        DMATransfer(3, PALRAM_BASE, sEwramPointer + 0x6C00, PALRAM_SIZE, 16);
    }
    else
    {
        DMATransfer(3, PALRAM_BASE, sEwramPointer + 0x6800, PALRAM_SIZE, 16);
    }

    PAUSE_SCREEN_DATA.mapScreenFading.stage = 0;
}

/**
 * @brief 68650 | 44 | Copies the palram backup in ewram to palram
 * 
 */
void PauseScreenCopyBackgroundPalette_Unused(void)
{
    if (PAUSE_SCREEN_DATA.mapScreenFading.unk_2)
    {
        DMATransfer(3, sEwramPointer + 0x6C00, PALRAM_BASE, PALRAM_SIZE, 16);
        PAUSE_SCREEN_DATA.mapScreenFading.unk_2 = FALSE;
    }
}

/**
 * @brief 68694 | 208 | Updates the map screen scroll arrows
 * 
 */
void PauseScreenUpdateMapArrows(void)
{
    i32 var_0;

    if (gPauseScreenFlag != PAUSE_SCREEN_PAUSE_OR_CUTSCENE)
        return;

    if (PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine == PAUSE_SCREEN_SUBROUTINE_MAP_SCREEN)
        var_0 = 1;
    else if (PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine == PAUSE_SCREEN_SUBROUTINE_STATUS_SCREEN_LEAVING)
        var_0 = 2;
    else
        var_0 = 0;

    if (var_0)
    {
        // Set can scroll flags depending on the view position
        PAUSE_SCREEN_DATA.canScrollUp = PAUSE_SCREEN_DATA.mapViewY > PAUSE_SCREEN_DATA.mapTopBorder;
        PAUSE_SCREEN_DATA.canScrollDown = PAUSE_SCREEN_DATA.mapBottomBorder > PAUSE_SCREEN_DATA.mapViewY;
        PAUSE_SCREEN_DATA.canScrollLeft = PAUSE_SCREEN_DATA.mapViewX > PAUSE_SCREEN_DATA.mapLeftBorder;
        PAUSE_SCREEN_DATA.canScrollRight = PAUSE_SCREEN_DATA.mapRightBorder > PAUSE_SCREEN_DATA.mapViewX;

        // Draw if can scroll
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[0]].notDrawn = PAUSE_SCREEN_DATA.canScrollRight ? FALSE : TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[4]].notDrawn = PAUSE_SCREEN_DATA.canScrollLeft ? FALSE : TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[8]].notDrawn = PAUSE_SCREEN_DATA.canScrollUp ? FALSE : TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[12]].notDrawn = PAUSE_SCREEN_DATA.canScrollDown ? FALSE : TRUE;
    }
    else
    {
        // Not on map screen, set not drawn
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[0]].notDrawn = TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[4]].notDrawn = TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[8]].notDrawn = TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[12]].notDrawn = TRUE;
    }

    // Update world map area highlight
    if (var_0 == 1)
    {
        PAUSE_SCREEN_DATA.areaNameOam[2].notDrawn = PAUSE_SCREEN_DATA.onWorldMap ? TRUE : FALSE;
    }
    else
    {
        PAUSE_SCREEN_DATA.areaNameOam[2].notDrawn = TRUE;
    }
}

/**
 * @brief 6889c | c0 | Updates the boss icons
 * 
 */
void PauseScreenUpdateBossIcons(void)
{
    u32 status;

    // Prevent overflow
    if (PAUSE_SCREEN_DATA.currentArea >= MAX_AMOUNT_OF_AREAS - 1)
        return;

    // Event field
    status = sBossIcons[PAUSE_SCREEN_DATA.currentArea][0];
    if (status != 0)
    {
        // X Position * tile size + X Offset
        PAUSE_SCREEN_DATA.bossIconOam[0].xPosition = sBossIcons[PAUSE_SCREEN_DATA.currentArea][2] * HALF_BLOCK_SIZE +
            sBossIcons[PAUSE_SCREEN_DATA.currentArea][4] * 4;

        // Y Position * tile size
        PAUSE_SCREEN_DATA.bossIconOam[0].yPosition = sBossIcons[PAUSE_SCREEN_DATA.currentArea][3] * HALF_BLOCK_SIZE;

        // Check event
        if (EventFunction(EVENT_ACTION_CHECKING, status))
        {
            // Boss dead, set new oam id
            if (PAUSE_SCREEN_DATA.currentArea != AREA_CRATERIA)
            {
                // Boss dead id, flag id changed
                PAUSE_SCREEN_DATA.bossIconOam[0].oamID = 3;
                status = TRUE << 1;
            }
            else
            {
                // Ship, simply remove it
                PAUSE_SCREEN_DATA.bossIconOam[0].oamID = 0;
                status = FALSE;
            }
        }
        else
        {
            // Set oam id
            PAUSE_SCREEN_DATA.bossIconOam[0].oamID = sBossIcons[PAUSE_SCREEN_DATA.currentArea][1];
            // Flag id changed
            status = TRUE << 1;
        }
    }

    PAUSE_SCREEN_DATA.bossIconOam[0].exists = status;
}

/**
 * @brief 6895c | fc | Draws the completion info (tanks, IGT)
 * 
 * @param dontDraw Don't draw flag
 */
void PauseScreenDrawCompletionInfo(u8 dontDraw)
{
    u8 cantDraw;
    u32 i;
    u8 priority;
    u16 offset;

    cantDraw = FALSE;

    // Draw if already completed game
    if (!gGameCompletion.completedGame)
        cantDraw = TRUE;

    // Draw if on map screen
    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_ON_MAP_SCREEN)
        cantDraw = TRUE;

    if (cantDraw)
    {
        PAUSE_SCREEN_DATA.unk_34 = 0;
        return;
    }

    if (dontDraw)
        return;

    // Count tanks and prepare VRAM with IGT and tanks
    count_tanks_in_area();
    draw_igt_and_tanks(FALSE, FALSE);
    draw_igt_and_tanks(FALSE, TRUE);

    priority = 3;

    // Setup oam data
    for (i = 0; i < ARRAY_SIZE(sPauseScreenCompletionInfoOamData[0]); i++)
    {
        // Set oam id and priority
        PAUSE_SCREEN_DATA.miscOam[sPauseScreenCompletionInfoOamData[i][0]].oamID = sPauseScreenCompletionInfoOamData[i][1];
        PAUSE_SCREEN_DATA.miscOam[sPauseScreenCompletionInfoOamData[i][0]].priority = priority;

        // Set positions
        PAUSE_SCREEN_DATA.miscOam[sPauseScreenCompletionInfoOamData[i][0]].xPosition = sPauseScreenCompletionInfoOamData[i][2];
        PAUSE_SCREEN_DATA.miscOam[sPauseScreenCompletionInfoOamData[i][0]].yPosition = sPauseScreenCompletionInfoOamData[i][3];
        
        // Mark as existing
        PAUSE_SCREEN_DATA.miscOam[sPauseScreenCompletionInfoOamData[i][0]].exists = TRUE;
    }
}

u8 unk_68a58(u8 param_1)
{

}

u8 PauseScreenDrawStatusScreenSamus(u8 param_1)
{

}

void PauseScreenUpdateWireframeSamus(u8 param_1)
{

}

void unk_68ec0(void)
{

}

/**
 * @brief 68fd0 | 54 | Updates the area name icon
 * 
 * @param area Area
 */
void PauseScreenUpdateWorldMapHighlight(u8 area)
{
    // Prevent overflow
    if (area >= MAX_AMOUNT_OF_AREAS - 1)
        area = AREA_DEBUG;

    // Update area name at the top
    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.areaNameOam[0], sPauseScreenAreIconsData[area].nameOamId);
    
    // Update hightlight border oam
    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.areaNameOam[2], sPauseScreenAreIconsData[area].highlightOamId);

    // Update hightlight border position
    PAUSE_SCREEN_DATA.areaNameOam[2].xPosition = sPauseScreenAreIconsData[area].xPosition;
    PAUSE_SCREEN_DATA.areaNameOam[2].yPosition = sPauseScreenAreIconsData[area].yPosition;
}

void PauseScreenUpdateWorldMap(u8 onWorldMap)
{

}

void PauseScreenLoadAreaNamesAndIcons(void)
{

}

/**
 * @brief 695bc | f0 | Processes the pause screen oam
 * 
 */
void PauseScreenProcessOam(void)
{
    gNextOamSlot = 0;

    // Always process area name oam
    ProcessMenuOam(ARRAY_SIZE(PAUSE_SCREEN_DATA.areaNameOam), PAUSE_SCREEN_DATA.areaNameOam, sPauseScreenAreaNameOam);

    // Check process border arrows or world map oam
    if (PAUSE_SCREEN_DATA.onWorldMap)
    {
        ProcessMenuOam(ARRAY_SIZE(PAUSE_SCREEN_DATA.worldMapOam), PAUSE_SCREEN_DATA.worldMapOam, sPauseScreenWorldMapOam);
    }
    else
    {
        ProcessMenuOam(ARRAY_SIZE(PAUSE_SCREEN_DATA.borderArrowsOam), PAUSE_SCREEN_DATA.borderArrowsOam, sPauseScreenBorderArrowsOam);
    }

    // Always process misc oam
    ProcessMenuOam(ARRAY_SIZE(PAUSE_SCREEN_DATA.miscOam), PAUSE_SCREEN_DATA.miscOam, sPauseScreenMiscOam);

    // Check process chozo hint oam
    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_CHOZO_STATUE_HINT)
    {
        ProcessMenuOam(ARRAY_SIZE(PAUSE_SCREEN_DATA.chozoHintOam), PAUSE_SCREEN_DATA.chozoHintOam, sPauseScreenTargetsOam);
    }

    // Check process map oam
    if (!PAUSE_SCREEN_DATA.onWorldMap && !(PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_ON_STATUS_SCREEN))
    {
        // Process samus head icon oam if checking out current area map
        if (PAUSE_SCREEN_DATA.currentArea == gCurrentArea)
        {
            ProcessMenuOam(ARRAY_SIZE(PAUSE_SCREEN_DATA.samusIconOam), PAUSE_SCREEN_DATA.samusIconOam, sPauseScreenSamusIconOam);
        }

        // Process targets and boss icons
        ProcessMenuOam(ARRAY_SIZE(PAUSE_SCREEN_DATA.targetsOam), PAUSE_SCREEN_DATA.targetsOam, sPauseScreenTargetsOam);
        ProcessMenuOam(ARRAY_SIZE(PAUSE_SCREEN_DATA.bossIconOam), PAUSE_SCREEN_DATA.bossIconOam, sPauseScreenBossIconsOam);
    }

    ResetFreeOam();
}

/**
 * @brief 696ac | 364 | Processes a set of menu oam
 * 
 * @param length Length of Oam buffer (number of objects)
 * @param pOam Oam buffer pointer
 * @param pOamData Oam array pointer
 */
void ProcessMenuOam(u8 length, struct MenuOamData* pOam, const struct OamArray* pOamData)
{
    u16* dst;
    const u16* src;
    u32 part;
    i32 currSlot;
    i32 nextSlot;
    i32 i;
    const struct FrameData* pFrame;
    i32 yPosition;
    i32 xPosition;

    dst = (u16*)gOamData;
    nextSlot = gNextOamSlot;
    currSlot = nextSlot;
    dst = (u16*)(&gOamData[nextSlot]);

    for (i = 0; i < length; i++, pOam++)
    {
        // No id, don't process
        if (pOam->oamID == 0)
            continue;

        // Doesn't exist, don't process
        if (!pOam->exists)
            continue;

        // Second bit indicates that the oam id changed
        if (pOam->exists == TRUE << 1)
        {
            // Set exist
            pOam->exists = TRUE;

            // Reset animation
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
        }

        pOam->ended = FALSE;

        // Get frame data
        pFrame = pOamData[pOam->oamID].pOam;

        if (pOam->animationDurationCounter >= pFrame[pOam->currentAnimationFrame].timer)
        {
            // Current animation frame has ended, apply pre action
            switch (pOamData[pOam->oamID].preAction)
            {
                case OAM_ARRAY_PRE_ACTION_NONE:
                    break;

                case OAM_ARRAY_PRE_ACTION_CHANGE_FRAME:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Loop back to start
                        pOam->currentAnimationFrame = 0;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_RESET_FRAME:
                    // Reset timer, makes the animation stay on the current frame forever
                    pOam->animationDurationCounter = 0;
                    break;

                case OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME:
                    // Get current frame timer
                    part = pFrame[pOam->currentAnimationFrame].timer;
                    // Advance to next frame
                    pOam->currentAnimationFrame++;

                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Animation ended, go back to previous frame and lock at the max timer
                        pOam->currentAnimationFrame--;
                        pOam->animationDurationCounter = part - 1;

                        // Set ended flag
                        pOam->ended = TRUE;
                    }
                    else
                    {
                        // Reset timer, continue animation
                        pOam->animationDurationCounter = 0;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_KILL_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Kill oam
                        pOam->oamID = 0;
                        pOam->currentAnimationFrame = 0;
                        pOam->exists = FALSE;

                        // Oam is dead, skip further processing
                        continue;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Increment oam id and fetch new frame data
                        pOam->oamID++;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case 6:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Increment oam id and fetch new frame data
                        pOam->oamID++;
                        // Lock on last frame, pretty unsafe as the number of frames need to be the same
                        pOam->currentAnimationFrame--;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Decrement oam id and fetch new frame data
                        pOam->oamID--;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME:
                    pOam->animationDurationCounter = 0;

                    // Check animation ended, it's played backwards
                    if (pOam->currentAnimationFrame == 0)
                    {
                        // Kill oam
                        pOam->oamID = 0;
                        pOam->currentAnimationFrame = 0;
                        pOam->exists = FALSE;

                        // Oam is dead, skip further processing
                        continue;
                    }
                    else
                    {
                        // Move back to previous frame
                        pOam->currentAnimationFrame--;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AT_BEGINNING:
                    pOam->animationDurationCounter = 0;

                    // Check animation ended, it's played backwards
                    if (pOam->currentAnimationFrame != 0)
                    {
                        // Move back to previous frame
                        pOam->currentAnimationFrame--;
                    }
                    else
                    {
                        // Decrement oam id and fetch new frame data
                        pOam->oamID--;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;
            }
        }

        // Increment animation timer
        pOam->animationDurationCounter++;

        // Check should draw
        if (pOam->notDrawn)
            continue;

        // Fetch background positions based on the bound background
        if (pOam->boundBackground == 0)
        {
            xPosition = (i16)gBG0HOFS_NonGameplay;
            yPosition = (i16)gBG0VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 1)
        {
            xPosition = (i16)gBG1HOFS_NonGameplay;
            yPosition = (i16)gBG1VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 2)
        {
            xPosition = (i16)gBG2HOFS_NonGameplay;
            yPosition = (i16)gBG2VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 3)
        {
            xPosition = (i16)gBG3HOFS_NonGameplay;
            yPosition = (i16)gBG3VOFS_NonGameplay;
        }
        else
        {
            // No background, use absolute position
            xPosition = 0;
            yPosition = 0;
        }

        // Offset position by background and global offset
        yPosition = (i16)((pOam->yPosition >> 2) - (yPosition >> 2) + gOamYOffset_NonGameplay);
        xPosition = (i16)((pOam->xPosition >> 2) - (xPosition >> 2) + gOamXOffset_NonGameplay);

        // Offset by current frame
        pFrame = &pFrame[pOam->currentAnimationFrame];

        // Get raw data pointer
        src = pFrame->pFrame;

        // Check for buffer overflow
        if (nextSlot + *src > 0x7F)
            break;

        // Add part count
        nextSlot += *src++;

        for (; currSlot < nextSlot; currSlot++)
        {
            // Copy raw contents and implement positions
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.y = part + yPosition;
            
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = (part + xPosition) & 0x1FF;
            *dst++ = *src++;

            // Write special parameters
            gOamData[currSlot].split.priority = pOam->priority;
            gOamData[currSlot].split.objMode = pOam->objMode;
            
            dst++;
        }
    }

    // Update next oam slot
    gNextOamSlot = nextSlot;
}

/**
 * @brief 69a10 | 3b8 | Processes a set of menu oam (accounts for scaling/rotation)
 * 
 * @param length Length of Oam buffer (number of objects)
 * @param pOam Oam buffer pointer
 * @param pOamData Oam array pointer
 */
void ProcessComplexMenuOam(u8 length, struct MenuOamData* pOam, const struct OamArray* pOamData)
{
    u16* dst;
    const u16* src;
    u32 part;
    i32 currSlot;
    i32 nextSlot;
    i32 i;
    const struct FrameData* pFrame;
    i32 yPosition;
    i32 xPosition;

    dst = (u16*)gOamData;
    nextSlot = gNextOamSlot;
    currSlot = nextSlot;
    dst = (u16*)(&gOamData[nextSlot]);

    for (i = 0; i < length; i++, pOam++)
    {
        // No id, don't process
        if (pOam->oamID == 0)
            continue;

        // Doesn't exist, don't process
        if (!pOam->exists)
            continue;

        // Second bit indicates that the oam id changed
        if (pOam->exists == TRUE << 1)
        {
            // Set exist
            pOam->exists = TRUE;

            // Reset animation
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
        }

        pOam->ended = FALSE;

        // Get frame data
        pFrame = pOamData[pOam->oamID].pOam;

        if (pOam->animationDurationCounter >= pFrame[pOam->currentAnimationFrame].timer)
        {
            // Current animation frame has ended, apply pre action
            switch (pOamData[pOam->oamID].preAction)
            {
                case OAM_ARRAY_PRE_ACTION_NONE:
                    break;

                case OAM_ARRAY_PRE_ACTION_CHANGE_FRAME:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Loop back to start
                        pOam->currentAnimationFrame = 0;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_RESET_FRAME:
                    // Reset timer, makes the animation stay on the current frame forever
                    pOam->animationDurationCounter = 0;
                    break;

                case OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME:
                    // Get current frame timer
                    part = pFrame[pOam->currentAnimationFrame].timer;
                    // Advance to next frame
                    pOam->currentAnimationFrame++;

                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Animation ended, go back to previous frame and lock at the max timer
                        pOam->currentAnimationFrame--;
                        pOam->animationDurationCounter = part - 1;

                        // Set ended flag
                        pOam->ended = TRUE;
                    }
                    else
                    {
                        // Reset timer, continue animation
                        pOam->animationDurationCounter = 0;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_KILL_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Kill oam
                        pOam->oamID = 0;
                        pOam->currentAnimationFrame = 0;
                        pOam->exists = FALSE;

                        // Oam is dead, skip further processing
                        continue;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Increment oam id and fetch new frame data
                        pOam->oamID++;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case 6:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Increment oam id and fetch new frame data
                        pOam->oamID++;
                        // Lock on last frame, pretty unsafe as the number of frames need to be the same
                        pOam->currentAnimationFrame--;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Decrement oam id and fetch new frame data
                        pOam->oamID--;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME:
                    pOam->animationDurationCounter = 0;

                    // Check animation ended, it's played backwards
                    if (pOam->currentAnimationFrame == 0)
                    {
                        // Kill oam
                        pOam->oamID = 0;
                        pOam->currentAnimationFrame = 0;
                        pOam->exists = FALSE;

                        // Oam is dead, skip further processing
                        continue;
                    }
                    else
                    {
                        // Move back to previous frame
                        pOam->currentAnimationFrame--;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AT_BEGINNING:
                    pOam->animationDurationCounter = 0;

                    // Check animation ended, it's played backwards
                    if (pOam->currentAnimationFrame != 0)
                    {
                        // Move back to previous frame
                        pOam->currentAnimationFrame--;
                    }
                    else
                    {
                        // Decrement oam id and fetch new frame data
                        pOam->oamID--;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;
            }
        }

        // Increment animation timer
        pOam->animationDurationCounter++;

        // Check should draw
        if (pOam->notDrawn)
            continue;

        // Fetch background positions based on the bound background
        if (pOam->boundBackground == 0)
        {
            xPosition = (i16)gBG0HOFS_NonGameplay;
            yPosition = (i16)gBG0VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 1)
        {
            xPosition = (i16)gBG1HOFS_NonGameplay;
            yPosition = (i16)gBG1VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 2)
        {
            xPosition = (i16)gBG2HOFS_NonGameplay;
            yPosition = (i16)gBG2VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 3)
        {
            xPosition = (i16)gBG3HOFS_NonGameplay;
            yPosition = (i16)gBG3VOFS_NonGameplay;
        }
        else
        {
            // No background, use absolute position
            xPosition = 0;
            yPosition = 0;
        }

        // Offset position by background and global offset
        yPosition = (i16)((pOam->yPosition >> 2) - (yPosition >> 2) + gOamYOffset_NonGameplay);
        xPosition = (i16)((pOam->xPosition >> 2) - (xPosition >> 2) + gOamXOffset_NonGameplay);

        // Offset by current frame
        pFrame = &pFrame[pOam->currentAnimationFrame];

        // Get raw data pointer
        src = pFrame->pFrame;

        // Check for buffer overflow
        if (nextSlot + *src > 0x7F)
            break;

        // Add part count
        nextSlot += *src++;

        for (; currSlot < nextSlot; currSlot++)
        {
            if (pOam->rotationScaling)
            {
                // Parameters will be processed by a function, so simply copy the raw contents
                part = *src++;
                *dst++ = part;
                
                part = *src++;
                *dst++ = part;
                
                *dst++ = *src++;
                dst++;

                // Process scaling and rotation
                ProcessComplexOam(currSlot, xPosition, yPosition, gCurrentOamRotation, gCurrentOamScaling, TRUE, 0);
            }
            else
            {
                // Copy raw contents and implement positions
                part = *src++;
                *dst++ = part;

                gOamData[currSlot].split.y = part + yPosition;
                
                part = *src++;
                *dst++ = part;

                gOamData[currSlot].split.x = (part + xPosition) & 0x1FF;
                *dst++ = *src++;
                dst++;
            }

            // Write special parameters
            gOamData[currSlot].split.priority = pOam->priority;
            gOamData[currSlot].split.objMode = pOam->objMode;
        }
    }

    // Update next oam slot
    gNextOamSlot = nextSlot;
}

/**
 * @brief 69dc8 | 3b8 | Processes a set of cutscene oam
 * 
 * @param length Length of Oam buffer (number of objects)
 * @param pOam Oam buffer pointer
 * @param pOamData Oam array pointer
 */
void ProcessCutsceneOam(u8 length, struct CutsceneOamData* pOam, const struct OamArray* pOamData)
{
    u16* dst;
    const u16* src;
    u32 part;
    i32 currSlot;
    i32 nextSlot;
    i32 i;
    const struct FrameData* pFrame;
    i32 yPosition;
    i32 xPosition;

    dst = (u16*)gOamData;
    nextSlot = gNextOamSlot;
    currSlot = nextSlot;
    dst = (u16*)(&gOamData[nextSlot]);

    for (i = 0; i < length; i++, pOam++)
    {
        // No id, don't process
        if (pOam->oamID == 0)
            continue;

        // Doesn't exist, don't process
        if (!pOam->exists)
            continue;

        // Second bit indicates that the oam id changed
        if (pOam->exists == TRUE << 1)
        {
            // Set exist
            pOam->exists = TRUE;

            // Reset animation
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
        }

        pOam->ended = FALSE;

        // Get frame data
        pFrame = pOamData[pOam->oamID].pOam;

        if (pOam->animationDurationCounter >= pFrame[pOam->currentAnimationFrame].timer)
        {
            // Current animation frame has ended, apply pre action
            switch (pOamData[pOam->oamID].preAction)
            {
                case OAM_ARRAY_PRE_ACTION_NONE:
                    break;

                case OAM_ARRAY_PRE_ACTION_CHANGE_FRAME:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Loop back to start
                        pOam->currentAnimationFrame = 0;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_RESET_FRAME:
                    // Reset timer, makes the animation stay on the current frame forever
                    pOam->animationDurationCounter = 0;
                    break;

                case OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME:
                    // Get current frame timer
                    part = pFrame[pOam->currentAnimationFrame].timer;
                    // Advance to next frame
                    pOam->currentAnimationFrame++;

                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Animation ended, go back to previous frame and lock at the max timer
                        pOam->currentAnimationFrame--;
                        pOam->animationDurationCounter = part - 1;

                        // Set ended flag
                        pOam->ended = TRUE;
                    }
                    else
                    {
                        // Reset timer, continue animation
                        pOam->animationDurationCounter = 0;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_KILL_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Kill oam
                        pOam->oamID = 0;
                        pOam->currentAnimationFrame = 0;
                        pOam->exists = FALSE;

                        // Oam is dead, skip further processing
                        continue;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Increment oam id and fetch new frame data
                        pOam->oamID++;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case 6:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Increment oam id and fetch new frame data
                        pOam->oamID++;
                        // Lock on last frame, pretty unsafe as the number of frames need to be the same
                        pOam->currentAnimationFrame--;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Decrement oam id and fetch new frame data
                        pOam->oamID--;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME:
                    pOam->animationDurationCounter = 0;

                    // Check animation ended, it's played backwards
                    if (pOam->currentAnimationFrame == 0)
                    {
                        // Kill oam
                        pOam->oamID = 0;
                        pOam->currentAnimationFrame = 0;
                        pOam->exists = FALSE;

                        // Oam is dead, skip further processing
                        continue;
                    }
                    else
                    {
                        // Move back to previous frame
                        pOam->currentAnimationFrame--;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AT_BEGINNING:
                    pOam->animationDurationCounter = 0;

                    // Check animation ended, it's played backwards
                    if (pOam->currentAnimationFrame != 0)
                    {
                        // Move back to previous frame
                        pOam->currentAnimationFrame--;
                    }
                    else
                    {
                        // Decrement oam id and fetch new frame data
                        pOam->oamID--;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;
            }
        }

        // Increment animation timer
        pOam->animationDurationCounter++;

        // Check should draw
        if (pOam->notDrawn)
            continue;

        // Fetch background positions based on the bound background
        if (pOam->boundBackground == 0)
        {
            xPosition = (i16)gBG0HOFS_NonGameplay;
            yPosition = (i16)gBG0VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 1)
        {
            xPosition = (i16)gBG1HOFS_NonGameplay;
            yPosition = (i16)gBG1VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 2)
        {
            xPosition = (i16)gBG2HOFS_NonGameplay;
            yPosition = (i16)gBG2VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 3)
        {
            xPosition = (i16)gBG3HOFS_NonGameplay;
            yPosition = (i16)gBG3VOFS_NonGameplay;
        }
        else
        {
            // No background, use absolute position
            xPosition = 0;
            yPosition = 0;
        }

        // Offset position by background and global offset
        yPosition = (i16)((pOam->yPosition >> 2) - (yPosition >> 2) + gOamYOffset_NonGameplay);
        xPosition = (i16)((pOam->xPosition >> 2) - (xPosition >> 2) + gOamXOffset_NonGameplay);

        // Offset by current frame
        pFrame = &pFrame[pOam->currentAnimationFrame];

        // Get raw data pointer
        src = pFrame->pFrame;

        // Check for buffer overflow
        if (nextSlot + *src > 0x7F)
            break;

        // Add part count
        nextSlot += *src++;

        for (; currSlot < nextSlot; currSlot++)
        {
            if (pOam->rotationScaling)
            {
                // Parameters will be processed by a function, so simply copy the raw contents
                part = *src++;
                *dst++ = part;
                
                part = *src++;
                *dst++ = part;
                
                *dst++ = *src++;
                dst++;

                // Process scaling and rotation
                ProcessComplexOam(currSlot, xPosition, yPosition, gCurrentOamRotation, gCurrentOamScaling, TRUE, 0);
            }
            else
            {
                // Copy raw contents and implement positions
                part = *src++;
                *dst++ = part;

                gOamData[currSlot].split.y = part + yPosition;
                
                part = *src++;
                *dst++ = part;

                gOamData[currSlot].split.x = (part + xPosition) & 0x1FF;
                *dst++ = *src++;
                dst++;
            }

            // Write special parameters
            gOamData[currSlot].split.priority = pOam->priority;
            gOamData[currSlot].split.objMode = pOam->objMode;
        }
    }

    // Update next oam slot
    gNextOamSlot = nextSlot;
}

u32 PauseScreenSubroutine(void)
{

}

/**
 * @brief 6a2f8 | 130 | Pause screen V-blank
 * 
 */
void PauseScreenVBlank(void)
{
    dma_set(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / 4);

    write16(REG_DISPCNT, PAUSE_SCREEN_DATA.dispcnt);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);
    write16(REG_MOSAIC, gWrittenToMOSAIC_L);

    write16(REG_BG0HOFS, (gBG0HOFS_NonGameplay / 4) & 0x1FF);
    write16(REG_BG0VOFS, (gBG0VOFS_NonGameplay / 4) & 0x1FF);
    write16(REG_BG1HOFS, (gBG1HOFS_NonGameplay / 4) & 0x1FF);
    write16(REG_BG1VOFS, (gBG1VOFS_NonGameplay / 4) & 0x1FF);
    write16(REG_BG2HOFS, (gBG2HOFS_NonGameplay / 4) & 0x1FF);
    write16(REG_BG2VOFS, (gBG2VOFS_NonGameplay / 4) & 0x1FF);
    write16(REG_BG3HOFS, (gBG3HOFS_NonGameplay / 4) & 0x1FF);
    write16(REG_BG3VOFS, (gBG3VOFS_NonGameplay / 4) & 0x1FF);
    
    write16(REG_BG0CNT, PAUSE_SCREEN_DATA.bg0cnt);
    write16(REG_BG1CNT, PAUSE_SCREEN_DATA.bg1cnt);
    write16(REG_BG2CNT, PAUSE_SCREEN_DATA.bg2cnt);
    write16(REG_BG3CNT, PAUSE_SCREEN_DATA.bg3cnt);

    write16(REG_BLDALPHA, gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L);
    write16(REG_BLDCNT, PAUSE_SCREEN_DATA.bldcnt);
}

/**
 * @brief 6a428 | c | Pause screen empty V-blank
 * 
 */
void PauseScreenVBlank_Empty(void)
{
    vu8 c = 0;
}

void PauseScreenInit(void)
{

}

void PauseScreenDetermineMapsViewable(void)
{

}

void PauseScreenUpdateBottomVisorOverlay(u8 param_1, u8 param_2)
{

}

void PauseScreenGetMinimapData(u8 area, u16* dst)
{

}

u32 PauseScreenCallCurrentSubroutine(void)
{

}

void PauseScreenMoveDebugCursor(u8 allowOverflow)
{

}

u32 unk_6b66c(u16* param_1, u16 param_2)
{

}

u32 unk_6b6c4(u16* param_1, u16 param_2)
{

}

void PauseScreenUpdateTopVisorOverlay(u8 oamId)
{

}

i32 PauseScreenSuitChangingStart(void)
{

}

i32 PauseScreenStatusScreenInit(void)
{

}

i32 PauseScreenQuitStatusScreen(void)
{

}

i32 PauseScreenEasySleepInit(void)
{

}

i32 PauseScreenQuitEasySleep(void)
{

}

/**
 * @brief 6c0e0 | 74 | Updates the maintained input
 * 
 */
void CheckForMaintainedInput(void)
{
    gUnk_3005804 = gChangedInput;

    if (gButtonInput & MAINTAINED_INPUT_KEYS)
    {
        // Pressing any concerned key
        gMaintainedInputData.delay++;
    }
    else
    {
        // Not pressing any concerned key, reset
        gMaintainedInputData.delay = 0;
        gMaintainedInputData.set = 0;
    }

    // Check delay threshold
    if (gMaintainedInputData.delay >= sMaintainedInputDelays[gMaintainedInputData.set])
    {
        // Apply to changed input
        gChangedInput |= gButtonInput & MAINTAINED_INPUT_KEYS;

        // Reset delay
        gMaintainedInputData.delay = 0;

        // Update set
        if (gMaintainedInputData.set < ARRAY_SIZE(sMaintainedInputDelays) - 1)
            gMaintainedInputData.set++;
    }
}
