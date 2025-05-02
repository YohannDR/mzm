#include "cutscenes/statue_opening.h"
#include "cutscenes/cutscene_utils.h"

#include "data/shortcut_pointers.h"
#include "data/cutscenes/statue_opening_data.h"
#include "data/cutscenes/internal_statue_opening_data.h"
#include "data/sprites/boss_statues.h"
#include "data/tilesets/tilesets_set1.h"
#include "data/rooms/brinstar_rooms_data.h"

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
            if (CUTSCENE_DATA.timeInfo.timer > ONE_THIRD_SECOND)
            {
                CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt, 0, 8, 1);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(.5f))
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            // Scroll to the statues
            pPosition = CutsceneGetBgVerticalPointer(sStatueOpeningPageData[0].bg);

            if (*pPosition > NON_GAMEPLAY_START_BG_POS)
                *pPosition -= PIXEL_SIZE / 2;

            if (*pPosition <= NON_GAMEPLAY_START_BG_POS)
            {
                *pPosition = NON_GAMEPLAY_START_BG_POS;
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
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(.5f))
            {
                #ifdef DEBUG
                if (gBootDebugActive)
                {
                    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[0], STATUE_OPENING_OAM_ID_KRAID_ACTIVATING);
                    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[1], STATUE_OPENING_OAM_ID_RIDLEY_ACTIVATING);
                    SoundPlay(SOUND_STATUE_OPENING_STATUE_ACTIVATING);
                    CUTSCENE_DATA.timeInfo.subStage++;
                    CUTSCENE_DATA.timeInfo.timer = 0;
                }
                else
                #endif // DEBUG
                {
                    // Set opening animation for appropriate statue
                    if (gCurrentArea == AREA_KRAID)
                        UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[0], STATUE_OPENING_OAM_ID_KRAID_ACTIVATING);
                    else if (gCurrentArea == AREA_RIDLEY)
                        UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[1], STATUE_OPENING_OAM_ID_RIDLEY_ACTIVATING);
    
                    SoundPlay(SOUND_STATUE_OPENING_STATUE_ACTIVATING);
                    CUTSCENE_DATA.timeInfo.subStage++;
                    CUTSCENE_DATA.timeInfo.timer = 0;
                }
            }
            break;

        case 5:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(3.f))
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 6:
            CutsceneFadeScreenToBlack();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    *CutsceneGetBgVerticalPointer(sStatueOpeningPageData[1].bg) = *CutsceneGetBgVerticalPointer(sStatueOpeningPageData[0].bg);
    *CutsceneGetBgVerticalPointer(sStatueOpeningPageData[2].bg) = *CutsceneGetBgVerticalPointer(sStatueOpeningPageData[0].bg) / 2;

    #ifdef DEBUG
    CutsceneCheckSkipStage(1);
    #endif

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
    const u8* ptr;
    
    CutsceneFadeScreenToBlack();
    DmaTransfer(3, sBossStatuesPal, PALRAM_OBJ + 8 * PAL_ROW_SIZE, sizeof(sBossStatuesPal), 16);
    DmaTransfer(3, sStatueOpeningPal, PALRAM_BASE, sizeof(sStatueOpeningPal), 16);
    SET_BACKDROP_COLOR(COLOR_BLACK);

    CallLZ77UncompVram(sStatueOpeningRoomGfx, VRAM_BASE + 0x1800 + sStatueOpeningPageData[0].graphicsPage * 0x4000);

    ptr = (const u8*)sTileset_65_Bg_Gfx;
    CallLZ77UncompVram(ptr, VRAM_BASE + 0xFDE0 - C_16_2_8(ptr[2], ptr[1])); 
    CallLZ77UncompVram(sStatueOpeningRoomTileTable, BGCNT_TO_VRAM_TILE_BASE(sStatueOpeningPageData[0].tiletablePage));
    CallLZ77UncompVram(sStatueOpening_3effc8, BGCNT_TO_VRAM_TILE_BASE(sStatueOpeningPageData[1].tiletablePage));
    CallLZ77UncompVram(&sBrinstar_Bg3_9[4], BGCNT_TO_VRAM_TILE_BASE(sStatueOpeningPageData[2].tiletablePage));

    CallLZ77UncompVram(sBossStatuesGfx, VRAM_OBJ + 0x4000);
    BitFill(3, 0, BGCNT_TO_VRAM_TILE_BASE(1), 32, 32);

    CutsceneSetBgcntPageData(sStatueOpeningPageData[0]);
    CutsceneSetBgcntPageData(sStatueOpeningPageData[1]);
    CutsceneSetBgcntPageData(sStatueOpeningPageData[2]);

    CutsceneReset();

    CUTSCENE_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;
    gWrittenToBLDY_NonGameplay = BLDY_MAX_VALUE;

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sStatueOpeningPageData[0].bg, NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sStatueOpeningPageData[1].bg, NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE);

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sStatueOpeningPageData[0].bg, NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE * 6);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sStatueOpeningPageData[1].bg, NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE * 6);

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sStatueOpeningPageData[2].bg, NON_GAMEPLAY_START_BG_POS / 2 + HALF_BLOCK_SIZE);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sStatueOpeningPageData[2].bg, NON_GAMEPLAY_START_BG_POS / 2);

    CUTSCENE_DATA.oam[0].xPosition = BLOCK_SIZE * 8;
    CUTSCENE_DATA.oam[0].yPosition = BLOCK_SIZE * 7;
    CUTSCENE_DATA.oam[0].priority = 0;
    CUTSCENE_DATA.oam[0].boundBackground = 1;
    CUTSCENE_DATA.oam[0].exists = 1;

    CUTSCENE_DATA.oam[1].xPosition = BLOCK_SIZE * 8;
    CUTSCENE_DATA.oam[1].yPosition = BLOCK_SIZE * 7;
    CUTSCENE_DATA.oam[1].priority = 0;
    CUTSCENE_DATA.oam[1].boundBackground = 1;
    CUTSCENE_DATA.oam[1].exists = 1;

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
    ProcessCutsceneOam(sStatueOpeningSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sStatueOpeningOam);
    ResetFreeOam();
}
