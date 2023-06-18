#include "sprites_AI/mecha_ridley.h"
#include "transparency.h"
#include "gba.h"
#include "macros.h"

#include "data/sprites/mecha_ridley.h"
#include "data/sprite_data.h"
#include "data/frame_data_pointers.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/sprite_util.h"
#include "constants/sprite.h"
#include "constants/text.h"

#include "structs/connection.h"
#include "structs/in_game_timer.h"
#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/animated_graphics.h"

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
 * 1 : Mecha ridley spawn Y position
 * 2 : Mecha ridley spawn X position
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
 * 2 : Missile attack timer
 * 3 : Health threshold
 * 4 : Right arm ram slot
 * 5 : Left arm ram slot
 */


/**
 * @brief 4ba9c | 68 | Sync the sub sprites of Mecha ridley
 * 
 */
void MechaRidleySyncSubSprites(void)
{
    u16 (*pData)[3];
    u32 offset;

    pData = (u16(*)[3])gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pFrame;
    offset = pData[gCurrentSprite.roomSlot][0];
    
    if (gCurrentSprite.pOam != sMechaRidleyFrameDataPointers[offset])
    {
        gCurrentSprite.pOam = sMechaRidleyFrameDataPointers[offset];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][1];
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][2];
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

/**
 * @brief 4bb88 | a4 | Loads the fireball graphics
 * 
 */
void MechaRidleyLoadFireballsGfx(void)
{
    u8 stage;

    // Check has no missiles, and at least a fireball active
    if (gBossWork.work6 == 0 && gBossWork.work8 != 0)
    {
        gCurrentSprite.workVariable2++;
        gCurrentSprite.arrayOffset++;

        if (gCurrentSprite.arrayOffset > 3)
            gCurrentSprite.arrayOffset = 0;

        stage = gCurrentSprite.arrayOffset;

        // Load graphics
        dma_set(3, &sMechaRidleyWeaponsGfx[3 * 32 +stage * 32], VRAM_BASE + 0x14280, (DMA_ENABLE << 16) | 64);
        dma_set(3, &sMechaRidleyWeaponsGfx[11 * 32 + stage * 32], VRAM_BASE + 0x14680, (DMA_ENABLE << 16) | 64);
        dma_set(3, &sMechaRidleyWeaponsGfx[19 * 32 + stage * 32], VRAM_BASE + 0x14A80, (DMA_ENABLE << 16) | 64);
        dma_set(3, &sMechaRidleyWeaponsGfx[27 * 32 + stage * 32], VRAM_BASE + 0x14E80, (DMA_ENABLE << 16) | 64);
    }
}

/**
 * @brief 4bc2c | a4 | Loads the missile graphics
 * 
 */
void MechaRidleyLoadMissilesGfx(void)
{
    u8 stage;

    // Check has no firebals, and at least a missile active
    if (gBossWork.work8 == 0 && gBossWork.work6 != 0)
    {
        gCurrentSprite.workVariable2++;
        gCurrentSprite.arrayOffset++;

        if (gCurrentSprite.arrayOffset > 2)
            gCurrentSprite.arrayOffset = 0;

        stage = gCurrentSprite.arrayOffset;

        // Load graphics
        dma_set(3, &sMechaRidleyWeaponsGfx[stage * 32], VRAM_BASE + 0x14280, (DMA_ENABLE << 16) | 64);
        dma_set(3, &sMechaRidleyWeaponsGfx[8 * 32 + stage * 32], VRAM_BASE + 0x14680, (DMA_ENABLE << 16) | 64);
        dma_set(3, &sMechaRidleyWeaponsGfx[16 * 32 + stage * 32], VRAM_BASE + 0x14A80, (DMA_ENABLE << 16) | 64);
        dma_set(3, &sMechaRidleyWeaponsGfx[24 * 32 + stage * 32], VRAM_BASE + 0x14E80, (DMA_ENABLE << 16) | 64);
    }
}

/**
 * @brief 4bcd0 | 128 | 
 * 
 * @return u8 1 if changing height, 0 otherwise
 */
u8 MechaRidleyUpdateHeight(void)
{
    u8 changing;

    changing = FALSE;

    // Check update height
    if (gSubSpriteData1.pMultiOam == sMechaRidleyMultiSpriteData_StandingLow)
    {
        // Low height
        if (gBossWork.work3 == MECHA_RIDLEY_SAMUS_POSITION_MIDDLE)
        {
            // Low to middle
            gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_LowToMiddle;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
            changing = TRUE;
        }
        else if (gBossWork.work3 == MECHA_RIDLEY_SAMUS_POSITION_HIGH)
        {
            // Low to high
            gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_LowToHigh;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
            changing = TRUE;
        }
    }
    else if (gSubSpriteData1.pMultiOam == sMechaRidleyMultiSpriteData_StandingMiddle)
    {
        // Middle height
        if (gBossWork.work3 == MECHA_RIDLEY_SAMUS_POSITION_HIGH)
        {
            // Middle to high
            gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_MiddleToHigh;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
            changing = TRUE;
        }
        else if (SpriteUtilCheckEndSubSprite1Anim() && gBossWork.work3 == MECHA_RIDLEY_SAMUS_POSITION_LOW)
        {
            // Middle to low
            gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_MiddleToLow;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
            changing = TRUE;
        }
    }
    else if (gSubSpriteData1.pMultiOam == sMechaRidleyMultiSpriteData_StandingHigh)
    {
        // High height
        if (SpriteUtilCheckEndSubSprite1Anim())
        {
            if (gBossWork.work3 == MECHA_RIDLEY_SAMUS_POSITION_LOW)
            {
                // High to low
                gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_HighToLow;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
                changing = TRUE;
            }
            else if (gBossWork.work3 == MECHA_RIDLEY_SAMUS_POSITION_MIDDLE)
            {
                // High to middle
                gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_HighToMiddle;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
                changing = TRUE;
            }
        }
    }
    else if (SpriteUtilCheckEndSubSprite1Anim())
    {
        // Set new height
        if (gSubSpriteData1.pMultiOam == sMechaRidleyMultiSpriteData_LowToMiddle)
            gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_StandingMiddle;
        else if (gSubSpriteData1.pMultiOam == sMechaRidleyMultiSpriteData_MiddleToHigh)
            gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_StandingHigh;
        else if (gSubSpriteData1.pMultiOam == sMechaRidleyMultiSpriteData_HighToMiddle)
            gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_StandingMiddle;
        else if (gSubSpriteData1.pMultiOam == sMechaRidleyMultiSpriteData_MiddleToLow)
            gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_StandingLow;
        else if (gSubSpriteData1.pMultiOam == sMechaRidleyMultiSpriteData_LowToHigh)
            gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_StandingHigh;
        else if (gSubSpriteData1.pMultiOam == sMechaRidleyMultiSpriteData_HighToLow)
            gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_StandingLow;

        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
    }
    else
        changing = TRUE;

    return changing;
}

/**
 * @brief 4bdf8 | bc | Initializes mecha ridley to be crawling back
 * 
 * @param leftArmSlot Left arm RAM slot
 */
void MechaRidleyCrawlingBackwardsInit(u8 leftArmSlot)
{
    u8 rightArmSlot;

    rightArmSlot = gSubSpriteData1.workVariable4;
    gBossWork.work7 = gSubSpriteData1.health;

    // Check current standing height
    if (gSubSpriteData1.pMultiOam == sMechaRidleyMultiSpriteData_StandingLow)
    {
        // Low, start crawling backwards
        gSpriteData[rightArmSlot].pOam = sMechaRidleyPartOAM_RightArmCrawlingBackwards;
        gSpriteData[rightArmSlot].animationDurationCounter = 0;
        gSpriteData[rightArmSlot].currentAnimationFrame = 0;

        gSpriteData[leftArmSlot].pOam = sMechaRidleyPartOAM_LeftArmCrawlingBackwards;
        gSpriteData[leftArmSlot].animationDurationCounter = 0;
        gSpriteData[leftArmSlot].currentAnimationFrame = 0;

        gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_CrawlingBackwardsLow;
        gCurrentSprite.pose = MECHA_RIDLEY_POSE_CRAWLING_BACKWARDS;
    }
    else if (gSubSpriteData1.pMultiOam == sMechaRidleyMultiSpriteData_StandingMiddle)
    {
        // Middle, set retracting to low
        gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_MiddleToLow;
        gCurrentSprite.pose = MECHA_RIDLEY_POSE_RETRACTING;
    }
    else if (gSubSpriteData1.pMultiOam == sMechaRidleyMultiSpriteData_StandingHigh)
    {
        // High, set retracting to low
        gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_HighToLow;
        gCurrentSprite.pose = MECHA_RIDLEY_POSE_RETRACTING;
    }

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
}

/**
 * @brief 4beb4 | b4 | Initializes mecha ridley to do the swinging attack
 * 
 * @param leftArmSlot Left arm RAM slot
 */
void MechaRidleyClawAttackInit(u8 leftArmSlot)
{
    // Check set height change animation
    if (gSubSpriteData1.pMultiOam == sMechaRidleyMultiSpriteData_StandingMiddle)
    {
        gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_MiddleToHigh;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        gCurrentSprite.timer = 6;
    }
    else if (gSubSpriteData1.pMultiOam == sMechaRidleyMultiSpriteData_StandingLow)
    {
        gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_LowToHigh;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        gCurrentSprite.timer = 12;
    }
    else
        gCurrentSprite.timer = 0;

    // Set left arm oam
    gSpriteData[leftArmSlot].pOam = sMechaRidleyPartOAM_LeftArmSwingingAtCloseGround;
    gSpriteData[leftArmSlot].animationDurationCounter = 0;
    gSpriteData[leftArmSlot].currentAnimationFrame = 0;

    gCurrentSprite.pose = MECHA_RIDLEY_POSE_CLAW_ATTACK;
    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
    gBossWork.work4 = EYE_STATE_BLINKING_INIT;
}

/**
 * @brief 4bf68 | 230 | Initializes Mecha ridley
 * 
 */
void MechaRidleyInit(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MECHA_RIDLEY_KILLED))
        gCurrentSprite.status = 0;
    else
    {
        TransparencyUpdateBLDCNT(1,
            BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL |
            BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG3_SECOND_TARGET_PIXEL |
            BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL);

        TransparencySpriteUpdateBLDALPHA(10, 0, 0, 16);

        gCurrentSprite.xPosition += BLOCK_SIZE;

        // Initialize work variables
        gBossWork.work1 = gCurrentSprite.yPosition;
        gBossWork.work2 = gCurrentSprite.xPosition;

        gBossWork.work3 = 0;
        gBossWork.work4 = 0;
        gBossWork.work5 = 0;
        gBossWork.work6 = 0;
        gBossWork.work7 = 0;
        gBossWork.work8 = 0;
        gBossWork.work9 = 0;
        gBossWork.work10 = 0;

        gBossWork.work11 = SpriteUtilGetFinalCompletionPercentage();

        // Offset to the right
        gCurrentSprite.xPosition += BLOCK_SIZE * 11;
        gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

        yPosition = gSubSpriteData1.yPosition;
        xPosition = gSubSpriteData1.xPosition;

        gCurrentSprite.drawDistanceTopOffset = 8;
        gCurrentSprite.drawDistanceBottomOffset = 8;
        gCurrentSprite.drawDistanceHorizontalOffset = 8;

        gCurrentSprite.hitboxTopOffset = -HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxBottomOffset = HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxLeftOffset = -HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxRightOffset = HALF_BLOCK_SIZE;

        gCurrentSprite.frozenPaletteRowOffset = 5;
        gCurrentSprite.drawOrder = 10;
        gCurrentSprite.samusCollision = SSC_NONE;

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);

        // Triple health if 100% items
        if (gBossWork.work11 == 100)
            gCurrentSprite.health *= 3;

        gBossWork.work9 = gCurrentSprite.health;

        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        // Set delay before crawling
        gCurrentSprite.yPositionSpawn = 60 * 5;
        gCurrentSprite.arrayOffset = gSpriteRNG;
        gCurrentSprite.oamRotation = 0;

        // Set crawling
        gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_CrawlingForwardLow;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gSubSpriteData1.workVariable2 = 0;
        gSubSpriteData1.workVariable3 = 0;

        gDoorUnlockTimer = 1;
        gCurrentSprite.pose = MECHA_RIDLEY_POSE_CRAWLING_INIT;
        gCurrentSprite.roomSlot = MECHA_RIDLEY_PART_CORE;

        gfxSlot = gCurrentSprite.spritesetGfxSlot;
        ramSlot = gCurrentSprite.primarySpriteRamSlot;

        // Spawn every part
        gSubSpriteData1.workVariable4 = SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_PART, MECHA_RIDLEY_PART_RIGHT_ARM,
            gfxSlot, ramSlot, yPosition, xPosition, 0);

        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_PART, MECHA_RIDLEY_PART_EYE,
            gfxSlot, ramSlot, yPosition, xPosition, 0);

        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_PART, MECHA_RIDLEY_PART_HEAD,
            gfxSlot, ramSlot, yPosition, xPosition, 0);

        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_PART, MECHA_RIDLEY_PART_NECK,
            gfxSlot, ramSlot, yPosition, xPosition, 0);

        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_PART, MECHA_RIDLEY_PART_COVER,
            gfxSlot, ramSlot, yPosition, xPosition, 0);

        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_PART, MECHA_RIDLEY_PART_TORSO,
            gfxSlot, ramSlot, yPosition, xPosition, 0);

        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_PART, MECHA_RIDLEY_PART_WAISTBAND,
            gfxSlot, ramSlot, yPosition, xPosition, 0);

        gSubSpriteData1.workVariable5 = SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_PART, MECHA_RIDLEY_PART_LEFT_ARM,
            gfxSlot, ramSlot, yPosition, xPosition, 0);

        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_PART, MECHA_RIDLEY_PART_TAIL,
            gfxSlot, ramSlot, yPosition, xPosition, 0);

        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_PART, MECHA_RIDLEY_PART_MISSILE_LAUNCHER,
            gfxSlot, ramSlot, yPosition, xPosition, 0);

    }
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
    if (gCurrentSprite.yPositionSpawn == 0)
        gCurrentSprite.pose = MECHA_RIDLEY_POSE_CRAWLING;
}

/**
 * @brief 4c200 | a4 | Handles mecha ridley crawling at the beginning of the fight
 * 
 */
void MechaRidleyCrawling(void)
{
    u8 rightArmSlot;
    u8 leftArmSlot;

    rightArmSlot = gSubSpriteData1.workVariable4;
    leftArmSlot = gSubSpriteData1.workVariable5;

    if (gSubSpriteData1.xPosition <= gBossWork.work2)
    {
        // Reached spawn position
        gSubSpriteData1.xPosition = gBossWork.work2;
        if (SpriteUtilCheckEndSubSprite1Anim())
        {
            // Finished crawling, set idle
            gCurrentSprite.pose = MECHA_RIDLEY_POSE_DELAY_BEFORE_IDLE;

            gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_StandingLow,
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;

            gCurrentSprite.timer = 0;

            // Timer before the battle actually starts (music/fade)
            gCurrentSprite.workVariable = 32;
            gBossWork.work4 = EYE_STATE_BLINKING_INIT;
        }
    }
    else
    {
        // Move based on animation
        switch (gSpriteData[rightArmSlot].currentAnimationFrame)
        {
            case 6:
                gSubSpriteData1.xPosition -= 4;
                break;

            case 7:
                gSubSpriteData1.xPosition -= 2;
                break;
        }

        switch (gSpriteData[leftArmSlot].currentAnimationFrame)
        {
            case 0:
                gSubSpriteData1.xPosition -= 4;
                break;

            case 1:
                gSubSpriteData1.xPosition -= 2;
                break;
        }
    }
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

            // Start music
            PlayMusic(MUSIC_MECHA_RIDLEY_BATTLE, 0);

            // Enable alarm
            gDisableAnimatedPalette = FALSE;
        }
        else
        {
            if (palRow == 1)
                SoundPlay(0x2AD);

            // Palette fading
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
            MechaRidleyClawAttackInit(ramSlot); // Start claw attack
        else
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;

            if (gSubSpriteData1.workVariable3 == HEALTH_THRESHOLD_COVER_DAMAGED && gBossWork.work6 == 0)
            {
                if (gBossWork.work5 == MISSILE_LAUNCHER_STATE_IDLE && gEquipment.currentMissiles + gEquipment.currentSuperMissiles != 0)
                {
                    // Start fireball attack
                    gCurrentSprite.pose = MECHA_RIDLEY_POSE_STANDING_FOR_FIREBALL_ATTACK_INIT;
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
    u8 leftArmSlot;

    leftArmSlot = gSubSpriteData1.workVariable5;

    //   Update height          Check trigger attacks (excluding fireballs for graphics conflits)     Check timer
    if ((MechaRidleyUpdateHeight() || !MechaRidleyCheckStartFireballAttack(leftArmSlot)) && gSubSpriteData1.workVariable2 == 170)
        gBossWork.work5 = MISSILE_LAUNCHER_STATE_MISSILE_ATTACK_INIT; // Start missile attack
}

/**
 * @brief 4c400 | 12c | Handles the claw attack
 * 
 */
void MechaRidleyClawAttack(void)
{
    u8 leftArmSlot;
    u16 coreSpawnHealth;

    coreSpawnHealth = gBossWork.work9;

    // Check standing timer
    if (gCurrentSprite.timer != 0)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0)
        {
            // Set standing high
            gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_StandingHigh;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
        }
    }

    leftArmSlot = gSubSpriteData1.workVariable5;

    // Check is doing the attack from the back
    if (gSubSpriteData1.xPosition > gBossWork.work2 - BLOCK_SIZE)
    {
        // Move/play sound based on the arm animation
        if ((u16)(gSpriteData[leftArmSlot].currentAnimationFrame - 4) < 4)
        {
            if (gSpriteData[leftArmSlot].currentAnimationFrame == 4 && gSpriteData[leftArmSlot].animationDurationCounter == 1)
                SoundPlay(0x29E);

            gSubSpriteData1.xPosition -= 4;
        }
    }

    if (SpriteUtilCheckEndSpriteAnim(leftArmSlot))
    {
        // Set forward position
        gSubSpriteData1.xPosition = gBossWork.work2 - BLOCK_SIZE;

        gSpriteData[leftArmSlot].pOam = sMechaRidleyPartOAM_LeftArmTrembling;
        gSpriteData[leftArmSlot].animationDurationCounter = 0;
        gSpriteData[leftArmSlot].currentAnimationFrame = 0;

        // Set delay for before mecha raises his arm
        if (gSubSpriteData1.workVariable3 >= HEALTH_THRESHOLD_COVER_BROKEN)
        {
            if (gSubSpriteData1.health < coreSpawnHealth / 2)
                gCurrentSprite.timer = 40;
            else if (gSubSpriteData1.health < coreSpawnHealth * 3 / 4)
                gCurrentSprite.timer = 80;
            else
                gCurrentSprite.timer = 120;
        }
        else
            gCurrentSprite.timer = 160;

        gCurrentSprite.pose = MECHA_RIDLEY_POSE_STANDING_UP;
        gBossWork.work7 = gSubSpriteData1.health;
    }
}

/**
 * @brief 4c52c | b0 | Handles mecha ridley standing up
 * 
 */
void MechaRidleyStandingUp(void)
{
    u8 leftArmSlot;

    leftArmSlot = gSubSpriteData1.workVariable5;

    // Delay before raising arm
    if (gCurrentSprite.timer != 0)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0)
        {
            // Raise arm
            gSpriteData[leftArmSlot].pOam = sMechaRidleyPartOAM_LeftArmHoldingUp;
            gSpriteData[leftArmSlot].animationDurationCounter = 0;
            gSpriteData[leftArmSlot].currentAnimationFrame = 0;
        }
    }
    else
    {
        if (SpriteUtilCheckEndSpriteAnim(leftArmSlot))
        {
            // Set curled up
            gSpriteData[leftArmSlot].pOam = sMechaRidleyPartOAM_LeftArmHeldUp;
            gSpriteData[leftArmSlot].animationDurationCounter = 0;
            gSpriteData[leftArmSlot].currentAnimationFrame = 0;

            gCurrentSprite.pose = MECHA_RIDLEY_POSE_CURLED_UP;
        }

        // Check retreat (not moving, took damage)
        if (!MechaRidleyUpdateHeight() && gBossWork.work7 > gSubSpriteData1.health)
            MechaRidleyCrawlingBackwardsInit(leftArmSlot);
    }
}

/**
 * @brief 4c5dc | 54 | Handles mecha ridley being curled up
 * 
 */
void MechaRidleyCurledUp(void)
{
    u8 leftArmSlot;

    leftArmSlot = gSubSpriteData1.workVariable5;

    if (!MechaRidleyUpdateHeight())
    {
        if (gBossWork.work7 > gSubSpriteData1.health)
            MechaRidleyCrawlingBackwardsInit(leftArmSlot); // Retreat if took damage
        else if (MechaRidleyCheckStartFireballAttack(leftArmSlot)) // Check attacks
            return; // Don't check for missile attack if fireball attack started (Gfx conflict)
    }

    // Check missile attack timer
    if (gSubSpriteData1.workVariable2 == 170)
        gBossWork.work5 = MISSILE_LAUNCHER_STATE_MISSILE_ATTACK_INIT;
}

/**
 * @brief 4c630 | 78 | Handles mecha ridley retracting
 * 
 */
void MechaRidleyRetracting(void)
{
    u8 rightArmSlot;
    u8 leftArmSlot;

    rightArmSlot = gSubSpriteData1.workVariable4;
    leftArmSlot = gSubSpriteData1.workVariable5;

    if (SpriteUtilCheckEndSubSprite1Anim())
    {
        // Set crawling backwards
        gSpriteData[rightArmSlot].pOam = sMechaRidleyPartOAM_RightArmCrawlingBackwards;
        gSpriteData[rightArmSlot].animationDurationCounter = 0;
        gSpriteData[rightArmSlot].currentAnimationFrame = 0;

        gSpriteData[leftArmSlot].pOam = sMechaRidleyPartOAM_LeftArmCrawlingBackwards;
        gSpriteData[leftArmSlot].animationDurationCounter = 0;
        gSpriteData[leftArmSlot].currentAnimationFrame = 0;

        gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_CrawlingBackwardsLow;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        gCurrentSprite.pose = MECHA_RIDLEY_POSE_CRAWLING_BACKWARDS;
        SoundPlay(0x29F);
    }
}

/**
 * @brief 4c6a8 | 90 | Handles mecha ridley crawling backwards
 * 
 */
void MechaRidleyCrawlingBack(void)
{
    u8 rightArmSlot;
    u8 leftArmSlot;

    rightArmSlot = gSubSpriteData1.workVariable4;
    leftArmSlot = gSubSpriteData1.workVariable5;

    if (gSubSpriteData1.xPosition < gBossWork.work2)
        gSubSpriteData1.xPosition++; // Move
    else
    {
        // Set back position
        gSubSpriteData1.xPosition = gBossWork.work2;

        if (SpriteUtilCheckEndSubSprite1Anim())
        {
            // Set standing
            gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_StandingLow;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;

            gCurrentSprite.pose = MECHA_RIDLEY_POSE_IDLE;

            // Set right arm trembling
            gSpriteData[rightArmSlot].pOam = sMechaRidleyPartOAM_RightArmTrembling;
            gSpriteData[rightArmSlot].animationDurationCounter = 0;
            gSpriteData[rightArmSlot].currentAnimationFrame = 0;

            // Set left arm raised
            gSpriteData[leftArmSlot].pOam = sMechaRidleyPartOAM_LeftArmHeldUp;
            gSpriteData[leftArmSlot].animationDurationCounter = 0;
            gSpriteData[leftArmSlot].currentAnimationFrame = 0;
        }
    }
}

/**
 * @brief 4c738 | 4c | Initializes mecha ridley standing up for the fireballs attack
 * 
 */
void MechaRidleyStandingForFireballsInit(void)
{
    // Check set height change animation to be high
    if (gSubSpriteData1.pMultiOam == sMechaRidleyMultiSpriteData_StandingMiddle)
    {
        gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_MiddleToHigh;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
    }

    if (gSubSpriteData1.pMultiOam == sMechaRidleyMultiSpriteData_StandingLow)
    {
        gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_LowToHigh;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
    }

    gCurrentSprite.pose = MECHA_RIDLEY_POSE_STANDING_FOR_FIREBALL_ATTACK;
}

/**
 * @brief 4c784 | 38 | Handles mecha ridley standing up for the fireballs attack
 * 
 */
void MechaRidleyStandingForFireballs(void)
{
    if (SpriteUtilCheckEndSubSprite1Anim())
    {
        // Set opening mouth
        gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_OpeningMouthHigh;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        gCurrentSprite.pose = MECHA_RIDLEY_POSE_OPENING_MOUTH;
        SoundPlay(0x2A8);
    }
}

/**
 * @brief 4c7bc | 38 | Handles mecha ridley opening its mouth for the fireballs attack
 * 
 */
void MechaRidleyCheckOpeningMouthAnimEnded(void)
{
    if (SpriteUtilCheckEndSubSprite1Anim())
    {
        // Set spitting fireballs
        gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_SpittingFireballsHigh;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        // Fireball attack duration timer
        gCurrentSprite.timer = 128;
        gCurrentSprite.pose = MECHA_RIDLEY_POSE_FIREBALL_ATTACK;
    }
}

/**
 * @brief 4c7f4 | bc | Handles mecha ridley spitting fireballs
 * 
 */
void MechaRidleyFireballsAttack(void)
{
    // Spawn fireball every 15 frames
    if (!(gCurrentSprite.timer & 15))
    {
        // Alternate between low and high fireball
        if (gCurrentSprite.timer & 16)
        {
            SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_FIREBALL, FIREBALL_LOW, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition - BLOCK_SIZE * 4,
                gSubSpriteData1.xPosition - BLOCK_SIZE, 0);
        }
        else
        {
            SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_FIREBALL, FIREBALL_HIGH, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition - BLOCK_SIZE * 4,
                gSubSpriteData1.xPosition - BLOCK_SIZE, 0);
        }

        SoundPlay(0x2A9);
    }

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0)
    {
        // End attack, set closing mouth
        gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_ClosingMouthHigh;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        gCurrentSprite.pose = MECHA_RIDLEY_POSE_CLOSING_MOUTH;
    }
}

/**
 * @brief 4c8b0 | 30 | Handles mecha ridley closing its mouth after the fireballs attack
 * 
 */
void MechaRidleyCheckClosingMouthAnimEnded(void)
{
    if (SpriteUtilCheckEndSubSprite1Anim())
    {
        // Set going low
        gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_HighToLow;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        gCurrentSprite.pose = MECHA_RIDLEY_POSE_RETRACTING_AFTER_FIREBALL_ATTACK;
    }
}

/**
 * @brief 4c8e0 | 4c | Handles mecha ridley retracting after the fireballs attack 
 * 
 */
void MechaRidleyRetractingAfterFireballAttack(void)
{
    if (SpriteUtilCheckEndSubSprite1Anim())
    {
        // Set standing low
        gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_StandingLow;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        if (gSubSpriteData1.xPosition == gBossWork.work2 - BLOCK_SIZE)
            gCurrentSprite.pose = MECHA_RIDLEY_POSE_CURLED_UP; // In front
        else
            gCurrentSprite.pose = MECHA_RIDLEY_POSE_IDLE; // In the back
    }
}

/**
 * @brief 4c92c | 68 | Initializes mecha ridley to be dying
 * 
 */
void MechaRidleyDyingInit(void)
{
    // Set dying standing low
    gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_DyingStandingLow;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.invincibilityStunFlashTimer = 60;
    gCurrentSprite.health = 1;
    gCurrentSprite.pose = MECHA_RIDLEY_POSE_DYING_STANDING_UP;

    gBossWork.work4 = EYE_STATE_LASER_SET_IDLE;

    ParticleSet(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition, PE_MAIN_BOSS_DEATH);
    SoundPlay(0x2B0);
    FadeMusic(60);
}

/**
 * @brief 4c994 | 9c | Handles mecha ridley dying
 * 
 */
void MechaRidleyDying(void)
{
    u8 rng;
    u32 offset;
    u32 yPosition;
    
    rng = gSpriteRNG * 2;

    if (gCurrentSprite.invincibilityStunFlashTimer != 0)
    {
        // Spawn random particles
        if (!(gCurrentSprite.invincibilityStunFlashTimer & 15))
        {
            if (gCurrentSprite.invincibilityStunFlashTimer & 16)
            {
                yPosition = gCurrentSprite.yPosition;
                offset = rng - BLOCK_SIZE;
                ParticleSet(yPosition - offset, gCurrentSprite.xPosition + rng, PE_MAIN_BOSS_DEATH);
            }
            else
            {
                offset = rng + BLOCK_SIZE;
                ParticleSet(gCurrentSprite.yPosition + offset, gCurrentSprite.xPosition - rng, PE_MAIN_BOSS_DEATH);
            }
        }
    }
    else
    {
        // Set dying animation
        gSubSpriteData1.pMultiOam = sMechaRidleyMultiSpriteData_Dying;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        gCurrentSprite.pose = MECHA_RIDLEY_POSE_DYING_GLOW_FADING;
        gCurrentSprite.timer = 0;

        SoundPlay(0x2AE);

        // Disable alarm
        gDisableAnimatedPalette = -1;
    }
}

/**
 * @brief 4ca30 | 1a8 | Handles mecha ridley fading when dying
 * 
 */
void MechaRidleyGlowFading(void)
{
    // Set destroyed graphics
    switch (gCurrentSprite.timer++)
    {
        case 0:
            dma_set(3, sMechaRidleyDestroyedGfx, VRAM_BASE + 0x15580, (DMA_ENABLE << 16) | 0x40);
            break;

        case 1:
            dma_set(3, &sMechaRidleyDestroyedGfx[0x30], VRAM_BASE + 0x15980, (DMA_ENABLE << 16) | 0x60);
            break;

        case 2:
            dma_set(3, &sMechaRidleyDestroyedGfx[0x60], VRAM_BASE + 0x15D80, (DMA_ENABLE << 16) | 0x60);
            break;

        case 3:
            dma_set(3, &sMechaRidleyDestroyedGfx[0x90], VRAM_BASE + 0x16180, (DMA_ENABLE << 16) | 0x60);
            break;

        case 4:
            dma_set(3, &sMechaRidleyDestroyedGfx[0xC0], VRAM_BASE + 0x16580, (DMA_ENABLE << 16) | 0x60);
            break;

        case 5:
            dma_set(3, &sMechaRidleyDestroyedGfx[0x100], VRAM_BASE + 0x169C0, (DMA_ENABLE << 16) | 0x40);
            break;

        case 6:
            dma_set(3, &sMechaRidleyDestroyedGfx[0x130], VRAM_BASE + 0x16DC0, (DMA_ENABLE << 16) | 0x40);
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

/**
 * @brief 4cbd8 | 244 | Handles the spawn of the energy drops
 * 
 */
void MechaRidleySpawnDrops(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 partNumber;
    u8 rngParam1;
    u8 rngParam2;
    u8 spriteID;

    yPosition = gCurrentSprite.yPosition - (BLOCK_SIZE + 0x24);
    xPosition = gCurrentSprite.xPosition - BLOCK_SIZE * 6;

    partNumber = gSpriteRNG;
    rngParam1 = gSpriteRNG * 8;
    partNumber &= 3;
    rngParam2 = (gCurrentSprite.timer & 15) * 8;
    spriteID = PSPRITE_MULTIPLE_LARGE_ENERGY;
    gCurrentSprite.timer++;

    // Update palette and spawn drops (10 in total)
    switch (gCurrentSprite.yPositionSpawn++)
    {
        case 1:
            dma_set(3, sMechaRidley_8323aaa_PAL, PALRAM_BASE + 0x322, (DMA_ENABLE << 16) | 6);
            break;

        case 6:
            dma_set(3, &sMechaRidleyGreenGlowPAL[4], PALRAM_BASE + 0x322, (DMA_ENABLE << 16) | 6);
            break;

        case 12:
            dma_set(3, &sMechaRidleyGreenGlowPAL[20], PALRAM_BASE + 0x322, (DMA_ENABLE << 16) | 6);
            break;

        case 30:
            SpriteSpawnDropFollowers(spriteID, partNumber, 0, gCurrentSprite.primarySpriteRamSlot,
                yPosition + rngParam1, xPosition - rngParam2, 0);
            break;

        case 31:
            SpriteSpawnDropFollowers(spriteID, partNumber, 0, gCurrentSprite.primarySpriteRamSlot,
                yPosition - rngParam1, xPosition + rngParam2, 0);
            break;

        case 33:
            SpriteSpawnDropFollowers(spriteID, partNumber, 0, gCurrentSprite.primarySpriteRamSlot,
                yPosition - rngParam1 + rngParam2 * 2, xPosition + rngParam2 + rngParam1, 0);
            break;

        case 35:
            SpriteSpawnDropFollowers(spriteID, partNumber, 0, gCurrentSprite.primarySpriteRamSlot,
                yPosition - rngParam1 + rngParam2 * 2, xPosition + rngParam2 + rngParam1, 0);
            break;

        case 37:
            SpriteSpawnDropFollowers(spriteID, partNumber, 0, gCurrentSprite.primarySpriteRamSlot,
                yPosition - rngParam1 + rngParam2 * 2, xPosition + rngParam2 + rngParam1, 0);
            break;

        case 32:
        case 34:
        case 36:
        case 38:
            SpriteSpawnDropFollowers(spriteID, partNumber, 0, gCurrentSprite.primarySpriteRamSlot,
                yPosition + rngParam1 - rngParam2 * 2, xPosition - rngParam2 - rngParam1, 0);
            break;

        case 39:
            SpriteSpawnDropFollowers(spriteID, partNumber, 0, gCurrentSprite.primarySpriteRamSlot,
                yPosition - rngParam1 + rngParam2 * 2, xPosition + rngParam2 + rngParam1, 0);
            break;
    }

    if (gCurrentSprite.yPositionSpawn > 60 * 6)
    {
        // Set first eye glow
        gCurrentSprite.timer = 30;
        gCurrentSprite.workVariable = 0;
        gCurrentSprite.workVariable2 = 4;
        gCurrentSprite.pose = MECHA_RIDLEY_POSE_FIRST_EYE_GLOW;
    }
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

        // Update palette
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
        // Set second eye glow
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

        // Update palette
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
            // Set event
            EventFunction(EVENT_ACTION_SETTING, EVENT_MECHA_RIDLEY_KILLED);
            
            // Start escape
            SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_CHOZODIA_ESCAPE, 0, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

            // Save IGT
            gInGameTimerAtBosses[3] = gInGameTimer;
            
            // Unlock doors
            gDoorUnlockTimer = -20;

            // Enable alarm
            gDisableAnimatedPalette = FALSE;

            PlayMusic(MUSIC_ESCAPE, 0x40);
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
    gCurrentSprite.pose = MECHA_RIDLEY_PART_IDLE;
    gCurrentSprite.samusCollision = SSC_MECHA_RIDLEY;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    switch (gCurrentSprite.roomSlot)
    {
        case MECHA_RIDLEY_PART_RIGHT_ARM:
            gCurrentSprite.drawDistanceTopOffset = 0x18;
            gCurrentSprite.drawDistanceBottomOffset = 0x38;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x58;

            gCurrentSprite.hitboxTopOffset = -4;
            gCurrentSprite.hitboxBottomOffset = 4;
            gCurrentSprite.hitboxLeftOffset = -4;
            gCurrentSprite.hitboxRightOffset = 4;

            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.pose = MECHA_RIDLEY_PART_POSE_RIGHT_ARM_IDLE;
            break;

        case MECHA_RIDLEY_PART_LEFT_ARM:
            gCurrentSprite.drawDistanceTopOffset = 0x50;
            gCurrentSprite.drawDistanceBottomOffset = 0x38;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x70;

            gCurrentSprite.hitboxTopOffset = -4;
            gCurrentSprite.hitboxBottomOffset = 4;
            gCurrentSprite.hitboxLeftOffset = -4;
            gCurrentSprite.hitboxRightOffset = 4;

            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.drawOrder = 0xD;
            gCurrentSprite.pose = MECHA_RIDLEY_PART_POSE_LEFT_ARM_IDLE;
            break;

        case MECHA_RIDLEY_PART_EYE:
            gCurrentSprite.drawDistanceTopOffset = 8;
            gCurrentSprite.drawDistanceBottomOffset = 8;
            gCurrentSprite.drawDistanceHorizontalOffset = 8;

            gCurrentSprite.hitboxTopOffset = 0;
            gCurrentSprite.hitboxBottomOffset = 0;
            gCurrentSprite.hitboxLeftOffset = 0;
            gCurrentSprite.hitboxRightOffset = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x4;
            gCurrentSprite.pose = MECHA_RIDLEY_PART_POSE_EYE_IDLE;
            gCurrentSprite.frozenPaletteRowOffset = 0x1;
            break;

        case MECHA_RIDLEY_PART_HEAD:
            gCurrentSprite.drawDistanceTopOffset = 0x28;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x38;

            gCurrentSprite.hitboxTopOffset = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottomOffset = (BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxLeftOffset = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRightOffset = HALF_BLOCK_SIZE;

            gCurrentSprite.health = 0x1;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pose = MECHA_RIDLEY_PART_POSE_HEAD_IDLE;

            gCurrentSprite.timer = 0;
            gCurrentSprite.workVariable = 0;
            gCurrentSprite.workVariable2 = 0;
            gCurrentSprite.arrayOffset = 0;
            break;

        case MECHA_RIDLEY_PART_NECK:
            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.drawDistanceBottomOffset = 0x20;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x40;

            gCurrentSprite.hitboxTopOffset = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxBottomOffset = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeftOffset = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRightOffset = HALF_BLOCK_SIZE;

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
            gCurrentSprite.hitboxBottomOffset = BLOCK_SIZE - QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxLeftOffset = -(BLOCK_SIZE - QUARTER_BLOCK_SIZE);
            gCurrentSprite.hitboxRightOffset = BLOCK_SIZE;

            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteID);

            // Triple health if 100% items
            if (gBossWork.work11 == 100)
                gCurrentSprite.health *= 3;

            gBossWork.work10 = gCurrentSprite.health;
            gSubSpriteData1.health = gCurrentSprite.health;
            gBossWork.work7 = gCurrentSprite.health;

            gCurrentSprite.drawOrder = 9;
            gCurrentSprite.pose = MECHA_RIDLEY_PART_POSE_COVER_IDLE;
            break;

        case MECHA_RIDLEY_PART_TORSO:
            gCurrentSprite.drawDistanceTopOffset = 0x28;
            gCurrentSprite.drawDistanceBottomOffset = 0x18;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            gCurrentSprite.hitboxTopOffset = -BLOCK_SIZE;
            gCurrentSprite.hitboxBottomOffset = BLOCK_SIZE;
            gCurrentSprite.hitboxLeftOffset = -QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRightOffset = BLOCK_SIZE;

            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.drawOrder = 11;
            break;

        case MECHA_RIDLEY_PART_WAISTBAND:
            gCurrentSprite.drawDistanceTopOffset = 0x18;
            gCurrentSprite.drawDistanceBottomOffset = 0x18;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            gCurrentSprite.hitboxTopOffset = -BLOCK_SIZE;
            gCurrentSprite.hitboxBottomOffset = BLOCK_SIZE;
            gCurrentSprite.hitboxLeftOffset = -BLOCK_SIZE;
            gCurrentSprite.hitboxRightOffset = BLOCK_SIZE;

            gCurrentSprite.health = 1;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.drawOrder = 12;
            break;

        case MECHA_RIDLEY_PART_TAIL:
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x30;

            gCurrentSprite.hitboxTopOffset = -BLOCK_SIZE;
            gCurrentSprite.hitboxBottomOffset = BLOCK_SIZE;
            gCurrentSprite.hitboxLeftOffset = -(BLOCK_SIZE * 3);
            gCurrentSprite.hitboxRightOffset = BLOCK_SIZE * 3;

            gCurrentSprite.health = 1;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.drawOrder = 14;
            break;

        case MECHA_RIDLEY_PART_MISSILE_LAUNCHER:
            gCurrentSprite.drawDistanceTopOffset = 0x20;
            gCurrentSprite.drawDistanceBottomOffset = 0x20;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

            gCurrentSprite.hitboxTopOffset = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottomOffset = BLOCK_SIZE + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeftOffset = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxRightOffset = BLOCK_SIZE + HALF_BLOCK_SIZE;

            gCurrentSprite.health = 1;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.drawOrder = 14;

            gCurrentSprite.workVariable2 = 0;
            gCurrentSprite.arrayOffset = 0;
            gCurrentSprite.pose = MECHA_RIDLEY_PART_POSE_MISSILE_LAUNCHER_IDLE;
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 4d2e0 | 10 | Handles the head part being idle
 * 
 */
void MechaRidleyPartHeadIdle(void)
{
    MechaRidleyLoadFireballsGfx();
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

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    // Enable core hitbox
    gSpriteData[ramSlot].status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;

    gSubSpriteData1.health = gBossWork.work9;
    gBossWork.work7 = gBossWork.work9;

    // Set cover destroyed flag
    gSubSpriteData1.workVariable3 = HEALTH_THRESHOLD_COVER_BROKEN;

    // Disable
    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.pose = MECHA_RIDLEY_PART_POSE_COVER_BROKEN;

    ParticleSet(gCurrentSprite.yPosition + 12, gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE, PE_SPRITE_EXPLOSION_HUGE);
    SoundPlay(0x12F);
}

/**
 * @brief 4d3a4 | 190 | Handles the missile launcher part being idle
 * 
 */
void MechaRidleyPartMissileLauncherIdle(void)
{
    MechaRidleyLoadMissilesGfx();

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
                // Set opened
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
                    // Set closing
                    gCurrentSprite.pOam = sMechaRidleyPartOAM_MissileLauncherClosing;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.animationDurationCounter = 0;

                    gBossWork.work5 = MISSILE_LAUNCHER_STATE_CLOSING;
                }
            }
            else
            {
                // Spawn missiles
                if (gCurrentSprite.currentAnimationFrame == 1 && gCurrentSprite.animationDurationCounter == 1)
                {
                    if (gCurrentSprite.timer == 1)
                    {
                        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_MISSILE, 0, gCurrentSprite.spritesetGfxSlot,
                            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_SIZE,
                            gCurrentSprite.xPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE), 0);
                    }
                    else if (gCurrentSprite.timer == 2)
                    {
                        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_MISSILE, 1, gCurrentSprite.spritesetGfxSlot,
                            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - 0x34,
                            gCurrentSprite.xPosition - 0x3C, 0);
                    }
                    else
                    {
                        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_MISSILE, 2, gCurrentSprite.spritesetGfxSlot,
                            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - 0x34,
                            gCurrentSprite.xPosition - 0x24, 0);

                        SoundPlay(0x2A7);
                    }
                }
            }
            break;

        case MISSILE_LAUNCHER_STATE_CLOSING:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                // Set closed
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
                            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                            gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition - 0x6C, 0);
                        break;

                    case LASER_DIRECTION_DOWN:
                        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_LASER, LASER_DIRECTION_DOWN,
                            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                            gCurrentSprite.yPosition + (BLOCK_SIZE + HALF_BLOCK_SIZE),
                            gCurrentSprite.xPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), 0);
                        break;

                    case LASER_DIRECTION_SLIGHTLY_UP:
                        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_LASER, LASER_DIRECTION_SLIGHTLY_UP,
                            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                            gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition - 0x6C, 0);
                        break;

                    case LASER_DIRECTION_UP:
                        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_LASER, LASER_DIRECTION_UP,
                            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                            gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
                            gCurrentSprite.xPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), 0);
                        break;

                    default:
                        SpriteSpawnSecondary(SSPRITE_MECHA_RIDLEY_LASER, direction,
                            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
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

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

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

    // Update hitbox based on animation
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

    if (gCurrentSprite.pose != 0)
    {
        samusY = gSamusData.yPosition;
        spriteY = gSubSpriteData1.yPosition - BLOCK_SIZE;

        if (samusY > spriteY)
        {
            if (gCurrentSprite.oamRotation == 0)
            {
                if (gBossWork.work3 != MECHA_RIDLEY_SAMUS_POSITION_LOW)
                    gCurrentSprite.oamRotation = 120;
            }
            else
            {
                gCurrentSprite.oamRotation--;
                if (gCurrentSprite.oamRotation == 0)
                    gBossWork.work3 = MECHA_RIDLEY_SAMUS_POSITION_LOW;
            }
        }
        else
        {
            if (spriteY - samusY > BLOCK_SIZE * 3)
                gBossWork.work3 = MECHA_RIDLEY_SAMUS_POSITION_HIGH;
            else if (gBossWork.work3 != MECHA_RIDLEY_SAMUS_POSITION_LOW)
            {
                if (gCurrentSprite.oamRotation == 0)
                {
                    if (gBossWork.work3 != MECHA_RIDLEY_SAMUS_POSITION_MIDDLE)
                        gCurrentSprite.oamRotation = 120;
                }
                else
                {
                    gCurrentSprite.oamRotation--;
                    if (gCurrentSprite.oamRotation == 0)
                        gBossWork.work3 = MECHA_RIDLEY_SAMUS_POSITION_MIDDLE;
                }
            }
            else
                gBossWork.work3 = MECHA_RIDLEY_SAMUS_POSITION_MIDDLE;
        }
    }
    
    switch (gCurrentSprite.pose)
    {
        case 0:
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

        case MECHA_RIDLEY_POSE_CLAW_ATTACK:
            MechaRidleyClawAttack();
            break;

        case MECHA_RIDLEY_POSE_STANDING_UP:
            MechaRidleyStandingUp();
            break;

        case MECHA_RIDLEY_POSE_CURLED_UP:
            MechaRidleyCurledUp();
            break;

        case MECHA_RIDLEY_POSE_RETRACTING:
            MechaRidleyRetracting();
            break;

        case MECHA_RIDLEY_POSE_CRAWLING_BACKWARDS:
            MechaRidleyCrawlingBack();
            break;

        case MECHA_RIDLEY_POSE_STANDING_FOR_FIREBALL_ATTACK_INIT:
            MechaRidleyStandingForFireballsInit();
            break;

        case MECHA_RIDLEY_POSE_STANDING_FOR_FIREBALL_ATTACK:
            MechaRidleyStandingForFireballs();
            break;

        case MECHA_RIDLEY_POSE_OPENING_MOUTH:
            MechaRidleyCheckOpeningMouthAnimEnded();
            break;

        case MECHA_RIDLEY_POSE_FIREBALL_ATTACK:
            MechaRidleyFireballsAttack();
            break;

        case MECHA_RIDLEY_POSE_CLOSING_MOUTH:
            MechaRidleyCheckClosingMouthAnimEnded();
            break;

        case MECHA_RIDLEY_POSE_RETRACTING_AFTER_FIREBALL_ATTACK:
            MechaRidleyRetractingAfterFireballAttack();
            break;

        case MECHA_RIDLEY_POSE_DYING_INIT:
            MechaRidleyDyingInit();
            break;

        case MECHA_RIDLEY_POSE_DYING_STANDING_UP:
            MechaRidleyDying();
            break;

        case MECHA_RIDLEY_POSE_DYING_GLOW_FADING:
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
    if (gCurrentSprite.pose == MECHA_RIDLEY_POSE_IDLE || gCurrentSprite.pose == MECHA_RIDLEY_POSE_CURLED_UP)
        gSubSpriteData1.workVariable2++; // Missile attack timer

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

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
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
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;

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

            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteID);
            gCurrentSprite.oamRotation = 0xA0;
            gCurrentSprite.oamScaling = 0x100;
            
            gCurrentSprite.timer = 30;
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
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
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

            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteID);
            gCurrentSprite.timer = 30;
            gCurrentSprite.pose = 9;

            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
            gCurrentSprite.drawOrder = 2;
            gCurrentSprite.oamScaling = 0x100;

            if (gCurrentSprite.roomSlot != FIREBALL_LOW)
                gCurrentSprite.oamRotation = 0x28;
            else
                gCurrentSprite.oamRotation = 0;

            gBossWork.work8++;
            break;

        case 9:
            if (gCurrentSprite.roomSlot != FIREBALL_LOW)
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
