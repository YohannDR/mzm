#include "sprites_AI/geega.h"
#include "macros.h"

#include "data/sprites/geega.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 40230 | 60 | Initializes a geega sprite
 * 
 */
void GeegaInit(void)
{
    gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE - PIXEL_SIZE);
    gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE - PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE - EIGHTH_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE - EIGHTH_BLOCK_SIZE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);

    gCurrentSprite.work1 = 1 * DELTA_TIME;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
    gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
    // Save spawn position for the respawn
    gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
    gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
}

/**
 * @brief 40290 | 3c | Initializes a geega to be idle
 * 
 */
void GeegaIdleInit(void)
{
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pose = GEEGA_POSE_IDLE;

    gCurrentSprite.pOam = sGeegaOAM_Idle;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    gCurrentSprite.bgPriority = 2;
}

/**
 * @brief 402cc | 118 | Handles a geega being idle
 * 
 */
void GeegaIdle(void)
{
    u16 samusX;
    u16 samusY;
    u16 spriteY;
    u16 spriteX;
    u8 ramSlot;
    s32 distance;

    if (gCurrentSprite.spriteId == PSPRITE_GEEGA_FOLLOWER)
    {
        // Directly go up if follower
        gCurrentSprite.pose = GEEGA_POSE_GOING_UP;
        gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    }
    else if ((gCurrentSprite.spriteId != PSPRITE_GEEGA_LEADER ||
        SpriteUtilCountPrimarySpritesWithCurrentSpriteRAMSlot(PSPRITE_GEEGA_FOLLOWER) == 0)
        && !SpriteUtilCheckHasDrops())
    {
        if (gCurrentSprite.work1 != 0)
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work1);
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
                    // Samus in range, set going up
                    gCurrentSprite.scaling = gSamusData.yPosition;
                    gCurrentSprite.pose = GEEGA_POSE_GOING_UP;
                    gCurrentSprite.work0 = 2 * DELTA_TIME;
                    gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    
                    SpriteUtilMakeSpriteFaceSamusXFlip();
    
                    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                        SoundPlay(SOUND_GEEGA_RISING);
    
                    if (gCurrentSprite.spriteId == PSPRITE_GEEGA_LEADER)
                    {
                        // Spawn follower
                        ramSlot = SpriteSpawnDropFollowers(PSPRITE_GEEGA_FOLLOWER, gCurrentSprite.roomSlot,
                            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                            gCurrentSprite.yPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE),
                            gCurrentSprite.xPosition - HALF_BLOCK_SIZE, gCurrentSprite.status & SPRITE_STATUS_X_FLIP);
    
                        if (ramSlot != UCHAR_MAX)
                        {
                            gSpriteData[ramSlot].scaling = gCurrentSprite.scaling;
                            gSpriteData[ramSlot].work0 = CONVERT_SECONDS(.3f);
                        }
                    }
                }
            }
        }
    }
}

/**
 * @brief 403e4 | 80 | Handles a geega going up
 * 
 */
void GeegaGoingUp(void)
{
    u16 positionRange;

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
            positionRange = gCurrentSprite.scaling;
        else
            positionRange = gSamusData.yPosition;

        if (positionRange - (BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE) > gCurrentSprite.yPosition)
        {
            // Reached samus, set moving
            gCurrentSprite.pose = GEEGA_POSE_MOVING;
            gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);

            gCurrentSprite.pOam = sGeegaOAM_Moving;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.bgPriority = 1;
        }
    }
}

/**
 * @brief 40464 | 94 | Handles a geega respawning
 * 
 */
void GeegaRespawn(void)
{
    if (gCurrentSprite.spriteId == PSPRITE_GEEGA_FOLLOWER)
        gCurrentSprite.status = 0; // Kill if not leader
    else
    {
        // Set spawn position
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn;

        GeegaIdleInit();

        gCurrentSprite.work1 = CONVERT_SECONDS(1.f);
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

        gCurrentSprite.invincibilityStunFlashTimer = 0;
        gCurrentSprite.paletteRow = 0;
        gCurrentSprite.frozenPaletteRowOffset = 0;
        gCurrentSprite.absolutePaletteRow = 0;
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        gCurrentSprite.freezeTimer = 0;
    }
}

/**
 * @brief 404c8 | c8 | Handles a geega moving
 * 
 */
void GeegaMove(void)
{
    if (gCurrentSprite.work0 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == 0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(SOUND_GEEGA_MOVING);

            gCurrentSprite.work1 = 0;
        }
    }
    else
    {
        APPLY_DELTA_TIME_INC(gCurrentSprite.work1);
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            // Check should respawn
            if (gCurrentSprite.xPosition - gSamusData.xPosition > BLOCK_SIZE * 16 || gCurrentSprite.xPosition & 0x8000) // xPos < 0
            {
                GeegaRespawn();
                return;
            }
            else
                gCurrentSprite.xPosition += 3 * PIXEL_SIZE; // Move
        }
        else
        {
            // Check should respawn
            if (gSamusData.xPosition - gCurrentSprite.xPosition > BLOCK_SIZE * 16 || gCurrentSprite.xPosition & 0x8000) // xPos < 0
            {
                GeegaRespawn();
                return;
            }
            else
                gCurrentSprite.xPosition -= 3 * PIXEL_SIZE; // Move
        }

        // CONVERT_SECONDS(.25f) + 1 * DELTA_TIME
        if (MOD_AND(gCurrentSprite.work1, 16) == 0 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(SOUND_GEEGA_MOVING);
    }
}

/**
 * @brief 4058c | 13c | Geega AI
 * 
 */
void Geega(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_GEEGA_DAMAGED);
    }

    if (gCurrentSprite.freezeTimer != 0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;

        switch (gCurrentSprite.pose)
        {
            case SPRITE_POSE_UNINITIALIZED:
                GeegaInit();

            case GEEGA_POSE_IDLE_INIT:
                GeegaIdleInit();

            case GEEGA_POSE_IDLE:
                GeegaIdle();
                break;

            case GEEGA_POSE_GOING_UP:
                GeegaGoingUp();
                break;

            case GEEGA_POSE_MOVING:
                GeegaMove();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_RESPAWNING, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                GeegaRespawn();
        }
    }
}