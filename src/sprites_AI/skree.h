#ifndef SKREE_AI_H
#define SKREE_AI_H

#include "../types.h"

void skree_init(void);
void skree_gfx_init(void);
void skree_detect_samus(void);
void skree_spin_gfx_init(void);
void skree_check_spin_ended(void);
void skree_start_going_down(void);
void skree_go_down(void);
void skree_crash_ground(void);
void skree_explosion_init(void);
void skree_explosion_move(void);
void skree(void);
void skree_explosion(void);

#endif /* SKREE_AI_H */