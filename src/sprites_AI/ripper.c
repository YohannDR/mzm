#include "sprites_AI/ripper.h"
#include "data/data.h"
#include "data/sprites/ripper.c"
#include "data/sprite_data.c"
#include "globals.h"

/**
 * @brief 1bd8c | 70 | Initializes a ripper sprite
 * 
 */
void RipperInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x24;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = -0x20;
    gCurrentSprite.hitboxRightOffset = 0x20;

    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

    gCurrentSprite.pOam = sRipperOAM_Moving;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.yPosition -= 0x8;
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
    gCurrentSprite.pOam = sRipperOAM_Moving;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
}

/**
 * @brief 1be1c | 6c | Handles a ripper moving
 * 
 */
void RipperMove(void)
{
    u16 speed;

    if (gCurrentSprite.spriteID == PSPRITE_RIPPER_PURPLE)
        speed = 0x4;
    else
        speed = 0x2;

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        // Move right
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition + 0x24);
        if (gPreviousCollisionCheck != 0x11)
            gCurrentSprite.xPosition += speed;
        else
            gCurrentSprite.pose = RIPPER_POSE_TURNING_AROUND_INIT;
    }
    else
    {
        // Move left
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition - 0x24);
        if (gPreviousCollisionCheck == 0x11)
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
    gCurrentSprite.pOam = sRipperOAM_TurningAround;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
}

/**
 * @brief 1bea8 | 38 | Handles the first part of a ripper turning around
 * 
 */
void RipperTurnAroundFirstPart(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.status ^= SPRITE_STATUS_XFLIP;
        gCurrentSprite.pose = RIPPER_POSE_TURNING_AROUND_SECOND_PART;
        gCurrentSprite.pOam = sRipperOAM_TurningAroundPart2;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
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
            SoundPlayNotAlreadyPlaying(0x149);
    }

    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;
        switch (gCurrentSprite.pose)
        {
            case 0x0:
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
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - 0x18, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
        }
    }
}