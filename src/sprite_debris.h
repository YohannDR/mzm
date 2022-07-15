#ifndef SPRITE_DEBRIS_H
#define SPRITE_DEBRIS_H

#include "types.h"
#include "clipdata.h"
#include "oam.h"

struct SpriteDebris {
    struct FrameData* oam_pointer;
    u16 curr_anim_frame;
    u16 y_position;
    u16 x_position;
    u8 anim_duration_counter;
    u8 exists;
    u8 debris_type;
    u8 frame_counter;
    u8 array_offset;
};

void SpriteDebrisSetSplash(u16 old_y, u16 y_position, u16 x_position);
void SpriteDebrisProcess(struct SpriteDebris* pDebris);
void SpriteDebrisProcessAll(void);
void SpriteDebrisDraw(struct SpriteDebris* pDebris);
void SpriteDebrisDrawAll(void);
void SpriteDebrisInit(u8 cloud_type, u8 debris_type, u16 y_position, u16 x_position);

#endif /* SPRITE_DEBRIS_H */