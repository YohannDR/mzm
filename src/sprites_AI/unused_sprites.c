#include "unused_sprites.h"
#include "../../data/data.h"
#include "../globals.h"

void UnusedSprites(void)
{
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.pose = 0x1;
        gCurrentSprite.drawDistanceTopOffset = 0x8;
        gCurrentSprite.drawDistanceBottomOffset = 0x8;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
        gCurrentSprite.hitboxTopOffset = -0x10;
        gCurrentSprite.hitboxBottomOffset = 0x10;
        gCurrentSprite.hitboxLeftOffset = -0x10;
        gCurrentSprite.hitboxRightOffset = 0x10;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pOam = unused_sprites_oam;
        gCurrentSprite.bgPriority = 0x1;
    }
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
}