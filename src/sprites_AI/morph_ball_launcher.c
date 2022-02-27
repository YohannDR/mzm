#include "morph_ball_launcher.h"
#include "../sprite_util.h"
#include "../projectile.h"
#include "../globals.h"

void morph_ball_launcher_change_ccaa(enum current_clipdata_affecting_action caa)
{
    u16 sprite_y;
    u16 sprite_x;
    
    sprite_y = current_sprite.y_position;
    sprite_x = current_sprite.x_position;
    current_clipdata_affecting_action = caa;
    clipdata_related(sprite_y, sprite_x + 0x40);
    current_clipdata_affecting_action = caa;
    clipdata_related(sprite_y + 0x40, sprite_x + 0x40);
    current_clipdata_affecting_action = caa;
    clipdata_related(sprite_y, sprite_x - 0x40);
    current_clipdata_affecting_action = caa;
    clipdata_related(sprite_y + 0x40, sprite_x - 0x40);
    current_clipdata_affecting_action = caa;
    clipdata_related(sprite_y + 0x40, sprite_x);
}

void morph_ball_launcher_init(void)
{
    current_sprite.y_position -= 0x20;
    current_sprite.hitbox_top_offset = 0x0;
    current_sprite.hitbox_bottom_offset = 0x0;
    current_sprite.hitbox_left_offset = 0x0;
    current_sprite.hitbox_right_offset = 0x0;
    current_sprite.draw_distance_top_offset = 0x8;
    current_sprite.draw_distance_bottom_offset = 0x20;
    current_sprite.draw_distance_horizontal_offset = 0x20;
    current_sprite.samus_collision = SSC_NONE;
    current_sprite.oam_pointer = morph_ball_launcher_oam_2de0f8;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.pose = 0x9;
    current_sprite.bg_priority = ((io_registers_backup.bg2cnt & 0x3) + 0x1) & 0x3;
    current_sprite.draw_order = 0x2;
    sprite_spawn_secondary(SSPRITE_MORPH_BALL_LAUNCHER_BACK, 0x0, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, current_sprite.y_position, current_sprite.x_position, 0x0);
    morph_ball_launcher_change_ccaa(CCAA_MAKE_SOLID);
}

void morph_ball_launcher_detect_bomb(void)
{
    struct projectile_data* pProj;
    u8 has_bomb;
    u8 count;
    u16 sprite_y;
    u16 sprite_x;
    u16 proj_y;
    u16 proj_x;

    has_bomb = FALSE;
    sprite_y = current_sprite.y_position + 0x20;
    sprite_x = current_sprite.x_position;
    count = 0x0;

    while (count <= 0xF)
    {
        pProj = projectile_data + count;

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
        current_sprite.pose = 0xB;
        current_sprite.timer1 = 0x20;
    }
}

void morph_ball_launcher_bomb_timer(void)
{
    current_sprite.timer1--;
    if (current_sprite.timer1 == 0x0)
    {
        current_sprite.oam_pointer = morph_ball_launcher_oam_2de120;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.pose = 0xC;
        current_sprite.timer1 = 0x3C;
        current_sprite.timer2 = 0x0;
    }
}

void morph_ball_launcher_launch_samus_anim(void)
{
    if (current_sprite.timer2 == 0x0 && samus_data.pose == SPOSE_DELAY_BEFORE_BALLSPARKING)
    {
        sprite_spawn_secondary(SSPRITE_MORPH_BALL_LAUNCHER_BACK, 0x1, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, samus_data.y_position - 0x10, samus_data.x_position, 0x0);
        current_sprite.timer2 = 0x1;
    }
    current_sprite.timer1--;
    if (current_sprite.timer1 == 0x0)
    {
        current_sprite.oam_pointer = morph_ball_launcher_oam_2de0f8;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.pose = 0x9;
    }
}

void morph_ball_launcher(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    switch (current_sprite.pose)
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