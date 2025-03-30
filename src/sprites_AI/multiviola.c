#include "sprites_AI/multiviola.h"
#include "macros.h"

#include "data/sprites/multiviola.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"

/**
 * @brief 1e854 | 70 | Initializes a multiviola sprite
 * 
 */
void MultiviolaInit(void)
{
    gCurrentSprite.drawDistanceTop = 0x20;
    gCurrentSprite.drawDistanceBottom = 0xC;
    gCurrentSprite.drawDistanceHorizontal = 0x10;

    gCurrentSprite.hitboxTop = -0x20;
    gCurrentSprite.hitboxBottom = 0x20;
    gCurrentSprite.hitboxLeft = -0x20;
    gCurrentSprite.hitboxRight = 0x20;

    gCurrentSprite.pOam = sMultiviolaOAM_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = gCurrentSprite.primarySpriteRamSlot * 2;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    SpriteUtilMakeSpriteFaceSamusXFlip();
    gCurrentSprite.pose = MULTIVIOLA_POSE_MOVING;
}

/**
 * @brief 1e8c4 | 110 | Handles a multiviola moving
 * 
 */
void MultiviolaMove(void)
{
    u8 isBouncing;
    u16 yMovement;

    isBouncing = FALSE;
    yMovement = 0x3;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        // Move right
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.xPosition += 0x3;
        else
        {
            // Bounce X
            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            isBouncing++;
        }
    }
    else
    {
        // Move left
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.xPosition -= 0x3;
        else
        {
            // Bounce X
            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            isBouncing++;
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        // Move up
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTop, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.yPosition -= yMovement;
        else
        {
            // Bounce Y
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            isBouncing++;
        }
    }
    else
    {
        // Move down
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxBottom, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.yPosition += yMovement;
        else
        {
            // Bounce Y
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            isBouncing++;
        }
    }

    if (isBouncing && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_MULTIVIOLA_BOUNCING);
}

/**
 * @brief 1e9cc | 4 | Unused multiviola sprite function
 * 
 */
void MultivioaUnused_Empty1(void)
{
    return;
}


/**
 * @brief 1e9d0 | 4 | Unused multiviola sprite function
 * 
 */
void MultivioaUnused_Empty2(void)
{
    return;
}

/**
 * @brief 1e9d4 | 90 | Multiviola AI
 * 
 */
void Multiviola(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_MULTIVIOLA_DAMAGED);
    }

    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent(SSPRITE_MULTIVIOLA_UNUSED, gCurrentSprite.primarySpriteRamSlot);
    }
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;

        switch (gCurrentSprite.pose)
        {
            default:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
                break;
                
            case SPRITE_POSE_UNINITIALIZED:
                MultiviolaInit();
                break;

            case MULTIVIOLA_POSE_MOVING:
                MultiviolaMove();
        }
    }
}

/**
 * @brief 1ea64 | 4 | Unused multiviola sprite AI
 * 
 */
void MultiviolaUnused(void)
{
    return;
}