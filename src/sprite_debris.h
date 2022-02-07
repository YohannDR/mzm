#ifndef SPRITE_DEBRIS_H
#define SPRITE_DEBRIS_H

#include "types.h"
#include "oam.h"

struct sprite_debris {
    struct frame_data* oam_pointer;
    u16 curr_anim_frame;
    u16 y_position;
    u16 x_position;
    u8 anim_duration_counter;
    u8 exists;
    u8 debris_type;
    u8 falling_timer;
    u8 array_offset;
    u8 undefined;
};

void sprite_debris_set_splash(u16 old_y, u16 y_position, u16 x_position);
void sprite_debris_process(struct sprite_debris* pDebris);
void sprite_debris_process_all(void);
void sprite_debris_draw(struct sprite_debris* pDebris);
void sprite_debris_draw_all(void);
void sprite_debris_init(u8 cloud_type, u8 debris_type, u16 y_position, u16 x_position);

#endif /* SPRITE_DEBRIS_H */