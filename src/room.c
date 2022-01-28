#include "room.h"
#include "memory.h"

void room_load(void)
{

}

void room_load_tileset(void)
{

}

void room_load_entry(void)
{

}

void room_load_backgrounds(void)
{

}

void room_remove_never_reform_blocks_and_collected_tanks(void)
{
	// remove_never_reform_blocks();
	// remove_collected_tanks();
}

void room_reset(void)
{

}

void room_set_background_scrolling(void)
{

}

void room_maybe_set_initial_tilemap(u8 bg_number)
{

}

u8 room_rle_decompress(u8 mode, u8* src, u8* dst)
{
    u32 len;
    u8* dest;
    u8* unk;
    u8* unk2;
    u8 unk3;
    u16 unk4;
    u32 i;

    len = 0x3000;
    if (mode == 0x0)
    {
        src++;
        len = 0x2000;
    }
    bit_fill(0x3, 0x0, dst, len, 0x10);

    len = 0x0;
    do {
        dest = dst;
        if (len != 0x0)
            dest = dst + 0x1;
        unk = src + 0x1;
        if (*src == 0x1)
        {
            unk3 = *unk;
            src += 0x2;
            while (i = unk3, i != 0x0)
            {
                if ((unk3 & 0x80) == 0x0)
                {
                    for (; i != 0x0; i--)
                    {
                        *dest = *src;
                        src++;
                        dst += 0x2;
                    }
                }
                else
                {
                    i &= 0x7F;
                    if (*src == 0x0)
                        dest = dest + (i * 0x2);
                    else
                    {
                        for (; i != 0x0; i--)
                        {
                            *dest = *src;
                            dest += 0x2;
                        }
                    }
                    src++;
                }
                unk3 = *src;
                src++;
            }
        }
        else
        {
            unk = src + 0x2;
            src += 0x3;
            unk4 = (*unk << 0x8 | *unk2);
            while (i = unk4, i != 0x0)
            {
                if ((unk4 & 0x8000) == 0x0)
                {
                    for (; i != 0x0; i--)
                    {
                        *dest = *src;
                        src++;
                        dest += 0x2;
                    }
                }
                else
                {
                    i &= 0x7FFF;
                    if (*src == 0x0)
                        dest = dest + (i * 0x2);
                    else
                    {
                        if ((unk4 & 0x7FFF) != 0x0)
                        {
                            do {
                                *dest = *src;
                                dest += 0x2;
                                i--;
                            } while(i != 0x0);
                        }
                    }
                    src++;
                }
                unk3 = *src;
                unk = src + 0x1;
                src += 0x2;
                unk4 = (unk3 << 0x8 | *unk);
            }
        }
        len++;
    } while (len < 0x2);
    return 0x0;
}

void room_unk56e28(void)
{

}

void room_maybe_check_update_animated_graphics_palette(void)
{

}

void room_unk56ef4(void)
{

}

void room_update(void)
{

}

void room_update_backgrounds_position(void)
{

}

void room_maybe_update_vertical_tilemap(u8 unk)
{

}

void room_maybe_update_horizontal_tilemap(u8 unk)
{

}