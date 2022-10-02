#include "oam.h"
#include "temp_globals.h"
#include "cutscenes/kraid_rising.h"

#include "data/cutscenes/cutscenes_data.h"
#include "data/cutscenes/kraid_rising.h"
#include "data/generic_data.h"

#include "constants/audio.h"
#include "constants/cutscene.h"

#include "structs/game_state.h"

u8 KraidRisingRising(void)
{

}

/**
 * @brief 626f8 | 54 | Updates a puff
 * 
 * @param pOam Cutscene OAM Data Pointer
 * @param puffID Puff ID
 * @return struct CutsceneOamData* First param
 */
struct CutsceneOamData* KraidRisingUpdatePuff(struct CutsceneOamData* pOam, u8 puffID)
{
    u8* data;
    i32 offset;

    if (!(pOam->status & 0xC0))
    {
        if (pOam->timer != 0)
            pOam->timer--;
        else
        {
            // Update timer
            pOam->timer = (sRandomNumberTable[gFrameCounter8Bit + puffID] & 0xF) + 1;

            // Why
            data = (u8*)(sKraidRisingPuffData);
            offset = puffID * 8;

            // OAM ID field
            data += 4;

            // Reset animation
            update_cutscene_oam_data_id(pOam, data[offset]); // Undefined
        }
    }

    // Implicit return
}

/**
 * @brief 6274c | c0 | Updates a debris
 * 
 * @param pOam Cutscene OAM Data Pointer
 * @param puffID Debris ID
 * @return struct CutsceneOamData* First param
 */
struct CutsceneOamData* KraidRisingUpdateDebris(struct CutsceneOamData* pOam, u8 debrisID)
{
    if (pOam->timer != 0)
        pOam->timer--;
    else
    {
        if (!(pOam->status & 0xC0))
        {
            // Set spawn X (base + [0-0x3F])
            pOam->xPosition = sKraidRisingDebrisSpawnXPosition[debrisID] + (sRandomNumberTable[~((gFrameCounter8Bit + debrisID) & 0xFF)] & 0x3F);
            
            // Start above ceiling
            pOam->yPosition = -HALF_BLOCK_SIZE;

            // Set random velocity
            pOam->unk_10 = ((gFrameCounter8Bit + debrisID) & ((debrisID & 1) + 3)) - 2;
            pOam->unk_18 = 0;

            // Reset anim
            update_cutscene_oam_data_id(pOam, KRAID_RISING_OAM_ID_DEBRIS);
        }
        else
        {
            // Gradually increment velocity
            if (pOam->unk_10 < 32)
                pOam->unk_10++;

            // Apply velocity
            pOam->yPosition += pOam->unk_10;
            if (pOam->yPosition > 0x2DF)
            {
                pOam->status &= 0x3F;
                // Set random timer
                pOam->timer = (sRandomNumberTable[(gFrameCounter8Bit + debrisID) & 0xFF] & 0xF) + 1;
            }
        }
    }
}

u8 KraidRisingOpeningEyes(void)
{
    // https://decomp.me/scratch/uSyVv

    switch (CUTSCENE_DATA.subStage)
    {
        case 0:
            if (CUTSCENE_DATA.timer > 8)
            {
                CutsceneStartSpriteEffect(CUTSCENE_DATA.bldcnt, 0, 0, 16);
                CUTSCENE_DATA.subStage++;
                CUTSCENE_DATA.timer = 0;
            }
            break;

        case 1:
            if (CUTSCENE_DATA.timer > 0x1E)
            {
                SoundPlay(0x22C);

                DMATransfer(3, sMemoryPointers[0] + 0x1000, VRAM_BASE + sKraidRisingBehaviorData[1].dstPage * 0x800, 0x800, 0x10);
                unk_6141c(sKraidRisingBehaviorData[1]);

                CUTSCENE_DATA.subStage++;
                CUTSCENE_DATA.timer = 0;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.timer > 6)
            {
                DMATransfer(3, sMemoryPointers[0] + 0x1800, VRAM_BASE + sKraidRisingBehaviorData[0].dstPage * 0x800, 0x800, 0x10);
                unk_6141c(sKraidRisingBehaviorData[0]);

                CUTSCENE_DATA.subStage++;
                CUTSCENE_DATA.timer = 0;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timer > 6)
            {
                MusicPlay(MUSIC_KRAID_BATTLE_WITH_INTRO, 0);

                DMATransfer(3, sMemoryPointers[0] + 0x2000, VRAM_BASE + sKraidRisingBehaviorData[1].dstPage * 0x800, 0x800, 0x10);
                unk_6141c(sKraidRisingBehaviorData[1]);

                CUTSCENE_DATA.subStage++;
                CUTSCENE_DATA.timer = 0;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.timer > 0x3C)
                CUTSCENE_DATA.subStage++;
            break;

        case 5:
            unk_61f0c();
            CUTSCENE_DATA.stage++;
            CUTSCENE_DATA.subStage = 0;
            CUTSCENE_DATA.timer = 0;
            break;
    }

    return FALSE;
}

u8 KraidRisingInit(void)
{

}

/**
 * @brief 62b24 | 37 | Kraid rising cutscene subroutine
 * 
 * @return u8 1 if ended, 0 otherwise
 */
u8 KraidRisingSubroutine(void)
{
    u8 ended;

    ended = sKraidRisingSubroutineData[CUTSCENE_DATA.stage].pFunction();

    CutsceneUpdateBackgroundsPosition(TRUE);
    KraidRisingProcessOAM();
    return ended;
}

/**
 * @brief 62b58 | 38 | Processes the OAM for the cutscene
 * 
 */
void KraidRisingProcessOAM(void)
{
    gNextOAMSlot = 0;

    process_cutscene_oam(sKraidRisingSubroutineData[CUTSCENE_DATA.stage].oamLength, CUTSCENE_DATA.oam, sKraidRisingCutsceneOAM); // Undefined
    ResetFreeOAM();
}
