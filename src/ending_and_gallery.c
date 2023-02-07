#include "ending_and_gallery.h"
#include "callbacks.h"

#include "data/shortcut_pointers.h"
#include "data/ending_and_gallery_data.h"

#include "constants/game_state.h"

#include "structs/bg_clip.h"
#include "structs/display.h"
#include "structs/ending_and_gallery.h"
#include "structs/game_state.h"

void FusionGalleryVBlank(void)
{

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

void EndingImageCheckDisplayLetter(u32 offset)
{

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

void EndScreenVBlank(void)
{

}

void UnlockedOptionsVBlank(void)
{

}

void CreditsInit(void)
{

}

u8 CreditsDisplayLine(u32 line)
{

}

u8 CreditsDisplay(void)
{

}

u8 CreditsChozoWallMovement(void)
{

}

u8 CreditsChozoWallZoom(void)
{

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
