#include "cutscenes/ridley_spawn.h"
#include "cutscenes/cutscene_utils.h"

#include "data/shortcut_pointers.h"
#include "data/cutscenes/ridley_spawn.h"
#include "data/cutscenes/cutscenes_data.h"

#include "constants/cutscene.h"

#include "structs/display.h"

u8 RidleySpawnRidleyFlyingIn(void)
{

}

/**
 * @brief 654a0 | a0 | Updates the ridley object
 * 
 * @param pOam Cutscene OAM Pointer
 */
void RidleySpawnUpdateRidley(struct CutsceneOamData* pOam)
{
    u16 velocity;
    
    if (pOam->unk_D & 1)
    {
        pOam->unk_16 += 2;
        gCurrentOamScaling += 4 +  (pOam->unk_16 >> 3);

        if (gCurrentOamScaling >= 0x1F8)
        {
            gCurrentOamScaling = 0x1F8;
            pOam->unk_D = 0;
        }
        else if (pOam->oamID != 3 && gCurrentOamScaling > 0x16F)
        {
            SoundPlay(0x24C); // Ridley cutscene roar
            update_cutscene_oam_data_id(pOam, 3);
        }
    }

    if (pOam->unk_D & 2)
    {
        pOam->unk_18++;
        velocity = (u16)pOam->unk_18 >> 2;
        pOam->unk_10 = 4 - velocity;
        if (pOam->unk_10 < 0)
        {
            pOam->unk_10 = 0;
            pOam->unk_D &= 1;
        }

        pOam->unk_10 *= 4;
        pOam->yPosition += pOam->unk_10;
    }
}

u8 RidleySpawnHelmetReflection(void)
{
    // https://decomp.me/scratch/sJH9O
    
    i32 velocity;

    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            CutsceneReset();
            gWrittenToBLDALPHA_L = 10;
            gWrittenToBLDALPHA_H = 6;

            CUTSCENE_DATA.bldcnt = BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG0_SECOND_TARGET_PIXEL |
                BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL |
                BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL |
                BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            CUTSCENE_DATA.oam[0].xPosition = sRidleySpawnRidleyPositions[0].x;
            CUTSCENE_DATA.oam[0].yPosition = sRidleySpawnRidleyPositions[0].y;

            CUTSCENE_DATA.oam[0].priority = sRidleySpawnPageData[2].priority;
            CUTSCENE_DATA.oam[0].unk_C_4 = TRUE;
            CUTSCENE_DATA.oam[0].unk_B_4 = TRUE;

            gCurrentOamScaling = 0x40;
            update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[0], 1);
            CUTSCENE_DATA.dispcnt = sRidleySpawnPageData[1].bg | sRidleySpawnPageData[2].bg | DCNT_OBJ;

            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            gCurrentOamScaling += 0x10;
            if (gCurrentOamScaling >= 0x200)
            {
                gCurrentOamScaling = 0x200;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }

            velocity = 8 - CUTSCENE_DATA.timeInfo.timer / 4;
            if (velocity > 0)
                CUTSCENE_DATA.oam[0].yPosition += velocity;

            CUTSCENE_DATA.oam[0].xPosition -= 4;
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
            gCurrentOamScaling += 0x20;
            if (gCurrentOamScaling >= 0x200)
            {
                gCurrentOamScaling = 0x200;
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

u8 RidleySpawnInit(void)
{

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
    process_cutscene_oam(sRidleySpawnSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sRidleySpawnOam);
    ResetFreeOAM();
    calculate_oam_part4(gCurrentOamRotation, gCurrentOamScaling, 0);
}
