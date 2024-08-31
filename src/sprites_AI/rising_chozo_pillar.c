#include "sprites_AI/rising_chozo_pillar.h"
#include "macros.h"

#include "data/sprites/rising_chozo_pillar.h"
#include "data/sprites/enemy_drop.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/sprite.h"

#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/sprite.h"

/**
 * 4854c | a8 | Spawns random sprite debris depending on the parameters
 * 
 * @param yPosition Y Position
 * @param xPosition X Position 
 * @param rng Set of debris to use
 */
void RisingChozoPillarRandomSpriteDebris(u16 yPosition, u16 xPosition, u8 rng)
{
    switch (rng)
    {
        case 1:
            SpriteDebrisInit(0, 17, yPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE * 2), xPosition);
            SpriteDebrisInit(0, 18, yPosition - QUARTER_BLOCK_SIZE, xPosition + (BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2));
            break;

        case 3:
            SpriteDebrisInit(0, 19, yPosition - 0x14, xPosition - 0x5C);
            SpriteDebrisInit(0, 4, yPosition - 0xA, xPosition + 0x1E);
            break;

        case 7:
            SpriteDebrisInit(0, 17, yPosition - 0x8, xPosition - 0x32);
            SpriteDebrisInit(0, 18, yPosition - 0x34, xPosition + 0x78);
            break;

        case 12:
            SpriteDebrisInit(0, 19, yPosition - HALF_BLOCK_SIZE, xPosition + 0x1E);
            SpriteDebrisInit(0, 4, yPosition - PIXEL_SIZE, xPosition - 0x6E);
    }
}

/**
 * 485f4 | ac | Spawns random particles depending on the parameters
 * 
 * @param yPosition Y Position
 * @param xPosition X Position 
 * @param rng Set of particles to use
 */
void RisingChozoPillarRandomParticles(u16 yPosition, u16 xPosition, u8 rng)
{
    switch (rng)
    {
        case 1:
            ParticleSet(yPosition, xPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE * 2), PE_TWO_MEDIUM_DUST);
            break;

        case 16:
            ParticleSet(yPosition, xPosition + (BLOCK_SIZE - PIXEL_SIZE), PE_SECOND_MEDIUM_DUST);
            break;

        case 33:
            ParticleSet(yPosition, xPosition - (BLOCK_SIZE - PIXEL_SIZE), PE_SECOND_MEDIUM_DUST);
            break;

        case 50:
            ParticleSet(yPosition, xPosition + (QUARTER_BLOCK_SIZE + PIXEL_SIZE), PE_MEDIUM_DUST);
            break;

        case 66:
            ParticleSet(yPosition, xPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE), PE_TWO_MEDIUM_DUST);
            break;

        case 84:
            ParticleSet(yPosition, xPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE), PE_SECOND_MEDIUM_DUST);
            ParticleSet(yPosition, xPosition, PE_SECOND_TWO_MEDIUM_DUST);
            break;

        case 100:
            ParticleSet(yPosition, xPosition - (QUARTER_BLOCK_SIZE + PIXEL_SIZE), PE_SECOND_TWO_MEDIUM_DUST);
            break;

        case 110:
            ParticleSet(yPosition, xPosition + (HALF_BLOCK_SIZE + PIXEL_SIZE * 2), PE_MEDIUM_DUST);
    }
}

/**
 * @brief 486a0 | e4 | Spawns three platforms and sets the collision for them
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param caa Clipdata Affecting Action
 */
void RisingChozoPillarSpawnThreePlatforms(u16 yPosition, u16 xPosition, u8 caa)
{
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 3), xPosition + (BLOCK_SIZE * 3));
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 3), xPosition + (BLOCK_SIZE * 4));
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 11), xPosition + (BLOCK_SIZE * 3));

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 11), xPosition + (BLOCK_SIZE * 4));
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 19), xPosition + (BLOCK_SIZE * 3));

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 19), xPosition + (BLOCK_SIZE * 4));

    // Spawn platforms
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x1, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, yPosition - (BLOCK_SIZE * 3),  xPosition + (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), 0);

    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x1, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, yPosition - (BLOCK_SIZE * 11),  xPosition + (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), 0);

    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x1, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, yPosition - (BLOCK_SIZE * 19), xPosition + (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), 0);
}

/**
 * 48784 | b8 | 
 * Spawns two platforms and sets the collision for them
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param caa Clipdata Affecting Action
 */
void RisingChozoPillarSpawnTwoPlatforms(u16 yPosition, u16 xPosition, u8 caa)
{
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 7, xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 7, xPosition + BLOCK_SIZE);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 24, xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 24, xPosition + BLOCK_SIZE);

    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x0, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, yPosition - BLOCK_SIZE * 7, xPosition + HALF_BLOCK_SIZE, 0);

    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x0, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, yPosition - BLOCK_SIZE * 24, xPosition + HALF_BLOCK_SIZE, 0);
}

/**
 * 4883c | 68 | 
 * Spawns one platform and sets the collision for it
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param caa Clipdata Affecting Action
 */
void RisingChozoPillarSpawnOnePlatform(u16 yPosition, u16 xPosition, u8 caa)
{
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 15), xPosition + (BLOCK_SIZE * 6));

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 15), xPosition + (BLOCK_SIZE * 7));

    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x0, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, yPosition - (BLOCK_SIZE * 15), xPosition + (BLOCK_SIZE * 6 + HALF_BLOCK_SIZE), 0);
}

/**
 * 488a4 | 248 | Rising Chozo Pillar AI
 * 
 */
void RisingChozoPillar(void)
{
    u8 caa;
    u16 yPosition;
    u16 xPosition;
    u16 debrisY;
    u16 debrisX;

    caa = CAA_MAKE_SOLID_GRIPPABLE;
    yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPosition;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED))
            {
                // Already extended, spawn all platforms
                RisingChozoPillarSpawnThreePlatforms(yPosition, xPosition, caa);
                RisingChozoPillarSpawnTwoPlatforms(yPosition, xPosition, caa);
                RisingChozoPillarSpawnOnePlatform(yPosition, xPosition, caa);
                gCurrentSprite.status = 0;
                break;
            }

            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.pOam = sEnemyDropOAM_LargeEnergy;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.pose = RISING_CHOZO_PILLAR_POSE_WAIT_FOR_POWER_GRIP;
            break;

        case RISING_CHOZO_PILLAR_POSE_WAIT_FOR_POWER_GRIP:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_POWER_GRIP_OBTAINED))
            {
                gCurrentSprite.pose = RISING_CHOZO_PILLAR_POSE_EXTENDING;
                gCurrentSprite.scaling = 704;
                SoundPlay(SOUND_RISING_CHOZO_PILLAR_RISING);
            }
            break;

        case RISING_CHOZO_PILLAR_POSE_EXTENDING:
            if (MOD_AND(gCurrentSprite.scaling, 32) == 0)
                ScreenShakeStartVertical(30, 0x80 | 1);

            gCurrentSprite.scaling--;
            if (gCurrentSprite.scaling != 0)
            {
                gBg2Movement.yOffset += 2;
            }
            else
            {
                gCurrentSprite.pose = RISING_CHOZO_PILLAR_POSE_SPAWN_3_PLATFORMS;
                SoundFade(SOUND_RISING_CHOZO_PILLAR_RISING, CONVERT_SECONDS(1.f / 6));
            }

            debrisY = yPosition + HALF_BLOCK_SIZE;
            debrisX = xPosition + BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            RisingChozoPillarRandomSpriteDebris(debrisY, debrisX, MOD_AND(gCurrentSprite.scaling, 16));
            RisingChozoPillarRandomParticles(debrisY, debrisX, MOD_AND(gCurrentSprite.scaling, 128));
            break;

        case RISING_CHOZO_PILLAR_POSE_SPAWN_3_PLATFORMS:
            gCurrentSprite.pose = RISING_CHOZO_PILLAR_POSE_SPAWN_2_PLATFORMS;
            RisingChozoPillarSpawnThreePlatforms(yPosition, xPosition, caa);
            break;

        case RISING_CHOZO_PILLAR_POSE_SPAWN_2_PLATFORMS:
            gCurrentSprite.pose = RISING_CHOZO_PILLAR_POSE_SPAWN_1_PLATFORMS;
            RisingChozoPillarSpawnTwoPlatforms(yPosition, xPosition, caa);
            break;

        case RISING_CHOZO_PILLAR_POSE_SPAWN_1_PLATFORMS:
            gCurrentSprite.pose = RISING_CHOZO_PILLAR_POSE_EXTENDED;
            RisingChozoPillarSpawnOnePlatform(yPosition, xPosition, caa);
            break;

        case RISING_CHOZO_PILLAR_POSE_EXTENDED:
            gCurrentSprite.pose = RISING_CHOZO_PILLAR_POSE_KILL;
            break;

        case RISING_CHOZO_PILLAR_POSE_KILL:
            EventFunction(EVENT_ACTION_SETTING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED);
            gCurrentSprite.status = 0;
    }
}

/**
 * 48aec | 124 | Chozo Pillar Platform AI 
 * 
 */
void ChozoPillarPlatform(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.yPosition += PIXEL_SIZE;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED))
            {
                gCurrentSprite.pose = RISING_CHOZO_PILLAR_PLATFORM_POSE_IDLE;
                if (gCurrentSprite.roomSlot != 0x0)
                {
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOam_Spawned;
                    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM_SHADOW, 0, gCurrentSprite.spritesetGfxSlot,
                        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
                }
                else
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOam_Slot0Spawned;
            }
            else
            {
                gCurrentSprite.pose = RISING_CHOZO_PILLAR_PLATFORM_POSE_SPAWNING;
                if (gCurrentSprite.roomSlot != 0x0)
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOam_Spawning;
                else
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOam_Slot0Spawning;

                SoundPlay(SOUND_RISING_CHOZO_PILLAR_PLATFORM_SPAWNING);
            }
            break;

        case RISING_CHOZO_PILLAR_PLATFORM_POSE_SPAWNING:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pose = RISING_CHOZO_PILLAR_PLATFORM_POSE_IDLE;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                if (gCurrentSprite.roomSlot != 0)
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOam_Spawned;
                else
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOam_Slot0Spawned;
            }
            else
            {
                if (gCurrentSprite.roomSlot != 0 && gCurrentSprite.currentAnimationFrame == 21 && gCurrentSprite.animationDurationCounter == 1)
                {
                    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM_SHADOW, 0, gCurrentSprite.spritesetGfxSlot,
                        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
                }
            }
    }
}

/**
 * 48c10 | 6c | Chozo Pillar Platform Shadow AI
 * 
 */
void ChozoPillarPlatformShadow(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gCurrentSprite.pose == 0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_NONE;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(0);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

        gCurrentSprite.hitboxTop = 0;
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = 0;
        gCurrentSprite.hitboxRight = 0;

        gCurrentSprite.pose = 8;

        gCurrentSprite.pOam = sRisingChozoPillarPlatformShadowOAM;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.drawOrder = 12;
    }
}
