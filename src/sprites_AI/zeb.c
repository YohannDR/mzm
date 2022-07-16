#include "zeb.h"
#include "../sprite_util.h"
#include "../globals.h"

void ZebInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x8;
    gCurrentSprite.hitboxBottomOffset = 0x14;
    gCurrentSprite.hitboxLeftOffset = -0x1C;
    gCurrentSprite.hitboxRightOffset = 0x1C;
    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
    gCurrentSprite.workVariable = 0x1;
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.spriteID][0x0];
    gCurrentSprite.yPosition -= 0x20;
    gCurrentSprite.xPosition += 0x20;
    gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
    gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
}

void ZebGFXInit(void)
{
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.pOam = zeb_oam_2cca2c;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
    gCurrentSprite.bg_priority = 0x2;
}

void ZebCheckSpawn(void)
{
    u16 samusX;
    u16 samusY;
    u16 spriteX;
    u16 spriteY;
    i32 offset;

    if (!SpriteUtilCheckHasDrops())
    {
        if (gCurrentSprite.workVariable != 0x0)
            gCurrentSprite.workVariable--;
        else
        {
            samusY = gSamusData.yPosition;
            samusX = gSamusData.xPosition;
            spriteY = gCurrentSprite.yPosition;
            spriteX = gCurrentSprite.xPosition;

            if (samusY <= (spriteY - 0x1E))
            {
                if (spriteX >= samusX)
                    offset = samusX - spriteX;
                else
                    offset = spriteX - samusX;
                
                if (offset > 0x24 && SpriteUtilCheckSamusNearSpriteAboveBelow(0x140, 0x140) == NSAB_ABOVE)
                {
                    gCurrentSprite.oamScaling = gSamusData.yPosition;
                    gCurrentSprite.pose = 0x23;
                    gCurrentSprite.timer = 0x2;
                    gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
                    SpriteUtilMakeSpriteFaceSamusXFlip();
                    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                        SoundPlay(0x144);
                }
            }
        }
    }
}

void ZebGoingUp(void)
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
        if (gCurrentSprite.oamScaling < gSamusData.yPosition && gSamusData.yPosition >= (i32)(gCurrentSprite.yPositionSpawn - 0x80))
            yPosition = gCurrentSprite.oamScaling;
        else
            yPosition = gSamusData.yPosition;

        if ((yPosition - 0x64) > gCurrentSprite.yPosition)
        {
            gCurrentSprite.pose = 0x25;
            gCurrentSprite.timer = 0xA;
            gCurrentSprite.pOam = zeb_oam_2cca54;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.bg_priority = 0x1;
        }
    }
}

void ZebReset(void)
{
    gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
    gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn;
    ZebGFXInit();
    gCurrentSprite.workVariable = 0x3C;
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.spriteID][0x0];
    gCurrentSprite.invicibilityStunFlashTimer = 0x0;
    gCurrentSprite.palette_row = 0x0;
    gCurrentSprite.frozenPaletteRowOffset = 0x0;
    gCurrentSprite.absolutePaletteRow = 0x0;
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.freezeTimer = 0x0;
}

void ZebMove(void)
{
    u8 timer;

    if (gCurrentSprite.timer != 0x0)
    {
        if (timer = gCurrentSprite.timer -= 0x1 == 0x0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                play_sound(0x145);
            gCurrentSprite.workVariable = timer;
        }
    }
    else
    {
        gCurrentSprite.workVariable++;
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            if ((i32)(gCurrentSprite.xPosition - gSamusData.xPosition) > 0x400 || gCurrentSprite.xPosition & 0x8000)
            {
                ZebReset();
                return;
            }
            gCurrentSprite.xPosition += 0xC;
        }
        else
        {
            if ((i32)(gSamusData.xPosition - gCurrentSprite.xPosition) > 0x400 || gCurrentSprite.xPosition & 0x8000)
            {
                ZebReset();
                return;
            }
            gCurrentSprite.xPosition -= 0xC;
        }
        if ((gCurrentSprite.workVariable & 0xF) == 0x0 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(0x145);
    }
}

void Zeb(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x146);
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
                    ZebInit();
                case 0x8:
                    ZebGFXInit();
                case 0x9:
                    ZebCheckSpawn();
                    break;
                case 0x23:
                    ZebGoingUp();
                    break;
                case 0x25:
                    ZebMove();
                    break;
                default:
                    SpriteUtilSpriteDeath(DEATH_RESPAWNING, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                    ZebReset();
            }
        }
    }
}