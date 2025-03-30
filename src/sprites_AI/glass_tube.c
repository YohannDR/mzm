#include "sprites_AI/glass_tube.h"

#include "data/sprites/glass_tube.h"

#include "constants/audio.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/power_bomb_explosion.h"

#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/clipdata.h"
#include "structs/power_bomb_explosion.h"

#define GLASS_TUBE_CRACKING_DELAY_TIMER work0

/**
 * @brief 4627c | 160 | Removes the clipdata for the glass tube
 * 
 */
void GlassTubeChangeCcaa(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 caa;

    yPosition = gCurrentSprite.yPosition - (HALF_BLOCK_SIZE);
    xPosition = gCurrentSprite.xPosition;
    caa = CAA_REMOVE_SOLID;

    // Top row
    // Left part
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition - BLOCK_SIZE);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition - (BLOCK_SIZE * 2));
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition - (BLOCK_SIZE * 3));
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition - (BLOCK_SIZE * 4));
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition - (BLOCK_SIZE * 5));

    // Right part
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition + BLOCK_SIZE);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition + (BLOCK_SIZE * 2));
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition + (BLOCK_SIZE * 3));
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition + (BLOCK_SIZE * 4));
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition + (BLOCK_SIZE * 5));
    
    // Bottom row
    // Left part
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + (BLOCK_SIZE * 3), xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + (BLOCK_SIZE * 3), xPosition - BLOCK_SIZE);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + (BLOCK_SIZE * 3), xPosition - (BLOCK_SIZE * 2));
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + (BLOCK_SIZE * 3), xPosition - (BLOCK_SIZE * 3));
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + (BLOCK_SIZE * 3), xPosition - (BLOCK_SIZE * 4));
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + (BLOCK_SIZE * 3), xPosition - (BLOCK_SIZE * 5));
    gCurrentClipdataAffectingAction = caa;

    // Right part
    ClipdataProcess(yPosition + (BLOCK_SIZE * 3), xPosition + BLOCK_SIZE);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + (BLOCK_SIZE * 3), xPosition + (BLOCK_SIZE * 2));
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + (BLOCK_SIZE * 3), xPosition + (BLOCK_SIZE * 3));
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + (BLOCK_SIZE * 3), xPosition + (BLOCK_SIZE * 4));
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + (BLOCK_SIZE * 3), xPosition + (BLOCK_SIZE * 5));
}

/**
 * 463dc | 90 | Initialize a glass tube sprite
 * 
 */
void GlassTubeInit(void)
{
    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(7 * BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -(2 * BLOCK_SIZE);
    gCurrentSprite.hitboxBottom = 2 * BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -(4 * BLOCK_SIZE);
    gCurrentSprite.hitboxRight = 4 * BLOCK_SIZE;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.samusCollision = SSC_NONE;
    
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_GLASS_TUBE_BROKEN))
    {
        // Set broken behavior
        gCurrentSprite.pOam = sGlassTubeOAM_Broken;
        gCurrentSprite.pose = GLASS_TUBE_POSE_IDLE;
        GlassTubeChangeCcaa(); // Remove collision
    }
    else
    {
        // Set waiting for power bomb behavior
        gCurrentSprite.pOam = sGlassTubeOAM_Intact;
        gCurrentSprite.pose = GLASS_TUBE_POSE_POWER_BOMB_COLLISION;
    }

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_FULLY_POWERED_SUIT_OBTAINED))
        SoundPlay(SOUND_RAIN_HITTING_GROUND);
}

/**
 * 4646c | c0 | Checks for collision between a power bomb and the glass tube
 * 
 */
void GlassTubeCheckPowerBombCollision(void)
{
    u16 bombY;
    u16 bombX;
    u16 bombTop;
    u16 bombBottom;
    u16 bombLeft;
    u16 bombRight;   
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_FULLY_POWERED_SUIT_OBTAINED)
        && gCurrentPowerBomb.animationState != PB_STATE_NONE && gEquipment.maxPowerBombs != 0)
    {
        bombY = gCurrentPowerBomb.yPosition;
        bombX = gCurrentPowerBomb.xPosition;
        bombTop = gCurrentPowerBomb.hitboxTop + bombY;
        bombBottom = gCurrentPowerBomb.hitboxBottom + bombY;
        bombLeft = gCurrentPowerBomb.hitboxLeft + bombX;
        bombRight = gCurrentPowerBomb.hitboxRight + bombX;
        
        spriteY = gCurrentSprite.yPosition;
        spriteX = gCurrentSprite.xPosition;
        spriteTop = gCurrentSprite.hitboxTop + spriteY;
        spriteBottom = gCurrentSprite.hitboxBottom + spriteY;
        spriteLeft = gCurrentSprite.hitboxLeft + spriteX;
        spriteRight = gCurrentSprite.hitboxRight + spriteX;

        if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, bombTop, bombBottom, bombLeft, bombRight))
        {
            // Set cracking behavior
            gCurrentSprite.pose = GLASS_TUBE_POSE_DELAY_BEFORE_CRACKING;
            gCurrentSprite.GLASS_TUBE_CRACKING_DELAY_TIMER = CONVERT_SECONDS(2.f);
            // Set event
            EventFunction(EVENT_ACTION_SETTING, EVENT_GLASS_TUBE_BROKEN);
        }
    }
}

/**
 * 4652c | 3c | Delay before the glass tube starts cracking
*/
void GlassTubeDelayBeforeBreaking(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.GLASS_TUBE_CRACKING_DELAY_TIMER);
    if (gCurrentSprite.GLASS_TUBE_CRACKING_DELAY_TIMER == 0)
    {
        // Set cracking behavior
        gCurrentSprite.pose = GLASS_TUBE_POSE_CRACKING;
        gCurrentSprite.pOam = sGlassTubeOAM_Cracking;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        SoundPlay(SOUND_GLASS_TUBE_BREAKING);
    }
}

/**
 * 46568 | 8c | Checks if the cracking animation ended, spawn dust particles and starts a global screen shake
 * 
 */
void GlassTubeCheckCrackingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set breaking behavior
        gCurrentSprite.pose = GLASS_TUBE_POSE_BREAKING;
        gCurrentSprite.pOam = sGlassTubeOAM_Breaking;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        // Remove collision
        GlassTubeChangeCcaa();

        // Play effects
        ParticleSet(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE - PIXEL_SIZE / 2), gCurrentSprite.xPosition - (5 * BLOCK_SIZE - QUARTER_BLOCK_SIZE - PIXEL_SIZE), PE_MEDIUM_DUST);
        ParticleSet(gCurrentSprite.yPosition + (2 * BLOCK_SIZE + HALF_BLOCK_SIZE), gCurrentSprite.xPosition - (5 * BLOCK_SIZE), PE_TWO_MEDIUM_DUST);

        ParticleSet(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE - PIXEL_SIZE / 2), gCurrentSprite.xPosition + (5 * BLOCK_SIZE - QUARTER_BLOCK_SIZE - PIXEL_SIZE), PE_MEDIUM_DUST);
        ParticleSet(gCurrentSprite.yPosition + (2 * BLOCK_SIZE + HALF_BLOCK_SIZE), gCurrentSprite.xPosition + (5 * BLOCK_SIZE), PE_TWO_MEDIUM_DUST);

        ScreenShakeStartVertical(CONVERT_SECONDS(.5f), 0x80 | 1);
        ScreenShakeStartHorizontal(CONVERT_SECONDS(.5f), 0x80 | 1);
    }
}

/**
 * 46568 | 8c | Checks if the breaking animation ended
 * 
 */
void GlassTubeCheckBreakingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set broken behavior
        gCurrentSprite.pose = GLASS_TUBE_POSE_IDLE;
        gCurrentSprite.pOam = sGlassTubeOAM_Broken;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * 46620 | e8 | Glass Tube AI
 * 
 */
void GlassTube(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            GlassTubeInit();
            break;
        case GLASS_TUBE_POSE_POWER_BOMB_COLLISION:
            GlassTubeCheckPowerBombCollision();
            break;
        case GLASS_TUBE_POSE_DELAY_BEFORE_CRACKING:
            GlassTubeDelayBeforeBreaking();
            break;
        case GLASS_TUBE_POSE_CRACKING:
            GlassTubeCheckCrackingAnimEnded();
            break;
        case GLASS_TUBE_POSE_BREAKING:
            GlassTubeCheckBreakingAnimEnded();
    }
}