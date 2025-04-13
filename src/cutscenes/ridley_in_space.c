#include "cutscenes/ridley_in_space.h"
#include "cutscenes/cutscene_utils.h"
#include "oam_id.h"

#include "data/generic_data.h"
#include "data/shortcut_pointers.h"
#include "data/cutscenes/cutscenes_data.h"
#include "data/cutscenes/ridley_in_space_data.h"
#include "data/cutscenes/internal_ridley_in_space_data.h"

#include "constants/audio.h"
#include "constants/cutscene.h"

#include "structs/display.h"
#include "structs/game_state.h"

#define SHIP_ACTION_MOVE_HORIZONTALLY 1
#define SHIP_ACTION_MOVE_VERTICALLY 2

#define MOTHER_SHIP_ACTION_MOVE_HORIZONTALLY 1
#define MOTHER_SHIP_ACTION_MOVE_VERTICALLY 2
#define MOTHER_SHIP_ACTION_ZOOM_MOVE 4
#define MOTHER_SHIP_ACTION_ZOOM_SCALE 8
#define MOTHER_SHIP_ACTION_MOVE (MOTHER_SHIP_ACTION_MOVE_HORIZONTALLY | MOTHER_SHIP_ACTION_MOVE_VERTICALLY)
#define MOTHER_SHIP_ACTION_ZOOM (MOTHER_SHIP_ACTION_ZOOM_MOVE | MOTHER_SHIP_ACTION_ZOOM_SCALE)

#define PARTICLE_ACTION_MOVE 1

#define SHIP_MAX_X BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE

/**
 * @brief 63884 | 298 | Handles the ship leaving part
 * 
 * @return u8 FALSE
 */
u8 RidleyInSpaceShipLeaving(void)
{
    s32 i;

    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            // Load space background palette
            DmaTransfer(3, sRidleyInSpaceSpaceBackgroundPal, PALRAM_BASE, sizeof(sRidleyInSpaceSpaceBackgroundPal), 16);
            SET_BACKDROP_COLOR(COLOR_BLACK);

            // Load space background graphics
            CallLZ77UncompVram(sRidleyInSpaceSpaceBackgroundGfx, BGCNT_TO_VRAM_CHAR_BASE(sRidleyInSpacePageData[0].graphicsPage));
            CallLZ77UncompVram(sRidleyInSpaceSpaceBackgroundTileTable, BGCNT_TO_VRAM_TILE_BASE(sRidleyInSpacePageData[0].tiletablePage));

            // Load object palette and graphics
            DmaTransfer(3, sRidleyInSpace_39dc70_Pal, PALRAM_OBJ, sizeof(sRidleyInSpace_39dc70_Pal), 16);
            CallLZ77UncompVram(sRidleyInSpaceMotherShipLeavingGfx, VRAM_OBJ);

            // Setup background for the space background
            CutsceneSetBgcntPageData(sRidleyInSpacePageData[0]);
            CutsceneReset();

            // Setup mother ship
            CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT].xPosition = sRidleyInSpaceShipLeavingPosition.x;
            CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT].yPosition = sRidleyInSpaceShipLeavingPosition.y;

            // Enable for scaling
            CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT].rotationScaling = TRUE;

            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT], RIDLEY_IN_SPACE_OAM_ID_MOTHER_SHIP_LEAVING_BACK);

            // Enable space background and objects
            CUTSCENE_DATA.dispcnt = sRidleyInSpacePageData[0].bg | DCNT_OBJ;

            // Probably a mistake, should be i < RIDLEY_IN_SPACE_SHIP_AMOUNT + RIDLEY_IN_SPACE_LEAVING_PARTICLE_AMOUNT
            // to properly initialize all particles
            for (i = RIDLEY_IN_SPACE_SHIP_AMOUNT; i <= RIDLEY_IN_SPACE_LEAVING_PARTICLE_AMOUNT; i++)
            {
                CUTSCENE_DATA.oam[i].actions = CUTSCENE_OAM_ACTION_NONE;

                // Set random position on screen
                // No modulo for X?
                CUTSCENE_DATA.oam[i].xPosition = PIXEL_TO_SUB_PIXEL(sRandomNumberTable[gFrameCounter8Bit & i]);
                CUTSCENE_DATA.oam[i].yPosition = PIXEL_TO_SUB_PIXEL(sRandomNumberTable[(u32)(gFrameCounter8Bit + i) % ARRAY_SIZE(sRandomNumberTable)]);

                // Check is off-screen
                if (CUTSCENE_DATA.oam[i].yPosition >= SCREEN_SIZE_Y_SUB_PIXEL)
                    continue;

                CUTSCENE_DATA.oam[i].timer = 0;
                CUTSCENE_DATA.oam[i].unk_12 = sRandomNumberTable[(u32)(gFrameCounter8Bit * i) % ARRAY_SIZE(sRandomNumberTable)];

                // Set random animation
                if (MOD_AND(CUTSCENE_DATA.oam[i].unk_12, 2))
                    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[i], RIDLEY_IN_SPACE_OAM_ID_SHIP_LEAVING_PARTICLE);
                else
                    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[i], RIDLEY_IN_SPACE_OAM_ID_SHIP_LEAVING_PARTICLE2);
            }

            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(1.f))
            {
                SoundPlay(SOUND_RIDLEY_IN_SPACE_MOTHER_SHIP_FLYING);

                // Start mother ship animation
                CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT].actions = MOTHER_SHIP_ACTION_MOVE_HORIZONTALLY | MOTHER_SHIP_ACTION_MOVE_VERTICALLY;

                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            // Wait for the mother ship animation to be done
            if (CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT].actions == CUTSCENE_OAM_ACTION_NONE)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(2.f))
            {
                // Start mother ship zoom animation
                CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT].actions = MOTHER_SHIP_ACTION_ZOOM;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            // Wait for the mother ship animation to be done
            if (CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT].actions == CUTSCENE_OAM_ACTION_NONE)
            {
                // Clear screen
                CUTSCENE_DATA.dispcnt &= ~(DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 5:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(2.f))
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

    // Update particles
    RidleyInSpaceShipLeavingParticles();

    // Slowly move background
    *CutsceneGetBgHorizontalPointer(sRidleyInSpacePageData[0].bg) += PIXEL_SIZE / 2;

    // Update mother ship
    RidleyInSpaceUpdateShipLeaving(&CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT]);

    #ifdef DEBUG
    CutsceneCheckSkipStage(1);
    #endif // DEBUG

    return FALSE;
}

/**
 * @brief 63b1c | c4 | Updates the ship leaving object
 * 
 * @param pOam Cutscene oam data pointer
 */
void RidleyInSpaceUpdateShipLeaving(struct CutsceneOamData* pOam)
{
    if (pOam->actions & MOTHER_SHIP_ACTION_MOVE)
    {
        // Moving to the upper right corner of the screen

        if (pOam->actions & MOTHER_SHIP_ACTION_MOVE_HORIZONTALLY)
        {
            // Move horizontally
            pOam->xPosition += PIXEL_SIZE * 2;

            // Check reached X destination
            if (pOam->xPosition > SCREEN_SIZE_X_SUB_PIXEL + BLOCK_SIZE * 4 + HALF_BLOCK_SIZE)
                pOam->actions = CUTSCENE_OAM_ACTION_NONE;
        }

        if (pOam->actions & MOTHER_SHIP_ACTION_MOVE_VERTICALLY)
        {
            // Move vertically
            pOam->unk_18++;
            pOam->yVelocity = -(PIXEL_SIZE - ONE_SUB_PIXEL);

            pOam->yPosition += pOam->yVelocity;

            // Check reached Y destination
            if (pOam->yPosition < -(BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE))
                pOam->actions = CUTSCENE_OAM_ACTION_NONE;
        }

        if (pOam->actions == CUTSCENE_OAM_ACTION_NONE)
        {
            // Either one of the destination was reached, setup zoom animation

            pOam->oamID = RIDLEY_IN_SPACE_OAM_ID_MOTHER_SHIP_LEAVING_FRONT;

            // Setup scaling
            gCurrentOamScaling = Q_8_8(1.f);

            // Top right corner of the screen, slightly off screen horizontally
            pOam->xPosition = SCREEN_SIZE_X_SUB_PIXEL + BLOCK_SIZE * 4;
            pOam->yPosition = BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE;
        }
    }
    else if (pOam->actions & MOTHER_SHIP_ACTION_ZOOM)
    {
        // Check move horizontally
        if (pOam->actions & MOTHER_SHIP_ACTION_ZOOM_MOVE)
            pOam->xPosition -= QUARTER_BLOCK_SIZE;

        pOam->yVelocity = 0;

        // Gradually scale up to x2
        if (gCurrentOamScaling < Q_8_8(2.f))
        {
            gCurrentOamScaling += Q_8_8(.035f);
            if (gCurrentOamScaling < Q_8_8(2.f))
                return;
        }

        // Scaling done, kill
        gCurrentOamScaling = Q_8_8(2.f);
        pOam->actions = CUTSCENE_OAM_ACTION_NONE;
    }
}

/**
 * @brief 63be0 | 1b0 | Handles the ridley being suspicious part
 * 
 * @return u8 FALSE
 */
u8 RidleyInSpaceRidleySuspicious(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            // Load ship interior palette
            DmaTransfer(3, sRidleyInSpaceShipInteriorPal, PALRAM_BASE, sizeof(sRidleyInSpaceShipInteriorPal), 16);
            SET_BACKDROP_COLOR(COLOR_BLACK);

            // Load ship interior graphics
            CallLZ77UncompVram(sRidleyInSpaceShipInterior2Gfx, BGCNT_TO_VRAM_CHAR_BASE(sRidleyInSpacePageData[3].graphicsPage));

            // Load ridley graphics
            CallLZ77UncompVram(sRidleyInSpaceRidleySuspiciousGfx, BGCNT_TO_VRAM_CHAR_BASE(sRidleyInSpacePageData[4].graphicsPage));

            // Load both ridley tile table to setup a transition
            CallLZ77UncompVram(sRidleyInSpaceRidleySuspiciousEyesOpenTileTable,
                BGCNT_TO_VRAM_TILE_BASE(sRidleyInSpacePageData[4].tiletablePage));

            CallLZ77UncompVram(sRidleyInSpaceRidleySuspiciousEyesSquintedTileTable,
                BGCNT_TO_VRAM_TILE_BASE(sRidleyInSpacePageData[5].tiletablePage));

            // Load ship interior tile table
            CallLZ77UncompVram(sRidleyInSpaceShipInteriorTileTable2, BGCNT_TO_VRAM_TILE_BASE(sRidleyInSpacePageData[3].tiletablePage));

            // Enable the ship interior and both ridley backgrounds 
            CutsceneSetBgcntPageData(sRidleyInSpacePageData[3]);
            CutsceneSetBgcntPageData(sRidleyInSpacePageData[4]);
            CutsceneSetBgcntPageData(sRidleyInSpacePageData[5]);

            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleyInSpacePageData[3].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleyInSpacePageData[4].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleyInSpacePageData[5].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneReset();

            CUTSCENE_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            gWrittenToBLDALPHA_H = BLDALPHA_MAX_VALUE;
            gWrittenToBLDALPHA_L = 0;

            CUTSCENE_DATA.dispcnt = sRidleyInSpacePageData[3].bg | sRidleyInSpacePageData[4].bg | sRidleyInSpacePageData[5].bg;
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 2:
            // Start fade from bg2 to bg1 to smootly transition between the 2 frames of ridley squinting his eyes
            CutsceneStartBackgroundEffect(CUTSCENE_DATA.bldcnt, BLDALPHA_MAX_VALUE, 0, 2, 2);
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 3:
            // Wait for fade to end
            if (CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_BG_ENDED)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;
        
        case 1:
        case 4:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(1.f))
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

    #ifdef DEBUG
    CutsceneCheckSkipStage(1);
    #endif // DEBUG

    return FALSE;
}

/**
 * @brief 63d90 | 1c4 | Handles the red alert part
 * 
 * @return u8 FALSE
 */
u8 RidleyInSpaceRedAlert(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            // Load palette
            DmaTransfer(3, sRidleyInSpace_39d910_Pal, PALRAM_BASE, sizeof(sRidleyInSpace_39d910_Pal), 16);
            SET_BACKDROP_COLOR(COLOR_BLACK);

            // Load ship interior graphics
            CallLZ77UncompVram(sRidleyInSpaceShipInteriorTileTable, BGCNT_TO_VRAM_TILE_BASE(sRidleyInSpacePageData[1].tiletablePage));
            CallLZ77UncompVram(sRidleyInSpaceShipInteriorGfx, BGCNT_TO_VRAM_CHAR_BASE(sRidleyInSpacePageData[1].graphicsPage));

            // Load ridley graphics
            CallLZ77UncompVram(sRidleyInSpaceRidleySittingGfx, BGCNT_TO_VRAM_CHAR_BASE(sRidleyInSpacePageData[2].graphicsPage));
            CallLZ77UncompVram(sRidleyInSpaceRidleySittingTileTable, BGCNT_TO_VRAM_TILE_BASE(sRidleyInSpacePageData[2].tiletablePage));

            // Setup both backgrounds
            CutsceneSetBgcntPageData(sRidleyInSpacePageData[1]);
            CutsceneSetBgcntPageData(sRidleyInSpacePageData[2]);

            // Set backgrounds position low vertically for the scrolling
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sRidleyInSpacePageData[1].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sRidleyInSpacePageData[1].bg, NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE * 10);

            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sRidleyInSpacePageData[2].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sRidleyInSpacePageData[2].bg, NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE * 10);

            CutsceneReset();

            CUTSCENE_DATA.dispcnt = sRidleyInSpacePageData[1].bg | sRidleyInSpacePageData[2].bg;
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > TWO_THIRD_SECOND)
            {
                // Setup palette data
                CUTSCENE_DATA.paletteData[0] = sRidleyInSpacePaletteData;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(1.f))
            {
                // Start scroll
                CutsceneStartBackgroundScrolling(sRidleyInSpaceScrollingInfo[0], sRidleyInSpacePageData[1].bg);
                CutsceneStartBackgroundScrolling(sRidleyInSpaceScrollingInfo[0], sRidleyInSpacePageData[2].bg);

                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            // Wait for scroll to end
            if (CutsceneCheckBackgroundScrollingActive(sRidleyInSpacePageData[1].bg) == 0)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(1.f))
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

    RidleyInSpaceUpdateAlertPalette(&CUTSCENE_DATA.paletteData[0]);

    #ifdef DEBUG
    CutsceneCheckSkipStage(1);
    #endif // DEBUG

    return FALSE;
}

/**
 * @brief 63f54 | 60 | Updates the red alert palette
 * 
 * @param pPalette Cutscene palette data pointer
 */
void RidleyInSpaceUpdateAlertPalette(struct CutscenePaletteData* pPalette)
{
    if (!(pPalette->active & TRUE))
        return;

    // Update timer
    if (pPalette->timer != 0)
    {
        APPLY_DELTA_TIME_DEC(pPalette->timer);
        return;
    }

    // Reset timer and change row
    pPalette->timer = pPalette->maxTimer;
    pPalette->paletteRow++;

    // Check for overflow
    if (pPalette->paletteRow >= ARRAY_SIZE(sRidleyInSpaceRedAlertPaletteRows))
        pPalette->paletteRow = 0;

    // Transfer current row
    DmaTransfer(3, &sRidleyInSpaceRedAlertPal[sRidleyInSpaceRedAlertPaletteRows[pPalette->paletteRow] * 16], PALRAM_BASE + 5 * PAL_ROW_SIZE, 1 * PAL_ROW_SIZE, 16);
}

/**
 * @brief 63fb4 | 1b4 | Handles the view of ship part
 * 
 * @return u8 FALSE
 */
u8 RidleyInSpaceViewOfShip(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(.5f))
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 1:
            if (CutsceneTransferAndUpdateFade())
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(1.f))
            {
                // Start left ship
                CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_LEFT_SHIP_SLOT].actions = SHIP_ACTION_MOVE_HORIZONTALLY | SHIP_ACTION_MOVE_VERTICALLY;
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(2.f / 15))
            {
                // Start right ship
                CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_RIGHT_SHIP_SLOT].actions = SHIP_ACTION_MOVE_HORIZONTALLY | SHIP_ACTION_MOVE_VERTICALLY;
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(2.f))
            {
                // Set ships semi transparent
                CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_LEFT_SHIP_SLOT].objMode = OAM_OBJ_MODE_SEMI_TRANSPARENT;
                CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_RIGHT_SHIP_SLOT].objMode = OAM_OBJ_MODE_SEMI_TRANSPARENT;

                // Start blending for the shadow effects on the small ships
                CutsceneStartBackgroundEffect(BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG3_SECOND_TARGET_PIXEL |
                    BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL, 14, 0, 32, 1);

                // Start mother ship
                CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT].actions = MOTHER_SHIP_ACTION_MOVE;
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 5:
            // Wait for mother ship to finish
            if (CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT].actions == CUTSCENE_OAM_ACTION_NONE)
            {
                CUTSCENE_DATA.timeInfo.subStage++;
                CUTSCENE_DATA.timeInfo.timer = 0;
            }
            break;

        case 6:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(1.5f))
            {
                CutsceneFadeScreenToBlack();
                CUTSCENE_DATA.timeInfo.stage++;
                MACRO_CUTSCENE_NEXT_STAGE();
            }
            break;
    }

    // Update ships
    RidleyInSpaceUpdateLeftBlueShip(&CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_LEFT_SHIP_SLOT]);
    RidleyInSpaceUpdateRightBlueShip(&CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_RIGHT_SHIP_SLOT]);
    RidleyInSpaceUpdateViewOfShip(&CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT]);

    // Update particles
    RidleyInSpaceViewOfShipParticles();

    // Slowly move background
    if (MOD_AND(gFrameCounter8Bit, 8) == 0)
        *CutsceneGetBgVerticalPointer(sRidleyInSpacePageData[0].bg) -= ONE_SUB_PIXEL;

    #ifdef DEBUG
    CutsceneCheckSkipStage(1);
    #endif // DEBUG

    return FALSE;
}

/**
 * @brief 64168 | 64 | Updates the mother ship during the view of ship part
 * 
 * @param pOam Cutscene OAM data pointer
 */
void RidleyInSpaceUpdateViewOfShip(struct CutsceneOamData* pOam)
{
    if (pOam->actions & MOTHER_SHIP_ACTION_MOVE_VERTICALLY)
    {
        // Set Y velocity, start by going fast then slow down
        if (pOam->yPosition < BLOCK_SIZE * 2)
            pOam->yVelocity = ONE_SUB_PIXEL * 2;
        else
            pOam->yVelocity = ONE_SUB_PIXEL;

        // Move
        pOam->yPosition += pOam->yVelocity;

        // Check reached destination position
        if (pOam->yPosition >= BLOCK_SIZE * 3 + HALF_BLOCK_SIZE)
            pOam->actions = CUTSCENE_OAM_ACTION_NONE;
    }

    pOam->unk_18++;

    // Handle idle floating
    if (MOD_AND(pOam->unk_18, 32) == 0)
        pOam->yPosition += sRidleyInSpaceShipsYMovementOffsets[DIV_SHIFT(pOam->unk_18, 32) % ARRAY_SIZE(sRidleyInSpaceShipsYMovementOffsets)];
}

/**
 * @brief 641cc | 80 | Updates the right blue ship
 * 
 * @param pOam Cutscene oam data pointer
 */
void RidleyInSpaceUpdateRightBlueShip(struct CutsceneOamData* pOam)
{
    s32 yVelocity;
    
    if (pOam->actions & SHIP_ACTION_MOVE_HORIZONTALLY)
    {
        // Move horizontally
        pOam->xVelocity = -PIXEL_SIZE / 2;
        pOam->xPosition += pOam->xVelocity;

        // Symetric with the left shift
        if (pOam->xPosition <= SCREEN_SIZE_X_SUB_PIXEL - SHIP_MAX_X)
        {
            // Reached stop point, stop all movement
            pOam->actions = CUTSCENE_OAM_ACTION_NONE;
            pOam->unk_18 = 0;
        }
    }

    if (pOam->actions & SHIP_ACTION_MOVE_VERTICALLY)
    {
        // Move vertically every 2 frames
        pOam->yVelocity = MOD_AND(pOam->unk_18, 2) ? -ONE_SUB_PIXEL : 0;
        pOam->yPosition += pOam->yVelocity;
    }

    pOam->unk_18++;

    // Handle idle floating
    if (MOD_AND(pOam->unk_18, 16) == 0)
        pOam->yPosition += sRidleyInSpaceShipsYMovementOffsets[DIV_SHIFT(pOam->unk_18, 16) % ARRAY_SIZE(sRidleyInSpaceShipsYMovementOffsets)];
}

/**
 * @brief 6424c | 70 | Updates the left blue ship during the view of ship part
 * 
 * @param pOam Cutscene oam data pointer
 */
void RidleyInSpaceUpdateLeftBlueShip(struct CutsceneOamData* pOam)
{
    if (pOam->actions & SHIP_ACTION_MOVE_HORIZONTALLY)
    {
        // Move horizontally
        pOam->xVelocity = PIXEL_SIZE / 2;
        pOam->xPosition += pOam->xVelocity;

        if (pOam->xPosition >= SHIP_MAX_X)
        {
            // Reached stop point, stop all movement
            pOam->actions = CUTSCENE_OAM_ACTION_NONE;
        }
    }

    if (pOam->actions & SHIP_ACTION_MOVE_VERTICALLY)
    {
        // Move vertically
        pOam->yVelocity = -ONE_SUB_PIXEL;
        pOam->yPosition += pOam->yVelocity;
    }

    pOam->unk_18++;

    // Handle idle floating
    if (MOD_AND(pOam->unk_18, 16) == 0)
        pOam->yPosition += sRidleyInSpaceShipsYMovementOffsets[DIV_SHIFT(pOam->unk_18, 16) % ARRAY_SIZE(sRidleyInSpaceShipsYMovementOffsets)];
}

/**
 * @brief 642bc | 15c | Initializes the ridley in space cutscene
 * 
 * @return u8 FALSE
 */
u8 RidleyInSpaceInit(void)
{
    CutsceneFadeScreenToBlack();

    // Load space background palette
    DmaTransfer(3, sRidleyInSpaceSpaceBackgroundPal, PALRAM_BASE, sizeof(sRidleyInSpaceSpaceBackgroundPal), 16);
    SET_BACKDROP_COLOR(COLOR_BLACK);

    // Load space background graphics
    CallLZ77UncompVram(sRidleyInSpaceSpaceBackgroundGfx, BGCNT_TO_VRAM_CHAR_BASE(sRidleyInSpacePageData[0].graphicsPage));
    CallLZ77UncompVram(sRidleyInSpaceSpaceBackgroundTileTable, BGCNT_TO_VRAM_TILE_BASE(sRidleyInSpacePageData[0].tiletablePage));

    DmaTransfer(3, sRidleyInSpaceShipsPal, PALRAM_OBJ, sizeof(sRidleyInSpaceShipsPal), 16);
    CallLZ77UncompVram(sRidleyInSpaceShipsGfx, VRAM_OBJ);

    // Setup background for the space background
    CutsceneSetBgcntPageData(sRidleyInSpacePageData[0]);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleyInSpacePageData[0].bg, NON_GAMEPLAY_START_BG_POS);

    CutsceneReset();

    gWrittenToBLDY_NonGameplay = 0;
    CUTSCENE_DATA.bldcnt = 0;

    // Setup ships
    CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_LEFT_SHIP_SLOT].xPosition = sRidleyInSpaceShipsStartPosition[RIDLEY_IN_SPACE_LEFT_SHIP_SLOT].x;
    CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_LEFT_SHIP_SLOT].yPosition = sRidleyInSpaceShipsStartPosition[RIDLEY_IN_SPACE_LEFT_SHIP_SLOT].y;

    CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_RIGHT_SHIP_SLOT].xPosition = sRidleyInSpaceShipsStartPosition[RIDLEY_IN_SPACE_RIGHT_SHIP_SLOT].x;
    CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_RIGHT_SHIP_SLOT].yPosition = sRidleyInSpaceShipsStartPosition[RIDLEY_IN_SPACE_RIGHT_SHIP_SLOT].y;

    CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT].xPosition = sRidleyInSpaceShipsStartPosition[RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT].x;
    CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT].yPosition = sRidleyInSpaceShipsStartPosition[RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT].y;

    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_LEFT_SHIP_SLOT], RIDLEY_IN_SPACE_OAM_ID_LEFT_BLUE_SHIP);
    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_RIGHT_SHIP_SLOT], RIDLEY_IN_SPACE_OAM_ID_RIGHT_BLUE_SHIP);
    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT], RIDLEY_IN_SPACE_OAM_ID_MOTHER_SHIP);

    PlayMusic(MUSIC_RIDLEY_IN_SPACE, 0);
    SoundPlay(SOUND_RIDLEY_IN_SPACE_SHIPS_APPEARING);

    // Start fade in
    CutsceneStartBackgroundFading(2);

    // Enable space background and objects
    CUTSCENE_DATA.dispcnt = sRidleyInSpacePageData[0].bg | DCNT_OBJ;

    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;
    CUTSCENE_DATA.timeInfo.stage++;

    return FALSE;
}

/**
 * @brief 64418 | 34 | Subroutine for the ridley in space cutscene
 * 
 * @return u8 bool, ended
 */
u8 RidleyInSpaceSubroutine(void)
{
    u8 ended;

    ended = sRidleyInSpaceSubroutineData[CUTSCENE_DATA.timeInfo.stage].pFunction();
    
    CutsceneUpdateBackgroundsPosition(TRUE);
    RidleyInSpaceProcessOAM();
    return ended;
}

/**
 * @brief 6444c | 4c | Processes the OAM for the cutscene
 * 
 */
void RidleyInSpaceProcessOAM(void)
{
    gNextOamSlot = 0;
    ProcessCutsceneOam(sRidleyInSpaceSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sRidleyInSpaceCutsceneOAM);

    ResetFreeOam();
    CalculateOamPart4(gCurrentOamRotation, gCurrentOamScaling, 0);
}

/**
 * @brief 64498 | 144 | Updates the particles during the view of ship part
 * 
 */
void RidleyInSpaceViewOfShipParticles(void)
{
    s32 i;
    u32 oamId;

    // 2 * DELTA_TIME
    if (MOD_AND(CUTSCENE_DATA.timeInfo.timer, 2) == 0)
    {
        // Try to initialize a new particle every 2 frames
        for (i = RIDLEY_IN_SPACE_SHIP_AMOUNT; i < RIDLEY_IN_SPACE_SHIP_AMOUNT + RIDLEY_IN_SPACE_VIEW_PARTICLE_AMOUNT; i++)
        {
            // Already exists, next
            if (CUTSCENE_DATA.oam[i].exists)
                continue;

            // Found slot, initialize
            CUTSCENE_DATA.oam[i].actions = CUTSCENE_OAM_ACTION_NONE;

            // Set random start position
            CUTSCENE_DATA.oam[i].xPosition = PIXEL_TO_SUB_PIXEL(sRandomNumberTable[(u32)(gFrameCounter8Bit + i) % ARRAY_SIZE(sRandomNumberTable)] & 0x53);
            CUTSCENE_DATA.oam[i].yPosition = PIXEL_TO_SUB_PIXEL(sRandomNumberTable[(u32)(CUTSCENE_DATA.oam[i].timer + i) % ARRAY_SIZE(sRandomNumberTable)] & 0x53);

            CUTSCENE_DATA.oam[i].timer = 0;

            // Check reverse position, loops through this sequence :
            // No reverse, X reverse, Y reverse, X and Y reverse
            if (CUTSCENE_DATA.timeInfo.customTimer & 1)
                CUTSCENE_DATA.oam[i].xPosition = SCREEN_SIZE_X_SUB_PIXEL - CUTSCENE_DATA.oam[i].xPosition;

            if (CUTSCENE_DATA.timeInfo.customTimer & 2)
                CUTSCENE_DATA.oam[i].yPosition = SCREEN_SIZE_Y_SUB_PIXEL - CUTSCENE_DATA.oam[i].yPosition;

            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[i], RIDLEY_IN_SPACE_OAM_ID_VIEW_OF_SHIP_PARTICLE);
            CUTSCENE_DATA.timeInfo.customTimer++;
            break;
        }
    }

    // Update particles
    for (i = RIDLEY_IN_SPACE_SHIP_AMOUNT; i < RIDLEY_IN_SPACE_SHIP_AMOUNT + RIDLEY_IN_SPACE_VIEW_PARTICLE_AMOUNT; i++)
    {
        // Don't update if doesn't exists
        if (!CUTSCENE_DATA.oam[i].exists)
            continue;

        // Update particle
        oamId = RidleyInSpaceViewOfShipUpdateParticle(&CUTSCENE_DATA.oam[i]);
        if (oamId != 0)
        {
            // Change oam id if needed
            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[i], oamId);
        }

        if (CUTSCENE_DATA.oam[i].exists == 0)
        {
            // Destroy if no longer exists
            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[i], 0);
        }
    }
}

/**
 * @brief 645dc | c0 | Updates a particle during the view of ship sequence
 * 
 * @param pOam Cutscene oam data pointer
 * @return u32 Oam id
 */
u32 RidleyInSpaceViewOfShipUpdateParticle(struct CutsceneOamData* pOam)
{
    u32 oamId;
    s32 divisor;
    u32 xOffset;
    u32 yOffset;
    u16 xPosition;

    oamId = 0;
    pOam->unk_12 = pOam->timer;

    if (pOam->actions == CUTSCENE_OAM_ACTION_NONE)
    {
        // Initialize destination position to move towards the edges of the screen
        pOam->xVelocity = (pOam->xPosition - PIXEL_TO_SUB_PIXEL(SCREEN_SIZE_X / 8)) * (SCREEN_SIZE_X + SCREEN_SIZE_Y);
        pOam->yVelocity = (pOam->yPosition - PIXEL_TO_SUB_PIXEL(SCREEN_SIZE_Y / 8)) * (SCREEN_SIZE_X + SCREEN_SIZE_Y);

        // Check any of the destination positions aren't 0
        if (pOam->xVelocity | pOam->yVelocity)
        {
            // Has to move, activate
            pOam->actions = PARTICLE_ACTION_MOVE;
        }
        else
        {
            // Already at destination, destroy
            pOam->exists = FALSE;
        }
    }
    else if (pOam->unk_12 < CONVERT_SECONDS(1.f) + TWO_THIRD_SECOND)
    {
        // Check change graphics
        if (pOam->unk_12 == CONVERT_SECONDS(5.f / 12) || pOam->unk_12 == CONVERT_SECONDS(5.f / 6) || pOam->unk_12 == CONVERT_SECONDS(7.f / 6))
            oamId = RIDLEY_IN_SPACE_OAM_ID_VIEW_OF_SHIP_PARTICLE2;

        // Get complement from 100, used to dilute speed over time
        // it'll start dividing by 99, then 98... up to 0 or when the destination has been reached
        // This creates a smooth, increasing velocity from the start position to the destination
        divisor = 100 + -pOam->unk_12;

        // Set positions to the center of the screen + diluted speed

        // X
        xOffset = pOam->xVelocity / divisor;
        pOam->xPosition = xOffset + SCREEN_SIZE_X_SUB_PIXEL / 2;

        // Y
        yOffset = pOam->yVelocity / divisor;
        pOam->yPosition = yOffset + SCREEN_SIZE_Y_SUB_PIXEL / 2;

        // Check despawn
        xPosition = xOffset + (SCREEN_SIZE_X_SUB_PIXEL + BLOCK_SIZE) / 2;
        if (xPosition > SCREEN_SIZE_X_SUB_PIXEL + BLOCK_SIZE)
        {
            // Outside of the X range
            pOam->exists = FALSE;
        }
        else if (pOam->yPosition > SCREEN_SIZE_Y_SUB_PIXEL + HALF_BLOCK_SIZE)
        {
            // Below the screen
            pOam->exists = FALSE;
        }
        else if (pOam->yPosition < -HALF_BLOCK_SIZE)
        {
            // Above the screen
            pOam->exists = FALSE;
        }
    }
    else
        pOam->exists = FALSE;

    pOam->timer++;

    return oamId;
}

/**
 * @brief 6469c | fc | Updates the particles during the ship leaving part
 * 
 */
void RidleyInSpaceShipLeavingParticles(void)
{
    s32 i;
    s32 newY;

    // 2 * DELTA_TIME
    if (MOD_AND(CUTSCENE_DATA.timeInfo.timer, 2) == 0)
    {
        // Try to initialize a new particle every 2 frames
        for (i = RIDLEY_IN_SPACE_SHIP_AMOUNT; i < RIDLEY_IN_SPACE_SHIP_AMOUNT + RIDLEY_IN_SPACE_LEAVING_PARTICLE_AMOUNT; i++)
        {
            // Already exists, next
            if (CUTSCENE_DATA.oam[i].exists)
                continue;

            // Found slot, initialize
            CUTSCENE_DATA.oam[i].actions = CUTSCENE_OAM_ACTION_NONE;

            CUTSCENE_DATA.oam[i].xPosition = -(BLOCK_SIZE + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);

            // Get random Y position
            newY = sRandomNumberTable[(u32)(gFrameCounter8Bit + i) % ARRAY_SIZE(sRandomNumberTable)];

            // Check is a valid position
            if (newY < SCREEN_SIZE_Y)
            {
                CUTSCENE_DATA.oam[i].yPosition = PIXEL_TO_SUB_PIXEL(newY);
                CUTSCENE_DATA.oam[i].timer = 0;
                CUTSCENE_DATA.oam[i].unk_12 = sRandomNumberTable[(u32)(gFrameCounter8Bit * i) % ARRAY_SIZE(sRandomNumberTable)];

                // Random animation
                if (MOD_AND(CUTSCENE_DATA.oam[i].unk_12, 2))
                    newY = RIDLEY_IN_SPACE_OAM_ID_SHIP_LEAVING_PARTICLE;
                else
                    newY = RIDLEY_IN_SPACE_OAM_ID_SHIP_LEAVING_PARTICLE2;

                UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[i], newY);
            }
            break;
        }
    }

    for (i = RIDLEY_IN_SPACE_SHIP_AMOUNT; i < RIDLEY_IN_SPACE_SHIP_AMOUNT + RIDLEY_IN_SPACE_LEAVING_PARTICLE_AMOUNT; i++)
    {
        // Don't update if doesn't exists
        if (!CUTSCENE_DATA.oam[i].exists)
            continue;

        // Update particle
        RidleyInSpaceShipLeavingUpdateParticle(&CUTSCENE_DATA.oam[i]);

        if (CUTSCENE_DATA.oam[i].exists == 0)
        {
            // Destroy if no longer exists
            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[i], 0);
        }
    }
}

/**
 * @brief 64798 | 38 | Updates a particle during the ship leaving sequence
 * 
 * @param pOam Cutscene OAM Data Pointer
 * @return struct CutsceneOamData* First param
 */
struct CutsceneOamData* RidleyInSpaceShipLeavingUpdateParticle(struct CutsceneOamData* pOam)
{
    if (pOam->actions == CUTSCENE_OAM_ACTION_NONE)
    {
        // Initialize
        pOam->xVelocity = MOD_AND(pOam->unk_12, 8) + PIXEL_SIZE / 2;
        pOam->actions = PARTICLE_ACTION_MOVE;
    }
    else
    {
        // Move
        pOam->xPosition += pOam->xVelocity;

        // Check is off-screen
        if (pOam->xPosition > SCREEN_SIZE_X_SUB_PIXEL + HALF_BLOCK_SIZE)
            pOam->exists = FALSE;
    }
}
