#include "sprites_AI/chozo_ball.h"
#include "sprites_AI/chozo_statue.h"
#include "macros.h"

#include "data/sprites/chozo_statue.h"
#include "data/sprites/unknown_item_chozo_statue.h"

#include "constants/audio.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/text.h"

#include "structs/sprite.h"
#include "structs/samus.h"

#define CHOZO_BALL_FLICKER_TIMER work0

/**
 * 162b0 | 94 | Spawns an item banner depending on the chozo statue sprite ID
 * 
 * @param spriteId Chozo statue sprite ID
 */
void ChozoBallSpawnItemBanner(u8 spriteId)
{
    u8 text;

    switch (spriteId)
    {
        case PSPRITE_CHOZO_STATUE_LONG:
            text = MESSAGE_LONG_BEAM;
            break;

        case PSPRITE_CHOZO_STATUE_ICE:
            text = MESSAGE_ICE_BEAM;
            break;

        case PSPRITE_CHOZO_STATUE_WAVE:
            text = MESSAGE_WAVE_BEAM;
            break;

        case PSPRITE_CHOZO_STATUE_PLASMA_BEAM:
            text = MESSAGE_UKNOWN_ITEM_PLASMA;
            break;

        case PSPRITE_CHOZO_STATUE_BOMB:
            text = MESSAGE_BOMB;
            break;

        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER:
            text = MESSAGE_SPEED_BOOSTER;
            break;

        case PSPRITE_CHOZO_STATUE_HIGH_JUMP:
            text = MESSAGE_HIGH_JUMP;
            break;

        case PSPRITE_CHOZO_STATUE_SCREW:
            text = MESSAGE_SCREW_ATTACK;
            break;

        case PSPRITE_CHOZO_STATUE_VARIA:
            text = MESSAGE_VARIA_SUIT;
            break;

        case PSPRITE_CHOZO_STATUE_SPACE_JUMP:
            text = MESSAGE_UNKNOWN_ITEM_SPACE_JUMP;
            break;

        case PSPRITE_CHOZO_STATUE_GRAVITY:
            text = MESSAGE_UNKNOWN_ITEM_GRAVITY;
            break;
    }

    SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, text, 6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
}

/**
 * @brief 16344 | 64 | Sets the closed OAM of a chozo ball based on the sprite ID
 * 
 * @param spriteId Chozo statue sprite ID
 */
void ChozoBallSetClosedOam(u8 spriteId)
{
    // Check whether to use the normal of unknown version
    switch (spriteId)
    {
        case PSPRITE_CHOZO_STATUE_PLASMA_BEAM:
            gCurrentSprite.pOam = sChozoBallOam_UnknownClosed;
            break;
        
        case PSPRITE_CHOZO_STATUE_SPACE_JUMP:
            gCurrentSprite.pOam = sChozoBallOam_UnknownClosed;
            break;

        case PSPRITE_CHOZO_STATUE_GRAVITY:
            gCurrentSprite.pOam = sChozoBallOam_UnknownClosed;
            break;
        
        case PSPRITE_CHOZO_STATUE_LONG:
        case PSPRITE_CHOZO_STATUE_ICE:
        case PSPRITE_CHOZO_STATUE_WAVE:
        case PSPRITE_CHOZO_STATUE_BOMB:
        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER:
        case PSPRITE_CHOZO_STATUE_HIGH_JUMP:
        case PSPRITE_CHOZO_STATUE_SCREW:
        case PSPRITE_CHOZO_STATUE_VARIA:
            gCurrentSprite.pOam = sChozoBallOam_NormalClosed;
            break;

        default:
            gCurrentSprite.pOam = sChozoBallOam_NormalClosed;
    }
}

/**
 * @brief 163a8 | 64 | Sets the revealing OAM of a chozo ball based on the sprite ID
 * 
 * @param spriteId Chozo statue sprite ID
 */
void ChozoBallSetRevealingOam(u8 spriteId)
{
    // Check whether to use the normal of unknown version
    switch (spriteId)
    {
        case PSPRITE_CHOZO_STATUE_PLASMA_BEAM:
            gCurrentSprite.pOam = sChozoBallOam_UnknownRevealing;
            break;

        case PSPRITE_CHOZO_STATUE_SPACE_JUMP:
            gCurrentSprite.pOam = sChozoBallOam_UnknownRevealing;
            break;

        case PSPRITE_CHOZO_STATUE_GRAVITY:
            gCurrentSprite.pOam = sChozoBallOam_UnknownRevealing;
            break;

        case PSPRITE_CHOZO_STATUE_LONG:
        case PSPRITE_CHOZO_STATUE_ICE:
        case PSPRITE_CHOZO_STATUE_WAVE:
        case PSPRITE_CHOZO_STATUE_BOMB:
        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER:
        case PSPRITE_CHOZO_STATUE_HIGH_JUMP:
        case PSPRITE_CHOZO_STATUE_SCREW:
        case PSPRITE_CHOZO_STATUE_VARIA:
            gCurrentSprite.pOam = sChozoBallOam_NormalRevealing;
            break;

        default:
            gCurrentSprite.pOam = sChozoBallOam_NormalRevealing;
    }
}

/**
 * @brief 1640c | 64 | Sets the revealed OAM of a chozo ball based on the sprite ID
 * 
 * @param spriteId Chozo statue sprite ID
 */
void ChozoBallSetRevealedOam(u8 spriteId)
{
    // Check whether to use the normal of unknown version
    switch (spriteId)
    {
        case PSPRITE_CHOZO_STATUE_PLASMA_BEAM:
            gCurrentSprite.pOam = sChozoBallOam_UnknownRevealed;
            break;

        case PSPRITE_CHOZO_STATUE_SPACE_JUMP:
            gCurrentSprite.pOam = sChozoBallOam_UnknownRevealed;
            break;

        case PSPRITE_CHOZO_STATUE_GRAVITY:
            gCurrentSprite.pOam = sChozoBallOam_UnknownRevealed;
            break;

        case PSPRITE_CHOZO_STATUE_LONG:
        case PSPRITE_CHOZO_STATUE_ICE:
        case PSPRITE_CHOZO_STATUE_WAVE:
        case PSPRITE_CHOZO_STATUE_BOMB:
        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER:
        case PSPRITE_CHOZO_STATUE_HIGH_JUMP:
        case PSPRITE_CHOZO_STATUE_SCREW:
        case PSPRITE_CHOZO_STATUE_VARIA:
            gCurrentSprite.pOam = sChozoBallOam_NormalRevealed;
            break;

        default:
            gCurrentSprite.pOam = sChozoBallOam_NormalRevealed;
    }
}

/**
 * 16470 | 74 | Initializes a chozo ball sprite
 * 
 */
void ChozoBallInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.hitboxTop = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3);
    gCurrentSprite.hitboxBottom = (QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3);
    gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3);
    gCurrentSprite.hitboxRight = (QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3);

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(QUARTER_BLOCK_SIZE * 3);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(QUARTER_BLOCK_SIZE * 3);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(QUARTER_BLOCK_SIZE * 3);

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.samusCollision = SSC_SOLID;
    gCurrentSprite.health = 1;
    gCurrentSprite.pose = CHOZO_BALL_POSE_DO_NOTHING;

    ChozoBallSetClosedOam(gSpriteData[gCurrentSprite.primarySpriteRamSlot].spriteId);
}

/**
 * 164e4 | 4 | Empty function
 * 
 */
void ChozoBallEmpty(void)
{
    return;
}

/**
 * 164e8 | 70 | Initializes a chozo ball to be revealing
 * 
 */
void ChozoBallRevealingInit(void)
{
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.health = 1;
    gCurrentSprite.samusCollision = SSC_CHECK_COLLIDING;
    gCurrentSprite.pose = CHOZO_BALL_POSE_REVEALING;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    SPRITE_CLEAR_ISFT(gCurrentSprite);

    ChozoBallSetRevealingOam(gSpriteData[gCurrentSprite.primarySpriteRamSlot].spriteId);
    SoundPlay(SOUND_CHOZO_BALL_REVEALING);
}

/**
 * 16558 | 3c | Checks if the revealing animation has ended
 * 
 */
void ChozoBallCheckRevealingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = CHOZO_BALL_POSE_IDLE;

        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        ChozoBallSetRevealedOam(gSpriteData[gCurrentSprite.primarySpriteRamSlot].spriteId);
    }
}

/**
 * 16594 | 1c | Registers the item grabbed and calls ChozoBallSpawnItemBanner
 * 
 */
void ChozoBallRegisterItem(void)
{
    u8 spriteId;

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gPreventMovementTimer = SAMUS_ITEM_PMT;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

        gCurrentSprite.pose = CHOZO_BALL_POSE_GETTING;
        gCurrentSprite.CHOZO_BALL_FLICKER_TIMER = 0;

        spriteId = gSpriteData[gCurrentSprite.primarySpriteRamSlot].spriteId;
        ChozoStatueRegisterItem(spriteId);
        ChozoBallSpawnItemBanner(spriteId);
    }
}

/**
 * 16600 | 3c | Handles the flashing animation when the item gets grabbed 
 * 
 */
void ChozoBallFlashAnimation(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    // Missing a timer increment?

    // 2 * DELTA_TIME
    if (MOD_AND(gCurrentSprite.CHOZO_BALL_FLICKER_TIMER, 2) == 0)
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    if (gPreventMovementTimer < SAMUS_ITEM_PMT - 1 * DELTA_TIME)
        gCurrentSprite.status = 0;
}

/**
 * 1663c | 58 | Chozo ball AI
 * 
 */
void ChozoBall(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ChozoBallInit();
            break;

        case CHOZO_BALL_POSE_DO_NOTHING:
            ChozoBallEmpty();
            break;

        case CHOZO_BALL_POSE_REVEALING:
            ChozoBallCheckRevealingAnimEnded();
            break;

        case CHOZO_BALL_POSE_IDLE:
            ChozoBallRegisterItem();
            break;

        case CHOZO_BALL_POSE_GETTING:
            ChozoBallFlashAnimation();
            break;

        default:
            // If code reached here, it means that the chozo ball was "killed", thus it needs to start revealing
            ChozoBallRevealingInit();
    }
}
