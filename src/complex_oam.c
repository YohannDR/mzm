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

/**
 * @brief 7ff58 | 19c | Calculates the part 4 of the OAM (used for special cases such as cutscenes and menus)
 * 
 * @param rotation Rotation
 * @param scaling Scaling
 * @param _oamSlot OAM Slot
 */
void CalculateOamPart4(u16 rotation, s16 scaling, u16 _oamSlot)
{
    s32 negativeScaling = scaling; // Needed to produce matching ASM.
    u8 oamSlot = _oamSlot; // Needed to produce matching ASM

    s32 dy1;
    s32 dmy1;
    s32 dx1;
    s32 dmx1;
    s32 dy2;
    s32 dmy2;

    s32 idx;

    dy1 = FixedMultiplication(cos(rotation), FixedInverse(scaling));

    // The following expression writes uselessly first to dmy2 to produce matching ASM:
    dmy1 = (dmy2 = FixedMultiplication(sin(rotation), FixedInverse(scaling)));
    dx1 = FixedMultiplication(-sin(rotation), FixedInverse(scaling));

    negativeScaling = -scaling;

    dmx1 = FixedMultiplication(cos(rotation), FixedInverse(negativeScaling));

    dy2 = FixedMultiplication(sin(rotation), FixedInverse(negativeScaling));
    dmy2 = FixedMultiplication(-sin(rotation), FixedInverse(negativeScaling));

    gOamData[oamSlot].all.affineParam = dy1;
    idx = oamSlot + 1; // Needed to produce matching ASM.
    gOamData[idx].all.affineParam = dmy1;
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
