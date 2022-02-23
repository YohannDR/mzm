#include "connection.h"
#include "globals.h"
#include "bg_clip.h"

void connection_opening_hatch_related(void)
{

}

void connection_update_hatch_animation(u8 dont_set_raw, u8 hatch)
{
    /*u32 value;
    u32 bg_block;
    u32 clip_block;
    i32 direction_flag;

    direction_flag = hatch_data[hatch].direction << 0x1B;
    bg_block = 0x411;
    if (direction_flag < 0x0)
        bg_block = 0x416;

    direction_flag = (hatch_data[hatch].direction << 0x1C >> 0x1D) - 0x1;
    if ((hatch_data[hatch].status & 0x3) == 0x3)
    {
        direction_flag = (0x2 - direction_flag);
        if (direction_flag < 0x0)
        {
            direction_flag = 0x0;
            bg_block = hatch_clipdata_block_values_3602c8[hatch_data[hatch].type] - (direction_flag >> 0x1F);
            clip_block = direction_flag;
            if (hatch_data[hatch].type == HATCH_NONE)
                clip_block = direction_flag + 0x80;
        }
        else if (hatch_data[hatch].type != HATCH_NONE)
        {
            direction_flag += 0x40;
            clip_block = direction_flag;
            if (hatch_data[hatch].type == HATCH_NONE)
                clip_block = direction_flag + 0x80;
        }
    }
    else
    {
        clip_block = direction_flag;
        if (hatch_data[hatch].type == HATCH_NONE)
            clip_block = direction_flag + 0x80;
    }

    value = bg_block + clip_block;
    if (dont_set_raw != FALSE)
    {
        bg_clip_set_bg1_block_value(value, hatch_data[hatch].y_position, hatch_data[hatch].x_position);
        bg_clip_set_bg1_block_value(value + 0x10, hatch_data[hatch].y_position + 0x1, hatch_data[hatch].x_position);
        bg_clip_set_bg1_block_value(value + 0x20, hatch_data[hatch].y_position + 0x2, hatch_data[hatch].x_position);
        bg_clip_set_bg1_block_value(value + 0x30, hatch_data[hatch].y_position + 0x3, hatch_data[hatch].x_position);
    }
    else
    {
        bg_clip_set_raw_bg1_block_value(value, hatch_data[hatch].y_position, hatch_data[hatch].x_position);
        bg_clip_set_raw_bg1_block_value(value + 0x10, hatch_data[hatch].y_position + 0x1, hatch_data[hatch].x_position);
        bg_clip_set_raw_bg1_block_value(value + 0x20, hatch_data[hatch].y_position + 0x2, hatch_data[hatch].x_position);
        bg_clip_set_raw_bg1_block_value(value + 0x30, hatch_data[hatch].y_position + 0x3, hatch_data[hatch].x_position);
    }
    
    bg_clip_set_clipdata_block_value((u16)value, hatch_data[hatch].y_position, hatch_data[hatch].x_position);
    bg_clip_set_clipdata_block_value((u16)value + 0x10, hatch_data[hatch].y_position + 0x1, hatch_data[hatch].x_position);
    bg_clip_set_clipdata_block_value((u16)value + 0x20, hatch_data[hatch].y_position + 0x2, hatch_data[hatch].x_position);
    bg_clip_set_clipdata_block_value((u16)value + 0x30, hatch_data[hatch].y_position + 0x3, hatch_data[hatch].x_position);*/
}

void unk_5EA54(u8 hatch)
{

}

void unk_5eb18(u8 hatch, enum hatch_type type)
{

}

u8 connection_check_enter_door(u16 y_position, u16 x_position)
{
    /*u8* pSrc;
    struct hatch_data* pData;
    enum area* pCurrArea;
    struct door* pCurr;
    struct door* pAreaDoors;
    u8* pLastDoor;
    u8 direction;
    u32 offset;
    u8 event_door;
    u8 last_door;
    u8 door_found;
    i32 count;

    if (game_mode_sub1 != 0x2)
        return FALSE;
    else
    {
        door_found = FALSE;
        count = 0x0;
        pData = hatch_data;
        pCurrArea = &current_area;
        pSrc = &pData[0x0].source_door;
        offset = 0x0;
        pLastDoor = &last_door_used;

        while (count < 0x10)
        {
            if (*pSrc != u8_array_345868[0x7])
            {
                pCurr = door_pointer_array_75faa8[*pCurrArea] + *pSrc;
                if (DOOR_AREA_CONNECTION < (pCurr->type & 0xF) && pCurr->x_start <= x_position && x_position <= pCurr->x_end && pCurr->y_start <= y_position && y_position <= pCurr->y_end)
                {
                    door_position_start.x = 0x0;
                    door_position_start.y = 0x0;

                    if ((pCurr->type & DOOR_LOAD_EVENT_BASED_ROOM) != 0x0)
                    {
                        event_door = connection_find_event_based_door(*pSrc);
                        if (event_door == 0xFF)
                            *pLastDoor = pCurr->destination_door;
                        else
                            *pLastDoor = event_door;
                    }
                    else
                        *pLastDoor = pCurr->destination_door;

                    if (DOOR_NO_HATCH < (pCurr->type & 0xF))
                    {
                        if (pCurr->x_start > (bg1_x_position >> 0x6) + 0x8)
                            door_position_start.x = 0x1;
                        door_position_start.y = pCurr->y_start;
                    }

                    samus_door_position_offset = ((pCurr->y_end + 0x1) * 0x40 - samus_data.y_position) - 0x1;
                    connection_process_door_type(pCurr->type);
                    game_mode_sub1 = 0x3;

                    direction = hatch_data[offset].direction;
                    if ((direction & 0x1) != 0x0 && (hatch_data[offset].status & 0x3) == 0x1)
                        hatch_data[offset].direction = direction | 0xE;

                    last_door = *pLastDoor;
                    pAreaDoors = door_pointer_array_75faa8[*pCurrArea];
                    connection_check_play_cutscene_during_transition(*pCurrArea, (u8)(pAreaDoors[last_door].source_room + 0x1));
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

u8 connection_check_area_connection(u16 y_position, u16 x_position)
{

}

void connection_process_door_type(enum door_type type)
{
    u8 transition;

    transition = 0x6;

    switch (type & 0xF)
    {
        case DOOR_REMOVE_MOTHER_SHIP:
            use_mother_ship_doors = FALSE;
            break;

        case DOOR_SET_MOTHER_SHIP:
            use_mother_ship_doors = TRUE;
            break;

        default:
            which_bg_position_is_written_to_bg30fs = 0x4;
            if (!skip_door_transition)
                transition = 0x4;

        case DOOR_NO_HATCH:
        case DOOR_AREA_CONNECTION:
            break;
    }

    background_fading_start(transition);
}

u8 connection_find_event_based_door(u8 source_room)
{

}

u8 connection_set_hatch_as_opened(enum hatch_action action, u8 hatch)
{

}

void connection_check_unlock_doors(void)
{

}

void connection_maybe_hatch_animation_related(u8 maybe_direction, u8 hatch, u8 maybe_status)
{

}

void connection_lock_hatches(u8 is_event)
{

}

void connection_load_doors(void)
{

}

void connection_lock_hatches_with_timer(void)
{

}

void connection_check_hatch_lock_events(void)
{

}

void connection_check_play_cutscene_during_transition(enum area area, u8 dst_door)
{

}

void connection_check_play_cutscene_during_elevator(void)
{

}