#include "sprites_AI/imago_cocoon.h"
#include "macros.h"

#include "data/frame_data_pointers.h"
#include "data/sprites/imago_cocoon.h"
#include "data/sprites/enemy_drop.h"
#include "data/sprite_data.h"
#include "data/generic_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/sprite.h"
#include "constants/samus.h"
#include "constants/sprite_util.h"
#include "constants/particle.h"

#include "structs/bg_clip.h"
#include "structs/connection.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/clipdata.h"

/**
 * @brief 26c38 | 68 | Sync the sub sprites of Imago cocoon
 * 
 */
void ImagoCocoonSyncSprites(void)
{
    u16 (*pData)[3];
    u32 offset;

    pData = (u16(*)[3])gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pFrame;
    offset = pData[gCurrentSprite.roomSlot][0];
    
    if (gCurrentSprite.pOam != sImagoCocoonFrameDataPointers[offset])
    {
        gCurrentSprite.pOam = sImagoCocoonFrameDataPointers[offset];
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][1];
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][2];
}

/**
 * 26ca0 | 40 | Updates the clipdata of the middle block of the ground when falling
 * 
 * @param caa Clipdata Affecting Action
 */
void ImagoCocoonChangeOneCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 11;
    xPosition = gSubSpriteData1.xPosition;
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - HALF_BLOCK_SIZE, xPosition);
    ParticleSet(yPosition - HALF_BLOCK_SIZE, xPosition, PE_SPRITE_EXPLOSION_HUGE);
}

/**
 * 26ce0 | 70 | Updates the clipdata of the 2 blocks around the middle of the ground when falling
 * 
 * @param caa Clipdata Affecting Action
 */
void ImagoCocoonChangeTwoMiddleCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 11;
    xPosition = gSubSpriteData1.xPosition;
    
    // Right block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (HALF_BLOCK_SIZE), xPosition + BLOCK_SIZE);
    
    // Left block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (HALF_BLOCK_SIZE), xPosition - BLOCK_SIZE);

    ParticleSet(yPosition, xPosition + 0x48, PE_SPRITE_EXPLOSION_HUGE);
    ParticleSet(yPosition, xPosition - 0x48, PE_SPRITE_EXPLOSION_HUGE);
}

/**
 * @brief 26d50 | 7c | Updates the clipdata of the 2 blocks at the edge of the ground when falling
 * 
 * @param caa Clipdata Affecting Action
 */
void ImagoCocoonChangeTwoAroundCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 11;
    xPosition = gSubSpriteData1.xPosition;

    // Right block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - 0x20, xPosition + BLOCK_SIZE * 2);

    // Left block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - 0x20, xPosition - BLOCK_SIZE * 2);

    ParticleSet(yPosition, xPosition + BLOCK_SIZE * 2, PE_SPRITE_EXPLOSION_HUGE);
    ParticleSet(yPosition, xPosition - BLOCK_SIZE * 2, PE_SPRITE_EXPLOSION_HUGE);
}

/**
 * 26dcc | 5c | Updates the current clipdata affecting action and applies it, removes the 2 blocks that block the passage
 * 
 * @param caa Clipdata Affecting Action
 */
void ImagoCocoonChangeTwoBlockingCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 13;
    xPosition = gSubSpriteData1.xPosition;

    // Top block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + HALF_BLOCK_SIZE, xPosition + BLOCK_SIZE * 9);
    
    // Bottom block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE + HALF_BLOCK_SIZE, xPosition + BLOCK_SIZE * 9);
}

/**
 * 26e28 | 54 | Changes the oam scaling of the imago cocoon (growing or shrinking)
 * 
 * @param limit The limit of the scaling
 * @param value The value to increment/decrement the scaling
 */
void ImagoCocoonChangeOAMScaling(u16 limit, u16 value)
{
    if (gCurrentSprite.workVariable2) // Check growing/shrinking
    {
        if (gCurrentSprite.oamScaling > (0x100 - limit))
            gCurrentSprite.oamScaling -= value;
        else
            gCurrentSprite.workVariable2 = FALSE; // Set growing
    }
    else
    {
        if (gCurrentSprite.oamScaling < (limit + 0x100))
            gCurrentSprite.oamScaling += value;
        else
            gCurrentSprite.workVariable2 = TRUE; // Set shrinking
    }
}

/**
 * @brief 26e7c | 2ac | Initializes an Imago cocoon sprite
 * 
 */
void ImagoCocoonInit(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;
    u8 newRamSlot;

    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_IMAGO_COCOON_KILLED))
    {
        SpriteSpawnSecondary(SSPRITE_IMAGO_CEILING_VINE, 0x0, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.primarySpriteRAMSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0x0);

        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ENTER_RIDLEY_DEMO_PLAYED))
            gCurrentSprite.status = 0x0;
        else
        {
            // Set in tunnel

            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;

            gCurrentSprite.drawDistanceTopOffset = 0x38;
            gCurrentSprite.drawDistanceBottomOffset = 0x18;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.drawOrder = 0x4;
            gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING;
            gCurrentSprite.oamScaling = 0x100;
            gCurrentSprite.oamRotation = 0x0;
            gCurrentSprite.roomSlot = IMAGO_COCOON_PART_IMAGO_COCOON;

            gSubSpriteData1.pMultiOam = sImagoCocoonMultiSpriteData_Idle;
            gSubSpriteData1.animationDurationCounter = 0x0;
            gSubSpriteData1.currentAnimationFrame = 0x0;

            gCurrentSprite.pOam = sImagoCocoonOAM_Static;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = IMAGO_COCOON_POSE_IN_GROUND;
            gSubSpriteData1.yPosition += BLOCK_SIZE * 15;
        }
    }
    else
    {
        yPosition = gSubSpriteData1.yPosition;
        xPosition = gSubSpriteData1.xPosition;
        gCurrentSprite.yPositionSpawn = yPosition;

        gCurrentSprite.drawDistanceTopOffset = 0x38;
        gCurrentSprite.drawDistanceBottomOffset = 0x18;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

        gCurrentSprite.hitboxTopOffset = -0xA0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = -0x60;
        gCurrentSprite.hitboxRightOffset = 0x60;

        gCurrentSprite.drawOrder = 0x6;
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
        gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING;

        gCurrentSprite.oamScaling = 0x100;
        gCurrentSprite.oamRotation = 0x0;
        gCurrentSprite.workVariable2 = FALSE;

        gSubSpriteData1.pMultiOam = sImagoCocoonMultiSpriteData_Idle;
        gSubSpriteData1.animationDurationCounter = 0x0;
        gSubSpriteData1.currentAnimationFrame = 0x0;
        
        gSubSpriteData1.workVariable2 = 0x0;
        gSubSpriteData1.workVariable1 = 0x0;
        // Number of vines alive
        gSubSpriteData1.health = 0x6;

        gDoorUnlockTimer = 0x1;
        gCurrentSprite.pose = IMAGO_COCOON_POSE_IDLE;
        gCurrentSprite.roomSlot = IMAGO_COCOON_PART_IMAGO_COCOON;

        gfxSlot = gCurrentSprite.spritesetGFXSlot;
        ramSlot = gCurrentSprite.primarySpriteRAMSlot;

        // Spawn vines
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_LEFT_MIDDLE, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_RIGHT_MIDDLE, gfxSlot, ramSlot, yPosition, xPosition, 0x0);

        // Save RAM slot of self for the spores
        newRamSlot = SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_LEFT_VINE_DECORATIONS,
            gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        gSpriteData[newRamSlot].workVariable = newRamSlot;

        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_CEILING_VINE, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_RIGHT_VINE_DECORATIONS, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_RIGHT_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_LEFT_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_RIGHT_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_LEFT_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        
        // Spawn winged ripper
        newRamSlot = SpriteSpawnSecondary(SSPRITE_WINGED_RIPPER, 0x0, gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 4, xPosition, SPRITE_STATUS_XFLIP);
        // Set destination of winged ripper
        gSpriteData[newRamSlot].yPositionSpawn = yPosition + BLOCK_SIZE * 6;
        gSpriteData[newRamSlot].xPositionSpawn = xPosition - BLOCK_SIZE * 3;

        gBossWork.work1 = IMAGO_COCOON_MUSIC_STAGE_WAITING_TO_FADE;
    }
}

/**
 * 27128 | 2c | Handles the movement of the Imago cocoon falling
 * 
 */
void ImagoCocoonFallingMovement(void)
{
    u32 increment;

    if (gCurrentSprite.arrayOffset < 0x30)
        gCurrentSprite.arrayOffset++;

    increment = (gCurrentSprite.arrayOffset >> 0x2) + 0x8;
    gSubSpriteData1.yPosition += increment;
}

/**
 * @brief 27154 | 130 | Handles the Imago cocoon being idle
 * 
 */
void ImagoCocoonIdle(void)
{
    u16 caf;
    
    // Update music
    if (gBossWork.work1 != IMAGO_COCOON_MUSIC_STAGE_STARTED_MUSIC)
    {
        if (gBossWork.work1 == IMAGO_COCOON_MUSIC_STAGE_WAITING_TO_FADE)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && gSubSpriteData1.yPosition < gSamusData.yPosition &&
                gSamusData.yPosition - gSubSpriteData1.yPosition > BLOCK_SIZE * 8)
            {
                FadeMusic(0x50);
                gBossWork.work1 = IMAGO_COCOON_MUSIC_STAGE_STARTED_FADING;
            }
        }
        else if (gBossWork.work1 == IMAGO_COCOON_MUSIC_STAGE_STARTED_FADING)
        {
            if (gSubSpriteData1.xPosition < gSamusData.xPosition && gSamusData.xPosition - gSubSpriteData1.xPosition < BLOCK_SIZE * 7)
            {
                PlayMusic(MUSIC_IMAGO_COCOON_BATTLE, 0x0);
                gBossWork.work1 = IMAGO_COCOON_MUSIC_STAGE_STARTED_MUSIC;
            }
        }
    }

    // Check play idle sound
    caf = gCurrentSprite.currentAnimationFrame;
    if (gCurrentSprite.animationDurationCounter == 0x1)
    {
        switch (caf)
        {
            case 0x0:
            case 0x2:
                SoundPlay(0x19F);
        }
    }

    // Check change palette
    if (gSubSpriteData1.health < 0x4)
    {
        gCurrentSprite.paletteRow = 0x1;
        gCurrentSprite.absolutePaletteRow = 0x1;
        if (!(gFrameCounter8Bit & 0x3F))
            ImagoCocoonChangeOAMScaling(0x1, 0x1);
    }

    // Check should fall
    if (gSubSpriteData1.health == 0x0)
    {
        // All vines dead, set falling
        gCurrentSprite.paletteRow = 0x2;
        gCurrentSprite.absolutePaletteRow = 0x2;

        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_NONE;

        gSubSpriteData1.pMultiOam = sImagoCocoonMultiSpriteData_Dying;
        gSubSpriteData1.animationDurationCounter = 0x0;
        gSubSpriteData1.currentAnimationFrame = 0x0;

        gCurrentSprite.timer = 0x0;
        gCurrentSprite.arrayOffset = 0x0;
        gCurrentSprite.pose = IMAGO_COCOON_POSE_FALLING_BEFORE_BLOCKS;

        // Set falling
        EventFunction(EVENT_ACTION_SETTING, EVENT_IMAGO_COCOON_KILLED);
        SoundPlay(0x1A3);
    }
}

/**
 * 27284 | 174 | Handles imago cocoon falling before the blocks are destroyed
 * 
 */
void ImagoCocoonFallingBeforeBlocks(void)
{
    u16 yPosition;
    u32 xPosition;
    u32 rng;
    u8 timer;

    if (!(gFrameCounter8Bit & 0x1F))
        ImagoCocoonChangeOAMScaling(0x1, 0x1);

    if (gSubSpriteData1.currentAnimationFrame > 0x7)
    {
        ImagoCocoonFallingMovement();
        yPosition = gSubSpriteData1.yPosition + BLOCK_SIZE * 6;
        xPosition = gSubSpriteData1.xPosition;
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition);
        if (gPreviousCollisionCheck & 0xF0) // Check for solid collision
        {
            ImagoCocoonChangeOneCCAA(CAA_REMOVE_SOLID); // Remove middile block

            // Set falling after blocks
            gCurrentSprite.pose = IMAGO_COCOON_POSE_FALLING_AFTER_BLOCKS;
            gCurrentSprite.timer = 0x0;
            ScreenShakeStartVertical(0x28, 0x81);
            SoundPlay(0x1A4);
        }
    }
    else
    {
        if (gSubSpriteData1.currentAnimationFrame == 0x7 && gSubSpriteData1.animationDurationCounter == 0x6)
        {
            SpriteSpawnSecondary(SSPRITE_IMAGO_CEILING_VINE, 0x0, gCurrentSprite.spritesetGFXSlot,
                gCurrentSprite.primarySpriteRAMSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0x0);
        }

        yPosition = gBG1YPosition - BLOCK_SIZE;
        xPosition = gSubSpriteData1.xPosition;
        rng = gSpriteRNG;
        
        timer = ++gCurrentSprite.timer;
        if (!(timer & 0x1F))
        {
            if (timer & 0x20)
                SpriteDebrisInit(0x0, 0x5, yPosition, xPosition + 0x5A - (rng * 0x8));
            else
                SpriteDebrisInit(0x0, 0x7, yPosition, xPosition - 0x46 + (rng * 0x8));
        }
        
        if (gSubSpriteData1.currentAnimationFrame > 0x3 && !(timer & 0x1))
        {
            if (rng > 0x7)
            {
                SpriteDebrisInit(0x0, 0x8, yPosition, xPosition - 0x96 + (rng * 0x4));
                SpriteDebrisInit(0x0, 0x6, yPosition, xPosition + 0x20 - (rng * 0x4));
            }
            else
            {
                SpriteDebrisInit(0x0, 0x6, yPosition, xPosition + 0x82 - (rng * 0x4));
                SpriteDebrisInit(0x0, 0x8, yPosition, xPosition - 0x20 + (rng * 0x4));
            }
        }
    }
}

/**
 * @brief 273f8 | fc | Handles imago cocoon falling after the blocks are destroyed
 * 
 */
void ImagoCocoonFallingAfterBlocks(void)
{
    u16 yPosition;
    u16 xPosition;
    u32 topEdge;

    // Scale and move
    if (!(gFrameCounter8Bit & 0x1))
        ImagoCocoonChangeOAMScaling(0x1, 0x1);

    ImagoCocoonFallingMovement();
    yPosition = gSubSpriteData1.yPosition + IMAGO_COCOON_SIZE;
    xPosition = gSubSpriteData1.xPosition;

    // Destroy ground/set effects
    gCurrentSprite.timer++;
    if (gCurrentSprite.timer == 0x4)
        ImagoCocoonChangeTwoMiddleCCAA(CAA_REMOVE_SOLID);
    else if (gCurrentSprite.timer == 0x8)
        ImagoCocoonChangeTwoAroundCCAA(CAA_REMOVE_SOLID);
    else if (gCurrentSprite.timer == 0xF)
    {
        ParticleSet(yPosition + 0xC0, xPosition + 0x64, PE_TWO_MEDIUM_DUST);
        ParticleSet(yPosition + 0xC0, xPosition - 0x64, PE_TWO_MEDIUM_DUST);
        ParticleSet(yPosition + 0xC0, xPosition, PE_SPRITE_EXPLOSION_HUGE);
    }

    topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(yPosition, xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        // Touched ground
        gCurrentSprite.pOam = sImagoCocoonOAM_Static;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        
        gCurrentSprite.paletteRow = 0x0;
        gCurrentSprite.absolutePaletteRow = 0x0;

        gSubSpriteData1.yPosition = topEdge - IMAGO_COCOON_SIZE;
        gCurrentSprite.pose = IMAGO_COCOON_POSE_UNLOCK_PASSAGE;
        gCurrentSprite.timer = 0x5A;

        ScreenShakeStartVertical(0x28, 0x81);
        SoundPlay(0x1A5);

        gCurrentSprite.oamScaling = 0x100;
        gCurrentSprite.workVariable2 = FALSE;

        FadeMusic(0x55);
    }
}

/**
 * 274f4 | 48 | Checks if the passage should be unlocked, and unlocks it if yes
 * 
 */
void ImagoCocoonUnlockPassage(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            gCurrentSprite.pose = IMAGO_COCOON_POSE_IN_GROUND;
            ImagoCocoonChangeTwoBlockingCCAA(CAA_REMOVE_SOLID); // Remove blocking collision

            gDoorUnlockTimer = -0x3C;
            PlayMusic(MUSIC_BOSS_KILLED, 0x0);
        }
    }
}

/**
 * @brief 2753c | 70 | Handles Imago cocoon being in the ground
 * 
 */
void ImagoCocoonInGround(void)
{
    if (!(gFrameCounter8Bit & 0x3))
    {
        if (gCurrentSprite.workVariable2)
        {
            // Scale up
            if (gCurrentSprite.oamScaling > 0xFC)
            {
                gCurrentSprite.oamScaling--;
                gSubSpriteData1.yPosition--;
            }
            else
            {
                gCurrentSprite.workVariable2 = FALSE;
                SoundPlay(0x1A6);
            }
        }
        else
        {
            // Scale down
            if (gCurrentSprite.oamScaling < 0x104)
            {
                gCurrentSprite.oamScaling++;
                gSubSpriteData1.yPosition++;
            }
            else
                gCurrentSprite.workVariable2 = TRUE;
        }
    }
}

/**
 * @brief 275ac | 320 | Initializes an Imago cocoon vine sprite
 * 
 */
void ImagoCocoonVineInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    switch (gCurrentSprite.roomSlot)
    {
        case IMAGO_COCOON_PART_VINE_LEFT_MIDDLE:
            gCurrentSprite.drawDistanceTopOffset = 0x20;
            gCurrentSprite.drawDistanceBottomOffset = 0x20;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = 0x40;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x4;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_RIGHT_MIDDLE:
            gCurrentSprite.drawDistanceTopOffset = 0x18;
            gCurrentSprite.drawDistanceBottomOffset = 0x20;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = 0x60;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x4;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_RIGHT_RIGHT:
            gCurrentSprite.drawDistanceTopOffset = 0x18;
            gCurrentSprite.drawDistanceBottomOffset = 0x20;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x40;
            gCurrentSprite.hitboxBottomOffset = 0x60;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x4;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_LEFT_LEFT:
            gCurrentSprite.drawDistanceTopOffset = 0x20;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = 0x80;
            gCurrentSprite.hitboxLeftOffset = -0x18;
            gCurrentSprite.hitboxRightOffset = 0x18;

            gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x4;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_RIGHT_LEFT:
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x38;
            gCurrentSprite.hitboxBottomOffset = 0x38;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x7;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_LEFT_RIGHT:
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = -0x38;
            gCurrentSprite.hitboxBottomOffset = 0x38;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x7;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_LEFT_VINE_DECORATIONS:
            gCurrentSprite.drawDistanceTopOffset = 0x38;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            // Set spawning spores behavior
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_SPAWN_SPORES;
            gCurrentSprite.yPositionSpawn = 0x0;
            break;

        case IMAGO_COCOON_PART_VINE_RIGHT_VINE_DECORATIONS:
            gCurrentSprite.drawDistanceTopOffset = 0x38;
            gCurrentSprite.drawDistanceBottomOffset = 0x18;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            // Set spawning spores behavior
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x8;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_SPAWN_SPORES;
            break;

        case IMAGO_COCOON_PART_CEILING_VINE:
            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

            gCurrentSprite.hitboxTopOffset = -0x20;
            gCurrentSprite.hitboxBottomOffset = 0xA0;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x20;

            gCurrentSprite.health = 0x1;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_CEILING_VINE_IDLE;

            gCurrentSprite.frozenPaletteRowOffset = 0x5;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 278cc | 38 | Checks if the damaged sound should play
 * 
 */
void ImagoCocoonVineCheckPlayDamagedSound(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x1A2);
    }
}

/**
 * 27904 | 88 | Called when a vine dies, plays a particle effect and decrements the health of the boss 
 * 
 */
void ImagoCocoonVineDeath(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    switch (gCurrentSprite.roomSlot)
    {
        case IMAGO_COCOON_PART_VINE_LEFT_MIDDLE:
            break;
        
        case IMAGO_COCOON_PART_VINE_RIGHT_MIDDLE:
        case IMAGO_COCOON_PART_VINE_RIGHT_RIGHT:
        case IMAGO_COCOON_PART_VINE_LEFT_LEFT:
            yPosition += HALF_BLOCK_SIZE;
            break;
            
        case IMAGO_COCOON_PART_VINE_RIGHT_LEFT:
        case IMAGO_COCOON_PART_VINE_LEFT_RIGHT:
            yPosition += QUARTER_BLOCK_SIZE;
            break;

        default:
            gCurrentSprite.status = 0x0;
            return;
    }

    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_HUGE);

    // Decrement number of vines alive
    if (gSubSpriteData1.health != 0x0)
        gSubSpriteData1.health--;
    gCurrentSprite.status = 0x0;
}

/**
 * 2798c | 160 | Handles the vines spawning the spores
 * 
 */
void ImagoCocoonVineSpawnSpore(void)
{
    u8 slot;
    u8 ramSlot;
    u8 gfxSlot;
    u16 status;
    u16 yPosition;
    u16 xPosition;

    slot = gCurrentSprite.primarySpriteRAMSlot;

    if (gSpriteData[slot].pose == IMAGO_COCOON_POSE_UNLOCK_PASSAGE)
    {
        yPosition = gCurrentSprite.yPosition;
        if (gCurrentSprite.roomSlot == IMAGO_COCOON_PART_VINE_LEFT_VINE_DECORATIONS)
            xPosition = gCurrentSprite.xPosition + BLOCK_SIZE;
        else
            xPosition = gCurrentSprite.xPosition - BLOCK_SIZE;

        ParticleSet(yPosition - 0x64, xPosition, PE_TWO_MEDIUM_DUST);
        gCurrentSprite.status = 0x0;
    }
    else if (gSubSpriteData1.health != 0x0 && gCurrentSprite.roomSlot == 0x0)
    {
        gCurrentSprite.yPositionSpawn++;
        if ((gCurrentSprite.yPositionSpawn & 0xFF) == 0x0)
        {
            if (gCurrentSprite.yPositionSpawn & 0x100)
            {
                // Spore on the left
                yPosition = gCurrentSprite.yPosition - IMAGO_COCOON_SPORE_LEFT_Y_OFFSET;
                xPosition = gCurrentSprite.xPosition - IMAGO_COCOON_SPORE_LEFT_X_OFFSET;
                status = SPRITE_STATUS_NONE;
            }
            else
            {
                // Spore on the right
                yPosition = gCurrentSprite.yPosition - IMAGO_COCOON_SPORE_RIGHT_Y_OFFSET;
                xPosition = gCurrentSprite.xPosition + IMAGO_COCOON_SPORE_RIGHT_X_OFFSET;
                status = SPRITE_STATUS_XFLIP;
            }

            // Spawn spores
            gfxSlot = gCurrentSprite.spritesetGFXSlot;
            ramSlot = gCurrentSprite.workVariable;
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, IMAGO_COCOON_SPORE_PART_DOWN, gfxSlot,
                ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, IMAGO_COCOON_SPORE_PART_DIAG_RIGHT_UP, gfxSlot,
                ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, IMAGO_COCOON_SPORE_PART_RIGHT, gfxSlot,
                ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, IMAGO_COCOON_SPORE_PART_DIAG_RIGHT_DOWN, gfxSlot,
                ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, IMAGO_COCOON_SPORE_PART_UP, gfxSlot,
                ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, IMAGO_COCOON_SPORE_PART_DIAG_LEFT_DOWN, gfxSlot,
                ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, IMAGO_COCOON_SPORE_PART_LEFT, gfxSlot,
                ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, IMAGO_COCOON_SPORE_PART_DIAG_LEFT_UP, gfxSlot,
                ramSlot, yPosition, xPosition, status);
        }
    }
}

/**
 * 27aec | 44 | Handles the Imago cocoon ceilig vine being idle
 * 
 */
void ImagoCocoonCeilingVineIdle(void)
{
    if (gSubSpriteData1.health == 0x0 && gSubSpriteData1.currentAnimationFrame > 0x7)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_CEILING_VINE_DEATH;
    }
}

/**
 * 27b30 | 44 | Handles the animation of the removal of the hanging vine when imago cocoon dies
 * 
 */
void ImagoCocoonCeilingVineDeath(void)
{
    u8 ramSlot;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gSpriteData[ramSlot].pose == IMAGO_COCOON_POSE_UNLOCK_PASSAGE)
    {
        ParticleSet(gCurrentSprite.yPosition + BLOCK_SIZE * 2 + HALF_BLOCK_SIZE, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_HUGE);
        gCurrentSprite.status = 0x0;
    }
}

/**
 * 27b74 | 54 | Synchronizes the spore position with the imago cocoon position
 * 
 */
void ImagoCocoonSporeSyncPosition(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - IMAGO_COCOON_SPORE_RIGHT_Y_OFFSET;
        gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition + IMAGO_COCOON_SPORE_RIGHT_X_OFFSET;
    }
    else
    {
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - IMAGO_COCOON_SPORE_LEFT_Y_OFFSET;
        gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition - IMAGO_COCOON_SPORE_LEFT_X_OFFSET;
    }
}

/**
 * 27bc8 | a8 | Initialize an imago cocoon spore sprite
 * 
 */
void ImagoCocoonSporeInit(void)
{
    // Only display the first spore for the nest
    if (gCurrentSprite.roomSlot == IMAGO_COCOON_SPORE_PART_DOWN)
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.drawDistanceTopOffset = 0xC;
    gCurrentSprite.drawDistanceBottomOffset = 0xC;
    gCurrentSprite.drawDistanceHorizontalOffset = 0xC;

    gCurrentSprite.hitboxTopOffset = -0x8;
    gCurrentSprite.hitboxBottomOffset = 0x8;
    gCurrentSprite.hitboxLeftOffset = -0x8;
    gCurrentSprite.hitboxRightOffset = 0x8;

    gCurrentSprite.pOam = sImagoCocoonSporeOAM_Spawning;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_SPAWNING;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawOrder = 0x3;
    gCurrentSprite.bgPriority = gIoRegistersBackup.BG1CNT & 0x3;

    gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    ImagoCocoonSporeSyncPosition();
}

/**
 * 27c70 | 74 | Handles an imago cocoon spore spawning
 * 
 */
void ImagoCocoonSporeSpawning(void)
{
    ImagoCocoonSporeSyncPosition();
    if (gSubSpriteData1.health == 0x0)
        gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_EXPLODING_INIT; // If imago cocoon is dead, kill the spores
    else
    {
        if (gCurrentSprite.roomSlot == 0x0 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN &&
            gCurrentSprite.currentAnimationFrame == 0x0 && gCurrentSprite.animationDurationCounter == 0x1)
            SoundPlay(0x1A0);

        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            // Set nest
            gCurrentSprite.pOam = sImagoCocoonSpore_Nest;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_NEST;
            gCurrentSprite.timer = 0x3C;
        }
    }
}

/**
 * 27ce4 | 8c | Handles an Imago cocoon spore being a nest 
 * 
 */
void ImagoCocoonSporeNest(void)
{
    ImagoCocoonSporeSyncPosition();
    if (gSubSpriteData1.health == 0x0)
        gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_EXPLODING_INIT; // If imago cocoon is dead, kill the spores
    else
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);

            gCurrentSprite.pOam = sImagoCocoonSpore_Moving;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
            gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_MOVING;

            if (gCurrentSprite.roomSlot == IMAGO_COCOON_SPORE_PART_DOWN && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(0x1A1);
        }
    }
}

/**
 * @brief 27d70 | 114 | Handles the movement of an Imago cocoon spore
 * 
 */
void ImagoCocoonSporeMove(void)
{
    u16 movement;

    movement = 0x4;
    switch (gCurrentSprite.roomSlot)
    {
        case IMAGO_COCOON_SPORE_PART_DIAG_RIGHT_UP:
            movement *= 0.8;
            gCurrentSprite.yPosition -= movement;
            gCurrentSprite.xPosition += movement;
            break;
        
        case IMAGO_COCOON_SPORE_PART_DIAG_RIGHT_DOWN:
            movement *= 0.8;
            gCurrentSprite.yPosition += movement;
            gCurrentSprite.xPosition += movement;
            break;
        
        case IMAGO_COCOON_SPORE_PART_RIGHT:
            gCurrentSprite.xPosition += movement;
            break;
        
        case IMAGO_COCOON_SPORE_PART_UP:
            gCurrentSprite.yPosition -= movement;
            break;
        
        case IMAGO_COCOON_SPORE_PART_DIAG_LEFT_DOWN:
            movement *= 0.8;
            gCurrentSprite.yPosition += movement;
            gCurrentSprite.xPosition -= movement;
            break;
        
        case IMAGO_COCOON_SPORE_PART_DIAG_LEFT_UP:
            movement *= 0.8;
            gCurrentSprite.yPosition -= movement;
            gCurrentSprite.xPosition -= movement;
            break;
        
        case IMAGO_COCOON_SPORE_PART_LEFT:
            gCurrentSprite.xPosition -= movement;
            break;

        default:
            gCurrentSprite.yPosition += movement;
    }

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousCollisionCheck & 0xF0)
        gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_EXPLODING_INIT;
}

/**
 * 27e84 | 34 | Initializes an Imago cocoon spore to b exploding
 * 
 */
void ImagoCocoonSporeExplodingInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    
    gCurrentSprite.pOam = sImagoCocoonSpore_Exploding;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_EXPLODING;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
}

/**
 * 27eb8 | 24 | Checks if the explosion animation has ended, if yes kills the sprite
 * 
 */
void ImagoCocoonSporeCheckExplodingAnimEnded(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}

/**
 * @brief 27edc | c4 | Checks if the winged ripper and the falling Imago cocoon are colliding 
 * 
 * @return u8 1 if colliding, 0 otherwise
 */
u8 WingedRipperImagoCollision(void)
{
    u8 colliding;
    u8 ramSlot;
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u16 imagoY;
    u16 imagoX;
    u16 imagoTop;
    u16 imagoBottom;
    u16 imagoLeft;
    u16 imagoRight;

    colliding = FALSE;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    if (gSpriteData[ramSlot].pose == IMAGO_COCOON_POSE_FALLING_BEFORE_BLOCKS && gSpriteData[ramSlot].arrayOffset > 0x10)
    {
        spriteY = gCurrentSprite.yPosition;
        spriteX = gCurrentSprite.xPosition;
        spriteTop = spriteY + gCurrentSprite.hitboxTopOffset;
        spriteBottom = spriteY + gCurrentSprite.hitboxBottomOffset;
        spriteLeft = spriteX + gCurrentSprite.hitboxLeftOffset;
        spriteRight = spriteX + gCurrentSprite.hitboxRightOffset;
        
        imagoY = gSpriteData[ramSlot].yPosition;
        imagoX = gSpriteData[ramSlot].xPosition;
        imagoTop = imagoY + gSpriteData[ramSlot].hitboxTopOffset;
        imagoBottom = imagoY + gSpriteData[ramSlot].hitboxBottomOffset;
        imagoLeft = imagoX + gSpriteData[ramSlot].hitboxLeftOffset;
        imagoRight = imagoX + gSpriteData[ramSlot].hitboxRightOffset;

        if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, imagoTop, imagoBottom, imagoLeft, imagoRight))
        {
            gCurrentSprite.pose = 0x62;
            colliding = TRUE;
        }
    }

    return colliding;
}

/**
 * @brief 27fa0 | a0 | Initializes a winged ripper sprite
 * 
 * @return * void 
 */
void WingedRipperInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.hitboxTopOffset = -0x20;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x20;
    gCurrentSprite.hitboxRightOffset = 0x20;

    gCurrentSprite.drawDistanceTopOffset = 0xC;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

    gCurrentSprite.pOam = sWingedRipperOAM_Moving;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.drawOrder = 0x8;

    gCurrentSprite.pose = WINGED_RIPPER_POSE_MOVING_INIT;
    gCurrentSprite.oamScaling = 0xC0;
    gCurrentSprite.workVariable = 0x80;

    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.frozenPaletteRowOffset = 0x4;
}

/**
 * @brief 28040 | 20 | Initializes a winged ripper to be moving
 * 
 */
void WingedRipperMovingInit(void)
{
    gCurrentSprite.pose = WINGED_RIPPER_POSE_MOVING;
    gCurrentSprite.pOam = sWingedRipperOAM_Moving;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
}

/**
 * @brief 28060 | 224 | Handles the movement of a winged ripper
 * 
 */
void WingedRipperMove(void)
{
    i32 radius;
    u8 angle;
    i32 previousY;
    i32 previousX;
    i32 s;
    i32 c;

    // Check turning around
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.workVariable == 0)
        {
            gCurrentSprite.xPositionSpawn += BLOCK_SIZE * 6;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.workVariable = PI - 1;
        }
        else if (gCurrentSprite.workVariable == PI)
        {
            if (gCurrentSprite.pOam != sWingedRipperOAM_TurningAround)
            {
                gCurrentSprite.pOam = sWingedRipperOAM_TurningAround;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
            }
        }
        else if (gCurrentSprite.pOam == sWingedRipperOAM_TurningAround && SpriteUtilCheckEndCurrentSpriteAnim())
        {
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            {
                gCurrentSprite.pOam = sWingedRipperOAM_Moving;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
            }
            else
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
        }
    }
    else
    {
        if (gCurrentSprite.workVariable == PI)
        {
            gCurrentSprite.xPositionSpawn -= BLOCK_SIZE * 6;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.workVariable = 1;
        }
        else if (gCurrentSprite.workVariable == 0x0)
        {
            if (gCurrentSprite.pOam != sWingedRipperOAM_TurningAround)
            {
                gCurrentSprite.pOam = sWingedRipperOAM_TurningAround;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
            }
        }
        else if (gCurrentSprite.pOam == sWingedRipperOAM_TurningAround && SpriteUtilCheckEndCurrentSpriteAnim())
        {
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            else
            {
                gCurrentSprite.pOam = sWingedRipperOAM_Moving;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
            }
        }
    }

    // Update angle
    if (gCurrentSprite.arrayOffset & 0x1)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.workVariable++;
        else
            gCurrentSprite.workVariable--;
    }

    radius = (i16)gCurrentSprite.oamScaling;
    angle = gCurrentSprite.workVariable;

    // Update Y position
    s = sin(angle);
    previousY = (i16)gCurrentSprite.yPosition;

    if (s < 0x0)
    {
        s = (i16)(-s * radius / 256);
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn - s;
    }
    else
    {
        s = (i16)(s * radius / 256);
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn + s;
    }

    // Update X position
    c = cos(angle);
    previousX = (i16)gCurrentSprite.xPosition;

    if (c < 0x0)
    {
        c = (i16)(-c * radius / 256);
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn - c;
    }
    else
    {
        c = (i16)(c * radius / 256);
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn + c;
    }

    s = (i16)gCurrentSprite.yPosition;
    c = (i16)gCurrentSprite.xPosition;
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP)
    {
        // Update samus standing on the winged ripper
        if (s > previousY)
        {
            previousY = (i16)(s - previousY);
            gSamusData.yPosition += previousY;
        }
        else
        {
            previousY = (i16)(previousY - s);
            gSamusData.yPosition -= previousY;
        }

        if (c > previousX)
        {
            previousX = (i16)(c - previousX);
            gSamusData.xPosition += previousX;
        }
        else
        {
            previousX = (i16)(previousX - c);
            gSamusData.xPosition -= previousX;
        }
    }

    WingedRipperImagoCollision();
}

/**
 * @brief 28284 | 44 | Handles the winged ripper death
 * 
 */
void WingedRipperDeath(void)
{
    if (gCurrentSprite.standingOnSprite)
    {
        if (gSamusData.standingStatus == STANDING_ENEMY)
            gSamusData.standingStatus = STANDING_MIDAIR;
        gCurrentSprite.standingOnSprite = FALSE;
    }

    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition + 0x8, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
}

/**
 * @brief 282c8 | 104 | Imago cocoon AI
 * 
 */
void ImagoCocoon(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ImagoCocoonInit();
            break;

        case IMAGO_COCOON_POSE_IDLE:
            ImagoCocoonIdle();
            break;

        case IMAGO_COCOON_POSE_FALLING_BEFORE_BLOCKS:
            ImagoCocoonFallingBeforeBlocks();
            break;

        case IMAGO_COCOON_POSE_FALLING_AFTER_BLOCKS:
            ImagoCocoonFallingAfterBlocks();
            break;

        case IMAGO_COCOON_POSE_UNLOCK_PASSAGE:
            ImagoCocoonUnlockPassage();
            break;

        case IMAGO_COCOON_POSE_IN_GROUND:
            ImagoCocoonInGround();
    }

    SpriteUtilUpdateSubSprite1Anim();
    if (gCurrentSprite.pose >= IMAGO_COCOON_POSE_UNLOCK_PASSAGE)
        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    else
        ImagoCocoonSyncSprites();
}

/**
 * @brief 283cc | 70 | Imago cocoon vine AI
 * 
 */
void ImagoCocoonVine(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ImagoCocoonVineInit();
            break;

        case 0x62:
            ImagoCocoonVineDeath();

        case IMAGO_COCOON_VINE_POSE_IDLE:
            ImagoCocoonVineCheckPlayDamagedSound();
            break;

        case IMAGO_COCOON_VINE_POSE_SPAWN_SPORES:
            ImagoCocoonVineSpawnSpore();
            break;
            
        case IMAGO_COCOON_VINE_POSE_CEILING_VINE_IDLE:
            ImagoCocoonCeilingVineIdle();
            break;

        case IMAGO_COCOON_VINE_POSE_CEILING_VINE_DEATH:
            ImagoCocoonCeilingVineDeath();
    }

    if (gCurrentSprite.pose == 0x67)
        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    else
        ImagoCocoonSyncSprites();
}

/**
 * @brief 2843c | 8c | Imago cocoon spore AI
 * 
 */
void ImagoCocoonSpore(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ImagoCocoonSporeInit();
            break;

        case IMAGO_COCOON_SPORE_POSE_SPAWNING:
            ImagoCocoonSporeSpawning();
            break;

        case IMAGO_COCOON_SPORE_POSE_NEST:
            ImagoCocoonSporeNest();
            break;

        case IMAGO_COCOON_SPORE_POSE_MOVING:
            ImagoCocoonSporeMove();
            break;

        case IMAGO_COCOON_SPORE_POSE_EXPLODING_INIT:
            ImagoCocoonSporeExplodingInit();
            break;

        case IMAGO_COCOON_SPORE_POSE_EXPLODING:
            ImagoCocoonSporeCheckExplodingAnimEnded();
            break;
        default:
            // Kill sprite
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);

            if (gCurrentSprite.status & SPRITE_STATUS_EXISTS && SpriteUtilCountDrops() > 0x1)
                gCurrentSprite.status = 0x0; // Anti lag measure
    }
}

/**
 * @brief 284c8 | 6c | Winged ripper AI
 * 
 */
void WingedRipper(void)
{
    if (gCurrentSprite.freezeTimer != 0x0)
    {
        SpriteUtilUnfreezeAnimEasy();
        if (!(WingedRipperImagoCollision()))
            return;
    }

    if (SpriteUtilIsSpriteStunned())
        return;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            WingedRipperInit();
            break;

        case WINGED_RIPPER_POSE_MOVING_INIT:
            WingedRipperMovingInit();

        case WINGED_RIPPER_POSE_MOVING:
            WingedRipperMove();
            break;

        default:
            WingedRipperDeath();
    }

    // Increment sine offset timer
    gCurrentSprite.arrayOffset++;
}

/**
 * @brief 28534 | 78 | Defeated Imago cocoon AI
 * 
 */
void DefeatedImagoCocoon(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        gCurrentSprite.drawDistanceTopOffset = 0xC;
        gCurrentSprite.drawDistanceBottomOffset = 0x28;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x30;

        gCurrentSprite.hitboxTopOffset = -0x4;
        gCurrentSprite.hitboxBottomOffset = 0x4;
        gCurrentSprite.hitboxLeftOffset = -0x4;
        gCurrentSprite.hitboxRightOffset = 0x4;

        gCurrentSprite.pOam = sDefeatedImagoCocoonOAM;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x5;
    }
}

/**
 * @brief 285ac | 7c | Imago cocoon ceiling vine AI
 * 
 */
void ImagoCocoonCeilingVine(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        gCurrentSprite.drawDistanceTopOffset = 0xC;
        gCurrentSprite.drawDistanceBottomOffset = 0x28;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x30;

        gCurrentSprite.hitboxTopOffset = -0x4;
        gCurrentSprite.hitboxBottomOffset = 0x4;
        gCurrentSprite.hitboxLeftOffset = -0x4;
        gCurrentSprite.hitboxRightOffset = 0x4;

        gCurrentSprite.pOam = sImagoCocoonOAM_CeilingVineBroken;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawOrder = 0x5;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x5;
    }
}

/**
 * @brief 28628 | 90 | Event trigger (discovered Imago passage) AI
 * 
 */
void EventTriggerDiscoveredImagoPassage(void)
{
    if (gCurrentSprite.pose == 0x0)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_IMAGO_TUNNEL_DISCOVERED))
        {
            gCurrentSprite.status = 0x0;
            return;
        }
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;

        gCurrentSprite.drawDistanceTopOffset = 0x10;
        gCurrentSprite.drawDistanceBottomOffset = 0x0;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

        gCurrentSprite.hitboxTopOffset = -0x40;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = -0x20;
        gCurrentSprite.hitboxRightOffset = 0x20;

        gCurrentSprite.pose = 0x8;
        gCurrentSprite.pOam = sEnemyDropOAM_LargeEnergy;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        // Set event
        gCurrentSprite.status = 0x0;
        EventFunction(EVENT_ACTION_SETTING, EVENT_IMAGO_TUNNEL_DISCOVERED);
    }
}

/**
 * @brief 286b8 | 74 | Imago cocoon after fight AI
 * 
 */
void ImagoCocoonAfterFight(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.drawDistanceTopOffset = 0x30;
        gCurrentSprite.drawDistanceBottomOffset = 0x10;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

        gCurrentSprite.hitboxTopOffset = -0x4;
        gCurrentSprite.hitboxBottomOffset = 0x4;
        gCurrentSprite.hitboxLeftOffset = -0x4;
        gCurrentSprite.hitboxRightOffset = 0x4;

        gCurrentSprite.pOam = sDefeatedImagoCocoonOAM;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = 0x9;
    }

    if (gCurrentSprite.animationDurationCounter == 0x1)
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 0x0:
            case 0x4:
                SoundPlay(0x212);
        }
    }
}