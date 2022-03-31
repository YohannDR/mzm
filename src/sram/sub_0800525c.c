#include "gba.h"
#include "io.h"
#include "types.h"

void
sub_0800525c(u8 *src, u8 *dest, u32 size)
{
    u16 w = read16(REG_WAITCNT) & ~WAIT_SRAM_8CYCLES | WAIT_SRAM_8CYCLES;
    write16(REG_WAITCNT, w);

    while (size-- != 0) {
        *dest++ = *src++;
    }
}
