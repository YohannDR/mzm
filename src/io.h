#ifndef IO_H
#define IO_H

#include "types.h"

#define writew(addr, val) (*(vu32 *)addr) = (val)
#define writeh(addr, val) (*(vu16 *)addr) = (val)
#define writeb(addr, val) (*(vu8  *)addr) = (val)

#define readw(addr) (*(vu32 *)addr)
#define readh(addr) (*(vu16 *)addr)
#define readb(addr) (*(vu8  *)addr)

#endif /* IO_H */
