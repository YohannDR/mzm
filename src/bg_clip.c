#include "gba.h"
#include "bg_clip.h"
#include "transparency.h"
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

void BgClipMotherBrainUpdateGlass(u8 bg, u16 value, u16 yPosition, u16 xPosition)
{

}

void BgClipSetBG1BlockValue(u32 value, u16 yPosition, u16 xPosition)
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
void BgClipSetRawBG1BlockValue(u32 value, u16 yPosition, u16 xPosition)
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
void BgClipSetClipdataBlockValue(u16 value, u16 yPosition, u16 xPosition)
{
    gBGPointersAndDimensions.pClipDecomp[gBGPointersAndDimensions.clipdataWidth * yPosition + xPosition] = value;
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

void BgClipApplyClipdataChangingTransparency(void)
{
    // https://decomp.me/scratch/qCOUj

    u16 clipdata;
    u32 xPosition;
    u32 yPosition;
    i32 position;

    position = gSamusData.xPosition;
    if (position > gBGPointersAndDimensions.clipdataWidth * BLOCK_SIZE)
        position = gBGPointersAndDimensions.clipdataWidth * BLOCK_SIZE;

    xPosition = position >> 6;

    position = gSamusData.yPosition + (gSamusPhysics.drawDistanceTopOffset >> 1);
    if (position < 0)
        position = 0;
    else
    {
        if (position > gBGPointersAndDimensions.clipdataHeight * BLOCK_SIZE)
            position = gBGPointersAndDimensions.clipdataHeight * BLOCK_SIZE;
    }

    yPosition = position >> 6;

    clipdata = gTilemapAndClipPointers.pClipBehaviors[gBGPointersAndDimensions.pClipDecomp[yPosition * gBGPointersAndDimensions.clipdataWidth + xPosition]];
    if (clipdata == CLIP_BEHAVIOR_NONE)
        return;

    clipdata = BgClipGetNewBldalphaValue(clipdata);
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
 * @return u16 Bldalpha value (eva on first 8 bits, then evb on next 8 bits)
 */
u16 BgClipGetNewBldalphaValue(u16 clip)
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

void BgClipCheckWalkingOnCrumbleBlock(void)
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
                    BgClipSetBG1BlockValue(0x401, yPosition, xPosition);
                    BgClipSetClipdataBlockValue(CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID, yPosition, xPosition);
                }
            }
        }
    }*/
}

void BgClipCheckTouchingTransitionOnElevator(void)
{

}

void BgClipCheckTouchingTransitionOrTank(void)
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
                if (collectionData.behaviors[i] != CLIP_BEHAVIOR_NONE &&
                    BEHAVIOR_TO_TANK(collectionData.behaviors[i]) <
                    BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_UNDERWATER_POWER_BOMB_TANK))
                {
                    tankType = sTankBehaviors[BEHAVIOR_TO_TANK(collectionData.behaviors[i])].itemType;

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

                            messageID = sTankBehaviors[BEHAVIOR_TO_TANK(collectionData.behaviors[i])].messageID + collectingFirstTank;
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
            clipdata = 0x43C;
        else
            clipdata = 0x0;

        BgClipSetBG1BlockValue(0x0, gLastTankCollected.yPosition, gLastTankCollected.xPosition);
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
    i32 i;
    u8* pItem;
    i32 limit;

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
    i32 i;
    i32 limit;
    i32 position;
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
            position = gBGPointersAndDimensions.clipdataWidth * pItem->yPosition + pItem->xPosition;

            behavior = gTilemapAndClipPointers.pClipBehaviors[gBGPointersAndDimensions.pClipDecomp[position]] -
                CLIP_BEHAVIOR_UNDERWATER_ENERGY_TANK;
            if (behavior <= BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_HIDDEN_POWER_BOMB_TANK))
            {
                gBGPointersAndDimensions.pClipDecomp[position] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_WATER;
                gBGPointersAndDimensions.backgrounds[1].pDecomp[position] = 0;
            }
            else
            {
                gBGPointersAndDimensions.pClipDecomp[position] = 0;
                gBGPointersAndDimensions.backgrounds[1].pDecomp[position] = 0;
            }
        }
    }
}

/**
 * @brief 5b1d8 | 74 | Calls the BgClipMotherBrainUpdateGlass on every block of the glass
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
            BgClipMotherBrainUpdateGlass(0, sMotherBrainGlassBreakingBaseTilemapValues[stage] + i * 16 + j, i + 13, j + 4);
        }
    }
}
