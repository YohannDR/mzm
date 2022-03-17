#include "display.h"
#include "globals.h"
#include "gba/memory.h"

void unk_57a24(void)
{

}

void unk_57af8(void)
{

}

/**
 * 57bd8 | 74 | 
 * Updates the DISPCNT (Display Control) register
 * 
 * @param operation Operation (0 = Remove, 1 = Add)
 * @param value Value to apply
 */
void io_update_dispcnt(u8 operation, u16 value)
{
    if (value != 0x0)
    {
        written_to_dispcnt = read16(REG_BASE);
        if (operation)
            dispcnt_backup = io_registers_backup.dispcnt_non_gameplay | value;
        else
            dispcnt_backup = io_registers_backup.dispcnt_non_gameplay & ~value;

        if (dispcnt_backup != io_registers_backup.dispcnt_non_gameplay)
        {
            if (written_to_dispcnt == io_registers_backup.dispcnt_non_gameplay)
                written_to_dispcnt = dispcnt_backup;
            else
                written_to_dispcnt = 0x0;

            io_registers_backup.dispcnt_non_gameplay = dispcnt_backup;
            dispcnt_backup = value;
        }
    }
}