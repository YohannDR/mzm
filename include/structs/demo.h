#ifndef DEMO_STRUCT_H
#define DEMO_STRUCT_H

#include "types.h"

struct Demo {
    u8 number:4;
    u32 playing:4;
    u32 status:16;
    u32 unk_3:4;
};

extern u8 gDemoState;
extern struct Demo gCurrentDemo;

#endif
