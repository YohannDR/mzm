#include "haze.h"
#include "gba.h"
#include "macros.h"
#include "temp_globals.h"

#include "data/engine_pointers.h"
#include "data/haze_data.h"

#include "constants/color_fading.h"
#include "constants/haze.h"
#include "constants/game_state.h"
#include "constants/room.h"
#include "constants/power_bomb_explosion.h"

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

    if (gCurrentHazeValue != HAZE_VALUE_NONE)
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
        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, C_32_2_16(DMA_ENABLE | DMA_DEST_RELOAD, gHazeInfo.size / 2));

        buffer = sHaze_345ff8[0];
        buffer = sHaze_345ff8[0];

        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, C_32_2_16(DMA_DEST_RELOAD, gHazeInfo.size / 2));

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
        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, C_32_2_16(DMA_ENABLE | DMA_DEST_RELOAD, gHazeInfo.size / 2));

        buffer = sHaze_345ff8[0];
        buffer = sHaze_345ff8[0];

        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, C_32_2_16(DMA_DEST_RELOAD, gHazeInfo.size / 2));

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
            gHazeInfo.unk_4 = 0x140;
            gHazeInfo.pAffected = PALRAM_BASE;
            break;

        case HAZE_VALUE_BG3:
            DmaTransfer(3, Haze_Bg3, &gNonGameplayRam.inGame[640], 0x200, 16);
            gHazeProcessCodePointer = (HazeFunc_T)(&gNonGameplayRam.inGame[640] + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 2;
            gHazeInfo.unk_4 = 0x140;
            gHazeInfo.pAffected = REG_BG3HOFS;
            break;

        case HAZE_VALUE_BG3_STRONG_WEAK:
            DmaTransfer(3, Haze_Bg3StrongWeak, &gNonGameplayRam.inGame[640], 0x200, 16);
            gHazeProcessCodePointer = (HazeFunc_T)(&gNonGameplayRam.inGame[640] + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 2;
            gHazeInfo.unk_4 = 0x140;
            gHazeInfo.pAffected = REG_BG3HOFS;
            break;
 
        case HAZE_VALUE_BG3_NONE_WEAK:
            DmaTransfer(3, Haze_Bg3NoneWeak, &gNonGameplayRam.inGame[640], 0x200, 16);
            gHazeProcessCodePointer = (HazeFunc_T)(&gNonGameplayRam.inGame[640] + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 2;
            gHazeInfo.unk_4 = 0x140;
            gHazeInfo.pAffected = REG_BG3HOFS;
            break;

        case HAZE_VALUE_BG3_BG2_STRONG_WEAK_MEDIUM:
            DmaTransfer(3, Haze_Bg3Bg2StrongWeakMedium, &gNonGameplayRam.inGame[640], 0x200, 16);
            gHazeProcessCodePointer = (HazeFunc_T)(&gNonGameplayRam.inGame[640] + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 8;
            gHazeInfo.unk_4 = 0x500;
            gHazeInfo.pAffected = REG_BG2HOFS;
            break;

        case HAZE_VALUE_BG3_BG2_BG1:
            DmaTransfer(3, Haze_Bg3Bg2Bg1, &gNonGameplayRam.inGame[640], 0x200, 16);
            gHazeProcessCodePointer = (HazeFunc_T)(&gNonGameplayRam.inGame[640] + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 12;
            gHazeInfo.unk_4 = 0x780;
            gHazeInfo.pAffected = REG_BG1HOFS;
            break;

        case HAZE_VALUE_POWER_BOMB_EXPANDING:
            gWrittenToWININ_H = HIGH_BYTE(WIN1_ALL_NO_COLOR_EFFECT);
            gWrittenToWINOUT_L = WIN0_BG0 | WIN0_BG1 | WIN0_BG2 | WIN0_OBJ | WIN0_COLOR_EFFECT;

            gWrittenToBLDCNT = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

            write16(REG_BLDY, 12);

            gWrittenToWIN1V = SCREEN_SIZE_Y;
            gWrittenToWIN1H = 0;

            PowerBombYellowTint(0);

            if (gIoRegistersBackup.Dispcnt_NonGameplay & DCNT_BG0 && gCurrentRoomEntry.Bg0Prop != BG_PROP_DISABLE_TRANSPARENCY)
                gWrittenToDISPCNT = read16(REG_DISPCNT) ^ DCNT_BG0;

            gBackdropColor = COLOR_WHITE;

            DmaTransfer(3, Haze_PowerBombExpanding, &gNonGameplayRam.inGame[640], 0x200, 16);
            gHazeProcessCodePointer = (HazeFunc_T)(&gNonGameplayRam.inGame[640] + 1);

            gHazeInfo.enabled = TRUE;
            
            gHazeInfo.size = 2;
            gHazeInfo.unk_4 = 0x140;
            gHazeInfo.pAffected = REG_WIN1H;

            if (gHazeInfo.enabled)
                gHazeInfo.active = TRUE;
            break;

        case HAZE_VALUE_POWER_BOMB_RETRACTING:
            DmaTransfer(3, Haze_PowerBombRetracting, &gNonGameplayRam.inGame[640], 0x200, 16);
            gHazeProcessCodePointer = (HazeFunc_T)(&gNonGameplayRam.inGame[640] + 1);

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
    if (gPauseScreenFlag == PAUSE_SCREEN_NONE)
    {
        gHazeLoops[0] = sHazeLoop_Empty;
        gHazeLoops[1] = sHazeLoop_Empty;
        gHazeLoops[2] = sHazeLoop_Empty;
    }

    gUnk_3005728 = 0;
    gUnk_3005729 = 0;
}

/**
 * @brief 5d414 | 1a8 | Calcules the gradiant
 * 
 */
void HazeCalculateGradient(void)
{
    s32 i;
    s32 j;
    u16* dst;
    u16* src;
    u16* src2;

    u8 rBase;
    u8 gBase;
    u8 bBase;

    s32 r;
    s32 g;
    s32 b;
    
    u8 newR;
    u8 newG;
    u8 newB;

    dst = gPreviousHazeValues;
    for (i = 0; i < 16 * 10; i++)
    {
        j = 0;
        if (i < 5)
        {
            src = (u16*)(PALRAM_BASE + 16 * 28);
            j = src[0];
        }
        else if (i > 0x9A)
        {
            src = (u16*)(PALRAM_BASE + 16 * 28);
            j = src[15];
        }

        dst[i] = j;
    }

    dst += 5;

    for (i = 0; i < 15; i++)
    {
        src = (u16*)(PALRAM_BASE + 16 * 28);
        src2 = &src[i];
        
        rBase = RED(src2[0]);
        gBase = GREEN(src2[0]);
        bBase = BLUE(src2[0]);

        r = RED(src2[1]);
        g = GREEN(src2[1]);
        b = BLUE(src2[1]);

        r -= rBase;
        g -= gBase;
        b -= bBase;

        for (j = 0; j < 10; j++)
        {
            newR = j * (r / 10) + rBase;
            newR += (r % 10 * j) / 10;
            newR += (r % 100 * j) / 100;

            newG = j * (g / 10) + gBase;
            newG += (g % 10 * j) / 10;
            newG += (g % 100 * j) / 100;
            
            newB = j * (b / 10) + bBase;
            newB += (b % 10 * j) / 10;
            newB += (b % 100 * j) / 100;

            *dst++ = COLOR_GRAD(newR, newG, newB);
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
                gCurrentPowerBomb.animationState = PB_STATE_IMPLODING;

                if (gAnimatedGraphicsEntry.palette == 0)
                {
                    DMA_SET(3, EWRAM_BASE + 0x9000, EWRAM_BASE + 0x35000, C_32_2_16(DMA_ENABLE, PALRAM_SIZE / 4));
                }
                else
                {
                    DMA_SET(3, EWRAM_BASE + 0x9000, EWRAM_BASE + 0x35000, C_32_2_16(DMA_ENABLE, PALRAM_SIZE / 4 - 16));
                }

                gColorFading.status |= COLOR_FADING_STATUS_ON_BG;
                gWrittenToWININ_H = HIGH_BYTE(WIN1_BG0 | WIN1_BG1 | WIN1_BG2 | WIN1_OBJ | WIN1_COLOR_EFFECT);
                gWrittenToWINOUT_L = WIN0_ALL_NO_COLOR_EFFECT;
                gBackdropColor = COLOR_BLACK;
            }
            break;

        case HAZE_VALUE_POWER_BOMB_RETRACTING:
            if (gHazeProcessCodePointer())
            {
                gIoRegistersBackup.unk_12 = gIoRegistersBackup.BG0CNT;
                gCurrentPowerBomb.animationState = PB_STATE_ENDING;
                gCurrentPowerBomb.stage = 0;

                HazeSetupCode(HAZE_VALUE_AFTER_POWER_BOMB);

                if (gAnimatedGraphicsEntry.palette == 0)
                {
                    DMA_SET(3, EWRAM_BASE + 0x9000, EWRAM_BASE + 0x35000, C_32_2_16(DMA_ENABLE, PALRAM_SIZE / 4));
                }
                else
                {
                    DMA_SET(3, EWRAM_BASE + 0x9000, EWRAM_BASE + 0x35000, C_32_2_16(DMA_ENABLE, PALRAM_SIZE / 4 - 16));
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

/**
 * @brief 5d768 | c0 | Updates the haze effect (BG3, strong everywhere)
 * 
 */
void Haze_Bg3(void)
{
    s32 mask;
    u16* dst;
    const s8* src;
    s32 i;
    s32 position;
    u8* ptr;
    s32 offset;

    do {
    dst = gPreviousHazeValues;
    }while(0);
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

    position = SUB_PIXEL_TO_PIXEL(gEffectYPosition) - SUB_PIXEL_TO_PIXEL(gBg1YPosition) - 1;

    CLAMP(position, 0, SCREEN_SIZE_Y);

    for (i = 0; i < position; i++)
    {
        dst[i] = gBackgroundPositions.bg[3].x;
    }

    while (i < SCREEN_SIZE_Y)
    {
        ptr = &gUnk_3005728;
        do{
        position = (gBackgroundPositions.bg[3].y + i + *ptr) & mask;
        }while(0);
        dst[i] = src[position] + gBackgroundPositions.bg[3].x;
        i++;
    }
}

/**
 * @brief 5d828 | 118 | Updates the haze effect (BG3, strong in effect, weak outside)
 * 
 */
void Haze_Bg3StrongWeak(void)
{
    s32 i;
    const s8* src1;
    s32 mask1;
    const s8* src2;
    s32 mask2;
    s32 position;
    u16* dst;
    s32 offset;
    u8* ptr1;
    u8* ptr2;

    dst = gPreviousHazeValues;

    i = 0;
    gHazeLoops[2].unk_3 = FALSE;

    src1 = sHaze_Bg3_StrongEffect;
    mask1 = 0xF;

    gHazeLoops[0].unk_3 = FALSE;
    gHazeLoops[0].timer++;

    if (gHazeLoops[0].timer > 5)
    {
        gHazeLoops[0].unk_3 = TRUE;
        gHazeLoops[0].timer = 0;
    }

    src2 = sHaze_Bg3_WeakOutside;
    mask2 = 0xF;

    gHazeLoops[1].unk_3 = FALSE;
    gHazeLoops[1].timer++;

    if (gHazeLoops[1].timer > 11)
    {
        gHazeLoops[1].unk_3 = TRUE;
        gHazeLoops[1].timer = 0;
    }

    gUnk_3005728 += gHazeLoops[0].unk_3;
    gUnk_3005729 += gHazeLoops[1].unk_3;

    position = SUB_PIXEL_TO_PIXEL(gEffectYPosition) - SUB_PIXEL_TO_PIXEL(gBg1YPosition) - 1;

    CLAMP(position, 0, SCREEN_SIZE_Y);

    for (i = 0; i < position; i++)
    {
        ptr1 = &gUnk_3005729;
        offset = (gBackgroundPositions.bg[3].y + i + *ptr1) & mask2;
        dst[i] = src2[offset] + gBackgroundPositions.bg[3].x;
    }

    while (i < SCREEN_SIZE_Y)
    {
        ptr2 = &gUnk_3005728;
        offset = (gBackgroundPositions.bg[3].y + i + *ptr2) & mask1;
        dst[i] = src1[offset] + gBackgroundPositions.bg[3].x;
        i++;
    }
}

/**
 * @brief 5d940 | 70 | Updates the haze effect (BG3, nothing in effect, weak outside)
 * 
 */
void Haze_Bg3NoneWeak(void)
{
    s32 i;
    s32 mask;
    const s8* src;
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

    for (; i < SCREEN_SIZE_Y; i++)
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
    s32 i;
    s32 mask;
    const s8* src;
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

    for (; i < SCREEN_SIZE_Y; i++)
    {
        *dst++ = src[(gBackgroundPositions.bg[2].y + i + gUnk_3005728) & mask] + gBackgroundPositions.bg[2].x;
        *dst++ = gBackgroundPositions.bg[2].y;

        *dst++ = src[(gBackgroundPositions.bg[3].y + i + gUnk_3005728) & mask] + gBackgroundPositions.bg[3].x;
        *dst++ = gBackgroundPositions.bg[3].y;
    }
}

/**
 * @brief 5da40 | ec | Updates the haze effect (BG3, BG2 and BG1, strong everywhere)
 * 
 */
void Haze_Bg3Bg2Bg1(void)
{
    s32 i;
    s32 mask;
    const s8* src;
    u16* dst;
    u8* ptr;
    s32 tmp;

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

    for (i = 0; i < SCREEN_SIZE_Y; i++)
    {
        ptr = &gUnk_3005728;

        tmp = gBackgroundPositions.bg[1].y + i + *ptr;
        tmp = src[tmp & mask] + gBackgroundPositions.bg[1].x;
        *dst++ = tmp;
        *dst++ = gBackgroundPositions.bg[1].y;

        *dst++ = tmp;
        *dst++ = gBackgroundPositions.bg[2].y;

        tmp = gBackgroundPositions.bg[3].y + i + *ptr;
        *dst++ = src[tmp & mask] + gBackgroundPositions.bg[3].x;
        *dst++ = gBackgroundPositions.bg[3].y;
    }
}

/**
 * @brief 5db2c | 118 | Updates the haze effect (power bomb expanding)
 * 
 * @return u32 bool, ended
 */
u32 Haze_PowerBombExpanding(void)
{
    const s16* src;
    s32 xPosition;
    s32 yPosition;
    u16* dst;
    s32 i;
    s32 screenY;
    s32 subSlice;
    s32 right;
    s32 size;

    if (gCurrentPowerBomb.unk_12 != 0)
        return FALSE;

    src = sHaze_PowerBomb_WindowValuesPointers[gCurrentPowerBomb.semiMinorAxis];
    size = gCurrentPowerBomb.semiMinorAxis;
    xPosition = SUB_PIXEL_TO_PIXEL_(gCurrentPowerBomb.xPosition - gBg1XPosition);
    yPosition = SUB_PIXEL_TO_PIXEL_(gCurrentPowerBomb.yPosition - gBg1YPosition);

    // FIXME use symbol
    dst = (u16*)0x2026d00; // gPreviousHazeValues
    for (i = 0; i <= 53 * 3; i++, dst++)
        *dst = 0;

    screenY = yPosition + size + 1;
    CLAMP(screenY, 0, 53 * 3);

    do {
    subSlice = 0;
    }while(0);
    i = yPosition - size;
    if (i < 0)
    {
        subSlice = -i;
        i = 0;
    }
    else if (i > 53 * 3)
    {
        i = 53 * 3;
    }

    // FIXME use symbol
    dst = (u16*)0x2026d00 + i; // gPreviousHazeValues
    for (; i < screenY; i++, subSlice++, dst++)
    {
        yPosition = (s16)(xPosition + src[subSlice * 2 + 1] * 2);
        right = (s16)(xPosition + src[subSlice * 2 + 0] * 2);

        CLAMP2(yPosition, 0, SCREEN_SIZE_X);
        CLAMP(right, 0, SCREEN_SIZE_X);

        *dst = C_16_2_8_(yPosition, right);
    }

    if (gCurrentPowerBomb.semiMinorAxis >= 53 * 3)
    {
        gCurrentPowerBomb.stage++;
        if (gCurrentPowerBomb.stage > 4)
            return TRUE;
    }
    else
    {
        gCurrentPowerBomb.semiMinorAxis += 3;
        if (gCurrentPowerBomb.semiMinorAxis > 53 * 3)
            gCurrentPowerBomb.semiMinorAxis = 53 * 3;
    }

    return FALSE;
}

/**
 * @brief 5dc44 | 118 | Updates the haze effect (power bomb retracting)
 * 
 * @return u32 bool, ended
 */
u32 Haze_PowerBombRetracting(void)
{
    const s16* src;
    s32 xPosition;
    s32 yPosition;
    u16* dst;
    s32 i;
    s32 screenY;
    s32 subSlice;
    s32 right;
    s32 size;

    if (gCurrentPowerBomb.unk_12 != 0)
        return FALSE;

    src = sHaze_PowerBomb_WindowValuesPointers[gCurrentPowerBomb.semiMinorAxis];
    size = gCurrentPowerBomb.semiMinorAxis;
    xPosition = SUB_PIXEL_TO_PIXEL_(gCurrentPowerBomb.xPosition - gBg1XPosition);
    yPosition = SUB_PIXEL_TO_PIXEL_(gCurrentPowerBomb.yPosition - gBg1YPosition);

    // FIXME use symbol
    dst = (u16*)0x2026d00; // gPreviousHazeValues
    for (i = 0; i <= 53 * 3; i++, dst++)
        *dst = 0;

    screenY = yPosition + size + 1;
    CLAMP(screenY, 0, 53 * 3);

    do {
    subSlice = 0;
    }while(0);
        
    i = yPosition - size;
    if (i < 0)
    {
        subSlice = -i;
        i = 0;
    }
    else if (i > 53 * 3)
    {
        i = 53 * 3;
    }

    // FIXME use symbol
    dst = (u16*)0x2026d00 + i; // gPreviousHazeValues
    for (; i < screenY; i++, subSlice++, dst++)
    {
        yPosition = (s16)(xPosition + src[subSlice * 2 + 1] * 2);
        right = (s16)(xPosition + src[subSlice * 2 + 0] * 2);

        CLAMP2(yPosition, 0, SCREEN_SIZE_X);
        CLAMP(right, 0, SCREEN_SIZE_X);

        *dst = C_16_2_8_(yPosition, right);
    }


    if (gCurrentPowerBomb.semiMinorAxis <= 4)
    {
        gCurrentPowerBomb.stage++;
        if (gCurrentPowerBomb.stage > 4)
            return TRUE;
    }
    else
    {
        gCurrentPowerBomb.semiMinorAxis -= 3;
        if (gCurrentPowerBomb.semiMinorAxis < 4)
            gCurrentPowerBomb.semiMinorAxis = 4;
    }

    return FALSE;
}
