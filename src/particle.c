#include "particle.h"
#include "escape.h"
#include "screen_shake.h"
#include "music.h"
#include "data/data.h"
#include "data/pointers.c"
#include "data/projectile_data.c"
#include "data/particle_data.c"
#include "globals.h"

/**
 * 53dd0 | 98 | 
 * Checks if a particle effect is on screen
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleCheckOnScreen(struct ParticleEffect* pParticle)
{
    /*u16 bgY_offset;
    u16 yOffset;
    u16 bgX_offset;
    u16 xOffset;

    if (pParticle->status & PARTICLE_STATUS_ABSOLUTE_POSITION)
        pParticle->status |= PARTICLE_STATUS_ONSCREEN;
    else
    {
        bgY_offset = gBG1YPosition + 0x200;
        yOffset = pParticle->yPosition + 0x200;
        bgX_offset = gBG1XPosition + 0x200;
        xOffset = pParticle->xPosition + 0x200;

        if (x_offset >= bgX_offset && bgX_offset >= xOffset && yOffset >= bgY_offset && bgY_offset >= yOffset)
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
 * 53e68 | 170 | Draws a particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleDraw(struct ParticleEffect* pParticle)
{
    // https://decomp.me/scratch/rmhDY

    u8 prevSlot;
    u32 partCount;
    const u16* src;
    u16* dst;
    u16 yPosition;
    u16 xPosition;
    u16 bgPriority;
    u16 part;
    union OamData* pUnion;

    prevSlot = gNextOAMSlot;
    src = gCurrentParticleEffectOAMFramePointer;

    partCount = *src++;

    if (partCount + prevSlot < 0x80)
    {
        dst = (u16*)(gOamData + prevSlot);

        if (pParticle->status & PARTICLE_STATUS_ABSOLUTE_POSITION)
        {
            yPosition = pParticle->yPosition;
            xPosition = pParticle->xPosition;
        }
        else
        {
            yPosition = (pParticle->yPosition / 4) - gBG1YPosition / 4;
            xPosition = (pParticle->xPosition / 4) - gBG1XPosition / 4;
        }

        if (pParticle->status & PARTICLE_STATUS_LOW_PRIORITY)
        {
            if (gSamusOnTopOfBackgrounds)
                bgPriority = 0x1;
            else
                bgPriority = 0x2;
        }
        else
            bgPriority = 0x0;

        if (partCount != 0x0)
        {
            pUnion = gOamData + (partCount + prevSlot);

            for (; partCount != 0x0; partCount--)
            {
                part = *src++;
                *dst++ = part;
                pUnion->split.y = part + yPosition;

                part = *src++;
                *dst++ = part;
                pUnion->split.x = part + xPosition;

                *dst++ = *src++;
                pUnion->split.priority = bgPriority;

                if (pParticle->status & SPRITE_STATUS_XFLIP)
                {
                    pUnion->split.xFlip ^= 0x1;
                    // pUnion->split.x = xPosition - (part + array_2b0c94[pUnion->split.shape][pUnion->split.size] * 8);
                }
                
                dst++;
                pUnion++;
            }

        }

        gNextOAMSlot = partCount + prevSlot;
    }
}

/**
 * 53fd8 | 114 | Processes all the particle effects (calls subroutine and calls the draw function)
 * 
 */
void ParticleProcessAll(void)
{
    struct ParticleEffect* pParticle;
    u8 status;

    if (gGameModeSub1 != 0x2 && (gGameModeSub1 == 0x1 || gGameModeSub1 == 0x3))
    {
        for (pParticle = gParticleEffects; pParticle < gParticleEffects + MAX_AMOUNT_OF_PARTICLES; pParticle++)
        {
            if (pParticle->status & PARTICLE_STATUS_EXISTS && pParticle->effect == PE_ESCAPE) // Probably a priority system
            {
                sProcessParticleFunctionPointers[pParticle->effect](pParticle); // Call subroutine
                if ((pParticle->status & PARTICLE_STATUS_EXISTS) != 0x0)
                    ParticleDraw(pParticle);
            } 
        }
    }
    else
    {
        for (pParticle = gParticleEffects; pParticle < gParticleEffects + MAX_AMOUNT_OF_PARTICLES; pParticle++)
        {
            if ((pParticle->status & (PARTICLE_STATUS_EXISTS | PARTICLE_STATUS_EXPLOSION)) == (PARTICLE_STATUS_EXISTS | PARTICLE_STATUS_EXPLOSION))
            {
                sProcessParticleFunctionPointers[pParticle->effect](pParticle); // Call subroutine
                if ((pParticle->status & PARTICLE_STATUS_EXISTS) != 0x0)
                {
                    ParticleCheckOnScreen(pParticle);
                    status = (pParticle->status & (PARTICLE_STATUS_ONSCREEN | PARTICLE_STATUS_NOT_DRAWN));
                    if (status == PARTICLE_STATUS_ONSCREEN)
                        ParticleDraw(pParticle);
                }
            }
        }

        for (pParticle = gParticleEffects; pParticle < gParticleEffects + MAX_AMOUNT_OF_PARTICLES; pParticle++)
        {
            if ((pParticle->status & (PARTICLE_STATUS_EXISTS | PARTICLE_STATUS_EXPLOSION)) == PARTICLE_STATUS_EXISTS)
            {
                sProcessParticleFunctionPointers[pParticle->effect](pParticle); // Call subroutine
                if (pParticle->status & PARTICLE_STATUS_EXISTS)
                {
                    ParticleCheckOnScreen(pParticle);
                    status = (pParticle->status & (PARTICLE_STATUS_ONSCREEN | PARTICLE_STATUS_NOT_DRAWN));
                    if (status == PARTICLE_STATUS_ONSCREEN)
                        ParticleDraw(pParticle);
                }
            }
        }
        EscaepUpdateTimer();
    }
}

/**
 * 540ec | a0 | 
 * Sets a new particle effect with the given parameters
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param effect Particle effect ID
 */
void ParticleSet(u16 yPosition, u16 xPosition, u8 effect)
{
    struct ParticleEffect* pParticle;
    struct ParticleEffect* pLow;
    u8 counter;
    u8 counter_d;
    u8 count;

    counter = FALSE;
    for (pParticle = gParticleEffects; pParticle < gParticleEffects + MAX_AMOUNT_OF_PARTICLES; pParticle++)
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
        for (pParticle = pLow = gParticleEffects; pParticle < gParticleEffects + MAX_AMOUNT_OF_PARTICLES; pParticle++)
        {
            if (pParticle->effect < PE_CHARGING_BEAM)
                counter_d = pParticle->frameCounter;
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
    pParticle->yPosition = yPosition;
    pParticle->xPosition = xPosition;
    pParticle->currentAnimationFrame = 0x0;
    pParticle->animationDurationCounter = 0x0;
    pParticle->effect = effect;
    pParticle->stage = 0x0;
    pParticle->frameCounter = 0x0;
}

/**
 * 5418c | 50 | 
 * Updates the animation of a particle effect
 * 
 * @param pParticle Particle Effect Pointer
 * @param pOam OAM Pointer to the concerned Frame Data
 * @return 1 if ended, 0 otherwise
 */
u8 ParticleUpdateAnimation(struct ParticleEffect* pParticle, const struct FrameData* pOam)
{
    u8 ended;
    u8 adc;

    ended = FALSE;
    adc = ++pParticle->animationDurationCounter;
    if (pOam[pParticle->currentAnimationFrame].timer <= adc)
    {
        pParticle->animationDurationCounter = 0x0;
        pParticle->currentAnimationFrame++;
        if (pOam[pParticle->currentAnimationFrame].timer == 0x0)
        {
            pParticle->currentAnimationFrame = 0x0;
            ended = TRUE;
        }
    }

    gCurrentParticleEffectOAMFramePointer = pOam[pParticle->currentAnimationFrame].pFrame;
    return ended;
}

/**
 * 541dc | 14 | 
 * Sets the current particle OAM Frame pointer depending on the parameters
 * 
 * @param pParticle Particle Effect Pointer
 * @param pOam OAM Pointer to the concerned Frame Data
 */
void ParticleSetCurrentOAMFramePointer(struct ParticleEffect* pParticle, const struct FrameData* pOam)
{
    gCurrentParticleEffectOAMFramePointer = pOam[pParticle->currentAnimationFrame].pFrame;
}

/**
 * 541f0 | 44 | 
 * Subroutine for the sprite splash water small particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleSpriteSplashWaterSmall(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_water_small_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->yPosition = gEffectYPosition;
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleSpriteSplashWaterBig(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_water_big_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->yPosition = gEffectYPosition;
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleSpriteSplashWaterHuge(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_water_huge_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->yPosition = gEffectYPosition;
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleSpriteSplashLavaSmall(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_lava_small_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->yPosition = gEffectYPosition;
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleSpriteSplashLavaBig(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_lava_big_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->yPosition = gEffectYPosition;
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleSpriteSplashLavaHuge(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_lava_huge_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->yPosition = gEffectYPosition;
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleSpriteSplashAcidSmall(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_acid_small_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->yPosition = gEffectYPosition;
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleSpriteSplashAcidBig(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_acid_big_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->yPosition = gEffectYPosition;
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleSpriteSplashAcidHuge(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, particle_sprite_splash_acid_huge_oam))
        pParticle->status = 0x0;
    else
    {
        pParticle->yPosition = gEffectYPosition;
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleShootingBeamLeft(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamHorizontalOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleShootingBeamRight(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamHorizontalOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleShootingBeamDiagUpLeft(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamDiagonallyUpOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleShootingBeamDiagUpRight(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamDiagonallyUpOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleShootingBeamDiagDownLeft(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamDiagonallyDownOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleShootingBeamDiagDownRight(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamDiagonallyDownOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleShootingBeamUpLeft(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamUpOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleShootingBeamUpRight(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamUpOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleShootingBeamDownLeft(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamDownOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleShootingBeamDownRight(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamDownOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleBomb(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleBombOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleMissileTrail(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleMissileTrailOAM))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
        }
    }
}

/**
 * 54700 | 38 | 
 * Subroutine for the super missile trail particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleSuperMissileTrail(struct ParticleEffect* pParticle)
{    
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleSuperMissileTrailOAM))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
        }
    }
}

/**
 * 54738 | 48 | 
 * Subroutine for the beam trailing right particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleBeamTrailingRight(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleBeamTrailingOAM))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
        {
            pParticle->xPosition++;
            pParticle->yPosition += 0x4;
        }
        else
        {
            pParticle->stage++;
            pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
        }
    }
}

/**
 * 54780 | 48 | 
 * Subroutine for the beam trailing left particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleBeamTrailingLeft(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleBeamTrailingOAM))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage != 0x0)
        {
            pParticle->xPosition--;
            pParticle->yPosition += 0x4;
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleChargedLongBeamTrail(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleChargedLongBeamTrailOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleChargedIceBeamTrail(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleChargedIceBeamTrailOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleChargedWaveBeamTrail(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleChargedWaveBeamTrailOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleChargedPlasmaBeamTrail(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleChargedPlasmaBeamTrailOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleChargedFullBeamTrail(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleChargedFullBeamTrailOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleChargedPistolTrail(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleChargedPistolTrailOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleSpriteExplosionHuge(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleSpriteExplosionHugeOAM))
        pParticle->status = 0x0;
    else if (pParticle->stage == 0x0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54938 | 34 | 
 * Subroutine for the sprite explosion small particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleSpriteExplosionSmall(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleSpriteExplosionSmallOAM))
        pParticle->status = 0x0;
    else if (pParticle->stage == 0x0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54970 | 34 | 
 * Subroutine for the sprite explosion medium particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleSpriteExplosionMedium(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleSpriteExplosionMediumOAM))
        pParticle->status = 0x0;
    else if (pParticle->stage == 0x0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 549a8 | 34 | 
 * Subroutine for the sprite explosion big particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleSpriteExplosionBig(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleSpriteExplosionBigOAM))
        pParticle->status = 0x0;
    else if (pParticle->stage == 0x0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 549e0 | 34 | 
 * Subroutine for the sprite explosion single then big particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleSpriteExplosionSingleThenBig(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleSpriteExplosionSingleThenBigOAM))
        pParticle->status = 0x0;
    else if (pParticle->stage == 0x0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54a18 | 38 | 
 * Subroutine for the screw attack destroyed particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleScrewAttackDestroyed(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleScrewAttackDestroyedOAM))
        pParticle->status = 0x0;
    else if (pParticle->stage == 0x0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54a50 | 38 | 
 * Subroutine for the shinespark destroyed particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleShinesparkDestroyed(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleShinesparkDestroyedOAM))
        pParticle->status = 0x0;
    else if (pParticle->stage == 0x0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54a88 | 38 | 
 * Subroutine for the sudo attack destroyed particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleSudoScrewDestroyed(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleSudoScrewDestroyedOAM))
        pParticle->status = 0x0;
    else if (pParticle->stage == 0x0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54ac0 | 38 | 
 * Subroutine for the speedbooster destroyed particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleSpeedboosterDestroyed(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleSpeedboosterDestroyedOAM))
        pParticle->status = 0x0;
    else if (pParticle->stage == 0x0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54af8 | 38 | 
 * Subroutine for the main boss death particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleMainBossDeath(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleMainBossDeathOAM))
        pParticle->status = 0x0;
    else if (pParticle->stage == 0x0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54b30 | 40 | 
 * Subroutine for the freezing sprite with ice particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleFreezingSpriteWithIce(struct ParticleEffect* pParticle)
{
    pParticle->status ^= PARTICLE_STATUS_NOT_DRAWN;
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleFreezingSpriteWithIceOAM))
        pParticle->status = 0x0;
    else if (pParticle->stage == 0x0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54b70 | 40 | 
 * Subroutine for the freezing sprite with charged ice particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleFreezingSpriteWithChargedIce(struct ParticleEffect* pParticle)
{
    pParticle->status ^= PARTICLE_STATUS_NOT_DRAWN;
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleFreezingSpritewithChargedIceBeamOAM))
        pParticle->status = 0x0;
    else if (pParticle->stage == 0x0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54bb0 | 3c | 
 * Subroutine for the hitting something with base beam particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleHittingSomethingWithNormalBeam(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithNormalBeamOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleHittingSomethingWithLongBeam(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithLongBeamOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleHittingSomethingWithIceBeam(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithIceBeamOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleHittingSomethingWithWaveBeam(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithWaveBeamOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleHittingSomethingWithFullBeamNoPlasma(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithWaveBeamOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleHittingSomethingWithPlasmaBeam(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithPlasmaBeamOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleHittingSomethingWithFullBeam(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithPlasmaBeamOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleHittingSomethingInvincible(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingInvincibleOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleHittingSomethingWithMissile(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithMissileOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleHittingSomethingWithSuperMissile(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithSuperMissileOAM))
        pParticle->status = 0x0;
    else
    {
        if (pParticle->stage == 0x0)
        {
            pParticle->stage++;
            SoundPlay(0xFC);
            SoundPlay(0xFD);
            ScreenShakeStartHorizontal(0xA, 0x81);
            ScreenShakeStartVertical(0xA, 0x81);
        }
    }
}

/**
 * 54e2c | 34 | 
 * Subroutine for the small dust particle effect
 * 
 * @param pParticle Particle Effect Pointer
 */
void ParticleSmallDust(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleSmallDustOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleMediumDust(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleMediumDustOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleTwoMediumDust(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleTwoMediumDustOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleSecondSmallDust(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleSmallDustOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleSecondMediumDust(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleMediumDustOAM))
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleSecondTwoMediumDust(struct ParticleEffect* pParticle)
{
    pParticle->frameCounter++;
    if (ParticleUpdateAnimation(pParticle, sParticleTwoMediumDustOAM))
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

    bbf = gEquipment.beamBombsActivation;

    if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
    {
        if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
            SoundPlay(0xE6);
        else
            SoundPlay(0xE4);
    }
    else
    {
        if (gEquipment.beamBombsActivation & BBF_PLASMA_BEAM)
        {
            if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
                SoundPlay(0xE2);
            else
                SoundPlay(0xE0);
        }
        else
        {
            if (gEquipment.beamBombsActivation & BBF_WAVE_BEAM)
            {
                if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
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

    bbf = gEquipment.beamBombsActivation;

    if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
    {
        if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
            SoundStop(0xE6);
        else
            SoundStop(0xE4);
    }
    else
    {
        if (gEquipment.beamBombsActivation & BBF_PLASMA_BEAM)
        {
            if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
                SoundStop(0xE2);
            else
                SoundStop(0xE0);
        }
        else
        {
            if (gEquipment.beamBombsActivation & BBF_WAVE_BEAM)
            {
                if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
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

    bbf = gEquipment.beamBombsActivation;

    if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
    {
        if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
            SoundPlay(0xE7);
        else
            SoundPlay(0xE5);
    }
    else
    {
        if (gEquipment.beamBombsActivation & BBF_PLASMA_BEAM)
        {
            if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
                SoundPlay(0xE3);
            else
                SoundPlay(0xE1);
        }
        else
        {
            if (gEquipment.beamBombsActivation & BBF_WAVE_BEAM)
            {
                if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
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
 * @param pParticle Particle Effect Pointer
 */
void ParticleChargingBeam(struct ParticleEffect* pParticle)
{
    pParticle->yPosition = gArmCannonY;
    pParticle->xPosition = gArmCannonX;

    if (gSamusWeaponInfo.chargeCounter < 0x10)
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
                ParticleUpdateAnimation(pParticle, sParticleChargingBeamBeginOAM);
                ParticlePlayBeginToChargeSound();
                break;

            case 0x1:
                if (gPreventMovementTimer != 0x0)
                    ParticleSetCurrentOAMFramePointer(pParticle, sParticleChargingBeamBeginOAM);
                else
                {
                    if (gSamusWeaponInfo.chargeCounter >= 0x40)
                    {
                        pParticle->stage = 0x2;
                        pParticle->currentAnimationFrame = 0x0;
                        pParticle->animationDurationCounter = 0x0;
                        pParticle->frameCounter = 0x0;
                        ParticleUpdateAnimation(pParticle, sParticleChargingBeamChargedOAM);
                    }
                    else
                        ParticleUpdateAnimation(pParticle, sParticleChargingBeamBeginOAM);
                }
                break;

            default:
                if (gPreventMovementTimer != 0x0)
                    ParticleSetCurrentOAMFramePointer(pParticle, sParticleChargingBeamChargedOAM);
                else
                {
                    ParticleUpdateAnimation(pParticle, sParticleChargingBeamChargedOAM);
                    if (!(pParticle->frameCounter & 0xF))
                        ParticlePlayBeamFullChargedSound();
                    pParticle->frameCounter++;
                    return;
                }
        }
    }
}

/**
 * 55208 | a8 | 
 * Subroutine for the escape particle effect
 * 
 * @param pParticle Particle Effect Pointer
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
                pParticle->frameCounter = 0xFF;
                play_cutscene(0x2);
            }
            else if (gCurrentEscapeStatus == ESCAPE_STATUS_HAPPENNING && EscapeCheckHasEscaped())
            {
                pParticle->stage = 0x2;
                pParticle->frameCounter = 0x20;
            }
            break;

        case 0x2:
            pParticle->yPosition -= 0x2;
            pParticle->frameCounter--;
            if (pParticle->frameCounter == 0x0)
                pParticle->status = 0x0;
    }

    EscapeUpdateOAM();
    gCurrentParticleEffectOAMFramePointer = gParticleEscapeOAMFrames;
}

/**
 * 552b0 | a8 | 
 * Subroutine for the samus reflection particle effect
 * 
 * @param pParticle Particle Effect Pointer
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

    pSrc = (u16*)gSamusPhysics.pBodyOam;
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

    pParticle->yPosition = gSubSpriteData1.yPosition + 0x5C;
    pParticle->xPosition = gSubSpriteData1.xPosition;

    if (gSubSpriteData1.workVariable1 == 0x0) // Probably checks for shootable symbol state
        pParticle->status &= ~PARTICLE_STATUS_NOT_DRAWN;
    else
    {
        pParticle->status |= PARTICLE_STATUS_NOT_DRAWN;
        if (gSubSpriteData1.workVariable3 == 0x1)
            pParticle->status = 0x0;
    }
}