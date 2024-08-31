#include "sprites_AI/zebetite_and_cannon.h"
#include "macros.h"

#include "data/sprites/zebetite_and_cannon.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
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
    u32 alreadyDead;
    u16 maxHealth;
    u16 spawnHealth;
    u32 phase;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        alreadyDead = FALSE;
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

        switch (gCurrentSprite.spriteId)
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

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 3);
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

        gCurrentSprite.frozenPaletteRowOffset = 1;
        gCurrentSprite.samusCollision = SSC_SOLID_SIDEWAYS;

        gCurrentSprite.pOam = sZebetiteOam_Phase1;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.drawOrder = 5;
        spawnHealth = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.health = spawnHealth;
        gCurrentSprite.scaling = spawnHealth;

        gCurrentSprite.pose = 9;

        if (gDifficulty == DIFF_EASY)
            gCurrentSprite.work0 = ZEBETITE_HEAL_TIMER * 2;
        else
            gCurrentSprite.work0 = ZEBETITE_HEAL_TIMER;
    }

    maxHealth = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    phase = (maxHealth - gCurrentSprite.health) / ZEBETITE_HEALTH_THRESHOLD;

    if (gCurrentSprite.health == gCurrentSprite.scaling)
    {
        if (phase != 0)
        {
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
                gCurrentSprite.health += ZEBETITE_HEALTH_THRESHOLD;
        }

        return;
    }

    if (gCurrentSprite.health < maxHealth)
    {
        if (gDifficulty == DIFF_EASY)
            gCurrentSprite.work0 = ZEBETITE_HEAL_TIMER * 2;
        else
            gCurrentSprite.work0 = ZEBETITE_HEAL_TIMER;
    }

    gCurrentSprite.scaling = gCurrentSprite.health;

    switch (phase)
    {
        case 0:
            if (gCurrentSprite.pOam != sZebetiteOam_Phase1)
            {
                SoundPlayNotAlreadyPlaying(SOUND_ZEBETITE_HURT_2);
                
                gCurrentSprite.pOam = sZebetiteOam_Phase1;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            break;

        case 1:
        case 2:
            if (gCurrentSprite.pOam != sZebetiteOam_Phase2)
            {
                if (gCurrentSprite.pOam == sZebetiteOam_Phase1)
                    SoundPlayNotAlreadyPlaying(SOUND_ZEBETITE_HURT_1);
                else if (gCurrentSprite.pOam == sZebetiteOam_Phase4)
                    SoundPlayNotAlreadyPlaying(SOUND_ZEBETITE_HURT_2);
                
                gCurrentSprite.pOam = sZebetiteOam_Phase2;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            break;

        case 3:
        case 4:
            if (gCurrentSprite.pOam != sZebetiteOam_Phase4)
            {
                if (gCurrentSprite.pOam == sZebetiteOam_Phase2)
                    SoundPlayNotAlreadyPlaying(SOUND_ZEBETITE_HURT_1);
                else if (gCurrentSprite.pOam == sZebetiteOam_Phase6)
                    SoundPlayNotAlreadyPlaying(SOUND_ZEBETITE_HURT_2);
                
                gCurrentSprite.pOam = sZebetiteOam_Phase4;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            break;

        case 5:
        case 6:
            if (gCurrentSprite.pOam != sZebetiteOam_Phase6)
            {
                SoundPlayNotAlreadyPlaying(SOUND_ZEBETITE_HURT_1);
                
                gCurrentSprite.pOam = sZebetiteOam_Phase6;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            break;

        default:
            ParticleSet(gCurrentSprite.yPosition - (BLOCK_SIZE + PIXEL_SIZE * 2), gCurrentSprite.xPosition,
                PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);

            SoundPlay(SOUND_SPRITE_EXPLOSION_SINGLE_THEN_BIG);

            switch (gCurrentSprite.spriteId)
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

/**
 * @brief 409d4 | 4c | Makes a cannon fire a bullet if possible
 * 
 */
void CannonFireBullet(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && gCurrentSprite.currentAnimationFrame == 1
        && gCurrentSprite.animationDurationCounter == 1)
    {
        SpriteSpawnSecondary(SSPRITE_CANNON_BULLET, gCurrentSprite.work1, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    }
}

void CannonCheckSurroundings(void)
{
    u8 rng;

    rng = gSpriteRng;

    gCurrentSprite.work0 = rng * 8 + 10;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + BLOCK_SIZE) != COLLISION_AIR)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.work1 = CANNON_AIM_DOWN_LEFT;
        gCurrentSprite.work3 = CANNON_VIEW_LEFT;
        gCurrentSprite.pOam = sCannonOam_AimingDownLeft;
    }
    else if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - BLOCK_SIZE) != COLLISION_AIR)
    {
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.work1 = CANNON_AIM_DOWN_RIGHT;
        gCurrentSprite.work3 = CANNON_VIEW_RIGHT;
        gCurrentSprite.pOam = sCannonOam_AimingDownRight;
    }
    else
    {
        if (MOD_AND(rng, 2))
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        else
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;

        if (rng > 7)
        {
            gCurrentSprite.work1 = CANNON_AIM_DOWN_RIGHT;
            gCurrentSprite.pOam = sCannonOam_AimingDownRight;
        }
        else
        {
            gCurrentSprite.work1 = CANNON_AIM_DOWN_LEFT;
            gCurrentSprite.pOam = sCannonOam_AimingDownLeft;
        }

        gCurrentSprite.work3 = CANNON_VIEW_EVERWHERE;
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

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
    {
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SMALL);
        
        gCurrentSprite.status = 0;
        return;
    }

    rng = gSpriteRng;

    if (gCurrentSprite.pose == 0)
    {
        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -PIXEL_SIZE;
        gCurrentSprite.hitboxBottom = PIXEL_SIZE;
        gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
        gCurrentSprite.hitboxRight = PIXEL_SIZE;

        gCurrentSprite.frozenPaletteRowOffset = 1;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawOrder = 5;

        gCurrentSprite.bgPriority = MOD_AND(gIoRegistersBackup.BG1CNT,4);
        gCurrentSprite.pose = 0x9;

        gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
        CannonCheckSurroundings();

        gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
        gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
        return;
    }

    spriteY = gCurrentSprite.yPositionSpawn;
    spriteX = gCurrentSprite.xPositionSpawn;
    samusX = gSamusData.xPosition;

    switch (gCurrentSprite.spriteId)
    {
        case PSPRITE_CANNON:
            range = QUARTER_BLOCK_SIZE + PIXEL_SIZE;
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
            range = QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2;
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
            range = QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2;
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

    switch (gCurrentSprite.work1)
    {
        case CANNON_AIM_LEFT:
            if (gCurrentSprite.pOam == sCannonOam_ShootingLeft)
            {
                if (SpriteUtilCheckEndCurrentSpriteAnim())
                {
                    gCurrentSprite.pOam = sCannonOam_AimingLeft;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
                else
                    CannonFireBullet();
            }

            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                gCurrentSprite.work0 = 66;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.work1++;

                gCurrentSprite.pOam = sCannonOam_LeftToDownLeftTransition;
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            }
            break;

        case CANNON_AIM_LEFT_TO_DOWN_LEFT_TRANSITION:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (rng > 2)
                        gCurrentSprite.pOam = sCannonOam_ShootingDownLeft;
                    else
                        gCurrentSprite.pOam = sCannonOam_AimingDownLeft;

                    gCurrentSprite.work1++;
                }
                else
                {
                    if (rng > 10)
                        gCurrentSprite.pOam = sCannonOam_ShootingLeft;
                    else
                        gCurrentSprite.pOam = sCannonOam_AimingLeft;

                    gCurrentSprite.work1--;
                }

                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            break;

        case CANNON_AIM_DOWN_LEFT:
            if (gCurrentSprite.pOam == sCannonOam_ShootingDownLeft)
            {
                if (SpriteUtilCheckEndCurrentSpriteAnim())
                {
                    gCurrentSprite.pOam = sCannonOam_AimingDownLeft;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
                else
                    CannonFireBullet();
            }

            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                gCurrentSprite.work0 = 66;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    gCurrentSprite.work1++;
                    gCurrentSprite.pOam = sCannonOam_DownLeftToDownTransition;
                }
                else
                {
                    gCurrentSprite.work1--;
                    gCurrentSprite.pOam = sCannonOam_LeftToDownLeftTransition;
                }
            }
            break;

        case CANNON_AIM_DOWN_LEFT_TO_DOWN_TRANSITION:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (rng > 4)
                        gCurrentSprite.pOam = sCannonOam_ShootingDown;
                    else
                        gCurrentSprite.pOam = sCannonOam_AimingDown;

                    gCurrentSprite.work1++;
                }
                else
                {
                    if (rng > 2)
                        gCurrentSprite.pOam = sCannonOam_ShootingDownLeft;
                    else
                        gCurrentSprite.pOam = sCannonOam_AimingDownLeft;

                    gCurrentSprite.work1--;
                }

                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            break;

        case CANNON_AIM_DOWN:
            if (gCurrentSprite.pOam == sCannonOam_ShootingDown)
            {
                if (SpriteUtilCheckEndCurrentSpriteAnim())
                {
                    gCurrentSprite.pOam = sCannonOam_AimingDown;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
                else
                    CannonFireBullet();
            }

            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                gCurrentSprite.work0 = 66;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                if (gCurrentSprite.work3 != CANNON_VIEW_EVERWHERE)
                    gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    gCurrentSprite.work1++;
                    gCurrentSprite.pOam = sCannonOam_DownToDownRightTransition;
                }
                else
                {
                    gCurrentSprite.work1--;
                    gCurrentSprite.pOam = sCannonOam_DownLeftToDownTransition;
                }
            }
            break;

        case CANNON_AIM_DOWN_TO_DOWN_RIGHT_TRANSITION:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (rng > 2)
                        gCurrentSprite.pOam = sCannonOam_ShootingDownRight;
                    else
                        gCurrentSprite.pOam = sCannonOam_AimingDownRight;

                    gCurrentSprite.work1++;
                }
                else
                {
                    if (rng > 4)
                        gCurrentSprite.pOam = sCannonOam_ShootingDown;
                    else
                        gCurrentSprite.pOam = sCannonOam_AimingDown;
                    gCurrentSprite.work1--;
                }

                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            break;

        case CANNON_AIM_DOWN_RIGHT:
            if (gCurrentSprite.pOam == sCannonOam_ShootingDownRight)
            {
                if (SpriteUtilCheckEndCurrentSpriteAnim())
                {
                    gCurrentSprite.pOam = sCannonOam_AimingDownRight;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
                else
                    CannonFireBullet();
            }

            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                gCurrentSprite.work0 = 66;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    gCurrentSprite.work1++;
                    gCurrentSprite.pOam = sCannonOam_DownRightToRightTransition;
                }
                else
                {
                    gCurrentSprite.work1--;
                    gCurrentSprite.pOam = sCannonOam_DownToDownRightTransition;
                }
            }
            break;

        case CANNON_AIM_DOWN_RIGHT_TO_RIGHT_TRANSITION:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (rng > 10)
                        gCurrentSprite.pOam = sCannonOam_ShootingRight;
                    else
                        gCurrentSprite.pOam = sCannonOam_AimingRight;

                    gCurrentSprite.work1++;
                }
                else
                {
                    if (rng > 2)
                        gCurrentSprite.pOam = sCannonOam_ShootingDownRight;
                    else
                        gCurrentSprite.pOam = sCannonOam_AimingDownRight;

                    gCurrentSprite.work1--;
                }

                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            break;

        case CANNON_AIM_RIGHT:
            if (gCurrentSprite.pOam == sCannonOam_ShootingRight)
            {
                if (SpriteUtilCheckEndCurrentSpriteAnim())
                {
                    gCurrentSprite.pOam = sCannonOam_AimingRight;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
                else
                    CannonFireBullet();
            }

            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                gCurrentSprite.work0 = 66;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                gCurrentSprite.work1--;
                gCurrentSprite.pOam = sCannonOam_DownRightToRightTransition;

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
            case SPRITE_POSE_UNINITIALIZED:
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
                gCurrentSprite.drawOrder = 2,
                gCurrentSprite.health = 0;

                gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
                gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
                gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

                gCurrentSprite.hitboxTop = -PIXEL_SIZE;
                gCurrentSprite.hitboxBottom = PIXEL_SIZE;
                gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
                gCurrentSprite.hitboxRight = PIXEL_SIZE;

                gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
                gCurrentSprite.pose = 9;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                // Set OAM and base position
                if (gCurrentSprite.roomSlot == CANNON_AIM_LEFT)
                {
                    gCurrentSprite.pOam = sCannonBulletOam_Left;
                    gCurrentSprite.xPosition -= BLOCK_SIZE;
                }
                else if (gCurrentSprite.roomSlot == CANNON_AIM_DOWN_LEFT)
                {
                    gCurrentSprite.pOam = sCannonBulletOam_DownLeft;
                    gCurrentSprite.yPosition += HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE;
                    gCurrentSprite.xPosition -= HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE;
                }
                else if (gCurrentSprite.roomSlot == CANNON_AIM_DOWN)
                {
                    gCurrentSprite.pOam = sCannonBulletOam_Down;
                    gCurrentSprite.yPosition += BLOCK_SIZE;
                }
                else if (gCurrentSprite.roomSlot == CANNON_AIM_DOWN_RIGHT)
                {
                    gCurrentSprite.pOam = sCannonBulletOam_DownRight;
                    gCurrentSprite.yPosition += HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE;
                    gCurrentSprite.xPosition += HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE;
                }
                else if (gCurrentSprite.roomSlot == CANNON_AIM_RIGHT)
                {
                    gCurrentSprite.pOam = sCannonBulletOam_Right;
                    gCurrentSprite.xPosition += BLOCK_SIZE;
                }
                else
                {
                    gCurrentSprite.status = 0;
                }
                break;

            case 9:
                if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) == COLLISION_SOLID)
                {
                    // Set destroyed
                    gCurrentSprite.pose = SPRITE_POSE_STOPPED;
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
                    SoundPlay(SOUND_SPRITE_EXPLOSION_SMALL);

                gCurrentSprite.status = 0;
                break;

        }
    }
    else
        gCurrentSprite.status = 0;
}
