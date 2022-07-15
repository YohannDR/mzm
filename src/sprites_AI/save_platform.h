#ifndef SAVE_PLATFORM_AI_H
#define SAVE_PLATFORM_AI_H

#include "../types.h"

u8 SavePlatformDetectSamus(void);
void SavePlatformInit(void);
void SavePlatformSamusDetection(void);
void SavePlatformCheckOpeningAnimEnded(void);
void SavePlatformSecondSamusDetection(void);
void SavePlatformCheckClosingAnimEnded(void);
void SavePlatformReleaseSamus(void);
void SavePlatformSamusDetectionOut(void);
void SavePlatformSpawnSprites(void);
void SavePlatformFlashingAnim(void);
void SavePlatformFlashingAnimEnd(void);
void SavePlatformTextTimer(void);
void SavePlatformCheckMessageBannerOut(void);
void SavePlatformMessageBannerDisappearingTimer(void);
void SavePlatformTopInit(void);
void SavePlatformTop_Empty(void);
void SavePlatformTopExtendGFXInit(void);
void SavePlatformTopCheckExtendingEnded(void);
void SavePlatformTopRetractGFXInit(void);
void SavePlatformTopCheckRetractingAnimEnded(void);
void SavePlatformTopCheckTubeAnimSpawnEnded(void);
void SavePlatformTopSpawnBigLight(void);
void SavePlatformTopCheckTubeAnimEnded(void);
void SavePlatformTopCheckTubeAnimDespawnEnded(void);
void SavePlatformTopCheckTubeAroundAnimEnded(void);
void SavePlatformTopTubeDownUpAnim(void);
void SavePlatform(void);
void SavePlatformTop(void);

#endif /* SAVE_PLATFORM_AI_H */