#include "sprites_AI/area_banner.h"
#include "macros.h"

#include "data/sprites/area_banner.h"

#include "constants/sprite.h"

#include "structs/sprite.h"

#define AREA_BANNER_POSE_SPAWNING_INIT 0x8
#define AREA_BANNER_POSE_SPAWNING 0x9
#define AREA_BANNER_POSE_STATIC 0x23
#define AREA_BANNER_POSE_LEAVING 0x25

/**
 * @brief 3c704 | a4 | Initializes an area banner sprite
 * 
 */
void AreaBannerInit(void)
{
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 8);

    gCurrentSprite.hitboxTop = -PIXEL_SIZE;
    gCurrentSprite.hitboxBottom = PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
    gCurrentSprite.hitboxRight = PIXEL_SIZE;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = AREA_BANNER_POSE_SPAWNING_INIT;

    if (gCurrentSprite.roomSlot < LT_MOTHERSHIP)
    {
        // Area name, spawn at bottom
        gCurrentSprite.pOam = sAreaBannerOam_SpawnBottom;
        gCurrentSprite.work1 = TRUE;
        gCurrentSprite.yPosition = SCREEN_SIZE_Y - SUB_PIXEL_TO_PIXEL(PIXEL_SIZE * 8);
        gCurrentSprite.xPosition = SCREEN_SIZE_X / 2;
    }
    else if ((gCurrentSprite.roomSlot == LT_SAVE_ROOM || gCurrentSprite.roomSlot == LT_MAP_ROOM) && gAlarmTimer != 0)
    {
        // Don't spawn save/map if alarm is active
        gCurrentSprite.status = 0;
    }
    else
    {
        // Spawn in middle
        gCurrentSprite.pOam = sAreaBannerOam_SpawnMiddle;
        gCurrentSprite.work1 = FALSE;
        gCurrentSprite.yPosition = SCREEN_SIZE_Y / 3 + SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
        gCurrentSprite.xPosition = SCREEN_SIZE_X / 2;
    }
}

/**
 * @brief 3c7a8 | 20 | Handles the area banner spawning
 * 
 */
void AreaBannerSpawningInit(void)
{
    gCurrentSprite.animationDurationCounter--;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN; // Remove not drawn
    gCurrentSprite.pose = AREA_BANNER_POSE_SPAWNING;
}

/**
 * @brief 3c7c8 | 60 | Handles the area banner scrolling up, determines the static behavior
 * 
 */
void AreaBannerSpawning(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = AREA_BANNER_POSE_STATIC;

        // Set oam and timer for how long the message stays
        if (gCurrentSprite.work1) // Position flag, 1 = on bottom, 0 = in middle
        {
            gCurrentSprite.pOam = sAreaBannerOam_StaticBottom;
            gCurrentSprite.work0 = CONVERT_SECONDS(2.f);
        }
        else
        {
            gCurrentSprite.pOam = sAreaBannerOam_StaticMiddle;

            if (gCurrentSprite.roomSlot == LT_SAVE_ROOM || gCurrentSprite.roomSlot == LT_MAP_ROOM)
            {
                // Save and map room banners stay less time
                gCurrentSprite.work0 = CONVERT_SECONDS(0.84f);
            }
            else
            {
                gCurrentSprite.work0 = CONVERT_SECONDS(1.5f);
            }
        }
    }
}

/**
 * @brief 3c828 | 44 | Handles the area banner being static
 * 
 */
void AreaBannerStatic(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);

    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = AREA_BANNER_POSE_LEAVING;

        // Set OAM
        if (gCurrentSprite.work1)
            gCurrentSprite.pOam = sAreaBannerOam_RemovingBottom;
        else
            gCurrentSprite.pOam = sAreaBannerOam_RemovingMiddle;
    }
}

/**
 * @brief 3c86c | 18 | Checks if the removing anim ended
 * 
 */
void AreaBannerLeaving(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0; // Kill sprite
}

/**
 * @brief 3c884 | e0 | Area banner AI
 * 
 */
void AreaBanner(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            AreaBannerInit();
            break;

        case AREA_BANNER_POSE_SPAWNING_INIT:
            AreaBannerSpawningInit();
            break;
        
        case AREA_BANNER_POSE_SPAWNING:
            AreaBannerSpawning();
            break;

        case AREA_BANNER_POSE_STATIC:
            AreaBannerStatic();
            break;

        case AREA_BANNER_POSE_LEAVING:
            AreaBannerLeaving();
            break;
    }
}
