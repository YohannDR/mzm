#include "cutscenes/cutscene_utils.h"
#include "gba.h"
#include "oam.h"
#include "color_effects.h"

#include "data/cutscenes/cutscenes_data.h"
#include "data/menus/pause_screen_data.h"
#include "data/shortcut_pointers.h"
#include "data/engine_pointers.h"

#include "constants/audio.h"
#include "constants/connection.h"
#include "constants/color_fading.h"
#include "constants/cutscene.h"
#include "constants/event.h"
#include "constants/game_state.h"

#include "structs/audio.h"
#include "structs/cutscene.h"
#include "structs/connection.h"
#include "structs/display.h"
#include "structs/game_state.h"

/**
 * @brief 60e28 | 4 | Default subroutine for cutscenes that don't have any
 * 
 * @return u8 1
 */
u8 CutsceneDefaultRoutine(void)
{
    return TRUE;
}

/**
 * @brief 60e2c | 94 | Subroutine for the tourian escape
 * 
 * @return u8 bool, ended
 */
u8 TourianEscapeSubroutine(void)
{
    u8 ended;

    ended = FALSE;
    if (sTourianEscapeFunctionPointers[gTourianEscapeCutsceneStage]())
    {
        SET_BACKDROP_COLOR(COLOR_BLACK);
        gSubGameModeStage = 0;
        gGameModeSub1 = 0;
        gGameModeSub2 = 4;
        ended = TRUE;
    }

    if (ended)
    {
        if (gTourianEscapeCutsceneStage == 1)
        {
            ColorFadingStart(COLOR_FADING_CANCEL);
            gCurrentArea = AREA_CHOZODIA;
            gCurrentRoom = 0;
            gLastDoorUsed = 0;
            gCurrentCutscene = CUTSCENE_COULD_I_SURVIVE;
            gGameModeSub2 = 10;
        }

        return TRUE;
    }

    return FALSE;
}

/**
 * @brief 60ec0 | 34 | Updates the audio after a cutscene was skipped
 * 
 */
void CutsceneUpdateMusicAfterSkip(void)
{
    switch (gCurrentCutscene)
    {
        case CUTSCENE_KRAID_RISING:
            PlayMusic(MUSIC_KRAID_BATTLE_WITH_INTRO, 0);
            break;

        case CUTSCENE_RIDLEY_SPAWNING:
            SoundPlay(SOUND_RIDLEY_SPAWN_ROAR);
    }

    FadeAllSounds(CONVERT_SECONDS(1.f / 6));
}

/**
 * @brief 60ef4 | 150 | Ends a cutscene
 * 
 */
void CutsceneEnd(void)
{
    switch (gCurrentCutscene)
    {
        case CUTSCENE_RIDLEY_LANDING:
            EventFunction(EVENT_ACTION_SETTING, sCutsceneData[CUTSCENE_RIDLEY_IN_SPACE].event);
            break;

        case CUTSCENE_INTRO_TEXT:
            gCurrentArea = AREA_BRINSTAR;
            gCurrentRoom = 0;
            gLastDoorUsed = 0;
            gGameModeSub3 = 0;
            gShipLandingFlag = FALSE;
            break;

        case CUTSCENE_GETTING_FULLY_POWERED:
            gPauseScreenFlag = PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS;
            break;

        case CUTSCENE_COULD_I_SURVIVE:
            gPauseScreenFlag = PAUSE_SCREEN_SUITLESS_ITEMS;
            gMusicTrackInfo.pauseScreenFlag = PAUSE_SCREEN_SUITLESS_ITEMS;
            break;

        case CUTSCENE_STATUE_OPENING:
            if (gCurrentArea == AREA_KRAID)
            {
                SoundStop(MUSIC_STATUE_ROOM_OPENED);
                unk_3bd0(MUSIC_KRAID_BATTLE_WITH_INTRO, 60);
            }
            else if (gCurrentArea == AREA_RIDLEY)
            {
                SoundStop(MUSIC_STATUE_ROOM_OPENED);
                unk_3bd0(MUSIC_RIDLEY_BATTLE, 60);
            }
    }

    ColorFadingStart(sCutsceneData[gCurrentCutscene].bgFading);
    if (sCutsceneData[gCurrentCutscene].event != EVENT_NONE)
        EventFunction(EVENT_ACTION_SETTING, sCutsceneData[gCurrentCutscene].event);

    if (sCutsceneData[gCurrentCutscene].isElevator)
    {
        PlayFadingSound(SOUND_ELEVATOR, sCutsceneData[gCurrentCutscene].fadingTimer);
        CheckPlayFadingMusic(gMusicTrackInfo.currentRoomTrack, sCutsceneData[gCurrentCutscene].fadingTimer, 0);
    }
}

/**
 * @brief 61044 | 1e4 | Subroutine for a cutscene
 * 
 * @return u8 1 if ended, 0 otherwise
 */
u8 CutsceneSubroutine(void)
{
    u8 result;
    u8 ended;

    switch (gSubGameModeStage)
    {
        case 0:
            CallbackSetVBlank(CutsceneLoadingVBlank);
            if (CutsceneStartBackgroundFading(sCutsceneData[gCurrentCutscene].preBgFading))
                gSubGameModeStage = 2;
            else
                gSubGameModeStage = 1;
            break;

        case 1:
            unk_61f60();
            if (CutsceneUpdateFading())
                gSubGameModeStage++;
            break;
            
        case 2:
            CutsceneInit();
            CallbackSetVBlank(CutsceneVBlank);

            gSubGameModeStage++;
            break;
            
        case 3:
            CUTSCENE_DATA.timeInfo.timer++;
            CutsceneUpdateSpecialEffect();

            result = sCutsceneData[gCurrentCutscene].pFunction();
            if (result)
                ended = TRUE;
            else
                ended = FALSE;

            if (gCutsceneToSkip == gCurrentCutscene && gChangedInput & KEY_B)
            {
                CutsceneUpdateMusicAfterSkip();
                ended = TRUE;
            }

            if (ended)
            {
                CUTSCENE_DATA.dispcnt = 0;
                gSubGameModeStage++;
            }
            break;
            
        case 4:
            if (CUTSCENE_DATA.fadingType == 3)
                BitFill(3, SHORT_MAX, PALRAM_BASE, PALRAM_SIZE, 0x10);
            else
                BitFill(3, 0, PALRAM_BASE, PALRAM_SIZE, 0x10);

            BitFill(3, 0x40, VRAM_BASE, 0x10000, 0x10);
            BitFill(3, 0, VRAM_OBJ, 0x8000, 0x10);
            BitFill(3, 0xFF, OAM_BASE, OAM_SIZE, 0x20);

            CutsceneEnd();

            if (sCutsceneData[gCurrentCutscene].skippable)
                gCutsceneToSkip = gCurrentCutscene;

            gSubGameModeStage = 0;

            if (sCutsceneData[gCurrentCutscene].unk_0 == 0)
                gCurrentCutscene = CUTSCENE_NONE;
        
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 61228 | 4 | Subroutine that marks the end of a cutscene
 * 
 * @return u8 1
 */
u8 CutsceneEndFunction(void)
{
    return TRUE;
}

/**
 * @brief 6122c | a8 | V-blank code during cutscenes
 * 
 */
void CutsceneVBlank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | 0x100);

    write16(REG_BG0HOFS, CUTSCENE_DATA.bg0hofs);
    write16(REG_BG0VOFS, CUTSCENE_DATA.bg0vofs);
    write16(REG_BG1HOFS, CUTSCENE_DATA.bg1hofs);
    write16(REG_BG1VOFS, CUTSCENE_DATA.bg1vofs);
    write16(REG_BG2HOFS, CUTSCENE_DATA.bg2hofs);
    write16(REG_BG2VOFS, CUTSCENE_DATA.bg2vofs);
    write16(REG_BG3HOFS, CUTSCENE_DATA.bg3hofs);
    write16(REG_BG3VOFS, CUTSCENE_DATA.bg3vofs);

    write16(REG_BG0CNT, CUTSCENE_DATA.bgcnt[0]);
    write16(REG_BG1CNT, CUTSCENE_DATA.bgcnt[1]);
    write16(REG_BG2CNT, CUTSCENE_DATA.bgcnt[2]);
    write16(REG_BG3CNT, CUTSCENE_DATA.bgcnt[3]);

    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);
    write16(REG_BLDALPHA, gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L);

    write16(REG_BLDCNT, CUTSCENE_DATA.bldcnt);
    write16(REG_DISPCNT, CUTSCENE_DATA.dispcnt);
}

/**
 * @brief 612d4 | c | V blank code when loading a cutscene
 * 
 */
void CutsceneLoadingVBlank(void)
{
    vu8 var = 0;
}

/**
 * @brief 612e0 | 13c | Initializes a cutscene
 * 
 */
void CutsceneInit(void)
{
    s32 unk;

    CallbackSetVBlank(CutsceneLoadingVBlank);
    BitFill(3, 0, &gNonGameplayRAM, sizeof(union NonGameplayRAM), 0x20);

    gOamXOffset_NonGameplay = gOamYOffset_NonGameplay = 0;
    gNextOamSlot = 0;
    ResetFreeOam();

    write16(REG_BLDCNT, CUTSCENE_DATA.bldcnt = 0xFF);

    write16(REG_BLDY, gWrittenToBLDY_NonGameplay = BLDY_MAX_VALUE);

    write16(REG_DISPCNT, CUTSCENE_DATA.dispcnt = 0);

    unk = sCutsceneData[gCurrentCutscene].unk_0;
    if (unk != 0)
    {
        if (unk == 2)
            gPauseScreenFlag = PAUSE_SCREEN_PAUSE_OR_CUTSCENE;

        if (unk < 3)
            DmaTransfer(3, VRAM_OBJ, EWRAM_BASE + 0x1E000, unk * 0x4000, 0x10);
    }

    if (gCutsceneToSkip != gCurrentCutscene)
        gCutsceneToSkip = CUTSCENE_NONE;

    ClearGfxRam();

    gBg0HOFS_NonGameplay = gBg0VOFS_NonGameplay = 0x800;
    gBg1HOFS_NonGameplay = gBg1VOFS_NonGameplay = 0x800;
    gBg2HOFS_NonGameplay = gBg2VOFS_NonGameplay = 0x800;
    gBg3HOFS_NonGameplay = gBg3VOFS_NonGameplay= 0x800;

    CUTSCENE_DATA.timeInfo.stage = 0;
    CUTSCENE_DATA.timeInfo.timer = 0;
    sCutsceneData[gCurrentCutscene].pFunction();
}

/**
 * @brief 6141c | 58 | Sets up a BGCNT IO register with the page data info
 * 
 * @param pageData Page Data Info
 */
void CutsceneSetBgcntPageData(struct CutscenePageData pageData)
{
    u8 offset;

    if (pageData.bg == DCNT_BG0)
        offset = 0;
    else if (pageData.bg == DCNT_BG1)
        offset = 1;
    else if (pageData.bg == DCNT_BG2)
        offset = 2;
    else if (pageData.bg == DCNT_BG3)
        offset = 3;
    else
        return;

    CUTSCENE_DATA.bgcnt[offset] = pageData.screenSize | pageData.priority | (pageData.tiletablePage << 8) | (pageData.graphicsPage << 2);
}

/**
 * @brief 61484 | 50 | Changes the BGCNT value of a specified background
 * 
 * @param value Value
 * @param bg Background (DISPCNT flags)
 */
void CutsceneSetBgcnt(u16 value, u16 bg)
{
    u8 offset;

    if (bg == DCNT_BG0)
        offset = 0;
    else if (bg == DCNT_BG1)
        offset = 1;
    else if (bg == DCNT_BG2)
        offset = 2;
    else if (bg == DCNT_BG3)
        offset = 3;
    else
        return;

    CUTSCENE_DATA.bgcnt[offset] = value;
}

/**
 * @brief 614d4 | a4 | Sets the position of a background
 * 
 * @param type Type (HOVS | VOFS)
 * @param bg Background (DISPCNT flags)
 * @param value Value
 */
void CutsceneSetBackgroundPosition(u8 type, u16 bg, u16 value)
{
    if (type & CUTSCENE_BG_EDIT_HOFS)
    {
        if (bg == DCNT_BG0)
            gBg0HOFS_NonGameplay = value;
        else if (bg == DCNT_BG1)
            gBg1HOFS_NonGameplay = value;
        else if (bg == DCNT_BG2)
            gBg2HOFS_NonGameplay = value;
        else if (bg == DCNT_BG3)
            gBg3HOFS_NonGameplay = value;
    }

    if (type & CUTSCENE_BG_EDIT_VOFS)
    {
        if (bg == DCNT_BG0)
            gBg0VOFS_NonGameplay = value;
        else if (bg == DCNT_BG1)
            gBg1VOFS_NonGameplay = value;
        else if (bg == DCNT_BG2)
            gBg2VOFS_NonGameplay = value;
        else if (bg == DCNT_BG3)
            gBg3VOFS_NonGameplay = value;
    }
}

/**
 * @brief 61578 | 50 | Gets the pointer to the HOFS (X) value of a specified background
 * 
 * @param bg Background (DISPCNT flags)
 * @return u16* Pointer
 */
u16* CutsceneGetBgHorizontalPointer(u16 bg)
{
    u16* pBg;

    pBg = NULL;
    if (bg == DCNT_BG0)
        pBg = &gBg0HOFS_NonGameplay;
    else if (bg == DCNT_BG1)
        pBg = &gBg1HOFS_NonGameplay;
    else if (bg == DCNT_BG2)
        pBg = &gBg2HOFS_NonGameplay;
    else if (bg == DCNT_BG3)
        pBg = &gBg3HOFS_NonGameplay;

    return pBg;
}

/**
 * @brief 615c8 | 50 | Gets the pointer to the VOFS (Y) value of a specified background
 * 
 * @param bg Background (DISPCNT flags)
 * @return u16* Pointer
 */
u16* CutsceneGetBgVerticalPointer(u16 bg)
{
    u16* pBg;

    pBg = NULL;
    if (bg == DCNT_BG0)
        pBg = &gBg0VOFS_NonGameplay;
    else if (bg == DCNT_BG1)
        pBg = &gBg1VOFS_NonGameplay;
    else if (bg == DCNT_BG2)
        pBg = &gBg2VOFS_NonGameplay;
    else if (bg == DCNT_BG3)
        pBg = &gBg3VOFS_NonGameplay;

    return pBg;
}

/**
 * @brief 61618 | 2c0 | Starts a background scrolling
 * 
 * @param scrollingData Scrolling data
 * @param bg Backgrounds
 * @return u32 
 */
u32 CutsceneStartBackgroundScrolling(struct CutsceneScrollingInfo scrollingData, u16 bg)
{
    s32 nbrBackgrounds;
    s32 slot;
    s32 var_0;

    nbrBackgrounds = 0;

    // Check not already active
    if (bg & DCNT_BG0 && CUTSCENE_DATA.bgScrolling[scrollingData.direction].pPosition)
        nbrBackgrounds++;

    if (bg & DCNT_BG1 && CUTSCENE_DATA.bgScrolling[scrollingData.direction + 2].pPosition)
        nbrBackgrounds++;

    if (bg & DCNT_BG2 && CUTSCENE_DATA.bgScrolling[scrollingData.direction + 4].pPosition)
        nbrBackgrounds++;

    if (bg & DCNT_BG3 && CUTSCENE_DATA.bgScrolling[scrollingData.direction + 6].pPosition)
        nbrBackgrounds++;

    // Already exsits, abort
    if (nbrBackgrounds != 0)
        return FALSE;

    while (nbrBackgrounds < 4)
    {
        // Get slot, each background has 2 slots attributed to it, one for horizontal and one for vertical
        // BG0H ; BG0V ; BG1H ; BG1V ; BG2H ; BG2V ; BG3H ; BG3V
        switch (nbrBackgrounds)
        {
            case 0:
                if (!(bg & DCNT_BG0))
                    slot = -1;
                else
                    slot = 0;
                break;

            case 1:
                if (bg & DCNT_BG1)
                    slot = 2;
                else
                    slot = -1;
                break;

            case 2:
                if (bg & DCNT_BG2)
                    slot = 4;
                else
                    slot = -1;
                break;

            case 3:
                if (bg & DCNT_BG3)
                    slot = 6;
                else
                    slot = -1;
                break;

            default:
                slot = -1;
        }

        nbrBackgrounds++;

        if (slot < 0)
            continue;

        // Offset by direction (horizontal/vertical)
        slot += scrollingData.direction;

        // Set pointer
        switch (slot)
        {
            case 0:
                CUTSCENE_DATA.bgScrolling[slot].pPosition = &gBg0HOFS_NonGameplay;
                break;

            case 1:
                CUTSCENE_DATA.bgScrolling[slot].pPosition = &gBg0VOFS_NonGameplay;
                break;

            case 2:
                CUTSCENE_DATA.bgScrolling[slot].pPosition = &gBg1HOFS_NonGameplay;
                break;

            case 3:
                CUTSCENE_DATA.bgScrolling[slot].pPosition = &gBg1VOFS_NonGameplay;
                break;

            case 4:
                CUTSCENE_DATA.bgScrolling[slot].pPosition = &gBg2HOFS_NonGameplay;
                break;

            case 5:
                CUTSCENE_DATA.bgScrolling[slot].pPosition = &gBg2VOFS_NonGameplay;
                break;

            case 6:
                CUTSCENE_DATA.bgScrolling[slot].pPosition = &gBg3HOFS_NonGameplay;
                break;

            case 7:
                CUTSCENE_DATA.bgScrolling[slot].pPosition = &gBg3VOFS_NonGameplay;
                break;
        }

        // Set speed
        if (scrollingData.speed == 0)
        {
            // No speed, set according to length
            CUTSCENE_DATA.bgScrolling[slot].speed = scrollingData.length >= 0 ? 1 : -1;
        }
        else
        {
            // Set actual speed
            CUTSCENE_DATA.bgScrolling[slot].speed = scrollingData.speed;
        }

        // Set parameters
        CUTSCENE_DATA.bgScrolling[slot].maxDelay = scrollingData.maxDelay;
        CUTSCENE_DATA.bgScrolling[slot].delay = scrollingData.maxDelay;
        CUTSCENE_DATA.bgScrolling[slot].lengthLeft = scrollingData.length;
    }

    return TRUE;
}

/**
 * @brief 618d8 | 6c | Updates a cutscene background scrolling
 * 
 * @param pScrolling Cutscene Scrolling Data Pointer
 */
void CutsceneUpdateBackgroundScrolling(struct CutsceneScrolling* pScrolling)
{
    s32 offset;

    if (pScrolling->lengthLeft != 0)
    {
        // Update delay
        if (pScrolling->delay > 0)
            pScrolling->delay--;
        else
        {
            // Reset delay
            pScrolling->delay = pScrolling->maxDelay;

            // Check speed doesn't overflow length left
            if (pScrolling->speed >= 0)
            {
                if (pScrolling->lengthLeft < pScrolling->speed)
                    offset = FALSE;
                else
                    offset = TRUE;
            }
            else
            {
                if (pScrolling->lengthLeft > pScrolling->speed)
                    offset = FALSE;
                else
                    offset = TRUE;
            }

            if (offset)
            {
                // No overflow, move at designated speed
                offset = pScrolling->speed;    
                pScrolling->lengthLeft -= offset;
            }
            else
            {
                // Overflow, move of what's left
                offset = pScrolling->lengthLeft;
                pScrolling->lengthLeft = 0;
            }

            (*pScrolling->pPosition) += offset;
        }
        
    }

    // Check ended
    if (pScrolling->lengthLeft == 0)
        pScrolling->pPosition = NULL;
}

/**
 * @brief 61944 | 80 | Checks if a background scrolling is active
 * 
 * @param bg Background
 * @return u8 Flags
 */
u8 CutsceneCheckBackgroundScrollingActive(u16 bg)
{
    s32 offset;    
    u8 status;

    status = 0;
    offset = -1;
    if (bg == DCNT_BG0)
        offset = 0;
    else if (bg == DCNT_BG1)
        offset = 2;
    else if (bg == DCNT_BG2)
        offset = 4;
    else if (bg == DCNT_BG3)
        offset = 6;

    if (offset >= 0)
    {
        if (CUTSCENE_DATA.bgScrolling[offset].pPosition)
            status |= CUTSCENE_BG_EDIT_HOFS;

        offset = (s8)(offset + 1);
        if (CUTSCENE_DATA.bgScrolling[offset].pPosition)
            status |= CUTSCENE_BG_EDIT_VOFS;
    }

    return status;
}

/**
 * @brief 619c4 | c4 | Updates the backgrounds positions
 * 
 * @param updateScrolling Update scrolling flag
 */
void CutsceneUpdateBackgroundsPosition(u8 updateScrolling)
{
    s32 i;

    if (updateScrolling & TRUE)
    {
        for (i = 0; i < ARRAY_SIZE(CUTSCENE_DATA.bgScrolling); i++)
        {
            if (CUTSCENE_DATA.bgScrolling[i].pPosition != NULL)
                CutsceneUpdateBackgroundScrolling(CUTSCENE_DATA.bgScrolling + i);
        }
    }

    CUTSCENE_DATA.bg0hofs = gBg0HOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg0vofs = gBg0VOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg1hofs = gBg1HOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg1vofs = gBg1VOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg2hofs = gBg2HOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg2vofs = gBg2VOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg3hofs = gBg3HOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg3vofs = gBg3VOFS_NonGameplay / 4;

    if (CUTSCENE_DATA.horizontalScreenShake.bg != 0)
        CutsceneUpdateScreenShake(FALSE, &CUTSCENE_DATA.horizontalScreenShake);

    if (CUTSCENE_DATA.verticalScreenShake.bg != 0)
        CutsceneUpdateScreenShake(TRUE, &CUTSCENE_DATA.verticalScreenShake);
}

/**
 * @brief 61a88 | 110 | 
 * 
 * @param affectVertical Affect vertical offset
 * @param pShake Cutscene screen shake pointer
 */
void CutsceneUpdateScreenShake(u8 affectVertical, struct CutsceneScreenShake* pShake)
{
    s32 offset;
    s32 size;

    // Update delay
    if (pShake->delay > 1)
    {
        pShake->delay--;
        return;
    }

    // Reset delay
    pShake->delay = pShake->maxDelay;

    // Check not overflowing
    size = sCutsceneScreenShakeOffsetSetSizes[pShake->set];
    if (pShake->currentSubSet > size)
        pShake->currentSubSet = 0;

    // Get screen offset
    offset = sCutsceneScreenShakeOffsetSetPointers[pShake->set][pShake->currentSubSet];
    
    // Update sub set
    pShake->currentSubSet++;

    // Apply
    if (!affectVertical)
    {
        // On horizontal
        if (pShake->bg & DCNT_BG0)
            CUTSCENE_DATA.bg0hofs += offset;

        if (pShake->bg & DCNT_BG1)
            CUTSCENE_DATA.bg1hofs += offset;

        if (pShake->bg & DCNT_BG2)
            CUTSCENE_DATA.bg2hofs += offset;

        if (pShake->bg & DCNT_BG3)
            CUTSCENE_DATA.bg3hofs += offset;
    }
    else
    {
        // On vertical
        if (pShake->bg & DCNT_BG0)
            CUTSCENE_DATA.bg0vofs += offset;

        if (pShake->bg & DCNT_BG1)
            CUTSCENE_DATA.bg1vofs += offset;

        if (pShake->bg & DCNT_BG2)
            CUTSCENE_DATA.bg2vofs += offset;

        if (pShake->bg & DCNT_BG3)
            CUTSCENE_DATA.bg3vofs += offset;
    }
}

/**
 * @brief 61b98 | 4c | Starts a cutscene screen shake
 * 
 * @param shakeInfo Screen shake start info
 * @param bg Affected background
 */
void CutsceneStartScreenShake(struct CutsceneScreenShakeInfo shakeInfo, u16 bg)
{
    struct CutsceneScreenShake* pShake;

    if (shakeInfo.type == 0)
    {
        pShake = &CUTSCENE_DATA.horizontalScreenShake;
        pShake->bg = bg;
        pShake->delay = 0;

        pShake->maxDelay = shakeInfo.maxDelay;
        pShake->set = shakeInfo.set;
        pShake->currentSubSet = 0;
    }
    else if (shakeInfo.type == 1)
    {
        pShake = &CUTSCENE_DATA.verticalScreenShake;
        pShake->bg = bg;
        pShake->delay = 0;

        pShake->maxDelay = shakeInfo.maxDelay;
        pShake->set = shakeInfo.set;
        pShake->currentSubSet = 0;
    }
}

/**
 * @brief 61be4 | 184 | Updates the cutscene special effect
 * 
 */
void CutsceneUpdateSpecialEffect(void)
{
    // Check any effect active
    if (!(CUTSCENE_DATA.specialEffect.status & (CUTSCENE_SPECIAL_EFFECT_STATUS_ON_BG | CUTSCENE_SPECIAL_EFFECT_STATUS_ON_SPRITE)))
        return;

    // Check update sprite effect
    if (CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_ON_SPRITE)
    {
        // Update timer
        if (CUTSCENE_DATA.specialEffect.s_Timer > 0)
        {
            CUTSCENE_DATA.specialEffect.s_Timer--;
            return;
        }

        // Reset timer
        CUTSCENE_DATA.specialEffect.s_Timer = CUTSCENE_DATA.specialEffect.s_Interval;

        // Update BLDY
        if (gWrittenToBLDY_NonGameplay != CUTSCENE_DATA.specialEffect.s_WrittenToBLDY)
        {
            if (gWrittenToBLDY_NonGameplay < CUTSCENE_DATA.specialEffect.s_WrittenToBLDY)
            {
                if (gWrittenToBLDY_NonGameplay + CUTSCENE_DATA.specialEffect.s_Intensity > CUTSCENE_DATA.specialEffect.s_WrittenToBLDY)
                    gWrittenToBLDY_NonGameplay = CUTSCENE_DATA.specialEffect.s_WrittenToBLDY;
                else
                    gWrittenToBLDY_NonGameplay += CUTSCENE_DATA.specialEffect.s_Intensity;
            }
            else
            {
                if (gWrittenToBLDY_NonGameplay - CUTSCENE_DATA.specialEffect.s_Intensity < CUTSCENE_DATA.specialEffect.s_WrittenToBLDY)
                    gWrittenToBLDY_NonGameplay = CUTSCENE_DATA.specialEffect.s_WrittenToBLDY;
                else
                    gWrittenToBLDY_NonGameplay -= CUTSCENE_DATA.specialEffect.s_Intensity;
            }
        }

        // Check reached destination value
        if (gWrittenToBLDY_NonGameplay != CUTSCENE_DATA.specialEffect.s_WrittenToBLDY)
            return;

        // Mark effect as ended
        CUTSCENE_DATA.specialEffect.status &= ~CUTSCENE_SPECIAL_EFFECT_STATUS_ON_SPRITE;
        CUTSCENE_DATA.specialEffect.status |= CUTSCENE_SPECIAL_EFFECT_STATUS_SPRITE_ENDED;

        if (CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_ON_BG)
            CUTSCENE_DATA.bldcnt = CUTSCENE_DATA.specialEffect.bg_WrittenToBLDCNT;
    }
    else
    {
        // Upate timer
        if (CUTSCENE_DATA.specialEffect.bg_Timer > 0)
        {
            CUTSCENE_DATA.specialEffect.bg_Timer--;
            return;
        }

        // Reset timer
        CUTSCENE_DATA.specialEffect.bg_Timer = CUTSCENE_DATA.specialEffect.bg_Interval;

        // Update BLDALPHA L
        if (gWrittenToBLDALPHA_L != CUTSCENE_DATA.specialEffect.bg_WrittenToBldalpha_L)
        {
            if (gWrittenToBLDALPHA_L < CUTSCENE_DATA.specialEffect.bg_WrittenToBldalpha_L)
            {
                if (gWrittenToBLDALPHA_L + CUTSCENE_DATA.specialEffect.bg_Intensity > CUTSCENE_DATA.specialEffect.bg_WrittenToBldalpha_L)
                    gWrittenToBLDALPHA_L = CUTSCENE_DATA.specialEffect.bg_WrittenToBldalpha_L;
                else
                    gWrittenToBLDALPHA_L += CUTSCENE_DATA.specialEffect.bg_Intensity;
            }
            else
            {
                if (gWrittenToBLDALPHA_L - CUTSCENE_DATA.specialEffect.bg_Intensity < CUTSCENE_DATA.specialEffect.bg_WrittenToBldalpha_L)
                    gWrittenToBLDALPHA_L = CUTSCENE_DATA.specialEffect.bg_WrittenToBldalpha_L;
                else
                    gWrittenToBLDALPHA_L -= CUTSCENE_DATA.specialEffect.bg_Intensity;
            }
        }

        // Update BLDALPHA H
        if (gWrittenToBLDALPHA_H != CUTSCENE_DATA.specialEffect.bg_WrittenToBldalpha_H)
        {
            if (gWrittenToBLDALPHA_H < CUTSCENE_DATA.specialEffect.bg_WrittenToBldalpha_H)
            {
                if (gWrittenToBLDALPHA_H + CUTSCENE_DATA.specialEffect.bg_Intensity > CUTSCENE_DATA.specialEffect.bg_WrittenToBldalpha_H)
                    gWrittenToBLDALPHA_H = CUTSCENE_DATA.specialEffect.bg_WrittenToBldalpha_H;
                else
                    gWrittenToBLDALPHA_H += CUTSCENE_DATA.specialEffect.bg_Intensity;
            }
            else
            {
                if (gWrittenToBLDALPHA_H - CUTSCENE_DATA.specialEffect.bg_Intensity < CUTSCENE_DATA.specialEffect.bg_WrittenToBldalpha_H)
                    gWrittenToBLDALPHA_H = CUTSCENE_DATA.specialEffect.bg_WrittenToBldalpha_H;
                else
                    gWrittenToBLDALPHA_H -= CUTSCENE_DATA.specialEffect.bg_Intensity;
            }
        }

        // Check reached destination values
        if (gWrittenToBLDALPHA_L != CUTSCENE_DATA.specialEffect.bg_WrittenToBldalpha_L)
            return;

        if (gWrittenToBLDALPHA_H != CUTSCENE_DATA.specialEffect.bg_WrittenToBldalpha_H)
            return;

        // Mark as ended
        CUTSCENE_DATA.specialEffect.status &= ~CUTSCENE_SPECIAL_EFFECT_STATUS_ON_BG;
        CUTSCENE_DATA.specialEffect.status |= CUTSCENE_SPECIAL_EFFECT_STATUS_BG_ENDED;
    }
}

/**
 * @brief 61d68 | 60 | Starts a cutscene sprite effect
 * 
 * @param bldcnt Bldcnt
 * @param bldy Bldy target
 * @param interval Interval between value changes
 * @param intensity Value change intensity
 */
void CutsceneStartSpriteEffect(u16 bldcnt, u8 bldy, u32 interval, u8 intensity)
{
    u8 _interval;

    CUTSCENE_DATA.specialEffect.status &= ~CUTSCENE_SPECIAL_EFFECT_STATUS_SPRITE_ENDED;
    CUTSCENE_DATA.specialEffect.status |= CUTSCENE_SPECIAL_EFFECT_STATUS_ON_SPRITE;

    CUTSCENE_DATA.specialEffect.s_WrittenToBLDY = bldy;
    CUTSCENE_DATA.specialEffect.s_Intensity = intensity;

    if (CUTSCENE_DATA.specialEffect.s_Interval)
    {
    }

    _interval = interval;
    CUTSCENE_DATA.specialEffect.s_Interval = _interval;
    CUTSCENE_DATA.specialEffect.s_Timer = _interval;

    CUTSCENE_DATA.bldcnt = CUTSCENE_DATA.specialEffect.s_Bldcnt = bldcnt;
}

/**
 * @brief 61dc8 | 70 | Starts a cutscene background effect
 * 
 * @param bldcnt Bldcnt
 * @param bldalphaL Bldqlphq L target
 * @param bldalphaH Bldqlphq H target
 * @param interval Interval between value changes
 * @param intensity Value change intensity
 */
void CutsceneStartBackgroundEffect(u16 bldcnt, u8 bldalphaL, u8 bldalphaH, u32 interval, u8 intensity)
{
    u8 _interval;

    CUTSCENE_DATA.specialEffect.status &= ~CUTSCENE_SPECIAL_EFFECT_STATUS_BG_ENDED;
    CUTSCENE_DATA.specialEffect.status |= CUTSCENE_SPECIAL_EFFECT_STATUS_ON_BG;
    
    CUTSCENE_DATA.specialEffect.bg_WrittenToBldalpha_L = bldalphaL;
    CUTSCENE_DATA.specialEffect.bg_WrittenToBldalpha_H = bldalphaH;
    CUTSCENE_DATA.specialEffect.bg_Intensity = intensity;

    if (CUTSCENE_DATA.specialEffect.bg_Interval)
    {
    }
    
    _interval = interval;
    CUTSCENE_DATA.specialEffect.bg_Interval = _interval;
    CUTSCENE_DATA.specialEffect.bg_Timer = _interval;

    CUTSCENE_DATA.specialEffect.bg_WrittenToBLDCNT = bldcnt;

    if (!(CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_ON_SPRITE))
        CUTSCENE_DATA.bldcnt = bldcnt;
}

/**
 * @brief 61e38 | d4 | Resets the data for a cutscene
 * 
 */
void CutsceneReset(void)
{
    s32 i;

    gWrittenToBLDY_NonGameplay = 0;
    gWrittenToBLDALPHA_L = 16;
    gWrittenToBLDALPHA_H = 0;

    // Clear special effect
    CUTSCENE_DATA.specialEffect.status = 0;
    CUTSCENE_DATA.bldcnt = 0;

    // Clear OAM
    for (i = 0; i < ARRAY_SIZE(CUTSCENE_DATA.oam); i++)
        CUTSCENE_DATA.oam[i] = sCutsceneOam_Empty;

    // Set default rotation and scaling
    gCurrentOamRotation = 0;
    gCurrentOamScaling = Q_8_8(1.f);

    // Clear structs
    BitFill(3, 0, &CUTSCENE_DATA.unk_8, sizeof(CUTSCENE_DATA.unk_8), 32);
    BitFill(3, 0, CUTSCENE_DATA.graphicsData, sizeof(CUTSCENE_DATA.graphicsData), 32);
    BitFill(3, 0, CUTSCENE_DATA.bgScrolling, sizeof(CUTSCENE_DATA.bgScrolling), 32);
    BitFill(3, 0, CUTSCENE_DATA.paletteData, sizeof(CUTSCENE_DATA.paletteData), 32);
}

/**
 * @brief 61f0c | 1c | To document
 * 
 */
void unk_61f0c(void)
{
    CUTSCENE_DATA.dispcnt = 0;
    gWrittenToBLDY_NonGameplay = BLDY_MAX_VALUE;
    CUTSCENE_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;
}

/**
 * @brief 61f28 | 1c | To document
 * 
 */
void unk_61f28(void)
{
    CUTSCENE_DATA.dispcnt = 0;
    gWrittenToBLDY_NonGameplay = 16;
    CUTSCENE_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;
}

/**
 * @brief 61f44 | 40 | To document
 * 
 * @return u32 
 */
u32 unk_61f44(void)
{
    unk_61f60();
    if (CutsceneUpdateFading())
        return TRUE;

    return FALSE;
}

/**
 * @brief 61f60 | 40 | To document
 * 
 */
void unk_61f60(void)
{
    if (CUTSCENE_DATA.unk_BC)
    {
        DmaTransfer(3, (void*)sEwramPointer + 0x400, PALRAM_BASE, 0x400, 0x10);
        CUTSCENE_DATA.unk_BC = FALSE;
    }
}

/**
 * @brief 61fa0 | 230 | Starts a cutscene background fading
 * 
 * @param type Type
 * @return u8 To document
 */
u8 CutsceneStartBackgroundFading(u8 type)
{
    u8 result;

    result = FALSE;

    CUTSCENE_DATA.fadingColor = 0;
    CUTSCENE_DATA.unk_BC = FALSE;
    CUTSCENE_DATA.unk_B8 = 0;

    DmaTransfer(3, PALRAM_BASE, (void*)sEwramPointer, PALRAM_SIZE, 16);

    switch (type)
    {
        case 1:
            BitFill(3, 0, PALRAM_BASE, PALRAM_SIZE, 16);
            DmaTransfer(3, PALRAM_BASE, (void*)sEwramPointer + PALRAM_SIZE, PALRAM_SIZE, 16);

            CUTSCENE_DATA.fadingStage = 0;
            CUTSCENE_DATA.fadingIntensity = 2;
            CUTSCENE_DATA.unk_BE = 0;
            CUTSCENE_DATA.fadingType = FADING_TYPE_IN;
            break;

        case 2:
            BitFill(3, 0, PALRAM_BASE, PALRAM_SIZE, 16);
            DmaTransfer(3, PALRAM_BASE, (void*)sEwramPointer + PALRAM_SIZE, PALRAM_SIZE, 16);

            CUTSCENE_DATA.fadingStage = 0;
            CUTSCENE_DATA.fadingIntensity = 1;
            CUTSCENE_DATA.unk_BE = 4;
            CUTSCENE_DATA.fadingType = FADING_TYPE_IN;
            break;

        case 3:
            BitFill(3, 0, PALRAM_BASE, PALRAM_SIZE, 16);
            DmaTransfer(3, PALRAM_BASE, (void*)sEwramPointer + PALRAM_SIZE, PALRAM_SIZE, 16);

            CUTSCENE_DATA.fadingStage = 0;
            CUTSCENE_DATA.fadingIntensity = 1;
            CUTSCENE_DATA.unk_BE = 8;
            CUTSCENE_DATA.fadingType = FADING_TYPE_IN;
            break;

        case 5:
            FadeMusic(20);

        case 6:
            CUTSCENE_DATA.fadingStage = 2;
            CUTSCENE_DATA.fadingIntensity = 2;
            CUTSCENE_DATA.unk_BE = 0;
            CUTSCENE_DATA.fadingType = FADING_TYPE_OUT;
            break;

        case 7:
            CUTSCENE_DATA.fadingStage = 2;
            CUTSCENE_DATA.fadingIntensity = 1;
            CUTSCENE_DATA.unk_BE = 4;
            CUTSCENE_DATA.fadingType = FADING_TYPE_OUT;
            break;

        case 8:
            CUTSCENE_DATA.fadingStage = 2;
            CUTSCENE_DATA.fadingIntensity = 8;
            CUTSCENE_DATA.unk_BE = 0;
            CUTSCENE_DATA.fadingType = FADING_TYPE_OUT;
            break;

        case 9:
            CUTSCENE_DATA.fadingStage = 2;
            CUTSCENE_DATA.fadingIntensity = 2;
            CUTSCENE_DATA.unk_BE = 0;
            CUTSCENE_DATA.fadingType = FADING_TYPE_UNK;
            break;

        case 10:
            CUTSCENE_DATA.fadingStage = 2;
            CUTSCENE_DATA.fadingIntensity = 1;
            CUTSCENE_DATA.unk_BE = 4;
            CUTSCENE_DATA.fadingType = FADING_TYPE_UNK;
            break;

        default:
            result = TRUE;
    }

    return result;
}

/**
 * @brief 621d0 | 23c | Updates a cutscene fading
 * 
 * @return u8 bool, ended
 */
u8 CutsceneUpdateFading(void)
{
    u16* src;
    u16* dst;
    u8 ended;

    ended = FALSE;
    CUTSCENE_DATA.unk_B8++;

    switch (CUTSCENE_DATA.fadingStage)
    {
        case 0:
            if (CUTSCENE_DATA.unk_BC)
                break;

            if (CUTSCENE_DATA.unk_B8 < CUTSCENE_DATA.unk_BE)
                break;

            if (CUTSCENE_DATA.fadingColor < 32)
            {
                src = (void*)sEwramPointer;
                dst = (void*)sEwramPointer + PALRAM_SIZE;
                ApplySpecialBackgroundFadingColor(CUTSCENE_DATA.fadingType, CUTSCENE_DATA.fadingColor, &src, &dst, USHORT_MAX);

                src = (void*)sEwramPointer + PALRAM_SIZE / 2;
                dst = (void*)sEwramPointer + PALRAM_SIZE + PALRAM_SIZE / 2;
                ApplySpecialBackgroundFadingColor(CUTSCENE_DATA.fadingType, CUTSCENE_DATA.fadingColor, &src, &dst, USHORT_MAX);

                CUTSCENE_DATA.unk_BC = TRUE;

                if (CUTSCENE_DATA.fadingColor == 31)
                {
                    CUTSCENE_DATA.fadingColor++;
                    break;
                }
                
                if (CUTSCENE_DATA.fadingColor + CUTSCENE_DATA.fadingIntensity > 31)
                    CUTSCENE_DATA.fadingColor = 31;
                else
                    CUTSCENE_DATA.fadingColor += CUTSCENE_DATA.fadingIntensity;
            }
            else
            {
                DmaTransfer(3, (void*)sEwramPointer, (void*)sEwramPointer + PALRAM_SIZE, PALRAM_SIZE, 16);
                CUTSCENE_DATA.unk_BC = TRUE;
                CUTSCENE_DATA.fadingStage++;
            }
            break;

        case 1:
            if (!CUTSCENE_DATA.unk_BC)
            {
                CUTSCENE_DATA.fadingColor = 0;
                CUTSCENE_DATA.fadingStage = 0;
                ended = TRUE;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.unk_BC)
                break;

            if (CUTSCENE_DATA.unk_B8 < CUTSCENE_DATA.unk_BE)
                break;

            CUTSCENE_DATA.unk_B8 = 0;
            if (CUTSCENE_DATA.fadingColor < 32)
            {
                src = (void*)sEwramPointer;
                dst = (void*)sEwramPointer + PALRAM_SIZE;
                ApplySpecialBackgroundFadingColor(CUTSCENE_DATA.fadingType, CUTSCENE_DATA.fadingColor, &src, &dst, USHORT_MAX);

                src = (void*)sEwramPointer + PALRAM_SIZE / 2;
                dst = (void*)sEwramPointer + PALRAM_SIZE + PALRAM_SIZE / 2;
                ApplySpecialBackgroundFadingColor(CUTSCENE_DATA.fadingType, CUTSCENE_DATA.fadingColor, &src, &dst, USHORT_MAX);

                CUTSCENE_DATA.unk_BC = TRUE;

                if (CUTSCENE_DATA.fadingColor == 31)
                {
                    CUTSCENE_DATA.fadingColor++;
                    break;
                }
                
                if (CUTSCENE_DATA.fadingColor + CUTSCENE_DATA.fadingIntensity > 31)
                    CUTSCENE_DATA.fadingColor = 31;
                else
                    CUTSCENE_DATA.fadingColor += CUTSCENE_DATA.fadingIntensity;
            }
            else
            {
                if (CUTSCENE_DATA.fadingType == 3)
                    BitFill(3, COLOR_WHITE, (void*)sEwramPointer + PALRAM_SIZE, PALRAM_SIZE, 16);
                else                
                    BitFill(3, COLOR_BLACK, (void*)sEwramPointer + PALRAM_SIZE, PALRAM_SIZE, 16);

                CUTSCENE_DATA.unk_BC = TRUE;
                CUTSCENE_DATA.fadingStage = 3;
            }
            break;

        case 3:
            if (!CUTSCENE_DATA.unk_BC)
            {
                CUTSCENE_DATA.fadingColor = 0;
                CUTSCENE_DATA.fadingStage = 0;
                ended = TRUE;
            }
            break;
    }

    return ended;
}
