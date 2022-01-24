#ifndef GLOBALS_H
#define GLOBALS_H

extern unsigned char softreset_disabled;
extern unsigned short game_mode;
extern unsigned short button_input;
extern unsigned short button_input_old;
extern unsigned short buttons_changed;
extern void *sp_sys;
extern void *sp_irq;
extern void *intr_vector; // TODO: proper type

#endif /* GLOBALS_H */
