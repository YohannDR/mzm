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
            DMA_SET(3, sKraidRisingRisingPAL, PALRAM_BASE, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sKraidRisingRisingPAL)));
            write16(PALRAM_BASE, 0);

            CallLZ77UncompVRAM(sKraidRisingKraidRisingGfx, BGCNT_TO_VRAM_CHAR_BASE(sKraidRisingPagesData[2].graphicsPage));
            DmaTransfer(3, KRAID_RISING_EWRAM.kraidRisingTileTable, BGCNT_TO_VRAM_TILE_BASE(sKraidRisingPagesData[2].tiletablePage), 0x800, 16);

            CutsceneSetBgcntPageData(sKraidRisingPagesData[2]);
            CutsceneReset();

            for (i = 0; i < 11; i++)
            {
                CUTSCENE_DATA.oam[i + 6].xPosition = sKraidRisingPuffData[i][0];
                CUTSCENE_DATA.oam[i + 6].yPosition = sKraidRisingPuffData[i][1];
                CUTSCENE_DATA.oam[i + 6].timer = sKraidRisingPuffData[i][3];
            }

            for (i = 0; i < 6; i++)
            {
                CUTSCENE_DATA.oam[i].xPosition = sKraidRisingDebrisSpawnXPosition[i];
                CUTSCENE_DATA.oam[i].yPosition = -HALF_BLOCK_SIZE;
                CUTSCENE_DATA.oam[i].timer = MOD_AND(sRandomNumberTable[gFrameCounter8Bit + i], 128);
            }

            CUTSCENE_DATA.timeInfo.subStage++;
            CUTSCENE_DATA.timeInfo.timer = 0;
            break;

        case 1:
            CallLZ77UncompVRAM(sKraidRisingCaveBackroundGfx, BGCNT_TO_VRAM_CHAR_BASE(sKraidRisingPagesData[3].graphicsPage));
            DmaTransfer(3, KRAID_RISING_EWRAM.caveBackgroundTileTable, BGCNT_TO_VRAM_TILE_BASE(sKraidRisingPagesData[3].tiletablePage), 0x800, 16);

            CutsceneSetBgcntPageData(sKraidRisingPagesData[3]);
            CutsceneStartScreenShake(sKraidRisingScreenShakeData, sKraidRisingPagesData[2].bg | sKraidRisingPagesData[3].bg);

            CUTSCENE_DATA.bldcnt = 0;
            CUTSCENE_DATA.oam[17].xPosition = BLOCK_SIZE * 7 + HALF_BLOCK_SIZE;
            CUTSCENE_DATA.oam[17].yPosition = BLOCK_SIZE * 10;
            CUTSCENE_DATA.oam[17].priority = sKraidRisingPagesData[2].priority;

            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[17], KRAID_RISING_OAM_ID_SAMUS);
            CUTSCENE_DATA.dispcnt = sKraidRisingPagesData[2].bg | sKraidRisingPagesData[3].bg | DCNT_OBJ;

            SoundPlay(0x22D);
            CUTSCENE_DATA.timeInfo.subStage++;
            CUTSCENE_DATA.timeInfo.timer = 0;
            break;

        case 2:
            if (CUTSCENE_DATA.timeInfo.timer != 0)
                CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 3:
            if (!CutsceneCheckBackgroundScrollingActive(sKraidRisingPagesData[2].bg))
            {
                CutsceneStartBackgroundScrolling(sKraidRisingScrollingInfo, sKraidRisingPagesData[2].bg);
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.timeInfo.timer > 60 * 2)
            {
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 5:
            unk_61f0c();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    for (i = 0; i < 11; i++)
        KraidRisingUpdatePuff(&CUTSCENE_DATA.oam[i + 6], i);

    for (i = 0; i < 6; i++)
        KraidRisingUpdateDebris(&CUTSCENE_DATA.oam[i], i);

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
    u8* data;
    s32 offset;

    if (!pOam->exists)
    {
        if (pOam->timer != 0)
            pOam->timer--;
        else
        {
            // Update timer
            pOam->timer = MOD_AND(sRandomNumberTable[gFrameCounter8Bit + puffID], 16) + 1;

            // Update OAM id
            UpdateCutsceneOamDataID(pOam, sKraidRisingPuffData[puffID][2]);
        }
    }

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
        pOam->timer--;
        return;
    }

    if (!pOam->exists)
    {
        // Set spawn X (base + [0-64[)
        pOam->xPosition = sKraidRisingDebrisSpawnXPosition[debrisID] + MOD_AND(sRandomNumberTable[~LOW_BYTE(gFrameCounter8Bit + debrisID)], 64);
        
        // Start above ceiling
        pOam->yPosition = -HALF_BLOCK_SIZE;

        // Set random velocity
        pOam->unk_10 = ((gFrameCounter8Bit + debrisID) & (MOD_AND(debrisID, 2) + 3)) - 2;
        pOam->unk_18 = 0;

        // Reset anim
        UpdateCutsceneOamDataID(pOam, KRAID_RISING_OAM_ID_DEBRIS);
    }
    else
    {
        // Gradually increment velocity
        if (pOam->unk_10 < 32)
            pOam->unk_10++;

        // Apply velocity
        pOam->yPosition += pOam->unk_10;
        if (pOam->yPosition >= BLOCK_SIZE * 11 + HALF_BLOCK_SIZE)
        {
            pOam->exists = FALSE;
            // Set random timer
            pOam->timer = 1 + MOD_AND(sRandomNumberTable[LOW_BYTE(gFrameCounter8Bit + debrisID)], 16);
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
            if (CUTSCENE_DATA.timeInfo.timer > 8)
            {
                CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt, 0, 0, 16);
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > 30)
            {
                SoundPlay(0x22C);

                DmaTransfer(3, KRAID_RISING_EWRAM.barelyOpenedTileTable, BGCNT_TO_VRAM_TILE_BASE(sKraidRisingPagesData[1].tiletablePage),
                    BGCNT_VRAM_TILE_SIZE, 16);
                CutsceneSetBgcntPageData(sKraidRisingPagesData[1]);

                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.timeInfo.timer > 6)
            {
                DmaTransfer(3, KRAID_RISING_EWRAM.aLittleOpenedTileTable, BGCNT_TO_VRAM_TILE_BASE(sKraidRisingPagesData[0].tiletablePage),
                    BGCNT_VRAM_TILE_SIZE, 16);
                CutsceneSetBgcntPageData(sKraidRisingPagesData[0]);

                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > 6)
            {
                PlayMusic(MUSIC_KRAID_BATTLE_WITH_INTRO, 0);

                DmaTransfer(3, KRAID_RISING_EWRAM.openedTileTable, BGCNT_TO_VRAM_TILE_BASE(sKraidRisingPagesData[1].tiletablePage), 0x800, 16);
                CutsceneSetBgcntPageData(sKraidRisingPagesData[1]);

                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.timeInfo.timer > 60)
                CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 5:
            unk_61f0c();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    return FALSE;
}

u8 KraidRisingInit(void)
{
    u16 bg;

    unk_61f0c();
    DmaTransfer(3, sKraidRisingCloseUpPal, PALRAM_BASE, sizeof(sKraidRisingCloseUpPal), 16);
    write16(PALRAM_BASE, 0);

    CallLZ77UncompVRAM(sKraidRisingKraidCloseUpGfx, BGCNT_TO_VRAM_CHAR_BASE(sKraidRisingPagesData[0].graphicsPage));

    if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
        DmaTransfer(3, sKraidRisingSamusVariaPal, PALRAM_OBJ, sizeof(sKraidRisingSamusVariaPal), 16);
    else
        DmaTransfer(3, sKraidRisingSamusPal, PALRAM_OBJ, sizeof(sKraidRisingSamusVariaPal), 16);

    DmaTransfer(3, sKraidRisingParticlesPal, PALRAM_OBJ + 16 * 2, sizeof(sKraidRisingParticlesPal), 16);

    CallLZ77UncompVRAM(sKraidRisingOamGfx, BGCNT_TO_VRAM_CHAR_BASE(4));
    
    CallLZ77UncompVRAM(sKraidRisingKraidCloseUpEyesBarelyOpenedTileTable, KRAID_RISING_EWRAM.barelyOpenedTileTable);
    CallLZ77UncompVRAM(sKraidRisingKraidCloseUpEyesALittleOpenedTileTable, KRAID_RISING_EWRAM.aLittleOpenedTileTable);
    CallLZ77UncompVRAM(sKraidRisingKraidCloseUpEyesOpenedTileTable, KRAID_RISING_EWRAM.openedTileTable);
    CallLZ77UncompVRAM(sKraidRisingKraidRisingTileTable, KRAID_RISING_EWRAM.kraidRisingTileTable);
    CallLZ77UncompVRAM(sKraidRisingCaveBackgroundTileTable, KRAID_RISING_EWRAM.caveBackgroundTileTable);
    CallLZ77UncompVRAM(sKraidRisingKraidCloseUpEyesClosedTileTable, BGCNT_TO_VRAM_TILE_BASE(sKraidRisingPagesData[0].tiletablePage));
    
    CutsceneSetBgcntPageData(sKraidRisingPagesData[0]);
    bg = sKraidRisingPagesData[0].bg;
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, bg, BLOCK_SIZE * 32);
    CutsceneReset();

    gWrittenToBLDY_NonGameplay = 16;
    CUTSCENE_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sKraidRisingPagesData[2].bg, BLOCK_SIZE * 31 + HALF_BLOCK_SIZE);

    CUTSCENE_DATA.dispcnt = bg;
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
    KraidRisingProcessOAM();
    return ended;
}

/**
 * @brief 62b58 | 38 | Processes the OAM for the cutscene
 * 
 */
void KraidRisingProcessOAM(void)
{
    gNextOamSlot = 0;

    ProcessCutsceneOam(sKraidRisingSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sKraidRisingCutsceneOAM);
    ResetFreeOam();
}
