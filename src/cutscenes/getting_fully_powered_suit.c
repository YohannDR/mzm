#include "cutscenes/getting_fully_powered_suit.h"
#include "cutscenes/cutscene_utils.h"
#include "macros.h"

#include "data/shortcut_pointers.h"
#include "data/generic_data.h"
#include "data/cutscenes/getting_fully_powered_suit_data.h"
#include "data/cutscenes/internal_getting_fully_powered_suit_data.h"

#include "constants/audio.h"
#include "constants/cutscene.h"
#include "constants/game_state.h"

#include "structs/game_state.h"
#include "structs/display.h"

#define OAM_UP_SPARKLES_AMOUNT 5
#define OAM_UP_SPARKLES_START (OAM_RING_SPARKLES_AMOUNT + 1)
#define OAM_UP_SPARKLES_END (OAM_UP_SPARKLES_START + OAM_UP_SPARKLES_AMOUNT)

#define OAM_SLOT_RING_BOTTOM OAM_RING_SPARKLES_AMOUNT
#define OAM_SLOT_RING_TOP 13

#define RING_SPARKLE_ACTION_SPAWN 1
#define RING_SPARKLE_ACTION_FOLLOW 2

#define UP_SPARKLE_ACTION_MOVE 2

#define RING_ACTION_MOVE 2
#define RING_ACTION_SCALING_VELOCITY 4

#define RING_MOVEMENT_SPEED PIXEL_SIZE

/**
 * @brief 65bd8 | 204 | Handles the animation part (entire cutscene)
 * 
 * @return u8 FALSE
 */
u8 GettingFullyPoweredSuitAnimation(void)
{
    s32 i;
    u16* bgPosition;

    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            // Setup blending for the window effect
            CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt, 12, 8, 1);
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > ONE_THIRD_SECOND)
            {
                // Start ring movement
                CUTSCENE_DATA.oam[OAM_SLOT_RING_BOTTOM].actions = RING_ACTION_MOVE;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            // Wait a bit for the ring to move
            if (CUTSCENE_DATA.oam[OAM_SLOT_RING_BOTTOM].yPosition <= BLOCK_SIZE * 17)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            // Scroll background at the same speed as the ring
            bgPosition = CutsceneGetBgVerticalPointer(sGettingFullyPoweredSuitPageData[0].bg);
            if (*bgPosition - RING_MOVEMENT_SPEED > NON_GAMEPLAY_START_BG_POS)
            {
                *bgPosition -= RING_MOVEMENT_SPEED;
                break;
            }

            *bgPosition = NON_GAMEPLAY_START_BG_POS;
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 4:
            if (CUTSCENE_DATA.oam[OAM_SLOT_RING_BOTTOM].yPosition < BLOCK_SIZE * 8)
            {
                // Disable window 1 to prevent a big white square during the final fade
                CUTSCENE_DATA.dispcnt ^= DCNT_WIN1;

                // Start final fade out
                CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt | BLDCNT_SCREEN_FIRST_TARGET, BLDY_MAX_VALUE, 8, 1);

                // Set ring flying away
                CUTSCENE_DATA.oam[OAM_SLOT_RING_BOTTOM].actions |= RING_ACTION_SCALING_VELOCITY;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 5:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(1.f))
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 6:
            CutsceneFadeScreenToWhite();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    // Update ring palette
    GettingFullyPoweredSuitUpdateRingPalette(&CUTSCENE_DATA.paletteData[0]);

    // Sync vertical position of the background with the samus background
    *CutsceneGetBgVerticalPointer(sGettingFullyPoweredSuitPageData[1].bg) = *CutsceneGetBgVerticalPointer(sGettingFullyPoweredSuitPageData[0].bg);

    // Update ring
    GettingFullyPoweredSuitUpdateRing(&CUTSCENE_DATA.oam[OAM_SLOT_RING_BOTTOM]);

    // Update ring sparkles
    for (i = 0; i < OAM_RING_SPARKLES_AMOUNT; i++)
        GettingFullyPoweredSuitUpdateSparkleAroundRing(&CUTSCENE_DATA.oam[i], i);

    // Calculte window 1 vertical position

    // Get samus background position, with the base position being 0
    i = *CutsceneGetBgVerticalPointer(sGettingFullyPoweredSuitPageData[0].bg) - NON_GAMEPLAY_START_BG_POS;

    // Compute difference between the ring and the background position, results a value that is the Y position of the center of the ring
    // Add half a block to that position to offset it down to around where the bottom of the ring is
    i = SUB_PIXEL_TO_PIXEL_(CUTSCENE_DATA.oam[OAM_SLOT_RING_BOTTOM].yPosition - i) + SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

    // Clamp value
    CLAMP2(i, 0, SCREEN_SIZE_Y);

    // Write to window 1 Y size
    write16(REG_WIN1V, i);

    // Update up sparkles
    for (i = OAM_UP_SPARKLES_START; i < OAM_UP_SPARKLES_END; i++)
        GettingFullyPoweredSuitUpdateSparkleGoingUp(&CUTSCENE_DATA.oam[i], i);

    return FALSE;
}

/**
 * @brief 65ddc | 60 | Updates the ring palette
 * 
 * @param pPalette Cutscene palette data pointer
 */
void GettingFullyPoweredSuitUpdateRingPalette(struct CutscenePaletteData* pPalette)
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
    if (pPalette->paletteRow >= ARRAY_SIZE(sGettingFullyPoweredSuitRingPaletteRows))
        pPalette->paletteRow = 0;

    // Transfer current row
    DmaTransfer(3, &sGettingFullyPoweredSuitRingPal[sGettingFullyPoweredSuitRingPaletteRows[pPalette->paletteRow] * PAL_ROW],
        PALRAM_OBJ + 10 * PAL_ROW_SIZE, 1 * PAL_ROW_SIZE, 16);
}

/**
 * @brief 65e3c | 70 | Updates the ring object
 * 
 * @param pOam Cutscene OAM data pointer
 */
void GettingFullyPoweredSuitUpdateRing(struct CutsceneOamData* pOam)
{
    u16 unk;
    
    if (pOam->actions & RING_ACTION_SCALING_VELOCITY)
    {
        // Move increasingly faster
        unk = ++pOam->unk_18;
        pOam->yVelocity = -RING_MOVEMENT_SPEED - (unk / RING_MOVEMENT_SPEED);
    }
    else
    {
        // Move at a set speed
        pOam->yVelocity = -RING_MOVEMENT_SPEED;
        pOam->unk_18 = 0;
    }

    if (pOam->actions & RING_ACTION_MOVE)
    {
        // Move
        pOam->yPosition += pOam->yVelocity;

        // Check despawn
        if (pOam->yPosition <= -(BLOCK_SIZE * 3))
            pOam->actions = CUTSCENE_OAM_ACTION_NONE;
    }

    // Sync top ring position with the bottom ring
    CUTSCENE_DATA.oam[OAM_SLOT_RING_TOP].yPosition = pOam->yPosition;
}

/**
 * @brief 65eac | c4 | Updates a sparkle around the ring
 * 
 * @param pOam Cutscene OAM data pointer
 * @param sparkleId Sparkle ID
 */
void GettingFullyPoweredSuitUpdateSparkleAroundRing(struct CutsceneOamData* pOam, u8 sparkleId)
{
    if (pOam->actions == CUTSCENE_OAM_ACTION_NONE)
    {
        // Set spawn timer
        pOam->timer = MOD_AND(sRandomNumberTable[(u32)(gFrameCounter8Bit + sparkleId) % ARRAY_SIZE(sRandomNumberTable)], 32);
        pOam->actions = RING_SPARKLE_ACTION_SPAWN;
    }
    else if (pOam->actions == RING_SPARKLE_ACTION_SPAWN)
    {
        // Spawn timer
        if (pOam->timer != 0)
        {
            APPLY_DELTA_TIME_DEC(pOam->timer);
        }
        else
        {
            // Set random graphics
            if (MOD_AND(sRandomNumberTable[gFrameCounter8Bit], 2))
                UpdateCutsceneOamDataID(pOam, GETTING_FULLY_POWERED_SUIT_OAM_ID_SPARKLE_AROUND_RING2);
            else
                UpdateCutsceneOamDataID(pOam, GETTING_FULLY_POWERED_SUIT_OAM_ID_SPARKLE_AROUND_RING1);

            pOam->actions = RING_SPARKLE_ACTION_FOLLOW;
        }
    }
    else
    {
        if (!pOam->exists)
            pOam->actions = CUTSCENE_OAM_ACTION_NONE;
    }
    
    if (pOam->exists)
    {
        // Exists, update position to ring position + offset
        pOam->xPosition = CUTSCENE_DATA.oam[OAM_SLOT_RING_BOTTOM].xPosition + sGettingFullyPoweredSuitRingSparklesPositions[sparkleId][0];
        pOam->yPosition = CUTSCENE_DATA.oam[OAM_SLOT_RING_BOTTOM].yPosition + sGettingFullyPoweredSuitRingSparklesPositions[sparkleId][1];
    }
}

/**
 * @brief 65f70 | b0 | Updates a sparkle going up
 * 
 * @param pOam Cutscene OAM data pointer
 * @param sparkleId Sparkle ID
 */
void GettingFullyPoweredSuitUpdateSparkleGoingUp(struct CutsceneOamData* pOam, u8 sparkleId)
{
    u16 unk;

    if (pOam->actions & UP_SPARKLE_ACTION_MOVE)
    {
        // Compute increasing velocity
        unk = ++pOam->unk_18;
        pOam->yVelocity += (unk / QUARTER_BLOCK_SIZE);

        // Clamp velocity
        if (pOam->yVelocity > HALF_BLOCK_SIZE)
            pOam->yVelocity = HALF_BLOCK_SIZE;

        // Move
        pOam->yPosition -= pOam->yVelocity;

        // Check off screen enough
        if (pOam->yPosition <= -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE))
        {
            // Soft destroy, stop moving
            pOam->actions = CUTSCENE_OAM_ACTION_NONE;

            // Set respawn timer
            pOam->timer = MOD_AND(sGettingFullyPoweredSuitBackgroundGfx[gFrameCounter8Bit + sparkleId], 64);
        }
    }
    else
    {
        // Spawn timer
        if (pOam->timer == 0)
        {
            // Initialize
            pOam->actions = UP_SPARKLE_ACTION_MOVE;
            pOam->yVelocity = 0;

            // X position + random offset
            pOam->xPosition = sGettingFullyPoweredSuitUpSparklesXPositions[sparkleId - OAM_UP_SPARKLES_START] +
                MOD_AND(sRandomNumberTable[gFrameCounter8Bit], 64);
            
            // Slightly below screen
            pOam->yPosition = SCREEN_SIZE_Y_SUB_PIXEL + BLOCK_SIZE;
            pOam->unk_18 = 0;
            return;
        }

        pOam->timer--;
    }
}

/**
 * @brief 66020 | 33c | Initializes the getting fully powered suit cutscene
 * 
 * @return u8 FALSE
 */
u8 GettingFullyPoweredSuitInit(void)
{
    s32 i;

    CutsceneFadeScreenToBlack();

    // Load palette, in both background and object
    DmaTransfer(3, sGettingFullyPoweredSuitPal, PALRAM_BASE, 11 * PAL_ROW_SIZE, 16);
    DmaTransfer(3, PALRAM_BASE, PALRAM_OBJ, PAL_SIZE, 32);
    SET_BACKDROP_COLOR(COLOR_BLACK);

    // Load samus graphics
    CallLZ77UncompVram(sGettingFullyPoweredSuitSamusGfx, BGCNT_TO_VRAM_CHAR_BASE(sGettingFullyPoweredSuitPageData[0].graphicsPage));
    CallLZ77UncompVram(sGettingFullyPoweredSuitSamusTileTable, BGCNT_TO_VRAM_TILE_BASE(sGettingFullyPoweredSuitPageData[0].tiletablePage));

    // Load background graphics
    CallLZ77UncompVram(sGettingFullyPoweredSuitBackgroundGfx, BGCNT_TO_VRAM_CHAR_BASE(sGettingFullyPoweredSuitPageData[1].graphicsPage));
    CallLZ77UncompVram(sGettingFullyPoweredSuitBackgroundTileTable, BGCNT_TO_VRAM_TILE_BASE(sGettingFullyPoweredSuitPageData[1].tiletablePage));

    // Load objects graphics
    CallLZ77UncompVram(sGettingFullyPoweredSuitRingSparklesGfx, VRAM_OBJ);

    // Setup samus and background background
    CutsceneSetBgcntPageData(sGettingFullyPoweredSuitPageData[0]);
    CutsceneSetBgcntPageData(sGettingFullyPoweredSuitPageData[1]);

    CutsceneReset();

    // Setup blending for the light effect below the ring using windows
    CUTSCENE_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_INCREASE_EFFECT |
        BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL |
        BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

    gWrittenToBLDY_NonGameplay = 0;
    gWrittenToBLDALPHA_L = 0;
    gWrittenToBLDALPHA_H = BLDALPHA_MAX_VALUE;

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sGettingFullyPoweredSuitPageData[0].bg, NON_GAMEPLAY_START_BG_POS);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sGettingFullyPoweredSuitPageData[1].bg, NON_GAMEPLAY_START_BG_POS);

    // Set background low for the scrolling
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sGettingFullyPoweredSuitPageData[0].bg, NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE * 10);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sGettingFullyPoweredSuitPageData[1].bg, NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE * 10);

    // Initialize ring bottom
    CUTSCENE_DATA.oam[OAM_SLOT_RING_BOTTOM].xPosition = BLOCK_SIZE * 8 - QUARTER_BLOCK_SIZE;
    CUTSCENE_DATA.oam[OAM_SLOT_RING_BOTTOM].yPosition = BLOCK_SIZE * 22;
    CUTSCENE_DATA.oam[OAM_SLOT_RING_BOTTOM].priority = sGettingFullyPoweredSuitPageData[0].priority;
    CUTSCENE_DATA.oam[OAM_SLOT_RING_BOTTOM].objMode = OAM_OBJ_MODE_NORMAL;
    CUTSCENE_DATA.oam[OAM_SLOT_RING_BOTTOM].boundBackground = 2;

    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[OAM_SLOT_RING_BOTTOM], GETTING_FULLY_POWERED_SUIT_OAM_ID_RING_BOTTOM);

    // Initialize ring top based on ring bottom
    CUTSCENE_DATA.oam[OAM_SLOT_RING_TOP] = CUTSCENE_DATA.oam[OAM_SLOT_RING_BOTTOM];
    // Lower priority than the ring bottom
    CUTSCENE_DATA.oam[OAM_SLOT_RING_TOP].priority = sGettingFullyPoweredSuitPageData[0].priority + 1;
    
    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[OAM_SLOT_RING_TOP], GETTING_FULLY_POWERED_SUIT_OAM_ID_RING_TOP);

    // Semi setup of the ring sparkles, they'll be properly initialized later
    for (i = 0; i < OAM_RING_SPARKLES_AMOUNT; i++)
    {
        CUTSCENE_DATA.oam[i].priority = sGettingFullyPoweredSuitPageData[0].priority;
        CUTSCENE_DATA.oam[i].boundBackground = 2;
    }

    // Setup one up sparkle
    CUTSCENE_DATA.oam[OAM_UP_SPARKLES_START].xPosition = sGettingFullyPoweredSuitUpSparklesXPositions[0];
    CUTSCENE_DATA.oam[OAM_UP_SPARKLES_START].yPosition = BLOCK_SIZE * 11;
    CUTSCENE_DATA.oam[OAM_UP_SPARKLES_START].priority = sGettingFullyPoweredSuitPageData[0].priority;
    CUTSCENE_DATA.oam[i].timer = MOD_AND(sRandomNumberTable[gFrameCounter8Bit], 64);

    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[OAM_UP_SPARKLES_START], GETTING_FULLY_POWERED_SUIT_OAM_ID_SPARKLE_GOING_UP);

    // Setup the rest of the sparkles
    for (i = OAM_UP_SPARKLES_START + 1; i < OAM_UP_SPARKLES_END; i++)
    {
        // Copy the template
        CUTSCENE_DATA.oam[i] = CUTSCENE_DATA.oam[OAM_UP_SPARKLES_START];

        // Just change X position and timer
        CUTSCENE_DATA.oam[i].xPosition = sGettingFullyPoweredSuitUpSparklesXPositions[i - OAM_UP_SPARKLES_START];
        CUTSCENE_DATA.oam[i].timer = MOD_AND(sGettingFullyPoweredSuitBackgroundGfx[gFrameCounter8Bit + i], 64);
    }

    CUTSCENE_DATA.paletteData[0] = sGettingFullyPoweredSuitPaletteData;

    // Enable objects, samus, background and window 1
    CUTSCENE_DATA.dispcnt = DCNT_OBJ | DCNT_WIN1 | sGettingFullyPoweredSuitPageData[0].bg | sGettingFullyPoweredSuitPageData[1].bg;

    // Setup windows
    write8(REG_WINOUT, WIN0_ALL);
    write8(REG_WININ + 1, HIGH_BYTE(WIN1_ALL_NO_COLOR_EFFECT));

    // Set entire screen for the size of window 1
    write16(REG_WIN1H, SCREEN_SIZE_X);
    write16(REG_WIN1V, SCREEN_SIZE_Y);

    gPauseScreenFlag = PAUSE_SCREEN_NONE;
    PlayMusic(MUSIC_GETTING_FULLY_POWERED_SUIT_CUTSCENE, 0);

    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;
    CUTSCENE_DATA.timeInfo.stage++;

    return FALSE;
}

/**
 * @brief 6635c | 34 | Subroutine for the getting fully powered suit cutscene
 * 
 * @return u8 bool, ended
 */
u8 GettingFullyPoweredSuitSubroutine(void)
{
    u8 ended;

    ended = sGettingFullyPoweredSuitSubroutineData[CUTSCENE_DATA.timeInfo.stage].pFunction();
    CutsceneUpdateBackgroundsPosition(TRUE);
    GettingFullyPoweredSuitProcessOAM();
    
    return ended;
}

/**
 * @brief 66390 | 38 | Processes the OAM
 * 
 */
void GettingFullyPoweredSuitProcessOAM(void)
{
    gNextOamSlot = 0;
    ProcessCutsceneOam(sGettingFullyPoweredSuitSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sGettingFullyPoweredSuitCutsceneOam);
    ResetFreeOam();
}
