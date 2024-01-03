#include "cutscenes/ridley_landing.h"
#include "cutscenes/cutscene_utils.h"
#include "temp_globals.h"

#include "data/cutscenes/cutscenes_data.h"
#include "data/cutscenes/ridley_landing_data.h"
#include "data/cutscenes/internal_ridley_landing_data.h"
#include "data/shortcut_pointers.h"

#include "constants/audio.h"
#include "constants/cutscene.h"

#include "structs/display.h"
#include "structs/game_state.h"

/**
 * @brief 647d0 | 178 | Handles the ridley flying part
 * 
 * @return u8 FALSE
 */
u8 RidleyLandingRidleyFlying(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            DmaTransfer(3, sRidleyLandingSkyBackgroundPal, PALRAM_BASE, 0xA0, 0x10);
			DmaTransfer(3, sRidleyLandingRidleyAndRocksPal, PALRAM_OBJ, 0x40, 0x10);
			
            SET_BACKDROP_COLOR(COLOR_BLACK);
			
            CallLZ77UncompVram(sRidleyLandingRidleyFlyingBackgroundGfx, VRAM_BASE + sRidleyLandingPageData[4].graphicsPage * 0x4000);
			CallLZ77UncompVram(sRidleyLandingRidleyAndRockShadowGfx, VRAM_BASE + 4 * 0x4000);
			CallLZ77UncompVram(sRidleyLandingRidleyFlyingBackgroundTileTable, VRAM_BASE + sRidleyLandingPageData[4].tiletablePage * 0x800);
			
            CutsceneSetBgcntPageData(sRidleyLandingPageData[4]);
			CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleyLandingPageData[4].bg, 0x800);
			CutsceneReset();
            
            CUTSCENE_DATA.oam[1].xPosition = 0x480;
			CUTSCENE_DATA.oam[1].yPosition = 0x180;
			UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[1], RIDLEY_LANDING_OAM_ID_RIDLEY);
            
			CUTSCENE_DATA.oam[0].xPosition = 0x2C0;
			CUTSCENE_DATA.oam[0].yPosition = 0x200;
			UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[0], RIDLEY_LANDING_OAM_ID_ROCKS);
            
            CUTSCENE_DATA.dispcnt = sRidleyLandingPageData[4].bg | DCNT_OBJ;
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > 60)
            {
                SoundPlay(0x292);
                CUTSCENE_DATA.oam[1].actions |= (1 | 2);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.oam[1].actions == 0)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > 60)
            {
                unk_61f0c();
                CUTSCENE_DATA.timeInfo.stage++;
                MACRO_CUTSCENE_NEXT_STAGE();
            }
            break;
    }

    RidleyLandingUpdateRidley(&CUTSCENE_DATA.oam[1]);
    return FALSE;
}

void RidleyLandingUpdateRidley(struct CutsceneOamData* pOam)
{
    u16* pX;

    if (pOam->actions & 1)
    {
        pOam->unk_16++;
        pOam->xVelocity = -0x24;
        pOam->xPosition += pOam->xVelocity;

        if (pOam->xPosition < -0xFF)
            pOam->actions = 0;

        if (pOam->unk_16 == 8)
            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[0], RIDLEY_LANDING_OAM_ID_ROCKS_AND_RIDLEY_SHADOW);
    }

    if (pOam->actions & 2)
    {
        pOam->unk_18++;
        pOam->yVelocity = -((u16)pOam->unk_18 >> 1);
        pOam->yPosition += pOam->yVelocity;
    }
}

/**
 * @brief 649b4 | 5a8 | Handles the ship landing part
 * 
 * @return u8 FALSE
 */
u8 RidleyLandingShipLanding(void)
{
    s32 movement;

    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            DmaTransfer(3, sCutsceneZebesPal, PALRAM_BASE, sizeof(sCutsceneZebesPal), 0x10);
            DmaTransfer(3, sCutsceneMotherShipPal, PALRAM_OBJ, sizeof(sCutsceneMotherShipPal), 0x10);

            SET_BACKDROP_COLOR(COLOR_BLACK);

            CallLZ77UncompVram(sCutsceneZebesMotherShipBackgroundGfx, VRAM_BASE + sRidleyLandingPageData[1].graphicsPage * 0x4000);
            CallLZ77UncompVram(sCutsceneZebesGroundGfx, VRAM_BASE + sRidleyLandingPageData[3].graphicsPage * 0x4000);
            CallLZ77UncompVram(sCutsceneZebesRockyBackgroundGfx, VRAM_BASE + 0x4C00 + sRidleyLandingPageData[2].graphicsPage * 0x4000);

            BitFill(3, 0, VRAM_OBJ, 0x800, 0x20);
            CallLZ77UncompVram(sCutsceneMotherShipEscapeShipParticlesGfx, VRAM_OBJ);

            CallLZ77UncompVram(sCutsceneZebesMotherShipBackgroundTileTable, VRAM_BASE + sRidleyLandingPageData[1].tiletablePage * 0x800);
            CallLZ77UncompVram(sCutscene_3b5168_TileTable, VRAM_BASE + sRidleyLandingPageData[2].tiletablePage * 0x800);
            CallLZ77UncompVram(sCutsceneZebesGroundTileTable, VRAM_BASE + sRidleyLandingPageData[3].tiletablePage * 0x800);

            CutsceneSetBgcntPageData(sRidleyLandingPageData[1]);
            CutsceneSetBgcntPageData(sRidleyLandingPageData[2]);
            CutsceneSetBgcntPageData(sRidleyLandingPageData[3]);

            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleyLandingPageData[1].bg, 0x800);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleyLandingPageData[2].bg, 0x800);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleyLandingPageData[3].bg, 0x800);

            CutsceneReset();

            CUTSCENE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
                BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            gWrittenToBLDY_NonGameplay = 16;

            CUTSCENE_DATA.oam[6].xPosition = BLOCK_SIZE * 7 + HALF_BLOCK_SIZE;
            CUTSCENE_DATA.oam[6].yPosition = -BLOCK_SIZE * 8;
            CUTSCENE_DATA.oam[6].boundBackground = 3;
            CUTSCENE_DATA.oam[6].priority = 1;

            CUTSCENE_DATA.oam[7].boundBackground = 3;
            CUTSCENE_DATA.oam[7].priority = 1;
            
            CUTSCENE_DATA.oam[8].boundBackground = 3;
            CUTSCENE_DATA.oam[8].priority = 1;

            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[6], 2);
            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[7], 3);
            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[8], 4);

            CUTSCENE_DATA.dispcnt = sRidleyLandingPageData[1].bg | DCNT_OBJ;

            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;

        case 1:
            SoundPlay(0x290);
            CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt, 0, 4, 1);
            CutsceneStartBackgroundScrolling(sRidleyLandingScrollingInfo[0], sRidleyLandingPageData[1].bg);

            CUTSCENE_DATA.oam[6].actions = 1;
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 2:
            movement = *CutsceneGetBgVerticalPointer(sRidleyLandingPageData[1].bg);

            if (!(CUTSCENE_DATA.dispcnt & sRidleyLandingPageData[2].bg))
            {
                if (movement >= 2848 - sRidleyLandingScrollingInfo[1].length / 1.5)
                {
                    CUTSCENE_DATA.dispcnt |= sRidleyLandingPageData[2].bg;
                    CutsceneStartBackgroundScrolling(sRidleyLandingScrollingInfo[1], sRidleyLandingPageData[2].bg);
                }
            }

            if (!(CUTSCENE_DATA.dispcnt & sRidleyLandingPageData[3].bg))
            {
                if (movement >= 0xb20 - sRidleyLandingScrollingInfo[2].length / 2)
                {
                    CUTSCENE_DATA.dispcnt |= sRidleyLandingPageData[3].bg;
                    CutsceneStartBackgroundScrolling(sRidleyLandingScrollingInfo[2], sRidleyLandingPageData[3].bg);
                    CUTSCENE_DATA.timeInfo.timer = 0;
                    CUTSCENE_DATA.timeInfo.subStage++;
                }
            }
            break;

        case 3:
            if (!CUTSCENE_DATA.oam[6].actions)
            {
                SoundPlay(0x291);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            switch (CUTSCENE_DATA.timeInfo.timer)
            {
                case 8:
                    movement = -12;
                    break;

                case 16:
                    CUTSCENE_DATA.oam[0].oamID = 5;
                    CUTSCENE_DATA.oam[0].oamID++;
                    movement = -8;
                    break;

                case 4:
                case 12:
                case 20:
                    movement = 8;
                    break;

                case 24:
                    CUTSCENE_DATA.oam[1].oamID = 5;
                    CUTSCENE_DATA.oam[1].oamID++;
                    movement = -4;
                    CUTSCENE_DATA.timeInfo.timer = 0;
                    CUTSCENE_DATA.timeInfo.subStage++;
                    break;

                default:
                    movement = 0;
            }

            if (movement == 0)
                break;

            gBg3VOFS_NonGameplay += movement / 2;
            gBg1VOFS_NonGameplay += movement;
            gBg0VOFS_NonGameplay += movement;
            CUTSCENE_DATA.oam[6].yPosition -= movement;
            break;

        case 5:
            if (CUTSCENE_DATA.timeInfo.timer > 60)
            {
                unk_61f0c();
                CUTSCENE_DATA.timeInfo.stage++;
                MACRO_CUTSCENE_NEXT_STAGE();
            }
    }

    RidleyLandingUpdateShipLanding(&CUTSCENE_DATA.oam[6]);

    CUTSCENE_DATA.oam[7].xPosition = CUTSCENE_DATA.oam[6].xPosition;
    CUTSCENE_DATA.oam[7].yPosition = CUTSCENE_DATA.oam[6].yPosition;
    CUTSCENE_DATA.oam[8].xPosition = CUTSCENE_DATA.oam[6].xPosition;
    CUTSCENE_DATA.oam[8].yPosition = CUTSCENE_DATA.oam[6].yPosition;

    movement = gBg3VOFS_NonGameplay - CUTSCENE_DATA.oam[6].yPosition;
    if (BLOCK_SIZE * 15u + HALF_BLOCK_SIZE < movement - BLOCK_SIZE * 37 + HALF_BLOCK_SIZE)
        movement = TRUE;
    else
        movement = FALSE;
    CUTSCENE_DATA.oam[6].notDrawn = movement;

    movement = gBg3VOFS_NonGameplay - CUTSCENE_DATA.oam[7].yPosition;
    if (BLOCK_SIZE * 17u < movement - BLOCK_SIZE * 32)
        movement = TRUE;
    else
        movement = FALSE;
    CUTSCENE_DATA.oam[7].notDrawn = movement;

    movement = gBg3VOFS_NonGameplay - CUTSCENE_DATA.oam[8].yPosition;
    if (BLOCK_SIZE * 13u + HALF_BLOCK_SIZE < movement - BLOCK_SIZE * 31 + QUARTER_BLOCK_SIZE)
        movement = TRUE;
    else
        movement = FALSE;
    CUTSCENE_DATA.oam[8].notDrawn = movement;

    return FALSE;
}

/**
 * @brief 64f5c | 84 | Updates the ship landing
 * 
 * @param pOam Cutscene OAM Data Pointer
 * @return struct CutsceneOamData* First param
 */
struct CutsceneOamData* RidleyLandingUpdateShipLanding(struct CutsceneOamData* pOam)
{
    s32 yPosition;

    if (pOam->actions != 0)
    {
        yPosition = 0x58 - pOam->yPosition;
        
        if (yPosition > 0x10)
            pOam->yPosition++;
        else if (yPosition != 0)
            pOam->yPosition++;

        if (yPosition == 0x88)
        {
            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[0], RIDLEY_LANDING_OAM_ID_SMOKE_PARTICLES);
            CUTSCENE_DATA.oam[0].xPosition = BLOCK_SIZE * 7 - QUARTER_BLOCK_SIZE;
            CUTSCENE_DATA.oam[0].yPosition = BLOCK_SIZE * 9;
        }
        else if (yPosition == 0x78)
        {
            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[1], RIDLEY_LANDING_OAM_ID_SMOKE_PARTICLES);
            CUTSCENE_DATA.oam[1].xPosition = BLOCK_SIZE * 9;
            CUTSCENE_DATA.oam[1].yPosition = BLOCK_SIZE * 9 + QUARTER_BLOCK_SIZE;
        }
        else if (yPosition == 0)
            pOam->actions = 0;
    }
}

/**
 * @brief 64fe0 | 108 | Handles the ship in space part
 * 
 * @return u8 FALSE
 */
u8 RidleyLandingShipInSpace(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt, 0, 2, 1);
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            if (CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_SPRITE_ENDED)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.timeInfo.timer > 60 * 3)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }

            if (CUTSCENE_DATA.timeInfo.timer == 110)
                CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt, 16, 4, 1);
            break;

        case 3:
            unk_61f0c();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    if (CUTSCENE_DATA.timeInfo.subStage >= 3)
        return FALSE;

    if (MOD_AND(gFrameCounter8Bit, 8) == 6)
        (*CutsceneGetBgHorizontalPointer(sRidleyLandingPageData[0].bg))++;

    if (gFrameCounter8Bit & 1)
    {
        CUTSCENE_DATA.oam[0].xPosition++;
        return FALSE;
    }

    if (MOD_AND(gFrameCounter8Bit, 4) == 0)
        CUTSCENE_DATA.oam[0].yPosition++;

    if (MOD_AND(gFrameCounter8Bit, 16) == 0)
        gCurrentOamScaling -= Q_8_8(.035f);

    return FALSE;
}

/**
 * @brief 650e8 | 19c | Initializes the ridley landing cutscene
 * 
 * @return u8 FALSE
 */
u8 RidleyLandingInit(void)
{
    unk_61f0c();

    DmaTransfer(3, sCutscene_3a09d4_Pal, PALRAM_BASE, sizeof(sCutscene_3a09d4_Pal), 0x10);
    DmaTransfer(3, PALRAM_BASE, PALRAM_OBJ, 0x200, 0x20);
    SET_BACKDROP_COLOR(COLOR_BLACK);

    CallLZ77UncompVram(sRidleyLandingZebesBackgroundGfx, VRAM_BASE + sRidleyLandingPageData[0].graphicsPage * 0x4000);
    CallLZ77UncompVram(sRidleyLandingZebesBackgroundTileTable, VRAM_BASE + sRidleyLandingPageData[0].tiletablePage * 0x800);

    CallLZ77UncompVram(sRidleyLandingMotherShipGfx_1, VRAM_OBJ);
    CallLZ77UncompVram(sRidleyLandingMotherShipGfx_2, VRAM_BASE + 0x10400);
    CallLZ77UncompVram(sRidleyLandingMotherShipGfx_3, VRAM_BASE + 0x10800);
    CallLZ77UncompVram(sRidleyLandingMotherShipGfx_4, VRAM_BASE + 0x10C00);
    CallLZ77UncompVram(sRidleyLandingMotherShipGfx_5, VRAM_BASE + 0x11000);
    CallLZ77UncompVram(sRidleyLandingMotherShipGfx_6, VRAM_BASE + 0x11400);
    CallLZ77UncompVram(sRidleyLandingMotherShipGfx_7, VRAM_BASE + 0x11800);
    CallLZ77UncompVram(sRidleyLandingMotherShipGfx_8, VRAM_BASE + 0x11C00);
    CallLZ77UncompVram(sRidleyLandingMotherShipGfx_9, VRAM_BASE + 0x12000);

    CutsceneSetBgcntPageData(sRidleyLandingPageData[0]);
    CutsceneReset();

    CUTSCENE_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET |
        BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

    gWrittenToBLDY_NonGameplay = 16;
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleyLandingPageData[0].bg, 0x800);

    CUTSCENE_DATA.oam[0].xPosition = 0;
    CUTSCENE_DATA.oam[0].yPosition = BLOCK_SIZE * 3;
    CUTSCENE_DATA.oam[0].rotationScaling = TRUE;

    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[0], RIDLEY_LANDING_OAM_ID_MOTHER_SHIP_IN_SPACE);

    PlayMusic(MUSIC_RIDLEY_LANDING, 0);
    SoundPlay(0x28F);

    CUTSCENE_DATA.dispcnt = sRidleyLandingPageData[0].bg | DCNT_OBJ;
    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;
    CUTSCENE_DATA.timeInfo.stage++;

    return FALSE;
}

/**
 * @brief 65284 | 34 | Subroutine for the ridley landing cutscene
 * 
 * @return u8 bool, ended
 */
u8 RidleyLandingSubroutine(void)
{
    u8 ended;

    ended = sRidleyLandingSubroutineData[CUTSCENE_DATA.timeInfo.stage].pFunction();
    CutsceneUpdateBackgroundsPosition(TRUE);
    RidleyLandingProcessOAM();

    return ended;
}

/**
 * @brief 652b8 | 4c | Processes the OAM
 * 
 */
void RidleyLandingProcessOAM(void)
{
    gNextOamSlot = 0;

    ProcessCutsceneOam(sRidleyLandingSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sRidleyLandingCutsceneOAM);
    ResetFreeOam();
    CalculateOamPart4(gCurrentOamRotation, gCurrentOamScaling, 0);
}
