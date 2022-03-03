#include "explosion_zebes_escape.h"
#include "screen_shake.h"
#include "particle.h"
#include "sprite_debris.h"
#include "globals.h"

void explosion_zebes_escape(void)
{
    u32 rng;
    u32 rng_;
    u32 x_position;
    u32 y_position;
    u8 array_offset;
    u8 variable;
    u32 y_offset;
    u32 x_offset;

    if (current_sprite.pose == 0x0)
    {
        current_sprite.status |= SPRITE_STATUS_NOT_DRAWN;
        current_sprite.draw_distance_top_offset = 0x1;
        current_sprite.draw_distance_bottom_offset = 0x1;
        current_sprite.draw_distance_horizontal_offset = 0x1;
        current_sprite.hitbox_top_offset = 0x0;
        current_sprite.hitbox_bottom_offset = 0x0;
        current_sprite.hitbox_left_offset = 0x0;
        current_sprite.hitbox_right_offset = 0x0;
        current_sprite.samus_collision = SSC_NONE;
        current_sprite.oam_pointer = large_energy_oam_data_2b2750;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.pose = 0x9;
        current_sprite.array_offset = 0x7;
        current_sprite.work_variable = 0x0;
        current_sprite.y_position_spawn = current_sprite.y_position;
        current_sprite.x_position_spawn = current_sprite.x_position;
        return;
    }

    y_position = current_sprite.y_position_spawn;
    x_position = (u16)(bg1_x_position + 0x1E0);
    rng = sprite_rng;
    rng_ = rng & 0x3;
    array_offset = current_sprite.array_offset;
    current_sprite.array_offset++;
    variable = current_sprite.work_variable;
    current_sprite.work_variable++;

    y_position = current_sprite.y_position_spawn;
    if (samus_data.y_position < (current_sprite.y_position_spawn - 0xA0))
        y_position = (u16)(samus_data.y_position + 0x64);

    if ((array_offset & 0xF) == 0x0 && rng >= 0x8)
    {
        if ((array_offset & 0x10) != 0x0)
        {
            if (rng >= 0xC)
            {
                if ((rng & 0x1) != 0x0)
                {
                    y_position += (rng * 0x8) - 0xE6;
                    x_position += (rng << rng_);
                    particle_set(y_position, x_position, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                    unk_2b20(0x276);
                }
                else
                {
                    y_position += (rng * 0x8) - 0xDC;
                    x_position += (rng << rng_) + 0xA0;
                    particle_set(y_position, x_position, PE_SPRITE_EXPLOSION_HUGE);
                    unk_2b20(0xA4);
                }
            }
            else
            {
                if ((rng & 0x1) != 0x0)
                {
                    y_position += (rng * 0x8) - 0xDC;
                    x_position -= (rng << rng_);
                    particle_set(y_position, x_position, PE_SPRITE_EXPLOSION_HUGE);
                    unk_2b20(0xA4);
                }
                else
                {
                    y_position += (rng * 0x8) - 0xE6;
                    x_position -= (rng << rng_) + 0xA0;
                    particle_set(y_position, x_position, PE_SPRITE_EXPLOSION_BIG);
                    unk_2b20(0x276);
                }
            }
        }
        else
        {
            screen_shake_start_vertical(0xA, 0x81);
            screen_shake_start_horizontal(0xA, 0x81);
            if (rng >= 0xC)
            {
                if ((rng & 0x1) != 0x0)
                {
                    particle_set(y_position + (rng * 0x10 - 0x140), x_position + rng << rng_, PE_TWO_MEDIUM_DUST);
                    unk_2b20(0xA5);
                }
                else
                {
                    y_offset = (rng * 0x10) - 0x118;
                    x_offset = rng << rng_;
                }
            }
            else
            {
                y_offset = (rng * 0x10) - 0x168;
                x_offset = (rng << rng_) + 0xC0;
            }

            particle_set(y_position + y_offset, x_position + x_offset, PE_MEDIUM_DUST);
            unk_2b20(0x277);
        }
    }

    y_position = (u16)(bg1_y_position - 0x40);
    if ((variable & 0x1F) == 0x0)
    {
        if ((variable & 0x20) != 0x0)
        {
            sprite_debris_init(0x0, 0x5, y_position, x_position - (rng * 0x10) - 0x78);
            sprite_debris_init(0x0, 0x8, y_position, x_position + (rng * 0x8) - 0x190);
        }
        else
        {
            sprite_debris_init(0x0, 0x7, y_position, x_position - (rng * 0x10) - 0x78);
            sprite_debris_init(0x0, 0x5, y_position, x_position + (rng * 0x8) - 0x12C);
        }
    }

    if ((array_offset & 0xF) == 0x0)
    {
        if (rng >= 0x8)
        {
            sprite_debris_init(0x0, 0x8, y_position, x_position + (rng * 0x20) - 0x1C2);
            sprite_debris_init(0x0, 0x6, y_position, x_position - (rng * 0x20) - 0x24E);
        }
        else
        {
            sprite_debris_init(0x0, 0x6, y_position, x_position - (rng * 0x20) - 0x17C);
            sprite_debris_init(0x0, 0x8, y_position, x_position + (rng * 0x8) - 0x278);
        }
    }
}