#include "bg_clip.h"
#include "globals.h"
#include "../data/data.h"

void BGClipMotherBrainUpdateGlass(u8 bg, u16 value, u16 yPosition, u16 xPosition)
{

}

void BGClipSetBG1BlockValue(u16 value, u16 yPosition, u16 xPosition)
{

}

void BGClipSetRawBG1BlockValue(u16 value, u16 yPosition, u16 xPosition)
{
    gBGPointersAndDimensions.backgrounds[0x1].pDecomp[gBGPointersAndDimensions.backgrounds[0x1].width * yPosition + xPosition] = value;
}

void BGClipSetClipdataBlockValue(u16 value, u16 yPosition, u16 xPosition)
{
    gBGPointersAndDimensions.pClipDecomp[gBGPointersAndDimensions.clipdataWidth * yPosition + xPosition] = value;
}

void BGClipCheckTouchingSpecialClipdata(void)
{

}

void BGClipApplyClipdataChangingTransparency(void)
{

}

u16 BGClipGetNewBLDALPHAValue(u16 clip)
{
    u16 bldalpha;
    u16 offset;

    offset = (u16)(clip - 0x44);
    if (offset < 0xB)
        return bldalpha_values_for_clipdata[offset];
    else
    {
        bldalpha = 0x0;
        if (clip == 0x4F)
            return 0xFFFF;
    }
    return bldalpha;
}

void BGClipCheckWalkingOnCrumbleBlock(void)
{

}

void BGClipCheckTouchingTransitionOnElevator(void)
{

}

void BGClipCheckTouchingTransitionOrTank(void)
{

}

void BGClipFinishCollectingTank(void)
{

}

void BGClipFinishCollectingAbility(void)
{
    BGClipSetItemAsCollected(gSamusData.xPosition >> 0x6, gSamusData.yPosition >> 0x6, 0x80);
    update_minimap_square_for_collected_items((u8)(gSamusData.xPosition >> 0x6), (u8)(gSamusData.yPosition >> 0x6));
}

void BGClipCheckGrabbingCrumnbleBlock(u8 false)
{

}

u8 BGClipCheckOpeningHatch(u16 xPosition, u16 yPosition)
{

}

void BGClipSetItemAsCollected(u8 xPosition, u8 yPosition, u8 type)
{

}

void BGClipRemoveCollectedTanks(void)
{

}

void BGClipCallMotherBrainUpdateGlass(u8 stage)
{

}