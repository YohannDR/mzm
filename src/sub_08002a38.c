#include "structs.h"
#include "types.h"

void
sub_08002a38(struct struct_08002a38 *param1)
{
    /* XXX: random bit masks */
    if (!(param1->unk_01e & 1) && (param1->unk_000 & 2)) {
        param1->unk_000 = 1;
    }
}
