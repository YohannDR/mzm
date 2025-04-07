#include "sprites_AI/zebbo.h"
#include "macros.h"

#include "data/sprites/zebbo.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 2f058 | 58 | Initializes a zebbo sprite
 * 
 */
void ZebboInit(void)
{
    gCurrentSprite.hitboxTop = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    gCurrentSprite.hitboxBottom = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    gCurrentSprite.work1 = 1 * DELTA_TIME;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
    gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
    // Save spawn position for the respawn
    gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
    gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
}

/**
 * @brief 2f0b0 | 3c | Initializes a zebbo to be idle
 * 
 */
void ZebboIdleInit(void)
{
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pose = ZEBBO_POSE_IDLE;

    gCurrentSprite.pOam = sZebboOAM_Idle;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    gCurrentSprite.bgPriority = 2;
}

/**
 * @brief 2f0ec | 164 | Handles a zebbo being idle
 * 
 */
void ZebboIdle(void)
{
    u16 samusX;
    u16 samusY;
    u16 spriteY;
    u16 spriteX;
    u8 ramSlot;
    s32 distance;

    if (gCurrentSprite.spriteId == PSPRITE_ZEBBO_GREEN_FOLLOWER)
    {
        // Directly go up if follower
        gCurrentSprite.pose = ZEBBO_POSE_GOING_UP;
        gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    }
    else if ((gCurrentSprite.spriteId != PSPRITE_ZEBBO_GREEN_LEADER ||
        SpriteUtilCountPrimarySpritesWithCurrentSpriteRAMSlot(PSPRITE_ZEBBO_GREEN_FOLLOWER) == 0)
        && !SpriteUtilCheckHasDrops())
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
                // TODO : make the ternary a macro
                if (ABS_DIFF(spriteX, samusX) <= (HALF_BLOCK_SIZE + PIXEL_SIZE) ||
                    SpriteUtilCheckSamusNearSpriteAboveBelow(BLOCK_SIZE * 5, BLOCK_SIZE * 5) != NSAB_ABOVE)
                    return;
                else
                {
                    // Samus in range, set going up
                    gCurrentSprite.scaling = gSamusData.yPosition;
                    gCurrentSprite.pose = ZEBBO_POSE_GOING_UP;
                    gCurrentSprite.work0 = 2 * DELTA_TIME;
                    gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    
                    SpriteUtilMakeSpriteFaceSamusXFlip();
    
                    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                        SoundPlay(SOUND_ZEBBO_RISING);
    
                    if (gCurrentSprite.spriteId == PSPRITE_ZEBBO_GREEN_LEADER)
                    {
                        // First follower
                        ramSlot = SpriteSpawnDropFollowers(PSPRITE_ZEBBO_GREEN_FOLLOWER, gCurrentSprite.roomSlot,
                            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                            gCurrentSprite.yPosition + (BLOCK_SIZE + HALF_BLOCK_SIZE),
                            gCurrentSprite.xPosition - HALF_BLOCK_SIZE, gCurrentSprite.status & SPRITE_STATUS_X_FLIP);
    
                        if (ramSlot != UCHAR_MAX)
                        {
                            gSpriteData[ramSlot].scaling = gCurrentSprite.scaling;
                            gSpriteData[ramSlot].work0 = CONVERT_SECONDS(1.f / 6);
    
                            // Second follower
                            ramSlot = SpriteSpawnDropFollowers(PSPRITE_ZEBBO_GREEN_FOLLOWER, gCurrentSprite.roomSlot,
                                gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                                gCurrentSprite.yPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE),
                                gCurrentSprite.xPosition - HALF_BLOCK_SIZE, gCurrentSprite.status & SPRITE_STATUS_X_FLIP);
    
                            if (ramSlot != UCHAR_MAX)
                            {
                                gSpriteData[ramSlot].scaling = gCurrentSprite.scaling;
                                gSpriteData[ramSlot].work0 = CONVERT_SECONDS(0.3f);
                            }
                        }
                    }
                }
            }
        }
    }
}

/**
 * @brief 2f250 | 80 | Handles a zebbo going up
 * 
 */
void ZebboGoingUp(void)
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
            gCurrentSprite.pose = ZEBBO_POSE_MOVING;
            gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);

            gCurrentSprite.pOam = sZebboOAM_Moving;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;

            gCurrentSprite.bgPriority = 1;
        }
    }
}

/**
 * @brief 2f2d0 | 64 | Handles a zebbo respawning
 * 
 */
void ZebboRespawn(void)
{
    if (gCurrentSprite.spriteId == PSPRITE_ZEBBO_GREEN_FOLLOWER)
        gCurrentSprite.status = 0; // Kill if not leader
    else
    {
        // Set spawn position
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn;

        ZebboIdleInit();

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
 * @brief 2f334 | c8 | Handles a zebbo moving
 * 
 */
void ZebboMove(void)
{
    if (gCurrentSprite.work0 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == 0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(SOUND_ZEBBO_MOVING);
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
                ZebboRespawn();
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
                ZebboRespawn();
                return;
            }
            else
                gCurrentSprite.xPosition -= EIGHTH_BLOCK_SIZE + 1 * PIXEL_SIZE; // Move
        }
        // CONVERT_SECONDS(.25f) + DELTA_TIME
        if (MOD_AND(gCurrentSprite.work1, 16) == 0 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(SOUND_ZEBBO_MOVING);
    }
}

/**
 * @brief 2f3fc | 138 | Zebbo AI
 * 
 */
void Zebbo(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_ZEBBO_DAMAGED);
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
                ZebboInit();

            case ZEBBO_POSE_IDLE_INIT:
                ZebboIdleInit();

            case ZEBBO_POSE_IDLE:
                ZebboIdle();
                break;

            case ZEBBO_POSE_GOING_UP:
                ZebboGoingUp();
                break;

            case ZEBBO_POSE_MOVING:
                ZebboMove();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_RESPAWNING, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                ZebboRespawn();
        }
    }
}