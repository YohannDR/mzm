#include "squeept.h"
#include "../sprite_util.h"
#include "../globals.h"

void squeept_gfx_reset(void)
{
    gCurrentSprite.hitbox_top_offset = -0x2C;
    gCurrentSprite.hitbox_bottom_offset = 0x20;
    gCurrentSprite.oam_pointer = squeept_oam_2d1be0;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
}

void squeept_turning_around_gfx_init(void)
{
    gCurrentSprite.hitbox_top_offset = -0x20;
    gCurrentSprite.hitbox_bottom_offset = 0x20;
    gCurrentSprite.oam_pointer = squeept_oam_2d1b68;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
}

void squeept_going_down_gfx_init(void)
{
    gCurrentSprite.hitbox_top_offset = 0x0;
    gCurrentSprite.hitbox_bottom_offset = 0x28;
    gCurrentSprite.oam_pointer = squeept_oam_2d1bc8;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
}

void squeept_init(void)
{
    gCurrentSprite.draw_distance_top_offset = 0x14;
    gCurrentSprite.draw_distance_bottom_offset = 0x14;
    gCurrentSprite.draw_distance_horizontal_offset = 0x10;
    gCurrentSprite.hitbox_left_offset = -0x20;
    gCurrentSprite.hitbox_right_offset = 0x20;
    gCurrentSprite.samus_collision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    gCurrentSprite.y_position += 0x4;
    gCurrentSprite.y_position_spawn = gCurrentSprite.y_position;
}

void squeept_reset(void)
{
    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.pose = 0xF;
    squeept_gfx_reset();
    gCurrentSprite.timer1 = 0x1E;
}

void squeept_detect_samus(void)
{
    u32 timer;
    u8 nsab;

    timer = gCurrentSprite.timer1;
    if (timer != 0x0)
        gCurrentSprite.timer1--;
    else
    {
        nsab = sprite_util_check_samus_near_sprite_above_below(0x200, 0x180);
        if (nsab == NSAB_ABOVE)
        {
            gCurrentSprite.pose = 0x35;
            gCurrentSprite.array_offset = timer;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
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
        gCurrentSprite.pose = 0x39;
        gCurrentSprite.array_offset = 0x0;
    }
}

void squeept_go_down(void)
{
    u16 old_y;
    u8 offset;
    i16 velocity;

    old_y = gCurrentSprite.y_position;
    offset = gCurrentSprite.array_offset;
    velocity = squeept_falling_speed_2d1562[offset];
    if (velocity == 0x7FFF)
        gCurrentSprite.y_position += squeept_falling_speed_2d1562[offset - 0x1];
    else
    {
        gCurrentSprite.array_offset = offset + 0x1;
        gCurrentSprite.y_position += velocity;
    }

    if (sprite_util_check_in_room_effect(old_y, gCurrentSprite.y_position, gCurrentSprite.x_position, SPLASH_BIG) && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(0x156);

    if (gCurrentSprite.y_position_spawn < gCurrentSprite.y_position)
    {
        gCurrentSprite.y_position = gCurrentSprite.y_position_spawn;
        squeept_reset();
    }
}

void squeept(void)
{
    if (gCurrentSprite.properties & SP_UNKNOWN)
    {
        gCurrentSprite.properties &= ~SP_UNKNOWN;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x157);
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
                    sprite_util_sprite_death(DEATH_NORMAL, gCurrentSprite.y_position, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
        }
    }
}