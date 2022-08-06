#include "dragon.h"
#include "../../data/data.h"
#include "../globals.h"

const i16 sDragonFireballYMovement[40] = {
    -12, -12, -12, -12, -10, -10, -10, -10, -8, -8, -8, -8,
    -6, -6, -6, -6, -5, -5, -4, -4, -3, -2, -1, 0, 1, 2, 3,
    4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16, 18, SPRITE_ARRAY_TERMINATOR
};

const i16 sDragonFireballOAMRotation[40] = {
    0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 6, 8, 10, 12, 14, 16, 16,
    20, 24, 28, 29, 30, 31, 32, 33, 34, 35, 36, 40, 44, 48,
    52, 56, 60, 64, 64, 64, 64, SPRITE_ARRAY_TERMINATOR
};

const u32 sDragonGFX[512];
const u16 sDragonPAL[32];

const u16 sDragonOAM_Spitting_Frame0[7] = {
    0x2,
    0xe6, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
OBJ_SHAPE_VERTICAL | 0x3, OBJ_SIZE_16x32 | 0x1f6, OBJ_SPRITE_OAM | 0x20d
};

const u16 sDragonOAM_Spitting_Frame1[7] = {
    0x2,
    0xe5, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0x3, OBJ_SIZE_16x32 | 0x1f7, OBJ_SPRITE_OAM | 0x20d
};

const u16 sDragonOAM_Idle_Frame0[7] = {
    0x2,
    0x6, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x24b,
    0xe9, OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sDragonOAM_Idle_Frame1[7] = {
    0x2,
    0xea, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x207,
    0x4, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x24b
};

const u16 sDragonOAM_Idle_Frame2[13] = {
    0x4,
    0xe9, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xe9, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xf9, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x245,
    0x5, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x24b
};

const u16 sDragonOAM_TurningAround_Frame0[7] = {
    0x2,
    0xe9, OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20f,
    0x5, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x215
};

const u16 sDragonOAM_TurningAround_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_SIZE_16x32 | 0x1fa, OBJ_SPRITE_OAM | 0x213,
    0x5, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x255
};

const u16 sDragonOAM_Unused_0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1fb, OBJ_SPRITE_OAM | 0x213,
    0x5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fc, OBJ_SPRITE_OAM | 0x255
};

const u16 sDragonOAM_Unused_1[7] = {
    0x2,
    0xe9, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1ec, OBJ_SPRITE_OAM | 0x20f,
    0x5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x215
};

const u16 sDragonFireballOAM_Moving_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25a
};

const u16 sDragonFireballOAM_Moving_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25c
};

const u16 sDragonFireballOAM_Moving_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x25e
};

const u16 sDragonFireballOAM_Exploding_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a
};

const u16 sDragonFireballOAM_Exploding_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c
};

const u16 sDragonFireballOAM_Exploding_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21e
};

const u16 sDragonFireballOAM_Exploding_Frame3[4] = {
    0x1,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x121e
};

const struct FrameData sDragonOAM_Idle[4] = {
    sDragonOAM_Idle_Frame0,
    0xC,
    sDragonOAM_Idle_Frame1,
    0xC,
    sDragonOAM_Idle_Frame2,
    0xC,
    NULL,
    0x0
};

const struct FrameData sDragonOAM_Warning[3] = {
    sDragonOAM_Idle_Frame0,
    0x6,
    sDragonOAM_Idle_Frame1,
    0x6,
    NULL,
    0x0
};

const struct FrameData sDragonOAM_Spitting[3] = {
    sDragonOAM_Spitting_Frame0,
    0x4,
    sDragonOAM_Spitting_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sDragonOAM_TurningAround[3] = {
    sDragonOAM_TurningAround_Frame0,
    0x3,
    sDragonOAM_TurningAround_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sDragonOAM_TurningAroundPart2[3] = {
    sDragonOAM_TurningAround_Frame1,
    0x3,
    sDragonOAM_TurningAround_Frame0,
    0x3,
    NULL,
    0x0
};

const struct FrameData sDragonFireballOAM_Moving[4] = {
    sDragonFireballOAM_Moving_Frame0,
    0x1,
    sDragonFireballOAM_Moving_Frame1,
    0x4,
    sDragonFireballOAM_Moving_Frame2,
    0x4,
    NULL,
    0x0
};

const struct FrameData sDragonFireballOAM_Exploding[5] = {
    sDragonFireballOAM_Exploding_Frame0,
    0x4,
    sDragonFireballOAM_Exploding_Frame1,
    0x4,
    sDragonFireballOAM_Exploding_Frame2,
    0x4,
    sDragonFireballOAM_Exploding_Frame3,
    0x4,
    NULL,
    0x0
};


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
        if ((i32)(ySpawn - 0x7F) < gCurrentSprite.yPosition)
            gCurrentSprite.yPosition -= 0x2;
        SpriteUtilCheckOutOfRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_SMALL);
    }
    else
    {
        if ((i32)(ySpawn - 0x2) > gCurrentSprite.yPosition)
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

    if (yMovement == SPRITE_ARRAY_TERMINATOR)
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