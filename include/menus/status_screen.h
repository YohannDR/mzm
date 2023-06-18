#ifndef STATUS_SCREEN_MENU_H
#define STATUS_SCREEN_MENU_H

#include "types.h"

void UpdateMinimapAnimatedPalette(void);
void LoadPauseScreenBgPalette(void);
void UpdateSuitType(u8 newSuit);
u32 StatusScreenDrawItems(u8 row);
u8 StatusScreenGetSlotForNewItem(u8 param_1, u8 item);
void StatusScreenDraw(void);
void StatusScreenSetPistolVisibility(u16* pTilemap);
void StatusScreenDrawSingleTankAmount(u8 group, u16 amout, u8 palette, u8 isMax);
void StatusScreenSetBeamsVisibility(u16* pTilemap);
void StatusScreenSetSuitsVisibility(u16* pTilemap);
void StatusScreenSetMiscsVisibility(u16* pTilemap);
void StatusScreenSetBombsVisibility(u16* pTilemap);
void StatusScreenSetMissilesVisibility(u16* pTilemap);
void StatusScreenUpdateRow(u8 group, u8 row, u8 isActivated, u8 param_4);
void StatusScreenEnableUnknownItem(u8 group, u8 row);
u32 StatusScreenCheckitemToggleInput(u16 button);
void StatusScreenInitCursorAndItems(void);
u32 StatusScreenSuitlessItems(void);
u32 StatusScreenFindUnknownItemSlot(u8 param_1);
u32 StatusScreenUpdateUnknownItemPalette(u8 param_1);
u32 StatusScreenFullyPoweredItems(void);
void StatusScreenSubroutine(void);
u8 StatusScreenGetCurrentEquipmentSelected(u8 statusSlot);
u32 StatusScreenUpdateCursorPosition(u8 statusSlot);
u32 StatusScreenIsStatusSlotEnabled(u8 statusSlot);
u32 StatusScreenToggleItem(u8 statusSlot, u8 action);
void StatusScreenMoveCursor(void);
u32 StatusScreenGetDestinationSlot(s8 offset, u8 previousSlot);

#endif /* STATUS_SCREEN_MENU_H */
