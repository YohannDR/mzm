#ifndef OAM_H
#define OAM_H

#include "types.h"

// Attribute 0

#define OBJ_ROTATION_SCALING 0x100
#define OBJ_DOUBLE_SIZE 0x200
#define OBJ_DISABLE 0x200
#define OBJ_MODE_SEMI_TRANSPARENT 0x400
#define OBJ_MODE_OBJ_WINDOW 0x800
#define OBJ_MOSAIC 0x1000
#define OBJ_COLOR_256_1 0x2000
#define OBJ_SHAPE_HORIZONTAL 0x4000
#define OBJ_SHAPE_VERTICAL 0x8000

// Attribute 1

#define OBJ_X_FLIP 0x1000
#define OBJ_Y_FLIP 0x2000
#define OBJ_SIZE_16x16 0x4000
#define OBJ_SIZE_32x8 0x4000
#define OBJ_SIZE_8x32 0x4000
#define OBJ_SIZE_32x32 0x8000
#define OBJ_SIZE_32x16 0x8000
#define OBJ_SIZE_16x32 0x8000
#define OBJ_SIZE_64x64 0xC000
#define OBJ_SIZE_64x32 0xC000
#define OBJ_SIZE_32x64 0xC000

// Attribute 2

#define OBJ_SPRITE_OAM 0x8000 // Not sure what this is, sprite OAM doesn't work without it

struct FrameData {
    const u16* pFrame;
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