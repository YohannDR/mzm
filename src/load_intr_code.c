#include "funcs.h"
#include "gba.h"
#include "globals.h"
#include "interrupts.h"

void
load_intr_code(void)
{
    dma_transfer(3, intr_main, &intr_code, sizeof(intr_code), 0x10);
    intr_code_ptr = &intr_code;
}
