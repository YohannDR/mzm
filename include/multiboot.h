#ifndef MULTIBOOT_H
#define MULTIBOOT_H

#include "types.h"
#include "structs/multiboot.h"

void MultiBootInit(struct MultiBootData* pMultiBoot);
u32 MultiBootMain(struct MultiBootData* pMultiBoot);
u32 MultiBootSend(struct MultiBootData* pMultiBoot, u16 data);
void MultiBootStartProbe(struct MultiBootData* pMultiBoot);
void MultiBootStartParent(struct MultiBootData* pMultiBoot, const u8* src, s32 length, u8 palette_color, s8 palette_speed);
u32 MultiBootCheckComplete(struct MultiBootData* pMultiBoot);
u32 MultiBootHandshake(struct MultiBootData* pMultiBoot);
void MultiBootWaitCycles(s32 cycles);
void MultiBootWaitSendDone(void);

#endif /* MULTIBOOT_H */
