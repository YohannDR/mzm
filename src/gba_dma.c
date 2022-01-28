#include "gba_dma.h"
#include "globals.h"

void dma_transfer(enum dma_channel channel, void *src, void *dst, u32 len, u8 bit_size)
{
    u32 control;
    u32 control_check;
    
    if (bit_size == 0x20) control = 0x4000000;
    else control = 0x0;

    for (; 0x800 < len; len -= 0x800)
    {
        reg_dma[channel].src = src;
        reg_dma[channel].dst = dst;
        reg_dma[channel].wordcount_control = control | 0x800 >> (bit_size >> 0x4) | 0x80000000;
        
        control_check = reg_dma[channel].wordcount_control;
        while ((control_check & 0x80000000) != 0x0) control_check = reg_dma[channel].wordcount_control;

        src = src + 0x800;
        dst = dst + 0x800;
    }

    reg_dma[channel].src = src;
    reg_dma[channel].dst = dst;
    reg_dma[channel].wordcount_control = control | len >> (bit_size >> 0x4) | 0x80000000;

    control = reg_dma[channel].wordcount_control;
    while ((control & 0x80000000) != 0x0) control = reg_dma[channel].wordcount_control;
}