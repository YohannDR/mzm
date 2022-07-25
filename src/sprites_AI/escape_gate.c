#include "escape_gate.h"
#include "../../data/data.h"
#include "../globals.h"

const u8 sEscapeGateAndTimerGFX[2048];
const u16 sEscapeGateAndTimerPAL[16];
const u16 sEscapeGateFlashingPAL[96];

const u16 sEscapeGateOAM_Closed_Frame0[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7,
    OBJ_SHAPE_HORIZONTAL | 0xda, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73db
};

const u16 sEscapeGateOAM_Opening_Frame1[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7,
    OBJ_SHAPE_HORIZONTAL | 0xda, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73fb
};

const u16 sEscapeGateOAM_Opening_Frame2[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame4[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xbe, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xce, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame3[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xbd, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xcd, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame5[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xcc, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame6[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xba, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cb,
    OBJ_SHAPE_HORIZONTAL | 0xca, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame7[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73eb,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame8[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xea, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7,
    OBJ_SHAPE_HORIZONTAL | 0xbe, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73eb
};

const u16 sEscapeGateOAM_Opening_Frame9[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc4, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73eb,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame10[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xba, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73eb,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame11[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xc0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3,
    OBJ_SHAPE_HORIZONTAL | 0xb8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73eb,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d7
};

const u16 sEscapeGateOAM_Opening_Frame12[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xbe, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3
};

const u16 sEscapeGateOAM_Opening_Frame13[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xbc, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3
};

const u16 sEscapeGateOAM_Opening_Frame14[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xba, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3
};

const u16 sEscapeGateOAM_Opening_Frame15[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xb8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73cf,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3
};

const u16 sEscapeGateOAM_Opening_Frame16[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xbe, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73ef,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x73d3
};

const struct FrameData sEscapeGateOAM_Closed[2] = {
    sEscapeGateOAM_Closed_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sEscapeGateOAM_Opening[18] = {
    sEscapeGateOAM_Closed_Frame0,
    0x32,
    sEscapeGateOAM_Opening_Frame1,
    0xC,
    sEscapeGateOAM_Opening_Frame2,
    0x32,
    sEscapeGateOAM_Opening_Frame3,
    0x4,
    sEscapeGateOAM_Opening_Frame4,
    0xA,
    sEscapeGateOAM_Opening_Frame5,
    0x1,
    sEscapeGateOAM_Opening_Frame6,
    0x1,
    sEscapeGateOAM_Opening_Frame7,
    0x1,
    sEscapeGateOAM_Opening_Frame8,
    0x1,
    sEscapeGateOAM_Opening_Frame9,
    0x1,
    sEscapeGateOAM_Opening_Frame10,
    0x1,
    sEscapeGateOAM_Opening_Frame11,
    0x1,
    sEscapeGateOAM_Opening_Frame12,
    0x1,
    sEscapeGateOAM_Opening_Frame13,
    0x1,
    sEscapeGateOAM_Opening_Frame14,
    0x1,
    sEscapeGateOAM_Opening_Frame15,
    0x1,
    sEscapeGateOAM_Opening_Frame16,
    0x1,
    NULL,
    0x0
};

const struct FrameData sEscapeGateOAM_Opened[2] = {
    sEscapeGateOAM_Opening_Frame16,
    0xFF,
    NULL,
    0x0
};


/**
 * @brief 4e910 | b0 | Updates the hitbox of the escape gate
 * 
 * @param caa Clipdata Affecting Action
 */
void EscapeGateChangeCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - (BLOCK_SIZE / 2);
    xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE / 2);

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

            gSubSpriteData1.workVariable1 = 0x0;
            EscapeGateChangeCCAA(CCAA_MAKE_SOLID1); // Set gate collision
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
            else if (gSubSpriteData1.workVariable1 == 0x2)
                gCurrentSprite.pose = ESCAPE_GATE_POSE_CHECK_OPEN;
            break;

        case ESCAPE_GATE_POSE_CHECK_OPEN:
            if (spriteID != PSPRITE_ESCAPE_GATE1 || SpriteUtilCheckSamusNearSpriteLeftRight(0x40, 0x180) == NSLR_LEFT)
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
                EscapeGateChangeCCAA(CCAA_REMOVE_SOLID);
            break;

        case ESCAPE_GATE_POSE_OPENED:
            if (spriteID != PSPRITE_ESCAPE_GATE1)
                return;

            if (gSubSpriteData1.workVariable1 == 0x1)
            {
                // Spawn pirate that chases the escape ship
                SpriteSpawnPrimary(PSPRITE_SPACE_PIRATE_WAITING1, 0x81, 0x0, gCurrentSprite.yPosition, gCurrentSprite.xPosition - 0xA0, 0x0);
                gCurrentSprite.pose = ESCAPE_GATE_POSE_ESCAPING;
            }
            break;

        case ESCAPE_GATE_POSE_ESCAPING:
            if (spriteID != PSPRITE_ESCAPE_GATE1)
                return;

            if (gSubSpriteData1.workVariable1 == 0x2)
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
            dma_set(3, sEscapeGateFlashingPAL[offset], PALRAM_BASE + 0x3E0, (DMA_ENABLE << 0x10) | 0x10);
        }
    }
}