#include "sprites_AI/zebetite_and_cannon.h"

#include "data/sprites/zebetite_and_cannon.h"
#include "data/sprite_data.h"

#include "constants/event.h"
#include "constants/clipdata.h"
#include "constants/game_state.h"
#include "constants/particle.h"
#include "constants/sprite.h"

#include "structs/display.h"
#include "structs/samus.h"
#include "structs/game_state.h"
#include "structs/sprite.h"

/**
 * @brief 406c8 | 30c | Zebetite AI
 * 
 */
void Zebetite(void)
{
    // https://decomp.me/scratch/0Oxa5
    
    u32 alreadyDead;
    u16 maxHealth;
    u16 spawnHealth;
    register u32 health asm("r4");
    u32 phase;
    i32 healthDiff;

    if (gCurrentSprite.pose == 0)
    {
        alreadyDead = FALSE;
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

        switch (gCurrentSprite.spriteID)
        {
            case PSPRITE_ZEBETITE_ONE_AND_THREE:
                if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZEBETITE_ONE_DESTROYED))
                {
                    gCurrentSprite.xPosition -= BLOCK_SIZE * 20;
                    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZEBETITE_THREE_DESTROYED))
                        alreadyDead++;
                }
                break;

            case PSPRITE_ZEBETITE_TWO_AND_FOUR:
                if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZEBETITE_TWO_DESTROYED))
                {
                    gCurrentSprite.xPosition -= BLOCK_SIZE * 20;
                    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZEBETITE_FOUR_DESTROYED))
                        alreadyDead++;
                }
                break;

            default:
                alreadyDead++;
        }

        if (alreadyDead)
        {
            gCurrentSprite.status = 0;
            return;
        }

        gCurrentSprite.drawDistanceTopOffset = 0x30;
        gCurrentSprite.drawDistanceBottomOffset = 0x0;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

        gCurrentSprite.hitboxTopOffset = -BLOCK_SIZE * 3;
        gCurrentSprite.hitboxBottomOffset = 0;
        gCurrentSprite.hitboxLeftOffset = -HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxRightOffset = HALF_BLOCK_SIZE;

        gCurrentSprite.frozenPaletteRowOffset = 1;
        gCurrentSprite.samusCollision = SSC_ZEBETITE;

        gCurrentSprite.pOam = sZebetiteOAM_Phase1;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.drawOrder = 5;
        spawnHealth = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
        gCurrentSprite.health = spawnHealth;
        gCurrentSprite.oamScaling = spawnHealth;

        gCurrentSprite.pose = 9;

        if (gDifficulty == DIFF_EASY)
            gCurrentSprite.timer = 0x3C;
        else
            gCurrentSprite.timer = 0x1E;
    }

    maxHealth = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    health = gCurrentSprite.health;

    healthDiff = maxHealth - health;
    phase = healthDiff / 20;

    if (health == gCurrentSprite.oamScaling)
    {
        if (phase != 0)
        {
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0)
                gCurrentSprite.health += 20;
        }
    }
    else
    {
        if (health < maxHealth)
        {
            if (gDifficulty == DIFF_EASY)
                gCurrentSprite.timer = 0x3C;
            else
                gCurrentSprite.timer = 0x1E;
        }

        gCurrentSprite.oamScaling = gCurrentSprite.health;

        switch (phase)
        {
            case 0:
                if (gCurrentSprite.pOam != sZebetiteOAM_Phase1)
                {
                    SoundPlayNotAlreadyPlaying(0x266);
                    
                    gCurrentSprite.pOam = sZebetiteOAM_Phase1;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
                break;

            case 1:
            case 2:
                if (gCurrentSprite.pOam != sZebetiteOAM_Phase2)
                {
                    if (gCurrentSprite.pOam == sZebetiteOAM_Phase1)
                        SoundPlayNotAlreadyPlaying(0x265);
                    else if (gCurrentSprite.pOam == sZebetiteOAM_Phase4)
                        SoundPlayNotAlreadyPlaying(0x266);
                    
                    gCurrentSprite.pOam = sZebetiteOAM_Phase2;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
                break;

            case 3:
            case 4:
                if (gCurrentSprite.pOam != sZebetiteOAM_Phase4)
                {
                    if (gCurrentSprite.pOam == sZebetiteOAM_Phase2)
                        SoundPlayNotAlreadyPlaying(0x265);
                    else if (gCurrentSprite.pOam == sZebetiteOAM_Phase6)
                        SoundPlayNotAlreadyPlaying(0x266);
                    
                    gCurrentSprite.pOam = sZebetiteOAM_Phase4;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
                break;

            case 5:
            case 6:
                if (gCurrentSprite.pOam != sZebetiteOAM_Phase6)
                {
                    SoundPlayNotAlreadyPlaying(0x265);
                    
                    gCurrentSprite.pOam = sZebetiteOAM_Phase6;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
                break;

            default:
                ParticleSet(gCurrentSprite.yPosition - 0x48, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                SoundPlay(0x12F);

                switch (gCurrentSprite.spriteID)
                {
                    case PSPRITE_ZEBETITE_ONE_AND_THREE:
                        if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ZEBETITE_ONE_DESTROYED))
                        {
                            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                            gCurrentSprite.pose = 0;
                            EventFunction(EVENT_ACTION_SETTING, EVENT_ZEBETITE_ONE_DESTROYED);
                        }
                        else
                        {
                            gCurrentSprite.status = 0;
                            EventFunction(EVENT_ACTION_SETTING, EVENT_ZEBETITE_THREE_DESTROYED);
                        }
                        break;

                    case PSPRITE_ZEBETITE_TWO_AND_FOUR:
                        if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ZEBETITE_TWO_DESTROYED))
                        {
                            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                            gCurrentSprite.pose = 0;
                            EventFunction(EVENT_ACTION_SETTING, EVENT_ZEBETITE_TWO_DESTROYED);
                        }
                        else
                        {
                            gCurrentSprite.status = 0;
                            EventFunction(EVENT_ACTION_SETTING, EVENT_ZEBETITE_FOUR_DESTROYED);
                        }
                        break;

                    default:
                        gCurrentSprite.status = 0;
                }
        }
    }
}

/**
 * @brief 409d4 | 4c | Makes a cannon fire a bullet if possible
 * 
 */
void CannonFireBullet(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && gCurrentSprite.currentAnimationFrame == 1
        && gCurrentSprite.animationDurationCounter == 1)
    {
        SpriteSpawnSecondary(SSPRITE_CANNON_BULLET, gCurrentSprite.workVariable, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    }
}

void CannonCheckSurroundings(void)
{
    u8 rng;

    rng = gSpriteRNG;

    gCurrentSprite.timer = rng * 8 + 10;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + BLOCK_SIZE) != COLLISION_AIR)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.workVariable = CANNON_AIM_DOWN_LEFT;
        gCurrentSprite.arrayOffset = CANNON_VIEW_LEFT;
        gCurrentSprite.pOam = sCannonOAM_AimingDownLeft;
    }
    else if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - BLOCK_SIZE) != COLLISION_AIR)
    {
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.workVariable = CANNON_AIM_DOWN_RIGHT;
        gCurrentSprite.arrayOffset = CANNON_VIEW_RIGHT;
        gCurrentSprite.pOam = sCannonOAM_AimingDownRight;
    }
    else
    {
        if (rng & 1)
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        else
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;

        if (rng > 7)
        {
            gCurrentSprite.workVariable = CANNON_AIM_DOWN_RIGHT;
            gCurrentSprite.pOam = sCannonOAM_AimingDownRight;
        }
        else
        {
            gCurrentSprite.workVariable = CANNON_AIM_DOWN_LEFT;
            gCurrentSprite.pOam = sCannonOAM_AimingDownLeft;
        }

        gCurrentSprite.arrayOffset = CANNON_VIEW_EVERWHERE;
    }
}

/**
 * @brief 40b08 | 61c | Cannon AI
 * 
 */
void Cannon(void)
{
    u8 rng;
    u16 spriteX;
    u16 spriteY;
    u16 samusX;
    u16 range;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
    {
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SMALL);
        
        gCurrentSprite.status = 0;
        return;
    }

    rng = gSpriteRNG;

    if (gCurrentSprite.pose == 0)
    {
        gCurrentSprite.drawDistanceTopOffset = 0x10;
        gCurrentSprite.drawDistanceBottomOffset = 0x10;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

        gCurrentSprite.hitboxTopOffset = -4;
        gCurrentSprite.hitboxBottomOffset = 4;
        gCurrentSprite.hitboxLeftOffset = -4;
        gCurrentSprite.hitboxRightOffset = 4;

        gCurrentSprite.frozenPaletteRowOffset = 1;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawOrder = 5;

        gCurrentSprite.bgPriority = gIoRegistersBackup.BG1CNT & 3;
        gCurrentSprite.pose = 9;

        gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
        CannonCheckSurroundings();

        gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
        gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
        return;
    }

    spriteY = gCurrentSprite.yPositionSpawn;
    spriteX = gCurrentSprite.xPositionSpawn;
    samusX = gSamusData.xPosition;

    switch (gCurrentSprite.spriteID)
    {
        case PSPRITE_CANNON:
            range = 0x14;
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            {
                spriteX -= BLOCK_SIZE * 20;
                if (spriteX < samusX && samusX - spriteX > range * 32)
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
                    gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn;

                    CannonCheckSurroundings();
                }
                else
                    gCurrentSprite.xPosition = spriteX;
            }
            else
            {
                if (samusX < spriteX && spriteX - samusX > range * 32)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                    gCurrentSprite.xPosition = spriteX - BLOCK_SIZE * 20;

                    CannonCheckSurroundings();
                }
                else
                    gCurrentSprite.xPosition = spriteX;
            }
            break;

        case PSPRITE_CANNON2:
            range = 0x18;
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            {
                spriteX -= BLOCK_SIZE * 24;
                if (spriteX < samusX && samusX - spriteX > range * 32)
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
                    gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn;

                    CannonCheckSurroundings();
                }
                else
                    gCurrentSprite.xPosition = spriteX;
            }
            else
            {
                if (samusX < spriteX && spriteX - samusX > range * 32)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                    gCurrentSprite.xPosition = spriteX - BLOCK_SIZE * 24;

                    CannonCheckSurroundings();
                }
                else
                    gCurrentSprite.xPosition = spriteX;
            }
            break;

        case PSPRITE_CANNON3:
            range = 0x18;
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            {
                spriteX -= BLOCK_SIZE * 24;
                if (spriteX < samusX && samusX - spriteX > range * 32)
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
                    gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn;
                    gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;

                    CannonCheckSurroundings();
                }
                else
                {
                    gCurrentSprite.xPosition = spriteX;
                    gCurrentSprite.yPosition = spriteY - BLOCK_SIZE;
                }
            }
            else
            {
                if (samusX < spriteX && spriteX - samusX > range * 32)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                    gCurrentSprite.xPosition = spriteX - BLOCK_SIZE * 24;
                    gCurrentSprite.yPosition = spriteY - BLOCK_SIZE;

                    CannonCheckSurroundings();
                }
                else
                {
                    gCurrentSprite.xPosition = spriteX;
                    gCurrentSprite.yPosition = spriteY;
                }
            }
            break;
    }

    switch (gCurrentSprite.workVariable)
    {
        case CANNON_AIM_LEFT:
            if (gCurrentSprite.pOam == sCannonOAM_ShootingLeft)
            {
                if (SpriteUtilCheckEndCurrentSpriteAnim())
                {
                    gCurrentSprite.pOam = sCannonOAM_AimingLeft;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
                else
                    CannonFireBullet();
            }

            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0)
            {
                gCurrentSprite.timer = 66;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.workVariable++;

                gCurrentSprite.pOam = sCannonOAM_LeftToDownLeftTransition;
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            }
            break;

        case CANNON_AIM_LEFT_TO_DOWN_LEFT_TRANSITION:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (rng > 2)
                        gCurrentSprite.pOam = sCannonOAM_ShootingDownLeft;
                    else
                        gCurrentSprite.pOam = sCannonOAM_AimingDownLeft;

                    gCurrentSprite.workVariable++;
                }
                else
                {
                    if (rng > 10)
                        gCurrentSprite.pOam = sCannonOAM_ShootingLeft;
                    else
                        gCurrentSprite.pOam = sCannonOAM_AimingLeft;

                    gCurrentSprite.workVariable--;
                }

                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            break;

        case CANNON_AIM_DOWN_LEFT:
            if (gCurrentSprite.pOam == sCannonOAM_ShootingDownLeft)
            {
                if (SpriteUtilCheckEndCurrentSpriteAnim())
                {
                    gCurrentSprite.pOam = sCannonOAM_AimingDownLeft;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
                else
                    CannonFireBullet();
            }

            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0)
            {
                gCurrentSprite.timer = 66;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    gCurrentSprite.workVariable++;
                    gCurrentSprite.pOam = sCannonOAM_DownLeftToDownTransition;
                }
                else
                {
                    gCurrentSprite.workVariable--;
                    gCurrentSprite.pOam = sCannonOAM_LeftToDownLeftTransition;
                }
            }
            break;

        case CANNON_AIM_DOWN_LEFT_TO_DOWN_TRANSITION:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (rng > 4)
                        gCurrentSprite.pOam = sCannonOAM_ShootingDown;
                    else
                        gCurrentSprite.pOam = sCannonOAM_AimingDown;

                    gCurrentSprite.workVariable++;
                }
                else
                {
                    if (rng > 2)
                        gCurrentSprite.pOam = sCannonOAM_ShootingDownLeft;
                    else
                        gCurrentSprite.pOam = sCannonOAM_AimingDownLeft;

                    gCurrentSprite.workVariable--;
                }

                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            break;

        case CANNON_AIM_DOWN:
            if (gCurrentSprite.pOam == sCannonOAM_ShootingDown)
            {
                if (SpriteUtilCheckEndCurrentSpriteAnim())
                {
                    gCurrentSprite.pOam = sCannonOAM_AimingDown;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
                else
                    CannonFireBullet();
            }

            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0)
            {
                gCurrentSprite.timer = 66;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                if (gCurrentSprite.arrayOffset != CANNON_VIEW_EVERWHERE)
                    gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    gCurrentSprite.workVariable++;
                    gCurrentSprite.pOam = sCannonOAM_DownToDownRightTransition;
                }
                else
                {
                    gCurrentSprite.workVariable--;
                    gCurrentSprite.pOam = sCannonOAM_DownLeftToDownTransition;
                }
            }
            break;

        case CANNON_AIM_DOWN_TO_DOWN_RIGHT_TRANSITION:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (rng > 2)
                        gCurrentSprite.pOam = sCannonOAM_ShootingDownRight;
                    else
                        gCurrentSprite.pOam = sCannonOAM_AimingDownRight;

                    gCurrentSprite.workVariable++;
                }
                else
                {
                    if (rng > 4)
                        gCurrentSprite.pOam = sCannonOAM_ShootingDown;
                    else
                        gCurrentSprite.pOam = sCannonOAM_AimingDown;
                    gCurrentSprite.workVariable--;
                }

                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            break;

        case CANNON_AIM_DOWN_RIGHT:
            if (gCurrentSprite.pOam == sCannonOAM_ShootingDownRight)
            {
                if (SpriteUtilCheckEndCurrentSpriteAnim())
                {
                    gCurrentSprite.pOam = sCannonOAM_AimingDownRight;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
                else
                    CannonFireBullet();
            }

            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0)
            {
                gCurrentSprite.timer = 66;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    gCurrentSprite.workVariable++;
                    gCurrentSprite.pOam = sCannonOAM_DownRightToRightTransition;
                }
                else
                {
                    gCurrentSprite.workVariable--;
                    gCurrentSprite.pOam = sCannonOAM_DownToDownRightTransition;
                }
            }
            break;

        case CANNON_AIM_DOWN_RIGHT_TO_RIGHT_TRANSITION:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (rng > 10)
                        gCurrentSprite.pOam = sCannonOAM_ShootingRight;
                    else
                        gCurrentSprite.pOam = sCannonOAM_AimingRight;

                    gCurrentSprite.workVariable++;
                }
                else
                {
                    if (rng > 2)
                        gCurrentSprite.pOam = sCannonOAM_ShootingDownRight;
                    else
                        gCurrentSprite.pOam = sCannonOAM_AimingDownRight;

                    gCurrentSprite.workVariable--;
                }

                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            break;

        case CANNON_AIM_RIGHT:
            if (gCurrentSprite.pOam == sCannonOAM_ShootingRight)
            {
                if (SpriteUtilCheckEndCurrentSpriteAnim())
                {
                    gCurrentSprite.pOam = sCannonOAM_AimingRight;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
                else
                    CannonFireBullet();
            }

            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0)
            {
                gCurrentSprite.timer = 66;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                gCurrentSprite.workVariable--;
                gCurrentSprite.pOam = sCannonOAM_DownRightToRightTransition;

                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;

            }
            break;
    }
}

/**
 * @brief 41124 | 184 | Cannon bullet AI
 * 
 */
void CannonBullet(void)
{
    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
    {
        switch (gCurrentSprite.pose)
        {
            case 0:
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
                gCurrentSprite.drawOrder = 2,
                gCurrentSprite.health = 0;

                gCurrentSprite.drawDistanceTopOffset = 8;
                gCurrentSprite.drawDistanceBottomOffset = 8;
                gCurrentSprite.drawDistanceHorizontalOffset = 8;

                gCurrentSprite.hitboxTopOffset = -4;
                gCurrentSprite.hitboxBottomOffset = 4;
                gCurrentSprite.hitboxLeftOffset = -4;
                gCurrentSprite.hitboxRightOffset = 4;

                gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
                gCurrentSprite.pose = 9;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                // Set OAM and base position
                if (gCurrentSprite.roomSlot == CANNON_AIM_LEFT)
                {
                    gCurrentSprite.pOam = sCannonBulletOAM_Left;
                    gCurrentSprite.xPosition -= BLOCK_SIZE;
                }
                else if (gCurrentSprite.roomSlot == CANNON_AIM_DOWN_LEFT)
                {
                    gCurrentSprite.pOam = sCannonBulletOAM_DownLeft;
                    gCurrentSprite.yPosition += (HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
                    gCurrentSprite.xPosition -= (HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
                }
                else if (gCurrentSprite.roomSlot == CANNON_AIM_DOWN)
                {
                    gCurrentSprite.pOam = sCannonBulletOAM_Down;
                    gCurrentSprite.yPosition += BLOCK_SIZE;
                }
                else if (gCurrentSprite.roomSlot == CANNON_AIM_DOWN_RIGHT)
                {
                    gCurrentSprite.pOam = sCannonBulletOAM_DownRight;
                    gCurrentSprite.yPosition += (HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
                    gCurrentSprite.xPosition += (HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
                }
                else if (gCurrentSprite.roomSlot == CANNON_AIM_RIGHT)
                {
                    gCurrentSprite.pOam = sCannonBulletOAM_Right;
                    gCurrentSprite.xPosition += BLOCK_SIZE;
                }
                else
                    gCurrentSprite.status = 0;
                break;

            case 9:
                if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) == COLLISION_SOLID)
                {
                    // Set destroyed
                    gCurrentSprite.pose = 0x42;
                    gCurrentSprite.samusCollision = SSC_NONE;
                    return;
                }

                // Move
                if (gCurrentSprite.roomSlot == CANNON_AIM_LEFT)
                {
                    gCurrentSprite.xPosition -= CANNON_BULLET_SPEED;
                }
                else if (gCurrentSprite.roomSlot == CANNON_AIM_DOWN_LEFT)
                {
                    gCurrentSprite.xPosition -= CANNON_BULLET_SPEED_DIAG;
                    gCurrentSprite.yPosition += CANNON_BULLET_SPEED_DIAG;
                }
                else if (gCurrentSprite.roomSlot == CANNON_AIM_DOWN)
                {
                    gCurrentSprite.yPosition += CANNON_BULLET_SPEED;
                }
                else if (gCurrentSprite.roomSlot == CANNON_AIM_DOWN_RIGHT)
                {
                    gCurrentSprite.xPosition += CANNON_BULLET_SPEED_DIAG;
                    gCurrentSprite.yPosition += CANNON_BULLET_SPEED_DIAG;
                }
                else if (gCurrentSprite.roomSlot == CANNON_AIM_RIGHT)
                {
                    gCurrentSprite.xPosition += CANNON_BULLET_SPEED;
                }
                else
                    gCurrentSprite.status = 0;
                break;

            default:
                // Destroy
                ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SMALL);
                if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlay(0x12C);
                gCurrentSprite.status = 0;
                break;

        }
    }
    else
        gCurrentSprite.status = 0;
}
