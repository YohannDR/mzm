#ifndef SCROLL_H
#define SCROLL_H

#include "types.h"

struct scroll {
    u8 within;
    u16 x_end;
    u16 x_start;
    u16 y_start;
    u16 y_end;
};

struct current_scrolls {
    struct scroll first;
    struct scroll second;
};

void scroll_process(struct raw_coords_x pCoords);
void scroll_screen(u16 screen_x, u16 screen_y);
u16 scroll_process_x(struct scroll* pScroll, struct raw_coords_x* pCoords);
u16 scroll_process_y(struct scroll* pScroll, struct raw_coords_x* pCoords);
void scroll_load(void);
void scroll_update_current(struct raw_coords_x* pCoords);
void scroll_process_general(void);
void scroll_with_no_scrolls(struct raw_coords_x* pCoords);
void scroll_with_no_scrolls_y(struct raw_coords_x* pCoords);
void scroll_with_no_scrolls_x(struct raw_coords_x* pCoords);
void scroll_update_effect_and_haze_position(struct raw_coords_x* pCoords);
void scroll_auto_bg0(void);
u32 scroll_get_bg3_scroll(void);
void scroll_bg3(void);
void scroll_bg3_related(void);
void scroll_auto_bg3(void);
void scroll_bg2(void);
void scroll_maybe_scroll_bg1_related(struct raw_coords_x* pCoords);

#endif /* SCROLL_H */