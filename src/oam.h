#ifndef OAM_H
#define OAM_H

#include "types.h"

struct oam_data {
    u16 oam0;
    u16 oam1;
    u16 oam2;
};

struct oam_frame {
    u16 part_count;
    struct oam_data data[0]; // "dynamic array" -> [part_count]
};

struct frame_data {
    struct oam_frame* oam_frame_ptr;
    u32 timer;
};

struct oam_part {
    u8 sub1;
    u8 sub2;
};

struct raw_oam_data {
    /*struct oam_part part1;
    struct oam_part part2;
    struct oam_part part3;
    struct oam_part part4;*/
    u16 part1;
    u16 part2;
    u16 part3;
    u16 part4;
};

#endif /* OAM_H */