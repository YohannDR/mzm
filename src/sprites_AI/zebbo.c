#include "zebbo.h"
#include "../sprite_util.h"
#include "../sprite.h"
#include "../globals.h"

void zebbo_init(void)
{
    current_sprite.hitbox_top_offset = -0x18;
    current_sprite.hitbox_bottom_offset = 0x18;
    current_sprite.hitbox_left_offset = -0x18;
    current_sprite.hitbox_right_offset = 0x18;
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

void zebbo_gfx_init(void)
{
    current_sprite.samus_collision = SSC_NONE;
    current_sprite.pose = 0x9;
    current_sprite.oam_pointer = zebbo_oam_2e7098;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
    current_sprite.bg_priority = 0x2;
}

void zebbo_spawn(void)
{

}

void zebbo_going_up(void)
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
        if (current_sprite.oam_scaling < samus_data.y_position && samus_data.y_position > (i32)(current_sprite.y_position_spawn - 0x80))
            y_position = current_sprite.oam_scaling;
        else
            y_position = samus_data.y_position;

        if ((i32)(y_position - 0x64) > current_sprite.y_position)
        {
            current_sprite.pose = 0x35;
            current_sprite.timer1 = 0xA;
            current_sprite.oam_pointer = zebbo_oam_2e70c0;
            current_sprite.curr_anim_frame = 0x0;
            current_sprite.anim_duration_counter = 0x0;
            current_sprite.bg_priority = 0x1;
        }
    }
}

void zebbo_respawning(void)
{
    if (current_sprite.sprite_id == PSPRITE_ZEBBO_GREEN_FOLLOWER)
        current_sprite.status = 0x0;
    else
    {
        current_sprite.y_position = current_sprite.y_position_spawn;
        current_sprite.x_position = current_sprite.x_position_spawn;
        zebbo_gfx_init();
        current_sprite.timer2 = 0x3C;
        current_sprite.health = primary_sprite_stats_2b0d68[current_sprite.sprite_id][0x0];
        current_sprite.invicibility_stun_flash_timer = 0x0;
        current_sprite.palette_row = 0x0;
        current_sprite.frozen_palette_row_offset = 0x0;
        current_sprite.maybe_absolute_palette_row = 0x0;
        current_sprite.ignore_samus_collision_timer = 0x1;
        current_sprite.freeze_timer = 0x0;
    }
}

void zebbo_move(void)
{

}

void zebbo(void)
{
    if (current_sprite.properties & SP_UNKNOWN)
    {
        current_sprite.properties &= ~SP_UNKNOWN;
        if (current_sprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x164);
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
                    zebbo_init();
                case 0x8:
                    zebbo_gfx_init();
                case 0x9:
                    zebbo_spawn();
                    break;
                case 0x23:
                    zebbo_going_up();
                    break;
                case 0x25:
                    zebbo_move();
                    break;
                default:
                    sprite_util_sprite_death(DEATH_RESPAWNING, current_sprite.y_position, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                    zebbo_respawning();
            }
        }
    }
}