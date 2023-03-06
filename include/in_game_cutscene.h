#ifndef IN_GAME_CUTSCENE_H
#define IN_GAME_CUTSCENE_H

#include "types.h"

u8 InGameCutsceneSamusCloseUp(u8 cutsceneNumber, u8 cutsceneNumberNoFlag);
void unk_5fd58(void);

u8 InGameCutsceneUpgradingSuit(u8 cutsceneNumber, u8 cutsceneNumberNoFlag);
u16 InGameCutsceneCalculateSuitFlashOffset(u8 intensity, u8 start, u8 end);

void MakeBackgroundFlash(u8 type);

void InGameCutsceneStart(u8 number);
void InGameCutsceneProcess(void);
void InGameCutsceneinit(void);
void LoadFirstRoom(void);

u8 unk_60760(u8 param_1);
void unk_60800(void);

void UpdateAnimatedPaletteAfterTransitionOrReload(void);
u8 unk_6087c(u8 param_1, u8 param_2);

#endif /* IN_GAME_CUTSCENE_H */
