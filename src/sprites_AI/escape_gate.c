#include "sprites_AI/escape_gate.h"
#include "gba.h"
#include "macros.h"

#include "data/sprites/escape_gate.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"
#include "structs/clipdata.h"

/**
 * @brief 4e910 | b0 | Updates the hitbox of the escape gate
 * 
 * @param caa Clipdata Affecting Action
 */
void EscapeGateChangeCcaa(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPosition - HALF_BLOCK_SIZE;

    // Left part
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition); // Top

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition); // Middle top

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 2), xPosition); // Middle bottom

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 3), xPosition); // Bottom

    xPosition += BLOCK_SIZE;

    // Right part
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition); // Top

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition); // Middle top

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 2), xPosition); // Middle bottom

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 3), xPosition); // Bottom
}

/**
 * @brief 4e9c0 | 348 | Escape gate AI
 * 
 */
void EscapeGate(void)
{
    u8 spriteId;
    u8 delay;
    u32 timer;
    u8 flag;
    u8 row;
    u32 offset;

    spriteId = gCurrentSprite.spriteId;
    delay = CONVERT_SECONDS(.25f) + 1 * DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.xPosition += HALF_BLOCK_SIZE;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pOam = sEscapeGateOAM_Closed,
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;

            gCurrentSprite.pose = ESCAPE_GATE_POSE_LOAD_GRAPHICS;
            gCurrentSprite.work1 = 0;
            gCurrentSprite.work2 = 1;
            gCurrentSprite.drawOrder = 3;

            gSubSpriteData1.workVariable3 = 0;
            EscapeGateChangeCcaa(CAA_MAKE_SOLID_GRIPPABLE); // Set gate collision
            break;

        case ESCAPE_GATE_POSE_LOAD_GRAPHICS:
            if (spriteId == PSPRITE_ESCAPE_GATE1)
            {
                // Load graphics and spawn the black pirates
                DMA_SET(3, sEscapeGateAndTimerGfx, VRAM_BASE + 0x17800, C_32_2_16(DMA_ENABLE, 0x400));
                DMA_SET(3, sEscapeGateAndTimerPal, PALRAM_OBJ + (PAL_SIZE - 1 * PAL_ROW_SIZE), C_32_2_16(DMA_ENABLE, 0x10));

                SpriteSpawnPrimary(PSPRITE_BLACK_SPACE_PIRATE, 0x80, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition - (BLOCK_SIZE * 2), 0);

                SpriteSpawnPrimary(PSPRITE_BLACK_SPACE_PIRATE, 0x80, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition - (BLOCK_SIZE * 10), SPRITE_STATUS_X_FLIP);
            }
            gCurrentSprite.pose = ESCAPE_GATE_POSE_IDLE;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            break;

        case ESCAPE_GATE_POSE_IDLE:
            if (spriteId == PSPRITE_ESCAPE_GATE1)
            {
                // Check if black pirates are dead
                if (SpriteUtilCountPrimarySprites(PSPRITE_BLACK_SPACE_PIRATE) == 0)
                    gCurrentSprite.pose = ESCAPE_GATE_POSE_CHECK_OPEN;
            }
            else
            {
                if (gSubSpriteData1.workVariable3 == 2)
                    gCurrentSprite.pose = ESCAPE_GATE_POSE_CHECK_OPEN;
            }
            break;

        case ESCAPE_GATE_POSE_CHECK_OPEN:
            if (spriteId != PSPRITE_ESCAPE_GATE1 || SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE, BLOCK_SIZE * 6) == NSLR_LEFT)
            {
                // Open gate if samus near
                gCurrentSprite.pOam = sEscapeGateOAM_Opening;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;

                gCurrentSprite.pose = ESCAPE_GATE_POSE_OPENING;
                SoundPlay(SOUND_ESCAPE_GATE_OPENING);
            }
            break;

        case ESCAPE_GATE_POSE_OPENING:
            delay = 3 * DELTA_TIME;

            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sEscapeGateOAM_Opened;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;

                gCurrentSprite.pose = ESCAPE_GATE_POSE_OPENED;
            }
            else
            {
                if (gCurrentSprite.currentAnimationFrame == 4 && gCurrentSprite.animationDurationCounter == CONVERT_SECONDS(1.f / 6))
                    EscapeGateChangeCcaa(CAA_REMOVE_SOLID);
            }
            break;

        case ESCAPE_GATE_POSE_OPENED:
            if (spriteId != PSPRITE_ESCAPE_GATE1)
                return;

            if (gSubSpriteData1.workVariable3 == 1)
            {
                // Spawn pirate that chases the escape ship
                SpriteSpawnPrimary(PSPRITE_SPACE_PIRATE_WAITING1, 0x81, 0, gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), 0);

                gCurrentSprite.pose = ESCAPE_GATE_POSE_ESCAPING;
            }
            break;

        case ESCAPE_GATE_POSE_ESCAPING:
            if (spriteId != PSPRITE_ESCAPE_GATE1)
                return;

            if (gSubSpriteData1.workVariable3 == 2)
                delay = 3 * DELTA_TIME;
            break;
    }

    // Update animated palette
    if (spriteId == PSPRITE_ESCAPE_GATE1)
    {
        timer = APPLY_DELTA_TIME_DEC(gCurrentSprite.work2);
        if (timer == 0)
        {
            gCurrentSprite.work2 = delay;
            row = gCurrentSprite.work1;
            flag = 0x80;
            if (row & flag)
            {
                if (gCurrentSprite.work1 > flag)
                    gCurrentSprite.work1--;

                if (gCurrentSprite.work1 == flag)
                    gCurrentSprite.work1 = timer;
            }
            else
            {
                if (gCurrentSprite.work1 < 5)
                    gCurrentSprite.work1++;

                if (gCurrentSprite.work1 == 2)
                    gCurrentSprite.work1 |= flag;
            }

            offset = MOD_AND(gCurrentSprite.work1, 128);
            DMA_SET(3, &sEscapeGateFlashingPal[offset * 16], PALRAM_OBJ + (PAL_SIZE - 1 * PAL_ROW_SIZE), C_32_2_16(DMA_ENABLE, 16));
        }
    }
}
