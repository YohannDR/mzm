#include "enemy_drop.h"
#include "../sprite.h"
#include "../globals.h"
#include "../oam.h"

void EnemyDropInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x14;
    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.yPositionSpawn = 0xC8;
    gCurrentSprite.xPositionSpawn = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
    gCurrentSprite.bgPriority = (u8)gIORegistersBackup.bg2_cnt & 0x3
    gCurrentSprite.drawOrder = 0x1;

    switch (gCurrentSprite.spriteID)
    {
        case PSPRITE_POWER_BOMB_DROP:
            gCurrentSprite.pOam = power_bomb_drop_oam;
            gCurrentSprite.samusCollision = SSC_POWER_BOMB_DROP;
            break;
        case PSPRITE_SUPER_MISSILE_DROP:
            gCurrentSprite.pOam = super_missile_drop_oam;
            gCurrentSprite.samusCollision = SSC_SUPER_MISSILE_DROP;
            break;
        case PSPRITE_MISSILE_DROP:
            gCurrentSprite.pOam = missile_drop_oam;
            gCurrentSprite.samusCollision = SSC_MISSILE_DROP;
            break;
        case PSPRITE_LARGE_ENERGY_DROP:
            gCurrentSprite.pOam = large_energy_oam;
            gCurrentSprite.samusCollision = SSC_LARGE_ENERGY_DROP;
            break;
        case PSPRITE_MULTIPLE_LARGE_ENERGY:
            if (gCurrentSprite.roomSlot == 0x1)
                gCurrentSprite.pOam = multiple_large_energy_oam1;
            else if (gCurrentSprite.roomSlot == 0x2)
                gCurrentSprite.pOam = multiple_large_energy_oam2;
            else
                gCurrentSprite.pOam = multiple_large_energy_oam3;

            gCurrentSprite.samusCollision = SSC_MULTIPLE_LARGE_ENERGY_DROP;
            break;
        default:
            gCurrentSprite.pOam = small_energy_oam;
            gCurrentSprite.samusCollision = SSC_SMALL_ENERGY_DROP;
    }

    gCurrentSprite.hitboxTopOffset = -0x24;
    gCurrentSprite.hitboxBottomOffset = 0x24;
    gCurrentSprite.hitboxLeftOffset = -0x20;
    gCurrentSprite.hitboxRightOffset = 0x20;
}

void EnemyDropGet(void)
{
    u16 status;
    struct SpriteData* pSprite;
    u32 timer;

    pSprite = &gCurrentSprite;
    if (pSpriteignoreSamusCollisionTimer != 0x0)
    {
        if (pSprite->ignoreSamusCollisionTimer < 0x2)
            status = pSprite->status & ~SPRITE_STATUS_NOT_DRAWN;
        else
            return;
    }
    else
    {
        if ((pSprite->status & SPRITE_STATUS_SAMUS_COLLIDING) != 0x0)
        {
            switch (pSprite->samusCollision)
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
                    gEquipmentcurrentPowerBombs += 0x1;
                    if (gEquipmentcurrentPowerBombs > gEquipment.maxPowerBombs)
                        gEquipmentcurrentPowerBombs = gEquipment.maxPowerBombs;
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
            return;
        }
        else
        {
            if (((u8)pSprite->xPositionSpawn & 0x1) != 0x0)
            {
                pSprite->yPositionSpawn--;
                timer = (u8)pSprite->yPositionSpawn;
                status = timer;
                if (timer != 0x0)
                {
                    if (timer < 0x50)
                        status = pSprite->status ^ SPRITE_STATUS_NOT_DRAWN;
                    else
                        return;
                }
            }
            else
                return;
        }
    }
    pSprite->status = status;
}

void EnemyDrop(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            EnemyDropInit();
            break;
        case 0x9:
            EnemyDropGet();
    }
    gCurrentSprite.xPositionSpawn++;
}