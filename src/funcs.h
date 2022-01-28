#ifndef FUNCS_H
#define FUNCS_H

#include "types.h"

void clear_ram(void);
void dma_transfer(int dma_channel, void *src, void *dst, u32 len, u8 bit_size);
void init_sound(void);
void load_intr_code(void);
void read_sram(void);
void softreset_vblank_callback(void);
void update_input(void);

#endif /* FUNCS_H */
