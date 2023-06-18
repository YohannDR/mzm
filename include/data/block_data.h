#ifndef BLOCK_DATA_H
#define BLOCK_DATA_H

#include "types.h"

#include "constants/clipdata.h"
#include "constants/game_state.h"

#include "structs/block.h"
#include "structs/connection.h"

extern const struct TankList sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS];

extern const struct TankList sStartingHealthAmmo;

extern const struct TankList sTankIncreaseAmount[MAX_AMOUNT_OF_DIFFICULTIES];

extern const u16 sClipdataAffectingActionDamageTypes[MAX_AMOUNT_OF_CAA];

extern const struct BlockBehavior sBlockBehaviors[MAX_AMOUNT_OF_BLOCKS];

extern const u16 sBlockWeaknesses[MAX_AMOUNT_OF_BLOCKS_TYPES];

extern const u16 sReformingBlocksTilemapValue[MAX_AMOUNT_OF_BLOCKS_TYPES];

extern const u8 sBrokenBlocksTimers[MAX_AMOUNT_OF_BLOCKS_TYPES][13];

extern const struct BombChainReverseData sBombChainReverseData[8];

extern const struct TankBehavior sTankBehaviors[MAX_AMOUNT_OF_TANK_TYPES];

extern const u16 sHatchBehaviors[MAX_AMOUNT_OF_HATCH_TYPES][2];

extern const u16 sBldalphaValuesForClipdata[11];

extern const s8 sSubBombChainPositionOffset[4][4];

extern const u8 sHatchRelated_345cee[4][2];

extern const u16 sMotherBrainGlassBreakingBaseTilemapValues[5];

#endif
