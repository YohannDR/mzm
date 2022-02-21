#ifndef RIPPER_AI_H
#define RIPPER_AI_H

#include "../types.h"

void ripper_init(void);
void ripper_gfx_init(void);
void ripper_move(void);
void ripper_turn_around_gfx_init(void);
void ripper_turn_around_begin(void);
void ripper_check_turned_around(void);
void ripper(void);

#endif /* RIPPER_AI_H */