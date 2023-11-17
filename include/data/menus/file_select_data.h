#ifndef FILE_SELECT_MENU_DATA_H
#define FILE_SELECT_MENU_DATA_H

#include "types.h"
#include "structs/menu.h"
#include "structs/cutscene.h"
#include "structs/text.h"

extern const u16 sFileSelectPal[7 * 16];
extern const u16 sFileSelect_4548f8[2 * 16];
extern const u16 sFileSelectIconsPal[6 * 16];

extern const struct FrameData sFileSelectOam_SamusHeadTurningOn[5];
extern const struct FrameData sFileSelectOam_SamusHeadTurning[11];
extern const struct FrameData sFileSelectOam_SamusHeadSuitlessTurningOn[6];
extern const struct FrameData sFileSelectOam_SamusHeadSuitlessIdle[5];
extern const struct FrameData sFileSelectOam_SamusHeadSuitlessTurning[8];

extern const u32 sFileSelectChozoBackgroundGfx[2985];
extern const u32 sFileSelectCharactersGfx[1531];
extern const u32 sFileSelectTextGfx[1725];
extern const u32 sFileSelectIconsGfx[1722];
extern const u32 sFileSelectChozoBackgroundTileTable[368];
extern const u32 sFileSelectMenuTileTable[148];
extern const u32 sFileSelectOptionsTileTable[188];
extern const u32 sFileSelect3BigPanelsTileTable[233];
extern const u32 sFileSelect1Small2BigPanelsTileTable[233];
extern const u32 sFileSelect2Big1SmallPanelsTileTable[230];

extern const struct MenuOamData sFileSelectOamData_Empty[2];

extern const struct OamArray sFileSelectOam[40];
extern const struct OamArray sOptionsOam[22];

extern const u8 sFileScreenMessagesInfo[33][3];
extern const struct Message sFileScreenMessage_Empty;

extern const u8 sNesMetroidDataCheck[18];
extern const u16 sTimeAttackButtonCode[5];

#endif /* FILE_SELECT_MENU_DATA_H */
