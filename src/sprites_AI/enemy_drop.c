#include "sprites_AI/enemy_drop.h"
#include "macros.h"

#include "data/sprites/enemy_drop.h"

#include "constants/audio.h"
#include "constants/sprite.h"

#include "structs/display.h"
#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 12d14 | 17a | Initializes an enemy drop sprite
 * 
 */
void EnemyDropInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 20;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.pose = ENEMY_DROP_POSE_IDLE;

    // Despawn timer
    gCurrentSprite.yPositionSpawn = 200;
    gCurrentSprite.xPositionSpawn = 0;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

    gCurrentSprite.bgPriority = MOD_AND(gIoRegistersBackup.BG1CNT, 4);
    gCurrentSprite.drawOrder = 1;

    // Set OAM and collision
    switch (gCurrentSprite.spriteId)
    {
        case PSPRITE_POWER_BOMB_DROP:
            gCurrentSprite.pOam = sEnemyDropOAM_PowerBomb;
            gCurrentSprite.samusCollision = SSC_POWER_BOMB_DROP;
            break;

        case PSPRITE_SUPER_MISSILE_DROP:
            gCurrentSprite.pOam = sEnemyDropOAM_SuperMissile;
            gCurrentSprite.samusCollision = SSC_SUPER_MISSILE_DROP;
            break;

        case PSPRITE_MISSILE_DROP:
            gCurrentSprite.pOam = sEnemyDropOAM_Missile;
            gCurrentSprite.samusCollision = SSC_MISSILE_DROP;
            break;

        case PSPRITE_LARGE_ENERGY_DROP:
            gCurrentSprite.pOam = sEnemyDropOAM_LargeEnergy;
            gCurrentSprite.samusCollision = SSC_LARGE_ENERGY_DROP;
            break;

        case PSPRITE_MULTIPLE_LARGE_ENERGY:
            if (gCurrentSprite.roomSlot == 1)
                gCurrentSprite.pOam = sEnemyDropOAM_MultipleLargeEnergySlot1;
            else if (gCurrentSprite.roomSlot == 2)
                gCurrentSprite.pOam = sEnemyDropOAM_MultipleLargeEnergySlot2;
            else
                gCurrentSprite.pOam = sEnemyDropOAM_MultipleLargeEnergySlot3;

            gCurrentSprite.samusCollision = SSC_MULTIPLE_LARGE_ENERGY_DROP;
            break;

        default:
            gCurrentSprite.pOam = sEnemyDropOAM_SmallEnergy;
            gCurrentSprite.samusCollision = SSC_SMALL_ENERGY_DROP;
    }

    gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE + PIXEL_SIZE);
    gCurrentSprite.hitboxBottom = (HALF_BLOCK_SIZE + PIXEL_SIZE);
    gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;
}

/**
 * @brief 12e98 | 158 | Handles an enemy drop being idle
 * 
 */
void EnemyDropIdle(void)
{
    u16 status;
    u8 timer;

    if (gCurrentSprite.ignoreSamusCollisionTimer != 0)
    {
        if (gCurrentSprite.ignoreSamusCollisionTimer < 2)
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        // Apply drop
        switch (gCurrentSprite.samusCollision)
        {
            case SSC_SMALL_ENERGY_DROP:
                gEquipment.currentEnergy += SMALL_ENERGY_DROP_REFILL;

                if (gEquipment.currentEnergy > gEquipment.maxEnergy)
                    gEquipment.currentEnergy = gEquipment.maxEnergy;

                SoundPlay(SOUND_GETTING_SMALL_ENERGY_DROP);
                break;

            case SSC_LARGE_ENERGY_DROP:
                gEquipment.currentEnergy += LARGE_ENERGY_DROP_REFILL;

                if (gEquipment.currentEnergy > gEquipment.maxEnergy)
                    gEquipment.currentEnergy = gEquipment.maxEnergy;

                SoundPlay(SOUND_GETTING_LARGE_ENERGY_DROP);
                break;

            case SSC_MISSILE_DROP:
                gEquipment.currentMissiles += MISSILE_DROP_REFILL;

                if (gEquipment.currentMissiles > gEquipment.maxMissiles)
                    gEquipment.currentMissiles = gEquipment.maxMissiles;

                SoundPlay(SOUND_GETTING_MISSILE_DROP);
                break;

            case SSC_SUPER_MISSILE_DROP:
                gEquipment.currentSuperMissiles += SUPER_MISSILE_DROP_REFILL;

                if (gEquipment.currentSuperMissiles > gEquipment.maxSuperMissiles)
                    gEquipment.currentSuperMissiles = gEquipment.maxSuperMissiles;

                SoundPlay(SOUND_GETTING_SUPER_MISSILE_DROP);
                break;

            case SSC_POWER_BOMB_DROP:
                gEquipment.currentPowerBombs += POWER_BOMB_DROP_REFILL;

                if (gEquipment.currentPowerBombs > gEquipment.maxPowerBombs)
                    gEquipment.currentPowerBombs = gEquipment.maxPowerBombs;

                SoundPlay(SOUND_GETTING_POWER_BOMB_DROP);
                break;

            case SSC_MULTIPLE_LARGE_ENERGY_DROP:
                gEquipment.currentEnergy += LARGE_ENERGY_DROP_REFILL * 3;

                if (gEquipment.currentEnergy > gEquipment.maxEnergy)
                    gEquipment.currentEnergy = gEquipment.maxEnergy;

                SoundPlay(SOUND_GETTING_LARGE_ENERGY_DROP);
                break;
        }

        gCurrentSprite.status = 0;
        return;
    }

    // Update sprite based on despawn timer
    timer = gCurrentSprite.xPositionSpawn;
    if (MOD_AND(timer, 2))
    {
        timer = --gCurrentSprite.yPositionSpawn;
        if (timer != 0)
        {
            if (timer < 80)
                gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
        }
        else
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 12ff0 | 34 | Enemy drop AI
 * 
 */
void EnemyDrop(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            EnemyDropInit();
            break;

        case ENEMY_DROP_POSE_IDLE:
            EnemyDropIdle();
    }

    // Update despawn timer
    gCurrentSprite.xPositionSpawn++;
}
