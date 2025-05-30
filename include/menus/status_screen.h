#ifndef STATUS_SCREEN_MENU_H
#define STATUS_SCREEN_MENU_H

#include "types.h"

void UpdateMinimapAnimatedPalette(void);
void LoadPauseScreenBgPalette(void);

#ifdef DEBUG

void PauseDebugUpdateMapOverlay(u8 param_0, u8 area);
void PauseDebugActivateAbilities(void);
u32 PauseDebugSubroutine(void);
void PauseDebugToggleAbility(u8 isActivation, u8 group, u8 abilityNum);
void PauseDebugStatusScreen(void);
void PauseDebugDrawAbilityGroup(u8 group);
void PauseDebugDrawAffectedGroups(u32 groups);
void PauseDebugDrawStaticInfo(void);
u8 PauseDebugEnergyAmmoInput(u8 xOffset, u8 group);
void PauseDebugDrawEnergyAmmoGroup(u8 group);
void PauseDebugDrawEnergyAmmoNumber(u16 number, u8 group);
void PauseDebugEquipTank(u8 tankOrEquip);
void PauseDebugDrawAllGroups(void);
void PauseDebugInitCursor(void);
void PauseDebugDrawEventList(void);
void PauseDebugEventList(void);
void PauseDebugEventListInput(void);
void PauseDebugDrawEventName(u16 event, u16* dst);

#endif

void UpdateSuitType(u8 newSuit);
u32 StatusScreenDrawItems(u8 row);
u8 StatusScreenGetSlotForNewItem(u8 param_1, u8 item);
void StatusScreenDraw(void);
void StatusScreenSetPistolVisibility(u16* pTilemap);
void StatusScreenDrawSingleTankAmount(u8 group, u16 amount, u8 palette, u8 isMax);
void StatusScreenSetBeamsVisibility(u16* pTilemap);
void StatusScreenSetSuitsVisibility(u16* pTilemap);
void StatusScreenSetMiscsVisibility(u16* pTilemap);
void StatusScreenSetBombsVisibility(u16* pTilemap);
void StatusScreenSetMissilesVisibility(u16* pTilemap);
void StatusScreenUpdateRow(u8 group, u8 row, u8 isActivated, u8 drawUpdate);
void StatusScreenEnableUnknownItem(u8 group, u8 row);
u32 StatusScreenCheckitemToggleInput(u16 button);
void StatusScreenInitCursorAndItems(void);
u32 StatusScreenSuitlessItems(void);
u32 StatusScreenFindUnknownItemSlot(u8 wantUnknownItem);
u32 StatusScreenUpdateUnknownItemPalette(u8 stage);
u32 StatusScreenFullyPoweredItems(void);
void StatusScreenSubroutine(void);
u8 StatusScreenGetCurrentEquipmentSelected(u8 statusSlot);
u32 StatusScreenUpdateCursorPosition(u8 statusSlot);
u32 StatusScreenIsStatusSlotEnabled(u8 statusSlot);
u32 StatusScreenToggleItem(u8 statusSlot, u8 action);
void StatusScreenMoveCursor(void);
u32 StatusScreenGetDestinationSlot(s32 offset, u32 previousSlot);

#endif /* STATUS_SCREEN_MENU_H */
