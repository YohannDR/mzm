#ifndef ELEVATOR_STATUE_AI_H
#define ELEVATOR_STATUE_AI_H

#include "../types.h"

void elevator_statue_change_two_ground_ccaa(u8 caa);
void kraid_elevator_statue_change_ccaa(u8 caa);
void kraid_elevator_statue_after_fall(void);
void kraid_elevator_statue_init(void);
void kraid_elevator_statue_check_should_fall(void);
void kraid_elevator_statue_timer_before_falling(void);
void kraid_elevator_statue_falling(void);
void ridley_elevator_statue_change_ccaa(u8 caa);
void ridley_elevator_statue_after_fall(void);
void ridley_elevator_statue_init(void);
void ridley_elevator_statue_check_should_fall(void);
void ridley_elevator_statue_timer_before_falling(void);
void ridley_elevator_statue_falling(void);
void kraid_elevator_statue(void);
void ridley_elevator_statue(void);
void elevator_statue_debris(void);

#endif /* ELEVATOR_STATUE_AI_H */