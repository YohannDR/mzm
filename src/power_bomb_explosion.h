#ifndef POWER_BOMB_EXPLOSION_H
#define POWER_BOMB_EXPLOSION_H

#include "types.h"

void PowerBombExplosionProcess(void);
void PowerBombExplosion(void);
void PowerBombExplosionStart(u16 x_position, u16 y_position, u8 zero);
void PowerBombExplosionSet0x12To0(void);
void PowerBombExplosionBegin(void);
void PowerBombExplosionEnd(void);

#endif /* POWER_BOMB_EXPLOSION_H */