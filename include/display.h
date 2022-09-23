#ifndef DISPLAY_H
#define DISPLAY_H

#include "types.h"

// Globals


// Structs


// Functions

void IOWriteRegisters(void);
void IOWriteRegistersDuringTransition(void);
void IOUpdateDISPCNT(u8 operation, u16 value);

#endif /* DISPLAY_H */
