#include "reo.h"
#include "../sprite_util.h"
#include "../globals.h"

void reo_init(void)
{
    gCurrentSprite.draw_distance_top_offset = 0x18;
    gCurrentSprite.draw_distance_bottom_offset = 0x18;
    gCurrentSprite.draw_distance_horizontal_offset = 0x18;
    gCurrentSprite.hitbox_top_offset = -0x20;
    gCurrentSprite.hitbox_bottom_offset = 0x20;
    gCurrentSprite.hitbox_left_offset = -0x38;
    gCurrentSprite.hitbox_right_offset = 0x38;
    gCurrentSprite.oam_pointer = reo_oam_2ce214;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    gCurrentSprite.samus_collision = SSC_HURTS_SAMUS;
    SpriteUtilChooseRandomXDirection();
    if (0x8 < gSpriteRNG)
        gCurrentSprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
    gCurrentSprite.pose = 0x8;
}

void reo_rng(void)
{
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.work_variable = (gSpriteRNG << 0x1A) >> 0x18;
    gCurrentSprite.array_offset = gCurrentSprite.work_variable;
}

void reo_samus_detection(void)
{
    i16 movement;
    u8 offset;

    offset = gCurrentSprite.array_offset;
    movement = reo_idle_anim_y_position_offsets[offset];
    if (movement == 0x7FFF)
    {
        movement = reo_idle_anim_y_position_offsets[0x0];
        offset = 0x0;
    }
    gCurrentSprite.array_offset = offset + 0x1;
    gCurrentSprite.y_position += movement;
    
    offset = gCurrentSprite.work_variable;
    movement = reo_idle_anim_x_position_offsets[offset];
    if (movement == 0x7FFF)
    {
        movement = reo_idle_anim_x_position_offsets[0x0];
        offset = 0x0;
    }
    gCurrentSprite.work_variable = offset + 0x1;
    gCurrentSprite.x_position += movement;

    if (SpriteUtilCheckSamusNearSpriteLeftRight(0x200, 0x1C0) != NSLR_OUT_OF_RANGE)
        gCurrentSprite.pose = 0x22;
}

void reo_samus_detected(void)
{

}

void reo_move(void)
{

}

void reo(void)
{
    if (gCurrentSprite.properties & SP_UNKNOWN)
    {
        gCurrentSprite.properties &= ~SP_UNKNOWN;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x159);
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
                    reo_init();
                    break;
                case 0x8:
                    reo_rng();
                    break;
                case 0x9:
                    reo_samus_detection();
                    break;
                case 0x22:
                    reo_samus_detected();
                case 0x23:
                    reo_move();
                    break;
                default:
                    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.y_position, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_BIG);
            }
        }
    }
}