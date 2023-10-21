#ifndef SAMUS_STRUCT_H
#define SAMUS_STRUCT_H

#include "types.h"
#include "macros.h"

#define SAMUS_CARRY_ELEVATOR_DIR()\
do {\
    pData->elevatorDirection = pCopy->elevatorDirection;\
}while(0);

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
    s16 xVelocity;
    s16 yVelocity;
    u16 currentSlope;
    u8 animationDurationCounter;
    u8 currentAnimationFrame;
};

struct SamusPhysics {
    const u16* pBodyOam;
    const u8* pShouldersGfx;
    u16 shoulderGfxSize;
    const u8* pTorsoGfx;
    u16 torsoGfxSize;
    const u8* pLegsGfx;
    u16 legsGfxSize;
    const u8* pBodyLowerHalfGfx;
    u16 bodyLowerHalfGfxSize;
    u16 unk_22;
    const u16* pArmCannonOam;
    const u8* pArmCannonGfxUpper;
    u16 armCannonGfxUpperSize;
    const u8* pArmCannonGfxLower;
    u16 armCannonGfxLowerSize;
    u8 unk_36;
    const u16* pScrewSpeedOam;
    const u8* pScrewSpeedGfx;
    u16 screwSpeedGfxSize;
    const u8* pScrewShinesparkGfx;
    u16 screwShinesparkGfxSize;
    u16 armCannonXPositionOffset;
    u16 armCannonYPositionOffset;
    u8 horizontalMovingDirection;
    u8 verticalMovingDirection;
    s16 hitboxLeftOffset;
    s16 hitboxRightOffset;
    s16 hitboxTopOffset;
    u8 standingStatus;
    u8 hitboxType;
    u8 touchingSideBlock;
    u8 touchingTopBlock;
    u8 unk_5A;
    u8 slowedByLiquid;
    u8 hasNewProjectile;
    s16 xAcceleration;
    s16 xVelocityCap;
    s16 yAcceleration;
    s16 positiveYVelocityCap;
    s16 negativeYVelocityCap;
    s16 midairXAcceleration;
    s16 midairXVelocityCap;
    s16 midairMorphedXVelocityCap;
    s16 drawDistanceLeftOffset;
    s16 drawDistanceTopOffset;
    s16 drawDistanceRightOffset;
    s16 drawDistanceBottomOffset;
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
    const u16* pOamFrame;
};

struct SamusEcho {
    u8 active;
    u8 timer;
    u8 position;
    u8 distance;
    u32 padding_4;
    u16 previous64XPositions[64];
    u16 previous64YPositions[64];
    s16 previousPositionCounter;
    s8 unknown;
};

struct ArmCannonOffset {
    s16 y;
    s16 x;
};

struct SamusAnimationData {
    const u8* const pTopGfx;
    const u8* const pBottomGfx;
    const u16* const pOam;
    u8 timer;
};

struct ArmCannonAnimationData {
    const struct ArmCannonOffset* const pOffset;
    const u16* const pOam;
};

struct SamusEffectAnimationData {
    const u8* const pGraphics;
    const u16* const pOam;
    u8 timer;
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
extern struct EnvironmentalEffect gSamusEnvironmentalEffects[5];
extern struct SamusPhysics gSamusPhysics;
extern u16 gPreviousXPosition;
extern u16 gPreviousYPosition;
extern u16 gPreventMovementTimer;
extern u8 gDisableDrawingSamusAndScrolling;

extern u16 gSamusPalette[16 * 2];
extern u16 gSamusPaletteSize;
extern s16 gSamusDoorPositionOffset;

#endif /* SAMUS_STRUCT_H */
