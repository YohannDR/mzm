#ifndef COMPLEX_OAM_H
#define COMPLEX_OAM_H

#include "types.h"

void process_complex_oam(u32 oamSlot, i16 xPosition, i16 yPosition, u16 rotation, i16 scaling, u8 doubleSize, u8 flipSize);
void calculate_oam_part4(u16 rotation, i16 scaling, u8 oamSlot);

#endif /* COMPLEX_OAM_H */
