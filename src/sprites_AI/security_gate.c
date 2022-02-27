#include "security_gate.h"
#include "../sprite_util.h"
#include "../particle.h"
#include "../globals.h"

void security_gate_change_ccaa(enum current_clipdata_affecting_action caa)
{

}

/**
 * 2eb48 | 40 | Opens the gate
 * 
 */
void security_gate_open(void)
{
    current_sprite.status |= SPRITE_STATUS_UNKNOWN3;
    current_sprite.oam_pointer = security_gate_oam_2e6bb8;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.pose = 0x27;
    security_gate_change_ccaa(CCAA_REMOVE_SOLID); // Remove collision
    unk_2b20(0x225);
}

/**
 * 2eb88 | 38 | Starts the closing of the gate
 * 
 */
void security_gate_start_closing(void)
{
    current_sprite.status &= ~SPRITE_STATUS_UNKNOWN3;
    current_sprite.oam_pointer = security_gate_oam_2e6b08;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.pose = 0x23;
    unk_2b20(0x109);
}

/**
 * 2ebc0 | a8 | Initializes a security gate default open sprite
 * 
 */
void security_gate_default_open_init(void)
{
    if (alarm_timer != 0x0) // Check if should be closed or open
    {
        current_sprite.oam_pointer = security_gate_oam_2e6b98;
        current_sprite.pose = 0x25;
        current_sprite.timer1 = 0x1;
        security_gate_change_ccaa(CCAA_MAKE_SOLID); // Set collision
    }
    else
    {
        current_sprite.status |= SPRITE_STATUS_UNKNOWN3;
        current_sprite.oam_pointer = security_gate_oam_2e6af8;
        current_sprite.pose = 0x9;
    }

    current_sprite.hitbox_top_offset = -0x100;
    current_sprite.hitbox_bottom_offset = 0x0;
    current_sprite.hitbox_left_offset = -0x18;
    current_sprite.hitbox_right_offset = 0x18;
    current_sprite.draw_distance_top_offset = 0x40;
    current_sprite.draw_distance_bottom_offset = 0x8;
    current_sprite.draw_distance_horizontal_offset = 0x8;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.samus_collision = SSC_NONE;
    current_sprite.health = 0x1;
    current_sprite.draw_order = 0x3;
    current_sprite.properties |= SP_IMMUNE_TO_PROJECTILES;
}

/**
 * 2ec68 | 18 | Checks if the alarm timer is different than 0, if yes closes the gate
 * 
 */
void security_gate_default_open_check_alarm(void)
{
    if (alarm_timer != 0x0)
        security_gate_start_closing();
}

/**
 * 2ec80 | 38 | Checks if the closing animation has ended
 * 
 */
void security_gate_check_closing_anim_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        current_sprite.oam_pointer = security_gate_oam_2e6b98;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.pose = 0x25;
        current_sprite.timer1 = 0x0;
        current_sprite.array_offset = 0x0;
    }
}

/**
 * 2ecb8 | 60 | Called after the alarm is done, opens the gate if necessary
 * 
 */
void security_gate_default_open_open_after_alarm(void)
{
    if (current_sprite.timer1 == 0x0 && !sprite_check_colliding_with_samus_drawing()) // ?
    {
        security_gate_change_ccaa(CCAA_MAKE_SOLID);
        current_sprite.timer1++;
    }

    if (alarm_timer == 0x0)
    {
        current_sprite.array_offset++;
        if (current_sprite.array_offset > 0x28)
            security_gate_open();
    }
    else
        current_sprite.array_offset = 0x0;
}

/**
 * 2ed18 | 28 | Checks if the opening animation has ended
 * 
 */
void security_gate_check_opening_anim_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        current_sprite.oam_pointer = security_gate_oam_2e6af8;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.pose = 0x9;
    }
}

/**
 * 2ed40 | 40 | Handles the death of the security gate, unused
 * 
 */
void security_gate_death(void)
{
    u16 y_position;
    u16 x_position;

    security_gate_change_ccaa(CCAA_REMOVE_SOLID);
    y_position = current_sprite.y_position - 0x40;
    x_position = current_sprite.x_position;
    particle_set(y_position, x_position, PE_SPRITE_EXPLOSION_HUGE);
    sprite_util_sprite_death(DEATH_NORMAL, y_position - 0x60, x_position, TRUE, PE_SPRITE_EXPLOSION_BIG);
}

/**
 * 2ed80 | a4 | Initializes a security gate default closed sprite
 * 
 */
void security_gate_default_closed_init(void)
{
    if (alarm_timer != 0x0)
    {
        current_sprite.status |= SPRITE_STATUS_UNKNOWN3;
        current_sprite.oam_pointer = security_gate_oam_2e6af8;
        current_sprite.pose = 0x9;
    }
    else
    {
        current_sprite.oam_pointer = security_gate_oam_2e6b98;
        current_sprite.pose = 0x25;
        current_sprite.timer1 = 0x1;
        security_gate_change_ccaa(CCAA_MAKE_SOLID);
    }

    current_sprite.hitbox_top_offset = -0x100;
    current_sprite.hitbox_bottom_offset = 0x0;
    current_sprite.hitbox_left_offset = -0x18;
    current_sprite.hitbox_right_offset = 0x18;
    current_sprite.draw_distance_top_offset = 0x40;
    current_sprite.draw_distance_bottom_offset = 0x8;
    current_sprite.draw_distance_horizontal_offset = 0x8;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.samus_collision = SSC_NONE;
    current_sprite.health = 0x1;
    current_sprite.draw_order = 0x3;
    current_sprite.properties |= SP_IMMUNE_TO_PROJECTILES;
}

/**
 * 2ee24 | 18 | Checks if the alarm timer is 0, if yes closes the gate
 * 
 */
void security_gate_default_closed_check_alarm(void)
{
    if (alarm_timer == 0x0)
        security_gate_start_closing();
}

/**
 * 2ee3c | 3c | Checks if the alarm timer isn't 0, if yes calls security_gate_open
 * 
 */
void security_gate_default_closed_close_after_alarm(void)
{
    if (current_sprite.timer1 == 0x0 && !sprite_check_colliding_with_samus_drawing())
    {
        security_gate_change_ccaa(CCAA_MAKE_SOLID);
        current_sprite.timer1++;
    }

    if (alarm_timer != 0x0)
        security_gate_open();
}

/**
 * 2ee78 | f0 | Security Gate Default Open AI
 * 
 */
void security_gate_default_open(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    switch (current_sprite.pose)
    {
        case 0x0:
            security_gate_default_open_init();
            break;
        case 0x9:
            security_gate_default_open_check_alarm();
            break;
        case 0x23:
            security_gate_check_closing_anim_ended();
            break;
        case 0x25:
            security_gate_default_open_open_after_alarm();
            break;
        case 0x27:
            security_gate_check_opening_anim_ended();
            break;
        default:
            security_gate_death();
    }
}

/**
 * 2ef68 | f0 | Security Gate Default Closed AI
 * 
 */
void security_gate_default_closed(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    switch (current_sprite.pose)
    {
        case 0x0:
            security_gate_default_closed_init();
            break;
        case 0x9:
            security_gate_default_closed_check_alarm();
            break;
        case 0x23:
            security_gate_check_closing_anim_ended();
            break;
        case 0x25:
            security_gate_default_closed_close_after_alarm();
            break;
        case 0x27:
            security_gate_check_opening_anim_ended();
            break;
        default:
            security_gate_death();
    }
}