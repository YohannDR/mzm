#include "data.h"

struct oam_frame normal_beam_oam_forward1 = {
    0x1,
    {
        { 0x40FC, 0x1FA, 0x2080 },
    }
};

struct oam_frame normal_beam_oam_forward2 = {
    0x1,
    {
        { 0x40FC, 0x1FA, 0x20A0 },
    }
};

struct oam_frame normal_beam_oam_diagonal1 = {
    0x1,
    {
        { 0xF9, 0x41F9, 0x2082 },
    }
};

struct oam_frame normal_beam_oam_diagonal2 = {
    0x1,
    {
        { 0xF9, 0x41F9, 0x2084 },
    }
};

struct oam_frame normal_beam_oam_up_down1 = {
    0x1,
    {
        { 0x80FA, 0x1FC, 0x2086 },
    }
};

struct oam_frame normal_beam_oam_up_down2 = {
    0x1,
    {
        { 0x80FA, 0x1FC, 0x2087 },
    }
};

struct oam_frame normal_beam_oam_unused11 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x20A8 },
    }
};

struct oam_frame normal_beam_oam_unused12 = {
    0x1,
    {
        { 0xFC, 0x1FD, 0x20A8 },
    }
};

struct oam_frame normal_beam_oam_unused21 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x20A9 },
    }
};

struct oam_frame normal_beam_oam_unused22 = {
    0x1,
    {
        { 0xFD, 0x1FD, 0x20A9 },
    }
};

struct oam_frame normal_beam_oam_unused31 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x20AA },
    }
};

struct oam_frame normal_beam_oam_unused32 = {
    0x1,
    {
        { 0xFD, 0x1FC, 0x20AA },
    }
};

struct oam_frame charged_normal_beam_oam_forward1 = {
    0x2,
    {
        { 0xF8, 0x41FA, 0x20C0 },
        { 0x41FA, 0x20C0, 0xF8 },
    }
};

struct oam_frame charged_normal_beam_oam_forward2 = {
    0x3,
    {
        { 0xF8, 0x41F8, 0x20C2 },
        { 0x41F8, 0x20C2, 0xF8 },
        { 0x20C2, 0xF8, 0x4001 },
    }
};

struct oam_frame charged_normal_beam_oam_diagonal1 = {
    0x2,
    {
        { 0xFB, 0x41FB, 0x20C4 },
        { 0x41FB, 0x20C4, 0xFE },
    }
};

struct oam_frame charged_normal_beam_oam_diagonal2 = {
    0x3,
    {
        { 0xFA, 0x41FA, 0x20C6 },
        { 0x41FA, 0x20C6, 0xFF },
        { 0x20C6, 0xFF, 0x41FF },
    }
};

struct oam_frame charged_normal_beam_oam_up_down1 = {
    0x2,
    {
        { 0xFA, 0x41F8, 0x20C8 },
        { 0x41F8, 0x20C8, 0xFF },
    }
};

struct oam_frame charged_normal_beam_oam_up_down2 = {
    0x3,
    {
        { 0xF8, 0x41F8, 0x20CA },
        { 0x41F8, 0x20CA, 0x1 },
        { 0x20CA, 0x1, 0x41F8 },
    }
};

struct oam_frame normal_beam_oam_unused41 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x20CE },
    }
};

struct oam_frame normal_beam_oam_unused42 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x20CF },
    }
};

struct oam_frame normal_beam_oam_unused43 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x20EE },
    }
};

struct oam_frame normal_beam_oam_unused44 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x20EF },
    }
};

struct oam_frame long_beam_oam_forward1 = {
    0x1,
    {
        { 0x40FC, 0x1FC, 0x2080 },
    }
};

struct oam_frame long_beam_oam_forward2 = {
    0x1,
    {
        { 0x40FC, 0x1FC, 0x20A0 },
    }
};

struct oam_frame long_beam_oam_diagonal1 = {
    0x1,
    {
        { 0xF9, 0x41F9, 0x20C0 },
    }
};

struct oam_frame long_beam_oam_diagonal2 = {
    0x1,
    {
        { 0xF9, 0x41F9, 0x20C2 },
    }
};

struct oam_frame long_beam_oam_up_down1 = {
    0x1,
    {
        { 0x80FC, 0x1FC, 0x2082 },
    }
};

struct oam_frame long_beam_oam_up_down2 = {
    0x1,
    {
        { 0x80FC, 0x1FC, 0x2083 },
    }
};

struct oam_frame charged_long_beam_oam_forward1 = {
    0x2,
    {
        { 0x40F8, 0x81FA, 0x2086 },
        { 0x81FA, 0x2086, 0x40F8 },
    }
};

struct oam_frame charged_long_beam_oam_forward2 = {
    0x3,
    {
        { 0x40F8, 0x81F8, 0x20C6 },
        { 0x81F8, 0x20C6, 0x40F8 },
        { 0x20C6, 0x40F8, 0x8002 },
    }
};

struct oam_frame charged_long_beam_oam_diagonal1 = {
    0x2,
    {
        { 0xFC, 0x41FC, 0x2084 },
        { 0x41FC, 0x2084, 0x2 },
    }
};

struct oam_frame charged_long_beam_oam_diagonal2 = {
    0x3,
    {
        { 0xFB, 0x41FB, 0x20C4 },
        { 0x41FB, 0x20C4, 0x1 },
        { 0x20C4, 0x1, 0x4001 },
    }
};

struct oam_frame charged_long_beam_oam_up_down1 = {
    0x2,
    {
        { 0x80FA, 0x81F8, 0x208A },
        { 0x81F8, 0x208A, 0x8001 },
    }
};

struct oam_frame charged_long_beam_oam_up_down2 = {
    0x3,
    {
        { 0x80F8, 0x81F8, 0x208C },
        { 0x81F8, 0x208C, 0x8002 },
        { 0x208C, 0x8002, 0x81F8 },
    }
};

struct oam_frame ice_beam_oam_forward1 = {
    0x1,
    {
        { 0xF8, 0x41FB, 0x2080 },
    }
};

struct oam_frame ice_beam_oam_forward2 = {
    0x1,
    {
        { 0xF8, 0x41FC, 0x2082 },
    }
};

struct oam_frame ice_beam_oam_diagonal1 = {
    0x1,
    {
        { 0xFA, 0x41F9, 0x2084 },
    }
};

struct oam_frame ice_beam_oam_diagonal2 = {
    0x1,
    {
        { 0xFB, 0x41FA, 0x2086 },
    }
};

struct oam_frame ice_beam_oam_up_down1 = {
    0x1,
    {
        { 0xFB, 0x41F8, 0x2088 },
    }
};

struct oam_frame ice_beam_oam_up_down2 = {
    0x1,
    {
        { 0xFC, 0x41F8, 0x208A },
    }
};

struct oam_frame ice_beam_oam_unused11 = {
    0x1,
    {
        { 0xFC, 0x1FC, 0x208C },
    }
};

struct oam_frame ice_beam_oam_unused12 = {
    0x1,
    {
        { 0xFC, 0x1FD, 0x208C },
    }
};

struct frame_data normal_beam_oam_forward[3] = {
    &normal_beam_oam_forward1,
    0x3,
    &normal_beam_oam_forward2,
    0x3,
};

struct frame_data normal_beam_oam_diagonal[3] = {
    &normal_beam_oam_diagonal1,
    0x3,
    &normal_beam_oam_diagonal2,
    0x3,
};

struct frame_data normal_beam_oam_up_down[3] = {
    &normal_beam_oam_up_down1,
    0x3,
    &normal_beam_oam_up_down2,
    0x3,
};

struct frame_data normal_beam_oam_unused1[3] = {
    &normal_beam_oam_unused11,
    0x3,
    &normal_beam_oam_unused12,
    0x3,
};

struct frame_data normal_beam_oam_unused2[3] = {
    &normal_beam_oam_unused21,
    0x3,
    &normal_beam_oam_unused22,
    0x3,
};

struct frame_data normal_beam_oam_unused3[3] = {
    &normal_beam_oam_unused31,
    0x3,
    &normal_beam_oam_unused32,
    0x3,
};

struct frame_data charged_normal_beam_oam_forward[3] = {
    &charged_normal_beam_oam_forward1,
    0x2,
    &charged_normal_beam_oam_forward2,
    0x2,
};

struct frame_data charged_normal_beam_oam_diagonal[3] = {
    &charged_normal_beam_oam_diagonal1,
    0x2,
    &charged_normal_beam_oam_diagonal2,
    0x2,
};

struct frame_data charged_normal_beam_oam_up_down[3] = {
    &charged_normal_beam_oam_up_down1,
    0x2,
    &charged_normal_beam_oam_up_down2,
    0x2,
};

struct frame_data normal_beam_oam_unused4[5] = {
    &normal_beam_oam_unused41,
    0x4,
    &normal_beam_oam_unused42,
    0x4,
    &normal_beam_oam_unused43,
    0x4,
    &normal_beam_oam_unused44,
    0x4,
};

struct frame_data long_beam_oam_forward[3] = {
    &long_beam_oam_forward1,
    0x3,
    &long_beam_oam_forward2,
    0x3,
};

struct frame_data long_beam_oam_diagonal[3] = {
    &long_beam_oam_diagonal1,
    0x3,
    &long_beam_oam_diagonal2,
    0x3,
};

struct frame_data long_beam_oam_up_down[3] = {
    &long_beam_oam_up_down1,
    0x3,
    &long_beam_oam_up_down2,
    0x3,
};

struct frame_data charged_long_beam_oam_forward[3] = {
    &charged_long_beam_oam_forward1,
    0x2,
    &charged_long_beam_oam_forward2,
    0x2,
};

struct frame_data charged_long_beam_oam_diagonal[3] = {
    &charged_long_beam_oam_diagonal1,
    0x2,
    &charged_long_beam_oam_diagonal2,
    0x2,
};

struct frame_data charged_long_beam_oam_up_down[3] = {
    &charged_long_beam_oam_up_down1,
    0x2,
    &charged_long_beam_oam_up_down2,
    0x2,
};

struct frame_data ice_beam_oam_forward[3] = {
    &ice_beam_oam_forward1,
    0x3,
    &ice_beam_oam_forward2,
    0x3,
};

struct frame_data ice_beam_oam_diagonal[3] = {
    &ice_beam_oam_diagonal1,
    0x3,
    &ice_beam_oam_diagonal2,
    0x3,
};

struct frame_data ice_beam_oam_up_down[3] = {
    &ice_beam_oam_up_down1,
    0x3,
    &ice_beam_oam_up_down2,
    0x3,
};

struct frame_data ice_beam_oam_unused1[3] = {
    &ice_beam_oam_unused11,
    0x3,
    &ice_beam_oam_unused12,
    0x3,
};

