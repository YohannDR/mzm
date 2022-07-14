#include "display.h"
#include "globals.h"
#include "gba/memory.h"

void IOWriteRegisters(void)
{

}

void IOWriteRegistersDuringTransition(void)
{

}

/**
 * 57bd8 | 74 | 
 * Updates the DISPCNT (Display Control) register
 * 
 * @param operation Operation (0 = Remove, 1 = Add)
 * @param value Value to apply
 */
void IOUpdateDISPCNT(u8 operation, u16 value)
{
    if (value != 0x0)
    {
        gWrittenToDISPCNT = read16(REG_BASE);
        if (operation)
            gDISPCNTBackup = gIORegistersBackup.dispcnt_non_gameplay | value;
        else
            gDISPCNTBackup = gIORegistersBackup.dispcnt_non_gameplay & ~value;

        if (gDISPCNTBackup != gIORegistersBackup.dispcnt_non_gameplay)
        {
            if (gWrittenToDISPCNT == gIORegistersBackup.dispcnt_non_gameplay)
                gWrittenToDISPCNT = gDISPCNTBackup;
            else
                gWrittenToDISPCNT = 0x0;

            gIORegistersBackup.dispcnt_non_gameplay = gDISPCNTBackup;
            gDISPCNTBackup = value;
        }
    }
}