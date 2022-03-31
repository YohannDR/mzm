#include "funcs.h"
#include "types.h"

void *
sub_08005330(u8 *src, u8 *dest, u32 size)
{
    void *unk;
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
