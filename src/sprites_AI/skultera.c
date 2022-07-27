#include "skultera.h"
#include "../../data/data.h"
#include "../globals.h"

const u8 sSkulteraGFX[1140];
const u16 sSkulteraPAL[16];

const u16 sSkulteraOAM_Idle_Frame0[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_SIZE_32x16 | 0x1ef, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x8 | 0x1ef, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x233,
    0xf1, 0x1, OBJ_SPRITE_OAM | 0x200,
    0xf4, OBJ_Y_FLIP | 0x5, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xef, 0xb, OBJ_SPRITE_OAM | 0x206
};

const u16 sSkulteraOAM_Idle_Frame1[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_SIZE_32x16 | 0x1e6, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1e7, OBJ_SPRITE_OAM | 0x236,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x216,
    0xf2, 0x1ff, OBJ_SPRITE_OAM | 0x201,
    0xf5, 0x6, OBJ_SPRITE_OAM | 0x202,
    0xf3, 0xa, OBJ_SPRITE_OAM | 0x225
};

const u16 sSkulteraOAM_Idle_Frame2[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_SIZE_32x16 | 0x1e6, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1e6, OBJ_SPRITE_OAM | 0x216,
    0xf5, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x201,
    0xf3, 0x7, OBJ_SPRITE_OAM | 0x200,
    0xf3, 0xb, OBJ_SPRITE_OAM | 0x205
};

const u16 sSkulteraOAM_Idle_Frame3[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x213,
    0xf5, 0x1, OBJ_SPRITE_OAM | 0x202,
    0xf3, 0x5, OBJ_SPRITE_OAM | 0x201,
    0xf2, OBJ_Y_FLIP | 0xa, OBJ_SPRITE_OAM | 0x225
};

const u16 sSkulteraOAM_TurningAround_Frame0[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_SIZE_32x16 | 0x1e6, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1e7, OBJ_SPRITE_OAM | 0x236,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x216,
    0xf1, 0x0, OBJ_SPRITE_OAM | 0x201,
    0xf3, 0x6, OBJ_SPRITE_OAM | 0x202,
    0xf4, OBJ_Y_FLIP | 0xb, OBJ_SPRITE_OAM | 0x225
};

const u16 sSkulteraOAM_TurningAround_Frame1[19] = {
    0x6,
    0xe1, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x20e,
    0xf1, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x21a,
    0xf9, 0x2, OBJ_SPRITE_OAM | 0x232,
    0xf2, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    0xf4, 0x1, OBJ_SPRITE_OAM | 0x202,
    0xf2, 0x6, OBJ_SPRITE_OAM | 0x204
};

const u16 sSkulteraOAM_TurningAround_Frame2[16] = {
    0x5,
    0xe1, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x210,
    0xf1, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x0, OBJ_SPRITE_OAM | 0x21e,
    0xf1, 0x1fe, OBJ_SPRITE_OAM | 0x200,
    0xf2, 0x3, OBJ_SPRITE_OAM | 0x205
};

const u16 sSkulteraOAM_TurningAround_Frame3[13] = {
    0x4,
    0xe1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20e,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21a,
    0xf1, OBJ_X_FLIP | 0x1ed, OBJ_SPRITE_OAM | 0x200,
    0xf3, 0x1fd, OBJ_SPRITE_OAM | 0x203
};

const u16 sSkulteraOAM_TurningAround_Frame4[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x216,
    0xf1, OBJ_X_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x201
};

const u16 sSkulteraOAM_TurningAround_Frame5[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1eb, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1eb, OBJ_SPRITE_OAM | 0x213,
    0xf4, OBJ_X_FLIP | 0x1f1, OBJ_SPRITE_OAM | 0x202,
    0xf1, OBJ_X_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x200
};

const u16 sSkulteraOAM_TurningAround_Frame6[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x1ee, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x1ed, OBJ_SPRITE_OAM | 0x233,
    0xf1, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x200,
    0xf4, OBJ_X_FLIP | 0x1ef, OBJ_SPRITE_OAM | 0x202,
    0xf2, OBJ_X_FLIP | 0x1ed, OBJ_SPRITE_OAM | 0x204
};

const u16 sSkulteraOAM_TurningAround_Frame7[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1fa, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x1f9, OBJ_SPRITE_OAM | 0x236,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x1fa, OBJ_SPRITE_OAM | 0x216,
    0xf4, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xf1, OBJ_X_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x200,
    0xf2, OBJ_X_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x205
};


const struct FrameData sSkulteraOAM_Idle[5] = {
    sSkulteraOAM_Idle_Frame0,
    0x8,
    sSkulteraOAM_Idle_Frame1,
    0x8,
    sSkulteraOAM_Idle_Frame2,
    0x8,
    sSkulteraOAM_Idle_Frame3,
    0x8,
    NULL,
    0x0
};

const struct FrameData sSkulteraOAM_TurningAround[9] = {
    sSkulteraOAM_TurningAround_Frame0,
    0xD,
    sSkulteraOAM_TurningAround_Frame1,
    0xA,
    sSkulteraOAM_TurningAround_Frame2,
    0x8,
    sSkulteraOAM_TurningAround_Frame3,
    0x6,
    sSkulteraOAM_TurningAround_Frame4,
    0x6,
    sSkulteraOAM_TurningAround_Frame5,
    0x8,
    sSkulteraOAM_TurningAround_Frame6,
    0xA,
    sSkulteraOAM_TurningAround_Frame7,
    0xD,
    NULL,
    0x0
};

const struct FrameData sSkulteraOAM_ChasingSamus[5] = {
    sSkulteraOAM_Idle_Frame0,
    0x3,
    sSkulteraOAM_Idle_Frame3,
    0x3,
    sSkulteraOAM_Idle_Frame2,
    0x3,
    sSkulteraOAM_Idle_Frame3,
    0x3,
    NULL,
    0x0
};


/**
 * @brief 48c7c | 30 | Sets the side hitboxes depending on the X flip
 * 
 */
void SkulteraSetSidesHitbox(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        gCurrentSprite.hitboxLeftOffset = -0x18;
        gCurrentSprite.hitboxRightOffset = 0x28;
    }
    else
    {
        gCurrentSprite.hitboxLeftOffset = -0x28;
        gCurrentSprite.hitboxRightOffset = 0x18;
    }
}

/**
 * @brief 48cac | 64 | Handles the horizontal movement of the skultera
 * 
 * @param movement X velocity
 * @return u8 1 if colliding with solid, 0 otherwise
 */
u8 SkulteraXMovement(u16 movement)
{
    i16 negMovement;

    negMovement = movement;
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE / 2), gCurrentSprite.xPosition + 0x38);
        if (gPreviousCollisionCheck != COLLISION_SOLID)
        {
            gCurrentSprite.xPosition += movement;
            return FALSE;
        }
        else
            return TRUE;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE / 2), gCurrentSprite.xPosition - 0x38);
        if (gPreviousCollisionCheck != COLLISION_SOLID)
        {
            gCurrentSprite.xPosition -= negMovement;
            return FALSE;
        }
        else
            return TRUE;
    }
}

/**
 * @brief 48d10 | 68 | Initializes a skultera sprite
 * 
 */
void SkulteraInit(void)
{
    SpriteUtilChooseRandomXFlip(); // Random direction
    gCurrentSprite.drawDistanceTopOffset = 0x20;
    gCurrentSprite.drawDistanceBottomOffset = 0x0;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

    gCurrentSprite.hitboxTopOffset = -0x60;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    SkulteraSetSidesHitbox();

    gCurrentSprite.pose = SKULTERA_POSE_IDLE_INIT;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    gCurrentSprite.pOam = sSkulteraOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0x0];
}

/**
 * @brief 48d78 | 30 | Initializes a skultera to be idle
 * 
 */
void SkulteraIdleInit(void)
{
    // Save spawn X to allow loop back
    gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
    gCurrentSprite.pose = SKULTERA_POSE_IDLE;

    gCurrentSprite.pOam = sSkulteraOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.timer = 0x3; // Timer before movement
}

/**
 * @brief 48da8 | c4 | Handles the skultera moving in idle behavior
 * 
 */
void SkulteraMoving(void)
{
    u32 nslr;

    gCurrentSprite.timer--; // Timer before movement
    if (gCurrentSprite.timer == 0x0)
    {
        if (SkulteraXMovement(0x4)) // Move and check hit solid
            gCurrentSprite.pose = SKULTERA_POSE_TURNING_AROUND; // Hit solid, set turning around
        else
        {
            // Check out of movement territory, if out set turning around
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            {
                if ((gCurrentSprite.xPositionSpawn + (BLOCK_SIZE * 8)) < gCurrentSprite.xPosition)
                    gCurrentSprite.pose = SKULTERA_POSE_TURNING_AROUND;
            }
            else
            {
                if ((gCurrentSprite.xPositionSpawn - (BLOCK_SIZE * 8)) > gCurrentSprite.xPosition)
                    gCurrentSprite.pose = SKULTERA_POSE_TURNING_AROUND;
            }
            gCurrentSprite.timer = 0x3; // Reset timer
        }
    }

    // Check detect samus

    // Change Y range
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 10, BLOCK_SIZE) != NSLR_OUT_OF_RANGE)
        return;

    nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 3, BLOCK_SIZE * 5);

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        // Check on right
        if (nslr == NSLR_RIGHT)
            gCurrentSprite.pose = SKULTERA_POSE_CHASING_SAMUS_INIT;
        else if (nslr == NSLR_LEFT)
            gCurrentSprite.pose = SKULTERA_POSE_TURNING_AROUND; // Turn around to face samus
    }
    else
    {
        // Check on left
        if (nslr == NSLR_LEFT)
            gCurrentSprite.pose = SKULTERA_POSE_CHASING_SAMUS_INIT;
        else if (nslr == NSLR_RIGHT)
            gCurrentSprite.pose = SKULTERA_POSE_TURNING_AROUND; // Turn around to face samus
    }
}

/**
 * @brief 48e6c | 20 | Initializes a skultera to be chasing samus
 * 
 */
void SkulteraChasingSamusInit(void)
{
    gCurrentSprite.pose = SKULTERA_POSE_CHASING_SAMUS;
    gCurrentSprite.pOam = sSkulteraOAM_ChasingSamus;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 48e8c | 110 | Handles the skultera moving in chasing samus behavior 
 * 
 */
void SkulteraChasingSamus(void)
{
    u16 samusY;
    u16 spriteY;
    u32 nslr;

    samusY = gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset / 2;
    spriteY = gCurrentSprite.yPosition - (BLOCK_SIZE / 2);

    // Check move vertically
    if ((i32)(spriteY - BLOCK_SIZE) > samusY)
    {
        // Check move up
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + BLOCK_SIZE / 2), gCurrentSprite.xPosition);
        // If no solid block and still in water
        if (gPreviousCollisionCheck == COLLISION_AIR && gCurrentAffectingClipdata.hazard == HAZARD_TYPE_WATER)
            gCurrentSprite.yPosition -= 0x2;
    }
    else if ((i32)(spriteY + BLOCK_SIZE) < samusY)
    {
        // Check move down
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        // If no solid block
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.yPosition += 0x2;
    }

    gCurrentSprite.timer--; // Timer before movement
    if (gCurrentSprite.timer == 0x0)
    {
        if (SkulteraXMovement(0x4))
            gCurrentSprite.pose = SKULTERA_POSE_TURNING_AROUND;
        else
            gCurrentSprite.timer = 0x2; // Reset timer, 1 frame faster than idle for faster movement
    }

    // Check samus still in range
    
    // Change Y range
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 10, BLOCK_SIZE) != NSLR_OUT_OF_RANGE)
        return;

    nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 3, BLOCK_SIZE * 5);

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        if (nslr != NSLR_RIGHT)
        {
            if (nslr == NSLR_LEFT)
                gCurrentSprite.pose = SKULTERA_POSE_TURNING_AROUND; // Turn around to face samus
            else
                gCurrentSprite.pose = SKULTERA_POSE_IDLE_INIT; // Samus out of range, back to init
        }
    }
    else
    {
        if (nslr != NSLR_LEFT)
        {
            if (nslr == NSLR_RIGHT)
                gCurrentSprite.pose = SKULTERA_POSE_TURNING_AROUND; // Turn around to face samus
            else
                gCurrentSprite.pose = SKULTERA_POSE_IDLE_INIT; // Samus out of range, back to init
        }
    }
}

/**
 * @brief 48f9c | 38 | Initializes a skultera to be turning around
 * 
 */
void SkulteraTurningAroundInit(void)
{
    gCurrentSprite.pose = SKULTERA_POSE_CHECK_TURNING_AROUND_ENDED;
    gCurrentSprite.pOam = sSkulteraOAM_TurningAround;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(0x269);
}

/**
 * @brief 48fd4 | 24 | Checks if the skultera has finished turning around
 * 
 */
void SkulteraCheckTurningAroundAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set idle behavior
        SkulteraIdleInit();
        // Flip and set hitbox
        gCurrentSprite.status ^= SPRITE_STATUS_XFLIP;
        SkulteraSetSidesHitbox();
    }
}

/**
 * @brief 48ff8 | 18c | Skultera AI
 * 
 */
void Skultera(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x26A);
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
                SkulteraInit();
                break;

            case SKULTERA_POSE_IDLE_INIT:
                SkulteraIdleInit();
                break;

            case SKULTERA_POSE_IDLE:
                SkulteraMoving();
                break;

            case SKULTERA_POSE_TURNING_AROUND:
                SkulteraTurningAroundInit();

            case SKULTERA_POSE_CHECK_TURNING_AROUND_ENDED:
                SkulteraCheckTurningAroundAnimEnded();
                break;

            case SKULTERA_POSE_CHASING_SAMUS_INIT:
                SkulteraChasingSamusInit();
            
            case SKULTERA_POSE_CHASING_SAMUS:
                SkulteraChasingSamus();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - (BLOCK_SIZE / 2), gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
        }
    }
}