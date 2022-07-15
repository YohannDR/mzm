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
void SavePlatformTopChozodiaInit(void);
void SavePlatformTopChozodiaCheckRefillAnimEnded(void);
void SavePlatformTopChozodia_Empty(void);
void SavePlatformTopChozodiaExtendGFXInit(void);
void SavePlatformTopChozodiaCheckExtendingAnimEnded(void);
void SavePlatformTopChozodiaRetractingGFXInit(void);
void SavePlatformTopChozodiaCheckRetractingAnimEnded(void);
void SavePlatformTopChozodiaCheckTubeAnimSpawnEnded(void);
void SavePlatformTopChozodiaCheckSpawnBigLight(void);
void SavePlatformTopChozodiaCheckTubeAnimEnded(void);
void SavePlatformTopChozodiaCheckTubeDespawningAnimEnded(void);
void SavePlatformTopChozodiaCheckTubeAroundAnimEnded(void);
void SavePlatformTopChozodiaTubeDownUpAnim(void);
void SavePlatformChozodia(void);
void SavePlatformTopChozodia(void);

#endif /* SAVE_PLATFORM_CHOZODIA_AI_H */