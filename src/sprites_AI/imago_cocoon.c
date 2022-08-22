#include "imago_cocoon.h"
#include "../event.h"
#include "../sprite.h"
#include "../sprite_util.h"
#include "../sprite_debris.h"
#include "../screen_shake.h"
#include "../particle.h"
#include "../globals.h"

void ImagoCocoonUpdatePositionAndAnim(void)
{
    
}

/**
 * 26ca0 | 40 | Updates the current clipdata affecting action and applies it, removes the middle block of the ground when falling
 * 
 * @param caa Clipdata Affecting Action to apply
 */
void ImagoCocoonChangeOneCCAA(u8 caa)
{
    u32 yPosition;
    u16 xPosition;

    yPosition = (u16)(gCurrentSprite.yPositionSpawn + 0x2C0);
    xPosition = gSubSpriteData1.xPosition;
    gCurrentClipdataAffectingAction = caa;
    yPosition -= 0x20;
    ClipdataProcess(yPosition, xPosition);
    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_HUGE);
}

/**
 * 26ce0 | 70 | Updates the current clipdata affecting action and applies it, removes the 2 blocks around the middle of the ground when falling
 * 
 * @param caa Clipdata Affecting Action to apply
 */
void ImagoCocoonChangeTwoMiddleCCAA(u8 caa)
{
    u32 yPosition;
    u32 yPosition_;
    u16 xPosition;

    yPosition = (u16)(gCurrentSprite.yPositionSpawn + 0x2C0);
    xPosition = gSubSpriteData1.xPosition;
    gCurrentClipdataAffectingAction = caa;
    yPosition_ = yPosition - 0x20,
    ClipdataProcess(yPosition_, xPosition + 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition_, xPosition - 0x40);

    ParticleSet(yPosition, xPosition + 0x48, PE_SPRITE_EXPLOSION_HUGE);
    ParticleSet(yPosition, xPosition - 0x48, PE_SPRITE_EXPLOSION_HUGE);
}

void ImagoCocoonChangeTwoAroundCCAA(u8 caa)
{
    
}

/**
 * 26dcc | 5c | Updates the current clipdata affecting action and applies it, removes the 2 blocks that block the passage
 * 
 * @param caa Clipdata Affecting Action to apply
 */
void ImagoCocoonChangeTwoBlockingCCAA(u8 caa)
{
    u32 yPosition;
    u32 yPosition_;
    u32 xPosition;

    yPosition = (u16)(gCurrentSprite.yPositionSpawn + 0x340);
    xPosition = gSubSpriteData1.xPosition;
    gCurrentClipdataAffectingAction = caa;
    yPosition_ = yPosition + 0x20;
    xPosition += 0x240;
    ClipdataProcess(yPosition_, xPosition);
    gCurrentClipdataAffectingAction = caa;
    yPosition += 0x60;
    ClipdataProcess(yPosition, xPosition);
}

/**
 * 26e28 | 54 | 
 * Changes the oam scaling of the imago cocoon (growing or shrinking)
 * 
 * @param limit The limit of the scaling
 * @param value The value to increment/decrement the scaling
 */
void ImagoCocoonChangeOAMScaling(u16 limit, u16 value)
{
    if (gCurrentSprite.workVariable2 != 0x0) // Check growing/shrinking
    {
        if (gCurrentSprite.oamScaling > (0x100 - limit))
            gCurrentSprite.oamScaling -= value;
        else
            gCurrentSprite.workVariable2 = 0x0; // Set growing
    }
    else
    {
        if (gCurrentSprite.oamScaling < (limit + 0x100))
            gCurrentSprite.oamScaling += value;
        else
            gCurrentSprite.workVariable2 = 0x1; // Set shrinking
    }
}

void ImagoCocoonInit(void)
{
    
}

/**
 * 27128 | 2c | Handles the movement of imago cocoon falling
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

void imago_cocoon_main_loop(void)
{
    
}

/**
 * 27284 | 174 | Handles imago cocoon falling before he destroyed the blocks on the ground
 * 
 */
void ImagoCocoonFallingBeforeBlocks(void)
{
    // /!\ Calculs with the xPosition are wrong
    u16 yPosition;
    u32 xPosition;
    u32 offset;
    u32 rng;
    u8 timer;

    if ((gFrameCounter8Bit & 0x1F) == 0x0)
        ImagoCocoonChangeOAMScaling(0x1, 0x1);

    if (gSubSpriteData1.currentAnimationFrame > 0x7)
    {
        ImagoCocoonFallingMovement();
        yPosition = gSubSpriteData1.yPosition + 0x180;
        xPosition = gSubSpriteData1.xPosition;
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition);
        if (gPreviousCollisionCheck & 0xF0) // Check for solid collision
        {
            ImagoCocoonChangeOneCCAA(CAA_REMOVE_SOLID); // Remove middile block
            gCurrentSprite.pose = 0x23;
            gCurrentSprite.timer = 0x0;
            ScreenShakeStartVertical(0x28, 0x81);
            SoundPlay(0x1A4);
        }
    }
    else
    {
        if (gSubSpriteData1.currentAnimationFrame == 0x7 && gSubSpriteData1.animationDurationCounter == 0x6)
            SpriteSpawnSecondary(SSPRITE_IMAGO_CEILING_VINE, 0x0, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0x0);

        yPosition = gBG1YPosition - 0x40;
        xPosition = gSubSpriteData1.xPosition;
        rng = gSpriteRNG;
        timer = gCurrentSprite.timer = gCurrentSprite.timer + 0x1;
        if ((timer & 0x1F) == 0x0)
        {
            if (timer & 0x20)
            {
                offset = (rng * 0x8) - 0x5A;
                xPosition -= offset;
                SpriteDebrisInit(0x0, 0x5, yPosition, xPosition);
            }
            else
            {
                offset = (rng * 0x8) + 0x5A;
                xPosition -= offset;
                SpriteDebrisInit(0x0, 0x5, yPosition, xPosition);
            }
        }
        
        if (gSubSpriteData1.currentAnimationFrame > 0x3 && (timer & 0x1) == 0x0)
        {
            if (rng > 0x8)
            {
                offset = (rng * 0x4) - 0x96;
                xPosition += offset;
                SpriteDebrisInit(0x0, 0x8, yPosition, xPosition);
                offset = (rng * 0x4) - 0x20;
                xPosition -= offset;
                SpriteDebrisInit(0x0, 0x6, yPosition, xPosition);
            }
            else
            {
                offset = (rng * 0x4) - 0x82;
                xPosition -= offset;
                SpriteDebrisInit(0x0, 0x6, yPosition, xPosition);
                offset = (rng * 0x4) - 0x20;
                xPosition += offset;
                SpriteDebrisInit(0x0, 0x8, yPosition, xPosition);
            }
        }
    }
}

void ImagoCocoonFallingAfterBlocks(void)
{
    
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
            gCurrentSprite.pose = 0x27;
            ImagoCocoonChangeTwoBlockingCCAA(CAA_REMOVE_SOLID); // Remove blocking collision
            gDoorUnlockTimer = -0x3C;
            music_play(0xB, 0x0); // Boss killed
        }
    }
}

void ImagoCocoonInGroundAnim(void)
{
    
}

void ImagoCocoonVineInit(void)
{
    
}

void ImagoCocoonVinePlaySound(void)
{
    
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
        case 0x1:
            break;
        case 0x2:
        case 0x6:
        case 0x7:
            yPosition += 0x20;
            break;
        case 0x8:
        case 0x9:
            yPosition += 0x10;
            break;
        default:
            gCurrentSprite.status = 0x0;
            return;
    }

    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_HUGE);
    if (gSubSpriteData1.health != 0x0)
        gSubSpriteData1.health--; // Health = number of vines alive so when a vine dies it gets decremented
    gCurrentSprite.status = 0x0;
}

/**
 * 2798c | 160 | Handles the vines spawning the spores, and the ceiling vine attached to imago cocoon dying?
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

    if (gSpriteData[slot].pose == 0x25)
    {
        yPosition = gCurrentSprite.yPosition;
        if (gCurrentSprite.roomSlot == 0x0)
            xPosition = gCurrentSprite.xPosition + 0x40;
        else
            xPosition = gCurrentSprite.xPosition - 0x40;
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
                yPosition = gCurrentSprite.yPosition - 0x60;
                xPosition = gCurrentSprite.xPosition - 0x46;
                status = SPRITE_STATUS_NONE;
            }
            else
            {
                // Spore on the right
                yPosition = gCurrentSprite.yPosition - 0x90;
                xPosition = gCurrentSprite.xPosition + 0x64;
                status = SPRITE_STATUS_XFLIP;
            }

            gfxSlot = gCurrentSprite.spritesetGFXSlot;
            ramSlot = gCurrentSprite.workVariable;
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, 0x0, gfxSlot, ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, 0x1, gfxSlot, ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, 0x2, gfxSlot, ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, 0x3, gfxSlot, ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, 0x4, gfxSlot, ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, 0x5, gfxSlot, ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, 0x6, gfxSlot, ramSlot, yPosition, xPosition, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, 0x7, gfxSlot, ramSlot, yPosition, xPosition, status);
        }
    }
}

/**
 * 27aec | 44 | Handles the removal of the hanging vine when imago cocoon dies
 * 
 */
void ImagoCocoonVineHangingDeath(void)
{
    if (gSubSpriteData1.health == 0x0 && gSubSpriteData1.currentAnimationFrame > 0x7)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = 0x43;
    }
}

/**
 * 27b30 | 44 | Handles the animation of the removal of the hanging vine when imago cocoon dies
 * 
 */
void ImagoCocoonVineHangingDeathAnim(void)
{
    u8 slot;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    slot = gCurrentSprite.primarySpriteRAMSlot;
    if (gSpriteData[slot].pose == 0x25)
    {
        ParticleSet(gCurrentSprite.yPosition + 0xA0, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_HUGE);
        gCurrentSprite.status = 0x0;
    }
}

/**
 * 27b74 | 54 | Synchronizes the spore position with the imago cocoon position
 * 
 */
void ImagoCocoonSporeSyncPosition(void)
{
    u8 slot;

    slot = gCurrentSprite.primarySpriteRAMSlot;
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        gCurrentSprite.yPosition = gSpriteData[slot].yPosition - 0x90;
        gCurrentSprite.xPosition = gSpriteData[slot].xPosition + 0x64;
    }
    else
    {
        gCurrentSprite.yPosition = gSpriteData[slot].yPosition - 0x60;
        gCurrentSprite.xPosition = gSpriteData[slot].xPosition + 0x46;
    }
}

/**
 * 27bc8 | a8 | Initialize an imago cocoon spore sprite
 * 
 */
void ImagoCocoonSporeInit(void)
{
    if (gCurrentSprite.roomSlot == 0x0)
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.drawDistanceTopOffset = 0xC;
    gCurrentSprite.drawDistanceBottomOffset = 0xC;
    gCurrentSprite.drawDistanceHorizontalOffset = 0xC;
    gCurrentSprite.hitboxTopOffset = -0x8;
    gCurrentSprite.hitboxBottomOffset = 0x8;
    gCurrentSprite.hitboxLeftOffset = -0x8;
    gCurrentSprite.hitboxRightOffset = 0x5;
    gCurrentSprite.pOam = imago_cocoon_spore_oam_2e0bd0;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawOrder = 0x3;
    gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
    gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    ImagoCocoonSporeSyncPosition();
}

/**
 * 27c70 | 74 | Handles an imago cocoon spore before it spawns (after it appeared, but before it moves)
 * 
 */
void ImagoCocoonSporeBeforeSpawning(void)
{
    ImagoCocoonSporeSyncPosition();
    if (gSubSpriteData1.health == 0x0)
        gCurrentSprite.pose = 0x42; // If imago cocoon is dead, kill the spores
    else
    {
        if (gCurrentSprite.roomSlot == 0x0 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && gCurrentSprite.currentAnimationFrame == 0x0 && gCurrentSprite.animationDurationCounter == 0x1)
            SoundPlay(0x1A0);

        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.pOam = imago_cocoon_spore_oam_2e0bf8;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.pose = 0x23;
            gCurrentSprite.timer = 0x3C;
        }
    }
}

/**
 * 27ce4 | 8c | Handles the spawning of the imago cocoon spore  
 * 
 */
void ImagoCocoonSporeSpawning(void)
{
    ImagoCocoonSporeSyncPosition();
    if (gSubSpriteData1.health == 0x0)
        gCurrentSprite.pose = 0x42; // If imago cocoon is dead, kill the spores
    else
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
            gCurrentSprite.pOam = imago_cocoon_spore_oam_2e0c18;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
            gCurrentSprite.pose = 0x25;
            if (gCurrentSprite.roomSlot == 0x0 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(0x1A1);
        }
    }
}

void ImagoCocoonSporeMove(void)
{
    
}

/**
 * 27e84 | 34 | Initializes the graphics for the imago cocoon spore exploding
 * 
 */
void ImagoCocoonSporeExplodingGFXInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.pOam = imago_cocoon_spore_oam_2e0c38;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = 0x43;
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

// 27edc | c4 | Checks if the winged ripper and imago are colliding (only if imago is falling), sets the winged ripper to a killed pose if yes
// Returns : 1 if colliding, 0 otherwise
u8 WingedRipperImagoCollision(void)
{
    u8 colliding;
    u8 slot;
    struct SpriteData* pSprite;
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u16 imago_y;
    u16 imago_x;
    u16 imago_top;
    u16 imago_bottom;
    u16 imago_left;
    u16 imago_right;

    colliding = FALSE;
    pSprite = gSpriteData + gCurrentSprite.primarySpriteRAMSlot;
    if (pSprite->pose == 0x9 && pSprite->arrayOffset > 0x10)
    {
        spriteY = gCurrentSprite.yPosition;
        spriteX = gCurrentSprite.xPosition;
        spriteTop = spriteY + gCurrentSprite.hitboxTopOffset;
        spriteBottom = spriteY + gCurrentSprite.hitboxBottomOffset;
        spriteLeft = spriteX + gCurrentSprite.hitboxLeftOffset;
        spriteRight = spriteX + gCurrentSprite.hitboxRightOffset;
        
        imago_y = pSprite->yPosition;
        imago_x = pSprite->xPosition;
        imago_top = imago_y + pSprite->hitboxTopOffset;
        imago_bottom = imago_y + pSprite->hitboxBottomOffset;
        imago_left = imago_x + pSprite->hitboxLeftOffset;
        imago_right = imago_x + pSprite->hitboxRightOffset;

        if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, imago_top, imago_bottom, imago_left, imago_right))
        {
            gCurrentSprite.pose = 0x62;
            colliding = TRUE;
        }
    }

    return colliding;
}

// 27fa0 | a0 | Initializes a winged ripper sprite  
void WingerRipperInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.hitboxTopOffset = -0x20;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x20;
    gCurrentSprite.hitboxRightOffset = 0x20;
    gCurrentSprite.drawDistanceTopOffset = 0xC;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10,
    gCurrentSprite.pOam = winged_ripper_oam_2e0c60;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.drawOrder = 0x8;
    gCurrentSprite.pose = 0x8;
    gCurrentSprite.oamScaling = 0xC0;
    gCurrentSprite.workVariable = 0x80;
    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.frozenPaletteRowOffset = 0x4;
}

void WingerRipperGFXInit(void)
{
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.pOam = winged_ripper_oam_2e0c60;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
}

void WingerRipperMove(void)
{

}

void WingerRipperDeath(void)
{
    if (gCurrentSprite.standingOnSprite)
    {
        if (gSamusData.standingStatus == STANDING_ENEMY)
            gSamusData.standingStatus = STANDING_MIDAIR;
        gCurrentSprite.standingOnSprite = FALSE;
    }
    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition + 0x8, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
}

void imago_cocoon(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ImagoCocoonInit();
            break;
        case 0x8:
            imago_cocoon_main_loop();
            break;
        case 0x9:
            ImagoCocoonFallingBeforeBlocks();
            break;
        case 0x23:
            ImagoCocoonFallingAfterBlocks();
            break;
        case 0x25:
            ImagoCocoonUnlockPassage();
            break;
        case 0x27:
            ImagoCocoonInGroundAnim();
    }

    if (gCurrentSprite.pose > 0x24)
        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    else
        ImagoCocoonUpdatePositionAndAnim();
}

void ImagoCocoonVine(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ImagoCocoonVineInit();
            break;
        case 0x62:
            ImagoCocoonVineDeath();
        case 0x8:
            ImagoCocoonVinePlaySound();
            break;
        case 0xE:
            ImagoCocoonVineSpawnSpore();
            break;
        case 0x42:
            ImagoCocoonVineHangingDeath();
            break;
        case 0x43:
            ImagoCocoonVineHangingDeathAnim();
    }

    if (gCurrentSprite.pose == 0x67)
        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    else
        ImagoCocoonUpdatePositionAndAnim();
}

void ImagoCocoonSpore(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ImagoCocoonSporeInit();
            break;
        case 0x9:
            ImagoCocoonSporeBeforeSpawning();
            break;
        case 0x23:
            ImagoCocoonSporeSpawning();
            break;
        case 0x25:
            ImagoCocoonSporeMove();
            break;
        case 0x42:
            ImagoCocoonSporeExplodingGFXInit();
            break;
        case 0x43:
            ImagoCocoonSporeCheckExplodingAnimEnded();
            break;
        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            if (gCurrentSprite.status & SPRITE_STATUS_EXISTS && SpriteUtilCountDrops() > 0x1)
                gCurrentSprite.status = 0x0; // Anti lag measure
    }
}

void WingedRipper(void)
{
    if (gCurrentSprite.freezeTimer != 0x0)
    {
        SpriteUtilUnfreezeAnimEasy();
        if (!(WingedRipperImagoCollision()))
            return;
    }
    if (!SpriteUtilIsSpriteStunned())
    {
        switch (gCurrentSprite.pose)
        {
            case 0x0:
                WingerRipperInit();
                break;
            case 0x8:
                WingerRipperGFXInit();
            case 0x9:
                WingerRipperMove();
                break;
            default:
                WingerRipperDeath();
        }

        gCurrentSprite.arrayOffset++;
    }
}

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
        gCurrentSprite.pOam = imago_cocoon_oam_2e0d00;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x5;
    }
}

void ImagoCeilingVine(void)
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
        gCurrentSprite.pOam = imago_ceiling_vine_oam_2e0a28;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawOrder = 0x5;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozenPaletteRowOffset = 0x5;
    }
}

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
        gCurrentSprite.status = 0x0;
        EventFunction(EVENT_ACTION_SETTING, EVENT_IMAGO_TUNNEL_DISCOVERED);
    }
}

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
        gCurrentSprite.pOam = imago_cocoon_oam_2e0d00;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = 0x9;
    }

    if (gCurrentSprite.animationDurationCounter == 0x1)
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 0x1:
            case 0x4:
                SoundPlay(0x212);
        }
    }
}