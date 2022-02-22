#include "power_grip.h"
#include "../sprite_util.h"
#include "../sprite.h"
#include "../globals.h"
#include "../event.h"

void power_grip(void)
{
    switch (current_sprite.pose)
    {
        case 0x0:
            if (equipment.suit_misc & SMF_POWER_GRIP)
                current_sprite.status = 0x0;
            else
            {
                current_sprite.draw_distance_top_offset = 0x8;
                current_sprite.draw_distance_bottom_offset = 0x8;
                current_sprite.draw_distance_horizontal_offset = 0x8;
                current_sprite.hitbox_top_offset = -0x1C;
                current_sprite.hitbox_bottom_offset = 0x1C;
                current_sprite.hitbox_left_offset = -0x1C;
                current_sprite.hitbox_right_offset = 0x1C;
                current_sprite.oam_pointer = power_grip_oam_2b310c;
                current_sprite.anim_duration_counter = 0x0;
                current_sprite.curr_anim_frame = 0x0;
                current_sprite.samus_collision = SSC_ABILITY_LASER_SEARCHLIGHT;
                current_sprite.health = 0x1;
                current_sprite.y_position -= 0x40;
                current_sprite.pose = 0x9;
                sprite_spawn_secondary(SSPRITE_POWER_GRIP_GLOW, current_sprite.room_slot, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, current_sprite.y_position, current_sprite.x_position, 0x0);
            }
            break;

        case 0x9:
            if ((current_sprite.status & SPRITE_STATUS_SAMUS_COLLIDING) != 0x0)
            {
                prevent_movement_timer = 0x3E8;
                current_sprite.properties |= SP_ALWAYS_ACTIVE;
                current_sprite.ignore_samus_collision_timer = 0x1;
                current_sprite.pose = 0x23;
                current_sprite.timer1 = 0x0;
                equipment.suit_misc |= SMF_POWER_GRIP;
                event_function(EVENT_ACTION_SETTING, EVENT_POWER_GRIP_OBTAINED);
                sprite_spawn_primary(PSPRITE_ITEM_BANNER, 0x15,0x6, current_sprite.y_position, current_sprite.x_position, 0x0);
            }
            break;

        case 0x23:
            current_sprite.ignore_samus_collision_timer = 0x1;
            if ((current_sprite.timer1 & 0x1) == 0x0)
                current_sprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            if (prevent_movement_timer < 0x3E7)
                current_sprite.status = 0x0;
    }
}

void power_grip_glow(void)
{
    switch (current_sprite.pose)
    {
        case 0x0:
            current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            current_sprite.draw_distance_top_offset = 0x10;
            current_sprite.draw_distance_bottom_offset = 0x10;
            current_sprite.draw_distance_horizontal_offset = 0x10;
            current_sprite.hitbox_top_offset = 0x0;
            current_sprite.hitbox_bottom_offset = 0x0;
            current_sprite.hitbox_left_offset = 0x0;
            current_sprite.hitbox_right_offset = 0x0;
            current_sprite.oam_pointer = power_grip_glow_oam;
            current_sprite.anim_duration_counter = 0x0;
            current_sprite.curr_anim_frame = 0x0;
            current_sprite.samus_collision = SSC_NONE;
            current_sprite.pose = 0x9;
            current_sprite.draw_order = 0x5;
            break;

        case 0x9:
            if (0x22 < sprite_data[current_sprite.primary_sprite_ram_slot].pose)
                current_sprite.status = 0x0;
    }
}