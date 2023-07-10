#ifndef ENEMY_DROP_AI_H
#define ENEMY_DROP_AI_H

#include "types.h"

#define ENEMY_DROP_POSE_IDLE 0x9

#define SMALL_ENERGY_DROP_REFILL 5
#define LARGE_ENERGY_DROP_REFILL 20
#define MISSILE_DROP_REFILL 2
#define SUPER_MISSILE_DROP_REFILL 2
#define POWER_BOMB_DROP_REFILL 1

void EnemyDropInit(void);
void EnemyDropIdle(void);
void EnemyDrop(void);

#endif /* ENEMY_DROP_AI_H */