#include "explosion_zebes_escape.h"
#include "screen_shake.h"
#include "particle.h"
#include "sprite_debris.h"
#include "globals.h"

void ExplosionZebesEscape(void)
{
    u32 rng;
    u32 rng_;
    u32 xPosition;
    u32 yPosition;
    u8 arrayOffset;
    u8 variable;
    u32 yOffset;
    u32 xOffset;

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.drawDistanceTopOffset = 0x1;
        gCurrentSprite.drawDistanceBottomOffset = 0x1;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x1;
        gCurrentSprite.hitboxTopOffset = 0x0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = 0x0;
        gCurrentSprite.hitboxRightOffset = 0x0;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pOam = large_energy_oam_data_2b2750;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.arrayOffset = 0x7;
        gCurrentSprite.workVariable2 = 0x0;
        gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
        gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
        return;
    }

    yPosition = gCurrentSprite.yPositionSpawn;
    xPosition = (u16)(gBG1XPosition + 0x1E0);
    rng = gSpriteRNG;
    rng_ = rng & 0x3;
    arrayOffset = gCurrentSprite.arrayOffset;
    gCurrentSprite.arrayOffset++;
    variable = gCurrentSprite.workVariable2;
    gCurrentSprite.workVariable2++;

    yPosition = gCurrentSprite.yPositionSpawn;
    if (gSamusData.yPosition < (gCurrentSprite.yPositionSpawn - 0xA0))
        yPosition = (u16)(gSamusData.yPosition + 0x64);

    if ((arrayOffset & 0xF) == 0x0 && rng >= 0x8)
    {
        if ((arrayOffset & 0x10) != 0x0)
        {
            if (rng >= 0xC)
            {
                if ((rng & 0x1) != 0x0)
                {
                    yPosition += (rng * 0x8) - 0xE6;
                    xPosition += (rng << rng_);
                    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                    SoundPlayNotAlreadyPlaying(0x276);
                }
                else
                {
                    yPosition += (rng * 0x8) - 0xDC;
                    xPosition += (rng << rng_) + 0xA0;
                    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_HUGE);
                    SoundPlayNotAlreadyPlaying(0xA4);
                }
            }
            else
            {
                if ((rng & 0x1) != 0x0)
                {
                    yPosition += (rng * 0x8) - 0xDC;
                    xPosition -= (rng << rng_);
                    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_HUGE);
                    SoundPlayNotAlreadyPlaying(0xA4);
                }
                else
                {
                    yPosition += (rng * 0x8) - 0xE6;
                    xPosition -= (rng << rng_) + 0xA0;
                    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_BIG);
                    SoundPlayNotAlreadyPlaying(0x276);
                }
            }
        }
        else
        {
            ScreenShakeStartVertical(0xA, 0x81);
            ScreenShakeStartHorizontal(0xA, 0x81);
            if (rng >= 0xC)
            {
                if ((rng & 0x1) != 0x0)
                {
                    ParticleSet(yPosition + (rng * 0x10 - 0x140), xPosition + rng << rng_, PE_TWO_MEDIUM_DUST);
                    SoundPlayNotAlreadyPlaying(0xA5);
                }
                else
                {
                    yOffset = (rng * 0x10) - 0x118;
                    xOffset = rng << rng_;
                }
            }
            else
            {
                yOffset = (rng * 0x10) - 0x168;
                xOffset = (rng << rng_) + 0xC0;
            }

            ParticleSet(yPosition + yOffset, xPosition + xOffset, PE_MEDIUM_DUST);
            SoundPlayNotAlreadyPlaying(0x277);
        }
    }

    yPosition = (u16)(gBG1YPosition - 0x40);
    if ((variable & 0x1F) == 0x0)
    {
        if ((variable & 0x20) != 0x0)
        {
            SpriteDebrisInit(0x0, 0x5, yPosition, xPosition - (rng * 0x10) - 0x78);
            SpriteDebrisInit(0x0, 0x8, yPosition, xPosition + (rng * 0x8) - 0x190);
        }
        else
        {
            SpriteDebrisInit(0x0, 0x7, yPosition, xPosition - (rng * 0x10) - 0x78);
            SpriteDebrisInit(0x0, 0x5, yPosition, xPosition + (rng * 0x8) - 0x12C);
        }
    }

    if ((arrayOffset & 0xF) == 0x0)
    {
        if (rng >= 0x8)
        {
            SpriteDebrisInit(0x0, 0x8, yPosition, xPosition + (rng * 0x20) - 0x1C2);
            SpriteDebrisInit(0x0, 0x6, yPosition, xPosition - (rng * 0x20) - 0x24E);
        }
        else
        {
            SpriteDebrisInit(0x0, 0x6, yPosition, xPosition - (rng * 0x20) - 0x17C);
            SpriteDebrisInit(0x0, 0x8, yPosition, xPosition + (rng * 0x8) - 0x278);
        }
    }
}