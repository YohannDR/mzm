#include "animated_graphics.h"
#include "gba.h"
#include "macros.h"
#include "sprite.h"
#include "color_effects.h"

#include "data/engine_pointers.h"
#include "data/shortcut_pointers.h"
#include "data/animated_graphics_data.h"
#include "data/animated_tiles_data.h"

#include "constants/animated_graphics.h"
#include "constants/color_fading.h"
#include "constants/connection.h"
#include "constants/event.h"
#include "constants/room.h"

#include "structs/animated_graphics.h"
#include "structs/color_effects.h"
#include "structs/power_bomb_explosion.h"
#include "structs/room.h"

/**
 * @brief 5dd5c | 270 | Transfers the animated graphics to VRAM
 * 
 */
void AnimatedGraphicsTransfer(void)
{
    if (gAnimatedGraphicsToUpdate == 0)
        return;

    if (gAnimatedGraphicsToUpdate & 0x1)
        dma_set(3, EWRAM_BASE + 0x1B000, VRAM_BASE + 0x4000, DMA_ENABLE << 16 | 0x40);

    if (gAnimatedGraphicsToUpdate & 0x2)
        dma_set(3, EWRAM_BASE + 0x1B080, VRAM_BASE + 0x4080, DMA_ENABLE << 16 | 0x40);

    if (gAnimatedGraphicsToUpdate & 0x4)
        dma_set(3, EWRAM_BASE + 0x1B100, VRAM_BASE + 0x4100, DMA_ENABLE << 16 | 0x40);

    if (gAnimatedGraphicsToUpdate & 0x8)
        dma_set(3, EWRAM_BASE + 0x1B180, VRAM_BASE + 0x4180, DMA_ENABLE << 16 | 0x40);

    if (gAnimatedGraphicsToUpdate & 0x10)
        dma_set(3, EWRAM_BASE + 0x1B200, VRAM_BASE + 0x4200, DMA_ENABLE << 16 | 0x40);

    if (gAnimatedGraphicsToUpdate & 0x20)
        dma_set(3, EWRAM_BASE + 0x1B280, VRAM_BASE + 0x4280, DMA_ENABLE << 16 | 0x40);

    if (gAnimatedGraphicsToUpdate & 0x40)
        dma_set(3, EWRAM_BASE + 0x1B300, VRAM_BASE + 0x4300, DMA_ENABLE << 16 | 0x40);

    if (gAnimatedGraphicsToUpdate & 0x80)
        dma_set(3, EWRAM_BASE + 0x1B380, VRAM_BASE + 0x4380, DMA_ENABLE << 16 | 0x40);

    if (gAnimatedGraphicsToUpdate & 0x100)
        dma_set(3, EWRAM_BASE + 0x1B400, VRAM_BASE + 0x4400, DMA_ENABLE << 16 | 0x40);

    if (gAnimatedGraphicsToUpdate & 0x200)
        dma_set(3, EWRAM_BASE + 0x1B480, VRAM_BASE + 0x4480, DMA_ENABLE << 16 | 0x40);

    if (gAnimatedGraphicsToUpdate & 0x400)
        dma_set(3, EWRAM_BASE + 0x1B500, VRAM_BASE + 0x4500, DMA_ENABLE << 16 | 0x40);

    if (gAnimatedGraphicsToUpdate & 0x800)
        dma_set(3, EWRAM_BASE + 0x1B580, VRAM_BASE + 0x4580, DMA_ENABLE << 16 | 0x40);

    if (gAnimatedGraphicsToUpdate & 0x1000)
    {
        dma_set(3, EWRAM_BASE + 0x1B600, VRAM_BASE + 0x4600, DMA_ENABLE << 16 | 0x40);
        dma_set(3, EWRAM_BASE + 0x1B600, VRAM_BASE + 0xFDE0, DMA_ENABLE << 16 | 0x40);
    }

    if (gAnimatedGraphicsToUpdate & 0x2000)
    {
        dma_set(3, EWRAM_BASE + 0x1B680, VRAM_BASE + 0x4680, DMA_ENABLE << 16 | 0x40);
        dma_set(3, EWRAM_BASE + 0x1B680, VRAM_BASE + 0xFE60, DMA_ENABLE << 16 | 0x40);
    }

    if (gAnimatedGraphicsToUpdate & 0x4000)
    {
        dma_set(3, EWRAM_BASE + 0x1B700, VRAM_BASE + 0x4700, DMA_ENABLE << 16 | 0x40);
        dma_set(3, EWRAM_BASE + 0x1B700, VRAM_BASE + 0xFEE0, DMA_ENABLE << 16 | 0x40);
    }

    if (gAnimatedGraphicsToUpdate & 0x8000)
    {
        dma_set(3, EWRAM_BASE + 0x1B780, VRAM_BASE + 0x4780, DMA_ENABLE << 16 | 0x40);
        dma_set(3, EWRAM_BASE + 0x1B780, VRAM_BASE + 0xFF60, DMA_ENABLE << 16 | 0x40);
    }

    gAnimatedGraphicsToUpdate = 0;
}

/**
 * @brief 5dfcc | 164 | Updates the animated graphics
 * 
 */
void AnimatedGraphicsUpdate(void)
{
    u32 update;
    i32 i;
    struct AnimatedGraphicsInfo* pGraphics;
    i32 frame;
    const u8* src;

    pGraphics = gAnimatedGraphicsData;
    for (i = 0; i < ARRAY_SIZE(gAnimatedGraphicsData); )
    {
        update = FALSE;

        switch (pGraphics->type)
        {
            case ANIMATED_GRAPHICS_TYPE_NONE:
                break;

            case ANIMATED_GRAPHICS_TYPE_NORMAL:
                pGraphics->animationDurationCounter++;
                if (pGraphics->animationDurationCounter == pGraphics->framesPerState)
                {
                    update = TRUE;
                    pGraphics->animationDurationCounter = 0;
                    pGraphics->currentAnimationFrame++;
                    if (pGraphics->currentAnimationFrame == pGraphics->numberOfStates)
                        pGraphics->currentAnimationFrame = 0;
                }
                break;

            case 2:
                break;

            case 3:
                if (pGraphics->currentAnimationFrame != pGraphics->numberOfStates - 1)
                {
                    pGraphics->animationDurationCounter++;
                    if (pGraphics->animationDurationCounter == pGraphics->framesPerState)
                    {
                        update = TRUE;
                        pGraphics->animationDurationCounter = 0;
                        pGraphics->currentAnimationFrame++;
                    }
                }
                break;

            case ANIMATED_GRAPHICS_TYPE_ALTERNATE:
                pGraphics->animationDurationCounter++;
                if (pGraphics->animationDurationCounter == pGraphics->framesPerState)
                {
                    update = TRUE;
                    pGraphics->animationDurationCounter = 0;
                    pGraphics->currentAnimationFrame++;
                    frame = pGraphics->currentAnimationFrame;
                    if (pGraphics->currentAnimationFrame == pGraphics->numberOfStates)
                        pGraphics->currentAnimationFrame = 2 - frame;
                }
                break;

            case 5:
                if (pGraphics->currentAnimationFrame != 0)
                {
                    pGraphics->animationDurationCounter++;
                    if (pGraphics->animationDurationCounter == pGraphics->framesPerState)
                    {
                        update = TRUE;
                        pGraphics->animationDurationCounter = 0;
                        pGraphics->currentAnimationFrame--;
                    }
                }
                break;

            case 6:
                pGraphics->animationDurationCounter++;
                if (pGraphics->animationDurationCounter == pGraphics->framesPerState)
                {
                    update = TRUE;
                    pGraphics->animationDurationCounter = 0;
                    pGraphics->currentAnimationFrame--;

                    if (pGraphics->currentAnimationFrame < 0)
                        pGraphics->currentAnimationFrame = pGraphics->numberOfStates - 1;
                }
                break;
        }

        if (update)
        {
            frame = pGraphics->currentAnimationFrame;
            if (pGraphics->currentAnimationFrame < 0)
                frame = (i8)(~frame + 1);

            src = &pGraphics->pGraphics[frame * 128];
            dma_set(3, src, EWRAM_BASE + 0x1B000 + i * 128, DMA_ENABLE << 16 | 0x40);

            gAnimatedGraphicsToUpdate |= 1 << i;
        }

        i++;
        pGraphics++;
    }
}

/**
 * @brief 5e130 | f4 | Loads the animated graphics
 * 
 */
void AnimatedGraphicsLoad(void)
{
    i32 i;
    u8 entry;
    const u8* src;
    const u8* dst;
    struct AnimatedGraphicsInfo* pGraphics;
    const struct AnimatedGraphicsData* pData;

    gAnimatedGraphicsToUpdate = 0;

    pGraphics = gAnimatedGraphicsData;
    for (i = 0; i < ARRAY_SIZE(gAnimatedGraphicsData); )
    {
        pGraphics->graphicsEntry = sAnimatedTilesetEntries[gAnimatedGraphicsEntry.tileset][i * 3];

        entry = pGraphics->graphicsEntry;
        pData = &sAnimatedGraphicsEntries[entry];
        pGraphics->type = pData->type;
        pGraphics->framesPerState = pData->framesPerState;
        pGraphics->numberOfStates = pData->numberOfStates;

        pGraphics->animationDurationCounter = 0;
        pGraphics->currentAnimationFrame = 0;
        pGraphics->pGraphics = pData->pGraphics;

        switch (pGraphics->type)
        {
            case 3:
            case 6:
                pGraphics->currentAnimationFrame = pGraphics->numberOfStates - 1;
        }

        src = &pGraphics->pGraphics[pGraphics->currentAnimationFrame * 128];
        dst = VRAM_BASE + 0x4000 + i * 0x80;
        dma_set(3, src, dst, DMA_ENABLE << 16 | 0x40);

        if (gPauseScreenFlag == 0 && pGraphics->graphicsEntry == 13)
            gRainSoundEffect |= RAIN_SOUND_ENABLED;

        i++;
        pGraphics++;
    }

    dma_set(3, VRAM_BASE + 0x4600, VRAM_BASE + 0xFDE0, DMA_ENABLE << 16 | 0x100);
}

/**
 * @brief 5e224 | 24 | Resets the tank animations
 * 
 */
void AnimatedGraphicsTanksAnimationReset(void)
{
    gTankAnimations[0].timer = 1;
    gTankAnimations[0].frame = 0;
    gTankAnimations[1].timer = 2;
    gTankAnimations[1].frame = 0;
    gTankAnimations[2].timer = 3;
    gTankAnimations[2].frame = 0;
    gTankAnimations[3].timer = 4;
    gTankAnimations[3].frame = 0;
}

/**
 * @brief 5e248 | 6c | Updates the animation of the collectable tanks
 * 
 */
void AnimatedGraphicsTanksAnimationUpdate(void)
{
    i32 i;
    
    for (i = ARRAY_SIZE(gTankAnimations) - 1; i >= 0; i--)
    {
        // Update timer
        gTankAnimations[i].timer++;

        // Swap animation frame every 5 frames
        if (gTankAnimations[i].timer < 5)
            continue;

        gTankAnimations[i].timer = 0;

        // Update current frame
        gTankAnimations[i].frame++;
        if (gTankAnimations[i].frame > 3)
            gTankAnimations[i].frame = 0;

        // Transfer graphics
        dma_set(3, &sAnimatedTankGfx[i * 512 + gTankAnimations[i].frame * 0x80],
            VRAM_BASE + 0x4820 + i * 0x80, DMA_ENABLE << 16 | 0x40);
    }
}

/**
 * @brief 5e2b4 | 170 | Updates the animated palette
 * 
 */
void AnimatedPaletteUpdate(void)
{
    u32 update;
    i32 row;
    i32 newRow;

    if (gAnimatedGraphicsEntry.palette == 0)
        return;

    if (gCurrentPowerBomb.animationState != 0)
        return;

    if (gDisableAnimatedPalette > FALSE)
        return;

    update = FALSE;
    gAnimatedPaletteTiming.timer++;

    switch (sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].type)
    {
        case ANIMATED_PALETTE_TYPE_NONE:
            break;

        case ANIMATED_PALETTE_TYPE_NORMAL:
            if (sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].framesPerState <= gAnimatedPaletteTiming.timer)
            {
                gAnimatedPaletteTiming.timer = 0;
                gAnimatedPaletteTiming.row++;
                if (sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].numbersOfStates <= gAnimatedPaletteTiming.row)
                {
                    gAnimatedPaletteTiming.row = 0;
                    if (gDisableAnimatedPalette < 0)
                        gDisableAnimatedPalette = TRUE;

                }
                update++;
            }
            break;

        case ANIMATED_PALETTE_TYPE_ALTERNATE:
            if (sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].framesPerState <= gAnimatedPaletteTiming.timer)
            {
                gAnimatedPaletteTiming.timer = 0;
                gAnimatedPaletteTiming.row++;
                if (sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].numbersOfStates <= gAnimatedPaletteTiming.row)
                {
                    newRow = sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].numbersOfStates - 1;
                    gAnimatedPaletteTiming.row = -newRow;
                }
            
                if (gDisableAnimatedPalette < 0 && gAnimatedPaletteTiming.row == 0)
                    gDisableAnimatedPalette = TRUE;
                update++;
            }
            break;

        case 3:
            if (sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].framesPerState <= gAnimatedPaletteTiming.timer)
            {
                gAnimatedPaletteTiming.timer = 0;
                gAnimatedPaletteTiming.row--;
                if (0 > gAnimatedPaletteTiming.row)
                    gAnimatedPaletteTiming.row = sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].numbersOfStates - 1;
                
                update++;
            }
            break;
    }

    if (!update)
        return;

    row = gAnimatedPaletteTiming.row;
    if (row < 0)
        row = -row;

    if (gGameModeSub1 == 2)
    {
        dma_set(3, &sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].pPalette[row * 16],
            PALRAM_BASE + 0x1E0, DMA_ENABLE << 16 | 0x10);
    }
    else
    {
        dma_set(3, &sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].pPalette[row * 16],
            EWRAM_BASE + 0x355E0, DMA_ENABLE << 16 | 0x10);    
    }
}

/**
 * @brief 5e424 | dc | Checks if the animated palette should be disabled when loading a room
 * 
 */
void AnimatedPaletteCheckDisableOnTransition(void)
{
    gAnimatedPaletteTiming = sAnimatedPaletteTiming_Empty;

    // FIXME merge struct HatchFlashingAnimation and struct AnimatedPaletteTiming 
    gHatchFlashingAnimation = *(struct HatchFlashingAnimation*)&sAnimatedPaletteTiming_Empty;

    gDisableAnimatedPalette = FALSE;

    if (gAnimatedGraphicsEntry.palette == 0)
        return;

    // Transfer palette
    dma_set(3, sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].pPalette, PALRAM_BASE + 0x1E0, DMA_ENABLE << 16 | 0x10);

    // Check disable
    switch (gAnimatedGraphicsEntry.palette)
    {
        case 3:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
                gDisableAnimatedPalette = TRUE; // No ziplines
            break;

        case 4:
        case 6:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 16:
        case 17:
            if (gAlarmTimer == 0)
                gDisableAnimatedPalette = TRUE; // No alarm
    }
}

/**
 * @brief 5e500 | 48 | Checks if the lightning effect should play
 * 
 */
void AnimatedGraphicsCheckPlayLightningEffect(void)
{
    u8 effect;

    effect = 0;

    // Check no effect currently active
    if (gPauseScreenFlag != 0 || gBackgroundEffect.type != 0)
        return;

    // Crateria, landing site with no gunship
    if (gCurrentArea == AREA_CRATERIA && gCurrentRoom == 5)
        effect = BACKGROUND_EFFECT_LIGHTNING;

    // Do effect
    if (effect)
        BackgroundEffectStart(effect);
}

/**
 * @brief 5e548 | 84 | Updates the current background effect
 * 
 */
void BackgroundEffectUpdate(void)
{
    u16 color;
    u16 selColor;
    
    gBackgroundEffect.timer++;

    color = BackgroundEffectProcess();

    if (color == 0)
        return;

    if (color == 2)
        selColor = sBackgroundEffectColorData[gBackgroundEffect.type].color_2;
    else
        selColor = sBackgroundEffectColorData[gBackgroundEffect.type].color_1;
    color = selColor;

    if ((color & 0x8000) == 0)
    {
        ApplySpecialBackgroundEffectColorOnBG(sBackgroundEffectColorData[gBackgroundEffect.type].colorMask, color, gBackgroundEffect.colorStage);
        if (sBackgroundEffectColorData[gBackgroundEffect.type].applyToOBJ)
            ApplySpecialBackgroundEffectColorOnOBJ(0xFFFC, color, gBackgroundEffect.colorStage);
    }
}

/**
 * @brief 5e5cc | 12c | Processes the current background effect
 * 
 * @return u16 Color id to update
 */
u16 BackgroundEffectProcess(void)
{
    u16 colorId;
    const u16* pBehavior;

    colorId = 0;

    // Behavior is an array of 3 u16
    pBehavior = &sBackgroundEffectBehaviorPointers[gBackgroundEffect.type][gBackgroundEffect.stage * sizeof(u16[3]) / sizeof(u16)];

    // Execute command
    switch (pBehavior[0])
    {
        case BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_RANDOM:
            if (gBackgroundEffect.timer > pBehavior[1] + gFrameCounter8Bit + gFrameCounter16Bit / 16)
            {
                gBackgroundEffect.stage++;
                gBackgroundEffect.timer = 0;
            }
            break;

        case BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER:
            if (gBackgroundEffect.timer > pBehavior[1])
            {
                gBackgroundEffect.stage++;
                gBackgroundEffect.timer = 0;
            }
            break;

        case BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE:
            if (gBackgroundEffect.timer >= pBehavior[1] - 1)
            {
                gBackgroundEffect.stage++;
                gBackgroundEffect.timer = 0;
            }
            break;

        case BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR:
            if (gColorFading.status == 0)
            {
                gBackgroundEffect.colorStage = pBehavior[2];
                gBackgroundEffect.stage++;
                gBackgroundEffect.timer = 0;
                colorId = 1;
            }
            break;

        case BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_SECOND_COLOR:
            if (gColorFading.status == 0)
            {
                gBackgroundEffect.colorStage = pBehavior[2];
                gBackgroundEffect.stage++;
                gBackgroundEffect.timer = 0;
                colorId = 2;
            }
            break;

        case BACKGROUND_EFFECT_COMMAND_PLAY_SOUND:
            if (pBehavior[2])
                SoundPlay(pBehavior[2]);

            gBackgroundEffect.stage++;
            gBackgroundEffect.timer = 0;
            break;

        case BACKGROUND_EFFECT_COMMAND_END_AND_KILL:
            gBackgroundEffect.type = 0;

        case BACKGROUND_EFFECT_COMMAND_END:
            gBackgroundEffect.stage = 0;
            gBackgroundEffect.timer = 0;
            break;

        case BACKGROUND_EFFECT_COMMAND_END_EXIT_ZEBES:
            gBackgroundEffect.type = 0;
            gBackgroundEffect.stage = 0;
            gBackgroundEffect.timer = 0;
            ColorFadingStart(COLOR_FADING_TOURIAN_ESCAPE);
            gGameModeSub1 = 3;
            break;

        case BACKGROUND_EFFECT_COMMAND_END_BEFORE_INTRO_TEXT:
            gBackgroundEffect.type = 0;
            gBackgroundEffect.stage = 0;
            gBackgroundEffect.timer = 0;
            ColorFadingStart(COLOR_FADING_INTRO_TEXT);
            gGameModeSub1 = 3;
            break;
    }

    return colorId;
}

/**
 * @brief 5e6f8 | 68 | Starts a background effect
 * 
 * @param effect Effect type
 * @return u32 bool, could start
 */
u32 BackgroundEffectStart(u8 effect)
{
    if (gBackgroundEffect.type == 0 && effect != UCHAR_MAX)
    {
        gBackgroundEffect.type = effect;
        gBackgroundEffect.colorStage = 0;
        gBackgroundEffect.stage = 0;
        gBackgroundEffect.timer = 0;
        gBackgroundEffect.unk_7 = 0;

        DMATransfer(3, EWRAM_BASE + 0x35400, EWRAM_BASE + 0x35800, 0x200, 16);
        DMATransfer(3, EWRAM_BASE + 0x35600, EWRAM_BASE + 0x35A00, 0x200, 16);
        return TRUE;
    }

    return FALSE;
}
