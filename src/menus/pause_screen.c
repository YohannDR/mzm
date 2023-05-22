#include "menus/pause_screen.h"
#include "temp_globals.h"
#include "gba.h"
#include "macros.h"
#include "minimap.h"
#include "oam_id.h"
#include "event.h"
#include "text.h"
#include "color_effects.h"
#include "menus/status_screen.h"

#include "data/shortcut_pointers.h"
#include "data/menus/pause_screen_data.h"
#include "data/menus/status_screen.h"
#include "data/menus/internal_pause_screen_data.h"

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

u32 unk_68168(u16 param_1, u8 param_2, u32 param_3)
{
    // https://decomp.me/scratch/7coJ2

    i32 _param_3 = (i8)param_3;
    
    if (!PAUSE_SCREEN_DATA.unk_7C && param_2 != 0)
    {
        PAUSE_SCREEN_DATA.unk_7C++;
        
        PAUSE_SCREEN_DATA.unk_7D = param_2;
        PAUSE_SCREEN_DATA.unk_7F = _param_3;

        PAUSE_SCREEN_DATA.unk_80 = (param_1 >> 0) & 0x1F;
        PAUSE_SCREEN_DATA.unk_81 = (param_1 >> 8) & 0x1F;
        
        PAUSE_SCREEN_DATA.unk_7E = 0;

        return TRUE;
    }

    return FALSE;
}

/**
 * @brief 681c8 | 124 | To document
 * 
 * @return u8 bool, ended
 */
u8 unk_681c8(void)
{
    u8 ended;

    ended = FALSE;

    if (PAUSE_SCREEN_DATA.unk_7C)
    {
        PAUSE_SCREEN_DATA.unk_7E++;
        if (PAUSE_SCREEN_DATA.unk_7F <= PAUSE_SCREEN_DATA.unk_7E)
        {
            PAUSE_SCREEN_DATA.unk_7E = 0;

            if (gWrittenToBLDALPHA_L != PAUSE_SCREEN_DATA.unk_80)
            {
                if (gWrittenToBLDALPHA_L > PAUSE_SCREEN_DATA.unk_80)
                {
                    if (gWrittenToBLDALPHA_L - PAUSE_SCREEN_DATA.unk_80 > PAUSE_SCREEN_DATA.unk_7D)
                        gWrittenToBLDALPHA_L -= PAUSE_SCREEN_DATA.unk_7D;
                    else
                        gWrittenToBLDALPHA_L = PAUSE_SCREEN_DATA.unk_80;
                }
                else
                {
                    gWrittenToBLDALPHA_L += PAUSE_SCREEN_DATA.unk_7D;
                    if (gWrittenToBLDALPHA_L > PAUSE_SCREEN_DATA.unk_80)
                        gWrittenToBLDALPHA_L = PAUSE_SCREEN_DATA.unk_80;
                }
            }

            if (gWrittenToBLDALPHA_H != PAUSE_SCREEN_DATA.unk_81)
            {
                if (gWrittenToBLDALPHA_H > PAUSE_SCREEN_DATA.unk_81)
                {
                    if (gWrittenToBLDALPHA_H - PAUSE_SCREEN_DATA.unk_81 > PAUSE_SCREEN_DATA.unk_7D)
                        gWrittenToBLDALPHA_H -= PAUSE_SCREEN_DATA.unk_7D;
                    else
                        gWrittenToBLDALPHA_H = PAUSE_SCREEN_DATA.unk_81;
                }
                else
                {
                    gWrittenToBLDALPHA_H += PAUSE_SCREEN_DATA.unk_7D;
                    if (gWrittenToBLDALPHA_H > PAUSE_SCREEN_DATA.unk_81)
                        gWrittenToBLDALPHA_H = PAUSE_SCREEN_DATA.unk_81;
                }
            }

            if (gWrittenToBLDALPHA_L == PAUSE_SCREEN_DATA.unk_80 && gWrittenToBLDALPHA_H == PAUSE_SCREEN_DATA.unk_81)
            {
                PAUSE_SCREEN_DATA.unk_7C = FALSE;
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
            if (!PAUSE_SCREEN_DATA.mapScreenFading.unk_2)
            {
                PAUSE_SCREEN_DATA.mapScreenFading.colorToApply = 0;
                PAUSE_SCREEN_DATA.mapScreenFading.stage = 0;
                return TRUE;
            }
            break;

        case PAUSE_SCREEN_FADING_IN_INIT:
            DMATransfer(3, PALRAM_BASE, PAUSE_SCREEN_EWRAM.unk_6800, PALRAM_SIZE, 16);
            BitFill(3, 0, PALRAM_BASE, PALRAM_SIZE, 16);
            DMATransfer(3, PALRAM_BASE, PAUSE_SCREEN_EWRAM.backgroundPalette, PALRAM_SIZE, 16);

            PAUSE_SCREEN_DATA.mapScreenFading.colorToApply = 0;
            PAUSE_SCREEN_DATA.mapScreenFading.unk_2 = FALSE;
            PAUSE_SCREEN_DATA.mapScreenFading.stage = PAUSE_SCREEN_FADING_IN;
            break;

        case PAUSE_SCREEN_FADING_IN:
            if (PAUSE_SCREEN_DATA.mapScreenFading.unk_2)
                break;

            if (PAUSE_SCREEN_DATA.mapScreenFading.colorToApply < 32)
            {
                src = &PAUSE_SCREEN_EWRAM.unk_6800[0];
                dst = &PAUSE_SCREEN_EWRAM.backgroundPalette[0];
                ApplySpecialBackgroundFadingColor(FADING_TYPE_IN, PAUSE_SCREEN_DATA.mapScreenFading.colorToApply, &src, &dst, USHORT_MAX);

                src = &PAUSE_SCREEN_EWRAM.unk_6800[16 * 16];
                dst = &PAUSE_SCREEN_EWRAM.backgroundPalette[16 * 16];
                ApplySpecialBackgroundFadingColor(FADING_TYPE_IN, PAUSE_SCREEN_DATA.mapScreenFading.colorToApply, &src, &dst, USHORT_MAX);

                PAUSE_SCREEN_DATA.mapScreenFading.unk_2 = TRUE;
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
                DMATransfer(3, PAUSE_SCREEN_EWRAM.unk_6800, PAUSE_SCREEN_EWRAM.backgroundPalette, PALRAM_SIZE, 16);
                PAUSE_SCREEN_DATA.mapScreenFading.unk_2 = TRUE;
                PAUSE_SCREEN_DATA.mapScreenFading.stage = 1;
            }
            break;

        case PAUSE_SCREEN_FADING_OUT_INIT:
            DMATransfer(3, PALRAM_BASE, PAUSE_SCREEN_EWRAM.unk_6800, PALRAM_SIZE, 16);

            PAUSE_SCREEN_DATA.mapScreenFading.colorToApply = 0;
            PAUSE_SCREEN_DATA.mapScreenFading.unk_2 = FALSE;
            PAUSE_SCREEN_DATA.mapScreenFading.stage = PAUSE_SCREEN_FADING_OUT;
            break;

        case PAUSE_SCREEN_FADING_OUT:
            if (PAUSE_SCREEN_DATA.mapScreenFading.unk_2)
                break;
            
            if (PAUSE_SCREEN_DATA.mapScreenFading.colorToApply < 32)
            {
                src = &PAUSE_SCREEN_EWRAM.unk_6800[0];
                dst = &PAUSE_SCREEN_EWRAM.backgroundPalette[0];
                ApplySpecialBackgroundFadingColor(FADING_TYPE_OUT, PAUSE_SCREEN_DATA.mapScreenFading.colorToApply, &src, &dst, USHORT_MAX);

                src = &PAUSE_SCREEN_EWRAM.unk_6800[16 * 16];
                dst = &PAUSE_SCREEN_EWRAM.backgroundPalette[16 * 16];
                ApplySpecialBackgroundFadingColor(FADING_TYPE_OUT, PAUSE_SCREEN_DATA.mapScreenFading.colorToApply, &src, &dst, USHORT_MAX);

                PAUSE_SCREEN_DATA.mapScreenFading.unk_2 = TRUE;
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
                PAUSE_SCREEN_DATA.mapScreenFading.unk_2 = TRUE;
                PAUSE_SCREEN_DATA.mapScreenFading.stage = 1;
            }
    }

    if (PAUSE_SCREEN_DATA.mapScreenFading.unk_2)
    {
        DMATransfer(3, PAUSE_SCREEN_EWRAM.backgroundPalette, PALRAM_BASE, PALRAM_SIZE, 16);
        PAUSE_SCREEN_DATA.mapScreenFading.unk_2 = FALSE;
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
        DMATransfer(3, PALRAM_BASE, PAUSE_SCREEN_EWRAM.unk_6800, PALRAM_SIZE, 16);
        BitFill(3, 0, PALRAM_BASE, PALRAM_SIZE, 16);
        DMATransfer(3, PALRAM_BASE, PAUSE_SCREEN_EWRAM.unk_6800, PALRAM_SIZE, 16);
    }
    else
    {
        DMATransfer(3, PALRAM_BASE, PAUSE_SCREEN_EWRAM.unk_6800, PALRAM_SIZE, 16);
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
        DMATransfer(3, PAUSE_SCREEN_EWRAM.backgroundPalette, PALRAM_BASE, PALRAM_SIZE, 16);
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
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[0][0]].notDrawn = PAUSE_SCREEN_DATA.canScrollRight ? FALSE : TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[1][0]].notDrawn = PAUSE_SCREEN_DATA.canScrollLeft ? FALSE : TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[2][0]].notDrawn = PAUSE_SCREEN_DATA.canScrollUp ? FALSE : TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[3][0]].notDrawn = PAUSE_SCREEN_DATA.canScrollDown ? FALSE : TRUE;
    }
    else
    {
        // Not on map screen, set not drawn
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[0][0]].notDrawn = TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[1][0]].notDrawn = TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[2][0]].notDrawn = TRUE;
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[3][0]].notDrawn = TRUE;
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
 * @brief 68a58 | a8 | To document
 * 
 * @param param_1 To document
 * @return u8 To document
 */
u8 unk_68a58(u8 param_1)
{
    u8 result;

    result = FALSE;
    if (gEquipment.suitType == SUIT_SUITLESS)
    {
        switch (param_1)
        {
            case 1:
                PAUSE_SCREEN_DATA.miscOam[3].oamID = 0x29;
                result = TRUE << 1;
                break;

            case 0:
                result = TRUE << 1;
                break;

            case 2:
                break;
        }
    }
    else
    {
        switch (param_1)
        {
            case 2:
                if (gEquipment.maxMissiles + gEquipment.maxSuperMissiles != 0)
                    result = TRUE << 1;
                break;

            case 3:
                if (PAUSE_SCREEN_DATA.statusScreenData.bombActivation[0])
                    result = TRUE << 1;
                break;

            case 5:
                if (PAUSE_SCREEN_DATA.statusScreenData.miscActivation[0])
                    result = TRUE << 1;
                break;

            case 0:
            case 1:
            case 4:
                result = TRUE << 1;

            case 6:
        }
    }

    return result;
}

/**
 * @brief 68af8 | 2c4 | Draws samus on the status screen
 * 
 * @param param_1 To document
 * @return u8 To document
 */
u8 PauseScreenUpdateStatusScreenOam(u8 param_1)
{
    i32 i;
    struct MenuOamData* pOam;
    u8 result;
    i32 size;
    i16 xPosition;

    result = FALSE;
    pOam = &PAUSE_SCREEN_DATA.miscOam[2];
    size = ARRAY_SIZE(sSamusWireframeData);

    switch (param_1)
    {
        case 0:
            for (i = 0; i < size; i++, pOam++)
            {
                pOam->oamID = sSamusWireframeData[i].oamId;
                pOam->xPosition = sSamusWireframeData[i].xPosition;
                pOam->yPosition = sSamusWireframeData[i].yPosition;
                pOam->objMode = sSamusWireframeData[i].objMode;
                pOam->exists = unk_68a58(i);
            }

            PauseScreenUpdateWireframeSamus(0);
            break;

        case 1:
            for (i = 0; i < size; i++, pOam++)
            {
                pOam->oamID = sSamusWireframeData[i].oamId;
                pOam->xPosition = sSamusWireframeData[i].xPosition + sSamusWireframeData[i].xOffset;
                pOam->yPosition = sSamusWireframeData[i].yPosition;
                pOam->objMode = sSamusWireframeData[i].objMode;
                pOam->exists = unk_68a58(i);
            }

            PauseScreenUpdateWireframeSamus(1);
            PAUSE_SCREEN_DATA.dispcnt |= DCNT_WINOBJ;
            PAUSE_SCREEN_DATA.samusIconOam[0].exists = FALSE;
            break;

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

        case 3:
            pOam->exists = FALSE;
            pOam++;

            for (i = 1; i < size - 1; i++, pOam++)
            {
                if (!pOam->exists)
                    continue;

                pOam->exists = TRUE << 1;
                pOam->oamID++;
                pOam->xPosition = sSamusWireframeData[i].unk_A;
                pOam->yPosition = sSamusWireframeData[i].unk_C;
            }
            break;

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
            PAUSE_SCREEN_DATA.samusIconOam[0].exists = TRUE << 1;
            break;
    }

    return result;
}

/**
 * @brief 68dbc | 104 | Updates the samus wireframe object
 * 
 * @param param_1 To document
 */
void PauseScreenUpdateWireframeSamus(u8 param_1)
{
    u8 oamId;

    if (param_1 == 2)
    {
        if (PAUSE_SCREEN_DATA.subroutineInfo.unk_8 == FALSE)
        {
            PAUSE_SCREEN_DATA.subroutineInfo.unk_8 = TRUE;
            PAUSE_SCREEN_DATA.subroutineInfo.unk_A = 0;
        }
        return;
    }

    if (gEquipment.suitType == SUIT_NORMAL)
        oamId = 0x2C;
    else if (gEquipment.suitType == SUIT_FULLY_POWERED)
        oamId = 0x2D;
    else if (gEquipment.suitType == SUIT_SUITLESS)
        oamId = 0x2E;
    else
        oamId = 0x2C;

    if (param_1 == 0 && gPauseScreenFlag == PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS)
        oamId = 0x2E;

    PAUSE_SCREEN_DATA.miscOam[8].oamID = oamId;
    PAUSE_SCREEN_DATA.miscOam[8].exists = TRUE << 1;

    PAUSE_SCREEN_DATA.miscOam[9] = PAUSE_SCREEN_DATA.miscOam[8];
    PAUSE_SCREEN_DATA.miscOam[9].objMode = 2;

    oamId = 0;
    if (PAUSE_SCREEN_DATA.miscOam[8].oamID == 0x2E)
        oamId = 3;
    else if (gEquipment.suitMiscActivation & SMF_GRAVITY_SUIT)
        oamId = 2;
    else if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
        oamId = 1;

    DMATransfer(3, &sSamusWireframePal[oamId * 16], sObjPalramPointer + 0x80, 16 * 2, 16);
}

/**
 * @brief 68ec0 | 110 | To document
 * 
 */
void unk_68ec0(void)
{
    PAUSE_SCREEN_DATA.subroutineInfo.unk_A++;

    switch (PAUSE_SCREEN_DATA.subroutineInfo.unk_8)
    {
        case 0:
            break;

        case 1:
            PAUSE_SCREEN_DATA.bldcnt &= ~BLDCNT_BG2_FIRST_TARGET_PIXEL;
            write8(REG_WINOUT + 1, 0xD0);
            PAUSE_SCREEN_DATA.subroutineInfo.unk_8++;
            break;

        case 2:
            if (gWrittenToBLDALPHA_H < 16)
                gWrittenToBLDALPHA_H += 2;

            if (gWrittenToBLDALPHA_H > 16)
                gWrittenToBLDALPHA_H = 16;

            gWrittenToBLDALPHA_L = 16 - gWrittenToBLDALPHA_H;
            if (gWrittenToBLDALPHA_L == 0)
            {
                PAUSE_SCREEN_DATA.subroutineInfo.unk_8++;
                PAUSE_SCREEN_DATA.subroutineInfo.unk_A = 0;
            }
            break;

        case 3:
            PauseScreenUpdateWireframeSamus(1);
            PAUSE_SCREEN_DATA.subroutineInfo.unk_8++;
            PAUSE_SCREEN_DATA.subroutineInfo.unk_A = 0;
            break;

        case 4:
            PAUSE_SCREEN_DATA.subroutineInfo.unk_8++;
            PAUSE_SCREEN_DATA.subroutineInfo.unk_A = 0;

        case 5:
            if (gWrittenToBLDALPHA_L < 16)
                gWrittenToBLDALPHA_L += 2;

            if (gWrittenToBLDALPHA_L > 16)
                gWrittenToBLDALPHA_L = 16;

            gWrittenToBLDALPHA_H = 16 - gWrittenToBLDALPHA_L;
            if (gWrittenToBLDALPHA_H == 0)
            {
                PAUSE_SCREEN_DATA.subroutineInfo.unk_8++;
                PAUSE_SCREEN_DATA.subroutineInfo.unk_A = 0;
            }
            break;

        case 6:
            PAUSE_SCREEN_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL |
                BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;
            write8(REG_WINOUT + 1, (WIN1_BG3 | WIN1_OBJ) >> 8);
            PAUSE_SCREEN_DATA.subroutineInfo.unk_8 = 0;
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
        area = AREA_DEBUG;

    // Update area name at the top
    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.areaNameOam[0], sPauseScreenAreaIconsData[area].nameOamId);
    
    // Update hightlight border oam
    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.areaNameOam[2], sPauseScreenAreaIconsData[area].highlightOamId);

    // Update hightlight border position
    PAUSE_SCREEN_DATA.areaNameOam[2].xPosition = sPauseScreenAreaIconsData[area].xPosition;
    PAUSE_SCREEN_DATA.areaNameOam[2].yPosition = sPauseScreenAreaIconsData[area].yPosition;
}

/**
 * @brief 69024 | 1e8 | Updates the world map oam
 * 
 * @param onWorldMap On world map
 */
void PauseScreenUpdateWorldMap(u8 onWorldMap)
{
    struct MenuOamData* pOam;
    i32 i;
    u32 status;

    if (onWorldMap == FALSE)
    {
        pOam = &PAUSE_SCREEN_DATA.worldMapOam[0];
        pOam->priority = 2;
        pOam->oamID = gEquipment.suitType == SUIT_SUITLESS ? 0x11 : 0x10;
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
            pOam->xPosition = sPauseScreen_40d1c0[i][0];
            pOam->yPosition = sPauseScreen_40d1c0[i][1];
            pOam->priority = 2;
            pOam->exists = FALSE;

            if ((PAUSE_SCREEN_DATA.activatedTargets >> i) & 1 && pOam->xPosition + pOam->yPosition != 0)
                pOam->exists = TRUE;

            pOam->oamID = pOam->exists ? 0xF : 0;
        }
    }
    else if (onWorldMap == 2)
    {
        pOam = &PAUSE_SCREEN_DATA.worldMapOam[8];
        for (i = 0; i < 16; i++, pOam++)
        {
            if ((PAUSE_SCREEN_DATA.activatedTargets >> i) & 1)
            {
                pOam->oamID = 0xF;
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
        status = TRUE << 1;
 
    pOam = &PAUSE_SCREEN_DATA.worldMapOam[1];
    for (i = 0; i < MAX_AMOUNT_OF_AREAS - 1; i++, pOam++)
    {
        if (PAUSE_SCREEN_DATA.currentArea != i)
            pOam->oamID = sWorldMapData[i].unk_0;
        else
            pOam->oamID = sWorldMapData[i].unk_1;

        pOam->exists = (PAUSE_SCREEN_DATA.areasViewables >> i) & 1 ? status : FALSE;
    }

    pOam = &PAUSE_SCREEN_DATA.worldMapOam[0];
    pOam->xPosition = sWorldMapData[gCurrentArea].xPosition;
    pOam->yPosition = sWorldMapData[gCurrentArea].yPosition - 0x18;
}

void PauseScreenLoadAreaNamesAndIcons(void)
{
    // https://decomp.me/scratch/w2KOM

    i32 i;
    struct MenuOamData* pOam;
    const u16* ptr;

    pOam = PAUSE_SCREEN_DATA.miscOam;
    for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.miscOam); i++, pOam++)
    {
        // FIXME *pOam = sMenuOamData_Empty;
        *pOam = *(struct MenuOamData*)0x840d028;
    }

    pOam = PAUSE_SCREEN_DATA.areaNameOam;
    for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.areaNameOam); i++, pOam++)
    {
        // FIXME *pOam = sMenuOamData_Empty;
        *pOam = *(struct MenuOamData*)0x840d028;
    }

    pOam = PAUSE_SCREEN_DATA.borderArrowsOam;
    for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.borderArrowsOam); i++, pOam++)
    {
        // FIXME *pOam = sMenuOamData_Empty;
        *pOam = *(struct MenuOamData*)0x840d028;
    }
    
    pOam = PAUSE_SCREEN_DATA.worldMapOam;
    for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.worldMapOam); i++, pOam++)
    {
        // FIXME *pOam = sMenuOamData_Empty;
        *pOam = *(struct MenuOamData*)0x840d028;
    }

    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_GETTING_NEW_ITEM)
    {
        PauseScreenUpdateStatusScreenOam(0);
        return;
    }
    
    PAUSE_SCREEN_DATA.samusIconOam[0].oamID = gEquipment.suitType != SUIT_SUITLESS ? 0x1 : 0x2;
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

    if (PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine != PAUSE_SCREEN_SUBROUTINE_STATUS_SCREEN)
    {
        PAUSE_SCREEN_DATA.miscOam[0].oamID = 0;
        PAUSE_SCREEN_DATA.miscOam[0].yPosition = 0;
        PAUSE_SCREEN_DATA.miscOam[0].xPosition = 0;
    }
    
    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_CHOZO_STATUE_HINT)
    {
        PAUSE_SCREEN_DATA.areaNameOam[0].oamID = sPauseScreen_40d180[PAUSE_SCREEN_DATA.currentArea];
        PAUSE_SCREEN_DATA.areaNameOam[0].yPosition = sPauseScreen_40d17c[1];
        PAUSE_SCREEN_DATA.areaNameOam[0].xPosition = sPauseScreen_40d17c[0];
        PAUSE_SCREEN_DATA.areaNameOam[0].priority = 0;
        PAUSE_SCREEN_DATA.areaNameOam[0].boundBackground = 4;
        PAUSE_SCREEN_DATA.areaNameOam[0].exists = TRUE;
    }
    else if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_DOWNLOADING_MAP)
    {
        if (gCurrentArea < AREA_DEBUG)
            i = gCurrentArea;
        else
            i = AREA_DEBUG;

        UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.areaNameOam[0], sPauseScreenAreaIconsData[i].unk_0);
        PAUSE_SCREEN_DATA.areaNameOam[0].yPosition = 12;
        PAUSE_SCREEN_DATA.areaNameOam[0].xPosition = BLOCK_SIZE * 7 + HALF_BLOCK_SIZE;
        PAUSE_SCREEN_DATA.areaNameOam[0].priority = 0;
    }
    else
    {
        PAUSE_SCREEN_DATA.areaNameOam[1].oamID = 0;
        PAUSE_SCREEN_DATA.areaNameOam[1].yPosition = 0x18;
        PAUSE_SCREEN_DATA.areaNameOam[1].xPosition = BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE;
        PAUSE_SCREEN_DATA.areaNameOam[1].priority = 1;
        PauseScreenUpdateWorldMapHighlight(gCurrentArea);

        PAUSE_SCREEN_DATA.areaNameOam[0].yPosition = 12;
        PAUSE_SCREEN_DATA.areaNameOam[0].xPosition = BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE;
        PAUSE_SCREEN_DATA.areaNameOam[0].priority = 1;

        PAUSE_SCREEN_DATA.areaNameOam[2].priority = 1;

        PAUSE_SCREEN_DATA.areaNameOam[3].oamID = 0;
        PAUSE_SCREEN_DATA.areaNameOam[3].yPosition = BLOCK_SIZE * 6 + QUARTER_BLOCK_SIZE + 8;
        PAUSE_SCREEN_DATA.areaNameOam[3].xPosition = BLOCK_SIZE * 8 + HALF_BLOCK_SIZE;
        PauseScreenUpdateWorldMap(0);
    }

    PauseScreenDrawCompletionInfo(FALSE);

    for (i = 0; i < ARRAY_SIZE(sPauseScreen_40d0d0); i++)
    {
        if (gPauseScreenFlag == PAUSE_SCREEN_PAUSE_OR_CUTSCENE)
        {
            PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[i][0]].exists = TRUE;
        }

        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[i][0]].oamID = sPauseScreen_40d0d0[i][1];
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[i][0]].xPosition = sPauseScreen_40d0d0[i][2];
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[i][0]].yPosition = sPauseScreen_40d0d0[i][3];
        PAUSE_SCREEN_DATA.borderArrowsOam[sPauseScreen_40d0d0[i][0]].priority = 3;
    }
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

/**
 * @brief 6aed4 | 138 | Determines which maps are viewables
 * 
 */
void PauseScreenDetermineMapsViewable(void)
{
    i32 i;

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

void PauseScreenUpdateBottomVisorOverlay(u8 param_1, u8 param_2)
{
    // https://decomp.me/scratch/kHRx8

    i32 var_0;
    i32 var_1;
    u16* dst;
    u16* src;
    i16 temp;
    
    dst = VRAM_BASE + 0xCC40;
    src = &PAUSE_SCREEN_EWRAM.visorOverlayTilemap[0x380];
    var_0 = -1;
    var_1 = -1;

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

    if (var_1 >= 0)
    {
        temp = var_1;
        dst[0x2D] = src[temp++];
        dst[0x2E] = src[temp++];
        dst[0x2F] = src[temp++];
        dst[0x30] = src[temp++];
    }
}

/**
 * @brief 6b0f8 | 148 | Gets the minimap for the provided area
 * 
 * @param area Area
 * @param dst Destination pointer
 */
void PauseScreenGetMinimapData(u8 area, u16* dst)
{
    u32 position;
    i32 i;

    // Decompress base minimap
    CallLZ77UncompWRAM(sMinimapDataPointers[area], dst);

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

    PAUSE_SCREEN_DATA.subroutineInfo.timer++;

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
                if (!PAUSE_SCREEN_DATA.disableDebugMenu)
                    PauseScreenMoveDebugCursor(TRUE);

                leaving = FALSE;
            }
            else
            {
                StatusScreenSubroutine();
            }
            break;

        case 2:
            FadeMusic(160);
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
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer > 12)
                leaving = TRUE;
            break;

        case PAUSE_SCREEN_SUBROUTINE_CHOZO_STATUE_HINT:
            if (ChozoStatueHintSubroutine())
            {
                PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = 0xE;
            }
            break;

        case PAUSE_SCREEN_SUBROUTINE_MAP_DOWNLOAD:
            if (PauseScreenMapDownloadSubroutine())
            {
                PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = 0x12;
            }
            break;

        case PAUSE_SCREEN_SUBROUTINE_EASY_SLEEP:
            if (PauseScreenEasySleepSubroutine())
            {
                PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_EASY_SLEEP_LEAVING;
            }
            break;

        case PAUSE_SCREEN_SUBROUTINE_STATUS_SCREEN_INIT:
            if (PAUSE_SCREEN_DATA.unk_7C)
            {
                unk_681c8();
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
            if (PAUSE_SCREEN_DATA.unk_7C)
            {
                unk_681c8();
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
            PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = 0x3;
            PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case 14:
            if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_ON_MAP_SCREEN)
                PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = 0x2;
            else
                PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_MAP_SCREEN;
            break;

        case PAUSE_SCREEN_SUBROUTINE_EASY_SLEEP_INIT:
            if (PAUSE_SCREEN_DATA.unk_7C)
            {
                unk_681c8();
            }
            else
            {
                if (PauseScreenEasySleepInit())
                {
                    PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_EASY_SLEEP;
                    PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
                    PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                }
            }
            break;

        case PAUSE_SCREEN_SUBROUTINE_EASY_SLEEP_LEAVING:
            if (PAUSE_SCREEN_DATA.unk_7C)
            {
                unk_681c8();
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
    PAUSE_SCREEN_DATA.miscOam[0].yPosition &= (~HALF_BLOCK_SIZE + 1);
    PAUSE_SCREEN_DATA.miscOam[0].xPosition &= (~HALF_BLOCK_SIZE + 1);
    
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
u32 unk_6b66c(u16* param_1, u16 param_2)
{
    u32 result;
    i32 var_0;
    i32 var_1;

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
        var_1 = (i16)*param_1;
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
u32 unk_6b6c4(u16* param_1, u16 param_2)
{
    u32 result;
    i32 var_0;
    i32 var_1;

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
        var_1 = (i16)*param_1;
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
    i32 offset;

    if (oamId != UCHAR_MAX)
    {
        UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.areaNameOam[1], oamId);
    }

    if (oamId == 0xF)
        offset = 1;
    else if (oamId == 0x10)
        offset = 2;
    else if (oamId == 0)
        offset = 0;
    else
        offset = 3;

    DMATransfer(3, &PAUSE_SCREEN_EWRAM.visorOverlayTilemap[0x280 + offset * 0x40], VRAM_BASE + 0xC800, 0x80, 16);
}

/**
 * @brief 6b778 | c0 | Initializes the status screen for a suit change (suitless or fully powered)
 * 
 * @return i32 bool, ended (-1 and 0)
 */
i32 PauseScreenSuitChangingStart(void)
{
    i32 stage;

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
 * @return i32 bool, ended (-1 and 0)
 */
i32 PauseScreenStatusScreenInit(void)
{
    i32 stage;
    
    stage = 0;
    switch (PAUSE_SCREEN_DATA.subroutineInfo.stage)
    {
        case 0:
            // Background tilemap?
            if (gEquipment.suitType == SUIT_SUITLESS)
            {
                DMATransfer(3, PAUSE_SCREEN_EWRAM.unk_8000, VRAM_BASE + 0xC000, 0x500, 32);
            }
            else
            {
                DMATransfer(3, PAUSE_SCREEN_EWRAM.unk_7800, VRAM_BASE + 0xC000, 0x500, 32);
            }
            
            // Set stage 1
            stage = 1;
            break;

        case 1:
            // Update top overlay
            PauseScreenUpdateTopVisorOverlay(0xF);
            stage = UCHAR_MAX + 1;
            SoundPlay(0x1F4);
            break;

        case 2:
            if (unk_68168(0x1000, 2, 0))
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
            if (unk_68168(0x10, 2, 0))
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
            PAUSE_SCREEN_DATA.areaNameOam[0].exists = FALSE;
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
 * @return i32 bool, ended (-1 and 0)
 */
i32 PauseScreenQuitStatusScreen(void)
{
    i32 stage;
    
    stage = 0;
    switch (PAUSE_SCREEN_DATA.subroutineInfo.stage)
    {
        case 0:
            SoundPlay(0x1F5);
            PAUSE_SCREEN_DATA.miscOam[0].oamID = 0;
            PauseScreenUpdateTopVisorOverlay(0);
            stage = UCHAR_MAX + 1;
            break;

        case 1:
            PauseScreenUpdateStatusScreenOam(4);
            PAUSE_SCREEN_DATA.miscOam[1].exists = FALSE;
            stage = UCHAR_MAX + 1;
            break;

        case 2:
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer > 12)
                stage = UCHAR_MAX + 1;
            break;

        case 3:
            if (unk_68168(0x1000, 2, 0))
            {
                PAUSE_SCREEN_DATA.dispcnt &= ~DCNT_BG0;
                PAUSE_SCREEN_DATA.areaNameOam[3].exists = FALSE;
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
            PAUSE_SCREEN_DATA.areaNameOam[0].exists = TRUE;
            PAUSE_SCREEN_DATA.subroutineInfo.stage++;

        case 6:
            PAUSE_SCREEN_DATA.bg2cnt = PAUSE_SCREEN_DATA.unk_72;
            stage = UCHAR_MAX + 1;
            break;

        case 7:
            if (unk_68168(PAUSE_SCREEN_DATA.unk_68, 2, 0))
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
        gWrittenToBLDALPHA_H = PAUSE_SCREEN_DATA.unk_68 >> 8;
        gWrittenToBLDALPHA_L = PAUSE_SCREEN_DATA.unk_68 & 0xFF;
    }

    return stage;
}

/**
 * @brief 6bc34 | 2d4 | Initializes the easy sleep screen
 * 
 * @return i32 bool, ended
 */
i32 PauseScreenEasySleepInit(void)
{
    // Update text processing
    if (PAUSE_SCREEN_DATA.easySleepTextState >= 0)
        TextDrawEasySleep();

    switch (PAUSE_SCREEN_DATA.subroutineInfo.stage)
    {
        case 0:
            if (!unk_68168(0x1000, 4, 0))
                PAUSE_SCREEN_DATA.subroutineInfo.stage--;
            break;

        case 1: 
            PauseScreenUpdateBottomVisorOverlay(2, 2);
            PauseScreenUpdateTopVisorOverlay(0x10);
            PAUSE_SCREEN_DATA.dispcnt &= ~DCNT_BG2;
            break;

        case 2:
            // Transfer tilemap
            DMATransfer(3, PAUSE_SCREEN_EWRAM.easySleepTilemap, VRAM_BASE + 0xD000, sizeof(PAUSE_SCREEN_EWRAM.easySleepTilemap), 16);
            break;

        case 3:
            // Make a backup of some GFX
            DMATransfer(3, VRAM_BASE + 0x6000, PAUSE_SCREEN_EWRAM.equipmentNamesGfxBackup,
                sizeof(PAUSE_SCREEN_EWRAM.equipmentNamesGfxBackup), 16);
            DMATransfer(3, VRAM_BASE + 0x6800, PAUSE_SCREEN_EWRAM.unk_b000,
                sizeof(PAUSE_SCREEN_EWRAM.unk_b000), 16);
            break;

        case 4:
            // More backups
            DMATransfer(3, VRAM_BASE + 0x7000, PAUSE_SCREEN_EWRAM.unk_b800,
                sizeof(PAUSE_SCREEN_EWRAM.unk_b800), 16);
            DMATransfer(3, VRAM_BASE + 0x7800, PAUSE_SCREEN_EWRAM.unk_c000,
                sizeof(PAUSE_SCREEN_EWRAM.unk_c000), 16);
            break;

        case 6:
            // Format easy sleep tilemap
            dma_set(3, &PAUSE_SCREEN_EWRAM.unk_6000[0], &PAUSE_SCREEN_EWRAM.easySleepTextFormatted_1[0x1C0], DMA_ENABLE << 16 | 0x40);
            dma_set(3, &PAUSE_SCREEN_EWRAM.unk_6000[0x200], &PAUSE_SCREEN_EWRAM.easySleepTextFormatted_1[0x3C0], DMA_ENABLE << 16 | 0x40);
            dma_set(3, &PAUSE_SCREEN_EWRAM.unk_6000[0xE0], &PAUSE_SCREEN_EWRAM.easySleepTextFormatted_2[0x1C0], DMA_ENABLE << 16 | 0x40);
            dma_set(3, &PAUSE_SCREEN_EWRAM.unk_6000[0x2E0], &PAUSE_SCREEN_EWRAM.easySleepTextFormatted_2[0x3C0], DMA_ENABLE << 16 | 0x40);
            break;

        case 7:
            // Transfer message text
            if ((u8)PAUSE_SCREEN_DATA.easySleepTextState > 1)
            {
                DMATransfer(3, PAUSE_SCREEN_EWRAM.easySleepTextFormatted_1, VRAM_BASE + 0x6000,
                    sizeof(PAUSE_SCREEN_EWRAM.easySleepTextFormatted_1), 16);

                DMATransfer(3, PAUSE_SCREEN_EWRAM.easySleepTextFormatted_2, VRAM_BASE + 0x6800,
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
                DMATransfer(3, PAUSE_SCREEN_EWRAM.unk_5000, VRAM_BASE + 0x7000,
                    sizeof(PAUSE_SCREEN_EWRAM.unk_5000), 16);

                DMATransfer(3, PAUSE_SCREEN_EWRAM.unk_5800, VRAM_BASE + 0x7800,
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
            if (!unk_68168(0x10, 4, 0))
                PAUSE_SCREEN_DATA.subroutineInfo.stage--;
            break;

        case 11:
            // Setup cursor
            UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[1], 2);
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
 * @return i32 bool, ended
 */
i32 PauseScreenQuitEasySleep(void)
{
    switch (PAUSE_SCREEN_DATA.subroutineInfo.stage)
    {
        case 0:
            gDisableSoftreset = FALSE;
            PauseScreenUpdateTopVisorOverlay(0);
            PAUSE_SCREEN_DATA.subroutineInfo.stage++;

        case 1:
            if (!unk_68168(0x1000, 4, 0))
                PAUSE_SCREEN_DATA.subroutineInfo.stage--;
            break;

        case 2:
            PAUSE_SCREEN_DATA.dispcnt &= ~DCNT_BG2;
            UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[1], 0);
            PAUSE_SCREEN_DATA.miscOam[1].objMode = 0;
            break;

        case 3:
            dma_set(3, PAUSE_SCREEN_EWRAM.mapScreenOverlayTilemap, VRAM_BASE + 0xD000,
                DMA_ENABLE << 16 | ARRAY_SIZE(PAUSE_SCREEN_EWRAM.mapScreenOverlayTilemap));
            break;

        case 4:
            DMATransfer(3, PAUSE_SCREEN_EWRAM.equipmentNamesGfxBackup, VRAM_BASE + 0x6000,
                sizeof(PAUSE_SCREEN_EWRAM.equipmentNamesGfxBackup), 16);
            DMATransfer(3, PAUSE_SCREEN_EWRAM.unk_b000, VRAM_BASE + 0x6800,
                sizeof(PAUSE_SCREEN_EWRAM.unk_b000), 16);
            break;

        case 5:
            DMATransfer(3, PAUSE_SCREEN_EWRAM.unk_b800, VRAM_BASE + 0x7000,
                sizeof(PAUSE_SCREEN_EWRAM.unk_b800), 16);
            DMATransfer(3, PAUSE_SCREEN_EWRAM.unk_c000, VRAM_BASE + 0x7800,
                sizeof(PAUSE_SCREEN_EWRAM.unk_c000), 16);
            break;

        case 6:
            PAUSE_SCREEN_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;
            PAUSE_SCREEN_DATA.dispcnt |= DCNT_BG2;
            PAUSE_SCREEN_DATA.subroutineInfo.stage++;

        case 7:
            if (!unk_68168(PAUSE_SCREEN_DATA.unk_68, 4, 0))
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
