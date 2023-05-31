#include "text.h"
#include "gba.h"
#include "macros.h"

#include "data/text_data.h"
#include "data/shortcut_pointers.h"
#include "data/menus/pause_screen_data.h"

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

void TextDrawCharacter(u16 charID, u32* dst, u16 indent, u8 color)
{
    // https://decomp.me/scratch/SAqIc

    u32 palette;
    u32* dstGfx;
    const u32* srcGfx;
    i32 size;
    u32 pixelSrc;
    u32 pixelDst;
    i32 unk_0;
    u8 width;
    i32 pass;
    u32 value;

    BitFill(3, 0, gCurrentCharacterGfx, sizeof(gCurrentCharacterGfx), 0x10);
    width = TextGetCharacterWidth(charID);

    for (pass = 0; pass < 2; pass++)
    {
        if (pass != 0)
            dstGfx = gCurrentCharacterGfx + 16;
        else
            dstGfx = gCurrentCharacterGfx;

        srcGfx = (const u32*)&sCharactersGfx[charID * 0x20 + pass * 0x400];
        
        if (width > 8)
            size = 16;
        else
            size = 8;

        if (color != 0)
        {
            if (size > 0)
            {
                while (size != 0)
                {
                    pixelSrc = *srcGfx;
                    
                    if (pixelSrc != 0)
                    {
                        pixelDst = 0;
                        if (color != 0)
                            palette = color;
                        else
                            palette = 4;
    
                        if (pixelSrc & sArray_760338[0])
                        {
                            if (pixelSrc & sArray_760338[0] & sArray_760398[0])
                                pixelDst |= palette;
                            else
                                pixelDst |= pixelSrc & sArray_760338[0];
                        }
                        palette <<= 4;
    
                        if (pixelSrc & sArray_760338[1])
                        {
                            if (pixelSrc & sArray_760338[1] & sArray_760398[1])
                                pixelDst |= palette;
                            else
                                pixelDst |= pixelSrc & sArray_760338[1];
                        }
                        palette <<= 4;
    
                        if (pixelSrc & sArray_760338[2])
                        {
                            if (pixelSrc & sArray_760338[2] & sArray_760398[2])
                                pixelDst |= palette;
                            else
                                pixelDst |= pixelSrc & sArray_760338[2];
                        }
                        palette <<= 4;
    
                        if (pixelSrc & sArray_760338[3])
                        {
                            if (pixelSrc & sArray_760338[3] & sArray_760398[3])
                                pixelDst |= palette;
                            else
                                pixelDst |= pixelSrc & sArray_760338[3];
                        }
                        palette <<= 4;
    
                        if (pixelSrc & sArray_760338[4])
                        {
                            if (pixelSrc & sArray_760338[4] & sArray_760398[4])
                                pixelDst |= palette;
                            else
                                pixelDst |= pixelSrc & sArray_760338[4];
                        }
                        palette <<= 4;
    
                        if (pixelSrc & sArray_760338[5])
                        {
                            if (pixelSrc & sArray_760338[5] & sArray_760398[5])
                                pixelDst |= palette;
                            else
                                pixelDst |= pixelSrc & sArray_760338[5];
                        }
                        palette <<= 4;
    
                        if (pixelSrc & sArray_760338[6])
                        {
                            if (pixelSrc & sArray_760338[6] & sArray_760398[6])
                                pixelDst |= palette;
                            else
                                pixelDst |= pixelSrc & sArray_760338[6];
                        }
                        palette <<= 4;
    
                        if (pixelSrc & sArray_760338[7])
                        {
                            if (pixelSrc & sArray_760338[7] & sArray_760398[7])
                                pixelDst |= palette;
                            else
                                pixelDst |= pixelSrc & sArray_760338[7];
                        }
    
                        *dstGfx = pixelDst;
                    }
                    
                    size--;
                    srcGfx++;
                    dstGfx++;
                }
            }
        }
        else
            DMATransfer(3, srcGfx, dstGfx, size * 4, 0x10);

        dstGfx = dst + ((indent & 0xFF) / 8) * 8 + pass * 0x100;
        dstGfx += (indent / 256) * 0x200;
        if (pass != 0)
            srcGfx = gCurrentCharacterGfx + 16;
        else
            srcGfx = gCurrentCharacterGfx;

        unk_0 = indent & 7;

        if (unk_0 != 0)
        {
            pixelSrc = unk_0 * 4;
            size = 32 - pixelSrc;

            if (unk_0 + width > 8)
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
                    if (unk_0 + width > 16)
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

void TextDrawMessageCharacter(u16 charID, u32* dst, u16 indent, u8 color)
{

}

void TextDrawLocationTextCharacters(u8 param_1, const u16** ppText)
{
    // https://decomp.me/scratch/sOmhX

    u32* dst;
    const u16* pText;
    u32 indent;
    u32 color;
    u32 charID;
    u32 drawFlag;
    u32 width;
    u16 charFlags;

    if (param_1 == 1)
        dst = EWRAM_BASE;
    else if (param_1 == 2)
    {
        dst = EWRAM_BASE + 0x800;

        pText = *ppText;
        while (*pText != CHAR_NEW_LINE)
        {
            *ppText = pText;
            pText++;
        }

        (*ppText)++;
    }
    else
        return;

    indent = 0;
    color = 0;

    pText = *ppText;

    while (*pText != CHAR_TERMINATOR && *pText != CHAR_NEW_LINE)
    {
        drawFlag = TRUE;

        charID = *pText;
        charFlags = charID & 0xFF00;

        if (charFlags == CHAR_WIDTH_MASK)
        {
            width = charID & 0xFF;
            drawFlag = FALSE;
        }
        else if (charFlags == CHAR_ABSOLUTE_WIDTH_MASK)
        {
            width = 0;
            indent = charID & 0xFF;
            drawFlag = FALSE;
        }
        else if (charFlags == CHAR_COLOR_MASK)
        {
            width = 0;
            color = charID & 0xFF;
            drawFlag = FALSE;
        }

        if (drawFlag)
        {
            width = TextGetCharacterWidth(*pText);
            TextDrawMessageCharacter(**ppText, dst, indent, color);
        }

        pText = ++(*ppText);
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

    pText = sLocationTextpointers[gLanguage][locationText];
    TextDrawLocationTextCharacters(1, &pText);

    dma_set(3, EWRAM_BASE, VRAM_BASE + 0x14000 + gfxSlot * 0x800, (DMA_ENABLE | DMA_32BIT) << 16 | 0xE0);
    dma_set(3, EWRAM_BASE + 0x400, VRAM_BASE + 0x14400 + gfxSlot * 0x800, (DMA_ENABLE | DMA_32BIT) << 16 | 0xE0);
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
    i32 i;
    i32 flag;

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
                switch (TextProcessCurrentMessage(&gCurrentMessage, sMessageTextpointers[gLanguage][gCurrentMessage.messageID],
                    VRAM_BASE + 0x14000 + gCurrentMessage.gfxSlot * 0x800 + gCurrentMessage.line * 0x800))
                {
                    case 2:
                        gCurrentMessage.stage++;

                    case 1:
                    case 4:
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
    i32 i;
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
                    sMessageTextpointers[gLanguage][gCurrentMessage.messageID],
                    VRAM_BASE + 0x14000 + gCurrentMessage.gfxSlot * 0x800 + gCurrentMessage.line * 0x800))
                {
                    case 2:
                        gCurrentMessage.stage++;

                    case 1:
                    case 4:
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
u8 TextProcessFileScreenPopUp(void)
{
    i32 i;
    u32* dst;
    i32 flag;

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
                switch (TextProcessCurrentMessage(&gCurrentMessage, sFileScreenTextPointers[gLanguage][gCurrentMessage.messageID], dst))
                {
                    case 2:
                        gCurrentMessage.stage++;

                    case 1:
                    case 4:
                        gCurrentMessage.indent = 0;
                        flag = TRUE;
                        break;

                    default:
                        flag = FALSE;
                }

                if (flag || gCurrentMessage.line > 3)
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

u8 TextProcessFileScreenPopUp(void)
{
    // https://decomp.me/scratch/vcoZi

    i32 i;
    u32* dst;
    i32 flag;

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
                switch (TextProcessCurrentMessage(&gCurrentMessage, sFileScreenTextPointers[gLanguage][gCurrentMessage.messageID], dst))
                {
                    case 2:
                        gCurrentMessage.stage++;

                    case 1:
                    case 4:
                        gCurrentMessage.indent = 0;
                        flag = TRUE;
                        break;

                    default:
                        flag = FALSE;
                }

                if (flag || gCurrentMessage.line > 3)
                    break;
            }
            break;

        case 1:
            gCurrentMessage.line++;
            gCurrentMessage.stage++;

        case 2:
        default:
            return gCurrentMessage.line;
    }

    return 0;
}

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
            gCurrentMessage.delay++;
            if (gCurrentMessage.delay > gCurrentMessage.unk_9 || gChangedInput & KEY_A)
            {
                gCurrentMessage.unk_9 = 0;
                PAUSE_SCREEN_DATA.unk_56++;
                gCurrentMessage.delay = 0;
            }
            break;

        case 2:
            // Process message
            result = TextProcessCurrentMessage(&gCurrentMessage,
                sDescriptionTextPointers[gLanguage][PAUSE_SCREEN_DATA.currentEquipment], VRAM_BASE + 0x7800);

            if (result == 2)
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
            else if (result == 1)
            {
                // New line
                result = MISC_OAM_ID_TEXT_MARKER_DOWN;
                gCurrentMessage.delay = 0;

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

                gCurrentMessage.delay = 0;
                gCurrentMessage.indent = 0;
                gCurrentMessage.unk_9 = 10;
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
            gCurrentMessage.delay++;
            if (gCurrentMessage.delay > 30)
            {
                // Clear graphics buffer
                BitFill(3, 0, VRAM_BASE + 0x7800, 0x800, 16);

                // Set process message behavior
                PAUSE_SCREEN_DATA.unk_56 = 1;

                gCurrentMessage.delay = 0;
                gCurrentMessage.indent = 0;
                gCurrentMessage.unk_9 = 10;
                PAUSE_SCREEN_DATA.miscOam[1].exists = FALSE;
            }
            break;

        case 6:
    }
}

u8 TextProcessCurrentMessage(struct Message* pMessage, const u16* pText, u32* dst)
{
    // https://decomp.me/scratch/PL6wn

    i32 state;
    i32 width;
    i32 charID;

    state = -1;
    pMessage->delay++;

    if (!(gButtonInput & KEY_A))
    {
        if (pMessage->unk_9 > pMessage->delay)
            state = 0;
        if (pMessage->unk_8 > pMessage->delay)
            state = 0;
    }

    if (state < 0)
    {
        pMessage->unk_9 = 0;
        pMessage->delay = 0;
        pText += pMessage->textIndex;

        while (state < 0)
        {
            width = 0;
            charID = *pText;

            switch (charID & 0xFF00)
            {
                case CHAR_WIDTH_MASK:
                    width = charID & UCHAR_MAX;
                    break;

                case CHAR_ABSOLUTE_WIDTH_MASK:
                    pMessage->indent = charID & UCHAR_MAX;
                    break;

                case CHAR_COLOR_MASK:
                    pMessage->color = charID;
                    break;
                
                case 0xE100:
                    pMessage->unk_9 = charID;
                    break;

                case 0xFE00:
                    state = 1;
                    break;

                case 0xFD00:
                    state = 4;
                    break;

                case 0xFC00:
                    state = 3;
                    break;

                case CHAR_TERMINATOR:
                    pMessage->messageEnded = TRUE;
                    state = 2;
                    break;

                default:
                    width = TextGetCharacterWidth(charID);
                    state = 0;
                    break;
            }

            if (pMessage->indent + width > 0xE0)
            {
                state = 1;
                break;
            }
            
            if (state < 0)
                pText++;
            else if (state == 0)
            {
                if (pMessage->isMessage)
                    TextDrawMessageCharacter(*pText, dst, pMessage->indent, pMessage->color);
                else
                    TextDrawCharacter(*pText, dst, pMessage->indent, pMessage->color);
            }
            else if (state != 2)
                pMessage->line++;

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
    pText = sMessageTextpointers[gLanguage][MESSAGE_EASY_SLEEP_PROMPT];

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
    i32 i;

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
                if (!TextProcessCurrentMessage(&gCurrentMessage, sMessageTextpointers[gLanguage][MESSAGE_ACTIVATE_EASY_SLEEP],
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
                if (!TextProcessCurrentMessage(&gCurrentMessage, sMessageTextpointers[gLanguage][MESSAGE_PRESS_SELECT_L_AND_R],
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
