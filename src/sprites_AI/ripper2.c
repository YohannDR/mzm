#include "ripper2.h"
#include "../../data/data.h"
#include "../globals.h"

const u32 sRipper2GFX[212];
const u16 sRipper2PAL[16];

const u16 sRipper2OAM_Moving_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x200,
    0xf5, OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x212
};

const u16 sRipper2OAM_Moving_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0xc, OBJ_SPRITE_OAM | 0x20e
};

const u16 sRipper2OAM_Moving_Frame2[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0xc, OBJ_SPRITE_OAM | 0x20a
};

const u16 sRipper2OAM_TurningAround_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x204,
    0xf4, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x212
};

const u16 sRipper2OAM_TurningAround_Frame1[7] = {
    0x2,
    0xf3, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xf5, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x212
};

const struct FrameData sRipper2OAM_Moving[5] = {
    sRipper2OAM_Moving_Frame0,
    0x3,
    sRipper2OAM_Moving_Frame1,
    0x3,
    sRipper2OAM_Moving_Frame2,
    0x3,
    sRipper2OAM_Moving_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sRipper2OAM_TurningAround[3] = {
    sRipper2OAM_TurningAround_Frame0,
    0x3,
    sRipper2OAM_TurningAround_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sRipper2OAM_TurningAroundPart2[3] = {
    sRipper2OAM_TurningAround_Frame1,
    0x3,
    sRipper2OAM_TurningAround_Frame0,
    0x3,
    NULL,
    0x0
};


/**
 * @brief 1bfd8 | 7c | Initializes a ripper 2 sprite
 * 
 */
void Ripper2Init(void)
{
    gCurrentSprite.hitboxTopOffset = -0x24;
    gCurrentSprite.hitboxBottomOffset = 0x8;
    gCurrentSprite.hitboxLeftOffset = -0x28;
    gCurrentSprite.hitboxRightOffset = 0x28;

    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

    gCurrentSprite.pOam = sRipper2OAM_Moving;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.yPosition -= 0x8;
    SpriteUtilChooseRandomXFlip();
    gCurrentSprite.pose = RIPPER2_POSE_MOVING_INIT;
}

/**
 * @brief 1c054 | 20 | Initializes a ripper 2 to be moving
 * 
 */
void Ripper2MovingInit(void)
{
    gCurrentSprite.pose = RIPPER2_POSE_MOVING;
    gCurrentSprite.pOam = sRipper2OAM_Moving;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
}

/**
 * @brief 1c074 | 60 | Handles a ripper 2 moving
 * 
 */
void Ripper2Move(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition + 0x2C);
        if (gPreviousCollisionCheck != 0x11)
            gCurrentSprite.xPosition += 0x8;
        else
            gCurrentSprite.pose = RIPPER2_POSE_TURNING_AROUND_INIT;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition - 0x2C);
        if (gPreviousCollisionCheck == 0x11)
            gCurrentSprite.pose = RIPPER2_POSE_TURNING_AROUND_INIT;
        else
            gCurrentSprite.xPosition -= 0x8;
    }
}

/**
 * @brief 1c0d4 | 38 | Initializes a ripper 2 to be turning around
 * 
 */
void Ripper2TurnAroundInit(void)
{
    gCurrentSprite.pose = RIPPER2_POSE_TURNING_AROUND_FIRST_PART;
    gCurrentSprite.pOam = sRipper2OAM_TurningAround;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(0x267);
}

/**
 * @brief 1c10c | 38 | Handles the first part of a ripper 2 turning around
 * 
 */
void Ripper2TurnAroundPart1(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.status ^= SPRITE_STATUS_XFLIP;
        gCurrentSprite.pose = RIPPER2_POSE_TURNING_AROUND_SECOND_PART;
        gCurrentSprite.pOam = sRipper2OAM_TurningAroundPart2;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 1c144 | 1c | Handles the second part of a ripper 2 turning around
 * 
 */
void Ripper2TurnAroundPart2(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = RIPPER2_POSE_MOVING_INIT;
}

/**
 * @brief 1c160 | d8 | Ripper 2 AI
 * 
 */
void Ripper2(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x268);
    }

    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (!SpriteUtilIsSpriteStunned())
        {
            switch (gCurrentSprite.pose)
            {
                case 0x0:
                    Ripper2Init();
                    break;
                case RIPPER2_POSE_MOVING_INIT:
                    Ripper2MovingInit();
                case RIPPER2_POSE_MOVING:
                    Ripper2Move();
                    break;
                case RIPPER2_POSE_TURNING_AROUND_INIT:
                    Ripper2TurnAroundInit();
                case RIPPER2_POSE_TURNING_AROUND_FIRST_PART:
                    Ripper2TurnAroundPart1();
                    break;
                case RIPPER2_POSE_TURNING_AROUND_SECOND_PART:
                    Ripper2TurnAroundPart2();
                    break;
                default:
                    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - 0x18, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
        }
    }
}