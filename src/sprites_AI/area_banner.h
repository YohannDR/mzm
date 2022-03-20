#ifndef AREA_BANNER_AI_H
#define AREA_BANNER_AI_H

#include "../types.h"

void area_banner_init(void);
void area_banner_spawn(void);
void area_banner_check_scrolling_up_anim_ended(void);
void area_banner_static(void);
void area_banner_check_removing_anim_ended(void);
void area_banner(void);

#endif /* AREA_BANNER_AI_H */