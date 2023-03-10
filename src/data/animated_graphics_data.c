#include "data/animated_graphics_data.h"
#include "data/animated_tiles_data.h"
#include "constants/animated_graphics.h"
#include "macros.h"

const struct AnimatedGraphicsData sAnimatedGraphicsEntries[38] = {
    [0] = {
        .type = ANIMATED_GRAPHICS_TYPE_NONE,
        .framesPerState = 0,
        .numberOfStates = 0,
        .pGraphics = &sAnimatedTilesGFX[0 * 128],
    },
    [1] = {
        .type = ANIMATED_GRAPHICS_TYPE_ALTERNATE,
        .framesPerState = 12,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGFX[36 * 128],
    },
    [2] = {
        .type = ANIMATED_GRAPHICS_TYPE_ALTERNATE,
        .framesPerState = 12,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGFX[40 * 128],
    },
    [3] = {
        .type = ANIMATED_GRAPHICS_TYPE_ALTERNATE,
        .framesPerState = 12,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGFX[44 * 128],
    },
    [4] = {
        .type = ANIMATED_GRAPHICS_TYPE_ALTERNATE,
        .framesPerState = 12,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGFX[48 * 128],
    },
    [5] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[0 * 512],
    },
    [6] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[1 * 512],
    },
    [7] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[2 * 512],
    },
    [8] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[3 * 512],
    },
    [9] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[6 * 512],
    },
    [10] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[7 * 512],
    },
    [11] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[4 * 512],
    },
    [12] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 12,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[5 * 512],
    },
    [13] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 2,
        .numberOfStates = 8,
        .pGraphics = &sAnimatedTilesGFX[4 * 128],
    },
    [14] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 2,
        .numberOfStates = 8,
        .pGraphics = &sAnimatedTilesGFX[12 * 128],
    },
    [15] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 11,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[6 * 512],
    },
    [16] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 11,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[7 * 512],
    },
    [17] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[8 * 512],
    },
    [18] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGFX[60 * 128],
    },
    [19] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGFX[64 * 128],
    },
    [20] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 11,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGFX[68 * 128],
    },
    [21] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 11,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGFX[72 * 128],
    },
    [22] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGFX[68 * 128],
    },
    [23] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 11,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[0 * 512],
    },
    [24] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 11,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[1 * 512],
    },
    [25] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 11,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[2 * 512],
    },
    [26] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 11,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[3 * 512],
    },
    [27] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGFX[52 * 128],
    },
    [28] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 10,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGFX[56 * 128],
    },
    [29] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 11,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedTilesGFX[52 * 128],
    },
    [30] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 8,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[9 * 512],
    },
    [31] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 8,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[10 * 512],
    },
    [32] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 8,
        .numberOfStates = 4,
        .pGraphics = &sAnimatedLiquidsGFX[11 * 512],
    },
    [33] = {
        .type = ANIMATED_GRAPHICS_TYPE_ALTERNATE,
        .framesPerState = 1,
        .numberOfStates = 8,
        .pGraphics = &sAnimatedTilesGFX[76 * 128],
    },
    [34] = {
        .type = ANIMATED_GRAPHICS_TYPE_ALTERNATE,
        .framesPerState = 1,
        .numberOfStates = 8,
        .pGraphics = &sAnimatedTilesGFX[84 * 128],
    },
    [35] = {
        .type = ANIMATED_GRAPHICS_TYPE_ALTERNATE,
        .framesPerState = 1,
        .numberOfStates = 8,
        .pGraphics = &sAnimatedTilesGFX[92 * 128],
    },
    [36] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 1,
        .numberOfStates = 8,
        .pGraphics = &sAnimatedTilesGFX[20 * 128],
    },
    [37] = {
        .type = ANIMATED_GRAPHICS_TYPE_NORMAL,
        .framesPerState = 2,
        .numberOfStates = 8,
        .pGraphics = &sAnimatedTilesGFX[28 * 128],
    },
};

#define GFX_ANIM_TO_3BYTES(n) n, 0, 0
const u8 sAnimatedTilesetEntries[8][48] = {
    [0] = {
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0),
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0),
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0),
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0)
    },
    [1] = {
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0),
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0),
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0),
        GFX_ANIM_TO_3BYTES(1), GFX_ANIM_TO_3BYTES(2), GFX_ANIM_TO_3BYTES(3), GFX_ANIM_TO_3BYTES(4)
    },
    [2] = {
        GFX_ANIM_TO_3BYTES(5), GFX_ANIM_TO_3BYTES(6), GFX_ANIM_TO_3BYTES(7), GFX_ANIM_TO_3BYTES(8),
        GFX_ANIM_TO_3BYTES(23), GFX_ANIM_TO_3BYTES(24), GFX_ANIM_TO_3BYTES(25), GFX_ANIM_TO_3BYTES(26),
        GFX_ANIM_TO_3BYTES(11), GFX_ANIM_TO_3BYTES(27), GFX_ANIM_TO_3BYTES(29), GFX_ANIM_TO_3BYTES(28),
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0)
    },
    [3] = {
        GFX_ANIM_TO_3BYTES(9), GFX_ANIM_TO_3BYTES(10), GFX_ANIM_TO_3BYTES(15), GFX_ANIM_TO_3BYTES(16),
        GFX_ANIM_TO_3BYTES(17), GFX_ANIM_TO_3BYTES(30), GFX_ANIM_TO_3BYTES(31), GFX_ANIM_TO_3BYTES(32),
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0),
        GFX_ANIM_TO_3BYTES(9), GFX_ANIM_TO_3BYTES(10), GFX_ANIM_TO_3BYTES(15), GFX_ANIM_TO_3BYTES(16)
    },
    [4] = {
        GFX_ANIM_TO_3BYTES(13), GFX_ANIM_TO_3BYTES(14), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0),
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0),
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0),
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0)
    },
    [5] = {
        GFX_ANIM_TO_3BYTES(18), GFX_ANIM_TO_3BYTES(19), GFX_ANIM_TO_3BYTES(20), GFX_ANIM_TO_3BYTES(21),
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0),
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0),
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0)
    },
    [6] = {
        GFX_ANIM_TO_3BYTES(33), GFX_ANIM_TO_3BYTES(34), GFX_ANIM_TO_3BYTES(35), GFX_ANIM_TO_3BYTES(0),
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0),
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0),
        GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0)
    },
    [7] = {
        GFX_ANIM_TO_3BYTES(5), GFX_ANIM_TO_3BYTES(6), GFX_ANIM_TO_3BYTES(7), GFX_ANIM_TO_3BYTES(8),
        GFX_ANIM_TO_3BYTES(23), GFX_ANIM_TO_3BYTES(24), GFX_ANIM_TO_3BYTES(25), GFX_ANIM_TO_3BYTES(26),
        GFX_ANIM_TO_3BYTES(11), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0),
        GFX_ANIM_TO_3BYTES(36), GFX_ANIM_TO_3BYTES(37), GFX_ANIM_TO_3BYTES(0), GFX_ANIM_TO_3BYTES(0)
    }
};

const struct AnimatedPaletteTiming sAnimatedPaletteTiming_Empty = {
    .timer = 0,
    .row = 0
};

const struct AnimatedPaletteData sAnimatedPaletteEntries[18] = {
    [0] = {
        .type = ANIMATED_PALETTE_TYPE_NONE,
        .framesPerState = 0,
        .numbersOfStates = 4,
        .pPalette = (const u16* const)0x85dfb60
    },
    [1] = {
        .type = ANIMATED_PALETTE_TYPE_NORMAL,
        .framesPerState = 7,
        .numbersOfStates = 4,
        .pPalette = (const u16* const)0x85dfb60
    },
    [2] = {
        .type = ANIMATED_PALETTE_TYPE_ALTERNATE,
        .framesPerState = 5,
        .numbersOfStates = 12,
        .pPalette = (const u16* const)0x862b8b8
    },
    [3] = {
        .type = ANIMATED_PALETTE_TYPE_ALTERNATE,
        .framesPerState = 10,
        .numbersOfStates = 8,
        .pPalette = (const u16* const)0x862bdb8
    },
    [4] = {
        .type = ANIMATED_PALETTE_TYPE_ALTERNATE,
        .framesPerState = 3,
        .numbersOfStates = 8,
        .pPalette = (const u16* const)0x872c7f8
    },
    [5] = {
        .type = ANIMATED_PALETTE_TYPE_ALTERNATE,
        .framesPerState = 10,
        .numbersOfStates = 4,
        .pPalette = (const u16* const)0x85dfda0
    },
    [6] = {
        .type = ANIMATED_PALETTE_TYPE_ALTERNATE,
        .framesPerState = 3,
        .numbersOfStates = 8,
        .pPalette = (const u16* const)0x872b178
    },
    [7] = {
        .type = ANIMATED_PALETTE_TYPE_ALTERNATE,
        .framesPerState = 10,
        .numbersOfStates = 4,
        .pPalette = (const u16* const)0x85df9e0
    },
    [8] = {
        .type = ANIMATED_PALETTE_TYPE_ALTERNATE,
        .framesPerState = 3,
        .numbersOfStates = 8,
        .pPalette = (const u16* const)0x872aeb8
    },
    [9] = {
        .type = ANIMATED_PALETTE_TYPE_ALTERNATE,
        .framesPerState = 3,
        .numbersOfStates = 8,
        .pPalette = (const u16* const)0x872adb8
    },
    [10] = {
        .type = ANIMATED_PALETTE_TYPE_ALTERNATE,
        .framesPerState = 3,
        .numbersOfStates = 8,
        .pPalette = (const u16* const)0x872b8b8
    },
    [11] = {
        .type = ANIMATED_PALETTE_TYPE_ALTERNATE,
        .framesPerState = 3,
        .numbersOfStates = 8,
        .pPalette = (const u16* const)0x872bb78
    },
    [12] = {
        .type = ANIMATED_PALETTE_TYPE_ALTERNATE,
        .framesPerState = 3,
        .numbersOfStates = 8,
        .pPalette = (const u16* const)0x872be38
    },
    [13] = {
        .type = ANIMATED_PALETTE_TYPE_ALTERNATE,
        .framesPerState = 4,
        .numbersOfStates = 8,
        .pPalette = (const u16* const)0x86ba614
    },
    [14] = {
        .type = ANIMATED_PALETTE_TYPE_ALTERNATE,
        .framesPerState = 10,
        .numbersOfStates = 4,
        .pPalette = (const u16* const)0x872cc78
    },
    [15] = {
        .type = ANIMATED_PALETTE_TYPE_ALTERNATE,
        .framesPerState = 10,
        .numbersOfStates = 4,
        .pPalette = (const u16* const)0x872d078
    },
    [16] = {
        .type = ANIMATED_PALETTE_TYPE_ALTERNATE,
        .framesPerState = 3,
        .numbersOfStates = 8,
        .pPalette = (const u16* const)0x85dfa60
    },
    [17] = {
        .type = ANIMATED_PALETTE_TYPE_ALTERNATE,
        .framesPerState = 3,
        .numbersOfStates = 8,
        .pPalette = (const u16* const)0x872b438
    },
};


const struct BackgroundEffectColorData sBackgroundEffectColorData[9] = {
    [0] = {
        .colorMask = COLOR_WHITE,
        .color_1 = COLOR_WHITE + 1,
        .color_2 = COLOR_WHITE + 1,
        .applyToOBJ = FALSE
    },
    [BACKGROUND_EFFECT_LIGHTNING] = {
        .colorMask = COLOR_WHITE,
        .color_1 = COLOR_WHITE,
        .color_2 = COLOR_WHITE + 1,
        .applyToOBJ = FALSE
    },
    [BACKGROUND_EFFECT_SLIGHT_YELLOW] = {
        .colorMask = COLOR_WHITE,
        .color_1 = COLOR(0x16, 0x16, 0x0),
        .color_2 = COLOR_WHITE + 1,
        .applyToOBJ = FALSE
    },
    [BACKGROUND_EFFECT_HEAVY_YELLOW] = {
        .colorMask = COLOR_WHITE,
        .color_1 = COLOR(0x16, 0x16, 0x0),
        .color_2 = COLOR_WHITE + 1,
        .applyToOBJ = FALSE
    },
    [BACKGROUND_EFFECT_EXIT_ZEBES_FADE] = {
        .colorMask = COLOR_WHITE,
        .color_1 = COLOR_WHITE,
        .color_2 = COLOR_WHITE + 1,
        .applyToOBJ = TRUE
    },
    [BACKGROUND_EFFECT_INTRO_TEXT_FADE] = {
        .colorMask = COLOR_WHITE,
        .color_1 = COLOR_BLACK,
        .color_2 = COLOR_WHITE + 1,
        .applyToOBJ = TRUE
    },
    [BACKGROUND_EFFECT_QUICK_FLASH] = {
        .colorMask = COLOR_WHITE,
        .color_1 = COLOR_WHITE,
        .color_2 = COLOR(0x0, 0x0, 0x1F),
        .applyToOBJ = FALSE
    },
    [BACKGROUND_EFFECT_ALL_BLACK] = {
        .colorMask = COLOR_WHITE,
        .color_1 = COLOR_BLACK,
        .color_2 = COLOR_WHITE + 1,
        .applyToOBJ = TRUE
    },
    [BACKGROUND_EFFECT_ALL_WHITE] = {
        .colorMask = COLOR_WHITE,
        .color_1 = COLOR_WHITE,
        .color_2 = COLOR_WHITE + 1,
        .applyToOBJ = TRUE
    },
};


const u16 sBackgroundEffectBehavior_Lightning[34][3] = {
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_RANDOM, 60 * 5, 0 },
    { BACKGROUND_EFFECT_COMMAND_PLAY_SOUND, 0, 0xA6 }, // Thunder sound
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 12 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 3, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 8 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 3, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 4 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 3, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 12 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 3, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 11 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 3, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 10 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 3, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 9 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 8 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 7 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 6 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 5, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 5 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 5, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 4 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 5, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 3 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 5, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 2 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 5, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 1 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 5, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 0 },
    { BACKGROUND_EFFECT_COMMAND_END, 0, 0 }
};

const u16 sBackgroundEffectBehavior_QuickFlash[12][3] = {
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 16 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_SECOND_COLOR, 0, 16 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 2, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 14 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 12 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 8 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 6 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 4 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 2 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 0 },
    { BACKGROUND_EFFECT_COMMAND_END_AND_KILL, 0, 0 }
};

const u16 sBackgroundEffectBehavior_SlightYellow[21][3] = {
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 13, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 3 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 12, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 4 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 12, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 5 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 12, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 4 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 12, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 3 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 12, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 4 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 12, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 5 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 12, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 4 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 10, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 3 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 10, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 0 },
    { BACKGROUND_EFFECT_COMMAND_END_AND_KILL, 0, 0 }
};

const u16 sBackgroundEffectBehavior_HeavyYellow[20][3] = {
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 2 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 12, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 4 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 12, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 6 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 12, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 8 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 12, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 10 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 12, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 8 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 12, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 6 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 12, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 4 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 12, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 2 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 12, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 0 },
    { BACKGROUND_EFFECT_COMMAND_END_AND_KILL, 0, 0 }
};

const u16 sBackgroundEffectBehavior_ExitZebes[30][3] = {
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 1 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 2, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 2 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 2, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 3 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 2, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 4 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 2, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 6 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 2, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 7 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 2, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 8 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 2, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 9 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 2, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 10 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 2, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 11 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 2, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 12 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 2, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 13 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 2, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 14 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 2, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 15 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 2, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 16 },
    { BACKGROUND_EFFECT_COMMAND_END_EXIT_ZEBES, 0, 0 }
};

const u16 sBackgroundEffectBehavior_IntroText[30][3] = {
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 1 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 2 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 3 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 4 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 6 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 7 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 8 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 9 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 10 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 11 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 12 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 13 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 14 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 15 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 16 },
    { BACKGROUND_EFFECT_COMMAND_END_BEFORE_INTRO_TEXT, 0, 0 }
};

const u16 sBackgroundEffectBehavior_AllBlackWhite[39][3] = {
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 1 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 2 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 3 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 4 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 6 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 7 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 8 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 9 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 10 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 11 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 12 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 13 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 14 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 15 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 16 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER, 60, 0 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 12 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 8 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 4 },
    { BACKGROUND_EFFECT_COMMAND_WAIT_FOR_TIMER_BEFORE, 4, 0 },
    { BACKGROUND_EFFECT_COMMAND_CHECK_APPLY_FIRST_COLOR, 0, 0 },
    { BACKGROUND_EFFECT_COMMAND_END_AND_KILL, 0, 0 }
};
