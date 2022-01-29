#include "particle.h"
#include "globals.h"
#include "screen_shake.h"

void particle_check_on_screen(struct particle_effect* ptr)
{
    
}

void particle_draw(struct particle_effect* ptr)
{

}

void particle_process_all(void)
{
    struct particle_effect* ptr;
    enum particle_status status;

    if (game_mode_sub1 != 0x2 && (game_mode_sub1 == 0x1 || game_mode_sub1 == 0x3))
    {
        ptr = particle_effects;
        while (ptr < particle_effects + 16)
        {
            if ((ptr->status & PARTICLE_STATUS_EXISTS) != 0x0 && ptr->effect == PE_ESCAPE)
            {
                bx_r1(ptr, func_array[ptr->effect]);
                if ((ptr->status & PARTICLE_STATUS_EXISTS) != 0x0)
                    particle_draw(ptr);
            } 
            ptr++;
        }
    }
    else
    {
        ptr = particle_effects;
        while (ptr < particle_effects + 16)
        {
            if ((ptr->status & (PARTICLE_STATUS_EXISTS | PARTICLE_STATUS_EXPLOSION)) == (PARTICLE_STATUS_EXISTS | PARTICLE_STATUS_EXPLOSION))
            {
                bx_r1(ptr, func_array[ptr->effect]);
                if ((ptr->status & PARTICLE_STATUS_EXISTS) != 0x0)
                {
                    particle_check_on_screen(ptr);
                    status = (ptr->status & (PARTICLE_STATUS_ONSCREEN | PARTICLE_STATUS_UNKNOWN));
                    if (status == PARTICLE_STATUS_ONSCREEN)
                        particle_draw(ptr);
                }
            }
            ptr++;
        }
                
        ptr = particle_effects;
         while (ptr < particle_effects + 16)
        {
            if ((ptr->status & (PARTICLE_STATUS_EXISTS | PARTICLE_STATUS_EXPLOSION)) == PARTICLE_STATUS_EXISTS)
            {
                bx_r1(ptr, func_array[ptr->effect]);
                if ((ptr->status & PARTICLE_STATUS_EXISTS) != 0x0)
                {
                    particle_check_on_screen(ptr);
                    status = (ptr->status & (PARTICLE_STATUS_ONSCREEN | PARTICLE_STATUS_UNKNOWN));
                    if (status == PARTICLE_STATUS_ONSCREEN)
                        particle_draw(ptr);
                }
            }
            ptr++;
        }
        update_escape_timer();
    }
}

void particle_set(u16 y_position, u16 x_position, enum particle_effect_id effect)
{
    struct particle_effect* ptr;
    u8 unk;

    unk = 0x0;
    ptr = particle_effects;

    if (particle_effects[0].status == 0x0) break;
    while (ptr < particle_effects + 16)
    {
        ptr++;
        if (ptr->status == 0x0)
        {
            unk = 0x1;
            break;
        }
    }

    ptr->status = PARTICLE_STATUS_EXISTS;
    ptr->y_position = y_position;
    ptr->x_position = x_position;
    ptr->curr_anim_frame = 0x0;
    ptr->anim_duration_counter = 0x0;
    ptr->effect = effect;
    ptr->stage = 0x0;
    ptr->frame_counter = 0x0;
}

u8 particle_update_animation(struct particle_effect* ptr, struct frame_data* oam_ptr)
{
    u8 ended;
    u32 adc;

    ended = 0x0;
    adc = ptr->anim_duration_counter + 0x1;
    ptr->anim_duration_counter = adc;
    if ((u8)oam_ptr[ptr->curr_anim_frame].timer <= (u8)adc)
    {
        ptr->anim_duration_counter = 0x0;
        ptr->curr_anim_frame++;
        if ((u8)oam_ptr[ptr->curr_anim_frame].timer == 0x0)
        {
            ptr->curr_anim_frame = 0x0;
            ended = 0x1;
        }
    }

    curr_particle_oam_frame_ptr = oam_ptr[ptr->curr_anim_frame].oam_frame_ptr;
    return ended;
}

void particle_set_current_oam_frame_pointer(struct particle_effect* ptr, struct frame_data* oam_ptr)
{
    curr_particle_oam_frame_ptr = oam_ptr[ptr->curr_anim_frame].oam_frame_ptr;
}

void particle_sprite_splash_water_small(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        ptr->y_position = effect_y_position;
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_sprite_splash_water_big(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        ptr->y_position = effect_y_position;
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_sprite_splash_water_huge(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        ptr->y_position = effect_y_position;
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_sprite_splash_lava_small(struct particle_effect* ptr)
{

    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        ptr->y_position = effect_y_position;
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_sprite_splash_lava_big(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        ptr->y_position = effect_y_position;
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_sprite_splash_lava_huge(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        ptr->y_position = effect_y_position;
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_sprite_splash_acid_small(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        ptr->y_position = effect_y_position;
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_sprite_splash_acid_big(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        ptr->y_position = effect_y_position;
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_sprite_splash_acid_huge(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        ptr->y_position = effect_y_position;
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_shooting_beam_left(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_shooting_beam_right(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= (PARTICLE_STATUS_XFLIP | PARTICLE_STATUS_UNKNOWN2);
    }
}

void particle_shooting_beam_diag_up_left(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_shooting_beam_diag_up_right(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= (PARTICLE_STATUS_XFLIP | PARTICLE_STATUS_UNKNOWN2);
    }
}

void particle_shooting_beam_diag_down_left(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_shooting_beam_diag_down_right(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= (PARTICLE_STATUS_XFLIP | PARTICLE_STATUS_UNKNOWN2);
    }
}

void particle_shooting_beam_up_left(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_shooting_beam_up_right(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= (PARTICLE_STATUS_XFLIP | PARTICLE_STATUS_UNKNOWN2);
    }
}

void particle_shooting_beam_down_left(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_shooting_beam_down_right(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= (PARTICLE_STATUS_XFLIP | PARTICLE_STATUS_UNKNOWN2);
    }
}

void particle_bomb(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
        {
            ptr->stage++;
            ptr->status |= PARTICLE_STATUS_EXPLOSION;
            play_sound1(0xFF);
        }
    }
}

void particle_missile_trail(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_super_missile_trail(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_beam_trailing_right(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
        {
            ptr->x_position++;
            ptr->y_position += 0x4;
            return;
        }
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_beam_trailing_left(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
        {
            ptr->x_position--;
            ptr->y_position += 0x4;
            return;
        }
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_charged_long_beam_trailing(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
            ptr->stage++;
    }
}

void particle_charged_ice_beam_trailing(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
            ptr->stage++;
    }
}

void particle_charged_wave_beam_trail(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
            ptr->stage++;
    }
}

void particle_charged_plasma_beam_trail(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
            ptr->stage++;
    }
}

void particle_charged_full_beam_trail(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
            ptr->stage++;
    }
}

void particle_charged_pistol_trail(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
            ptr->stage++;
    }
}

void particle_sprite_explosion_huge(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_sprite_explosion_small(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_sprite_explosion_medium(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_sprite_explosion_big(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_sprite_explosion_single_then_big(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_screw_attack_destroyed(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_shinespark_destroyed(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_sudo_screw_destroyed(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_speedbooster_destroyed(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_main_boss_death(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_freezing_sprite_with_ice(struct particle_effect* ptr)
{
    u8 ended;

    ptr->status ^= PARTICLE_STATUS_UNKNOWN;
    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_freezing_sprite_with_charged_ice(struct particle_effect* ptr)
{
    u8 ended;

    ptr->status ^= PARTICLE_STATUS_UNKNOWN;
    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_hitting_something_with_base_beam(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
        {
            ptr->stage++;
            play_sound1(0x102);
        }
    }
}

void particle_hitting_something_with_long_beam(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
        {
            ptr->stage++;
            play_sound1(0x103);
        }
    }
}

void particle_hitting_something_with_ice_beam(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
        {
            ptr->stage++;
            play_sound1(0x104);
        }
    }
}

void particle_hitting_something_with_wave_beam(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
        {
            ptr->stage++;
            play_sound1(0x105);
        }
    }
}

void particle_hitting_something_with_full_beam_no_plasma(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
        {
            ptr->stage++;
            play_sound1(0x104);
        }
    }
}

void particle_hitting_something_with_plasma_beam(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
        {
            ptr->stage++;
            play_sound1(0x106);
        }
    }
}

void particle_hitting_something_with_full_beam(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
        {
            ptr->stage++;
            play_sound1(0x104);
        }
    }
}

void particle_hitting_something_invicible(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
        {
            ptr->stage++;
            play_sound1(0x107);
        }
    }
}

void particle_hitting_something_with_missile(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
        {
            ptr->stage++;
            play_sound1(0xF9)
            play_sound1(0xFA);
        }
    }
}

void particle_hitting_something_with_super_missile(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
        {
            ptr->stage++;
            play_sound1(0xFC)
            play_sound1(0xFD);
            screen_shake_start_horizontal(0xA, 0x81);
            screen_shake_start_vertical(0xA, 0x81);
        }
    }
}

void particle_small_dust(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
            ptr->stage++;
    }
}

void particle_medium_dust(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
            ptr->stage++;
    }
}

void particle_two_medium_dust(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage == 0x0)
            ptr->stage++;
    }
}

void particle_second_small_dust(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_second_medium_dust(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_second_two_medium_dust(struct particle_effect* ptr)
{
    u8 ended;

    ptr->frame_counter++;
    ended = //particle_update_animation(ptr, frame_data_array);
    if (ended != 0x0)
        ptr->status = 0x0;
    else
    {
        if (ptr->stage != 0x0)
            return;
        ptr->stage++;
        ptr->status |= PARTICLE_STATUS_UNKNOWN2;
    }
}

void particle_play_begin_to_charge_sound(void)
{

}

void particle_play_shooting_charged_beam_sound(void)
{

}

void particle_play_beam_fully_charged_sound(void)
{

}

void particle_charging_beam(struct particle_effect* ptr)
{

}

void particle_escape(struct particle_effect* ptr)
{

}

void particle_samus_reflecion(struct particle_effect* ptr)
{

}