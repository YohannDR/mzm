#include "water_drop.h"
#include "../sprite_util.h"
#include "../globals.h"

void water_drop_init(void)
{
    current_sprite.hitbox_top_offset = -0x4;
    current_sprite.hitbox_bottom_offset = 0x4;
    current_sprite.hitbox_left_offset = -0x4;
    current_sprite.hitbox_right_offset = 0x4;
    current_sprite.samus_collision = SSC_NONE;
    current_sprite.draw_order = 0x1;
    current_sprite.anim_duration_counter = 0x0;
}

void water_drop(void)
{
    u16 offset;
    u32 block;

    current_sprite.ignore_samus_collision_timer = 0x1;

    switch (current_sprite.pose)
    {
        case 0x0:
            water_drop_init();
            current_sprite.y_position -= 0x40;
            current_sprite.draw_distance_top_offset = 0x8;
            current_sprite.draw_distance_bottom_offset = 0x8;
            current_sprite.draw_distance_horizontal_offset = 0x8;
            current_sprite.curr_anim_frame = 0x0;
            current_sprite.oam_pointer = water_drop_oam_data_33bc54;
            current_sprite.y_position_spawn = current_sprite.y_position;
            current_sprite.x_position_spawn = current_sprite.x_position;
            current_sprite.status |= SPRITE_STATUS_NOT_DRAWN;
            current_sprite.pose = 0x11;
            current_sprite.timer1 = sprite_rng << 0x3;
            break;

        case 0x9:
            if (sprite_util_check_end_current_sprite_anim() != FALSE)
            {
                current_sprite.oam_pointer = water_drop_oam_falling_33bc94;
                current_sprite.curr_anim_frame = 0x0;
                current_sprite.anim_duration_counter = 0x0;
                current_sprite.timer2 = 0x0;
                current_sprite.array_offset = 0x0;
                current_sprite.pose = 0x1F;
            }
            break;

        case 0x1F:
            block = sprite_util_check_vertical_collision_at_position_slopes(current_sprite.y_position, current_sprite.x_position);
            if (current_affecting_clipdata.hazard == HAZARD_TYPE_WATER)
            {
                if (effect_y_position != 0x0)
                {
                    current_sprite.y_position = effect_y_position;
                    current_sprite.timer2 = 0x1;
                }
                else
                    current_sprite.y_position = block;
                current_sprite.pose = 0xE;
            }
            else
            {
                if (previous_vertical_collision_check != 0x0)
                {
                    current_sprite.y_position = block;
                    current_sprite.pose = 0xE;
                }
                else
                {
                    offset = current_sprite.array_offset;
                    if (sprites_falling_speed_2b0d04[offset] == 0x7FFF)
                        current_sprite.y_position += (i16)sprites_falling_speed_2b0d04[offset - 0x1];
                    else
                    {
                        current_sprite.array_offset++;
                        current_sprite.y_position += sprites_falling_speed_2b0d04[offset];
                    }
                }
            }
            break;

        case 0xE:
            current_sprite.oam_pointer = water_drop_oam_splashing_33bca4;
            current_sprite.curr_anim_frame = 0x0;
            current_sprite.anim_duration_counter = 0x0;
            current_sprite.pose = 0xF;

        case 0xF:
            if (current_sprite.timer2 != 0x0)
                current_sprite.y_position = effect_y_position;

            if (sprite_util_check_end_current_sprite_anim() != FALSE)
            {
                current_sprite.status |= SPRITE_STATUS_NOT_DRAWN;
                current_sprite.pose = 0x11;
                current_sprite.timer1 = (sprite_rng << 0x3) + 0x64;
            }
            break;

        case 0x11:
            current_sprite.timer1--;
            if ((u8)current_sprite.timer1 == 0x0)
            {
                current_sprite.oam_pointer = water_drop_oam_data_33bc54;
                current_sprite.curr_anim_frame = 0x0;
                current_sprite.anim_duration_counter = 0x0;
                current_sprite.pose = 0x9;
                current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                current_sprite.y_position = current_sprite.y_position_spawn;
                current_sprite.x_position = current_sprite.x_position_spawn;
                if ((sprite_rng & 0x1) != 0x0)
                    current_sprite.x_position = current_sprite.x_position_spawn + ((i32)(sprite_rng + 0x1) / 0x2);
                else
                    current_sprite.x_position = current_sprite.x_position_spawn - ((i32)(sprite_rng + 0x1) / 0x2);
            }
    }
}