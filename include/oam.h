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

#define OAM_OBJ_MODE_NORMAL 0
#define OAM_OBJ_MODE_SEMI_TRANSPARENT 1
#define OAM_OBJ_MODE_WINDOW 2

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

#define FRAME_DATA_TERMINATOR \
{\
    .pFrame = NULL,\
    .timer = 0\
}

union OamData {
    struct {
    /*0x00*/ u32 y:8;
             u32 affineMode:2;  // 0x1, 0x2 -> 0x4
             u32 objMode:2;     // 0x4, 0x8 -> 0xC
             u32 mosaic:1;      // 0x10
             u32 bpp:1;         // 0x20
             u32 shape:2;       // 0x40, 0x80 -> 0xC0

    /*0x01*/ u32 x:9;
             u32 matrixNum:3;
             u32 xFlip:1;
             u32 yFlip:1;
             u32 size:2;        // 0x4000, 0x8000 -> 0xC000

    /*0x02*/ u16 tileNum:10;    // 0x3FF
             u16 priority:2;    // 0x400, 0x800 -> 0xC00
             u16 paletteNum:4;

    /*0x03*/ u16 fractional:8;
             u16 integer:7;
             u16 sign:1;
    } split;

    struct {
        u16 attr0;
        u16 attr1;
        u16 attr2;
        u16 affineParam;
    } all;
};

extern u8 gNextOamSlot;

#define OAM_BUFFER_DATA_SIZE 128
#define OAM_BUFFER_AFFINE_SIZE 32

extern union OamData gOamData[OAM_BUFFER_DATA_SIZE + OAM_BUFFER_AFFINE_SIZE];

#endif /* OAM_H */
