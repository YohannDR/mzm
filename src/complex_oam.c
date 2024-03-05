#include "complex_oam.h"
#include "oam.h"
#include "macros.h"
#include "fixed_point.h"

#include "data/generic_data.h"
#include "data/intro_data.h"

/**
 * @brief 7fd64 | 1f4 | Processes complex OAM with rotation/scaling and other params
 * 
 * @param oamSlot OAM Slot
 * @param xPosition X Position
 * @param yPosition Y Position
 * @param rotation Rotation
 * @param _scaling Scaling
 * @param _doubleSize Double size
 * @param _matrixNum Matrix number
 * @return u8 0
 */
u8 ProcessComplexOam(u32 oamSlot, s16 xPosition, s16 yPosition, u16 rotation, s16 _scaling, u16 _doubleSize, u16 _matrixNum)
{
    s32 scaling;
    u8 doubleSize, matrixNum;
    
    s32 y;    
    s32 x;
    s32 xOffset;
    s32 yOffset;
    u8 shape;
    u8 size;
    u8 unk_0;
    u8 unk_1;
    s32 unk_2;
    s32 unk_3;
    s32 tmpX;
    s32 tmpY;
    s32 scaledX;
    s32 scaledY;

    scaling = _scaling;

    doubleSize = _doubleSize;
    matrixNum = _matrixNum;

    xOffset = (s16)((u16)xPosition + BLOCK_SIZE);
    yOffset = (s16)((u16)yPosition + BLOCK_SIZE);

    shape = gOamData[oamSlot].split.shape;
    size = gOamData[oamSlot].split.size;

    unk_0 = sArray_45fd24[shape][size];
    unk_1 = sArray_45fd30[shape][size];

    x = MOD_AND((s16)(gOamData[oamSlot].split.x + xOffset), 512);
    y = MOD_AND((s16)(gOamData[oamSlot].split.y + yOffset), 256);

    tmpX = (s16)(x - xOffset + unk_0);
    tmpY = (s16)(y - yOffset + unk_1);

    scaledX = (s16)(Q_24_8_TO_INT(tmpX * scaling) - tmpX);
    scaledY = (s16)(Q_24_8_TO_INT(tmpY * scaling) - tmpY);

    x = (s16)(x + scaledX);
    y = (s16)(y + scaledY);

    unk_2 = (s16)(x - xOffset + unk_0);
    unk_3 = (s16)(y - yOffset + unk_1);

    x = Q_8_8_TO_SHORT(unk_2 * cos(rotation) - unk_3 * sin(rotation));
    y = Q_8_8_TO_SHORT(unk_2 * sin(rotation) + unk_3 * cos(rotation));

    if (!doubleSize)
    {
        gOamData[oamSlot].split.affineMode = 1;

        x = (s16)(x - unk_0);
        y = (s16)(y - unk_1);
    }
    else
    {
        gOamData[oamSlot].split.affineMode = 3;

        x = (s16)(x - unk_0 * 2);
        y = (s16)(y - unk_1 * 2);
    }

    gOamData[oamSlot].split.x = MOD_AND(x + xOffset - BLOCK_SIZE, 512);
    gOamData[oamSlot].split.y = MOD_AND(y + yOffset - BLOCK_SIZE, 256);

    if (gOamData[oamSlot].split.xFlip)
    {
        if (gOamData[oamSlot].split.yFlip)
        {
            gOamData[oamSlot].split.matrixNum = matrixNum + 3;
        }
        else
        {
            gOamData[oamSlot].split.matrixNum = matrixNum + 1;
        }
    }
    else
    {
        if (gOamData[oamSlot].split.yFlip)
        {
            gOamData[oamSlot].split.matrixNum = matrixNum + 2;
        }
        else
        {
            gOamData[oamSlot].split.matrixNum = matrixNum;
        }
    }

    gOamData[oamSlot].split.xFlip = FALSE;
    gOamData[oamSlot].split.yFlip = FALSE;
    
    return FALSE;
}

#ifdef NON_MATCHING
void CalculateOamPart4(u16 rotation, s16 scaling, u8 oamSlot)
{
    // https://decomp.me/scratch/jijJJ

    s32 dy1;
    s32 dmy1;
    s32 dx1;
    s32 dmx1;
    s32 dy2;
    s32 dmy2;
    
    dy1 = FixedMultiplication(cos(rotation), FixedInverse(scaling));
   
    dmy1 = FixedMultiplication(sin(rotation), FixedInverse(scaling));
    dx1 = FixedMultiplication(-sin(rotation), FixedInverse(scaling));

    dmx1 = FixedMultiplication(cos(rotation), FixedInverse(-scaling));

    dy2 = FixedMultiplication(sin(rotation), FixedInverse(-scaling));
    dmy2 = FixedMultiplication(-sin(rotation), FixedInverse(-scaling));

    gOamData[oamSlot].all.affineParam = dy1;
    gOamData[oamSlot + 1].all.affineParam = dmy1;
    gOamData[oamSlot + 2].all.affineParam = dx1;
    gOamData[oamSlot + 3].all.affineParam = dy1;
    gOamData[oamSlot + 4].all.affineParam = dmx1;
    gOamData[oamSlot + 5].all.affineParam = dy2;
    gOamData[oamSlot + 6].all.affineParam = dx1;
    gOamData[oamSlot + 7].all.affineParam = dy1;
    gOamData[oamSlot + 8].all.affineParam = dy1;
    gOamData[oamSlot + 9].all.affineParam = dmy1;
    gOamData[oamSlot + 10].all.affineParam = dmy2;
    gOamData[oamSlot + 11].all.affineParam = dmx1;
    gOamData[oamSlot + 12].all.affineParam = dmx1;
    gOamData[oamSlot + 13].all.affineParam = dy2;
    gOamData[oamSlot + 14].all.affineParam = dmy2;
    gOamData[oamSlot + 15].all.affineParam = dmx1;
}
#else
NAKED_FUNCTION
void CalculateOamPart4(u16 rotation, s16 scaling, u8 oamSlot)
{
    asm(" \n\
    push {r4, r5, r6, r7, lr} \n\
    mov r7, sl \n\
    mov r6, sb \n\
    mov r5, r8 \n\
    push {r5, r6, r7} \n\
    sub sp, #8 \n\
    add r4, r0, #0 \n\
    add r5, r1, #0 \n\
    lsl r4, r4, #0x10 \n\
    lsr r4, r4, #0x10 \n\
    lsl r5, r5, #0x10 \n\
    asr r5, r5, #0x10 \n\
    lsl r2, r2, #0x18 \n\
    lsr r7, r2, #0x18 \n\
    ldr r6, lbl_080800ec @ =sSineTable \n\
    add r0, r4, #0 \n\
    add r0, #0x40 \n\
    lsl r0, r0, #1 \n\
    add r0, r0, r6 \n\
    movs r2, #0 \n\
    ldrsh r1, [r0, r2] \n\
    str r1, [sp] \n\
    add r0, r5, #0 \n\
    bl FixedInverse \n\
    add r1, r0, #0 \n\
    lsl r1, r1, #0x10 \n\
    asr r1, r1, #0x10 \n\
    ldr r0, [sp] \n\
    bl FixedMultiplication \n\
    mov r8, r0 \n\
    mov r3, r8 \n\
    lsl r3, r3, #0x10 \n\
    asr r3, r3, #0x10 \n\
    mov r8, r3 \n\
    lsl r4, r4, #1 \n\
    add r4, r4, r6 \n\
    movs r1, #0 \n\
    ldrsh r0, [r4, r1] \n\
    mov sl, r0 \n\
    add r0, r5, #0 \n\
    bl FixedInverse \n\
    add r1, r0, #0 \n\
    lsl r1, r1, #0x10 \n\
    asr r1, r1, #0x10 \n\
    mov r0, sl \n\
    bl FixedMultiplication \n\
    lsl r0, r0, #0x10 \n\
    asr r0, r0, #0x10 \n\
    str r0, [sp, #4] \n\
    ldrh r4, [r4] \n\
    neg r4, r4 \n\
    lsl r4, r4, #0x10 \n\
    asr r4, r4, #0x10 \n\
    add r0, r5, #0 \n\
    bl FixedInverse \n\
    add r1, r0, #0 \n\
    lsl r1, r1, #0x10 \n\
    asr r1, r1, #0x10 \n\
    add r0, r4, #0 \n\
    bl FixedMultiplication \n\
    mov sb, r0 \n\
    mov r2, sb \n\
    lsl r2, r2, #0x10 \n\
    asr r2, r2, #0x10 \n\
    mov sb, r2 \n\
    neg r5, r5 \n\
    lsl r5, r5, #0x10 \n\
    asr r5, r5, #0x10 \n\
    add r0, r5, #0 \n\
    bl FixedInverse \n\
    add r1, r0, #0 \n\
    lsl r1, r1, #0x10 \n\
    asr r1, r1, #0x10 \n\
    ldr r0, [sp] \n\
    bl FixedMultiplication \n\
    add r6, r0, #0 \n\
    lsl r6, r6, #0x10 \n\
    asr r6, r6, #0x10 \n\
    add r0, r5, #0 \n\
    bl FixedInverse \n\
    add r1, r0, #0 \n\
    lsl r1, r1, #0x10 \n\
    asr r1, r1, #0x10 \n\
    mov r0, sl \n\
    bl FixedMultiplication \n\
    mov sl, r0 \n\
    mov r3, sl \n\
    lsl r3, r3, #0x10 \n\
    asr r3, r3, #0x10 \n\
    mov sl, r3 \n\
    add r0, r5, #0 \n\
    bl FixedInverse \n\
    add r1, r0, #0 \n\
    lsl r1, r1, #0x10 \n\
    asr r1, r1, #0x10 \n\
    add r0, r4, #0 \n\
    bl FixedMultiplication \n\
    lsl r0, r0, #0x10 \n\
    asr r0, r0, #0x10 \n\
    ldr r2, lbl_080800f0 @ =gOamData \n\
    lsl r1, r7, #3 \n\
    add r1, r1, r2 \n\
    mov r4, r8 \n\
    strh r4, [r1, #6] \n\
    add r1, r7, #1 \n\
    lsl r1, r1, #3 \n\
    add r1, r1, r2 \n\
    mov r3, sp \n\
    ldrh r3, [r3, #4] \n\
    strh r3, [r1, #6] \n\
    add r1, r7, #2 \n\
    lsl r1, r1, #3 \n\
    add r1, r1, r2 \n\
    mov r4, sb \n\
    strh r4, [r1, #6] \n\
    add r1, r7, #3 \n\
    lsl r1, r1, #3 \n\
    add r1, r1, r2 \n\
    mov r3, r8 \n\
    strh r3, [r1, #6] \n\
    add r1, r7, #4 \n\
    lsl r1, r1, #3 \n\
    add r1, r1, r2 \n\
    strh r6, [r1, #6] \n\
    add r1, r7, #5 \n\
    lsl r1, r1, #3 \n\
    add r1, r1, r2 \n\
    mov r4, sl \n\
    strh r4, [r1, #6] \n\
    add r1, r7, #6 \n\
    lsl r1, r1, #3 \n\
    add r1, r1, r2 \n\
    mov r3, sb \n\
    strh r3, [r1, #6] \n\
    add r1, r7, #7 \n\
    lsl r1, r1, #3 \n\
    add r1, r1, r2 \n\
    mov r4, r8 \n\
    strh r4, [r1, #6] \n\
    add r1, r7, #0 \n\
    add r1, #8 \n\
    lsl r1, r1, #3 \n\
    add r1, r1, r2 \n\
    strh r4, [r1, #6] \n\
    add r1, r7, #0 \n\
    add r1, #9 \n\
    lsl r1, r1, #3 \n\
    add r1, r1, r2 \n\
    mov r3, sp \n\
    ldrh r3, [r3, #4] \n\
    strh r3, [r1, #6] \n\
    add r1, r7, #0 \n\
    add r1, #0xa \n\
    lsl r1, r1, #3 \n\
    add r1, r1, r2 \n\
    strh r0, [r1, #6] \n\
    add r1, r7, #0 \n\
    add r1, #0xb \n\
    lsl r1, r1, #3 \n\
    add r1, r1, r2 \n\
    strh r6, [r1, #6] \n\
    add r1, r7, #0 \n\
    add r1, #0xc \n\
    lsl r1, r1, #3 \n\
    add r1, r1, r2 \n\
    strh r6, [r1, #6] \n\
    add r1, r7, #0 \n\
    add r1, #0xd \n\
    lsl r1, r1, #3 \n\
    add r1, r1, r2 \n\
    mov r4, sl \n\
    strh r4, [r1, #6] \n\
    add r1, r7, #0 \n\
    add r1, #0xe \n\
    lsl r1, r1, #3 \n\
    add r1, r1, r2 \n\
    strh r0, [r1, #6] \n\
    add r0, r7, #0 \n\
    add r0, #0xf \n\
    lsl r0, r0, #3 \n\
    add r0, r0, r2 \n\
    strh r6, [r0, #6] \n\
    add sp, #8 \n\
    pop {r3, r4, r5} \n\
    mov r8, r3 \n\
    mov sb, r4 \n\
    mov sl, r5 \n\
    pop {r4, r5, r6, r7} \n\
    pop {r0} \n\
    bx r0 \n\
    .align 2, 0 \n\
lbl_080800ec: .4byte sSineTable \n\
lbl_080800f0: .4byte gOamData \n\
    ");
}
#endif
