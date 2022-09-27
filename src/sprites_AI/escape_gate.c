#include "gba.h"
#include "sprites_AI/escape_gate.h"

#include "data/sprites/escape_gate.h"

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
void EscapeGateChangeCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - (HALF_BLOCK_SIZE);
    xPosition = gCurrentSprite.xPosition - (HALF_BLOCK_SIZE);

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
    u8 spriteID;
    u8 delay;
    u32 timer;
    u8 flag;
    u8 row;
    u32 offset;

    spriteID = gCurrentSprite.spriteID;
    delay = 0x10;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.xPosition += 0x20;

            gCurrentSprite.drawDistanceTopOffset = 0x48;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pOam = sEscapeGateOAM_Closed,
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;

            gCurrentSprite.pose = ESCAPE_GATE_POSE_LOAD_GRAPHICS;
            gCurrentSprite.workVariable = 0x0;
            gCurrentSprite.workVariable2 = 0x1;
            gCurrentSprite.drawOrder = 0x3;

            gSubSpriteData1.workVariable3 = 0x0;
            EscapeGateChangeCCAA(CAA_MAKE_SOLID_GRIPPABLE); // Set gate collision
            break;

        case ESCAPE_GATE_POSE_LOAD_GRAPHICS:
            if (spriteID == PSPRITE_ESCAPE_GATE1)
            {
                // Load graphics and spawn the black pirates
                dma_set(3, sEscapeGateAndTimerGFX, VRAM_BASE + 0x17800, (DMA_ENABLE << 0x10) | 0x400);
                dma_set(3, sEscapeGateAndTimerPAL, PALRAM_BASE + 0x3E0, (DMA_ENABLE << 0x10) | 0x10);
                SpriteSpawnPrimary(PSPRITE_BLACK_SPACE_PIRATE, 0x80, gCurrentSprite.spritesetGFXSlot,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition - 0x80, 0x0);
                SpriteSpawnPrimary(PSPRITE_BLACK_SPACE_PIRATE, 0x80, gCurrentSprite.spritesetGFXSlot,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition - 0x280, SPRITE_STATUS_XFLIP);
            }
            gCurrentSprite.pose = ESCAPE_GATE_POSE_IDLE;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            break;

        case ESCAPE_GATE_POSE_IDLE:
            if (spriteID == PSPRITE_ESCAPE_GATE1)
            {
                // Check if black pirates are dead
                if (SpriteUtilCountPrimarySprites(PSPRITE_BLACK_SPACE_PIRATE) == 0x0)
                    gCurrentSprite.pose = ESCAPE_GATE_POSE_CHECK_OPEN;
            }
            else if (gSubSpriteData1.workVariable3 == 0x2)
                gCurrentSprite.pose = ESCAPE_GATE_POSE_CHECK_OPEN;
            break;

        case ESCAPE_GATE_POSE_CHECK_OPEN:
            if (spriteID != PSPRITE_ESCAPE_GATE1 || SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE, BLOCK_SIZE * 6) == NSLR_LEFT)
            {
                // Open gate if samus near
                gCurrentSprite.pOam = sEscapeGateOAM_Opening;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.pose = ESCAPE_GATE_POSE_OPENING;
                SoundPlay(0x24D);
            }
            break;

        case ESCAPE_GATE_POSE_OPENING:
            delay = 0x3;

            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sEscapeGateOAM_Opened;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.pose = ESCAPE_GATE_POSE_OPENED;
            }
            else if (gCurrentSprite.currentAnimationFrame == 0x4 && gCurrentSprite.animationDurationCounter == 0xA)
                EscapeGateChangeCCAA(CAA_REMOVE_SOLID);
            break;

        case ESCAPE_GATE_POSE_OPENED:
            if (spriteID != PSPRITE_ESCAPE_GATE1)
                return;

            if (gSubSpriteData1.workVariable3 == 0x1)
            {
                // Spawn pirate that chases the escape ship
                SpriteSpawnPrimary(PSPRITE_SPACE_PIRATE_WAITING1, 0x81, 0x0, gCurrentSprite.yPosition, gCurrentSprite.xPosition - 0xA0, 0x0);
                gCurrentSprite.pose = ESCAPE_GATE_POSE_ESCAPING;
            }
            break;

        case ESCAPE_GATE_POSE_ESCAPING:
            if (spriteID != PSPRITE_ESCAPE_GATE1)
                return;

            if (gSubSpriteData1.workVariable3 == 0x2)
                delay = 0x3;
            break;
    }

    // Update animated palette
    if (spriteID == PSPRITE_ESCAPE_GATE1)
    {
        timer = --gCurrentSprite.workVariable2;
        if (timer == 0x0)
        {
            gCurrentSprite.workVariable2 = delay;
            row = gCurrentSprite.workVariable;
            flag = 0x80;
            if (row & flag)
            {
                if (gCurrentSprite.workVariable > 0x80)
                    gCurrentSprite.workVariable--;

                if (gCurrentSprite.workVariable == 0x80)
                    gCurrentSprite.workVariable = timer;
            }
            else
            {
                if (gCurrentSprite.workVariable < 0x5)
                    gCurrentSprite.workVariable++;

                if (gCurrentSprite.workVariable == 0x2)
                    gCurrentSprite.workVariable |= flag;
            }

            offset = gCurrentSprite.workVariable & 0x7F;
            dma_set(3, (sEscapeGateFlashingPAL + offset * 16), PALRAM_BASE + 0x3E0, (DMA_ENABLE << 0x10) | 0x10);
        }
    }
}