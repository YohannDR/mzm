#ifndef ESCAPE_H
#define ESCAPE_H

#include "types.h"

// Functions

u8 EscapeDetermineTimer(void);
u8 EscapeCheckHasEscaped(void);
void EscapeUpdateOam(void);
void EscapeCheckReloadGraphics(void);
void EscapeStart(void);
void EscapeSetTimer(void);
void EscaepUpdateTimer(void);

#endif /* ESCAPE_H */