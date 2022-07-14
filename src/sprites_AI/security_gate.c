#include "security_gate.h"
#include "../sprite_util.h"
#include "../particle.h"
#include "../globals.h"

void security_gate_change_ccaa(u8 caa)
{

}

/**
 * 2eb48 | 40 | Opens the gate
 * 
 */
void security_gate_open(void)
{
    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
    gCurrentSprite.oam_pointer = security_gate_oam_2e6bb8;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.pose = 0x27;
    security_gate_change_ccaa(CCAA_REMOVE_SOLID); // Remove collision
    unk_2b20(0x225);
}

/**
 * 2eb88 | 38 | Starts the closing of the gate
 * 
 */
void security_gate_start_closing(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN3;
    gCurrentSprite.oam_pointer = security_gate_oam_2e6b08;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.pose = 0x23;
    unk_2b20(0x109);
}

/**
 * 2ebc0 | a8 | Initializes a security gate default open sprite
 * 
 */
void security_gate_default_open_init(void)
{
    if (gAlarmTimer != 0x0) // Check if should be closed or open
    {
        gCurrentSprite.oam_pointer = security_gate_oam_2e6b98;
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.timer1 = 0x1;
        security_gate_change_ccaa(CCAA_MAKE_SOLID3); // Set collision
    }
    else
    {
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
        gCurrentSprite.oam_pointer = security_gate_oam_2e6af8;
        gCurrentSprite.pose = 0x9;
    }

    gCurrentSprite.hitbox_top_offset = -0x100;
    gCurrentSprite.hitbox_bottom_offset = 0x0;
    gCurrentSprite.hitbox_left_offset = -0x18;
    gCurrentSprite.hitbox_right_offset = 0x18;
    gCurrentSprite.draw_distance_top_offset = 0x40;
    gCurrentSprite.draw_distance_bottom_offset = 0x8;
    gCurrentSprite.draw_distance_horizontal_offset = 0x8;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.draw_order = 0x3;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
}

/**
 * 2ec68 | 18 | Checks if the alarm timer is different than 0, if yes closes the gate
 * 
 */
void security_gate_default_open_check_alarm(void)
{
    if (gAlarmTimer != 0x0)
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
        gCurrentSprite.oam_pointer = security_gate_oam_2e6b98;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.timer1 = 0x0;
        gCurrentSprite.array_offset = 0x0;
    }
}

/**
 * 2ecb8 | 60 | Called after the alarm is done, opens the gate if necessary
 * 
 */
void security_gate_default_open_open_after_alarm(void)
{
    if (gCurrentSprite.timer1 == 0x0 && !sprite_check_colliding_with_samus_drawing()) // ?
    {
        security_gate_change_ccaa(CCAA_MAKE_SOLID3);
        gCurrentSprite.timer1++;
    }

    if (gAlarmTimer == 0x0)
    {
        gCurrentSprite.array_offset++;
        if (gCurrentSprite.array_offset > 0x28)
            security_gate_open();
    }
    else
        gCurrentSprite.array_offset = 0x0;
}

/**
 * 2ed18 | 28 | Checks if the opening animation has ended
 * 
 */
void security_gate_check_opening_anim_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        gCurrentSprite.oam_pointer = security_gate_oam_2e6af8;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.pose = 0x9;
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
    y_position = gCurrentSprite.y_position - 0x40;
    x_position = gCurrentSprite.x_position;
    ParticleSet(y_position, x_position, PE_SPRITE_EXPLOSION_HUGE);
    sprite_util_sprite_death(DEATH_NORMAL, y_position - 0x60, x_position, TRUE, PE_SPRITE_EXPLOSION_BIG);
}

/**
 * 2ed80 | a4 | Initializes a security gate default closed sprite
 * 
 */
void security_gate_default_closed_init(void)
{
    if (gAlarmTimer != 0x0)
    {
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
        gCurrentSprite.oam_pointer = security_gate_oam_2e6af8;
        gCurrentSprite.pose = 0x9;
    }
    else
    {
        gCurrentSprite.oam_pointer = security_gate_oam_2e6b98;
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.timer1 = 0x1;
        security_gate_change_ccaa(CCAA_MAKE_SOLID3);
    }

    gCurrentSprite.hitbox_top_offset = -0x100;
    gCurrentSprite.hitbox_bottom_offset = 0x0;
    gCurrentSprite.hitbox_left_offset = -0x18;
    gCurrentSprite.hitbox_right_offset = 0x18;
    gCurrentSprite.draw_distance_top_offset = 0x40;
    gCurrentSprite.draw_distance_bottom_offset = 0x8;
    gCurrentSprite.draw_distance_horizontal_offset = 0x8;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.draw_order = 0x3;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
}

/**
 * 2ee24 | 18 | Checks if the alarm timer is 0, if yes closes the gate
 * 
 */
void security_gate_default_closed_check_alarm(void)
{
    if (gAlarmTimer == 0x0)
        security_gate_start_closing();
}

/**
 * 2ee3c | 3c | Checks if the alarm timer isn't 0, if yes calls security_gate_open
 * 
 */
void security_gate_default_closed_close_after_alarm(void)
{
    if (gCurrentSprite.timer1 == 0x0 && !sprite_check_colliding_with_samus_drawing())
    {
        security_gate_change_ccaa(CCAA_MAKE_SOLID3);
        gCurrentSprite.timer1++;
    }

    if (gAlarmTimer != 0x0)
        security_gate_open();
}

/**
 * 2ee78 | f0 | Security Gate Default Open AI
 * 
 */
void security_gate_default_open(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    switch (gCurrentSprite.pose)
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
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    switch (gCurrentSprite.pose)
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