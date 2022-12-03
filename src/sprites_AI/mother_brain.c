#include "sprites_AI/mother_brain.h"
#include "sprites_AI/item_banner.h"

#include "data/frame_data_pointers.h"
#include "data/sprites/mother_brain.h"
#include "data/sprites/zebetite_and_cannon.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/game_state.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/in_game_timer.h"
#include "structs/samus.h"
#include "structs/scroll.h"
#include "structs/sprite.h"

/**
 * @brief 3c964 | 68 | Synchronize the sub sprites of Mother Brain
 * 
 */
void MotherBrainSyncSubSpritesPosition(void)
{
    const u16 (*pFrame)[3];
    u32 offset;

    pFrame = (const u16 (*)[3])gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pFrame;
    offset = pFrame[gCurrentSprite.roomSlot][0]; // Frame data ID

    if (gCurrentSprite.pOam != sMotheBrainFrameDataPointers[offset])
    {
        gCurrentSprite.pOam = sMotheBrainFrameDataPointers[offset];
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pFrame[gCurrentSprite.roomSlot][1]; // Y offset
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pFrame[gCurrentSprite.roomSlot][2]; // X offset
}

/**
 * @brief 3c9cc | 80 | Updates the palette of mother brain when firing
 * 
 */
void MotherBrainUpdatePalette(void)
{
    u8 timer;
    u8 offset;
    u8 newTimer;

    if (gCurrentSprite.oamScaling != 0x0)
    {
        gCurrentSprite.oamScaling--;
        gCurrentSprite.paletteRow = sMotherBrainDynamicPaletteData[gCurrentSprite.oamRotation][0];
    }
    else
    {
        offset = gCurrentSprite.oamRotation++;
        timer = sMotherBrainDynamicPaletteData[offset][0];
        if (timer == 0x80)
        {
            gCurrentSprite.oamRotation = 0x1;
            offset = 0x0;
            timer = sMotherBrainDynamicPaletteData[offset][0];
        }

        newTimer = sMotherBrainDynamicPaletteData[offset][1];
        if (offset == 0x0 || offset == 0x6)
            SoundPlay(0x2BB);

        gCurrentSprite.paletteRow = timer;
        gCurrentSprite.oamScaling = newTimer;
    }
}

/**
 * @brief 3ca4c | 144 | Initializes mother brain
 * 
 */
void MotherBrainInit(void)
{
    u8 gfxSlot;
    u8 ramSlot;
    u16 yPosition;
    u16 xPosition;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ESCAPED_ZEBES) || EventFunction(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.xPosition += 0x20;
        gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

        yPosition = gSubSpriteData1.yPosition;
        xPosition = gSubSpriteData1.xPosition;
        gBossWork.work1 = yPosition;
        gBossWork.work2 = xPosition;
        gBossWork.work3 = 0x0;
        gBossWork.work4 = 0x0;
        gBossWork.work5 = 0x0;

        gCurrentSprite.drawDistanceTopOffset = 0x28;
        gCurrentSprite.drawDistanceBottomOffset = 0x20;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x30;

        gCurrentSprite.hitboxTopOffset = -0x70;
        gCurrentSprite.hitboxBottomOffset = 0x60;
        gCurrentSprite.hitboxLeftOffset = -0xA0;
        gCurrentSprite.hitboxRightOffset = 0x80;

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
        gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
        gCurrentSprite.timer = 0x0;
        gCurrentSprite.workVariable = 0x0;
        gCurrentSprite.oamScaling = 0x0;
        gCurrentSprite.oamRotation = 0x0;
        gCurrentSprite.workVariable2 = 0x0;
        
        gSubSpriteData1.pMultiOam = sMotherBrainMultiSpriteData;
        gSubSpriteData1.animationDurationCounter = 0x0;
        gSubSpriteData1.currentAnimationFrame = 0x0;
        gSubSpriteData1.workVariable3 = 0x0;

        gCurrentSprite.pose = MOTHER_BRAIN_POSE_WAITING_GLASS;
        gCurrentSprite.roomSlot = 0x1;

        gfxSlot = gCurrentSprite.spritesetGFXSlot;
        ramSlot = gCurrentSprite.primarySpriteRAMSlot;

        gSubSpriteData1.workVariable4 = SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_PART, MOTHER_BRAIN_PART_BEAM_SHOOTER,
            gfxSlot, ramSlot, yPosition, xPosition, 0x0);

        gSubSpriteData1.workVariable5 = SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_PART, MOTHER_BRAIN_PART_EYE,
            gfxSlot, ramSlot, yPosition, xPosition, 0x0);

        gSubSpriteData1.workVariable6 = SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_PART, MOTHER_BRAIN_PART_BOTTOM,
            gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    }
}

/**
 * @brief 3cb90 | 6c | Checks if the glass breaked, starts battle behaviors
 * 
 */
void MotherBrainCheckGlassBreaked(void)
{
    u8 eyeRamSlot;

    eyeRamSlot = gSubSpriteData1.workVariable5;
    if (gSubSpriteData1.workVariable3 == 0x1)
    {
        gCurrentSprite.pose = MOTHER_BRAIN_POSE_MAIN_LOOP;
        gSpriteData[eyeRamSlot].health = gCurrentSprite.health;
        gBossWork.work4 = gCurrentSprite.health;
        // Open eye
        gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOAM_EyeOpening;
        gSpriteData[eyeRamSlot].animationDurationCounter = 0x0;
        gSpriteData[eyeRamSlot].currentAnimationFrame = 0x0;
        SoundPlay(0x2B9); // Mother brain eye open
    }
}

/**
 * @brief 3cbfc | 3fc | Mother brain main behavior loop
 * 
 */
void MotherBrainMainLoop(void)
{
    u8 palette;
    u8 beamShooterRamSlot;
    u8 eyeRamSlot;
    u8 bottomRamSlot;
    u32 counter;

    beamShooterRamSlot = gSubSpriteData1.workVariable4;
    eyeRamSlot = gSubSpriteData1.workVariable5;
    bottomRamSlot = gSubSpriteData1.workVariable6;
    palette = gSpriteData[eyeRamSlot].paletteRow;
    
    gCurrentSprite.paletteRow = palette;
    gSpriteData[bottomRamSlot].paletteRow = palette;

    if (gSpriteData[eyeRamSlot].health == 0x0)
    {
        // Set dying behavior
        gCurrentSprite.pose = MOTHER_BRAIN_POSE_DYING;
        gCurrentSprite.pOam = sMotherBrainOAM_ChargingBeam;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.invincibilityStunFlashTimer = 0x78;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.health = 0x1;
        gCurrentSprite.paletteRow = 0x0;

        gSpriteData[eyeRamSlot].paletteRow = 0x0;
        gSpriteData[bottomRamSlot].paletteRow = 0x0;
               
        gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOAM_EyeDying;
        gSpriteData[eyeRamSlot].animationDurationCounter = 0x0;
        gSpriteData[eyeRamSlot].currentAnimationFrame = 0x0;
        gSpriteData[eyeRamSlot].samusCollision = SSC_NONE;

        gSpriteData[beamShooterRamSlot].status = 0x0;
        gSubSpriteData1.workVariable3 = 0x2;
        // Set event
        EventFunction(EVENT_ACTION_SETTING, EVENT_MOTHER_BRAIN_KILLED);
        SoundPlay(0x2BF); // Mother brain dying
        return;
    }

    if (gCurrentSprite.pOam == sMotherBrainOAM_ChargingBeam)
    {
        // delay before charging
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            gCurrentSprite.pOam = sMotherBrainOAM_Idle;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }
    else
    {
        if (gCurrentSprite.currentAnimationFrame == 0x1 && gCurrentSprite.animationDurationCounter == 0x1)
            SoundPlay(0x2BD); // Mother brain idle

        if ((gSpriteData[eyeRamSlot].invincibilityStunFlashTimer & 0x7F) == 0x10)
        {
            SoundPlay(0x2BE); // Mother brain hurt
            if (gSpriteData[eyeRamSlot].health < gBossWork.work4)
            {
                // Damage dealt, check should close eye
                // Add damage to counter
                gBossWork.work5 += (gBossWork.work4 - gSpriteData[eyeRamSlot].health);
                gBossWork.work4 = gSpriteData[eyeRamSlot].health;

                // Get counter threshold
                if (gDifficulty == DIFF_EASY)
                    counter = 0xC8;
                else if (gDifficulty == DIFF_HARD)
                    counter = 0x3C;
                else
                    counter = 0x64;

                if (gBossWork.work5 >= counter)
                {
                    // Set closing behavior
                    gBossWork.work5 = 0x0;
                    gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOAM_EyeClosing;
                    gSpriteData[eyeRamSlot].animationDurationCounter = 0x0;
                    gSpriteData[eyeRamSlot].currentAnimationFrame = 0x0;
                    gSpriteData[eyeRamSlot].properties |= SP_IMMUNE_TO_PROJECTILES;
                    SoundPlay(0x2BA); // Mother brain eye closing
                    gCurrentSprite.workVariable2 = 0x1;
                }
            }
        }
    }

    if (gSpriteData[eyeRamSlot].pOam == sMotherBrainPartOAM_EyeClosing)
    {
        // Check should close
        if (SpriteUtilCheckEndSpriteAnim(eyeRamSlot))
        {
            gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOAM_EyeClosed;
            gSpriteData[eyeRamSlot].animationDurationCounter = 0x0;
            gSpriteData[eyeRamSlot].currentAnimationFrame = 0x0;
        }
    }
    else if (gSpriteData[eyeRamSlot].pOam == sMotherBrainPartOAM_EyeClosed)
    {
        // Check should start charging beam
        if (gSubSpriteData1.yPosition + (BLOCK_SIZE * 2) >= gSamusData.yPosition)
        {
            gCurrentSprite.workVariable2--; // Delay
            if (gCurrentSprite.workVariable2 == 0x0)
            {
                // Set charging beam behavior
                gCurrentSprite.pOam = sMotherBrainOAM_ChargingBeam;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;

                gCurrentSprite.workVariable = 0x48;
                gCurrentSprite.timer = 0x48;
                gCurrentSprite.oamScaling = 0x0;
                gCurrentSprite.oamRotation = 0x0;
            }
        }
    }
    else if (gSpriteData[eyeRamSlot].pOam == sMotherBrainPartOAM_EyeOpening)
    {
        if (gCurrentSprite.workVariable == 0x0)
        {
            // Check should close eye
            if (gSubSpriteData1.yPosition + (BLOCK_SIZE * 2) < gSamusData.yPosition)
            {
                // Samus fell below the blocks, set closing behavior
                gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOAM_EyeClosing;
                gSpriteData[eyeRamSlot].animationDurationCounter = 0x0;
                gSpriteData[eyeRamSlot].currentAnimationFrame = 0x0;
                gSpriteData[eyeRamSlot].properties |= SP_IMMUNE_TO_PROJECTILES;
                SoundPlay(0x2BA); // Mother brain eye close
                gCurrentSprite.workVariable2 = 0x3C;
            }
            return;
        }
    }

    if (gCurrentSprite.workVariable == 0x0)
        return;
   
    // Shooting beam
    if (gCurrentSprite.workVariable-- == 0x1)
    {
        if (palette != 0xE)
        {
            // Set normal palette
            gCurrentSprite.paletteRow = 0x0;
            gSpriteData[eyeRamSlot].paletteRow = 0x0;
            gSpriteData[bottomRamSlot].paletteRow = 0x0;
        }
    }
    else
    {
        if (gCurrentSprite.workVariable == 0xC)
        {
            // Spawn beam
            SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_BEAM, 0x0, gCurrentSprite.spritesetGFXSlot,
                gCurrentSprite.primarySpriteRAMSlot, gSpriteData[beamShooterRamSlot].yPosition,
                gSpriteData[beamShooterRamSlot].xPosition + 0xCC, 0x0);

            // Hide beam shooter
            gSpriteData[beamShooterRamSlot].status |= SPRITE_STATUS_NOT_DRAWN;
        }
        else if (gCurrentSprite.workVariable == 0x14)
        {
            // Open eye
            gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOAM_EyeOpening;
            gSpriteData[eyeRamSlot].animationDurationCounter = 0x0;
            gSpriteData[eyeRamSlot].currentAnimationFrame = 0x0;
            // Make eye vulnerable
            gSpriteData[eyeRamSlot].properties &= ~SP_IMMUNE_TO_PROJECTILES;
            SoundPlay(0x2B9); // Mother brain eye open
        }
        else if (gCurrentSprite.workVariable == 0x18)
        {
            // Set beam shooter behavior
            gSpriteData[beamShooterRamSlot].pOam = sMotherBrainPartOAM_BeamSpawning;
            gSpriteData[beamShooterRamSlot].animationDurationCounter = 0x0;
            gSpriteData[beamShooterRamSlot].currentAnimationFrame = 0x0;
            gSpriteData[beamShooterRamSlot].status &= ~SPRITE_STATUS_NOT_DRAWN;
            SoundPlay(0x2BC);
        }

        if (palette != 0xE)
        {
            // Update palette
            MotherBrainUpdatePalette();
            gSpriteData[eyeRamSlot].paletteRow = gCurrentSprite.paletteRow;
            gSpriteData[bottomRamSlot].paletteRow = gCurrentSprite.paletteRow;
        }
    }
}

/**
 * @brief 3cff8 | cc | Handles the death of mother brain
 * 
 */
void MotherBrainDeath(void)
{
    u8 bottomRamSlot;
    u8 eyeRamSlot;

    eyeRamSlot = gSubSpriteData1.workVariable5;
    bottomRamSlot = gSubSpriteData1.workVariable6;

    if (gCurrentSprite.invincibilityStunFlashTimer != 0x0)
    {
        gSpriteData[eyeRamSlot].paletteRow = gCurrentSprite.paletteRow;
        gSpriteData[bottomRamSlot].paletteRow = gCurrentSprite.paletteRow;
        if (!(gCurrentSprite.invincibilityStunFlashTimer & 0x3F))
            make_background_flash(0x3); // Quick flash || Undefined
    }
    else
    {
        gSpriteData[eyeRamSlot].status = 0x0;
        gSpriteData[bottomRamSlot].status = 0x0;
        gCurrentSprite.pose = MOTHER_BRAIN_POSE_START_ESCAPE;
        gCurrentSprite.timer = 0x3C;
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        ParticleSet(gSubSpriteData1.yPosition + 0x46, gSubSpriteData1.xPosition - 0x3C, PE_MAIN_BOSS_DEATH);
        ParticleSet(gSubSpriteData1.yPosition + 0x3C, gSubSpriteData1.xPosition + 0x50, PE_MAIN_BOSS_DEATH);
        gInGameTimerAtBosses[1] = gInGameTimer;
        SoundPlay(0x2C0); // Mother brain death explosion
        make_background_flash(0x3); // Quick flash || Undefined
    }
}

/**
 * @brief 3d0c4 | 6c | Starts the escape
 * 
 */
void MotherBrainStartEscape(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        // Kill sprite
        gCurrentSprite.status = 0x0;
        // Spawn banner and effects
        SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_ZEBES_ESCAPE, 0x0, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        SpriteSpawnPrimary(PSPRITE_EXPLOSION_ZEBES_ESCAPE, 0x0, 0x0, gCurrentSprite.yPosition + (BLOCK_SIZE * 4), gCurrentSprite.xPosition, 0x0);
        MusicPlay(MUSIC_ESCAPE, 0x40);
        SoundPlay(0x120);
        gSubSpriteData1.workVariable3 = 0x3;
    }
}

/**
 * @brief 3d130 | 158 | Initializes a mother brain part sprite
 * 
 */
void MotherBrainPartInit(void)
{
    u16 health;
    
    switch (gCurrentSprite.roomSlot)
    {
        case MOTHER_BRAIN_PART_BEAM_SHOOTER:
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x40;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4,
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.pose = 0x32;

            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.health = 0x1;
            break;

        case MOTHER_BRAIN_PART_EYE:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            gCurrentSprite.hitboxTopOffset = -0x28;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x4;
            
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pose = 0x8;
            break;

        case MOTHER_BRAIN_PART_BOTTOM:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x14;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

            gCurrentSprite.hitboxTopOffset = -0xF8;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = -0xB0;
            gCurrentSprite.hitboxRightOffset = 0xB0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x6;
            gCurrentSprite.pose = 0xE;
            health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.health = health;
            gBossWork.work3 = health;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 3d288 | a4 | Upates the hitbox of the mother brain eye
 * 
 */
void MotherBrainPartHitboxInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 0x1:
                gCurrentSprite.hitboxTopOffset = -0x10;
                gCurrentSprite.hitboxBottomOffset = 0x10;
                gCurrentSprite.hitboxLeftOffset = 0x20;
                gCurrentSprite.hitboxRightOffset = 0x60;
                break;

            case 0x2:
                gCurrentSprite.hitboxTopOffset = -0x20;
                gCurrentSprite.hitboxBottomOffset = 0x20;
                gCurrentSprite.hitboxLeftOffset = 0x40;
                gCurrentSprite.hitboxRightOffset = 0xA0;
                break;

            case 0x3:
                gCurrentSprite.hitboxTopOffset = -0x30;
                gCurrentSprite.hitboxBottomOffset = 0x30;
                gCurrentSprite.hitboxLeftOffset = 0xA0;
                gCurrentSprite.hitboxRightOffset = 0xE0;
                break;

            default:
                gCurrentSprite.hitboxTopOffset = -0x8;
                gCurrentSprite.hitboxBottomOffset = 0x8;
                gCurrentSprite.hitboxLeftOffset = -0x4;
                gCurrentSprite.hitboxRightOffset = 0x20;
        }
    }
}

/**
 * @brief 3d32c | 4 | Empty function
 * 
 */
void MotherBrainPart_Empty(void)
{
    return;
}

/**
 * @brief 3d330 | 74 | Spawns the mother brain block sprite if necessary
 * 
 */
void MotherBrainSpawnBlock(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gSubSpriteData1.yPosition - (BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
    xPosition = gSubSpriteData1.xPosition + (BLOCK_SIZE * 11 + HALF_BLOCK_SIZE);

    if (gSamusData.xPosition < (xPosition - 0x3C))
    {
        SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_BLOCK, 0x0, 0x6, gCurrentSprite.primarySpriteRAMSlot,
            yPosition, xPosition, 0x0);
        gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_STAGE_1;
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    }
}

/**
 * @brief 3d3a4 | 40 | First stage of the glass
 * 
 */
void MotherBrainPartGlassStage1(void)
{
    gCurrentSprite.invincibilityStunFlashTimer = 0x0;
    // 3/4 of health
    if (gCurrentSprite.health <= (gBossWork.work3 * 3) >> 2)
    {
        gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_STAGE_2;
        // Edit BG
        BGClipCallMotherBrainUpdateGlass(0x1);
        SoundPlay(0x2B5);
    }
}

/**
 * @brief 3d3e4 | 3c | Second stage of the glass
 * 
 */
void MotherBrainPartGlassStage2(void)
{
    gCurrentSprite.invincibilityStunFlashTimer = 0x0;
    // 2/4 of health
    if (gCurrentSprite.health <= gBossWork.work3 / 2)
    {
        gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_STAGE_3;
        // Edit BG
        BGClipCallMotherBrainUpdateGlass(0x2);
        SoundPlay(0x2B6);
    }
}

/**
 * @brief 3d420 | 3c | Third stage of the glass
 * 
 */
void MotherBrainPartGlassStage3(void)
{
    gCurrentSprite.invincibilityStunFlashTimer = 0x0;
    // 1/4 of health
    if (gCurrentSprite.health <= gBossWork.work3 / 4)
    {
        gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_BROKEN;
        // Edit BG
        BGClipCallMotherBrainUpdateGlass(0x3);
        SoundPlay(0x2B7);
    }
}

/**
 * @brief 3d45c | 10 | Sets the invicibility stun flash timer to 0
 * 
 */
void MotherBrainPartISFT(void)
{
    gCurrentSprite.invincibilityStunFlashTimer = 0x0;
}

/**
 * @brief 3d46c | 54 | Breaks the mother brain glass
 * 
 */
void MotherBrainPartSpawnGlassBreaking(void)
{
    gCurrentSprite.invincibilityStunFlashTimer = 0x0;
    gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_BROKEN;
    gSubSpriteData1.workVariable3 = 0x1;
    // Spawn glass
    SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_GLASS_BREAKING, 0x0, gCurrentSprite.spritesetGFXSlot,
        gCurrentSprite.primarySpriteRAMSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0x0);
    // Remove in BG
    BGClipCallMotherBrainUpdateGlass(0x4);
    SoundPlay(0x2B8);
}

/**
 * @brief 3d4c0 | e0 | Mother brain AI
 * 
 */
void MotherBrain(void)
{
    u8 mbSize;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            MotherBrainInit();
            break;

        case MOTHER_BRAIN_POSE_WAITING_GLASS:
            MotherBrainCheckGlassBreaked();
            break;

        case MOTHER_BRAIN_POSE_MAIN_LOOP:
            MotherBrainMainLoop();
            break;

        case MOTHER_BRAIN_POSE_DYING:
            MotherBrainDeath();
            break;

        case MOTHER_BRAIN_POSE_START_ESCAPE:
            MotherBrainStartEscape();
            break;
    }

    if (gCurrentSprite.pose < 0x8)
    {
        SpriteUtilUpdateSubSprite1Anim();
        MotherBrainSyncSubSpritesPosition();
    }
    else
    {
        SpriteUtilUpdateSubSprite1Anim();
        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    }

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && gSubSpriteData1.workVariable3 < 0x3
        && gSamusData.xPosition < (gSubSpriteData1.xPosition + (BLOCK_SIZE * 12)))
    {
        gLockScreen.lock = TRUE;
        gLockScreen.yPositionCenter = gBossWork.work1;
        gLockScreen.xPositionCenter = gSubSpriteData1.xPosition + (BLOCK_SIZE * 5);

        if (gSubSpriteData1.workVariable3 == 0x0)
            mbSize = 0xDC;
        else
            mbSize = 0xA0;

        if (gSamusData.xPosition < gBossWork.work2 + mbSize)
            gSamusData.xPosition = gBossWork.work2 + mbSize;
    }
    else
        gLockScreen.lock = FALSE;
}

/**
 * @brief 3d5a0 | a0 | Mother brain part AI
 * 
 */
void MotherBrainPart(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            MotherBrainPartInit();
            MotherBrainSyncSubSpritesPosition();
            return;

        case MOTHER_BRAIN_PART_POSE_UPDATE:
            MotherBrainPartHitboxInit();
            break;

        case MOTHER_BRAIN_PART_POSE_IDLE:
            MotherBrainPart_Empty();
            break;

        case MOTHER_BRAIN_PART_POSE_SPAWN_BLOCK:
            MotherBrainSpawnBlock();
            break;

        case MOTHER_BRAIN_PART_POSE_GLASS_STAGE_1:
            MotherBrainPartGlassStage1();
            break;

        case MOTHER_BRAIN_PART_POSE_GLASS_STAGE_2:
            MotherBrainPartGlassStage2();
            break;

        case MOTHER_BRAIN_PART_POSE_GLASS_STAGE_3:
            MotherBrainPartGlassStage3();
            break;

        case MOTHER_BRAIN_PART_POSE_GLASS_BROKEN:
            MotherBrainPartISFT();
            break;

        case MOTHER_BRAIN_PART_POSE_GLASS_BREAKING:
            if (gCurrentSprite.roomSlot == MOTHER_BRAIN_PART_BOTTOM)
                MotherBrainPartSpawnGlassBreaking();
            break;
    }

    if (gCurrentSprite.roomSlot == MOTHER_BRAIN_PART_BOTTOM)
        MotherBrainSyncSubSpritesPosition();
    else
        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
}

/**
 * @brief 3d640 | e4 | Mother brain beam AI
 * 
 */
void MotherBrainBeam(void)
{
    if (gSubSpriteData1.workVariable3 > 0x1)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.properties |= (SP_KILL_OFF_SCREEN | SP_IMMUNE_TO_PROJECTILES);

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x30;

            gCurrentSprite.hitboxTopOffset = -0x30;
            gCurrentSprite.hitboxBottomOffset = 0x30;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x20;

            gCurrentSprite.pOam = sMotherBrainBeamOAM_Moving;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = 0x9;
            gCurrentSprite.samusCollision = SSC_MOTHER_BRAIN_BEAM;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
            gCurrentSprite.health = 0x1;
            gCurrentSprite.timer = 0x10;

        case 0x9:
            gCurrentSprite.xPosition += 0xC;
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck != COLLISION_AIR)
            {
                ParticleSet(gCurrentSprite.yPosition + 0x1C, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_BIG);
                gCurrentSprite.status = 0x0;
                SoundPlay(0x2C3);
            }
    }
}

/**
 * @brief 3d724 | a8 | Mother brain block AI
 * 
 */
void MotherBrainBlock(void)
{
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.drawDistanceTopOffset = 0x10;
        gCurrentSprite.drawDistanceBottomOffset = 0x10;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

        gCurrentSprite.hitboxTopOffset = -0x20;
        gCurrentSprite.hitboxBottomOffset = 0x20;
        gCurrentSprite.hitboxLeftOffset = -0x20;
        gCurrentSprite.hitboxRightOffset = 0x20;

        gCurrentSprite.pOam = sMotherBrainBlockOAM;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;
    }
    else if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        else
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            
            gCurrentClipdataAffectingAction = CAA_MAKE_SOLID3;
            ClipdataProcess(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        }
    }
}

/**
 * @brief 3d7cc | 94 | Mother brain glass breaking AI
 * 
 */
void MotherBrainGlassBreaking(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.drawDistanceBottomOffset = 0x30;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x50;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.pOam = sMotherBrainGlassBreakingOAM_Breaking;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = 0x9;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
            break;

        case 0x9:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
                gCurrentSprite.status = 0x0;
    }
}