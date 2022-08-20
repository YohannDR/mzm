#include "ruins_test.h"
#include "../../data/data.h"
#include "../globals.h"

/**
 * @brief 38988 | 24 | Calculates the new delay for the symbol
 * 
 * @param delay 
 */
void RuinsTestCalculateDelay(u8 delay)
{
    gBossWork.work5 = sRandomNumberTable[gFrameCounter8Bit] + delay;
}

/**
 * @brief 389ac | d8
 * 
 * @param caa Clipdata Affecting Action
 */
void RuinsTestChangeCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gBossWork.work1 - (BLOCK_SIZE * 6 + BLOCK_SIZE / 2);
    xPosition = gBossWork.work2;

    // Left side
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 1);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 2);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 3);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 4);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 5);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 6);

    // Right side
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 1);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 2);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 3);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 4);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 5);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 6);
}

/**
 * @brief 38a84 | 1d0 | Handles slowly moving an object from current position to target position
 * 
 * @param yTarget Y Position target
 * @param xTarget X Position target
 * @param yPosition Y Position current
 * @param xPosition X Position current
 * @param speedMultiplier Speed multiplier 
 * @param speed Speed
 */
void RuinsTestMoveToPosition(u16 yTarget, u16 xTarget, u16 yPosition, u16 xPosition, u16 speedMultiplier, u16 speed)
{
    u16 distanceY;
    u16 distanceX;
    i32 totalDistance;
    u16 samusY;
    u16 spriteY;
    u16 acceleration;

    speed *= speedMultiplier;

    if (yPosition > yTarget)
    {
        distanceY = yPosition - yTarget;
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
    }
    else
    {
        distanceY = yTarget - yPosition;
        gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
    }

    if (xPosition > xTarget)
    {
        distanceX = xPosition - xTarget;
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    }
    else
    {
        distanceX = xTarget - xPosition;
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            totalDistance = (u16)Sqrt(distanceX * distanceX + distanceY * distanceY);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = yTarget + ((speed * ((i32)(distanceY << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = xTarget + ((speed * ((i32)(distanceX << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceX * distanceX + distanceY * distanceY);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = yTarget - ((speed * ((i32)(distanceY << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = xTarget + ((speed * ((i32)(distanceX << 0xA) / totalDistance) >> 0xA));
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            totalDistance = (u16)Sqrt(distanceX * distanceX + distanceY * distanceY);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = yTarget + ((speed * ((i32)(distanceY << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = xTarget - ((speed * ((i32)(distanceX << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceX * distanceX + distanceY * distanceY);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = yTarget - ((speed * ((i32)(distanceY << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = xTarget - ((speed * ((i32)(distanceX << 0xA) / totalDistance) >> 0xA));
            }
        }
    }
}

/**
 * @brief 38c54 | 1d0 | Checks if a projectile is colliding with the shootable symbol
 * 
 * @return u8 
 */
u8 RuinsTestProjectileCollision(void)
{
    u8 damage;
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    struct ProjectileData* pProj;

    if (gDifficulty == DIFF_EASY)
        damage = 0x19;
    else if (gDifficulty == DIFF_HARD)
        damage = 0x64;
    else
        damage = 0x32;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    spriteTop = spriteY + gCurrentSprite.hitboxTopOffset;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottomOffset;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeftOffset;
    spriteRight = spriteX + gCurrentSprite.hitboxRightOffset;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if (pProj->status & PROJ_STATUS_EXISTS && pProj->status & PROJ_STATUS_CAN_AFFECT_ENVIRONMENT &&
            pProj->movementStage > 1 && (pProj->type == PROJ_TYPE_PISTOL || pProj->type == PROJ_TYPE_CHARGED_PISTOL) &&
            pProj->xPosition > spriteLeft && pProj->xPosition < spriteRight && pProj->yPosition > spriteTop && pProj->yPosition < spriteBottom)
        {
            pProj->status &= ~PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;

            if (gSamusData.invincibilityTimer == 0x0)
            {
                // Apply damage
                if (gEquipment.currentEnergy > damage)
                    gEquipment.currentEnergy -= damage;
                else
                    gEquipment.currentEnergy = 0x0;
                gSamusData.forcedMovement = 0xFF;
                SamusSetPose(SPOSE_HURT_REQUEST);
                return TRUE;
            }
        }
    }

    return FALSE;
}

/**
 * @brief 38d28 | 48 | Checks if a charged pistol is colliding with the shootable symbol 
 * 
 * @return u8 
 */
u8 RuinsTestCheckHitByChargedPistol(void)
{
    struct ProjectileData* pProj;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if (pProj->status & PROJ_STATUS_EXISTS && pProj->status & PROJ_STATUS_CAN_AFFECT_ENVIRONMENT &&
            pProj->movementStage > 1 && pProj->type == PROJ_TYPE_CHARGED_PISTOL)
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 38d70 | 84 | Checks if a symbol is getting shot
 * 
 * @return u8 1 if last symbol, 0 otherwise
 */
u8 RuinsTestCheckSymbolShooted(void)
{
    if (gCurrentSprite.invicibilityStunFlashTimer != 0x0 && gCurrentSprite.health != 0x64)
    {
        SoundPlay(0x1D9);
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.health = 0x64;

        gSubSpriteData1.health++;
        if (gSubSpriteData1.health > 0x3)
        {
            // Last symbol
            gCurrentSprite.pose = 0x67;
            gSubSpriteData1.workVariable3 = 0x1;
            gSubSpriteData1.workVariable1 = 0x1;
            gCurrentSprite.oamScaling = 0x0;
            gCurrentSprite.samusCollision = SSC_NONE;

            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.invicibilityStunFlashTimer += 0x3C;

            return TRUE;
        }

        gSubSpriteData1.workVariable1 = 0x80;
        RuinsTestCalculateDelay(0xF0);
    }

    return FALSE;
}

/**
 * @brief 38df4 | 34 | Checks if samus is getting hurt
 * 
 * @return u8 1 if getting hurt, 0 otherwise
 */
u8 RuinsTestCheckSamusHurting(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
    {
        if (gSamusData.pose == SPOSE_GETTING_HURT)
            return TRUE;

        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
    }

    return FALSE;
}

/**
 * @brief 38e28 | 11c | Updates the symbol
 * 
 * @return u8 
 */
u8 RuinsTestUpdateSymbol(void)
{
    u8 ramSlot;

    if (gSubSpriteData1.workVariable1 & 0x7F)
    {
        if (gSubSpriteData1.workVariable1 == 0x1)
        {
            if (!RuinsTestCheckHitByChargedPistol())
                gSubSpriteData1.workVariable1--;
        }
        else
            gSubSpriteData1.workVariable1--;

        if (gCurrentSprite.status & SPRITE_STATUS_IGNORE_PROJECTILES)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;

            ramSlot = SpriteSpawnSecondary(SSPRITE_RUINS_TEST_SHOOTABLE_SYMBOL, 0x0, gCurrentSprite.spritesetGFXSlot,
                gCurrentSprite.primarySpriteRAMSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0x0);

            if (ramSlot < MAX_AMOUNT_OF_SPRITES)
                gSpriteData[ramSlot].health = gSubSpriteData1.health;
        }
    }
    else
    {
        if (!(gCurrentSprite.status & SPRITE_STATUS_IGNORE_PROJECTILES))
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        if (!(gSubSpriteData1.workVariable1 & 0x80))
        {
            if (gBossWork.work3 == 0x0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                RuinsTestCalculateDelay(0xF0);
                return TRUE;
            }

            if (gBossWork.work5 == 0x0)
            {
                // Set timer for how long symbol stays active
                if (gSubSpriteData1.health == 0x0)
                    gSubSpriteData1.workVariable1 = 0x78;
                else if (gSubSpriteData1.health == 0x1)
                    gSubSpriteData1.workVariable1 = 0x5A;
                else if (gSubSpriteData1.health == 0x2)
                    gSubSpriteData1.workVariable1 = 0x3C;
                else
                    gSubSpriteData1.workVariable1 = 0x28;

                // Get new delay
                RuinsTestCalculateDelay(0x78);
            }
            else
            {
                // Decrement delay
                gBossWork.work5--;
                if (RuinsTestProjectileCollision())
                {
                    // Reset delay
                    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
                    RuinsTestCalculateDelay(0x78);
                }
            }
        }
    }

    return FALSE;
}

void RuinsTestGhostMove(u8 speed)
{
    // https://decomp.me/scratch/clUGQ

    i32 multiplier;
    i32 sine;
    u8 offset;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.workVariable += speed;
    else
        gCurrentSprite.workVariable -= speed;

    multiplier = (i16)gCurrentSprite.oamScaling;

    offset = gCurrentSprite.workVariable;
    sine = sSineYValues[offset];

    if (sine < 0x0)
    {
        sine = (i16)(-sine * multiplier) >> 0x8;
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn - sine;
    }
    else
    {
        sine = (i16)(sine * multiplier) >> 0x8;
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn + sine;
    }

    sine = sSineYValues[offset + 0x40];

    if (sine < 0x0)
    {
        sine = (i16)(-sine * multiplier) >> 0x8;
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn - sine;
    }
    else
    {
        sine = (i16)(sine * multiplier) >> 0x8;
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn + sine;
    }
}

void RuinsTestInit(void)
{

}

void RuinsTestSpawningAnim(void)
{

}

void RuinsTestSpawnReflectionStart(void)
{

}

void unk_39194(void)
{

}

void RuinsTestCheckSamusNotFacingBackground(void)
{

}

void unk_391f0(void)
{

}

void RuinsTestSpawnGhost(void)
{

}

void RuinsTestAfterGhostSpawn(void)
{

}

void RuinsTestGhostMaybeMoveSecondPhase(void)
{

}

void RuinsTestMaybeMoveSecondPhase(void)
{

}

void RuinsTestMoveGhostToCenter(void)
{

}

void RuinsTestCheckAllSymbolsInPlace(void)
{

}

void RuinsTestReflectionEnd(void)
{

}

void RuinsTestGhostInit(void)
{

}

void RuinsTestGhostSpawn(void)
{

}

void RuinsTestGhostSyncPosition(void)
{

}

void RuinsTestGhostDespawn(void)
{

}

void unk_39a40(void)
{

}

void RuinsTestGhostAfterFirstSymbol(void)
{

}

void RuinsTestGhostAfterFight(void)
{

}

void unk_39e14(void)
{

}

void unk_39e3c(void)
{

}

void RuinsTest(void)
{

}

void RuinsTestSymbol(void)
{

}

void RuinsTestSamusReflectionStart(void)
{

}

void RuinsTestReflectionCover(void)
{

}

void RuinsTestGhostOutline(void)
{

}

void RuinsTestShootableSymbol(void)
{

}

void RuinsTestGhost(void)
{

}

void RuinsTestSamusReflectionEnd(void)
{

}

void RuinsTestLightningInit(void)
{

}

void RuinsTestLightning(void)
{

}