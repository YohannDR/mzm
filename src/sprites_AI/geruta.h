#ifndef GERUTA_AI_H
#define GERUTA_AI_H

#include "../types.h"

u8 geruta_y_movement(u16 movement);
u8 geruta_x_movement(u16 movement);
void geruta_init(void);
void geruta_gfx_init(void);
void geruta_detect_samus(void);
void geruta_go_down_gfx_init(void);
void geruta_check_warning_ended(void);
void geruta_check_going_down_anim_ended(void);
void geruta_going_down(void);
void geruta_check_bouncing_anim_ended(void);
void geruta_going_up(void);
void geruta_check_reset_anim_ended(void);
void geruta(void);

#endif /* GERUTA_AI_H */