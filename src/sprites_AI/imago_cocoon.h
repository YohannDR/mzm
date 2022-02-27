#ifndef IMAGO_COCOON_AI_H
#define IMAGO_COCOON_AI_H

#include "../types.h"
#include "../clipdata.h"

void imago_cocoon_update_position_and_anim(void);
void imago_cocoon_change_one_ccaa(enum current_clipdata_affecting_action caa);
void imago_cocoon_change_two_middle_ccaa(enum current_clipdata_affecting_action caa);
void imago_cocoon_change_two_around_ccaa(enum current_clipdata_affecting_action caa);
void imago_cocoon_change_two_blocking_ccaa(enum current_clipdata_affecting_action caa);
void imago_cocoon_change_oam_scaling(u16 limit, u16 value);
void imago_cocoon_init(void);
void imago_cocoon_falling_movement(void);
void imago_cocoon_spawning_dying(void);
void imago_cocoon_falling_before_blocks(void);
void imago_cocoon_falling_after_blocks(void);
void imago_cocoon_unlock_passage(void);
void imago_cocoon_in_ground_anim(void);
void imago_cocoon_vine_init(void);
void imago_cocoon_vine_play_sound(void);
void imago_cocoon_vine_death(void);
void imago_cocoon_vine_spawn_spore(void);
void imago_cocoon_vine_hanging_death(void);
void imago_cocoon_vine_hanging_death_anim(void);
void imago_cocoon_spore_sync_position(void);
void imago_cocoon_spore_init(void);
void imago_cocoon_spore_before_spawning(void);
void imago_cocoon_spore_spawning(void);
void imago_cocoon_spore_move(void);
void imago_cocoon_spore_exploding_gfx_init(void);
void imago_cocoon_spore_check_exploding_anim_ended(void);
u8 winged_ripper_imago_collision(void);
void winged_ripper_init(void);
void winged_ripper_gfx_init(void);
void winged_ripper_move(void);
void winged_ripper_death(void);
void imago_cocoon(void);
void imago_cocoon_vine(void);
void imago_cocoon_spore(void);
void winged_ripper(void);
void defeated_imago_cocoon(void);
void imago_ceiling_vine(void);
void event_trigger_discovered_imago_passage(void);
void imago_cocoon_after_fight(void);

#endif /* IMAGO_COCOON_AI_H */