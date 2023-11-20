#include "data/empty_datatypes.h"
#include "types.h"

#include "constants/block.h"
#include "constants/connection.h"

// 345868

const struct HatchData sHatchData_Empty = {
    .exists = FALSE,
    .currentAnimationFrame = 0,
    .facingRight = FALSE,
    .padding = 0,
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

const struct BackgroundEffect sBackgroundEffect_Empty = {
    .unused = 0,
    .timer = 0,
    .colorStage = 0,
    .type = 0,
    .stage = 0,
    .unk_7 = 0
};

const struct BrokenBlock sBrokenBlock_Empty = {
    .broken = FALSE,
    .stage = 0,
    .type = BLOCK_TYPE_NONE,
    .xPosition = 0,
    .yPosition = 0,
    .timer = 0
};

const struct BombChain sBombChain_Empty = {
    .currentOffset = 0,
    .srcXPosition = 0,
    .srcYPosition = 0,
    .type = 0,
    .padding = 0,
    .flipped = 0,
    .unk = 0
};

const struct PowerBomb sPowerBomb_Empty = {
    .animationState = 0,
    .stage = 0,
    .semiMinorAxis = 0,
    .unk_3 = 0,
    .xPosition = 0,
    .yPosition = 0,
    .hitboxLeftOffset = 0,
    .hitboxRightOffset = 0,
    .hitboxTopOffset = 0,
    .hitboxBottomOffset = 0,
    .powerBombPlaced = FALSE,
    .owner = 0,
    .unk_12 = 0
};

const struct ScreenShake sScreenShake_Empty = {
    .timer = 0,
    .loopCounter = 0,
    .unk_2 = 0,
    .direction = 0
};

const struct BG0Movement sBg0Movement_Empty = {
    .type = 0,
    .counter = 0,
    .unused = 0,
    .xOffset = 0,
    .yOffset = 0
};

const struct BG3Movement sBg3Movement_Empty = {
    .active = FALSE,
    .counter = 0,
    .xOffset = 0,
    .undefined = 0
};

const struct Unused_3005504 sUnusedStruct_3005504_Empty = {
    .field_0 = 0,
    .field_4 = 0
};

const struct WaterMovement sWaterMovement_Empty = {
    .moving = FALSE,
    .stage = 0,
    .loopCounter = 0,
    .yOffset = 0
};

const struct TransparencyRelated sTransparencyRelated_Empty = {
    .unk_0 = 0,
    .unk_1 = 0,
    .unk_2 = 0,
    .unk_3 = 0
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
    .unk_0 = 0,
    .unk_1 = 0,
    .evbCoef = 0,
    .evaCoef = 0,
    .bldcnt = 0
};
