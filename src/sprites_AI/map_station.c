#include "map_station.h"
#include "../sprite.h"
#include "../sprite_util.h"
#include "../samus.h"
#include "../globals.h"

void MapStationInit(void)
{
    gCurrentSprite.y_position += 0x80;
    gCurrentSprite.draw_distance_top_offset = 0x80;
    gCurrentSprite.draw_distance_bottom_offset = 0x10;
    gCurrentSprite.draw_distance_horizontal_offset = 0x1C;
    gCurrentSprite.hitbox_top_offset = -0x200;
    gCurrentSprite.hitbox_left_offset = -0x20;
    gCurrentSprite.hitbox_right_offset = 0x20;
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.draw_order = 0x4;
    gCurrentSprite.bg_priority = 0x1;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;

    if ((gEquipment.downloaded_map_status >> gCurrentArea) & 0x1 || gAlarmTimer != 0x0)
    {
        gCurrentSprite.hitbox_bottom_offset = -0x40;
        gCurrentSprite.pose = 0xF;
        gCurrentSprite.oam_pointer = map_station_oam_2d3788;
        gCurrentSprite.curr_anim_frame = 0x13;
        gCurrentSprite.anim_duration_counter = 0x0;
    }
    else
    {
        gCurrentSprite.hitbox_bottom_offset = 0x40;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.oam_pointer = map_station_oam_2d36f8;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.anim_duration_counter = 0x0;
        sprite_util_spawn_secondary(SSPRITE_MAP_STATION_SCREEN, 0x0, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
        sprite_util_spawn_secondary(SSPRITE_MAP_STATION_SCREEN, 0x1, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
    }
}

void MapStationSamusDetection(void)
{
    i32 samus_y;
    i32 samus_x;
    u16 sprite_y;
    u16 sprite_x;

    samus_y = gSamusData.y_position;
    samus_x = gSamusData.x_position;
    sprite_y = (u16)(gCurrentSprite.y_position + 0x80);
    sprite_x = (u16)(gCurrentSprite.x_position + 0x60);

    if (!SpriteUtilCheckCrouchinOrMorphed() && samus_y == sprite_y - 0x1 && sprite_x - 0x40 < samus_x && sprite_x + 0x40 > samus_x)
    {
        gCurrentSprite.oam_pointer = map_station_oam_2d3708;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.pose = 0x23;
        gSamusData.x_position = sprite_x;
        if (gSamusData.invincibility_timer != 0x0)
            gSamusData.invincibility_timer = 0x0;

        if (gSamusData.direction & KEY_RIGHT)
            SamusSetPose(SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA);
        else
            SamusSetPose(SPOSE_DOWNLOADING_MAP_DATA);
        SoundPlay(0x123);
    }
}

void MapStationCheckSamusGrabbedAnimEnded(void)
{
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.oam_pointer = map_station_oam_2d3758;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.timer1 = 0x46;
        gSamusData.timer = 0x0;
    }
}

void MapStationDownloadingAnim(void)
{
    u32 timer;

    timer = gCurrentSprite.timer1 - 0x1;
    gCurrentSprite.timer1 = timer;
    if ((u8)timer == 0x0)
    {
        gCurrentSprite.oam_pointer = map_station_oam_2d3778;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.pose = 0x27;
        gCurrentSprite.timer1 = 0xA;
    }
    else if (timer == 0xA)
        gPauseScreenFlag = 0x5;
}

void MapStationSpawnMessage(void)
{
    u8 text;

    gCurrentSprite.timer1--;
    if (gCurrentSprite.timer1 == 0x0)
    {
        switch (gCurrentArea)
        {
            case AREA_BRINSTAR:
                text = 0x1B;
                break;
            case AREA_KRAID:
                text = 0x1C;
                break;
            case AREA_NORFAIR:
                text = 0x1D;
                break;
            case AREA_RIDLEY:
                text = 0x1E;
                break;
            case AREA_CHOZODIA:
                text = 0x1F;
                break;
            default:
                text = 0x23;
        }

        gCurrentSprite.workVariable = SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, text, 0x6, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
        gCurrentSprite.hitbox_top_offset = -0x40;
        gCurrentSprite.pose = 0x29;
        gSamusData.curr_anim_frame = 0x0;
        gSamusData.timer = 0x1;
        call_sound_function(0x123, 0xA);
    }
}

void MapStationAfterDownload(void)
{
    u8 slot;

    slot = gCurrentSprite.workVariable;
    if (gSpriteData[slot].pose == 0x25)
    {
        gCurrentSprite.pose = 0x2B;
        gCurrentSprite.timer1 = 0xA;
    }
}

void MapStationBeforeRetraction(void)
{
    gCurrentSprite.timer1--;
    if (gCurrentSprite.timer1 == 0x0)
        gCurrentSprite.pose = 0x2D;
}

void MapStationRetraction(void)
{
    gCurrentSprite.pose = 0x2F;
    gCurrentSprite.oam_pointer = map_station_oam_2d3788;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
    SamusSetPose(SPOSE_STANDING);
    SoundPlay(0x124);
}

void MapStation(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            MapStationInit();
            break;
        case 0x9:
            MapStationSamusDetection();
            break;
        case 0x23:
            MapStationCheckSamusGrabbedAnimEnded();
            break;
        case 0x25:
            MapStationDownloadingAnim();
            break;
        case 0x27:
            MapStationSpawnMessage();
            break;
        case 0x29:
            MapStationAfterDownload();
            break;
        case 0x2B:
            MapStationBeforeRetraction();
            break;
        case 0x2D:
            MapStationRetraction();
    }
}

void MapStationScreen(void)
{

}