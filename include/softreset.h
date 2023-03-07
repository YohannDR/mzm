#ifndef SOFTRESET_H
#define SOFTRESET_H

#include "types.h"

u32 SoftresetSubroutine(void);
void SoftresetInit(void);
void SoftresetVBlank(void);
void SoftresetVBlank_Empty(void);

#endif /* SOFTRESET_H */
