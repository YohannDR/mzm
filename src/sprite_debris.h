#ifndef SPRITE_DEBRIS_H
#define SPRITE_DEBRIS_H

#include "types.h"
#include "clipdata.h"
#include "oam.h"

struct SpriteDebris {
    struct FrameData* oam_pointer;
    u16 currentAnimationFrame;
    u16 yPosition;
    u16 xPosition;
    u8 animationDuratoinCounter;
    u8 exists;
    u8 debris_type;
    u8 frame_counter;
    u8 array_offset;
};

void SpriteDebrisSetSplash(u16 old_y, u16 yPosition, u16 xPosition);
void SpriteDebrisProcess(struct SpriteDebris* pDebris);
void SpriteDebrisProcessAll(void);
void SpriteDebrisDraw(struct SpriteDebris* pDebris);
void SpriteDebrisDrawAll(void);
void SpriteDebrisInit(u8 cloud_type, u8 debris_type, u16 yPosition, u16 xPosition);

#endif /* SPRITE_DEBRIS_H */