#ifndef PAUSE_SCREEN_MENU_H
#define PAUSE_SCREEN_MENU_H

#include "types.h"
#include "structs/menu.h"
#include "structs/cutscene.h"

u32 unk_68168(u16 param_1, u8 param_2, u32 param_3);
u8 unk_681c8(void);
u32 PauseScreenUpdateOrStartFading(u8 stage);
void PauseScreenCopyPalramToEwram_Unused(u8 param_1);
void PauseScreenCopyBackgroundPalette_Unused(void);
void PauseScreenUpdateMapArrows(void);
void PauseScreenUpdateBossIcons(void);
void PauseScreenDrawCompletionInfo(u8 dontDraw);
u8 unk_68a58(u8 param_1);
u32 PauseScreenUpdateStatusScreenOam(u8 param_1);
void PauseScreenUpdateWireframeSamus(u8 param_1);
void unk_68ec0(void);
void PauseScreenUpdateWorldMapHighlight(u8 area);
void PauseScreenUpdateWorldMap(u8 onWorldMap);
void PauseScreenLoadAreaNamesAndIcons(void);
void PauseScreenProcessOam(void);
void ProcessMenuOam(u8 length, struct MenuOamData* pOam, const struct OamArray* pOamData);
void ProcessComplexMenuOam(u8 length, struct MenuOamData* pOam, const struct OamArray* pOamData);
void ProcessCutsceneOam(u8 length, struct CutsceneOamData* pOam, const struct OamArray* pOamData);
u32 PauseScreenSubroutine(void);
void PauseScreenVBlank(void);
void PauseScreenVBlank_Empty(void);
void PauseScreenInit(void);
void PauseScreenDetermineMapsViewable(void);
void PauseScreenUpdateBottomVisorOverlay(u8 param_1, u8 param_2);
void PauseScreenGetMinimapData(u8 area, u16* dst);
u32 PauseScreenCallCurrentSubroutine(void);
void PauseScreenMoveDebugCursor(u8 allowOverflow);
u32 unk_6b66c(u16* param_1, u16 param_2);
u32 unk_6b6c4(u16* param_1, u16 param_2);
void PauseScreenUpdateTopVisorOverlay(u8 oamId);
s32 PauseScreenSuitChangingStart(void);
s32 PauseScreenStatusScreenInit(void);
s32 PauseScreenQuitStatusScreen(void);
s32 PauseScreenEasySleepInit(void);
s32 PauseScreenQuitEasySleep(void);
void CheckForMaintainedInput(void);

#endif /* PAUSE_SCREEN_MENU_H */
