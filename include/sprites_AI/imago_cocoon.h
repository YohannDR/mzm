#ifndef IMAGO_COCOON_AI_H
#define IMAGO_COCOON_AI_H

#include "types.h"

#define IMAGO_COCOON_POSE_IDLE 0x8
#define IMAGO_COCOON_POSE_FALLING_BEFORE_BLOCKS 0x9
#define IMAGO_COCOON_POSE_FALLING_AFTER_BLOCKS 0x23
#define IMAGO_COCOON_POSE_UNLOCK_PASSAGE 0x25
#define IMAGO_COCOON_POSE_IN_GROUND 0x27

#define IMAGO_COCOON_PART_VINE_LEFT_VINE_DECORATIONS 0x0
#define IMAGO_COCOON_PART_VINE_LEFT_MIDDLE 0x1
#define IMAGO_COCOON_PART_VINE_RIGHT_MIDDLE 0x2
#define IMAGO_COCOON_PART_CEILING_VINE 0x3
#define IMAGO_COCOON_PART_IMAGO_COCOON 0x4
#define IMAGO_COCOON_PART_VINE_RIGHT_VINE_DECORATIONS 0x5
#define IMAGO_COCOON_PART_VINE_RIGHT_RIGHT 0x6
#define IMAGO_COCOON_PART_VINE_LEFT_LEFT 0x7
#define IMAGO_COCOON_PART_VINE_RIGHT_LEFT 0x8
#define IMAGO_COCOON_PART_VINE_LEFT_RIGHT 0x9

#define IMAGO_COCOON_MUSIC_STAGE_STARTED_MUSIC 0x0 
#define IMAGO_COCOON_MUSIC_STAGE_STARTED_FADING 0x1
#define IMAGO_COCOON_MUSIC_STAGE_WAITING_TO_FADE 0x2

#define IMAGO_COCOON_SIZE 0xE8

// Imago cocoon vine

#define IMAGO_COCOON_VINE_POSE_IDLE 0x8
#define IMAGO_COCOON_VINE_POSE_SPAWN_SPORES 0xE
#define IMAGO_COCOON_VINE_POSE_CEILING_VINE_IDLE 0x42
#define IMAGO_COCOON_VINE_POSE_CEILING_VINE_DEATH 0x43

// Imago cocoon spore

#define IMAGO_COCOON_SPORE_POSE_SPAWNING 0x9
#define IMAGO_COCOON_SPORE_POSE_NEST 0x23
#define IMAGO_COCOON_SPORE_POSE_MOVING 0x25
#define IMAGO_COCOON_SPORE_POSE_EXPLODING_INIT 0x42
#define IMAGO_COCOON_SPORE_POSE_EXPLODING 0x43

#define IMAGO_COCOON_SPORE_LEFT_Y_OFFSET 0x60
#define IMAGO_COCOON_SPORE_LEFT_X_OFFSET 0x46
#define IMAGO_COCOON_SPORE_RIGHT_Y_OFFSET 0x90
#define IMAGO_COCOON_SPORE_RIGHT_X_OFFSET 0x64

#define IMAGO_COCOON_SPORE_PART_DOWN 0x0
#define IMAGO_COCOON_SPORE_PART_DIAG_RIGHT_UP 0x1
#define IMAGO_COCOON_SPORE_PART_RIGHT 0x2
#define IMAGO_COCOON_SPORE_PART_DIAG_RIGHT_DOWN 0x3
#define IMAGO_COCOON_SPORE_PART_UP 0x4
#define IMAGO_COCOON_SPORE_PART_DIAG_LEFT_DOWN 0x5
#define IMAGO_COCOON_SPORE_PART_LEFT 0x6
#define IMAGO_COCOON_SPORE_PART_DIAG_LEFT_UP 0x7

// Winged ripper

#define WINGED_RIPPER_POSE_MOVING_INIT 0x8
#define WINGED_RIPPER_POSE_MOVING 0x9


void ImagoCocoonSyncSprites(void);
void ImagoCocoonChangeOneCCAA(u8 caa);
void ImagoCocoonChangeTwoMiddleCCAA(u8 caa);
void ImagoCocoonChangeTwoAroundCCAA(u8 caa);
void ImagoCocoonChangeTwoBlockingCCAA(u8 caa);
void ImagoCocoonChangeOAMScaling(u16 limit, u16 value);
void ImagoCocoonInit(void);
void ImagoCocoonFallingMovement(void);
void ImagoCocoonIdle(void);
void ImagoCocoonFallingBeforeBlocks(void);
void ImagoCocoonFallingAfterBlocks(void);
void ImagoCocoonUnlockPassage(void);
void ImagoCocoonInGround(void);
void ImagoCocoonVineInit(void);
void ImagoCocoonVineCheckPlayDamagedSound(void);
void ImagoCocoonVineDeath(void);
void ImagoCocoonVineSpawnSpore(void);
void ImagoCocoonCeilingVineIdle(void);
void ImagoCocoonCeilingVineDeath(void);
void ImagoCocoonSporeSyncPosition(void);
void ImagoCocoonSporeInit(void);
void ImagoCocoonSporeSpawning(void);
void ImagoCocoonSporeNest(void);
void ImagoCocoonSporeMove(void);
void ImagoCocoonSporeExplodingInit(void);
void ImagoCocoonSporeCheckExplodingAnimEnded(void);
u8 WingedRipperImagoCollision(void);
void WingedRipperInit(void);
void WingedRipperMovingInit(void);
void WingedRipperMove(void);
void WingedRipperDeath(void);
void ImagoCocoon(void);
void ImagoCocoonVine(void);
void ImagoCocoonSpore(void);
void WingedRipper(void);
void DefeatedImagoCocoon(void);
void ImagoCocoonCeilingVine(void);
void EventTriggerDiscoveredImagoPassage(void);
void ImagoCocoonAfterFight(void);

#endif /* IMAGO_COCOON_AI_H */