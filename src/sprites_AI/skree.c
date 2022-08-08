#include "skree.h"
#include "../../data/data.h"
#include "../globals.h"

const i16 sSkreeFallingSpeed[8] = {
    2, 4, 6, 7, 12, 14, 16, SPRITE_ARRAY_TERMINATOR
};

const u32 sSkreeGFX[264];
const u16 sSkreePAL[16];
const u32 sSkreeBlueGFX[264];
const u16 sSkreeBluePAL[16];

const u16 sSkreeOAM_Idle_Frame0[13] = {
    0x4,
    0x0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0x10, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x202,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x200,
    0x10, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x202
};

const u16 sSkreeOAM_Idle_Frame1[7] = {
    0x2,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0x10, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

const u16 sSkreeOAM_Idle_Frame2[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1fc, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x10, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    0x0, 0x4, OBJ_SPRITE_OAM | 0x211,
    0x0, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x211
};

const u16 sSkreeOAM_Idle_Frame3[7] = {
    0x2,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x213,
    0x10, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x215
};

const u16 sSkreeOAM_Spinning_Frame1[13] = {
    0x4,
    0x0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x20a
};

const u16 sSkreeOAM_Spinning_Frame2[13] = {
    0x4,
    0x0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x206
};

const u16 sSkreeOAM_CrashingUnused_Frame0[13] = {
    0x4,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0xe0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x202,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x200,
    0xe0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x202
};

const u16 sSkreeOAM_CrashingUnused_Frame1[7] = {
    0x2,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xe0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

const u16 sSkreeOAM_CrashingUnused_Frame2[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x212,
    0xf8, OBJ_Y_FLIP | 0x4, OBJ_SPRITE_OAM | 0x211,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x211
};

const u16 sSkreeOAM_CrashingUnused_Frame3[7] = {
    0x2,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x213,
    0xe0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x215
};

const u16 sSkreeOAM_CrashingUnused2_Frame1[13] = {
    0x4,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x20a
};

const u16 sSkreeOAM_CrashingUnused2_Frame2[13] = {
    0x4,
    0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x206
};

const u16 sSkreeExplosionOAM_GoingUp_Frame0[10] = {
    0x3,
    0x6, 0x1fb, OBJ_SPRITE_OAM | 0x238,
    0xf6, 0x1fb, OBJ_SPRITE_OAM | 0x217,
    0xfe, 0x1fb, OBJ_SPRITE_OAM | 0x218
};

const u16 sSkreeExplosionOAM_GoingUp_Frame1[10] = {
    0x3,
    0xf8, 0x1fb, OBJ_SPRITE_OAM | 0x217,
    0xfd, 0x1fb, OBJ_SPRITE_OAM | 0x218,
    0x2, 0x1fb, OBJ_SPRITE_OAM | 0x238
};

const u16 sSkreeExplosionOAM_GoingUp_Frame2[7] = {
    0x2,
    0xff, 0x1f9, OBJ_SPRITE_OAM | 0x238,
    0xf9, OBJ_Y_FLIP | 0x1f9, OBJ_SPRITE_OAM | 0x238
};

const u16 sSkreeExplosionOAM_GoingDown_Frame0[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1fa, OBJ_SPRITE_OAM | 0x219,
    0x6, 0x1fa, OBJ_SPRITE_OAM | 0x23a,
    0xfe, 0x1fa, OBJ_SPRITE_OAM | 0x21a
};

const u16 sSkreeExplosionOAM_GoingDown_Frame1[7] = {
    0x2,
    0xfa, 0x1fa, OBJ_SPRITE_OAM | 0x219,
    0xfe, 0x1fa, OBJ_SPRITE_OAM | 0x21a
};

const u16 sSkreeExplosionOAM_GoingDown_Frame2[4] = {
    0x1,
    0xfc, 0x1fa, OBJ_SPRITE_OAM | 0x219
};

const struct FrameData sSkreeOAM_Idle[5] = {
    sSkreeOAM_Idle_Frame0,
    0x8,
    sSkreeOAM_Idle_Frame1,
    0x8,
    sSkreeOAM_Idle_Frame2,
    0x8,
    sSkreeOAM_Idle_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sSkreeOAM_Spinning[6] = {
    sSkreeOAM_Idle_Frame0,
    0x4,
    sSkreeOAM_Spinning_Frame1,
    0x2,
    sSkreeOAM_Spinning_Frame2,
    0x2,
    sSkreeOAM_Spinning_Frame1,
    0x2,
    sSkreeOAM_Spinning_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sSkreeOAM_GoingDown[5] = {
    sSkreeOAM_Idle_Frame0,
    0x2,
    sSkreeOAM_Idle_Frame1,
    0x2,
    sSkreeOAM_Idle_Frame2,
    0x2,
    sSkreeOAM_Idle_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sSkreeOAM_Crashing[5] = {
    sSkreeOAM_Idle_Frame0,
    0x1,
    sSkreeOAM_Idle_Frame1,
    0x1,
    sSkreeOAM_Idle_Frame2,
    0x1,
    sSkreeOAM_Idle_Frame3,
    0x1,
    NULL,
    0x0
};

const struct FrameData sSkreeOAM_CrashingUnused[5] = {
    sSkreeOAM_CrashingUnused_Frame0,
    0x8,
    sSkreeOAM_CrashingUnused_Frame1,
    0x8,
    sSkreeOAM_CrashingUnused_Frame2,
    0x8,
    sSkreeOAM_CrashingUnused_Frame3,
    0x8,
    NULL,
    0x0
};

const struct FrameData sSkreeOAM_CrashingUnused2[6] = {
    sSkreeOAM_CrashingUnused_Frame0,
    0x4,
    sSkreeOAM_CrashingUnused2_Frame1,
    0x2,
    sSkreeOAM_CrashingUnused2_Frame2,
    0x4,
    sSkreeOAM_CrashingUnused2_Frame1,
    0x1,
    sSkreeOAM_CrashingUnused_Frame2,
    0x10,
    NULL,
    0x0
};

const struct FrameData sSkreeOAM_CrashingUnused3[5] = {
    sSkreeOAM_CrashingUnused_Frame0,
    0x2,
    sSkreeOAM_CrashingUnused_Frame1,
    0x2,
    sSkreeOAM_CrashingUnused_Frame2,
    0x2,
    sSkreeOAM_CrashingUnused_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sSkreeOAM_CrashingUnused4[5] = {
    sSkreeOAM_CrashingUnused_Frame0,
    0x1,
    sSkreeOAM_CrashingUnused_Frame1,
    0x1,
    sSkreeOAM_CrashingUnused_Frame2,
    0x1,
    sSkreeOAM_CrashingUnused_Frame3,
    0x1,
    NULL,
    0x0
};

const struct FrameData sSkreeExplosionOAM_GoingDown[4] = {
    sSkreeExplosionOAM_GoingDown_Frame0,
    0x8,
    sSkreeExplosionOAM_GoingDown_Frame1,
    0x6,
    sSkreeExplosionOAM_GoingDown_Frame2,
    0x6,
    NULL,
    0x0
};

const struct FrameData sSkreeExplosionOAM_GoingUp[4] = {
    sSkreeExplosionOAM_GoingUp_Frame0,
    0x8,
    sSkreeExplosionOAM_GoingUp_Frame1,
    0x6,
    sSkreeExplosionOAM_GoingUp_Frame2,
    0x6,
    NULL,
    0x0
};


/**
 * @brief 1c644 | 50 | Initializes a skree sprite
 * 
 */
void SkreeInit(void)
{
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawDistanceTopOffset = 0x0;
    gCurrentSprite.drawDistanceBottomOffset = 0x20;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

    gCurrentSprite.hitboxTopOffset = 0x0;
    gCurrentSprite.hitboxBottomOffset = 0x60;
    gCurrentSprite.hitboxLeftOffset = -0x18;
    gCurrentSprite.hitboxRightOffset = 0x18;

    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.yPosition -= BLOCK_SIZE;
}

/**
 * @brief 1c694 | 1c | Initializes a skree to be idle
 * 
 */
void SkreeIdleInit(void)
{
    gCurrentSprite.pOam = sSkreeOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = SKREE_POSE_DETECTING_SAMUS;
}

/**
 * @brief 1c6b0 | 50 | Checks if samus is in the range of the skree
 * 
 */
void SkreeDetectSamus(void)
{
    if (gSamusData.yPosition > gCurrentSprite.yPosition &&
        gSamusData.yPosition - gCurrentSprite.yPosition < 0x284 &&
        gCurrentSprite.status & SPRITE_STATUS_ONSCREEN &&
        gSamusData.xPosition > gCurrentSprite.xPosition - 0x96 &&
        gSamusData.xPosition < gCurrentSprite.xPosition + 0x96)
    {
        // Set spinning
        gCurrentSprite.pose = SKREE_POSE_SPINNING_INIT;
    }
}

/**
 * @brief 1c700 | 1c | Initializes a skree to be spinning
 * 
 */
void SkreeSpinningInit(void)
{
    gCurrentSprite.pOam = sSkreeOAM_Spinning;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = SKREE_POSE_SPINNING;
}

/**
 * @brief 1c71c | 1c | Checks if the spin animation ended
 * 
 */
void SkreeCheckSpinAnimEnded(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = SKREE_POSE_GOING_DOWN_INIT;
}

/**
 * @brief 1c738 | 68 | Initializes a skree to be going down
 * 
 */
void SkreeGoingDownInit(void)
{
    gCurrentSprite.pOam = sSkreeOAM_GoingDown;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.workVariable2 = 0x0;
    gCurrentSprite.pose = SKREE_POSE_GOING_DOWN;

    if (gCurrentSprite.xPosition > gSamusData.xPosition)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(0x141);
}

/**
 * @brief 1c7a0 | fc | Handles a skree going down
 * 
 */
void SkreeGoDown(void)
{
    u32 block;
    u32 xMovement;
    u32 yMovement;
    u32 offset;

    block = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.hitboxBottomOffset + gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != 0x0)
    {
        gCurrentSprite.yPosition = block - gCurrentSprite.hitboxBottomOffset;
        gCurrentSprite.pose = SKREE_POSE_CRASHING;
        gCurrentSprite.timer = 0x0;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(0x142);
    }
    else
    {
        xMovement = gCurrentSprite.workVariable2 >> 0x2;
        offset = gCurrentSprite.arrayOffset;
        yMovement = sSkreeFallingSpeed[offset];
        if (yMovement == SPRITE_ARRAY_TERMINATOR)
        {
            yMovement = sSkreeFallingSpeed[offset - 0x1];
            gCurrentSprite.yPosition += yMovement;
        }
        else
        {
            gCurrentSprite.arrayOffset++;
            gCurrentSprite.yPosition += yMovement;
        }

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition + (BLOCK_SIZE / 2));
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                return;
            gCurrentSprite.xPosition += xMovement;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition - (BLOCK_SIZE / 2));
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                return;
            gCurrentSprite.xPosition -= xMovement;
        }

        if (xMovement < 0x10)
            gCurrentSprite.workVariable2++;
    }
}

/**
 * @brief 1c89c | 128 | Handles a skree crashing on the ground
 * 
 */
void SkreeCrashGround(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;
    u8 spriteID;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    gCurrentSprite.timer++;

    switch (gCurrentSprite.timer)
    {
        case 0x1:
            yPosition += 0x48;
            SpriteDebrisInit(0x0, 0x11, yPosition - 0x10, xPosition);
            SpriteDebrisInit(0x0, 0x12, yPosition, xPosition + 0xC);
            SpriteDebrisInit(0x0, 0x13, yPosition - 0x2A, xPosition + 0x14);
            SpriteDebrisInit(0x0, 0x4, yPosition - 0x18, xPosition - 0x1E);
            break;

        case 0x28:
            gCurrentSprite.pOam = sSkreeOAM_Crashing;
            break;

        case 0x3C:
            gfxSlot = gCurrentSprite.spritesetGFXSlot;
            ramSlot = gCurrentSprite.primarySpriteRAMSlot;

            if (gCurrentSprite.spriteID == PSPRITE_SKREE_BLUE)
                spriteID = SSPRITE_BLUE_SKREE_EXPLOSION;
            else
                spriteID = SSPRITE_SKREE_EXPLOSION;
            
            SpriteSpawnSecondary(spriteID, SKREE_EXPLOSION_PART_GOING_UP, gfxSlot, ramSlot, yPosition - 0x8, xPosition, 0x0);
            SpriteSpawnSecondary(spriteID, SKREE_EXPLOSION_PART_GOING_UP, gfxSlot, ramSlot, yPosition - 0x8, xPosition, SPRITE_STATUS_XFLIP);
            SpriteSpawnSecondary(spriteID, SKREE_EXPLOSION_PART_GOING_DOWN, gfxSlot, ramSlot, yPosition + 0x8, xPosition - 0xC, 0x0);
            SpriteSpawnSecondary(spriteID, SKREE_EXPLOSION_PART_GOING_DOWN, gfxSlot, ramSlot, yPosition + 0x8, xPosition + 0xC, SPRITE_STATUS_XFLIP);
            gCurrentSprite.status = 0x0;
            ParticleSet(yPosition + 0x24, xPosition, PE_SPRITE_EXPLOSION_HUGE);
            SoundPlay(0x134);
    }
}

/**
 * @brief 1c9c4 | b4 | Initializes a skree explosion sprite
 * 
 */
void SkreeExplosionInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    
    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
    
    gCurrentSprite.hitboxTopOffset = -0xC;
    gCurrentSprite.hitboxBottomOffset = 0xC;
    gCurrentSprite.hitboxLeftOffset = -0xC;
    gCurrentSprite.hitboxRightOffset = 0xC;
    
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 0x3;
    gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
    
    gCurrentSprite.yPosition += 0x28;
    gCurrentSprite.status |= (SPRITE_STATUS_DOUBLE_SIZE | SPRITE_STATUS_ROTATION_SCALING);
    gCurrentSprite.oamScaling = 0x100;
    gCurrentSprite.oamRotation = 0x0;

    if (gCurrentSprite.roomSlot != SKREE_EXPLOSION_PART_GOING_UP)
        gCurrentSprite.pOam = sSkreeExplosionOAM_GoingDown;
    else
        gCurrentSprite.pOam = sSkreeExplosionOAM_GoingUp;
}

/**
 * @brief 1ca78 | 68 | Handles the movement of a skree explosion sprite
 * 
 */
void SkreeExplosionMove(void)
{
    if (gCurrentSprite.currentAnimationFrame > 0x1)
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        gCurrentSprite.xPosition += 0x8;
        gCurrentSprite.oamRotation += 0x20;
    }
    else
    {
        gCurrentSprite.xPosition -= 0x8;
        gCurrentSprite.oamRotation -= 0x20;
    }

    if (gCurrentSprite.roomSlot != SKREE_EXPLOSION_PART_GOING_UP)
        gCurrentSprite.yPosition += 0x4;
    else
        gCurrentSprite.yPosition -= 0x4;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}

/**
 * @brief 1cae0 | 194 | Skree AI
 * 
 */
void Skree(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x143);
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
                SkreeInit();

            case 0x8:
                SkreeIdleInit();

            case SKREE_POSE_DETECTING_SAMUS:
                SkreeDetectSamus();
                break;

            case SKREE_POSE_SPINNING_INIT:
                SkreeSpinningInit();

            case SKREE_POSE_SPINNING:
                SkreeCheckSpinAnimEnded();
                break;

            case SKREE_POSE_GOING_DOWN_INIT:
                SkreeGoingDownInit();

            case SKREE_POSE_GOING_DOWN:
                SkreeGoDown();
                break;

            case SKREE_POSE_CRASHING:
                SkreeCrashGround();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition + 0x34, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
        }
    }
}

/**
 * @brief 1cc74 | 24 | Skree explosion AI
 * 
 */
void SkreeExplosion(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            SkreeExplosionInit();

        case 0x9:
            SkreeExplosionMove();
    }
}