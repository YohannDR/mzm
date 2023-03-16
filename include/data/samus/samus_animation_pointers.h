#ifndef SAMUS_ANIMATION_POINTERS_DATA_H
#define SAMUS_ANIMATION_POINTERS_DATA_H

#include "types.h"
#include "structs/samus.h"

extern const struct EnvironmentalEffect sEnvironmentalEffect_Empty;

// Power suit

extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit[MAX_AMOUNT_OF_SAMUS_POSES][2];

extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_Running[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_Running_Speedboosting[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_Standing[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_TurningAround[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_Shooting[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_Crouching[3][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_TurningAroundAndCrouching[3][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_ShootingAndCrouching[3][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_Skidding[2][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_MidAir[5][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_TurningAroundMidAir[5][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_Landing[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_ScrewAttacking[1][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_SpaceJumping[1][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_AimingWhileHanging[5][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_ShootingWhileHanging[5][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_UsingAnElevator[2][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_Shinesparking[3][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_OnZipline[5][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_ShootingOnZipline[5][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_PowerSuit_TurningOnZipline[5][2];

extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_All[MAX_AMOUNT_OF_SAMUS_POSES][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_Running[4][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_Running_Speedboosting[4][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_Standing[4][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_TurningAround[4][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_Shooting[4][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_Crouching[3][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_TurningAroundAndCrouching[3][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_ShootingAndCrouching[3][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_MidAir[5][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_TurningAroundMidAir[5][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_Landing[4][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_AimingWhileHanging[5][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_ShootingWhileHanging[5][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_UsingAnElevator[2][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_Shinesparking[3][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_OnZipline[5][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_ShootingOnZipline[5][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_PowerSuit_TurningOnZipline[5][2];

extern const u8 sSamusVisualData[MAX_AMOUNT_OF_SAMUS_POSES][3];


// Full suit

extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit[MAX_AMOUNT_OF_SAMUS_POSES][2];

extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_Running[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_Running_Speedboosting[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_Standing[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_TurningAround[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_Shooting[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_Crouching[3][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_TurningAroundAndCrouching[3][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_ShootingAndCrouching[3][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_Skidding[2][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_MidAir[5][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_TurningAroundMidAir[5][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_Landing[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_ScrewAttacking[1][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_SpaceJumping[1][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_AimingWhileHanging[5][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_ShootingWhileHanging[5][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_UsingAnElevator[2][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_Shinesparking[3][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_OnZipline[5][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_ShootingOnZipline[5][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_FullSuit_TurningOnZipline[5][2];


// Suitless

extern const struct SamusAnimationData* const sSamusAnimPointers_Suitless[MAX_AMOUNT_OF_SAMUS_POSES][2];

extern const struct SamusAnimationData* const sSamusAnimPointers_Suitless_Running[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_Suitless_Standing[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_Suitless_TurningAround[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_Suitless_Shooting[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_Suitless_Crouching[3][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_Suitless_TurningAroundAndCrouching[3][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_Suitless_ShootingAndCrouching[3][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_Suitless_MidAir[5][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_Suitless_TurningAroundMidAir[5][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_Suitless_Landing[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_Suitless_AimingWhileHanging[5][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_Suitless_ShootingWhileHanging[5][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_Suitless_UncrouchingSuitless[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_Suitless_CrouchingSuitless[4][2];
extern const struct SamusAnimationData* const sSamusAnimPointers_Suitless_CrawlingStopped[3][2];

extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_All[MAX_AMOUNT_OF_SAMUS_POSES][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_Running[4][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_Standing[4][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_TurningAround[4][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_Shooting[4][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_Crouching[3][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_TurningAroundAndCrouching[3][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_ShootingAndCrouching[3][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_MidAir[5][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_TurningAroundMidAir[5][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_Landing[4][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_AimingWhileHanging[5][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_ShootingWhileHanging[5][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_UncrouchingSuitless[4][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_CrouchingSuitless[4][2];
extern const struct ArmCannonAnimationData* const sArmCannonAnimPointers_Suitless_CrawlingStopped[3][2];

// Palette pointers

extern const u16* const sSamusPal_PowerSuit_SavingPointers[11];
extern const u16* const sSamusPal_VariaSuit_SavingPointers[11];
extern const u16* const sSamusPal_FullSuit_SavingPointers[11];
extern const u16* const sSamusPal_GravitySuit_SavingPointers[11];
extern const u16* const sSamusPal_Suitless_SavingPointers[11];

extern const u16* const sSamusPal_PowerSuit_DownloadingMapPointers[8];
extern const u16* const sSamusPal_VariaSuit_DownloadingMapPointers[8];
extern const u16* const sSamusPal_FullSuit_DownloadingMapPointers[8];
extern const u16* const sSamusPal_GravitySuit_DownloadingMapPointers[8];
extern const u16* const sSamusPal_Suitless_DownloadingMapPointers[8];

// Arm cannon graphics pointers

extern const u8* const sArmCannonGfxPointers_Upper_Standing[5];
extern const u8* const sArmCannonGfxPointers_Lower_Standing[5];
extern const u8* const sArmCannonGfxPointers_Armed_Upper_Standing[5];
extern const u8* const sArmCannonGfxPointers_Armed_Lower_Standing[5];

extern const u8* const sArmCannonGfxPointers_Upper_Right_Default[5];
extern const u8* const sArmCannonGfxPointers_Lower_Right_Default[5];
extern const u8* const sArmCannonGfxPointers_Upper_Left_Default[5];
extern const u8* const sArmCannonGfxPointers_Lower_Left_Default[5];

extern const u8* const sArmCannonGfxPointers_Upper_Right_Armed_Default[5];
extern const u8* const sArmCannonGfxPointers_Lower_Right_Armed_Default[5];
extern const u8* const sArmCannonGfxPointers_Upper_Left_Armed_Default[5];
extern const u8* const sArmCannonGfxPointers_Lower_Left_Armed_Default[5];

extern const u8* const sArmCannonGfxPointers_Upper_Left_Hanging[5];
extern const u8* const sArmCannonGfxPointers_Lower_Left_Hanging[5];
extern const u8* const sArmCannonGfxPointers_Upper_Right_Hanging[5];
extern const u8* const sArmCannonGfxPointers_Lower_Right_Hanging[5];

extern const u8* const sArmCannonGfxPointers_Upper_Left_Armed_Hanging[5];
extern const u8* const sArmCannonGfxPointers_Lower_Left_Armed_Hanging[5];
extern const u8* const sArmCannonGfxPointers_Upper_Right_Armed_Hanging[5];
extern const u8* const sArmCannonGfxPointers_Lower_Right_Armed_Hanging[5];

extern const u8* const sArmCannonGfxPointers_Upper_Right_OnZipline[5];
extern const u8* const sArmCannonGfxPointers_Lower_Right_OnZipline[5];
extern const u8* const sArmCannonGfxPointers_Upper_Right_Armed_OnZipline[5];
extern const u8* const sArmCannonGfxPointers_Lower_Right_Armed_OnZipline[5];

// Samus effects pointers

extern const struct SamusEffectAnimationData* const sSamusEffectAnimPointers_Speedboosting[1][2];
extern const struct SamusEffectAnimationData* const sSamusEffectAnimPointers_Shinesparking[3][2];
extern const struct SamusEffectAnimationData* const sSamusEffectAnimPointers_Ballsparking[3][2];



extern const i16 sSamusDrawDistanceOffsets[4][4];
extern const i16 sSamusHitboxData[4][4];
extern const struct FrameData* const sSamusEnvEffectsFrameDataPointers[18];
const u16 sSamusPullingSelfUpVelocity[8];

#endif /* SAMUS_ANIMATION_POINTERS_DATA_H */
