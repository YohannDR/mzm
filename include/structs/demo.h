#ifndef DEMO_STRUCT_H
#define DEMO_STRUCT_H

#include "types.h"

struct Demo {
    u8 number;
    u8 active;
    u16 hasBeenInit:4;
    u16 loading:4;
    u16 endedWithInput:4;
    u16 noDemoShuffle:4;
};

struct DemoEntry {
    const u16* const pInputs;
    u16 inputsSize;
    const u16* const pDuration;
    u16 durationSize;
};

extern u8 gDemoState;
extern struct Demo gCurrentDemo;

#define DEMO_MAX_DURATION 256

extern u16 gDemoInputData[DEMO_MAX_DURATION];
extern u16 gDemoInputDuration[DEMO_MAX_DURATION];
extern u16 gDemoInputNumber;
extern u16 gDemoInputTimer;
extern u16 gDemoInput;

#endif
