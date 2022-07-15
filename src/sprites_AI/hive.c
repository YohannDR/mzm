#include "hive.h"
#include "../particle.h"
#include "../event.h"
#include "../sprite_util.h"
#include "../../data/data.h"
#include "../globals.h"

void hive_spawn_particle(void)
{
    u16 x_pos;
    u16 y_pos;

    x_pos = gCurrentSprite.x_position;
    y_pos = gCurrentSprite.y_position;

    ParticleSet(gCurrentSprite.y_position - 0x20, gCurrentSprite.x_position, PE_MEDIUM_DUST);
    ParticleSet(y_pos + 0x60, x_pos, PE_TWO_MEDIUM_DUST);
}

void hive_init(void)
{
    u32 event_check;
    u8 room_slot;
    u8 gfx_slot;
    u16 y_position;
    u16 x_position;

    event_check = EventFunction(EVENT_ACTION_CHECKING, EVENT_THREE_HIVES_DESTROYED);
    if (event_check != 0x0)
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.draw_distance_top_offset = 0x28;
        gCurrentSprite.draw_distance_bottom_offset = 0x28;
        gCurrentSprite.draw_distance_horizontal_offset = 0x14;
        gCurrentSprite.hitbox_top_offset = -0x80;
        gCurrentSprite.hitbox_bottom_offset = 0x80;
        gCurrentSprite.hitbox_left_offset = -0x30;
        gCurrentSprite.hitbox_right_offset = 0x30;
        gCurrentSprite.samus_collision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;
        gCurrentSprite.frozen_palette_row_offset = 0x1;
        gCurrentSprite.oam_pointer = hive_oam_2da8ec;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = event_check;
        gCurrentSprite.draw_order = 0x5;
        gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.timer1 = 0x0;
        
        y_position = gCurrentSprite.y_position;
        x_position = gCurrentSprite.x_position;
        gfx_slot = gCurrentSprite.spriteset_gfx_slot;
        room_slot = gCurrentSprite.room_slot;
        
        SpriteSpawnSecondary(SSPRITE_HIVE_ROOTS, room_slot, gfx_slot, gCurrentSprite.primary_sprite_ram_slot, y_position, x_position, 0x0);
        SpriteSpawnPrimary(PSPRITE_MELLOW, room_slot, gfx_slot, y_position + 0x40, x_position - 0x1F, 0x0);
        SpriteSpawnPrimary(PSPRITE_MELLOW, room_slot, gfx_slot, y_position + 0x20, x_position + 0x10, 0x0);
        SpriteSpawnPrimary(PSPRITE_MELLOW, room_slot, gfx_slot, y_position - 0x48, x_position - 0x10, 0x0);
        SpriteSpawnPrimary(PSPRITE_MELLOW, room_slot, gfx_slot, y_position - 0x60, x_position + 0x1F, 0x0);
    }
}

u8 hive_count_mellows(void)
{
    u8 count;
    u8 room_slot;
    u8 collision;
    struct SpriteData* pSprite;

    count = 0x0;
    collision = SSC_MELLOW;
    room_slot = gCurrentSprite.room_slot;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && pSprite->samus_collision == collision && pSprite->room_slot == room_slot)
            count++;
        pSprite++;
    }

    return count;
}

void hive_phase1(void)
{
    if ((u8)hive_count_mellows() < 0x4)
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.room_slot, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
    
    if (gCurrentSprite.health < primary_sprite_stats[gCurrentSprite.sprite_id][0x0] >> 0x1)
    {
        gCurrentSprite.frozen_palette_row_offset = 0x2;
        gCurrentSprite.oam_pointer = hive_oam_2da9a4;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.pose = 0x23;
        unk_2b20(0x160);
        hive_spawn_particle();
    }
}

void hive_phase2(void)
{
    if ((u8)hive_count_mellows() < 0x4)
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.room_slot, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
    
    if (gCurrentSprite.health < primary_sprite_stats[gCurrentSprite.sprite_id][0x0] >> 0x2)
    {
        gCurrentSprite.frozen_palette_row_offset = 0x3;
        gCurrentSprite.oam_pointer = hive_oam_2daa04;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.pose = 0x25;
        unk_2b20(0x160);
        hive_spawn_particle();
    }
}

void hive_phase3(void)
{
    if ((u8)hive_count_mellows() < 0x4)
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.room_slot, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
}

void hive_dying(void)
{    
    u8 count;
    u8 room_slot;
    u8 pose;
    u8 collision;
    struct SpriteData* pSprite;
    u8 hive_id;

    count = 0x0;
    hive_id = PSPRITE_HIVE;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) == 0x0 && pSprite->sprite_id == hive_id && pSprite->health != 0x0)
            count++;
        pSprite++;
    }

    if (count == 0x0)
        EventFunction(EVENT_ACTION_SETTING, EVENT_THREE_HIVES_DESTROYED);

    pose = 0x9;
    room_slot = gCurrentSprite.room_slot;
    collision = SSC_MELLOW;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && pSprite->samus_collision == collision && pSprite->room_slot == room_slot && pSprite->pose == pose)
        {
            pSprite->pose = 0x25;
            pSprite->properties |= SP_PROJECTILE;
        }
        pSprite++;
    }

    if (gCurrentSprite.pose < 0x63 && gCurrentSprite.timer1 != 0x0)
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.y_position + 0x48, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    else
    {
        gCurrentSprite.pose = 0x67;
        gCurrentSprite.oam_pointer = hive_oam_2daa6c;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.samus_collision = SSC_NONE;
        unk_2b20(0x161);
        hive_spawn_particle();
    }
}

void hive_ignore_samus_collision(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
}

void hive_roots_init(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.draw_distance_top_offset = 0x0;
    gCurrentSprite.draw_distance_bottom_offset = 0x20;
    gCurrentSprite.draw_distance_horizontal_offset = 0x14;
    gCurrentSprite.hitbox_top_offset = -0x4;
    gCurrentSprite.hitbox_bottom_offset = 0x4;
    gCurrentSprite.hitbox_left_offset = -0x4;
    gCurrentSprite.hitbox_right_offset = 0x4;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.oam_pointer = hive_roots_oam;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.frozen_palette_row_offset = 0x1;
}

void hive_roots_move(void)
{
    u8 ram_slot;

    ram_slot = gCurrentSprite.primary_sprite_ram_slot;

    gCurrentSprite.y_position = gSpriteData[ram_slot].y_position;
    gCurrentSprite.x_position = gSpriteData[ram_slot].x_position;
}

void mellow_init(struct SpriteData* pSprite)
{
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_THREE_HIVES_DESTROYED))
        pSprite->status = 0x0;
    else
    {
        pSprite->status &= ~SPRITE_STATUS_NOT_DRAWN;
        pSprite->draw_distance_top_offset = 0x8;
        pSprite->draw_distance_bottom_offset = 0x8;
        pSprite->draw_distance_horizontal_offset = 0xC;
        pSprite->hitbox_top_offset = -0xC;
        pSprite->hitbox_bottom_offset = 0xC;
        pSprite->hitbox_left_offset = -0x20;
        pSprite->hitbox_right_offset = 0x20;
        pSprite->anim_duration_counter = 0x0;
        pSprite->curr_anim_frame = 0x0;
        pSprite->samus_collision = SSC_MELLOW;
        pSprite->health = primary_sprite_stats[pSprite->sprite_id][0x0];
        if (pSprite->room_slot != 0x88)
        {
            pSprite->oam_pointer = mellow_oam_2da88c;
            pSprite->pose = 0x9;
            pSprite->array_offset = gSpriteRNG << 0x2;
            if (gSpriteRNG & 0x1)
                pSprite->work_variable = 0x14;
            else
                pSprite->work_variable = 0x3C;
            
            if (pSprite->x_position & 0x1)
                pSprite->draw_order = 0x3;
            else
                pSprite->draw_order = 0x6;
        }
        else
        {
            pSprite->oam_pointer = mellow_oam_2da8bc;
            pSprite->bg_priority = gIORegistersBackup.bg2cnt & 0x3;
            pSprite->draw_order = 0x3;
            pSprite->timer2 = 0x0;
            pSprite->work_variable = 0x1;
            pSprite->timer1 = 0x0;
            pSprite->array_offset = 0x1;
            pSprite->x_position_spawn = gSpriteRNG & 0x3;
            pSprite->pose = 0x23;
            pSprite->oam_scaling = 0x20;
            SpriteUtilMakeSpriteFaceSamusDirection();
            if (pSprite->y_position > gSamusData.y_position + gSamusPhysics.draw_distance_top_offset)
                pSprite->status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
            else
                pSprite->status |= SPRITE_STATUS_ON_VERTICAL_WALL;
        }
    }
}

void mellow_idle_anim(struct SpriteData* pSprite)
{

}

void mellow_fleeing(struct SpriteData* pSprite)
{
    u8 rng;
    u16 movement;

    rng = gSpriteRNG >> 0x2;
    movement = rng + 0x8;
    if (pSprite->work_variable < 0x28)
        pSprite->x_position -= -movement;
    else
        pSprite->x_position -= movement;

    movement = rng + 0x4;
    if (pSprite->array_offset < 0x20)
        pSprite->y_position -= -movement;
    else
        pSprite->y_position -= movement;
}

void mellow_samus_detected(struct SpriteData* pSprite)
{
    pSprite->timer2 = 0x0;
    pSprite->work_variable = 0x1;
    pSprite->timer1 = 0x0;
    pSprite->array_offset = 0x1;
    pSprite->x_position_spawn = 0x0;
    pSprite->pose = 0x23;
    pSprite->oam_scaling = 0x20;
    SpriteUtilMakeSpriteFaceSamusDirection();
    if (pSprite->y_position > gSamusData.y_position + gSamusPhysics.draw_distance_top_offset)
        pSprite->status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
    else
        pSprite->status |= SPRITE_STATUS_ON_VERTICAL_WALL;
}

void mellow_move(struct SpriteData* pSprite)
{

}

void hive(void)
{
    if (gCurrentSprite.freeze_timer != 0x0)
    {
        SpriteUtilUpdateFreezeTimer();
        SpriteUtilUnfreezeSecondarySprites(SSPRITE_HIVE_ROOTS, gCurrentSprite.primary_sprite_ram_slot);
        gCurrentSprite.timer1 = gCurrentSprite.freeze_timer;
    }
    else
    {
        if (SpriteUtilIsSpriteStunned() == FALSE)
        {
            switch (gCurrentSprite.pose)
            {
                case 0x0:
                    hive_init();
                    break;
                case 0x9:
                    hive_phase1();
                    break;
                case 0x23:
                    hive_phase2();
                    break;
                case 0x25:
                    hive_phase3();
                    break;
                case 0x67:
                    hive_ignore_samus_collision();
                    break;
                default:
                    hive_dying();
            }
        }
    }
}

void hive_roots(void)
{
    u8 ram_slot;
    struct SpriteData* pSprite;

    ram_slot = gCurrentSprite.primary_sprite_ram_slot;
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    pSprite = gSpriteData + ram_slot;
    if (pSprite->sprite_id == PSPRITE_HIVE)
    {
        gCurrentSprite.palette_row = pSprite->palette_row;
        if (pSprite->health < primary_sprite_stats[pSprite->sprite_id][0x0] >> 0x1 && pSprite->freeze_timer == 0x0)
            gCurrentSprite.status = 0x0;
        else
        {
            if (pSprite->status == 0x0)
                gCurrentSprite.status = 0x0;
            else
            {
                if (gCurrentSprite.freeze_timer != 0x0)
                    SpriteUtilUpdateFreezeTimer();
                else
                {
                    if (gCurrentSprite.pose == 0x0)
                        hive_roots_init();
                    hive_roots_move();
                }
            }
        }
    }
    else
        gCurrentSprite.status = 0x0;
}

void mellow(void)
{
    struct SpriteData* pSprite;

    pSprite = &current_sprite;

    if ((pSprite->properties & SP_UNKNOWN) != 0x0)
    {
        pSprite->properties &= ~SP_UNKNOWN;
        if ((pSprite->status & SPRITE_STATUS_ONSCREEN) != 0x0)
            unk_2b20(0x15F);
    }
    
    if (pSprite->freeze_timer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (0x9 < (pSprite->invicibility_stun_flash_timer & 0x7F) && pSprite->pose < 0x62)
        {
            if (pSprite->anim_duration_counter == 0x0)
                return;
            pSprite->anim_duration_counter--;
        }
        else
        {
            switch (pSprite->pose)
            {
                case 0x0:
                    mellow_init(pSprite);
                    break;
                case 0x9:
                    mellow_idle_anim(pSprite);
                    break;
                case 0x22:
                    mellow_samus_detected(pSprite);
                case 0x23:
                    mellow_move(pSprite);
                    break;
                case 0x25:
                    mellow_fleeing(pSprite);
                    break;
                default:
                    SpriteUtilSpriteDeath(0x0, pSprite->y_position, pSprite->x_position, TRUE, PE_SPRITE_EXPLOSION_SMALL);
            }
        }
    }
}

void mellow_swarm(void)
{
    u8 count;
    struct SpriteData* pSprite;
    u8 collision;
    u16 x_pos;
    u16 y_pos;

    count = 0x0;
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_THREE_HIVES_DESTROYED))
            gCurrentSprite.status = 0x0;
        else
        {
            gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
            gCurrentSprite.hitbox_top_offset = -0x4;
            gCurrentSprite.hitbox_bottom_offset = 0x4;
            gCurrentSprite.hitbox_left_offset = -0x4;
            gCurrentSprite.hitbox_right_offset = 0x4;
            gCurrentSprite.draw_distance_top_offset = 0x1;
            gCurrentSprite.draw_distance_bottom_offset = 0x1;
            gCurrentSprite.draw_distance_horizontal_offset = 0x1;
            gCurrentSprite.samus_collision = SSC_NONE;
            gCurrentSprite.oam_pointer = mellow_oam_2da88c;
            gCurrentSprite.curr_anim_frame = 0x0;
            gCurrentSprite.anim_duration_counter = 0x0;
            gCurrentSprite.pose = 0x9;
            if (0x78 < (gSamusData.x_position >> 0x2) -( gBG1XPosition >> 0x2))
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.y_position_spawn = 0xF0;

            if (gCurrentSprite.sprite_id == PSPRITE_MELLOW_SWARM_HEALTH_BASED)
            {
                if (gEquipment.current_energy >= 0x190)
                    gCurrentSprite.work_variable = 0xF;
                else
                {
                    if (gEquipment.current_energy >= 0x12C)
                        gCurrentSprite.work_variable = 0xC;
                    else
                    {
                        if (gEquipment.current_energy >= 0xC8)
                            gCurrentSprite.work_variable = 0x9;
                        else
                        {
                            if (gEquipment.current_energy >= 0x64)
                                gCurrentSprite.work_variable = 0x6;
                            else
                                gCurrentSprite.work_variable = 0x3;
                        }
                    }
                }
            }
            else
                gCurrentSprite.work_variable = 0x5;
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_ON_VERTICAL_WALL && gCurrentSprite.y_position_spawn != 0x0)
            gCurrentSprite.y_position_spawn--;
        else
        {
            collision = SSC_MELLOW;
            pSprite = gSpriteData;
            while (pSprite < gSpriteData + 24)
            {
                if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samus_collision == collision)
                    count++;
                pSprite++;
            }

            if ((gCurrentSprite.status & SPRITE_STATUS_ON_VERTICAL_WALL) == 0x0)
            {
                if (count >= gCurrentSprite.work_variable)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
                    return;
                }
            }
            else
            {
                if (count <= 0x13)
                    gCurrentSprite.y_position_spawn = 0xF0;
                else
                    return;
            }

            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                x_pos = gSamusData.x_position + (gSpriteRNG * 0x20);
            else
                x_pos = gSamusData.x_position + (gSpriteRNG * -0x20);
            if (x_pos & 0x8000)
                x_pos = 0x0;
            y_pos = (u16)(gBG1YPosition - ((gSpriteRNG * 0x2) + 0x10));
            SpriteSpawnPrimary(PSPRITE_MELLOW, 0x88, gCurrentSprite.spriteset_gfx_slot, y_pos, x_pos, 0x0);
        }
    }
}