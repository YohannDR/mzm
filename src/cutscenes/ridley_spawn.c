#include "cutscenes/ridley_spawn.h"
#include "cutscenes/cutscene_utils.h"

#include "data/shortcut_pointers.h"
#include "data/cutscenes/ridley_spawn_data.h"
#include "data/cutscenes/internal_ridley_spawn_data.h"
#include "data/cutscenes/cutscenes_data.h"

#include "constants/audio.h"
#include "constants/cutscene.h"
#include "constants/samus.h"

#include "structs/display.h"
#include "structs/samus.h"

/**
 * @brief 65304 | 19c | Handles the ridley flying in part of the cutscene
 * 
 * @return u8 FALSE
 */
u8 RidleySpawnRidleyFlyingIn(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            DmaTransfer(3, sRidleySpawnRidleyScreamingPal, PALRAM_OBJ, sizeof(sRidleySpawnRidleyScreamingPal), 0x10);
            CallLZ77UncompVram(sRidleySpawnScreamingGfx, VRAM_OBJ);
            
            CallLZ77UncompVram(sRidleySpawnBackgroundGfx, VRAM_BASE + sRidleySpawnPageData[3].graphicsPage * 0x4000);
            CallLZ77UncompVram(sRidleySpawnBackgroundTileTable, VRAM_BASE + sRidleySpawnPageData[3].tiletablePage * 0x800);
            DmaTransfer(3, sRidleySpawnBackgroundPal, PALRAM_BASE, sizeof(sRidleySpawnBackgroundPal), 0x10);
            SET_BACKDROP_COLOR(COLOR_BLACK);
            CutsceneSetBgcntPageData(sRidleySpawnPageData[3]);

            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleySpawnPageData[3].bg, 0x800);
            CutsceneReset();
            
            CUTSCENE_DATA.oam[0].xPosition = sRidleySpawnRidleyPositions[1].x;
            CUTSCENE_DATA.oam[0].yPosition = sRidleySpawnRidleyPositions[1].y;

            CUTSCENE_DATA.oam[0].rotationScaling = TRUE;
            CUTSCENE_DATA.oam[0].notDrawn = FALSE;
            CUTSCENE_DATA.oam[0].priority = 0;
            CUTSCENE_DATA.oam[0].objMode = FALSE;

            gCurrentOamScaling = Q_8_8(1.125f);
            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[0], RIDLEY_SPAWN_OAM_ID_RIDLEY_FLYING);
            CUTSCENE_DATA.dispcnt = sRidleySpawnPageData[3].bg | DCNT_OBJ;
            
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            CUTSCENE_DATA.oam[0].actions |= 3;
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 2:
            if (CUTSCENE_DATA.oam[0].actions == 0)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            unk_61f0c();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    RidleySpawnUpdateRidley(&CUTSCENE_DATA.oam[0]);

    return FALSE;
}

/**
 * @brief 654a0 | a0 | Updates the ridley object
 * 
 * @param pOam Cutscene OAM Pointer
 */
void RidleySpawnUpdateRidley(struct CutsceneOamData* pOam)
{
    u16 velocity;
    
    if (pOam->actions & 1)
    {
        pOam->unk_16 += 2;
        gCurrentOamScaling += 4 + DIV_SHIFT(pOam->unk_16, 8);

        if (gCurrentOamScaling >= Q_8_8(1.97f))
        {
            gCurrentOamScaling = Q_8_8(1.97f);
            pOam->actions = 0;
        }
        else if (pOam->oamID != RIDLEY_SPAWN_OAM_ID_RIDLEY_SCREAMING && gCurrentOamScaling >= Q_8_8(1.44f))
        {
            SoundPlay(SOUND_RIDLEY_SPAWN_ROAR);
            UpdateCutsceneOamDataID(pOam, RIDLEY_SPAWN_OAM_ID_RIDLEY_SCREAMING);
        }
    }

    if (pOam->actions & 2)
    {
        pOam->unk_18++;
        velocity = DIV_SHIFT((u16)pOam->unk_18, 4);
        pOam->yVelocity = 4 - velocity;
        if (pOam->yVelocity < 0)
        {
            pOam->yVelocity = 0;
            pOam->actions &= 1;
        }

        pOam->yVelocity *= 4;
        pOam->yPosition += pOam->yVelocity;
    }
}

/**
 * @brief 65540 | 12c | Handles the helmet reflection part
 * 
 * @return u8 FALSE
 */
u8 RidleySpawnHelmetReflection(void)
{    
    s32 velocity;

    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            CutsceneReset();
            gWrittenToBLDALPHA_L = 10;
            gWrittenToBLDALPHA_H = 6;

            CUTSCENE_DATA.bldcnt = BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET;

            CUTSCENE_DATA.oam[0].xPosition = sRidleySpawnRidleyPositions[0].x;
            CUTSCENE_DATA.oam[0].yPosition = sRidleySpawnRidleyPositions[0].y;

            CUTSCENE_DATA.oam[0].priority = sRidleySpawnPageData[2].priority;
            CUTSCENE_DATA.oam[0].rotationScaling = TRUE;
            CUTSCENE_DATA.oam[0].objMode = 1;

            gCurrentOamScaling = Q_8_8(.25f);
            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[0], RIDLEY_SPAWN_OAM_ID_RIDLEY_FLYING_REFLECTION);
            CUTSCENE_DATA.dispcnt = sRidleySpawnPageData[1].bg | sRidleySpawnPageData[2].bg | DCNT_OBJ;

            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            gCurrentOamScaling += Q_8_8(0.0625f);
            if (gCurrentOamScaling >= Q_8_8(2.f))
            {
                gCurrentOamScaling = Q_8_8(2.f);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }

            velocity = 8 - SUB_PIXEL_TO_PIXEL(CUTSCENE_DATA.timeInfo.timer);
            if (velocity > 0)
                CUTSCENE_DATA.oam[0].yPosition += velocity;

            CUTSCENE_DATA.oam[0].xPosition -= PIXEL_SIZE;
            break;

        case 2:
            unk_61f0c();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
    }

    return FALSE;
}

/**
 * @brief 6566c | 7c | Handles the samus looking up part of the cutscene
 * 
 * @return u8 FALSE
 */
u8 RidleySpawnSamusLookingUp(void)
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
            gCurrentOamScaling += Q_8_8(0.25f / 2);
            if (gCurrentOamScaling >= Q_8_8(2.f))
            {
                gCurrentOamScaling = Q_8_8(2.f);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;
        
        case 2:
            if (CUTSCENE_DATA.timeInfo.timer > 40)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    return FALSE;
}

/**
 * @brief 656e8 | 1bc | Initializes the ridley spawn cutscene
 * 
 * @return u8 FALSE
 */
u8 RidleySpawnInit(void)
{
    unk_61f0c();

    if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
        DmaTransfer(3, sRidleySpawnSamusVariaPal, PALRAM_OBJ, sizeof(sRidleySpawnSamusVariaPal), 0x10);
    else
        DmaTransfer(3, sRidleySpawnSamusPal, PALRAM_OBJ, sizeof(sRidleySpawnSamusPal), 0x10);

    DmaTransfer(3, sRidleySpawnBackgroundPal, PALRAM_BASE, sizeof(sRidleySpawnBackgroundPal), 0x10);
    SET_BACKDROP_COLOR(COLOR_BLACK);

    CallLZ77UncompVram(sRidleySpawnSamusAndRidleyGfx, VRAM_OBJ);

    CallLZ77UncompVram(sRidleySpawnBackgroundGfx, VRAM_BASE + sRidleySpawnPageData[0].graphicsPage * 0x4000);
    CallLZ77UncompVram(sRidleySpawnBackgroundTileTable, VRAM_BASE + sRidleySpawnPageData[0].tiletablePage * 0x800);

    CallLZ77UncompVram(sRidleySpawnSamusHelmetFaceGfx, VRAM_BASE + sRidleySpawnPageData[1].graphicsPage * 0x4000);
    CallLZ77UncompVram(sRidleySpawnSamusHelmetTileTable, VRAM_BASE + sRidleySpawnPageData[1].tiletablePage * 0x800);
    CallLZ77UncompVram(sRidleySpawnSamusFaceTileTable, VRAM_BASE + sRidleySpawnPageData[2].tiletablePage * 0x800);

    CutsceneSetBgcntPageData(sRidleySpawnPageData[1]);
    CutsceneSetBgcntPageData(sRidleySpawnPageData[2]);
    CutsceneSetBgcntPageData(sRidleySpawnPageData[0]);

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleySpawnPageData[1].bg, 0x800);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleySpawnPageData[2].bg, 0x800);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleySpawnPageData[0].bg, 0x800);
    
    CutsceneReset();

    CUTSCENE_DATA.oam[0].xPosition = sRidleySpawnRidleyPositions[2].x;
    CUTSCENE_DATA.oam[0].yPosition = sRidleySpawnRidleyPositions[2].y;
    CUTSCENE_DATA.oam[0].priority = sRidleySpawnPageData[0].priority;
    CUTSCENE_DATA.oam[0].rotationScaling = TRUE;
    CUTSCENE_DATA.oam[0].objMode = 1;

    gCurrentOamScaling = 0x100;
    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[0], RIDLEY_SPAWN_OAM_ID_SAMUS);

    CUTSCENE_DATA.dispcnt = sRidleySpawnPageData[0].bg | DCNT_OBJ;

    PlayMusic(MUSIC_RIDLEY_BATTLE, 0);
    CUTSCENE_DATA.timeInfo.stage++;
    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;
    
    return FALSE;
}

/**
 * @brief 658a4 | 34 | Subroutine for the ridley spawn cutscene
 * 
 * @return u8 bool, ended
 */
u8 RidleySpawnSubroutine(void)
{
    u8 ended;

    ended = sRidleySpawnSubroutineData[CUTSCENE_DATA.timeInfo.stage].pFunction();
    CutsceneUpdateBackgroundsPosition(TRUE);
    RidleySpawnProcessOAM();
    
    return ended;
}

/**
 * @brief 658d8 | 4c | Processes the OAM for the cutscene
 * 
 */
void RidleySpawnProcessOAM(void)
{
    gNextOamSlot = 0;
    ProcessCutsceneOam(sRidleySpawnSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sRidleySpawnOam);
    ResetFreeOam();
    CalculateOamPart4(gCurrentOamRotation, gCurrentOamScaling, 0);
}
