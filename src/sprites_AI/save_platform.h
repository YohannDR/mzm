#ifndef SAVE_PLATFORM_AI_H
#define SAVE_PLATFORM_AI_H

#include "../types.h"

u8 save_platform_detect_samus(void);
void save_platform_init(void);
void save_platform_samus_detection(void);
void save_platform_check_opening_anim_ended(void);
void save_platform_second_samus_detection(void);
void save_platform_check_closing_anim_ended(void);
void save_platform_release_samus(void);
void save_platform_samus_detection_out(void);
void save_platform_spawn_sprites(void);
void save_platform_flashing_anim(void);
void save_platform_flashing_anim_end(void);
void save_platform_text_timer(void);
void save_platform_check_message_banner_out(void);
void save_platform_message_banner_disappearing_timer(void);
void save_platform_top_init(void);
void save_platform_top_empty(void);
void save_platform_top_extend_gfx_init(void);
void save_platform_top_check_extending_ended(void);
void save_platform_top_retract_gfx_init(void);
void save_platform_top_check_retracting_ended(void);
void save_platform_top_check_tube_anim_spawn_ended(void);
void save_platform_top_spawn_big_light(void);
void save_platform_top_check_tube_anim_ended(void);
void save_platform_top_check_tube_anim_despawn_ended(void);
void save_platform_top_check_tube_around_anim_ended(void);
void save_platform_top_tube_down_up_anim(void);
void save_platform(void);
void save_platform_top(void);

#endif /* SAVE_PLATFORM_AI_H */