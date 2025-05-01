#ifndef STATUS_SCREEN_MENU_DATA_H
#define STATUS_SCREEN_MENU_DATA_H

#include "types.h"
#include "structs/menus/status_screen.h"

extern const u16 sStatusScreenUnknownItemsWhiteFlashingPal[6 * 16];
extern const u16 sStatusScreenUnknownItemsNamesFlashingPal[4 * 16];

extern const u8 sStatusScreenGroupsPositions[13][5];
extern const u8 sStatusScreenUnknownItemsPositions[10][5];
extern const struct StatusScreenItemData sStatusScreenItemsData[18];
extern const struct StatusScreenItemAcquisitionData sStatusScreenItemsAcquisitionData[22];

extern const u8 sStatusScreenUnknownItemsPartialFlash[8];
extern const u8 sStatusScreenUnknownItemsFullFlash[6];
extern const u8 sStatusScreenUnknownItemsNamesFlash[4];

#endif /* STATUS_SCREEN_MENU_DATA_H */
