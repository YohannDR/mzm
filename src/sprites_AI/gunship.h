#ifndef GUNSHIP_AI_H
#define GUNSHIP_AI_H

#include "../types.h"

void gunship_flicker_flames(void);
void gunship_porthole_flames(void);
u8 gunship_check_samus_enter(void);
void gunship_init(void);
void gunship_game_start_move(void);
void gunship_samus_enter(void);
void gunship_samus_entering(void);
void gunship_refill(void);
void gunship_after_refill(void);
void gunship_after_save(void);
void gunship_saving(void);
void gunship_samus_leave(void);
void gunship_samus_leaving(void);
void gunship_release_samus(void);
void gunship_reset(void);
void gunship_check_samus_on_top_after_leaving(void);
void gunship_escape_zebes(void);
void gunship_samus_entering_when_escaping(void);
void gunship_spawn_flames_escape(void);
void gunship_taking_off(void);
void gunship_flying(void);
void gunship_part_init(void);
void gunship_part_flames_flying_gfx_init(void);
void unk_45974(void);
void unk_459ac(void);
void gunship_part_check_landing_ended(void);
void unk_45a40(void);
void gunship_part_entry_sides(void);
void gunship_part_entry_sides_close(void);
void gunship_part_entry_top(void);
void gunship_part_entry_top_close(void);
void gunship_partcheck_spawn_platform(void);
void gunship_spawn_platform(void);
void gunship_part_despawn_platform(void);
void unk_45dfc(void);
void gunship(void);
void gunship_part(void);

#endif /* GUNSHIP_AI_H */