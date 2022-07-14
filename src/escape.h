#ifndef ESCAPE_H
#define ESCAPE_H

#include "types.h"

// Globals

extern u8 gCurrentEscapeStatus;
extern u8 gEscapeTimerCounter;
extern struct EscapeDigits gEscapeTimerDigits;

// Defines

#define ESCAPE_NONE 0x0
#define ESCAPE_MOTHER_BRAIN 0x1
#define ESCAPE_MECHA_RIDLEY 0x2

#define ESCAPE_STATUS_NONE 0x0
#define ESCAPE_STATUS_HAPPENNING 0x1
#define ESCAPE_STATUS_FAILED 0x2

// Structs

struct __attribute__((packed)) EscapeDigits {
    u8 hundredths;
    u8 tenths;
    u8 seconds_ones;
    u8 seconds_tens;
    u8 minutes_ones;
    u8 minutes_tens;
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