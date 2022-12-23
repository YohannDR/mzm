#include "sprites_AI/rising_chozo_pillar.h"
#include "data/sprites/rising_chozo_pillar.h"
#include "data/sprites/enemy_drop.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/sprite.h"

/**
 * 4854c | a8 | 
 * Spawns random sprite debris depending on the parameters
 * 
 * @param yPosition Y Position
 * @param xPosition X Position 
 * @param rng Set of debris to use
 */
void RisingChozoPillarRandomSpriteDebris(u16 yPosition, u16 xPosition, u8 rng)
{
    switch (rng)
    {
        case 0x1:
            SpriteDebrisInit(0x0, 0x11, yPosition - 0x28, xPosition);
            SpriteDebrisInit(0x0, 0x12, yPosition - 0x10, xPosition + 0x46);
            break;
        case 0x3:
            SpriteDebrisInit(0x0, 0x13, yPosition - 0x14, xPosition - 0x5C);
            SpriteDebrisInit(0x0, 0x4, yPosition - 0xA, xPosition + 0x1E);
            break;
        case 0x7:
            SpriteDebrisInit(0x0, 0x11, yPosition - 0x8, xPosition - 0x32);
            SpriteDebrisInit(0x0, 0x12, yPosition - 0x34, xPosition + 0x78);
            break;
        case 0xC:
            SpriteDebrisInit(0x0, 0x13, yPosition - 0x20, xPosition + 0x1E);
            SpriteDebrisInit(0x0, 0x4, yPosition - 0x4, xPosition - 0x6E);
    }
}

/**
 * 485f4 | ac | 
 * Spawns random particles depending on the parameters
 * 
 * @param yPosition Y Position
 * @param xPosition X Position 
 * @param rng Set of particles to use
 */
void RisingChozoPillarRandomParticles(u16 yPosition, u16 xPosition, u8 rng)
{
    switch (rng)
    {
        case 0x1:
            ParticleSet(yPosition, xPosition - 0x28, PE_TWO_MEDIUM_DUST);
            break;
        case 0x10:
            ParticleSet(yPosition, xPosition + 0x3C, PE_SECOND_MEDIUM_DUST);
            break;
        case 0x21:
            ParticleSet(yPosition, xPosition - 0x3C, PE_SECOND_MEDIUM_DUST);
            break;
        case 0x32:
            ParticleSet(yPosition, xPosition + 0x14, PE_MEDIUM_DUST);
            break;
        case 0x42:
            ParticleSet(yPosition, xPosition - 0x50, PE_TWO_MEDIUM_DUST);
            break;
        case 0x54:
            ParticleSet(yPosition, xPosition + 0x50, PE_SECOND_MEDIUM_DUST);
            ParticleSet(yPosition, xPosition, PE_SECOND_TWO_MEDIUM_DUST);
            break;
        case 0x64:
            ParticleSet(yPosition, xPosition - 0x14, PE_SECOND_TWO_MEDIUM_DUST);
            break;
        case 0x6E:
            ParticleSet(yPosition, xPosition + 0x28, PE_MEDIUM_DUST);
    }
}

/**
 * @brief 486a0 | e4 | 
 * Spawns three platforms and sets the collision for them
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
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x1, gCurrentSprite.spritesetGFXSlot,
        gCurrentSprite.primarySpriteRAMSlot, yPosition - (BLOCK_SIZE * 3),  xPosition + (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), 0x0);
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x1, gCurrentSprite.spritesetGFXSlot,
        gCurrentSprite.primarySpriteRAMSlot, yPosition - (BLOCK_SIZE * 11),  xPosition + (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), 0x0);
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x1, gCurrentSprite.spritesetGFXSlot,
        gCurrentSprite.primarySpriteRAMSlot, yPosition - (BLOCK_SIZE * 19), xPosition + (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), 0x0);
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

    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x0, gCurrentSprite.spritesetGFXSlot,
        gCurrentSprite.primarySpriteRAMSlot, yPosition - BLOCK_SIZE * 7, xPosition + HALF_BLOCK_SIZE, 0x0);
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x0, gCurrentSprite.spritesetGFXSlot,
        gCurrentSprite.primarySpriteRAMSlot, yPosition - BLOCK_SIZE * 24, xPosition + HALF_BLOCK_SIZE, 0x0);
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
    ClipdataProcess(yPosition - 0x3C0, xPosition + 0x180);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - 0x3C0, xPosition + 0x1C0);
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x0, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, yPosition - 0x3C0, xPosition + 0x1A0, 0x0);
}

/**
 * 488a4 | 248 | Rising Chozo Pillar AI
 * 
 */
void RisingChozoPillar(void)
{
    u8 caa;
    u16 yPosition;
    u16 y_pos;
    u16 xPosition;
    u16 x_pos;

    caa = CAA_MAKE_SOLID_GRIPPABLE;
    yPosition = gCurrentSprite.yPosition - 0x20;
    xPosition = gCurrentSprite.xPosition;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED))
            {
                RisingChozoPillarSpawnThreePlatforms(yPosition, xPosition, caa);
                RisingChozoPillarSpawnTwoPlatforms(yPosition, xPosition, caa);
                RisingChozoPillarSpawnOnePlatform(yPosition, xPosition, caa);
                gCurrentSprite.status = 0x0;
            }
            else
            {
                gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
                gCurrentSprite.samusCollision = SSC_NONE;
                gCurrentSprite.drawDistanceTopOffset = 0x1;
                gCurrentSprite.drawDistanceBottomOffset = 0x1;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x1;
                gCurrentSprite.hitboxTopOffset = 0x0;
                gCurrentSprite.hitboxBottomOffset = 0x0;
                gCurrentSprite.hitboxLeftOffset = 0x0;
                gCurrentSprite.hitboxRightOffset = 0x0;
                gCurrentSprite.pOam = sEnemyDropOAM_LargeEnergy;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.pose = 0x8;
            }
            break;
        case 0x8:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_POWER_GRIP_OBTAINED))
            {
                gCurrentSprite.pose = 0x9;
                gCurrentSprite.oamScaling = 0x2C0;
                SoundPlay(0x125);
            }
            break;
        case 0x9:
            if ((gCurrentSprite.oamScaling & 0x1F) == 0x0)
                ScreenShakeStartVertical(0x1E, 0x81);
            gCurrentSprite.oamScaling--;
            if (gCurrentSprite.oamScaling != 0x0)
                gBG2Movement.yOffset += 0x2;
            else
            {
                gCurrentSprite.pose = 0x22;
                SoundFade(0x125, 0xA);
            }
            y_pos = yPosition + 0x20;
            x_pos = xPosition + 0xE0;
            RisingChozoPillarRandomSpriteDebris(y_pos, x_pos, gCurrentSprite.oamScaling & 0xF);
            RisingChozoPillarRandomParticles(y_pos, x_pos, gCurrentSprite.oamScaling & 0x7F);
            break;
        case 0x22:
            gCurrentSprite.pose = 0x23;
            RisingChozoPillarSpawnThreePlatforms(yPosition, xPosition, caa);
            break;
        case 0x23:
            gCurrentSprite.pose = 0x24;
            RisingChozoPillarSpawnTwoPlatforms(yPosition, xPosition, caa);
            break;
        case 0x24:
            gCurrentSprite.pose = 0x25;
            RisingChozoPillarSpawnOnePlatform(yPosition, xPosition, caa);
            break;
        case 0x25:
            gCurrentSprite.pose = 0x26;
            break;
        case 0x26:
            EventFunction(EVENT_ACTION_SETTING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED);
            gCurrentSprite.status = 0x0;
    }
}

/**
 * 48aec | 124 | Chozo Pillar Platform AI 
 * 
 */
void ChozoPillarPlatform(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.yPosition += 0x4;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED))
            {
                gCurrentSprite.pose = 0x9;
                if (gCurrentSprite.roomSlot != 0x0)
                {
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOAM_Spawned;
                    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM_SHADOW, 0x0, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
                }
                else
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOAM_Slot0Spawned;
            }
            else
            {
                gCurrentSprite.pose = 0x8;
                if (gCurrentSprite.roomSlot != 0x0)
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOAM_Spawning;
                else
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOAM_Slot0Spawning;
                SoundPlay(0x126);
            }
            break;

        case 0x8:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pose = 0x9;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                if (gCurrentSprite.roomSlot != 0x0)
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOAM_Spawned;
                else
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOAM_Slot0Spawned;
            }
            else
            {
                if (gCurrentSprite.roomSlot != 0x0 && gCurrentSprite.currentAnimationFrame == 0x15 && gCurrentSprite.animationDurationCounter == 0x1)
                    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM_SHADOW, 0x0, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
            }
    }
}

/**
 * 48c10 | 6c | Chozo Pillar Platform Shadow AI
 * 
 */
void ChozoPillarPlatformShadow(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawDistanceTopOffset = 0x0;
        gCurrentSprite.drawDistanceBottomOffset = 0x10;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
        gCurrentSprite.hitboxTopOffset = 0x0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = 0x0;
        gCurrentSprite.hitboxRightOffset = 0x0;
        gCurrentSprite.pose = 0x8;
        gCurrentSprite.pOam = sRisingChozoPillarPlatformShadowOAM;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.drawOrder = 0xC;
    }
}