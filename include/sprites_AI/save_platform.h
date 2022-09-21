#ifndef SAVE_PLATFORM_AI_H
#define SAVE_PLATFORM_AI_H

#include "types.h"

#define SAVE_PLATFORM_POSE_IDLE 0x9
#define SAVE_PLATFORM_POSE_OPENING 0x23
#define SAVE_PLATFORM_POSE_OPENED 0x25
#define SAVE_PLATFORM_POSE_CLOSING 0x27
#define SAVE_PLATFORM_POSE_RELEASE_SAMUS 0x28
#define SAVE_PLATFORM_POSE_AFTER_SAVE 0x29
#define SAVE_PLATFORM_POSE_SAVE_PROMPT 0x42
#define SAVE_PLATFORM_POSE_SAVING 0x43
#define SAVE_PLATFORM_POSE_OPENED_OFF_INIT 0x45
#define SAVE_PLATFORM_POSE_SPAWN_SAVE_DONE_MESSAGE 0x47
#define SAVE_PLATFORM_POSE_WAIT_FOR_MESSAGE_OUT 0x49
#define SAVE_PLATFORM_POSE_DELAY_BEFORE_RELEASING 0x4B
#define SAVE_PLATFORM_POSE_OFF 0x51

// Save platform part

#define SAVE_PLATFORM_PART_TUBE 0x0
#define SAVE_PLATFORM_PART_TUBE_SHADOW 0x1
#define SAVE_PLATFORM_PART_RAY 0x2
#define SAVE_PLATFORM_PART_TOP 0x3

#define SAVE_PLATFORM_PART_POSE_TUBE_SPAWNING 0x9
#define SAVE_PLATFORM_PART_POSE_TUBE_CHECK_SHADOW_DISAPPEARED 0x23
#define SAVE_PLATFORM_PART_POSE_TUBE_IDLE 0x25
#define SAVE_PLATFORM_PART_POSE_TUBE_DESPAWNING 0x27
#define SAVE_PLATFORM_PART_POSE_TUBE_SHADOW_IDLE 0x29
#define SAVE_PLATFORM_PART_POSE_RAY_IDLE 0x2B
#define SAVE_PLATFORM_PART_POSE_TOP_IDLE 0x43
#define SAVE_PLATFORM_PART_POSE_TOP_EXTENDING_INIT 0x44
#define SAVE_PLATFORM_PART_POSE_TOP_EXTENDING 0x45
#define SAVE_PLATFORM_PART_POSE_TOP_RETRACTING_INIT 0x46
#define SAVE_PLATFORM_PART_POSE_TOP_RETRACTING 0x47


u8 SavePlatformDetectSamus(void);
void SavePlatformInit(void);
void SavePlatformSamusDetection(void);
void SavePlatformCheckOpeningAnimEnded(void);
void SavePlatformSecondSamusDetection(void);
void SavePlatformCheckClosingAnimEnded(void);
void SavePlatformReleaseSamus(void);
void SavePlatformSamusDetectionOut(void);
void SavePlatformSavePrompt(void);
void SavePlatformSaving(void);
void SavePlatformOpenedOffInit(void);
void SavePlatformSpawnSaveDoneMessage(void);
void SavePlatformCheckMessageBannerOut(void);
void SavePlatformDelayBeforeReleasingSamus(void);
void SavePlatformPartInit(void);
void SavePlatformPart_Empty(void);
void SavePlatformPartExtendingInit(void);
void SavePlatformPartTopExtending(void);
void SavePlatformPartTopRetractingInit(void);
void SavePlatformPartTopRetracting(void);
void SavePlatformPartTubeSpawning(void);
void SavePlatformPartSpawnRay(void);
void SavePlatformPartTubeIdle(void);
void SavePlatformPartTubeDespawning(void);
void SavePlatformPartTubeShadowIdle(void);
void SavePlatformPartRayIdle(void);
void SavePlatform(void);
void SavePlatformPart(void);

#endif /* SAVE_PLATFORM_AI_H */