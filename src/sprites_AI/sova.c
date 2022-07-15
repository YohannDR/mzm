#include "sova.h"
#include "../sprite_util.h"
#include "../globals.h"

u8 SovaCheckCollidingWithAir(void)
{
    u8 colliding;

    colliding = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_ON_VERTICAL_WALL)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position - 0x20, gCurrentSprite.x_position);
            if (gPreviousCollisionCheck != 0x0)
                colliding = FALSE;
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position + 0x20, gCurrentSprite.x_position);
                if (gPreviousCollisionCheck == 0x0)
                    colliding = TRUE;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position - 0x20, gCurrentSprite.x_position - 0x4);
            if (gPreviousCollisionCheck != 0x0)
                colliding = FALSE;
            else
            {                
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position + 0x20, gCurrentSprite.x_position - 0x4);
                if (gPreviousCollisionCheck == 0x0)
                    colliding = TRUE;
            }
        }
    }
    else
    {
        if (gCurrentSprite.workVariable2 != 0x0)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position - 0x4, gCurrentSprite.x_position - 0x20);
            if (gPreviousCollisionCheck != 0x0)
                colliding = FALSE;
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position - 0x4, gCurrentSprite.x_position + 0x20);
                if (gPreviousCollisionCheck == 0x0)
                    colliding = TRUE;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position, gCurrentSprite.x_position - 0x20);
            if (gPreviousCollisionCheck != 0x0)
                colliding = FALSE;
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position, gCurrentSprite.x_position + 0x20);
                if (gPreviousCollisionCheck == 0x0)
                    colliding = TRUE;
            }
        }
    }

    return colliding;
}

void SovaHitboxUpdate(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ON_VERTICAL_WALL)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            gCurrentSprite.hitbox_top_offset = -0x1C;
            gCurrentSprite.hitbox_bottom_offset = 0x1C;
            gCurrentSprite.hitbox_left_offset = -0x34;
            gCurrentSprite.hitbox_right_offset = 0x4;
        }
        else
        {
            gCurrentSprite.hitbox_top_offset = -0x1C;
            gCurrentSprite.hitbox_bottom_offset = 0x1C;
            gCurrentSprite.hitbox_left_offset = -0x4;
            gCurrentSprite.hitbox_right_offset = 0x34;
        }
    }
    else
    {
        if (gCurrentSprite.workVariable2 != 0x0)
        {
            gCurrentSprite.hitbox_top_offset = -0x4;
            gCurrentSprite.hitbox_bottom_offset = 0x34;
        }
        else
        {
            gCurrentSprite.hitbox_top_offset = -0x34;
            gCurrentSprite.hitbox_bottom_offset = 0x4;
        }
        gCurrentSprite.hitbox_left_offset = -0x1C;
        gCurrentSprite.hitbox_right_offset = 0x1C;
    }
}

void SovaGFXUpdate(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ON_VERTICAL_WALL)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.oam_pointer = sova_oam_2cfc78;
        else
            gCurrentSprite.oam_pointer = sova_oam_2cfc40;
    }
    else
    {
        if (gCurrentSprite.workVariable2 != 0x0)
            gCurrentSprite.oam_pointer = sova_oam_2cfcb0;
        else
            gCurrentSprite.oam_pointer = sova_oam_2cfb98;
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            status |= SPRITE_STATUS_XFLIP;
        else
            status &= ~SPRITE_STATUS_XFLIP;
    }

    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
}

void SovaInit(void)
{
    gCurrentSprite.workVariable2 = 0x0;
    gCurrentSprite.pose = 0x9;
    SpriteUtilChooseRandomXDirection();
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position, gCurrentSprite.x_position);
    if (gPreviousCollisionCheck & 0xF0)
        gCurrentSprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position - 0x44, gCurrentSprite.x_position);
        if (gPreviousCollisionCheck & 0xF0)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
            gCurrentSprite.y_position -= 0x40;
            gCurrentSprite.workVariable2 = 0x1;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position - 0x20, gCurrentSprite.x_position - 0x24);
            if (gPreviousCollisionCheck & 0xF0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
                gCurrentSprite.y_position -= 0x20;
                gCurrentSprite.x_position -= 0x20;
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position - 0x20, gCurrentSprite.x_position + 0x20);
                if ((gPreviousCollisionCheck & 0xF0) == 0x0)
                {
                    gCurrentSprite.gCurrentSprite.status = gPreviousCollisionCheck & 0xF0;
                    return;
                }
                else
                {
                    gCurrentSprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
                    gCurrentSprite.status |= SPRITE_STATUS_XFLIP;                    
                    gCurrentSprite.y_position -= 0x20;
                    gCurrentSprite.x_position += 0x20;
                }
            }
        }
    }

    if (!(gCurrentSprite.gCurrentSprite.status & SPRITE_STATUS_ON_VERTICAL_WALL))
    {
        if (gCurrentSprite.gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    }

    gCurrentSprite.samus_collision = SSC_HURTS_SAMUS;
    SovaGFXUpdate();
    SovaHitboxUpdate();
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    gCurrentSprite.draw_distance_top_offset = 0x10;
    gCurrentSprite.draw_distance_bottom_offset = 0x10;
    gCurrentSprite.draw_distance_horizontal_offset = 0x10;
    if (gCurrentSprite.sprite_id == PSPRITE_SOVA_ORANGE)
    {
        gCurrentSprite.absolute_palette_row = 0x1;
        gCurrentSprite.palette_row = 0x1;
    }
}

void SovaInit(void)
{
    SovaGFXUpdate();
    gCurrentSprite.pose = 0x9;
}

void SovaMove(void)
{
    u16 speed;
    u8 turning;

    switch (gCurrentSprite.curr_anim_frame)
    {
        case 0x2:
            speed = 0x1;
            break;
        case 0x3:
            speed = 0x2;
            break;
        case 0x4:
            speed = 0x3;
            break;
        case 0x5:
            speed = 0x1;
            break;
        default:
            speed = 0x0;
    }

    if (gCurrentSprite.sprite_id == PSPRITE_SOVA_ORANGE && speed)
        speed++;

    turning = FALSE;

    if (SovaCheckCollidingWithAir() << 0x18)
    {
        gCurrentSprite.pose = 0x1E;
        return;
    }

    if (sprite_util_is_screen_on_screen_and_screen_shake())
    {
        if (gCurrentSprite.status & SPRITE_STATUS_ON_VERTICAL_WALL || gCurrentSprite.workVariable2)
            gCurrentSprite.pose = 0x1E;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_ON_VERTICAL_WALL)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            if (gCurrentSprite..status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position, gCurrentSprite.x_position);
                if ((gPreviousCollisionCheck & 0xF0) == 0x0)
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position + 0x1C, gCurrentSprite.x_position - 0x4);
                    if (gPreviousCollisionCheck != 0x11)
                    {
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.workVariable = 0x5;
                    }
                    else
                        gCurrentSprite.y_position += speed;
                    
                    if (turning)
                        gCurrentSprite.pose = 0xA;
                    return;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position - 0x4, gCurrentSprite.x_position);
                if ((gPreviousCollisionCheck & 0xF0) == 0x0)
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position - 0x1C, gCurrentSprite.x_position - 0x4);
                    if (gPreviousCollisionCheck != 0x11)
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    else
                    {
                        gCurrentSprite.y_position -= speed;
                        if (turning)
                            gCurrentSprite.pose = 0xA;
                        return;
                    }

                    if (turning)
                        gCurrentSprite.pose = 0xA;
                    return;
                }
            }

            turning = TRUE;
            gCurrentSprite.workVariable = 0x7;
            if (turning)
                gCurrentSprite.pose = 0xA;
            return;
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position, gCurrentSprite.x_position - 0x4);
                if ((gPreviousCollisionCheck & 0xF0) == 0x0)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position + 0x1C, gCurrentSprite.x_position);
                    if (gPreviousCollisionCheck != 0x11)
                    {
                        gCurrentSprite.y_position += speed;
                        if (turning)
                            gCurrentSprite.pose = 0xA;
                        return;
                    }
                    else
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.workVariable = 0x4;
                        if (turning)
                            gCurrentSprite.pose = 0xA;
                        return;
                    }
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position - 0x4, gCurrentSprite.x_position - 0x4);
                if ((gPreviousCollisionCheck & 0xF0) == 0x0)
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.workVariable = 0x4;
                    if (turning)
                        gCurrentSprite.pose = 0xA;
                    return;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position, gCurrentSprite.x_position - 0x4);
                    if (gPreviousCollisionCheck != 0x11)
                    {
                        gCurrentSprite.y_position -= speed;
                        if (turning)
                            gCurrentSprite.pose = 0xA;
                        return;
                    }
                    else
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.workVariable = 0x4;
                        if (turning)
                            gCurrentSprite.pose = 0xA;
                        return;
                    }
                }
            }
            turning = TRUE;
            gCurrentSprite.workVariable = 0x6;
            if (turning)
                gCurrentSprite.pose = 0xA;
            return;
        }
    }

    if (gCurrentSprite.workVariable2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position - 0x4, gCurrentSprite.x_position);
            if ((gPreviousCollisionCheck & 0xF) == 0x0)
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position, gCurrentSprite.x_position + 0x1C);
                if (gPreviousCollisionCheck != 0x11)
                {
                    gCurrentSprite.x_position += speed;
                    if (turning)
                        gCurrentSprite.pose = 0xA;
                    return;
                }
                else
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.workVariable = 0x3;
                    if (turning)
                        gCurrentSprite.pose = 0xA;
                    return;
                }
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position - 0x4, gCurrentSprite.x_position - 0x4);
            if ((gPreviousCollisionCheck & 0xF) == 0x0)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                turning = TRUE;
                gCurrentSprite.workVariable = 0x3;
                if (turning)
                    gCurrentSprite.pose = 0xA;
                return;
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position, gCurrentSprite.x_position - 0x1C);
                if (gPreviousCollisionCheck != 0x11)
                {
                    gCurrentSprite.x_position -= speed;
                    if (turning)
                        gCurrentSprite.pose = 0xA;
                    return;
                }
                else
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            }
        }

        turning = TRUE;
        gCurrentSprite.workVariable = 0x2;
        if (turning)
            gCurrentSprite.pose = 0xA;
        return;
    }
    else
    {
        unk_f594();
        if (gPreviousVerticalCollisionCheck == 0x0 || gPreviousVerticalCollisionCheck & 0xF0)
        {
            if (gCurrentSprite.oam_pointer != sova_oam_2cfb98)
            {
                gCurrentSprite.oam_pointer = sova_oam_2cfb98;
                gCurrentSprite.anim_duration_counter = 0x0;
                gCurrentSprite.curr_anim_frame = 0x0;
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                    gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
                else
                    gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            }

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position, gCurrentSprite.x_position);
                if (gPreviousCollisionCheck == 0x0)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.workVariable = 0x0;
                    if (turning)
                        gCurrentSprite.pose = 0xA;
                    return;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position - 0x4, gCurrentSprite.x_position + 0x1C);
                    if (gPreviousCollisionCheck != 0x11)
                    {
                        gCurrentSprite.x_position += speed;
                        if (turning)
                            gCurrentSprite.pose = 0xA;
                        return;
                    }
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                }
            }

            turning = TRUE;
            gCurrentSprite.workVariable = 0x1;
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (gPreviousVerticalCollisionCheck == 0x2 || gPreviousVerticalCollisionCheck == 0x4)
                {
                    if (gCurrentSprite.oam_pointer != sova_oam_2cfbd0)
                    {
                        gCurrentSprite.oam_pointer = sova_oam_2cfbd0;
                        gCurrentSprite.anim_duration_counter = 0x0;
                        gCurrentSprite.curr_anim_frame = 0x0;
                        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
                    }

                    speed = (speed << 0x1) / 0x3;
                    gCurrentSprite.x_position += speed;

                    if (turning)
                        gCurrentSprite.pose = 0xA;
                    return;
                }
                else
                {
                    if (gCurrentSprite.oam_pointer != sova_oam_2cfc08)
                    {
                        gCurrentSprite.oam_pointer = sova_oam_2cfc08;
                        gCurrentSprite.anim_duration_counter = 0x0;
                        gCurrentSprite.curr_anim_frame = 0x0;
                        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
                    }
                    gCurrentSprite.x_position += speed;

                    if (turning)
                        gCurrentSprite.pose = 0xA;
                    return;
                }
            }
            else
            {
                if (gPreviousVerticalCollisionCheck == 0x3 || gPreviousVerticalCollisionCheck == 0x5)
                {
                    if (gCurrentSprite.oam_pointer != sova_oam_2cfc08)
                    {
                        gCurrentSprite.oam_pointer = sova_oam_2cfc08;
                        gCurrentSprite.anim_duration_counter = 0x0;
                        gCurrentSprite.curr_anim_frame = 0x0;
                        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
                    }
                    gCurrentSprite.x_position -= speed;
                }
                else
                {
                    if (gCurrentSprite.oam_pointer != sova_oam_2cfbd0)
                    {
                        gCurrentSprite.oam_pointer = sova_oam_2cfbd0;
                        gCurrentSprite.anim_duration_counter = 0x0;
                        gCurrentSprite.curr_anim_frame = 0x0;
                        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
                    }
                    speed = (speed << 0x1) / 0x3;
                    gCurrentSprite.x_position -= speed;

                    if (turning)
                        gCurrentSprite.pose = 0xA;
                    return;
                }
            }
        }

        if (turning)
            gCurrentSprite.pose = 0xA;
        return;
    }
}

void SovaTurningAroundGFXUpdate(void)
{
    u16 status;

    status = SPRITE_STATUS_NONE;
    gCurrentSprite.pose = 0xB;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;

    switch (gCurrentSprite.workVariable)
    {
        case 0x0:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.oam_pointer = sova_oam_2cfce8;
            else
                gCurrentSprite.oam_pointer = sova_oam_2cfd28;

            status &= ~SPRITE_STATUS_XFLIP;
            status &= ~SPRITE_STATUS_FACING_DOWN;
            break;

        case 0x1:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.oam_pointer = sova_oam_2cfce8;
            else
                gCurrentSprite.oam_pointer = sova_oam_2cfd28;

            status |= SPRITE_STATUS_XFLIP;
            status &= ~SPRITE_STATUS_FACING_DOWN;
            break;

        case 0x2:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.oam_pointer = sova_oam_2cfd28;
            else
                gCurrentSprite.oam_pointer = sova_oam_2cfce8;

            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            return;

        case 0x3:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.oam_pointer = sova_oam_2cfd28;
            else
                gCurrentSprite.oam_pointer = sova_oam_2cfce8;

            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            return;

        case 0x4:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.oam_pointer = sova_oam_2cfd48;
            else
                gCurrentSprite.oam_pointer = sova_oam_2cfd08;
            
            status &= ~SPRITE_STATUS_XFLIP;
            status &= ~SPRITE_STATUS_FACING_DOWN;
            break;

        case 0x5:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.oam_pointer = sova_oam_2cfd08;
            else
                gCurrentSprite.oam_pointer = sova_oam_2cfd48;

            status |= SPRITE_STATUS_XFLIP;
            status &= ~SPRITE_STATUS_FACING_DOWN;
            break;

        case 0x6:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.oam_pointer = sova_oam_2cfd48;
            else
                gCurrentSprite.oam_pointer = sova_oam_2cfd08;

            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            return;

        case 0x7:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.oam_pointer = sova_oam_2cfd08;
            else
                gCurrentSprite.oam_pointer = sova_oam_2cfd48;
            
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            return;
    }

    gCurrentSprite.status = status;
}

void SovaTurningAround(void)
{
    if (!SpriteUtillCheckEndCurrentSpriteAnim())
        return;
    
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
    gCurrentSprite.workVariable2 = 0x0;

    switch (gCurrentSprite.workVariable)
    {
        case 0x0:
            if ((gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT) == 0x0)
            {
                gCurrentSprite.y_position -= 0x18;
                gCurrentSprite.x_position &= 0xFFC0;
            }
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
            break;

        case 0x1:
            if ((gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT) == 0x0)
            {
                gCurrentSprite.y_position -= 0x1C;
                gCurrentSprite.x_position = (gCurrentSprite.x_position & 0xFFC0) + 0x40;
            }
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
            break;

        case 0x2:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.y_position += 0x18;
                gCurrentSprite.x_position &= 0xFFC0;
            }
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
            break;

        case 0x3:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.y_position += 0x1C;
                gCurrentSprite.x_position = (gCurrentSprite.x_position & 0xFFC0) + 0x40;
            }
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
            break;

        case 0x4:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.x_position += 0x1C;
                gCurrentSprite.y_position = (gCurrentSprite.y_position & 0xFFC0) + 0x40;
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            }
            else
            {
                gCurrentSprite.y_position &= 0xFFC0;
                gCurrentSprite.status & ~(SPRITE_STATUS_XFLIP);
            }
            gCurrentSprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
            break;

        case 0x5:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.y_position &= 0xFFC0;
                gCurrentSprite.status & ~(SPRITE_STATUS_XFLIP);
            }
            else
            {
                gCurrentSprite.x_position -= 0x1C;
                gCurrentSprite.y_position = (gCurrentSprite.y_position & 0xFFC0) + 0x40;
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            }
            gCurrentSprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
            break;

        case 0x6:
            if ((gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN) == 0x0)
            {
                gCurrentSprite.y_position &= 0xFFC0;
                gCurrentSprite.x_position += 0x18;
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;

            gCurrentSprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
            gCurrentSprite.workVariable2 = 0x1;
            break;

        case 0x7:
            if ((gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT) == 0x0)
            {
                gCurrentSprite.y_position &= 0xFFC0;
                gCurrentSprite.x_position -= 0x1C;
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            
            gCurrentSprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
            gCurrentSprite.workVariable2 = 0x1;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }

    SovaGFXUpdate();
    SovaHitboxUpdate();
}

void SovaBackOnGround(void)
{
    gCurrentSprite.pose = 0xF;
    gCurrentSprite.oam_pointer = sova_oam_falling_2cfd68;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    SpriteUtilChooseRandomXFlip();
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        status |= SPRITE_STATUS_XFLIP;
    else
        status &= ~SPRITE_STATUS_XFLIP;
}

void SovaCheckBackOnGroundAnimEnded(void)
{
    if (SovaCheckCollidingWithAir() << 0x18 != 0x0)
        gCurrentSprite.pose = 0x1E;
    else
    {
        if (SpriteUtilCheckNearEndCurrentSpriteAnim())
            gCurrentSprite.pose = 0x8;
    }
}

void SovaStartFalling(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ON_VERTICAL_WALL)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            gCurrentSprite.x_position -= 0x20;
        else
            gCurrentSprite.x_position += 0x20;
    }
    else if (gCurrentSprite.workVariable2 != 0x0)
        gCurrentSprite.y_position += 0x28;

    gCurrentSprite.pose = 0x1F;
    gCurrentSprite.array_offset = 0x0;
    gCurrentSprite.workVariable2 = 0x0;
    status &= ~(SPRITE_STATUS_XFLIP | SPRITE_STATUS_FACING_DOWN | SPRITE_STATUS_ON_VERTICAL_WALL);
    SovaHitboxUpdate();
    gCurrentSprite.oam_pointer = sova_oam_falling_2cfd68;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
}

void SovaFalling(void)
{
    u16 old_y;
    i16 movement;
    u16 offset;
    u32 new_y;
    u32 block;

    old_y = gCurrentSprite.y_position;
    offset = gCurrentSprite.array_offset;
    movement = sprites_falling_speed_2b0d04[offset];
    if (movement == 0x7FFF)
    {
        movement = sprites_falling_speed_2b0d04[offset - 0x1];
        new_y = old_y + movement;
    }
    else
    {
        gCurrentSprite.array_offset++;
        new_y = gCurrentSprite.y_position + movement;
    }

    gCurrentSprite.y_position = new_y;
    block = SpriteUtilCheckVerticalCollisionAtPosition_slopes(gCurrentSprite.y_position, gCurrentSprite.x_position);
    if (gPreviousVerticalCollisionCheck)
    {
        gCurrentSprite.y_position = block;
        SovaBackOnGround();
    }
    else
        SpriteUtilCheckInRoomEffect(old_y, gCurrentSprite.y_position, gCurrentSprite.x_position, SPLASH_BIG);
}

void SovaDeath(void)
{
    u16 y_position;
    u16 x_position;

    y_position = gCurrentSprite.y_position;
    x_position = gCurrentSprite.x_position;

    if (gCurrentSprite.status & SPRITE_STATUS_ON_VERTICAL_WALL)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            x_position -= 0x28;
        else
            x_position += 0x28;
    }
    else
    {
        if (gCurrentSprite.workVariable2 != 0x0)
            y_position += 0x28;
        else
            y_position -= 0x28;
    }

    SpriteUtilSpriteDeath(DEATH_NORMAL, y_position, x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
}

void Sova(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x154);
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
                    SovaInit();
                    break;
                case 0x8:
                    SovaInit();
                case 0x9:
                    SovaMove();
                    break;
                case 0xA:
                    SovaTurningAroundGFXUpdate();
                case 0xB:
                    SovaTurningAround();
                    break;
                case 0xE:
                    SovaBackOnGround();
                case 0xF:
                    SovaCheckBackOnGroundAnimEnded();
                    break;
                case 0x1E:
                    SovaStartFalling();
                case 0x1F:
                    SovaFalling();
                    break;
                default:
                    SovaDeath();
            }
        }
    }
}