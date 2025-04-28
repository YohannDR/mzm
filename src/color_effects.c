#include "color_effects.h"
#include "macros.h"
#include "gba.h"

#include "data/color_fading_data.h"

#include "constants/color_fading.h"
#include "constants/game_state.h"

#include "structs/color_effects.h"
#include "structs/room.h"
#include "structs/game_state.h"

/**
 * @brief 5b24c | 3c | Transfers palette RAM to color data 2 RAM
 * 
 */
void unk_5b24c(void)
{
    DmaTransfer(3, PALRAM_BASE, COLOR_DATA_BG_EWRAM2, PAL_SIZE, 16);
    DmaTransfer(3, PALRAM_OBJ, COLOR_DATA_OBJ_EWRAM2, PAL_SIZE, 16);
}

/**
 * @brief 5b288 | 3c | Transfers palette RAM to color data 1 RAM
 * 
 */
void unk_5b288(void)
{
    DmaTransfer(3, PALRAM_BASE, COLOR_DATA_BG_EWRAM, PAL_SIZE, 16);
    DmaTransfer(3, PALRAM_OBJ, COLOR_DATA_OBJ_EWRAM, PAL_SIZE, 16);
}

/**
 * @brief 5b2c4 | 3c | Transfers color data 2 RAM to color data 1 RAM
 * 
 */
void unk_5b2c4(void)
{
    DmaTransfer(3, COLOR_DATA_BG_EWRAM2, COLOR_DATA_BG_EWRAM, PAL_SIZE, 16);
    DmaTransfer(3, COLOR_DATA_OBJ_EWRAM2, COLOR_DATA_OBJ_EWRAM, PAL_SIZE, 16);
}

/**
 * @brief 5b304 | 3c | Transfers palette RAM to color data 3 RAM
 * 
 */
void unk_5b304(void)
{
    DmaTransfer(3, PALRAM_BASE, COLOR_DATA_BG_EWRAM3, PAL_SIZE, 16);
    DmaTransfer(3, PALRAM_OBJ, COLOR_DATA_OBJ_EWRAM3, PAL_SIZE, 16);
}

/**
 * @brief 5b340 | 10 | Transfers palette RAM to color data 1 and 2 RAM
 * 
 */
void unk_5b340(void)
{
    unk_5b24c();
    unk_5b288();
}

/**
 * @brief 5b350 | 3c | Transfers color data 2 RAM to color data 1 RAM
 * 
 */
void unk_5b350(void)
{
    DmaTransfer(3, COLOR_DATA_BG_EWRAM2, COLOR_DATA_BG_EWRAM3, PAL_SIZE, 16);
    DmaTransfer(3, COLOR_DATA_OBJ_EWRAM2, COLOR_DATA_OBJ_EWRAM3, PAL_SIZE, 16);
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
        DmaTransfer(3, COLOR_DATA_BG_EWRAM, PALRAM_BASE, PAL_SIZE, 16);
        gColorFading.status &= ~COLOR_FADING_STATUS_ON_BG;
    }

    if (gColorFading.status & COLOR_FADING_STATUS_ON_OBJ)
    {
        DmaTransfer(3, COLOR_DATA_OBJ_EWRAM, PALRAM_OBJ, PAL_SIZE, 16);
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
            DmaTransfer(3, COLOR_DATA_BG_EWRAM, PALRAM_BASE, PAL_SIZE, 16);
            gColorFading.status ^= COLOR_FADING_STATUS_ON_BG;
        }

        if (gColorFading.status & COLOR_FADING_STATUS_ON_OBJ)
        {
            DmaTransfer(3, COLOR_DATA_OBJ_EWRAM + 2 * PAL_ROW, (u16*)PALRAM_OBJ + 2 * PAL_ROW, PAL_SIZE - 2 * PAL_ROW_SIZE, 16);
            gColorFading.status ^= COLOR_FADING_STATUS_ON_OBJ;
        }
    }
    else
    {
        if (gColorFading.status == 0)
            return;

        if (gColorFading.status & COLOR_FADING_STATUS_ON_BG)
        {
            DmaTransfer(3, COLOR_DATA_BG_EWRAM, PALRAM_BASE, PAL_SIZE, 16);
            gColorFading.status &= ~COLOR_FADING_STATUS_ON_BG;
        }

        if (gColorFading.status & COLOR_FADING_STATUS_ON_OBJ)
        {
            DmaTransfer(3, COLOR_DATA_OBJ_EWRAM, PALRAM_OBJ, PAL_SIZE, 16);
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
            type = COLOR_FADING_TYPE_FLASH;
        else
            type = COLOR_FADING_TYPE_UNK;
    }
    else
    {
        if (!gColorFading.useSecondColorSet)
            type = COLOR_FADING_TYPE_IN;
        else
            type = COLOR_FADING_TYPE_OUT;
    }

    dst = COLOR_DATA_BG_EWRAM;
    src = COLOR_DATA_BG_EWRAM2;
    mask = sColorFadingData[gColorFading.type].bgColorMask;
    ApplySpecialBackgroundFadingColor(type, color, &src, &dst, mask);

    dst = COLOR_DATA_OBJ_EWRAM;
    src = COLOR_DATA_OBJ_EWRAM2;
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
        length = COLORS_IN_PAL;
    }
    else
    {
        // Omit last row, where the animated palette is
        length = COLORS_IN_PAL - 1 * PAL_ROW;
    }

    // Get palram
    DmaTransfer(3, PALRAM_BASE, COLOR_DATA_BG_EWRAM, PAL_SIZE, 16);

    // Get starting position
    pPalette = COLOR_DATA_BG_EWRAM + paletteRow * PAL_ROW;

    for (i = paletteRow * PAL_ROW; i < length; i++, pPalette++)
    {
        // Ignore first color (transparent color)
        if (i % PAL_ROW == 0)
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
 * @brief 5b624 | 68 | Applies a monochrome effect to a palette
 * 
 * @param src Source address
 * @param dst Destination address
 * @param additionalValue Additional color
 */
void ApplyMonochromeToPalette(const u16* src, u16* dst, s8 additionalValue)
{
    s32 i;
    s32 result;
    u16 r;
    u16 g;
    u16 b;

    for (i = 0; i < COLORS_IN_PAL; i++, src++, dst++)
    {
        r = RED(*src);
        g = GREEN(*src);
        b = BLUE(*src);

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
        DmaTransfer(3, srcBase, dst, PAL_SIZE, 16);
        return;
    }
    
    if (stage >= 31)
    {
        // Transition is done, simply use the monochrome
        DmaTransfer(3, srcMonochrome, dst, PAL_SIZE, 16);
        return;
    }
    
    i = 0;
    while (i < COLORS_IN_PAL)
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
        DmaTransfer(3, srcStart, dst, 1 * PAL_ROW_SIZE, 16);
        return;
    }

    if (stage >= 0x1F)
    {
        do {
        DmaTransfer(3, srcEnd, dst, 1 * PAL_ROW_SIZE, 16);
        }while(0);
        return;
    }

    for (i = 0; i < 2 * PAL_ROW; )
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
        DmaTransfer(3, COLOR_DATA_BG_EWRAM3, PALRAM_BASE, PAL_SIZE - 1 * PAL_ROW_SIZE, 16);
        DmaTransfer(3, COLOR_DATA_BG_EWRAM3, COLOR_DATA_BG_EWRAM2, PAL_SIZE - 1 * PAL_ROW_SIZE, 16);
        return;
    }

    src = COLOR_DATA_BG_EWRAM3;
    dst = COLOR_DATA_BG_EWRAM;
    DmaTransfer(3, src, dst, PAL_SIZE - 1 * PAL_ROW_SIZE, 16);

    baseR = RED(color);
    baseG = GREEN(color);
    baseB = BLUE(color);

    for (i = 0; i < COLORS_IN_PAL / PAL_ROW; i++)
    {
        if (!(mask >> i & 1))
            continue;

        tmp = i * PAL_ROW;
        for (k = 0, j = i * PAL_ROW; j < i * PAL_ROW + PAL_ROW; k++, j++)
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
        DmaTransfer(3, COLOR_DATA_OBJ_EWRAM3 + 2 * PAL_ROW, (u16*)PALRAM_OBJ + 2 * PAL_ROW, PAL_SIZE - 2 * PAL_ROW_SIZE, 16);
        DmaTransfer(3, COLOR_DATA_OBJ_EWRAM3 + 2 * PAL_ROW, COLOR_DATA_OBJ_EWRAM2 + 2 * PAL_ROW, PAL_SIZE - 2 * PAL_ROW_SIZE, 16);
        return;
    }

    DmaTransfer(3, COLOR_DATA_OBJ_EWRAM3 + 2 * PAL_ROW, COLOR_DATA_OBJ_EWRAM + 2 * PAL_ROW, PAL_SIZE - 2 * PAL_ROW_SIZE, 16);

    baseR = RED(color);
    baseG = GREEN(color);
    baseB = BLUE(color);

    for (i = 0; i < COLORS_IN_PAL / PAL_ROW; i++)
    {
        if (!(mask >> i & 1))
            continue;

        tmp = i * PAL_ROW + 1;
        for (k = 0, j = tmp; j < i * PAL_ROW + PAL_ROW; k++, j++)
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

    for (i = 0; i < COLORS_IN_PAL / PAL_ROW; i++)
    {
        if (!((mask >> i) & 1))
        {
            *ppSrc = *ppSrc + PAL_ROW;
            *ppDst = *ppDst + PAL_ROW;
            continue;
        }

        for (j = 0; j < PAL_ROW; j++, *ppSrc = *ppSrc + 1, *ppDst = *ppDst + 1)
        {
            red = RED(**ppSrc);
            green = GREEN(**ppSrc);
            blue = BLUE(**ppSrc);

            switch (type)
            {
                case COLOR_FADING_TYPE_IN:
                    red = (red * color) >> 5 & COLOR_MASK;
                    green = (green * color) >> 5 & COLOR_MASK;
                    blue = (blue * color) >> 5 & COLOR_MASK;
                    break;

                case COLOR_FADING_TYPE_FLASH:
                    red = (COLOR_MASK - (((COLOR_MASK - red) * color) >> 5)) & COLOR_MASK;
                    green = (COLOR_MASK - (((COLOR_MASK - green) * color) >> 5)) & COLOR_MASK;
                    blue = (COLOR_MASK - (((COLOR_MASK - blue) * color) >> 5)) & COLOR_MASK;
                    break;

                case COLOR_FADING_TYPE_OUT:
                    red = (red - ((red * color) >> 5)) & COLOR_MASK;
                    green = (green - ((green * color) >> 5)) & COLOR_MASK;
                    blue = (blue - ((blue * color) >> 5)) & COLOR_MASK;
                    break;

                case COLOR_FADING_TYPE_UNK:
                    red = (red + ((color * (COLOR_MASK - red)) >> 5)) & COLOR_MASK;
                    green = (green + ((color * (COLOR_MASK - green)) >> 5)) & COLOR_MASK;
                    blue = (blue + ((color * (COLOR_MASK - blue)) >> 5)) & COLOR_MASK;
                    break;
            }

            **ppDst = COLOR_GRAD(red, green, blue);
        }
    }
}

/**
 * @brief 5bbe4 | cc | Applies a fade effect on a color, unused
 * 
 * @param type Fading type
 * @param color Color
 * @param currentColor Current color
 */
u16 ApplyFadeOnColor(u8 type, u16 color, u8 currentColor)
{
    u8 red;
    u8 green;
    u8 blue;

    u32 tmp_red;

    tmp_red = RED(color);
    red = tmp_red; // Needed to produce matching ASM.
    green = GREEN(color);
    blue = BLUE(color);

    switch (type)
    {
        case COLOR_FADING_TYPE_IN:
            red = (red * currentColor) >> 5 & COLOR_MASK;
            green = (green * currentColor) >> 5 & COLOR_MASK;
            blue = (blue * currentColor) >> 5 & COLOR_MASK;
            break;

        case COLOR_FADING_TYPE_FLASH:
            red = (COLOR_MASK - (((COLOR_MASK - red) * currentColor) >> 5)) & COLOR_MASK;
            green = (COLOR_MASK - (((COLOR_MASK - green) * currentColor) >> 5)) & COLOR_MASK;
            blue = (COLOR_MASK - (((COLOR_MASK - blue) * currentColor) >> 5)) & COLOR_MASK;
            break;

        case COLOR_FADING_TYPE_OUT:
            red = (red - ((red * currentColor) >> 5)) & COLOR_MASK;
            green = (green - ((green * currentColor) >> 5)) & COLOR_MASK;
            blue = (blue - ((blue * currentColor) >> 5)) & COLOR_MASK;
            break;

        case COLOR_FADING_TYPE_UNK:
            red = (red + ((currentColor * (COLOR_MASK - red)) >> 5)) & COLOR_MASK;
            green = (green + ((currentColor * (COLOR_MASK - green)) >> 5)) & COLOR_MASK;
            blue = (blue + ((currentColor * (COLOR_MASK - blue)) >> 5)) & COLOR_MASK;
            break;
    }

    return COLOR_GRAD(red, green, blue);
}
