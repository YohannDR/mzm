#include "gba.h"
#include "sprites_AI/item_banner.h"
#include "sprites_AI/save_platform_chozodia.h"

#include "data/sprites/save_platform_chozodia.h"

#include "constants/escape.h"
#include "constants/sprite.h"
#include "constants/samus.h"

#include "structs/game_state.h"
#include "structs/hud.h"
#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 46708 | 168 | Initializes a save platform (Chozodia) sprite
 * 
 */
void SavePlatformChozodiaInit(void)
{
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.yPositionSpawn = 0x0;
    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.drawDistanceTopOffset = 0x18;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

    gCurrentSprite.hitboxTopOffset = -0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;

    if (gAlarmTimer != 0x0)
        gCurrentSprite.workVariable2 = TRUE;
    else
        gCurrentSprite.workVariable2 = FALSE;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.timer = 0xA;

    if (gCurrentSprite.workVariable2 || EscapeDetermineTimer() != ESCAPE_NONE)
    {
        gCurrentSprite.pOam = sSavePlatformChozodiaOAM_OpenedOff;
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_OFF;
    }
    else if (gIsLoadingFile)
    {
        SpriteSpawnSecondary(SSPRITE_CHOZODIA_SAVE_PLATFORM_PART, SAVE_PLATFORM_CHOZODIA_PART_TUBE,
            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

        gCurrentSprite.pOam = sSavePlatformChozodiaOAM_IdleOff;
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_RELEASE_SAMUS;
        gCurrentSprite.yPositionSpawn = 0x154;
    }
    else
    {
        gCurrentSprite.pOam = sSavePlatformChozodiaOAM_Idle;
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_IDLE;
    }

    gCurrentSprite.arrayOffset = SpriteSpawnSecondary(SSPRITE_CHOZODIA_SAVE_PLATFORM_PART, SAVE_PLATFORM_CHOZODIA_PART_TOP,
        gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
        gCurrentSprite.yPosition - BLOCK_SIZE * 8, gCurrentSprite.xPosition, 0x0);

    if (gCurrentSprite.pose == SAVE_PLATFORM_CHOZODIA_POSE_OFF)
    {
        gCurrentSprite.paletteRow = 0x3;
        gSpriteData[gCurrentSprite.arrayOffset].paletteRow = 0x3;
    }

    TransparencyUpdateBLDCNT(0x1, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
        BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL |
        BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL);
    
    TransparencySpriteUpdateBLDALPHA(0x0, 0x10, 0x0, 0x10);
}

/**
 * @brief 46870 | 58 | Handles a save platform (Chozodia) being idle
 * 
 */
void SavePlatformChozodiaSamusDetection(void)
{
    if (SavePlatformDetectSamus() && !SpriteUtilCheckCrouchingOrMorphed())
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_OPENING;
            gCurrentSprite.pOam = sSavePlatformChozodiaOAM_Opening;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            SoundPlay(0x127);
        }
    }
    else
        gCurrentSprite.timer = 0xA;
}

/**
 * @brief 468c8 | 2c | Handles a save platform opening
 * 
 */
void SavePlatformChozodiaCheckOpeningAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_OPENED;
        gCurrentSprite.pOam = sSavePlatformChozodiaOAM_Opened;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 468f4 | 78 | Handles a save platform (Chozodia) being opened
 * 
 */
void SavePlatformChozodiaSecondSamusDetection(void)
{
    if (SavePlatformDetectSamus())
    {
        if (!SpriteUtilCheckCrouchingOrMorphed())
        {
            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_CHECK_REFILL;
            gCurrentSprite.timer = 0x4;
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
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_CLOSING;
        gCurrentSprite.pOam = sSavePlatformChozodiaOAM_Closing;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        SoundPlay(0x128);
    }
}

/**
 * @brief 4696c | 30 | Handles a save platform (Chozodia) closing
 * 
 */
void SavePlatformChozodiaCheckClosingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_IDLE;
        gCurrentSprite.pOam = sSavePlatformChozodiaOAM_Idle;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.timer = 0xA;
    }
}

/**
 * @brief 4699c | 34 | Handles a save platform (Chozodia) releasing Samus
 * 
 */
void SavePlatformChozodiaReleaseSamus(void)
{
    if (gCurrentSprite.yPositionSpawn != 0x0)
        gCurrentSprite.yPositionSpawn--;
    else
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_AFTER_SAVE;
        SamusSetPose(SPOSE_FACING_THE_FOREGROUND);
        gDisablePause = FALSE;
    }
}

/**
 * @brief 469d0 | 34 | Handles a save platform after a save
 * 
 */
void SavePlatformChozodiaSamusDetectionOut(void)
{
    if (!SavePlatformDetectSamus())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_CLOSING;
        gCurrentSprite.pOam = sSavePlatformChozodiaOAM_Closing;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        SoundPlay(0x128);
    }
}

/**
 * @brief 46a04 | c0 | Checksif Samus needs a refill
 * 
 */
void SavePlatformChozodiaCheckRefill(void)
{
    u8 isFull;

    isFull = FALSE;

    if (gCurrentSprite.timer != 0x0)
        gCurrentSprite.timer--;
    else
    {
        if (gEquipment.suitType == SUIT_SUITLESS)
        {
            if (gEquipment.currentEnergy == gEquipment.maxEnergy)
                isFull = TRUE;
        }
        else
        {
            if (gEquipment.currentEnergy == gEquipment.maxEnergy && gEquipment.currentMissiles == gEquipment.maxMissiles &&
                gEquipment.currentSuperMissiles == gEquipment.maxSuperMissiles)
            {
                if (gEquipment.currentPowerBombs == gEquipment.maxPowerBombs)
                    isFull = TRUE;
            }
        }

        if (isFull)
        {
            gCurrentSprite.timer = 0xA;
            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_SAVE_PROMPT;
        }
        else
        {
            gSamusData.timer = FALSE;
            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_REFILL;
            gCurrentSprite.timer = 0x5;

            SpriteSpawnSecondary(SSPRITE_CHOZODIA_SAVE_PLATFORM_PART, SAVE_PLATFORM_CHOZODIA_PART_REFILL_LIGHT,
                gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

            TransparencySpriteUpdateBLDALPHA(0x7, 0x10, 0x0, 0x10);
            SoundPlay(0x129);
        }
    }
}

/**
 * @brief 46ac4 | 194 | Handles a save platform (Chozodia) refilling Samus
 * 
 */
void SavePlatformChozodiaRefill(void)
{
    if (gEquipment.suitType == SUIT_SUITLESS)
    {
        if (gCurrentSprite.timer == 0x5)
        {
            if (!SpriteUtilRefillEnergy())
            {
                gCurrentSprite.timer--;
                gEnergyRefillAnimation = 0xD;
            }
        }
        else if (gCurrentSprite.timer == 0x4)
        {
            if (gEnergyRefillAnimation != 0x0)
                gEnergyRefillAnimation--;
            else
                gCurrentSprite.timer--;
        }
        else if (gCurrentSprite.timer != 0x0)
        {
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                gSamusData.timer = TRUE;
                TransparencySpriteUpdateBLDALPHA(0x0, 0x10, 0x0, 0x10);
                SoundFade(0x129, 0x14);
            }
        }
        else
        {
            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_AFTER_REFILL;
            gCurrentSprite.workVariable = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_ENERGY_TANK_RECHARGE_COMPLETE,
                0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        }
    }
    else
    {
        if (gCurrentSprite.timer == 0x5)
        {
            if (!SpriteUtilRefillEnergy())
            {
                gCurrentSprite.timer--;
                gEnergyRefillAnimation = 0xD;
            }
        }
        else if (gCurrentSprite.timer == 0x4)
        {
            if (gEnergyRefillAnimation != 0x0)
                gEnergyRefillAnimation--;
            else if (!SpriteUtilRefillMissiles())
            {
                gCurrentSprite.timer--;
                gMissileRefillAnimation = 0xD;
            }
        }
        else if (gCurrentSprite.timer == 0x3)
        {
            if (gMissileRefillAnimation != 0x0)
                gMissileRefillAnimation--;
            else if (!SpriteUtilRefillSuperMissiles())
            {
                gCurrentSprite.timer--;
                gSuperMissileRefillAnimation = 0xD;
            }
        }
        else if (gCurrentSprite.timer == 0x2)
        {
            if (gSuperMissileRefillAnimation != 0x0)
                gSuperMissileRefillAnimation--;
            else if (!SpriteUtilRefillPowerBombs())
            {
                gCurrentSprite.timer--;
                gPowerBombRefillAnimation = 0xD;
            }
        }
        else if (gPowerBombRefillAnimation != 0x0)
                gPowerBombRefillAnimation--;
        else if (gCurrentSprite.timer != 0x0)
        {
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                gSamusData.timer = TRUE;
                TransparencySpriteUpdateBLDALPHA(0x0, 0x10, 0x0, 0x10);
                SoundFade(0x129, 0x14);
            }
        }
        else
        {
            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_AFTER_REFILL;
            gCurrentSprite.workVariable = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_WEAPONS_AND_ENERGY_RESTORED,
                0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        }
    }
}

/**
 * @brief 46c58 | 38 | Handles a save platform (Complete) waiting for the "Refill complete" message to be done
 * 
 */
void SavePlatformChozodiaAfterRefill(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.workVariable;
    if (gSpriteData[ramSlot].pose == ITEM_BANNER_POSE_REMOVAL_ANIMATION)
    {
        gCurrentSprite.timer = 0x14;
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_SAVE_PROMPT;
    }
}

/**
 * @brief 46c90 | d0 | Handles a save platform (Chozodia) during a save prompt
 * 
 */
void SavePlatformChozodiaSavePrompt(void)
{
    u8 ramSlot;

    if (gCurrentSprite.timer != 0x0)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            gCurrentSprite.workVariable = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_SAVE_PROMPT,
                0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        }
    }
    else
    {
        ramSlot = gCurrentSprite.workVariable;
        if (gSpriteData[ramSlot].pose == ITEM_BANNER_POSE_REMOVAL_ANIMATION)
        {
            if (gSpriteData[ramSlot].workVariable == TRUE)
            {
                gCurrentSprite.pOam = sSavePlatformChozodiaOAM_Saving;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;

                gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_SAVING;

                SpriteSpawnSecondary(SSPRITE_CHOZODIA_SAVE_PLATFORM_PART, SAVE_PLATFORM_CHOZODIA_PART_TUBE,
                    gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition, 0x0);

                gSpriteData[gCurrentSprite.arrayOffset].pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_EXTENDING_INIT;
                gSamusData.timer = FALSE;
                SoundPlay(0x114);
            }
            else
            {
                gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_DELAY_BEFORE_RELEASING;
                gCurrentSprite.timer = 0xA;
            }
        }
    }
}

/**
 * @brief 46d60 | 40 | Handles a save platform (Chozodia) saving
 * 
 */
void SavePlatformChozodiaSaving(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.arrayOffset;
    if (gCurrentSprite.currentAnimationFrame & 0x1)
    {
        gCurrentSprite.paletteRow = 0x0;
        gSpriteData[ramSlot].paletteRow = 0x0;
    }
    else
    {
        gCurrentSprite.paletteRow = 0x2;
        gSpriteData[ramSlot].paletteRow = 0x2;
    }
}

/**
 * @brief 46da0 | 44 | Initializes a save platform (Chozodia) to be opened (off)
 * 
 */
void SavePlatformChozodiaOpenedOffInit(void)
{
    gCurrentSprite.pOam = sSavePlatformChozodiaOAM_IdleOff;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_SPAWN_SAVE_DONE_MESSAGE;
    gCurrentSprite.timer = 0x3C;
    gCurrentSprite.paletteRow = 0x0;
    gSpriteData[gCurrentSprite.arrayOffset].paletteRow = 0x0;
}

/**
 * @brief 46de4 | 44 | Spawns the "save complete" message
 * 
 */
void SavePlatformChozodiaSpawnSaveDoneMessage(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_WAIT_FOR_MESSAGE_OUT;
        gCurrentSprite.workVariable = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_SAVE_COMPLETE,
            0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 46e28 | 38 | Handles a save platform (Chozodia) waiting for the "Save complete" message to be done
 * 
 */
void SavePlatformChozodiaCheckMessageBannerOut(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.workVariable;

    if (gSpriteData[ramSlot].pose == ITEM_BANNER_POSE_REMOVAL_ANIMATION)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_DELAY_BEFORE_RELEASING;
        gCurrentSprite.timer = 0xA;
    }
}

/**
 * @brief 46e60 | 24 | andles the delay before a save platform (Chozodia) releases Samus
 * 
 */
void SavePlatformChozodiaDelayBeforeReleasingSamus(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_RELEASE_SAMUS;
}

/**
 * @brief 46e84 | 1b6 | Initializes a save platform (Chozodia) part sprite
 * 
 */
void SavePlatformChozodiaPartInit(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.hitboxTopOffset = -0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    switch (gCurrentSprite.roomSlot)
    {
        case SAVE_PLATFORM_CHOZODIA_PART_TUBE:
            gCurrentSprite.drawDistanceTopOffset = 0x50;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            if (gSpriteData[ramSlot].pose == SAVE_PLATFORM_CHOZODIA_POSE_RELEASE_SAMUS)
            {
                gCurrentSprite.pOam = sSavePlatformChozodiaPartOAM_TubeIdle;
                gCurrentSprite.yPositionSpawn = 0x136;
                gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_IDLE;
            }
            else
            {
                gCurrentSprite.pOam = sSavePlatformChozodiaPartOAM_TubeSpawning;
                gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_SPAWNING;
            }
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_TUBE_SHADOW:
            gCurrentSprite.drawOrder = 0xC;
            gCurrentSprite.pOam = sSavePlatformChozodiaPartOAM_TubeShadow;

            gCurrentSprite.drawDistanceTopOffset = 0x50;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_SHADOW_IDLE;
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_RAY:
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pOam = sSavePlatformChozodiaPartOAM_Ray;
            
            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_RAY_IDLE;
            gCurrentSprite.timer = 0x60;
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_TOP:
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.drawDistanceTopOffset = 0x40;
            gCurrentSprite.drawDistanceBottomOffset = 0x40;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_IDLE;

            if (gSpriteData[ramSlot].pose == SAVE_PLATFORM_CHOZODIA_POSE_RELEASE_SAMUS)
                gCurrentSprite.pOam = sSavePlatformChozodiaPartOAM_TopExtended;
            else
                gCurrentSprite.pOam = sSavePlatformChozodiaPartOAM_TopIdle;
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_REFILL_LIGHT:
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pOam = sSavePlatformChozodiaPartOAM_RefillLight;

            gCurrentSprite.drawDistanceTopOffset = 0x50;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x14;

            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_REFILL_LIGHT_IDLE;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 4703c | 2c | Handles the refill light part being idle
 * 
 */
void SavePlatformChozodiaPartRefillLightIdle(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    if (gSpriteData[ramSlot].pose == SAVE_PLATFORM_CHOZODIA_POSE_AFTER_REFILL)
        gCurrentSprite.status = 0x0;
}

/**
 * @brief 47068 | 4 | Empty function
 * 
 */
void SavePlatformChozodiaPart_Empty(void)
{
    return;
}

/**
 * @brief 4706c | 1c | Initializes the top part to be extending
 * 
 */
void SavePlatformChozodiaPartTopExtendingInit(void)
{
    gCurrentSprite.pOam = sSavePlatformChozodiaPartOAM_TopExtending;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_EXTENDING;
}

/**
 * @brief 47088 | 2c | Handles the top part extending
 * 
 */
void SavePlatformChozodiaPartTopExtending(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_IDLE;

        gCurrentSprite.pOam = sSavePlatformChozodiaPartOAM_TopExtended;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 470b4 | 34 | Initializes the top part to be retracting
 * 
 */
void SavePlatformChozodiaPartTopRetractingInit(void)
{
    gCurrentSprite.pOam = sSavePlatformChozodiaPartOAM_TopRetracting;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_RETRACTING;

    gSamusData.timer = TRUE;
    SoundPlay(0x115);
}

/**
 * @brief 470e8 | 2c | Handles the top part retracting
 * 
 */
void SavePlatformChozodiaPartTopRetracting(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_IDLE;

        gCurrentSprite.pOam = sSavePlatformChozodiaPartOAM_TopIdle;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 47114 | 50 | Handles the tube part spawning
 * 
 */
void SavePlatformChozodiaPartTubeSpawning(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_CHECK_SHADOW_DISAPPEARED;
        
        gCurrentSprite.pOam = sSavePlatformChozodiaPartOAM_TubeIdle;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.workVariable = SpriteSpawnSecondary(SSPRITE_CHOZODIA_SAVE_PLATFORM_PART, SAVE_PLATFORM_CHOZODIA_PART_TUBE_SHADOW,
            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 47164 | 54 | Handles the tube part spawning the ray part
 * 
 */
void SavePlatformChozodiaPartSpawnRay(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.workVariable;

    if (gSpriteData[ramSlot].status == 0x0)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_IDLE;
        gCurrentSprite.yPositionSpawn = 0x78;
        SpriteSpawnSecondary(SSPRITE_CHOZODIA_SAVE_PLATFORM_PART, SAVE_PLATFORM_CHOZODIA_PART_RAY,
            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 471b8 | 30 | Handles the tube part being idle
 * 
 */
void SavePlatformChozodiaPartTubeIdle(void)
{
    gCurrentSprite.yPositionSpawn--;
    if (gCurrentSprite.yPositionSpawn == 0x0)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_DESPAWNING;
        gCurrentSprite.pOam = sSavePlatformChozodiaPartOAM_TubeDespawning;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 471e8 | 3c | Handles the tube part despawning
 * 
 */
void SavePlatformChozodiaPartTubeDespawning(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.status = 0x0;
        gSpriteData[gSpriteData[gCurrentSprite.primarySpriteRAMSlot].arrayOffset].pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_RETRACTING_INIT;
    }
}

/**
 * @brief 47224 | 18 | Handles the shadow part being idle
 * 
 */
void SavePlatformChozodiaPartTubeShadowIdle(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}

/**
 * @brief 4723c | 44 | Handles the ray part being idle
 * 
 */
void SavePlatformChozodiaPartRayIdle(void)
{
    gCurrentSprite.yPosition -= 0x4;
    gCurrentSprite.timer--;

    if (gCurrentSprite.timer == 0x0)
    {
        gSpriteData[gCurrentSprite.primarySpriteRAMSlot].pose = SAVE_PLATFORM_CHOZODIA_POSE_OPENED_OFF_INIT;
        gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 47280 | 1e8 | Save platform (Chozodia) AI
 * 
 */
void SavePlatformChozodia(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            SavePlatformChozodiaInit();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_IDLE:
            SavePlatformChozodiaSamusDetection();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_OPENING:
            MechaRidleyCheckOpeningMouthAnimEnded();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_OPENED:
            SavePlatformChozodiaSecondSamusDetection();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_CLOSING:
            SavePlatformChozodiaCheckClosingAnimEnded();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_RELEASE_SAMUS:
            SavePlatformChozodiaReleaseSamus();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_AFTER_SAVE:
            SavePlatformChozodiaSamusDetectionOut();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_SAVE_PROMPT:
            SavePlatformChozodiaSavePrompt();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_SAVING:
            SavePlatformChozodiaSaving();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_OPENED_OFF_INIT:
            SavePlatformChozodiaOpenedOffInit();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_SPAWN_SAVE_DONE_MESSAGE:
            SavePlatformChozodiaSpawnSaveDoneMessage();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_WAIT_FOR_MESSAGE_OUT:
            SavePlatformChozodiaCheckMessageBannerOut();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_DELAY_BEFORE_RELEASING:
            SavePlatformChozodiaDelayBeforeReleasingSamus();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_CHECK_REFILL:
            SavePlatformChozodiaCheckRefill();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_REFILL:
            SavePlatformChozodiaRefill();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_AFTER_REFILL:
            SavePlatformChozodiaAfterRefill();
            break;
    }
}

/**
 * @brief 47468 | 198 | Save platform (Chozodia) part AI
 * 
 */
void SavePlatformChozodiaPart(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            SavePlatformChozodiaPartInit();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_SPAWNING:
            SavePlatformChozodiaPartTubeSpawning();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_CHECK_SHADOW_DISAPPEARED:
            SavePlatformChozodiaPartSpawnRay();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_IDLE:
            SavePlatformChozodiaPartTubeIdle();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_DESPAWNING:
            SavePlatformChozodiaPartTubeDespawning();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_SHADOW_IDLE:
            SavePlatformChozodiaPartTubeShadowIdle();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_RAY_IDLE:
            SavePlatformChozodiaPartRayIdle();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_IDLE:
            SavePlatformChozodiaPart_Empty();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_EXTENDING_INIT:
            SavePlatformChozodiaPartTopExtendingInit();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_EXTENDING:
            SavePlatformChozodiaPartTopExtending();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_RETRACTING_INIT:
            SavePlatformChozodiaPartTopRetractingInit();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_RETRACTING:
            SavePlatformChozodiaPartTopRetracting();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_REFILL_LIGHT_IDLE:
            SavePlatformChozodiaPartRefillLightIdle();
            break;
    }
}
