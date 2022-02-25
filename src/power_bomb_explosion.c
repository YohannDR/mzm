#include "power_bomb_explosion.h"
#include "clipdata.h"
#include "screen_shake.h"
#include "globals.h"

/**
 * 5745c | 48 | Subroutine for the power bomb explosion
 */
void power_bomb_explosion_process(void)
{
    if (current_power_bomb.animation_state > 0x1)
    {
        power_bomb_explosion_set_0x12_to_0();
        if (current_power_bomb.also_always_zero == 0x0) // Most likely a cancelled feature
        {
            if (current_power_bomb.animation_state == 0x2)
                power_bomb_explosion_begin();
            else if (current_power_bomb.animation_state == 0x5)
                power_bomb_explosion_end();
            else if (game_mode_sub1 == 0x2)
                power_bomb_explosion();
        }
    }
}

void power_bomb_explosion(void)
{

}

/**
 * 576ec | 48 | Starts a power bomb explosion at the given parameters
 * 
 * @param x_position The X Position of the epicenter
 * @param y_position The Y Position of the epicenter
 * @param zero Written to the field at offset 0x11, is always zero, most likely a cancelled feature
 */
void power_bomb_explosion_start(u16 x_position, u16 y_position, u8 zero)
{
    if (game_mode_sub2 == 0x2) // /!\ Wrong register for ldrsh
    {
        power_bomb_explosion_set_0x12_to_0();
        if (current_power_bomb.animation_state == 0x0) // Check if there isn't already an explosion
        {
            current_power_bomb.x_position = x_position;
            current_power_bomb.y_position = y_position;
            current_power_bomb.always_zero = zero;
            if (current_power_bomb.also_always_zero != 0x0)
                current_power_bomb.animation_state = 0x2;
            else
                power_bomb_explosion_begin();
        }
    }
}

/**
 * 57734 | c | Sets the field at offset 0x12 of the current power bomb to 0x0, purpose is unknown 
 * 
 */
void power_bomb_explosion_set_0x12_to_0(void)
{
    current_power_bomb.also_always_zero = 0x0;
}

void power_bomb_explosion_begin(void)
{

}

void power_bomb_explosion_end(void)
{

}