#include "data/empty_datatypes.h"
#include "types.h"

#include "constants/connection.h"

// 345868

const struct HatchData sHatchData_Empty = {
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
    .sourceDoor = UCHAR_MAX,
};

const struct RawCoordsX sCoordsX_Empty = {
    .x = USHORT_MAX,
    .y = USHORT_MAX
};

const struct LockScreen sLockScreen_Empty = {
    .lock = FALSE,
    .xPositionCenter = USHORT_MAX,
    .yPositionCenter = USHORT_MAX,
};

// More...

// 34587c

// More ...

const struct TransparencyRelated sTransparencyRelated_Empty = {
    .unknown_0 = 0,
    .unknown_1 = 0,
    .unknown_2 = 0,
    .unknown_3 = 0
};

const struct LastElevatorUsed sLastElevatorUsed_Empty = {
    .unused = 0,
    .route = ELEVATOR_ROUTE_NONE,
    .direction = 0
};

const struct BldalphaData sBldalphaData_Empty = {
    .BLDCNT = 0,
    .activeFlag = FALSE,
    .evbCoef = 0,
    .evaCoef = 0,
    .delayMax = 0,
    .delay = 0,
    .intensity = 1
};

const struct BldyData sBldyData_Empty = {
    .BLDCNT = 0,
    .activeFlag = FALSE,
    .value = 0,
    .delayMax = 0,
    .delay = 0,
    .intensity = 1,
};

const struct DefaultTransparency sDefaultTransparency_Empty = {
    .unknown_0 = 0,
    .unknown_1 = 0,
    .evbCoef = 0,
    .evaCoef = 0,
    .unknown_4 = 0
};
