#ifndef EVENT_H
#define EVENT_H

#include "types.h"

extern u32 gEventsTriggered[8];

u32 EventFunction(u8 action, u8 event);

#endif /* EVENT_H */