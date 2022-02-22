#include "waver.h"
#include "../sprite_util.h"
#include "../globals.h"

void waver_init(void)
{
    current_sprite.draw_distance_top_offset = 0x10;
    current_sprite.draw_distance_bottom_offset = 0x10;
    current_sprite.draw_distance_horizontal_offset = 0x10;
    current_sprite.hitbox_top_offset = -0x20;
    current_sprite.hitbox_bottom_offset = 0x20;
    current_sprite.hitbox_left_offset = -0x20;
    current_sprite.hitbox_right_offset = -0x20;
    current_sprite.oam_pointer = waver_oam_2d88ac;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.health = primary_sprite_stats_2b0d68[current_sprite.sprite_id][0x0];
    current_sprite.samus_collision = SSC_HURTS_SAMUS;
    sprite_util_make_sprite_face_samus_x_flip();
    current_sprite.pose = 0x9;
}

void waver_move(void)
{
    u16 speed;

    speed = 0x2;
    if (current_sprite.status & SPRITE_STATUS_XFLIP)
    {
        sprite_util_check_collision_at_position(current_sprite.y_position, current_sprite.hitbox_right_offset + current_sprite.x_position);
        if (previous_collision_check == 0x0)
            current_sprite.x_position += 0x4;
        else
            current_sprite.status &= ~SPRITE_STATUS_XFLIP;
    }
    else
    {
        sprite_util_check_collision_at_position(current_sprite.y_position, current_sprite.hitbox_left_offset + current_sprite.x_position);
        if (previous_collision_check == 0x0)
            current_sprite.x_position -= 0x4;
        else
            current_sprite.status |= SPRITE_STATUS_XFLIP;
    }

    if (current_sprite.status & SPRITE_STATUS_ON_VERTICAL_WALL)
    {
        sprite_util_check_collision_at_position(current_sprite.hitbox_top_offset + current_sprite.y_position, current_sprite.x_position);
        if (previous_collision_check == 0x0)
            current_sprite.y_position -= speed;
        else
            current_sprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
    }
    else
    {
        sprite_util_check_collision_at_position(current_sprite.hitbox_bottom_offset + current_sprite.y_position, current_sprite.x_position);
        if (previous_collision_check == 0x0)
            current_sprite.y_position += speed;
        else
            current_sprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
    }
}

void waver(void)
{
    if (current_sprite.properties & SP_UNKNOWN)
    {
        current_sprite.properties &= ~SP_UNKNOWN;
        if (current_sprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x177);
    }

    if (current_sprite.freeze_timer != 0x0)
        sprite_util_update_freeze_timer();
    else
    {
        if (!sprite_util_is_sprite_stunned())
        {
            switch (current_sprite.pose)
            {
                default:
                    sprite_util_sprite_death(DEATH_NORMAL, current_sprite.y_position, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                    break;
                case 0x0:
                    waver_init();
                    break;
                case 0x9:
                    waver_move();
            }
        }
    }
}