#include "rising_chozo_pillar.h"
#include "../particle.h"
#include "../sprite_debris.h"
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

}

void rising_chozo_pillar_spawn_two_platforms(u16 y_position, u16 x_position, u8 caa)
{

}

void rising_chozo_pillar_spawn_one_platform(u16 y_position, u16 x_position, u8 caa)
{

}

void rising_chozo_pillar(void)
{

}

void chozo_pillar_platform(void)
{

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
        current_sprite.oam_pointer = chozo_platform_pillar_shadow_oam;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.draw_order = 0xC;
    }
}