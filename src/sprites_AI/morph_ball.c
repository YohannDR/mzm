#include "morph_ball.h"
#include "../sprite_util.h"
#include "../sprite.h"
#include "../globals.h"

void MorphBallInit(void)
{
    if (gEquipment.suitMisc & SMF_MORPH_BALL)
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
        gCurrentSprite.hitboxTopOffset = -0x1C;
        gCurrentSprite.hitboxBottomOffset = 0x1C;
        gCurrentSprite.hitboxLeftOffset = -0x1C;
        gCurrentSprite.hitboxRightOffset = 0x1C;
        gCurrentSprite.drawDistanceTopOffset = 0x8;
        gCurrentSprite.drawDistanceBottomOffset = 0x8;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
        gCurrentSprite.pOam = morph_ball_oam_2b2ba8;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;
        gCurrentSprite.health = 0x1;
        gCurrentSprite.yPosition -= 0x20;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.drawOrder = 0x3;
        SpriteSpawnSecondary(SSPRITE_MORPH_BALL_OUTSIDE, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

void MorphBallGet(void)
{
    if ((gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING) != 0x0)
    {
        gPreventMovementTimer = 0x3E8;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        gCurrentSprite.pose = 0x23;
        gCurrentSprite.timer = 0x0;
        gEquipment.suitMisc |= SMF_MORPH_BALL;
        SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, 0x10, 0xC, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

void MorphBallFlashAnim(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if ((gCurrentSprite.timer & 0x1) == 0x0)
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    if (gPreventMovementTimer < 0x3E7)
        gCurrentSprite.status = 0x0;
}

void MorphBallOutsideInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;
    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
    gCurrentSprite.pOam = morph_ball_outside_oam_2b2bd0;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawOrder = 0x2;
    gCurrentSprite.pose = 0x9;
}

void MorphBallOutsideFlashAnim(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    gCurrentSprite.status = gSpriteData[ramSlot].status;
    if ((gSpriteData[ramSlot].properties & SP_ALWAYS_ACTIVE) != 0x0)
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
}

void MorphBall(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            MorphBallInit();
            break;
        case 0x9:
            MorphBallGet();
            break;
        case 0x23:
            MorphBallFlashAnim();
    }
}

void MorphBallOutside(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            MorphBallOutsideInit();
        case 0x9:
            MorphBallOutsideFlashAnim();
    }
}