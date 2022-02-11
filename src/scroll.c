#include "scroll.h"
#include "globals.h"
#include "bg_clip.h"

void scroll_process(struct raw_coords_x pCoords)
{
    u32 screen_x;
    u32 screen_y;
    u32 new_position;
    struct scroll* pScroll;

    scroll_update_current(pCoords);
    screen_x = screen_position_and_velocity.x_position;
    screen_y = screen_position_and_velocity.y_position;

    pScroll = &current_scrolls.first;
    if (pScroll->within != FALSE)
    {
        screen_x = scroll_process_x(pScroll, pCoords);
        screen_y = scroll_process_y(pScroll, pCoords);
    }

    pScroll = &current_scrolls.second;
    if (pScroll->within != FALSE)
    {
        new_position = scroll_process_x(pScroll, pCoords);
        screen_x = (i32)(screen_x + new_position) >> 0x1;
        new_position = scroll_process_y(pScroll, pCoords);
        screen_y = (i32)(screen_y + new_position) >> 0x1;
    }

    scroll_screen((u16)screen_x, (u16)screen_y);
}

void scroll_screen(u16 screen_x, u16 screen_y)
{

}

i32 scroll_process_x(struct scroll* pScroll, struct raw_coords_x* pCoords)
{
    i32 x_pos;
    i32 x_start;

    x_pos = pCoords->x;
    x_start = pScroll->x_start;

    if (x_start + 0x1E0 <= x_pos)
        return x_start;
    else if (x_pos <= pScroll->x_end - 0x1E0)
        return x_pos - 0x1E0;
    else
        return pScroll->x_end - 0x3C0;
}

i32 scroll_process_y(struct scroll* pScroll, struct raw_coords_x* pCoords)
{
    i32 y_pos;
    i32 y_start;

    if (pScroll->within == 0x2)
    {
        y_pos = pCoords->y;
        y_start = pScroll->y_start;

        if (y_pos >= y_start + 0x180)
        {
            if (y_pos > pScroll->y_end - 0x100)
            {
                if (pScroll->y_end - 0x280 < y_start)
                    return y_start;
                return pScroll->y_end - 0x280;
            }
            else
                return y_pos - 0x180;
        }
        else
            return y_start;
    }
    else
        return pScroll->y_end - 0x280;
}

void scroll_load(void)
{

}

void scroll_update_current(struct raw_coords_x* pCoords)
{
    /*struct scroll* pScroll;
    struct scroll* pScrollLimit;
    struct background_pointers_and_dimensions* pBG;
    u8* pData;
    u16 x_pos;
    u16 y_pos;
    u32 id;
    i32 bounds[0x4];
    i32 bound;
    i32 clip_limit;
    i32 bound_limit;

    pScroll = &current_scrolls.first;
    pScrollLimit = pScroll;
    pScroll->within = FALSE;
    pScroll[0x1].within = FALSE;

    x_pos = pCoords->x >> 0x6;
    y_pos = (u16)(pCoords->y - 0x1 >> 0x6);

    id = current_room_scroll_data_pointer->id;
    pData = current_room_scroll_data_pointer->data;

    if (id != 0x0)
    {
        pBG = &bg_pointers_and_dimensions;
        while (id != 0x0)
        {
            if (pScroll == (pScrollLimit + 2))
                return;

            bounds[0x0] = 0x0;
            bounds[0x1] = 0x1;
            bounds[0x2] = 0x2;
            bounds[0x3] = 0x3;

            if (pData[0x4] != 0xFF && pData[0x7] != 0xFF)
            {
                if (pBG->clipdata_decompressed[pData[0x5] * pBG->clipdata_width + pData[0x4]] == 0x0)
                {
                    if (pData[0x6] != 0xFF)
                        bounds[pData[0x6]] = 0x7;
                }
            }
            else
            {
                if (samus_data.pose == SPOSE_USING_AN_ELEVATOR && pData[0x7] != 0xFF && (u8)(pData[0x6] - 0x2) < 0x2)
                    bounds[pData[0x6]] = 0x7;
            }

            if (pData[bounds[0x0]] <= x_pos && x_pos <= pData[bounds[0x1]] && pData[bounds[0x2]] <= y_pos && y_pos <= pData[bounds[0x3]] && pScroll->within == 0x0)
            {
                bound = pData[bounds[0x0]] << 0x6;
                if (0x80 >= bound)
                    bound = 0x80;
                pScroll->x_start = bound;

                // X end
                clip_limit = (pBG->clipdata_width << 0x6) - 0x80;
                bound_limit = (pData[bounds[0x1]] + 0x1) << 0x6;
                if (bound_limit < clip_limit)
                    bound = bound_limit;
                else
                    bound = clip_limit;
                pScroll->x_end = bound;

                bound = pData[bounds[0x2]] << 0x6;
                if (bound < 0x80)
                    bound = 0x80;
                pScroll->y_start = bound;

                // Y end
                clip_limit = (pBG->clipdata_height << 0x6) - 0x80;
                bound_limit = (pData[bounds[0x3]] + 0x1) << 0x6;
                if (bound_limit < clip_limit)
                    bound = bound_limit;
                else
                    bound = clip_limit;
                pScroll->y_end = bound;

                pScroll->within = 0x2;
                pScroll++;
            }

            pData += 0x8;
            id--;
        }
    }
    
    if (pScroll->within == FALSE && pScroll[0x1].within == FALSE)
    {
        pScroll->within = 0x0;
        pScroll->x_end = 0x0;
        pScroll->x_start = 0x0;
        pScroll->y_start = 0x0;
        pScroll->y_end = 0x0;
    }*/
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
    u32 x_scroll;

    x_scroll = scroll_get_bg3_scroll();
    x_scroll &= 0xFF;
    if (x_scroll == 0x0)
        bg3_x_position = 0x0;
    else if (x_scroll == 0x2)
        bg3_x_position = (bg1_x_position - 0x80) >> 0x1;
    else if (x_scroll == 0x3)
        bg3_x_position = (bg1_x_position - 0x80) >> 0x2;
}

void scroll_auto_bg3(void)
{
    if (bg3_movement.sub1.direction == 0x1 && (bg3_movement.sub1.counter & 0x7) == 0x0)
        bg3_movement.sub2.x_offset++;
    bg3_movement.sub1.counter++;
}

void scroll_bg2(void)
{

}

void scroll_maybe_scroll_bg1_related(struct raw_coords_x* pCoords)
{

}