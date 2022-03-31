#include "types.h"

u8 *
sub_0800529c(u8 *src, u8 *dest, u32 size)
{
    while (size-- != 0) {
        if (*dest++ != *src++) {
            return dest - 1;
        }
    }

    return NULL;
}
