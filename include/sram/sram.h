#ifndef SRAM_SRAM_H
#define SRAM_SRAM_H

#include "types.h"

void SRAMWriteUnchecked(u8 *src, u8 *dest, u32 size);
void SRAMWrite(u8 *src, u8 *dest, u32 size);
u8 *SRAMCheck(u8 *src, u8 *dest, u32 size);
u8 *SRAMWriteChecked(u8 *src, u8 *dest, u32 size);

#endif /* SRAM_SRAM_H */
