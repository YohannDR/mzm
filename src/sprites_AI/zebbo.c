#include "sprites_AI/zebbo.h"
#include "data/sprites/zebbo.h"
#include "constants/particle.h"
#include "data/sprite_data.h"
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
    gCurrentSprite.hitboxTopOffset = -0x18;
    gCurrentSprite.hitboxBottomOffset = 0x18;
    gCurrentSprite.hitboxLeftOffset = -0x18;
    gCurrentSprite.hitboxRightOffset = 0x18;

    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

    gCurrentSprite.workVariable = 0x1;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];

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
    i32 distance;

    if (gCurrentSprite.spriteID == PSPRITE_ZEBBO_GREEN_FOLLOWER)
    {
        // Directly go up if follower
        gCurrentSprite.pose = ZEBBO_POSE_GOING_UP;
        gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    }
    else if ((gCurrentSprite.spriteID != PSPRITE_ZEBBO_GREEN_LEADER ||
        SpriteUtilCountPrimarySpritesWithCurrentSpriteRAMSlot(PSPRITE_ZEBBO_GREEN_FOLLOWER) == 0x0)
        && !SpriteUtilCheckHasDrops())
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
                    // Samus in range, set going up
                    gCurrentSprite.oamScaling = gSamusData.yPosition;
                    gCurrentSprite.pose = ZEBBO_POSE_GOING_UP;
                    gCurrentSprite.timer = 0x2;
                    gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    
                    SpriteUtilMakeSpriteFaceSamusXFlip();
    
                    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                        SoundPlay(0x162);
    
                    if (gCurrentSprite.spriteID == PSPRITE_ZEBBO_GREEN_LEADER)
                    {
                        // First follower
                        ramSlot = SpriteSpawnDropFollowers(PSPRITE_ZEBBO_GREEN_FOLLOWER, gCurrentSprite.roomSlot,
                            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                            gCurrentSprite.yPosition + (BLOCK_SIZE + HALF_BLOCK_SIZE),
                            gCurrentSprite.xPosition - HALF_BLOCK_SIZE, gCurrentSprite.status & SPRITE_STATUS_XFLIP);
    
                        if (ramSlot != 0xFF)
                        {
                            gSpriteData[ramSlot].oamScaling = gCurrentSprite.oamScaling;
                            gSpriteData[ramSlot].timer = 0xA;
    
                            // Second follower
                            ramSlot = SpriteSpawnDropFollowers(PSPRITE_ZEBBO_GREEN_FOLLOWER, gCurrentSprite.roomSlot,
                                gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                                gCurrentSprite.yPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE),
                                gCurrentSprite.xPosition - HALF_BLOCK_SIZE, gCurrentSprite.status & SPRITE_STATUS_XFLIP);
    
                            if (ramSlot != 0xFF)
                            {
                                gSpriteData[ramSlot].oamScaling = gCurrentSprite.oamScaling;
                                gSpriteData[ramSlot].timer = 0x12;
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
    if (gCurrentSprite.timer != 0x0)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    }
    else
    {
        if (gCurrentSprite.oamScaling < gSamusData.yPosition && gSamusData.yPosition > (i32)(gCurrentSprite.yPositionSpawn - BLOCK_SIZE * 2))
            positionRange = gCurrentSprite.oamScaling;
        else
            positionRange = gSamusData.yPosition;

        if (positionRange - 0x64 > gCurrentSprite.yPosition)
        {
            // Reached samus, set moving
            gCurrentSprite.pose = ZEBBO_POSE_MOVING;
            gCurrentSprite.timer = 0xA;

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
    if (gCurrentSprite.spriteID == PSPRITE_ZEBBO_GREEN_FOLLOWER)
        gCurrentSprite.status = 0x0; // Kill if not leader
    else
    {
        // Set spawn position
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn;

        ZebboIdleInit();

        gCurrentSprite.workVariable = 0x3C;
        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];

        gCurrentSprite.invincibilityStunFlashTimer = 0x0;
        gCurrentSprite.paletteRow = 0x0;
        gCurrentSprite.frozenPaletteRowOffset = 0x0;
        gCurrentSprite.absolutePaletteRow = 0x0;
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        gCurrentSprite.freezeTimer = 0x0;
    }
}

/**
 * @brief 2f334 | c8 | Handles a zebbo moving
 * 
 */
void ZebboMove(void)
{
    if (gCurrentSprite.timer != 0x0)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(0x163);

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

        if (!(gCurrentSprite.workVariable & 0xF) && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
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