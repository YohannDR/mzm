#include "cutscenes/ridley_in_space.h"
#include "cutscenes/cutscene_utils.h"

#include "data/generic_data.h"
#include "data/shortcut_pointers.h"
#include "data/cutscenes/cutscenes_data.h"
#include "data/cutscenes/ridley_in_space_data.h"

#include "constants/audio.h"
#include "constants/cutscene.h"

#include "structs/display.h"
#include "structs/game_state.h"

void update_cutscene_oam_data_id(struct CutsceneOamData*, u8);

u8 RidleyInSpaceShipLeaving(void)
{

}

void RidleyInSpaceUpdateShipLeaving(struct CutsceneOamData* pOam)
{

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

            CallLZ77UncompVRAM(sRidleyInSpaceShipInterior2GFX, VRAM_BASE + sRidleyInSpacePageData[3].graphicsPage * 0x4000);
            CallLZ77UncompVRAM(sRidleyInSpaceRidleySuspiciousGFX, VRAM_BASE + sRidleyInSpacePageData[4].graphicsPage * 0x4000);

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

void RidleyInSpaceUpdateAlertPalette(struct CutsceneGraphicsData* pGraphics)
{

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
                CUTSCENE_DATA.oam[0].unk_D = 3;
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > 8)
            {
                CUTSCENE_DATA.oam[1].unk_D = 3;
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.timeInfo.timer > 60 * 2)
            {
                CUTSCENE_DATA.oam[0].unk_B_4 = TRUE;
                CUTSCENE_DATA.oam[1].unk_B_4 = TRUE;

                CutsceneStartBackgroundEffect(BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG3_SECOND_TARGET_PIXEL |
                    BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL, 14, 0, 32, 1);

                CUTSCENE_DATA.oam[2].unk_D = 3;
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 5:
            if (CUTSCENE_DATA.oam[2].unk_D == 0)
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

void RidleyInSpaceUpdateViewOfShip(struct CutsceneOamData* pOam)
{

}

void RidleyInSpaceUpdateRightBlueShip(struct CutsceneOamData* pOam)
{

}

void RidleyInSpaceUpdateLeftBlueShip(struct CutsceneOamData* pOam)
{

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

    CallLZ77UncompVRAM(sRidleyInSpaceSpaceBackgroundGFX, VRAM_BASE + sRidleyInSpacePageData[0].graphicsPage * 0x4000);
    CallLZ77UncompVRAM(sRidleyInSpaceSpaceBackgroundTileTable, VRAM_BASE + sRidleyInSpacePageData[0].tiletablePage * 0x800);

    DMATransfer(3, sRidleyInSpaceShipsPAL, PALRAM_BASE + 0x200, sizeof(sRidleyInSpaceShipsPAL), 0x10);
    CallLZ77UncompVRAM(sRidleyInSpaceShipsGFX, VRAM_BASE + 0x10000);

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

    update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[0], 1);
    update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[1], 2);
    update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[2], 3);

    PlayMusic(MUSIC_RIDLEY_IN_SPACE, 0);
    SoundPlay(0x28D);
    unk_61fa0(2);

    CUTSCENE_DATA.dispcnt = sRidleyInSpacePageData[0].bg | DCNT_OBJ;
    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;
    CUTSCENE_DATA.timeInfo.stage++;

    return FALSE;
}

u8 RidleyInSpaceSubroutine(void)
{

}

void RidleyInSpaceProcessOAM(void)
{

}

/**
 * @brief 64498 | 144 | Updates the particles during the view of ship part
 * 
 */
void RidleyInSpaceViewOfShipParticles(void)
{
    i32 i;
    u32 oamId;

    if (!(CUTSCENE_DATA.timeInfo.timer & 1))
    {
        for (i = 3; i < 29; i++)
        {
            if (CUTSCENE_DATA.oam[i].idChanged)
                continue;

            CUTSCENE_DATA.oam[i].unk_D = 0;

            CUTSCENE_DATA.oam[i].xPosition = (sRandomNumberTable[gFrameCounter8Bit + i & 0xFF] & 0x53) * 4;
            CUTSCENE_DATA.oam[i].yPosition = (sRandomNumberTable[CUTSCENE_DATA.oam[i].timer + i & 0xFF] & 0x53) * 4;

            CUTSCENE_DATA.oam[i].timer = 0;
            if (CUTSCENE_DATA.timeInfo.unk_6 & 1)
                CUTSCENE_DATA.oam[i].xPosition = BLOCK_SIZE * 15 - CUTSCENE_DATA.oam[i].xPosition;

            if (CUTSCENE_DATA.timeInfo.unk_6 & 2)
                CUTSCENE_DATA.oam[i].yPosition = BLOCK_SIZE * 10 - CUTSCENE_DATA.oam[i].yPosition;

            update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[i], 6);
            CUTSCENE_DATA.timeInfo.unk_6++;
            break;
        }
    }

    for (i = 3; i < 29; i++)
    {
        if (!CUTSCENE_DATA.oam[i].idChanged)
            continue;

        oamId = RidleyInSpaceViewOfShipUpdateParticle(&CUTSCENE_DATA.oam[i]);
        if (oamId != 0)
            update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[i], oamId);

        if (CUTSCENE_DATA.oam[i].idChanged == 0)
            update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[i], 0);
    }
}

u32 RidleyInSpaceViewOfShipUpdateParticle(struct CutsceneOamData* pOam)
{
    // https://decomp.me/scratch/BWCTd

    u32 oamId;
    i32 divisor;
    u32 xPosition;

    oamId = 0;
    pOam->unk_12 = pOam->timer;

    if (pOam->unk_D == 0)
    {
        pOam->unk_E = (pOam->xPosition - 0x78) * 0x190;
        pOam->unk_10 = (pOam->yPosition - 0x50) * 0x190;

        if (pOam->unk_E | pOam->unk_10)
            pOam->unk_D = 1;
        else
            pOam->idChanged = 0;
    }
    else if (pOam->timer < 100)
    {
        if (pOam->timer == 0x19 || pOam->timer == 0x32 || pOam->timer == 0x46)
            oamId = 8;

        divisor = -pOam->unk_12 + 0x64;
        xPosition = pOam->unk_E / divisor;
        pOam->xPosition = xPosition + 0x1E0;
        
        pOam->yPosition = pOam->unk_10 / divisor + 0x140;

        if ((u16)(xPosition + 0xC0) > 0x400 || pOam->yPosition > 0x2A0 || pOam->yPosition < -0x20)
            pOam->idChanged = 0;
    }
    else
        pOam->idChanged = 0;

    pOam->timer++;
    return oamId;
}

/**
 * @brief 6469c | fc | Updates the particles during the ship leaving part
 * 
 */
void RidleyInSpaceShipLeavingParticles(void)
{
    i32 i;
    i32 newY;

    if (!(CUTSCENE_DATA.timeInfo.timer & 1))
    {
        for (i = 3; i < 15; i++)
        {
            if (CUTSCENE_DATA.oam[i].idChanged)
                continue;

            CUTSCENE_DATA.oam[i].unk_D = 0;

            CUTSCENE_DATA.oam[i].xPosition = -0x58;

            newY = sRandomNumberTable[(gFrameCounter8Bit + i) & 0xFF];
            if (newY < 0xA0)
            {
                CUTSCENE_DATA.oam[i].yPosition = newY * 4;
                CUTSCENE_DATA.oam[i].timer = 0;
                CUTSCENE_DATA.oam[i].unk_12 = sRandomNumberTable[i * gFrameCounter8Bit & 0xFF];

                if (CUTSCENE_DATA.oam[i].unk_12 & 1)
                    newY = 9;
                else
                    newY = 10;

                update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[i], newY);
            }
            break;
        }
    }

    for (i = 3; i < 15; i++)
    {
        if (!CUTSCENE_DATA.oam[i].idChanged)
            continue;

        RidleyInSpaceViewOfShipUpdateParticle(&CUTSCENE_DATA.oam[i]);

        if (CUTSCENE_DATA.oam[i].idChanged == 0)
            update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[i], 0);
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
    if (pOam->unk_D == 0)
    {
        pOam->unk_E = (pOam->unk_12 & 7) + 2;
        pOam->unk_D = 1;
    }
    else
    {
        pOam->xPosition += pOam->unk_E;
        if (pOam->xPosition > 0x3E0)
            pOam->idChanged = 0;
    }
}
