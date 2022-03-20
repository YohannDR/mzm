#ifndef ATOMIC_AI_H
#define ATOMIC_AI_H

#include "../types.h"

void unk_3b944(void);
void atomic_check_samus_position(void);
void atomic_shoot_electricity(void);
void atomic_init(void);
void atomic_gfx_init(void);
void atomic_idle_animation(void);
void atomic_move(void);
void atomic_move_back_to_idle(void);
void unk_3c0e8(void);
void unk_3c118(void);
u8 atomic_electricity_check_atomic_alive(u8 slot);
void atomic_electricity_init(void);
void atomic_electricity_spawn(void);
void atomic_electricity_move(void);
void atomic_electricity_exploding(void);
void atomic_electricity_check_on_ground_anim_ended(void);
void atomic(void);
void atomic_electricity(void);

#endif /* ATOMIC_AI_H */