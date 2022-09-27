#ifndef SAMUS_STRUCT_H
#define SAMUS_STRUCT_H

#include "types.h"

#define MAX_AMOUNT_OF_SAMUS_POSES 67

// Structs

struct Equipment {
    u16 maxEnergy;
    u16 maxMissiles;
    u8 maxSuperMissiles;
    u8 maxPowerBombs;
    u16 currentEnergy;
    u16 currentMissiles;
    u8 currentSuperMissiles;
    u8 currentPowerBombs;
    u8 beamBombs;
    u8 beamBombsActivation;
    u8 suitMisc;
    u8 suitMiscActivation;
    u8 downloadedMapStatus;
    u8 lowHealth;
    u8 suitType;
    u8 grabbedByMetroid;
};


struct WeaponInfo {
    u8 diagonalAim;
    u8 newProjectile;
    u8 weaponHighlighted;
    u8 missilesSelected;
    u8 cooldown;
    u8 chargeCounter;
    u8 beamReleasePaletteTimer;
};

struct SamusData {
    u8 pose;
    u8 standingStatus;
    u8 armCannonDirection;
    u8 turning;
    u8 forcedMovement;
    u8 speedboostingShinesparking;
    u8 invincibilityTimer;
    u8 walljumpTimer;
    u8 shinesparkTimer;
    u8 unmorphPaletteTimer;
    u8 timer;
    u16 lastWallTouchedMidAir;
    u16 direction;
    u16 elevatorDirection;
    u16 xPosition;
    u16 yPosition;
    i16 xVelocity;
    i16 yVelocity;
    u16 currentSlope;
    u8 animationDurationCounter;
    u8 currentAnimationFrame;
};

struct SamusPhysics {
    u16* pBodyOam;
    u8* pShouldersGFX;
    u16 shoulderGFXSize;
    u8* pTorsoGFX;
    u16 torsoGFXSize;
    u8* pLegsGFX;
    u16 legsGFXSize;
    u8* pBodyLowerHalfGFX;
    u16 bodyLowerHalfGFXSize;
    u16 unk;
    u16* pArmCannonOAM;
    u8* pArmCannonGFXUpper;
    u16 armCannonGFXUpperSize;
    u8* pArmCannonGFXLower;
    u16 armCannonGFXLowerSize;
    u16* pScrewSpeedOAM;
    u8* pScrewSpeedGFX;
    u16 screwSpeedGFXSize;
    u8* pScrewShinesparkGFX;
    u16 screwShinesparkGFXSize;
    u16 armCannonXPositionOffset;
    u16 armCannonYPositionOffset;
    u8 horizontalMovingDirection;
    u8 verticalMovingDirection;
    i16 hitboxLeftOffset;
    i16 hitboxRightOffset;
    i16 hitboxTopOffset;
    u8 standingStatus;
    u8 hitboxType; // TODO define
    u8 touchingSideBlock;
    u8 touchingTopBlock;
    u8 unknown;
    u8 slowedByLiquid;
    u8 hasNewProjectile;
    i16 xAcceleration;
    i16 xVelocityCap;
    i16 yAcceleration;
    i16 positiveYVelocityCap;
    i16 negativeYVelocityCap;
    i16 midairXAcceleration;
    i16 midairXVelocityCap;
    i16 midairMorphedXVelocityCap;
    i16 drawDistanceLeftOffset;
    i16 drawDistanceTopOffset;
    i16 drawDistanceRightOffset;
    i16 drawDistanceBottomOffset;
};

struct ScrewSpeedAnimation {
    u8 flag;
    u8 animationDurationCounter;
    u8 currentAnimationFrame;
    u32 unknown;
};

struct HazardDamage {
    u8 damageTimer;
    u16 knockbackTimer;
    u8 paletteTimer;
};

struct EnvironmentalEffect {
    u8 type;
    u8 animationDurationCounter;
    u8 currentAnimationFrame;
    u8 breathingTimer;
    u16 xPosition;
    u16 yPosition;
    struct OamFrame* pOamFrame;
};

struct SamusEcho {
    u8 active;
    u8 timer;
    u8 position;
    u8 distance;
    u16 previous64XPositions[64];
    u16 previous64YPositions[64];
    u16 previousPositionCounter;
    u8 unknown;
};

// Typedefs

typedef u8 (*SamusFunc_T)(struct SamusData*);

// Globals

extern u8 gSamusOnTopOfBackgrounds;
extern struct SamusData gSamusData;
extern struct SamusData gSamusDataCopy;
extern struct WeaponInfo gSamusWeaponInfo;
extern struct SamusEcho gSamusEcho;
extern struct ScrewSpeedAnimation gScrewSpeedAnimation;
extern struct Equipment gEquipment;
extern struct HazardDamage gSamusHazardDamage;
extern struct EnvironmentalEffect gSamusEnvirnmentalEffects[5];
extern struct SamusPhysics gSamusPhysics;
extern u16 gPreviousXPosition;
extern u16 gPreviousYPosition;
extern u16 gPreventMovementTimer;

extern u16 gSamusPalette[16 * 2];
extern i16 gSamusDoorPositionOffset;

#endif