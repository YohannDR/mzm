#ifndef OAM_H
#define OAM_H

#include "types.h"

struct OamFrame {
    u16 part_count;
    u16 data[0]; // "dynamic array" -> [part_count]
};

struct FrameData {
    u16* oam_frame_ptr;
    u8 timer;
};

struct RawOamData {
    union SplittedI16
    {
        i16 valueU[2];
        i8 valueB[4];
    } data[2];
    /*u16 part2;
    u16 part3;
    u16 part4;*/
};

#endif /* OAM_H */