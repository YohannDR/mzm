#include "funcs.h"
#include "gba.h"
#include "globals.h"
#include "memory.h"
#include "sram/sram.h"
#include "types.h"
#include "structs/save_file.h"

void EraseSram(void)
{
    BitFill(3, 0xffff, &gSram, SRAM_SIZE, 16);
    if (!gSramCorruptFlag) {
        SramWriteChecked((u8*)&gSram, SRAM_BASE, SRAM_SIZE);
    }
}
