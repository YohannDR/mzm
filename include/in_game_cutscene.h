#ifndef IN_GAME_CUTSCENE_H
#define IN_GAME_CUTSCENE_H

#include "types.h"

u32 InGameCutsceneSamusCloseUp(u8 cutsceneNumber, u8 cutsceneNumberNoFlag);
void unk_5fd58(void);

u32 InGameCutsceneUpgradingSuit(u8 cutsceneNumber, u8 cutsceneNumberNoFlag);
u16 InGameCutsceneCalculateSuitFlashOffset(u8 intensity, u8 start, u8 end);

void MakeBackgroundFlash(u8 type);

void InGameCutsceneStart(u8 number);
void InGameCutsceneProcess(void);
void InGameCutsceneInit(void);
void InGameCutsceneCheckPlayOnTransition(void);

u32 InGameCutsceneTryQuery(u8 param_1);
void InGameCutsceneCheckStartQueried(void);

void UpdateAnimatedPaletteAfterTransitionOrReload(void);
u32 InGameCutsceneCheckFlag(u8 setting, u8 param_2);

#endif /* IN_GAME_CUTSCENE_H */
