#include "gba.h"
#include "oam.h"
#include "cutscenes/cutscene_utils.h"
#include "temp_globals.h"

#include "constants/audio.h"
#include "constants/cutscene.h"


/**
 * @brief 60e28 | 4 | Default subroutine for Cutscene that don't have any
 * 
 * @return u8 1
 */
u8 CutsceneDefaultRoutine(void)
{
    return TRUE;
}

u8 TourianEscapeSubroutine(void)
{

}

/**
 * @brief 60ec0 | 34 | Updates the audio after a cutscene was skipped
 * 
 */
void CutsceneUpdateMusicAfterSkip(void)
{
    switch (gCurrentCutscene)
    {
        case CUTSCENE_KRAID_RISING:
            MusicPlay(MUSIC_KRAID_BATTLE_WITH_INTRO, 0);
            break;

        case CUTSCENE_RIDLEY_SPAWNING:
            SoundPlay(0x24C);
    }

    SoundFade(10);
}

void CutsceneEnd(void)
{

}

u8 CutsceneSubroutine(void)
{

}

/**
 * @brief 61228 | 4 | Subroutine that marks the end of a cutscene
 * 
 * @return u8 1
 */
u8 CutsceneEndFunction(void)
{
    return TRUE;
}

void CutsceneVBlank(void)
{
    // https://decomp.me/scratch/u6eTX

    struct CutsceneData* pCutscene;
    
    dma_set(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | 0x100);

    pCutscene = &CUTSCENE_DATA;

    write16(REG_BG0HOFS, pCutscene->bg0hofs);
    write16(REG_BG0VOFS, pCutscene->bg0vofs);
    write16(REG_BG1HOFS, pCutscene->bg1hofs);
    write16(REG_BG1VOFS, pCutscene->bg1vofs);
    write16(REG_BG2HOFS, pCutscene->bg2hofs);
    write16(REG_BG2VOFS, pCutscene->bg2vofs);
    write16(REG_BG3HOFS, pCutscene->bg3hofs);
    write16(REG_BG3VOFS, pCutscene->bg3vofs);

    write16(REG_BG0CNT, pCutscene->bgcnt[0]);
    write16(REG_BG1CNT, pCutscene->bgcnt[1]);
    write16(REG_BG2CNT, pCutscene->bgcnt[2]);
    write16(REG_BG3CNT, pCutscene->bgcnt[3]);

    write16(REG_BLDY, gWrittenToBLDY);
    write16(REG_BLDALPHA, gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L);

    write16(REG_BLDCNT, pCutscene->bldcnt);
    write16(REG_DISPCNT, pCutscene->dispcnt);
}

/**
 * @brief 612d4 | c | V blank code when loading a cutscene
 * 
 */
void CutsceneLoadingVBlank(void)
{
    vu8 var = 0;
}

void CutsceneInit(void)
{

}

void unk_6141c(u32 value, u16 bg)
{

}

/**
 * @brief 61484 | 50 | Changes the BGCNT value of a specified background
 * 
 * @param value Value
 * @param bg Background (DISPCNT flags)
 */
void CutsceneSetBGCNT(u16 value, u16 bg)
{
    u8 offset;

    if (bg == DCNT_BG0)
        offset = 0;
    else if (bg == DCNT_BG1)
        offset = 1;
    else if (bg == DCNT_BG2)
        offset = 2;
    else if (bg == DCNT_BG3)
        offset = 3;
    else
        return;

    CUTSCENE_DATA.bgcnt[offset] = value;
}

void CutsceneUpdateBGPosition(u8 type, u16 bg, u16 value)
{

}

/**
 * @brief 61578 | 50 | Gets the pointer to the HOFS (X) value of a specified background
 * 
 * @param bg Background (DISPCNT flags)
 * @return u16* Pointer
 */
u16* CutsceneGetBGHOFSPointer(u16 bg)
{
    u16* pBg;

    pBg = NULL;
    if (bg == DCNT_BG0)
        pBg = &gBG0HOFS_NonGameplay;
    else if (bg == DCNT_BG1)
        pBg = &gBG1HOFS_NonGameplay;
    else if (bg == DCNT_BG2)
        pBg = &gBG2HOFS_NonGameplay;
    else if (bg == DCNT_BG3)
        pBg = &gBG3HOFS_NonGameplay;

    return pBg;
}

/**
 * @brief 615c8 | 50 | Gets the pointer to the VOFS (Y) value of a specified background
 * 
 * @param bg Background (DISPCNT flags)
 * @return u16* Pointer
 */
u16* CutsceneGetBGVOFSPointer(u16 bg)
{
    u16* pBg;

    pBg = NULL;
    if (bg == DCNT_BG0)
        pBg = &gBG0VOFS_NonGameplay;
    else if (bg == DCNT_BG1)
        pBg = &gBG1VOFS_NonGameplay;
    else if (bg == DCNT_BG2)
        pBg = &gBG2VOFS_NonGameplay;
    else if (bg == DCNT_BG3)
        pBg = &gBG3VOFS_NonGameplay;

    return pBg;
}

void CutsceneStartBackgroundScrolling(u32 param_1, u32 param_2, u16 bg)
{

}

void CutsceneUpdateBackgroundScrolling(struct CutsceneScrolling* pScrolling)
{

}

u8 CutsceneCheckBackgroundScrollingActive(u16 bg)
{

}

void CutsceneUpdateBackgroundsPosition(u8 updateScrolling)
{
    // https://decomp.me/scratch/l3Uul

    i32 i;

    if (updateScrolling & TRUE)
    {
        for (i = 0; i < 8; i++)
        {
            if (CUTSCENE_DATA.bgScrolling[i].pPosition != NULL)
                CutsceneUpdateBackgroundScrolling(CUTSCENE_DATA.bgScrolling + i);
        }
    }

    CUTSCENE_DATA.bg0hofs = gBG0HOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg0vofs = gBG0VOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg1hofs = gBG1HOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg1vofs = gBG1VOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg2hofs = gBG2HOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg2vofs = gBG2VOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg3hofs = gBG3HOFS_NonGameplay / 4;
    CUTSCENE_DATA.bg3vofs = gBG3VOFS_NonGameplay / 4;

    if (CUTSCENE_DATA.horizontalScreenShake.bg != 0)
        CutsceneUpdateScreenShake(FALSE, &CUTSCENE_DATA.horizontalScreenShake);

    if (CUTSCENE_DATA.verticalScreenShake.bg != 0)
        CutsceneUpdateScreenShake(TRUE, &CUTSCENE_DATA.verticalScreenShake);
}

void CutsceneUpdateScreenShake(u8 affectVertical, struct CutsceneScreenShake* pShake)
{

}

void CutsceneStartScreenShake(u32 param_1, u16 bg)
{

}

void CutsceneUpdateSpecialEffect(void)
{

}

void CutsceneStartSpriteEffect(u16 bldcnt, u8 bldy, u8 interval, u8 intensity)
{

}

void CutsceneStartBackgroundEffect(u16 bldcnt, u8 bldalphaL, u8 bldalphaH, u8 interval, u8 intensity)
{

}

void CutsceneReset(void)
{

}

void unk_61f0c(void)
{

}

void unk_61f28(void)
{

}

void unk_61f44(void)
{

}

void unk_61f60(void)
{

}

void unk_61fa0(void)
{

}

void unk_621d0(void)
{

}
