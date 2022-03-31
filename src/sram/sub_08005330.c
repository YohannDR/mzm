#include "funcs.h"
#include "types.h"

u8 *
sub_08005330(u8 *src, u8 *dest, u32 size)
{
    u8 *unk;
    u8 i;

    for (i = 0; i < 3; ++i) {
        sub_0800525c(src, dest, size);
        unk = sub_080052cc(src, dest, size);
        if (!unk) {
            break;
        }
    }

    return unk;
}
