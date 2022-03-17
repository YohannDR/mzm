#include "data.h"

struct oam_frame bomb_oam_normal1 = {
    0x1,
    {
        { 0xF8, 0x1FC, 0x414D },
    }
};

struct oam_frame bomb_oam_normal2 = {
    0x1,
    {
        { 0xF8, 0x1FC, 0x414E },
    }
};

struct oam_frame bomb_oam_normal3 = {
    0x1,
    {
        { 0xF8, 0x1FC, 0x414F },
    }
};

struct oam_frame bomb_oam_normal4 = {
    0x1,
    {
        { 0xF8, 0x1FC, 0x4150 },
    }
};

struct oam_frame bomb_oam_fast1 = {
    0x1,
    {
        { 0xF8, 0x1FC, 0x414D },
    }
};

struct oam_frame bomb_oam_fast2 = {
    0x1,
    {
        { 0xF8, 0x1FC, 0x414E },
    }
};

struct oam_frame bomb_oam_fast3 = {
    0x1,
    {
        { 0xF8, 0x1FC, 0x414F },
    }
};

struct oam_frame bomb_oam_fast4 = {
    0x1,
    {
        { 0xF8, 0x1FC, 0x4150 },
    }
};

struct oam_frame power_bomb_oam_normal1 = {
    0x1,
    {
        { 0xF8, 0x1FC, 0x414B },
    }
};

struct oam_frame power_bomb_oam_normal2 = {
    0x1,
    {
        { 0xF8, 0x1FC, 0x414C },
    }
};

struct oam_frame power_bomb_oam_normal3 = {
    0x1,
    {
        { 0xF8, 0x1FC, 0x416B },
    }
};

struct oam_frame power_bomb_oam_fast1 = {
    0x1,
    {
        { 0xF8, 0x1FC, 0x414B },
    }
};

struct oam_frame power_bomb_oam_fast2 = {
    0x1,
    {
        { 0xF8, 0x1FC, 0x414C },
    }
};

struct oam_frame power_bomb_oam_fast3 = {
    0x1,
    {
        { 0xF8, 0x1FC, 0x416B },
    }
};

struct frame_data bomb_oam_normal[5] = {
    &bomb_oam_normal1,
    0x6,
    &bomb_oam_normal2,
    0x6,
    &bomb_oam_normal3,
    0x6,
    &bomb_oam_normal4,
    0x6,
};

struct frame_data bomb_oam_fast[5] = {
    &bomb_oam_fast1,
    0x2,
    &bomb_oam_fast2,
    0x2,
    &bomb_oam_fast3,
    0x2,
    &bomb_oam_fast4,
    0x2,
};

struct frame_data power_bomb_oam_normal[4] = {
    &power_bomb_oam_normal1,
    0x6,
    &power_bomb_oam_normal2,
    0x6,
    &power_bomb_oam_normal3,
    0x6,
};

struct frame_data power_bomb_oam_fast[4] = {
    &power_bomb_oam_fast1,
    0x3,
    &power_bomb_oam_fast2,
    0x3,
    &power_bomb_oam_fast3,
    0x3,
};

