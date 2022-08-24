#include "sova.h"
#include "../../data/data.h"
#include "../globals.h"

u8 SovaCheckCollidingWithAir(void)
{
    u8 colliding;

    colliding = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x20, gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck != 0x0)
                colliding = FALSE;
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + 0x20, gCurrentSprite.xPosition);
                if (gPreviousCollisionCheck == 0x0)
                    colliding = TRUE;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x20, gCurrentSprite.xPosition - 0x4);
            if (gPreviousCollisionCheck != 0x0)
                colliding = FALSE;
            else
            {                
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + 0x20, gCurrentSprite.xPosition - 0x4);
                if (gPreviousCollisionCheck == 0x0)
                    colliding = TRUE;
            }
        }
    }
    else
    {
        if (gCurrentSprite.workVariable2 != 0x0)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x4, gCurrentSprite.xPosition - 0x20);
            if (gPreviousCollisionCheck != 0x0)
                colliding = FALSE;
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x4, gCurrentSprite.xPosition + 0x20);
                if (gPreviousCollisionCheck == 0x0)
                    colliding = TRUE;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - 0x20);
            if (gPreviousCollisionCheck != 0x0)
                colliding = FALSE;
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + 0x20);
                if (gPreviousCollisionCheck == 0x0)
                    colliding = TRUE;
            }
        }
    }

    return colliding;
}

void SovaHitboxUpdate(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            gCurrentSprite.hitboxTopOffset = -0x1C;
            gCurrentSprite.hitboxBottomOffset = 0x1C;
            gCurrentSprite.hitboxLeftOffset = -0x34;
            gCurrentSprite.hitboxRightOffset = 0x4;
        }
        else
        {
            gCurrentSprite.hitboxTopOffset = -0x1C;
            gCurrentSprite.hitboxBottomOffset = 0x1C;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x34;
        }
    }
    else
    {
        if (gCurrentSprite.workVariable2 != 0x0)
        {
            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x34;
        }
        else
        {
            gCurrentSprite.hitboxTopOffset = -0x34;
            gCurrentSprite.hitboxBottomOffset = 0x4;
        }
        gCurrentSprite.hitboxLeftOffset = -0x1C;
        gCurrentSprite.hitboxRightOffset = 0x1C;
    }
}

void SovaGFXUpdate(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.pOam = sova_oam_2cfc78;
        else
            gCurrentSprite.pOam = sova_oam_2cfc40;
    }
    else
    {
        if (gCurrentSprite.workVariable2 != 0x0)
            gCurrentSprite.pOam = sova_oam_2cfcb0;
        else
            gCurrentSprite.pOam = sova_oam_2cfb98;
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    }

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

void SovaInit(void)
{
    gCurrentSprite.workVariable2 = 0x0;
    gCurrentSprite.pose = 0x9;
    SpriteUtilChooseRandomXDirection();
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousCollisionCheck & 0xF0)
        gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x44, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & 0xF0)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
            gCurrentSprite.yPosition -= 0x40;
            gCurrentSprite.workVariable2 = 0x1;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x20, gCurrentSprite.xPosition - 0x24);
            if (gPreviousCollisionCheck & 0xF0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
                gCurrentSprite.yPosition -= 0x20;
                gCurrentSprite.xPosition -= 0x20;
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x20, gCurrentSprite.xPosition + 0x20);
                if ((gPreviousCollisionCheck & 0xF0) == 0x0)
                {
                    gCurrentSprite.status = gPreviousCollisionCheck & 0xF0;
                    return;
                }
                else
                {
                    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
                    gCurrentSprite.status |= SPRITE_STATUS_XFLIP;                    
                    gCurrentSprite.yPosition -= 0x20;
                    gCurrentSprite.xPosition += 0x20;
                }
            }
        }
    }

    if (!(gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2))
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    }

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    SovaGFXUpdate();
    SovaHitboxUpdate();
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
    if (gCurrentSprite.spriteID == PSPRITE_SOVA_ORANGE)
    {
        gCurrentSprite.absolutePaletteRow = 0x1;
        gCurrentSprite.paletteRow = 0x1;
    }
}

void SovaIdleInit(void)
{
    SovaGFXUpdate();
    gCurrentSprite.pose = 0x9;
}

void SovaMove(void)
{
    u16 speed;
    u8 turning;

    switch (gCurrentSprite.currentAnimationFrame)
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

    if (gCurrentSprite.spriteID == PSPRITE_SOVA_ORANGE && speed)
        speed++;

    turning = FALSE;

    if (SovaCheckCollidingWithAir() )
    {
        gCurrentSprite.pose = 0x1E;
        return;
    }

    if (sprite_util_is_screen_on_screen_and_screen_shake())
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2 || gCurrentSprite.workVariable2)
            gCurrentSprite.pose = 0x1E;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            if (gCurrentSprite..status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
                if ((gPreviousCollisionCheck & 0xF0) == 0x0)
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + 0x1C, gCurrentSprite.xPosition - 0x4);
                    if (gPreviousCollisionCheck != 0x11)
                    {
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.workVariable = 0x5;
                    }
                    else
                        gCurrentSprite.yPosition += speed;
                    
                    if (turning)
                        gCurrentSprite.pose = 0xA;
                    return;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x4, gCurrentSprite.xPosition);
                if ((gPreviousCollisionCheck & 0xF0) == 0x0)
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x1C, gCurrentSprite.xPosition - 0x4);
                    if (gPreviousCollisionCheck != 0x11)
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    else
                    {
                        gCurrentSprite.yPosition -= speed;
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
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - 0x4);
                if ((gPreviousCollisionCheck & 0xF0) == 0x0)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + 0x1C, gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck != 0x11)
                    {
                        gCurrentSprite.yPosition += speed;
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
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x4, gCurrentSprite.xPosition - 0x4);
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
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - 0x4);
                    if (gPreviousCollisionCheck != 0x11)
                    {
                        gCurrentSprite.yPosition -= speed;
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
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x4, gCurrentSprite.xPosition);
            if ((gPreviousCollisionCheck & 0xF) == 0x0)
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + 0x1C);
                if (gPreviousCollisionCheck != 0x11)
                {
                    gCurrentSprite.xPosition += speed;
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
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x4, gCurrentSprite.xPosition - 0x4);
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
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - 0x1C);
                if (gPreviousCollisionCheck != 0x11)
                {
                    gCurrentSprite.xPosition -= speed;
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
            if (gCurrentSprite.pOam != sova_oam_2cfb98)
            {
                gCurrentSprite.pOam = sova_oam_2cfb98;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                    gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
                else
                    gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            }

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
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
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x4, gCurrentSprite.xPosition + 0x1C);
                    if (gPreviousCollisionCheck != 0x11)
                    {
                        gCurrentSprite.xPosition += speed;
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
                    if (gCurrentSprite.pOam != sova_oam_2cfbd0)
                    {
                        gCurrentSprite.pOam = sova_oam_2cfbd0;
                        gCurrentSprite.animationDurationCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
                    }

                    speed = (speed << 0x1) / 0x3;
                    gCurrentSprite.xPosition += speed;

                    if (turning)
                        gCurrentSprite.pose = 0xA;
                    return;
                }
                else
                {
                    if (gCurrentSprite.pOam != sova_oam_2cfc08)
                    {
                        gCurrentSprite.pOam = sova_oam_2cfc08;
                        gCurrentSprite.animationDurationCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
                    }
                    gCurrentSprite.xPosition += speed;

                    if (turning)
                        gCurrentSprite.pose = 0xA;
                    return;
                }
            }
            else
            {
                if (gPreviousVerticalCollisionCheck == 0x3 || gPreviousVerticalCollisionCheck == 0x5)
                {
                    if (gCurrentSprite.pOam != sova_oam_2cfc08)
                    {
                        gCurrentSprite.pOam = sova_oam_2cfc08;
                        gCurrentSprite.animationDurationCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
                    }
                    gCurrentSprite.xPosition -= speed;
                }
                else
                {
                    if (gCurrentSprite.pOam != sova_oam_2cfbd0)
                    {
                        gCurrentSprite.pOam = sova_oam_2cfbd0;
                        gCurrentSprite.animationDurationCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
                    }
                    speed = (speed << 0x1) / 0x3;
                    gCurrentSprite.xPosition -= speed;

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
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    switch (gCurrentSprite.workVariable)
    {
        case 0x0:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sova_oam_2cfce8;
            else
                gCurrentSprite.pOam = sova_oam_2cfd28;

            status &= ~SPRITE_STATUS_XFLIP;
            status &= ~SPRITE_STATUS_FACING_DOWN;
            break;

        case 0x1:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sova_oam_2cfce8;
            else
                gCurrentSprite.pOam = sova_oam_2cfd28;

            status |= SPRITE_STATUS_XFLIP;
            status &= ~SPRITE_STATUS_FACING_DOWN;
            break;

        case 0x2:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sova_oam_2cfd28;
            else
                gCurrentSprite.pOam = sova_oam_2cfce8;

            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            return;

        case 0x3:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sova_oam_2cfd28;
            else
                gCurrentSprite.pOam = sova_oam_2cfce8;

            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            return;

        case 0x4:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sova_oam_2cfd48;
            else
                gCurrentSprite.pOam = sova_oam_2cfd08;
            
            status &= ~SPRITE_STATUS_XFLIP;
            status &= ~SPRITE_STATUS_FACING_DOWN;
            break;

        case 0x5:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sova_oam_2cfd08;
            else
                gCurrentSprite.pOam = sova_oam_2cfd48;

            status |= SPRITE_STATUS_XFLIP;
            status &= ~SPRITE_STATUS_FACING_DOWN;
            break;

        case 0x6:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sova_oam_2cfd48;
            else
                gCurrentSprite.pOam = sova_oam_2cfd08;

            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            return;

        case 0x7:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sova_oam_2cfd08;
            else
                gCurrentSprite.pOam = sova_oam_2cfd48;
            
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            return;
    }

    gCurrentSprite.status = status;
}

void SovaTurningAround(void)
{
    if (!SpriteUtilCheckEndCurrentSpriteAnim())
        return;
    
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
    gCurrentSprite.workVariable2 = 0x0;

    switch (gCurrentSprite.workVariable)
    {
        case 0x0:
            if ((gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT) == 0x0)
            {
                gCurrentSprite.yPosition -= 0x18;
                gCurrentSprite.xPosition &= 0xFFC0;
            }
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            break;

        case 0x1:
            if ((gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT) == 0x0)
            {
                gCurrentSprite.yPosition -= 0x1C;
                gCurrentSprite.xPosition = (gCurrentSprite.xPosition & BLOCK_POSITION_FLAG) + 0x40;
            }
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            break;

        case 0x2:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition += 0x18;
                gCurrentSprite.xPosition &= 0xFFC0;
            }
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            break;

        case 0x3:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition += 0x1C;
                gCurrentSprite.xPosition = (gCurrentSprite.xPosition & BLOCK_POSITION_FLAG) + 0x40;
            }
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            break;

        case 0x4:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.xPosition += 0x1C;
                gCurrentSprite.yPosition = (gCurrentSprite.yPosition & BLOCK_POSITION_FLAG) + 0x40;
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            }
            else
            {
                gCurrentSprite.yPosition &= 0xFFC0;
                gCurrentSprite.status & ~(SPRITE_STATUS_XFLIP);
            }
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
            break;

        case 0x5:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition &= 0xFFC0;
                gCurrentSprite.status & ~(SPRITE_STATUS_XFLIP);
            }
            else
            {
                gCurrentSprite.xPosition -= 0x1C;
                gCurrentSprite.yPosition = (gCurrentSprite.yPosition & BLOCK_POSITION_FLAG) + 0x40;
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            }
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
            break;

        case 0x6:
            if ((gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN) == 0x0)
            {
                gCurrentSprite.yPosition &= 0xFFC0;
                gCurrentSprite.xPosition += 0x18;
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;

            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
            gCurrentSprite.workVariable2 = 0x1;
            break;

        case 0x7:
            if ((gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT) == 0x0)
            {
                gCurrentSprite.yPosition &= 0xFFC0;
                gCurrentSprite.xPosition -= 0x1C;
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
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
    gCurrentSprite.pOam = sova_oam_falling_2cfd68;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    SpriteUtilChooseRandomXFlip();
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        status |= SPRITE_STATUS_XFLIP;
    else
        status &= ~SPRITE_STATUS_XFLIP;
}

void SovaCheckBackOnGroundAnimEnded(void)
{
    if (SovaCheckCollidingWithAir()  != 0x0)
        gCurrentSprite.pose = 0x1E;
    else
    {
        if (SpriteUtilCheckNearEndCurrentSpriteAnim())
            gCurrentSprite.pose = 0x8;
    }
}

void SovaStartFalling(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            gCurrentSprite.xPosition -= 0x20;
        else
            gCurrentSprite.xPosition += 0x20;
    }
    else if (gCurrentSprite.workVariable2 != 0x0)
        gCurrentSprite.yPosition += 0x28;

    gCurrentSprite.pose = 0x1F;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.workVariable2 = 0x0;
    status &= ~(SPRITE_STATUS_XFLIP | SPRITE_STATUS_FACING_DOWN | SPRITE_STATUS_UNKNOWN2);
    SovaHitboxUpdate();
    gCurrentSprite.pOam = sova_oam_falling_2cfd68;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

void SovaFalling(void)
{
    u16 oldY;
    i16 movement;
    u16 offset;
    u32 new_y;
    u32 block;

    oldY = gCurrentSprite.yPosition;
    offset = gCurrentSprite.arrayOffset;
    movement = sSpritesFallingSpeed_2b0d04[offset];
    if (movement == SPRITE_ARRAY_TERMINATOR)
    {
        movement = sSpritesFallingSpeed_2b0d04[offset - 0x1];
        new_y = oldY + movement;
    }
    else
    {
        gCurrentSprite.arrayOffset++;
        new_y = gCurrentSprite.yPosition + movement;
    }

    gCurrentSprite.yPosition = new_y;
    block = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck)
    {
        gCurrentSprite.yPosition = block;
        SovaBackOnGround();
    }
    else
        SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_BIG);
}

void SovaDeath(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            xPosition -= 0x28;
        else
            xPosition += 0x28;
    }
    else
    {
        if (gCurrentSprite.workVariable2 != 0x0)
            yPosition += 0x28;
        else
            yPosition -= 0x28;
    }

    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
}

void Sova(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x154);
    }

    if (gCurrentSprite.freezeTimer != 0x0)
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
                    SovaIdleInit();
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