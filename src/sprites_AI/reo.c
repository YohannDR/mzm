#include "reo.h"
#include "../../data/data.h"
#include "../globals.h"

const i16 sReoIdleYMovement[65] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1,
    1, 2, 2, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, 0, -1,
    0, 1, 0, -1, 1, -1, -2, 2, -1, -1, 1, 0,
    -1, 0, -1, 0, 1, 0, -1, 0, 0, 0, 0, SHORT_MAX
};

const i16 sReoIdleXMovement[81] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1,
    1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1,
    0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, -1,
    -1, -1, -1, -1, -2, -2, -2, -2, -1, -1,
    -1, -1, -1, -1, 0, -1, 0, -1, 0, -1, 0,
    -1, 0, 0, 0, 0, SHORT_MAX
};

const u32 sReoGFX[277];
const u16 sReoPAL[16];
const u32 sReoPurpleWingsGFX[277];
const u16 sReoPurpleWingsPAL[16];

const u16 sReoOAM_Idle_Frame0[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_Idle_Frame1[13] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    0xee, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x204,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_Idle_Frame2[13] = {
    0x4,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ea, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_Moving_Unused_Frame0[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_Moving_Unused_Frame1[13] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    0xee, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x204,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_Moving_Unused_Frame2[13] = {
    0x4,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1eb, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x5, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_UnusedFrame[13] = {
    0x4,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1eb, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x5, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_Idle_Unused_Frame0[10] = {
    0x3,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sReoOAM_Idle_Unused_Frame1[13] = {
    0x4,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xef, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x204,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_Idle_Unused_Frame2[13] = {
    0x4,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ea, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

const u16 sReoOAM_Idle_Unused_Frame4[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sReoOAM_Idle_Unused_Frame5[13] = {
    0x4,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xef, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x204,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sReoOAM_Idle_Unused_Frame6[13] = {
    0x4,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ea, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

const u16 sReoOAM_Moving_Frame0[13] = {
    0x4,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0xfe, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x210,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x210
};

const u16 sReoOAM_Moving_Frame1[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xee, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x204,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x204,
    0xfd, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x210,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x210
};

const u16 sReoOAM_Moving_Frame2[16] = {
    0x5,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e9, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x226,
    0xfd, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x210,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x210
};

const u16 sReoOAM_Moving_Frame4[10] = {
    0x3,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x214
};

const u16 sReoOAM_Moving_Frame5[13] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf0, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x204,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x214
};

const u16 sReoOAM_Moving_Frame6[13] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ea, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x214
};

const struct FrameData sReoOAM_Unused1[5] = {
    sReoOAM_Idle_Frame0,
    0x6,
    sReoOAM_Idle_Frame1,
    0x2,
    sReoOAM_Idle_Frame2,
    0x2,
    sReoOAM_Idle_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sReoOAM_Idle[5] = {
    sReoOAM_Idle_Frame0,
    0x4,
    sReoOAM_Idle_Frame1,
    0x2,
    sReoOAM_Idle_Frame2,
    0x2,
    sReoOAM_Idle_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sReoOAM_Idle_Unused[9] = {
    sReoOAM_Idle_Unused_Frame0,
    0x2,
    sReoOAM_Idle_Unused_Frame1,
    0x2,
    sReoOAM_Idle_Unused_Frame2,
    0x2,
    sReoOAM_Idle_Unused_Frame1,
    0x2,
    sReoOAM_Idle_Unused_Frame4,
    0x2,
    sReoOAM_Idle_Unused_Frame5,
    0x1,
    sReoOAM_Idle_Unused_Frame6,
    0x1,
    sReoOAM_Idle_Unused_Frame5,
    0x1,
    NULL,
    0x0
};

const struct FrameData sReoOAM_Moving[13] = {
    sReoOAM_Moving_Frame0,
    0x2,
    sReoOAM_Moving_Frame1,
    0x2,
    sReoOAM_Moving_Frame2,
    0x2,
    sReoOAM_Moving_Frame1,
    0x2,
    sReoOAM_Moving_Frame4,
    0x2,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame6,
    0x1,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame4,
    0x2,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame6,
    0x1,
    sReoOAM_Moving_Frame5,
    0x1,
    NULL,
    0x0
};

const struct FrameData sReoOAM_Unused2[21] = {
    sReoOAM_Moving_Frame4,
    0x2,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame6,
    0x1,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame4,
    0x2,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame6,
    0x1,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame4,
    0x2,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame6,
    0x1,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame4,
    0x2,
    sReoOAM_Moving_Frame6,
    0x1,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame0,
    0x2,
    sReoOAM_Moving_Frame1,
    0x2,
    sReoOAM_Moving_Frame2,
    0x2,
    sReoOAM_Moving_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sReoOAM_Unused3[9] = {
    sReoOAM_Idle_Unused_Frame4,
    0x2,
    sReoOAM_Idle_Unused_Frame5,
    0x1,
    sReoOAM_Idle_Unused_Frame6,
    0x1,
    sReoOAM_Idle_Unused_Frame5,
    0x1,
    sReoOAM_Idle_Unused_Frame0,
    0x2,
    sReoOAM_Idle_Unused_Frame1,
    0x2,
    sReoOAM_Idle_Unused_Frame2,
    0x2,
    sReoOAM_Idle_Unused_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sReoOAM_Moving_Unused[5] = {
    sReoOAM_Moving_Unused_Frame0,
    0x4,
    sReoOAM_Moving_Unused_Frame1,
    0x2,
    sReoOAM_Moving_Unused_Frame2,
    0x2,
    sReoOAM_Moving_Unused_Frame1,
    0x2,
    NULL,
    0x0
};

/**
 * @brief 1cc98 | 88 | Initializes a reo sprite
 * 
 */
void ReoInit(void)
{
    gCurrentSprite.drawDistanceTopOffset = 0x18;
    gCurrentSprite.drawDistanceBottomOffset = 0x18;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

    gCurrentSprite.hitboxTopOffset = -0x20;
    gCurrentSprite.hitboxBottomOffset = 0x20;
    gCurrentSprite.hitboxLeftOffset = -0x38;
    gCurrentSprite.hitboxRightOffset = 0x38;

    gCurrentSprite.pOam = sReoOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    SpriteUtilChooseRandomXDirection();

    if (0x8 < gSpriteRNG)
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;

    gCurrentSprite.pose = REO_POSE_IDLE_INIT;
}

/**
 * @brief 1cd20 | 24 | Initializes a reo to be idle
 * 
 */
void ReoIdleInit(void)
{
    u8 offset;
    
    gCurrentSprite.pose = REO_POSE_IDLE;
    offset = gSpriteRNG * 4;
    gCurrentSprite.workVariable2 = offset;
    gCurrentSprite.arrayOffset = gCurrentSprite.workVariable2;
}

/**
 * @brief 1cd44 | 84 | Handles a reo being idle
 * 
 */
void ReoIdle(void)
{
    i32 movement;
    u8 offset;

    // Y movement
    offset = gCurrentSprite.arrayOffset;
    movement = sReoIdleYMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sReoIdleYMovement[0];
        offset = 0x0;
    }
    gCurrentSprite.arrayOffset = offset + 0x1;
    gCurrentSprite.yPosition += movement;
    
    // X movement
    offset = gCurrentSprite.workVariable2;
    movement = sReoIdleXMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sReoIdleXMovement[0];
        offset = 0x0;
    }
    gCurrentSprite.workVariable2 = offset + 0x1;
    gCurrentSprite.xPosition += movement;

    // Check samus is in range
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 8, BLOCK_SIZE * 7) != NSLR_OUT_OF_RANGE)
        gCurrentSprite.pose = REO_POSE_MOVING_INIT;
}

/**
 * @brief 1cdc8 | 88 | Initializes a reo to be moving
 * 
 */
void ReoMovingInit(void)
{
    gCurrentSprite.workVariable = 0x0;
    gCurrentSprite.workVariable2 = 0x1;
    gCurrentSprite.timer = 0x0;
    gCurrentSprite.arrayOffset = 0x1;

    gCurrentSprite.xPositionSpawn = gSpriteRNG & 0x3;
    gCurrentSprite.pose = REO_POSE_MOVING;
    gCurrentSprite.oamScaling = 0x20;

    gCurrentSprite.pOam = sReoOAM_Moving;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    SpriteUtilMakeSpriteFaceSamusDirection();

    if (gCurrentSprite.yPosition > gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset)
        gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
    else
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
}

void ReoMove(void)
{
    // https://decomp.me/scratch/RUez3

    /*u16 yPosition;
    u16 xPosition;
    u16 otherY;
    u16 otherX;
    
    u8 spriteID;
    u8 ramSlot;
    u16 offset;
    u8 collision;
    
    u16 ySpeedCap;
    u16 xSpeedCap;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;
    offset = 0x28;
    spriteID = gCurrentSprite.spriteID;

    for (ramSlot = gCurrentSprite.primarySpriteRAMSlot + 0x1; ramSlot < MAX_AMOUNT_OF_SPRITES; ramSlot++)
    {
        if (gSpriteData[ramSlot].status & SPRITE_STATUS_EXISTS && !(gSpriteData[ramSlot].properties & SP_SECONDARY_SPRITE) && gSpriteData[ramSlot].spriteID == spriteID)
        {
            otherY = gSpriteData[ramSlot].yPosition;
            otherX = gSpriteData[ramSlot].xPosition;

            if (yPosition + offset > otherY - offset && yPosition - offset < otherY + offset && xPosition + offset > otherX - offset && xPosition - offset < otherX + offset)
            {
                if (gSpriteData[ramSlot].freezeTimer == 0x0)
                {
                    if (yPosition > otherY)
                    {
                        if (SpriteUtilGetCollisionAtPosition(otherY - HALF_BLOCK_SIZE, otherX) == COLLISION_AIR)
                            gSpriteData[ramSlot].yPosition -= 0x4;
                    }
                    else
                    {
                        if (SpriteUtilGetCollisionAtPosition(otherY + HALF_BLOCK_SIZE, otherX) == COLLISION_AIR)
                            gSpriteData[ramSlot].yPosition += 0x4;
                    }

                    if (xPosition > otherX)
                    {
                        if (SpriteUtilGetCollisionAtPosition(otherY, otherX - HALF_BLOCK_SIZE) == COLLISION_AIR)
                            gSpriteData[ramSlot].xPosition -= 0x4;
                    }
                    else
                    {
                        if (SpriteUtilGetCollisionAtPosition(otherY, otherX + HALF_BLOCK_SIZE) == COLLISION_AIR)
                            gSpriteData[ramSlot].xPosition += 0x4;
                    }
                }

                break;
            }
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
        if (collision != COLLISION_AIR)
        {
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.workVariable = 0x0;
            gCurrentSprite.workVariable2 = 0x1;
        }
    }
    else
    {
        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
        if (collision != COLLISION_AIR)
        {
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.workVariable = 0x0;
            gCurrentSprite.workVariable2 = 0x1;
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition);
        if (collision != COLLISION_AIR)
        {
            gCurrentSprite.status ^= SPRITE_STATUS_UNKNOWN2;
            gCurrentSprite.timer = 0x0;
            gCurrentSprite.arrayOffset = 0x1;
        }
    }
    else
    {
        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition);
        if (collision != COLLISION_AIR)
        {
            gCurrentSprite.status ^= SPRITE_STATUS_UNKNOWN2;
            gCurrentSprite.timer = 0x0;
            gCurrentSprite.arrayOffset = 0x1;
        }
    }

    otherY = gSamusData.yPosition - 0x48;
    otherX = gSamusData.xPosition;
    if (spriteID == PSPRITE_REO_PURPLE_WINGS)
    {
        ySpeedCap = 0x20;
        xSpeedCap = 0x40;
    }
    else
    {
        ySpeedCap = 0x10;
        xSpeedCap = 0x18;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.workVariable == 0x0)
        {
            if (gCurrentSprite.xPosition > otherX - 4)
                gCurrentSprite.workVariable = gCurrentSprite.workVariable2;
            else
            {
                if (gCurrentSprite.workVariable2 < xSpeedCap)
                    gCurrentSprite.workVariable2++;

                gCurrentSprite.xPosition += gCurrentSprite.workVariable2 >> 2;
            }
        }
        else
        {
            if (gCurrentSprite.workVariable-- != 0x1)
            {
                gCurrentSprite.xPosition += gCurrentSprite.workVariable >> 2;
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
                gCurrentSprite.workVariable2 = 0x1;
            }
        }
    }
    else
    {
        if (gCurrentSprite.workVariable == 0x0)
        {
            if (gCurrentSprite.xPosition < otherX + 4)
                gCurrentSprite.workVariable = gCurrentSprite.workVariable2;
            else
            {
                if (gCurrentSprite.workVariable2 < xSpeedCap)
                    gCurrentSprite.workVariable2++;

                gCurrentSprite.xPosition -= gCurrentSprite.workVariable2 >> 2;
            }
        }
        else
        {
            if (gCurrentSprite.workVariable-- != 0x1)
            {
                gCurrentSprite.xPosition -= gCurrentSprite.workVariable >> 2;
            }
            else
            {
                gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
                gCurrentSprite.workVariable2 = 0x1;
            }
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.timer == 0x0)
        {
            if (gCurrentSprite.yPosition > otherY - 4)
                gCurrentSprite.timer = gCurrentSprite.arrayOffset;
            else
            {
                if (gCurrentSprite.arrayOffset < ySpeedCap)
                    gCurrentSprite.arrayOffset++;

                gCurrentSprite.yPosition += gCurrentSprite.arrayOffset >> 2;
            }
        }
        else
        {
            if (gCurrentSprite.timer-- != 0x1)
            {
                gCurrentSprite.yPosition += gCurrentSprite.timer >> 2;
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
                gCurrentSprite.arrayOffset = 0x1;
            }
        }

        SpriteUtilCheckInRoomEffect(yPosition, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_SMALL);
    }
    else
    {
        if (gCurrentSprite.timer == 0x0)
        {
            if (gCurrentSprite.yPosition < otherY + 4)
                gCurrentSprite.timer = gCurrentSprite.arrayOffset;
            else
            {
                if (gCurrentSprite.arrayOffset < ySpeedCap)
                    gCurrentSprite.arrayOffset++;

                gCurrentSprite.yPosition -= gCurrentSprite.arrayOffset >> 2;
            }
        }
        else
        {
            if (gCurrentSprite.timer-- != 0x1)
            {
                gCurrentSprite.yPosition -= gCurrentSprite.timer >> 2;
            }
            else
            {
                gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
                gCurrentSprite.arrayOffset = 0x1;
            }
        }

        SpriteUtilCheckOutOfRoomEffect(yPosition, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_SMALL);
    }

    gCurrentSprite.oamScaling--;
    if (gCurrentSprite.oamScaling == 0x0)
    {
        gCurrentSprite.oamScaling = 0x20;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x158);
    }*/
}

/**
 * @brief 1d1e4 | 134 | Reo AI
 * 
 */
void Reo(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x159);
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
                ReoInit();
                break;

            case REO_POSE_IDLE_INIT:
                ReoIdleInit();
                break;

            case REO_POSE_IDLE:
                ReoIdle();
                break;

            case REO_POSE_MOVING_INIT:
                ReoMovingInit();

            case REO_POSE_MOVING:
                ReoMove();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
        }
    }
}