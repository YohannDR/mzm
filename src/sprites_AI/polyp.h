#ifndef POLYP_AI_H
#define POLYP_AI_H

#include "../types.h"

void polyp_init(void);
void polyp_gfx_init(void);
void polyp_check_spawn_projectile(void);
void polyp_check_spitting_anim_ended(void);
void polyp_spawn_projectile(void);
void polyp_check_after_spitting_anim_ended(void);
void polyp_check_retracting_anim_ended(void);
void polyp_projectile_init(void);
void polyp_projectile_spawn(void);
void polyp_projectile_move(void);
void polyp_projectile_exploding_gfx_init(void);
void polyp_projectile_check_exploding_anim_ended(void);
void polyp(void);
void polyp_projectile(void);

#endif /* POLYP_AI_H */