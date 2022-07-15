#include "multiviola.h"
#include "../sprite_util.h"
#include "../globals.h"

void MultiviolaInit(void)
{
    gCurrentSprite.draw_distance_top_offset = 0x20;
    gCurrentSprite.draw_distance_bottom_offset = 0xC;
    gCurrentSprite.draw_distance_horizontal_offset = 0x10;
    gCurrentSprite.hitbox_top_offset = -0x20;
    gCurrentSprite.hitbox_bottom_offset = 0x20;
    gCurrentSprite.hitbox_left_offset = -0x20;
    gCurrentSprite.hitbox_right_offset = 0x20;
    gCurrentSprite.oam_pointer = multiviola_oam_2d0520;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = gCurrentSprite.primary_sprite_ram_slot << 0x1;
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    gCurrentSprite.samus_collision = SSC_HURTS_SAMUS;
    SpriteUtilMakeSpriteFaceSamusXFlip();
    gCurrentSprite.pose = 0x9;
}

void MultiviolaMove(void)
{
    u8 is_bouncing;
    u16 y_movement;

    is_bouncing = 0x0;
    y_movement = 0x3;

    if ((gCurrentSprite.status & SPRITE_STATUS_XFLIP) != 0x0)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position, gCurrentSprite.hitbox_right_offset + gCurrentSprite.x_position);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.x_position += 0x3;
        else
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            is_bouncing = 0x1;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position, gCurrentSprite.hitbox_left_offset + gCurrentSprite.x_position);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.x_position -= 0x3;
        else
        {
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            is_bouncing = 0x1;
        }
    }

    if ((gCurrentSprite.status & SPRITE_STATUS_ON_VERTICAL_WALL) != 0x0)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.hitbox_top_offset + gCurrentSprite.y_position, gCurrentSprite.x_position);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.y_position -= y_movement;
        else
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
            is_bouncing++;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.hitbox_bottom_offset + gCurrentSprite.y_position, gCurrentSprite.x_position);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.y_position += y_movement;
        else
        {
            gCurrentSprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
            is_bouncing++;
        }
    }

    if (is_bouncing != 0x0 && (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
        unk_2b20(0x152);
}

void MultivioaUnused_Empty1(void)
{
    return;
}

void MultivioaUnused_Empty2(void)
{
    return;
}

void Multiviola(void)
{
    if ((gCurrentSprite.properties & SP_DAMAGED) != 0x0)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if ((gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
            unk_2b20(0x153);
    }

    if (gCurrentSprite.freeze_timer != 0x0)
    {
        SpriteUtilUpdateFreezeTimer();
        SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent(SSPRITE_MULTIVIOLA_UNUSED, gCurrentSprite.primary_sprite_ram_slot);
    }
    else
    {
        if (!SpriteUtilIsSpriteStunned())
        {
            switch (gCurrentSprite.pose)
            {
                default:
                    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.y_position, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_BIG);
                    break;
                case 0x0:
                    MultiviolaInit();
                    break;
                case 0x9:
                    MultiviolaMove();
            }
        }
    }
}

void MultiviolaUnused(void)
{
    return;
}