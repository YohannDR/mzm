#include "cutscenes/statue_opening.h"
#include "cutscenes/cutscene_utils.h"

#include "data/shortcut_pointers.h"
#include "data/cutscenes/statue_opening_data.h"
#include "data/cutscenes/internal_statue_opening_data.h"
#include "data/sprites/boss_statues.h"

#include "constants/audio.h"
#include "constants/connection.h"
#include "constants/cutscene.h"
#include "constants/event.h"

#include "structs/connection.h"
#include "structs/display.h"

/**
 * @brief 66c00 | 164 | Handles the statue opening animation
 * 
 * @return u8 
 */
u8 StatueOpeningOpening(void)
{
    u16* pPosition;

    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            if (CUTSCENE_DATA.timeInfo.timer > 20)
            {
                CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt, 0, 8, 1);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > 30)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            // Scroll to the statues
            pPosition = CutsceneGetBGVOFSPointer(sStatueOpeningPageData[0].bg);

            if (*pPosition > BLOCK_SIZE * 32)
                (*pPosition) -= 2;

            if (*pPosition <= BLOCK_SIZE * 32)
            {
                *pPosition = BLOCK_SIZE * 32;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            // Wait for effect to finish
            if (CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_SPRITE_ENDED)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.timeInfo.timer > 30)
            {
                // Set opening animation for appropriate statue
                if (gCurrentArea == AREA_KRAID)
                    update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[0], STATUE_OPENING_OAM_ID_KRAID_ACTIVATING);
                else if (gCurrentArea == AREA_RIDLEY)
                    update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[1], STATUE_OPENING_OAM_ID_RIDLEY_ACTIVATING);

                SoundPlay(0x231);
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 5:
            if (CUTSCENE_DATA.timeInfo.timer > 60 * 3)
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

    *CutsceneGetBGVOFSPointer(sStatueOpeningPageData[1].bg) = *CutsceneGetBGVOFSPointer(sStatueOpeningPageData[0].bg);
    *CutsceneGetBGVOFSPointer(sStatueOpeningPageData[2].bg) = *CutsceneGetBGVOFSPointer(sStatueOpeningPageData[0].bg) / 2;

    return FALSE;
}

/**
 * @brief 66d64 | 2b0 | Initializes the statue opening cutscene
 * 
 * @return u8 FALSE
 */
u8 StatueOpeningInit(void)
{
    u8 oamId;
    u8* ptr;
    
    unk_61f0c();
    DMATransfer(3, sBossStatuesPAL, PALRAM_BASE + 0x300, sizeof(sBossStatuesPAL), 0x10);
    DMATransfer(3, sStatueOpeningPAL, PALRAM_BASE, sizeof(sStatueOpeningPAL), 0x10);
    write16(PALRAM_BASE, 0);

    CallLZ77UncompVRAM(sStatueOpeningRoomGFX, VRAM_BASE + 0x1800 + sStatueOpeningPageData[0].graphicsPage * 0x4000);

    // TODO : TIleset 65 Background GFX
    ptr = (u8*)0x85fe4c8;
    CallLZ77UncompVRAM(ptr, VRAM_BASE + 0xFDE0 - (ptr[2] << 8 | ptr[1])); 
    CallLZ77UncompVRAM(sStatueOpeningRoomTileTable, VRAM_BASE + sStatueOpeningPageData[0].tiletablePage * 0x800);
    CallLZ77UncompVRAM(sStatueOpening_3effc8, VRAM_BASE + sStatueOpeningPageData[1].tiletablePage * 0x800);
    // TODO : Brinstar Room 10 BG3 tiletable
    CallLZ77UncompVRAM(0x861ac50, VRAM_BASE + sStatueOpeningPageData[2].tiletablePage * 0x800);

    CallLZ77UncompVRAM(sBossStatuesGFX, VRAM_BASE + 0x14000);
    BitFill(3, 0, VRAM_BASE + 0x800, 0x20, 0x20);

    CutsceneSetBGCNTPageData(sStatueOpeningPageData[0]);
    CutsceneSetBGCNTPageData(sStatueOpeningPageData[1]);
    CutsceneSetBGCNTPageData(sStatueOpeningPageData[2]);

    CutsceneReset();

    CUTSCENE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
        BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_BACKDROP_FIRST_TARGET_PIXEL |
        BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;
    gWrittenToBLDY_NonGameplay = 16;

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sStatueOpeningPageData[0].bg, 0x840);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sStatueOpeningPageData[1].bg, 0x840);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sStatueOpeningPageData[0].bg, 0x980);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sStatueOpeningPageData[1].bg, 0x980);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sStatueOpeningPageData[2].bg, 0x420);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sStatueOpeningPageData[2].bg, 0x400);

    CUTSCENE_DATA.oam[0].xPosition = BLOCK_SIZE * 8;
    CUTSCENE_DATA.oam[0].yPosition = BLOCK_SIZE * 7;
    CUTSCENE_DATA.oam[0].priority = 0;
    CUTSCENE_DATA.oam[0].unk_C_0 = 1;
    CUTSCENE_DATA.oam[0].idChanged = 1;

    CUTSCENE_DATA.oam[1].xPosition = BLOCK_SIZE * 8;
    CUTSCENE_DATA.oam[1].yPosition = BLOCK_SIZE * 7;
    CUTSCENE_DATA.oam[1].priority = 0;
    CUTSCENE_DATA.oam[1].unk_C_0 = 1;
    CUTSCENE_DATA.oam[1].idChanged = 1;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_STATUE_OPENED))
        oamId = STATUE_OPENING_OAM_ID_KRAID_OPENED;
    else
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_KILLED))
            oamId = STATUE_OPENING_OAM_ID_KRAID_ACTIVATED;
        else
            oamId = STATUE_OPENING_OAM_ID_KRAID_IDLE;

        if (gCurrentArea == AREA_KRAID)
            oamId = STATUE_OPENING_OAM_ID_KRAID_IDLE;
    }
    CUTSCENE_DATA.oam[0].oamID = oamId;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_STATUE_OPENED))
       oamId = STATUE_OPENING_OAM_ID_RIDLEY_OPENED;
    else
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_KILLED))
           oamId = STATUE_OPENING_OAM_ID_RIDLEY_ACTIVATED;
        else
           oamId = STATUE_OPENING_OAM_ID_RIDLEY_IDLE;

        if (gCurrentArea == AREA_RIDLEY)
           oamId = STATUE_OPENING_OAM_ID_RIDLEY_IDLE;
    }
    CUTSCENE_DATA.oam[1].oamID = oamId;

    CUTSCENE_DATA.dispcnt = DCNT_OBJ | sStatueOpeningPageData[0].bg | sStatueOpeningPageData[1].bg | sStatueOpeningPageData[2].bg;

    CUTSCENE_DATA.timeInfo.stage++;
    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;

    return FALSE;
}

/**
 * @brief 67014 | 34 | Subroutine for the statue opening cutscene
 * 
 * @return u8 bool, ended
 */
u8 StatueOpeningSubroutine(void)
{
    u8 ended;

    ended = sStatueOpeningSubroutineData[CUTSCENE_DATA.timeInfo.stage].pFunction();

    CutsceneUpdateBackgroundsPosition(TRUE);
    StatueOpeningProcessOAM();

    return ended;
}

/**
 * @brief 67048 | 38 | Processes the OAM for the cutscene
 * 
 */
void StatueOpeningProcessOAM(void)
{
    gNextOamSlot = 0;
    process_cutscene_oam(sStatueOpeningSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sStatueOpeningOam);
    ResetFreeOAM();
}
