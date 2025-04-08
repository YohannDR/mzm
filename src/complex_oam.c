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
 * @param scaling Scaling
 * @param doubleSize Double size
 * @param matrixNum Matrix number
 * @return u8 0
 */
u8 ProcessComplexOam(u32 oamSlot, s16 xPosition, s16 yPosition, u16 rotation, s16 scaling, u16 doubleSize, u16 matrixNum)
{
    s32 _scaling;
    u8 _doubleSize;
    u8 _matrixNum;
    
    s32 y;    
    s32 x;
    s32 xOrigin;
    s32 yOrigin;
    u8 shape;
    u8 size;
    u8 xHalfRadius;
    u8 yHalfRadius;
    s32 unk_2;
    s32 unk_3;
    s32 tmpX;
    s32 tmpY;
    s32 scaledX;
    s32 scaledY;

    _scaling = scaling;
    _doubleSize = doubleSize;
    _matrixNum = matrixNum;

    xOrigin = (s16)((u16)xPosition + BLOCK_SIZE);
    yOrigin = (s16)((u16)yPosition + BLOCK_SIZE);

    shape = gOamData[oamSlot].split.shape;
    size = gOamData[oamSlot].split.size;

    xHalfRadius = sSpriteXHalfRadius[shape][size];
    yHalfRadius = sSpriteYHalfRadius[shape][size];

    x = MOD_AND((s16)(gOamData[oamSlot].split.x + xOrigin), 512);
    y = MOD_AND((s16)(gOamData[oamSlot].split.y + yOrigin), 256);

    tmpX = (s16)(x - xOrigin + xHalfRadius);
    tmpY = (s16)(y - yOrigin + yHalfRadius);

    // Scale x and y
    scaledX = (s16)(Q_24_8_TO_INT(tmpX * _scaling) - tmpX);
    scaledY = (s16)(Q_24_8_TO_INT(tmpY * _scaling) - tmpY);

    x = (s16)(x + scaledX);
    y = (s16)(y + scaledY);

    unk_2 = (s16)(x - xOrigin + xHalfRadius);
    unk_3 = (s16)(y - yOrigin + yHalfRadius);

    // Rotate x and y
    x = Q_8_8_TO_SHORT(unk_2 * cos(rotation) - unk_3 * sin(rotation));
    y = Q_8_8_TO_SHORT(unk_2 * sin(rotation) + unk_3 * cos(rotation));

    if (!_doubleSize)
    {
        gOamData[oamSlot].split.affineMode = OAM_AFFINE_MODE_AFFINE;

        x = (s16)(x - xHalfRadius);
        y = (s16)(y - yHalfRadius);
    }
    else
    {
        gOamData[oamSlot].split.affineMode = OAM_AFFINE_MODE_DOUBLE_SIZED;

        x = (s16)(x - xHalfRadius * 2);
        y = (s16)(y - yHalfRadius * 2);
    }

    // Update rotated x and y in OAM
    gOamData[oamSlot].split.x = MOD_AND(x + xOrigin - BLOCK_SIZE, 512);
    gOamData[oamSlot].split.y = MOD_AND(y + yOrigin - BLOCK_SIZE, 256);

    if (gOamData[oamSlot].split.xFlip)
    {
        if (gOamData[oamSlot].split.yFlip)
        {
            gOamData[oamSlot].split.matrixNum = _matrixNum + 3;
        }
        else
        {
            gOamData[oamSlot].split.matrixNum = _matrixNum + 1;
        }
    }
    else
    {
        if (gOamData[oamSlot].split.yFlip)
        {
            gOamData[oamSlot].split.matrixNum = _matrixNum + 2;
        }
        else
        {
            gOamData[oamSlot].split.matrixNum = _matrixNum;
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
 * @param oamSlot OAM Slot
 */
void CalculateOamPart4(u16 rotation, s16 scaling, u16 oamSlot)
{
    s32 negativeScaling;
    u8 _oamSlot;

    s32 dy1;
    s32 dmy1;
    s32 dx1;
    s32 dmx1;
    s32 dy2;
    s32 dmy2;

    negativeScaling = scaling; // Needed to produce matching ASM.
    _oamSlot = oamSlot; // Needed to produce matching ASM
    dy1 = FixedMultiplication(cos(rotation), FixedInverse(scaling));

    // The following expression writes uselessly first to dmy2 to produce matching ASM:
    dmy1 = (dmy2 = FixedMultiplication(sin(rotation), FixedInverse(scaling)));
    dx1 = FixedMultiplication(-sin(rotation), FixedInverse(scaling));

    negativeScaling = -scaling;

    dmx1 = FixedMultiplication(cos(rotation), FixedInverse(negativeScaling));

    dy2 = FixedMultiplication(sin(rotation), FixedInverse(negativeScaling));
    dmy2 = FixedMultiplication(-sin(rotation), FixedInverse(negativeScaling));

    gOamData[_oamSlot].all.affineParam = dy1;
    gOamData[_oamSlot + 1].all.affineParam = dmy1;
    gOamData[_oamSlot + 2].all.affineParam = dx1;
    gOamData[_oamSlot + 3].all.affineParam = dy1;
    gOamData[_oamSlot + 4].all.affineParam = dmx1;
    gOamData[_oamSlot + 5].all.affineParam = dy2;
    gOamData[_oamSlot + 6].all.affineParam = dx1;
    gOamData[_oamSlot + 7].all.affineParam = dy1;
    gOamData[_oamSlot + 8].all.affineParam = dy1;
    gOamData[_oamSlot + 9].all.affineParam = dmy1;
    gOamData[_oamSlot + 10].all.affineParam = dmy2;
    gOamData[_oamSlot + 11].all.affineParam = dmx1;
    gOamData[_oamSlot + 12].all.affineParam = dmx1;
    gOamData[_oamSlot + 13].all.affineParam = dy2;
    gOamData[_oamSlot + 14].all.affineParam = dmy2;
    gOamData[_oamSlot + 15].all.affineParam = dmx1;
}
