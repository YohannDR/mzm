#include "cutscenes/kraid_rising.h"
#include "oam.h"
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

u8 KraidRisingRising(void)
{
    // https://decomp.me/scratch/DHiok

    u32 i;

    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            dma_set(3, sKraidRisingRisingPAL, PALRAM_BASE, DMA_ENABLE << 16 | 0x70);
            write16(PALRAM_BASE, 0);

            CallLZ77UncompVRAM(sKraidRisingKraidRisingGFX, VRAM_BASE + sKraidRisingPagesData[2].graphicsPage * 0x4000);
            DMATransfer(3, sEwramPointer + 0x2800, VRAM_BASE + sKraidRisingPagesData[2].tiletablePage * 0x800, 0x800, 0x10);

            CutsceneSetBGCNTPageData(sKraidRisingPagesData[2]);
            CutsceneReset();

            for (i = 0; i < 11; i++)
            {
                CUTSCENE_DATA.oam[i + 6].xPosition = sKraidRisingPuffData[i].xPosition;
                CUTSCENE_DATA.oam[i + 6].yPosition = sKraidRisingPuffData[i].yPosition;
                CUTSCENE_DATA.oam[i + 6].timer = sKraidRisingPuffData[i].timer;
            }

            for (i = 0; i < 6; i++)
            {
                CUTSCENE_DATA.oam[i].xPosition = sKraidRisingDebrisSpawnXPosition[i];
                CUTSCENE_DATA.oam[i].yPosition = -HALF_BLOCK_SIZE;
                CUTSCENE_DATA.oam[i].timer = sRandomNumberTable[gFrameCounter8Bit + i] & 0x7F;
            }

            CUTSCENE_DATA.timeInfo.subStage++;
            CUTSCENE_DATA.timeInfo.timer = 0;
            break;

        case 1:
            CallLZ77UncompVRAM(sKraidRisingCaveBackroundGFX, VRAM_BASE + sKraidRisingPagesData[3].graphicsPage * 0x4000);
            DMATransfer(3, sEwramPointer + 0x3000, VRAM_BASE + sKraidRisingPagesData[3].tiletablePage * 0x800, 0x800, 0x10);

            CutsceneSetBGCNTPageData(sKraidRisingPagesData[3]);
            CutsceneStartScreenShake(sKraidRisingScreenShakeData, sKraidRisingPagesData[2].bg | sKraidRisingPagesData[3].bg);

            CUTSCENE_DATA.bldcnt = 0;
            CUTSCENE_DATA.oam[17].xPosition = BLOCK_SIZE * 7 + HALF_BLOCK_SIZE;
            CUTSCENE_DATA.oam[17].yPosition = BLOCK_SIZE * 10;
            CUTSCENE_DATA.oam[17].priority = sKraidRisingPagesData[2].priority;

            update_cutscene_oam_data_id(CUTSCENE_DATA.oam + 17, KRAID_RISING_OAM_ID_SAMUS);
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
            if (CUTSCENE_DATA.timeInfo.timer > 0x78)
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
        KraidRisingUpdatePuff(&CUTSCENE_DATA.oam[i], i);

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
    i32 offset;

    if (!pOam->idChanged)
    {
        if (pOam->timer != 0)
            pOam->timer--;
        else
        {
            // Update timer
            pOam->timer = (sRandomNumberTable[gFrameCounter8Bit + puffID] & 0xF) + 1;

            // Why
            data = (u8*)(sKraidRisingPuffData);
            offset = puffID * 8;

            // OAM ID field
            data += 4;

            // Reset animation
            update_cutscene_oam_data_id(pOam, data[offset]); // Undefined
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
        pOam->timer--;
    else
    {
        if (!pOam->idChanged)
        {
            // Set spawn X (base + [0-0x3F])
            pOam->xPosition = sKraidRisingDebrisSpawnXPosition[debrisID] + (sRandomNumberTable[~((gFrameCounter8Bit + debrisID) & 0xFF)] & 0x3F);
            
            // Start above ceiling
            pOam->yPosition = -HALF_BLOCK_SIZE;

            // Set random velocity
            pOam->unk_10 = ((gFrameCounter8Bit + debrisID) & ((debrisID & 1) + 3)) - 2;
            pOam->unk_18 = 0;

            // Reset anim
            update_cutscene_oam_data_id(pOam, KRAID_RISING_OAM_ID_DEBRIS);
        }
        else
        {
            // Gradually increment velocity
            if (pOam->unk_10 < 32)
                pOam->unk_10++;

            // Apply velocity
            pOam->yPosition += pOam->unk_10;
            if (pOam->yPosition > 0x2DF)
            {
                pOam->idChanged = FALSE;
                // Set random timer
                pOam->timer = (sRandomNumberTable[(gFrameCounter8Bit + debrisID) & 0xFF] & 0xF) + 1;
            }
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
            if (CUTSCENE_DATA.timeInfo.timer > 0x1E)
            {
                SoundPlay(0x22C);

                DMATransfer(3, sEwramPointer + 0x1000, VRAM_BASE + sKraidRisingPagesData[1].tiletablePage * 0x800, 0x800, 0x10);
                CutsceneSetBGCNTPageData(sKraidRisingPagesData[1]);

                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.timeInfo.timer > 6)
            {
                DMATransfer(3, sEwramPointer + 0x1800, VRAM_BASE + sKraidRisingPagesData[0].tiletablePage * 0x800, 0x800, 0x10);
                CutsceneSetBGCNTPageData(sKraidRisingPagesData[0]);

                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > 6)
            {
                PlayMusic(MUSIC_KRAID_BATTLE_WITH_INTRO, 0);

                DMATransfer(3, sEwramPointer + 0x2000, VRAM_BASE + sKraidRisingPagesData[1].tiletablePage * 0x800, 0x800, 0x10);
                CutsceneSetBGCNTPageData(sKraidRisingPagesData[1]);

                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.timeInfo.timer > 0x3C)
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
    DMATransfer(3, sKraidRisingCloseUpPAL, PALRAM_BASE, 0xA0, 0x10);
    write16(PALRAM_BASE, 0);
    CallLZ77UncompVRAM(sKraidRisingKraidCloseUpGFX, VRAM_BASE + sKraidRisingPagesData[0].graphicsPage * 0x4000);

    if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
        DMATransfer(3, sKraidRisingSamusVariaPAL, PALRAM_BASE + 0x200, 0x20, 0x10);
    else
        DMATransfer(3, sKraidRisingSamusPAL, PALRAM_BASE + 0x200, 0x20, 0x10);

    DMATransfer(3, sKraidRisingParticlesPAL, PALRAM_BASE + 0x220, 0x20, 0x10);

    CallLZ77UncompVRAM(sKraidRisingOAMGFX, VRAM_BASE + 0x10000);
    
    CallLZ77UncompVRAM(sKraidRisingKraidCloseUpEyesBarelyOpenedTileTable, sEwramPointer + 0x1000);
    CallLZ77UncompVRAM(sKraidRisingKraidCloseUpEyesALittleOpenedTileTable, sEwramPointer + 0x1800);
    CallLZ77UncompVRAM(sKraidRisingKraidCloseUpEyesOpenedTileTable, sEwramPointer + 0x2000);
    CallLZ77UncompVRAM(sKraidRisingKraidRisingTileTable, sEwramPointer + 0x2800);
    CallLZ77UncompVRAM(sKraidRisingCaveBackgroundTileTable, sEwramPointer + 0x3000);
    CallLZ77UncompVRAM(sKraidRisingKraidCloseUpEyesClosedTileTable, VRAM_BASE + sKraidRisingPagesData[0].tiletablePage * 0x800);
    
    CutsceneSetBGCNTPageData(sKraidRisingPagesData[0]);
    bg = sKraidRisingPagesData[0].bg;
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, bg, 0x800);
    CutsceneReset();

    gWrittenToBLDY_NonGameplay = 0x10;
    CUTSCENE_DATA.bldcnt = 0xFF;

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sKraidRisingPagesData[2].bg, 0x7E0);

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

    process_cutscene_oam(sKraidRisingSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sKraidRisingCutsceneOAM); // Undefined
    ResetFreeOAM();
}
