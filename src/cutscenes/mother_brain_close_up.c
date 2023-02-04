#include "cutscenes/mother_brain_close_up.h"
#include "cutscenes/cutscene_utils.h"
#include "temp_globals.h"

#include "data/shortcut_pointers.h"
#include "data/cutscenes/cutscenes_data.h"

#include "constants/cutscene.h"

u8 MotherBrainCloseUpLookingAtSamus(void)
{

}

void MotherBrainCloseUpUpdateElevatorReflection(struct CutsceneOamData* pOam)
{

}

u8 MotherBrainCloseUpEyeOpening(void)
{

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
            SoundPlay(0x22E);
            CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt, 10, 0, 8);
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > 30)
            {
                CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt, 0, 2, 1);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_SPRITE_ENDED)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > 60)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            unk_61f0c();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    return FALSE;
}

u8 MotherBrainCloseUpInit(void)
{

}

u8 MotherBrainCloseUpSubroutine(void)
{

}

void MotherBrainCloseUpProcessOAM(void)
{

}

void MotherBrainCloseUpUpdateEye(u8 lookingAtSamus)
{

}

void MotherBrainCloseUpUpdateBubble(struct CutsceneOamData* pOam)
{
    // https://decomp.me/scratch/14vAj

    i32 yPosition;

    pOam->yPosition -= 4;
    yPosition = (pOam->yPosition + BLOCK_SIZE * 32);
    yPosition -= gBG3VOFS_NonGameplay;

    if (yPosition < -0x90)
        pOam->idChanged = FALSE;
    else if (yPosition > 0x300)
    {
        if (!(pOam->notDrawn))
            pOam->notDrawn = TRUE;
    }
    else if (pOam->notDrawn)
        pOam->notDrawn = FALSE;
}

void MotherBrainCloseUpInitBubbles(u8 packId)
{

}
