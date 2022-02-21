#include "zeb.h"
#include "../sprite_util.h"
#include "../globals.h"

void zeb_init(void)
{
    current_sprite.hitbox_top_offset = -0x8;
    current_sprite.hitbox_bottom_offset = 0x14;
    current_sprite.hitbox_left_offset = -0x1C;
    current_sprite.hitbox_right_offset = 0x1C;
    current_sprite.draw_distance_top_offset = 0x8;
    current_sprite.draw_distance_bottom_offset = 0x8;
    current_sprite.draw_distance_horizontal_offset = 0x10;
    current_sprite.timer2 = 0x1;
    current_sprite.health = primary_sprite_stats_2b0d68[current_sprite.sprite_id][0x0];
    current_sprite.y_position -= 0x20;
    current_sprite.x_position += 0x20;
    current_sprite.y_position_spawn = current_sprite.y_position;
    current_sprite.x_position_spawn = current_sprite.x_position;
}

void zeb_gfx_init(void)
{
    current_sprite.samus_collision = SSC_NONE;
    current_sprite.pose = 0x9;
    current_sprite.oam_pointer = zeb_oam_2cca2c;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
    current_sprite.bg_priority = 0x2;
}

void zeb_check_spawn(void)
{
    u16 samus_x;
    u16 samus_y;
    u16 sprite_x;
    u16 sprite_y;
    i32 offset;

    if (!sprite_util_check_has_drop())
    {
        if (current_sprite.timer2 != 0x0)
            current_sprite.timer2--;
        else
        {
            samus_y = samus_data.y_position;
            samus_x = samus_data.x_position;
            sprite_y = current_sprite.y_position;
            sprite_x = current_sprite.x_position;

            if (samus_y <= (sprite_y - 0x1E))
            {
                if (sprite_x >= samus_x)
                    offset = samus_x - sprite_x;
                else
                    offset = sprite_x - samus_x;
                
                if (offset > 0x24 && sprite_util_check_samus_near_sprite_above_below(0x140, 0x140) == NSAB_ABOVE)
                {
                    current_sprite.oam_scaling = samus_data.y_position;
                    current_sprite.pose = 0x23;
                    current_sprite.timer1 = 0x2;
                    current_sprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
                    sprite_util_make_sprite_face_samus_x_flip();
                    if (current_sprite.status & SPRITE_STATUS_ONSCREEN)
                        play_sound1(0x144);
                }
            }
        }
    }
}

void zeb_going_up(void)
{
    u16 y_position;

    current_sprite.y_position -= 0x8;
    if (current_sprite.timer1 != 0x0)
    {
        current_sprite.timer1--;
        if (current_sprite.timer1 == 0x0)
            current_sprite.samus_collision = SSC_HURTS_SAMUS;
    }
    else
    {
        if (current_sprite.oam_scaling < samus_data.y_position && samus_data.y_position >= (i32)(current_sprite.y_position_spawn - 0x80))
            y_position = current_sprite.oam_scaling;
        else
            y_position = samus_data.y_position;

        if ((y_position - 0x64) > current_sprite.y_position)
        {
            current_sprite.pose = 0x25;
            current_sprite.timer1 = 0xA;
            current_sprite.oam_pointer = zeb_oam_2cca54;
            current_sprite.curr_anim_frame = 0x0;
            current_sprite.anim_duration_counter = 0x0;
            current_sprite.bg_priority = 0x1;
        }
    }
}

void zeb_reset(void)
{
    current_sprite.y_position = current_sprite.y_position_spawn;
    current_sprite.x_position = current_sprite.x_position_spawn;
    zeb_gfx_init();
    current_sprite.timer2 = 0x3C;
    current_sprite.health = primary_sprite_stats_2b0d68[current_sprite.sprite_id][0x0];
    current_sprite.invicibility_stun_flash_timer = 0x0;
    current_sprite.palette_row = 0x0;
    current_sprite.frozen_palette_row_offset = 0x0;
    current_sprite.maybe_absolute_palette_row = 0x0;
    current_sprite.ignore_samus_collision_timer = 0x1;
    current_sprite.freeze_timer = 0x0;
}

void zeb_move(void)
{
    u8 timer;

    if (current_sprite.timer1 != 0x0)
    {
        if (timer = current_sprite.timer1 -= 0x1 == 0x0)
        {
            if (current_sprite.status & SPRITE_STATUS_ONSCREEN)
                play_sound(0x145);
            current_sprite.timer2 = timer;
        }
    }
    else
    {
        current_sprite.timer2++;
        if (current_sprite.status & SPRITE_STATUS_XFLIP)
        {
            if ((i32)(current_sprite.x_position - samus_data.x_position) > 0x400 || current_sprite.x_position & 0x8000)
            {
                zeb_reset();
                return;
            }
            current_sprite.x_position += 0xC;
        }
        else
        {
            if ((i32)(samus_data.x_position - current_sprite.x_position) > 0x400 || current_sprite.x_position & 0x8000)
            {
                zeb_reset();
                return;
            }
            current_sprite.x_position -= 0xC;
        }
        if ((current_sprite.timer2 & 0xF) == 0x0 && current_sprite.status & SPRITE_STATUS_ONSCREEN)
            play_sound1(0x145);
    }
}

void zeb(void)
{
    if (current_sprite.properties & SP_UNKNOWN)
    {
        current_sprite.properties &= ~SP_UNKNOWN;
        if (current_sprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x146);
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
                    zeb_init();
                case 0x8:
                    zeb_gfx_init();
                case 0x9:
                    zeb_check_spawn();
                    break;
                case 0x23:
                    zeb_going_up();
                    break;
                case 0x25:
                    zeb_move();
                    break;
                default:
                    sprite_util_sprite_death(DEATH_RESPAWNING, current_sprite.y_position, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                    zeb_reset();
            }
        }
    }
}