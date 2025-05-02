#include "cutscenes/kraid_rising.h"
#include "cutscenes/cutscene_utils.h"
#include "oam.h"
#include "oam_id.h"
#include "syscall_wrappers.h"

#include "data/cutscenes/cutscenes_data.h"
#include "data/cutscenes/internal_kraid_rising_data.h"
#include "data/cutscenes/kraid_rising_data.h"
#include "data/generic_data.h"
#include "data/shortcut_pointers.h"

#include "constants/audio.h"
#include "constants/cutscene.h"
#include "constants/samus.h"

#include "structs/game_state.h"
#include "structs/display.h"
#include "structs/samus.h"

/**
 * @brief 6240c | 2ec | Handles the kraid rising part
 * 
 * @return u8 FALSE
 */
u8 KraidRisingRising(void)
{
    u32 i;

    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            // Load kraid rising palette
            DMA_SET(3, sKraidRisingRisingPal, PALRAM_BASE, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sKraidRisingRisingPal)));
            write16(PALRAM_BASE, COLOR_BLACK);

            // Load kraid rising graphics
            CallLZ77UncompVram(sKraidRisingKraidRisingGfx, BGCNT_TO_VRAM_CHAR_BASE(sKraidRisingPagesData[2].graphicsPage));

            // Load kraid rising tile table
            DmaTransfer(3, KRAID_RISING_EWRAM.kraidRisingTileTable, BGCNT_TO_VRAM_TILE_BASE(sKraidRisingPagesData[2].tiletablePage),
                sizeof(KRAID_RISING_EWRAM.kraidRisingTileTable), 16);

            // Enable kraid rising background
            CutsceneSetBgcntPageData(sKraidRisingPagesData[2]);

            // Clear data
            CutsceneReset();

            // Setup puffs
            for (i = 0; i < KRAID_RISING_PUFF_AMOUNT; i++)
            {
                CUTSCENE_DATA.oam[KRAID_RISING_DEBRIS_AMOUNT + i].xPosition = sKraidRisingPuffData[i][0];
                CUTSCENE_DATA.oam[KRAID_RISING_DEBRIS_AMOUNT + i].yPosition = sKraidRisingPuffData[i][1];
                CUTSCENE_DATA.oam[KRAID_RISING_DEBRIS_AMOUNT + i].timer = sKraidRisingPuffData[i][3];
            }

            // Setup debris
            for (i = 0; i < KRAID_RISING_DEBRIS_AMOUNT; i++)
            {
                CUTSCENE_DATA.oam[i].xPosition = sKraidRisingDebrisSpawnXPosition[i];
                CUTSCENE_DATA.oam[i].yPosition = -HALF_BLOCK_SIZE;
                CUTSCENE_DATA.oam[i].timer = MOD_AND(sRandomNumberTable[gFrameCounter8Bit + i], 128);
            }

            CUTSCENE_DATA.timeInfo.subStage++;
            CUTSCENE_DATA.timeInfo.timer = 0;
            break;

        case 1:
            // Load cave background graphics
            CallLZ77UncompVram(sKraidRisingCaveBackroundGfx, BGCNT_TO_VRAM_CHAR_BASE(sKraidRisingPagesData[3].graphicsPage));

            // Load cave background tile table
            DmaTransfer(3, KRAID_RISING_EWRAM.caveBackgroundTileTable, BGCNT_TO_VRAM_TILE_BASE(sKraidRisingPagesData[3].tiletablePage),
                sizeof(KRAID_RISING_EWRAM.caveBackgroundTileTable), 16);

            // Enable cave background
            CutsceneSetBgcntPageData(sKraidRisingPagesData[3]);

            // Start screen shake for the kraid rising and the cave background
            CutsceneStartScreenShake(sKraidRisingScreenShakeData, sKraidRisingPagesData[2].bg | sKraidRisingPagesData[3].bg);

            CUTSCENE_DATA.bldcnt = 0;

            // Samus sprite, allocate after the puffs and debris
            CUTSCENE_DATA.oam[KRAID_RISING_DEBRIS_AMOUNT + KRAID_RISING_PUFF_AMOUNT].xPosition = BLOCK_SIZE * 7 + HALF_BLOCK_SIZE;
            CUTSCENE_DATA.oam[KRAID_RISING_DEBRIS_AMOUNT + KRAID_RISING_PUFF_AMOUNT].yPosition = BLOCK_SIZE * 10;
            CUTSCENE_DATA.oam[KRAID_RISING_DEBRIS_AMOUNT + KRAID_RISING_PUFF_AMOUNT].priority = sKraidRisingPagesData[2].priority;

            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[KRAID_RISING_DEBRIS_AMOUNT + KRAID_RISING_PUFF_AMOUNT], KRAID_RISING_OAM_ID_SAMUS);

            // Enable render for kraid rising, the cave background and objects
            CUTSCENE_DATA.dispcnt = sKraidRisingPagesData[2].bg | sKraidRisingPagesData[3].bg | DCNT_OBJ;

            SoundPlay(SOUND_KRAID_RISING_SCREAMS);

            CUTSCENE_DATA.timeInfo.subStage++;
            CUTSCENE_DATA.timeInfo.timer = 0;
            break;

        case 2:
            // Useless, since the first time this code is executed the timer is 1
            if (CUTSCENE_DATA.timeInfo.timer != 0)
                CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 3:
            // Wait for scrolling to end, even though no scrolling ever happened?
            if (!CutsceneCheckBackgroundScrollingActive(sKraidRisingPagesData[2].bg))
            {
                // Start scrolling up for the kraid rising background
                CutsceneStartBackgroundScrolling(sKraidRisingScrollingInfo, sKraidRisingPagesData[2].bg);
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 4:
            // Wait 2 seconds, it should probably be better to call CutsceneCheckBackgroundScrollingActive
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(2.f))
            {
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 5:
            CutsceneFadeScreenToBlack();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    // Update puffs
    for (i = 0; i < KRAID_RISING_PUFF_AMOUNT; i++)
        KraidRisingUpdatePuff(&CUTSCENE_DATA.oam[KRAID_RISING_DEBRIS_AMOUNT + i], i);

    // Update debris
    for (i = 0; i < KRAID_RISING_DEBRIS_AMOUNT; i++)
        KraidRisingUpdateDebris(&CUTSCENE_DATA.oam[i], i);

    #if DEBUG
    CutsceneCheckSkipStage(1);
    #endif // DEBUG

    return FALSE;
}

/**
 * @brief 626f8 | 54 | Updates a puff
 * 
 * @param pOam Cutscene OAM Data Pointer
 * @param puffID Puff ID
 * @return struct CutsceneOamData* First param
 */
struct CutsceneOamData* KraidRisingUpdatePuff(struct CutsceneOamData* pOam, u8 puffID)
{
    s32 offset;

    if (pOam->exists)
    {
        // Puff already exists, nothing to do
        return;
    }

    if (pOam->timer != 0)
    {
        // Spawn delay
        APPLY_DELTA_TIME_DEC(pOam->timer);
        return;
    }

    // Set new timer
    // CONVERT_SECONDS(.25f) + 1 * DELTA_TIME
    pOam->timer = MOD_AND(sRandomNumberTable[gFrameCounter8Bit + puffID], 16) + 1 * DELTA_TIME;

    // Update OAM id
    UpdateCutsceneOamDataID(pOam, sKraidRisingPuffData[puffID][2]);

    // Implicit return
}

/**
 * @brief 6274c | c0 | Updates a debris
 * 
 * @param pOam Cutscene OAM Data Pointer
 * @param puffID Debris ID
 * @return struct CutsceneOamData* First param
 */
struct CutsceneOamData* KraidRisingUpdateDebris(struct CutsceneOamData* pOam, u8 debrisID)
{
    if (pOam->timer != 0)
    {
        // Spawn timer
        APPLY_DELTA_TIME_DEC(pOam->timer);
        return;
    }

    if (!pOam->exists)
    {
        // Initialize debris

        // Set spawn X (base + [0-64])
        pOam->xPosition = sKraidRisingDebrisSpawnXPosition[debrisID] + MOD_AND(sRandomNumberTable[~MOD_AND(gFrameCounter8Bit + debrisID, ARRAY_SIZE(sRandomNumberTable))], 64);
        
        // Start above ceiling
        pOam->yPosition = -HALF_BLOCK_SIZE;

        // Set random velocity
        pOam->yVelocity = ((gFrameCounter8Bit + debrisID) & (MOD_AND(debrisID, 2) + 3)) - 2;
        pOam->unk_18 = 0;

        // Reset anim
        UpdateCutsceneOamDataID(pOam, KRAID_RISING_OAM_ID_DEBRIS);
    }
    else
    {
        // Gradually increment velocity
        if (pOam->yVelocity < HALF_BLOCK_SIZE)
            pOam->yVelocity++;

        // Apply velocity
        pOam->yPosition += pOam->yVelocity;

        if (pOam->yPosition >= BLOCK_SIZE * 11 + HALF_BLOCK_SIZE)
        {
            // Set dead
            pOam->exists = FALSE;

            // Set random respawn timer
            pOam->timer = 1 + MOD_AND(sRandomNumberTable[MOD_AND(gFrameCounter8Bit + debrisID, ARRAY_SIZE(sRandomNumberTable))], 16);
        }
    }
}

/**
 * @brief 6280c | 188 | Handles the kraid opening his eyes part of the cutscene
 * 
 * @return u8 FALSE
 */
u8 KraidRisingOpeningEyes(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(2.f / 15))
            {
                // Start fade
                CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt, 0, 0, 16);
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(.5f))
            {
                SoundPlay(SOUND_KRAID_RISING_EYES_OPENING);

                // Load second opening eye frame
                DmaTransfer(3, KRAID_RISING_EWRAM.barelyOpenedTileTable, BGCNT_TO_VRAM_TILE_BASE(sKraidRisingPagesData[1].tiletablePage),
                    sizeof(KRAID_RISING_EWRAM.barelyOpenedTileTable), 16);

                CutsceneSetBgcntPageData(sKraidRisingPagesData[1]);

                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(.1f))
            {
                // Load third opening eye frame
                DmaTransfer(3, KRAID_RISING_EWRAM.aLittleOpenedTileTable, BGCNT_TO_VRAM_TILE_BASE(sKraidRisingPagesData[0].tiletablePage),
                    sizeof(KRAID_RISING_EWRAM.aLittleOpenedTileTable), 16);

                CutsceneSetBgcntPageData(sKraidRisingPagesData[0]);

                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(.1f))
            {
                PlayMusic(MUSIC_KRAID_BATTLE_WITH_INTRO, 0);

                // Load fourth opening eye frame
                DmaTransfer(3, KRAID_RISING_EWRAM.openedTileTable, BGCNT_TO_VRAM_TILE_BASE(sKraidRisingPagesData[1].tiletablePage),
                    sizeof(KRAID_RISING_EWRAM.openedTileTable), 16);

                CutsceneSetBgcntPageData(sKraidRisingPagesData[1]);

                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(1.f))
                CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 5:
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
 * @brief 62994 | 190 | Initializes the kraid rising cutscene
 * 
 * @return u8 
 */
u8 KraidRisingInit(void)
{
    CutsceneFadeScreenToBlack();

    // Load close up palette
    DmaTransfer(3, sKraidRisingCloseUpPal, PALRAM_BASE, sizeof(sKraidRisingCloseUpPal), 16);
    
    SET_BACKDROP_COLOR(COLOR_BLACK);

    // Load close up graphics
    CallLZ77UncompVram(sKraidRisingKraidCloseUpGfx, BGCNT_TO_VRAM_CHAR_BASE(sKraidRisingPagesData[0].graphicsPage));

    // Load samus palette based, with or without varia
    if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
        DmaTransfer(3, sKraidRisingSamusVariaPal, PALRAM_OBJ, sizeof(sKraidRisingSamusVariaPal), 16);
    else
        DmaTransfer(3, sKraidRisingSamusPal, PALRAM_OBJ, sizeof(sKraidRisingSamusPal), 16);

    // Load obj palette
    DmaTransfer(3, sKraidRisingParticlesPal, PALRAM_OBJ + sizeof(sKraidRisingSamusVariaPal), sizeof(sKraidRisingParticlesPal), 16);

    // Load obj data
    CallLZ77UncompVram(sKraidRisingOamGfx, VRAM_OBJ);

    // Setup later tile tables in EWRAM

    // Eye animation frames
    CallLZ77UncompVram(sKraidRisingKraidCloseUpEyesBarelyOpenedTileTable, KRAID_RISING_EWRAM.barelyOpenedTileTable);
    CallLZ77UncompVram(sKraidRisingKraidCloseUpEyesALittleOpenedTileTable, KRAID_RISING_EWRAM.aLittleOpenedTileTable);
    CallLZ77UncompVram(sKraidRisingKraidCloseUpEyesOpenedTileTable, KRAID_RISING_EWRAM.openedTileTable);

    CallLZ77UncompVram(sKraidRisingKraidRisingTileTable, KRAID_RISING_EWRAM.kraidRisingTileTable);
    CallLZ77UncompVram(sKraidRisingCaveBackgroundTileTable, KRAID_RISING_EWRAM.caveBackgroundTileTable);

    // First frame of the eye animation
    CallLZ77UncompVram(sKraidRisingKraidCloseUpEyesClosedTileTable, BGCNT_TO_VRAM_TILE_BASE(sKraidRisingPagesData[0].tiletablePage));

    // Setup for the eyes closed tile table
    CutsceneSetBgcntPageData(sKraidRisingPagesData[0]);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sKraidRisingPagesData[0].bg, NON_GAMEPLAY_START_BG_POS);
    CutsceneReset();

    gWrittenToBLDY_NonGameplay = BLDY_MAX_VALUE;
    CUTSCENE_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sKraidRisingPagesData[2].bg, NON_GAMEPLAY_START_BG_POS - HALF_BLOCK_SIZE);

    // Only display the background of the eyes closed
    CUTSCENE_DATA.dispcnt = sKraidRisingPagesData[0].bg;

    CUTSCENE_DATA.timeInfo.stage++;
    MACRO_CUTSCENE_NEXT_STAGE();

    return FALSE;
}

/**
 * @brief 62b24 | 37 | Kraid rising cutscene subroutine
 * 
 * @return u8 1 if ended, 0 otherwise
 */
u8 KraidRisingSubroutine(void)
{
    u8 ended;

    ended = sKraidRisingSubroutineData[CUTSCENE_DATA.timeInfo.stage].pFunction();

    CutsceneUpdateBackgroundsPosition(TRUE);
    KraidRisingProcessOam();

    return ended;
}

/**
 * @brief 62b58 | 38 | Processes the OAM for the cutscene
 * 
 */
void KraidRisingProcessOam(void)
{
    gNextOamSlot = 0;

    ProcessCutsceneOam(sKraidRisingSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sKraidRisingCutsceneOam);
    ResetFreeOam();
}
