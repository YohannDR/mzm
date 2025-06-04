#ifndef INTERNAL_STATUS_SCREEN_DATA_H
#define INTERNAL_STATUS_SCREEN_DATA_H

#include "types.h"
#include "constants/event.h"

#ifdef DEBUG
extern const u8* const sPauseDebugEventNamePointers[EVENT_COUNT];
#endif // DEBUG
extern const u8 sStatusScreenGroupsDimensions[6][3];
extern const u8 sPauseScreen_7603ea[6];

#endif /* INTERNAL_STATUS_SCREEN_DATA_H */
