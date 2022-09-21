#include "sprites_AI/zeb.h"
#include "data/data.h"
#include "data/sprites/zeb.c"
#include "data/sprite_data.c"
#include "globals.h"

/**
 * @brief 1c238 | 60 | Initializes a zeb sprite
 * 
 */
void ZebInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x8;
    gCurrentSprite.hitboxBottomOffset = 0x14;
    gCurrentSprite.hitboxLeftOffset = -0x1C;
    gCurrentSprite.hitboxRightOffset = 0x1C;

    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

    gCurrentSprite.workVariable = 0x1;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];

    gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
    gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
    // Save spawn position
    gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
    gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
}

/**
 * @brief 1c298 | 3c | Initializes a zeb to be idle
 * 
 */
void ZebIdleInit(void)
{
    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.pose = ZEB_POSE_IDLE;
    gCurrentSprite.pOam = sZebOAM_Idle;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    gCurrentSprite.bgPriority = 0x2;
}

/**
 * @brief 1c2d4 | 98 | Handles a zeb being idle
 * 
 */
void ZebIdle(void)
{
    u16 samusX;
    u16 samusY;
    u16 spriteX;
    u16 spriteY;
    i32 offset;

    if (!SpriteUtilCheckHasDrops())
    {
        if (gCurrentSprite.workVariable != 0x0)
            gCurrentSprite.workVariable--;
        else
        {
            samusY = gSamusData.yPosition;
            samusX = gSamusData.xPosition;
            spriteY = gCurrentSprite.yPosition;
            spriteX = gCurrentSprite.xPosition;

            if (samusY <= spriteY - 0x1E)
            {
                // TODO : make the ternary a macro
                if ((spriteX > samusX ? spriteX - samusX : samusX - spriteX) <= 0x24 ||
                    SpriteUtilCheckSamusNearSpriteAboveBelow(BLOCK_SIZE * 5, BLOCK_SIZE * 5) != NSAB_ABOVE)
                    return;
                else
                {
                    // Samus in range
                    gCurrentSprite.oamScaling = gSamusData.yPosition;
                    gCurrentSprite.pose = ZEB_POSE_GOING_UP;
                    gCurrentSprite.timer = 0x2;
                    gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);

                    SpriteUtilMakeSpriteFaceSamusXFlip();

                    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                        SoundPlay(0x144);
                }
            }   
        }
    }
}

/**
 * @brief 1c36c | 80 | Handles a zeb going up
 * 
 */
void ZebGoingUp(void)
{
    u16 yPosition;

    gCurrentSprite.yPosition -= 0x8;
    if (gCurrentSprite.timer != 0x0)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    }
    else
    {
        if (gCurrentSprite.oamScaling < gSamusData.yPosition && gSamusData.yPosition >= gCurrentSprite.yPositionSpawn - BLOCK_SIZE * 2)
            yPosition = gCurrentSprite.oamScaling;
        else
            yPosition = gSamusData.yPosition;

        if (yPosition - 0x64 > gCurrentSprite.yPosition)
        {
            gCurrentSprite.pose = ZEB_POSE_GOING_UP;
            gCurrentSprite.timer = 0xA;

            gCurrentSprite.pOam = sZebOAM_Moving;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;

            gCurrentSprite.bgPriority = 0x1;
        }
    }
}

/**
 * @brief 1c3ec | 58 | Handles a zeb respawning
 * 
 */
void ZebRespawn(void)
{
    // Set spawn position
    gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
    gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn;

    ZebIdleInit();

    gCurrentSprite.workVariable = 0x3C;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.invicibilityStunFlashTimer = 0x0;
    gCurrentSprite.paletteRow = 0x0;
    gCurrentSprite.frozenPaletteRowOffset = 0x0;
    gCurrentSprite.absolutePaletteRow = 0x0;
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.freezeTimer = 0x0;
}

/**
 * @brief 1c444 | c8 | Handles a zeb moving
 * 
 */
void ZebMove(void)
{
    if (gCurrentSprite.timer != 0x0)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(0x145);
            gCurrentSprite.workVariable = 0x0;
        }
    }
    else
    {
        gCurrentSprite.workVariable++;
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            // Check should respawn
            if (gCurrentSprite.xPosition - gSamusData.xPosition > BLOCK_SIZE * 16 || gCurrentSprite.xPosition & 0x8000)
            {
                ZebRespawn();
                return;
            }
            else
                gCurrentSprite.xPosition += 0xC; // Move
        }
        else
        {
            // Check should respawn
            if (gSamusData.xPosition - gCurrentSprite.xPosition > BLOCK_SIZE * 16 || gCurrentSprite.xPosition & 0x8000)
            {
                ZebRespawn();
                return;
            }
            else
                gCurrentSprite.xPosition -= 0xC; // Move
        }
        if (!(gCurrentSprite.workVariable & 0xF) && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(0x145);
    }
}

/**
 * @brief 1c50c | 138 | Zeb AI
 * 
 */
void Zeb(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x146);
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
                ZebInit();

            case ZEB_POSE_IDLE_INIT:
                ZebIdleInit();

            case ZEB_POSE_IDLE:
                ZebIdle();
                break;

            case ZEB_POSE_GOING_UP:
                ZebGoingUp();
                break;

            case ZEB_POSE_MOVING:
                ZebMove();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_RESPAWNING, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                ZebRespawn();
        }
    }
}