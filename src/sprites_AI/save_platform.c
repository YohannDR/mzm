#include "save_platform.h"
#include "../escape.h"
#include "../sprite_util.h"
#include "../samus.h"
#include "../globals.h"

u8 SavePlatformDetectSamus(void)
{
    u8 colliding;
    i32 samus_y;
    i32 samus_x;
    i32 sprite_y;
    i32 sprite_x;

    colliding = FALSE;
    samus_y = gSamusData.y_position;
    samus_x = gSamusData.x_position;
    sprite_y = gCurrentSprite.y_position;
    sprite_x = gCurrentSprite.x_position;

    if (samus_y == (sprite_y - 0x41) && (sprite_x - 0x40) < samus_x && (sprite_x + 0x40) > samus_x)
        colliding = TRUE;
    return colliding;
}

void SavePlatformInit(void)
{
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.y_position_spawn = 0x0;
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.draw_distance_top_offset = 0x10;
    gCurrentSprite.draw_distance_bottom_offset = 0x10;
    gCurrentSprite.draw_distance_horizontal_offset = 0x28;
    gCurrentSprite.hitbox_top_offset = -0x4;
    gCurrentSprite.hitbox_bottom_offset = 0x4;
    gCurrentSprite.hitbox_left_offset = -0x4;
    gCurrentSprite.hitbox_right_offset = 0x4;
    if (gAlarmTimer != 0x0)
        gCurrentSprite.workVariable2 = 0x1;
    else
        gCurrentSprite.workVariable2 = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.timer1 = 0xA;

    if (gCurrentSprite.workVariable2 || EscapeDetermineTimer() != ESCAPE_NONE)
    {
        gCurrentSprite.oam_pointer = save_platform_oam_2d4df4;
        gCurrentSprite.pose = 0x51;
    }
    else if (gIsLoadingFile)
    {
        SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_TOP, 0x0, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
        gCurrentSprite.oam_pointer = save_platform_oam_2d4dc4;
        gCurrentSprite.pose = 0x28;
        gCurrentSprite.y_position_spawn = 0x154;
    }
    else
    {
        gCurrentSprite.oam_pointer = save_platform_oam_2d4cfc;
        gCurrentSprite.pose = 0x9;
    }

    gCurrentSprite.array_offset = SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_TOP, 0x3, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, gCurrentSprite.y_position - 0x200, gCurrentSprite.x_position, 0x0);
}

void SavePlatformSamusDetection(void)
{
    u8 timer;

    if (SavePlatformDetectSamus() << 0x18 && !SpriteUtilCheckCrouchinOrMorphed())
    {
        timer = gCurrentSprite.timer1 = gCurrentSprite.timer1 - 0x1;
        if (timer == 0x0)
        {
            gCurrentSprite.pose = 0x23;
            gCurrentSprite.oam_pointer = save_platform_oam_2d4d34;
            gCurrentSprite.anim_duration_counter = 0x0;
            gCurrentSprite.curr_anim_frame = 0x0;
            SoundPlay(0x112);
        }
    }
    else
        gCurrentSprite.timer1 = 0xA;
}

void SavePlatformCheckOpeningAnimEnded(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.oam_pointer = save_platform_oam_2d4d54;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
    }
}

void SavePlatformSecondSamusDetection(void)
{
    u8 colliding;

    colliding = SavePlatformDetectSamus();
    if (colliding)
    {
        if (!SpriteUtilCheckCrouchinOrMorphed())
        {
            gCurrentSprite.pose = 0x42;
            gCurrentSprite.timer1 = 0x4;
            gSamusData.x_position = gCurrentSprite.x_position;
            if (gSamusData.invincibility_timer != 0x0)
                gSamusData.invincibility_timer = 0x0;
            SamusSetPose(SPOSE_TURNING_FROM_FACING_THE_FOREGROUND);
            gSamusData.timer = 0x1;
            gDisablePause = TRUE;
        }
    }
    else
    {
        gCurrentSprite.pose = 0x27;
        gCurrentSprite.oam_pointer = save_platform_oam_2d4dd4;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        SoundPlay(0x113);
    }
}

void SavePlatformCheckClosingAnimEnded(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.oam_pointer = save_platform_oam_2d4cfc;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.timer1 = 0xA;
    }
}

void SavePlatformReleaseSamus(void)
{
    if (gCurrentSprite.y_position_spawn != 0x0)
        gCurrentSprite.y_position_spawn--;
    else
    {
        gCurrentSprite.pose = 0x29;
        SamusSetPose(SPOSE_FACING_THE_FOREGROUND);
        gDisablePause = FALSE;
    }
}

void SavePlatformSamusDetectionOut(void)
{
    u8 colliding;

    colliding = SavePlatformDetectSamus();
    if (!colliding)
    {
        gCurrentSprite.pose = 0x27;
        gCurrentSprite.oam_pointer = save_platform_oam_2d4dd4;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        SoundPlay(0x113);
    }
}

void SavePlatformSpawnSprites(void)
{
    u8 offset;

    if (gCurrentSprite.timer1 != 0x0)
    {
        gCurrentSprite.timer1--;
        if (gCurrentSprite.timer1 == 0x0)
            gCurrentSprite.workVariable = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, 0x16, 0x6, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
    }
    else
    {
        offset = gCurrentSprite.workVariable;
        if (gSpriteData[offset].pose == 0x25)
        {
            if (gSpriteData[offset].workVariable == 0x1)
            {
                gCurrentSprite.oam_pointer = save_platform_oam_2d4d8c;
                gCurrentSprite.anim_duration_counter = 0x0;
                gCurrentSprite.curr_anim_frame = 0x0;
                gCurrentSprite.pose = 0x43;
                SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_TOP, 0x0, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
                gSpriteData[gCurrentSprite.array_offset].pose = 0x44;
                gSamusData.invincibility_timer = 0x0;
                SoundPlay(0x114);
            }
            else
            {
                gCurrentSprite.pose = 0x4B;
                gCurrentSprite.timer1 = 0xA;
            }
        }
    }
}

void SavePlatformFlashingAnim(void)
{
    u8 offset;

    offset = gCurrentSprite.array_offset;
    if (gCurrentSprite.curr_anim_frame & 0x1)
    {
        gCurrentSprite.palette_row = 0x0;
        gSpriteData[offset].palette_row = gCurrentSprite.palette_row;
    }
    else
    {
        gCurrentSprite.palette_row = 0x2;
        gSpriteData[offset].palette_row = gCurrentSprite.palette_row;
    }
}

void SavePlatformFlashingAnimEnd(void)
{
    gCurrentSprite.oam_pointer = save_platform_oam_2d4dc4;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.pose = 0x47;
    gCurrentSprite.timer1 = 0x3C;
    gCurrentSprite.palette_row = 0x0;
    gSpriteData[gCurrentSprite.array_offset].palette_row = 0x0;
}

void SavePlatformTextTimer(void)
{
    u8 timer;

    timer = gCurrentSprite.timer1 = gCurrentSprite.timer1 - 0x1;
    if (timer == 0x0)
    {
        gCurrentSprite.pose = 0x49;
        gCurrentSprite.workVariable = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, 0x17, 0x6, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
    }
}

void SavePlatformCheckMessageBannerOut(void)
{
    u8 offset;

    offset = gCurrentSprite.workVariable;
    if (gSpriteData[offset].pose == 0x25)
    {
        gCurrentSprite.pose = 0x4B;
        gCurrentSprite.timer1 = 0xA;
    }
}

void SavePlatformMessageBannerDisappearingTimer(void)
{
    gCurrentSprite.timer1--;
    if (gCurrentSprite.timer1 == 0x0)
        gCurrentSprite.pose = 0x28;
}

void SavePlatformTopInit(void)
{
    u8 offset;

    offset = gCurrentSprite.primary_sprite_ram_slot;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.hitbox_top_offset = -0x4;
    gCurrentSprite.hitbox_bottom_offset = 0x4;
    gCurrentSprite.hitbox_left_offset = -0x4;
    gCurrentSprite.hitbox_right_offset = 0x4;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;

    switch (gCurrentSprite.room_slot)
    {
        case 0x0:
            gCurrentSprite.draw_distance_top_offset = 0x50;
            gCurrentSprite.draw_distance_bottom_offset = 0x0;
            gCurrentSprite.draw_distance_horizontal_offset = 0x18;
            if (gSpriteData[offset].pose == 0x28)
            {
                gCurrentSprite.oam_pointer = save_platform_top_oam_2d5024;
                gCurrentSprite.y_position_spawn = 0x136;
                gCurrentSprite.pose = 0x25;
            }
            else
            {
                gCurrentSprite.oam_pointer = save_platform_top_oam_2d4e84;
                gCurrentSprite.pose = 0x9;
            }
            break;

        case 0x1:
            gCurrentSprite.draw_order = 0xC;
            gCurrentSprite.oam_pointer = save_platform_top_oam_2d4fbc;
            gCurrentSprite.draw_distance_top_offset = 0x50;
            gCurrentSprite.draw_distance_bottom_offset = 0x0;
            gCurrentSprite.draw_distance_horizontal_offset = 0x18;
            gCurrentSprite.pose = 0x29;
            break;

        case 0x2:
            gCurrentSprite.draw_order = 0x5;
            gCurrentSprite.oam_pointer = save_platform_top_oam_2d50ec;
            gCurrentSprite.draw_distance_top_offset = 0x8;
            gCurrentSprite.draw_distance_bottom_offset = 0x0;
            gCurrentSprite.draw_distance_horizontal_offset = 0x18;
            gCurrentSprite.pose = 0x2B;
            gCurrentSprite.timer1 = 0x60;
            break;

        case 0x3:
            gCurrentSprite.draw_order = 0x3;
            gCurrentSprite.draw_distance_top_offset = 0x20;
            gCurrentSprite.draw_distance_bottom_offset = 0x40;
            gCurrentSprite.draw_distance_horizontal_offset = 0x20;
            gCurrentSprite.pose = 0x43;
            if (gSpriteData[offset].pose == 0x28)
                gCurrentSprite.oam_pointer = save_platform_top_oam_2d4e44;
            else
                gCurrentSprite.oam_pointer = save_platform_top_oam_2d4e04;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

void SavePlatformTop_Empty(void)
{
    return;
}

void SavePlatformTopExtendGFXInit(void)
{
    gCurrentSprite.oam_pointer = save_platform_top_oam_2d4e14;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.pose = 0x45;
}

void SavePlatformTopCheckExtendingEnded(void)
{
    if (SpriteUtilCheckEndSpriteAnim())
    {
        gCurrentSprite.pose = 0x43;
        gCurrentSprite.oam_pointer = save_platform_top_oam_2d4e44;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
    }
}

void SavePlatformTopRetractGFXInit(void)
{
    gCurrentSprite.oam_pointer = save_platform_top_oam_2d4e54;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.pose = 0x47;
    gSamusData.timer = 0x1;
    SoundPlay(0x115);
}

void SavePlatformTopCheckRetractingAnimEnded(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0x43;
        gCurrentSprite.oam_pointer = save_platform_top_oam_2d4e04;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
    }
}

void SavePlatformTopCheckTubeAnimSpawnEnded(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0x23;
        gCurrentSprite.oam_pointer = save_platform_top_oam_2d5024;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.workVariable = SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_TOP, 0x1, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
    }
}

void SavePlatformTopSpawnBigLight(void)
{
    u8 offset;

    offset = gCurrentSprite.workVariable;
    if (gSpriteData[offset].status == 0x0)
    {
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.y_position_spawn = 0x78;
        SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_TOP, 0x2, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
    }
}

void SavePlatformTopCheckTubeAnimEnded(void)
{
    gCurrentSprite.y_position_spawn--;
    if (gCurrentSprite.y_position_spawn == 0x0)
    {
        gCurrentSprite.pose = 0x27;
        gCurrentSprite.oam_pointer = save_platform_top_oam_2d5064;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
    }
}

void SavePlatformTopCheckTubeAnimDespawnEnded(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.status = 0x0;
        gSpriteData[gSpriteData[gCurrentSprite.primary_sprite_ram_slot].array_offset].pose = 0x46;
    }
}

void SavePlatformTopCheckTubeAroundAnimEnded(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}

void SavePlatformTopTubeDownUpAnim(void)
{
    gCurrentSprite.y_position -= 0x4;
    gCurrentSprite.timer1--;
    if (gCurrentSprite.timer1 == 0x0)
    {
        gSpriteData[gCurrentSprite.primary_sprite_ram_slot].pose = 0x45;
        gCurrentSprite.status = 0x0;
    }
}

void SavePlatform(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            SavePlatformInit();
            break;
        case 0x9:
            SavePlatformSamusDetection();
            break;
        case 0x23:
            SavePlatformCheckOpeningAnimEnded();
            break;
        case 0x25:
            SavePlatformSecondSamusDetection();
            break;
        case 0x27:
            SavePlatformCheckClosingAnimEnded();
            break;
        case 0x28:
            SavePlatformReleaseSamus();
            break;
        case 0x29:
            SavePlatformSamusDetectionOut();
            break;
        case 0x42:
            SavePlatformSpawnSprites();
            break;
        case 0x43:
            SavePlatformFlashingAnim();
            break;
        case 0x45:
            SavePlatformFlashingAnimEnd();
            break;
        case 0x47:
            SavePlatformTextTimer();
            break;
        case 0x49:
            SavePlatformCheckMessageBannerOut();
            break;
        case 0x4B:
            SavePlatformMessageBannerDisappearingTimer();
    }
}

void SavePlatformTop(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            SavePlatformTopInit();
            break;
        case 0x9:
            SavePlatformTopCheckTubeAnimSpawnEnded();
            break;
        case 0x23:
            SavePlatformTopSpawnBigLight();
            break;
        case 0x25:
            SavePlatformTopCheckTubeAnimEnded();
            break;
        case 0x27:
            SavePlatformTopCheckTubeAnimDespawnEnded();
            break;
        case 0x29:
            SavePlatformTopCheckTubeAroundAnimEnded();
            break;
        case 0x2B:
            SavePlatformTopTubeDownUpAnim();
            break;
        case 0x43:
            SavePlatformTop_Empty();
            break;
        case 0x44:
            SavePlatformTopExtendGFXInit();
            break;
        case 0x45:
            SavePlatformTopCheckExtendingEnded();
            break;
        case 0x46:
            SavePlatformTopRetractGFXInit();
            break;
        case 0x47:
            SavePlatformTopCheckRetractingAnimEnded();
    }
}