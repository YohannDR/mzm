#include "gekitai_machine.h"
#include "../../data/data.h"
#include "../globals.h"

const u32 sGekitaiMachineGFX[364];
const u32 sGekitaiMachinePAL[80];

/**
 * @brief 3897c | c | Gekitai machine AI
 * 
 */
void GekitaiMachine(void)
{
    gCurrentSprite.status = 0x0;
}