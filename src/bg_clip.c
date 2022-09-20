#include "bg_clip.h"
#include "globals.h"
#include "data/block_data.c"
#include "../data/data.h"

void BGClipMotherBrainUpdateGlass(u8 bg, u16 value, u16 yPosition, u16 xPosition)
{

}

void BGClipSetBG1BlockValue(u32 value, u16 yPosition, u16 xPosition)
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
void BGClipSetRawBG1BlockValue(u32 value, u16 yPosition, u16 xPosition)
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
    // https://decomp.me/scratch/68qvD

    i32 position;
    i32 collectingFirstTank;
    i32 limit;
    struct TankCollectionData collectionData;
    u16* pBehavior;
    i32 i;
    i32 offset;
    u16* pPosition;
    i32 unk;
    u8 tankType;
    i32 newMax;
    i8 messageID;
    i32 max;
    i32 increment;

    position = (gSamusPhysics.drawDistanceRightOffset >> 0x1) + gSamusData.xPosition;
    if (position < 0x0)
        position = 0x0;
    else
    {
        if (position > gBGPointersAndDimensions.clipdataWidth << 0x6)
            position = gBGPointersAndDimensions.clipdataWidth << 0x6;
    }

    collectionData.xPositions[0] = position >> 0x6;

    position = gSamusData.xPosition + (gSamusPhysics.drawDistanceLeftOffset >> 0x1);
    if (position < 0x0)
        position = 0x0;
    else
    {
        if (position > gBGPointersAndDimensions.clipdataWidth << 0x6)
            position = gBGPointersAndDimensions.clipdataWidth << 0x6;
    }

    collectionData.xPositions[1] = position >> 0x6;

    position = gSamusData.xPosition;
    if (position > gBGPointersAndDimensions.clipdataWidth << 0x6)
        position = gBGPointersAndDimensions.clipdataWidth << 0x6;

    collectionData.xPositions[2] = position >> 0x6;

    position = gSamusData.yPosition + (gSamusPhysics.drawDistanceTopOffset >> 0x1);
    if (position < 0x0)
        position = 0x0;
    else
    {
        if (position > gBGPointersAndDimensions.clipdataHeight << 0x6)
            position = gBGPointersAndDimensions.clipdataHeight << 0x6;
    }

    collectionData.yPositions[0] = position;

    position = gSamusData.yPosition + (gSamusPhysics.drawDistanceTopOffset >> 0x2);
    if (position < 0x0)
        position = 0x0;
    else
    {
        if (position > gBGPointersAndDimensions.clipdataHeight << 0x6)
            position = gBGPointersAndDimensions.clipdataHeight << 0x6;
    }

    collectionData.yPositions[1] = position;

    position = gSamusData.yPosition + (gSamusPhysics.drawDistanceTopOffset >> 0x1) + (gSamusPhysics.drawDistanceTopOffset >> 0x2);
    if (position < 0x0)
        position = 0x0;
    else
    {
        if (position > gBGPointersAndDimensions.clipdataHeight << 0x6)
            position = gBGPointersAndDimensions.clipdataHeight << 0x6;
    }

    collectionData.yPositions[2] = position;

    pPosition = collectionData.xPositions;
    pBehavior = collectionData.behaviors;
    for (i = 1; i > 0; i--)
    {
        position = *pPosition++;
        offset = gBGPointersAndDimensions.pClipDecomp[collectionData.yPositions[0] * gBGPointersAndDimensions.clipdataWidth + position];
        *pBehavior++ = gTilemapAndClipPointers.pClipBehaviors[offset];
    }

    pPosition = collectionData.yPositions;
    pBehavior = collectionData.behaviors + 2;
    for (i = 1; i > 0; i--)
    {
        position = *pPosition++;
        offset = gBGPointersAndDimensions.pClipDecomp[position * gBGPointersAndDimensions.clipdataWidth + collectionData.xPositions[0]];
        *pBehavior++ = gTilemapAndClipPointers.pClipBehaviors[offset];
    }

    if (collectionData.behaviors[0] | collectionData.behaviors[1] |
        collectionData.behaviors[2] | collectionData.behaviors[3])
    {
        unk = -1;
        if (collectionData.behaviors[0] == CLIP_BEHAVIOR_DOOR_TRANSITION)
            unk = 0x0;
        else if (collectionData.behaviors[1] == CLIP_BEHAVIOR_DOOR_TRANSITION)
            unk = 0x1;
        else if (collectionData.behaviors[2] == CLIP_BEHAVIOR_VERTICAL_UP_TRANSITION)
            unk = 0x2;
        else if (collectionData.behaviors[3] == CLIP_BEHAVIOR_VERTICAL_DOWN_TRANSITION)
            unk = 0x3;

        if ((unk + 1) != 0)
        {
            if (!ConnectionCheckEnterDoor(collectionData.yPositions[sHatchRelated_345cee[i][1]], collectionData.xPositions[sHatchRelated_345cee[i][0]]))
                ConnectionCheckAreaConnection(collectionData.yPositions[sHatchRelated_345cee[i][1]], collectionData.xPositions[sHatchRelated_345cee[i][0]]);
        }
        else
        {
            collectingFirstTank = FALSE;

            for (position = 3; position >= 0; position--)
            {
                if (collectionData.behaviors[i] != CLIP_BEHAVIOR_AIR_SOLID &&
                    behavior_to_tank(collectionData.behaviors[i]) <
                    behavior_to_tank(CLIP_BEHAVIOR_UNDERWATER_POWER_BOMB_TANK))
                {
                    tankType = sTankBehaviors[behavior_to_tank(collectionData.behaviors[i])].itemType;

                    if (tankType != ITEM_TYPE_NONE)
                    {
                        if (check_tile_is_explored(collectionData.yPositions[sHatchRelated_345cee[i][1]], collectionData.xPositions[sHatchRelated_345cee[i][0]]))
                        {
                            gCollectingTank = TRUE;
                            gPreventMovementTimer = 0x3E8;
                            gLastTankCollected.behavior = collectionData.behaviors[i];
                            gLastTankCollected.xPosition = collectionData.xPositions[i];
                            gLastTankCollected.yPosition = collectionData.yPositions[i];

                            if (tankType == ITEM_TYPE_MISSILE)
                            {
                                max = sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS].missile;
                                increment = sTankIncreaseAmount[gDifficulty].missile;
                                newMax = gEquipment.maxMissiles + increment;
                                if ((increment * max) + sStartingHealthAmmo.missile >= newMax)
                                {
                                    if (gEquipment.maxMissiles == 0x0)
                                        collectingFirstTank = TRUE;

                                    gEquipment.maxMissiles = newMax;
                                    gEquipment.currentMissiles += increment;
                                }
                            }
                            else if (tankType == ITEM_TYPE_ENERGY)
                            {
                                max = sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS].energy;
                                increment = sTankIncreaseAmount[gDifficulty].energy;
                                newMax = gEquipment.maxEnergy + increment;
                                if ((increment * max) + sStartingHealthAmmo.energy >= newMax)
                                {
                                    gEquipment.maxEnergy = newMax;
                                    gEquipment.currentEnergy += increment;
                                }
                            }
                            else if (tankType == ITEM_TYPE_SUPER_MISSILE)
                            {                                
                                max = sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS].superMissile;
                                increment = sTankIncreaseAmount[gDifficulty].superMissile;
                                newMax = gEquipment.maxSuperMissiles + increment;
                                if ((increment * max) + sStartingHealthAmmo.superMissile >= newMax)
                                {
                                    if (gEquipment.maxSuperMissiles == 0x0)
                                        collectingFirstTank = TRUE;

                                    gEquipment.maxSuperMissiles = newMax;
                                    gEquipment.currentSuperMissiles += increment;
                                }
                            }
                            else if (tankType == ITEM_TYPE_POWER_BOMB)
                            {
                                max = sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS].powerBomb;
                                increment = sTankIncreaseAmount[gDifficulty].powerBomb;
                                newMax = gEquipment.maxPowerBombs + increment;
                                if ((increment * max) + sStartingHealthAmmo.powerBomb >= newMax)
                                {
                                    if (gEquipment.maxPowerBombs == 0x0)
                                        collectingFirstTank = TRUE;

                                    gEquipment.maxPowerBombs = newMax;
                                    gEquipment.currentPowerBombs += increment;
                                }
                            }

                            messageID = sTankBehaviors[behavior_to_tank(collectionData.behaviors[i])].messageID + collectingFirstTank;
                            if (messageID != MESSAGE_NONE)
                            {
                                SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, messageID, 0x6,
                                    gSamusData.yPosition, gSamusData.xPosition, 0x0);
                            }
                        }
                    }
                }

                if (gCollectingTank)
                    break;
            }
        }
    }
}

/**
 * @brief 5ad8c | 60 | Finishes the collection of a tank
 * 
 */
void BGClipFinishCollectingTank(void)
{
    u32 clipdata;
    u32 tank;

    gCollectingTank = FALSE;

    tank = behavior_to_tank(gLastTankCollected.behavior);
    if (sTankBehaviors[tank].itemType != ITEM_TYPE_NONE)
    {
        // Get clip
        if (sTankBehaviors[tank].underwater)
            clipdata = 0x43C;
        else
            clipdata = 0x0;

        BGClipSetBG1BlockValue(0x0, gLastTankCollected.yPosition, gLastTankCollected.xPosition);
        BGClipSetBG1BlockValue(clipdata, gLastTankCollected.yPosition, gLastTankCollected.xPosition);
        BGClipSetItemAsCollected(gLastTankCollected.xPosition, gLastTankCollected.yPosition, sTankBehaviors[tank].itemType);
        MinimapUpdateForCollectedItem(gLastTankCollected.xPosition, gLastTankCollected.yPosition);
    }
}

void BGClipFinishCollectingAbility(void)
{
    BGClipSetItemAsCollected(gSamusData.xPosition >> 0x6, gSamusData.yPosition >> 0x6, ITEM_TYPE_ABILITY);
    MinimapUpdateForCollectedItem((u8)(gSamusData.xPosition >> 0x6), (u8)(gSamusData.yPosition >> 0x6));
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

/**
 * @brief 5af20 | 180 | Checks if a hatch should open depending on the CCAA
 * 
 * @param xPosition X Position
 * @param yPosition Y Position
 * @return u8 Hatch opening action
 */
u8 BGClipCheckOpeningHatch(u16 xPosition, u16 yPosition)
{
    i32 i;
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

void BGClipSetItemAsCollected(u16 xPosition, u16 yPosition, u8 type)
{
    // https://decomp.me/scratch/sixf9

    u8 overLimit;
    i32 i;
    u8* pItem;
    i32 limit;

    if (gCurrentArea > MAX_AMOUNT_OF_AREAS)
        return;

    i = gCurrentArea;
    limit = MAX_AMOUNT_OF_ITEMS_PER_AREA;
    overLimit = TRUE;
    pItem = (u8*)gItemsCollected[i];
    i = 0;
    for (; ; pItem += 4)
    {
        if (i >= limit)
            break;
        else if (pItem[0] == 0xFF)
        {
            overLimit = FALSE;
            break;
        }
        i++;
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

void BGClipRemoveCollectedTanks(void)
{
    // https://decomp.me/scratch/RQGNU

    struct ItemInfo* pItem;
    i32 i;
    i32 limit;
    i32 position;
    u32 behavior;
    u32 temp;

    if (gPauseScreenFlag == PAUSE_SCREEN_NONE && gCurrentArea < MAX_AMOUNT_OF_AREAS)
    {
        i = gCurrentArea;
        limit = MAX_AMOUNT_OF_ITEMS_PER_AREA;
        pItem = gItemsCollected[i];
        i = 0;

        for (; i < limit; pItem++)
        {
            if (pItem->room == 0xFF)
                return;
            
            if (pItem->room == gCurrentRoom && pItem->type >= 0)
            {
                position = gBGPointersAndDimensions.clipdataWidth * pItem->yPosition + pItem->xPosition;

                behavior = gTilemapAndClipPointers.pClipBehaviors[gBGPointersAndDimensions.pClipDecomp[position]] - CLIP_BEHAVIOR_UNDERWATER_ENERGY_TANK;
                if (behavior <= behavior_to_tank(CLIP_BEHAVIOR_HIDDEN_POWER_BOMB_TANK))
                {
                    gBGPointersAndDimensions.pClipDecomp[position] = 0x43C;
                    gBGPointersAndDimensions.backgrounds[1].pDecomp[position] = 0x0;
                }
                else
                {
                    gBGPointersAndDimensions.pClipDecomp[position] = 0x0;
                    gBGPointersAndDimensions.backgrounds[1].pDecomp[position] = 0x0;
                }
            }

            i++;
        }
    }
}

void BGClipCallMotherBrainUpdateGlass(u8 stage)
{

}