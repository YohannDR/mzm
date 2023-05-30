#ifndef SHORTCUT_POINTERS_H
#define SHORTCUT_POINTERS_H

#include "types.h"
#include "temp_globals.h"
#include "structs/save_file.h"

extern union EwramData* sEwramPointer;
extern u16* sBgPalramPointer;
extern u16* sObjPalramPointer;
extern u32* sVisitedMinimapTilesPointer;
extern union NonGameplayRAM* sNonGameplayRamPointer;
extern struct Sram* sSramEwramPointer;
extern struct Sram* sSramFlashPointer;

#endif /* SHORTCUT_POINTERS_H */
