#include "Ripper2.h"
#include "../sprite_util.h"
#include "../../data/data.h"
#include "../globals.h"

void Ripper2Init(void)
{
    gCurrentSprite.hitboxTopOffset = -0x24;
    gCurrentSprite.hitboxBottomOffset = 0x8;
    gCurrentSprite.hitboxLeftOffset = -0x28;
    gCurrentSprite.hitboxRightOffset = 0x28;
    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x28;
    gCurrentSprite.pOam = ripper2_oam_2cc458;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.spriteID][0x0];
    gCurrentSprite.yPosition -= 0x8;
    SpriteUtilChooseRandomXFlip();
    gCurrentSprite.pose = 0x8;
}

void Ripper2GFXInit(void)
{
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.pOam = ripper2_oam_2cc458;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
}

void Ripper2Move(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition + 0x2C);
        if (gPreviousCollisionCheck != 0x11)
            gCurrentSprite.xPosition += 0x8;
        else
            gCurrentSprite.pose = 0xA;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition - 0x2C);
        if (gPreviousCollisionCheck == 0x11)
            gCurrentSprite.pose = 0xA;
        else
            gCurrentSprite.xPosition -= 0x8;
    }
}

void Ripper2TurnAroundGFXInit(void)
{
    gCurrentSprite.pose = 0xB;
    gCurrentSprite.pOam = ripper2_oam_2cc480;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        unk_2b20(0x267);
}

void Ripper2TurnAroundBegin(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.status ^= SPRITE_STATUS_XFLIP;
        gCurrentSprite.pose = 0xC;
        gCurrentSprite.pOam = ripper2_oam_2cc498;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
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

    if (gCurrentSprite.freezeTimer != 0x0)
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
                    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - 0x18, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
        }
    }
}