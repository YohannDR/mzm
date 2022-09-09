#include "funcs.h"
#include "globals.h"
#include "gba.h"

struct DMA {
    void* pSrc;
    void* pDst;
    u32 control;
};

void DMATransfer(u8 channel, void *src, void *dst, u32 len, u8 bitSize)
{
    // https://decomp.me/scratch/j8Gur

    volatile struct DMA* pDma;
    u32 sizeControl;
    u32 lengthControl;
    u32 temp;

    pDma = gRegDMA + channel;

    if (bitSize == 0x20)
        sizeControl = (DMA_32BIT << 16);
    else
        sizeControl = 0;
    
    temp = bitSize << 0x1;
    lengthControl = (0x800 >> (temp));
    lengthControl |= (DMA_ENABLE << 16);
    
    while (len > 0x800)
    {
        pDma->pSrc = src;
        pDma->pDst = dst;

        pDma->control = sizeControl | lengthControl;
        pDma->control;

        while (gRegDMA[channel].control & (DMA_ENABLE << 16));

        len -= 0x800;
        (char*)src += 0x800;
        (char*)dst += 0x800;
    }

    pDma->pSrc = src;
    pDma->pDst = dst;

    temp = bitSize << 0x1;
    lengthControl = (len >> (temp));
    pDma->control = sizeControl | lengthControl;
    pDma->control;

    while (gRegDMA[channel].control & (DMA_ENABLE << 16));
}