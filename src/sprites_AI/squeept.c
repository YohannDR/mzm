#include "squeept.h"
#include "../sprite_util.h"
#include "../globals.h"

void squeept_gfx_reset(void)
{
    current_sprite.hitbox_top_offset = -0x2C;
    current_sprite.hitbox_bottom_offset = 0x20;
    current_sprite.oam_pointer = squeept_oam_2d1be0;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
}

void squeept_turning_around_gfx_init(void)
{
    current_sprite.hitbox_top_offset = -0x20;
    current_sprite.hitbox_bottom_offset = 0x20;
    current_sprite.oam_pointer = squeept_oam_2d1b68;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
}

void squeept_going_down_gfx_init(void)
{
    current_sprite.hitbox_top_offset = 0x0;
    current_sprite.hitbox_bottom_offset = 0x28;
    current_sprite.oam_pointer = squeept_oam_2d1bc8;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
}

void squeept_init(void)
{
    current_sprite.draw_distance_top_offset = 0x14;
    current_sprite.draw_distance_bottom_offset = 0x14;
    current_sprite.draw_distance_horizontal_offset = 0x10;
    current_sprite.hitbox_left_offset = -0x20;
    current_sprite.hitbox_right_offset = 0x20;
    current_sprite.samus_collision = SSC_HURTS_SAMUS;
    current_sprite.health = primary_sprite_stats_2b0d68[current_sprite.sprite_id][0x0];
    current_sprite.y_position += 0x4;
    current_sprite.y_position_spawn = current_sprite.y_position;
}

void squeept_reset(void)
{
    current_sprite.status |= SPRITE_STATUS_NOT_DRAWN;
    current_sprite.pose = 0xF;
    squeept_gfx_reset();
    current_sprite.timer1 = 0x1E;
}

void squeept_detect_samus(void)
{
    u32 timer;
    enum near_sprite_above_below nsab;

    timer = current_sprite.timer1;
    if (timer != 0x0)
        current_sprite.timer1--;
    else
    {
        nsab = sprite_util_check_samus_near_sprite_above_below(0x200, 0x180);
        if (nsab == NSAB_ABOVE)
        {
            current_sprite.pose = 0x35;
            current_sprite.array_offset = timer;
            current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        }
    }
}

void squeept_go_up(void)
{

}

void squeept_turn_around(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        squeept_going_down_gfx_init();
        current_sprite.pose = 0x39;
        current_sprite.array_offset = 0x0;
    }
}

void squeept_go_down(void)
{
    u16 old_y;
    u8 offset;
    i16 velocity;

    old_y = current_sprite.y_position;
    offset = current_sprite.array_offset;
    velocity = squeept_falling_speed_2d1562[offset];
    if (velocity == 0x7FFF)
        current_sprite.y_position += squeept_falling_speed_2d1562[offset - 0x1];
    else
    {
        current_sprite.array_offset = offset + 0x1;
        current_sprite.y_position += velocity;
    }

    if (sprite_util_check_in_room_effect(old_y, current_sprite.y_position, current_sprite.x_position, SPLASH_BIG) && current_sprite.status & SPRITE_STATUS_ONSCREEN)
        play_sound1(0x156);

    if (current_sprite.y_position_spawn < current_sprite.y_position)
    {
        current_sprite.y_position = current_sprite.y_position_spawn;
        squeept_reset();
    }
}

void squeept(void)
{
    if (current_sprite.properties & SP_UNKNOWN)
    {
        current_sprite.properties &= ~SP_UNKNOWN;
        if (current_sprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x157);
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
                    squeept_init();
                case 0xE:
                    squeept_reset();
                case 0xF:
                    squeept_detect_samus();
                    break;
                case 0x35:
                    squeept_go_up();
                    break;
                case 0x37:
                    squeept_turn_around();
                    break;
                case 0x39:
                    squeept_go_down();
                    break;
                default:
                    sprite_util_sprite_death(DEATH_NORMAL, current_sprite.y_position, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
        }
    }
}