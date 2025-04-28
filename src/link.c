#include "cable_link.h"
#include "macros.h"
#include "gba.h"
#include "link.h"

#include "data/io_transfer_data.h"

#include "constants/cable_link.h"

#include "structs/cable_link.h"
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
            DMA_SET(3, ptr, gRecvCmds, C_32_2_16(DMA_ENABLE | DMA_SRC_FIXED, MAX_LINK_PLAYERS * CMD_LENGTH));

            gErrorFlag = 0;
            gShouldAdvanceLinkState = 0;
            gLinkPlayerCount = 0;
            gLinkLocalId = 0;
            gLinkUnkFlag9 = 0;

            CallbackSetSerialCommunication(LinkCommunicate);
            CallbackSetTimer3(LinkReloadTransfer);

            LinkResetSerial();

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
                LinkDisableSerial();
                if (gIoTransferInfo.command == LINKCMD_3300)
                    gIoTransferInfo.linkStage = LINK_STAGE_RECEIVED_GALLERY;
                else if (gIoTransferInfo.errorFlag)
                    gIoTransferInfo.linkStage = LINK_STAGE_ERROR0;
                else
                    gIoTransferInfo.linkStage = LINK_STAGE_ERROR1;
            }
            else
            {
                LinkHandleConnection();
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
u8* LinkHandleConnection(void)
{
    vu32 c;
    u32* link_stat;
    
    gShouldAdvanceLinkState = gFrameCounter8Bit & 1;
    link_stat = &gErrorFlag;
    *link_stat = LinkMain(&gShouldAdvanceLinkState, gSendCmd, gRecvCmds);
    gLinkLocalId = *link_stat & LINK_STAT_LOCAL_ID;
    gLinkPlayerCount = EXTRACT_PLAYER_COUNT(*link_stat);
    gLinkUnkFlag9 = EXTRACT_LINK_ERRORS(*link_stat);

    if (*link_stat & LINK_STAT_CONN_ESTABLISHED)
    {
        gIoTransferInfo.timer = 0;
        LinkBuildSendCmd(gIoTransferInfo.command);
        LinkProcessRecvCmds();
    }

    if (*link_stat & LINK_ERROR_ID_OVER)
    {
        gIoTransferInfo.errorFlag |= 1;
        CableLinkDrawErrorStr(sErrorString_IdOver, VRAM_BASE + 0xE304, 12);
    }

    if (*link_stat & LINK_ERROR_CHECKSUM)
    {
        gIoTransferInfo.errorFlag |= 2;
        CableLinkDrawErrorStr(sErrorString_ChecksumError, VRAM_BASE + 0xE344, 12);
    }

    if (*link_stat & LINK_ERROR_HARDWARE)
    {
        gIoTransferInfo.errorFlag |= 4;
        CableLinkDrawErrorStr(sErrorString_HardwareError, VRAM_BASE + 0xE384, 12);
    }

    if (*link_stat & LINK_ERROR_SEND_OVERFLOW)
    {
        gIoTransferInfo.errorFlag |= 8;
        CableLinkDrawErrorStr(sErrorString_SendOverflow, VRAM_BASE + 0xE3C4, 12);
    }

    if (*link_stat & LINK_ERROR_RECEIVE_OVERFLOW)
    {
        gIoTransferInfo.errorFlag |= 16;
        CableLinkDrawErrorStr(sErrorString_ReceiveOverflow, VRAM_BASE + 0xE404, 12);
    }

    if (*link_stat & LINK_ERROR_SIO_INTERNAL)
    {
        gIoTransferInfo.errorFlag |= 32;
        CableLinkDrawErrorStr(sErrorString_SioInternal, VRAM_BASE + 0xE444, 12);
    }

    if (*link_stat & LINK_ERROR_SIO_STOP)
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
void LinkBuildSendCmd(u16 command)
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
 * 
 */
void LinkProcessRecvCmds(void)
{
    u8 var;

    if (gErrorFlag & LINK_STAT_RECEIVED_NOTHING)
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
void LinkDisableSerial(void)
{
    u32 buffer;

    // Disable Interrupts
    gLinkSavedIme = read16(REG_IME);
    write16(REG_IME, FALSE);
    write16(REG_IE, read16(REG_IE) & ~(IF_TIMER3 | IF_SERIAL));
    write16(REG_IME, gLinkSavedIme);

    write16(REG_SIO, SIO_MULTI_MODE);
    write16(REG_TM3CNT_H, 0);
    write16(REG_IF, IF_TIMER3 | IF_SERIAL);

    buffer = 0;
    CpuSet(&buffer, &gLink, C_32_2_16(CPU_SET_32BIT | CPU_SET_SRC_FIXED, sizeof(gLink) / sizeof(u32)));
}

/**
 * @brief 8a2c8 | D4 | Enable serial transfer
 * 
 */
void LinkEnableSerial(void)
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
    CpuSet(&buffer, &gLink, C_32_2_16(CPU_SET_32BIT | CPU_SET_SRC_FIXED, sizeof(gLink) / sizeof(u32)));

    gNumVBlanksWithoutSerialIntr = 0;
    gSendBufferEmpty = 0;
    gHandshakePlayerCount = 0;
    gLastSendQueueCount = 0;
    gLastRecvQueueCount = 0;
    gChecksumAvailable = 0;
    gSendNonzeroCheck = 0;
    gRecvNonzeroCheck = 0;
}

/**
 * @brief 8a39c | 10 | Reset the state of the serial transfer
 * 
 */
void LinkResetSerial(void)
{
    LinkEnableSerial();
    LinkDisableSerial();
}

/**
 * @brief 8a3ac | 120 | Handle connection, sending data, and checking errors
 * 
 * @param shouldAdvanceLinkState Should advance link state
 * @param sendCmd The commands to send
 * @param recvCmds A queue of received commands
 * @return u32 The state of the connection
 */
u32 LinkMain(u8* shouldAdvanceLinkState, u16 sendCmd[CMD_LENGTH], u16 recvCmds[MAX_LINK_PLAYERS][CMD_LENGTH])
{
    u32 retval;
    u32 receivedNothing;
    u32 errorFlag_1;
    u32 hardwareError;
    u32 badChecksum;
    u32 queueFull;
    u32 errorFlag_sioInternal;
    u32 val;

    switch (gLink.session.state)
    {
        case LINK_STATE_START0:
            LinkDisableSerial();
            gLink.session.state = LINK_STATE_START1;
            break;

        case LINK_STATE_START1:
            if (*shouldAdvanceLinkState == 1)
            {
                LinkEnableSerial();
                gLink.session.state = LINK_STATE_HANDSHAKE;
            }
            break;

        case LINK_STATE_HANDSHAKE:
            switch (*shouldAdvanceLinkState)
            {
                case 1:
                    if (gLink.session.isParent != 0 && gLink.session.playerCount > 1)
                        gLink.connection.handshakeAsParent = 1;
                    break;

                case 2:
                    gLink.session.state = LINK_STATE_START0;
                    write16(REG_SIO_DATA8, 0);
                    break;

                default:
                    LinkCheckParentOrChild();
                    break;
            }
            break;

        case LINK_STATE_INIT_TIMER:
            LinkInitTimer();
            gLink.session.state = LINK_STATE_CONN_ESTABLISHED;

        case LINK_STATE_CONN_ESTABLISHED:
            LinkEnqueueSendCmd(sendCmd);
            LinkDequeueRecvCmds(recvCmds);
            break;
    }

    *shouldAdvanceLinkState = 0;

    retval = gLink.session.localId | (gLink.session.playerCount << LINK_STAT_SHIFT_PLAYER_COUNT);
    if (gLink.session.isParent == LINK_PARENT)
    {
        retval |= LINK_STAT_PARENT;
    }

    receivedNothing = gLink.session.receivedNothing << LINK_STAT_SHIFT_RECEIVED_NOTHING;
    errorFlag_1 = gLink.connection.unk_11 << LINK_STAT_SHIFT_ERRORS;
    hardwareError = gLink.connection.hardwareErrorFlag << LINK_ERROR_SHIFT_HARDWARE;
    badChecksum = gLink.connection.checksumErrorFlag << LINK_ERROR_SHIFT_CHECKSUM;
    queueFull = gLink.connection.overflowErrorFlags << LINK_ERROR_SHIFT_OVERFLOW;
    errorFlag_sioInternal = gLink.connection.sioErrorFlags << LINK_ERROR_SHIFT_SIO;

    if (gLink.session.state == LINK_STATE_CONN_ESTABLISHED)
    {
        val = LINK_STAT_CONN_ESTABLISHED;
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

    if (gLink.session.localId >= MAX_LINK_PLAYERS)
        retval |= LINK_ERROR_ID_OVER;

    return retval;
}

/**
 * @brief 8a4cc | 2c | Check if the current connection is parent or child
 * 
 */
void LinkCheckParentOrChild(void)
{
    u32 terminals;

    terminals = read32(REG_SIO) & (SIO_MULTI_CONNECTION_READY | SIO_MULTI_RECEIVE_ID);
    if (terminals == (SIO_MULTI_CONNECTION_READY | SIO_MULTI_PARENT) && gLink.session.localId == 0)
    {
        gLink.session.isParent = LINK_PARENT;
    }
    else
    {
        gLink.session.isParent = LINK_CHILD;
    }
}

/**
 * @brief 8a4f8 | 50 | Load timer 3 if all GBA's are ready
 * 
 */
void LinkInitTimer(void)
{
    if (gLink.session.isParent)
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
void LinkEnqueueSendCmd(u16 sendCmd[CMD_LENGTH])
{
    u8 offset;
    u8 i;

    gLinkSavedIme = read16(REG_IME);
    write16(REG_IME, FALSE);

    if (gLink.sendQueue.count < QUEUE_CAPACITY)
    {
        offset = gLink.sendQueue.pos + gLink.sendQueue.count;
        if (offset >= QUEUE_CAPACITY)
        {
            offset -= QUEUE_CAPACITY;
        }

        for (i = 0; i < CMD_LENGTH; i++)
        {
            gSendNonzeroCheck |= *sendCmd;
            gLink.sendQueue.data[i][offset] = *sendCmd;
            *sendCmd++ = 0;
        }
    }
    else
    {
        gLink.connection.overflowErrorFlags |= QUEUE_FULL_SEND;
    }

    if (gSendNonzeroCheck)
    {
        gLink.sendQueue.count++;
        gSendNonzeroCheck = 0;
    }

    write16(REG_IME, gLinkSavedIme);
    gLastSendQueueCount = gLink.sendQueue.count;
}

/**
 * @brief 8a628 | 108 | Get commands from recieve queue
 * 
 * @param recvCmds A queue of received commands
 */
void LinkDequeueRecvCmds(u16 recvCmds[MAX_LINK_PLAYERS][CMD_LENGTH])
{
    u8 i;
    u8 j;

    gLinkSavedIme = read16(REG_IME);
    write16(REG_IME, FALSE);

    if (gLink.recvQueue.count == 0)
    {
        for (i = 0; i < CMD_LENGTH; i++)
        {
            for (j = 0; j < gLink.session.playerCount; j++)
            {
                recvCmds[i][j] = 0;
            }
        }

        gLink.session.receivedNothing = TRUE;
    }
    else
    {
        for (i = 0; i < CMD_LENGTH; i++)
        {
            for (j = 0; j < gLink.session.playerCount; j++)
            {
                recvCmds[i][j] = gLink.recvQueue.data[j][i][gLink.recvQueue.pos];
            }
        }

        gLink.recvQueue.count--;
        gLink.recvQueue.pos++;

        if (gLink.recvQueue.pos >= QUEUE_CAPACITY)
        {
            gLink.recvQueue.pos = 0;
        }

        gLink.session.receivedNothing = FALSE;
    }

    write16(REG_IME, gLinkSavedIme);
}

/**
 * @brief 8a730 | 70 | Keep track of VSync frames and either start a transfer or lag out if enough frames has passed
 * 
 */
void LinkVSync(void)
{
    if (gLink.session.isParent)
    {
        switch (gLink.session.state)
        {
            case LINK_STATE_CONN_ESTABLISHED:
                if (gLink.session.serialIntrCounter <= CMD_LENGTH)
                {
                    if (gLink.connection.hardwareErrorFlag == 0)
                    {
                        gLink.connection.sioErrorFlags = 1;
                    }
                    else
                    {
                        LinkStartTransfer();
                    }
                }

                else if (gLink.connection.sioErrorFlags == 0)
                {
                    gLink.session.serialIntrCounter = 0;
                    LinkStartTransfer();
                }
                break;
            
            case LINK_STATE_HANDSHAKE:
                LinkStartTransfer();
                break;
        }
    }
    
    else if (gLink.session.state == LINK_STATE_CONN_ESTABLISHED || gLink.session.state == LINK_STATE_HANDSHAKE)
    {
        gNumVBlanksWithoutSerialIntr++;
        if (gNumVBlanksWithoutSerialIntr > 10)
        {
            if (gLink.session.state == LINK_STATE_CONN_ESTABLISHED)
            {
                gLink.connection.sioErrorFlags = LAG_CHILD;
            }
            
            if (gLink.session.state == LINK_STATE_HANDSHAKE)
            {
                gLink.session.localId = 0;
                gLink.session.playerCount = 0;
                gLink.connection.unk_11 = 0;
            }
        }
    }
}

/**
 * @brief 8a7a0 | 10 | Reload timer 3 and start serial transfer
 * 
 */
void LinkReloadTransfer(void)
{
    // Called when timer 3 interrupts
    LinkStopTimer();
    LinkStartTransfer();
}

/**
 * @brief 8a7b0 | 90 | Establish a connection and send data
 * 
 */
void LinkCommunicate(void)
{
    u32 control;

    control = read32(REG_SIO);
    gLink.session.localId = (control << 26) >> 30; // SIO_MULTI_CONNECTION_ID_FLAG

    switch (gLink.session.state)
    {
        case LINK_STATE_CONN_ESTABLISHED:
            if (control & SIO_MULTI_ERROR)
                gLink.connection.hardwareErrorFlag = TRUE;

            LinkDoRecv();
            LinkDoSend();
            LinkSendRecvDone();
            break;

        case LINK_STATE_HANDSHAKE:
            if (LinkDoHandshake())
            {
                if (gLink.session.isParent)
                {
                    gLink.session.state = LINK_STATE_INIT_TIMER;
                    gLink.session.serialIntrCounter = CMD_LENGTH;
                }
                else
                {
                    gLink.session.state = LINK_STATE_CONN_ESTABLISHED;
                }
            }
            break;
    }

    gLink.session.serialIntrCounter++;
    gNumVBlanksWithoutSerialIntr = 0;
    if (gLink.session.serialIntrCounter == CMD_LENGTH)
    {
        gLastRecvQueueCount = gLink.recvQueue.count;
    }
}

/**
 * @brief 8a840 | 10 | Start a serial transfer
 * 
 */
void LinkStartTransfer(void)
{
    write16(REG_SIO, read16(REG_SIO) | SIO_START_BIT_ACTIVE);
}

/**
 * @brief 8a850 | fc | Try to perform the handshake between the parent and child connections
 * 
 * @return u8 bool, handshake was successfully performed
 */
u8 LinkDoHandshake(void)
{
    u16 minRecv;
    u8 i;
    u8 playerCount;

    playerCount = 0;
    minRecv = USHORT_MAX;

    if (gLink.connection.handshakeAsParent == TRUE)
    {
        write16(REG_SIO_DATA8, PARENT_HANDSHAKE);
    }
    else
    {
        write16(REG_SIO_DATA8, CHILD_HANDSHAKE);
    }
    gLink.connection.handshakeAsParent = FALSE;

    write64(gLink.session.handshakeBuffer, read64(REG_SIO_MULTI));

    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {    
        if ((gLink.session.handshakeBuffer[i] & ~3) == CHILD_HANDSHAKE || gLink.session.handshakeBuffer[i] == PARENT_HANDSHAKE)
        {
            playerCount++;
            if (minRecv > gLink.session.handshakeBuffer[i] && gLink.session.handshakeBuffer[i] != 0)
            {
                minRecv = gLink.session.handshakeBuffer[i];
            }
        }
        else if (gLink.session.handshakeBuffer[i] != USHORT_MAX)
        {
            playerCount = 0;
            break;
        }
        else if (i == gLink.session.localId)
        {
            playerCount = 0;
        }
    }

    gLink.session.playerCount = playerCount;

    if (gLink.session.playerCount > 1)
    {
        if (gLink.session.playerCount == gHandshakePlayerCount && gLink.session.handshakeBuffer[0] == PARENT_HANDSHAKE)
        {
            return TRUE;
        }
    
        if (gLink.session.playerCount > 1)
        {
            gLink.connection.unk_11 = (minRecv & 3) + 1;
        }
        else
        {
            gLink.connection.unk_11 = 0;
        }
    }
    else
    {
        gLink.connection.unk_11 = 0;
    }

    gHandshakePlayerCount = gLink.session.playerCount;

    return FALSE;
}

/**
 * @brief 8a94c | 108 | Receive a command from the receive queue
 * 
 */
void LinkDoRecv(void)
{
    u16 recv[4];
    u8 i;
    u8 offset;

    write64(recv, read64(REG_SIO_MULTI));

    if (gLink.connection.sendCmdIndex == 0)
    {
        for (i = 0; i < gLink.session.playerCount; i++)
        {
            if (gLink.connection.checksum != recv[i] && gChecksumAvailable)
            {
                gLink.connection.checksumErrorFlag = TRUE;
            }
        }

        gLink.connection.checksum = 0;
        gChecksumAvailable = TRUE;
    }
    else
    {
        offset = gLink.recvQueue.pos + gLink.recvQueue.count;
        if (offset >= QUEUE_CAPACITY)
            offset -= QUEUE_CAPACITY;

        if (gLink.recvQueue.count < QUEUE_CAPACITY)
        {
            for (i = 0; i < gLink.session.playerCount; i++)
            {
                gLink.connection.checksum += recv[i];
                gRecvNonzeroCheck |= recv[i];

                gLink.recvQueue.data[i][gLink.connection.recvCmdIndex][offset] = recv[i];
            }
        }
        else
        {
            gLink.connection.overflowErrorFlags |= QUEUE_FULL_RECV;
        }

        gLink.connection.recvCmdIndex++;
        if (gLink.connection.recvCmdIndex == CMD_LENGTH && gRecvNonzeroCheck)
        {
            gLink.recvQueue.count++;
            gRecvNonzeroCheck = 0;
        }
    }
}

/**
 * @brief 8aa54 | 9c | Send a command from the send queue
 * 
 */
void LinkDoSend(void)
{
    if (gLink.connection.sendCmdIndex == CMD_LENGTH)
    {
        write16(REG_SIO_DATA8, gLink.connection.checksum);

        if (!gSendBufferEmpty)
        {
            gLink.sendQueue.count--;
            gLink.sendQueue.pos++;

            if (gLink.sendQueue.pos >= QUEUE_CAPACITY)
            {
                gLink.sendQueue.pos = 0;
            }
        }
        else
        {
            gSendBufferEmpty = FALSE;
        }
    }
    else
    {
        if (gLink.connection.sendCmdIndex == 0 && gLink.sendQueue.count == 0)
        {
            gSendBufferEmpty = TRUE;
        }
            
        if (gSendBufferEmpty)
        {
            write16(REG_SIO_DATA8, 0);
        }
        else
        {
            write16(REG_SIO_DATA8, gLink.sendQueue.data[gLink.connection.sendCmdIndex][gLink.sendQueue.pos]);
        }

        gLink.connection.sendCmdIndex++;
    }
}

/**
 * @brief 8aaf0 | 34 | Stops the timer for the parent
 * 
 */
void LinkStopTimer(void)
{
    if (gLink.session.isParent)
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
void LinkSendRecvDone(void)
{
    if (gLink.connection.recvCmdIndex == CMD_LENGTH)
    {
        gLink.connection.sendCmdIndex = 0;
        gLink.connection.recvCmdIndex = 0;
    }
    else if (gLink.session.isParent)
    {
        write16(REG_TM3CNT_H, read16(REG_TM3CNT_H) | TIMER_CONTROL_ACTIVE);
    }
}

/**
 * @brief 8ab54 | 48 | Clear the commands in the send queue
 * 
 */
void LinkResetSendBuffer(void)
{
    u8 i;
    u8 j;

    gLink.sendQueue.count = 0;
    gLink.sendQueue.pos = 0;

    for (i = 0; i < CMD_LENGTH; i++)
    {
        for (j = 0; j < QUEUE_CAPACITY; j++)
        {
            gLink.sendQueue.data[i][j] = LINKCMD_NONE;
        }
    }
}

/**
 * @brief 8ab9c | 5c | Clear the commands in the receive queue
 * 
 */
void LinkResetRecvBuffer(void)
{
    u8 i;
    u8 j;
    u8 k;

    gLink.recvQueue.count = 0;
    gLink.recvQueue.pos = 0;

    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        for (j = 0; j < CMD_LENGTH; j++)
        {
            for (k = 0; k < QUEUE_CAPACITY; k++)
            {
                gLink.recvQueue.data[i][j][k] = LINKCMD_NONE;
            }
        }
    }
}
