#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "types.h"

struct background_pointers_and_dimensions {
    struct sub_bg_ptr {
        u16* decompressed;
        u16 width;
        u16 height;
    } backgrounds[3];
    u16* clipdata_decompressed;
    u16 clipdata_width;
    u16 clipdata_height;
};

#endif /* BACKGROUND_H */