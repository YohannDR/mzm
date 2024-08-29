#include "sprites_AI/zebbo.h"
#include "macros.h"

#include "data/sprites/zebbo.h"
#include "data/sprite_data.h"

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
    gCurrentSprite.hitboxTop = -0x18;
    gCurrentSprite.hitboxBottom = 0x18;
    gCurrentSprite.hitboxLeft = -0x18;
    gCurrentSprite.hitboxRight = 0x18;

    gCurrentSprite.drawDistanceTop = 0x8;
    gCurrentSprite.drawDistanceBottom = 0x8;
    gCurrentSprite.drawDistanceHorizontal = 0x10;

    gCurrentSprite.work1 = 0x1;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    gCurrentSprite.yPosition -= 0x20;
    gCurrentSprite.xPosition += 0x20;
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
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    gCurrentSprite.bgPriority = 0x2;
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
        SpriteUtilCountPrimarySpritesWithCurrentSpriteRAMSlot(PSPRITE_ZEBBO_GREEN_FOLLOWER) == 0x0)
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
                    gCurrentSprite.pose = ZEBBO_POSE_GOING_UP;
                    gCurrentSprite.work0 = 0x2;
                    gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    
                    SpriteUtilMakeSpriteFaceSamusXFlip();
    
                    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                        SoundPlay(0x162);
    
                    if (gCurrentSprite.spriteId == PSPRITE_ZEBBO_GREEN_LEADER)
                    {
                        // First follower
                        ramSlot = SpriteSpawnDropFollowers(PSPRITE_ZEBBO_GREEN_FOLLOWER, gCurrentSprite.roomSlot,
                            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                            gCurrentSprite.yPosition + (BLOCK_SIZE + HALF_BLOCK_SIZE),
                            gCurrentSprite.xPosition - HALF_BLOCK_SIZE, gCurrentSprite.status & SPRITE_STATUS_X_FLIP);
    
                        if (ramSlot != 0xFF)
                        {
                            gSpriteData[ramSlot].scaling = gCurrentSprite.scaling;
                            gSpriteData[ramSlot].work0 = 0xA;
    
                            // Second follower
                            ramSlot = SpriteSpawnDropFollowers(PSPRITE_ZEBBO_GREEN_FOLLOWER, gCurrentSprite.roomSlot,
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
 * @brief 2f250 | 80 | Handles a zebbo going up
 * 
 */
void ZebboGoingUp(void)
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
        if (gCurrentSprite.scaling < gSamusData.yPosition && gSamusData.yPosition > (s32)(gCurrentSprite.yPositionSpawn - BLOCK_SIZE * 2))
            positionRange = gCurrentSprite.scaling;
        else
            positionRange = gSamusData.yPosition;

        if (positionRange - 0x64 > gCurrentSprite.yPosition)
        {
            // Reached samus, set moving
            gCurrentSprite.pose = ZEBBO_POSE_MOVING;
            gCurrentSprite.work0 = 0xA;

            gCurrentSprite.pOam = sZebboOAM_Moving;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.bgPriority = 0x1;
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
        gCurrentSprite.status = 0x0; // Kill if not leader
    else
    {
        // Set spawn position
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn;

        ZebboIdleInit();

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
 * @brief 2f334 | c8 | Handles a zebbo moving
 * 
 */
void ZebboMove(void)
{
    if (gCurrentSprite.work0 != 0x0)
    {
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0x0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(0x163);

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
                ZebboRespawn();
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
                ZebboRespawn();
                return;
            }
            else
                gCurrentSprite.xPosition -= 0xC; // Move
        }

        if (!(gCurrentSprite.work1 & 0xF) && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(0x163);
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
            SoundPlayNotAlreadyPlaying(0x164);
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