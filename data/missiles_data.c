#include "data.h"

struct oam_frame missile_oam_forward1 = {
    0x2,
    {
        { 0xFC, 0x3, 0x30D0 },
        { 0x3, 0x30D0, 0x40FC },
    }
};

struct oam_frame missile_oam_forward2 = {
    0x2,
    {
        { 0xFC, 0x7, 0x30D1 },
        { 0x7, 0x30D1, 0x40FC },
    }
};

struct oam_frame missile_oam_diagonal1 = {
    0x2,
    {
        { 0x1, 0x1, 0x30D0 },
        { 0x1, 0x30D0, 0xF8 },
    }
};

struct oam_frame missile_oam_diagonal2 = {
    0x2,
    {
        { 0xF8, 0x41F8, 0x405C },
        { 0x41F8, 0x405C, 0x3 },
    }
};

struct oam_frame missile_oam_up_down1 = {
    0x2,
    {
        { 0x3, 0x1FC, 0x30D0 },
        { 0x1FC, 0x30D0, 0x80F8 },
    }
};

struct oam_frame missile_oam_up_down2 = {
    0x2,
    {
        { 0x7, 0x1FC, 0x30F1 },
        { 0x1FC, 0x30F1, 0x80F8 },
    }
};

struct oam_frame super_missile_oam_forward1 = {
    0x2,
    {
        { 0xF8, 0x4002, 0x30D3 },
        { 0x4002, 0x30D3, 0x40FC },
    }
};

struct oam_frame super_missile_oam_forward2 = {
    0x2,
    {
        { 0x40FC, 0x1F8, 0x407A },
        { 0x1F8, 0x407A, 0xFC },
    }
};

struct oam_frame super_missile_oam_diagonal1 = {
    0x2,
    {
        { 0xFF, 0x41FF, 0x30D3 },
        { 0x41FF, 0x30D3, 0xF8 },
    }
};

struct oam_frame super_missile_oam_diagonal2 = {
    0x2,
    {
        { 0xF8, 0x41F8, 0x405E },
        { 0x41F8, 0x405E, 0x3 },
    }
};

struct oam_frame super_missile_oam_up_down1 = {
    0x2,
    {
        { 0x1, 0x41F8, 0x30D3 },
        { 0x41F8, 0x30D3, 0x80F8 },
    }
};

struct oam_frame super_missile_oam_up_down2 = {
    0x2,
    {
        { 0x80F8, 0x1FC, 0x4186 },
        { 0x1FC, 0x4186, 0x5 },
    }
};

struct oam_frame missile_tumbling_oam1 = {
    0x1,
    {
        { 0x40FC, 0x1F8, 0x4078 },
    }
};

struct oam_frame missile_tumbling_oam2 = {
    0x1,
    {
        { 0xF8, 0x41F8, 0x405C },
    }
};

struct oam_frame missile_tumbling_oam3 = {
    0x1,
    {
        { 0x80F8, 0x1FC, 0x4185 },
    }
};

struct oam_frame missile_tumbling_oam4 = {
    0x1,
    {
        { 0xF8, 0x51F8, 0x405C },
    }
};

struct oam_frame missile_tumbling_oam5 = {
    0x1,
    {
        { 0x40FC, 0x11F8, 0x4078 },
    }
};

struct oam_frame missile_tumbling_oam6 = {
    0x1,
    {
        { 0xF8, 0x71F8, 0x405C },
    }
};

struct oam_frame missile_tumbling_oam7 = {
    0x1,
    {
        { 0x80F8, 0x21FC, 0x4185 },
    }
};

struct oam_frame missile_tumbling_oam8 = {
    0x1,
    {
        { 0xF8, 0x61F8, 0x405C },
    }
};

struct oam_frame super_missile_tumbling_oam1 = {
    0x1,
    {
        { 0x40FC, 0x1F8, 0x407A },
    }
};

struct oam_frame super_missile_tumbling_oam2 = {
    0x1,
    {
        { 0xF8, 0x41F8, 0x405E },
    }
};

struct oam_frame super_missile_tumbling_oam3 = {
    0x1,
    {
        { 0x80F8, 0x1FC, 0x4186 },
    }
};

struct oam_frame super_missile_tumbling_oam4 = {
    0x1,
    {
        { 0xF8, 0x51F8, 0x405E },
    }
};

struct oam_frame super_missile_tumbling_oam5 = {
    0x1,
    {
        { 0x40FC, 0x11F8, 0x407A },
    }
};

struct oam_frame super_missile_tumbling_oam6 = {
    0x1,
    {
        { 0xF8, 0x71F8, 0x405E },
    }
};

struct oam_frame super_missile_tumbling_oam7 = {
    0x1,
    {
        { 0x80F8, 0x21FC, 0x4186 },
    }
};

struct oam_frame super_missile_tumbling_oam8 = {
    0x1,
    {
        { 0xF8, 0x61F8, 0x405E },
    }
};

struct oam_frame particle_missile_trail_oam1 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x30D5 },
    }
};

struct oam_frame particle_missile_trail_oam2 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x30F5 },
    }
};

struct oam_frame particle_missile_trail_oam3 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x30F6 },
    }
};

struct oam_frame particle_missile_trail_oam4 = {
    0x1,
    {
        { 0xF9, 0x1FC, 0x415A },
    }
};

struct oam_frame particle_missile_trail_oam5 = {
    0x1,
    {
        { 0xF7, 0x1FC, 0x415B },
    }
};

struct oam_frame particle_missile_trail_oam6 = {
    0x1,
    {
        { 0xF3, 0x1FC, 0x415C },
    }
};

struct oam_frame particle_missile_trail_oam7 = {
    0x1,
    {
        { 0xF1, 0x1FC, 0x415D },
    }
};

struct oam_frame particle_super_missile_trail_oam1 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x30D0 },
    }
};

struct oam_frame particle_super_missile_trail_oam2 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x30F5 },
    }
};

struct oam_frame particle_super_missile_trail_oam3 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x30F6 },
    }
};

struct oam_frame particle_super_missile_trail_oam4 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x4159 },
    }
};

struct oam_frame particle_super_missile_trail_oam5 = {
    0x1,
    {
        { 0xF9, 0x1FC, 0x415A },
    }
};

struct oam_frame particle_super_missile_trail_oam6 = {
    0x1,
    {
        { 0xF7, 0x1FC, 0x415B },
    }
};

struct oam_frame particle_super_missile_trail_oam7 = {
    0x1,
    {
        { 0xF3, 0x1FC, 0x415C },
    }
};

struct oam_frame particle_super_missile_trail_oam8 = {
    0x1,
    {
        { 0xF1, 0x1FC, 0x415D },
    }
};

struct frame_data missile_oam_forward[3] = {
    &missile_oam_forward1,
    0x2,
    &missile_oam_forward2,
    0x2,
};

struct frame_data missile_oam_diagonal[3] = {
    &missile_oam_diagonal1,
    0x2,
    &missile_oam_diagonal2,
    0x2,
};

struct frame_data missile_oam_up_down[3] = {
    &missile_oam_up_down1,
    0x2,
    &missile_oam_up_down2,
    0x2,
};

struct frame_data super_missile_oam_forward[3] = {
    &super_missile_oam_forward1,
    0x2,
    &super_missile_oam_forward2,
    0x2,
};

struct frame_data super_missile_oam_diagonal[3] = {
    &super_missile_oam_diagonal1,
    0x2,
    &super_missile_oam_diagonal2,
    0x2,
};

struct frame_data super_missile_oam_up_down[3] = {
    &super_missile_oam_up_down1,
    0x2,
    &super_missile_oam_up_down2,
    0x2,
};

struct frame_data missile_tumbling_oam[9] = {
    &missile_tumbling_oam1,
    0x3,
    &missile_tumbling_oam2,
    0x3,
    &missile_tumbling_oam3,
    0x3,
    &missile_tumbling_oam4,
    0x3,
    &missile_tumbling_oam5,
    0x3,
    &missile_tumbling_oam6,
    0x3,
    &missile_tumbling_oam7,
    0x3,
    &missile_tumbling_oam8,
    0x3,
};

struct frame_data super_missile_tumbling_oam[9] = {
    &super_missile_tumbling_oam1,
    0x3,
    &super_missile_tumbling_oam2,
    0x3,
    &super_missile_tumbling_oam3,
    0x3,
    &super_missile_tumbling_oam4,
    0x3,
    &super_missile_tumbling_oam5,
    0x3,
    &super_missile_tumbling_oam6,
    0x3,
    &super_missile_tumbling_oam7,
    0x3,
    &super_missile_tumbling_oam8,
    0x3,
};

struct frame_data particle_missile_trail_oam[8] = {
    &particle_missile_trail_oam1,
    0x4,
    &particle_missile_trail_oam2,
    0x4,
    &particle_missile_trail_oam3,
    0x4,
    &particle_missile_trail_oam4,
    0x3,
    &particle_missile_trail_oam5,
    0x3,
    &particle_missile_trail_oam6,
    0x3,
    &particle_missile_trail_oam7,
    0x3,
};

struct frame_data particle_super_missile_trail_oam[9] = {
    &particle_super_missile_trail_oam1,
    0x4,
    &particle_super_missile_trail_oam2,
    0x4,
    &particle_super_missile_trail_oam3,
    0x4,
    &particle_super_missile_trail_oam4,
    0x3,
    &particle_super_missile_trail_oam5,
    0x3,
    &particle_super_missile_trail_oam6,
    0x3,
    &particle_super_missile_trail_oam7,
    0x3,
    &particle_super_missile_trail_oam8,
    0x3,
};

