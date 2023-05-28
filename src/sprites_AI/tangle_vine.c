#include "sprites_AI/tangle_vine.h"
#include "macros.h"

#include "data/frame_data_pointers.h"
#include "data/sprites/tangle_vine.h"
#include "data/sprite_data.h"

#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"

/**
 * @brief 413c4 | 88 | Synchronize the sub sprites of a tangle vine
 * 
 */
void TangleVineSyncSprites(void)
{
    u16 (*pData)[3];
    u32 offset;

    pData = (u16(*)[3])gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pFrame;
    offset = pData[gCurrentSprite.roomSlot][0];
    
    if (gCurrentSprite.pOam != sTangleVineFrameDataPointers[offset])
    {
        gCurrentSprite.pOam = sTangleVineFrameDataPointers[offset];
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][1];

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition - pData[gCurrentSprite.roomSlot][2];
    else
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][2];
}

/**
 * @brief 4144c | 1a0 | Tangle vine (geruta) AI
 * 
 */
void TangleVineGeruta(void)
{
    u8 gfxSlot;
    u32 ramSlot;
    u16 yPosition;
    u16 xPosition;
    u8 newRamSlot;
    u8 counter;

    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x264);
    }

    counter = 0x0;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.drawDistanceTopOffset = 0x40;
        gCurrentSprite.drawDistanceBottomOffset = 0x0;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

        gCurrentSprite.hitboxTopOffset = -0xE0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = -0x1C;
        gCurrentSprite.hitboxRightOffset = 0x1C;

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;
        gCurrentSprite.pose = 0x9;

        gCurrentSprite.pOam = sTangleVineGerutaOAM_Root;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gSubSpriteData1.pMultiOam = sTangleVineGerutaMultiSpriteData_Idle;
        gSubSpriteData1.animationDurationCounter = 0x0;
        gSubSpriteData1.currentAnimationFrame = 0x0;

        gSubSpriteData1.health = TANGLE_VINE_GERUTA_STATUS_VINE_DEAD;
        gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

        gCurrentSprite.frozenPaletteRowOffset = 0x1;
        gCurrentSprite.drawOrder = 0x5;
        gCurrentSprite.roomSlot = TANGLE_VINE_GERUTA_PART_ROOT;

        yPosition = gSubSpriteData1.yPosition;
        xPosition = gSubSpriteData1.xPosition;
        gfxSlot = gCurrentSprite.spritesetGFXSlot;
        ramSlot = gCurrentSprite.primarySpriteRAMSlot;

        newRamSlot = SpriteSpawnSecondary(SSPRITE_TANGLE_VINE_GERUTA_PART, TANGLE_VINE_GERUTA_PART_GRIP, gfxSlot,
            ramSlot, yPosition, xPosition, 0x0);

        if (newRamSlot >= MAX_AMOUNT_OF_SPRITES)
            counter = TRUE;

        newRamSlot = SpriteSpawnSecondary(SSPRITE_TANGLE_VINE_GERUTA_PART, TANGLE_VINE_GERUTA_PART_GERUTA, gfxSlot,
            ramSlot, yPosition, xPosition, 0x0);

        if (newRamSlot >= MAX_AMOUNT_OF_SPRITES)
            counter++;

        if (counter != 0x0)
            gCurrentSprite.status = 0x0;
        else
            gSubSpriteData1.health = TANGLE_VINE_GERUTA_STATUS_FULL;
    }
    else 
    {
        if (gCurrentSprite.pose > 0x61)
        {
            gSubSpriteData1.health = TANGLE_VINE_GERUTA_STATUS_VINE_DEAD;
            ParticleSet(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - 0x92, gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE, TRUE, PE_SPRITE_EXPLOSION_BIG);
            return;
        }

        if (gCurrentSprite.pose == 0x9 && gSubSpriteData1.health == TANGLE_VINE_GERUTA_STATUS_GERUTA_DEAD)
        {
            gCurrentSprite.pOam = sTangleVineGerutaOAM_Full;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = 0x23;
        }
    }

    SpriteUtilUpdateSubSprite1Anim();
    SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOAM();
}

/**
 * @brief 415ec | 130 | Tangle vine (geruta) part AI
 * 
 */
void TangleVineGerutaPart(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.pose = 0xF;

        if (gCurrentSprite.roomSlot == TANGLE_VINE_GERUTA_PART_GRIP)
        {
            gCurrentSprite.drawDistanceTopOffset = 0x40;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.health = 0x0;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x3;
        }
        else if (gCurrentSprite.roomSlot == TANGLE_VINE_GERUTA_PART_GERUTA)
        {
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            gCurrentSprite.hitboxTopOffset = -0x20;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = -0x40;
            gCurrentSprite.hitboxRightOffset = 0x40;

            gCurrentSprite.health = 0x1;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        }
        else
            gCurrentSprite.status = 0x0;
    }

    if (gCurrentSprite.roomSlot == TANGLE_VINE_GERUTA_PART_GRIP)
    {
        if (gSubSpriteData1.health != TANGLE_VINE_GERUTA_STATUS_FULL)
        {
            gCurrentSprite.status = 0x0;
            return;
        }
        else
            gCurrentSprite.paletteRow = gSpriteData[ramSlot].paletteRow;
    }
    else if (gCurrentSprite.roomSlot == TANGLE_VINE_GERUTA_PART_GERUTA)
    {
        if (gCurrentSprite.health == 0x0)
        {
            gSubSpriteData1.health = TANGLE_VINE_GERUTA_STATUS_GERUTA_DEAD;
            ParticleSet(gCurrentSprite.yPosition + 0x8, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
            SoundPlay(0x12D);
            gCurrentSprite.status = 0x0;
            return;
        }
        
        if (gSubSpriteData1.health == TANGLE_VINE_GERUTA_STATUS_VINE_DEAD)
        {
            SpriteSpawnPrimary(PSPRITE_GERUTA_RED, 0x80, 0x5, gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition, 0x0);
            gCurrentSprite.status = 0x0;
            return;
        }
    }

    TangleVineSyncSprites();
}

/**
 * @brief 417ac | cc | Tangle vine (red geruta) AI
 * 
 */
void TangleVineRedGeruta(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x264);
    }

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.drawDistanceTopOffset = 0x48;
        gCurrentSprite.drawDistanceBottomOffset = 0x0;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

        gCurrentSprite.hitboxTopOffset = -0x110;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = -0x24;
        gCurrentSprite.hitboxRightOffset = 0x24;

        gCurrentSprite.pOam = sTangleVineRedGerutaOAM;
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x2;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        ParticleSet(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE,
            PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - 0x92,
            gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}

/**
 * @brief 417e8 | d0 | Tangle vine (imago right) AI
 * 
 */
void TangleVineLarvaRight(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x264);
    }

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.yPosition -= QUARTER_BLOCK_SIZE;

        gCurrentSprite.drawDistanceTopOffset = 0x38;
        gCurrentSprite.drawDistanceBottomOffset = 0x8;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

        gCurrentSprite.hitboxTopOffset = -0xC0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = 0x0;
        gCurrentSprite.hitboxRightOffset = 0x24;

        gCurrentSprite.pOam = sTangleVineLarvaRightOAM;
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x2;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        ParticleSet(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE, PE_SPRITE_EXPLOSION_BIG);
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - 0x78,
            gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}

/**
 * @brief 418b8 | d4 | Tangle vine (imago left) AI
 * 
 */
void TangleVineLarvaLeft(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x264);
    }

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.xPosition -= QUARTER_BLOCK_SIZE;

        gCurrentSprite.drawDistanceTopOffset = 0x38;
        gCurrentSprite.drawDistanceBottomOffset = 0x8;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

        gCurrentSprite.hitboxTopOffset = -0xC0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = -0x24;
        gCurrentSprite.hitboxRightOffset = 0x0;

        gCurrentSprite.pOam = sTangleVineLarvaLeftOAM;
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x2;
        gCurrentSprite.drawOrder = 0x5;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        ParticleSet(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE, PE_SPRITE_EXPLOSION_BIG);
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - 0x78,
            gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}

/**
 * @brief 4198c | 130 | Tangle vine (tall) AI
 * 
 */
void TangleVineTall(void)
{
    u16 yPosition;

    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x264);
    }

    if (gCurrentSprite.pose == 0x0)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.drawDistanceTopOffset = 0x40;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0xF8;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = -0x18;
            gCurrentSprite.hitboxRightOffset = 0x18;

            gCurrentSprite.pOam = sTangleVineTallOAM_OnGround;
        }
        else
        {
            gCurrentSprite.drawDistanceTopOffset = 0x0;
            gCurrentSprite.drawDistanceBottomOffset = 0x40;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0xF8;
            gCurrentSprite.hitboxLeftOffset = -0x18;
            gCurrentSprite.hitboxRightOffset = 0x18;

            gCurrentSprite.pOam = sTangleVineTallOAM_OnCeiling;

            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;

        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x1;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
            yPosition = gCurrentSprite.yPosition + 0x64;
        else
            yPosition = gCurrentSprite.yPosition - BLOCK_SIZE;

        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}

/**
 * @brief 41abc | 130 | Tangle vine (medium) AI
 * 
 */
void TangleVineMedium(void)
{
    u16 yPosition;

    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x264);
    }

    if (gCurrentSprite.pose == 0x0)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0xB8;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = -0x18;
            gCurrentSprite.hitboxRightOffset = 0x18;

            gCurrentSprite.pOam = sTangleVineMediumOAM_OnGround;
        }
        else
        {
            gCurrentSprite.drawDistanceTopOffset = 0x0;
            gCurrentSprite.drawDistanceBottomOffset = 0x30;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0xB8;
            gCurrentSprite.hitboxLeftOffset = -0x18;
            gCurrentSprite.hitboxRightOffset = 0x18;

            gCurrentSprite.pOam = sTangleVineMediumOAM_OnCeiling;

            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;

        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x1;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
            yPosition = gCurrentSprite.yPosition + 0x70;
        else
            yPosition = gCurrentSprite.yPosition - 0x30;

        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
    }
}

/**
 * @brief 41bec | 130 | Tangle vine (curved) AI
 * 
 */
void TangleVineCurved(void)
{
    u16 yPosition;

    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x264);
    }

    if (gCurrentSprite.pose == 0x0)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.drawDistanceTopOffset = 0x28;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = -0x80;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.pOam = sTangleVineCurvedOAM_OnGround;
        }
        else
        {
            gCurrentSprite.drawDistanceTopOffset = 0x0;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x80;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.pOam = sTangleVineCurvedOAM_OnCeiling;

            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;

        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x1;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
            yPosition = gCurrentSprite.yPosition + 0x48;
        else
            yPosition = gCurrentSprite.yPosition - 0x28;

        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
    }
}

/**
 * @brief 41d1c | 130 | Tangle vine (short) AI
 * 
 */
void TangleVineShort(void)
{
    u16 yPosition;

    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x264);
    }

    if (gCurrentSprite.pose == 0x0)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.drawDistanceTopOffset = 0x28;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = -0x88;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.pOam = sTangleVineShortOAM_OnGround;
        }
        else
        {
            gCurrentSprite.drawDistanceTopOffset = 0x0;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x88;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x10;

            gCurrentSprite.pOam = sTangleVineShortOAM_OnCeiling;

            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;

        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x1;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
            yPosition = gCurrentSprite.yPosition + BLOCK_SIZE;
        else
            yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;

        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}