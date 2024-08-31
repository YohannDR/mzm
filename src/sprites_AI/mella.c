#include "sprites_AI/mella.h"
#include "macros.h"

#include "data/sprites/mella.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 3b36c | cc | Handles the X movement of a mella
 * 
 * @param movement Y Movement
 * @return u8 1 if colliding with solid, 0 otherwise
 */
u8 MellaYMovement(u16 movement)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;
        
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition - (QUARTER_BLOCK_SIZE * 3));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition + (QUARTER_BLOCK_SIZE * 3));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;
            
        gCurrentSprite.yPosition += movement;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE,
            gCurrentSprite.xPosition - (QUARTER_BLOCK_SIZE * 3));

        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE,
                gCurrentSprite.xPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE * 3));

            if (gPreviousCollisionCheck == COLLISION_SOLID)
                return TRUE;
        }

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE,
            gCurrentSprite.xPosition + (QUARTER_BLOCK_SIZE * 3));

        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE,
                gCurrentSprite.xPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE * 3));

            if (gPreviousCollisionCheck == COLLISION_SOLID)
                return TRUE;
        }
            
        gCurrentSprite.yPosition -= movement;
    }

    return FALSE;
}

/**
 * @brief 3b438 | 8c | Handles the X movement of a mella
 * 
 * @param movement X Movement
 * @return u8 1 if colliding with solid, 0 otherwise
 */
u8 MellaXMovement(u16 movement)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition + BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition + BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.xPosition += movement;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition - BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition - BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.xPosition -= movement;
    }

    return FALSE;
}

/**
 * @brief 3b4c4 | 68 | Initializes a mella sprite
 * 
 */
void MellaInit(void)
{
    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

    gCurrentSprite.pOam = sMellaOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.pose = MELLA_POSE_IDLE_INIT;
}

/**
 * @brief 3b52c | 38 | Initializes a mella to be idle
 * 
 */
void MellaIdleInit(void)
{
    u8 rng;
    
    gCurrentSprite.pose = MELLA_POSE_IDLE;
    gCurrentSprite.pOam = sMellaOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    rng = gSpriteRng;
    gCurrentSprite.work3 = rng * 4;
    gCurrentSprite.work2 = rng * 2;
}

/**
 * @brief 3b564 | 9c | Handles a mella being idle
 * 
 */
void MellaIdle(void)
{
    s32 movement;
    u8 offset;
    u8 nslr;

    // Y movement
    offset = gCurrentSprite.work3;
    movement = sMellaIdleYMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sMellaIdleYMovement[0]; // 0
        offset = 0;
    }

    gCurrentSprite.work3 = offset + 1;
    gCurrentSprite.yPosition += movement;

    // X movement
    offset = gCurrentSprite.work2;
    movement = sMellaIdleXMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sMellaIdleXMovement[0]; // 0
        offset = 0;
    }

    gCurrentSprite.work2 = offset + 1;
    gCurrentSprite.xPosition += movement;

    if (gSamusData.yPosition - (BLOCK_SIZE + PIXEL_SIZE * 2) >= gCurrentSprite.yPosition)
    {
        // Detect samus
        nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 8, BLOCK_SIZE * 3);
        if (nslr == NSLR_RIGHT || nslr == NSLR_LEFT)
            gCurrentSprite.pose = MELLA_POSE_MOVING_INIT;
    }
}

/**
 * @brief 3b600 | 34 | Initializes a mella to be moving
 * 
 */
void MellaMovingInit(void)
{
    gCurrentSprite.pose = MELLA_POSE_DELAY_BEOFRE_GOING_DOWN;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sMelloOAM_Moving;

    gCurrentSprite.work0 = 7;
}

/**
 * @brief 3b624 | 64 | Handles the delay before a mella goes down
 * 
 */
void MellaDelayBeforeGoingDown(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN &&
        gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
        SoundPlayNotAlreadyPlaying(SOUND_MELLA_MOVING);

    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0)
    {
        // Set going down behavior
        gCurrentSprite.pose = MELLA_POSE_GOING_DOWN;
        gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;

        SpriteUtilMakeSpriteFaceSamusDirection();

        gCurrentSprite.work2 = 0;
        gCurrentSprite.work3 = 0;
    }
}

/**
 * @brief 3b688 | 94 | Handles a mella going down
 * 
 */
void MellaGoingDown(void)
{
    u16 yMovement;
    u16 xMovement;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN &&
        gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
        SoundPlayNotAlreadyPlaying(SOUND_MELLA_MOVING);

    // Check increase offsets
    if (gCurrentSprite.work3 < ARRAY_SIZE(sMellaGoingDownYMovement) * 8 - 1)
        gCurrentSprite.work3++;

    if (gCurrentSprite.work2 < ARRAY_SIZE(sMellaMovingXMovement) * 8 - 1)
        gCurrentSprite.work2++;

    // Move
    yMovement = sMellaGoingDownYMovement[gCurrentSprite.work3 / 8];
    xMovement = sMellaMovingXMovement[gCurrentSprite.work2 / 8];

    MellaXMovement(xMovement);

    if (MellaYMovement(yMovement))
    {
        // Touched floor, set going up behavior
        gCurrentSprite.pose = MELLA_POSE_GOING_UP;
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        gCurrentSprite.work3 = 0;
    }
}

/**
 * @brief 3b71c | 94 | Handles the mella going up
 * 
 */
void MellaGoingUp(void)
{
    u16 yMovement;
    u16 xMovement;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN &&
        gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
        SoundPlayNotAlreadyPlaying(SOUND_MELLA_MOVING);

    // Check increase offsets
    if (gCurrentSprite.work3 < ARRAY_SIZE(sMellaGoingUpYMovement) * 8 - 1)
        gCurrentSprite.work3++;

    // Odd arbitrary number
    if (gCurrentSprite.work2 > 0x18)
        gCurrentSprite.work2--;

    // Move
    yMovement = sMellaGoingUpYMovement[gCurrentSprite.work3 / 8];
    xMovement = sMellaMovingXMovement[gCurrentSprite.work2 / 8];

    MellaXMovement(xMovement);

    if (MellaYMovement(yMovement))
    {
        // Touched ceiling, set idle behavior
        gCurrentSprite.yPosition = (gCurrentSprite.yPosition & BLOCK_POSITION_FLAG) + HALF_BLOCK_SIZE;
        gCurrentSprite.pose = MELLA_POSE_IDLE_INIT;
    }
}

/**
 * @brief 3b7b0 | 194 | Mella AI
 * 
 */
void Mella(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_MELLA_DAMAGED);
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
            MellaInit();
            break;

        case MELLA_POSE_IDLE_INIT:
            MellaIdleInit();
            break;

        case MELLA_POSE_IDLE:
            MellaIdle();
            break;

        case MELLA_POSE_MOVING_INIT:
            MellaMovingInit();
        
        case MELLA_POSE_DELAY_BEOFRE_GOING_DOWN:
            MellaDelayBeforeGoingDown();
            break;

        case MELLA_POSE_GOING_DOWN:
            MellaGoingDown();
            break;

        case MELLA_POSE_GOING_UP:
            MellaGoingUp();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}
