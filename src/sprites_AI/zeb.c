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
    gCurrentSprite.hitboxTop = -(EIGHTH_BLOCK_SIZE);
    gCurrentSprite.hitboxBottom = QUARTER_BLOCK_SIZE + PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE + PIXEL_SIZE);
    gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE + PIXEL_SIZE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    gCurrentSprite.work1 = 1 * DELTA_TIME;
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
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    gCurrentSprite.bgPriority = 2;
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
        if (gCurrentSprite.work1 != 0)
        {
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work1);
        }
        else
        {
            samusY = gSamusData.yPosition;
            samusX = gSamusData.xPosition;
            spriteY = gCurrentSprite.yPosition;
            spriteX = gCurrentSprite.xPosition;

            if (samusY <= spriteY - (HALF_BLOCK_SIZE - PIXEL_SIZE / 2))
            {
                if (ABS_DIFF(spriteX, samusX) <= (HALF_BLOCK_SIZE + PIXEL_SIZE) ||
                    SpriteUtilCheckSamusNearSpriteAboveBelow(BLOCK_SIZE * 5, BLOCK_SIZE * 5) != NSAB_ABOVE)
                    return;
                else
                {
                    // Samus in range
                    gCurrentSprite.scaling = gSamusData.yPosition;
                    gCurrentSprite.pose = ZEB_POSE_GOING_UP;
                    gCurrentSprite.work0 = 2 * DELTA_TIME;
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

    gCurrentSprite.yPosition -= EIGHTH_BLOCK_SIZE;
    if (gCurrentSprite.work0 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == 0)
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    }
    else
    {
        if (gCurrentSprite.scaling < gSamusData.yPosition && gSamusData.yPosition > gCurrentSprite.yPositionSpawn - BLOCK_SIZE * 2)
            yPosition = gCurrentSprite.scaling;
        else
            yPosition = gSamusData.yPosition;

        if (yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE) > gCurrentSprite.yPosition)
        {
            // Reached samus, set moving
            gCurrentSprite.pose = ZEB_POSE_MOVING;
            gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);

            gCurrentSprite.pOam = sZebOAM_Moving;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;

            gCurrentSprite.bgPriority = 1;
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

    gCurrentSprite.work1 = CONVERT_SECONDS(1.f);
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.invincibilityStunFlashTimer = 0;
    gCurrentSprite.paletteRow = 0;
    gCurrentSprite.frozenPaletteRowOffset = 0;
    gCurrentSprite.absolutePaletteRow = 0;
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    gCurrentSprite.freezeTimer = 0;
}

/**
 * @brief 1c444 | c8 | Handles a zeb moving
 * 
 */
void ZebMove(void)
{
    if (gCurrentSprite.work0 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == 0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(SOUND_ZEB_MOVING);
            gCurrentSprite.work1 = 0;
        }
    }
    else
    {
        APPLY_DELTA_TIME_INC(gCurrentSprite.work1);
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            // Check should respawn
            if (gCurrentSprite.xPosition - gSamusData.xPosition > (SCREEN_SIZE_X_SUB_PIXEL + BLOCK_SIZE) || gCurrentSprite.xPosition & 0x8000) // xPos < 0
            {
                ZebRespawn();
                return;
            }
            else
                gCurrentSprite.xPosition += EIGHTH_BLOCK_SIZE + 1 * PIXEL_SIZE; // Move
        }
        else
        {
            // Check should respawn
            if (gSamusData.xPosition - gCurrentSprite.xPosition > (SCREEN_SIZE_X_SUB_PIXEL + BLOCK_SIZE) || gCurrentSprite.xPosition & 0x8000) // xPos < 0
            {
                ZebRespawn();
                return;
            }
            else
                gCurrentSprite.xPosition -= EIGHTH_BLOCK_SIZE + 1 * PIXEL_SIZE; // Move
        }
        // CONVERT_SECONDS(.25f) + DELTA_TIME
        if (MOD_AND(gCurrentSprite.work1, 16) == 0 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
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

    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
    }
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;
        
        switch (gCurrentSprite.pose)
        {
            case SPRITE_POSE_UNINITIALIZED:
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
