#include "morph_ball.h"
#include "../globals.h"
#include "item_banner.h"

const u32 sMorphBallGFX[168];
const u16 sMorphBallPAL[16];

const u16 sMorphBallOAM_Idle_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sMorphBallOAM_Idle_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sMorphBallOAM_Idle_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sMorphBallOutsideOAM_Idle_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sMorphBallOutsideOAM_Idle_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sMorphBallOutsideOAM_Idle_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sMorphBallOutsideOAM_Idle_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

const u16 sMorphBallOutsideOAM_Idle_Frame4[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

const struct FrameData sMorphBallOAM_Idle[5] = {
    sMorphBallOAM_Idle_Frame0,
    0x10,
    sMorphBallOAM_Idle_Frame1,
    0x10,
    sMorphBallOAM_Idle_Frame2,
    0x10,
    sMorphBallOAM_Idle_Frame1,
    0x10,
    NULL,
    0x0
};

const struct FrameData sMorphBallOutsideOAM_Idle[6] = {
    sMorphBallOutsideOAM_Idle_Frame0,
    0x64,
    sMorphBallOutsideOAM_Idle_Frame1,
    0x3,
    sMorphBallOutsideOAM_Idle_Frame2,
    0x6,
    sMorphBallOutsideOAM_Idle_Frame3,
    0x4,
    sMorphBallOutsideOAM_Idle_Frame4,
    0x3,
    NULL,
    0x0
};


/**
 * @brief 13080 | ac | Initializes a morph ball sprite
 * 
 */
void MorphBallInit(void)
{
    if (gEquipment.suitMisc & SMF_MORPH_BALL)
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
        gCurrentSprite.hitboxTopOffset = -0x1C;
        gCurrentSprite.hitboxBottomOffset = 0x1C;
        gCurrentSprite.hitboxLeftOffset = -0x1C;
        gCurrentSprite.hitboxRightOffset = 0x1C;

        gCurrentSprite.drawDistanceTopOffset = 0x8;
        gCurrentSprite.drawDistanceBottomOffset = 0x8;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

        gCurrentSprite.pOam = sMorphBallOAM_Idle;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;
        gCurrentSprite.health = 0x1;
        gCurrentSprite.yPosition -= (HALF_BLOCK_SIZE);
        gCurrentSprite.pose = MORPH_BALL_POSE_IDLE;
        gCurrentSprite.drawOrder = 0x3;

        // Spawn outside
        SpriteSpawnSecondary(SSPRITE_MORPH_BALL_OUTSIDE, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 1312c | 74 | Handles a morph ball sprite being idle
 * 
 */
void MorphBallGet(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gPreventMovementTimer = 0x3E8;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        gCurrentSprite.pose = MORPH_BALL_POSE_BEING_ACQUIRED;
        gCurrentSprite.timer = 0x0;
        gEquipment.suitMisc |= SMF_MORPH_BALL;
        SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_MORPH_BALL, 0xC, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 131a0 | 3c | Handles a morph ball being acquired
 * 
 */
void MorphBallFlashAnim(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (!(gCurrentSprite.timer & 0x1))
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    if (gPreventMovementTimer < 0x3E7)
        gCurrentSprite.status = 0x0;
}

/**
 * @brief 131dc | 58 | Initializes a morph ball outside sprite
 * 
 */
void MorphBallOutsideInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;

    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

    gCurrentSprite.pOam = sMorphBallOutsideOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawOrder = 0x2;
    gCurrentSprite.pose = 0x9;
}

/**
 * @brief 13234 | 3c | Handles a morph ball outside being acquired 
 * 
 */
void MorphBallOutsideFlashAnim(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    gCurrentSprite.status = gSpriteData[ramSlot].status;
    if (gSpriteData[ramSlot].properties & SP_ALWAYS_ACTIVE)
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
}

/**
 * @brief 13270 | 38 | Morph ball AI
 * 
 */
void MorphBall(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            MorphBallInit();
            break;
        case MORPH_BALL_POSE_IDLE:
            MorphBallGet();
            break;
        case MORPH_BALL_POSE_BEING_ACQUIRED:
            MorphBallFlashAnim();
    }
}

/**
 * @brief 132a8 | 2c | Morph ball outside AI
 * 
 */
void MorphBallOutside(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            MorphBallOutsideInit();
        case 0x9:
            MorphBallOutsideFlashAnim();
    }
}