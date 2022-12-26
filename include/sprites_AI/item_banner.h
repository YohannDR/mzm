#ifndef ITEM_BANNER_AI_H
#define ITEM_BANNER_AI_H

#include "types.h"

// Item banner

#define ITEM_BANNER_POSE_GFX_INIT 0x8
#define ITEM_BANNER_POSE_POP_UP 0x9
#define ITEM_BANNER_POSE_STATIC 0x23
#define ITEM_BANNER_POSE_REMOVAL_INIT 0x24
#define ITEM_BANNER_POSE_REMOVAL_ANIMATION 0x25

// Save yes no cursor

#define SAVE_YES_NO_CURSOR_POSE_INPUT 0x9
#define SAVE_YES_NO_CURSOR_POSE_SAVING 0x43

#define SAVE_YES_NO_CURSOR_LEFT_POSITION 0x36
#define SAVE_YES_NO_CURSOR_RIGHT_POSITION 0x96

void ItemBannerInit(void);
void ItemBannerGFXInit(void);
void ItemBannerPopUp(void);
void ItemBannerStatic(void);
void ItemBannerRemovalInit(void);
void ItemBannerRemovalAnimation(void);
void ItemBanner(void);
void SaveYesNoCursor(void);

#endif /* ITEM_BANNER_AI_H* */