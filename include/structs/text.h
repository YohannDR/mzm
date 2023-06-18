#ifndef TEXT_STRUCT_H
#define TEXT_STRUCT_H

#include "types.h"

struct Message {
    u16 textIndex;
    u16 indent;
    u16 timer;
    u8 color;
    u8 line;

    u8 continuousDelay;
    u8 delay;

    u8 messageID;
    u8 gfxSlot;
    u8 stage;
    u8 isMessage;
    u8 messageEnded;
};

extern struct Message gCurrentMessage;
extern u32 gCurrentCharacterGfx[32];
extern s8 gCurrentItemBeingAcquired;

#endif /* TEXT_STRUCT_H */
