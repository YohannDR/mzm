#ifndef GBA_DMA_H
#define GBA_DMA_H

#include "types.h"

struct dma {
    void *src;
    void *dst;
    u32 wordcount_control;
};

enum dma_channel {
    DMA_TIME_CRITICAL_INTERNAL,
    DMA_SOUNDBUFFER_TRANSFER1,
    DMA_SOUNDBUFFER_TRANSFER2,
    DMA_GENERAL_PURPOSE_COPY,
};

void dma_transfer(enum dma_channel channel, void *src, void *dst, u32 len, u8 bit_size);

#endif /* GBA_DMA_H */
