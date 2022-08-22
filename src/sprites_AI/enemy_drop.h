#ifndef ENEMY_DROP_AI_H
#define ENEMY_DROP_AI_H

#include "../types.h"

extern const struct FrameData sEnemyDropOAM_LargeEnergy[5];

#define ENEMY_DROP_POSE_IDLE 0x9

void EnemyDropInit(void);
void EnemyDropIdle(void);
void EnemyDrop(void);

#endif /* ENEMY_DROP_AI_H */