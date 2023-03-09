#ifndef HAZE_STRUCT_H
#define HAZE_STRUCT_H

#include "types.h"

typedef u32 (*HazeFunc_T)(void);

struct Haze {
    void* pAffected;
    u16 unk;
    u8 size;
    u8 flag;
};

struct HazeLoop {
    u16 timer;
    u8 unk_2;
    u8 unk_3;
};

extern struct Haze gHazeInfo;
extern struct HazeLoop gHazeLoops[3];

extern u8 gUnk_3005728;
extern u8 gUnk_3005729;

extern HazeFunc_T gHazeProcessCodePointer;

#endif /* HAZE_STRUCT_H */
