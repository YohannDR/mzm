#include "gba_dma.h"
#include "globals.h"
#include "interrupts.h"

void load_intr_code(void) {
    /* TODO: magic number */
    dma_transfer(DMA_GENERAL_PURPOSE_COPY, intr_main, &intr_code, sizeof(intr_code), 0x10);
    intr_code_ptr = &intr_code;
}
