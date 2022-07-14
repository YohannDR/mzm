#include "glass_tube.h"
#include "../sprite_util.h"
#include "../clipdata.h"
#include "../particle.h"
#include "../screen_shake.h"
#include "../music.h"
#include "../event.h"
#include "../../data/data.h"
#include "../globals.h"

void glass_tube_change_ccaa(void)
{
    /*u16 y_position;
    u16 x_position;
    u8 caa;

    y_position = gCurrentSprite.y_position - 0x20;
    x_position = gCurrentSprite.x_position;

    caa = CCAA_REMOVE_SOLID;
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position - 0x40, x_position);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position - 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position - 0x80);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position - 0xC0);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position - 0x100);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position - 0x140);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position + 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position + 0x80);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position + 0xC0);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position + 0x100);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position + 0x140);
    y_position += 0x140;
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position - 0x40, x_position);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position - 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position - 0x80);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position - 0xC0);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position - 0x100);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position - 0x140);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position + 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position + 0x80);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position + 0xC0);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position + 0x100);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position, x_position + 0x140);*/
}

/**
 * 463dc | 90 | Initialize a glass tube sprite
 * 
 */
void glass_tube_init(void)
{
    gCurrentSprite.draw_distance_top_offset = 0x30;
    gCurrentSprite.draw_distance_bottom_offset = 0x30;
    gCurrentSprite.draw_distance_horizontal_offset = 0x70;
    gCurrentSprite.hitbox_top_offset = -0x80;
    gCurrentSprite.hitbox_bottom_offset = 0x80;
    gCurrentSprite.hitbox_left_offset = -0x100;
    gCurrentSprite.hitbox_right_offset = 0x100;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.samus_collision = SSC_NONE;
    
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_GLASS_TUBE_BROKEN))
    {
        gCurrentSprite.oam_pointer = glass_tube_oam_broken;
        gCurrentSprite.pose = 0xF;
        glass_tube_change_ccaa();
    }
    else
    {
        gCurrentSprite.oam_pointer = glass_tube_oam;
        gCurrentSprite.pose = 0x9;
    }

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_FULLY_POWERED_SUIT_OBTAINED))
        SoundPlay(0x122);
}

/**
 * 4646c | c0 | Checks for collision between a power bomb and the glass tube
 * 
 */
void glass_tube_check_power_bomb_collision(void)
{
    u16 bomb_y;
    u16 bomb_x;
    u16 bomb_top;
    u16 bomb_bottom;
    u16 bomb_left;
    u16 bomb_right;   
    u16 sprite_y;
    u16 sprite_x;
    u16 sprite_top;
    u16 sprite_bottom;
    u16 sprite_left;
    u16 sprite_right;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_FULLY_POWERED_SUIT_OBTAINED) && gCurrentPowerBomb.animation_state != 0x0 && gEquipment.max_power_bombs != 0x0)
    {
        bomb_y = gCurrentPowerBomb.y_position;
        bomb_x = gCurrentPowerBomb.x_position;
        bomb_top = gCurrentPowerBomb.hitbox_top_offset + bomb_y;
        bomb_bottom = gCurrentPowerBomb.hitbox_bottom_offset + bomb_y;
        bomb_left = gCurrentPowerBomb.hitbox_left_offset + bomb_x;
        bomb_right = gCurrentPowerBomb.hitbox_right_offset + bomb_x;
        
        sprite_y = gCurrentSprite.y_position;
        sprite_x = gCurrentSprite.x_position;
        sprite_top = gCurrentSprite.hitbox_top_offset + sprite_y;
        sprite_bottom = gCurrentSprite.hitbox_bottom_offset + sprite_y;
        sprite_left = gCurrentSprite.hitbox_left_offset + sprite_x;
        sprite_right = gCurrentSprite.hitbox_right_offset + sprite_x;

        if (sprite_util_check_objects_touching(sprite_top, sprite_bottom, sprite_left, sprite_right, bomb_top, bomb_bottom, bomb_left, bomb_right))
        {
            gCurrentSprite.pose = 0x23;
            gCurrentSprite.timer1 = 0x78;
            EventFunction(EVENT_ACTION_SETTING, EVENT_GLASS_TUBE_BROKEN);
        }
    }
}

/**
 * 4652c | 3c | Delay before the glass tube starts cracking
*/
void glass_tube_delay_before_breaking(void)
{
    gCurrentSprite.timer1--;
    if (gCurrentSprite.timer1 == 0x0)
    {
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.oam_pointer = glass_tube_oam_cracking;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        SoundPlay(0x27A);
    }
}

/**
 * 46568 | 8c | Checks if the cracking animation ended, spawn dust particles and starts a global screen shake
 * 
 */
void glass_tube_check_cracking_anim_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        gCurrentSprite.pose = 0x27;
        gCurrentSprite.oam_pointer = glass_tube_oam_breaking;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        glass_tube_change_ccaa();
        ParticleSet(gCurrentSprite.y_position - 0x1E, gCurrentSprite.x_position - 0x12C, PE_MEDIUM_DUST);
        ParticleSet(gCurrentSprite.y_position + 0xA0, gCurrentSprite.x_position - 0x140, PE_TWO_MEDIUM_DUST);
        ParticleSet(gCurrentSprite.y_position - 0x1E, gCurrentSprite.x_position + 0x12C, PE_MEDIUM_DUST);
        ParticleSet(gCurrentSprite.y_position + 0xA0, gCurrentSprite.x_position + 0x140, PE_TWO_MEDIUM_DUST);
        screen_shake_start_vertical(0x1E, 0x81);
        screen_shake_start_horizontal(0x1E, 0x81);
    }
}

/**
 * 46568 | 8c | Checks if the breaking animation ended
 * 
 */
void glass_tube_check_breaking_anim_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        gCurrentSprite.pose = 0xF;
        gCurrentSprite.oam_pointer = glass_tube_oam_broken;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
    }
}

/**
 * 46620 | e8 | Glass Tube AI
 * 
 */
void glass_tube(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            glass_tube_init();
            break;
        case 0x9:
            glass_tube_check_power_bomb_collision();
            break;
        case 0x23:
            glass_tube_delay_before_breaking();
            break;
        case 0x25:
            glass_tube_check_cracking_anim_ended();
            break;
        case 0x27:
            glass_tube_check_breaking_anim_ended();
    }
}