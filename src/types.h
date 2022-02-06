#ifndef TYPES_H
#define TYPES_H

#define TRUE 1
#define FALSE 0

typedef unsigned char   u8;
typedef   signed char   i8;
typedef unsigned short u16;
typedef   signed short i16;
typedef unsigned int   u32;
typedef   signed int   i32;

struct raw_coords_x {
    u16 x;
    u16 y;
};

struct raw_coords_y {
    u16 y;
    u16 x;
};

#endif /* TYPES_H */
