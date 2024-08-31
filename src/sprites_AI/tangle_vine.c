#include "sprites_AI/tangle_vine.h"
#include "macros.h"

#include "data/frame_data_pointers.h"
#include "data/sprites/tangle_vine.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
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
    MultiSpriteDataInfo_T pData;
    u16 oamIdx;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];
    
    if (gCurrentSprite.pOam != sTangleVineFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sTangleVineFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition - pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
    else
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
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
            SoundPlayNotAlreadyPlaying(SOUND_TANGLE_VINE_DAMAGE);
    }

    counter = 0;
    if (gCurrentSprite.pose == 0)
    {
        gCurrentSprite.drawDistanceTop = 0x40;
        gCurrentSprite.drawDistanceBottom = 0;
        gCurrentSprite.drawDistanceHorizontal = 0x18;

        gCurrentSprite.hitboxTop = -0xE0;
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = -0x1C;
        gCurrentSprite.hitboxRight = 0x1C;

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;
        gCurrentSprite.pose = 0x9;

        gCurrentSprite.pOam = sTangleVineGerutaOam_Root;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gSubSpriteData1.pMultiOam = sTangleVineGerutaMultiSpriteData_Idle;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        gSubSpriteData1.health = TANGLE_VINE_GERUTA_STATUS_VINE_DEAD;
        gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

        gCurrentSprite.frozenPaletteRowOffset = 0x1;
        gCurrentSprite.drawOrder = 0x5;
        gCurrentSprite.roomSlot = TANGLE_VINE_GERUTA_PART_ROOT;

        yPosition = gSubSpriteData1.yPosition;
        xPosition = gSubSpriteData1.xPosition;
        gfxSlot = gCurrentSprite.spritesetGfxSlot;
        ramSlot = gCurrentSprite.primarySpriteRamSlot;

        newRamSlot = SpriteSpawnSecondary(SSPRITE_TANGLE_VINE_GERUTA_PART, TANGLE_VINE_GERUTA_PART_GRIP, gfxSlot,
            ramSlot, yPosition, xPosition, 0);

        if (newRamSlot >= MAX_AMOUNT_OF_SPRITES)
            counter = TRUE;

        newRamSlot = SpriteSpawnSecondary(SSPRITE_TANGLE_VINE_GERUTA_PART, TANGLE_VINE_GERUTA_PART_GERUTA, gfxSlot,
            ramSlot, yPosition, xPosition, 0);

        if (newRamSlot >= MAX_AMOUNT_OF_SPRITES)
            counter++;

        if (counter != 0)
            gCurrentSprite.status = 0;
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
            gCurrentSprite.pOam = sTangleVineGerutaOam_Full;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = 0x23;
        }
    }

    SpriteUtilUpdateSubSprite1Anim();
    SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOam();
}

/**
 * @brief 415ec | 130 | Tangle vine (geruta) part AI
 * 
 */
void TangleVineGerutaPart(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.pose == 0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.pose = 0xF;

        if (gCurrentSprite.roomSlot == TANGLE_VINE_GERUTA_PART_GRIP)
        {
            gCurrentSprite.drawDistanceTop = 0x40;
            gCurrentSprite.drawDistanceBottom = 0;
            gCurrentSprite.drawDistanceHorizontal = 0x10;

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.health = 0;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x3;
        }
        else if (gCurrentSprite.roomSlot == TANGLE_VINE_GERUTA_PART_GERUTA)
        {
            gCurrentSprite.drawDistanceTop = 0x10;
            gCurrentSprite.drawDistanceBottom = 0x10;
            gCurrentSprite.drawDistanceHorizontal = 0x18;

            gCurrentSprite.hitboxTop = -0x20;
            gCurrentSprite.hitboxBottom = 0x20;
            gCurrentSprite.hitboxLeft = -0x40;
            gCurrentSprite.hitboxRight = 0x40;

            gCurrentSprite.health = 0x1;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        }
        else
            gCurrentSprite.status = 0;
    }

    if (gCurrentSprite.roomSlot == TANGLE_VINE_GERUTA_PART_GRIP)
    {
        if (gSubSpriteData1.health != TANGLE_VINE_GERUTA_STATUS_FULL)
        {
            gCurrentSprite.status = 0;
            return;
        }
        else
            gCurrentSprite.paletteRow = gSpriteData[ramSlot].paletteRow;
    }
    else if (gCurrentSprite.roomSlot == TANGLE_VINE_GERUTA_PART_GERUTA)
    {
        if (gCurrentSprite.health == 0)
        {
            gSubSpriteData1.health = TANGLE_VINE_GERUTA_STATUS_GERUTA_DEAD;
            ParticleSet(gCurrentSprite.yPosition + 0x8, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
            SoundPlay(SOUND_SPRITE_EXPLOSION_MEDIUM);
            gCurrentSprite.status = 0;
            return;
        }
        
        if (gSubSpriteData1.health == TANGLE_VINE_GERUTA_STATUS_VINE_DEAD)
        {
            SpriteSpawnPrimary(PSPRITE_GERUTA_RED, 0x80, 0x5, gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition, 0);
            gCurrentSprite.status = 0;
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
            SoundPlayNotAlreadyPlaying(SOUND_TANGLE_VINE_DAMAGE);
    }

    if (gCurrentSprite.pose == 0)
    {
        gCurrentSprite.drawDistanceTop = 0x48;
        gCurrentSprite.drawDistanceBottom = 0;
        gCurrentSprite.drawDistanceHorizontal = 0x18;

        gCurrentSprite.hitboxTop = -0x110;
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = -0x24;
        gCurrentSprite.hitboxRight = 0x24;

        gCurrentSprite.pOam = sTangleVineRedGerutaOam;
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

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
            SoundPlayNotAlreadyPlaying(SOUND_TANGLE_VINE_DAMAGE);
    }

    if (gCurrentSprite.pose == 0)
    {
        gCurrentSprite.yPosition -= QUARTER_BLOCK_SIZE;

        gCurrentSprite.drawDistanceTop = 0x38;
        gCurrentSprite.drawDistanceBottom = 0x8;
        gCurrentSprite.drawDistanceHorizontal = 0x10;

        gCurrentSprite.hitboxTop = -0xC0;
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = 0;
        gCurrentSprite.hitboxRight = 0x24;

        gCurrentSprite.pOam = sTangleVineLarvaRightOam;
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

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
            SoundPlayNotAlreadyPlaying(SOUND_TANGLE_VINE_DAMAGE);
    }

    if (gCurrentSprite.pose == 0)
    {
        gCurrentSprite.xPosition -= QUARTER_BLOCK_SIZE;

        gCurrentSprite.drawDistanceTop = 0x38;
        gCurrentSprite.drawDistanceBottom = 0x8;
        gCurrentSprite.drawDistanceHorizontal = 0x10;

        gCurrentSprite.hitboxTop = -0xC0;
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = -0x24;
        gCurrentSprite.hitboxRight = 0;

        gCurrentSprite.pOam = sTangleVineLarvaLeftOam;
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

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
            SoundPlayNotAlreadyPlaying(SOUND_TANGLE_VINE_DAMAGE);
    }

    if (gCurrentSprite.pose == 0)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.drawDistanceTop = 0x40;
            gCurrentSprite.drawDistanceBottom = 0;
            gCurrentSprite.drawDistanceHorizontal = 0x10;

            gCurrentSprite.hitboxTop = -0xF8;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = -0x18;
            gCurrentSprite.hitboxRight = 0x18;

            gCurrentSprite.pOam = sTangleVineTallOam_OnGround;
        }
        else
        {
            gCurrentSprite.drawDistanceTop = 0;
            gCurrentSprite.drawDistanceBottom = 0x40;
            gCurrentSprite.drawDistanceHorizontal = 0x10;

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0xF8;
            gCurrentSprite.hitboxLeft = -0x18;
            gCurrentSprite.hitboxRight = 0x18;

            gCurrentSprite.pOam = sTangleVineTallOam_OnCeiling;

            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;

        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x1;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
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
            SoundPlayNotAlreadyPlaying(SOUND_TANGLE_VINE_DAMAGE);
    }

    if (gCurrentSprite.pose == 0)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.drawDistanceTop = 0x30;
            gCurrentSprite.drawDistanceBottom = 0;
            gCurrentSprite.drawDistanceHorizontal = 0x10;

            gCurrentSprite.hitboxTop = -0xB8;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = -0x18;
            gCurrentSprite.hitboxRight = 0x18;

            gCurrentSprite.pOam = sTangleVineMediumOam_OnGround;
        }
        else
        {
            gCurrentSprite.drawDistanceTop = 0;
            gCurrentSprite.drawDistanceBottom = 0x30;
            gCurrentSprite.drawDistanceHorizontal = 0x10;

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0xB8;
            gCurrentSprite.hitboxLeft = -0x18;
            gCurrentSprite.hitboxRight = 0x18;

            gCurrentSprite.pOam = sTangleVineMediumOam_OnCeiling;

            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;

        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x1;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
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
            SoundPlayNotAlreadyPlaying(SOUND_TANGLE_VINE_DAMAGE);
    }

    if (gCurrentSprite.pose == 0)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.drawDistanceTop = 0x28;
            gCurrentSprite.drawDistanceBottom = 0;
            gCurrentSprite.drawDistanceHorizontal = 0x8;

            gCurrentSprite.hitboxTop = -0x80;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = -0x10;
            gCurrentSprite.hitboxRight = 0x10;

            gCurrentSprite.pOam = sTangleVineCurvedOam_OnGround;
        }
        else
        {
            gCurrentSprite.drawDistanceTop = 0;
            gCurrentSprite.drawDistanceBottom = 0x28;
            gCurrentSprite.drawDistanceHorizontal = 0x8;

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0x80;
            gCurrentSprite.hitboxLeft = -0x10;
            gCurrentSprite.hitboxRight = 0x10;

            gCurrentSprite.pOam = sTangleVineCurvedOam_OnCeiling;

            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;

        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x1;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
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
            SoundPlayNotAlreadyPlaying(SOUND_TANGLE_VINE_DAMAGE);
    }

    if (gCurrentSprite.pose == 0)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.drawDistanceTop = 0x28;
            gCurrentSprite.drawDistanceBottom = 0;
            gCurrentSprite.drawDistanceHorizontal = 0x8;

            gCurrentSprite.hitboxTop = -0x88;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = -0x10;
            gCurrentSprite.hitboxRight = 0x10;

            gCurrentSprite.pOam = sTangleVineShortOam_OnGround;
        }
        else
        {
            gCurrentSprite.drawDistanceTop = 0;
            gCurrentSprite.drawDistanceBottom = 0x28;
            gCurrentSprite.drawDistanceHorizontal = 0x8;

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0x88;
            gCurrentSprite.hitboxLeft = -0x10;
            gCurrentSprite.hitboxRight = 0x10;

            gCurrentSprite.pOam = sTangleVineShortOam_OnCeiling;

            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;

        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x1;
    }
    else if (gCurrentSprite.pose > 0x61)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
            yPosition = gCurrentSprite.yPosition + BLOCK_SIZE;
        else
            yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;

        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}