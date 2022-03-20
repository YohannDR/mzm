#ifndef IO_H
#define IO_H

#include "types.h"

#define write32(addr, val) (*(vu32 *)addr) = (val)
#define write16(addr, val) (*(vu16 *)addr) = (val)
#define write8(addr, val) (*(vu8 *)addr) = (val)

#define read32(addr) (*(vu32 *)addr)
#define read16(addr) (*(vu16 *)addr)
#define read8(addr) (*(vu8 *)addr)

#endif /* IO_H */
