#include "in_game_cutscene.h"
#include "sprites_AI/ruins_test.h"
#include "gba.h"

#include "constants/menus/pause_screen.h"
#include "constants/samus.h"

#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/in_game_cutscene.h"
#include "structs/sprite.h"
#include "structs/transparency.h"
#include "structs/samus.h"
#include "structs/room.h"
#include "structs/bg_clip.h"

u8 InGameCutsceneSamusCloseUp(u8 cutsceneNumber, u8 cutsceneNumberNoFlag)
{

}

void unk_5fd58(void)
{

}


u8 InGameCutsceneUpgradingSuit(u8 cutsceneNumber, u8 cutsceneNumberNoFlag)
{
    // https://decomp.me/scratch/lEzCZ

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

            if (gWrittenToBLDALPHA_H != 16) // FIXME
            {
                gWrittenToBLDALPHA_H++;
                if (gWrittenToBLDALPHA_H > 16)
                    gWrittenToBLDALPHA_H = 16;
            }
            else
                changeStage++;

            if (gWrittenToBLDALPHA_L != 0) // FIXME
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
            // FIXME
            break;

        case 3:
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
            // FIXME
            break;

        case 8:
            increment = 4;
            if (gSuitFlashEffect.top != 0)
            {
                if (gSuitFlashEffect.top > increment) //FIXME
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
            increment = 7;
            if (gSuitFlashEffect.left != 0)
            {
                if (gSuitFlashEffect.left > increment) //FIXME
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
            } //FIXME
            else
                changeStage++;

            changeStage >>= 1;
            break;

        case 10:
            if (gInGameCutscene.timer > 5)
                changeStage = TRUE;
            break;

        case 11:
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
            do{
            result = InGameCutsceneCalculateSuitFlashOffset(3, top - gSuitFlashEffect.top, gSuitFlashEffect.bottom - bottom);
            res_1 = result & 0xFF;
            res_2 = result >> 8;
            }while(0);
                
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
            do{
            result = InGameCutsceneCalculateSuitFlashOffset(9, left - gSuitFlashEffect.left, gSuitFlashEffect.right - right);
            res_1 = result & 0xFF;
            res_2 = result >> 8;
            }while(0);

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
            if (gCurrentItemBeingAcquired == ITEM_ACQUISITION_GRAVITY)
                gSubSpriteData1.workVariable3 = RUINS_TEST_FIGHT_STAGE_SUIT_ANIM_ENDED;

            gSamusData.lastWallTouchedMidAir = FALSE;
            gDisablePause = FALSE;
            gDefaultTransparency.unknown_0 = 0;
            ended = TRUE;
    }

    if (changeStage)
    {
        gInGameCutscene.stage++;
        gInGameCutscene.timer = 0;
    }

    gWrittenToWIN1H = gSuitFlashEffect.left << 8 | gSuitFlashEffect.right;
    gWrittenToWIN1V = gSuitFlashEffect.top << 8 | gSuitFlashEffect.bottom;

    return ended;
}

u16 InGameCutsceneCalculateSuitFlashOffset(u8 intensity, u8 start, u8 end)
{

}


void MakeBackgroundFlash(u8 type)
{

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

void InGameCutsceneProcess(void)
{

}

void InGameCutsceneinit(void)
{

}

void LoadFirstRoom(void)
{

}


u8 unk_60760(u8 param_1)
{

}

void unk_60800(void)
{

}


void UpdateAnimatedPaletteAfterTransitionOrReload(void)
{

}

u8 unk_6087c(u8 param_1, u8 param_2)
{

}
