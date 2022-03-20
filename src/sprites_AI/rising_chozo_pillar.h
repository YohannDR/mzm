#ifndef RISING_CHOZO_PILLAR_AI_H
#define RISING_CHOZO_PILLAR_AI_H

#include "../types.h"

void rising_chozo_pillar_random_sprite_debris(u16 y_position, u16 x_position, u8 rng);
void rising_chozo_pillar_random_particles(u16 y_position, u16 x_position, u8 rng);
void rising_chozo_pillar_spawn_three_platforms(u16 y_position, u16 x_position, u8 caa);
void rising_chozo_pillar_spawn_two_platforms(u16 y_position, u16 x_position, u8 caa);
void rising_chozo_pillar_spawn_one_platform(u16 y_position, u16 x_position, u8 caa);
void rising_chozo_pillar(void);
void chozo_pillar_platform(void);
void chozo_pillar_platform_shadow(void);

#endif /* RISING_CHOZO_PILLAR_AI_H */