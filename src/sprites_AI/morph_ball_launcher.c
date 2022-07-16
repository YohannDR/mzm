#include "morph_ball_launcher.h"
#include "../sprite_util.h"
#include "../projectile.h"
#include "../globals.h"

void MorphBallLauncherChangeCCAA(u8 caa)
{
    u16 sprite_y;
    u16 sprite_x;
    
    sprite_y = gCurrentSprite.yPosition;
    sprite_x = gCurrentSprite.xPosition;
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(sprite_y, sprite_x + 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(sprite_y + 0x40, sprite_x + 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(sprite_y, sprite_x - 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(sprite_y + 0x40, sprite_x - 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(sprite_y + 0x40, sprite_x);
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
    gCurrentSprite.draw_distance_horizontal_offset = 0x20;
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.oam_pointer = morph_ball_launcher_oam_2de0f8;
    gCurrentSprite.animationDuratoinCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.bg_priority = ((gIORegistersBackup.BG1CNT & 0x3) + 0x1) & 0x3;
    gCurrentSprite.draw_order = 0x2;
    SpriteSpawnSecondary(SSPRITE_MORPH_BALL_LAUNCHER_BACK, 0x0, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    MorphBallLauncherChangeCCAA(CCAA_MAKE_SOLID3);
}

void MorphBallLauncherDetectBomb(void)
{
    struct ProjectileData* pProj;
    u8 has_bomb;
    u8 count;
    u16 sprite_y;
    u16 sprite_x;
    u16 proj_y;
    u16 proj_x;

    has_bomb = FALSE;
    sprite_y = gCurrentSprite.yPosition + 0x20;
    sprite_x = gCurrentSprite.xPosition;
    count = 0x0;

    while (count <= 0xF)
    {
        pProj = gProjectileData + count;

        if (pProj->status & PROJ_STATUS_EXISTS && pProj->type == PROJ_TYPE_BOMB && pProj->movement_stage == 0x1)
        {
            proj_y = pProj->yPosition;
            proj_x = pProj->xPosition;

            if (proj_y < sprite_y && proj_y > (i32)(sprite_y - 0x8) && proj_x < (sprite_x + 0x8) && proj_x > (i32)(sprite_x - 0x8))
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
        gCurrentSprite.timer1 = 0x20;
    }
}

void MorphBallLauncherBombTimer(void)
{
    gCurrentSprite.timer1--;
    if (gCurrentSprite.timer1 == 0x0)
    {
        gCurrentSprite.oam_pointer = morph_ball_launcher_oam_2de120;
        gCurrentSprite.animationDuratoinCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = 0xC;
        gCurrentSprite.timer1 = 0x3C;
        gCurrentSprite.workVariable = 0x0;
    }
}

void MorphBallLauncherLaunchSamusAnim(void)
{
    if (gCurrentSprite.workVariable == 0x0 && gSamusData.pose == SPOSE_DELAY_BEFORE_BALLSPARKING)
    {
        SpriteSpawnSecondary(SSPRITE_MORPH_BALL_LAUNCHER_BACK, 0x1, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, gSamusData.yPosition - 0x10, gSamusData.xPosition, 0x0);
        gCurrentSprite.workVariable = 0x1;
    }
    gCurrentSprite.timer1--;
    if (gCurrentSprite.timer1 == 0x0)
    {
        gCurrentSprite.oam_pointer = morph_ball_launcher_oam_2de0f8;
        gCurrentSprite.animationDuratoinCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = 0x9;
    }
}

void MorphBallLauncher(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
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