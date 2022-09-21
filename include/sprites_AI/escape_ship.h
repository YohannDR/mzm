#ifndef ESCAPE_SHIP_AI_H
#define ESCAPE_SHIP_AI_H

#include "types.h"

#define ESCAPE_SHIP_POSE_CHECK_OPEN 0x8
#define ESCAPE_SHIP_POSE_OPENING 0x9
#define ESCAPE_SHIP_POSE_OPENED 0x22
#define ESCAPE_SHIP_POSE_DELAY_BEFORE_CLOSING 0x23
#define ESCAPE_SHIP_POSE_CLOSING 0x24
#define ESCAPE_SHIP_POSE_CLOSED 0x25
#define ESCAPE_SHIP_POSE_HOVERING 0x26
#define ESCAPE_SHIP_POSE_ESCAPING 0x27
#define ESCAPE_SHIP_POSE_ESCAPED 0x28

// Escape ship part

#define ESCAPE_SHIP_PART_TOP 0x0
#define ESCAPE_SHIP_PART_TAIL 0x2
#define ESCAPE_SHIP_PART_FLAMES 0x3

#define ESCAPE_SHIP_PART_POSE_WAIT_FOR_MOVING_TAIL 0x8
#define ESCAPE_SHIP_PART_POSE_UPDATE_PALETTE 0x9
#define ESCAPE_SHIP_PART_POSE_UPDATE_TOP 0xE
#define ESCAPE_SHIP_PART_POSE_UPDATE_FLAMES 0x32

void EscapeShipPartUpdatePalette(u8 delay);
void EscapeShipSetIgnoreSamus(void);
void EscapeShipSetPirateDrawOrder(void);
void EscapeShipPirateCollision(void);
void EscapeShipCheckCollidingWithLaser(void);
void EscapeShip(void);
void EscapeShipPart(void);

#endif /* ESCAPE_SHIP_AI_H */