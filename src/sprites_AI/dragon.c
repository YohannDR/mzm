#include "sprites_AI/dragon.h"
#include "macros.h"

#include "data/sprites/dragon.h"
#include "data/sprite_data.h"

#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/display.h"
#include "structs/samus.h"
#include "structs/sprite.h"

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

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (ySpawn - (BLOCK_SIZE * 2 - PIXEL_SIZE / SUB_PIXEL_RATIO) < gCurrentSprite.yPosition)
            gCurrentSprite.yPosition -= PIXEL_SIZE / 2;

        SpriteUtilCheckOutOfRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_SMALL);
    }
    else
    {
        if (ySpawn - PIXEL_SIZE / 2 > gCurrentSprite.yPosition)
            gCurrentSprite.yPosition += PIXEL_SIZE / 2;

        SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_SMALL);
    }
}

/**
 * @brief 205b4 | 60 | Initializes a dragon sprite
 * 
 */
void DragonInit(void)
{
    gCurrentSprite.hitboxTopOffset = -BLOCK_SIZE;
    gCurrentSprite.hitboxBottomOffset = BLOCK_SIZE + QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxLeftOffset = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2);
    gCurrentSprite.hitboxRightOffset = (QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2);

    gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

    gCurrentSprite.pOam = sDragonOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);

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

    gCurrentSprite.pOam = sDragonOAM_Idle;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.timer = 100;
}

/**
 * @brief 20650 | d0 | Handles the dragon going up
 * 
 */
void DragonGoUp(void)
{
    u8 nslr;
    u16 xPosition;
    u16 yPosition;

    if (gCurrentSprite.timer != 0)
        gCurrentSprite.timer--;

    DragonYMovement();
    gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;

    if (gSamusData.yPosition > gCurrentSprite.yPosition)
        return;

    nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 6, BLOCK_SIZE * 6);
    if (nslr != NSLR_OUT_OF_RANGE)
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;

    if (nslr == NSLR_RIGHT)
    {
        if (!(gCurrentSprite.status & SPRITE_STATUS_XFLIP))
        {
            gCurrentSprite.pose = DRAGON_POSE_TURN_AROUND_INIT;
            return;
        }
    }
    else if (nslr == NSLR_LEFT)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            gCurrentSprite.pose = DRAGON_POSE_TURN_AROUND_INIT;
            return;
        }
    }
    else
    {
        return;
    }

    if (gCurrentSprite.timer == 0)
    {
        yPosition = gCurrentSprite.yPosition - 0x88;

        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            xPosition = gCurrentSprite.xPosition + 0x48;
        else
            xPosition = gCurrentSprite.xPosition - 0x48;

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

    gCurrentSprite.pOam = sDragonOAM_TurningAround;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;
}

/**
 * @brief 20740 | 30 | Checks if the first part of the turning around animation ended
 * 
 */
void DragonCheckTurningAroundFirstHalfAnimEnded(void)
{
    DragonYMovement();

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = DRAGON_POSE_TURN_AROUND_SECOND_HALF;

        gCurrentSprite.pOam = sDragonOAM_TurningAroundPart2;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.status ^= SPRITE_STATUS_XFLIP;
    }
}

/**
 * @brief 20778 | 20 | Checks if the second part of the turning around animation ended
 * 
 */
void DragonCheckTurningAroundSecondHalfAnimEnded(void)
{
    DragonYMovement();

    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = DRAGON_POSE_WARNING_INIT;
}

/**
 * @brief 20798 | 28 | Initializes a dragon to do the warning before spitting
 * 
 */
void DragonWarningInit(void)
{
    gCurrentSprite.pose = DRAGON_POSE_WARNING;

    gCurrentSprite.pOam = sDragonOAM_Warning;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.timer = 30;
}

/**
 * @brief 207c0 | 40 | Handles the warning (delay before spitting)
 * 
 */
void DragonWarning(void)
{
    DragonYMovement();

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0)
    {
        gCurrentSprite.pose = DRAGON_POSE_SPIT;

        gCurrentSprite.pOam = sDragonOAM_Spitting;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.timer = 8;
    }
}

/**
 * @brief 20800 | Handles the dragon spitting
 * 
 */
void DragonSpit(void)
{
    u16 yPosition;
    u16 xPosition;

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0)
    {
        DragonIdleInit();

        yPosition = gCurrentSprite.yPosition - (BLOCK_SIZE + PIXEL_SIZE * 2);
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            xPosition = gCurrentSprite.xPosition + (HALF_BLOCK_SIZE + PIXEL_SIZE * 2);
        else
            xPosition = gCurrentSprite.xPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE * 2);

        // Spawn projectile
        SpriteSpawnSecondary(SSPRITE_DRAGON_FIREBALL, 0, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, gCurrentSprite.status & SPRITE_STATUS_XFLIP);
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

    gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTopOffset = -QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxBottomOffset = QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxLeftOffset = -QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxRightOffset = QUARTER_BLOCK_SIZE;

    gCurrentSprite.pOam = sDragonFireballOAM_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = 0x9;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.bgPriority = MOD_AND(gIoRegistersBackup.BG1CNT, 4);
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteID);
    
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.oamRotation = PI / 2;
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    }
    else
        gCurrentSprite.oamRotation = 0;

    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
    gCurrentSprite.oamScaling = Q_8_8(1.f);
    gCurrentSprite.arrayOffset = 0;

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
    offset = gCurrentSprite.arrayOffset;

    yMovement = sDragonFireballYMovement[offset];
    rotation = sDragonFireballOAMRotation[offset];

    if (yMovement == SHORT_MAX)
    {
        newVel = sDragonFireballYMovement[offset - 1];
        rotation = sDragonFireballOAMRotation[offset - 1];
        gCurrentSprite.yPosition += newVel;
    }
    else
    {
        gCurrentSprite.arrayOffset++;
        gCurrentSprite.yPosition += yMovement;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        gCurrentSprite.xPosition += xMovement;
        gCurrentSprite.oamRotation = rotation + PI / 2;
    }
    else
    {
        gCurrentSprite.xPosition -= xMovement;
        gCurrentSprite.oamRotation = -rotation;
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
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    gCurrentSprite.pOam = sDragonFireballOAM_Exploding;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = DRAGON_FIREBALL_POSE_EXPLODING;
    gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN3;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
}

/**
 * @brief 20a64 | 24 | Checks if the exploding animation ended
 * 
 */
void DragonFireballCheckExplodingAnimEnded(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0; // Kill sprite
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
            SoundPlayNotAlreadyPlaying(0x14D);
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
            DragonGoUp();
            break;

        case DRAGON_POSE_TURN_AROUND_INIT:
            DragonTurningAroundInit();

        case DRAGON_POSE_TURN_AROUND_FIRST_HALF:
            DragonCheckTurningAroundFirstHalfAnimEnded();
            break;

        case DRAGON_POSE_TURN_AROUND_SECOND_HALF:
            DragonCheckTurningAroundSecondHalfAnimEnded();
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
