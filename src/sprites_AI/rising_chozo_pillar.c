#include "rising_chozo_pillar.h"
#include "../particle.h"
#include "../music.h"
#include "../sprite_debris.h"
#include "../sprite_util.h"
#include "../screen_shake.h"
#include "../sprite.h"
#include "../particle.h"
#include "../../data/data.h"
#include "../globals.h"

/**
 * 4854c | a8 | 
 * Spawns random sprite debris depending on the parameters
 * 
 * @param y_position Y Position
 * @param x_position X Position 
 * @param rng Set of debris to use
 */
void rising_chozo_pillar_random_sprite_debris(u16 y_position, u16 x_position, u8 rng)
{
    switch (rng)
    {
        case 0x1:
            sprite_debris_init(0x0, 0x11, y_position - 0x28, x_position);
            sprite_debris_init(0x0, 0x12, y_position - 0x10, x_position + 0x46);
            break;
        case 0x3:
            sprite_debris_init(0x0, 0x13, y_position - 0x14, x_position - 0x5C);
            sprite_debris_init(0x0, 0x4, y_position - 0xA, x_position + 0x1E);
            break;
        case 0x7:
            sprite_debris_init(0x0, 0x11, y_position - 0x8, x_position - 0x32);
            sprite_debris_init(0x0, 0x12, y_position - 0x34, x_position + 0x78);
            break;
        case 0xC:
            sprite_debris_init(0x0, 0x13, y_position - 0x20, x_position + 0x1E);
            sprite_debris_init(0x0, 0x4, y_position - 0x4, x_position - 0x6E);
    }
}

/**
 * 485f4 | ac | 
 * Spawns random particles depending on the parameters
 * 
 * @param y_position Y Position
 * @param x_position X Position 
 * @param rng Set of particles to use
 */
void rising_chozo_pillar_random_particles(u16 y_position, u16 x_position, u8 rng)
{
    switch (rng)
    {
        case 0x1:
            particle_set(y_position, x_position - 0x28, PE_TWO_MEDIUM_DUST);
            break;
        case 0x10:
            particle_set(y_position, x_position + 0x3C, PE_SECOND_MEDIUM_DUST);
            break;
        case 0x21:
            particle_set(y_position, x_position - 0x3C, PE_SECOND_MEDIUM_DUST);
            break;
        case 0x32:
            particle_set(y_position, x_position + 0x14, PE_MEDIUM_DUST);
            break;
        case 0x42:
            particle_set(y_position, x_position - 0x50, PE_TWO_MEDIUM_DUST);
            break;
        case 0x54:
            particle_set(y_position, x_position + 0x50, PE_SECOND_MEDIUM_DUST);
            particle_set(y_position, x_position, PE_SECOND_TWO_MEDIUM_DUST);
            break;
        case 0x64:
            particle_set(y_position, x_position - 0x14, PE_SECOND_TWO_MEDIUM_DUST);
            break;
        case 0x6E:
            particle_set(y_position, x_position + 0x28, PE_MEDIUM_DUST);
    }
}

void rising_chozo_pillar_spawn_three_platforms(u16 y_position, u16 x_position, u8 caa)
{
    current_clipdata_affecting_action = caa;
    clipdata_related(y_position - 0xC0, x_position + 0xC0);
    current_clipdata_affecting_action = caa;
    clipdata_related(y_position - 0xC0, x_position + 0x100);
    current_clipdata_affecting_action = caa;
    clipdata_related(y_position - 0x2C0, x_position + 0xC0);
    current_clipdata_affecting_action = caa;
    clipdata_related(y_position - 0x2C0, x_position + 0x100);
    current_clipdata_affecting_action = caa;
    clipdata_related(y_position - 0x4C0, x_position + 0xC0);
    current_clipdata_affecting_action = caa;
    clipdata_related(y_position - 0x4C0, x_position - 0x100);
    sprite_spawn_secondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x1, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, y_position - 0xC0, x_position + 0xE0, 0x0);
    sprite_spawn_secondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x1, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, y_position - 0x2C0, x_position + 0xE0, 0x0);
    sprite_spawn_secondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x1, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, y_position - 0x4C0, x_position + 0xE0, 0x0);
}

/**
 * 48784 | b8 | 
 * Spawns two platforms and sets the collision for them
 * 
 * @param y_position Y Position
 * @param x_position X Position
 * @param caa Clipdata Affecting Action
 */
void rising_chozo_pillar_spawn_two_platforms(u16 y_position, u16 x_position, u8 caa)
{
    current_clipdata_affecting_action = caa;
    clipdata_related(y_position - 0x1C0, x_position);
    current_clipdata_affecting_action = caa;
    clipdata_related(y_position - 0x1C0, x_position + 0x40);
    current_clipdata_affecting_action = caa;
    clipdata_related(y_position - 0x7c0, x_position);
    current_clipdata_affecting_action = caa;
    clipdata_related(y_position - 0x7c0, x_position + 0x40);
    sprite_spawn_secondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x0, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, y_position - 0x1C0, x_position + 0x20, 0x0);
    sprite_spawn_secondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x0, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, y_position - 0x7c0, x_position + 0x20, 0x0);
}

/**
 * 4883c | 68 | 
 * Spawns one platform and sets the collision for it
 * 
 * @param y_position Y Position
 * @param x_position X Position
 * @param caa Clipdata Affecting Action
 */
void rising_chozo_pillar_spawn_one_platform(u16 y_position, u16 x_position, u8 caa)
{
    current_clipdata_affecting_action = caa;
    clipdata_related(y_position - 0x3C0, x_position + 0x180);
    current_clipdata_affecting_action = caa;
    clipdata_related(y_position - 0x3C0, x_position + 0x1C0);
    sprite_spawn_secondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x0, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, y_position - 0x3C0, x_position + 0x1A0, 0x0);
}

/**
 * 488a4 | 248 | Rising Chozo Pillar AI
 * 
 */
void rising_chozo_pillar(void)
{
    u8 caa;
    u16 y_position;
    u16 y_pos;
    u16 x_position;
    u16 x_pos;

    caa = CCAA_MAYBE_MAKE_SOLID;
    y_position = current_sprite.y_position - 0x20;
    x_position = current_sprite.x_position;

    switch (current_sprite.pose)
    {
        case 0x0:
            if (event_function(EVENT_ACTION_CHECKING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED))
            {
                rising_chozo_pillar_spawn_three_platforms(y_position, x_position, caa);
                rising_chozo_pillar_spawn_two_platforms(y_position, x_position, caa);
                rising_chozo_pillar_spawn_one_platforms(y_position, x_position, caa);
                current_sprite.status = 0x0;
            }
            else
            {
                current_sprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
                current_sprite.samus_collision = SSC_NONE;
                current_sprite.draw_distance_top_offset = 0x1;
                current_sprite.draw_distance_bottom_offset = 0x1;
                current_sprite.draw_distance_horizontal_offset = 0x1;
                current_sprite.hitbox_top_offset = 0x0;
                current_sprite.hitbox_bottom_offset = 0x0;
                current_sprite.hitbox_left_offset = 0x0;
                current_sprite.hitbox_right_offset = 0x0;
                current_sprite.oam_pointer = large_energy_drop_oam;
                current_sprite.anim_duration_counter = 0x0;
                current_sprite.curr_anim_frame = 0x0;
                current_sprite.pose = 0x8;
            }
            break;
        case 0x8:
            if (event_function(EVENT_ACTION_CHECKING, EVENT_POWER_GRIP_OBTAINED))
            {
                current_sprite.pose = 0x9;
                current_sprite.oam_scaling = 0x2C0;
                sound_play1(0x125);
            }
            break;
        case 0x9:
            if ((current_sprite.oam_scaling & 0x1F) == 0x0)
                screen_shake_start_vertical(0x1E, 0x81);
            current_sprite.oam_scaling--;
            if (current_sprite.oam_scaling != 0x0)
                bg2_movement.y_offset += 0x2;
            else
            {
                current_sprite.pose = 0x22;
                sound_call_func(0x125, 0xA);
            }
            y_pos = y_position + 0x20;
            x_pos = x_position + 0xE0;
            rising_chozo_pillar_random_sprite_debris(y_pos, x_pos, current_sprite.oam_scaling & 0xF);
            rising_chozo_pillar_random_particles(y_pos, x_pos, current_sprite.oam_scaling & 0x7F);
            break;
        case 0x22:
            current_sprite.pose = 0x23;
            rising_chozo_pillar_spawn_three_platforms(y_position, x_position, caa);
            break;
        case 0x23:
            current_sprite.pose = 0x24;
            rising_chozo_pillar_spawn_two_platforms(y_position, x_position, caa);
            break;
        case 0x24:
            current_sprite.pose = 0x25;
            rising_chozo_pillar_spawn_one_platform(y_position, x_position, caa);
            break;
        case 0x25:
            current_sprite.pose = 0x26;
            break;
        case 0x26:
            event_function(EVENT_ACTION_SETTING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED);
            current_sprite.status = 0x0;
    }
}

/**
 * 48aec | 124 | Chozo Pillar Platform AI 
 * 
 */
void chozo_pillar_platform(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;

    switch (current_sprite.pose)
    {
        case 0x0:
            current_sprite.y_position += 0x4;
            current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            current_sprite.status |= SPRITE_STATUS_UNKNOWN3;
            current_sprite.samus_collision = SSC_NONE;
            current_sprite.draw_distance_top_offset = 0x8;
            current_sprite.draw_distance_bottom_offset = 0x10;
            current_sprite.draw_distance_horizontal_offset = 0x10;
            current_sprite.hitbox_top_offset = 0x0;
            current_sprite.hitbox_bottom_offset = 0x0;
            current_sprite.hitbox_left_offset = 0x0;
            current_sprite.hitbox_right_offset = 0x0;
            current_sprite.anim_duration_counter = 0x0;
            current_sprite.curr_anim_frame = 0x0;
            if (event_function(EVENT_ACTION_CHECKING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED))
            {
                current_sprite.pose = 0x9;
                if (current_sprite.room_slot != 0x0)
                {
                    current_sprite.oam_pointer = chozo_pillar_platform_oam_spawned;
                    sprite_spawn_secondary(SSPRITE_CHOZO_PILLAR_PLATFORM_SHADOW, 0x0, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, current_sprite.y_position, current_sprite.x_position, 0x0);
                }
                else
                    current_sprite.oam_pointer = chozo_pillar_platform_slot1_oam_spawned;
            }
            else
            {
                current_sprite.pose = 0x8;
                if (current_sprite.room_slot != 0x0)
                    current_sprite.oam_pointer = chozo_pillar_platform_slot1_oam_spawning;
                else
                    current_sprite.oam_pointer = chozo_pillar_platform_oam_spawning;
                sound_play1(0x126);
            }
            break;

        case 0x8:
            if (sprite_util_check_end_current_sprite_anim())
            {
                current_sprite.pose = 0x9;
                current_sprite.anim_duration_counter = 0x0;
                current_sprite.curr_anim_frame = 0x0;
                if (current_sprite.room_slot != 0x0)
                    current_sprite.oam_pointer = chozo_pillar_platform_slot1_oam_spawned;
                else
                    current_sprite.oam_pointer = chozo_pillar_platform_oam_spawned;
            }
            else
            {
                if (current_sprite.room_slot != 0x0 && current_sprite.curr_anim_frame == 0x15 && current_sprite.anim_duration_counter == 0x1)
                    sprite_spawn_secondary(SSPRITE_CHOZO_PILLAR_PLATFORM_SHADOW, 0x0, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, current_sprite.y_position, current_sprite.x_position, 0x0);
            }
    }
}

/**
 * 48c10 | 6c | Chozo Pillar Platform Shadow AI
 * 
 */
void chozo_pillar_platform_shadow(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;

    if (current_sprite.pose == 0x0)
    {
        current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        current_sprite.status |= SPRITE_STATUS_UNKNOWN3;
        current_sprite.samus_collision = SSC_NONE;
        current_sprite.draw_distance_top_offset = 0x0;
        current_sprite.draw_distance_bottom_offset = 0x10;
        current_sprite.draw_distance_horizontal_offset = 0x10;
        current_sprite.hitbox_top_offset = 0x0;
        current_sprite.hitbox_bottom_offset = 0x0;
        current_sprite.hitbox_left_offset = 0x0;
        current_sprite.hitbox_right_offset = 0x0;
        current_sprite.pose = 0x8;
        current_sprite.oam_pointer = chozo_pillar_platform_shadow_oam;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.draw_order = 0xC;
    }
}