#ifndef TEMP_GLOBALS_H
#define TEMP_GLOBALS_H

#include "gba.h"
#include "types.h"
#include "structs/cutscene.h"


union NonGameplayRAM {
    struct CutsceneData cutscene;
    u8 inGame[1576];
};

extern u16 unk_02035400;

extern u8 gUnk_03004fc9;
extern union NonGameplayRAM gNonGameplayRAM;

extern u16 gBG0HOFS_NonGameplay;
extern u16 gBG0VOFS_NonGameplay;
extern u16 gBG1HOFS_NonGameplay;
extern u16 gBG1VOFS_NonGameplay;
extern u16 gBG2HOFS_NonGameplay;
extern u16 gBG2VOFS_NonGameplay;
extern u16 gBG3HOFS_NonGameplay;
extern u16 gBG3VOFS_NonGameplay;


extern void* const sMemoryPointers[1];

extern union NonGameplayRAM* const sNonGameplayRAMPointer[1];

#endif