#ifndef POWER_BOMB_EXPLOSION_H
#define POWER_BOMB_EXPLOSION_H

#include "types.h"

void PowerBombExplosionProcess(void);
void PowerBombExplosion(void);
void PowerBombExplosionStart(u16 xPosition, u16 yPosition, u8 owner);
void PowerBombExplosionSet0x12To0(void);
void PowerBombExplosionBegin(void);
void PowerBombExplosionEnd(void);

#endif /* POWER_BOMB_EXPLOSION_H */