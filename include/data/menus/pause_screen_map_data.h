#ifndef PAUSE_SCREEN_MAP_DATA_H
#define PAUSE_SCREEN_MAP_DATA_H

#include "types.h"
#include "structs/cutscene.h"
#include "structs/menus/pause_screen.h"
#include "connection.h"

extern const u8 sPauseScreen_40d6fc[80];
extern const u8 sPauseScreen_40d74c[80];

extern const u8 sMinimapTilesGfx[5120];
extern const u32 sPauseScreen_40f4c4[1792];
extern const u32 sMapScreenAreaNamesGfx[167];
extern const u16 sMinimapTilesPal[5 * 16];

// Temp
// FORCE_RODATA
extern u32* sPauseScreen_7602a8;
// FORCE_RODATA
extern u8 sMapDownloadLineTrailOamOffsets[4];
extern const u32 sPauseScreen_7602b0[9];

#endif /* PAUSE_SCREEN_MAP_DATA_H */
