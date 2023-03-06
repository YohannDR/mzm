#ifndef COLOR_EFFECTS_STRUCT_H
#define COLOR_EFFECTS_STRUCT_H

#include "types.h"

// Typedef

typedef u8 (*ColorFadingFunc_T)(u8, u8);
typedef u8 (*ColorFadingUnkFunc_T)(void);

// Structs

struct ColorFading {
    u8 type;
    u8 stage;
    u8 timer;
    u8 unk_3;
    u8 status;
    u8 unk_5;
    u16 unk_6;
};

struct ColorFadingData {
    u8 unk_0;
    ColorFadingUnkFunc_T unk_4;
    u8 unk_8;
    ColorFadingUnkFunc_T unk_C;
    u8 unk_10;
    u16 bgColorMask;
    u16 objColorMask;
    u8 unk_16;
};

// Globals

extern struct ColorFading gColorFading;

#endif