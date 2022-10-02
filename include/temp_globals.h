#ifndef TEMP_GLOBALS_H
#define TEMP_GLOBALS_H

#include "types.h"
#include "structs/cutscene.h"

extern u16 unk_02035400;

extern u8 gUnk_03004fc9;
extern u8 gNonGameplayRAM[640]; // Weird type, subject to change

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

union NonGameplayRAM {
    struct CutsceneData cutscene;
};

union NonGameplayRAM* const sNonGameplayRAMPointer;

#endif