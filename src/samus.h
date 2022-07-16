#ifndef SAMUS_H
#define SAMUS_H

#include "types.h"
#include "oam.h"
#include "game_modes.h"

// Globals

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

extern u16 gSamusPalette[32];
extern i16 gSamusDoorPositionOffset;

// Defines

#define BBF_NONE 0x0
#define BBF_LONG_BEAM 0x1
#define BBF_ICE_BEAM 0x2
#define BBF_WAVE_BEAM 0x4
#define BBF_PLASMA_BEAM 0x8
#define BBF_CHARGE_BEAM 0x10
#define BBF_BOMBS 0x80

#define SMF_NONE 0x0
#define SMF_HIGH_JUMP 0x1
#define SMF_SPEED_BOOSTER 0x2
#define SMF_SPACE_JUMP 0x4
#define SMF_SCREW_ATTACK 0x8
#define SMF_VARIA_SUIT 0x10
#define SMF_GRAVITY_SUIT 0x20
#define SMF_MORPH_BALL 0x40
#define SMF_POWER_GRIP 0x80

#define SUIT_NORMAL 0x0
#define SUIT_FULLY_POWERED 0x1
#define SUIT_SUITLESS 0x2

#define DIAG_AIM_NONE 0x0
#define DIAG_AIM_UP 0x1
#define DIAG_AIM_DOWN 0x2

#define WH_NONE 0x0
#define WH_MISSILE 0x1
#define WH_SUPER_MISSILE 0x2
#define WH_POWER_BOMB 0x4

#define SPOSE_RUNNING 0x0
#define SPOSE_STANDING 0x1
#define SPOSE_TURNING_AROUND 0x2
#define SPOSE_SHOOTING 0x3
#define SPOSE_CROUCHING 0x4
#define SPOSE_TURNING_AROUND_AND_CROUCHING 0x5
#define SPOSE_SHOOTING_AND_CROUCHING 0x6
#define SPOSE_SKIDDING 0x7
#define SPOSE_MIDAIR 0x8
#define SPOSE_TURNING_AROUND_MIDAIR 0x9
#define SPOSE_LANDING 0xA
#define SPOSE_STARTING_SPIN_JUMP 0xB
#define SPOSE_SPINNING 0xC
#define SPOSE_STARTING_WALL_JUMP 0xD
#define SPOSE_SPACE_JUMPING 0xE
#define SPOSE_SCREW_ATTACKING 0xF
#define SPOSE_MORPHING 0x10
#define SPOSE_MORPH_BALL 0x11
#define SPOSE_ROLLING 0x12
#define SPOSE_UNMORPHING 0x13
#define SPOSE_MORPH_BALL_MIDAIR 0x14
#define SPOSE_HANGING_ON_LEDGE 0x15
#define SPOSE_TURNING_TO_AIM_WHILE_HANGING 0x16
#define SPOSE_HIDING_ARM_CANNON_WHILE_HANGING 0x17
#define SPOSE_AIMING_WHILE_HANGING 0x18
#define SPOSE_SHOOTING_WHILE_HANGING 0x19
#define SPOSE_PULLING_YOURSELF_UP_FROM_HANGING 0x1A
#define SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING 0x1B
#define SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL 0x1C
#define SPOSE_USING_AN_ELEVATOR 0x1D
#define SPOSE_FACING_THE_FOREGROUND 0x1E
#define SPOSE_TURNING_FROM_FACING_THE_FOREGROUND 0x1F
#define SPOSE_GRABBED_BY_CHOZO_STATUE 0x20
#define SPOSE_DELAY_BEFORE_SHINESPARKING 0x21
#define SPOSE_SHINESPARKING 0x22
#define SPOSE_SHINESPARK_COLLISION 0x23
#define SPOSE_DELAY_AFTER_SHINESPARKING 0x24
#define SPOSE_DELAY_BEFORE_BALLSPARKING 0x25
#define SPOSE_BALLSPARKING 0x26
#define SPOSE_BALLSPARK_COLLISION 0x27
#define SPOSE_ON_ZIPLINE 0x28
#define SPOSE_SHOOTING_ON_ZIPLINE 0x29
#define SPOSE_TURNING_ON_ZIPLINE 0x2A
#define SPOSE_MORPH_BALL_ON_ZIPLINE 0x2B
#define SPOSE_SAVING_LOADING_GAME 0x2C
#define SPOSE_DOWNLOADING_MAP_DATA 0x2D
#define SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA 0x2E
#define SPOSE_GETTING_HURT 0x2F
#define SPOSE_GETTING_KNOCKED_BACK 0x30
#define SPOSE_GETTING_HURT_IN_MORPH_BALL 0x31
#define SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL 0x32
#define SPOSE_DYING 0x33
#define SPOSE_CROUCHING_TO_CRAWL 0x34
#define SPOSE_CRAWLING_STOPPED 0x35
#define SPOSE_STARTING_TO_CRAWL 0x36
#define SPOSE_CRAWLING 0x37
#define SPOSE_UNCROUCHING_FROM_CRAWLING 0x38
#define SPOSE_TURNING_AROUND_WHILE_CRAWLING 0x39
#define SPOSE_SHOOTING_WHILE_CRAWLING 0x3A
#define SPOSE_UNCROUCHING_SUITLESS 0x3B
#define SPOSE_CROUCHING_SUITLESS 0x3C
#define SPOSE_GRABBING_A_LEDGE_SUITLESS 0x3D
#define SPOSE_FACING_THE_BACKGROUND_SUITLESS 0x3E
#define SPOSE_TURNING_FROM_FACING_THE_BACKGROUND_SUITLESS 0x3F
#define SPOSE_ACTIVATING_ZIPLINES 0x40
#define SPOSE_IN_ESCAPE_SHIP 0x41
#define SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP 0x42
#define SPOSE_KNOCKBACK_REQUEST 0xF9
#define SPOSE_HURT_REQUEST 0xFA
#define SPOSE_LANDING_REQUEST 0xFD
#define SPOSE_UPDATE_JUMP_VELOCITY_REQUEST 0xFE
#define SPOSE_NONE 0xFF

#define STANDING_GROUND 0x0
#define STANDING_ENEMY 0x1
#define STANDING_MIDAIR 0x2
#define STANDING_NOT_IN_CONTROL 0x3
#define STANDING_FORCED_POSE 0x4
#define STANDING_HANGING 0x5
#define STANDING_INVALID 0xFF

#define ACD_FORWARD 0x0
#define ACD_DIAGONALLY_UP 0x1
#define ACD_DIAGONALLY_DOWN 0x2
#define ACD_UP 0x3
#define ACD_DOWN 0x4
#define ACD_NONE 0x5

#define SLOPE_NONE 0x0
#define SLOPE_STEEP 0x1
#define SLOPE_SLIGHT 0x2
#define SLOPE_LEFT 0x10
#define SLOPE_RIGHT 0x20

#define HDMOVING_NONE 0x0
#define HDMOVING_LEFT 0x1
#define HDMOVING_RIGHT 0x2

#define VDMOVING_NONE 0x0
#define VDMOVING_UP 0x1
#define VDMOVING_DOWN 0x2

#define ENV_EFFECT_NONE 0x0
#define ENV_EFFECT_RUNNING_ON_WET_GROUND 0x1
#define ENV_EFFECT_RUNNING_ON_DUSTY_GROUND 0x2
#define ENV_EFFECT_RUNNING_ON_VERY_DUSTY_GROUND 0x3
#define ENV_EFFECT_GOING_OUT_OF_WATER 0x4
#define ENV_EFFECT_RUNNING_INTO_WATER 0x5
#define ENV_EFFECT_GOING_OUT_OF_LAVA 0x6
#define ENV_EFFECT_RUNNING_INTO_LAVA 0x7
#define ENV_EFFECT_GOING_OUT_OF_ACID 0x8
#define ENV_EFFECT_RUNNING_INTO_ACID 0x9
#define ENV_EFFECT_TAKING_DAMAGE_IN_LAVA 0xA
#define ENV_EFFECT_TAKING_DAMAGE_IN_ACID 0xB
#define ENV_EFFECT_LANDING_ON_WET_GROUND 0xC
#define ENV_EFFECT_LANDING_ON_BUBBLY_GROUND 0xD
#define ENV_EFFECT_LANDING_ON_DUSTY_GROUND 0xE
#define ENV_EFFECT_LANDING_ON_VERY_DUSTY_GROUND 0xF
#define ENV_EFFECT_SKIDDING_ON_WET_GROUND 0x10
#define ENV_EFFECT_SKIDDING_ON_DUSTY_GROUND 0x11
#define ENV_EFFECT_BREATHING_BUBBLES 0x12

#define WANTING_RUNNING_EFFECT 0x0
#define WANTING_RUNNING_EFFECT_ 0x1
#define WANTING_LANDING_EFFECT 0x2
#define WANTING_GOING_OUT_OF_LIQUID_EFFECT 0x3
#define WANTING_RUNNING_OUT_OF_LIQUID_EFFECT 0x4
#define WANTING_BREATHING_BUBBLES 0x5
#define WANTING_SKIDDING_EFFECT 0x6
#define WANTING_RUNNING_ON_WET_GROUND 0x7

#define DESTRUCTING_ACTION_NONE 0X0
#define DESTRUCTING_ACTION_SPEED 0x1
#define DESTRUCTING_ACTION_SCREW 0x2
#define DESTRUCTING_ACTION_SPEED_SCREW 0x3

#define SAMUS_ANIM_STATE_NONE 0x0
#define SAMUS_ANIM_STATE_SUB_ENDED 0x1
#define SAMUS_ANIM_STATE_ENDED 0x2

// Probably not 100% true
#define SAMUS_COLLISION_DETECTION_NONE 0x0
#define SAMUS_COLLISION_DETECTION_LEFT_MOST 0x1
#define SAMUS_COLLISION_DETECTION_MIDDLE_LEFT 0x2
#define SAMUS_COLLISION_DETECTION_MIDDLE_RIGHT 0x4
#define SAMUS_COLLISION_DETECTION_RIGHT_MOST 0x8
#define SAMUS_COLLISION_DETECTION_SLOPE 0x80

#define FORCED_MOVEMENT_UPWARDS_SHINESPARK 0x0
#define FORCED_MOVEMENT_SIDEWARDS_SHINESPARK 0x1
#define FORCED_MOVEMENT_CROUCHING_ARM_CANNON_UP 0x1
#define FORCED_MOVEMENT_DIAGONAL_SHINESPARK 0x2
#define FORCED_MOVEMENT_LAUNCHED_BY_CANNON 0xF0

#define SCREW_SPEED_FLAG_NONE 0x0
#define SCREW_SPEED_FLAG_SHINESPARKING 0x1
#define SCREW_SPEED_FLAG_SPEEDBOOSTING 0x1
#define SCREW_SPEED_FLAG_SCREW_ATTACKING 0x1
#define SCREW_SPEED_FLAG_STORING_SHINESPARK 0x8

// Structs

struct Equipment {
    u16 maxEnergy;
    u16 maxMissiles;
    u8 maxSuperMissiles;
    u8 maxPowerBombs;
    u16 currentEnergy;
    u16 currentMissiles;
    u8 currentSuperMissiles;
    u8 gCurrentPowerBombs;
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
    u8 missilesSeleced;
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
    // u8 undefined; // Needed for correct alignment
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

typedef u8 (*SamusFunc_t)(struct SamusData*);

// Functions

void SamusCheckScrewSpeedboosterAffectingEnvironment(struct SamusData* pData, struct SamusPhysics* pPhysics);
u8 SamusSlopeRelated(u16 xPosition, u16 yPosition, u16* pXPosition, u16* pYPosition, u16* pSlope);
u8 unk_5604(struct SamusData* pData, struct SamusPhysics* pPhysics, u16 xPosition, u16* pPosition);
u8 SamusCheckTopSideCollisionMidAir(struct SamusData* pData, struct SamusPhysics* pPhysics, u16 xPosition, u16* pPosition);
u8 SamusCheckWalkingOnSlope(struct SamusData* pData, u16 xPosition);
u8 SamusCheckCollisionAbove(struct SamusData* pData, i16 hitbox);
u8 SamusCheckWalkingSidesCollision(struct SamusData* pData, struct SamusPhysics* pPhysics);
u8 unk_5AD8(struct SamusData* pData, struct SamusPhysics* pPhysics);
u8 SamusCheckStandingOnGroundCollision(struct SamusData* pData, struct SamusPhysics* pPhysics);
u8 SamusCheckLandingCollision(struct SamusData* pData, struct SamusPhysics* pPhysics);
u8 SamusCheckTopCollision(struct SamusData* pData, struct SamusPhysics* pPhysics);
void SamusCheckCollisions(struct SamusData* pData, struct SamusPhysics* pPhysics);
void SamusCheckSetEnvironmentalEffect(struct SamusData* pData, u32 default_offset, u32 request);
void SamusUpdateEnvironmentalEffect(struct SamusData* pData);
void SamusUpdateJumpVelocity(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon);
void SamusSetLandingPose(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon);
void SamusChangeToHurtPose(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon);
void SamusChangeToKnockbackPose(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon);
void SamusCheckCarryFromCopy(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon);
void SamusSetPose(u8 pose);
void SamusCopyData(struct SamusData* pData);
void SamusUpdatePhysics(struct SamusData* pData);
i16 SamusChangeVelocityOnSlope(struct SamusData* pData);
void SamusCopyPalette(u16* pSrc, i32 offset, i32 nbrColors);
void SamusUpdate(void);
void SamusUpdateHitboxMovingDirection(void);
void SamusCallGFXFunctions(void);
void SamusCallCheckLowHealth(void);
void SamusCallUpdateArmCannonPositionOffset(void);
void SamusBombBounce(u8 direction);
void SamusAimCannon(struct SamusData* pData);
u8 SamusCheckFireBeamMissile(struct SamusData* pData, struct WeaponInfo* pWeapon, struct Equipment* pEquipment);
u8 SamusCheckFirePistol(struct SamusData* pData, struct WeaponInfo* pWeapon);
void SamusCheckNewProjectile(struct SamusData* pData, struct WeaponInfo* pWeapon, struct Equipment* pEquipment);
u8 SamusCheckAButtonPressed(struct SamusData* pData);
void SamusSetHighlightedWeapon(struct SamusData* pData, struct WeaponInfo* pWeapon, struct Equipment* pEquipment);
void SamusSetSpinningPose(struct SamusData* pData, struct Equipment* pEquipment);
void SamusApplyXAcceleration(i16 acceleration, i16 velocity, struct SamusData* pData);
u8 SamusTakeHazardDamage(struct SamusData* pData, struct Equipment* pEquipment, struct HazardDamage* pHazard);
void SamusCheckShinesparking(struct SamusData* pData);
u8 SamusInactivity(struct SamusData* pData);
u8 SamusUpdateAnimation(struct SamusData* pData, u8 slowed);
u8 SamusRunning(struct SamusData* pData);
u8 SamusRunningGFX(struct SamusData* pData);
u8 SamusStanding(struct SamusData* pData);
u8 SamusStandingGFX(struct SamusData* pData);
u8 SamusTurningAround(struct SamusData* pData);
u8 SamusTurningAroundGFX(struct SamusData* pData);
u8 SamusShootingGFX(struct SamusData* pData);
u8 SamusCrouching(struct SamusData* pData);
u8 SamusTurningAroundAndCrouching(struct SamusData* pData);
u8 SamusTurningAroundAndCrouchingGFX(struct SamusData* pData);
u8 SamusShootingAndCrouchingGFX(struct SamusData* pData);
u8 SamusSkidding(struct SamusData* pData);
u8 SamusMidAir(struct SamusData* pData);
u8 SamusMidAirGFX(struct SamusData* pData);
u8 SamusTurningAroundMidAir(struct SamusData* pData);
u8 SamusTurningAroundMidAirGFX(struct SamusData* pData);
u8 SamusStartingSpinJumpGFX(struct SamusData* pData);
u8 SamusSpinning(struct SamusData* pData);
u8 SamusSpinningGFX(struct SamusData* pData);
u8 SamusStartingWallJump(struct SamusData* pData);
u8 SamusStartingWallJumpGFX(struct SamusData* pData);
u8 SamusSpaceJumpingGFX(struct SamusData* pData);
u8 SamusCrewAttackingGFX(struct SamusData* pData);
u8 SamusMorphing(struct SamusData* pData);
u8 SamusMorphingGFX(struct SamusData* pData);
u8 SamusMorphball(struct SamusData* pData);
u8 SamusRolling(struct SamusData* pData);
u8 SamusRollingGFX(struct SamusData* pData);
u8 SamusUnmorphing(struct SamusData* pData);
u8 SamusUnmorphingGFX(struct SamusData* pData);
u8 SamusMorphballMidAir(struct SamusData* pData);
u8 SamusHangingOnLedge(struct SamusData* pData);
u8 SamusHangingOnLedgeGFX(struct SamusData* pData);
u8 SamusTurningToAimWhileHanging(struct SamusData* pData);
u8 SamusTurningToAimWhileHangingGFX(struct SamusData* pData);
u8 SamusHidingArmCannonWhileHangingGFX(struct SamusData* pData);
u8 SamusAimingWhileHanging(struct SamusData* pData);
u8 SamusPullingSelfUp(struct SamusData* pData);
u8 SamusPullingSelfUpGFX(struct SamusData* pData);
u8 SamusPullingSelfForward(struct SamusData* pData);
u8 SamusPullingSelfForwardGFX(struct SamusData* pData);
u8 SamusPullingSelfIntoMorphballTunnelGFX(struct SamusData* pData);
u8 SamusUsingAnElevator(struct SamusData* pData);
u8 SamusUsingAnElevatorGFX(struct SamusData* pData);
u8 SamusFacingTheForeground(struct SamusData* pData);
u8 SamusTurningFromFacningForegroundGFX(struct SamusData* pData);
u8 SamusDelayBeforeShinesparkingGFX(struct SamusData* pData);
u8 SamusShinesparking(struct SamusData* pData);
u8 SamusShinesparkingGFX(struct SamusData* pData);
u8 SamusShinesparkCollisionGFX(struct SamusData* pData);
u8 SamusDelayAfterShinesparkingGFX(struct SamusData* pData);
u8 SamusDelayBeforeBallsparking(struct SamusData* pData);
u8 SamusDelayBeforeBallsparkingGFX(struct SamusData* pData);
u8 SamusBallsparkingGFX(struct SamusData* pData);
u8 SamusBallsparkCollisionGFX(struct SamusData* pData);
u8 SamusOnZipline(struct SamusData* pData);
u8 SamusShootingOnZiplineGFX(struct SamusData* pData);
u8 SamusMorphballOnZipline(struct SamusData* pData);
u8 SamusSavingLoadingGame(struct SamusData* pData);
u8 SamusTurningAroundToDownloadMapDataGFX(struct SamusData* pData);
u8 SamusGettingHurt(struct SamusData* pData);
u8 SamusGettingHurtGFX(struct SamusData* pData);
u8 SamusGettingKnockedBack(struct SamusData* pData);
u8 SamusDying(struct SamusData* pData);
u8 SamusCrouchingToCrawlGFX(struct SamusData* pData);
u8 SamusCrawlingStopped(struct SamusData* pData);
u8 SamusStartingToCrawlGFX(struct SamusData* pData);
u8 SamusCrawling(struct SamusData* pData);
u8 SamusDyingGFX(struct SamusData* pData);
u8 SamusTurningAroundWhileCrawling(struct SamusData* pData);
u8 SamusCrawlingGFX(struct SamusData* pData);
u8 SamusGrabbingALedgeSuitlessGFX(struct SamusData* pData);
u8 SamusFacingTheBackground(struct SamusData* pData);
u8 SamusTurningFromFacingTheBackgroundGFX(struct SamusData* pData);
u8 SamusTurningToEnterEscapeShipGFX(struct SamusData* pData);
u8 SamusExecutePoseSubroutine(struct SamusData* pData);
void SamusUpdateVelocityPosition(struct SamusData* pData);
void SamusUpdateGraphicsOAM(struct SamusData* pData, u8 direction);
void SamusUpdatePalette(struct SamusData* pData);
void SamusCheckPlayLowHealthSound(void);
void SamusUpdateDrawDistanceAndStandingStatus(struct SamusData* pData, struct SamusPhysics* pPhysics);
void SamusUpdateArmCannonPositionOffset(u8 direction);
void SamusInit(void);
void SamusDraw(void);


#endif /* SAMUS_H */