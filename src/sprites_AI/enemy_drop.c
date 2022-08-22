#include "enemy_drop.h"
#include "../globals.h"

const u16 sEnemyDropOAM_SmallEnergy_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x4183
};

const u16 sEnemyDropOAM_SmallEnergy_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, 0x41a3
};

const u16 sEnemyDropOAM_SmallEnergy_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, 0x4184
};

const u16 sEnemyDropOAM_SmallEnergy_Frame3[4] = {
    0x1,
    0xfc, 0x1fc, 0x41a4
};

const u16 sEnemyDropOAM_LargeEnergy_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x41c0
};

const u16 sEnemyDropOAM_LargeEnergy_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x41c2,
};

const u16 sEnemyDropOAM_LargeEnergy_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x41c4
};

const u16 sEnemyDropOAM_LargeEnergy_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x41c6
};

const u16 sEnemyDropOAM_Missile_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4185
};

const u16 sEnemyDropOAM_Missile_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4190
};

const u16 sEnemyDropOAM_SuperMissile_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4186
};

const u16 sEnemyDropOAM_SuperMissile_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x4191
};

const u16 sEnemyDropOAM_PowerBomb_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x414b
};

const u16 sEnemyDropOAM_PowerBomb_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, 0x416c
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot1_Frame0[10] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1f1, 0x41c0,
    0xf8, OBJ_SIZE_16x16 | 0x0, 0x41c0,
    0x0, OBJ_SIZE_16x16 | 0x1f8, 0x41c0
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot1_Frame1[10] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1f1, 0x41c2,
    0xf8, OBJ_SIZE_16x16 | 0x0, 0x41c2,
    0x0, OBJ_SIZE_16x16 | 0x1f8, 0x41c2
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot1_Frame2[10] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1f1, 0x41c4,
    0xf8, OBJ_SIZE_16x16 | 0x0, 0x41c4,
    0x0, OBJ_SIZE_16x16 | 0x1f8, 0x41c4
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot1_Frame3[10] = {
    0x3,
    0xf3, OBJ_SIZE_16x16 | 0x1f1, 0x41c6,
    0xf8, OBJ_SIZE_16x16 | 0x0, 0x41c6,
    0x0, OBJ_SIZE_16x16 | 0x1f8, 0x41c6
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot3_Frame0[10] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f7, 0x41c0,
    0xff, OBJ_SIZE_16x16 | 0x1f1, 0x41c0,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x41c0
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot3_Frame1[10] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f7, 0x41c2,
    0xff, OBJ_SIZE_16x16 | 0x1f1, 0x41c2,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x41c2
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot3_Frame2[10] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f7, 0x41c4,
    0xff, OBJ_SIZE_16x16 | 0x1f1, 0x41c4,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x41c4,
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot3_Frame3[10] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f7, 0x41c6,
    0xff, OBJ_SIZE_16x16 | 0x1f1, 0x41c6,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x41c6
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot2_Frame0[10] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1fb, 0x41c0,
    0xff, OBJ_SIZE_16x16 | 0x1f3, 0x41c0,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x41c0
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot2_Frame1[10] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1fb, 0x41c2,
    0xff, OBJ_SIZE_16x16 | 0x1f3, 0x41c2,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x41c2
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot2_Frame2[10] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1fb, 0x41c4,
    0xff, OBJ_SIZE_16x16 | 0x1f3, 0x41c4,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x41c4
};

const u16 sEnemyDropOAM_MultipleLargeEnergySlot2_Frame3[10] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1fb, 0x41c6,
    0xff, OBJ_SIZE_16x16 | 0x1f3, 0x41c6,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x41c6
};

const struct FrameData sEnemyDropOAM_SmallEnergy[5] = {
    sEnemyDropOAM_SmallEnergy_Frame0,
    0x8,
    sEnemyDropOAM_SmallEnergy_Frame1,
    0x8,
    sEnemyDropOAM_SmallEnergy_Frame2,
    0x8,
    sEnemyDropOAM_SmallEnergy_Frame3,
    0x8,
    NULL,
    0x0
};

const struct FrameData sEnemyDropOAM_LargeEnergy[5] = {
    sEnemyDropOAM_LargeEnergy_Frame0,
    0x8,
    sEnemyDropOAM_LargeEnergy_Frame1,
    0x8,
    sEnemyDropOAM_LargeEnergy_Frame2,
    0x8,
    sEnemyDropOAM_LargeEnergy_Frame3,
    0x8,
    NULL,
    0x0
};

const struct FrameData sEnemyDropOAM_Missile[3] = {
    sEnemyDropOAM_Missile_Frame0,
    0x4,
    sEnemyDropOAM_Missile_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sEnemyDropOAM_SuperMissile[3] = {
    sEnemyDropOAM_SuperMissile_Frame0,
    0x4,
    sEnemyDropOAM_SuperMissile_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sEnemyDropOAM_PowerBomb[3] = {
    sEnemyDropOAM_PowerBomb_Frame0,
    0x4,
    sEnemyDropOAM_PowerBomb_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sEnemyDropOAM_MultipleLargeEnergySlot1[5] = {
    sEnemyDropOAM_MultipleLargeEnergySlot1_Frame0,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot1_Frame1,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot1_Frame2,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot1_Frame3,
    0x8,
    NULL,
    0x0
};

const struct FrameData sEnemyDropOAM_MultipleLargeEnergySlot3[5] = {
    sEnemyDropOAM_MultipleLargeEnergySlot3_Frame0,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot3_Frame1,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot3_Frame2,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot3_Frame3,
    0x8,
    NULL,
    0x0
};

const struct FrameData sEnemyDropOAM_MultipleLargeEnergySlot2[5] = {
    sEnemyDropOAM_MultipleLargeEnergySlot2_Frame0,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot2_Frame1,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot2_Frame2,
    0x8,
    sEnemyDropOAM_MultipleLargeEnergySlot2_Frame3,
    0x8,
    NULL,
    0x0
};

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
void EnemyDropGet(void)
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