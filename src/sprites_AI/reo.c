#include "reo.h"
#include "../sprite_util.h"
#include "../globals.h"

void reo_init(void)
{
    current_sprite.draw_distance_top_offset = 0x18;
    current_sprite.draw_distance_bottom_offset = 0x18;
    current_sprite.draw_distance_horizontal_offset = 0x18;
    current_sprite.hitbox_top_offset = -0x20;
    current_sprite.hitbox_bottom_offset = 0x20;
    current_sprite.hitbox_left_offset = -0x38;
    current_sprite.hitbox_right_offset = 0x38;
    current_sprite.oam_pointer = reo_oam_2ce214;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.health = primary_sprite_stats_2b0d68[current_sprite.sprite_id][0x0];
    current_sprite.samus_collision = SSC_HURTS_SAMUS;
    sprite_util_choose_random_x_direction();
    if (0x8 < sprite_rng)
        current_sprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
    current_sprite.pose = 0x8;
}

void reo_rng(void)
{
    current_sprite.pose = 0x9;
    current_sprite.work_variable = (sprite_rng << 0x1A) >> 0x18;
    current_sprite.array_offset = current_sprite.work_variable;
}

void reo_samus_detection(void)
{
    i16 movement;
    u8 offset;

    offset = current_sprite.array_offset;
    movement = reo_idle_anim_y_position_offsets[offset];
    if (movement == 0x7FFF)
    {
        movement = reo_idle_anim_y_position_offsets[0x0];
        offset = 0x0;
    }
    current_sprite.array_offset = offset + 0x1;
    current_sprite.y_position += movement;
    
    offset = current_sprite.work_variable;
    movement = reo_idle_anim_x_position_offsets[offset];
    if (movement == 0x7FFF)
    {
        movement = reo_idle_anim_x_position_offsets[0x0];
        offset = 0x0;
    }
    current_sprite.work_variable = offset + 0x1;
    current_sprite.x_position += movement;

    if (sprite_util_check_samus_near_sprite_left_right(0x200, 0x1C0) != NSLR_OUT_OF_RANGE)
        current_sprite.pose = 0x22;
}

void reo_samus_detected(void)
{

}

void reo_move(void)
{

}

void reo(void)
{
    if (current_sprite.properties & SP_UNKNOWN)
    {
        current_sprite.properties &= ~SP_UNKNOWN;
        if (current_sprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x159);
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
                    reo_init();
                    break;
                case 0x8:
                    reo_rng();
                    break;
                case 0x9:
                    reo_samus_detection();
                    break;
                case 0x22:
                    reo_samus_detected();
                case 0x23:
                    reo_move();
                    break;
                default:
                    sprite_util_sprite_death(DEATH_NORMAL, current_sprite.y_position, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_BIG);
            }
        }
    }
}