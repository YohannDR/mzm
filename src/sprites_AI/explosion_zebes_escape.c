#include "explosion_zebes_escape.h"
#include "../data/sprites/enemy_drop.c"
#include "../globals.h"

void ExplosionZebesEscape(void)
{
    // https://decomp.me/scratch/anca0

    u16 yPosition;
    u16 xPosition;
    u8 particleTimer;
    u8 debrisTimer;
    u8 rngParam1;
    u8 rngParam2;
    i32 zero = 0;

    if (gCurrentSprite.pose == 0)
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
        
        gCurrentSprite.pOam = sEnemyDropOAM_LargeEnergy;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.arrayOffset = 0x0;
        gCurrentSprite.workVariable2 = 0x7;

        gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
        gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
        return;
    }
    ++zero; --zero;
    yPosition = gCurrentSprite.yPositionSpawn;
    xPosition = gBG1XPosition + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE;

    rngParam1 = gSpriteRNG;
    rngParam2 = rngParam1 & 0x3;

    particleTimer = gCurrentSprite.arrayOffset++;
    debrisTimer = gCurrentSprite.workVariable2++;

    if (gSamusData.yPosition < yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE))
        yPosition = gSamusData.yPosition + 0x64;

    if (!(particleTimer & 0xF) && rngParam1 > 0x7)
    {
        if (particleTimer & 0x10)
        {
            if (rngParam1 > 0xB)
            {
                if (rngParam1 & 0x1)
                {
                    ParticleSet(yPosition - 0xDC + rngParam1 * 8, xPosition + 0xA0 + (rngParam1 << rngParam2), PE_SPRITE_EXPLOSION_HUGE);
                    SoundPlayNotAlreadyPlaying(0xA4);
                }
                else
                {
                    ParticleSet(yPosition - 0xE6 + rngParam1 * 8, xPosition + (rngParam1 << rngParam2), PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                    SoundPlayNotAlreadyPlaying(0x276);
                }
            }
            else
            {
                if (rngParam1 & 0x1)
                {
                    ParticleSet(yPosition - 0xDC + rngParam1 * 8, xPosition - (rngParam1 << rngParam2), PE_SPRITE_EXPLOSION_HUGE);
                    SoundPlayNotAlreadyPlaying(0xA4);
                }
                else
                {
                    ParticleSet(yPosition - 0xE6 + rngParam1 * 8, xPosition - 0xA0 - (rngParam1 << rngParam2), PE_SPRITE_EXPLOSION_BIG);
                    SoundPlayNotAlreadyPlaying(0x276);
                }
            }
        }
        else
        {
            ScreenShakeStartVertical(0xA, 0x81);
            ScreenShakeStartHorizontal(0xA, 0x81);
            
            if (rngParam1 > 0xB)
            {
                if (rngParam1 & 0x1)
                {
                    ParticleSet(yPosition - 0x140 + rngParam1 * 16, xPosition + 0xC0 + (rngParam1 << rngParam2), PE_TWO_MEDIUM_DUST);
                    SoundPlayNotAlreadyPlaying(0xA5);
                }
                else
                {
                    ParticleSet(yPosition - 0x118 + rngParam1 * 16, xPosition + (rngParam1 << rngParam2), PE_MEDIUM_DUST);
                    SoundPlayNotAlreadyPlaying(0x277);
                }
            }
            else
            {
                if (rngParam1 & 0x1)
                {
                    ParticleSet(yPosition - 0x168 + rngParam1 * 16, xPosition - 0xC0 - (rngParam1 << rngParam2), PE_MEDIUM_DUST);
                    SoundPlayNotAlreadyPlaying(0x277);
                }
                else
                {
                    ParticleSet(yPosition - 0x12C + rngParam1 * 16, xPosition - (rngParam1 << rngParam2), PE_TWO_MEDIUM_DUST);
                    SoundPlayNotAlreadyPlaying(0xA5);
                }
            }
        }
    }

    yPosition = gBG1YPosition - BLOCK_SIZE;

    if (!(debrisTimer & 0x1F))
    {
        if (debrisTimer & 0x20)
        {
            SpriteDebrisInit(0x0, 0x5, yPosition, xPosition + 0x78 - rngParam1 * 16);
            SpriteDebrisInit(0x0, 0x8, yPosition, xPosition - 0x190 + rngParam1 * 8);
        }
        else
        {
            SpriteDebrisInit(0x0, 0x7, yPosition, xPosition - 0xA0 - rngParam1 * 16);
            SpriteDebrisInit(0x0, 0x5, yPosition, xPosition - 0x12C + rngParam1 * 8);
        }
    }

    if (!(particleTimer & 0xF))
    {
        if (rngParam1 > 0x7)
        {
            SpriteDebrisInit(0x0, 0x8, yPosition, xPosition - 0x1C2 + rngParam1 * 32);
            SpriteDebrisInit(0x0, 0x6, yPosition, xPosition + 0x24E - rngParam1 * 32);
        }
        else
        {
            SpriteDebrisInit(0x0, 0x6, yPosition, xPosition + 0x17C - rngParam1 * 32);
            SpriteDebrisInit(0x0, 0x8, yPosition, xPosition - 0x278 + rngParam1 * 8);
        }
    }
}