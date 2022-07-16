#include "hive.h"
#include "../particle.h"
#include "../event.h"
#include "../sprite_util.h"
#include "../../data/data.h"
#include "../globals.h"

void HiveSpawnParticle(void)
{
    u16 x_pos;
    u16 y_pos;

    x_pos = gCurrentSprite.xPosition;
    y_pos = gCurrentSprite.yPosition;

    ParticleSet(gCurrentSprite.yPosition - 0x20, gCurrentSprite.xPosition, PE_MEDIUM_DUST);
    ParticleSet(y_pos + 0x60, x_pos, PE_TWO_MEDIUM_DUST);
}

void HiveInit(void)
{
    u32 event_check;
    u8 room_slot;
    u8 gfx_slot;
    u16 yPosition;
    u16 xPosition;

    event_check = EventFunction(EVENT_ACTION_CHECKING, EVENT_THREE_HIVES_DESTROYED);
    if (event_check != 0x0)
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.drawDistanceTopOffset = 0x28;
        gCurrentSprite.drawDistanceBottomOffset = 0x28;
        gCurrentSprite.draw_distance_horizontal_offset = 0x14;
        gCurrentSprite.hitboxTopOffset = -0x80;
        gCurrentSprite.hitboxBottomOffset = 0x80;
        gCurrentSprite.hitboxLeftOffset = -0x30;
        gCurrentSprite.hitboxRightOffset = 0x30;
        gCurrentSprite.samus_collision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;
        gCurrentSprite.frozen_palette_row_offset = 0x1;
        gCurrentSprite.oam_pointer = hive_oam_2da8ec;
        gCurrentSprite.animationDuratoinCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = event_check;
        gCurrentSprite.draw_order = 0x5;
        gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.timer1 = 0x0;
        
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;
        gfx_slot = gCurrentSprite.spriteset_gfx_slot;
        room_slot = gCurrentSprite.room_slot;
        
        SpriteSpawnSecondary(SSPRITE_HIVE_ROOTS, room_slot, gfx_slot, gCurrentSprite.primary_sprite_ram_slot, yPosition, xPosition, 0x0);
        SpriteSpawnPrimary(PSPRITE_MELLOW, room_slot, gfx_slot, yPosition + 0x40, xPosition - 0x1F, 0x0);
        SpriteSpawnPrimary(PSPRITE_MELLOW, room_slot, gfx_slot, yPosition + 0x20, xPosition + 0x10, 0x0);
        SpriteSpawnPrimary(PSPRITE_MELLOW, room_slot, gfx_slot, yPosition - 0x48, xPosition - 0x10, 0x0);
        SpriteSpawnPrimary(PSPRITE_MELLOW, room_slot, gfx_slot, yPosition - 0x60, xPosition + 0x1F, 0x0);
    }
}

u8 HiveCountMellows(void)
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

void HivePhase1(void)
{
    if ((u8)HiveCountMellows() < 0x4)
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.room_slot, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    
    if (gCurrentSprite.health < primary_sprite_stats[gCurrentSprite.sprite_id][0x0] >> 0x1)
    {
        gCurrentSprite.frozen_palette_row_offset = 0x2;
        gCurrentSprite.oam_pointer = hive_oam_2da9a4;
        gCurrentSprite.animationDuratoinCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = 0x23;
        unk_2b20(0x160);
        HiveSpawnParticle();
    }
}

void HivePhase2(void)
{
    if ((u8)HiveCountMellows() < 0x4)
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.room_slot, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    
    if (gCurrentSprite.health < primary_sprite_stats[gCurrentSprite.sprite_id][0x0] >> 0x2)
    {
        gCurrentSprite.frozen_palette_row_offset = 0x3;
        gCurrentSprite.oam_pointer = hive_oam_2daa04;
        gCurrentSprite.animationDuratoinCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = 0x25;
        unk_2b20(0x160);
        HiveSpawnParticle();
    }
}

void HivePhase3(void)
{
    if ((u8)HiveCountMellows() < 0x4)
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.room_slot, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
}

void HiveDying(void)
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
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition + 0x48, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    else
    {
        gCurrentSprite.pose = 0x67;
        gCurrentSprite.oam_pointer = hive_oam_2daa6c;
        gCurrentSprite.animationDuratoinCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.samus_collision = SSC_NONE;
        unk_2b20(0x161);
        HiveSpawnParticle();
    }
}

void HiveIgnoreSamusCollision(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
}

void HiveRootsInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.drawDistanceTopOffset = 0x0;
    gCurrentSprite.drawDistanceBottomOffset = 0x20;
    gCurrentSprite.draw_distance_horizontal_offset = 0x14;
    gCurrentSprite.hitboxTopOffset = -0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.oam_pointer = HiveRoots_oam;
    gCurrentSprite.animationDuratoinCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.frozen_palette_row_offset = 0x1;
}

void HiveRootsMove(void)
{
    u8 ram_slot;

    ram_slot = gCurrentSprite.primary_sprite_ram_slot;

    gCurrentSprite.yPosition = gSpriteData[ram_slot].yPosition;
    gCurrentSprite.xPosition = gSpriteData[ram_slot].xPosition;
}

void MellowInit(struct SpriteData* pSprite)
{
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_THREE_HIVES_DESTROYED))
        pSprite->status = 0x0;
    else
    {
        pSprite->status &= ~SPRITE_STATUS_NOT_DRAWN;
        pSprite->drawDistanceTopOffset = 0x8;
        pSprite->drawDistanceBottomOffset = 0x8;
        pSprite->draw_distance_horizontal_offset = 0xC;
        pSprite->hitboxTopOffset = -0xC;
        pSprite->hitboxBottomOffset = 0xC;
        pSprite->hitboxLeftOffset = -0x20;
        pSprite->hitboxRightOffset = 0x20;
        pSprite->animationDuratoinCounter = 0x0;
        pSprite->currentAnimationFrame = 0x0;
        pSprite->samus_collision = SSC_MELLOW;
        pSprite->health = primary_sprite_stats[pSprite->sprite_id][0x0];
        if (pSprite->room_slot != 0x88)
        {
            pSprite->oam_pointer = mellow_oam_2da88c;
            pSprite->pose = 0x9;
            pSprite->array_offset = gSpriteRNG << 0x2;
            if (gSpriteRNG & 0x1)
                pSprite->workVariable2 = 0x14;
            else
                pSprite->workVariable2 = 0x3C;
            
            if (pSprite->xPosition & 0x1)
                pSprite->draw_order = 0x3;
            else
                pSprite->draw_order = 0x6;
        }
        else
        {
            pSprite->oam_pointer = mellow_oam_2da8bc;
            pSprite->bg_priority = gIORegistersBackup.BG1CNT & 0x3;
            pSprite->draw_order = 0x3;
            pSprite->workVariable = 0x0;
            pSprite->workVariable2 = 0x1;
            pSprite->timer1 = 0x0;
            pSprite->array_offset = 0x1;
            pSprite->xPosition_spawn = gSpriteRNG & 0x3;
            pSprite->pose = 0x23;
            pSprite->oam_scaling = 0x20;
            SpriteUtilMakeSpriteFaceSamusDirection();
            if (pSprite->yPosition > gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset)
                pSprite->status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
            else
                pSprite->status |= SPRITE_STATUS_ON_VERTICAL_WALL;
        }
    }
}

void MellowIdleAnim(struct SpriteData* pSprite)
{

}

void MellowFleeing(struct SpriteData* pSprite)
{
    u8 rng;
    u16 movement;

    rng = gSpriteRNG >> 0x2;
    movement = rng + 0x8;
    if (pSprite->workVariable2 < 0x28)
        pSprite->xPosition -= -movement;
    else
        pSprite->xPosition -= movement;

    movement = rng + 0x4;
    if (pSprite->array_offset < 0x20)
        pSprite->yPosition -= -movement;
    else
        pSprite->yPosition -= movement;
}

void MellowSamusDetected(struct SpriteData* pSprite)
{
    pSprite->workVariable = 0x0;
    pSprite->workVariable2 = 0x1;
    pSprite->timer1 = 0x0;
    pSprite->array_offset = 0x1;
    pSprite->xPosition_spawn = 0x0;
    pSprite->pose = 0x23;
    pSprite->oam_scaling = 0x20;
    SpriteUtilMakeSpriteFaceSamusDirection();
    if (pSprite->yPosition > gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset)
        pSprite->status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
    else
        pSprite->status |= SPRITE_STATUS_ON_VERTICAL_WALL;
}

void MellowMove(struct SpriteData* pSprite)
{

}

void Hive(void)
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
                    HiveInit();
                    break;
                case 0x9:
                    HivePhase1();
                    break;
                case 0x23:
                    HivePhase2();
                    break;
                case 0x25:
                    HivePhase3();
                    break;
                case 0x67:
                    HiveIgnoreSamusCollision();
                    break;
                default:
                    HiveDying();
            }
        }
    }
}

void HiveRoots(void)
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
                        HiveRootsInit();
                    HiveRootsMove();
                }
            }
        }
    }
    else
        gCurrentSprite.status = 0x0;
}

void Mellow(void)
{
    struct SpriteData* pSprite;

    pSprite = &current_sprite;

    if ((pSprite->properties & SP_DAMAGED) != 0x0)
    {
        pSprite->properties &= ~SP_DAMAGED;
        if ((pSprite->status & SPRITE_STATUS_ONSCREEN) != 0x0)
            unk_2b20(0x15F);
    }
    
    if (pSprite->freeze_timer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (0x9 < (pSprite->invicibility_stun_flash_timer & 0x7F) && pSprite->pose < 0x62)
        {
            if (pSprite->animationDuratoinCounter == 0x0)
                return;
            pSprite->animationDuratoinCounter--;
        }
        else
        {
            switch (pSprite->pose)
            {
                case 0x0:
                    MellowInit(pSprite);
                    break;
                case 0x9:
                    MellowIdleAnim(pSprite);
                    break;
                case 0x22:
                    MellowSamusDetected(pSprite);
                case 0x23:
                    MellowMove(pSprite);
                    break;
                case 0x25:
                    MellowFleeing(pSprite);
                    break;
                default:
                    SpriteUtilSpriteDeath(0x0, pSprite->yPosition, pSprite->xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
            }
        }
    }
}

void MellowSwarm(void)
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
            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;
            gCurrentSprite.drawDistanceTopOffset = 0x1;
            gCurrentSprite.drawDistanceBottomOffset = 0x1;
            gCurrentSprite.draw_distance_horizontal_offset = 0x1;
            gCurrentSprite.samus_collision = SSC_NONE;
            gCurrentSprite.oam_pointer = mellow_oam_2da88c;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDuratoinCounter = 0x0;
            gCurrentSprite.pose = 0x9;
            if (0x78 < (gSamusData.xPosition >> 0x2) -( gBG1XPosition >> 0x2))
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.yPosition_spawn = 0xF0;

            if (gCurrentSprite.sprite_id == PSPRITE_MELLOW_SWARM_HEALTH_BASED)
            {
                if (gEquipment.currentEnergy >= 0x190)
                    gCurrentSprite.workVariable2 = 0xF;
                else
                {
                    if (gEquipment.currentEnergy >= 0x12C)
                        gCurrentSprite.workVariable2 = 0xC;
                    else
                    {
                        if (gEquipment.currentEnergy >= 0xC8)
                            gCurrentSprite.workVariable2 = 0x9;
                        else
                        {
                            if (gEquipment.currentEnergy >= 0x64)
                                gCurrentSprite.workVariable2 = 0x6;
                            else
                                gCurrentSprite.workVariable2 = 0x3;
                        }
                    }
                }
            }
            else
                gCurrentSprite.workVariable2 = 0x5;
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_ON_VERTICAL_WALL && gCurrentSprite.yPosition_spawn != 0x0)
            gCurrentSprite.yPosition_spawn--;
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
                if (count >= gCurrentSprite.workVariable2)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
                    return;
                }
            }
            else
            {
                if (count <= 0x13)
                    gCurrentSprite.yPosition_spawn = 0xF0;
                else
                    return;
            }

            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                x_pos = gSamusData.xPosition + (gSpriteRNG * 0x20);
            else
                x_pos = gSamusData.xPosition + (gSpriteRNG * -0x20);
            if (x_pos & 0x8000)
                x_pos = 0x0;
            y_pos = (u16)(gBG1YPosition - ((gSpriteRNG * 0x2) + 0x10));
            SpriteSpawnPrimary(PSPRITE_MELLOW, 0x88, gCurrentSprite.spriteset_gfx_slot, y_pos, x_pos, 0x0);
        }
    }
}