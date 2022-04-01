#include "funcs.h"
#include "gba.h"
#include "io.h"
#include "types.h"

void
sub_080051f8(u8 *src, u8 *dest, u32 size)
{
    u16 code[0x40];
    u16 *code_ptr;
    u16 *func_ptr;
    u16 csize;
    void *(*func)(u8 *, u8 *, u32);

    write16(
        REG_WAITCNT,
        read16(REG_WAITCNT) & ~WAIT_SRAM_CYCLES_MASK | WAIT_SRAM_8CYCLES);

    func_ptr = (u16 *)sub_080051d4;
    func_ptr = (u16 *)((u32)func_ptr & ~1);
    code_ptr = code;

    for (csize = ((u32)sub_080051f8 - (u32)sub_080051d4) / 2; csize > 0;
         --csize) {
        *code_ptr++ = *func_ptr++;
    }

    func = (void *(*)(u8 *, u8 *, u32))code + 1;
    func(src, dest, size);
}
