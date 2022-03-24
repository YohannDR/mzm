#ifndef OAM_H
#define OAM_H

#include "types.h"

struct oam_data {
    u16 oam0;
    u16 oam1;
    u16 oam2;
};

struct OamFrame {
    u16 part_count;
    u16 data[0]; // "dynamic array" -> [part_count]
};

struct FrameData {
    struct OamFrame* oam_frame_ptr;
    u8 timer;
};

struct raw_oam_data {
    u16 data[4];
    /*u16 part2;
    u16 part3;
    u16 part4;*/
};

#endif /* OAM_H */