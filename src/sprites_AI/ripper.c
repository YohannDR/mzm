#include "sprites_AI/ripper.h"
#include "macros.h"

#include "data/sprites/ripper.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/clipdata.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"

/**
 * @brief 1bd8c | 70 | Initializes a ripper sprite
 * 
 */
void RipperInit(void)
{
    gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE + PIXEL_SIZE);
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    gCurrentSprite.pOam = sRipperOam_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.yPosition -= PIXEL_SIZE * 2;

    SpriteUtilChooseRandomXFlip();
    gCurrentSprite.pose = RIPPER_POSE_MOVING_INIT;
}

/**
 * @brief 1bdfc | 20 | Initializes a ripper to be moving
 * 
 */
void RipperMovingInit(void)
{
    gCurrentSprite.pose = RIPPER_POSE_MOVING;

    gCurrentSprite.pOam = sRipperOam_Moving;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;
}

/**
 * @brief 1be1c | 6c | Handles a ripper moving
 * 
 */
void RipperMove(void)
{
    u16 speed;

    if (gCurrentSprite.spriteId == PSPRITE_RIPPER_PURPLE)
        speed = 4;
    else
        speed = 2;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        // Move right
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition + (HALF_BLOCK_SIZE + PIXEL_SIZE));

        if (gPreviousCollisionCheck != COLLISION_SOLID)
            gCurrentSprite.xPosition += speed;
        else
            gCurrentSprite.pose = RIPPER_POSE_TURNING_AROUND_INIT;
    }
    else
    {
        // Move left
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE));

        if (gPreviousCollisionCheck == COLLISION_SOLID)
            gCurrentSprite.pose = RIPPER_POSE_TURNING_AROUND_INIT;
        else
            gCurrentSprite.xPosition -= speed;
    }
}

/**
 * @brief 1be88 | 20 | Initializes a ripper to be turning around
 * 
 */
void RipperTurnAroundInit(void)
{
    gCurrentSprite.pose = RIPPER_POSE_TURNING_AROUND_FIRST_PART;

    gCurrentSprite.pOam = sRipperOam_TurningAround;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;
}

/**
 * @brief 1bea8 | 38 | Handles the first part of a ripper turning around
 * 
 */
void RipperTurnAroundFirstPart(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
        gCurrentSprite.pose = RIPPER_POSE_TURNING_AROUND_SECOND_PART;

        gCurrentSprite.pOam = sRipperOam_TurningAroundPart2;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 1bee0 | 1c | Handles the second part of a ripper turning around
 * 
 */
void RipperTurnAroundSecondPart(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = RIPPER_POSE_MOVING_INIT;
}

/**
 * @brief 1befc | dc | Ripper AI
 * 
 */
void Ripper(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_RIPPER_DAMAGED);
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
        case SPRITE_POSE_UNINITIALIZED:
            RipperInit();
            break;
            
        case RIPPER_POSE_MOVING_INIT:
            RipperMovingInit();

        case RIPPER_POSE_MOVING:
            RipperMove();
            break;
            
        case RIPPER_POSE_TURNING_AROUND_INIT:
            RipperTurnAroundInit();

        case RIPPER_POSE_TURNING_AROUND_FIRST_PART:
            RipperTurnAroundFirstPart();
            break;
            
        case RIPPER_POSE_TURNING_AROUND_SECOND_PART:
            RipperTurnAroundSecondPart();
            break;
            
        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - (QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2),
                gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
    }
}
