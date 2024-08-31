#include "sprites_AI/zeb.h"
#include "macros.h"

#include "data/sprites/zeb.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 1c238 | 60 | Initializes a zeb sprite
 * 
 */
void ZebInit(void)
{
    gCurrentSprite.hitboxTop = -0x8;
    gCurrentSprite.hitboxBottom = 0x14;
    gCurrentSprite.hitboxLeft = -0x1C;
    gCurrentSprite.hitboxRight = 0x1C;

    gCurrentSprite.drawDistanceTop = 0x8;
    gCurrentSprite.drawDistanceBottom = 0x8;
    gCurrentSprite.drawDistanceHorizontal = 0x10;

    gCurrentSprite.work1 = 0x1;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

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
    s32 offset;

    if (!SpriteUtilCheckHasDrops())
    {
        if (gCurrentSprite.work1 != 0x0)
            gCurrentSprite.work1--;
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
                    gCurrentSprite.scaling = gSamusData.yPosition;
                    gCurrentSprite.pose = ZEB_POSE_GOING_UP;
                    gCurrentSprite.work0 = 0x2;
                    gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);

                    SpriteUtilMakeSpriteFaceSamusXFlip();

                    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                        SoundPlay(SOUND_ZEB_RISING);
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
    if (gCurrentSprite.work0 != 0x0)
    {
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0x0)
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    }
    else
    {
        if (gCurrentSprite.scaling < gSamusData.yPosition && gSamusData.yPosition > gCurrentSprite.yPositionSpawn - BLOCK_SIZE * 2)
            yPosition = gCurrentSprite.scaling;
        else
            yPosition = gSamusData.yPosition;

        if (yPosition - 0x64 > gCurrentSprite.yPosition)
        {
            gCurrentSprite.pose = ZEB_POSE_MOVING;
            gCurrentSprite.work0 = 0xA;

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

    gCurrentSprite.work1 = 0x3C;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.invincibilityStunFlashTimer = 0x0;
    gCurrentSprite.paletteRow = 0x0;
    gCurrentSprite.frozenPaletteRowOffset = 0x0;
    gCurrentSprite.absolutePaletteRow = 0x0;
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    gCurrentSprite.freezeTimer = 0x0;
}

/**
 * @brief 1c444 | c8 | Handles a zeb moving
 * 
 */
void ZebMove(void)
{
    if (gCurrentSprite.work0 != 0x0)
    {
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0x0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(SOUND_ZEB_MOVING);
            gCurrentSprite.work1 = 0x0;
        }
    }
    else
    {
        gCurrentSprite.work1++;
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
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
        if (!(gCurrentSprite.work1 & 0xF) && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(SOUND_ZEB_MOVING);
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
            SoundPlayNotAlreadyPlaying(SOUND_ZEB_DAMAGED);
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
