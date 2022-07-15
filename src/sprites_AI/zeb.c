#include "zeb.h"
#include "../sprite_util.h"
#include "../globals.h"

void zeb_init(void)
{
    gCurrentSprite.hitbox_top_offset = -0x8;
    gCurrentSprite.hitbox_bottom_offset = 0x14;
    gCurrentSprite.hitbox_left_offset = -0x1C;
    gCurrentSprite.hitbox_right_offset = 0x1C;
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

void zeb_gfx_init(void)
{
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.oam_pointer = zeb_oam_2cca2c;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
    gCurrentSprite.bg_priority = 0x2;
}

void zeb_check_spawn(void)
{
    u16 samus_x;
    u16 samus_y;
    u16 sprite_x;
    u16 sprite_y;
    i32 offset;

    if (!SpriteUtilCheckHasDrops())
    {
        if (gCurrentSprite.timer2 != 0x0)
            gCurrentSprite.timer2--;
        else
        {
            samus_y = gSamusData.y_position;
            samus_x = gSamusData.x_position;
            sprite_y = gCurrentSprite.y_position;
            sprite_x = gCurrentSprite.x_position;

            if (samus_y <= (sprite_y - 0x1E))
            {
                if (sprite_x >= samus_x)
                    offset = samus_x - sprite_x;
                else
                    offset = sprite_x - samus_x;
                
                if (offset > 0x24 && SpriteUtilCheckSamusNearSpriteAboveBelow(0x140, 0x140) == NSAB_ABOVE)
                {
                    gCurrentSprite.oam_scaling = gSamusData.y_position;
                    gCurrentSprite.pose = 0x23;
                    gCurrentSprite.timer1 = 0x2;
                    gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
                    SpriteUtilMakeSpriteFaceSamusXFlip();
                    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                        SoundPlay(0x144);
                }
            }
        }
    }
}

void zeb_going_up(void)
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
        if (gCurrentSprite.oam_scaling < gSamusData.y_position && gSamusData.y_position >= (i32)(gCurrentSprite.y_position_spawn - 0x80))
            y_position = gCurrentSprite.oam_scaling;
        else
            y_position = gSamusData.y_position;

        if ((y_position - 0x64) > gCurrentSprite.y_position)
        {
            gCurrentSprite.pose = 0x25;
            gCurrentSprite.timer1 = 0xA;
            gCurrentSprite.oam_pointer = zeb_oam_2cca54;
            gCurrentSprite.curr_anim_frame = 0x0;
            gCurrentSprite.anim_duration_counter = 0x0;
            gCurrentSprite.bg_priority = 0x1;
        }
    }
}

void zeb_reset(void)
{
    gCurrentSprite.y_position = gCurrentSprite.y_position_spawn;
    gCurrentSprite.x_position = gCurrentSprite.x_position_spawn;
    zeb_gfx_init();
    gCurrentSprite.timer2 = 0x3C;
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    gCurrentSprite.invicibility_stun_flash_timer = 0x0;
    gCurrentSprite.palette_row = 0x0;
    gCurrentSprite.frozen_palette_row_offset = 0x0;
    gCurrentSprite.absolute_palette_row = 0x0;
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    gCurrentSprite.freeze_timer = 0x0;
}

void zeb_move(void)
{
    u8 timer;

    if (gCurrentSprite.timer1 != 0x0)
    {
        if (timer = gCurrentSprite.timer1 -= 0x1 == 0x0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                play_sound(0x145);
            gCurrentSprite.timer2 = timer;
        }
    }
    else
    {
        gCurrentSprite.timer2++;
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            if ((i32)(gCurrentSprite.x_position - gSamusData.x_position) > 0x400 || gCurrentSprite.x_position & 0x8000)
            {
                zeb_reset();
                return;
            }
            gCurrentSprite.x_position += 0xC;
        }
        else
        {
            if ((i32)(gSamusData.x_position - gCurrentSprite.x_position) > 0x400 || gCurrentSprite.x_position & 0x8000)
            {
                zeb_reset();
                return;
            }
            gCurrentSprite.x_position -= 0xC;
        }
        if ((gCurrentSprite.timer2 & 0xF) == 0x0 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(0x145);
    }
}

void zeb(void)
{
    if (gCurrentSprite.properties & SP_UNKNOWN)
    {
        gCurrentSprite.properties &= ~SP_UNKNOWN;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x146);
    }

    if (gCurrentSprite.freeze_timer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (!SpriteUtilIsSpriteStunned())
        {
            switch (gCurrentSprite.pose)
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
                    SpriteUtilSpriteDeath(DEATH_RESPAWNING, gCurrentSprite.y_position, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                    zeb_reset();
            }
        }
    }
}