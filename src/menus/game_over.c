#include "menus/game_over.h"
#include "macros.h"
#include "callbacks.h"
#include "oam_id.h"
#include "temp_globals.h"

#include "data/menus/game_over_data.h"
#include "data/menus/internal_game_over_data.h"
#include "data/menus/file_select_data.h"
#include "data/shortcut_pointers.h"
#include "data/menus/pause_screen_data.h"

#include "constants/audio.h"
#include "constants/demo.h"
#include "constants/game_over.h"
#include "constants/menus/file_select.h"

#include "structs/demo.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/samus.h"

/**
 * @brief 778c4 | 214 | Subroutine for the game over
 * 
 * @return u32 bool, ended
 */
u32 GameOverSubroutine(void)
{
    u32 ended;

    ended = FALSE;

    GAME_OVER_DATA.timer++;

    switch (gGameModeSub1)
    {
        case 0:
            if (gCurrentDemo.active)
            {
                gCurrentDemo.number++;
                gCurrentDemo.active = FALSE;

                DoSoundAction(0x194F780);
                FadeAllSounds(10);
                FadeMusic(10);
                gDemoState = DEMO_STATE_NONE;
                gGameModeSub2 = 2;
                return TRUE;
            }

            GameOverInit();
            GAME_OVER_DATA.timer = 0;
            gGameModeSub1++;
            break;

        case 1:
            if (gWrittenToBLDY_NonGameplay > 2)
            {
                gWrittenToBLDY_NonGameplay--;
                break;
            }

            GAME_OVER_DATA.dispcnt |= DCNT_WIN1;
            GAME_OVER_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;
            gGameModeSub1++;
            break;

        case 2:
            if (gWrittenToBLDY_NonGameplay < 6)
            {
                gWrittenToBLDY_NonGameplay += 2;
                if (gWrittenToBLDY_NonGameplay > 6)
                    gWrittenToBLDY_NonGameplay = 6;
                break;
            }
            GAME_OVER_DATA.dynamicPalette.enableFlags = 0x80 | 1;
            PlayMusic(MUSIC_GAME_OVER, 0);
            gGameModeSub1++;
            break;

        case 3:
            if (GameOverProcessInput())
            {
                GAME_OVER_DATA.timer = 0;
                gGameModeSub1++;
            }

            GameOverUpdateLettersPalette();
            break;
        
        case 4:
            if (GAME_OVER_DATA.oam[0].ended)
            {
                GAME_OVER_DATA.timer = 0;
                gGameModeSub1++;
            }

            GameOverUpdateLettersPalette();
            break;

        case 5:
            GameOverUpdateLettersPalette();
            gWrittenToBLDY_NonGameplay = 4;

            GAME_OVER_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
                BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            GAME_OVER_DATA.dispcnt ^= DCNT_WIN1;
            FadeMusic(20);
            gGameModeSub1++;
            break;

        case 6:
            if (gWrittenToBLDY_NonGameplay < 16)
                gWrittenToBLDY_NonGameplay++;
            else
                gGameModeSub1++;
            break;

        case 7:
            if (GAME_OVER_DATA.optionSelected == 1)
            {
                gGameModeSub2 = 1;
                ended = TRUE;
                break;
            }

            gGameModeSub2 = 4;
            gGameModeSub1++;
            break;

        case 8:
            unk_75c04(0);
            gLanguage = gGameCompletion.language;
            ended = TRUE;
            break;

        case 9:
            if (gWrittenToBLDY_NonGameplay < 16)
                gWrittenToBLDY_NonGameplay++;
            else
            {
                gGameModeSub2 = 0x10;
                ended = TRUE;
            }
            break;
    }

    GameOverProcessOAM();
    return ended;
}

/**
 * @brief 77ad4 | 78 | Handles the inputs for the game over menu
 * 
 * @return u32 bool, leaving
 */
u32 GameOverProcessInput(void)
{
    u32 doingSomething;

    doingSomething = FALSE;

    if (gChangedInput & (KEY_A | KEY_START))
    {
        FileSelectPlayMenuSound(MENU_SOUND_REQUEST_GAME_OVER_START_GAME);
        GameOverUpdateSamusHead(SAMUS_CURSOR_ACTION_SELECTING);
        return TRUE;
    }

    // Handle cursor movement
    if (gChangedInput & KEY_UP)
    {
        if (GAME_OVER_DATA.optionSelected != 0)
        {
            GAME_OVER_DATA.optionSelected = 0;
            doingSomething++;
        }
    }
    else if (gChangedInput & KEY_DOWN)
    {
        if (GAME_OVER_DATA.optionSelected != 1)
        {
            GAME_OVER_DATA.optionSelected = 1;
            doingSomething++;
        }
    }

    if (!doingSomething)
        return FALSE;

    // Update cursor
    FileSelectPlayMenuSound(MENU_SOUND_REQUEST_GAME_OVER_MENU_CURSOR);
    GameOverUpdateTextGfx();
    GameOverUpdateSamusHead(SAMUS_CURSOR_ACTION_MOVING);

    return FALSE;
}

/**
 * @brief 77b4c | 5c | Updates the graphics of the text
 * 
 */
void GameOverUpdateTextGfx(void)
{
    u8 palette;
    u16* dst;
    s32 i;

    dst = VRAM_BASE + 0x340;

    // Get palette
    if (GAME_OVER_DATA.optionSelected == 0)
        palette = 2;
    else
        palette = 3;

    // Top
    for (i = 0; i < 64; i++, dst++)
        *dst = (*dst & 0xFFF) | palette << 12;

    // Toggle palette
    palette ^= 1;
    dst += 32;

    // Bottom
    for (i = 0; i < 64; i++, dst++)
        *dst = (*dst & 0xFFF) | palette << 12;
}

/**
 * @brief 77ba8 | 230 | Initializes the game over menu
 * 
 */
void GameOverInit(void)
{
    u32 zero;

    CallbackSetVBlank(GameOverVBlank_Empty);
    zero = 0;
    DMA_SET(3, &zero, &gNonGameplayRAM, C_32_2_16(DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED, sizeof(gNonGameplayRAM) / 4));

    write16(REG_BLDCNT, GAME_OVER_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);

    write16(REG_BLDY, gWrittenToBLDY_NonGameplay = 16);
    write16(REG_DISPCNT, 0);

    gNextOamSlot = 0;
    ClearGfxRam();
    ResetFreeOam();

    gOamXOffset_NonGameplay = gOamYOffset_NonGameplay = 0;

    DoSoundAction(0x80);
    StopAllMusicsAndSounds();

    DmaTransfer(3, sGameOverMenuPal, PALRAM_BASE, sizeof(sGameOverMenuPal), 16);
    SET_BACKDROP_COLOR(COLOR_BLACK);
    DMA_SET(3, sFileSelectIconsPal, PALRAM_OBJ, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sFileSelectIconsPal)));

    LZ77UncompVRAM(sGameOverBackgroundTileTable, VRAM_BASE + 0x1800);
    LZ77UncompVRAM(sGameOverTextTileTable, VRAM_BASE + 0x800);
    LZ77UncompVRAM(sGameOver_454520, VRAM_BASE);
    DmaTransfer(3, VRAM_BASE + 0x1800, VRAM_BASE + 0x1000, 0x800, 32);
    LZ77UncompVRAM(sGameOverTextAndBackgroundGfx, VRAM_BASE + 0x4000);
    LZ77UncompVRAM(sFileSelectIconsGfx, VRAM_OBJ);
    LZ77UncompVRAM(sGameOverTextPromptGfxPointers[gLanguage], VRAM_BASE + 0xA800);

    write16(REG_BG0CNT, CREATE_BGCNT(1, 0, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    write16(REG_BG1CNT, CREATE_BGCNT(1, 1, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    write16(REG_BG2CNT, CREATE_BGCNT(1, 2, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    write16(REG_BG3CNT, CREATE_BGCNT(1, 3, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    GAME_OVER_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ;
    write8(REG_WINOUT, WIN0_ALL_NO_COLOR_EFFECT);
    write8(REG_WININ + 1, HIGH_BYTE(WIN1_ALL));

    GAME_OVER_DATA.dynamicPalette = sGameOverDynamicPalette_Empty;

    gGameModeSub3 = 0;

    gBG0HOFS_NonGameplay = gBG0VOFS_NonGameplay = 0;
    gBG1HOFS_NonGameplay = gBG1VOFS_NonGameplay = 0;
    gBG3HOFS_NonGameplay = gBG3VOFS_NonGameplay = 0;
    gBG2HOFS_NonGameplay = gBG2VOFS_NonGameplay = 0;

    GAME_OVER_DATA.optionSelected = GAME_OVER_DATA.unk_35 = 0;

    GameOverUpdateTextGfx();

    GAME_OVER_DATA.oam[0] = sMenuOamData_Empty;

    GameOverUpdateSamusHead(SAMUS_CURSOR_ACTION_LOADING);
    CallbackSetVBlank(GameOverVBlank);
}

/**
 * @brief 77dd8 | 134 | Unused game over init function
 * 
 */
void GameOverInit_Unused(void)
{
    u32 zero;

    CallbackSetVBlank(GameOverVBlank_Empty);
    zero = 0;
    DMA_SET(3, &zero, &gNonGameplayRAM, C_32_2_16(DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED, sizeof(gNonGameplayRAM) / 4));

    write16(REG_BLDCNT, GAME_OVER_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);

    write16(REG_BLDY, gWrittenToBLDY_NonGameplay = 16);
    write16(REG_DISPCNT, GAME_OVER_DATA.dispcnt = 0);

    gNextOamSlot = 0;
    ClearGfxRam();
    ResetFreeOam();

    gOamXOffset_NonGameplay = gOamYOffset_NonGameplay = 0;

    DoSoundAction(0x194F780);
    StopAllMusicsAndSounds();

    SET_BACKDROP_COLOR(COLOR_WHITE);

    write16(REG_BG0CNT, 0);
    write16(REG_BG1CNT, 0);
    write16(REG_BG2CNT, 0);
    write16(REG_BG3CNT, 0);

    gGameModeSub3 = 0;

    gBG0HOFS_NonGameplay = gBG0VOFS_NonGameplay = 0;
    gBG1HOFS_NonGameplay = gBG1VOFS_NonGameplay = 0;
    gBG2HOFS_NonGameplay = gBG2VOFS_NonGameplay = 0;
    gBG3HOFS_NonGameplay = gBG3VOFS_NonGameplay = 0;

    GAME_OVER_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

    gWrittenToBLDY_NonGameplay = 0;
    GAME_OVER_DATA.optionSelected = GAME_OVER_DATA.unk_35 = 0;

    GameOverUpdateTextGfx();

    GAME_OVER_DATA.oam[0] = sMenuOamData_Empty;

    CallbackSetVBlank(GameOverVBlank);
}

/**
 * @brief 77f0c | dc | V-blank code for the game over
 * 
 */
void GameOverVBlank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / sizeof(u32))

    write16(REG_BG0HOFS, SUB_PIXEL_TO_PIXEL(gBG0HOFS_NonGameplay));
    write16(REG_BG0VOFS, SUB_PIXEL_TO_PIXEL(gBG0VOFS_NonGameplay));

    write16(REG_BG1HOFS, SUB_PIXEL_TO_PIXEL(gBG1HOFS_NonGameplay));
    write16(REG_BG1VOFS, SUB_PIXEL_TO_PIXEL(gBG1VOFS_NonGameplay));

    write16(REG_BG2HOFS, SUB_PIXEL_TO_PIXEL(gBG2HOFS_NonGameplay));
    write16(REG_BG2VOFS, SUB_PIXEL_TO_PIXEL(gBG2VOFS_NonGameplay));

    write16(REG_BG3HOFS, SUB_PIXEL_TO_PIXEL(gBG3HOFS_NonGameplay));
    write16(REG_BG3VOFS, SUB_PIXEL_TO_PIXEL(gBG3VOFS_NonGameplay));

    write16(REG_DISPCNT, GAME_OVER_DATA.dispcnt);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_BLDALPHA, C_16_2_8(gWrittenToBLDALPHA_H, gWrittenToBLDALPHA_L));

    write16(REG_BLDCNT, GAME_OVER_DATA.bldcnt);
    write16(REG_WIN1H, GAME_OVER_DATA.win1H);
    write16(REG_WIN1V, GAME_OVER_DATA.win1V);
}

/**
 * @brief 77fe8 | c | Empty V-blank code
 * 
 */
void GameOverVBlank_Empty(void)
{
    vu8 c = 0;
}

/**
 * @brief 77ff4 | 180 | Handles the animation of the GAME OVER letters
 * 
 */
void GameOverUpdateLettersPalette(void)
{
    s32 i;
    s32 j;
    s32 k;
    s32 row;
    const u16* src;

    if (GAME_OVER_DATA.dynamicPalette.enableFlags == 0)
        return;

    if (GAME_OVER_DATA.dynamicPalette.enableFlags & 0x80)
    {
        if (MOD_AND(GAME_OVER_DATA.dynamicPalette.enableFlags, 128) != GAME_OVER_DATA.dynamicPalette.unk_4)
        {
            GAME_OVER_DATA.dynamicPalette.unk_4 = MOD_AND(GAME_OVER_DATA.dynamicPalette.enableFlags, 128);
            GAME_OVER_DATA.dynamicPalette.timer = 0;
            GAME_OVER_DATA.dynamicPalette.currentPaletteRow = 0;
            GAME_OVER_DATA.dynamicPalette.unk_13 = 0;
            GAME_OVER_DATA.dynamicPalette.timerLimit = sGameOverTextPaletteMaxTimers[GAME_OVER_DATA.dynamicPalette.unk_4];
        }

        GAME_OVER_DATA.dynamicPalette.enableFlags = 1;
        return;
    }

    GAME_OVER_DATA.dynamicPalette.timer++;
    if (GAME_OVER_DATA.dynamicPalette.timerLimit > GAME_OVER_DATA.dynamicPalette.timer)
        return;

    src = &sGameOverMenuPal[4];
    switch (GAME_OVER_DATA.dynamicPalette.unk_4)
    {
        case 0:
            GAME_OVER_DATA.dynamicPalette.currentPaletteRow++;
            if (GAME_OVER_DATA.dynamicPalette.currentPaletteRow >= ARRAY_SIZE(GAME_OVER_DATA.dynamicPalette.palette))
                GAME_OVER_DATA.dynamicPalette.currentPaletteRow = 0;

            row = GAME_OVER_DATA.dynamicPalette.currentPaletteRow;
            i = 0;
            while (i < (s32)ARRAY_SIZE(GAME_OVER_DATA.dynamicPalette.palette))
            {
                if (row >= (s32)ARRAY_SIZE(GAME_OVER_DATA.dynamicPalette.palette))
                    row = 0;

                GAME_OVER_DATA.dynamicPalette.palette[i] = src[row];

                i++;
                row++;
            }
            break;

        case 1:
            GAME_OVER_DATA.dynamicPalette.currentPaletteRow++;
            if (GAME_OVER_DATA.dynamicPalette.currentPaletteRow > 8)
                GAME_OVER_DATA.dynamicPalette.currentPaletteRow = 0;

            j = sGameOver_760b0f[GAME_OVER_DATA.dynamicPalette.currentPaletteRow];
            if (j >= 0)
            {
                for (i = 0; i < j; i++)
                    GAME_OVER_DATA.dynamicPalette.palette[i] = *src;

                for (k = 0; i < 6; i++, k++)
                    GAME_OVER_DATA.dynamicPalette.palette[i] = src[k];
            }
            else
            {
                for (i = 5; j < 0; j++, i--)
                    GAME_OVER_DATA.dynamicPalette.palette[i] = src[5];

                for (k = 4; i >= 0; i--, k--)
                    GAME_OVER_DATA.dynamicPalette.palette[i] = src[k];
            }
            break;
    }

    GAME_OVER_DATA.dynamicPalette.timer = 0;
    DmaTransfer(3, GAME_OVER_DATA.dynamicPalette.palette, PALRAM_BASE + 8, sizeof(GAME_OVER_DATA.dynamicPalette.palette), 16);
}

/**
 * @brief 78174 | 88 | Updates the head of Samus (cursor)
 * 
 * @param action Action done
 */
void GameOverUpdateSamusHead(u8 action)
{
    UpdateMenuOamDataID(&GAME_OVER_DATA.oam[0], sGameOverSamusHeadOamIds[gEquipment.suitType][action]);

    GAME_OVER_DATA.oam[0].xPosition = sGameOverSamusHeadXPositions[gLanguage];
    GAME_OVER_DATA.oam[0].yPosition = sGameOverSamusHeadYPositions[GAME_OVER_DATA.optionSelected];

    if (GAME_OVER_DATA.optionSelected != 0)
        GAME_OVER_DATA.win1V = C_16_2_8(0x7E, 0x91 + 1);
    else
        GAME_OVER_DATA.win1V = C_16_2_8(0x66, 0x79 + 1);

    GAME_OVER_DATA.win1H = C_16_2_8(0, 0xEF + 1);
}

/**
 * @brief 781fc | 2c | Processes the OAM for the game over menu
 * 
 */
void GameOverProcessOAM(void)
{
    gNextOamSlot = 0;
    ProcessComplexMenuOam(ARRAY_SIZE(GAME_OVER_DATA.oam), GAME_OVER_DATA.oam, sGameOverOam);
    ResetFreeOam();
}
