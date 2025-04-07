#include "cable_link.h"
#include "macros.h"
#include "gba.h"
#include "link.h"

#include "data/cable_link_data.h"
#include "data/io_transfer_data.h"

#include "constants/cable_link.h"

#include "structs/game_state.h"
#include "structs/link.h"


/**
 * @brief 89e30 | 164 | Handle transfer of fusion gallery images
 * 
 * @return u8 The result of the transfer
 */
u8 FusionGalleryLinkProcess(void)
{
    u16 buffer;
    u16* ptr;

    gIoTransferInfo.result = TRANSFER_RESULT_NONE;
    APPLY_DELTA_TIME_INC(gIoTransferInfo.timer);

    switch (gIoTransferInfo.linkStage)
    {
        case LINK_STAGE_INIT:
            ptr = &buffer;
            buffer = 0;
            DMA_SET(3, ptr, gSendCmd, C_32_2_16(DMA_ENABLE | DMA_SRC_FIXED, CMD_LENGTH));

            buffer = 0;
            DMA_SET(3, ptr, gRecvCmds, C_32_2_16(DMA_ENABLE | DMA_SRC_FIXED, ARRAY_SIZE(gRecvCmds) * ARRAY_SIZE(gRecvCmds[0])));

            gErrorFlag = 0;
            gShouldAdvanceLinkState = 0;
            gLinkPlayerCount = 0;
            gLinkLocalId = 0;
            gLinkUnkFlag9 = 0;

            CallbackSetSerialCommunication(SerialCB);
            CallbackSetTimer3(Timer3Intr);

            ResetSerial();

            gIoTransferInfo.command = LINKCMD_5500;
            gIoTransferInfo.language = -1;
            gIoTransferInfo.fusionGalleryImages = -1;
            gIoTransferInfo.errorFlag = 0;
            gIoTransferInfo.timer = 0;
            gIoTransferInfo.linkStage++;
            break;

        case LINK_STAGE_PROCESS_CONNECTION:
            if (!gIoTransferInfo.linkInProgress)
            {
                DisableSerial();
                if (gIoTransferInfo.command == LINKCMD_3300)
                    gIoTransferInfo.linkStage = LINK_STAGE_RECEIVED_GALLERY;
                else if (gIoTransferInfo.errorFlag)
                    gIoTransferInfo.linkStage = LINK_STAGE_ERROR0;
                else
                    gIoTransferInfo.linkStage = LINK_STAGE_ERROR1;
            }
            else
            {
                HandleLinkConnection();
                if (gIoTransferInfo.command == LINKCMD_3300 || gIoTransferInfo.errorFlag != 0)
                    gIoTransferInfo.linkInProgress = 0;
                else if (gIoTransferInfo.timer > CONVERT_SECONDS(3.f))
                    gIoTransferInfo.linkInProgress = gIoTransferInfo.errorFlag;
            }
            break;

        case LINK_STAGE_RECEIVED_GALLERY:
            gFileScreenOptionsUnlocked.fusionGalleryImages = gIoTransferInfo.fusionGalleryImages;
            gIoTransferInfo.result = TRANSFER_RESULT_SUCCESS;
            break;

        case LINK_STAGE_ERROR0:
        case LINK_STAGE_ERROR1:
            gIoTransferInfo.result = TRANSFER_RESULT_FAILURE;
            break;

        case LINK_STAGE_UNK5:
            break;
    }

    return gIoTransferInfo.result;
}

/**
 * @brief 89f94 | 198 | Handle connection, sending/receiving commands, and errors
 * 
 * @return u8* Garbage, contains no value/undefined behavior
 */
u8* HandleLinkConnection(void)
{
    vu32 c;
    u32* link_stat;
    
    gShouldAdvanceLinkState = gFrameCounter8Bit & 1;
    link_stat = &gErrorFlag;
    *link_stat = LinkMain(&gShouldAdvanceLinkState, gSendCmd, gRecvCmds);
    gLinkLocalId = *link_stat & CABLE_LINK_STAT_LOCAL_ID;
    gLinkPlayerCount = (*link_stat & (7 << CABLE_LINK_STAT_SHIFT_PLAYER_COUNT)) >> CABLE_LINK_STAT_SHIFT_PLAYER_COUNT;
    gLinkUnkFlag9 = (*link_stat & (7 << CABLE_LINK_STAT_SHIFT_UNK_FLAG_9)) >> CABLE_LINK_STAT_SHIFT_UNK_FLAG_9;

    if (*link_stat & CABLE_LINK_STAT_CONN_ESTABLISHED)
    {
        gIoTransferInfo.timer = 0;
        BuildSendCmd(gIoTransferInfo.command);
        ProcessRecvCmds();
    }

    if (*link_stat & CABLE_LINK_ERROR_ID_OVER)
    {
        gIoTransferInfo.errorFlag |= 1;
        CableLinkDrawErrorStr(sErrorString_IdOver, VRAM_BASE + 0xE304, 12);
    }

    if (*link_stat & CABLE_LINK_ERROR_CHECKSUM)
    {
        gIoTransferInfo.errorFlag |= 2;
        CableLinkDrawErrorStr(sErrorString_ChecksumError, VRAM_BASE + 0xE344, 12);
    }

    if (*link_stat & CABLE_LINK_ERROR_HARDWARE)
    {
        gIoTransferInfo.errorFlag |= 4;
        CableLinkDrawErrorStr(sErrorString_HardwareError, VRAM_BASE + 0xE384, 12);
    }

    if (*link_stat & CABLE_LINK_ERROR_SEND_OVERFLOW)
    {
        gIoTransferInfo.errorFlag |= 8;
        CableLinkDrawErrorStr(sErrorString_SendOverflow, VRAM_BASE + 0xE3C4, 12);
    }

    if (*link_stat & CABLE_LINK_ERROR_RECEIVE_OVERFLOW)
    {
        gIoTransferInfo.errorFlag |= 16;
        CableLinkDrawErrorStr(sErrorString_ReceiveOverflow, VRAM_BASE + 0xE404, 12);
    }

    if (*link_stat & CABLE_LINK_ERROR_SIO_INTERNAL)
    {
        gIoTransferInfo.errorFlag |= 32;
        CableLinkDrawErrorStr(sErrorString_SioInternal, VRAM_BASE + 0xE444, 12);
    }

    if (*link_stat & CABLE_LINK_ERROR_SIO_STOP)
    {
        gIoTransferInfo.errorFlag |= 64;
        CableLinkDrawErrorStr(sErrorString_SioStop, VRAM_BASE + 0xE484, 12);
    }
}

/**
 * @brief 8a12c | a8 | Input commands into the send queue
 * 
 * @param command The command to send
 */
void BuildSendCmd(u16 command)
{
    u32 value;
    
    switch (command)
    {
        case LINKCMD_8800:
            gSendCmd[0] |= command;
            gSendCmd[1] = gButtonInput;

            // Buffer overflow
            value = gChangedInput;
            gSendCmd[3] = gLanguage;
            gSendCmd[2] = value;
            break;

        case LINKCMD_5500:
            gSendCmd[0] |= command;
            gSendCmd[1] = gLanguage;
            break;

        case LINKCMD_4400:
            gSendCmd[0] |= command;
            gSendCmd[1] = 0;
            break;

        case LINKCMD_2200:
            gSendCmd[0] |= command;
            gSendCmd[1] = 1;
            break;
    }
}

/**
 * @brief 8a1d4 | 8c | Process commands from the receive queue
 */
void ProcessRecvCmds(void)
{
    u8 var;

    if (gErrorFlag & CABLE_LINK_STAT_RECEIVED_NOTHING)
        return;

    if (gRecvCmds[0][1] == LINKCMD_5500)
    {
        gIoTransferInfo.language = gRecvCmds[1][1];
        if (gIoTransferInfo.language == gLanguage)
            gIoTransferInfo.command = LINKCMD_4400;
    }

    if (gRecvCmds[0][1] == LINKCMD_6600)
    {
        gIoTransferInfo.fusionGalleryImages = gRecvCmds[1][1];

        var = gIoTransferInfo.fusionGalleryImages - 1;
        if (var < 3)
        {
            gIoTransferInfo.command = LINKCMD_2200;
        }
        else
        {
            gIoTransferInfo.command = 0;
            gIoTransferInfo.result = TRANSFER_RESULT_SUCCESS2;
        }
    }

    if (gRecvCmds[0][1] == LINKCMD_3300)
        gIoTransferInfo.command = LINKCMD_3300;
}

/**
 * @brief 8a260 | 68 | Disable serial transfer
 * 
 */
void DisableSerial(void)
{
    u32 buffer;

    gLinkSavedIme = read16(REG_IME);
    write16(REG_IME, FALSE);
    write16(REG_IE, read16(REG_IE) & ~(IF_TIMER3 | IF_SERIAL));
    write16(REG_IME, gLinkSavedIme);

    write16(REG_SIO, SIO_MULTI_MODE);
    write16(REG_TM3CNT_H, 0);
    write16(REG_IF, IF_TIMER3 | IF_SERIAL);

    buffer = 0;
    CpuSet(&buffer, &gCableLinkInfo, C_32_2_16(CPU_SET_32BIT | CPU_SET_SRC_FIXED, sizeof(gCableLinkInfo) / sizeof(u32)));
}

/**
 * @brief 8a2c8 | D4 | Enable serial transfer
 */
void EnableSerial(void)
{
    u32 buffer;
    u32* ptr;

    // Disable Interrupts
    gLinkSavedIme = read16(REG_IME);
    write16(REG_IME, FALSE);
    write16(REG_IE, read16(REG_IE) & ~(IF_TIMER3 | IF_SERIAL));
    write16(REG_IME, gLinkSavedIme);

    write16(REG_RNCT, 0);
    write16(REG_SIO, SIO_MULTI_MODE);
    write16(REG_SIO, read16(REG_SIO) | SIO_BAUD_RATE_115200 | SIO_IRQ_ENABLE);

    // Enable Interrupts
    gLinkSavedIme = read16(REG_IME);
    write16(REG_IME, FALSE);
    write16(REG_IE, read16(REG_IE) | IF_SERIAL);
    write16(REG_IME, gLinkSavedIme);

    write16(REG_SIO_DATA8, 0);
    write64(REG_SIO_MULTI, 0);

    buffer = 0;
    CpuSet(&buffer, &gCableLinkInfo, C_32_2_16(CPU_SET_32BIT | CPU_SET_SRC_FIXED, sizeof(gCableLinkInfo) / sizeof(u32)));

    sNumVBlanksWithoutSerialIntr = 0;
    sSendBufferEmpty = 0;
    sHandshakePlayerCount = 0;
    gLastSendQueueCount = 0;
    gLastRecvQueueCount = 0;
    sChecksumAvailable = 0;
    sSendNonzeroCheck = 0;
    sRecvNonzeroCheck = 0;
}

/**
 * @brief 8a39c | 10 | Reset the state of the serial transfer
 * 
 */
void ResetSerial(void)
{
    EnableSerial();
    DisableSerial();
}

/**
 * @brief 8a3ac | 120 | Handle connection, sending data, and checking errors
 * 
 * @param shouldAdvanceLinkState To document
 * @param sendCmd The commands to send
 * @param recvCmds A queue of received commands
 * @return u32 The state of the connection
 */
u32 LinkMain(u8* shouldAdvanceLinkState, u16* sendCmd, RecvCmds_T recvCmds)
{
    u32 retval;
    u32 receivedNothing;
    u32 errorFlag_1;
    u32 hardwareError;
    u32 badChecksum;
    u32 queueFull;
    u32 errorFlag_sioInternal;
    u32 val;

    switch (gCableLinkInfo.state)
    {
        case LINK_STATE_START0:
            DisableSerial();
            gCableLinkInfo.state = LINK_STATE_START1;
            break;

        case LINK_STATE_START1:
            if (*shouldAdvanceLinkState == 1)
            {
                EnableSerial();
                gCableLinkInfo.state = LINK_STATE_HANDSHAKE;
            }
            break;

        case LINK_STATE_HANDSHAKE:
            switch (*shouldAdvanceLinkState)
            {
                case 1:
                    if (gCableLinkInfo.isParent != 0 && gCableLinkInfo.playerCount > 1)
                        gCableLinkInfo.handshakeAsParent = 1;
                    break;

                case 2:
                    gCableLinkInfo.state = LINK_STATE_START0;
                    write16(REG_SIO_DATA8, 0);
                    break;

                default:
                    CheckParentOrChild();
                    break;
            }
            break;

        case LINK_STATE_INIT_TIMER:
            InitTimer();
            gCableLinkInfo.state = LINK_STATE_CONN_ESTABLISHED;

        case LINK_STATE_CONN_ESTABLISHED:
            EnqueueSendCmd(sendCmd);
            DequeueRecvCmds(recvCmds);
            break;
    }

    *shouldAdvanceLinkState = 0;

    retval = gCableLinkInfo.localId | (gCableLinkInfo.playerCount << CABLE_LINK_STAT_SHIFT_PLAYER_COUNT);
    if (gCableLinkInfo.isParent == LINK_PARENT)
    {
        retval |= CABLE_LINK_STAT_PARENT;
    }

    receivedNothing = gCableLinkInfo.recievedNothing << CABLE_LINK_STAT_SHIFT_RECEIVED_NOTHING;
    errorFlag_1 = gCableLinkInfo.unk_11 << CABLE_LINK_STAT_SHIFT_UNK_FLAG_9;
    hardwareError = gCableLinkInfo.hardwareErrorFlag << CABLE_LINK_ERROR_SHIFT_HARDWARE;
    badChecksum = gCableLinkInfo.checksumErrorFlag << CABLE_LINK_ERROR_SHIFT_CHECKSUM;
    queueFull = gCableLinkInfo.overflowErrorFlags << CABLE_LINK_ERROR_SHIFT_OVERFLOW;
    errorFlag_sioInternal = gCableLinkInfo.sioErrorFlags << CABLE_LINK_ERROR_SHIFT_SIO;

    if (gCableLinkInfo.state == LINK_STATE_CONN_ESTABLISHED)
    {
        val = CABLE_LINK_STAT_CONN_ESTABLISHED;
        val |= receivedNothing;
        val |= retval;
        val |= errorFlag_1;
        val |= hardwareError;
        val |= badChecksum;
        val |= queueFull;
        val |= errorFlag_sioInternal;
    }
    else
    {
        val = retval;
        val |= receivedNothing;
        val |= errorFlag_1;
        val |= hardwareError;
        val |= badChecksum;
        val |= queueFull;
        val |= errorFlag_sioInternal;
    }
    retval = val;

    if (gCableLinkInfo.localId >= MAX_LINK_PLAYERS)
        retval |= CABLE_LINK_ERROR_ID_OVER;

    return retval;
}

/**
 * @brief 8a4cc | 2c | Check if the current connection is parent or child
 * 
 */
void CheckParentOrChild(void)
{
    u32 terminals;

    terminals = read32(REG_SIO) & (SIO_MULTI_CONNECTION_READY | SIO_MULTI_RECEIVE_ID);
    if (terminals == (SIO_MULTI_CONNECTION_READY | SIO_MULTI_PARENT) && gCableLinkInfo.localId == 0)
    {
        gCableLinkInfo.isParent = LINK_PARENT;
    }
    else
    {
        gCableLinkInfo.isParent = LINK_CHILD;
    }
}

/**
 * @brief 8a4f8 | 50 | Load timer 3 if all GBA's are ready
 * 
 */
void InitTimer(void)
{
    if (gCableLinkInfo.isParent)
    {
        // Load -132 into timer 3 with 1/64 the normal frequency
        write16(REG_TM3CNT_L, -132);
        write16(REG_TM3CNT_H, TIMER_CONTROL_IRQ_ENABLE | 1);

        // Enable timer 3 interrupt, enable interrupts if already enabled
        gLinkSavedIme = read16(REG_IME);
        write16(REG_IME, FALSE);
        write16(REG_IE, read16(REG_IE) | IF_TIMER3);
        write16(REG_IME, gLinkSavedIme);
    }
}

/**
 * @brief 8a548 | e0 | Put commands into send queue
 * 
 * @param sendCmd The commands to send
 */
void EnqueueSendCmd(u16* sendCmd)
{
    u8 offset;
    u8 i;

    gLinkSavedIme = read16(REG_IME);
    write16(REG_IME, FALSE);

    if (gCableLinkInfo.sendQueue_Count < QUEUE_CAPACITY)
    {
        offset = gCableLinkInfo.sendQueue_Pos + gCableLinkInfo.sendQueue_Count;
        if (offset >= QUEUE_CAPACITY)
        {
            offset -= QUEUE_CAPACITY;
        }

        for (i = 0; i < CMD_LENGTH; i++)
        {
            sSendNonzeroCheck |= *sendCmd;
            gCableLinkInfo.sendQueue_Data[i][offset] = *sendCmd;
            *sendCmd++ = 0;
        }
    }
    else
    {
        gCableLinkInfo.overflowErrorFlags |= QUEUE_FULL_SEND;
    }

    if (sSendNonzeroCheck)
    {
        gCableLinkInfo.sendQueue_Count++;
        sSendNonzeroCheck = 0;
    }

    write16(REG_IME, gLinkSavedIme);
    gLastSendQueueCount = gCableLinkInfo.sendQueue_Count;
}

/**
 * @brief 8a628 | 108 | Get commands from recieve queue
 * 
 * @param recvCmds A queue of received commands
 */
void DequeueRecvCmds(RecvCmds_T recvCmds)
{
    u8 i;
    u8 j;

    gLinkSavedIme = read16(REG_IME);
    write16(REG_IME, FALSE);

    if (gCableLinkInfo.recvQueue_Count == 0)
    {
        for (i = 0; i < CMD_LENGTH; i++)
        {
            for (j = 0; j < gCableLinkInfo.playerCount; j++)
            {
                recvCmds[i][j] = 0;
            }
        }

        gCableLinkInfo.recievedNothing = TRUE;
    }
    else
    {
        for (i = 0; i < CMD_LENGTH; i++)
        {
            for (j = 0; j < gCableLinkInfo.playerCount; j++)
            {
                recvCmds[i][j] = gCableLinkInfo.recvQueue_Data[j][i][gCableLinkInfo.recvQueue_Pos];
            }
        }

        gCableLinkInfo.recvQueue_Count--;
        gCableLinkInfo.recvQueue_Pos++;

        if (gCableLinkInfo.recvQueue_Pos >= QUEUE_CAPACITY)
        {
            gCableLinkInfo.recvQueue_Pos = 0;
        }

        gCableLinkInfo.recievedNothing = FALSE;
    }

    write16(REG_IME, gLinkSavedIme);
}

/**
 * @brief 8a730 | 70 | Keep track of VSync frames and either start a transfer or lag out if enough frames has passed
 * 
 */
void LinkVSync(void)
{
    if (gCableLinkInfo.isParent)
    {
        switch (gCableLinkInfo.state)
        {
            case LINK_STATE_CONN_ESTABLISHED:
                if (gCableLinkInfo.serialIntrCounter < 3)
                {
                    if (gCableLinkInfo.hardwareErrorFlag == 0)
                    {
                        gCableLinkInfo.sioErrorFlags = 1;
                    }
                    else
                    {
                        StartTransfer();
                    }
                }

                else if (gCableLinkInfo.sioErrorFlags == 0)
                {
                    gCableLinkInfo.serialIntrCounter = 0;
                    StartTransfer();
                }
                break;
            
            case LINK_STATE_HANDSHAKE:
                StartTransfer();
                break;
        }
    }
    
    else if (gCableLinkInfo.state == LINK_STATE_CONN_ESTABLISHED || gCableLinkInfo.state == LINK_STATE_HANDSHAKE)
    {
        sNumVBlanksWithoutSerialIntr++;
        if (sNumVBlanksWithoutSerialIntr > 10)
        {
            if (gCableLinkInfo.state == LINK_STATE_CONN_ESTABLISHED)
            {
                gCableLinkInfo.sioErrorFlags = LAG_CHILD;
            }
            
            if (gCableLinkInfo.state == LINK_STATE_HANDSHAKE)
            {
                gCableLinkInfo.localId = 0;
                gCableLinkInfo.playerCount = 0;
                gCableLinkInfo.unk_11 = 0;
            }
        }
    }
}

/**
 * @brief 8a7a0 | 10 | Stop the timer and begin a transfer
 * 
 */
void Timer3Intr(void)
{
    StopTimer();
    StartTransfer();
}

/**
 * @brief 8a7b0 | 90 | Establish a connection and send data
 * 
 */
void SerialCB(void)
{
    u32 control;

    control = read32(REG_SIO);
    gCableLinkInfo.localId = (control << 26) >> 30;

    switch (gCableLinkInfo.state)
    {
        case LINK_STATE_CONN_ESTABLISHED:
            if (control & 0x40) // bit 6 should (always?) be 0
                gCableLinkInfo.hardwareErrorFlag = TRUE;

            DoRecv();
            DoSend();
            SendRecvDone();
            break;

        case LINK_STATE_HANDSHAKE:
            if (DoHandshake())
            {
                if (gCableLinkInfo.isParent)
                {
                    gCableLinkInfo.state = LINK_STATE_INIT_TIMER;
                    gCableLinkInfo.serialIntrCounter = 2;
                }
                else
                {
                    gCableLinkInfo.state = LINK_STATE_CONN_ESTABLISHED;
                }
            }
            break;
    }

    gCableLinkInfo.serialIntrCounter++;
    sNumVBlanksWithoutSerialIntr = 0;

    if (gCableLinkInfo.serialIntrCounter == CMD_LENGTH)
    {
        gLastRecvQueueCount = gCableLinkInfo.recvQueue_Count;
    }
}

/**
 * @brief 8a840 | 10 | Start a serial transfer
 * 
 */
void StartTransfer(void)
{
    write16(REG_SIO, read16(REG_SIO) | SIO_START_BIT_ACTIVE);
}

/**
 * @brief 8a850 | fc | Try to perform the handshake between the parent and child connections
 * 
 * @return u8 bool, handshake was successfully performed
 */
u8 DoHandshake(void)
{
    u16 minRecv;
    u8 i;
    u8 playerCount;

    playerCount = 0;
    minRecv = USHORT_MAX;

    if (gCableLinkInfo.handshakeAsParent == TRUE)
    {
        write16(REG_SIO_DATA8, PARENT_HANDSHAKE);
    }
    else
    {
        write16(REG_SIO_DATA8, CHILD_HANDSHAKE);
    }
    gCableLinkInfo.handshakeAsParent = FALSE;

    write64(&gCableLinkInfo.handshakeBuffer, *(vu64 *)REG_SIO_MULTI);

    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {    
        if ((gCableLinkInfo.handshakeBuffer[i] & ~3) == CHILD_HANDSHAKE || gCableLinkInfo.handshakeBuffer[i] == PARENT_HANDSHAKE)
        {
            playerCount++;
            if (minRecv > gCableLinkInfo.handshakeBuffer[i] && gCableLinkInfo.handshakeBuffer[i] != 0)
            {
                minRecv = gCableLinkInfo.handshakeBuffer[i];
            }
        }
        else if (gCableLinkInfo.handshakeBuffer[i] != USHORT_MAX)
        {
            playerCount = 0;
            break;
        }
        else if (i == gCableLinkInfo.localId)
        {
            playerCount = 0;
        }
    }

    gCableLinkInfo.playerCount = playerCount;

    if (gCableLinkInfo.playerCount > 1)
    {
        if (gCableLinkInfo.playerCount == sHandshakePlayerCount && gCableLinkInfo.handshakeBuffer[0] == PARENT_HANDSHAKE)
        {
            return TRUE;
        }
    
        if (gCableLinkInfo.playerCount > 1)
        {
            gCableLinkInfo.unk_11 = (minRecv & 3) + 1;
        }
        else
        {
            gCableLinkInfo.unk_11 = 0;
        }
    }
    else
    {
        gCableLinkInfo.unk_11 = 0;
    }

    sHandshakePlayerCount = gCableLinkInfo.playerCount;

    return FALSE;
}

/**
 * @brief 8a94c | 108 | Receive a command from the receive queue
 * 
 */
void DoRecv(void)
{
    u16 recv[4];
    u8 i;
    u8 offset;

    write64(recv, *(vu64 *)REG_SIO_MULTI);

    if (gCableLinkInfo.sendCmdIndex == 0)
    {
        for (i = 0; i < gCableLinkInfo.playerCount; i++)
        {
            if (gCableLinkInfo.checksum != recv[i] && sChecksumAvailable)
            {
                gCableLinkInfo.checksumErrorFlag = TRUE;
            }
        }

        gCableLinkInfo.checksum = 0;
        sChecksumAvailable = TRUE;
    }
    else
    {
        offset = gCableLinkInfo.recvQueue_Pos + gCableLinkInfo.recvQueue_Count;
        if (offset >= QUEUE_CAPACITY)
            offset -= QUEUE_CAPACITY;

        if (gCableLinkInfo.recvQueue_Count < QUEUE_CAPACITY)
        {
            for (i = 0; i < gCableLinkInfo.playerCount; i++)
            {
                gCableLinkInfo.checksum += recv[i];
                sRecvNonzeroCheck |= recv[i];

                gCableLinkInfo.recvQueue_Data[i][gCableLinkInfo.recvCmdIndex][offset] = recv[i];
            }
        }
        else
        {
            gCableLinkInfo.overflowErrorFlags |= QUEUE_FULL_RECV;
        }

        gCableLinkInfo.recvCmdIndex++;
        if (gCableLinkInfo.recvCmdIndex == CMD_LENGTH && sRecvNonzeroCheck)
        {
            gCableLinkInfo.recvQueue_Count++;
            sRecvNonzeroCheck = 0;
        }
    }
}

/**
 * @brief 8aa54 | 9c | Send a command from the send queue
 * 
 */
void DoSend(void)
{
    if (gCableLinkInfo.sendCmdIndex == CMD_LENGTH)
    {
        write16(REG_SIO_DATA8, gCableLinkInfo.checksum);

        if (!sSendBufferEmpty)
        {
            gCableLinkInfo.sendQueue_Count--;
            gCableLinkInfo.sendQueue_Pos++;

            if (gCableLinkInfo.sendQueue_Pos >= QUEUE_CAPACITY)
            {
                gCableLinkInfo.sendQueue_Pos = 0;
            }
        }
        else
        {
            sSendBufferEmpty = FALSE;
        }
    }
    else
    {
        if (gCableLinkInfo.sendCmdIndex == 0 && gCableLinkInfo.sendQueue_Count == 0)
        {
            sSendBufferEmpty = TRUE;
        }
            
        if (sSendBufferEmpty)
        {
            write16(REG_SIO_DATA8, 0);
        }
        else
        {
            write16(REG_SIO_DATA8, gCableLinkInfo.sendQueue_Data[gCableLinkInfo.sendCmdIndex][gCableLinkInfo.sendQueue_Pos]);
        }

        gCableLinkInfo.sendCmdIndex++;
    }
}

/**
 * @brief 8aaf0 | 34 | Stops the timer for the parent
 * 
 */
void StopTimer(void)
{
    if (gCableLinkInfo.isParent)
    {
        // Turn off timer 3 and load in -132
        write16(REG_TM3CNT_H, read16(REG_TM3CNT_H) & ~TIMER_CONTROL_ACTIVE);
        write16(REG_TM3CNT_L, -132);
    }
}

/**
 * @brief 8ab24 | 30 | Send a signal that the receive command is done
 * 
 */
void SendRecvDone(void)
{
    if (gCableLinkInfo.recvCmdIndex == CMD_LENGTH)
    {
        gCableLinkInfo.sendCmdIndex = 0;
        gCableLinkInfo.recvCmdIndex = 0;
    }
    else if (gCableLinkInfo.isParent)
    {
        write16(REG_TM3CNT_H, read16(REG_TM3CNT_H) | TIMER_CONTROL_ACTIVE);
    }
}

/**
 * @brief 8ab54 | 48 | Clear the commands in the send queue
 * 
 */
void ResetSendBuffer(void)
{
    u8 i;
    u8 j;

    gCableLinkInfo.sendQueue_Count = 0;
    gCableLinkInfo.sendQueue_Pos = 0;

    for (i = 0; i < CMD_LENGTH; i++)
    {
        for (j = 0; j < QUEUE_CAPACITY; j++)
        {
            gCableLinkInfo.sendQueue_Data[i][j] = LINKCMD_NONE;
        }
    }
}

/**
 * @brief 8ab9c | 5c | Clear the commands in the receive queue
 * 
 */
void ResetRecvBuffer(void)
{
    u8 i;
    u8 j;
    u8 k;

    gCableLinkInfo.recvQueue_Count = 0;
    gCableLinkInfo.recvQueue_Pos = 0;

    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        for (j = 0; j < CMD_LENGTH; j++)
        {
            for (k = 0; k < QUEUE_CAPACITY; k++)
            {
                gCableLinkInfo.recvQueue_Data[i][j][k] = LINKCMD_NONE;
            }
        }
    }
}
