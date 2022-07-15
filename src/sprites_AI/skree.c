#include "skree.h"
#include "../sprite_debris.h"
#include "../sprite_util.h"
#include "../globals.h"

void SkreeInit(void)
{
    gCurrentSprite.samus_collision = SSC_HURTS_SAMUS;
    gCurrentSprite.draw_distance_top_offset = 0x0;
    gCurrentSprite.draw_distance_bottom_offset = 0x20;
    gCurrentSprite.draw_distance_horizontal_offset = 0x10;
    gCurrentSprite.hitbox_top_offset = 0x0;
    gCurrentSprite.hitbox_bottom_offset = 0x60;
    gCurrentSprite.hitbox_left_offset = -0x18;
    gCurrentSprite.hitbox_right_offset = 0x18;
    gCurrentSprite.health = primary_sprites_stats[gCurrentSprite.sprite_id].spawn_health;
    gCurrentSprite.y_position -= 0x40;
}

void SkreeGFXInit(void)
{
    gCurrentSprite.oam_pointer = skree_oam_2cd474;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.pose = 0x9;
}

void SkreeDetectSamus(void)
{
    if (gSamusData.y_position > gCurrentSprite.y_position && gSamusData.y_position - gCurrentSprite.y_position < 0x284 && (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) != 0x0 && gSamusData.x_position > gCurrentSprite.x_position - 0x96 && gSamusData.x_position < gCurrentSprite.x_position + 0x96)
        gCurrentSprite.pose = 0x22;
}

void SkreeSpinGFXInit(void)
{
    gCurrentSprite.oam_pointer = skree_oam_spinning_2cd49c;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.pose = 0x23;
}

void SkreeCheckSpinAnimEnded(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = 0x34;
}

void SkreeStartGoingDown(void)
{
    gCurrentSprite.oam_pointer = skree_going_down_2cd4cc;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.array_offset = 0x0;
    gCurrentSprite.workVariable2 = 0x0;
    gCurrentSprite.pose = 0x35;

    if (gCurrentSprite.x_position > gSamusData.x_position)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;

    if ((gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
        SoundPlay(0x141);
}

void SkreeGoDown(void)
{
    u32 block;
    u32 x_movement;
    u32 y_movement;
    u32 array_offset;

    block = SpriteUtilCheckVerticalCollisionAtPosition_slopes(gCurrentSprite.hitbox_bottom_offset + gCurrentSprite.y_position, gCurrentSprite.x_position);
    if (gPreviousVerticalCollisionCheck != 0x0)
    {
        gCurrentSprite.y_position = block - gCurrentSprite.hitbox_bottom_offset;
        gCurrentSprite.pose = 0x37;
        gCurrentSprite.timer1 = 0x0;
        if ((gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
            SoundPlay(0x142);
    }
    else
    {
        x_movement = gCurrentSprite.workVariable2 >> 0x2;
        array_offset = gCurrentSprite.array_offset;
        y_movement = skree_falling_speed_2cca7c[array_offset];
        if (y_movement == 0x7FFF)
        {
            y_movement = skree_falling_speed_2cca7c[array_offset - 0x1];
            gCurrentSprite.y_position += y_movement;
        }
        else
        {
            gCurrentSprite.array_offset++;
            gCurrentSprite.y_position += y_movement;
        }

        if ((gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT) != 0x0)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position + 0x40, gCurrentSprite.x_position + 0x20);
            if (gPreviousCollisionCheck == 0x11)
                return;
            gCurrentSprite.x_position += x_movement;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.y_position + 0x40, gCurrentSprite.x_position - 0x20);
            if (gPreviousCollisionCheck == 0x11)
                return;
            gCurrentSprite.x_position -= x_movement;
        }

        if (x_movement < 0x10)
            gCurrentSprite.workVariable2++;
    }
}

void SkreeCrashGround(void)
{
    u16 y_position;
    u16 x_position;
    u8 gfx_slot;
    u8 ram_slot;
    u8 sprite_id;

    y_position = gCurrentSprite.y_position;
    x_position = gCurrentSprite.x_position;

    gCurrentSprite.timer1++;

    switch (gCurrentSprite.timer1)
    {
        case 0x1:
            y_position += 0x48;
            SpriteDebrisInit(0x0, 0x11, y_position - 0x10, x_position);
            SpriteDebrisInit(0x0, 0x12, y_position, x_position + 0xC);
            SpriteDebrisInit(0x0, 0x13, y_position - 0x2A, x_position + 0x14);
            SpriteDebrisInit(0x0, 0x4, y_position - 0x18, x_position - 0x1E);
            break;

        case 0x28:
            gCurrentSprite.oam_pointer = skree_oam_crashing_2cd4f4;
            break;

        case 0x3C:
            gfx_slot = gCurrentSprite.spriteset_gfx_slot;
            ram_slot = gCurrentSprite.primary_sprite_ram_slot;

            if (gCurrentSprite.sprite_id == PSPRITE_SKREE_BLUE)
                sprite_id = SSPRITE_BLUE_SKREE_EXPLOSION;
            else
                sprite_id = SSPRITE_SKREE_EXPLOSION;
            
            SpriteSpawnSecondary(sprite_id, 0x0, gfx_slot, ram_slot, y_position - 0x8, x_position, 0x0);
            SpriteSpawnSecondary(sprite_id, 0x0, gfx_slot, ram_slot, y_position - 0x8, x_position, SPRITE_STATUS_XFLIP);
            SpriteSpawnSecondary(sprite_id, 0x1, gfx_slot, ram_slot, y_position + 0x8, x_position - 0xC, 0x0);
            SpriteSpawnSecondary(sprite_id, 0x1, gfx_slot, ram_slot, y_position + 0x8, x_position + 0xC, SPRITE_STATUS_XFLIP);
            gCurrentSprite.status = 0x0;
            ParticleSet(y_position + 0x24, x_position, PE_SPRITE_EXPLOSION_HUGE);
            SoundPlay(0x134);
    }
}

void SkreeExplosionInit(void)
{
    u16 status;

    status = gCurrentSprite.status & ~SPRITE_STATUS_NOT_DRAWN | (SPRITE_STATUS_UNKNOWN3 | SPRITE_STATUS_NONE);
    gCurrentSprite.properties |= SP_PROJECTILE;
    gCurrentSprite.draw_distance_top_offset = 0x10;
    gCurrentSprite.draw_distance_bottom_offset = 0x10;
    gCurrentSprite.draw_distance_horizontal_offset = 0x10;
    gCurrentSprite.hitbox_top_offset = -0xC;
    gCurrentSprite.hitbox_bottom_offset = 0xC;
    gCurrentSprite.hitbox_left_offset = -0xC;
    gCurrentSprite.hitbox_right_offset = 0xC;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.samus_collision = SSC_HURTS_SAMUS;
    gCurrentSprite.draw_order = 0x3;
    gCurrentSprite.bg_priority = gIORegistersBackup.bg2cnt & 0x3;
    gCurrentSprite.y_position += 0x28;
    gCurrentSprite.status = (status | SPRITE_STATUS_DOUBLE_SIZE | SPRITE_STATUS_ROTATION_SCALING);
    gCurrentSprite.oam_scaling = 0x100;
    gCurrentSprite.oam_rotation = 0x0;

    if (gCurrentSprite.room_slot != 0x0)
        gCurrentSprite.oam_pointer = skree_explosion_oam_going_down_2cd5c4;
    else
        gCurrentSprite.oam_pointer = skree_explosion_oam_going_up_2cd5e4;
}

void SkreeExplosionMove(void)
{
    if (gCurrentSprite.curr_anim_frame > 0x1)
        gCurrentSprite.ignore_samus_collision_timer = 0x1;

    if ((gCurrentSprite.status & SPRITE_STATUS_XFLIP) != 0x0)
    {
        gCurrentSprite.x_position += 0x8;
        gCurrentSprite.oam_rotation += 0x20;
    }
    else
    {
        gCurrentSprite.x_position -= 0x8;
        gCurrentSprite.oam_rotation -= 0x20;
    }

    if (gCurrentSprite.room_slot != 0x0)
        gCurrentSprite.y_position += 0x4;
    else
        gCurrentSprite.y_position -= 0x4;

    if (SpriteUtillCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}

void Skree(void)
{
    if ((gCurrentSprite.properties & SP_DAMAGED) != 0x0)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if ((gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) != 0x0)
            unk_2b20(0x143);
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
                    SkreeInit();
                case 0x8:
                    SkreeGFXInit();
                case 0x9:
                    SkreeDetectSamus();
                    break;
                case 0x22:
                    SkreeSpinGFXInit();
                case 0x23:
                    SkreeCheckSpinAnimEnded();
                    break;
                case 0x34:
                    SkreeStartGoingDown();
                case 0x35:
                    SkreeGoDown();
                    break;
                case 0x37:
                    SkreeCrashGround();
                    break;
                default:
                    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.y_position + 0x34, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
        }
    }
}

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