#include "sprites_AI/skultera.h"
#include "macros.h"

#include "data/sprites/skultera.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/clipdata.h"
#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 48c7c | 30 | Sets the side hitboxes depending on the X flip
 * 
 */
void SkulteraSetSidesHitbox(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = -SKULTERA_TAIL_HITBOX;
        gCurrentSprite.hitboxRight = SKULTERA_HEAD_HITBOX;
    }
    else
    {
        gCurrentSprite.hitboxLeft = -SKULTERA_HEAD_HITBOX;
        gCurrentSprite.hitboxRight = SKULTERA_TAIL_HITBOX;
    }
}

/**
 * @brief 48cac | 64 | Handles the horizontal movement of the skultera
 * 
 * @param movement X velocity
 * @return u8 bool, colliding with solid
 */
u8 SkulteraXMovement(u16 movement)
{
    s16 negMovement;

    negMovement = movement;
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE,
            gCurrentSprite.xPosition + (QUARTER_BLOCK_SIZE * 3 + PIXEL_SIZE * 2));

        if (gPreviousCollisionCheck != COLLISION_SOLID)
        {
            gCurrentSprite.xPosition += movement;
            return FALSE;
        }

        return TRUE;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE,
            gCurrentSprite.xPosition - (QUARTER_BLOCK_SIZE * 3 + PIXEL_SIZE * 2));

        if (gPreviousCollisionCheck != COLLISION_SOLID)
        {
            gCurrentSprite.xPosition -= negMovement;
            return FALSE;
        }

        return TRUE;
    }
}

/**
 * @brief 48d10 | 68 | Initializes a skultera sprite
 * 
 */
void SkulteraInit(void)
{
    // Random direction
    SpriteUtilChooseRandomXFlip();

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.hitboxBottom = 0;

    SkulteraSetSidesHitbox();

    gCurrentSprite.pose = SKULTERA_POSE_IDLE_INIT;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    gCurrentSprite.pOam = sSkulteraOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
}

/**
 * @brief 48d78 | 30 | Initializes a skultera to be idle
 * 
 */
void SkulteraIdleInit(void)
{
    // Save spawn X to allow loop back
    gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;

    gCurrentSprite.pose = SKULTERA_POSE_IDLE;

    gCurrentSprite.pOam = sSkulteraOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    // Timer before movement
    gCurrentSprite.work0 = 3;
}

/**
 * @brief 48da8 | c4 | Handles the skultera moving in idle behavior
 * 
 */
void SkulteraMoving(void)
{
    u32 nslr;

    gCurrentSprite.work0--; // Timer before movement
    if (gCurrentSprite.work0 == 0)
    {
        if (SkulteraXMovement(SKULTERA_X_MOVEMENT_SPEED)) // Move and check hit solid
        {
            // Hit solid, set turning around
            gCurrentSprite.pose = SKULTERA_POSE_TURNING_AROUND;
        }
        else
        {
            // Check out of movement territory, if out set turning around
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                if (gCurrentSprite.xPositionSpawn + SKULTERA_TERRITORY_RANGE < gCurrentSprite.xPosition)
                    gCurrentSprite.pose = SKULTERA_POSE_TURNING_AROUND;
            }
            else
            {
                if (gCurrentSprite.xPositionSpawn - SKULTERA_TERRITORY_RANGE > gCurrentSprite.xPosition)
                    gCurrentSprite.pose = SKULTERA_POSE_TURNING_AROUND;
            }

            // Reset timer
            gCurrentSprite.work0 = 3;
        }
    }

    // Check detect samus

    // Change Y range
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 10, BLOCK_SIZE) != NSLR_OUT_OF_RANGE)
        return;

    nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 3, BLOCK_SIZE * 5);

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        // Check on right
        if (nslr == NSLR_RIGHT)
            gCurrentSprite.pose = SKULTERA_POSE_CHASING_SAMUS_INIT; // Samus in range, chase
        else if (nslr == NSLR_LEFT)
            gCurrentSprite.pose = SKULTERA_POSE_TURNING_AROUND; // Turn around to face samus
    }
    else
    {
        // Check on left
        if (nslr == NSLR_LEFT)
            gCurrentSprite.pose = SKULTERA_POSE_CHASING_SAMUS_INIT; // Samus in range, chase
        else if (nslr == NSLR_RIGHT)
            gCurrentSprite.pose = SKULTERA_POSE_TURNING_AROUND; // Turn around to face samus
    }
}

/**
 * @brief 48e6c | 20 | Initializes a skultera to be chasing samus
 * 
 */
void SkulteraChasingSamusInit(void)
{
    gCurrentSprite.pose = SKULTERA_POSE_CHASING_SAMUS;

    gCurrentSprite.pOam = sSkulteraOam_ChasingSamus;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 48e8c | 110 | Handles the skultera moving in chasing samus behavior 
 * 
 */
void SkulteraChasingSamus(void)
{
    u16 samusY;
    u16 spriteY;
    u32 nslr;

    samusY = gSamusData.yPosition + gSamusPhysics.drawDistanceTop / 2;
    spriteY = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;

    // Check move vertically
    if (spriteY - BLOCK_SIZE > samusY)
    {
        // Check move up
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), gCurrentSprite.xPosition);

        // If no solid block and still in water
        if (gPreviousCollisionCheck == COLLISION_AIR && gCurrentAffectingClipdata.hazard == HAZARD_TYPE_WATER)
            gCurrentSprite.yPosition -= SKULTERA_Y_MOVEMENT_SPEED;
    }
    else if (spriteY + BLOCK_SIZE < samusY)
    {
        // Check move down
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

        // If no solid block
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.yPosition += SKULTERA_Y_MOVEMENT_SPEED;
    }

    gCurrentSprite.work0--; // Timer before movement
    if (gCurrentSprite.work0 == 0)
    {
        if (SkulteraXMovement(SKULTERA_X_MOVEMENT_SPEED))
            gCurrentSprite.pose = SKULTERA_POSE_TURNING_AROUND;
        else
            gCurrentSprite.work0 = 2; // Reset timer, 1 frame faster than idle for faster movement
    }

    // Check samus still in range
    
    // Change Y range
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 10, BLOCK_SIZE) != NSLR_OUT_OF_RANGE)
        return;

    nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 3, BLOCK_SIZE * 5);

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (nslr != NSLR_RIGHT)
        {
            if (nslr == NSLR_LEFT)
                gCurrentSprite.pose = SKULTERA_POSE_TURNING_AROUND; // Turn around to face samus
            else
                gCurrentSprite.pose = SKULTERA_POSE_IDLE_INIT; // Samus out of range, back to init
        }
    }
    else
    {
        if (nslr != NSLR_LEFT)
        {
            if (nslr == NSLR_RIGHT)
                gCurrentSprite.pose = SKULTERA_POSE_TURNING_AROUND; // Turn around to face samus
            else
                gCurrentSprite.pose = SKULTERA_POSE_IDLE_INIT; // Samus out of range, back to init
        }
    }
}

/**
 * @brief 48f9c | 38 | Initializes a skultera to be turning around
 * 
 */
void SkulteraTurningAroundInit(void)
{
    gCurrentSprite.pose = SKULTERA_POSE_CHECK_TURNING_AROUND_ENDED;

    gCurrentSprite.pOam = sSkulteraOam_TurningAround;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_SKULTERA_TURNING_AROUND);
}

/**
 * @brief 48fd4 | 24 | Checks if the skultera has finished turning around
 * 
 */
void SkulteraCheckTurningAroundAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set idle behavior
        SkulteraIdleInit();

        // Flip and set hitbox
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;

        SkulteraSetSidesHitbox();
    }
}

/**
 * @brief 48ff8 | 18c | Skultera AI
 * 
 */
void Skultera(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_SKULTERA_DAMAGED);
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
            SkulteraInit();
            break;

        case SKULTERA_POSE_IDLE_INIT:
            SkulteraIdleInit();
            break;

        case SKULTERA_POSE_IDLE:
            SkulteraMoving();
            break;

        case SKULTERA_POSE_TURNING_AROUND:
            SkulteraTurningAroundInit();

        case SKULTERA_POSE_CHECK_TURNING_AROUND_ENDED:
            SkulteraCheckTurningAroundAnimEnded();
            break;

        case SKULTERA_POSE_CHASING_SAMUS_INIT:
            SkulteraChasingSamusInit();
        
        case SKULTERA_POSE_CHASING_SAMUS:
            SkulteraChasingSamus();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - HALF_BLOCK_SIZE,
                gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
    }
}
