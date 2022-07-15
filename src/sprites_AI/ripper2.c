#include "Ripper2.h"
#include "../sprite_util.h"
#include "../../data/data.h"
#include "../globals.h"

void Ripper2Init(void)
{
    gCurrentSprite.hitbox_top_offset = -0x24;
    gCurrentSprite.hitbox_bottom_offset = 0x8;
    gCurrentSprite.hitbox_left_offset = -0x28;
    gCurrentSprite.hitbox_right_offset = 0x28;
    gCurrentSprite.draw_distance_top_offset = 0x10;
    gCurrentSprite.draw_distance_bottom_offset = 0x8;
    gCurrentSprite.draw_distance_horizontal_offset = 0x28;
    gCurrentSprite.oam_pointer = ripper2_oam_2cc458;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.samus_collision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    gCurrentSprite.y_position -= 0x8;
    SpriteUtilChooseRandomXFlip();
    gCurrentSprite.pose = 0x8;
}

void Ripper2GFXInit(void)
{
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.oam_pointer = ripper2_oam_2cc458;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
}

void Ripper2Move(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position - 0x10, gCurrentSprite.x_position + 0x2C);
        if (gPreviousCollisionCheck != 0x11)
            gCurrentSprite.x_position += 0x8;
        else
            gCurrentSprite.pose = 0xA;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position - 0x10, gCurrentSprite.x_position - 0x2C);
        if (gPreviousCollisionCheck == 0x11)
            gCurrentSprite.pose = 0xA;
        else
            gCurrentSprite.x_position -= 0x8;
    }
}

void Ripper2TurnAroundGFXInit(void)
{
    gCurrentSprite.pose = 0xB;
    gCurrentSprite.oam_pointer = ripper2_oam_2cc480;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        unk_2b20(0x267);
}

void Ripper2TurnAroundBegin(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.status ^= SPRITE_STATUS_XFLIP;
        gCurrentSprite.pose = 0xC;
        gCurrentSprite.oam_pointer = ripper2_oam_2cc498;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
    }
}

void Ripper2CheckTurnedAround(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = 0x8;
}

void Ripper2(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x268);
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
                    Ripper2Init();
                    break;
                case 0x8:
                    Ripper2GFXInit();
                case 0x9:
                    Ripper2Move();
                    break;
                case 0xA:
                    Ripper2TurnAroundGFXInit();
                case 0xB:
                    Ripper2TurnAroundBegin();
                    break;
                case 0xC:
                    Ripper2CheckTurnedAround();
                    break;
                default:
                    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.y_position - 0x18, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
        }
    }
}