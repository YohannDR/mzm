#include "callbacks.h"

#include "gba.h"
#include "globals.h"
#include "io.h"
#include "music.h"

void call_vblank_callback(void) {
    if (vblank_callback) {
        vblank_callback();
    }

    write16(REG_IF, read16(REG_IF) | IF_VBLANK);
    vblank_request_flag = 1;
    unk_03007ff8 |= 0x01;

    if (!cleared_every_frame) {
        sub_08004d48();
    }
}

void set_vblank_callback(callback_t callback) {
    vblank_callback = callback;
    if (!callback) {
        vblank_callback = empty_callback;
    }
}

void call_hblank_callback(void) {
    if (hblank_callback) {
        hblank_callback();
    }

    write16(REG_IF, read16(REG_IF) | IF_HBLANK);
}

void set_hblank_callback(callback_t callback) {
    hblank_callback = callback;
    if (!callback) {
        hblank_callback = empty_callback;
    }
}

void call_vcount_callback(void) {
    if (vcount_callback) {
        vcount_callback();
    }
    
    write16(REG_IF, read16(REG_IF) | IF_VCOUNT);
}

void set_vcount_callback(callback_t callback) {
    vcount_callback = callback;
    if (!callback) {
        vcount_callback = empty_callback;
    }
}

void call_serial_callback(void) {
    if (serial_callback) {
        serial_callback();
    }

    write16(REG_IF, read16(REG_IF) | IF_SERIAL);
}

void set_serial_callback(callback_t callback) {
    serial_callback = callback;
    if (!callback) {
        serial_callback = empty_callback;
    }
}

void call_timer3_callback(void) {
    if (timer3_callback) {
        timer3_callback();
    }

    write16(REG_IF, read16(REG_IF) | IF_TIMER3);
}

void set_timer3_callback(callback_t callback) {
    timer3_callback = callback;
    if (!callback) {
        timer3_callback = empty_callback;
    }
}

void empty_callback(void) {
    return;
}
