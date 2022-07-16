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
        gCurrentSprite.draw_distance_horizontal_offset = 0x8;
        gCurrentSprite.hitboxTopOffset = -0x10;
        gCurrentSprite.hitboxBottomOffset = 0x10;
        gCurrentSprite.hitboxLeftOffset = -0x10;
        gCurrentSprite.hitboxRightOffset = 0x10;
        gCurrentSprite.animationDuratoinCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.oam_pointer = unused_sprites_oam;
        gCurrentSprite.bg_priority = 0x1;
    }
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
}