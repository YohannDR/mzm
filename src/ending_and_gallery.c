#include "ending_and_gallery.h"
#include "callbacks.h"

#include "data/shortcut_pointers.h"
#include "data/ending_and_gallery_data.h"

#include "constants/audio.h"
#include "constants/ending_and_gallery.h"
#include "constants/game_state.h"
#include "constants/text.h"

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

/**
 * @brief 85e08 | 248 | Initializes the end screen (samus posing)
 * 
 */
void EndScreenInit(void)
{
    u32 zero;

    write16(REG_IME, FALSE);
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) & ~IF_HBLANK);
    write16(REG_IF, IF_HBLANK);

    write16(REG_IME, TRUE);
    write16(REG_DISPCNT, 0);

    write16(REG_IME, FALSE);
    CallbackSetVBlank(EndScreenVBlank);
    write16(REG_IME, TRUE);

    LZ77UncompVRAM(sEndingSamusPosingSpaceBackgroundGFX, VRAM_BASE + 0x3000);
    LZ77UncompVRAM(sEndingLightGFX, VRAM_BASE + 0xB000);
    LZ77UncompVRAM(sEndingSamusPosingGFX_1, VRAM_BASE);
    LZ77UncompVRAM(sEndingSamusPosingGFX_2, VRAM_BASE + 0x8000);

    LZ77UncompVRAM(sEndingSamusPosingSpaceBackgroundTileTable, VRAM_BASE + 0xF800);
    LZ77UncompVRAM(sEndingLightTileTable, VRAM_BASE + 0xF000);
    LZ77UncompVRAM(sEndingSamusPosingTileTable_1, VRAM_BASE + 0xD000);
    LZ77UncompVRAM(sEndingSamusPosingTileTable_2, VRAM_BASE + 0xE000);

    BitFill(3, 0, VRAM_BASE + 0xD800, 0x800, 32);
    BitFill(3, 0, VRAM_BASE + 0xE800, 0x800, 32);

    dma_set(3, sEndingPosingPAL, PALRAM_BASE, DMA_ENABLE << 16 | ARRAY_SIZE(sEndingPosingPAL));

    write16(REG_BG0CNT, 0x1E08);
    write16(REG_BG1CNT, 0x5A01);
    write16(REG_BG2CNT, 0x5C0A);
    write16(REG_BG3CNT, 0x1F03);
    
    gNextOamSlot = 0;
    ResetFreeOAM();
    dma_set(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / 4);

    gBG0XPosition = 0;
    gBG0YPosition = 0;
    gBG1XPosition = 0x100;
    gBG1YPosition = 0;
    gBG2XPosition = 0x100;
    gBG2YPosition = 0;
    gBG3XPosition = 0;
    gBG3YPosition = 0;

    write16(REG_BG0HOFS, 0);
    write16(REG_BG0VOFS, 0);
    write16(REG_BG1HOFS, 0x100);
    write16(REG_BG1VOFS, 0);
    write16(REG_BG2HOFS, 0x100);
    write16(REG_BG2VOFS, 0);
    write16(REG_BG3HOFS, 0);
    write16(REG_BG3VOFS, 0);

    zero = 0;
    dma_set(3, &zero, &gNonGameplayRAM, (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | sizeof(gNonGameplayRAM) / 4);

    ENDING_DATA.endingNumber = GetPercentAndEndingNumber() & 7;
    ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ;

    gWrittenToBLDALPHA_L = 16;
    gWrittenToBLDALPHA_H = 0;
    gWrittenToBLDY_NonGameplay = 16;

    EndScreenVBlank();
}

/**
 * @brief 86050 | 764 | Handles the entire samus posing sequence
 * 
 * @return u8 bool, ended
 */
u8 EndScreenSamusPosing(void)
{
    u8 ended;
    u32 temp;

    ended = FALSE;

    ENDING_DATA.endScreenTimer++;

    switch (ENDING_DATA.unk_1)
    {
        case 4:
            if (ENDING_DATA.timer++ <= 7)
                break;

        case 0:
            gBG1XPosition += 8;
            if (gBG1XPosition >= BLOCK_SIZE * 8)
            {
                gBG1XPosition = 0;
                ENDING_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                    BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;
                ENDING_DATA.timer = 0;
                ENDING_DATA.unk_1++;
            }
            break;

        case 1:
        case 3:
        case 5:
            if (ENDING_DATA.timer++ > 24)
            {
                ENDING_DATA.unk_124[0] = 1;
                ENDING_DATA.timer = 0;
                ENDING_DATA.unk_1++;
            }
            break;

        case 2:
        case 6:
            if (ENDING_DATA.timer++ > 7)
            {
                gBG2XPosition += 8;
                if (gBG2XPosition >= BLOCK_SIZE * 8)
                {
                    gBG2XPosition = BLOCK_SIZE * 8;
                    ENDING_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                        BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;
                    ENDING_DATA.timer = 0;
                    ENDING_DATA.unk_1++;
                }
            }
            break;

        case 7:
            if (ENDING_DATA.timer++ > 64)
            {
                ENDING_DATA.unk_124[0] = 1;
                ENDING_DATA.timer = 0;
                ENDING_DATA.unk_1++;
            }
            break;

        case 8:
            if (ENDING_DATA.timer++ > 23)
            {
                if (gBG1XPosition >= 10)
                {
                    gBG1XPosition -= 10;
                }
                else
                {
                    gBG1XPosition = 0;
                    ENDING_DATA.timer = 0;
                    ENDING_DATA.unk_1++;
                }
            }
            break;

        case 9:
            if (ENDING_DATA.timer++ > 31)
            {
                ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_BG2 | DCNT_BG3;
                
                if (ENDING_DATA.endingNumber != 0)
                {
                    ENDING_DATA.unk_124[0] = 3;
                }
                else
                {
                    ENDING_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                        BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;
                    ENDING_DATA.unk_124[0] = 1;
                }
                
                ENDING_DATA.timer = 0;
                ENDING_DATA.unk_1++;
            }
            break;

        case 10:
            if (ENDING_DATA.timer++ > 288)
                ENDING_DATA.unk_124[1] = 32;
            break;
    }

    switch (ENDING_DATA.unk_124[0])
    {
        case 1:
            if (ENDING_DATA.endScreenTimer & 1)
            {
                if (gWrittenToBLDALPHA_L != 0)
                    gWrittenToBLDALPHA_L--;
                else
                {
                    ENDING_DATA.unk_124[0] = 0;
                    ENDING_DATA.unk_124[1]++;
                }

                gWrittenToBLDALPHA_H = 16 - gWrittenToBLDALPHA_L;
            }
            break;

        case 2:
            if (ENDING_DATA.endScreenTimer & 3)
                break;

            if (gWrittenToBLDALPHA_L < 16)
                gWrittenToBLDALPHA_L++;
            else
            {
                ENDING_DATA.unk_124[0] = 0;
                ENDING_DATA.unk_124[1]++;
            }
            break;

        case 3:
            ++ENDING_DATA.unk_160[0];
            temp = ENDING_DATA.unk_160[0];
            if ((u8)temp >= 16)
            {
                ENDING_DATA.unk_160[0] = 0;
                ENDING_DATA.unk_124[1] = 16;
                break;
            }
            dma_set(3, sEndingWhitePalPointers[(u8)temp / 4],
                PALRAM_BASE, DMA_ENABLE << 16 | ARRAY_SIZE(sEndingPosingPAL_White1));
            break;

        case 4:
            if (!(ENDING_DATA.endScreenTimer & 1))
                break;

            if (gWrittenToBLDY_NonGameplay < 16)
                gWrittenToBLDY_NonGameplay++;
            else
                ENDING_DATA.unk_124[1]++;
            break;

        case 5:
            if (ENDING_DATA.endScreenTimer & 3)
                break;

            if (gWrittenToBLDY_NonGameplay)
                gWrittenToBLDY_NonGameplay--;
            else
            {
                ENDING_DATA.unk_124[0] = 0;
                ENDING_DATA.unk_124[1]++;
            }
            break;
    }

    switch (ENDING_DATA.unk_124[1])
    {
        case 1:
            write16(REG_BG1CNT, 0x5A02);
            write16(REG_BG2CNT, 0x5C09);

            LZ77UncompVRAM(sEndingSamusPosingGFX_3, VRAM_BASE);
            LZ77UncompVRAM(sEndingSamusPosingTileTable_3, VRAM_BASE + 0xD000);

            ENDING_DATA.bldcnt = 0;
            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            gBG1XPosition = BLOCK_SIZE * 4;
            ENDING_DATA.unk_124[1]++;
            break;

        case 3:
            write16(REG_BG1CNT, 0x5A01);
            write16(REG_BG2CNT, 0x5C0A);

            LZ77UncompVRAM(sEndingSamusPosingGFX_4, VRAM_BASE + 0x8000);
            LZ77UncompVRAM(sEndingSamusPosingTileTable_4, VRAM_BASE + 0xE000);

            ENDING_DATA.bldcnt = 0;
            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            gBG2XPosition = BLOCK_SIZE * 4;
            ENDING_DATA.unk_124[1]++;
            break;

        case 5:
            write16(REG_BG1CNT, 0x5A02);
            write16(REG_BG2CNT, 0x5C09);

            LZ77UncompVRAM(sEndingSamusPosingGFX_5, VRAM_BASE);
            LZ77UncompVRAM(sEndingSamusPosingTileTable_5, VRAM_BASE + 0xD000);

            ENDING_DATA.bldcnt = 0;
            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            gBG1XPosition = BLOCK_SIZE * 4;
            ENDING_DATA.unk_124[1]++;
            break;

        case 7:
            write16(REG_BG1CNT, 0x5A01);
            write16(REG_BG2CNT, 0x5C0A);

            if (ENDING_DATA.endingNumber == 0)
            {
                LZ77UncompVRAM(sEndingSamusPosingFullSuitGFX, VRAM_BASE + 0x8000);
                LZ77UncompVRAM(sEndingSamusPosingFullSuitTileTable, VRAM_BASE + 0xE000);
            }
            else if (ENDING_DATA.endingNumber == 1)
            {
                LZ77UncompVRAM(sEndingSamusPosingHelmetOffGFX, VRAM_BASE + 0x8000);
                LZ77UncompVRAM(sEndingSamusPosingHelmetOffTileTable, VRAM_BASE + 0xE000);
            }
            else
            {
                LZ77UncompVRAM(sEndingSamusPosingSuitlessGFX, VRAM_BASE + 0x8000);
                LZ77UncompVRAM(sEndingSamusPosingSuitlessTileTable, VRAM_BASE + 0xE000);
            }

            ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_BG3;
            ENDING_DATA.bldcnt = 0;
            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            gBG2XPosition = 0;

            ENDING_DATA.unk_124[1]++;
            break;

        case 9:
            ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG2 | DCNT_BG3;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;
            
            gWrittenToBLDALPHA_L = 0;
            gWrittenToBLDALPHA_H = 16;
            ENDING_DATA.unk_124[0] = 2;
            ENDING_DATA.unk_124[1]++;
            break;

        case 16:
            ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_BG2 | DCNT_BG3;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;
            
            ENDING_DATA.unk_124[0]++;
            ENDING_DATA.unk_124[1]++;
            break;

        case 18:
            ENDING_DATA.dispcnt = DCNT_BG2 | DCNT_BG3;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
                BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;
            
            ENDING_DATA.unk_124[0]++;
            ENDING_DATA.unk_124[1]++;
            break;

        case 19:
            dma_set(3, sEndingPosingPAL, PALRAM_BASE, DMA_ENABLE << 16 | 0x50);
            ENDING_DATA.unk_124[1]++;
            break;

        case 32:
            ENDING_DATA.dispcnt = DCNT_BG2 | DCNT_BG3;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
                BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            ended++;
            break;
    }

    if (!(ENDING_DATA.endScreenTimer & 7))
        gBG3XPosition++;

    return ended;
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

/**
 * @brief 86c8c | 1ec | Handles the ending image displaying
 * 
 * @return u8 bool, ended
 */
u8 EndingImageDisplay(void)
{
    u8 ended;
    u8 i;

    ended = FALSE;

    switch (ENDING_DATA.timer++)
    {
        case 0:
            ENDING_DATA.unk_8++;
            break;

        case 30:
            EndingImageLoadTextOAM(0);
            ENDING_DATA.unk_1 = TRUE;
            break;

        case 110:
            EndingImageDisplayLinePermanently(0);
            break;

        case 180:
            EndingImageDisplayLinePermanently(1);
            if (gEndingFlags & ENDING_FLAG_NEW_TIME_ATTACK_RECORD)
                ENDING_DATA.unk_141++;
            break;

        case 330:
            EndingImageLoadTextOAM(1);
            break;

        case 375:
            if (ENDING_DATA.language == LANGUAGE_JAPANESE || ENDING_DATA.language == LANGUAGE_ENGLISH ||
                ENDING_DATA.language == LANGUAGE_ITALIAN)
                EndingImageDisplayLinePermanently(2);
            break;

        case 380:
            if (ENDING_DATA.language == LANGUAGE_JAPANESE || ENDING_DATA.language == LANGUAGE_ENGLISH ||
                ENDING_DATA.language == LANGUAGE_ITALIAN)
                EndingImageLoadTextOAM(2);
            break;

        case 460:
            EndingImageDisplayLinePermanently(3);
            break;

        case 530:
            EndingImageDisplayLinePermanently(4);
            break;

        case 780:
            if (ENDING_DATA.language != LANGUAGE_HIRAGANA)
                EndingImageDisplayLinePermanently(5);
            break;

        case 1376:
            if (gChangedInput & (KEY_A | KEY_B | KEY_START))
                FadeMusic(256);
            else
                ENDING_DATA.timer--;
            break;

        case 1664:
            ended = TRUE;
    }

    if (ENDING_DATA.unk_8)
    {
        if (gBG0YPosition > 6)
        {
            gBG0YPosition -= 6;
            gBG1YPosition -= 6;
        }
        else
        {
            gBG0YPosition = 0;
            gBG1YPosition = 0;
            ENDING_DATA.unk_8 = FALSE;
        }
    }

    if (ENDING_DATA.timer > 1380)
        return ended;

    if (ENDING_DATA.timer > 809 && gButtonInput & (KEY_R | KEY_L))
        return ended;

    if (ENDING_DATA.unk_1 == TRUE)
    {
        for (i = 6; i < ENDING_DATA.oamLength; i++)
            EndingImageCheckDisplayLetter(i);
    }

    EndingImageDisplayText();

    return ended;
}

/**
 * @brief 86e78 | 158 | Initializes the unlocked options
 * 
 */
void UnlockedOptionsInit(void)
{
    u32 zero;

    write16(REG_IME, FALSE);
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) & ~IF_HBLANK);
    write16(REG_IF, IF_HBLANK);

    write16(REG_IME, TRUE);
    write16(REG_DISPCNT, 0);

    write16(REG_IME, FALSE);
    CallbackSetVBlank(UnlockedOptionsVBlank);
    write16(REG_IME, TRUE);

    zero = 0;
    dma_set(3, &zero, &gNonGameplayRAM, (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | sizeof(gNonGameplayRAM) / 4);
    ClearGfxRam();

    LZ77UncompVRAM(sUnlockedOptionsTileTable, VRAM_BASE + 0x8000);
    BitFill(3, -1, VRAM_BASE + 0x7FE0, 0x20, 32);
    BitFill(3, 0xF3FFF3FF, VRAM_BASE + 0x8800, 0x800, 32);

    dma_set(3, sUnlockedOptionsPAL, PALRAM_BASE + 0x1E0, DMA_ENABLE << 16 | ARRAY_SIZE(sUnlockedOptionsPAL));

    write16(REG_BG0CNT, 0x1000);
    write16(REG_BG1CNT, 0x1101);

    gNextOamSlot = 0;
    ResetFreeOAM();

    write16(REG_BG0HOFS, 0);
    write16(REG_BG0VOFS, 0);

    ENDING_DATA.dispcnt = 0;
    ENDING_DATA.bldcnt = 0;

    gWrittenToBLDALPHA_L = 16;
    gWrittenToBLDALPHA_H = 0;

    gWrittenToBLDY_NonGameplay = 16;

    EndScreenVBlank();
}

/**
 * @brief 86fd0 | 20c | Handlkes the pop up displaying what's been unlocked
 * 
 * @return u8 0, 1 pop up ended, 2 ended
 */
u8 UnlockedOptionsPopUp(void)
{
    u32 msgNumber;
    u8 ended;

    ended = FALSE;

    switch (ENDING_DATA.timer++)
    {
        case 0:
            BitFill(3, 0, VRAM_BASE, 0x2000, 32);

            if (gEndingFlags & ENDING_FLAG_FIRST_CLEAR)
                msgNumber = FILE_SCREEN_TEXT_GALLERY_UNLOCK;
            else if (gEndingFlags & ENDING_FLAG_FIRST_HARD_MODE_CLEAR)
                msgNumber = FILE_SCREEN_TEXT_SOUND_TEST_UNLOCK;
            else if (gEndingFlags & ENDING_FLAG_FIRST_TIME_ATTACK_CLEAR)
                msgNumber = FILE_SCREEN_TEXT_TIME_ATTACK_RECORD_UNLOCK;
            else
                msgNumber = FILE_SCREEN_TEXT_NES_METROID_UNLOCK;

            TextStartFileScreen(msgNumber);
            ENDING_DATA.unk_124[0] = 0;
            break;

        case 32:
            ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_WIN0;
            write16(REG_WININ, 3);
            write16(REG_WINOUT, 0);
            ENDING_DATA.unk_1++;

            ENDING_DATA.oamXPositions[0] = 0x78;
            ENDING_DATA.oamXPositions[1] = 0x78;
            ENDING_DATA.oamYPositions[0] = 0x50;
            ENDING_DATA.oamYPositions[1] = 0x50;
            break;

        case 128:
            ENDING_DATA.timer--;
            break;
    }

    if (ENDING_DATA.unk_124[0] == 0)
        ENDING_DATA.unk_124[0] = TextProcessFileScreen();

    if (ENDING_DATA.unk_1 == 1)
    {
        if (ENDING_DATA.oamXPositions[0] > 0x30)
        {
            ENDING_DATA.oamXPositions[0] -= 8;
            ENDING_DATA.oamXPositions[1] += 8;
            ENDING_DATA.oamYPositions[0] -= 4;
            ENDING_DATA.oamYPositions[1] += 4;
        }
        else
        {
            ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_WIN0;

            ENDING_DATA.oamXPositions[0] = 0x2C;
            ENDING_DATA.oamXPositions[1] = 0xBC;
            ENDING_DATA.oamYPositions[0] = 0x2C;
            ENDING_DATA.oamYPositions[1] = 0x74;
            ENDING_DATA.unk_1++;
        }
    }
    else if (ENDING_DATA.unk_1 == 2)
    {
        if (gChangedInput & KEY_A)
        {
            ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_WIN0;
            ENDING_DATA.unk_1++;
            ENDING_DATA.timer++;
        }
    }
    else if (ENDING_DATA.unk_1 == 3)
    {
        if (ENDING_DATA.oamXPositions[0] < 0x70)
        {
            ENDING_DATA.oamXPositions[0] += 8;
            ENDING_DATA.oamXPositions[1] -= 8;
            ENDING_DATA.oamYPositions[0] += 4;
            ENDING_DATA.oamYPositions[1] -= 4;
        }
        else
        {
            ENDING_DATA.dispcnt = 0;

            if (gEndingFlags & ENDING_FLAG_FIRST_CLEAR)
                ended++;
            else
                ended += 2;
        }
    }

    return ended;
}

u32 CreditsSubroutine(void)
{

}

/**
 * @brief 873e4 | 238 | Initializes the gallery
 * 
 */
void GalleryInit(void)
{
    u32 zero;
    u32 endingNbr;
    u32 i;
    u32 bit;

    write16(REG_IME, FALSE);
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) & ~IF_HBLANK);
    write16(REG_IF, IF_HBLANK);

    write16(REG_IME, TRUE);
    write16(REG_DISPCNT, 0);

    write16(REG_IME, FALSE);
    CallbackSetVBlank(GalleryVBlank);
    write16(REG_IME, TRUE);

    if (gGameModeSub1 == 0)
    {
        ClearGfxRam();

        zero = 0;
        dma_set(3, &zero, &gNonGameplayRAM, (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | sizeof(gNonGameplayRAM) / 4);
    }

    endingNbr = ENDING_DATA.endingNumber;

    for (i = 0; i < 8; i++)
    {
        bit = 1 << endingNbr;
        if (gFileScreenOptionsUnlocked.galleryImages & bit)
            break;

        if (ENDING_DATA.completionPercentage != 0)
        {
            if (endingNbr != 0)
                endingNbr--;
            else
                endingNbr = 7;
        }
        else
        {
            if (endingNbr < 7)
                endingNbr++;
            else
                endingNbr = 0;
        }
    }

    ENDING_DATA.endingNumber = endingNbr;

    LZ77UncompVRAM(sEndingImagesTopHalfGfxPointers[endingNbr], VRAM_BASE);
    LZ77UncompVRAM(sEndingImagesLowerHalfGfxPointers[endingNbr], VRAM_BASE + 0x8000);
    LZ77UncompVRAM(sEndingImagesTopHalfTileTablePointers[endingNbr], VRAM_BASE + 0xE000);
    LZ77UncompVRAM(sEndingImagesLowerHalfTileTablePointers[endingNbr], VRAM_BASE + 0xF800);

    BitFill(3, 0x4FF04FF, VRAM_BASE + 0xE800, 0x800, 32);

    dma_set(3, sEndingImagesPalPointers[endingNbr], PALRAM_BASE, DMA_ENABLE << 16 | PALRAM_SIZE / 4);

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
    write16(REG_BG0VOFS, 0x1000);
    write16(REG_BG1HOFS, 0);
    write16(REG_BG1VOFS, 0x1000);
    write16(REG_BG2HOFS, 0);
    write16(REG_BG2VOFS, 0);
    write16(REG_BG3HOFS, 0);
    write16(REG_BG3VOFS, 0);

    ENDING_DATA.unk_8 = 0;

    ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_OBJ;
    ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
        BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
        BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

    GalleryVBlank();
}

#define GALLERY_RESET_BG_POS()\
do {                          \
gBG0YPosition = 0;            \
gBG1YPosition = 0;            \
} while(0);

/**
 * @brief 8761c | 15c | Handles the display of the gallery image
 * 
 * @return u32 
 */
u32 GalleryDisplay(void)
{
    u8 endingNbr;
    u32 ended;
    i32 velocity;
    u32 change;
    u8 complPercent;
    u8 bit;

    endingNbr = ENDING_DATA.endingNumber;
    bit = 1 << endingNbr;
    ended = FALSE;
    change = FALSE;
    complPercent = 0;

    if (gChangedInput & KEY_B)
    {
        ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
            BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
            BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

        gWrittenToBLDY_NonGameplay = 0;
        ended = TRUE;
    }
    else if (gChangedInput & (KEY_A | KEY_RIGHT))
    {
        if (endingNbr < 7)
            endingNbr++;
        else
            endingNbr = 0;
        
        if (gFileScreenOptionsUnlocked.galleryImages > bit)
            change++;
    }
    else if (gChangedInput & KEY_LEFT)
    {
        if (endingNbr != 0)
            endingNbr--;
        else
            endingNbr = 7;

        complPercent++;
        if (gFileScreenOptionsUnlocked.galleryImages > bit)
            change++;
    }

    
    if (change)
    {
        ENDING_DATA.endingNumber = endingNbr;
        ENDING_DATA.completionPercentage = complPercent;

        ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
            BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
            BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

        gWrittenToBLDY_NonGameplay = 0;
        gGameModeSub1 = 5;
    }

    change = FALSE;
    velocity = 8;

    if (ENDING_DATA.unk_8 != 0)
    {
        if (gButtonInput & KEY_DOWN)
            change = TRUE;

        velocity = 12;
    }

    if (!change)
    {
        if (gBG0YPosition > velocity)
        {
            gBG0YPosition -= velocity;
            gBG1YPosition -= velocity;
        }
        else
        {
            GALLERY_RESET_BG_POS();
            ENDING_DATA.unk_8 = TRUE;
        }
    }
    else
    {
        gBG0YPosition += velocity;
        gBG1YPosition += velocity;

        if (gBG0YPosition > BLOCK_SIZE * 64)
        {
            gBG0YPosition = BLOCK_SIZE * 64;
            gBG1YPosition = BLOCK_SIZE * 64;
        }
    }

    return ended;
}

/**
 * @brief 87778 | d8 | Subroutine for the gallery
 * 
 * @return u32 
 */
u32 GallerySubroutine(void)
{
    u32 ended;

    ended = FALSE;
    ENDING_DATA.unk_6 = 0;

    switch (gGameModeSub1)
    {
        case 0:
        case 4:
            GalleryInit();
            gGameModeSub1 = 1;
            break;

        case 1:
            if (gWrittenToBLDY_NonGameplay != 0)
            {
                gWrittenToBLDY_NonGameplay--;
                break;
            }

            ENDING_DATA.bldcnt = 0;
            gGameModeSub1++;
            break;

        case 2:
            if (GalleryDisplay())
                gGameModeSub1++;
            break;

        case 3:
        case 5:
            if (gWrittenToBLDY_NonGameplay < 16)
            {
                if (ENDING_DATA.timer++ & 1)
                    gWrittenToBLDY_NonGameplay++;

                break;
            }

            if (gGameModeSub1 == 3)
                ended++;
            else
                gGameModeSub1 = 4;
            break;
    }

    return ended;
}
