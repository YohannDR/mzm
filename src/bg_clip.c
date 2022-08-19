#include "bg_clip.h"
#include "globals.h"
#include "../data/data.h"

void BGClipMotherBrainUpdateGlass(u8 bg, u16 value, u16 yPosition, u16 xPosition)
{

}

void BGClipSetBG1BlockValue(u16 value, u16 yPosition, u16 xPosition)
{
    // https://decomp.me/scratch/1BdqX

    /*u16* pDst;
    u16 topOffset;
    u16 bottomOffset;

    gBGPointersAndDimensions.backgrounds[1].pDecomp[yPosition * gBGPointersAndDimensions.backgrounds[1].width + xPosition] = value;

    if ((gBG1YPosition >> 0x6) - 0x4 <= yPosition &&
        yPosition <= (gBG1YPosition >> 0x6) + 0xD &&
        (gBG1XPosition >> 0x6) - 0x4 <= xPosition &&
        xPosition <= (gBG1XPosition >> 0x6) + 0x12)
    {
        pDst = (u16*)(VRAM_BASE + 0x1000);
        if (xPosition & 0x10)
            pDst = (u16*)(VRAM_BASE + 0x1800);

        pDst += (yPosition & 0xF) * 0x40 + (xPosition & 0xF) * 0x2;
        topOffset = value * 0x4;

        bottomOffset = topOffset | 1;
        pDst[0] = gTilemapAndClipPointers.pTilemap[topOffset];

        topOffset = bottomOffset + 1;
        pDst[1] = gTilemapAndClipPointers.pTilemap[bottomOffset];

        pDst[32] = gTilemapAndClipPointers.pTilemap[topOffset];
        
        bottomOffset = topOffset + 1;
        pDst[33] = gTilemapAndClipPointers.pTilemap[bottomOffset];
    }*/
}

/**
 * @brief 5a628 | 24 | Sets the raw value of a BG1 block
 * 
 * @param value Block value
 * @param yPosition Y Position
 * @param xPosition X Position
 */
void BGClipSetRawBG1BlockValue(u16 value, u16 yPosition, u16 xPosition)
{
    gBGPointersAndDimensions.backgrounds[1].pDecomp[gBGPointersAndDimensions.backgrounds[1].width * yPosition + xPosition] = value;
}

/**
 * @brief 5a64c | 24 | Sets the value of a clipdata block
 * 
 * @param value Block value
 * @param yPosition Y Position
 * @param xPosition X Position
 */
void BGClipSetClipdataBlockValue(u16 value, u16 yPosition, u16 xPosition)
{
    gBGPointersAndDimensions.pClipDecomp[gBGPointersAndDimensions.clipdataWidth * yPosition + xPosition] = value;
}

/**
 * @brief 5a670 | 58 | Calls other functions related to checking special clipdata
 * 
 */
void BGClipCheckTouchingSpecialClipdata(void)
{
    BGClipCheckGrabbingCrumnbleBlock(FALSE);
    if (gSamusData.pose == SPOSE_USING_AN_ELEVATOR)
        BGClipCheckTouchingTransitionOnElevator();
    else if (!gDisableDoorAndTanks)
    {
        if (gFrameCounter8Bit & 0x1)
            BGClipCheckTouchingTransitionOrTank();
        else if (!gDisableClipdataChangingTransparency)
            BGClipApplyClipdataChangingTransparency();
        
        BGClipCheckWalkingOnCrumbleBlock();
    }
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
    // https://decomp.me/scratch/agN3y

    /*u32 ignoreBlock;
    i32 xOffsetLeft;
    u16 xOffsetRight;
    u16 xPosition;
    u16 yPosition;
    i32 behavior;
    u32 stopSamus;

    behavior = gSamusData.yVelocity >> 0x1F;
    if (gSamusPhysics.standingStatus == STANDING_NOT_IN_CONTROL)
        behavior++;

    if (!behavior)
    {
        xOffsetRight = (gSamusData.xPosition + gSamusPhysics.drawDistanceRightOffset) >> 0x6;
        if (xOffsetRight > gBGPointersAndDimensions.clipdataWidth)
            xOffsetRight = gBGPointersAndDimensions.clipdataWidth;

        behavior = gSamusData.xPosition + gSamusPhysics.drawDistanceLeftOffset;
        if (behavior < 0x0)
            behavior = 0x0;

        xPosition = behavior >> 0x6;
        yPosition = (gSamusData.yPosition + gSamusPhysics.drawDistanceBottomOffset + 0x2) >> 0x6;

        if (yPosition > gBGPointersAndDimensions.clipdataHeight)
            yPosition = gBGPointersAndDimensions.clipdataHeight;

        for (; xPosition <= xOffsetRight; xPosition++)
        {
            behavior = gTilemapAndClipPointers.pClipBehaviors[gBGPointersAndDimensions.
                pClipDecomp[yPosition * gBGPointersAndDimensions.clipdataWidth + xPosition]];

            if (behavior == CLIP_BEHAVIOR_CRUMBLE_BLOCK)
            {
                behavior = FALSE;
                if ((gSamusData.pose == SPOSE_RUNNING || gSamusData.pose == SPOSE_ROLLING) && gSamusData.speedboostingShinesparking)
                    behavior = TRUE;

                BlockStoreBrokenReformBlock(BLOCK_TYPE_CRUMBLE, xPosition, yPosition, (u8)behavior);
            }
            else if (behavior == CLIP_BEHAVIOR_SLOW_CRUMBLE_BLOCK)
            {
                if (BlockStoreBrokenReformBlock(BLOCK_TYPE_SLOW_CRUMBLE, xPosition, yPosition, TRUE))
                {
                    BGClipSetBG1BlockValue(0x401, yPosition, xPosition);
                    BGClipSetClipdataBlockValue(0x401, yPosition, xPosition);
                }
            }
        }
    }*/
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