#ifndef SPRITE_DATA_H
#define SPRITE_DATA_H

#include "types.h"
#include "constants/sprite.h"

#define SPRITESET_EMPTY 0, 0

// 2b0c94

static const u8 sOamXFlipOffsets[3][4] = {
    { 1, 2, 4, 8 },
    { 2, 4, 4, 8 },
    { 1, 1, 2, 4 }
};

static const u8 sOamYFlipOffsets[3][4] = {
    { 1, 2, 4, 8 },
    { 1, 1, 2, 4 },
    { 2, 4, 4, 8 }
};

static const u8 sSpriteRandomNumberTable[56] = {
    13, 2, 6, 8, 7, 9, 14, 10, 2, 4, 14, 4, 12,
    15, 13, 12, 11, 1, 3, 15, 0, 6, 7, 8, 11, 5,
    0, 3, 5, 1, 9, 10, 10, 0, 3, 0, 1, 0, 10, 0,
    6, 0, 3, 0, 10, 0, 8, 0, 1, 0, 10, 0, 9, 0, 8, 0
};

static const i16 sSpritesFallingCeilingSpeed[16] = {
    -4, -4, -4, -4, -4, -4, -8, -8, -8, -12,
    -12, -12, -12, -12, -16, SHORT_MAX
};

static const i16 sSpritesFallingSpeed[16] = {
    4, 4, 4, 4, 8, 8, 8, 8, 12, 12, 12,
    16, 16, 16, 20, SHORT_MAX
};

static const i16 sSpritesFallingSpeed_Unused[8] = {
    4, 6, 8, 10, 12,
    14, 16, SHORT_MAX,
};

static const i16 sSpritesFallingSpeed_Unused2[16] = {
    1, 1, 2, 2, 3, 3, 4, 4, 5, 5,
    6, 6, 7, 7, 8, SHORT_MAX
};

static const i16 sWorkerRobotSleepingFallingSpeed[10] = {
    4, 8, 8, 12, 12, 16, 16, 20, 24, SHORT_MAX
};

/**
 * @brief Stats of the primary sprites
 * 0 : Spawn health
 * 1 : Damage
 * 2 : Weaknesses
 * 3 : No drop probability
 * 4 : Small health drop probability
 * 5 : Large health drop probability
 * 6 : Missile drop probability
 * 7 : Super missile drop probability
 * 8 : Power bomb drop probability
 */
static const u16 sPrimarySpriteStats[206][9] = {
    [PSPRITE_UNUSED0] = {
        0,
        0,
        WEAKNESS_NONE,
        0,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_UNUSED1] = {
        0,
        0,
        WEAKNESS_NONE,
        0,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_UNUSED2] = {
        0,
        0,
        WEAKNESS_NONE,
        0,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_UNUSED3] = {
        0,
        0,
        WEAKNESS_NONE,
        0,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_UNUSED4] = {
        0,
        0,
        WEAKNESS_NONE,
        0,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_UNUSED5] = {
        0,
        0,
        WEAKNESS_NONE,
        0,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_UNUSED6] = {
        0,
        0,
        WEAKNESS_NONE,
        0,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_UNUSED7] = {
        0,
        0,
        WEAKNESS_NONE,
        0,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_UNUSED8] = {
        0,
        0,
        WEAKNESS_NONE,
        0,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_UNUSED9] = {
        0,
        0,
        WEAKNESS_NONE,
        0,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_UNUSED10] = {
        0,
        0,
        WEAKNESS_NONE,
        0,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_UNUSED11] = {
        0,
        0,
        WEAKNESS_NONE,
        0,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_UNUSED12] = {
        0,
        0,
        WEAKNESS_NONE,
        0,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_UNUSED13] = {
        0,
        0,
        WEAKNESS_NONE,
        0,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_UNUSED14] = {
        0,
        0,
        WEAKNESS_NONE,
        0,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_UNUSED15] = {
        0,
        0,
        WEAKNESS_NONE,
        0,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_UNUSED16] = {
        0,
        0,
        WEAKNESS_NONE,
        0,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_ITEM_BANNER] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_ZOOMER_YELLOW] = {
        3,
        10,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        380,
        300,
        20,
        224,
        50,
        50
    },
    [PSPRITE_ZOOMER_RED] = {
        8,
        20,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        644,
        30,
        150,
        100,
        50,
        50
    },
    [PSPRITE_ZEELA] = {
        6,
        10,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        754,
        120,
        30,
        80,
        20,
        20
    },
    [PSPRITE_ZEELA_RED] = {
        12,
        20,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        764,
        20,
        120,
        80,
        20,
        20
    },
    [PSPRITE_RIPPER_BROWN] = {
        20,
        10,
        WEAKNESS_SUPER_MISSILES | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        374,
        50,
        80,
        400,
        80,
        40
    },
    [PSPRITE_RIPPER_PURPLE] = {
        40,
        20,
        WEAKNESS_SUPER_MISSILES | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        134,
        50,
        200,
        300,
        300,
        40
    },
    [PSPRITE_ZEB] = {
        2,
        6,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        64,
        500,
        80,
        250,
        80,
        50
    },
    [PSPRITE_ZEB_BLUE] = {
        6,
        9,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_LARGE_ENERGY_DROP] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SMALL_ENERGY_DROP] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_MISSILE_DROP] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SUPER_MISSILE_DROP] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_POWER_BOMB_DROP] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SKREE_GREEN] = {
        3,
        10,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        714,
        100,
        50,
        100,
        30,
        30
    },
    [PSPRITE_SKREE_BLUE] = {
        8,
        20,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        224,
        300,
        150,
        150,
        100,
        100
    },
    [PSPRITE_MORPH_BALL] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CHOZO_STATUE_LONG_HINT] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CHOZO_STATUE_LONG] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CHOZO_STATUE_ICE_HINT] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CHOZO_STATUE_ICE] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CHOZO_STATUE_WAVE_HINT] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CHOZO_STATUE_WAVE] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CHOZO_STATUE_BOMB_HINT] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CHOZO_STATUE_BOMB] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CHOZO_STATUE_SPEEDBOOSTER_HINT] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CHOZO_STATUE_SPEEDBOOSTER] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CHOZO_STATUE_HIGH_JUMP_HINT] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CHOZO_STATUE_HIGH_JUMP] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CHOZO_STATUE_SCREW_HINT] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CHOZO_STATUE_SCREW] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CHOZO_STATUE_VARIA_HINT] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CHOZO_STATUE_VARIA] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SOVA_PURPLE] = {
        4,
        12,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        664,
        200,
        0,
        100,
        30,
        30
    },
    [PSPRITE_SOVA_ORANGE] = {
        12,
        22,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        264,
        400,
        50,
        200,
        60,
        50
    },
    [PSPRITE_MULTIVIOLA] = {
        12,
        18,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        494,
        300,
        50,
        100,
        50,
        30
    },
    [PSPRITE_MULTIPLE_LARGE_ENERGY] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_GERUTA_RED] = {
        10,
        16,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        494,
        200,
        0,
        200,
        100,
        30
    },
    [PSPRITE_GERUTA_GREEN] = {
        40,
        30,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        0,
        0,
        200,
        444,
        280,
        100
    },
    [PSPRITE_SQUEEPT] = {
        8,
        16,
        WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        0,
        0,
        0,
        924,
        50,
        50
    },
    [PSPRITE_SQUEEPT_UNUSED] = {
        8,
        16,
        WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        0,
        0,
        0,
        924,
        50,
        50
    },
    [PSPRITE_MAP_STATION] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_DRAGON] = {
        18,
        18,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        254,
        500,
        100,
        100,
        40,
        30
    },
    [PSPRITE_DRAGON_UNUSED] = {
        18,
        18,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        254,
        500,
        100,
        100,
        40,
        30
    },
    [PSPRITE_ZIPLINE] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_ZIPLINE_BUTTON] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_REO_GREEN_WINGS] = {
        16,
        12,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        524,
        200,
        100,
        100,
        50,
        50
    },
    [PSPRITE_REO_PURPLE_WINGS] = {
        20,
        12,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        374,
        50,
        250,
        250,
        50,
        50
    },
    [PSPRITE_GUNSHIP] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_DEOREM] = {
        1,
        12,
        WEAKNESS_NONE,
        24,
        300,
        0,
        700,
        0,
        0
    },
    [PSPRITE_DEOREM_SECOND_LOCATION] = {
        1,
        12,
        WEAKNESS_NONE,
        24,
        300,
        0,
        700,
        0,
        0
    },
    [PSPRITE_CHARGE_BEAM] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SKULTERA] = {
        20,
        30,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        0,
        100,
        412,
        512,
        0,
        0
    },
    [PSPRITE_DESSGEEGA] = {
        30,
        30,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        174,
        300,
        200,
        150,
        150,
        50
    },
    [PSPRITE_DESSGEEGA_AFTER_LONG_BEAM] = {
        40,
        24,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        174,
        300,
        200,
        150,
        150,
        50
    },
    [PSPRITE_WAVER] = {
        8,
        12,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        794,
        100,
        40,
        50,
        20,
        20
    },
    [PSPRITE_WAVER_UNUSED] = {
        8,
        12,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        794,
        100,
        40,
        50,
        20,
        20
    },
    [PSPRITE_MELLOW] = {
        3,
        5,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_HIVE] = {
        64,
        14,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        0,
        0,
        1024,
        0,
        0,
        0
    },
    [PSPRITE_POWER_GRIP] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_IMAGO_LARVA_RIGHT] = {
        30,
        20,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        0,
        0,
        600,
        424,
        0,
        0
    },
    [PSPRITE_MORPH_BALL_LAUNCHER] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_IMAGO_COCOON] = {
        1,
        30,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_ELEVATOR_PAD] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SPACE_PIRATE] = {
        30,
        100,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SPACE_PIRATE_WAITING1] = {
        30,
        100,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SPACE_PIRATE_WAITING2] = {
        30,
        100,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SPACE_PIRATE_WAITING3] = {
        30,
        100,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SPACE_PIRATE2] = {
        30,
        100,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_GAMET_BLUE_SINGLE] = {
        4,
        8,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        214,
        400,
        150,
        200,
        30,
        30
    },
    [PSPRITE_GAMET_RED_SINGLE] = {
        13,
        16,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        0,
        250,
        400,
        250,
        64,
        60
    },
    [PSPRITE_CHOZO_STATUE_GRAVITY] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CHOZO_STATUE_SPACE_JUMP] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SECURITY_GATE_DEFAULT_OPEN] = {
        1,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_ZEBBO_GREEN] = {
        6,
        10,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        94,
        400,
        200,
        200,
        100,
        30
    },
    [PSPRITE_ZEBBO_YELLOW] = {
        14,
        18,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        0,
        100,
        400,
        314,
        150,
        60
    },
    [PSPRITE_WORKER_ROBOT] = {
        1,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_PARASITE_MULTIPLE] = {
        1,
        1,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_PARASITE] = {
        1,
        1,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_PISTON] = {
        256,
        0,
        WEAKNESS_BEAM_BOMBS,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_RIDLEY] = {
        1000,
        30,
        WEAKNESS_CHARGE_BEAM_PISTOL | WEAKNESS_MISSILES,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SECURITY_GATE_DEFAULT_CLOSED] = {
        1,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_ZIPLINE_GENERATOR] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_METROID] = {
        100,
        1,
        WEAKNESS_CAN_BE_FROZEN,
        0,
        0,
        400,
        500,
        124,
        0
    },
    [PSPRITE_FROZEN_METROID] = {
        100,
        1,
        WEAKNESS_MISSILES | WEAKNESS_CAN_BE_FROZEN,
        0,
        0,
        400,
        500,
        124,
        0
    },
    [PSPRITE_RINKA_ORANGE] = {
        7,
        10,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        604,
        10,
        50,
        350,
        10,
        0
    },
    [PSPRITE_POLYP] = {
        20,
        0,
        WEAKNESS_MISSILES | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        0,
        0,
        0,
        1024,
        0,
        0
    },
    [PSPRITE_VIOLA_BLUE] = {
        12,
        16,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        524,
        200,
        20,
        200,
        50,
        30
    },
    [PSPRITE_VIOLA_ORANGE] = {
        20,
        30,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        274,
        300,
        100,
        200,
        100,
        50
    },
    [PSPRITE_GERON_NORFAIR] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_HOLTZ] = {
        30,
        40,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        0,
        0,
        0,
        200,
        774,
        50
    },
    [PSPRITE_GEKITAI_MACHINE] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_RUINS_TEST] = {
        100,
        50,
        WEAKNESS_BEAM_BOMBS,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SAVE_PLATFORM] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_KRAID] = {
        300,
        20,
        WEAKNESS_NONE,
        0,
        0,
        1024,
        0,
        0,
        0
    },
    [PSPRITE_IMAGO_COCOON_AFTER_FIGHT] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_RIPPERII] = {
        30,
        30,
        WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        0,
        100,
        200,
        374,
        300,
        50
    },
    [PSPRITE_MELLA] = {
        3,
        6,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        729,
        200,
        0,
        80,
        10,
        5
    },
    [PSPRITE_ATOMIC] = {
        40,
        30,
        WEAKNESS_MISSILES | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        0,
        0,
        1024,
        0,
        0,
        0
    },
    [PSPRITE_AREA_BANNER] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_MOTHER_BRAIN] = {
        700,
        20,
        WEAKNESS_MISSILES,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_FAKE_POWER_BOMB_EVENT_TRIGGER] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_ACID_WORM] = {
        600,
        10,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        0,
        0,
        500,
        524,
        0,
        0
    },
    [PSPRITE_ESCAPE_SHIP] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SIDEHOPPER] = {
        30,
        20,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        574,
        100,
        200,
        100,
        50,
        0
    },
    [PSPRITE_GEEGA] = {
        4,
        8,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        124,
        500,
        100,
        300,
        0,
        0
    },
    [PSPRITE_GEEGA_WHITE] = {
        10,
        16,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        24,
        300,
        400,
        300,
        0,
        0
    },
    [PSPRITE_RINKA_MOTHER_BRAIN] = {
        7,
        10,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        364,
        0,
        50,
        600,
        10,
        0
    },
    [PSPRITE_ZEBETITE_ONE_AND_THREE] = {
        140,
        0,
        WEAKNESS_MISSILES,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CANNON] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_IMAGO_LARVA_RIGHT_SIDE] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_TANGLE_VINE_TALL] = {
        18,
        20,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        124,
        200,
        100,
        600,
        0,
        0
    },
    [PSPRITE_TANGLE_VINE_MEDIUM] = {
        12,
        15,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        374,
        200,
        50,
        400,
        0,
        0
    },
    [PSPRITE_TANGLE_VINE_CURVED] = {
        6,
        10,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        424,
        250,
        50,
        300,
        0,
        0
    },
    [PSPRITE_TANGLE_VINE_SHORT] = {
        3,
        6,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        474,
        300,
        50,
        200,
        0,
        0
    },
    [PSPRITE_MELLOW_SWARM] = {
        3,
        5,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_MELLOW_SWARM_HEALTH_BASED] = {
        3,
        5,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_IMAGO] = {
        750,
        10,
        WEAKNESS_CHARGE_BEAM_PISTOL | WEAKNESS_MISSILES,
        0,
        0,
        512,
        512,
        0,
        0
    },
    [PSPRITE_ZEBETITE_TWO_AND_FOUR] = {
        140,
        0,
        WEAKNESS_MISSILES,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CANNON2] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CANNON3] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_CROCOMIRE] = {
        100,
        10,
        WEAKNESS_CHARGE_BEAM_PISTOL | WEAKNESS_MISSILES,
        0,
        0,
        512,
        512,
        0,
        0
    },
    [PSPRITE_IMAGO_LARVA_LEFT] = {
        30,
        20,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        0,
        0,
        600,
        424,
        0,
        0
    },
    [PSPRITE_GERON_BRINSTAR_ROOM_15] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_GERON_BRINSTAR_ROOM_1C] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_GERON_VARIA1] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_GERON_VARIA2] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_GERON_VARIA3] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_GLASS_TUBE] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SAVE_PLATFORM_CHOZODIA] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_BARISTUTE] = {
        200,
        58,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        0,
        0,
        100,
        454,
        370,
        100
    },
    [PSPRITE_CHOZO_STATUE_PLASMA_BEAM] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_KRAID_ELEVATOR_STATUE] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_RIDLEY_ELEVATOR_STATUE] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_RISING_CHOZO_PILLAR] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SECURITY_LASER_VERTICAL] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SECURITY_LASER_HORIZONTAL] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SECURITY_LASER_VERTICAL2] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SECURITY_LASER_HORIZONTAL2] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_LOCK_UNLOCK_METROID_DOORS_UNUSED] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_GAMET_BLUE_LEADER] = {
        4,
        8,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        0,
        24,
        450,
        400,
        100,
        50
    },
    [PSPRITE_GAMET_BLUE_FOLLOWER] = {
        4,
        8,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        0,
        24,
        450,
        400,
        100,
        50
    },
    [PSPRITE_GEEGA_LEADER] = {
        4,
        8,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        0,
        24,
        450,
        400,
        100,
        50
    },
    [PSPRITE_GEEGA_FOLLOWER] = {
        4,
        8,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        0,
        24,
        450,
        400,
        100,
        50
    },
    [PSPRITE_ZEBBO_GREEN_LEADER] = {
        6,
        10,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        0,
        24,
        450,
        400,
        100,
        50
    },
    [PSPRITE_ZEBBO_GREEN_FOLLOWER] = {
        6,
        10,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        0,
        24,
        450,
        400,
        100,
        50
    },
    [PSPRITE_KRAID_STATUE] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_RIDLEY_STATUE] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_RINKA_GREEN] = {
        7,
        20,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        0,
        0,
        350,
        574,
        100,
        0
    },
    [PSPRITE_SEARCHLIGHT_EYE] = {
        1,
        0,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SEARCHLIGHT_EYE2] = {
        1,
        0,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_STEAM_LARGE] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_STEAM_SMALL] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_PLASMA_BEAM_BLOCK] = {
        1,
        0,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_GRAVITY_SUIT_BLOCK] = {
        1,
        0,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SPACE_JUMP_BLOCK] = {
        1,
        0,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_GADORA_KRAID] = {
        1,
        25,
        WEAKNESS_NONE,
        0,
        0,
        512,
        512,
        0,
        0
    },
    [PSPRITE_GADORA_RIDLEY] = {
        1,
        25,
        WEAKNESS_NONE,
        0,
        0,
        512,
        512,
        0,
        0
    },
    [PSPRITE_SEARCHLIGHT] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SEARCHLIGHT2] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SEARCHLIGHT3] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SEARCHLIGHT4] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_MAYBE_SEARCHLIGHT_TRIGGER] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_DISCOVERED_IMAGO_PASSAGE_EVENT_TRIGGER] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_FAKE_POWER_BOMB] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_SPACE_PIRATE_CARRYING_POWER_BOMB] = {
        30,
        100,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_TANGLE_VINE_RED_GARUTA] = {
        24,
        25,
        WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        0,
        0,
        0,
        1024,
        0,
        0
    },
    [PSPRITE_TANGLE_VINE_GERUTA] = {
        18,
        20,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        124,
        200,
        100,
        600,
        0,
        0
    },
    [PSPRITE_TANGLE_VINE_LARVA_RIGHT] = {
        24,
        25,
        WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        0,
        0,
        0,
        1024,
        0,
        0
    },
    [PSPRITE_TANGLE_VINE_LARVA_LEFT] = {
        24,
        25,
        WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        0,
        0,
        0,
        1024,
        0,
        0
    },
    [PSPRITE_WATER_DROP] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_FALLING_CHOZO_PILLAR] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_MECHA_RIDLEY] = {
        360,
        0,
        WEAKNESS_MISSILES,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_EXPLOSION_ZEBES_ESCAPE] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_STEAM_LARGE_DIAGONAL_UP] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_STEAM_SMALL_DIAGONAL_UP] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_STEAM_LARGE_DIAGONAL_DOWN] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_STEAM_SMALL_DIAGONAL_DOWN] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_BARISTUTE_KRAID_UPPER] = {
        200,
        58,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        0,
        0,
        100,
        454,
        370,
        100
    },
    [PSPRITE_ESCAPE_GATE1] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_ESCAPE_GATE2] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_BLACK_SPACE_PIRATE] = {
        72,
        50,
        WEAKNESS_BEAM_BOMBS,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_ESCAPE_SHIP_SPACE_PIRATE] = {
        30,
        100,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [PSPRITE_BARISTUTE_KRAID_LOWER] = {
        200,
        58,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        0,
        0,
        100,
        454,
        370,
        100
    },
    [PSPRITE_RINKA_MOTHER_BRAIN2] = {
        7,
        10,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        364,
        0,
        50,
        600,
        10,
        0
    },
    [PSPRITE_RINKA_MOTHER_BRAIN3] = {
        7,
        10,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        364,
        0,
        50,
        600,
        10,
        0
    },
    [PSPRITE_RINKA_MOTHER_BRAIN4] = {
        7,
        10,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        364,
        0,
        50,
        600,
        10,
        0
    },
    [PSPRITE_RINKA_MOTHER_BRAIN5] = {
        7,
        10,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        364,
        0,
        50,
        600,
        10,
        0
    },
    [PSPRITE_RINKA_MOTHER_BRAIN6] = {
        7,
        10,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        364,
        0,
        50,
        600,
        10,
        0
    }
};

/**
 * @brief Stats of the secondary sprites
 * 0 : Spawn health
 * 1 : Damage
 * 2 : Weaknesses
 * 3 : No drop probability
 * 4 : Small health drop probability
 * 5 : Large health drop probability
 * 6 : Missile drop probability
 * 7 : Super missile drop probability
 * 8 : Power bomb drop probability
 */
static const u16 sSecondarySpriteStats[77][9] = {
    [SSPRITE_CHOZO_BALL] = {
        1,
        0,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_CHOZO_STATUE_PART] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_CHOZO_STATUE_REFILL] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_KRAID_PART] = {
        1000,
        20,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES,
        0,
        0,
        512,
        512,
        0,
        0
    },
    [SSPRITE_CHOZO_STATUE_MOVEMENT] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_CHARGE_BEAM_GLOW] = {
        1,
        0,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_WINGED_RIPPER] = {
        1,
        2,
        WEAKNESS_CAN_BE_FROZEN,
        0,
        0,
        1024,
        0,
        0,
        0
    },
    [SSPRITE_MULTIVIOLA_UNUSED] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_DRAGON_FIREBALL] = {
        1,
        8,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        424,
        300,
        100,
        200,
        0,
        0
    },
    [SSPRITE_DEOREM_SEGMENT] = {
        1,
        8,
        WEAKNESS_NONE,
        24,
        300,
        0,
        700,
        0,
        0
    },
    [SSPRITE_DEOREM_EYE] = {
        60,
        0,
        WEAKNESS_MISSILES,
        24,
        300,
        0,
        700,
        0,
        0
    },
    [SSPRITE_DEOREM_THORN] = {
        1,
        4,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        24,
        100,
        400,
        500,
        0,
        0
    },
    [SSPRITE_SKREE_EXPLOSION] = {
        0,
        2,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_SAVE_PLATFORM_PART] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_SAVE_YES_NO_CURSOR] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_BLUE_SKREE_EXPLOSION] = {
        0,
        4,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_ZEELA_EYES] = {
        0,
        3,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_HIVE_ROOTS] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_IMAGO_LARVA_PART] = {
        1000,
        20,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        0,
        0,
        500,
        524,
        0,
        0
    },
    [SSPRITE_MORPH_BALL_OUTSIDE] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_IMAGO_COCOON_VINE] = {
        50,
        30,
        WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_IMAGO_COCOON_SPORE] = {
        1,
        20,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        524,
        0,
        100,
        400,
        0,
        0
    },
    [SSPRITE_SPACE_PIRATE_LASER] = {
        0,
        100,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_RIDLEY_PART] = {
        0,
        30,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_RIDLEY_TAIL] = {
        1,
        50,
        WEAKNESS_NONE,
        0,
        0,
        500,
        324,
        200,
        0
    },
    [SSPRITE_SEARCHLIGHT_EYE_BEAM] = {
        0,
        100,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_METROID_SHELL] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_POLYP_PROJECTILE] = {
        1,
        8,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK | WEAKNESS_CAN_BE_FROZEN,
        889,
        100,
        5,
        20,
        5,
        5
    },
    [SSPRITE_KRAID_SPIKE] = {
        10,
        30,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_KRAID_NAIL] = {
        1,
        4,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        124,
        200,
        200,
        500,
        0,
        0
    },
    [SSPRITE_ZIPLINE_GENERATOR_PART] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_ATOMIC_ELECTRICITY] = {
        0,
        10,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_MOTHER_BRAIN_PART] = {
        400,
        0,
        WEAKNESS_MISSILES,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_RIDLEY_FIREBALL] = {
        1,
        15,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_UNKNOWN_ITEM_CHOZO_STATUE_PART] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_UNKNOWN_ITEM_CHOZO_STATUE_REFILL] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_MORPH_BALL_LAUNCHER_PART] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_ACID_WORM_BODY] = {
        1,
        10,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB,
        0,
        600,
        100,
        324,
        0,
        0
    },
    [SSPRITE_ACID_WORM_SPIT] = {
        1,
        10,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        100,
        400,
        224,
        300,
        0,
        0
    },
    [SSPRITE_CANNON_BULLET] = {
        0,
        10,
        WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_CROCOMIRE_PART] = {
        1,
        10,
        WEAKNESS_NONE,
        0,
        512,
        256,
        256,
        0,
        0
    },
    [SSPRITE_IMAGO_PART] = {
        1,
        50,
        WEAKNESS_NONE,
        0,
        0,
        250,
        774,
        0,
        0
    },
    [SSPRITE_DEFEATED_IMAGO_COCOON] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_IMAGO_CEILING_VINE] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_SEARCHLIGHT_EYE_BEAM2] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_TANGLE_VINE_GERUTA_PART] = {
        1,
        1,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_CHOZODIA_SAVE_PLATFORM_PART] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_IMAGO_NEEDLE] = {
        1,
        20,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        0,
        200,
        0,
        824,
        0,
        0
    },
    [SSPRITE_ELEVATOR_STATUE_DEBRIS] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_IMAGO_DAMAGED_STINGER] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_GUNSHIP_PART] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_IMAGO_EGG] = {
        1,
        0,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_MAP_STATION_PART] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_CHOZO_PILLAR_PLATFORM] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_GADORA_EYE] = {
        60,
        0,
        WEAKNESS_CHARGE_BEAM_PISTOL | WEAKNESS_MISSILES,
        0,
        0,
        512,
        512,
        0,
        0
    },
    [SSPRITE_GADORA_BEAM] = {
        1,
        30,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_UNKNOWN_ITEM_BLOCK_LIGHT] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_SEARCHLIGHT_EYE_PROJECTILE] = {
        0,
        16,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_CHOZO_PILLAR_PLATFORM_SHADOW] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_RUINS_TEST_SYMBOL] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_RUINS_TEST_SAMUS_REFLECTION_START] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_RUINS_TEST_REFLECTION_COVER] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_RUINS_TEST_GHOST_OUTLINE] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_RUINS_TEST_GHOST] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_RUINS_TEST_SHOOTABLE_SYMBOL] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_RUINS_TEST_SAMUS_REFLECTION_END] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_RUINS_TEST_LIGHTNING] = {
        0,
        50,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_RIDLEY_BIG_FIREBALL] = {
        1,
        30,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        0,
        50,
        100,
        840,
        34,
        0
    },
    [SSPRITE_MECHA_RIDLEY_PART] = {
        200,
        150,
        WEAKNESS_MISSILES,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_ESCAPE_SHIP_PART] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_POWER_GRIP_GLOW] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_MECHA_RIDLEY_LASER] = {
        0,
        50,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_MECHA_RIDLEY_MISSILE] = {
        10,
        80,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        274,
        0,
        300,
        400,
        50,
        0
    },
    [SSPRITE_MECHA_RIDLEY_FIREBALL] = {
        10,
        60,
        WEAKNESS_BEAM_BOMBS | WEAKNESS_MISSILES | WEAKNESS_POWER_BOMB | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK,
        0,
        0,
        0,
        1000,
        24,
        0
    },
    [SSPRITE_MOTHER_BRAIN_BEAM] = {
        1,
        50,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_MOTHER_BRAIN_BLOCK] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    },
    [SSPRITE_MOTHER_BRAIN_GLASS_BREAKING] = {
        0,
        0,
        WEAKNESS_NONE,
        1024,
        0,
        0,
        0,
        0,
        0
    }
};


static const u8 sSpriteset0[2] = {
    SPRITESET_EMPTY
};

static const u8 sSpriteset113[4] = {
    PSPRITE_BLACK_SPACE_PIRATE, 0,
    SPRITESET_EMPTY
};

static const u8 sSpriteset1[12] = {
    PSPRITE_ZOOMER_YELLOW, 0,
    PSPRITE_MORPH_BALL, 2,
    PSPRITE_ELEVATOR_PAD, 3,
    PSPRITE_MORPH_BALL_LAUNCHER, 4,
    PSPRITE_ZOOMER_RED, 0,
    SPRITESET_EMPTY
};

static const u8 sSpriteset2[10] = {
    PSPRITE_ZOOMER_YELLOW, 0,
    PSPRITE_ZOOMER_RED, 0,
    PSPRITE_SKREE_GREEN, 2,
    PSPRITE_PISTON, 3,
    SPRITESET_EMPTY
};

static const u8 sSpriteset3[18] = {
	PSPRITE_ZEELA, 0,
	PSPRITE_RIPPER_BROWN, 2,
	PSPRITE_ELEVATOR_PAD, 3,
	PSPRITE_SPACE_JUMP_BLOCK, 4,
	PSPRITE_ZEELA_RED, 0,
	PSPRITE_GEEGA_LEADER, 5,
	PSPRITE_GEEGA_FOLLOWER, 5,
	PSPRITE_GADORA_KRAID, 6,
	SPRITESET_EMPTY
};

static const u8 sSpriteset4[4] = {
	PSPRITE_CHOZO_STATUE_LONG, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset5[16] = {
	PSPRITE_ZEELA, 0,
	PSPRITE_RIPPER_BROWN, 2,
	PSPRITE_ELEVATOR_PAD, 3,
	PSPRITE_MORPH_BALL_LAUNCHER, 4,
	PSPRITE_ZEELA_RED, 0,
	PSPRITE_GEEGA_LEADER, 5,
	PSPRITE_GEEGA_FOLLOWER, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset6[6] = {
	PSPRITE_SKREE_GREEN, 0,
	PSPRITE_CHOZO_STATUE_LONG_HINT, 1,
	SPRITESET_EMPTY
};

static const u8 sSpriteset7[4] = {
	PSPRITE_KRAID, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset8[14] = {
	PSPRITE_ZOOMER_YELLOW, 0,
	PSPRITE_ZOOMER_RED, 0,
	PSPRITE_RIPPER_BROWN, 2,
	PSPRITE_SKREE_GREEN, 3,
	PSPRITE_MORPH_BALL_LAUNCHER, 4,
	PSPRITE_PARASITE, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset9[16] = {
	PSPRITE_REO_GREEN_WINGS, 0,
	PSPRITE_ZIPLINE, 1,
	PSPRITE_ZIPLINE_BUTTON, 1,
	PSPRITE_ZIPLINE_GENERATOR, 2,
	PSPRITE_GEEGA, 3,
	PSPRITE_REO_PURPLE_WINGS, 4,
	PSPRITE_SPACE_JUMP_BLOCK, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset10[6] = {
	PSPRITE_CHOZO_STATUE_BOMB_HINT, 0,
	PSPRITE_SKREE_GREEN, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset11[4] = {
	PSPRITE_CHOZO_STATUE_BOMB, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset12[4] = {
	PSPRITE_CHOZO_STATUE_ICE_HINT, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset13[6] = {
	PSPRITE_CHOZO_STATUE_ICE, 0,
	PSPRITE_RIPPER_PURPLE, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset14[6] = {
	PSPRITE_CHOZO_STATUE_SPEEDBOOSTER_HINT, 0,
	PSPRITE_SQUEEPT, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset15[4] = {
	PSPRITE_CHOZO_STATUE_SPEEDBOOSTER, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset16[6] = {
	PSPRITE_CHOZO_STATUE_WAVE_HINT, 0,
	PSPRITE_SKREE_BLUE, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset17[6] = {
	PSPRITE_CHOZO_STATUE_HIGH_JUMP, 0,
	PSPRITE_SQUEEPT, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset18[4] = {
	PSPRITE_CHOZO_STATUE_HIGH_JUMP_HINT, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset19[4] = {
	PSPRITE_CHOZO_STATUE_VARIA, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset20[6] = {
	PSPRITE_CHOZO_STATUE_VARIA_HINT, 0,
	PSPRITE_SQUEEPT, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset21[4] = {
	PSPRITE_CHOZO_STATUE_WAVE, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset22[6] = {
	PSPRITE_CHOZO_STATUE_SCREW_HINT, 0,
	PSPRITE_MORPH_BALL_LAUNCHER, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset23[4] = {
	PSPRITE_CHOZO_STATUE_SCREW, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset24[12] = {
	PSPRITE_SOVA_PURPLE, 0,
	PSPRITE_SOVA_ORANGE, 0,
	PSPRITE_MULTIVIOLA, 3,
	PSPRITE_GERUTA_RED, 4,
	PSPRITE_SQUEEPT, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset25[14] = {
	PSPRITE_VIOLA_BLUE, 0,
	PSPRITE_VIOLA_ORANGE, 1,
	PSPRITE_DESSGEEGA, 2,
	PSPRITE_HOLTZ, 3,
	PSPRITE_ZEBBO_GREEN, 4,
	PSPRITE_ZEBBO_YELLOW, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset26[12] = {
	PSPRITE_SOVA_PURPLE, 0,
	PSPRITE_SOVA_ORANGE, 0,
	PSPRITE_RIPPERII, 3,
	PSPRITE_MULTIVIOLA, 4,
	PSPRITE_SQUEEPT, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset27[4] = {
	PSPRITE_MAP_STATION, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset28[12] = {
	PSPRITE_SOVA_PURPLE, 0,
	PSPRITE_SOVA_ORANGE, 0,
	PSPRITE_DRAGON, 3,
	PSPRITE_DRAGON_UNUSED, 3,
	PSPRITE_GERUTA_RED, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset29[12] = {
	PSPRITE_SOVA_PURPLE, 0,
	PSPRITE_SOVA_ORANGE, 0,
	PSPRITE_DRAGON, 3,
	PSPRITE_DRAGON_UNUSED, 3,
	PSPRITE_GAMET_RED_SINGLE, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset30[14] = {
	PSPRITE_SOVA_PURPLE, 0,
	PSPRITE_SOVA_ORANGE, 0,
	PSPRITE_ZIPLINE, 3,
	PSPRITE_ZIPLINE_BUTTON, 3,
	PSPRITE_DRAGON, 4,
	PSPRITE_DRAGON_UNUSED, 4,
	SPRITESET_EMPTY
};

static const u8 sSpriteset31[4] = {
	PSPRITE_GUNSHIP, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset32[6] = {
	PSPRITE_ZEB, 0,
	PSPRITE_DEOREM, 1,
	SPRITESET_EMPTY
};

static const u8 sSpriteset33[6] = {
	PSPRITE_SAVE_PLATFORM, 0,
	PSPRITE_AREA_BANNER, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset34[12] = {
	PSPRITE_SOVA_PURPLE, 0,
	PSPRITE_SOVA_ORANGE, 0,
	PSPRITE_GAMET_RED_SINGLE, 3,
	PSPRITE_RIPPER_PURPLE, 4,
	PSPRITE_SQUEEPT, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset35[8] = {
	PSPRITE_SPACE_PIRATE, 0,
	PSPRITE_SPACE_PIRATE_WAITING1, 0,
	PSPRITE_GLASS_TUBE, 3,
	SPRITESET_EMPTY
};

static const u8 sSpriteset36[14] = {
	PSPRITE_VIOLA_BLUE, 0,
	PSPRITE_VIOLA_ORANGE, 1,
	PSPRITE_DESSGEEGA, 2,
	PSPRITE_HOLTZ, 3,
	PSPRITE_ZEBBO_GREEN, 4,
	PSPRITE_MULTIVIOLA, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset37[10] = {
	PSPRITE_HIVE, 0,
	PSPRITE_MELLOW_SWARM, 0,
	PSPRITE_MELLOW_SWARM_HEALTH_BASED, 0,
	PSPRITE_PARASITE, 6,
	SPRITESET_EMPTY
};

static const u8 sSpriteset38[8] = {
	PSPRITE_WAVER, 0,
	PSPRITE_WAVER_UNUSED, 1,
	PSPRITE_PARASITE, 2,
	SPRITESET_EMPTY
};

static const u8 sSpriteset39[12] = {
	PSPRITE_ZIPLINE, 0,
	PSPRITE_ZIPLINE_BUTTON, 0,
	PSPRITE_SIDEHOPPER, 1,
	PSPRITE_RIPPER_PURPLE, 2,
	PSPRITE_MORPH_BALL_LAUNCHER, 3,
	SPRITESET_EMPTY
};

static const u8 sSpriteset40[6] = {
	PSPRITE_POWER_GRIP, 0,
	PSPRITE_ELEVATOR_PAD, 2,
	SPRITESET_EMPTY
};

static const u8 sSpriteset41[6] = {
	PSPRITE_IMAGO_LARVA_RIGHT, 0,
	PSPRITE_IMAGO_LARVA_LEFT, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset42[6] = {
	PSPRITE_IMAGO_COCOON, 0,
	PSPRITE_DISCOVERED_IMAGO_PASSAGE_EVENT_TRIGGER, 8,
	SPRITESET_EMPTY
};

static const u8 sSpriteset43[12] = {
	PSPRITE_SOVA_PURPLE, 0,
	PSPRITE_SOVA_ORANGE, 0,
	PSPRITE_RIPPER_PURPLE, 3,
	PSPRITE_MULTIVIOLA, 4,
	PSPRITE_ELEVATOR_PAD, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset44[6] = {
	PSPRITE_SKREE_GREEN, 0,
	PSPRITE_DEOREM_SECOND_LOCATION, 1,
	SPRITESET_EMPTY
};

static const u8 sSpriteset45[10] = {
	PSPRITE_ITEM_BANNER, 7,
	PSPRITE_ITEM_BANNER, 7,
	PSPRITE_ITEM_BANNER, 7,
	PSPRITE_ITEM_BANNER, 7,
	SPRITESET_EMPTY
};

static const u8 sSpriteset46[10] = {
	PSPRITE_ZEB, 0,
	PSPRITE_GERON_BRINSTAR_ROOM_15, 1,
	PSPRITE_PARASITE, 1,
	PSPRITE_PISTON, 4,
	SPRITESET_EMPTY
};

static const u8 sSpriteset47[6] = {
	PSPRITE_CHOZO_STATUE_GRAVITY, 0,
	PSPRITE_GRAVITY_SUIT_BLOCK, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset48[6] = {
	PSPRITE_CHOZO_STATUE_SPACE_JUMP, 0,
	PSPRITE_SPACE_JUMP_BLOCK, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset49[10] = {
	PSPRITE_SOVA_PURPLE, 0,
	PSPRITE_SOVA_ORANGE, 0,
	PSPRITE_GERUTA_RED, 3,
	PSPRITE_GERUTA_GREEN, 4,
	SPRITESET_EMPTY
};

static const u8 sSpriteset50[24] = {
	PSPRITE_SPACE_PIRATE, 0,
	PSPRITE_SPACE_PIRATE_WAITING1, 0,
	PSPRITE_SPACE_PIRATE_WAITING3, 0,
	PSPRITE_SPACE_PIRATE2, 0,
	PSPRITE_SECURITY_GATE_DEFAULT_OPEN, 3,
	PSPRITE_SECURITY_GATE_DEFAULT_CLOSED, 3,
	PSPRITE_SECURITY_LASER_VERTICAL, 4,
	PSPRITE_SECURITY_LASER_HORIZONTAL, 4,
	PSPRITE_SECURITY_LASER_VERTICAL2, 4,
	PSPRITE_SECURITY_LASER_HORIZONTAL2, 4,
	PSPRITE_ITEM_BANNER, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset51[4] = {
	PSPRITE_PARASITE_MULTIPLE, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset52[12] = {
	PSPRITE_DESSGEEGA_AFTER_LONG_BEAM, 0,
	PSPRITE_RIPPER_BROWN, 1,
	PSPRITE_MORPH_BALL_LAUNCHER, 2,
	PSPRITE_ZIPLINE, 3,
	PSPRITE_ZIPLINE_BUTTON, 3,
	SPRITESET_EMPTY
};

static const u8 sSpriteset53[20] = {
	PSPRITE_SPACE_PIRATE, 0,
	PSPRITE_SPACE_PIRATE_WAITING1, 0,
	PSPRITE_SECURITY_GATE_DEFAULT_OPEN, 3,
	PSPRITE_SECURITY_GATE_DEFAULT_CLOSED, 3,
	PSPRITE_SEARCHLIGHT, 4,
	PSPRITE_SEARCHLIGHT2, 4,
	PSPRITE_SEARCHLIGHT3, 4,
	PSPRITE_SEARCHLIGHT4, 4,
	PSPRITE_MAYBE_SEARCHLIGHT_TRIGGER, 8,
	SPRITESET_EMPTY
};

static const u8 sSpriteset54[10] = {
	PSPRITE_METROID, 0,
	PSPRITE_RINKA_ORANGE, 5,
	PSPRITE_RINKA_GREEN, 6,
	PSPRITE_LOCK_UNLOCK_METROID_DOORS_UNUSED, 8,
	SPRITESET_EMPTY
};

static const u8 sSpriteset55[4] = {
	PSPRITE_RIDLEY, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset56[12] = {
	PSPRITE_SOVA_PURPLE, 0,
	PSPRITE_SOVA_ORANGE, 0,
	PSPRITE_RIPPER_PURPLE, 3,
	PSPRITE_MELLA, 4,
	PSPRITE_POLYP, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset57[14] = {
	PSPRITE_SPACE_PIRATE, 0,
	PSPRITE_SPACE_PIRATE_WAITING1, 0,
	PSPRITE_SPACE_PIRATE_WAITING3, 0,
	PSPRITE_SPACE_PIRATE2, 0,
	PSPRITE_SECURITY_GATE_DEFAULT_OPEN, 3,
	PSPRITE_WORKER_ROBOT, 4,
	SPRITESET_EMPTY
};

static const u8 sSpriteset58[12] = {
	PSPRITE_SOVA_PURPLE, 0,
	PSPRITE_SOVA_ORANGE, 0,
	PSPRITE_DRAGON, 3,
	PSPRITE_DRAGON_UNUSED, 3,
	PSPRITE_POLYP, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset59[6] = {
	PSPRITE_SAVE_PLATFORM_CHOZODIA, 0,
	PSPRITE_AREA_BANNER, 4,
	SPRITESET_EMPTY
};

static const u8 sSpriteset60[18] = {
	PSPRITE_SPACE_PIRATE, 0,
	PSPRITE_SPACE_PIRATE_WAITING1, 0,
	PSPRITE_SPACE_PIRATE_WAITING3, 0,
	PSPRITE_SPACE_PIRATE2, 0,
	PSPRITE_SECURITY_GATE_DEFAULT_OPEN, 3,
	PSPRITE_SECURITY_GATE_DEFAULT_CLOSED, 3,
	PSPRITE_SEARCHLIGHT_EYE, 4,
	PSPRITE_SEARCHLIGHT_EYE2, 4,
	SPRITESET_EMPTY
};

static const u8 sSpriteset61[4] = {
	PSPRITE_STEAM_SMALL, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset62[6] = {
	PSPRITE_ZOOMER_YELLOW, 0,
	PSPRITE_ZOOMER_RED, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset63[12] = {
	PSPRITE_SOVA_PURPLE, 0,
	PSPRITE_SOVA_ORANGE, 0,
	PSPRITE_GAMET_BLUE_SINGLE, 3,
	PSPRITE_MELLA, 4,
	PSPRITE_GAMET_RED_SINGLE, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset64[8] = {
	PSPRITE_RIPPER_BROWN, 0,
	PSPRITE_RIPPER_PURPLE, 0,
	PSPRITE_ATOMIC, 1,
	SPRITESET_EMPTY
};

static const u8 sSpriteset65[12] = {
	PSPRITE_VIOLA_BLUE, 0,
	PSPRITE_VIOLA_ORANGE, 1,
	PSPRITE_MORPH_BALL_LAUNCHER, 2,
	PSPRITE_GRAVITY_SUIT_BLOCK, 3,
	PSPRITE_RIPPER_PURPLE, 4,
	SPRITESET_EMPTY
};

static const u8 sSpriteset66[12] = {
	PSPRITE_SOVA_PURPLE, 0,
	PSPRITE_SOVA_ORANGE, 0,
	PSPRITE_RIPPER_BROWN, 3,
	PSPRITE_MORPH_BALL_LAUNCHER, 4,
	PSPRITE_GAMET_RED_SINGLE, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset67[26] = {
	PSPRITE_MOTHER_BRAIN, 0,
	PSPRITE_ZEBETITE_ONE_AND_THREE, 6,
	PSPRITE_ZEBETITE_TWO_AND_FOUR, 6,
	PSPRITE_RINKA_MOTHER_BRAIN2, 6,
	PSPRITE_RINKA_MOTHER_BRAIN3, 6,
	PSPRITE_RINKA_MOTHER_BRAIN4, 6,
	PSPRITE_RINKA_MOTHER_BRAIN5, 6,
	PSPRITE_RINKA_MOTHER_BRAIN6, 6,
	PSPRITE_RINKA_MOTHER_BRAIN, 6,
	PSPRITE_CANNON, 6,
	PSPRITE_CANNON2, 6,
	PSPRITE_CANNON3, 6,
	SPRITESET_EMPTY
};

static const u8 sSpriteset68[4] = {
	PSPRITE_ITEM_BANNER, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset69[20] = {
	PSPRITE_ELEVATOR_PAD, 0,
	PSPRITE_AREA_BANNER, 1,
	PSPRITE_EXPLOSION_ZEBES_ESCAPE, 8,
	PSPRITE_STEAM_LARGE, 2,
	PSPRITE_STEAM_SMALL, 2,
	PSPRITE_STEAM_LARGE_DIAGONAL_UP, 2,
	PSPRITE_STEAM_SMALL_DIAGONAL_UP, 2,
	PSPRITE_STEAM_LARGE_DIAGONAL_DOWN, 2,
	PSPRITE_STEAM_SMALL_DIAGONAL_DOWN, 2,
	SPRITESET_EMPTY
};

static const u8 sSpriteset70[8] = {
	PSPRITE_ACID_WORM, 0,
	PSPRITE_ZIPLINE, 4,
	PSPRITE_ZIPLINE_BUTTON, 4,
	SPRITESET_EMPTY
};

static const u8 sSpriteset71[12] = {
	PSPRITE_SOVA_PURPLE, 0,
	PSPRITE_SOVA_ORANGE, 0,
	PSPRITE_GERON_NORFAIR, 3,
	PSPRITE_POLYP, 4,
	PSPRITE_SQUEEPT, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset72[4] = {
	PSPRITE_IMAGO_LARVA_RIGHT_SIDE, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset73[22] = {
	PSPRITE_TANGLE_VINE_TALL, 0,
	PSPRITE_TANGLE_VINE_MEDIUM, 0,
	PSPRITE_TANGLE_VINE_CURVED, 0,
	PSPRITE_TANGLE_VINE_SHORT, 0,
	PSPRITE_TANGLE_VINE_RED_GARUTA, 0,
	PSPRITE_TANGLE_VINE_GERUTA, 0,
	PSPRITE_TANGLE_VINE_LARVA_RIGHT, 0,
	PSPRITE_TANGLE_VINE_LARVA_LEFT, 0,
	PSPRITE_GERUTA_RED, 5,
	PSPRITE_GERUTA_GREEN, 6,
	SPRITESET_EMPTY
};

static const u8 sSpriteset74[4] = {
	PSPRITE_IMAGO, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset75[4] = {
	PSPRITE_CROCOMIRE, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset76[18] = {
	PSPRITE_ZOOMER_YELLOW, 0,
	PSPRITE_ZOOMER_RED, 0,
	PSPRITE_GERON_BRINSTAR_ROOM_1C, 2,
	PSPRITE_GERON_VARIA1, 2,
	PSPRITE_GERON_VARIA2, 2,
	PSPRITE_PISTON, 5,
	PSPRITE_PARASITE, 2,
	PSPRITE_GERON_VARIA3, 2,
	SPRITESET_EMPTY
};

static const u8 sSpriteset77[6] = {
	PSPRITE_RUINS_TEST, 0,
	PSPRITE_FALLING_CHOZO_PILLAR, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset78[4] = {
	PSPRITE_BARISTUTE, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset79[8] = {
	PSPRITE_CHOZO_STATUE_PLASMA_BEAM, 0,
	PSPRITE_PLASMA_BEAM_BLOCK, 5,
	PSPRITE_WATER_DROP, 8,
	SPRITESET_EMPTY
};

static const u8 sSpriteset80[8] = {
	PSPRITE_ELEVATOR_PAD, 0,
	PSPRITE_RIDLEY_ELEVATOR_STATUE, 1,
	PSPRITE_GAMET_BLUE_LEADER, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset81[8] = {
	PSPRITE_ELEVATOR_PAD, 0,
	PSPRITE_KRAID_ELEVATOR_STATUE, 1,
	PSPRITE_ZOOMER_YELLOW, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset82[4] = {
	PSPRITE_RISING_CHOZO_PILLAR, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset83[8] = {
	PSPRITE_SIDEHOPPER, 0,
	PSPRITE_GEEGA_LEADER, 1,
	PSPRITE_GEEGA_FOLLOWER, 1,
	SPRITESET_EMPTY
};

static const u8 sSpriteset84[6] = {
	PSPRITE_SKREE_BLUE, 0,
	PSPRITE_CHOZO_STATUE_LONG_HINT, 1,
	SPRITESET_EMPTY
};

static const u8 sSpriteset85[16] = {
	PSPRITE_VIOLA_BLUE, 0,
	PSPRITE_VIOLA_ORANGE, 1,
	PSPRITE_HOLTZ, 2,
	PSPRITE_ZEBBO_GREEN, 3,
	PSPRITE_ZEBBO_GREEN_LEADER, 3,
	PSPRITE_ZEBBO_YELLOW, 4,
	PSPRITE_RIPPER_PURPLE, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset86[6] = {
	PSPRITE_KRAID_STATUE, 0,
	PSPRITE_RIDLEY_STATUE, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset87[2] = {
	SPRITESET_EMPTY
};

static const u8 sSpriteset88[8] = {
	PSPRITE_SAVE_PLATFORM_CHOZODIA, 0,
	PSPRITE_AREA_BANNER, 4,
	PSPRITE_SPACE_PIRATE, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset89[12] = {
	PSPRITE_SPACE_PIRATE, 0,
	PSPRITE_SPACE_PIRATE_WAITING2, 0,
	PSPRITE_SECURITY_GATE_DEFAULT_OPEN, 3,
	PSPRITE_SECURITY_GATE_DEFAULT_CLOSED, 3,
	PSPRITE_FAKE_POWER_BOMB_EVENT_TRIGGER, 8,
	SPRITESET_EMPTY
};

static const u8 sSpriteset90[6] = {
	PSPRITE_SKULTERA, 0,
	PSPRITE_WATER_DROP, 8,
	SPRITESET_EMPTY
};

static const u8 sSpriteset91[12] = {
	PSPRITE_VIOLA_BLUE, 0,
	PSPRITE_VIOLA_ORANGE, 1,
	PSPRITE_ZEBBO_YELLOW, 2,
	PSPRITE_GRAVITY_SUIT_BLOCK, 3,
	PSPRITE_GADORA_RIDLEY, 4,
	SPRITESET_EMPTY
};

static const u8 sSpriteset92[4] = {
	PSPRITE_GEKITAI_MACHINE, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset93[12] = {
	PSPRITE_SPACE_PIRATE, 0,
	PSPRITE_SPACE_PIRATE_WAITING1, 0,
	PSPRITE_ESCAPE_SHIP, 3,
	PSPRITE_ESCAPE_GATE1, 8,
	PSPRITE_ESCAPE_GATE2, 8,
	SPRITESET_EMPTY
};

static const u8 sSpriteset94[14] = {
	PSPRITE_DESSGEEGA_AFTER_LONG_BEAM, 0,
	PSPRITE_ZOOMER_YELLOW, 1,
	PSPRITE_ZOOMER_RED, 1,
	PSPRITE_RIPPER_BROWN, 3,
	PSPRITE_SKREE_GREEN, 4,
	PSPRITE_PARASITE, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset95[10] = {
	PSPRITE_GEEGA_LEADER, 0,
	PSPRITE_ZIPLINE, 1,
	PSPRITE_ZIPLINE_BUTTON, 1,
	PSPRITE_ZIPLINE_GENERATOR, 2,
	SPRITESET_EMPTY
};

static const u8 sSpriteset96[16] = {
	PSPRITE_SPACE_PIRATE, 0,
	PSPRITE_SPACE_PIRATE_WAITING1, 0,
	PSPRITE_SPACE_PIRATE_WAITING3, 0,
	PSPRITE_SPACE_PIRATE2, 0,
	PSPRITE_SPACE_PIRATE_CARRYING_POWER_BOMB, 0,
	PSPRITE_FAKE_POWER_BOMB, 3,
	PSPRITE_ITEM_BANNER, 4,
	SPRITESET_EMPTY
};

static const u8 sSpriteset97[8] = {
	PSPRITE_VIOLA_BLUE, 0,
	PSPRITE_VIOLA_ORANGE, 1,
	PSPRITE_IMAGO_COCOON_AFTER_FIGHT, 2,
	SPRITESET_EMPTY
};

static const u8 sSpriteset98[8] = {
	PSPRITE_PLASMA_BEAM_BLOCK, 0,
	PSPRITE_RIPPER_BROWN, 1,
	PSPRITE_WATER_DROP, 8,
	SPRITESET_EMPTY
};

static const u8 sSpriteset99[4] = {
	PSPRITE_ESCAPE_SHIP, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset100[12] = {
	PSPRITE_SPACE_PIRATE, 0,
	PSPRITE_SPACE_PIRATE_WAITING1, 0,
	PSPRITE_SPACE_PIRATE_WAITING3, 0,
	PSPRITE_SPACE_PIRATE2, 0,
	PSPRITE_ATOMIC, 3,
	SPRITESET_EMPTY
};

static const u8 sSpriteset101[4] = {
	PSPRITE_MECHA_RIDLEY, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset102[6] = {
	PSPRITE_BARISTUTE_KRAID_UPPER, 0,
	PSPRITE_BARISTUTE_KRAID_LOWER, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset103[8] = {
	PSPRITE_MAP_STATION, 0,
	PSPRITE_AREA_BANNER, 4,
	PSPRITE_SPACE_PIRATE, 5,
	SPRITESET_EMPTY
};

static const u8 sSpriteset104[12] = {
	PSPRITE_SPACE_PIRATE, 0,
	PSPRITE_SPACE_PIRATE_WAITING1, 0,
	PSPRITE_SPACE_PIRATE_WAITING3, 0,
	PSPRITE_SPACE_PIRATE2, 0,
	PSPRITE_BLACK_SPACE_PIRATE, 0,
	SPRITESET_EMPTY
};

static const u8 sSpriteset105[8] = {
	PSPRITE_REO_GREEN_WINGS, 0,
	PSPRITE_SIDEHOPPER, 1,
	PSPRITE_GEEGA, 2,
	SPRITESET_EMPTY
};

static const u8 sSpriteset106[2] = {
	SPRITESET_EMPTY
};

static const u8 sSpriteset107[2] = {
	SPRITESET_EMPTY
};

static const u8 sSpriteset108[2] = {
	SPRITESET_EMPTY
};

static const u8 sSpriteset109[2] = {
	SPRITESET_EMPTY
};

static const u8 sSpriteset110[2] = {
	SPRITESET_EMPTY
};

static const u8 sSpriteset111[2] = {
	SPRITESET_EMPTY
};

static const u8 sSpriteset112[2] = {
	SPRITESET_EMPTY
};

static const i16 sDebrisBouncingVelocity[9] = {
    -4, -8, -4, 0, 4, 8, 12, 16, 20
};

static const i16 sDebris11YVelocity[9] = {
    -4, -8, -6, -4, 0, 4, 8, 8, 12
};

static const i16 sDebris12YVelocity[9] = {
    -4, -8, -4, -2, 0, 4, 8, 12, 12
};

static const i16 sDebris13YVelocity[9] = {
    -6, -8, -10, -6, 0, 4, 8, 12, 16
};

static const i16 sDebris4YVelocity[9] = {
    -5, -13, -7, -3, 0, 6, 10, 16, 20
};

static const i16 sDebris5YVelocity[9] = {
    4, 8, 12, 16, 20, 24, 28, 28, 28
};

static const i16 sDebris6YVelocity[9] = {
    8, 10, 12, 14, 16, 18, 20, 22, 22
};

static const i16 sDebris7YVelocity[9] = {
    2, 4, 6, 8, 10, 12, 14, 16, 16, 
};

static const i16 sDebris8YVelocity[9] = {
    8, 16, 20, 24, 28, 32, 36, 36, 36
};

// 2b25c8

#endif