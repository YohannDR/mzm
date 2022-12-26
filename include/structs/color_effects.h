#ifndef COLOR_EFFECTS_STRUCT_H
#define COLOR_EFFECTS_STRUCT_H

#include "types.h"

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

// Typedef


// Globals

extern struct ColorFading gColorFading;

#endif