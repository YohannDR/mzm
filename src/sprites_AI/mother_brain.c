#include "sprites_AI/mother_brain.h"
#include "macros.h"

#include "data/frame_data_pointers.h"
#include "data/sprites/mother_brain.h"
#include "data/sprites/zebetite_and_cannon.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/in_game_cutscene.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/game_state.h"
#include "constants/sprite.h"
#include "constants/text.h"

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
    MultiSpriteDataInfo_T pData;
    u16 oamIdx;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];

    if (gCurrentSprite.pOam != sMotheBrainFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sMotheBrainFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
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

    if (gCurrentSprite.scaling != 0)
    {
        gCurrentSprite.scaling--;
        gCurrentSprite.paletteRow = sMotherBrainDynamicPaletteData[gCurrentSprite.rotation][0];
    }
    else
    {
        offset = gCurrentSprite.rotation++;
        timer = sMotherBrainDynamicPaletteData[offset][0];
        if (timer == 0x80)
        {
            gCurrentSprite.rotation = 0x1;
            offset = 0;
            timer = sMotherBrainDynamicPaletteData[offset][0];
        }

        newTimer = sMotherBrainDynamicPaletteData[offset][1];
        if (offset == 0 || offset == 0x6)
            SoundPlay(SOUND_MOTHER_BRAIN_CHARGING);

        gCurrentSprite.paletteRow = timer;
        gCurrentSprite.scaling = newTimer;
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
        gCurrentSprite.status = 0;
    else
    {
        gCurrentSprite.xPosition += 0x20;
        gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

        yPosition = gSubSpriteData1.yPosition;
        xPosition = gSubSpriteData1.xPosition;
        gBossWork.work1 = yPosition;
        gBossWork.work2 = xPosition;
        gBossWork.work3 = 0;
        gBossWork.work4 = 0;
        gBossWork.work5 = 0;

        gCurrentSprite.drawDistanceTop = 0x28;
        gCurrentSprite.drawDistanceBottom = 0x20;
        gCurrentSprite.drawDistanceHorizontal = 0x30;

        gCurrentSprite.hitboxTop = -0x70;
        gCurrentSprite.hitboxBottom = 0x60;
        gCurrentSprite.hitboxLeft = -0xA0;
        gCurrentSprite.hitboxRight = 0x80;

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
        gCurrentSprite.work0 = 0;
        gCurrentSprite.work1 = 0;
        gCurrentSprite.scaling = 0;
        gCurrentSprite.rotation = 0;
        gCurrentSprite.work2 = 0;
        
        gSubSpriteData1.pMultiOam = sMotherBrainMultiSpriteData;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gSubSpriteData1.workVariable3 = 0;

        gCurrentSprite.pose = MOTHER_BRAIN_POSE_WAITING_GLASS;
        gCurrentSprite.roomSlot = MOTHER_BRAIN_PART_BODY;

        gfxSlot = gCurrentSprite.spritesetGfxSlot;
        ramSlot = gCurrentSprite.primarySpriteRamSlot;

        gSubSpriteData1.workVariable4 = SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_PART, MOTHER_BRAIN_PART_BEAM_SHOOTER,
            gfxSlot, ramSlot, yPosition, xPosition, 0);

        gSubSpriteData1.workVariable5 = SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_PART, MOTHER_BRAIN_PART_EYE,
            gfxSlot, ramSlot, yPosition, xPosition, 0);

        gSubSpriteData1.workVariable6 = SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_PART, MOTHER_BRAIN_PART_BOTTOM,
            gfxSlot, ramSlot, yPosition, xPosition, 0);
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
        gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOam_EyeOpening;
        gSpriteData[eyeRamSlot].animationDurationCounter = 0;
        gSpriteData[eyeRamSlot].currentAnimationFrame = 0;
        SoundPlay(SOUND_MOTHER_BRAIN_EYE_OPENING);
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

    if (gSpriteData[eyeRamSlot].health == 0)
    {
        // Set dying behavior
        gCurrentSprite.pose = MOTHER_BRAIN_POSE_DYING;
        gCurrentSprite.pOam = sMotherBrainOam_ChargingBeam;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.invincibilityStunFlashTimer = 0x78;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.health = 0x1;
        gCurrentSprite.paletteRow = 0;

        gSpriteData[eyeRamSlot].paletteRow = 0;
        gSpriteData[bottomRamSlot].paletteRow = 0;
               
        gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOam_EyeDying;
        gSpriteData[eyeRamSlot].animationDurationCounter = 0;
        gSpriteData[eyeRamSlot].currentAnimationFrame = 0;
        gSpriteData[eyeRamSlot].samusCollision = SSC_NONE;

        gSpriteData[beamShooterRamSlot].status = 0;
        gSubSpriteData1.workVariable3 = 0x2;
        // Set event
        EventFunction(EVENT_ACTION_SETTING, EVENT_MOTHER_BRAIN_KILLED);
        SoundPlay(SOUND_MOTHER_BRAIN_DYING);
        return;
    }

    if (gCurrentSprite.pOam == sMotherBrainOam_ChargingBeam)
    {
        // delay before charging
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.pOam = sMotherBrainOam_Idle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
    else
    {
        if (gCurrentSprite.currentAnimationFrame == 0x1 && gCurrentSprite.animationDurationCounter == 0x1)
            SoundPlay(SOUND_MOTHER_BRAIN_IDLE);

        if ((gSpriteData[eyeRamSlot].invincibilityStunFlashTimer & 0x7F) == 0x10)
        {
            SoundPlay(SOUND_MOTHER_BRAIN_DAMAGED);
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
                    gBossWork.work5 = 0;
                    gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOam_EyeClosing;
                    gSpriteData[eyeRamSlot].animationDurationCounter = 0;
                    gSpriteData[eyeRamSlot].currentAnimationFrame = 0;
                    gSpriteData[eyeRamSlot].properties |= SP_IMMUNE_TO_PROJECTILES;
                    SoundPlay(SOUND_MOTHER_BRAIN_EYE_CLOSING);
                    gCurrentSprite.work2 = 0x1;
                }
            }
        }
    }

    if (gSpriteData[eyeRamSlot].pOam == sMotherBrainPartOam_EyeClosing)
    {
        // Check should close
        if (SpriteUtilCheckEndSpriteAnim(eyeRamSlot))
        {
            gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOam_EyeClosed;
            gSpriteData[eyeRamSlot].animationDurationCounter = 0;
            gSpriteData[eyeRamSlot].currentAnimationFrame = 0;
        }
    }
    else if (gSpriteData[eyeRamSlot].pOam == sMotherBrainPartOam_EyeClosed)
    {
        // Check should start charging beam
        if (gSubSpriteData1.yPosition + (BLOCK_SIZE * 2) >= gSamusData.yPosition)
        {
            gCurrentSprite.work2--; // Delay
            if (gCurrentSprite.work2 == 0)
            {
                // Set charging beam behavior
                gCurrentSprite.pOam = sMotherBrainOam_ChargingBeam;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                gCurrentSprite.work1 = 0x48;
                gCurrentSprite.work0 = CONVERT_SECONDS(1.2f);
                gCurrentSprite.scaling = 0;
                gCurrentSprite.rotation = 0;
            }
        }
    }
    else if (gSpriteData[eyeRamSlot].pOam == sMotherBrainPartOam_EyeOpening)
    {
        if (gCurrentSprite.work1 == 0)
        {
            // Check should close eye
            if (gSubSpriteData1.yPosition + (BLOCK_SIZE * 2) < gSamusData.yPosition)
            {
                // Samus fell below the blocks, set closing behavior
                gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOam_EyeClosing;
                gSpriteData[eyeRamSlot].animationDurationCounter = 0;
                gSpriteData[eyeRamSlot].currentAnimationFrame = 0;
                gSpriteData[eyeRamSlot].properties |= SP_IMMUNE_TO_PROJECTILES;
                SoundPlay(SOUND_MOTHER_BRAIN_EYE_CLOSING);
                gCurrentSprite.work2 = 0x3C;
            }
            return;
        }
    }

    if (gCurrentSprite.work1 == 0)
        return;
   
    // Shooting beam
    if (gCurrentSprite.work1-- == 0x1)
    {
        if (palette != 0xE)
        {
            // Set normal palette
            gCurrentSprite.paletteRow = 0;
            gSpriteData[eyeRamSlot].paletteRow = 0;
            gSpriteData[bottomRamSlot].paletteRow = 0;
        }
    }
    else
    {
        if (gCurrentSprite.work1 == 0xC)
        {
            // Spawn beam
            SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_BEAM, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gSpriteData[beamShooterRamSlot].yPosition,
                gSpriteData[beamShooterRamSlot].xPosition + 0xCC, 0);

            // Hide beam shooter
            gSpriteData[beamShooterRamSlot].status |= SPRITE_STATUS_NOT_DRAWN;
        }
        else if (gCurrentSprite.work1 == 0x14)
        {
            // Open eye
            gSpriteData[eyeRamSlot].pOam = sMotherBrainPartOam_EyeOpening;
            gSpriteData[eyeRamSlot].animationDurationCounter = 0;
            gSpriteData[eyeRamSlot].currentAnimationFrame = 0;
            // Make eye vulnerable
            gSpriteData[eyeRamSlot].properties &= ~SP_IMMUNE_TO_PROJECTILES;
            SoundPlay(SOUND_MOTHER_BRAIN_EYE_OPENING);
        }
        else if (gCurrentSprite.work1 == 0x18)
        {
            // Set beam shooter behavior
            gSpriteData[beamShooterRamSlot].pOam = sMotherBrainPartOam_BeamSpawning;
            gSpriteData[beamShooterRamSlot].animationDurationCounter = 0;
            gSpriteData[beamShooterRamSlot].currentAnimationFrame = 0;
            gSpriteData[beamShooterRamSlot].status &= ~SPRITE_STATUS_NOT_DRAWN;
            SoundPlay(SOUND_MOTHER_BRAIN_SHOOTING);
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

    if (gCurrentSprite.invincibilityStunFlashTimer != 0)
    {
        gSpriteData[eyeRamSlot].paletteRow = gCurrentSprite.paletteRow;
        gSpriteData[bottomRamSlot].paletteRow = gCurrentSprite.paletteRow;
        if (!(gCurrentSprite.invincibilityStunFlashTimer & 0x3F))
            MakeBackgroundFlash(BG_FLASH_QUICK_YELLOW);
    }
    else
    {
        gSpriteData[eyeRamSlot].status = 0;
        gSpriteData[bottomRamSlot].status = 0;
        gCurrentSprite.pose = MOTHER_BRAIN_POSE_START_ESCAPE;
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f);
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        ParticleSet(gSubSpriteData1.yPosition + 0x46, gSubSpriteData1.xPosition - 0x3C, PE_MAIN_BOSS_DEATH);
        ParticleSet(gSubSpriteData1.yPosition + 0x3C, gSubSpriteData1.xPosition + 0x50, PE_MAIN_BOSS_DEATH);
        gInGameTimerAtBosses[1] = gInGameTimer;
        SoundPlay(SOUND_MOTHER_BRAIN_DEATH_EXPLOSION);
        MakeBackgroundFlash(BG_FLASH_QUICK_YELLOW);
    }
}

/**
 * @brief 3d0c4 | 6c | Starts the escape
 * 
 */
void MotherBrainStartEscape(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        // Kill sprite
        gCurrentSprite.status = 0;
        // Spawn banner and effects
        SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_ZEBES_ESCAPE, 0, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
        SpriteSpawnPrimary(PSPRITE_EXPLOSION_ZEBES_ESCAPE, 0, 0, gCurrentSprite.yPosition + (BLOCK_SIZE * 4), gCurrentSprite.xPosition, 0);
        PlayMusic(MUSIC_ESCAPE, 0x40);
        SoundPlay(SOUND_ESCAPE_BEEP);
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
            gCurrentSprite.drawDistanceTop = 0x10;
            gCurrentSprite.drawDistanceBottom = 0x10;
            gCurrentSprite.drawDistanceHorizontal = 0x40;

            gCurrentSprite.hitboxTop = -0x4;
            gCurrentSprite.hitboxBottom = 0x4;
            gCurrentSprite.hitboxLeft = -0x4,
            gCurrentSprite.hitboxRight = 0x4;

            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.pose = 0x32;

            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.health = 0x1;
            break;

        case MOTHER_BRAIN_PART_EYE:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.drawDistanceTop = 0x10;
            gCurrentSprite.drawDistanceBottom = 0x10;
            gCurrentSprite.drawDistanceHorizontal = 0x18;

            gCurrentSprite.hitboxTop = -0x28;
            gCurrentSprite.hitboxBottom = 0x20;
            gCurrentSprite.hitboxLeft = -0x20;
            gCurrentSprite.hitboxRight = 0x4;
            
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pose = 0x8;
            break;

        case MOTHER_BRAIN_PART_BOTTOM:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.drawDistanceTop = 0x10;
            gCurrentSprite.drawDistanceBottom = 0x14;
            gCurrentSprite.drawDistanceHorizontal = 0x20;

            gCurrentSprite.hitboxTop = -0xF8;
            gCurrentSprite.hitboxBottom = 0x20;
            gCurrentSprite.hitboxLeft = -0xB0;
            gCurrentSprite.hitboxRight = 0xB0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x6;
            gCurrentSprite.pose = 0xE;
            health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.health = health;
            gBossWork.work3 = health;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        default:
            gCurrentSprite.status = 0;
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
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 0x1:
                gCurrentSprite.hitboxTop = -0x10;
                gCurrentSprite.hitboxBottom = 0x10;
                gCurrentSprite.hitboxLeft = 0x20;
                gCurrentSprite.hitboxRight = 0x60;
                break;

            case 0x2:
                gCurrentSprite.hitboxTop = -0x20;
                gCurrentSprite.hitboxBottom = 0x20;
                gCurrentSprite.hitboxLeft = 0x40;
                gCurrentSprite.hitboxRight = 0xA0;
                break;

            case 0x3:
                gCurrentSprite.hitboxTop = -0x30;
                gCurrentSprite.hitboxBottom = 0x30;
                gCurrentSprite.hitboxLeft = 0xA0;
                gCurrentSprite.hitboxRight = 0xE0;
                break;

            default:
                gCurrentSprite.hitboxTop = -0x8;
                gCurrentSprite.hitboxBottom = 0x8;
                gCurrentSprite.hitboxLeft = -0x4;
                gCurrentSprite.hitboxRight = 0x20;
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
        SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_BLOCK, 0, 0x6, gCurrentSprite.primarySpriteRamSlot,
            yPosition, xPosition, 0);
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
    gCurrentSprite.invincibilityStunFlashTimer = 0;
    // 3/4 of health
    if (gCurrentSprite.health <= (gBossWork.work3 * 3) >> 2)
    {
        gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_STAGE_2;
        // Edit BG
        BgClipCallMotherBrainUpdateGlass(0x1);
        SoundPlay(SOUND_MOTHER_BRAIN_JAR_DAMAGE_1);
    }
}

/**
 * @brief 3d3e4 | 3c | Second stage of the glass
 * 
 */
void MotherBrainPartGlassStage2(void)
{
    gCurrentSprite.invincibilityStunFlashTimer = 0;
    // 2/4 of health
    if (gCurrentSprite.health <= gBossWork.work3 / 2)
    {
        gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_STAGE_3;
        // Edit BG
        BgClipCallMotherBrainUpdateGlass(0x2);
        SoundPlay(SOUND_MOTHER_BRAIN_JAR_DAMAGE_2);
    }
}

/**
 * @brief 3d420 | 3c | Third stage of the glass
 * 
 */
void MotherBrainPartGlassStage3(void)
{
    gCurrentSprite.invincibilityStunFlashTimer = 0;
    // 1/4 of health
    if (gCurrentSprite.health <= gBossWork.work3 / 4)
    {
        gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_BROKEN;
        // Edit BG
        BgClipCallMotherBrainUpdateGlass(0x3);
        SoundPlay(SOUND_MOTHER_BRAIN_JAR_DAMAGE_3);
    }
}

/**
 * @brief 3d45c | 10 | Sets the invicibility stun flash timer to 0
 * 
 */
void MotherBrainPartISFT(void)
{
    gCurrentSprite.invincibilityStunFlashTimer = 0;
}

/**
 * @brief 3d46c | 54 | Breaks the mother brain glass
 * 
 */
void MotherBrainPartSpawnGlassBreaking(void)
{
    gCurrentSprite.invincibilityStunFlashTimer = 0;
    gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_BROKEN;
    gSubSpriteData1.workVariable3 = 0x1;
    // Spawn glass
    SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_GLASS_BREAKING, 0, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    // Remove in BG
    BgClipCallMotherBrainUpdateGlass(0x4);
    SoundPlay(SOUND_MOTHER_BRAIN_JAR_SHATTER);
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
        case SPRITE_POSE_UNINITIALIZED:
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
        gLockScreen.lock = LOCK_SCREEN_TYPE_POSITION;
        gLockScreen.yPositionCenter = gBossWork.work1;
        gLockScreen.xPositionCenter = gSubSpriteData1.xPosition + (BLOCK_SIZE * 5);

        if (gSubSpriteData1.workVariable3 == 0)
            mbSize = 0xDC;
        else
            mbSize = 0xA0;

        if (gSamusData.xPosition < gBossWork.work2 + mbSize)
            gSamusData.xPosition = gBossWork.work2 + mbSize;
    }
    else
        gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;
}

/**
 * @brief 3d5a0 | a0 | Mother brain part AI
 * 
 */
void MotherBrainPart(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
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
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.properties |= (SP_KILL_OFF_SCREEN | SP_IMMUNE_TO_PROJECTILES);

            gCurrentSprite.drawDistanceTop = 0x10;
            gCurrentSprite.drawDistanceBottom = 0x10;
            gCurrentSprite.drawDistanceHorizontal = 0x30;

            gCurrentSprite.hitboxTop = -0x30;
            gCurrentSprite.hitboxBottom = 0x30;
            gCurrentSprite.hitboxLeft = -0x20;
            gCurrentSprite.hitboxRight = 0x20;

            gCurrentSprite.pOam = sMotherBrainBeamOam_Moving;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = 0x9;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_IGNORE_INVINCIBILITY;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.bgPriority = gIoRegistersBackup.BG1CNT & 0x3;
            gCurrentSprite.health = 0x1;
            gCurrentSprite.work0 = 0x10;

        case 0x9:
            gCurrentSprite.xPosition += 0xC;
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck != COLLISION_AIR)
            {
                ParticleSet(gCurrentSprite.yPosition + 0x1C, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_BIG);
                gCurrentSprite.status = 0;
                SoundPlay(SOUND_MOTHER_BRAIN_LASER_EXPLODING);
            }
    }
}

/**
 * @brief 3d724 | a8 | Mother brain block AI
 * 
 */
void MotherBrainBlock(void)
{
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.drawDistanceTop = 0x10;
        gCurrentSprite.drawDistanceBottom = 0x10;
        gCurrentSprite.drawDistanceHorizontal = 0x8;

        gCurrentSprite.hitboxTop = -0x20;
        gCurrentSprite.hitboxBottom = 0x20;
        gCurrentSprite.hitboxLeft = -0x20;
        gCurrentSprite.hitboxRight = 0x20;

        gCurrentSprite.pOam = sMotherBrainBlockOAM;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.samusCollision = SSC_CHECK_COLLIDING;
    }
    else if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        else
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            
            gCurrentClipdataAffectingAction = CAA_MAKE_NON_POWER_GRIP;
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
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

            gCurrentSprite.drawDistanceTop = 0x30;
            gCurrentSprite.drawDistanceBottom = 0x30;
            gCurrentSprite.drawDistanceHorizontal = 0x50;

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.pOam = sMotherBrainGlassBreakingOam_Breaking;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = 0x9;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.bgPriority = gIoRegistersBackup.BG1CNT & 0x3;
            break;

        case 0x9:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
                gCurrentSprite.status = 0;
    }
}