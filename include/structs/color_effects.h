#ifndef COLOR_EFFECTS_STRUCT_H
#define COLOR_EFFECTS_STRUCT_H

#include "types.h"

// Structs

struct ColorFading {
    u8 type;
    u8 stage;
    u8 timer;
    u8 unk;
    u8 status;
    u8 unk_flag;
};

// Typedef


// Globals

extern struct ColorFading gColorFading;

#endif