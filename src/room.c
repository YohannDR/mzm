#include "room.h"
#include "memory.h"
#include "screen_shake.h"
#include "globals.h"
#include "event.h"
#include "bg_clip.h"

void room_load(void)
{

}

void room_load_tileset(void)
{

}

void room_load_entry(void)
{
    /*struct room_entry_rom entry;
    u16 effect_y;

    copy_bytes(&entry, entry_pointers[current_area] + current_room, sizeof(struct room_entry_rom));

    current_room_entry.tileset = entry.tileset;
    current_room_entry.bg0_prop = entry.bg0_prop;
    current_room_entry.bg1_prop = entry.bg1_prop;
    current_room_entry.bg2_prop = entry.bg2_prop;
    current_room_entry.bg3_prop = entry.bg3_prop;
    current_room_entry.bg3_scrolling = entry.bg3_scrolling;
    current_room_entry.transparency = entry.transparency;
    current_room_entry.map_x = entry.map_x;
    current_room_entry.map_y = entry.map_y;
    current_room_entry.effect = entry.effect;
    current_room_entry.music_track = entry.music_track;

    if (entry.effect_y != 0xFF)
        effect_y = entry.effect_y << 0x6;
    else
        effect_y = 0xFFFF;

    current_room_entry.effect_y = effect_y;
    spriteset_entry_used = 0x0;
    current_room_entry.first_spriteset_event = entry.first_spriteset_event;
    current_room_entry.second_spriteset_event = entry.second_spriteset_event;
    if (entry.second_spriteset_event != EVENT_NONE && event_function(EVENT_ACTION_CHECKING, current_room_entry.second_spriteset_event) != 0x0)
    {
        current_room_entry.enemy_room_data = entry.second_sprite_data_ptr;
        spriteset = entry.second_spriteset;
        spriteset_entry_used = 0x2;
    }
    if (current_room_entry.first_spriteset_event != EVENT_NONE && spriteset_entry_used == 0x0)
    {
        if (spriteset_entry_used != 0x0) goto skip_check;
        if (event_function(EVENT_ACTION_CHECKING, current_room_entry.first_spriteset_event) != 0x0)
        {
            current_room_entry.enemy_room_data = entry.first_sprite_data_ptr;
            spriteset = entry.first_spriteset;
            spriteset_entry_used = 0x1;
        }
    }

    if (spriteset_entry_used == 0x0)
    {
        current_room_entry.enemy_room_data = entry.default_sprite_data_ptr;
        spriteset = entry.default_spriteset;
    }

    skip_check:

    current_room_entry.scrolls_flag = 0x2;
    current_room_entry.effect_clone = EFFECT_NONE;
    current_room_entry.bg0_size = 0x0;
    current_room_entry.bg3_size = 0x0;

    if (spriteset_entry_used != 0x0 && current_room_entry.bg0_prop == 0x44)
    {
        waiting_space_pirates_position.x = 0x8000;
        waiting_space_pirates_position.y = 0x8000;
    }

    current_room_entry.bg3_from_bottom_flag = 0x0;
    if (current_room_entry.bg3_prop == 0x46)
    {
        current_room_entry.bg3_from_bottom_flag = 0x1;
        bg0_movement.type = BG0_MOVEMENT_WATER_CLOUDS;
    }*/
}

void room_load_backgrounds(void)
{

}

void room_remove_never_reform_blocks_and_collected_tanks(void)
{
	// remove_never_reform_blocks();
	bg_clip_remove_collected_tanks();
}

void room_reset(void)
{

}

void room_set_background_scrolling(void)
{

}

void room_maybe_set_initial_tilemap(u8 bg_number)
{

}

u8 room_rle_decompress(u8 mode, u8* src, u8* dst)
{
    u32 len;
    u8* dest;
    u8* unk;
    u8* unk2;
    u8 unk3;
    u16 unk4;
    u32 i;

    len = 0x3000;
    if (mode == 0x0)
    {
        src++;
        len = 0x2000;
    }
    bit_fill(0x3, 0x0, dst, len, 0x10);

    len = 0x0;
    do {
        dest = dst;
        if (len != 0x0)
            dest = dst + 0x1;
        unk = src + 0x1;
        if (*src == 0x1)
        {
            unk3 = *unk;
            src += 0x2;
            while (i = unk3, i != 0x0)
            {
                if ((unk3 & 0x80) == 0x0)
                {
                    for (; i != 0x0; i--)
                    {
                        *dest = *src;
                        src++;
                        dst += 0x2;
                    }
                }
                else
                {
                    i &= 0x7F;
                    if (*src == 0x0)
                        dest = dest + (i * 0x2);
                    else
                    {
                        for (; i != 0x0; i--)
                        {
                            *dest = *src;
                            dest += 0x2;
                        }
                    }
                    src++;
                }
                unk3 = *src;
                src++;
            }
        }
        else
        {
            unk = src + 0x2;
            src += 0x3;
            unk4 = (*unk << 0x8 | *unk2);
            while (i = unk4, i != 0x0)
            {
                if ((unk4 & 0x8000) == 0x0)
                {
                    for (; i != 0x0; i--)
                    {
                        *dest = *src;
                        src++;
                        dest += 0x2;
                    }
                }
                else
                {
                    i &= 0x7FFF;
                    if (*src == 0x0)
                        dest = dest + (i * 0x2);
                    else
                    {
                        if ((unk4 & 0x7FFF) != 0x0)
                        {
                            do {
                                *dest = *src;
                                dest += 0x2;
                                i--;
                            } while(i != 0x0);
                        }
                    }
                    src++;
                }
                unk3 = *src;
                unk = src + 0x1;
                src += 0x2;
                unk4 = (unk3 << 0x8 | *unk);
            }
        }
        len++;
    } while (len < 0x2);
    return 0x0;
}

void room_unk56e28(void)
{

}

void room_maybe_check_update_animated_graphics_palette(void)
{

}

void room_unk56ef4(void)
{

}

void room_update(void)
{

}

void room_update_backgrounds_position(void)
{
    i32 y_offset;
    i32 x_offset;
    u16 x_pos_shift;
    u16 y_pos_shift;
    u16 new_bg3_x;
    u16 new_bg3_y;

    y_offset = screen_shake_update_vertical();
    x_offset = screen_shake_update_horizontal();

    x_pos_shift = bg1_x_position >> 0x2 & 0x1FF;
    y_pos_shift = bg1_y_position >> 0x2 & 0x1FF;
    background_positions.bg[1].x = x_pos_shift + x_offset;
    background_positions.bg[1].y = y_pos_shift + y_offset;
    x_pos_shift = bg2_x_position >> 0x2 & 0x1FF;
    background_positions.bg[2].x = x_pos_shift + x_offset;
    y_pos_shift = bg2_y_position >> 0x2 & 0x1FF;
    background_positions.bg[2].y = y_pos_shift + y_offset;

    if ((screen_shake_related & 0x100) != 0x0)
    {
        background_positions.bg[0].x = (bg0_x_position >> 0x2) + bg0_movement.y_offset & 0x1FF;
        background_positions.bg[0].y = (bg0_y_position >> 0x2) + bg0_movement.snowflakes_related & 0x1FF;
    }
    else
    {
        background_positions.bg[0].x = ((bg0_x_position >> 0x2) + bg0_movement.y_offset & 0x1FF) + x_offset;
        background_positions.bg[0].y = ((bg0_y_position >> 0x2) + bg0_movement.snowflakes_related & 0x1FF) + x_offset;
    }

    new_bg3_x = (bg3_x_position >> 0x2) + bg3_movement.sub2.x_offset & 0x1FF;
    new_bg3_y = bg3_y_position >> 0x2 & 0x1FF;

    if ((screen_shake_related & 0x800) != 0x0)
    {
        background_positions.bg[3].x = new_bg3_x;
        background_positions.bg[3].y = new_bg3_y;
    }
    else
    {
        background_positions.bg[3].x = new_bg3_x + (x_offset >> 0x1);
        background_positions.bg[3].y = new_bg3_y + (y_offset >> 0x1);
    }
}

void room_maybe_update_vertical_tilemap(u8 unk)
{

}

void room_maybe_update_horizontal_tilemap(u8 unk)
{

}

void room_check_dma3_ended(void)
{
    
}