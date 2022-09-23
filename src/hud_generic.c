#include "gba.h"
#include "hud_generic.h"
#include "escape.h" // Required

#include "data/hud_data.c"

#include "constants/escape.h"
#include "constants/game_state.h"
#include "constants/minimap.h"
#include "constants/particle.h"

#include "structs/escape.h"
#include "structs/game_state.h"
#include "structs/minimap.h"
#include "structs/hud.h"
#include "structs/particle.h"

/**
 * @brief 53c68 | 24 | Loads the common sprites graphics
 * 
 */
void HUDGenericLoadCommonSpriteGFX(void)
{
    dma_set(3, sCommonSpritesGFX, VRAM_BASE + 0x10800, DMA_ENABLE << 16 | 0x1C00);
}

/**
 * @brief 53c8c | 24 | Resets the refill animations
 * 
 */
void HUDGenericResetRefillAnimations(void)
{
    gEnergyRefillAnimation = 0x0;
    gMissileRefillAnimation = 0x0;
    gSuperMissileRefillAnimation = 0x0;
    gPowerBombRefillAnimation = 0x0;
}

/**
 * @brief 53cb0 | 120 | Resets the HUD data and the particles
 * 
 */
void HUDGenericResetHUDData(void)
{
    struct ParticleEffect* pParticle;

    if (gGameModeSub3 == 0x0 || gTourianEscapeCutsceneStage != 0x0)
    {
        for (pParticle = gParticleEffects; pParticle < gParticleEffects + MAX_AMOUNT_OF_PARTICLES; pParticle++)
            pParticle->status = 0x0;

        gEnergyDigits.ones = 0xF;
        gEnergyDigits.tens = 0xF;
        gEnergyDigits.hundreds = 0xF;
        gEnergyDigits.thousands = 0xF;

        gMaxEnergyDigits.ones = 0xF;
        gMaxEnergyDigits.tens = 0xF;
        gMaxEnergyDigits.hundreds = 0xF;
        gMaxEnergyDigits.thousands = 0xF;

        gMissileDigits.ones = 0xF;
        gMissileDigits.tens = 0xF;
        gMissileDigits.hundreds = 0xF;

        gPowerBombDigits.ones = 0xF;
        gPowerBombDigits.tens = 0xF;
        gPowerBombDigits.hundreds = 0xF;

        gSuperMissileDigits.ones = 0xF;
        gSuperMissileDigits.tens = 0xF;
        gSuperMissileDigits.hundreds = 0xF;

        gMissileHighlightStatus = 0x0;
        gPowerBombHighlightStatus = 0x0;
        gSuperMissileHighlightStatus = 0x0;

        gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_LOWER_LINE;
        gCurrentEscapeStatus = ESCAPE_STATUS_NONE;

        HUDGenericResetRefillAnimations();
    }
    else if (gPauseScreenFlag == PAUSE_SCREEN_NONE)
    {
        HUDGenericResetRefillAnimations();
        for (pParticle = gParticleEffects; pParticle < gParticleEffects + MAX_AMOUNT_OF_PARTICLES; pParticle++)
        {
            if (pParticle->effect < PE_CHARGING_BEAM)
                pParticle->status = 0x0;
            else if (pParticle->effect == PE_ESCAPE && EscapeDetermineTimer() == ESCAPE_NONE)
                pParticle->status = 0x0;
        }
    }
}
