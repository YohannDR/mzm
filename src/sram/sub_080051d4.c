#include "types.h"

void
sub_080051d4(u8 *src, u8 *dest, u32 size)
{
    while (size-- != 0) {
        *dest++ = *src++;
    }
}
