#include "cutscenes/mother_brain_close_up.h"
#include "cutscenes/cutscene_utils.h"
#include "temp_globals.h"

#include "data/shortcut_pointers.h"
#include "data/cutscenes/cutscenes_data.h"
#include "data/cutscenes/mother_brain_close_up_data.h"
#include "data/cutscenes/internal_mother_brain_close_up_data.h"

#include "constants/audio.h"
#include "constants/cutscene.h"
#include "constants/samus.h"

#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/samus.h"

/**
 * @brief 63008 | 234 | Handles the looking at samus part
 * 
 * @return u8 FALSE
 */
u8 MotherBrainCloseUpLookingAtSamus(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            DMATransfer(3, sMotherBrainCloseUpBackgroundPAL, PALRAM_BASE, sizeof(sMotherBrainCloseUpBackgroundPAL), 0x10);
            write16(PALRAM_BASE, 0);

            // Load samus palette (varia or power suit)
            if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
                DMATransfer(3, sMotherBrainCloseUpSamusVariaPAL, PALRAM_BASE + 0xA0, sizeof(sMotherBrainCloseUpSamusVariaPAL), 0x10);
            else
                DMATransfer(3, sMotherBrainCloseUpSamusPAL, PALRAM_BASE + 0xA0, sizeof(sMotherBrainCloseUpSamusPAL), 0x10);

            // Load samus graphics
            CallLZ77UncompVRAM(sMotherBrainCloseUpSamusGFX, VRAM_BASE + sMotherBrainCloseUpPageData[4].graphicsPage * 0x4000);
            CallLZ77UncompVRAM(sMotherBrainCloseUpBackgroundTileTable, VRAM_BASE + sMotherBrainCloseUpPageData[3].tiletablePage * 0x800);
            CallLZ77UncompVRAM(sMotherBrainCloseUpSamusTileTable, VRAM_BASE + sMotherBrainCloseUpPageData[4].tiletablePage * 0x800);

            // Load big eye graphics
            DMATransfer(3, sMotherBrainCloseUpBigEyePAL, PALRAM_BASE + 0x200, sizeof(sMotherBrainCloseUpBigEyePAL), 0x10);
            CallLZ77UncompVRAM(sMotherBrainCloseUpBigEyeGFX, VRAM_BASE + 0x10000);

            CutsceneSetBGCNTPageData(sMotherBrainCloseUpPageData[4]);
            CutsceneSetBGCNTPageData(sMotherBrainCloseUpPageData[3]);

            CutsceneReset();

            // Update eye
            MotherBrainCloseUpUpdateEye(TRUE);

            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            CallLZ77UncompVRAM(sMotherBrainCloseUpBackgroundGFX, VRAM_BASE + sMotherBrainCloseUpPageData[3].graphicsPage * 0x4000);

            // Start small fade on eye
            CutsceneStartBackgroundEffect(BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG0_SECOND_TARGET_PIXEL |
                BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL |
                BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL, 12, 12, 8, 1);

            // Start screen shake for the elevator/samus
            CutsceneStartScreenShake(sMotherBrainCloseUpScreenShakeInfo, sMotherBrainCloseUpPageData[4].bg);

            CUTSCENE_DATA.dispcnt = DCNT_OBJ | sMotherBrainCloseUpPageData[3].bg | sMotherBrainCloseUpPageData[4].bg;
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 2:
            // Wait for fade to end
            if (CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_BG_ENDED)
            {
                // Allow elevator animation to start
                CUTSCENE_DATA.oam[0].unk_D = 1;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > sMotherBrainCloseUpLookingAtSamusTimers[0])
            {
                SoundPlay(0x230);

                // Set eye focusing animation
                update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[1], 6);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            // Simply wait
            if (CUTSCENE_DATA.timeInfo.timer > sMotherBrainCloseUpLookingAtSamusTimers[1])
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

    MotherBrainCloseUpUpdateElevatorReflection(&CUTSCENE_DATA.oam[0]);

    return FALSE;
}

/**
 * @brief 6323c | 48 | Updates the elevator reflection object
 * 
 * @param pOam Cutscene OAM data pointer
 */
void MotherBrainCloseUpUpdateElevatorReflection(struct CutsceneOamData* pOam)
{
    if (pOam->unk_D == 0)
        return;

    if (pOam->unk_D == 1)
    {
        // Set cooldown
        pOam->timer = 60;
        pOam->unk_D = 2;
        return;
    }

    if (pOam->timer != 0)
    {
        pOam->timer--;
        return;
    }

    // Set cooldown
    pOam->timer = 90;

    // Set the elevator animation
    update_cutscene_oam_data_id(pOam, 4);

    // Check for elevator animation limit
    pOam->unk_D++;
    if (pOam->unk_D > 6)
        pOam->unk_D = 0; // Stop animation
}

/**
 * @brief 63284 | 23c | Handles the eye opening part
 * 
 * @return u8 FALSE
 */
u8 MotherBrainCloseUpEyeOpening(void)
{
    i32 i;

    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            DMATransfer(3, sMotherBrainCloseUpPAL, PALRAM_BASE, sizeof(sMotherBrainCloseUpPAL), 0x10);
            write16(PALRAM_BASE, 0);

            // Load mother brain close up graphics
            CallLZ77UncompVRAM(sMotherBrainCloseUpMotherBrainGFX, VRAM_BASE + sMotherBrainCloseUpPageData[2].graphicsPage * 0x4000);
            CallLZ77UncompVRAM(sMotherBrainCloseUpMotherBrainTileTable, VRAM_BASE + sMotherBrainCloseUpPageData[2].tiletablePage * 0x800);

            // Load glass tile table
            CallLZ77UncompVRAM(sMotherBrainCloseUpGlassTileTable, VRAM_BASE + sMotherBrainCloseUpPageData[1].tiletablePage * 0x800);

            // Load eye graphics
            DMATransfer(3, sMotherBrainCloseUpEyePAL, PALRAM_BASE + 0x200, sizeof(sMotherBrainCloseUpEyePAL), 0x10);
            CallLZ77UncompVRAM(sMotherBrainCloseUpEyeGFX, VRAM_BASE + 0x10000);

            CutsceneSetBGCNTPageData(sMotherBrainCloseUpPageData[2]);
            CutsceneSetBGCNTPageData(sMotherBrainCloseUpPageData[1]);
            CutsceneReset();

            // Initialize eye
            MotherBrainCloseUpUpdateEye(FALSE);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sMotherBrainCloseUpPageData[2].bg, 0x800);

            // Setup transparency for the flicket effect
            gWrittenToBLDALPHA_L = 6;
            gWrittenToBLDALPHA_H = 12;

            CUTSCENE_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            CUTSCENE_DATA.dispcnt = DCNT_OBJ | sMotherBrainCloseUpPageData[1].bg | sMotherBrainCloseUpPageData[2].bg;
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > sMotherBrainCloseUpEyeOpeningTimers[0])
            {
                // Spawn first set of bubbles
                MotherBrainCloseUpInitBubbles(0);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;
            
        case 2:
            if (CUTSCENE_DATA.timeInfo.timer > sMotherBrainCloseUpEyeOpeningTimers[1])
            {
                // Spawn second set of bubbles
                MotherBrainCloseUpInitBubbles(1);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;
            
        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > sMotherBrainCloseUpEyeOpeningTimers[2])
            {
                SoundPlay(0x22F);
                // Start eye opening animation
                update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[7], 3);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;
            
        case 4:
            // Wait for eye opening animation to end
            if (CUTSCENE_DATA.oam[7].ended)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;
            
        case 5:
            // Simply wait
            if (CUTSCENE_DATA.timeInfo.timer > sMotherBrainCloseUpEyeOpeningTimers[3])
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

    // Update bubbles
    for (i = 0; i < 6; i++)
    {
        if (CUTSCENE_DATA.oam[i].oamID != 0)
            MotherBrainCloseUpUpdateBubble(&CUTSCENE_DATA.oam[i]);
    }

    // Flicker transparency
    if (!(gFrameCounter8Bit & 7))
        gWrittenToBLDALPHA_H ^= 1;

    return FALSE;
}

/**
 * @brief 634c0 | c4 | Handles the tank view part of the cutscene
 * 
 * @return u8 FALSE
 */
u8 MotherBrainCloseUpTankView(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            SoundPlay(0x22E);

            // Start first fade, to semi visible screen
            CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt, 10, 0, 8);
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > 30)
            {
                // Start second fade, fully visible screen
                CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt, 0, 2, 1);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            // Wait for second fade to end
            if (CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_SPRITE_ENDED)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            // Wait one second
            if (CUTSCENE_DATA.timeInfo.timer > 60)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            unk_61f0c();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    return FALSE;
}

/**
 * @brief 63584 | b8 | Initializes the mother brain close up cutscene
 * 
 * @return u8 FALSE
 */
u8 MotherBrainCloseUpInit(void)
{
    unk_61f0c();
    DMATransfer(3, sMotherBrainCloseUpTankViewPAL, PALRAM_BASE, sizeof(sMotherBrainCloseUpTankViewPAL), 0x10);
    write16(PALRAM_BASE, 0);

    // Load tank view graphics
    CallLZ77UncompVRAM(sMotherBrainCloseUpTankViewGFX, VRAM_BASE + sMotherBrainCloseUpPageData[0].graphicsPage * 0x4000);
    CallLZ77UncompVRAM(sMotherBrainCloseUpTankViewTileTable, VRAM_BASE + sMotherBrainCloseUpPageData[0].tiletablePage * 0x800);

    CutsceneSetBGCNTPageData(sMotherBrainCloseUpPageData[0]);
    CutsceneReset();

    CUTSCENE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
        BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
        BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;
    gWrittenToBLDY_NonGameplay = 16;

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sMotherBrainCloseUpPageData[0].bg, 0x800);

    PlayMusic(MUSIC_ENTERING_NORFAIR_CUTSCENE, 0);
    CUTSCENE_DATA.dispcnt = sMotherBrainCloseUpPageData[0].bg;

    CUTSCENE_DATA.timeInfo.stage++;
    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;

    return FALSE;
}

/**
 * @brief 6363c | 34 | Subroutine for the mother brain close up cutscene
 * 
 * @return u8 bool, ended
 */
u8 MotherBrainCloseUpSubroutine(void)
{
    u8 ended;

    ended = sMotherBrainCloseUpSubroutineData[CUTSCENE_DATA.timeInfo.stage].pFunction();
    CutsceneUpdateBackgroundsPosition(TRUE);
    MotherBrainCloseUpProcessOAM();

    return ended;
}

/**
 * @brief 63670 | 38 | Processes the OAM
 * 
 */
void MotherBrainCloseUpProcessOAM(void)
{
    gNextOamSlot = 0;
    process_cutscene_oam(sMotherBrainCloseUpSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sMotherBrainCloseUpCutsceneOAM);
    ResetFreeOAM();
}

void MotherBrainCloseUpUpdateEye(u8 lookingAtSamus)
{
    struct CutsceneOamData* pOam;
    struct CutsceneOamData* pOam2;

    pOam = &CUTSCENE_DATA.oam[0];
    if (!lookingAtSamus)
    {
        pOam2 = &CUTSCENE_DATA.oam[7];
        pOam2->xPosition = BLOCK_SIZE * 7 + HALF_BLOCK_SIZE;
        pOam2->yPosition = BLOCK_SIZE * 5 + HALF_BLOCK_SIZE;
        pOam2->priority = sMotherBrainCloseUpPageData[2].priority;
        pOam2->unk_C_0 = 3;
        pOam2->oamID = 0;
        pOam2->idChanged = TRUE;
    }
    else
    {
        pOam->xPosition = BLOCK_SIZE * 7 + HALF_BLOCK_SIZE;
        pOam->yPosition = BLOCK_SIZE * 5 + 4;
        pOam->priority = sMotherBrainCloseUpPageData[4].priority;
        pOam->unk_C_0 = 1;
        pOam->unk_B_4 = 1;
        update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[1], 5);
        
        pOam[1].xPosition = BLOCK_SIZE * 7 + HALF_BLOCK_SIZE;
        pOam[1].yPosition = BLOCK_SIZE * 5 + 4;

        CUTSCENE_DATA.oam[1].priority = sMotherBrainCloseUpPageData[4].priority;

        CUTSCENE_DATA.oam[1].unk_C_0 = 1;
        CUTSCENE_DATA.oam[1].unk_B_4 = 1;
    }
}

void MotherBrainCloseUpUpdateBubble(struct CutsceneOamData* pOam)
{
    // https://decomp.me/scratch/14vAj

    i32 yPosition;

    pOam->yPosition -= 4;
    yPosition = (pOam->yPosition + BLOCK_SIZE * 32);
    yPosition -= gBG3VOFS_NonGameplay;

    if (yPosition < -0x90)
        pOam->idChanged = FALSE;
    else if (yPosition > 0x300)
    {
        if (!(pOam->notDrawn))
            pOam->notDrawn = TRUE;
    }
    else if (pOam->notDrawn)
        pOam->notDrawn = FALSE;
}

/**
 * @brief 6380c | 78 | Initializes all the bubbles
 * 
 * @param packId Bubble pack ID
 * @return u8 bool, couldn't initialize
 */
u8 MotherBrainCloseUpInitBubbles(u8 packId)
{
    i32 i;

    for (i = 0; i < 6; i++)
    {
        if (CUTSCENE_DATA.oam[i].idChanged)
            continue;

        CUTSCENE_DATA.oam[i].xPosition = sMotherBrainCloseUpBubblesSpawnPositions[packId][0];
        CUTSCENE_DATA.oam[i].yPosition = sMotherBrainCloseUpBubblesSpawnPositions[packId][1];

        update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[i], 1);
        CUTSCENE_DATA.oam[i].unk_C_0 = 3;
        return FALSE;
    }

    return TRUE;
}

