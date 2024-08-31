#include "sprites_AI/dessgeega.h"
#include "macros.h"

#include "data/sprites/dessgeega.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/clipdata.h"
#include "structs/connection.h"
#include "structs/sprite.h"

/**
 * @brief 23b4c | 20 | Checks if samus is near the dessgeega on the sides in a 5 block range
 * 
 * @return u8 1 if near, 0 otherwise
 */
u8 DessgeegaCheckSamusNearLeftRight(void)
{
    u8 result;

    result = FALSE;
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 5, BLOCK_SIZE * 5) != NSLR_OUT_OF_RANGE)
    {
        result = TRUE;
        SpriteUtilMakeSpriteFaceSamusDirection();
    }
    return result;
}

/**
 * @brief 23b6c | 10c | Initializes a dessgeega sprite
 * 
 */
void DessgeegaInit(void)
{
    u8 spriteId;

    spriteId = gCurrentSprite.spriteId;

    if (spriteId == PSPRITE_DESSGEEGA_AFTER_LONG_BEAM)
    {
        // Check should kill dessgeega
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_LONG_BEAM_DESSGEEGA_KILLED)
            || !EventFunction(EVENT_ACTION_CHECKING, EVENT_VIEWED_STATUE_ROOM))
        {
            // If already dead or didn't view statue room
            gCurrentSprite.status = 0x0;
            return;
        }

        // Lock doors and set samus detection behavior
        LOCK_DOORS();
        gCurrentSprite.pose = DESSGEEGA_POSE_LONG_BEAM_DETECT;
    }
    else
    {
        // Check is on ceiling
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + 4), gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        {
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }
        // Should be idle init instead of idle, this skips the initialization of some variables
        gCurrentSprite.pose = DESSGEEGA_POSE_IDLE;
    }

    // Set hitbox and draw distances based on direction
    gCurrentSprite.work0 = 0x0;
    if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
    {
        gCurrentSprite.drawDistanceTop = 0x8;
        gCurrentSprite.drawDistanceBottom = 0x28;
        gCurrentSprite.hitboxTop = 0x0;
        gCurrentSprite.hitboxBottom = 0x58;
    }
    else
    {
        gCurrentSprite.drawDistanceTop = 0x28;
        gCurrentSprite.drawDistanceBottom = 0x8;
        gCurrentSprite.hitboxTop = -0x58;
        gCurrentSprite.hitboxBottom = 0x0;
    }

    gCurrentSprite.drawDistanceHorizontal = 0x18;
    gCurrentSprite.hitboxLeft = -0x40;
    gCurrentSprite.hitboxRight = 0x40;

    gCurrentSprite.pOam = sDessgeegaOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(spriteId);
    SpriteUtilChooseRandomXDirection();
}

/**
 * @brief 23c78 | 20 | Initializes a dessgeega to do the warning before a jump
 * 
 */
void DessgeegaJumpWarningInit(void)
{
    gCurrentSprite.pose = DESSGEEGA_POSE_JUMP_WARNING;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pOam = sDessgeegaOAM_JumpWarning;
}

/**
 * @brief 23c98 | 64 | Initializes a dessgeega to be jumping
 * 
 */
void DessgeegaJumpingInit(void)
{
    gCurrentSprite.pose = DESSGEEGA_POSE_JUMPING;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.work3 = 0x0;
    gCurrentSprite.pOam = sDessgeegaOAM_Jumping;

    // Set high or low jump depending on RNG
    if (gSpriteRng & 0x1)
        gCurrentSprite.work2 = TRUE; // Low
    else
        gCurrentSprite.work2 = FALSE; // High

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_DESSGEEGA_JUMPING);
}

/**
 * @brief 23cfc | 38 | Initializes a dessgeega to be landing
 * 
 */
void DessgeegaLandingInit(void)
{
    gCurrentSprite.pose = DESSGEEGA_POSE_LANDING;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pOam = sDessgeegaOAM_Landing;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_DESSGEEGA_LANDING);
}

/**
 * @brief 23d34 | 74 | Initializes a dessgeega to be idle
 * 
 */
void DessgeegaIdleInit(void)
{
    if (DessgeegaCheckSamusNearLeftRight())
        DessgeegaJumpWarningInit(); // Jump if smaus near
    else
    {
        // Set idle
        gCurrentSprite.pose = DESSGEEGA_POSE_IDLE;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.work0 = 0x0;
        gCurrentSprite.work1 = gSpriteRng & 0x3;

        // Set screaming or idle
        if (gSpriteRng >= 0x8)
            gCurrentSprite.pOam = sDessgeegaOAM_Idle;
        else
        {
            gCurrentSprite.pOam = sDessgeegaOAM_Screaming;
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(SOUND_DESSGEEGA_SCREAMING);
        }
    }
}

/**
 * @brief 23da8 | 24 | Initializes a dessgeega to be falling
 * 
 */
void DessgeegaFallingInit(void)
{
    gCurrentSprite.pose = DESSGEEGA_POSE_FALLING;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.work3 = 0x0;
    gCurrentSprite.pOam = sDessgeegaOAM_Jumping; // Use same animation as jumping
}

/**
 * @brief 23dcc | 5c | Handles the jump warning of a dessgeega on the ground
 * 
 */
void DessgeegaJumpWarningGround(void)
{
    // Check should fall
    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) == COLLISION_AIR)
    {
        // Check right block
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            // Check left block
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                DessgeegaFallingInit();
                return;
            }
        }
    }
    
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        DessgeegaJumpingInit(); // Jump if anim ended
}

/**
 * @brief 23e28 | 14 | Handles the jump warning of a dessgeega on the ceiling
 * 
 */
void DessgeegaJumpWarningCeiling(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        DessgeegaJumpingInit(); // Jump if anim ended
}

/**
 * @brief 23e3c | 1e8 | Handles the dessgeega jumping from the ground
 * 
 */
void DessgeegaJumpingGround(void)
{
    u8 collision;
    s32 yVelocity;
    u32 topEdge;

    collision = 0x0;
    if (gCurrentSprite.work2) // Low jump flag
        yVelocity = sDessgeegaLowJumpYVelocity[gCurrentSprite.work3 / 4];
    else
        yVelocity = sDessgeegaHighJumpYVelocity[gCurrentSprite.work3 / 4];

    // Apply movement
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Check colliding with wall on right
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight + 4);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            collision++;
            gCurrentSprite.xPosition -= 0x6;
        }
        else if (yVelocity >= 0x1)
            gCurrentSprite.xPosition += 0x4;
        else
            gCurrentSprite.xPosition += 0x5;
    }
    else
    {
        // Check colliding with wall on left
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft - 4);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            collision++;
            gCurrentSprite.xPosition += 0x6;
        }
        else if (yVelocity >= 0x1)
            gCurrentSprite.xPosition -= 0x4;
        else
            gCurrentSprite.xPosition -= 0x5;
    }

    // Apply Y
    gCurrentSprite.yPosition += yVelocity;

    if (gCurrentSprite.work3 < 0x27)
        gCurrentSprite.work3++;

    if (yVelocity >= 0x1)
    {
        // Positive velocity, check if landing

        // Rotate if collided
        if (collision)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;

        // Block right below
        topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            // Set landing behavior
            gCurrentSprite.yPosition = topEdge;
            DessgeegaLandingInit();
        }
        else if (!collision) // No need to check for side blocks if colliding with a wall
        {
            // Block on right
            topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
            if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
            {
                // Block on left
                topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
                if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                    collision = TRUE;

                if (!collision)
                    return;
            }

            // Set landing behavior
            gCurrentSprite.yPosition = topEdge;
            DessgeegaLandingInit();
        }
    }
    else
    {
        // Negative velocity, check if colliding with ceiling to fall
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            // Check block on top right
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTop, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                // Set falling behavior
                collision++;
                gCurrentSprite.xPosition -= 0x6;
                DessgeegaFallingInit();
            }
        }
        else
        {
            // Check block on top left
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTop, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                // Set falling behavior
                collision++;
                gCurrentSprite.xPosition += 0x6;
                DessgeegaFallingInit();
            }
        }

        // Rotate if collided
        if (collision)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
    }
}

/**
 * @brief 24024 | 1fc | Handles the dessgeega jumping from the ceiling
 * 
 */
void DessgeegaJumpingCeiling(void)
{
    u8 collision;
    s32 yVelocity;
    u32 topEdge;

    collision = 0x0;
    if (gCurrentSprite.work2) // Low jump flag
        yVelocity = sDessgeegaLowJumpYVelocity[gCurrentSprite.work3 / 4];
    else
        yVelocity = sDessgeegaHighJumpYVelocity[gCurrentSprite.work3 / 4];

    // Apply movement
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Check colliding with wall on right
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + 0x10, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight + 4);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            collision++;
            gCurrentSprite.xPosition -= 0x6;
        }
        else if (yVelocity >= 0x1)
            gCurrentSprite.xPosition += 0x4;
        else
            gCurrentSprite.xPosition += 0x5;
    }
    else
    {
        // Check colliding with wall on left
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + 0x10, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft - 4);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            collision++;
            gCurrentSprite.xPosition += 0x6;
        }
        else if (yVelocity >= 0x1)
            gCurrentSprite.xPosition -= 0x4;
        else
            gCurrentSprite.xPosition -= 0x5;
    }

    // Apply Y
    gCurrentSprite.yPosition -= yVelocity;

    if (gCurrentSprite.work3 < 0x27)
        gCurrentSprite.work3++;

    if (yVelocity < 0x0)
    {
        // Negative velocity, check if colliding with ground to fall
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            // Check block on bottom right
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxBottom, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                // Set falling behavior
                collision++;
                gCurrentSprite.xPosition -= 0x6;
                DessgeegaFallingInit();
            }
        }
        else
        {
            // Check block on bottom left
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxBottom, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                // Set falling behavior
                collision++;
                gCurrentSprite.xPosition += 0x6;
                DessgeegaFallingInit();
            }
        }

        // Rotate if collided
        if (collision)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
    }
    else
    {
        // Positive velocity, check if landing

        // Rotate if collided
        if (collision)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;

        // Block right below
        topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck & 0xF)
        {
            // Set landing behavior
            gCurrentSprite.yPosition = topEdge + BLOCK_SIZE;
            DessgeegaLandingInit();
        }
        else if (!collision) // No need to check for side blocks if colliding with a wall
        {
            // Block on right
            topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
            if (!(gPreviousVerticalCollisionCheck & 0xF))
            {
                // Block on left
                topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
                if (gPreviousVerticalCollisionCheck & 0xF)
                    collision = TRUE;

                if (!collision)
                    return;
            }

            // Set landing behavior
            gCurrentSprite.yPosition = topEdge + BLOCK_SIZE;
            DessgeegaLandingInit();
        }
    }
}

/**
 * @brief 24220 | 14 | Checks if the landing animation as ended
 * 
 */
void DessgeegaCheckLandingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        DessgeegaIdleInit(); // Set idle
}

/**
 * @brief 24234 | a4 | Handles a dessgeega falling from the ground
 * 
 */
void DessgeegaFallingGround(void)
{
    u8 colliding;
    u32 topEdge;
    u8 offset;
    s32 movement;

    colliding = FALSE;

    topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        colliding++;
    else
    {
        topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            colliding++;
        else
        {
            topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                colliding++;
        }
    }
    
    if (colliding)
    {
        gCurrentSprite.yPosition = topEdge;
        DessgeegaLandingInit();
    }
    else
    {
        // Update Y position
        offset = gCurrentSprite.work3;
        movement = sSpritesFallingSpeed[offset];
        if (movement == SHORT_MAX)
        {
            // Reached end of array, use last velocity
            movement = sSpritesFallingSpeed[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            gCurrentSprite.work3++;
            gCurrentSprite.yPosition += movement;
        }
    }
}

/**
 * @brief 242d8 | a8 | Handles a dessgeega falling from the ceiling
 * 
 */
void DessgeegaFallingCeiling(void)
{
    u8 colliding;
    u32 topEdge;
    u8 offset;
    s32 movement;

    colliding = FALSE;

    topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        colliding++;
    else
    {
        topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            colliding++;
        else
        {
            topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                colliding++;
        }
    }
    
    if (colliding)
    {
        gCurrentSprite.yPosition = topEdge + BLOCK_SIZE;
        DessgeegaLandingInit();
    }
    else
    {
        // Update Y position
        offset = gCurrentSprite.work3;
        movement = sSpritesFallingCeilingSpeed[offset];
        if (movement == SHORT_MAX)
        {
            // Reached end of array, use last velocity
            movement = sSpritesFallingCeilingSpeed[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            gCurrentSprite.work3++;
            gCurrentSprite.yPosition += movement;
        }
    }
}

/**
 * @brief 24380 | 98 | Handles a dessgeega being idle on the ground
 * 
 */
void DessgeegaIdleGround(void)
{
    if (DessgeegaCheckSamusNearLeftRight())
        DessgeegaJumpWarningInit();
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                DessgeegaFallingInit();
                return;
            }
        }
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            if (gCurrentSprite.work0++ == gCurrentSprite.work1)
                DessgeegaJumpWarningInit();
            else
            {
                if (gCurrentSprite.pOam == sDessgeegaOAM_Screaming && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(SOUND_DESSGEEGA_SCREAMING);
            }
        }
    }
}

/**
 * @brief 24418 | 5c | Handles a dessgeega being idle on the ceiling
 * 
 */
void DessgeegaIdleCeiling(void)
{
    if (DessgeegaCheckSamusNearLeftRight())
        DessgeegaJumpWarningInit();
    else
    {
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            if (gCurrentSprite.work0++ == gCurrentSprite.work1)
                DessgeegaJumpWarningInit();
            else
            {
                if (gCurrentSprite.pOam == sDessgeegaOAM_Screaming && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(SOUND_DESSGEEGA_SCREAMING);
            }
        }
    } 
}

/**
 * @brief 24474 | 58 | Handles the death of a dessgeega
 * 
 */
void DessgeegaDeath(void)
{
    u16 yPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        yPosition = gCurrentSprite.yPosition + 0x30;
    else
    {
        // Set event every time a ground dessgeega is killed instead of checking for the sprite ID ?
        EventFunction(EVENT_ACTION_SETTING, EVENT_LONG_BEAM_DESSGEEGA_KILLED);
        // Unlock doors
        gDoorUnlockTimer = -0x14;
        yPosition = gCurrentSprite.yPosition - 0x30;
    }

    // Kill sprite
    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
}

/**
 * @brief 244cc | b8 | Handles the detection of samus for the long beam dessgeega
 * 
 */
void DessgeegaLongBeamDetectSamus(void)
{
    u16 yPosition;
    u16 xPosition;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    // Detect samus
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN &&
        SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 12, BLOCK_SIZE * 4 - 0x10) != NSLR_OUT_OF_RANGE)
    {
        gCurrentSprite.pose = DESSGEEGA_POSE_LONG_BEAM_SPAWNING;
        gCurrentSprite.pOam = sDessgeegaOAM_Jumping;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.work3 = FALSE;
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;

        ScreenShakeStartVertical(0xA, 0x81);

        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;

        SpriteDebrisInit(0x0, 0x5, yPosition + 0x30, xPosition + 0x50);
        SpriteDebrisInit(0x0, 0x7, yPosition + 0x10, xPosition + 0x1A);
        SpriteDebrisInit(0x0, 0x8, yPosition + 0x40, xPosition - 0x5A);
        SpriteDebrisInit(0x0, 0x6, yPosition + 0x20, xPosition - 0x10);
        SoundPlay(SOUND_DESSGEEGA_LONG_BEAM_SPAWNING);
    }
}

/**
 * @brief 24584 | dc | Handles the spawning of the dessgeega long beam
 * 
 */
void DessgeegaLongBeamSpawning(void)
{
    u32 topEdge;
    u16 yPosition;
    u16 xPosition;
    u8 caa;

    topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        // Colliding with solid
        // Check hasn't destroyed floor
        if (!gCurrentSprite.work3)
        {
            gCurrentSprite.work3++; // Set block destroyed flag

            yPosition = gCurrentSprite.yPosition;
            xPosition = gCurrentSprite.xPosition;

            caa = CAA_REMOVE_SOLID;
             // Remove middle block
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition, xPosition);

             // Remove right block
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition, xPosition + BLOCK_SIZE);

             // Remove left block
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition, xPosition - BLOCK_SIZE);

            // Play effects
            ParticleSet(yPosition - 0x8, xPosition + 0x34, PE_TWO_MEDIUM_DUST);
            ParticleSet(yPosition + 0x8, xPosition - 0x34, PE_MEDIUM_DUST);

            SpriteDebrisInit(0x0, 0x11, yPosition - 0x40, xPosition);
            SpriteDebrisInit(0x0, 0x12, yPosition - 0x20, xPosition + 0x3E);
            SpriteDebrisInit(0x0, 0x13, yPosition - 0x28, xPosition - 0x5C);
            SpriteDebrisInit(0x0, 0x4, yPosition - 0x48, xPosition + 0x1E);
            SoundPlay(SOUND_DESSGEEGA_DESTROYING_FLOOR);
        }
        else
        {
            // Set landing behavior
            gCurrentSprite.yPosition = topEdge;
            ScreenShakeStartVertical(0xA, 0x81);
            DessgeegaLandingInit();
        }
    }
    else
        gCurrentSprite.yPosition += 0x18; // Go down
}

/**
 * @brief 24660 | 1dc | Dessgeega AI
 * 
 */
void Dessgeega(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_DESSGEEGA_DAMAGED);
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
                DessgeegaInit();
                break;

            case DESSGEEGA_POSE_LONG_BEAM_DETECT:
                DessgeegaLongBeamDetectSamus();
                break;

            case DESSGEEGA_POSE_LONG_BEAM_SPAWNING:
                DessgeegaLongBeamSpawning();
                break;

            case DESSGEEGA_POSE_JUMP_WARNING_INIT:
                DessgeegaJumpWarningInit();

            case DESSGEEGA_POSE_JUMP_WARNING:
                if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
                    DessgeegaJumpWarningCeiling();
                else
                    DessgeegaJumpWarningGround();
                break;

            case DESSGEEGA_POSE_JUMPING:
                if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
                    DessgeegaJumpingCeiling();
                else
                    DessgeegaJumpingGround();
                break;

            case DESSGEEGA_POSE_LANDING:
                DessgeegaCheckLandingAnimEnded();
                break;

            case DESSGEEGA_POSE_IDLE:
                if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
                    DessgeegaIdleCeiling();
                else
                    DessgeegaIdleGround();
                break;

            case DESSGEEGA_POSE_FALLING:
                if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
                    DessgeegaFallingCeiling();
                else
                    DessgeegaFallingGround();
                break;

            default:
                DessgeegaDeath();
        }
    }
}