#include "sprites_AI/polyp.h"
#include "macros.h"

#include "data/sprites/polyp.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/display.h"
#include "structs/sprite.h"

/**
 * @brief 36ec4 | 4c | Initializes a polyp sprite
 * 
 */
void PolypInit(void)
{
    gCurrentSprite.hitboxTop = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2);
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = -(BLOCK_SIZE - PIXEL_SIZE * 2);
    gCurrentSprite.hitboxRight = (BLOCK_SIZE - PIXEL_SIZE * 2);

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    gCurrentSprite.samusCollision = SSC_KNOCKS_BACK_SAMUS;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
}

/**
 * @brief 36f10 | 24 | Initializes a polyp to be idle
 * 
 */
void PolypIdleInit(void)
{
    gCurrentSprite.pose = POLYP_POSE_IDLE;

    gCurrentSprite.pOam = sPolypOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    // Delay before spitting
    gCurrentSprite.work0 = POLYP_SHOOT_DELAY;
}

/**
 * @brief 36f34 | 74 | Checks if the polyp should be shooting a projectile
 * 
 */
void PolypCheckSpawnProjectile(void)
{
    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 != 0)
        return;

    // Shoot if on screen, not already shooted and projectile doesn't have an active drop
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN &&
        SpriteUtilCountSecondarySpritesWithCurrentSpriteRAMSlot(SSPRITE_POLYP_PROJECTILE) == 0 &&
        !SpriteUtilCheckHasDrops())
    {
        // Set warning behavior
        gCurrentSprite.pose = POLYP_POSE_WARNING;

        gCurrentSprite.pOam = sPolypOam_Warning;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(SOUND_POLYP_WARNING);
    }
    else
    {
        // Can't shoot, reset timer
        gCurrentSprite.work0 = POLYP_SHOOT_DELAY;
    }
}

/**
 * @brief 36fa8 | 30 | Checks if the warning animation has ended
 * 
 */
void PolypCheckWarningEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set spitting behavior
        gCurrentSprite.pose = POLYP_POSE_SPITTING;

        gCurrentSprite.pOam = sPolypOam_Spitting;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.work0 = POLYP_SPIT_DURATION;
    }
}

/**
 * @brief 36fd8 | 64 | Handles the polyp spitting
 * 
 */
void PolypSpawnProjectile(void)
{
    if (--gCurrentSprite.work0 == 0)
    {
        // Set after spitting behavior
        gCurrentSprite.pose = POLYP_POSE_AFTER_SPITTING;

        gCurrentSprite.pOam = sPolypOam_AfterSpitting;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
    else if (gCurrentSprite.work0 == POLYP_SPIT_DURATION / 5)
    {
        // Spawn projectile
        SpriteSpawnSecondary(SSPRITE_POLYP_PROJECTILE, gCurrentSprite.roomSlot,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition, 0);
    }
}

/**
 * @brief 3703c | 2c | Checks if the after spitting animation ended
 * 
 */
void PolypCheckAfterSpittingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set retracting behavior
        gCurrentSprite.pose = POLYP_POSE_RETRACTING;

        gCurrentSprite.pOam = sPolypOam_Retracting;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 37068 | 1c | Checks if the retracting animation ended
 * 
 */
void PolypCheckRetractingAnimEnded(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = POLYP_POSE_IDLE_INIT; // Set idle
}

/**
 * @brief 37084 | e0 | Initializes a polyp projectile
 * 
 */
void PolypProjectileInit(void)
{
    u8 nslr;

    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = POLYP_PROJECTILE_POSE_SPAWN;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 5;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);

    // Try set same direction samus
    nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 5, BLOCK_SIZE * 8 + HALF_BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2);
    if (nslr == NSLR_RIGHT)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    else if (nslr != NSLR_LEFT)
        SpriteUtilChooseRandomXDirection(); // Random if can't find samus

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.pOam = sPolypProjectileOam_Right;
    else
        gCurrentSprite.pOam = sPolypProjectileOam_Left;

    gCurrentSprite.work0 = 4;
    gCurrentSprite.work3 = 0;
}

/**
 * @brief 37164 | 48 | Handles the spawning of a polyp projectile
 * 
 */
void PolypProjectileSpawn(void)
{
    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = POLYP_PROJECTILE_POSE_MOVING;
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(SOUND_POLYP_SPITTING);
    }
}

/**
 * @brief 371ac | 88 | Handles the movement of a polyp projectile
 * 
 */
void PolypProjectileMove(void)
{
    u16 xMovement;
    s32 yMovement;
    u8 offset;

    xMovement = PIXEL_SIZE;

    // Y movement
    offset = gCurrentSprite.work3;
    yMovement = sPolypProjectileYVelocity[offset];
    if (yMovement == SHORT_MAX)
    {
        yMovement = sPolypProjectileYVelocity[offset - 1];
        gCurrentSprite.yPosition += yMovement;
    }
    else
    {
        gCurrentSprite.work3++;
        gCurrentSprite.yPosition += yMovement;
    }

    // X Movement
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.xPosition += xMovement;
    else
        gCurrentSprite.xPosition -= xMovement;

    // Check colliding with solid
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousCollisionCheck & 0xF0)
        gCurrentSprite.pose = SPRITE_POSE_STOPPED;
}

/**
 * @brief 37234 | 50 | Initializes a polyp projectile to be exploding
 * 
 */
void PolypProjectileExplodingInit(void)
{
    gCurrentSprite.pOam = sPolypProjectileOam_Exploding;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = POLYP_PROJECTILE_POSE_EXPLODING;
    gCurrentSprite.bgPriority = MOD_AND(gIoRegistersBackup.BG1CNT, 4);
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(SOUND_POLYP_PROJECTILE_EXPLODING);
}

/**
 * @brief 37284 | 24 | Checks if the exploding animation ended
 * 
 */
void PolypProjectileCheckExplodingAnimEnded(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0; // Kill sprite
}

/**
 * @brief 372a8 | 11c | Polyp AI
 * 
 */
void Polyp(void)
{
    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            PolypInit();

        case POLYP_POSE_IDLE_INIT:
            PolypIdleInit();

        case POLYP_POSE_IDLE:
            PolypCheckSpawnProjectile();
            break;

        case POLYP_POSE_WARNING:
            PolypCheckWarningEnded();
            break;

        case POLYP_POSE_SPITTING:
            PolypSpawnProjectile();
            break;

        case POLYP_POSE_AFTER_SPITTING:
            PolypCheckAfterSpittingAnimEnded();
            break;

        case POLYP_POSE_RETRACTING:
            PolypCheckRetractingAnimEnded();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE,
                gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
    }
}

/**
 * @brief 373c4 | 78 | Polyp projectile AI
 * 
 */
void PolypProjectile(void)
{
    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            PolypProjectileInit();
            break;

        case POLYP_PROJECTILE_POSE_SPAWN:
            PolypProjectileSpawn();
            break;

        case POLYP_PROJECTILE_POSE_MOVING:
            PolypProjectileMove();
            break;

        case SPRITE_POSE_STOPPED:
            PolypProjectileExplodingInit();

        case POLYP_PROJECTILE_POSE_EXPLODING:
            PolypProjectileCheckExplodingAnimEnded();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}
