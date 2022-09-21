#ifndef EMPTY_DATATYPES_C
#define EMPTY_DATATYPES_C

#include "types.h"
#include "connection.h"
#include "scroll.h"

// 345868

static const struct HatchData sHatchData_Empty = {
    .exists = FALSE,
    .currentAnimationFrame = 0,
    .facingRight = FALSE,
    .padding = 3,
    .opening = FALSE,
    .locked = FALSE,
    .flashingTimer = 0,
    .hitTimer = 0,
    .hits = 0,
    .type = HATCH_NONE,
    .animationDurationCounter = 0,
    .xPosition = 0,
    .yPosition = 0,
    .sourceDoor = 255,
};

static const struct RawCoordsX sCoordsX_Empty = {
    .x = 65535,
    .y = 65535
};

static const struct LockScreen sLockScreen_Empty = {
    .lock = FALSE,
    .xPositionCenter = 65535,
    .yPositionCenter = 65535,
};

// More...

// 34587c

#endif