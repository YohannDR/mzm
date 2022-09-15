#ifndef SAVE_PLATFORM_CHOZODIA_AI_H
#define SAVE_PLATFORM_CHOZODIA_AI_H

#include "../types.h"

void SavePlatformChozodiaInit(void);
void SavePlatformChozodiaSamusDetection(void);
void SavePlatformChozodiaCheckOpeningAnimEnded(void);
void SavePlatformChozodiaSecondSamusDetection(void);
void SavePlatformChozodiaCheckClosingAnimEnded(void);
void SavePlatformChozodiaReleaseSamus(void);
void SavePlatformChozodiaSamusDetectionOut(void);
void SavePlatformChozodiaCheckRefill(void);
void SavePlatformChozodiaRefill(void);
void SavePlatformChozodiaAfterRefill(void);
void SavePlatformChozodiaSaveInput(void);
void SavePlatformChozodiaFlashingAnim(void);
void SavePlatformChozodiaFlashingAnimEnd(void);
void SavePlatformChozodiaTextTimer(void);
void SavePlatformChozodiaCheckMessageBannerOut(void);
void SavePlatformChozodiaMessageBannerDisappearingTimer(void);
void SavePlatformChozodiaPartInit(void);
void SavePlatformChozodiaPartCheckRefillAnimEnded(void);
void SavePlatformChozodiaPart_Empty(void);
void SavePlatformChozodiaPartExtendGFXInit(void);
void SavePlatformChozodiaPartCheckExtendingAnimEnded(void);
void SavePlatformChozodiaPartRetractingGFXInit(void);
void SavePlatformChozodiaPartCheckRetractingAnimEnded(void);
void SavePlatformChozodiaPartCheckTubeAnimSpawnEnded(void);
void SavePlatformChozodiaPartCheckSpawnBigLight(void);
void SavePlatformChozodiaPartCheckTubeAnimEnded(void);
void SavePlatformChozodiaPartCheckTubeDespawningAnimEnded(void);
void SavePlatformChozodiaPartCheckTubeAroundAnimEnded(void);
void SavePlatformChozodiaPartTubeDownUpAnim(void);
void SavePlatformChozodia(void);
void SavePlatformChozodiaPart(void);

#endif /* SAVE_PLATFORM_CHOZODIA_AI_H */