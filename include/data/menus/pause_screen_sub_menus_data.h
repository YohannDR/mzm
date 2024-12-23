#ifndef PAUSE_SCREEN_SUB_MENUS_DATA_H
#define PAUSE_SCREEN_SUB_MENUS_DATA_H

#include "types.h"
#include "structs/menus/pause_screen.h"
#include "constants/menus/pause_screen.h"

extern const struct ChozoStatueTarget sChozoStatueTargets[TARGET_END];

extern const u8 sChozoStatueTargetConditions[TARGET_END][2];
extern const u8 sChozoStatueHintEvents[TARGET_END];

extern const s8 sChozoStatueTargetPathBrinstar[9][2];
extern const s8 sChozoStatueTargetPathKraid[9][2];
extern const s8 sChozoStatueTargetPathNorfair[9][2];
extern const s8 sChozoStatueTargetPathRidley[9][2];
extern const s8 sChozoStatueTargetPathCrateria[9][2];

#endif /* PAUSE_SCREEN_SUB_MENUS_DATA_H */
