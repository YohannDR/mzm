#include "map_station.h"
#include "../sprite.h"
#include "item_banner.h"
#include "../globals.h"

void MapStationInit(void)
{
    gCurrentSprite.yPosition += 0x80;
    gCurrentSprite.drawDistanceTopOffset = 0x80;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x1C;
    gCurrentSprite.hitboxTopOffset = -0x200;
    gCurrentSprite.hitboxLeftOffset = -0x20;
    gCurrentSprite.hitboxRightOffset = 0x20;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawOrder = 0x4;
    gCurrentSprite.bgPriority = 0x1;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;

    if ((gEquipment.downloadedMapStatus >> gCurrentArea) & 0x1 || gAlarmTimer != 0x0)
    {
        gCurrentSprite.hitboxBottomOffset = -0x40;
        gCurrentSprite.pose = 0xF;
        gCurrentSprite.pOam = map_station_oam_2d3788;
        gCurrentSprite.currentAnimationFrame = 0x13;
        gCurrentSprite.animationDurationCounter = 0x0;
    }
    else
    {
        gCurrentSprite.hitboxBottomOffset = 0x40;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.pOam = map_station_oam_2d36f8;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        sprite_util_spawn_secondary(SSPRITE_MAP_STATION_SCREEN, 0x0, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        sprite_util_spawn_secondary(SSPRITE_MAP_STATION_SCREEN, 0x1, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

void MapStationSamusDetection(void)
{
    i32 samusY;
    i32 samusX;
    u16 spriteY;
    u16 spriteX;

    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;
    spriteY = (u16)(gCurrentSprite.yPosition + 0x80);
    spriteX = (u16)(gCurrentSprite.xPosition + 0x60);

    if (!SpriteUtilCheckCrouchinOrMorphed() && samusY == spriteY - 0x1 && spriteX - 0x40 < samusX && spriteX + 0x40 > samusX)
    {
        gCurrentSprite.pOam = map_station_oam_2d3708;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.pose = 0x23;
        gSamusData.xPosition = spriteX;
        if (gSamusData.invincibilityTimer != 0x0)
            gSamusData.invincibilityTimer = 0x0;

        if (gSamusData.direction & KEY_RIGHT)
            SamusSetPose(SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA);
        else
            SamusSetPose(SPOSE_DOWNLOADING_MAP_DATA);
        SoundPlay(0x123);
    }
}

void MapStationCheckSamusGrabbedAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pOam = map_station_oam_2d3758;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.timer = 0x46;
        gSamusData.timer = 0x0;
    }
}

void MapStationDownloadingAnim(void)
{
    u32 timer;

    timer = gCurrentSprite.timer - 0x1;
    gCurrentSprite.timer = timer;
    if ((u8)timer == 0x0)
    {
        gCurrentSprite.pOam = map_station_oam_2d3778;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.pose = 0x27;
        gCurrentSprite.timer = 0xA;
    }
    else if (timer == 0xA)
        gPauseScreenFlag = 0x5;
}

void MapStationSpawnMessage(void)
{
    u8 text;

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        switch (gCurrentArea)
        {
            case AREA_BRINSTAR:
                text = 0x1B;
                break;
            case AREA_KRAID:
                text = 0x1C;
                break;
            case AREA_NORFAIR:
                text = 0x1D;
                break;
            case AREA_RIDLEY:
                text = 0x1E;
                break;
            case AREA_CHOZODIA:
                text = 0x1F;
                break;
            default:
                text = 0x23;
        }

        gCurrentSprite.workVariable = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, text, 0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        gCurrentSprite.hitboxTopOffset = -0x40;
        gCurrentSprite.pose = 0x29;
        gSamusData.currentAnimationFrame = 0x0;
        gSamusData.timer = 0x1;
        SoundFade(0x123, 0xA);
    }
}

void MapStationAfterDownload(void)
{
    u8 slot;

    slot = gCurrentSprite.workVariable;
    if (gSpriteData[slot].pose == ITEM_BANNER_POSE_REMOVAL_ANIMATION)
    {
        gCurrentSprite.pose = 0x2B;
        gCurrentSprite.timer = 0xA;
    }
}

void MapStationBeforeRetraction(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
        gCurrentSprite.pose = 0x2D;
}

void MapStationRetraction(void)
{
    gCurrentSprite.pose = 0x2F;
    gCurrentSprite.pOam = map_station_oam_2d3788;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    SamusSetPose(SPOSE_STANDING);
    SoundPlay(0x124);
}

void MapStation(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            MapStationInit();
            break;
        case 0x9:
            MapStationSamusDetection();
            break;
        case 0x23:
            MapStationCheckSamusGrabbedAnimEnded();
            break;
        case 0x25:
            MapStationDownloadingAnim();
            break;
        case 0x27:
            MapStationSpawnMessage();
            break;
        case 0x29:
            MapStationAfterDownload();
            break;
        case 0x2B:
            MapStationBeforeRetraction();
            break;
        case 0x2D:
            MapStationRetraction();
    }
}

void MapStationScreen(void)
{

}