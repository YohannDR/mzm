#include "color_effects.h"
#include "macros.h"
#include "gba.h"

#include "data/color_fading_data.h"

#include "constants/color_fading.h"
#include "constants/game_state.h"

#include "structs/color_effects.h"
#include "structs/room.h"
#include "structs/game_state.h"

#define COLOR_DATA_BG_EWRAM ((u16*)(EWRAM_BASE + 0x35000))
#define COLOR_DATA_OBJ_EWRAM ((u16*)(EWRAM_BASE + 0x35200))

/**
 * @brief 5b24c | 3c | To document
 * 
 */
void unk_5b24c(void)
{
    DmaTransfer(3, PALRAM_BASE, EWRAM_BASE + 0x35400, PALRAM_SIZE / 2, 16);
    DmaTransfer(3, PALRAM_OBJ, EWRAM_BASE + 0x35600, PALRAM_SIZE / 2, 16);
}

/**
 * @brief 5b288 | 3c | To document
 * 
 */
void unk_5b288(void)
{
    DmaTransfer(3, PALRAM_BASE, EWRAM_BASE + 0x35000, PALRAM_SIZE / 2, 16);
    DmaTransfer(3, PALRAM_OBJ, EWRAM_BASE + 0x35200, PALRAM_SIZE / 2, 16);
}

/**
 * @brief 5b2c4 | 3c | To document
 * 
 */
void unk_5b2c4(void)
{
    DmaTransfer(3, EWRAM_BASE + 0x35400, EWRAM_BASE + 0x35000, PALRAM_SIZE / 2, 16);
    DmaTransfer(3, EWRAM_BASE + 0x35600, EWRAM_BASE + 0x35200, PALRAM_SIZE / 2, 16);
}

/**
 * @brief 5b304 | 3c | To document
 * 
 */
void unk_5b304(void)
{
    DmaTransfer(3, PALRAM_BASE, EWRAM_BASE + 0x35800, PALRAM_SIZE / 2, 16);
    DmaTransfer(3, PALRAM_OBJ, EWRAM_BASE + 0x35A00, PALRAM_SIZE / 2, 16);
}

/**
 * @brief 5b340 | 10 | To document
 * 
 */
void unk_5b340(void)
{
    unk_5b24c();
    unk_5b288();
}

/**
 * @brief 5b350 | 3c | To document
 * 
 */
void unk_5b350(void)
{
    DmaTransfer(3, EWRAM_BASE + 0x35400, EWRAM_BASE + 0x35800, PALRAM_SIZE / 2, 16);
    DmaTransfer(3, EWRAM_BASE + 0x35600, EWRAM_BASE + 0x35A00, PALRAM_SIZE / 2, 16);
}

/**
 * @brief 5b390 | 6c | [Unused] Checks for the color fading status and transfer the results to Palram
 * 
 */
void CheckTransferFadedPalette_Unused(void)
{
    if (gColorFading.status == 0)
        return;

    if (gColorFading.status & COLOR_FADING_STATUS_ON_BG)
    {
        DmaTransfer(3, EWRAM_BASE + 0x35000, PALRAM_BASE, PALRAM_SIZE / 2, 16);
        gColorFading.status &= ~COLOR_FADING_STATUS_ON_BG;
    }

    if (gColorFading.status & COLOR_FADING_STATUS_ON_OBJ)
    {
        DmaTransfer(3, EWRAM_BASE + 0x35200, PALRAM_OBJ, PALRAM_SIZE / 2, 16);
        gColorFading.status &= ~COLOR_FADING_STATUS_ON_OBJ;
    }
}

/**
 * @brief 5b3fc | dc | Checks for the color fading status and transfer the results to Palram
 * 
 */
void CheckTransferFadedPalette(void)
{
    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
    {
        if (gColorFading.status == 0)
            return;

        if (gColorFading.status & COLOR_FADING_STATUS_ON_BG)
        {
            DmaTransfer(3, EWRAM_BASE + 0x35000, PALRAM_BASE, PALRAM_SIZE / 2, 16);
            gColorFading.status ^= COLOR_FADING_STATUS_ON_BG;
        }

        if (gColorFading.status & COLOR_FADING_STATUS_ON_OBJ)
        {
            DmaTransfer(3, EWRAM_BASE + 0x35200 + 16 * 4, PALRAM_OBJ + 16 * 4, PALRAM_SIZE / 2 - 16 * 4, 16);
            gColorFading.status ^= COLOR_FADING_STATUS_ON_OBJ;
        }
    }
    else
    {
        if (gColorFading.status == 0)
            return;

        if (gColorFading.status & COLOR_FADING_STATUS_ON_BG)
        {
            DmaTransfer(3, EWRAM_BASE + 0x35000, PALRAM_BASE, PALRAM_SIZE / 2, 16);
            gColorFading.status &= ~COLOR_FADING_STATUS_ON_BG;
        }

        if (gColorFading.status & COLOR_FADING_STATUS_ON_OBJ)
        {
            DmaTransfer(3, EWRAM_BASE + 0x35200, PALRAM_OBJ, PALRAM_SIZE / 2, 16);
            gColorFading.status &= ~COLOR_FADING_STATUS_ON_OBJ;
        }
    }
}

/**
 * @brief 5b4d8 | ac | Calls the apply fading color function with the correct fading type and values
 * 
 * @param color Color
 */
void CallApplySpecialBackgroundFadingColor(u8 color)
{
    u8 type;
    u16* dst;
    u16* src;
    u16 mask;

    if (sColorFadingData[gColorFading.type].isWhite)
    {
        if (!gColorFading.useSecondColorSet)
            type = FADING_TYPE_FLASH;
        else
            type = FADING_TYPE_UNK;
    }
    else
    {
        if (!gColorFading.useSecondColorSet)
            type = FADING_TYPE_IN;
        else
            type = FADING_TYPE_OUT;
    }

    dst = EWRAM_BASE + 0x35000;
    src = EWRAM_BASE + 0x35400;
    mask = sColorFadingData[gColorFading.type].bgColorMask;
    ApplySpecialBackgroundFadingColor(type, color, &src, &dst, mask);

    dst = EWRAM_BASE + 0x35200;
    src = EWRAM_BASE + 0x35600;
    mask = sColorFadingData[gColorFading.type].objColorMask;
    ApplySpecialBackgroundFadingColor(type, color, &src, &dst, mask);

    gColorFading.status = COLOR_FADING_STATUS_ON_BG | COLOR_FADING_STATUS_ON_OBJ;
}

/**
 * @brief 5b584 | a0 | Handles the yellow on the screen during a power bomb explosion
 * 
 * @param paletteRow Palette row to start from
 */
void PowerBombYellowTint(u8 paletteRow)
{
    s32 length;
    s32 i;
    u16* pPalette;
    u8 r;
    u8 g;
    u8 b;

    if (gAnimatedGraphicsEntry.palette == 0)
    {
        // Affect all of palram
        length = 16 * 16;
    }
    else
    {
        // Omit last row, where the animated palette is
        length = 15 * 16;
    }

    // Get palram
    DmaTransfer(3, PALRAM_BASE, EWRAM_BASE + 0x35000, PALRAM_SIZE / 2, 16);

    // Get starting position
    pPalette = (u16*)(EWRAM_BASE + 0x35000) + paletteRow * 16;

    for (i = paletteRow * 16; i < length; i++, pPalette++)
    {
        // Ignore first color (transparent color)
        if (i % 16 == 0)
            continue;

        // Get components
        r = RED(*pPalette);
        g = GREEN(*pPalette);
        b = BLUE(*pPalette);

        // Tint red and green
        r += 5;
        g += 5;

        // Check for overflow
        if (r > COLOR_MASK)
            r = COLOR_MASK;

        if (g > COLOR_MASK)
            g = COLOR_MASK;

        // Apply color
        *pPalette = COLOR(r, g, b);
    }

    gColorFading.status |= COLOR_FADING_STATUS_ON_BG;
}

/**
 * @brief 5b624 | 68 | Applyes a monochrome effect to a palette
 * 
 * @param src Source address
 * @param dst Destination address
 * @param additionalValue Additional color
 */
void ApplyMonochromeToPalette(const u16* src, u16* dst, s8 additionalValue)
{
    s32 i;
    u16 color;
    s32 result;
    u16 r;
    u16 g;
    u16 b;

    for (i = 0; i <= UCHAR_MAX; i++, src++, dst++)
    {
        color = *src;

        r = RED(color);
        g = GREEN(color);
        do {
            b = BLUE(color);
        }while(0);

        // Get average
        result = (r + g + b) / 3 + additionalValue;
        CLAMP2(result, 0, COLOR_MASK);
        
        // Create grey color
        *dst = COLOR(result, result, result);
    }
}

/**
 * @brief 5b68c | d8 | Applies a smooth transition of a palette to its monochrome variant (created with ApplyMonochromeToPalette)
 * 
 * @param srcBase Base palette pointer
 * @param srcMonochrome Monochrome palette pointer
 * @param dst Destination address
 * @param stage Stage
 */
void ApplySmoothMonochromeToPalette(u16* srcBase, u16* srcMonochrome, u16* dst, u8 stage)
{
    s32 i;

    s32 color;
    
    s32 colorMono;
    u16 monoR;
    u16 monoG;
    u16 monoB;

    s32 colorBase;
    u8 baseR;
    u8 baseG;
    u8 baseB;

    u8 newR;
    u8 newG;
    u8 newB;

    if (stage == 0)
    {
        // Optimization, no calculations needed
        DmaTransfer(3, srcBase, dst, PALRAM_SIZE / 2, 0x10);
        return;
    }
    
    if (stage >= 0x1F)
    {
        // Transition is done, simply use the monochrome
        DmaTransfer(3, srcMonochrome, dst, PALRAM_SIZE / 2, 0x10);
        return;
    }
    
    i = 0;
    while (i <= UCHAR_MAX)
    {
        // Get monochrome components
        color = *srcMonochrome;
        monoR = RED(color);
        color >>= 5;
        monoG = RED(color);
        color >>= 5;
        monoB = RED(color);

        // Get normal components
        color = *srcBase;
        baseR = RED(color);
        color >>= 5;
        baseG = RED(color);
        color >>= 5;
        baseB = RED(color);

        // Lerp the difference with the stage, clamp to max color value
        color = (monoR - baseR) * stage / (COLOR_MASK + 1);
        baseR += color;
        color = (monoG - baseG) * stage / (COLOR_MASK + 1);
        baseG += color;
        color = (monoB - baseB) * stage / (COLOR_MASK + 1);
        baseB += color;

        // Create color
        *dst = COLOR(baseR, baseG, baseB);

        i++;
        srcBase++;
        dst++;
        srcMonochrome++;
    }
}

/**
 * @brief 5b764 | cc | Applies a smooth transition between 2 palettes
 * 
 * @param srcStart Start palette pointer
 * @param srcEnd End palette pointer
 * @param dst Destination address
 * @param stage Stage
 */
void ApplySmoothPaletteTransition(u16* srcStart, u16* srcEnd, u16* dst, u8 stage)
{
    s32 i;
    s32 endR;
    s32 endG;
    s32 endB;
    u8 startR;
    u8 startG;
    u8 startB;
    s32 color;

    if (stage == 0)
    {
        DmaTransfer(3, srcStart, dst, 16 * 2, 16);
        return;
    }

    if (stage >= 0x1F)
    {
        do {
        DmaTransfer(3, srcEnd, dst, 16 * 2, 16);
        }while(0);
        return;
    }

    for (i = 0; i <= 0x1F; )
    {
        color = *srcEnd;
        endR = RED(color);
        color >>= 5;
        endG = RED(color);
        color >>= 5;
        endB = RED(color);

        do {
        color = *srcStart;
        }while(0);
        startR = RED(color);
        color >>= 5;
        startG = RED(color);
        color >>= 5;
        startB = RED(color);

        color = (endR - startR) * stage / (COLOR_MASK + 1);
        startR += color;
        color = (endG - startG) * stage / (COLOR_MASK + 1);
        startG += color;
        color = (endB - startB) * stage / (COLOR_MASK + 1);
        startB += color;

        *dst = COLOR(startR, startG, startB);

        i++;
        srcStart++;
        dst++;
        srcEnd++;
    }
}

/**
 * @brief 5b830 | 13c | Applies the color of a special fading to the background palette
 * 
 * @param mask Row mask
 * @param color Color
 * @param stage Stage
 */
void ApplySpecialBackgroundEffectColorOnBG(u16 mask, u16 color, u8 stage)
{
    s32 i;
    s32 j;
    s32 k;

    u8 r;
    u8 g;
    u8 b;

    s32 baseR;
    s32 baseG;
    s32 baseB;

    u16* pal;
    u16* src;
    u16* dst;

    s32 tmp;

    if (stage == 0)
    {
        DmaTransfer(3, EWRAM_BASE + 0x35800, PALRAM_BASE, 0x1E0, 16);
        DmaTransfer(3, EWRAM_BASE + 0x35800, EWRAM_BASE + 0x35400, 0x1E0, 16);
        return;
    }

    src = EWRAM_BASE + 0x35800;
    dst = EWRAM_BASE + 0x35000;
    DmaTransfer(3, src, dst, 0x1E0, 16);

    baseR = RED(color);
    baseG = GREEN(color);
    baseB = BLUE(color);

    for (i = 0; i < 16; i++)
    {
        if (!(mask >> i & 1))
            continue;

        tmp = i * 16;
        for (k = 0, j = i * 16; j < i * 16 + 16; k++, j++)
        {
            pal = dst;

            r = RED(pal[tmp + k]);
            g = GREEN(pal[tmp + k]);
            b = BLUE(pal[tmp + k]);

            r += (baseR - r) * stage / 16;
            g += (baseG - g) * stage / 16;
            b += (baseB - b) * stage / 16;

            pal[tmp + k] = COLOR(r, g, b);
        }
    }

    gColorFading.status |= COLOR_FADING_STATUS_ON_BG;
}

/**
 * @brief 5b96c | 140 | Applies the color of a special fading to the object palette
 * 
 * @param mask Row mask
 * @param color Color
 * @param stage Stage
 */
void ApplySpecialBackgroundEffectColorOnOBJ(u16 mask, u16 color, u8 stage)
{
    s32 i;
    s32 j;
    s32 k;

    u8 r;
    u8 g;
    u8 b;

    s32 baseR;
    s32 baseG;
    s32 baseB;

    u16* pal;
    s32 tmp;

    if (stage == 0)
    {
        DmaTransfer(3, EWRAM_BASE + 0x35A40, PALRAM_OBJ + 16 * 4, 0x1C0, 16);
        DmaTransfer(3, EWRAM_BASE + 0x35A40, EWRAM_BASE + 0x35640, 0x1C0, 16);
        return;
    }

    DmaTransfer(3, EWRAM_BASE + 0x35A40, EWRAM_BASE + 0x35240, 0x1C0, 16);

    baseR = RED(color);
    baseG = GREEN(color);
    baseB = BLUE(color);

    for (i = 0; i < 16; i++)
    {
        if (!(mask >> i & 1))
            continue;

        tmp = i * 16 + 1;
        for (k = 0, j = tmp; j < i * 16 + 16; k++, j++)
        {
            pal = COLOR_DATA_OBJ_EWRAM;

            r = RED(pal[tmp + k]);
            g = GREEN(pal[tmp + k]);
            b = BLUE(pal[tmp + k]);

            r += (baseR - r) * stage / 16;
            g += (baseG - g) * stage / 16;
            b += (baseB - b) * stage / 16;

            pal[tmp + k] = COLOR(r, g, b);
        }
    }

    gColorFading.status |= COLOR_FADING_STATUS_ON_OBJ;
}

/**
 * @brief 5baac | 13a | Applies the color change of a background fading
 * 
 * @param type Fading type
 * @param color Color
 * @param ppSrc Source address pointer
 * @param ppDst Destination address pointer
 * @param mask Palette rows mask
 */
void ApplySpecialBackgroundFadingColor(u8 type, u8 color, u16** ppSrc, u16** ppDst, u16 mask)
{
    s32 i;
    s32 j;
    s32 red;
    s32 green;
    s32 blue;

    for (i = 0; i < 16; i++)
    {
        if (!((mask >> i) & 1))
        {
            *ppSrc = *ppSrc + 16;
            *ppDst = *ppDst + 16;
            continue;
        }

        for (j = 0; j < 16; j++, *ppSrc = *ppSrc + 1, *ppDst = *ppDst + 1)
        {
            red = RED(**ppSrc);
            green = GREEN(**ppSrc);
            blue = BLUE(**ppSrc);

            switch (type)
            {
                case FADING_TYPE_IN:
                    red = (red * color) >> 5 & COLOR_MASK;
                    green = (green * color) >> 5 & COLOR_MASK;
                    blue = (blue * color) >> 5 & COLOR_MASK;
                    break;

                case FADING_TYPE_FLASH:
                    red = (COLOR_MASK - (((COLOR_MASK - red) * color) >> 5)) & COLOR_MASK;
                    green = (COLOR_MASK - (((COLOR_MASK - green) * color) >> 5)) & COLOR_MASK;
                    blue = (COLOR_MASK - (((COLOR_MASK - blue) * color) >> 5)) & COLOR_MASK;
                    break;

                case FADING_TYPE_OUT:
                    red = (red - ((red * color) >> 5)) & COLOR_MASK;
                    green = (green - ((green * color) >> 5)) & COLOR_MASK;
                    blue = (blue - ((blue * color) >> 5)) & COLOR_MASK;
                    break;

                case FADING_TYPE_UNK:
                    red = (red + ((color * (COLOR_MASK - red)) >> 5)) & COLOR_MASK;
                    green = (green + ((color * (COLOR_MASK - green)) >> 5)) & COLOR_MASK;
                    blue = (blue + ((color * (COLOR_MASK - blue)) >> 5)) & COLOR_MASK;
                    break;
            }

            **ppDst = COLOR_GRAD(red, green, blue);
        }
    }
}

u16 ApplyFadeOnColor(u8 type, u16 color, u8 currentColor)
{
    // https://decomp.me/scratch/RdwBt

    s32 red;
    s32 green;
    s32 blue;

    red = RED(color);
    green = GREEN(color);
    blue = BLUE(color);

    switch (type)
    {
        case FADING_TYPE_IN:
            red = (red * currentColor) >> 5 & COLOR_MASK;
            green = (green * currentColor) >> 5 & COLOR_MASK;
            blue = (blue * currentColor) >> 5 & COLOR_MASK;
            break;

        case FADING_TYPE_FLASH:
            red = (COLOR_MASK - (((COLOR_MASK - red) * currentColor) >> 5)) & COLOR_MASK;
            green = (COLOR_MASK - (((COLOR_MASK - green) * currentColor) >> 5)) & COLOR_MASK;
            blue = (COLOR_MASK - (((COLOR_MASK - blue) * currentColor) >> 5)) & COLOR_MASK;
            break;

        case FADING_TYPE_OUT:
            red = (red - ((red * currentColor) >> 5)) & COLOR_MASK;
            green = (green - ((green * currentColor) >> 5)) & COLOR_MASK;
            blue = (blue - ((blue * currentColor) >> 5)) & COLOR_MASK;
            break;

        case FADING_TYPE_UNK:
            red = (red + ((currentColor * (COLOR_MASK - red)) >> 5)) & COLOR_MASK;
            green = (green + ((currentColor * (COLOR_MASK - green)) >> 5)) & COLOR_MASK;
            blue = (blue + ((currentColor * (COLOR_MASK - blue)) >> 5)) & COLOR_MASK;
            break;
    }

    return COLOR_GRAD(red, green, blue);
}
