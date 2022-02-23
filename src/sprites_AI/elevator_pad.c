#include "elevator_pad.h"
#include "../samus.h"
#include "../globals.h"

void elevator_pad(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    if (current_sprite.pose == 0x0)
    {
        current_sprite.y_position -= 0x8;
        current_sprite.properties |= SP_ALWAYS_ACTIVE;
        current_sprite.samus_collision = SSC_NONE;
        current_sprite.pose = 0x9;
        current_sprite.draw_distance_top_offset = 0x1;
        current_sprite.draw_distance_bottom_offset = 0x8;
        current_sprite.draw_distance_horizontal_offset = 0x10;
        current_sprite.hitbox_top_offset = -0x4;
        current_sprite.hitbox_bottom_offset = 0x4;
        current_sprite.hitbox_left_offset = -0x4;
        current_sprite.hitbox_right_offset = -0x4;
        current_sprite.oam_pointer = elevator_pad_oam_2e0fe8;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
    }

    if (samus_data.pose == SPOSE_USING_AN_ELEVATOR)
    {
        current_sprite.y_position = samus_data.y_position;
        current_sprite.x_position = samus_data.x_position;
        if (current_sprite.oam_pointer == elevator_pad_oam_2e0fe8)
        {
            current_sprite.oam_pointer = elevator_pad_oam_2e0fc0;
            current_sprite.anim_duration_counter = 0x0;
            current_sprite.curr_anim_frame = 0x0;
        }
    }
    else
    {
        if (current_sprite.oam_pointer == elevator_pad_oam_2e0fc0)
        {
            current_sprite.oam_pointer = elevator_pad_oam_2e0fe8;
            current_sprite.anim_duration_counter = 0x0;
            current_sprite.curr_anim_frame = 0x0;
        }
    }
}