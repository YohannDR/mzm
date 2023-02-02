#include "cutscenes/ridley_landing.h"
#include "cutscenes/cutscene_utils.h"

#include "data/cutscenes/cutscenes_data.h"
#include "data/shortcut_pointers.h"

#include "constants/cutscene.h"

/**
 * @brief 647d0 | 178 | Handles the ridley flying part
 * 
 * @return u8 FALSE
 */
u8 RidleyLandingRidleyFlying(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            DMATransfer(3, sRidleyLandingSkyBackgroundPAL, PALRAM_BASE, 0xA0, 0x10);
			DMATransfer(3, sRidleyLandingRidleyAndRocksPAL, PALRAM_BASE + 0x200, 0x40, 0x10);
			
            write16(PALRAM_BASE, 0);
			
            CallLZ77UncompVRAM(sRidleyLandingRidleyFlyingBackgroundGFX, VRAM_BASE + sRidleyLandingPageData[4].graphicsPage * 0x4000);
			CallLZ77UncompVRAM(sRidleyLandingRidleyAndRockShadowGFX, VRAM_BASE + 4 * 0x4000);
			CallLZ77UncompVRAM(sRidleyLandingRidleyFlyingBackgroundTileTable, VRAM_BASE + sRidleyLandingPageData[4].tiletablePage * 0x800);
			
            CutsceneSetBGCNTPageData(sRidleyLandingPageData[4]);
			CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleyLandingPageData[4].bg, 0x800);
			CutsceneReset();
            
            CUTSCENE_DATA.oam[1].xPosition = 0x480;
			CUTSCENE_DATA.oam[1].yPosition = 0x180;
			update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[1], 8);
            
			CUTSCENE_DATA.oam[0].xPosition = 0x2C0;
			CUTSCENE_DATA.oam[0].yPosition = 0x200;
			update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[0], 9);
            
            CUTSCENE_DATA.dispcnt = sRidleyLandingPageData[4].bg | DCNT_OBJ;
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > 60)
            {
                SoundPlay(0x292);
                CUTSCENE_DATA.oam[1].unk_D |= (1 | 2);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.oam[1].unk_D == 0)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > 60)
            {
                unk_61f0c();
                CUTSCENE_DATA.timeInfo.stage++;
                MACRO_CUTSCENE_NEXT_STAGE();
            }
            break;
    }

    RidleyLandingUpdateRidley(&CUTSCENE_DATA.oam[1]);
    return FALSE;
}

void RidleyLandingUpdateRidley(struct CutsceneOamData* pOam)
{
    // https://decomp.me/scratch/14Jma

    if (pOam->unk_D & 1)
    {
        pOam->unk_16++;
        pOam->unk_E = -0x24;
        pOam->xPosition += pOam->unk_E;

        if (pOam->xPosition < -0x100)
            pOam->unk_D = 0;

        if (pOam->unk_16 == 8)
            update_cutscene_oam_data_id(&CUTSCENE_DATA.oam[0], 10);
    }

    if (pOam->unk_D & 2)
    {
        pOam->unk_18++;
        pOam->unk_10 = -((u16)pOam->unk_18 >> 1);
        pOam->yPosition += pOam->unk_10;
    }
}

u8 RidleyLandingShipLanding(void)
{

}

struct CutsceneOamData* RidleyLandingUpdateShipLanding(struct CutsceneOamData* pOam)
{

}

u8 RidleyLandingShipInShip(void)
{

}

u8 RidleyLandingInit(void)
{

}

u8 RidleyLandingSubroutine(void)
{

}

void RidleyLandingProcessOAM(void)
{

}
