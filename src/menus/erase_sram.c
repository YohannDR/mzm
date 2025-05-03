#include "menus/erase_sram.h"
#include "macros.h"
#include "callbacks.h"

#include "data/shortcut_pointers.h"
#include "data/menus/erase_sram_data.h"
#include "data/menus/internal_erase_sram_data.h"
#include "data/menus/title_screen_data.h"
#include "data/menus/pause_screen_data.h"

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

    APPLY_DELTA_TIME_INC(ERASE_SRAM_DATA.timer);
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

            ERASE_SRAM_DATA.bldcnt = (BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT) & ~BLDCNT_OBJ_FIRST_TARGET_PIXEL;
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
            if (ERASE_SRAM_DATA.timer <= TWO_THIRD_SECOND)
                break;

            ERASE_SRAM_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

            ERASE_SRAM_DATA.timer = 0;
            gGameModeSub1++;
            break;

        case 4:
            if (gWrittenToBLDY_NonGameplay < BLDY_MAX_VALUE)
            {
                gWrittenToBLDY_NonGameplay++;
                break;
            }

            ERASE_SRAM_DATA.dispcnt &= ~(DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);
            leaving = TRUE;
            break;

        case 5:
            if (ERASE_SRAM_DATA.timer <= TWO_THIRD_SECOND)
                break;

            ERASE_SRAM_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            ERASE_SRAM_DATA.timer = 0;
            gGameModeSub1++;
            break;

        case 6:
            if (gWrittenToBLDY_NonGameplay < BLDY_MAX_VALUE)
            {
                gWrittenToBLDY_NonGameplay++;
                break;
            }

            gGameModeSub1++;
            ERASE_SRAM_DATA.dispcnt = DCNT_BLANK;
            break;

        case 7:
            RestartSound();
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

    ERASE_SRAM_DATA.oam[1].exists = OAM_ID_CHANGED_FLAG;
    ERASE_SRAM_DATA.oam[2].exists = OAM_ID_CHANGED_FLAG;

    ERASE_SRAM_DATA.oam[0].oamID = ERASE_SRAM_OAM_ID_CURSOR_IDLE;
    ERASE_SRAM_DATA.oam[0].exists = OAM_ID_CHANGED_FLAG;
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
                sound = ERASE_SRAM_SOUND_CURSOR;
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
                sound = ERASE_SRAM_SOUND_CURSOR;
                break;
            }

            if (gChangedInput & KEY_A)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_CONFIRM_NO;
                sound = ERASE_SRAM_SOUND_SELECT_YES;
                ERASE_SRAM_DATA.bldyTarget = 4;
            }
            break;

        case ERASE_SRAM_OPTION_CONFIRM_NO:
            if (gChangedInput & KEY_RIGHT)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_CONFIRM_YES;
                sound = ERASE_SRAM_SOUND_CURSOR;
                break;
            }

            if (gChangedInput & (KEY_A | KEY_B))
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_QUESTION_NO;
                ERASE_SRAM_DATA.bldyTarget = 0;
                sound = ERASE_SRAM_SOUND_REFUSE;
            }
            break;

        case ERASE_SRAM_OPTION_CONFIRM_YES:
            if (gChangedInput & KEY_LEFT)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_CONFIRM_NO;
                sound = ERASE_SRAM_SOUND_CURSOR;
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
                sound = ERASE_SRAM_SOUND_REFUSE;
                ERASE_SRAM_DATA.bldyTarget = 0;
            }
            break;
    }

    if (exiting)
    {
        ERASE_SRAM_DATA.oam[0].oamID = ERASE_SRAM_OAM_ID_CURSOR_SELECTING;
        ERASE_SRAM_DATA.oam[0].exists = OAM_ID_CHANGED_FLAG;
        sound = ERASE_SRAM_SOUND_CONFIRM;
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

    write16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);

    write16(REG_BLDY, gWrittenToBLDY_NonGameplay = BLDY_MAX_VALUE);

    zero = 0;
    DMA_SET(3, &zero, &gNonGameplayRam, C_32_2_16(DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED, sizeof(gNonGameplayRam) / sizeof(u32)));

    ClearGfxRam();
    gNextOamSlot = 0;
    ResetFreeOam();

    ERASE_SRAM_DATA.language = gLanguage;
    #ifdef DEBUG
    if (ERASE_SRAM_DATA.language > LANGUAGE_SPANISH)
    #else // !DEBUG
    if (ERASE_SRAM_DATA.language < LANGUAGE_ENGLISH || ERASE_SRAM_DATA.language > LANGUAGE_SPANISH)
    #endif // DEBUG
    {
        ERASE_SRAM_DATA.language = LANGUAGE_ENGLISH;
    }

    while (read16(REG_VCOUNT) >= 21 && read16(REG_VCOUNT) <= SCREEN_SIZE_Y);

    DMA_SET(3, sEraseSramMenuBackgroundPal, PALRAM_BASE, C_32_2_16(DMA_ENABLE, (13 * PAL_ROW_SIZE) / sizeof(u16)));
    DMA_SET(3, sEraseSramMenuObjectsPal, PALRAM_OBJ, C_32_2_16(DMA_ENABLE, sizeof(sEraseSramMenuObjectsPal) / sizeof(u16)));
    SET_BACKDROP_COLOR(COLOR_BLACK);

    LZ77UncompVRAM(sEraseSramMenuFirstBoxGfx, VRAM_BASE + 0x1000);
    LZ77UncompVRAM(sEraseSramMenuObjectsGfx, VRAM_BASE + 0x12000);
    LZ77UncompVRAM(sTitleScreenSpaceBackgroundDecorationGfx, VRAM_BASE + 0x1800);
    LZ77UncompVRAM(sTitleScreenSpaceAndGroundBackgroundGfx, VRAM_BASE + 0x3400);

    LZ77UncompVRAM(sEraseSramTextGfxPointers[ERASE_SRAM_DATA.language][0], VRAM_BASE);
    LZ77UncompVRAM(sEraseSramTextGfxPointers[ERASE_SRAM_DATA.language][1], VRAM_BASE + 0x11000);
    LZ77UncompVRAM(sEraseSramTextGfxPointers[ERASE_SRAM_DATA.language][0], VRAM_OBJ);

    LZ77UncompVRAM(sEraseSramMenuBoxTileTable, VRAM_BASE + 0xD000);
    LZ77UncompVRAM(sEraseSramMenuBackgroundTileTable, VRAM_BASE + 0xF000);

    write16(REG_BG0CNT, 0);
    write16(REG_BG2CNT, 0);
    
    write16(REG_BG1CNT, CREATE_BGCNT(0, 26, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    write16(REG_BG3CNT, CREATE_BGCNT(0, 30, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    gWrittenToBLDALPHA_H = 0;
    write16(REG_BLDALPHA, 0);

    gGameModeSub3 = 0;

    gBg1HOFS_NonGameplay = 0;
    gBg1VOFS_NonGameplay = 0;
    gBg3HOFS_NonGameplay = 0;
    gBg3VOFS_NonGameplay = 0;

    EraseSramResetOam();
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
void EraseSramResetOam(void)
{
    s32 i;
    
    gOamXOffset_NonGameplay = 0;
    gOamYOffset_NonGameplay = 0;

    ERASE_SRAM_DATA.currentOption = ERASE_SRAM_OPTION_QUESTION_NO;
    ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_QUESTION_NO;

    for (i = 0; i < ARRAY_SIZE(ERASE_SRAM_DATA.oam); i++)
        ERASE_SRAM_DATA.oam[i] = sMenuOamDataEraseSram_Empty;

    ERASE_SRAM_DATA.oam[2].oamID = sEraseSramQuestionWindowNoSelectedOamId;
    ERASE_SRAM_DATA.oam[2].yPosition = sEraseSramMenuCursorPosition[0][1];
    ERASE_SRAM_DATA.oam[2].xPosition = sEraseSramMenuCursorPosition[0][0];
    ERASE_SRAM_DATA.oam[2].exists = TRUE;

    ERASE_SRAM_DATA.oam[1].oamID = 0;
    ERASE_SRAM_DATA.oam[1].yPosition = sEraseSramMenuCursorPosition[1][1];
    ERASE_SRAM_DATA.oam[1].xPosition = sEraseSramMenuCursorPosition[1][0];
    ERASE_SRAM_DATA.oam[1].exists = TRUE;

    ERASE_SRAM_DATA.oam[0].oamID = ERASE_SRAM_OAM_ID_CURSOR_IDLE;
    ERASE_SRAM_DATA.oam[0].exists = TRUE;
}

/**
 * @brief 76298 | 48 | Updates the cursor position based on the current option
 * 
 */
void EraseSramUpdateCursorPosition(void)
{
    // Panel position + option position
    ERASE_SRAM_DATA.oam[0].yPosition = sEraseSramMenuCursorPosition[DIV_SHIFT(ERASE_SRAM_DATA.currentOption, 2)][1] +
        sEraseSramMenuCursorPositionOffset[ERASE_SRAM_DATA.currentOption][1];

    ERASE_SRAM_DATA.oam[0].xPosition = sEraseSramMenuCursorPosition[DIV_SHIFT(ERASE_SRAM_DATA.currentOption, 2)][0] +
        sEraseSramMenuCursorPositionOffset[ERASE_SRAM_DATA.currentOption][0];
}

/**
 * @brief 762e0 | 78 | Erase sram menu V-blank code
 * 
 */
void EraseSramVBlank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16(DMA_ENABLE | DMA_32BIT, OAM_SIZE / sizeof(u32)));

    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_BG1HOFS, SUB_PIXEL_TO_PIXEL(gBg1HOFS_NonGameplay));
    write16(REG_BG1VOFS, SUB_PIXEL_TO_PIXEL(gBg1VOFS_NonGameplay));

    write16(REG_BG3HOFS, SUB_PIXEL_TO_PIXEL(gBg3HOFS_NonGameplay));
    write16(REG_BG3VOFS, SUB_PIXEL_TO_PIXEL(gBg3VOFS_NonGameplay));

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
    ProcessMenuOam(ARRAY_SIZE(ERASE_SRAM_DATA.oam), ERASE_SRAM_DATA.oam, sEraseSramMenuOam);
    ResetFreeOam();
}

