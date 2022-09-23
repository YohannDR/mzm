#include "gba.h"
#include "sprites_AI/map_station.h"
#include "sprites_AI/item_banner.h"
#include "data/sprites/map_station.c"
#include "constants/connection.h"
#include "constants/game_state.h"
#include "constants/sprite.h"
#include "constants/samus.h"
#include "structs/connection.h"
#include "structs/game_state.h"
#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 1f41c | f0 | Initializes a map station sprite
 * 
 */
void MapStationInit(void)
{
    gCurrentSprite.yPosition += BLOCK_SIZE * 2;

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

    // Check set inactive
    if ((gEquipment.downloadedMapStatus >> gCurrentArea) & 0x1 || gAlarmTimer != 0x0)
    {
        gCurrentSprite.hitboxBottomOffset = -0x40;
        gCurrentSprite.pose = MAP_STATION_POSE_DO_NOTHING;

        gCurrentSprite.pOam = sMapStationOAM_Inactive;
        gCurrentSprite.currentAnimationFrame = 0x13; // Last frame
        gCurrentSprite.animationDurationCounter = 0x0;
    }
    else
    {
        gCurrentSprite.hitboxBottomOffset = 0x40;
        gCurrentSprite.pose = MAP_STATION_POSE_IDLE;

        gCurrentSprite.pOam = sMapStationOAM_Idle;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        // Spawn parts
        SpriteSpawnSecondary(SSPRITE_MAP_STATION_PART, MAP_STATION_PART_BACK_SCREEN, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_MAP_STATION_PART, MAP_STATION_PART_FRONT_SCREEN, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 1f50c | 98 | Handles a map station being idle
 * 
 */
void MapStationIdle(void)
{
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;

    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;
    spriteY = gCurrentSprite.yPosition + BLOCK_SIZE * 2;
    spriteX = gCurrentSprite.xPosition + BLOCK_SIZE + HALF_BLOCK_SIZE;

    // Detect samus
    if (!SpriteUtilCheckCrouchingOrMorphed() && samusY == spriteY - 0x1 && spriteX - BLOCK_SIZE < samusX && spriteX + BLOCK_SIZE > samusX)
    {
        // Set grabbing
        gCurrentSprite.pOam = sMapStationOAM_GrabbingSamus;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        
        gCurrentSprite.pose = MAP_STATION_POSE_GRABBING_SAMUS;
        gSamusData.xPosition = spriteX;
        
        if (gSamusData.invincibilityTimer != 0x0)
            gSamusData.invincibilityTimer = 0x0;

        // Set pose
        if (gSamusData.direction & KEY_RIGHT)
            SamusSetPose(SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA);
        else
            SamusSetPose(SPOSE_DOWNLOADING_MAP_DATA);

        SoundPlay(0x123);
    }
}

/**
 * @brief 1f5a4 | 3c | Check sif the grabbing animation ended
 * 
 */
void MapStationCheckSamusGrabbedAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set downloading
        gCurrentSprite.pOam = sMapStationOAM_Downloading;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = MAP_STATION_POSE_DOWNLOADING;
        gCurrentSprite.timer = 0x46;
        gSamusData.timer = 0x0;
    }
}

/**
 * @brief 1f5e0 | 4c | Handles Samus downloading the map
 * 
 */
void MapStationDownloading(void)
{
    if (--gCurrentSprite.timer == 0x0)
    {
        // Set retracting
        gCurrentSprite.pOam = sMapStationOAM_Retracting;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = MAP_STATION_POSE_DOWNLOADED;
        gCurrentSprite.timer = 0xA;
    }
    else if (gCurrentSprite.timer == 0xA)
        gPauseScreenFlag = PAUSE_SCREEN_MAP_DOWNLOAD; // Download
}

/**
 * @brief 1f62c | b4 | Spawns the map downloaded message
 * 
 */
void MapStationSpawnMessage(void)
{
    u8 text;

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        // Get message
        switch (gCurrentArea)
        {
            case AREA_BRINSTAR:
                text = MESSAGE_BRINSTAR_MAP_ACQUIRED;
                break;

            case AREA_KRAID:
                text = MESSAGE_KRAID_MAP_ACQUIRED;
                break;

            case AREA_NORFAIR:
                text = MESSAGE_NORFAIR_MAP_ACQUIRED;
                break;

            case AREA_RIDLEY:
                text = MESSAGE_RIDLEY_MAP_ACQUIRED;
                break;

            case AREA_CHOZODIA:
                text = MESSAGE_MOTHER_SHIP_MAP_ACQUIRED;
                break;

            default:
                text = MESSAGE_ENEMY_LOCATION_ABNORMAL;
        }

        gCurrentSprite.workVariable = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, text, 0x6,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

        gCurrentSprite.hitboxTopOffset = -0x40;
        gCurrentSprite.pose = MAP_STATION_POSE_WAIT_FOR_MESSAGE;
        gSamusData.currentAnimationFrame = 0x0;
        gSamusData.timer = 0x1;
        SoundFade(0x123, 0xA);
    }
}

/**
 * @brief 1f6e0 | 38 | Waits for the message to be disappearing
 * 
 */
void MapStationWaitForMessage(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.workVariable;
    if (gSpriteData[ramSlot].pose == ITEM_BANNER_POSE_REMOVAL_ANIMATION)
    {
        gCurrentSprite.pose = MAP_STATION_POSE_DELAY_BEFORE_RETRACTING;
        gCurrentSprite.timer = 0xA;
    }
}

/**
 * @brief 1f718 | 24 | Handles the delay before the map station retracts
 * 
 */
void MapStationDelayBeforeRetracting(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
        gCurrentSprite.pose = MAP_STATION_POSE_RETRACTING;
}

/**
 * @brief 1f73c | 34 | Initializes a map station to be retracting
 * 
 */
void MapStationRetracting(void)
{
    gCurrentSprite.pose = MAP_STATION_POSE_RETRACTED;

    gCurrentSprite.pOam = sMapStationOAM_Inactive;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    SamusSetPose(SPOSE_STANDING);
    SoundPlay(0x124);
}

/**
 * @brief 1f770 | 144 | Map station AI
 * 
 */
void MapStation(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            MapStationInit();
            break;

        case MAP_STATION_POSE_IDLE:
            MapStationIdle();
            break;
            
        case MAP_STATION_POSE_GRABBING_SAMUS:
            MapStationCheckSamusGrabbedAnimEnded();
            break;

        case MAP_STATION_POSE_DOWNLOADING:
            MapStationDownloading();
            break;

        case MAP_STATION_POSE_DOWNLOADED:
            MapStationSpawnMessage();
            break;

        case MAP_STATION_POSE_WAIT_FOR_MESSAGE:
            MapStationWaitForMessage();
            break;

        case MAP_STATION_POSE_DELAY_BEFORE_RETRACTING:
            MapStationDelayBeforeRetracting();
            break;

        case MAP_STATION_POSE_RETRACTING:
            MapStationRetracting();
    }
}

/**
 * @brief 1f884 | 12c | Map station part AI
 * 
 */
void MapStationPart(void)
{
    u8 ramSlot;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.bgPriority = 0x1;

            gCurrentSprite.drawDistanceTopOffset = 0x20;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.pose = MAP_STATION_PART_POSE_IDLE;

            if (gCurrentSprite.roomSlot == MAP_STATION_PART_BACK_SCREEN)
                gCurrentSprite.pOam = sMapStationPartOAM_BackScreenIdle;
            else
                gCurrentSprite.pOam = sMapStationPartOAM_FrontScreenIdle;

            break;

        case MAP_STATION_PART_POSE_IDLE:
            if (gSpriteData[ramSlot].pose == MAP_STATION_POSE_DOWNLOADING)
            {
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.pose = MAP_STATION_PART_POSE_DOWNLOADING;

                if (gCurrentSprite.roomSlot == MAP_STATION_PART_BACK_SCREEN)
                    gCurrentSprite.pOam = sMapStationPartOAM_BackScreenDownloading;
                else
                    gCurrentSprite.pOam = sMapStationPartOAM_FrontScreenDownloading;

            }
            break;

        case MAP_STATION_PART_POSE_DOWNLOADING:
            if (gSpriteData[ramSlot].pose == MAP_STATION_POSE_DOWNLOADED)
            {
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.pose = MAP_STATION_PART_POSE_DOWNLOADED;

                if (gCurrentSprite.roomSlot == MAP_STATION_PART_BACK_SCREEN)
                    gCurrentSprite.pOam = sMapStationPartOAM_BackScreenDownloaded;
                else
                    gCurrentSprite.pOam = sMapStationPartOAM_FrontScreenDownloaded;

            }
            break;

        case MAP_STATION_PART_POSE_DOWNLOADED:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
                gCurrentSprite.status = 0x0;
    }
}