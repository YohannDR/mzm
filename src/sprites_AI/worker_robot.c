#include "worker_robot.h"
#include "../sprite_util.h"
#include "../globals.h"

u8 worker_robot_check_samus_in_front(void)
{
    u16 sprite_y;
    u16 sprite_x;
    u16 sprite_top;
    u16 sprite_left;
    u16 sprite_right;
    u16 samus_y;
    u16 samus_x;
    u16 samus_top;
    u16 samus_bottom;
    u16 samus_left;
    u16 samus_right;

    if ((current_sprite.status & SPRITE_STATUS_SAMUS_ON_TOP) == 0x0)
    {
        sprite_y = current_sprite.y_position;
        sprite_x = current_sprite.x_position;
        sprite_top = sprite_y - 0xA4;
        sprite_left = sprite_y - 0x48;
        sprite_right = sprite_y + 0x48;

        samus_y = samus_data.y_position;
        samus_x = samus_data.x_position;
        samus_top = samus_y + samus_physics.draw_distance_top_offset;
        samus_bottom = samus_y + samus_physics.draw_distance_bottom_offset;
        samus_left = samus_x + samus_physics.draw_distance_left_offset;
        samus_right = samus_x + samus_physics.draw_distance_right_offset;

        if (sprite_util_check_objects_touching(sprite_top, sprite_y, sprite_left, sprite_right, samus_top, samus_bottom, samus_left, samus_right))
        {
            if (current_sprite.status & SPRITE_STATUS_XFLIP)
            {
                if (sprite_x < samus_x)
                    return TRUE;
            }
            else
            {
                if (sprite_x > samus_x)
                    return TRUE;
            }
        }
    }
    
    return FALSE;
}

void worker_robot_init(void)
{
    current_sprite.hitbox_top_offset = -0x74;
    current_sprite.hitbox_bottom_offset = 0x0;
    current_sprite.hitbox_left_offset = -0x1C;
    current_sprite.hitbox_right_offset = 0x1C;
    current_sprite.draw_distance_top_offset = 0x28;
    current_sprite.draw_distance_bottom_offset = 0x0;
    current_sprite.draw_distance_horizontal_offset = 0x10;
    current_sprite.oam_pointer = worker_robot_oam_2e7bcc;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    current_sprite.timer2 = 0x0;
    current_sprite.samus_collision = SSC_SOLID;
    current_sprite.health = primary_sprite_stats_2b0d68[current_sprite.sprite_id][0x0];
    sprite_util_make_sprite_face_away_samus_x_flip();
    if (current_sprite.status & SPRITE_STATUS_XFLIP)
        current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
    current_sprite.pose = 0x11;
}

void worker_robot_gfx_init(void)
{
    current_sprite.pose = 0x11;
    current_sprite.oam_pointer = worker_robot_oam_2e7bcc;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.anim_duration_counter = 0x0;
}

void worker_robot_sleeping_detect_projectile(void)
{
    if (sprite_util_check_collision_at_position_no_global(current_sprite.y_position, current_sprite.x_position) == 0x0)
        current_sprite.pose = 0x20;
    else if (current_sprite.invicibility_stun_flash_timer & 0x7F)
        current_sprite.pose = 0x12;
}

void worker_robot_standing_gfx_init(void)
{

}

void worker_robot_check_standing_anim_ended(void)
{

}

void worker_robot_walking_detect_projectile(void)
{

}

void worker_robot_waking_up_gfx_init(void)
{

}

void worker_robot_check_projectile(void)
{

}

void worker_robot_walk_gfx_init(void)
{

}

void worker_robot_move(void)
{

}

void worker_robot_back_to_sleep_gfx_init(void)
{

}

void worker_robot_check_back_to_sleep_anim_ended(void)
{

}

void worker_robot_turning_around(void)
{

}

void worker_robot_check_turning_around_anim_ended(void)
{

}

void worker_robot_falling_gfx_init(void)
{

}

void worker_robot_falling(void)
{

}

void worker_robot_falling_sleep_gfx_init(void)
{

}

void worker_robot_falling_speed(void)
{

}

void worker_robot(void)
{

}