#ifndef DISPLAY_H
#define DISPLAY_H

#include "types.h"

// Globals


// Structs


// Functions

void IoWriteRegisters(void);
void IoWriteRegistersDuringTransition(void);
void IoUpdateDISPCNT(u8 operation, u16 value);

#endif /* DISPLAY_H */
