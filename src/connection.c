#include "gba.h"
#include "connection.h"

#include "data/engine_pointers.h"
#include "data/empty_datatypes.h"
#include "data/hatch_data.h"

#include "constants/audio.h"
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

// FIXME, find a better solution
void BgClipSetClipdataBlockValue(u16, u16, u16); // From bg_clip.h
// bg_clip.h must not be included, as declaring the correct signature for some
// of its functions produces non-matching code here.

/**
 * @brief 5e760 | 198 | Updates the hatches
 * 
 */
void ConnectionUpdateHatches(void)
{
    s32 i;

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
                {
                    SoundPlay(SOUND_DOOR_OPENING);
                }
                else
                {
                    switch (gHatchData[i].type)
                    {
                        case HATCH_LOCKED:
                        case HATCH_LOCKED_AND_LOCK_DESTINATION:
                            SoundPlay(SOUND_DOORS_LOCKING);
                            break;
                        
                        case HATCH_NONE:
                        case HATCH_SUPER_MISSILE:
                        case HATCH_POWER_BOMB:
                        default:
                            SoundPlay(SOUND_DOOR_CLOSING);
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

/**
 * @brief 5e8f8 | 15c | Updates the closing/opening animation of a hatch
 *
 * @param dontSetRaw Flag for "do not set raw"
 * @param hatchNbr Hatch number
 */
void ConnectionUpdateHatchAnimation(u8 dontSetRaw, u32 hatchNbr)
{
    s32 caf;
    u32 tilemapValue;

    tilemapValue = gHatchData[hatchNbr].facingRight ? 0x416 : 0x411;

    caf = gHatchData[hatchNbr].currentAnimationFrame - 1;

    if (gHatchData[hatchNbr].opening == 3)
    {
        caf = 2 - caf;
        if (caf < 0)
        {
            caf = 0;
            tilemapValue = gHatchData[hatchNbr].facingRight + sHatchesTilemapValues[gHatchData[hatchNbr].type];
        }
        else
        {
            if (gHatchData[hatchNbr].type != 0)
                caf += 0x40;
        }
    }
    
    if (gHatchData[hatchNbr].type == 0)
        caf += 0x80;

    tilemapValue += caf;
    if (dontSetRaw)
    {
        BgClipSetBg1BlockValue(tilemapValue, gHatchData[hatchNbr].yPosition, gHatchData[hatchNbr].xPosition);
        BgClipSetBg1BlockValue(tilemapValue + 0x10, gHatchData[hatchNbr].yPosition + 1, gHatchData[hatchNbr].xPosition);
        BgClipSetBg1BlockValue(tilemapValue + 0x20, gHatchData[hatchNbr].yPosition + 2, gHatchData[hatchNbr].xPosition);
        BgClipSetBg1BlockValue(tilemapValue + 0x30, gHatchData[hatchNbr].yPosition + 3, gHatchData[hatchNbr].xPosition);
    }
    else
    {
        BgClipSetRawBG1BlockValue(tilemapValue, gHatchData[hatchNbr].yPosition, gHatchData[hatchNbr].xPosition);
        BgClipSetRawBG1BlockValue(tilemapValue + 0x10, gHatchData[hatchNbr].yPosition + 1, gHatchData[hatchNbr].xPosition);
        BgClipSetRawBG1BlockValue(tilemapValue + 0x20, gHatchData[hatchNbr].yPosition + 2, gHatchData[hatchNbr].xPosition);
        BgClipSetRawBG1BlockValue(tilemapValue + 0x30, gHatchData[hatchNbr].yPosition + 3, gHatchData[hatchNbr].xPosition);
    }

    BgClipSetClipdataBlockValue(tilemapValue, gHatchData[hatchNbr].yPosition, gHatchData[hatchNbr].xPosition);
    BgClipSetClipdataBlockValue(tilemapValue + 0x10, gHatchData[hatchNbr].yPosition + 1, gHatchData[hatchNbr].xPosition);
    BgClipSetClipdataBlockValue(tilemapValue + 0x20, gHatchData[hatchNbr].yPosition + 2, gHatchData[hatchNbr].xPosition);
    BgClipSetClipdataBlockValue(tilemapValue + 0x30, gHatchData[hatchNbr].yPosition + 3, gHatchData[hatchNbr].xPosition);
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
    if (gHatchData[hatch].hitTimer == 0)
        gHatchData[hatch].hitTimer = 4;
    else
    {
        gHatchData[hatch].hitTimer--;
        return;
    }
    
    if (gHatchData[hatch].flashingTimer & 1)
        value = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_NO_HATCH_DOOR_TOP_LEFT; // Flashing door cap
    else
        value = sHatchesTilemapValues[gHatchData[hatch].type];

    if (gHatchData[hatch].facingRight)
        value++;

    // Update Gfx
    BgClipSetBg1BlockValue(value, gHatchData[hatch].yPosition, gHatchData[hatch].xPosition);
    BgClipSetBg1BlockValue(value + 0x10, gHatchData[hatch].yPosition + 1, gHatchData[hatch].xPosition);
    BgClipSetBg1BlockValue(value + 0x20, gHatchData[hatch].yPosition + 2, gHatchData[hatch].xPosition);
    BgClipSetBg1BlockValue(value + 0x30, gHatchData[hatch].yPosition + 3, gHatchData[hatch].xPosition);

    // Update timer
    if (gHatchData[hatch].flashingTimer >= 4)
        gHatchData[hatch].flashingTimer = 0;
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

    BgClipSetBg1BlockValue(value, gHatchData[hatch].yPosition, gHatchData[hatch].xPosition);
    BgClipSetBg1BlockValue(value + 0x10, gHatchData[hatch].yPosition + 0x1, gHatchData[hatch].xPosition);
    BgClipSetBg1BlockValue(value + 0x20, gHatchData[hatch].yPosition + 0x2, gHatchData[hatch].xPosition);
    BgClipSetBg1BlockValue(value + 0x30, gHatchData[hatch].yPosition + 0x3, gHatchData[hatch].xPosition);

    BgClipSetClipdataBlockValue(value, gHatchData[hatch].yPosition, gHatchData[hatch].xPosition);
    BgClipSetClipdataBlockValue(value + 0x10, gHatchData[hatch].yPosition + 0x1, gHatchData[hatch].xPosition);
    BgClipSetClipdataBlockValue(value + 0x20, gHatchData[hatch].yPosition + 0x2, gHatchData[hatch].xPosition);
    BgClipSetClipdataBlockValue(value + 0x30, gHatchData[hatch].yPosition + 0x3, gHatchData[hatch].xPosition);

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
u32 ConnectionCheckEnterDoor(u16 yPosition, u16 xPosition)
{
    const struct Door* pDoor;
    struct HatchData* pHatch;
    s32 i;
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

            if ((pDoor->type & DOOR_TYPE_NO_FLAGS) > DOOR_TYPE_AREA_CONNECTION && pDoor->xStart <= xPosition &&
                xPosition <= pDoor->xEnd && pDoor->yStart <= yPosition && yPosition <= pDoor->yEnd)
            {
                gDoorPositionStart.x = 0;
                gDoorPositionStart.y = 0;

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
                    if (pDoor->xStart > (gBg1XPosition >> 0x6) + 8)
                        gDoorPositionStart.x = 1;
                    gDoorPositionStart.y = pDoor->yStart;
                }

                gSamusDoorPositionOffset = (pDoor->yEnd + 1) * BLOCK_SIZE - gSamusData.yPosition - 1;
                ConnectionProcessDoorType(pDoor->type);
                gGameModeSub1 = SUB_GAME_MODE_LOADING_ROOM;

                if (gHatchData[i].exists && gHatchData[i].opening == TRUE)
                    gHatchData[i].currentAnimationFrame = 7;

                pDoor = sAreaDoorsPointers[gCurrentArea] + gLastDoorUsed;
                ConnectionCheckPlayCutsceneDuringTransition(gCurrentArea, pDoor->sourceRoom + 1);
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
u32 ConnectionCheckAreaConnection(u16 yPosition, u16 xPosition)
{
    const struct Door* pDoor;
    struct HatchData* pHatch;
    s32 i;
    s32 j;
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

    transition = COLOR_FADING_NO_TRANSITION;

    switch (type & DOOR_TYPE_NO_FLAGS)
    {
        case DOOR_TYPE_REMOVE_MOTHER_SHIP:
            gUseMotherShipDoors = FALSE;
            break;

        case DOOR_TYPE_SET_MOTHER_SHIP:
            gUseMotherShipDoors = TRUE;
            break;

        default:
            gWhichBGPositionIsWrittenToBG3OFS = 4;
            if (!gSkipDoorTransition)
                transition = COLOR_FADING_DOOR_TRANSITION;

        case DOOR_TYPE_NO_HATCH:
        case DOOR_TYPE_AREA_CONNECTION:
            break;
    }

    ColorFadingStart(transition);
}

/**
 * @brief 5efa8 | 5c | Finds an event based door (if it exists) for the provided door
 * 
 * @param sourceDoor Source door
 * @return u8 Destination door, 0xFF otherwise
 */
u8 ConnectionFindEventBasedDoor(u8 sourceDoor)
{
    s32 i;
    
    for (i = MAX_AMOUNT_OF_EVENT_BASED_CONNECTIONS - 1; i >= 0; i--)
    {
        if (gCurrentArea != sEventBasedConnections[i][0])
            continue;
        
        if (sourceDoor != sEventBasedConnections[i][1])
            continue;

        if (EventFunction(EVENT_ACTION_CHECKING, sEventBasedConnections[i][2]))
            return sEventBasedConnections[i][3];
    }

    return UCHAR_MAX;
}

/**
 * @brief 5f004 | a0 | Sets or checks if a hatch was opened
 * 
 * @param action Action
 * @param hatch Hatch number
 * @return u32 bool, closed
 */
u32 ConnectionSetHatchAsOpened(u8 action, u8 hatch)
{
    u32* pHatch;
    u32 closed;
    u32 doorBit;
    u32 chunk;
    struct Door currDoor;

    // 0x2037c00 = gHatchesOpened
    pHatch = (u32*)(0x2037c00 + gCurrentArea * 32);
    closed = FALSE;

    // Get chunk and bit
    chunk = hatch / 32;
    doorBit = hatch % 32;

    // Apply action
    if (action != HATCH_ACTION_CHECKING_OPENED)
    {
        // Mark as opened
        pHatch[chunk] &= ~(1 << doorBit);

        // Check set destination
        if (action == HATCH_ACTION_SETTING_SOURCE_AND_DESTINATION)
        {
            // Get door info
            currDoor = sAreaDoorsPointers[gCurrentArea][hatch];

            // Get chunk and bit for the destination
            chunk = currDoor.destinationDoor / 32;
            doorBit = currDoor.destinationDoor % 32;

            // Mark as opened
            pHatch[chunk] &= ~(1 << doorBit);
        }
    }
    else
    {
        // Check bit
        closed = pHatch[chunk] & (1 << doorBit);
        // Not zero, so closed
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
            SoundPlay(SOUND_DOORS_UNLOCKING);
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
    gHatchData[hatch].currentAnimationFrame = 0;

    ConnectionUpdateHatchAnimation(dontSetRaw, hatch); 
}

/**
 * @brief 5f120 | 174 | Locks the hatches
 * 
 * @param isEvent bool, is event lock
 */
void ConnectionLockHatches(u8 isEvent)
{
    s32 i;
    u16 lockedHatches;
    s32 hatch;
    
    i = 0;
    lockedHatches = 0;
    
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
            if ((lockedHatches >> i) & 1)
            {
                gHatchData[i].locked = TRUE;
                gHatchData[i].type = HATCH_LOCKED;

                if (gHatchData[i].sourceDoor != gLastDoorUsed)
                    ConnectionHatchStartLockAnimation(TRUE, hatch, FALSE);
                else
                    ConnectionHatchStartLockAnimation(TRUE, hatch, 3);
            }
            hatch++;
        }
    }
    else
    {
        lockedHatches = gHatchesState.hatchesLockedWithEvent | gHatchesState.unk2;
        
        for (i = 0, hatch = 0; i < MAX_AMOUNT_OF_HATCHES; hatch++, i++)
        {
            if ((lockedHatches >> i) & 1)
            {
                if ((gHatchesState.unk2 >> i) & 1)
                {
                    gHatchData[hatch].locked = TRUE;
                    gHatchData[hatch].type = HATCH_LOCKED;
                }
                else
                {
                    gHatchData[hatch].locked = 2;
                    gHatchData[hatch].type = HATCH_LOCKED_AND_LOCK_DESTINATION;
                }

                if (gHatchData[hatch].sourceDoor != gLastDoorUsed)
                    ConnectionHatchStartLockAnimation(TRUE, hatch, FALSE);
                else
                    ConnectionHatchStartLockAnimation(TRUE, hatch, 3);
            }
        }
    }
}

/**
 * @brief 5f294 | 320 | Loads the doors for the current room
 * 
 */
void ConnectionLoadDoors(void)
{
    s32 i;
    s32 hatchCount;
    u32 currHatchId;
    const struct Door* pDoor;
    struct HatchData* pHatch;
    s32 currDoor;
    u32 doorType;
    u16 bldalpha;
    s32 yPosition;
    u8 facingRight;
    u16 clipdata;
    u32 position;
    u32 behavior;
    u16 behaviorCheck;
    s32 hatchType;
    s32 collision;
    
    // Check has no pause screen, this prevents the re-loading of doors if the current room is reloaded (pause menu, cutscene...)
    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
        return;

    // Clear hatches
    for (i = 0; i < MAX_AMOUNT_OF_HATCHES; i++)
        gHatchData[i] = sHatchData_Empty;

    // Current hatch that samus is using
    currHatchId = UCHAR_MAX;

    // Resest hatches count
    gNumberOfValidHatchesInRoom = 0;

    // Get current doors
    pDoor = sAreaDoorsPointers[gCurrentArea];

    for (hatchCount = 0, currDoor = 0; pDoor->type != DOOR_TYPE_NONE; pDoor++, currDoor++)
    {
        if (gCurrentRoom != pDoor->sourceRoom)
            continue;

        // Get door type
        doorType = (pDoor->type & DOOR_TYPE_NO_FLAGS);

        // Doors with hatches are handled differently than doors without
        if (doorType == DOOR_TYPE_OPEN_HATCH || doorType == DOOR_TYPE_CLOSED_HATCH)
        {
            // Get position of the door
            position = gBgPointersAndDimensions.clipdataWidth * pDoor->yStart + pDoor->xStart;

            // Get raw clipdata, offset position by one to the right
            clipdata = gBgPointersAndDimensions.pClipDecomp[position + 1];

            // Get collision type
            collision = gTilemapAndClipPointers.pClipCollisions[clipdata];
            facingRight = TRUE;
            if (collision != CLIPDATA_TYPE_DOOR)
            {
                // No door on the right, get on the left
                facingRight = FALSE;
                clipdata = gBgPointersAndDimensions.pClipDecomp[position - 1];
            }

            // Get clipdata behavior
            behavior = gTilemapAndClipPointers.pClipBehaviors[clipdata];

            // Check is valid behavior
            behaviorCheck = BEHAVIOR_TO_DOOR(behavior) - 1;
            if (behaviorCheck < BEHAVIOR_TO_DOOR(CLIP_BEHAVIOR_POWER_BOMB_DOOR))
                hatchType = BEHAVIOR_TO_DOOR(behavior);
            else
                hatchType = 0;

            // Get hatch type
            hatchType = sHatchTypeTable[hatchType];

            // Start iteration from the first un-initialized hatch
            i = gNumberOfValidHatchesInRoom;
            if (i < MAX_AMOUNT_OF_HATCHES)
            {
                // Actually the the first hatch doesn't exist
                for (; i < MAX_AMOUNT_OF_HATCHES; i++)
                {
                    if (!gHatchData[i].exists)
                        break;
                }
                
                // Check again, just in case
                if (i < MAX_AMOUNT_OF_HATCHES)
                {
                    // Set type
                    gHatchData[i].type = hatchType;
                    if (hatchType >= HATCH_NORMAL)
                    {
                        // Set data and position
                        gHatchData[i].facingRight = facingRight;
                        gHatchData[i].yPosition = pDoor->yStart;
                        gHatchData[i].xPosition = pDoor->xStart;
                        
                        // Offset position
                        if (facingRight)
                            gHatchData[i].xPosition++;
                        else
                            gHatchData[i].xPosition--;

                        // Set exists
                        gHatchData[i].exists = TRUE;
                        gHatchData[i].sourceDoor = currDoor;

                        // Increment number of hatches
                        gNumberOfValidHatchesInRoom = i + 1;

                        // Set hatch lock flag
                        if (hatchType == HATCH_LOCKED)
                            gHatchesState.hatchesLockedWithTimer |= (1 << i);
                        else if (hatchType == HATCH_LOCKED_AND_LOCK_DESTINATION)
                            gHatchesState.hatchesLockedWithEvent |= (1 << i);
                    }
                    else
                    {
                        // Set data
                        gHatchData[i].yPosition = pDoor->yStart;
                        gHatchData[i].xPosition = pDoor->xStart;
                        gHatchData[i].exists = TRUE;
                        gHatchData[i].sourceDoor = currDoor;

                        // Set position based on the x exit direction
                        if (pDoor->xExit > 0)
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

                    // Increase actual hatch count
                    hatchCount++;
                }
            }

            // Check set current hatch
            if (currHatchId == UCHAR_MAX && currDoor == gLastDoorUsed)
                currHatchId = i;
        }
        else
        {
            // Load a door without a hatch, iterate from the end
            for (i = MAX_AMOUNT_OF_HATCHES - 1; i > -1; i--)
            {
                if (gHatchData[i].sourceDoor == sHatchData_Empty.sourceDoor)
                {
                    // Register door
                    gHatchData[i].sourceDoor = currDoor;
                    break;
                }
            }
        }
        
        // Check for overflow
        if (hatchCount >= MAX_AMOUNT_OF_HATCHES)
            break;
    }

    // Try to override the hatches
    for (i = 0; i < MAX_AMOUNT_OF_HATCHES; i++)
    {
        if (!gHatchData[i].exists)
            continue;

        // Is a hatch, and has been opened
        if (gHatchData[i].type > HATCH_UNUSED && !ConnectionSetHatchAsOpened(HATCH_ACTION_CHECKING_OPENED, gHatchData[i].sourceDoor))
            ConnectionOverrideOpenedHatch(i, HATCH_NORMAL);
    }

    if (currHatchId != UCHAR_MAX && gGameModeSub3 != 0)
    {
        // Check start lock animation
        if (gHatchData[currHatchId].exists && gHatchData[currHatchId].type != HATCH_NONE)
            ConnectionHatchStartLockAnimation(FALSE, currHatchId, 3);

        // Get X position
        currDoor = gHatchData[currHatchId].xPosition;
        if (gHatchData[currHatchId].facingRight)
            currDoor++;
        else
            currDoor--;

        // Get Y position
        i = gHatchData[currHatchId].yPosition;

        // Get behavior
        bldalpha = gTilemapAndClipPointers.pClipBehaviors[gBgPointersAndDimensions.pClipDecomp[i *
            gBgPointersAndDimensions.clipdataWidth + currDoor]];

        // Check for transparency
        bldalpha = BgClipGetNewBldalphaValue(bldalpha, bldalpha);
        if (bldalpha != 0)
        {
            // Update bldalpha
            TransparencyUpdateBLDALPHA(LOW_BYTE(bldalpha), HIGH_BYTE(bldalpha), 1, 1);

            gIoRegistersBackup.BLDALPHA_NonGameplay_EVB = gBldalphaData1.evbCoef;
            gIoRegistersBackup.BLDALPHA_NonGameplay_EVA = gBldalphaData1.evaCoef;

            write16(REG_BLDALPHA, gIoRegistersBackup.BLDALPHA_NonGameplay_EVB << 8 | gIoRegistersBackup.BLDALPHA_NonGameplay_EVA);
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

/**
 * @brief 5f5d8 | 16c | Checks for a hatch lock event in the current room
 * 
 */
void ConnectionCheckHatchLockEvents(void)
{
    s32 i;
    u16 hatchesToLock;
    u32 eventCheck;
    s32 total;
    const struct HatchLockEvent* pLock;
    
    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
        return;

    // Reset locked doors
    gHatchesState.hatchesLockedWithEvent = 0;
    gHatchesState.unk2 = 0;

    // Bounds check
    if (gCurrentArea >= MAX_AMOUNT_OF_AREAS - 1)
        return;

    // Get lock info
    total = sNumberOfHatchLockEventsPerArea[gCurrentArea];
    pLock = sHatchLockEventsPointers[gCurrentArea];
    
    for (i = 0; i < total; i++, pLock++)
    {
        hatchesToLock = 0;
        if (pLock->room == gCurrentRoom)
        {
            // Check event
            eventCheck = EventFunction(EVENT_ACTION_CHECKING, pLock->event);
            if (pLock->isBefore == TRUE)
            {
                // Invert event if before
                eventCheck ^= pLock->isBefore;
            }
            else
            {
                if (pLock->isBefore == 3)
                    eventCheck ^= TRUE;
            }

            if (eventCheck)
            {
                // Seriously
                hatchesToLock |= pLock->hatchesToLock_0;
                hatchesToLock |= pLock->hatchesToLock_1 << 1;
                hatchesToLock |= pLock->hatchesToLock_2 << 2;
                hatchesToLock |= pLock->hatchesToLock_3 << 3;
                hatchesToLock |= pLock->hatchesToLock_4 << 4;
                hatchesToLock |= pLock->hatchesToLock_5 << 5;
                hatchesToLock |= pLock->hatchesToLock_6 << 6;
                hatchesToLock |= pLock->hatchesToLock_7 << 7;

                hatchesToLock |= pLock->hatchesToLock_8 << 8;
                hatchesToLock |= pLock->hatchesToLock_9 << 9;
                hatchesToLock |= pLock->hatchesToLock_10 << 10;
                hatchesToLock |= pLock->hatchesToLock_11 << 11;
                hatchesToLock |= pLock->hatchesToLock_12 << 12;
                hatchesToLock |= pLock->hatchesToLock_13 << 13;
                hatchesToLock |= pLock->hatchesToLock_14 << 14;
                hatchesToLock |= pLock->hatchesToLock_15 << 15;
            }
        }

        // Apply lock
        if (pLock->isBefore == FALSE)
            gHatchesState.hatchesLockedWithEvent |= hatchesToLock;
        else if (pLock->isBefore == TRUE)
            gHatchesState.hatchesLockedWithEvent |= hatchesToLock;
        else if (pLock->isBefore == 2)
            gHatchesState.unk2 |= hatchesToLock;
        else if (pLock->isBefore == 3)
            gHatchesState.unk2 |= hatchesToLock;
    }

    // Check actually lock doors
    if (gHatchesState.hatchesLockedWithEvent != 0 || gHatchesState.unk2 != 0)
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
                    SoundFade(SOUND_RAIN, CONVERT_SECONDS(1.f / 6));
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
                SoundFade(SOUND_ELEVATOR, CONVERT_SECONDS(1.f / 6));
                FadeMusic(CONVERT_SECONDS(1.f / 6));
            }
            break;

        case ELEVATOR_ROUTE_BRINSTAR_TO_KRAID:
            if (gLastElevatorUsed.direction == ELEVATOR_DIRECTION_UP && EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_KILLED) && !EventFunction(EVENT_ACTION_CHECKING, EVENT_EXIT_KRAID_DEMO_PLAYED))
            {
                gCurrentCutscene = CUTSCENE_RIDLEY_IN_SPACE;

                ColorFadingStart(COLOR_FADING_CANCEL);
                SoundFade(SOUND_ELEVATOR, CONVERT_SECONDS(1.f / 6));
                FadeMusic(CONVERT_SECONDS(1.f / 6));
            }
            break;

        case ELEVATOR_ROUTE_NORFAIR_TO_RIDLEY:
            if (gLastElevatorUsed.direction == ELEVATOR_DIRECTION_DOWN && !EventFunction(EVENT_ACTION_CHECKING, EVENT_ENTER_RIDLEY_DEMO_PLAYED))
            {
                gCurrentCutscene = CUTSCENE_RIDLEY_LANDING;

                ColorFadingStart(COLOR_FADING_CANCEL);
                SoundFade(SOUND_ELEVATOR, CONVERT_SECONDS(1.f / 6));
                FadeMusic(CONVERT_SECONDS(1.f / 6));
            }
            break;

        case ELEVATOR_ROUTE_BRINSTAR_TO_TOURIAN:
            if (gLastElevatorUsed.direction == ELEVATOR_DIRECTION_DOWN && !EventFunction(EVENT_ACTION_CHECKING, EVENT_ENTER_TOURIAN_DEMO_PLAYED))
            {
                gCurrentCutscene = CUTSCENE_ENTER_TOURIAN;

                ColorFadingStart(COLOR_FADING_CANCEL);
                SoundFade(SOUND_ELEVATOR, CONVERT_SECONDS(1.f / 6));
                FadeMusic(CONVERT_SECONDS(1.f / 6));
            }
            break;

        case ELEVATOR_ROUTE_NONE:
        case ELEVATOR_ROUTE_CRATERIA_TO_BRINSTAR:
            return;
    }
}
