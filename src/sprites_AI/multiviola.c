#include "multiviola.h"
#include "../sprite_util.h"
#include "../globals.h"

void MultiviolaInit(void)
{
    gCurrentSprite.drawDistanceTopOffset = 0x20;
    gCurrentSprite.drawDistanceBottomOffset = 0xC;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
    gCurrentSprite.hitboxTopOffset = -0x20;
    gCurrentSprite.hitboxBottomOffset = 0x20;
    gCurrentSprite.hitboxLeftOffset = -0x20;
    gCurrentSprite.hitboxRightOffset = 0x20;
    gCurrentSprite.pOam = multiviola_oam_2d0520;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = gCurrentSprite.primarySpriteRAMSlot << 0x1;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0x0];
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
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
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.hitboxRightOffset + gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.xPosition += 0x3;
        else
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            is_bouncing = 0x1;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.hitboxLeftOffset + gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.xPosition -= 0x3;
        else
        {
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            is_bouncing = 0x1;
        }
    }

    if ((gCurrentSprite.status & SPRITE_STATUS_ON_VERTICAL_WALL) != 0x0)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.hitboxTopOffset + gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.yPosition -= y_movement;
        else
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
            is_bouncing++;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.hitboxBottomOffset + gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.yPosition += y_movement;
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

    if (gCurrentSprite.freezeTimer != 0x0)
    {
        SpriteUtilUpdateFreezeTimer();
        SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent(SSPRITE_MULTIVIOLA_UNUSED, gCurrentSprite.primarySpriteRAMSlot);
    }
    else
    {
        if (!SpriteUtilIsSpriteStunned())
        {
            switch (gCurrentSprite.pose)
            {
                default:
                    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
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