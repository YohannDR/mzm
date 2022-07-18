#include "zebbo.h"
#include "../sprite_util.h"
#include "../sprite.h"
#include "../globals.h"

void ZebboInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x18;
    gCurrentSprite.hitboxBottomOffset = 0x18;
    gCurrentSprite.hitboxLeftOffset = -0x18;
    gCurrentSprite.hitboxRightOffset = 0x18;
    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
    gCurrentSprite.workVariable = 0x1;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0x0];
    gCurrentSprite.yPosition -= 0x20;
    gCurrentSprite.xPosition += 0x20;
    gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
    gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
}

void ZebboGFXInit(void)
{
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.pOam = zebbo_oam_2e7098;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
    gCurrentSprite.bg_priority = 0x2;
}

void ZebbosSpawn(void)
{

}

void ZebooGoingUp(void)
{
    u16 yPosition;

    gCurrentSprite.yPosition -= 0x8;
    if (gCurrentSprite.timer != 0x0)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    }
    else
    {
        if (gCurrentSprite.oamScaling < gSamusData.yPosition && gSamusData.yPosition > (i32)(gCurrentSprite.yPositionSpawn - 0x80))
            yPosition = gCurrentSprite.oamScaling;
        else
            yPosition = gSamusData.yPosition;

        if ((i32)(yPosition - 0x64) > gCurrentSprite.yPosition)
        {
            gCurrentSprite.pose = 0x35;
            gCurrentSprite.timer = 0xA;
            gCurrentSprite.pOam = zebbo_oam_2e70c0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.bg_priority = 0x1;
        }
    }
}

void ZebboRespawning(void)
{
    if (gCurrentSprite.spriteID == PSPRITE_ZEBBO_GREEN_FOLLOWER)
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn;
        ZebboGFXInit();
        gCurrentSprite.workVariable = 0x3C;
        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0x0];
        gCurrentSprite.invicibilityStunFlashTimer = 0x0;
        gCurrentSprite.palette_row = 0x0;
        gCurrentSprite.frozenPaletteRowOffset = 0x0;
        gCurrentSprite.absolutePaletteRow = 0x0;
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        gCurrentSprite.freezeTimer = 0x0;
    }
}

void ZebboMove(void)
{

}

void Zebbo(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x164);
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
                    ZebboInit();
                case 0x8:
                    ZebboGFXInit();
                case 0x9:
                    ZebbosSpawn();
                    break;
                case 0x23:
                    ZebooGoingUp();
                    break;
                case 0x25:
                    ZebboMove();
                    break;
                default:
                    SpriteUtilSpriteDeath(DEATH_RESPAWNING, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                    ZebboRespawning();
            }
        }
    }
}