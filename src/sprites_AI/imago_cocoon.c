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
    MultiSpriteDataInfo_T pData;
    u16 oamIdx;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];
    
    if (gCurrentSprite.pOam != sImagoCocoonFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sImagoCocoonFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

/**
 * 26ca0 | 40 | Updates the clipdata of the middle block of the ground when falling
 * 
 * @param caa Clipdata Affecting Action
 */
void ImagoCocoonChangeOneCcaa(u8 caa)
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
void ImagoCocoonChangeTwoMiddleCcaa(u8 caa)
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

    ParticleSet(yPosition, xPosition + (BLOCK_SIZE + EIGHTH_BLOCK_SIZE), PE_SPRITE_EXPLOSION_HUGE);
    ParticleSet(yPosition, xPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE), PE_SPRITE_EXPLOSION_HUGE);
}

/**
 * @brief 26d50 | 7c | Updates the clipdata of the 2 blocks at the edge of the ground when falling
 * 
 * @param caa Clipdata Affecting Action
 */
void ImagoCocoonChangeTwoAroundCcaa(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 11;
    xPosition = gSubSpriteData1.xPosition;

    // Right block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - HALF_BLOCK_SIZE, xPosition + BLOCK_SIZE * 2);

    // Left block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - HALF_BLOCK_SIZE, xPosition - BLOCK_SIZE * 2);

    ParticleSet(yPosition, xPosition + BLOCK_SIZE * 2, PE_SPRITE_EXPLOSION_HUGE);
    ParticleSet(yPosition, xPosition - BLOCK_SIZE * 2, PE_SPRITE_EXPLOSION_HUGE);
}

/**
 * 26dcc | 5c | Updates the current clipdata affecting action and applies it, removes the 2 blocks that block the passage
 * 
 * @param caa Clipdata Affecting Action
 */
void ImagoCocoonChangeTwoBlockingCcaa(u8 caa)
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
    if (gCurrentSprite.work2) // Check growing/shrinking
    {
        if (gCurrentSprite.scaling > (Q_8_8(1.f) - limit))
            gCurrentSprite.scaling -= value;
        else
            gCurrentSprite.work2 = FALSE; // Set growing
    }
    else
    {
        if (gCurrentSprite.scaling < (Q_8_8(1.f) + limit))
            gCurrentSprite.scaling += value;
        else
            gCurrentSprite.work2 = TRUE; // Set shrinking
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
        SpriteSpawnSecondary(SSPRITE_IMAGO_CEILING_VINE, 0, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);

        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ENTER_RIDLEY_DEMO_PLAYED))
            gCurrentSprite.status = 0;
        else
        {
            // Set in tunnel

            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.drawOrder = 4;
            gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING;
            gCurrentSprite.scaling = Q_8_8(1.f);
            gCurrentSprite.rotation = 0;
            gCurrentSprite.roomSlot = IMAGO_COCOON_PART_IMAGO_COCOON;

            gSubSpriteData1.pMultiOam = sImagoCocoonMultiSpriteData_Idle;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;

            gCurrentSprite.pOam = sImagoCocoonOam_Static;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = IMAGO_COCOON_POSE_IN_GROUND;
            gSubSpriteData1.yPosition += BLOCK_SIZE * 15;
        }
    }
    else
    {
        yPosition = gSubSpriteData1.yPosition;
        xPosition = gSubSpriteData1.xPosition;
        gCurrentSprite.yPositionSpawn = yPosition;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE + HALF_BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -(2 * BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE;

        gCurrentSprite.drawOrder = 6;
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING;

        gCurrentSprite.scaling = Q_8_8(1.f);
        gCurrentSprite.rotation = 0;
        gCurrentSprite.work2 = FALSE;

        gSubSpriteData1.pMultiOam = sImagoCocoonMultiSpriteData_Idle;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        
        gSubSpriteData1.workVariable2 = 0;
        gSubSpriteData1.workVariable1 = 0;
        // Number of vines alive
        gSubSpriteData1.health = 6;

        LOCK_DOORS();
        gCurrentSprite.pose = IMAGO_COCOON_POSE_IDLE;
        gCurrentSprite.roomSlot = IMAGO_COCOON_PART_IMAGO_COCOON;

        gfxSlot = gCurrentSprite.spritesetGfxSlot;
        ramSlot = gCurrentSprite.primarySpriteRamSlot;

        // Spawn vines
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_LEFT_MIDDLE, gfxSlot, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_RIGHT_MIDDLE, gfxSlot, ramSlot, yPosition, xPosition, 0);

        // Save RAM slot of self for the spores
        newRamSlot = SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_LEFT_VINE_DECORATIONS,
            gfxSlot, ramSlot, yPosition, xPosition, 0);
        gSpriteData[newRamSlot].work1 = newRamSlot;

        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_CEILING_VINE, gfxSlot, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_RIGHT_VINE_DECORATIONS, gfxSlot, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_RIGHT_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_LEFT_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_RIGHT_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_VINE, IMAGO_COCOON_PART_VINE_LEFT_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0);
        
        // Spawn winged ripper
        newRamSlot = SpriteSpawnSecondary(SSPRITE_WINGED_RIPPER, 0, gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 4, xPosition, SPRITE_STATUS_X_FLIP);
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

    if (gCurrentSprite.work3 < CONVERT_SECONDS(0.8f))
        APPLY_DELTA_TIME_INC(gCurrentSprite.work3);

    // Every 4 frames, add one sub pixel to the falling speed
    // 4 * DELTA_TIME
    increment = DIV_SHIFT(gCurrentSprite.work3, 4) + EIGHTH_BLOCK_SIZE;
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
                FadeMusic(CONVERT_SECONDS(1.f) + ONE_THIRD_SECOND);
                gBossWork.work1 = IMAGO_COCOON_MUSIC_STAGE_STARTED_FADING;
            }
        }
        else if (gBossWork.work1 == IMAGO_COCOON_MUSIC_STAGE_STARTED_FADING)
        {
            if (gSubSpriteData1.xPosition < gSamusData.xPosition && gSamusData.xPosition - gSubSpriteData1.xPosition < BLOCK_SIZE * 7)
            {
                PlayMusic(MUSIC_IMAGO_COCOON_BATTLE, 0);
                gBossWork.work1 = IMAGO_COCOON_MUSIC_STAGE_STARTED_MUSIC;
            }
        }
    }

    // Check play idle sound
    caf = gCurrentSprite.currentAnimationFrame;
    if (gCurrentSprite.animationDurationCounter == 1 * DELTA_TIME)
    {
        switch (caf)
        {
            case 0:
            case 2 * DELTA_TIME:
                SoundPlay(SOUND_IMAGO_COCOON_IDLE);
        }
    }

    // Check change palette
    if (gSubSpriteData1.health < 4)
    {
        gCurrentSprite.paletteRow = 1;
        gCurrentSprite.absolutePaletteRow = 1;
        // CONVERT_SECONDS(1.f) + 4 * DELTA_TIME
        if (MOD_AND(gFrameCounter8Bit, 64) == 0)
            ImagoCocoonChangeOAMScaling(1, 1);
    }

    // Check should fall
    if (gSubSpriteData1.health == 0)
    {
        // All vines dead, set falling
        gCurrentSprite.paletteRow = 2;
        gCurrentSprite.absolutePaletteRow = 2;

        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_NONE;

        gSubSpriteData1.pMultiOam = sImagoCocoonMultiSpriteData_Dying;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        gCurrentSprite.work0 = 0;
        gCurrentSprite.work3 = 0;
        gCurrentSprite.pose = IMAGO_COCOON_POSE_FALLING_BEFORE_BLOCKS;

        // Set falling
        EventFunction(EVENT_ACTION_SETTING, EVENT_IMAGO_COCOON_KILLED);
        SoundPlay(SOUND_IMAGO_COCOON_VINES_CRACKING);
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

    // CONVERT_SECONDS(.5f) + 2 * DELTA_TIME
    if (MOD_AND(gFrameCounter8Bit, 32) == 0)
        ImagoCocoonChangeOAMScaling(1, 1);

    if (gSubSpriteData1.currentAnimationFrame > 7)
    {
        ImagoCocoonFallingMovement();
        yPosition = gSubSpriteData1.yPosition + BLOCK_SIZE * 6;
        xPosition = gSubSpriteData1.xPosition;
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition);
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0) // Check for solid collision
        {
            ImagoCocoonChangeOneCcaa(CAA_REMOVE_SOLID); // Remove middle block

            // Set falling after blocks
            gCurrentSprite.pose = IMAGO_COCOON_POSE_FALLING_AFTER_BLOCKS;
            gCurrentSprite.work0 = 0;
            ScreenShakeStartVertical(TWO_THIRD_SECOND, 0x80 | 1);
            SoundPlay(SOUND_IMAGO_COCOON_DESTROYING_BLOCKS);
        }
    }
    else
    {
        if (gSubSpriteData1.currentAnimationFrame == 7 && gSubSpriteData1.animationDurationCounter == 6 * DELTA_TIME)
        {
            SpriteSpawnSecondary(SSPRITE_IMAGO_CEILING_VINE, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
        }

        yPosition = gBg1YPosition - BLOCK_SIZE;
        xPosition = gSubSpriteData1.xPosition;
        rng = gSpriteRng;
        
        timer = APPLY_DELTA_TIME_INC(gCurrentSprite.work0);
        // CONVERT_SECONDS(.5f) + 2 * DELTA_TIME
        if (MOD_AND(timer, 32) == 0)
        {
            if (timer & 32)
                SpriteDebrisInit(0, 5, yPosition, xPosition + (BLOCK_SIZE + HALF_BLOCK_SIZE - PIXEL_SIZE - PIXEL_SIZE / 2) - (rng * 8));
            else
                SpriteDebrisInit(0, 7, yPosition, xPosition - (BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2) + (rng * 8));
        }

        // 2 * DELTA_TIME
        if (gSubSpriteData1.currentAnimationFrame > 3 && MOD_AND(timer, 2) == 0)
        {
            if (rng > 7)
            {
                SpriteDebrisInit(0, 8, yPosition, xPosition - (2 * BLOCK_SIZE + QUARTER_BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2) + (rng * 4));
                SpriteDebrisInit(0, 6, yPosition, xPosition + HALF_BLOCK_SIZE - (rng * 4));
            }
            else
            {
                SpriteDebrisInit(0, 6, yPosition, xPosition + (2 * BLOCK_SIZE + PIXEL_SIZE / 2) - (rng * 4));
                SpriteDebrisInit(0, 8, yPosition, xPosition - HALF_BLOCK_SIZE + (rng * 4));
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
    // 2 * DELTA_TIME
    if (MOD_AND(gFrameCounter8Bit, 2) == 0)
        ImagoCocoonChangeOAMScaling(1, 1);

    ImagoCocoonFallingMovement();
    yPosition = gSubSpriteData1.yPosition + IMAGO_COCOON_SIZE;
    xPosition = gSubSpriteData1.xPosition;

    // Destroy ground/set effects
    APPLY_DELTA_TIME_INC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == CONVERT_SECONDS(1.f / 15))
        ImagoCocoonChangeTwoMiddleCcaa(CAA_REMOVE_SOLID);
    else if (gCurrentSprite.work0 == CONVERT_SECONDS(2.f / 15))
        ImagoCocoonChangeTwoAroundCcaa(CAA_REMOVE_SOLID);
    else if (gCurrentSprite.work0 == CONVERT_SECONDS(.25f))
    {
        ParticleSet(yPosition + (3 * BLOCK_SIZE), xPosition + (BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE), PE_TWO_MEDIUM_DUST);
        ParticleSet(yPosition + (3 * BLOCK_SIZE), xPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE), PE_TWO_MEDIUM_DUST);
        ParticleSet(yPosition + (3 * BLOCK_SIZE), xPosition, PE_SPRITE_EXPLOSION_HUGE);
    }

    topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(yPosition, xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        // Touched ground
        gCurrentSprite.pOam = sImagoCocoonOam_Static;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        
        gCurrentSprite.paletteRow = 0;
        gCurrentSprite.absolutePaletteRow = 0;

        gSubSpriteData1.yPosition = topEdge - IMAGO_COCOON_SIZE;
        gCurrentSprite.pose = IMAGO_COCOON_POSE_UNLOCK_PASSAGE;
        gCurrentSprite.work0 = CONVERT_SECONDS(1.5f);

        ScreenShakeStartVertical(TWO_THIRD_SECOND, 0x80 | 1);
        SoundPlay(SOUND_IMAGO_COCOON_CRASHING);

        gCurrentSprite.scaling = Q_8_8(1.f);
        gCurrentSprite.work2 = FALSE;

        FadeMusic(CONVERT_SECONDS(1.f) + CONVERT_SECONDS(5.f / 12)); // 1.4 + 1 * DELTA_TIME
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
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.pose = IMAGO_COCOON_POSE_IN_GROUND;
            ImagoCocoonChangeTwoBlockingCcaa(CAA_REMOVE_SOLID); // Remove blocking collision

            gDoorUnlockTimer = -CONVERT_SECONDS(1.f);
            PlayMusic(MUSIC_BOSS_KILLED, 0);
        }
    }
}

/**
 * @brief 2753c | 70 | Handles Imago cocoon being in the ground
 * 
 */
void ImagoCocoonInGround(void)
{
    // 4 * DELTA_TIME
    if (MOD_AND(gFrameCounter8Bit, 4) == 0)
    {
        if (gCurrentSprite.work2)
        {
            // Scale up
            if (gCurrentSprite.scaling > Q_8_8(1.f - 1.f / 64))
            {
                gCurrentSprite.scaling--;
                gSubSpriteData1.yPosition -= ONE_SUB_PIXEL;
            }
            else
            {
                gCurrentSprite.work2 = FALSE;
                SoundPlay(SOUND_IMAGO_COCOON_IN_GROUND);
            }
        }
        else
        {
            // Scale down
            if (gCurrentSprite.scaling < Q_8_8(1.f + 1.f / 64))
            {
                gCurrentSprite.scaling++;
                gSubSpriteData1.yPosition += ONE_SUB_PIXEL;
            }
            else
                gCurrentSprite.work2 = TRUE;
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
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;

            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 4;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_RIGHT_MIDDLE:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = BLOCK_SIZE + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;

            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 4;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_RIGHT_RIGHT:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = BLOCK_SIZE + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;

            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 4;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_LEFT_LEFT:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = 2 * BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 4;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_RIGHT_LEFT:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE - EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = BLOCK_SIZE - EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;

            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 7;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_LEFT_RIGHT:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE - EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = BLOCK_SIZE - EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;

            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 7;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_IDLE;
            break;

        case IMAGO_COCOON_PART_VINE_LEFT_VINE_DECORATIONS:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -PIXEL_SIZE;
            gCurrentSprite.hitboxBottom = PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
            gCurrentSprite.hitboxRight = PIXEL_SIZE;

            // Set spawning spores behavior
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_SPAWN_SPORES;
            gCurrentSprite.yPositionSpawn = 0;
            break;

        case IMAGO_COCOON_PART_VINE_RIGHT_VINE_DECORATIONS:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -PIXEL_SIZE;
            gCurrentSprite.hitboxBottom = PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
            gCurrentSprite.hitboxRight = PIXEL_SIZE;

            // Set spawning spores behavior
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 8;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_SPAWN_SPORES;
            break;

        case IMAGO_COCOON_PART_CEILING_VINE:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = 2 * BLOCK_SIZE + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

            gCurrentSprite.health = 1;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 5;
            gCurrentSprite.pose = IMAGO_COCOON_VINE_POSE_CEILING_VINE_IDLE;

            gCurrentSprite.frozenPaletteRowOffset = 5;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            break;

        default:
            gCurrentSprite.status = 0;
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
            SoundPlayNotAlreadyPlaying(SOUND_IMAGO_COCOON_VINE_DAMAGED);
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
            gCurrentSprite.status = 0;
            return;
    }

    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_HUGE);

    // Decrement number of vines alive
    if (gSubSpriteData1.health != 0)
        gSubSpriteData1.health--;
    gCurrentSprite.status = 0;
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

    slot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[slot].pose == IMAGO_COCOON_POSE_UNLOCK_PASSAGE)
    {
        yPosition = gCurrentSprite.yPosition;
        if (gCurrentSprite.roomSlot == IMAGO_COCOON_PART_VINE_LEFT_VINE_DECORATIONS)
            xPosition = gCurrentSprite.xPosition + BLOCK_SIZE;
        else
            xPosition = gCurrentSprite.xPosition - BLOCK_SIZE;

        ParticleSet(yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE), xPosition, PE_TWO_MEDIUM_DUST);
        gCurrentSprite.status = 0;
    }
    else if (gSubSpriteData1.health != 0 && gCurrentSprite.roomSlot == 0)
    {
        gCurrentSprite.yPositionSpawn += ONE_SUB_PIXEL;
        // 4 * BLOCK_SIZE
        if (MOD_AND(gCurrentSprite.yPositionSpawn, 256) == 0)
        {
            if (gCurrentSprite.yPositionSpawn & 256)
            {
                // Spore on the left
                yPosition = gCurrentSprite.yPosition - IMAGO_COCOON_SPORE_LEFT_Y_OFFSET;
                xPosition = gCurrentSprite.xPosition - IMAGO_COCOON_SPORE_LEFT_X_OFFSET;
                status = 0;
            }
            else
            {
                // Spore on the right
                yPosition = gCurrentSprite.yPosition - IMAGO_COCOON_SPORE_RIGHT_Y_OFFSET;
                xPosition = gCurrentSprite.xPosition + IMAGO_COCOON_SPORE_RIGHT_X_OFFSET;
                status = SPRITE_STATUS_X_FLIP;
            }

            // Spawn spores
            gfxSlot = gCurrentSprite.spritesetGfxSlot;
            ramSlot = gCurrentSprite.work1;
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
    if (gSubSpriteData1.health == 0 && gSubSpriteData1.currentAnimationFrame > 7)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
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

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[ramSlot].pose == IMAGO_COCOON_POSE_UNLOCK_PASSAGE)
    {
        ParticleSet(gCurrentSprite.yPosition + BLOCK_SIZE * 2 + HALF_BLOCK_SIZE, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_HUGE);
        gCurrentSprite.status = 0;
    }
}

/**
 * 27b74 | 54 | Synchronizes the spore position with the imago cocoon position
 * 
 */
void ImagoCocoonSporeSyncPosition(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
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

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -EIGHTH_BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = EIGHTH_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -EIGHTH_BLOCK_SIZE;
    gCurrentSprite.hitboxRight = EIGHTH_BLOCK_SIZE;

    gCurrentSprite.pOam = sImagoCocoonSporeOam_Spawning;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_SPAWNING;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.bgPriority = gIoRegistersBackup.BG1CNT & 3;

    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    ImagoCocoonSporeSyncPosition();
}

/**
 * 27c70 | 74 | Handles an imago cocoon spore spawning
 * 
 */
void ImagoCocoonSporeSpawning(void)
{
    ImagoCocoonSporeSyncPosition();
    if (gSubSpriteData1.health == 0)
        gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_EXPLODING_INIT; // If imago cocoon is dead, kill the spores
    else
    {
        if (gCurrentSprite.roomSlot == 0 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN &&
            gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1 * DELTA_TIME)
            SoundPlay(SOUND_IMAGO_COCOON_SPORE_SPAWNING);

        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            // Set nest
            gCurrentSprite.pOam = sImagoCocoonSpore_Nest;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_NEST;
            gCurrentSprite.work0 = CONVERT_SECONDS(1.f);
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
    if (gSubSpriteData1.health == 0)
        gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_EXPLODING_INIT; // If imago cocoon is dead, kill the spores
    else
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);

            gCurrentSprite.pOam = sImagoCocoonSpore_Moving;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
            gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_MOVING;

            if (gCurrentSprite.roomSlot == IMAGO_COCOON_SPORE_PART_DOWN && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(SOUND_IMAGO_COCOON_SPORE_NEST_SPAWNING);
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

    movement = PIXEL_SIZE;
    switch (gCurrentSprite.roomSlot)
    {
        case IMAGO_COCOON_SPORE_PART_DIAG_RIGHT_UP:
            movement *= 0.8; // 4 * 0.8 = 3.2
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
    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_EXPLODING_INIT;
}

/**
 * 27e84 | 34 | Initializes an Imago cocoon spore to b exploding
 * 
 */
void ImagoCocoonSporeExplodingInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    
    gCurrentSprite.pOam = sImagoCocoonSpore_Exploding;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = IMAGO_COCOON_SPORE_POSE_EXPLODING;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
}

/**
 * 27eb8 | 24 | Checks if the explosion animation has ended, if yes kills the sprite
 * 
 */
void ImagoCocoonSporeCheckExplodingAnimEnded(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0;
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
    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (gSpriteData[ramSlot].pose == IMAGO_COCOON_POSE_FALLING_BEFORE_BLOCKS && gSpriteData[ramSlot].work3 > CONVERT_SECONDS(.25f) + 1 * DELTA_TIME)
    {
        spriteY = gCurrentSprite.yPosition;
        spriteX = gCurrentSprite.xPosition;
        spriteTop = spriteY + gCurrentSprite.hitboxTop;
        spriteBottom = spriteY + gCurrentSprite.hitboxBottom;
        spriteLeft = spriteX + gCurrentSprite.hitboxLeft;
        spriteRight = spriteX + gCurrentSprite.hitboxRight;
        
        imagoY = gSpriteData[ramSlot].yPosition;
        imagoX = gSpriteData[ramSlot].xPosition;
        imagoTop = imagoY + gSpriteData[ramSlot].hitboxTop;
        imagoBottom = imagoY + gSpriteData[ramSlot].hitboxBottom;
        imagoLeft = imagoX + gSpriteData[ramSlot].hitboxLeft;
        imagoRight = imagoX + gSpriteData[ramSlot].hitboxRight;

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

    gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    gCurrentSprite.pOam = sWingedRipperOam_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.drawOrder = 8;

    gCurrentSprite.pose = WINGED_RIPPER_POSE_MOVING_INIT;
    gCurrentSprite.scaling = Q_8_8(.75f);
    gCurrentSprite.work1 = PI;

    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.frozenPaletteRowOffset = 4;
}

/**
 * @brief 28040 | 20 | Initializes a winged ripper to be moving
 * 
 */
void WingedRipperMovingInit(void)
{
    gCurrentSprite.pose = WINGED_RIPPER_POSE_MOVING;
    gCurrentSprite.pOam = sWingedRipperOam_Moving;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;
}

/**
 * @brief 28060 | 224 | Handles the movement of a winged ripper
 * 
 */
void WingedRipperMove(void)
{
    s32 radius;
    u8 angle;
    s32 previousY;
    s32 previousX;
    s32 s;
    s32 c;

    // Check turning around
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.work1 == 0)
        {
            gCurrentSprite.xPositionSpawn += BLOCK_SIZE * 6;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.work1 = PI - 1;
        }
        else if (gCurrentSprite.work1 == PI)
        {
            if (gCurrentSprite.pOam != sWingedRipperOam_TurningAround)
            {
                gCurrentSprite.pOam = sWingedRipperOam_TurningAround;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;
            }
        }
        else if (gCurrentSprite.pOam == sWingedRipperOam_TurningAround && SpriteUtilCheckEndCurrentSpriteAnim())
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                gCurrentSprite.pOam = sWingedRipperOam_Moving;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;
            }
            else
                gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
        }
    }
    else
    {
        if (gCurrentSprite.work1 == PI)
        {
            gCurrentSprite.xPositionSpawn -= BLOCK_SIZE * 6;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.work1 = 1;
        }
        else if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.pOam != sWingedRipperOam_TurningAround)
            {
                gCurrentSprite.pOam = sWingedRipperOam_TurningAround;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;
            }
        }
        else if (gCurrentSprite.pOam == sWingedRipperOam_TurningAround && SpriteUtilCheckEndCurrentSpriteAnim())
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            else
            {
                gCurrentSprite.pOam = sWingedRipperOam_Moving;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;
            }
        }
    }

    // Update angle
    // 2 * DELTA_TIME
    if (MOD_AND(gCurrentSprite.work3, 2))
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.work1++;
        else
            gCurrentSprite.work1--;
    }

    radius = (s16)gCurrentSprite.scaling;
    angle = gCurrentSprite.work1;

    // Update Y position
    s = sin(angle);
    previousY = (s16)gCurrentSprite.yPosition;

    if (s < 0)
    {
        s = (s16)(-s * radius / Q_8_8(1.f));
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn - s;
    }
    else
    {
        s = (s16)(s * radius / Q_8_8(1.f));
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn + s;
    }

    // Update X position
    c = cos(angle);
    previousX = (s16)gCurrentSprite.xPosition;

    if (c < 0)
    {
        c = (s16)(-c * radius / Q_8_8(1.f));
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn - c;
    }
    else
    {
        c = (s16)(c * radius / Q_8_8(1.f));
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn + c;
    }

    s = (s16)gCurrentSprite.yPosition;
    c = (s16)gCurrentSprite.xPosition;
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP)
    {
        // Update samus standing on the winged ripper
        if (s > previousY)
        {
            previousY = (s16)(s - previousY);
            gSamusData.yPosition += previousY;
        }
        else
        {
            previousY = (s16)(previousY - s);
            gSamusData.yPosition -= previousY;
        }

        if (c > previousX)
        {
            previousX = (s16)(c - previousX);
            gSamusData.xPosition += previousX;
        }
        else
        {
            previousX = (s16)(previousX - c);
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
    if (gCurrentSprite.standingOnSprite != SAMUS_STANDING_ON_SPRITE_OFF)
    {
        if (gSamusData.standingStatus == STANDING_ENEMY)
            gSamusData.standingStatus = STANDING_MIDAIR;
        gCurrentSprite.standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;
    }

    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition + EIGHTH_BLOCK_SIZE, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
}

/**
 * @brief 282c8 | 104 | Imago cocoon AI
 * 
 */
void ImagoCocoon(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
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
        case SPRITE_POSE_UNINITIALIZED:
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
        case SPRITE_POSE_UNINITIALIZED:
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

            if (gCurrentSprite.status & SPRITE_STATUS_EXISTS && SpriteUtilCountDrops() > 1)
                gCurrentSprite.status = 0; // Anti lag measure
    }
}

/**
 * @brief 284c8 | 6c | Winged ripper AI
 * 
 */
void WingedRipper(void)
{
    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUnfreezeAnimEasy();
        if (!(WingedRipperImagoCollision()))
            return;
    }

    if (SpriteUtilIsSpriteStunned())
        return;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
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
    APPLY_DELTA_TIME_INC(gCurrentSprite.work3);
}

/**
 * @brief 28534 | 78 | Defeated Imago cocoon AI
 * 
 */
void DefeatedImagoCocoon(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -PIXEL_SIZE;
        gCurrentSprite.hitboxBottom = PIXEL_SIZE;
        gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
        gCurrentSprite.hitboxRight = PIXEL_SIZE;

        gCurrentSprite.pOam = sDefeatedImagoCocoonOam;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 5;
    }
}

/**
 * @brief 285ac | 7c | Imago cocoon ceiling vine AI
 * 
 */
void ImagoCocoonCeilingVine(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -PIXEL_SIZE;
        gCurrentSprite.hitboxBottom = PIXEL_SIZE;
        gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
        gCurrentSprite.hitboxRight = PIXEL_SIZE;

        gCurrentSprite.pOam = sImagoCocoonOam_CeilingVineBroken;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawOrder = 5;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 5;
    }
}

/**
 * @brief 28628 | 90 | Event trigger (discovered Imago passage) AI
 * 
 */
void EventTriggerDiscoveredImagoPassage(void)
{
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_IMAGO_TUNNEL_DISCOVERED))
        {
            gCurrentSprite.status = 0;
            return;
        }
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_CHECK_COLLIDING;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -BLOCK_SIZE;
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

        gCurrentSprite.pose = 0x8;
        gCurrentSprite.pOam = sEnemyDropOAM_LargeEnergy;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        // Set event
        gCurrentSprite.status = 0;
        EventFunction(EVENT_ACTION_SETTING, EVENT_IMAGO_TUNNEL_DISCOVERED);
    }
}

/**
 * @brief 286b8 | 74 | Imago cocoon after fight AI
 * 
 */
void ImagoCocoonAfterFight(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -PIXEL_SIZE;
        gCurrentSprite.hitboxBottom = PIXEL_SIZE;
        gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
        gCurrentSprite.hitboxRight = PIXEL_SIZE;

        gCurrentSprite.pOam = sDefeatedImagoCocoonOam;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = 0x9;
    }

    if (gCurrentSprite.animationDurationCounter == 1 * DELTA_TIME)
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 0:
            case 4:
                SoundPlay(SOUND_IMAGO_COCOON_IN_GROUND_IDLE);
        }
    }
}