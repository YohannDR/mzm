#include "gba.h"
#include "oam.h"
#include "cutscenes/cutscene_utils.h"

#include "data/cutscenes/cutscenes_data.h"
#include "data/shortcut_pointers.h"

#include "constants/audio.h"
#include "constants/connection.h"
#include "constants/cutscene.h"
#include "constants/event.h"
#include "constants/game_state.h"

#include "structs/audio.h"
#include "structs/cutscene.h"
#include "structs/connection.h"
#include "structs/display.h"
#include "structs/game_state.h"

/**
 * @brief 60e28 | 4 | Default subroutine for Cutscene that don't have any
 * 
 * @return u8 1
 */
u8 CutsceneDefaultRoutine(void)
{
    return TRUE;
}

u8 TourianEscapeSubroutine(void)
{

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
            SoundPlay(0x24C);
    }

    SoundFade(10);
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
                SoundStop(0x1C);
                unk_3bd0(MUSIC_KRAID_BATTLE_WITH_INTRO, 0x3C);
            }
            else if (gCurrentArea == AREA_RIDLEY)
            {
                SoundStop(0x1C);
                unk_3bd0(MUSIC_RIDLEY_BATTLE, 0x3C);
            }
    }

    start_special_background_fading(sCutsceneData[gCurrentCutscene].bgFading);
    if (sCutsceneData[gCurrentCutscene].event != EVENT_NONE)
        EventFunction(EVENT_ACTION_SETTING, sCutsceneData[gCurrentCutscene].event);

    if (sCutsceneData[gCurrentCutscene].isElevator)
    {
        play_fading_sound(0x10E, sCutsceneData[gCurrentCutscene].fadingTimer);
        check_play_fading_music(gMusicTrackInfo.currentRoomTrack, sCutsceneData[gCurrentCutscene].fadingTimer, 0);
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
            if (unk_61fa0(sCutsceneData[gCurrentCutscene].unk_8))
                gSubGameModeStage = 2;
            else
                gSubGameModeStage = 1;
            break;

        case 1:
            unk_61f60();
            if (unk_621d0())
                gSubGameModeStage++;
            break;
            
        case 2:
            CutsceneInit();
            CallbackSetVBlank(CutsceneVBlank);

            gSubGameModeStage++;
            break;
            
        case 3:
            CUTSCENE_DATA.timer++;
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
            if (CUTSCENE_DATA.unk_BF == 3)
                BitFill(3, SHORT_MAX, PALRAM_BASE, PALRAM_SIZE, 0x10);
            else
                BitFill(3, 0, PALRAM_BASE, PALRAM_SIZE, 0x10);

            BitFill(3, 0x40, VRAM_BASE, 0x10000, 0x10);
            BitFill(3, 0, VRAM_BASE + 0x10000, 0x8000, 0x10);
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
    dma_set(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | 0x100);

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
    i32 unk;

    CallbackSetVBlank(CutsceneLoadingVBlank);
    BitFill(3, 0, &gNonGameplayRAM, sizeof(union NonGameplayRAM), 0x20);

    sOamXOffset_NonGameplay = sOamYOffset_NonGameplay = 0;
    gNextOamSlot = 0;
    ResetFreeOAM();

    write16(REG_BLDCNT, CUTSCENE_DATA.bldcnt = 0xFF);

    write16(REG_BLDY, gWrittenToBLDY = 0x10);

    write16(REG_DISPCNT, CUTSCENE_DATA.dispcnt = 0);

    unk = sCutsceneData[gCurrentCutscene].unk_0;
    if (unk != 0)
    {
        if (unk == 2)
            gPauseScreenFlag = PAUSE_SCREEN_PAUSE_OR_CUTSCENE;

        if (unk < 3)
            DMATransfer(3, VRAM_BASE + 0x10000, EWRAM_BASE + 0x1E000, unk * 0x4000, 0x10);
    }

    if (gCutsceneToSkip != gCurrentCutscene)
        gCurrentCutscene = CUTSCENE_NONE;

    ClearGFXRAM();

    gBG0HOFS_NonGameplay = gBG0VOFS_NonGameplay = 0x800;
    gBG1HOFS_NonGameplay = gBG1VOFS_NonGameplay = 0x800;
    gBG2HOFS_NonGameplay = gBG2VOFS_NonGameplay = 0x800;
    gBG3HOFS_NonGameplay = gBG3VOFS_NonGameplay= 0x800;

    CUTSCENE_DATA.stage = 0;
    CUTSCENE_DATA.timer = 0;
    sCutsceneData[gCurrentCutscene].pFunction();
}

/**
 * @brief 6141c | 58 | Sets up a BGCNT IO register with the page data info
 * 
 * @param pageData Page Data Info
 */
void CutsceneSetBGCNTPageData(struct CutscenePageData pageData)
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

    CUTSCENE_DATA.bgcnt[offset] = pageData.unk_6 | pageData.priority | (pageData.tiletablePage << 8) | (pageData.graphicsPage << 2);
}

/**
 * @brief 61484 | 50 | Changes the BGCNT value of a specified background
 * 
 * @param value Value
 * @param bg Background (DISPCNT flags)
 */
void CutsceneSetBGCNT(u16 value, u16 bg)
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
            gBG0HOFS_NonGameplay = value;
        else if (bg == DCNT_BG1)
            gBG1HOFS_NonGameplay = value;
        else if (bg == DCNT_BG2)
            gBG2HOFS_NonGameplay = value;
        else if (bg == DCNT_BG3)
            gBG3HOFS_NonGameplay = value;
    }

    if (type & CUTSCENE_BG_EDIT_VOFS)
    {
        if (bg == DCNT_BG0)
            gBG0VOFS_NonGameplay = value;
        else if (bg == DCNT_BG1)
            gBG1VOFS_NonGameplay = value;
        else if (bg == DCNT_BG2)
            gBG2VOFS_NonGameplay = value;
        else if (bg == DCNT_BG3)
            gBG3VOFS_NonGameplay = value;
    }
}

/**
 * @brief 61578 | 50 | Gets the pointer to the HOFS (X) value of a specified background
 * 
 * @param bg Background (DISPCNT flags)
 * @return u16* Pointer
 */
u16* CutsceneGetBGHOFSPointer(u16 bg)
{
    u16* pBg;

    pBg = NULL;
    if (bg == DCNT_BG0)
        pBg = &gBG0HOFS_NonGameplay;
    else if (bg == DCNT_BG1)
        pBg = &gBG1HOFS_NonGameplay;
    else if (bg == DCNT_BG2)
        pBg = &gBG2HOFS_NonGameplay;
    else if (bg == DCNT_BG3)
        pBg = &gBG3HOFS_NonGameplay;

    return pBg;
}

/**
 * @brief 615c8 | 50 | Gets the pointer to the VOFS (Y) value of a specified background
 * 
 * @param bg Background (DISPCNT flags)
 * @return u16* Pointer
 */
u16* CutsceneGetBGVOFSPointer(u16 bg)
{
    u16* pBg;

    pBg = NULL;
    if (bg == DCNT_BG0)
        pBg = &gBG0VOFS_NonGameplay;
    else if (bg == DCNT_BG1)
        pBg = &gBG1VOFS_NonGameplay;
    else if (bg == DCNT_BG2)
        pBg = &gBG2VOFS_NonGameplay;
    else if (bg == DCNT_BG3)
        pBg = &gBG3VOFS_NonGameplay;

    return pBg;
}

void CutsceneStartBackgroundScrolling(struct CutsceneScrollingInfo scrollingData, u16 bg)
{

}

/**
 * @brief 618d8 | 6c | Updates a cutscene background scrolling
 * 
 * @param pScrolling Cutscene Scrolling Data Pointer
 */
void CutsceneUpdateBackgroundScrolling(struct CutsceneScrolling* pScrolling)
{
    i32 offset;

    if (pScrolling->unk_4 != 0)
    {
        if (pScrolling->unk_6 > 0)
            pScrolling->unk_6--;
        else
        {
            pScrolling->unk_6 = pScrolling->unk_8;
            if (pScrolling->unk_7 >= 0)
            {
                if (pScrolling->unk_4 < pScrolling->unk_7)
                    offset = FALSE;
                else
                    offset = TRUE;
            }
            else
            {
                if (pScrolling->unk_4 > pScrolling->unk_7)
                    offset = FALSE;
                else
                    offset = TRUE;
            }

            if (offset)
            {
                offset = pScrolling->unk_7;    
                pScrolling->unk_4 -= offset;
            }
            else
            {
                offset = pScrolling->unk_4;
                pScrolling->unk_4 = 0;
            }


            (*pScrolling->pPosition) += offset;
        }
        
    }

    if (pScrolling->unk_4 == 0)
        pScrolling->pPosition = NULL;
}

/**
 * @brief 61944 | 80 | Checks if a background scrolling is active
 * 
 * @param bg 
 * @return u8 
 */
u8 CutsceneCheckBackgroundScrollingActive(u16 bg)
{
    i32 offset;    
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

        offset = (i8)(offset + 1);
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
    i32 i;

    if (updateScrolling & TRUE)
    {
        for (i = 0; i < ARRAY_SIZE(CUTSCENE_DATA.bgScrolling); i++)
        {
            if (CUTSCENE_DATA.bgScrolling[i].pPosition != NULL)
                CutsceneUpdateBackgroundScrolling(CUTSCENE_DATA.bgScrolling + i);
        }
    }

    CUTSCENE_DATA.bg0hofs = gBG0HOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg0vofs = gBG0VOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg1hofs = gBG1HOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg1vofs = gBG1VOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg2hofs = gBG2HOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg2vofs = gBG2VOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg3hofs = gBG3HOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg3vofs = gBG3VOFS_NonGameplay / 4;

    if (CUTSCENE_DATA.horizontalScreenShake.bg != 0)
        CutsceneUpdateScreenShake(FALSE, &CUTSCENE_DATA.horizontalScreenShake);

    if (CUTSCENE_DATA.verticalScreenShake.bg != 0)
        CutsceneUpdateScreenShake(TRUE, &CUTSCENE_DATA.verticalScreenShake);
}

void CutsceneUpdateScreenShake(u8 affectVertical, struct CutsceneScreenShake* pShake)
{

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
        pShake->loopCounter = 0;

        pShake->unk_3 = shakeInfo.unk_1;
        pShake->unk_4 = shakeInfo.unk_2;
        pShake->unk_5 = 0;
    }
    else if (shakeInfo.type == 1)
    {
        pShake = &CUTSCENE_DATA.verticalScreenShake;
        pShake->bg = bg;
        pShake->loopCounter = 0;

        pShake->unk_3 = shakeInfo.unk_1;
        pShake->unk_4 = shakeInfo.unk_2;
        pShake->unk_5 = 0;
    }
}

void CutsceneUpdateSpecialEffect(void)
{

}

void CutsceneStartSpriteEffect(u16 bldcnt, u8 bldy, u8 interval, u8 intensity)
{
    // https://decomp.me/scratch/2WAha

    CUTSCENE_DATA.specialEffect.status &= ~CUTSCENE_SPECIAL_EFFECT_STATUS_SPRITE_ENDED;
    CUTSCENE_DATA.specialEffect.status |= CUTSCENE_SPECIAL_EFFECT_STATUS_ON_SPRITE;

    CUTSCENE_DATA.specialEffect.s_WrittenToBLDY = bldy;
    CUTSCENE_DATA.specialEffect.s_Intensity = intensity;
    CUTSCENE_DATA.specialEffect.s_Interval = interval;
    CUTSCENE_DATA.specialEffect.s_Timer = interval;

    CUTSCENE_DATA.specialEffect.s_BLDCNT = bldcnt;
    CUTSCENE_DATA.bldcnt = bldcnt;
}

void CutsceneStartBackgroundEffect(u16 bldcnt, u8 bldalphaL, u8 bldalphaH, u8 interval, u8 intensity)
{

}

void CutsceneReset(void)
{

}

void unk_61f0c(void)
{

}

void unk_61f28(void)
{

}

u32 unk_61f44(void)
{

}

void unk_61f60(void)
{

}

u8 unk_61fa0(u8 param_1)
{

}

u8 unk_621d0(void)
{

}
