#include "display.h"
#include "gba.h"
#include "structs/display.h"

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
            gDISPCNTBackup = gIoRegistersBackup.DISPCNT_NonGameplay | value;
        else
            gDISPCNTBackup = gIoRegistersBackup.DISPCNT_NonGameplay & ~value;

        if (gDISPCNTBackup != gIoRegistersBackup.DISPCNT_NonGameplay)
        {
            if (gWrittenToDISPCNT == gIoRegistersBackup.DISPCNT_NonGameplay)
                gWrittenToDISPCNT = gDISPCNTBackup;
            else
                gWrittenToDISPCNT = 0x0;

            gIoRegistersBackup.DISPCNT_NonGameplay = gDISPCNTBackup;
            gDISPCNTBackup = value;
        }
    }
}