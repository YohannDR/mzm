#include "cutscenes/enter_tourian.h"
#include "cutscenes/cutscene_utils.h"
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
    i32 i;
    i32 movement;
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
                CUTSCENE_DATA.oam[1].unk_D |= 2;
                SoundPlay(0x296);
            }
            else if (CUTSCENE_DATA.timeInfo.timer == 90)
            {
                CUTSCENE_DATA.oam[3].unk_D |= 2;
            }
            else if (CUTSCENE_DATA.timeInfo.timer == 100)
            {
                CUTSCENE_DATA.oam[5].unk_D |= 2;
                CUTSCENE_DATA.oam[8].unk_D |= 2;
            }
            else if (CUTSCENE_DATA.timeInfo.timer >= 120)
            {
                CUTSCENE_DATA.oam[7].unk_D |= 2;
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
                CUTSCENE_DATA.oam[1].unk_D &= ~4;
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
            gCurrentOamScaling += 8;
            if (gCurrentOamScaling > 0x200)
            {
                gCurrentOamScaling = 0x200;
                unk_61fa0(8);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }

            if (CUTSCENE_DATA.oam[1].currentAnimationFrame != 6)
            {
                CUTSCENE_DATA.oam[1].oamID = 5;
                if (gCurrentOamScaling > 0x1A0)
                    CUTSCENE_DATA.oam[1].currentAnimationFrame = 6;
            }

            if (gCurrentOamScaling > 0x1B0)
                movement = -6;
            else
                movement = 16 - (gCurrentOamScaling >> 6);
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
        if (CUTSCENE_DATA.oam[i].unk_D & 1)
        {
            flag = TRUE;
            break;
        }
    }

    EnterTourianSwitchMetroidPalette(&CUTSCENE_DATA.paletteData[0], movement = flag);
    CUTSCENE_DATA.oam[8].unk_D |= movement;
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

    pPosition = CutsceneGetBGHOFSPointer(sEnterTourianPageData[1].bg);
    if (*pPosition > BLOCK_SIZE * 21 + HALF_BLOCK_SIZE)
        (*pPosition) -= 2;

    if (*pPosition <= BLOCK_SIZE * 21 + HALF_BLOCK_SIZE)
        CUTSCENE_DATA.unk_A = FALSE;

    pPosition = CutsceneGetBGHOFSPointer(sEnterTourianPageData[0].bg);
    (*pPosition)--;
}

void EnterTourianUpdateMetroid(struct CutsceneOamData* pOam, u8 metroidId)
{

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

        if (pPalette->paletteRow >= ARRAY_SIZE(sMetroidPAL_SamusGrabbed) / 16)
            pPalette->paletteRow = 0;

        DMATransfer(3, &sMetroidPAL_SamusGrabbed[pPalette->paletteRow * 16], PALRAM_BASE + 0x380, 32, 0x10);
        return;
    }

    if (pPalette->active)
    {
        pPalette->active = FALSE;
        DMATransfer(3, &sMetroidOAM_Moving_Frame10[8], PALRAM_BASE + 0x380, 32, 0x10);
    }
}

void EnterTourianUpdatePirate(struct CutsceneOamData* pOam)
{
    // https://decomp.me/scratch/k9SZe

    u16 position;
    u8 notDrawn;
    i32 velocity;

    if (pOam->unk_D & 1)
    {
        if (pOam->unk_16 != 0)
            pOam->unk_16--;
        else
        {
            if (pOam->unk_E != 0)
            {
                pOam->xPosition -= pOam->unk_E;
                pOam->unk_E = 0;
            }
            else
            {
                if (sRandomNumberTable[gFrameCounter8Bit] & 1)
                    velocity = -4;
                else
                    velocity = 4;

                pOam->unk_E = velocity;
                pOam->xPosition += pOam->unk_E;
            }

            pOam->unk_16 = sRandomNumberTable[gFrameCounter8Bit - 1] + 8;
        }

        if (pOam->unk_18 != 0)
            pOam->unk_18--;
        else
        {
            if (pOam->unk_10 != 0)
            {
                pOam->yPosition -= pOam->unk_10;
                pOam->unk_10 = 0;
            }
            else
            {
                pOam->unk_10 = -4;
                pOam->yPosition += pOam->unk_10;
            }

            pOam->unk_18 = (sRandomNumberTable[gFrameCounter8Bit] & 0x7F) + 8;

            if (pOam->unk_18 == pOam->unk_16)
                pOam->unk_18 += 16;
        }
    }

    if (pOam->unk_D & 2)
    {
        pOam->unk_1A++;
        if (pOam->unk_1A > 4)
        {
            pOam->unk_1A = 0;
            pOam->unk_12++;

            velocity = 0x3AA0;
            ApplySmoothPaletteTransition(sEwramPointer + 0x280, sEwramPointer + velocity, PALRAM_BASE + 0x280, pOam->unk_12);
            if (pOam->unk_12 > 30)
                pOam->unk_D ^= 2;
        }
    }

    pOam->unk_D &= ~1;
    position = *CutsceneGetBGHOFSPointer(sEnterTourianPageData[0].bg);

    if (position - pOam->xPosition + 0x5DF < 0x6DE)
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
    i32 i;

    unk_61f0c();
    DMATransfer(3, sEnterTourianBackgroundPAL, PALRAM_BASE, sizeof(sEnterTourianBackgroundPAL), 0x10);
    write16(PALRAM_BASE, 0);

    DMATransfer(3, sEnterTourianMetroidPAL, PALRAM_BASE + 0x200, sizeof(sEnterTourianMetroidPAL), 0x10);
    DMATransfer(3, sMetroidPAL, PALRAM_BASE + 0x300, sizeof(sMetroidPAL), 0x10);

    CallLZ77UncompWRAM(sEnterTourianDeadSpacePirateGFX_1, VRAM_BASE + 0x10000);
    CallLZ77UncompWRAM(sEnterTourianDeadSpacePirateGFX_2, VRAM_BASE + 0x10400);
    CallLZ77UncompWRAM(sEnterTourianDeadSpacePirateGFX_3, VRAM_BASE + 0x10800);
    CallLZ77UncompWRAM(sMetroidGFX, VRAM_BASE + 0x14000);
    
    CallLZ77UncompWRAM(sEnterTourianBackgroundGFX, VRAM_BASE + sEnterTourianPageData[0].graphicsPage * 0x4000);
    CallLZ77UncompWRAM(sEnterTourianForegroundGFX, VRAM_BASE + sEnterTourianPageData[1].graphicsPage * 0x4000);

    CallLZ77UncompWRAM(sEnterTourianBackgroundTileTable, VRAM_BASE + sEnterTourianPageData[0].tiletablePage * 0x800);
    CallLZ77UncompWRAM(sEnterTourianForegroundTileTable, VRAM_BASE + sEnterTourianPageData[1].tiletablePage * 0x800);

    CutsceneSetBGCNTPageData(sEnterTourianPageData[0]);
    CutsceneSetBGCNTPageData(sEnterTourianPageData[1]);
    CutsceneReset();

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sEnterTourianPageData[0].bg, 0x800);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sEnterTourianPageData[1].bg, 0x800);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sEnterTourianPageData[0].bg, 0x950);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS, sEnterTourianPageData[1].bg, 0x800);

    CUTSCENE_DATA.oam[1].oamID = 6;
    CUTSCENE_DATA.oam[1].idChanged = TRUE;
    CUTSCENE_DATA.oam[1].unk_C_0 = 3;
    CUTSCENE_DATA.oam[1].priority = sEnterTourianPageData[0].priority;
    CUTSCENE_DATA.oam[1].unk_D = 1;

    CUTSCENE_DATA.oam[3] = CUTSCENE_DATA.oam[1];
    CUTSCENE_DATA.oam[5] = CUTSCENE_DATA.oam[1];
    CUTSCENE_DATA.oam[7] = CUTSCENE_DATA.oam[1];

    CUTSCENE_DATA.oam[1].rotationScaling = TRUE;

    CUTSCENE_DATA.oam[3].currentAnimationFrame = 2;
    CUTSCENE_DATA.oam[5].currentAnimationFrame = 4;
    CUTSCENE_DATA.oam[7].currentAnimationFrame = 8;

    
    CUTSCENE_DATA.oam[0].oamID = 2;
    CUTSCENE_DATA.oam[0].idChanged = TRUE;
    CUTSCENE_DATA.oam[0].unk_C_0 = 3;
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

    update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[8], 1);
    CUTSCENE_DATA.oam[8].unk_C_0 = 3;
    CUTSCENE_DATA.oam[8].priority = sEnterTourianPageData[0].priority;
    CUTSCENE_DATA.oam[8].unk_D = 1;
    CUTSCENE_DATA.oam[8].xPosition = sEnterTourian_760090[4][0];
    CUTSCENE_DATA.oam[8].yPosition = sEnterTourian_760090[4][1];

    CUTSCENE_DATA.bldcnt = BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;
    gWrittenToBLDY_NonGameplay = 16;
    CUTSCENE_DATA.unk_A = TRUE;

    PlayMusic(MUSIC_ENTERING_TOURIAN_CUTSCENE, 0);
    DMATransfer(3, PALRAM_BASE + 0x200, sEwramPointer + 0x3A00, 0x200, 0x10);
    unk_61fa0(3);

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
    process_cutscene_oam(sEnterTourianSubroutineData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sEnterTourianOam);
    ResetFreeOAM();
    CalculateOamPart4(gCurrentOamRotation, gCurrentOamScaling, 0);
}
