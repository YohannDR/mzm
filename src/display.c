#include "display.h"
#include "gba.h"

#include "structs/display.h"
#include "structs/color_effects.h"

/**
 * @brief 57a24 | d4 | Writes to the IO registers using the WrittenToXXX globals
 * 
 */
void IoWriteRegisters(void)
{
    if (gWrittenToDISPCNT)
    {
        write16(REG_DISPCNT, gWrittenToDISPCNT);
        gWrittenToDISPCNT = 0;
    }

    if (gWrittenToBLDALPHA)
    {
        write16(REG_BLDALPHA, gWrittenToBLDALPHA);
        gWrittenToBLDALPHA = 0;
    }

    if (gWrittenToBLDY >= 0)
    {
        write16(REG_BLDY, gWrittenToBLDY);
        gWrittenToBLDY = -1;
    }

    if (gWrittenToWININ_H)
    {
        write8(REG_WININ + 1, gWrittenToWININ_H);
        gWrittenToWININ_H = 0;
    }

    if (gWrittenToWINOUT_L)
    {
        write8(REG_WINOUT, gWrittenToWINOUT_L);
        gWrittenToWINOUT_L = 0;
    }

    if (gWrittenToWIN1H | gWrittenToWIN1V)
    {
        write16(REG_WIN1H, gWrittenToWIN1H);
        write16(REG_WIN1V, gWrittenToWIN1V);
        gWrittenToWIN1H = 0;
        gWrittenToWIN1V = 0;
    }

    if (gWrittenToBLDCNT)
    {
        write16(REG_BLDCNT, gWrittenToBLDCNT);
        gWrittenToBLDCNT = 0;
    }

    CheckTransferFadedPalette();
    AnimatedGraphicsTransfer();
}

/**
 * @brief 57af8 | e0 | Writes to the IO registers using the WrittenToXXX globals during a transition
 * 
 */
void IoWriteRegistersDuringTransition(void)
{
    if (gWrittenToDISPCNT)
    {
        write16(REG_DISPCNT, gWrittenToDISPCNT);
        gWrittenToDISPCNT = 0;
    }

    if (gWrittenToBLDALPHA)
    {
        write16(REG_BLDALPHA, gWrittenToBLDALPHA);
        gWrittenToBLDALPHA = 0;
    }

    if (gWrittenToWININ_H)
    {
        write8(REG_WININ + 1, gWrittenToWININ_H);
        gWrittenToWININ_H = 0;
    }

    if (gWrittenToWINOUT_L)
    {
        write8(REG_WINOUT, gWrittenToWINOUT_L);
        gWrittenToWINOUT_L = 0;
    }

    if (gWrittenToWIN1H | gWrittenToWIN1V)
    {
        write16(REG_WIN1H, gWrittenToWIN1H);
        write16(REG_WIN1V, gWrittenToWIN1V);
        gWrittenToWIN1H = 0;
        gWrittenToWIN1V = 0;
    }

    if (gWrittenToBLDCNT)
    {
        write16(REG_BLDCNT, gWrittenToBLDCNT);
        gWrittenToBLDCNT = 0;
    }

    if (gBg1CntDuringDoorTransition)
    {
        write16(REG_BG1CNT, gBg1CntDuringDoorTransition);
        gBg1CntDuringDoorTransition = 0;
    }

    if (gBg3CntDuringDoorTransition)
    {
        write16(REG_BG3CNT, gBg3CntDuringDoorTransition);
        gBg3CntDuringDoorTransition = 0;
    }

    CheckTransferFadedPalette();
    AnimatedGraphicsTransfer();
}

/**
 * 57bd8 | 74 | Updates the DISPCNT (Display Control) register
 * 
 * @param operation Operation (0 = Remove, 1 = Add)
 * @param value Value to apply
 */
void IoUpdateDISPCNT(u8 operation, u16 value)
{
    if (value != 0)
    {
        gWrittenToDISPCNT = read16(REG_BASE);
        if (operation)
            gDISPCNTBackup = gIoRegistersBackup.Dispcnt_NonGameplay | value;
        else
            gDISPCNTBackup = gIoRegistersBackup.Dispcnt_NonGameplay & ~value;

        if (gDISPCNTBackup != gIoRegistersBackup.Dispcnt_NonGameplay)
        {
            if (gWrittenToDISPCNT == gIoRegistersBackup.Dispcnt_NonGameplay)
                gWrittenToDISPCNT = gDISPCNTBackup;
            else
                gWrittenToDISPCNT = 0;

            gIoRegistersBackup.Dispcnt_NonGameplay = gDISPCNTBackup;
            gDISPCNTBackup = value;
        }
    }
}