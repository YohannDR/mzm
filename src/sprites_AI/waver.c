#include "sprites_AI/waver.h"
#include "macros.h"

#include "data/sprites/waver.h"
#include "data/sprite_data.h"

#include "constants/particle.h"
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
    gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    gCurrentSprite.hitboxTopOffset = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxBottomOffset = HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxLeftOffset = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxRightOffset = HALF_BLOCK_SIZE;

    gCurrentSprite.pOam = sWaverOAM;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
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
    u16 ySpeed;
    u16 xSpeed;

    ySpeed = PIXEL_SIZE / 2;
    xSpeed = PIXEL_SIZE;

    // Move horizontaly
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.hitboxRightOffset + gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.xPosition += xSpeed;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.hitboxLeftOffset + gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.xPosition -= xSpeed;
        else
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
    }

    // Move vertically
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.hitboxTopOffset + gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.yPosition -= ySpeed;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.hitboxBottomOffset + gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.yPosition += ySpeed;
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

    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    if (SpriteUtilIsSpriteStunned())
        return;

    switch (gCurrentSprite.pose)
    {
        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case SPRITE_POSE_UNINITIALIZED:
            WaverInit();
            break;

        case WAVER_POSE_MOVING:
            WaverMove();
    }
}
