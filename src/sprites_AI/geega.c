#include "sprites_AI/geega.h"
#include "macros.h"

#include "data/sprites/geega.h"
#include "data/sprite_data.h"

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
    gCurrentSprite.hitboxTop = -0x1C;
    gCurrentSprite.hitboxBottom = 0x1C;
    gCurrentSprite.hitboxLeft = -0x18;
    gCurrentSprite.hitboxRight = 0x18;

    gCurrentSprite.drawDistanceTop = 0xA;
    gCurrentSprite.drawDistanceBottom = 0xA;
    gCurrentSprite.drawDistanceHorizontal = 0xC;

    gCurrentSprite.work1 = 0x1;
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
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    gCurrentSprite.bgPriority = 0x2;
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
        SpriteUtilCountPrimarySpritesWithCurrentSpriteRAMSlot(PSPRITE_GEEGA_FOLLOWER) == 0x0)
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
                // TODO : make the ternary a macro
                if ((spriteX > samusX ? spriteX - samusX : samusX - spriteX) <= 0x24 ||
                    SpriteUtilCheckSamusNearSpriteAboveBelow(BLOCK_SIZE * 5, BLOCK_SIZE * 5) != NSAB_ABOVE)
                    return;
                else
                {
                    // Samus in range, set going up
                    gCurrentSprite.scaling = gSamusData.yPosition;
                    gCurrentSprite.pose = GEEGA_POSE_GOING_UP;
                    gCurrentSprite.work0 = 0x2;
                    gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    
                    SpriteUtilMakeSpriteFaceSamusXFlip();
    
                    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                        SoundPlay(0x183);
    
                    if (gCurrentSprite.spriteId == PSPRITE_GEEGA_LEADER)
                    {
                        // Spawn follower
                        ramSlot = SpriteSpawnDropFollowers(PSPRITE_GEEGA_FOLLOWER, gCurrentSprite.roomSlot,
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

/**
 * @brief 403e4 | 80 | Handles a geega going up
 * 
 */
void GeegaGoingUp(void)
{
    u16 positionRange;

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
            positionRange = gCurrentSprite.scaling;
        else
            positionRange = gSamusData.yPosition;

        if (positionRange - 0x64 > gCurrentSprite.yPosition)
        {
            // Reached samus, set moving
            gCurrentSprite.pose = GEEGA_POSE_MOVING;
            gCurrentSprite.work0 = 0xA;

            gCurrentSprite.pOam = sGeegaOAM_Moving;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.bgPriority = 0x1;
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
        gCurrentSprite.status = 0x0; // Kill if not leader
    else
    {
        // Set spawn position
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn;

        GeegaIdleInit();

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
 * @brief 404c8 | c8 | Handles a geega moving
 * 
 */
void GeegaMove(void)
{
    if (gCurrentSprite.work0 != 0x0)
    {
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0x0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(0x184);

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
                GeegaRespawn();
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
                GeegaRespawn();
                return;
            }
            else
                gCurrentSprite.xPosition -= 0xC; // Move
        }

        if (!(gCurrentSprite.work1 & 0xF) && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(0x184);
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
            SoundPlayNotAlreadyPlaying(0x185);
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