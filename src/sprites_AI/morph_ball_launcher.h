#ifndef MORPH_BALL_LAUNCHER_AI_H
#define MORPH_BALL_LAUNCHER_AI_H

#include "../types.h"
#include "../clipdata.h"

void morph_ball_launcher_change_ccaa(enum current_clipdata_affecting_action caa);
void morph_ball_launcher_init(void);
void morph_ball_launcher_detect_bomb(void);
void morph_ball_launcher_bomb_timer(void);
void morph_ball_launcher_launch_samus_anim(void);
void morph_ball_launcher(void);
void morph_ball_launcher_back(void);

#endif /* MORPH_BALL_LAUNCHER_AI_H */
