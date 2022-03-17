#include "data.h"

struct oam_frame small_energy_drop_oam1 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x4183 },
    }
};

struct oam_frame small_energy_drop_oam2 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x41A3 },
    }
};

struct oam_frame small_energy_drop_oam3 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x4184 },
    }
};

struct oam_frame small_energy_drop_oam4 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x41A4 },
    }
};

struct oam_frame large_energy_drop_oam1 = {
    0x1,
    {
        { 0xF8, 0x41F8, 0x41C0 },
    }
};

struct oam_frame large_energy_drop_oam2 = {
    0x1,
    {
        { 0xF8, 0x41F8, 0x41C2 },
    }
};

struct oam_frame large_energy_drop_oam3 = {
    0x1,
    {
        { 0xF8, 0x41F8, 0x41C4 },
    }
};

struct oam_frame large_energy_drop_oam4 = {
    0x1,
    {
        { 0xF8, 0x41F8, 0x41C6 },
    }
};

struct oam_frame missile_drop_oam1 = {
    0x1,
    {
        { 0x80F8, 0x1FC, 0x4185 },
    }
};

struct oam_frame missile_drop_oam2 = {
    0x1,
    {
        { 0x80F8, 0x1FC, 0x4190 },
    }
};

struct oam_frame super_missile_drop_oam1 = {
    0x1,
    {
        { 0x80F8, 0x1FC, 0x4186 },
    }
};

struct oam_frame super_missile_drop_oam2 = {
    0x1,
    {
        { 0x80F8, 0x1FC, 0x4191 },
    }
};

struct oam_frame power_bomb_drop_oam1 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x414B },
    }
};

struct oam_frame power_bomb_drop_oam2 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x416C },
    }
};

struct oam_frame multiple_large_energy_drop_slot1_oam1 = {
    0x3,
    {
        { 0xF3, 0x41F1, 0x41C0 },
        { 0x41F1, 0x41C0, 0xF8 },
        { 0x41C0, 0xF8, 0x4000 },
    }
};

struct oam_frame multiple_large_energy_drop_slot1_oam2 = {
    0x3,
    {
        { 0xF3, 0x41F1, 0x41C2 },
        { 0x41F1, 0x41C2, 0xF8 },
        { 0x41C2, 0xF8, 0x4000 },
    }
};

struct oam_frame multiple_large_energy_drop_slot1_oam3 = {
    0x3,
    {
        { 0xF3, 0x41F1, 0x41C4 },
        { 0x41F1, 0x41C4, 0xF8 },
        { 0x41C4, 0xF8, 0x4000 },
    }
};

struct oam_frame multiple_large_energy_drop_slot1_oam4 = {
    0x3,
    {
        { 0xF3, 0x41F1, 0x41C6 },
        { 0x41F1, 0x41C6, 0xF8 },
        { 0x41C6, 0xF8, 0x4000 },
    }
};

struct oam_frame multiple_large_energy_drop_slot3_oam1 = {
    0x3,
    {
        { 0xF2, 0x41F7, 0x41C0 },
        { 0x41F7, 0x41C0, 0xFF },
        { 0x41C0, 0xFF, 0x41F1 },
    }
};

struct oam_frame multiple_large_energy_drop_slot3_oam2 = {
    0x3,
    {
        { 0xF2, 0x41F7, 0x41C2 },
        { 0x41F7, 0x41C2, 0xFF },
        { 0x41C2, 0xFF, 0x41F1 },
    }
};

struct oam_frame multiple_large_energy_drop_slot3_oam3 = {
    0x3,
    {
        { 0xF2, 0x41F7, 0x41C4 },
        { 0x41F7, 0x41C4, 0xFF },
        { 0x41C4, 0xFF, 0x41F1 },
    }
};

struct oam_frame multiple_large_energy_drop_slot3_oam4 = {
    0x3,
    {
        { 0xF2, 0x41F7, 0x41C6 },
        { 0x41F7, 0x41C6, 0xFF },
        { 0x41C6, 0xFF, 0x41F1 },
    }
};

struct oam_frame multiple_large_energy_drop_slot2_oam1 = {
    0x3,
    {
        { 0xF4, 0x41FB, 0x41C0 },
        { 0x41FB, 0x41C0, 0xFF },
        { 0x41C0, 0xFF, 0x41F3 },
    }
};

struct oam_frame multiple_large_energy_drop_slot2_oam2 = {
    0x3,
    {
        { 0xF4, 0x41FB, 0x41C2 },
        { 0x41FB, 0x41C2, 0xFF },
        { 0x41C2, 0xFF, 0x41F3 },
    }
};

struct oam_frame multiple_large_energy_drop_slot2_oam3 = {
    0x3,
    {
        { 0xF4, 0x41FB, 0x41C4 },
        { 0x41FB, 0x41C4, 0xFF },
        { 0x41C4, 0xFF, 0x41F3 },
    }
};

struct oam_frame multiple_large_energy_drop_slot2_oam4 = {
    0x3,
    {
        { 0xF4, 0x41FB, 0x41C6 },
        { 0x41FB, 0x41C6, 0xFF },
        { 0x41C6, 0xFF, 0x41F3 },
    }
};

struct frame_data small_energy_drop_oam[5] = {
    &small_energy_drop_oam1,
    0x8,
    &small_energy_drop_oam2,
    0x8,
    &small_energy_drop_oam3,
    0x8,
    &small_energy_drop_oam4,
    0x8,
};

struct frame_data large_energy_drop_oam[5] = {
    &large_energy_drop_oam1,
    0x8,
    &large_energy_drop_oam2,
    0x8,
    &large_energy_drop_oam3,
    0x8,
    &large_energy_drop_oam4,
    0x8,
};

struct frame_data missile_drop_oam[3] = {
    &missile_drop_oam1,
    0x4,
    &missile_drop_oam2,
    0x4,
};

struct frame_data super_missile_drop_oam[3] = {
    &super_missile_drop_oam1,
    0x4,
    &super_missile_drop_oam2,
    0x4,
};

struct frame_data power_bomb_drop_oam[3] = {
    &power_bomb_drop_oam1,
    0x4,
    &power_bomb_drop_oam2,
    0x4,
};

struct frame_data multiple_large_energy_drop_slot1_oam[5] = {
    &multiple_large_energy_drop_slot1_oam1,
    0x8,
    &multiple_large_energy_drop_slot1_oam2,
    0x8,
    &multiple_large_energy_drop_slot1_oam3,
    0x8,
    &multiple_large_energy_drop_slot1_oam4,
    0x8,
};

struct frame_data multiple_large_energy_drop_slot3_oam[5] = {
    &multiple_large_energy_drop_slot3_oam1,
    0x8,
    &multiple_large_energy_drop_slot3_oam2,
    0x8,
    &multiple_large_energy_drop_slot3_oam3,
    0x8,
    &multiple_large_energy_drop_slot3_oam4,
    0x8,
};

struct frame_data multiple_large_energy_drop_slot2_oam[5] = {
    &multiple_large_energy_drop_slot2_oam1,
    0x8,
    &multiple_large_energy_drop_slot2_oam2,
    0x8,
    &multiple_large_energy_drop_slot2_oam3,
    0x8,
    &multiple_large_energy_drop_slot2_oam4,
    0x8,
};

