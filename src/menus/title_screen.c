#include "menus/title_screen.h"
#include "macros.h"
#include "callbacks.h"
#include "oam_id.h"

#include "data/shortcut_pointers.h"
#include "data/menus/title_screen_data.h"
#include "data/menus/internal_title_screen_data.h"
#include "data/menus/pause_screen_data.h"

#include "constants/menus/title_screen.h"
#include "constants/audio.h"
#include "constants/demo.h"

#include "structs/demo.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/samus.h"

/**
 * @brief 76390 | 60 | Forward the page data to the correct BGCNT register
 * 
 * @param pPageData Title screen page data pointer
 */
void TitleScreenSetBGCNTPageData(const struct TitleScreenPageData* const pPageData)
{
    u16 value;

    // value = CREATE_BGCNT(pPageData->graphicsPage, pPageData->tiletablePage, pPageData->priority, pPageData->screenSize);
    value = pPageData->priority | pPageData->screenSize | pPageData->tiletablePage << BGCNT_SCREEN_BASE_BLOCK_SHIFT |
        pPageData->graphicsPage << BGCNT_CHAR_BASE_BLOCK_SHIFT;

    if (pPageData->bg == DCNT_BG0)
        write16(REG_BG0CNT, value);
    else if (pPageData->bg == DCNT_BG1)
        write16(REG_BG1CNT, value);
    else if (pPageData->bg == DCNT_BG2)
        write16(REG_BG2CNT, value);
    else
        write16(REG_BG3CNT, value);
}

/**
 * @brief 763f0 | 18 | Loads the tiletable of a page data
 * 
 * @param pPageData Title screen page data pointer
 */
void TitleScreenLoadPageData(const struct TitleScreenPageData* const pPageData)
{
    LZ77UncompVRAM(pPageData->tiletablePointer, VRAM_BASE + pPageData->tiletablePage * 0x800);
}

/**
 * @brief 76408 | 18 | Loads the tiletable of a page data
 * 
 * @param pPageData Title screen page data pointer
 */
void TitleScreenLoadPageData_Copy(const struct TitleScreenPageData* const pPageData)
{
    LZ77UncompVRAM(pPageData->tiletablePointer, VRAM_BASE + pPageData->tiletablePage * 0x800);
}

/**
 * @brief 76420 | 2c | Updates the OAM id of a title screen OAM
 * 
 * @param offset OAM offset
 * @param oamId OAM id
 */
void TitleScreenUpdateOamId(u8 offset, u8 oamId)
{
    TITLE_SCREEN_DATA.oam[offset].oamID = oamId;
    TITLE_SCREEN_DATA.oam[offset].animationDurationCounter = 0;
    TITLE_SCREEN_DATA.oam[offset].currentAnimationFrame = 0;
}

/**
 * @brief 7644c | 2c | Calls the OAM process handler
 * 
 */
void TitleScreenCallProcessOAM(void)
{
    gNextOamSlot = 0;
    ProcessMenuOam(ARRAY_SIZE(TITLE_SCREEN_DATA.oam), TITLE_SCREEN_DATA.oam, sTitleScreenOam);
    ResetFreeOam();
}

/**
 * @brief 76478 | 50 | Resets the OAM
 * 
 */
void TitleScreenResetOAM(void)
{
    s32 i;
    struct MenuOamData* pOam;

    for (pOam = TITLE_SCREEN_DATA.oam, i = 0; i < (s32)ARRAY_SIZE(TITLE_SCREEN_DATA.oam); i++, pOam++)
        *pOam = sMenuOamData_Empty;

    TitleScreenUpdateOamId(0, 0);

    TITLE_SCREEN_DATA.oam[0].yPosition = sTitleScreenRomInfoPosition[0];
    TITLE_SCREEN_DATA.oam[0].xPosition = sTitleScreenRomInfoPosition[1];
}

/**
 * @brief 764c8 | 118 | Handles the title screen fading in
 * 
 * @return u32 
 */
u32 TitleScreenFadingIn(void)
{
    u32 ended;
    u16* src;
    u16* dst;

    ended = FALSE;
    switch (TITLE_SCREEN_DATA.unk_10)
    {
        case 0:
            TITLE_SCREEN_DATA.colorToApply = 0;
            TITLE_SCREEN_DATA.unk_12 = FALSE;
            TITLE_SCREEN_DATA.unk_14 = 0;

            TITLE_SCREEN_DATA.unk_10++;
            break;

        case 1:
            if (TITLE_SCREEN_DATA.unk_12)
                break;

            if (TITLE_SCREEN_DATA.colorToApply < 32)
            {
                src = (void*)sEwramPointer + 0x8000;
                dst = (void*)sEwramPointer + 0x8400;
                ApplySpecialBackgroundFadingColor(0, TITLE_SCREEN_DATA.colorToApply, &src, &dst, USHORT_MAX);

                src = (void*)sEwramPointer + 0x8200;
                dst = (void*)sEwramPointer + 0x8600;
                ApplySpecialBackgroundFadingColor(0, TITLE_SCREEN_DATA.colorToApply, &src, &dst, USHORT_MAX);

                TITLE_SCREEN_DATA.unk_12 = TRUE;
                if (TITLE_SCREEN_DATA.colorToApply == 31)
                {
                    TITLE_SCREEN_DATA.colorToApply++;
                    break;
                }

                if (TITLE_SCREEN_DATA.colorToApply + 4 > 31)
                    TITLE_SCREEN_DATA.colorToApply = 31;
                else
                    TITLE_SCREEN_DATA.colorToApply += 4;

                break;
            }
            
            DmaTransfer(3, (void*)sEwramPointer + 0x8000, (void*)sEwramPointer + 0x8400, 0x400, 16);
            TITLE_SCREEN_DATA.unk_12 = TRUE;
            TITLE_SCREEN_DATA.unk_10++;
            break;

        case 2:
            if (!TITLE_SCREEN_DATA.unk_12)
            {
                TITLE_SCREEN_DATA.colorToApply = 0;
                TITLE_SCREEN_DATA.unk_10 = 0;
                ended = TRUE;
            }
    }

    return ended;
}

/**
 * @brief 765e0 | 130 | Handles the title screen fading out
 * 
 * @param intensity 
 * @param delay 
 * @return u32 bool, ended
 */
u32 TitleScreenFadingOut(u8 intensity, u8 delay)
{
    u32 ended;
    u16* src;
    u16* dst;

    ended = FALSE;
    TITLE_SCREEN_DATA.unk_14++;
    switch (TITLE_SCREEN_DATA.unk_10)
    {
        case 0:
            TITLE_SCREEN_DATA.colorToApply = 0;
            TITLE_SCREEN_DATA.unk_12 = FALSE;
            TITLE_SCREEN_DATA.unk_14 = 0;

            TITLE_SCREEN_DATA.unk_10++;
            break;

        case 1:
            if (TITLE_SCREEN_DATA.unk_12)
                break;

            if (TITLE_SCREEN_DATA.unk_14 < delay)
                break;

            TITLE_SCREEN_DATA.unk_14 = 0;
            if (TITLE_SCREEN_DATA.colorToApply < 32)
            {
                src = (void*)sEwramPointer + 0x8000;
                dst = (void*)sEwramPointer + 0x8400;
                ApplySpecialBackgroundFadingColor(2, TITLE_SCREEN_DATA.colorToApply, &src, &dst, USHORT_MAX);

                src = (void*)sEwramPointer + 0x8200;
                dst = (void*)sEwramPointer + 0x8600;
                ApplySpecialBackgroundFadingColor(2, TITLE_SCREEN_DATA.colorToApply, &src, &dst, USHORT_MAX);

                TITLE_SCREEN_DATA.unk_12 = TRUE;
                if (TITLE_SCREEN_DATA.colorToApply == 31)
                {
                    TITLE_SCREEN_DATA.colorToApply++;
                    break;
                }

                if (TITLE_SCREEN_DATA.colorToApply + intensity > 31)
                    TITLE_SCREEN_DATA.colorToApply = 31;
                else
                    TITLE_SCREEN_DATA.colorToApply += intensity;

                break;
            }
            
            BitFill(3, 0, (void*)sEwramPointer + 0x8400, 0x400, 16);
            TITLE_SCREEN_DATA.unk_12 = TRUE;
            TITLE_SCREEN_DATA.unk_10++;
            break;

        case 2:
            if (!TITLE_SCREEN_DATA.unk_12)
            {
                TITLE_SCREEN_DATA.colorToApply = 0;
                TITLE_SCREEN_DATA.unk_10 = 0;
                ended = TRUE;
            }
    }

    return ended;
}

/**
 * @brief 76710 | 94 | To document
 * 
 * @param param_1 To document
 */
void unk_76710(u8 param_1)
{
    if (!param_1)
    {
        DmaTransfer(3, PALRAM_BASE, (void*)sEwramPointer + 0x8000, 0x400, 16);
        BitFill(3, 0, PALRAM_BASE, 0x400, 16);
        DmaTransfer(3, PALRAM_BASE, (void*)sEwramPointer + 0x8400, 0x400, 16);
    }
    else
        DmaTransfer(3, PALRAM_BASE, (void*)sEwramPointer + 0x8000, 0x400, 16);

    TITLE_SCREEN_DATA.unk_10 = 0;
}

/**
 * @brief 767a4 | 40 | To document
 * 
 */
void unk_767a4(void)
{
    if (TITLE_SCREEN_DATA.unk_12)
    {
        DmaTransfer(3, (void*)sEwramPointer + 0x8400, PALRAM_BASE, 0x400, 16);
        TITLE_SCREEN_DATA.unk_12 = FALSE;
    }
}

/**
 * @brief 767e4 | 194 | Updates the animated palettes of the title screen
 * 
 */
void TitleScreenUpdateAnimatedPalette(void)
{
    struct TitleScreenAnimatedPalette* pAnim;

    if (TITLE_SCREEN_DATA.activeAnimatedPalettes & TITLE_SCREEN_ANIMATED_PALETTE_SKY_DECORATIONS)
    {
        pAnim = &TITLE_SCREEN_DATA.animatedPalettes[0];
        pAnim->timer--;
        if (pAnim->timer == 0)
        {
            pAnim->timer = pAnim->maxTimer;
            pAnim->paletteRow++;

            if (pAnim->paletteRow >= ARRAY_SIZE(sTitleScreenSkyDecorationsPaletteRows))
                pAnim->paletteRow = 0;

            DmaTransfer(3, &sTitleScreenPal[sTitleScreenSkyDecorationsPaletteRows[pAnim->paletteRow] * 16], PALRAM_BASE + 0x100, 0x20, 16);
        }
    }

    if (TITLE_SCREEN_DATA.activeAnimatedPalettes & TITLE_SCREEN_ANIMATED_PALETTE_TITLE)
    {
        pAnim = &TITLE_SCREEN_DATA.animatedPalettes[1];
        if (pAnim->unk_4 == 0)
        {
            pAnim->unk_4 = sTitleScreenAnimatedPaletteTemplates[1].unk_4;
            TITLE_SCREEN_DATA.activeAnimatedPalettes ^= TITLE_SCREEN_ANIMATED_PALETTE_TITLE;
        }
        else
        {
            pAnim->timer--;
            if (pAnim->timer == 0)
            {
                pAnim->timer = pAnim->maxTimer;
                pAnim->paletteRow++;

                if (pAnim->paletteRow >= ARRAY_SIZE(sTitleScreenTitlePaletteRows))
                {
                    pAnim->paletteRow = 0;
                    pAnim->unk_4--;
                }

                DmaTransfer(3, &sTitleScreenPal[sTitleScreenTitlePaletteRows[pAnim->paletteRow] * 16 + 1], PALRAM_BASE + 2, 0x1E, 16);
            }
        }
    }

    if (TITLE_SCREEN_DATA.activeAnimatedPalettes & TITLE_SCREEN_ANIMATED_PALETTE_PROMPT)
    {
        pAnim = &TITLE_SCREEN_DATA.animatedPalettes[2];
        if (pAnim->unk_4 != 0)
        {
            pAnim->timer--;
            if (pAnim->timer == 0)
            {
                pAnim->timer = pAnim->maxTimer;
                pAnim->paletteRow++;

                if (pAnim->paletteRow > 1)
                    pAnim->paletteRow = 0;

                pAnim->paletteRow *= 4;
            }

            DmaTransfer(3, &sTitleScreenPromptPal[pAnim->paletteRow * 16], PALRAM_BASE + 0x1A0, 0x18, 16);
        }
        else
        {
            pAnim->timer--;
            if (pAnim->timer == 0)
            {
                pAnim->timer = pAnim->maxTimer;
                pAnim->paletteRow++;

                if (pAnim->paletteRow > 5)
                    pAnim->paletteRow = 0;
            }
            
            DmaTransfer(3, &sTitleScreenPromptPal[sTitleScreenPromptPaletteRows[pAnim->paletteRow] * 16], PALRAM_BASE + 0x1A0, 0x18, 16);
        }
    }
}

/**
 * @brief 76978 | 120 | To document
 * 
 */
void unk_76978(u8 param_1)
{
    if (param_1 & 1)
    {
        DmaTransfer(3, (void*)sEwramPointer + 0x4000, VRAM_BASE + 0x4000, 0x800, 16);
        DmaTransfer(3, (void*)sEwramPointer + 0x4800, VRAM_BASE + 0x4800, 0x800, 16);
    }

    if (param_1 & 2)
    {
        DmaTransfer(3, (void*)sEwramPointer + 0x5000, VRAM_BASE + 0x5000, 0x800, 16);
        DmaTransfer(3, (void*)sEwramPointer + 0x5800, VRAM_BASE + 0x5800, 0x800, 16);
    }

    if (param_1 & 4)
    {
        DmaTransfer(3, (void*)sEwramPointer + 0x6000, VRAM_BASE + 0x6000, 0x800, 16);
        DmaTransfer(3, (void*)sEwramPointer + 0x6800, VRAM_BASE + 0x6800, 0x800, 16);
    }

    if (param_1 & 8)
    {
        DmaTransfer(3, (void*)sEwramPointer + 0x7000, VRAM_BASE + 0x7000, 0x400, 16);
        TITLE_SCREEN_DATA.unk_24 = gBg3VOFS_NonGameplay = BLOCK_SIZE * 12 + HALF_BLOCK_SIZE;
    }
}

/**
 * @brief 76a98 | c8 | To document
 * 
 * @return u32 bool, ended
 */
u32 unk_76a98(void)
{
    u32 ended;

    ended = FALSE;
    switch (TITLE_SCREEN_DATA.unk_E)
    {
        case 0:
            break;

        case 1:
            TITLE_SCREEN_DATA.oamTimings[0].stage = 16;
            TITLE_SCREEN_DATA.oamTimings[1].stage = 16;

            TITLE_SCREEN_DATA.dispcnt &= ~sTitleScreenPageData[0].bg;
            TITLE_SCREEN_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

            TITLE_SCREEN_DATA.unk_E++;
            break;

        case 2:
            gWrittenToBLDY_NonGameplay += 4;
            if (gWrittenToBLDY_NonGameplay >= BLDY_MAX_VALUE)
            {
                gWrittenToBLDY_NonGameplay = BLDY_MAX_VALUE;
                TITLE_SCREEN_DATA.unk_E++;
            }
            break;

        case 3:
        case 4:
        case 5:
        case 6:
            unk_76978(1 << (TITLE_SCREEN_DATA.unk_E - 3));
            TITLE_SCREEN_DATA.unk_E++;
            break;

        case 7:
            if (gWrittenToBLDY_NonGameplay >= 9)
            {
                gWrittenToBLDY_NonGameplay -= 8;
                break;
            }

            gWrittenToBLDY_NonGameplay = 0;
            TITLE_SCREEN_DATA.unk_E = 0;
            ended = TRUE;
            break;
    }

    return ended;
}

/**
 * @brief 76b60 | 194 | Handles the comet view part of the title screen
 * 
 * @return u32 bool, ended
 */
u32 TitleScreenCometsView(void)
{
    u32 ended;
    s32 screenOffset;

    screenOffset = 0;
    ended = FALSE;
    TITLE_SCREEN_DATA.cometsTimer++;

    if (gChangedInput & (KEY_A | KEY_START))
    {
        TITLE_SCREEN_DATA.unk_E = 1;
        return FALSE;
    }

    switch (TITLE_SCREEN_DATA.cometsStage)
    {
        case 0:
            TITLE_SCREEN_DATA.cometsStage++;
            TITLE_SCREEN_DATA.cometsTimer = 0;
            break;

        case 1:
            // Wait
            if (TITLE_SCREEN_DATA.cometsTimer > 60)
            {
                // Spawn first comet
                TITLE_SCREEN_DATA.type |= TITLE_SCREEN_TYPE_FIRST_COMET_ACTIVE;
                TITLE_SCREEN_DATA.oamTimings[0].stage = 0;
                TITLE_SCREEN_DATA.oamTimings[0].timer = 0;

                TITLE_SCREEN_DATA.cometsStage++;
                TITLE_SCREEN_DATA.cometsTimer = 0;
            }
            break;

        case 2:
            // Wait
            if (TITLE_SCREEN_DATA.cometsTimer > 60 * 2)
            {
                // Spawn second comet
                TITLE_SCREEN_DATA.type |= TITLE_SCREEN_TYPE_SECOND_COMET_ACTIVE;
                TITLE_SCREEN_DATA.oamTimings[1].stage = 0;
                TITLE_SCREEN_DATA.oamTimings[1].timer = 0;

                TITLE_SCREEN_DATA.cometsStage++;
                TITLE_SCREEN_DATA.cometsTimer = 0;
            }
            break;

        case 3:
            // Wait
            if (TITLE_SCREEN_DATA.cometsTimer > 60 / 2)
            {
                TITLE_SCREEN_DATA.cometsStage++;
                TITLE_SCREEN_DATA.cometsTimer = 0;
            }
            break;

        case 4:
            // Scroll screen
            if (gBg3VOFS_NonGameplay >= BLOCK_SIZE * 12 + HALF_BLOCK_SIZE)
            {
                gBg3VOFS_NonGameplay = BLOCK_SIZE * 12 + HALF_BLOCK_SIZE;
                TITLE_SCREEN_DATA.cometsStage++;
                break;
            }

            if (BLOCK_SIZE * 12 + HALF_BLOCK_SIZE - gBg3VOFS_NonGameplay < 9)
                screenOffset += PIXEL_SIZE / 2;
            else
                screenOffset += PIXEL_SIZE;
            break;

        default:
            ended = TRUE;
            break;
    }

    if (!ended)
    {
        screenOffset += gBg3VOFS_NonGameplay;
        if (screenOffset > BLOCK_SIZE * 12 + HALF_BLOCK_SIZE)
            screenOffset = BLOCK_SIZE * 12 + HALF_BLOCK_SIZE;
        else if (screenOffset < 0)
            screenOffset = 0;

        gBg3VOFS_NonGameplay = screenOffset;

        TitleScreenTransferGroundGraphics();
    }

    TITLE_SCREEN_DATA.unk_24 = gBg3VOFS_NonGameplay;

    return ended;
}

/**
 * @brief 76cf4 | 9c | Transfers the ground graphics
 * 
 */
void TitleScreenTransferGroundGraphics(void)
{
    s32 var_0;
    s32 var_1;
    u8* src;

    var_0 = -1;
    var_1 = -1;

    if (TITLE_SCREEN_DATA.unk_24 != gBg3VOFS_NonGameplay)
    {
        if (TITLE_SCREEN_DATA.unk_24 < gBg3VOFS_NonGameplay)
        {
            if (gBg3VOFS_NonGameplay >= (BLOCK_SIZE * 5 + HALF_BLOCK_SIZE))
            {
                var_0 = (gBg3VOFS_NonGameplay - (BLOCK_SIZE * 5 + HALF_BLOCK_SIZE)) >> 5;
                var_1 = (TITLE_SCREEN_DATA.unk_24 - (BLOCK_SIZE * 5 + HALF_BLOCK_SIZE)) >> 5;
                src = (void*)sEwramPointer + 0x4000;
            }
        }
        else
        {
            if (gBg3VOFS_NonGameplay <= (BLOCK_SIZE * 7 + HALF_BLOCK_SIZE))
            {
                var_0 = 13 - (((BLOCK_SIZE * 7 + HALF_BLOCK_SIZE) - gBg3VOFS_NonGameplay) >> 5);
                var_1 = 13 - (((BLOCK_SIZE * 7 + HALF_BLOCK_SIZE) - TITLE_SCREEN_DATA.unk_24) >> 5);
                src = (void*)sEwramPointer;
            }
        }
    }

    if (var_0 < 14u && var_0 != var_1)
    {
        var_0 *= 0x400;
        DmaTransfer(3, src + var_0, VRAM_BASE + 0x4000 + var_0, 0x400, 16);
    }
}

/**
 * @brief 76d90 | 88 | Processes the comets and the sparkles
 * 
 */
void TitleScreenProcessOAM(void)
{
    if (TITLE_SCREEN_DATA.type & TITLE_SCREEN_TYPE_TOP_SPARKLE_ACTIVE)
        TitleScreenProcessTopSparkle(&TITLE_SCREEN_DATA.oamTimings[0], &TITLE_SCREEN_DATA.oam[5]);
    else if (TITLE_SCREEN_DATA.type & TITLE_SCREEN_TYPE_FIRST_COMET_ACTIVE)
        TitleScreenProcessComets(&TITLE_SCREEN_DATA.oamTimings[0], &TITLE_SCREEN_DATA.oam[5], 0);

    if (TITLE_SCREEN_DATA.type & TITLE_SCREEN_TYPE_BOTTOM_SPARKLE_ACTIVE)
    {
        if (TitleScreenProcessBottomSparkle(&TITLE_SCREEN_DATA.oamTimings[1], &TITLE_SCREEN_DATA.oam[6]))
        {
            UpdateMenuOamDataID(&TITLE_SCREEN_DATA.oam[5], TITLE_SCREEN_OAM_ID_SPARKLE_GROWING);
            UpdateMenuOamDataID(&TITLE_SCREEN_DATA.oam[6], TITLE_SCREEN_OAM_ID_SPARKLE_GROWING);
        }
    }
    else if (TITLE_SCREEN_DATA.type & TITLE_SCREEN_TYPE_SECOND_COMET_ACTIVE)
        TitleScreenProcessComets(&TITLE_SCREEN_DATA.oamTimings[1], &TITLE_SCREEN_DATA.oam[6], 1);
}

/**
 * @brief 76e18 | 174 | Processes a comet
 * 
 * @param pTiming OAM Timing pointer
 * @param pOam Menu OAM pointer
 * @param cometNumber Comet number
 */
void TitleScreenProcessComets(struct TitleScrenOamTiming* pTiming, struct MenuOamData* pOam, u8 cometNumber)
{
    u32 movement;
    u32 xLimit;
    u32 yLimit;

    pTiming->timer++;
    
    switch (pTiming->stage)
    {
        case 0:
            // Set starting position
            if (cometNumber == 0)
            {
                pOam->yPosition = BLOCK_SIZE * 2;
                pOam->xPosition = BLOCK_SIZE * 8;
            }
            else
            {
                pOam->yPosition = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
                pOam->xPosition = BLOCK_SIZE * 13 + 8;
            }

            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->oamID = TITLE_SCREEN_OAM_ID_COMET_SPAWNING;

            pOam->exists = TRUE;
            pOam->boundBackground = 3;
            pOam->notDrawn = FALSE;

            pTiming->stage++;
            pTiming->timer = 0;
            break;

        case 1:
            // Wait
            if (pTiming->timer > 20)
            {
                pOam->oamID = TITLE_SCREEN_OAM_ID_COMET_APPEARING;
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 2:
            // Wait for animation to end
            if (pOam->oamID == TITLE_SCREEN_OAM_ID_COMET_FLYING)
            {
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 3:
            movement = pTiming->timer + 8;

            // Move comet
            pOam->xPosition -= movement;
            pOam->yPosition += movement;

            // Check out of bounds
            yLimit = pOam->yPosition - (s16)gBg3VOFS_NonGameplay;
            xLimit = pOam->xPosition - (s16)gBg3HOFS_NonGameplay;

            pOam->notDrawn = FALSE;

            if (yLimit + BLOCK_SIZE * 2 > BLOCK_SIZE * 14)
                pOam->notDrawn = TRUE;

            if (xLimit + BLOCK_SIZE * 2 > BLOCK_SIZE * 19)
                pOam->notDrawn = TRUE;

            if (pOam->notDrawn)
            {
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 4:
            // Set comet to be inactive
            TITLE_SCREEN_DATA.type ^= sTitleScreenCometsFlags[cometNumber][0]; // Active flag
            TITLE_SCREEN_DATA.type |= sTitleScreenCometsFlags[cometNumber][1]; // Ended flag
            break;

        default:
            TITLE_SCREEN_DATA.type &= ~sTitleScreenCometsFlags[cometNumber][0];
            pOam->notDrawn = TRUE;
            break;
    }
}

/**
 * @brief 76f8c | 88 | Processes the top sparkle
 * 
 * @param pTiming OAM Timing pointer
 * @param pOam Menu OAM pointer
 */
void TitleScreenProcessTopSparkle(struct TitleScrenOamTiming* pTiming, struct MenuOamData* pOam)
{
    pTiming->timer++;

    switch (pTiming->stage)
    {
        case 0:
            // Initialize OAM
            DmaTransfer(3, &sTitleScreenTopSparkleBaseOam, pOam, sizeof(sTitleScreenTopSparkleBaseOam), 16);
            pTiming->stage++;
            pTiming->timer = 0;
            break;

        case 1:
            // Wait
            if (pTiming->timer > TITLE_SCREEN_SPARKLE_DELAY)
            {
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 2:
            // Move to the right
            pOam->xPosition += 12;

            // Check animation has ended
            if (pOam->oamID == 0)
            {
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 3:
            // Set sparkle to be inactive
            TITLE_SCREEN_DATA.type ^= TITLE_SCREEN_TYPE_TOP_SPARKLE_ACTIVE;
            TITLE_SCREEN_DATA.type |= TITLE_SCREEN_TYPE_TOP_SPARKLE_ENDED;
    }
}

/**
 * @brief 77014 | e4 | Processes the bottom sparkle
 * 
 * @param pTiming OAM Timing pointer
 * @param pOam Menu OAM pointer
 * @return u32 bool, OAM id update needed
 */
u32 TitleScreenProcessBottomSparkle(struct TitleScrenOamTiming* pTiming, struct MenuOamData* pOam)
{
    u32 idUpdate;

    idUpdate = FALSE;

    pTiming->timer++;
    switch (pTiming->stage)
    {
        case 0:
            // Initialize OAM
            DmaTransfer(3, &sTitleScreenBottomSparkleBaseOam, pOam, sizeof(sTitleScreenBottomSparkleBaseOam), 0x10);
            pTiming->stage++;
            pTiming->timer = 0;
            break;

        case 1:
            // Wait
            if (pTiming->timer > TITLE_SCREEN_SPARKLE_DELAY)
            {
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;
        
        case 2:
            // Move to the left
            pOam->xPosition -= PIXEL_SIZE * 3;
            if (pOam->xPosition <= BLOCK_SIZE * 11 + HALF_BLOCK_SIZE)
            {
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 3:
            // Move down
            pOam->yPosition += PIXEL_SIZE * 2;
            if (pOam->yPosition >= BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE * 3)
            {
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 4:
            // Move to the left
            pOam->xPosition -= PIXEL_SIZE * 3;
            if (pOam->xPosition <= BLOCK_SIZE * 10)
            {
                // Flag an OAM id update for both sparkles 
                idUpdate = TRUE;
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 5:
            // Move to the left
            pOam->xPosition -= PIXEL_SIZE * 3;
            // Check animation has ended
            if (pOam->oamID == 0)
            {
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 6:
            // Set sparkle to be inactive
            TITLE_SCREEN_DATA.type ^= TITLE_SCREEN_TYPE_BOTTOM_SPARKLE_ACTIVE;
            TITLE_SCREEN_DATA.type |= TITLE_SCREEN_TYPE_BOTTOM_SPARKLE_ENDED;
    }

    return idUpdate;
}

/**
 * @brief 770f8 | a8 | Checks if a demo should play
 * 
 * @return s8 0 = Nothing, 1 = Input, 2 = Demo start
 */
s8 TitleScreenCheckPlayEffects(void)
{
    TITLE_SCREEN_DATA.demoTimer++;
    if (TITLE_SCREEN_DATA.demoTimer > 60 * 17)
        return 2;

    TITLE_SCREEN_DATA.effectsTimer++;
    if ((TITLE_SCREEN_DATA.type & TITLE_SCREEN_TYPE_ALL_SPARKLES_ENDED) == TITLE_SCREEN_TYPE_ALL_SPARKLES_ENDED)
    {
        // Restart timer
        TITLE_SCREEN_DATA.effectsTimer = 0;
        TITLE_SCREEN_DATA.type ^= TITLE_SCREEN_TYPE_ALL_SPARKLES_ENDED;
    }
    else if (TITLE_SCREEN_DATA.effectsTimer == 60 * 4)
    {
        // Start title animated palette
        TITLE_SCREEN_DATA.activeAnimatedPalettes |= TITLE_SCREEN_ANIMATED_PALETTE_TITLE;
    }
    else if (TITLE_SCREEN_DATA.effectsTimer == 60 * 6)
    {
        // Start sparkles
        TITLE_SCREEN_DATA.type |= TITLE_SCREEN_TYPE_TOP_SPARKLE_ACTIVE | TITLE_SCREEN_TYPE_BOTTOM_SPARKLE_ACTIVE;
        TITLE_SCREEN_DATA.oamTimings[0].stage = 0;
        TITLE_SCREEN_DATA.oamTimings[0].timer = 0;
        TITLE_SCREEN_DATA.oamTimings[1].stage = 0;
        TITLE_SCREEN_DATA.oamTimings[1].timer = 0;
    }

    if (!TITLE_SCREEN_DATA.unk_F)
    {
        if (TITLE_SCREEN_DATA.timer > 30)
            TITLE_SCREEN_DATA.unk_F = TRUE;
    }
    else if (gChangedInput & (KEY_A | KEY_START))
        return 1;

    return 0;
}

/**
 * @brief 771a0 | 178 | Subroutine for the title screen
 * 
 * @return u32 bool, leaving
 */
u32 TitleScreenSubroutine(void)
{
    u32 leaving;
    u32 ret;

    leaving = FALSE;
    TITLE_SCREEN_DATA.timer++;

    switch (gGameModeSub1)
    {
        case 0:
            TitleScreenInit();
            gGameModeSub1 = 1;
            TITLE_SCREEN_DATA.timer = 0;
            break;

        case 1:
            unk_767a4();
            if (TitleScreenFadingIn())
            {
                UpdateMusicPriority(2);
                PlayMusic(MUSIC_TITLE_SCREEN, 2);
                TITLE_SCREEN_DATA.timer = 0;
                gGameModeSub1++;
            }
            break;

        case 2:
            ret = TitleScreenIdle();
            gGameModeSub2 = ret;
            if (gGameModeSub2 != 0)
            {
                TITLE_SCREEN_DATA.timer = 0;
                if (gGameModeSub2 == 2)
                    UpdateMusicPriority(4);
                else
                {
                    SoundPlay(SOUND_TITLE_SCREEN_PRESSING_START);
                    TITLE_SCREEN_DATA.animatedPalettes[2] = sTitleScreenAnimatedPaletteTemplates[3];
                }
                gGameModeSub1 = 3;

                if (TITLE_SCREEN_DATA.animatedPalettes[1].unk_4 != 0)
                    TITLE_SCREEN_DATA.animatedPalettes[1].unk_4 = 1;

                gDemoState = DEMO_STATE_NONE;
            }

            TitleScreenUpdateAnimatedPalette();
            TitleScreenProcessOAM();
            break;

        case 3:
            TitleScreenUpdateAnimatedPalette();
            TitleScreenProcessOAM();

            if (TITLE_SCREEN_DATA.animatedPalettes[2].paletteRow == 0 && TITLE_SCREEN_DATA.timer > 40)
            {
                unk_76710(TRUE);
                gGameModeSub1++;
                TITLE_SCREEN_DATA.timer = 0;
            }
            break;

        case 4:
            unk_767a4();
            if (TitleScreenFadingOut(1, 1))
                leaving = TRUE;
            break;

        case 5:
            break;
    }

    if (!leaving)
        TitleScreenCallProcessOAM();

    return leaving;
}

/**
 * @brief 77318 | b0 | Handles the title screen being idle
 * 
 * @return u32 0 = Nothing, 1 = Input, 2 = Demo start
 */
u32 TitleScreenIdle(void)
{
    u32 ret;

    ret = 0;

    switch (TITLE_SCREEN_DATA.oamTimings[2].stage)
    {
        case TITLE_SCREEN_IDLE_STAGE_COMETS:
            if (TITLE_SCREEN_DATA.unk_E != 0)
            {
                if (unk_76a98())
                    TitleScreenSetIdleStage(TITLE_SCREEN_IDLE_STAGE_IDLE);
            }
            else
            {
                if (TitleScreenCometsView())
                    TitleScreenSetIdleStage(TITLE_SCREEN_IDLE_STAGE_TITLE_FADING);
            }
            break;

        case TITLE_SCREEN_IDLE_STAGE_TITLE_FADING:
            if (gChangedInput != KEY_NONE)
            {
                gWrittenToBLDALPHA_L = 16;
                gWrittenToBLDALPHA_H = 0;
            }
            else if (TITLE_SCREEN_DATA.timer % 10 == 0)
            {
                if (gWrittenToBLDALPHA_L >= 16)
                {
                    TitleScreenSetIdleStage(TITLE_SCREEN_IDLE_STAGE_IDLE);
                    break;
                }
                
                gWrittenToBLDALPHA_L++;
                gWrittenToBLDALPHA_H = 16 - gWrittenToBLDALPHA_L;
            }

            if (gWrittenToBLDALPHA_L >= 16)
                TitleScreenSetIdleStage(TITLE_SCREEN_IDLE_STAGE_IDLE);
            break;

        case TITLE_SCREEN_IDLE_STAGE_IDLE:
            ret = TitleScreenCheckPlayEffects();
    }

    return ret;
}

/**
 * @brief 773c8 | 94 | Sets the idle stage for the title screen
 * 
 * @param stage 
 */
void TitleScreenSetIdleStage(u8 stage)
{
    TITLE_SCREEN_DATA.oamTimings[2].stage = stage;

    switch (TITLE_SCREEN_DATA.oamTimings[2].stage)
    {
        case 1:
            TITLE_SCREEN_DATA.dispcnt |= sTitleScreenPageData[1].bg | sTitleScreenPageData[0].bg;

            TITLE_SCREEN_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG0_SECOND_TARGET_PIXEL |
                BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL |
                BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            TITLE_SCREEN_DATA.timer = 0;
            gWrittenToBLDALPHA_L = 0;
            gWrittenToBLDALPHA_H = 16;
            break;

        case 2:
            TITLE_SCREEN_DATA.dispcnt |= sTitleScreenPageData[1].bg | sTitleScreenPageData[0].bg;

            TITLE_SCREEN_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG0_SECOND_TARGET_PIXEL |
                BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL |
                BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            TITLE_SCREEN_DATA.effectsTimer = 210;
            TITLE_SCREEN_DATA.unk_F = FALSE;
            TITLE_SCREEN_DATA.timer = 0;
            break;
    }
}

/**
 * @brief 7745c | 2a0 | Initializes the title screen
 * 
 */
void TitleScreenInit(void)
{
    u32 zero;

    CallbackSetVBlank(TitleScreenVBlank_Empty);
    
    zero = 0;
    DMA_SET(3, &zero, &gNonGameplayRAM, (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | sizeof(gNonGameplayRAM) / 4);

    TITLE_SCREEN_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

    write16(REG_BLDCNT, TITLE_SCREEN_DATA.bldcnt);

    write16(REG_BLDY, gWrittenToBLDY_NonGameplay = BLDY_MAX_VALUE);

    write16(REG_DISPCNT, TITLE_SCREEN_DATA.dispcnt = 0);

    gNextOamSlot = 0;

    ClearGfxRam();
    ResetFreeOam();
    
    gOamXOffset_NonGameplay = gOamYOffset_NonGameplay = 0;

    zero = 0;
    DMA_SET(3, &zero, &gSamusPhysics, C_32_2_16(DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED, sizeof(gSamusPhysics) / sizeof(u32)));

    gSramErrorFlag = FALSE;
    gDebugFlag = FALSE;

    StopAllMusicsAndSounds();

    DmaTransfer(3, sTitleScreenPal, PALRAM_BASE, sizeof(sTitleScreenPal), 16);
    DmaTransfer(3, sTitleScreenPal, PALRAM_OBJ, sizeof(sTitleScreenPal), 16);

    SET_BACKDROP_COLOR(COLOR_BLACK);

    TitleScreenLoadPageData(&sTitleScreenPageData[0]);
    TitleScreenLoadPageData(&sTitleScreenPageData[1]);

    unk_777d8(2);

    CallLZ77UncompVram(sTitleScreenTitleGfx, VRAM_BASE + 0xC000);
    CallLZ77UncompVram(sTitleScreenSpaceBackgroundGfx, VRAM_BASE + 0x4000);
    CallLZ77UncompVram(sTitleScreenSpaceBackgroundDecorationGfx, VRAM_BASE + 0xA400);
    CallLZ77UncompWram(sTitleScreenSpaceAndGroundBackgroundGfx, (void*)sEwramPointer + 0x4000);

    DmaTransfer(3, VRAM_BASE + 0x4000, (void*)sEwramPointer, 0x4000, 16);

    CallLZ77UncompVram(sTitleScreenSparklesGfx, VRAM_OBJ);

    // Undefined
    TitleScreenSetBGCNTPageData(&sTitleScreenPageData[0]);
    TitleScreenSetBGCNTPageData(&sTitleScreenPageData[1]);

    gGameModeSub3 = 0;
    gBg0HOFS_NonGameplay = gBg0VOFS_NonGameplay = 0;
    gBg1HOFS_NonGameplay = gBg1VOFS_NonGameplay = 0;
    gBg2HOFS_NonGameplay = gBg2VOFS_NonGameplay = 0;
    gBg3HOFS_NonGameplay = gBg3VOFS_NonGameplay = 0;

    gWrittenToBLDALPHA_H = 16;
    gWrittenToBLDALPHA_L = 0;

    TITLE_SCREEN_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET;

    TITLE_SCREEN_DATA.demoTimer = 0;

    if (gGameModeSub2 == 0)
    {
        TITLE_SCREEN_DATA.oamTimings[2].stage = TITLE_SCREEN_IDLE_STAGE_COMETS;
    }
    else
    {
        unk_76978(UCHAR_MAX);
        TITLE_SCREEN_DATA.oamTimings[2].stage = TITLE_SCREEN_IDLE_STAGE_IDLE;

        TITLE_SCREEN_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET;
        
        gWrittenToBLDALPHA_L = 16;
        gWrittenToBLDALPHA_H = 0;

        TITLE_SCREEN_DATA.effectsTimer = 210;
        TITLE_SCREEN_DATA.unk_F = FALSE;
        TITLE_SCREEN_DATA.timer = 0;
    }

    TitleScreenResetOAM();
    TitleScreenCallProcessOAM();
    TitleScreenVBlank();
    unk_76710(FALSE);

    // Set active animated palettes
    TITLE_SCREEN_DATA.activeAnimatedPalettes = TITLE_SCREEN_ANIMATED_PALETTE_SKY_DECORATIONS | TITLE_SCREEN_ANIMATED_PALETTE_PROMPT;

    TITLE_SCREEN_DATA.animatedPalettes[0] = sTitleScreenAnimatedPaletteTemplates[0];
    TITLE_SCREEN_DATA.animatedPalettes[1] = sTitleScreenAnimatedPaletteTemplates[1];
    TITLE_SCREEN_DATA.animatedPalettes[2] = sTitleScreenAnimatedPaletteTemplates[2];

    write16(REG_DISPCNT, TITLE_SCREEN_DATA.dispcnt = DCNT_OBJ | sTitleScreenPageData[0].bg | sTitleScreenPageData[1].bg);

    CallbackSetVBlank(TitleScreenVBlank);
}

/**
 * @brief 776fc | d0 | Title screen V-blank code
 * 
 */
void TitleScreenVBlank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16(DMA_ENABLE | DMA_32BIT, OAM_SIZE / sizeof(u32)));

    write16(REG_BG0HOFS, SUB_PIXEL_TO_PIXEL(gBg0HOFS_NonGameplay));
    write16(REG_BG0VOFS, SUB_PIXEL_TO_PIXEL(gBg0VOFS_NonGameplay));

    write16(REG_BG1HOFS, SUB_PIXEL_TO_PIXEL(gBg1HOFS_NonGameplay));
    write16(REG_BG1VOFS, SUB_PIXEL_TO_PIXEL(gBg1VOFS_NonGameplay));

    write16(REG_BG2HOFS, SUB_PIXEL_TO_PIXEL(gBg2HOFS_NonGameplay));
    write16(REG_BG2VOFS, SUB_PIXEL_TO_PIXEL(gBg2VOFS_NonGameplay));

    write16(REG_BG3HOFS, SUB_PIXEL_TO_PIXEL(gBg3HOFS_NonGameplay));
    write16(REG_BG3VOFS, SUB_PIXEL_TO_PIXEL(gBg3VOFS_NonGameplay));

    write16(REG_DISPCNT, TITLE_SCREEN_DATA.dispcnt);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);
    write16(REG_BLDALPHA, C_16_2_8(gWrittenToBLDALPHA_H, gWrittenToBLDALPHA_L));
    write16(REG_BLDCNT, TITLE_SCREEN_DATA.bldcnt);
}

/**
 * @brief 777cc | c | Empty v-blank for the title screen
 * 
 */
void TitleScreenVBlank_Empty(void)
{
    vu8 c = 0;
}

/**
 * @brief 777d8 | 4c | To document
 * 
 * @param param_1 To document
 */
void unk_777d8(u8 param_1)
{
    s32 i;
    u32 value;
    u32 bgOffset;
    u16* dst;
    u32 mask;
    u32 temp;

    bgOffset = sTitleScreenPageData[0].tiletablePage * 2048;

    if (param_1 == 0)
        return;

    if (param_1 == 2)
        temp = 0x12D;
    else
        temp = 0x10D;
    value = temp;
    
    i = 0;
    mask = 0xFC00;
    dst = VRAM_BASE + 0x178 + bgOffset;

    while (i < 2)
    {
        *dst++ = (*dst & mask) | (value + i);

        i++;
    }
}

/**
 * @brief 77824 | a0 | Unknown (probably some tilemap manipulation)
 * 
 * @param param_1 Source pointer?
 * @param param_2 Destination pointer
 * @param param_3 Palette?
 */
void unk_77824(u8* param_1, u16* dst, u8 palette)
{
    u16 var_0;

    while (*param_1)
    {
        if (*param_1 != 0x20)
        {
            if ((u8)(*param_1 - 0x30) < 10)
                var_0 = *param_1 - 0x30;
            else if ((u8)(*param_1 - 0x41) < 26)
                var_0 = *param_1 + -0x37;
            else if (*param_1 == 0x3A)
                var_0 = 0x24;
            else if (*param_1 == 0x5F)
                var_0 = 0x25;
            else if (*param_1 == 0x2F)
                var_0 = 0x26;
            else if ((u8)(*param_1 - 0x61) < 26)
                var_0 = *param_1 + -0x57;
            else
                var_0 = 0x8000;
        }
        else
            var_0 = 0x8000;

        if (var_0 != 0x8000)
        {
            *dst = (palette << 12) | (var_0 + 0x1C0);
        }

        dst++;
        param_1++;
    }
}
