#include "sprites_AI/squeept.h"
#include "macros.h"

#include "data/sprites/squeept.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"

/**
 * @brief 1eff4 | 24 | Initializes a squeept to be going up
 * 
 */
void SqueeptGoingUpInit(void)
{
    gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE + PIXEL_SIZE * 3);
    gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;

    gCurrentSprite.pOam = sSqueeptOam_GoingUp;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 1f018 | 24 | Initializes a squeept to be turning around
 * 
 */
void SqueeptTurningAroundInit(void)
{
    gCurrentSprite.hitboxTop = -QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;

    gCurrentSprite.pOam = sSqueeptOam_TurningAround;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 1f03c | 20 | Initializes a squeept to be going down
 * 
 */
void SqueeptGoingDownInit(void)
{
    gCurrentSprite.hitboxTop = 0;
    gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE + PIXEL_SIZE * 2;

    gCurrentSprite.pOam = sSqueeptOam_GoingDown;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 1f05c | 4c | Initializes a squeept sprite
 * 
 */
void SqueeptInit(void)
{
    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + QUARTER_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + QUARTER_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.yPosition += PIXEL_SIZE;

    // Save spawn Y
    gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
}

/**
 * @brief 1f0a8 | 28 | Initializes a squeept to be idle
 * 
 */
void SqueeptIdleInit(void)
{
    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.pose = SQUEEPT_POSE_IDLE;
    SqueeptGoingUpInit();

    // Timer before it checks for samus
    gCurrentSprite.work0 = 30;
}

/**
 * @brief 1f0d0 | 50 | Handles a squeept being idle
 * 
 */
void SqueeptIdle(void)
{
    u8 nsab;

    if (gCurrentSprite.work0 != 0)
    {
        gCurrentSprite.work0--;
        return;
    }

    // Detect samus
    nsab = SpriteUtilCheckSamusNearSpriteAboveBelow(BLOCK_SIZE * 8, BLOCK_SIZE * 6);
    if (nsab == NSAB_ABOVE)
    {
        // Set going up
        gCurrentSprite.pose = SQUEEPT_POSE_GOING_UP;
        gCurrentSprite.work3 = 0;
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    }
}

/**
 * @brief 1f120 | bc | Handles a squeept going up
 * 
 */
void SqueeptGoUp(void)
{
    u16 oldY;
    s32 movement;
    s32 newMovement;
    u8 offset;

    oldY = gCurrentSprite.yPosition;

    if (gCurrentSprite.yPositionSpawn - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE) > oldY)
    {
        // Check top left
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE),
            gCurrentSprite.xPosition - HALF_BLOCK_SIZE);

        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            SqueeptTurningAroundInit();
            gCurrentSprite.pose = SQUEEPT_POSE_TURNING_AROUND;
            return;
        }

        // Check top right
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE),
            gCurrentSprite.xPosition + HALF_BLOCK_SIZE);

        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            SqueeptTurningAroundInit();
            gCurrentSprite.pose = SQUEEPT_POSE_TURNING_AROUND;
            return;
        }
    }

    offset = gCurrentSprite.work3;
    movement = sSqueeptRisingMovement[offset];

    if (movement == SHORT_MAX)
    {
        SqueeptTurningAroundInit();
        gCurrentSprite.pose = SQUEEPT_POSE_TURNING_AROUND;
    }
    else
    {
        gCurrentSprite.work3++;
        gCurrentSprite.yPosition += movement;
    }

    if (SpriteUtilCheckOutOfRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_SMALL) &&
        gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        SoundPlay(SOUND_SQUEEPT_LEAVING_LAVA);
    }
}

/**
 * @brief 1f1dc | 28 | Handles a squeept turning around
 * 
 */
void SqueeptTurningAround(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set going down
        SqueeptGoingDownInit();
        gCurrentSprite.pose = SQUEEPT_POSE_GOING_DOWN;
        gCurrentSprite.work3 = 0;
    }
}

/**
 * @brief 1f204 | 84 | Handles a squeept going down
 * 
 */
void SqueeptGoDown(void)
{
    u16 oldY;
    s32 movement;
    s32 newMovement;
    u8 offset;

    oldY = gCurrentSprite.yPosition;
    offset = gCurrentSprite.work3;
    movement = sSqueeptFallingMovement[offset];

    if (movement == SHORT_MAX)
    {
        newMovement = sSqueeptFallingMovement[offset - 1];
        gCurrentSprite.yPosition += newMovement;
    }
    else
    {
        gCurrentSprite.work3++;
        gCurrentSprite.yPosition += movement;
    }

    if (SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_BIG) &&
        gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        SoundPlay(SOUND_SQUEEPT_ENTERING_LAVA);
    }

    if (gCurrentSprite.yPositionSpawn < gCurrentSprite.yPosition)
    {
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
        SqueeptIdleInit();
    }
}

/**
 * @brief  1f288 | 194 | Squeept AI
 * 
 */
void Squeept(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_SQUEEPT_DAMAGED);
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
            SqueeptInit();

        case SQUEEPT_POSE_IDLE_INIT:
            SqueeptIdleInit();

        case SQUEEPT_POSE_IDLE:
            SqueeptIdle();
            break;

        case SQUEEPT_POSE_GOING_UP:
            SqueeptGoUp();
            break;

        case SQUEEPT_POSE_TURNING_AROUND:
            SqueeptTurningAround();
            break;

        case SQUEEPT_POSE_GOING_DOWN:
            SqueeptGoDown();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
    }
}
