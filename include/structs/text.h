#ifndef TEXT_STRUCT_H
#define TEXT_STRUCT_H

#include "types.h"

struct Message {
    u16 textIndex;
    u16 indent;
    u16 delay;
    u8 color;
    u8 line;

    u8 unk_8;
    u8 unk_9;

    u8 messageID;
    u8 gfxSlot;
    u8 stage;
    u8 isMessage;
    u8 messageEnded;
    u8 unk_F;
};

extern struct Message gCurrentMessage;
extern u32 gCurrentCharacterGfx[32];

#endif /* TEXT_STRUCT_H */
