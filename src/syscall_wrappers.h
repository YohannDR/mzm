#ifndef SYSCALL_WRAPPERS_H
#define SYSCALL_WRAPPERS_H

#include "types.h"

void call_LZ77_uncomp_vram(void *src, void *dst);
void call_LZ77_uncomp_wram(void *src, void *dst);
void maybe_test_divarm_sqrt(void);
void call_soundbias(void);
int call_multiboot(void *mbp);
void call_vblankintrwait(void);

#endif /* SYSCALL_WRAPPERS_H */
