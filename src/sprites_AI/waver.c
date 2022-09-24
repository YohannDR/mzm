#include "sprites_AI/waver.h"
#include "constants/particle.h"
#include "data/sprites/waver.h"
#include "data/sprite_data.h"
#include "constants/clipdata.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "structs/sprite.h"

/**
 * @brief 2483c | 68 | Initializes a waver sprite
 * 
 */
void WaverInit(void)
{
    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

    gCurrentSprite.hitboxTopOffset = -0x20;
    gCurrentSprite.hitboxBottomOffset = 0x20;
    gCurrentSprite.hitboxLeftOffset = -0x20;
    gCurrentSprite.hitboxRightOffset = -0x20;

    gCurrentSprite.pOam = sWaverOAM;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    SpriteUtilMakeSpriteFaceSamusXFlip();
    gCurrentSprite.pose = WAVER_POSE_MOVING;
}

/**
 * @brief 248a4 | e0 | Handles a waver moving
 * 
 */
void WaverMove(void)
{
    u16 speed;

    speed = 0x2;
    // Move horizontaly
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.hitboxRightOffset + gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.xPosition += 0x4;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.hitboxLeftOffset + gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.xPosition -= 0x4;
        else
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
    }

    // Move vertically
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.hitboxTopOffset + gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.yPosition -= speed;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.hitboxBottomOffset + gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.yPosition += speed;
        else
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
    }
}

/**
 * @brief 2498c | 84 | Waver AI
 * 
 */
void Waver(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x177);
    }

    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;
        switch (gCurrentSprite.pose)
        {
            default:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                break;
            case 0x0:
                WaverInit();
                break;
            case WAVER_POSE_MOVING:
                WaverMove();
        }
    }
}