#include "morph_ball_launcher.h"
#include "../sprite_util.h"
#include "../projectile.h"
#include "../globals.h"

void MorphBallLauncherChangeCCAA(u8 caa)
{
    u16 spriteY;
    u16 spriteX;
    
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(spriteY, spriteX + 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(spriteY + 0x40, spriteX + 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(spriteY, spriteX - 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(spriteY + 0x40, spriteX - 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(spriteY + 0x40, spriteX);
}

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
    gCurrentSprite.pOam = morph_ball_launcher_oam_2de0f8;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.bg_priority = ((gIORegistersBackup.BG1CNT & 0x3) + 0x1) & 0x3;
    gCurrentSprite.drawOrder = 0x2;
    SpriteSpawnSecondary(SSPRITE_MORPH_BALL_LAUNCHER_BACK, 0x0, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    MorphBallLauncherChangeCCAA(CCAA_MAKE_SOLID3);
}

void MorphBallLauncherDetectBomb(void)
{
    struct ProjectileData* pProj;
    u8 has_bomb;
    u8 count;
    u16 spriteY;
    u16 spriteX;
    u16 proj_y;
    u16 proj_x;

    has_bomb = FALSE;
    spriteY = gCurrentSprite.yPosition + 0x20;
    spriteX = gCurrentSprite.xPosition;
    count = 0x0;

    while (count <= 0xF)
    {
        pProj = gProjectileData + count;

        if (pProj->status & PROJ_STATUS_EXISTS && pProj->type == PROJ_TYPE_BOMB && pProj->movement_stage == 0x1)
        {
            proj_y = pProj->yPosition;
            proj_x = pProj->xPosition;

            if (proj_y < spriteY && proj_y > (i32)(spriteY - 0x8) && proj_x < (spriteX + 0x8) && proj_x > (i32)(spriteX - 0x8))
            {
                pProj->movement_stage = 0x4;
                has_bomb++;
                break;
            }
        }
        count++;
    }

    if (has_bomb)
    {
        gCurrentSprite.pose = 0xB;
        gCurrentSprite.timer = 0x20;
    }
}

void MorphBallLauncherBombTimer(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pOam = morph_ball_launcher_oam_2de120;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = 0xC;
        gCurrentSprite.timer = 0x3C;
        gCurrentSprite.workVariable = 0x0;
    }
}

void MorphBallLauncherLaunchSamusAnim(void)
{
    if (gCurrentSprite.workVariable == 0x0 && gSamusData.pose == SPOSE_DELAY_BEFORE_BALLSPARKING)
    {
        SpriteSpawnSecondary(SSPRITE_MORPH_BALL_LAUNCHER_BACK, 0x1, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gSamusData.yPosition - 0x10, gSamusData.xPosition, 0x0);
        gCurrentSprite.workVariable = 0x1;
    }
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pOam = morph_ball_launcher_oam_2de0f8;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = 0x9;
    }
}

void MorphBallLauncher(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            MorphBallLauncherInit();
            break;
        case 0x9:
            MorphBallLauncherDetectBomb();
            break;
        case 0xB:
            MorphBallLauncherBombTimer();
            break;
        case 0xC:
            MorphBallLauncherLaunchSamusAnim();
    }
}

void MorphBallLauncherBack(void)
{

}