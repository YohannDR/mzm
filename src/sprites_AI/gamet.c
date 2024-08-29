#include "sprites_AI/gamet.h"
#include "macros.h"

#include "data/sprites/gamet.h"
#include "data/sprite_data.h"

#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 2e610 | 60 | Initializes a gamet sprite
 * 
 */
void GametInit(void)
{
    gCurrentSprite.hitboxTop = -0x1C;
    gCurrentSprite.hitboxBottom = 0x1C;
    gCurrentSprite.hitboxLeft = -0x18;
    gCurrentSprite.hitboxRight = 0x18;

    gCurrentSprite.drawDistanceTop = 0x8;
    gCurrentSprite.drawDistanceBottom = 0x8;
    gCurrentSprite.drawDistanceHorizontal = 0x10;

    gCurrentSprite.work1 = 0x1;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
    gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
    // Save spawn position for the respawn
    gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
    gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
}

/**
 * @brief 2e670 | Initializes a gamet to be idle
 * 
 */
void GametIdleInit(void)
{
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pose = GAMET_POSE_IDLE;

    gCurrentSprite.pOam = sGametOAM_Idle;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    gCurrentSprite.bgPriority = 0x2;
}

/**
 * @brief 2e6ac | 168 | Handles a gamet being idle
 * 
 */
void GametIdle(void)
{
    u16 samusX;
    u16 samusY;
    u16 spriteY;
    u16 spriteX;
    u8 ramSlot;
    s32 distance;

    if (gCurrentSprite.spriteId == PSPRITE_GAMET_BLUE_FOLLOWER)
    {
        // Directly go up if follower
        gCurrentSprite.pose = GAMET_POSE_GOING_UP;
        gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    }
    else if ((gCurrentSprite.spriteId != PSPRITE_GAMET_BLUE_LEADER ||
        SpriteUtilCountPrimarySpritesWithCurrentSpriteRAMSlot(PSPRITE_GAMET_BLUE_FOLLOWER) == 0x0)
        && !SpriteUtilCheckHasDrops())
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
                if ((spriteX > samusX ? spriteX - samusX : samusX - spriteX) <= 0x24 ||
                    SpriteUtilCheckSamusNearSpriteAboveBelow(BLOCK_SIZE * 5, BLOCK_SIZE * 5) != NSAB_ABOVE)
                    return;
                else
                {
                    // Samus in range, set going up
                    gCurrentSprite.scaling = gSamusData.yPosition;
                    gCurrentSprite.pose = GAMET_POSE_GOING_UP;
                    gCurrentSprite.work0 = 0x2;
                    gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    
                    SpriteUtilMakeSpriteFaceSamusXFlip();
    
                    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                        SoundPlay(0x179);
    
                    if (gCurrentSprite.spriteId == PSPRITE_GAMET_BLUE_LEADER)
                    {
                        // First follower
                        ramSlot = SpriteSpawnDropFollowers(PSPRITE_GAMET_BLUE_FOLLOWER, gCurrentSprite.roomSlot,
                            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                            gCurrentSprite.yPosition + (BLOCK_SIZE + HALF_BLOCK_SIZE),
                            gCurrentSprite.xPosition - HALF_BLOCK_SIZE, gCurrentSprite.status & SPRITE_STATUS_X_FLIP);
    
                        if (ramSlot != 0xFF)
                        {
                            gSpriteData[ramSlot].scaling = gCurrentSprite.scaling;
                            gSpriteData[ramSlot].work0 = 0xA;
    
                            // Second follower
                            ramSlot = SpriteSpawnDropFollowers(PSPRITE_GAMET_BLUE_FOLLOWER, gCurrentSprite.roomSlot,
                                gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                                gCurrentSprite.yPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE),
                                gCurrentSprite.xPosition - HALF_BLOCK_SIZE, gCurrentSprite.status & SPRITE_STATUS_X_FLIP);
    
                            if (ramSlot != 0xFF)
                            {
                                gSpriteData[ramSlot].scaling = gCurrentSprite.scaling;
                                gSpriteData[ramSlot].work0 = 0x12;
                            }
                        }
                    }
                }
            }
        }
    }
}

/**
 * @brief 2e814 | 80 | Handles a gamet going up
 * 
 */
void GametGoingUp(void)
{
    u16 positionRange;

    // Move Y
    gCurrentSprite.yPosition -= 0x8;

    // Damage delay
    if (gCurrentSprite.work0 != 0x0)
    {
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0x0)
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    }
    else
    {
        if (gCurrentSprite.scaling < gSamusData.yPosition && gSamusData.yPosition > gCurrentSprite.yPositionSpawn - BLOCK_SIZE * 2)
            positionRange = gCurrentSprite.scaling;
        else
            positionRange = gSamusData.yPosition;

        if (positionRange - 0x64 > gCurrentSprite.yPosition)
        {
            // Reached samus, set moving
            gCurrentSprite.pose = GAMET_POSE_MOVING;
            gCurrentSprite.work0 = 0xA;

            gCurrentSprite.pOam = sGametOAM_Moving;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;

            gCurrentSprite.bgPriority = 0x1;
        }
    }
}

/**
 * @brief 2e894 | 64 | Handles a gamet respawning
 * 
 */
void GametRespawn(void)
{
    if (gCurrentSprite.spriteId == PSPRITE_GAMET_BLUE_FOLLOWER)
        gCurrentSprite.status = 0x0; // Kill if not leader
    else
    {
        // Set spawn position
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn;

        GametIdleInit();

        gCurrentSprite.work1 = 0x3C;
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

        gCurrentSprite.invincibilityStunFlashTimer = 0x0;
        gCurrentSprite.paletteRow = 0x0;
        gCurrentSprite.frozenPaletteRowOffset = 0x0;
        gCurrentSprite.absolutePaletteRow = 0x0;
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        gCurrentSprite.freezeTimer = 0x0;
    }
}

/**
 * @brief 2e8f8 | d4 | Handles a gamet moving
 * 
 */
void GametMove(void)
{
    if (gCurrentSprite.work0 != 0x0)
    {
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0x0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(0x17A);

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
                GametRespawn();
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
                GametRespawn();
                return;
            }
            else
                gCurrentSprite.xPosition -= 0xC; // Move
        }

        if (!(gCurrentSprite.work1 & 0xF) && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(0x17A);
    }
}

/**
 * @brief 2e9bc | 13c | Gamet AI
 * 
 */
void Gamet(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x17B);
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
                GametInit();

            case GAMET_POSE_IDLE_INIT:
                GametIdleInit();

            case GAMET_POSE_IDLE:
                GametIdle();
                break;

            case GAMET_POSE_GOING_UP:
                GametGoingUp();
                break;

            case GAMET_POSE_MOVING:
                GametMove();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_RESPAWNING, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                GametRespawn();
                break;
        }
    }
}
