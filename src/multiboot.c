#include "types.h"
#include "macros.h"
#include "gba.h"
#include "multiboot.h"

#include "structs/multiboot.h"


/**
 * @brief 89164 | 3c | Initialize multiboot data and set serial communication to multiplayer
 * 
 * @param pMultiBoot Multi boot param pointer
 */
void MultiBootInit(struct MultiBootData* pMultiBoot)
{
    pMultiBoot->clientBit = 0;
    pMultiBoot->probeCount = 0;
    pMultiBoot->responseBit = 0;
    pMultiBoot->checkWait = 15;
    pMultiBoot->sendFlag = FALSE;
    pMultiBoot->handshakeTimeout = 0;

    write16(REG_RNCT, 0);
    write16(REG_SIO, SIO_MULTI_MODE | SIO_BAUD_RATE_115200);
    write16(REG_SIO_DATA8, 0);
}

/**
 * @brief 891a0 | 3f0 | Handles transfer of multiboot data over serial communication
 * @param pMultiBoot Multi boot data pointer
 * @return u32 Status of the connection, non-zero is error
 */
u32 MultiBootMain(struct MultiBootData* pMultiBoot)
{
    s32 mask;
    s32 i;
    s32 value;

    if (MultiBootCheckComplete(pMultiBoot))
    {
        /* Transfer is complete so no other processing done */
        return 0;
    }

    if (pMultiBoot->checkWait > 15)
    {
        /* After system call error, do not send anything,
         * and wait for client to have timeout error.
         */
        pMultiBoot->checkWait--;
        return 0;
    }

output_burst:
    if (pMultiBoot->sendFlag)
    {
        pMultiBoot->sendFlag = FALSE;

        /* There is a problem if SIO is busy at this point, or an error was received.
         * There may be a problem with the connection(connected to JOY) and      
         * communication does not have timeout error.
         * When the connection ID is not the parent, or there is a bad connection, or the receive ID was set to child, an error occurs.
         */
        i = read16(REG_SIO) & (SIO_START_BIT_ACTIVE | SIO_MULTI_ERROR | SIO_MULTI_CONNECTION_ID_FLAG | SIO_MULTI_CONNECTION_READY | SIO_MULTI_RECEIVE_ID);
        if (i != SIO_MULTI_CONNECTION_READY)
        {
            MultiBootInit(pMultiBoot);
            return i ^ SIO_MULTI_CONNECTION_READY;
        }
    }

    if (pMultiBoot->probeCount >= 0xe0)
    {
        /* Check(handshake) to see if all children booted properly. */
        i = MultiBootHandshake(pMultiBoot);
        if (i)
        {
            return i;
        }

        /* If Low speed recognition mode, handshake also 2bytes communication, call
         * If High speed recognition mode, handshake also high speed communication.
         */
        if (pMultiBoot->serverType == MULTIBOOT_SERVER_TYPE_QUICK && pMultiBoot->probeCount > 0xe1 && !MultiBootCheckComplete(pMultiBoot))
        {
            MultiBootWaitSendDone();
            goto output_burst;
        }

        /* Timeout check */
        if (!MultiBootCheckComplete(pMultiBoot))
        {
            if (pMultiBoot->handshakeTimeout == 0)
            {
                MultiBootInit(pMultiBoot);
                return MULTIBOOT_ERROR_HANDSHAKE_FAILURE;
            }
            pMultiBoot->handshakeTimeout--;
        }

        return 0;
    }

    switch (pMultiBoot->probeCount)
    {
        case 0:
            /* client not doing recognition
             * Value should be CLIENT_INFO 000 0 ccc 0
             * First, check if some kind of response(other than 0xffff) 
             * from machine.
             */
            mask = 0xE;

            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                if (READ_SIO_MULTI(i) != USHORT_MAX)
                {
                    break;
                }
                mask >>= 1;
            }

            mask &= 0xE; /* 4P-2P: d3-d1 is 1 */
            pMultiBoot->responseBit = mask; /* mark connected children */

            /* Machine recognized as client, 
             * must be CLIENT_INFO 000 0 ccc 0.
             */
            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                value = READ_SIO_MULTI(i);

                if (pMultiBoot->clientBit & (1 << i))
                {
                    if (value != ((MULTIBOOT_CLIENT_INFO << 8) | (1 << i)))
                    {
                        mask = 0;
                        break;
                    }
                }
            }

            pMultiBoot->clientBit &= mask; /* update recognized children */

            if (mask == 0)
            {
                /* From client, until at least one returns value other than 
                 * 0xffff, maintain fixed time until redo of recognition processing
                 */
                pMultiBoot->checkWait = 15;
            }

            if (pMultiBoot->checkWait)
            {
                pMultiBoot->checkWait--;
            }
            else
            {
                /* If machine with response and client status do not match up,
                 * do recognition processing again.
                 */
                if (pMultiBoot->responseBit != pMultiBoot->clientBit)
                {
                    MultiBootStartProbe(pMultiBoot);
                    goto case_1;
                }
            }

            output_parent_info:
            /* Output PARENT_INFO 000 0 ccc 0. */
            return MultiBootSend(pMultiBoot, pMultiBoot->clientBit | (MULTIBOOT_PARENT_INFO << 8));

        case_1:
        case 1:
            /* Start recognition.
             * Those where in data is CLIENT_INFO 000 0 ccc 0
             * are recognized.
             */
            pMultiBoot->probeTargetBit = 0;

            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                value = READ_SIO_MULTI(i);
                if ((value >> 8) == MULTIBOOT_CLIENT_INFO)
                {
                    /* Check validity of 000 0 ccc 0.
                     * If 4P, 0x08
                     * If 3P, 0x04
                     * If 2P, 0x02
                     * If not so, invalid.
                     */
                    gMultiBootRequiredData[i - 1] = value; /* During processing next time must be same value */
                    value &= 0xFF;
                    if (value == (1 << i))
                    {
                        pMultiBoot->probeTargetBit |= value; /* recognized */
                    }
                }
            }

            if (pMultiBoot->responseBit != pMultiBoot->probeTargetBit)
            {
                goto output_parent_info;
            }

            /* Send PARENT_START_PROBE 000 0 ccc 0.
             * Here the recognized bits are 000, ccc.
             * If not possible that 000 or ccc, not recognized by parent.
             */
            pMultiBoot->probeCount = 2;
            return MultiBootSend(pMultiBoot, pMultiBoot->probeTargetBit | (MULTIBOOT_PARENT_START_PROBE << 8));

        case 2:
            /* Must be CLIENT_INFO 000 0 ccc 0.
             * Output header +0, +1 bytes.
             */
            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                if (pMultiBoot->probeTargetBit & (1 << i))
                {
                    value = READ_SIO_MULTI(i);
                    if (value != gMultiBootRequiredData[i - 1])
                    {
                        pMultiBoot->probeTargetBit ^= 1 << i;
                    }
                }
            }
            goto output_header;

        case 0xd0:
            /* Request for start of parent server.
             * If CLIENT_INFO 000 0 ccc 0, not ready
             * to download client.
             * If all clients CLIENT_DL_READY, call system
             * call and transfer boot program.
             */
            mask = 1; /* Okay to go to download start? */
            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                value = READ_SIO_MULTI(i);
                /* handshake data from client
                 * Regardless of recognition, save for all machines
                 */
                pMultiBoot->clientData[i - 1] = value;

                if (pMultiBoot->probeTargetBit & (1 << i))
                {
                    if ((value >> 8) != MULTIBOOT_CLIENT_INFO && (value >> 8) != MULTIBOOT_CLIENT_DL_READY)
                    {
                        MultiBootInit(pMultiBoot);
                        return MULTIBOOT_ERROR_NO_DL_READY; /* No response saying ready to do download */
                    }

                    if (value == gMultiBootRequiredData[i - 1])
                    {
                        /* CLIENT_INFO 000 0 ccc 0
                         * Was at least one machine not ready for download,
                         * so not start download yet.
                         */
                        mask = 0;
                    }
                }
            }

            if (mask == 0)
            {
                /* Not start download yet.
                 * Send request for download preparation
                 */
                return MultiBootSend(pMultiBoot, pMultiBoot->paletteData | (MULTIBOOT_PARENT_REQUEST_DL_READY << 8));
            }

            /* All machines ready to download */
            pMultiBoot->probeCount = 0xd1;
            mask = 0x11;

            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                /* handshake data */
                mask += pMultiBoot->clientData[i - 1];
            }

            pMultiBoot->handshakeData = mask;

            return MultiBootSend(pMultiBoot, (mask & 0xFF) | (MULTIBOOT_PARENT_START_DL << 8));

        case 0xd1:
            /* Send PARENT_START_DL
             * Should be CLIENT_DL_READY.
             */
            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                value = READ_SIO_MULTI(i);

                if (pMultiBoot->probeTargetBit & (1 << i))
                {
                    if ((value >> 8) != MULTIBOOT_CLIENT_DL_READY)
                    {
                        MultiBootInit(pMultiBoot);
                        return MULTIBOOT_ERROR_NO_DL_READY; /* No response saying ready to do download */
                    }
                }
            }

            i = Multiboot(pMultiBoot);

            if (i == FALSE)
            {
                pMultiBoot->probeCount = 0xe0;
                pMultiBoot->handshakeTimeout = 400;
                return 0;
            }

            MultiBootInit(pMultiBoot);
            /* With system call failure, possible that client still in
             * receive data status.
             * Therefore, until retry, do not send anything including PARENT_INFO,
             * during time for "Client has timeout error".
             */
            pMultiBoot->checkWait = 30;
            return MULTIBOOT_ERROR_BOOT_FAILED;

        default:
            /* 4-...: Doing recognition processing
             * 4 -> +0,1 byte
             * 6 -> +2,3
             * 8 -> +4,5
             *  :
             * 0xc2 -> +0xbe, 0xbf byte
             * Output header data.
             */
            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                if (pMultiBoot->probeTargetBit & (1 << i))
                {
                    value = READ_SIO_MULTI(i);

                    if ((value >> 8) != ((MULTIBOOT_PARENT_START_PROBE + 1) - (pMultiBoot->probeCount >> 1)) || (value & 0xFF) != (1 << i))
                    {
                        /* Problem with client recognition */
                        pMultiBoot->probeTargetBit ^= 1 << i;
                    }
                }
            }

            if (pMultiBoot->probeCount == 0xc4)
            {
                /* From recognized, those leftover last are 
                 * qualified as client.
                 */
                pMultiBoot->clientBit = pMultiBoot->probeTargetBit & 0xE;
                pMultiBoot->probeCount = 0;
                goto output_parent_info;
            }
            break;
    }
    
    output_header:
    /* If no target, ends with error in middle. */
    if (pMultiBoot->probeTargetBit == 0)
    {
        MultiBootInit(pMultiBoot);
        return MULTIBOOT_ERROR_NO_PROBE_TARGET; /* No recognized target */
    }

    pMultiBoot->probeCount += 2;
    if (pMultiBoot->probeCount == 0xc4)
    {
        /* When getting final data, send PARENT_INFO 000 0 ccc 0.
         * If do not problem with timing.
         */
        goto output_parent_info;
    }

    i = MultiBootSend(pMultiBoot, C_16_2_8(pMultiBoot->dataSentPointer[pMultiBoot->probeCount - 3], pMultiBoot->dataSentPointer[pMultiBoot->probeCount - 4]));
    if (i)
    {
        return i;
    }

    /* If Low speed recognition mode, for each frame of call, 2 bytes of 
     * communication.
     * If High speed recognition mode,
     * (time to end of communication + sufficient time for child 
     * interrupt processing)
     * Wait, continued communication.
     */
    if (pMultiBoot->serverType == MULTIBOOT_SERVER_TYPE_QUICK)
    {
        MultiBootWaitSendDone();
        goto output_burst;
    }
    return 0;
}

/**
 * @brief 89590 | 4c | Send data
 * 
 * @param pMultiBoot Multi boot param pointer
 * @param data Data to send
 * @return u16 Status of the connection, non-zero is error
 */
u32 MultiBootSend(struct MultiBootData* pMultiBoot, u16 data)
{
    /* If still busy at this point, problem has occurred.
     * There may be a problem with the connection(connected to JOY) and      
     * communication does not have timeout error.
     * (reconnect cable) May be first communication so no check for
     * error bit or connection ID.
     */
    u16 control = read16(REG_SIO) & (SIO_START_BIT_ACTIVE | SIO_MULTI_CONNECTION_READY | SIO_MULTI_RECEIVE_ID);
    if (control != SIO_HIGH_DURING_INACTIVITY)
    {
        MultiBootInit(pMultiBoot);
        return control ^ SIO_MULTI_CONNECTION_READY;
    }

    write16(REG_SIO_DATA8, data);
    write16(REG_SIO, SIO_MULTI_MODE | SIO_START_BIT_ACTIVE | SIO_BAUD_RATE_115200);
    pMultiBoot->sendFlag = TRUE;
    return FALSE;
}

/**
 * @brief 895dc | 24 | Begin recognizing the client
 * 
 * @param pMultiBoot Multi boot param pointer
 */
void MultiBootStartProbe(struct MultiBootData* pMultiBoot)
{
    if (pMultiBoot->probeCount != 0)
    {
        MultiBootInit(pMultiBoot);
        return;
    }

    pMultiBoot->checkWait = 0;
    pMultiBoot->clientBit = 0;
    pMultiBoot->probeCount = 1;
}

/**
 * @brief 89600 | b8 | Starts data transfer from the parent
 * 
 * @param pMultiBoot Multi boot param pointer
 * @param src Data source pointer
 * @param length Data size
 * @param palette_color Palette to flash
 * @param palette_speed Speed of palette flash
 */
void MultiBootStartParent(struct MultiBootData* pMultiBoot, const u8* src, s32 length, u8 palette_color, s8 palette_speed)
{
    s32 paletteData;
    s32 var_2;

    var_2 = palette_speed;
    
    if (pMultiBoot->probeCount != 0 || pMultiBoot->clientBit == 0 || pMultiBoot->checkWait != 0)
    {
        /* Recognition processing, cannot do processing */
        MultiBootInit(pMultiBoot);
        return;
    }

    pMultiBoot->bootSourcePointer = src;
    length = (length + 15) & ~15; /* 16 byte units */

    if (length < MULTIBOOT_SEND_SIZE_MIN || length > MULTIBOOT_SEND_SIZE_MAX)
    {
        MultiBootInit(pMultiBoot);
        return;
    }

    pMultiBoot->bootEndPointer = src + length;

    switch (palette_speed)
    {
        case -4:
        case -3:
        case -2:
        case -1:
            paletteData = (palette_color << 3) | (3 - var_2);
            break;

        case 0:
            paletteData = palette_color | 0x38;
            break;

        case 1:
        case 2:
        case 3:
        case 4:
            paletteData = (palette_color << 3) | (var_2 - 1);
            break;
    }

    pMultiBoot->paletteData = ((paletteData & 0x3F) << 1) | 0x81;
    pMultiBoot->probeCount = 0xD0;
}

/**
 * @brief 896b8 | 14 | Check if the transfer was completed
 * 
 * @param pMultiBoot Multi boot param pointer
 * @return u32 bool, transfer was completed
 */
u32 MultiBootCheckComplete(struct MultiBootData* pMultiBoot)
{
    if (pMultiBoot->probeCount == 0xE9)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 * @brief 896cc | ec | To document
 * 
 * @param pMultiBoot Multi boot param pointer
 * @return u32 SIOCNT
 */
u32 MultiBootHandshake(struct MultiBootData* pMultiBoot)
{
    s32 i;
    u16 value;

    switch (pMultiBoot->probeCount)
    {
        case 0xe0:
            c_0xe0:
            /* Parent sends 0x0000. */
            pMultiBoot->probeCount = 0xe1;
            pMultiBoot->systemWork_1[1] = 0;
            pMultiBoot->systemWork_1[0] = 0x100000; /* Right before next send >> 5  */

            return MultiBootSend(pMultiBoot, 0);

        default:
            /* 0xe1-0xe6
             * If expected data does not come, do again from case_0xe0.
             * 0xe1: After parent sends 0x0000. All children must be 0x0000.
             * 0xe2: After parent sends 0x8000. All children must be 0x0000.
             * 0xe3:        0x0400                            0x8000
             * 0xe4:        0x0020                            0x0400
             * 0xe5:        0x0001                            0x0020
             * 0xe6:        0x0000                            0x0001
             */
            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                value = READ_SIO_MULTI(i);
                if ((pMultiBoot->clientBit & (1 << i)) && value != pMultiBoot->systemWork_1[1])
                {
                    /* Expected data still hasn't come from all children. */
                    goto c_0xe0;
                }
            }

            pMultiBoot->probeCount++;
            pMultiBoot->systemWork_1[1] = pMultiBoot->systemWork_1[0] & 0xFFFF;
            if (pMultiBoot->systemWork_1[0] == 0)
            {
                /* This time send initial code low. */
                pMultiBoot->systemWork_1[1] = C_16_2_8_(pMultiBoot->dataSentPointer[0xAD], pMultiBoot->dataSentPointer[0xAC]);
                pMultiBoot->systemWork_1[0] = pMultiBoot->systemWork_1[1] << 5; /* right before sending >> 5 */
            }

            pMultiBoot->systemWork_1[0] >>= 5;

            output_common:
            return MultiBootSend(pMultiBoot, pMultiBoot->systemWork_1[0]);

        case 0xe7: /* Parent sent initial code, low. All children must be same. */
        case 0xe8: /* Parent sent initial code, high. All children must be same. */
            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                value = READ_SIO_MULTI(i);
                if ((pMultiBoot->clientBit & (1 << i)) && value != pMultiBoot->systemWork_1[1])
                {
                    /* Desired data did not come from all children.
                     * If reach this point and have error, stop(infinite loop) child, 
                     * and no retry by parent.
                     * On parent's screen display,
                     * "Communication failure. Turn off power and check connection. 
                     *  Turn on power again."
                     */
                    MultiBootInit(pMultiBoot);
                    return MULTIBOOT_ERROR_HANDSHAKE_FAILURE;
                }
            }

            pMultiBoot->probeCount++;
            if (pMultiBoot->probeCount == 0xe9)
            {
                /* Handshake Success! */
                return 0;
            }

            /* This time send the initial code, high. */
            pMultiBoot->systemWork_1[0] = C_16_2_8_(pMultiBoot->dataSentPointer[0xAF], pMultiBoot->dataSentPointer[0xAE]);
            pMultiBoot->systemWork_1[1] = pMultiBoot->systemWork_1[0];

            #ifndef NON_MATCHING
            goto output_common;
            #else // NON_MATCHING
            return MultiBootSend(pMultiBoot, pMultiBoot->systemWork_1[0]);
            #endif // NON_MATCHING
    }
}

/**
 * @brief 897b8 | 18 | Wait for an amount of cycles for the child to interrupt
 * 
 * @param cycles Cycles to wait
 */
NAKED_FUNCTION
void MultiBootWaitCycles(s32 cycles)
{
    // Assumed to be hand written due to the use of PC and no cmp before the bgt
    // Closest approximation: https://decomp.me/scratch/4CRCE

    /* Depending on if this is in CPU internal working, CPU external 
     * working, ROM, the CPU cycles used for one of this function's wait 
     * loops is different.
     * CPU External Working (0x02XXXXXX) ... 12 cycles/loop
     * ROM        (0x08XXXXXX) ... 13 cycles/loop 
     *            (Have prefetch  Setup maximum speed)
     * CPU Internal Working (0x03XXXXXX) ... 4  cycles/loop
     * If address area other than above, temporarily use 4 cycles/loop.
     * If set up lower cycles/loop than actual, 
     * can get specified cycle number wait.
     *
     * Use AGB system clock 16.78MHz as hint for argument, cycles.
     * If use 0x1000000 (16777216) with cycles approximately 1 second wait.
     * (If V blank interrupt is processed during this, actual wait is longer)
     */

    asm("                            \n\
        mov r2, pc                   \n\
        lsr r2, r2, #0x18            \n\
        movs r1, #0xc                \n\
        cmp r2, #2                   \n\
        beq MultiBootWaitCyclesLoop  \n\
        mov r1, #0xd                 \n\
        cmp r2, #8                   \n\
        beq MultiBootWaitCyclesLoop  \n\
        mov r1, #4                   \n\
    MultiBootWaitCyclesLoop:         \n\
        sub r0, r0, r1               \n\
        bgt MultiBootWaitCyclesLoop  \n\
        bx lr                        \n\
    ");
}

/**
 * @brief 897d0 | 3c | Wait up to one frame for communication to be completed
 */
void MultiBootWaitSendDone(void)
{
    s32 i;

    /* If cannot detect communication end within fixed time(1 frame),
     * remove loop.
     * Even if fast this loop takes 9 cycles/loop,
     * (ldr=3, and=1, branch skip=1, i++=1, branch=3)
     * try loop for 1 frame.
     * Number of times do loop is,
     * 0x1000000 (16.78MHz=cycles/sec) / 60 (frames/sec) / 9 (cycles/loop)
     * = approximately 31069 (loops/frame)
     */
    for (i = 0; i <= (u16)(CLOCKRATE / FRAMES_PER_SECOND / 9); i++)
    {
        if ((read16(REG_SIO) & SIO_START_BIT_ACTIVE) == 0)
        {
            break;
        }
    }

    MultiBootWaitCycles(600);
}
