#ifndef ESCAPE_SHIP_AI_H
#define ESCAPE_SHIP_AI_H

#include "../types.h"

void escape_ship_part_update_palette(u8 unk);
void escape_ship_set_ignore_samus(void);
void escape_ship_set_pirate_draw_order(void);
void escape_ship_pirate_collision(void);
void escape_ship_check_colliding_with_laser(void);
void escape_ship(void);
void escape_ship_part(void);

#endif /* ESCAPE_SHIP_AI_H */