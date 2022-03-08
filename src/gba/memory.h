#ifndef GBA_MEMORY_H
#define GBA_MEMORY_H

#define IWRAM_BASE (void *)0x02000000
#define IWRAM_SIZE (32 * 0x400)

#define EWRAM_BASE (void *)0x03000000
#define EWRAM_SIZE (256 * 0x400)

#define REG_BASE (void *)0x04000000

#define PALRAM_BASE (void *)0x05000000
#define PALRAM_SIZE 0x400

#define VRAM_BASE (void *)0x06000000
#define VRAM_SIZE (96 * 0x400)

#define OAM_BASE (void *)0x07000000
#define OAM_SIZE 0x400

#define ROM_BASE (void *)0x08000000
#define ROM_SIZE (32 * 0x100000)

#endif /* GBA_MEMORY_H */
