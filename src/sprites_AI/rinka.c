#include "sprites_AI/rinka.h"
#include "sprites_AI/zebetite_and_cannon.h"
#include "syscalls.h"
#include "macros.h"

#include "data/sprites/rinka.h"
#include "data/sprites/zebetite_and_cannon.h"
#include "data/sprite_data.h"

#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/event.h"
#include "constants/samus.h"

#include "structs/display.h"
#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 3630c | 98 | Initializes a rinka sprite
 * 
 */
void RinkaInit(void)
{
    gCurrentSprite.hitboxTop = -0x14;
    gCurrentSprite.hitboxBottom = 0x14;
    gCurrentSprite.hitboxLeft = -0x14;
    gCurrentSprite.hitboxRight = 0x14;

    gCurrentSprite.drawDistanceTop = 0x8;
    gCurrentSprite.drawDistanceBottom = 0x8;
    gCurrentSprite.drawDistanceHorizontal = 0x8;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.yPosition -= (HALF_BLOCK_SIZE);

    // Get spawn tile position
    gCurrentSprite.work3 = (gCurrentSprite.yPosition - (HALF_BLOCK_SIZE)) >> 6;
    gCurrentSprite.work2 = (gCurrentSprite.xPosition - (HALF_BLOCK_SIZE)) >> 6;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 0x3;
    gCurrentSprite.bgPriority = gIoRegistersBackup.BG1CNT & 0x3;
    gCurrentSprite.work1 = 0x0;

    if (gCurrentSprite.spriteId != PSPRITE_RINKA_GREEN && gCurrentSprite.spriteId != PSPRITE_RINKA_ORANGE)
        gCurrentSprite.frozenPaletteRowOffset = 0x1;
}

/**
 * @brief 363a4 | 3c | Initializes a rinka to be spawning
 * 
 */
void RinkaSpawningInit(void)
{
    gCurrentSprite.pose = RINKA_POSE_SPAWNING;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    if (gCurrentSprite.spriteId == PSPRITE_RINKA_GREEN)
    {
        gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
        gCurrentSprite.pOam = sRinkaGreenOAM_Spawning;
    }
    else
        gCurrentSprite.pOam = sRinkaOrangeOAM_Spawning;
}

/**
 * @brief 363e0 | 94 | Handles a rinka respawning
 * 
 */
void RinkaRespawn(void)
{
    // Set spawn position
    gCurrentSprite.yPosition = (gCurrentSprite.work3 * BLOCK_SIZE) + (HALF_BLOCK_SIZE);
    gCurrentSprite.xPosition = (gCurrentSprite.work2 * BLOCK_SIZE) + (HALF_BLOCK_SIZE);

    RinkaSpawningInit();
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.invincibilityStunFlashTimer = 0x0;
    gCurrentSprite.paletteRow = 0x0;
    gCurrentSprite.frozenPaletteRowOffset = 0x0;
    gCurrentSprite.absolutePaletteRow = 0x0;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    gCurrentSprite.freezeTimer = 0x0;

    // Set spawn delay
    if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
        gCurrentSprite.work1 = 0x14; // Green rinka
    else
        gCurrentSprite.work1 = 0x3C; // Orange rinka

    gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    // Duplicated code
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
}

/**
 * @brief 36474 | 118 | Handles a rinka spawning
 * 
 */
void RinkaSpawning(void)
{
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;

    // Spawn delay
    if (gCurrentSprite.work1 != 0x0)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        gCurrentSprite.work1--;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
        {
            gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.work0 = 0xB;
            }
        }
        else
        {
            // Vulnerability delay
            if (gCurrentSprite.work0 != 0x0)
            {
                gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
                gCurrentSprite.work0--;
                if (gCurrentSprite.work0 == 0x0)
                    gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
            }
            else if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                if (gCurrentSprite.spriteId == PSPRITE_RINKA_GREEN)
                    gCurrentSprite.pOam = sRinkaGreenOAM_Moving;
                else
                    gCurrentSprite.pOam = sRinkaOrangeOAM_Moving;

                gCurrentSprite.pose = RINKA_POSE_MOVING;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.scaling = 0x0;

                samusY = gSamusData.yPosition - 0x3C;
                samusX = gSamusData.xPosition;
                spriteY = gCurrentSprite.yPosition;
                spriteX = gCurrentSprite.xPosition;

                // Set destination position
                gCurrentSprite.yPositionSpawn = samusY;
                gCurrentSprite.xPositionSpawn = samusX;

                // Set direction
                if (samusY < spriteY)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
                else
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

                    
                if (samusX < spriteX)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                else
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            }
        }
    }
}

/**
 * @brief 3658c | 234 | Handles a rinka moving
 * 
 */
void RinkaMove(void)
{
    u16 velocity;
    u32 spawnY;
    u32 spawnX;
    u8 respawn;
    u16 distanceYDown;
    u16 distanceYUp;
    u16 distanceXLeft;
    u16 distanceXRight;
    s32 totalDistance;
    u16 samusY;
    u16 spriteY;
    u16 acceleration;

    respawn = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
        velocity = 0x5;
    else
        velocity = 0x4;

    acceleration = ++gCurrentSprite.scaling;
    velocity *= (acceleration);

    spawnY = gCurrentSprite.work3 * BLOCK_SIZE + (HALF_BLOCK_SIZE);
    spawnX = gCurrentSprite.work2 * BLOCK_SIZE + (HALF_BLOCK_SIZE);

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        distanceYUp = gCurrentSprite.yPositionSpawn - spawnY;
    else
        distanceYDown = spawnY - gCurrentSprite.yPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        distanceXRight = gCurrentSprite.xPositionSpawn - spawnX;
    else
        distanceXLeft = spawnX - gCurrentSprite.xPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYUp * distanceYUp);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((s32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((s32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYDown * distanceYDown);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY - ((velocity * ((s32)(distanceYDown << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((s32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYUp * distanceYUp);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((s32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX - ((velocity * ((s32)(distanceXLeft << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYDown * distanceYDown);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY - ((velocity * ((s32)(distanceYDown << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX - ((velocity * ((s32)(distanceXLeft << 0xA) / totalDistance) >> 0xA));
            }
        }
    }

    if (!(gCurrentSprite.xPosition & 0x8000))
    {
        if (gCurrentSprite.xPosition > gSamusData.xPosition)
        {
            if ((gCurrentSprite.xPosition - gSamusData.xPosition) > 0x400)
                respawn++;
        }
        else
        {
            if ((gSamusData.xPosition - gCurrentSprite.xPosition) > 0x400)
                respawn++;
        }
    }
    else
        respawn++;

    if (!(gCurrentSprite.yPosition & 0x8000))
    {
        if (gCurrentSprite.yPosition > gSamusData.yPosition)
        {
            if ((gCurrentSprite.yPosition - gSamusData.yPosition) > 0x400)
                respawn++;
        }
        else
        {
            if ((gSamusData.yPosition - gCurrentSprite.yPosition) > 0x400)
                respawn++;
        }
    }
    else
        respawn++;

    if (respawn)
        RinkaRespawn();
}

/**
 * @brief 367c0 | 20 | Initializes a rinka mother brain to be spawning
 * 
 */
void RinkaMotherBrainSpawningInit(void)
{
    gCurrentSprite.pose = RINKA_POSE_SPAWNING;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.pOam = sRinkaMotherBrainOAM_Spawning;
}

/**
 * @brief 367e0 | 184 | Handles a rinka mother brain respawning
 * 
 */
void RinkaMotherBrainRespawn(void)
{
    u16 spriteY;
    u16 spriteX;
    u16 samusX;
    s32 offset;
    u8* pSprite;

    spriteY = gCurrentSprite.work3 * BLOCK_SIZE + (HALF_BLOCK_SIZE);
    spriteX = gCurrentSprite.work2 * BLOCK_SIZE + (HALF_BLOCK_SIZE);
    samusX = gSamusData.xPosition;

    // Check should be first or second place
    switch (gCurrentSprite.spriteId)
    {
        case PSPRITE_RINKA_MOTHER_BRAIN2:
            offset = 0x28;
            if (samusX < spriteX && (s32)(spriteX - samusX) > (offset * (HALF_BLOCK_SIZE)))
            {
                gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                spriteY += BLOCK_SIZE;
                spriteX -= (BLOCK_SIZE * 40);
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN3:
            offset = 0x22;
            if (samusX < spriteX && (s32)(spriteX - samusX) > (offset * (HALF_BLOCK_SIZE)))
            {
                gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                spriteY -= BLOCK_SIZE;
                spriteX -= (BLOCK_SIZE * 34);
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN4:
            offset = 0x18;
            if (samusX < spriteX && (s32)(spriteX - samusX) > (offset * (HALF_BLOCK_SIZE)))
            {
                gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                spriteX -= (BLOCK_SIZE * 24);
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN5:
            offset = 0x1E;
            if (samusX < spriteX && (s32)(spriteX - samusX) > (offset * (HALF_BLOCK_SIZE)))
            {
                gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                spriteX -= (BLOCK_SIZE * 30);
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN6:
            offset = 0x14;
            if (samusX < spriteX && (s32)(spriteX - samusX) > (offset * (HALF_BLOCK_SIZE)))
            {
                gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                spriteX -= (BLOCK_SIZE * 20);
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            break;
    }

    gCurrentSprite.yPosition = spriteY;
    gCurrentSprite.xPosition = spriteX;
    RinkaMotherBrainSpawningInit();
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.invincibilityStunFlashTimer = 0x0;
    gCurrentSprite.paletteRow = 0x0;
    gCurrentSprite.frozenPaletteRowOffset = 0x1;
    gCurrentSprite.absolutePaletteRow = 0x0;
    pSprite = &gCurrentSprite.ignoreSamusCollisionTimer;
    gCurrentSprite.freezeTimer = 0x0;
    gCurrentSprite.work1 = 0x3C;
    gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    *pSprite = 0x1;
}

/**
 * @brief 36964 | 110 | Handles a rinka mother brain spawning
 * 
 */
void RinkaMotherBrainSpawning(void)
{
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;

    // Spawn delay
    if (gCurrentSprite.work1 != 0x0)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        gCurrentSprite.work1--;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
        {
            gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.work0 = 0xB;
            }
            else
                RinkaMotherBrainRespawn();
        }
        else
        {
            // Vulnerability delay
            if (gCurrentSprite.work0 != 0x0)
            {
                gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
                gCurrentSprite.work0--;
                if (gCurrentSprite.work0 == 0x0)
                    gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
            }
            else if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sRinkaMotherBrainOAM_Moving;

                gCurrentSprite.pose = RINKA_POSE_MOVING;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.scaling = 0x0;

                samusY = gSamusData.yPosition - 0x3C;
                samusX = gSamusData.xPosition;
                spriteY = gCurrentSprite.yPosition;
                spriteX = gCurrentSprite.xPosition;

                // Set destination position
                gCurrentSprite.yPositionSpawn = samusY;
                gCurrentSprite.xPositionSpawn = samusX;

                // Set direction
                if (samusY < spriteY)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
                else
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

                    
                if (samusX < spriteX)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                else
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            }
        }
    }
}

/**
 * @brief 36a74 | 2c0 | Handles the movement of a rinka mother brain
 * 
 */
void RinkaMotherBrainMove(void)
{
    u16 velocity;
    u8 tileY;
    u8 tileX;
    u16 spawnY;
    u16 spawnX;
    u16 distanceYDown;
    u16 distanceYUp;
    u16 distanceXLeft;
    u16 distanceXRight;
    u8 respawn;
    s32 totalDistance;
    u16 samusY;
    u16 spriteY;
    u16 acceleration;

    respawn = FALSE;

    acceleration = ++gCurrentSprite.scaling;
    velocity = acceleration * 4;

    tileX = gCurrentSprite.work2;
    tileY = gCurrentSprite.work3;

    // Check spawn at second place
    switch (gCurrentSprite.spriteId)
    {
        case PSPRITE_RINKA_MOTHER_BRAIN2:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            {
                tileX -= 0x28;
                tileY += 0x1;
            }
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN3:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            {
                tileX -= 0x22;
                tileY -= 0x1;
            }
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN4:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
                tileX -= 0x18;
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN5:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
                tileX -= 0x1E;
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN6:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
                tileX -= 0x14;
            break;
    }

    spawnY = tileY * BLOCK_SIZE + (HALF_BLOCK_SIZE);
    spawnX = tileX * BLOCK_SIZE + (HALF_BLOCK_SIZE);

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        distanceYUp = gCurrentSprite.yPositionSpawn - spawnY;
    else
        distanceYDown = spawnY - gCurrentSprite.yPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        distanceXRight = gCurrentSprite.xPositionSpawn - spawnX;
    else
        distanceXLeft = spawnX - gCurrentSprite.xPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYUp * distanceYUp);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((s32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((s32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYDown * distanceYDown);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY - ((velocity * ((s32)(distanceYDown << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((s32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYUp * distanceYUp);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((s32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX - ((velocity * ((s32)(distanceXLeft << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYDown * distanceYDown);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY - ((velocity * ((s32)(distanceYDown << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX - ((velocity * ((s32)(distanceXLeft << 0xA) / totalDistance) >> 0xA));
            }
        }
    }

    if (!(gCurrentSprite.xPosition & 0x8000))
    {
        if (gCurrentSprite.xPosition > gSamusData.xPosition)
        {
            if ((gCurrentSprite.xPosition - gSamusData.xPosition) > 0x400)
                respawn++;
        }
        else
        {
            if ((gSamusData.xPosition - gCurrentSprite.xPosition) > 0x400)
                respawn++;
        }
    }
    else
        respawn++;

    if (!(gCurrentSprite.yPosition & 0x8000))
    {
        if (gCurrentSprite.yPosition > gSamusData.yPosition)
        {
            if ((gCurrentSprite.yPosition - gSamusData.yPosition) > 0x400)
                respawn++;
        }
        else
        {
            if ((gSamusData.yPosition - gCurrentSprite.yPosition) > 0x400)
                respawn++;
        }
    }
    else
        respawn++;

    if (respawn)
        RinkaMotherBrainRespawn();
}

/**
 * @brief 36d34 | 9c | Rinka AI
 * 
 */
void Rinka(void)
{
    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;

        switch (gCurrentSprite.pose)
        {
            case SPRITE_POSE_UNINITIALIZED:
                RinkaInit();
                
            case RINKA_POSE_SPAWNING_INIT:
                RinkaSpawningInit();

            case RINKA_POSE_SPAWNING:
                RinkaSpawning();
                break;

            case RINKA_POSE_MOVING:
                RinkaMove();
                break;

            default:
                if (SpriteUtilCheckHasDrops())
                {
                    SpriteUtilSpriteDeath(DEATH_NO_DEATH_OR_RESPAWNING_ALREADY_HAS_DROP, gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                }
                else
                {
                    SpriteUtilSpriteDeath(DEATH_RESPAWNING, gCurrentSprite.yPosition, gCurrentSprite.xPosition,
                        TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                }
                RinkaRespawn();
        }
    }
}

/**
 * @brief 36dd0 | f4 | Rinka mother brain AI
 * 
 */
void RinkaMotherBrain(void)
{
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
    {
        // Kill if mother brain is dead
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        {
            if (!(gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN))
                ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SMALL);
        }

        if (gCurrentSprite.standingOnSprite != SAMUS_STANDING_ON_SPRITE_OFF && gSamusData.standingStatus == STANDING_ENEMY)
        {
            gSamusData.standingStatus = STANDING_MIDAIR;
            gCurrentSprite.standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;
        }

        gCurrentSprite.status = 0x0;
    }
    else
    {
        if (gCurrentSprite.freezeTimer != 0)
            SpriteUtilUpdateFreezeTimer();
        else
        {
            if (SpriteUtilIsSpriteStunned())
                return;

            switch (gCurrentSprite.pose)
            {
                case SPRITE_POSE_UNINITIALIZED:
                    RinkaInit();
                    
                case RINKA_POSE_SPAWNING_INIT:
                    RinkaMotherBrainSpawningInit();

                case RINKA_POSE_SPAWNING:
                    RinkaMotherBrainSpawning();
                    break;

                case RINKA_POSE_MOVING:
                    RinkaMotherBrainMove();
                    break;

                default:
                    if (SpriteUtilCheckHasDrops())
                    {
                        SpriteUtilSpriteDeath(DEATH_NO_DEATH_OR_RESPAWNING_ALREADY_HAS_DROP, gCurrentSprite.yPosition,
                            gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                    }
                    else
                    {
                        SpriteUtilSpriteDeath(DEATH_RESPAWNING, gCurrentSprite.yPosition, gCurrentSprite.xPosition,
                            TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
                    }
                    RinkaMotherBrainRespawn();
            }
        }
    }
}