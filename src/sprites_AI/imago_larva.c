#include "sprites_AI/imago_larva.h"
#include "data/pointers.h"
#include "data/sprites/imago_larva.h"
#include "data/sprite_data.h"
#include "constants/audio.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/event.h"
#include "structs/connection.h"
#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 259a0 | 84 | Synchronize the sub sprites of an Imago larva
 * 
 * @param pSub 
 */
void ImagoLarvaSyncSubSprites(struct SubSpriteData* pSub)
{
    u16 (*pData)[3];
    u32 offset;

    pData = (u16(*)[3])pSub->pMultiOam[pSub->currentAnimationFrame].pFrame;
    offset = pData[gCurrentSprite.roomSlot][0];
    
    if (gCurrentSprite.pOam != sImagoLarvaFrameDataPointers[offset])
    {
        gCurrentSprite.pOam = sImagoLarvaFrameDataPointers[offset];
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    gCurrentSprite.yPosition = pSub->yPosition + pData[gCurrentSprite.roomSlot][1];

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.xPosition = pSub->xPosition - pData[gCurrentSprite.roomSlot][2];
    else
        gCurrentSprite.xPosition = pSub->xPosition + pData[gCurrentSprite.roomSlot][2];
}

/**
 * @brief 25a24 | 5c | Updates the palette of an Imago larva
 * 
 */
void ImagoLarvaUpdatePalette(void)
{
    u8 timer;
    u8 timerLimit;
    
    if (!(gCurrentSprite.invincibilityStunFlashTimer & 0x7F))
    {
        gCurrentSprite.workVariable2++;
        timer = gCurrentSprite.workVariable2;
        timerLimit = 0xA;
        if (timer >= timerLimit)
        {
            gCurrentSprite.workVariable2 = 0x0;
            gCurrentSprite.arrayOffset++;
            if (gCurrentSprite.arrayOffset > 0x3)
                gCurrentSprite.arrayOffset = 0x0;
        }

        gCurrentSprite.absolutePaletteRow = sImagoLarvaPaletteRows[gCurrentSprite.arrayOffset];
        gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }
}

/**
 * @brief 25a80 | 194 | Initializes an Imago larva sprite
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaInit(struct SubSpriteData* pSub)
{
    u8 spriteID;
    u16 health;
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;
    u16 status;
    u16 offset;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_CATERPILLAR_KILLED))
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.yPosition += 0x8;
        pSub->yPosition = gCurrentSprite.yPosition;
        pSub->xPosition = gCurrentSprite.xPosition;

        yPosition = pSub->yPosition;
        xPosition = pSub->xPosition;

        gCurrentSprite.xPositionSpawn = xPosition;
        spriteID = gCurrentSprite.spriteID;
        if (spriteID == PSPRITE_IMAGO_LARVA_LEFT)
        {
            // Left larva
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.hitboxLeftOffset = -0x78;
            gCurrentSprite.hitboxRightOffset = 0x58;
            gCurrentSprite.pose = IMAGO_LARVA_POSE_IDLE;
            gDoorUnlockTimer = 0x1;
            PlayMusic(MUSIC_CATTERPILLARS_BATTLE_2, 0x0);
        }
        else
        {
            // Right larva
            gCurrentSprite.hitboxLeftOffset = -0x58;
            gCurrentSprite.hitboxRightOffset = 0x78;

            // Move to cocoon
            pSub->xPosition += BLOCK_SIZE * 11;
            xPosition += BLOCK_SIZE * 11;
            gCurrentSprite.pose = IMAGO_LARVA_POSE_DETECT_SAMUS;
        }

        gCurrentSprite.drawDistanceTopOffset = 0x28;
        gCurrentSprite.drawDistanceBottomOffset = 0x28;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

        gCurrentSprite.hitboxTopOffset = -0x30;
        gCurrentSprite.hitboxBottomOffset = 0x0;

        gCurrentSprite.workVariable2 = 0x0;
        gCurrentSprite.arrayOffset = 0x0;
        gCurrentSprite.timer = 0x0;
        gCurrentSprite.workVariable = 0x0;
        gCurrentSprite.yPositionSpawn = 0x0;
        gCurrentSprite.samusCollision = SSC_NONE;

        health = sPrimarySpriteStats[spriteID][0];
        gCurrentSprite.health = health;
        pSub->health = health;

        pSub->pMultiOam = sImagoLarvaMultiSpriteData_Idle;
        pSub->animationDurationCounter = 0x0;
        pSub->currentAnimationFrame = 0x0;

        // Immune to retreating flag
        pSub->workVariable2 = FALSE;
        // Retreating counter
        pSub->workVariable1 = 0x0;

        gCurrentSprite.drawOrder = 0x6;
        gCurrentSprite.frozenPaletteRowOffset = 0x2;
        gCurrentSprite.roomSlot = IMAGO_LARVA_PART_LARVA;

        gfxSlot = gCurrentSprite.spritesetGFXSlot;
        ramSlot = gCurrentSprite.primarySpriteRAMSlot;
        status = gCurrentSprite.status & SPRITE_STATUS_XFLIP;

        // Spawn secondaries
        SpriteSpawnSecondary(SSPRITE_IMAGO_LARVA_PART, IMAGO_LARVA_PART_CLAWS, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_LARVA_PART, IMAGO_LARVA_PART_RIGHT_DOT, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_LARVA_PART, IMAGO_LARVA_PART_MIDDLE_DOT, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_LARVA_PART, IMAGO_LARVA_PART_LEFT_DOT, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_LARVA_PART, IMAGO_LARVA_PART_SHELL, gfxSlot, ramSlot, yPosition, xPosition, status);
    }
}

/**
 * @brief 25c14 | 38 | Checks if samus is in range for an Imago larva to attack
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaDetectSamus(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();

    if (pSub->xPosition > gSamusData.xPosition && pSub->xPosition - gSamusData.xPosition < BLOCK_SIZE * 5)
        gCurrentSprite.pose = IMAGO_LARVA_POSE_WARNING_INIT;
}

/**
 * @brief 25c4c | 1c | Initializes an Imago larva to be idle
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaIdleInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_Idle;
    pSub->animationDurationCounter = 0x0;
    pSub->currentAnimationFrame = 0x0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_IDLE;
}

/**
 * @brief 25c68 | c | Handles an Imago larva being idle
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaIdle(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();
}

/**
 * @brief 25c74 | 28 | Initializes an Imago larva to be retreating
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaRetreatingInit(struct SubSpriteData* pSub)
{
    if (pSub->pMultiOam != sImagoLarvaMultiSpriteData_Retreating)
    {
        pSub->pMultiOam = sImagoLarvaMultiSpriteData_Retreating;
        pSub->animationDurationCounter = 0x0;
        pSub->currentAnimationFrame = 0x0;
    }

    gCurrentSprite.pose = IMAGO_LARVA_POSE_RETREATING;
}

/**
 * @brief 25c9c | 68 | Handles an Imago larva retreating
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaRetreating(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();

    if (gCurrentSprite.timer-- != 0x0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            // Check can move
            if (pSub->xPosition >= gCurrentSprite.xPositionSpawn - BLOCK_SIZE * 5)
                pSub->xPosition -= gCurrentSprite.yPositionSpawn;
        }
        else
        {
            // Check can move
            if (pSub->xPosition <= gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 11)
                pSub->xPosition += gCurrentSprite.yPositionSpawn;
        }
    }
    else
        gCurrentSprite.pose = IMAGO_LARVA_POSE_STUNNED_INIT;
}

/**
 * @brief 25d04 | 1c | Initializes an Imago larva sprite to be stunned
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaStunnedInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_Idle;
    pSub->animationDurationCounter = 0x0;
    pSub->currentAnimationFrame = 0x0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_STUNNED;
}

/**
 * @brief 25d20 | 28 | Handles an Imago larva being stunned
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaStunned(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();

    if (gCurrentSprite.workVariable-- == 0x0)
        gCurrentSprite.pose = IMAGO_LARVA_POSE_WARNING_INIT;
}

/**
 * @brief 25d48 | 34 | Initializes an Imago larva to do the warning
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaWarningInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_Warning;
    pSub->animationDurationCounter = 0x0;
    pSub->currentAnimationFrame = 0x0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_WARNING;
    gCurrentSprite.timer = 0x3C;
    pSub->workVariable1 = 0x0;

    SoundPlay(0xAD);
}

/**
 * @brief 25d7c | 24 | Checks if the warning animation has ended
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaCheckWarningAnimEnded(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();

    if (SpriteUtilCheckNearEndSubSpriteAnim(pSub))
        gCurrentSprite.pose = IMAGO_LARVA_POSE_ATTACKING_INIT;
}

/**
 * @brief 25da0 | 28 | Initializes an Imago larva to be attacking
 * 
 * @param pSub 
 */
void ImagoLarvaAttackingInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_Attacking;
    pSub->animationDurationCounter = 0x0;
    pSub->currentAnimationFrame = 0x0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_ATTACKING;
    SoundPlay(0xAE);
}

/**
 * @brief 25dc8 | 34 | Handles an Imago larva attacking
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaAttacking(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        pSub->xPosition += 0x8;
        if (pSub->xPosition >= gCurrentSprite.xPositionSpawn)
        {
            // Reached spawn position, set idle
            pSub->xPosition = gCurrentSprite.xPositionSpawn;
            gCurrentSprite.pose = IMAGO_LARVA_POSE_IDLE_INIT;
            SoundFade(0xAE, 0xA);
        }
    }
    else
    {
        pSub->xPosition -= 0x8;
        if (pSub->xPosition <= gCurrentSprite.xPositionSpawn)
        {
            // Reached spawn position, set idle
            pSub->xPosition = gCurrentSprite.xPositionSpawn;
            gCurrentSprite.pose = IMAGO_LARVA_POSE_IDLE_INIT;
            SoundFade(0xAE, 0xA);
        }
    }
}

/**
 * @brief 25e2c | 38 | Initializes an Imago larva to be taking damage
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaTakingDamageInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_TakingDamage;
    pSub->animationDurationCounter = 0x0;
    pSub->currentAnimationFrame = 0x0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_TAKING_DAMAGE;
    gCurrentSprite.timer = 0x2F;
    pSub->workVariable1 = 0x0;

    SoundFade(0xAE, 0xA);
}

/**
 * @brief 25e64 | 24 | Handles an Imago larva taking damage 
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaTakingDamage(struct SubSpriteData* pSub)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
        gCurrentSprite.pose = IMAGO_LARVA_POSE_ATTACKING_INIT;
}

/**
 * @brief 25e88 | 64 | Initializes an Imago larva to be dying
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaDyingInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_Dying;
    pSub->animationDurationCounter = 0x0;
    pSub->currentAnimationFrame = 0x0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_DYING;
    gCurrentSprite.timer = 0x64;
    gCurrentSprite.invincibilityStunFlashTimer &= 0x80;
    gCurrentSprite.invincibilityStunFlashTimer |= gCurrentSprite.timer;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.health = 0x1;

    SoundFade(0xAE, 0xA);
    SoundPlay(0xB0);

    if (gCurrentSprite.spriteID == PSPRITE_IMAGO_LARVA_RIGHT)
        FadeMusic(0xA);
}

/**
 * @brief 25eec | 28 | Handles an Imago larva dying
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaDying(struct SubSpriteData* pSub)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = IMAGO_LARVA_POSE_DEAD;
        gCurrentSprite.timer = 0x2;
    }
}

/**
 * @brief 25f14 | 5c | Kills the Imago larva
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaDeath(struct SubSpriteData* pSub)
{
    u16 yPosition;
    
    gCurrentSprite.timer--;

    if (gCurrentSprite.timer == 0x0)
    {
        if (gCurrentSprite.spriteID == PSPRITE_IMAGO_LARVA_RIGHT)
        {
            EventFunction(EVENT_ACTION_SETTING, EVENT_CATERPILLAR_KILLED);
            gDoorUnlockTimer = -0x3C;
            PlayMusic(0xB, 0x0); // Boss killed
        }

        yPosition = gCurrentSprite.yPosition - 0x24;
        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}

/**
 * @brief 25f70 | 1cc | Initializes an Imago larva part sprite
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaPartInit(struct SubSpriteData* pSub)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.health = 0x1;

    switch (gCurrentSprite.roomSlot)
    {
        case IMAGO_LARVA_PART_RIGHT_DOT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.pOam = sImagoLarvaPartOAM_RightDotVisible;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_IDLE;
            break;
            
        case IMAGO_LARVA_PART_MIDDLE_DOT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.pOam = sImagoLarvaPartOAM_MiddleDotVisible;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_IDLE;
            break;
            
        case IMAGO_LARVA_PART_LEFT_DOT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.pOam = sImagoLarvaPartOAM_LeftDotVisible;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_IDLE;
            break;

        case IMAGO_LARVA_PART_SHELL:
            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x38;

            gCurrentSprite.hitboxTopOffset = -0xB0;
            gCurrentSprite.hitboxBottomOffset = 0x0;

            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            {
                gCurrentSprite.hitboxLeftOffset = -0xA8;
                gCurrentSprite.hitboxRightOffset = 0x98;
            }
            else
            {
                gCurrentSprite.hitboxLeftOffset = -0x98;
                gCurrentSprite.hitboxRightOffset=  0xA8;
            }

            gCurrentSprite.samusCollision = SSC_KRAID;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_SHELL_IDLE;
            gCurrentSprite.health = 0xFF;
            break;

        case IMAGO_LARVA_PART_CLAWS:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

            gCurrentSprite.drawDistanceTopOffset = 0x18;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_CLAWS_IDLE;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 2613c | 180 | Handles an Imago larva shell being idle
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaPartShellIdle(struct SubSpriteData* pSub)
{
    u8 ramSlot;
    u8 speed;
    u16 health;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    if (gSpriteData[ramSlot].pose == IMAGO_LARVA_POSE_IDLE ||
        gSpriteData[ramSlot].pose == IMAGO_LARVA_POSE_STUNNED ||
        gSpriteData[ramSlot].pose == IMAGO_LARVA_POSE_DETECT_SAMUS)
    {
        if (gCurrentSprite.currentAnimationFrame & 0x1 && gCurrentSprite.animationDurationCounter == 0x1 &&
            gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(0xAA);
    }

    if (gSpriteData[ramSlot].spriteID == PSPRITE_IMAGO_LARVA_LEFT)
    {
        if (pSub->xPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE) < gSamusData.xPosition &&
            pSub->xPosition + (BLOCK_SIZE + HALF_BLOCK_SIZE) > gSamusData.xPosition)
            gCurrentSprite.hitboxBottomOffset = -0x20;
        else
            gCurrentSprite.hitboxBottomOffset = 0x0;

        if (gCurrentSprite.invincibilityStunFlashTimer & 0x7F)
        {
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
            gCurrentSprite.invincibilityStunFlashTimer &= 0x80;
            gCurrentSprite.health = 0xFF;
        }
    }
    else if (pSub->xPosition < gSamusData.xPosition)
    {
        if (gCurrentSprite.invincibilityStunFlashTimer & 0x7F)
        {
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
            gCurrentSprite.invincibilityStunFlashTimer &= 0x80;
            gCurrentSprite.health = 0xFF;
        }
    }
    else if (gCurrentSprite.invincibilityStunFlashTimer & 0x7F)
    {
        // Hit by something, check should retreat
        if (!pSub->workVariable2)
        {
            // Get speed
            health = 0xFF - gCurrentSprite.health;
            if (health >= 0x64)
                speed = 0x8;
            else if (health >= 0x14)
                speed = 0x4;
            else
                speed = 0x1;

            if (speed > 0x1)
                SoundPlay(0xAC);
            else
                SoundPlay(0xAB);

            // Update retreating counter
            if (pSub->workVariable1 < 0x8)
                pSub->workVariable1++;

            // Set retracting
            gSpriteData[ramSlot].timer = 0x10;
            // Set stunned delay
            gSpriteData[ramSlot].workVariable = pSub->workVariable1 * 8;
            // Set moving speed
            gSpriteData[ramSlot].yPositionSpawn = speed;
            gSpriteData[ramSlot].pose = IMAGO_LARVA_POSE_RETREATING_INIT;
        }

        gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
        gCurrentSprite.invincibilityStunFlashTimer &= 0x80;
        gCurrentSprite.health = 0xFF;
    }
}

/**
 * @brief 262bc | 60 | Handles an Imago larva dot being idle
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaPartDotIdle(struct SubSpriteData* pSub)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    if (gSpriteData[ramSlot].pose == IMAGO_LARVA_POSE_WARNING)
    {
        // Set disappearing
        if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_RIGHT_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOAM_RightDotDisappearing;
        else if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_MIDDLE_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOAM_MiddleDotDisappearing;
        else
            gCurrentSprite.pOam = sImagoLarvaPartOAM_LeftDotDisappearing;

        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_REMOVING;
        // Set immune to retreat flag
        pSub->workVariable2 = TRUE;
    }
}

/**
 * @brief 2631c | 50 | Checks if the disappearing animation ended
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaPartDotCheckDisappearingAnimEnded(struct SubSpriteData* pSub)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_RIGHT_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOAM_RightDotVisible;
        else if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_MIDDLE_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOAM_MiddleDotVisible;
        else
            gCurrentSprite.pOam = sImagoLarvaPartOAM_LeftDotVisible;

        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_CHECK_REAPPEAR;
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    }
}

/**
 * @brief 2636c | 68 | Checks if an Imago larva dot should re-appear
 * 
 * @param pSub 
 */
void ImagoLarvaPartDotCheckShouldReappear(struct SubSpriteData* pSub)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gSpriteData[ramSlot].pose == IMAGO_LARVA_POSE_IDLE)
    {
        // Set appearing
        if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_RIGHT_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOAM_RightDotAppearing;
        else if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_MIDDLE_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOAM_MiddleDotAppearing;
        else
            gCurrentSprite.pOam = sImagoLarvaPartOAM_LeftDotAppearing;

        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_REAPPEARING;
    }
}

/**
 * @brief 263d4 | 50 | Checks if the appearing animation ended
 * 
 * @param pSub 
 */
void ImagoLarvaPartDotCheckAppearingAnimEnded(struct SubSpriteData* pSub)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set visible
        if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_RIGHT_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOAM_RightDotVisible;
        else if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_MIDDLE_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOAM_MiddleDotVisible;
        else
            gCurrentSprite.pOam = sImagoLarvaPartOAM_LeftDotVisible;

        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_IDLE;
        // Remove immune to retreat flag
        pSub->workVariable2 = FALSE;
    }
}

/**
 * @brief 26424 | d0 | Handles an Imago larva part dying
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void ImagoLarvaPartDead(struct SubSpriteData* pSub)
{
    u8 ramSlot;
    u16 yPosition;
    u16 xPosition;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gSpriteData[ramSlot].pose == IMAGO_LARVA_POSE_DEAD)
    {
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;

        switch (gCurrentSprite.roomSlot)
        {
            case IMAGO_LARVA_PART_RIGHT_DOT:
                yPosition += QUARTER_BLOCK_SIZE;
                if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                    xPosition -= 0x48;
                else
                    xPosition += 0x48;
                break;

            case IMAGO_LARVA_PART_MIDDLE_DOT:
                yPosition -= QUARTER_BLOCK_SIZE;
                if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                    xPosition -= HALF_BLOCK_SIZE;
                else
                    xPosition += HALF_BLOCK_SIZE;
                break;

            case IMAGO_LARVA_PART_SHELL:
                yPosition -= BLOCK_SIZE;
                if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                    xPosition -= 0x78;
                else
                    xPosition += 0x78;
                break;

            case IMAGO_LARVA_PART_CLAWS:
                gCurrentSprite.status = 0x0;
                return;

            default:
            case IMAGO_LARVA_PART_LEFT_DOT:
                break;
        }

        // Kill sprite
        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, xPosition, FALSE, PE_SPRITE_EXPLOSION_BIG);
    }
}

/**
 * @brief 264f4 | 2c0 | Imago larva AI
 * 
 */
void ImagoLarva(void)
{
    struct SubSpriteData* pSub;

    // Get sub sprite data pointer
    if (gCurrentSprite.spriteID == PSPRITE_IMAGO_LARVA_LEFT)
        pSub = &gSubSpriteData2;
    else
        pSub = &gSubSpriteData1;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if ((u8)(gCurrentSprite.pose - 0x1) < IMAGO_LARVA_POSE_DYING_INIT - 1)
    {
        // Not dying
        // Check play damaged sound
        if (gCurrentSprite.properties & SP_DAMAGED)
        {
            gCurrentSprite.properties &= ~SP_DAMAGED;
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(0xAF);
        }

        // Check took damage
        if (pSub->health != gCurrentSprite.health)
        {
            pSub->health = gCurrentSprite.health;
            gCurrentSprite.pose = IMAGO_LARVA_POSE_TAKING_DAMAGE_INIT;
        }
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ImagoLarvaInit(pSub);
            break;

        case IMAGO_LARVA_POSE_DETECT_SAMUS:
            ImagoLarvaDetectSamus(pSub);
            break;

        case IMAGO_LARVA_POSE_IDLE_INIT:
            ImagoLarvaIdleInit(pSub);

        case IMAGO_LARVA_POSE_IDLE:
            ImagoLarvaIdle(pSub);
            break;

        case IMAGO_LARVA_POSE_RETREATING_INIT:
            ImagoLarvaRetreatingInit(pSub);

        case IMAGO_LARVA_POSE_RETREATING:
            ImagoLarvaRetreating(pSub);
            break;

        case IMAGO_LARVA_POSE_STUNNED_INIT:
            ImagoLarvaStunnedInit(pSub);

        case IMAGO_LARVA_POSE_STUNNED:
            ImagoLarvaStunned(pSub);
            break;

        case IMAGO_LARVA_POSE_WARNING_INIT:
            ImagoLarvaWarningInit(pSub);

        case IMAGO_LARVA_POSE_WARNING:
            ImagoLarvaCheckWarningAnimEnded(pSub);
            break;

        case IMAGO_LARVA_POSE_ATTACKING_INIT:
            ImagoLarvaAttackingInit(pSub);

        case IMAGO_LARVA_POSE_ATTACKING:
            ImagoLarvaAttacking(pSub);
            break;

        case IMAGO_LARVA_POSE_TAKING_DAMAGE_INIT:
            ImagoLarvaTakingDamageInit(pSub);

        case IMAGO_LARVA_POSE_TAKING_DAMAGE:
            ImagoLarvaTakingDamage(pSub);
            break;

        case IMAGO_LARVA_POSE_DYING_INIT:
            ImagoLarvaDyingInit(pSub);

        case IMAGO_LARVA_POSE_DYING:
            ImagoLarvaDying(pSub);
            break;

        case IMAGO_LARVA_POSE_DEAD:
            ImagoLarvaDeath(pSub);
    }

    if (gCurrentSprite.health != 0x0)
    {
        // Update sub sprites
        SpriteUtilUpdateSubSpriteAnim(pSub);
        ImagoLarvaSyncSubSprites(pSub);
    }
}

/**
 * @brief 267b4 | 108 | Imago larva part AI
 * 
 */
void ImagoLarvaPart(void)
{
    struct SubSpriteData* pSub;
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    // Get sub sprite data pointer
    if (gSpriteData[ramSlot].spriteID == PSPRITE_IMAGO_LARVA_LEFT)
        pSub = &gSubSpriteData2;
    else
        pSub = &gSubSpriteData1;

    if (gSpriteData[ramSlot].pose >= IMAGO_LARVA_POSE_DYING_INIT && gCurrentSprite.pose <= 0x61)
    {
        // Set dead
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DEAD;
        gCurrentSprite.invincibilityStunFlashTimer = gSpriteData[ramSlot].invincibilityStunFlashTimer;
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ImagoLarvaPartInit(pSub);
            break;

        case IMAGO_LARVA_PART_POSE_DOT_IDLE:
            ImagoLarvaPartDotIdle(pSub);
            break;

        case IMAGO_LARVA_PART_POSE_DOT_REMOVING:
            ImagoLarvaPartDotCheckDisappearingAnimEnded(pSub);
            break;

        case IMAGO_LARVA_PART_POSE_DOT_CHECK_REAPPEAR:
            ImagoLarvaPartDotCheckShouldReappear(pSub);
            break;

        case IMAGO_LARVA_PART_POSE_DOT_REAPPEARING:
            ImagoLarvaPartDotCheckAppearingAnimEnded(pSub);
            break;

        case IMAGO_LARVA_PART_POSE_SHELL_IDLE:
            ImagoLarvaPartShellIdle(pSub);
            break;
        
        case IMAGO_LARVA_PART_POSE_DEAD:
            ImagoLarvaPartDead(pSub);
            break;
    }

    if (gCurrentSprite.health != 0x0)
    {
        // Update sub sprites
        if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_SHELL || gCurrentSprite.roomSlot == IMAGO_LARVA_PART_CLAWS)
            ImagoLarvaSyncSubSprites(pSub);
        else
        {
            if (gCurrentSprite.pose == IMAGO_LARVA_PART_POSE_DEAD)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                ImagoLarvaSyncSubSprites(pSub);                
            }
            else
                SpriteUtilSyncCurrentSpritePositionWithSubSpritePositionAndOAM(pSub);
        }
    }
}
