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
void SavePlatformPartChozodiaInit(void);
void SavePlatformPartChozodiaCheckRefillAnimEnded(void);
void SavePlatformPartChozodia_Empty(void);
void SavePlatformPartChozodiaExtendGFXInit(void);
void SavePlatformPartChozodiaCheckExtendingAnimEnded(void);
void SavePlatformPartChozodiaRetractingGFXInit(void);
void SavePlatformPartChozodiaCheckRetractingAnimEnded(void);
void SavePlatformPartChozodiaCheckTubeAnimSpawnEnded(void);
void SavePlatformPartChozodiaCheckSpawnBigLight(void);
void SavePlatformPartChozodiaCheckTubeAnimEnded(void);
void SavePlatformPartChozodiaCheckTubeDespawningAnimEnded(void);
void SavePlatformPartChozodiaCheckTubeAroundAnimEnded(void);
void SavePlatformPartChozodiaTubeDownUpAnim(void);
void SavePlatformChozodia(void);
void SavePlatformPartChozodia(void);

#endif /* SAVE_PLATFORM_CHOZODIA_AI_H */