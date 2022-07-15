#include "geruta.h"
#include "../sprite_util.h"
#include "../globals.h"

u8 GerutaYMovement(u16 movement)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.y_position + 0x40, gCurrentSprite.x_position) == 0x11 ||
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.y_position + 0x40, gCurrentSprite.x_position - 0x30) == 0x11 ||
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.y_position + 0x40, gCurrentSprite.x_position + 0x30) == 0x11)
            return TRUE;
        gCurrentSprite.y_position += movement;
    }
    else
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.y_position - 0x28, gCurrentSprite.x_position - 0x30) == 0x11 &&
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.y_position - 0x28, gCurrentSprite.x_position - 0x70) == 0x11)
            return TRUE;

        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.y_position - 0x28, gCurrentSprite.x_position + 0x30) == 0x11 &&
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.y_position - 0x28, gCurrentSprite.x_position + 0x70) == 0x11)
            return TRUE;

        gCurrentSprite.y_position -= movement;
    }

    return FALSE;
}

u8 GerutaXMovement(u16 movement)
{
    register u16 movement_;

    movement_ = movement;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.y_position - 0x20, gCurrentSprite.x_position + 0x40) == 0x11 || SpriteUtilGetCollisionAtPosition(gCurrentSprite.y_position + 0x20, gCurrentSprite.x_position + 0x40) == 0x11)
            return TRUE;
        gCurrentSprite.x_position += movement;
    }
    else
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.y_position - 0x20, gCurrentSprite.x_position - 0x40) == 0x11 || SpriteUtilGetCollisionAtPosition(gCurrentSprite.y_position + 0x20, gCurrentSprite.x_position - 0x40) == 0x11)
            return TRUE;
        gCurrentSprite.x_position -= movement_;
    }
    
    return FALSE;
}

void GerutaInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    SpriteUtilMakeSpriteFaceSamusDirection();
    gCurrentSprite.draw_distance_top_offset = 0x18;
    gCurrentSprite.draw_distance_bottom_offset = 0x18;
    gCurrentSprite.draw_distance_horizontal_offset = 0x18;
    gCurrentSprite.hitbox_top_offset = -0x20;
    gCurrentSprite.hitbox_bottom_offset = 0x20;
    gCurrentSprite.hitbox_left_offset = -0x30;
    gCurrentSprite.hitbox_right_offset = 0x30;
    gCurrentSprite.oam_pointer = geruta_oam_2d1400;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    gCurrentSprite.samus_collision = SSC_HURTS_SAMUS;
    gCurrentSprite.y_position -= 0xC;
    gCurrentSprite.pose = 0x8;
}

void GerutaGFXInit(void)
{
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.oam_pointer = geruta_oam_2d1400;
}

void GerutaDetectSamus(void)
{
    u8 nslr;

    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.y_position - 0x40, gCurrentSprite.x_position - 0x30) != 0x11 && SpriteUtilGetCollisionAtPosition(gCurrentSprite.y_position - 0x40, gCurrentSprite.x_position + 0x30) != 0x11)
        SpriteUtilMakeSpriteFaceSamusDirection();
    else
    {
        if ((gSamusData.y_position - 0x48) >= gCurrentSprite.y_position)
        {
            nslr = SpriteUtilCheckSamusNearSpriteLeftRight(0x140, 0x140);
            if (nslr != NSLR_RIGHT && nslr != NSLR_LEFT)
                return;
            gCurrentSprite.pose = 0x32;
            return;
        }
        else
            return;
    }

    gCurrentSprite.pose = 0x32;
}

void GerutaGoDownGFXInit(void)
{
    gCurrentSprite.pose = 0x33;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.oam_pointer = geruta_oam_2d1418;
    if ((gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
        SoundPlay(0x150);
}

void GerutaCheckWarningEnded(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0x35;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.oam_pointer = geruta_oam_2d1438;
    }
}

void GerutaCheckGoingDownAnimEnded(void)
{
    if (SpriteUtilCheckEndSpriteAnim())
    {
        gCurrentSprite.pose = 0x37;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.oam_pointer = geruta_oam_2d1460;
        gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
        SpriteUtilMakeSpriteFaceSamusDirection();
        if ((gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
            unk_2b20(0x14E);
    }
}

void GerutaGoingDown(void)
{
    u16 old_y;

    old_y = gCurrentSprite.y_position;
    GerutaXMovement(0x4);
    if (GerutaYMovement(0xC) << 0x18)
    {
        gCurrentSprite.pose = 0x39;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.oam_pointer = geruta_oam_2d1488;
    }

    SpriteUtilCheckInRoomEffect(old_y, gCurrentSprite.y_position, gCurrentSprite.x_position, SPLASH_BIG);
}

void GerutaCheckBouncingAnimEnded(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0x3B;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.oam_pointer = geruta_oam_2d14a0;
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        if ((gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
            unk_2b20(0x14F);
    }
}

void GerutaGoingUp(void)
{
    GerutaXMovement(0x4);
    if (GerutaYMovement(0xC) << 0x18)
    {
        gCurrentSprite.y_position = (gCurrentSprite.y_position & 0xFFC0);
        gCurrentSprite.y_position  += 0x34;
        gCurrentSprite.pose = 0x3D;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.oam_pointer = geruta_oam_2d14c8;
    }
}

void GerutaCheckResetAnimEnded(void)
{
    if (SpriteUtilCheckNearEndSpriteAnim())
        gCurrentSprite.pose = 0x8;
}

void Geruta(void)
{
    if ((gCurrentSprite.properties & SP_DAMAGED) != 0x0)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if ((gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
            unk_2b20(0x151);
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
                    GerutaInit();
                    break;
                case 0x8:
                    GerutaGFXInit();
                case 0x9:
                    GerutaDetectSamus();
                    break;
                case 0x32:
                    GerutaGoDownGFXInit();
                case 0x33:
                    GerutaCheckWarningEnded();
                    break;
                case 0x35:
                    GerutaCheckGoingDownAnimEnded();
                    break;
                case 0x37:
                    GerutaGoingDown();
                    break;
                case 0x39:
                    GerutaCheckBouncingAnimEnded();
                    break;
                case 0x3B:
                    GerutaGoingUp();
                    break;
                case 0x3D:
                    GerutaCheckResetAnimEnded();
                    break;

                default:
                    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.y_position, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
        }
    }
}