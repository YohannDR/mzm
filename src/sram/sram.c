#include "sram/sram.h"

#include "gba.h"
#include "io.h"

static void
sram_write_unchecked_internal(u8 *src, u8 *dest, u32 size)
{
    while (size-- != 0) {
        *dest++ = *src++;
    }
}

void
sram_write_unchecked(u8 *src, u8 *dest, u32 size)
{
    u16 code[0x40];
    u16 *code_ptr;
    u16 *func_ptr;
    u16 csize;
    void *(*func)(u8 *, u8 *, u32);

    write16(
        REG_WAITCNT,
        read16(REG_WAITCNT) & ~WAIT_SRAM_CYCLES_MASK | WAIT_SRAM_8CYCLES);

    func_ptr = (u16 *)sram_write_unchecked_internal;
    func_ptr = (u16 *)((u32)func_ptr & ~1);
    code_ptr = code;

    for (csize =
             ((u32)sram_write_unchecked - (u32)sram_write_unchecked_internal)
             / 2;
         csize > 0;
         --csize) {
        *code_ptr++ = *func_ptr++;
    }

    func = (void *(*)(u8 *, u8 *, u32))code + 1;
    func(src, dest, size);
}

void
sram_write(u8 *src, u8 *dest, u32 size)
{
    u16 w = read16(REG_WAITCNT) & ~WAIT_SRAM_CYCLES_MASK | WAIT_SRAM_8CYCLES;
    write16(REG_WAITCNT, w);

    while (size-- != 0) {
        *dest++ = *src++;
    }
}

static u8 *
sram_check_internal(u8 *src, u8 *dest, u32 size)
{
    while (size-- != 0) {
        if (*dest++ != *src++) {
            return dest - 1;
        }
    }

    return NULL;
}

u8 *
sram_check(u8 *src, u8 *dest, u32 size)
{
    u16 code[0x60];
    u16 *code_ptr;
    u16 *func_ptr;
    u16 csize;
    void *(*func)(u8 *, u8 *, u32);

    write16(
        REG_WAITCNT,
        read16(REG_WAITCNT) & ~WAIT_SRAM_CYCLES_MASK | WAIT_SRAM_8CYCLES);

    func_ptr = (u16 *)sram_check_internal;
    func_ptr = (u16 *)((u32)func_ptr & ~1);
    code_ptr = code;

    for (csize = ((u32)sram_check - (u32)sram_check_internal) / 2; csize > 0;
         --csize) {
        *code_ptr++ = *func_ptr++;
    }

    func = (void *(*)(u8 *, u8 *, u32))code + 1;
    return func(src, dest, size);
}

u8 *
sram_write_checked(u8 *src, u8 *dest, u32 size)
{
    u8 *diff;
    u8 i;

    for (i = 0; i < 3; ++i) {
        sram_write(src, dest, size);
        diff = sram_check(src, dest, size);
        if (!diff) {
            break;
        }
    }

    return diff;
}
