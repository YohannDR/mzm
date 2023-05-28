#include "sprites_AI/morph_ball_launcher.h"
#include "data/sprites/morph_ball_launcher.h"
#include "constants/clipdata.h"
#include "constants/sprite.h"
#include "constants/samus.h"
#include "constants/projectile.h"
#include "structs/display.h"
#include "structs/clipdata.h"
#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/projectile.h"

/**
 * @brief 268bc | 74 | Updates the clipdata of a morph ball launcher
 * 
 * @param caa Clipdata Affecting Action
 */
void MorphBallLauncherChangeCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;
    
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    // Top right
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE);
    // Bottom right
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition + BLOCK_SIZE);

    // Top left
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE);
    // Bottom Left
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition - BLOCK_SIZE);

    // Bottom middle
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition);
}

/**
 * @brief 26930 | 94 | Initializes a morph ball launcher sprite 
 * 
 */
void MorphBallLauncherInit(void)
{
    gCurrentSprite.yPosition -= 0x20;
    gCurrentSprite.hitboxTopOffset = 0x0;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = 0x0;
    gCurrentSprite.hitboxRightOffset = 0x0;

    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x20;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pOam = sMorphBallLauncherOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = MORPH_BALL_LAUNCHER_POSE_IDLE;
    gCurrentSprite.bgPriority = ((gIoRegistersBackup.BG1CNT & 0x3) + 0x1) & 0x3;
    gCurrentSprite.drawOrder = 0x2;

    // Spawn back
    SpriteSpawnSecondary(SSPRITE_MORPH_BALL_LAUNCHER_PART, MORPH_BALL_LAUNCHER_PART_BACK, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

    // Set hitbox
    MorphBallLauncherChangeCCAA(CAA_MAKE_NON_POWER_GRIP);
}

/**
 * @brief 269c4 | 94 | Checks if there's a bomb on the launcher
 * 
 */
void MorphBallLauncherDetectBomb(void)
{
    struct ProjectileData* pProj;
    u8 hasBomb;
    u8 count;
    u16 spriteY;
    u16 spriteX;
    u16 projY;
    u16 projX;

    hasBomb = FALSE;
    spriteY = gCurrentSprite.yPosition + HALF_BLOCK_SIZE;
    spriteX = gCurrentSprite.xPosition;

    for (count = 0x0; count < MAX_AMOUNT_OF_PROJECTILES; count++)
    {
        pProj = gProjectileData + count;

        if (pProj->status & PROJ_STATUS_EXISTS && pProj->type == PROJ_TYPE_BOMB && pProj->movementStage == BOMB_STAGE_FIRST_SPIN)
        {
            projY = pProj->yPosition;
            projX = pProj->xPosition;

            if (projY < spriteY && projY > spriteY - 0x8 && projX < spriteX + 0x8 && projX > spriteX - 0x8)
            {
                pProj->movementStage = BOMB_STAGE_PLACED_ON_LAUNCHER;
                hasBomb++;
                break;
            }
        }
    }

    if (hasBomb)
    {
        gCurrentSprite.pose = MORPH_BALL_LAUNCHER_POSE_DELAY_BEFORE_LAUNCHING;
        gCurrentSprite.timer = 0x20;
    }
}

/**
 * @brief 26a58 | 40 | Delay before samus is launched
 * 
 */
void MorphBallLauncherDelayBeforeLaunching(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pOam = sMorphBallLauncherOAM_Launching;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = MORPH_BALL_LAUNCHER_POSE_LAUNCHING;
        gCurrentSprite.timer = 0x3C;
        gCurrentSprite.workVariable = 0x0;
    }
}

/**
 * @brief 26a98 | 40 | Handles the launcher launching Samus
 * 
 */
void MorphBallLauncherLaunchSamus(void)
{
    if (gCurrentSprite.workVariable == 0x0 && gSamusData.pose == SPOSE_DELAY_BEFORE_BALLSPARKING)
    {
        SpriteSpawnSecondary(SSPRITE_MORPH_BALL_LAUNCHER_PART, MORPH_BALL_LAUNCHER_PART_ENERGY, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSamusData.yPosition - 0x10, gSamusData.xPosition, 0x0);
        gCurrentSprite.workVariable = 0x1;
    }

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pOam = sMorphBallLauncherOAM_Idle;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = MORPH_BALL_LAUNCHER_POSE_IDLE;
    }
}

/**
 * @brief 26b08 | 48 | Morph ball launcher AI
 * 
 */
void MorphBallLauncher(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            MorphBallLauncherInit();
            break;
        case MORPH_BALL_LAUNCHER_POSE_IDLE:
            MorphBallLauncherDetectBomb();
            break;
        case MORPH_BALL_LAUNCHER_POSE_DELAY_BEFORE_LAUNCHING:
            MorphBallLauncherDelayBeforeLaunching();
            break;
        case MORPH_BALL_LAUNCHER_POSE_LAUNCHING:
            MorphBallLauncherLaunchSamus();
    }
}

/**
 * @brief 26b50 | e8 | Morph ball launcher part AI
 * 
 */
void MorphBallLauncherPart(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            if (gCurrentSprite.roomSlot == MORPH_BALL_LAUNCHER_PART_BACK)
            {
                gCurrentSprite.pOam = sMorphBallLauncherPartOAM_Back;
                gCurrentSprite.drawDistanceTopOffset = 0x8;
                gCurrentSprite.drawDistanceBottomOffset = 0x0;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

                gCurrentSprite.bgPriority = ((gIoRegistersBackup.BG1CNT & 0x3) + 0x1) & 0x3;
                gCurrentSprite.drawOrder = 0xC;
                gCurrentSprite.pose = MORPH_BALL_LAUNCHER_PART_POSE_IDLE;
            }
            else if (gCurrentSprite.roomSlot == MORPH_BALL_LAUNCHER_PART_ENERGY)
            {
                gCurrentSprite.pOam = sMorphBallLauncherPartOAM_Energy;
                gCurrentSprite.drawDistanceTopOffset = 0x18;
                gCurrentSprite.drawDistanceBottomOffset = 0x18;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

                gCurrentSprite.bgPriority = gIoRegistersBackup.BG1CNT & 0x3;
                gCurrentSprite.drawOrder = 0x1;
                gCurrentSprite.pose = MORPH_BALL_LAUNCHER_PART_POSE_ENERGY;
                gCurrentSprite.timer = 0x3C;
            }
            else
                gCurrentSprite.status = 0x0;
            break;

        case MORPH_BALL_LAUNCHER_PART_POSE_ENERGY:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
                gCurrentSprite.status = 0x0;
    }
}