#ifndef SRAM_SRAM_H
#define SRAM_SRAM_H

#include "types.h"

void sram_write_unchecked(u8 *src, u8 *dest, u32 size);
void sram_write(u8 *src, u8 *dest, u32 size);
u8 *sram_check(u8 *src, u8 *dest, u32 size);
u8 *sram_write_checked(u8 *src, u8 *dest, u32 size);

#endif /* SRAM_SRAM_H */
