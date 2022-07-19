#include "save_platform.h"
#include "../escape.h"
#include "../sprite_util.h"
#include "../samus.h"
#include "../globals.h"

u8 SavePlatformDetectSamus(void)
{
    u8 colliding;
    i32 samusY;
    i32 samusX;
    i32 spriteY;
    i32 spriteX;

    colliding = FALSE;
    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;

    if (samusY == (spriteY - 0x41) && (spriteX - 0x40) < samusX && (spriteX + 0x40) > samusX)
        colliding = TRUE;
    return colliding;
}

void SavePlatformInit(void)
{
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.yPositionSpawn = 0x0;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x28;
    gCurrentSprite.hitboxTopOffset = -0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;
    if (gAlarmTimer != 0x0)
        gCurrentSprite.workVariable2 = 0x1;
    else
        gCurrentSprite.workVariable2 = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.timer = 0xA;

    if (gCurrentSprite.workVariable2 || EscapeDetermineTimer() != ESCAPE_NONE)
    {
        gCurrentSprite.pOam = save_platform_oam_2d4df4;
        gCurrentSprite.pose = 0x51;
    }
    else if (gIsLoadingFile)
    {
        SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_TOP, 0x0, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        gCurrentSprite.pOam = save_platform_oam_2d4dc4;
        gCurrentSprite.pose = 0x28;
        gCurrentSprite.yPositionSpawn = 0x154;
    }
    else
    {
        gCurrentSprite.pOam = save_platform_oam_2d4cfc;
        gCurrentSprite.pose = 0x9;
    }

    gCurrentSprite.arrayOffset = SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_TOP, 0x3, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition - 0x200, gCurrentSprite.xPosition, 0x0);
}

void SavePlatformSamusDetection(void)
{
    u8 timer;

    if (SavePlatformDetectSamus() << 0x18 && !SpriteUtilCheckCrouchinOrMorphed())
    {
        timer = gCurrentSprite.timer = gCurrentSprite.timer - 0x1;
        if (timer == 0x0)
        {
            gCurrentSprite.pose = 0x23;
            gCurrentSprite.pOam = save_platform_oam_2d4d34;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            SoundPlay(0x112);
        }
    }
    else
        gCurrentSprite.timer = 0xA;
}

void SavePlatformCheckOpeningAnimEnded(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.pOam = save_platform_oam_2d4d54;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

void SavePlatformSecondSamusDetection(void)
{
    u8 colliding;

    colliding = SavePlatformDetectSamus();
    if (colliding)
    {
        if (!SpriteUtilCheckCrouchinOrMorphed())
        {
            gCurrentSprite.pose = 0x42;
            gCurrentSprite.timer = 0x4;
            gSamusData.xPosition = gCurrentSprite.xPosition;
            if (gSamusData.invincibilityTimer != 0x0)
                gSamusData.invincibilityTimer = 0x0;
            SamusSetPose(SPOSE_TURNING_FROM_FACING_THE_FOREGROUND);
            gSamusData.timer = 0x1;
            gDisablePause = TRUE;
        }
    }
    else
    {
        gCurrentSprite.pose = 0x27;
        gCurrentSprite.pOam = save_platform_oam_2d4dd4;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        SoundPlay(0x113);
    }
}

void SavePlatformCheckClosingAnimEnded(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.pOam = save_platform_oam_2d4cfc;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.timer = 0xA;
    }
}

void SavePlatformReleaseSamus(void)
{
    if (gCurrentSprite.yPositionSpawn != 0x0)
        gCurrentSprite.yPositionSpawn--;
    else
    {
        gCurrentSprite.pose = 0x29;
        SamusSetPose(SPOSE_FACING_THE_FOREGROUND);
        gDisablePause = FALSE;
    }
}

void SavePlatformSamusDetectionOut(void)
{
    u8 colliding;

    colliding = SavePlatformDetectSamus();
    if (!colliding)
    {
        gCurrentSprite.pose = 0x27;
        gCurrentSprite.pOam = save_platform_oam_2d4dd4;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        SoundPlay(0x113);
    }
}

void SavePlatformSpawnSprites(void)
{
    u8 offset;

    if (gCurrentSprite.timer != 0x0)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
            gCurrentSprite.workVariable = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, 0x16, 0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
    else
    {
        offset = gCurrentSprite.workVariable;
        if (gSpriteData[offset].pose == 0x25)
        {
            if (gSpriteData[offset].workVariable == 0x1)
            {
                gCurrentSprite.pOam = save_platform_oam_2d4d8c;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.pose = 0x43;
                SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_TOP, 0x0, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
                gSpriteData[gCurrentSprite.arrayOffset].pose = 0x44;
                gSamusData.invincibilityTimer = 0x0;
                SoundPlay(0x114);
            }
            else
            {
                gCurrentSprite.pose = 0x4B;
                gCurrentSprite.timer = 0xA;
            }
        }
    }
}

void SavePlatformFlashingAnim(void)
{
    u8 offset;

    offset = gCurrentSprite.arrayOffset;
    if (gCurrentSprite.currentAnimationFrame & 0x1)
    {
        gCurrentSprite.paletteRow = 0x0;
        gSpriteData[offset].paletteRow = gCurrentSprite.paletteRow;
    }
    else
    {
        gCurrentSprite.paletteRow = 0x2;
        gSpriteData[offset].paletteRow = gCurrentSprite.paletteRow;
    }
}

void SavePlatformFlashingAnimEnd(void)
{
    gCurrentSprite.pOam = save_platform_oam_2d4dc4;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = 0x47;
    gCurrentSprite.timer = 0x3C;
    gCurrentSprite.paletteRow = 0x0;
    gSpriteData[gCurrentSprite.arrayOffset].paletteRow = 0x0;
}

void SavePlatformTextTimer(void)
{
    u8 timer;

    timer = gCurrentSprite.timer = gCurrentSprite.timer - 0x1;
    if (timer == 0x0)
    {
        gCurrentSprite.pose = 0x49;
        gCurrentSprite.workVariable = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, 0x17, 0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

void SavePlatformCheckMessageBannerOut(void)
{
    u8 offset;

    offset = gCurrentSprite.workVariable;
    if (gSpriteData[offset].pose == 0x25)
    {
        gCurrentSprite.pose = 0x4B;
        gCurrentSprite.timer = 0xA;
    }
}

void SavePlatformMessageBannerDisappearingTimer(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
        gCurrentSprite.pose = 0x28;
}

void SavePlatformTopInit(void)
{
    u8 offset;

    offset = gCurrentSprite.primarySpriteRAMSlot;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.hitboxTopOffset = -0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    switch (gCurrentSprite.roomSlot)
    {
        case 0x0:
            gCurrentSprite.drawDistanceTopOffset = 0x50;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;
            if (gSpriteData[offset].pose == 0x28)
            {
                gCurrentSprite.pOam = save_platform_top_oam_2d5024;
                gCurrentSprite.yPositionSpawn = 0x136;
                gCurrentSprite.pose = 0x25;
            }
            else
            {
                gCurrentSprite.pOam = save_platform_top_oam_2d4e84;
                gCurrentSprite.pose = 0x9;
            }
            break;

        case 0x1:
            gCurrentSprite.drawOrder = 0xC;
            gCurrentSprite.pOam = save_platform_top_oam_2d4fbc;
            gCurrentSprite.drawDistanceTopOffset = 0x50;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;
            gCurrentSprite.pose = 0x29;
            break;

        case 0x2:
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.pOam = save_platform_top_oam_2d50ec;
            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;
            gCurrentSprite.pose = 0x2B;
            gCurrentSprite.timer = 0x60;
            break;

        case 0x3:
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.drawDistanceTopOffset = 0x20;
            gCurrentSprite.drawDistanceBottomOffset = 0x40;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x20;
            gCurrentSprite.pose = 0x43;
            if (gSpriteData[offset].pose == 0x28)
                gCurrentSprite.pOam = save_platform_top_oam_2d4e44;
            else
                gCurrentSprite.pOam = save_platform_top_oam_2d4e04;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

void SavePlatformTop_Empty(void)
{
    return;
}

void SavePlatformTopExtendGFXInit(void)
{
    gCurrentSprite.pOam = save_platform_top_oam_2d4e14;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = 0x45;
}

void SavePlatformTopCheckExtendingEnded(void)
{
    if (SpriteUtilCheckEndSpriteAnim())
    {
        gCurrentSprite.pose = 0x43;
        gCurrentSprite.pOam = save_platform_top_oam_2d4e44;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

void SavePlatformTopRetractGFXInit(void)
{
    gCurrentSprite.pOam = save_platform_top_oam_2d4e54;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = 0x47;
    gSamusData.timer = 0x1;
    SoundPlay(0x115);
}

void SavePlatformTopCheckRetractingAnimEnded(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0x43;
        gCurrentSprite.pOam = save_platform_top_oam_2d4e04;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

void SavePlatformTopCheckTubeAnimSpawnEnded(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0x23;
        gCurrentSprite.pOam = save_platform_top_oam_2d5024;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.workVariable = SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_TOP, 0x1, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

void SavePlatformTopSpawnBigLight(void)
{
    u8 offset;

    offset = gCurrentSprite.workVariable;
    if (gSpriteData[offset].status == 0x0)
    {
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.yPositionSpawn = 0x78;
        SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_TOP, 0x2, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

void SavePlatformTopCheckTubeAnimEnded(void)
{
    gCurrentSprite.yPositionSpawn--;
    if (gCurrentSprite.yPositionSpawn == 0x0)
    {
        gCurrentSprite.pose = 0x27;
        gCurrentSprite.pOam = save_platform_top_oam_2d5064;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

void SavePlatformTopCheckTubeAnimDespawnEnded(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.status = 0x0;
        gSpriteData[gSpriteData[gCurrentSprite.primarySpriteRAMSlot].arrayOffset].pose = 0x46;
    }
}

void SavePlatformTopCheckTubeAroundAnimEnded(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}

void SavePlatformTopTubeDownUpAnim(void)
{
    gCurrentSprite.yPosition -= 0x4;
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gSpriteData[gCurrentSprite.primarySpriteRAMSlot].pose = 0x45;
        gCurrentSprite.status = 0x0;
    }
}

void SavePlatform(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            SavePlatformInit();
            break;
        case 0x9:
            SavePlatformSamusDetection();
            break;
        case 0x23:
            SavePlatformCheckOpeningAnimEnded();
            break;
        case 0x25:
            SavePlatformSecondSamusDetection();
            break;
        case 0x27:
            SavePlatformCheckClosingAnimEnded();
            break;
        case 0x28:
            SavePlatformReleaseSamus();
            break;
        case 0x29:
            SavePlatformSamusDetectionOut();
            break;
        case 0x42:
            SavePlatformSpawnSprites();
            break;
        case 0x43:
            SavePlatformFlashingAnim();
            break;
        case 0x45:
            SavePlatformFlashingAnimEnd();
            break;
        case 0x47:
            SavePlatformTextTimer();
            break;
        case 0x49:
            SavePlatformCheckMessageBannerOut();
            break;
        case 0x4B:
            SavePlatformMessageBannerDisappearingTimer();
    }
}

void SavePlatformTop(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            SavePlatformTopInit();
            break;
        case 0x9:
            SavePlatformTopCheckTubeAnimSpawnEnded();
            break;
        case 0x23:
            SavePlatformTopSpawnBigLight();
            break;
        case 0x25:
            SavePlatformTopCheckTubeAnimEnded();
            break;
        case 0x27:
            SavePlatformTopCheckTubeAnimDespawnEnded();
            break;
        case 0x29:
            SavePlatformTopCheckTubeAroundAnimEnded();
            break;
        case 0x2B:
            SavePlatformTopTubeDownUpAnim();
            break;
        case 0x43:
            SavePlatformTop_Empty();
            break;
        case 0x44:
            SavePlatformTopExtendGFXInit();
            break;
        case 0x45:
            SavePlatformTopCheckExtendingEnded();
            break;
        case 0x46:
            SavePlatformTopRetractGFXInit();
            break;
        case 0x47:
            SavePlatformTopCheckRetractingAnimEnded();
    }
}