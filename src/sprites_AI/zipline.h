#ifndef ZIPLINE_AI_H
#define ZIPLINE_AI_H

#include "../types.h"

void zipline_check_colliding(void);
u8 zipline_moving(void);
void zipline_gfx_update(void);
void zipline_init(void);
void zipline_update(void);
void zipline_button_init(void);
void zipline_button_activated_gfx_init(void);
void zipline_button_spawn(void);
void zipline_button_check_ziplines_activated(void);
void zipline_button_idle(void);
void zipline_button_zipline_moving(void);
void zipline(void);
void zipline_button(void);

#endif /* ZIPLINE_AI_H */