#include "fusion_gallery.h"

#include "data/shortcut_pointers.h"
#include "data/fusion_gallery_data.h"

#include "constants/audio.h"
#include "constants/ending_and_gallery.h"
#include "constants/game_state.h"
#include "constants/text.h"

#include "structs/bg_clip.h"
#include "structs/display.h"
#include "structs/fusion_gallery.h"
#include "structs/game_state.h"

/**
 * @brief 847f8 | 78 | V-blank code for the fusion gallery
 * 
 */
void FusionGalleryVBlank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / sizeof(u32));

    write16(REG_DISPCNT, FUSION_GALLERY_DATA.dispcnt);
    write16(REG_BLDCNT, FUSION_GALLERY_DATA.bldcnt);

    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_BG0VOFS, (gBg0YPosition / 16) & 0x1FF);
    write16(REG_BG1VOFS, (gBg1YPosition / 16) & 0x1FF);
}

void FusionGalleryInit(void)
{
    u32 zero;
    u32 image;

    write16(REG_IME, FALSE);
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) & ~IF_HBLANK);
    write16(REG_IF, IF_HBLANK);

    write16(REG_IME, TRUE);
    write16(REG_DISPCNT, 0);

    write16(REG_IME, FALSE);
    CallbackSetVBlank(FusionGalleryVBlank);
    write16(REG_IME, TRUE);

    if (gGameModeSub1 == 0)
    {
        ClearGfxRam();
        zero = 0;
        DMA_SET(3, &zero, &gNonGameplayRAM, (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | sizeof(gNonGameplayRAM) / 4);
    }

    image = FUSION_GALLERY_DATA.currentImage;
    LZ77UncompVRAM(sFusionGalleryData[image].pTopGfx, VRAM_BASE);
    LZ77UncompVRAM(sFusionGalleryData[image].pBottomGfx, VRAM_BASE + 0x8000);
    LZ77UncompVRAM(sFusionGalleryData[image].pTopTileTable, VRAM_BASE + 0xE000);
    LZ77UncompVRAM(sFusionGalleryData[image].pBottomTileTable, VRAM_BASE + 0xF800);

    BitFill(3, 0x4FF04FF, VRAM_BASE + 0xE800, 0x800, 32);
    DMA_SET(3, sFusionGalleryData[image].pPalette, PALRAM_BASE, DMA_ENABLE << 16 | PALRAM_SIZE / 4);

    write16(REG_BG0CNT, 0x9C00);
    write16(REG_BG1CNT, 0x9E09);

    gNextOamSlot = 0;
    ResetFreeOam();

    gBg0XPosition = 0;
    gBg0YPosition = 0x1000;
    gBg1XPosition = 0;
    gBg1YPosition = 0x1000;
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    write16(REG_BG0HOFS, 0);
    write16(REG_BG0VOFS, 0x1000);
    write16(REG_BG1HOFS, 0);
    write16(REG_BG1VOFS, 0x1000);
    write16(REG_BG2HOFS, 0);
    write16(REG_BG2VOFS, 0);
    write16(REG_BG3HOFS, 0);
    write16(REG_BG3VOFS, 0);

    FUSION_GALLERY_DATA.unk_2 = 0;
    FUSION_GALLERY_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_OBJ;
    ENDING_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET |
        BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

    FusionGalleryVBlank();
}

/**
 * @brief 84a40 | 120 | Handles the display of the fusion gallery image
 * 
 * @return u32 bool, ended
 */
u32 FusionGalleryDisplay(void)
{
    u8 imageId;
    u32 ended;
    s32 velocity;
    u32 change;
    u8 complPercent;
    u8 bit;

    ended = FALSE;
    change = FALSE;
    imageId = FUSION_GALLERY_DATA.currentImage;
    complPercent = 0;

    if (gChangedInput & KEY_B)
    {
        FUSION_GALLERY_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
            BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
            BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

        gWrittenToBLDY_NonGameplay = 0;
        ended = TRUE;
    }
    else if (gChangedInput & (KEY_A | KEY_RIGHT))
    {
        if (imageId < NUMBER_OF_FUSION_GALLERY_IMAGES - 1)
            imageId++;
        else
            imageId = 0;
        
        change++;
    }
    else if (gChangedInput & KEY_LEFT)
    {
        if (imageId != 0)
            imageId--;
        else
            imageId = NUMBER_OF_FUSION_GALLERY_IMAGES - 1;

        change++;
    }

    
    if (change)
    {
        FUSION_GALLERY_DATA.currentImage = imageId;

        FUSION_GALLERY_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
            BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
            BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

        gWrittenToBLDY_NonGameplay = 0;
        gGameModeSub1 = 5;
    }

    change = FALSE;
    velocity = 8;

    if (FUSION_GALLERY_DATA.unk_2 != 0)
    {
        if (gButtonInput & KEY_DOWN)
            change = TRUE;

        velocity = 12;
    }

    if (!change)
    {
        if (gBg0YPosition > velocity)
        {
            gBg0YPosition -= velocity;
            gBg1YPosition -= velocity;
        }
        else
        {
            GALLERY_RESET_BG_POS();
            FUSION_GALLERY_DATA.unk_2 = TRUE;
        }
    }
    else
    {
        gBg0YPosition += velocity;
        gBg1YPosition += velocity;

        if (gBg0YPosition > BLOCK_SIZE * 64)
        {
            gBg0YPosition = BLOCK_SIZE * 64;
            gBg1YPosition = BLOCK_SIZE * 64;
        }
    }

    return ended;
}

/**
 * @brief 84b60 | d4 | Fusion gallery subroutine
 * 
 * @return u32 bool, ended
 */
u32 FusionGallerySubroutine(void)
{
    u32 ended;

    ended = FALSE;
    FUSION_GALLERY_DATA.stage = 0;

    switch (gGameModeSub1)
    {
        case 0:
        case 4:
            FusionGalleryInit();
            gGameModeSub1 = 1;
            break;

        case 1:
            if (gWrittenToBLDY_NonGameplay != 0)
            {
                gWrittenToBLDY_NonGameplay--;
                break;
            }

            FUSION_GALLERY_DATA.bldcnt = 0;
            gGameModeSub1++;
            break;

        case 2:
            if (FusionGalleryDisplay())
                gGameModeSub1++;
            break;

        case 3:
        case 5:
            if (gWrittenToBLDY_NonGameplay < 16)
            {
                if (FUSION_GALLERY_DATA.unk_94++ & 1)
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
