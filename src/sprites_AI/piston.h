#ifndef PISTON_AI_H
#define PISTON_AI_H

#include "../types.h"

void piston_change_four_ccaa(u8 caa);
void piston_change_one_below_ccaa(u8 caa);
void piston_change_one_upper_ccaa(u8 caa);
u8 piston_samus_collision_bugged(void);
u8 piston_check_samus_in(void);
void piston_init(void);
void piston_gfx_init(void);
void piston_check_projectile(void);
void piston_move(void);
void piston_after_moving(void);
void piston(void);

#endif /* PISTON_AI_H */