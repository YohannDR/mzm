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
void ParticleCheckOnScreen(struct ParticleEffect* pParticle)
{
    /*u16 bgY_offset;
    u16 y_offset;
    u16 bgX_offset;
    u16 x_offset;

    if (pParticle->status & PARTICLE_STATUS_ABSOLUTE_POSITION)
        pParticle->status |= PARTICLE_STATUS_ONSCREEN;
    else
    {
        bgY_offset = gBG1YPosition + 0x200;
        y_offset = pParticle->y_position + 0x200;
        bgX_offset = gBG1XPosition + 0x200;
        x_offset = pParticle->x_position + 0x200;

        if (x_offset >= bgX_offset && bgX_offset >= x_offset && y_offset >= bgY_offset && bgY_offset >= y_offset)
            pParticle->status |= PARTICLE_STATUS_ONSCREEN;
        else
        {
            if (pParticle->status & PARTICLE_STATUS_SPECIAL_EFFECT)
                pParticle->status &= ~PARTICLE_STATUS_ONSCREEN;
            else
                pParticle->status |= PARTICLE_STATUS_ONSCREEN;
        }
    }*/
}
/**
 * 53e68 | 170 | 
 * Draws a particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle 
 */
void ParticleDraw(struct ParticleEffect* pParticle)
{
    u16 part_count;
    u16* pSrc;
    struct RawOamData* pDst;
    u8 slot;
    u16 y_position;
    u16 x_position;
    u8 status;
    u8 priority;

    slot = gNextOAMSlot;
    pSrc = gCurrentParticleEffectOAMFramePointer;
    part_count = *pSrc++;
    if (part_count + slot < 0x80) // Checks within bounds
    {
        pDst = oam_data + slot;
        status = pParticle->status;
        if (status & PARTICLE_STATUS_ABSOLUTE_POSITION)
        {
            y_position = pParticle->y_position;
            x_position = pParticle->x_position;
        }
        else
        {
            y_position = (pParticle->y_position >> 0x2) - (gBG1YPosition >> 0x2);
            x_position = (pParticle->x_position >> 0x2) - (gBG1XPosition >> 0x2);
        }

        if (status & PARTICLE_STATUS_LOW_PRIORITY)
        {
            if (gSamusOnTopOfBackgrounds)
                priority = 0x1;
            else
                priority = 0x2;
        }
        else
            priority = 0x0;

        status &= PARTICLE_STATUS_XFLIP;

        do {
            // pDst->data->valueU = *pSrc++;


        } while (part_count != 0x0);
    }
}

/**
 * 53fd8 | 114 | Processes all the particle effects (calls subroutine and calls the draw function)
 * 
 */
void ParticleProcessAll(void)
{
    /*struct ParticleEffect* pParticle;
    u8 status;

    if (gGameModeSub1 != 0x2 && (gGameModeSub1 == 0x1 || gGameModeSub1 == 0x3))
    {
        pParticle = pParticleEffects;
        while (pParticle < pParticleEffects + 16)
        {
            if (pParticle->status & PARTICLE_STATUS_EXISTS && pParticle->effect == PE_ESCAPE) // Probably a priority system
            {
                process_particle_functions_pointer[pParticle->effect](pParticle); // Call subroutine
                if ((pParticle->status & PARTICLE_STATUS_EXISTS) != 0x0)
                    ParticleDraw(pParticle);
            } 
            pParticle++;
        }
    }
    else
    {
        pParticle = pParticleEffects;
        while (pParticle < pParticleEffects + 16)
        {
            if ((pParticle->status & (PARTICLE_STATUS_EXISTS | PARTICLE_STATUS_EXPLOSION)) == (PARTICLE_STATUS_EXISTS | PARTICLE_STATUS_EXPLOSION))
            {
                process_particle_functions_pointer[pParticle->effect](pParticle); // Call subroutine
                if ((pParticle->status & PARTICLE_STATUS_EXISTS) != 0x0)
                {
                    ParticleCheckOnScreen(pParticle);
                    status = (pParticle->status & (PARTICLE_STATUS_ONSCREEN | PARTICLE_STATUS_NOT_DRAWN));
                    if (status == PARTICLE_STATUS_ONSCREEN)
                        ParticleDraw(pParticle);
                }
            }
            pParticle++;
        }
                
        pParticle = pParticleEffects;
         while (pParticle < pParticleEffects + 16)
        {
            if ((pParticle->status & (PARTICLE_STATUS_EXISTS | PARTICLE_STATUS_EXPLOSION)) == PARTICLE_STATUS_EXISTS)
            {
                process_particle_functions_pointer[pParticle->effect](pParticle); // Call subroutine
                if (pParticle->status & PARTICLE_STATUS_EXISTS)
                {
                    ParticleCheckOnScreen(pParticle);
                    status = (pParticle->status & (PARTICLE_STATUS_ONSCREEN | PARTICLE_STATUS_NOT_DRAWN));
                    if (status == PARTICLE_STATUS_ONSCREEN)
                        ParticleDraw(pParticle);
                }
            }
            pParticle++;
        }
        EscaepUpdateTimer();
    }*/
}

/**
 * 540ec | a0 | 
 * Sets a new particle effect with the given parameters
 * 
 * @param y_position Y Position
 * @param x_position X Position
 * @param effect Particle effect ID
 */
void ParticleSet(u16 y_position, u16 x_position, u8 effect)
{
    struct ParticleEffect* pParticle;
    struct ParticleEffect* pLow;
    u8 counter;
    u8 counter_d;
    u8 count;

    counter = FALSE;
    for (pParticle = pParticleEffects; pParticle < pParticleEffects + 16; pParticle++)
    {
        if (!pParticle->status)
        {
            counter = TRUE;
            break;
        }
    }

    if (!counter)
    {
        count = 0x0;
        for (pParticle = pLow = pParticleEffects; pParticle < pParticleEffects + 16; pParticle++)
        {
            if (pParticle->effect < PE_CHARGING_BEAM)
                counter_d = pParticle->frame_counter;
            else
                counter_d = 0x0;
            if (counter < counter_d)
            {
                counter = counter_d;
                pLow = pParticle;
                count++;
            }
        }
        if (count == 0x0)
            return;
        else
            pParticle = pLow;
    }

    pParticle->status = PARTICLE_STATUS_EXISTS;
    pParticle->y_position = y_position;
    pParticle->x_position = x_position;
    pParticle->curr_anim_frame = 0x0;
    pParticle->anim_duration_counter = 0x0;
    pParticle->effect = effect;
    pParticle->stage = 0x0;
    pParticle->frame_counter = 0x0;
}

/**
 * 5418c | 50 | 
 * Updates the animation of a particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 * @param pOam OAM Pointer to the concerned Frame Data
 * @return 1 if ended, 0 otherwise
 */
u8 ParticleUpdateAnimation(struct ParticleEffect* pParticle, struct FrameData* pOam)
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

    gCurrentParticleEffectOAMFramePointer = pOam[pParticle->curr_anim_frame].oam_frame_ptr;
    return ended;
}

/**
 * 541dc | 14 | 
 * Sets the current particle OAM Frame pointer depending on the parameters
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 * @param pOam OAM Pointer to the concerned Frame Data
 */
void ParticleSetCurrentOAMFramePointer(struct ParticleEffect* pParticle, struct FrameData* pOam)
{
    gCurrentParticleEffectOAMFramePointer = pOam[pParticle->curr_anim_frame].oam_frame_ptr;
}

/**
 * 541f0 | 44 | 
 * Subroutine for the sprite splash water small particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void ParticleSpriteSplashSmall(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_water_small_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = gEffectYPosition;
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
void ParticleSpriteSplashWaterBig(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_water_big_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = gEffectYPosition;
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
void ParticleSpriteSplashWaterHuge(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_water_huge_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = gEffectYPosition;
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
void ParticleSpriteSplashLavaSmall(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_lava_small_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = gEffectYPosition;
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
void ParticleSpriteSplashLavaBig(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_lava_big_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = gEffectYPosition;
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
void ParticleSpriteSplashLavaHuge(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_lava_huge_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = gEffectYPosition;
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
void ParticleSpriteSplashAcidSmall(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_acid_small_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = gEffectYPosition;
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
void ParticleSpriteSplashAcidBig(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_acid_big_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = gEffectYPosition;
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
void ParticleSpriteSplashAcidHuge(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_acid_huge_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->y_position = gEffectYPosition;
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
void ParticleShootingBeamLeft(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_shooting_beam_left_right_oam))
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
void ParticleShootingBeamRight(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_shooting_beam_left_right_oam))
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
void ParticleShootingBeamDiagUpLeft(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_shooting_beam_diagonally_up_oam))
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
void ParticleShootingBeamDiagUpRight(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_shooting_beam_diagonally_up_oam))
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
void ParticleShootingBeamDiagDownLeft(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_shooting_beam_diagonally_down_oam))
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
void ParticleShootingBeamDiagDownRight(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_shooting_beam_diagonally_down_oam))
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
void ParticleShootingBeamDownLeft(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_shooting_beam_up_oam))
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
void ParticleShootingBeamDownRight(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_shooting_beam_up_oam))
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
void ParticleShootingBeamDownLeft(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_shooting_beam_down_oam))
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
void ParticleShootingBeamDownRight(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_shooting_beam_down_oam))
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
void ParticleBomb(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_bomb_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            pParticle->status |= PARTICLE_STATUS_EXPLOSION;
            SoundPlay(0xFF);
        }
    }
}

/**
 * 546c8 | 38 | 
 * Subroutine for the missile trail particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void ParticleMissileTrail(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_missile_trail_oam))
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
void ParticleSuperMissileTrail(struct ParticleEffect* pParticle)
{    
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_super_missile_trail_oam))
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
void ParticleBeamTrailingRight(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_beam_trailing_oam))
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
void ParticleBeamTrailingLeft(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_beam_trailing_oam))
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
void ParticleChargedLongBeamTrail(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_charged_long_beam_trail_oam))
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
void ParticleChargedIceBeamTrail(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_charged_ice_beam_trail_oam))
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
void ParticleChargedWaveBeamTrail(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_charged_wave_beam_trail_oam))
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
void ParticleChargedPlasmaBeamTrail(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_charged_plasma_beam_trail_oam))
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
void ParticleChargedFullBeamTrail(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_charged_full_beam_trail_oam))
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
void ParticleChargedPistolTrail(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_charged_pistol_trail_oam))
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
void ParticleSpriteExplosionHuge(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_explosion_huge_oam))
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
void ParticleSpriteExplosionSmall(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_explosion_small_oam))
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
void ParticleSpriteExplosionMedium(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_explosion_medium_oam))
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
void ParticleSpriteExplosionBig(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_explosion_big_oam))
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
void ParticleSpriteExplosionSingleThenBig(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_explosion_single_then_big_oam))
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
void ParticleScrewAttackDestroyed(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_screw_attack_destroyed_oam))
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
void ParticleShinesparkDestroyed(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_shinespark_destroyed_oam))
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
void ParticleSudoScrewDestroyed(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_sudo_screw_destroyed_oam))
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
void ParticleSpeedboosterDestroyed(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_speedbooster_destroyed_oam))
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
void ParticleMainBossDeath(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_main_boss_death_oam))
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
void ParticleFreezingSpriteWithIce(struct ParticleEffect* pParticle)
{
    pParticle->status ^= PARTICLE_STATUS_NOT_DRAWN;
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_freezing_sprite_with_ice_oam))
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
void ParticleFreezingSpriteWithChargedIce(struct ParticleEffect* pParticle)
{
    pParticle->status ^= PARTICLE_STATUS_NOT_DRAWN;
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_freezing_sprite_with_charged_ice_oam))
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
void ParticleHittingSomethingWithBaseBeam(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_hitting_something_with_base_beam_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            SoundPlay(0x102);
        }
    }
}

/**
 * 54bec | 40 | 
 * Subroutine for the hitting something with long beam particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void ParticleHittingSomethingWithLongBeam(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_hitting_something_with_long_beam_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            SoundPlay(0x103);
        }
    }
}

/**
 * 54c2c | 3c | 
 * Subroutine for the hitting something with ice beam particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void ParticleHittingSomethingWithIceBeam(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_hitting_something_with_ice_beam_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            SoundPlay(0x104);
        }
    }
}

/**
 * 54c68 | 40 | 
 * Subroutine for the hitting something with wave beam particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void ParticleHittingSomethingWithWaveBeam(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            SoundPlay(0x105);
        }
    }
}

/**
 * 54ca8 | 3c | 
 * Subroutine for the hitting something with full beam no plasma particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void ParticleHittingSomethingWithFullBeamNoPlasma(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_hitting_something_with_wave_beam_full_beam_no_plasma_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            SoundPlay(0x104);
        }
    }
}

/**
 * 54ce4 | 3c | 
 * Subroutine for the hitting something with plasma beam particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void ParticleHittingSomethingWithPlasmaBeam(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_hitting_something_with_plasma_beam_full_beam_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            SoundPlay(0x106);
        }
    }
}

/**
 * 54d20 | 3c | 
 * Subroutine for the hitting something with full beam particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void ParticleHittingSomethingWithFullBeam(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_hitting_something_with_plasma_beam_full_beam_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            SoundPlay(0x104);
        }
    }
}

/**
 * 54d5c | 40 | 
 * Subroutine for the hitting something invincible particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void ParticleHittingSomethingInvincible(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_hitting_something_invincible_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            SoundPlay(0x107);
        }
    }
}

/**
 * 54d9c | 40 | 
 * Subroutine for the hitting something with missile particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void ParticleHittingSomethingWithMissile(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_hitting_something_with_missile_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            SoundPlay(0xF9);
            SoundPlay(0xFA);
        }
    }
}

/**
 * 54ddc | 50 | 
 * Subroutine for the hitting something with super missile particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void ParticleHittingSomethingWithSuperMissile(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_hitting_something_with_super_missile_oam))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            SoundPlay(0xFC);
            SoundPlay(0xFD);
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
void ParticleSmallDust(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_small_dust_oam))
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
void ParticleMediumDust(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_medium_dust_oam))
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
void ParticleTwoMediumDust(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_two_medium_dust_oam))
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
void ParticleSecondSmallDust(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_small_dust_oam))
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
void ParticleSecondMediumDust(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_medium_dust_oam))
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
void ParticleSecondTwoMediumDust(struct ParticleEffect* pParticle)
{
    pParticle->frame_counter++;
    if (ParticleUpdateAnimation(pParticle, particle_two_medium_dust_oam))
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
void ParticlePlayBeginToChargeSound(void)
{
    u16 bbf;

    bbf = gEquipment.beam_bombs_activation;

    if (gEquipment.beam_bombs_activation & BBF_ICE_BEAM)
    {
        if (gEquipment.beam_bombs_activation & BBF_LONG_BEAM)
            SoundPlay(0xE6);
        else
            SoundPlay(0xE4);
    }
    else
    {
        if (gEquipment.beam_bombs_activation & BBF_PLASMA_BEAM)
        {
            if (gEquipment.beam_bombs_activation & BBF_LONG_BEAM)
                SoundPlay(0xE2);
            else
                SoundPlay(0xE0);
        }
        else
        {
            if (gEquipment.beam_bombs_activation & BBF_WAVE_BEAM)
            {
                if (gEquipment.beam_bombs_activation & BBF_LONG_BEAM)
                    SoundPlay(0xDE);
                else
                    SoundPlay(0xDC);
            }
            else
            {
                if (bbf & BBF_LONG_BEAM)
                    SoundPlay(0xDA);
                else
                    SoundPlay(0xD8);
            }
        }
    }
}

/**
 * 54ff8 | 88 | Plays a sound depending on the beams activated when shooting a charged beam
 * 
 */
void ParticleStopBeginToChargeSound(void)
{
    u16 bbf;

    bbf = gEquipment.beam_bombs_activation;

    if (gEquipment.beam_bombs_activation & BBF_ICE_BEAM)
    {
        if (gEquipment.beam_bombs_activation & BBF_LONG_BEAM)
            SoundStop(0xE6);
        else
            SoundStop(0xE4);
    }
    else
    {
        if (gEquipment.beam_bombs_activation & BBF_PLASMA_BEAM)
        {
            if (gEquipment.beam_bombs_activation & BBF_LONG_BEAM)
                SoundStop(0xE2);
            else
                SoundStop(0xE0);
        }
        else
        {
            if (gEquipment.beam_bombs_activation & BBF_WAVE_BEAM)
            {
                if (gEquipment.beam_bombs_activation & BBF_LONG_BEAM)
                    SoundStop(0xDE);
                else
                    SoundStop(0xDC);
            }
            else
            {
                if (bbf & BBF_LONG_BEAM)
                    SoundStop(0xDA);
                else
                    SoundStop(0xD8);
            }
        }
    }
}

/**
 * 55080 | 88 | Plays a sound depending on the beams activated when charging a fully charged beam
 * 
 */
void ParticlePlayBeamFullChargedSound(void)
{
    u16 bbf;

    bbf = gEquipment.beam_bombs_activation;

    if (gEquipment.beam_bombs_activation & BBF_ICE_BEAM)
    {
        if (gEquipment.beam_bombs_activation & BBF_LONG_BEAM)
            SoundPlay(0xE7);
        else
            SoundPlay(0xE5);
    }
    else
    {
        if (gEquipment.beam_bombs_activation & BBF_PLASMA_BEAM)
        {
            if (gEquipment.beam_bombs_activation & BBF_LONG_BEAM)
                SoundPlay(0xE3);
            else
                SoundPlay(0xE1);
        }
        else
        {
            if (gEquipment.beam_bombs_activation & BBF_WAVE_BEAM)
            {
                if (gEquipment.beam_bombs_activation & BBF_LONG_BEAM)
                    SoundPlay(0xDF);
                else
                    SoundPlay(0xDD);
            }
            else
            {
                if (bbf & BBF_LONG_BEAM)
                    SoundPlay(0xDB);
                else
                    SoundPlay(0xD9);
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
void ParticleChargingBeam(struct ParticleEffect* pParticle)
{
    pParticle->y_position = gArmCannonY;
    pParticle->x_position = gArmCannonX;

    if (gSamusWeaponInfo.charge_counter < 0x10)
    {
        pParticle->status = 0x0;
        ParticleStopBeginToChargeSound();
    }
    else
    {
        switch (gSamusData.pose)
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
                ParticleUpdateAnimation(pParticle, particle_charging_beam_oam_begin);
                ParticlePlayBeginToChargeSound();
                break;

            case 0x1:
                if (gPreventMovementTimer != 0x0)
                    ParticleSetCurrentOAMFramePointer(pParticle, particle_charging_beam_oam_begin);
                else
                {
                    if (gSamusWeaponInfo.charge_counter >= 0x40)
                    {
                        pParticle->stage = 0x2;
                        pParticle->curr_anim_frame = 0x0;
                        pParticle->anim_duration_counter = 0x0;
                        pParticle->frame_counter = 0x0;
                        ParticleUpdateAnimation(pParticle, particle_charging_beam_oam_charged);
                    }
                    else
                        ParticleUpdateAnimation(pParticle, particle_charging_beam_oam_begin);
                }
                break;

            default:
                if (gPreventMovementTimer != 0x0)
                    ParticleSetCurrentOAMFramePointer(pParticle, particle_charging_beam_oam_charged);
                else
                {
                    ParticleUpdateAnimation(pParticle, particle_charging_beam_oam_charged);
                    if ((pParticle->frame_counter & 0xF) == 0x0)
                        ParticlePlayBeamFullChargedSound();
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
void ParticleEscape(struct ParticleEffect* pParticle)
{
    switch (pParticle->stage)
    {
        case 0x0:
            pParticle->stage = 0x1;
            pParticle->status |= (PARTICLE_STATUS_EXPLOSION | PARTICLE_STATUS_SPECIAL_EFFECT | PARTICLE_STATUS_ABSOLUTE_POSITION);
            EscapeSetTimer();
            gCurrentEscapeStatus = ESCAPE_STATUS_HAPPENNING;
            break;
        
        case 0x1:
            if (gCurrentEscapeStatus == ESCAPE_STATUS_FAILED)
            {
                gPreventMovementTimer = 0x3E8;
                pParticle->stage = 0x3;
                pParticle->frame_counter = 0xFF;
                play_cutscene(0x2);
            }
            else if (gCurrentEscapeStatus == ESCAPE_STATUS_HAPPENNING && EscapeCheckHasEscaped() << 0x18)
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

    EscapeUpdateOAM();
    gCurrentParticleEffectOAMFramePointer = gParticleEscapeOAMFrames;
}

/**
 * 552b0 | a8 | 
 * Subroutine for the samus reflection particle effect
 * 
 * @param pParticle Particle Effect Pointer to the concerned particle
 */
void ParticleSamusReflection(struct ParticleEffect* pParticle)
{
    u16 part_count;
    u16 count;
    u16* pSrc;
    u16* pDst;

    if (pParticle->stage == 0x0)
    {
        pParticle->stage = 0x1;
        pParticle->status |= (PARTICLE_STATUS_SPECIAL_EFFECT | PARTICLE_STATUS_LOW_PRIORITY | PARTICLE_STATUS_XFLIP); // Init status
    }

    pSrc = (u16*)gSamusPhysics.body_oam;
    part_count = *pSrc++;
    pDst = gParticleSamusReflectionOAMFrames;
    if (part_count > 0x18) // Check within bounds
        part_count = 0x18;
    *pDst++ = part_count;

    part_count *= 0x3; // Correct number for the loop
    count = 0x0;

    while (count < part_count)
    {
        *pDst++ = *pSrc++; // Copy
        count++;
    }

    gCurrentParticleEffectOAMFramePointer = gParticleSamusReflectionOAMFrames; // Set for draw

    pParticle->y_position = gSubSpriteData1.y_position + 0x5C;
    pParticle->x_position = gSubSpriteData1.x_position;

    if (gSubSpriteData1.maybe_status == 0x0) // Probably checks for shootable symbol state
        pParticle->status &= ~PARTICLE_STATUS_NOT_DRAWN;
    else
    {
        pParticle->status |= PARTICLE_STATUS_NOT_DRAWN;
        if (gSubSpriteData1.unknown == 0x1)
            pParticle->status = 0x0;
    }
}