#include "metroid.h"
#include "../sprite_util.h"
#include "../globals.h"

u8 metroid_check_air_collision(u16 y_position, u16 x_position)
{

}

void metroid_move(u16 samus_y, u16 samus_x, u8 speed_y, u8 speed_x, u8 speed_divisor)
{

}

u8 metroid_bomb_detection(void)
{

}

void metroid_check_bouncing_on_metroid(u16 movement)
{

}

u8 metroid_check_samus_grabbed(void)
{

}

void metroid_play_sound(void)
{

}

void metroid_init(void)
{

}

void metroid_gfx_init(void)
{

}

void metroid_spawning(void)
{

}

void metroid_spawned_gfx_init(void)
{

}

void metroid_movement(void)
{

}

void metroid_grab_samus_gfx_init(void)
{

}

void metroid_samus_grabbed(void)
{

}

void metroid_death(void)
{

}

void metroid(void)
{
    
}

void metroid_shell(void)
{
    u8 slot;
    u8 rng;
    u16 y_position;
    u16 x_position;

    slot = current_sprite.primary_sprite_ram_slot;
    current_sprite.ignore_samus_collision_timer = 0x1;
    current_sprite.palette_row = sprite_data[slot].palette_row;
    if (sprite_data[slot].health == 0x0)
    {
        rng = sprite_rng;
        y_position = current_sprite.y_position;
        x_position = current_sprite.x_position;
        if (sprite_data[slot].status & SPRITE_STATUS_XFLIP)
            y_position -= rng;
        else
            y_position += rng;

        current_sprite.sprite_id = PSPRITE_METROID;
        current_sprite.properties &= ~SP_SECONDARY_SPRITE;
        sprite_util_sprite_death(DEATH_NORMAL, y_position, x_position - 0x24, TRUE, PE_FREEZING_SPRITE_WITH_CHARGED_ICE);
    }
    else
    {
        if (current_sprite.pose == 0x0)
        {
            current_sprite.samus_collision = SSC_NONE;
            current_sprite.draw_distance_top_offset = 0x14;
            current_sprite.draw_distance_bottom_offset = 0xA;
            current_sprite.draw_distance_horizontal_offset = 0x18;
            current_sprite.hitbox_top_offset = -0x4;
            current_sprite.hitbox_bottom_offset = 0x4;
            current_sprite.hitbox_left_offset = -0x4;
            current_sprite.hitbox_right_offset = 0x4;
            current_sprite.pose = 0x9;
            current_sprite.draw_order = 0x3;
            current_sprite.oam_pointer = metroid_shell_oam_2edc08;
            current_sprite.anim_duration_counter = 0x0;
            current_sprite.curr_anim_frame = 0x0;
        }

        if (current_sprite.status & SPRITE_STATUS_NOT_DRAWN && (sprite_data[slot].status & SPRITE_STATUS_YFLIP) == 0x0)
            current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

        current_sprite.y_position = sprite_data[slot].y_position;
        current_sprite.x_position = sprite_data[slot].x_position;
    }
}

void metroid_door_lock(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    if (current_sprite.pose == 0x0)
    {
        current_sprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
        current_sprite.samus_collision = SSC_NONE;
        current_sprite.draw_distance_top_offset = 0x1;
        current_sprite.draw_distance_bottom_offset = 0x1;
        current_sprite.draw_distance_horizontal_offset = 0x1;
        current_sprite.hitbox_top_offset = 0x0;
        current_sprite.hitbox_bottom_offset = 0x0;
        current_sprite.hitbox_left_offset = 0x0;
        current_sprite.hitbox_right_offset = 0x0;
        current_sprite.pose = 0x8;
        current_sprite.oam_pointer = large_energy_oam_2b2750;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;

        if (sprite_util_count_primary_sprites(PSPRITE_METROID) != 0x0)
            door_unlock_timer = 0x1;
        else
            current_sprite.status = 0x0;
    }
    else
    {
        if (sprite_util_count_primary_sprites(PSPRITE_METROID) == 0x0 && sprite_util_count_primary_sprites(PSPRITE_FROZEN_METROID) == 0x0)
        {
            current_sprite.status = 0x0;
            door_unlock_timer = -0x14;
        }
    }
}