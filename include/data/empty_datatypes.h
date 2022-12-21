#ifndef EMPTY_DATATYPES_C
#define EMPTY_DATATYPES_C

#include "types.h"

#include "constants/connection.h"

#include "structs/connection.h"
#include "structs/transparency.h"
#include "structs/scroll.h"

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

// More ...

static const struct TransparencyRelated sTransparencyRelated_Empty = {
    .unknown_0 = 0,
    .unknown_1 = 0,
    .unknown_2 = 0,
    .unknown_3 = 0
};

static const struct LastElevatorUsed sLastElevatorUsed_Empty = {
    .unused = 0,
    .route = ELEVATOR_ROUTE_NONE,
    .direction = 0
};

static const struct BldalphaData sBldalphaData_Empty = {
    .BLDCNT = 0,
    .activeFlag = FALSE,
    .evbCoef = 0,
    .evaCoef = 0,
    .delayMax = 0,
    .delay = 0,
    .intensity = 1
};

static const struct BldyData sBldyData_Empty = {
    .BLDCNT = 0,
    .activeFlag = FALSE,
    .value = 0,
    .delayMax = 0,
    .delay = 0,
    .intensity = 1,
};

static const struct DefaultTransparency sDefaultTransparency_Empty = {
    .unknown_0 = 0,
    .unknown_1 = 0,
    .evbCoef = 0,
    .evaCoef = 0,
    .unknown_4 = 0
};


#endif