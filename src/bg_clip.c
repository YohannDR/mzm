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
    gBGPointersAndDimensions.backgrounds[1].pDecomp[gBGPointersAndDimensions.backgrounds[1].width * yPosition + xPosition] = value;
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

    offset = clip - 0x44;
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

/**
 * @brief 5ae1c | 104 | Checks if samus is grabbing a crumble block
 * 
 * @param dontDestroy 
 */
void BGClipCheckGrabbingCrumnbleBlock(u8 dontDestroy)
{
    u8 setPose;
    i32 yOffset;
    i32 xOffset;
    u16 yPosition;
    u16 xPosition;
    u16 behavior;

    if (gSamusPhysics.standingStatus != STANDING_HANGING)
        return;

    setPose = FALSE;
    yOffset = -0x6C;
    if (gSamusData.direction & KEY_RIGHT)
        xOffset = BLOCK_SIZE / 2;
    else
        xOffset = -(BLOCK_SIZE / 2);

    if (gSamusData.pose != SPOSE_HANGING_ON_LEDGE && gSamusData.pose != SPOSE_GRABBING_A_LEDGE_SUITLESS)
        xOffset = -xOffset;

    if (!dontDestroy)
    {
        // Get position
        xPosition = (gSamusData.xPosition + xOffset) >> 0x6;
        yPosition = (gSamusData.yPosition + yOffset) >> 0x6;

        // Get behavior
        behavior = gTilemapAndClipPointers.pClipBehaviors[gBGPointersAndDimensions.
            pClipDecomp[yPosition * gBGPointersAndDimensions.clipdataWidth + xPosition]];

        // Check is crumble
        if (behavior == CLIP_BEHAVIOR_CRUMBLE_BLOCK)
        {
            // Destroy block
            if (BlockStoreBrokenReformBlock(BLOCK_TYPE_CRUMBLE, xPosition, yPosition, FALSE))
                setPose = TRUE;
        }
        else if (behavior == CLIP_BEHAVIOR_SLOW_CRUMBLE_BLOCK)
        {
            // Destroy block
            if (BlockStoreBrokenReformBlock(BLOCK_TYPE_SLOW_CRUMBLE, xPosition, yPosition, TRUE))
            {
                BGClipSetBG1BlockValue(0x401, yPosition, xPosition);
                BGClipSetClipdataBlockValue(0x401, yPosition, xPosition);
                setPose = FALSE;
            }
        }
    }

    if (!setPose)
    {
        if (!(ClipdataProcessForSamus(gSamusData.yPosition + yOffset, gSamusData.xPosition + xOffset) & CLIPDATA_TYPE_SOLID_FLAG))
            setPose = TRUE;
    }
    if (setPose)
        SamusSetPose(SPOSE_UPDATE_JUMP_VELOCITY_REQUEST);
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