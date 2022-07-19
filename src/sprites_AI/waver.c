#include "waver.h"
#include "../sprite_util.h"
#include "../globals.h"

void WaverInit(void)
{
    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
    gCurrentSprite.hitboxTopOffset = -0x20;
    gCurrentSprite.hitboxBottomOffset = 0x20;
    gCurrentSprite.hitboxLeftOffset = -0x20;
    gCurrentSprite.hitboxRightOffset = -0x20;
    gCurrentSprite.pOam = waver_oam_2d88ac;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0x0];
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    SpriteUtilMakeSpriteFaceSamusXFlip();
    gCurrentSprite.pose = 0x9;
}

void WaverMove(void)
{
    u16 speed;

    speed = 0x2;
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.hitboxRightOffset + gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.xPosition += 0x4;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.hitboxLeftOffset + gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.xPosition -= 0x4;
        else
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.hitboxTopOffset + gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.yPosition -= speed;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.hitboxBottomOffset + gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == 0x0)
            gCurrentSprite.yPosition += speed;
        else
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
    }
}

void Waver(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x177);
    }

    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (!SpriteUtilIsSpriteStunned())
        {
            switch (gCurrentSprite.pose)
            {
                default:
                    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                    break;
                case 0x0:
                    WaverInit();
                    break;
                case 0x9:
                    WaverMove();
            }
        }
    }
}