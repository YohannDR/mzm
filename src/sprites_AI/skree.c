#include "sprites_AI/skree.h"
#include "data/sprites/skree.c"
#include "constants/particle.h"
#include "data/sprite_data.c"
#include "constants/clipdata.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "structs/display.h"
#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 1c644 | 50 | Initializes a skree sprite
 * 
 */
void SkreeInit(void)
{
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawDistanceTopOffset = 0x0;
    gCurrentSprite.drawDistanceBottomOffset = 0x20;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

    gCurrentSprite.hitboxTopOffset = 0x0;
    gCurrentSprite.hitboxBottomOffset = 0x60;
    gCurrentSprite.hitboxLeftOffset = -0x18;
    gCurrentSprite.hitboxRightOffset = 0x18;

    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.yPosition -= BLOCK_SIZE;
}

/**
 * @brief 1c694 | 1c | Initializes a skree to be idle
 * 
 */
void SkreeIdleInit(void)
{
    gCurrentSprite.pOam = sSkreeOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = SKREE_POSE_DETECTING_SAMUS;
}

/**
 * @brief 1c6b0 | 50 | Checks if samus is in the range of the skree
 * 
 */
void SkreeDetectSamus(void)
{
    if (gSamusData.yPosition > gCurrentSprite.yPosition &&
        gSamusData.yPosition - gCurrentSprite.yPosition < 0x284 &&
        gCurrentSprite.status & SPRITE_STATUS_ONSCREEN &&
        gSamusData.xPosition > gCurrentSprite.xPosition - 0x96 &&
        gSamusData.xPosition < gCurrentSprite.xPosition + 0x96)
    {
        // Set spinning
        gCurrentSprite.pose = SKREE_POSE_SPINNING_INIT;
    }
}

/**
 * @brief 1c700 | 1c | Initializes a skree to be spinning
 * 
 */
void SkreeSpinningInit(void)
{
    gCurrentSprite.pOam = sSkreeOAM_Spinning;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = SKREE_POSE_SPINNING;
}

/**
 * @brief 1c71c | 1c | Checks if the spin animation ended
 * 
 */
void SkreeCheckSpinAnimEnded(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = SKREE_POSE_GOING_DOWN_INIT;
}

/**
 * @brief 1c738 | 68 | Initializes a skree to be going down
 * 
 */
void SkreeGoingDownInit(void)
{
    gCurrentSprite.pOam = sSkreeOAM_GoingDown;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.workVariable2 = 0x0;
    gCurrentSprite.pose = SKREE_POSE_GOING_DOWN;

    if (gCurrentSprite.xPosition > gSamusData.xPosition)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(0x141);
}

/**
 * @brief 1c7a0 | fc | Handles a skree going down
 * 
 */
void SkreeGoDown(void)
{
    u32 block;
    u32 xMovement;
    u32 yMovement;
    u32 offset;

    block = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.hitboxBottomOffset + gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != 0x0)
    {
        gCurrentSprite.yPosition = block - gCurrentSprite.hitboxBottomOffset;
        gCurrentSprite.pose = SKREE_POSE_CRASHING;
        gCurrentSprite.timer = 0x0;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(0x142);
    }
    else
    {
        xMovement = gCurrentSprite.workVariable2 >> 0x2;
        offset = gCurrentSprite.arrayOffset;
        yMovement = sSkreeFallingSpeed[offset];
        if (yMovement == SHORT_MAX)
        {
            yMovement = sSkreeFallingSpeed[offset - 0x1];
            gCurrentSprite.yPosition += yMovement;
        }
        else
        {
            gCurrentSprite.arrayOffset++;
            gCurrentSprite.yPosition += yMovement;
        }

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition + (HALF_BLOCK_SIZE));
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                return;
            gCurrentSprite.xPosition += xMovement;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition - (HALF_BLOCK_SIZE));
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                return;
            gCurrentSprite.xPosition -= xMovement;
        }

        if (xMovement < 0x10)
            gCurrentSprite.workVariable2++;
    }
}

/**
 * @brief 1c89c | 128 | Handles a skree crashing on the ground
 * 
 */
void SkreeCrashGround(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;
    u8 spriteID;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    gCurrentSprite.timer++;

    switch (gCurrentSprite.timer)
    {
        case 0x1:
            yPosition += 0x48;
            SpriteDebrisInit(0x0, 0x11, yPosition - 0x10, xPosition);
            SpriteDebrisInit(0x0, 0x12, yPosition, xPosition + 0xC);
            SpriteDebrisInit(0x0, 0x13, yPosition - 0x2A, xPosition + 0x14);
            SpriteDebrisInit(0x0, 0x4, yPosition - 0x18, xPosition - 0x1E);
            break;

        case 0x28:
            gCurrentSprite.pOam = sSkreeOAM_Crashing;
            break;

        case 0x3C:
            gfxSlot = gCurrentSprite.spritesetGFXSlot;
            ramSlot = gCurrentSprite.primarySpriteRAMSlot;

            if (gCurrentSprite.spriteID == PSPRITE_SKREE_BLUE)
                spriteID = SSPRITE_BLUE_SKREE_EXPLOSION;
            else
                spriteID = SSPRITE_SKREE_EXPLOSION;
            
            SpriteSpawnSecondary(spriteID, SKREE_EXPLOSION_PART_GOING_UP, gfxSlot, ramSlot, yPosition - 0x8, xPosition, 0x0);
            SpriteSpawnSecondary(spriteID, SKREE_EXPLOSION_PART_GOING_UP, gfxSlot, ramSlot, yPosition - 0x8, xPosition, SPRITE_STATUS_XFLIP);
            SpriteSpawnSecondary(spriteID, SKREE_EXPLOSION_PART_GOING_DOWN, gfxSlot, ramSlot, yPosition + 0x8, xPosition - 0xC, 0x0);
            SpriteSpawnSecondary(spriteID, SKREE_EXPLOSION_PART_GOING_DOWN, gfxSlot, ramSlot, yPosition + 0x8, xPosition + 0xC, SPRITE_STATUS_XFLIP);
            gCurrentSprite.status = 0x0;
            ParticleSet(yPosition + 0x24, xPosition, PE_SPRITE_EXPLOSION_HUGE);
            SoundPlay(0x134);
    }
}

/**
 * @brief 1c9c4 | b4 | Initializes a skree explosion sprite
 * 
 */
void SkreeExplosionInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    
    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
    
    gCurrentSprite.hitboxTopOffset = -0xC;
    gCurrentSprite.hitboxBottomOffset = 0xC;
    gCurrentSprite.hitboxLeftOffset = -0xC;
    gCurrentSprite.hitboxRightOffset = 0xC;
    
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 0x3;
    gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
    
    gCurrentSprite.yPosition += 0x28;
    gCurrentSprite.status |= (SPRITE_STATUS_DOUBLE_SIZE | SPRITE_STATUS_ROTATION_SCALING);
    gCurrentSprite.oamScaling = 0x100;
    gCurrentSprite.oamRotation = 0x0;

    if (gCurrentSprite.roomSlot != SKREE_EXPLOSION_PART_GOING_UP)
        gCurrentSprite.pOam = sSkreeExplosionOAM_GoingDown;
    else
        gCurrentSprite.pOam = sSkreeExplosionOAM_GoingUp;
}

/**
 * @brief 1ca78 | 68 | Handles the movement of a skree explosion sprite
 * 
 */
void SkreeExplosionMove(void)
{
    if (gCurrentSprite.currentAnimationFrame > 0x1)
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        gCurrentSprite.xPosition += 0x8;
        gCurrentSprite.oamRotation += 0x20;
    }
    else
    {
        gCurrentSprite.xPosition -= 0x8;
        gCurrentSprite.oamRotation -= 0x20;
    }

    if (gCurrentSprite.roomSlot != SKREE_EXPLOSION_PART_GOING_UP)
        gCurrentSprite.yPosition += 0x4;
    else
        gCurrentSprite.yPosition -= 0x4;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}

/**
 * @brief 1cae0 | 194 | Skree AI
 * 
 */
void Skree(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x143);
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
                SkreeInit();

            case 0x8:
                SkreeIdleInit();

            case SKREE_POSE_DETECTING_SAMUS:
                SkreeDetectSamus();
                break;

            case SKREE_POSE_SPINNING_INIT:
                SkreeSpinningInit();

            case SKREE_POSE_SPINNING:
                SkreeCheckSpinAnimEnded();
                break;

            case SKREE_POSE_GOING_DOWN_INIT:
                SkreeGoingDownInit();

            case SKREE_POSE_GOING_DOWN:
                SkreeGoDown();
                break;

            case SKREE_POSE_CRASHING:
                SkreeCrashGround();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition + 0x34, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
        }
    }
}

/**
 * @brief 1cc74 | 24 | Skree explosion AI
 * 
 */
void SkreeExplosion(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            SkreeExplosionInit();

        case 0x9:
            SkreeExplosionMove();
    }
}