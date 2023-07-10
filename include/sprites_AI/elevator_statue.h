#ifndef ELEVATOR_STATUE_AI_H
#define ELEVATOR_STATUE_AI_H

#include "types.h"

#define ELEVATOR_STATUE_POSE_CHECK_FALL 0x8
#define ELEVATOR_STATUE_POSE_DELAY_BEFORE_FALLING 0x9
#define ELEVATOR_STATUE_POSE_FALLING 0xB
#define ELEVATOR_STATUE_POSE_IDLE 0xF


#define ELEVATOR_STATUE_DEBRIS_PART_KRAID 0x0
#define ELEVATOR_STATUE_DEBRIS_PART_RIDLEY 0x1
#define ELEVATOR_STATUE_DEBRIS_PART_DUST 0x2

#define ELEVATOR_STATUE_DEBRIS_POSE_IDLE 0x9

void ElevatorStatueChangeTwoGroundCCAA(u8 caa);
void KraidElevatorStatueChangeCAA(u8 caa);
void KraidElevatorStatueFallenInit(void);
void KraidElevatorStatueInit(void);
void KraidElevatorStatueCheckShouldFall(void);
void KraidElevatorStatueDelayBeforeFalling(void);
void KraidElevatorStatueFalling(void);
void RidleyElevatorStatueChangeCCAA(u8 caa);
void RidleyElevatorStatueFallenInit(void);
void RidleyElevatorStatueInit(void);
void RidleyElevatorStatueCheckShouldFall(void);
void RidleyElevatorStatueDelayBeforeFalling(void);
void RidleyElevatorStatueFalling(void);
void KraidElevatorStatue(void);
void RidleyElevatorStatue(void);
void ElevatorStatueDebris(void);

#endif /* ELEVATOR_STATUE_AI_H */