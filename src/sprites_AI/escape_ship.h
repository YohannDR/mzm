#ifndef ESCAPE_SHIP_AI_H
#define ESCAPE_SHIP_AI_H

#include "../types.h"

void EscapeShipPartUpdatePalette(u8 delay);
void EscapeShipSetIgnoreSamus(void);
void EscapeShipSetPirateDrawOrder(void);
void EscapeShipPirateCollision(void);
void EscapeShipCheckCollidingWithLaser(void);
void EscapeShip(void);
void EscapeShipPart(void);

#endif /* ESCAPE_SHIP_AI_H */