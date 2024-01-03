#include "cutscenes/samus_in_blue_ship.h"
#include "cutscenes/cutscene_utils.h"
#include "data/shortcut_pointers.h"
#include "data/cutscenes/samus_in_blue_ship_data.h"
#include "data/cutscenes/internal_samus_in_blue_ship_data.h"

#include "constants/cutscene.h"

#include "structs/display.h"

/**
 * @brief 67d8c | f8 | Handles the sip powering up part (entire cutscene)
 * 
 * @return u8 FALSE
 */
u8 SamusInBlueShipPoweringUp(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            if (unk_61f44())
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > 30)
            {
                CUTSCENE_DATA.oam[0].actions = 1;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.oam[0].actions == 4)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > 30)
            {
                SoundPlay(0x254);
                CUTSCENE_DATA.graphicsData[0].active = TRUE;
                CUTSCENE_DATA.graphicsData[0].timer = 0;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.timeInfo.timer > 90)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 5:
            unk_61f0c();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    SamusInBlueShipShakeScreen(&CUTSCENE_DATA.graphicsData[0]);
    SamusInBlueShipUpdateControlPanel(&CUTSCENE_DATA.oam[0]);

    return FALSE;
}

/**
 * @brief 67e84 | 4c | Handles the screen shake movement
 * 
 * @param pGraphics Cutscene graphics data pointer
 */
void SamusInBlueShipShakeScreen(struct CutsceneGraphicsData* pGraphics)
{
    if (!pGraphics->active)
        return;

    pGraphics->timer++;
    if (MOD_AND(pGraphics->timer, 2))
        return;

    if (pGraphics->timer & 2)
        *CutsceneGetBgHorizontalPointer(sSamusInBlueShipPageData[0].bg) += PIXEL_SIZE;
    else
        *CutsceneGetBgHorizontalPointer(sSamusInBlueShipPageData[0].bg) -= PIXEL_SIZE;
}

/**
 * @brief 67ed0 | c0 | Updates the control panel object
 * 
 * @param pOam Cutscene OAM data pointer
 */
void SamusInBlueShipUpdateControlPanel(struct CutsceneOamData* pOam)
{
    switch (pOam->actions)
    {
        case 0:
            break;

        case 1:
            UpdateCutsceneOamDataID(pOam, 2);
            SoundPlay(0x253);
            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            pOam->actions++;
            break;

        case 2:
            if (pOam->ended)
            {
                pOam->timer = 0;
                pOam->actions++;
            }
            break;

        case 3:
            pOam->unk_1A = 0;
            pOam->unk_1E = 2;
            pOam->timer = 0;
            pOam->actions++;
            break;

        case 4:
            if (pOam->unk_1A == 0)
            {
                pOam->unk_1A = pOam->unk_1E;
                pOam->timer++;
                if (pOam->timer >= ARRAY_SIZE(sSamusInBlueShipPanelTransparency))
                    pOam->timer = 0;

                gWrittenToBLDALPHA_L = sSamusInBlueShipPanelTransparency[pOam->timer];
                gWrittenToBLDALPHA_H = 16 - gWrittenToBLDALPHA_L;
            }
            else
                pOam->unk_1A--;
            break;
    }
}

/**
 * @brief 67f90 | 12c | Initializes the samus in blue ship cutscene
 * 
 * @return u8 FALSE
 */
u8 SamusInBlueShipInit(void)
{
    unk_61f0c();

    DmaTransfer(3, sSamusInBlueShipPal, PALRAM_OBJ, sizeof(sSamusInBlueShipPal), 16);
    DmaTransfer(3, sSamusInBlueShipPal, PALRAM_BASE, sizeof(sSamusInBlueShipPal), 16);
    SET_BACKDROP_COLOR(COLOR_BLACK);

    CallLZ77UncompVram(sSamusInBlueShipSamusGfx, BGCNT_TO_VRAM_CHAR_BASE(sSamusInBlueShipPageData[0].graphicsPage));
    CallLZ77UncompVram(sSamusInBlueShipSamusTileTable, BGCNT_TO_VRAM_TILE_BASE(sSamusInBlueShipPageData[0].tiletablePage));
    CallLZ77UncompVram(sSamusInBlueShipControlsGfx, BGCNT_TO_VRAM_CHAR_BASE(4));

    CutsceneSetBgcntPageData(sSamusInBlueShipPageData[0]);
    CutsceneReset();

    CUTSCENE_DATA.bldcnt = BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET;

    gWrittenToBLDALPHA_L = 16;
    gWrittenToBLDALPHA_H = 0;

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sSamusInBlueShipPageData[0].bg, BLOCK_SIZE * 32);

    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[0], 1);

    CUTSCENE_DATA.oam[0].xPosition = BLOCK_SIZE * 39 + HALF_BLOCK_SIZE;
    CUTSCENE_DATA.oam[0].yPosition = BLOCK_SIZE * 37 - PIXEL_SIZE;
    CUTSCENE_DATA.oam[0].priority = 0;
    CUTSCENE_DATA.oam[0].boundBackground = 3;

    CutsceneStartBackgroundFading(2);
    CUTSCENE_DATA.dispcnt = DCNT_OBJ | sSamusInBlueShipPageData[0].bg;

    CUTSCENE_DATA.timeInfo.stage++;
    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;

    return FALSE;
}

/**
 * @brief 680bc | 34 | Subroutine for the samus in blue ship cutscene
 * 
 * @return u8 bool, ended
 */
u8 SamusInBlueShipSubroutine(void)
{
    u8 ended;

    ended = sSamusInBlueShipSubroutineData[CUTSCENE_DATA.timeInfo.stage].pFunction();
    CutsceneUpdateBackgroundsPosition(TRUE);
    SamusInBlueShipProcessOAM();

    return ended;
}

/**
 * @brief 680f0 | 38 | Processes the OAM
 * 
 */
void SamusInBlueShipProcessOAM(void)
{
    gNextOamSlot = 0;
    ProcessCutsceneOam(sSamusInBlueShipSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sSamusInBlueShipOam);
    ResetFreeOam();
}
