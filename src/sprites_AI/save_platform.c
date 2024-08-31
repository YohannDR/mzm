#include "sprites_AI/save_platform.h"
#include "sprites_AI/item_banner.h"

#include "data/sprites/save_platform.h"

#include "constants/audio.h"
#include "constants/escape.h"
#include "constants/sprite.h"
#include "constants/samus.h"
#include "constants/text.h"

#include "structs/game_state.h"
#include "structs/hud.h"
#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 1f9b0 | 38 | Checks if Samus is standing on a save platform
 * 
 * @return u8 1 if standing on, 0 otherwise
 */
u8 SavePlatformDetectSamus(void)
{
    u8 colliding;
    s32 samusY;
    s32 samusX;
    s32 spriteY;
    s32 spriteX;

    colliding = FALSE;
    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;

    if (samusY == spriteY - (BLOCK_SIZE + 1) && (spriteX - BLOCK_SIZE) < samusX && (spriteX + BLOCK_SIZE) > samusX)
        colliding = TRUE;

    return colliding;
}

/**
 * @brief 1f9e8 | 128 | Initializes a save platform sprite
 * 
 */
void SavePlatformInit(void)
{
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.yPositionSpawn = 0x0;
    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.drawDistanceTop = 0x10;
    gCurrentSprite.drawDistanceBottom = 0x10;
    gCurrentSprite.drawDistanceHorizontal = 0x28;

    gCurrentSprite.hitboxTop = -0x4;
    gCurrentSprite.hitboxBottom = 0x4;
    gCurrentSprite.hitboxLeft = -0x4;
    gCurrentSprite.hitboxRight = 0x4;

    if (gAlarmTimer != 0x0)
        gCurrentSprite.work2 = TRUE;
    else
        gCurrentSprite.work2 = FALSE;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.work0 = 0xA;

    if (gCurrentSprite.work2 || EscapeDetermineTimer() != ESCAPE_NONE)
    {
        gCurrentSprite.pOam = sSavePlatformOAM_IdleOff;
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_OFF;
    }
    else if (gIsLoadingFile)
    {
        SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_PART, SAVE_PLATFORM_PART_TUBE, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

        gCurrentSprite.pOam = sSavePlatformOAM_OpenedOff;
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_RELEASE_SAMUS;
        gCurrentSprite.yPositionSpawn = 0x154;
    }
    else
    {
        gCurrentSprite.pOam = sSavePlatformOAM_Idle;
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_IDLE;
    }

    gCurrentSprite.work3 = SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_PART, SAVE_PLATFORM_PART_TOP,
        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
        gCurrentSprite.yPosition - BLOCK_SIZE * 8, gCurrentSprite.xPosition, 0x0);
}

/**
 * @brief 1fb10 | 58 | Handles a save platform being idle
 * 
 */
void SavePlatformSamusDetection(void)
{
    if (SavePlatformDetectSamus() && !SpriteUtilCheckCrouchingOrMorphed())
    {
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0x0)
        {
            gCurrentSprite.pose = SAVE_PLATFORM_POSE_OPENING;
            gCurrentSprite.pOam = sSavePlatformOAM_Opening;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            SoundPlay(SOUND_SAVE_PLATFORM_OPENING);
        }
    }
    else
        gCurrentSprite.work0 = 0xA;
}

/**
 * @brief 1fb68 | 2c | Handles a save platform opening
 * 
 */
void SavePlatformCheckOpeningAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_OPENED;
        gCurrentSprite.pOam = sSavePlatformOAM_Opened;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 1fb94 | 80 | Handles a save platform being opened
 * 
 */
void SavePlatformSecondSamusDetection(void)
{
    if (SavePlatformDetectSamus())
    {
        if (!SpriteUtilCheckCrouchingOrMorphed())
        {
            gCurrentSprite.pose = SAVE_PLATFORM_POSE_SAVE_PROMPT;
            gCurrentSprite.work0 = 0x4;
            gSamusData.xPosition = gCurrentSprite.xPosition;
            if (gSamusData.invincibilityTimer != 0x0)
                gSamusData.invincibilityTimer = 0x0;
            SamusSetPose(SPOSE_TURNING_FROM_FACING_THE_FOREGROUND);
            gSamusData.timer = TRUE;
            gDisablePause = TRUE;
        }
    }
    else
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_CLOSING;
        gCurrentSprite.pOam = sSavePlatformOAM_Closing;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        SoundPlay(SOUND_SAVE_PLATFORM_CLOSING);
    }
}

/**
 * @brief 1fc14 | 30 | Handles a save platform closing
 * 
 */
void SavePlatformCheckClosingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_IDLE;
        gCurrentSprite.pOam = sSavePlatformOAM_Idle;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.work0 = 0xA;
    }
}

/**
 * @brief 1fc44 | 34 | Handles a save platform releasing Samus
 * 
 */
void SavePlatformReleaseSamus(void)
{
    if (gCurrentSprite.yPositionSpawn != 0x0)
        gCurrentSprite.yPositionSpawn--;
    else
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_AFTER_SAVE;
        SamusSetPose(SPOSE_FACING_THE_FOREGROUND);
        gDisablePause = FALSE;
    }
}

/**
 * @brief 1fc78 | 38 | Handles a save platform after a save
 * 
 */
void SavePlatformSamusDetectionOut(void)
{
    if (!SavePlatformDetectSamus())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_CLOSING;
        gCurrentSprite.pOam = sSavePlatformOAM_Closing;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        SoundPlay(SOUND_SAVE_PLATFORM_CLOSING);
    }
}

/**
 * @brief 1fcb0 | d0 | Handles a save platform during a save prompt
 * 
 */
void SavePlatformSavePrompt(void)
{
    u8 ramSlot;

    if (gCurrentSprite.work0 != 0x0)
    {
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0x0)
            gCurrentSprite.work1 = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_SAVE_PROMPT, 0x6,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
    else
    {
        // Item banner
        ramSlot = gCurrentSprite.work1;
        if (gSpriteData[ramSlot].pose == ITEM_BANNER_POSE_REMOVAL_ANIMATION)
        {
            if (gSpriteData[ramSlot].work1 == TRUE)
            {
                gCurrentSprite.pOam = sSavePlatformOAM_Saving;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;

                gCurrentSprite.pose = SAVE_PLATFORM_POSE_SAVING;
                SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_PART, SAVE_PLATFORM_PART_TUBE, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

                gSpriteData[gCurrentSprite.work3].pose = SAVE_PLATFORM_PART_POSE_TOP_EXTENDING_INIT;
                gSamusData.timer = FALSE;
                SoundPlay(SOUND_SAVING);
            }
            else
            {
                gCurrentSprite.pose = SAVE_PLATFORM_POSE_DELAY_BEFORE_RELEASING;
                gCurrentSprite.work0 = 0xA;
            }
        }
    }
}

/**
 * @brief 1fd80 | 40 | Handles a save platform saving
 * 
 */
void SavePlatformSaving(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.work3;
    if (gCurrentSprite.currentAnimationFrame & 0x1)
    {
        gCurrentSprite.paletteRow = 0x0;
        gSpriteData[ramSlot].paletteRow = gCurrentSprite.paletteRow;
    }
    else
    {
        gCurrentSprite.paletteRow = 0x2;
        gSpriteData[ramSlot].paletteRow = gCurrentSprite.paletteRow;
    }
}

/**
 * @brief 1fdc0 | 44 | Initializes a save platform to be opened (off)
 * 
 */
void SavePlatformOpenedOffInit(void)
{
    gCurrentSprite.pOam = sSavePlatformOAM_OpenedOff;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = SAVE_PLATFORM_POSE_SPAWN_SAVE_DONE_MESSAGE;
    gCurrentSprite.work0 = 0x3C;
    gCurrentSprite.paletteRow = 0x0;
    gSpriteData[gCurrentSprite.work3].paletteRow = 0x0;
}

/**
 * @brief 1fe04 | 44 | Spawns the "save complete" message
 * 
 */
void SavePlatformSpawnSaveDoneMessage(void)
{
    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0x0)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_WAIT_FOR_MESSAGE_OUT;
        gCurrentSprite.work1 = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_SAVE_COMPLETE, 0x6,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 1fe48 | 38 | Handles a save platform waiting for the "Save complete" message to be done
 * 
 */
void SavePlatformCheckMessageBannerOut(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.work1;
    if (gSpriteData[ramSlot].pose == ITEM_BANNER_POSE_REMOVAL_ANIMATION)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_DELAY_BEFORE_RELEASING;
        gCurrentSprite.work0 = 0xA;
    }
}

/**
 * @brief 1fe80 | 24 | Handles the delay before a save platform releases Samus
 * 
 */
void SavePlatformDelayBeforeReleasingSamus(void)
{
    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0x0)
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_RELEASE_SAMUS;
}

/**
 * @brief 1fea4 | 16c | Initializes a save platform part sprite
 * 
 */
void SavePlatformPartInit(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.hitboxTop = -0x4;
    gCurrentSprite.hitboxBottom = 0x4;
    gCurrentSprite.hitboxLeft = -0x4;
    gCurrentSprite.hitboxRight = 0x4;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    switch (gCurrentSprite.roomSlot)
    {
        case SAVE_PLATFORM_PART_TUBE:
            gCurrentSprite.drawDistanceTop = 0x50;
            gCurrentSprite.drawDistanceBottom = 0x0;
            gCurrentSprite.drawDistanceHorizontal = 0x18;
            if (gSpriteData[ramSlot].pose == SAVE_PLATFORM_POSE_RELEASE_SAMUS)
            {
                gCurrentSprite.pOam = sSavePlatformPartOAM_TubeIdle;
                gCurrentSprite.yPositionSpawn = 0x136;
                gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_IDLE;
            }
            else
            {
                gCurrentSprite.pOam = sSavePlatformPartOAM_TubeSpawning;
                gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_SPAWNING;
            }
            break;

        case SAVE_PLATFORM_PART_TUBE_SHADOW:
            gCurrentSprite.drawOrder = 0xC;
            gCurrentSprite.pOam = sSavePlatformPartOAM_TubeShadow;
            gCurrentSprite.drawDistanceTop = 0x50;
            gCurrentSprite.drawDistanceBottom = 0x0;
            gCurrentSprite.drawDistanceHorizontal = 0x18;
            gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_SHADOW_IDLE;
            break;

        case SAVE_PLATFORM_PART_RAY:
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pOam = sSavePlatformPartOAM_Ray;
            gCurrentSprite.drawDistanceTop = 0x8;
            gCurrentSprite.drawDistanceBottom = 0x0;
            gCurrentSprite.drawDistanceHorizontal = 0x18;
            gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_RAY_IDLE;
            gCurrentSprite.work0 = 0x60;
            break;

        case SAVE_PLATFORM_PART_TOP:
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.drawDistanceTop = 0x20;
            gCurrentSprite.drawDistanceBottom = 0x40;
            gCurrentSprite.drawDistanceHorizontal = 0x20;
            gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TOP_IDLE;
            if (gSpriteData[ramSlot].pose == SAVE_PLATFORM_POSE_RELEASE_SAMUS)
                gCurrentSprite.pOam = sSavePlatformPartOAM_TopExtended;
            else
                gCurrentSprite.pOam = sSavePlatformPartOAM_TopIdle;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 20010 | 4 | Empty function
 * 
 */
void SavePlatformPart_Empty(void)
{
    return;
}

/**
 * @brief 20014 | 1c | Initializes the top part to be extending
 * 
 */
void SavePlatformPartExtendingInit(void)
{
    gCurrentSprite.pOam = sSavePlatformPartOAM_TopExtending;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TOP_EXTENDING;
}

/**
 * @brief 20030 | 2c | Handles the top part extending
 * 
 */
void SavePlatformPartTopExtending(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TOP_IDLE;
        gCurrentSprite.pOam = sSavePlatformPartOAM_TopExtended;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 2005c | 34 | Initializes the top part to be retracting
 * 
 */
void SavePlatformPartTopRetractingInit(void)
{
    gCurrentSprite.pOam = sSavePlatformPartOAM_TopRetracting;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TOP_RETRACTING;
    gSamusData.timer = TRUE;
    SoundPlay(SOUND_SAVE_PLATFORM_RETRACTING);
}

/**
 * @brief 20090 | 2c | Handles the top part retracting
 * 
 */
void SavePlatformPartTopRetracting(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TOP_IDLE;
        gCurrentSprite.pOam = sSavePlatformPartOAM_TopIdle;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 200bc | 50 | Handles the tube part spawning
 * 
 */
void SavePlatformPartTubeSpawning(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_CHECK_SHADOW_DISAPPEARED;
        gCurrentSprite.pOam = sSavePlatformPartOAM_TubeIdle;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.work1 = SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_PART, SAVE_PLATFORM_PART_TUBE_SHADOW,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 2010c | 54 | Handles the tube part spawning the ray part
 * 
 */
void SavePlatformPartSpawnRay(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.work1;
    if (gSpriteData[ramSlot].status == 0x0)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_IDLE;
        gCurrentSprite.yPositionSpawn = 0x78;
        SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_PART, SAVE_PLATFORM_PART_RAY, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 20160 | 30 | Handles the tube part being idle
 * 
 */
void SavePlatformPartTubeIdle(void)
{
    gCurrentSprite.yPositionSpawn--;
    if (gCurrentSprite.yPositionSpawn == 0x0)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_DESPAWNING;
        gCurrentSprite.pOam = sSavePlatformPartOAM_TubeDespawning;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 20190 | 3c | handles the tube part despawning
 * 
 */
void SavePlatformPartTubeDespawning(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.status = 0x0;
        gSpriteData[gSpriteData[gCurrentSprite.primarySpriteRamSlot].work3].pose = SAVE_PLATFORM_PART_POSE_TOP_RETRACTING_INIT;
    }
}

/**
 * @brief 201cc | 18 | Handles the tube shadow part being idle
 * 
 */
void SavePlatformPartTubeShadowIdle(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}

/**
 * @brief 201e4 | 44 | Handles the ray part being idle
 * 
 */
void SavePlatformPartRayIdle(void)
{
    gCurrentSprite.yPosition -= 0x4;
    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0x0)
    {
        gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose = SAVE_PLATFORM_POSE_OPENED_OFF_INIT;
        gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 20228 | 1a8 | Save platform AI
 * 
 */
void SavePlatform(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            SavePlatformInit();
            break;

        case SAVE_PLATFORM_POSE_IDLE:
            SavePlatformSamusDetection();
            break;

        case SAVE_PLATFORM_POSE_OPENING:
            SavePlatformCheckOpeningAnimEnded();
            break;

        case SAVE_PLATFORM_POSE_OPENED:
            SavePlatformSecondSamusDetection();
            break;

        case SAVE_PLATFORM_POSE_CLOSING:
            SavePlatformCheckClosingAnimEnded();
            break;

        case SAVE_PLATFORM_POSE_RELEASE_SAMUS:
            SavePlatformReleaseSamus();
            break;

        case SAVE_PLATFORM_POSE_AFTER_SAVE:
            SavePlatformSamusDetectionOut();
            break;

        case SAVE_PLATFORM_POSE_SAVE_PROMPT:
            SavePlatformSavePrompt();
            break;

        case SAVE_PLATFORM_POSE_SAVING:
            SavePlatformSaving();
            break;

        case SAVE_PLATFORM_POSE_OPENED_OFF_INIT:
            SavePlatformOpenedOffInit();
            break;

        case SAVE_PLATFORM_POSE_SPAWN_SAVE_DONE_MESSAGE:
            SavePlatformSpawnSaveDoneMessage();
            break;

        case SAVE_PLATFORM_POSE_WAIT_FOR_MESSAGE_OUT:
            SavePlatformCheckMessageBannerOut();
            break;

        case SAVE_PLATFORM_POSE_DELAY_BEFORE_RELEASING:
            SavePlatformDelayBeforeReleasingSamus();
    }
}

/**
 * @brief 203d0 | 194 | Save platform part AI
 * 
 */
void SavePlatformPart(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            SavePlatformPartInit();
            break;

        case SAVE_PLATFORM_PART_POSE_TUBE_SPAWNING:
            SavePlatformPartTubeSpawning();
            break;

        case SAVE_PLATFORM_PART_POSE_TUBE_CHECK_SHADOW_DISAPPEARED:
            SavePlatformPartSpawnRay();
            break;

        case SAVE_PLATFORM_PART_POSE_TUBE_IDLE:
            SavePlatformPartTubeIdle();
            break;

        case SAVE_PLATFORM_PART_POSE_TUBE_DESPAWNING:
            SavePlatformPartTubeDespawning();
            break;

        case SAVE_PLATFORM_PART_POSE_TUBE_SHADOW_IDLE:
            SavePlatformPartTubeShadowIdle();
            break;

        case SAVE_PLATFORM_PART_POSE_RAY_IDLE:
            SavePlatformPartRayIdle();
            break;

        case SAVE_PLATFORM_PART_POSE_TOP_IDLE:
            SavePlatformPart_Empty();
            break;

        case SAVE_PLATFORM_PART_POSE_TOP_EXTENDING_INIT:
            SavePlatformPartExtendingInit();
            break;

        case SAVE_PLATFORM_PART_POSE_TOP_EXTENDING:
            SavePlatformPartTopExtending();
            break;

        case SAVE_PLATFORM_PART_POSE_TOP_RETRACTING_INIT:
            SavePlatformPartTopRetractingInit();
            break;

        case SAVE_PLATFORM_PART_POSE_TOP_RETRACTING:
            SavePlatformPartTopRetracting();
    }
}