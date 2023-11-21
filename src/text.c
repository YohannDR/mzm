#include "text.h"
#include "gba.h"
#include "macros.h"

#include "data/text_data.h"
#include "data/text_pointers.h"
#include "data/internal_text_data.h"
#include "data/shortcut_pointers.h"
#include "data/menus/pause_screen_data.h"
#include "data/cutscenes/internal_story_text_cutscene_data.h"

#include "constants/text.h"
#include "constants/menus/pause_screen.h"

#include "structs/game_state.h"
#include "structs/menus/pause_screen.h"

/**
 * @brief 6e460 | 24 | Gets the width of a character
 * 
 * @param charID Character
 * @return u8 Width
 */
u32 TextGetCharacterWidth(u16 charID)
{
    if (charID >= ARRAY_SIZE(sCharacterWidths))
        return 10;
    else
        return sCharacterWidths[charID];
}

/**
 * @brief 6e484 | 4b8 | Draws a character in append mode
 * 
 * @param charID Character
 * @param dst Destination address
 * @param indent Indent
 * @param color Color
 */
void TextDrawCharacter(u16 charID, u32* dst, u16 indent, u8 color)
{
    s32 palette;
    u32* dstGfx;
    const u32* srcGfx;
    s32 size;
    u32 pixelSrc;
    u32 pixelDst;
    u8 width;
    s32 pass;
    u32 value;
    s32 i;

    BitFill(3, 0, gCurrentCharacterGfx, sizeof(gCurrentCharacterGfx), 0x10);
    width = TextGetCharacterWidth(charID);

    for (pass = 0; pass < 2; pass++)
    {
        if (pass != 0)
            dstGfx = gCurrentCharacterGfx + 16;
        else
            dstGfx = gCurrentCharacterGfx;

        pixelSrc = charID * 32 + pass * 0x400;
        srcGfx = (const u32*)&sCharactersGfx[pixelSrc];
        
        if (width > 8)
            size = 16;
        else
            size = 8;

        if (color != 0)
        {
            for (i = 0; i < size; i++, dstGfx++, srcGfx++)
            {
                pixelSrc = *srcGfx;
                
                if (pixelSrc == 0)
                    continue;
                    
                pixelDst = 0;
                if (color != 0)
                    palette = color;
                else
                    palette = 4;

                value = pixelSrc & sArray_760338[0];
                if (value)
                {
                    if (value & sArray_760398[0])
                        pixelDst |= palette;
                    else
                        pixelDst |= value;
                }
                palette <<= 4;

                value = pixelSrc & sArray_760338[1];
                if (value)
                {
                    if (value & sArray_760398[1])
                        pixelDst |= palette;
                    else
                        pixelDst |= value;
                }
                palette <<= 4;

                value = pixelSrc & sArray_760338[2];
                if (value)
                {
                    if (value & sArray_760398[2])
                        pixelDst |= palette;
                    else
                        pixelDst |= value;
                }
                palette <<= 4;

                value = pixelSrc & sArray_760338[3];
                if (value)
                {
                    if (value & sArray_760398[3])
                        pixelDst |= palette;
                    else
                        pixelDst |= value;
                }
                palette <<= 4;

                value = pixelSrc & sArray_760338[4];
                if (value)
                {
                    if (value & sArray_760398[4])
                        pixelDst |= palette;
                    else
                        pixelDst |= value;
                }
                palette <<= 4;

                value = pixelSrc & sArray_760338[5];
                if (value)
                {
                    if (value & sArray_760398[5])
                        pixelDst |= palette;
                    else
                        pixelDst |= value;
                }
                palette <<= 4;

                value = pixelSrc & sArray_760338[6];
                if (value)
                {
                    if (value & sArray_760398[6])
                        pixelDst |= palette;
                    else
                        pixelDst |= value;
                }
                palette <<= 4;

                value = pixelSrc & sArray_760338[7];
                if (value)
                {
                    if (value & sArray_760398[7])
                        pixelDst |= palette;
                    else
                        pixelDst |= value;
                }

                *dstGfx = pixelDst;
            }
        }
        else
            DmaTransfer(3, srcGfx, dstGfx, size * 4, 16);

        dstGfx = dst + ((indent & 0xFF) / 8) * 8 + pass * 0x100;
        dstGfx += (indent / 256) * 0x200;
        if (pass != 0)
            srcGfx = gCurrentCharacterGfx + 16;
        else
            srcGfx = gCurrentCharacterGfx;

        palette = indent & 7;

        if (palette != 0)
        {
            pixelSrc = palette * 4;
            size = 32 - pixelSrc;

            if (palette + width > 8)
            {
                value = srcGfx[0];
                dstGfx[0] |= value << pixelSrc;
                dstGfx[8] |= value >> size;
                value = srcGfx[1];
                dstGfx[1] |= value << pixelSrc;
                dstGfx[9] |= value >> size;
                value = srcGfx[2];
                dstGfx[2] |= value << pixelSrc;
                dstGfx[10] |= value >> size;
                value = srcGfx[3];
                dstGfx[3] |= value << pixelSrc;
                dstGfx[11] |= value >> size;
                value = srcGfx[4];
                dstGfx[4] |= value << pixelSrc;
                dstGfx[12] |= value >> size;
                value = srcGfx[5];
                dstGfx[5] |= value << pixelSrc;
                dstGfx[13] |= value >> size;
                value = srcGfx[6];
                dstGfx[6] |= value << pixelSrc;
                dstGfx[14] |= value >> size;
                value = srcGfx[7];
                dstGfx[7] |= value << pixelSrc;
                dstGfx[15] |= value >> size;

                if (width > 8)
                {
                    if (palette + width > 16)
                    {
                        value = srcGfx[8];
                        dstGfx[8] |= value << pixelSrc;
                        dstGfx[16] |= value >> size;
                        value = srcGfx[9];
                        dstGfx[9] |= value << pixelSrc;
                        dstGfx[17] |= value >> size;
                        value = srcGfx[10];
                        dstGfx[10] |= value << pixelSrc;
                        dstGfx[18] |= value >> size;
                        value = srcGfx[11];
                        dstGfx[11] |= value << pixelSrc;
                        dstGfx[19] |= value >> size;
                        value = srcGfx[12];
                        dstGfx[12] |= value << pixelSrc;
                        dstGfx[20] |= value >> size;
                        value = srcGfx[13];
                        dstGfx[13] |= value << pixelSrc;
                        dstGfx[21] |= value >> size;
                        value = srcGfx[14];
                        dstGfx[14] |= value << pixelSrc;
                        dstGfx[22] |= value >> size;
                        value = srcGfx[15];
                        dstGfx[15] |= value << pixelSrc;
                        dstGfx[23] |= value >> size;
                    }
                    else
                    {
                        dstGfx[8] |= srcGfx[8] << pixelSrc;
                        dstGfx[9] |= srcGfx[9] << pixelSrc;
                        dstGfx[10] |= srcGfx[10] << pixelSrc;
                        dstGfx[11] |= srcGfx[11] << pixelSrc;
                        dstGfx[12] |= srcGfx[12] << pixelSrc;
                        dstGfx[13] |= srcGfx[13] << pixelSrc;
                        dstGfx[14] |= srcGfx[14] << pixelSrc;
                        dstGfx[15] |= srcGfx[15] << pixelSrc;
                    }
                }
            }
            else
            {
                dstGfx[0] |= srcGfx[0] << pixelSrc;
                dstGfx[1] |= srcGfx[1] << pixelSrc;
                dstGfx[2] |= srcGfx[2] << pixelSrc;
                dstGfx[3] |= srcGfx[3] << pixelSrc;
                dstGfx[4] |= srcGfx[4] << pixelSrc;
                dstGfx[5] |= srcGfx[5] << pixelSrc;
                dstGfx[6] |= srcGfx[6] << pixelSrc;
                dstGfx[7] |= srcGfx[7] << pixelSrc;
            }
        }
        else
        {
            dstGfx[0] |= srcGfx[0];
            dstGfx[1] |= srcGfx[1];
            dstGfx[2] |= srcGfx[2];
            dstGfx[3] |= srcGfx[3];
            dstGfx[4] |= srcGfx[4];
            dstGfx[5] |= srcGfx[5];
            dstGfx[6] |= srcGfx[6];
            dstGfx[7] |= srcGfx[7];

            if (width > 8)
            {
                dstGfx[8] |= srcGfx[8];
                dstGfx[9] |= srcGfx[9];
                dstGfx[10] |= srcGfx[10];
                dstGfx[11] |= srcGfx[11];
                dstGfx[12] |= srcGfx[12];
                dstGfx[13] |= srcGfx[13];
                dstGfx[14] |= srcGfx[14];
                dstGfx[15] |= srcGfx[15];
            }
        }
    }
}

/**
 * @brief 6e93c | 5f0 | Draws a character in mask mode
 * 
 * @param charID Character
 * @param dst Destination address
 * @param indent Indent
 * @param color Color
 */
void TextDrawMessageCharacter(u16 charID, u32* dst, u16 indent, u8 color)
{
    s32 palette;
    u32* dstGfx;
    const u32* srcGfx;
    s32 pass;
    s32 size;
    u32 pixelSrc;
    u32 pixelDst;
    u8 width;
    u32 value;
    s32 i;

    BitFill(3, 0, 0x2027700, sizeof(gCurrentCharacterGfx), 16);
    width = TextGetCharacterWidth(charID);

    for (pass = 0; pass < 2; pass++)
    {
        if (pass != 0)
            dstGfx = ((u32*)0x2027700) + 16;
        else
            dstGfx = ((u32*)0x2027700);

        pixelDst = charID * 0x20 + pass * 0x400;
        srcGfx = (const u32*)&sCharactersGfx[pixelDst];
        
        if (width > 8)
            size = 16;
        else
            size = 8;

        for (i = 0; i < size; i++, srcGfx++)
        {
            pixelSrc = *srcGfx;
            
            pixelDst = 0;
            if (color != 0)
                palette = color;
            else
                palette = 4;

            value = pixelSrc & sArray_760338[0];
            if (value)
            {
                if (value & sArray_760398[0])
                    pixelDst |= palette;
                else
                    pixelDst |= value;
            }
            else
                pixelDst |= sArray_7603b8[0];
            palette <<= 4;

            value = pixelSrc & sArray_760338[1];
            if (value)
            {
                if (value & sArray_760398[1])
                    pixelDst |= palette;
                else
                    pixelDst |= value;
            }
            else
                pixelDst |= sArray_7603b8[1];
            palette <<= 4;

            value = pixelSrc & sArray_760338[2];
            if (value)
            {
                if (value & sArray_760398[2])
                    pixelDst |= palette;
                else
                    pixelDst |= value;
            }
            else
                pixelDst |= sArray_7603b8[2];
            palette <<= 4;

            value = pixelSrc & sArray_760338[3];
            if (value)
            {
                if (value & sArray_760398[3])
                    pixelDst |= palette;
                else
                    pixelDst |= value;
            }
            else
                pixelDst |= sArray_7603b8[3];
            palette <<= 4;

            value = pixelSrc & sArray_760338[4];
            if (value)
            {
                if (value & sArray_760398[4])
                    pixelDst |= palette;
                else
                    pixelDst |= value;
            }
            else
                pixelDst |= sArray_7603b8[4];
            palette <<= 4;

            value = pixelSrc & sArray_760338[5];
            if (value)
            {
                if (value & sArray_760398[5])
                    pixelDst |= palette;
                else
                    pixelDst |= value;
            }
            else
                pixelDst |= sArray_7603b8[5];
            palette <<= 4;

            value = pixelSrc & sArray_760338[6];
            if (value)
            {
                if (value & sArray_760398[6])
                    pixelDst |= palette;
                else
                    pixelDst |= value;
            }
            else
                pixelDst |= sArray_7603b8[6];
            palette <<= 4;

            value = pixelSrc & sArray_760338[7];
            if (value)
            {
                if (value & sArray_760398[7])
                    pixelDst |= palette;
                else
                    pixelDst |= value;
            }
            else
                pixelDst |= sArray_7603b8[7];

            *dstGfx++ = pixelDst;
        }

        dstGfx = dst + ((indent & 0xFF) / 8) * 8 + pass * 0x100;
        dstGfx += (indent / 256) * 0x200;
        if (pass != 0)
            srcGfx = gCurrentCharacterGfx + 16;
        else
            srcGfx = gCurrentCharacterGfx;

        palette = indent & 7;

        if (palette != 0)
        {
            pixelDst = palette * 4;
            i = 8 - palette;
            size = 32 - pixelDst;

            if (palette + width > 8)
            {
                value = srcGfx[0];
                dstGfx[0] &= (value << pixelDst) | sArray_7602f0[palette];
                dstGfx[8] &= (value >> size) | sArray_760314[i];
                value = srcGfx[1];
                dstGfx[1] &= (value << pixelDst) | sArray_7602f0[palette];
                dstGfx[9] &= (value >> size) | sArray_760314[i];
                value = srcGfx[2];
                dstGfx[2] &= (value << pixelDst) | sArray_7602f0[palette];
                dstGfx[10] &= (value >> size) | sArray_760314[i];
                value = srcGfx[3];
                dstGfx[3] &= (value << pixelDst) | sArray_7602f0[palette];
                dstGfx[11] &= (value >> size) | sArray_760314[i];
                value = srcGfx[4];
                dstGfx[4] &= (value << pixelDst) | sArray_7602f0[palette];
                dstGfx[12] &= (value >> size) | sArray_760314[i];
                value = srcGfx[5];
                dstGfx[5] &= (value << pixelDst) | sArray_7602f0[palette];
                dstGfx[13] &= (value >> size) | sArray_760314[i];
                value = srcGfx[6];
                dstGfx[6] &= (value << pixelDst) | sArray_7602f0[palette];
                dstGfx[14] &= (value >> size) | sArray_760314[i];
                value = srcGfx[7];
                dstGfx[7] &= (value << pixelDst) | sArray_7602f0[palette];
                dstGfx[15] &= (value >> size) | sArray_760314[i];

                if (width > 8)
                {
                    if (palette + width > 16)
                    {
                        value = srcGfx[8];
                        dstGfx[8] &= (value << pixelDst) | sArray_7602f0[palette];
                        dstGfx[16] &= (value >> size) | sArray_760314[i];
                        value = srcGfx[9];
                        dstGfx[9] &= (value << pixelDst) | sArray_7602f0[palette];
                        dstGfx[17] &= (value >> size) | sArray_760314[i];
                        value = srcGfx[10];
                        dstGfx[10] &= (value << pixelDst) | sArray_7602f0[palette];
                        dstGfx[18] &= (value >> size) | sArray_760314[i];
                        value = srcGfx[11];
                        dstGfx[11] &= (value << pixelDst) | sArray_7602f0[palette];
                        dstGfx[19] &= (value >> size) | sArray_760314[i];
                        value = srcGfx[12];
                        dstGfx[12] &= (value << pixelDst) | sArray_7602f0[palette];
                        dstGfx[20] &= (value >> size) | sArray_760314[i];
                        value = srcGfx[13];
                        dstGfx[13] &= (value << pixelDst) | sArray_7602f0[palette];
                        dstGfx[21] &= (value >> size) | sArray_760314[i];
                        value = srcGfx[14];
                        dstGfx[14] &= (value << pixelDst) | sArray_7602f0[palette];
                        dstGfx[22] &= (value >> size) | sArray_760314[i];
                        value = srcGfx[15];
                        dstGfx[15] &= (value << pixelDst) | sArray_7602f0[palette];
                        dstGfx[23] &= (value >> size) | sArray_760314[i];
                    }
                    else
                    {
                        dstGfx[8] &= (srcGfx[8] << pixelDst) | sArray_7602f0[palette];
                        dstGfx[9] &= (srcGfx[9] << pixelDst) | sArray_7602f0[palette];
                        dstGfx[10] &= (srcGfx[10] << pixelDst) | sArray_7602f0[palette];
                        dstGfx[11] &= (srcGfx[11] << pixelDst) | sArray_7602f0[palette];
                        dstGfx[12] &= (srcGfx[12] << pixelDst) | sArray_7602f0[palette];
                        dstGfx[13] &= (srcGfx[13] << pixelDst) | sArray_7602f0[palette];
                        dstGfx[14] &= (srcGfx[14] << pixelDst) | sArray_7602f0[palette];
                        dstGfx[15] &= (srcGfx[15] << pixelDst) | sArray_7602f0[palette];
                    }
                }
            }
            else
            {
                dstGfx[0] &= (srcGfx[0] << pixelDst) | sArray_7602f0[palette];
                dstGfx[1] &= (srcGfx[1] << pixelDst) | sArray_7602f0[palette];
                dstGfx[2] &= (srcGfx[2] << pixelDst) | sArray_7602f0[palette];
                dstGfx[3] &= (srcGfx[3] << pixelDst) | sArray_7602f0[palette];
                dstGfx[4] &= (srcGfx[4] << pixelDst) | sArray_7602f0[palette];
                dstGfx[5] &= (srcGfx[5] << pixelDst) | sArray_7602f0[palette];
                dstGfx[6] &= (srcGfx[6] << pixelDst) | sArray_7602f0[palette];
                dstGfx[7] &= (srcGfx[7] << pixelDst) | sArray_7602f0[palette];
            }
        }
        else
        {
            dstGfx[0] &= srcGfx[0];
            dstGfx[1] &= srcGfx[1];
            dstGfx[2] &= srcGfx[2];
            dstGfx[3] &= srcGfx[3];
            dstGfx[4] &= srcGfx[4];
            dstGfx[5] &= srcGfx[5];
            dstGfx[6] &= srcGfx[6];
            dstGfx[7] &= srcGfx[7];

            if (width > 8)
            {
                dstGfx[8] &= srcGfx[8];
                dstGfx[9] &= srcGfx[9];
                dstGfx[10] &= srcGfx[10];
                dstGfx[11] &= srcGfx[11];
                dstGfx[12] &= srcGfx[12];
                dstGfx[13] &= srcGfx[13];
                dstGfx[14] &= srcGfx[14];
                dstGfx[15] &= srcGfx[15];
            }
        }
    }
}

/**
 * @brief 6ef2c | ec | Draws the location text characters
 * 
 * @param param_1 To document
 * @param ppText Pointer to text pointer
 */
void TextDrawLocationTextCharacters(u8 param_1, const u16** ppText)
{
    u32* dst;
    u32 indent;
    u32 color;
    u32 drawFlag;
    u32 width;

    if (param_1 == 1)
        dst = EWRAM_BASE;
    else if (param_1 == 2)
    {
        dst = EWRAM_BASE + 0x800;

        while (**ppText != CHAR_NEW_LINE)
        {
            *ppText = *ppText + 1;
        }

        *ppText = *ppText + 1;
    }
    else
        return;

    indent = 0;
    color = 0;

    while (**ppText != CHAR_TERMINATOR && **ppText != CHAR_NEW_LINE)
    {
        drawFlag = TRUE;

        if ((**ppText & CHAR_MASK) == CHAR_WIDTH_MASK)
        {
            width = **ppText & 0xFF;
            drawFlag = FALSE;
        }
        else if ((**ppText & CHAR_MASK) == CHAR_INDENT_MASK)
        {
            width = 0;
            indent = **ppText & 0xFF;
            drawFlag = FALSE;
        }
        else if ((**ppText & CHAR_MASK) == CHAR_COLOR_MASK)
        {
            width = 0;
            color = **ppText & 0xFF;
            drawFlag = FALSE;
        }

        if (drawFlag)
        {
            width = TextGetCharacterWidth(**ppText);
            TextDrawMessageCharacter(**ppText, dst, indent, color);
        }

        *ppText = *ppText + 1;
        indent += width;
    }
}

/**
 * @brief 6f018 | 90 | Draws a location text
 * 
 * @param locationText 
 * @param gfxSlot 
 */
void TextDrawlocation(u8 locationText, u8 gfxSlot)
{
    const u16* pText;

    BitFill(3, 0xFFFF, EWRAM_BASE, 0x800, 0x10);

    pText = sLocationTextPointers[gLanguage][locationText];
    TextDrawLocationTextCharacters(1, &pText);

    DMA_SET(3, EWRAM_BASE, VRAM_BASE + 0x14000 + gfxSlot * 0x800, (DMA_ENABLE | DMA_32BIT) << 16 | 0xE0);
    DMA_SET(3, EWRAM_BASE + 0x400, VRAM_BASE + 0x14400 + gfxSlot * 0x800, (DMA_ENABLE | DMA_32BIT) << 16 | 0xE0);
}

/**
 * @brief 6f0a8 | 1b0 | To document
 * 
 * @param textID Message ID
 * @param gfxSlot Gfx slot
 * @param param_3 To document
 * @return u8 To document
 */
u8 unk_6f0a8(u8 textID, u8 gfxSlot, u8 param_3)
{
    s32 i;
    s32 flag;

    if (param_3 == 0xF)
    {
        gCurrentMessage = sMessage_Empty;
        
        gCurrentMessage.messageID = textID > MESSAGE_ENEMY_LOCATION_ABNORMAL ? MESSAGE_ENEMY_LOCATION_ABNORMAL : textID;
        gCurrentMessage.gfxSlot = gfxSlot;
    }

    switch (gCurrentMessage.stage)
    {
        case 0:
            BitFill(3, -1, VRAM_BASE + 0x14000 + gCurrentMessage.gfxSlot * 0x800, 0x380, 32);
            BitFill(3, -1, VRAM_BASE + 0x14400 + gCurrentMessage.gfxSlot * 0x800, 0x380, 32);
            gCurrentMessage.stage++;
            break;

        case 1:
            BitFill(3, -1, VRAM_BASE + 0x14800 + gCurrentMessage.gfxSlot * 0x800, 0x380, 32);
            BitFill(3, -1, VRAM_BASE + 0x14C00 + gCurrentMessage.gfxSlot * 0x800, 0x380, 32);
            gCurrentMessage.stage++;
            break;

        case 2:
            i = 8;
            if (gCurrentMessage.line > 1 || gCurrentMessage.messageEnded)
            {
                gCurrentMessage.stage++;
                i = 0;
            }

            if (param_3 == 1)
            {
                gCurrentMessage.stage++;
                i = 0;
            }

            for (; i != 0; i--)
            {
                switch (TextProcessCurrentMessage(&gCurrentMessage, sMessageTextPointers[gLanguage][gCurrentMessage.messageID],
                    VRAM_BASE + 0x14000 + gCurrentMessage.gfxSlot * 0x800 + gCurrentMessage.line * 0x800))
                {
                    case TEXT_STATE_ENDED:
                        gCurrentMessage.stage++;

                    case TEXT_STATE_NEW_LINE:
                    case TEXT_STATE_NEW_PAGE:
                        gCurrentMessage.indent = 0;
                        flag = TRUE;
                        break;

                    default:
                        flag = FALSE;
                }

                if (flag || gCurrentMessage.line > 1)
                    break;
            }
            break;

        case 3:
            gCurrentMessage.line++;
            if (gCurrentMessage.messageID <= MESSAGE_POWER_GRIP)
            {
                gCurrentItemBeingAcquired = gCurrentMessage.messageID;
                if (gCurrentMessage.messageID >= MESSAGE_LONG_BEAM)
                    BgClipFinishCollectingAbility();
            }
            gCurrentMessage.stage++;

        case 4:
        default:
            return gCurrentMessage.line;
    }

    return 0;
}

/**
 * @brief 6f258 | 34 | Starts a new message
 * 
 * @param textID Text ID
 * @param gfxSlot Graphics slot
 */
void TextStartMessage(u8 textID, u8 gfxSlot)
{
    gCurrentMessage = sMessage_Empty;

    gCurrentMessage.messageID = textID > MESSAGE_ENEMY_LOCATION_ABNORMAL ? MESSAGE_ENEMY_LOCATION_ABNORMAL : textID;
    gCurrentMessage.gfxSlot = gfxSlot;
}

/**
 * @brief 6f28c | 178 | Processes an item banner text
 * 
 * @return u8 Current line
 */
u8 TextProcessItemBanner(void)
{
    s32 i;
    u32 flag;

    switch (gCurrentMessage.stage)
    {
        case 0:
            BitFill(3, -1, VRAM_BASE + 0x14000 + gCurrentMessage.gfxSlot * 0x800, 0x380, 32);
            BitFill(3, -1, VRAM_BASE + 0x14400 + gCurrentMessage.gfxSlot * 0x800, 0x380, 32);

            gCurrentMessage.stage++;
            break;

        case 1:
            BitFill(3, -1, VRAM_BASE + 0x14800 + gCurrentMessage.gfxSlot * 0x800, 0x380, 32);
            BitFill(3, -1, VRAM_BASE + 0x14C00 + gCurrentMessage.gfxSlot * 0x800, 0x380, 32);
            
            gCurrentMessage.stage++;
            break;

        case 2:
            i = 8;
            if (gCurrentMessage.line > 1 || gCurrentMessage.messageEnded)
            {
                gCurrentMessage.stage++;
                i = 0;
            }

            if (i == 0)
                break;

            while (i != 0)
            {
                switch (TextProcessCurrentMessage(&gCurrentMessage,
                    sMessageTextPointers[gLanguage][gCurrentMessage.messageID],
                    VRAM_BASE + 0x14000 + gCurrentMessage.gfxSlot * 0x800 + gCurrentMessage.line * 0x800))
                {
                    case TEXT_STATE_ENDED:
                        gCurrentMessage.stage++;

                    case TEXT_STATE_NEW_LINE:
                    case TEXT_STATE_NEW_PAGE:
                        gCurrentMessage.indent = 0;
                        flag = TRUE;
                        break;

                    default:
                        flag = FALSE;
                }

                if (flag)
                    break;

                if (gCurrentMessage.line > 1)
                    break;

                i--;
            }
            break;

        case 3:
            gCurrentMessage.line++;
            if (gCurrentMessage.messageID <= MESSAGE_POWER_GRIP)
            {
                gCurrentItemBeingAcquired = gCurrentMessage.messageID;
                if (gCurrentMessage.messageID >= MESSAGE_LONG_BEAM)
                    BgClipFinishCollectingAbility();
            }
            gCurrentMessage.stage++;

        case 4:
        default:
            return gCurrentMessage.line;
    }

    return 0;
}

/**
 * @brief 6f404 | 20 | Starts a story text
 * 
 * @param textID Story text ID
 */
void TextStartStory(u8 textID)
{
    gCurrentMessage = sMessageStoryText_Empty;
    gCurrentMessage.messageID = textID;
}

/**
 * @brief 6f424 | 180 | Processes a story text
 * 
 * @return u8 Current line
 */
u8 TextProcessStory(void)
{
    s32 i;
    u32* dst;
    s32 flag;
    s32 maxLine;
    s32 state;

    switch (gCurrentMessage.stage)
    {
        case 0:
            if (gCurrentMessage.messageID == STORY_TEXT_THE_TIMING)
            {
                gCurrentMessage.stage = 2;
                gCurrentMessage.gfxSlot = 1;
            }
            else
            {
                BitFill(3, 0, VRAM_BASE + 0x7000, 0x380, 0x20);
                BitFill(3, 0, VRAM_BASE + 0x7400, 0x380, 0x20);
                gCurrentMessage.stage = 1;
            }
            break;

        case 1:
            BitFill(3, 0, VRAM_BASE + 0x7800, 0x380, 0x20);
            BitFill(3, 0, VRAM_BASE + 0x7C00, 0x380, 0x20);
            gCurrentMessage.stage++;
            break;

        case 2:
            i = 6;
            if (gCurrentMessage.gfxSlot != 0)
            {
                if (gCurrentMessage.line < 10 && !gCurrentMessage.messageEnded)
                    dst = VRAM_BASE + 0x13000 + gCurrentMessage.line * 0x800;
                else
                    i = 0;
            }
            else
            {
                if (gCurrentMessage.line >= 2 || gCurrentMessage.messageEnded)
                    i = 0;
                else
                    dst = VRAM_BASE + 0x7000 + gCurrentMessage.line * 0x800;
            }

            if (i == 0)
            {
                gCurrentMessage.stage = 3;
                break;
            }
            
            while (i != 0)
            {
                maxLine = TextProcessCurrentMessage(&gCurrentMessage, sStoryTextPointers[gLanguage][gCurrentMessage.messageID], dst);
                
                switch (maxLine)
                {
                    case TEXT_STATE_ENDED:
                        gCurrentMessage.stage++;

                    case TEXT_STATE_NEW_LINE:
                    case TEXT_STATE_NEW_PAGE:
                        gCurrentMessage.indent = 0;
                        flag = TRUE;
                        break;

                    default:
                        flag = FALSE;
                }

                if (flag)
                    break;

                if (gCurrentMessage.gfxSlot)
                    maxLine = 10;
                else
                    maxLine = 2;

                if (gCurrentMessage.line >= maxLine)
                    break;

                i--;
            }

            break;

        case 3:
            gCurrentMessage.line++;
            gCurrentMessage.stage++;

        case 4:
        default:
            return gCurrentMessage.line;
    }

    return 0;
}

/**
 * @brief 6f5a4 | 20 | Starts a file screen text
 * 
 * @param textID File screen text ID
 */
void TextStartFileScreen(u8 textID)
{
    gCurrentMessage = sMessageFileScreen_Empty;
    gCurrentMessage.messageID = textID;
}

#ifdef NON_MATCHING
u8 TextProcessFileScreenPopUp(void)
{
    // https://decomp.me/scratch/vcoZi

    s32 i;
    u32* dst;
    s32 flag;
    s32 result;

    switch (gCurrentMessage.stage)
    {
        case 0:
            i = 8;
            if (gCurrentMessage.line > 3 || gCurrentMessage.messageEnded)
            {
                gCurrentMessage.stage = 1;
                break;
            }

            dst = VRAM_BASE + gCurrentMessage.line * 0x800;
            for (; i != 0; i--)
            {
                result = TextProcessCurrentMessage(&gCurrentMessage, sFileScreenTextPointers[gLanguage][gCurrentMessage.messageID], dst);
                
                switch (result)
                {
                    case TEXT_STATE_ENDED:
                        gCurrentMessage.stage++;

                    case TEXT_STATE_NEW_LINE:
                    case TEXT_STATE_NEW_PAGE:
                        gCurrentMessage.indent = 0;
                        flag = TRUE;
                        break;

                    default:
                        flag = FALSE;
                }

                if (flag)
                    break;
                    
                if (gCurrentMessage.line > 3)
                    break;
            }
            break;

        case 1:
            gCurrentMessage.line++;
            gCurrentMessage.stage++;

        case 2:
            return gCurrentMessage.line;
        
        default:
            return gCurrentMessage.line;
    }

    return 0;
}
#else
NAKED_FUNCTION
u8 TextProcessFileScreenPopUp(void)
{
    asm(" \n\
    push {r4, r5, r6, lr} \n\
    ldr r0, lbl_0806f5ec @ =gCurrentMessage \n\
    ldrb r1, [r0, #0xc] \n\
    add r2, r0, #0 \n\
    cmp r1, #1 \n\
    beq lbl_0806f668 \n\
    cmp r1, #1 \n\
    bgt lbl_0806f674 \n\
    cmp r1, #0 \n\
    bne lbl_0806f674 \n\
    movs r5, #8 \n\
    ldrb r0, [r2, #7] \n\
    cmp r0, #3 \n\
    bhi lbl_0806f5e6 \n\
    ldrb r0, [r2, #0xe] \n\
    cmp r0, #0 \n\
    beq lbl_0806f5f0 \n\
lbl_0806f5e6: \n\
    movs r0, #1 \n\
    strb r0, [r2, #0xc] \n\
    b lbl_0806f678 \n\
    .align 2, 0 \n\
lbl_0806f5ec: .4byte gCurrentMessage \n\
lbl_0806f5f0: \n\
    ldrb r0, [r2, #7] \n\
    lsl r0, r0, #0xb \n\
    movs r1, #0xc0 \n\
    lsl r1, r1, #0x13 \n\
    add r6, r0, r1 \n\
lbl_0806f5fa: \n\
    ldr r4, lbl_0806f630 @ =gCurrentMessage \n\
    ldr r1, lbl_0806f634 @ =sFileScreenTextPointers \n\
    ldr r0, lbl_0806f638 @ =gLanguage \n\
    ldrb r0, [r0] \n\
    lsl r0, r0, #0x18 \n\
    asr r0, r0, #0x18 \n\
    lsl r0, r0, #2 \n\
    add r0, r0, r1 \n\
    ldrb r1, [r4, #0xa] \n\
    ldr r0, [r0] \n\
    lsl r1, r1, #2 \n\
    add r1, r1, r0 \n\
    ldr r1, [r1] \n\
    add r0, r4, #0 \n\
    add r2, r6, #0 \n\
    bl TextProcessCurrentMessage \n\
    lsl r0, r0, #0x18 \n\
    lsr r0, r0, #0x18 \n\
    cmp r0, #2 \n\
    beq lbl_0806f642 \n\
    cmp r0, #2 \n\
    bgt lbl_0806f63c \n\
    cmp r0, #1 \n\
    beq lbl_0806f648 \n\
    b lbl_0806f654 \n\
    .align 2, 0 \n\
lbl_0806f630: .4byte gCurrentMessage \n\
lbl_0806f634: .4byte sFileScreenTextPointers \n\
lbl_0806f638: .4byte gLanguage \n\
lbl_0806f63c: \n\
    cmp r0, #4 \n\
    beq lbl_0806f648 \n\
    b lbl_0806f654 \n\
lbl_0806f642: \n\
    ldrb r0, [r4, #0xc] \n\
    add r0, #1 \n\
    strb r0, [r4, #0xc] \n\
lbl_0806f648: \n\
    ldr r1, lbl_0806f650 @ =gCurrentMessage \n\
    movs r0, #0 \n\
    strh r0, [r1, #2] \n\
    b lbl_0806f678 \n\
    .align 2, 0 \n\
lbl_0806f650: .4byte gCurrentMessage \n\
lbl_0806f654: \n\
    ldr r0, lbl_0806f664 @ =gCurrentMessage \n\
    ldrb r0, [r0, #7] \n\
    cmp r0, #3 \n\
    bhi lbl_0806f678 \n\
    sub r5, #1 \n\
    cmp r5, #0 \n\
    bne lbl_0806f5fa \n\
    b lbl_0806f678 \n\
    .align 2, 0 \n\
lbl_0806f664: .4byte gCurrentMessage \n\
lbl_0806f668: \n\
    ldrb r0, [r2, #7] \n\
    add r0, #1 \n\
    strb r0, [r2, #7] \n\
    ldrb r0, [r2, #0xc] \n\
    add r0, #1 \n\
    strb r0, [r2, #0xc] \n\
lbl_0806f674: \n\
    ldrb r0, [r2, #7] \n\
    b lbl_0806f67a \n\
lbl_0806f678: \n\
    movs r0, #0 \n\
lbl_0806f67a: \n\
    pop {r4, r5, r6} \n\
    pop {r1} \n\
    bx r1 \n\
    ");
}
#endif

/**
 * @brief 6f680 | 30c | Processes the description text
 * 
 */
void TextProcessDescription(void)
{
    u8 result;

    if (PAUSE_SCREEN_DATA.currentStatusSlot != PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot)
    {
        // Status slot changed, restart message
        PAUSE_SCREEN_DATA.miscOam[1].exists = FALSE;
        PAUSE_SCREEN_DATA.unk_56 = 0;
        PAUSE_SCREEN_DATA.currentStatusSlot = PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot;
        PAUSE_SCREEN_DATA.currentEquipment = 0;

        gCurrentMessage = sMessageDescription_Empty;
    }

    switch (PAUSE_SCREEN_DATA.unk_56)
    {
        case 0:
            // Get message id
            PAUSE_SCREEN_DATA.currentEquipment = StatusScreenGetCurrentEquipmentSelected(PAUSE_SCREEN_DATA.currentStatusSlot);
            BitFill(3, 0, VRAM_BASE + 0x7800, 0x800, 16);

            if (PAUSE_SCREEN_DATA.currentEquipment <= DESCRIPTION_TEXT_PISTOL)
                PAUSE_SCREEN_DATA.unk_56++;
            else
                PAUSE_SCREEN_DATA.unk_56 = 0x80;
            break;

        case 1:
            // Initial delay
            gCurrentMessage.timer++;
            if (gCurrentMessage.timer > gCurrentMessage.delay || gChangedInput & KEY_A)
            {
                gCurrentMessage.delay = 0;
                PAUSE_SCREEN_DATA.unk_56++;
                gCurrentMessage.timer = 0;
            }
            break;

        case 2:
            // Process message
            result = TextProcessCurrentMessage(&gCurrentMessage,
                sDescriptionTextPointers[gLanguage][PAUSE_SCREEN_DATA.currentEquipment], VRAM_BASE + 0x7800);

            if (result == TEXT_STATE_ENDED)
            {
                // Message ended
                if (gCurrentMessage.line != 0)
                {
                    // Not on first line, so it's a multi line message
                    result = MISC_OAM_ID_TEXT_MARKER_UP;
                    PAUSE_SCREEN_DATA.unk_56 = 4;
                }
                else
                {
                    // Single line message
                    result = 0;
                    PAUSE_SCREEN_DATA.unk_56 = 6;
                }
            }
            else if (result == TEXT_STATE_NEW_LINE)
            {
                // New line
                result = MISC_OAM_ID_TEXT_MARKER_DOWN;
                gCurrentMessage.timer = 0;

                if (gDemoState != 0)
                    PAUSE_SCREEN_DATA.unk_56 = 5;
                else
                    PAUSE_SCREEN_DATA.unk_56 = 3;
            }
            else
            {
                result = 0;
            }

            if (result != 0)
            {
                // Set right after the text
                PAUSE_SCREEN_DATA.miscOam[1].xPosition = (gCurrentMessage.indent + 10) * 4;

                if (result == 4)
                {
                    // Arrow pointing down
                    PAUSE_SCREEN_DATA.miscOam[1].yPosition = BLOCK_SIZE * 9;
                }
                else
                {
                    // Arrow pointing up
                    PAUSE_SCREEN_DATA.miscOam[1].yPosition = BLOCK_SIZE * 8 + HALF_BLOCK_SIZE + 4;
                    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_GETTING_NEW_ITEM)
                        result = 0;
                }

                UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[1], result);
            }
            break;

        case 3:
            // Waiting for input to change line
            if (gChangedInput & KEY_A || gDemoState != 0)
            {
                // Clear graphics buffer
                BitFill(3, 0, VRAM_BASE + 0x7800, 0x800, 16);

                // Set process message behavior
                PAUSE_SCREEN_DATA.unk_56 = 1;

                gCurrentMessage.timer = 0;
                gCurrentMessage.indent = 0;
                gCurrentMessage.delay = 10;
                PAUSE_SCREEN_DATA.miscOam[1].exists = FALSE;
            }
            break;

        case 4:
            // Waiting for input at the end of a message
            if (gChangedInput & KEY_A)
            {
                // Clear graphics buffer
                BitFill(3, 0, VRAM_BASE + 0x7800, 0x800, 16);

                // Set process message behavior
                PAUSE_SCREEN_DATA.unk_56 = 1;

                // Fully reset
                gCurrentMessage = sMessageDescription_Empty;
                PAUSE_SCREEN_DATA.miscOam[1].exists = FALSE;
            }
            break;

        case 5:
            // During a demo, wait to change line
            gCurrentMessage.timer++;
            if (gCurrentMessage.timer > 30)
            {
                // Clear graphics buffer
                BitFill(3, 0, VRAM_BASE + 0x7800, 0x800, 16);

                // Set process message behavior
                PAUSE_SCREEN_DATA.unk_56 = 1;

                gCurrentMessage.timer = 0;
                gCurrentMessage.indent = 0;
                gCurrentMessage.delay = 10;
                PAUSE_SCREEN_DATA.miscOam[1].exists = FALSE;
            }
            break;

        case 6:
    }
}

/**
 * @brief 6f98c | 140 | Processes the current message
 * 
 * @param pMessage Message data pointer
 * @param pText Text pointer
 * @param dst Destination address
 * @return u8 State
 */
u8 TextProcessCurrentMessage(struct Message* pMessage, const u16* pText, u32* dst)
{
    s32 state;
    s32 width;

    state = TEXT_STATE_NONE;
    pMessage->timer++;

    // Check for message delay
    if (!(gButtonInput & KEY_A))
    {
        // One time delay
        if (pMessage->delay > pMessage->timer)
            state = TEXT_STATE_NOTHING;

        // Continuons delay
        if (pMessage->continuousDelay > pMessage->timer)
            state = TEXT_STATE_NOTHING;
    }

    if (state < TEXT_STATE_NOTHING)
    {
        // Clear delay (not the continuous one) and timer
        pMessage->delay = 0;
        pMessage->timer = 0;

        // Get the current character
        pText += pMessage->textIndex;

        // Loop until something was drawn or a special action happended (new line, end, new page)
        while (state < TEXT_STATE_NOTHING)
        {
            width = 0;

            // Check apply special characters
            switch (*pText & CHAR_MASK)
            {
                case CHAR_WIDTH_MASK:
                    // Special width character, directly sets the width
                    width = *pText & UCHAR_MAX;
                    break;

                case CHAR_INDENT_MASK:
                    // Special indent character, changes the indent
                    pMessage->indent = *pText & UCHAR_MAX;
                    break;

                case CHAR_COLOR_MASK:
                    // Special color character, changes the color
                    pMessage->color = *pText;
                    break;
                
                case CHAR_DELAY_MASK:
                    // Special delay character, changes the delay
                    pMessage->delay = *pText;
                    break;

                case CHAR_NEW_LINE:
                    // New line character
                    state = TEXT_STATE_NEW_LINE;
                    break;

                case CHAR_NEW_PAGE:
                    // New page character
                    state = TEXT_STATE_NEW_PAGE;
                    break;

                case 0xFC00:
                    state = TEXT_STATE_UNK_3;
                    break;

                case CHAR_TERMINATOR:
                    // Terminator
                    pMessage->messageEnded = TRUE;
                    state = TEXT_STATE_ENDED;
                    break;

                default:
                    // Normal character, get its width
                    width = TextGetCharacterWidth(*pText);
                    state = TEXT_STATE_NOTHING;
                    break;
            }

            // Check for line overflow
            if (pMessage->indent + width > 0xE0)
            {
                // Force new line
                // the character that should have been drawn will be drawn on the next line since the text index isn't updated
                state = TEXT_STATE_NEW_LINE;
                break;
            }
            
            if (state < TEXT_STATE_NOTHING)
            {
                // Indent, color or delay character
                pText++;
            }
            else if (state == TEXT_STATE_NOTHING)
            {
                // Call correct draw character function
                if (pMessage->isMessage)
                    TextDrawMessageCharacter(*pText, dst, pMessage->indent, pMessage->color);
                else
                    TextDrawCharacter(*pText, dst, pMessage->indent, pMessage->color);
            }
            else if (state != TEXT_STATE_ENDED)
            {
                // New line
                pMessage->line++;
            }

            // Update indent and current character
            pMessage->indent += width;
            pMessage->textIndex++;
        }
    }

    return state;
}

/**
 * @brief 6facc | ec | Draws the "yes no" prompt of the easy sleep menu
 * 
 */
void TextDrawYesNoEasySleep(void)
{
    const u16* pText;
    u8 shouldDraw;

    // Clear graphics buffer
    BitFill(3, USHORT_MAX, PAUSE_SCREEN_EWRAM.easySleepTextFormatted_1,
        sizeof(PAUSE_SCREEN_EWRAM.easySleepTextFormatted_1) * 5, 16);

    // Signal that the main text can start drawing
    PAUSE_SCREEN_DATA.easySleepTextState = 0;

    // Get text pointer
    pText = sMessageTextPointers[gLanguage][MESSAGE_EASY_SLEEP_PROMPT];

    // Reset current message
    BitFill(3, 0, &gCurrentMessage, sizeof(gCurrentMessage), 32);

    while (*pText != CHAR_TERMINATOR)
    {
        shouldDraw = TRUE;
        if (*pText == CHAR_NEW_LINE)
        {
            // Hardcode indent
            if (gCurrentMessage.indent > 112)
                return;

            gCurrentMessage.indent = 112;
            shouldDraw = FALSE;
        }
        else if (*pText & CHAR_WIDTH_MASK)
        {
            // Check for color change
            if ((*pText & CHAR_TERMINATOR) == CHAR_COLOR_MASK)
                gCurrentMessage.color = *pText;

            shouldDraw = FALSE;
        }

        if (shouldDraw)
        {
            // Draw and update indent
            TextDrawMessageCharacter(*pText, (u32*)PAUSE_SCREEN_EWRAM.unk_6000, gCurrentMessage.indent, gCurrentMessage.color);
            gCurrentMessage.indent += TextGetCharacterWidth(*pText);
        }

        pText++;
    }
}

/**
 * @brief 6fbb8 | 148 | Draws the easy sleep text
 * 
 */
void TextDrawEasySleep(void)
{
    s32 i;

    switch ((u8)PAUSE_SCREEN_DATA.easySleepTextState)
    {
        case 0:
            // Reset current message
            BitFill(3, 0, &gCurrentMessage, sizeof(gCurrentMessage), 32);
            gCurrentMessage.isMessage = TRUE;
            PAUSE_SCREEN_DATA.easySleepTextState++;

        case 1:
            // Process message
            for (i = 3; i != -1; i--)
            {
                if (!TextProcessCurrentMessage(&gCurrentMessage, sMessageTextPointers[gLanguage][MESSAGE_ACTIVATE_EASY_SLEEP],
                    (u32*)&PAUSE_SCREEN_EWRAM.easySleepTextFormatted_1[gCurrentMessage.line * 1024]))
                    continue;

                gCurrentMessage.indent = 0;
                if (gCurrentMessage.messageEnded)
                {
                    PAUSE_SCREEN_DATA.easySleepTextState++;
                    break;
                }
            }
            break;

        case 2:
            // Reset current message
            BitFill(3, 0, &gCurrentMessage, sizeof(gCurrentMessage), 32);
            gCurrentMessage.isMessage = TRUE;
            PAUSE_SCREEN_DATA.easySleepTextState++;

        case 3:
            // Process message
            for (i = 3; i != -1; i--)
            {
                if (!TextProcessCurrentMessage(&gCurrentMessage, sMessageTextPointers[gLanguage][MESSAGE_PRESS_SELECT_L_AND_R],
                    (u32*)&PAUSE_SCREEN_EWRAM.unk_5000[gCurrentMessage.line * 1024]))
                    continue;

                gCurrentMessage.indent = 0;
                if (gCurrentMessage.messageEnded)
                {
                    // Mark as ended
                    PAUSE_SCREEN_DATA.easySleepTextState = 0x80;
                    break;
                }
            }
            break;
    }
}
