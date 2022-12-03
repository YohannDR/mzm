#include "sprites_AI/mecha_ridley.h"

#include "data/sprites/mecha_ridley.h"
#include "data/sprite_data.h"

#include "constants/event.h"
#include "constants/particle.h"
#include "constants/sprite.h"

#include "structs/sprite.h"
#include "structs/samus.h"

#define HEALTH_THRESHOLD_FULL 0
#define HEALTH_THRESHOLD_DAMAGED 1
#define HEALTH_THRESHOLD_COVER_BROKEN 2
#define HEALTH_THRESHOLD_THREE_QUARTERS 3
#define HEALTH_THRESHOLD_HALF 4
#define HEALTH_THRESHOLD_QUARTER 5


#define CHECK_COVER_HEALTH_THRESHOLD(maxHealth)               \
do {                                                          \
if (gSubSpriteData1.health < maxHealth * 3 / 4)               \
    gSubSpriteData1.workVariable3 = HEALTH_THRESHOLD_DAMAGED; \
} while(0);                                                   \



void MechaRidleySyncSubSprites(void)
{

}

void MechaRidleyPartGreeGlow(void)
{

}

void MechaRidleyPartLoadWeaponsGFX(void)
{

}

void unk_4bc2c(void)
{

}

u8 unk_4bcd0(void)
{

}

void unk_4bdf8(u8 ramSlot)
{

}

void unk_4beb4(u8 ramSlot)
{

}

void MechaRidleyInit(void)
{

}

void MechaRidleyStartWalking(void)
{

}

/**
 * @brief 4c1e0 | 20 | Delay before mecha starts crawling
 * 
 */
void MechaRidleyDelayBeforeCrawling(void)
{
    gCurrentSprite.yPositionSpawn--;
    if (gCurrentSprite.yPositionSpawn == 0x0)
        gCurrentSprite.pose = MECHA_RIDLEY_POSE_CRAWLING;
}

void MechaRidleyCrawling(void)
{

}

void MechaRidleyStartBattle(void)
{

}

/**
 * @brief 4c33c | 8c | Checks if the fireball attack should start
 * 
 * @param ramSlot Left arm RAM slot
 * @return u8 1 if started, 0 otherwise
 */
u8 MechaRidleyCheckStartFireballAttack(u8 ramSlot)
{
    if (!(gCurrentSprite.arrayOffset & 0x3F))
    {
        if (!(gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2) && gSpriteRNG < 8)
            unk_4beb4(ramSlot); // Start claw attack
        else
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;

            if (gSubSpriteData1.workVariable3 == HEALTH_THRESHOLD_DAMAGED && gBossWork.work6 == 0)
            {
                if (gBossWork.work5 == 0 && gEquipment.currentMissiles + gEquipment.currentSuperMissiles != 0)
                {
                    // Start fireball attack
                    gCurrentSprite.pose = MECHA_RIDLEY_POSE_FIREBALL_ATTACK_INIT;
                    return TRUE;
                }
            }

            gBossWork.work4 = 2;
        }
    }

    return FALSE;
}

/**
 * @brief 4c3c8 | 38 | Handles Mecha being idle
 * 
 */
void MechaRidleyIdle(void)
{
    u8 armSlot;

    armSlot = gSubSpriteData1.workVariable5;

    if ((unk_4bcd0() || !MechaRidleyCheckStartFireballAttack(armSlot)) && gSubSpriteData1.workVariable2 == 0xAA)
        gBossWork.work5 = 1;
}

void MechaRidleyClawAttack(void)
{

}

void MechaRidleyStandingUp(void)
{

}

void MechaRidleyCurledUp(void)
{

}

void MechaRidleyCheckRetractingHeadBeforeMovingBackAnimEnded(void)
{

}

void MechaRidleyMovingBack(void)
{

}

void MechaRidleyBeforeFireballs(void)
{

}

void MechaRidleyCheckExtendingHeadBeforeFireballsAnimEnded(void)
{

}

void MechaRidleyCheckOpeningMouthAnimEnded(void)
{

}

void MechaRidleyFireballsAttack(void)
{

}

void MechaRidleyCheckClosingMouthAnimEnded(void)
{

}

void MechaRidleyCheckRetractingHeadAfterFireballsAnimEnded(void)
{

}

void MechaRidleyStartDying(void)
{

}

void MechaRidleyDying(void)
{

}

void MechaRidleyGlowFading(void)
{

}

void MechaRidleySpawnDrops(void)
{

}

void MechaRidleyFirstEyeGlow(void)
{

}

void MechaRidleySecondEyeGlow(void)
{

}

/**
 * @brief 4cf88 | 358 | Initializes a mecha ridley part sprite
 * 
 */
void MechaRidleyPartInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.pose = 0x61;
    gCurrentSprite.samusCollision = SSC_MECHA_RIDLEY;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    switch (gCurrentSprite.roomSlot)
    {
        case MECHA_RIDLEY_PART_RIGHT_ARM:
            gCurrentSprite.drawDistanceTopOffset = 0x18;
            gCurrentSprite.drawDistanceBottomOffset = 0x38;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x58;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.pose = 0x8;
            break;

        case MECHA_RIDLEY_PART_LEFT_ARM:
            gCurrentSprite.drawDistanceTopOffset = 0x50;
            gCurrentSprite.drawDistanceBottomOffset = 0x38;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x70;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.drawOrder = 0xD;
            gCurrentSprite.pose = 0x22;
            break;

        case MECHA_RIDLEY_PART_EYE:
            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x4;
            gCurrentSprite.pose = 0x26;
            gCurrentSprite.frozenPaletteRowOffset = 0x1;
            break;

        case MECHA_RIDLEY_PART_HEAD:
            gCurrentSprite.drawDistanceTopOffset = 0x28;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x38;

            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = 0x60;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x20;

            gCurrentSprite.health = 0x1;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pose = 0x2C;

            gCurrentSprite.timer = 0x0;
            gCurrentSprite.workVariable = 0x0;
            gCurrentSprite.workVariable2 = 0x0;
            gCurrentSprite.arrayOffset = 0x0;
            break;

        case MECHA_RIDLEY_PART_NECK:
            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.drawDistanceBottomOffset = 0x20;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x40;

            gCurrentSprite.hitboxTopOffset = -0x20;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x20;

            gCurrentSprite.health = 0x1;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.drawOrder = 0x6;
            gCurrentSprite.pose = 0x24;
            break;

        case MECHA_RIDLEY_PART_COVER:
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x28;
            gCurrentSprite.hitboxBottomOffset = 0x30;
            gCurrentSprite.hitboxLeftOffset = -0x30;
            gCurrentSprite.hitboxRightOffset = 0x40;

            gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];

            if (gBossWork.work11 == 0x64)
                gCurrentSprite.health *= 0x3;

            gBossWork.work10 = gCurrentSprite.health;
            gSubSpriteData1.health = gCurrentSprite.health;
            gBossWork.work7 = gCurrentSprite.health;

            gCurrentSprite.drawOrder = 0x9;
            gCurrentSprite.pose = 0x2A;
            break;

        case MECHA_RIDLEY_PART_TORSO:
            gCurrentSprite.drawDistanceTopOffset = 0x28;
            gCurrentSprite.drawDistanceBottomOffset = 0x18;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            gCurrentSprite.hitboxTopOffset = -0x40;
            gCurrentSprite.hitboxBottomOffset = 0x40;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x40;

            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.drawOrder = 0xB;
            break;

        case MECHA_RIDLEY_PART_WAISTBAND:
            gCurrentSprite.drawDistanceTopOffset = 0x18;
            gCurrentSprite.drawDistanceBottomOffset = 0x18;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            gCurrentSprite.hitboxTopOffset = -0x40;
            gCurrentSprite.hitboxBottomOffset = 0x40;
            gCurrentSprite.hitboxLeftOffset = -0x40;
            gCurrentSprite.hitboxRightOffset = 0x40;

            gCurrentSprite.health = 0x1;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.drawOrder = 0xC;
            break;

        case MECHA_RIDLEY_PART_TAIL:
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x30;

            gCurrentSprite.hitboxTopOffset = -0x40;
            gCurrentSprite.hitboxBottomOffset = 0x40;
            gCurrentSprite.hitboxLeftOffset = -0xC0;
            gCurrentSprite.hitboxRightOffset = 0xC0;

            gCurrentSprite.health = 0x1;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.drawOrder = 0xE;
            break;

        case MECHA_RIDLEY_PART_MISSILE_LAUNCHER:
            gCurrentSprite.drawDistanceTopOffset = 0x20;
            gCurrentSprite.drawDistanceBottomOffset = 0x20;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = 0x60;
            gCurrentSprite.hitboxLeftOffset = -0x60;
            gCurrentSprite.hitboxRightOffset = 0x60;

            gCurrentSprite.health = 0x1;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.drawOrder = 0xE;

            gCurrentSprite.workVariable2 = 0x0;
            gCurrentSprite.arrayOffset = 0x0;
            gCurrentSprite.pose = 0x28;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 4d2e0 | 10 | Handles the head part being idle
 * 
 */
void MechaRidleyPartHeadIdle(void)
{
    MechaRidleyPartLoadWeaponsGFX();
    MechaRidleyPartGreeGlow();
}

/**
 * @brief 4d2f0 | 48 | Handles the core part being idle
 * 
 */
void MechaRidleyPartCoverIdle(void)
{
    u16 maxHealth;

    if ((gCurrentSprite.invincibilityStunFlashTimer & 0x7F) == 0x10)
        SoundPlay(0x2AF);

    // Spawn health of cover
    maxHealth = gBossWork.work10;

    gSubSpriteData1.health = gCurrentSprite.health;

    CHECK_COVER_HEALTH_THRESHOLD(maxHealth);
}

/**
 * @brief 4d338 | 6c | Handles the cover part exploding
 * 
 */
void MechaRidleyPartCoreCoverExplosion(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    // Enable core hitbox
    gSpriteData[ramSlot].status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;

    gSubSpriteData1.health = gBossWork.work9;
    gBossWork.work7 = gBossWork.work9;

    // Set cover destroyed flag
    gSubSpriteData1.workVariable3 = HEALTH_THRESHOLD_COVER_BROKEN;

    // Disable
    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.pose = MECHA_RIDLEY_PART_COVER_POSE_BROKEN;

    ParticleSet(gCurrentSprite.yPosition + 13, gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE, PE_SPRITE_EXPLOSION_HUGE);
    SoundPlay(0x12F);
}

void MechaRidleyPartMissileAttack(void)
{

}

void MechaRidleyPartLaserAttack(void)
{

}

void MechaRidleyPartUpdateHitboxOf_Unk(void)
{

}

void MechaRidleyPartUpdateFrontClawHitbox(void)
{

}

void MechaRidleyPartUpdateHitboxOf_Unk2(void)
{

}

/**
 * @brief 4dd58 | 384 | Mecha ridley AI
 * 
 */
void MechaRidley(void)
{
    u16 spriteY;
    u16 samusY;
    u16 health;

    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        SoundPlay(0x2AF);
    }

    if (gCurrentSprite.pose != 0x0)
    {
        samusY = gSamusData.yPosition;
        spriteY = gSubSpriteData1.yPosition - BLOCK_SIZE;

        if (samusY > spriteY)
        {
            if (gCurrentSprite.oamRotation == 0x0)
            {
                if (gBossWork.work3 != MECHA_RIDLEY_SAMUS_POSITION_LOW)
                    gCurrentSprite.oamRotation = 0x78;
            }
            else
            {
                gCurrentSprite.oamRotation--;
                if (gCurrentSprite.oamRotation == 0x0)
                    gBossWork.work3 = MECHA_RIDLEY_SAMUS_POSITION_LOW;
            }
        }
        else
        {
            if (spriteY - samusY > BLOCK_SIZE * 3)
                gBossWork.work3 = MECHA_RIDLEY_SAMUS_POSITION_HIGH;
            else if (gBossWork.work3 != 0x0)
            {
                if (gCurrentSprite.oamRotation == 0x0)
                {
                    if (gBossWork.work3 != MECHA_RIDLEY_SAMUS_POSITION_MIDDLE)
                        gCurrentSprite.oamRotation = 0x78;
                }
                else
                {
                    gCurrentSprite.oamRotation--;
                    if (gCurrentSprite.oamRotation == 0x0)
                        gBossWork.work3 = MECHA_RIDLEY_SAMUS_POSITION_MIDDLE;
                }
            }
            else
                gBossWork.work3 = MECHA_RIDLEY_SAMUS_POSITION_MIDDLE;
        }
    }
    
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            MechaRidleyInit();
            break;

        case MECHA_RIDLEY_POSE_CRAWLING_INIT:
            MechaRidleyStartWalking();
            break;

        case MECHA_RIDLEY_POSE_DELAY_BEFORE_CRAWLING:
            MechaRidleyDelayBeforeCrawling();
            break;

        case MECHA_RIDLEY_POSE_CRAWLING:
            MechaRidleyCrawling();
            break;

        case MECHA_RIDLEY_POSE_DELAY_BEFORE_IDLE:
            MechaRidleyStartBattle();
            break;

        case MECHA_RIDLEY_POSE_IDLE:
            MechaRidleyIdle();
            break;

        case 0x22:
            MechaRidleyClawAttack();
            break;

        case 0x23:
            MechaRidleyStandingUp();
            break;

        case 0x25:
            MechaRidleyCurledUp();
            break;

        case 0x27:
            MechaRidleyCheckRetractingHeadBeforeMovingBackAnimEnded();
            break;

        case 0x29:
            MechaRidleyMovingBack();
            break;

        case 0x34:
            MechaRidleyBeforeFireballs();
            break;

        case 0x35:
            MechaRidleyCheckExtendingHeadBeforeFireballsAnimEnded();
            break;

        case 0x37:
            MechaRidleyCheckOpeningMouthAnimEnded();
            break;

        case 0x39:
            MechaRidleyFireballsAttack();
            break;

        case 0x3B:
            MechaRidleyCheckRetractingHeadAfterFireballsAnimEnded();
            break;

        case 0x3D:
            MechaRidleyCheckClosingMouthAnimEnded();
            break;

        case MECHA_RIDLEY_POSE_DYING_INIT:
            MechaRidleyStartDying();
            break;

        case MECHA_RIDLEY_POSE_DYING_STANDING_UP:
            MechaRidleyDying();
            break;

        case 0x64:
            MechaRidleyGlowFading();
            break;

        case MECHA_RIDLEY_POSE_SPAWN_DROPS:
            MechaRidleySpawnDrops();
            break;

        case MECHA_RIDLEY_POSE_FIRST_EYE_GLOW:
            MechaRidleyFirstEyeGlow();
            break;

        case MECHA_RIDLEY_POSE_SECOND_EYE_GLOW:
            MechaRidleySecondEyeGlow();
    }

    if (gSubSpriteData1.workVariable3 >= HEALTH_THRESHOLD_COVER_BROKEN)
    {
        gSubSpriteData1.health = gCurrentSprite.health;

        health = gBossWork.work9;

        if (gSubSpriteData1.health < health / 4)
            gSubSpriteData1.workVariable3 = HEALTH_THRESHOLD_QUARTER;
        else if (gSubSpriteData1.health < health / 2)
            gSubSpriteData1.workVariable3 = HEALTH_THRESHOLD_HALF;
        else if (gSubSpriteData1.health < health * 3 / 4)
            gSubSpriteData1.workVariable3 = HEALTH_THRESHOLD_THREE_QUARTERS;
    }

    gCurrentSprite.arrayOffset++;
    if (gCurrentSprite.pose == 0x9 || gCurrentSprite.pose == 0x25)
        gSubSpriteData1.workVariable2++;

    SpriteUtilUpdateSubSprite1Anim();
    MechaRidleySyncSubSprites();
}

void MechaRidleyPart(void)
{

}

void MechaRidleyLaser(void)
{

}

void MechaRidleyMissile(void)
{

}

void MechaRidleyFireball(void)
{

}
