#ifndef HIVE_AI_H
#define HIVE_AI_H

#include "../types.h"
#include "../sprite.h"

void hive_spawn_particle(void);
void hive_init(void);
u8 hive_count_mellows(void);
void hive_phase1(void);
void hive_phase2(void);
void hive_phase3(void);
void hive_dying(void);
void hive_ignore_samus_collision(void);
void hive_roots_init(void);
void hive_roots_move(void);
void hive_mellow_init(struct sprite_data* pSprite);
void hive_mellow_idle_anim(struct sprite_data* pSprite);
void hive_mellow_fleeing(struct sprite_data* pSprite);
void hive_mellow_samus_detected(struct sprite_data* pSprite);
void hive_mellow_move(struct sprite_data* pSprite);
void hive(void);
void hive_roots(void);
void hive_mellow(void);
void hive_mellow_swarm(void);

#endif /* HIVE_AI_H */