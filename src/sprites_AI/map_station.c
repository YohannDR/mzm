#include "sprites_AI/map_station.h"
#include "gba.h"
#include "macros.h"
#include "sprites_AI/item_banner.h"

#include "data/sprites/map_station.h"

#include "constants/audio.h"
#include "constants/connection.h"
#include "constants/game_state.h"
#include "constants/sprite.h"
#include "constants/samus.h"
#include "constants/text.h"

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

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 8);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 8);
    gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawOrder = 4;
    gCurrentSprite.bgPriority = 1;
    gCurrentSprite.health = 1;
    gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;

    // Check set inactive
    if (HAS_AREA_MAP(gCurrentArea) || gAlarmTimer != 0)
    {
        gCurrentSprite.hitboxBottom = -BLOCK_SIZE;
        gCurrentSprite.pose = MAP_STATION_POSE_DO_NOTHING;

        gCurrentSprite.pOam = sMapStationOAM_Inactive;
        gCurrentSprite.currentAnimationFrame = 19; // Last frame
        gCurrentSprite.animationDurationCounter = 0;
    }
    else
    {
        gCurrentSprite.hitboxBottom = BLOCK_SIZE;
        gCurrentSprite.pose = MAP_STATION_POSE_IDLE;

        gCurrentSprite.pOam = sMapStationOAM_Idle;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        // Spawn parts
        SpriteSpawnSecondary(SSPRITE_MAP_STATION_PART, MAP_STATION_PART_BACK_SCREEN, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_MAP_STATION_PART, MAP_STATION_PART_FRONT_SCREEN, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
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
    if (!SpriteUtilCheckCrouchingOrMorphed() && samusY == spriteY - 1 && spriteX - BLOCK_SIZE < samusX && spriteX + BLOCK_SIZE > samusX)
    {
        // Set grabbing
        gCurrentSprite.pOam = sMapStationOAM_GrabbingSamus;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;
        
        gCurrentSprite.pose = MAP_STATION_POSE_GRABBING_SAMUS;
        gSamusData.xPosition = spriteX;
        
        if (gSamusData.invincibilityTimer != 0)
            gSamusData.invincibilityTimer = 0;

        // Set pose
        if (gSamusData.direction & KEY_RIGHT)
            SamusSetPose(SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA);
        else
            SamusSetPose(SPOSE_DOWNLOADING_MAP_DATA);

        SoundPlay(SOUND_USING_MAP_STATION);
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
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = MAP_STATION_POSE_DOWNLOADING;
        gCurrentSprite.work0 = 60 + 60 / 6;
        gSamusData.timer = 0;
    }
}

/**
 * @brief 1f5e0 | 4c | Handles Samus downloading the map
 * 
 */
void MapStationDownloading(void)
{
    if (--gCurrentSprite.work0 == 0)
    {
        // Set retracting
        gCurrentSprite.pOam = sMapStationOAM_Retracting;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = MAP_STATION_POSE_DOWNLOADED;
        gCurrentSprite.work0 = 10;
    }
    else if (gCurrentSprite.work0 == 10)
    {
        // Start pause screen download sequence
        gPauseScreenFlag = PAUSE_SCREEN_MAP_DOWNLOAD;
    }
}

/**
 * @brief 1f62c | b4 | Spawns the map downloaded message
 * 
 */
void MapStationSpawnMessage(void)
{
    u8 text;

    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 != 0)
        return;

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

    // Spawn item banner
    gCurrentSprite.work1 = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, text, 6,
        gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

    gCurrentSprite.hitboxBottom = -BLOCK_SIZE;
    gCurrentSprite.pose = MAP_STATION_POSE_WAIT_FOR_MESSAGE;
    gSamusData.currentAnimationFrame = 0;
    gSamusData.timer = 1;

    SoundFade(SOUND_USING_MAP_STATION, CONVERT_SECONDS(1.f / 6));
}

/**
 * @brief 1f6e0 | 38 | Waits for the message to be disappearing
 * 
 */
void MapStationWaitForMessage(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.work1;
    if (gSpriteData[ramSlot].pose == ITEM_BANNER_POSE_REMOVAL_ANIMATION)
    {
        // Message was removed, continue animation
        gCurrentSprite.pose = MAP_STATION_POSE_DELAY_BEFORE_RETRACTING;
        gCurrentSprite.work0 = 10;
    }
}

/**
 * @brief 1f718 | 24 | Handles the delay before the map station retracts
 * 
 */
void MapStationDelayBeforeRetracting(void)
{
    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0)
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
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    SamusSetPose(SPOSE_STANDING);
    SoundPlay(SOUND_MAP_STATION_RETRACTING);
}

/**
 * @brief 1f770 | 144 | Map station AI
 * 
 */
void MapStation(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
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

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.bgPriority = 1;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.pose = MAP_STATION_PART_POSE_IDLE;

            if (gCurrentSprite.roomSlot == MAP_STATION_PART_BACK_SCREEN)
                gCurrentSprite.pOam = sMapStationPartOAM_BackScreenIdle;
            else
                gCurrentSprite.pOam = sMapStationPartOAM_FrontScreenIdle;

            break;

        case MAP_STATION_PART_POSE_IDLE:
            if (gSpriteData[ramSlot].pose == MAP_STATION_POSE_DOWNLOADING)
            {
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
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
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = MAP_STATION_PART_POSE_DOWNLOADED;

                if (gCurrentSprite.roomSlot == MAP_STATION_PART_BACK_SCREEN)
                    gCurrentSprite.pOam = sMapStationPartOAM_BackScreenDownloaded;
                else
                    gCurrentSprite.pOam = sMapStationPartOAM_FrontScreenDownloaded;

            }
            break;

        case MAP_STATION_PART_POSE_DOWNLOADED:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
                gCurrentSprite.status = 0;
    }
}
