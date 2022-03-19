#ifndef SCROLL_H
#define SCROLL_H

#include "types.h"

struct Scroll {
    u8 within;
    u16 x_end;
    u16 x_start;
    u16 y_start;
    u16 y_end;
};

struct ScreenPositionAndVelocity {
    u16 x_position;
    u16 y_position;
    i8 x_velocity;
    i8 y_velocity;
};

void scroll_process(struct RawCoordsX* pCoords);
void scroll_screen(u16 screen_x, u16 screen_y);
i32 scroll_process_x(struct Scroll* pScroll, struct RawCoordsX* pCoords);
i32 scroll_process_y(struct Scroll* pScroll, struct RawCoordsX* pCoords);
void scroll_load(void);
void scroll_update_current(struct RawCoordsX* pCoords);
void scroll_process_general(void);
void scroll_with_no_scrolls(struct RawCoordsX* pCoords);
void scroll_with_no_scrolls_y(struct RawCoordsX* pCoords);
void scroll_with_no_scrolls_x(struct RawCoordsX* pCoords);
void scroll_update_effect_and_haze_position(struct RawCoordsX* pCoords);
void scroll_auto_bg0(void);
u32 scroll_get_bg3_scroll(void);
void scroll_bg3(void);
void scroll_bg3_related(void);
void scroll_auto_bg3(void);
void scroll_bg2(void);
void scroll_maybe_scroll_bg1_related(struct RawCoordsX* pCoords);

#endif /* SCROLL_H */