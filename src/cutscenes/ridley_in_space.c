#include "cutscenes/ridley_in_space.h"
#include "cutscenes/cutscene_utils.h"
#include "oam_id.h"

#include "data/generic_data.h"
#include "data/shortcut_pointers.h"
#include "data/cutscenes/cutscenes_data.h"
#include "data/cutscenes/ridley_in_space_data.h"
#include "data/cutscenes/internal_ridley_in_space_data.h"

#include "constants/audio.h"
#include "constants/cutscene.h"

#include "structs/display.h"
#include "structs/game_state.h"

/**
 * @brief 63884 | 298 | Handles the ship leaving part
 * 
 * @return u8 FALSE
 */
u8 RidleyInSpaceShipLeaving(void)
{
    s32 i;

    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            DMATransfer(3, sRidleyInSpaceSpaceBackgroundPAL, PALRAM_BASE, sizeof(sRidleyInSpaceSpaceBackgroundPAL), 0x10);
            write16(PALRAM_BASE, 0);

            CallLZ77UncompVRAM(sRidleyInSpaceSpaceBackgroundGfx, VRAM_BASE + sRidleyInSpacePageData[0].graphicsPage * 0x4000);
            CallLZ77UncompVRAM(sRidleyInSpaceSpaceBackgroundTileTable, VRAM_BASE + sRidleyInSpacePageData[0].tiletablePage * 0x800);

            DMATransfer(3, sRidleyInSpace_39dc70_PAL, PALRAM_OBJ, sizeof(sRidleyInSpace_39dc70_PAL), 0x10);
            CallLZ77UncompVRAM(sRidleyInSpaceMotherShipLeavingGfx, VRAM_BASE + 0x10000);

            CutsceneSetBGCNTPageData(sRidleyInSpacePageData[0]);
            CutsceneReset();

            CUTSCENE_DATA.oam[2].xPosition = sRidleyInSpaceShipLeavingPosition.x;
            CUTSCENE_DATA.oam[2].yPosition = sRidleyInSpaceShipLeavingPosition.y;
            CUTSCENE_DATA.oam[2].rotationScaling = TRUE;
            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[2], RIDLEY_IN_SPACE_OAM_ID_MOTHER_SHIP_LEAVING_BACK);

            CUTSCENE_DATA.dispcnt = sRidleyInSpacePageData[0].bg | DCNT_OBJ;

            for (i = 3; i < 13; i++)
            {
                CUTSCENE_DATA.oam[i].actions = 0;
                CUTSCENE_DATA.oam[i].xPosition = sRandomNumberTable[gFrameCounter8Bit & i] * 4;
                CUTSCENE_DATA.oam[i].yPosition = sRandomNumberTable[(gFrameCounter8Bit + i) & 0xFF] * 4;

                if (CUTSCENE_DATA.oam[i].yPosition >= BLOCK_SIZE * 10)
                    continue;

                CUTSCENE_DATA.oam[i].timer = 0;
                CUTSCENE_DATA.oam[i].unk_12 = sRandomNumberTable[(gFrameCounter8Bit * i) & 0xFF];

                if (CUTSCENE_DATA.oam[i].unk_12 & 1)
                    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[i], RIDLEY_IN_SPACE_OAM_ID_SHIP_LEAVING_PARTICLE);
                else
                    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[i], RIDLEY_IN_SPACE_OAM_ID_SHIP_LEAVING_PARTICLE2);
            }
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > 60)
            {
                SoundPlay(0x28E);
                CUTSCENE_DATA.oam[2].actions = 3;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.oam[2].actions == 0)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > 60 * 2)
            {
                CUTSCENE_DATA.oam[2].actions = 12;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.oam[2].actions == 0)
            {
                CUTSCENE_DATA.dispcnt &= ~(DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 5:
            if (CUTSCENE_DATA.timeInfo.timer > 60 * 2)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 6:
            unk_61f0c();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    RidleyInSpaceShipLeavingParticles();
    (*CutsceneGetBGHOFSPointer(sRidleyInSpacePageData[0].bg)) += 2;
    RidleyInSpaceUpdateShipLeaving(&CUTSCENE_DATA.oam[2]);

    return FALSE;
}

/**
 * @brief 63b1c | c4 | Updates the ship leaving object
 * 
 * @param pOam Cutscene OAM data pointer
 */
void RidleyInSpaceUpdateShipLeaving(struct CutsceneOamData* pOam)
{
    if (pOam->actions & 3)
    {
        if (pOam->actions & 1)
        {
            pOam->xPosition += 8;
            if (pOam->xPosition > 0x4E0)
                pOam->actions = 0;
        }

        if (pOam->actions & 2)
        {
            pOam->unk_18++;
            pOam->unk_10 = -3;

            pOam->yPosition += pOam->unk_10;

            if (pOam->yPosition < -0x70)
                pOam->actions = 0;
        }

        if (pOam->actions == 0)
        {
            pOam->oamID = RIDLEY_IN_SPACE_OAM_ID_MOTHER_SHIP_LEAVING_FRONT;
            gCurrentOamScaling = 0x100;
            pOam->xPosition = 0x4C0;
            pOam->yPosition = 0x78;
        }
    }
    else if (pOam->actions & 0xC)
    {
        if (pOam->actions & 4)
            pOam->xPosition -= 16;

        pOam->unk_10 = 0;
        if (gCurrentOamScaling < 0x200)
        {
            gCurrentOamScaling += 8;
            if (gCurrentOamScaling < 0x200)
                return;
        }
        
        gCurrentOamScaling = 0x200;
        pOam->actions = 0;
    }
}

/**
 * @brief 63be0 | 1b0 | Handles the ridley being suspicious part
 * 
 * @return u8 FALSE
 */
u8 RidleyInSpaceRidleySuspicious(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            DMATransfer(3, sRidleyInSpaceShipInteriorPAL, PALRAM_BASE, sizeof(sRidleyInSpaceShipInteriorPAL), 0x10);
            write16(PALRAM_BASE, 0);

            CallLZ77UncompVRAM(sRidleyInSpaceShipInterior2Gfx, VRAM_BASE + sRidleyInSpacePageData[3].graphicsPage * 0x4000);
            CallLZ77UncompVRAM(sRidleyInSpaceRidleySuspiciousGfx, VRAM_BASE + sRidleyInSpacePageData[4].graphicsPage * 0x4000);

            CallLZ77UncompVRAM(sRidleyInSpaceRidleySuspiciousEyesOpenTileTable, VRAM_BASE + sRidleyInSpacePageData[4].tiletablePage * 0x800);
            CallLZ77UncompVRAM(sRidleyInSpaceRidleySuspiciousEyesSquintedTileTable, VRAM_BASE + sRidleyInSpacePageData[5].tiletablePage * 0x800);
            CallLZ77UncompVRAM(sRidleyInSpaceShipInteriorTileTable2, VRAM_BASE + sRidleyInSpacePageData[3].tiletablePage * 0x800);

            CutsceneSetBGCNTPageData(sRidleyInSpacePageData[3]);
            CutsceneSetBGCNTPageData(sRidleyInSpacePageData[4]);
            CutsceneSetBGCNTPageData(sRidleyInSpacePageData[5]);

            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleyInSpacePageData[3].bg, 0x800);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleyInSpacePageData[4].bg, 0x800);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleyInSpacePageData[5].bg, 0x800);
            CutsceneReset();

            CUTSCENE_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            gWrittenToBLDALPHA_H = 16;
            gWrittenToBLDALPHA_L = 0;

            CUTSCENE_DATA.dispcnt = sRidleyInSpacePageData[3].bg | sRidleyInSpacePageData[4].bg | sRidleyInSpacePageData[5].bg;
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 2:
            CutsceneStartBackgroundEffect(CUTSCENE_DATA.bldcnt, 16, 0, 2, 2);
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 3:
            if (CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_BG_ENDED)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;
        
        case 1:
        case 4:
            if (CUTSCENE_DATA.timeInfo.timer > 60)
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

    return FALSE;
}

/**
 * @brief 63d90 | 1c4 | Handles the red alert part
 * 
 * @return u8 FALSE
 */
u8 RidleyInSpaceRedAlert(void)
{
    u8 scrollStatus;

    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            DMATransfer(3, sRidleyInSpace_39d910_PAL, PALRAM_BASE, sizeof(sRidleyInSpace_39d910_PAL), 0x10);
            write16(PALRAM_BASE, 0);

            CallLZ77UncompVRAM(sRidleyInSpaceShipInteriorTileTable, VRAM_BASE + sRidleyInSpacePageData[1].tiletablePage * 0x800);
            CallLZ77UncompVRAM(sRidleyInSpaceShipInteriorGfx, VRAM_BASE + sRidleyInSpacePageData[1].graphicsPage * 0x4000);

            CallLZ77UncompVRAM(sRidleyInSpaceRidleySittingGfx, VRAM_BASE + sRidleyInSpacePageData[2].graphicsPage * 0x4000);
            CallLZ77UncompVRAM(sRidleyInSpaceRidleySittingTileTable, VRAM_BASE + sRidleyInSpacePageData[2].tiletablePage * 0x800);

            CutsceneSetBGCNTPageData(sRidleyInSpacePageData[1]);
            CutsceneSetBGCNTPageData(sRidleyInSpacePageData[2]);

            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sRidleyInSpacePageData[1].bg, 0x800);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sRidleyInSpacePageData[1].bg, 0xA80);

            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sRidleyInSpacePageData[2].bg, 0x800);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sRidleyInSpacePageData[2].bg, 0xA80);

            CutsceneReset();
            CUTSCENE_DATA.dispcnt = sRidleyInSpacePageData[1].bg | sRidleyInSpacePageData[2].bg;
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > 40)
            {
                CUTSCENE_DATA.paletteData[0] = sRidleyInSpacePaletteData;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.timeInfo.timer > 60)
            {
                CutsceneStartBackgroundScrolling(sRidleyInSpaceScrollingInfo[0], sRidleyInSpacePageData[1].bg);
                CutsceneStartBackgroundScrolling(sRidleyInSpaceScrollingInfo[0], sRidleyInSpacePageData[2].bg);

                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            scrollStatus = CutsceneCheckBackgroundScrollingActive(sRidleyInSpacePageData[1].bg);
            if (scrollStatus == 0)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.timeInfo.timer > 60)
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

    RidleyInSpaceUpdateAlertPalette(&CUTSCENE_DATA.paletteData[0]);
    return FALSE;
}

/**
 * @brief 63f54 | 60 | Updates the red alert palette
 * 
 * @param pPalette Cutscene palette data pointer
 */
void RidleyInSpaceUpdateAlertPalette(struct CutscenePaletteData* pPalette)
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

    if (pPalette->paletteRow >= ARRAY_SIZE(sRidleyInSpaceRedAlertPaletteRows))
        pPalette->paletteRow = 0;

    DMATransfer(3, &sRidleyInSpaceRedAlertPAL[sRidleyInSpaceRedAlertPaletteRows[pPalette->paletteRow] * 16],
        PALRAM_BASE + 0xA0, 16 * 2, 0x10);
}

/**
 * @brief 63fb4 | 1b4 | Handles the view of ship part
 * 
 * @return u8 FALSE
 */
u8 RidleyInSpaceViewOfShip(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            if (CUTSCENE_DATA.timeInfo.timer > 30)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 1:
            if (unk_61f44())
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.timeInfo.timer > 60)
            {
                CUTSCENE_DATA.oam[0].actions = 3;
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > 8)
            {
                CUTSCENE_DATA.oam[1].actions = 3;
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.timeInfo.timer > 60 * 2)
            {
                CUTSCENE_DATA.oam[0].objMode = TRUE;
                CUTSCENE_DATA.oam[1].objMode = TRUE;

                CutsceneStartBackgroundEffect(BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG3_SECOND_TARGET_PIXEL |
                    BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL, 14, 0, 32, 1);

                CUTSCENE_DATA.oam[2].actions = 3;
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 5:
            if (CUTSCENE_DATA.oam[2].actions == 0)
            {
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 6:
            if (CUTSCENE_DATA.timeInfo.timer > 90)
            {
                unk_61f0c();
                CUTSCENE_DATA.timeInfo.stage++;
                MACRO_CUTSCENE_NEXT_STAGE();
            }
            break;
    }

    RidleyInSpaceUpdateLeftBlueShip(&CUTSCENE_DATA.oam[0]);
    RidleyInSpaceUpdateRightBlueShip(&CUTSCENE_DATA.oam[1]);
    RidleyInSpaceUpdateViewOfShip(&CUTSCENE_DATA.oam[2]);
    RidleyInSpaceViewOfShipParticles();

    if (!(gFrameCounter8Bit & 7))
        (*CutsceneGetBGVOFSPointer(sRidleyInSpacePageData[0].bg))--;

    return FALSE;
}

/**
 * @brief 64168 | 64 | Updates the mother ship during the view of ship part
 * 
 * @param pOam Cutscene OAM data pointer
 */
void RidleyInSpaceUpdateViewOfShip(struct CutsceneOamData* pOam)
{
    if (pOam->actions & 2)
    {
        if (pOam->yPosition < BLOCK_SIZE * 2)
            pOam->unk_10 = 2;
        else
            pOam->unk_10 = 1;

        pOam->yPosition += pOam->unk_10;
        if (pOam->yPosition > 0xDF)
            pOam->actions = 0;
    }

    pOam->unk_18++;

    if (!(pOam->unk_18 & 0x1F))
        pOam->yPosition += sRidleyInSpaceShipsYMovementOffsets[((u16)pOam->unk_18 >> 5) & 7];
}

/**
 * @brief 641cc | 80 | Updates the right blue ship
 * 
 * @param pOam Cutscene oam data pointer
 */
void RidleyInSpaceUpdateRightBlueShip(struct CutsceneOamData* pOam)
{
    s32 yVelocity;
    
    if (pOam->actions & 1)
    {
        pOam->unk_E = -2;
        pOam->xPosition += pOam->unk_E;

        if (pOam->xPosition <= 0x2D0)
        {
            pOam->actions = 0;
            pOam->unk_18 = 0;
        }
    }

    if (pOam->actions & 2)
    {
        pOam->unk_10 = pOam->unk_18 & 1 ? -1 : 0;
        pOam->yPosition += pOam->unk_10;
    }

    pOam->unk_18++;

    if (!(pOam->unk_18 & 0xF))
        pOam->yPosition += sRidleyInSpaceShipsYMovementOffsets[((u16)pOam->unk_18 >> 4) & 7];
}

/**
 * @brief 6424c | 70 | Updates the left blue ship during the view of ship part
 * 
 * @param pOam 
 */
void RidleyInSpaceUpdateLeftBlueShip(struct CutsceneOamData* pOam)
{    
    if (pOam->actions & 1)
    {
        pOam->unk_E = 2;
        pOam->xPosition += pOam->unk_E;

        if (pOam->xPosition > 0x10F)
            pOam->actions = 0;
    }

    if (pOam->actions & 2)
    {
        pOam->unk_10 = -1;
        pOam->yPosition += pOam->unk_10;
    }

    pOam->unk_18++;

    if (!(pOam->unk_18 & 0xF))
        pOam->yPosition += sRidleyInSpaceShipsYMovementOffsets[((u16)pOam->unk_18 >> 4) & 7];
}

/**
 * @brief 642bc | 15c | Initializes the ridley in space cutscene
 * 
 * @return u8 FALSE
 */
u8 RidleyInSpaceInit(void)
{
    unk_61f0c();
    DMATransfer(3, sRidleyInSpaceSpaceBackgroundPAL, PALRAM_BASE, sizeof(sRidleyInSpaceSpaceBackgroundPAL), 0x10);
    write16(PALRAM_BASE, 0);

    CallLZ77UncompVRAM(sRidleyInSpaceSpaceBackgroundGfx, VRAM_BASE + sRidleyInSpacePageData[0].graphicsPage * 0x4000);
    CallLZ77UncompVRAM(sRidleyInSpaceSpaceBackgroundTileTable, VRAM_BASE + sRidleyInSpacePageData[0].tiletablePage * 0x800);

    DMATransfer(3, sRidleyInSpaceShipsPAL, PALRAM_OBJ, sizeof(sRidleyInSpaceShipsPAL), 0x10);
    CallLZ77UncompVRAM(sRidleyInSpaceShipsGfx, VRAM_BASE + 0x10000);

    CutsceneSetBGCNTPageData(sRidleyInSpacePageData[0]);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleyInSpacePageData[0].bg, 0x800);
    CutsceneReset();

    gWrittenToBLDY_NonGameplay = 0;
    CUTSCENE_DATA.bldcnt = 0;

    CUTSCENE_DATA.oam[0].xPosition = sRidleyInSpaceShipsStartPosition[0].x;
    CUTSCENE_DATA.oam[0].yPosition = sRidleyInSpaceShipsStartPosition[0].y;

    CUTSCENE_DATA.oam[1].xPosition = sRidleyInSpaceShipsStartPosition[1].x;
    CUTSCENE_DATA.oam[1].yPosition = sRidleyInSpaceShipsStartPosition[1].y;

    CUTSCENE_DATA.oam[2].xPosition = sRidleyInSpaceShipsStartPosition[2].x;
    CUTSCENE_DATA.oam[2].yPosition = sRidleyInSpaceShipsStartPosition[2].y;

    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[0], RIDLEY_IN_SPACE_OAM_ID_LEFT_BLUE_SHIP);
    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[1], RIDLEY_IN_SPACE_OAM_ID_RIGHT_BLUE_SHIP);
    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[2], RIDLEY_IN_SPACE_OAM_ID_MOTHER_SHIP);

    PlayMusic(MUSIC_RIDLEY_IN_SPACE, 0);
    SoundPlay(0x28D);
    CutsceneStartBackgroundFading(2);

    CUTSCENE_DATA.dispcnt = sRidleyInSpacePageData[0].bg | DCNT_OBJ;
    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;
    CUTSCENE_DATA.timeInfo.stage++;

    return FALSE;
}

/**
 * @brief 64418 | 34 | Subroutine for the ridley in space cutscene
 * 
 * @return u8 bool, ended
 */
u8 RidleyInSpaceSubroutine(void)
{
    u8 ended;

    ended = sRidleyInSpaceSubroutineData[CUTSCENE_DATA.timeInfo.stage].pFunction();
    
    CutsceneUpdateBackgroundsPosition(TRUE);
    RidleyInSpaceProcessOAM();
    return ended;
}

/**
 * @brief 6444c | 4c | Processes the OAM for the cutscene
 * 
 */
void RidleyInSpaceProcessOAM(void)
{
    gNextOamSlot = 0;
    ProcessCutsceneOam(sRidleyInSpaceSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sRidleyInSpaceCutsceneOAM);

    ResetFreeOAM();
    CalculateOamPart4(gCurrentOamRotation, gCurrentOamScaling, 0);
}

/**
 * @brief 64498 | 144 | Updates the particles during the view of ship part
 * 
 */
void RidleyInSpaceViewOfShipParticles(void)
{
    s32 i;
    u32 oamId;

    if (!(CUTSCENE_DATA.timeInfo.timer & 1))
    {
        for (i = 3; i < 29; i++)
        {
            if (CUTSCENE_DATA.oam[i].exists)
                continue;

            CUTSCENE_DATA.oam[i].actions = 0;

            CUTSCENE_DATA.oam[i].xPosition = (sRandomNumberTable[gFrameCounter8Bit + i & 0xFF] & 0x53) * 4;
            CUTSCENE_DATA.oam[i].yPosition = (sRandomNumberTable[CUTSCENE_DATA.oam[i].timer + i & 0xFF] & 0x53) * 4;

            CUTSCENE_DATA.oam[i].timer = 0;
            if (CUTSCENE_DATA.timeInfo.unk_6 & 1)
                CUTSCENE_DATA.oam[i].xPosition = BLOCK_SIZE * 15 - CUTSCENE_DATA.oam[i].xPosition;

            if (CUTSCENE_DATA.timeInfo.unk_6 & 2)
                CUTSCENE_DATA.oam[i].yPosition = BLOCK_SIZE * 10 - CUTSCENE_DATA.oam[i].yPosition;

            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[i], RIDLEY_IN_SPACE_OAM_ID_VIEW_OF_SHIP_PARTICLE);
            CUTSCENE_DATA.timeInfo.unk_6++;
            break;
        }
    }

    for (i = 3; i < 29; i++)
    {
        if (!CUTSCENE_DATA.oam[i].exists)
            continue;

        oamId = RidleyInSpaceViewOfShipUpdateParticle(&CUTSCENE_DATA.oam[i]);
        if (oamId != 0)
            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[i], oamId);

        if (CUTSCENE_DATA.oam[i].exists == 0)
            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[i], 0);
    }
}

/**
 * @brief 645dc | c0 | Updates a particle during the view of ship sequence
 * 
 * @param pOam Cutscene oam data pointer
 * @return u32 Oam Id
 */
u32 RidleyInSpaceViewOfShipUpdateParticle(struct CutsceneOamData* pOam)
{
    u32 oamId;
    s32 divisor;
    u32 xPosition;

    oamId = 0;
    pOam->unk_12 = pOam->timer;

    if (pOam->actions == 0)
    {
        pOam->unk_E = (pOam->xPosition - 0x78) * 0x190;
        pOam->unk_10 = (pOam->yPosition - 0x50) * 0x190;

        if (pOam->unk_E | pOam->unk_10)
            pOam->actions = 1;
        else
            pOam->exists = FALSE;
    }
    else if (pOam->unk_12 < 100)
    {
        if (pOam->unk_12 == 0x19 || pOam->unk_12 == 0x32 || pOam->unk_12 == 0x46)
            oamId = RIDLEY_IN_SPACE_OAM_ID_VIEW_OF_SHIP_PARTICLE2;

        divisor = -pOam->unk_12 + 0x64;
        xPosition = pOam->unk_E / divisor;
        pOam->xPosition = xPosition + 0x1E0;
        
        pOam->yPosition = pOam->unk_10 / divisor + 0x140;

        if ((u16)(xPosition + 0x200) > 0x400)
            pOam->exists = FALSE;
        else if (pOam->yPosition > 0x2A0)
            pOam->exists = FALSE;
        else if (pOam->yPosition < -0x20)
            pOam->exists = FALSE;
    }
    else
        pOam->exists = FALSE;

    pOam->timer++;
    return oamId;
}

/**
 * @brief 6469c | fc | Updates the particles during the ship leaving part
 * 
 */
void RidleyInSpaceShipLeavingParticles(void)
{
    s32 i;
    s32 newY;

    if (!(CUTSCENE_DATA.timeInfo.timer & 1))
    {
        for (i = 3; i < 15; i++)
        {
            if (CUTSCENE_DATA.oam[i].exists)
                continue;

            CUTSCENE_DATA.oam[i].actions = 0;

            CUTSCENE_DATA.oam[i].xPosition = -0x58;

            newY = sRandomNumberTable[(gFrameCounter8Bit + i) & 0xFF];
            if (newY < 0xA0)
            {
                CUTSCENE_DATA.oam[i].yPosition = newY * 4;
                CUTSCENE_DATA.oam[i].timer = 0;
                CUTSCENE_DATA.oam[i].unk_12 = sRandomNumberTable[i * gFrameCounter8Bit & 0xFF];

                if (CUTSCENE_DATA.oam[i].unk_12 & 1)
                    newY = RIDLEY_IN_SPACE_OAM_ID_SHIP_LEAVING_PARTICLE;
                else
                    newY = RIDLEY_IN_SPACE_OAM_ID_SHIP_LEAVING_PARTICLE2;

                UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[i], newY);
            }
            break;
        }
    }

    for (i = 3; i < 15; i++)
    {
        if (!CUTSCENE_DATA.oam[i].exists)
            continue;

        RidleyInSpaceShipLeavingUpdateParticle(&CUTSCENE_DATA.oam[i]);

        if (CUTSCENE_DATA.oam[i].exists == 0)
            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[i], 0);
    }
}

/**
 * @brief 64798 | 38 | Updates a particle during the ship leaving sequence
 * 
 * @param pOam Cutscene OAM Data Pointer
 * @return struct CutsceneOamData* First param
 */
struct CutsceneOamData* RidleyInSpaceShipLeavingUpdateParticle(struct CutsceneOamData* pOam)
{
    if (pOam->actions == 0)
    {
        pOam->unk_E = (pOam->unk_12 & 7) + 2;
        pOam->actions = 1;
    }
    else
    {
        pOam->xPosition += pOam->unk_E;
        if (pOam->xPosition > 0x3E0)
            pOam->exists = 0;
    }
}
