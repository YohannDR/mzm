#include "text.h"
#include "gba.h"

#include "data/text_data.h"

#include "constants/text.h"

#include "structs/game_state.h"

/**
 * @brief 6e460 | 24 | Gets the width of a character
 * 
 * @param charID Character
 * @return u8 Width
 */
u32 TextGetCharacterWidth(u16 charID)
{
    if (charID >= 0x4A0)
        return 10;
    else
        return sCharacterWidths[charID];
}

void TextDrawCharacter(u16 charID, u32* dst, u16 indent, u8 color)
{

}

void TextDrawMessageCharacter(u16 charID, u32* dst, u16 indent, u8 color)
{

}

void TextDrawLocationTextCharacters(u8 param_1, const u16** ppText)
{

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
    dma_set(3, EWRAM_BASE + 0X400, VRAM_BASE + 0x14400 + gfxSlot * 0x800, (DMA_ENABLE | DMA_32BIT) << 16 | 0xE0);
}

void unk_6f0a8(u8 textID, u8 gfxSlot, u8 param_3)
{

}

void TextStartMessage(u8 textID, u8 gfxSlot)
{
    // https://decomp.me/scratch/NdHu7

    register u32 messageID asm("r1");
    
    gCurrentMessage = sMessage_Empty;
    
    messageID = textID;
    if (textID > 0x23)
        messageID = 0x23;

    gCurrentMessage.messageID = messageID;
    gCurrentMessage.gfxSlot = gfxSlot;
}

void TextProcessItemBanner(void)
{

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

u8 TextProcessStory(void)
{
    // https://decomp.me/scratch/fxWFY

    i32 i;
    u32* dst;
    i32 flag;
    i32 maxLine;
    register i32 state asm("r1");

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
                if (gCurrentMessage.line < 2 && !gCurrentMessage.messageEnded)
                    dst = VRAM_BASE + 0x7000 + gCurrentMessage.line * 0x800;
                else
                    goto lbl;
            }

            if (i == 0)
            {
                lbl:
                gCurrentMessage.stage = 3;
                break;
            }
            
            while (i != 0)
            {
                state = TextProcessCurrentMessage(&gCurrentMessage, sStoryTextPointers[gLanguage][gCurrentMessage.messageID], dst);
                
                switch (state)
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
            while (i != 0)
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

                if (flag)
                    break;
                
                if (gCurrentMessage.line > 3)
                    break;
                i--;
            }
            break;

        case 1:
            gCurrentMessage.line++;
            gCurrentMessage.stage++;
            return gCurrentMessage.line;
    }

    return 0;
}

void TextProcessDescription(void)
{

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

void TextDrawYesNoEasySleep(void)
{

}

void TextDrawEasySleep(void)
{

}
