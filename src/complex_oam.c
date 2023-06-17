#include "complex_oam.h"
#include "oam.h"
#include "macros.h"
#include "fixed_point.h"

#include "data/generic_data.h"
#include "data/intro_data.h"

u8 ProcessComplexOam(u32 oamSlot, i16 xPosition, i16 yPosition, u16 rotation, i16 scaling, u8 doubleSize, u8 matrixNum)
{
    // https://decomp.me/scratch/rFihS

    i32 y;    
    i32 x;
    i32 xOffset;
    i32 yOffset;
    u8 shape;
    u8 size;
    u8 unk_0;
    u8 unk_1;
    i32 unk_2;
    i32 unk_3;
    i32 tmpX;
    i32 tmpY;
    i32 scaledX;
    i32 scaledY;

    xOffset = (i16)((u16)xPosition + BLOCK_SIZE);
    yOffset = (i16)((u16)yPosition + BLOCK_SIZE);

    shape = gOamData[oamSlot].split.shape;
    size = gOamData[oamSlot].split.size;

    unk_0 = sArray_45fd24[shape][size];
    unk_1 = sArray_45fd30[shape][size];

    x = (i16)(gOamData[oamSlot].split.x + xOffset) & 0x1FF;
    y = (i16)(gOamData[oamSlot].split.y + yOffset) & 0xFF;

    tmpX = (i16)(x - xOffset + unk_0);
    tmpY = (i16)(y - yOffset + unk_1);
    scaledX = (i16)((tmpX * scaling >> 8) - tmpX);
    scaledY = (i16)((tmpY * scaling >> 8) - tmpY);

    x = (i16)(x + scaledX);
    y = (i16)(y + scaledY);

    unk_2 = (i16)(x - xOffset + unk_0);
    unk_3 = (i16)(y - yOffset + unk_1);

    x = (i16)((unk_2 * cos(rotation) - unk_3 * sin(rotation)) >> 8);
    y = (i16)((unk_2 * sin(rotation) + unk_3 * cos(rotation)) >> 8);

    if (!doubleSize)
    {
        gOamData[oamSlot].split.affineMode = 1;

        x = (i16)(x - unk_0);
        y = (i16)(y - unk_1);
    }
    else
    {
        gOamData[oamSlot].split.affineMode = 3;

        x = (i16)(x - unk_0 * 2);
        y = (i16)(y - unk_1 * 2);
    }

    gOamData[oamSlot].split.x = (x + xOffset - BLOCK_SIZE) & 0x1FF;
    gOamData[oamSlot].split.y = (y + yOffset - BLOCK_SIZE) & 0xFF;


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

void CalculateOamPart4(u16 rotation, i16 scaling, u8 oamSlot)
{
    // https://decomp.me/scratch/jijJJ

    i32 dy1;
    i32 dmy1;
    i32 dx1;
    i32 dmx1;
    i32 dy2;
    i32 dmy2;
    
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
