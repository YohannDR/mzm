#include "holtz.h"
#include "../../data/data.h"
#include "../globals.h"

const i16 sHoltzIdleYVelocity[65] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 2, 2, 1, 1,
    1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0,
    -1, 0, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0,
    -1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0, SPRITE_ARRAY_TERMINATOR
};

const u32 sHoltzGFX[200];
const u16 sHoltzPAL[16];

const u16 sHoltzOAM_Idle_Frame0[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0x1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x23c
};

const u16 sHoltzOAM_Idle_Frame1[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x200,
    0x1, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x9, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21e
};

const u16 sHoltzOAM_Idle_Frame2[16] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x200,
    0x2, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x9, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21c
};

const u16 sHoltzOAM_Idle_Frame3[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x2, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xa, 0x1f8, OBJ_SPRITE_OAM | 0x22a,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21e
};

const u16 sHoltzOAM_Warning_Frame1[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1f8, OBJ_SPRITE_OAM | 0x224,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1f8, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x23c
};

const u16 sHoltzOAM_Warning_Frame2[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1f8, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21e
};

const u16 sHoltzOAM_Warning_Frame3[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21c
};

const u16 sHoltzOAM_Warning_Frame4[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21a
};

const u16 sHoltzOAM_Warning_Frame5[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c
};

const u16 sHoltzOAM_Warning_Frame6[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21c
};

const u16 sHoltzOAM_Warning_Frame7[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x8, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21a
};

const u16 sHoltzOAM_Warning_Frame8[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x3, 0x1f8, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xb, 0x1f8, OBJ_SPRITE_OAM | 0x224,
    OBJ_SHAPE_HORIZONTAL | 0xff, 0x8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21c
};

const u16 sHoltzOAM_GoingDown_Frame0[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x7, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c
};

const u16 sHoltzOAM_GoingDown_Frame1[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x8, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x210
};

const u16 sHoltzOAM_IdleAware_Frame2[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0x5, 0x1fc, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x23c
};

const u16 sHoltzOAM_GoingUp_Frame2[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0x7, 0x1fc, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x23c
};

const u16 sHoltzOAM_GoingUp_Frame1[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1f8, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_VERTICAL | 0x6, 0x1fc, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x23c
};

const u16 sHoltzOAM_GoingUp_Frame0[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x22a,
    OBJ_SHAPE_VERTICAL | 0x5, 0x1fc, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x23c
};

const struct FrameData sHoltzOAM_Idle[5] = {
    sHoltzOAM_Idle_Frame0,
    0xC,
    sHoltzOAM_Idle_Frame1,
    0xC,
    sHoltzOAM_Idle_Frame2,
    0xC,
    sHoltzOAM_Idle_Frame3,
    0xC,
    NULL,
    0x0
};

const struct FrameData sHoltzOAM_Warning[10] = {
    sHoltzOAM_Idle_Frame0,
    0x5,
    sHoltzOAM_Warning_Frame1,
    0x4,
    sHoltzOAM_Warning_Frame2,
    0x3,
    sHoltzOAM_Warning_Frame3,
    0x4,
    sHoltzOAM_Warning_Frame4,
    0x5,
    sHoltzOAM_Warning_Frame5,
    0x5,
    sHoltzOAM_Warning_Frame6,
    0x5,
    sHoltzOAM_Warning_Frame7,
    0x5,
    sHoltzOAM_Warning_Frame8,
    0x5,
    NULL,
    0x0
};

const struct FrameData sHoltzOAM_GoingDown[3] = {
    sHoltzOAM_GoingDown_Frame0,
    0x4,
    sHoltzOAM_GoingDown_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sHoltzOAM_IdleAware[4] = {
    sHoltzOAM_GoingDown_Frame0,
    0x5,
    sHoltzOAM_Warning_Frame4,
    0x5,
    sHoltzOAM_IdleAware_Frame2,
    0x5,
    NULL,
    0x0
};

const struct FrameData sHoltzOAM_GoingUp[8] = {
    sHoltzOAM_GoingUp_Frame0,
    0x2,
    sHoltzOAM_GoingUp_Frame1,
    0x2,
    sHoltzOAM_GoingUp_Frame2,
    0x2,
    sHoltzOAM_GoingUp_Frame0,
    0x2,
    sHoltzOAM_GoingUp_Frame1,
    0x2,
    sHoltzOAM_GoingUp_Frame2,
    0x2,
    sHoltzOAM_IdleAware_Frame2,
    0x4,
    NULL,
    0x0
};

const struct FrameData sHoltzOAM_BonkingOnCeiling[10] = {
    sHoltzOAM_IdleAware_Frame2,
    0x5,
    sHoltzOAM_Warning_Frame4,
    0x5,
    sHoltzOAM_Warning_Frame3,
    0x4,
    sHoltzOAM_Warning_Frame2,
    0x3,
    sHoltzOAM_Warning_Frame1,
    0x4,
    sHoltzOAM_Warning_Frame7,
    0x5,
    sHoltzOAM_Warning_Frame6,
    0x3,
    sHoltzOAM_Warning_Frame5,
    0x3,
    sHoltzOAM_Idle_Frame0,
    0x3,
    NULL,
    0x0
};


/**
 * @brief 3830c | cc | Handles the Y movement of a holtz
 * 
 * @param movement Y movement
 * @return u8 1 if colliding with solid, 0 otherwise
 */
u8 HoltzYMovement(u16 movement)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        // Going down
        // Middle block
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        // Left block
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition - 0x30);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        // Right block
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition + 0x30);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.yPosition += movement;
        return FALSE;
    }
    else
    {
        // Going up
        // Check on left
        // Middle left block
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HOLTZ_SIZE, gCurrentSprite.xPosition - 0x30);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            // Far left block
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HOLTZ_SIZE, gCurrentSprite.xPosition - 0x70);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                return TRUE;
        }

        // Check on right
        // Middle right block
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HOLTZ_SIZE, gCurrentSprite.xPosition + 0x30);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            // Far right block
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HOLTZ_SIZE, gCurrentSprite.xPosition + 0x70);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                return TRUE;
        }

        gCurrentSprite.yPosition -= movement;
        return FALSE;
    }
}

/**
 * @brief 383d8 | 8c | Handles the X movement of a holtz
 * 
 * @param movement X movement
 * @return u8 1 if colliding with solid, 0 otherwise
 */
u8 HoltzXMovement(u16 movement)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE / 2), gCurrentSprite.xPosition + BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;


        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + (BLOCK_SIZE / 2), gCurrentSprite.xPosition + BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.xPosition += movement;
        return FALSE;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE / 2), gCurrentSprite.xPosition - BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;


        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + (BLOCK_SIZE / 2), gCurrentSprite.xPosition - BLOCK_SIZE);
        if (gPreviousCollisionCheck != COLLISION_SOLID)
        {
            gCurrentSprite.xPosition -= movement;            
            return FALSE;
        }
        else
            return TRUE;
    }
}

/**
 * @brief 38518 | 70 | Initializes a holtz sprite
 * 
 */
void HoltzInit(void)
{
    SpriteUtilMakeSpriteFaceSamusDirection();
    gCurrentSprite.drawDistanceTopOffset = 0xC;
    gCurrentSprite.drawDistanceBottomOffset = 0x18;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

    gCurrentSprite.hitboxTopOffset = -0x20;
    gCurrentSprite.hitboxBottomOffset = 0x20;
    gCurrentSprite.hitboxLeftOffset = -0x28;
    gCurrentSprite.hitboxRightOffset = 0x28;

    gCurrentSprite.pOam = sHoltzOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.pose = HOLTZ_POSE_IDLE_INIT;
    gCurrentSprite.arrayOffset = 0x0;
}

/**
 * @brief 384dc | 3c | Initializes a holtz to be idle
 * 
 */
void HoltzIdleInit(void)
{
    gCurrentSprite.pose = HOLTZ_POSE_IDLE;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    // Set OAM based on samus position
    if ((i32)(gSamusData.yPosition - 0x48) < gCurrentSprite.yPosition)
        gCurrentSprite.pOam = sHoltzOAM_IdleAware;
    else
        gCurrentSprite.pOam = sHoltzOAM_Idle;
}

/**
 * @brief 38518 | 70 | Handles a holtz being idle
 * 
 */
void HoltzIdle(void)
{
    i32 movement;
    u8 offset;
    u8 nslr;

    // Y idle movement
    offset = gCurrentSprite.arrayOffset;
    movement = sHoltzIdleYVelocity[offset];
    if (movement == SPRITE_ARRAY_TERMINATOR)
    {
        movement = sHoltzIdleYVelocity[0]; // 0
        offset = 0x0;
    }
    gCurrentSprite.arrayOffset = offset + 0x1;
    gCurrentSprite.yPosition += movement;

    // Detect samus
    if ((i32)(gSamusData.yPosition - 0x48) >= gCurrentSprite.yPosition)
    {
        nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 8, BLOCK_SIZE * 5);
        if (nslr == NSLR_RIGHT || nslr == NSLR_LEFT)
            gCurrentSprite.pose = HOLTZ_POSE_WARNING_INIT;
    }
}

/**
 * @brief 38588 | 20 | Initializes a holtz to do the warning
 * 
 */
void HoltzWarningInit(void)
{
    gCurrentSprite.pose = HOLTZ_POSE_WARNING;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pOam = sHoltzOAM_Warning;
}

/**
 * @brief 385a8 | 90 | Checks if the warning animation has ended
 * 
 */
void HoltzCheckWarningAnimEnded(void)
{
    i16 offset;
    i32 movement;

    // Y idle movement
    offset = gCurrentSprite.arrayOffset;
    movement = sHoltzIdleYVelocity[offset];
    if (movement == SPRITE_ARRAY_TERMINATOR)
    {
        movement = sHoltzIdleYVelocity[0]; // 0
        offset = 0x0;
    }
    gCurrentSprite.arrayOffset = offset + 0x1;
    gCurrentSprite.yPosition += movement;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set going down behavior
        gCurrentSprite.pose = HOLTZ_POSE_GOING_DOWN;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pOam = sHoltzOAM_GoingDown;
        // Set going down flag (they could've used the facing down flag?)
        gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
        SpriteUtilMakeSpriteFaceSamusDirection();
        gCurrentSprite.timer = 0x0;
        gCurrentSprite.workVariable2 = 0x2; // Initial X speed
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x186);
    }
}

/**
 * @brief 38638 | 60 | Handles the holtz going down
 * 
 */
void HoltzGoingDownMove(void)
{
    // Gradually increase X movement
    gCurrentSprite.timer++;
    if (gCurrentSprite.workVariable2 < 0xC && !(gCurrentSprite.timer & 0x1))
        gCurrentSprite.workVariable2++;

    HoltzXMovement(gCurrentSprite.workVariable2);
    if (HoltzYMovement(0xC)) // Y movement
    {
        // Touched ground, set sliding behavior
        gCurrentSprite.pose = HOLTZ_POSE_SLIDING;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pOam = sHoltzOAM_IdleAware;
    }
}

/**
 * @brief 38698 | 4c | Handles the holtz sliding on the ground
 * 
 */
void HoltzSlidingMove(void)
{
    HoltzXMovement(gCurrentSprite.workVariable2); // X Movement

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set going up behavior
        gCurrentSprite.pose = HOLTZ_POSE_GOING_UP;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pOam = sHoltzOAM_GoingUp;
        // Remove going down flag
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        gCurrentSprite.timer = 0x0;
    }
}

/**
 * @brief 386e4 | 9c | Handles the holtz moving up
 * 
 */
void HoltzGoingUpMove(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN &&
        (gCurrentSprite.currentAnimationFrame == 0x0 || gCurrentSprite.currentAnimationFrame == 0x3)
        && gCurrentSprite.animationDurationCounter == 0x1)
    {
        SoundPlayNotAlreadyPlaying(0x187);
    }

    // Gradually decrease X movement
    gCurrentSprite.timer++;
    if (gCurrentSprite.workVariable2 > 0x2 && !(gCurrentSprite.timer & 0x1))
        gCurrentSprite.workVariable2--;

    HoltzXMovement(gCurrentSprite.workVariable2); // X movement
    if (HoltzYMovement(0xC)) // Y movement
    {
        // Touching ceiling, set bonking behavior
        gCurrentSprite.yPosition &= 0xFFC0; // Clear subpixel
        gCurrentSprite.yPosition += HOLTZ_SIZE; // Offset with size of holtz
        gCurrentSprite.pose = HOLTZ_POSE_BACK_TO_CEILING;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pOam = sHoltzOAM_BonkingOnCeiling;
        gCurrentSprite.arrayOffset = 0x0;
    }
}

/**
 * @brief 38780 | 50 | Handles the holtz being back on the ceiling
 * 
 */
void HoltzBackToCeiling(void)
{
    i32 movement;
    u8 offset;

    // Y idle movement
    offset = gCurrentSprite.arrayOffset;
    movement = sHoltzIdleYVelocity[offset];
    if (movement == SPRITE_ARRAY_TERMINATOR)
    {
        movement = sHoltzIdleYVelocity[0]; // 0
        offset = 0x0;
    }
    gCurrentSprite.arrayOffset = offset + 0x1;
    gCurrentSprite.yPosition += movement;

    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = HOLTZ_POSE_IDLE_INIT; // Set idle
}

/**
 * @brief 387d0 | 1ac | Holtz AI
 * 
 */
void Holtz(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x188);
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
                HoltzInit();
                break;

            case HOLTZ_POSE_IDLE_INIT:
                HoltzIdleInit();
                break;

            case HOLTZ_POSE_IDLE:
                HoltzIdle();
                break;

            case HOLTZ_POSE_WARNING_INIT:
                HoltzWarningInit();
            
            case HOLTZ_POSE_WARNING:
                HoltzCheckWarningAnimEnded();
                break;

            case HOLTZ_POSE_GOING_DOWN:
                HoltzGoingDownMove();
                break;

            case HOLTZ_POSE_SLIDING:
                HoltzSlidingMove();
                break;

            case HOLTZ_POSE_GOING_UP:
                HoltzGoingUpMove();
                break;

            case HOLTZ_POSE_BACK_TO_CEILING:
                HoltzBackToCeiling();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
        }
    }
}