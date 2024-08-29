#include "particle.h"
#include "sprites_AI/ruins_test.h"
#include "escape.h" // Required

#include "data/engine_pointers.h"
#include "data/projectile_data.h"
#include "data/sprite_data.h"
#include "data/particle_data.h"
#include "data/visual_effects_data.h"

#include "constants/audio.h"
#include "constants/color_fading.h"
#include "constants/escape.h"
#include "constants/game_state.h"
#include "constants/particle.h"
#include "constants/samus.h"
#include "constants/projectile.h"

#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/escape.h"
#include "structs/game_state.h"
#include "structs/samus.h"
#include "structs/sprite.h"

/**
 * 53dd0 | 98 | Checks if a particle effect is on screen
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleCheckOnScreen(struct ParticleEffect* pParticle)
{
    u16 bgBaseY;
    u16 bgBaseX;
    u16 bgRightBoundry;
    u16 bgTopBoundry;
    u16 bgLeftBoundry;
    u16 bgBottomBoundry;
    u16 particleY;
    u16 particleX;

    if (pParticle->status & PARTICLE_STATUS_ABSOLUTE_POSITION)
    {
        pParticle->status |= PARTICLE_STATUS_ONSCREEN;
        return;
    }

    bgBaseY = gBg1YPosition + BLOCK_SIZE * 8;
    particleY = pParticle->yPosition + BLOCK_SIZE * 8;
    bgBottomBoundry = bgBaseY - BLOCK_SIZE * 2;
    bgTopBoundry = bgBaseY + BLOCK_SIZE * 12;

    bgBaseX = gBg1XPosition + BLOCK_SIZE * 8;
    particleX = pParticle->xPosition + BLOCK_SIZE * 8;
    bgLeftBoundry = bgBaseX - BLOCK_SIZE * 2;
    bgRightBoundry = bgBaseX + BLOCK_SIZE * 17;

    if (bgLeftBoundry < particleX && particleX < bgRightBoundry &&
        bgBottomBoundry < particleY && particleY < bgTopBoundry)
    {
        pParticle->status |= PARTICLE_STATUS_ONSCREEN;
    }
    else
    {
        if (pParticle->status & PARTICLE_STATUS_LIVE_OFF_SCREEN)
            pParticle->status &= ~PARTICLE_STATUS_ONSCREEN;
        else
            pParticle->status = 0;
    }
}

/**
 * 53e68 | 170 | Draws a particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleDraw(struct ParticleEffect* pParticle)
{
    s32 prevSlot;
    s32 partCount;
    const u16* src;
    u16* dst;
    u8 xFlipped;
    s32 newSlot;
    u16 yPosition;
    u16 xPosition;
    u16 bgPriority;
    u16 part;
    s32 i;
    u32 shape;
    u32 size;
    
    prevSlot = gNextOamSlot;
    src = gCurrentParticleEffectOamFramePointer;

    partCount = *src++;
    
    newSlot = partCount + prevSlot;

    if (newSlot < OAM_BUFFER_DATA_SIZE)
    {
        dst = (u16*)(gOamData + prevSlot);

        if (pParticle->status & PARTICLE_STATUS_ABSOLUTE_POSITION)
        {
            yPosition = pParticle->yPosition;
            xPosition = pParticle->xPosition;
        }
        else
        {
            yPosition = SUB_PIXEL_TO_PIXEL(pParticle->yPosition) - SUB_PIXEL_TO_PIXEL(gBg1YPosition);
            xPosition = SUB_PIXEL_TO_PIXEL(pParticle->xPosition) - SUB_PIXEL_TO_PIXEL(gBg1XPosition);
        }

        if (pParticle->status & PARTICLE_STATUS_LOW_PRIORITY)
        {
            if (gSamusOnTopOfBackgrounds)
                bgPriority = 1;
            else
                bgPriority = 2;
        }
        else
            bgPriority = 0;

        xFlipped = pParticle->status & PARTICLE_STATUS_X_FLIP;

        for (i = 0; i < partCount; i++)
        {
            part = *src++;
            *dst++ = part;
            gOamData[prevSlot + i].split.y = part + yPosition;

            part = *src++;
            *dst++ = part;
            gOamData[prevSlot + i].split.x = part + xPosition;

            *dst++ = *src++;
            gOamData[prevSlot + i].split.priority = bgPriority;

            if (xFlipped)
            {
                gOamData[prevSlot + i].split.xFlip ^= TRUE;
                shape = gOamData[prevSlot + i].split.shape;
                size = gOamData[prevSlot + i].split.size;
                gOamData[prevSlot + i].split.x = xPosition - (part + sOamXFlipOffsets[shape][size] * 8);
            }
            
            dst++;
        }

        gNextOamSlot = partCount + prevSlot;
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

    if (gGameModeSub1 != SUB_GAME_MODE_PLAYING)
    {
        if (gGameModeSub1 != SUB_GAME_MODE_DOOR_TRANSITION && gGameModeSub1 != SUB_GAME_MODE_LOADING_ROOM)
            return;

        for (pParticle = gParticleEffects; pParticle < gParticleEffects + MAX_AMOUNT_OF_PARTICLES; pParticle++)
        {
            if (pParticle->status & PARTICLE_STATUS_EXISTS && pParticle->effect == PE_ESCAPE) // Probably a priority system
            {
                sProcessParticleFunctionPointers[pParticle->effect](pParticle); // Call subroutine

                if (pParticle->status & PARTICLE_STATUS_EXISTS)
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

                if (pParticle->status & PARTICLE_STATUS_EXISTS)
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
 * 540ec | a0 | Sets a new particle effect with the given parameters
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
    u8 counterMax;
    u8 count;

    // Try to find an empty slot
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
        // Couldn't find an empty slot, try to find a particle with the highest frame counter

        count = FALSE;
        for (pParticle = pLow = gParticleEffects; pParticle < gParticleEffects + MAX_AMOUNT_OF_PARTICLES; pParticle++)
        {
            if (pParticle->effect < PE_CHARGING_BEAM)
            {
                // Get counter
                counterMax = pParticle->frameCounter;
            }
            else
            {
                // Includes PE_CHARGING_BEAM and PE_ESCAPE, those 2 particles aren't included in the search
                counterMax = 0;
            }

            if (counter < counterMax)
            {
                // Found new highest, update counter
                counter = counterMax;

                // Store particle pointer
                pLow = pParticle;
                count++;
            }
        }

        if (count)
        {
            // Found a particle, restore it
            pParticle = pLow;
        }
        else
        {
            // Couldn't find a particle, abort
            return;
        }
    }

    // Initialize
    pParticle->status = PARTICLE_STATUS_EXISTS;

    pParticle->yPosition = yPosition;
    pParticle->xPosition = xPosition;

    pParticle->currentAnimationFrame = 0;
    pParticle->animationDurationCounter = 0;

    pParticle->effect = effect;
    pParticle->stage = 0;
    pParticle->frameCounter = 0;
}

/**
 * 5418c | 50 | Updates the animation of a particle effect
 * 
 * @param pParticle Particle effect pointer
 * @param pOam Oam pointer of the particle
 * @return 1 if ended, 0 otherwise
 */
u8 ParticleUpdateAnimation(struct ParticleEffect* pParticle, const struct FrameData* pOam)
{
    u8 ended;

    ended = FALSE;
    APPLY_DELTA_TIME_INC(pParticle->animationDurationCounter);

    if (pOam[pParticle->currentAnimationFrame].timer <= pParticle->animationDurationCounter)
    {
        pParticle->animationDurationCounter = 0;
        pParticle->currentAnimationFrame++;

        if (pOam[pParticle->currentAnimationFrame].timer == 0)
        {
            pParticle->currentAnimationFrame = 0;
            ended = TRUE;
        }
    }

    // Update oam pointer
    gCurrentParticleEffectOamFramePointer = pOam[pParticle->currentAnimationFrame].pFrame;

    return ended;
}

/**
 * 541dc | 14 | Sets the current particle OAM Frame pointer depending on the parameters
 * 
 * @param pParticle Particle effect pointer
 * @param pOam Oam pointer of the particle
 */
void ParticleSetCurrentOamFramePointer(struct ParticleEffect* pParticle, const struct FrameData* pOam)
{
    // Update oam pointer
    gCurrentParticleEffectOamFramePointer = pOam[pParticle->currentAnimationFrame].pFrame;
}

/**
 * 541f0 | 44 | Subroutine for the sprite splash water small particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSpriteSplashWaterSmall(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSpriteSplashWaterSmallOam))
    {
        pParticle->status = 0;
        return;
    }

    // Sync with effect
    pParticle->yPosition = gEffectYPosition;

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54234 | 44 | Subroutine for the sprite splash water big particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSpriteSplashWaterBig(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSpriteSplashWaterBigOam))
    {
        pParticle->status = 0;
        return;
    }

    // Sync with effect
    pParticle->yPosition = gEffectYPosition;

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54278 | 44 | Subroutine for the sprite splash water huge particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSpriteSplashWaterHuge(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSpriteSplashWaterHugeOam))
    {
        pParticle->status = 0;
        return;
    }

    // Sync with effect
    pParticle->yPosition = gEffectYPosition;

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 542bc | 44 | Subroutine for the sprite splash lava small particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSpriteSplashLavaSmall(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);
    if (ParticleUpdateAnimation(pParticle, sParticleSpriteSplashLavaSmallOam))
    {
        pParticle->status = 0;
        return;
    }

    // Sync with effect
    pParticle->yPosition = gEffectYPosition;

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54300 | 44 | Subroutine for the sprite splash lava big particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSpriteSplashLavaBig(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSpriteSplashLavaBigOam))
    {
        pParticle->status = 0;
        return;
    }

    // Sync with effect
    pParticle->yPosition = gEffectYPosition;

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54344 | 44 | Subroutine for the sprite splash lava huge particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSpriteSplashLavaHuge(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSpriteSplashLavaHugeOam))
    {
        pParticle->status = 0;
        return;
    }

    // Sync with effect
    pParticle->yPosition = gEffectYPosition;

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54388 | 44 | Subroutine for the sprite splash acid small particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSpriteSplashAcidSmall(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSpriteSplashAcidSmallOam))
    {
        pParticle->status = 0;
        return;
    }

    // Sync with effect
    pParticle->yPosition = gEffectYPosition;

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54388 | 44 | Subroutine for the sprite splash acid big particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSpriteSplashAcidBig(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSpriteSplashAcidBigOam))
    {
        pParticle->status = 0;
        return;
    }

    // Sync with effect
    pParticle->yPosition = gEffectYPosition;

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54410 | 44 | Subroutine for the sprite splash acid huge particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSpriteSplashAcidHuge(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSpriteSplashAcidHugeOam))
    {
        pParticle->status = 0;
        return;
    }

    // Sync with effect
    pParticle->yPosition = gEffectYPosition;

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54454 | 38 | Subroutine for the shooting beam left particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleShootingBeamLeft(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamHorizontalOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 5448c | 38 | Subroutine for the shooting beam right particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleShootingBeamRight(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamHorizontalOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_X_FLIP | PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 544c4 | 38 | Subroutine for the shooting beam diagonally up particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleShootingBeamDiagUpLeft(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamDiagonallyUpOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 544fc | 38 | Subroutine for the shooting beam diagonally down particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleShootingBeamDiagUpRight(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamDiagonallyUpOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_X_FLIP | PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54534 | 38 | Subroutine for the shooting beam diagonally left particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleShootingBeamDiagDownLeft(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamDiagonallyDownOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 5456c | 38 | Subroutine for the shooting beam diagonally right particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleShootingBeamDiagDownRight(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamDiagonallyDownOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= (PARTICLE_STATUS_X_FLIP | PARTICLE_STATUS_LOW_PRIORITY);
    }
}

/**
 * 545a4 | 38 | Subroutine for the shooting beam up left particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleShootingBeamUpLeft(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamUpOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 545dc | 38 | Subroutine for the shooting beam up right particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleShootingBeamUpRight(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamUpOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= (PARTICLE_STATUS_X_FLIP | PARTICLE_STATUS_LOW_PRIORITY);
    }
}

/**
 * 54614 | 38 | Subroutine for the shooting beam down left particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleShootingBeamDownLeft(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamDownOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 5464c | 38 | Subroutine for the shooting beam down right particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleShootingBeamDownRight(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleShootingBeamDownOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= (PARTICLE_STATUS_X_FLIP | PARTICLE_STATUS_LOW_PRIORITY);
    }
}

/**
 * 54684 | 44 | Subroutine for the bomb particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleBomb(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleBombOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
        SoundPlay(SOUND_BOMB_EXPLOSION);
    }
}

/**
 * 546c8 | 38 | Subroutine for the missile trail particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleMissileTrail(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleMissileTrailOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54700 | 38 | Subroutine for the super missile trail particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSuperMissileTrail(struct ParticleEffect* pParticle)
{    
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSuperMissileTrailOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54738 | 48 | Subroutine for the beam trailing right particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleBeamTrailingRight(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleBeamTrailingOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage != 0)
    {
        pParticle->xPosition += ONE_SUB_PIXEL;
        pParticle->yPosition += PIXEL_SIZE;
    }
    else
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54780 | 48 | Subroutine for the beam trailing left particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleBeamTrailingLeft(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleBeamTrailingOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage != 0)
    {
        pParticle->xPosition -= ONE_SUB_PIXEL;
        pParticle->yPosition += PIXEL_SIZE;
    }
    else
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 547c8 | 34 | Subroutine for the charged long beam trailing particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleChargedLongBeamTrail(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleChargedLongBeamTrailOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
        pParticle->stage++;
}

/**
 * 547fc | 34 | Subroutine for the charged ice beam trailing particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleChargedIceBeamTrail(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleChargedIceBeamTrailOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
        pParticle->stage++;
}

/**
 * 54830 | 34 | Subroutine for the charged wave beam trailing particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleChargedWaveBeamTrail(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleChargedWaveBeamTrailOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
        pParticle->stage++;
}

/**
 * 54864 | 34 | Subroutine for the charged plasma beam trailing particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleChargedPlasmaBeamTrail(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleChargedPlasmaBeamTrailOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
        pParticle->stage++;
}

/**
 * 54898 | 34 | Subroutine for the charged full beam beam trailing particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleChargedFullBeamTrail(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleChargedFullBeamTrailOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
        pParticle->stage++;
}

/**
 * 548cc | 34 | Subroutine for the charged pistol trailing particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleChargedPistolTrail(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleChargedPistolTrailOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
        pParticle->stage++;
}

/**
 * 54900 | 34 | Subroutine for the sprite explosion huge particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSpriteExplosionHuge(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSpriteExplosionHugeOam))
    {
        pParticle->status = 0;
        return;
    }
    
    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54938 | 34 | Subroutine for the sprite explosion small particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSpriteExplosionSmall(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSpriteExplosionSmallOam))
    {
        pParticle->status = 0;
        return;
    }
    
    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54970 | 34 | Subroutine for the sprite explosion medium particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSpriteExplosionMedium(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSpriteExplosionMediumOam))
    {
        pParticle->status = 0;
        return;
    }
    
    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 549a8 | 34 | Subroutine for the sprite explosion big particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSpriteExplosionBig(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSpriteExplosionBigOam))
    {
        pParticle->status = 0;
        return;
    }
    
    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 549e0 | 34 | Subroutine for the sprite explosion single then big particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSpriteExplosionSingleThenBig(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSpriteExplosionSingleThenBigOam))
    {
        pParticle->status = 0;
        return;
    }
    
    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54a18 | 38 | Subroutine for the screw attack destroyed particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleScrewAttackDestroyed(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleScrewAttackDestroyedOam))
    {
        pParticle->status = 0;
        return;
    }
    
    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54a50 | 38 | Subroutine for the shinespark destroyed particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleShinesparkDestroyed(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleShinesparkDestroyedOam))
    {
        pParticle->status = 0;
        return;
    }
    
    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54a88 | 38 | Subroutine for the sudo attack destroyed particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSudoScrewDestroyed(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSudoScrewDestroyedOam))
    {
        pParticle->status = 0;
        return;
    }
    
    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54ac0 | 38 | Subroutine for the speedbooster destroyed particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSpeedboosterDestroyed(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSpeedboosterDestroyedOam))
    {
        pParticle->status = 0;
        return;
    }
    
    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54af8 | 38 | Subroutine for the main boss death particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleMainBossDeath(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleMainBossDeathOam))
    {
        pParticle->status = 0;
        return;
    }
    
    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54b30 | 40 | Subroutine for the freezing sprite with ice particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleFreezingSpriteWithIce(struct ParticleEffect* pParticle)
{
    pParticle->status ^= PARTICLE_STATUS_NOT_DRAWN;
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleFreezingSpriteWithIceOam))
    {
        pParticle->status = 0;
        return;
    }
    
    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54b70 | 40 | Subroutine for the freezing sprite with charged ice particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleFreezingSpriteWithChargedIce(struct ParticleEffect* pParticle)
{
    pParticle->status ^= PARTICLE_STATUS_NOT_DRAWN;
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleFreezingSpritewithChargedIceBeamOam))
    {
        pParticle->status = 0;
        return;
    }
    
    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_EXPLOSION;
    }
}

/**
 * 54bb0 | 3c | Subroutine for the hitting something with base beam particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleHittingSomethingWithNormalBeam(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithNormalBeamOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        SoundPlay(SOUND_BEAM_IMPACT);
    }
}

/**
 * 54bec | 40 | Subroutine for the hitting something with long beam particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleHittingSomethingWithLongBeam(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithLongBeamOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        SoundPlay(SOUND_LONG_BEAM_IMPACT);
    }
}

/**
 * 54c2c | 3c | Subroutine for the hitting something with ice beam particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleHittingSomethingWithIceBeam(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithIceBeamOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        SoundPlay(SOUND_ICE_BEAM_IMPACT);
    }
}

/**
 * 54c68 | 40 | Subroutine for the hitting something with wave beam particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleHittingSomethingWithWaveBeam(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithWaveBeamOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        SoundPlay(SOUND_WAVE_BEAM_IMPACT);
    }
}

/**
 * 54ca8 | 3c | Subroutine for the hitting something with full beam no plasma particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleHittingSomethingWithFullBeamNoPlasma(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithWaveBeamOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        SoundPlay(SOUND_ICE_BEAM_IMPACT);
    }
}

/**
 * 54ce4 | 3c | Subroutine for the hitting something with plasma beam particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleHittingSomethingWithPlasmaBeam(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithPlasmaBeamOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        SoundPlay(SOUND_PLASMA_BEAM_IMPACT);
    }
}

/**
 * 54d20 | 3c | Subroutine for the hitting something with full beam particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleHittingSomethingWithFullBeam(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithPlasmaBeamOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        SoundPlay(SOUND_ICE_BEAM_IMPACT);
    }
}

/**
 * 54d5c | 40 | Subroutine for the hitting something invincible particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleHittingSomethingInvincible(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingInvincibleOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        SoundPlay(SOUND_INVINCIBLE_IMPACT);
    }
}

/**
 * 54d9c | 40 | Subroutine for the hitting something with missile particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleHittingSomethingWithMissile(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithMissileOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        SoundStop(SOUND_MISSILE_THRUST);
        SoundPlay(SOUND_MISSILE_EXPLOSION);
    }
}

/**
 * 54ddc | 50 | Subroutine for the hitting something with super missile particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleHittingSomethingWithSuperMissile(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleHittingSomethingWithSuperMissileOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        SoundStop(SOUND_SUPER_MISSILE_THRUST);
        SoundPlay(SOUND_SUPER_MISSILE_EXPLOSION);

        ScreenShakeStartHorizontal(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
        ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
    }
}

/**
 * 54e2c | 34 | Subroutine for the small dust particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSmallDust(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSmallDustOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
        pParticle->stage++;
}

/**
 * 54e60 | 34 | Subroutine for the medium dust particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleMediumDust(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleMediumDustOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
        pParticle->stage++;
}

/**
 * 54e94 | 34 | Subroutine for the two medium dust particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleTwoMediumDust(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleTwoMediumDustOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
        pParticle->stage++;
}

/**
 * 54e94 | 38 | Subroutine for the second small dust particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSecondSmallDust(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleSmallDustOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54e94 | 38 | Subroutine for the second medium dust particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSecondMediumDust(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleMediumDustOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
        pParticle->stage++;
        pParticle->status |= PARTICLE_STATUS_LOW_PRIORITY;
    }
}

/**
 * 54f00 | 38 | Subroutine for the second two medium dust particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSecondTwoMediumDust(struct ParticleEffect* pParticle)
{
    APPLY_DELTA_TIME_INC(pParticle->frameCounter);

    if (ParticleUpdateAnimation(pParticle, sParticleTwoMediumDustOam))
    {
        pParticle->status = 0;
        return;
    }

    if (pParticle->stage == 0)
    {
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
            SoundPlay(SOUND_ICE_LONG_CHARGE_INIT);
        else
            SoundPlay(SOUND_ICE_CHARGE_INIT);
    }
    else if (gEquipment.beamBombsActivation & BBF_PLASMA_BEAM)
    {
        if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
            SoundPlay(SOUND_PLASMA_LONG_CHARGE_INIT);
        else
            SoundPlay(SOUND_PLASMA_CHARGE_INIT);
    }
    else if (gEquipment.beamBombsActivation & BBF_WAVE_BEAM)
    {
        if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
            SoundPlay(SOUND_WAVE_LONG_CHARGE_INIT);
        else
            SoundPlay(SOUND_WAVE_CHARGE_INIT);
    }
    else
    {
        if (bbf & BBF_LONG_BEAM)
            SoundPlay(SOUND_LONG_CHARGE_INIT);
        else
            SoundPlay(SOUND_SHORT_CHARGE_INIT);
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
            SoundStop(SOUND_ICE_LONG_CHARGE_INIT);
        else
            SoundStop(SOUND_ICE_CHARGE_INIT);
    }
    else if (gEquipment.beamBombsActivation & BBF_PLASMA_BEAM)
    {
        if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
            SoundStop(SOUND_PLASMA_LONG_CHARGE_INIT);
        else
            SoundStop(SOUND_PLASMA_CHARGE_INIT);
    }
    else if (gEquipment.beamBombsActivation & BBF_WAVE_BEAM)
    {
        if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
            SoundStop(SOUND_WAVE_LONG_CHARGE_INIT);
        else
            SoundStop(SOUND_WAVE_CHARGE_INIT);
    }
    else
    {
        if (bbf & BBF_LONG_BEAM)
            SoundStop(SOUND_LONG_CHARGE_INIT);
        else
            SoundStop(SOUND_SHORT_CHARGE_INIT);
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
            SoundPlay(SOUND_ICE_LONG_CHARGE_LOOP);
        else
            SoundPlay(SOUND_ICE_CHARGE_LOOP);
    }
    else if (gEquipment.beamBombsActivation & BBF_PLASMA_BEAM)
    {
        if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
            SoundPlay(SOUND_PLASMA_LONG_CHARGE_LOOP);
        else
            SoundPlay(SOUND_PLASMA_CHARGE_LOOP);
    }
    else if (gEquipment.beamBombsActivation & BBF_WAVE_BEAM)
    {
        if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
            SoundPlay(SOUND_WAVE_LONG_CHARGE_LOOP);
        else
            SoundPlay(SOUND_WAVE_CHARGE_LOOP);
    }
    else
    {
        if (bbf & BBF_LONG_BEAM)
            SoundPlay(SOUND_LONG_CHARGE_LOOP);
        else
            SoundPlay(SOUND_SHORT_CHARGE_LOOP);
    }
}

/**
 * 55108 | 100 | Subroutine for the charging beam particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleChargingBeam(struct ParticleEffect* pParticle)
{
    pParticle->yPosition = gArmCannonY;
    pParticle->xPosition = gArmCannonX;

    if (gSamusWeaponInfo.chargeCounter < CHARGE_BEAM_START_THRESHOLD)
    {
        pParticle->status = 0;
        ParticleStopBeginToChargeSound();
        return;
    }

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
        case 0:
            pParticle->status |= PARTICLE_STATUS_LIVE_OFF_SCREEN;
            pParticle->stage++;
            ParticleUpdateAnimation(pParticle, sParticleChargingBeamBeginOAM);
            ParticlePlayBeginToChargeSound();
            break;

        case 1:
            if (gPreventMovementTimer != 0)
            {
                ParticleSetCurrentOamFramePointer(pParticle, sParticleChargingBeamBeginOAM);
                break;
            }

            if (gSamusWeaponInfo.chargeCounter >= CHARGE_BEAM_THRESHOLD)
            {
                pParticle->stage = 2;
                pParticle->currentAnimationFrame = 0;
                pParticle->animationDurationCounter = 0;
                pParticle->frameCounter = 0;

                ParticleUpdateAnimation(pParticle, sParticleChargingBeamChargedOAM);
            }
            else
            {
                ParticleUpdateAnimation(pParticle, sParticleChargingBeamBeginOAM);
            }
            break;

        default:
            if (gPreventMovementTimer != 0)
            {
                ParticleSetCurrentOamFramePointer(pParticle, sParticleChargingBeamChargedOAM);
                break;
            }

            ParticleUpdateAnimation(pParticle, sParticleChargingBeamChargedOAM);

            if (MOD_AND(pParticle->frameCounter, CONVERT_SECONDS(.25f + 1.f / 60)) == 0)
                ParticlePlayBeamFullChargedSound();

            APPLY_DELTA_TIME_INC(pParticle->frameCounter);
    }
}

/**
 * 55208 | a8 | Subroutine for the escape particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleEscape(struct ParticleEffect* pParticle)
{
    switch (pParticle->stage)
    {
        case 0:
            pParticle->stage = 1;
            pParticle->status |= PARTICLE_STATUS_EXPLOSION | PARTICLE_STATUS_LIVE_OFF_SCREEN | PARTICLE_STATUS_ABSOLUTE_POSITION;

            EscapeSetTimer();
            gCurrentEscapeStatus = ESCAPE_STATUS_HAPPENNING;
            break;
        
        case 1:
            if (gCurrentEscapeStatus == ESCAPE_STATUS_FAILED)
            {
                gPreventMovementTimer = SAMUS_ITEM_PMT;

                pParticle->stage = 3;
                pParticle->frameCounter = UCHAR_MAX;

                StartEffectForCutscene(EFFECT_CUTSCENE_ESCAPE_FAILED);
            }
            else if (gCurrentEscapeStatus == ESCAPE_STATUS_HAPPENNING && EscapeCheckHasEscaped())
            {
                pParticle->stage = 2;
                pParticle->frameCounter = CONVERT_SECONDS(.5f + 1.f / 30);
            }
            break;

        case 2:
            pParticle->yPosition -= PIXEL_SIZE / 2;
            APPLY_DELTA_TIME_DEC(pParticle->frameCounter);

            if (pParticle->frameCounter == 0)
                pParticle->status = 0;
    }

    EscapeUpdateOam();

    gCurrentParticleEffectOamFramePointer = gParticleEscapeOamFrames;
}

/**
 * 552b0 | a8 | Subroutine for the samus reflection particle effect
 * 
 * @param pParticle Particle effect pointer
 */
void ParticleSamusReflection(struct ParticleEffect* pParticle)
{
    u16 partCount;
    u16 count;
    const u16* src;
    u16* dst;

    if (pParticle->stage == 0)
    {
        pParticle->stage = 1;
        pParticle->status |= PARTICLE_STATUS_LIVE_OFF_SCREEN | PARTICLE_STATUS_LOW_PRIORITY | PARTICLE_STATUS_X_FLIP; // Init status
    }

    // Copy the main samus body oam
    src = gSamusPhysics.pBodyOam;
    partCount = *src++;
    dst = gParticleSamusReflectionOamFrames;

    // Check within bounds
    if (partCount > GET_OAM_DATA_SIZE(ARRAY_SIZE(gParticleSamusReflectionOamFrames)))
        partCount = GET_OAM_DATA_SIZE(ARRAY_SIZE(gParticleSamusReflectionOamFrames));

    *dst++ = partCount;

    // Correct number for the loop
    partCount *= OAM_PART_SIZE;

    for (count = 0; count < partCount; count++)
        *dst++ = *src++; // Copy

    // Set for draw
    gCurrentParticleEffectOamFramePointer = gParticleSamusReflectionOamFrames;

    pParticle->yPosition = gSubSpriteData1.yPosition + (BLOCK_SIZE + HALF_BLOCK_SIZE - PIXEL_SIZE);
    pParticle->xPosition = gSubSpriteData1.xPosition;

    if (gSubSpriteData1.workVariable1 == 0)
    {
        // Timer for shootable symbol, if it's 0 then there's no shootable symbol
        pParticle->status &= ~PARTICLE_STATUS_NOT_DRAWN;
    }
    else
    {
        // There's a shootable symbol, don't draw
        pParticle->status |= PARTICLE_STATUS_NOT_DRAWN;

        if (gSubSpriteData1.workVariable3 == RUINS_TEST_FIGHT_STAGE_LAST_SYMBOL_HIT)
        {
            // Fight has ended, destroy
            pParticle->status = 0;
        }
    }
}
