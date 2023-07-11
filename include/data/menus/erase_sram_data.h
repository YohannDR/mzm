#ifndef ERASE_SRAM_MENU_DATA_H
#define ERASE_SRAM_MENU_DATA_H

#include "types.h"
#include "structs/cutscene.h"

extern const u16 sEraseSramMenuObjectsPal[7 * 16];
extern const u16 sEraseSramMenuBackgroundPal[15 * 16 - 1];

// ...

extern const u32 sEraseSramMenuObjectsGfx[477];
extern const u32 sEraseSramMenuFirstBoxGfx[118];
extern const u32 sEraseSramMenuConfirmJapanseGfx[245];
extern const u32 sEraseSramMenuConfirmEnglishGfx[1027];
extern const u32 sEraseSramMenuQuestionJapaneseGfx[245];
extern const u32 sEraseSramMenuQuestionEnglishGfx[1006];
extern const u32 sEraseSramMenuBoxTileTable[137];
extern const u32 sEraseSramMenuBackgroundTileTable[368];

extern const u8 sEraseSramQuestionWindowNoSelectedOamId;
extern const u8 sEraseSramQuestionWindowYesSelectedOamId;
extern const u8 sEraseSramConfirmWindowNoSelectedOamId;
extern const u8 sEraseSramConfirmWindowYesSelectedOamId;
extern const u16 sEraseSramMenuSoundsID[5];
extern const u16 sEraseSramMenuCursorPosition[2][2];
extern const u16 sEraseSramMenuCursorPositionOffset[4][2];
extern const struct OamArray sEraseSramMenuOam[7];

#endif /* ERASE_SRAM_MENU_DATA_H */
