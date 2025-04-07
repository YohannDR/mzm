#include "sprites_AI/explosion_zebes_escape.h"

#include "data/sprites/enemy_drop.h"

#include "constants/audio.h"
#include "constants/particle.h"
#include "constants/sprite.h"

#include "structs/bg_clip.h"
#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 12a34 | 2e0 | Explosion zebes escape AI
 * 
 */
void ExplosionZebesEscape(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 particleTimer;
    u8 debrisTimer;
    u8 rngParam1;
    u8 rngParam2;
    u32 tmp;

    // Weird unused local variable, probably optimized out or its use was commented out?
    tmp = 0;
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        
        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);

        gCurrentSprite.hitboxTop = 0;
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = 0;
        gCurrentSprite.hitboxRight = 0;

        gCurrentSprite.samusCollision = SSC_NONE;
        
        // Default oam
        gCurrentSprite.pOam = sEnemyDropOAM_LargeEnergy;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = 9;
        gCurrentSprite.work3 = 0;
        gCurrentSprite.work2 = CONVERT_SECONDS(.1f) + 1 * DELTA_TIME;

        gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
        gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
        return;
    }

    yPosition = gCurrentSprite.yPositionSpawn;
    xPosition = gBg1XPosition + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE;

    rngParam1 = gSpriteRng;
    rngParam2 = rngParam1 & 3;

    // todo: APPLY_DELTA_TIME_INC won't match here
    particleTimer = gCurrentSprite.work3++;
    debrisTimer = gCurrentSprite.work2++;

    if (gSamusData.yPosition < yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE))
        yPosition = gSamusData.yPosition + BLOCK_SIZE + HALF_BLOCK_SIZE + 4;

    // CONVERT_SECONDS(.25f) + 1 * DELTA_TIME
    if (particleTimer % 16 == 0 && rngParam1 > 7)
    {
        if (particleTimer & 16)
        {
            if (rngParam1 > 11)
            {
                if (rngParam1 % 2)
                {
                    ParticleSet(yPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE + 12) + rngParam1 * 8,
                        xPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE) + (rngParam1 << rngParam2), PE_SPRITE_EXPLOSION_HUGE);
                    SoundPlayNotAlreadyPlaying(SOUND_ZEBES_ESCAPE_EXPLOSION_1);
                }
                else
                {
                    ParticleSet(yPosition - (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE + 6) + rngParam1 * 8,
                        xPosition + (rngParam1 << rngParam2), PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                    SoundPlayNotAlreadyPlaying(SOUND_ZEBES_ESCAPE_EXPLOSION_3);
                }
            }
            else
            {
                if (rngParam1 % 2)
                {
                    ParticleSet(yPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE + 12) + rngParam1 * 8,
                        xPosition - (rngParam1 << rngParam2), PE_SPRITE_EXPLOSION_HUGE);
                    SoundPlayNotAlreadyPlaying(SOUND_ZEBES_ESCAPE_EXPLOSION_1);
                }
                else
                {
                    ParticleSet(yPosition - (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE + 6) + rngParam1 * 8,
                        xPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE) - (rngParam1 << rngParam2), PE_SPRITE_EXPLOSION_BIG);
                    SoundPlayNotAlreadyPlaying(SOUND_ZEBES_ESCAPE_EXPLOSION_3);
                }
            }
        }
        else
        {
            ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
            ScreenShakeStartHorizontal(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
            
            if (rngParam1 > 11)
            {
                if (rngParam1 % 2)
                {
                    ParticleSet(yPosition - (BLOCK_SIZE * 5) + rngParam1 * 16,
                        xPosition + (BLOCK_SIZE * 3) + (rngParam1 << rngParam2), PE_TWO_MEDIUM_DUST);
                    SoundPlayNotAlreadyPlaying(SOUND_ZEBES_ESCAPE_EXPLOSION_2);
                }
                else
                {
                    ParticleSet(yPosition - (BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE + 8) + rngParam1 * 16,
                        xPosition + (rngParam1 << rngParam2), PE_MEDIUM_DUST);
                    SoundPlayNotAlreadyPlaying(SOUND_ZEBES_ESCAPE_EXPLOSION_4);
                }
            }
            else
            {
                if (rngParam1 % 2)
                {
                    ParticleSet(yPosition - (BLOCK_SIZE * 5 + HALF_BLOCK_SIZE + 8) + rngParam1 * 16,
                        xPosition - (BLOCK_SIZE * 3) - (rngParam1 << rngParam2), PE_MEDIUM_DUST);
                    SoundPlayNotAlreadyPlaying(SOUND_ZEBES_ESCAPE_EXPLOSION_4);
                }
                else
                {
                    ParticleSet(yPosition - (BLOCK_SIZE * 4 + HALF_BLOCK_SIZE + 12) + rngParam1 * 16,
                        xPosition - (rngParam1 << rngParam2), PE_TWO_MEDIUM_DUST);
                    SoundPlayNotAlreadyPlaying(SOUND_ZEBES_ESCAPE_EXPLOSION_2);
                }
            }
        }
    }

    yPosition = gBg1YPosition - BLOCK_SIZE;

    // CONVERT_SECONDS(.5f) + 2 * DELTA_TIME
    if (debrisTimer % 32 == 0)
    {
        if (debrisTimer & 32)
        {
            tmp = xPosition;
            SpriteDebrisInit(0, 5, yPosition, xPosition + (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE + 8) - rngParam1 * 16);
            SpriteDebrisInit(0, 8, yPosition, xPosition - (BLOCK_SIZE * 6 + QUARTER_BLOCK_SIZE) + rngParam1 * 8);
        }
        else
        {
            SpriteDebrisInit(0, 7, yPosition, xPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE) - rngParam1 * 16);
            SpriteDebrisInit(0, 5, yPosition, xPosition - (BLOCK_SIZE * 4 + HALF_BLOCK_SIZE + 12) + rngParam1 * 8);
        }
    }

    // CONVERT_SECONDS(.25f) + 1 * DELTA_TIME
    if (particleTimer % 16 == 0)
    {
        if (rngParam1 > 7)
        {
            SpriteDebrisInit(0, 8, yPosition, xPosition - (BLOCK_SIZE * 7 + 2) + rngParam1 * 32);
            SpriteDebrisInit(0, 6, yPosition, xPosition + (BLOCK_SIZE * 9 + QUARTER_BLOCK_SIZE - 2) - rngParam1 * 32);
        }
        else
        {
            SpriteDebrisInit(0, 6, yPosition, xPosition + (BLOCK_SIZE * 6 - 4) - rngParam1 * 32);
            SpriteDebrisInit(0, 8, yPosition, xPosition - (BLOCK_SIZE * 10 - QUARTER_BLOCK_SIZE + 8) + rngParam1 * 8);
        }
    }
}
