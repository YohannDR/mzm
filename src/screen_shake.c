#include "screen_shake.h"
#include "macros.h"
#include "structs/screen_shake.h"

/**
 * @brief 55344 | 34 | Starts a vertical screen shake
 * 
 * @param duration Duration
 * @param param_2 To document
 * @return u8 Screen shake timer
 */
u8 ScreenShakeStartVertical(u8 duration, u8 param_2)
{
    if (duration != 0 && duration > gScreenShakeY.timer)
    {
        gScreenShakeY.timer = duration;
        gScreenShakeY.loopCounter = 0;
        gScreenShakeY.unk_2 = param_2;
        gScreenShakeY.direction = 0;

        gScreenShakeYOffset = 0;
    }

    return gScreenShakeY.timer;
}

/**
 * @brief 55378 | 34 | Starts an horizontal screen shake
 * 
 * @param duration Duration
 * @param param_2 To document
 * @return u8 Screen shake timer
 */
u8 ScreenShakeStartHorizontal(u8 duration, u8 param_2)
{
    if (duration != 0 && duration > gScreenShakeX.timer)
    {
        gScreenShakeX.timer = duration;
        gScreenShakeX.loopCounter = 0;
        gScreenShakeX.unk_2 = param_2;
        gScreenShakeX.direction = 0;

        gScreenShakeXOffset = 0;
    }

    return gScreenShakeX.timer;
}

/**
 * @brief 553ac | 30 | Starts an horizontal screen shake, unused
 * 
 * @param duration Duration
 * @return u8 Screen shake timer
 */
u8 ScreenShakeStartHorizontal_Unused(u8 duration)
{
    if (duration != 0 && duration > gScreenShakeX.timer)
    {
        gScreenShakeX.timer = duration;
        gScreenShakeX.loopCounter = 0;
        gScreenShakeX.unk_2 = 0;
        gScreenShakeX.direction = 0;

        gScreenShakeXOffset = 0;
    }

    return gScreenShakeX.timer;
}

/**
 * @brief 553dc | 68 | Updates the vertical screen shake
 * 
 * @return s32 Screen offset
 */
#ifdef NON_MATCHING
s32 ScreenShakeUpdateVertical(void)
{
    // https://decomp.me/scratch/je2b5

    s32 offset;
    u32 unk;
    
    offset = 0;
    gScreenShakeYOffset = 0;

    if (gScreenShakeY.timer == 0)
        return 0;

    do {
    }while(0);
    gScreenShakeY.timer--;
    if (gScreenShakeY.loopCounter < 2)
    {
        gScreenShakeY.loopCounter++;
        return 0;
    }

    gScreenShakeY.loopCounter = 0;

    unk = gScreenShakeY.unk_2 & 0x7F;
    offset = -2;
    if (gScreenShakeY.direction)
    {
        if (!unk)
            offset = 0;
        else
            offset = 2;
    }

    gScreenShakeY.direction ^= TRUE;
    if (gScreenShakeY.timer < 16)
        offset >>= 1;

    gScreenShakeYOffset = offset;

    return offset;
}
#else
NAKED_FUNCTION
s32 ScreenShakeUpdateVertical(void)
{
    asm(" \n\
    push {r4, r5, r6, lr} \n\
    movs r2, #0 \n\
    ldr r6, lbl_080553f4 @ =gScreenShakeYOffset \n\
    strb r2, [r6] \n\
    ldr r4, lbl_080553f8 @ =gScreenShakeY \n\
    ldrb r0, [r4] \n\
    add r3, r4, #0 \n\
    cmp r0, #0 \n\
    bne lbl_080553fc \n\
    movs r0, #0 \n\
    b lbl_0805543e \n\
    .align 2, 0 \n\
lbl_080553f4: .4byte gScreenShakeYOffset \n\
lbl_080553f8: .4byte gScreenShakeY \n\
lbl_080553fc: \n\
    sub r5, r0, #1 \n\
    strb r5, [r3] \n\
    ldrb r0, [r3, #1] \n\
    cmp r0, #1 \n\
    bhi lbl_0805540e \n\
    add r0, #1 \n\
    strb r0, [r3, #1] \n\
    movs r0, #0 \n\
    b lbl_0805543e \n\
lbl_0805540e: \n\
    strb r2, [r3, #1] \n\
    ldrb r0, [r3, #2] \n\
    movs r1, #0x7f \n\
    and r1, r0 \n\
    movs r2, #2 \n\
    neg r2, r2 \n\
    ldrb r3, [r3, #3] \n\
    cmp r3, #0 \n\
    beq lbl_0805542a \n\
    movs r2, #2 \n\
    neg r0, r1 \n\
    orr r0, r1 \n\
    asr r0, r0, #0x1f \n\
    and r2, r0 \n\
lbl_0805542a: \n\
    movs r0, #1 \n\
    eor r0, r3 \n\
    strb r0, [r4, #3] \n\
    lsl r0, r5, #0x18 \n\
    lsr r0, r0, #0x18 \n\
    cmp r0, #0xf \n\
    bhi lbl_0805543a \n\
    asr r2, r2, #1 \n\
lbl_0805543a: \n\
    strb r2, [r6] \n\
    add r0, r2, #0 \n\
lbl_0805543e: \n\
    pop {r4, r5, r6} \n\
    pop {r1} \n\
    bx r1 \n\
    ");
}
#endif

/**
 * @brief 55444 | 68 | Updates the horizontal screen shake
 * 
 * @return s32 Screen offset
 */
#ifdef NON_MATCHING
s32 ScreenShakeUpdateHorizontal(void)
{
    // https://decomp.me/scratch/O4FYJ
    
    s32 offset;
    u32 unk;
    
    offset = 0;
    gScreenShakeXOffset = 0;

    if (gScreenShakeX.timer == 0)
        return 0;

    do {
    }while(0);
    gScreenShakeX.timer--;
    if (gScreenShakeX.loopCounter < 2)
    {
        gScreenShakeX.loopCounter++;
        return 0;
    }

    gScreenShakeX.loopCounter = 0;

    unk = gScreenShakeX.unk_2 & 0x7F;
    offset = -2;
    if (gScreenShakeX.direction)
    {
        if (!unk)
            offset = 0;
        else
            offset = 2;
    }

    gScreenShakeX.direction ^= TRUE;
    if (gScreenShakeX.timer < 16)
        offset >>= 1;

    gScreenShakeXOffset = offset;

    return offset;
}
#else
NAKED_FUNCTION
s32 ScreenShakeUpdateHorizontal(void)
{
    asm(" \n\
    push {r4, r5, r6, lr} \n\
    movs r2, #0 \n\
    ldr r6, lbl_0805545c @ =gScreenShakeXOffset \n\
    strb r2, [r6] \n\
    ldr r4, lbl_08055460 @ =gScreenShakeX \n\
    ldrb r0, [r4] \n\
    add r3, r4, #0 \n\
    cmp r0, #0 \n\
    bne lbl_08055464 \n\
    movs r0, #0 \n\
    b lbl_080554a6 \n\
    .align 2, 0 \n\
lbl_0805545c: .4byte gScreenShakeXOffset \n\
lbl_08055460: .4byte gScreenShakeX \n\
lbl_08055464: \n\
    sub r5, r0, #1 \n\
    strb r5, [r3] \n\
    ldrb r0, [r3, #1] \n\
    cmp r0, #1 \n\
    bhi lbl_08055476 \n\
    add r0, #1 \n\
    strb r0, [r3, #1] \n\
    movs r0, #0 \n\
    b lbl_080554a6 \n\
lbl_08055476: \n\
    strb r2, [r3, #1] \n\
    ldrb r0, [r3, #2] \n\
    movs r1, #0x7f \n\
    and r1, r0 \n\
    movs r2, #2 \n\
    neg r2, r2 \n\
    ldrb r3, [r3, #3] \n\
    cmp r3, #0 \n\
    beq lbl_08055492 \n\
    movs r2, #2 \n\
    neg r0, r1 \n\
    orr r0, r1 \n\
    asr r0, r0, #0x1f \n\
    and r2, r0 \n\
lbl_08055492: \n\
    movs r0, #1 \n\
    eor r0, r3 \n\
    strb r0, [r4, #3] \n\
    lsl r0, r5, #0x18 \n\
    lsr r0, r0, #0x18 \n\
    cmp r0, #0xf \n\
    bhi lbl_080554a2 \n\
    asr r2, r2, #1 \n\
lbl_080554a2: \n\
    strb r2, [r6] \n\
    add r0, r2, #0 \n\
lbl_080554a6: \n\
    pop {r4, r5, r6} \n\
    pop {r1} \n\
    bx r1 \n\
    ");
}
#endif
