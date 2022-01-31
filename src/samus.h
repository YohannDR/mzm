#ifndef SAMUS_H
#define SAMUS_H

#include "types.h"

enum __attribute__ ((packed)) beam_bombs_flags {
    BBF_NONE = 0x0,
    BBF_LONG_BEAM = 0x1,
    BBF_ICE_BEAM = 0x2,
    BBF_WAVE_BEAM = 0x4,
    BBF_PLASMA_BEAM = 0x8,
    BBF_CHARGE_BEAM = 0x10,
    BBF_BOMBS = 0x80
};

enum __attribute__ ((packed)) suit_misc_flags {
    SMF_NONE = 0x0,
    SMF_HIGH_JUMP = 0x1,
    SMF_SPEED_BOOSTER = 0x2,
    SMF_SPACE_JUMP = 0x4,
    SMF_SCREW_ATTACK = 0x8,
    SMF_VARIA_SUIT = 0x10,
    SMF_GRAVITY_SUIT = 0x20,
    SMF_MORPH_BALL = 0x40,
    SMF_POWER_GRIP = 0x80
};

enum __attribute__ ((packed)) suit_type {
    SUIT_NORMAL = 0x0,
    SUIT_FULLY_POWERED = 0x1,
    SUIT_SUITLESS = 0x2
};

struct equipment {
    u16 max_energy;
    u16 max_missiles;
    u8 max_super_missiles;
    u8 max_power_bombs;
    u16 current_energy;
    u16 current_missiles;
    u8 current_super_missiles;
    u8 current_power_bombs;
    enum beam_bombs_flags beam_bombs;
    enum beam_bombs_flags beam_bombs_activation;
    enum suit_misc_flags suit_misc;
    enum suit_misc_flags suit_misc_activation;
    u8 downloaded_map_status;
    u8 low_health;
    enum suit_type suit_type;
    u8 grabbed_by_metroid;
};

#endif /* SAMUS_H */