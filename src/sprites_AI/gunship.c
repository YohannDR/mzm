#include "sprites_AI/gunship.h"
#include "gba.h"
#include "sprites_AI/item_banner.h"

#include "data/sprites/gunship.h"

#include "constants/audio.h"
#include "constants/color_fading.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/event.h"
#include "constants/samus.h"
#include "constants/text.h"

#include "structs/connection.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/hud.h"
#include "structs/sprite.h"
#include "structs/samus.h"

#define GUNSHIP_START_FLYING(flyDuration)       \
do {                                            \
    gCurrentSprite.pose = GUNSHIP_POSE_FLYING;  \
    gCurrentSprite.work0 = flyDuration;         \
    gCurrentSprite.work3 = 0;                   \
} while (0)

/**
 * @brief 44c24 | 84 | Updates the flames palette
 * 
 */
void GunshipFlickerFlames(void)
{
    u32 timer;
    u8 flag;
    u8 row;
    u8 offset;
    
    if (!(gCurrentSprite.status & SPRITE_STATUS_MOSAIC) && gCurrentSprite.work2 == 0x4)
    {
        row = gCurrentSprite.scaling;
        flag = 0x80;

        // Update palette row
        if (row & flag)
        {
            if (row > 0x80)
                gCurrentSprite.scaling--;

            if (gCurrentSprite.scaling == 0x80)
                gCurrentSprite.scaling = 0x0;
        }
        else
        {
            if (row < 0x2)
                gCurrentSprite.scaling++;

            if (gCurrentSprite.scaling == 0x2)
                gCurrentSprite.scaling |= flag;
        }

        // Transfer palette
        offset = gCurrentSprite.scaling & 0x7F;
        DMA_SET(3, (sGunshipFlashingPal + offset * 16),
            (PALRAM_BASE + 0x340), (DMA_ENABLE << 0x10) | 0x10);
    }
}

/**
 * @brief 44ca8 | b0 | Updates the entrance palette
 * 
 */
void GunshipEntranceFlashingAnim(void)
{
    u8 flag;
    u8 row;
    u8 offset;
    
    if (!(gCurrentSprite.status & SPRITE_STATUS_MOSAIC) && --gCurrentSprite.work2 == 0x0)
    {
        if (gCurrentSprite.pOam == sGunshipOAM_Refilling)
            gCurrentSprite.work2 = 0x2;
        else if (gCurrentSprite.pOam == sGunshipOAM_Flying)
            gCurrentSprite.work2 = 0x4;
        else
            gCurrentSprite.work2 = 0x8;

        row = gCurrentSprite.work1;

        // Update palette row
        if (row & 0x80)
        {
            if (gCurrentSprite.work1 > 0x80)
                gCurrentSprite.work1--;

            if (gCurrentSprite.work1 == 0x80)
                gCurrentSprite.work1 = 0x0;
        }
        else
        {
            if (gCurrentSprite.work1 < 0x4)
                gCurrentSprite.work1++;

            if (gCurrentSprite.work1 == 0x4)
                gCurrentSprite.work1 |= 0x80;
        }

        // Transfer palette
        offset = gCurrentSprite.work1 & 0x7F;
        DMA_SET(3, (sGunshipFlashingPal + 0x38 + offset * 16), // Not sure
            (PALRAM_BASE + 0x330), (DMA_ENABLE << 0x10) | 0x8);
    }
}

/**
 * @brief 44d58 | 64 | Checks if samus is entering the gunship
 * 
 * @return u8 1 if entering, 0 otherwise
 */
u8 GunshipCheckSamusEnter(void)
{
    u16 samusX;
    
    if (!SpriteUtilCheckCrouchingOrMorphed())
    {
        samusX = gSamusData.xPosition;
        if (gCurrentSprite.xPosition - 0x30 < samusX && gCurrentSprite.xPosition + 0x30 > samusX)
        {
            SamusSetPose(SPOSE_TURNING_FROM_FACING_THE_FOREGROUND);
            gSamusData.timer = 0x1;
            gSamusData.standingStatus = STANDING_ENEMY;
            gSamusData.xPosition = gCurrentSprite.xPosition;

            gCurrentSprite.work0 = 0x38;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;
            gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_ON_TOP;
            return TRUE;
        }
    }
    
    return FALSE;
}

/**
 * @brief 44dbc | 1e0 | Initializes a gunship sprite
 * 
 */
void GunshipInit(void)
{
    u8 introCutscene;

    introCutscene = FALSE;

    // Check if landing
    if (gLastDoorUsed == 0x0)
    {
        introCutscene = TRUE;
        gCurrentSprite.yPosition -= BLOCK_SIZE * 6;
        SoundPlay(SOUND_GUNSHIP_LANDING);
    }

    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;

    gCurrentSprite.hitboxTop = -0xC4;
    gCurrentSprite.hitboxBottom = 0x0;
    gCurrentSprite.hitboxLeft = -0x40;
    gCurrentSprite.hitboxRight = 0x40;

    gCurrentSprite.drawDistanceTop = 0x30;
    gCurrentSprite.drawDistanceBottom = 0x8;
    gCurrentSprite.drawDistanceHorizontal = 0x78;

    gCurrentSprite.pOam = sGunshipOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.work2 = 0x8;
    gCurrentSprite.work1 = 0x0;
    gCurrentSprite.work0 = 0x0;
    gCurrentSprite.work3 = 0x0;

    gSubSpriteData1.workVariable3 = FALSE;

    // Spawn entrance
    SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_FRONT, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_BACK, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

    if (gSamusData.pose == SPOSE_SAVING_LOADING_GAME)
    {
        // Loading game from gunship
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_LEAVE;
        gCurrentSprite.work0 = 0x1E;

        gSamusData.timer = 0x0;
        gSamusData.lastWallTouchedMidAir = 0x1;
        gCurrentSprite.yPositionSpawn = 0x154;
        gSubSpriteData1.workVariable3 = TRUE;

        SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_PLATFORM, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
    else if (introCutscene)
    {
        // Landing
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = GUNSHIP_POSE_LANDING;
        gCurrentSprite.work0 = -0x40;

        SamusSetPose(SPOSE_SAVING_LOADING_GAME);
        gSamusData.timer = 0x1;
        gSamusData.lastWallTouchedMidAir = 0x1;

        SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_FLAMES_VERTICAL, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

        UpdateMusicPriority(0x0);
        gHideHud = TRUE;
    }
    else
    {
        // Idle
        SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_PLATFORM, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_SIZE * 3 + HALF_BLOCK_SIZE, gCurrentSprite.xPosition, 0x0);
        
        gCurrentSprite.yPositionSpawn = 0x0;
        gCurrentSprite.samusCollision = SSC_CAN_STAND_ON_TOP;
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
            gCurrentSprite.pose = GUNSHIP_POSE_CHECK_ESCAPE;
        else
            gCurrentSprite.pose = GUNSHIP_POSE_IDLE;
        gCurrentSprite.drawOrder = 0xC;
    }
}

/**
 * @brief 44f9c | 48 | Handles the gunship landing during the intro
 * 
 */
void GunshipLanding(void)
{
    if (gCurrentSprite.work0 != 0x0)
    {
        gCurrentSprite.work0--;
        gCurrentSprite.yPosition += 0x2;
        gSamusData.yPosition = gCurrentSprite.yPosition - 0x4;
        gSamusData.xPosition = gCurrentSprite.xPosition;

        if (gCurrentSprite.work0 == 0x1E)
        {
            // Start intro
            StartEffectForCutscene(EFFECT_CUTSCENE_INTRO_TEXT);
            gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
        }
    }
}

/**
 * @brief 44fe4 | 40 | Handles the gunship being idle
 * 
 */
void GunshipIdle(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP)
    {
        // Check samus entering
        gCurrentSprite.drawOrder = 0x4;
        if (GunshipCheckSamusEnter())
            gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_ENTERING;
    }
    else
        gCurrentSprite.drawOrder = 0xC;
}

/**
 * @brief 45024 | cc | Handles Samus entering the gunship
 * 
 */
void GunshipSamusEntering(void)
{
    u8 ramSlot;

    if (--gCurrentSprite.work0 == 0x0)
    {
        gCurrentSprite.pose = GUNSHIP_POSE_REFILL;
        gCurrentSprite.work0 = 0x41;

        // Check close entrance
        ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_FRONT);
        if (ramSlot != 0xFF)
        {
            gSpriteData[ramSlot].pOam = sGunshipPartOAM_EntranceFrontClosing;
            gSpriteData[ramSlot].animationDurationCounter = 0x0;
            gSpriteData[ramSlot].currentAnimationFrame = 0x0;
            gSpriteData[ramSlot].pose = GUNSHIP_PART_POSE_ENTRANCE_FRONT_OPENING_CLOSING;

            ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_BACK);
            if (ramSlot != 0xFF)
            {
                gSpriteData[ramSlot].pOam = sGunshipPartOAM_EntranceBackClosing;
                gSpriteData[ramSlot].animationDurationCounter = 0x0;
                gSpriteData[ramSlot].currentAnimationFrame = 0x0;
                gSpriteData[ramSlot].pose = GUNSHIP_PART_POSE_ENTRANCE_BACK_OPENING_CLOSING;

                SoundPlay(SOUND_GUNSHIP_CLOSING);
                SoundFade(SOUND_GUNSHIP_PLATFORM_MOVING, CONVERT_SECONDS(1.f / 6)); 
            }
        }
    }
    else if (gCurrentSprite.work0 < 0x2C)
        gSamusData.yPosition += 0x4; // move samus
    else if (gCurrentSprite.work0 == 0x2C)
        SoundPlay(SOUND_GUNSHIP_PLATFORM_MOVING); 
}

/**
 * @brief 450f0 | 15c | Handles the gunship refilling Samus
 * 
 */
void GunshipRefill(void)
{
    if (gCurrentSprite.work0 > 0x6)
    {
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0x6)
        {
            gCurrentSprite.pOam = sGunshipOAM_Refilling;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            SoundPlay(SOUND_GUNSHIP_REFILL);
        }
    }
    else if (gCurrentSprite.work0 == 0x5)
    {
        // Refill energy
        if (!SpriteUtilRefillEnergy())
        {
            gCurrentSprite.work0--;
            gEnergyRefillAnimation = 0xD;
        }
    }
    else if (gCurrentSprite.work0 == 0x4)
    {
        // Refill missiles
        if (gEnergyRefillAnimation != 0x0)
            gEnergyRefillAnimation--;
        else if (!SpriteUtilRefillMissiles())
        {
            gCurrentSprite.work0--;
            if (gEquipment.maxMissiles != 0x0)
                gMissileRefillAnimation = 0xD;
        }
    }
    else if (gCurrentSprite.work0 == 0x3)
    {
        // Refill super missiles
        if (gMissileRefillAnimation != 0x0)
            gMissileRefillAnimation--;
        else if (!SpriteUtilRefillSuperMissiles())
        {
            gCurrentSprite.work0--;
            if (gEquipment.maxSuperMissiles != 0x0)
                gSuperMissileRefillAnimation = 0xD;
        }
    }
    else if (gCurrentSprite.work0 == 0x2)
    {
        // Refill power bombs
        if (gSuperMissileRefillAnimation != 0x0)
            gSuperMissileRefillAnimation--;
        else if (!SpriteUtilRefillPowerBombs())
        {
            gCurrentSprite.work0--;
            if (gEquipment.maxPowerBombs != 0x0)
                gPowerBombRefillAnimation = 0xD;
        }
    }
    else if (gPowerBombRefillAnimation != 0x0)
        gPowerBombRefillAnimation--;
    else if (gCurrentSprite.work0 != 0x0)
        gCurrentSprite.work0--;
    else
    {
        // Spawn item banner
        gCurrentSprite.pose = GUNSHIP_POSE_AFTER_REFILL;
        gCurrentSprite.work0 = 0x1E;

        gCurrentSprite.rotation = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_WEAPONS_AND_ENERGY_RESTORED,
            0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        SoundFade(SOUND_GUNSHIP_REFILL, CONVERT_SECONDS(.25f));
    }
}

/**
 * @brief 4524c | 90 | Handles the behavior of the gunship after a refill
 * 
 */
void GunshipAfterRefill(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.rotation;
    if (gSpriteData[ramSlot].pose == ITEM_BANNER_POSE_REMOVAL_ANIMATION)
    {
        if (gCurrentSprite.work0 != 0x0)
        {
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0x0)
            {
                // Spawn save prompt
                gCurrentSprite.rotation = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_SAVE_PROMPT,
                    0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
            }
        }
        else
        {
            // Check is save prompt
            if (gSpriteData[ramSlot].work1 == TRUE)
            {
                // Saving
                gCurrentSprite.pose = GUNSHIP_POSE_SAVING;
                gCurrentSprite.work0 = 0x1E;
                SoundPlay(SOUND_GUNSHIP_SAVING);
            }
            else
            {
                // Not saving
                gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_LEAVE;
                gCurrentSprite.work0 = 0x1E;
            }
        }
    }
}

/**
 * @brief 452dc | 44 | Handles the gunship saving
 * 
 */
void GunshipSaving(void)
{
    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0x0)
    {
        gCurrentSprite.pose = GUNSHIP_POSE_AFTER_SAVE;
        gCurrentSprite.rotation = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_SAVE_COMPLETE,
            0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 45320 | 38 | Handles the behavior of the gunship after saving
 * 
 */
void GunshipAfterSave(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.rotation;
    if (gSpriteData[ramSlot].pose == ITEM_BANNER_POSE_REMOVAL_ANIMATION)
    {
        // Eject samus
        gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_LEAVE;
        gCurrentSprite.work0 = 0x1E;
    }
}

/**
 * @brief 45358 | b8 | Handles the gunship starting to eject samus
 * 
 */
void GunshipSamusLeave(void)
{
    u8 ramSlot;

    if (--gCurrentSprite.work0 == 0x0)
    {
        gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_LEAVING;
        gCurrentSprite.work0 = 0x2C;
        SoundPlay(SOUND_GUNSHIP_PLATFORM_MOVING);
    }
    else if (gCurrentSprite.work0 == 0xA)
    {
        // Check open entrance
        ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_FRONT);
        if (ramSlot != 0xFF)
        {
            gSpriteData[ramSlot].pOam = sGunshipPartOAM_EntranceFrontOpening;
            gSpriteData[ramSlot].animationDurationCounter = 0x0;
            gSpriteData[ramSlot].currentAnimationFrame = 0x0;

            ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_BACK);
            if (ramSlot != 0xFF)
            {
                gSpriteData[ramSlot].pOam = sGunshipPartOAM_EntranceBackOpening;
                gSpriteData[ramSlot].animationDurationCounter = 0x0;
                gSpriteData[ramSlot].currentAnimationFrame = 0x0;

                gCurrentSprite.pOam = sGunshipOAM_Idle;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;

                SoundPlay(SOUND_GUNSHIP_OPENING);
            }
        }
    }
}

/**
 * @brief 45410 | 28 | Handles samus leaving the gunship
 * 
 */
void GunshipSamusLeaving(void)
{
    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0x0)
    {
        if (gHideHud)
        {
            gCurrentSprite.pose = GUNSHIP_POSE_DO_NOTHING;
            gCurrentSprite.work0 = 0x32;
        }
        else
            gCurrentSprite.pose = GUNSHIP_POSE_RELEASE_SAMUS;
        SoundFade(SOUND_GUNSHIP_PLATFORM_MOVING, CONVERT_SECONDS(1.f / 6));
    }
    else
        gSamusData.yPosition -= 0x4;
}

/**
 * @brief 45468 | 24 | Handles the gunship releasing samus
 * 
 */
void GunshipReleaseSamus(void)
{
    if (gCurrentSprite.yPositionSpawn == 0x0)
    {
        SamusSetPose(SPOSE_FACING_THE_FOREGROUND);
        gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_RELEASED;
    }
}

/**
 * @brief 4548c | 28 | Called after samus is released
 * 
 */
void GunshipSamusReleased(void)
{
    if (gSamusData.pose != SPOSE_FACING_THE_FOREGROUND)
    {
        gCurrentSprite.pose = GUNSHIP_POSE_CHECK_SAMUS_ON_TOP_AFTER_RELEASED;
        gCurrentSprite.samusCollision = SSC_CAN_STAND_ON_TOP;
    }
}

/**
 * @brief 454b4 | 28 | Checks if samus is still on the gunship after being released
 * 
 */
void GunshipCheckSamusOnTopAfterLeaving(void)
{
    if (!(gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP))
    {
        gCurrentSprite.drawOrder = 0xC;
        gCurrentSprite.pose = GUNSHIP_POSE_IDLE;
    }
}

/**
 * @brief 454dc | 50 | Checks if samus should escape
 * 
 */
void GunshipCheckEscapeZebes(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP && GunshipCheckSamusEnter())
    {
        // Samus entering ship

        gCurrentSprite.drawOrder = 0x4;
        gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_ENTERING_WHEN_ESCAPING;

        // Set event and update minimap
        EventFunction(EVENT_ACTION_SETTING, EVENT_ESCAPED_ZEBES);
        MinimapUpdateChunk(EVENT_ESCAPED_ZEBES);
        SoundFade(SOUND_ESCAPE_BEEP, CONVERT_SECONDS(1.f));
        UpdateMusicPriority(0x0);
    }
}

/**
 * @brief 4552c | e4 | Handles samus entering the gunship when escaping
 * 
 */
void GunshipSamusEnteringWhenEscaping(void)
{
    u8 ramSlot;

    if (--gCurrentSprite.work0 == 0x0)
    {
        gCurrentSprite.pose = GUNSHIP_POSE_START_ESCAPING;
        gCurrentSprite.work0 = 0x78;

        // Check close entrance
        ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_FRONT);
        if (ramSlot != 0xFF)
        {
            gSpriteData[ramSlot].pOam = sGunshipPartOAM_EntranceFrontClosing;
            gSpriteData[ramSlot].animationDurationCounter = 0x0;
            gSpriteData[ramSlot].currentAnimationFrame = 0x0;
            gSpriteData[ramSlot].pose = GUNSHIP_PART_POSE_ENTRANCE_FRONT_OPENING_CLOSING;

            ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_BACK);
            if (ramSlot != 0xFF)
            {
                gSpriteData[ramSlot].pOam = sGunshipPartOAM_EntranceBackClosing;
                gSpriteData[ramSlot].animationDurationCounter = 0x0;
                gSpriteData[ramSlot].currentAnimationFrame = 0x0;
                gSpriteData[ramSlot].pose = GUNSHIP_PART_POSE_ENTRANCE_BACK_OPENING_CLOSING;

                ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_PLATFORM);
                if (ramSlot != 0xFF)
                {
                    gSpriteData[ramSlot].status = 0x0;

                    SoundPlay(SOUND_GUNSHIP_CLOSING);
                    SoundFade(SOUND_GUNSHIP_PLATFORM_MOVING, CONVERT_SECONDS(1.f / 6));
                }
            }
        }
    }
    else if (gCurrentSprite.work0 < 0x2C)
        gSamusData.yPosition += 0x4;
    else if (gCurrentSprite.work0 == 0x2C)
        SoundPlay(SOUND_GUNSHIP_PLATFORM_MOVING); 
}

/**
 * @brief 45610 | 78 | Handles the gunship starting to escape
 * 
 */
void GunshipStartEscaping(void)
{
    if (--gCurrentSprite.work0 == 0x0)
    {
        // Set taking off
        gCurrentSprite.pose = GUNSHIP_POSE_TAKING_OFF;
        gCurrentSprite.work0 = 0x98;
        gCurrentSprite.work3 = 0x0;
        gCurrentSprite.scaling = 0x0;

        // Spawn flames
        SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_FLAMES_HORIZONTAL, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
    else if (gCurrentSprite.work0 == 0x4)
    {
        gCurrentSprite.pOam = sGunshipOAM_Flying;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        SoundPlay(SOUND_GUNSHIP_FLYING_OFF);
    }
}

/**
 * @brief 45688 | 80 | Handles the gunship taking off before flying
 * 
 */
void GunshipTakingOff(void)
{
    u8 offset;
    s32 movement;

    GunshipFlickerFlames();

    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0x0)
        GUNSHIP_START_FLYING(0xA0);
    else
    {
        offset = gCurrentSprite.work3;
        movement = sGunshipTakingOffYVelocity[offset];
        if (movement == SHORT_MAX)
        {
            movement = sGunshipTakingOffYVelocity[offset - 1];
            gCurrentSprite.yPosition += movement;
            gSamusData.yPosition += movement;
            
        }
        else
        {
            gCurrentSprite.work3++;
            gCurrentSprite.yPosition += movement;
            gSamusData.yPosition += movement;
        }
    }
}

/**
 * @brief 45708 | 8c | Handles the ship flying when escaping
 * 
 */
void GunshipFlying(void)
{
    u8 offset;
    s32 movement;

    if (--gCurrentSprite.work0 == 0x0)
        gCurrentSprite.pose = GUNSHIP_POSE_DO_NOTHING_ESCAPE;
    else
    {
        if (gCurrentSprite.work0 == 0x32)
        {
            StartEffectForCutscene(EFFECT_CUTSCENE_EXITING_ZEBES);
            gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
        }

        GunshipFlickerFlames();

        offset = gCurrentSprite.work3;
        movement = sGunshipFlyingYVelocity[offset];
        if (movement == SHORT_MAX)
        {
            movement = sGunshipFlyingYVelocity[offset - 1];
            gCurrentSprite.yPosition += movement;
            gSamusData.yPosition += movement;
            
        }
        else
        {
            gCurrentSprite.work3 = offset + 0x1;
            gCurrentSprite.yPosition += movement;
            gSamusData.yPosition += movement;
        }
    }
}

/**
 * @brief 45794 | 1a0 | Initializes a gunship part sprite
 * 
 */
void GunshipPartInit(void)
{
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    gCurrentSprite.hitboxTop = 0x0;
    gCurrentSprite.hitboxBottom = 0x0;
    gCurrentSprite.hitboxLeft = 0x0;
    gCurrentSprite.hitboxRight = 0x0;

    switch (gCurrentSprite.roomSlot)
    {
        case GUNSHIP_PART_ENTRANCE_FRONT:
            gCurrentSprite.drawDistanceTop = 0x38;
            gCurrentSprite.drawDistanceBottom = 0x0;
            gCurrentSprite.drawDistanceHorizontal = 0x28;
            
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontClosed;

            if (gSamusData.pose == SPOSE_SAVING_LOADING_GAME)
                gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_FRONT_OPENING_CLOSING;
            else
                gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_FRONT_IDLE;
            break;

        case GUNSHIP_PART_ENTRANCE_BACK:
            gCurrentSprite.drawDistanceTop = 0x40;
            gCurrentSprite.drawDistanceBottom = 0x0;
            gCurrentSprite.drawDistanceHorizontal = 0x20;

            gCurrentSprite.drawOrder = 0xE;
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackClosed;

            if (gSamusData.pose == SPOSE_SAVING_LOADING_GAME)
                gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_BACK_OPENING_CLOSING;
            else
                gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_BACK_IDLE;
            break;

        case GUNSHIP_PART_PLATFORM:
            gCurrentSprite.drawDistanceTop = 0x0;
            gCurrentSprite.drawDistanceBottom = 0x8;
            gCurrentSprite.drawDistanceHorizontal = 0x10;

            gCurrentSprite.drawOrder = 0xD;
            gCurrentSprite.pOam = sGunshipPartOAM_Platform;

            if (gSamusData.pose == SPOSE_SAVING_LOADING_GAME)
            {
                gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_DOWN;
                gCurrentSprite.yPosition += -0x18;
            }
            else
                gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_UP;
            break;

        case GUNSHIP_PART_FLAMES_HORIZONTAL:
            gCurrentSprite.drawDistanceTop = 0x18;
            gCurrentSprite.drawDistanceBottom = 0x30;
            gCurrentSprite.drawDistanceHorizontal = 0x60;

            gCurrentSprite.drawOrder = 0xF;
            gCurrentSprite.pOam = sGunshipPartOAM_FlamesHorizontal;
            gCurrentSprite.pose = GUNSHIP_PART_POSE_CHECK_SET_VERTICAL_FLAMES;
            break;

        case GUNSHIP_PART_FLAMES_VERTICAL:
            gCurrentSprite.drawDistanceTop = 0x18;
            gCurrentSprite.drawDistanceBottom = 0x30;
            gCurrentSprite.drawDistanceHorizontal = 0x60;

            gCurrentSprite.drawOrder = 0xF;
            gCurrentSprite.pOam = sGunshipPartOAM_FlamesVertical;
            gCurrentSprite.pose = GUNSHIP_PART_POSE_CHECK_SET_HORIZONTAL_FLAMES;
            gCurrentSprite.work0 = 0x50;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 45934 | 40 | Checks if the horizontal flames should become the vertical flames
 * 
 */
void GunshipPartCheckSetVerticalFlames(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[ramSlot].pose == GUNSHIP_POSE_FLYING)
    {
        gCurrentSprite.pOam = sGunshipPartOAM_FlamesVertical;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = GUNSHIP_PART_POSE_VERTICAL_FLAME_IDLE;
    }
}

/**
 * @brief 45974 | 38 | Checks if the vertical flames should become the horizontal flames
 * 
 */
void GunshipPartCheckSetHorizontalFlames(void)
{
    if (gCurrentSprite.work0 != 0x0)
    {
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0x0)
        {
            gCurrentSprite.pOam = sGunshipPartOAM_FlamesHorizontal;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.work0 = 0xF;
            gCurrentSprite.pose = GUNSHIP_PART_POSE_CHECK_SET_VERTICAL_FLAMES_BEFORE_LANDING;
        }
    }
}

/**
 * @brief 459ac | 38 | Checks if the horizontal flames should become the vertical flames (before landing)
 * 
 */
void GunshipPartCheckSetVerticalFlamesBeforeLanding(void)
{
    if (gCurrentSprite.work0 != 0x0)
    {
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0x0)
        {
            gCurrentSprite.pOam = sGunshipPartOAM_FlamesVertical;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.work0 = 0xA;
            gCurrentSprite.pose = GUNSHIP_PART_POSE_CHECK_SET_HORIZONTAL_FLAMES_BEFORE_LANDING;
        }
    }
}

/**
 * @brief 459e4 | 5c | Checks if the vertical flames should become the horizontal flames (before landing)
 * 
 */
void GunshipPartCheckSetHorizontalFlamesBeforeLanding(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (gCurrentSprite.work0 != 0x0)
    {
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0x0)
        {
            gCurrentSprite.pOam = sGunshipPartOAM_FlamesHorizontal;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }

    if (gSpriteData[ramSlot].pose == GUNSHIP_POSE_UNKNOWN)
    {
        gCurrentSprite.pose = GUNSHIP_PART_POSE_FLICKER_FLAMES_UNUSED;
        gCurrentSprite.work0 = 0x3C;
    }
}

/**
 * @brief 45a40 | 28 | Flickers the flames, unused
 * 
 */
void GunshipPartFlickFlames_Unused(void)
{
    gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0x0)
        gCurrentSprite.status = 0x0;
}

/**
 * @brief 45a68 | a8 | Handles the front part of the entrance being idle
 * 
 */
void GunshipPartEntranceFrontIdle(void)
{
    if (gSubSpriteData1.workVariable3 == TRUE)
    {
        if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceFrontClosed)
        {
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontOpening;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
        else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceFrontOpening)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontOpened;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
            }
        }
        else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceFrontClosing)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontOpening;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
            }
        }
    }
    else
    {
        if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceFrontOpened)
        {
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontClosing;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
        else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceFrontClosing)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontClosed;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
            }
        }
        else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceFrontOpening)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontClosing;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
            }            
        }
    }
}

/**
 * @brief 45b10 | 5c | Handles the front part of the entrance opening/closing
 * 
 */
void GunshipPartEntranceFrontOpenClose(void)
{
    if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceFrontClosing)
    {
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontClosed;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }
    else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceFrontOpening)
    {
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceFrontOpened;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_FRONT_IDLE;
        }
    }
}

/**
 * @brief 45b6c | f8 | Handles the back part of the entrance being idle
 * 
 */
void GunshipPartEntranceBackIdle(void)
{
    if (gSubSpriteData1.workVariable3 == TRUE)
    {
        if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceBackClosed)
        {
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackOpening;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(SOUND_GUNSHIP_OPENING);
        }
        else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceBackOpening)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackOpened;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
            }
        }
        else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceBackClosing)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackOpening;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                SoundPlay(SOUND_GUNSHIP_OPENING);
            }
        }
    }
    else
    {
        if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceBackOpened)
        {
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackClosing;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            SoundPlay(SOUND_GUNSHIP_CLOSING);
        }
        else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceBackClosing)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackClosed;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
            }
        }
        else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceBackOpening)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackClosing;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                SoundPlay(SOUND_GUNSHIP_CLOSING);
            }
        }
    }
}

/**
 * @brief 45c64 | 5c | Handles the back part of the entrance opening/closing
 * 
 */
void GunshipPartEntranceBackOpenClose(void)
{
    if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceBackClosing)
    {
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackClosed;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }
    else if (gCurrentSprite.pOam == sGunshipPartOAM_EntranceBackOpening)
    {
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.pOam = sGunshipPartOAM_EntranceBackOpened;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_BACK_IDLE;
        }
    }
}

/**
 * @brief 45cc0 | 54 | Checks if the platform should go up
 * 
 */
void GunshipPartCheckPlatformGoUp(void)
{
    u8 ramSlot;

    ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_BACK);
    if (ramSlot != 0xFF && gSubSpriteData1.workVariable3 == TRUE && gSpriteData[ramSlot].pOam == sGunshipPartOAM_EntranceBackOpening)
    {
        gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_GO_UP;
        gCurrentSprite.work0 = 0x8;
    }
}

/**
 * @brief 45d14 | 50 | Handles the platform moving up
 * 
 */
void GunshipPartPlatformGoUp(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (gCurrentSprite.work0 != 0x0)
        gCurrentSprite.work0--;
    else
    {
        if (gSpriteData[ramSlot].yPosition - (BLOCK_SIZE * 3 + 4) > gCurrentSprite.yPosition)
        {
            gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - (BLOCK_SIZE * 3 + 4);
            gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_DOWN;
        }
        else
            gCurrentSprite.yPosition -= 0x4;
    }
}

/**
 * @brief 45d64 | 98 | Checks if the platform should go down
 * 
 */
void GunshipPartCheckPlatformGoDown(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (!gSubSpriteData1.workVariable3)
    {
        gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_GO_DOWN;
        gCurrentSprite.work0 = 0x8;
    }
    else if (gSpriteData[ramSlot].pose == GUNSHIP_POSE_SAMUS_ENTERING && gSpriteData[ramSlot].work0 < 0x2C)
        gCurrentSprite.yPosition += 0x4;
    else if (gSpriteData[ramSlot].pose == GUNSHIP_POSE_SAMUS_LEAVING && gSpriteData[ramSlot].work0 < 0x2C)
        gCurrentSprite.yPosition -= 0x4;
    else if (gSpriteData[ramSlot].pose == GUNSHIP_POSE_SAMUS_ENTERING_WHEN_ESCAPING && gSpriteData[ramSlot].work0 < 0x2C)
        gCurrentSprite.yPosition += 0x4;
}

/**
 * @brief 45dfc | 50 | Handles the platform moving down 
 * 
 */
void GunshipPartPlatformGoDown(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (gCurrentSprite.work0 != 0x0)
        gCurrentSprite.work0--;
    else
    {
        if (gSpriteData[ramSlot].yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE) < gCurrentSprite.yPosition)
        {
            gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition -  (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_UP;
        }
        else
            gCurrentSprite.yPosition += 0x4;
    }
}

/**
 * @brief 45e4c | 24c | Gunship AI
 * 
 */
void Gunship(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            GunshipInit();
            break;

        case GUNSHIP_POSE_IDLE:
            GunshipIdle();
            break;

        case GUNSHIP_POSE_SAMUS_ENTERING:
            GunshipSamusEntering();
            break;

        case GUNSHIP_POSE_REFILL:
            GunshipRefill();
            break;

        case GUNSHIP_POSE_AFTER_REFILL:
            GunshipAfterRefill();
            break;

        case GUNSHIP_POSE_SAMUS_LEAVE:
            GunshipSamusLeave();
            break;

        case GUNSHIP_POSE_SAMUS_LEAVING:
            GunshipSamusLeaving();
            break;

        case GUNSHIP_POSE_RELEASE_SAMUS:
            GunshipReleaseSamus();
            break;

        case GUNSHIP_POSE_SAMUS_RELEASED:
            GunshipSamusReleased();
            break;

        case GUNSHIP_POSE_CHECK_SAMUS_ON_TOP_AFTER_RELEASED:
            GunshipCheckSamusOnTopAfterLeaving();
            break;

        case GUNSHIP_POSE_SAVING:
            GunshipSaving();
            break;

        case GUNSHIP_POSE_AFTER_SAVE:
            GunshipAfterSave();
            break;

        case GUNSHIP_POSE_CHECK_ESCAPE:
            GunshipCheckEscapeZebes();
            break;

        case GUNSHIP_POSE_SAMUS_ENTERING_WHEN_ESCAPING:
            GunshipSamusEnteringWhenEscaping();
            break;

        case GUNSHIP_POSE_START_ESCAPING:
            GunshipStartEscaping();
            break;

        case GUNSHIP_POSE_TAKING_OFF:
            GunshipTakingOff();
            break;

        case GUNSHIP_POSE_FLYING:
            GunshipFlying();
            break;

        case GUNSHIP_POSE_LANDING:
            GunshipLanding();
            break;
    }

    // Check set samus near flag
    if (!gSubSpriteData1.workVariable3)
    {
        // Check set
        if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 20, BLOCK_SIZE * 7) != NSLR_OUT_OF_RANGE)
            gSubSpriteData1.workVariable3 = TRUE;
    }
    else
    {
        // Check remove
        if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 20, BLOCK_SIZE * 9) == NSLR_OUT_OF_RANGE)
            gSubSpriteData1.workVariable3 = FALSE;
    }

    GunshipEntranceFlashingAnim();

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ESCAPED_ZEBES) && gCurrentSprite.yPositionSpawn != 0x0)
    {
        gCurrentSprite.yPositionSpawn--;
        if (gCurrentSprite.yPositionSpawn == 0x0)
            gDisablePause = FALSE;
    }
}

/**
 * @brief 46098 | 1e4 | Gunship part AI
 * 
 */
void GunshipPart(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (gCurrentSprite.roomSlot == GUNSHIP_PART_ENTRANCE_FRONT)
    {
        if (gSpriteData[ramSlot].drawOrder == 0x4)
            gCurrentSprite.drawOrder = 0x3;
        else
            gCurrentSprite.drawOrder = 0xB;
    }

    if (gCurrentSprite.roomSlot != GUNSHIP_PART_PLATFORM)
    {
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
        gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            GunshipPartInit();
            break;

        case GUNSHIP_PART_POSE_ENTRANCE_FRONT_IDLE:
            GunshipPartEntranceFrontIdle();
            break;

        case GUNSHIP_PART_POSE_ENTRANCE_FRONT_OPENING_CLOSING:
            GunshipPartEntranceFrontOpenClose();
            break;

        case GUNSHIP_PART_POSE_ENTRANCE_BACK_IDLE:
            GunshipPartEntranceBackIdle();
            break;

        case GUNSHIP_PART_POSE_ENTRANCE_BACK_OPENING_CLOSING:
            GunshipPartEntranceBackOpenClose();
            break;

        case GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_UP:
            GunshipPartCheckPlatformGoUp();
            break;

        case GUNSHIP_PART_POSE_PLATFORM_GO_UP:
            GunshipPartPlatformGoUp();
            break;

        case GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_DOWN:
            GunshipPartCheckPlatformGoDown();
            break;

        case GUNSHIP_PART_POSE_PLATFORM_GO_DOWN:
            GunshipPartPlatformGoDown();
            break;

        case GUNSHIP_PART_POSE_CHECK_SET_VERTICAL_FLAMES:
            GunshipPartCheckSetVerticalFlames();
            break;

        case GUNSHIP_PART_POSE_CHECK_SET_HORIZONTAL_FLAMES:
            GunshipPartCheckSetHorizontalFlames();
            break;

        case GUNSHIP_PART_POSE_CHECK_SET_VERTICAL_FLAMES_BEFORE_LANDING:
            GunshipPartCheckSetVerticalFlamesBeforeLanding();
            break;

        case GUNSHIP_PART_POSE_CHECK_SET_HORIZONTAL_FLAMES_BEFORE_LANDING:
            GunshipPartCheckSetHorizontalFlamesBeforeLanding();
            break;

        case GUNSHIP_PART_POSE_FLICKER_FLAMES_UNUSED:
            GunshipPartFlickFlames_Unused();
            break;
    }
}