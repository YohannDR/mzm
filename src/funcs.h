#ifndef FUNCS_H
#define FUNCS_H

#include "types.h"

void clear_ram();
void dma_transfer(int dma_channel, void *src, void *dst, u32 len, u8 bit_size);
void init_sound();
void load_intr_code();
void read_sram();
void sub_080007c4();
void update_input();

#endif /* FUNCS_H */
