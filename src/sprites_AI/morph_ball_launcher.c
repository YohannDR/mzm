#include "morph_ball_launcher.h"
#include "../sprite_util.h"
#include "../projectile.h"
#include "../globals.h"

void morph_ball_launcher_change_ccaa(u8 caa)
{
    u16 sprite_y;
    u16 sprite_x;
    
    sprite_y = gCurrentSprite.y_position;
    sprite_x = gCurrentSprite.x_position;
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

void morph_ball_launcher_init(void)
{
    gCurrentSprite.y_position -= 0x20;
    gCurrentSprite.hitbox_top_offset = 0x0;
    gCurrentSprite.hitbox_bottom_offset = 0x0;
    gCurrentSprite.hitbox_left_offset = 0x0;
    gCurrentSprite.hitbox_right_offset = 0x0;
    gCurrentSprite.draw_distance_top_offset = 0x8;
    gCurrentSprite.draw_distance_bottom_offset = 0x20;
    gCurrentSprite.draw_distance_horizontal_offset = 0x20;
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.oam_pointer = morph_ball_launcher_oam_2de0f8;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.bg_priority = ((gIORegistersBackup.bg2cnt & 0x3) + 0x1) & 0x3;
    gCurrentSprite.draw_order = 0x2;
    sprite_spawn_secondary(SSPRITE_MORPH_BALL_LAUNCHER_BACK, 0x0, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
    morph_ball_launcher_change_ccaa(CCAA_MAKE_SOLID3);
}

void morph_ball_launcher_detect_bomb(void)
{
    struct ProjectileData* pProj;
    u8 has_bomb;
    u8 count;
    u16 sprite_y;
    u16 sprite_x;
    u16 proj_y;
    u16 proj_x;

    has_bomb = FALSE;
    sprite_y = gCurrentSprite.y_position + 0x20;
    sprite_x = gCurrentSprite.x_position;
    count = 0x0;

    while (count <= 0xF)
    {
        pProj = gProjectileData + count;

        if (pProj->status & PROJ_STATUS_EXISTS && pProj->type == PROJ_TYPE_BOMB && pProj->movement_stage == 0x1)
        {
            proj_y = pProj->y_position;
            proj_x = pProj->x_position;

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

void morph_ball_launcher_bomb_timer(void)
{
    gCurrentSprite.timer1--;
    if (gCurrentSprite.timer1 == 0x0)
    {
        gCurrentSprite.oam_pointer = morph_ball_launcher_oam_2de120;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.pose = 0xC;
        gCurrentSprite.timer1 = 0x3C;
        gCurrentSprite.timer2 = 0x0;
    }
}

void morph_ball_launcher_launch_samus_anim(void)
{
    if (gCurrentSprite.timer2 == 0x0 && gSamusData.pose == SPOSE_DELAY_BEFORE_BALLSPARKING)
    {
        sprite_spawn_secondary(SSPRITE_MORPH_BALL_LAUNCHER_BACK, 0x1, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, gSamusData.y_position - 0x10, gSamusData.x_position, 0x0);
        gCurrentSprite.timer2 = 0x1;
    }
    gCurrentSprite.timer1--;
    if (gCurrentSprite.timer1 == 0x0)
    {
        gCurrentSprite.oam_pointer = morph_ball_launcher_oam_2de0f8;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.pose = 0x9;
    }
}

void morph_ball_launcher(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            morph_ball_launcher_init();
            break;
        case 0x9:
            morph_ball_launcher_detect_bomb();
            break;
        case 0xB:
            morph_ball_launcher_bomb_timer();
            break;
        case 0xC:
            morph_ball_launcher_launch_samus_anim();
    }
}

void morph_ball_launcher_back(void)
{

}