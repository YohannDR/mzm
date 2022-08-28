#include "squeept.h"
#include "../../data/data.h"
#include "../globals.h"

const i16 sSqueeptRisingMovement[65] = {
    -18, -18, -18, -18, -16, -16, -16, -16, -14,
    -14, -14, -14, -12, -12, -12, -12, -12, -12,
    -12, -12, -11, -11, -11, -11, -10, -10, -10,
    -10, -9, -9, -9, -9, -8, -8, -8, -8, -8, -8,
    -8, -8, -7, -7, -7, -7, -6, -6, -6, -6, -5,
    -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -3,
    -2, -2, -2, -2, SPRITE_ARRAY_TERMINATOR
};

const i16 sSqueeptFallingMovement[16] = {
    4, 4, 4, 6, 6, 8, 8, 10, 10, 12, 12, 14,
    14, 16, 16, SPRITE_ARRAY_TERMINATOR
};

const u32 sSqueeptGFX[263];
const u16 sSqueeptPAL[16];

const u16 sSqueeptOAM_GoingUp_Frame0[25] = {
    0x8,
    0x3, 0x1f8, OBJ_SPRITE_OAM | 0x22d,
    0x3, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x22d,
    0xf3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1f1, OBJ_SPRITE_OAM | 0x206,
    0xff, 0x1f9, OBJ_SPRITE_OAM | 0x207,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x206,
    0xff, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x207
};

const u16 sSqueeptOAM_GoingUp_Frame2[22] = {
    0x7,
    0xf2, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x202,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0xff, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x206,
    0xff, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0x2, 0x1fc, OBJ_SPRITE_OAM | 0x20f
};

const u16 sSqueeptOAM_GoingUp_Frame4[22] = {
    0x7,
    0xf2, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0xff, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x206,
    0xff, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0x2, 0x1fc, OBJ_SPRITE_OAM | 0x20e
};

const u16 sSqueeptOAM_GoingUp_Frame1[19] = {
    0x6,
    0xf3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1f1, OBJ_SPRITE_OAM | 0x206,
    0xff, 0x1f9, OBJ_SPRITE_OAM | 0x207,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x206,
    0xff, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x207
};

const u16 sSqueeptOAM_GoingUp_Frame3[19] = {
    0x6,
    0xf3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x202,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x206,
    0x0, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x207
};

const u16 sSqueeptOAM_GoingUp_Frame5[19] = {
    0x6,
    0xf3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x206,
    0x0, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x207
};

const u16 sSqueeptOAM_TurningAround_Frame0[13] = {
    0x4,
    0xf3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    0x3, 0x1f0, OBJ_SPRITE_OAM | 0x20d,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x208,
    0x3, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x20d
};

const u16 sSqueeptOAM_TurningAround_Frame1[7] = {
    0x2,
    0xf4, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20a
};

const u16 sSqueeptOAM_TurningAround_Frame2[7] = {
    0x2,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20a
};

const u16 sSqueeptOAM_TurningAround_Frame3[13] = {
    0x4,
    0xf7, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    0xef, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x20d,
    0xf7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x208,
    0xef, OBJ_X_FLIP | OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x20d
};

const u16 sSqueeptOAM_TurningAround_Frame4[19] = {
    0x6,
    0xfc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0xf7, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x206,
    0xf7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x207
};

const u16 sSqueeptOAM_GoingDown_Frame0[13] = {
    0x4,
    0xfd, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xfd, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x20c
};

const u16 sSqueeptOAM_GoingDown_Frame1[13] = {
    0x4,
    0xfc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1f7, OBJ_SPRITE_OAM | 0x20c,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x20c
};

const struct FrameData sSqueeptOAM_TurningAround[6] = {
    sSqueeptOAM_TurningAround_Frame0,
    0x5,
    sSqueeptOAM_TurningAround_Frame1,
    0x9,
    sSqueeptOAM_TurningAround_Frame2,
    0x7,
    sSqueeptOAM_TurningAround_Frame3,
    0x3,
    sSqueeptOAM_TurningAround_Frame4,
    0xA,
    NULL,
    0x0
};

const struct FrameData sSqueeptOAM_TurningAround_Unused[6] = {
    sSqueeptOAM_TurningAround_Frame4,
    0x5,
    sSqueeptOAM_TurningAround_Frame3,
    0x4,
    sSqueeptOAM_TurningAround_Frame2,
    0x3,
    sSqueeptOAM_TurningAround_Frame1,
    0x2,
    sSqueeptOAM_TurningAround_Frame0,
    0x1,
    NULL,
    0x0
};

const struct FrameData sSqueeptOAM_GoingDown[3] = {
    sSqueeptOAM_GoingDown_Frame0,
    0x4,
    sSqueeptOAM_GoingDown_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sSqueeptOAM_GoingUp[8] = {
    sSqueeptOAM_GoingUp_Frame0,
    0x2,
    sSqueeptOAM_GoingUp_Frame1,
    0x1,
    sSqueeptOAM_GoingUp_Frame2,
    0x2,
    sSqueeptOAM_GoingUp_Frame3,
    0x1,
    sSqueeptOAM_GoingUp_Frame4,
    0x2,
    sSqueeptOAM_GoingUp_Frame5,
    0x1,
    sSqueeptOAM_GoingUp_Frame3,
    0x2,
    NULL,
    0x0
};


/**
 * @brief 1eff4 | 24 | Initializes a squeept to be going up
 * 
 */
void SqueeptGoingUpInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x2C;
    gCurrentSprite.hitboxBottomOffset = 0x20;

    gCurrentSprite.pOam = sSqueeptOAM_GoingUp;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 1f018 | 24 | Initializes a squeept to be turning around
 * 
 */
void SqueeptTurningAroundInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x20;
    gCurrentSprite.hitboxBottomOffset = 0x20;

    gCurrentSprite.pOam = sSqueeptOAM_TurningAround;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 1f03c | 20 | Initializes a squeept to be going down
 * 
 */
void SqueeptGoingDownInit(void)
{
    gCurrentSprite.hitboxTopOffset = 0x0;
    gCurrentSprite.hitboxBottomOffset = 0x28;

    gCurrentSprite.pOam = sSqueeptOAM_GoingDown;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 1f05c | 4c | Initializes a squeept sprite
 * 
 */
void SqueeptInit(void)
{
    gCurrentSprite.drawDistanceTopOffset = 0x14;
    gCurrentSprite.drawDistanceBottomOffset = 0x14;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

    gCurrentSprite.hitboxLeftOffset = -0x20;
    gCurrentSprite.hitboxRightOffset = 0x20;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.yPosition += 0x4;

    // Save spawn Y
    gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
}

/**
 * @brief 1f0a8 | 28 | Initializes a squeept to be idle
 * 
 */
void SqueeptIdleInit(void)
{
    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.pose = SQUEEPT_POSE_IDLE;
    SqueeptGoingUpInit();
    gCurrentSprite.timer = 0x1E;
}

/**
 * @brief 1f0d0 | 50 | Handles a squeept being idle
 * 
 */
void SqueeptIdle(void)
{
    u8 nsab;

    if (gCurrentSprite.timer != 0x0)
        gCurrentSprite.timer--;
    else
    {
        // Detect samus
        nsab = SpriteUtilCheckSamusNearSpriteAboveBelow(BLOCK_SIZE * 8, BLOCK_SIZE * 6);
        if (nsab == NSAB_ABOVE)
        {
            // Set going up
            gCurrentSprite.pose = SQUEEPT_POSE_GOING_UP;
            gCurrentSprite.arrayOffset = 0x0;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        }
    }
}

/**
 * @brief 1f120 | bc | Handles a squeept going up
 * 
 */
void SqueeptGoUp(void)
{
    u16 oldY;
    i32 movement;
    i32 newMovement;
    u8 offset;

    oldY = gCurrentSprite.yPosition;

    if (gCurrentSprite.yPositionSpawn - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE) > oldY)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE), gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            SqueeptTurningAroundInit();
            gCurrentSprite.pose = SQUEEPT_POSE_TURNING_AROUND;
            return;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE), gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                SqueeptTurningAroundInit();
                gCurrentSprite.pose = SQUEEPT_POSE_TURNING_AROUND;
                return;
            }
        }
    }

    offset = gCurrentSprite.arrayOffset;
    movement = sSqueeptRisingMovement[offset];

    if (movement == SPRITE_ARRAY_TERMINATOR)
    {
        SqueeptTurningAroundInit();
        gCurrentSprite.pose = SQUEEPT_POSE_TURNING_AROUND;
    }
    else
    {
        gCurrentSprite.arrayOffset++;
        gCurrentSprite.yPosition += movement;
    }

    if (SpriteUtilCheckOutOfRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_SMALL) &&
        gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(0x155);
}

/**
 * @brief 1f1dc | 28 | Handles a squeept turning around
 * 
 */
void SqueeptTurningAround(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set going down
        SqueeptGoingDownInit();
        gCurrentSprite.pose = SQUEEPT_POSE_GOING_DOWN;
        gCurrentSprite.arrayOffset = 0x0;
    }
}

/**
 * @brief 1f204 | 84 | Handles a squeept going down
 * 
 */
void SqueeptGoDown(void)
{
    u16 oldY;
    i32 movement;
    i32 newMovement;
    u8 offset;

    oldY = gCurrentSprite.yPosition;
    offset = gCurrentSprite.arrayOffset;
    movement = sSqueeptFallingMovement[offset];

    if (movement == SPRITE_ARRAY_TERMINATOR)
    {
        newMovement = sSqueeptFallingMovement[offset - 0x1];
        gCurrentSprite.yPosition += newMovement;
    }
    else
    {
        gCurrentSprite.arrayOffset++;
        gCurrentSprite.yPosition += movement;
    }

    if (SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_BIG) && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(0x156);

    if (gCurrentSprite.yPositionSpawn < gCurrentSprite.yPosition)
    {
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
        SqueeptIdleInit();
    }
}

/**
 * @brief  1f288 | 194 | Squeept AI
 * 
 */
void Squeept(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x157);
    }

    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (!SpriteUtilIsSpriteStunned())
            return;

        switch (gCurrentSprite.pose)
        {
            case 0x0:
                SqueeptInit();

            case SQUEEPT_POSE_IDLE_INIT:
                SqueeptIdleInit();

            case SQUEEPT_POSE_IDLE:
                SqueeptIdle();
                break;

            case SQUEEPT_POSE_GOING_UP:
                SqueeptGoUp();
                break;

            case SQUEEPT_POSE_TURNING_AROUND:
                SqueeptTurningAround();
                break;

            case SQUEEPT_POSE_GOING_DOWN:
                SqueeptGoDown();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
        }
    }
}