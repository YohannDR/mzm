#include "sidehopper.h"
#include "../../data/data.h"
#include "../globals.h"

const i16 sSidehopperHighJumpVelocity[10] = {
    -8, -16, -16, -8, -4, 0, 4, 8, 16, 16
};

const i16 sSidehopperLowJumpVelocity[10] = {
    -4, -8, -4, -2, 0, 4, 8, 16, 16, 16
};

const u32 sSidehopperGFX[303];
const u16 sSidehopperPAL[16];

const u16 sSidehopperOAM_Idle_Frame0[19] = {
    0x6,
    0xec, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf0, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x206,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x206,
    0xe6, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x212,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_Idle_Frame1[19] = {
    0x6,
    0xed, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xf0, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x206,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x206,
    0xe7, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x212,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x212,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_Idle_Frame2[19] = {
    0x6,
    0xee, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf0, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x208,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x208,
    0xe8, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x212,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x212,
    0xf3, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_JumpWarning_Frame0[19] = {
    0x6,
    0xec, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf0, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x206,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x206,
    0xe7, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x212,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_JumpWarning_Frame1[19] = {
    0x6,
    0xed, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf0, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x206,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x206,
    0xe8, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x212,
    0xf2, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_JumpWarning_Frame2[19] = {
    0x6,
    0xef, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf1, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x208,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x208,
    0xea, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x212,
    0xea, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x212,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_JumpWarning_Frame3[19] = {
    0x6,
    0xea, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf1, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x208,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x208,
    0xea, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x216,
    0xea, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x216,
    0xef, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_JumpWarning_Frame4[19] = {
    0x6,
    0xe4, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xf1, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x20a,
    0xe5, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x218,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x20a,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x218
};

const u16 sSidehopperOAM_Jumping_Frame0[25] = {
    0x8,
    0xdd, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xe2, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1e9, OBJ_SPRITE_OAM | 0x210,
    0xf0, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x210,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x20e,
    0xe1, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x218,
    0xe1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x218
};

const u16 sSidehopperOAM_Jumping_Frame1[25] = {
    0x8,
    0xdd, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xe3, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xe7, 0x1e9, OBJ_SPRITE_OAM | 0x210,
    0xef, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xe7, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x210,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x20e,
    0xe0, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x218,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x218
};

const u16 sSidehopperOAM_Jumping_Frame2[25] = {
    0x8,
    0xde, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xe2, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1e9, OBJ_SPRITE_OAM | 0x210,
    0xf0, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20e,
    0xe1, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x210,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x20e,
    0xe1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x218
};

const u16 sSidehopperOAM_Landing_Frame0[25] = {
    0x8,
    0xdf, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xe5, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xf1, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xe9, 0x1e8, OBJ_SPRITE_OAM | 0x210,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xe9, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x210,
    0xe4, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x21a,
    0xe4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x21a
};

const u16 sSidehopperOAM_ShakingHead_Frame0[19] = {
    0x6,
    0xe9, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x21c,
    0xf0, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x206,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x206,
    0xe6, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x212,
    0xef, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_ShakingHead_Frame1[19] = {
    0x6,
    0xeb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf0, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x206,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x206,
    0xe7, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x212,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_ShakingHead_Frame2[19] = {
    0x6,
    0xeb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xf0, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x206,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x206,
    0xe7, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x212,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const struct FrameData sSidehopperOAM_Idle[5] = {
    sSidehopperOAM_Idle_Frame0,
    0xC,
    sSidehopperOAM_Idle_Frame1,
    0xC,
    sSidehopperOAM_Idle_Frame2,
    0xC,
    sSidehopperOAM_Idle_Frame1,
    0xC,
    NULL,
    0x0
};

const struct FrameData sSidehopperOAM_ShakingHead[9] = {
    sSidehopperOAM_ShakingHead_Frame0,
    0xA,
    sSidehopperOAM_ShakingHead_Frame1,
    0xA,
    sSidehopperOAM_ShakingHead_Frame2,
    0xA,
    sSidehopperOAM_ShakingHead_Frame1,
    0xA,
    sSidehopperOAM_ShakingHead_Frame0,
    0x6,
    sSidehopperOAM_ShakingHead_Frame1,
    0x6,
    sSidehopperOAM_ShakingHead_Frame2,
    0x6,
    sSidehopperOAM_ShakingHead_Frame1,
    0x6,
    NULL,
    0x0
};

const struct FrameData sSidehopperOAM_JumpWarning[6] = {
    sSidehopperOAM_JumpWarning_Frame0,
    0x3,
    sSidehopperOAM_JumpWarning_Frame1,
    0x4,
    sSidehopperOAM_JumpWarning_Frame2,
    0x6,
    sSidehopperOAM_JumpWarning_Frame3,
    0xC,
    sSidehopperOAM_JumpWarning_Frame4,
    0x2,
    NULL,
    0x0
};

const struct FrameData sSidehopperOAM_Jumping[4] = {
    sSidehopperOAM_Jumping_Frame0,
    0x2,
    sSidehopperOAM_Jumping_Frame1,
    0x3,
    sSidehopperOAM_Jumping_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sSidehopperOAM_Landing[7] = {
    sSidehopperOAM_Landing_Frame0,
    0x3,
    sSidehopperOAM_JumpWarning_Frame4,
    0x4,
    sSidehopperOAM_JumpWarning_Frame3,
    0x6,
    sSidehopperOAM_JumpWarning_Frame1,
    0xC,
    sSidehopperOAM_JumpWarning_Frame2,
    0x10,
    sSidehopperOAM_JumpWarning_Frame1,
    0x8,
    NULL,
    0x0
};


/**
 * @brief 3f684 | 20 | Checks if samus is near the dessgeega on the sides in a 5 block range
 * 
 * @return u8 1 if near, 0 otherwise
 */
u8 SidehopperCheckSamusNearLeftRight(void)
{
    u8 result;

    result = FALSE;
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 5, BLOCK_SIZE * 5) != NSLR_OUT_OF_RANGE)
    {
        result = TRUE;
        SpriteUtilMakeSpriteFaceSamusDirection();
    }

    return result;
}

/**
 * @brief 3f6a4 | d0 | Initializes a sidehopper sprite
 * 
 */
void SidehopperInit(void)
{
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + 0x4), gCurrentSprite.xPosition);

    if (gPreviousCollisionCheck & 0xF0)
    {
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
        gCurrentSprite.yPosition -= BLOCK_SIZE;
    }

    gCurrentSprite.timer = 0x0;
    gCurrentSprite.pose = SIDEHOPPER_POSE_IDLE;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        gCurrentSprite.drawDistanceTopOffset = 0x8;
        gCurrentSprite.drawDistanceBottomOffset = 0x28;
        gCurrentSprite.hitboxTopOffset = 0x0;
        gCurrentSprite.hitboxBottomOffset = 0x5C;
    }
    else
    {
        gCurrentSprite.drawDistanceTopOffset = 0x28;
        gCurrentSprite.drawDistanceBottomOffset = 0x8;
        gCurrentSprite.hitboxTopOffset = -0x5C;
        gCurrentSprite.hitboxBottomOffset = 0x0;
    }

    gCurrentSprite.drawDistanceHorizontalOffset = 0x1C;
    gCurrentSprite.hitboxLeftOffset = -0x48;
    gCurrentSprite.hitboxRightOffset = 0x48;

    gCurrentSprite.pOam = sSidehopperOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    SpriteUtilChooseRandomXDirection();
}

/**
 * @brief 3f774 | 50 | Initializes a sidehopper to do the jump warning
 * 
 */
void SidehopperJumpWarningInit(void)
{
    gCurrentSprite.pose = SIDEHOPPER_POSE_JUMP_WARNING;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pOam = sSidehopperOAM_JumpWarning;
}

/**
 * @brief 3f794 | 80 | Initializes a sidehopper to jump
 * 
 */
void SidehopperJumpingInit(void)
{
    gCurrentSprite.pose = SIDEHOPPER_POSE_JUMPING;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.pOam = sSidehopperOAM_Jumping;

    if (gSpriteRNG & 0x1)
        gCurrentSprite.workVariable2 = TRUE;
    else
        gCurrentSprite.workVariable2 = FALSE;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        gCurrentSprite.hitboxBottomOffset = 0x70;
    else
        gCurrentSprite.hitboxTopOffset = -0x70;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(0x17F);
}

/**
 * @brief 3f814 | 50 | Initializes a sidehopper to land
 * 
 */
void SidehopperLandingInit(void)
{
    gCurrentSprite.pose = SIDEHOPPER_POSE_LANDING;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pOam = sSidehopperOAM_Landing;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        gCurrentSprite.hitboxBottomOffset = 0x5C;
    else
        gCurrentSprite.hitboxTopOffset = -0x5C;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(0x180);
}

/**
 * @brief 3f864 | 74 | Initializes a sidehopper to be idle
 * 
 */
void SidehopperIdleInit(void)
{
    if (SidehopperCheckSamusNearLeftRight())
        SidehopperJumpWarningInit();
    else
    {
        gCurrentSprite.pose = SIDEHOPPER_POSE_IDLE;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.timer = 0x0;

        gCurrentSprite.workVariable = gSpriteRNG & 0x3;

        if (gSpriteRNG > 0x7)
            gCurrentSprite.pOam = sSidehopperOAM_Idle;
        else
        {
            gCurrentSprite.pOam = sSidehopperOAM_ShakingHead;
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(0x181);
        }
    }
}

/**
 * @brief 3f8d8 | 24 | Initializes a sidehopper to be falling
 * 
 */
void SidehopperFallingInit(void)
{
    gCurrentSprite.pose = SIDEHOPPER_POSE_FALLING;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.pOam = sSidehopperOAM_Jumping;
}

/**
 * @brief 3f8fc | 5c | Handles a sidehopper doing the jump warning when on the ground
 * 
 */
void SidehopperJumpWarningGround(void)
{
    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SidehopperFallingInit();
                return;
            }
        }
    }
    
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        SidehopperJumpingInit();
}

/**
 * @brief 3f958 | 14 | Handles a sidehopper doing the jump warning when on the ceiling
 * 
 */
void SidehopperJumpWarningCeiling(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        SidehopperJumpingInit();
}

/**
 * @brief 3f96c | 1e8 | Handles a sidehopper jumping when on the ground
 * 
 */
void SidehopperJumpingGround(void)
{
    u8 colliding;
    u8 offset;
    i32 movement;
    u32 blockTop;

    colliding = FALSE;

    if (gCurrentSprite.workVariable2)
        movement = sSidehopperLowJumpVelocity[gCurrentSprite.arrayOffset / 4];
    else
        movement = sSidehopperHighJumpVelocity[gCurrentSprite.arrayOffset / 4];

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset + 0x4);

        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            colliding++;
            gCurrentSprite.xPosition -= 0x6;
        }
        else if (movement > 0x0)
            gCurrentSprite.xPosition += 0x4;
        else
            gCurrentSprite.xPosition += 0x5;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset - 0x4);

        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            colliding++;
            gCurrentSprite.xPosition += 0x6;
        }
        else if (movement > 0x0)
            gCurrentSprite.xPosition -= 0x4;
        else
            gCurrentSprite.xPosition -= 0x5;
    }

    gCurrentSprite.yPosition += movement;
    if (gCurrentSprite.arrayOffset < 0x27)
        gCurrentSprite.arrayOffset++;

    if (movement > 0x0)
    {
        if (colliding)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;

        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            gCurrentSprite.yPosition = blockTop;
            SidehopperLandingInit();
            return;
        }

        if (!colliding)
        {
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                colliding++;
            else
            {
                blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset);
                if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                    colliding++;
            }
    
            if (colliding)
            {
                gCurrentSprite.yPosition = blockTop;
                SidehopperLandingInit();
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTopOffset,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset);

            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                colliding++;
                gCurrentSprite.xPosition -= 0x6;
                SidehopperFallingInit();
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTopOffset,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset);

            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                colliding++;
                gCurrentSprite.xPosition += 0x6;
                SidehopperFallingInit();
            }
        }

        if (colliding)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
    }
}

/**
 * @brief 3fb54 | 1fc | Handles a sidehopper jumping when on the ceiling
 * 
 */
void SidehopperJumpingCeiling(void)
{
    u8 colliding;
    u8 offset;
    i32 movement;
    u32 blockTop;

    colliding = FALSE;

    if (gCurrentSprite.workVariable2)
        movement = sSidehopperLowJumpVelocity[gCurrentSprite.arrayOffset / 4];
    else
        movement = sSidehopperHighJumpVelocity[gCurrentSprite.arrayOffset / 4];

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset + 0x4);

        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            colliding++;
            gCurrentSprite.xPosition -= 0x6;
        }
        else if (movement > 0x0)
            gCurrentSprite.xPosition += 0x4;
        else
            gCurrentSprite.xPosition += 0x5;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset - 0x4);

        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            colliding++;
            gCurrentSprite.xPosition += 0x6;
        }
        else if (movement > 0x0)
            gCurrentSprite.xPosition -= 0x4;
        else
            gCurrentSprite.xPosition -= 0x5;
    }

    gCurrentSprite.yPosition -= movement;
    if (gCurrentSprite.arrayOffset < 0x27)
        gCurrentSprite.arrayOffset++;

    if (movement < 0x0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxBottomOffset,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset);

            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                colliding++;
                gCurrentSprite.xPosition -= 0x6;
                SidehopperFallingInit();
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxBottomOffset,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset);

            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                colliding++;
                gCurrentSprite.xPosition += 0x6;
                SidehopperFallingInit();
            }
        }

        if (colliding)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
    }
    else
    {
        if (colliding)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;

        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck & 0xF)
        {
            gCurrentSprite.yPosition = blockTop + BLOCK_SIZE;
            SidehopperLandingInit();
            return;
        }

        if (!colliding)
        {
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset);
            if (gPreviousVerticalCollisionCheck & 0xF)
                colliding++;
            else
            {
                blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset);
                if (gPreviousVerticalCollisionCheck & 0xF)
                    colliding++;
            }
    
            if (colliding)
            {
                gCurrentSprite.yPosition = blockTop + BLOCK_SIZE;
                SidehopperLandingInit();
            }
        }
    }
}

/**
 * @brief 3fd50 | 14 | Checks if the landing animation as ended
 * 
 */
void SidehopperCheckLandingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        SidehopperIdleInit();
}

/**
 * @brief 3fd64 | a4 | Handles a dessgeega falling from the ground
 * 
 */
void SidehopperFallingGround(void)
{
    u8 colliding;
    u32 blockTop;
    u8 offset;
    i32 movement;

    colliding = FALSE;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        colliding++;
    else
    {
        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            colliding++;
        else
        {
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                colliding++;
        }
    }

    if (colliding)
    {
        gCurrentSprite.yPosition = blockTop;
        SidehopperLandingInit();
    }
    else
    {
        offset = gCurrentSprite.arrayOffset;
        movement = sSpritesFallingSpeed[offset];

        if (movement == SPRITE_ARRAY_TERMINATOR)
        {
            movement = sSpritesFallingSpeed[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            gCurrentSprite.arrayOffset++;
            gCurrentSprite.yPosition += movement;
        }
    }
}

/**
 * @brief 3fe08 | a8 | Handles a dessgeega falling from the ceiling
 * 
 */
void SidehopperFallingCeiling(void)
{
    u8 colliding;
    u32 blockTop;
    u8 offset;
    i32 movement;

    colliding = FALSE;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        colliding++;
    else
    {
        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            colliding++;
        else
        {
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                colliding++;
        }
    }

    if (colliding)
    {
        gCurrentSprite.yPosition = blockTop + BLOCK_SIZE;
        SidehopperLandingInit();
    }
    else
    {
        offset = gCurrentSprite.arrayOffset;
        movement = sSpritesFallingCeilingSpeed[offset];

        if (movement == SPRITE_ARRAY_TERMINATOR)
        {
            movement = sSpritesFallingCeilingSpeed[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            gCurrentSprite.arrayOffset++;
            gCurrentSprite.yPosition += movement;
        }
    }
}

/**
 * @brief 3feb0 | 9c | Handles a sidehopper being idle on the ground
 * 
 */
void SidehopperIdleGround(void)
{
    if (SidehopperCheckSamusNearLeftRight())
        SidehopperJumpWarningInit();
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SidehopperFallingInit();
                return;
            }
        }

        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            if (gCurrentSprite.timer++ == gCurrentSprite.workVariable)
                SidehopperJumpWarningInit();
            else
            {
                if (gCurrentSprite.pOam == sSidehopperOAM_ShakingHead && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(0x181);
            }
        }
    }
}

/**
 * @brief 3ff4c | 5c | Handles a sidehopper being idle on the ceiling
 * 
 */
void SidehopperIdleCeiling(void)
{
    if (SidehopperCheckSamusNearLeftRight())
        SidehopperJumpWarningInit();
    else
    {
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            if (gCurrentSprite.timer++ == gCurrentSprite.workVariable)
                SidehopperJumpWarningInit();
            else
            {
                if (gCurrentSprite.pOam == sSidehopperOAM_ShakingHead && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(0x181);
            }
        }
    }
}

/**
 * @brief 3ffa8 | 38 | Handles the death of a sidehopper
 * 
 */
void SidehopperDeath(void)
{
    u16 yPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        yPosition = gCurrentSprite.yPosition + 0x34;
    else
        yPosition = gCurrentSprite.yPosition - 0x34;

    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
}

/**
 * @brief 3ffe0 | 198 | Sidehopper AI
 * 
 */
void Sidehopper(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x182);
    }

    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;

        switch (gCurrentSprite.pose)
        {
            case 0x0:
                SidehopperInit();
                break;

            case SIDEHOPPER_POSE_JUMP_WARNING_INIT:
                SidehopperJumpWarningInit();

            case SIDEHOPPER_POSE_JUMP_WARNING:
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                    SidehopperJumpWarningCeiling();
                else
                    SidehopperJumpWarningGround();
                break;

            case SIDEHOPPER_POSE_JUMPING:
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                    SidehopperJumpingCeiling();
                else
                    SidehopperJumpingGround();
                break;

            case SIDEHOPPER_POSE_LANDING:
                SidehopperCheckLandingAnimEnded();
                break;

            case SIDEHOPPER_POSE_IDLE:
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                    SidehopperIdleCeiling();
                else
                    SidehopperIdleGround();
                break;

            case SIDEHOPPER_POSE_FALLING:
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                    SidehopperFallingCeiling();
                else
                    SidehopperFallingGround();
                break;

            default:
                SidehopperDeath();
        }
    }
}