#include "gba.h"
#include "bg_clip.h"
#include "transparency.h"
#include "block.h"
#include "minimap.h"
#include "connection.h"
#include "macros.h"

#include "data/block_data.h"

#include "constants/block.h"
#include "constants/connection.h"
#include "constants/clipdata.h"
#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/text.h"

#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/connection.h"
#include "structs/transparency.h"
#include "structs/game_state.h"
#include "structs/samus.h"

/**
 * @brief 5a484 | d8 | Sets the value for a BG block
 * 
 * @param bg Background
 * @param value Value
 * @param yPosition Y position
 * @param xPosition X position
 */
void BgClipSetBgBlockValue(u8 bg, u16 value, u16 yPosition, u16 xPosition)
{
    u16* dst;
    u16 offset;

    // Write value
    gBgPointersAndDimensions.backgrounds[bg].pDecomp[yPosition * gBgPointersAndDimensions.backgrounds[bg].width + xPosition] = value;

    // Check is on screen, no need to update the tilemap if off screen, that can be delegated to the room tilemap update functions
    offset = gBG1YPosition / BLOCK_SIZE;
    if ((s32)(offset - 4) > yPosition)
        return;
    
    if (yPosition > (offset + 13))
        return;

    offset = gBG1XPosition / BLOCK_SIZE;
    if ((s32)(offset - 4) > xPosition)
        return;

    if (xPosition > (s32)(offset + 18))
        return;

    // Update tilemap
    dst = (u16*)(VRAM_BASE + bg * 0x1000);
    if (xPosition & 0x10)
        dst = (u16*)(VRAM_BASE + 0x800 + bg * 0x1000);

    dst += (yPosition & 0xF) * 64 + (xPosition & 0xF) * 2;
    
    offset = value * 4;
        
    dst[0] = gTilemapAndClipPointers.pTilemap[offset++];
    dst[1] = gTilemapAndClipPointers.pTilemap[offset++];
    dst[32] = gTilemapAndClipPointers.pTilemap[offset++];
    dst[33] = gTilemapAndClipPointers.pTilemap[offset];
}

/**
 * @brief 5a55c | cc | Sets the value for a BG1 block
 * 
 * @param value Value
 * @param yPosition Y position
 * @param xPosition X position
 */
void BgClipSetBG1BlockValue(u16 value, u16 yPosition, u16 xPosition)
{
    u16* dst;
    u16 offset;

    // Write value
    gBgPointersAndDimensions.backgrounds[1].pDecomp[yPosition * gBgPointersAndDimensions.backgrounds[1].width + xPosition] = value;

    // Check is on screen, no need to update the tilemap if off screen, that can be delegated to the room tilemap update functions
    offset = gBG1YPosition / BLOCK_SIZE;
    if (offset - 4 > yPosition)
        return;
    
    if (yPosition > (offset + 13))
        return;

    offset = gBG1XPosition / BLOCK_SIZE;
    if (offset - 4 > xPosition)
        return;

    if (xPosition > offset + 18)
        return;

    // Update tilemap
    dst = (u16*)(VRAM_BASE + 0x1000);
    if (xPosition & 0x10)
        dst = (u16*)(VRAM_BASE + 0x1800);

    dst += (yPosition & 0xF) * 64 + (xPosition & 0xF) * 2;
    
    offset = value * 4;
        
    dst[0] = gTilemapAndClipPointers.pTilemap[offset++];
    dst[1] = gTilemapAndClipPointers.pTilemap[offset++];
    dst[32] = gTilemapAndClipPointers.pTilemap[offset++];
    dst[33] = gTilemapAndClipPointers.pTilemap[offset];
}

/**
 * @brief 5a628 | 24 | Sets the raw value of a BG1 block
 * 
 * @param value Block value
 * @param yPosition Y Position
 * @param xPosition X Position
 */
void BgClipSetRawBG1BlockValue(u32 value, u16 yPosition, u16 xPosition)
{
    gBgPointersAndDimensions.backgrounds[1].pDecomp[gBgPointersAndDimensions.backgrounds[1].width * yPosition + xPosition] = value;
}

/**
 * @brief 5a64c | 24 | Sets the value of a clipdata block
 * 
 * @param value Block value
 * @param yPosition Y Position
 * @param xPosition X Position
 */
void BgClipSetClipdataBlockValue(u16 value, u16 yPosition, u16 xPosition)
{
    gBgPointersAndDimensions.pClipDecomp[gBgPointersAndDimensions.clipdataWidth * yPosition + xPosition] = value;
}

/**
 * @brief 5a670 | 58 | Calls other functions related to checking special clipdata
 * 
 */
void BgClipCheckTouchingSpecialClipdata(void)
{
    BgClipCheckGrabbingCrumnbleBlock(FALSE);
    if (gSamusData.pose == SPOSE_USING_AN_ELEVATOR)
        BgClipCheckTouchingTransitionOnElevator();
    else if (!gDisableDoorAndTanks)
    {
        if (gFrameCounter8Bit & 0x1)
            BgClipCheckTouchingTransitionOrTank();
        else if (!gDisableClipdataChangingTransparency)
            BgClipApplyClipdataChangingTransparency();
        
        BgClipCheckWalkingOnCrumbleBlock();
    }
}

void BGClipApplyClipdataChangingTransparency(void)
{
    // https://decomp.me/scratch/qCOUj

    u32 clipdata;
    u32 xPosition;
    u32 yPosition;
    s32 position;

    position = gSamusData.xPosition;
    if (position > gBgPointersAndDimensions.clipdataWidth * BLOCK_SIZE)
        position = gBgPointersAndDimensions.clipdataWidth * BLOCK_SIZE;

    xPosition = position >> 6;

    position = gSamusData.yPosition + (gSamusPhysics.drawDistanceTopOffset >> 1);
    if (position < 0)
        position = 0;
    else
    {
        if (position > gBgPointersAndDimensions.clipdataHeight * BLOCK_SIZE)
            position = gBgPointersAndDimensions.clipdataHeight * BLOCK_SIZE;
    }

    yPosition = position >> 6;

    clipdata = gTilemapAndClipPointers.pClipBehaviors[gBgPointersAndDimensions.pClipDecomp[yPosition * gBgPointersAndDimensions.clipdataWidth + xPosition]];
    if (clipdata == CLIP_BEHAVIOR_NONE)
        return;

    clipdata = BgClipGetNewBldalphaValue(clipdata, clipdata);
    if (clipdata == 0)
        return;
    
    if (clipdata == USHORT_MAX)
        TransparencyUpdateBLDALPHA(gDefaultTransparency.evaCoef, gDefaultTransparency.evbCoef, 1, 1);
    else
        TransparencyUpdateBLDALPHA(clipdata & UCHAR_MAX, (clipdata & 0xFF00) >> 8, 1, 1);
}

/**
 * @brief 5a770 | 30 | Tries to get a bldalpha value based on a clipdata behavior
 * 
 * @param clip Clipdata behavior
 * @param unused Unused parameter
 * @return u16 Bldalpha value (eva on first 8 bits, then evb on next 8 bits)
 */
u16 BgClipGetNewBldalphaValue(u16 clip, u16 unused)
{
    u16 bldalpha;

    // Check is a bldapha change behavior (trigger transparent, opaque, brighter)
    if ((u16)BEHAVIOR_TO_BLDALPHA(clip) < BEHAVIOR_TO_BLDALPHA(CLIP_BEHAVIOR_BG0_TRIGGER_DEFAULT_TRANSPARENCY))
    {
        // Fetch the correct value
        bldalpha = sBldalphaValuesForClipdata[BEHAVIOR_TO_BLDALPHA(clip)];
    }
    else if (clip == CLIP_BEHAVIOR_BG0_TRIGGER_DEFAULT_TRANSPARENCY)
    {
        // Request the default transparency to take over
        bldalpha = USHORT_MAX;
    }
    else
    {
        // Not an appropriate behavior, return nothing
        bldalpha = 0;
    }
    
    return bldalpha;
}

/**
 * @brief 5a7a0 | 108 | Checks if samus is walking on a crumble block
 * 
 */
void BgClipCheckWalkingOnCrumbleBlock(void)
{
    u32 ignoreBlock;
    s32 xOffsetLeft;
    u16 checkPos;
    u16 xPosition;
    u16 yPosition;
    s32 behavior;
    u32 stopSamus;
    u16 i;

    // Check falling
    if (gSamusData.yVelocity < 0)
        behavior = TRUE;
    else
        behavior = FALSE;
    
    if (gSamusPhysics.standingStatus == STANDING_NOT_IN_CONTROL)
        behavior++;

    if (behavior)
        return;

    // Get max position to check for crumble blocks
    behavior = gSamusData.xPosition + gSamusPhysics.drawDistanceRightOffset;

    checkPos = (u32)behavior / BLOCK_SIZE;
    if (checkPos > gBgPointersAndDimensions.clipdataWidth)
        checkPos = gBgPointersAndDimensions.clipdataWidth;

    // Get positions
    behavior = gSamusData.xPosition + gSamusPhysics.drawDistanceLeftOffset;
    if (behavior < 0)
        behavior = 0;

    xPosition = (u32)behavior / BLOCK_SIZE;

    behavior = gSamusData.yPosition + gSamusPhysics.drawDistanceBottomOffset;
    yPosition = (u32)(behavior + 2) / BLOCK_SIZE;

    if (yPosition > gBgPointersAndDimensions.clipdataHeight)
        yPosition = gBgPointersAndDimensions.clipdataHeight;

    // Loop from current position to the check position
    for (i = xPosition; i <= checkPos; i++)
    {
        // Get clipdata behavior
        behavior = gTilemapAndClipPointers.pClipBehaviors[gBgPointersAndDimensions.
            pClipDecomp[yPosition * gBgPointersAndDimensions.clipdataWidth + i]];

        if (behavior == CLIP_BEHAVIOR_CRUMBLE_BLOCK)
        {
            // Check if speedboosting to not directly destroy the floor under samus, allows to run over crumble blocks
            behavior = FALSE;
            if ((gSamusData.pose == SPOSE_RUNNING || gSamusData.pose == SPOSE_ROLLING) && gSamusData.speedboostingShinesparking)
                behavior = TRUE;

            // Store block
            BlockStoreBrokenReformBlock(BLOCK_TYPE_CRUMBLE, i, yPosition, behavior);
        }
        else if (behavior == CLIP_BEHAVIOR_SLOW_CRUMBLE_BLOCK)
        {
            // Store block
            if (BlockStoreBrokenReformBlock(BLOCK_TYPE_SLOW_CRUMBLE, i, yPosition, TRUE))
            {
                // Set "crumbling" graphics for the block
                BgClipSetBG1BlockValue(CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID, yPosition, i);
                BgClipSetClipdataBlockValue(CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID, yPosition, i);
            }
        }
    }
}

void BgClipCheckTouchingTransitionOnElevator(void)
{
    // https://decomp.me/scratch/tH2oX
    
    u32 goingDown;
    s32 position;
    u16 xPosition;
    u16 yPosition;
    s32 onTransition;
    u16 behavior;

    goingDown = (gSamusData.elevatorDirection ^ KEY_UP) != 0;

    position = gSamusData.xPosition;
    if (position > gBgPointersAndDimensions.clipdataWidth * BLOCK_SIZE)
        position = gBgPointersAndDimensions.clipdataWidth * BLOCK_SIZE;

    xPosition = (u32)position / BLOCK_SIZE;

    if (!goingDown)
    {
        position = gSamusData.yPosition + gSamusPhysics.drawDistanceBottomOffset + BLOCK_SIZE * 2;
    }
    else
    {
        position = gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset - BLOCK_SIZE * 2;
    }

    behavior = position;
    if (position < 0)
        behavior = 0;
    else
    {
        if (behavior > gBgPointersAndDimensions.clipdataHeight * BLOCK_SIZE)
            behavior = gBgPointersAndDimensions.clipdataHeight * BLOCK_SIZE;
    }

    yPosition = behavior / BLOCK_SIZE;

    onTransition = gBgPointersAndDimensions.pClipDecomp[
        yPosition * gBgPointersAndDimensions.clipdataWidth + xPosition];
    behavior = gTilemapAndClipPointers.pClipBehaviors[onTransition];

    onTransition = FALSE;
    if (!goingDown)
    {
        if (behavior == CLIP_BEHAVIOR_VERTICAL_UP_TRANSITION)
            onTransition = TRUE;
    }
    else
    {
        if (behavior == CLIP_BEHAVIOR_VERTICAL_DOWN_TRANSITION)
            onTransition = TRUE;
    }

    if (!onTransition)
        return;

    if (!ConnectionCheckAreaConnection(yPosition, xPosition))
    {
        ConnectionCheckEnterDoor(yPosition, xPosition);
    }
}

/**
 * @brief 5a96c | 420 | Checks if samus is touching a transition or a tank
 * 
 */
void BgClipCheckTouchingTransitionOrTank(void)
{
    s32 behaviors[4];
    s32 yPositions[3];
    s32 xPositions[3];
    s32 i;
    s32 j;
    s32 isFirstTank;

    // Get X positions
    // On the right
    j = (gSamusPhysics.drawDistanceRightOffset >> 1) + gSamusData.xPosition;
    CLAMP2(j, 0, gBgPointersAndDimensions.clipdataWidth * BLOCK_SIZE);
    xPositions[0] = j >> 6;

    // On the left
    j = (gSamusPhysics.drawDistanceLeftOffset >> 1) + gSamusData.xPosition;
    CLAMP2(j, 0, gBgPointersAndDimensions.clipdataWidth * BLOCK_SIZE);
    xPositions[1] = j >> 6;

    // Center
    j = gSamusData.xPosition;
    CLAMP2(j, 0, gBgPointersAndDimensions.clipdataWidth * BLOCK_SIZE);
    xPositions[2] = j >> 6;

    // Get Y positions
    // Center
    j = (gSamusPhysics.drawDistanceTopOffset >> 1) + gSamusData.yPosition;
    CLAMP2(j, 0, gBgPointersAndDimensions.clipdataHeight * BLOCK_SIZE);
    yPositions[0] = j >> 6;

    // Bottom
    j = (gSamusPhysics.drawDistanceTopOffset >> 2) + gSamusData.yPosition;
    CLAMP2(j, 0, gBgPointersAndDimensions.clipdataHeight * BLOCK_SIZE);
    yPositions[1] = j >> 6;

    // Top
    j = (gSamusPhysics.drawDistanceTopOffset >> 2) + (gSamusPhysics.drawDistanceTopOffset >> 1) + gSamusData.yPosition;
    CLAMP2(j, 0, gBgPointersAndDimensions.clipdataHeight * BLOCK_SIZE);
    yPositions[2] = j >> 6;

    // Get clipdata behaviors on the X axis
    for (i = 0; i < ARRAY_SIZE(xPositions) - 1; i++)
    {
        j = gBgPointersAndDimensions.pClipDecomp[gBgPointersAndDimensions.clipdataWidth * yPositions[0] + xPositions[i]];
        behaviors[i] = gTilemapAndClipPointers.pClipBehaviors[j];
    }

    // Get clipdata behaviors on the y axis
    for (i = 0; i < ARRAY_SIZE(yPositions) - 1; i++)
    {
        j = gBgPointersAndDimensions.pClipDecomp[yPositions[i + 1] * gBgPointersAndDimensions.clipdataWidth + xPositions[2]];
        behaviors[i + 2] = gTilemapAndClipPointers.pClipBehaviors[j];
    }

    // Check if at least one behavior was found
    if ((behaviors[0] | behaviors[1] | behaviors[2] | behaviors[3]) == CLIP_BEHAVIOR_NONE)
        return;

    // Check for transition clipdata
    j = -1;
    if (behaviors[0] == CLIP_BEHAVIOR_DOOR_TRANSITION)
        j = 0;
    else if (behaviors[1] == CLIP_BEHAVIOR_DOOR_TRANSITION)
        j = 1;
    else if (behaviors[2] == CLIP_BEHAVIOR_VERTICAL_UP_TRANSITION)
        j = 2;
    else if (behaviors[3] == CLIP_BEHAVIOR_VERTICAL_DOWN_TRANSITION)
        j = 3;

    if (j + 1 != 0)
    {
        // Check for door
        if (!ConnectionCheckEnterDoor(yPositions[sHatchRelated_345cee[j][0]], xPositions[sHatchRelated_345cee[j][1]]))
        {
            ConnectionCheckAreaConnection(yPositions[sHatchRelated_345cee[j][0]], xPositions[sHatchRelated_345cee[j][1]]);
        }
        return;
    }

    // Abort if already collecting a tank
    if (gCollectingTank)
        return;

    isFirstTank = FALSE;

    for (j = 3; j >= 0; j--)
    {
        // No behavior, continue
        if (behaviors[j] == 0)
            continue;

        // Not a tank behavior, continue
        if (BEHAVIOR_TO_TANK(behaviors[j]) > (u32)BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_UNDERWATER_POWER_BOMB_TANK))
            continue;

        // Get item type
        i = sTankBehaviors[BEHAVIOR_TO_TANK(behaviors[j])].itemType;

        // Check is an item (hidden tanks not broken aren't tanks yet)
        if (i != ITEM_TYPE_NONE)
        {
            // Check the tile is explored
            if (MinimapCheckIsTileExplored(xPositions[sHatchRelated_345cee[j][1]], yPositions[sHatchRelated_345cee[j][0]]))
            {
                // Set flag and stop samus
                gCollectingTank = TRUE;
                gPreventMovementTimer = 0x3E8;

                // Set last tankk collected data
                gLastTankCollected.behavior = behaviors[j];
                gLastTankCollected.xPosition = xPositions[sHatchRelated_345cee[j][1]];
                gLastTankCollected.yPosition = yPositions[sHatchRelated_345cee[j][0]];

                // Apply tank :
                // Check not above max (max number of tanks * increase amount + starting) >= current max + increase
                // Check if it's not first tank of that type (except for energy)
                // Apply increment to max and current

                if (i == ITEM_TYPE_MISSILE)
                {
                    if (sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].missile * sTankIncreaseAmount[gDifficulty].missile + sStartingHealthAmmo.missile >= gEquipment.maxMissiles + sTankIncreaseAmount[gDifficulty].missile)
                    {
                        if (gEquipment.maxMissiles == 0)
                            isFirstTank = TRUE;

                        gEquipment.maxMissiles += sTankIncreaseAmount[gDifficulty].missile;
                        gEquipment.currentMissiles += sTankIncreaseAmount[gDifficulty].missile;
                    }
                }
                else if (i == ITEM_TYPE_ENERGY)
                {
                    if (sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].energy * sTankIncreaseAmount[gDifficulty].energy + sStartingHealthAmmo.energy >= gEquipment.maxEnergy + sTankIncreaseAmount[gDifficulty].energy)
                    {
                        gEquipment.maxEnergy += sTankIncreaseAmount[gDifficulty].energy;
                        gEquipment.currentEnergy = gEquipment.maxEnergy;
                    }
                }
                else if (i == ITEM_TYPE_SUPER_MISSILE)
                {
                    if (sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].superMissile * sTankIncreaseAmount[gDifficulty].superMissile + sStartingHealthAmmo.superMissile >= gEquipment.maxSuperMissiles + sTankIncreaseAmount[gDifficulty].superMissile)
                    {
                        if (gEquipment.maxSuperMissiles == 0)
                            isFirstTank = TRUE;

                        gEquipment.maxSuperMissiles += sTankIncreaseAmount[gDifficulty].superMissile;
                        gEquipment.currentSuperMissiles += sTankIncreaseAmount[gDifficulty].superMissile;
                    }
                }
                else if (i == ITEM_TYPE_POWER_BOMB)
                {
                    if (sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].powerBomb * sTankIncreaseAmount[gDifficulty].powerBomb + sStartingHealthAmmo.powerBomb >= gEquipment.maxPowerBombs + sTankIncreaseAmount[gDifficulty].powerBomb)
                    {
                        if (gEquipment.maxPowerBombs == 0)
                            isFirstTank = TRUE;

                        gEquipment.maxPowerBombs += sTankIncreaseAmount[gDifficulty].powerBomb;
                        gEquipment.currentPowerBombs += sTankIncreaseAmount[gDifficulty].powerBomb;
                    }
                }

                // Spawn the item banner
                i = sTankBehaviors[BEHAVIOR_TO_TANK(behaviors[j])].messageID + isFirstTank;
                if (i != MESSAGE_NONE)
                {
                    SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, i, 6, gSamusData.yPosition, gSamusData.xPosition, 0);
                }
            }
        }

        // Collecting a tank, abort
        if (gCollectingTank)
            break;
    }
}

/**
 * @brief 5ad8c | 60 | Finishes the collection of a tank
 * 
 */
void BgClipFinishCollectingTank(void)
{
    u32 clipdata;
    u32 tank;

    gCollectingTank = FALSE;

    tank = BEHAVIOR_TO_TANK(gLastTankCollected.behavior);
    if (sTankBehaviors[tank].itemType != ITEM_TYPE_NONE)
    {
        // Get clip
        if (sTankBehaviors[tank].underwater)
            clipdata = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_WATER;
        else
            clipdata = 0;

        BgClipSetBG1BlockValue(0, gLastTankCollected.yPosition, gLastTankCollected.xPosition);
        BgClipSetBG1BlockValue(clipdata, gLastTankCollected.yPosition, gLastTankCollected.xPosition);
        BgClipSetItemAsCollected(gLastTankCollected.xPosition, gLastTankCollected.yPosition, sTankBehaviors[tank].itemType);
        MinimapUpdateForCollectedItem(gLastTankCollected.xPosition, gLastTankCollected.yPosition);
    }
}

void BgClipFinishCollectingAbility(void)
{
    BgClipSetItemAsCollected(gSamusData.xPosition >> 0x6, gSamusData.yPosition >> 0x6, ITEM_TYPE_ABILITY);
    MinimapUpdateForCollectedItem((u8)(gSamusData.xPosition >> 0x6), (u8)(gSamusData.yPosition >> 0x6));
}

/**
 * @brief 5ae1c | 104 | Checks if samus is grabbing a crumble block
 * 
 * @param dontDestroy 
 */
void BgClipCheckGrabbingCrumnbleBlock(u8 dontDestroy)
{
    u8 setPose;
    s32 yOffset;
    s32 xOffset;
    u16 yPosition;
    u16 xPosition;
    u16 behavior;

    if (gSamusPhysics.standingStatus != STANDING_HANGING)
        return;

    setPose = FALSE;
    yOffset = -0x6C;
    if (gSamusData.direction & KEY_RIGHT)
        xOffset = HALF_BLOCK_SIZE;
    else
        xOffset = -(HALF_BLOCK_SIZE);

    if (gSamusData.pose != SPOSE_HANGING_ON_LEDGE && gSamusData.pose != SPOSE_GRABBING_A_LEDGE_SUITLESS)
        xOffset = -xOffset;

    if (!dontDestroy)
    {
        // Get position
        xPosition = (gSamusData.xPosition + xOffset) >> 0x6;
        yPosition = (gSamusData.yPosition + yOffset) >> 0x6;

        // Get behavior
        behavior = gTilemapAndClipPointers.pClipBehaviors[gBgPointersAndDimensions.
            pClipDecomp[yPosition * gBgPointersAndDimensions.clipdataWidth + xPosition]];

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
                BgClipSetBG1BlockValue(0x401, yPosition, xPosition);
                BgClipSetClipdataBlockValue(CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID, yPosition, xPosition);
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

/**
 * @brief 5af20 | 180 | Checks if a hatch should open depending on the CCAA
 * 
 * @param xPosition X Position
 * @param yPosition Y Position
 * @return u8 Hatch opening action
 */
u8 BgClipCheckOpeningHatch(u16 xPosition, u16 yPosition)
{
    s32 i;
    u8 action;

    for (i = 0; i < MAX_AMOUNT_OF_HATCHES; i++)
    {
        if (gHatchData[i].exists && !gHatchData[i].opening)
        {
            action = HATCH_OPENING_ACTION_NOT_OPENING;

            // Check touches hatch and hatch is weak
            if (gHatchData[i].xPosition == xPosition && gHatchData[i].yPosition <= yPosition &&
                yPosition <= gHatchData[i].yPosition + (HATCH_VERTICAL_SIZE - 1) &&
                sHatchBehaviors[gHatchData[i].type][0] &
                sClipdataAffectingActionDamageTypes[gCurrentClipdataAffectingAction])
            {
                // Increase hits
                gHatchData[i].hits++;
                action = HATCH_OPENING_ACTION_OPENING;

                // Check for a special action
                if (gHatchData[i].type == HATCH_LOCKED)
                {
                    // Check hatches are unlocked
                    if (!gHatchesState.unlocking)
                        action = HATCH_OPENING_ACTION_LOCKED;
                }
                else if (gHatchData[i].type == HATCH_LOCKED_AND_LOCK_DESTINATION)
                {
                    if (!gHatchesState.unk)
                        action = HATCH_OPENING_ACTION_LOCKED;
                }
                else if (gHatchData[i].type == HATCH_MISSILE)
                {
                    // Check instantly open
                    if (sClipdataAffectingActionDamageTypes[gCurrentClipdataAffectingAction] & CAA_DAMAGE_TYPE_SUPER_MISSILE)
                        gHatchData[i].hits = sHatchBehaviors[HATCH_MISSILE][1]; // Set max health
                }
            }
            
            if (action != HATCH_OPENING_ACTION_NOT_OPENING)
            {
                if (action == HATCH_OPENING_ACTION_OPENING)
                {
                    // Check enough hits
                    if (gHatchData[i].hits >= sHatchBehaviors[gHatchData[i].type][1])
                    {
                        // Unlock
                        gHatchData[i].locked = FALSE;
                        gHatchData[i].opening = TRUE;

                        // Set hatch as opened
                        if (gHatchData[i].type >= HATCH_MISSILE)
                            ConnectionSetHatchAsOpened(HATCH_ACTION_SETTING_SOURCE_AND_DESTINATION, gHatchData[i].sourceDoor);
                        else
                            ConnectionSetHatchAsOpened(HATCH_ACTION_SETTING_SOURCE, gHatchData[i].sourceDoor);
                    }
                    else
                        gHatchData[i].flashingTimer = 0x1; // Set flashing
                }
                else
                    gHatchData[i].hits = 0x0; // Locked, reset

                gHatchData[i].hitTimer = 0x0;
                break;
            }
        }
    }

    return action;
}

/**
 * @brief 5b0a0 | 74 | Regsiters a collected item in the save
 * 
 * @param xPosition X position
 * @param yPosition Y position
 * @param type Item type
 */
void BgClipSetItemAsCollected(u16 xPosition, u16 yPosition, u8 type)
{
    u8 overLimit;
    s32 i;
    u8* pItem;
    s32 limit;

    if (gCurrentArea > MAX_AMOUNT_OF_AREAS)
        return;

    i = gCurrentArea;
    limit = MAX_AMOUNT_OF_ITEMS_PER_AREA;
    overLimit = TRUE;
    pItem = (u8*)0x2036c00 + i * MAX_AMOUNT_OF_ITEMS_PER_AREA * sizeof(struct ItemInfo);

    for (i = 0; i < limit; i++, pItem += 4)
    {
        if (pItem[0] == UCHAR_MAX)
        {
            overLimit = FALSE;
            break;
        }
    }

    if (!overLimit)
    {
        *pItem++ = gCurrentRoom;
        *pItem++ = type;
        *pItem++ = xPosition;
        *pItem++ = yPosition;

        gNumberOfItemsCollected[gCurrentArea]++;
    }
}

/**
 * @brief 5b114 | c4 | Removes the collected tanks of a room
 * 
 */
void BgClipRemoveCollectedTanks(void)
{
    struct ItemInfo* pItem;
    s32 i;
    s32 limit;
    s32 position;
    u32 behavior;
    u32 temp;

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
        return;

    if (gCurrentArea > MAX_AMOUNT_OF_AREAS)
        return;
    
    i = gCurrentArea;
    limit = MAX_AMOUNT_OF_ITEMS_PER_AREA;
    pItem = (struct ItemInfo*)0x2036c00 + i * MAX_AMOUNT_OF_ITEMS_PER_AREA;

    for (i = 0; i < limit; i++, pItem++)
    {
        if (pItem->room == UCHAR_MAX)
            return;
        
        if (pItem->room == gCurrentRoom && pItem->type >= 0)
        {
            position = gBgPointersAndDimensions.clipdataWidth * pItem->yPosition + pItem->xPosition;

            behavior = gTilemapAndClipPointers.pClipBehaviors[gBgPointersAndDimensions.pClipDecomp[position]] -
                CLIP_BEHAVIOR_UNDERWATER_ENERGY_TANK;
            if (behavior <= BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_HIDDEN_POWER_BOMB_TANK))
            {
                gBgPointersAndDimensions.pClipDecomp[position] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_WATER;
                gBgPointersAndDimensions.backgrounds[1].pDecomp[position] = 0;
            }
            else
            {
                gBgPointersAndDimensions.pClipDecomp[position] = 0;
                gBgPointersAndDimensions.backgrounds[1].pDecomp[position] = 0;
            }
        }
    }
}

/**
 * @brief 5b1d8 | 74 | Calls the BgClipSetBgBlockValue on every block of the glass
 * 
 * @param stage Breaking stage
 */
void BgClipCallMotherBrainUpdateGlass(u8 stage)
{
    u16 i;
    u16 j;

    // Check in the mother brain room
    if (gCurrentArea != AREA_TOURIAN)
        return;

    if (gCurrentRoom != 4)
        return;

    // Loop on every tile of the glass
    for (i = 0; i < 5; i++) // Y
    {
        for (j = 0; j < 7; j++) // X
        {
            // Fetch the correct tile value, and the correct positions
            BgClipSetBgBlockValue(0, sMotherBrainGlassBreakingBaseTilemapValues[stage] + i * 16 + j, i + 13, j + 4);
        }
    }
}
