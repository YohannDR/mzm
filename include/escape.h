#ifndef ESCAPE_H
#define ESCAPE_H

#include "types.h"

// Globals

extern u8 gCurrentEscapeStatus;
extern u8 gEscapeTimerCounter;
extern struct EscapeDigits gEscapeTimerDigits;

// Structs

struct __attribute__((packed)) EscapeDigits {
    u8 hundredths;
    u8 tenths;
    u8 secondsOnes;
    u8 secondsTens;
    u8 minutesOnes;
    u8 minutesTens;
};

// Functions

u8 EscapeDetermineTimer(void);
u8 EscapeCheckHasEscaped(void);
void EscapeUpdateOAM(void);
void EscapeCheckReloadGraphics(void);
void EscapeStart(void);
void EscapeSetTimer(void);
void EscaepUpdateTimer(void);

#endif /* ESCAPE_H */