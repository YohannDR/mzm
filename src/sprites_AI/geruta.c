#include "sprites_AI/geruta.h"
#include "macros.h"

#include "data/sprites/geruta.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 1ea68 | b0 | Handles the Y movement of a geruta
 * 
 * @param movement Y movement
 * @return u8 1 if hitting solid, 0 otherwise
 */
u8 GerutaYMovement(u16 movement)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition) == COLLISION_SOLID ||
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE * 3) == COLLISION_SOLID ||
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE * 3) == COLLISION_SOLID)
            return TRUE;
        gCurrentSprite.yPosition += movement;
    }
    else
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE), gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE * 3) == COLLISION_SOLID &&
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE), gCurrentSprite.xPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE * 3)) == COLLISION_SOLID)
            return TRUE;

        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE), gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE * 3) == COLLISION_SOLID &&
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE), gCurrentSprite.xPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE * 3)) == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.yPosition -= movement;
    }

    return FALSE;
}

/**
 * @brief 1eb18 | 74 | Handles the X movement of a geruta
 * 
 * @param movement X movement
 * @return u8 1 if hitting solid, 0 otherwise
 */
u8 GerutaXMovement(u16 movement)
{
    s16 negMovement;

    negMovement = movement;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition + BLOCK_SIZE) == COLLISION_SOLID ||
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition + BLOCK_SIZE) == COLLISION_SOLID)
            return TRUE;
        gCurrentSprite.xPosition += movement;
    }
    else
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition - BLOCK_SIZE) == COLLISION_SOLID ||
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition - BLOCK_SIZE) == COLLISION_SOLID)
            return TRUE;
        gCurrentSprite.xPosition -= negMovement;
    }
    
    return FALSE;
}

/**
 * @brief 1eb8c | 80 | Initializes a geruta sprite
 * 
 */
void GerutaInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    SpriteUtilMakeSpriteFaceSamusDirection();

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE;

    gCurrentSprite.pOam = sGerutaOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.yPosition -= 3 * PIXEL_SIZE;
    gCurrentSprite.pose = GERUTA_POSE_IDLE_INIT;
}

/**
 * @brief 1ec0c | 20 | Initializes a geruta sprite to be idle
 * 
 */
void GerutaIdleInit(void)
{
    gCurrentSprite.pose = GERUTA_POSE_IDLE;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sGerutaOAM_Idle;
}

/**
 * @brief 1ec2c | 6c | Handles a geruta detecting samus
 * 
 */
void GerutaDetectSamus(void)
{
    u8 nslr;

    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE * 3) != COLLISION_SOLID &&
        SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE * 3) != COLLISION_SOLID)
    {
        SpriteUtilMakeSpriteFaceSamusDirection();
        gCurrentSprite.pose = GERUTA_POSE_WARNING_INIT;

    }
    else if ((gSamusData.yPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE)) >= gCurrentSprite.yPosition)
    {
        nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 5, BLOCK_SIZE * 5);

        if (nslr == NSLR_RIGHT || nslr == NSLR_LEFT)
            gCurrentSprite.pose = GERUTA_POSE_WARNING_INIT;
    }
}

/**
 * @brief 1ec98 | 34 | Initializes a geruta to do the warning
 * 
 */
void GerutaWarningInit(void)
{
    gCurrentSprite.pose = GERUTA_POSE_WARNING;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sGerutaOAM_Warning;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(SOUND_GERUTA_WARNING);
}

/**
 * @brief 1eccc | 2c | Checks if the warning has ended
 * 
 */
void GerutaCheckWarningEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = GERUTA_POSE_LAUNCHING;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sGerutaOAM_Launching;
    }
}

/**
 * @brief 1ecf8 | 50 | Checks if the launching animation has ended
 * 
 */
void GerutaCheckLaunchingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = GERUTA_POSE_GOING_DOWN;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sGerutaOAM_GoingDown;
        gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;

        SpriteUtilMakeSpriteFaceSamusDirection();
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_GERUTA_GOING_DOWN);
    }
}

/**
 * @brief 1ed48 | 44 | Handles a geruta going down
 * 
 */
void GerutaGoingDown(void)
{
    u16 oldY;

    oldY = gCurrentSprite.yPosition;
    GerutaXMovement(PIXEL_SIZE);
    if (GerutaYMovement(3 * PIXEL_SIZE))
    {
        gCurrentSprite.pose = GERUTA_POSE_BOUNCING;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sGerutaOAM_Bouncing;
    }

    SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_BIG);
}

/**
 * @brief 1ed8c | 48 | Checks if the bouning animation has ended
 * 
 */
void GerutaCheckBouncingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = GERUTA_POSE_GOING_UP;

        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sGerutaOAM_GoingUp;

        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_GERUTA_GOING_UP);
    }
}

/**
 * @brief 1edd4 | 48 | Handles a geruta going up
 * 
 */
void GerutaGoingUp(void)
{
    GerutaXMovement(PIXEL_SIZE);
    if (GerutaYMovement(3 * PIXEL_SIZE))
    {
        gCurrentSprite.yPosition = (gCurrentSprite.yPosition & BLOCK_POSITION_FLAG);
        gCurrentSprite.yPosition += HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE + PIXEL_SIZE;
        gCurrentSprite.pose = GERUTA_POSE_BOUNCING_ON_CEILING;

        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sGerutaOAM_BouncingOnCeiling;
    }
}

/**
 * @brief 1ee1c | 1c | Checks if the bouncing on ceiling animation ended
 * 
 */
void GerutaCheckBouncingOnCeilingAnimEnded(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = GERUTA_POSE_IDLE_INIT;
}

/**
 * @brief 1ee38 | 1bc | Geruta AI
 * 
 */
void Geruta(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_GERUTA_DAMAGED);
    }

    if (gCurrentSprite.freezeTimer != 0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;

        switch (gCurrentSprite.pose)
        {
            case SPRITE_POSE_UNINITIALIZED:
                GerutaInit();
                break;

            case GERUTA_POSE_IDLE_INIT:
                GerutaIdleInit();

            case GERUTA_POSE_IDLE:
                GerutaDetectSamus();
                break;

            case GERUTA_POSE_WARNING_INIT:
                GerutaWarningInit();

            case GERUTA_POSE_WARNING:
                GerutaCheckWarningEnded();
                break;

            case GERUTA_POSE_LAUNCHING:
                GerutaCheckLaunchingAnimEnded();
                break;

            case GERUTA_POSE_GOING_DOWN:
                GerutaGoingDown();
                break;

            case GERUTA_POSE_BOUNCING:
                GerutaCheckBouncingAnimEnded();
                break;

            case GERUTA_POSE_GOING_UP:
                GerutaGoingUp();
                break;

            case GERUTA_POSE_BOUNCING_ON_CEILING:
                GerutaCheckBouncingOnCeilingAnimEnded();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
        }
    }
}