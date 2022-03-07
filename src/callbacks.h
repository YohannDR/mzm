#ifndef CALLBACKS_H
#define CALLBACKS_H

#include "types.h"

typedef void (*callback_t)(void);

extern callback_t vblank_callback;
extern callback_t hblank_callback;
extern callback_t vcount_callback;
extern callback_t serial_comm_callback;
extern callback_t timer3_callback;

void call_vblank_callback(void);
void set_vblank_callback(callback_t callback);
void call_hblank_callback(void);
void set_hblank_callback(callback_t callback);
void call_vcount_callback(void);
void set_vcount_callback(callback_t callback);
void call_serial_comm_callback(void);
void set_serial_comm_callback(callback_t callback);
void call_timer3_callback(void);
void set_timer3_callback(callback_t callback);
void empty_callback(void);

#endif /* CALLBACKS_H */
