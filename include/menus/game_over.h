#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "types.h"

u32 GameOverSubroutine(void);
u32 GameOverProcessInput(void);
void GameOverUpdateTextGfx(void);
void GameOverInit(void);
void GameOverInit_Unused(void);
void GameOverVBlank(void);
void GameOverVBlank_Empty(void);
void GameOverUpdateLettersPalette(void);
void GameOverUpdateSamusHead(u8 action);
void GameOverProcessOAM(void);

#endif /* GAME_OVER_H */
