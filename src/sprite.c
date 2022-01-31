#include "sprite.h"
#include "globals.h"
#include "sprite_debris.h"

void sprite_update(void)
{

}

void sprite_update_animation(struct sprite_data* ptr)
{
    u32 adc;

    if (ptr->freeze_timer == 0x0)
    {
        adc = ptr->anim_duration_counter + 0x1;
        ptr->anim_duration_counter = adc;
        if ((u8)ptr->oam_pointer[ptr->curr_anim_frame].timer < (u8)adc)
        {
            ptr->anim_duration_counter = 0x1;
            ptr->curr_anim_frame++;
            if ((u8)ptr->oam_pointer[ptr->curr_anim_frame].timer == 0x0)
                ptr->curr_anim_frame = 0x0;
        }
    }
}

void sprite_draw_all_2(void)
{

}

void sprite_draw_all(void)
{
    struct sprite_data* ptr;
    enum sprite_status status_flag;
    enum sprite_status status_check;
    u8* draw_order;
    u8* g_draw_order;
    u32 ram_slot;
    int i;
    u32 unk;
    i32 unk2;
    u8 zero;

    status_flag = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN;
    status_check = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN;
    sprite_debris_draw_all();
    ptr = sprite_data;
    zero = 0x0;
    g_draw_order = sprite_draw_order;
    draw_order = &sprite_data[0].draw_order;
    //ram_slot = 0x17;

    for (i = 0x17; i >= 0x0; i--)
    {
        if ((ptr->status & status_flag) == status_check && *draw_order < 0x9)
            *g_draw_order = *draw_order;
        else
            *g_draw_order = zero;
        g_draw_order += 0x1;
        draw_order += 0x38;
        ptr++;
    }
    
    unk = 0x1;
    
    do
    {
        ram_slot = 0x0;
        ptr = sprite_data;
        unk2 = unk + 0x1;

        do
        {
            if (sprite_draw_order[ram_slot] == unk)
            {
                sprite_draw(ptr, ram_slot);

            }
            ram_slot++;
            ptr++;
        } while ((u32)ptr < 0x30006ec);
        unk = unk2;
    } while (unk2 < 0x9);
}

void sprite_draw_all_3(void)
{

}

void sprite_draw(struct sprite_data* ptr, u32 slot)
{
    
}

void sprite_check_on_screen(struct sprite_data* ptr)
{
    u16 y_pos;
    u16 bg1X;
    u16 bg1Y;
    u16 x_pos;

    if ((ptr->properties & SP_MESSAGE_BANNER) == 0x0)
    {
        bg1Y = bg1_y_position;
        bg1X = bg1_x_position;
        x_pos = ptr->x_position;
        y_pos = ptr->y_position + 0x200;

        

        if (
            (bg1_y_position + 0x200 + ptr->draw_distance_bottom_offset * -0x4 < (ptr->y_position + 0x200)) &&
            (y_pos < bg1_y_position + 0x200 + ptr->draw_distance_top_offset * 0x4 + 0x280) &&
            (bg1_x_position + 0x200 + ptr->draw_distance_horizontal_offset * -0x4 < x_pos + 0x200) &&
            (x_pos + 0x200 < bg1_x_position + 0x200 + ptr->draw_distance_horizontal_offset * 0x4 + 0x3C0)
        )
            ptr->status |= SPRITE_STATUS_ONSCREEN;
        else
        {
            ptr->status &= ~SPRITE_STATUS_ONSCREEN;
            if ((ptr->properties & SP_PROJECTILE) != 0x0)
            {
                y_pos = ptr->y_position + 0x280;
                if (
                    (x_pos + 0x280 <= bg1X + 0x40) ||
                    (bg1X + 0x880 <= x_pos + 0x280) ||
                    (y_pos <= bg1Y + 0x40) ||
                    (bg1Y + 0x740 <= y_pos)
                )
                    ptr->status = 0x0;
            }
        }
    } 
}

void sprite_load_all_data(void)
{
    if (pause_screen_flag == 0x0)
    {
        if (game_mode_sub3 == 0x0 && is_current_file_existing == FALSE)
            alarm_timer = 0x0;
        sprite_clear_data();
        sprite_load_spriteset();
        //unk_53a18();
        //init_location_text();
        sprite_load_room_sprites();
        //spawn_waiting_pirates();
        parasite_related = 0x0;
    }
}

void sprite_load_spriteset(void)
{

}

void sprite_load_gfx(enum p_sprite_id sprite_id, u8 gfx_row)
{

}

void sprite_load_pal(enum p_sprite_id sprite_id, u8 gfx_row, u32 len)
{
    
}

void sprite_clear_data(void)
{
    /*struct sprite_data* s_ptr;
    struct sprite_debris* sd_ptr;
    i32 i;

    s_ptr = sprite_data;
    i = 0x17;

    while (i >= 0)
    {
        s_ptr->status = 0x0;
        s_ptr->standing_on_sprite = FALSE;
        s_ptr->room_slot = 0xFF;
        s_ptr++;
        i--;
    }

    sd_ptr = sprite_debris + 7;
    while (sd_ptr >= sprite_debris)
    {
        sd_ptr->exists = FALSE;
        sd_ptr--;
    }*/
}

void sprite_load_room_sprites(void)
{
    u8 room_slot;
    u8 y_pos;
    u8 x_pos;

    room_slot = 0x0;
    y_pos = (current_room_entry.enemy_room_data)->y_position;
    if (y_pos == 0xFF) return;
    while (1)
    {
        x_pos = current_room_entry.enemy_room_data[room_slot].x_position;
        sprite_init_primary(current_room_entry.enemy_room_data[room_slot].spriteset_slot, y_pos, x_pos, room_slot);
        room_slot++;
        if (room_slot > 0x17) return;
        y_pos = current_room_entry.enemy_room_data[room_slot].y_position;
        if (y_pos == 0xFF) return;
    }
}

void sprite_init_primary(u8 spriteset_slot, u16 y_position, u16 x_position, u8 room_slot)
{
    struct sprite_data* ptr;
    u8 ram_slot;
    u8 slot;
    u8 unk;
    enum s_sprite_id id;

    ram_slot = 0x0;
    ptr = sprite_data;

    while (ptr < sprite_data + 24)
    {
        if ((ptr->status & SPRITE_STATUS_EXISTS) == 0x0)
        {
            ptr->status = SPRITE_STATUS_EXISTS;
            slot = spriteset_slot & 0x7F;
            if (slot < 0x11)
            {
                ptr->spriteset_gfx_slot = 0x0;
                id = slot - 0x1;
            }
            else
            {
                unk = (slot - 0x1 & 0xf);
                ptr->spriteset_gfx_slot = spriteset_sprite_gfx_slots[unk];
                id = spriteset_sprite_id[unk];
            }
            ptr->sprite_id = id;
            ptr->properties = 0x0;
            ptr->y_position = y_position * 0x40 + 0x40;
            ptr->x_position = x_position * 0x40 + 0x20;
            ptr->room_slot = room_slot;
            ptr->bg_priority = 0x2;
            ptr->draw_order = 0x4;
            ptr->pose = 0x0;
            ptr->health = 0x0;
            ptr->invicibility_stun_flash_timer = 0x0;
            ptr->palette_row = 0x0;
            ptr->frozen_palette_row_offset = 0x0;
            ptr->maybe_absolute_palette_row = 0x0;
            ptr->ignore_samus_collision_timer = 0x1;
            ptr->primary_sprite_ram_slot = slot;
            ptr->freeze_timer = 0x0;
            ptr->standing_on_sprite = FALSE;
            return;
        }
        ram_slot++;
        ptr++;
    }
}

u8 sprite_spawn_secondary(enum s_sprite_id sprite_id, u8 room_slot, u8 gfx_slot, u8 ram_slot, u16 y_position, u16 x_position, enum sprite_status status_to_add)
{
    u8 new_ram_slot;
    struct sprite_data* ptr;
    enum sprite_status status;

    new_ram_slot = 0x0;
    ptr = sprite_data;

    while (ptr < sprite_data + 24)
    {
        status = ptr->status & SPRITE_STATUS_EXISTS;
        if (status == 0x0)
        {
            ptr->status = status_to_add | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            ptr->properties = SP_SECONDARY_SPRITE;
            ptr->spriteset_gfx_row = gfx_slot;
            ptr->sprite_id = sprite_id;
            ptr->y_position = y_position;
            ptr->x_position = x_position;
            ptr->room_slot = room_slot;
            ptr->bg_priority = 0x2;
            ptr->draw_order = 0x4;
            ptr->pose = 0x0;
            ptr->health = status;
            ptr->invicibility_stun_flash_timer = 0x0;
            ptr->palette_row = 0x0;
            ptr->frozen_palette_row_offset = 0x0;
            ptr->maybe_absolute_palette_row = 0x0;
            ptr->ignore_samus_collision_timer = 0x1;
            ptr->primary_sprite_ram_slot = ram_slot;
            ptr->freeze_timer = 0x0;
            ptr->standing_on_sprite = FALSE;

            return new_ram_slot;
        }

        new_ram_slot += 0x1;
        ptr += 0x1;
    }

    return 0xFF;
}

u8 sprite_spawn_primary(enum p_sprite_id sprite_id, u8 room_slot, u8 gfx_slot, u16 y_position, u16 x_position, enum sprite_status status_to_add)
{
    u8 new_ram_slot;
    struct sprite_data* ptr;
    enum sprite_status status;

    new_ram_slot = 0x0;
    ptr = sprite_data;

    while (ptr < sprite_data + 24)
    {
        status = ptr->status & SPRITE_STATUS_EXISTS;
        if (status == 0x0)
        {
            ptr->status = status_to_add | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            ptr->properties = 0x0;
            ptr->spriteset_gfx_slot = gfx_slot;
            ptr->sprite_id = sprite_id;
            ptr->y_position = y_position;
            ptr->x_position = x_position;
            ptr->room_slot = room_slot;
            ptr->bg_priority = 0x2;
            ptr->draw_order = 0x4;
            ptr->pose = 0x0;
            ptr->health = status;
            ptr->invicibility_stun_flash_timer = 0x0;
            ptr->palette_row = 0x0;
            ptr->frozen_palette_row_offset = 0x0;
            ptr->maybe_absolute_palette_row = 0x0;
            ptr->ignore_samus_collision_timer = 0x1;
            ptr->primary_sprite_ram_slot = new_ram_slot;
            ptr->freeze_timer = 0x0;
            ptr->standing_on_sprite = FALSE;

            return new_ram_slot;
        }

        new_ram_slot += 0x1;
        ptr += 0x1;
    }

    return 0xFF;
}

u8 sprite_spawn_drop_followers(enum p_sprite_id sprite_id, u8 room_slot, u8 gfx_slot, u8 ram_slot, u16 y_position, u16 x_position, enum sprite_status status_to_add)
{
    u8 new_ram_slot;
    struct sprite_data* ptr;
    enum sprite_status status;

    new_ram_slot = 0x0;
    ptr = sprite_data;

    while (ptr < sprite_data + 24)
    {
        status = ptr->status & SPRITE_STATUS_EXISTS;
        if (status == 0x0)
        {
            ptr->status = status_to_add | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            ptr->properties = 0x0;
            ptr->spriteset_gfx_row = gfx_slot;
            ptr->sprite_id = sprite_id;
            ptr->y_position = y_position;
            ptr->x_position = x_position;
            ptr->room_slot = room_slot;
            ptr->bg_priority = 0x2;
            ptr->draw_order = 0x4;
            ptr->pose = 0x0;
            ptr->health = status;
            ptr->invicibility_stun_flash_timer = 0x0;
            ptr->palette_row = 0x0;
            ptr->frozen_palette_row_offset = 0x0;
            ptr->maybe_absolute_palette_row = 0x0;
            ptr->ignore_samus_collision_timer = 0x1;
            ptr->primary_sprite_ram_slot = ram_slot;
            ptr->freeze_timer = 0x0;
            ptr->standing_on_sprite = FALSE;

            return new_ram_slot;
        }

        new_ram_slot += 0x1;
        ptr += 0x1;
    }

    return 0xFF;
}