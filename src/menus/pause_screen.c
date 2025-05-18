#include "menus/pause_screen.h"
#include "temp_globals.h"
#include "gba.h"
#include "macros.h"
#include "minimap.h"
#include "oam_id.h"
#include "event.h"
#include "text.h"
#include "color_effects.h"
#include "callbacks.h"
#include "menus/status_screen.h"
#include "menus/pause_screen_map.h"
#include "menus/pause_screen_sub_menus.h"

#include "data/shortcut_pointers.h"
#include "data/menus/pause_screen_data.h"
#include "data/menus/status_screen_data.h"
#include "data/menus/internal_pause_screen_data.h"
#include "data/menus/pause_screen_map_data.h"

#include "constants/audio.h"
#include "constants/color_fading.h"
#include "constants/connection.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/menus/pause_screen.h"
#include "constants/menus/status_screen.h"

#include "structs/menus/pause_screen.h"
#include "structs/demo.h"
#include "structs/display.h"
#include "structs/minimap.h"
#include "structs/game_state.h"
#include "structs/text.h"

/**
 * @brief 68168 | 60 | Initialize the pause screen for fading
 * 
 * @param targetBldAlpha The target alpha blend level
 * @param bldAlphaStepLevel The amount to change alpha blend by
 * @param bldAlphaStepDelayThreshold Amount of time between each fade step
 * @return u32 bool, suceeded
 */
u32 PauseScreenInitFading(u16 targetBldAlpha, u8 bldAlphaStepLevel, s8 bldAlphaStepDelayThreshold)
{
    s32 _bldAlphaStepDelayThreshold = bldAlphaStepDelayThreshold;

    if (PAUSE_SCREEN_DATA.isFading)
        return FALSE;

    if (bldAlphaStepLevel == 0)
        return FALSE;

    PAUSE_SCREEN_DATA.isFading++;

    PAUSE_SCREEN_DATA.bldAlphaStepLevel = bldAlphaStepLevel;
    PAUSE_SCREEN_DATA.bldAlphaStepDelayThreshold = _bldAlphaStepDelayThreshold;

    PAUSE_SCREEN_DATA.targetBldAlpha_L = targetBldAlpha & 0x1F;
    PAUSE_SCREEN_DATA.targetBldAlpha_H = (targetBldAlpha >> 8) & 0x1F;

    PAUSE_SCREEN_DATA.bldAlphaStepTimer = 0;

    return TRUE;
}

/**
 * @brief 681c8 | 124 | Fade the screen to the desired alpha blend level
 * 
 * @return u8 bool, ended
 */
u8 PauseScreenApplyFading(void)
{
    u8 ended;

    ended = FALSE;

    if (PAUSE_SCREEN_DATA.isFading)
    {
        APPLY_DELTA_TIME_INC(PAUSE_SCREEN_DATA.bldAlphaStepTimer);
        // bldAlphaStepDelayThreshold is always 0 and bldAlphaStepTimer is strictly non-negative
        // thus this condition is always true
        if (PAUSE_SCREEN_DATA.bldAlphaStepDelayThreshold <= PAUSE_SCREEN_DATA.bldAlphaStepTimer)
        {
            PAUSE_SCREEN_DATA.bldAlphaStepTimer = 0;

            if (gWrittenToBLDALPHA_L != PAUSE_SCREEN_DATA.targetBldAlpha_L)
            {
                if (gWrittenToBLDALPHA_L > PAUSE_SCREEN_DATA.targetBldAlpha_L)
                {
                    if (gWrittenToBLDALPHA_L - PAUSE_SCREEN_DATA.targetBldAlpha_L > PAUSE_SCREEN_DATA.bldAlphaStepLevel)
                        gWrittenToBLDALPHA_L -= PAUSE_SCREEN_DATA.bldAlphaStepLevel;
                    else
                        gWrittenToBLDALPHA_L = PAUSE_SCREEN_DATA.targetBldAlpha_L;
                }
                else
                {
                    gWrittenToBLDALPHA_L += PAUSE_SCREEN_DATA.bldAlphaStepLevel;
                    if (gWrittenToBLDALPHA_L > PAUSE_SCREEN_DATA.targetBldAlpha_L)
                        gWrittenToBLDALPHA_L = PAUSE_SCREEN_DATA.targetBldAlpha_L;
                }
            }

            if (gWrittenToBLDALPHA_H != PAUSE_SCREEN_DATA.targetBldAlpha_H)
            {
                if (gWrittenToBLDALPHA_H > PAUSE_SCREEN_DATA.targetBldAlpha_H)
                {
                    if (gWrittenToBLDALPHA_H - PAUSE_SCREEN_DATA.targetBldAlpha_H > PAUSE_SCREEN_DATA.bldAlphaStepLevel)
                        gWrittenToBLDALPHA_H -= PAUSE_SCREEN_DATA.bldAlphaStepLevel;
                    else
                        gWrittenToBLDALPHA_H = PAUSE_SCREEN_DATA.targetBldAlpha_H;
                }
                else
                {
                    gWrittenToBLDALPHA_H += PAUSE_SCREEN_DATA.bldAlphaStepLevel;
                    if (gWrittenToBLDALPHA_H > PAUSE_SCREEN_DATA.targetBldAlpha_H)
                        gWrittenToBLDALPHA_H = PAUSE_SCREEN_DATA.targetBldAlpha_H;
                }
            }

            if (gWrittenToBLDALPHA_L == PAUSE_SCREEN_DATA.targetBldAlpha_L && gWrittenToBLDALPHA_H == PAUSE_SCREEN_DATA.targetBldAlpha_H)
            {
                PAUSE_SCREEN_DATA.isFading = FALSE;
                ended = TRUE;
            }
        }
    }

    return ended;
}

/**
 * @brief 682ec | 2cc | Starts and updates the pause screen fading
 * 
 * @param stage Stage to start
 * @return u32 bool, ended
 */
u32 PauseScreenUpdateOrStartFading(u8 stage)
{
    u16* src;
    u16* dst;

    if (stage)
        PAUSE_SCREEN_DATA.mapScreenFading.stage = stage;

    switch (PAUSE_SCREEN_DATA.mapScreenFading.stage)
    {
        case 0:
            break;

        case 1:
            if (!PAUSE_SCREEN_DATA.mapScreenFading.paletteUpdated)
            {
                PAUSE_SCREEN_DATA.mapScreenFading.colorToApply = 0;
                PAUSE_SCREEN_DATA.mapScreenFading.stage = 0;
                return TRUE;
            }
            break;

        case PAUSE_SCREEN_FADING_IN_INIT:
            DmaTransfer(3, PALRAM_BASE, PAUSE_SCREEN_EWRAM.originalBackgroundPalette, PALRAM_SIZE, 16);
            BitFill(3, 0, PALRAM_BASE, PALRAM_SIZE, 16);
            DmaTransfer(3, PALRAM_BASE, PAUSE_SCREEN_EWRAM.backgroundPalette, PALRAM_SIZE, 16);

            PAUSE_SCREEN_DATA.mapScreenFading.colorToApply = 0;
            PAUSE_SCREEN_DATA.mapScreenFading.paletteUpdated = FALSE;
            PAUSE_SCREEN_DATA.mapScreenFading.stage = PAUSE_SCREEN_FADING_IN;
            break;

        case PAUSE_SCREEN_FADING_IN:
            if (PAUSE_SCREEN_DATA.mapScreenFading.paletteUpdated)
                break;

            if (PAUSE_SCREEN_DATA.mapScreenFading.colorToApply < 32)
            {
                src = &PAUSE_SCREEN_EWRAM.originalBackgroundPalette[0];
                dst = &PAUSE_SCREEN_EWRAM.backgroundPalette[0];
                ApplySpecialBackgroundFadingColor(COLOR_FADING_TYPE_IN, PAUSE_SCREEN_DATA.mapScreenFading.colorToApply, &src, &dst, USHORT_MAX);

                src = &PAUSE_SCREEN_EWRAM.originalBackgroundPalette[16 * 16];
                dst = &PAUSE_SCREEN_EWRAM.backgroundPalette[16 * 16];
                ApplySpecialBackgroundFadingColor(COLOR_FADING_TYPE_IN, PAUSE_SCREEN_DATA.mapScreenFading.colorToApply, &src, &dst, USHORT_MAX);

                PAUSE_SCREEN_DATA.mapScreenFading.paletteUpdated = TRUE;
                if (PAUSE_SCREEN_DATA.mapScreenFading.colorToApply == 31)
                {
                    PAUSE_SCREEN_DATA.mapScreenFading.colorToApply++;
                    break;
                }

                if (PAUSE_SCREEN_DATA.mapScreenFading.colorToApply + 2 > 31)
                    PAUSE_SCREEN_DATA.mapScreenFading.colorToApply = 31;
                else
                    PAUSE_SCREEN_DATA.mapScreenFading.colorToApply += 2;
            }
            else
            {
                DmaTransfer(3, PAUSE_SCREEN_EWRAM.originalBackgroundPalette, PAUSE_SCREEN_EWRAM.backgroundPalette, PALRAM_SIZE, 16);
                PAUSE_SCREEN_DATA.mapScreenFading.paletteUpdated = TRUE;
                PAUSE_SCREEN_DATA.mapScreenFading.stage = 1;
            }
            break;

        case PAUSE_SCREEN_FADING_OUT_INIT:
            DmaTransfer(3, PALRAM_BASE, PAUSE_SCREEN_EWRAM.originalBackgroundPalette, PALRAM_SIZE, 16);

            PAUSE_SCREEN_DATA.mapScreenFading.colorToApply = 0;
            PAUSE_SCREEN_DATA.mapScreenFading.paletteUpdated = FALSE;
            PAUSE_SCREEN_DATA.mapScreenFading.stage = PAUSE_SCREEN_FADING_OUT;
            break;

        case PAUSE_SCREEN_FADING_OUT:
            if (PAUSE_SCREEN_DATA.mapScreenFading.paletteUpdated)
                break;
            
            if (PAUSE_SCREEN_DATA.mapScreenFading.colorToApply < 32)
            {
                src = &PAUSE_SCREEN_EWRAM.originalBackgroundPalette[0];
                dst = &PAUSE_SCREEN_EWRAM.backgroundPalette[0];
                ApplySpecialBackgroundFadingColor(COLOR_FADING_TYPE_OUT, PAUSE_SCREEN_DATA.mapScreenFading.colorToApply, &src, &dst, USHORT_MAX);

                src = &PAUSE_SCREEN_EWRAM.originalBackgroundPalette[16 * 16];
                dst = &PAUSE_SCREEN_EWRAM.backgroundPalette[16 * 16];
                ApplySpecialBackgroundFadingColor(COLOR_FADING_TYPE_OUT, PAUSE_SCREEN_DATA.mapScreenFading.colorToApply, &src, &dst, USHORT_MAX);

                PAUSE_SCREEN_DATA.mapScreenFading.paletteUpdated = TRUE;
                if (PAUSE_SCREEN_DATA.mapScreenFading.colorToApply == 31)
                {
                    PAUSE_SCREEN_DATA.mapScreenFading.colorToApply++;
                    break;
                }

                if (PAUSE_SCREEN_DATA.mapScreenFading.colorToApply + 2 > 31)
                    PAUSE_SCREEN_DATA.mapScreenFading.colorToApply = 31;
                else
                    PAUSE_SCREEN_DATA.mapScreenFading.colorToApply += 2;
            }
            else
            {
                BitFill(3, 0, PAUSE_SCREEN_EWRAM.backgroundPalette, PALRAM_SIZE, 16);
                PAUSE_SCREEN_DATA.mapScreenFading.paletteUpdated = TRUE;
                PAUSE_SCREEN_DATA.mapScreenFading.stage = 1;
            }
    }

    if (PAUSE_SCREEN_DATA.mapScreenFading.paletteUpdated)
    {
        DmaTransfer(3, PAUSE_SCREEN_EWRAM.backgroundPalette, PALRAM_BASE, PALRAM_SIZE, 16);
        PAUSE_SCREEN_DATA.mapScreenFading.paletteUpdated = FALSE;
    }

    return FALSE;
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
        DmaTransfer(3, PALRAM_BASE, PAUSE_SCREEN_EWRAM.originalBackgroundPalette, PALRAM_SIZE, 16);
        BitFill(3, 0, PALRAM_BASE, PALRAM_SIZE, 16);
        DmaTransfer(3, PALRAM_BASE, PAUSE_SCREEN_EWRAM.backgroundPalette, PALRAM_SIZE, 16);
    }
    else
    {
        DmaTransfer(3, PALRAM_BASE, PAUSE_SCREEN_EWRAM.originalBackgroundPalette, PALRAM_SIZE, 16);
    }

    PAUSE_SCREEN_DATA.mapScreenFading.stage = 0;
}

/**
 * @brief 68650 | 44 | Copies the palram backup in ewram to palram
 * 
 */
void PauseScreenCopyBackgroundPalette_Unused(void)
{
    if (PAUSE_SCREEN_DATA.mapScreenFading.paletteUpdated)
    {
        DmaTransfer(3, PAUSE_SCREEN_EWRAM.backgroundPalette, PALRAM_BASE, PALRAM_SIZE, 16);
        PAUSE_SCREEN_DATA.mapScreenFading.paletteUpdated = FALSE;
    }
}

/**
 * @brief 68694 | 208 | Updates the map screen scroll arrows
 * 
 */
void PauseScreenUpdateMapArrows(void)
{
    s32 onMapScreen;

    if (gPauseScreenFlag != PAUSE_SCREEN_PAUSE_OR_CUTSCENE)
        return;

    if (PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine == PAUSE_SCREEN_SUBROUTINE_MAP_SCREEN)
        onMapScreen = TRUE;
    else if (PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine == PAUSE_SCREEN_SUBROUTINE_STATUS_SCREEN_LEAVING)
        onMapScreen = TRUE + 1;
    else
        onMapScreen = FALSE;

    if (onMapScreen)
    {
        // Set can scroll flags depending on the view position
        PAUSE_SCREEN_DATA.canScrollUp = PAUSE_SCREEN_DATA.mapViewY > PAUSE_SCREEN_DATA.mapTopBorder;
        PAUSE_SCREEN_DATA.canScrollDown = PAUSE_SCREEN_DATA.mapBottomBorder > PAUSE_SCREEN_DATA.mapViewY;
        PAUSE_SCREEN_DATA.canScrollLeft = PAUSE_SCREEN_DATA.mapViewX > PAUSE_SCREEN_DATA.mapLeftBorder;
        PAUSE_SCREEN_DATA.canScrollRight = PAUSE_SCREEN_DATA.mapRightBorder > PAUSE_SCREEN_DATA.mapViewX;

        // Draw if can scroll
        PAUSE_SCREEN_DATA.borderArrowsOam[sMapScreenArrowsData[0][0]].notDrawn = PAUSE_SCREEN_DATA.canScrollRight ? FALSE : TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sMapScreenArrowsData[1][0]].notDrawn = PAUSE_SCREEN_DATA.canScrollLeft ? FALSE : TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sMapScreenArrowsData[2][0]].notDrawn = PAUSE_SCREEN_DATA.canScrollUp ? FALSE : TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sMapScreenArrowsData[3][0]].notDrawn = PAUSE_SCREEN_DATA.canScrollDown ? FALSE : TRUE;
    }
    else
    {
        // Not on map screen, set not drawn
        PAUSE_SCREEN_DATA.borderArrowsOam[sMapScreenArrowsData[0][0]].notDrawn = TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sMapScreenArrowsData[1][0]].notDrawn = TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sMapScreenArrowsData[2][0]].notDrawn = TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sMapScreenArrowsData[3][0]].notDrawn = TRUE;
    }

    // Update world map area highlight
    if (onMapScreen == TRUE)
    {
        PAUSE_SCREEN_DATA.overlayOam[2].notDrawn = PAUSE_SCREEN_DATA.onWorldMap ? TRUE : FALSE;
    }
    else
    {
        PAUSE_SCREEN_DATA.overlayOam[2].notDrawn = TRUE;
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
    if (PAUSE_SCREEN_DATA.currentArea >= AREA_NORMAL_COUNT)
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
                PAUSE_SCREEN_DATA.bossIconOam[0].oamID = BOSS_ICON_OAM_ID_CROSSMARK;
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
            status = OAM_ID_CHANGED_FLAG;
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

    #ifdef DEBUG
    if (!gDebugMode)
    #endif // DEBUG
    {
        // Draw if already completed game
        if (!gGameCompletion.completedGame)
            cantDraw = TRUE;
    }

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
    PauseScreenCountTanksInArea();
    PauseScreenDrawIgtAndTanks(FALSE, FALSE);
    PauseScreenDrawIgtAndTanks(FALSE, TRUE);

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

/**
 * @brief 68a58 | a8 | Determine if the category header should be drawn
 * 
 * @param samusWireframeDataIndex The current wireframe data index
 * @return u8 2 if the header is to be drawn, 0 otherwise
 */
u8 PauseScreenStatusScreenShouldDrawHeader(u8 samusWireframeDataIndex)
{
    u8 result;

    result = FALSE;
    if (gEquipment.suitType == SUIT_SUITLESS)
    {
        switch (samusWireframeDataIndex)
        {
            case SAMUS_WIREFRAME_DATA_BEAM:
                PAUSE_SCREEN_DATA.miscOam[3].oamID = MISC_OAM_ID_GUN_HEADER;
                result = TRUE << 1;
                break;

            case SAMUS_WIREFRAME_DATA_ENERGY:
                result = TRUE << 1;
                break;

            case SAMUS_WIREFRAME_DATA_MISSILE:
                break;
        }
    }
    else
    {
        switch (samusWireframeDataIndex)
        {
            case SAMUS_WIREFRAME_DATA_MISSILE:
                if (gEquipment.maxMissiles + gEquipment.maxSuperMissiles != 0)
                    result = TRUE << 1;
                break;

            case SAMUS_WIREFRAME_DATA_BOMB:
                if (PAUSE_SCREEN_DATA.statusScreenData.bombActivation[0])
                    result = TRUE << 1;
                break;

            case SAMUS_WIREFRAME_DATA_MISC:
                if (PAUSE_SCREEN_DATA.statusScreenData.miscActivation[0])
                    result = TRUE << 1;
                break;

            case SAMUS_WIREFRAME_DATA_ENERGY:
            case SAMUS_WIREFRAME_DATA_BEAM:
            case SAMUS_WIREFRAME_DATA_SUIT:
                result = TRUE << 1;

            case SAMUS_WIREFRAME_DATA_SAMUS_POWER_SUIT_WIREFRAME:
        }
    }

    return result;
}

/**
 * @brief 68af8 | 2c4 | Draws samus on the status screen
 * 
 * @param param_1 To document
 * @return u8 bool, wireframe part was not in position
 */
u32 PauseScreenUpdateStatusScreenOam(u8 param_1)
{
    s32 i;
    struct MenuOamData* pOam;
    u8 result;
    s32 size;
    s16 xPosition;

    result = FALSE;
    pOam = &PAUSE_SCREEN_DATA.miscOam[2];
    size = ARRAY_SIZE(sSamusWireframeData);

    switch (param_1)
    {
        // PAUSE_SCREEN_TYPE_GETTING_NEW_ITEM
        case 0:
            for (i = 0; i < size; i++, pOam++)
            {
                pOam->oamID = sSamusWireframeData[i].oamId;
                pOam->xPosition = sSamusWireframeData[i].xPosition;
                pOam->yPosition = sSamusWireframeData[i].yPosition;
                pOam->objMode = sSamusWireframeData[i].objMode;
                pOam->exists = PauseScreenStatusScreenShouldDrawHeader(i);
            }

            PauseScreenUpdateWireframeSamus(0);
            break;

        // Flag as status screen
        case 1:
            for (i = 0; i < size; i++, pOam++)
            {
                pOam->oamID = sSamusWireframeData[i].oamId;
                pOam->xPosition = sSamusWireframeData[i].xPosition + sSamusWireframeData[i].xOffset;
                pOam->yPosition = sSamusWireframeData[i].yPosition;
                pOam->objMode = sSamusWireframeData[i].objMode;
                pOam->exists = PauseScreenStatusScreenShouldDrawHeader(i);
            }

            PauseScreenUpdateWireframeSamus(1);
            PAUSE_SCREEN_DATA.dispcnt |= DCNT_WINOBJ;
            PAUSE_SCREEN_DATA.samusIconOam[0].exists = FALSE;
            break;

        // // Flag as status screen + 1
        case 2:
            result = TRUE;
            
            for (i = 0; i < size - 1; i++, pOam++)
            {
                if (!pOam->exists)
                    continue;

                xPosition = sSamusWireframeData[i].xPosition;
                if (pOam->xPosition != xPosition)
                {
                    result = FALSE;
                    pOam->xPosition -= BLOCK_SIZE;
                    if (pOam->xPosition < xPosition)
                        pOam->xPosition = xPosition;
                }
            }
            break;

        // Update upgrade headers
        case 3:
            pOam->exists = FALSE;
            pOam++;

            for (i = 1; i < size - 1; i++, pOam++)
            {
                if (!pOam->exists)
                    continue;

                pOam->exists = TRUE << 1;
                pOam->oamID++;
                pOam->xPosition = sSamusWireframeData[i].xPosition2;
                pOam->yPosition = sSamusWireframeData[i].yPosition2;
            }
            break;

        // StatusScreenSuitlessItems()
        case 4:
            for (i = 0; i < size - 1; i++, pOam++)
            {
                if (!pOam->exists)
                    continue;

                pOam->objMode = 1;

                if (i == 0)
                    continue;

                pOam->oamID++;
                pOam->animationDurationCounter = 0;
                if (pOam->currentAnimationFrame)
                    pOam->currentAnimationFrame--;
            }
            break;

        // PauseScreenInitFading (out)
        case 5:
            PAUSE_SCREEN_DATA.miscOam[2].exists = FALSE;
            PAUSE_SCREEN_DATA.miscOam[3].exists = FALSE;
            PAUSE_SCREEN_DATA.miscOam[4].exists = FALSE;
            PAUSE_SCREEN_DATA.miscOam[5].exists = FALSE;
            PAUSE_SCREEN_DATA.miscOam[6].exists = FALSE;
            PAUSE_SCREEN_DATA.miscOam[7].exists = FALSE;
            PAUSE_SCREEN_DATA.miscOam[8].exists = FALSE;
            PAUSE_SCREEN_DATA.miscOam[9].exists = FALSE;
            PAUSE_SCREEN_DATA.dispcnt &= ~DCNT_WINOBJ;
            PAUSE_SCREEN_DATA.samusIconOam[0].exists = OAM_ID_CHANGED_FLAG;
            break;
    }

    return result;
}

/**
 * @brief 68dbc | 104 | Updates the samus wireframe object
 * 
 * @param updateWireframeOption 0 if getting new suit, 1 if no suit change, 2 if changing suits
 */
void PauseScreenUpdateWireframeSamus(u8 updateWireframeOption)
{
    u8 oamId;

    if (updateWireframeOption == 2)
    {
        if (PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeStage == 0)
        {
            PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeStage = 1;
            PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeTimer = 0;
        }
        return;
    }

    if (gEquipment.suitType == SUIT_NORMAL)
        oamId = MISC_OAM_ID_SAMUS_POWER_SUIT_WIREFRAME;
    else if (gEquipment.suitType == SUIT_FULLY_POWERED)
        oamId = MISC_OAM_ID_SAMUS_FULL_SUIT_WIREFRAME;
    else if (gEquipment.suitType == SUIT_SUITLESS)
        oamId = MISC_OAM_ID_SAMUS_SUITLESS_WIREFRAME;
    else
        oamId = MISC_OAM_ID_SAMUS_POWER_SUIT_WIREFRAME;

    if (updateWireframeOption == 0 && gPauseScreenFlag == PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS)
        oamId = MISC_OAM_ID_SAMUS_SUITLESS_WIREFRAME;

    PAUSE_SCREEN_DATA.miscOam[8].oamID = oamId;
    PAUSE_SCREEN_DATA.miscOam[8].exists = OAM_ID_CHANGED_FLAG;

    PAUSE_SCREEN_DATA.miscOam[9] = PAUSE_SCREEN_DATA.miscOam[8];
    PAUSE_SCREEN_DATA.miscOam[9].objMode = 2;

    oamId = 0;
    if (PAUSE_SCREEN_DATA.miscOam[8].oamID == MISC_OAM_ID_SAMUS_SUITLESS_WIREFRAME)
        oamId = 3;
    else if (gEquipment.suitMiscActivation & SMF_GRAVITY_SUIT)
        oamId = 2;
    else if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
        oamId = 1;

    DmaTransfer(3, &sSamusWireframePal[oamId * 16], sObjPalramPointer + 16 * 4, 16 * 2, 16);
}

/**
 * @brief 68ec0 | 110 | Handle suit transition fade
 * 
 */
void PauseScreenFadeWireframeSamus(void)
{
    APPLY_DELTA_TIME_INC(PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeTimer);

    switch (PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeStage)
    {
        case 0:
            break;

        case 1:
            PAUSE_SCREEN_DATA.bldcnt &= ~BLDCNT_BG2_FIRST_TARGET_PIXEL;
            write8(REG_WINOUT + 1, 0xD0);
            PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeStage++;
            break;

        case 2:
            if (gWrittenToBLDALPHA_H < 16)
                gWrittenToBLDALPHA_H += 2;

            if (gWrittenToBLDALPHA_H > 16)
                gWrittenToBLDALPHA_H = 16;

            gWrittenToBLDALPHA_L = 16 - gWrittenToBLDALPHA_H;
            if (gWrittenToBLDALPHA_L == 0)
            {
                PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeStage++;
                PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeTimer = 0;
            }
            break;

        case 3:
            PauseScreenUpdateWireframeSamus(1);
            PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeStage++;
            PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeTimer = 0;
            break;

        case 4:
            PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeStage++;
            PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeTimer = 0;

        case 5:
            if (gWrittenToBLDALPHA_L < 16)
                gWrittenToBLDALPHA_L += 2;

            if (gWrittenToBLDALPHA_L > 16)
                gWrittenToBLDALPHA_L = 16;

            gWrittenToBLDALPHA_H = 16 - gWrittenToBLDALPHA_L;
            if (gWrittenToBLDALPHA_H == 0)
            {
                PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeStage++;
                PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeTimer = 0;
            }
            break;

        case 6:
            PAUSE_SCREEN_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL |
                BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;
            write8(REG_WINOUT + 1, (WIN1_BG3 | WIN1_OBJ) >> 8);
            PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeStage = 0;
            break;
    }
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
        area = AREA_DEBUG_1;

    // Update area name at the top
    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.overlayOam[0], sPauseScreenAreaIconsData[area].nameSpawningOamId);
    
    // Update hightlight border oam
    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.overlayOam[2], sPauseScreenAreaIconsData[area].outlineOamId);

    // Update hightlight border position
    PAUSE_SCREEN_DATA.overlayOam[2].xPosition = sPauseScreenAreaIconsData[area].xPosition;
    PAUSE_SCREEN_DATA.overlayOam[2].yPosition = sPauseScreenAreaIconsData[area].yPosition;
}

/**
 * @brief 69024 | 1e8 | Updates the world map oam
 * 
 * @param onWorldMap On world map
 */
void PauseScreenUpdateWorldMap(u8 onWorldMap)
{
    struct MenuOamData* pOam;
    s32 i;
    u32 status;

    if (onWorldMap == FALSE)
    {
        pOam = &PAUSE_SCREEN_DATA.worldMapOam[0];
        pOam->priority = 2;
        pOam->oamID = gEquipment.suitType == SUIT_SUITLESS ? WORLD_MAP_OAM_ID_SAMUS_ICON_SUITLESS : WORLD_MAP_OAM_ID_SAMUS_ICON_SUIT;
        pOam->exists = TRUE;

        pOam = &PAUSE_SCREEN_DATA.worldMapOam[1];
        for (i = 0; i < 7; i++, pOam++)
        {
            pOam->xPosition = sWorldMapData[i].xPosition;
            pOam->yPosition = sWorldMapData[i].yPosition;
            pOam->priority = 2;
        }

        pOam = &PAUSE_SCREEN_DATA.worldMapOam[8];
        for (i = 0; i < 16; i++, pOam++)
        {
            pOam->xPosition = sWorldMapTargetPositions[i][0];
            pOam->yPosition = sWorldMapTargetPositions[i][1];
            pOam->priority = 2;
            pOam->exists = FALSE;

            if ((PAUSE_SCREEN_DATA.chozoHintTarget.activatedTargets >> i) & 1 && pOam->xPosition + pOam->yPosition != 0)
                pOam->exists = TRUE;

            pOam->oamID = pOam->exists ? WORLD_MAP_OAM_ID_TARGET : 0;
        }
    }
    else if (onWorldMap == 2)
    {
        pOam = &PAUSE_SCREEN_DATA.worldMapOam[8];
        for (i = 0; i < 16; i++, pOam++)
        {
            if ((PAUSE_SCREEN_DATA.chozoHintTarget.activatedTargets >> i) & 1)
            {
                pOam->oamID = WORLD_MAP_OAM_ID_TARGET;
                pOam->exists = TRUE;
            }
            else
            {
                pOam->oamID = 0;
                pOam->exists = FALSE;
            }
        }
    }

    if (onWorldMap == FALSE)
        status = TRUE;
    else
        status = OAM_ID_CHANGED_FLAG;
 
    pOam = &PAUSE_SCREEN_DATA.worldMapOam[1];
    for (i = 0; i < AREA_NORMAL_COUNT; i++, pOam++)
    {
        if (PAUSE_SCREEN_DATA.currentArea != i)
            pOam->oamID = sWorldMapData[i].nameOamId;
        else
            pOam->oamID = sWorldMapData[i].outlinedOamId;

        pOam->exists = (PAUSE_SCREEN_DATA.areasViewables >> i) & 1 ? status : FALSE;
    }

    pOam = &PAUSE_SCREEN_DATA.worldMapOam[0];
    pOam->xPosition = sWorldMapData[gCurrentArea].xPosition;
    pOam->yPosition = sWorldMapData[gCurrentArea].yPosition - 0x18;
}

/**
 * @brief 6920c | 3b0 | Loads the area name and icons oam
 * 
 */
void PauseScreenLoadAreaNamesAndIcons(void)
{
    s32 i;
    s32 j;
    struct MenuOamData* pOam;
    const u16* ptr;

    pOam = PAUSE_SCREEN_DATA.miscOam;
    for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.miscOam); i++, pOam++)
        *pOam = sMenuOamData_Empty;

    pOam = PAUSE_SCREEN_DATA.overlayOam;
    for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.overlayOam); i++, pOam++)
        *pOam = sMenuOamData_Empty;

    pOam = PAUSE_SCREEN_DATA.borderArrowsOam;
    for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.borderArrowsOam); i++, pOam++)
        *pOam = sMenuOamData_Empty;
    
    pOam = PAUSE_SCREEN_DATA.worldMapOam;
    for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.worldMapOam); i++, pOam++)
        *pOam = sMenuOamData_Empty;

    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_GETTING_NEW_ITEM)
    {
        PauseScreenUpdateStatusScreenOam(0);
        return;
    }
    
    PAUSE_SCREEN_DATA.samusIconOam[0].oamID = gEquipment.suitType != SUIT_SUITLESS ? SAMUS_ICON_OAM_ID_SUIT : SAMUS_ICON_OAM_ID_SUITLESS;
    PAUSE_SCREEN_DATA.samusIconOam[0].exists = TRUE;
    PAUSE_SCREEN_DATA.samusIconOam[0].xPosition = gMinimapX * HALF_BLOCK_SIZE;
    PAUSE_SCREEN_DATA.samusIconOam[0].yPosition = gMinimapY * HALF_BLOCK_SIZE;
    PAUSE_SCREEN_DATA.samusIconOam[0].boundBackground = 3;
    PAUSE_SCREEN_DATA.bossIconOam[0].boundBackground = 3;

    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_ON_MAP_SCREEN)
    {
        PAUSE_SCREEN_DATA.samusIconOam[0].priority = 1;
        PAUSE_SCREEN_DATA.bossIconOam[0].priority = 1;
    }
    else
    {
        PAUSE_SCREEN_DATA.samusIconOam[0].priority = 3;
        PAUSE_SCREEN_DATA.bossIconOam[0].priority = 3;
    }

    #ifdef DEBUG
    if (PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine == PAUSE_SCREEN_SUBROUTINE_STATUS_SCREEN)
    {
        if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_DEBUG)
            PauseDebugInitCursor();
    }
    else
    #else // !DEBUG
    if (PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine != PAUSE_SCREEN_SUBROUTINE_STATUS_SCREEN)
    #endif // DEBUG
    {
        PAUSE_SCREEN_DATA.miscOam[0].oamID = 0;
        PAUSE_SCREEN_DATA.miscOam[0].yPosition = 0;
        PAUSE_SCREEN_DATA.miscOam[0].xPosition = 0;
    }
    
    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_CHOZO_STATUE_HINT)
    {
        PAUSE_SCREEN_DATA.overlayOam[0].oamID = sChozoHintAreaNamesOamIds[PAUSE_SCREEN_DATA.currentArea];
        PAUSE_SCREEN_DATA.overlayOam[0].yPosition = sChozoHintAreaNamesPosition[1];
        PAUSE_SCREEN_DATA.overlayOam[0].xPosition = sChozoHintAreaNamesPosition[0];
        PAUSE_SCREEN_DATA.overlayOam[0].priority = 0;
        PAUSE_SCREEN_DATA.overlayOam[0].boundBackground = 4;
        PAUSE_SCREEN_DATA.overlayOam[0].exists = TRUE;
    }
    else if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_DOWNLOADING_MAP)
    {
        if (gCurrentArea < AREA_DEBUG_1)
            i = gCurrentArea;
        else
            i = AREA_DEBUG_1;

        UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.overlayOam[0], sPauseScreenAreaIconsData[i].nameOamId);
        PAUSE_SCREEN_DATA.overlayOam[0].yPosition = 12;
        PAUSE_SCREEN_DATA.overlayOam[0].xPosition = BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE;
        PAUSE_SCREEN_DATA.overlayOam[0].priority = 0;
    }
    else
    {
        PAUSE_SCREEN_DATA.overlayOam[1].oamID = 0;
        PAUSE_SCREEN_DATA.overlayOam[1].yPosition = QUARTER_BLOCK_SIZE + 8;
        PAUSE_SCREEN_DATA.overlayOam[1].xPosition = BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE;
        PAUSE_SCREEN_DATA.overlayOam[1].priority = 1;
        PauseScreenUpdateWorldMapHighlight(gCurrentArea);

        PAUSE_SCREEN_DATA.overlayOam[0].yPosition = 12;
        PAUSE_SCREEN_DATA.overlayOam[0].xPosition = BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE;
        PAUSE_SCREEN_DATA.overlayOam[0].priority = 1;

        PAUSE_SCREEN_DATA.overlayOam[2].priority = 1;

        PAUSE_SCREEN_DATA.overlayOam[3].oamID = 0;
        PAUSE_SCREEN_DATA.overlayOam[3].yPosition = BLOCK_SIZE * 6 + QUARTER_BLOCK_SIZE + 8;
        PAUSE_SCREEN_DATA.overlayOam[3].xPosition = BLOCK_SIZE * 8 + HALF_BLOCK_SIZE;
        PauseScreenUpdateWorldMap(0);
    }

    PauseScreenDrawCompletionInfo(FALSE);

    for (i = ARRAY_SIZE(sMapScreenArrowsData); i > 0; )
    {
        i--;
        
        if (gPauseScreenFlag == PAUSE_SCREEN_PAUSE_OR_CUTSCENE)
        {
            PAUSE_SCREEN_DATA.borderArrowsOam[sMapScreenArrowsData[i][0]].exists = TRUE;
        }

        PAUSE_SCREEN_DATA.borderArrowsOam[sMapScreenArrowsData[i][0]].oamID = sMapScreenArrowsData[i][1];
        PAUSE_SCREEN_DATA.borderArrowsOam[sMapScreenArrowsData[i][0]].xPosition = sMapScreenArrowsData[i][2];
        PAUSE_SCREEN_DATA.borderArrowsOam[sMapScreenArrowsData[i][0]].yPosition = sMapScreenArrowsData[i][3];
        PAUSE_SCREEN_DATA.borderArrowsOam[sMapScreenArrowsData[i][0]].priority = 3;
    }

    #ifdef DEBUG
    PAUSE_SCREEN_DATA.unk_418[0] = sUnused_40d078;
    #endif
}

/**
 * @brief 695bc | f0 | Processes the pause screen oam
 * 
 */
void PauseScreenProcessOam(void)
{
    gNextOamSlot = 0;

    #ifdef DEBUG
    if (PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine == 0 && PAUSE_SCREEN_DATA.currentArea == gCurrentArea)
        ProcessMenuOam(ARRAY_SIZE(PAUSE_SCREEN_DATA.unk_418), PAUSE_SCREEN_DATA.unk_418, sPauseScreenMiscOam);
    #endif // DEBUG

    // Always process area name oam
    ProcessMenuOam(ARRAY_SIZE(PAUSE_SCREEN_DATA.overlayOam), PAUSE_SCREEN_DATA.overlayOam, sPauseScreenOverlayOam);

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
    s32 currSlot;
    s32 nextSlot;
    s32 i;
    const struct FrameData* pFrame;
    s32 yPosition;
    s32 xPosition;

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
        if (pOam->exists == OAM_ID_CHANGED_FLAG)
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
            xPosition = (s16)gBg0HOFS_NonGameplay;
            yPosition = (s16)gBg0VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 1)
        {
            xPosition = (s16)gBg1HOFS_NonGameplay;
            yPosition = (s16)gBg1VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 2)
        {
            xPosition = (s16)gBg2HOFS_NonGameplay;
            yPosition = (s16)gBg2VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 3)
        {
            xPosition = (s16)gBg3HOFS_NonGameplay;
            yPosition = (s16)gBg3VOFS_NonGameplay;
        }
        else
        {
            // No background, use absolute position
            xPosition = 0;
            yPosition = 0;
        }

        // Offset position by background and global offset
        yPosition = (s16)(SUB_PIXEL_TO_PIXEL_(pOam->yPosition) - SUB_PIXEL_TO_PIXEL_(yPosition) + gOamYOffset_NonGameplay);
        xPosition = (s16)(SUB_PIXEL_TO_PIXEL_(pOam->xPosition) - SUB_PIXEL_TO_PIXEL_(xPosition) + gOamXOffset_NonGameplay);

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
    s32 currSlot;
    s32 nextSlot;
    s32 i;
    const struct FrameData* pFrame;
    s32 yPosition;
    s32 xPosition;

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
        if (pOam->exists == OAM_ID_CHANGED_FLAG)
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
            xPosition = (s16)gBg0HOFS_NonGameplay;
            yPosition = (s16)gBg0VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 1)
        {
            xPosition = (s16)gBg1HOFS_NonGameplay;
            yPosition = (s16)gBg1VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 2)
        {
            xPosition = (s16)gBg2HOFS_NonGameplay;
            yPosition = (s16)gBg2VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 3)
        {
            xPosition = (s16)gBg3HOFS_NonGameplay;
            yPosition = (s16)gBg3VOFS_NonGameplay;
        }
        else
        {
            // No background, use absolute position
            xPosition = 0;
            yPosition = 0;
        }

        // Offset position by background and global offset
        yPosition = (s16)(SUB_PIXEL_TO_PIXEL_(pOam->yPosition) - SUB_PIXEL_TO_PIXEL_(yPosition) + gOamYOffset_NonGameplay);
        xPosition = (s16)(SUB_PIXEL_TO_PIXEL_(pOam->xPosition) - SUB_PIXEL_TO_PIXEL_(xPosition) + gOamXOffset_NonGameplay);

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
    s32 currSlot;
    s32 nextSlot;
    s32 i;
    const struct FrameData* pFrame;
    s32 yPosition;
    s32 xPosition;

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
        if (pOam->exists == OAM_ID_CHANGED_FLAG)
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
            xPosition = (s16)gBg0HOFS_NonGameplay;
            yPosition = (s16)gBg0VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 1)
        {
            xPosition = (s16)gBg1HOFS_NonGameplay;
            yPosition = (s16)gBg1VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 2)
        {
            xPosition = (s16)gBg2HOFS_NonGameplay;
            yPosition = (s16)gBg2VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 3)
        {
            xPosition = (s16)gBg3HOFS_NonGameplay;
            yPosition = (s16)gBg3VOFS_NonGameplay;
        }
        else
        {
            // No background, use absolute position
            xPosition = 0;
            yPosition = 0;
        }

        // Offset position by background and global offset
        yPosition = (s16)(SUB_PIXEL_TO_PIXEL_(pOam->yPosition) - SUB_PIXEL_TO_PIXEL_(yPosition) + gOamYOffset_NonGameplay);
        xPosition = (s16)(SUB_PIXEL_TO_PIXEL_(pOam->xPosition) - SUB_PIXEL_TO_PIXEL_(xPosition) + gOamXOffset_NonGameplay);

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
 * @brief 6a180 | 178 | Main subroutine for the pause screen
 * 
 * @return u32 bool, leaving
 */
u32 PauseScreenSubroutine(void)
{
    u32 leaving;

    leaving = FALSE;

    switch (gSubGameModeStage)
    {
        case 0:
            if (gDemoState)
            {
                gButtonInput = gChangedInput = 0;
                gSubGameModeStage = 5;
            }
            else
            {
                gSubGameModeStage = 1;
            }
            PauseScreenInit();
            break;

        case 2:
            PauseScreenUpdateOrStartFading(0);
            if (PauseScreenCallCurrentSubroutine())
            {
                PauseScreenUpdateOrStartFading(PAUSE_SCREEN_FADING_OUT_INIT);
                gSubGameModeStage++;
            }

            if (PAUSE_SCREEN_DATA.mapScreenFading.stage == 0)
                UpdateMinimapAnimatedPalette();

            PauseScreenUpdateMapArrows();
            PauseScreenProcessOam();
            break;

        case 4:
            gSubGameModeStage = 0;
            gGameModeSub2 = 4;
            #ifdef DEBUG
            if ((gPauseScreenFlag == PAUSE_SCREEN_SUITLESS_ITEMS || gPauseScreenFlag == PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS) && gBootDebugActive)
                gGameModeSub2 = 10;
            #endif // DEBUG
            leaving = TRUE;
            break;

        case 1:
        case 3:
        case 5:
        case 7:
            if (PauseScreenUpdateOrStartFading(0))
                gSubGameModeStage++;
            break;

        case 6:
            PauseScreenUpdateOrStartFading(0);
            if (gButtonInput)
            {
                gCurrentDemo.endedWithInput = TRUE;
                DemoEnd();
                gPauseScreenFlag = PAUSE_SCREEN_UNKNOWN_9;
                leaving = TRUE;
                gSubGameModeStage = 7;
            }
            else
            {
                gButtonInput = gChangedInput = 0;
                if (PauseScreenCallCurrentSubroutine())
                {
                    gGameModeSub2 = 11;
                    leaving = TRUE;
                    gSubGameModeStage = 7;
                }
            }

            if (leaving)
                PauseScreenUpdateOrStartFading(PAUSE_SCREEN_FADING_OUT_INIT);

            if (PAUSE_SCREEN_DATA.mapScreenFading.stage == 0)
                UpdateMinimapAnimatedPalette();

            PauseScreenUpdateMapArrows();
            PauseScreenProcessOam();
            leaving = FALSE;
            break;

        case 8:
            leaving = TRUE;
            gSubGameModeStage = 0;
    }

    return leaving;
}

/**
 * @brief 6a2f8 | 130 | Pause screen V-blank
 * 
 */
void PauseScreenVBlank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16(DMA_ENABLE | DMA_32BIT, OAM_SIZE / sizeof(u32)));

    write16(REG_DISPCNT, PAUSE_SCREEN_DATA.dispcnt);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);
    write16(REG_MOSAIC, gWrittenToMOSAIC_L);

    write16(REG_BG0HOFS, SUB_PIXEL_TO_PIXEL(gBg0HOFS_NonGameplay) & 0x1FF);
    write16(REG_BG0VOFS, SUB_PIXEL_TO_PIXEL(gBg0VOFS_NonGameplay) & 0x1FF);
    write16(REG_BG1HOFS, SUB_PIXEL_TO_PIXEL(gBg1HOFS_NonGameplay) & 0x1FF);
    write16(REG_BG1VOFS, SUB_PIXEL_TO_PIXEL(gBg1VOFS_NonGameplay) & 0x1FF);
    write16(REG_BG2HOFS, SUB_PIXEL_TO_PIXEL(gBg2HOFS_NonGameplay) & 0x1FF);
    write16(REG_BG2VOFS, SUB_PIXEL_TO_PIXEL(gBg2VOFS_NonGameplay) & 0x1FF);
    write16(REG_BG3HOFS, SUB_PIXEL_TO_PIXEL(gBg3HOFS_NonGameplay) & 0x1FF);
    write16(REG_BG3VOFS, SUB_PIXEL_TO_PIXEL(gBg3VOFS_NonGameplay) & 0x1FF);
    
    write16(REG_BG0CNT, PAUSE_SCREEN_DATA.bg0cnt);
    write16(REG_BG1CNT, PAUSE_SCREEN_DATA.bg1cnt);
    write16(REG_BG2CNT, PAUSE_SCREEN_DATA.bg2cnt);
    write16(REG_BG3CNT, PAUSE_SCREEN_DATA.bg3cnt);

    write16(REG_BLDALPHA, C_16_2_8(gWrittenToBLDALPHA_H, gWrittenToBLDALPHA_L));
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

/**
 * @brief 6a434 | aa0 | Initializes the pause screen
 * 
 */
void PauseScreenInit(void)
{
    CallbackSetVBlank(PauseScreenVBlank_Empty);
    
    write16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay = BLDY_MAX_VALUE);
    write16(REG_DISPCNT, 0);

    gNextOamSlot = 0;
    BitFill(3, 0, &gNonGameplayRam, sizeof(union NonGameplayRAM), 32);
    ResetFreeOam();
    
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16(DMA_ENABLE | DMA_32BIT, OAM_SIZE / sizeof(u32)));

    PAUSE_SCREEN_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;
    PAUSE_SCREEN_DATA.dispcnt = 0;

    if (gCurrentCutscene == 0)
    {
        DmaTransfer(3, VRAM_OBJ, EWRAM_BASE + 0x1E000, 0x8000, 16);
    }

    PAUSE_SCREEN_DATA.currentArea = gCurrentArea;
    PAUSE_SCREEN_DATA.mapX = gMinimapX;
    PAUSE_SCREEN_DATA.mapY = gMinimapY;
    PAUSE_SCREEN_DATA.typeFlags = 0;

    #ifdef DEBUG
    if (gDebugMode && gPauseScreenFlag == PAUSE_SCREEN_PAUSE_OR_CUTSCENE)
    {
        if ((gButtonInput & (KEY_L | KEY_SELECT)) == (KEY_L | KEY_SELECT))
            gPauseScreenFlag = PAUSE_SCREEN_MAP_DOWNLOAD;
        else if (!(gButtonInput & KEY_SELECT))
            PAUSE_SCREEN_DATA.typeFlags = PAUSE_SCREEN_TYPE_DEBUG;
    }
    #endif // DEBUG

    switch (gPauseScreenFlag)
    {
        case PAUSE_SCREEN_CHOZO_HINT:
            PAUSE_SCREEN_DATA.typeFlags |= PAUSE_SCREEN_TYPE_ON_MAP_SCREEN | PAUSE_SCREEN_TYPE_CHOZO_STATUE_HINT;
            break;

        case PAUSE_SCREEN_UNKNOWN_3:
            PAUSE_SCREEN_DATA.typeFlags |= PAUSE_SCREEN_TYPE_UNKNOWN_8;
            break;

        case PAUSE_SCREEN_MAP_DOWNLOAD:
            PAUSE_SCREEN_DATA.typeFlags |= PAUSE_SCREEN_TYPE_ON_MAP_SCREEN | PAUSE_SCREEN_TYPE_DOWNLOADING_MAP;
            break;

        case PAUSE_SCREEN_ITEM_ACQUISITION:
            PAUSE_SCREEN_DATA.typeFlags |= PAUSE_SCREEN_TYPE_ON_STATUS_SCREEN | PAUSE_SCREEN_TYPE_GETTING_NEW_ITEM;
            break;

        case PAUSE_SCREEN_SUITLESS_ITEMS:
            UpdateSuitType(SUIT_SUITLESS);
            gSamusData.pose = SPOSE_FACING_THE_FOREGROUND;
            gSamusData.direction = KEY_LEFT;
            gSamusData.currentAnimationFrame = 0;
            gSamusData.lastWallTouchedMidAir = FALSE;

            // TODO pistol
            gCurrentItemBeingAcquired = ITEM_ACQUISITION_LONG_BEAM;
            PAUSE_SCREEN_DATA.typeFlags = PAUSE_SCREEN_TYPE_ON_STATUS_SCREEN | PAUSE_SCREEN_TYPE_GETTING_NEW_ITEM | PAUSE_SCREEN_TYPE_GETTING_SUITLESS;
            break;

        case PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS:
            UpdateSuitType(SUIT_FULLY_POWERED);
            PAUSE_SCREEN_DATA.typeFlags = PAUSE_SCREEN_TYPE_ON_STATUS_SCREEN | PAUSE_SCREEN_TYPE_GETTING_NEW_ITEM | PAUSE_SCREEN_TYPE_GETTING_FULLY_POWERED;
            break;
    }

    DmaTransfer(3, sTankIconsPal, PALRAM_OBJ, sizeof(sTankIconsPal), 16);
    DmaTransfer(3, sMinimapTilesPal, PALRAM_BASE, sizeof(sMinimapTilesPal), 16);
    DmaTransfer(3, sPauseScreen_3fcef0, PALRAM_BASE + 0xA0, sizeof(sPauseScreen_3fcef0), 16);
    sBgPalramPointer[0] = 0;

    DmaTransfer(3, sMinimapTilesGfx, VRAM_BASE + 0x8000, 0x3000, 16);
    DmaTransfer(3, VRAM_BASE + 0xA820, VRAM_BASE + 0xAC20, 0x3E0, 32);

    CallLZ77UncompVram(sTankIconsGfx, VRAM_BASE + 0x13000);
    CallLZ77UncompVram(sMapScreenAreaNamesGfxPointers[gLanguage], VRAM_BASE + 0x10800);
    CallLZ77UncompVram(sMapScreenUnknownItemsNamesGfxPointers[gLanguage], VRAM_BASE + 0x11400);
    CallLZ77UncompVram(sMapScreenChozoStatueAreaNamesGfxPointers[gLanguage], VRAM_BASE + 0x11800);

    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_CHOZO_STATUE_HINT)
    {
        CallLZ77UncompVram(sChozoHintBackgroundGfx, VRAM_BASE);
        CallLZ77UncompVram(sMapScreenAreaNamesGfx, VRAM_BASE + 0xA800);
    }
    else
    {
        CallLZ77UncompVram(sMotifBehindWireframeSamusGfx, VRAM_BASE);
        CallLZ77UncompVram(sPauseScreenHudGfx, VRAM_BASE + 0x1000);
        CallLZ77UncompVram(sMinimapLettersGfx, VRAM_BASE + 0x7400);
        CallLZ77UncompVram(sMapScreenEquipmentNamesGfxPointers[gLanguage], VRAM_BASE + 0x6000);
        CallLZ77UncompVram(sMapScreenMenuNamesGfxPointers[gLanguage], VRAM_BASE + 0xC00);
        DmaTransfer(3, VRAM_BASE + 0x6000, VRAM_OBJ, 0x800, 32);
    }

    BitFill(3, 0x1140, VRAM_BASE + 0xE800, 0x1800, 16);
    // 0x2034000 = gDecompressedMinimapVisitedTiles
    DmaTransfer(3, 0x2034000, VRAM_BASE + 0xE000, sizeof(gDecompressedMinimapVisitedTiles), 16);

    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_CHOZO_STATUE_HINT)
    {
        CallLZ77UncompVram(sChozoHintBackgroundTileTable, VRAM_BASE + 0xB800);
        BitFill(3, 0x115F, VRAM_BASE + 0xC000, 0x800, 16);
    }
    else
    {
        CallLZ77UncompWram(sMapScreenVisorOverlayTilemap, PAUSE_SCREEN_EWRAM.visorOverlayTilemap);
        DmaTransfer(3, PAUSE_SCREEN_EWRAM.visorOverlayTilemap, VRAM_BASE + 0xC800,
            sizeof(PAUSE_SCREEN_EWRAM.visorOverlayTilemap), 16);
        PauseScreenUpdateBottomVisorOverlay(2, 2);

        if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_DOWNLOADING_MAP)
        {
            PauseScreenUpdateTopVisorOverlay(UCHAR_MAX);
        }
        else
        {
            if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_DEBUG)
            {
                CallLZ77UncompVram(sDebugMenuTileParts, VRAM_BASE + 0xB000);
                BitFill(3, 0xF000, PAUSE_SCREEN_EWRAM.unk_d000, sizeof(PAUSE_SCREEN_EWRAM.unk_d000), 16);
            }

            CallLZ77UncompWram(sStatusScreenTilemap, PAUSE_SCREEN_EWRAM.unk_7800);
            CallLZ77UncompWram(sStatusScreenBackgroundTilemap, PAUSE_SCREEN_EWRAM.statusScreenBackgroundTilemap);
            
            if (gEquipment.suitType == SUIT_SUITLESS)
            {
                DmaTransfer(3, PAUSE_SCREEN_EWRAM.statusScreenBackgroundTilemap, VRAM_BASE + 0xC000, 0x500, 16);
            }
            else
            {
                DmaTransfer(3, PAUSE_SCREEN_EWRAM.unk_7800, VRAM_BASE + 0xC000, 0x500, 16);
            }

            CallLZ77UncompWram(sMapScreenOverlayTilemap, PAUSE_SCREEN_EWRAM.mapScreenOverlayTilemap);
            CallLZ77UncompWram(sWorldMapOverlayTilemap, PAUSE_SCREEN_EWRAM.worldMapOverlayTilemap);
            PAUSE_SCREEN_DATA.onWorldMap = FALSE;

            CallLZ77UncompVram(sMapScreenTextBg0TileTable, VRAM_BASE + 0xD800);
            CallLZ77UncompWram(sEasySleepTilemap, PAUSE_SCREEN_EWRAM.easySleepTilemap);
        }
    }

    gBg0HOFS_NonGameplay = gBg0VOFS_NonGameplay = 0;
    gBg1HOFS_NonGameplay = gBg1VOFS_NonGameplay = 0;
    gBg2HOFS_NonGameplay = gBg2VOFS_NonGameplay = 0;
    gBg3HOFS_NonGameplay = gBg3VOFS_NonGameplay = 0;

    PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
    PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
    PAUSE_SCREEN_DATA.subroutineInfo = sMapScreenSubroutineInfo_Empty;

    gBg1VOFS_NonGameplay = BLOCK_SIZE * 16;

    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_CHOZO_STATUE_HINT)
    {
        PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_CHOZO_STATUE_HINT_INIT;
    }
    else if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_DOWNLOADING_MAP)
    {
        gEquipment.downloadedMapStatus |= (1 << gCurrentArea);
        PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_MAP_DOWNLOAD;

        // FIXME use symbol
        PauseScreenGetMinimapData(gCurrentArea, (u16*)0x2034000); // gDecompressedMinimapData
        MinimapSetDownloadedTiles(gCurrentArea, (u16*)0x2034000); // gDecompressedMinimapData
        PauseScreenInitMapDownload();
    }
    else if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_GETTING_FULLY_POWERED)
    {
        PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_FULLY_POWERED_ITEMS_INIT;
    }
    else if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_GETTING_NEW_ITEM)
    {
        PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_SUITLESS_ITEMS_INIT;
        StatusScreenGetSlotForNewItem(1, gCurrentItemBeingAcquired);
    }

    PauseScreenGetAllMinimapData(UCHAR_MAX);
    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_DEBUG)
    {
        #ifdef DEBUG
        PauseDebugDrawEventList();
        #endif // DEBUG
    }
    StatusScreenDraw();
    ChozoStatueHintDeterminePath(FALSE);
    PauseScreenMapSetSpawnPosition(0);
    TextDrawYesNoEasySleep();

    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_ON_MAP_SCREEN)
    {
        PAUSE_SCREEN_DATA.areasWithVisitedTiles = 0;
        PAUSE_SCREEN_DATA.areasWithHints = 0;
        PAUSE_SCREEN_DATA.areasViewables = 0;
        PAUSE_SCREEN_DATA.areasViewablesTotal = 0;
    }
    else
    {
        PauseScreenMapCheckExploredAreas();
        PauseScreenCheckAreasWithTargets();
        PauseScreenDetermineMapsViewable();
        LoadPauseScreenBgPalette();
        DmaTransfer(3, PAUSE_SCREEN_EWRAM.mapScreenOverlayTilemap, VRAM_BASE + 0xD000,
            sizeof(PAUSE_SCREEN_EWRAM.mapScreenOverlayTilemap), 16);
    }

    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_ON_MAP_SCREEN)
    {
        gBg1HOFS_NonGameplay = QUARTER_BLOCK_SIZE;
        gBg1VOFS_NonGameplay = QUARTER_BLOCK_SIZE;
    }

    #ifdef DEBUG
    MinimapDrawRoomInfo();
    #endif // DEBUG

    gWrittenToBLDY_NonGameplay = gWrittenToBLDALPHA_H = 0;
    gWrittenToBLDALPHA_L = 16;

    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_CHOZO_STATUE_HINT)
    {
        PAUSE_SCREEN_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
            BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL |
            BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

        PAUSE_SCREEN_DATA.targetBldAlpha = C_16_2_8(7, 9);
        gWrittenToBLDALPHA_H = 7;
        gWrittenToBLDALPHA_L = 9;
    }
    else if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_GETTING_NEW_ITEM)
    {
        PAUSE_SCREEN_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
            BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL |
            BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

        PAUSE_SCREEN_DATA.targetBldAlpha = C_16_2_8(0, 22);
        gWrittenToBLDALPHA_H = 0;
        gWrittenToBLDALPHA_L = 22;
    }
    else
    {
        PAUSE_SCREEN_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
            BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

        PAUSE_SCREEN_DATA.targetBldAlpha = C_16_2_8(6, 10);
        gWrittenToBLDALPHA_H = 6;
        gWrittenToBLDALPHA_L = 10; 
    }

    write8(REG_WINOUT, WIN0_BG0 | WIN0_BG1 | WIN0_BG2 | WIN0_BG3 | WIN0_OBJ | WIN0_COLOR_EFFECT);
    write8(REG_WINOUT + 1, WIN0_BG3 | WIN0_OBJ);
    gWrittenToMOSAIC_L = 0;

    write16(REG_BG0HOFS, SUB_PIXEL_TO_PIXEL(gBg0HOFS_NonGameplay) & 0x1FF);
    write16(REG_BG0VOFS, SUB_PIXEL_TO_PIXEL(gBg0VOFS_NonGameplay) & 0x1FF);
    write16(REG_BG1HOFS, SUB_PIXEL_TO_PIXEL(gBg1HOFS_NonGameplay) & 0x1FF);
    write16(REG_BG1VOFS, SUB_PIXEL_TO_PIXEL(gBg1VOFS_NonGameplay) & 0x1FF);
    write16(REG_BG2HOFS, SUB_PIXEL_TO_PIXEL(gBg2HOFS_NonGameplay) & 0x1FF);
    write16(REG_BG2VOFS, SUB_PIXEL_TO_PIXEL(gBg2VOFS_NonGameplay) & 0x1FF);
    write16(REG_BG3HOFS, SUB_PIXEL_TO_PIXEL(gBg3HOFS_NonGameplay) & 0x1FF);
    write16(REG_BG3VOFS, SUB_PIXEL_TO_PIXEL(gBg3VOFS_NonGameplay) & 0x1FF);

    write16(REG_MOSAIC, 0);
    write16(REG_BLDCNT, PAUSE_SCREEN_DATA.bldcnt);
    write16(REG_BLDALPHA, C_16_2_8(gWrittenToBLDALPHA_H, gWrittenToBLDALPHA_L));

    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_CHOZO_STATUE_HINT)
    {
        PAUSE_SCREEN_DATA.dispcnt = DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ;
        PAUSE_SCREEN_DATA.unk_6A = 0;
        PAUSE_SCREEN_DATA.unk_70 = 0;
        PAUSE_SCREEN_DATA.unk_72 = 0;
        PAUSE_SCREEN_DATA.unk_74 = 0;
        PAUSE_SCREEN_DATA.unk_76 = 0;
        PAUSE_SCREEN_DATA.unk_78 = 0;
        PAUSE_SCREEN_DATA.unk_7A = 0;
        PAUSE_SCREEN_DATA.unk_6E = 0;
        PAUSE_SCREEN_DATA.unk_6C = CREATE_BGCNT(2, 28, sPauseScreen_BgCntPriority[BGCNT_HIGH_MID_PRIORITY], BGCNT_SIZE_512x512) | (1 << 6);
        PAUSE_SCREEN_DATA.bg3cnt = PAUSE_SCREEN_DATA.unk_6C;
        PAUSE_SCREEN_DATA.bg2cnt = CREATE_BGCNT(0, 23, sPauseScreen_BgCntPriority[BGCNT_LOW_PRIORITY], BGCNT_SIZE_256x256);
        PAUSE_SCREEN_DATA.bg1cnt = CREATE_BGCNT(2, 24, sPauseScreen_BgCntPriority[BGCNT_LOW_MID_PRIORITY], BGCNT_SIZE_256x256);
        PAUSE_SCREEN_DATA.bg0cnt = 0;
    }
    else if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_DOWNLOADING_MAP)
    {
        PAUSE_SCREEN_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ;
        PAUSE_SCREEN_DATA.unk_6A = 0;
        PAUSE_SCREEN_DATA.unk_70 = CREATE_BGCNT(0, 25, sPauseScreen_BgCntPriority[BGCNT_HIGH_PRIORITY], BGCNT_SIZE_256x256);
        PAUSE_SCREEN_DATA.unk_72 = 0;
        PAUSE_SCREEN_DATA.unk_74 = 0;
        PAUSE_SCREEN_DATA.unk_76 = 0;
        PAUSE_SCREEN_DATA.unk_78 = 0;
        PAUSE_SCREEN_DATA.unk_7A = 0;
        PAUSE_SCREEN_DATA.unk_6E = 0;
        PAUSE_SCREEN_DATA.unk_6C = CREATE_BGCNT(2, 28, sPauseScreen_BgCntPriority[BGCNT_HIGH_MID_PRIORITY], BGCNT_SIZE_512x512) | (1 << 6);
        PAUSE_SCREEN_DATA.bg3cnt = PAUSE_SCREEN_DATA.unk_6C;
        PAUSE_SCREEN_DATA.bg2cnt = CREATE_BGCNT(0, 23, sPauseScreen_BgCntPriority[BGCNT_LOW_PRIORITY], BGCNT_SIZE_256x256);
        PAUSE_SCREEN_DATA.bg1cnt = CREATE_BGCNT(2, 24, sPauseScreen_BgCntPriority[BGCNT_LOW_MID_PRIORITY], BGCNT_SIZE_256x256);
        PAUSE_SCREEN_DATA.bg0cnt = PAUSE_SCREEN_DATA.unk_70;
    }
    else
    {
        PAUSE_SCREEN_DATA.dispcnt = DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ;
        PAUSE_SCREEN_DATA.unk_6A = CREATE_BGCNT(1, 27, sPauseScreen_BgCntPriority[BGCNT_HIGH_PRIORITY], BGCNT_SIZE_256x256);
        PAUSE_SCREEN_DATA.unk_6C = CREATE_BGCNT(2, 28, sPauseScreen_BgCntPriority[BGCNT_LOW_PRIORITY], BGCNT_SIZE_512x512);
        PAUSE_SCREEN_DATA.unk_6E = CREATE_BGCNT(2, 31, sPauseScreen_BgCntPriority[BGCNT_LOW_PRIORITY], BGCNT_SIZE_256x256);
        PAUSE_SCREEN_DATA.unk_70 = CREATE_BGCNT(0, 25, sPauseScreen_BgCntPriority[BGCNT_HIGH_MID_PRIORITY], BGCNT_SIZE_256x256);
        PAUSE_SCREEN_DATA.unk_72 = CREATE_BGCNT(0, 26, sPauseScreen_BgCntPriority[BGCNT_LOW_MID_PRIORITY], BGCNT_SIZE_256x256);
        PAUSE_SCREEN_DATA.unk_74 = CREATE_BGCNT(0, 24, sPauseScreen_BgCntPriority[BGCNT_LOW_MID_PRIORITY], BGCNT_SIZE_256x256);
        PAUSE_SCREEN_DATA.unk_76 = PAUSE_SCREEN_DATA.unk_72;

        if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_DEBUG)
        {
            PAUSE_SCREEN_DATA.unk_78 = CREATE_BGCNT(0, 22, sPauseScreen_BgCntPriority[BGCNT_LOW_MID_PRIORITY], BGCNT_SIZE_256x256);
            PAUSE_SCREEN_DATA.unk_7A = CREATE_BGCNT(2, 22, sPauseScreen_BgCntPriority[BGCNT_LOW_MID_PRIORITY], BGCNT_SIZE_256x256);
        }
        else
        {
            PAUSE_SCREEN_DATA.unk_78 = 0;
            PAUSE_SCREEN_DATA.unk_7A = 0;
        }

        PAUSE_SCREEN_DATA.bg3cnt = PAUSE_SCREEN_DATA.unk_6C;
        PAUSE_SCREEN_DATA.bg1cnt = PAUSE_SCREEN_DATA.unk_70;
        PAUSE_SCREEN_DATA.bg0cnt = PAUSE_SCREEN_DATA.unk_6A;

        if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_GETTING_NEW_ITEM)
        {
            PAUSE_SCREEN_DATA.dispcnt = DCNT_BG2 | DCNT_OBJ | DCNT_WINOBJ;
            PAUSE_SCREEN_DATA.bg2cnt = PAUSE_SCREEN_DATA.unk_74;
        }
        else
        {
            PAUSE_SCREEN_DATA.bg2cnt = PAUSE_SCREEN_DATA.unk_72;
        }
    }

    write16(REG_BG0CNT, PAUSE_SCREEN_DATA.bg0cnt);
    write16(REG_BG1CNT, PAUSE_SCREEN_DATA.bg1cnt);
    write16(REG_BG2CNT, PAUSE_SCREEN_DATA.bg2cnt);
    write16(REG_BG3CNT, PAUSE_SCREEN_DATA.bg3cnt);

    PauseScreenLoadAreaNamesAndIcons();

    gOamYOffset_NonGameplay = 4;
    gOamXOffset_NonGameplay = 4;

    PauseScreenUpdateMapArrows();
    PauseScreenUpdateBossIcons();

    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_DOWNLOADING_MAP && PAUSE_SCREEN_DATA.bossIconOam[0].oamID != BOSS_ICON_OAM_ID_CROSSMARK)
    {
        PAUSE_SCREEN_DATA.bossIconOam[0].notDrawn = TRUE;
    }

    PauseScreenProcessOam();
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16(DMA_ENABLE | DMA_32BIT, OAM_SIZE / sizeof(u32)));

    PauseScreenUpdateOrStartFading(PAUSE_SCREEN_FADING_IN_INIT);
    
    CallbackSetVBlank(PauseScreenVBlank);
    write16(REG_DISPCNT, PAUSE_SCREEN_DATA.dispcnt);
}

/**
 * @brief 6aed4 | 138 | Determines which maps are viewables
 * 
 */
void PauseScreenDetermineMapsViewable(void)
{
    s32 i;

    PAUSE_SCREEN_DATA.areasViewables = gEquipment.downloadedMapStatus;
    PAUSE_SCREEN_DATA.areasViewables |= PAUSE_SCREEN_DATA.areasWithVisitedTiles;
    PAUSE_SCREEN_DATA.areasViewables |= PAUSE_SCREEN_DATA.areasWithHints;

    // Seriously?
    PAUSE_SCREEN_DATA.areasViewablesTotal = (PAUSE_SCREEN_DATA.areasViewables >> AREA_BRINSTAR) & 1;
    PAUSE_SCREEN_DATA.areasViewablesTotal += (PAUSE_SCREEN_DATA.areasViewables >> AREA_KRAID) & 1;
    PAUSE_SCREEN_DATA.areasViewablesTotal += (PAUSE_SCREEN_DATA.areasViewables >> AREA_NORFAIR) & 1;
    PAUSE_SCREEN_DATA.areasViewablesTotal += (PAUSE_SCREEN_DATA.areasViewables >> AREA_RIDLEY) & 1;
    PAUSE_SCREEN_DATA.areasViewablesTotal += (PAUSE_SCREEN_DATA.areasViewables >> AREA_TOURIAN) & 1;
    PAUSE_SCREEN_DATA.areasViewablesTotal += (PAUSE_SCREEN_DATA.areasViewables >> AREA_CRATERIA) & 1;
    PAUSE_SCREEN_DATA.areasViewablesTotal += (PAUSE_SCREEN_DATA.areasViewables >> AREA_CHOZODIA) & 1;

    if (PAUSE_SCREEN_DATA.areasViewablesTotal <= 1)
    {
        // Remove "press select" text from the tilemap
        for (i = 0x24C; i < 0x252; i++)
        {
            PAUSE_SCREEN_EWRAM.mapScreenOverlayTilemap[i] = 0;
            PAUSE_SCREEN_EWRAM.mapScreenOverlayTilemap[i + 32] = 0;
            PAUSE_SCREEN_EWRAM.worldMapOverlayTilemap[i] = 9 << 12 | 0xD0;
            PAUSE_SCREEN_EWRAM.worldMapOverlayTilemap[i + 32] = 9 << 12 | 0xD0;
        }
    }

    PauseScreenUpdateBottomVisorOverlay(1, 1);
}

#ifdef NON_MATCHING
void PauseScreenUpdateBottomVisorOverlay(u8 param_1, u8 param_2)
{
    // https://decomp.me/scratch/kHRx8
    
    s32 var_0;
    s16 var_1;
    u16* dst;
    u16* src;
    s32 tmp;

    dst = VRAM_BASE + 0xCC40;
    src = &PAUSE_SCREEN_EWRAM.visorOverlayTilemap[0x380];
    var_1 = -1;
    var_0 = -1;

    if (param_1)
    {
        var_0 = 0;
        if (param_1 == 1 && !PAUSE_SCREEN_DATA.onWorldMap)
            var_0 = 0x16;
    }

    if (param_2)
    {
        var_1 = 0;
        if (param_2 == 1 && PAUSE_SCREEN_DATA.areasViewablesTotal > 1)
            var_1 = 0x2D;
    }

    if (var_0 == 0 && var_1 == 0)
    {
        BitFill(3, 0, dst, 0x80, 32);
        return;
    }

    if (var_0 >= 0)
    {
        dst[0x16] = src[var_0 + 0];
        dst[0x17] = src[var_0 + 1];
        dst[0x16 + 32] = src[var_0 + 0 + 32];
        dst[0x17 + 32] = src[var_0 + 1 + 32];
    }

    if (tmp >= 0)
    {
        dst[0x2D] = src[var_1++];
        dst[0x2E] = src[var_1++];
        dst[0x2F] = src[var_1++];
        dst[0x30] = src[var_1++];
    }
}
#else
NAKED_FUNCTION
void PauseScreenUpdateBottomVisorOverlay(u8 param_1, u8 param_2)
{
    asm(" \n\
    push {r4, r5, lr} \n\
    sub sp, #4 \n\
    lsl r0, r0, #0x18 \n\
    lsr r2, r0, #0x18 \n\
    lsl r1, r1, #0x18 \n\
    lsr r1, r1, #0x18 \n\
    ldr r0, lbl_0806b074 @ =0x0600cc40 \n\
    mov ip, r0 \n\
    ldr r0, lbl_0806b078 @ =sEwramPointer \n\
    ldr r0, [r0] \n\
    movs r3, #0x97 \n\
    lsl r3, r3, #8 \n\
    add r5, r0, r3 \n\
    movs r4, #1 \n\
    neg r4, r4 \n\
    add r3, r4, #0 \n\
    cmp r2, #0 \n\
    beq lbl_0806b042 \n\
    movs r3, #0 \n\
    cmp r2, #1 \n\
    bne lbl_0806b042 \n\
    ldr r0, lbl_0806b07c @ =sNonGameplayRamPointer \n\
    ldr r0, [r0] \n\
    ldrb r0, [r0, #0x11] \n\
    cmp r0, #0 \n\
    bne lbl_0806b042 \n\
    movs r3, #0x16 \n\
lbl_0806b042: \n\
    cmp r1, #0 \n\
    beq lbl_0806b05a \n\
    movs r4, #0 \n\
    cmp r1, #1 \n\
    bne lbl_0806b05a \n\
    ldr r0, lbl_0806b07c @ =sNonGameplayRamPointer \n\
    ldr r0, [r0] \n\
    add r0, #0xbb \n\
    ldrb r0, [r0] \n\
    cmp r0, #1 \n\
    bls lbl_0806b05a \n\
    movs r4, #0x2d \n\
lbl_0806b05a: \n\
    cmp r3, #0 \n\
    bne lbl_0806b080 \n\
    cmp r4, #0 \n\
    bne lbl_0806b080 \n\
    movs r0, #0x20 \n\
    str r0, [sp] \n\
    movs r0, #3 \n\
    movs r1, #0 \n\
    mov r2, ip \n\
    movs r3, #0x80 \n\
    bl BitFill \n\
    b lbl_0806b0ee \n\
    .align 2, 0 \n\
lbl_0806b074: .4byte 0x0600cc40 \n\
lbl_0806b078: .4byte sEwramPointer \n\
lbl_0806b07c: .4byte sNonGameplayRamPointer \n\
lbl_0806b080: \n\
    cmp r3, #0 \n\
    blt lbl_0806b0a6 \n\
    lsl r0, r3, #1 \n\
    add r0, r0, r5 \n\
    ldrh r1, [r0] \n\
    mov r2, ip \n\
    strh r1, [r2, #0x2c] \n\
    ldrh r1, [r0, #2] \n\
    strh r1, [r2, #0x2e] \n\
    add r2, #0x6c \n\
    add r1, r0, #0 \n\
    add r1, #0x40 \n\
    ldrh r1, [r1] \n\
    strh r1, [r2] \n\
    mov r1, ip \n\
    add r1, #0x6e \n\
    add r0, #0x42 \n\
    ldrh r0, [r0] \n\
    strh r0, [r1] \n\
lbl_0806b0a6: \n\
    cmp r4, #0 \n\
    blt lbl_0806b0ee \n\
    mov r3, ip \n\
    add r3, #0x5a \n\
    add r1, r4, #0 \n\
    add r0, r1, #1 \n\
    lsl r0, r0, #0x10 \n\
    asr r4, r0, #0x10 \n\
    add r2, r4, #0 \n\
    lsl r1, r1, #1 \n\
    add r1, r1, r5 \n\
    ldrh r0, [r1] \n\
    strh r0, [r3] \n\
    add r3, #2 \n\
    add r0, r2, #1 \n\
    lsl r0, r0, #0x10 \n\
    asr r4, r0, #0x10 \n\
    add r1, r4, #0 \n\
    lsl r2, r2, #1 \n\
    add r2, r2, r5 \n\
    ldrh r0, [r2] \n\
    strh r0, [r3] \n\
    mov r2, ip \n\
    add r2, #0x5e \n\
    add r0, r1, #1 \n\
    lsl r0, r0, #0x10 \n\
    lsl r1, r1, #1 \n\
    add r1, r1, r5 \n\
    ldrh r1, [r1] \n\
    strh r1, [r2] \n\
    mov r1, ip \n\
    add r1, #0x60 \n\
    asr r0, r0, #0xf \n\
    add r0, r0, r5 \n\
    ldrh r0, [r0] \n\
    strh r0, [r1] \n\
lbl_0806b0ee: \n\
    add sp, #4 \n\
    pop {r4, r5} \n\
    pop {r0} \n\
    bx r0 \n\
    ");
}
#endif

/**
 * @brief 6b0f8 | 148 | Gets the minimap for the provided area
 * 
 * @param area Area
 * @param dst Destination pointer
 */
void PauseScreenGetMinimapData(u8 area, u16* dst)
{
    u32 position;
    s32 i;

    // Decompress base minimap
    CallLZ77UncompWram(sMinimapDataPointers[area], dst);

    // Add obtained items
    MinimapSetTilesWithObtainedItems(area, dst);

    // Check update boss icons
    position = sBossIcons[area][0]; // Event
    if (position && EventFunction(EVENT_ACTION_CHECKING, position))
    {
        position = sBossIcons[area][2] + sBossIcons[area][3] * MINIMAP_SIZE;

        if (area == AREA_CRATERIA)
        {
            // Ship, 3x1 tiles
            if ((dst[position] & 0x3FF) == sMapChunksToUpdate[2])
            {
                for (i = 0; i < 3; i++)
                    dst[position + i]++;
            }
        }
        else if (area == AREA_KRAID)
        {
            // Kraid icon, 2x2 tiles
            if ((dst[position] & 0x3FF) == sMapChunksToUpdate[0])
            {
                for (i = 0; i < 2; i++)
                    dst[position + i] += MINIMAP_SIZE;
                    
                for (i = MINIMAP_SIZE; i < MINIMAP_SIZE + 2; i++)
                    dst[position + i] += MINIMAP_SIZE;
            }
        }
        else if (area == AREA_RIDLEY)
        {
            // Ridley icon, 2x2 tiles
            if ((dst[position] & 0x3FF) == sMapChunksToUpdate[1])
            {
                for (i = 0; i < 2; i++)
                    dst[position + i] += MINIMAP_SIZE;
                    
                for (i = MINIMAP_SIZE; i < MINIMAP_SIZE + 2; i++)
                    dst[position + i] += MINIMAP_SIZE;
            }
        }
    }

    // Check update the varia statue tile if varia suit was skipped
    if (area == AREA_BRINSTAR && EventFunction(EVENT_ACTION_CHECKING, EVENT_SKIPPED_VARIA_SUIT))
        dst[MINIMAP_SIZE * 2 + 14]++;
}

/**
 * @brief 6b240 | 2c4 | Calls the current pause screen subroutine
 * 
 * @return u32 bool, ended
 */
u32 PauseScreenCallCurrentSubroutine(void)
{
    u32 leaving;

    leaving = FALSE;
    CheckForMaintainedInput();

    APPLY_DELTA_TIME_INC(PAUSE_SCREEN_DATA.subroutineInfo.timer);

    switch (PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine)
    {
        case PAUSE_SCREEN_SUBROUTINE_MAP_SCREEN:
            if (!(gChangedInput & (gButtonAssignments.pause | KEY_B)))
            {
                MapScreenSubroutine();
                break;
            }
            
            if (PAUSE_SCREEN_DATA.onWorldMap)
            {
                MapScreenSubroutine();
                break;
            }

            leaving = TRUE;
            break;

        case PAUSE_SCREEN_SUBROUTINE_STATUS_SCREEN:
            if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_DEBUG)
            {
                if (!PAUSE_SCREEN_DATA.debugOnEventList)
                    PauseScreenMoveDebugCursor(TRUE);

                #ifdef DEBUG
                leaving = PauseDebugSubroutine();
                #else // !DEBUG
                leaving = FALSE;
                #endif
            }
            else
            {
                StatusScreenSubroutine();
            }
            break;

        case 2:
            FadeMusic(CONVERT_SECONDS(2.f) + TWO_THIRD_SECOND);
            leaving = TRUE;
            break;

        case 3:
            if (gChangedInput & (gButtonAssignments.pause | (KEY_A | KEY_B)) && !PAUSE_SCREEN_DATA.onWorldMap)
            {
                leaving = TRUE;
                break;
            }
            
            break;

        case PAUSE_SCREEN_SUBROUTINE_SUITLESS_ITEMS:
            if (StatusScreenSuitlessItems())
            {
                PauseScreenUpdateStatusScreenOam(4);
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = 0x5;
            }
            break;

        case PAUSE_SCREEN_SUBROUTINE_FULLY_POWERED_ITEMS:
            if (StatusScreenFullyPoweredItems())
            {
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = 0x7;
            }
            break;

        case 5:
        case 7:
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer > CONVERT_SECONDS(.2f))
                leaving = TRUE;
            break;

        case PAUSE_SCREEN_SUBROUTINE_CHOZO_STATUE_HINT:
            if (ChozoStatueHintSubroutine())
            {
                PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = 14;
            }
            break;

        case PAUSE_SCREEN_SUBROUTINE_MAP_DOWNLOAD:
            if (PauseScreenMapDownloadSubroutine())
            {
                PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = 18;
            }
            break;

        case PAUSE_SCREEN_SUBROUTINE_EASY_SLEEP:
            if (PauseScreenEasySleepSubroutine())
            {
                PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_EASY_SLEEP_LEAVING;
            }
            break;

        case PAUSE_SCREEN_SUBROUTINE_STATUS_SCREEN_INIT:
            if (PAUSE_SCREEN_DATA.isFading)
            {
                PauseScreenApplyFading();
            }
            else
            {
                if (PauseScreenStatusScreenInit())
                {
                    PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_STATUS_SCREEN;
                    PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
                    PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                    PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                }
            }
            break;

        case PAUSE_SCREEN_SUBROUTINE_STATUS_SCREEN_LEAVING:
            if (PAUSE_SCREEN_DATA.isFading)
            {
                PauseScreenApplyFading();
            }
            else
            {
                if (PauseScreenQuitStatusScreen())
                {
                    PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_MAP_SCREEN;
                    PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
                    PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                    PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                }
            }
            break;

        case 13:
        case PAUSE_SCREEN_SUBROUTINE_CHOZO_STATUE_HINT_INIT:
            PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_CHOZO_STATUE_HINT;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
            PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case 18:
            PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = 3;
            PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case 14:
            if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_ON_MAP_SCREEN)
                PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = 2;
            else
                PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_MAP_SCREEN;
            break;

        case PAUSE_SCREEN_SUBROUTINE_EASY_SLEEP_INIT:
            if (PAUSE_SCREEN_DATA.isFading)
            {
                PauseScreenApplyFading();
            }
            else
            {
                if (PauseScreenEasySleepInit())
                {
                    PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_EASY_SLEEP;
                    PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
                    PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                    #ifdef DEBUG
                    PAUSE_SCREEN_DATA.unk_418[0].notDrawn ^= TRUE;
                    #endif // DEBUG
                }
            }
            break;

        case PAUSE_SCREEN_SUBROUTINE_EASY_SLEEP_LEAVING:
            if (PAUSE_SCREEN_DATA.isFading)
            {
                PauseScreenApplyFading();
            }
            else
            {
                if (PauseScreenQuitEasySleep())
                {
                    PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_MAP_SCREEN;
                    PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
                    PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                }
            }
            break;

        case PAUSE_SCREEN_SUBROUTINE_SUITLESS_ITEMS_INIT:
            if (PauseScreenSuitChangingStart())
            {
                PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_SUITLESS_ITEMS;
                PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            break;

        case PAUSE_SCREEN_SUBROUTINE_FULLY_POWERED_ITEMS_INIT:
            if (PauseScreenSuitChangingStart())
            {
                PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_FULLY_POWERED_ITEMS;
                PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            break;
    }

    return leaving;
}

/**
 * @brief 6b504 | 168 | Movement hanhdler for the debug cursor
 * 
 * @param allowOverflow Allow screen overflow
 */
void PauseScreenMoveDebugCursor(u8 allowOverflow)
{
    // Stick to block position
    PAUSE_SCREEN_DATA.miscOam[0].yPosition &= HALF_BLOCK_POSITION_FLAG;
    PAUSE_SCREEN_DATA.miscOam[0].xPosition &= HALF_BLOCK_POSITION_FLAG;
    
    if (gButtonInput & KEY_A)
        return;

    if (PAUSE_SCREEN_DATA.subroutineInfo.stage != 0)
        return;

    if (allowOverflow == FALSE)
    {
        // Move cursor horizontally
        if (gChangedInput & KEY_RIGHT)
        {
            if (PAUSE_SCREEN_DATA.miscOam[0].xPosition < HALF_BLOCK_SIZE * 29)
                PAUSE_SCREEN_DATA.miscOam[0].xPosition += HALF_BLOCK_SIZE;
        }
        else if (gChangedInput & KEY_LEFT)
        {
            if (PAUSE_SCREEN_DATA.miscOam[0].xPosition != 0)
                PAUSE_SCREEN_DATA.miscOam[0].xPosition -= HALF_BLOCK_SIZE;
        }

        // Move cursor vertically
        if (gChangedInput & KEY_UP)
        {
            if (PAUSE_SCREEN_DATA.miscOam[0].yPosition != 0)
                PAUSE_SCREEN_DATA.miscOam[0].yPosition -= HALF_BLOCK_SIZE;
        }
        else if (gChangedInput & KEY_DOWN)
        {
            if (PAUSE_SCREEN_DATA.miscOam[0].yPosition < HALF_BLOCK_SIZE * 19)
                PAUSE_SCREEN_DATA.miscOam[0].yPosition += HALF_BLOCK_SIZE;
        }
    }
    else
    {
        // Move cursor horizontally
        if (gChangedInput & KEY_RIGHT)
        {
            if (PAUSE_SCREEN_DATA.miscOam[0].xPosition < HALF_BLOCK_SIZE * 29)
                PAUSE_SCREEN_DATA.miscOam[0].xPosition += HALF_BLOCK_SIZE;
            else
                PAUSE_SCREEN_DATA.miscOam[0].xPosition = 0;
        }
        else if (gChangedInput & KEY_LEFT)
        {
            if (PAUSE_SCREEN_DATA.miscOam[0].xPosition != 0)
                PAUSE_SCREEN_DATA.miscOam[0].xPosition -= HALF_BLOCK_SIZE;
            else
                PAUSE_SCREEN_DATA.miscOam[0].xPosition = HALF_BLOCK_SIZE * 29;
        }

        // Move cursor vertically
        if (gChangedInput & KEY_UP)
        {
            if (PAUSE_SCREEN_DATA.miscOam[0].yPosition != 0)
                PAUSE_SCREEN_DATA.miscOam[0].yPosition -= HALF_BLOCK_SIZE;
            else
                PAUSE_SCREEN_DATA.miscOam[0].yPosition = HALF_BLOCK_SIZE * 19;
        }
        else if (gChangedInput & KEY_DOWN)
        {
            if (PAUSE_SCREEN_DATA.miscOam[0].yPosition < HALF_BLOCK_SIZE * 19)
                PAUSE_SCREEN_DATA.miscOam[0].yPosition += HALF_BLOCK_SIZE;
            else
                PAUSE_SCREEN_DATA.miscOam[0].yPosition = 0;
        }
    }
}

/**
 * @brief 6b66c | 58 | [Unused] To document
 * 
 * @param param_1 To document
 * @param param_2 To document
 * @return u32 To document
 */
u32 unk_6b66c_Unused(u16* param_1, u16 param_2)
{
    u32 result;
    s32 var_0;
    s32 var_1;

    result = FALSE;

    if (*param_1 > param_2)
        var_0 = -1;
    else
        var_0 = 1;

    if (PAUSE_SCREEN_DATA.subroutineInfo.timer + 4 < 32)
        *param_1 += var_0 * (PAUSE_SCREEN_DATA.subroutineInfo.timer + 4);
    else
        *param_1 += var_0 * 32;

    if (var_0 > 0)
    {
        if (*param_1 >= param_2)
        {
            *param_1 = param_2;
            result = TRUE;
        }
    }
    else
    {
        var_1 = (s16)*param_1;
        if (var_1 <= param_2)
        {
            *param_1 += (param_2 - var_1);
            result = TRUE;
        }
    }

    return result;
}

/**
 * @brief 6b6c4 | 54 | [Unused] To document
 * 
 * @param param_1 To document
 * @param param_2 To document
 * @return u32 To document
 */
u32 unk_6b6c4_Unused(u16* param_1, u16 param_2)
{
    u32 result;
    s32 var_0;
    s32 var_1;

    result = FALSE;

    if (*param_1 > param_2)
        var_0 = -1;
    else
        var_0 = 1;

    if (PAUSE_SCREEN_DATA.subroutineInfo.timer + 4 < 32)
        *param_1 += var_0 * (PAUSE_SCREEN_DATA.subroutineInfo.timer + 4);
    else
        *param_1 += var_0 * 32;

    if (var_0 > 0)
    {
        if (*param_1 >= param_2)
        {
            result = TRUE;
        }
    }
    else
    {
        var_1 = (s16)*param_1;
        if (var_1 <= param_2)
        {
            result = TRUE;
        }
    }

    if (result)
        *param_1 = param_2;

    return result;
}

/**
 * @brief 6b718 | 60 | Updates the top visor overlay
 * 
 * @param oamId Oam id
 */
void PauseScreenUpdateTopVisorOverlay(u8 oamId)
{
    s32 offset;

    if (oamId != UCHAR_MAX)
    {
        UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.overlayOam[1], oamId);
    }

    if (oamId == OVERLAY_OAM_ID_R_PROMPT_PRESSED)
        offset = 1;
    else if (oamId == OVERLAY_OAM_ID_L_PROMPT_PRESSED)
        offset = 2;
    else if (oamId == 0)
        offset = 0;
    else
        offset = 3;

    DmaTransfer(3, &PAUSE_SCREEN_EWRAM.visorOverlayTilemap[0x280 + offset * 0x40], VRAM_BASE + 0xC800, 0x80, 16);
}

/**
 * @brief 6b778 | c0 | Initializes the status screen for a suit change (suitless or fully powered)
 * 
 * @return s32 bool, ended (-1 and 0)
 */
s32 PauseScreenSuitChangingStart(void)
{
    s32 stage;

    stage = 0;

    switch (PAUSE_SCREEN_DATA.subroutineInfo.stage)
    {
        case 0:
            // Nothing to do, next stage
            stage = UCHAR_MAX + 1;
            break;

        case 1:
            // Update upgrade headers
            PauseScreenUpdateStatusScreenOam(3);
            // Next stage
            stage = UCHAR_MAX + 1;
            break;

        case 2:
            // Draw status screen
            if (StatusScreenDrawItems(PAUSE_SCREEN_DATA.subroutineInfo.timer - 1))
                stage = UCHAR_MAX + 1;
            break;

        case 3:
            // Setup cursor for the new item
            PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = StatusScreenGetSlotForNewItem(2, gCurrentItemBeingAcquired);
            StatusScreenInitCursorAndItems();
            
            // Display text background
            PAUSE_SCREEN_DATA.dispcnt |= DCNT_BG0;

            // Clear text buffer graphics
            BitFill(3, 0, VRAM_BASE + 0x7800, 0x800, 16);

            // Mark as ended
            stage = -1;
    }

    // Check should update stage
    if (stage > 0)
    {
        // Set direct value or increment
        if (stage > UCHAR_MAX)
            PAUSE_SCREEN_DATA.subroutineInfo.stage++;
        else
            PAUSE_SCREEN_DATA.subroutineInfo.stage = stage;

        PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
        stage = FALSE;
    }

    return stage;
}

/**
 * @brief 6b838 | 1fc | Initializes the status screen
 * 
 * @return s32 bool, ended (-1 and 0)
 */
s32 PauseScreenStatusScreenInit(void)
{
    s32 stage;
    
    stage = 0;
    switch (PAUSE_SCREEN_DATA.subroutineInfo.stage)
    {
        case 0:
            // Background tilemap?
            if (gEquipment.suitType == SUIT_SUITLESS)
            {
                DmaTransfer(3, PAUSE_SCREEN_EWRAM.statusScreenBackgroundTilemap, VRAM_BASE + 0xC000, 0x500, 32);
            }
            else
            {
                DmaTransfer(3, PAUSE_SCREEN_EWRAM.unk_7800, VRAM_BASE + 0xC000, 0x500, 32);
            }
            
            // Set stage 1
            stage = 1;
            break;

        case 1:
            // Update top overlay
            PauseScreenUpdateTopVisorOverlay(OVERLAY_OAM_ID_R_PROMPT_PRESSED);
            #ifdef DEBUG
            if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_DEBUG)
            {
                if (gButtonInput & KEY_SELECT)
                {
                    PAUSE_SCREEN_DATA.typeFlags |= PAUSE_SCREEN_TYPE_UNKNOWN_40;
                    PAUSE_SCREEN_DATA.typeFlags ^= PAUSE_SCREEN_TYPE_DEBUG;
                }

                if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_DEBUG)
                {
                    PAUSE_SCREEN_DATA.overlayOam[1].exists = FALSE;
                    PauseDebugDrawAllGroups();
                    stage = 9;
                }
                else
                {
                    StatusScreenDraw();
                    stage = UCHAR_MAX + 1;
                }
            }
            else
            #endif // DEBUG
            {
                stage = UCHAR_MAX + 1;
            }
            if (stage & (UCHAR_MAX + 1))
                SoundPlay(SOUND_OPENING_STATUS_SCREEN);
            break;

        case 2:
            if (PauseScreenInitFading(C_16_2_8(16, 0), 2, 0))
            {
                // Update bottom overlay
                PauseScreenUpdateBottomVisorOverlay(2, 2);
                stage = UCHAR_MAX + 1;
            }
            break;

        case 3:
            // Flag as status screen
            PAUSE_SCREEN_DATA.typeFlags |= PAUSE_SCREEN_TYPE_ON_STATUS_SCREEN;
            PAUSE_SCREEN_DATA.bg2cnt = PAUSE_SCREEN_DATA.unk_74;
            
            PAUSE_SCREEN_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL |
                BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            PauseScreenUpdateStatusScreenOam(1);
            stage = UCHAR_MAX + 1;
            break;

        case 4:
            if (PauseScreenUpdateStatusScreenOam(2))
                stage = UCHAR_MAX + 1;
            break;

        case 5:
            if (PauseScreenInitFading(C_16_2_8(0, 16), 2, 0))
                stage = UCHAR_MAX + 1;
            break;

        case 6:
            // Update upgrade headers
            PauseScreenUpdateStatusScreenOam(3);
            stage = UCHAR_MAX + 1;
            break;

        case 7:
            // Draw status screen
            if (StatusScreenDrawItems(PAUSE_SCREEN_DATA.subroutineInfo.timer - 1))
                stage = UCHAR_MAX + 1;
            break;

        case 8:
            // Setup cursor
            StatusScreenInitCursorAndItems();
            
            // Display text background
            PAUSE_SCREEN_DATA.dispcnt |= DCNT_BG0;

            // Clear text buffer graphics
            BitFill(3, 0, VRAM_BASE + 0x7800, 0x800, 16);
            stage = -1;
            break;

        case 9:
            PAUSE_SCREEN_DATA.bg2cnt = PAUSE_SCREEN_DATA.unk_78;
            PAUSE_SCREEN_DATA.dispcnt &= ~DCNT_BG1;
            PAUSE_SCREEN_DATA.overlayOam[0].exists = FALSE;
            #ifdef DEBUG
            PauseDebugInitCursor();
            #endif // DEBUG
            stage = -1;
    }

    // Check should update stage
    if (stage > 0)
    {
        // Set direct value or increment
        if (stage > UCHAR_MAX)
            PAUSE_SCREEN_DATA.subroutineInfo.stage++;
        else
            PAUSE_SCREEN_DATA.subroutineInfo.stage = stage;

        PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
        stage = FALSE;
    }
    else if (stage < 0)
    {
        gWrittenToBLDALPHA_H = 0;
        gWrittenToBLDALPHA_L = 16;
    }

    return stage;
}

/**
 * @brief 6ba34 | 200 | Un-initializes the status screen
 * 
 * @return s32 bool, ended (-1 and 0)
 */
s32 PauseScreenQuitStatusScreen(void)
{
    s32 stage;
    
    stage = 0;
    switch (PAUSE_SCREEN_DATA.subroutineInfo.stage)
    {
        case 0:
            SoundPlay(SOUND_LEAVING_STATUS_SCREEN);
            PAUSE_SCREEN_DATA.miscOam[0].oamID = 0;
            PauseScreenUpdateTopVisorOverlay(0);
            #ifdef DEBUG
            if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_DEBUG)
            {
                stage = 5;
            }
            else
            {
                stage = UCHAR_MAX + 1;
                if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_UNKNOWN_40)
                {
                    PAUSE_SCREEN_DATA.typeFlags |= PAUSE_SCREEN_TYPE_DEBUG;
                    PAUSE_SCREEN_DATA.typeFlags ^= PAUSE_SCREEN_TYPE_UNKNOWN_40;
                }
            }
            #else // !DEBUG
            stage = UCHAR_MAX + 1;
            #endif // DEBUG
            break;

        case 1:
            PauseScreenUpdateStatusScreenOam(4);
            PAUSE_SCREEN_DATA.miscOam[1].exists = FALSE;
            stage = UCHAR_MAX + 1;
            break;

        case 2:
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer > CONVERT_SECONDS(.2f))
                stage = UCHAR_MAX + 1;
            break;

        case 3:
            if (PauseScreenInitFading(C_16_2_8(16, 0), 2, 0))
            {
                PAUSE_SCREEN_DATA.dispcnt &= ~DCNT_BG0;
                PAUSE_SCREEN_DATA.overlayOam[3].exists = FALSE;
                stage = UCHAR_MAX + 1;
            }
            break;

        case 4:
            PAUSE_SCREEN_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            PauseScreenUpdateStatusScreenOam(5);
            PAUSE_SCREEN_DATA.currentStatusSlot = 0;
            stage = UCHAR_MAX + 1;
            break;

        case 5:
            gWrittenToBLDALPHA_H = 16;
            gWrittenToBLDALPHA_L = 0;
            PAUSE_SCREEN_DATA.dispcnt |= DCNT_BG1;
            PAUSE_SCREEN_DATA.overlayOam[0].exists = TRUE;
            PAUSE_SCREEN_DATA.subroutineInfo.stage++;

        case 6:
            PAUSE_SCREEN_DATA.bg2cnt = PAUSE_SCREEN_DATA.unk_72;
            stage = UCHAR_MAX + 1;
            break;

        case 7:
            if (PauseScreenInitFading(PAUSE_SCREEN_DATA.targetBldAlpha, 2, 0))
            {
                PAUSE_SCREEN_DATA.typeFlags &= ~PAUSE_SCREEN_TYPE_ON_STATUS_SCREEN;
                stage = UCHAR_MAX + 1;
            }
            break;

        case 8:
            PauseScreenUpdateBottomVisorOverlay(1, 1);
            stage = -1;
    }

    // Check should update stage
    if (stage > 0)
    {
        // Set direct value or increment
        if (stage > UCHAR_MAX)
            PAUSE_SCREEN_DATA.subroutineInfo.stage++;
        else
            PAUSE_SCREEN_DATA.subroutineInfo.stage = stage;

        PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
        stage = FALSE;
    }
    else if (stage < 0)
    {
        gWrittenToBLDALPHA_H = HIGH_BYTE(PAUSE_SCREEN_DATA.targetBldAlpha);
        gWrittenToBLDALPHA_L = LOW_BYTE(PAUSE_SCREEN_DATA.targetBldAlpha);
    }

    return stage;
}

/**
 * @brief 6bc34 | 2d4 | Initializes the easy sleep screen
 * 
 * @return s32 bool, ended
 */
s32 PauseScreenEasySleepInit(void)
{
    // Update text processing
    if (PAUSE_SCREEN_DATA.easySleepTextState >= 0)
        TextDrawEasySleep();

    switch (PAUSE_SCREEN_DATA.subroutineInfo.stage)
    {
        case 0:
            if (!PauseScreenInitFading(C_16_2_8(16, 0), 4, 0))
                PAUSE_SCREEN_DATA.subroutineInfo.stage--;
            break;

        case 1: 
            PauseScreenUpdateBottomVisorOverlay(2, 2);
            PauseScreenUpdateTopVisorOverlay(OVERLAY_OAM_ID_L_PROMPT_PRESSED);
            PAUSE_SCREEN_DATA.dispcnt &= ~DCNT_BG2;
            break;

        case 2:
            // Transfer tilemap
            DmaTransfer(3, PAUSE_SCREEN_EWRAM.easySleepTilemap, VRAM_BASE + 0xD000, sizeof(PAUSE_SCREEN_EWRAM.easySleepTilemap), 16);
            break;

        case 3:
            // Make a backup of some Gfx
            DmaTransfer(3, VRAM_BASE + 0x6000, PAUSE_SCREEN_EWRAM.equipmentNamesGfxBackup,
                sizeof(PAUSE_SCREEN_EWRAM.equipmentNamesGfxBackup), 16);
            DmaTransfer(3, VRAM_BASE + 0x6800, PAUSE_SCREEN_EWRAM.unk_b000,
                sizeof(PAUSE_SCREEN_EWRAM.unk_b000), 16);
            break;

        case 4:
            // More backups
            DmaTransfer(3, VRAM_BASE + 0x7000, PAUSE_SCREEN_EWRAM.unk_b800,
                sizeof(PAUSE_SCREEN_EWRAM.unk_b800), 16);
            DmaTransfer(3, VRAM_BASE + 0x7800, PAUSE_SCREEN_EWRAM.unk_c000,
                sizeof(PAUSE_SCREEN_EWRAM.unk_c000), 16);
            break;

        case 6:
            // Format easy sleep tilemap
            DMA_SET(3, &PAUSE_SCREEN_EWRAM.unk_6000[0], &PAUSE_SCREEN_EWRAM.easySleepTextFormatted_1[0x1C0], C_32_2_16(DMA_ENABLE, 0x40));
            DMA_SET(3, &PAUSE_SCREEN_EWRAM.unk_6000[0x200], &PAUSE_SCREEN_EWRAM.easySleepTextFormatted_1[0x3C0], C_32_2_16(DMA_ENABLE, 0x40));
            DMA_SET(3, &PAUSE_SCREEN_EWRAM.unk_6000[0xE0], &PAUSE_SCREEN_EWRAM.easySleepTextFormatted_2[0x1C0],  C_32_2_16(DMA_ENABLE, 0x40));
            DMA_SET(3, &PAUSE_SCREEN_EWRAM.unk_6000[0x2E0], &PAUSE_SCREEN_EWRAM.easySleepTextFormatted_2[0x3C0], C_32_2_16(DMA_ENABLE, 0x40));
            break;

        case 7:
            // Transfer message text
            if ((u8)PAUSE_SCREEN_DATA.easySleepTextState > 1)
            {
                DmaTransfer(3, PAUSE_SCREEN_EWRAM.easySleepTextFormatted_1, VRAM_BASE + 0x6000,
                    sizeof(PAUSE_SCREEN_EWRAM.easySleepTextFormatted_1), 16);

                DmaTransfer(3, PAUSE_SCREEN_EWRAM.easySleepTextFormatted_2, VRAM_BASE + 0x6800,
                    sizeof(PAUSE_SCREEN_EWRAM.easySleepTextFormatted_2), 16);
            }
            else
            {
                PAUSE_SCREEN_DATA.subroutineInfo.stage--;
            }
            break;

        case 8:
            // Transfer prompt text
            if (PAUSE_SCREEN_DATA.easySleepTextState < 0)
            {
                DmaTransfer(3, PAUSE_SCREEN_EWRAM.unk_5000, VRAM_BASE + 0x7000,
                    sizeof(PAUSE_SCREEN_EWRAM.unk_5000), 16);

                DmaTransfer(3, PAUSE_SCREEN_EWRAM.unk_5800, VRAM_BASE + 0x7800,
                    sizeof(PAUSE_SCREEN_EWRAM.unk_5800), 16);
            }
            else
            {
                PAUSE_SCREEN_DATA.subroutineInfo.stage--;
            }
            break;

        case 9:
            PAUSE_SCREEN_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL |
                BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            PAUSE_SCREEN_DATA.dispcnt |= DCNT_BG2;
            PAUSE_SCREEN_DATA.subroutineInfo.stage++;

        case 10:
            if (!PauseScreenInitFading(C_16_2_8(0, 16), 4, 0))
                PAUSE_SCREEN_DATA.subroutineInfo.stage--;
            break;

        case 11:
            // Setup cursor
            UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[1], MISC_OAM_ID_RIGHT_CURSOR);
            PAUSE_SCREEN_DATA.miscOam[1].xPosition = BLOCK_SIZE * 8 + QUARTER_BLOCK_SIZE;
            PAUSE_SCREEN_DATA.miscOam[1].yPosition = BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE;
            PAUSE_SCREEN_DATA.miscOam[1].objMode = 1;

            gDisableSoftreset = TRUE;

            PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            return TRUE;
    }

    PAUSE_SCREEN_DATA.subroutineInfo.stage++;
    return FALSE;
}

/**
 * @brief 6bf08 | 1d8 | Un-initializes the status screen
 * 
 * @return s32 bool, ended
 */
s32 PauseScreenQuitEasySleep(void)
{
    switch (PAUSE_SCREEN_DATA.subroutineInfo.stage)
    {
        case 0:
            gDisableSoftreset = FALSE;
            PauseScreenUpdateTopVisorOverlay(0);
            PAUSE_SCREEN_DATA.subroutineInfo.stage++;

        case 1:
            if (!PauseScreenInitFading(C_16_2_8(16, 0), 4, 0))
                PAUSE_SCREEN_DATA.subroutineInfo.stage--;
            break;

        case 2:
            PAUSE_SCREEN_DATA.dispcnt &= ~DCNT_BG2;
            UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[1], 0);
            PAUSE_SCREEN_DATA.miscOam[1].objMode = 0;
            break;

        case 3:
            DMA_SET(3, PAUSE_SCREEN_EWRAM.mapScreenOverlayTilemap, VRAM_BASE + 0xD000,
                C_32_2_16(DMA_ENABLE, ARRAY_SIZE(PAUSE_SCREEN_EWRAM.mapScreenOverlayTilemap)));
            break;

        case 4:
            DmaTransfer(3, PAUSE_SCREEN_EWRAM.equipmentNamesGfxBackup, VRAM_BASE + 0x6000,
                sizeof(PAUSE_SCREEN_EWRAM.equipmentNamesGfxBackup), 16);
            DmaTransfer(3, PAUSE_SCREEN_EWRAM.unk_b000, VRAM_BASE + 0x6800,
                sizeof(PAUSE_SCREEN_EWRAM.unk_b000), 16);
            break;

        case 5:
            DmaTransfer(3, PAUSE_SCREEN_EWRAM.unk_b800, VRAM_BASE + 0x7000,
                sizeof(PAUSE_SCREEN_EWRAM.unk_b800), 16);
            DmaTransfer(3, PAUSE_SCREEN_EWRAM.unk_c000, VRAM_BASE + 0x7800,
                sizeof(PAUSE_SCREEN_EWRAM.unk_c000), 16);
            break;

        case 6:
            PAUSE_SCREEN_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;
            PAUSE_SCREEN_DATA.dispcnt |= DCNT_BG2;
            PAUSE_SCREEN_DATA.subroutineInfo.stage++;

        case 7:
            if (!PauseScreenInitFading(PAUSE_SCREEN_DATA.targetBldAlpha, 4, 0))
                PAUSE_SCREEN_DATA.subroutineInfo.stage--;
            break;

        case 8:
            PauseScreenUpdateBottomVisorOverlay(1, 1);
            PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            return TRUE;
    }

    PAUSE_SCREEN_DATA.subroutineInfo.stage++;
    return FALSE;
}

/**
 * @brief 6c0e0 | 74 | Updates the maintained input
 * 
 */
void CheckForMaintainedInput(void)
{
    gPrevChangedInput = gChangedInput;

    if (gButtonInput & KEY_ALL_DIRECTIONS)
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
        gChangedInput |= gButtonInput & KEY_ALL_DIRECTIONS;

        // Reset delay
        gMaintainedInputData.delay = 0;

        // Update set
        if (gMaintainedInputData.set < ARRAY_SIZE(sMaintainedInputDelays) - 2)
            gMaintainedInputData.set++;
    }
}
