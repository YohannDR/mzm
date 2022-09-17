#include "../block.h"
#include "../clipdata.h"
#include "../connection.h"
#include "../globals.h"
#include "../samus.h"
#include "../types.h"
#include "../sprites_AI/item_banner.h"

static const struct TankList sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS + 1] = {
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
    [MAX_AMOUNT_OF_AREAS] = {
        .energy = 18,
        .missile = 50,
        .superMissile = 15,
        .powerBomb = 9
    }
};

static const struct TankList sStartingHealthAmmo = {
    .energy = 99,
    .missile = 0,
    .superMissile = 0,
    .powerBomb = 0,
};

static const struct TankList sTankIncreaseAmount[MAX_AMOUNT_OF_DIFFICULTIES] = {
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

static const u16 sClipdataAffectingActionDamageTypes[MAX_AMOUNT_OF_CAA] = {
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

static const struct BlockBehavior sBlockBehaviors[MAX_AMOUNT_OF_BLOCKS] = {
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

static const u16 sBlockWeaknesses[MAX_AMOUNT_OF_BLOCKS_TYPES] = {
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

static const u16 sReformingBlocksTilemapValue[MAX_AMOUNT_OF_BLOCKS_TYPES] = {
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

static const u8 sBrokenBlocksTimers[MAX_AMOUNT_OF_BLOCKS_TYPES][13] = {
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

static const struct BombChainReverseData sBombChainReverseData[8] = {
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

static const struct TankBehavior sTankBehaviors[MAX_AMOUNT_OF_TANK_TYPES] = {
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

static const u16 sHatchBehaviors[MAX_AMOUNT_OF_HATCH_TYPES][2] = {
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

static const u16 sBldalphaValuesForClipdata[11] = {
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

static const i8 sSubBombChainPositionOffset[4][4] = {
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

static const u8 sHatchRelated_345cee[4][2] = {
    { 0, 0 },
    { 0, 1 },
    { 1, 2 },
    { 2, 2 },
};

static const u16 sMotherBrainGlassBreakingBaseTilemapValues[5] = {
    0x170, 0x177, 0x1C0, 0x1C7, 0x210
};