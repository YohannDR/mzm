#include "ending_and_gallery.h"
#include "callbacks.h"

#include "data/shortcut_pointers.h"
#include "data/ending_and_gallery_data.h"

#include "constants/audio.h"
#include "constants/game_state.h"

#include "structs/bg_clip.h"
#include "structs/display.h"
#include "structs/ending_and_gallery.h"
#include "structs/game_state.h"

/**
 * @brief 847f8 | 78 | V-blank code for the fusion gallery
 * 
 */
void FusionGalleryVBlank(void)
{
    dma_set(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / 4);

    write16(REG_DISPCNT, ENDING_DATA.dispcnt);
    write16(REG_BLDCNT, ENDING_DATA.bldcnt);

    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_BG0VOFS, (gBG0YPosition / 16) & 0x1FF);
    write16(REG_BG1VOFS, (gBG1YPosition / 16) & 0x1FF);
}

void FusionGalleryInit(void)
{

}

u32 FusionGalleryDisplay(void)
{

}

u32 FusionGallerySubroutine(void)
{

}

/**
 * @brief 84c34 | 48 | Checks if an ending letter should display
 * 
 * @param offset Offset, to document
 */
void EndingImageCheckDisplayLetter(u32 offset)
{
    if (!ENDING_DATA.unk_124[offset])
        return;

    if (ENDING_DATA.unk_142[offset])
    {
        ENDING_DATA.unk_142[offset]--;
        if (ENDING_DATA.unk_142[offset] == 0)
            ENDING_DATA.unk_124[offset]++;
    }
}

void EndingImageLoadTextOAM(u32 set)
{

}

void EndingImageDisplayLinePermanently(u32 line)
{

}

void EndingImageLoadIGTAndPercentageGraphics(void)
{

}

void GalleryVBlank(void)
{

}

/**
 * @brief 85318 | a8 | V-blank code for the end screen
 * 
 */
void EndScreenVBlank(void)
{
    dma_set(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / 4);

    write16(REG_DISPCNT, ENDING_DATA.dispcnt);
    write16(REG_BLDCNT, ENDING_DATA.bldcnt);

    write16(REG_BLDALPHA, gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_BG1HOFS, gBG1XPosition & 0x1FF);
    write16(REG_BG2HOFS, gBG2XPosition & 0x1FF);
    write16(REG_BG3HOFS, gBG3XPosition & 0x1FF);
}

void UnlockedOptionsVBlank(void)
{

}

/**
 * @brief 85464 | 1f8 | Initializes the credits
 * 
 */
void CreditsInit(void)
{
    u32 zero;

    write16(REG_IME, FALSE);
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) & ~IF_HBLANK);
    write16(REG_IF, IF_HBLANK);

    write16(REG_IME, TRUE);
    write16(REG_DISPCNT, 0);

    write16(REG_IME, FALSE);
    CallbackSetVBlank(GalleryVBlank);
    write16(REG_IME, TRUE);

    zero = 0;
    dma_set(3, &zero, &gNonGameplayRAM, (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | sizeof(gNonGameplayRAM) / 4);

    ClearGfxRam();

    LZ77UncompVRAM(sCreditsChozoWallBackgroundGFX, VRAM_BASE);
    LZ77UncompVRAM(sCreditsChozoWallBackgroundTileTable, VRAM_BASE + 0xE000);
    LZ77UncompVRAM(sCreditsChozoWallBottomTileTable, VRAM_BASE + 0xD800);
    LZ77UncompVRAM(sCreditsCharactersGFX, VRAM_BASE + 0x8000);

    dma_set(3, sCreditsChozoWallPAL, PALRAM_BASE, DMA_ENABLE << 16 | sizeof(sCreditsChozoWallPAL) / 2);
    dma_set(3, sCreditsCharactersPAL, PALRAM_BASE + 0x1A0, DMA_ENABLE << 16 | sizeof(sCreditsCharactersPAL) / 2);

    write16(REG_BG0CNT, 0x1E08);
    write16(REG_BG1CNT, 0x1F09);
    write16(REG_BG2CNT, 0x9C02);
    write16(REG_BG3CNT, 0x9A0B);

    gNextOamSlot = 0;
    ResetFreeOAM();

    gBG0XPosition = 0;
    gBG0YPosition = 0x1000;
    gBG1XPosition = 0;
    gBG1YPosition = 0x1000;
    gBG2XPosition = 0;
    gBG2YPosition = 0;
    gBG3XPosition = 0;
    gBG3YPosition = 0;

    write16(REG_BG0HOFS, 0);
    write16(REG_BG0VOFS, 0x1000);
    write16(REG_BG1HOFS, 4);
    write16(REG_BG1VOFS, 0x1000);
    write16(REG_BG2HOFS, 0);
    write16(REG_BG2VOFS, 0);
    write16(REG_BG3HOFS, 0);
    write16(REG_BG3VOFS, 0);

    ENDING_DATA.unk_E = 0x80;
    ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;
    ENDING_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

    gWrittenToBLDALPHA_L = 16;
    gWrittenToBLDALPHA_H = 0;
    gWrittenToBLDY_NonGameplay = 16;

    GalleryVBlank();
    PlayMusic(MUSIC_CREDITS, 0);
}

u8 CreditsDisplayLine(u32 line)
{

}

u8 CreditsDisplay(void)
{

}

/**
 * @brief 85b80 | 90 | Handles the scrolling wall part of the after credits
 * 
 * @return u8 bool, ended
 */
u8 CreditsChozoWallMovement(void)
{
    u8 ended;

    ended = FALSE;

    switch (ENDING_DATA.timer++)
    {
        case 0:
            // Load bottom graphics
            LZ77UncompVRAM(sCreditsChozoWallBottomGFX, VRAM_BASE + 0x8000);
            break;

        case 1:
            // Enable background scrolling
            ENDING_DATA.unk_1++;
            break;

        case 512:
            write16(REG_BG1HOFS, 0);
            ended = TRUE;
            break;
    }

    if (ENDING_DATA.unk_1)
    {
        gBG2YPosition += 8;
        gBG3YPosition += 8;
    
        // Check end scrolling
        if (gBG2YPosition == BLOCK_SIZE * 56)
            ENDING_DATA.unk_1 = FALSE; // Disable background scrolling
    }

    return ended;
}

/**
 * @brief 85c10 | 1f8 | Handles the zooming wall part of the after credits 
 * 
 * @return u8 bool, ended (0/2)
 */
u8 CreditsChozoWallZoom(void)
{
    u8 ended;

    ended = FALSE;

    switch (ENDING_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sCreditsChozoWallBottomZoomedGFX, VRAM_BASE);
            dma_set(3, sCreditsChozoWallPAL, PALRAM_BASE, DMA_ENABLE << 16 | ARRAY_SIZE(sCreditsChozoWallPAL));
            gBG0YPosition = 0;
            gWrittenToBLDALPHA_L = 0;
            gWrittenToBLDALPHA_H = 16;
            break;

        case 1:
            LZ77UncompVRAM(sCreditsChozoWallBottomZoomedTileTable, VRAM_BASE + 0xF000);
            write16(REG_BG0CNT, 0x1E00);
            ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG2 | DCNT_BG3;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;

            ENDING_DATA.unk_1++;
            break;

        case 192:
            ENDING_DATA.dispcnt = DCNT_BG0;
            ENDING_DATA.bldcnt = 0;
            ENDING_DATA.unk_1++;
            gBG1YPosition = 0;
            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            break;

        case 193:
            LZ77UncompVRAM(sCreditsChozoDrawingGFX, VRAM_BASE + 0x8000);
            break;

        case 194:
            LZ77UncompVRAM(sCreditsChozoDrawingTileTable, VRAM_BASE + 0xF800);
            ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG1;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG1_SECOND_TARGET_PIXEL;

            ENDING_DATA.unk_1++;
            break;

        case 800:
            ENDING_DATA.dispcnt = DCNT_BG1;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
                BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            ENDING_DATA.unk_1++;
            break;

        case 960:
            ended = 2;
            break;
    }

    if (ENDING_DATA.unk_1 == 1)
    {
        if (!(ENDING_DATA.timer & 7))
        {
            if (gWrittenToBLDALPHA_L < 16)
                gWrittenToBLDALPHA_L++;

            if (gWrittenToBLDALPHA_H != 0)
                gWrittenToBLDALPHA_H--;
        }
    }
    else if (ENDING_DATA.unk_1 == 3)
    {
        if (!(ENDING_DATA.timer & 7))
        {
            if (gWrittenToBLDALPHA_L != 0)
                gWrittenToBLDALPHA_L--;

            if (gWrittenToBLDALPHA_H < 16)
                gWrittenToBLDALPHA_H++;
        }
    }
    else if (ENDING_DATA.unk_1 == 4)
    {
        if (!(ENDING_DATA.timer & 7))
        {
            if (gWrittenToBLDY_NonGameplay < 16)
                gWrittenToBLDY_NonGameplay++;
        }
    }

    return ended;
}

void EndScreenInit(void)
{

}

u8 EndScreenSamusPosing(void)
{

}

/**
 * @brief 867b4 | 29c | Initiliazes the ending image sequence
 * 
 */
void EndingImageInit(void)
{
    u32 zero;
    u32 endingNumber;
    u32 part1;
    u32 part2;
    u32 part3;
    u32 part4;
    u32 part5;
    u32 pen;
    u32 mask;

    write16(REG_IME, FALSE);
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) & ~IF_HBLANK);
    write16(REG_IF, IF_HBLANK);
    write16(REG_IME, TRUE);
    write16(REG_DISPCNT, 0);
    write16(REG_IME, FALSE);

    CallbackSetVBlank(GalleryVBlank);
    write16(REG_IME, TRUE);

    zero = 0;
    dma_set(3, &zero, &gNonGameplayRAM, (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | sizeof(gNonGameplayRAM) / 4);

    pen = GetPercentAndEndingNumber();

    mask = 0xFF;
    // TODO figure out how PEN is structured
    part1 = pen >> 0x18;
    part2 = (pen >> 0x10) & mask;

    part3 = (pen >> 0xC) & 0xF;
    part4 = (pen >> 0x8) & 0xF;
    part5 = (pen >> 0x4) & 0xF;

    endingNumber = pen & 0xF;
        
    LZ77UncompVRAM(sEndingImagesTopHalfGfxPointers[endingNumber], VRAM_BASE);
    LZ77UncompVRAM(sEndingImagesLowerHalfGfxPointers[endingNumber], VRAM_BASE + 0x8000);
    LZ77UncompVRAM(sEndingImagesTopHalfTileTablePointers[endingNumber], VRAM_BASE + 0xE000);
    LZ77UncompVRAM(sEndingImagesLowerHalfTileTablePointers[endingNumber], VRAM_BASE + 0xF800);
    BitFill(3, 0x4FF04FF, VRAM_BASE + 0xE800, 0x800, 0x20);
    dma_set(3, sEndingImagesPalPointers[endingNumber], PALRAM_BASE, DMA_ENABLE << 16 | 0x100);

    ENDING_DATA.completionPercentage = part1 + part2 + part3 + part4 + part5;

    LZ77UncompVRAM(sEndingImageNumbersMiscGFX, VRAM_BASE + 0x10000);

    ENDING_DATA.language = gLanguage;
    if (gLanguage > LANGUAGE_ENGLISH)
        ENDING_DATA.language = LANGUAGE_ENGLISH;

    if (ENDING_DATA.language == LANGUAGE_HIRAGANA)
        LZ77UncompVRAM(sEndingImageTextJapGFX, VRAM_BASE + 0x11000);
    else
        LZ77UncompVRAM(sEndingImageTextGFX, VRAM_BASE + 0x11000);

    dma_set(3, sEndingImageTextPAL, PALRAM_BASE + 0x200, DMA_ENABLE << 16 | sizeof(sEndingImageTextPAL) / 2);

    EndingImageLoadIGTAndPercentageGraphics();
    write16(REG_BG0CNT, 0x9C00);
    write16(REG_BG1CNT, 0x9E09);

    gNextOamSlot = 0;
    ResetFreeOAM();

    gBG0XPosition = 0;
    gBG0YPosition = 0x1000;
    gBG1XPosition = 0;
    gBG1YPosition = 0x1000;
    gBG2XPosition = 0;
    gBG2YPosition = 0;
    gBG3XPosition = 0;
    gBG3YPosition = 0;

    write16(REG_BG0HOFS, 0);
    write16(REG_BG0VOFS, 0);
    write16(REG_BG1HOFS, 0);
    write16(REG_BG1VOFS, 0);
    write16(REG_BG2HOFS, 0);
    write16(REG_BG2VOFS, 0);
    write16(REG_BG3HOFS, 0);
    write16(REG_BG3VOFS, 0);

    ENDING_DATA.dispcnt = DCNT_OBJ | DCNT_BG0 | DCNT_BG1;
    ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
        BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
        BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

    gWrittenToBLDALPHA_L = 16;
    gWrittenToBLDALPHA_H = 0;
    gWrittenToBLDY_NonGameplay = 16;

    GalleryVBlank();
}

void EndingImageDisplayText(void)
{

}

u8 EndingImageDisplay(void)
{

}

void UnlockedOptionsInit(void)
{

}

u8 UnlockedOptionsPopUp(void)
{

}

u32 CreditsSubroutine(void)
{

}

void GalleryInit(void)
{

}

u32 GalleryDisplay(void)
{

}

u32 GallerySubroutine(void)
{

}
