#ifndef SPACE_PIRATE_AI_H
#define SPACE_PIRATE_AI_H

#include "types.h"

#define SPACE_PIRATE_HEIGHT (BLOCK_SIZE * 3 + 0x34)

#define SPACE_PIRATE_CLIMBING_DIRECTION_UP 0x0
#define SPACE_PIRATE_CLIMBING_DIRECTION_DOWN 0x1

#define SPACE_PIRATE_AIM_FORWARD 0x0
#define SPACE_PIRATE_AIM_DIAGONALLY_UP 0x1
#define SPACE_PIRATE_AIM_DIAGONALLY_DOWN 0x2

#define SPACE_PIRATE_POSE_WALKING_INIT 0x8
#define SPACE_PIRATE_POSE_WALKING 0x9
#define SPACE_PIRATE_POSE_TURNING_AROUND_INIT 0xA
#define SPACE_PIRATE_POSE_TURNING_AROUND_FIRST_PART 0xB
#define SPACE_PIRATE_POSE_TURNING_AROUND_SECOND_PART 0xC
#define SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT 0x12
#define SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP 0x13
#define SPACE_PIRATE_POSE_DELAY_BEFORE_LAUNCHING_FROM_WALL 0x15
#define SPACE_PIRATE_POSE_0x16 0x16
#define SPACE_PIRATE_POSE_0x18 0x18
#define SPACE_PIRATE_POSE_0x19 0x19
#define SPACE_PIRATE_POSE_FALLING_INIT 0x1E
#define SPACE_PIRATE_POSE_FALLING 0x1F
#define SPACE_PIRATE_POSE_WALKING_ALERTED_INIT 0x22
#define SPACE_PIRATE_POSE_WALKING_ALERTED 0x23
#define SPACE_PIRATE_POSE_WAITING_AT_DOOR 0x24
#define SPACE_PIRATE_POSE_SHOOTING_AFTER_WAITING_AT_DOOR 0x25
#define SPACE_PIRATE_POSE_IDLE 0x27
#define SPACE_PIRATE_POSE_IDLE_AT_DOOR 0x28
#define SPACE_PIRATE_POSE_CHARGING_LASER_INIT 0x34
#define SPACE_PIRATE_POSE_CHARGING_LASER 0x35
#define SPACE_PIRATE_POSE_SHOOTING_LASER_INIT 0x36
#define SPACE_PIRATE_POSE_SHOOTING_LASER 0x37
#define SPACE_PIRATE_POSE_CLIMBING_CHARGING_LASER_INIT 0x38
#define SPACE_PIRATE_POSE_CLIMBING_CHARGING_LASER 0x39
#define SPACE_PIRATE_POSE_CLIMBING_SHOOTING_LASER_INIT 0x3A
#define SPACE_PIRATE_POSE_CLIMBING_SHOOTING_LASER 0x3B
#define SPACE_PIRATE_POSE_JUMPING_INIT 0x42
#define SPACE_PIRATE_POSE_JUMPING 0x43
#define SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT 0x44
#define SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_FIRST_PART 0x45
#define SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_SECOND_PART 0x47
#define SPACE_PIRATE_POSE_CLIMBING_UP_INIT 0x48
#define SPACE_PIRATE_POSE_CLIMBING_UP 0x49
#define SPACE_PIRATE_POSE_LAUNCHING_FROM_WALL_INIT 0x4A
#define SPACE_PIRATE_POSE_LAUNCHING_FROM_WALL 0x4B
#define SPACE_PIRATE_POSE_WALL_JUMPING 0x4D
#define SPACE_PIRATE_POSE_STARTING_TO_CRAWL_INIT 0x4E
#define SPACE_PIRATE_POSE_STARTING_TO_CRAWL 0x4F
#define SPACE_PIRATE_POSE_CRAWLING 0x51
#define SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_INIT 0x52
#define SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_FIRST_PART 0x53
#define SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_SECOND_PART 0x55
#define SPACE_PIRATE_POSE_STANDING_UP_INIT 0x56
#define SPACE_PIRATE_POSE_STANDING_UP 0x57
#define SPACE_PIRATE_POSE_CRAWLING_STOPPED_INIT 0x58
#define SPACE_PIRATE_POSE_CRAWLING_STOPPED 0x59
#define SPACE_PIRATE_POSE_FALLING_WHILE_CRAWLING_INIT 0x5A
#define SPACE_PIRATE_POSE_FALLING_WHILE_CRAWLING 0x5B
#define SPACE_PIRATE_POSE_CLIMBING_DOWN_INIT 0x5E
#define SPACE_PIRATE_POSE_CLIMBING_DOWN 0x5F
#define SPACE_PIRATE_POSE_HIT_BY_LASER_INIT 0x6B
#define SPACE_PIRATE_POSE_HIT_BY_LASER 0x6C

// Space pirate laser

#define SPACE_PIRATE_LASER_POSE_MOVING 0x9
#define SPACE_PIRATE_LASER_POSE_EXPLODING_INIT 0x42
#define SPACE_PIRATE_LASER_POSE_EXPLODING 0x43

#define SPACE_PIRATE_LASER_PART_FORWARD 0x0
#define SPACE_PIRATE_LASER_PART_DIAGONALLY_UP 0x1
#define SPACE_PIRATE_LASER_PART_DIAGONALLY_DOWN 0x2

void DisableChozodiaAlarm(void);
void DecrementChozodiaAlarm(void);
void SpawnWaitingPirates(void);
void SpacePirateFlip(void);
void SpacePirateSamusDetection(void);
void SpacePirateCheckCollidingWithLaser(void);
void SpacePirateFireLaserGround(void);
void SpacePirateFireLaserWall(void);
u8 SpacePirateCheckCollidingWithPirateWhenWalking(void);
u8 SpacePirateCheckCollidingWithPirateWhenClimbing(u8 direction);
u8 SpacePirateCheckSamusInShootingRange(void);
u8 unk_29b68(void);
u8 SpacePirateDetectSamusWhileCrawling(void);
u8 SpacePirateClimbingCheckWallJumpOrFire(void);
void unk_29ef0(void);
void SpacePirateInit(void);
void SpacePirateFallingInit(void);
void SpacePirateFalling(void);
void unk_2a768(void);
void unk_2a794(void);
void unk_2a7c0(void);
void SpacePirateWalkingInit(void);
void SpacePirateWalking(void);
void SpacePirateIdle(void);
void SpacePirateIdleAtDoor(void);
void unk_2aa5c(void);
void unk_2aa88(void);
void unk_2aaec(void);
void unk_2ab10(void);
void unk_2ab34(void);
void unk_2ab58(void);
void SpacePirateTurningAroundInit(void);
void SpacePirateTurningAroundFirstPart(void);
void SpacePirateTurningAroundSecondPart(void);
void SpacePirateTurningAroundAlertedInit(void);
void SpacePirateTurningAroundFirstPartAlerted(void);
void SpacePirateTurningAroundSecondPartAlerted(void);
void SpacePirateWalkingAlertedInit(void);
void SpacePirateWalkingAlerted(void);
void SpacePirateJumpingInit(void);
void SpacePirateJumping(void);
void SpacePirateChargingLaserInit(void);
void SpacePirateChargingLaser(void);
void SpacePirateShootingLaserInit(void);
void SpacePirateShootingLaser(void);
void SpacePirateWaitingAtDoor(void);
void SpacePirateShootingAfterWaitingAtDoor(void);
void SpacePirateClimbingUpInit(void);
void SpacePirateClimbingUp(void);
void SpacePirateClimbingDownInit(void);
void SpacePirateClimbingDown(void);
void unk_2ba7c(void);
void unk_2ba98(void);
void SpacePirateClimbingChargingLaserInit(void);
void SpacePirateClimbingChargingLaser(void);
void SpacePirateClimbingShootingLaserInit(void);
void SpacePirateClimbingShootingLaser(void);
void SpacePirateTurningAroundToWallJumpInit(void);
void SpacePirateTurningAroundToWallJump(void);
void SpacePirateDelayBeforeLaunchingFromWall(void);
void SpacePirateLaunchingFromWallInit(void);
void SpacePirateLaunchingFromWall(void);
void SpacePirateStartingToCrawlInit(void);
void SpacePirateStartingToCrawl(void);
void SpacePirateCrawling(void);
void SpacePirateTurningAroundWhileCrawlingInit(void);
void SpacePirateTurningWhileCrawlingFirstPart(void);
void SpacePirateTurningWhileCrawlingSecondPart(void);
void SpacePirateStandingUpInit(void);
void SpacePirateStandingUp(void);
void SpacePirateFallingWhileCrawlingInit(void);
void SpacePirateFallingWhileCrawling(void);
void SpacePirateCrawlingStoppedInit(void);
void SpacePirateCrawlingStopped(void);
void SpacePirateDeath(u8 playSound);
void SpacePirateHitByLaserInit(void);
void SpacePirateHitByLaser(void);
void SpacePirateLaserInit(void);
void SpacePirateLaserExplodingInit(void);
void SpacePirateLaserCheckExplodingAnimEnded(void);
void SpacePirateLaserMove(void);
void SpacePirate(void);
void SpacePirateLaser(void);

#endif /* SPACE_PIRATE_AI_H */