#include "menus/erase_sram.h"
#include "macros.h"
#include "callbacks.h"
#include "data/shortcut_pointers.h"
#include "data/menus/erase_sram_data.h"
#include "data/menus/internal_erase_sram_data.h"
#include "data/menus/title_screen_data.h"

#include "constants/audio.h"
#include "constants/game_state.h"
#include "constants/menus/erase_sram.h"

#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/menus/erase_sram.h"

/**
 * @brief 75c30 | 14c | Subroutine for the erase sram menu
 * 
 * @return u32 bool, leaving
 */
u32 EraseSramSubroutine(void)
{
    u32 leaving;

    leaving = FALSE;

    ERASE_SRAM_DATA.timer++;
    switch (gGameModeSub1)
    {
        case 0:
            EraseSramInit();
            gGameModeSub1++;
            break;

        case 1:
            if (gWrittenToBLDY_NonGameplay != 0)
            {
                gWrittenToBLDY_NonGameplay--;
                break;
            }

            ERASE_SRAM_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            ERASE_SRAM_DATA.bldyTarget = gWrittenToBLDY_NonGameplay;

            gGameModeSub1++;
            ERASE_SRAM_DATA.timer = 0;
            break;

        case 2:
            gGameModeSub2 = EraseSramProcessInput();
            if (gGameModeSub2 == 0)
                break;

            ERASE_SRAM_DATA.timer = 0;
            if (gGameModeSub2 == ERASE_SRAM_INPUT_ACTION_ERASING)
                gGameModeSub1 = 5;
            else
                gGameModeSub1 = 3;
            break;

        case 3:
            if (ERASE_SRAM_DATA.timer <= 40)
                break;

            ERASE_SRAM_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
                BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            ERASE_SRAM_DATA.timer = 0;
            gGameModeSub1++;
            break;

        case 4:
            if (gWrittenToBLDY_NonGameplay < 16)
            {
                gWrittenToBLDY_NonGameplay++;
                break;
            }

            ERASE_SRAM_DATA.dispcnt &= ~(DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);
            leaving = TRUE;
            break;

        case 5:
            if (ERASE_SRAM_DATA.timer <= 40)
                break;

            ERASE_SRAM_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
                BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            ERASE_SRAM_DATA.timer = 0;
            gGameModeSub1++;
            break;

        case 6:
            if (gWrittenToBLDY_NonGameplay < 16)
            {
                gWrittenToBLDY_NonGameplay++;
                break;
            }

            gGameModeSub1++;
            ERASE_SRAM_DATA.dispcnt = DCNT_BLANK;
            break;

        case 7:
            unk_33dc();
            EraseSram();
            leaving = TRUE;
    }

    if (!leaving)
        EraseSramProcessOAM();

    return leaving;
}

/**
 * @brief 75d7c | 54 | Processes the input for the erase sram menu
 * 
 * @return u32 action
 */
u32 EraseSramProcessInput(void)
{
    u32 result;

    result = ERASE_SRAM_INPUT_ACTION_NONE;

    if (ERASE_SRAM_DATA.nextOption & ERASE_SRAM_OPTION_CHANGED_FLAG)
        EraseSramApplyInput();
    else
        result = EraseSramCheckForInput();

    // Update BLDY based on target
    if (ERASE_SRAM_DATA.bldyTarget != gWrittenToBLDY_NonGameplay)
    {
        if (ERASE_SRAM_DATA.bldyTarget > gWrittenToBLDY_NonGameplay)
            gWrittenToBLDY_NonGameplay++;
        else
            gWrittenToBLDY_NonGameplay--;
    }
    
    EraseSramUpdateCursorPosition();

    return result;
}

/**
 * @brief 75dd0 | ac | Applies the input
 * 
 */
void EraseSramApplyInput(void)
{
    if (ERASE_SRAM_DATA.oam[0].oamID == ERASE_SRAM_OAM_ID_CURSOR_SELECTING)
        return;

    ERASE_SRAM_DATA.nextOption &= ~ERASE_SRAM_OPTION_CHANGED_FLAG;
    ERASE_SRAM_DATA.currentOption = ERASE_SRAM_DATA.nextOption;

    switch (ERASE_SRAM_DATA.nextOption)
    {
        case ERASE_SRAM_OPTION_QUESTION_NO:
            ERASE_SRAM_DATA.oam[2].oamID = sEraseSramQuestionWindowNoSelectedOamId;
            ERASE_SRAM_DATA.oam[1].oamID = 0;
            break;

        case ERASE_SRAM_OPTION_QUESTION_YES:
            ERASE_SRAM_DATA.oam[2].oamID = sEraseSramQuestionWindowYesSelectedOamId;
            ERASE_SRAM_DATA.oam[1].oamID = 0;
            break;

        case ERASE_SRAM_OPTION_CONFIRM_NO:
            ERASE_SRAM_DATA.oam[1].oamID = sEraseSramConfirmWindowNoSelectedOamId;
            break;

        case ERASE_SRAM_OPTION_CONFIRM_YES:
            ERASE_SRAM_DATA.oam[1].oamID = sEraseSramConfirmWindowYesSelectedOamId;
            break;
    }

    ERASE_SRAM_DATA.oam[1].idChanged = TRUE << 1;
    ERASE_SRAM_DATA.oam[2].idChanged = TRUE << 1;
    ERASE_SRAM_DATA.oam[0].oamID = ERASE_SRAM_OAM_ID_CURSOR_IDLE;
    ERASE_SRAM_DATA.oam[0].idChanged = TRUE << 1;
}

/**
 * @brief 75e7c | 10c | Checks for input
 * 
 * @return u32 action
 */
u32 EraseSramCheckForInput(void)
{
    u32 sound;
    u32 result;
    u32 exiting;

    result = ERASE_SRAM_INPUT_ACTION_NONE;
    sound = 0;
    exiting = FALSE;

    switch (ERASE_SRAM_DATA.currentOption)
    {
        case ERASE_SRAM_OPTION_QUESTION_NO:
            if (gChangedInput & KEY_RIGHT)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_QUESTION_YES;
                sound = 4;
                break;
            }

            if (gChangedInput & KEY_A)
            {
                result = ERASE_SRAM_INPUT_ACTION_OPENING_SUB_WINDOW;
                exiting = TRUE;
            }
            break;

        case ERASE_SRAM_OPTION_QUESTION_YES:
            if (gChangedInput & KEY_LEFT)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_QUESTION_NO;
                sound = 4;
                break;
            }

            if (gChangedInput & KEY_A)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_CONFIRM_NO;
                sound = 2;
                ERASE_SRAM_DATA.bldyTarget = 4;
            }
            break;

        case ERASE_SRAM_OPTION_CONFIRM_NO:
            if (gChangedInput & KEY_RIGHT)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_CONFIRM_YES;
                sound = 4;
                break;
            }

            if (gChangedInput & (KEY_A | KEY_B))
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_QUESTION_NO;
                ERASE_SRAM_DATA.bldyTarget = 0;
                sound = 3;
            }
            break;

        case ERASE_SRAM_OPTION_CONFIRM_YES:
            if (gChangedInput & KEY_LEFT)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_CONFIRM_NO;
                sound = 4;
                break;
            }

            if (gChangedInput & KEY_A)
            {
                result = ERASE_SRAM_INPUT_ACTION_ERASING;
                exiting = TRUE;
                break;
            }

            if (gChangedInput & KEY_B)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_QUESTION_NO;
                sound = 3;
                ERASE_SRAM_DATA.bldyTarget = 0;
            }
            break;
    }

    if (exiting)
    {
        ERASE_SRAM_DATA.oam[0].oamID = ERASE_SRAM_OAM_ID_CURSOR_SELECTING;
        ERASE_SRAM_DATA.oam[0].idChanged = TRUE << 1;
        sound = 1;
    }

    if (sEraseSramMenuSoundsID[sound])
        SoundPlay(sEraseSramMenuSoundsID[sound]);

    return result;
}

/**
 * @brief 75f88 | 24c | Initializes the erase sram menu
 * 
 */
void EraseSramInit(void)
{
    u32 zero;

    write16(REG_IME, FALSE);
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) & ~IF_HBLANK);
    write16(REG_IF, IF_HBLANK);
    write16(REG_IME, TRUE);
    
    CallbackSetVBlank(EraseSramVBlank_Empty);

    write16(REG_BLDCNT, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
        BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
        BLDCNT_BRIGHTNESS_INCREASE_EFFECT);

    write16(REG_BLDY, gWrittenToBLDY_NonGameplay = 16);

    zero = 0;
    dma_set(3, &zero, &gNonGameplayRAM, (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | sizeof(gNonGameplayRAM) / 4);

    ClearGfxRam();
    gNextOamSlot = 0;
    ResetFreeOAM();

    ERASE_SRAM_DATA.language = gLanguage;
    if ((u8)(ERASE_SRAM_DATA.language - 2) > LANGUAGE_SPANISH - 2)
        ERASE_SRAM_DATA.language = LANGUAGE_ENGLISH;

    while ((u16)(read16(REG_VCOUNT) - 0x15) < 0x8C);

    dma_set(3, sEraseSramMenuBackgroundPAL, PALRAM_BASE, DMA_ENABLE << 16 | 0xD0);
    dma_set(3, sEraseSramMenuObjectsPAL, PALRAM_BASE + 0x200, DMA_ENABLE << 16 | sizeof(sEraseSramMenuObjectsPAL) / 2);
    write16(PALRAM_BASE, 0);

    LZ77UncompVRAM(sEraseSramMenuFirstBoxGFX, VRAM_BASE + 0x1000);
    LZ77UncompVRAM(sEraseSramMenuObjectsGFX, VRAM_BASE + 0x12000);
    LZ77UncompVRAM(sTitleScreenSpaceBackgroundDecorationGFX, VRAM_BASE + 0x1800);
    LZ77UncompVRAM(sTitleScreenSpaceAndGroundBackgroundGFX, VRAM_BASE + 0x3400);

    LZ77UncompVRAM(sEraseSramTextGfxPointers[ERASE_SRAM_DATA.language][0], VRAM_BASE);
    LZ77UncompVRAM(sEraseSramTextGfxPointers[ERASE_SRAM_DATA.language][1], VRAM_BASE + 0x11000);
    LZ77UncompVRAM(sEraseSramTextGfxPointers[ERASE_SRAM_DATA.language][0], VRAM_BASE + 0x10000);

    LZ77UncompVRAM(sEraseSramMenuBoxTileTable, VRAM_BASE + 0xD000);
    LZ77UncompVRAM(sEraseSramMenuBackgroundTileTable, VRAM_BASE + 0xF000);

    write16(REG_BG0CNT, 0);
    write16(REG_BG2CNT, 0);
    
    write16(REG_BG1CNT, 0x1A01);
    write16(REG_BG3CNT, 0x1E03);

    gWrittenToBLDALPHA_H = 0;
    write16(REG_BLDALPHA, 0);

    gGameModeSub3 = 0;

    gBG1HOFS_NonGameplay = 0;
    gBG1VOFS_NonGameplay = 0;
    gBG3HOFS_NonGameplay = 0;
    gBG3VOFS_NonGameplay = 0;

    EraseSramResetOAM();
    EraseSramUpdateCursorPosition();
    EraseSramProcessOAM();
    EraseSramVBlank();

    ERASE_SRAM_DATA.bldcnt = read16(REG_BLDCNT);
    ERASE_SRAM_DATA.dispcnt = DCNT_BG1 | DCNT_BG3 | DCNT_OBJ;
    write16(REG_DISPCNT, ERASE_SRAM_DATA.dispcnt);

    CallbackSetVBlank(EraseSramVBlank);
}

/**
 * @brief 761d4 | c4 | Initializes the OAM for the erase sram menu
 * 
 */
void EraseSramResetOAM(void)
{
    i32 i;
    
    gOamXOffset_NonGameplay = 0;
    gOamYOffset_NonGameplay = 0;

    ERASE_SRAM_DATA.currentOption = ERASE_SRAM_OPTION_QUESTION_NO;
    ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_QUESTION_NO;

    for (i = 0; i < ARRAY_SIZE(ERASE_SRAM_DATA.oam); i++)
    {
        ERASE_SRAM_DATA.oam[i] = *(struct MenuOamData*)0x840d048;
        // FIXME *pOam = sEraseSramMenuOamData_Empty;
    }

    ERASE_SRAM_DATA.oam[2].oamID = sEraseSramQuestionWindowNoSelectedOamId;
    ERASE_SRAM_DATA.oam[2].yPosition = sEraseSramMenuCursorPosition[0][1];
    ERASE_SRAM_DATA.oam[2].xPosition = sEraseSramMenuCursorPosition[0][0];
    ERASE_SRAM_DATA.oam[2].idChanged = TRUE;

    ERASE_SRAM_DATA.oam[1].oamID = 0;
    ERASE_SRAM_DATA.oam[1].yPosition = sEraseSramMenuCursorPosition[1][1];
    ERASE_SRAM_DATA.oam[1].xPosition = sEraseSramMenuCursorPosition[1][0];
    ERASE_SRAM_DATA.oam[1].idChanged = TRUE;

    ERASE_SRAM_DATA.oam[0].oamID = ERASE_SRAM_OAM_ID_CURSOR_IDLE;
    ERASE_SRAM_DATA.oam[0].idChanged = TRUE;
}

/**
 * @brief 76298 | 48 | Updates the cursor position based on the current option
 * 
 */
void EraseSramUpdateCursorPosition(void)
{
    // Panel position + option position
    ERASE_SRAM_DATA.oam[0].yPosition = sEraseSramMenuCursorPosition[ERASE_SRAM_DATA.currentOption >> 1][1] + sEraseSramMenuCursorPositionOffset[ERASE_SRAM_DATA.currentOption][1];
    ERASE_SRAM_DATA.oam[0].xPosition = sEraseSramMenuCursorPosition[ERASE_SRAM_DATA.currentOption >> 1][0] + sEraseSramMenuCursorPositionOffset[ERASE_SRAM_DATA.currentOption][0];
}

/**
 * @brief 762e0 | 78 | Erase sram menu V-blank code
 * 
 */
void EraseSramVBlank(void)
{
    dma_set(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / 4);

    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_BG1HOFS, gBG1HOFS_NonGameplay / 4);
    write16(REG_BG1VOFS, gBG1VOFS_NonGameplay / 4);

    write16(REG_BG3HOFS, gBG3HOFS_NonGameplay / 4);
    write16(REG_BG3VOFS, gBG3VOFS_NonGameplay / 4);

    write16(REG_BLDCNT, ERASE_SRAM_DATA.bldcnt);
    write16(REG_DISPCNT, ERASE_SRAM_DATA.dispcnt);
}

/**
 * @brief 76358 | c | Empty v-blank for the erase sram menu
 * 
 */
void EraseSramVBlank_Empty(void)
{
    vu8 c = 0;
}

/**
 * @brief 76364 | 2c | Processes the OAM for the erase sram menu
 * 
 */
void EraseSramProcessOAM(void)
{
    gNextOamSlot = 0;
    process_menu_oam(ARRAY_SIZE(ERASE_SRAM_DATA.oam), ERASE_SRAM_DATA.oam, sEraseSramMenuOam);
    ResetFreeOAM();
}

