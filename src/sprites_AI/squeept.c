#include "squeept.h"
#include "../sprite_util.h"
#include "../globals.h"

void SqueeptGFXReset(void)
{
    gCurrentSprite.hitbox_top_offset = -0x2C;
    gCurrentSprite.hitbox_bottom_offset = 0x20;
    gCurrentSprite.oam_pointer = squeept_oam_2d1be0;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
}

void SqueeptTurningAroundGFXInit(void)
{
    gCurrentSprite.hitbox_top_offset = -0x20;
    gCurrentSprite.hitbox_bottom_offset = 0x20;
    gCurrentSprite.oam_pointer = squeept_oam_2d1b68;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
}

void SqueeptGoingDownGFXInit(void)
{
    gCurrentSprite.hitbox_top_offset = 0x0;
    gCurrentSprite.hitbox_bottom_offset = 0x28;
    gCurrentSprite.oam_pointer = squeept_oam_2d1bc8;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
}

void SqueeptInit(void)
{
    gCurrentSprite.draw_distance_top_offset = 0x14;
    gCurrentSprite.draw_distance_bottom_offset = 0x14;
    gCurrentSprite.draw_distance_horizontal_offset = 0x10;
    gCurrentSprite.hitbox_left_offset = -0x20;
    gCurrentSprite.hitbox_right_offset = 0x20;
    gCurrentSprite.samus_collision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    gCurrentSprite.y_position += 0x4;
    gCurrentSprite.y_position_spawn = gCurrentSprite.y_position;
}

void SqueeptReset(void)
{
    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.pose = 0xF;
    SqueeptGFXReset();
    gCurrentSprite.timer1 = 0x1E;
}

void SqueeptDetectSamus(void)
{
    u32 timer;
    u8 nsab;

    timer = gCurrentSprite.timer1;
    if (timer != 0x0)
        gCurrentSprite.timer1--;
    else
    {
        nsab = SpriteUtilCheckSamusNearSpriteAboveBelow(0x200, 0x180);
        if (nsab == NSAB_ABOVE)
        {
            gCurrentSprite.pose = 0x35;
            gCurrentSprite.array_offset = timer;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        }
    }
}

void SqueeptGoUp(void)
{

}

void SqueeptTurnAround(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        SqueeptGoingDownGFXInit();
        gCurrentSprite.pose = 0x39;
        gCurrentSprite.array_offset = 0x0;
    }
}

void SqueeptGoDown(void)
{
    u16 old_y;
    u8 offset;
    i16 velocity;

    old_y = gCurrentSprite.y_position;
    offset = gCurrentSprite.array_offset;
    velocity = squeept_falling_speed_2d1562[offset];
    if (velocity == 0x7FFF)
        gCurrentSprite.y_position += squeept_falling_speed_2d1562[offset - 0x1];
    else
    {
        gCurrentSprite.array_offset = offset + 0x1;
        gCurrentSprite.y_position += velocity;
    }

    if (SpriteUtilCheckInRoomEffect(old_y, gCurrentSprite.y_position, gCurrentSprite.x_position, SPLASH_BIG) && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(0x156);

    if (gCurrentSprite.y_position_spawn < gCurrentSprite.y_position)
    {
        gCurrentSprite.y_position = gCurrentSprite.y_position_spawn;
        SqueeptReset();
    }
}

void Squeept(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x157);
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
                    SqueeptInit();
                case 0xE:
                    SqueeptReset();
                case 0xF:
                    SqueeptDetectSamus();
                    break;
                case 0x35:
                    SqueeptGoUp();
                    break;
                case 0x37:
                    SqueeptTurnAround();
                    break;
                case 0x39:
                    SqueeptGoDown();
                    break;
                default:
                    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.y_position, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
        }
    }
}