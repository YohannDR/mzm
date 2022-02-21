#include "geruta.h"
#include "../sprite_util.h"
#include "../globals.h"

u8 geruta_y_movement(u16 movement)
{
    if (current_sprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        if (sprite_util_check_collision_at_position_no_global(current_sprite.y_position + 0x40, current_sprite.x_position) == 0x11 ||
            sprite_util_check_collision_at_position_no_global(current_sprite.y_position + 0x40, current_sprite.x_position - 0x30) == 0x11 ||
            sprite_util_check_collision_at_position_no_global(current_sprite.y_position + 0x40, current_sprite.x_position + 0x30) == 0x11)
            return TRUE;
        current_sprite.y_position += movement;
    }
    else
    {
        if (sprite_util_check_collision_at_position_no_global(current_sprite.y_position - 0x28, current_sprite.x_position - 0x30) == 0x11 &&
            sprite_util_check_collision_at_position_no_global(current_sprite.y_position - 0x28, current_sprite.x_position - 0x70) == 0x11)
            return TRUE;

        if (sprite_util_check_collision_at_position_no_global(current_sprite.y_position - 0x28, current_sprite.x_position + 0x30) == 0x11 &&
            sprite_util_check_collision_at_position_no_global(current_sprite.y_position - 0x28, current_sprite.x_position + 0x70) == 0x11)
            return TRUE;

        current_sprite.y_position -= movement;
    }

    return FALSE;
}

u8 geruta_x_movement(u16 movement)
{
    register u16 movement_;

    movement_ = movement;

    if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (sprite_util_check_collision_at_position_no_global(current_sprite.y_position - 0x20, current_sprite.x_position + 0x40) == 0x11 || sprite_util_check_collision_at_position_no_global(current_sprite.y_position + 0x20, current_sprite.x_position + 0x40) == 0x11)
            return TRUE;
        current_sprite.x_position += movement;
    }
    else
    {
        if (sprite_util_check_collision_at_position_no_global(current_sprite.y_position - 0x20, current_sprite.x_position - 0x40) == 0x11 || sprite_util_check_collision_at_position_no_global(current_sprite.y_position + 0x20, current_sprite.x_position - 0x40) == 0x11)
            return TRUE;
        current_sprite.x_position -= movement_;
    }
    
    return FALSE;
}

void geruta_init(void)
{
    current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    sprite_util_make_sprite_face_samus_direction();
    current_sprite.draw_distance_top_offset = 0x18;
    current_sprite.draw_distance_bottom_offset = 0x18;
    current_sprite.draw_distance_horizontal_offset = 0x18;
    current_sprite.hitbox_top_offset = -0x20;
    current_sprite.hitbox_bottom_offset = 0x20;
    current_sprite.hitbox_left_offset = -0x30;
    current_sprite.hitbox_right_offset = 0x30;
    current_sprite.oam_pointer = geruta_oam_2d1400;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.health = primary_sprite_stats_2b0d68[current_sprite.sprite_id][0x0];
    current_sprite.samus_collision = SSC_HURTS_SAMUS;
    current_sprite.y_position -= 0xC;
    current_sprite.pose = 0x8;
}

void geruta_gfx_init(void)
{
    current_sprite.pose = 0x9;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.oam_pointer = geruta_oam_2d1400;
}

void geruta_detect_samus(void)
{
    enum near_sprite_left_right nslr;

    if (sprite_util_check_collision_at_position_no_global(current_sprite.y_position - 0x40, current_sprite.x_position - 0x30) != 0x11 && sprite_util_check_collision_at_position_no_global(current_sprite.y_position - 0x40, current_sprite.x_position + 0x30) != 0x11)
        sprite_util_make_sprite_face_samus_direction();
    else
    {
        if ((samus_data.y_position - 0x48) >= current_sprite.y_position)
        {
            nslr = sprite_util_check_samus_near_sprite_left_right(0x140, 0x140);
            if (nslr != NSLR_RIGHT && nslr != NSLR_LEFT)
                return;
            current_sprite.pose = 0x32;
            return;
        }
        else
            return;
    }

    current_sprite.pose = 0x32;
}

void geruta_go_down_gfx_init(void)
{
    current_sprite.pose = 0x33;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.oam_pointer = geruta_oam_2d1418;
    if ((current_sprite.status & SPRITE_STATUS_ONSCREEN))
        play_sound1(0x150);
}

void geruta_check_warning_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        current_sprite.pose = 0x35;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.oam_pointer = geruta_oam_2d1438;
    }
}

void geruta_check_going_down_anim_ended(void)
{
    if (sprite_util_check_end_sprite_anim())
    {
        current_sprite.pose = 0x37;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.oam_pointer = geruta_oam_2d1460;
        current_sprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
        sprite_util_make_sprite_face_samus_direction();
        if ((current_sprite.status & SPRITE_STATUS_ONSCREEN))
            unk_2b20(0x14E);
    }
}

void geruta_going_down(void)
{
    u16 old_y;

    old_y = current_sprite.y_position;
    geruta_x_movement(0x4);
    if (geruta_y_movement(0xC) << 0x18)
    {
        current_sprite.pose = 0x39;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.oam_pointer = geruta_oam_2d1488;
    }

    sprite_util_check_in_room_effect(old_y, current_sprite.y_position, current_sprite.x_position, SPLASH_BIG);
}

void geruta_check_bouncing_anim_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        current_sprite.pose = 0x3B;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.oam_pointer = geruta_oam_2d14a0;
        current_sprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        if ((current_sprite.status & SPRITE_STATUS_ONSCREEN))
            unk_2b20(0x14F);
    }
}

void geruta_going_up(void)
{
    geruta_x_movement(0x4);
    if (geruta_y_movement(0xC) << 0x18)
    {
        current_sprite.y_position = (current_sprite.y_position & 0xFFC0);
        current_sprite.y_position  += 0x34;
        current_sprite.pose = 0x3D;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.oam_pointer = geruta_oam_2d14c8;
    }
}

void geruta_check_reset_anim_ended(void)
{
    if (sprite_util_check_near_end_sprite_anim())
        current_sprite.pose = 0x8;
}

void geruta(void)
{
    if ((current_sprite.properties & SP_UNKNOWN) != 0x0)
    {
        current_sprite.properties &= ~SP_UNKNOWN;
        if ((current_sprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
            unk_2b20(0x151);
    }

    if (current_sprite.freeze_timer != 0x0)
        sprite_util_update_freeze_timer();
    else
    {
        if (!sprite_util_is_sprite_stunned())
        {
            switch (current_sprite.pose)
            {
                case 0x0:
                    geruta_init();
                    break;
                case 0x8:
                    geruta_gfx_init();
                case 0x9:
                    geruta_detect_samus();
                    break;
                case 0x32:
                    geruta_go_down_gfx_init();
                case 0x33:
                    geruta_check_warning_ended();
                    break;
                case 0x35:
                    geruta_check_going_down_anim_ended();
                    break;
                case 0x37:
                    geruta_going_down();
                    break;
                case 0x39:
                    geruta_check_bouncing_anim_ended();
                    break;
                case 0x3B:
                    geruta_going_up();
                    break;
                case 0x3D:
                    geruta_check_reset_anim_ended();
                    break;

                default:
                    sprite_util_sprite_death(DEATH_NORMAL, current_sprite.y_position, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
        }
    }
}