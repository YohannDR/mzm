#include "data/shortcut_pointers.h"

#include "gba.h"
#include "macros.h"
#include "structs/minimap.h"

FORCE_RODATA
void* sEwramPointer = EWRAM_BASE;
FORCE_RODATA
void* sBgPalramPointer = PALRAM_BASE;
FORCE_RODATA
void* sObjPalramPointer = PALRAM_BASE + 0x200;
FORCE_RODATA
u32** sVisitedMinimapTilesPointer = (u32**)&gVisitedMinimapTiles;
FORCE_RODATA
union NonGameplayRAM* sNonGameplayRAMPointer = &gNonGameplayRAM;
FORCE_RODATA
void* sSramEwramPointer = EWRAM_BASE + 0x38000;
FORCE_RODATA
void* sSramFlashPointer = SRAM_BASE;

const u8 sTempArray_754bd0[0x9ad8] = INCBIN_U8("data/Blob_754bd0_75e6a8.bin");
