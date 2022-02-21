#include "multiviola.h"
#include "../sprite_util.h"
#include "../globals.h"

void multiviola_init(void)
{
    current_sprite.draw_distance_top_offset = 0x20;
    current_sprite.draw_distance_bottom_offset = 0xC;
    current_sprite.draw_distance_horizontal_offset = 0x10;
    current_sprite.hitbox_top_offset = -0x20;
    current_sprite.hitbox_bottom_offset = 0x20;
    current_sprite.hitbox_left_offset = -0x20;
    current_sprite.hitbox_right_offset = 0x20;
    current_sprite.oam_pointer = multiviola_oam_2d0520;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = current_sprite.primary_sprite_ram_slot << 0x1;
    current_sprite.health = primary_sprite_stats_2b0d68[current_sprite.sprite_id][0x0];
    current_sprite.samus_collision = SSC_HURTS_SAMUS;
    sprite_util_make_sprite_face_samus_x_flip();
    current_sprite.pose = 0x9;
}

void multiviola_move(void)
{
    u8 is_bouncing;
    u16 y_movement;

    is_bouncing = 0x0;
    y_movement = 0x3;

    if ((current_sprite.status & SPRITE_STATUS_XFLIP) != 0x0)
    {
        sprite_util_check_collision_at_position(current_sprite.y_position, current_sprite.hitbox_right_offset + current_sprite.x_position);
        if (previous_collision_check == 0x0)
            current_sprite.x_position += 0x3;
        else
        {
            current_sprite.status &= ~SPRITE_STATUS_XFLIP;
            is_bouncing = 0x1;
        }
    }
    else
    {
        sprite_util_check_collision_at_position(current_sprite.y_position, current_sprite.hitbox_left_offset + current_sprite.x_position);
        if (previous_collision_check == 0x0)
            current_sprite.x_position -= 0x3;
        else
        {
            current_sprite.status |= SPRITE_STATUS_XFLIP;
            is_bouncing = 0x1;
        }
    }

    if ((current_sprite.status & SPRITE_STATUS_ON_VERTICAL_WALL) != 0x0)
    {
        sprite_util_check_collision_at_position(current_sprite.hitbox_top_offset + current_sprite.y_position, current_sprite.x_position);
        if (previous_collision_check == 0x0)
            current_sprite.y_position -= y_movement;
        else
        {
            current_sprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
            is_bouncing++;
        }
    }
    else
    {
        sprite_util_check_collision_at_position(current_sprite.hitbox_bottom_offset + current_sprite.y_position, current_sprite.x_position);
        if (previous_collision_check == 0x0)
            current_sprite.y_position += y_movement;
        else
        {
            current_sprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
            is_bouncing++;
        }
    }

    if (is_bouncing != 0x0 && (current_sprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
        unk_2b20(0x152);
}

void multiviola_unused_empty1(void)
{
    return;
}

void multiviola_unused_empty2(void)
{
    return;
}

void multiviola(void)
{
    if ((current_sprite.properties & SP_UNKNOWN) != 0x0)
    {
        current_sprite.properties &= ~SP_UNKNOWN;
        if ((current_sprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
            unk_2b20(0x153);
    }

    if (current_sprite.freeze_timer != 0x0)
    {
        sprite_util_update_freeze_timer();
        sprite_util_update_secondary_sprite_freeze_timer_of_current(SSPRITE_MULTIVIOLA_UNUSED, current_sprite.primary_sprite_ram_slot);
    }
    else
    {
        if (!sprite_util_is_sprite_stunned())
        {
            switch (current_sprite.pose)
            {
                default:
                    sprite_util_sprite_death(DEATH_NORMAL, current_sprite.y_position, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_BIG);
                    break;
                case 0x0:
                    multiviola_init();
                    break;
                case 0x9:
                    multiviola_move();
            }
        }
    }
}

void multiviola_unused(void)
{
    return;
}