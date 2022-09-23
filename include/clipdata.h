#ifndef CLIPDATA_H
#define CLIPDATA_H

#include "types.h"
#include "structs/clipdata.h"
#include "gba.h"

// Functions

void ClipdataSetupCode(void);
u32 ClipdataProcessForSamus(u16 yPosition, u16 xPosition);
u32 ClipdataProcess(u16 yPosition, u16 xPosition);
u32 ClipdataConvertToCollision(struct CollisionData* pCollision);
i32 ClipdataCheckCurrentAffectingAtPosition(u16 yPosition, u16 xPosition);
i32 ClipdataUpdateCurrentAffecting(u16 yPosition, u16 tileY, u16 tileX, u8 unk);
u8 ClipdataCheckCantUseElevator(void);
i32 ClipdataCheckGroundEffect(u16 yPosition, u16 xPosition);

#endif /* CLIPDATA_H */