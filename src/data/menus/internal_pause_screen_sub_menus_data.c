#include "data/menus/internal_pause_screen_sub_menus_data.h"
#include "data/menus/pause_screen_sub_menus_data.h"

#include "constants/connection.h"

const s8* const sChozoStatueTargetPathPointers[6] = {
    [AREA_BRINSTAR] = (s8*)sChozoStatueTargetPathBrinstar,
    [AREA_KRAID] = (s8*)sChozoStatueTargetPathKraid,
    [AREA_NORFAIR] = (s8*)sChozoStatueTargetPathNorfair,
    [AREA_RIDLEY] = (s8*)sChozoStatueTargetPathRidley,
    [AREA_TOURIAN] = (s8*)NULL,
    [AREA_CRATERIA] = (s8*)sChozoStatueTargetPathCrateria
};
