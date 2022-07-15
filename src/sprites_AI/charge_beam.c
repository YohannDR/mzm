#include "PowerGrip.h"
#include "../sprite_util.h"
#include "../sprite.h"
#include "../globals.h"
#include "../event.h"

void ChargeBeamInit(void)
{
    u8 check;
    u16 status;

    if (gEquipment.beam_bombs & BBF_CHARGE_BEAM)
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
        status = gCurrentSprite.status & ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.hitbox_top_offset = -0x1C;
        gCurrentSprite.hitbox_bottom_offset = 0x1C;
        gCurrentSprite.hitbox_left_offset = -0x1C;
        gCurrentSprite.hitbox_right_offset = 0x1C;
        gCurrentSprite.draw_distance_top_offset = 0x20;
        gCurrentSprite.draw_distance_bottom_offset = 0x20;
        gCurrentSprite.draw_distance_horizontal_offset = 0x20;
        gCurrentSprite.oam_pointer = charge_beam_oam_2b3920;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.samus_collision = SSC_NONE;
        gCurrentSprite.health = 0x1;
        gCurrentSprite.array_offset = 0x0;
        gCurrentSprite.pose = 0xA;
        gCurrentSprite.status = status | SPRITE_STATUS_ON_VERTICAL_WALL;
        gCurrentSprite.draw_order = 0x2;
    }
}

void ChargeBeamSpawnGlow(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    if (SpriteUtilCheckNearEndCurrentSpriteAnim() != 0x0)
    {
        gCurrentSprite.pose = 0xB;
        gCurrentSprite.workVariable = SpriteSpawnSecondary(SSPRITE_CHARGE_BEAM_GLOW, 0x0, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
    }
}

void ChargeBeamGFXInit(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.oam_pointer = charge_beam_oam_2b38f8;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
    gCurrentSprite.samus_collision = SSC_ABILITY_LASER_SEARCHLIGHT;
    gCurrentSprite.array_offset = 0x0;
}

void ChargeBeamGet(void)
{
    i16 y_offset;
    u8 array_offset;

    array_offset = gCurrentSprite.array_offset;
    y_offset = i16_array_2b31ac[array_offset];
    if (y_offset == 0x7FFF)
    {
        y_offset = i16_array_2b31ac[0x0];
        array_offset = 0x0;
    }
    gCurrentSprite.array_offset = array_offset + 0x1;
    gCurrentSprite.y_position += y_offset;
    if ((gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING) != 0x0)
    {
        if (gCurrentSprite.workVariable < 0x18)
            gSpriteData[gCurrentSprite.workVariable].status = 0x0;
        gPreventMovementTimer = 0x3E8;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
        gCurrentSprite.ignore_samus_collision_timer = 0x2;
        gCurrentSprite.pose = 0x23;
        gCurrentSprite.timer1 = 0x0;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gEquipment.beam_bombs |= BBF_CHARGE_BEAM;
        EventFunction(EVENT_ACTION_SETTING, EVENT_CHARGE_BEAM_OBTAINED);
        SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, 0x9, 0x6, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
    }
}

void ChargeBeamFlashingAnim(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    gCurrentSprite.anim_duration_counter;
    if ((gCurrentSprite.timer1 & 0x1) == 0x0)
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    if (gPreventMovementTimer < 0x3E7)
        gCurrentSprite.status = 0x0;
}

void ChargeBeamGlowInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.draw_order = 0x3;
    gCurrentSprite.draw_distance_top_offset = 0x10;
    gCurrentSprite.draw_distance_bottom_offset = 0x10;
    gCurrentSprite.draw_distance_horizontal_offset = 0x10;
    gCurrentSprite.hitbox_top_offset = -0x20;
    gCurrentSprite.hitbox_bottom_offset = 0x20;
    gCurrentSprite.hitbox_left_offset = -0x20;
    gCurrentSprite.hitbox_right_offset = 0x20;
    gCurrentSprite.oam_pointer = charge_beam_glow_oam;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.pose = 0x9;
}

void ChargeBeamGlowMovement(void)
{
    u8 ram_slot;

    ram_slot = gCurrentSprite.primary_sprite_ram_slot;

    gCurrentSprite.y_position = gSpriteData[ram_slot].y_position;
}

void ChargeBeam(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ChargeBeamInit();
            break;
        case 0xA:
            ChargeBeamSpawnGlow();
            break;
        case 0xB:
            ChargeBeamGFXInit();
            break;
        case 0x9:
            ChargeBeamGet();
            break;
        case 0x23:
            ChargeBeamFlashingAnim();
    }
}

void ChargeBeamGlow(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ChargeBeamGlowInit();
        case 0x9:
            ChargeBeamGlowMovement();
    }
}