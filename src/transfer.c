#include "cable_link.h"
#include "macros.h"
#include "gba.h"
#include "transfer.h"

#include "constants/transfer.h"


/**
 * @brief 8980c | ac | Process the serial transfer and the result
 * 
 * @param size Data size
 * @param pData Pointer to data to transfer
 * @return u32 Result of serial transfer update, 0 is finished, otherwise failure
 */
u32 CableLinkProcessSerialTransfer(u32 size, const u32* pData)
{
    // pData is transfer rom, size is size of transfer rom
    u32 result;
    u32 buffer;
    s32 i;

    CableLinkBackupIoRegs();

    while (TRUE)
    {
        // bits 0-1 is gCableLinkSerialTransferInfo.dataTransferStage, bits 2-3 is gCableLinkSerialTransferInfo.verifyTransferResult
        // bits 4-7 is gCableLinkSerialTransferInfo.errorDuringTransfer, bits 8+ is gCableLinkSerialTransferInfo.unk_2
        gSerialTransferUpdateResult = CableLinkUpdateSerialTransfer(1, size, pData, 0);

        // if serial transfer stopped and the correct data was transferred
        if ((gSerialTransferUpdateResult & 3) == CABLE_LINK_TRANSFER_STAGE_NO_DATA && (gSerialTransferUpdateResult & (3 << 2)) != 0)
        {
            result = 0;
            break;
        }

        if (gSerialTransferUpdateResult & (CABLE_LINK_DURING_TRANSFER_ERROR_UNK2 << 4))
        {
            result = 1;
            break;
        }

        if (gSerialTransferUpdateResult & (CABLE_LINK_DURING_TRANSFER_ERROR_VERIFY_TIMEOUT << 4))
        {
            result = 2;
            break;
        }

        if (gSerialTransferUpdateResult & (CABLE_LINK_DURING_TRANSFER_ERROR_INIT_TIMEOUT << 4))
        {
            result = 3;
            break;
        }

        if (gSerialTransferUpdateResult & (CABLE_LINK_DURING_TRANSFER_ERROR_INIT_TOO_MANY_CONNECTIONS << 4))
        {
            result = 4;
            break;
        }

        // Only reaches here if verifyTransferResult is 0, indicating it did not finish properly?
        if (gIoTransferInfo.pFunction)
            gIoTransferInfo.pFunction(); // always FileSelectProcessOAM?

        VBlankIntrWait();
    }

    // Clear gCableLinkSerialTransferInfo
    buffer = 0;
    CpuSet(&buffer, &gCableLinkSerialTransferInfo, C_32_2_16(CPU_SET_32BIT | CPU_SET_SRC_FIXED, sizeof(gCableLinkSerialTransferInfo) / sizeof(u32)));

    CableLinkRetrieveIoRegs();

    return result;
}

/**
 * @brief 898b8 | 54 | Reset data for serial transfer
 * 
 */
void CableLinkResetSerialTransfer(void)
{
    u32 buffer;

    gCableLinkUnk_30058aa = 0;
    gSerialTransferDataTimer = 0;
    gSerialTransferStartupTimer = 0;
    gCableLinkUnk_30058af = 0;
    gSerialTransferGbaDetectedCount = 0;
    gSerialTransferGbaId = 0;

    buffer = 0;
    CpuSet(&buffer, &gCableLinkSerialTransferInfo, C_32_2_16(CPU_SET_32BIT | CPU_SET_SRC_FIXED, sizeof(gCableLinkSerialTransferInfo) / sizeof(u32)));
}

/**
 * @brief 8990c | 40 | Stop serial transfer and timer 3
 * 
 */
void CableLinkStopSerialTransfer(void)
{
    // Disable timer 3 and serial interrupt
    write16(REG_IME, FALSE);
    write16(REG_IE, read16(REG_IE) & ~(IF_TIMER3 | IF_SERIAL));
    write16(REG_IME, TRUE);

    // Reset timer 3 and serial and acknowledge outstanding interrupt requests
    write16(REG_SIO, 0);
    write16(REG_TM3CNT_H, 0);
    write16(REG_IF, IF_TIMER3 | IF_SERIAL);
}

/**
 * @brief 8994c | 58 | Initialize serial transfer
 * 
 */
void CableLinkInitializeSerialTransfer(void)
{
    // Disable timer 3 and serial interrupt
    write16(REG_IME, FALSE);
    write16(REG_IE, read16(REG_IE) & ~(IF_TIMER3 | IF_SERIAL));
    write16(REG_IME, TRUE);

    write16(REG_RNCT, 0);
    write16(REG_SIO, SIO_MULTI_MODE);

    // Baud rate = 115200 bits per second, request interrupt upon completion
    write16(REG_SIO, read16(REG_SIO) | SIO_BAUD_RATE_115200 | SIO_IRQ_ENABLE);

    // Enable serial port interrupt
    write16(REG_IME, FALSE);
    write16(REG_IE, read16(REG_IE) | IF_SERIAL);
    write16(REG_IME, TRUE);
}

/**
 * @brief 899a4 | 24 | Set serial transfer to normal 32 bit transfer and set serial out to not ready
 * 
 */
void CableLinkSetNormalSerialWait(void)
{
    write16(REG_RNCT, 0);
    write16(REG_SIO, SIO_32BIT_MODE | SIO_IRQ_ENABLE); // Bit 12 is 1 and Bit 13 is 0, so SIO is normal mode? If so, then transfer mode is 32 bits. Request interrupt when done
    write16(REG_SIO, read16(REG_SIO) | SIO_HIGH_DURING_INACTIVITY); // Output is high during inactivity
}

/**
 * @brief 899c8 | 174 | Update the serial transfer
 * 
 * @param param_1 Unused
 * @param Size Data size
 * @param pData Pointer to data to transfer
 * @param param_3 Unused
 * @return u16 Bits 0-1 is dataTransferStage, bits 2-3 is verifyTransferResult, bits 4-7 is errorDuringTransfer, bits 8+ is unk_2
 */
u16 CableLinkUpdateSerialTransfer(u32 param_1, u32 size, const u32* pData, u32 param_3)
{
    // pData is transfer rom, size is size of transfer rom
    switch (gCableLinkSerialTransferInfo.stage)
    {
        case CABLE_LINK_SERIAL_TRANSFER_STAGE_INIT:
            // Clear and set up transfer
            CableLinkResetSerialTransfer();
            CableLinkInitializeSerialTransfer();
            gCableLinkSerialTransferInfo.dataTransferStage = CABLE_LINK_TRANSFER_STAGE_INIT_DATA;
            gCableLinkSerialTransferInfo.stage = CABLE_LINK_SERIAL_TRANSFER_STAGE_SETUP_CONNECTION;
            break;

        case CABLE_LINK_SERIAL_TRANSFER_STAGE_SETUP_CONNECTION:
            if (CableLinkIsGbaParent(TRUE))
                CableLinkStartSerialTransfer();

            if (gCableLinkSerialTransferInfo.errorDuringTransfer != CABLE_LINK_DURING_TRANSFER_ERROR_NONE)
                gCableLinkSerialTransferInfo.stage = CABLE_LINK_SERIAL_TRANSFER_STAGE_TERMINATE_CONNECTION;

            APPLY_DELTA_TIME_INC(gSerialTransferStartupTimer);
            // If more than half a second passes, fail
            if (gSerialTransferStartupTimer > CONVERT_SECONDS(.5f))
            {
                gCableLinkSerialTransferInfo.errorDuringTransfer = CABLE_LINK_DURING_TRANSFER_ERROR_INIT_TIMEOUT;
                gCableLinkSerialTransferInfo.stage = CABLE_LINK_SERIAL_TRANSFER_STAGE_TERMINATE_CONNECTION;
            }
            break;

        case CABLE_LINK_SERIAL_TRANSFER_STAGE_SETUP_DATA:
            // Set up transmission for size of data to transfer?
            CableLinkSetNormalSerialWait();
            CableLinkLoadDataAndSizeToTransfer(size, pData, param_3);
            gCableLinkSerialTransferInfo.stage = CABLE_LINK_SERIAL_TRANSFER_STAGE_TRANSFER_DATA;

        case CABLE_LINK_SERIAL_TRANSFER_STAGE_TRANSFER_DATA:
            if (gCableLinkSerialTransferInfo.dataTransferStage == CABLE_LINK_TRANSFER_STAGE_SENDING_DATA)
                break;

            if (gCableLinkSerialTransferInfo.isParent)
            {
                APPLY_DELTA_TIME_INC(gSerialTransferDataTimer);
                if (gSerialTransferDataTimer >= CONVERT_SECONDS(1.f / 6))
                {
                    CableLinkStartSerialTransfer();
                    gCableLinkSerialTransferInfo.dataTransferStage = CABLE_LINK_TRANSFER_STAGE_SENDING_DATA;
                    break;
                }
            }
            
            CableLinkStartSerialTransfer();
            gCableLinkSerialTransferInfo.dataTransferStage = CABLE_LINK_TRANSFER_STAGE_SENDING_DATA;
            break;

        case CABLE_LINK_SERIAL_TRANSFER_STAGE_SETUP_VERIFICATION:
            CableLinkInitializeSerialTransfer();
            gCableLinkSerialTransferInfo.stage = CABLE_LINK_SERIAL_TRANSFER_STAGE_VERIFY_DATA;
            break;

        case CABLE_LINK_SERIAL_TRANSFER_STAGE_VERIFY_DATA:
            if (gCableLinkSerialTransferInfo.isParent == TRUE && gSerialTransferDataTimer >= CONVERT_SECONDS(1.f / 6))
                CableLinkStartSerialTransfer();

            APPLY_DELTA_TIME_INC(gSerialTransferDataTimer);
            if (gSerialTransferDataTimer > CONVERT_SECONDS(.5f))
            {
                gCableLinkSerialTransferInfo.errorDuringTransfer = CABLE_LINK_DURING_TRANSFER_ERROR_VERIFY_TIMEOUT;
                gCableLinkSerialTransferInfo.stage = CABLE_LINK_SERIAL_TRANSFER_STAGE_TERMINATE_CONNECTION;
            }
            break;

        case CABLE_LINK_SERIAL_TRANSFER_STAGE_TERMINATE_CONNECTION:
            if (gCableLinkSerialTransferInfo.dataTransferStage != CABLE_LINK_TRANSFER_STAGE_NO_DATA)
            {
                CableLinkStopSerialTransfer();
                gCableLinkSerialTransferInfo.dataTransferStage = CABLE_LINK_TRANSFER_STAGE_NO_DATA;
            }
            break;
    }

    gCableLinkSerialTransferInfo.unk_2 = gCableLinkSerialTransferInfo.dataCursor * 100 / gCableLinkSerialTransferInfo.dataSizeInt;

    return gCableLinkSerialTransferInfo.dataTransferStage | gCableLinkSerialTransferInfo.verifyTransferResult << 2 | gCableLinkSerialTransferInfo.errorDuringTransfer << 4 | gCableLinkSerialTransferInfo.unk_2 << 8;
}

/**
 * @brief 89b3c | 34 | Determine if all GBA's are ready and the GBA is the parent or child
 * 
 * @param wantParent Is parent or child GBA possibly updated
 * @return u16 bool Is GBA parent
 */
u16 CableLinkIsGbaParent(u8 wantParent)
{
    u16 isParent;
    // If all GBA's are ready and is currently the parent GBA
    if ((read32(REG_SIO) & (SIO_MULTI_CONNECTION_READY | SIO_MULTI_RECEIVE_ID)) == (SIO_MULTI_CONNECTION_READY | SIO_MULTI_PARENT) && wantParent)
    {
        isParent = gCableLinkSerialTransferInfo.isParent = TRUE;
    }
    else
    {
        isParent = gCableLinkSerialTransferInfo.isParent = FALSE;
    }
    return isParent;
}

/**
 * @brief 89b70 | 30 | Initialize data to copy and load the size of the data to transmit and load timer 3
 * 
 * @param size Data size
 * @param pData Pointer to data to transfer
 */
void CableLinkLoadDataAndSizeToTransfer(u32 size, const u32* pData, u32 param_3)
{
    write16(REG_SIO, read16(REG_SIO) | SIO_SHIFT_CLOCK); // shift clock is internal, indicating parent
    
    gCableLinkSerialTransferInfo.pData = pData;
    write32(REG_SIO_MULTI, size); // transmit the size of data to transfer?

    gCableLinkSerialTransferInfo.dataSizeInt = (size / sizeof(u32)) + 1; // 32740 / 4 + 1 = 8186

    CableLinkInitializeTimer3();
}

/**
 * @brief 89ba0 | 34 | Load timer 3 with -101
 * 
 */
void CableLinkInitializeTimer3(void)
{
    // Load -101 into timer 3 (what is -101?)
    write16(REG_TM3CNT_L, -101);
    write16(REG_TM3CNT_H, TIMER_CONTROL_IRQ_ENABLE);

    // Enable timer 3 interrupt
    write16(REG_IME, FALSE);
    write16(REG_IE, read16(REG_IE) | IF_TIMER3);
    write16(REG_IME, TRUE);
}

/**
 * @brief 89bd4 | 10 | Initialize timer 3 and start serial transfer
 * 
 */
void CableLinkBeginTransferWithTimer3(void)
{
    CableLinkStopAndReloadTimer3();
    CableLinkStartSerialTransfer();
}

/**
 * @brief 89be4 | 180 | Transfer data over serial
 * 
 */
void CableLinkSerialTransferExchangeData(void)
{
    // Called when serial communication interrupt 
    u16 recv[4];
    u32 control;
    u16 i;
    u16 numGbaDetected;
    u16 numGbaSendingData;

    control = read32(REG_SIO);

    switch (gCableLinkSerialTransferInfo.stage)
    {
        case CABLE_LINK_SERIAL_TRANSFER_STAGE_SETUP_CONNECTION:
            write16(REG_SIO_DATA8, TRANSFER_HANDSHAKE); // Outgoing data
            write64(recv, *(vu64 *)REG_SIO_MULTI);

            i = 0;
            numGbaDetected = 0;
            numGbaSendingData = 0;

            for (; i < ARRAY_SIZE(recv); i++)
            {
                // if GBA either sent or is receiving data
                if (recv[i] == TRANSFER_HANDSHAKE)
                    numGbaDetected++;
                // if receiving some data
                else if (recv[i] != USHORT_MAX)
                    numGbaSendingData++;
            }

            gSerialTransferGbaDetectedCount = numGbaDetected;
            gSerialTransferGbaId = (control << 26) >> 30; // bits 4 and 5 of REG_SIO, which is multiplayer ID

            // If 0-2 GBA's detected
            if (numGbaDetected <= 2)
            {
                // If 2 GBA's detected and not sending anymore data
                if (numGbaDetected >= 2 && numGbaSendingData == 0)
                    gCableLinkSerialTransferInfo.stage = CABLE_LINK_SERIAL_TRANSFER_STAGE_SETUP_DATA;
            }
            else
                gCableLinkSerialTransferInfo.errorDuringTransfer = CABLE_LINK_DURING_TRANSFER_ERROR_INIT_TOO_MANY_CONNECTIONS;
            break;

        case CABLE_LINK_SERIAL_TRANSFER_STAGE_TRANSFER_DATA:
            read32(REG_SIO_MULTI); // why the read?

            // If data still left to transfer
            if (gCableLinkSerialTransferInfo.dataCursor < gCableLinkSerialTransferInfo.dataSizeInt)
            {
                // Transfer current byte and update checksum
                write32(REG_SIO_MULTI, gCableLinkSerialTransferInfo.pData[gCableLinkSerialTransferInfo.dataCursor]);
                gCableLinkSerialTransferInfo.dataChecksum += gCableLinkSerialTransferInfo.pData[gCableLinkSerialTransferInfo.dataCursor];
            }
            // If data all transferred
            else if (gCableLinkSerialTransferInfo.dataCursor == gCableLinkSerialTransferInfo.dataSizeInt)
            {
                // Transfer checksum
                write32(REG_SIO_MULTI, gCableLinkSerialTransferInfo.dataChecksum);
            }
            // Sanity check to make sure more data than available not transferred?
            else
            {
                write32(REG_SIO_MULTI, 0);
            }

            gCableLinkSerialTransferInfo.dataCursor++;

            // Continue timer if still data to transfer (extra time for each GBA active?)
            if (gCableLinkSerialTransferInfo.dataCursor < gCableLinkSerialTransferInfo.dataSizeInt + gSerialTransferGbaDetectedCount)
            {
                write16(REG_TM3CNT_H, read16(REG_TM3CNT_H) | TIMER_CONTROL_ACTIVE);
            }
            else
            {
                gCableLinkSerialTransferInfo.stage = CABLE_LINK_SERIAL_TRANSFER_STAGE_SETUP_VERIFICATION;
                gSerialTransferDataTimer = 0;
            }
            break;

        case CABLE_LINK_SERIAL_TRANSFER_STAGE_VERIFY_DATA:
            write64(recv, *(vu64 *)REG_SIO_MULTI);

            i = 1; // start from GBA receiving data?
            numGbaDetected = 1;

            for (i; i < gSerialTransferGbaDetectedCount; i++)
            {
                // if child GBA 1 correctly sends 1
                if (recv[i] == 1)
                    numGbaDetected++;
                // if another child GBA sends 1 (this shouldn't happen?)
                else if (recv[i] == 2)
                {
                    gCableLinkSerialTransferInfo.verifyTransferResult = 2;
                    gCableLinkSerialTransferInfo.stage = CABLE_LINK_SERIAL_TRANSFER_STAGE_TERMINATE_CONNECTION;
                    break;
                }

                // Check if correct number of GBA's sent correct data
                if (numGbaDetected == gSerialTransferGbaDetectedCount)
                {
                    gCableLinkSerialTransferInfo.verifyTransferResult = 1;
                    gCableLinkSerialTransferInfo.stage = CABLE_LINK_SERIAL_TRANSFER_STAGE_TERMINATE_CONNECTION;
                }
            }
            break;
    }
}

/**
 * @brief 89d64 | 10 | Start a serial transfer by setting the start bit of the SIO control register
 * 
 */
void CableLinkStartSerialTransfer(void)
{
    write16(REG_SIO, read16(REG_SIO) | SIO_START_BIT_ACTIVE);
}

/**
 * @brief 89d74 | 24 | Stop and reload timer 3 with -101
 * 
 */
void CableLinkStopAndReloadTimer3(void)
{
    write16(REG_TM3CNT_H, read16(REG_TM3CNT_H) & ~TIMER_CONTROL_ACTIVE);
    write16(REG_TM3CNT_L, -101);
}

/**
 * @brief 89d98 | 54 | Makes a backup of the SIO related registers
 * 
 */
void CableLinkBackupIoRegs(void)
{
    gRegIme_Backup = read16(REG_IME);
    gRegIe_Backup = read16(REG_IE);
    gRegTm3Cnt_H_Backup = read16(REG_TM3CNT_H);
    gRegSiocnt_Backup = read16(REG_SIO);
    gRegRcnt_Backup = read16(REG_RNCT);
}

/**
 * @brief 89dec | 44 | Retrieves the SIO related registers from the backups
 * 
 */
void CableLinkRetrieveIoRegs(void)
{
    write16(REG_IME, gRegIme_Backup);
    write16(REG_IE, gRegIe_Backup);
    write16(REG_TM3CNT_H, gRegTm3Cnt_H_Backup);
    write16(REG_SIO, gRegSiocnt_Backup);
    write16(REG_RNCT, gRegRcnt_Backup);
}
