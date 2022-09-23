#include "sprites_AI/dragon.h"
#include "data/data.h"
#include "data/sprites/dragon.c"
#include "data/sprite_data.c"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "structs/display.h"
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
        if (ySpawn - 0x7F < gCurrentSprite.yPosition)
            gCurrentSprite.yPosition -= 0x2;
        SpriteUtilCheckOutOfRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_SMALL);
    }
    else
    {
        if (ySpawn - 0x2 > gCurrentSprite.yPosition)
            gCurrentSprite.yPosition += 0x2;
        SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_SMALL);
    }
}

/**
 * @brief 205b4 | 60 | Initializes a dragon sprite
 * 
 */
void DragonInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x40;
    gCurrentSprite.hitboxBottomOffset = 0x50;
    gCurrentSprite.hitboxLeftOffset = -0x18;
    gCurrentSprite.hitboxRightOffset = 0x18;
    gCurrentSprite.drawDistanceTopOffset = 0x18;
    gCurrentSprite.drawDistanceBottomOffset = 0x18;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x18;
    gCurrentSprite.pOam = sDragonOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
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
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.timer = 0x64;
}

void DragonGoUp(void)
{
    // https://decomp.me/scratch/5xAh9

    /*u8 nslr;
    u16 xPosition;
    u16 yPosition;

    if (gCurrentSprite.timer != 0x0)
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
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            if (gCurrentSprite.timer == 0x0)
            {
                yPosition = gCurrentSprite.yPosition - 0x88;
                xPosition = gCurrentSprite.xPosition + 0x48;

                SpriteUtilCheckCollisionAtPosition(yPosition, xPosition);
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    gCurrentSprite.pose = DRAGON_POSE_WARNING_INIT;
            }
        }
        else
            gCurrentSprite.pose = DRAGON_POSE_TURN_AROUND_INIT;
    }
    else if (nslr == NSLR_LEFT)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            gCurrentSprite.pose = DRAGON_POSE_TURN_AROUND_INIT;
        else
        {
            if (gCurrentSprite.timer == 0x0)
            {
                yPosition = gCurrentSprite.yPosition - 0x88;
                xPosition = gCurrentSprite.xPosition - 0x48;

                SpriteUtilCheckCollisionAtPosition(yPosition, xPosition);
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    gCurrentSprite.pose = DRAGON_POSE_WARNING_INIT;
            }
        }
    }*/
}

/**
 * @brief 20720 | 20 | Initializes a dragon to be turning around
 * 
 */
void DragonTurningAroundInit(void)
{
    gCurrentSprite.pose = DRAGON_POSE_TURN_AROUND_FIRST_HALF;
    gCurrentSprite.pOam = sDragonOAM_TurningAround;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
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
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
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
    if (SpriteUtilCheckEndCurrentSpriteAnim())
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
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.timer = 0x1E;
}

/**
 * @brief 207c0 | 40 | Handles the warning (delay before spitting)
 * 
 */
void DragonWarning(void)
{
    DragonYMovement();
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = DRAGON_POSE_SPIT;
        gCurrentSprite.pOam = sDragonOAM_Spitting;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.timer = 0x8;
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
    if (gCurrentSprite.timer == 0x0)
    {
        DragonIdleInit();
        yPosition = gCurrentSprite.yPosition - 0x48;
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            xPosition = gCurrentSprite.xPosition + 0x28;
        else
            xPosition = gCurrentSprite.xPosition - 0x28;
        // Spawn projectile
        SpriteSpawnSecondary(SSPRITE_DRAGON_FIREBALL, 0x0, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.primarySpriteRAMSlot, yPosition, xPosition, gCurrentSprite.status & SPRITE_STATUS_XFLIP);
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
    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
    gCurrentSprite.hitboxTopOffset = -0x10;
    gCurrentSprite.hitboxBottomOffset = 0x10;
    gCurrentSprite.hitboxLeftOffset = -0x10;
    gCurrentSprite.hitboxRightOffset = 0x10;
    gCurrentSprite.pOam = sDragonFireballOAM_Moving;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
    gCurrentSprite.drawOrder = 0x3;
    gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
    gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
    
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.oamRotation = 0x40;
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    }
    else
        gCurrentSprite.oamRotation = 0x0;

    gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
    gCurrentSprite.oamScaling = 0x100;
    gCurrentSprite.arrayOffset = 0x0;
    SoundPlay(0x14C);
}

void DragonFireballMove(void)
{
    // https://decomp.me/scratch/x48fr

    /*u16 oldY;
    u8 offset;
    i32 yMovement;
    i32 xMovement;
    i32 rotation;

    xMovement = 0xC;
    oldY = gCurrentSprite.yPosition;
    offset = gCurrentSprite.arrayOffset;

    yMovement = sDragonFireballYMovement[offset];
    rotation = sDragonFireballOAMRotation[offset];

    if (yMovement == SHORT_MAX)
    {
        yMovement = sDragonFireballYMovement[offset - 1];
        rotation = sDragonFireballOAMRotation[offset - 1];
        gCurrentSprite.yPosition += yMovement;
    }
    else
    {
        gCurrentSprite.arrayOffset++;
        gCurrentSprite.yPosition += yMovement;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        gCurrentSprite.xPosition += xMovement;
        gCurrentSprite.oamRotation = rotation + 0x40;
    }
    else
    {
        gCurrentSprite.xPosition -= xMovement;
        gCurrentSprite.oamRotation = -rotation;
    }

    if (SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_NONE))
        gCurrentSprite.pose = DRAGON_FIREBALL_POSE_EXPLODING_INIT;
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & 0xF0)
            gCurrentSprite.pose = DRAGON_FIREBALL_POSE_EXPLODING_INIT;
    }*/
}

/**
 * @brief 20a28 | 3c | Initializes a dragon fireball to be exploding
 * 
 */
void DragonFireballExplodingInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.pOam = sDragonFireballOAM_Exploding;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = 0x43;
    gCurrentSprite.status = (gCurrentSprite.status & ~SPRITE_STATUS_YFLIP);
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
}

/**
 * @brief 20a64 | 24 | Checks if the exploding animation ended
 * 
 */
void DragonFireballCheckExplodingAnimEnded(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0; // Kill sprite
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

    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (!SpriteUtilIsSpriteStunned())
        {
            switch (gCurrentSprite.pose)
            {
                case 0x0:
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
        case 0x0:
            DragonFireballInit();
        case DRAGON_FIREBALL_POSE_MOVE:
            DragonFireballMove();
            break;
        case DRAGON_FIREBALL_POSE_EXPLODING_INIT:
            DragonFireballExplodingInit();
            break;
        case DRAGON_FIREBALL_POSE_EXPLODING:
            DragonFireballCheckExplodingAnimEnded();
            break;
        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}