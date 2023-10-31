#ifndef STATUS_SCREEN_MENU_DATA_H
#define STATUS_SCREEN_MENU_DATA_H

#include "types.h"
#include "structs/menus/status_screen.h"

extern const u16 sStatusScreen_40dd10[6 * 16];
extern const u16 sStatusScreen_40ddd0[4 * 16];

extern const u8 sStatusScreenGroupsData[13][5];
extern const u8 sStatusScreenUnknownItemsData[10][5];
extern const struct StatusScreenItemData sStatusScreenItemsData[18];
extern const struct StatusScreenItemAcquisitionData sStatusScreenItemsAcquisitionData[22];

extern const u8 sStatusScreen_40df64[8];
extern const u8 sStatusScreen_40df6c[6];
extern const u8 sStatusScreen_40df72[6];

#endif /* STATUS_SCREEN_MENU_DATA_H */
