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

extern u16 gWrittenToBLDALPHA_H;
extern u16 gWrittenToBLDALPHA_L;
extern u16 gWrittenToBLDY;

extern u16 gBG0HOFS_NonGameplay;
extern u16 gBG0VOFS_NonGameplay;
extern u16 gBG1HOFS_NonGameplay;
extern u16 gBG1VOFS_NonGameplay;
extern u16 gBG2HOFS_NonGameplay;
extern u16 gBG2VOFS_NonGameplay;
extern u16 gBG3HOFS_NonGameplay;
extern u16 gBG3VOFS_NonGameplay;


void* const sMemoryPointers[] = {
    EWRAM_BASE
};

union NonGameplayRAM* const sNonGameplayRAMPointer[] = {
    &gNonGameplayRAM
};

#endif