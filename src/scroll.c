#include "scroll.h"
#include "globals.h"

void scroll_process(struct raw_coords_x pCoords)
{

}

void scroll_screen(u16 screen_x, u16 screen_y)
{

}

u16 scroll_process_x(struct scroll* pScroll, struct raw_coords_x* pCoords)
{

}

u16 scroll_process_y(struct scroll* pScroll, struct raw_coords_x* pCoords)
{

}

void scroll_load(void)
{

}

void scroll_update_current(struct raw_coords_x* pCoords)
{

}

void scroll_process_general(void)
{

}

void scroll_with_no_scrolls(struct raw_coords_x* pCoords)
{
    scroll_with_no_scrolls_x(pCoords);
    scroll_with_no_scrolls_y(pCoords);
}

void scroll_with_no_scrolls_y(struct raw_coords_x* pCoords)
{

}

void scroll_with_no_scrolls_x(struct raw_coords_x* pCoords)
{

}

void scroll_update_effect_and_haze_position(struct raw_coords_x* pCoords)
{

}

void scroll_auto_bg0(void)
{

}

u32 scroll_get_bg3_scroll(void)
{
    u32 x_scroll;
    u32 y_scroll;

    y_scroll = 0x0;
    x_scroll = 0x0;

    switch (current_room_entry.bg3_scrolling)
    {
        case 0x0:
            break;

        case 0x1:
            x_scroll = 0x2;
            y_scroll = 0x0;
            break;

        case 0x2:
            x_scroll = 0x0;
            y_scroll = 0x2;
            break;

        case 0x3:
            x_scroll = 0x2;
            y_scroll = 0x2;
            break;

        case 0x4:
            x_scroll = 0x1;
            y_scroll = 0x2;
            break;

        case 0x5:
            x_scroll = 0x2;
            y_scroll = 0x1;
            break;

        case 0x6:
        case 0xA:
            x_scroll = 0x1;
            y_scroll = 0x1;
            break;
        
        case 0x9:
            x_scroll = 0x3;
            y_scroll = 0x0;
            break;

        case 0x7:
            x_scroll = 0x1;
            y_scroll = 0x0;
    }

    return y_scroll << 0x10 | x_scroll;
}

void scroll_bg3(void)
{

}

void scroll_bg3_related(void)
{

}

void scroll_auto_bg3(void)
{

}

void scroll_bg2(void)
{

}

void scroll_maybe_scroll_bg1_related(struct raw_coords_x* pCoords)
{

}