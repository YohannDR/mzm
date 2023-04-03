#include "complex_oam.h"
#include "oam.h"
#include "macros.h"
#include "fixed_point.h"

#include "data/generic_data.h"
#include "data/intro_data.h"

u8 ProcessComplexOam(u32 oamSlot, i16 xPosition, i16 yPosition, u16 rotation, i16 scaling, u8 doubleSize, u8 flipSize)
{
    // https://decomp.me/scratch/rFihS

    i16 xOffset;
    i16 yOffset;
    i32 x;
    i32 y;
    u32 shape;
    u32 size;
    u8 unk_0;
    u8 unk_1;

    i16 unk_x;
    i16 unk_y;

    xOffset = xPosition + BLOCK_SIZE;
    yOffset = yPosition + BLOCK_SIZE;

    shape = gOamData[oamSlot].split.shape;
    size = gOamData[oamSlot].split.size;

    unk_0 = sArray_45fd24[shape + size * 4];
    unk_1 = sArray_45fd30[shape + size * 4];

    x = (gOamData[oamSlot].split.x + xOffset) & 0x1FF;
    y = (gOamData[oamSlot].split.y + yOffset) & 0xFF;

    unk_x = x - xOffset;
    unk_y = y - yOffset;

    unk_x = scaling * unk_x / 256 - unk_x;
    unk_y = scaling * unk_y / 256 - unk_y;

    x = x + unk_x;
    y = y + unk_y;

    gOamData[oamSlot].split.y = x * cos(rotation) - y * sin(rotation);
    gOamData[oamSlot].split.y = y * sin(rotation) + y * cos(rotation);

    if (!doubleSize)
    {
        gOamData[oamSlot].split.affineMode = 1;
    }
    else
    {
        gOamData[oamSlot].split.affineMode = 3;
    }



    if (gOamData[oamSlot].split.shape & 2)
    {
        if (gOamData[oamSlot].split.shape & 1)
            gOamData[oamSlot].split.matrixNum = flipSize + 3;
        else
            gOamData[oamSlot].split.matrixNum = flipSize + 1;
    }
    else
    {
        if (gOamData[oamSlot].split.shape & 1)
            gOamData[oamSlot].split.matrixNum = flipSize + 2;
        else
            gOamData[oamSlot].split.matrixNum = flipSize;
    }

    gOamData[oamSlot].split.xFlip = FALSE;
    gOamData[oamSlot].split.yFlip = FALSE;
    return FALSE;
}

void CalculateOamPart4(u16 rotation, i16 scaling, u8 oamSlot)
{
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
