#ifndef NES_METROID_DATA_H
#define NES_METROID_DATA_H

#include "types.h"

typedef void (*NesEmuFunc_T)(void*);

extern const NesEmuFunc_T sNesEmuBootLoader;

static const u8 sNesMetroidData[];

#endif /* NES_METROID_DATA_H */

