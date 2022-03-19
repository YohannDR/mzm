#ifndef ESCAPE_H
#define ESCAPE_H

#include "types.h"

#define ESCAPE_NONE 0x0
#define ESCAPE_MOTHER_BRAIN 0x1
#define ESCAPE_MECHA_RIDLEY 0x2

#define ESCAPE_STATUS_NONE 0x0
#define ESCAPE_STATUS_HAPPENNING 0x1
#define ESCAPE_STATUS_FAILED 0x2

struct __attribute__((packed)) EscapeDigits {
    u8 hundredths;
    u8 tenths;
    u8 seconds_ones;
    u8 seconds_tens;
    u8 minutes_ones;
    u8 minutes_tens;
};

u8 escape_determine_timer(void);
u8 escape_check_has_escaped(void);
void escape_update_oam(void);
void unk_53a18(void);
void escape_start(void);
void escape_set_timer(void);
void escape_update_timer(void);

#endif /* ESCAPE_H */