#ifndef TYPES_H
#define TYPES_H

#define TRUE 1
#define FALSE 0
#define NULL ((void *)0)

typedef unsigned char u8;
typedef signed char i8;
typedef unsigned short u16;
typedef signed short i16;
typedef unsigned int u32;
typedef signed int i32;
typedef volatile unsigned char vu8;
typedef volatile signed char vi8;
typedef volatile unsigned short vu16;
typedef volatile signed short vi16;
typedef volatile unsigned int vu32;
typedef volatile signed int vi32;

#define SCHAR_MIN (-128)
#define SCHAR_MAX (127)
#define UCHAR_MAX (255)

#define SHORT_MIN (-32768)
#define SHORT_MAX (32767)
#define USHORT_MAX (65535)

#define INT_MIN (-2147483648)
#define INT_MAX (2147483647)
#define UINT_MAX ((u32)4294967295)

#define BLOCK_SIZE 0x40
#define HALF_BLOCK_SIZE (BLOCK_SIZE / 2)
#define QUARTER_BLOCK_SIZE (BLOCK_SIZE / 4)
#define BLOCK_POSITION_FLAG ((u16)~BLOCK_SIZE + 1)
#define SUB_PIXEL_POSITION_FLAG (BLOCK_SIZE - 1)

struct RawCoordsX {
    u16 x;
    u16 y;
};

struct RawCoordsY {
    u16 y;
    u16 x;
};

typedef void (*Func_T)(void);

#endif /* TYPES_H */
