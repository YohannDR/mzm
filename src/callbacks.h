#ifndef CALLBACKS_H
#define CALLBACKS_H

#include "types.h"

extern Func_t vblank_callback;
extern Func_t hblank_callback;
extern Func_t vcount_callback;
extern Func_t serial_comm_callback;
extern Func_t timer3_callback;

void call_vblank_callback(void);
void set_vblank_callback(Func_t callback);
void call_hblank_callback(void);
void set_hblank_callback(Func_t callback);
void call_vcount_callback(void);
void set_vcount_callback(Func_t callback);
void call_serial_comm_callback(void);
void set_serial_comm_callback(Func_t callback);
void call_timer3_callback(void);
void set_timer3_callback(Func_t callback);
void empty_callback(void);

#endif /* CALLBACKS_H */
