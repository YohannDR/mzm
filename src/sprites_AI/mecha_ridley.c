#include "sprites_AI/mecha_ridley.h"
#include "sprites_AI/item_banner.h"
#include "transparency.h"
#include "sprite_util.h" // delete
#include "gba.h"

#include "data/sprites/mecha_ridley.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/sprite_util.h"
#include "constants/sprite.h"

#include "structs/connection.h"
#include "structs/in_game_timer.h"
#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/visual_effects.h"

#define HEALTH_THRESHOLD_FULL 0
#define HEALTH_THRESHOLD_COVER_DAMAGED 1
#define HEALTH_THRESHOLD_COVER_BROKEN 2
#define HEALTH_THRESHOLD_THREE_QUARTERS 3
#define HEALTH_THRESHOLD_HALF 4
#define HEALTH_THRESHOLD_QUARTER 5


#define CHECK_COVER_HEALTH_THRESHOLD(maxHealth)                     \
do {                                                                \
if (gSubSpriteData1.health < maxHealth * 3 / 4)                     \
    gSubSpriteData1.workVariable3 = HEALTH_THRESHOLD_COVER_DAMAGED; \
} while(0);                                                         \


/**
 * Boss work map :
 * 
 * 1 : 
 * 2 : Mecha ridley X position (forward)
 * 3 : Last heigth of samus
 * 4 : Eye state
 * 5 : Missile launcher state
 * 6 : Number of missiles
 * 7 : Current weak spot health max threshold?
 * 8 : Number of fireballs
 * 9 : Core spawn health
 * 10 : Cover spawn health
 * 11 : Completion percentage
 * 
 */

/**
 * Sub sprite data (work variables) map :
 * 
 * 1 : 
 * 2 : Claw attack timer?
 * 3 : Health threshold
 * 4 : Right arm ram slot
 * 5 : Left arm ram slot
 */


void MechaRidleySyncSubSprites(void)
{

}

/**
 * @brief 4bb04 | 84 | Handles the green palette cycle
 * 
 */
void MechaRidleyPartGreenGlow(void)
{
    u8 palRow;
    u8 stage;

    if (gCurrentSprite.timer != 0)
        gCurrentSprite.timer--;
    else
    {
        stage = gCurrentSprite.workVariable++;

        palRow = sMechaRidleyGreenGlowPaletteData[stage][0];
        if (palRow == SCHAR_MAX + 1)
        {
            gCurrentSprite.workVariable = 1;
            stage = 0;
            palRow = sMechaRidleyGreenGlowPaletteData[stage][0];
        }

        gCurrentSprite.timer = sMechaRidleyGreenGlowPaletteData[stage][1];

        dma_set(3, &sMechaRidleyGreenGlowPAL[palRow * 16],
            PALRAM_BASE + 0x31A + gCurrentSprite.absolutePaletteRow * 32,
            (DMA_ENABLE << 16) | 3);
    }
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

/**
 * @brief 4c198 | 48 | Initializes Mecha ridley to be walking at the beginning of the fight
 * 
 */
void MechaRidleyStartWalking(void)
{
    gCurrentSprite.pose = MECHA_RIDLEY_POSE_DELAY_BEFORE_CRAWLING;
    SoundPlay(0x2B3);

    dma_set(3, sMechaRidleyFadingPAL, PALRAM_BASE + 0x300, (DMA_ENABLE << 16) | 13);

    TransparencyUpdateBLDCNT(1,
        BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL |
        BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG3_SECOND_TARGET_PIXEL |
        BLDCNT_BACKDROP_SECOND_TARGET_PIXEL);
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

/**
 * @brief 4c2a4 | 98 | Handles the fading at the start of the battle
 * 
 */
void MechaRidleyStartBattle(void)
{
    u8 palRow;

    if (--gCurrentSprite.workVariable == 0)
    {
        gCurrentSprite.workVariable = 2;
        palRow = ++gCurrentSprite.timer;
        
        if (palRow > 6)
        {
            gCurrentSprite.pose = MECHA_RIDLEY_POSE_IDLE;
            MusicPlay(MUSIC_MECHA_RIDLEY_BATTLE, 0);
            gDisableAnimatedPalette = FALSE;
        }
        else
        {
            if (palRow == 1)
                SoundPlay(0x2AD);

            dma_set(3, &sMechaRidleyFadingPAL[palRow * 16],
                PALRAM_BASE + 0x300, (DMA_ENABLE << 16) | 13);

            TransparencySpriteUpdateBLDALPHA(palRow + 10, 0, 0, 16);
        }
    }
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

            if (gSubSpriteData1.workVariable3 == HEALTH_THRESHOLD_COVER_DAMAGED && gBossWork.work6 == 0)
            {
                if (gBossWork.work5 == MISSILE_LAUNCHER_STATE_IDLE && gEquipment.currentMissiles + gEquipment.currentSuperMissiles != 0)
                {
                    // Start fireball attack
                    gCurrentSprite.pose = MECHA_RIDLEY_POSE_FIREBALL_ATTACK_INIT;
                    return TRUE;
                }
            }

            // Start laser attack
            gBossWork.work4 = EYE_STATE_LASER_ATTACK_INIT;
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
        gBossWork.work5 = MISSILE_LAUNCHER_STATE_MISSILE_ATTACK_INIT;
}

void MechaRidleyClawAttack(void)
{

}

void MechaRidleyStandingUp(void)
{

}

/**
 * @brief 4c5dc | 54 | Handles mecha ridley being curled up
 * 
 */
void MechaRidleyCurledUp(void)
{
    u8 leftArmSlot;

    leftArmSlot = gSubSpriteData1.workVariable5;
    if (!unk_4bcd0())
    {
        if (gBossWork.work7 > gSubSpriteData1.health)
            unk_4bdf8(leftArmSlot);
        else if (MechaRidleyCheckStartFireballAttack(leftArmSlot))
            return;
    }

    if (gSubSpriteData1.workVariable2 == 170)
        gBossWork.work5 = MISSILE_LAUNCHER_STATE_MISSILE_ATTACK_INIT;
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

/**
 * @brief 4ca30 | 1a8 | Handles mecha ridley fading when dying
 * 
 */
void MechaRidleyGlowFading(void)
{
    switch (gCurrentSprite.timer++)
    {
        case 0:
            dma_set(3, sMechaRidleyDestroyedGFX, VRAM_BASE + 0x15580, (DMA_ENABLE << 16) | 0x40);
            break;

        case 1:
            dma_set(3, &sMechaRidleyDestroyedGFX[0x60], VRAM_BASE + 0x15980, (DMA_ENABLE << 16) | 0x60);
            break;

        case 2:
            dma_set(3, &sMechaRidleyDestroyedGFX[0xC0], VRAM_BASE + 0x15D80, (DMA_ENABLE << 16) | 0x60);
            break;

        case 3:
            dma_set(3, &sMechaRidleyDestroyedGFX[0x120], VRAM_BASE + 0x16180, (DMA_ENABLE << 16) | 0x60);
            break;

        case 4:
            dma_set(3, &sMechaRidleyDestroyedGFX[0x180], VRAM_BASE + 0x16580, (DMA_ENABLE << 16) | 0x60);
            break;

        case 5:
            dma_set(3, &sMechaRidleyDestroyedGFX[0x200], VRAM_BASE + 0x169C0, (DMA_ENABLE << 16) | 0x40);
            break;

        case 6:
            dma_set(3, &sMechaRidleyDestroyedGFX[0x260], VRAM_BASE + 0x16DC0, (DMA_ENABLE << 16) | 0x40);
            break;

        case 8:
            dma_set(3, sMechaRidley_8323b42_PAL, PALRAM_BASE + 0x39A, (DMA_ENABLE << 16) | 3);
            break;

        case 16:
            dma_set(3, sMechaRidley_8323b62_PAL, PALRAM_BASE + 0x39A, (DMA_ENABLE << 16) | 3);
            break;
    }

    if (gCurrentSprite.timer > 200)
    {
        gCurrentSprite.yPositionSpawn = 0;
        gCurrentSprite.timer = 0;
        gCurrentSprite.pose = MECHA_RIDLEY_POSE_SPAWN_DROPS;
        gBossWork.work4 = EYE_STATE_LASER_SET_INACTIVE;
    }
}

void MechaRidleySpawnDrops(void)
{

}

/**
 * @brief 4ce1c | a4 | Handles the first eye glow after the fight
 * 
 */
void MechaRidleyFirstEyeGlow(void)
{
    if (--gCurrentSprite.workVariable2 == 0)
    {
        gCurrentSprite.workVariable2 = 4;

        if (gCurrentSprite.workVariable != 0)
        {
            gCurrentSprite.workVariable = 0;
            dma_set(3, &sMechaRidleyGreenGlowPAL[2 * 16 + 4], PALRAM_BASE + 0x322, (DMA_ENABLE << 16) | 6);
        }
        else
        {
            gCurrentSprite.workVariable = 1;
            dma_set(3, &sMechaRidleyGreenGlowPAL[3 * 16 + 4], PALRAM_BASE + 0x322, (DMA_ENABLE << 16) | 6);
        }
    }

    if (--gCurrentSprite.timer == 0)
    {
        gCurrentSprite.pose = MECHA_RIDLEY_POSE_SECOND_EYE_GLOW;
        gCurrentSprite.timer = 200;
        gCurrentSprite.workVariable = 0;
        gCurrentSprite.workVariable2 = 4;
        gBossWork.work4 = EYE_STATE_LASER_SET_DYING;
        SoundPlay(0x2B1);
    }
}

/**
 * @brief 4cec0 | c8 | Handles the second eye glow after the fight
 * 
 */
void MechaRidleySecondEyeGlow(void)
{
    if (--gCurrentSprite.workVariable2 == 0)
    {
        gCurrentSprite.workVariable2 = 4;

        if (gCurrentSprite.workVariable != 0)
        {
            gCurrentSprite.workVariable = 0;
            dma_set(3, &sMechaRidleyGreenGlowPAL[3 * 16 + 4], PALRAM_BASE + 0x322, (DMA_ENABLE << 16) | 6);
        }
        else
        {
            gCurrentSprite.workVariable = 1;
            dma_set(3, sMechaRidley_8323b4a_PAL, PALRAM_BASE + 0x322, (DMA_ENABLE << 16) | 6);
        }
    }

    if (gCurrentSprite.timer != 0)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0)
        {
            EventFunction(EVENT_ACTION_SETTING, EVENT_MECHA_RIDLEY_KILLED);
            SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_CHOZODIA_ESCAPE, 0, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

            gInGameTimerAtBosses[3] = gInGameTimer;
            gDoorUnlockTimer = -20;
            gDisableAnimatedPalette = FALSE;

            MusicPlay(MUSIC_ESCAPE, 0x40);
        }
    }
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
            gCurrentSprite.pose = MECHA_RIDLEY_PART_POSE_RIGHT_ARM_IDLE;
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
            gCurrentSprite.pose = MECHA_RIDLEY_PART_POSE_LEFT_ARM_IDLE;
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
            gCurrentSprite.pose = MECHA_RIDLEY_PART_POSE_EYE_IDLE;
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
            gCurrentSprite.pose = MECHA_RIDLEY_PART_POSE_NECK_IDLE;
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
            gCurrentSprite.pose = MECHA_RIDLEY_PART_POSE_COVER_IDLE;
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
            gCurrentSprite.pose = MECHA_RIDLEY_PART_POSE_MISSILE_LAUNCHER_IDLE;
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
    MechaRidleyPartGreenGlow();
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
    gCurrentSprite.pose = MECHA_RIDLEY_PART_POSE_COVER_BROKEN;

    ParticleSet(gCurrentSprite.yPosition + 13, gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE, PE_SPRITE_EXPLOSION_HUGE);
    SoundPlay(0x12F);
}

/**
 * @brief 4d3a4 | 190 | Handles the missile launcher part being idle
 * 
 */
void MechaRidleyPartMissileLauncherIdle(void)
{
    unk_4bc2c();

    switch (gBossWork.work5)
    {
        case MISSILE_LAUNCHER_STATE_MISSILE_ATTACK_INIT:
            if (gSubSpriteData1.workVariable3 >= HEALTH_THRESHOLD_COVER_BROKEN || gEquipment.currentEnergy < 150 ||
                gEquipment.currentMissiles + gEquipment.currentSuperMissiles == 0)
            {
                // Set opening
                gCurrentSprite.pOam = sMechaRidleyPartOAM_MissileLauncherOpening;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;

                gBossWork.work5 = MISSILE_LAUNCHER_STATE_OPENING;
                SoundPlay(0x2A6);
            }
            else
                gBossWork.work5 = MISSILE_LAUNCHER_STATE_IDLE; // Cancel attack
            break;

        case MISSILE_LAUNCHER_STATE_OPENING:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sMechaRidleyPartOAM_MissileLauncherOpened;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;

                gBossWork.work5 = MISSILE_LAUNCHER_STATE_OPENED;
                gCurrentSprite.timer = MISSILE_LAUNCHER_STATE_OPENED;
            }
            break;

        case MISSILE_LAUNCHER_STATE_OPENED:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.timer--;
                if (gCurrentSprite.timer == 0)
                {
                    gCurrentSprite.pOam = sMechaRidleyPartOAM_MissileLauncherClosing;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.animationDurationCounter = 0;

                    gBossWork.work5 = MISSILE_LAUNCHER_STATE_CLOSING;
                }
            }
            else
            {
                if (gCurrentSprite.currentAnimationFrame == 1 && gCurrentSprite.animationDurationCounter == 1)
                {
                    if (gCurrentSprite.timer == 1)
                    {
                        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_MISSILE, 0, gCurrentSprite.spritesetGFXSlot,
                            gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition - BLOCK_SIZE,
                            gCurrentSprite.xPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE), 0);
                    }
                    else if (gCurrentSprite.timer == 2)
                    {
                        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_MISSILE, 1, gCurrentSprite.spritesetGFXSlot,
                            gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition - 0x34,
                            gCurrentSprite.xPosition - 0x3C, 0);
                    }
                    else
                    {
                        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_MISSILE, 2, gCurrentSprite.spritesetGFXSlot,
                            gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition - 0x34,
                            gCurrentSprite.xPosition - 0x24, 0);

                        SoundPlay(0x2A7);
                    }
                }
            }
            break;

        case MISSILE_LAUNCHER_STATE_CLOSING:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sMechaRidleyPartOAM_MissileLauncherClosed;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;

                gBossWork.work5 = MISSILE_LAUNCHER_STATE_IDLE;
            }
            break;
    }
}

/**
 * @brief 4d534 | 1f4 | Handles the eye part being idle
 * 
 */
void MechaRidleyPartEyeIdle(void)
{
    u8 rng;
    u8 direction;

    rng = gSpriteRNG;

    switch (gBossWork.work4)
    {
        case EYE_STATE_BLINKING_INIT:
            if (gCurrentSprite.pOam != sMechaRidleyPartOAM_EyeIdle)
                gCurrentSprite.pOam = sMechaRidleyPartOAM_EyeIdle;

            // Set blinking animation
            gCurrentSprite.currentAnimationFrame = 1;
            gCurrentSprite.animationDurationCounter = 0;
            gBossWork.work4 = EYE_STATE_IDLE;
            break;

        case EYE_STATE_LASER_ATTACK_INIT:
            if (gSubSpriteData1.workVariable3 < HEALTH_THRESHOLD_COVER_BROKEN)
            {
                gBossWork.work4 = EYE_STATE_IDLE;
                break;
            }

            // Set glowing
            gCurrentSprite.pOam = sMechaRidleyPartOAM_EyeGlowing;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;

            gCurrentSprite.timer = 40;
            gBossWork.work4 = EYE_STATE_LASER_ATTACK;
            break;

        case EYE_STATE_LASER_ATTACK:
            if (gCurrentSprite.timer != 0)
            {
                // Delay before attack
                gCurrentSprite.timer--;
                if (gCurrentSprite.timer != 0)
                    break;

                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;

                // Get direction
                if (rng > 11)
                {
                    gCurrentSprite.pOam = sMechaRidleyPartOAM_EyeShootingLaserSlightlyDown;
                    gCurrentSprite.workVariable = LASER_DIRECTION_SLIGHTLY_DOWN;
                }
                else if (rng > 7)
                {
                    gCurrentSprite.pOam = sMechaRidleyPartOAM_EyeShootingLaserSlightlyUp;
                    gCurrentSprite.workVariable = LASER_DIRECTION_SLIGHTLY_UP;
                }
                else if (rng > 3)
                {
                    gCurrentSprite.pOam = sMechaRidleyPartOAM_EyeShootingLaserDown;
                    gCurrentSprite.workVariable = LASER_DIRECTION_DOWN;
                }
                else
                {
                    gCurrentSprite.pOam = sMechaRidleyPartOAM_EyeShootingLaserForward;
                    gCurrentSprite.workVariable = LASER_DIRECTION_FORWARD;
                }

                SoundPlay(0x2AA);
            }
            else if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                // Spawn laser
                direction = gCurrentSprite.workVariable;
                switch (direction)
                {
                    case LASER_DIRECTION_SLIGHTLY_DOWN:
                        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_LASER, LASER_DIRECTION_SLIGHTLY_DOWN,
                            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                            gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition - 0x6C, 0);
                        break;

                    case LASER_DIRECTION_DOWN:
                        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_LASER, LASER_DIRECTION_DOWN,
                            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                            gCurrentSprite.yPosition + (BLOCK_SIZE + HALF_BLOCK_SIZE),
                            gCurrentSprite.xPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), 0);
                        break;

                    case LASER_DIRECTION_SLIGHTLY_UP:
                        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_LASER, LASER_DIRECTION_SLIGHTLY_UP,
                            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                            gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition - 0x6C, 0);
                        break;

                    case LASER_DIRECTION_UP:
                        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_LASER, LASER_DIRECTION_UP,
                            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                            gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
                            gCurrentSprite.xPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), 0);
                        break;

                    default:
                        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_LASER, direction,
                            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                            gCurrentSprite.yPosition, gCurrentSprite.xPosition - BLOCK_SIZE * 2, 0);
                        break;
                }

                // Set idle
                gCurrentSprite.pOam = sMechaRidleyPartOAM_EyeIdle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gBossWork.work4 = EYE_STATE_IDLE;
            }
            break;
    }
}

/**
 * @brief 4d728 | 200 | Handles the right arm part being idle
 * 
 */
void MechaRidleyPartRightArmIdle(void)
{
    u8 ramSlot;
    i32 topHitbox;
    i32 bottomHitbox;
    i32 leftHitbox;
    i32 rightHitbox;

    u16 rHitbox;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    topHitbox = 0;
    bottomHitbox = 0;
    leftHitbox = 0;
    rightHitbox = 0;

    // Update hitbox based on animation
    if (gCurrentSprite.pOam == sMechaRidleyPartOAM_RightArmTrembling)
    {
        topHitbox = BLOCK_SIZE * 2;
        bottomHitbox = BLOCK_SIZE * 3;
        leftHitbox = -0xE8;
        rightHitbox = BLOCK_SIZE;
    }
    else if (gCurrentSprite.pOam == sMechaRidleyPartOAM_RightArmHoldingUp)
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 0:
                topHitbox = BLOCK_SIZE;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -BLOCK_SIZE * 3;
                rightHitbox = BLOCK_SIZE;
                break;

            case 1:
            case 2:
            case 3:
            case 4:
                topHitbox = HALF_BLOCK_SIZE;
                bottomHitbox = BLOCK_SIZE * 2;
                leftHitbox = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
                break;
        }
    }
    else if (gCurrentSprite.pOam == sMechaRidleyPartOAM_RightArmCrawlingForward)
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 0:
                if (gCurrentSprite.animationDurationCounter == 1 && gSpriteData[ramSlot].pose > 7)
                    SoundPlay(0x2B2);

                topHitbox = BLOCK_SIZE;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -BLOCK_SIZE * 3;
                rightHitbox = BLOCK_SIZE;
                break;

            case 1:
                topHitbox = BLOCK_SIZE;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
                break;

            case 2:
                topHitbox = BLOCK_SIZE;
                bottomHitbox = (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                leftHitbox = -(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
                break;

            case 3:
            case 4:
            case 5:
                topHitbox = BLOCK_SIZE * 2;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -BLOCK_SIZE * 5;
                rightHitbox = BLOCK_SIZE;
                break;

            case 6:
                topHitbox = BLOCK_SIZE * 2;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
                break;

            case 7:
            case 8:
            case 9:
            case 10:
                topHitbox = BLOCK_SIZE * 2;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
        }
    }
    else if (gCurrentSprite.pOam == sMechaRidleyPartOAM_RightArmCrawlingBackwards)
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 0:
            case 1:
            case 2:
            case 10:
                topHitbox = BLOCK_SIZE * 2;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
                break;

            case 3:
                topHitbox = BLOCK_SIZE * 2;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
                break;

            case 4:
                topHitbox = BLOCK_SIZE * 2;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -(BLOCK_SIZE * 5 + HALF_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
                break;

            case 5:
            case 6:
                topHitbox = BLOCK_SIZE * 2;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -(BLOCK_SIZE * 5 + HALF_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
                break;
            
            case 7:
                if (gCurrentSprite.animationDurationCounter == 1 && gSpriteData[ramSlot].pose > 7)
                    SoundPlay(0x2B2);

                topHitbox = BLOCK_SIZE;
                bottomHitbox = (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                leftHitbox = -(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
                break;

            case 8:
                topHitbox = BLOCK_SIZE;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
                break;

            case 9:
                topHitbox = BLOCK_SIZE;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -BLOCK_SIZE * 3;
                rightHitbox = BLOCK_SIZE;
        }
    }

    gCurrentSprite.hitboxTopOffset = topHitbox;
    gCurrentSprite.hitboxBottomOffset = bottomHitbox;
    gCurrentSprite.hitboxLeftOffset = leftHitbox;

    rHitbox = rightHitbox;
    gCurrentSprite.hitboxRightOffset = rHitbox;
}

/**
 * @brief 4d928 | 238 | Handles the left arm part being idle
 * 
 */
void MechaRidleyPartLeftArmIdle(void)
{
    i32 topHitbox;
    i32 bottomHitbox;
    i32 leftHitbox;
    i32 rightHitbox;

    topHitbox = 0;
    bottomHitbox = 0;
    leftHitbox = 0;
    rightHitbox = 0;

    // Update hitbox based on animation
    if (gCurrentSprite.pOam == sMechaRidleyPartOAM_LeftArmHeldUp)
    {
        topHitbox = HALF_BLOCK_SIZE;
        bottomHitbox = BLOCK_SIZE * 2;
        leftHitbox = -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
        rightHitbox = BLOCK_SIZE;
    }
    else if (gCurrentSprite.pOam == sMechaRidleyPartOAM_LeftArmTrembling)
    {
        topHitbox = BLOCK_SIZE * 2;
        bottomHitbox = BLOCK_SIZE * 3;
        leftHitbox = -BLOCK_SIZE * 5;
        rightHitbox = BLOCK_SIZE;
    }
    else if (gCurrentSprite.pOam == sMechaRidleyPartOAM_LeftArmSwingingAtCloseGround)
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 0:
                if (gCurrentSprite.animationDurationCounter == 1)
                    SoundPlay(0x2A4);

                topHitbox = -BLOCK_SIZE;
                bottomHitbox = BLOCK_SIZE;
                leftHitbox = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
                break;

            case 1:
                topHitbox = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                bottomHitbox = BLOCK_SIZE;
                leftHitbox = -BLOCK_SIZE * 2;
                rightHitbox = BLOCK_SIZE;
                break;

            case 2:
                topHitbox = -(BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE);
                bottomHitbox = 0;
                leftHitbox = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
                break;

            case 3:
                if (gCurrentSprite.animationDurationCounter == 20)
                    SoundPlay(0x2A5);

                topHitbox = -(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
                bottomHitbox = 0;
                leftHitbox = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
                break;

            case 4:
                topHitbox = -(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
                bottomHitbox = 0;
                leftHitbox = -BLOCK_SIZE * 4;
                rightHitbox = BLOCK_SIZE;
                break;

            case 5:
                topHitbox = -BLOCK_SIZE * 2;
                bottomHitbox = 0;
                leftHitbox = -(BLOCK_SIZE * 7 - QUARTER_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
                break;

            case 6:
                topHitbox = 0;
                bottomHitbox = BLOCK_SIZE + QUARTER_BLOCK_SIZE;
                leftHitbox = -BLOCK_SIZE * 7;
                rightHitbox = BLOCK_SIZE;
                break;

            case 7:
                if (gCurrentSprite.animationDurationCounter == 1)
                {
                    ScreenShakeStartVertical(20, 0x81);
                    SoundPlay(0x2A0);
                }

            case 8:
                topHitbox = BLOCK_SIZE * 2;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -BLOCK_SIZE * 6;
                rightHitbox = -BLOCK_SIZE * 3;
                break;

            case 9:
                topHitbox = BLOCK_SIZE * 2;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -(BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE);
                rightHitbox = -BLOCK_SIZE * 3;
        }
    }
    else if (gCurrentSprite.pOam == sMechaRidleyPartOAM_LeftArmHoldingUp)
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 0:
                topHitbox = BLOCK_SIZE * 2;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -BLOCK_SIZE * 5;
                rightHitbox = BLOCK_SIZE;
                break;

            case 1:
                if (gCurrentSprite.animationDurationCounter == 8)
                    SoundPlay(0x2A3);
                topHitbox = BLOCK_SIZE * 2;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -BLOCK_SIZE * 5;
                rightHitbox = BLOCK_SIZE;
                break;
            
            case 2:
                topHitbox = BLOCK_SIZE;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -BLOCK_SIZE * 4;
                rightHitbox = BLOCK_SIZE;
                break;

            case 3:
            case 4:
                topHitbox = 0;
                bottomHitbox = BLOCK_SIZE * 2;
                leftHitbox = -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
                break;
        }
    }
    else if (gCurrentSprite.pOam == sMechaRidleyPartOAM_LeftArmCrawlingForward)
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 0:
                topHitbox = BLOCK_SIZE * 2;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -BLOCK_SIZE * 4;
                rightHitbox = BLOCK_SIZE;
                break;

            case 1:
            case 2:
            case 3:
            case 4:
                topHitbox = BLOCK_SIZE * 2;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
                break;

            case 5:
                topHitbox = BLOCK_SIZE;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                rightHitbox = BLOCK_SIZE;
                break;

            case 6:
                topHitbox = BLOCK_SIZE;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -BLOCK_SIZE * 3;
                rightHitbox = BLOCK_SIZE;
                break;

            case 7:
                topHitbox = BLOCK_SIZE;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -BLOCK_SIZE * 4;
                rightHitbox = BLOCK_SIZE;
                break;

            case 8:
            case 9:
            case 10:
                topHitbox = BLOCK_SIZE * 2;
                bottomHitbox = BLOCK_SIZE * 3;
                leftHitbox = -BLOCK_SIZE * 5;
                rightHitbox = HALF_BLOCK_SIZE;
        }
    }

    gCurrentSprite.hitboxTopOffset = topHitbox;
    gCurrentSprite.hitboxBottomOffset = bottomHitbox;
    gCurrentSprite.hitboxLeftOffset = leftHitbox;
    gCurrentSprite.hitboxRightOffset = rightHitbox;
}

/**
 * @brief 4db60 | 1f8 | Handles the neck part being idle
 * 
 */
void MechaRidleyPartNeckIdle(void)
{
    i32 topHitbox;
    i32 bottomHitbox;
    i32 leftHitbox;
    i32 rightHitbox;

    u16 rHitbox;

    topHitbox = 0;
    bottomHitbox = 0;
    leftHitbox = 0;
    rightHitbox = 0;

    if (gCurrentSprite.pOam == sMechaRidleyPartOAM_NeckLow)
    {
        topHitbox = -HALF_BLOCK_SIZE;
        bottomHitbox = BLOCK_SIZE + HALF_BLOCK_SIZE;
        leftHitbox = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
        rightHitbox = HALF_BLOCK_SIZE;
    }
    else if (gCurrentSprite.pOam == sMechaRidleyPartOAM_NeckLow_2)
    {
        topHitbox = -HALF_BLOCK_SIZE;
        bottomHitbox = BLOCK_SIZE + HALF_BLOCK_SIZE;
        leftHitbox = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
        rightHitbox = HALF_BLOCK_SIZE;
    }
    else if (gCurrentSprite.pOam == sMechaRidleyPartOAM_NeckMiddle || gCurrentSprite.pOam == sMechaRidleyPartOAM_NeckMiddle_2)
    {
        topHitbox = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
        bottomHitbox = QUARTER_BLOCK_SIZE;
        leftHitbox = -BLOCK_SIZE * 2;
        rightHitbox = HALF_BLOCK_SIZE;
    }
    else if (gCurrentSprite.pOam == sMechaRidleyPartOAM_NeckHigh || gCurrentSprite.pOam == sMechaRidleyPartOAM_NeckHigh_2)
    {
        topHitbox = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
        bottomHitbox = QUARTER_BLOCK_SIZE;
        leftHitbox = -BLOCK_SIZE;
        rightHitbox = HALF_BLOCK_SIZE;
    }
    else if (gCurrentSprite.pOam == sMechaRidleyPartOAM_NeckLowToMiddle)
    {
        if (gCurrentSprite.currentAnimationFrame == 0)
        {
            if (gCurrentSprite.animationDurationCounter == 1)
                SoundPlay(0x2AB);

            topHitbox = -BLOCK_SIZE;
            bottomHitbox = BLOCK_SIZE;
            leftHitbox = -BLOCK_SIZE * 2;
            rightHitbox = HALF_BLOCK_SIZE;
        }
        else
        {
            topHitbox = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            bottomHitbox = QUARTER_BLOCK_SIZE;
            leftHitbox = -BLOCK_SIZE * 2;
            rightHitbox = HALF_BLOCK_SIZE;
        }
    }
    else if (gCurrentSprite.pOam == sMechaRidleyPartOAM_NeckMiddleToHigh)
    {
        if (gCurrentSprite.currentAnimationFrame == 0)
        {
            if (gCurrentSprite.animationDurationCounter == 1)
                SoundPlay(0x2AB);

            topHitbox = -BLOCK_SIZE * 2;
            bottomHitbox = 0;
            leftHitbox = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            rightHitbox = HALF_BLOCK_SIZE;
        }
        else
        {
            topHitbox = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            bottomHitbox = QUARTER_BLOCK_SIZE;
            leftHitbox = -BLOCK_SIZE;
            rightHitbox = HALF_BLOCK_SIZE;
        }
    }
    else if (gCurrentSprite.pOam == sMechaRidleyPartOAM_NeckHighToMiddle)
    {
        if (gCurrentSprite.currentAnimationFrame == 0)
        {
            if (gCurrentSprite.animationDurationCounter == 1)
                SoundPlay(0x2AC);

            topHitbox = -BLOCK_SIZE * 2;
            bottomHitbox = 0;
            leftHitbox = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            rightHitbox = HALF_BLOCK_SIZE;
        }
        else
        {
            topHitbox = -BLOCK_SIZE;
            bottomHitbox = QUARTER_BLOCK_SIZE;
            leftHitbox = -BLOCK_SIZE * 2;
            rightHitbox = HALF_BLOCK_SIZE;
        }
    }
    else if (gCurrentSprite.pOam == sMechaRidleyPartOAM_NeckMiddleToLow)
    {
        if (gCurrentSprite.currentAnimationFrame == 0)
        {
            if (gCurrentSprite.animationDurationCounter == 1)
                SoundPlay(0x2AC);

            topHitbox = -BLOCK_SIZE;
            bottomHitbox = BLOCK_SIZE;
            leftHitbox = -BLOCK_SIZE * 2;
            rightHitbox = HALF_BLOCK_SIZE;
        }
        else
        {
            topHitbox = -HALF_BLOCK_SIZE;
            bottomHitbox = BLOCK_SIZE + HALF_BLOCK_SIZE;
            leftHitbox = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            rightHitbox = HALF_BLOCK_SIZE;
        }
    }
    else if (gCurrentSprite.pOam == sMechaRidleyPartOAM_NeckLowToHigh)
    {
        if (gCurrentSprite.currentAnimationFrame == 0)
        {
            if (gCurrentSprite.animationDurationCounter == 1)
                SoundPlay(0x2A1);

            topHitbox = -BLOCK_SIZE;
            bottomHitbox = BLOCK_SIZE;
            leftHitbox = -BLOCK_SIZE * 2;
            rightHitbox = HALF_BLOCK_SIZE;
        }
        else if (gCurrentSprite.currentAnimationFrame == 1)
        {
            topHitbox = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            bottomHitbox = QUARTER_BLOCK_SIZE;
            leftHitbox = -BLOCK_SIZE * 2;
            rightHitbox = HALF_BLOCK_SIZE;
        }
        else if (gCurrentSprite.currentAnimationFrame == 2)
        {
            topHitbox = -BLOCK_SIZE * 2;
            bottomHitbox = 0;
            leftHitbox = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            rightHitbox = HALF_BLOCK_SIZE;
        }
        else if (gCurrentSprite.currentAnimationFrame == 3)
        {
            topHitbox = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            bottomHitbox = 0;
            leftHitbox = -BLOCK_SIZE;
            rightHitbox = HALF_BLOCK_SIZE;
        }
    }
    else if (gCurrentSprite.pOam == sMechaRidleyPartOAM_NeckHighToLow)
    {
        if (gCurrentSprite.currentAnimationFrame == 0)
        {
            if (gCurrentSprite.animationDurationCounter == 1)
                SoundPlay(0x2A2);

            topHitbox = -BLOCK_SIZE * 2;
            bottomHitbox = 0;
            leftHitbox = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            rightHitbox = HALF_BLOCK_SIZE;
        }
        else if (gCurrentSprite.currentAnimationFrame == 1)
        {
            topHitbox = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            bottomHitbox = QUARTER_BLOCK_SIZE;
            leftHitbox = -BLOCK_SIZE * 2;
            rightHitbox = HALF_BLOCK_SIZE;
        }
        else if (gCurrentSprite.currentAnimationFrame == 2)
        {
            topHitbox = -BLOCK_SIZE;
            bottomHitbox = BLOCK_SIZE;
            leftHitbox = -BLOCK_SIZE * 2;
            rightHitbox = HALF_BLOCK_SIZE;
        }
        else if (gCurrentSprite.currentAnimationFrame == 3)
        {
            topHitbox = -HALF_BLOCK_SIZE;
            bottomHitbox = BLOCK_SIZE + HALF_BLOCK_SIZE;
            leftHitbox = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            rightHitbox = HALF_BLOCK_SIZE;
        }
    }

    gCurrentSprite.hitboxTopOffset = topHitbox;
    gCurrentSprite.hitboxBottomOffset = bottomHitbox;
    gCurrentSprite.hitboxLeftOffset = leftHitbox;

    rHitbox = rightHitbox;
    gCurrentSprite.hitboxRightOffset = rHitbox;
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

/**
 * @brief 4e0dc | 3c4 | Mecha ridley part AI
 * 
 */
void MechaRidleyPart(void)
{
    u8 ramSlot;
    u8 partNumber;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    partNumber = gCurrentSprite.roomSlot;

    if (gSpriteData[ramSlot].pose > 0x61)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 1;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.invincibilityStunFlashTimer = gSpriteData[ramSlot].invincibilityStunFlashTimer;

        switch (partNumber)
        {
            case MECHA_RIDLEY_PART_RIGHT_ARM:
                gCurrentSprite.drawOrder = 9;
                break;

            case MECHA_RIDLEY_PART_EYE:
                gCurrentSprite.drawOrder = 10;
                break;

            case MECHA_RIDLEY_PART_HEAD:
                gCurrentSprite.drawOrder = 11;
                break;

            case MECHA_RIDLEY_PART_NECK:
                gCurrentSprite.drawOrder = 12;
                break;

            case MECHA_RIDLEY_PART_TORSO:
                gCurrentSprite.drawOrder = 13;
                break;

            case MECHA_RIDLEY_PART_WAISTBAND:
                gCurrentSprite.drawOrder = 14;
                break;

            case MECHA_RIDLEY_PART_LEFT_ARM:
                gCurrentSprite.drawOrder = 15;
                break;

            case MECHA_RIDLEY_PART_TAIL:
            case MECHA_RIDLEY_PART_MISSILE_LAUNCHER:
                gCurrentSprite.drawOrder = 16;
                break;
        }

        if (partNumber == MECHA_RIDLEY_PART_EYE)
        {
            switch (gBossWork.work4)
            {
                case 4:
                    gCurrentSprite.pOam = sMechaRidleyPartOAM_EyeIdle;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.animationDurationCounter = 0;

                    gBossWork.work4 = 7;
                    break;

                case EYE_STATE_LASER_SET_INACTIVE:
                    gCurrentSprite.pOam = sMechaRidleyPartOAM_EyeInactive;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.animationDurationCounter = 0;

                    gBossWork.work4 = 7;
                    break;

                case EYE_STATE_LASER_SET_DYING:
                    gCurrentSprite.pOam = sMechaRidleyPartOAM_EyeDying;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.animationDurationCounter = 0;

                    gBossWork.work4 = 7;
                    break;
            }

            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
        }
        else
            MechaRidleySyncSubSprites();

        return;
    }

    if (gCurrentSprite.pose != 0 && gCurrentSprite.health != 0)
    {
        if (partNumber == MECHA_RIDLEY_PART_EYE)
        {
            if (gSubSpriteData1.workVariable3 > HEALTH_THRESHOLD_COVER_DAMAGED)
                gCurrentSprite.invincibilityStunFlashTimer = gSpriteData[ramSlot].invincibilityStunFlashTimer;
        }
        else 
        {
            if (gSpriteData[ramSlot].pose > MECHA_RIDLEY_POSE_DELAY_BEFORE_CRAWLING)
                BlackSpacePirateProjectileCollision();

            if (gSubSpriteData1.workVariable3 > HEALTH_THRESHOLD_COVER_DAMAGED)
            {
                gCurrentSprite.invincibilityStunFlashTimer = gSpriteData[ramSlot].invincibilityStunFlashTimer;
                if (gCurrentSprite.paletteRow != 0xE)
                {
                    if (gSubSpriteData1.workVariable3 > HEALTH_THRESHOLD_HALF)
                    {
                        gCurrentSprite.paletteRow = 4;
                        gCurrentSprite.absolutePaletteRow = gCurrentSprite.paletteRow;
                    }
                    else if (gSubSpriteData1.workVariable3 > HEALTH_THRESHOLD_THREE_QUARTERS)
                    {
                        gCurrentSprite.paletteRow = 3;
                        gCurrentSprite.absolutePaletteRow = gCurrentSprite.paletteRow;
                    }
                    else if (gSubSpriteData1.workVariable3 > HEALTH_THRESHOLD_COVER_BROKEN)
                    {
                        gCurrentSprite.paletteRow = 2;
                        gCurrentSprite.absolutePaletteRow = gCurrentSprite.paletteRow;
                    }
                }
            }
        }
    }

    switch (gCurrentSprite.pose)
    {
        case 0:
            MechaRidleyPartInit();
            MechaRidleySyncSubSprites();
            break;

        case MECHA_RIDLEY_PART_POSE_RIGHT_ARM_IDLE:
            MechaRidleyPartRightArmIdle();
            if (gSpriteData[ramSlot].pose < 8)
                MechaRidleySyncSubSprites();
            else
                SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case MECHA_RIDLEY_PART_POSE_LEFT_ARM_IDLE:
            MechaRidleyPartLeftArmIdle();
            if (gSpriteData[ramSlot].pose < 8)
                MechaRidleySyncSubSprites();
            else
                SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case MECHA_RIDLEY_PART_POSE_NECK_IDLE:
            MechaRidleyPartNeckIdle();
            MechaRidleySyncSubSprites();
            break;

        case MECHA_RIDLEY_PART_POSE_EYE_IDLE:
            MechaRidleyPartEyeIdle();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case MECHA_RIDLEY_PART_POSE_MISSILE_LAUNCHER_IDLE:
            MechaRidleyPartMissileLauncherIdle();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case MECHA_RIDLEY_PART_POSE_COVER_IDLE:
            MechaRidleyPartCoverIdle();
            MechaRidleySyncSubSprites();
            break;

        case MECHA_RIDLEY_PART_POSE_COVER_DESTROYED:
            MechaRidleyPartCoreCoverExplosion();
            break;

        case MECHA_RIDLEY_PART_POSE_HEAD_IDLE:
            MechaRidleyPartHeadIdle();
            MechaRidleySyncSubSprites();
            break;

        case 0xE:
        case 0x42:
        case 0x43:
        case MECHA_RIDLEY_PART_POSE_COVER_BROKEN:
            break;
        
        default:
            MechaRidleySyncSubSprites();
            break;
    }
}

/**
 * @brief 4e4a0 | 118 | Mecha ridley laser AI
 * 
 */
void MechaRidleyLaser(void)
{
    if (gCurrentSprite.pose == 0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

        gCurrentSprite.drawDistanceTopOffset = 8;
        gCurrentSprite.drawDistanceBottomOffset = 8;
        gCurrentSprite.drawDistanceHorizontalOffset = 8;

        gCurrentSprite.hitboxTopOffset = -HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxBottomOffset = HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxLeftOffset = -HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxRightOffset = HALF_BLOCK_SIZE;

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        gCurrentSprite.drawOrder = 3;
        gCurrentSprite.pose = 9;

        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        // Set OAM
        switch (gCurrentSprite.roomSlot)
        {
            case LASER_DIRECTION_SLIGHTLY_DOWN:
                gCurrentSprite.pOam = sMechaRidleyLaserOAM_SlightlyDown;
                break;

            case LASER_DIRECTION_DOWN:
                gCurrentSprite.pOam = sMechaRidleyLaserOAM_Down;
                break;

            case LASER_DIRECTION_SLIGHTLY_UP:
                gCurrentSprite.pOam = sMechaRidleyLaserOAM_SlightlyUp;
                break;

            case LASER_DIRECTION_UP:
                gCurrentSprite.pOam = sMechaRidleyLaserOAM_Up;
                break;

            default:
                gCurrentSprite.pOam = sMechaRidleyLaserOAM_Forward;
                break;
        }
    }

    // Move
    switch (gCurrentSprite.roomSlot)
    {
        case LASER_DIRECTION_SLIGHTLY_DOWN:
            gCurrentSprite.yPosition += 6;
            gCurrentSprite.xPosition -= QUARTER_BLOCK_SIZE;
            break;

        case LASER_DIRECTION_DOWN:
            gCurrentSprite.yPosition += 15;
            gCurrentSprite.xPosition -= 15;
            break;

        case LASER_DIRECTION_SLIGHTLY_UP:
            gCurrentSprite.yPosition -= 6;
            gCurrentSprite.xPosition -= QUARTER_BLOCK_SIZE;
            break;

        case LASER_DIRECTION_UP:
            gCurrentSprite.yPosition -= 15;
            gCurrentSprite.xPosition -= 15;
            break;

        default:
            gCurrentSprite.xPosition -= 20;
            break;
    }

    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
    {
        // Destroy
        gCurrentSprite.status = 0;
        ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SMALL);
        SoundPlay(0x2C1);
    }
}

/**
 * @brief 4e5b8 | 208 | Mecha ridley missile AI
 * 
 */
void MechaRidleyMissile(void)
{
    u16 movement;

    switch (gCurrentSprite.pose)
    {
        case 0:
            gCurrentSprite.status |= SPRITE_STATUS_YFLIP;

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxBottomOffset = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeftOffset = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRightOffset = HALF_BLOCK_SIZE;

            gCurrentSprite.pOam = sMechaRidleyMissileOAM;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.oamRotation = 0xA0;
            gCurrentSprite.oamScaling = 0x100;
            
            gCurrentSprite.timer = 0x1E;
            gCurrentSprite.pose = 9;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
            gCurrentSprite.drawOrder = 2;

            gBossWork.work6++;
            break;

        case 9:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            movement = gCurrentSprite.timer / 2;
            if (gCurrentSprite.roomSlot == 1)
                movement -= 2;
            else if (gCurrentSprite.roomSlot == 2)
                movement += 2;

            gCurrentSprite.yPosition -= movement;
            gCurrentSprite.xPosition -= movement;

            if (movement < 3)
            {
                gCurrentSprite.oamRotation = SpriteUtilMakeSpriteFaceSamusRotation(gCurrentSprite.oamRotation,
                    gSamusData.yPosition - BLOCK_SIZE, gSamusData.xPosition,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition);
            }

            gCurrentSprite.timer -= 2;
            if (gCurrentSprite.timer < 2)
            {
                gCurrentSprite.pose = 0x23;
                gCurrentSprite.workVariable = 0;
                gCurrentSprite.workVariable2 = 1;
                gCurrentSprite.timer = 0;
                gCurrentSprite.arrayOffset = 1;
            }
            break;

        case 0x23:
            if (gCurrentSprite.roomSlot == 1)
                movement = BLOCK_SIZE;
            else if (gCurrentSprite.roomSlot == 2)
                movement = 0x5C;
            else
                movement = HALF_BLOCK_SIZE;
            
            SpriteUtilMoveSpriteTowardsSamus(gSamusData.yPosition - HALF_BLOCK_SIZE, gSamusData.xPosition, 0x28, 0x28, 2);
            
            gCurrentSprite.oamRotation = SpriteUtilMakeSpriteFaceSamusRotation(gCurrentSprite.oamRotation,
                gSamusData.yPosition - movement, gSamusData.xPosition,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition);

            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
                gCurrentSprite.pose = 0x44;
            break;

        case 0x42:
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_HUGE);
            gCurrentSprite.status = 0;
            gBossWork.work6--;
            SoundPlay(0x2C2);
            break;

        case 0x44:
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SMALL);
            gCurrentSprite.status = 0;
            gBossWork.work6--;
            SoundPlay(0x12C);
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
            gBossWork.work6--;
    }
}

/**
 * @brief 4e7c0 | 150 | Mecha ridley fireball AI
 * 
 */
void MechaRidleyFireball(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTopOffset = 0x14;
            gCurrentSprite.drawDistanceBottomOffset = 0x14;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x14;
            
            gCurrentSprite.hitboxTopOffset = -0x1C;
            gCurrentSprite.hitboxBottomOffset = 0x1C;
            gCurrentSprite.hitboxLeftOffset = -0x1C;
            gCurrentSprite.hitboxRightOffset = 0x1C;

            gCurrentSprite.pOam = sMechaRidleyFireballOAM;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.timer = 0x1E;
            gCurrentSprite.pose = 9;

            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
            gCurrentSprite.drawOrder = 2;
            gCurrentSprite.oamScaling = 0x100;

            if (gCurrentSprite.roomSlot != 0)
                gCurrentSprite.oamRotation = 0x28;
            else
                gCurrentSprite.oamRotation = 0;

            gBossWork.work8++;
            break;

        case 9:
            if (gCurrentSprite.roomSlot != 0)
                gCurrentSprite.yPosition -= 2;
            else
                gCurrentSprite.yPosition += 12;

            gCurrentSprite.xPosition -= 12;

            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
                gCurrentSprite.pose = 0x44;
            break;

        case 0x23:
            break;

        case 0x42:
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_HUGE);
            gCurrentSprite.status = 0;
            gBossWork.work8--;
            SoundPlay(0x2B4);
            break;

        case 0x44:
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SMALL);
            gCurrentSprite.status = 0;
            gBossWork.work8--;
            SoundPlay(0x2B4);
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
            gBossWork.work8--;
    }
}
