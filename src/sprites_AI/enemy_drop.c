#include "sprites_AI/enemy_drop.h"
#include "data/sprites/enemy_drop.h"
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
    gCurrentSprite.ignoreSamusCollisionTimer = 0x14;
    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
    gCurrentSprite.pose = ENEMY_DROP_POSE_IDLE;

    // Despawn timer
    gCurrentSprite.yPositionSpawn = 0xC8;
    gCurrentSprite.xPositionSpawn = 0x0;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

    gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
    gCurrentSprite.drawOrder = 0x1;

    // Set OAM and collision
    switch (gCurrentSprite.spriteID)
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
            if (gCurrentSprite.roomSlot == 0x1)
                gCurrentSprite.pOam = sEnemyDropOAM_MultipleLargeEnergySlot1;
            else if (gCurrentSprite.roomSlot == 0x2)
                gCurrentSprite.pOam = sEnemyDropOAM_MultipleLargeEnergySlot2;
            else
                gCurrentSprite.pOam = sEnemyDropOAM_MultipleLargeEnergySlot3;

            gCurrentSprite.samusCollision = SSC_MULTIPLE_LARGE_ENERGY_DROP;
            break;

        default:
            gCurrentSprite.pOam = sEnemyDropOAM_SmallEnergy;
            gCurrentSprite.samusCollision = SSC_SMALL_ENERGY_DROP;
    }

    gCurrentSprite.hitboxTopOffset = -0x24;
    gCurrentSprite.hitboxBottomOffset = 0x24;
    gCurrentSprite.hitboxLeftOffset = -0x20;
    gCurrentSprite.hitboxRightOffset = 0x20;
}

/**
 * @brief 12e98 | 158 | Handles an enemy drop being idle
 * 
 */
void EnemyDropIdle(void)
{
    u16 status;
    u8 timer;

    if (gCurrentSprite.ignoreSamusCollisionTimer != 0x0)
    {
        if (gCurrentSprite.ignoreSamusCollisionTimer < 0x2)
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
        {
            // Apply drop
            switch (gCurrentSprite.samusCollision)
            {
                case SSC_SMALL_ENERGY_DROP:
                    gEquipment.currentEnergy += 0x5;
                    if (gEquipment.currentEnergy > gEquipment.maxEnergy)
                        gEquipment.currentEnergy = gEquipment.maxEnergy;
                    SoundPlay(0x86);
                    break;

                case SSC_LARGE_ENERGY_DROP:
                    gEquipment.currentEnergy += 0x14;
                    if (gEquipment.currentEnergy > gEquipment.maxEnergy)
                        gEquipment.currentEnergy = gEquipment.maxEnergy;
                    SoundPlay(0x87);
                    break;

                case SSC_MISSILE_DROP:
                    gEquipment.currentMissiles += 0x2;
                    if (gEquipment.currentMissiles > gEquipment.maxMissiles)
                        gEquipment.currentMissiles = gEquipment.maxMissiles;
                    SoundPlay(0x88);
                    break;

                case SSC_SUPER_MISSILE_DROP:
                    gEquipment.currentSuperMissiles += 0x2;
                    if (gEquipment.currentSuperMissiles > gEquipment.maxSuperMissiles)
                        gEquipment.currentSuperMissiles = gEquipment.maxSuperMissiles;
                    SoundPlay(0x89);
                    break;

                case SSC_POWER_BOMB_DROP:
                    gEquipment.currentPowerBombs += 0x1;
                    if (gEquipment.currentPowerBombs > gEquipment.maxPowerBombs)
                        gEquipment.currentPowerBombs = gEquipment.maxPowerBombs;
                    SoundPlay(0x8A);
                    break;

                case SSC_MULTIPLE_LARGE_ENERGY_DROP:
                    gEquipment.currentEnergy += 0x3C;
                    if (gEquipment.currentEnergy > gEquipment.maxEnergy)
                        gEquipment.currentEnergy = gEquipment.maxEnergy;
                    SoundPlay(0x87);
                    break;
            }
            gCurrentSprite.status = 0x0;
        }
        else
        {
            // Update sprite based on despawn timer
            timer = gCurrentSprite.xPositionSpawn;
            if (timer & 0x1)
            {
                timer = --gCurrentSprite.yPositionSpawn;
                if (timer != 0x0)
                {
                    if (timer < 0x50)
                        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
                }
                else
                    gCurrentSprite.status = 0x0;
            }
        }
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
        case 0x0:
            EnemyDropInit();
            break;
        case ENEMY_DROP_POSE_IDLE:
            EnemyDropIdle();
    }

    // Update despawn timer
    gCurrentSprite.xPositionSpawn++;
}