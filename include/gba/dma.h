#ifndef GBA_DMA_H
#define GBA_DMA_H

#include "memory.h"
#include "types.h"

#define REG_DMA0 (REG_BASE + 0x0b0)
#define REG_DMA1 (REG_BASE + 0x0bc)
#define REG_DMA2 (REG_BASE + 0x0c8)
#define REG_DMA3 (REG_BASE + 0x0d4)

#define REG_DMA1_CNT (REG_DMA1 + 8)
#define REG_DMA2_CNT (REG_DMA2 + 8)

#define dma_set(channel, src, dst, cnt)                                        \
    {                                                                          \
        vu32 *dma_ = (vu32 *)REG_DMA##channel;                                 \
        dma_[0]    = (vu32)src;                                                \
        dma_[1]    = (vu32)dst;                                                \
        dma_[2]    = (vu32)cnt;                                                \
        dma_[2];                                                               \
    }

#define dma_fill(channel, val, dst, size, bit)                                 \
    {                                                                          \
        vu##bit dma_tmp_ = (vu##bit)val;                                       \
        dma_set(                                                               \
            channel,                                                           \
            &dma_tmp_,                                                         \
            dst,                                                               \
            (DMA_ENABLE | DMA_START_NOW | DMA_##bit##BIT | DMA_SRC_FIXED       \
             | DMA_DEST_INC)                                                   \
                    << 16                                                      \
                | ((size) / (bit / 8)));                                       \
    }

#define dma_fill16(channel, value, dest, size)                                 \
    dma_fill(channel, value, dest, size, 16)
#define dma_fill32(channel, value, dest, size)                                 \
    dma_fill(channel, value, dest, size, 32)

#define dma_clear(channel, dest, size, bit)                                    \
    {                                                                          \
        vu##bit *dma_dest_ = (vu##bit *)(dest);                                \
        u32 dma_size_      = size;                                             \
        dma_fill##bit(channel, 0, dma_dest_, dma_size_);                       \
    }

#define dma_clear16(channel, dest, size) dma_clear(channel, dest, size, 16)
#define dma_clear32(channel, dest, size) dma_clear(channel, dest, size, 32)

#define DMA_DEST_INC 0x0000
#define DMA_DEST_DEC (1 << 5)
#define DMA_DEST_FIXED (1 << 6)
#define DMA_DEST_RELOAD (1 << 5 | 1 << 6)
#define DMA_SRC_INC 0x0000
#define DMA_SRC_DEC (1 << 7)
#define DMA_SRC_FIXED (1 << 8)
#define DMA_REPEAT (1 << 9)
#define DMA_16BIT 0x0000
#define DMA_32BIT (1 << 10)
#define DMA_DREQ_ON (1 << 11)
#define DMA_START_NOW 0x0000
#define DMA_START_VBLANK (1 << 12)
#define DMA_START_HBLANK (1 << 13)
#define DMA_START_SPECIAL (1 << 12 | 1 << 13)
#define DMA_START_MASK (1 << 12 | 1 << 13)
#define DMA_INTR_ENABLE (1 << 14)
#define DMA_ENABLE (1 << 15)

#define CPU_SET_SRC_FIXED (1 << 8)
#define CPU_SET_32BIT (1 << 10)

#endif /* GBA_DMA_H */
