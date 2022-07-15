#include "ripper.h"
#include "../sprite_util.h"
#include "../globals.h"

void RipperInit(void)
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

void RipperGFXInit(void)
{
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.oam_pointer = ripper_oam_2cc048;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
}

void RipperMove(void)
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

void RipperTurnAroundGFXInit(void)
{
    gCurrentSprite.pose = 0xB;
    gCurrentSprite.oam_pointer = ripper_oam_2cc070;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
}

void RipperTurnAroundBegin(void)
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

void RipperCheckTurnedAround(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = 0x8;
}

void Ripper(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
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
                    RipperInit();
                    break;
                case 0x8:
                    RipperGFXInit();
                case 0x9:
                    RipperMove();
                    break;
                case 0xA:
                    RipperTurnAroundGFXInit();
                case 0xB:
                    RipperTurnAroundBegin();
                    break;
                case 0xC:
                    RipperCheckTurnedAround();
                    break;
                default:
                    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.y_position - 0x18, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
        }
    }
}