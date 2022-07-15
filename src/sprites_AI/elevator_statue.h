#ifndef ELEVATOR_STATUE_AI_H
#define ELEVATOR_STATUE_AI_H

#include "../types.h"

void ElevatorStatueChangeTwoGroundCCAA(u8 caa);
void KraidElevatorStatueChangeCAA(u8 caa);
void KraidElevatorStatueAfterFall(void);
void KraidElevatorStatueInit(void);
void KraidElevatorStatueCheckShouldFall(void);
void KraidElevatorStatueDelayBeforeFalling(void);
void KraidElevatorStatueFalling(void);
void RidleyElevatorStatueChangeCCAA(u8 caa);
void RidleyElevatorStatueAfterFall(void);
void RidleyElevatorStatueInit(void);
void RidleyElevatorStatueCheckShouldFall(void);
void RidleyElevatorStatueDelayBeforeFalling(void);
void RidleyElevatorStatueFalling(void);
void KraidElevatorStatue(void);
void RidleyElevatorStatue(void);
void ElevatorStatueDebris(void);

#endif /* ELEVATOR_STATUE_AI_H */