#include "geruta.h"
#include "../../data/data.h"
#include "../globals.h"

const u32 sGerutaRedGFX[321];
const u16 sGerutaRedPAL[16];
const u16 sGerutaGreenGFX[308];
const u16 sGerutaGreenPAL[16];

const u16 sGerutaOAM_Idle_Frame0[16] = {
    0x5,
    0xf5, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf6, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x208,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x208,
    0xf9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x212,
    0xfa, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x212
};

const u16 sGerutaOAM_Idle_Frame1[16] = {
    0x5,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x208,
    0xf5, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x208,
    0xf9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x212,
    0xfa, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212
};

const u16 sGerutaOAM_Warning_Frame1[16] = {
    0x5,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xf5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x208,
    0xf6, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x208,
    0xfb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x212,
    0xfb, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x212
};

const u16 sGerutaOAM_Warning_Frame2[16] = {
    0x5,
    0xf3, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x20a,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20a,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xfb, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x210,
    0xfa, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x210
};

const u16 sGerutaOAM_Launching_Frame0[16] = {
    0x5,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xfd, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x20a,
    0xf6, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20a
};

const u16 sGerutaOAM_Launching_Frame1[16] = {
    0x5,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xfa, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xfa, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x20a,
    0xf7, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20a
};

const u16 sGerutaOAM_Launching_Frame2[16] = {
    0x5,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20c,
    0xf7, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20c,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xf3, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xf3, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212
};

const u16 sGerutaOAM_Launching_Frame3[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xf3, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20c
};

const u16 sGerutaOAM_GoingDown_Frame0[28] = {
    0x9,
    0xf2, OBJ_Y_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x21b,
    0xf2, OBJ_Y_FLIP | 0x3, OBJ_SPRITE_OAM | 0x21b,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xfc, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x20c,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x20a,
    0xfc, 0x1f5, OBJ_SPRITE_OAM | 0x213,
    0xfd, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x213,
    0xf4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x214,
    0xf4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x214
};

const u16 sGerutaOAM_GoingDown_Frame1[25] = {
    0x8,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xfc, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x20c,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x20a,
    0xfd, 0x1f5, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_Y_FLIP | 0x3, OBJ_SPRITE_OAM | 0x21c,
    0xf4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x214,
    0xf4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x214
};

const u16 sGerutaOAM_GoingDown_Frame2[22] = {
    0x7,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xfc, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x20c,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x20a,
    0xfc, 0x1f5, OBJ_SPRITE_OAM | 0x213,
    0xfe, OBJ_X_FLIP | 0x2, OBJ_SPRITE_OAM | 0x213,
    0xf4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x214,
    0xf4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fd, OBJ_SPRITE_OAM | 0x214
};

const u16 sGerutaOAM_GoingDown_Frame3[25] = {
    0x8,
    0xf0, OBJ_Y_FLIP | 0x2, OBJ_SPRITE_OAM | 0x23b,
    0xf1, OBJ_Y_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x23b,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xfd, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20c,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20a,
    0xfd, 0x1f4, OBJ_SPRITE_OAM | 0x213,
    0xf2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fd, OBJ_SPRITE_OAM | 0x214,
    0xf3, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x214
};

const u16 sGerutaOAM_Bouncing_Frame0[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xfa, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20c,
    0xf9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20a,
    0xfc, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x212
};

const u16 sGerutaOAM_Bouncing_Frame1[22] = {
    0x7,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x20a,
    0xf7, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20a,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0x8, 0x1f3, OBJ_SPRITE_OAM | 0x23b,
    0x8, 0x6, OBJ_SPRITE_OAM | 0x23b,
    0xfd, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x210,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x210
};

const u16 sGerutaOAM_GoingUp_Frame0[22] = {
    0x7,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20a,
    0xf7, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x20a,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xff, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xfe, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    0x9, 0x1f4, OBJ_SPRITE_OAM | 0x21b,
    0xa, 0x4, OBJ_SPRITE_OAM | 0x21b
};

const u16 sGerutaOAM_GoingUp_Frame1[22] = {
    0x7,
    0xf9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x20a,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xfd, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0x6, 0x3, OBJ_SPRITE_OAM | 0x21c
};

const u16 sGerutaOAM_GoingUp_Frame2[22] = {
    0x7,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20a,
    0xf7, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x20a,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xff, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xfe, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0x9, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xa, 0x3, OBJ_SPRITE_OAM | 0x21d
};

const u16 sGerutaOAM_GoingUp_Frame3[22] = {
    0x7,
    0xf9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x20a,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xfd, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    0x9, 0x1f5, OBJ_SPRITE_OAM | 0x23b,
    0x9, 0x3, OBJ_SPRITE_OAM | 0x23b
};

const u16 sGerutaOAM_BouncingOnCeiling_Frame0[16] = {
    0x5,
    0xf6, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x20c,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x20c,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xfb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xfa, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212
};

const u16 sGerutaOAM_BouncingOnCeiling_Frame1[16] = {
    0x5,
    0xf7, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20a,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x20a,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x212,
    0xfb, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x212
};

const struct FrameData sGerutaOAM_Idle[3] = {
    sGerutaOAM_Idle_Frame0,
    0xC,
    sGerutaOAM_Idle_Frame1,
    0xC,
    NULL,
    0x0
};

const struct FrameData sGerutaOAM_Warning[4] = {
    sGerutaOAM_Idle_Frame0,
    0x4,
    sGerutaOAM_Warning_Frame1,
    0x8,
    sGerutaOAM_Warning_Frame2,
    0x10,
    NULL,
    0x0
};

const struct FrameData sGerutaOAM_Launching[5] = {
    sGerutaOAM_Launching_Frame0,
    0x6,
    sGerutaOAM_Launching_Frame1,
    0x6,
    sGerutaOAM_Launching_Frame2,
    0x6,
    sGerutaOAM_Launching_Frame3,
    0x6,
    NULL,
    0x0
};

const struct FrameData sGerutaOAM_GoingDown[5] = {
    sGerutaOAM_GoingDown_Frame0,
    0x3,
    sGerutaOAM_GoingDown_Frame1,
    0x3,
    sGerutaOAM_GoingDown_Frame2,
    0x3,
    sGerutaOAM_GoingDown_Frame3,
    0x3,
    NULL,
    0x0
};

const struct FrameData sGerutaOAM_Bouncing[3] = {
    sGerutaOAM_Bouncing_Frame0,
    0x6,
    sGerutaOAM_Bouncing_Frame1,
    0x6,
    NULL,
    0x0
};

const struct FrameData sGerutaOAM_GoingUp[5] = {
    sGerutaOAM_GoingUp_Frame0,
    0x2,
    sGerutaOAM_GoingUp_Frame1,
    0x2,
    sGerutaOAM_GoingUp_Frame2,
    0x2,
    sGerutaOAM_GoingUp_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sGerutaOAM_BouncingOnCeiling[3] = {
    sGerutaOAM_BouncingOnCeiling_Frame0,
    0x8,
    sGerutaOAM_BouncingOnCeiling_Frame1,
    0x8,
    NULL,
    0x0
};


/**
 * @brief 1ea68 | b0 | Handles the Y movement of a geruta
 * 
 * @param movement Y movement
 * @return u8 1 if hitting solid, 0 otherwise
 */
u8 GerutaYMovement(u16 movement)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition) == COLLISION_SOLID ||
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE * 3) == COLLISION_SOLID ||
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE * 3) == COLLISION_SOLID)
            return TRUE;
        gCurrentSprite.yPosition += movement;
    }
    else
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE * 3) == COLLISION_SOLID &&
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE * 3)) == COLLISION_SOLID)
            return TRUE;

        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE * 3) == COLLISION_SOLID &&
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE * 3)) == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.yPosition -= movement;
    }

    return FALSE;
}

/**
 * @brief 1eb18 | 74 | Handles the X movement of a geruta
 * 
 * @param movement X movement
 * @return u8 1 if hitting solid, 0 otherwise
 */
u8 GerutaXMovement(u16 movement)
{
    i16 negMovement;

    negMovement = movement;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition + BLOCK_SIZE) == COLLISION_SOLID ||
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition + BLOCK_SIZE) == COLLISION_SOLID)
            return TRUE;
        gCurrentSprite.xPosition += movement;
    }
    else
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition - BLOCK_SIZE) == COLLISION_SOLID ||
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition - BLOCK_SIZE) == COLLISION_SOLID)
            return TRUE;
        gCurrentSprite.xPosition -= negMovement;
    }
    
    return FALSE;
}

/**
 * @brief 1eb8c | 80 | Initializes a geruta sprite
 * 
 */
void GerutaInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    SpriteUtilMakeSpriteFaceSamusDirection();

    gCurrentSprite.drawDistanceTopOffset = 0x18;
    gCurrentSprite.drawDistanceBottomOffset = 0x18;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

    gCurrentSprite.hitboxTopOffset = -0x20;
    gCurrentSprite.hitboxBottomOffset = 0x20;
    gCurrentSprite.hitboxLeftOffset = -0x30;
    gCurrentSprite.hitboxRightOffset = 0x30;

    gCurrentSprite.pOam = sGerutaOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.yPosition -= 0xC;
    gCurrentSprite.pose = GERUTA_POSE_IDLE_INIT;
}

/**
 * @brief 1ec0c | 20 | Initializes a geruta sprite to be idle
 * 
 */
void GerutaIdleInit(void)
{
    gCurrentSprite.pose = GERUTA_POSE_IDLE;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pOam = sGerutaOAM_Idle;
}

/**
 * @brief 1ec2c | 6c | Handles a geruta detecting samus
 * 
 */
void GerutaDetectSamus(void)
{
    u8 nslr;

    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE * 3) != COLLISION_SOLID &&
        SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE * 3) != COLLISION_SOLID)
    {
        SpriteUtilMakeSpriteFaceSamusDirection();
        gCurrentSprite.pose = GERUTA_POSE_WARNING_INIT;

    }
    else if ((gSamusData.yPosition - 0x48) >= gCurrentSprite.yPosition)
    {
        nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 5, BLOCK_SIZE * 5);

        if (nslr == NSLR_RIGHT || nslr == NSLR_LEFT)
            gCurrentSprite.pose = GERUTA_POSE_WARNING_INIT;
    }
}

/**
 * @brief 1ec98 | 34 | Initializes a geruta to do the warning
 * 
 */
void GerutaWarningInit(void)
{
    gCurrentSprite.pose = GERUTA_POSE_WARNING;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pOam = sGerutaOAM_Warning;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(0x150);
}

/**
 * @brief 1eccc | 2c | Checks if the warning has ended
 * 
 */
void GerutaCheckWarningEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = GERUTA_POSE_LAUNCHING;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pOam = sGerutaOAM_Launching;
    }
}

/**
 * @brief 1ecf8 | 50 | Checks if the launching animation has ended
 * 
 */
void GerutaCheckLaunchingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = GERUTA_POSE_GOING_DOWN;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pOam = sGerutaOAM_GoingDown;
        gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;

        SpriteUtilMakeSpriteFaceSamusDirection();
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x14E);
    }
}

/**
 * @brief 1ed48 | 44 | Handles a geruta going down
 * 
 */
void GerutaGoingDown(void)
{
    u16 oldY;

    oldY = gCurrentSprite.yPosition;
    GerutaXMovement(0x4);
    if (GerutaYMovement(0xC))
    {
        gCurrentSprite.pose = GERUTA_POSE_BOUNCING;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pOam = sGerutaOAM_Bouncing;
    }

    SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_BIG);
}

/**
 * @brief 1ed8c | 48 | Checks if the bouning animation has ended
 * 
 */
void GerutaCheckBouncingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = GERUTA_POSE_GOING_UP;

        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pOam = sGerutaOAM_GoingUp;

        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        if ((gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
            SoundPlayNotAlreadyPlaying(0x14F);
    }
}

/**
 * @brief 1edd4 | 48 | Handles a geruta going up
 * 
 */
void GerutaGoingUp(void)
{
    GerutaXMovement(0x4);
    if (GerutaYMovement(0xC))
    {
        gCurrentSprite.yPosition = (gCurrentSprite.yPosition & BLOCK_POSITION_FLAG);
        gCurrentSprite.yPosition  += 0x34;
        gCurrentSprite.pose = GERUTA_POSE_BOUNCING_ON_CEILING;

        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pOam = sGerutaOAM_BouncingOnCeiling;
    }
}

/**
 * @brief 1ee1c | 1c | Checks if the bouncing on ceiling animation ended
 * 
 */
void GerutaCheckBouncingOnCeilingAnimEnded(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = GERUTA_POSE_IDLE_INIT;
}

/**
 * @brief 1ee38 | 1bc | Geruta AI
 * 
 */
void Geruta(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x151);
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
                GerutaInit();
                break;

            case GERUTA_POSE_IDLE_INIT:
                GerutaIdleInit();

            case GERUTA_POSE_IDLE:
                GerutaDetectSamus();
                break;

            case GERUTA_POSE_WARNING_INIT:
                GerutaWarningInit();

            case GERUTA_POSE_WARNING:
                GerutaCheckWarningEnded();
                break;

            case GERUTA_POSE_LAUNCHING:
                GerutaCheckLaunchingAnimEnded();
                break;

            case GERUTA_POSE_GOING_DOWN:
                GerutaGoingDown();
                break;

            case GERUTA_POSE_BOUNCING:
                GerutaCheckBouncingAnimEnded();
                break;

            case GERUTA_POSE_GOING_UP:
                GerutaGoingUp();
                break;

            case GERUTA_POSE_BOUNCING_ON_CEILING:
                GerutaCheckBouncingOnCeilingAnimEnded();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
        }
    }
}