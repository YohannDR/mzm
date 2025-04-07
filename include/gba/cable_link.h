#ifndef GBA_CABLE_LINK_H
#define GBA_CABLE_LINK_H

#include "memory.h"
#include "types.h"

#define REG_TM0CNT_L (REG_BASE + 0x100)
#define REG_TM0CNT_H (REG_BASE + 0x102)

#define REG_TM3CNT_L (REG_BASE + 0x10C)
#define REG_TM3CNT_H (REG_BASE + 0x10E)

#define REG_SIO_MULTI (REG_BASE + 0x120)
#define REG_SIO (REG_BASE + 0x128)
#define REG_SIO_DATA8 (REG_BASE + 0x12A)
#define REG_RNCT (REG_BASE + 0x134)

#define SIO_SHIFT_CLOCK_EXTERNAL (0 << 0)
#define SIO_SHIFT_CLOCK_INTERNAL (1 << 0)

#define SIO_INTERNAL_SHIFT_CLOCK_256K (0 << 1)
#define SIO_INTERNAL_SHIFT_CLOCK_2M   (1 << 1)

#define SIO_8BIT_MODE  (0 << 12)
#define SIO_32BIT_MODE (1 << 12)
#define SIO_MULTI_MODE (2 << 12)
#define SIO_UART_MODE  (3 << 12)

#define SIO_SHIFT_CLOCK               (1 << 0)
#define SIO_INTERNAL_SHIFT_CLOCK      (1 << 1)
#define SIO_STATE_HIGH_OR_NONE        (1 << 2)
#define SIO_HIGH_DURING_INACTIVITY    (1 << 3)
#define SIO_START_BIT_ACTIVE          (1 << 7)
#define SIO_IRQ_ENABLE                (1 << 14)

#define SIO_BAUD_RATE_9600   (0 << 0)
#define SIO_BAUD_RATE_38400  (1 << 0)
#define SIO_BAUD_RATE_57600  (2 << 0)
#define SIO_BAUD_RATE_115200 (3 << 0)

#define SIO_MULTI_PARENT (0 << 2)
#define SIO_MULTI_CHILD  (1 << 2)

#define SIO_MULTI_CONNECTION_ID(i)      ((i) << 4)

#define SIO_MULTI_RECEIVE_ID            (1 << 2)
#define SIO_MULTI_CONNECTION_READY      (1 << 3)
#define SIO_MULTI_CONNECTION_ID_FLAG    (3 << 4)
#define SIO_MULTI_ERROR                 (1 << 6)

#define TIMER_CONTROL_IRQ_ENABLE (1 << 6)
#define TIMER_CONTROL_ACTIVE     (1 << 7)

#endif /* GBA_CABLE_LINK_H */
