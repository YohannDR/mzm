#include "power_grip.h"
#include "../sprite_util.h"
#include "../sprite.h"
#include "../globals.h"
#include "../event.h"

void charge_beam_init(void)
{
    u8 check;
    enum sprite_status status;

    if (equipment.beam_bombs & BBF_CHARGE_BEAM)
        current_sprite.status = 0x0;
    else
    {
        current_sprite.properties |= SP_IMMUNE_TO_PROJECTILES;
        status = current_sprite.status & ~SPRITE_STATUS_NOT_DRAWN;
        current_sprite.hitbox_top_offset = -0x1C;
        current_sprite.hitbox_bottom_offset = 0x1C;
        current_sprite.hitbox_left_offset = -0x1C;
        current_sprite.hitbox_right_offset = 0x1C;
        current_sprite.draw_distance_top_offset = 0x20;
        current_sprite.draw_distance_bottom_offset = 0x20;
        current_sprite.draw_distance_horizontal_offset = 0x20;
        current_sprite.oam_pointer = charge_beam_oam_2b3920;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.samus_collision = SSC_NONE;
        current_sprite.health = 0x1;
        current_sprite.array_offset = 0x0;
        current_sprite.pose = 0xA;
        current_sprite.status = status | SPRITE_STATUS_ON_VERTICAL_WALL;
        current_sprite.draw_order = 0x2;
    }
}

void charge_beam_spawn_glow(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    if (sprite_util_check_near_end_current_sprite_anim() != 0x0)
    {
        current_sprite.pose = 0xB;
        current_sprite.timer2 = sprite_spawn_secondary(SSPRITE_CHARGE_BEAM_GLOW, 0x0, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, current_sprite.y_position, current_sprite.x_position, 0x0);
    }
}

void charge_beam_gfx_init(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    current_sprite.pose = 0x9;
    current_sprite.oam_pointer = charge_beam_oam_2b38f8;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
    current_sprite.samus_collision = SSC_ABILITY_LASER_SEARCHLIGHT;
    current_sprite.array_offset = 0x0;
}

void charge_beam_get(void)
{
    i16 y_offset;
    u8 array_offset;

    array_offset = current_sprite.array_offset;
    y_offset = i16_array_2b31ac[array_offset];
    if (y_offset == 0x7FFF)
    {
        y_offset = i16_array_2b31ac[0x0];
        array_offset = 0x0;
    }
    current_sprite.array_offset = array_offset + 0x1;
    current_sprite.y_position += y_offset;
    if ((current_sprite.status & SPRITE_STATUS_SAMUS_COLLIDING) != 0x0)
    {
        if (current_sprite.timer2 < 0x18)
            sprite_data[current_sprite.timer2].status = 0x0;
        prevent_movement_timer = 0x3E8;
        current_sprite.properties |= SP_ALWAYS_ACTIVE;
        current_sprite.ignore_samus_collision_timer = 0x2;
        current_sprite.pose = 0x23;
        current_sprite.timer1 = 0x0;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        equipment.beam_bombs |= BBF_CHARGE_BEAM;
        event_function(EVENT_ACTION_SETTING, EVENT_CHARGE_BEAM_OBTAINED);
        sprite_spawn_primary(PSPRITE_ITEM_BANNER, 0x9, 0x6, current_sprite.y_position, current_sprite.x_position, 0x0);
    }
}

void charge_beam_flashing_anim(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    current_sprite.animation_duration_counter--;
    if ((current_sprite.timer1 & 0x1) == 0x0)
        current_sprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    if (prevent_movement_timer < 0x3E7)
        current_sprite.status = 0x0;
}

void charge_beam_glow_init(void)
{
    current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    current_sprite.draw_order = 0x3;
    current_sprite.draw_distance_top_offset = 0x10;
    current_sprite.draw_distance_bottom_offset = 0x10;
    current_sprite.draw_distance_horizontal_offset = 0x10;
    current_sprite.hitbox_top_offset = -0x20;
    current_sprite.hitbox_bottom_offset = 0x20;
    current_sprite.hitbox_left_offset = -0x20;
    current_sprite.hitbox_right_offset = 0x20;
    current_sprite.oam_pointer = charge_beam_glow_oam;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.samus_collision = SSC_NONE;
    current_sprite.pose = 0x9;
}

void charge_beam_glow_movement(void)
{
    u8 ram_slot;

    ram_slot = current_sprite.primary_sprite_ram_slot;

    current_sprite.y_position = sprite_data[ram_slot].y_position;
}

void charge_beam(void)
{
    switch (current_sprite.pose)
    {
        case 0x0:
            charge_beam_init();
            break;
        case 0xA:
            charge_beam_spawn_glow();
            break;
        case 0xB:
            charge_beam_gfx_init();
            break;
        case 0x9:
            charge_beam_get();
            break;
        case 0x23:
            charge_beam_flashing_anim();
    }
}

void charge_beam_glow(void)
{
    switch (current_sprite.pose)
    {
        case 0x0:
            charge_beam_glow_init();
        case 0x9:
            charge_beam_glow_movement();
    }
}