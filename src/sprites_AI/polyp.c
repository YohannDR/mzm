#include "polyp.h"
#include "../../data/data.h"
#include "../globals.h"

const i16 sPolypProjectileYVelocity[44] = {
    -16, -16, -14, -14, -12, -12, -10, -10, -8, -8, -8, -8,
    -6, -6, -6, -6, -5, -5, -4, -4, -3, -2, -1, 0, 0, 0, 0, 0, 1,
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16, 18, SPRITE_ARRAY_TERMINATOR
};

const u32 sPolypGFX[241];
const u16 sPolypPAL[16];

const u16 sPolypOAM_Idle_Frame0[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220
};

const u16 sPolypOAM_Idle_Frame1[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220
};

const u16 sPolypOAM_Idle_Frame2[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

const u16 sPolypOAM_Warning_Frame3[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
}; 

const u16 sPolypOAM_Warning_Frame2[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

const u16 sPolypOAM_Warning_Frame1[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

const u16 sPolypOAM_Warning_Frame0[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

const u16 sPolypOAM_AfterSpitting_Frame2[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

const u16 sPolypProjectileOAM_Right_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

const u16 sPolypProjectileOAM_Right_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212
};

const u16 sPolypProjectileOAM_Right_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214
};

const u16 sPolypProjectileOAM_Right_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216
};

const u16 sPolypProjectileOAM_Left_Frame0[4] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

const u16 sPolypProjectileOAM_Left_Frame1[4] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212
};

const u16 sPolypProjectileOAM_Left_Frame2[4] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214
};

const u16 sPolypProjectileOAM_Left_Frame3[4] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216
};

const u16 sPolypProjectileOAM_Exploding_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x218
};

const u16 sPolypProjectileOAM_Exploding_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a
};

const u16 sPolypProjectileOAM_Exploding_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c
};

const u16 sPolypProjectileOAM_Exploding_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21e
};

const struct FrameData sPolypOAM_Idle[5] = {
    sPolypOAM_Idle_Frame0,
    0x10,
    sPolypOAM_Idle_Frame1,
    0x10,
    sPolypOAM_Idle_Frame2,
    0x10,
    sPolypOAM_Idle_Frame1,
    0x10,
    NULL,
    0x0
};

const struct FrameData sPolypOAM_Warning[5] = {
    sPolypOAM_Warning_Frame0,
    0x2,
    sPolypOAM_Warning_Frame1,
    0x2,
    sPolypOAM_Warning_Frame2,
    0x2,
    sPolypOAM_Warning_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sPolypOAM_Spitting[2] = {
    sPolypOAM_Warning_Frame2,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sPolypOAM_AfterSpitting[4] = {
    sPolypOAM_Warning_Frame1,
    0x2,
    sPolypOAM_Warning_Frame0,
    0x2,
    sPolypOAM_AfterSpitting_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sPolypOAM_Retracting[3] = {
    sPolypOAM_Warning_Frame0,
    0x2,
    sPolypOAM_Warning_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sPolypProjectileOAM_Right[5] = {
    sPolypProjectileOAM_Right_Frame0,
    0x6,
    sPolypProjectileOAM_Right_Frame1,
    0x6,
    sPolypProjectileOAM_Right_Frame2,
    0x6,
    sPolypProjectileOAM_Right_Frame3,
    0x6,
    NULL,
    0x0
};

const struct FrameData sPolypProjectileOAM_Left[5] = {
    sPolypProjectileOAM_Left_Frame0,
    0x6,
    sPolypProjectileOAM_Left_Frame1,
    0x6,
    sPolypProjectileOAM_Left_Frame2,
    0x6,
    sPolypProjectileOAM_Left_Frame3,
    0x6,
    NULL,
    0x0
};

const struct FrameData sPolypProjectileOAM_Exploding[5] = {
    sPolypProjectileOAM_Exploding_Frame0,
    0x4,
    sPolypProjectileOAM_Exploding_Frame1,
    0x4,
    sPolypProjectileOAM_Exploding_Frame2,
    0x4,
    sPolypProjectileOAM_Exploding_Frame3,
    0x4,
    NULL,
    0x0
};


/**
 * @brief 36ec4 | 4c | Initializes a polyp sprite
 * 
 */
void PolypInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x18;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = -0x38;
    gCurrentSprite.hitboxRightOffset = 0x28;

    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

    gCurrentSprite.samusCollision = SSC_KNOCKS_BACK_SAMUS;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
}

/**
 * @brief 36f10 | 24 | Initializes a polyp to be idle
 * 
 */
void PolypIdleInit(void)
{
    gCurrentSprite.pose = POLYP_POSE_IDLE;
    gCurrentSprite.pOam = sPolypOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.timer = 0x78; // Delay before spitting
}

/**
 * @brief 36f34 | 74 | Checks if the polyp should be shooting a projectile
 * 
 */
void PolypCheckSpawnProjectile(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        // Shoot if on screen, not already shooted and projectile doesn't have an active drop
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN &&
            SpriteUtilCountSecondarySpritesWithCurrentSpriteRAMSlot(SSPRITE_POLYP_PROJECTILE) == 0x0 &&
            !SpriteUtilCheckHasDrops())
        {
            // Set warning behavior
            gCurrentSprite.pose = POLYP_POSE_WARNING;
            gCurrentSprite.pOam = sPolypOAM_Warning;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(0x17C);
        }
        else
        {
            // Can't shoot, reset timer
            gCurrentSprite.timer = 0x78;
        }
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
        gCurrentSprite.pOam = sPolypOAM_Spitting;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.timer = 0x14;
    }
}

/**
 * @brief 36fd8 | 64 | Handles the polyp spitting
 * 
 */
void PolypSpawnProjectile(void)
{
    if (--gCurrentSprite.timer == 0x0)
    {
        // Set after spitting behavior
        gCurrentSprite.pose = POLYP_POSE_AFTER_SPITTING;
        gCurrentSprite.pOam = sPolypOAM_AfterSpitting;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
    else if (gCurrentSprite.timer == 0x4)
    {
        // Spawn projectile
        SpriteSpawnSecondary(SSPRITE_POLYP_PROJECTILE, gCurrentSprite.roomSlot,
            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
            gCurrentSprite.yPosition - (HALF_BLOCK_SIZE), gCurrentSprite.xPosition, 0x0);
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
        gCurrentSprite.pOam = sPolypOAM_Retracting;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
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

    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

    gCurrentSprite.hitboxTopOffset = -0x10;
    gCurrentSprite.hitboxBottomOffset = 0x10;
    gCurrentSprite.hitboxLeftOffset = -0x10;
    gCurrentSprite.hitboxRightOffset = 0x10;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = 0x8;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 0x5;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];

    // Try set same direction samus
    nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 5, BLOCK_SIZE * 8 + 0x26);
    if (nslr == NSLR_RIGHT)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    else if (nslr != NSLR_LEFT)
        SpriteUtilChooseRandomXDirection(); // Random if can't find samus

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.pOam = sPolypProjectileOAM_Right;
    else
        gCurrentSprite.pOam = sPolypProjectileOAM_Left;

    gCurrentSprite.timer = 0x4;
    gCurrentSprite.arrayOffset = 0x0;
}

/**
 * @brief 37164 | 48 | Handles the spawning of a polyp projectile
 * 
 */
void PolypProjectileSpawn(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer != 0x0)
    {
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(0x17D);
    }
}

/**
 * @brief 371ac | 88 | Handles the movement of a polyp projectile
 * 
 */
void PolypProjectileMove(void)
{
    u16 xMovement;
    i32 yMovement;
    u8 offset;

    xMovement = 0x4;

    // Y movement
    offset = gCurrentSprite.arrayOffset;
    yMovement = sPolypProjectileYVelocity[offset];
    if (yMovement == SPRITE_ARRAY_TERMINATOR)
    {
        yMovement = sPolypProjectileYVelocity[offset - 1];
        gCurrentSprite.yPosition += yMovement;
    }
    else
    {
        gCurrentSprite.arrayOffset = offset + 1;
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
        gCurrentSprite.pose = 0x42;
}

/**
 * @brief 37234 | 50 | Initializes a polyp projectile to be exploding
 * 
 */
void PolypProjectileExplodingInit(void)
{
    gCurrentSprite.pOam = sPolypProjectileOAM_Exploding;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = 0x43;
    gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(0x17E);
}

/**
 * @brief 37284 | 24 | Checks if the exploding animation ended
 * 
 */
void PolypProjectileCheckExplodingAnimEnded(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0; // Kill sprite
}

/**
 * @brief 372a8 | 11c | Polyp AI
 * 
 */
void Polyp(void)
{
    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        switch (gCurrentSprite.pose)
        {
            case 0x0:
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
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
        }
    }
}

/**
 * @brief 373c4 | 78 | Polyp projectile AI
 * 
 */
void PolypProjectile(void)
{
    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        switch (gCurrentSprite.pose)
        {
            case 0x0:
                PolypProjectileInit();
                break;

            case 0x8:
                PolypProjectileSpawn();
                break;

            case 0x9:
                PolypProjectileMove();
                break;

            case 0x42:
                PolypProjectileExplodingInit();

            case 0x43:
                PolypProjectileCheckExplodingAnimEnded();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
        }
    }
}