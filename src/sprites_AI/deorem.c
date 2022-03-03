#include "deorem.h"
#include "../sprite_debris.h"
#include "../screen_shake.h"
#include "../particle.h"
#include "../sprite_util.h"
#include "../sprite.h"
#include "../globals.h"

void deorem_change_left_ccaa(enum current_clipdata_affecting_action caa)
{

}

void deorem_change_right_ccaa(enum current_clipdata_affecting_action caa)
{

}

void deorem_20d90(u8 unk, u16 unk2)
{

}

void deorem_random_sprite_debris(u8 rng)
{

}

/**
 * 20f80 | a8 | 
 * Handles the spawning of sprite debris when Deorem appears
 * 
 * @param y_position Y Position
 * @param x_position X Position
 * @param timer Timer (determines which set to spawn)
 */
void deorem_sprite_debris_spawn(u16 y_position, u16 x_position, u8 timer)
{
    switch (timer)
    {
        case 0x1:
            sprite_debris_init(0x0, 0x11, y_position - 0x40, x_position);
            sprite_debris_init(0x0, 0x12, y_position - 0x10, x_position + 0x3E);
            break;
        case 0x3:
            sprite_debris_init(0x0, 0x13, y_position + 0x28, x_position - 0x5C);
            sprite_debris_init(0x0, 0x4, y_position, x_position + 0x1E);
            break;
        case 0x7:
            sprite_debris_init(0x0, 0x11, y_position + 0x14, x_position - 0x14);
            sprite_debris_init(0x0, 0x12, y_position - 0x14, x_position + 0x6E);
            break;
        case 0xC:
            sprite_debris_init(0x0, 0x13, y_position + 0x28, x_position + 0x1E);
            sprite_debris_init(0x0, 0x4, y_position - 0x10, x_position - 0x64);
    }
}

u8 deorem_check_leaving(u8 ram_slot)
{

}

/**
 * 21094 | 40 |
 * Spawns and loads a charge beam sprite at the given position
 * 
 * @param y_position Y Position
 * @param x_position X Position
 */
void deorem_spawn_charge_beam(u16 y_position, u16 x_position)
{
    u8 gfx_slot;

    gfx_slot = current_sprite.spriteset_gfx_slot;
    sprite_spawn_primary(PSPRITE_CHARGE_BEAM, 0x0, gfx_slot, y_position, x_position, 0x0);
    sprite_load_gfx(PSPRITE_CHARGE_BEAM, gfx_slot);
    sprite_load_pal(PSPRITE_CHARGE_BEAM, gfx_slot, 0x1);
}

/**
 * 210d4 | 3c | Sets the timer for how long the eye stays open depending on the difficulty
 * 
 */
void deorem_set_eye_opening_timer(void)
{
    if (difficulty == 0x0)
        current_sprite.timer1 = 0x78; // Easy
    else if (difficulty == 0x2)
        current_sprite.timer1 = 0x28; // Hard
    else
        current_sprite.timer1 = 0x50; // Normal
}

/**
 * 21110 | 2c | Calls the charge beam spawn handler, used when deorem is already dead but the charge beam hasn't been picked up
 * 
 */
void deorem_call_spawn_charge_beam(void)
{
    deorem_spawn_charge_beam(current_sprite.y_position + 0xB0, current_sprite.x_position + 0x1A0);
    current_sprite.status = 0x0;
}

void deorem_init(void)
{

}

void deorem_spawn_going_down(void)
{

}

void deorem_spawn_going_down_anim(void)
{

}

void deorem_spawn_going_up(void)
{
    /*u16 y_position;
    u8 gfx_slot;
    u8 ram_slot;
    u16 x_position;

    current_sprite.timer1--;
    if (current_sprite.timer1 == 0x0)
    {
        current_sprite.pose = 0x23;
        current_sprite.timer1 = 0x32;
        y_position = current_sprite.y_position = current_sprite.y_position_spawn + 0x31C;
        gfx_slot = current_sprite.spriteset_gfx_slot;
        ram_slot = current_sprite.primary_sprite_ram_slot;
        x_position = current_sprite.x_position;
        sprite_spawn_secondary(SSPRITE_DEOREM_SEGMENT, 0xB, gfx_slot, ram_slot, y_position, x_position, 0x0);
        sprite_spawn_secondary(SSPRITE_DEOREM_SEGMENT, 0xA, gfx_slot, ram_slot, y_position, x_position, 0x0);
        sprite_spawn_secondary(SSPRITE_DEOREM_SEGMENT, 0x9, gfx_slot, ram_slot, y_position, x_position, 0x0);
        sprite_spawn_secondary(SSPRITE_DEOREM_SEGMENT, 0x8, gfx_slot, ram_slot, y_position, x_position, 0x0);
        sprite_spawn_secondary(SSPRITE_DEOREM_SEGMENT, 0x7, gfx_slot, ram_slot, y_position, x_position, 0x0);
        sprite_spawn_secondary(SSPRITE_DEOREM_SEGMENT, 0x6, gfx_slot, ram_slot, y_position, x_position, 0x0);
        screen_shake_start_vertical(0x28, 0x81);
        play_sound1(0x193);
    }*/
}

void deorem_spawn_going_up_anim(void)
{

}

void deorem_spawn_head_body(void)
{

}

void deorem_after_spawn(void)
{

}

void deorem_main_loop(void)
{

}

void deorem_retracting(void)
{

}

void deorem_throwing_thorns(void)
{

}

void deorem_after_thorns(void)
{

}

void deorem_dying(void)
{

}

void deorem_dying_going_down(void)
{

}

void deorem_death(void)
{

}

void deorem_check_leaving_ceiling_anim_ended(void)
{

}

void deorem_leaving(void)
{

}

void deorem_leaving_anim(void)
{

}

void deorem_leaving_in_ground_debris(void)
{

}

void deorem_segment_init(void)
{

}

void deorem_segment_spawn_going_down(void)
{

}

void deorem_segment_spawn_going_down_after(void)
{

}

void deorem_segment_spawn_going_up(void)
{

}

void deorem_segment_spawn_going_up_after(void)
{

}

void deorem_segment_right_idle_anim(void)
{

}

void deorem_segment_left_idle_anim(void)
{

}

void deorem_segment_going_down(void)
{

}

void deorem_segment_going_up(void)
{

}

void deorem_segment_above_head_movement(void)
{

}

void deorem_segment_left_leaving(void)
{

}

void deorem_segment_left_leaving_end(void)
{

}

void deorem_segment_middle_leaving_end(void)
{

}

void deorem_segment_middle_leaving(void)
{

}

void deorem_segment_right_leaving(void)
{

}

void deorem_segment_right_leaving_end(void)
{

}

void deorem_segment_set_timer_dying(void)
{

}

void deorem_segment_dying(void)
{

}

void deorem_eye_init(void)
{

}

void deorem_eye_set_pose9(void)
{

}

void deorem_eye_move(void)
{

}

void deorem_eye_230d4(void)
{

}

void deorem_eye_dying_gfx_init(void)
{

}

void deorem_eye_dying_spinning_anim(void)
{

}

void deorem_eye_dying_moving_anim(void)
{

}

void deorem_thorn_init(void)
{

}

void deorem_thorn_spawning(void)
{

}

void deorem_thorn_movement(void)
{

}

void deorem(void)
{

}

void deorem_segment(void)
{

}

void deorem_eye(void)
{

}

/**
 * 23b00 | 4c | Deorem Thorn AI
 * 
 */
void deorem_thorn(void)
{
    switch (current_sprite.pose)
    {
        case 0x0:
            deorem_init();
        case 0x9:
            deorem_thorn_spawning();
            break;
        case 0x23:
            deorem_thorn_movement();
            break;
        default:
            sprite_util_sprite_death(DEATH_NORMAL, current_sprite.y_position, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
    }
}