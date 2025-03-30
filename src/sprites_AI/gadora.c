#include "sprites_AI/gadora.h"
#include "macros.h"

#include "data/sprites/gadora.h"
#include "data/sprites/enemy_drop.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/display.h"
#include "structs/sprite.h"

#define GADORA_DETECTION_DELAY_TIMER work0
#define GADORA_EYE_OPEN_TIMER work0
#define GADORA_DEATH_ANIMATION_TIMER work0
#define GADORA_EYE_DEATH_ANIMATION_TIMER work0
#define GADORA_BEAM_MOVEMENT_DELAY_TIMER work0

/**
 * @brief 49eb8 | 134 | Initializes a gadora sprite
 * 
 */
void GadoraInit(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 ramSlot;

    // Check isn't already dead
    if (gCurrentSprite.spriteId == PSPRITE_GADORA_KRAID)
    {
        if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_GADORA_KILLED))
        {
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_10;
        }
        else
        {
            gCurrentSprite.status = 0;
            return;
        }
    }
    else if (gCurrentSprite.spriteId == PSPRITE_GADORA_RIDLEY && EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_GADORA_KILLED))
    {
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
    gCurrentSprite.xPosition += PIXEL_SIZE * 3;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    // Disable hatch
    GadoraHatchUpdate(xPosition, yPosition, FALSE);

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        xPosition += QUARTER_BLOCK_SIZE;
    else
        xPosition -= QUARTER_BLOCK_SIZE;

    ramSlot = SpriteSpawnSecondary(SSPRITE_GADORA_EYE, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, 0);

    if (ramSlot == UCHAR_MAX)
    {
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.pose = GADORA_POSE_IDLE_INIT;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -(2 * BLOCK_SIZE - EIGHTH_BLOCK_SIZE);
    gCurrentSprite.hitboxBottom = 2 * BLOCK_SIZE - EIGHTH_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE);
    gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE + PIXEL_SIZE;

    gCurrentSprite.pOam = sGadoraOAM_EyeClosed;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 5;
    gCurrentSprite.bgPriority = MOD_AND(gIoRegistersBackup.BG1CNT, 4);
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    // Change palette if ridley gadora
    if (gCurrentSprite.spriteId == PSPRITE_GADORA_RIDLEY)
    {
        gCurrentSprite.absolutePaletteRow = 1;
        gCurrentSprite.paletteRow = 1;
    }
}

/**
 * @brief 49fec | 30 | Initializes a gadora to be idle
 * 
 */
void GadoraIdleInit(void)
{
    gCurrentSprite.pose = GADORA_POSE_SAMUS_DETECTION;

    gCurrentSprite.pOam = sGadoraOAM_EyeClosed;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.GADORA_DETECTION_DELAY_TIMER = GADORA_COMPUTE_TIMER(61);
}

/**
 * @brief 4a01c | 54 | Checks if samus is in range to open the eye
 * 
 */
void GadoraSamusDetection(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.GADORA_DETECTION_DELAY_TIMER); // Timer before checking for samus
    if (gCurrentSprite.GADORA_DETECTION_DELAY_TIMER == 0)
    {
        // Check if samus in front
        if (SpriteUtilCheckSamusNearSpriteFrontBehind(BLOCK_SIZE * 2, BLOCK_SIZE * 7, 0) == NSFB_IN_FRONT)
        {
            gCurrentSprite.pose = GADORA_POSE_CHECK_WARNING_ENDED;

            gCurrentSprite.pOam = sGadoraOAM_Warning;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
        else
        {
            gCurrentSprite.GADORA_DETECTION_DELAY_TIMER = GADORA_COMPUTE_TIMER(61); // Reset timer
        }
    }
}

/**
 * @brief 4a070 | 34 | Checks if the warning animation ended
 * 
 */
void GadoraCheckWarningAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = GADORA_POSE_CHECK_OPENING_EYE_ENDED;

        gCurrentSprite.pOam = sGadoraOAM_OpeningEye;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        SoundPlay(SOUND_GADORA_OPENING_EYE);
    }
}

/**
 * @brief 4a0a4 | 38 | Checks if the opening eye animation ended
 * 
 */
void GadoraCheckOpeningEyeAnimEnded(void)
{
    u16 xPosition;
    u16 status;
    
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = GADORA_POSE_EYE_OPENED;

        gCurrentSprite.pOam = sGadoraOAM_EyeOpened;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.GADORA_EYE_OPEN_TIMER = CONVERT_SECONDS(1.f); // Timer for how long to stay open
        if (gCurrentSprite.spriteId == PSPRITE_GADORA_RIDLEY)
        {
            gCurrentSprite.GADORA_EYE_OPEN_TIMER = CONVERT_SECONDS(1.f) + CONVERT_SECONDS(7.f / 15); // Longer timer because of beam

            // Spawn beam
            xPosition = gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE;
            status = SPRITE_STATUS_X_FLIP;

            SpriteSpawnSecondary(SSPRITE_GADORA_BEAM, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, xPosition, status);
        }
    }
}

/**
 * @brief 4a10c | 74 | Handles the gadora having its eye opened
 * 
 */
void GadoraEyeOpened(void)
{
    if (gCurrentSprite.GADORA_EYE_OPEN_TIMER == 0)
    {
        // Timer done, close eye
        gCurrentSprite.pose = GADORA_POSE_CHECK_CLOSING_EYE_ENDED;

        gCurrentSprite.pOam = sGadoraOAM_ClosingEye;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        SoundPlay(SOUND_GADORA_CLOSING_EYE);
        return;
    }

    APPLY_DELTA_TIME_DEC(gCurrentSprite.GADORA_EYE_OPEN_TIMER); // Timer for how long it stays open

    // Check set the eye moving OAM
    if (gCurrentSprite.pOam == sGadoraOAM_EyeOpened)
    {
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.pOam = sGadoraOAM_EyeMoving;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
    else if (gCurrentSprite.GADORA_EYE_OPEN_TIMER == CONVERT_SECONDS(0.1f) + 1 * DELTA_TIME)
    {
        // Eye will soon close, set before closing OAM
        gCurrentSprite.pOam = sGadoraOAM_BeforeClosing;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 4a180 | 1c | Checks if the closing eye animation almost ended
 * 
 */
void GadoraCheckClosingEyeAnimNearEnded(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = GADORA_POSE_IDLE_INIT; // Set idle
}

/**
 * @brief 4a19c | 30 | Initializes a gadara to be dying
 * 
 */
void GadoraDeathGfxInit(void)
{
    gCurrentSprite.pose = GADORA_POSE_DEATH;

    gCurrentSprite.pOam = sGadoraOAM_Death;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.GADORA_DEATH_ANIMATION_TIMER = TWO_THIRD_SECOND; // Death animation timer
    gCurrentSprite.samusCollision = SSC_NONE;
}

/**
 * @brief 4a1cc | d4 | Handles the death of a gadora
 * 
 */
void GadoraDeath(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 rng;
    u8 drop;
    u8 timer;
    u32 yOffset;
    
    timer = APPLY_DELTA_TIME_DEC(gCurrentSprite.GADORA_DEATH_ANIMATION_TIMER);
    // CONVERT_SECONDS(1.f / 15)
    if (MOD_AND(timer, 4))
        return;

    if (MOD_BLOCK_AND(timer, 4))
    {
        // Set stun (white) palette
        gCurrentSprite.paletteRow = 14 - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset);
        return;
    }

    // Set normal palette
    gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    if (timer == 0)
    {
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;

        // Re-enable hatch
        GadoraHatchUpdate(xPosition, yPosition, TRUE);

        // Set event
        if (gCurrentSprite.spriteId == PSPRITE_GADORA_KRAID)
            EventFunction(EVENT_ACTION_SETTING, EVENT_KRAID_GADORA_KILLED);
        else if (gCurrentSprite.spriteId == PSPRITE_GADORA_RIDLEY)
            EventFunction(EVENT_ACTION_SETTING, EVENT_RIDLEY_GADORA_KILLED);

        rng = gSpriteRng;
        xPosition += QUARTER_BLOCK_SIZE;
        yOffset = rng - (BLOCK_SIZE + PIXEL_SIZE * 2);

        // Kill sprite
        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition - yOffset, xPosition - rng, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);

        // Create additional drop if the gadora spawned a drop
        if (gCurrentSprite.status)
        {
            if (MOD_AND(rng, 2))
                drop = PSPRITE_LARGE_ENERGY_DROP;
            else
                drop = PSPRITE_MISSILE_DROP;

            SpriteSpawnDropFollowers(drop, gCurrentSprite.roomSlot, 0,
                gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, 0);
        }
    }
}

/**
 * @brief 4a2a0 | 78 | Gadora AI
 * 
 */
void Gadora(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            GadoraInit();
            break;

        case GADORA_POSE_IDLE_INIT:
            GadoraIdleInit();

        case GADORA_POSE_SAMUS_DETECTION:
            GadoraSamusDetection();
            break;

        case GADORA_POSE_CHECK_WARNING_ENDED:
            GadoraCheckWarningAnimEnded();
            break;

        case GADORA_POSE_CHECK_OPENING_EYE_ENDED:
            GadoraCheckOpeningEyeAnimEnded();
            break;

        case GADORA_POSE_EYE_OPENED:
            GadoraEyeOpened();
            break;

        case GADORA_POSE_CHECK_CLOSING_EYE_ENDED:
            GadoraCheckClosingEyeAnimNearEnded();
            break;

        case GADORA_POSE_DEATH:
            GadoraDeath();
            break;

        default:
            GadoraDeathGfxInit();
    }
}

/**
 * @brief 4a318 | 1d0 | Gadora eye AI
 * 
 */
void GadoraEye(void)
{
    u8 ramSlot;
    u32 rng;
    u32 yOffset;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(SOUND_GADORA_EYE_DAMAGED);
    }

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.health != 0)
        gSpriteData[ramSlot].paletteRow = gCurrentSprite.paletteRow;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.bgPriority = MOD_AND(gIoRegistersBackup.BG1CNT, 4);

            if (gSpriteData[ramSlot].spriteId == PSPRITE_GADORA_KRAID)
            {
                gCurrentSprite.health = 1;
            }
            else
            {
                gCurrentSprite.absolutePaletteRow = 1;
                gCurrentSprite.paletteRow = 1;
                gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            }

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;

            gCurrentSprite.pOam = sEnemyDropOAM_LargeEnergy; // No graphics
            gCurrentSprite.animationDurationCounter = 0.;
            gCurrentSprite.currentAnimationFrame = 0.;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = 0x9;
            break;

        case SPRITE_POSE_DESTROYED: // Killed
            gSpriteData[ramSlot].pose = SPRITE_POSE_DESTROYED;
            gSpriteData[ramSlot].ignoreSamusCollisionTimer = 1 * DELTA_TIME;
            gSpriteData[ramSlot].health = 0;

            gCurrentSprite.pose = GADORA_EYE_POSE_DEATH;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.GADORA_EYE_DEATH_ANIMATION_TIMER = TWO_THIRD_SECOND; // Death timer
            break;

        case GADORA_EYE_POSE_DEATH:
            APPLY_DELTA_TIME_DEC(gCurrentSprite.GADORA_EYE_DEATH_ANIMATION_TIMER);
            if (gCurrentSprite.GADORA_EYE_DEATH_ANIMATION_TIMER == 0)
            {
                rng = gSpriteRng;
                yOffset = rng - (BLOCK_SIZE + PIXEL_SIZE);
                rng += QUARTER_BLOCK_SIZE;
                
                SpriteUtilSpriteDeath(DEATH_NORMAL, yOffset + gCurrentSprite.yPosition,
                    rng + gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            }
            break;

        default:
            if (gSpriteData[ramSlot].pose == GADORA_POSE_EYE_OPENED)
            {
                // Make vulnerable
                gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;

                // CONVERT_SECONDS(.25f) + 1 * DELTA_TIME
                if (SPRITE_GET_ISFT(gCurrentSprite) == 16)
                    gSpriteData[ramSlot].GADORA_EYE_OPEN_TIMER = 0; // Force close eye if hit
            }
            else
                gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES; // Make un-vulnerable
    }
}

/**
 * @brief 4a4e8 | fc | Gadora beam AI
 * 
 */
void GadoraBeam(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(QUARTER_BLOCK_SIZE * 3);
            gCurrentSprite.hitboxBottom = (QUARTER_BLOCK_SIZE * 3);

            gCurrentSprite.pOam = sGadoraBeamOAM_Moving;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = GADORA_BEAM_POSE_MOVING;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.bgPriority = MOD_AND(gIoRegistersBackup.BG1CNT, 4);
            gCurrentSprite.health = 1;

            gCurrentSprite.GADORA_BEAM_MOVEMENT_DELAY_TIMER = CONVERT_SECONDS(.25f) + 1 * DELTA_TIME; // Delay before it starts actually moving
            gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2;

        case GADORA_BEAM_POSE_MOVING:
            if (gCurrentSprite.GADORA_BEAM_MOVEMENT_DELAY_TIMER != 0)
            {
                APPLY_DELTA_TIME_DEC(gCurrentSprite.GADORA_BEAM_MOVEMENT_DELAY_TIMER);
                if (gCurrentSprite.GADORA_BEAM_MOVEMENT_DELAY_TIMER == 0)
                    SoundPlay(SOUND_GADORA_BEAM_EMERGING);
            }
            else
            {
                gCurrentSprite.xPosition += PIXEL_SIZE * 3;
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

                if (gPreviousCollisionCheck == COLLISION_AIR)
                    return;

                ParticleSet(gCurrentSprite.yPosition + QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3, gCurrentSprite.xPosition, 
                    PE_SPRITE_EXPLOSION_BIG);

                if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlay(SOUND_GADORA_BEAM_MOVING);

                gCurrentSprite.status = 0;
            }
    }
}
