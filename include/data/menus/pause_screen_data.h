#ifndef PAUSE_SCREEN_DATA_H
#define PAUSE_SCREEN_DATA_H

#include "types.h"
#include "structs/cutscene.h"
#include "structs/menus/pause_screen.h"
#include "connection.h"

extern const struct PauseScreenAreaIconData sPauseScreenAreIconsData[MAX_AMOUNT_OF_AREAS];
extern const u16 sPauseScreen_40d0d0[16];

// ...

extern const u8 sBossIcons[7][5];
extern const u16 sMapChunksToUpdate[3];

extern const struct OamArray sPauseScreenMiscOam[56];
extern const struct OamArray sPauseScreenAreaNameOam[33];
extern const struct OamArray sPauseScreenBorderArrowsOam[5];
extern const struct OamArray sPauseScreenSamusIconOam[5];
extern const struct OamArray sPauseScreenBossIconsOam[5];
extern const struct OamArray sPauseScreenTargetsOam[16];
extern const struct OamArray sPauseScreenWorldMapOam[18];

extern const u8 sMaintainedInputDelays[7];

#endif /* PAUSE_SCREEN_DATA_H */
