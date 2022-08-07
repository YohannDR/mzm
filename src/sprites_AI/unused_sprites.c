#include "unused_sprites.h"
#include "../globals.h"

const u16 sUnusedSpritesOAM_Idle_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, 0x3151
};

const u16 sUnusedSpritesOAM_Idle_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, 0x3150
};

const struct FrameData sUnusedSpritesOAM_Idle[3] = {
    sUnusedSpritesOAM_Idle_Frame0,
    0x1E,
    sUnusedSpritesOAM_Idle_Frame1,
    0x1E,
    NULL,
    0x0
};

const struct FrameData sUnusedSpritesOAM_Unused[3] = {
    sUnusedSpritesOAM_Idle_Frame0,
    0x1E,
    NULL,
    0x0
};

const u32 sUnusedSpritesGFX[6];
const u16 sUnusedSpritesPAL[16];

/**
 * @brief 13024 | 5c | Unused sprites AI
 * 
 */
void UnusedSprites(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.pose++;
        
        gCurrentSprite.drawDistanceTopOffset = 0x8;
        gCurrentSprite.drawDistanceBottomOffset = 0x8;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
        
        gCurrentSprite.hitboxTopOffset = -0x10;
        gCurrentSprite.hitboxBottomOffset = 0x10;
        gCurrentSprite.hitboxLeftOffset = -0x10;
        gCurrentSprite.hitboxRightOffset = 0x10;
        
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pOam = sUnusedSpritesOAM_Idle;
        
        gCurrentSprite.bgPriority = 0x1;
    }
}