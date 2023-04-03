#include "gba.h"
#include "connection.h"
#include "bg_clip.h" // Required

#include "data/engine_pointers.h"
#include "data/empty_datatypes.h"
#include "data/hatch_data.h"

#include "constants/connection.h"
#include "constants/color_fading.h"
#include "constants/clipdata.h"
#include "constants/cutscene.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/room.h"

#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/connection.h"
#include "structs/cutscene.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/room.h"
#include "structs/samus.h"

/**
 * @brief 5e760 | 198 | Updates the hatches
 * 
 */
void ConnectionUpdateHatches(void)
{
    i32 i;

    for (i = 0; i < MAX_AMOUNT_OF_HATCHES; i++)
    {
        if (!gHatchData[i].exists)
            continue;
            
        if (gHatchData[i].opening != TRUE && gHatchData[i].opening != 0x3)
        {
            if (gHatchData[i].flashingTimer != 0x0 && gHatchData[i].type == HATCH_MISSILE)
                ConnectionHatchFlashingAnimation(i);
        }
        else
        {
            if (gHatchData[i].currentAnimationFrame == 0x0)
            {
                if (gHatchData[i].opening == TRUE)
                    SoundPlay(0x10C);
                else
                {
                    switch (gHatchData[i].type)
                    {
                        case HATCH_LOCKED:
                        case HATCH_LOCKED_AND_LOCK_DESTINATION:
                            SoundPlay(0x117);
                            break;
                        
                        case HATCH_NONE:
                        case HATCH_SUPER_MISSILE:
                        case HATCH_POWER_BOMB:
                        default:
                            SoundPlay(0x10D);
                            break;
                    }
                }
                
                gHatchData[i].animationDurationCounter = 0x0;
                gHatchData[i].currentAnimationFrame++;
            }
            else if (gHatchData[i].currentAnimationFrame == 0x7)
            {
                if (gHatchData[i].opening == TRUE)
                {
                    gHatchData[i].currentAnimationFrame = 0x4;
                    ConnectionUpdateHatchAnimation(TRUE, i);
                    gHatchData[i].opening = 0x2;
                    gHatchData[i].currentAnimationFrame = 0x0;
                }
            }
            else
            {
                if (gHatchData[i].animationDurationCounter < sHatchesAnimationDurationCounter[gHatchData[i].currentAnimationFrame])
                    gHatchData[i].animationDurationCounter++;
                else
                {
                    gHatchData[i].animationDurationCounter = 0x0;
                    ConnectionUpdateHatchAnimation(TRUE, i);
                    gHatchData[i].currentAnimationFrame++;

                    if (gHatchData[i].currentAnimationFrame == 0x5)
                    {
                        if (gHatchData[i].opening == TRUE)
                            gHatchData[i].opening = 0x2;
                        else if (gHatchData[i].opening == 0x3)
                            gHatchData[i].opening = 0x0;

                        gHatchData[i].currentAnimationFrame = 0x0;
                    }
                }
            }
        }
    }
}

void ConnectionUpdateHatchAnimation(u8 dontSetRaw, u32 hatchNbr)
{
    // https://decomp.me/scratch/q1BYt

    u32 value;
    i8 direction;
    i32 caf;
    u32 tilemapValue;

    value = gHatchData[hatchNbr].facingRight ? 0x416 : 0x411;

    caf = gHatchData[hatchNbr].currentAnimationFrame - 0x1;

    if (gHatchData[hatchNbr].opening == 0x3)
    {
        caf = 0x2 - caf;
        if (caf < 0x0)
        {
            caf = 0x0;
            value = gHatchData[hatchNbr].facingRight + sHatchesTilemapValues[gHatchData[hatchNbr].type];
        }
        else
        {
            if (gHatchData[hatchNbr].type != 0x0)
                caf += 0x40;
        }
    }
    
    if (gHatchData[hatchNbr].type == 0x0)
        caf += 0x80;

    tilemapValue = value + caf;
    if (dontSetRaw)
    {
        BGClipSetBG1BlockValue(tilemapValue, gHatchData[hatchNbr].yPosition, gHatchData[hatchNbr].xPosition);
        BGClipSetBG1BlockValue(tilemapValue + 0x10, gHatchData[hatchNbr].yPosition + 0x1, gHatchData[hatchNbr].xPosition);
        BGClipSetBG1BlockValue(tilemapValue + 0x20, gHatchData[hatchNbr].yPosition + 0x2, gHatchData[hatchNbr].xPosition);
        BGClipSetBG1BlockValue(tilemapValue + 0x30, gHatchData[hatchNbr].yPosition + 0x3, gHatchData[hatchNbr].xPosition);
    }
    else
    {
        BGClipSetRawBG1BlockValue(tilemapValue, gHatchData[hatchNbr].yPosition, gHatchData[hatchNbr].xPosition);
        BGClipSetRawBG1BlockValue(tilemapValue + 0x10, gHatchData[hatchNbr].yPosition + 0x1, gHatchData[hatchNbr].xPosition);
        BGClipSetRawBG1BlockValue(tilemapValue + 0x20, gHatchData[hatchNbr].yPosition + 0x2, gHatchData[hatchNbr].xPosition);
        BGClipSetRawBG1BlockValue(tilemapValue + 0x30, gHatchData[hatchNbr].yPosition + 0x3, gHatchData[hatchNbr].xPosition);
    }

    BGClipSetClipdataBlockValue(tilemapValue, gHatchData[hatchNbr].yPosition, gHatchData[hatchNbr].xPosition);
    BGClipSetClipdataBlockValue(tilemapValue + 0x10, gHatchData[hatchNbr].yPosition + 0x1, gHatchData[hatchNbr].xPosition);
    BGClipSetClipdataBlockValue(tilemapValue + 0x20, gHatchData[hatchNbr].yPosition + 0x2, gHatchData[hatchNbr].xPosition);
    BGClipSetClipdataBlockValue(tilemapValue + 0x30, gHatchData[hatchNbr].yPosition + 0x3, gHatchData[hatchNbr].xPosition);
}

/**
 * @brief 5ea54 | c4 | Updates the flashing animation of an hatch
 * 
 * @param hatch Hatch ID
 */
void ConnectionHatchFlashingAnimation(u8 hatch)
{
    u32 value;

    // Update hit timer
    if (gHatchData[hatch].hitTimer == 0x0)
        gHatchData[hatch].hitTimer = 0x4;
    else
    {
        gHatchData[hatch].hitTimer--;
        return;
    }
    
    if (gHatchData[hatch].flashingTimer & 0x1)
        value = 0x49A; // Flashing door cap
    else
        value = sHatchesTilemapValues[gHatchData[hatch].type];

    if (gHatchData[hatch].facingRight)
        value++;

    // Update GFX
    BGClipSetBG1BlockValue(value, gHatchData[hatch].yPosition, gHatchData[hatch].xPosition);
    BGClipSetBG1BlockValue(value + 0x10, gHatchData[hatch].yPosition + 0x1, gHatchData[hatch].xPosition);
    BGClipSetBG1BlockValue(value + 0x20, gHatchData[hatch].yPosition + 0x2, gHatchData[hatch].xPosition);
    BGClipSetBG1BlockValue(value + 0x30, gHatchData[hatch].yPosition + 0x3, gHatchData[hatch].xPosition);

    // Update timer
    if (gHatchData[hatch].flashingTimer >= 0x4)
        gHatchData[hatch].flashingTimer = 0x0;
    else
        gHatchData[hatch].flashingTimer++;
}

/**
 * @brief 5eb18 | d8 | Overrides an opened hatch and changes its type
 * 
 * @param hatch Hatch ID
 * @param type Hatch type
 */
void ConnectionOverrideOpenedHatch(u8 hatch, u32 type)
{
    u16 value;
    struct HatchData* pHatch;

    pHatch = gHatchData;
    
    // Change type
    gHatchData[hatch].type = type;

    // Change hatch behavior
    value = sHatchesTilemapValues[gHatchData[hatch].type] + gHatchData[hatch].facingRight;

    BGClipSetBG1BlockValue(value, gHatchData[hatch].yPosition, gHatchData[hatch].xPosition);
    BGClipSetBG1BlockValue(value + 0x10, gHatchData[hatch].yPosition + 0x1, gHatchData[hatch].xPosition);
    BGClipSetBG1BlockValue(value + 0x20, gHatchData[hatch].yPosition + 0x2, gHatchData[hatch].xPosition);
    BGClipSetBG1BlockValue(value + 0x30, gHatchData[hatch].yPosition + 0x3, gHatchData[hatch].xPosition);

    BGClipSetClipdataBlockValue(value, gHatchData[hatch].yPosition, gHatchData[hatch].xPosition);
    BGClipSetClipdataBlockValue(value + 0x10, gHatchData[hatch].yPosition + 0x1, gHatchData[hatch].xPosition);
    BGClipSetClipdataBlockValue(value + 0x20, gHatchData[hatch].yPosition + 0x2, gHatchData[hatch].xPosition);
    BGClipSetClipdataBlockValue(value + 0x30, gHatchData[hatch].yPosition + 0x3, gHatchData[hatch].xPosition);

    gHatchData[hatch].opening = FALSE;
    gHatchData[hatch].currentAnimationFrame = 0x0;
    gHatchData[hatch].animationDurationCounter = 0x0;
}

/**
 * @brief 5ebf0 | 1a4 | Checks for a door
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @return u8 Could enter
 */
u8 ConnectionCheckEnterDoor(u16 yPosition, u16 xPosition)
{
    const struct Door* pDoor;
    struct HatchData* pHatch;
    i32 i;
    u8 state;

    if (gGameModeSub1 != SUB_GAME_MODE_PLAYING)
        return FALSE;

    state = 0x0;
    pHatch = gHatchData;

    for (i = 0; i < MAX_AMOUNT_OF_HATCHES; i++)
    {
        if (gHatchData[i].sourceDoor != sHatchData_Empty.sourceDoor)
        {
            pDoor = sAreaDoorsPointers[gCurrentArea] + gHatchData[i].sourceDoor;

            if ((pDoor->type & DOOR_TYPE_NO_FLAGS) > DOOR_TYPE_AREA_CONNECTION && pDoor->xStart <= xPosition &&
                xPosition <= pDoor->xEnd && pDoor->yStart <= yPosition && yPosition <= pDoor->yEnd)
            {
                gDoorPositionStart.x = 0x0;
                gDoorPositionStart.y = 0x0;

                if (pDoor->type & DOOR_TYPE_LOAD_EVENT_BASED_ROOM)
                {
                    state = ConnectionFindEventBasedDoor(gHatchData[i].sourceDoor);
                    if (state != 0xFF)
                        gLastDoorUsed = state;
                    else
                        gLastDoorUsed = pDoor->destinationDoor;
                }
                else
                    gLastDoorUsed = pDoor->destinationDoor;

                if ((pDoor->type & DOOR_TYPE_NO_FLAGS) > DOOR_TYPE_NO_HATCH)
                {
                    if (pDoor->xStart > (gBG1XPosition >> 0x6) + 0x8)
                        gDoorPositionStart.x = 0x1;
                    gDoorPositionStart.y = pDoor->yStart;
                }

                gSamusDoorPositionOffset = (pDoor->yEnd + 0x1) * BLOCK_SIZE - gSamusData.yPosition - 0x1;
                ConnectionProcessDoorType(pDoor->type);
                gGameModeSub1 = SUB_GAME_MODE_LOADING_ROOM;

                if (gHatchData[i].exists && gHatchData[i].opening == TRUE)
                    gHatchData[i].currentAnimationFrame = 0x7;

                pDoor = sAreaDoorsPointers[gCurrentArea] + gLastDoorUsed;
                ConnectionCheckPlayCutsceneDuringTransition(gCurrentArea, pDoor->sourceRoom + 0x1);
                CheckPlayRoomMusicTrack(gCurrentArea, pDoor->sourceRoom);

                state = TRUE;
                break;
            }
        }
    }

    return state;
}

/**
 * @brief 5ed94 | 1b0 | Checks for an area connection
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @return u8 Could enter
 */
u8 ConnectionCheckAreaConnection(u16 yPosition, u16 xPosition)
{
    const struct Door* pDoor;
    struct HatchData* pHatch;
    i32 i;
    i32 j;
    u8 state;

    if (gGameModeSub1 != SUB_GAME_MODE_PLAYING)
        return FALSE;

    state = FALSE;
    pHatch = gHatchData;

    for (i = 0; i < MAX_AMOUNT_OF_HATCHES; i++)
    {
        if (gHatchData[i].sourceDoor != sHatchData_Empty.sourceDoor)
        {
            pDoor = sAreaDoorsPointers[gCurrentArea] + gHatchData[i].sourceDoor;

            if ((pDoor->type & DOOR_TYPE_NO_FLAGS) == DOOR_TYPE_AREA_CONNECTION && pDoor->xStart <= xPosition &&
                xPosition <= pDoor->xEnd && pDoor->yStart <= yPosition && yPosition <= pDoor->yEnd)
            {
                if (pDoor->type & DOOR_TYPE_LOAD_EVENT_BASED_ROOM)
                {
                    state = ConnectionFindEventBasedDoor(gHatchData[i].sourceDoor);
                    if (state != 0xFF)
                        gLastDoorUsed = state;
                    else
                        gLastDoorUsed = pDoor->destinationDoor;
                }
                else
                    gLastDoorUsed = pDoor->destinationDoor;

                state = 0x1;
                break;
            }
        }
    }

    if (!state)
        return FALSE;

    j = 0;
    while (sAreaConnections[j][0] != AREA_NONE)
    {
        if (sAreaConnections[j][0] == gCurrentArea && sAreaConnections[j][1] == gHatchData[i].sourceDoor)
        {
            gCurrentArea = sAreaConnections[j][2];
            state = 0x2;
            break;
        }

        j++;
    }

    if (state != 0x2)
    {
        gLastDoorUsed = 0x0;
        return FALSE;
    }

    if (gSamusData.pose == SPOSE_USING_AN_ELEVATOR)
        gSamusDoorPositionOffset = 0x0;
    else
        gSamusDoorPositionOffset = (pDoor->yEnd + 0x1) * BLOCK_SIZE - gSamusData.yPosition - 0x1;

    ColorFadingStart(0x6); // No transition
    gGameModeSub1 = SUB_GAME_MODE_LOADING_ROOM;
    pDoor = sAreaDoorsPointers[gCurrentArea] + gLastDoorUsed;

    ConnectionCheckPlayCutsceneDuringElevator();
    CheckPlayRoomMusicTrack(gCurrentArea, pDoor->sourceRoom);
    return TRUE;
}

/**
 * @brief 5ef44 | 64 | Processes a door type
 * 
 * @param type Door type
 */
void ConnectionProcessDoorType(u8 type)
{
    u8 transition;

    transition = 0x6;

    switch (type & DOOR_TYPE_NO_FLAGS)
    {
        case DOOR_TYPE_REMOVE_MOTHER_SHIP:
            gUseMotherShipDoors = FALSE;
            break;

        case DOOR_TYPE_SET_MOTHER_SHIP:
            gUseMotherShipDoors = TRUE;
            break;

        default:
            gWhichBGPositionIsWrittenToBG3OFS = 0x4;
            if (!gSkipDoorTransition)
                transition = 0x4;

        case DOOR_TYPE_NO_HATCH:
        case DOOR_TYPE_AREA_CONNECTION:
            break;
    }

    background_fading_start(transition); // Undefined
}

/**
 * @brief 5efa8 | 5c | Finds an event based door (if it exists) for the provided door
 * 
 * @param sourceDoor Source door
 * @return u8 Destination door, 0xFF otherwise
 */
u8 ConnectionFindEventBasedDoor(u8 sourceDoor)
{
    i32 i;
    
    for (i = MAX_AMOUNT_OF_EVENT_BASED_CONNECTIONS - 1; i >= 0; i--)
    {
        if (gCurrentArea == sEventBasedConnections[i].sourceArea &&
            sourceDoor == sEventBasedConnections[i].sourceDoor &&
            EventFunction(EVENT_ACTION_CHECKING, sEventBasedConnections[i].event))
            return sEventBasedConnections[i].destinationDoor;
    }

    return 0xFF;
}

u32 ConnectionSetHatchAsOpened(u8 action, u8 hatch)
{
    // https://decomp.me/scratch/3q3rr

    u32* pHatch;
    u32 closed;
    u32 doorBit;
    u32 chunk;
    u32 mask;
    struct Door currDoor;

    pHatch = gHatchesOpened[gCurrentArea];
    closed = FALSE;
    chunk = hatch / 32;
    doorBit = hatch & 31;

    if (action != HATCH_ACTION_CHECKING_OPENED)
    {
        pHatch[chunk] &= ~(1 << doorBit);
        if (action == HATCH_ACTION_SETTING_SOURCE_AND_DESTINATION)
        {
            currDoor = sAreaDoorsPointers[gCurrentArea][hatch];
            chunk = currDoor.destinationDoor / 32;
            doorBit = currDoor.destinationDoor & 31;
            pHatch[chunk] &= ~(1 << doorBit);
        }
    }
    else
    {
        closed = pHatch[chunk] & (1 << doorBit);
        if (closed)
            closed = TRUE;
    }

    return closed;
}

/**
 * @brief 5f0a4 | 40 | Checks if the doors should unlock
 * 
 */
void ConnectionCheckUnlockDoors(void)
{
    if (gDoorUnlockTimer < 0x0)
    {
        // Update timer
        gDoorUnlockTimer++;
        if (gDoorUnlockTimer == 0x0 && (gHatchesState.hatchesLockedWithTimer || gHatchesState.unk2))
        {
            // Timer done and has hatches to unlock
            SoundPlay(0x116);
            gHatchesState.unlocking = TRUE;
        }
    }
}

/**
 * @brief 5f0e4 | 3c | Starts a hatch locking animation
 * 
 * @param dontSetRaw Don't set raw flag
 * @param hatch Hatch ID
 * @param status Opening status
 */
void ConnectionHatchStartLockAnimation(u8 dontSetRaw, u8 hatch, u8 status)
{
    gHatchData[hatch].opening = status;
    gHatchData[hatch].currentAnimationFrame = 0x0;

    ConnectionUpdateHatchAnimation(dontSetRaw, hatch); 
}

/**
 * @brief 5f120 | 174 | Locks the hatches
 * 
 * @param isEvent bool, is event lock
 */
void ConnectionLockHatches(u8 isEvent)
{
    i32 i;
    u16 lockedHatches;
    i32 hatch;
    
    i = 0x0;
    lockedHatches = 0x0;
    
    for (; i < MAX_AMOUNT_OF_HATCHES; i++)
    {
        if (gHatchData[i].exists)
            lockedHatches |= (1 << i);
    }

    if (!isEvent)
        gHatchesState.hatchesLockedWithTimer &= lockedHatches;
    else
    {
        gHatchesState.hatchesLockedWithEvent &= lockedHatches;
        gHatchesState.unk2 &= lockedHatches;
    }

    if (!isEvent)
    {
        lockedHatches = gHatchesState.hatchesLockedWithTimer &= ~(gHatchesState.hatchesLockedWithEvent | gHatchesState.unk2);

        i = 0;
        hatch = 0;
        for (; i < MAX_AMOUNT_OF_HATCHES; i++)
        {
            if ((lockedHatches >> i) & 0x1)
            {
                gHatchData[i].locked = TRUE;
                gHatchData[i].type = HATCH_LOCKED;

                if (gHatchData[i].sourceDoor != gLastDoorUsed)
                    ConnectionHatchStartLockAnimation(TRUE, hatch, FALSE);
                else
                    ConnectionHatchStartLockAnimation(TRUE, hatch, 0x3);
            }
            hatch++;
        }
    }
    else
    {
        lockedHatches = gHatchesState.hatchesLockedWithEvent | gHatchesState.unk2;
        
        i = 0;
        hatch = 0;
        for (; i < MAX_AMOUNT_OF_HATCHES; i++)
        {
            if ((lockedHatches >> i) & 0x1)
            {
                if ((gHatchesState.unk2 >> i) & 0x1)
                {
                    gHatchData[hatch].locked = TRUE;
                    gHatchData[hatch].type = HATCH_LOCKED;
                }
                else
                {
                    gHatchData[hatch].locked = 0x32;
                    gHatchData[hatch].type = HATCH_LOCKED_AND_LOCK_DESTINATION;
                }

                if (gHatchData[hatch].sourceDoor != gLastDoorUsed)
                    ConnectionHatchStartLockAnimation(TRUE, hatch, FALSE);
                else
                    ConnectionHatchStartLockAnimation(TRUE, hatch, 0x3);
            }
            hatch++;
        }
    }
}

void ConnectionLoadDoors(void)
{
    // https://decomp.me/scratch/wlekD

    i32 i;
    i32 hatchCount;
    u32 currHatchId;
    const struct Door* pDoor;
    struct HatchData* pHatch;
    i32 currDoor;
    u32 doorType;
    u16 bldalpha;
    i32 yPosition;
    u8 direction;
    u16 clipdata;
    u32 position;
    u32 behavior;
    u16 behaviorCheck;
    i32 hatchType;
    u32 temp;
    
    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
        return;

    i = MAX_AMOUNT_OF_HATCHES - 1;
    pHatch = gHatchData + MAX_AMOUNT_OF_HATCHES-1;
    do
    {
        gHatchData[i--] = sHatchData_Empty;
    } while (i >= 0);

    currHatchId = 0xFF;
    gNumberOfValidHatchesInRoom = 0x0;
    pDoor = sAreaDoorsPointers[gCurrentArea];

    hatchCount = 0x0;
    currDoor = 0x0;
    for (doorType = pDoor->type; doorType != DOOR_TYPE_NONE; doorType = pDoor->type)
    {
        if (gCurrentRoom == pDoor->sourceRoom)
        {
            doorType = (doorType & DOOR_TYPE_NO_FLAGS) - 0x3;
            if (doorType < 0x2)
            {
                position = gBGPointersAndDimensions.clipdataWidth * pDoor->yStart + pDoor->xStart;

                clipdata = gBGPointersAndDimensions.pClipDecomp[position + 1];
                
                direction = 0x1;
                if (gTilemapAndClipPointers.pClipCollisions[clipdata] != CLIPDATA_TYPE_DOOR)
                {
                    direction = 0x0;
                    clipdata = gBGPointersAndDimensions.pClipDecomp[position - 1];
                }

                temp = gTilemapAndClipPointers.pClipBehaviors[clipdata];
                behaviorCheck = BEHAVIOR_TO_DOOR(temp) - 0x1;
                hatchType = 0x0;
                if (behaviorCheck < BEHAVIOR_TO_DOOR(CLIP_BEHAVIOR_POWER_BOMB_DOOR))
                    hatchType = BEHAVIOR_TO_DOOR(temp);

                hatchType = sHatchTypeTable[hatchType];
                i = gNumberOfValidHatchesInRoom;
                if (i < MAX_AMOUNT_OF_HATCHES)
                {
                    for (; i < MAX_AMOUNT_OF_HATCHES; i++)
                    {
                        if (!gHatchData[i].exists)
                            break;
                    }
                    
                    if (i < MAX_AMOUNT_OF_HATCHES)
                    {
                        gHatchData[i].type = hatchType;
                        if (hatchType >= HATCH_NORMAL)
                        {
                            gHatchData[i].facingRight = direction;
                            gHatchData[i].yPosition = pDoor->yStart;
                            gHatchData[i].xPosition = pDoor->xStart;
                            
                            if (direction)
                                gHatchData[i].xPosition++;
                            else
                                gHatchData[i].xPosition--;

                            gHatchData[i].exists = TRUE;
                            gHatchData[i].sourceDoor = currDoor;
                            gNumberOfValidHatchesInRoom = i + 0x1;

                            if (hatchType == HATCH_LOCKED)
                                gHatchesState.hatchesLockedWithTimer |= (1 << i);
                            else if (hatchType == HATCH_LOCKED_AND_LOCK_DESTINATION)
                                gHatchesState.hatchesLockedWithEvent |= (1 << i);
                        }
                        else
                        {
                            gHatchData[i].yPosition = pDoor->yStart;
                            gHatchData[i].xPosition = pDoor->xStart;
                            gHatchData[i].exists = TRUE;
                            gHatchData[i].sourceDoor = currDoor;

                            if (pDoor->xExit > 0x0)
                            {
                                gHatchData[i].xPosition++;
                                gHatchData[i].facingRight = TRUE;
                            }
                            else
                            {
                                gHatchData[i].xPosition--;
                                gHatchData[i].facingRight = FALSE;
                            }
                        }

                        hatchCount++;
                    }
                }

                if (currHatchId == 0xFF && currDoor == gLastDoorUsed)
                    currHatchId = i;
            }
            else
            {
                for (i = MAX_AMOUNT_OF_HATCHES - 1; i > -1; i--)
                {
                    if (gHatchData[i].sourceDoor == sHatchData_Empty.sourceDoor)
                    {
                        gHatchData[i].sourceDoor = currDoor;
                        break;
                    }
                }
            }
            
            if (hatchCount >= MAX_AMOUNT_OF_HATCHES)
                break;
        }


        pDoor++;
        currDoor++;
    }

    for (i = 0; i < MAX_AMOUNT_OF_HATCHES; i++)
    {
        if (gHatchData[i].exists && gHatchData[i].type > HATCH_UNUSED && !ConnectionSetHatchAsOpened(HATCH_ACTION_CHECKING_OPENED, gHatchData[i].sourceDoor))
            ConnectionOverrideOpenedHatch(i, HATCH_NORMAL);
    }

    if (currHatchId != 0xFF && gGameModeSub3 != 0x0)
    {
        if (gHatchData[currHatchId].exists && gHatchData[currHatchId].type != HATCH_NONE)
            ConnectionHatchStartLockAnimation(FALSE, currHatchId, 3);

        currDoor = gHatchData[currHatchId].xPosition;
        if (gHatchData[currHatchId].facingRight)
            currDoor++;
        else
            currDoor--;

        i = gHatchData[currHatchId].yPosition;

        bldalpha = gTilemapAndClipPointers.pClipBehaviors[gBGPointersAndDimensions.pClipDecomp[i *
            gBGPointersAndDimensions.clipdataWidth + currDoor]];
        bldalpha = BGClipGetNewBLDALPHAValue(bldalpha);
        if (bldalpha)
        {
            TransparencyUpdateBLDALPHA(bldalpha & 0xFF, bldalpha, 1, 1);
            gIoRegistersBackup.BLDALPHA_NonGameplay_EVB = gBldalphaData1.evbCoef;
            gIoRegistersBackup.BLDALPHA_NonGameplay_EVA = gBldalphaData1.evaCoef;
            write16((REG_BASE + 0x52), gIoRegistersBackup.BLDALPHA_NonGameplay_EVB << 8 | gIoRegistersBackup.BLDALPHA_NonGameplay_EVA);;
        }
    }
}

/**
 * @brief 5f5b4 | 24 | Locks the hatches (using Door Unlock Timer)
 * 
 */
void ConnectionLockHatchesWithTimer(void)
{
    gHatchesState.hatchesLockedWithTimer = USHORT_MAX;
    ConnectionLockHatches(FALSE);
    gDoorUnlockTimer = 0x2;
}

void ConnectionCheckHatchLockEvents(void)
{
    // https://decomp.me/scratch/m98IS

    i32 i;
    u16 hatchesToLock;
    u32 eventCheck;
    u16 total;
    const struct HatchLockEvent* pLock;
    
    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
        return;

    gHatchesState.hatchesLockedWithEvent = 0x0;
    gHatchesState.unk2 = 0x0;

    if (gCurrentArea >= MAX_AMOUNT_OF_AREAS - 1)
        return;

    i = sNumberOfHatchLockEventsPerArea[gCurrentArea];
    pLock = sHatchLockEventsPointers[gCurrentArea];
    
    while (i != 0)
    {
        hatchesToLock = 0x0;
        if (pLock->room == gCurrentRoom)
        {
            eventCheck = EventFunction(EVENT_ACTION_CHECKING, pLock->event);
            if (pLock->isBefore == TRUE)
                eventCheck ^= pLock->isBefore;
            else
            {
                if (pLock->isBefore == 0x3)
                    eventCheck ^= TRUE;
            }

            if (eventCheck)
            {
                hatchesToLock |= pLock->hatchesToLock1;
                hatchesToLock |= pLock->hatchesToLock2 << 1;
                hatchesToLock |= pLock->hatchesToLock3 << 2;
                hatchesToLock |= pLock->hatchesToLock4 << 3;
                hatchesToLock |= pLock->hatchesToLock5 << 4;
                hatchesToLock |= pLock->hatchesToLock6 << 5;
                hatchesToLock |= pLock->hatchesToLock7 << 6;
                hatchesToLock |= pLock->hatchesToLock8 << 7;

                hatchesToLock |= pLock->hatchesToLockPart2_1 << 8;
                hatchesToLock |= pLock->hatchesToLockPart2_2 << 9;
                hatchesToLock |= pLock->hatchesToLockPart2_3 << 10;
                hatchesToLock |= pLock->hatchesToLockPart2_4 << 11;
                hatchesToLock |= pLock->hatchesToLockPart2_5 << 12;
                hatchesToLock |= pLock->hatchesToLockPart2_6 << 13;
                hatchesToLock |= pLock->hatchesToLockPart2_7 << 14;
                hatchesToLock |= pLock->hatchesToLockPart2_8 << 15;
            }
        }

        if (pLock->isBefore == FALSE)
            gHatchesState.hatchesLockedWithEvent |= hatchesToLock;
        else if (pLock->isBefore == TRUE)
            gHatchesState.hatchesLockedWithEvent |= hatchesToLock;
        else if (pLock->isBefore == 0x2)
            gHatchesState.unk2 |= hatchesToLock;
        else if (pLock->isBefore == 0x3)
            gHatchesState.unk2 |= hatchesToLock;

        i--;
        pLock++;
    }

    if (gHatchesState.hatchesLockedWithEvent != 0x0 || gHatchesState.unk2 != 0x0)
        ConnectionLockHatches(TRUE);
}

/**
 * @brief 5f744 | b8 | Checks if a cutscene should play during a door transition
 * 
 * @param area Current area
 * @param dstRoomPlusOne Destination room (+ 1)
 */
void ConnectionCheckPlayCutsceneDuringTransition(u8 area, u8 dstRoomPlusOne)
{
    switch (area)
    {
        case AREA_KRAID:
            // Room 0x1E is the Kraid fight room
            if (dstRoomPlusOne == 0x1F && !EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_KILLED))
            {
                FadeMusic(0xA);
                FadeAllSounds(0xA);
                gCurrentCutscene = CUTSCENE_KRAID_RISING;
            }
            break;

        case AREA_CHOZODIA:
            // Room 0x2A is the Charlie fight room
            if (dstRoomPlusOne == 0x2B)
            {
                if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_FULLY_POWERED_SUIT_OBTAINED))
                    gCurrentCutscene = CUTSCENE_BEFORE_CHARLIE;
            }
            // Room 0xA is the suitless entry of the mothership
            else if (dstRoomPlusOne == 0xB && !EventFunction(EVENT_ACTION_CHECKING, EVENT_ENTER_MOTHERSHIP_DEMO_PLAYED))
            {
                if (gRainSoundEffect & RAIN_SOUND_PLAYING)
                    SoundFade(0x121, 0xA); // Rain sound
                gCurrentCutscene = CUTSCENE_MECHA_RIDLEY_SEES_SAMUS;
            }
            break;

        // Dumb cases in order to generate jump table
        case AREA_BRINSTAR:
        case AREA_NORFAIR:
        case AREA_RIDLEY:
        case AREA_CRATERIA:
        case AREA_TOURIAN:
            break;
    }
}

/**
 * @brief 5f7fc | f8 | Checks if a cutscene should play during an door transition on an elevator
 * 
 */
void ConnectionCheckPlayCutsceneDuringElevator(void)
{
    switch (gLastElevatorUsed.route)
    {
        case ELEVATOR_ROUTE_BRINSTAR_TO_NORFAIR:
            if (gLastElevatorUsed.direction == ELEVATOR_DIRECTION_DOWN && !EventFunction(EVENT_ACTION_CHECKING, EVENT_ENTER_NORFAIR_DEMO_PLAYED))
            {
                gCurrentCutscene = CUTSCENE_MOTHER_BRAIN_CLOSE_UP;

                ColorFadingStart(COLOR_FADING_CANCEL);
                SoundFade(0x10E, 0xA);
                FadeMusic(0xA);
            }
            break;

        case ELEVATOR_ROUTE_BRINSTAR_TO_KRAID:
            if (gLastElevatorUsed.direction == ELEVATOR_DIRECTION_UP && EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_KILLED) && !EventFunction(EVENT_ACTION_CHECKING, EVENT_EXIT_KRAID_DEMO_PLAYED))
            {
                gCurrentCutscene = CUTSCENE_RIDLEY_IN_SPACE;

                ColorFadingStart(COLOR_FADING_CANCEL);
                SoundFade(0x10E, 0xA);
                FadeMusic(0xA);
            }
            break;

        case ELEVATOR_ROUTE_NORFAIR_TO_RIDLEY:
            if (gLastElevatorUsed.direction == ELEVATOR_DIRECTION_DOWN && !EventFunction(EVENT_ACTION_CHECKING, EVENT_ENTER_RIDLEY_DEMO_PLAYED))
            {
                gCurrentCutscene = CUTSCENE_RIDLEY_LANDING;

                ColorFadingStart(COLOR_FADING_CANCEL);
                SoundFade(0x10E, 0xA);
                FadeMusic(0xA);
            }
            break;

        case ELEVATOR_ROUTE_BRINSTAR_TO_TOURIAN:
            if (gLastElevatorUsed.direction == ELEVATOR_DIRECTION_DOWN && !EventFunction(EVENT_ACTION_CHECKING, EVENT_ENTER_TOURIAN_DEMO_PLAYED))
            {
                gCurrentCutscene = CUTSCENE_ENTER_TOURIAN;

                ColorFadingStart(COLOR_FADING_CANCEL);
                SoundFade(0x10E, 0xA);
                FadeMusic(0xA);
            }
            break;

        case ELEVATOR_ROUTE_NONE:
        case ELEVATOR_ROUTE_CRATERIA_TO_BRINSTAR:
            return;
    }
}