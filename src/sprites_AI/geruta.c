#include "geruta.h"
#include "../sprite_util.h"
#include "../globals.h"

u8 geruta_y_movement(u16 movement)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        if (sprite_util_get_collision_at_position(gCurrentSprite.y_position + 0x40, gCurrentSprite.x_position) == 0x11 ||
            sprite_util_get_collision_at_position(gCurrentSprite.y_position + 0x40, gCurrentSprite.x_position - 0x30) == 0x11 ||
            sprite_util_get_collision_at_position(gCurrentSprite.y_position + 0x40, gCurrentSprite.x_position + 0x30) == 0x11)
            return TRUE;
        gCurrentSprite.y_position += movement;
    }
    else
    {
        if (sprite_util_get_collision_at_position(gCurrentSprite.y_position - 0x28, gCurrentSprite.x_position - 0x30) == 0x11 &&
            sprite_util_get_collision_at_position(gCurrentSprite.y_position - 0x28, gCurrentSprite.x_position - 0x70) == 0x11)
            return TRUE;

        if (sprite_util_get_collision_at_position(gCurrentSprite.y_position - 0x28, gCurrentSprite.x_position + 0x30) == 0x11 &&
            sprite_util_get_collision_at_position(gCurrentSprite.y_position - 0x28, gCurrentSprite.x_position + 0x70) == 0x11)
            return TRUE;

        gCurrentSprite.y_position -= movement;
    }

    return FALSE;
}

u8 geruta_x_movement(u16 movement)
{
    register u16 movement_;

    movement_ = movement;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (sprite_util_get_collision_at_position(gCurrentSprite.y_position - 0x20, gCurrentSprite.x_position + 0x40) == 0x11 || sprite_util_get_collision_at_position(gCurrentSprite.y_position + 0x20, gCurrentSprite.x_position + 0x40) == 0x11)
            return TRUE;
        gCurrentSprite.x_position += movement;
    }
    else
    {
        if (sprite_util_get_collision_at_position(gCurrentSprite.y_position - 0x20, gCurrentSprite.x_position - 0x40) == 0x11 || sprite_util_get_collision_at_position(gCurrentSprite.y_position + 0x20, gCurrentSprite.x_position - 0x40) == 0x11)
            return TRUE;
        gCurrentSprite.x_position -= movement_;
    }
    
    return FALSE;
}

void geruta_init(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    sprite_util_make_sprite_face_samus_direction();
    gCurrentSprite.draw_distance_top_offset = 0x18;
    gCurrentSprite.draw_distance_bottom_offset = 0x18;
    gCurrentSprite.draw_distance_horizontal_offset = 0x18;
    gCurrentSprite.hitbox_top_offset = -0x20;
    gCurrentSprite.hitbox_bottom_offset = 0x20;
    gCurrentSprite.hitbox_left_offset = -0x30;
    gCurrentSprite.hitbox_right_offset = 0x30;
    gCurrentSprite.oam_pointer = geruta_oam_2d1400;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    gCurrentSprite.samus_collision = SSC_HURTS_SAMUS;
    gCurrentSprite.y_position -= 0xC;
    gCurrentSprite.pose = 0x8;
}

void geruta_gfx_init(void)
{
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.oam_pointer = geruta_oam_2d1400;
}

void geruta_detect_samus(void)
{
    u8 nslr;

    if (sprite_util_get_collision_at_position(gCurrentSprite.y_position - 0x40, gCurrentSprite.x_position - 0x30) != 0x11 && sprite_util_get_collision_at_position(gCurrentSprite.y_position - 0x40, gCurrentSprite.x_position + 0x30) != 0x11)
        sprite_util_make_sprite_face_samus_direction();
    else
    {
        if ((gSamusData.y_position - 0x48) >= gCurrentSprite.y_position)
        {
            nslr = sprite_util_check_samus_near_sprite_left_right(0x140, 0x140);
            if (nslr != NSLR_RIGHT && nslr != NSLR_LEFT)
                return;
            gCurrentSprite.pose = 0x32;
            return;
        }
        else
            return;
    }

    gCurrentSprite.pose = 0x32;
}

void geruta_go_down_gfx_init(void)
{
    gCurrentSprite.pose = 0x33;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.oam_pointer = geruta_oam_2d1418;
    if ((gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
        SoundPlay(0x150);
}

void geruta_check_warning_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        gCurrentSprite.pose = 0x35;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.oam_pointer = geruta_oam_2d1438;
    }
}

void geruta_check_going_down_anim_ended(void)
{
    if (sprite_util_check_end_sprite_anim())
    {
        gCurrentSprite.pose = 0x37;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.oam_pointer = geruta_oam_2d1460;
        gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
        sprite_util_make_sprite_face_samus_direction();
        if ((gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
            unk_2b20(0x14E);
    }
}

void geruta_going_down(void)
{
    u16 old_y;

    old_y = gCurrentSprite.y_position;
    geruta_x_movement(0x4);
    if (geruta_y_movement(0xC) << 0x18)
    {
        gCurrentSprite.pose = 0x39;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.oam_pointer = geruta_oam_2d1488;
    }

    sprite_util_check_in_room_effect(old_y, gCurrentSprite.y_position, gCurrentSprite.x_position, SPLASH_BIG);
}

void geruta_check_bouncing_anim_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        gCurrentSprite.pose = 0x3B;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.oam_pointer = geruta_oam_2d14a0;
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        if ((gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
            unk_2b20(0x14F);
    }
}

void geruta_going_up(void)
{
    geruta_x_movement(0x4);
    if (geruta_y_movement(0xC) << 0x18)
    {
        gCurrentSprite.y_position = (gCurrentSprite.y_position & 0xFFC0);
        gCurrentSprite.y_position  += 0x34;
        gCurrentSprite.pose = 0x3D;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.oam_pointer = geruta_oam_2d14c8;
    }
}

void geruta_check_reset_anim_ended(void)
{
    if (sprite_util_check_near_end_sprite_anim())
        gCurrentSprite.pose = 0x8;
}

void geruta(void)
{
    if ((gCurrentSprite.properties & SP_UNKNOWN) != 0x0)
    {
        gCurrentSprite.properties &= ~SP_UNKNOWN;
        if ((gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
            unk_2b20(0x151);
    }

    if (gCurrentSprite.freeze_timer != 0x0)
        sprite_util_update_freeze_timer();
    else
    {
        if (!sprite_util_is_sprite_stunned())
        {
            switch (gCurrentSprite.pose)
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
                    sprite_util_sprite_death(DEATH_NORMAL, gCurrentSprite.y_position, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
        }
    }
}