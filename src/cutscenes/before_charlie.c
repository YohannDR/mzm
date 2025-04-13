#include "cutscenes/before_charlie.h"
#include "cutscenes/cutscene_utils.h"
#include "gba.h"
#include "color_effects.h" // Required

#include "data/shortcut_pointers.h"
#include "data/cutscenes/before_charlie_data.h"
#include "data/cutscenes/internal_before_charlie_data.h"

#include "constants/cutscene.h"
#include "constants/audio.h"

#include "structs/display.h"

/**
 * @brief 663c8 | 270 | Handles the close up part
 * 
 * @return u8 FALSE
 */
u8 BeforeCharlieSamusCloseUp(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            SEND_TO_PALRAM(sBeforeCharlieSamusCloseUpPal, PALRAM_BASE);
            SET_BACKDROP_COLOR(COLOR_BLACK);

            CallLZ77UncompVram(sBeforeCharlieYoungSamusCloseUpGfx, BGCNT_TO_VRAM_CHAR_BASE(sBeforeCharliePageData[5].graphicsPage));
            CallLZ77UncompVram(sBeforeCharlieSamusCloseUpGfx, BGCNT_TO_VRAM_CHAR_BASE(sBeforeCharliePageData[6].graphicsPage));
            
            CallLZ77UncompVram(sBeforeCharlieYoungSamusCloseUpTileTable, BGCNT_TO_VRAM_TILE_BASE(sBeforeCharliePageData[5].tiletablePage));
            CallLZ77UncompVram(sBeforeCharlieSamusCloseUpEyesClosedTileTable, BGCNT_TO_VRAM_TILE_BASE(sBeforeCharliePageData[8].tiletablePage));
            CallLZ77UncompVram(sBeforeCharlieSamusCloseUpEyesOpenedTileTable, BGCNT_TO_VRAM_TILE_BASE(sBeforeCharliePageData[7].tiletablePage));
            CallLZ77UncompVram(sBeforeCharlieSamusCloseUpOutlineTileTable, BGCNT_TO_VRAM_TILE_BASE(sBeforeCharliePageData[6].tiletablePage));

            CutsceneSetBgcntPageData(sBeforeCharliePageData[5]);
            CutsceneSetBgcntPageData(sBeforeCharliePageData[8]);
            CutsceneSetBgcntPageData(sBeforeCharliePageData[7]);
            CutsceneSetBgcntPageData(sBeforeCharliePageData[6]);

            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sBeforeCharliePageData[5].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sBeforeCharliePageData[8].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sBeforeCharliePageData[7].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sBeforeCharliePageData[6].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneReset();

            CutsceneStartBackgroundFading(10);
            CUTSCENE_DATA.dispcnt = sBeforeCharliePageData[5].bg | sBeforeCharliePageData[8].bg |sBeforeCharliePageData[6].bg;
            
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(3.f))
            {
                CutsceneStartBackgroundEffect(BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET,
                    0, BLDALPHA_MAX_VALUE, 16, 1);

                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_BG_ENDED)
            {
                CUTSCENE_DATA.dispcnt ^= sBeforeCharliePageData[5].bg;

                CutsceneStartBackgroundEffect(BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET,
                    0, BLDALPHA_MAX_VALUE, 1, 16);

                CUTSCENE_DATA.dispcnt |= sBeforeCharliePageData[7].bg;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(1.f) + TWO_THIRD_SECOND)
            {
                CutsceneStartBackgroundEffect(BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET,
                    BLDALPHA_MAX_VALUE, 0, 1, 4);

                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_BG_ENDED)
            {
                CUTSCENE_DATA.dispcnt ^= sBeforeCharliePageData[8].bg;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 5:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(2.f) + ONE_THIRD_SECOND)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 6:
            if (CutsceneTransferAndUpdateFade())
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 7:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(1.f) + CONVERT_SECONDS(1.f / 6))
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 8:
            CutsceneFadeScreenToWhite();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    #ifdef DEBUG
    CutsceneCheckSkipStage(1);
    #endif // DEBUG

    return FALSE;
}

/**
 * @brief 66638 | 2d8 | Handles the wall view and the grey voice part
 * 
 * @return u8 FALSE
 */
u8 BeforeCharlieWallAndGreyVoice(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            SEND_TO_PALRAM(sBeforeCharlieChozoWallPal, PALRAM_BASE);
            SET_BACKDROP_COLOR(COLOR_BLACK);

            ApplyMonochromeToPalette(sBeforeCharlieChozoWallPal, BEFORE_CHARLIE_EWRAM.wallPalMonochrome, 0);
            DmaTransfer(3, sBeforeCharlieChozoWallPal, BEFORE_CHARLIE_EWRAM.wallPal, sizeof(sBeforeCharlieChozoWallPal), 16);

            CallLZ77UncompVram(sBeforeCharlieChozoWallBackgroundGfx, BGCNT_TO_VRAM_CHAR_BASE(sBeforeCharliePageData[2].graphicsPage));
            BitFill(3, 0, BGCNT_TO_VRAM_TILE_BASE(sBeforeCharliePageData[2].tiletablePage), BGCNT_VRAM_TILE_SIZE, 32);
            BitFill(3, 0, BGCNT_TO_VRAM_TILE_BASE(sBeforeCharliePageData[3].tiletablePage), BGCNT_VRAM_TILE_SIZE, 32);

            CallLZ77UncompVram(sBeforeCharlieChozoWallBackgroundTileTable, BGCNT_TO_VRAM_TILE_BASE(sBeforeCharliePageData[2].tiletablePage));
            CallLZ77UncompVram(sBeforeCharlieYoungSamusAndGreyVoiceTileTable, BGCNT_TO_VRAM_TILE_BASE(sBeforeCharliePageData[3].tiletablePage));

            CutsceneSetBgcntPageData(sBeforeCharliePageData[2]);
            CutsceneSetBgcntPageData(sBeforeCharliePageData[3]);

            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sBeforeCharliePageData[2].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sBeforeCharliePageData[3].bg, NON_GAMEPLAY_START_BG_POS);

            CallLZ77UncompVram(sBeforeCharlieYoungSamusAndGreyVoiceCloseUpGfx, BGCNT_TO_VRAM_CHAR_BASE(sBeforeCharliePageData[4].graphicsPage));
            CallLZ77UncompVram(sBeforeCharlieYoungSamusAndGreyVoiceCloseuUpTileTable, BGCNT_TO_VRAM_TILE_BASE(sBeforeCharliePageData[4].tiletablePage));

            CutsceneSetBgcntPageData(sBeforeCharliePageData[4]);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sBeforeCharliePageData[4].bg, NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE * 5);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sBeforeCharliePageData[4].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneReset();

            gWrittenToBLDALPHA_L = 0;
            gWrittenToBLDALPHA_H = BLDALPHA_MAX_VALUE;

            CUTSCENE_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;
            DmaTransfer(3, &sBeforeCharlieCutsceneGraphicsData, &CUTSCENE_DATA.graphicsData[1], sizeof(CUTSCENE_DATA.graphicsData[1]), 16);

            CUTSCENE_DATA.dispcnt = sBeforeCharliePageData[2].bg | sBeforeCharliePageData[4].bg;
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(2.f))
            {
                CUTSCENE_DATA.graphicsData[0].active |= TRUE;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.timeInfo.timer == (CONVERT_SECONDS(3.f) + ONE_THIRD_SECOND) && !CUTSCENE_DATA.graphicsData[1].active)
            {
                CUTSCENE_DATA.graphicsData[1].active |= TRUE;
            }

            if (CUTSCENE_DATA.timeInfo.timer == (CONVERT_SECONDS(9.f) + ONE_THIRD_SECOND) && !CUTSCENE_DATA.graphicsData[2].active)
            {
                CutsceneStartBackgroundEffect(CUTSCENE_DATA.bldcnt, BLDALPHA_MAX_VALUE, 0, 16, 1);
                CUTSCENE_DATA.graphicsData[2].active |= TRUE;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            if (!CUTSCENE_DATA.graphicsData[0].active && !CUTSCENE_DATA.graphicsData[1].active && !CUTSCENE_DATA.graphicsData[2].active &&
                CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_BG_ENDED)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(1.f))
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 5:
            CutsceneFadeScreenToWhite();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    BeforeCharlieWallAndGreyVoiceScrollAndLoadYoungSamusGfx(&CUTSCENE_DATA.graphicsData[0]);
    BeforeCharlieWallAndGreyVoiceApplyMonochrome(&CUTSCENE_DATA.graphicsData[1]);
    BeforeCharlieWallAndGreyScrollCloseUp(&CUTSCENE_DATA.graphicsData[2]);

    *CutsceneGetBgVerticalPointer(sBeforeCharliePageData[3].bg) = *CutsceneGetBgVerticalPointer(sBeforeCharliePageData[2].bg);

    #ifdef DEBUG
    CutsceneCheckSkipStage(1);
    #endif // DEBUG

    return FALSE;
}

/**
 * @brief 66910 | 78 | Handles the scrolling of the wall and loads the young samus and grey voice graphics
 * 
 * @param pGraphics Cutscene graphics data pointer
 */
void BeforeCharlieWallAndGreyVoiceScrollAndLoadYoungSamusGfx(struct CutsceneGraphicsData* pGraphics)
{
    u16* pPosition;

    if (!(pGraphics->active & TRUE))
        return;

    pPosition = CutsceneGetBgVerticalPointer(sBeforeCharliePageData[2].bg);
    (*pPosition)++;

    if (*pPosition >= NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE * 10)
    {
        *pPosition = NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE * 10;
        pGraphics->active = FALSE;
    }

    if (!(CUTSCENE_DATA.dispcnt & sBeforeCharliePageData[3].bg) && *pPosition == NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE * 6)
    {
        CallLZ77UncompVram(sBeforeCharlieYoungSamusAndGreyVoiceGfx, BGCNT_TO_VRAM_CHAR_BASE(sBeforeCharliePageData[3].graphicsPage));
        CUTSCENE_DATA.dispcnt |= sBeforeCharliePageData[3].bg;
    }
}

/**
 * @brief 66988 | 6c | Handles the monochrome palette transition
 * 
 * @param pGraphics Cutscene graphics data pointer
 */
void BeforeCharlieWallAndGreyVoiceApplyMonochrome(struct CutsceneGraphicsData* pGraphics)
{
    if (!(pGraphics->active & TRUE))
        return;

    if (pGraphics->timer != 0)
    {
        APPLY_DELTA_TIME_DEC(pGraphics->timer);
        return;
    }

    pGraphics->timer = pGraphics->maxTimer;
    pGraphics->paletteStage++;

    ApplySmoothMonochromeToPalette(BEFORE_CHARLIE_EWRAM.wallPal, BEFORE_CHARLIE_EWRAM.wallPalMonochrome,
        BEFORE_CHARLIE_EWRAM.wallPalMonochromeTransition, pGraphics->paletteStage);
    DmaTransfer(3, BEFORE_CHARLIE_EWRAM.wallPalMonochromeTransition, PALRAM_BASE, sizeof(BEFORE_CHARLIE_EWRAM.wallPalMonochromeTransition), 16);

    if (pGraphics->paletteStage == 32)
        pGraphics->active = FALSE;
}

/**
 * @brief 669f4 | 3c | Handles the scrolling of the young samus and grey voice close up
 * 
 * @param pGraphics Cutscene graphics data pointer
 */
void BeforeCharlieWallAndGreyScrollCloseUp(struct CutsceneGraphicsData* pGraphics)
{
    u16* pPosition;

    if (!(pGraphics->active & TRUE))
        return;

    pPosition = CutsceneGetBgHorizontalPointer(sBeforeCharliePageData[4].bg);
    (*pPosition) -= PIXEL_SIZE / 2;

    if (*pPosition <= NON_GAMEPLAY_START_BG_POS)
    {
        *pPosition = NON_GAMEPLAY_START_BG_POS;
        pGraphics->active = FALSE;
    }
}

/**
 * @brief 66a30 | 70 | Handles the view of the chozo side walls part
 * 
 * @return u8 FALSE
 */
u8 BeforeCharlieChozoWallSides(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            // Wait
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(2.f) + ONE_THIRD_SECOND)
            {
                // Toggle viewed wall
                CUTSCENE_DATA.dispcnt ^= sBeforeCharliePageData[0].bg;
                CUTSCENE_DATA.dispcnt |= sBeforeCharliePageData[1].bg;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 1:
            // Wait
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(2.f) + ONE_THIRD_SECOND)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            CutsceneFadeScreenToBlack();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    #ifdef DEBUG
    CutsceneCheckSkipStage(1);
    #endif // DEBUG

    return FALSE;
}

/**
 * @brief 66aa0 | 130 | Initializes the before charlie cutscene
 * 
 * @return u8 FALSE
 */
u8 BeforeCharlieInit(void)
{
    CutsceneFadeScreenToBlack();

    SEND_TO_PALRAM(sBeforeCharlieChozoWallSidesPal, PALRAM_BASE);
    BitFill(3, 0, PALRAM_OBJ, PAL_SIZE, 32);
    SET_BACKDROP_COLOR(COLOR_BLACK);

    CallLZ77UncompVram(sBeforeCharlieLeftSideOfChozoWallGfx, BGCNT_TO_VRAM_CHAR_BASE(sBeforeCharliePageData[0].graphicsPage));
    CallLZ77UncompVram(sBeforeCharlieRightSideOfChozoWallGfx, BGCNT_TO_VRAM_CHAR_BASE(sBeforeCharliePageData[1].graphicsPage));

    BitFill(3, 0, BGCNT_VRAM_TILE_SIZE + BGCNT_TO_VRAM_TILE_BASE(sBeforeCharliePageData[0].tiletablePage), BGCNT_VRAM_TILE_SIZE, 32);
    BitFill(3, 0, BGCNT_TO_VRAM_TILE_BASE(sBeforeCharliePageData[1].tiletablePage), BGCNT_VRAM_TILE_SIZE, 32);

    CallLZ77UncompVram(sBeforeCharlieLeftSideOfChozoWallTileTable, BGCNT_TO_VRAM_TILE_BASE(sBeforeCharliePageData[0].tiletablePage));
    CallLZ77UncompVram(sBeforeCharlieRightSideOfChozoWallTileTable, BGCNT_VRAM_TILE_SIZE + BGCNT_TO_VRAM_TILE_BASE(sBeforeCharliePageData[1].tiletablePage));

    CutsceneSetBgcntPageData(sBeforeCharliePageData[0]);
    CutsceneSetBgcntPageData(sBeforeCharliePageData[1]);
    CutsceneReset();

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sBeforeCharliePageData[0].bg, NON_GAMEPLAY_START_BG_POS);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sBeforeCharliePageData[1].bg, NON_GAMEPLAY_START_BG_POS);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sBeforeCharliePageData[1].bg, NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE * 16);

    PlayMusic(MUSIC_CHOZO_STATUE_HINT_DELAY, 0);

    CUTSCENE_DATA.dispcnt = sBeforeCharliePageData[0].bg;

    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;
    CUTSCENE_DATA.timeInfo.stage++;

    return FALSE;
}

/**
 * @brief 66bd0 | 30 | Subroutine for the before charlie cutscene
 * 
 * @return u8 bool, ended
 */
u8 BeforeCharlieSubroutine(void)
{
    u8 ended;

    ended = sBeforeCharlieSubroutineData[CUTSCENE_DATA.timeInfo.stage].pFunction();

    CutsceneUpdateBackgroundsPosition(TRUE);
    return ended;
}
