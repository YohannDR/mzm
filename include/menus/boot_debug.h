#ifndef BOOT_DEBUG_H
#define BOOT_DEBUG_H

#include "types.h"
#include "structs/game_state.h"

void BootDebugUpdateMenuOam(void);
void BootDebugSetupMenuOam(void);
void BootDebugUpdateCursorOam(void);
void BootDebugUpdateNonCursorOam(void);
void BootDebugUpdateMapScreenPosition(void);
void BootDebugReadSram(void);
void BootDebugWriteSram(u8 selectSaveFile);
s32 BootDebugSubroutine(void);
void BootDebugSetVBlankCodePtr(void);
void VBlankCodeDuringBootDebug(void);
void BootDebugSetupMenu(void);
s32 BootDebugHandleInput(void);
s32 BootDebugSectionSubroutine(void);
void BootDebugSectionMapRoomOrDoorUpdated(u8 roomOrDoor);
void BootDebugSectionMapDrawRoomAndDoorIds(u8 initialized);
void BootDebugModeSubroutine(void);
void BootDebugSaveSubroutine(void);
void BootDebugSaveUpdateText(u8 subMenuOption, struct FileScreenOptionsUnlocked* fileScreenOptions);
void BootDebugSaveSetSaveTextColor(void);
void BootDebugSamusSubroutine(void);
void BootDebugSoundSubroutine(void);
void BootDebugSetSoundTestIdColor(void);
s32 BootDebugDemoSubroutine(void);
s32 BootDebugEtcSubroutine(void);
void BootDebugDrawMenuNames(void);
void BootDebugDrawSubMenuText(void);
void BootDebugDrawTextAtPosition(u8 background, u8 xPosition, u8 yPosition, u8 palette, u8 size, const u8* text);
void BootDebugSectionDrawStar(u8 prevIndex);
void BootDebugSectionSetFilesColor(void);
void BootDebugDrawSubMenuOptionText(u8 subMenu, u8 subMenuOption);
void BootDebugDrawNumber(u16* dst, u8 number, u8 numDigits, u8 palette);
void BootDebugDrawTextAtAddress(u16* dst, const u8* text, u8 palette);

#endif
