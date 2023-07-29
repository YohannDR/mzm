#ifndef TYPES_H
#define TYPES_H

#define TRUE 1
#define FALSE 0
#define NULL ((void *)0)

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef volatile unsigned char vu8;
typedef volatile signed char vs8;
typedef volatile unsigned short vu16;
typedef volatile signed short vs16;
typedef volatile unsigned int vu32;
typedef volatile signed int vs32;

#define SCHAR_MIN (-128)
#define SCHAR_MAX (127)
#define UCHAR_MAX (255)

#define SHORT_MIN (-32768)
#define SHORT_MAX (32767)
#define USHORT_MAX (65535)

#define INT_MIN (-2147483648)
#define INT_MAX (2147483647)
#define UINT_MAX ((u32)4294967295)

#define SUB_PIXEL_RATIO 4
#define SUB_PIXEL_NUMBER 16

#define BLOCK_SIZE (SUB_PIXEL_NUMBER * SUB_PIXEL_RATIO)
#define HALF_BLOCK_SIZE (BLOCK_SIZE / 2)
#define QUARTER_BLOCK_SIZE (BLOCK_SIZE / 4)
#define PIXEL_SIZE (BLOCK_SIZE / SUB_PIXEL_NUMBER)
#define BLOCK_POSITION_FLAG ((u16)~BLOCK_SIZE + ONE_SUB_PIXEL)
#define SUB_PIXEL_POSITION_FLAG (BLOCK_SIZE - ONE_SUB_PIXEL)
#define ONE_SUB_PIXEL (PIXEL_SIZE / PIXEL_SIZE)

#define SCREEN_SIZE_X 240
#define SCREEN_SIZE_Y 160

#define SCREEN_SIZE_X_SUB_PIXEL (SCREEN_SIZE_X * SUB_PIXEL_RATIO)
#define SCREEN_SIZE_Y_SUB_PIXEL (SCREEN_SIZE_Y * SUB_PIXEL_RATIO)

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
