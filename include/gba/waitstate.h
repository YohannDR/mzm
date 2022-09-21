#ifndef GBA_WAITSTATE_H
#define GBA_WAITSTATE_H

#define REG_WAITCNT (REG_BASE + 0x204)

#define WAIT_SRAM_4CYCLES 0
#define WAIT_SRAM_3CYCLES (1 << 0)
#define WAIT_SRAM_2CYCLES (1 << 1)
#define WAIT_SRAM_8CYCLES (1 << 0 | 1 << 1)
#define WAIT_SRAM_CYCLES_MASK (1 << 0 | 1 << 1)

#define WAIT_BANK0_4CYCLES 0
#define WAIT_BANK0_3CYCLES (1 << 2)
#define WAIT_BANK0_2CYCLES (1 << 3)
#define WAIT_BANK0_8CYCLES (1 << 2 | 1 << 3)
#define WAIT_BANK0_SUBSEQUENT_1CYCLE (1 << 4)
#define WAIT_BANK0_CYCLES_MASK (1 << 2 | 1 << 3 | 1 << 4)

#define WAIT_BANK1_4CYCLES 0
#define WAIT_BANK1_3CYCLES (1 << 5)
#define WAIT_BANK1_2CYCLES (1 << 6)
#define WAIT_BANK1_8CYCLES (1 << 5 | 1 << 6)
#define WAIT_BANK1_SUBSEQUENT_1CYCLE (1 << 7)
#define WAIT_BANK1_CYCLES_MASK (1 << 5 | 1 << 6 | 1 << 7)

#define WAIT_BANK2_4CYCLES 0
#define WAIT_BANK2_3CYCLES (1 << 8)
#define WAIT_BANK2_2CYCLES (1 << 9)
#define WAIT_BANK2_8CYCLES (1 << 8 | 1 << 9)
#define WAIT_BANK2_SUBSEQUENT_1CYCLE (1 << 10)
#define WAIT_BANK2_CYCLES_MASK (1 << 8 | 1 << 9 | 1 << 10)

#define WAIT_TERMOUT_4_19MHZ (1 << 11)
#define WAIT_TERMOUT_8_38MHZ (1 << 12)
#define WAIT_TERMOUT_16_76MHZ (1 << 11 | 1 << 12)
#define WAIT_TERMOUT_MASK (1 << 11 | 1 << 12)

#define WAIT_PREFETCH (1 << 13)

#define WAIT_GAMEPACK_CGB (1 << 14)

#endif /* GBA_WAITSTATE_H */
