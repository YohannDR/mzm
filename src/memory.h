#ifndef MEMORY_H
#define MEMORY_H

#include "gba.h"
#include "types.h"

struct DMA {
    void* src;
    void* dst;
    u32 control;
};

void bit_fill(int dma_channel, u32 value, void *dst, u32 len, u8 bit_size);

#endif /* MEMORY_H */
