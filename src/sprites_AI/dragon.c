#include "sprites_AI/dragon.h"
#include "macros.h"

#include "data/sprites/dragon.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/display.h"
#include "structs/samus.h"
#include "structs/sprite.h"

#define DRAGON_Y_VELOCITY (PIXEL_SIZE / 2)
#define DRAGON_SPIT_Y_OFFSET (BLOCK_SIZE + EIGHTH_BLOCK_SIZE)
#define DRAGON_SPIT_X_OFFSET (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE)

#define DRAGON_MAX_RISING_HEIGHT (BLOCK_SIZE * 2 - ONE_SUB_PIXEL)

// The sprite status flag is used with "reverse" intent, when it's set, the dragon rises
#define STATUS_RISING (SPRITE_STATUS_FACING_DOWN)

/**
 * @brief 20564 | 50 | Handles the Y movement of a dragon
 * 
 */
void DragonYMovement(void)
{
    u16 oldY;
    u16 ySpawn;

    oldY = gCurrentSprite.yPosition;
    ySpawn = gCurrentSprite.yPositionSpawn;

    if (gCurrentSprite.status & STATUS_RISING)
    {
        // Check for the max height threshold
        if (ySpawn - DRAGON_MAX_RISING_HEIGHT < gCurrentSprite.yPosition)
            gCurrentSprite.yPosition -= DRAGON_Y_VELOCITY;

        SpriteUtilCheckOutOfRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_SMALL);
    }
    else
    {
        // Check has reached the spawn position
        if (ySpawn - DRAGON_Y_VELOCITY > gCurrentSprite.yPosition)
            gCurrentSprite.yPosition += DRAGON_Y_VELOCITY;

        SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_SMALL);
    }
}

/**
 * @brief 205b4 | 60 | Initializes a dragon sprite
 * 
 */
void DragonInit(void)
{
    gCurrentSprite.hitboxTop = -BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = BLOCK_SIZE + QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

    gCurrentSprite.pOam = sDragonOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    SpriteUtilMakeSpriteFaceSamusXFlip();

    gCurrentSprite.pose = DRAGON_POSE_IDLE_INIT;
    gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
}

/**
 * @brief 20628 | 28 | Initializes a dragon to be idle
 * 
 */
void DragonIdleInit(void)
{
    gCurrentSprite.pose = DRAGON_POSE_IDLE;

    gCurrentSprite.pOam = sDragonOam_Idle;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    // Spitting interval
    gCurrentSprite.work0 = CONVERT_SECONDS(1.f) + TWO_THIRD_SECOND;
}

/**
 * @brief 20650 | d0 | Handles the dragon going up
 * 
 */
void DragonIdle(void)
{
    u8 nslr;
    u16 xPosition;
    u16 yPosition;

    if (gCurrentSprite.work0 != 0)
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);

    // Move vertically
    DragonYMovement();

    // Default to sinking
    gCurrentSprite.status &= ~STATUS_RISING;

    // If samus is below the dragon, don't do anything
    if (gSamusData.yPosition > gCurrentSprite.yPosition)
        return;

    // Check where samus is
    nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 6, BLOCK_SIZE * 6);

    if (nslr != NSLR_OUT_OF_RANGE)
    {
        // Samus is in range, set rising
        // Due to this only being checked if samus isn't below the dragon, if samus is in range, but below the rising range of the dragon,
        // it'll stutter (sink for one frame, rise for one frame, sink, rise...)
        gCurrentSprite.status |= STATUS_RISING;
    }

    // Check should turn around
    if (nslr == NSLR_RIGHT)
    {
        if (!(gCurrentSprite.status & SPRITE_STATUS_X_FLIP))
        {
            gCurrentSprite.pose = DRAGON_POSE_TURN_AROUND_INIT;
            return;
        }
    }
    else if (nslr == NSLR_LEFT)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.pose = DRAGON_POSE_TURN_AROUND_INIT;
            return;
        }
    }
    else
    {
        return;
    }

    if (gCurrentSprite.work0 == 0)
    {
        // Check if there's nothing 2 blocks above and 1 in front
        // If the intent was to check for a block where the fireball would spawn, that doesn't work
        // In fact, the fireball never colldes with the block that's checked here 
        yPosition = gCurrentSprite.yPosition - (BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE);

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
        else
            xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE);

        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.pose = DRAGON_POSE_WARNING_INIT;
    }
}


/**
 * @brief 20720 | 20 | Initializes a dragon to be turning around
 * 
 */
void DragonTurningAroundInit(void)
{
    gCurrentSprite.pose = DRAGON_POSE_TURN_AROUND_FIRST_HALF;

    gCurrentSprite.pOam = sDragonOam_TurningAround;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;
}

/**
 * @brief 20740 | 30 | Checks if the first part of the turning around animation ended
 * 
 */
void DragonTurningAroundFirstHalf(void)
{
    DragonYMovement();

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = DRAGON_POSE_TURN_AROUND_SECOND_HALF;

        gCurrentSprite.pOam = sDragonOam_TurningAroundPart2;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
    }
}

/**
 * @brief 20778 | 20 | Checks if the second part of the turning around animation ended
 * 
 */
void DragonTurningAroundSecondHalf(void)
{
    DragonYMovement();

    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
    {
        // Immediatly spit after turning around
        gCurrentSprite.pose = DRAGON_POSE_WARNING_INIT;
    }
}

/**
 * @brief 20798 | 28 | Initializes a dragon to do the warning before spitting
 * 
 */
void DragonWarningInit(void)
{
    gCurrentSprite.pose = DRAGON_POSE_WARNING;

    gCurrentSprite.pOam = sDragonOam_Warning;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.work0 = CONVERT_SECONDS(.5f);
}

/**
 * @brief 207c0 | 40 | Handles the warning (delay before spitting)
 * 
 */
void DragonWarning(void)
{
    DragonYMovement();

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);

    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = DRAGON_POSE_SPIT;

        gCurrentSprite.pOam = sDragonOam_Spitting;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.work0 = 8;
    }
}

/**
 * @brief 20800 | 70 | Handles the dragon spitting
 * 
 */
void DragonSpit(void)
{
    u16 yPosition;
    u16 xPosition;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        DragonIdleInit();

        yPosition = gCurrentSprite.yPosition - DRAGON_SPIT_Y_OFFSET;
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            xPosition = gCurrentSprite.xPosition + DRAGON_SPIT_X_OFFSET;
        else
            xPosition = gCurrentSprite.xPosition - DRAGON_SPIT_X_OFFSET;

        // Spawn projectile
        SpriteSpawnSecondary(SSPRITE_DRAGON_FIREBALL, 0, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, gCurrentSprite.status & SPRITE_STATUS_X_FLIP);
    }
}

/**
 * @brief 20870 | e4 | Initializes a dragon fireball sprite
 * 
 */
void DragonFireballInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;

    gCurrentSprite.pOam = sDragonFireballOam_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = 0x9;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.bgPriority = MOD_AND(gIoRegistersBackup.BG1CNT, 4);
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.rotation = PI / 2;
        gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
    }
    else
    {
        gCurrentSprite.rotation = 0;
    }

    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_80;
    gCurrentSprite.scaling = Q_8_8(1.f);
    gCurrentSprite.work3 = 0;

    SoundPlay(0x14C);
}

/**
 * @brief 20954 | d8 | Handles the movement of a dragon fireball
 * 
 */
void DragonFireballMove(void)
{
    u16 oldY;
    u8 offset;
    s32 yMovement;
    s32 xMovement;
    s32 rotation;
    s32 newVel;

    xMovement = PIXEL_SIZE * 3;
    oldY = gCurrentSprite.yPosition;
    offset = gCurrentSprite.work3;

    yMovement = sDragonFireballYMovement[offset];
    rotation = sDragonFireballOamRotation[offset];

    if (yMovement == SHORT_MAX)
    {
        newVel = sDragonFireballYMovement[offset - 1];
        rotation = sDragonFireballOamRotation[offset - 1];
        gCurrentSprite.yPosition += newVel;
    }
    else
    {
        gCurrentSprite.work3++;
        gCurrentSprite.yPosition += yMovement;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        gCurrentSprite.xPosition += xMovement;
        gCurrentSprite.rotation = rotation + PI / 2;
    }
    else
    {
        gCurrentSprite.xPosition -= xMovement;
        gCurrentSprite.rotation = -rotation;
    }

    if (SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_NONE))
    {
        gCurrentSprite.pose = SPRITE_POSE_STOPPED;
        return;
    }

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousCollisionCheck & 0xF0)
        gCurrentSprite.pose = SPRITE_POSE_STOPPED;
}

/**
 * @brief 20a28 | 3c | Initializes a dragon fireball to be exploding
 * 
 */
void DragonFireballExplodingInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    gCurrentSprite.pOam = sDragonFireballOam_Exploding;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = DRAGON_FIREBALL_POSE_EXPLODING;
    gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN_80;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
}

/**
 * @brief 20a64 | 24 | Checks if the exploding animation ended
 * 
 */
void DragonFireballCheckExplodingAnimEnded(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0;
}

/**
 * @brief 20a88 | 19c | Dragon AI
 * 
 */
void Dragon(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;

        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_DRAGON_DAMAGED);
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
            DragonInit();
            break;

        case DRAGON_POSE_IDLE_INIT:
            DragonIdleInit();

        case DRAGON_POSE_IDLE:
            DragonIdle();
            break;

        case DRAGON_POSE_TURN_AROUND_INIT:
            DragonTurningAroundInit();

        case DRAGON_POSE_TURN_AROUND_FIRST_HALF:
            DragonTurningAroundFirstHalf();
            break;

        case DRAGON_POSE_TURN_AROUND_SECOND_HALF:
            DragonTurningAroundSecondHalf();
            break;

        case DRAGON_POSE_WARNING_INIT:
            DragonWarningInit();

        case DRAGON_POSE_WARNING:
            DragonWarning();
            break;

        case DRAGON_POSE_SPIT:
            DragonSpit();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
    }
}

/**
 * @brief 20c24 | 58 | Dragon fireball AI
 * 
 */
void DragonFireball(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            DragonFireballInit();

        case DRAGON_FIREBALL_POSE_MOVE:
            DragonFireballMove();
            break;

        case SPRITE_POSE_STOPPED:
            DragonFireballExplodingInit();
            break;

        case DRAGON_FIREBALL_POSE_EXPLODING:
            DragonFireballCheckExplodingAnimEnded();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}
