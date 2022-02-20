#ifndef ESCAPE_H
#define ESCAPE_H

#include "types.h"

enum __attribute__((packed)) escape {
    ESCAPE_NONE = 0x0,
    ESCAPE_MOTHER_BRAIN = 0x1,
    ESCAPE_MECHA_RIDLEY = 0x2
};

enum __attribute__((packed)) escape_status {
    ESCAPE_STATUS_NONE = 0x0,
    ESCAPE_STATUS_HAPPENNING = 0x1,
    ESCAPE_STATUS_FAILED = 0x2
};

struct __attribute__((packed)) escape_digits {
    u8 hundredths;
    u8 tenths;
    u8 seconds_ones;
    u8 seconds_tens;
    u8 minutes_ones;
    u8 minutes_tens;
};

enum escape escape_determine_timer(void);
u8 escape_check_has_escaped(void);
void escape_update_oam(void);
void unk_53a18(void);
void escape_start(void);
void escape_set_timer(void);
void escape_update_timer(void);

#endif /* ESCAPE_H */