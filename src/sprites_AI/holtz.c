#include "sprites_AI/holtz.h"
#include "macros.h"

#include "data/sprites/holtz.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 3830c | cc | Handles the Y movement of a holtz
 * 
 * @param movement Y movement
 * @return u8 1 if colliding with solid, 0 otherwise
 */
u8 HoltzYMovement(u16 movement)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        // Going down
        // Middle block
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        // Left block
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition - 0x30);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        // Right block
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition + 0x30);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.yPosition += movement;
        return FALSE;
    }
    else
    {
        // Going up
        // Check on left
        // Middle left block
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HOLTZ_SIZE, gCurrentSprite.xPosition - 0x30);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            // Far left block
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HOLTZ_SIZE, gCurrentSprite.xPosition - 0x70);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                return TRUE;
        }

        // Check on right
        // Middle right block
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HOLTZ_SIZE, gCurrentSprite.xPosition + 0x30);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            // Far right block
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HOLTZ_SIZE, gCurrentSprite.xPosition + 0x70);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                return TRUE;
        }

        gCurrentSprite.yPosition -= movement;
        return FALSE;
    }
}

/**
 * @brief 383d8 | 8c | Handles the X movement of a holtz
 * 
 * @param movement X movement
 * @return u8 1 if colliding with solid, 0 otherwise
 */
u8 HoltzXMovement(u16 movement)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE), gCurrentSprite.xPosition + BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;


        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + (HALF_BLOCK_SIZE), gCurrentSprite.xPosition + BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.xPosition += movement;
        return FALSE;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE), gCurrentSprite.xPosition - BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;


        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + (HALF_BLOCK_SIZE), gCurrentSprite.xPosition - BLOCK_SIZE);
        if (gPreviousCollisionCheck != COLLISION_SOLID)
        {
            gCurrentSprite.xPosition -= movement;            
            return FALSE;
        }
        else
            return TRUE;
    }
}

/**
 * @brief 38518 | 70 | Initializes a holtz sprite
 * 
 */
void HoltzInit(void)
{
    SpriteUtilMakeSpriteFaceSamusDirection();
    gCurrentSprite.drawDistanceTop = 0xC;
    gCurrentSprite.drawDistanceBottom = 0x18;
    gCurrentSprite.drawDistanceHorizontal = 0x18;

    gCurrentSprite.hitboxTop = -0x20;
    gCurrentSprite.hitboxBottom = 0x20;
    gCurrentSprite.hitboxLeft = -0x28;
    gCurrentSprite.hitboxRight = 0x28;

    gCurrentSprite.pOam = sHoltzOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.pose = HOLTZ_POSE_IDLE_INIT;
    gCurrentSprite.work3 = 0x0;
}

/**
 * @brief 384dc | 3c | Initializes a holtz to be idle
 * 
 */
void HoltzIdleInit(void)
{
    gCurrentSprite.pose = HOLTZ_POSE_IDLE;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    // Set OAM based on samus position
    if ((s32)(gSamusData.yPosition - 0x48) < gCurrentSprite.yPosition)
        gCurrentSprite.pOam = sHoltzOAM_IdleAware;
    else
        gCurrentSprite.pOam = sHoltzOAM_Idle;
}

/**
 * @brief 38518 | 70 | Handles a holtz being idle
 * 
 */
void HoltzIdle(void)
{
    s32 movement;
    u8 offset;
    u8 nslr;

    // Y idle movement
    offset = gCurrentSprite.work3;
    movement = sHoltzIdleYVelocity[offset];
    if (movement == SHORT_MAX)
    {
        movement = sHoltzIdleYVelocity[0]; // 0
        offset = 0x0;
    }
    gCurrentSprite.work3 = offset + 0x1;
    gCurrentSprite.yPosition += movement;

    // Detect samus
    if ((gSamusData.yPosition - 0x48) >= gCurrentSprite.yPosition)
    {
        nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 8, BLOCK_SIZE * 5);
        if (nslr == NSLR_RIGHT || nslr == NSLR_LEFT)
            gCurrentSprite.pose = HOLTZ_POSE_WARNING_INIT;
    }
}

/**
 * @brief 38588 | 20 | Initializes a holtz to do the warning
 * 
 */
void HoltzWarningInit(void)
{
    gCurrentSprite.pose = HOLTZ_POSE_WARNING;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pOam = sHoltzOAM_Warning;
}

/**
 * @brief 385a8 | 90 | Checks if the warning animation has ended
 * 
 */
void HoltzCheckWarningAnimEnded(void)
{
    s16 offset;
    s32 movement;

    // Y idle movement
    offset = gCurrentSprite.work3;
    movement = sHoltzIdleYVelocity[offset];
    if (movement == SHORT_MAX)
    {
        movement = sHoltzIdleYVelocity[0]; // 0
        offset = 0x0;
    }
    gCurrentSprite.work3 = offset + 0x1;
    gCurrentSprite.yPosition += movement;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set going down behavior
        gCurrentSprite.pose = HOLTZ_POSE_GOING_DOWN;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pOam = sHoltzOAM_GoingDown;
        // Set going down flag (they could've used the facing down flag?)
        gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
        SpriteUtilMakeSpriteFaceSamusDirection();
        gCurrentSprite.work0 = 0x0;
        gCurrentSprite.work2 = 0x2; // Initial X speed
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_HOLTZ_GOING_DOWN);
    }
}

/**
 * @brief 38638 | 60 | Handles the holtz going down
 * 
 */
void HoltzGoingDownMove(void)
{
    // Gradually increase X movement
    gCurrentSprite.work0++;
    if (gCurrentSprite.work2 < 0xC && !(gCurrentSprite.work0 & 0x1))
        gCurrentSprite.work2++;

    HoltzXMovement(gCurrentSprite.work2);
    if (HoltzYMovement(0xC)) // Y movement
    {
        // Touched ground, set sliding behavior
        gCurrentSprite.pose = HOLTZ_POSE_SLIDING;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pOam = sHoltzOAM_IdleAware;
    }
}

/**
 * @brief 38698 | 4c | Handles the holtz sliding on the ground
 * 
 */
void HoltzSlidingMove(void)
{
    HoltzXMovement(gCurrentSprite.work2); // X Movement

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set going up behavior
        gCurrentSprite.pose = HOLTZ_POSE_GOING_UP;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pOam = sHoltzOAM_GoingUp;
        // Remove going down flag
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        gCurrentSprite.work0 = 0x0;
    }
}

/**
 * @brief 386e4 | 9c | Handles the holtz moving up
 * 
 */
void HoltzGoingUpMove(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN &&
        (gCurrentSprite.currentAnimationFrame == 0x0 || gCurrentSprite.currentAnimationFrame == 0x3)
        && gCurrentSprite.animationDurationCounter == 0x1)
    {
        SoundPlayNotAlreadyPlaying(SOUND_HOLTZ_GOING_UP);
    }

    // Gradually decrease X movement
    gCurrentSprite.work0++;
    if (gCurrentSprite.work2 > 0x2 && !(gCurrentSprite.work0 & 0x1))
        gCurrentSprite.work2--;

    HoltzXMovement(gCurrentSprite.work2); // X movement
    if (HoltzYMovement(0xC)) // Y movement
    {
        // Touching ceiling, set bonking behavior
        gCurrentSprite.yPosition &= 0xFFC0; // Clear subpixel
        gCurrentSprite.yPosition += HOLTZ_SIZE; // Offset with size of holtz
        gCurrentSprite.pose = HOLTZ_POSE_BACK_TO_CEILING;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pOam = sHoltzOAM_BonkingOnCeiling;
        gCurrentSprite.work3 = 0x0;
    }
}

/**
 * @brief 38780 | 50 | Handles the holtz being back on the ceiling
 * 
 */
void HoltzBackToCeiling(void)
{
    s32 movement;
    u8 offset;

    // Y idle movement
    offset = gCurrentSprite.work3;
    movement = sHoltzIdleYVelocity[offset];
    if (movement == SHORT_MAX)
    {
        movement = sHoltzIdleYVelocity[0]; // 0
        offset = 0x0;
    }
    gCurrentSprite.work3 = offset + 0x1;
    gCurrentSprite.yPosition += movement;

    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = HOLTZ_POSE_IDLE_INIT; // Set idle
}

/**
 * @brief 387d0 | 1ac | Holtz AI
 * 
 */
void Holtz(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_HOLTZ_DAMAGED);
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
                HoltzInit();
                break;

            case HOLTZ_POSE_IDLE_INIT:
                HoltzIdleInit();
                break;

            case HOLTZ_POSE_IDLE:
                HoltzIdle();
                break;

            case HOLTZ_POSE_WARNING_INIT:
                HoltzWarningInit();
            
            case HOLTZ_POSE_WARNING:
                HoltzCheckWarningAnimEnded();
                break;

            case HOLTZ_POSE_GOING_DOWN:
                HoltzGoingDownMove();
                break;

            case HOLTZ_POSE_SLIDING:
                HoltzSlidingMove();
                break;

            case HOLTZ_POSE_GOING_UP:
                HoltzGoingUpMove();
                break;

            case HOLTZ_POSE_BACK_TO_CEILING:
                HoltzBackToCeiling();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
        }
    }
}