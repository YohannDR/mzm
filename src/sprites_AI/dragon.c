#include "dragon.h"
#include "../sprite_util.h"
#include "../globals.h"

void dragon_y_movement(void)
{
    u16 old_y;
    u16 y_spawn;

    old_y = gCurrentSprite.y_position;
    y_spawn = gCurrentSprite.y_position_spawn;

    if (gCurrentSprite.status & SPRITE_STATUS_ON_VERTICAL_WALL)
    {
        if ((i32)(y_spawn - 0x7F) < gCurrentSprite.y_position)
            gCurrentSprite.y_position -= 0x2;
        SpriteUtilCheckOutOfRoomEffect(old_y, gCurrentSprite.y_position, gCurrentSprite.x_position, SPLASH_SMALL);
    }
    else
    {
        if ((i32)(y_spawn - 0x2) > gCurrentSprite.y_position)
            gCurrentSprite.y_position += 0x2;
        SpriteUtilCheckInRoomEffect(old_y, gCurrentSprite.y_position, gCurrentSprite.x_position, SPLASH_SMALL);
    }
}

void dragon_init(void)
{
    gCurrentSprite.hitbox_top_offset = -0x40;
    gCurrentSprite.hitbox_bottom_offset = 0x50;
    gCurrentSprite.hitbox_left_offset = -0x18;
    gCurrentSprite.hitbox_right_offset = 0x18;
    gCurrentSprite.draw_distance_top_offset = 0x18;
    gCurrentSprite.draw_distance_bottom_offset = 0x18;
    gCurrentSprite.draw_distance_horizontal_offset = 0x18;
    gCurrentSprite.oam_pointer = dragon_oam_2d5ad8;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.samus_collision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    SpriteUtilMakeSpriteFaceSamusXFlip();
    gCurrentSprite.pose = 0x8;
    gCurrentSprite.y_position_spawn = gCurrentSprite.y_position;
}

void dragon_gfx_init(void)
{
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.oam_pointer = dragon_oam_2d5ad8;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.timer1 = 0x64;
}

void dragon_go_up(void)
{
    /*u8 nslr;
    u16 x_position;
    u16 y_position;

    if (gCurrentSprite.timer1 != 0x0)
        gCurrentSprite.timer1--;

    dragon_y_movement();
    gCurrentSprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
    if (gSamusData.y_position <= gCurrentSprite.y_position)
    {
        nslr = SpriteUtilCheckSamusNearSpriteLeftRight(0x180, 0x180);
        if (nslr != NSLR_OUT_OF_RANGE)
            gCurrentSprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
        
        if (nslr == NSLR_RIGHT)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            {
                if (gCurrentSprite.timer1 == 0x0)
                {
                    y_position = gCurrentSprite.y_position - 0x88;
                    x_position = gCurrentSprite.x_position + 0x48;
                    SpriteUtilCheckCollisionAtPosition(y_position, x_position);
                    if (gPreviousCollisionCheck == 0x0)
                        gCurrentSprite.pose = 0x34;
                }
            }
        }
        else if (nslr == NSLR_LEFT)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                gCurrentSprite.pose = 0xA;
            else
            {
                if (gCurrentSprite.timer1 == 0x0)
                {
                    y_position = gCurrentSprite.y_position - 0x88;
                    x_position = gCurrentSprite.x_position - 0x48;
                    SpriteUtilCheckCollisionAtPosition(y_position, x_position);
                    if (gPreviousCollisionCheck == 0x0)
                        gCurrentSprite.pose = 0x34;
                }
            }
        }
    }*/
}

void dragon_turning_turning_around_gfx_init(void)
{
    gCurrentSprite.pose = 0xB;
    gCurrentSprite.oam_pointer = dragon_oam_2d5b28;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
}

void dragon_check_turning_around_first_half_anim_ended(void)
{
    dragon_y_movement();
    if (SpriteUtillCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0xC;
        gCurrentSprite.oam_pointer = dragon_oam_2d5b40;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.status ^= SPRITE_STATUS_XFLIP;
    }
}

void dragon_check_turning_around_second_half_anim_ended(void)
{
    dragon_y_movement();
    if (SpriteUtillCheckEndCurrentSpriteAnim())
        gCurrentSprite.pose = 0x34;
}

void dragon_spitting_gfx_init(void)
{
    gCurrentSprite.pose = 0x35;
    gCurrentSprite.oam_pointer = dragon_oam_2d5af8;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.timer1 = 0x1E;
}

void dragon_spitting_anim(void)
{
    dragon_y_movement();
    gCurrentSprite.timer1--;
    if (gCurrentSprite.timer1 == 0x0)
    {
        gCurrentSprite.pose = 0x37;
        gCurrentSprite.oam_pointer = dragon_oam_2d5b10;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.timer1 = 0x8;
    }
}

void dragon_spawn_fireball(void)
{
    u16 y_position;
    u16 x_position;

    gCurrentSprite.timer1--;
    if (gCurrentSprite.timer1 == 0x0)
    {
        dragon_gfx_init();
        y_position = gCurrentSprite.y_position - 0x48;
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            x_position = gCurrentSprite.x_position + 0x28;
        else
            x_position = gCurrentSprite.x_position - 0x28;
        SpriteSpawnSecondary(SSPRITE_DRAGON_FIREBALL, 0x0, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, y_position, x_position, gCurrentSprite.status & SPRITE_STATUS_XFLIP);
    }
}

void dragon_fireball_init(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_PROJECTILE;
    gCurrentSprite.draw_distance_top_offset = 0x8;
    gCurrentSprite.draw_distance_bottom_offset = 0x8;
    gCurrentSprite.draw_distance_horizontal_offset = 0x8;
    gCurrentSprite.hitbox_top_offset = -0x10;
    gCurrentSprite.hitbox_bottom_offset = 0x10;
    gCurrentSprite.hitbox_left_offset = -0x10;
    gCurrentSprite.hitbox_right_offset = 0x10;
    gCurrentSprite.oam_pointer = dragon_fireball_oam_2d5b58;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.samus_collision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
    gCurrentSprite.draw_order = 0x3;
    gCurrentSprite.bg_priority = gIORegistersBackup.bg2cnt & 0x3;
    gCurrentSprite.health = secondary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.oam_rotation = 0x40;
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    }
    else
        gCurrentSprite.oam_rotation = 0x0;

    gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
    gCurrentSprite.oam_scaling = 0x100;
    gCurrentSprite.array_offset = 0x0;
    SoundPlay(0x14C);
}

void dragon_fireball_move(void)
{
    /*u16 x_speed;
    u16 old_y;
    u8 offset;
    i16 movement;
    i16 rotation;

    x_speed = 0xC;
    old_y = gCurrentSprite.y_position;
    offset = gCurrentSprite.array_offset;
    movement = dragon_array_2d5134[offset];
    rotation = dragon_array_2d5184[offset];
    if (movement == 0x7FFF)
    {
        movement = dragon_array_2d5134[offset - 0x1];
        rotation = dragon_array_2d5184[offset - 0x1];
        gCurrentSprite.y_position += movement;
    }
    else
    {
        gCurrentSprite.array_offset = offset + 0x1;
        gCurrentSprite.y_position += movement;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        gCurrentSprite.x_position += x_speed;
        gCurrentSprite.oam_rotation = rotation + 0x40;
    }
    else
    {
        gCurrentSprite.x_position -= x_speed;
        gCurrentSprite.oam_rotation = -rotation;
    }

    if (SpriteUtilCheckInRoomEffect(old_y, gCurrentSprite.y_position, gCurrentSprite.x_position, SPLASH_NONE))
        gCurrentSprite.pose = 0x42;
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position, gCurrentSprite.x_position);
        if (gPreviousCollisionCheck & 0xF0)
            gCurrentSprite.pose = 0x42;
    }*/
}

void dragon_fireball_exploding_gfx_init(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    gCurrentSprite.oam_pointer = dragon_fireball_oam_2d5b78;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.pose = 0x43;
    gCurrentSprite.status = (gCurrentSprite.status & ~SPRITE_STATUS_YFLIP);
    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
}

void dragon_fireball_check_exploding_anim_ended(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    if (SpriteUtillCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}

void dragon(void)
{
    if (gCurrentSprite.properties & SP_UNKNOWN)
    {
        gCurrentSprite.properties &= ~SP_UNKNOWN;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x14D);
    }

    if (gCurrentSprite.freeze_timer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (!SpriteUtilIsSpriteStunned())
        {
            switch (gCurrentSprite.pose)
            {
                case 0x0:
                    dragon_init();
                    break;
                case 0x8:
                    ddragon_gfx_init();
                case 0x9:
                    dragon_go_up();
                    break;
                case 0xA:
                    dragon_turning_turning_around_gfx_init();
                case 0xB:
                    dragon_check_turning_around_first_half_anim_ended();
                    break;
                case 0xC:
                    dragon_check_turning_around_second_half_anim_ended();
                    break;
                case 0x34:
                    dragon_spitting_gfx_init();
                case 0x35:
                    dragon_spitting_anim();
                    break;
                case 0x37:
                    dragon_spawn_fireball();
                    break;
                default:
                    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.y_position, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_BIG);
            }
        }
    }
}

void dragon_fireball(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            dragon_fireball_init();
        case 0x9:
            dragon_fireball_move();
            break;
        case 0x42:
            dragon_fireball_exploding_gfx_init();
            break;
        case 0x43:
            dragon_fireball_check_exploding_anim_ended();
            break;
        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.y_position, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}