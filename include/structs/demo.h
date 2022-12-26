#ifndef DEMO_STRUCT_H
#define DEMO_STRUCT_H

#include "types.h"

struct Demo {
    u8 number;
    u8 playing;
    u8 status;
    u8 unk_3;
};

extern u8 gDemoState;
extern struct Demo gCurrentDemo; /* XXX: type */

#endif
