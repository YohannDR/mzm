#ifndef GBA_GFX_H
#define GBA_GFX_H

#include "types.h"

struct frame_data {
    void* oam_frame_ptr;
    u32 timer;
};

#endif /* GBA_GFX_H */