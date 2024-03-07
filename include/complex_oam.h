#ifndef COMPLEX_OAM_H
#define COMPLEX_OAM_H

#include "types.h"

u8 ProcessComplexOam(u32 oamSlot, s16 xPosition, s16 yPosition, u16 rotation, s16 scaling, u16 doubleSize, u16 matrixNum);
void CalculateOamPart4(u16 rotation, s16 scaling, u16 oamSlot);

#endif /* COMPLEX_OAM_H */
