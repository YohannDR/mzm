#ifndef MEMORY_H
#define MEMORY_H

#include "gba_dma.h"
#include "types.h"

void clear_ram(void);
void bit_fill(int dma_channel, u8 value, void *dst, u32 len, u8 bit_size);

#endif /* MEMORY_H */
