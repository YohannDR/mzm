#ifndef NES_METROID_DATA_H
#define NES_METROID_DATA_H

#include "types.h"

typedef void (*NesEmuFunc_T)(void*);
struct NesMetroid {
    const NesEmuFunc_T emuBootLoader;
    const u8 data_Prologue[156];
    const u8 data_Text[18];
    const u8 data[0];
};

extern const u8 sNesMetroid[];

#endif /* NES_METROID_DATA_H */

