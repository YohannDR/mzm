#include "block.h"
#include "clipdata.h"
#include "samus.h"
#include "sprites_AI/item_banner.h"
#include "globals.h"

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
    [7] = {
        .energy = 18,
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
        .energy = 99,
        .missile = 5,
        .superMissile = 2,
        .powerBomb = 2
    },
    [DIFF_NORMAL] = {
        .energy = 99,
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
    [CAA_MAKE_SOLID2] =            CAA_DAMAGE_TYPE_NONE,
    [CAA_MAKE_SOLID3] =            CAA_DAMAGE_TYPE_NONE,
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
    [behavior_to_block(CLIP_BEHAVIOR_SHOT_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_NO_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_TOP_LEFT_SHOT_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_TOP_RIGHT_SHOT_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_BOTTOM_LEFT_SHOT_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_BOTTOM_RIGHT_SHOT_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_SHOT_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_TOP_LEFT_SHOT_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NO_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_TOP_RIGHT_SHOT_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NO_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_BOTTOM_LEFT_SHOT_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NO_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_BOTTOM_RIGHT_SHOT_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_SQUARE_NO_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_SHOT_BLOCK_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SHOT_BLOCK_REFORM,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_BOMB_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_NO_REFORM,
        .type = BLOCK_TYPE_BOMB_BLOCK_NEVER_REFORM,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_BOMB_BLOCK_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_BOMB_BLOCK_REFORM,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_MISSILE_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_NO_REFORM,
        .type = BLOCK_TYPE_MISSILE_NEVER_REFORM,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_MISSILE_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_MISSILE_NO_REFORM,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_SUPER_MISSILE_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_NO_REFORM,
        .type = BLOCK_TYPE_SUPER_MISSILE_NEVER_REFORM,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_SUPER_MISSILE_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SUPER_MISSILE_NO_REFORM
    },
    [behavior_to_block(CLIP_BEHAVIOR_SPEEDBOOST_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SPEEDBOOSTER_BLOCK_NO_REFORM,
        .unk = 1
    },
    [behavior_to_block(CLIP_BEHAVIOR_SPEEDBOOST_BLOCK_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SPEEDBOOSTER_BLOCK_REFORM,
        .unk = 1
    },
    [behavior_to_block(CLIP_BEHAVIOR_CRUMBLE_BLOCK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_CRUMBLE,
        .unk = 1
    },
    [behavior_to_block(CLIP_BEHAVIOR_POWER_BOMB_BLOCK_NEVER_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_NO_REFORM,
        .type = BLOCK_TYPE_POWER_BOMB_NEVER_REFORM,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_SCREW_ATTACK_BLOCK_NO_REFORM)] = {
        .lifeType = BLOCK_LIFE_TYPE_NO_NEVER_REFORM,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SCREW_NO_REFORM,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN1)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_VERTICAL_BOMB_CHAIN1,
        .unk = 0x10
    },
    [behavior_to_block(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN2)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_VERTICAL_BOMB_CHAIN2,
        .unk = 0x10
    },
    [behavior_to_block(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN3)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_VERTICAL_BOMB_CHAIN3,
        .unk = 0x10
    },
    [behavior_to_block(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN4)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_VERTICAL_BOMB_CHAIN4,
        .unk = 0x10
    },
    [behavior_to_block(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN1)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN1,
        .unk = 0x10
    },
    [behavior_to_block(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN2)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN2,
        .unk = 0x10
    },
    [behavior_to_block(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN3)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN3,
        .unk = 0x10
    },
    [behavior_to_block(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN4)] = {
        .lifeType = BLOCK_LIFE_TYPE_BOMB_CHAIN,
        .subType = BLOCK_SUB_TYPE_BOMB_CHAIN,
        .type = BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN4,
        .unk = 0x10
    },
    [behavior_to_block(CLIP_BEHAVIOR_SLOW_CRUMBLE_BLOCK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_SLOW_CRUMBLE,
        .unk = 0
    },
    // Empty space, 31-35 (5 blocks)
    [behavior_to_block(CLIP_BEHAVIOR_HIDDEN_ENERGY_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_TANK,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_HIDDEN_MISSILE_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_TANK,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_HIDDEN_SUPER_MISSILE_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_TANK,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_HIDDEN_POWER_BOMB_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_TANK,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_ENERGY_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_MISSILE_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_SUPER_MISSILE_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_POWER_BOMB_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_UNDERWATER_ENERGY_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_UNDERWATER_MISSILE_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_UNDERWATER_SUPER_MISSILE_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
    [behavior_to_block(CLIP_BEHAVIOR_UNDERWATER_POWER_BOMB_TANK)] = {
        .lifeType = BLOCK_LIFE_TYPE_NONE,
        .subType = BLOCK_SUB_TYPE_REFORM,
        .type = BLOCK_TYPE_NONE,
        .unk = 0
    },
};

const u16 sBlockWeaknesses[MAX_AMOUNT_OF_BLOCKS_TYPES] = {
    [BLOCK_TYPE_NONE] = CAA_DAMAGE_TYPE_NONE,
    [BLOCK_TYPE_SHOT_BLOCK_REFORM] = 0xFFFF,
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
    [BLOCK_TYPE_BOMB_BLOCK_NEVER_REFORM] = CAA_DAMAGE_TYPE_BOMB_CHAIN | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_SPEEDBOOST | CAA_DAMAGE_TYPE_SCREW_ATTACK,
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN1] = CAA_DAMAGE_TYPE_BOMB_CHAIN | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_BOMB_CHAIN,
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN2] = CAA_DAMAGE_TYPE_BOMB_CHAIN | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_BOMB_CHAIN,
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN3] = CAA_DAMAGE_TYPE_BOMB_CHAIN | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_BOMB_CHAIN,
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN4] = CAA_DAMAGE_TYPE_BOMB_CHAIN | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_BOMB_CHAIN,
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN1] = CAA_DAMAGE_TYPE_BOMB_CHAIN | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_BOMB_CHAIN,
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN2] = CAA_DAMAGE_TYPE_BOMB_CHAIN | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_BOMB_CHAIN,
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN3] = CAA_DAMAGE_TYPE_BOMB_CHAIN | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_BOMB_CHAIN,
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN4] = CAA_DAMAGE_TYPE_BOMB_CHAIN | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_BOMB_CHAIN
};

const u16 sReformingBlocksTilemapValue[MAX_AMOUNT_OF_BLOCKS_TYPES] = {
    [BLOCK_TYPE_NONE] =                         0x400,
    [BLOCK_TYPE_SHOT_BLOCK_REFORM] =            0x405,
    [BLOCK_TYPE_BOMB_BLOCK_REFORM] =            0x406,
    [BLOCK_TYPE_SPEEDBOOSTER_BLOCK_REFORM] =    0x409,
    [BLOCK_TYPE_CRUMBLE] =                      0x40B,
    [BLOCK_TYPE_SLOW_CRUMBLE] =                 0x47D,
    [BLOCK_TYPE_MISSILE_NEVER_REFORM] =         0x40C,
    [BLOCK_TYPE_MISSILE_NO_REFORM] =            0x40D,
    [BLOCK_TYPE_SUPER_MISSILE_NEVER_REFORM] =   0x40E,
    [BLOCK_TYPE_SUPER_MISSILE_NO_REFORM] =      0x40F,
    [BLOCK_TYPE_POWER_BOMB_NEVER_REFORM] =      0x407,
    [BLOCK_TYPE_SCREW_NO_REFORM] =              0x40A,
    [BLOCK_TYPE_SPEEDBOOSTER_BLOCK_NO_REFORM] = 0x408,
    [BLOCK_TYPE_BOMB_BLOCK_NEVER_REFORM] =      0x47C,
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN1] =         0x45C,
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN2] =         0x45D,
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN3] =         0x45E,
    [BLOCK_TYPE_VERTICAL_BOMB_CHAIN4] =         0x45F,
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN1] =       0x46C,
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN2] =       0x46D,
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN3] =       0x46E,
    [BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN4] =       0x46F
};

const u16 sBrokenBlocksTimers[MAX_AMOUNT_OF_BLOCKS_TYPES][13] = {
    [BLOCK_TYPE_NONE] = {
        0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0
    },
    [BLOCK_TYPE_SHOT_BLOCK_REFORM] = {
        0, 0, 4, 4, 4, 4, 4, 255, 4, 4, 4, 4, 4
    },
    [BLOCK_TYPE_BOMB_BLOCK_REFORM] = {
        0, 0, 4, 4, 4, 4, 4, 255, 4, 4, 4, 4, 4
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
    [behavior_to_tank(CLIP_BEHAVIOR_HIDDEN_ENERGY_TANK)] = {
        .itemType = ITEM_TYPE_NONE,
        .underwater = FALSE,
        .messageID = MESSAGE_NONE,
        .revealedClipdata = 0x41C
    },
    [behavior_to_tank(CLIP_BEHAVIOR_HIDDEN_MISSILE_TANK)] = {
        .itemType = ITEM_TYPE_NONE,
        .underwater = FALSE,
        .messageID = MESSAGE_NONE,
        .revealedClipdata = 0x41D
    },
    [behavior_to_tank(CLIP_BEHAVIOR_HIDDEN_SUPER_MISSILE_TANK)] = {
        .itemType = ITEM_TYPE_NONE,
        .underwater = FALSE,
        .messageID = MESSAGE_NONE,
        .revealedClipdata = 0x41E
    },
    [behavior_to_tank(CLIP_BEHAVIOR_HIDDEN_POWER_BOMB_TANK)] = {
        .itemType = ITEM_TYPE_NONE,
        .underwater = FALSE,
        .messageID = MESSAGE_NONE,
        .revealedClipdata = 0x41F
    },
    [behavior_to_tank(CLIP_BEHAVIOR_ENERGY_TANK)] = {
        .itemType = ITEM_TYPE_ENERGY,
        .underwater = FALSE,
        .messageID = MESSAGE_ENERGY_TANK_ACQUIRED,
        .revealedClipdata = 0
    },
    [behavior_to_tank(CLIP_BEHAVIOR_MISSILE_TANK)] = {
        .itemType = ITEM_TYPE_MISSILE,
        .underwater = FALSE,
        .messageID = MESSAGE_MISSILE_TANK_ACQUIRED,
        .revealedClipdata = 0
    },
    [behavior_to_tank(CLIP_BEHAVIOR_SUPER_MISSILE_TANK)] = {
        .itemType = ITEM_TYPE_SUPER_MISSILE,
        .underwater = FALSE,
        .messageID = MESSAGE_SUPER_MISSILE_TANK_ACQUIRED,
        .revealedClipdata = 0
    },
    [behavior_to_tank(CLIP_BEHAVIOR_POWER_BOMB_TANK)] = {
        .itemType = ITEM_TYPE_POWER_BOMB,
        .underwater = FALSE,
        .messageID = MESSAGE_POWER_BOMB_TANK_ACQUIRED,
        .revealedClipdata = 0
    },
    [behavior_to_tank(CLIP_BEHAVIOR_UNDERWATER_ENERGY_TANK)] = {
        .itemType = ITEM_TYPE_ENERGY,
        .underwater = TRUE,
        .messageID = MESSAGE_ENERGY_TANK_ACQUIRED,
        .revealedClipdata = 0
    },
    [behavior_to_tank(CLIP_BEHAVIOR_UNDERWATER_MISSILE_TANK)] = {
        .itemType = ITEM_TYPE_MISSILE,
        .underwater = TRUE,
        .messageID = MESSAGE_MISSILE_TANK_ACQUIRED,
        .revealedClipdata = 0
    },
    [behavior_to_tank(CLIP_BEHAVIOR_UNDERWATER_SUPER_MISSILE_TANK)] = {
        .itemType = ITEM_TYPE_SUPER_MISSILE,
        .underwater = TRUE,
        .messageID = MESSAGE_SUPER_MISSILE_TANK_ACQUIRED,
        .revealedClipdata = 0
    },
    [behavior_to_tank(CLIP_BEHAVIOR_UNDERWATER_POWER_BOMB_TANK)] = {
        .itemType = ITEM_TYPE_POWER_BOMB,
        .underwater = TRUE,
        .messageID = MESSAGE_POWER_BOMB_TANK_ACQUIRED,
        .revealedClipdata = 0
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
        CAA_DAMAGE_TYPE_MISSILE | CAA_DAMAGE_TYPE_SUPER_MISSILE,
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
    [behavior_to_bldalpha(CLIP_BEHAVIOR_BG0_TRIGGER_OPAQUE)] = 0x10,
    [behavior_to_bldalpha(CLIP_BEHAVIOR_BG0_TRIGGER_TRANSPARENT_LEVEL1)] = 0x30D,
    [behavior_to_bldalpha(CLIP_BEHAVIOR_BG0_TRIGGER_TRANSPARENT_LEVEL2)] = 0x60A,
    [behavior_to_bldalpha(CLIP_BEHAVIOR_BG0_TRIGGER_TRANSPARENT_LEVEL3)] = 0x907,
    [behavior_to_bldalpha(CLIP_BEHAVIOR_BG0_TRIGGER_TRANSPARENT_LEVEL4)] = 0xB05,
    [behavior_to_bldalpha(CLIP_BEHAVIOR_BG0_TRIGGER_TRANSPARENT_LEVEL5)] = 0xD03,
    [behavior_to_bldalpha(CLIP_BEHAVIOR_BG0_TRIGGER_TRANSPARENT_FULL)] = 0x1000,
    [behavior_to_bldalpha(CLIP_BEHAVIOR_BG0_TRIGGER_BRIGHTER_LEVEL1)] = 0x1007,
    [behavior_to_bldalpha(CLIP_BEHAVIOR_BG0_TRIGGER_BRIGHTER_LEVEL2)] = 0x100A,
    [behavior_to_bldalpha(CLIP_BEHAVIOR_BG0_TRIGGER_BRIGHTER_LEVEL3)] = 0x100D,
    [behavior_to_bldalpha(CLIP_BEHAVIOR_BG0_TRIGGER_BRIGHTER_LEVEL4)] = 0x1010,
};

const i8 sSubBombChainPositionOffset[4][2][2] = {
    {
        { 1, 1 },
        { -1, 1 }
    },
    {
        { 1, -1 },
        { -1, -1 },
    },
    {
        { 1, -1 },
        { 1, 1 },
    },
    {
        { -1, -1 },
        { -1, 1 },
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


u32 BlockCheckCCAA(struct ClipdataBlockData* pClipBlock)
{

}

u8 BlockDestroyNonReformBlock(struct ClipdataBlockData* pClipBlock)
{

}

u8 BlockDestroyBombChainBlock(struct ClipdataBlockData* pClipBlock)
{

}

u8 BlockDestroySingleBreakableBlock(struct ClipdataBlockData* pClipBlock)
{

}

u8 BlockDestroySquareBlock(struct ClipdataBlockData* pClipBlock)
{

}

u8 BlockStoreSingleNeverReformBlock(u16 xPosition, u16 yPosition)
{

}

void BlockRemoveNeverReformBlocks(void)
{

}

void BlockRemoveNeverReformSingleBlock(u16 xPosition, u16 yPosition)
{

}

void BlockShiftNeverReformBlocks(void)
{

}

u8 BlockCheckRevealOrDestroyNonBombBlock(struct ClipdataBlockData* pClipBlock)
{

}

u8 BlockCheckRevealOrDestroyBombBlock(struct ClipdataBlockData* pClipBlock)
{

}

/**
 * @brief 5987c | 164 | Applies the CCAA (Current Clipdata Affecting Action)
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param trueClip True clipdata block value
 * @return u32 1 if a block changed, 0 otherwise
 */
u32 BlockApplyCCAA(u16 yPosition, u16 xPosition, u16 trueClip)
{
    struct ClipdataBlockData clipBlock;
    u32 result;

    // Create clipdata block data structure
    clipBlock.xPosition = xPosition;
    clipBlock.yPosition = yPosition;
    clipBlock.behavior = gTilemapAndClipPointers.pClipBehaviors[trueClip];
    clipBlock.blockBehavior = 0x0;

    result = FALSE;

    switch (gCurrentClipdataAffectingAction)
    {
        case CAA_BEAM:
        case CAA_BOMB_PISTOL:
        case CAA_MISSILE:
        case CAA_SUPER_MISSILE:
        case CAA_POWER_BOMB:
            // Check on hatch
            if (gTilemapAndClipPointers.pClipCollisions[trueClip] == CLIPDATA_TYPE_DOOR &&
                BGClipCheckOpeningHatch(clipBlock.xPosition, clipBlock.yPosition) != 0x0)
                result = TRUE;
            else
            {
                // Check on block
                if (BlockCheckCCAA(&clipBlock))
                    result = TRUE;
            }
            break;

        case CAA_SPEEDBOOSTER:
        case CAA_SPEEDBOOSTER_ON_GROUND:
            if (BlockCheckCCAA(&clipBlock))
            {
                SoundPlayNotAlreadyPlaying(0x135);
                result = TRUE;
            }
            break;

        case CAA_SCREW_ATTACK:
            if (BlockCheckCCAA(&clipBlock))
            {
                SoundPlayNotAlreadyPlaying(0x139);
                result = TRUE;
            }
            break;

        case CAA_BOMB_CHAIN:
        case CAA_BOMB_CHAIN_UNUSED:
            if (BlockCheckCCAA(&clipBlock))
                result = TRUE;
            break;

        case CAA_REMOVE_SOLID:
            if (!BlockUpdateMakeSolidBlocks(FALSE, xPosition, yPosition))
                BGClipSetBG1BlockValue(0x0, yPosition, xPosition);

            BGClipSetClipdataBlockValue(0x0, yPosition, xPosition);
            break;

        case CAA_MAKE_SOLID_GRIPPABLE:
            result = BlockUpdateMakeSolidBlocks(TRUE, xPosition, yPosition);
            if (result)
                BGClipSetClipdataBlockValue(0x43E, yPosition, xPosition);
            break;

        case CAA_MAKE_SOLID2:
            result = BlockUpdateMakeSolidBlocks(TRUE, xPosition, yPosition);
            if (result)
                BGClipSetClipdataBlockValue(0x43D, yPosition, xPosition);
            break;

        case CAA_MAKE_SOLID3:
            result = BlockUpdateMakeSolidBlocks(TRUE, xPosition, yPosition);
            if (result)
                BGClipSetClipdataBlockValue(0x43F, yPosition, xPosition);
            break;
    }

    return result;
}

/**
 * @brief 599e0 | b8 | Updates the "make solid blocks" array
 * 
 * @param makeSolid Make solid flag
 * @param xPosition X Position
 * @param yPosition Y Position
 * @return u32 1 if could store, 0 otherwise
 */
u32 BlockUpdateMakeSolidBlocks(u8 makeSolid, u16 xPosition, u16 yPosition)
{
    u32 result;
    i32 i;
    u16* pBlocks;

    result = FALSE;

    if (!makeSolid)
    {
        // Remove solid
        pBlocks = gMakeSolidBlocks;
        for (i = MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS; i > 0x0; i--)
        {
            if (pBlocks[--i] == (xPosition << 8 | yPosition))
            {
                // Found in the array, remove
                pBlocks[i] = 0x0;
                result = TRUE;
                break;
            }
        }
    }
    else
    {
        // Make solid
        pBlocks = gMakeSolidBlocks;
        for (i = MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS; i > 0x0; i--)
        {
            if (pBlocks[--i] == (xPosition << 8 | yPosition))
            {
                // Already in the array
                i = 0xFF;
                break;
            }
            else if (pBlocks[i] == 0x0)
                break; // Found empty space
        }

        result = FALSE;
        if (i != 0xFF)
        {
            if (gBGPointersAndDimensions.pClipDecomp[gBGPointersAndDimensions.clipdataWidth * yPosition + xPosition] == 0x0)
            {
                // Store if no block
                pBlocks[i] = (xPosition << 8 | yPosition);
                result = TRUE;
            }
        }
    }

    return result;
}

/**
 * @brief 59a9c | b8 | Applies the speedbooster/screw attack destructing action
 * 
 * @param xPosition X Position
 * @param yPosition Y Position
 * @param action Destructing action
 * @return u32 1 if destroyed, 0
 */
u32 BlockSamusApplyScrewSpeedboosterDamageToEnvironment(u16 xPosition, u16 yPosition, u16 action)
{
    u16 blockY;
    u16 blockX;
    u16 clipdata;
    u16 result;
    u16 position;

    blockX = xPosition >> 6;
    blockY = yPosition >> 6;

    if (blockX < gBGPointersAndDimensions.clipdataWidth && blockY < gBGPointersAndDimensions.clipdataHeight)
    {
        // Set CCAA
        if (action == DESTRUCTING_ACTION_SPEED)
            gCurrentClipdataAffectingAction = CAA_SPEEDBOOSTER;
        else if (action == DESTRUCTING_ACTION_SCREW)
            gCurrentClipdataAffectingAction = CAA_SCREW_ATTACK;
        else if (action == DESTRUCTING_ACTION_SPEED_SCREW)
            gCurrentClipdataAffectingAction = CAA_SCREW_ATTACK;
        else if (action == DESTRUCTING_ACTION_SPEED_ON_GROUND)
            gCurrentClipdataAffectingAction = CAA_SPEEDBOOSTER_ON_GROUND;
        else
            return FALSE;

        // Get clipdata block
        position = gBGPointersAndDimensions.clipdataWidth * blockY + blockX;
        clipdata = gBGPointersAndDimensions.pClipDecomp[position];
        if (clipdata != 0x0)
        {
            // Apply first
            result = BlockApplyCCAA(blockY, blockX, clipdata);

            if (!result && action == DESTRUCTING_ACTION_SPEED_SCREW)
            {
                // Apply second
                gCurrentClipdataAffectingAction = CAA_SPEEDBOOSTER;
                BlockApplyCCAA(blockY, blockX, clipdata);
            }
        }
    }
    else
        return FALSE;

    // Clear CCAA
    gCurrentClipdataAffectingAction = CAA_NONE;
    
    return result;
}

void BlockUpdateBrokenBlocks(void)
{

}

void BlockUpdateBrokenBlockAnimation(struct BrokenBlock* pBlock)
{

}

/**
 * @brief 59da8 | ac | Stores a new broken block (that reforms)
 * 
 * @param type Block type
 * @param xPosition X Position
 * @param yPosition Y Position
 * @param advanceStage Starts the block at stage 2 if true
 * @return u32 1 if could store, 0 otherwise
 */
u32 BlockStoreBrokenReformBlock(u8 type, u16 xPosition, u16 yPosition, u8 advanceStage)
{
    u32 result;
    i32 i;
    struct BrokenBlock* pBlock;

    result = FALSE;
    pBlock = gBrokenBlocks;
    for (i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS;)
    {
        if (pBlock->xPosition == xPosition && pBlock->yPosition == yPosition)
        {
            // Already in array
            if (pBlock->stage == 0x0)
                result = TRUE;
            else
                result = FALSE;
            break;
        }
        else
        {
            // Check save empty offset
            if (!(result & 0x80) && pBlock->stage == 0x0)
                result = i | 0x80; // Store empty offset
        }

        i++;
        pBlock++;
    }

    // Empty space was found
    if (result)
    {
        // Get offset
        if (result != TRUE)
            i = result & 0x7F;

        pBlock = gBrokenBlocks + i;

        // Store block
        pBlock->broken = TRUE;
        pBlock->type = type;
        pBlock->timer = 0x0;

        if (result & 0x80)
        {
            pBlock->xPosition = xPosition;
            pBlock->yPosition = yPosition;
        }

        if (!advanceStage)
        {
            pBlock->stage = 0x2;
            BlockBrokenBlockRemoveCollision(yPosition, xPosition);
            BlockUpdateBrokenBlockAnimation(pBlock);
        }
        else
            pBlock->stage = 0x1;

        result = TRUE;
    }

    return result;
}

u8 BlockStoreBrokenNonReformBlock(u16 xPosition, u16 yPosition, u8 type)
{

}

u8 BlockCheckRevealBombChainBlock(u8 type, u16 xPosition, u16 yPosition)
{

}

/**
 * @brief 59f70 | 70 | Checks if Samus is in a reforming block
 * 
 * @param xPosition X Position
 * @param yPosition Y Position
 * @return u32 1 if in block, 0 otherwise
 */
u32 BlockCheckSamusInReformingBlock(u8 xPosition, u8 yPosition)
{
    u8 inX;
    u8 inY;
    u8 inBlock;

    // Check in X
    inX = FALSE;
    if ((gSamusData.xPosition + gSamusPhysics.drawDistanceLeftOffset) >> 6 <= xPosition &&
        xPosition <= (gSamusData.xPosition + gSamusPhysics.drawDistanceRightOffset) >> 6)
        inX = TRUE;

    // Check in Y
    inY = FALSE;
    if ((gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset) >> 6 <= yPosition &&
        yPosition <= (gSamusData.yPosition + gSamusPhysics.drawDistanceBottomOffset) >> 6)
        inY = TRUE;

    inBlock = FALSE;
    if (inX)
        inBlock = inY;
        
    return inBlock;
}

u8 BlockStartBombChain(u8 type, u16 xPosition, u16 yPosition)
{

}

void BlockProcessBombChains(void)
{

}

void BlockCheckStartNewSubBombChain(u8 type, u8 xPosition, u8 yPosition)
{

}

void BlockBrokenBlockRemoveCollision(u16 yPosition, u16 xPosition)
{

}