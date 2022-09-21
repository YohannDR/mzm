#include "sprites_AI/deorem.h"
#include "data/data.h"
#include "data/sprite_data.c"
#include "globals.h"

void DeoremChangeLeftCCAA(u8 caa)
{

}

void DeoremChangeRightCCAA(u8 caa)
{

}

void DeoremMoveDiagonaly(u8 velocity, u16 dstPosition)
{

}

void DeoremRandomSpriteDebris(u8 rng)
{

}

/**
 * 20f80 | a8 | 
 * Handles the spawning of sprite debris when Deorem appears
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param timer Timer (determines which set to spawn)
 */
void DeoremSpriteDebrisSpawn(u16 yPosition, u16 xPosition, u8 timer)
{
    switch (timer)
    {
        case 0x1:
            SpriteDebrisInit(0x0, 0x11, yPosition - 0x40, xPosition);
            SpriteDebrisInit(0x0, 0x12, yPosition - 0x10, xPosition + 0x3E);
            break;
        case 0x3:
            SpriteDebrisInit(0x0, 0x13, yPosition + 0x28, xPosition - 0x5C);
            SpriteDebrisInit(0x0, 0x4, yPosition, xPosition + 0x1E);
            break;
        case 0x7:
            SpriteDebrisInit(0x0, 0x11, yPosition + 0x14, xPosition - 0x14);
            SpriteDebrisInit(0x0, 0x12, yPosition - 0x14, xPosition + 0x6E);
            break;
        case 0xC:
            SpriteDebrisInit(0x0, 0x13, yPosition + 0x28, xPosition + 0x1E);
            SpriteDebrisInit(0x0, 0x4, yPosition - 0x10, xPosition - 0x64);
    }
}

u8 DeoremCheckLeaving(u8 ramSlot)
{

}

/**
 * 21094 | 40 |
 * Spawns and loads a charge beam sprite at the given position
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 */
void DeoremSpawnChargeBeam(u16 yPosition, u16 xPosition)
{
    u8 gfxSlot;

    gfxSlot = gCurrentSprite.spritesetGFXSlot;
    SpriteSpawnPrimary(PSPRITE_CHARGE_BEAM, 0x0, gfxSlot, yPosition, xPosition, 0x0);
    SpriteLoadGFX(PSPRITE_CHARGE_BEAM, gfxSlot);
    SpriteLoadPAL(PSPRITE_CHARGE_BEAM, gfxSlot, 0x1);
}

/**
 * 210d4 | 3c | Sets the timer for how long the eye stays open depending on the gDifficulty
 * 
 */
void DeoremSetEyeOpeningTimer(void)
{
    if (gDifficulty == 0x0)
        gCurrentSprite.timer = 0x78; // Easy
    else if (gDifficulty == 0x2)
        gCurrentSprite.timer = 0x28; // Hard
    else
        gCurrentSprite.timer = 0x50; // Normal
}

/**
 * 21110 | 2c | Calls the charge beam spawn handler, used when Deorem is already dead but the charge beam hasn't been picked up
 * 
 */
void DeoremCallSpawnChargeBeam(void)
{
    DeoremSpawnChargeBeam(gCurrentSprite.yPosition + 0xB0, gCurrentSprite.xPosition + 0x1A0);
    gCurrentSprite.status = 0x0;
}

void DeoremInit(void)
{

}

void DeoremSpawnGoingDown(void)
{

}

void DeoremSpawnGoingDownAnim(void)
{

}

/**
 * 21510 | d0 | Called when imago goes up when spawning, spawns 6 Deorem segments
 * 
 */
void DeoremSpawnGoingUp(void)
{
    u16 yPosition;
    u8 gfxSlot;
    u8 ramSlot;
    u16 xPosition;

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = 0x23;
        gCurrentSprite.timer = 0x32;
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn + 0x31C;
        gfxSlot = gCurrentSprite.spritesetGFXSlot;
        ramSlot = gCurrentSprite.primarySpriteRAMSlot;
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xB, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xA, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0x9, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0x8, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0x7, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0x6, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        ScreenShakeStartVertical(0x28, 0x81);
        SoundPlay(0x193);
    }
}

void DeoremSpawnGoingUpAnim(void)
{

}

/**
 * 216c0 | 117 | Spawns the hidden part of the body (above the head) and the eye
 * 
 */
void DeoremSpawnHeadBody(void)
{
    u8 gfxSlot;
    u8 ramSlot;
    u16 yPosition;
    u16 xPosition;
    u8 segment_E_slot;
    u8 segment_D_slot;
    u8 segment_C_slot;
    u8 eye_slot;

    if ((gCurrentSprite.timer & 0x1F) == 0x0)
        DeoremRandomSpriteDebris(gCurrentSprite.timer);

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.timer = 0xB;
        gfxSlot = gCurrentSprite.spritesetGFXSlot;
        ramSlot = gCurrentSprite.primarySpriteRAMSlot;
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;
        segment_E_slot = SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xE, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        segment_D_slot = SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xD, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        segment_C_slot = SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xC, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        gSpriteData[segment_D_slot].timer = segment_C_slot;
        gSpriteData[segment_E_slot].timer = segment_D_slot;
        eye_slot = SpriteSpawnSecondary(SSPRITE_DEOREM_EYE, 0x0, gfxSlot, ramSlot, yPosition - 0x1C, xPosition - 0x4, 0x0);
        if (eye_slot == 0xFF)
            gCurrentSprite.status = 0x0;
        else
            gCurrentSprite.arrayOffset = eye_slot;
    }
}

void DeoremAfterSpawn(void)
{

}

void DeoremMainLoop(void)
{

}

void DeoremRetracting(void)
{

}

void DeoremThrowingThorns(void)
{

}

void DeoremAfterThorns(void)
{

}

void DeoremDying(void)
{

}

void DeoremDyingGoingDown(void)
{

}

/**
 * 21e74 | 38 | Calls Sprite Death
 * 
 */
void DeoremDeath(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition + 0x40, FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
}

void DeoremCheckLeavingCeilingAnimEnded(void)
{

}

void DeoremLeaving(void)
{

}

void DeoremLeavingAnim(void)
{

}

void DeoremLeavingInGroundDebris(void)
{

}

void DeoremSegmentInit(void)
{

}

void DeoremSegmentSpawnGoingDown(void)
{

}

void DeoremSegmentSpawnGoingDownAfter(void)
{

}

void DeoremSegmentSpawnGoingUp(void)
{

}

void DeoremSegmentSpawnGoingUpAfter(void)
{

}

void DeoremSegmentRightIdleAnim(void)
{

}

void DeoremSegmentLeftIdleAnim(void)
{

}

void DeoremSegmentGoingDown(void)
{

}

void DeoremSegmentGoingUp(void)
{

}

void DeoremSegmentAboveHeadMovement(void)
{

}

void DeoremSegmentLeftLeaving(void)
{

}

void DeoremSegmentLeftLeavingEnd(void)
{

}

void DeoremSegmentMiddleLeavingEnd(void)
{

}

void DeoremSegmentMiddleLeaving(void)
{

}

void DeoremSegmentRighLeaving(void)
{

}

void DeoremSegmentRighLeavingEnd(void)
{

}

void DeoremSegmentSetTimerDying(void)
{

}

void DeoremSegmentDying(void)
{

}

void DeoremEyeInit(void)
{

}

void DeoremEyeSetPose9(void)
{
    gCurrentSprite.pose = 0x9;
}

void DeoremEyeMove(void)
{

}

void DeoremEyeMainLoop(void)
{

}

void DeoremEyeDyingGFXInit(void)
{

}

void DeoremEyeDyingSpinningAnim(void)
{

}

void DeoremEyeDyingMovingAnim(void)
{

}

void DeoremThornInit(void)
{

}

void DeoremThornSpawning(void)
{

}

void DeoremThornMovement(void)
{

}

/**
 * 23520 | 238 | Deorem AI
 * 
 */
void Deorem(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            DeoremInit();
            break;
        case 0x8:
            DeoremSpawnGoingDown();
            break;
        case 0x9:
            DeoremSpawnGoingDownAnim();
            break;
        case 0x22:
            DeoremSpawnGoingUp();
            break;
        case 0x23:
            DeoremSpawnGoingUpAnim();
            break;
        case 0x24:
            DeoremSpawnHeadBody();
            break;
        case 0x25:
            DeoremAfterSpawn();
            break;
        case 0x26:
            DeoremMainLoop();
            break;
        case 0x27:
            DeoremRetracting();
            break;
        case 0x28:
        case 0x29:
            DeoremThrowingThorns();
            break;
        case 0xA:
            DeoremAfterThorns();
            break;
        case 0x62:
            DeoremDying();
            break;
        case 0x67:
            DeoremDyingGoingDown();
            break;
        case 0x68:
            DeoremDeath();
            break;
        case 0x42:
            DeoremCheckLeavingCeilingAnimEnded();
            break;
        case 0x43:
            DeoremLeaving();
            break;
        case 0x44:
            DeoremLeavingAnim();
            break;
        case 0x45:
            DeoremLeavingInGroundDebris();
            break;
        case 0x60:
            DeoremCallSpawnChargeBeam();
    }
}

void DeoremSegment(void)
{

}

/**
 * 23a20 | e0 | Deorem Eye
 * 
 */
void DeoremEye(void)
{
    u8 ramSlot;
    u8 isft;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.pose < 0x68)
    {
        ramSlot = gCurrentSprite.primarySpriteRAMSlot;
        isft = gCurrentSprite.invicibilityStunFlashTimer & 0x7F;
        if (isft && gSpriteData[ramSlot].pose < 0x62)
        {
            gSpriteData[ramSlot].invicibilityStunFlashTimer = gCurrentSprite.invicibilityStunFlashTimer;
            if (isft == 0x10)
            {
                // gSpriteData[ramSlot].pOam = deorem_oam_2d7a84;
                gSpriteData[ramSlot].animationDurationCounter = 0x0;
                gSpriteData[ramSlot].currentAnimationFrame = 0x0;
                gSpriteData[ramSlot].hitboxBottomOffset = 0x40;
                if (gCurrentSprite.health < 0x15)
                    gSpriteData[ramSlot].absolutePaletteRow = 0x2;
                gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                SoundPlay(0x19A);
            }
        }
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            DeoremEyeInit();
            break;
        case 0x8:
            DeoremEyeSetPose9();
            break;
        case 0x9:
            DeoremEyeMainLoop();
            break;
        case 0x62:
            DeoremEyeDyingGFXInit();
        case 0x67:
            DeoremEyeDyingSpinningAnim();
            break;
        case 0x68:
            DeoremEyeDyingMovingAnim();
    }
}

/**
 * 23b00 | 4c | Deorem Thorn AI
 * 
 */
void DeoremThorn(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            DeoremThornInit();
        case 0x9:
            DeoremThornSpawning();
            break;
        case 0x23:
            DeoremThornMovement();
            break;
        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
    }
}