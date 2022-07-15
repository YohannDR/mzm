#include "ripper.h"
#include "../sprite_util.h"
#include "../globals.h"

void ripper_init(void)
{
    gCurrentSprite.hitbox_top_offset = -0x24;
    gCurrentSprite.hitbox_bottom_offset = 0x0;
    gCurrentSprite.hitbox_left_offset = -0x20;
    gCurrentSprite.hitbox_right_offset = 0x20;
    gCurrentSprite.draw_distance_top_offset = 0x10;
    gCurrentSprite.draw_distance_bottom_offset = 0x8;
    gCurrentSprite.draw_distance_horizontal_offset = 0x10;
    gCurrentSprite.oam_pointer = ripper_oam_2cc048;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.samus_collision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    gCurrentSprite.y_position -= 0x8;
    SpriteUtilChooseRandomXFlip();
    gCurrentSprite.pose = 0x8;
}

void ripper_gfx_init(void)
{
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.oam_pointer = ripper_oam_2cc048;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
}

void ripper_move(void)
{
    u16 speed;

    if (gCurrentSprite.sprite_id == PSPRITE_RIPPER_PURPLE)
        speed = 0x4;
    else
        speed = 0x2;

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position - 0x10, gCurrentSprite.x_position + 0x24);
        if (gPreviousCollisionCheck != 0x11)
            gCurrentSprite.x_position += speed;
        else
            gCurrentSprite.pose = 0xA;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position - 0x10, gCurrentSprite.x_position - 0x24);
        if (gPreviousCollisionCheck == 0x11)
            gCurrentSprite.pose = 0xA;
        else
            gCurrentSprite.x_position -= speed;
    }
}

void ripper_turn_around_gfx_init(void)
{
    gCurrentSprite.pose = 0xB;
    gCurrentSprite.oam_pointer = ripper_oam_2cc070;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
}

void ripper_turn_around_begin(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.status ^= SPRITE_STATUS_XFLIP;
        gCurrentSprite.pose = 0xC;
        gCurrentSprite.oam_pointer = ripper_oam_2cc088;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
    }
}

void ripper_check_turned_around(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = 0x8;
}

void ripper(void)
{
    if (gCurrentSprite.properties & SP_UNKNOWN)
    {
        gCurrentSprite.properties &= ~SP_UNKNOWN;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x149);
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
                    ripper_init();
                    break;
                case 0x8:
                    ripper_gfx_init();
                case 0x9:
                    ripper_move();
                    break;
                case 0xA:
                    ripper_turn_around_gfx_init();
                case 0xB:
                    ripper_turn_around_begin();
                    break;
                case 0xC:
                    ripper_check_turned_around();
                    break;
                default:
                    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.y_position - 0x18, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
        }
    }
}