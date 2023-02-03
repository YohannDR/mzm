#include "game_over.h"
#include "macros.h"
#include "temp_globals.h"

#include "data/shortcut_pointers.h"
#include "data/game_over_data.h"

#include "constants/audio.h"
#include "constants/demo.h"
#include "constants/game_over.h"

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
            if (gCurrentDemo.playing)
            {
                gCurrentDemo.number++;
                gCurrentDemo.playing = FALSE;

                UpdateSOUNDCNT_H(0x194F780);
                FadeAllSounds(10);
                MusicFade(10);
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
            if (GAME_OVER_DATA.oam[0].status & 0x10)
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
            MusicFade(20);
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
            sub_75c04(0);
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
        play_menu_sound(12); // Undefined
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
    play_menu_sound(11); // Undefined
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
    u32 palVal;
    u16* dst;
    u32 mask;
    i32 i;

    dst = VRAM_BASE + 0x340;
    if (GAME_OVER_DATA.optionSelected == 0)
        palette = 2;
    else
        palette = 3;

    mask = 0xFFF;
    palVal = palette << 12;
    i = 0x3F;
    while (i >= 0)
    {
        *dst = (*dst & mask) | palVal;

        i--;
        dst++;
    }

    palette ^= 1;
    dst += 0x20;
    mask = 0xFFF;
    palVal = palette << 12;
    i = 0x3F;

    while (i >= 0)
    {
        *dst = (*dst & mask) | palVal;

        i--;
        dst++;
    }
}

void GameOverInit(void)
{

}

void GameOverInit_Unused(void)
{

}

/**
 * @brief 77f0c | dc | V-blank code for the game over
 * 
 */
void GameOverVBlank(void)
{
    dma_set(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / sizeof(u32))

    write16(REG_BG0HOFS, gBG0HOFS_NonGameplay / 4);
    write16(REG_BG0VOFS, gBG0VOFS_NonGameplay / 4);

    write16(REG_BG1HOFS, gBG1HOFS_NonGameplay / 4);
    write16(REG_BG1VOFS, gBG1VOFS_NonGameplay / 4);

    write16(REG_BG2HOFS, gBG2HOFS_NonGameplay / 4);
    write16(REG_BG2VOFS, gBG2VOFS_NonGameplay / 4);

    write16(REG_BG3HOFS, gBG3HOFS_NonGameplay / 4);
    write16(REG_BG3VOFS, gBG3VOFS_NonGameplay / 4);

    write16(REG_DISPCNT, GAME_OVER_DATA.dispcnt);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_BLDALPHA, gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L);

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

void GameOverUpdateLettersPalette(void)
{

}

/**
 * @brief 78174 | 88 | Updates the head of Samus (cursor)
 * 
 * @param action Action done
 */
void GameOverUpdateSamusHead(u8 action)
{
    update_menu_oam_id(&GAME_OVER_DATA.oam[0], sGameOverSamusHeadOAMIds[gEquipment.suitType][action]); // undefined
    GAME_OVER_DATA.oam[0].xPosition = sGameOverSamusHeadXPositions[gLanguage];
    GAME_OVER_DATA.oam[0].yPosition = sGameOverSamusHeadYPositions[GAME_OVER_DATA.optionSelected];

    if (GAME_OVER_DATA.optionSelected != 0)
        GAME_OVER_DATA.win1V = 0x7E92;
    else
        GAME_OVER_DATA.win1V = 0x667A;

    GAME_OVER_DATA.win1H = 0xF0;
}

/**
 * @brief 781fc | 2c | Processes the OAM for the game over menu
 * 
 */
void GameOverProcessOAM(void)
{
    gNextOamSlot = 0;
    process_complex_menu_oam(ARRAY_SIZE(GAME_OVER_DATA.oam), GAME_OVER_DATA.oam, sGameOverOam); // Undefined
    ResetFreeOAM();
}
