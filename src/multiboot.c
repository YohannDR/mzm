#include "cable_link.h"
#include "macros.h"
#include "gba.h"
#include "multiboot.h"
#include "link.h"

#include "data/cable_link_data.h"
#include "data/io_transfer_data.h"

#include "constants/cable_link.h"

#include "structs/multiboot.h"


/**
 * @brief 89164 | 3c | Resets the transfer and multi boot data
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
    write16(REG_SIO, SIO_MP_BAUD_RATE_115200 | SIO_NON_NORMAL_MODE);
    write16(REG_SIO_DATA8, 0);
}

/**
 * @brief 891a0 | 3f0 | Handles sending multi boot data
 * @return u32 Error flags
 */
u32 MultiBootMain(struct MultiBootData* pMultiBoot)
{
    s32 mask;
    s32 i;
    s32 value;

    if (MultiBootCheckComplete(pMultiBoot))
        return 0;

    if (pMultiBoot->checkWait > 15)
    {
        pMultiBoot->checkWait--;
        return 0;
    }

output_burst:
    if (pMultiBoot->sendFlag)
    {
        pMultiBoot->sendFlag = FALSE;
        i = read16(REG_SIO) & (u8)~(SIO_SHIFT_INTERNAL_CLOCK_FLAG | SIO_SHIFT_INTERNAL_CLOCK_2MHZ);

        if (i != SIO_HIGH_DURING_INACTIVITY)
        {
            MultiBootInit(pMultiBoot);
            return i ^ SIO_HIGH_DURING_INACTIVITY;
        }
    }

    if (pMultiBoot->probeCount >= 224)
    {
        i = MultiBootHandshake(pMultiBoot);
        if (i)
        {
            return i;
        }

        if (pMultiBoot->serverType == 1 && pMultiBoot->probeCount > 225 && MultiBootCheckComplete(pMultiBoot) == 0)
        {
            MultiBootWaitSendDone();
            goto output_burst;
        }

        if (MultiBootCheckComplete(pMultiBoot) == 0)
        {
            if (pMultiBoot->handshakeTimeout == 0)
            {
                MultiBootInit(pMultiBoot);
                return (0x10 | 0x20 | 0x40 | SIO_SHIFT_INTERNAL_CLOCK_FLAG);
            }
            pMultiBoot->handshakeTimeout--;
        }

        return 0;
    }

    switch (pMultiBoot->probeCount)
    {
        case 0:
            mask = 0xE;

            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                if (READ_SIO_MULTI(i) != USHORT_MAX)
                {
                    break;
                }
                mask >>= 1;
            }

            mask &= 0xE;
            pMultiBoot->responseBit = mask;

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

            pMultiBoot->clientBit &= mask;

            if (mask == 0)
            {
                pMultiBoot->checkWait = 15;
            }

            if (pMultiBoot->checkWait)
            {
                pMultiBoot->checkWait--;
            }
            else
            {
                if (pMultiBoot->responseBit != pMultiBoot->clientBit)
                {
                    MultiBootStartProbe(pMultiBoot);
                    goto case_1;
                }
            }

output_parent_info:
            return MultiBootSend(pMultiBoot, pMultiBoot->clientBit | (MULTIBOOT_PARENT_INFO << 8));

case_1:
        case 1:
            pMultiBoot->probeTargetBit = 0;

            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                value = READ_SIO_MULTI(i);
                if ((value >> 8) == MULTIBOOT_CLIENT_INFO)
                {
                    gMultibootRequiredData[i - 1] = value;

                    value &= 0xFF;

                    if (value == (1 << i))
                    {
                        pMultiBoot->probeTargetBit |= value;
                    }
                }
            }

            if (pMultiBoot->responseBit != pMultiBoot->probeTargetBit)
            {
                goto output_parent_info;
            }

            pMultiBoot->probeCount = 2;
            return MultiBootSend(pMultiBoot, pMultiBoot->probeTargetBit | (MULTIBOOT_PARENT_START_PROBE << 8));

        case 2:
            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                if (pMultiBoot->probeTargetBit & (1 << i))
                {
                    value = READ_SIO_MULTI(i);
                    if (value != gMultibootRequiredData[i - 1])
                    {
                        pMultiBoot->probeTargetBit ^= 1 << i;
                    }
                }
            }
            goto output_header;

        case 0xd0:
            mask = 1;
            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                value = READ_SIO_MULTI(i);
                pMultiBoot->clientData[i - 1] = value;

                if (pMultiBoot->probeTargetBit & (1 << i))
                {
                    if ((value >> 8) != MULTIBOOT_CLIENT_INFO && (value >> 8) != MULTIBOOT_CLIENT_DL_READY)
                    {
                        MultiBootInit(pMultiBoot);
                        return MULTIBOOT_ERROR_NO_DL_READY;
                    }

                    if (value == gMultibootRequiredData[i - 1])
                    {
                        mask = 0;
                    }
                }
            }

            if (mask == 0)
            {
                return MultiBootSend(pMultiBoot, pMultiBoot->paletteData | (MULTIBOOT_PARENT_REQUEST_DL_READY << 8));
            }

            pMultiBoot->probeCount = 0xd1;
            mask = 0x11;

            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                mask += pMultiBoot->clientData[i - 1];
            }

            pMultiBoot->handshakeData = mask;

            return MultiBootSend(pMultiBoot, (mask & 0xFF) | (MULTIBOOT_PARENT_START_DL << 8));

        case 209:
            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                value = READ_SIO_MULTI(i);

                if (pMultiBoot->probeTargetBit & (1 << i))
                {
                    if ((value >> 8) != MULTIBOOT_CLIENT_DL_READY)
                    {
                        MultiBootInit(pMultiBoot);
                        return MULTIBOOT_ERROR_NO_DL_READY;
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
            pMultiBoot->checkWait = 30;
            return MULTIBOOT_ERROR_BOOT_FAILED;

        default:
            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                if (pMultiBoot->probeTargetBit & (1 << i))
                {
                    value = READ_SIO_MULTI(i);

                    if ((value >> 8) != ((MULTIBOOT_PARENT_START_PROBE + 1) - (pMultiBoot->probeCount >> 1)) || (value & 0xFF) != (1 << i))
                    {
                        pMultiBoot->probeTargetBit ^= 1 << i;
                    }
                }
            }

            if (pMultiBoot->probeCount == 0xc4)
            {
                pMultiBoot->clientBit = pMultiBoot->probeTargetBit & 0xE;
                pMultiBoot->probeCount = 0;
                goto output_parent_info;
            }
    }
    
output_header:
    if (pMultiBoot->probeTargetBit == 0)
    {
        MultiBootInit(pMultiBoot);
        return MULTIBOOT_ERROR_NO_PROBE_TARGET;
    }

    pMultiBoot->probeCount += 2;
    if (pMultiBoot->probeCount == 0xc4)
    {
        goto output_parent_info;
    }

    i = MultiBootSend(pMultiBoot, C_16_2_8(pMultiBoot->dataSentPointer[pMultiBoot->probeCount - 3], pMultiBoot->dataSentPointer[pMultiBoot->probeCount - 4]));
    if (i)
    {
        return i;
    }

    if (pMultiBoot->serverType == MULTIBOOT_SERVER_TYPE_QUICK)
    {
        MultiBootWaitSendDone();
        goto output_burst;
    }
    return 0;
}


/**
 * @brief 89590 | 4c | Starts a data transfer
 * 
 * @param pMultiBoot Multi boot param pointer
 * @param data Data
 * @return u16 bool, could start? (to document)
 */
u32 MultiBootSend(struct MultiBootData* pMultiBoot, u16 data)
{
    u16 control = read16(REG_SIO) & (SIO_STATE_HIGH_OR_NONE | SIO_HIGH_DURING_INACTIVITY | SIO_START_BIT_ACTIVE);
    if (control != SIO_HIGH_DURING_INACTIVITY)
    {
        MultiBootInit(pMultiBoot);
        return control ^ SIO_HIGH_DURING_INACTIVITY;
    }

    write16(REG_SIO_DATA8, data);
    write16(REG_SIO, SIO_SHIFT_INTERNAL_CLOCK_FLAG | SIO_SHIFT_INTERNAL_CLOCK_2MHZ | SIO_START_BIT_ACTIVE | SIO_NON_NORMAL_MODE);
    pMultiBoot->sendFlag = TRUE;
    return FALSE;
}

/**
 * @brief 895dc | 24 | To document
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
 * @brief 89600 | b8 | To document
 * 
 * @param pMultiBoot Multi boot param pointer
 * @param src Data source pointer
 * @param length Data size
 * @param palette_color To document
 * @param palette_speed To document
 */
void MultiBootStartParent(struct MultiBootData* pMultiBoot, const u8* src, s32 length, u8 palette_color, s8 palette_speed)
{
    s32 paletteData;
    s32 var_2;

    var_2 = (s8)palette_speed;
    
    if (pMultiBoot->probeCount != 0 || pMultiBoot->clientBit == 0 || pMultiBoot->checkWait != 0)
    {
        MultiBootInit(pMultiBoot);
        return;
    }

    pMultiBoot->bootSourcePointer = src;
    length = (length + 15) & ~15;

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
    u32 value;
    u16 var_0;

    switch (pMultiBoot->probeCount)
    {
        case 224:
        c_224:
            pMultiBoot->probeCount = 225;
            pMultiBoot->systemWork_1[1] = 0;
            pMultiBoot->systemWork_1[0] = 0x100000;

            return MultiBootSend(pMultiBoot, 0);

        default:
            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                var_0 = READ_SIO_MULTI(i);
                if ((pMultiBoot->clientBit & (1 << i)) && var_0 != pMultiBoot->systemWork_1[1])
                {
                    goto c_224;
                    pMultiBoot->probeCount = 225;
                    pMultiBoot->systemWork_1[1] = 0;
                    pMultiBoot->systemWork_1[0] = 0x100000;
                    break;
                }
            }

            pMultiBoot->probeCount++;
            pMultiBoot->systemWork_1[1] = pMultiBoot->systemWork_1[0] & 0xFFFF;
            if (pMultiBoot->systemWork_1[0] == 0)
            {
                pMultiBoot->systemWork_1[1] = C_16_2_8_(pMultiBoot->dataSentPointer[0xAD], pMultiBoot->dataSentPointer[0xAC]);
                pMultiBoot->systemWork_1[0] = pMultiBoot->systemWork_1[1] << 5;
            }

            pMultiBoot->systemWork_1[0] >>= 5;

            output_common:
            return MultiBootSend(pMultiBoot, pMultiBoot->systemWork_1[0]);

        case 231:
        case 232:
            for (i = MULTIBOOT_MAX_CHILD; i != 0; i--)
            {
                var_0 = READ_SIO_MULTI(i);
                if ((pMultiBoot->clientBit & (1 << i)) && var_0 != pMultiBoot->systemWork_1[1])
                {
                    MultiBootInit(pMultiBoot);
                    return (0x10 | 0x20 | 0x40 | SIO_SHIFT_INTERNAL_CLOCK_FLAG);
                }
            }

            pMultiBoot->probeCount++;
            if (pMultiBoot->probeCount == 233)
                return 0;

            value = C_16_2_8_(pMultiBoot->dataSentPointer[0xAF], pMultiBoot->dataSentPointer[0xAE]);

            pMultiBoot->systemWork_1[0] = value;
            pMultiBoot->systemWork_1[1] = value;

            #ifndef NON_MATCHING
            goto output_common;
            #else // NON_MATCHING
            return MultiBootSend(pMultiBoot, pMultiBoot->systemWork_1[0]);
            #endif // NON_MATCHING
    }
}

/**
 * @brief 897b8 | 18 | Wait for an amount of cycles
 * 
 * @param cycles To document
 */
NAKED_FUNCTION
void MultiBootWaitCycles(s32 cycles)
{
    // Assumed to be hand written due to the use of PC and no cmp before the bgt
    // Closest approximation: https://decomp.me/scratch/4CRCE
    asm("                 \n\
        mov r2, pc        \n\
        lsr r2, r2, #0x18 \n\
        movs r1, #0xc     \n\
        cmp r2, #2        \n\
        beq lbl_080897ca  \n\
        mov r1, #0xd      \n\
        cmp r2, #8        \n\
        beq lbl_080897ca  \n\
        mov r1, #4        \n\
    lbl_080897ca:         \n\
        sub r0, r0, r1    \n\
        bgt lbl_080897ca  \n\
        bx lr             \n\
    ");
}

/**
 * @brief 897d0 | 3c | Wait one frame for communication to be completed
 * 
 */
void MultiBootWaitSendDone(void)
{
    s32 i;

    for (i = 0; i <= (u16)(CLOCKRATE / FRAMES_PER_SECOND / 9); i++)
    {
        if ((read16(REG_SIO) & SIO_START_BIT_ACTIVE) == 0)
        {
            break;
        }
    }

    MultiBootWaitCycles(600);
}
