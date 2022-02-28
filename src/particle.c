#include "particle.h"
#include "escape.h"
#include "screen_shake.h"
#include "globals.h"

void particle_check_on_screen(struct particle_effect* pParticle)
{
    
}

void particle_draw(struct particle_effect* pParticle)
{
    /*u8 next_slot;
    u8 new_next_slot;
    u16 part_count;
    struct raw_oam_data* frame_data_pParticle;
    struct raw_oam_data* curr_oam_data;
    struct oam_frame* oam_frame_ptr;
    enum particle_status status;
    u16 y_pos;
    u16 x_pos;
    u16 priority;

    next_slot = next_oam_slot;
    part_count = curr_particle_oam_frame_ptr->part_count;
    if (part_count + next_oam_slot < 0x80)
    {
        frame_data_pParticle = oam_data + next_slot;
        status = pParticle->status;
        if ((status & PARTICLE_STATUS_ABSOLUTE_POSITION) != 0x0)
        {
            y_pos = pParticle->y_position;
            x_pos = pParticle->x_position;
        }
        else
        {
            y_pos = (pParticle->y_position >> 0x2) - (bg1_y_position >> 0x2);
            x_pos = (pParticle->x_position >> 0x2) - (bg1_x_position >> 0x2);
        }

        if ((status & PARTICLE_STATUS_LOW_PRIORITY) != 0x0)
        {
            priority = 0x2;
            if (samus_on_top_backgrounds != FALSE)
                priority = 0x1;
        }
        else
            priority = 0x0;

        new_next_slot = curr_particle_oam_frame_ptr->part_count + next_oam_slot;
        
        if (part_count != 0x0)
        {
            curr_oam_data = oam_data + next_slot;
            oam_frame_ptr = curr_particle_oam_frame_ptr;
            do {
                frame_data_pParticle->part1 = oam_frame_ptr->data[0].oam0;
                (u8)curr_oam_data->part1 = (u8)frame_data_pParticle->part1 + y_pos;

                frame_data_pParticle->part2 = oam_frame_ptr->data[0].oam1;
                curr_oam_data->part2 = curr_oam_data->part2 & 0xFE00 | frame_data_pParticle->part2 + x_pos & 0x1FF;

                frame_data_pParticle->part3 = oam_frame_ptr->data[0].oam2;
                (u8)(curr_oam_data->part3 + 1) = (u8)(curr_oam_data->part3 + 1) & 0xF3 | (u8)(priority << 0x2);

                if ((status & PARTICLE_STATUS_XFLIP) != 0x0)
                {
                    (u8)(curr_oam_data->part2 + 1) = (u8)(curr_oam_data->part2 + 1) & 0xEF | (((u8)(curr_oam_data->part2 + 1) << 0x1B) >> 0x1F ^ 0x1) << 0x4;
                    curr_oam_data->part2 = curr_oam_data->part2 & 0xFE00 | x_pos - (oam_frame_ptr->data[1] + array_2b0c94[((u8)(curr_oam_data->part2 + 1) >> 0x6) + ((u8)(curr_oam_data->part1 + 1) >> 0x6) * 0x4] * 0x8) & 0x1FF;
                }

                frame_data_pParticle++;
                curr_oam_data++;
                part_count--;
            } while (part_count != 0x0);
        }

        next_oam_slot = new_next_slot;
    }*/
}

/**
 * 53fd8 | 114 | Processes all the particle effects (calls subroutine and calls the draw function)
 * 
 */
void particle_process_all(void)
{
    struct particle_effect* pParticle;
    enum particle_status status;

    if (game_mode_sub1 != 0x2 && (game_mode_sub1 == 0x1 || game_mode_sub1 == 0x3))
    {
        pParticle = particle_effects;
        while (pParticle < particle_effects + 16)
        {
            if (pParticle->status & PARTICLE_STATUS_EXISTS && pParticle->effect == PE_ESCAPE) // Probably a priority system
            {
                (*pVoid_pParticle_array_75f9b4[pParticle->effect])(pParticle); // Call subroutine
                if ((pParticle->status & PARTICLE_STATUS_EXISTS) != 0x0)
                    particle_draw(pParticle);
            } 
            pParticle++;
        }
    }
    else
    {
        pParticle = particle_effects;
        while (pParticle < particle_effects + 16)
        {
            if ((pParticle->status & (PARTICLE_STATUS_EXISTS | PARTICLE_STATUS_EXPLOSION)) == (PARTICLE_STATUS_EXISTS | PARTICLE_STATUS_EXPLOSION))
            {
                (*pVoid_pParticle_array_75f9b4[pParticle->effect])(pParticle); // Call subroutine
                if ((pParticle->status & PARTICLE_STATUS_EXISTS) != 0x0)
                {
                    particle_check_on_screen(pParticle);
                    status = (pParticle->status & (PARTICLE_STATUS_ONSCREEN | PARTICLE_STATUS_NOT_DRAWN));
                    if (status == PARTICLE_STATUS_ONSCREEN)
                        particle_draw(pParticle);
                }
            }
            pParticle++;
        }
                
        pParticle = particle_effects;
         while (pParticle < particle_effects + 16)
        {
            if ((pParticle->status & (PARTICLE_STATUS_EXISTS | PARTICLE_STATUS_EXPLOSION)) == PARTICLE_STATUS_EXISTS)
            {
                (*pVoid_pParticle_array_75f9b4[pParticle->effect])(pParticle); // Call subroutine
                if (pParticle->status & PARTICLE_STATUS_EXISTS)
                {
                    particle_check_on_screen(pParticle);
                    status = (pParticle->status & (PARTICLE_STATUS_ONSCREEN | PARTICLE_STATUS_NOT_DRAWN));
                    if (status == PARTICLE_STATUS_ONSCREEN)
                        particle_draw(pParticle);
                }
            }
            pParticle++;
        }
        escape_update_timer();
    }
}

/**
 * 540ec | a0 | 
 * Sets a new particle with the given parameters
 * 
 * @param y_position Y Position
 * @param x_position X Position
 * @param effect Particle effect ID
 */
void particle_set(u16 y_position, u16 x_position, enum particle_effect_id effect)
{

}

u8 particle_update_animation(struct particle_effect* pParticle, struct frame_data* oam_pParticle)
{
    u8 ended;
    u32 adc;

    ended = 0x0;
    adc = pParticle->anim_duration_counter + 0x1;
    pParticle->anim_duration_counter = adc;
    if ((u8)oam_pParticle[pParticle->curr_anim_frame].timer <= (u8)adc)
    {
        pParticle->anim_duration_counter = 0x0;
        pParticle->curr_anim_frame++;
        if ((u8)oam_pParticle[pParticle->curr_anim_frame].timer == 0x0)
        {
            pParticle->curr_anim_frame = 0x0;
            ended = 0x1;
        }
    }

    curr_particle_oam_frame_ptr = oam_pParticle[pParticle->curr_anim_frame].oam_frame_ptr;
    return ended;
}

void particle_set_current_oam_frame_pointer(struct particle_effect* pParticle, struct frame_data* oam_pParticle)
{
    curr_particle_oam_frame_ptr = oam_pParticle[pParticle->curr_anim_frame].oam_frame_ptr;
}

void particle_sprite_splash_water_small(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33d5ac);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = effect_y_position;
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_sprite_splash_water_big(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33d50c);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = effect_y_position;
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_sprite_splash_water_huge(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33d55c);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = effect_y_position;
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_sprite_splash_lava_small(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33d684);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = effect_y_position;
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_sprite_splash_lava_big(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33d5e4);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = effect_y_position;
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_sprite_splash_lava_huge(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33d634);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = effect_y_position;
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_sprite_splash_acid_small(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33d75c);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = effect_y_position;
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_sprite_splash_acid_big(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33d6bc);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = effect_y_position;
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_sprite_splash_acid_huge(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33d70c);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = effect_y_position;
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_shooting_beam_left(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_339ce4);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_shooting_beam_right(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_339ce4);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= (PARTICLE_STATUS_XFLIP | PARTICLE_STATUS_LOW_PRIORITY);
    }
}

void particle_shooting_beam_diag_up_left(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_339d0c);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_shooting_beam_diag_up_right(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_339d0c);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= (PARTICLE_STATUS_XFLIP | PARTICLE_STATUS_LOW_PRIORITY);
    }
}

void particle_shooting_beam_diag_down_left(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_339d34);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_shooting_beam_diag_down_right(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_339d34);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= (PARTICLE_STATUS_XFLIP | PARTICLE_STATUS_LOW_PRIORITY);
    }
}

void particle_shooting_beam_up_left(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_339d5c);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_shooting_beam_up_right(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_339d5c);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= (PARTICLE_STATUS_XFLIP | PARTICLE_STATUS_LOW_PRIORITY);
    }
}

void particle_shooting_beam_down_left(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_339d84);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_shooting_beam_down_right(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_339d84);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= (PARTICLE_STATUS_XFLIP | PARTICLE_STATUS_LOW_PRIORITY);
    }
}

void particle_bomb(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_339dac);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            pParticle->status |= PARTICLE_STATUS_EXPLOSION;
            play_sound1(0xFF);
        }
    }
}

void particle_missile_trail(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_327060);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_super_missile_trail(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_3270a0);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_beam_trailing_right(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_339de4);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
        {
            pParticle->x_position++;
            pParticle->y_position += 0x4;
            return;
        }
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_beam_trailing_left(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_339de4);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
        {
            pParticle->x_position--;
            pParticle->y_position += 0x4;
            return;
        }
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_charged_long_beam_trailing(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_3284d8);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

void particle_charged_ice_beam_trailing(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_328f04);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

void particle_charged_wave_beam_trail(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_329eac);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

void particle_charged_plasma_beam_trail(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_32b008);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

void particle_charged_full_beam_trail(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_32b030);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

void particle_charged_pistol_trail(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_32b9c0);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

void particle_sprite_explosion_huge(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b634);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_sprite_explosion_small(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b784);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_sprite_explosion_medium(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b7e4);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_sprite_explosion_big(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b874);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_sprite_explosion_single_then_big(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b904);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_screw_attack_destroyed(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b98c);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_shinespark_destroyed(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b9d4);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_sudo_screw_destroyed(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33ba2c);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_speedbooster_destroyed(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33ba74);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_main_boss_death(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33bbc4);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_freezing_sprite_with_ice(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->status ^= PARTICLE_STATUS_NOT_DRAWN;
    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33babc);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_freezing_sprite_with_charged_ice(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->status ^= PARTICLE_STATUS_NOT_DRAWN;
    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33bb44);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

void particle_hitting_something_with_base_beam(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b48c);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            play_sound1(0x102);
        }
    }
}

void particle_hitting_something_with_long_beam(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b4b4);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            play_sound1(0x103);
        }
    }
}

void particle_hitting_something_with_ice_beam(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b4dc);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            play_sound1(0x104);
        }
    }
}

void particle_hitting_something_with_wave_beam(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b50c);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            play_sound1(0x105);
        }
    }
}

void particle_hitting_something_with_full_beam_no_plasma(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b50c);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            play_sound1(0x104);
        }
    }
}

void particle_hitting_something_with_plasma_beam(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b544);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            play_sound1(0x106);
        }
    }
}

void particle_hitting_something_with_full_beam(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b544);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            play_sound1(0x104);
        }
    }
}

void particle_hitting_something_invicible(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b584);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            play_sound1(0x107);
        }
    }
}

void particle_hitting_something_with_missile(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b5b4);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            play_sound1(0xF9)
            play_sound1(0xFA);
        }
    }
}

void particle_hitting_something_with_super_missile(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b5f4);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            play_sound1(0xFC);
            play_sound1(0xFD);
            screen_shake_start_horizontal(0xA, 0x81);
            screen_shake_start_vertical(0xA, 0x81);
        }
    }
}

void particle_small_dust(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b6a4);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

void particle_medium_dust(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b6dc);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

void particle_two_medium_dust(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b72c);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

void particle_second_small_dust(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b6a4);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_second_medium_dust(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b6dc);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_second_two_medium_dust(struct particle_effect* pParticle)
{
    u8 ended;

    pParticle->frame_counter++;
    ended = particle_update_animation(pParticle, particle_oam_33b72c);
    if (ended != 0x0)
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

void particle_play_begin_to_charge_sound(void)
{
    enum beam_bombs_flags bbf;

    bbf = equipment.beam_bombs_activation;

    if (equipment.beam_bombs_activation & BBF_ICE_BEAM)
    {
        if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
            play_sound1(0xE6);
        else
            play_sound1(0xE4);
    }
    else
    {
        if (equipment.beam_bombs_activation & BBF_PLASMA_BEAM)
        {
            if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
                play_sound1(0xE2);
            else
                play_sound1(0xE0);
        }
        else
        {
            if (equipment.beam_bombs_activation & BBF_WAVE_BEAM)
            {
                if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
                    play_sound1(0xDE);
                else
                    play_sound1(0xDC);
            }
            else
            {
                if (bbf & BBF_LONG_BEAM)
                    play_sound1(0xDA);
                else
                    play_sound1(0xD8);
            }
        }
    }
}

void particle_play_shooting_charged_beam_sound(void)
{
    enum beam_bombs_flags bbf;

    bbf = equipment.beam_bombs_activation;

    if (equipment.beam_bombs_activation & BBF_ICE_BEAM)
    {
        if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
            play_sound2(0xE6);
        else
            play_sound2(0xE4);
    }
    else
    {
        if (equipment.beam_bombs_activation & BBF_PLASMA_BEAM)
        {
            if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
                play_sound2(0xE2);
            else
                play_sound2(0xE0);
        }
        else
        {
            if (equipment.beam_bombs_activation & BBF_WAVE_BEAM)
            {
                if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
                    play_sound2(0xDE);
                else
                    play_sound2(0xDC);
            }
            else
            {
                if (bbf & BBF_LONG_BEAM)
                    play_sound2(0xDA);
                else
                    play_sound2(0xD8);
            }
        }
    }
}

void particle_play_beam_fully_charged_sound(void)
{
    enum beam_bombs_flags bbf;

    bbf = equipment.beam_bombs_activation;

    if (equipment.beam_bombs_activation & BBF_ICE_BEAM)
    {
        if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
            play_sound1(0xE7);
        else
            play_sound1(0xE5);
    }
    else
    {
        if (equipment.beam_bombs_activation & BBF_PLASMA_BEAM)
        {
            if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
                play_sound1(0xE3);
            else
                play_sound1(0xE1);
        }
        else
        {
            if (equipment.beam_bombs_activation & BBF_WAVE_BEAM)
            {
                if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
                    play_sound1(0xDF);
                else
                    play_sound1(0xDD);
            }
            else
            {
                if (bbf & BBF_LONG_BEAM)
                    play_sound1(0xDB);
                else
                    play_sound1(0xD9);
            }
        }
    }
}

void particle_charging_beam(struct particle_effect* pParticle)
{
    pParticle->y_position = arm_cannon_y;
    pParticle->x_position = arm_cannon_x;

    if (samus_weapon_info.charge_counter < 0x10)
    {
        pParticle->status = 0x0;
        particle_play_shooting_charged_beam_sound();
    }
    else
    {
        switch (samus_data.pose)
        {
            case SPOSE_SPINNING:
            case SPOSE_STARTING_WALL_JUMP:
            case SPOSE_SPACE_JUMPING:
            case SPOSE_SCREW_ATTACKING:
                pParticle->status |= PARTICLE_STATUS_NOT_DRAWN;
                break;

            default:
                pParticle->status &= ~PARTICLE_STATUS_NOT_DRAWN;
        }

        switch (pParticle->stage)
        {
            case 0x0:
                pParticle->status |= PARTICLE_STATUS_SPECIAL_EFFECT;
                pParticle->stage++;
                particle_update_animation(pParticle, particle_charging_beam_oam_339e14);
                particle_play_begin_to_charge_sound();
                break;

            case 0x1:
                if (prevent_movement_timer != 0x0)
                    particle_set_current_oam_frame_pointer(pParticle, particle_charging_beam_oam_339e14);
                else
                {
                    if (samus_weapon_info.charge_counter >= 0x40)
                    {
                        pParticle->stage = 0x2;
                        pParticle->curr_anim_frame = 0x0;
                        pParticle->anim_duration_counter = 0x0;
                        pParticle->frame_counter = 0x0;
                        particle_update_animation(pParticle, particle_charging_beam_oam_339ecc);
                    }
                    else
                        particle_update_animation(pParticle, particle_charging_beam_oam_339e14);
                }
                break;

            default:
                if (prevent_movement_timer != 0x0)
                    particle_set_current_oam_frame_pointer(pParticle, particle_charging_beam_oam_339ecc);
                else
                {
                    particle_update_animation(pParticle, particle_charging_beam_oam_339ecc);
                    if ((pParticle->frame_counter & 0xF) == 0x0)
                        particle_play_beam_fully_charged_sound();
                    pParticle->frame_counter++;
                    return;
                }
        }
    }
}

void particle_escape(struct particle_effect* pParticle)
{
    switch (pParticle->stage)
    {
        case 0x0:
            pParticle->stage = 0x1;
            pParticle->status |= (PARTICLE_STATUS_EXPLOSION | PARTICLE_STATUS_SPECIAL_EFFECT | PARTICLE_STATUS_ABSOLUTE_POSITION);
            escape_set_timer();
            current_escape_status = ESCAPE_STATUS_HAPPENNING;
            break;
        
        case 0x1:
            if (current_escape_status == ESCAPE_STATUS_FAILED)
            {
                prevent_movement_timer = 0x3E8;
                pParticle->stage = 0x3;
                pParticle->frame_counter = 0xFF;
                play_cutscene(0x2);
            }
            else if (current_escape_status == ESCAPE_STATUS_HAPPENNING && escape_check_has_escaped() << 0x18)
            {
                pParticle->stage = 0x2;
                pParticle->frame_counter = 0x20;
            }
            break;

        case 0x2:
            pParticle->y_position -= 0x2;
            pParticle->frame_counter--;
            if (pParticle->frame_counter == 0x0)
                pParticle->status = 0x0;
    }

    escape_update_oam();
    curr_particle_oam_frame_ptr = particle_escape_oam_frames;
}

void particle_samus_reflecion(struct particle_effect* pParticle)
{

}