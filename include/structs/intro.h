#ifndef INTRO_STRUCT_H
#define INTRO_STRUCT_H

#include "types.h"

#define INTRO_DATA sNonGameplayRAMPointer->intro

struct IntroData {
    u8 stage; // 0
    u8 currentCharacter; // 1
    u8 characterPalette; // 2
    u8 nextCharacter; // 3
    
    i16 charDrawerY; // 4
    u16 charDrawerX; // 6
    u8 charDrawerPalette; // 8

    u8 unk_9; // 9
    u8 unk_A; // A

    u16 timer; // C
    u16* pTextOamFramePointer; // 10
    u16 fuzzPalette[16]; // 14

    u16 rotation; // 34
    i16 scaling; // 36

    u8 padding_38_3c[5]; // 38

    u8 unk_3d; // 3D
    u16 shipFlyingTowardsCameraX; // 3E
    u16 shipFlyingTowardsCameraY; // 40

    u8 unk_42; // 42

    u16 dispcnt; // 44
    u16 bldcnt; // 46
};

#endif /* INTRO_STRUCT_H */
