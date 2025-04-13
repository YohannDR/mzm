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

#define OAM_BUBBLES_COUNT 6

#define ELEVATOR_REFLECTION_ACTION_ACTIVE 1

#define OAM_SLOT_ELEVATOR_ANIMATION 0
#define OAM_SLOT_EYE_OPENING (OAM_BUBBLES_COUNT + 1)

#define OAM_SLOT_EYE_PUPIL 1

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
            DmaTransfer(3, sMotherBrainCloseUpBackgroundPal, PALRAM_BASE, sizeof(sMotherBrainCloseUpBackgroundPal), 16);
            SET_BACKDROP_COLOR(COLOR_BLACK);

            // Load samus palette (varia or power suit)
            if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
            {
                DmaTransfer(3, sMotherBrainCloseUpSamusVariaPal, PALRAM_BASE + sizeof(sMotherBrainCloseUpBackgroundPal),
                    sizeof(sMotherBrainCloseUpSamusVariaPal), 16);
            }
            else
            {
                DmaTransfer(3, sMotherBrainCloseUpSamusPal, PALRAM_BASE + sizeof(sMotherBrainCloseUpBackgroundPal),
                    sizeof(sMotherBrainCloseUpSamusPal), 16);
            }

            // Load samus graphics
            CallLZ77UncompVram(sMotherBrainCloseUpSamusGfx, BGCNT_TO_VRAM_CHAR_BASE(sMotherBrainCloseUpPageData[4].graphicsPage));
            CallLZ77UncompVram(sMotherBrainCloseUpBackgroundTileTable, BGCNT_TO_VRAM_TILE_BASE(sMotherBrainCloseUpPageData[3].tiletablePage));
            CallLZ77UncompVram(sMotherBrainCloseUpSamusTileTable, BGCNT_TO_VRAM_TILE_BASE(sMotherBrainCloseUpPageData[4].tiletablePage));

            // Load big eye graphics
            DmaTransfer(3, sMotherBrainCloseUpBigEyePal, PALRAM_OBJ, sizeof(sMotherBrainCloseUpBigEyePal), 16);
            CallLZ77UncompVram(sMotherBrainCloseUpBigEyeGfx, VRAM_OBJ);

            CutsceneSetBgcntPageData(sMotherBrainCloseUpPageData[4]);
            CutsceneSetBgcntPageData(sMotherBrainCloseUpPageData[3]);

            CutsceneReset();

            // Update eye
            MotherBrainCloseUpUpdateEye(TRUE);

            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            CallLZ77UncompVram(sMotherBrainCloseUpBackgroundGfx, BGCNT_TO_VRAM_CHAR_BASE(sMotherBrainCloseUpPageData[3].graphicsPage));

            // Start small fade on eye
            CutsceneStartBackgroundEffect(BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET, 12, 12, 8, 1);

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
                CUTSCENE_DATA.oam[OAM_SLOT_ELEVATOR_ANIMATION].actions = ELEVATOR_REFLECTION_ACTION_ACTIVE;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > sMotherBrainCloseUpLookingAtSamusTimers[0])
            {
                SoundPlay(SOUND_MOTHER_BRAIN_CLOSE_UP_EYE_FOCUSING);

                // Set eye focusing animation
                UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[OAM_SLOT_EYE_PUPIL], MOTHER_BRAIN_CLOSE_UP_OAM_ID_EYE_FOCUSING);
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
            CutsceneFadeScreenToBlack();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    MotherBrainCloseUpUpdateElevatorReflection(&CUTSCENE_DATA.oam[OAM_SLOT_ELEVATOR_ANIMATION]);

    #ifdef DEBUG
    CutsceneCheckSkipStage(1);
    #endif // DEBUG

    return FALSE;
}

/**
 * @brief 6323c | 48 | Updates the elevator reflection object
 * 
 * @param pOam Cutscene OAM data pointer
 */
void MotherBrainCloseUpUpdateElevatorReflection(struct CutsceneOamData* pOam)
{
    if (pOam->actions == CUTSCENE_OAM_ACTION_NONE)
        return;

    if (pOam->actions == ELEVATOR_REFLECTION_ACTION_ACTIVE)
    {
        // Set cooldown
        pOam->timer = CONVERT_SECONDS(1.f);
        pOam->actions++;
        return;
    }

    if (pOam->timer != 0)
    {
        APPLY_DELTA_TIME_DEC(pOam->timer);
        return;
    }

    // Set cooldown
    pOam->timer = CONVERT_SECONDS(1.5f);

    // Set the elevator animation
    UpdateCutsceneOamDataID(pOam, MOTHER_BRAIN_CLOSE_UP_OAM_ID_ELEVATOR_ANIMATION);

    // Check for elevator animation limit
    pOam->actions++;
    if (pOam->actions > ELEVATOR_REFLECTION_ACTION_ACTIVE + 5)
    {
        // Stop animation
        pOam->actions = CUTSCENE_OAM_ACTION_NONE;
    }
}

/**
 * @brief 63284 | 23c | Handles the eye opening part
 * 
 * @return u8 FALSE
 */
u8 MotherBrainCloseUpEyeOpening(void)
{
    s32 i;

    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            DmaTransfer(3, sMotherBrainCloseUpPal, PALRAM_BASE, sizeof(sMotherBrainCloseUpPal), 16);
            SET_BACKDROP_COLOR(COLOR_BLACK);

            // Load mother brain close up graphics
            CallLZ77UncompVram(sMotherBrainCloseUpMotherBrainGfx, BGCNT_TO_VRAM_CHAR_BASE(sMotherBrainCloseUpPageData[2].graphicsPage));
            CallLZ77UncompVram(sMotherBrainCloseUpMotherBrainTileTable, BGCNT_TO_VRAM_TILE_BASE(sMotherBrainCloseUpPageData[2].tiletablePage));

            // Load glass tile table
            CallLZ77UncompVram(sMotherBrainCloseUpGlassTileTable, BGCNT_TO_VRAM_TILE_BASE(sMotherBrainCloseUpPageData[1].tiletablePage));

            // Load eye graphics
            DmaTransfer(3, sMotherBrainCloseUpEyePal, PALRAM_OBJ, sizeof(sMotherBrainCloseUpEyePal), 16);
            CallLZ77UncompVram(sMotherBrainCloseUpEyeGfx, VRAM_OBJ);

            CutsceneSetBgcntPageData(sMotherBrainCloseUpPageData[2]);
            CutsceneSetBgcntPageData(sMotherBrainCloseUpPageData[1]);
            CutsceneReset();

            // Initialize eye
            MotherBrainCloseUpUpdateEye(FALSE);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sMotherBrainCloseUpPageData[2].bg, NON_GAMEPLAY_START_BG_POS);

            // Setup transparency for the flicket effect
            gWrittenToBLDALPHA_L = 6;
            gWrittenToBLDALPHA_H = 12;

            // Setup blending between background 2 (the white lines) and the rest, used for the transparency flicker
            CUTSCENE_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            // Enable objects and both backgrounds
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
                SoundPlay(SOUND_MOTHER_BRAIN_CLOSE_UP_EYE_OPENING);
                // Start eye opening animation
                UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[7], MOTHER_BRAIN_CLOSE_UP_OAM_ID_EYE_OPENING);
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
            CutsceneFadeScreenToBlack();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    // Update bubbles
    for (i = 0; i < OAM_BUBBLES_COUNT; i++)
    {
        if (CUTSCENE_DATA.oam[i].oamID != 0)
            MotherBrainCloseUpUpdateBubble(&CUTSCENE_DATA.oam[i]);
    }

    // Flicker transparency
    if (MOD_AND(gFrameCounter8Bit, 8) == 0)
        gWrittenToBLDALPHA_H ^= 1;

    #ifdef DEBUG
    CutsceneCheckSkipStage(1);
    #endif // DEBUG

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
            SoundPlay(SOUND_MOTHER_BRAIN_CLOSE_UP_BUBBLES);

            // Start first fade, to semi visible screen
            CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt, 10, 0, 8);
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(.5f))
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
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(1.f))
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
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
 * @brief 63584 | b8 | Initializes the mother brain close up cutscene
 * 
 * @return u8 FALSE
 */
u8 MotherBrainCloseUpInit(void)
{
    CutsceneFadeScreenToBlack();

    // Load tank view palette
    DmaTransfer(3, sMotherBrainCloseUpTankViewPal, PALRAM_BASE, sizeof(sMotherBrainCloseUpTankViewPal), 16);
    SET_BACKDROP_COLOR(COLOR_BLACK);

    // Load tank view graphics
    CallLZ77UncompVram(sMotherBrainCloseUpTankViewGfx, BGCNT_TO_VRAM_CHAR_BASE(sMotherBrainCloseUpPageData[0].graphicsPage));
    CallLZ77UncompVram(sMotherBrainCloseUpTankViewTileTable, BGCNT_TO_VRAM_TILE_BASE(sMotherBrainCloseUpPageData[0].tiletablePage));

    // Setup tank view background
    CutsceneSetBgcntPageData(sMotherBrainCloseUpPageData[0]);
    CutsceneReset();

    // Setup full screen fade in
    CUTSCENE_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;
    gWrittenToBLDY_NonGameplay = BLDY_MAX_VALUE;

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sMotherBrainCloseUpPageData[0].bg, NON_GAMEPLAY_START_BG_POS);

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
    ProcessCutsceneOam(sMotherBrainCloseUpSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sMotherBrainCloseUpCutsceneOam);
    ResetFreeOam();
}

/**
 * @brief 636a8 | 108 | Updates the eye OAM object
 * 
 * @param lookingAtSamus bool, looking at samus
 */
void MotherBrainCloseUpUpdateEye(u8 lookingAtSamus)
{
    struct CutsceneOamData* pOam;
    struct CutsceneOamData* pEye;

    pOam = CUTSCENE_DATA.oam;
    
    if (!lookingAtSamus)
    {
        // Setup eye opening
        pEye = &CUTSCENE_DATA.oam[OAM_SLOT_EYE_OPENING];

        // Place at the center of the screen
        pEye->xPosition = SCREEN_SIZE_X_SUB_PIXEL / 2;
        pEye->yPosition = SCREEN_SIZE_Y_SUB_PIXEL / 2 + HALF_BLOCK_SIZE;

        pEye->priority = sMotherBrainCloseUpPageData[2].priority;
        pEye->boundBackground = 3;
        pEye->oamID = 0;
        pEye->exists = TRUE;
    }
    else
    {
        // Setup eye contour
        // Place at the center of the screen
        pOam->xPosition = SCREEN_SIZE_X_SUB_PIXEL / 2;
        pOam->yPosition = SCREEN_SIZE_Y_SUB_PIXEL / 2 + PIXEL_SIZE;

        pOam->priority = sMotherBrainCloseUpPageData[4].priority;
        pOam->boundBackground = 1;
        pOam->objMode = OAM_OBJ_MODE_SEMI_TRANSPARENT;

        // Setup eye pupil
        UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[OAM_SLOT_EYE_PUPIL], MOTHER_BRAIN_CLOSE_UP_OAM_ID_EYE_OPENED);
        
        // Place at the center of the screen
        pOam[OAM_SLOT_EYE_PUPIL].xPosition = SCREEN_SIZE_X_SUB_PIXEL / 2;
        pOam[OAM_SLOT_EYE_PUPIL].yPosition = SCREEN_SIZE_Y_SUB_PIXEL / 2 + PIXEL_SIZE;

        pOam[OAM_SLOT_EYE_PUPIL].priority = sMotherBrainCloseUpPageData[4].priority;

        pOam[OAM_SLOT_EYE_PUPIL].boundBackground = 1;
        pOam[OAM_SLOT_EYE_PUPIL].objMode = OAM_OBJ_MODE_SEMI_TRANSPARENT;
    }
}

/**
 * @brief 637b0 | 5c | Updates a bubble
 * 
 * @param pOam Cutscene oam data pointer
 */
void MotherBrainCloseUpUpdateBubble(struct CutsceneOamData* pOam)
{
    s32 yPosition;
    s32 convertedY;

    // Move vertically
    pOam->yPosition -= PIXEL_SIZE;

    // Convert position to to have 0 Y be the top of background 3
    yPosition = pOam->yPosition + NON_GAMEPLAY_START_BG_POS;
    convertedY = yPosition - gBg3VOFS_NonGameplay;

    // Check above screen
    if (convertedY < -(BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE))
    {
        // Kill
        pOam->exists = FALSE;
        return;
    }

    // Screen overflow check?
    if (convertedY > -SCREEN_SIZE_Y_SUB_PIXEL * 2 + NON_GAMEPLAY_START_BG_POS)
    {
        if (!(pOam->notDrawn))
            pOam->notDrawn = TRUE;
    }
    else
    {
        if (pOam->notDrawn)
            pOam->notDrawn = FALSE;
    }
}

/**
 * @brief 6380c | 78 | Initializes all the bubbles
 * 
 * @param packId Bubble pack ID
 * @return u8 bool, couldn't initialize
 */
u8 MotherBrainCloseUpInitBubbles(u8 packId)
{
    s32 i;

    for (i = 0; i < OAM_BUBBLES_COUNT; i++)
    {
        if (CUTSCENE_DATA.oam[i].exists)
            continue;

        CUTSCENE_DATA.oam[i].xPosition = sMotherBrainCloseUpBubblesSpawnPositions[packId][0];
        CUTSCENE_DATA.oam[i].yPosition = sMotherBrainCloseUpBubblesSpawnPositions[packId][1];

        UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[i], MOTHER_BRAIN_CLOSE_UP_OAM_ID_BUBBLE);
        CUTSCENE_DATA.oam[i].boundBackground = 3;

        return FALSE;
    }

    return TRUE;
}

