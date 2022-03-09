#ifndef GLOBALS_H
#define GLOBALS_H

#include "callbacks.h"
#include "types.h"

enum pause_screen_flags {
    PAUSE_SCREEN_NONE,
    PAUSE_SCREEN_UNKNOWN_1,
    PAUSE_SCREEN_PAUSE_OR_CUTSCENE,
    PAUSE_SCREEN_UNKNOWN_3,
    PAUSE_SCREEN_CHOZO_HINT,
    PAUSE_SCREEN_MAP_DOWNLOAD,
    PAUSE_SCREEN_ITEM_ACQUISITION,
    PAUSE_SCREEN_SUITLESS_ITEMS,
    PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS,
    PAUSE_SCREEN_UNKNOWN_9,
};

extern u8 debug_flag;
extern u16 frame_counter_16bit;
extern u8 stereo_enabled;
extern u32 curr_demo; /* XXX: type */
extern u8 reset_game;
extern u8 softreset_disabled;
extern i8 curr_cutscene;
extern i8 unk_0300007e;
extern u8 pause_screen_flag;
extern u16 button_input;
extern u16 button_input_old;
extern u16 buttons_changed;
extern u8 unk_030013d2;
extern void *sp_sys;
extern void *sp_irq;
extern callback_t intr_vector[13];
extern u16 intr_code[0x100];
extern u16 (*intr_code_ptr)[0x100];
extern i8 unk_03000c76;
extern u8 frame_counter_8bit;
extern vu16 vblank_request_flag;
extern u16 unk_03007ff8;

#endif /* GLOBALS_H */
