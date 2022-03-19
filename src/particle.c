#include "particle.h"
#include "escape.h"
#include "screen_shake.h"
#include "music.h"
#include "../data/data.h"
#include "globals.h"

/**
 * 53dd0 | 98 | 
 * Checks if a particle effect is on screen
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_check_on_screen(struct ParticleEffect* pParticle)
{
    
}

/**
 * 53e68 | 170 | 
 * Draws a particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle 
 */
void particle_draw(struct ParticleEffect* pParticle)
{

}

/**
 * 53fd8 | 114 | Processes all the particle effects (calls subroutine and calls the draw function)
 * 
 */
void particle_process_all(void)
{
    /*struct ParticleEffect* pParticle;
    u8 status;

    if (game_mode_sub1 != 0x2 && (game_mode_sub1 == 0x1 || game_mode_sub1 == 0x3))
    {
        pParticle = particle_effects;
        while (pParticle < particle_effects + 16)
        {
            if (pParticle->status & PARTICLE_STATUS_EXISTS && pParticle->effect == PE_ESCAPE) // Probably a priority system
            {
                process_particle_functions_pointer[pParticle->effect](pParticle); // Call subroutine
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
                process_particle_functions_pointer[pParticle->effect](pParticle); // Call subroutine
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
                process_particle_functions_pointer[pParticle->effect](pParticle); // Call subroutine
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
    }*/
}

/**
 * 540ec | a0 | 
 * Sets a new particle with the given parameters
 * 
 * @param y_position Y Position
 * @param x_position X Position
 * @param effect Particle effect ID
 */
void particle_set(u16 y_position, u16 x_position, u8 effect)
{

}

/**
 * 5418c | 50 | 
 * Updates the animation of a particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 * @param pOam OAM Pointer to the concerned Frame Data
 * @return 1 if ended, 0 otherwise
 */
u8 particle_update_animation(struct ParticleEffect* pParticle, struct FrameData* pOam)
{
    u8 ended;
    u32 adc;

    ended = 0x0;
    adc = pParticle->anim_duration_counter + 0x1;
    pParticle->anim_duration_counter = adc;
    if ((u8)pOam[pParticle->curr_anim_frame].timer <= (u8)adc)
    {
        pParticle->anim_duration_counter = 0x0;
        pParticle->curr_anim_frame++;
        if ((u8)pOam[pParticle->curr_anim_frame].timer == 0x0)
        {
            pParticle->curr_anim_frame = 0x0;
            ended = 0x1;
        }
    }

    curr_particle_oam_frame_ptr = pOam[pParticle->curr_anim_frame].oam_frame_ptr;
    return ended;
}

/**
 * 541dc | 14 | 
 * Sets the current particle OAM Frame pointer depending on the parameters
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 * @param pOam OAM Pointer to the concerned Frame Data
 */
void particle_set_current_oam_frame_pointer(struct ParticleEffect* pParticle, struct FrameData* pOam)
{
    curr_particle_oam_frame_ptr = pOam[pParticle->curr_anim_frame].oam_frame_ptr;
}

/**
 * 541f0 | 44 | 
 * Subroutine for the sprite splash water small particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_sprite_splash_water_small(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_sprite_splash_water_small_oam))
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

/**
 * 54234 | 44 | 
 * Subroutine for the sprite splash water big particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_sprite_splash_water_big(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_sprite_splash_water_big_oam))
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

/**
 * 54278 | 44 | 
 * Subroutine for the sprite splash water huge particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_sprite_splash_water_huge(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_sprite_splash_water_huge_oam))
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

/**
 * 542bc | 44 | 
 * Subroutine for the sprite splash lava small particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_sprite_splash_lava_small(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_sprite_splash_lava_small_oam))
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

/**
 * 54300 | 44 | 
 * Subroutine for the sprite splash lava big particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_sprite_splash_lava_big(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_sprite_splash_lava_big_oam))
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

/**
 * 54344 | 44 | 
 * Subroutine for the sprite splash lava huge particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_sprite_splash_lava_huge(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_sprite_splash_lava_huge_oam))
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

/**
 * 54388 | 44 | 
 * Subroutine for the sprite splash acid small particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_sprite_splash_acid_small(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_sprite_splash_acid_small_oam))
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

/**
 * 54388 | 44 | 
 * Subroutine for the sprite splash acid big particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_sprite_splash_acid_big(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_sprite_splash_acid_big_oam))
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

/**
 * 54410 | 44 | 
 * Subroutine for the sprite splash acid huge particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_sprite_splash_acid_huge(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_sprite_splash_acid_huge_oam))
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

/**
 * 54454 | 38 | 
 * Subroutine for the shooting beam left particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_shooting_beam_left(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_shooting_beam_left_right_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 5448c | 38 | 
 * Subroutine for the shooting beam right particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_shooting_beam_right(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_shooting_beam_left_right_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= (PARTICLE_STATUS_XFLIP | PARTICLE_STATUS_LOW_PRIORITY);
    }
}

/**
 * 544c4 | 38 | 
 * Subroutine for the shooting beam diagonally up particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_shooting_beam_diag_up_left(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_shooting_beam_diagonally_up_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 544fc | 38 | 
 * Subroutine for the shooting beam diagonally down particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_shooting_beam_diag_up_right(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_shooting_beam_diagonally_up_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= (PARTICLE_STATUS_XFLIP | PARTICLE_STATUS_LOW_PRIORITY);
    }
}

/**
 * 54534 | 38 | 
 * Subroutine for the shooting beam diagonally left particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_shooting_beam_diag_down_left(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_shooting_beam_diagonally_down_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 5456c | 38 | 
 * Subroutine for the shooting beam diagonally right particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_shooting_beam_diag_down_right(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_shooting_beam_diagonally_down_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= (PARTICLE_STATUS_XFLIP | PARTICLE_STATUS_LOW_PRIORITY);
    }
}

/**
 * 545a4 | 38 | 
 * Subroutine for the shooting beam up left particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_shooting_beam_up_left(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_shooting_beam_up_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 545dc | 38 | 
 * Subroutine for the shooting beam up right particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_shooting_beam_up_right(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_shooting_beam_up_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= (PARTICLE_STATUS_XFLIP | PARTICLE_STATUS_LOW_PRIORITY);
    }
}

/**
 * 54614 | 38 | 
 * Subroutine for the shooting beam down left particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_shooting_beam_down_left(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_shooting_beam_down_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 5464c | 38 | 
 * Subroutine for the shooting beam down right particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_shooting_beam_down_right(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_shooting_beam_down_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= (PARTICLE_STATUS_XFLIP | PARTICLE_STATUS_LOW_PRIORITY);
    }
}

/**
 * 54684 | 44 | 
 * Subroutine for the bomb particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_bomb(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_bomb_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            pParticle->status |= PARTICLE_STATUS_EXPLOSION;
            sound_play1(0xFF);
        }
    }
}

/**
 * 546c8 | 38 | 
 * Subroutine for the missile trail particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_missile_trail(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_missile_trail_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54700 | 38 | 
 * Subroutine for the super missile trail particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_super_missile_trail(struct ParticleEffect* pParticle)
{    
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_super_missile_trail_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54738 | 48 | 
 * Subroutine for the beam trailing right particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_beam_trailing_right(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_beam_trailing_oam))
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

/**
 * 54780 | 48 | 
 * Subroutine for the beam trailing left particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_beam_trailing_left(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_beam_trailing_oam))
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

/**
 * 547c8 | 34 | 
 * Subroutine for the charged long beam trailing particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_charged_long_beam_trailing(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_charged_long_beam_trail_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

/**
 * 547fc | 34 | 
 * Subroutine for the charged ice beam trailing particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_charged_ice_beam_trailing(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_charged_ice_beam_trail_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

/**
 * 54830 | 34 | 
 * Subroutine for the charged wave beam trailing particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_charged_wave_beam_trail(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_charged_wave_beam_trail_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

/**
 * 54864 | 34 | 
 * Subroutine for the charged plasma beam trailing particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_charged_plasma_beam_trail(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_charged_plasma_beam_trail_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

/**
 * 54898 | 34 | 
 * Subroutine for the charged full beam beam trailing particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_charged_full_beam_trail(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_charged_full_beam_trail_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

/**
 * 548cc | 34 | 
 * Subroutine for the charged pistol trailing particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_charged_pistol_trail(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_charged_pistol_trail_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

/**
 * 54900 | 34 | 
 * Subroutine for the sprite explosion huge particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_sprite_explosion_huge(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_sprite_explosion_huge_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54938 | 34 | 
 * Subroutine for the sprite explosion small particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_sprite_explosion_small(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_sprite_explosion_small_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54970 | 34 | 
 * Subroutine for the sprite explosion medium particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_sprite_explosion_medium(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_sprite_explosion_medium_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 549a8 | 34 | 
 * Subroutine for the sprite explosion big particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_sprite_explosion_big(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_sprite_explosion_big_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 549e0 | 34 | 
 * Subroutine for the sprite explosion single then big particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_sprite_explosion_single_then_big(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_sprite_explosion_single_then_big_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54a18 | 38 | 
 * Subroutine for the screw attack destroyed particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_screw_attack_destroyed(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_screw_attack_destroyed_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54a50 | 38 | 
 * Subroutine for the shinespark destroyed particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_shinespark_destroyed(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_shinespark_destroyed_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54a88 | 38 | 
 * Subroutine for the sudo attack destroyed particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_sudo_screw_destroyed(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_sudo_screw_destroyed_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54ac0 | 38 | 
 * Subroutine for the speedbooster destroyed particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_speedbooster_destroyed(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_speedbooster_destroyed_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54af8 | 38 | 
 * Subroutine for the main boss death particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_main_boss_death(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_main_boss_death_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54b30 | 40 | 
 * Subroutine for the freezing sprite with ice particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_freezing_sprite_with_ice(struct ParticleEffect* pParticle)
{
    pParticle->status ^= PARTICLE_STATUS_NOT_DRAWN;
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_freezing_sprite_with_ice_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54b70 | 40 | 
 * Subroutine for the freezing sprite with charged ice particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_freezing_sprite_with_charged_ice(struct ParticleEffect* pParticle)
{
    pParticle->status ^= PARTICLE_STATUS_NOT_DRAWN;
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_freezing_sprite_with_charged_ice_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54bb0 | 3c | 
 * Subroutine for the hitting something with base beam particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_hitting_something_with_base_beam(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_hitting_something_with_base_beam_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            sound_play1(0x102);
        }
    }
}

/**
 * 54bec | 40 | 
 * Subroutine for the hitting something with long beam particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_hitting_something_with_long_beam(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_hitting_something_with_long_beam_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            sound_play1(0x103);
        }
    }
}

/**
 * 54c2c | 3c | 
 * Subroutine for the hitting something with ice beam particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_hitting_something_with_ice_beam(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_hitting_something_with_ice_beam_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            sound_play1(0x104);
        }
    }
}

/**
 * 54c68 | 40 | 
 * Subroutine for the hitting something with wave beam particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_hitting_something_with_wave_beam(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            sound_play1(0x105);
        }
    }
}

/**
 * 54ca8 | 3c | 
 * Subroutine for the hitting something with full beam no plasma particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_hitting_something_with_full_beam_no_plasma(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            sound_play1(0x104);
        }
    }
}

/**
 * 54ce4 | 3c | 
 * Subroutine for the hitting something with plasma beam particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_hitting_something_with_plasma_beam(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_hitting_something_with_plasma_beam_full_beam_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            sound_play1(0x106);
        }
    }
}

/**
 * 54d20 | 3c | 
 * Subroutine for the hitting something with full beam particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_hitting_something_with_full_beam(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_hitting_something_with_plasma_beam_full_beam_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            sound_play1(0x104);
        }
    }
}

/**
 * 54d5c | 40 | 
 * Subroutine for the hitting something invincible particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_hitting_something_invicible(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_hitting_something_invincible_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            sound_play1(0x107);
        }
    }
}

/**
 * 54d9c | 40 | 
 * Subroutine for the hitting something with missile particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_hitting_something_with_missile(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_hitting_something_with_missile_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            sound_play1(0xF9);
            sound_play1(0xFA);
        }
    }
}

/**
 * 54ddc | 50 | 
 * Subroutine for the hitting something with super missile particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_hitting_something_with_super_missile(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_hitting_something_with_super_missile_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            sound_play1(0xFC);
            sound_play1(0xFD);
            screen_shake_start_horizontal(0xA, 0x81);
            screen_shake_start_vertical(0xA, 0x81);
        }
    }
}

/**
 * 54e2c | 34 | 
 * Subroutine for the small dust particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_small_dust(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_small_dust_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

/**
 * 54e60 | 34 | 
 * Subroutine for the medium dust particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_medium_dust(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_medium_dust_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

/**
 * 54e94 | 34 | 
 * Subroutine for the two medium dust particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_two_medium_dust(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_two_medium_dust_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
            pParticle->stage++;
    }
}

/**
 * 54e94 | 38 | 
 * Subroutine for the second small dust particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_second_small_dust(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_small_dust_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54e94 | 38 | 
 * Subroutine for the second medium dust particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_second_medium_dust(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_medium_dust_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54f00 | 38 | 
 * Subroutine for the second two medium dust particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_second_two_medium_dust(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (particle_update_animation(pParticle, particle_two_medium_dust_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
            return;
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54f70 | 88 | Plays a sound depending on the beams activated when beginning to charge a beam
 * 
 */
void particle_play_begin_to_charge_sound(void)
{
    u16 bbf;

    bbf = equipment.beam_bombs_activation;

    if (equipment.beam_bombs_activation & BBF_ICE_BEAM)
    {
        if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
            sound_play1(0xE6);
        else
            sound_play1(0xE4);
    }
    else
    {
        if (equipment.beam_bombs_activation & BBF_PLASMA_BEAM)
        {
            if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
                sound_play1(0xE2);
            else
                sound_play1(0xE0);
        }
        else
        {
            if (equipment.beam_bombs_activation & BBF_WAVE_BEAM)
            {
                if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
                    sound_play1(0xDE);
                else
                    sound_play1(0xDC);
            }
            else
            {
                if (bbf & BBF_LONG_BEAM)
                    sound_play1(0xDA);
                else
                    sound_play1(0xD8);
            }
        }
    }
}

/**
 * 54ff8 | 88 | Plays a sound depending on the beams activated when shooting a charged beam
 * 
 */
void particle_play_shooting_charged_beam_sound(void)
{
    u16 bbf;

    bbf = equipment.beam_bombs_activation;

    if (equipment.beam_bombs_activation & BBF_ICE_BEAM)
    {
        if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
            sound_play2(0xE6);
        else
            sound_play2(0xE4);
    }
    else
    {
        if (equipment.beam_bombs_activation & BBF_PLASMA_BEAM)
        {
            if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
                sound_play2(0xE2);
            else
                sound_play2(0xE0);
        }
        else
        {
            if (equipment.beam_bombs_activation & BBF_WAVE_BEAM)
            {
                if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
                    sound_play2(0xDE);
                else
                    sound_play2(0xDC);
            }
            else
            {
                if (bbf & BBF_LONG_BEAM)
                    sound_play2(0xDA);
                else
                    sound_play2(0xD8);
            }
        }
    }
}

/**
 * 55080 | 88 | Plays a sound depending on the beams activated when charging a fully charged beam
 * 
 */
void particle_play_beam_fully_charged_sound(void)
{
    u16 bbf;

    bbf = equipment.beam_bombs_activation;

    if (equipment.beam_bombs_activation & BBF_ICE_BEAM)
    {
        if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
            sound_play1(0xE7);
        else
            sound_play1(0xE5);
    }
    else
    {
        if (equipment.beam_bombs_activation & BBF_PLASMA_BEAM)
        {
            if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
                sound_play1(0xE3);
            else
                sound_play1(0xE1);
        }
        else
        {
            if (equipment.beam_bombs_activation & BBF_WAVE_BEAM)
            {
                if (equipment.beam_bombs_activation & BBF_LONG_BEAM)
                    sound_play1(0xDF);
                else
                    sound_play1(0xDD);
            }
            else
            {
                if (bbf & BBF_LONG_BEAM)
                    sound_play1(0xDB);
                else
                    sound_play1(0xD9);
            }
        }
    }
}

/**
 * 55108 | 100 | 
 * Subroutine for the charging beam particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_charging_beam(struct ParticleEffect* pParticle)
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
                particle_update_animation(pParticle, particle_charging_beam_oam_begin);
                particle_play_begin_to_charge_sound();
                break;

            case 0x1:
                if (prevent_movement_timer != 0x0)
                    particle_set_current_oam_frame_pointer(pParticle, particle_charging_beam_oam_begin);
                else
                {
                    if (samus_weapon_info.charge_counter >= 0x40)
                    {
                        pParticle->stage = 0x2;
                        pParticle->curr_anim_frame = 0x0;
                        pParticle->anim_duration_counter = 0x0;
                        pParticle->frame_counter = 0x0;
                        particle_update_animation(pParticle, particle_charging_beam_oam_charged);
                    }
                    else
                        particle_update_animation(pParticle, particle_charging_beam_oam_begin);
                }
                break;

            default:
                if (prevent_movement_timer != 0x0)
                    particle_set_current_oam_frame_pointer(pParticle, particle_charging_beam_oam_charged);
                else
                {
                    particle_update_animation(pParticle, particle_charging_beam_oam_charged);
                    if ((pParticle->frame_counter & 0xF) == 0x0)
                        particle_play_beam_fully_charged_sound();
                    pParticle->frame_counter++;
                    return;
                }
        }
    }
}

/**
 * 55208 | a8 | 
 * Subroutine for the escape particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_escape(struct ParticleEffect* pParticle)
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

/**
 * 55208 | a8 | 
 * Subroutine for the samus reflection particle effect /!\ NO CODE
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void particle_samus_reflection(struct ParticleEffect* pParticle)
{

}