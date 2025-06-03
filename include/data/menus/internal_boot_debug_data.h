#ifndef INTERNAL_BOOT_DEBUG_DATA_H
#define INTERNAL_BOOT_DEBUG_DATA_H

#include "types.h"
#include "constants/cutscene.h"

#ifdef DEBUG

extern const u8* const sBootDebugCutsceneBTextPointers[CUTSCENE_END];
extern const u8* const sBootDebugCutsceneATextPointers[2];
extern const u8* const sBootDebugDemoStateTextPointers[5];

extern u8 sBootDebugTextToggleColors[2][2];

#endif /* DEBUG */

#endif /* INTERNAL_BOOT_DEBUG_DATA_H */
