#ifndef BOSS_STATUES_AI_H
#define BOSS_STATUES_AI_H

#include "../types.h"

void boss_statue_vertical_lign_change_ccaa(u8 caa);
void boss_statue_horizontal_lign_three_change_ccaa(u8 caa);
void boss_statue_horizontal_lign_height_change_ccaa(u8 caa);
void kraid_statue_after_open(void);
void kraid_statue_init(void);
void kraid_statue_check_background_locked(void);
void kraid_statue_opening(void);
void ridley_statue_change_three_ccaa(u8 caa);
void ridley_statue_change_four_ccaa(u8 caa);
void ridley_statue_after_open(void);
void ridley_statue_init(void);
void ridley_statue_check_background_locked(void);
void ridley_statue_opening(void);
void kraid_statue(void);
void ridley_statue(void);

#endif /* BOSS_STATUES_AI_H */