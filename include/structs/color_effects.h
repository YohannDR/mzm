#ifndef COLOR_EFFECTS_STRUCT_H
#define COLOR_EFFECTS_STRUCT_H

#include "types.h"

// Typedef

typedef u8 (*ColorFadingFunc_T)(u8, u8);
typedef u8 (*ColorFadingUnkFunc_T)(void);

// Structs

struct ColorFading {
    u8 type;
    u8 stage;
    u8 fadeTimer;
    u8 unk_3;
    u8 status;
    u8 useSecondColorSet;
    u16 subroutineTimer;
};

struct ColorFadingData {
    u8 isWhite;
    ColorFadingUnkFunc_T pUpdateSubroutine;
    u8 firstColorSet;
    ColorFadingUnkFunc_T pProcessSubroutine;
    u8 secondColorSet;
    u16 bgColorMask;
    u16 objColorMask;
    u8 pFadeSubroutine;
};

struct ColorFadingColorInfo {
    const u8* const colorArray;
    u8 size;
};

// Globals

extern struct ColorFading gColorFading;
extern u16 gBg1CntDuringDoorTransition;
extern u16 gBg3CntDuringDoorTransition;

#endif