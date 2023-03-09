#include "haze.h"
#include "gba.h"

#include "data/engine_pointers.h"
#include "data/haze_data.h"

#include "constants/haze.h"

#include "structs/haze.h"
#include "structs/room.h"

#define HAZE_SET_INACTIVE()              \
do {                                     \
gHazeInfo.flag &= ~HAZE_FLAG_ACTIVE_FLAG;\
} while(0);

void HazeSetBackgroundEffect(void)
{
    // https://decomp.me/scratch/MYhgd

    HazeResetLoops();

    gCurrentHazeValue = sHazeData[gCurrentRoomEntry.visualEffect][0];

    if (gCurrentHazeValue)
    {
        gCurrentRoomEntry.damageEffect = sHazeData[gCurrentRoomEntry.visualEffect][1];
        gWaterMovement.moving = sHazeData[gCurrentRoomEntry.visualEffect][2];
    }

    HazeSetupCode(gCurrentHazeValue);
}

/**
 * @brief 5d034 | 98 | Transfers the haze effect and clears it
 * 
 */
void HazeTransferAndDeactivate(void)
{
    vu8 buffer;

    if (gHazeInfo.flag & HAZE_FLAG_ACTIVE_FLAG)
    {
        dma_set(0, EWRAM_BASE + 0x26300, gHazeInfo.pAffected, (DMA_ENABLE | DMA_DEST_RELOAD) << 16 | gHazeInfo.size / 2);

        buffer = sHaze_345ff8[0];
        buffer = sHaze_345ff8[0];

        dma_set(0, EWRAM_BASE + 0x26300, gHazeInfo.pAffected, (DMA_DEST_RELOAD) << 16 | gHazeInfo.size / 2);

        gHazeInfo.flag &= ~HAZE_FLAG_ACTIVE_FLAG;
    }
}

/**
 * @brief 5d09c | 7c | To document
 * 
 */
void unk_5d09c(void)
{
    vu8 buffer;

    if (gHazeInfo.flag & HAZE_FLAG_ACTIVE_FLAG)
    {
        dma_set(0, EWRAM_BASE + 0x26300, gHazeInfo.pAffected, (DMA_ENABLE | DMA_DEST_RELOAD) << 16 | gHazeInfo.size / 2);

        buffer = sHaze_345ff8[0];
        buffer = sHaze_345ff8[0];

        dma_set(0, EWRAM_BASE + 0x26300, gHazeInfo.pAffected, (DMA_DEST_RELOAD) << 16 | gHazeInfo.size / 2);

        HAZE_SET_INACTIVE();
        gHazeInfo.size = 2;
        gHazeInfo.pAffected = EWRAM_BASE + 0x26D00;
        gCurrentHazeValue = 0;
    }
}

void HazeSetupCode(u8 hazeValue)
{

}

void HazeResetLoops(void)
{

}

void HazeCalculateGradient(void)
{

}

u32 HazeProcess(void)
{

}


void Haze_Bg3(void)
{

}

void Haze_Bg3StrongWeak(void)
{

}

void Haze_Bg3NoneWeak(void)
{

}


void Haze_Bg3Bg2StrongWeakMedium(void)
{

}

void Haze_Bg3Bg2Bg1(void)
{

}


u32 Haze_PowerBombExpanding(void)
{

}

u32 Haze_PowerBombRetracting(void)
{

}
