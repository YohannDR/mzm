#include "data/block_data.h"

#include "macros.h"


#include "constants/block.h"
#include "constants/connection.h"
#include "constants/text.h"

const struct TankList sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS] = {
    [AREA_BRINSTAR] = {
        .energy = 3,
        .missile = 10,
        .superMissile = 1,
        .powerBomb = 0,
    },
    [AREA_KRAID] = {
        .energy = 2,
        .missile = 9,
        .superMissile = 0,
        .powerBomb = 0
    },
    [AREA_NORFAIR] = {
        .energy = 1,
        .missile = 13,
        .superMissile = 2,
        .powerBomb = 1
    },
    [AREA_RIDLEY] = {
        .energy = 3,
        .missile = 13,
        .superMissile = 3,
        .powerBomb = 0
    },
    [AREA_TOURIAN] = {
        .energy = 0,
        .missile = 1,
        .superMissile = 0,
        .powerBomb = 1
    },
    [AREA_CRATERIA] = {
        .energy = 0,
        .missile = 3,
        .superMissile = 1,
        .powerBomb = 1
    },
    [AREA_CHOZODIA] = {
        .energy = 3,
        .missile = 1,
        .superMissile = 8,
        .powerBomb = 6
    },
    // Total number of tanks in the entire game
    [MAX_AMOUNT_OF_AREAS - 1] = {
        .energy = 12,
        .missile = 50,
        .superMissile = 15,
        .powerBomb = 9
    }
};

const struct TankList sStartingHealthAmmo = {
    .energy = 99,
    .missile = 0,
    .superMissile = 0,
    .powerBomb = 0,
};

const struct TankList sTankIncreaseAmount[MAX_AMOUNT_OF_DIFFICULTIES] = {
    [DIFF_EASY] = {
        .energy = 100,
        .missile = 5,
        .superMissile = 2,
        .powerBomb = 2
    },
    [DIFF_NORMAL] = {
        .energy = 100,
        .missile = 5,
        .superMissile = 2,
        .powerBomb = 2
    },
    [DIFF_HARD] = {
        .energy = 50,
        .missile = 2,
        .superMissile = 1,
        .powerBomb = 1,
    }
};

const u16 sClipdataAffectingActionDamageTypes[MAX_AMOUNT_OF_CAA] = {
    [CAA_NONE] =                   CAA_DAMAGE_TYPE_NONE,
    [CAA_REMOVE_SOLID] =           CAA_DAMAGE_TYPE_NONE,
    [CAA_MAKE_SOLID_GRIPPABLE] =   CAA_DAMAGE_TYPE_NONE,
    [CAA_MAKE_STOP_ENEMY] =            CAA_DAMAGE_TYPE_NONE,
    [CAA_MAKE_NON_POWER_GRIP] =            CAA_DAMAGE_TYPE_NONE,
    [CAA_BOMB_CHAIN_UNUSED] =      CAA_DAMAGE_TYPE_NONE,
    [CAA_BEAM] =                   CAA_DAMAGE_TYPE_BEAM,
    [CAA_BOMB_PISTOL] =            CAA_DAMAGE_TYPE_BOMB_PISTOL,
    [CAA_MISSILE] =                CAA_DAMAGE_TYPE_MISSILE,
    [CAA_SUPER_MISSILE] =          CAA_DAMAGE_TYPE_SUPER_MISSILE,
    [CAA_POWER_BOMB] =             CAA_DAMAGE_TYPE_POWER_BOMB,
    [CAA_SPEEDBOOSTER] =           CAA_DAMAGE_TYPE_SPEEDBOOST,
    [CAA_SPEEDBOOSTER_ON_GROUND] = CAA_DAMAGE_TYPE_SPEEDBOOST_ON_GROUND,
    [CAA_SCREW_ATTACK] =           CAA_DAMAGE_TYPE_SCREW_ATTACK,
    [CAA_BOMB_CHAIN] =             CAA_DAMAGE_TYPE_BOMB_CHAIN,
};

const struct BlockBehavior sBlockBehaviors[MAX_AMOUNT_OF_BLOCKS] = {
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SHOT_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_NO_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_TOP_LEFT_SHOT_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_TOP_RIGHT_SHOT_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_LEFT_SHOT_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_RIGHT_SHOT_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SHOT_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_TOP_LEFT_SHOT_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NO_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_TOP_RIGHT_SHOT_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NO_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_LEFT_SHOT_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NO_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_RIGHT_SHOT_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NO_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SHOT_BLOCK_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SHOT_BLOCK_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOMB_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_NO_REFORM,
        .type = BLOCK_TYPE_BOMB_BLOCK_NEVER_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOMB_BLOCK_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_BOMB_BLOCK_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_MISSILE_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_NO_REFORM,
        .type = BLOCK_TYPE_MISSILE_NEVER_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_MISSILE_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_MISSILE_NO_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SUPER_MISSILE_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_NO_REFORM,
        .type = BLOCK_TYPE_SUPER_MISSILE_NEVER_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SUPER_MISSILE_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SUPER_MISSILE_NO_REFORM
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SPEEDBOOST_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SPEEDBOOSTER_BLOCK_NO_REFORM,
        .isSpeedboost = TRUE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SPEEDBOOST_BLOCK_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SPEEDBOOSTER_BLOCK_REFORM,
        .isSpeedboost = TRUE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_CRUMBLE_BLOCK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_CRUMBLE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_POWER_BOMB_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_NO_REFORM,
        .type = BLOCK_TYPE_POWER_BOMB_NEVER_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SCREW_ATTACK_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SCREW_NO_REFORM,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN1)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_VERTICAL_BOMB_CHAIN1,
        .isSpeedboost = FALSE,
        .isBombChain = TRUE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN2)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_VERTICAL_BOMB_CHAIN2,
        .isSpeedboost = FALSE,
        .isBombChain = TRUE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN3)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_VERTICAL_BOMB_CHAIN3,
        .isSpeedboost = FALSE,
        .isBombChain = TRUE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN4)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_VERTICAL_BOMB_CHAIN4,
        .isSpeedboost = FALSE,
        .isBombChain = TRUE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN1)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN1,
        .isSpeedboost = FALSE,
        .isBombChain = TRUE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN2)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN2,
        .isSpeedboost = FALSE,
        .isBombChain = TRUE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN3)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN3,
        .isSpeedboost = FALSE,
        .isBombChain = TRUE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN4)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN4,
        .isSpeedboost = FALSE,
        .isBombChain = TRUE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SLOW_CRUMBLE_BLOCK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SLOW_CRUMBLE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    // Empty space, 31-35 (5 blocks)
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HIDDEN_ENERGY_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_TANK,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HIDDEN_MISSILE_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_TANK,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HIDDEN_SUPER_MISSILE_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_TANK,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HIDDEN_POWER_BOMB_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_TANK,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_ENERGY_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_MISSILE_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SUPER_MISSILE_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_POWER_BOMB_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_UNDERWATER_ENERGY_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_UNDERWATER_MISSILE_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_UNDERWATER_SUPER_MISSILE_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
    [BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_UNDERWATER_POWER_BOMB_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .isSpeedboost = FALSE,
        .isBombChain = FALSE
    },
};

const u16 sBlockWeaknesses[MAX_AMOUNT_OF_BLOCKS_TYPES] = {
    [BLOCK_TYPE_NONE] = CAA_DAMAGE_TYPE_NONE,
    [BLOCK_TYPE_SHOT_BLOCK_REFORM] = USHORT_MAX,
    [BLOCK_TYPE_BOMB_BLOCK_REFORM] = CAA_DAMAGE_TYPE_BOMB_PISTOL | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_SPEEDBOOST | CAA_DAMAGE_TYPE_SCREW_ATTACK,
    [BLOCK_TYPE_SPEEDBOOSTER_BLOCK_REFORM] = CAA_DAMAGE_TYPE_SPEEDBOOST,
    [BLOCK_TYPE_CRUMBLE] = CAA_DAMAGE_TYPE_SPEEDBOOST,
    [BLOCK_TYPE_SLOW_CRUMBLE] = CAA_DAMAGE_TYPE_SPEEDBOOST,
    [BLOCK_TYPE_MISSILE_NEVER_REFORM] = CAA_DAMAGE_TYPE_MISSILE | CAA_DAMAGE_TYPE_SUPER_MISSILE,
    [BLOCK_TYPE_MISSILE_NO_REFORM] = CAA_DAMAGE_TYPE_MISSILE | CAA_DAMAGE_TYPE_SUPER_MISSILE,
    [BLOCK_TYPE_SUPER_MISSILE_NEVER_REFORM] = CAA_DAMAGE_TYPE_SUPER_MISSILE,
    [BLOCK_TYPE_SUPER_MISSILE_NO_REFORM] = CAA_DAMAGE_TYPE_SUPER_MISSILE,
    [BLOCK_TYPE_POWER_BOMB_NEVER_REFORM] = CAA_DAMAGE_TYPE_POWER_BOMB,
    [BLOCK_TYPE_SCREW_NO_REFORM] = CAA_DAMAGE_TYPE_SCREW_ATTACK,
    [BLOCK_TYPE_SPEEDBOOSTER_BLOCK_NO_REFORM] = CAA_DAMAGE_TYPE_SPEEDBOOST,
    [BLOCK_TYPE_BOMB_BLOCK_NEVER_REFORM] = CAA_DAMAGE_TYPE_BOMB_PISTOL | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_SPEEDBOOST | CAA_DAMAGE_TYPE_SCREW_ATTACK,
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN1] = CAA_DAMAGE_TYPE_BOMB_CHAIN | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_BOMB_PISTOL,
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN2] = CAA_DAMAGE_TYPE_BOMB_CHAIN | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_BOMB_PISTOL,
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN3] = CAA_DAMAGE_TYPE_BOMB_CHAIN | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_BOMB_PISTOL,
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN4] = CAA_DAMAGE_TYPE_BOMB_CHAIN | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_BOMB_PISTOL,
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN1] = CAA_DAMAGE_TYPE_BOMB_CHAIN | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_BOMB_PISTOL,
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN2] = CAA_DAMAGE_TYPE_BOMB_CHAIN | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_BOMB_PISTOL,
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN3] = CAA_DAMAGE_TYPE_BOMB_CHAIN | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_BOMB_PISTOL,
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN4] = CAA_DAMAGE_TYPE_BOMB_CHAIN | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_BOMB_PISTOL
};

const u16 sReformingBlocksTilemapValue[MAX_AMOUNT_OF_BLOCKS_TYPES] = {
    [BLOCK_TYPE_NONE] =                         CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_AIR,
    [BLOCK_TYPE_SHOT_BLOCK_REFORM] =            CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SHOT_BLOCK_REFORM,
    [BLOCK_TYPE_BOMB_BLOCK_REFORM] =            CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_BOMB_BLOCK_REFORM,
    [BLOCK_TYPE_SPEEDBOOSTER_BLOCK_REFORM] =    CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SPEEDBOOST_REFORM,
    [BLOCK_TYPE_CRUMBLE] =                      CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_CRUMBLE,
    [BLOCK_TYPE_SLOW_CRUMBLE] =                 CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SLOW_CRUMBLE,
    [BLOCK_TYPE_MISSILE_NEVER_REFORM] =         CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_MISSILE_NEVER_REFORM,
    [BLOCK_TYPE_MISSILE_NO_REFORM] =            CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_MISSILE_NO_REFORM,
    [BLOCK_TYPE_SUPER_MISSILE_NEVER_REFORM] =   CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SUPER_MISSILE_NEVER_REFORM,
    [BLOCK_TYPE_SUPER_MISSILE_NO_REFORM] =      CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SUPER_MISSILE_NO_REFORM,
    [BLOCK_TYPE_POWER_BOMB_NEVER_REFORM] =      CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_POWER_BOMB_NEVER_REFORM,
    [BLOCK_TYPE_SCREW_NO_REFORM] =              CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SCREW_ATTACK_NO_REFORM,
    [BLOCK_TYPE_SPEEDBOOSTER_BLOCK_NO_REFORM] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SPEEDBOOST_NO_REFORM,
    [BLOCK_TYPE_BOMB_BLOCK_NEVER_REFORM] =      CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_BOMB_NEVER_REFORM,
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN1] =         CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_VERTICAL_BOMB_CHAIN1,
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN2] =         CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_VERTICAL_BOMB_CHAIN2,
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN3] =         CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_VERTICAL_BOMB_CHAIN3,
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN4] =         CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_VERTICAL_BOMB_CHAIN4,
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN1] =       CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_HORIZONTAL_BOMB_CHAIN1,
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN2] =       CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_HORIZONTAL_BOMB_CHAIN2,
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN3] =       CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_HORIZONTAL_BOMB_CHAIN3,
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN4] =       CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_HORIZONTAL_BOMB_CHAIN4
};

const u8 sBrokenBlocksTimers[MAX_AMOUNT_OF_BLOCKS_TYPES][13] = {
    [BLOCK_TYPE_NONE] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    },
    [BLOCK_TYPE_SHOT_BLOCK_REFORM] = {
        0, 0, 4, 4, 4, 4, 4, UCHAR_MAX, 4, 4, 4, 4, 4
    },
    [BLOCK_TYPE_BOMB_BLOCK_REFORM] = {
        0, 0, 4, 4, 4, 4, 4, UCHAR_MAX, 4, 4, 4, 4, 4
    },
    [BLOCK_TYPE_SPEEDBOOSTER_BLOCK_REFORM] = {
        0, 0, 4, 4, 4, 4, 4, 20, 4, 4, 4, 4, 4
    },
    [BLOCK_TYPE_CRUMBLE] = {
        0, 5, 4, 4, 4, 4, 4, 15, 4, 4, 4, 4, 4
    },
    [BLOCK_TYPE_SLOW_CRUMBLE] = {
        0, 60, 4, 4, 4, 4, 4, 30, 4, 4, 4, 4, 4
    },
    [BLOCK_TYPE_MISSILE_NEVER_REFORM] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    },
    [BLOCK_TYPE_MISSILE_NO_REFORM] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    },
    [BLOCK_TYPE_SUPER_MISSILE_NEVER_REFORM] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    },
    [BLOCK_TYPE_SUPER_MISSILE_NO_REFORM] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    },
    [BLOCK_TYPE_POWER_BOMB_NEVER_REFORM] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    },
    [BLOCK_TYPE_SCREW_NO_REFORM] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    },
    [BLOCK_TYPE_SPEEDBOOSTER_BLOCK_NO_REFORM] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    },
    [BLOCK_TYPE_BOMB_BLOCK_NEVER_REFORM] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    },
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN1] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    },
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN2] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    },
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN3] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    },
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN4] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    },
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN1] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    },
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN2] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    },
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN3] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    },
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN4] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    }
};

const struct BombChainReverseData sBombChainReverseData[8] = {
    [BOMB_CHAIN_TYPE_VERTICAL1] = {
        .typeFlag = bomb_chain_type_to_flag(BOMB_CHAIN_TYPE_VERTICAL1),
        .behavior = CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN1
    },
    [BOMB_CHAIN_TYPE_VERTICAL2] = {
        .typeFlag = bomb_chain_type_to_flag(BOMB_CHAIN_TYPE_VERTICAL2),
        .behavior = CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN2
    },
    [BOMB_CHAIN_TYPE_VERTICAL3] = {
        .typeFlag = bomb_chain_type_to_flag(BOMB_CHAIN_TYPE_VERTICAL3),
        .behavior = CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN3
    },
    [BOMB_CHAIN_TYPE_VERTICAL4] = {
        .typeFlag = bomb_chain_type_to_flag(BOMB_CHAIN_TYPE_VERTICAL4),
        .behavior = CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN4
    },
    [BOMB_CHAIN_TYPE_HORIZONTAL1] = {
        .typeFlag = bomb_chain_type_to_flag(BOMB_CHAIN_TYPE_HORIZONTAL1),
        .behavior = CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN1
    },
    [BOMB_CHAIN_TYPE_HORIZONTAL2] = {
        .typeFlag = bomb_chain_type_to_flag(BOMB_CHAIN_TYPE_HORIZONTAL2),
        .behavior = CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN2
    },
    [BOMB_CHAIN_TYPE_HORIZONTAL3] = {
        .typeFlag = bomb_chain_type_to_flag(BOMB_CHAIN_TYPE_HORIZONTAL3),
        .behavior = CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN3
    },
    [BOMB_CHAIN_TYPE_HORIZONTAL4] = {
        .typeFlag = bomb_chain_type_to_flag(BOMB_CHAIN_TYPE_HORIZONTAL4),
        .behavior = CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN4
    },
};

const struct TankBehavior sTankBehaviors[MAX_AMOUNT_OF_TANK_TYPES] = {
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_HIDDEN_ENERGY_TANK)] = {
        .itemType = ITEM_TYPE_NONE,
        .underwater = FALSE,
        .messageID = MESSAGE_NONE,
        .revealedClipdata = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_ENERGY_TANK
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_HIDDEN_MISSILE_TANK)] = {
        .itemType = ITEM_TYPE_NONE,
        .underwater = FALSE,
        .messageID = MESSAGE_NONE,
        .revealedClipdata = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_MISSILE_TANK
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_HIDDEN_SUPER_MISSILE_TANK)] = {
        .itemType = ITEM_TYPE_NONE,
        .underwater = FALSE,
        .messageID = MESSAGE_NONE,
        .revealedClipdata = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SUPER_MISSILE_TANK
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_HIDDEN_POWER_BOMB_TANK)] = {
        .itemType = ITEM_TYPE_NONE,
        .underwater = FALSE,
        .messageID = MESSAGE_NONE,
        .revealedClipdata = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_POWER_BOMB_TANK
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_ENERGY_TANK)] = {
        .itemType = ITEM_TYPE_ENERGY,
        .underwater = FALSE,
        .messageID = MESSAGE_ENERGY_TANK_ACQUIRED,
        .revealedClipdata = CLIPDATA_TILEMAP_AIR
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_MISSILE_TANK)] = {
        .itemType = ITEM_TYPE_MISSILE,
        .underwater = FALSE,
        .messageID = MESSAGE_MISSILE_TANK_ACQUIRED,
        .revealedClipdata = CLIPDATA_TILEMAP_AIR
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_SUPER_MISSILE_TANK)] = {
        .itemType = ITEM_TYPE_SUPER_MISSILE,
        .underwater = FALSE,
        .messageID = MESSAGE_SUPER_MISSILE_TANK_ACQUIRED,
        .revealedClipdata = CLIPDATA_TILEMAP_AIR
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_POWER_BOMB_TANK)] = {
        .itemType = ITEM_TYPE_POWER_BOMB,
        .underwater = FALSE,
        .messageID = MESSAGE_POWER_BOMB_TANK_ACQUIRED,
        .revealedClipdata = CLIPDATA_TILEMAP_AIR
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_UNDERWATER_ENERGY_TANK)] = {
        .itemType = ITEM_TYPE_ENERGY,
        .underwater = TRUE,
        .messageID = MESSAGE_ENERGY_TANK_ACQUIRED,
        .revealedClipdata = CLIPDATA_TILEMAP_AIR
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_UNDERWATER_MISSILE_TANK)] = {
        .itemType = ITEM_TYPE_MISSILE,
        .underwater = TRUE,
        .messageID = MESSAGE_MISSILE_TANK_ACQUIRED,
        .revealedClipdata = CLIPDATA_TILEMAP_AIR
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_UNDERWATER_SUPER_MISSILE_TANK)] = {
        .itemType = ITEM_TYPE_SUPER_MISSILE,
        .underwater = TRUE,
        .messageID = MESSAGE_SUPER_MISSILE_TANK_ACQUIRED,
        .revealedClipdata = CLIPDATA_TILEMAP_AIR
    },
    [BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_UNDERWATER_POWER_BOMB_TANK)] = {
        .itemType = ITEM_TYPE_POWER_BOMB,
        .underwater = TRUE,
        .messageID = MESSAGE_POWER_BOMB_TANK_ACQUIRED,
        .revealedClipdata = CLIPDATA_TILEMAP_AIR
    },
};

const u16 sHatchBehaviors[MAX_AMOUNT_OF_HATCH_TYPES][2] = {
    // 0 : Weakness
    // 2 : Health
    [HATCH_NONE] = {
        CAA_DAMAGE_TYPE_BEAM | CAA_DAMAGE_TYPE_BOMB_PISTOL | CAA_DAMAGE_TYPE_MISSILE | CAA_DAMAGE_TYPE_SUPER_MISSILE | CAA_DAMAGE_TYPE_POWER_BOMB,
        0
    },
    [HATCH_UNUSED] = {
        CAA_DAMAGE_TYPE_BEAM | CAA_DAMAGE_TYPE_BOMB_PISTOL | CAA_DAMAGE_TYPE_MISSILE | CAA_DAMAGE_TYPE_SUPER_MISSILE | CAA_DAMAGE_TYPE_POWER_BOMB,
        0
    },
    [HATCH_NORMAL] = {
        CAA_DAMAGE_TYPE_BEAM | CAA_DAMAGE_TYPE_BOMB_PISTOL | CAA_DAMAGE_TYPE_MISSILE | CAA_DAMAGE_TYPE_SUPER_MISSILE | CAA_DAMAGE_TYPE_POWER_BOMB,
        0
    },
    [HATCH_MISSILE] = {
        CAA_DAMAGE_TYPE_MISSILE | CAA_DAMAGE_TYPE_SUPER_MISSILE,
        0
    },
    [HATCH_SUPER_MISSILE] = {
        CAA_DAMAGE_TYPE_SUPER_MISSILE,
        0
    },
    [HATCH_POWER_BOMB] = {
        CAA_DAMAGE_TYPE_POWER_BOMB,
        0
    },
    [HATCH_LOCKED] = {
        CAA_DAMAGE_TYPE_BEAM | CAA_DAMAGE_TYPE_BOMB_PISTOL | CAA_DAMAGE_TYPE_MISSILE | CAA_DAMAGE_TYPE_SUPER_MISSILE | CAA_DAMAGE_TYPE_POWER_BOMB,
        0
    },
    [HATCH_LOCKED_AND_LOCK_DESTINATION] = {
        CAA_DAMAGE_TYPE_BEAM | CAA_DAMAGE_TYPE_BOMB_PISTOL | CAA_DAMAGE_TYPE_MISSILE | CAA_DAMAGE_TYPE_SUPER_MISSILE | CAA_DAMAGE_TYPE_POWER_BOMB,
        0
    },
};

const u16 sBldalphaValuesForClipdata[11] = {
    [BEHAVIOR_TO_BLDALPHA(CLIP_BEHAVIOR_BG0_TRIGGER_OPAQUE)] = 0x10,
    [BEHAVIOR_TO_BLDALPHA(CLIP_BEHAVIOR_BG0_TRIGGER_TRANSPARENT_LEVEL1)] = 0x30D,
    [BEHAVIOR_TO_BLDALPHA(CLIP_BEHAVIOR_BG0_TRIGGER_TRANSPARENT_LEVEL2)] = 0x60A,
    [BEHAVIOR_TO_BLDALPHA(CLIP_BEHAVIOR_BG0_TRIGGER_TRANSPARENT_LEVEL3)] = 0x907,
    [BEHAVIOR_TO_BLDALPHA(CLIP_BEHAVIOR_BG0_TRIGGER_TRANSPARENT_LEVEL4)] = 0xB05,
    [BEHAVIOR_TO_BLDALPHA(CLIP_BEHAVIOR_BG0_TRIGGER_TRANSPARENT_LEVEL5)] = 0xD03,
    [BEHAVIOR_TO_BLDALPHA(CLIP_BEHAVIOR_BG0_TRIGGER_TRANSPARENT_FULL)] = 0x1000,
    [BEHAVIOR_TO_BLDALPHA(CLIP_BEHAVIOR_BG0_TRIGGER_BRIGHTER_LEVEL1)] = 0x1007,
    [BEHAVIOR_TO_BLDALPHA(CLIP_BEHAVIOR_BG0_TRIGGER_BRIGHTER_LEVEL2)] = 0x100A,
    [BEHAVIOR_TO_BLDALPHA(CLIP_BEHAVIOR_BG0_TRIGGER_BRIGHTER_LEVEL3)] = 0x100D,
    [BEHAVIOR_TO_BLDALPHA(CLIP_BEHAVIOR_BG0_TRIGGER_BRIGHTER_LEVEL4)] = 0x1010,
};

const s8 sSubBombChainPositionOffset[4][4] = {
    {
        1, 1, -1, 1
    },
    {
        1, -1, -1, -1
    },
    {
        1, -1,  1, 1
    },
    {
        -1, -1, -1, 1
    }
};

const u8 sHatchRelated_345cee[4][2] = {
    { 0, 0 },
    { 0, 1 },
    { 1, 2 },
    { 2, 2 },
};

const u16 sMotherBrainGlassBreakingBaseTilemapValues[5] = {
    0x170, 0x177, 0x1C0, 0x1C7, 0x210
};
