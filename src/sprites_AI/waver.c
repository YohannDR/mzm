#include "sprites_AI/waver.h"
#include "macros.h"

#include "data/sprites/waver.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"

/**
 * @brief 2483c | 68 | Initializes a waver sprite
 * 
 */
void WaverInit(void)
{
    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

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
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.hitboxRight + gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.xPosition += xSpeed;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.hitboxLeft + gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.xPosition -= xSpeed;
        else
            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
    }

    // Move vertically
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.hitboxTop + gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.yPosition -= ySpeed;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.hitboxBottom + gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.yPosition += ySpeed;
        else
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
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
            SoundPlayNotAlreadyPlaying(SOUND_WAVER_DAMAGED);
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
