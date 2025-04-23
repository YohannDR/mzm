#ifndef IN_GAME_H
#define IN_GAME_H

#include "types.h"
#include "structs/samus.h"

u32 InGameMainLoop(void);
void SetVBlankCodeInGame(void);
void TransferSamusGraphics(u32 updatePalette, struct SamusPhysics* pPhysics);
void VBlankCodeInGameLoad(void);
void TransferSamusAndBgGraphics(void);
void VBlankCodeInGame(void);
void VBlankInGame_Empty(void);
void InitAndLoadGenerics(void);
void UpdateNoClip_Debug(void);

#endif /* IN_GAME_H */
