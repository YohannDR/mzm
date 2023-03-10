#include "haze.h"
#include "gba.h"
#include "macros.h"
#include "temp_globals.h"

#include "data/engine_pointers.h"
#include "data/haze_data.h"

#include "constants/color_fading.h"
#include "constants/haze.h"

#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/haze.h"
#include "structs/room.h"
#include "structs/power_bomb_explosion.h"

#define HAZE_SET_INACTIVE() \
do {                        \
gHazeInfo.active = FALSE;   \
} while(0);

/**
 * @brief 5cfe0 | 54 | Sets the background haze effect based on the visual effect of the room entry
 * 
 */
void HazeSetBackgroundEffect(void)
{
    HazeResetLoops();

    gCurrentHazeValue = sHazeData[gCurrentRoomEntry.visualEffect][0];

    if (gCurrentHazeValue)
    {
        gCurrentRoomEntry.damageEffect = sHazeData[gCurrentRoomEntry.visualEffect][1];
        gWaterMovement.moving = sHazeData[gCurrentRoomEntry.visualEffect][2];
    }

    HazeSetupCode(gCurrentHazeValue);
}

/**
 * @brief 5d034 | 98 | Transfers the haze effect and clears it
 * 
 */
void HazeTransferAndDeactivate(void)
{
    vu8 buffer;

    if (gHazeInfo.active)
    {
        dma_set(0, gHazeValues, gHazeInfo.pAffected, (DMA_ENABLE | DMA_DEST_RELOAD) << 16 | gHazeInfo.size / 2);

        buffer = sHaze_345ff8[0];
        buffer = sHaze_345ff8[0];

        dma_set(0, gHazeValues, gHazeInfo.pAffected, (DMA_DEST_RELOAD) << 16 | gHazeInfo.size / 2);

        gHazeInfo.active = FALSE;
    }
}

/**
 * @brief 5d09c | 7c | To document
 * 
 */
void unk_5d09c(void)
{
    vu8 buffer;

    if (gHazeInfo.active)
    {
        dma_set(0, gHazeValues, gHazeInfo.pAffected, (DMA_ENABLE | DMA_DEST_RELOAD) << 16 | gHazeInfo.size / 2);

        buffer = sHaze_345ff8[0];
        buffer = sHaze_345ff8[0];

        dma_set(0, gHazeValues, gHazeInfo.pAffected, (DMA_DEST_RELOAD) << 16 | gHazeInfo.size / 2);

        HAZE_SET_INACTIVE();
        gHazeInfo.size = 2;
        gHazeInfo.pAffected = gPreviousHazeValues;
        gCurrentHazeValue = 0;
    }
}

/**
 * @brief 5d118 | 2ba | Sets up code and values for a haze effect
 * 
 * @param hazeValue Haze value
 */
void HazeSetupCode(u8 hazeValue)
{
    gCurrentHazeValue = hazeValue;
    gHazeInfo.enabled = FALSE;

    HazeTransferAndDeactivate();

    switch (gCurrentHazeValue)
    {
        case HAZE_VALUE_GRADIENT:
            HazeCalculateGradient();

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 2;
            gHazeInfo.unk = 0x140;
            gHazeInfo.pAffected = PALRAM_BASE;
            break;

        case HAZE_VALUE_BG3:
            DMATransfer(3, Haze_Bg3, &gNonGameplayRAM.inGame[640], 0x200, 16);
            gHazeProcessCodePointer = (HazeFunc_T)(&gNonGameplayRAM.inGame[640] + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 2;
            gHazeInfo.unk = 0x140;
            gHazeInfo.pAffected = REG_BG3HOFS;
            break;

        case HAZE_VALUE_BG3_STRONG_WEAK:
            DMATransfer(3, Haze_Bg3StrongWeak, &gNonGameplayRAM.inGame[640], 0x200, 16);
            gHazeProcessCodePointer = (HazeFunc_T)(&gNonGameplayRAM.inGame[640] + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 2;
            gHazeInfo.unk = 0x140;
            gHazeInfo.pAffected = REG_BG3HOFS;
            break;
 
        case HAZE_VALUE_BG3_NONE_WEAK:
            DMATransfer(3, Haze_Bg3NoneWeak, &gNonGameplayRAM.inGame[640], 0x200, 16);
            gHazeProcessCodePointer = (HazeFunc_T)(&gNonGameplayRAM.inGame[640] + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 2;
            gHazeInfo.unk = 0x140;
            gHazeInfo.pAffected = REG_BG3HOFS;
            break;

        case HAZE_VALUE_BG3_BG2_STRONG_WEAK_MEDIUM:
            DMATransfer(3, Haze_Bg3Bg2StrongWeakMedium, &gNonGameplayRAM.inGame[640], 0x200, 16);
            gHazeProcessCodePointer = (HazeFunc_T)(&gNonGameplayRAM.inGame[640] + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 8;
            gHazeInfo.unk = 0x500;
            gHazeInfo.pAffected = REG_BG2HOFS;
            break;

        case HAZE_VALUE_BG3_BG2_BG1:
            DMATransfer(3, Haze_Bg3Bg2Bg1, &gNonGameplayRAM.inGame[640], 0x200, 16);
            gHazeProcessCodePointer = (HazeFunc_T)(&gNonGameplayRAM.inGame[640] + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 12;
            gHazeInfo.unk = 0x780;
            gHazeInfo.pAffected = REG_BG1HOFS;
            break;

        case HAZE_VALUE_POWER_BOMB_EXPANDING:
            gWrittenToWININ_H = 0x1F;
            gWrittenToWINOUT_L = 0x37;
            gWrittenToBLDCNT = 0xCF;
            write16(REG_BLDY, 0xC);
            gWrittenToWIN1V = 0xA0;
            gWrittenToWIN1H = 0x0;
            PowerBombYellowTint(0);

            if (gIoRegistersBackup.DISPCNT_NonGameplay & DCNT_BG0 && gCurrentRoomEntry.BG0Prop != 0x12)
                gWrittenToDISPCNT = read16(REG_DISPCNT) ^ DCNT_BG0;

            gWrittenTo0x05000000 = COLOR_WHITE;

            DMATransfer(3, Haze_PowerBombExpanding, &gNonGameplayRAM.inGame[640], 0x200, 16);
            gHazeProcessCodePointer = (HazeFunc_T)(&gNonGameplayRAM.inGame[640] + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 2;
            gHazeInfo.unk = 0x140;
            gHazeInfo.pAffected = REG_WIN1H;

            if (gHazeInfo.enabled)
                gHazeInfo.active = TRUE;
            break;

        case HAZE_VALUE_POWER_BOMB_RETRACTING:
            DMATransfer(3, Haze_PowerBombRetracting, &gNonGameplayRAM.inGame[640], 0x200, 16);
            gHazeProcessCodePointer = (HazeFunc_T)(&gNonGameplayRAM.inGame[640] + 1);

            gHazeInfo.enabled = TRUE;

            if (gHazeInfo.enabled)
                gHazeInfo.active = TRUE;
            break;

        case HAZE_VALUE_AFTER_POWER_BOMB:
        case HAZE_VALUE_COLD:
            gCurrentHazeValue = 0;
            break;
    }
}

/**
 * @brief 5d3d8 | 3c | Resets the haze loops
 * 
 */
void HazeResetLoops(void)
{
    if (gPauseScreenFlag == 0)
    {
        gHazeLoops[0] = sHazeLoop_Empty;
        gHazeLoops[1] = sHazeLoop_Empty;
        gHazeLoops[2] = sHazeLoop_Empty;
    }

    gUnk_3005728 = 0;
    gUnk_3005729 = 0;
}

void HazeCalculateGradient(void)
{
    // https://decomp.me/scratch/Y11RY

    i32 i;
    i32 j;
    u16* dst;
    u16* sec;
    u16 value;
    u8 r1;
    u8 g1;
    u8 b1;
    u16 color1;
    u8 r2;
    u8 g2;
    u8 b2;
    u16 color2;
    u32 var_sp_8;
    u32 var_sp_C;
    u32 var_sp_10;
    u32 var_sp_14;
    u32 var_sp_1C;
    u32 var_sp_20;
    u32 var_sp_24;

    dst = gPreviousHazeValues;
    for (i = 0; i < 0xA0; i++)
    {
        value = 0;
        if (i < 5)
            value = read16(PALRAM_BASE + 0x1C0);
        else if (i > 0x9A)
            value = read16(PALRAM_BASE + 0x1D8);

        dst[i] = value;
    }

    dst += 5;

    for (i = 0; i < 16; i++)
    {
        color1 = read16(PALRAM_BASE + 0xE0 + i);
        r1 = RED(color1);
        g1 = GREEN(color1);
        BLUE(color1, b1);

        color2 = read16(PALRAM_BASE + 0xE2 + i);
        r2 = RED(color2) - r1;
        g2 = GREEN(color2) - g1;
        BLUE(color2, b2); b2 -= b1;

        j = 0;

        var_sp_8 = b2 / 10;
        var_sp_C = b2 % 10;
        var_sp_1C = 0;
        // var_sp_20 = ;
        var_sp_10 = b2 / 100;
        var_sp_14 = g2 % 100;
        var_sp_24 = 0;

        for (; j < 16; j++)
        {
        }
    }
}

/**
 * @brief 5d5bc | 1ac | Processes the current haze effect
 * 
 * @return u32 bool, ended
 */
u32 HazeProcess(void)
{
    u32 ended;

    ended = FALSE;

    switch (gCurrentHazeValue)
    {
        case HAZE_VALUE_NONE:
            break;
    
        case HAZE_VALUE_BG3:
        case HAZE_VALUE_BG3_STRONG_WEAK:
        case HAZE_VALUE_BG3_NONE_WEAK:
        case HAZE_VALUE_BG3_BG2_STRONG_WEAK_MEDIUM:
            // Update the haze
            gHazeProcessCodePointer();
            break;

        case HAZE_VALUE_POWER_BOMB_EXPANDING:
            // Update the haze
            if (gHazeProcessCodePointer())
            {
                // Expanding ended, setup retracting
                gCurrentHazeValue = HAZE_VALUE_POWER_BOMB_RETRACTING;
                HazeSetupCode(HAZE_VALUE_POWER_BOMB_RETRACTING);
                gCurrentPowerBomb.animationState = 4;

                if (gAnimatedGraphicsEntry.palette == 0)
                {
                    dma_set(3, EWRAM_BASE + 0x9000, EWRAM_BASE + 0x35000, DMA_ENABLE << 16 | 0x100);
                }
                else
                {
                    dma_set(3, EWRAM_BASE + 0x9000, EWRAM_BASE + 0x35000, DMA_ENABLE << 16 | 0xF0);
                }

                gColorFading.status |= COLOR_FADING_STATUS_ON_BG;
                gWrittenToWININ_H = 0x37;
                gWrittenToWINOUT_L = 0x1F;
                gWrittenTo0x05000000 = COLOR_BLACK;
            }
            break;

        case HAZE_VALUE_POWER_BOMB_RETRACTING:
            if (gHazeProcessCodePointer())
            {
                gIoRegistersBackup.unknown_12 = gIoRegistersBackup.BG0CNT;
                gCurrentPowerBomb.animationState = 5;
                gCurrentPowerBomb.stage = 0;

                HazeSetupCode(HAZE_VALUE_AFTER_POWER_BOMB);

                if (gAnimatedGraphicsEntry.palette == 0)
                {
                    dma_set(3, EWRAM_BASE + 0x9000, EWRAM_BASE + 0x35000, DMA_ENABLE << 16 | 0x100);
                }
                else
                {
                    dma_set(3, EWRAM_BASE + 0x9000, EWRAM_BASE + 0x35000, DMA_ENABLE << 16 | 0xF0);
                }

                gColorFading.status |= COLOR_FADING_STATUS_ON_BG;
                ended = TRUE;
            }
            break;

        case HAZE_VALUE_BG3_BG2_BG1:
            Haze_Bg3Bg2Bg1();
            break;
    }

    if (ended)
    {
        HazeSetBackgroundEffect();
        if (gCurrentHazeValue == 0)
            ended = FALSE;
    }

    return ended;
}


void Haze_Bg3(void)
{
    // https://decomp.me/scratch/X4zm8

    i32 mask;
    u16* dst;
    const i8* src;
    i32 i;
    i32 position;
    u16* _dst;

    dst = gPreviousHazeValues;
    i = 0;

    gHazeLoops[2].unk_3 = FALSE;
    gHazeLoops[1].unk_3 = FALSE;

    src = sHaze_Bg3_StrongEffect;
    mask = ARRAY_SIZE(sHaze_Bg3_StrongEffect) / 3 - 1;
    gHazeLoops[0].unk_3 = FALSE;
    gHazeLoops[0].timer++;

    if (gHazeLoops[0].timer > 5)
    {
        gHazeLoops[0].unk_3 = TRUE;
        gHazeLoops[0].timer = 0;
    }

    gUnk_3005728 += gHazeLoops[0].unk_3;

    position = (gEffectYPosition / 4) - (gBG1YPosition / 4) - 1;

    if (position > 0xA0)
        position = 0xA0;
    else if (position < 0)
        position = 0;

    i = 0;
    if (i < position)
    {
        _dst = dst;

        i = position;
        do
        {
            *_dst++ = gBackgroundPositions.bg[3].x;
            i--;
        }
        while (i);

        i = position;
    }

    while (i < 0xA0)
    {
        dst[i] = src[(gBackgroundPositions.bg[3].y + i + gUnk_3005728) & mask] + gBackgroundPositions.bg[3].x;
        i++;
    }
}

void Haze_Bg3StrongWeak(void)
{

}

/**
 * @brief 5d940 | 70 | Updates the haze effect (BG3, nothing in effect, weak outside)
 * 
 */
void Haze_Bg3NoneWeak(void)
{
    i32 i;
    i32 mask;
    const i8* src;
    u8* ptr;

    i = 0;

    gHazeLoops[2].unk_3 = FALSE;
    gHazeLoops[1].unk_3 = FALSE;

    src = sHaze_Bg_WeakOutside;
    mask = ARRAY_SIZE(sHaze_Bg_WeakOutside) - 1;
    gHazeLoops[0].unk_3 = FALSE;

    gHazeLoops[0].timer++;
    if (gHazeLoops[0].timer > 5)
    {
        gHazeLoops[0].unk_3 = TRUE;
        gHazeLoops[0].timer = 0;
    }

    gUnk_3005728 += gHazeLoops[0].unk_3;
    ptr = &gUnk_3005728;

    for (; i < 0xA0; i++)
    {
        gPreviousHazeValues[i] = src[(gBackgroundPositions.bg[3].y + i + *ptr) & mask] + gBackgroundPositions.bg[3].x;
    }
}

/**
 * @brief 5d9b0 | 90 | Updates the haze effect (BG3 and BG2, strong in effect, weak outside and medium everywhere)
 * 
 */
void Haze_Bg3Bg2StrongWeakMedium(void)
{
    i32 i;
    i32 mask;
    const i8* src;
    u16* dst;

    i = 0;

    gHazeLoops[1].unk_3 = FALSE;

    src = sHaze_Bg_WeakOutside;
    mask = ARRAY_SIZE(sHaze_Bg_WeakOutside) - 1;
    gHazeLoops[0].unk_3 = FALSE;

    gHazeLoops[0].timer++;
    if (gHazeLoops[0].timer > 5)
    {
        gHazeLoops[0].unk_3 = TRUE;
        gHazeLoops[0].timer = 0;
    }

    gUnk_3005728 += gHazeLoops[0].unk_3;
    dst = gPreviousHazeValues;

    for (; i < 0xA0; i++)
    {
        *dst++ = src[(gBackgroundPositions.bg[2].y + i + gUnk_3005728) & mask] + gBackgroundPositions.bg[2].x;
        *dst++ = gBackgroundPositions.bg[2].y;
        *dst++ = src[(gBackgroundPositions.bg[3].y + i + gUnk_3005728) & mask] + gBackgroundPositions.bg[3].x;
        *dst++ = gBackgroundPositions.bg[3].y;
    }
}

void Haze_Bg3Bg2Bg1(void)
{
    // https://decomp.me/scratch/nT6YG

    i32 i;
    i32 mask;
    const i8* src;
    u16* dst;
    i32 temp;

    i = 0;
    gHazeLoops[2].timer++;

    if (gUnk_3005514 == TRUE)
    {
        if (gHazeLoops[2].timer > 15)
        {
            gHazeLoops[2].timer = 0;
            if (gHazeLoops[2].unk_3 < 4)
                gHazeLoops[2].unk_3++;
        }
    }
    else
    {
        if (gHazeLoops[2].timer > 15)
        {
            gHazeLoops[2].timer = 0;
            if (gHazeLoops[2].unk_3 != 0)
                gHazeLoops[2].unk_3--;
        }
    }

    src = sHaze_Bg3Bg2Bg1[gHazeLoops[2].unk_3];
    mask = ARRAY_SIZE(sHaze_Bg3Bg2Bg1[0]) - 1;

    gHazeLoops[0].unk_3 = FALSE;
    gHazeLoops[0].timer++;
    if (gHazeLoops[0].timer > 7)
    {
        gHazeLoops[0].unk_3 = TRUE;
        gHazeLoops[0].timer = 0;
    }

    gUnk_3005728 -= gHazeLoops[0].unk_3;
    dst = gPreviousHazeValues;

    for (i = 0; i < 0xA0; i++)
    {
        temp = *dst++ = src[(gBackgroundPositions.bg[1].y + i + gUnk_3005728) & mask] + gBackgroundPositions.bg[1].x;
        *dst++ = gBackgroundPositions.bg[1].y;
        *dst++ = temp;
        *dst++ = gBackgroundPositions.bg[2].y;
        *dst++ = src[(gBackgroundPositions.bg[3].y + i + gUnk_3005728) & mask] + gBackgroundPositions.bg[3].x;
        *dst++ = gBackgroundPositions.bg[3].y;
    }
}


u32 Haze_PowerBombExpanding(void)
{

}

u32 Haze_PowerBombRetracting(void)
{

}
