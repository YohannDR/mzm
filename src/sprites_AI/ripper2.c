#include "sprites_AI/ripper2.h"
#include "macros.h"

#include "data/sprites/ripper2.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/particle.h"
#include "constants/clipdata.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"

/**
 * @brief 1bfd8 | 7c | Initializes a ripper 2 sprite
 * 
 */
void Ripper2Init(void)
{
    gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE + PIXEL_SIZE);
    gCurrentSprite.hitboxBottom = PIXEL_SIZE * 2;
    gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE + PIXEL_SIZE * 2);
    gCurrentSprite.hitboxRight = (HALF_BLOCK_SIZE + PIXEL_SIZE * 2);

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);

    gCurrentSprite.pOam = sRipper2Oam_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.yPosition -= PIXEL_SIZE * 2;

    SpriteUtilChooseRandomXFlip();
    gCurrentSprite.pose = RIPPER2_POSE_MOVING_INIT;
}

/**
 * @brief 1c054 | 20 | Initializes a ripper 2 to be moving
 * 
 */
void Ripper2MovingInit(void)
{
    gCurrentSprite.pose = RIPPER2_POSE_MOVING;

    gCurrentSprite.pOam = sRipper2Oam_Moving;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;
}

/**
 * @brief 1c074 | 60 | Handles a ripper 2 moving
 * 
 */
void Ripper2Move(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition + (HALF_BLOCK_SIZE + PIXEL_SIZE * 3));

        if (gPreviousCollisionCheck != COLLISION_SOLID)
            gCurrentSprite.xPosition += PIXEL_SIZE * 2;
        else
            gCurrentSprite.pose = RIPPER2_POSE_TURNING_AROUND_INIT;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE * 3));

        if (gPreviousCollisionCheck == COLLISION_SOLID)
            gCurrentSprite.pose = RIPPER2_POSE_TURNING_AROUND_INIT;
        else
            gCurrentSprite.xPosition -= PIXEL_SIZE * 2;
    }
}

/**
 * @brief 1c0d4 | 38 | Initializes a ripper 2 to be turning around
 * 
 */
void Ripper2TurnAroundInit(void)
{
    gCurrentSprite.pose = RIPPER2_POSE_TURNING_AROUND_FIRST_PART;

    gCurrentSprite.pOam = sRipper2Oam_TurningAround;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_RIPPER2_TURNING_AROUND);
}

/**
 * @brief 1c10c | 38 | Handles the first part of a ripper 2 turning around
 * 
 */
void Ripper2TurnAroundPart1(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
        gCurrentSprite.pose = RIPPER2_POSE_TURNING_AROUND_SECOND_PART;

        gCurrentSprite.pOam = sRipper2Oam_TurningAroundPart2;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 1c144 | 1c | Handles the second part of a ripper 2 turning around
 * 
 */
void Ripper2TurnAroundPart2(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = RIPPER2_POSE_MOVING_INIT;
}

/**
 * @brief 1c160 | d8 | Ripper 2 AI
 * 
 */
void Ripper2(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_RIPPER2_DAMAGED);
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
            Ripper2Init();
            break;

        case RIPPER2_POSE_MOVING_INIT:
            Ripper2MovingInit();

        case RIPPER2_POSE_MOVING:
            Ripper2Move();
            break;

        case RIPPER2_POSE_TURNING_AROUND_INIT:
            Ripper2TurnAroundInit();

        case RIPPER2_POSE_TURNING_AROUND_FIRST_PART:
            Ripper2TurnAroundPart1();
            break;

        case RIPPER2_POSE_TURNING_AROUND_SECOND_PART:
            Ripper2TurnAroundPart2();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - (QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2),
                gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
    }
}
