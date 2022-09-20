#include "area_banner.h"
#include "../../data/data.h"
#include "../data/sprites/area_banner.c"
#include "../globals.h"

/**
 * @brief 3c704 | a4 | Initializes an area banner sprite
 * 
 */
void AreaBannerInit(void)
{
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;

    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10,
    gCurrentSprite.drawDistanceHorizontalOffset = 0x80;

    gCurrentSprite.hitboxTopOffset = -0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = AREA_BANNER_POSE_SPAWN;

    if (gCurrentSprite.roomSlot < LT_MOTHERSHIP)
    {
        // Area name, spawn at bottom
        gCurrentSprite.pOam = sAreaBannerOAM_SpawnBottom;
        gCurrentSprite.workVariable = TRUE;
        gCurrentSprite.yPosition = 0x98;
        gCurrentSprite.xPosition = 0x78;
    }
    else if ((gCurrentSprite.roomSlot == LT_SAVE_ROOM || gCurrentSprite.roomSlot == LT_MAP_ROOM) && gAlarmTimer != 0x0)
        gCurrentSprite.status = 0x0; // Don't spawn save/map if alarm is active
    else
    {
        // Spawn in middle
        gCurrentSprite.pOam = sAreaBannerOAM_SpawnMiddle;
        gCurrentSprite.workVariable = FALSE;
        gCurrentSprite.yPosition = 0x36;
        gCurrentSprite.xPosition = 0x78;
    }
}

/**
 * @brief 3c7a8 | 20 | Handles the area banner spawning
 * 
 */
void AreaBannerSpawn(void)
{
    gCurrentSprite.animationDurationCounter--;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN; // Remove not drawn
    gCurrentSprite.pose = AREA_BANNER_POSE_SCROLLING_UP;
}

/**
 * @brief 3c7c8 | 60 | Handles the area banner scrolling up, determines the static behavior
 * 
 */
void AreaBannerScrollingUp(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = AREA_BANNER_POSE_STATIC;

        // Set OAM and timer for how long the message stays
        if (gCurrentSprite.workVariable) // Position flag, 1 = on bottom, 0 = in middle
        {
            gCurrentSprite.pOam = sAreaBannerOAM_StaticBottom;
            gCurrentSprite.timer = 0x78;
        }
        else
        {
            gCurrentSprite.pOam = sAreaBannerOAM_StaticMiddle;
            if (gCurrentSprite.roomSlot == LT_SAVE_ROOM || gCurrentSprite.roomSlot == LT_MAP_ROOM)
                gCurrentSprite.timer = 0x32;
            else
                gCurrentSprite.timer = 0x5A;
        }
    }
}

/**
 * @brief 3c828 | 44 | Handles the area banner being static
 * 
 */
void AreaBannerStatic(void)
{
    gCurrentSprite.timer--; // Timer for how long it stays
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = AREA_BANNER_POSE_REMOVING;

        // Set OAM
        if (gCurrentSprite.workVariable)
            gCurrentSprite.pOam = sAreaBannerOAM_RemovingBottom;
        else
            gCurrentSprite.pOam = sAreaBannerOAM_RemovingMiddle;
    }
}

/**
 * @brief 3c86c | 18 | Checks if the removing anim ended
 * 
 */
void AreaBannerCheckRemovingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0; // Kill sprite
}

/**
 * @brief 3c884 | e0 | Area banner AI
 * 
 */
void AreaBanner(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            AreaBannerInit();
            break;

        case AREA_BANNER_POSE_SPAWN:
            AreaBannerSpawn();
            break;
        
        case AREA_BANNER_POSE_SCROLLING_UP:
            AreaBannerScrollingUp();
            break;

        case AREA_BANNER_POSE_STATIC:
            AreaBannerStatic();
            break;

        case AREA_BANNER_POSE_REMOVING:
            AreaBannerCheckRemovingAnimEnded();
            break;
    }
}