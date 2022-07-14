#include "connection.h"
#include "globals.h"
#include "bg_clip.h"

void ConnectionUpdateOpeningClosingHatches(void)
{

}

void ConnectionUpdateHatchAnimation(u8 dont_set_raw, u8 hatch)
{
    /*u32 value;
    u32 bg_block;
    u32 clip_block;
    i32 direction_flag;

    direction_flag = gHatchData[hatch].direction << 0x1B;
    bg_block = 0x411;
    if (direction_flag < 0x0)
        bg_block = 0x416;

    direction_flag = (gHatchData[hatch].direction << 0x1C >> 0x1D) - 0x1;
    if ((gHatchData[hatch].status & 0x3) == 0x3)
    {
        direction_flag = (0x2 - direction_flag);
        if (direction_flag < 0x0)
        {
            direction_flag = 0x0;
            bg_block = hatch_clipdata_block_values_3602c8[gHatchData[hatch].type] - (direction_flag >> 0x1F);
            clip_block = direction_flag;
            if (gHatchData[hatch].type == HATCH_NONE)
                clip_block = direction_flag + 0x80;
        }
        else if (gHatchData[hatch].type != HATCH_NONE)
        {
            direction_flag += 0x40;
            clip_block = direction_flag;
            if (gHatchData[hatch].type == HATCH_NONE)
                clip_block = direction_flag + 0x80;
        }
    }
    else
    {
        clip_block = direction_flag;
        if (gHatchData[hatch].type == HATCH_NONE)
            clip_block = direction_flag + 0x80;
    }

    value = bg_block + clip_block;
    if (dont_set_raw != FALSE)
    {
        BGClipSetBG1BlockValue(value, gHatchData[hatch].y_position, gHatchData[hatch].x_position);
        BGClipSetBG1BlockValue(value + 0x10, gHatchData[hatch].y_position + 0x1, gHatchData[hatch].x_position);
        BGClipSetBG1BlockValue(value + 0x20, gHatchData[hatch].y_position + 0x2, gHatchData[hatch].x_position);
        BGClipSetBG1BlockValue(value + 0x30, gHatchData[hatch].y_position + 0x3, gHatchData[hatch].x_position);
    }
    else
    {
        BGClipSetRawBG1BlockValue(value, gHatchData[hatch].y_position, gHatchData[hatch].x_position);
        BGClipSetRawBG1BlockValue(value + 0x10, gHatchData[hatch].y_position + 0x1, gHatchData[hatch].x_position);
        BGClipSetRawBG1BlockValue(value + 0x20, gHatchData[hatch].y_position + 0x2, gHatchData[hatch].x_position);
        BGClipSetRawBG1BlockValue(value + 0x30, gHatchData[hatch].y_position + 0x3, gHatchData[hatch].x_position);
    }
    
    BGClipSetClipdataBlockValue((u16)value, gHatchData[hatch].y_position, gHatchData[hatch].x_position);
    BGClipSetClipdataBlockValue((u16)value + 0x10, gHatchData[hatch].y_position + 0x1, gHatchData[hatch].x_position);
    BGClipSetClipdataBlockValue((u16)value + 0x20, gHatchData[hatch].y_position + 0x2, gHatchData[hatch].x_position);
    BGClipSetClipdataBlockValue((u16)value + 0x30, gHatchData[hatch].y_position + 0x3, gHatchData[hatch].x_position);*/
}

void ConnectionHatchFlashingAnimation(u8 hatch)
{

}

void ConnectionOverrideOpenedHatch(u8 hatch, u8 type)
{

}

u8 ConnectionCheckEnterDoor(u16 y_position, u16 x_position)
{
    /*u8* pSrc;
    struct gHatchData* pData;
    u8* pCurrArea;
    struct door* pCurr;
    struct door* pAreaDoors;
    u8* pLastDoor;
    u8 direction;
    u32 offset;
    u8 event_door;
    u8 last_door;
    u8 door_found;
    i32 count;

    if (gGameModeSub1 != 0x2)
        return FALSE;
    else
    {
        door_found = FALSE;
        count = 0x0;
        pData = gHatchData;
        pCurrArea = &gCurrentArea;
        pSrc = &pData[0x0].source_door;
        offset = 0x0;
        pLastDoor = &gLastDoorUsed;

        while (count < 0x10)
        {
            if (*pSrc != u8_array_345868[0x7])
            {
                pCurr = door_pointer_array_75faa8[*pCurrArea] + *pSrc;
                if (DOOR_AREA_CONNECTION < (pCurr->type & 0xF) && pCurr->x_start <= x_position && x_position <= pCurr->x_end && pCurr->y_start <= y_position && y_position <= pCurr->y_end)
                {
                    gDoorPositionStart.x = 0x0;
                    gDoorPositionStart.y = 0x0;

                    if ((pCurr->type & DOOR_LOAD_EVENT_BASED_ROOM) != 0x0)
                    {
                        event_door = ConnectionFindEventBasedDoor(*pSrc);
                        if (event_door == 0xFF)
                            *pLastDoor = pCurr->destination_door;
                        else
                            *pLastDoor = event_door;
                    }
                    else
                        *pLastDoor = pCurr->destination_door;

                    if (DOOR_NO_HATCH < (pCurr->type & 0xF))
                    {
                        if (pCurr->x_start > (gBG1XPosition >> 0x6) + 0x8)
                            gDoorPositionStart.x = 0x1;
                        gDoorPositionStart.y = pCurr->y_start;
                    }

                    gSamusDoorPositionOffset = ((pCurr->y_end + 0x1) * 0x40 - gSamusData.y_position) - 0x1;
                    ConnectionProcessDoorType(pCurr->type);
                    gGameModeSub1 = 0x3;

                    direction = gHatchData[offset].direction;
                    if ((direction & 0x1) != 0x0 && (gHatchData[offset].status & 0x3) == 0x1)
                        gHatchData[offset].direction = direction | 0xE;

                    last_door = *pLastDoor;
                    pAreaDoors = door_pointer_array_75faa8[*pCurrArea];
                    ConnectionCheckPlayCutsceneDuringTransition(*pCurrArea, (u8)(pAreaDoors[last_door].source_room + 0x1));
                    check_play_room_music_track(*pCurrArea, pAreaDoors[last_door].source_room);
                    door_found = TRUE;
                    break;
                }
            }

            pSrc += 0x8;
            offset += 0x8;
            count++;
        }

        return door_found;
    }*/
}

u8 ConnectionCheckAreaConnection(u16 y_position, u16 x_position)
{

}

void ConnectionProcessDoorType(u8 type)
{
    /*8 transition;

    transition = 0x6;

    switch (type & 0xF)
    {
        case DOOR_REMOVE_MOTHER_SHIP:
            gUseMotherShip = FALSE;
            break;

        case DOOR_SET_MOTHER_SHIP:
            gUseMotherShip = TRUE;
            break;

        default:
            gWhichBGPositionIsWrittenToBG3OFS = 0x4;
            if (!gSkipDoorTransition)
                transition = 0x4;

        case DOOR_NO_HATCH:
        case DOOR_AREA_CONNECTION:
            break;
    }

    background_fading_start(transition);*/
}

u8 ConnectionFindEventBasedDoor(u8 source_room)
{

}

u8 ConnectionSetHatchAsOpened(u8 action, u8 hatch)
{

}

void ConnectionCheckUnlockDoors(void)
{

}

void ConnectionStartLockAnimation(u8 maybe_direction, u8 hatch, u8 maybe_status)
{

}

void ConnectionLockHatches(u8 is_event)
{

}

void ConnectionLoadDoors(void)
{

}

void ConnectionLockHatchesWithTimer(void)
{

}

void ConnectionCheckHatchLockEvents(void)
{

}

void ConnectionCheckPlayCutsceneDuringTransition(u8 area, u8 dst_door)
{

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

                start_special_background_fading(0x2);
                SoundFade(0x10E, 0xA);
                fade_music(0xA);
            }
            break;

        case ELEVATOR_ROUTE_BRINSTAR_TO_KRAID:
            if (gLastElevatorUsed.direction == ELEVATOR_DIRECTION_UP && EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_KILLED) && !EventFunction(EVENT_ACTION_CHECKING, EVENT_EXIT_KRAID_DEMO_PLAYED))
            {
                gCurrentCutscene = CUTSCENE_RIDLEY_IN_SPACE;

                start_special_background_fading(0x2);
                SoundFade(0x10E, 0xA);
                fade_music(0xA);
            }
            break;

        case ELEVATOR_ROUTE_NORFAIR_TO_RIDLEY:
            if (gLastElevatorUsed.direction == ELEVATOR_DIRECTION_DOWN && !EventFunction(EVENT_ACTION_CHECKING, EVENT_ENTER_RIDLEY_DEMO_PLAYED))
            {
                gCurrentCutscene = CUTSCENE_RIDLEY_LANDING;

                start_special_background_fading(0x2);
                SoundFade(0x10E, 0xA);
                fade_music(0xA);
            }
            break;

        case ELEVATOR_ROUTE_BRINSTAR_TO_TOURIAN:
            if (gLastElevatorUsed.direction == ELEVATOR_DIRECTION_DOWN && !EventFunction(EVENT_ACTION_CHECKING, EVENT_ENTER_TOURIAN_DEMO_PLAYED))
            {
                gCurrentCutscene = CUTSCENE_ENTER_TOURIAN;

                start_special_background_fading(0x2);
                SoundFade(0x10E, 0xA);
                fade_music(0xA);
            }
            break;

        case ELEVATOR_ROUTE_NONE:
        case ELEVATOR_ROUTE_CRATERIA_TO_BRINSTAR:
            return;
    }
}