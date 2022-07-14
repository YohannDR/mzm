#include "zebbo.h"
#include "../sprite_util.h"
#include "../sprite.h"
#include "../globals.h"

void zebbo_init(void)
{
    gCurrentSprite.hitbox_top_offset = -0x18;
    gCurrentSprite.hitbox_bottom_offset = 0x18;
    gCurrentSprite.hitbox_left_offset = -0x18;
    gCurrentSprite.hitbox_right_offset = 0x18;
    gCurrentSprite.draw_distance_top_offset = 0x8;
    gCurrentSprite.draw_distance_bottom_offset = 0x8;
    gCurrentSprite.draw_distance_horizontal_offset = 0x10;
    gCurrentSprite.timer2 = 0x1;
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    gCurrentSprite.y_position -= 0x20;
    gCurrentSprite.x_position += 0x20;
    gCurrentSprite.y_position_spawn = gCurrentSprite.y_position;
    gCurrentSprite.x_position_spawn = gCurrentSprite.x_position;
}

void zebbo_gfx_init(void)
{
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.oam_pointer = zebbo_oam_2e7098;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
    gCurrentSprite.bg_priority = 0x2;
}

void zebbo_spawn(void)
{

}

void zebbo_going_up(void)
{
    u16 y_position;

    gCurrentSprite.y_position -= 0x8;
    if (gCurrentSprite.timer1 != 0x0)
    {
        gCurrentSprite.timer1--;
        if (gCurrentSprite.timer1 == 0x0)
            gCurrentSprite.samus_collision = SSC_HURTS_SAMUS;
    }
    else
    {
        if (gCurrentSprite.oam_scaling < gSamusData.y_position && gSamusData.y_position > (i32)(gCurrentSprite.y_position_spawn - 0x80))
            y_position = gCurrentSprite.oam_scaling;
        else
            y_position = gSamusData.y_position;

        if ((i32)(y_position - 0x64) > gCurrentSprite.y_position)
        {
            gCurrentSprite.pose = 0x35;
            gCurrentSprite.timer1 = 0xA;
            gCurrentSprite.oam_pointer = zebbo_oam_2e70c0;
            gCurrentSprite.curr_anim_frame = 0x0;
            gCurrentSprite.anim_duration_counter = 0x0;
            gCurrentSprite.bg_priority = 0x1;
        }
    }
}

void zebbo_respawning(void)
{
    if (gCurrentSprite.sprite_id == PSPRITE_ZEBBO_GREEN_FOLLOWER)
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.y_position = gCurrentSprite.y_position_spawn;
        gCurrentSprite.x_position = gCurrentSprite.x_position_spawn;
        zebbo_gfx_init();
        gCurrentSprite.timer2 = 0x3C;
        gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
        gCurrentSprite.invicibility_stun_flash_timer = 0x0;
        gCurrentSprite.palette_row = 0x0;
        gCurrentSprite.frozen_palette_row_offset = 0x0;
        gCurrentSprite.absolute_palette_row = 0x0;
        gCurrentSprite.ignore_samus_collision_timer = 0x1;
        gCurrentSprite.freeze_timer = 0x0;
    }
}

void zebbo_move(void)
{

}

void zebbo(void)
{
    if (gCurrentSprite.properties & SP_UNKNOWN)
    {
        gCurrentSprite.properties &= ~SP_UNKNOWN;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x164);
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
                    sprite_util_sprite_death(DEATH_RESPAWNING, gCurrentSprite.y_position, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                    zebbo_respawning();
            }
        }
    }
}