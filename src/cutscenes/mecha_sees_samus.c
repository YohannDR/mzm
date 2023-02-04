#include "cutscenes/mecha_sees_samus.h"
#include "cutscenes/cutscene_utils.h"
#include "syscall_wrappers.h"

#include "data/cutscenes/cutscenes_data.h"
#include "data/cutscenes/internal_mecha_sees_samus_data.h"
#include "data/cutscenes/mecha_sees_samus_data.h"
#include "data/shortcut_pointers.h"

#include "constants/cutscene.h"

u8 MechaRidleySeesSamusEyeOpen(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            if (unk_61f44())
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > 30)
            {
                SoundPlay(0x293);
                update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[0], 2);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            if (!CUTSCENE_DATA.oam[0].idChanged)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > 4)
            {
                SoundPlay(0x294);
                update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[1], 4);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.oam[1].ended)
            {
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
            unk_61f0c();
            {
                CUTSCENE_DATA.timeInfo.stage++;
                MACRO_CUTSCENE_NEXT_STAGE();
            }
    }

    return FALSE;
}

/**
 * @brief 65a24 | 148 | Initializes the mecha ridley sees Samus cutscene
 * 
 * @return u8 FALSE
 */
u8 MechaRidleySeesSamusInit(void)
{
    u16 bg;
    u32 priority;

    unk_61f0c();
    DMATransfer(3, sMechaSeesSamusPAL, PALRAM_BASE, sizeof(sMechaSeesSamusPAL), 0x10);
    DMATransfer(3, PALRAM_BASE, PALRAM_BASE + 0x200, 0x200, 0x20);

    write16(PALRAM_BASE, 0);

    CallLZ77UncompVRAM(sMechaSeesSamusMetalGFX, VRAM_BASE + sMechaRidleySeesSamusPagesData[0].graphicsPage * 0x4000);
    CallLZ77UncompVRAM(sMechaSeesSamusCoverMetalTileTable, VRAM_BASE + sMechaRidleySeesSamusPagesData[0].tiletablePage * 0x800);
    CallLZ77UncompVRAM(sMechaSeesSamusCoverEyeGFX, VRAM_BASE + 0x10000);

    CutsceneSetBGCNTPageData(sMechaRidleySeesSamusPagesData[0]);

    bg = sMechaRidleySeesSamusPagesData[0].bg;
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, bg, 0x800);
    CutsceneReset();

    CUTSCENE_DATA.oam[0].xPosition = BLOCK_SIZE * 7 + BLOCK_SIZE / 2;
    CUTSCENE_DATA.oam[0].yPosition = BLOCK_SIZE * 5;
    priority = sMechaRidleySeesSamusPagesData[0].priority;
    CUTSCENE_DATA.oam[0].priority = priority;
    update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[0], 1);

    CUTSCENE_DATA.oam[1].xPosition = BLOCK_SIZE * 7 + BLOCK_SIZE / 2;
    CUTSCENE_DATA.oam[1].yPosition = BLOCK_SIZE * 5;
    CUTSCENE_DATA.oam[1].priority = priority + 1;
    update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[1], 3);

    unk_61fa0(2);

    CUTSCENE_DATA.dispcnt = bg | DCNT_OBJ;
    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;
    CUTSCENE_DATA.timeInfo.stage++;

    return FALSE;
}

/**
 * @brief 65b6c | 34 | Mecha ridley sees Samus cutscene subroutine
 * 
 * @return u8 1 if ended, 0 otherwise
 */
u8 MechaRidleySeesSamusSubroutine(void)
{
    u8 ended;

    ended = sMechaSeesSamusSubroutineData[CUTSCENE_DATA.timeInfo.stage].pFunction();
    CutsceneUpdateBackgroundsPosition(TRUE);
    MechaRidleySeesSamusProcessOAM();

    return ended;
}

/**
 * @brief 65ba0 | 38 | Processes the OAM for the cutscene
 * 
 */
void MechaRidleySeesSamusProcessOAM(void)
{
    gNextOamSlot = 0;
    process_cutscene_oam(sMechaSeesSamusSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sMechaSeesSamusCutsceneOAM); // Undefined
    ResetFreeOAM();
}
