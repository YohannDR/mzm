#include "in_game_cutscene.h"
#include "sprites_AI/ruins_test.h"
#include "gba.h"

#include "data/in_game_cutscene_data.h"
#include "data/samus_close_up_data.h"

#include "constants/audio.h"
#include "constants/animated_graphics.h"
#include "constants/room.h"
#include "constants/color_fading.h"
#include "constants/menus/pause_screen.h"
#include "constants/samus.h"
#include "constants/in_game_cutscene.h"

#include "structs/display.h"
#include "structs/hud.h"
#include "structs/save_file.h"
#include "structs/game_state.h"
#include "structs/power_bomb_explosion.h"
#include "structs/in_game_cutscene.h"
#include "structs/sprite.h"
#include "structs/transparency.h"
#include "structs/samus.h"
#include "structs/room.h"
#include "structs/bg_clip.h"

/**
 * @brief 5f8f4 | 464 | Handles the samus close up cutscene
 * 
 * @param cutsceneNumber [Unused] Cutscene number
 * @param cutsceneNumberNoFlag [Unused] Cutscene number (no start flag)
 * @return u8 bool, ended
 */
u32 InGameCutsceneSamusCloseUp(u8 cutsceneNumber, u8 cutsceneNumberNoFlag)
{
    u32 result;

    result = FALSE;
    switch (gInGameCutscene.stage)
    {
        case 0:
            if (gInGameCutscene.timer != 0)
            {
                result = TRUE;
                InGameCutsceneCheckFlag(TRUE, IGC_CLOSE_UP);
            }
            break;

        case 1:
            TransparencyUpdateBLDALPHA(16, 0, 7, 1);
            result = 1;
            break;

        case 2:
            if (gIoRegistersBackup.BLDALPHA_NonGameplay_EVA == 16 && gIoRegistersBackup.BLDALPHA_NonGameplay_EVB == 0)
                result = TRUE;
            break;

        case 5:
        case 7:
            if (gInGameCutscene.timer > 2)
                result = TRUE;
            break;

        case 3:
        case 9:
            if (gInGameCutscene.timer > 102)
                result = TRUE;
            break;

        case 4:
            DMATransfer(3, &sSamusCloseUpEyesGFX_1[0], VRAM_BASE + 0xB940, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B000, VRAM_BASE + 0x294, 0x14, 16);

            DMATransfer(3, &sSamusCloseUpEyesGFX_1[256], VRAM_BASE + 0xBD40, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B040, VRAM_BASE + 0x2D4, 0x14, 16);

            DMATransfer(3, &sSamusCloseUpEyesGFX_1[512], VRAM_BASE + 0xC140, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B080, VRAM_BASE + 0x314, 0x14, 16);

            DMATransfer(3, &sSamusCloseUpEyesGFX_1[768], VRAM_BASE + 0xC540, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B0C0, VRAM_BASE + 0x354, 0x14, 16);

            DMATransfer(3, &sSamusCloseUpEyesGFX_1[1024], VRAM_BASE + 0xC940, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B100, VRAM_BASE + 0x394, 0x14, 16);

          
            DMATransfer(3, &sSamusCloseUpEyesGFX_1[1280], VRAM_BASE + 0xCD40, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B140, VRAM_BASE + 0x3D4, 0x14, 16);
            result = 1;
            break;

        case 6:
            DMATransfer(3, &sSamusCloseUpEyesGFX_2[0], VRAM_BASE + 0xB940, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B014, VRAM_BASE + 0x294, 0x14, 16);

            DMATransfer(3, &sSamusCloseUpEyesGFX_2[256], VRAM_BASE + 0xBD40, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B014, VRAM_BASE + 0x294, 0x14, 16);

            DMATransfer(3, &sSamusCloseUpEyesGFX_2[512], VRAM_BASE + 0xC140, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B094, VRAM_BASE + 0x314, 0x14, 16);

            DMATransfer(3, &sSamusCloseUpEyesGFX_2[768], VRAM_BASE + 0xC540, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B0D4, VRAM_BASE + 0x354, 0x14, 16);

            DMATransfer(3, &sSamusCloseUpEyesGFX_2[1024], VRAM_BASE + 0xC940, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B114, VRAM_BASE + 0x394, 0x14, 16);


            DMATransfer(3, &sSamusCloseUpEyesGFX_2[1280], VRAM_BASE + 0xCD40, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B154, VRAM_BASE + 0x3D4, 0x14, 16);
            result = 1;
            break;

        case 8:
            DMATransfer(3, &sSamusCloseUpEyesGFX_3[0], VRAM_BASE + 0xB940, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B028, VRAM_BASE + 0x294, 0x14, 16);

            DMATransfer(3, &sSamusCloseUpEyesGFX_3[256], VRAM_BASE + 0xBD40, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B068, VRAM_BASE + 0x2D4, 0x14, 16);

            DMATransfer(3, &sSamusCloseUpEyesGFX_3[512], VRAM_BASE + 0xC140, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B0A8, VRAM_BASE + 0x314, 0x14, 16);

            DMATransfer(3, &sSamusCloseUpEyesGFX_3[768], VRAM_BASE + 0xC540, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B0E8, VRAM_BASE + 0x354, 0x14, 16);

            DMATransfer(3, &sSamusCloseUpEyesGFX_3[1024], VRAM_BASE + 0xC940, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B128, VRAM_BASE + 0x394, 0x14, 16);
            
            DMATransfer(3, &sSamusCloseUpEyesGFX_3[1280], VRAM_BASE + 0xCD40, 0x140, 16);
            DMATransfer(3, EWRAM_BASE + 0x2B168, VRAM_BASE + 0x3D4, 0x14, 16);
            result = 1;
            break;

        case 10:
            TransparencyUpdateBLDALPHA(0, 16, 0, 16);
            result = 1;
            break;

        case 11:
            if (gIoRegistersBackup.BLDALPHA_NonGameplay_EVA == 0 && gIoRegistersBackup.BLDALPHA_NonGameplay_EVB == 16)
            {
                gHideHud = FALSE;
                result = TRUE;
            }
            break;

        case 12:
            DMATransfer(3, EWRAM_BASE + 0x1E000, VRAM_BASE + 0x9000, 0x2000, 16);
            gSramOperationStage = 0;
            result = 1;
            break;

        case 13:
            if (SramProcessIntroSave())
            {
                SramWrite_Language();
                result = 1;
            }
            break;

        case 14:
            if (gPreventMovementTimer == 0)
            {
                InGameCutsceneCheckFlag(TRUE, IGC_CLOSE_UP);
                gPreventMovementTimer = 0;
                gDisablePause = FALSE;
                result = 5;
            }
            break;
    }

    return result;
}

/**
 * @brief 5fd58 | 74 | To document
 * 
 */
void unk_5fd58(void)
{
    i32 i;
    i32 j;
    u16* src;
    u16* dst;

    u16 value;

    src = EWRAM_BASE + 0x2AA94;
    dst = EWRAM_BASE + 0x2B000;

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 10; j++)
        {
            value = src[i * 0x20 + j] & 0xFFF;

            dst[i * 0x20 + j] = (dst[i * 0x20 + j] & 0xF000) | value;
            dst[i * 0x20 + j + 10] = (dst[i * 0x20 + j + 10] & 0xF000) | value;
            dst[i * 0x20 + j + 20] = (dst[i * 0x20 + j + 20] & 0xF000) | value;
        }
    }
}

/**
 * @brief 5fdcc | 5a8 | Handles the samus upgrading suit cutscene
 * 
 * @param cutsceneNumber [Unused] Cutscene number
 * @param cutsceneNumberNoFlag [Unused] Cutscene number (no start flag)
 * @return u8 bool, ended
 */
u32 InGameCutsceneUpgradingSuit(u8 cutsceneNumber, u8 cutsceneNumberNoFlag)
{
    i32 changeStage;
    u8 ended;

    i32 left;
    i32 right;
    i32 top;
    i32 bottom;

    u16 newValue;

    i32 temp;
    u32 result;
    u32 flag;
    
    u32 res_1;
    u32 res_2;

    i32 increment;

    ended = FALSE;
    changeStage = FALSE;

    temp = gSamusData.xPosition - gBG1XPosition;
    if (temp < 0)
        left = 0;
    else
    {
        if (temp > 0x3B8)
            left = 0xEE;
        else
            left = temp >> 2;
    }
    right = left + 2;

    bottom = gSamusData.yPosition - 0x60;
    temp = bottom - gBG1YPosition;
    if (temp < 0)
        top = 0;
    else
    {
        if (temp > 0x278)
            top = 0x9E;
        else
            top = temp >> 2;
    }
    bottom = top + 2;

    if (gSuitFlashEffect.timer != UCHAR_MAX)
        gSuitFlashEffect.timer++;

    switch (gInGameCutscene.stage)
    {
        case 0:
            // Check if the cutscene should start
            // Item is varia, or item is gravity and the starting flag in sub sprite data is set
            if (gCurrentItemBeingAcquired == ITEM_ACQUISITION_VARIA || (gCurrentItemBeingAcquired == ITEM_ACQUISITION_GRAVITY && 
                gSubSpriteData1.workVariable3 == RUINS_TEST_FIGHT_STAGE_STARTING_SUIT_ANIM))
            {
                changeStage = TRUE;   
            }
            break;

        case 1:
            gDefaultTransparency.unknown_0 = 1;
            gWrittenToBLDALPHA_H = gIoRegistersBackup.BLDALPHA_NonGameplay_EVB;
            gWrittenToBLDALPHA_L = gIoRegistersBackup.BLDALPHA_NonGameplay_EVA;
            changeStage = TRUE;
            break;

        case 2:
            if (gInGameCutscene.timer & 1)
                break;

            if (gWrittenToBLDALPHA_H != 16)
            {
                gWrittenToBLDALPHA_H++;
                if (gWrittenToBLDALPHA_H > 16)
                    gWrittenToBLDALPHA_H = 16;
            }
            else
                changeStage++;

            if (gWrittenToBLDALPHA_L != 0)
            {
                if (gWrittenToBLDALPHA_L - 1 < 0)
                    gWrittenToBLDALPHA_L = 0;
                else
                    gWrittenToBLDALPHA_L--;
            }
            else
                changeStage++;
           
            gWrittenToBLDALPHA = gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L;
            changeStage >>= 1;
            break;

        case 3:
            // Hide BG0, and backup its tilemap
            gWrittenToDISPCNT = gIoRegistersBackup.DISPCNT_NonGameplay & ~DCNT_BG0;
            dma_set(3, VRAM_BASE + 0x800, EWRAM_BASE + 0x1E000, DMA_ENABLE << 16 | 0x400);

            changeStage = TRUE;
            break;

        case 4:
            // Fill BG0 tilemap with tile 0xC0, palette 9 
            BitFill(3, (9 << 0xC) | 0xC0, VRAM_BASE + 0x800, 0x800, 16);
            write16(REG_BG0CNT, 0x104);

            changeStage = TRUE;
            break;

        case 5:
            changeStage = TRUE;
            break;

        case 6:
            changeStage = TRUE;
            break;

        case 7:
            gWrittenToDISPCNT = gIoRegistersBackup.DISPCNT_NonGameplay;
            gWrittenToWININ_H = 0x3F;
            gWrittenToWINOUT_L = 0x1E;
            gWrittenToBLDALPHA = 0x100D;
            gWrittenToBLDCNT = 0x3F41;

            gSuitFlashEffect.left = left;
            gSuitFlashEffect.right = right;
            gSuitFlashEffect.top = top;
            gSuitFlashEffect.bottom = bottom;
            gSuitFlashEffect.timer = 0x0;

            if (gCurrentItemBeingAcquired == ITEM_ACQUISITION_VARIA)
                SoundPlay(0x222); // Varia upgrade sound
            else if (gCurrentItemBeingAcquired == ITEM_ACQUISITION_GRAVITY)
                SoundPlay(0x223); // Gravity upgrade sound

            changeStage = TRUE;
            break;

        case 8:
            // Handle suit flash growing vertically
            increment = 4;
            if (gSuitFlashEffect.top != 0)
            {
                if (gSuitFlashEffect.top > increment)
                    gSuitFlashEffect.top -= increment;
                else
                    gSuitFlashEffect.top = 0;
            }
            else
                changeStage++;

            if (gSuitFlashEffect.bottom < 0xA0)
            {
                gSuitFlashEffect.bottom += increment; 
                
                if (gSuitFlashEffect.bottom > 0xA0)
                    gSuitFlashEffect.bottom = 0xA0;
            }
            else
                changeStage++;

            changeStage >>= 1;
            break;

        case 9:
            // Handle suit flash growing horizontally
            increment = 7;
            if (gSuitFlashEffect.left != 0)
            {
                if (gSuitFlashEffect.left > increment)
                    gSuitFlashEffect.left -= increment;
                else
                    gSuitFlashEffect.left = 0;
            }
            else
                changeStage++;

            if (gSuitFlashEffect.right < 0xF0)
            {
                gSuitFlashEffect.right += increment; 
                
                if (gSuitFlashEffect.right > 0xF0)
                    gSuitFlashEffect.right = 0xF0;
            }
            else
                changeStage++;

            changeStage >>= 1;
            break;

        case 10:
            if (gInGameCutscene.timer > 5)
                changeStage = TRUE;
            break;

        case 11:
            // Set suit flag (updates graphics)
            if (gCurrentItemBeingAcquired == ITEM_ACQUISITION_VARIA)
                gEquipment.suitMiscActivation |= SMF_VARIA_SUIT;
            else if (gCurrentItemBeingAcquired == ITEM_ACQUISITION_GRAVITY)
                gEquipment.suitMiscActivation |= SMF_GRAVITY_SUIT;

            changeStage = TRUE;
            break;

        case 12:
            if (gInGameCutscene.timer > 5)
                changeStage = TRUE;
            break;

        case 13:
            // Handle suit flash shrinking vertically
            result = InGameCutsceneCalculateSuitFlashOffset(3, top - gSuitFlashEffect.top, gSuitFlashEffect.bottom - bottom);
            res_1 = result & 0xFF;
            res_2 = (result & 0xFF00) >> 8;
                
            if (gSuitFlashEffect.top < top)
            {
                gSuitFlashEffect.top += res_2;
                if (gSuitFlashEffect.top > top)
                    gSuitFlashEffect.top = top;
            }
            else
                changeStage++;

            if (gSuitFlashEffect.bottom > bottom)
            {
                gSuitFlashEffect.bottom -= res_1;
                if (gSuitFlashEffect.bottom < bottom)
                    gSuitFlashEffect.bottom = bottom;
            }
            else
                changeStage++;

            changeStage >>= 1;
            break;

        case 14:
            // Handle suit flash shrinking horizontally
            result = InGameCutsceneCalculateSuitFlashOffset(9, left - gSuitFlashEffect.left, gSuitFlashEffect.right - right);
            res_1 = result & 0xFF;
            res_2 = (result & 0xFF00) >> 8;

            if (gSuitFlashEffect.left < left)
            {
                gSuitFlashEffect.left += res_2;
                if (gSuitFlashEffect.left > left)
                    gSuitFlashEffect.left = left;
            }
            else
                changeStage++;

            if (gSuitFlashEffect.right > right)
            {
                gSuitFlashEffect.right -= res_1;
                if (gSuitFlashEffect.right < right)
                    gSuitFlashEffect.right = right;
            }
            else
                changeStage++;

            changeStage >>= 1;
            break;

        case 15:
            gWrittenToDISPCNT = gIoRegistersBackup.DISPCNT_NonGameplay & ~DCNT_BG0;
            gWrittenToWINOUT_L = gIoRegistersBackup.WINOUT_L;
            gWrittenToWININ_H = gIoRegistersBackup.WININ_H;
            gWrittenToBLDALPHA = gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L;
            gWrittenToBLDCNT = gIoRegistersBackup.BLDCNT_NonGameplay;

            gSuitFlashEffect.left = 0;
            gSuitFlashEffect.right = 0xF0;
            gSuitFlashEffect.top = 0;
            gSuitFlashEffect.bottom = 0xA0;

            changeStage = TRUE;
            break;

        case 16:
            // Put BG0 in the state it was before the cutscene
            dma_set(3, EWRAM_BASE + 0x1E000, VRAM_BASE + 0x800, DMA_ENABLE << 16 | 0x400);
            write16(REG_BG0CNT, gIoRegistersBackup.BG0CNT);

            changeStage = TRUE;
            break;

        case 17:
            gWrittenToDISPCNT = gIoRegistersBackup.DISPCNT_NonGameplay;
            changeStage = TRUE;
            break;

        case 18:
            if (gInGameCutscene.timer & 1)
                break;

            if (gWrittenToBLDALPHA_H != gIoRegistersBackup.BLDALPHA_NonGameplay_EVB)
            {
                if (gWrittenToBLDALPHA_H > gIoRegistersBackup.BLDALPHA_NonGameplay_EVB)
                    gWrittenToBLDALPHA_H--;
                else if (gWrittenToBLDALPHA_H < gIoRegistersBackup.BLDALPHA_NonGameplay_EVB)
                    gWrittenToBLDALPHA_H++;
            }
            else
                changeStage++;

            if (gWrittenToBLDALPHA_L != gIoRegistersBackup.BLDALPHA_NonGameplay_EVA)
            {
                if (gWrittenToBLDALPHA_L > gIoRegistersBackup.BLDALPHA_NonGameplay_EVA)
                    gWrittenToBLDALPHA_L--;
                else if (gWrittenToBLDALPHA_L < gIoRegistersBackup.BLDALPHA_NonGameplay_EVA)
                    gWrittenToBLDALPHA_L++;
            }
            else
                changeStage++;

            gWrittenToBLDALPHA = gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L;
            changeStage >>= 1;
            break;

        case 19:
            // Flag cutscene has ended
            if (gCurrentItemBeingAcquired == ITEM_ACQUISITION_GRAVITY)
                gSubSpriteData1.workVariable3 = RUINS_TEST_FIGHT_STAGE_SUIT_ANIM_ENDED;

            // Give control back to player
            gSamusData.lastWallTouchedMidAir = FALSE;
            gDisablePause = FALSE;
            gDefaultTransparency.unknown_0 = 0;

            // Since this cutscene never returns 5, this function is still called even after it ended
            // it's on stage 20 so technically nothing happens, but it's a weird oversight
            ended = TRUE;
    }

    if (changeStage)
    {
        gInGameCutscene.stage++;
        gInGameCutscene.timer = 0;
    }

    // Update window 1
    gWrittenToWIN1H = gSuitFlashEffect.left << 8 | gSuitFlashEffect.right;
    gWrittenToWIN1V = gSuitFlashEffect.top << 8 | gSuitFlashEffect.bottom;

    return ended;
}

/**
 * @brief 60374 | 50 | Calcultes the position offsets for the suit flash effect
 * 
 * @param intensity Intensity
 * @param start Start
 * @param end End
 * @return u16 New end | New start
 */
u16 InGameCutsceneCalculateSuitFlashOffset(u8 intensity, u8 start, u8 end)
{
    u8 newStart;
    u8 newEnd;

    newEnd = 0;
    newStart = 0;

    if (start > end)
    {
        if (end > start - intensity)
            newStart = end - (start - intensity);

        newEnd = intensity;
    }
    else if (start < end)
    {
        if (start > end - intensity)
            newEnd = start - (end - intensity);

        newStart = intensity;
    }
    else
    {
        newStart = intensity;
        newEnd = intensity;
    }

    return newEnd << 8 | newStart;
}

/**
 * @brief 603c4 | 58 | Start a background flash effect
 * 
 * @param type Type
 */
void MakeBackgroundFlash(u8 type)
{
    switch (type)
    {
        case BG_FLASH_SLIGHT_YELLOW:
            BackgroundEffectStart(BACKGROUND_EFFECT_SLIGHT_YELLOW);
            break;

        case BG_FLASH_HEAVY_YELLOW:
            BackgroundEffectStart(BACKGROUND_EFFECT_HEAVY_YELLOW);
            break;

        case BG_FLASH_CHOZO_LONG_TRANSPARENCY:
            TransparencyUpdateBLDALPHA(gDefaultTransparency.evaCoef, gDefaultTransparency.evbCoef, 2, 1);

            // Set cutscene flag
            InGameCutsceneCheckFlag(TRUE, IGC_LONG_BEAM_HINT);
            break;

        case BG_FLASH_QUICK_YELLOW:
            BackgroundEffectStart(BACKGROUND_EFFECT_QUICK_FLASH);
            break;
    }
}

/**
 * @brief 6041c | 18 | Starts an in game cutscene
 * 
 * @param number Cutscene number
 */
void InGameCutsceneStart(u8 number)
{
    if (gInGameCutscene.cutsceneNumber == 0)
        gInGameCutscene.cutsceneNumber = number;
}

/**
 * @brief 60434 | ac | Processes the current in game cutscene
 * 
 */
void InGameCutsceneProcess(void)
{
    u32 ended;
    u8 cutsceneNumber;

    gInGameCutscene.timer++;

    // Check has cutscene
    cutsceneNumber = gInGameCutscene.cutsceneNumber;
    if (cutsceneNumber == 0)
        return;

    // Check was init
    if (cutsceneNumber & IGC_STARTED_FLAG)
    {
        // Check has subroutine pointer, and check if has cutscene again (why?)
        if (gInGameCutscene.pSubroutine == NULL || !(cutsceneNumber & IGC_NO_STARTED_FLAG))
            return;

        // Execute subroutine
        ended = gInGameCutscene.pSubroutine(cutsceneNumber & IGC_NO_STARTED_FLAG, cutsceneNumber);

        if (ended)
            gInGameCutscene.timer = 0;

        // Weird
        switch (ended)
        {
            case 1:
                gInGameCutscene.stage++;
                break;

            case 2:
                gInGameCutscene.stage--;
                break;

            case 3:
                gInGameCutscene.stage -= 3;
                break;

            case 4:
                break;

            case 5:
                // Stop cutscene
                gInGameCutscene.cutsceneNumber = IGC_STARTED_FLAG;
                gInGameCutscene.stage = 0;
                break;
        }
    }
    else
        InGameCutsceneInit();
}

/**
 * @brief 604e0 | 128 | Initializes and sets up the in game cutscene
 * 
 */
void InGameCutsceneInit(void)
{
    u8 exists;

    exists = FALSE;

    switch (gInGameCutscene.cutsceneNumber)
    {
        case IGC_CLOSE_UP:
            gPreventMovementTimer = 60 * 6;
            exists = TRUE;
            break;

        case 6:
            if (gInGameCutscene.timer > 60)
                exists = TRUE;
            break;

        case IGC_GETTING_VARIA:
        case IGC_GETTING_FULLY_POWERED:
            if (gCurrentPowerBomb.animationState == 0 && !gCurrentPowerBomb.powerBombPlaced)
                exists = TRUE;
            break;
    }

    if (!exists)
        return;

    gInGameCutscene.stage = 0;
    gInGameCutscene.timer = 0;

    gInGameCutscene.pSubroutine = sInGameCutsceneData[gInGameCutscene.cutsceneNumber].pSubroutine;
    gInGameCutscene.cutsceneNumber |= IGC_STARTED_FLAG;
}

/**
 * @brief 6055c | 204 | Checks if an in game cutscene should play during a transition
 * 
 */
void InGameCutsceneCheckPlayOnTransition(void)
{
    i32 i;

    // Try to trigger an in game cutscene if none
    if (gInGameCutscene.queriedCutscene == 0)
    {
        for (i = 0; i < ARRAY_SIZE(sInGameCutsceneData); i++)
        {
            // ?
            if (i % 32 == 0 && gInGameCutscenesTriggered[i >> 5] == -1)
            {
                i += 32;
                continue;
            }

            // Check not set, in the correct area, and could query the cutscene
            if (InGameCutsceneCheckFlag(FALSE, i) && sInGameCutsceneData[i].area == gCurrentArea && InGameCutsceneTryQuery(i))
                break;
        }
    }

    // Apply queried cutscene
    switch (gInGameCutscene.queriedCutscene)
    {
        case IGC_CLOSE_UP:
            if (gPauseScreenFlag)
                break;

            gDisablePause = TRUE;
            gDisplayLocationText = FALSE;

            // Query brinstar and play loading jingle
            PlayMusic(MUSIC_BRINSTAR, 0);
            InsertMusicAndQueueCurrent(MUSIC_LOADING_JINGLE, 1);

            // Set samus to facing foreground
            SamusSetPose(SPOSE_FACING_THE_FOREGROUND);
            // Starting Y position
            gSamusData.yPosition = gPreviousYPosition = BLOCK_SIZE * 30 - 1;

            // Backup BG0 map
            DMATransfer(3, VRAM_BASE + 0x9000, EWRAM_BASE + 0x1E000, 0x2000, 16);
            
            // Load graphics, tile table and palette
            CallLZ77UncompVRAM(sSamusCloseUpGFX, VRAM_BASE + 0x9000);
            CallLZ77UncompWRAM(sSamusCloseUpBackgroundMap, gDecompBG0Map);
            CallLZ77UncompWRAM(sSamusCloseUpEyesTiletable, EWRAM_BASE + 0x2B000);
            dma_set(3, sSamusCloseUpPAL, PALRAM_BASE + 0xE0, DMA_ENABLE << 16 | 0x60);

            unk_5fd58();

            gCurrentRoomEntry.BG0Prop = BG_PROP_CLOSE_UP;
            gCurrentRoomEntry.BG0Size = 0;

            gBG0XPosition = 0;
            gBG0YPosition = 0;

            // Setup fade and blending
            gIoRegistersBackup.BLDALPHA_NonGameplay_EVA = gDefaultTransparency.evaCoef = 4;
            gIoRegistersBackup.BLDALPHA_NonGameplay_EVB = gDefaultTransparency.evbCoef = 12;

            write16(REG_BLDALPHA, gIoRegistersBackup.BLDALPHA_NonGameplay_EVB << 8 | gIoRegistersBackup.BLDALPHA_NonGameplay_EVA);
            TransparencyUpdateBLDALPHA(4, 12, 1, 1);

            gIoRegistersBackup.BLDCNT_NonGameplay = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL |
                BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            TransparencyUpdateBLDCNT(0, gIoRegistersBackup.BLDCNT_NonGameplay);

            gIoRegistersBackup.BG0CNT = 8;
            gIoRegistersBackup.unknown_12 = 8;
            gIoRegistersBackup.DISPCNT_NonGameplay |= DCNT_BG0;

            ColorFadingStart(COLOR_FADING_NO_TRANSITION_HUD_HIDE);
            gHideHud = TRUE;
            break;

        case IGC_LONG_BEAM_HINT:
            if (gPauseScreenFlag)
                break;

            // Setup fading
            gIoRegistersBackup.BLDALPHA_NonGameplay_EVB = 0;
            gIoRegistersBackup.BLDALPHA_NonGameplay_EVA = 16;

            TransparencyUpdateBLDALPHA(16, 0, 1, 1);
            write16(REG_BLDALPHA, gIoRegistersBackup.BLDALPHA_NonGameplay_EVB << 8 | gIoRegistersBackup.BLDALPHA_NonGameplay_EVA);
            break;
    }
}

/**
 * @brief 60800 | 74 | Try to query an in game cutscene
 * 
 * @param cutscene Cutscene
 * @return u8 bool, was queried
 */
u32 InGameCutsceneTryQuery(u8 cutscene)
{
    u8 queried;

    queried = FALSE;

    switch (cutscene)
    {
        case IGC_CLOSE_UP:
            if (gCurrentRoom == 0 && gLastDoorUsed == 0 && !gIsLoadingFile && gGameModeSub3 == 0 && !gDebugFlag && gDemoState == 0)
                queried = TRUE;
            break;

        case 6:
            if (gCurrentRoom == 5)
                queried = TRUE;
            break;

        case IGC_LONG_BEAM_HINT:
            if (gCurrentRoom == 2)
                queried = TRUE;
            break;
    }

    if (queried)
        gInGameCutscene.queriedCutscene = cutscene;

    return queried;
}

/**
 * @brief 60800 | 28 | Checks if the queried in game cutscene should play
 * 
 */
void InGameCutsceneCheckStartQueried(void)
{
    if (gPauseScreenFlag == 0)
    {
        gInGameCutscene.stage = 0;

        // Start the queried cutscene, if there's any
        if (gInGameCutscene.queriedCutscene != 0)
            InGameCutsceneStart(gInGameCutscene.queriedCutscene);
    }
}

/**
 * @brief 60828 | 54 | Transfers the previously animated palette row
 * 
 */
void UpdateAnimatedPaletteAfterTransitionOrReload(void)
{
    if (gPauseScreenFlag)
    {
        if (gAnimatedGraphicsEntry.palette != 0) // FIXME add symbol for ewram address
            dma_set(3, EWRAM_BASE + 0x355E0, PALRAM_BASE + 0x1E0, DMA_ENABLE << 16 | 16);
    }
    else
    {
        gInGameCutscene.stage = 0;
        gInGameCutscene.timer = 0;
        AnimatedPaletteCheckDisableOnTransition(); // Undefined
    }
}

/**
 * @brief 6087c | 40 | Checks if an in game cutscene was triggered, can also set it
 * 
 * @param setting Setting flag
 * @param cutscene In game cutscene number
 * @return u8 bool, not set
 */
u32 InGameCutsceneCheckFlag(u8 setting, u8 cutscene)
{
    u8 notSet;
    u32 flag;
    u32 previous;
    u32 chunk;
    u32 sub;

    // Get sub bit and chunk
    sub = cutscene % 32;
    chunk = cutscene / 32;
    notSet = FALSE;

    previous = gInGameCutscenesTriggered[chunk];

    // Get bit concerned
    flag = 1 << sub;

    // Check isn't set
    if (!(gInGameCutscenesTriggered[chunk] & flag))
    {
        notSet = TRUE;

        // Set flag if requested
        if (setting)
            gInGameCutscenesTriggered[chunk] |= flag;
    }

    return notSet;
}
