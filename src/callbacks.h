#ifndef CALLBACKS_H
#define CALLBACKS_H

#include "types.h"

typedef void (*callback_t)(void);

void call_vblank_callback(void);
void set_vblank_callback(callback_t callback);
void call_hblank_callback(void);
void set_hblank_callback(callback_t callback);
void call_vcount_callback(void);
void set_vcount_callback(callback_t callback);
void call_serial_callback(void);
void set_serial_callback(callback_t callback);
void call_timer3_callback(void);
void set_timer3_callback(callback_t callback);
void empty_callback(void);

#endif /* CALLBACKS_H */
