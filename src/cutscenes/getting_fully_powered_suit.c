#include "cutscenes/getting_fully_powered_suit.h"
#include "cutscenes/cutscene_utils.h"
#include "macros.h"

#include "data/shortcut_pointers.h"
#include "data/generic_data.h"
#include "data/cutscenes/getting_fully_powered_suit_data.h"
#include "data/cutscenes/internal_getting_fully_powered_suit_data.h"

#include "constants/audio.h"
#include "constants/cutscene.h"
#include "constants/game_state.h"

#include "structs/game_state.h"
#include "structs/display.h"

/**
 * @brief 65bd8 | 204 | Handles the animation part (entire cutscene)
 * 
 * @return u8 FALSE
 */
u8 GettingFullyPoweredSuitAnimation(void)
{
    i32 i;
    u16* bgPosition;

    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt, 12, 8, 1);
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > 20)
            {
                CUTSCENE_DATA.oam[6].actions = 2;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.oam[6].yPosition <= BLOCK_SIZE * 17)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            bgPosition = CutsceneGetBGVOFSPointer(sGettingFullyPoweredSuitPageData[0].bg);
            if (*bgPosition - 4 > BLOCK_SIZE * 32)
                (*bgPosition) -= 4;
            else
            {
                *bgPosition = BLOCK_SIZE * 32;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.oam[6].yPosition < BLOCK_SIZE * 8)
            {
                CUTSCENE_DATA.dispcnt ^= DCNT_WIN1;
                CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt | BLDCNT_BG0_FIRST_TARGET_PIXEL |
                    BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                    BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                    BLDCNT_BACKDROP_FIRST_TARGET_PIXEL, 16, 8, 1);

                CUTSCENE_DATA.oam[6].actions |= 4;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 5:
            if (CUTSCENE_DATA.timeInfo.timer > 60)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 6:
            unk_61f28();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    GettingFullyPoweredSuitUpdateRingPalette(&CUTSCENE_DATA.paletteData[0]);
    *CutsceneGetBGVOFSPointer(sGettingFullyPoweredSuitPageData[1].bg) = *CutsceneGetBGVOFSPointer(sGettingFullyPoweredSuitPageData[0].bg);

    GettingFullyPoweredSuitUpdateRing(&CUTSCENE_DATA.oam[6]);

    for (i = 0; i < 6; i++)
        GettingFullyPoweredSuitUpdateSparkleAroundRing(&CUTSCENE_DATA.oam[i], i);

    // ...

    i = -0x800 + *CutsceneGetBGVOFSPointer(sGettingFullyPoweredSuitPageData[0].bg);
    i = (CUTSCENE_DATA.oam[6].yPosition - i >> 2) + 8;
    if (i < 0)
        i = 0;
    else if (i > 0xA0)
        i = 0xA0;

    write16(REG_WIN1V, i);

    for (i = 7; i < 12; i++)
        GettingFullyPoweredSuitUpdateSparkleGoingUp(&CUTSCENE_DATA.oam[i], i);

    return FALSE;
}

/**
 * @brief 65ddc | 60 | Updates the ring palette
 * 
 * @param pPalette Cutscene palette data pointer
 */
void GettingFullyPoweredSuitUpdateRingPalette(struct CutscenePaletteData* pPalette)
{
    if (!(pPalette->active & TRUE))
        return;

    if (pPalette->timer != 0)
    {
        pPalette->timer--;
        return;
    }

    pPalette->timer = pPalette->maxTimer;
    pPalette->paletteRow++;

    if (pPalette->paletteRow >= ARRAY_SIZE(sGettingFullyPoweredSuitRingPaletteRows))
        pPalette->paletteRow = 0;

    DMATransfer(3, &sGettingFullyPoweredSuitRingPAL[sGettingFullyPoweredSuitRingPaletteRows[pPalette->paletteRow] * 16],
        PALRAM_BASE + 0x340, 32, 0x10);
}

/**
 * @brief 65e3c | 70 | Updates the ring object
 * 
 * @param pOam Cutscene OAM data pointer
 */
void GettingFullyPoweredSuitUpdateRing(struct CutsceneOamData* pOam)
{
    u16 unk;
    
    if (pOam->actions & 4)
    {
        unk = ++pOam->unk_18;
        pOam->unk_10 = -4 - (unk / 4);
    }
    else
    {
        pOam->unk_10 = -4;
        pOam->unk_18 = 0;
    }

    if (pOam->actions & 2)
    {
        pOam->yPosition += pOam->unk_10;
        if (pOam->yPosition < -0xBF)
            pOam->actions = 0;
    }

    CUTSCENE_DATA.oam[13].yPosition = pOam->yPosition;
}

/**
 * @brief 65eac | c4 | Updates a sparkle around the ring
 * 
 * @param pOam Cutscene OAM data pointer
 * @param sparkleId Sparkle ID
 */
void GettingFullyPoweredSuitUpdateSparkleAroundRing(struct CutsceneOamData* pOam, u8 sparkleId)
{
    if (pOam->actions == 0)
    {
        pOam->timer = sRandomNumberTable[(gFrameCounter8Bit + sparkleId) & 0xFF] & 0x1F;
        pOam->actions = 1;
    }
    else if (pOam->actions == 1)
    {
        if (pOam->timer != 0)
            pOam->timer--;
        else
        {
            if (sRandomNumberTable[gFrameCounter8Bit] & 1)
                UpdateCutsceneOamDataID(pOam, GETTING_FULLY_POWERED_SUIT_OAM_ID_SPARKLE_AROUND_RING2);
            else
                UpdateCutsceneOamDataID(pOam, GETTING_FULLY_POWERED_SUIT_OAM_ID_SPARKLE_AROUND_RING1);

            pOam->actions = 2;
        }
    }
    else if (!pOam->idChanged)
        pOam->actions = 0;
    
    if (pOam->idChanged)
    {
        pOam->xPosition = CUTSCENE_DATA.oam[6].xPosition + sGettingFullyPoweredSuitRingSparklesSpawnPositions[sparkleId][0];
        pOam->yPosition = CUTSCENE_DATA.oam[6].yPosition + sGettingFullyPoweredSuitRingSparklesSpawnPositions[sparkleId][1];
    }
}

/**
 * @brief 65f70 | b0 | Updates a sparkle going up
 * 
 * @param pOam Cutscene OAM data pointer
 * @param sparkleId Sparkle ID
 */
void GettingFullyPoweredSuitUpdateSparkleGoingUp(struct CutsceneOamData* pOam, u8 sparkleId)
{
    u16 unk;

    if (pOam->actions & 2)
    {
        unk = ++pOam->unk_18;
        pOam->unk_10 += (unk / 16);

        if (pOam->unk_10 > 0x20)
            pOam->unk_10 = 0x20;

        pOam->yPosition -= pOam->unk_10;
        if (pOam->yPosition >= -0xDF)
            return;

        pOam->actions = 0;
        pOam->timer = sGettingFullyPoweredSuitBackgroundGFX[gFrameCounter8Bit + sparkleId] & 0x3F;
    }
    else
    {
        if (pOam->timer == 0)
        {
            pOam->actions = 2;
            pOam->unk_10 = 0;
            pOam->xPosition = sGettingFullyPoweredSuit_3c642c[sparkleId - 7] + (sRandomNumberTable[gFrameCounter8Bit] & 0x3F);
            pOam->yPosition = BLOCK_SIZE * 11;
            pOam->unk_18 = 0;
            return;
        }

        pOam->timer--;
    }
}

/**
 * @brief 66020 | 33c | Initializes the getting fully powered suit cutscene
 * 
 * @return u8 FALSE
 */
u8 GettingFullyPoweredSuitInit(void)
{
    i32 i;

    unk_61f0c();
    DMATransfer(3, sGettingFullyPoweredSuitPAL, PALRAM_BASE, 352, 0x10);
    DMATransfer(3, PALRAM_BASE, PALRAM_OBJ, 0x200, 0x20);
    write16(PALRAM_BASE, 0);

    CallLZ77UncompVRAM(sGettingFullyPoweredSuitSamusGFX, VRAM_BASE + sGettingFullyPoweredSuitPageData[0].graphicsPage * 0x4000);
    CallLZ77UncompVRAM(sGettingFullyPoweredSuitSamusTileTable, VRAM_BASE + sGettingFullyPoweredSuitPageData[0].tiletablePage * 0x800);

    CallLZ77UncompVRAM(sGettingFullyPoweredSuitBackgroundGFX, VRAM_BASE + sGettingFullyPoweredSuitPageData[1].graphicsPage * 0x4000);
    CallLZ77UncompVRAM(sGettingFullyPoweredSuitBackgroundTileTable, VRAM_BASE + sGettingFullyPoweredSuitPageData[1].tiletablePage * 0x800);

    CallLZ77UncompVRAM(sGettingFullyPoweredSuitRingSparklesGFX, VRAM_BASE + 0x10000);

    CutsceneSetBGCNTPageData(sGettingFullyPoweredSuitPageData[0]);
    CutsceneSetBGCNTPageData(sGettingFullyPoweredSuitPageData[1]);

    CutsceneReset();

    CUTSCENE_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_INCREASE_EFFECT |
        BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL |
        BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

    gWrittenToBLDY_NonGameplay = 0;
    gWrittenToBLDALPHA_L = 0;
    gWrittenToBLDALPHA_H = 16;

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sGettingFullyPoweredSuitPageData[0].bg, 0x800);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sGettingFullyPoweredSuitPageData[1].bg, 0x800);

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sGettingFullyPoweredSuitPageData[0].bg, 0xA80);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sGettingFullyPoweredSuitPageData[1].bg, 0xA80);

    CUTSCENE_DATA.oam[6].xPosition = BLOCK_SIZE * 8 - QUARTER_BLOCK_SIZE;
    CUTSCENE_DATA.oam[6].yPosition = BLOCK_SIZE * 22;
    CUTSCENE_DATA.oam[6].priority = sGettingFullyPoweredSuitPageData[0].priority;
    CUTSCENE_DATA.oam[6].unk_B_4 = 0;
    CUTSCENE_DATA.oam[6].boundBackground = 2;

    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[6], GETTING_FULLY_POWERED_SUIT_OAM_ID_RING_BOTTOM);
    CUTSCENE_DATA.oam[13] = CUTSCENE_DATA.oam[6];
    CUTSCENE_DATA.oam[13].priority = sGettingFullyPoweredSuitPageData[0].priority + 1;
    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[13], GETTING_FULLY_POWERED_SUIT_OAM_ID_RING_TOP);

    for (i = 0; i < 6; i++)
    {
        CUTSCENE_DATA.oam[i].priority = sGettingFullyPoweredSuitPageData[0].priority;
        CUTSCENE_DATA.oam[i].boundBackground = 2;
    }

    CUTSCENE_DATA.oam[7].xPosition = sGettingFullyPoweredSuit_3c642c[0];
    CUTSCENE_DATA.oam[7].yPosition = BLOCK_SIZE * 11;
    CUTSCENE_DATA.oam[7].priority = sGettingFullyPoweredSuitPageData[0].priority;
    CUTSCENE_DATA.oam[i].timer = sRandomNumberTable[gFrameCounter8Bit] & 0x3F;
    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[7], GETTING_FULLY_POWERED_SUIT_OAM_ID_SPARKLE_GOING_UP);

    for (i = 8; i < 12; i++)
    {
        CUTSCENE_DATA.oam[i] = CUTSCENE_DATA.oam[7];

        CUTSCENE_DATA.oam[i].xPosition = sGettingFullyPoweredSuit_3c642c[i - 7];
        CUTSCENE_DATA.oam[i].timer = sGettingFullyPoweredSuitBackgroundGFX[gFrameCounter8Bit + i] & 0x3F;
    }

    CUTSCENE_DATA.paletteData[0] = sGettingFullyPoweredSuitPaletteData;
    CUTSCENE_DATA.dispcnt = DCNT_OBJ | DCNT_WIN1 | sGettingFullyPoweredSuitPageData[0].bg | sGettingFullyPoweredSuitPageData[1].bg;

    write8(REG_WINOUT, 0x3F);
    write8(REG_WININ + 1, 0x1F);
    write16(REG_WIN1H, 0xF0);
    write16(REG_WIN1V, 0xA0);

    gPauseScreenFlag = PAUSE_SCREEN_NONE;
    PlayMusic(MUSIC_GETTING_FULLY_POWERED_SUIT_CUTSCENE, 0);

    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;
    CUTSCENE_DATA.timeInfo.stage++;

    return FALSE;
}

/**
 * @brief 6635c | 34 | Subroutine for the getting fully powered suit cutscene
 * 
 * @return u8 bool, ended
 */
u8 GettingFullyPoweredSuitSubroutine(void)
{
    u8 ended;

    ended = sGettingFullyPoweredSuitSubroutineData[CUTSCENE_DATA.timeInfo.stage].pFunction();
    CutsceneUpdateBackgroundsPosition(TRUE);
    GettingFullyPoweredSuitProcessOAM();
    
    return ended;
}

/**
 * @brief 66390 | 38 | Processes the OAM
 * 
 */
void GettingFullyPoweredSuitProcessOAM(void)
{
    gNextOamSlot = 0;
    process_cutscene_oam(sGettingFullyPoweredSuitSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sGettingFullyPoweredSuitCutsceneOAM);
    ResetFreeOAM();
}
