#include "syscall_wrappers.h"

#include "syscalls.h"

void call_LZ77_uncomp_vram(void *src, void *dst) {
    LZ77_uncomp_vram(src, dst);
}

void call_LZ77_uncomp_wram(void *src, void *dst) {
    LZ77_uncomp_wram(src, dst);
}

void maybe_test_divarm_sqrt(void) {
    divarm_div(1, 1);
    divarm_mod(1, 1);
    Sqrt(2);
}

void call_soundbias(void) {
    soundbias_0();
    SYSCALL(3); /* SYSCALL_Halt */
    soundbias_200();
}

int call_multiboot(void *mbp) {
    return multiboot(mbp);
}

void call_vblankintrwait(void) {
    vblankintrwait();
}
