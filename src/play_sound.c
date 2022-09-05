#include "funcs.h"
#include "types.h"

void SoundPlay(u16 id)
{
    sub_08003fac(id, 0);
}

void SoundStop(u16 id)
{
    sub_08004014(id, 0);
}
