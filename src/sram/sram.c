#include "sram/sram.h"

#include "gba.h"
#include "io.h"

static void SRAMWriteUncheckedInternal(u8 *src, u8 *dest, u32 size)
{
    while (size-- != 0) {
        *dest++ = *src++;
    }
}

void SRAMWriteUnchecked(u8 *src, u8 *dest, u32 size)
{
    u16 code[0x40];
    u16 *code_ptr;
    u16 *func_ptr;
    u16 csize;
    void *(*func)(u8 *, u8 *, u32);

    write16(
        REG_WAITCNT,
        read16(REG_WAITCNT) & ~WAIT_SRAM_CYCLES_MASK | WAIT_SRAM_8CYCLES);

    func_ptr = (u16 *)SRAMWriteUncheckedInternal;
    func_ptr = (u16 *)((u32)func_ptr & ~1);
    code_ptr = code;

    for (csize =
             ((u32)SRAMWriteUnchecked - (u32)SRAMWriteUncheckedInternal)
             / 2;
         csize > 0;
         --csize) {
        *code_ptr++ = *func_ptr++;
    }

    func = (void *(*)(u8 *, u8 *, u32))code + 1;
    func(src, dest, size);
}

void SRAMWrite(u8 *src, u8 *dest, u32 size)
{
    u16 w = read16(REG_WAITCNT) & ~WAIT_SRAM_CYCLES_MASK | WAIT_SRAM_8CYCLES;
    write16(REG_WAITCNT, w);

    while (size-- != 0) {
        *dest++ = *src++;
    }
}

static u8* SRAMCheckInternal(u8 *src, u8 *dest, u32 size)
{
    while (size-- != 0) {
        if (*dest++ != *src++) {
            return dest - 1;
        }
    }

    return NULL;
}

u8* SRAMCheck(u8 *src, u8 *dest, u32 size)
{
    u16 code[0x60];
    u16 *code_ptr;
    u16 *func_ptr;
    u16 csize;
    void *(*func)(u8 *, u8 *, u32);

    write16(
        REG_WAITCNT,
        read16(REG_WAITCNT) & ~WAIT_SRAM_CYCLES_MASK | WAIT_SRAM_8CYCLES);

    func_ptr = (u16 *)SRAMCheckInternal;
    func_ptr = (u16 *)((u32)func_ptr & ~1);
    code_ptr = code;

    for (csize = ((u32)SRAMCheck - (u32)SRAMCheckInternal) / 2; csize > 0;
         --csize) {
        *code_ptr++ = *func_ptr++;
    }

    func = (void *(*)(u8 *, u8 *, u32))code + 1;
    return func(src, dest, size);
}

u8* SRAMWriteChecked(u8 *src, u8 *dest, u32 size)
{
    u8 *diff;
    u8 i;

    for (i = 0; i < 3; ++i) {
        SRAMWrite(src, dest, size);
        diff = SRAMCheck(src, dest, size);
        if (!diff) {
            break;
        }
    }

    return diff;
}
