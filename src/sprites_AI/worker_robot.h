#ifndef WORKER_ROBOT_AI_H
#define WORKER_ROBOT_AI_H

#include "../types.h"

u8 worker_robot_check_samus_in_front(void);
void worker_robot_init(void);
void worker_robot_gfx_init(void);
void worker_robot_sleeping_detect_projectile(void);
void worker_robot_standing_gfx_init(void);
void worker_robot_check_standing_anim_ended(void);
void worker_robot_walking_detect_projectile(void);
void worker_robot_waking_up_gfx_init(void);
void worker_robot_check_projectile(void);
void worker_robot_walk_gfx_init(void);
void worker_robot_move(void);
void worker_robot_back_to_sleep_gfx_init(void);
void worker_robot_check_back_to_sleep_anim_ended(void);
void worker_robot_turning_around(void);
void worker_robot_check_turning_around_anim_ended(void);
void worker_robot_falling_gfx_init(void);
void worker_robot_falling(void);
void worker_robot_falling_sleep_gfx_init(void);
void worker_robot_falling_sleep(void);
void worker_robot(void);

#endif /* WORKER_ROBOT_AI_H */