#include "ending_and_gallery.h"
#include "callbacks.h"

#include "data/shortcut_pointers.h"
#include "data/ending_and_gallery_data.h"
#include "data/internal_ending_and_gallery_data.h"

#include "constants/audio.h"
#include "constants/ending_and_gallery.h"
#include "constants/game_state.h"
#include "constants/text.h"

#include "structs/bg_clip.h"
#include "structs/display.h"
#include "structs/ending_and_gallery.h"
#include "structs/game_state.h"

/**
 * @brief 84c34 | 48 | Checks if an ending letter should display
 * 
 * @param offset Offset, to document
 */
void EndingImageUpdateLettersSpawnDelay(u32 offset)
{
    if (ENDING_DATA.oamTypes[offset] == ENDING_OAM_TYPE_NONE)
        return;

    if (ENDING_DATA.endingLettersSpawnDelay[offset])
    {
        ENDING_DATA.endingLettersSpawnDelay[offset]--;
        if (ENDING_DATA.endingLettersSpawnDelay[offset] == 0)
            ENDING_DATA.oamTypes[offset]++;
    }
}

/**
 * @brief 84c7c | 26c | Loads a set of OAM for the ending image
 * 
 * @param set Set to load
 */
void EndingImageLoadTextOAM(u32 set)
{
    s32 i;

    if (ENDING_DATA.language == LANGUAGE_HIRAGANA)
    {
        if (set == ENDING_IMAGE_OAM_SET_CLEAR_TIME)
        {
            ENDING_DATA.oamLength = ARRAY_SIZE(sEndingImageOam_ClearTime_Hiragana) + 6;

            for (i = 0; i < ARRAY_SIZE(sEndingImageOam_ClearTime_Hiragana); i++)
            {
                ENDING_DATA.oamTypes[i + 6] = sEndingImageOam_ClearTime_Hiragana[i].type;
                ENDING_DATA.endingLettersSpawnDelay[i + 6] = sEndingImageOam_ClearTime_Hiragana[i].spawnDelay;
                ENDING_DATA.unk_160[i + 6] = sEndingImageOam_ClearTime_Hiragana[i].unk_2;

                ENDING_DATA.oamXPositions[i + 6] = sEndingImageOam_ClearTime_Hiragana[i].xPosition;
                ENDING_DATA.oamYPositions[i + 6] = sEndingImageOam_ClearTime_Hiragana[i].yPosition;

                ENDING_DATA.oamFramePointers[i + 6] = sEndingImageOam_ClearTime_Hiragana[i].pFrame;
            }
        }
        else
        {
            ENDING_DATA.oamLength = ARRAY_SIZE(sEndingImageOam_Collecting_Hiragana) + 6;

            for (i = 0; i < ARRAY_SIZE(sEndingImageOam_Collecting_Hiragana); i++)
            {
                ENDING_DATA.oamTypes[i + 6] = sEndingImageOam_Collecting_Hiragana[i].type;
                ENDING_DATA.endingLettersSpawnDelay[i + 6] = sEndingImageOam_Collecting_Hiragana[i].spawnDelay;
                ENDING_DATA.unk_160[i + 6] = sEndingImageOam_Collecting_Hiragana[i].unk_2;

                ENDING_DATA.oamXPositions[i + 6] = sEndingImageOam_Collecting_Hiragana[i].xPosition;
                ENDING_DATA.oamYPositions[i + 6] = sEndingImageOam_Collecting_Hiragana[i].yPosition;

                ENDING_DATA.oamFramePointers[i + 6] = sEndingImageOam_Collecting_Hiragana[i].pFrame;
            }
        }
    }
    else
    {
        if (set == ENDING_IMAGE_OAM_SET_CLEAR_TIME)
        {
            ENDING_DATA.oamLength = ARRAY_SIZE(sEndingImageOam_ClearTime_English) + 6;

            for (i = 0; i < ARRAY_SIZE(sEndingImageOam_ClearTime_English); i++)
            {
                ENDING_DATA.oamTypes[i + 6] = sEndingImageOam_ClearTime_English[i].type;
                ENDING_DATA.endingLettersSpawnDelay[i + 6] = sEndingImageOam_ClearTime_English[i].spawnDelay;
                ENDING_DATA.unk_160[i + 6] = sEndingImageOam_ClearTime_English[i].unk_2;

                ENDING_DATA.oamXPositions[i + 6] = sEndingImageOam_ClearTime_English[i].xPosition;
                ENDING_DATA.oamYPositions[i + 6] = sEndingImageOam_ClearTime_English[i].yPosition;

                ENDING_DATA.oamFramePointers[i + 6] = sEndingImageOam_ClearTime_English[i].pFrame;
            }
        }
        else if (set == ENDING_IMAGE_OAM_SET_YOUR_RATE)
        {
            ENDING_DATA.oamLength = ARRAY_SIZE(sEndingImageOam_YourRate_English) + 6;

            for (i = 0; i < ARRAY_SIZE(sEndingImageOam_YourRate_English); i++)
            {
                ENDING_DATA.oamTypes[i + 6] = sEndingImageOam_YourRate_English[i].type;
                ENDING_DATA.endingLettersSpawnDelay[i + 6] = sEndingImageOam_YourRate_English[i].spawnDelay;
                ENDING_DATA.unk_160[i + 6] = sEndingImageOam_YourRate_English[i].unk_2;

                ENDING_DATA.oamXPositions[i + 6] = sEndingImageOam_YourRate_English[i].xPosition;
                ENDING_DATA.oamYPositions[i + 6] = sEndingImageOam_YourRate_English[i].yPosition;

                ENDING_DATA.oamFramePointers[i + 6] = sEndingImageOam_YourRate_English[i].pFrame;
            }
        }
        else
        {
            ENDING_DATA.oamLength = ARRAY_SIZE(sEndingImageOam_Collecting_English) + 6;

            for (i = 0; i < ARRAY_SIZE(sEndingImageOam_Collecting_English); i++)
            {
                ENDING_DATA.oamTypes[i + 6] = sEndingImageOam_Collecting_English[i].type;
                ENDING_DATA.endingLettersSpawnDelay[i + 6] = sEndingImageOam_Collecting_English[i].spawnDelay;
                ENDING_DATA.unk_160[i + 6] = sEndingImageOam_Collecting_English[i].unk_2;

                ENDING_DATA.oamXPositions[i + 6] = sEndingImageOam_Collecting_English[i].xPosition;
                ENDING_DATA.oamYPositions[i + 6] = sEndingImageOam_Collecting_English[i].yPosition;

                ENDING_DATA.oamFramePointers[i + 6] = sEndingImageOam_Collecting_English[i].pFrame;
            }
        }
    }
}

/**
 * @brief 84ee8 | c8 | Display a line of text of an ending image permanetly
 * 
 * @param line Line
 */
void EndingImageDisplayLinePermanently(u32 line)
{
    s32 i;

    if (ENDING_DATA.language == LANGUAGE_HIRAGANA)
    {
        ENDING_DATA.oamTypes[line] = sEndingImageOam_FullLines_Hiragana[line].type;
        ENDING_DATA.endingLettersSpawnDelay[line] = sEndingImageOam_FullLines_Hiragana[line].spawnDelay;
        ENDING_DATA.unk_160[line] = sEndingImageOam_FullLines_Hiragana[line].unk_2;
        ENDING_DATA.oamXPositions[line] = sEndingImageOam_FullLines_Hiragana[line].xPosition;
        ENDING_DATA.oamYPositions[line] = sEndingImageOam_FullLines_Hiragana[line].yPosition;
        ENDING_DATA.oamFramePointers[line] = sEndingImageOam_FullLines_Hiragana[line].pFrame;
    }
    else
    {
        ENDING_DATA.oamTypes[line] = sEndingImageOam_FullLines_English[line].type;
        ENDING_DATA.endingLettersSpawnDelay[line] = sEndingImageOam_FullLines_English[line].spawnDelay;
        ENDING_DATA.unk_160[line] = sEndingImageOam_FullLines_English[line].unk_2;
        ENDING_DATA.oamXPositions[line] = sEndingImageOam_FullLines_English[line].xPosition;
        ENDING_DATA.oamYPositions[line] = sEndingImageOam_FullLines_English[line].yPosition;
        ENDING_DATA.oamFramePointers[line] = sEndingImageOam_FullLines_English[line].pFrame;
    }

    for (i  = 0; i < ENDING_DATA.oamLength - 6; i++)
        ENDING_DATA.oamTypes[i + 6] = ENDING_OAM_TYPE_NONE;

    ENDING_DATA.oamLength = 6;
}

#ifdef NON_MATCHING
void EndingImageLoadIGTAndPercentageGraphics(void)
{
    // https://decomp.me/scratch/vLTLr

    s32 hoursTens;
    s32 hoursOnes;
    s32 minutesTens;
    s32 minutesOnes;
    s32 secondsTens;
    s32 secondsOnes;

    s32 percentageHundreds;
    s32 percentageTens;
    s32 percentageOnes;

    s32 offset;

    hoursTens = 0;
    hoursOnes = gInGameTimer.hours;

    while (hoursOnes > 9)
    {
        hoursOnes -= 10;
        hoursTens++;
    }

    minutesTens = 0;
    minutesOnes = gInGameTimer.minutes;

    while (minutesOnes > 9)
    {
        minutesOnes -= 10;
        minutesTens++;
    }

    secondsTens = 0;
    secondsOnes = gInGameTimer.seconds;

    while (secondsOnes > 9)
    {
        secondsOnes -= 10;
        secondsTens++;
    }

    if (hoursTens != 0)
    {
        offset = hoursTens * 64;
        DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ, C_32_2_16(DMA_ENABLE, 64 / 2));
        DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x400, C_32_2_16(DMA_ENABLE, 64 / 2));
    }

    offset = hoursOnes * 64;
    DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x040, C_32_2_16(DMA_ENABLE, 64 / 2));
    DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x440, C_32_2_16(DMA_ENABLE, 64 / 2));

    offset = minutesTens * 64;
    DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x0A0, C_32_2_16(DMA_ENABLE, 64 / 2));
    DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x4A0, C_32_2_16(DMA_ENABLE, 64 / 2));

    offset = minutesOnes * 64;
    DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x0E0, C_32_2_16(DMA_ENABLE, 64 / 2));
    DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x4E0, C_32_2_16(DMA_ENABLE, 64 / 2));

    offset = secondsTens * 64;
    DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x140, C_32_2_16(DMA_ENABLE, 64 / 2));
    DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x540, C_32_2_16(DMA_ENABLE, 64 / 2));

    offset = secondsOnes * 64;
    DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x180, C_32_2_16(DMA_ENABLE, 64 / 2));
    DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x580, C_32_2_16(DMA_ENABLE, 64 / 2));

    percentageHundreds = 0;
    percentageTens = 0;
    percentageOnes = ENDING_DATA.completionPercentage;

    while (percentageOnes >= 100)
    {
        percentageOnes -= 100;
        percentageHundreds++;
    }

    while (percentageOnes >= 10)
    {
        percentageOnes -= 10;
        percentageTens++;
    }

    if (percentageHundreds != 0)
    {
        offset = percentageHundreds * 64;
        DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x1C0, C_32_2_16(DMA_ENABLE, 64 / 2));
        DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x5C0, C_32_2_16(DMA_ENABLE, 64 / 2));
    }
    
    if (percentageHundreds != 0 || percentageTens != 0)
    {
        offset = percentageTens * 64;
        DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x200, C_32_2_16(DMA_ENABLE, 64 / 2));
        DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x600, C_32_2_16(DMA_ENABLE, 64 / 2));
    }

    offset = percentageOnes * 64;
    DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x240, C_32_2_16(DMA_ENABLE, 64 / 2));
    DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x640, C_32_2_16(DMA_ENABLE, 64 / 2));
}
#else
NAKED_FUNCTION
void EndingImageLoadIGTAndPercentageGraphics(void)
{
    asm(" \n\
    push {r4, r5, r6, r7, lr} \n\
    mov r7, sl \n\
    mov r6, sb \n\
    mov r5, r8 \n\
    push {r5, r6, r7} \n\
    movs r1, #0 \n\
    ldr r0, lbl_080850c8 @ =gInGameTimer \n\
    ldrb r4, [r0] \n\
    ldr r6, lbl_080850cc @ =sEndingImageNumbersGfx_Upper \n\
    ldr r7, lbl_080850d0 @ =sEndingImageNumbersGfx_Lower \n\
    ldr r2, lbl_080850d4 @ =sNonGameplayRamPointer \n\
    mov sl, r2 \n\
    cmp r4, #9 \n\
    ble lbl_08084fd4 \n\
lbl_08084fcc: \n\
    sub r4, #0xa \n\
    add r1, #1 \n\
    cmp r4, #9 \n\
    bgt lbl_08084fcc \n\
lbl_08084fd4: \n\
    movs r5, #0 \n\
    ldrb r2, [r0, #1] \n\
    lsl r4, r4, #6 \n\
    mov r8, r4 \n\
    cmp r2, #9 \n\
    ble lbl_08084fe8 \n\
lbl_08084fe0: \n\
    sub r2, #0xa \n\
    add r5, #1 \n\
    cmp r2, #9 \n\
    bgt lbl_08084fe0 \n\
lbl_08084fe8: \n\
    movs r3, #0 \n\
    mov ip, r3 \n\
    ldrb r4, [r0, #2] \n\
    lsl r5, r5, #6 \n\
    lsl r2, r2, #6 \n\
    mov sb, r2 \n\
    cmp r4, #9 \n\
    ble lbl_08085002 \n\
lbl_08084ff8: \n\
    sub r4, #0xa \n\
    movs r0, #1 \n\
    add ip, r0 \n\
    cmp r4, #9 \n\
    bgt lbl_08084ff8 \n\
lbl_08085002: \n\
    cmp r1, #0 \n\
    beq lbl_08085024 \n\
    lsl r3, r1, #6 \n\
    ldr r0, lbl_080850d8 @ =0x040000d4 \n\
    add r1, r3, r6 \n\
    str r1, [r0] \n\
    ldr r1, lbl_080850dc @ =0x06010000 \n\
    str r1, [r0, #4] \n\
    ldr r2, lbl_080850e0 @ =0x80000020 \n\
    str r2, [r0, #8] \n\
    ldr r1, [r0, #8] \n\
    add r1, r3, r7 \n\
    str r1, [r0] \n\
    ldr r1, lbl_080850e4 @ =0x06010400 \n\
    str r1, [r0, #4] \n\
    str r2, [r0, #8] \n\
    ldr r0, [r0, #8] \n\
lbl_08085024: \n\
    mov r3, r8 \n\
    ldr r0, lbl_080850d8 @ =0x040000d4 \n\
    add r1, r3, r6 \n\
    str r1, [r0] \n\
    ldr r1, lbl_080850e8 @ =0x06010040 \n\
    str r1, [r0, #4] \n\
    ldr r2, lbl_080850e0 @ =0x80000020 \n\
    str r2, [r0, #8] \n\
    ldr r1, [r0, #8] \n\
    add r1, r3, r7 \n\
    str r1, [r0] \n\
    ldr r1, lbl_080850ec @ =0x06010440 \n\
    str r1, [r0, #4] \n\
    str r2, [r0, #8] \n\
    ldr r1, [r0, #8] \n\
    add r3, r5, #0 \n\
    add r1, r3, r6 \n\
    str r1, [r0] \n\
    ldr r1, lbl_080850f0 @ =0x060100a0 \n\
    str r1, [r0, #4] \n\
    str r2, [r0, #8] \n\
    ldr r1, [r0, #8] \n\
    add r1, r3, r7 \n\
    str r1, [r0] \n\
    ldr r1, lbl_080850f4 @ =0x060104a0 \n\
    str r1, [r0, #4] \n\
    str r2, [r0, #8] \n\
    ldr r1, [r0, #8] \n\
    mov r3, sb \n\
    add r1, r3, r6 \n\
    str r1, [r0] \n\
    ldr r1, lbl_080850f8 @ =0x060100e0 \n\
    str r1, [r0, #4] \n\
    str r2, [r0, #8] \n\
    ldr r1, [r0, #8] \n\
    add r1, r3, r7 \n\
    str r1, [r0] \n\
    ldr r1, lbl_080850fc @ =0x060104e0 \n\
    str r1, [r0, #4] \n\
    str r2, [r0, #8] \n\
    ldr r1, [r0, #8] \n\
    mov r1, ip \n\
    lsl r3, r1, #6 \n\
    add r1, r3, r6 \n\
    str r1, [r0] \n\
    ldr r1, lbl_08085100 @ =0x06010140 \n\
    str r1, [r0, #4] \n\
    str r2, [r0, #8] \n\
    ldr r1, [r0, #8] \n\
    add r1, r3, r7 \n\
    str r1, [r0] \n\
    ldr r1, lbl_08085104 @ =0x06010540 \n\
    str r1, [r0, #4] \n\
    str r2, [r0, #8] \n\
    ldr r1, [r0, #8] \n\
    lsl r3, r4, #6 \n\
    add r1, r3, r6 \n\
    str r1, [r0] \n\
    ldr r1, lbl_08085108 @ =0x06010180 \n\
    str r1, [r0, #4] \n\
    str r2, [r0, #8] \n\
    ldr r1, [r0, #8] \n\
    add r1, r3, r7 \n\
    str r1, [r0] \n\
    ldr r1, lbl_0808510c @ =0x06010580 \n\
    str r1, [r0, #4] \n\
    str r2, [r0, #8] \n\
    ldr r0, [r0, #8] \n\
    movs r1, #0 \n\
    movs r4, #0 \n\
    mov r2, sl \n\
    ldr r0, [r2] \n\
    add r0, #0x99 \n\
    ldrb r5, [r0] \n\
    cmp r5, #0x63 \n\
    ble lbl_08085114 \n\
lbl_080850bc: \n\
    sub r5, #0x64 \n\
    add r1, #1 \n\
    cmp r5, #0x63 \n\
    bgt lbl_080850bc \n\
    b lbl_08085114 \n\
    .align 2, 0 \n\
lbl_080850c8: .4byte gInGameTimer \n\
lbl_080850cc: .4byte sEndingImageNumbersGfx_Upper \n\
lbl_080850d0: .4byte sEndingImageNumbersGfx_Lower \n\
lbl_080850d4: .4byte sNonGameplayRamPointer \n\
lbl_080850d8: .4byte 0x040000d4 \n\
lbl_080850dc: .4byte 0x06010000 \n\
lbl_080850e0: .4byte 0x80000020 \n\
lbl_080850e4: .4byte 0x06010400 \n\
lbl_080850e8: .4byte 0x06010040 \n\
lbl_080850ec: .4byte 0x06010440 \n\
lbl_080850f0: .4byte 0x060100a0 \n\
lbl_080850f4: .4byte 0x060104a0 \n\
lbl_080850f8: .4byte 0x060100e0 \n\
lbl_080850fc: .4byte 0x060104e0 \n\
lbl_08085100: .4byte 0x06010140 \n\
lbl_08085104: .4byte 0x06010540 \n\
lbl_08085108: .4byte 0x06010180 \n\
lbl_0808510c: .4byte 0x06010580 \n\
lbl_08085110: \n\
    sub r5, #0xa \n\
    add r4, #1 \n\
lbl_08085114: \n\
    cmp r5, #9 \n\
    bgt lbl_08085110 \n\
    cmp r1, #0 \n\
    beq lbl_0808514c \n\
    lsl r3, r1, #6 \n\
    ldr r0, lbl_0808513c @ =0x040000d4 \n\
    add r1, r3, r6 \n\
    str r1, [r0] \n\
    ldr r1, lbl_08085140 @ =0x060101c0 \n\
    str r1, [r0, #4] \n\
    ldr r2, lbl_08085144 @ =0x80000020 \n\
    str r2, [r0, #8] \n\
    ldr r1, [r0, #8] \n\
    add r1, r3, r7 \n\
    str r1, [r0] \n\
    ldr r1, lbl_08085148 @ =0x060105c0 \n\
    str r1, [r0, #4] \n\
    str r2, [r0, #8] \n\
    ldr r0, [r0, #8] \n\
    b lbl_08085150 \n\
    .align 2, 0 \n\
lbl_0808513c: .4byte 0x040000d4 \n\
lbl_08085140: .4byte 0x060101c0 \n\
lbl_08085144: .4byte 0x80000020 \n\
lbl_08085148: .4byte 0x060105c0 \n\
lbl_0808514c: \n\
    cmp r4, #0 \n\
    beq lbl_0808516e \n\
lbl_08085150: \n\
    lsl r3, r4, #6 \n\
    ldr r0, lbl_0808519c @ =0x040000d4 \n\
    add r1, r3, r6 \n\
    str r1, [r0] \n\
    ldr r1, lbl_080851a0 @ =0x06010200 \n\
    str r1, [r0, #4] \n\
    ldr r2, lbl_080851a4 @ =0x80000020 \n\
    str r2, [r0, #8] \n\
    ldr r1, [r0, #8] \n\
    add r1, r3, r7 \n\
    str r1, [r0] \n\
    ldr r1, lbl_080851a8 @ =0x06010600 \n\
    str r1, [r0, #4] \n\
    str r2, [r0, #8] \n\
    ldr r0, [r0, #8] \n\
lbl_0808516e: \n\
    lsl r3, r5, #6 \n\
    ldr r0, lbl_0808519c @ =0x040000d4 \n\
    add r1, r3, r6 \n\
    str r1, [r0] \n\
    ldr r1, lbl_080851ac @ =0x06010240 \n\
    str r1, [r0, #4] \n\
    ldr r2, lbl_080851a4 @ =0x80000020 \n\
    str r2, [r0, #8] \n\
    ldr r1, [r0, #8] \n\
    add r1, r3, r7 \n\
    str r1, [r0] \n\
    ldr r1, lbl_080851b0 @ =0x06010640 \n\
    str r1, [r0, #4] \n\
    str r2, [r0, #8] \n\
    ldr r0, [r0, #8] \n\
    pop {r3, r4, r5} \n\
    mov r8, r3 \n\
    mov sb, r4 \n\
    mov sl, r5 \n\
    pop {r4, r5, r6, r7} \n\
    pop {r0} \n\
    bx r0 \n\
    .align 2, 0 \n\
lbl_0808519c: .4byte 0x040000d4 \n\
lbl_080851a0: .4byte 0x06010200 \n\
lbl_080851a4: .4byte 0x80000020 \n\
lbl_080851a8: .4byte 0x06010600 \n\
lbl_080851ac: .4byte 0x06010240 \n\
lbl_080851b0: .4byte 0x06010640 \n\
    ");
}
#endif

/**
 * @brief 851b4 | 164 | V-blank code for gallery, ending image and credits
 * 
 */
void GalleryVBlank(void)
{
    u32 buffer;
    u32 bgPos;

    DMA_SET(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / sizeof(u32));

    if (ENDING_DATA.unk_6 == 1)
    {
        DMA_SET(3, ENDING_DATA.creditLineTilemap_1, VRAM_BASE + ENDING_DATA.creditLineOffset_1,
            DMA_ENABLE << 16 | ARRAY_SIZE(ENDING_DATA.creditLineTilemap_1));
        DMA_SET(3, ENDING_DATA.creditLineTilemap_2, VRAM_BASE + ENDING_DATA.creditLineOffset_2,
            DMA_ENABLE << 16 | ARRAY_SIZE(ENDING_DATA.creditLineTilemap_2));

        buffer = 0;
        DMA_SET(3, &buffer, VRAM_BASE + 0x800 + ENDING_DATA.creditLineOffset_1,
            (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | ARRAY_SIZE(ENDING_DATA.creditLineTilemap_1) / 2);
        buffer = 0;
        DMA_SET(3, &buffer, VRAM_BASE + 0x800 + ENDING_DATA.creditLineOffset_2,
            (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | ARRAY_SIZE(ENDING_DATA.creditLineTilemap_2) / 2);
    }
    else if (ENDING_DATA.unk_6 != 0)
    {
        DMA_SET(3, ENDING_DATA.creditLineTilemap_1, VRAM_BASE + 0x800 + ENDING_DATA.creditLineOffset_1,
            DMA_ENABLE << 16 | ARRAY_SIZE(ENDING_DATA.creditLineTilemap_1));
        DMA_SET(3, ENDING_DATA.creditLineTilemap_2, VRAM_BASE + 0x800 + ENDING_DATA.creditLineOffset_2,
            DMA_ENABLE << 16 | ARRAY_SIZE(ENDING_DATA.creditLineTilemap_2));

        buffer = 0;
        DMA_SET(3, &buffer, VRAM_BASE + ENDING_DATA.creditLineOffset_1,
            (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | ARRAY_SIZE(ENDING_DATA.creditLineTilemap_1) / 2);
        buffer = 0;
        DMA_SET(3, &buffer, VRAM_BASE + ENDING_DATA.creditLineOffset_2,
            (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | ARRAY_SIZE(ENDING_DATA.creditLineTilemap_2) / 2);
    }

    write16(REG_DISPCNT, ENDING_DATA.dispcnt);
    write16(REG_BLDCNT, ENDING_DATA.bldcnt);

    write16(REG_BLDALPHA, gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_BG0VOFS, bgPos = gBg0YPosition / 16 & 0x1FF);
    write16(REG_BG1VOFS, bgPos);
    write16(REG_BG2VOFS, gBg2YPosition / 16 & 0x1FF);
    write16(REG_BG3VOFS, gBg3YPosition / 16 & 0x1FF);
}

/**
 * @brief 85318 | a8 | V-blank code for the end screen
 * 
 */
void EndScreenVBlank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / sizeof(u32));

    write16(REG_DISPCNT, ENDING_DATA.dispcnt);
    write16(REG_BLDCNT, ENDING_DATA.bldcnt);

    write16(REG_BLDALPHA, gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_BG1HOFS, gBg1XPosition & 0x1FF);
    write16(REG_BG2HOFS, gBg2XPosition & 0x1FF);
    write16(REG_BG3HOFS, gBg3XPosition & 0x1FF);
}

/**
 * @brief 853c0 | a8 | V-blank code for the unlocked options
 * 
 */
void UnlockedOptionsVBlank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / sizeof(u32));

    write16(REG_DISPCNT, ENDING_DATA.dispcnt);
    write16(REG_BLDCNT, ENDING_DATA.bldcnt);

    write16(REG_BLDALPHA, gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_WIN0H, ENDING_DATA.oamXPositions[0] << 8 | ENDING_DATA.oamXPositions[1]);
    write16(REG_WIN0V, ENDING_DATA.oamYPositions[0] << 8 | ENDING_DATA.oamYPositions[1]);
}

/**
 * @brief 85464 | 1f8 | Initializes the credits
 * 
 */
void CreditsInit(void)
{
    u32 zero;

    write16(REG_IME, FALSE);
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) & ~IF_HBLANK);
    write16(REG_IF, IF_HBLANK);

    write16(REG_IME, TRUE);
    write16(REG_DISPCNT, 0);

    write16(REG_IME, FALSE);
    CallbackSetVBlank(GalleryVBlank);
    write16(REG_IME, TRUE);

    zero = 0;
    DMA_SET(3, &zero, &gNonGameplayRAM, (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | sizeof(gNonGameplayRAM) / 4);

    ClearGfxRam();

    LZ77UncompVRAM(sCreditsChozoWallBackgroundGfx, VRAM_BASE);
    LZ77UncompVRAM(sCreditsChozoWallBackgroundTileTable, VRAM_BASE + 0xE000);
    LZ77UncompVRAM(sCreditsChozoWallBottomTileTable, VRAM_BASE + 0xD800);
    LZ77UncompVRAM(sCreditsCharactersGfx, VRAM_BASE + 0x8000);

    DMA_SET(3, sCreditsChozoWallPAL, PALRAM_BASE, DMA_ENABLE << 16 | sizeof(sCreditsChozoWallPAL) / 2);
    DMA_SET(3, sCreditsCharactersPAL, PALRAM_BASE + 0x1A0, DMA_ENABLE << 16 | sizeof(sCreditsCharactersPAL) / 2);

    write16(REG_BG0CNT, 0x1E08);
    write16(REG_BG1CNT, 0x1F09);
    write16(REG_BG2CNT, 0x9C02);
    write16(REG_BG3CNT, 0x9A0B);

    gNextOamSlot = 0;
    ResetFreeOam();

    gBg0XPosition = 0;
    gBg0YPosition = 0x1000;
    gBg1XPosition = 0;
    gBg1YPosition = 0x1000;
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    write16(REG_BG0HOFS, 0);
    write16(REG_BG0VOFS, 0x1000);
    write16(REG_BG1HOFS, 4);
    write16(REG_BG1VOFS, 0x1000);
    write16(REG_BG2HOFS, 0);
    write16(REG_BG2VOFS, 0);
    write16(REG_BG3HOFS, 0);
    write16(REG_BG3VOFS, 0);

    ENDING_DATA.unk_E = 0x80;
    ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;
    ENDING_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

    gWrittenToBLDALPHA_L = 16;
    gWrittenToBLDALPHA_H = 0;
    gWrittenToBLDY_NonGameplay = 16;

    GalleryVBlank();
    PlayMusic(MUSIC_CREDITS, 0);
}

/**
 * @brief 8565c | 398 | Displays a credit line
 * 
 * @param line Line
 * @return u8 To document
 */
u8 CreditsDisplayLine(u32 line)
{
    u8 i;
    s32 tile;
    u32 ret_0;
    u32 ret_1;
    u8 tilemapOffset;
    const struct CreditsEntry* pCredits;

    pCredits = sCredits;
    pCredits += line;
    
    for (i = 0; i < ARRAY_SIZE(ENDING_DATA.creditLineTilemap_1); i++)
    {
        ENDING_DATA.creditLineTilemap_1[i] = 0;
        ENDING_DATA.creditLineTilemap_2[i] = 0;
    }

    if (pCredits->type == CREDIT_LINE_TYPE_BLUE)
        tile = 14 << 12;
    else if (pCredits->type == CREDIT_LINE_TYPE_RED)
        tile = 15 << 12;
    else
        tile = 13 << 12;

    ret_0 = 0;
    ret_1 = 0;
    i = 0;
    
    switch (pCredits->type)
    {
        case CREDIT_LINE_TYPE_BLUE:
        case CREDIT_LINE_TYPE_RED:
        case CREDIT_LINE_TYPE_WHITE_SMALL:
            for (tilemapOffset = 0; tilemapOffset < ARRAY_SIZE(ENDING_DATA.creditLineTilemap_1) - 2; tilemapOffset++)
            {
                if (pCredits->text[tilemapOffset] == 0)
                    break;
            }

            if (tilemapOffset & 1)
            {
                ret_1 = 0x80;
                tilemapOffset--;
            }

            tilemapOffset = (0x1E - tilemapOffset) >> 1;

            while (TRUE)
            {
                if (pCredits->text[i] == 0)
                    break;
                
                if ((u8)(pCredits->text[i] - 0x41) < 0x1A)
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = pCredits->text[i] + (tile - 0x40);
                }
                else if ((u8)(pCredits->text[i] - 0x61) < 0x1A)
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = pCredits->text[i] + (tile - 0x41);
                }
                else if (pCredits->text[i] == '.')
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = tile + 0x1B;
                }
                else if (pCredits->text[i] == ',')
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = tile + 0x1C;
                }
                else if (pCredits->text[i] == '&')
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = tile + 0x1D;
                }

                i++;
                tilemapOffset++;
            }
            ret_0 = 1;
            break;

        case CREDIT_LINE_TYPE_END:
            ret_0 = 9;
            break;

        case CREDIT_LINE_TYPE_ALL_RIGHTS:
            for (i = 0; i < 20; i++)
                ENDING_DATA.creditLineTilemap_1[i + 5] = 0xC0 + i + tile;
            ret_0 = 1;
            ret_1 = 0x10;
            break;

        case CREDIT_LINE_TYPE_THE_COPYRIGHT:
            for (i = 0; i < 20; i++)
                ENDING_DATA.creditLineTilemap_1[i + 5] = 0xE0 + i + tile;
            ret_0 = 1;
            break;

        case 5:
            ret_0 = 1;
            break;

        case CREDIT_LINE_TYPE_SCENARIO:
            for (i = 0; i < 20; i++)
                ENDING_DATA.creditLineTilemap_1[i + 5] = 0x100 + i + tile;
            ret_0 = 1;
            break;

        case CREDIT_LINE_TYPE_RESERVED:
            for (i = 0; i < 20; i++)
                ENDING_DATA.creditLineTilemap_1[i + 5] = 0x120 + i + tile;
            ret_0 = 1;
            break;

        case CREDIT_LINE_TYPE_WHITE_BIG:
            for (tilemapOffset = 0; tilemapOffset < 0x1E; tilemapOffset++)
            {
                if (pCredits->text[tilemapOffset] == 0)
                    break;
            }

            if (tilemapOffset & 1)
            {
                ret_1 = 0x80;
                tilemapOffset--;
            }

            tilemapOffset = (0x1E - tilemapOffset) >> 1;

            while (TRUE)
            {
                if (pCredits->text[i] == 0)
                    break;
                
                if ((u8)(pCredits->text[i] - 0x41) < 0x1A)
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = pCredits->text[i] + (tile - 1);
                    ENDING_DATA.creditLineTilemap_2[tilemapOffset] = pCredits->text[i] + (tile + 0x1F);
                }
                else if ((u8)(pCredits->text[i] - 0x61) < 0x1A)
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = pCredits->text[i] + (tile + 0x1F);
                    ENDING_DATA.creditLineTilemap_2[tilemapOffset] = pCredits->text[i] + (tile + 0x3F);
                }
                else if (pCredits->text[i] == '.')
                {
                    ENDING_DATA.creditLineTilemap_2[tilemapOffset] = tile + 0x7B;
                }
                else if (pCredits->text[i] == ',')
                {
                    ENDING_DATA.creditLineTilemap_2[tilemapOffset] = tile + 0x7C;
                }
                else if (pCredits->text[i] == '-')
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = tile + 0x5A;
                }
                else if (pCredits->text[i] == '+')
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = tile + 0x9A;
                    ENDING_DATA.creditLineTilemap_2[tilemapOffset] = tile + 0xBA;
                }

                i++;
                tilemapOffset++;
            }
            ret_0 = 2;
            break;
    }

    return ret_0 | ret_1;
}

/**
 * @brief 859f4 | 18c | Displays the credits
 * 
 * @return u8 bool, ended
 */
u8 CreditsDisplay(void)
{
    u8 ended;
    s32 temp;
    u8 result;

    u8 unk_0;
    u8 unk_1;

    if (ENDING_DATA.unk_1)
    {
        ended = FALSE;
        switch (ENDING_DATA.timer++)
        {
            case 464:
                ENDING_DATA.unk_1++;
                break;

            case 528:
                ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_SECOND_TARGET_PIXEL;
                gWrittenToBLDY_NonGameplay = 0;
                ENDING_DATA.unk_1++;
                break;

            case 560:
                ENDING_DATA.dispcnt = DCNT_BG2 | DCNT_BG3;
                ENDING_DATA.bldcnt = 0;
                ended = TRUE;
                break;
        }

        if (ENDING_DATA.unk_1 == 2)
        {
            if (!(ENDING_DATA.endScreenTimer++ & 3))
            {
                if (gWrittenToBLDY_NonGameplay)
                    gWrittenToBLDY_NonGameplay--;
            }
        }
        else if (ENDING_DATA.unk_1 == 3)
        {
            if (ENDING_DATA.timer & 1)
            {
                if (gWrittenToBLDALPHA_L)
                {
                    gWrittenToBLDALPHA_L--;
                    gWrittenToBLDALPHA_H = 16 - gWrittenToBLDALPHA_L;
                }
                else
                    ENDING_DATA.unk_1++;
            }
        }

        return ended;
    }

    if (ENDING_DATA.unk_E > 127)
    {
        ENDING_DATA.unk_E &= 127;

        if (ENDING_DATA.unk_8 == ENDING_DATA.unk_A)
        {
            ended = CreditsDisplayLine(ENDING_DATA.currentCreditLine);
            unk_0 = ended & 0xF0;
            ended = ended & 0xF;

            if (ended == 0x9)
            {
                ENDING_DATA.unk_1 = 1;
            }
            else
            {
                temp = ENDING_DATA.unk_A * 0x40 + 0x500;
                if (temp > 0x7FF)
                    temp &= 0x7FF;

                ENDING_DATA.creditLineOffset_1 = temp + 0xF000;

                temp = ENDING_DATA.unk_A * 0x40 + 0x540;
                if (temp > 0x7FF)
                    temp &= 0x7FF;

                ENDING_DATA.creditLineOffset_2 = temp + 0xF000;

                ENDING_DATA.unk_A += ended;
                ENDING_DATA.currentCreditLine++;
                ENDING_DATA.unk_6++;

                if (unk_0 == 0x80)
                    ENDING_DATA.unk_6++;
            }
        }

        ENDING_DATA.unk_8++;
    }

    ENDING_DATA.unk_E += 7;
    gBg0YPosition += 7;
    return FALSE;
}

/**
 * @brief 85b80 | 90 | Handles the scrolling wall part of the after credits
 * 
 * @return u8 bool, ended
 */
u8 CreditsChozoWallMovement(void)
{
    u8 ended;

    ended = FALSE;

    switch (ENDING_DATA.timer++)
    {
        case 0:
            // Load bottom graphics
            LZ77UncompVRAM(sCreditsChozoWallBottomGfx, VRAM_BASE + 0x8000);
            break;

        case 1:
            // Enable background scrolling
            ENDING_DATA.unk_1++;
            break;

        case 512:
            write16(REG_BG1HOFS, 0);
            ended = TRUE;
            break;
    }

    if (ENDING_DATA.unk_1)
    {
        gBg2YPosition += 8;
        gBg3YPosition += 8;
    
        // Check end scrolling
        if (gBg2YPosition == BLOCK_SIZE * 56)
            ENDING_DATA.unk_1 = FALSE; // Disable background scrolling
    }

    return ended;
}

/**
 * @brief 85c10 | 1f8 | Handles the zooming wall part of the after credits 
 * 
 * @return u8 bool, ended (0/2)
 */
u8 CreditsChozoWallZoom(void)
{
    u8 ended;

    ended = FALSE;

    switch (ENDING_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sCreditsChozoWallBottomZoomedGfx, VRAM_BASE);
            DMA_SET(3, sCreditsChozoWallPAL, PALRAM_BASE, DMA_ENABLE << 16 | ARRAY_SIZE(sCreditsChozoWallPAL));
            gBg0YPosition = 0;
            gWrittenToBLDALPHA_L = 0;
            gWrittenToBLDALPHA_H = 16;
            break;

        case 1:
            LZ77UncompVRAM(sCreditsChozoWallBottomZoomedTileTable, VRAM_BASE + 0xF000);
            write16(REG_BG0CNT, 0x1E00);
            ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG2 | DCNT_BG3;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;

            ENDING_DATA.unk_1++;
            break;

        case 192:
            ENDING_DATA.dispcnt = DCNT_BG0;
            ENDING_DATA.bldcnt = 0;
            ENDING_DATA.unk_1++;
            gBg1YPosition = 0;
            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            break;

        case 193:
            LZ77UncompVRAM(sCreditsChozoDrawingGfx, VRAM_BASE + 0x8000);
            break;

        case 194:
            LZ77UncompVRAM(sCreditsChozoDrawingTileTable, VRAM_BASE + 0xF800);
            ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG1;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG1_SECOND_TARGET_PIXEL;

            ENDING_DATA.unk_1++;
            break;

        case 800:
            ENDING_DATA.dispcnt = DCNT_BG1;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
                BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            ENDING_DATA.unk_1++;
            break;

        case 960:
            ended = 2;
            break;
    }

    if (ENDING_DATA.unk_1 == 1)
    {
        if (!(ENDING_DATA.timer & 7))
        {
            if (gWrittenToBLDALPHA_L < 16)
                gWrittenToBLDALPHA_L++;

            if (gWrittenToBLDALPHA_H != 0)
                gWrittenToBLDALPHA_H--;
        }
    }
    else if (ENDING_DATA.unk_1 == 3)
    {
        if (!(ENDING_DATA.timer & 7))
        {
            if (gWrittenToBLDALPHA_L != 0)
                gWrittenToBLDALPHA_L--;

            if (gWrittenToBLDALPHA_H < 16)
                gWrittenToBLDALPHA_H++;
        }
    }
    else if (ENDING_DATA.unk_1 == 4)
    {
        if (!(ENDING_DATA.timer & 7))
        {
            if (gWrittenToBLDY_NonGameplay < 16)
                gWrittenToBLDY_NonGameplay++;
        }
    }

    return ended;
}

/**
 * @brief 85e08 | 248 | Initializes the end screen (samus posing)
 * 
 */
void EndScreenInit(void)
{
    u32 zero;

    write16(REG_IME, FALSE);
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) & ~IF_HBLANK);
    write16(REG_IF, IF_HBLANK);

    write16(REG_IME, TRUE);
    write16(REG_DISPCNT, 0);

    write16(REG_IME, FALSE);
    CallbackSetVBlank(EndScreenVBlank);
    write16(REG_IME, TRUE);

    LZ77UncompVRAM(sEndingSamusPosingSpaceBackgroundGfx, VRAM_BASE + 0x3000);
    LZ77UncompVRAM(sEndingLightGfx, VRAM_BASE + 0xB000);
    LZ77UncompVRAM(sEndingSamusPosingGfx_1, VRAM_BASE);
    LZ77UncompVRAM(sEndingSamusPosingGfx_2, VRAM_BASE + 0x8000);

    LZ77UncompVRAM(sEndingSamusPosingSpaceBackgroundTileTable, VRAM_BASE + 0xF800);
    LZ77UncompVRAM(sEndingLightTileTable, VRAM_BASE + 0xF000);
    LZ77UncompVRAM(sEndingSamusPosingTileTable_1, VRAM_BASE + 0xD000);
    LZ77UncompVRAM(sEndingSamusPosingTileTable_2, VRAM_BASE + 0xE000);

    BitFill(3, 0, VRAM_BASE + 0xD800, 0x800, 32);
    BitFill(3, 0, VRAM_BASE + 0xE800, 0x800, 32);

    DMA_SET(3, sEndingPosingPAL, PALRAM_BASE, DMA_ENABLE << 16 | ARRAY_SIZE(sEndingPosingPAL));

    write16(REG_BG0CNT, 0x1E08);
    write16(REG_BG1CNT, 0x5A01);
    write16(REG_BG2CNT, 0x5C0A);
    write16(REG_BG3CNT, 0x1F03);
    
    gNextOamSlot = 0;
    ResetFreeOam();
    DMA_SET(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / sizeof(u32));

    gBg0XPosition = 0;
    gBg0YPosition = 0;
    gBg1XPosition = 0x100;
    gBg1YPosition = 0;
    gBg2XPosition = 0x100;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    write16(REG_BG0HOFS, 0);
    write16(REG_BG0VOFS, 0);
    write16(REG_BG1HOFS, 0x100);
    write16(REG_BG1VOFS, 0);
    write16(REG_BG2HOFS, 0x100);
    write16(REG_BG2VOFS, 0);
    write16(REG_BG3HOFS, 0);
    write16(REG_BG3VOFS, 0);

    zero = 0;
    DMA_SET(3, &zero, &gNonGameplayRAM, (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | sizeof(gNonGameplayRAM) / 4);

    ENDING_DATA.endingNumber = ChozodiaEscapeGetItemCountAndEndingNumber() & 7;
    ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ;

    gWrittenToBLDALPHA_L = 16;
    gWrittenToBLDALPHA_H = 0;
    gWrittenToBLDY_NonGameplay = 16;

    EndScreenVBlank();
}

/**
 * @brief 86050 | 764 | Handles the entire samus posing sequence
 * 
 * @return u8 bool, ended
 */
u8 EndScreenSamusPosing(void)
{
    u8 ended;
    u32 temp;

    ended = FALSE;

    ENDING_DATA.endScreenTimer++;

    switch (ENDING_DATA.unk_1)
    {
        case 4:
            if (ENDING_DATA.timer++ <= 7)
                break;

        case 0:
            gBg1XPosition += 8;
            if (gBg1XPosition >= BLOCK_SIZE * 8)
            {
                gBg1XPosition = 0;
                ENDING_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                    BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;
                ENDING_DATA.timer = 0;
                ENDING_DATA.unk_1++;
            }
            break;

        case 1:
        case 3:
        case 5:
            if (ENDING_DATA.timer++ > 24)
            {
                ENDING_DATA.oamTypes[0] = 1;
                ENDING_DATA.timer = 0;
                ENDING_DATA.unk_1++;
            }
            break;

        case 2:
        case 6:
            if (ENDING_DATA.timer++ > 7)
            {
                gBg2XPosition += 8;
                if (gBg2XPosition >= BLOCK_SIZE * 8)
                {
                    gBg2XPosition = BLOCK_SIZE * 8;
                    ENDING_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                        BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;
                    ENDING_DATA.timer = 0;
                    ENDING_DATA.unk_1++;
                }
            }
            break;

        case 7:
            if (ENDING_DATA.timer++ > 64)
            {
                ENDING_DATA.oamTypes[0] = 1;
                ENDING_DATA.timer = 0;
                ENDING_DATA.unk_1++;
            }
            break;

        case 8:
            if (ENDING_DATA.timer++ > 23)
            {
                if (gBg1XPosition >= 10)
                {
                    gBg1XPosition -= 10;
                }
                else
                {
                    gBg1XPosition = 0;
                    ENDING_DATA.timer = 0;
                    ENDING_DATA.unk_1++;
                }
            }
            break;

        case 9:
            if (ENDING_DATA.timer++ > 31)
            {
                ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_BG2 | DCNT_BG3;
                
                if (ENDING_DATA.endingNumber != 0)
                {
                    ENDING_DATA.oamTypes[0] = 3;
                }
                else
                {
                    ENDING_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                        BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;
                    ENDING_DATA.oamTypes[0] = 1;
                }
                
                ENDING_DATA.timer = 0;
                ENDING_DATA.unk_1++;
            }
            break;

        case 10:
            if (ENDING_DATA.timer++ > 288)
                ENDING_DATA.oamTypes[1] = 32;
            break;
    }

    switch (ENDING_DATA.oamTypes[0])
    {
        case 1:
            if (ENDING_DATA.endScreenTimer & 1)
            {
                if (gWrittenToBLDALPHA_L != 0)
                    gWrittenToBLDALPHA_L--;
                else
                {
                    ENDING_DATA.oamTypes[0] = 0;
                    ENDING_DATA.oamTypes[1]++;
                }

                gWrittenToBLDALPHA_H = 16 - gWrittenToBLDALPHA_L;
            }
            break;

        case 2:
            if (ENDING_DATA.endScreenTimer & 3)
                break;

            if (gWrittenToBLDALPHA_L < 16)
                gWrittenToBLDALPHA_L++;
            else
            {
                ENDING_DATA.oamTypes[0] = 0;
                ENDING_DATA.oamTypes[1]++;
            }
            break;

        case 3:
            ++ENDING_DATA.unk_160[0];
            temp = ENDING_DATA.unk_160[0];
            if ((u8)temp >= 16)
            {
                ENDING_DATA.unk_160[0] = 0;
                ENDING_DATA.oamTypes[1] = 16;
                break;
            }
            DMA_SET(3, sEndingWhitePalPointers[(u8)temp / 4],
                PALRAM_BASE, DMA_ENABLE << 16 | ARRAY_SIZE(sEndingPosingPAL_White1));
            break;

        case 4:
            if (!(ENDING_DATA.endScreenTimer & 1))
                break;

            if (gWrittenToBLDY_NonGameplay < 16)
                gWrittenToBLDY_NonGameplay++;
            else
                ENDING_DATA.oamTypes[1]++;
            break;

        case 5:
            if (ENDING_DATA.endScreenTimer & 3)
                break;

            if (gWrittenToBLDY_NonGameplay)
                gWrittenToBLDY_NonGameplay--;
            else
            {
                ENDING_DATA.oamTypes[0] = 0;
                ENDING_DATA.oamTypes[1]++;
            }
            break;
    }

    switch (ENDING_DATA.oamTypes[1])
    {
        case 1:
            write16(REG_BG1CNT, 0x5A02);
            write16(REG_BG2CNT, 0x5C09);

            LZ77UncompVRAM(sEndingSamusPosingGfx_3, VRAM_BASE);
            LZ77UncompVRAM(sEndingSamusPosingTileTable_3, VRAM_BASE + 0xD000);

            ENDING_DATA.bldcnt = 0;
            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            gBg1XPosition = BLOCK_SIZE * 4;
            ENDING_DATA.oamTypes[1]++;
            break;

        case 3:
            write16(REG_BG1CNT, 0x5A01);
            write16(REG_BG2CNT, 0x5C0A);

            LZ77UncompVRAM(sEndingSamusPosingGfx_4, VRAM_BASE + 0x8000);
            LZ77UncompVRAM(sEndingSamusPosingTileTable_4, VRAM_BASE + 0xE000);

            ENDING_DATA.bldcnt = 0;
            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            gBg2XPosition = BLOCK_SIZE * 4;
            ENDING_DATA.oamTypes[1]++;
            break;

        case 5:
            write16(REG_BG1CNT, 0x5A02);
            write16(REG_BG2CNT, 0x5C09);

            LZ77UncompVRAM(sEndingSamusPosingGfx_5, VRAM_BASE);
            LZ77UncompVRAM(sEndingSamusPosingTileTable_5, VRAM_BASE + 0xD000);

            ENDING_DATA.bldcnt = 0;
            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            gBg1XPosition = BLOCK_SIZE * 4;
            ENDING_DATA.oamTypes[1]++;
            break;

        case 7:
            write16(REG_BG1CNT, 0x5A01);
            write16(REG_BG2CNT, 0x5C0A);

            if (ENDING_DATA.endingNumber == 0)
            {
                LZ77UncompVRAM(sEndingSamusPosingFullSuitGfx, VRAM_BASE + 0x8000);
                LZ77UncompVRAM(sEndingSamusPosingFullSuitTileTable, VRAM_BASE + 0xE000);
            }
            else if (ENDING_DATA.endingNumber == 1)
            {
                LZ77UncompVRAM(sEndingSamusPosingHelmetOffGfx, VRAM_BASE + 0x8000);
                LZ77UncompVRAM(sEndingSamusPosingHelmetOffTileTable, VRAM_BASE + 0xE000);
            }
            else
            {
                LZ77UncompVRAM(sEndingSamusPosingSuitlessGfx, VRAM_BASE + 0x8000);
                LZ77UncompVRAM(sEndingSamusPosingSuitlessTileTable, VRAM_BASE + 0xE000);
            }

            ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_BG3;
            ENDING_DATA.bldcnt = 0;
            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            gBg2XPosition = 0;

            ENDING_DATA.oamTypes[1]++;
            break;

        case 9:
            ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG2 | DCNT_BG3;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;
            
            gWrittenToBLDALPHA_L = 0;
            gWrittenToBLDALPHA_H = 16;
            ENDING_DATA.oamTypes[0] = 2;
            ENDING_DATA.oamTypes[1]++;
            break;

        case 16:
            ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_BG2 | DCNT_BG3;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;
            
            ENDING_DATA.oamTypes[0]++;
            ENDING_DATA.oamTypes[1]++;
            break;

        case 18:
            ENDING_DATA.dispcnt = DCNT_BG2 | DCNT_BG3;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
                BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;
            
            ENDING_DATA.oamTypes[0]++;
            ENDING_DATA.oamTypes[1]++;
            break;

        case 19:
            DMA_SET(3, sEndingPosingPAL, PALRAM_BASE, DMA_ENABLE << 16 | 0x50);
            ENDING_DATA.oamTypes[1]++;
            break;

        case 32:
            ENDING_DATA.dispcnt = DCNT_BG2 | DCNT_BG3;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
                BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            ended++;
            break;
    }

    if (!(ENDING_DATA.endScreenTimer & 7))
        gBg3XPosition++;

    return ended;
}

/**
 * @brief 867b4 | 29c | Initiliazes the ending image sequence
 * 
 */
void EndingImageInit(void)
{
    u32 zero;
    u32 endingNumber;
    u32 part1;
    u32 part2;
    u32 part3;
    u32 part4;
    u32 part5;
    u32 pen;
    u32 mask;

    write16(REG_IME, FALSE);
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) & ~IF_HBLANK);
    write16(REG_IF, IF_HBLANK);
    write16(REG_IME, TRUE);
    write16(REG_DISPCNT, 0);
    write16(REG_IME, FALSE);

    CallbackSetVBlank(GalleryVBlank);
    write16(REG_IME, TRUE);

    zero = 0;
    DMA_SET(3, &zero, &gNonGameplayRAM, (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | sizeof(gNonGameplayRAM) / 4);

    pen = ChozodiaEscapeGetItemCountAndEndingNumber();

    mask = 0xFF;
    // TODO figure out how PEN is structured
    part1 = pen >> 0x18;
    part2 = (pen >> 0x10) & mask;

    part3 = (pen >> 0xC) & 0xF;
    part4 = (pen >> 0x8) & 0xF;
    part5 = (pen >> 0x4) & 0xF;

    endingNumber = pen & 0xF;
        
    LZ77UncompVRAM(sEndingImagesTopGfxPointers[endingNumber], VRAM_BASE);
    LZ77UncompVRAM(sEndingImagesBottomGfxPointers[endingNumber], VRAM_BASE + 0x8000);
    LZ77UncompVRAM(sEndingImagesTopTileTablePointers[endingNumber], VRAM_BASE + 0xE000);
    LZ77UncompVRAM(sEndingImagesHalfTileTablePointers[endingNumber], VRAM_BASE + 0xF800);
    BitFill(3, 0x4FF04FF, VRAM_BASE + 0xE800, 0x800, 0x20);
    DMA_SET(3, sEndingImagesPalPointers[endingNumber], PALRAM_BASE, DMA_ENABLE << 16 | 0x100);

    ENDING_DATA.completionPercentage = part1 + part2 + part3 + part4 + part5;

    LZ77UncompVRAM(sEndingImageNumbersMiscGfx, VRAM_OBJ);

    ENDING_DATA.language = gLanguage;
    if (gLanguage > LANGUAGE_ENGLISH)
        ENDING_DATA.language = LANGUAGE_ENGLISH;

    if (ENDING_DATA.language == LANGUAGE_HIRAGANA)
        LZ77UncompVRAM(sEndingImageTextJapGfx, VRAM_BASE + 0x11000);
    else
        LZ77UncompVRAM(sEndingImageTextGfx, VRAM_BASE + 0x11000);

    DMA_SET(3, sEndingImageTextPAL, PALRAM_OBJ, DMA_ENABLE << 16 | sizeof(sEndingImageTextPAL) / 2);

    EndingImageLoadIGTAndPercentageGraphics();
    write16(REG_BG0CNT, 0x9C00);
    write16(REG_BG1CNT, 0x9E09);

    gNextOamSlot = 0;
    ResetFreeOam();

    gBg0XPosition = 0;
    gBg0YPosition = 0x1000;
    gBg1XPosition = 0;
    gBg1YPosition = 0x1000;
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    write16(REG_BG0HOFS, 0);
    write16(REG_BG0VOFS, 0);
    write16(REG_BG1HOFS, 0);
    write16(REG_BG1VOFS, 0);
    write16(REG_BG2HOFS, 0);
    write16(REG_BG2VOFS, 0);
    write16(REG_BG3HOFS, 0);
    write16(REG_BG3VOFS, 0);

    ENDING_DATA.dispcnt = DCNT_OBJ | DCNT_BG0 | DCNT_BG1;
    ENDING_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET |
        BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

    gWrittenToBLDALPHA_L = 16;
    gWrittenToBLDALPHA_H = 0;
    gWrittenToBLDY_NonGameplay = 16;

    GalleryVBlank();
}

/**
 * @brief 86a50 | 23c | Display the text on an ending image
 * 
 */
void EndingImageDisplayText(void)
{
    u16* dst;
    const u16* src;
    s32 i;
    s32 nextSlot;
    s32 currSlot;
    u16 part;
    s32 palette;

    dst = (u16*)gOamData;
    nextSlot = 0;
    currSlot = 0;

    for (i = 0; i < ENDING_DATA.oamLength; i++)
    {
        if (ENDING_DATA.oamTypes[i] == ENDING_OAM_TYPE_NONE || ENDING_DATA.oamTypes[i] == ENDING_OAM_TYPE_CHAR)
            continue;

        if (ENDING_DATA.unk_160[i] < 64)
            ENDING_DATA.unk_160[i]++;

        palette = 0;
        if (i > 5)
        {
            if (ENDING_DATA.unk_160[i] < 4)
                palette = 11;
            else if (ENDING_DATA.unk_160[i] < 8)
                palette = 12;
            else if (ENDING_DATA.unk_160[i] < 12)
                palette = 13;
        }
        else if (i == 5)
        {
            ENDING_DATA.unk_160[i] &= 0x3F;
            palette = sEndingImage_54e2dc[ENDING_DATA.unk_160[i] / 8];
        }

        src = ENDING_DATA.oamFramePointers[i];
        part = *src++;
        nextSlot += part & 0xFF;

        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.y = part + ENDING_DATA.oamYPositions[i];

            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = (part + ENDING_DATA.oamXPositions[i]) & 0x1FF;

            *dst++ = *src++;
            gOamData[currSlot].split.paletteNum = palette;

            dst++;
        }
    }

    if (ENDING_DATA.hasNewRecord)
    {
        if (ENDING_DATA.newRecordPaletteTimer++ > 70)
            ENDING_DATA.newRecordPaletteTimer = 0;
            
        palette = sEndingImageNewRecordPalettes[ENDING_DATA.newRecordPaletteTimer / 6];

        src = sEndingImageOam_NewRecord;
        part = *src++;
        nextSlot += part & 0xFF;

        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.y = part + 59;

            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = (part + 48) & 0x1FF;

            *dst++ = *src++;
            gOamData[currSlot].split.paletteNum = palette;

            dst++;
        }
    }

    gNextOamSlot = currSlot;
}

/**
 * @brief 86c8c | 1ec | Handles the ending image displaying
 * 
 * @return u8 bool, ended
 */
u8 EndingImageDisplay(void)
{
    u8 ended;
    u8 i;

    ended = FALSE;

    switch (ENDING_DATA.timer++)
    {
        case 0:
            ENDING_DATA.unk_8++;
            break;

        case 30:
            EndingImageLoadTextOAM(ENDING_IMAGE_OAM_SET_CLEAR_TIME);
            ENDING_DATA.unk_1 = TRUE;
            break;

        case 110:
            EndingImageDisplayLinePermanently(ENDING_IMAGE_LINE_CLEAR_TIME);
            break;

        case 180:
            EndingImageDisplayLinePermanently(ENDING_IMAGE_LINE_TIMER);
            if (gEndingFlags & ENDING_FLAG_NEW_TIME_ATTACK_RECORD)
                ENDING_DATA.hasNewRecord++;
            break;

        case 330:
            EndingImageLoadTextOAM(ENDING_IMAGE_OAM_SET_YOUR_RATE);
            break;

        case 375:
            if (ENDING_DATA.language == LANGUAGE_JAPANESE || ENDING_DATA.language == LANGUAGE_ENGLISH ||
                ENDING_DATA.language == LANGUAGE_ITALIAN)
                EndingImageDisplayLinePermanently(ENDING_IMAGE_LINE_YOUR_RATE);
            break;

        case 380:
            if (ENDING_DATA.language == LANGUAGE_JAPANESE || ENDING_DATA.language == LANGUAGE_ENGLISH ||
                ENDING_DATA.language == LANGUAGE_ITALIAN)
                EndingImageLoadTextOAM(ENDING_IMAGE_OAM_SET_COLLECTING);
            break;

        case 460:
            EndingImageDisplayLinePermanently(ENDING_IMAGE_LINE_COLLECTING);
            break;

        case 530:
            EndingImageDisplayLinePermanently(ENDING_IMAGE_LINE_PERCENTAGE);
            break;

        case 780:
            if (ENDING_DATA.language != LANGUAGE_HIRAGANA)
                EndingImageDisplayLinePermanently(ENDING_IMAGE_LINE_NEXT_MISSION);
            break;

        case 1376:
            if (gChangedInput & (KEY_A | KEY_B | KEY_START))
                FadeMusic(256);
            else
                ENDING_DATA.timer--;
            break;

        case 1664:
            ended = TRUE;
    }

    if (ENDING_DATA.unk_8)
    {
        if (gBg0YPosition > 6)
        {
            gBg0YPosition -= 6;
            gBg1YPosition -= 6;
        }
        else
        {
            gBg0YPosition = 0;
            gBg1YPosition = 0;
            ENDING_DATA.unk_8 = FALSE;
        }
    }

    if (ENDING_DATA.timer > 1380)
        return ended;

    if (ENDING_DATA.timer > 809 && gButtonInput & (KEY_R | KEY_L))
        return ended;

    if (ENDING_DATA.unk_1 == TRUE)
    {
        for (i = 6; i < ENDING_DATA.oamLength; i++)
            EndingImageUpdateLettersSpawnDelay(i);
    }

    EndingImageDisplayText();

    return ended;
}

/**
 * @brief 86e78 | 158 | Initializes the unlocked options
 * 
 */
void UnlockedOptionsInit(void)
{
    u32 zero;

    write16(REG_IME, FALSE);
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) & ~IF_HBLANK);
    write16(REG_IF, IF_HBLANK);

    write16(REG_IME, TRUE);
    write16(REG_DISPCNT, 0);

    write16(REG_IME, FALSE);
    CallbackSetVBlank(UnlockedOptionsVBlank);
    write16(REG_IME, TRUE);

    zero = 0;
    DMA_SET(3, &zero, &gNonGameplayRAM, (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | sizeof(gNonGameplayRAM) / 4);
    ClearGfxRam();

    LZ77UncompVRAM(sUnlockedOptionsTileTable, VRAM_BASE + 0x8000);
    BitFill(3, -1, VRAM_BASE + 0x7FE0, 0x20, 32);
    BitFill(3, 0xF3FFF3FF, VRAM_BASE + 0x8800, 0x800, 32);

    DMA_SET(3, sUnlockedOptionsPAL, PALRAM_BASE + 0x1E0, DMA_ENABLE << 16 | ARRAY_SIZE(sUnlockedOptionsPAL));

    write16(REG_BG0CNT, 0x1000);
    write16(REG_BG1CNT, 0x1101);

    gNextOamSlot = 0;
    ResetFreeOam();

    write16(REG_BG0HOFS, 0);
    write16(REG_BG0VOFS, 0);

    ENDING_DATA.dispcnt = 0;
    ENDING_DATA.bldcnt = 0;

    gWrittenToBLDALPHA_L = 16;
    gWrittenToBLDALPHA_H = 0;

    gWrittenToBLDY_NonGameplay = 16;

    EndScreenVBlank();
}

/**
 * @brief 86fd0 | 20c | Handlkes the pop up displaying what's been unlocked
 * 
 * @return u8 0, 1 pop up ended, 2 ended
 */
u8 UnlockedOptionsPopUp(void)
{
    u32 msgNumber;
    u8 ended;

    ended = FALSE;

    switch (ENDING_DATA.timer++)
    {
        case 0:
            BitFill(3, 0, VRAM_BASE, 0x2000, 32);

            if (gEndingFlags & ENDING_FLAG_FIRST_CLEAR)
                msgNumber = FILE_SCREEN_TEXT_GALLERY_UNLOCK;
            else if (gEndingFlags & ENDING_FLAG_FIRST_HARD_MODE_CLEAR)
                msgNumber = FILE_SCREEN_TEXT_SOUND_TEST_UNLOCK;
            else if (gEndingFlags & ENDING_FLAG_FIRST_TIME_ATTACK_CLEAR)
                msgNumber = FILE_SCREEN_TEXT_TIME_ATTACK_RECORD_UNLOCK;
            else
                msgNumber = FILE_SCREEN_TEXT_NES_METROID_UNLOCK;

            TextStartFileScreen(msgNumber);
            ENDING_DATA.oamTypes[0] = 0;
            break;

        case 32:
            ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_WIN0;
            write16(REG_WININ, 3);
            write16(REG_WINOUT, 0);
            ENDING_DATA.unk_1++;

            ENDING_DATA.oamXPositions[0] = 0x78;
            ENDING_DATA.oamXPositions[1] = 0x78;
            ENDING_DATA.oamYPositions[0] = 0x50;
            ENDING_DATA.oamYPositions[1] = 0x50;
            break;

        case 128:
            ENDING_DATA.timer--;
            break;
    }

    if (ENDING_DATA.oamTypes[0] == 0)
        ENDING_DATA.oamTypes[0] = TextProcessFileScreenPopUp();

    if (ENDING_DATA.unk_1 == 1)
    {
        if (ENDING_DATA.oamXPositions[0] > 0x30)
        {
            ENDING_DATA.oamXPositions[0] -= 8;
            ENDING_DATA.oamXPositions[1] += 8;
            ENDING_DATA.oamYPositions[0] -= 4;
            ENDING_DATA.oamYPositions[1] += 4;
        }
        else
        {
            ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_WIN0;

            ENDING_DATA.oamXPositions[0] = 0x2C;
            ENDING_DATA.oamXPositions[1] = 0xBC;
            ENDING_DATA.oamYPositions[0] = 0x2C;
            ENDING_DATA.oamYPositions[1] = 0x74;
            ENDING_DATA.unk_1++;
        }
    }
    else if (ENDING_DATA.unk_1 == 2)
    {
        if (gChangedInput & KEY_A)
        {
            ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_WIN0;
            ENDING_DATA.unk_1++;
            ENDING_DATA.timer++;
        }
    }
    else if (ENDING_DATA.unk_1 == 3)
    {
        if (ENDING_DATA.oamXPositions[0] < 0x70)
        {
            ENDING_DATA.oamXPositions[0] += 8;
            ENDING_DATA.oamXPositions[1] -= 8;
            ENDING_DATA.oamYPositions[0] += 4;
            ENDING_DATA.oamYPositions[1] -= 4;
        }
        else
        {
            ENDING_DATA.dispcnt = 0;

            if (gEndingFlags & ENDING_FLAG_FIRST_CLEAR)
                ended++;
            else
                ended += 2;
        }
    }

    return ended;
}

/**
 * @brief 871dc | 208 | Subroutine for the credits
 * 
 * @return u32 bool, ended
 */
u32 CreditsSubroutine(void)
{
    u32 ended;
    u32 subroutineResult;

    ended = FALSE;
    ENDING_DATA.unk_6 = 0;
    gNextOamSlot = 0;

    switch (gGameModeSub1)
    {
        case 0:
            CreditsInit();
            gGameModeSub1++;
            break;

        case 2:
            subroutineResult = sCreditsFunctionPointers[ENDING_DATA.stage]();
            if (subroutineResult)
            {
                ENDING_DATA.stage++;
                ENDING_DATA.unk_1 = 0;
                ENDING_DATA.endScreenTimer = 0;
                ENDING_DATA.timer = 0;

                if (subroutineResult > 1)
                    gGameModeSub1++;
            }

            ResetFreeOam();
            break;

        case 7:
        case 11:
            if (gWrittenToBLDY_NonGameplay < 16)
                gWrittenToBLDY_NonGameplay++;
            else
                gGameModeSub1++;
            break;

        case 4:
            EndScreenInit();
            gGameModeSub1++;
            break;

        case 6:
            if (sEndScreenFunctionPointers[ENDING_DATA.stage]())
                gGameModeSub1++;
            break;

        case 8:
            EndingImageInit();
            gGameModeSub1++;
            break;

        case 5:
        case 9:
        case 13:
            if (gWrittenToBLDY_NonGameplay != 0)
                gWrittenToBLDY_NonGameplay--;
            else
            {
                ENDING_DATA.bldcnt = 0;
                gGameModeSub1++;
            }
            break;

        case 10:
            if (sEndingImageFunctionPointers[ENDING_DATA.stage]())
            {
                if (gEndingFlags & (ENDING_FLAG_UNKNOWN | ENDING_FLAG_FIRST_TIME_ATTACK_CLEAR |
                    ENDING_FLAG_FIRST_HARD_MODE_CLEAR | ENDING_FLAG_FIRST_CLEAR))
                {
                    ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
                        BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                        BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

                    gWrittenToBLDY_NonGameplay = 0;
                    gGameModeSub1++;
                }
                else
                {
                    gDisableSoftreset = FALSE;
                    ended++;
                }
            }

            ResetFreeOam();
            break;

        case 1:
        case 3:
            gGameModeSub1++;
            break;

        case 15:
            if (gEndingFlags & (ENDING_FLAG_UNKNOWN | ENDING_FLAG_FIRST_TIME_ATTACK_CLEAR |
                ENDING_FLAG_FIRST_HARD_MODE_CLEAR | ENDING_FLAG_FIRST_CLEAR))
            {
                gGameModeSub1++;
                break;
            }

            gDisableSoftreset = FALSE;
            ended++;
            break;

        case 12:
            UnlockedOptionsInit();
            gGameModeSub1++;
            break;

        case 14:
            subroutineResult = sUnlockedOptionsFunctionPointers[ENDING_DATA.stage]();
            if (subroutineResult)
            {
                gEndingFlags = 0;
                ENDING_DATA.stage++;
                ENDING_DATA.unk_1 = 0;
                ENDING_DATA.endScreenTimer = 0;
                ENDING_DATA.timer = 0;

                if (subroutineResult > 1)
                    gGameModeSub1++;
            }

            ResetFreeOam();
            break;
    }

    return ended;
}

/**
 * @brief 873e4 | 238 | Initializes the gallery
 * 
 */
void GalleryInit(void)
{
    u32 zero;
    u32 endingNbr;
    u32 i;
    u32 bit;

    write16(REG_IME, FALSE);
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) & ~IF_HBLANK);
    write16(REG_IF, IF_HBLANK);

    write16(REG_IME, TRUE);
    write16(REG_DISPCNT, 0);

    write16(REG_IME, FALSE);
    CallbackSetVBlank(GalleryVBlank);
    write16(REG_IME, TRUE);

    if (gGameModeSub1 == 0)
    {
        ClearGfxRam();

        zero = 0;
        DMA_SET(3, &zero, &gNonGameplayRAM, (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | sizeof(gNonGameplayRAM) / 4);
    }

    endingNbr = ENDING_DATA.endingNumber;

    for (i = 0; i < 8; i++)
    {
        bit = 1 << endingNbr;
        if (gFileScreenOptionsUnlocked.galleryImages & bit)
            break;

        if (ENDING_DATA.completionPercentage != 0)
        {
            if (endingNbr != 0)
                endingNbr--;
            else
                endingNbr = 7;
        }
        else
        {
            if (endingNbr < 7)
                endingNbr++;
            else
                endingNbr = 0;
        }
    }

    ENDING_DATA.endingNumber = endingNbr;

    LZ77UncompVRAM(sEndingImagesTopGfxPointers[endingNbr], VRAM_BASE);
    LZ77UncompVRAM(sEndingImagesBottomGfxPointers[endingNbr], VRAM_BASE + 0x8000);
    LZ77UncompVRAM(sEndingImagesTopTileTablePointers[endingNbr], VRAM_BASE + 0xE000);
    LZ77UncompVRAM(sEndingImagesHalfTileTablePointers[endingNbr], VRAM_BASE + 0xF800);

    BitFill(3, 0x4FF04FF, VRAM_BASE + 0xE800, 0x800, 32);

    DMA_SET(3, sEndingImagesPalPointers[endingNbr], PALRAM_BASE, DMA_ENABLE << 16 | PALRAM_SIZE / 4);

    write16(REG_BG0CNT, 0x9C00);
    write16(REG_BG1CNT, 0x9E09);

    gNextOamSlot = 0;
    ResetFreeOam();

    gBg0XPosition = 0;
    gBg0YPosition = 0x1000;
    gBg1XPosition = 0;
    gBg1YPosition = 0x1000;
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    write16(REG_BG0HOFS, 0);
    write16(REG_BG0VOFS, 0x1000);
    write16(REG_BG1HOFS, 0);
    write16(REG_BG1VOFS, 0x1000);
    write16(REG_BG2HOFS, 0);
    write16(REG_BG2VOFS, 0);
    write16(REG_BG3HOFS, 0);
    write16(REG_BG3VOFS, 0);

    ENDING_DATA.unk_8 = 0;

    ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_OBJ;
    ENDING_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET |
        BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

    GalleryVBlank();
}

/**
 * @brief 8761c | 15c | Handles the display of the gallery image
 * 
 * @return u32 
 */
u32 GalleryDisplay(void)
{
    u8 endingNbr;
    u32 ended;
    s32 velocity;
    u32 change;
    u8 complPercent;
    u8 bit;

    endingNbr = ENDING_DATA.endingNumber;
    bit = 1 << endingNbr;
    ended = FALSE;
    change = FALSE;
    complPercent = 0;

    if (gChangedInput & KEY_B)
    {
        ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
            BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
            BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

        gWrittenToBLDY_NonGameplay = 0;
        ended = TRUE;
    }
    else if (gChangedInput & (KEY_A | KEY_RIGHT))
    {
        if (endingNbr < 7)
            endingNbr++;
        else
            endingNbr = 0;
        
        if (gFileScreenOptionsUnlocked.galleryImages > bit)
            change++;
    }
    else if (gChangedInput & KEY_LEFT)
    {
        if (endingNbr != 0)
            endingNbr--;
        else
            endingNbr = 7;

        complPercent++;
        if (gFileScreenOptionsUnlocked.galleryImages > bit)
            change++;
    }

    
    if (change)
    {
        ENDING_DATA.endingNumber = endingNbr;
        ENDING_DATA.completionPercentage = complPercent;

        ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
            BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
            BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

        gWrittenToBLDY_NonGameplay = 0;
        gGameModeSub1 = 5;
    }

    change = FALSE;
    velocity = 8;

    if (ENDING_DATA.unk_8 != 0)
    {
        if (gButtonInput & KEY_DOWN)
            change = TRUE;

        velocity = 12;
    }

    if (!change)
    {
        if (gBg0YPosition > velocity)
        {
            gBg0YPosition -= velocity;
            gBg1YPosition -= velocity;
        }
        else
        {
            GALLERY_RESET_BG_POS();
            ENDING_DATA.unk_8 = TRUE;
        }
    }
    else
    {
        gBg0YPosition += velocity;
        gBg1YPosition += velocity;

        if (gBg0YPosition > BLOCK_SIZE * 64)
        {
            gBg0YPosition = BLOCK_SIZE * 64;
            gBg1YPosition = BLOCK_SIZE * 64;
        }
    }

    return ended;
}

/**
 * @brief 87778 | d8 | Subroutine for the gallery
 * 
 * @return u32 bool, ended
 */
u32 GallerySubroutine(void)
{
    u32 ended;

    ended = FALSE;
    ENDING_DATA.unk_6 = 0;

    switch (gGameModeSub1)
    {
        case 0:
        case 4:
            GalleryInit();
            gGameModeSub1 = 1;
            break;

        case 1:
            if (gWrittenToBLDY_NonGameplay != 0)
            {
                gWrittenToBLDY_NonGameplay--;
                break;
            }

            ENDING_DATA.bldcnt = 0;
            gGameModeSub1++;
            break;

        case 2:
            if (GalleryDisplay())
                gGameModeSub1++;
            break;

        case 3:
        case 5:
            if (gWrittenToBLDY_NonGameplay < 16)
            {
                if (ENDING_DATA.timer++ & 1)
                    gWrittenToBLDY_NonGameplay++;

                break;
            }

            if (gGameModeSub1 == 3)
                ended++;
            else
                gGameModeSub1 = 4;
            break;
    }

    return ended;
}
