#include "funcs.h"
#include "gba.h"
#include "globals.h"
#include "memory.h"
#include "sram/sram.h"
#include "types.h"

void EraseSRAM(void)
{
    BitFill(3, 0xffff, &unk_02038000, SRAM_SIZE, 16);
    if (gSRAMCorruptFlag == 0) {
        SRAMWriteChecked(unk_02038000, SRAM_BASE, SRAM_SIZE);
    }
}
