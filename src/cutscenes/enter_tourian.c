#include "cutscenes/enter_tourian.h"
#include "cutscenes/cutscene_utils.h"
#include "color_effects.h"
#include "macros.h"

#include "data/shortcut_pointers.h"
#include "data/generic_data.h"
#include "data/cutscenes/enter_tourian_data.h"
#include "data/cutscenes/internal_enter_tourian_data.h"
#include "data/sprites/metroid.h"

#include "constants/audio.h"
#include "constants/cutscene.h"
#include "constants/game_state.h"

#include "structs/game_state.h"
#include "structs/display.h"

/**
 * @brief 67080 | 310 | Handles the entire cutscene
 * 
 * @return u8 FALSE
 */
u8 EnterTourianAnimation(void)
{
    s32 i;
    s32 movement;
    u32 flag;

    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            if (unk_61f44())
            {
                SoundPlay(0x295);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 1:
            if (!CUTSCENE_DATA.unk_A)
            {
                CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt, 0, 8, 1);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            else
                CUTSCENE_DATA.timeInfo.timer = 0;
            break;

        case 2:
            if (CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_SPRITE_ENDED)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer == 8)
            {
                CUTSCENE_DATA.oam[1].actions |= 2;
                SoundPlay(0x296);
            }
            else if (CUTSCENE_DATA.timeInfo.timer == 90)
            {
                CUTSCENE_DATA.oam[3].actions |= 2;
            }
            else if (CUTSCENE_DATA.timeInfo.timer == 100)
            {
                CUTSCENE_DATA.oam[5].actions |= 2;
                CUTSCENE_DATA.oam[8].actions |= 2;
            }
            else if (CUTSCENE_DATA.timeInfo.timer >= 120)
            {
                CUTSCENE_DATA.oam[7].actions |= 2;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.timeInfo.timer > 300)
            {
                CUTSCENE_DATA.oam[1].oamID++;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 5:
            if (CUTSCENE_DATA.oam[1].ended || CUTSCENE_DATA.timeInfo.timer > 300)
            {
                CUTSCENE_DATA.oam[1].actions &= ~4;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 6:
            if (CUTSCENE_DATA.timeInfo.timer > 60)
            {
                SoundPlay(0x297);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 7:
            gCurrentOamScaling += Q_8_8(.035f);

            if (gCurrentOamScaling > Q_8_8(2.f))
            {
                gCurrentOamScaling = Q_8_8(2.f);

                CutsceneStartBackgroundFading(8);

                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }

            if (CUTSCENE_DATA.oam[1].currentAnimationFrame != 6)
            {
                CUTSCENE_DATA.oam[1].oamID = 5;

                if (gCurrentOamScaling > Q_8_8(1.625f))
                    CUTSCENE_DATA.oam[1].currentAnimationFrame = 6;
            }

            if (gCurrentOamScaling > Q_8_8(1.69f))
                movement = -(PIXEL_SIZE + PIXEL_SIZE / 2);
            else
                movement = QUARTER_BLOCK_SIZE - DIV_SHIFT(gCurrentOamScaling, BLOCK_SIZE);

            CUTSCENE_DATA.oam[1].yPosition += movement;
            break;

        case 8:
            if (unk_61f44())
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 9:
            unk_61f0c();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    EnterTourianScrollBackground();

    for (i = 1; i < 8; i += 2)
        EnterTourianUpdateMetroid(&CUTSCENE_DATA.oam[i], (i - 1) / 2);

    flag = FALSE;
    for (i = 1; i < 8; i += 2)
    {
        if (CUTSCENE_DATA.oam[i].actions & 1)
        {
            flag = TRUE;
            break;
        }
    }

    EnterTourianSwitchMetroidPalette(&CUTSCENE_DATA.paletteData[0], movement = flag);
    CUTSCENE_DATA.oam[8].actions |= movement;
    EnterTourianUpdatePirate(&CUTSCENE_DATA.oam[8]);

    return FALSE;
}

/**
 * @brief 67390 | 50 | Handles the movement of the backgrounds
 * 
 */
void EnterTourianScrollBackground(void)
{
    u16* pPosition;

    if (!CUTSCENE_DATA.unk_A)
        return;

    pPosition = CutsceneGetBgHorizontalPointer(sEnterTourianPageData[1].bg);
    if (*pPosition > BLOCK_SIZE * 21 + HALF_BLOCK_SIZE)
        *pPosition -= PIXEL_SIZE / 2;

    if (*pPosition <= BLOCK_SIZE * 21 + HALF_BLOCK_SIZE)
        CUTSCENE_DATA.unk_A = FALSE;

    pPosition = CutsceneGetBgHorizontalPointer(sEnterTourianPageData[0].bg);
    *pPosition -= ONE_SUB_PIXEL;
}

/**
 * @brief 673e0 | 378 | Updates a metroid
 * 
 * @param pOam Cutscene oam data pointer
 * @param metroidId Metroid oam
 */
void EnterTourianUpdateMetroid(struct CutsceneOamData* pOam, u8 metroidId)
{
    u32 position;
    u32 notDrawn;
    s32 var_0;
    struct CutsceneOamData* pShell;
    s32 var_1;
    s32 var_2;
    s32 var_3;

    pShell = pOam - 1;

    if (pOam->actions & 2)
    {
        UpdateCutsceneOamDataID(pOam, 3);
        pOam->actions &= ~1;
        pOam->actions ^= 2;
        pOam->actions |= 4;
        pOam->timer = 0;
    }

    if (pOam->actions & 1)
    {
        if (pOam->timer != USHORT_MAX)
            pOam->timer++;

        if (pOam->unk_16 != 0)
        {
            pOam->unk_16--;
        }
        else
        {
            if (pOam->xVelocity != 0)
            {
                pOam->xPosition -= pOam->xVelocity;
                pOam->xVelocity = 0;

            }
            else
            {
                pOam->xVelocity = sRandomNumberTable[(pOam->timer + metroidId) & 0xFF] & 1 ? -4 : 4;
                pOam->xPosition += pOam->xVelocity;
            }
            pOam->unk_16 = (sRandomNumberTable[(pOam->timer - metroidId) & 0xFF] & 0x1F) + 8;
        }

        if (pOam->unk_18 != 0)
        {
            pOam->unk_18--;
        }
        else
        {
            if (pOam->yVelocity != 0)
            {
                pOam->yPosition -= pOam->yVelocity;
                pOam->yVelocity = 0;
            }
            else
            {
                pOam->yVelocity = sRandomNumberTable[(pOam->timer + metroidId) & 0xFF] & 2 ? -4 : 4;
                pOam->yPosition += pOam->yVelocity;
            }
            
            pOam->unk_18 = (sRandomNumberTable[(pOam->timer - metroidId) & 0xFF] & 0x3F) + 8;

            if (pOam->unk_18 == pOam->unk_16)
                pOam->unk_18 += 16;
        }
    }
    else if (pOam->actions & 4)
    {
        if (pOam->timer != USHORT_MAX)
            pOam->timer++;

        if (metroidId == 0)
            var_0 = 0xB4;
        else
            var_0 = 0x3C;

        if (pOam->timer < var_0)
        {
            var_1 = 1;
            var_0 = 2;
        }
        else
        {
            var_1 = 2;
            var_0 = 1;
        }

        pOam->unk_16++;
        if (pOam->xVelocity == 0)
        {
            pOam->xVelocity = sEnterTourian_7600b4[metroidId][0] - pOam->xPosition;

            var_2 = MOD_AND(sRandomNumberTable[LOW_BYTE(pOam->timer * metroidId)], 2) ? 1 : -1;
            var_2 *= MOD_AND(sRandomNumberTable[LOW_BYTE(pOam->timer + metroidId)], 4);

            if (pOam->xVelocity > 0)
                pOam->xVelocity = var_2 * 4 + 0x20;
            else
                pOam->xVelocity = var_2 * 4 - 0x20;
        }
        else
        {
            if (pOam->xVelocity > 0)
            {
                if (sEnterTourian_7600b4[metroidId][0] <= pOam->xPosition)
                    pOam->xVelocity -= 2;

                var_2 = pOam->xVelocity / 12 + 1;
                if (var_2 > var_1)
                    var_2 = var_1;
            }
            else
            {
                if (sEnterTourian_7600b4[metroidId][0] >= pOam->xPosition)
                    pOam->xVelocity += 2;

                var_2 = pOam->xVelocity / 12 - 1;
                if (var_2 < -var_1)
                    var_2 = -var_1;
            }

            pOam->xPosition += var_2;
        }

        pOam->unk_18++;
        if (pOam->yVelocity == 0)
        {
            var_2 = sRandomNumberTable[LOW_BYTE(pOam->animationDurationCounter + pOam->currentAnimationFrame)] & 2 ? 1 : -1;
            var_2 *= sRandomNumberTable[LOW_BYTE(pOam->timer + metroidId)] & 1;

            if (sEnterTourian_7600b4[metroidId][1] < pOam->yPosition)
                pOam->yVelocity = sEnterTourian_7600b4[metroidId][1] - PIXEL_TO_SUB_PIXEL(var_2 + PIXEL_SIZE)- pOam->yPosition;
            else
                pOam->yVelocity = sEnterTourian_7600b4[metroidId][1] + PIXEL_TO_SUB_PIXEL(var_2 + PIXEL_SIZE)- pOam->yPosition;
        }
        else if (pOam->unk_18 & 1)
        {
            if (pOam->yVelocity > 0)
                pOam->yVelocity--;
            else
                pOam->yVelocity++;

            var_3 = pOam->yPosition;
            if (pOam->yVelocity <= 0)
                pOam->yPosition = var_3 - var_0;
            else
                pOam->yPosition = var_3 + var_0;
        }
    }

    pShell->yPosition = pOam->yPosition;
    pShell->xPosition = pOam->xPosition;
    
    position = *CutsceneGetBgHorizontalPointer(sEnterTourianPageData[0].bg);
    var_2 = position - pOam->xPosition;
    position = var_2 + 0x7DF;

    if (position < 0xBDF)
        var_2 = FALSE;
    else
        var_2 = TRUE;

    pOam->notDrawn = var_2;
    pShell->notDrawn = var_2;
}

/**
 * @brief 67758 | 8c | Updates the metroid palette
 * 
 * @param pPalette Cutscene palette data pointer
 * @param grabbedPal bool, use grabbed pal
 */
void EnterTourianSwitchMetroidPalette(struct CutscenePaletteData* pPalette, u8 grabbedPal)
{
    if (grabbedPal == TRUE)
    {
        if (pPalette->active)
        {
            pPalette->active = TRUE;
            pPalette->timer = 0;
            pPalette->paletteRow = 0;
            pPalette->maxTimer = 32;
            return;
        }

        if (pPalette->timer != 0)
        {
            pPalette->timer--;
            return;
        }

        pPalette->timer = pPalette->maxTimer;
        pPalette->paletteRow++;

        if (pPalette->paletteRow >= ARRAY_SIZE(sMetroidPal_SamusGrabbed) / 16)
            pPalette->paletteRow = 0;

        DmaTransfer(3, &sMetroidPal_SamusGrabbed[pPalette->paletteRow * 16], PALRAM_BASE + 0x380, 32, 0x10);
        return;
    }

    if (pPalette->active)
    {
        pPalette->active = FALSE;
        DmaTransfer(3, &sMetroidOAM_Moving_Frame10[8], PALRAM_BASE + 0x380, 32, 0x10);
    }
}

/**
 * @brief 677e4 | 168 | Updates the pirate
 * 
 * @param pOam Cutscene oam data pointer
 */
void EnterTourianUpdatePirate(struct CutsceneOamData* pOam)
{
    u32 position;
    u32 notDrawn;

    if (pOam->actions & 1)
    {
        if (pOam->unk_16 != 0)
            pOam->unk_16--;
        else
        {
            if (pOam->xVelocity != 0)
            {
                pOam->xPosition -= pOam->xVelocity;
                pOam->xVelocity = 0;
            }
            else
            {
                pOam->xVelocity = sRandomNumberTable[gFrameCounter8Bit] & 1 ? -4 : 4;
                pOam->xPosition += pOam->xVelocity;
            }

            pOam->unk_16 = sRandomNumberTable[gFrameCounter8Bit - 1] + 8;
        }

        if (pOam->unk_18 != 0)
            pOam->unk_18--;
        else
        {
            if (pOam->yVelocity != 0)
            {
                pOam->yPosition -= pOam->yVelocity;
                pOam->yVelocity = 0;
            }
            else
            {
                pOam->yVelocity = -4;
                pOam->yPosition += pOam->yVelocity;
            }

            pOam->unk_18 = (sRandomNumberTable[gFrameCounter8Bit] & 0x7F) + 8;

            if (pOam->unk_18 == pOam->unk_16)
                pOam->unk_18 += 16;
        }
    }

    if (pOam->actions & 2)
    {
        pOam->unk_1A++;
        if (pOam->unk_1A > 4)
        {
            pOam->unk_1A = 0;
            pOam->unk_12++;

            ApplySmoothPaletteTransition((void*)sEwramPointer + 0x280, (void*)sEwramPointer + 0x3AA0, PALRAM_BASE + 0x280, pOam->unk_12);
            if (pOam->unk_12 > 30)
                pOam->actions ^= 2;
        }
    }

    pOam->actions &= ~1;
    position = *CutsceneGetBgHorizontalPointer(sEnterTourianPageData[0].bg);
    notDrawn = position - pOam->xPosition;
    position = notDrawn + 0x5DF;

    if (position <= 0x6DE)
        notDrawn = FALSE;
    else
        notDrawn = TRUE;

    pOam->notDrawn = notDrawn;
}

/**
 * @brief 6794c | 3c0 | Initializes the enter tourian cutscene
 * 
 * @return u8 FALSE
 */
u8 EnterTourianInit(void)
{
    s32 i;

    unk_61f0c();
    DmaTransfer(3, sEnterTourianBackgroundPal, PALRAM_BASE, sizeof(sEnterTourianBackgroundPal), 0x10);
    SET_BACKDROP_COLOR(COLOR_BLACK);

    DmaTransfer(3, sEnterTourianMetroidPal, PALRAM_OBJ, sizeof(sEnterTourianMetroidPal), 0x10);
    DmaTransfer(3, sMetroidPal, PALRAM_BASE + 0x300, sizeof(sMetroidPal), 0x10);

    CallLZ77UncompVram(sEnterTourianDeadSpacePirateGfx_1, VRAM_OBJ);
    CallLZ77UncompVram(sEnterTourianDeadSpacePirateGfx_2, VRAM_BASE + 0x10400);
    CallLZ77UncompVram(sEnterTourianDeadSpacePirateGfx_3, VRAM_BASE + 0x10800);
    CallLZ77UncompVram(sMetroidGfx, VRAM_BASE + 0x14000);
    
    CallLZ77UncompVram(sEnterTourianBackgroundGfx, VRAM_BASE + sEnterTourianPageData[0].graphicsPage * 0x4000);
    CallLZ77UncompVram(sEnterTourianForegroundGfx, VRAM_BASE + sEnterTourianPageData[1].graphicsPage * 0x4000);

    CallLZ77UncompVram(sEnterTourianBackgroundTileTable, VRAM_BASE + sEnterTourianPageData[0].tiletablePage * 0x800);
    CallLZ77UncompVram(sEnterTourianForegroundTileTable, VRAM_BASE + sEnterTourianPageData[1].tiletablePage * 0x800);

    CutsceneSetBgcntPageData(sEnterTourianPageData[0]);
    CutsceneSetBgcntPageData(sEnterTourianPageData[1]);
    CutsceneReset();

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sEnterTourianPageData[0].bg, 0x800);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sEnterTourianPageData[1].bg, 0x800);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sEnterTourianPageData[0].bg, 0x950);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sEnterTourianPageData[1].bg, 0x800);

    CUTSCENE_DATA.oam[1].oamID = 6;
    CUTSCENE_DATA.oam[1].exists = TRUE;
    CUTSCENE_DATA.oam[1].boundBackground = 3;
    CUTSCENE_DATA.oam[1].priority = sEnterTourianPageData[0].priority;
    CUTSCENE_DATA.oam[1].actions = 1;

    CUTSCENE_DATA.oam[3] = CUTSCENE_DATA.oam[1];
    CUTSCENE_DATA.oam[5] = CUTSCENE_DATA.oam[1];
    CUTSCENE_DATA.oam[7] = CUTSCENE_DATA.oam[1];

    CUTSCENE_DATA.oam[1].rotationScaling = TRUE;

    CUTSCENE_DATA.oam[3].currentAnimationFrame = 2;
    CUTSCENE_DATA.oam[5].currentAnimationFrame = 4;
    CUTSCENE_DATA.oam[7].currentAnimationFrame = 8;

    
    CUTSCENE_DATA.oam[0].oamID = 2;
    CUTSCENE_DATA.oam[0].exists = TRUE;
    CUTSCENE_DATA.oam[0].boundBackground = 3;
    CUTSCENE_DATA.oam[0].priority = sEnterTourianPageData[0].priority;

    CUTSCENE_DATA.oam[2] = CUTSCENE_DATA.oam[0];
    CUTSCENE_DATA.oam[4] = CUTSCENE_DATA.oam[0];
    CUTSCENE_DATA.oam[6] = CUTSCENE_DATA.oam[0];

    CUTSCENE_DATA.oam[0].rotationScaling = TRUE;

    CUTSCENE_DATA.oam[2].currentAnimationFrame = 1;
    CUTSCENE_DATA.oam[4].currentAnimationFrame = 1;

    for (i = 0; i < 8; i++)
    {
        CUTSCENE_DATA.oam[i].xPosition = sEnterTourian_760090[i >> 1][0];
        CUTSCENE_DATA.oam[i].yPosition = sEnterTourian_760090[i >> 1][1];
    }

    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[8], 1);
    CUTSCENE_DATA.oam[8].boundBackground = 3;
    CUTSCENE_DATA.oam[8].priority = sEnterTourianPageData[0].priority;
    CUTSCENE_DATA.oam[8].actions = 1;
    CUTSCENE_DATA.oam[8].xPosition = sEnterTourian_760090[4][0];
    CUTSCENE_DATA.oam[8].yPosition = sEnterTourian_760090[4][1];

    CUTSCENE_DATA.bldcnt = BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;
    gWrittenToBLDY_NonGameplay = 16;
    CUTSCENE_DATA.unk_A = TRUE;

    PlayMusic(MUSIC_ENTERING_TOURIAN_CUTSCENE, 0);
    DmaTransfer(3, PALRAM_OBJ, (void*)sEwramPointer + 0x3A00, 0x200, 0x10);
    CutsceneStartBackgroundFading(3);

    CUTSCENE_DATA.dispcnt = DCNT_OBJ | sEnterTourianPageData[0].bg | sEnterTourianPageData[1].bg;
    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;
    CUTSCENE_DATA.timeInfo.stage++;

    return FALSE;
}

u8 EnterTourianSubroutine(void)
{
    u8 ended;

    ended = sEnterTourianSubroutineData[CUTSCENE_DATA.timeInfo.stage].pFunction();

    CutsceneUpdateBackgroundsPosition(TRUE);
    EnterTourianProcessOAM();

    return ended;
}

/**
 * @brief 67d40 | 4c | Processes the OAM for the cutscene
 * 
 */
void EnterTourianProcessOAM(void)
{
    gNextOamSlot = 0;
    ProcessCutsceneOam(sEnterTourianSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength,
        CUTSCENE_DATA.oam, sEnterTourianOam);
    ResetFreeOam();
    CalculateOamPart4(gCurrentOamRotation, gCurrentOamScaling, 0);
}
