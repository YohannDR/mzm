#ifndef PAUSE_SCREEN_MAP_MENU_H
#define PAUSE_SCREEN_MAP_MENU_H

#include "types.h"
#include "structs/menu.h"
#include "structs/cutscene.h"

void PauseScreenCountTanksInArea(void);
void PauseScreenDrawIgtAndTanks(u8 param_1, u8 drawTanks);
void PauseScreenInitMapDownload(void);
u32 PauseScreenMapDownloadSubroutine(void);
u32 PauseScreenMapDownloadInstant_Unused(void);
u32 PauseScreenMapDownloadInstantWithLine_Unused(void);
u32 PauseScreenMapDownload(void);
void PauseScreenMapSetSpawnPosition(u8 spawnOption);
void PauseScreenMapGetAbsoluteMapBordersPositions(void);
void PauseScreenMapUpdateMapBordersForTargets(void);
void PauseScreenGetAllMinimapData(u8 start);
void PauseScreenMapCheckExploredAreas(void);
void MapScreenSubroutine(void);
void MapScreenToggleWorldMap(u8 notOpeningWorldMap);
void MapScreenChangeMap(void);

#endif /* PAUSE_SCREEN_MAP_MENU_H */
