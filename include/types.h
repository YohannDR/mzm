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
typedef unsigned long long u64;
typedef signed long long s64;
typedef volatile unsigned char vu8;
typedef volatile signed char vs8;
typedef volatile unsigned short vu16;
typedef volatile signed short vs16;
typedef volatile unsigned int vu32;
typedef volatile signed int vs32;
typedef volatile unsigned long long vu64;
typedef volatile signed long long vs64;

#define SCHAR_MIN (-128)
#define SCHAR_MAX (127)
#define UCHAR_MAX (255)

#define SHORT_MIN (-32768)
#define SHORT_MAX (32767)
#define USHORT_MAX (65535)

#define INT_MIN (-2147483648)
#define INT_MAX (2147483647)
#define UINT_MAX ((u32)0xFFFFFFFF)

// The amount of sub pixels a single visible pixel contains
#define SUB_PIXEL_RATIO 4
// The amount of visible pixels a block contains
#define PIXEL_PER_BLOCK 16

// Size of a block, in sub pixels
#define BLOCK_SIZE (PIXEL_PER_BLOCK * SUB_PIXEL_RATIO)
// Shorthand for half a block, in sub pixels
#define HALF_BLOCK_SIZE (BLOCK_SIZE / 2)
// Shorthand for a quarter of a block, in sub pixels
#define QUARTER_BLOCK_SIZE (BLOCK_SIZE / 4)
// Shorthand for an eighth of a block, in sub pixels
#define EIGHTH_BLOCK_SIZE (BLOCK_SIZE / 8)
// Size of a visible pixel, in sub pixels
#define PIXEL_SIZE (BLOCK_SIZE / PIXEL_PER_BLOCK)
// Size of a single sub pixel
#define ONE_SUB_PIXEL (PIXEL_SIZE / PIXEL_SIZE)
// Mask to filter out the sub pixel coordinates, effectively clamping to a pixel
#define PIXEL_POSITION_FLAG ((u16)~PIXEL_SIZE + ONE_SUB_PIXEL)
// Mask to filter out the sub pixel coordinates, effectively clamping to half of a block
#define HALF_BLOCK_POSITION_FLAG ((u16)~HALF_BLOCK_SIZE + ONE_SUB_PIXEL)
// Mask to filter out the sub pixel coordinates, effectively clamping to a block
#define BLOCK_POSITION_FLAG ((u16)~BLOCK_SIZE + ONE_SUB_PIXEL)
// Mask to filter out the block coordinates, resulting in only the sub pixels coordinates in the current block
#define SUB_PIXEL_POSITION_FLAG (BLOCK_SIZE - ONE_SUB_PIXEL)

// Width of the screen, in pixels
#define SCREEN_SIZE_X 240
// Height of the screen, in pixels
#define SCREEN_SIZE_Y 160

#define SCREEN_X_MIDDLE (SCREEN_SIZE_X / 2)
#define SCREEN_Y_MIDDLE (SCREEN_SIZE_Y / 2)

// Target FPS
#define FRAMES_PER_SECOND 60
// The amount of frames the games considers 1 second internally (used by detailed timers)
#define SIMULATED_FPS 64
// Amount of time that happens in one frame
#define DELTA_TIME 1
// Converts a floating point value of seconds to an amount of frames (CONVERT_SECONDS(1.f) == FRAMES_PER_SECOND)
#define CONVERT_SECONDS(s) ((s32)((s) * FRAMES_PER_SECOND))
// Applies the delta time to a value via decrementation
#define APPLY_DELTA_TIME_DEC(v) ((v) -= DELTA_TIME)
// Applies the delta time to a value via incrementation
#define APPLY_DELTA_TIME_INC(v) ((v) += DELTA_TIME)

// Shorthand for one third of a second
#define ONE_THIRD_SECOND (CONVERT_SECONDS(1.f / 3.f))
// Shorthand for two thirds of a second
#define TWO_THIRD_SECOND (CONVERT_SECONDS(1.f / 3.f) * 2)

#define NBR_OF_PALETTE_ROWS 15

// Generic coordinates struct
struct Coordinates {
    u16 x;
    u16 y;
};

// void, void function pointer
typedef void (*Func_T)(void);

#endif /* TYPES_H */
