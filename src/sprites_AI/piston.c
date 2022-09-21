#include "sprites_AI/piston.h"
#include "data/data.h"
#include "data/sprites/piston.c"
#include "globals.h"

/**
 * @brief 31708 | 54 | Updates the clipdata of the 4 piston blocks
 * 
 * @param caa 
 */
void PistonChangeFourCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - ((BLOCK_SIZE * 0x2) + (HALF_BLOCK_SIZE)), xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - ((BLOCK_SIZE * 0x3) + (HALF_BLOCK_SIZE)), xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - ((BLOCK_SIZE * 0x4) + (HALF_BLOCK_SIZE)), xPosition);
}

/**
 * @brief 3175c | 20 | Updates the clipdata of the bottom block of the piston
 * 
 * @param caa 
 */
void PistonChangeOneBelowCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (HALF_BLOCK_SIZE), xPosition);
}

/**
 * @brief 3177c | 28 | Updates the clipdata of the top block of the piston
 * 
 * @param caa 
 */
void PistonChangeOneUpperCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - ((BLOCK_SIZE * 0x5) + (HALF_BLOCK_SIZE)), xPosition);
}

/**
 * @brief 317a4 | 40 | Checks if samus is colliding with the piston
 * 
 * @return u8 1 if colliding, 0 otherwise
 */
u8 PistonSamusCollision(void)
{
    // Not 100% what this function is supposed to do, my best guess is that it was supposed
    // to check if samus is in the pison when retracting, but pistons can't retract in the final game

    u8 result;
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;

    result = FALSE;
    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;

    if (spriteY - (BLOCK_SIZE - 0x10) < samusY && spriteY + (BLOCK_SIZE - 0x10) > samusY
        && spriteX - (BLOCK_SIZE - 0x10) < samusX && spriteX + (BLOCK_SIZE - 0x10) > samusX)
        result = TRUE;

    return result;
}

/**
 * @brief 317e4 | 4c | Checks if samus is colliding with the piston upper part when it goes up
 * 
 * @return u8 
 */
u8 PistonCheckSamusIn(void)
{
    u8 result;
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;

    result = FALSE;
    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;
    spriteY = gCurrentSprite.yPosition - (BLOCK_SIZE * 0x5); // Offset to the top of the piston
    spriteX = gCurrentSprite.xPosition;

    if (spriteY - (BLOCK_SIZE - 0x10) < samusY && spriteY + (BLOCK_SIZE - 0x10) > samusY
        && spriteX - (BLOCK_SIZE - 0x10) < samusX && spriteX + (BLOCK_SIZE - 0x10) > samusX)
        result = TRUE;

    return result;
}

/**
 * @brief 31830 | 60 | Initializes a piston sprite
 * 
 */
void PistonInit(void)
{
    gCurrentSprite.drawDistanceTopOffset = 0x64;
    gCurrentSprite.drawDistanceBottomOffset = 0x0;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

    gCurrentSprite.hitboxLeftOffset = -0x18;
    gCurrentSprite.hitboxRightOffset = 0x18;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.health = 0x100;
    gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
    gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;

    PistonChangeFourCCAA(CAA_MAKE_SOLID3); // Set hitbox
}

/**
 * @brief 31890 | 2c | Initializes the GFX for a piston
 * 
 */
void PistonGFXInit(void)
{
    gCurrentSprite.pOam = sPistonOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = PISTON_POSE_CHECK_FOR_PROJECTILES;

    gCurrentSprite.hitboxTopOffset = -0x74;
    gCurrentSprite.hitboxBottomOffset = -0x6C;
}

/**
 * @brief 318bc | 88 | Detects if a projectile is hitting the pistol
 * 
 */
void PistonCheckProjectile(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        if ((gCurrentSprite.invicibilityStunFlashTimer & 0x7F) == 0x10)
        {
            // Projectile detected
            gCurrentSprite.invicibilityStunFlashTimer &= 0x80;
            gCurrentSprite.health = 0x100;

            gCurrentSprite.pOam = sPistonOAM_Opening;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = PISTON_POSE_OPENING;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            SoundPlay(0x173);
        }
    }
    else if (!PistonSamusCollision())
    {
        PistonChangeOneBelowCCAA(CAA_MAKE_SOLID3);
        gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    }
}

/**
 * @brief 31944 | 58 | Handles the piston opening
 * 
 */
void PistonOpen(void)
{
    if (gCurrentSprite.currentAnimationFrame == 0x2 && gCurrentSprite.animationDurationCounter == 0x1)
    {
        // Remove collision of the bottom part
        PistonChangeOneBelowCCAA(CAA_REMOVE_SOLID);
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
    }

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Opening animation done, set opened behavior
        gCurrentSprite.pOam = sPistonOAM_Opened;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = PISTON_POSE_OPENED;
        gCurrentSprite.hitboxTopOffset = -0xB4;
        gCurrentSprite.hitboxBottomOffset = -0xAC;
    }
}

/**
 * @brief 3199c | 34 | Handles the piston being opened
 * 
 */
void PistonOpened(void)
{
    // Check should set the top solid (not already solid and samus not in the block)
    if (!(gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING) && !PistonCheckSamusIn())
    {
        PistonChangeOneUpperCCAA(CAA_MAKE_SOLID3); // Set collision of top part
        gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING; // Set flag to know collision has been set
    }
}

/**
 * @brief 319d0 | d4 | Piston AI
 * 
 */
void Piston(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            PistonInit();

        case 0x8:
            PistonGFXInit();
        
        case PISTON_POSE_CHECK_FOR_PROJECTILES:
            PistonCheckProjectile();
            break;

        case PISTON_POSE_OPENING:
            PistonOpen();
            break;

        case PISTON_POSE_OPENED:
            PistonOpened();
            break;
    }
}