#ifndef GADORA_AI_H
#define GADORA_AI_H

#include "../types.h"

void gadora_init(void);
void gadora_gfx_init(void);
void gadora_samus_detection(void);
void gadora_check_before_opening_eye_anim_ended(void);
void gadora_check_opening_eye_anim_ended(void);
void gadora_eye_opened(void);
void gadora_check_closing_eye_anim_near_ended(void);
void gadora_death_gfx_init(void);
void gadora_death(void);
void gadora(void);
void gadora_eye(void);
void gadora_beam(void);

#endif /* GADORA_AI_H */