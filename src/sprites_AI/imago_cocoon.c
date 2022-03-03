#include "imago_cocoon.h"
#include "../event.h"
#include "../sprite.h"
#include "../sprite_util.h"
#include "../sprite_debris.h"
#include "../screen_shake.h"
#include "../particle.h"
#include "../globals.h"

void imago_cocoon_update_position_and_anim(void)
{
    
}

/**
 * 26ca0 | 40 | Updates the current clipdata affecting action and applies it, removes the middle block of the ground when falling
 * 
 * @param caa Clipdata Affecting Action to apply
 */
void imago_cocoon_change_one_ccaa(enum current_clipdata_affecting_action caa)
{
    u32 y_position;
    u16 x_position;

    y_position = (u16)(current_sprite.y_position_spawn + 0x2C0);
    x_position = sub_sprite_data1.x_position;
    current_clipdata_affecting_action = caa;
    y_position -= 0x20;
    clipdata_related(y_position, x_position);
    particle_set(y_position, x_position, PE_SPRITE_EXPLOSION_HUGE);
}

/**
 * 26ce0 | 70 | Updates the current clipdata affecting action and applies it, removes the 2 blocks around the middle of the ground when falling
 * 
 * @param caa Clipdata Affecting Action to apply
 */
void imago_cocoon_change_two_middle_ccaa(enum current_clipdata_affecting_action caa)
{
    u32 y_position;
    u32 y_position_;
    u16 x_position;

    y_position = (u16)(current_sprite.y_position_spawn + 0x2C0);
    x_position = sub_sprite_data1.x_position;
    current_clipdata_affecting_action = caa;
    y_position_ = y_position - 0x20,
    clipdata_related(y_position_, x_position + 0x40);
    current_clipdata_affecting_action = caa;
    clipdata_related(y_position_, x_position - 0x40);

    particle_set(y_position, x_position + 0x48, PE_SPRITE_EXPLOSION_HUGE);
    particle_set(y_position, x_position - 0x48, PE_SPRITE_EXPLOSION_HUGE);
}

void imago_cocoon_change_two_around_ccaa(enum current_clipdata_affecting_action caa)
{
    
}

/**
 * 26dcc | 5c | Updates the current clipdata affecting action and applies it, removes the 2 blocks that block the passage
 * 
 * @param caa Clipdata Affecting Action to apply
 */
void imago_cocoon_change_two_blocking_ccaa(enum current_clipdata_affecting_action caa)
{
    u32 y_position;
    u32 y_position_;
    u32 x_position;

    y_position = (u16)(current_sprite.y_position_spawn + 0x340);
    x_position = sub_sprite_data1.x_position;
    current_clipdata_affecting_action = caa;
    y_position_ = y_position + 0x20;
    x_position += 0x240;
    clipdata_related(y_position_, x_position);
    current_clipdata_affecting_action = caa;
    y_position += 0x60;
    clipdata_related(y_position, x_position);
}

/**
 * 26e28 | 54 | 
 * Changes the oam scaling of the imago cocoon (growing or shrinking)
 * 
 * @param limit The limit of the scaling
 * @param value The value to increment/decrement the scaling
 */
void imago_cocoon_change_oam_scaling(u16 limit, u16 value)
{
    if (current_sprite.work_variable != 0x0) // Check growing/shrinking
    {
        if (current_sprite.oam_scaling > (0x100 - limit))
            current_sprite.oam_scaling -= value;
        else
            current_sprite.work_variable = 0x0; // Set growing
    }
    else
    {
        if (current_sprite.oam_scaling < (limit + 0x100))
            current_sprite.oam_scaling += value;
        else
            current_sprite.work_variable = 0x1; // Set shrinking
    }
}

void imago_cocoon_init(void)
{
    
}

/**
 * 27128 | 2c | Handles the movement of imago cocoon falling
 * 
 */
void imago_cocoon_falling_movement(void)
{
    u32 increment;

    if (current_sprite.array_offset < 0x30)
        current_sprite.array_offset++;

    increment = (current_sprite.array_offset >> 0x2) + 0x8;
    sub_sprite_data1.y_position += increment;
}

void imago_cocoon_main_loop(void)
{
    
}

/**
 * 27284 | 174 | Handles imago cocoon falling before he destroyed the blocks on the ground
 * 
 */
void imago_cocoon_falling_before_blocks(void)
{
    // /!\ Calculs with the x_position are wrong
    u16 y_position;
    u32 x_position;
    u32 offset;
    u32 rng;
    u8 timer;

    if ((eight_bit_frame_counter & 0x1F) == 0x0)
        imago_cocoon_change_oam_scaling(0x1, 0x1);

    if (sub_sprite_data1.curr_anim_frame > 0x7)
    {
        imago_cocoon_falling_movement();
        y_position = sub_sprite_data1.y_position + 0x180;
        x_position = sub_sprite_data1.x_position;
        sprite_util_check_collision_at_position(y_position, x_position);
        if (previous_collision_check & 0xF0) // Check for solid collision
        {
            imago_cocoon_change_one_ccaa(CCAA_REMOVE_SOLID); // Remove middile block
            current_sprite.pose = 0x23;
            current_sprite.timer1 = 0x0;
            screen_shake_start_vertical(0x28, 0x81);
            play_sound1(0x1A4);
        }
    }
    else
    {
        if (sub_sprite_data1.curr_anim_frame == 0x7 && sub_sprite_data1.anim_duration_counter == 0x6)
            sprite_spawn_secondary(SSPRITE_IMAGO_CEILING_VINE, 0x0, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, sub_sprite_data1.y_position, sub_sprite_data1.x_position, 0x0);

        y_position = bg1_y_position - 0x40;
        x_position = sub_sprite_data1.x_position;
        rng = sprite_rng;
        timer = current_sprite.timer1 = current_sprite.timer1 + 0x1;
        if ((timer & 0x1F) == 0x0)
        {
            if (timer & 0x20)
            {
                offset = (rng * 0x8) - 0x5A;
                x_position -= offset;
                sprite_debris_init(0x0, 0x5, y_position, x_position);
            }
            else
            {
                offset = (rng * 0x8) + 0x5A;
                x_position -= offset;
                sprite_debris_init(0x0, 0x5, y_position, x_position);
            }
        }
        
        if (sub_sprite_data1.curr_anim_frame > 0x3 && (timer & 0x1) == 0x0)
        {
            if (rng > 0x8)
            {
                offset = (rng * 0x4) - 0x96;
                x_position += offset;
                sprite_debris_init(0x0, 0x8, y_position, x_position);
                offset = (rng * 0x4) - 0x20;
                x_position -= offset;
                sprite_debris_init(0x0, 0x6, y_position, x_position);
            }
            else
            {
                offset = (rng * 0x4) - 0x82;
                x_position -= offset;
                sprite_debris_init(0x0, 0x6, y_position, x_position);
                offset = (rng * 0x4) - 0x20;
                x_position += offset;
                sprite_debris_init(0x0, 0x8, y_position, x_position);
            }
        }
    }
}

void imago_cocoon_falling_after_blocks(void)
{
    
}

/**
 * 274f4 | 48 | Checks if the passage should be unlocked, and unlocks it if yes
 * 
 */
void imago_cocoon_unlock_passage(void)
{
    if (current_sprite.status & SPRITE_STATUS_ONSCREEN)
    {
        current_sprite.timer1--;
        if (current_sprite.timer1 == 0x0)
        {
            current_sprite.pose = 0x27;
            imago_cocoon_change_two_blocking_ccaa(CCAA_REMOVE_SOLID); // Remove blocking collision
            door_unlock_timer = -0x3C;
            music_play(0xB, 0x0); // Boss killed
        }
    }
}

void imago_cocoon_in_ground_anim(void)
{
    
}

void imago_cocoon_vine_init(void)
{
    
}

void imago_cocoon_vine_play_sound(void)
{
    
}

/**
 * 27904 | 88 | Called when a vine dies, plays a particle effect and decrements the health of the boss 
 * 
 */
void imago_cocoon_vine_death(void)
{
    u16 y_position;
    u16 x_position;

    y_position = current_sprite.y_position;
    x_position = current_sprite.x_position;

    switch (current_sprite.room_slot)
    {
        case 0x1:
            break;
        case 0x2:
        case 0x6:
        case 0x7:
            y_position += 0x20;
            break;
        case 0x8:
        case 0x9:
            y_position += 0x10;
            break;
        default:
            current_sprite.status = 0x0;
            return;
    }

    particle_set(y_position, x_position, PE_SPRITE_EXPLOSION_HUGE);
    if (sub_sprite_data1.health != 0x0)
        sub_sprite_data1.health--; // Health = number of vines alive so when a vine dies it gets decremented
    current_sprite.status = 0x0;
}

/**
 * 2798c | 160 | Handles the vines spawning the spores, and the ceiling vine attached to imago cocoon dying?
 * 
 */
void imago_cocoon_vine_spawn_spore(void)
{
    u8 slot;
    u8 ram_slot;
    u8 gfx_slot;
    enum sprite_status status;
    u16 y_position;
    u16 x_position;

    slot = current_sprite.primary_sprite_ram_slot;

    if (sprite_data[slot].pose == 0x25)
    {
        y_position = current_sprite.y_position;
        if (current_sprite.room_slot == 0x0)
            x_position = current_sprite.x_position + 0x40;
        else
            x_position = current_sprite.x_position - 0x40;
        particle_set(y_position - 0x64, x_position, PE_TWO_MEDIUM_DUST);
        current_sprite.status = 0x0;
    }
    else if (sub_sprite_data1.health != 0x0 && current_sprite.room_slot == 0x0)
    {
        current_sprite.y_position_spawn++;
        if ((current_sprite.y_position_spawn & 0xFF) == 0x0)
        {
            if (current_sprite.y_position_spawn & 0x100)
            {
                // Spore on the left
                y_position = current_sprite.y_position - 0x60;
                x_position = current_sprite.x_position - 0x46;
                status = SPRITE_STATUS_NONE;
            }
            else
            {
                // Spore on the right
                y_position = current_sprite.y_position - 0x90;
                x_position = current_sprite.x_position + 0x64;
                status = SPRITE_STATUS_XFLIP;
            }

            gfx_slot = current_sprite.spriteset_gfx_slot;
            ram_slot = current_sprite.timer2;
            sprite_spawn_secondary(SSPRITE_IMAGO_COCOON_SPORE, 0x0, gfx_slot, ram_slot, y_position, x_position, status);
            sprite_spawn_secondary(SSPRITE_IMAGO_COCOON_SPORE, 0x1, gfx_slot, ram_slot, y_position, x_position, status);
            sprite_spawn_secondary(SSPRITE_IMAGO_COCOON_SPORE, 0x2, gfx_slot, ram_slot, y_position, x_position, status);
            sprite_spawn_secondary(SSPRITE_IMAGO_COCOON_SPORE, 0x3, gfx_slot, ram_slot, y_position, x_position, status);
            sprite_spawn_secondary(SSPRITE_IMAGO_COCOON_SPORE, 0x4, gfx_slot, ram_slot, y_position, x_position, status);
            sprite_spawn_secondary(SSPRITE_IMAGO_COCOON_SPORE, 0x5, gfx_slot, ram_slot, y_position, x_position, status);
            sprite_spawn_secondary(SSPRITE_IMAGO_COCOON_SPORE, 0x6, gfx_slot, ram_slot, y_position, x_position, status);
            sprite_spawn_secondary(SSPRITE_IMAGO_COCOON_SPORE, 0x7, gfx_slot, ram_slot, y_position, x_position, status);
        }
    }
}

/**
 * 27aec | 44 | Handles the removal of the hanging vine when imago cocoon dies
 * 
 */
void imago_cocoon_vine_hanging_death(void)
{
    if (sub_sprite_data1.health == 0x0 && sub_sprite_data1.curr_anim_frame > 0x7)
    {
        current_sprite.ignore_samus_collision_timer = 0x1;
        current_sprite.status |= SPRITE_STATUS_UNKNOWN3;
        current_sprite.samus_collision = SSC_NONE;
        current_sprite.pose = 0x43;
    }
}

/**
 * 27b30 | 44 | Handles the animation of the removal of the hanging vine when imago cocoon dies
 * 
 */
void imago_cocoon_vine_hanging_death_anim(void)
{
    u8 slot;

    current_sprite.ignore_samus_collision_timer = 0x1;
    slot = current_sprite.primary_sprite_ram_slot;
    if (sprite_data[slot].pose == 0x25)
    {
        particle_set(current_sprite.y_position + 0xA0, current_sprite.x_position, PE_SPRITE_EXPLOSION_HUGE);
        current_sprite.status = 0x0;
    }
}

/**
 * 27b74 | 54 | Synchronizes the spore position with the imago cocoon position
 * 
 */
void imago_cocoon_spore_sync_position(void)
{
    u8 slot;

    slot = current_sprite.primary_sprite_ram_slot;
    if (current_sprite.status & SPRITE_STATUS_XFLIP)
    {
        current_sprite.y_position = sprite_data[slot].y_position - 0x90;
        current_sprite.x_position = sprite_data[slot].x_position + 0x64;
    }
    else
    {
        current_sprite.y_position = sprite_data[slot].y_position - 0x60;
        current_sprite.x_position = sprite_data[slot].x_position + 0x46;
    }
}

/**
 * 27bc8 | a8 | Initialize an imago cocoon spore sprite
 * 
 */
void imago_cocoon_spore_init(void)
{
    if (current_sprite.room_slot == 0x0)
        current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    current_sprite.draw_distance_top_offset = 0xC;
    current_sprite.draw_distance_bottom_offset = 0xC;
    current_sprite.draw_distance_horizontal_offset = 0xC;
    current_sprite.hitbox_top_offset = -0x8;
    current_sprite.hitbox_bottom_offset = 0x8;
    current_sprite.hitbox_left_offset = -0x8;
    current_sprite.hitbox_right_offset = 0x5;
    current_sprite.oam_pointer = imago_cocoon_spore_oam_2e0bd0;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.pose = 0x9;
    current_sprite.samus_collision = SSC_NONE;
    current_sprite.draw_order = 0x3;
    current_sprite.bg_priority = io_registers_backup.bg2cnt & 0x3;
    current_sprite.health = secondary_sprite_stats_2b1be4[current_sprite.sprite_id][0x0];
    current_sprite.status |= SPRITE_STATUS_UNKNOWN3;
    current_sprite.ignore_samus_collision_timer = 0x1;
    imago_cocoon_spore_sync_position();
}

/**
 * 27c70 | 74 | Handles an imago cocoon spore before it spawns (after it appeared, but before it moves)
 * 
 */
void imago_cocoon_spore_before_spawning(void)
{
    imago_cocoon_spore_sync_position();
    if (sub_sprite_data1.health == 0x0)
        current_sprite.pose = 0x42; // If imago cocoon is dead, kill the spores
    else
    {
        if (current_sprite.room_slot == 0x0 && current_sprite.status & SPRITE_STATUS_ONSCREEN && current_sprite.curr_anim_frame == 0x0 && current_sprite.anim_duration_counter == 0x1)
            play_sound1(0x1A0);

        if (sprite_util_check_end_current_sprite_anim())
        {
            current_sprite.oam_pointer = imago_cocoon_spore_oam_2e0bf8;
            current_sprite.anim_duration_counter = 0x0;
            current_sprite.curr_anim_frame = 0x0;
            current_sprite.pose = 0x23;
            current_sprite.timer1 = 0x3C;
        }
    }
}

/**
 * 27ce4 | 8c | Handles the spawning of the imago cocoon spore  
 * 
 */
void imago_cocoon_spore_spawning(void)
{
    imago_cocoon_spore_sync_position();
    if (sub_sprite_data1.health == 0x0)
        current_sprite.pose = 0x42; // If imago cocoon is dead, kill the spores
    else
    {
        current_sprite.timer1--;
        if (current_sprite.timer1 == 0x0)
        {
            current_sprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
            current_sprite.oam_pointer = imago_cocoon_spore_oam_2e0c18;
            current_sprite.anim_duration_counter = 0x0;
            current_sprite.curr_anim_frame = 0x0;
            current_sprite.properties |= SP_PROJECTILE;
            current_sprite.samus_collision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
            current_sprite.pose = 0x25;
            if (current_sprite.room_slot == 0x0 && current_sprite.status & SPRITE_STATUS_ONSCREEN)
                play_sound1(0x1A1);
        }
    }
}

void imago_cocoon_spore_move(void)
{
    
}

/**
 * 27e84 | 34 | Initializes the graphics for the imago cocoon spore exploding
 * 
 */
void imago_cocoon_spore_exploding_gfx_init(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    current_sprite.oam_pointer = imago_cocoon_spore_oam_2e0c38;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.pose = 0x43;
    current_sprite.status |= SPRITE_STATUS_UNKNOWN3;
}

/**
 * 27eb8 | 24 | Checks if the explosion animation has ended, if yes kills the sprite
 * 
 */
void imago_cocoon_spore_check_exploding_anim_ended(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    if (sprite_util_check_end_current_sprite_anim())
        current_sprite.status = 0x0;
}

// 27edc | c4 | Checks if the winged ripper and imago are colliding (only if imago is falling), sets the winged ripper to a killed pose if yes
// Returns : 1 if colliding, 0 otherwise
u8 winged_ripper_imago_collision(void)
{
    u8 colliding;
    u8 slot;
    struct sprite_data* pSprite;
    u16 sprite_y;
    u16 sprite_x;
    u16 sprite_top;
    u16 sprite_bottom;
    u16 sprite_left;
    u16 sprite_right;
    u16 imago_y;
    u16 imago_x;
    u16 imago_top;
    u16 imago_bottom;
    u16 imago_left;
    u16 imago_right;

    colliding = FALSE;
    pSprite = sprite_data + current_sprite.primary_sprite_ram_slot;
    if (pSprite->pose == 0x9 && pSprite->array_offset > 0x10)
    {
        sprite_y = current_sprite.y_position;
        sprite_x = current_sprite.x_position;
        sprite_top = sprite_y + current_sprite.hitbox_top_offset;
        sprite_bottom = sprite_y + current_sprite.hitbox_bottom_offset;
        sprite_left = sprite_x + current_sprite.hitbox_left_offset;
        sprite_right = sprite_x + current_sprite.hitbox_right_offset;
        
        imago_y = pSprite->y_position;
        imago_x = pSprite->x_position;
        imago_top = imago_y + pSprite->hitbox_top_offset;
        imago_bottom = imago_y + pSprite->hitbox_bottom_offset;
        imago_left = imago_x + pSprite->hitbox_left_offset;
        imago_right = imago_x + pSprite->hitbox_right_offset;

        if (sprite_util_check_objects_touching(sprite_top, sprite_bottom, sprite_left, sprite_right, imago_top, imago_bottom, imago_left, imago_right))
        {
            current_sprite.pose = 0x62;
            colliding = TRUE;
        }
    }

    return colliding;
}

// 27fa0 | a0 | Initializes a winged ripper sprite  
void winged_ripper_init(void)
{
    current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    current_sprite.hitbox_top_offset = -0x20;
    current_sprite.hitbox_bottom_offset = 0x4;
    current_sprite.hitbox_left_offset = -0x20;
    current_sprite.hitbox_right_offset = 0x20;
    current_sprite.draw_distance_top_offset = 0xC;
    current_sprite.draw_distance_bottom_offset = 0x8;
    current_sprite.draw_distance_horizontal_offset = 0x10,
    current_sprite.oam_pointer = winged_ripper_oam_2e0c60;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.samus_collision = SSC_HURTS_SAMUS;
    current_sprite.health = secondary_sprite_stats_2b1be4[current_sprite.sprite_id][0x0];
    current_sprite.draw_order = 0x8;
    current_sprite.pose = 0x8;
    current_sprite.oam_scaling = 0xC0;
    current_sprite.timer2 = 0x80;
    current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
    current_sprite.array_offset = 0x0;
    current_sprite.frozen_palette_row_offset = 0x4;
}

void winged_ripper_gfx_init(void)
{
    current_sprite.pose = 0x9;
    current_sprite.oam_pointer = winged_ripper_oam_2e0c60;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.anim_duration_counter = 0x0;
}

void winged_ripper_move(void)
{

}

void winged_ripper_death(void)
{
    if (current_sprite.standing_on_sprite)
    {
        if (samus_data.standing_status == STANDING_ENEMY)
            samus_data.standing_status = STANDING_MIDAIR;
        current_sprite.standing_on_sprite = FALSE;
    }
    sprite_util_sprite_death(DEATH_NORMAL, current_sprite.y_position + 0x8, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
}

void imago_cocoon(void)
{
    switch (current_sprite.pose)
    {
        case 0x0:
            imago_cocoon_init();
            break;
        case 0x8:
            imago_cocoon_main_loop();
            break;
        case 0x9:
            imago_cocoon_falling_before_blocks();
            break;
        case 0x23:
            imago_cocoon_falling_after_blocks();
            break;
        case 0x25:
            imago_cocoon_unlock_passage();
            break;
        case 0x27:
            imago_cocoon_in_ground_anim();
    }

    if (current_sprite.pose > 0x24)
        sprite_util_sync_current_sprite_position_with_sub_sprite1_position();
    else
        imago_cocoon_update_position_and_anim();
}

void imago_cocoon_vine(void)
{
    switch (current_sprite.pose)
    {
        case 0x0:
            imago_cocoon_vine_init();
            break;
        case 0x62:
            imago_cocoon_vine_death();
        case 0x8:
            imago_cocoon_vine_play_sound();
            break;
        case 0xE:
            imago_cocoon_vine_spawn_spore();
            break;
        case 0x42:
            imago_cocoon_vine_hanging_death();
            break;
        case 0x43:
            imago_cocoon_vine_hanging_death_anim();
    }

    if (current_sprite.pose == 0x67)
        sprite_util_sync_current_sprite_position_with_sub_sprite1_position();
    else
        imago_cocoon_update_position_and_anim();
}

void imago_cocoon_spore(void)
{
    switch (current_sprite.pose)
    {
        case 0x0:
            imago_cocoon_spore_init();
            break;
        case 0x9:
            imago_cocoon_spore_before_spawning();
            break;
        case 0x23:
            imago_cocoon_spore_spawning();
            break;
        case 0x25:
            imago_cocoon_spore_move();
            break;
        case 0x42:
            imago_cocoon_spore_exploding_gfx_init();
            break;
        case 0x43:
            imago_cocoon_spore_check_exploding_anim_ended();
            break;
        default:
            sprite_util_sprite_death(DEATH_NORMAL, current_sprite.y_position, current_sprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            if (current_sprite.status & SPRITE_STATUS_EXISTS && sprite_util_count_drops() > 0x1)
                current_sprite.status = 0x0; // Anti lag measure
    }
}

void winged_ripper(void)
{
    if (current_sprite.freeze_timer != 0x0)
    {
        sprite_util_unfreeze_anim_easy();
        if (!(winged_ripper_imago_collision() << 0x18))
            return;
    }
    if (!sprite_util_is_sprite_stunned())
    {
        switch (current_sprite.pose)
        {
            case 0x0:
                winged_ripper_init();
                break;
            case 0x8:
                winged_ripper_gfx_init();
            case 0x9:
                winged_ripper_move();
                break;
            default:
                winged_ripper_death();
        }

        current_sprite.array_offset++;
    }
}

void defeated_imago_cocoon(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    if (current_sprite.pose == 0x0)
    {
        current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        current_sprite.status |= SPRITE_STATUS_UNKNOWN3;
        current_sprite.draw_distance_top_offset = 0xC;
        current_sprite.draw_distance_bottom_offset = 0x28;
        current_sprite.draw_distance_horizontal_offset = 0x30;
        current_sprite.hitbox_top_offset = -0x4;
        current_sprite.hitbox_bottom_offset = 0x4;
        current_sprite.hitbox_left_offset = -0x4;
        current_sprite.hitbox_right_offset = 0x4;
        current_sprite.oam_pointer = imago_cocoon_oam_2e0d00;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.samus_collision = SSC_NONE;
        current_sprite.pose = 0x9;
        current_sprite.frozen_palette_row_offset = 0x5;
    }
}

void imago_ceiling_vine(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    if (current_sprite.pose == 0x0)
    {
        current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        current_sprite.status |= SPRITE_STATUS_UNKNOWN3;
        current_sprite.draw_distance_top_offset = 0xC;
        current_sprite.draw_distance_bottom_offset = 0x28;
        current_sprite.draw_distance_horizontal_offset = 0x30;
        current_sprite.hitbox_top_offset = -0x4;
        current_sprite.hitbox_bottom_offset = 0x4;
        current_sprite.hitbox_left_offset = -0x4;
        current_sprite.hitbox_right_offset = 0x4;
        current_sprite.oam_pointer = imago_ceiling_vine_oam_2e0a28;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.samus_collision = SSC_NONE;
        current_sprite.draw_order = 0x5;
        current_sprite.pose = 0x9;
        current_sprite.frozen_palette_row_offset = 0x5;
    }
}

void event_trigger_discovered_imago_passage(void)
{
    if (current_sprite.pose == 0x0)
    {
        if (event_function(EVENT_ACTION_CHECKING, EVENT_IMAGO_TUNNEL_DISCOVERED))
        {
            current_sprite.status = 0x0;
            return;
        }
        current_sprite.status |= SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3;
        current_sprite.samus_collision = SSC_ABILITY_LASER_SEARCHLIGHT;
        current_sprite.draw_distance_top_offset = 0x10;
        current_sprite.draw_distance_bottom_offset = 0x0;
        current_sprite.draw_distance_horizontal_offset = 0x8;
        current_sprite.hitbox_top_offset = -0x40;
        current_sprite.hitbox_bottom_offset = 0x0;
        current_sprite.hitbox_left_offset = -0x20;
        current_sprite.hitbox_right_offset = 0x20;
        current_sprite.pose = 0x8;
        current_sprite.oam_pointer = large_energy_oam_2b2750;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
    }

    if (current_sprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        current_sprite.status = 0x0;
        event_function(EVENT_ACTION_SETTING, EVENT_IMAGO_TUNNEL_DISCOVERED);
    }
}

void imago_cocoon_after_fight(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    if (current_sprite.pose == 0x0)
    {
        current_sprite.draw_distance_top_offset = 0x30;
        current_sprite.draw_distance_bottom_offset = 0x10;
        current_sprite.draw_distance_horizontal_offset = 0x20;
        current_sprite.hitbox_top_offset = -0x4;
        current_sprite.hitbox_bottom_offset = 0x4;
        current_sprite.hitbox_left_offset = -0x4;
        current_sprite.hitbox_right_offset = 0x4;
        current_sprite.oam_pointer = imago_cocoon_oam_2e0d00;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.samus_collision = SSC_NONE;
        current_sprite.pose = 0x9;
    }

    if (current_sprite.anim_duration_counter == 0x1)
    {
        switch (current_sprite.curr_anim_frame)
        {
            case 0x1:
            case 0x4:
                play_sound1(0x212);
        }
    }
}