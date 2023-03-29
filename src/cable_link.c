#include "cable_link.h"
#include "macros.h"
#include "gba.h"
#include "callbacks.h"
#include "music_wrappers.h"

#include "data/cable_link_data.h"

#include "structs/audio.h"
#include "structs/game_state.h"

/**
 * @brief 88ea0 | 270 | Processes the cable link connection
 * 
 * @return u8 Connection result
 */
u8 CableLinkProcess(void)
{
    u8 probeCount;
    
    gIoTransferInfo.result = 0;

    switch (gIoTransferInfo.unk_9)
    {
        case 0:
            gIoTransferInfo.timer = 0;
            FadeMusic(20);
            gIoTransferInfo.unk_9++;
            break;

        case 1:
            gIoTransferInfo.timer++;
            if (gIoTransferInfo.timer > 30)
            {
                unk_3458();
                gIoTransferInfo.musicTrack = gMusicInfo.musicTrack;
                gIoTransferInfo.musicPriority = gMusicInfo.priority;
                gIoTransferInfo.timer = 0;
                gIoTransferInfo.unk_9++;
            }
            break;

        case 2:
            CallbackSetSerialCommunication(unk_89be4);
            CallbackSetTimer3(unk_89bd4);

            gDataSentPointer = sTransferData_8754bd0;
            gDataSentSize = 0x87566c4 - (u32)sTransferData_8754bd0;
            gMultiBootParamData.dataSentPointer = sTransferData_8754bd0;
            gMultiBootParamData.serverType = 0;
            CableLinkResetTransfer(&gMultiBootParamData);
            gIoTransferInfo.timer = 0;
            gIoTransferInfo.unk_9++;
            break;

        case 3:
            gIoTransferInfo.timer++;
            if (gMultiBootParamData.clientBit & (2 | 4 | 8))
            {
                probeCount = gMultiBootParamData.probeCount;
                if (probeCount == 0xD1)
                    gIoTransferInfo.timer = 0;
                
                if (gMultiBootParamData.probeCount > 0xDF)
                    gIoTransferInfo.timer = 0;
            }

            if (gMultiBootParamData.probeCount == 0 && gMultiBootParamData.clientBit)
            {
                unk_89600(&gMultiBootParamData, gDataSentPointer + 0xC0, gDataSentSize - 0xC0, 4, 1);
            }

            gUnk_3005874 = unk_891a0(&gMultiBootParamData);

            if (unk_896b8(&gMultiBootParamData))
            {
                gUnk_3005884 = 0;
                gIoTransferInfo.unk_9++;
                break;
            }

            if (gMultiBootParamData.probeCount != 0xD1 && gChangedInput & KEY_B && gMultiBootParamData.probeCount < 0xE0)
            {
                gIoTransferInfo.unk_9 = 8;
                break;
            }

            if (gIoTransferInfo.timer > 180)
            {
                gIoTransferInfo.unk_9 = 7;
            }
            break;

        case 4:
            if (!unk_8980c(0x875e6a8 - (u32)sTransferData_87566c4, sTransferData_87566c4))
            {
                gIoTransferInfo.unk_9++;
                break;
            }

            gIoTransferInfo.unk_9 = 9;
            break;

        case 5:
            switch (gUnk_3005880)
            {
                case 0:
                    gIoTransferInfo.unk_9++;
                    break;

                case 1:
                    gIoTransferInfo.unk_9 = 8;
                    break;

                case 2:
                    gIoTransferInfo.unk_9 = 9;
                    break;
            }

        case 6:
            gIoTransferInfo.unk_9 = 10;
            break;

        case 7:
            gIoTransferInfo.result = 2;
            gIoTransferInfo.unk_9 = 11;
            break;

        case 8:
            gIoTransferInfo.result = 3;
            gIoTransferInfo.unk_9 = 11;
            break;

        case 9:
            gIoTransferInfo.result = 4;
            gIoTransferInfo.unk_9 = 11;
            break;

        case 10:
            gIoTransferInfo.active = 2;

        case 11:
            InitializeAudio();
            FileSelectApplyStereo();
            PlayMusic(gIoTransferInfo.musicTrack, gIoTransferInfo.musicPriority);
            gIoTransferInfo.unk_9 = 12;
            break;

        case 12:
            break;
    }

    return gIoTransferInfo.result;
}

/**
 * @brief 89110 | 84 | Draws an error string to the provided tilemap
 * 
 * @param str Error string
 * @param dst Destination
 * @param palette Palette
 */
void CableLinkDrawErrorStr(const u8* str, u16* dst, u8 palette)
{
    u16 letter;

    if (!gSramErrorFlag)
        return;

    while (*str)
    {
        letter = 0x28;
        if (*str >= '0')
        {
            if (*str <= '9')
                letter = *str - '0';
            else if (*str <= 'Z')
                letter = *str + -0x37;
        }

        *dst++ = letter | palette << 0xC;
        str++;
    }
}

/**
 * @brief 89164 | 3c | Resets the transfer and multi boot data
 * 
 * @param pMultiBoot Multi boot param pointer
 */
void CableLinkResetTransfer(struct MultiBootData* pMultiBoot)
{
    pMultiBoot->clientBit = 0;
    pMultiBoot->probeCount = 0;
    pMultiBoot->responseBit = 0;
    pMultiBoot->checkWait = 15;
    pMultiBoot->sendFlag = FALSE;
    pMultiBoot->handshakeTimeout = 0;

    write16(REG_RNCT, 0);
    write16(REG_SIO, SIO_SHIFT_INTERNAL_CLOCK_FLAG | SIO_SHIFT_INTERNAL_CLOCK_2MHZ | SIO_NON_NORMAL_MODE);
    write16(REG_SIO_DATA8, 0);
}

u32 unk_891a0(struct MultiBootData* pMultiBoot)
{
    // https://decomp.me/scratch/fqhAa

    u32 control;
    i32 mask;
    i32 i;

    if (unk_896b8(pMultiBoot))
        return 0;

    if (pMultiBoot->checkWait > 16)
    {
        pMultiBoot->checkWait--;
        return 0;
    }

    if (pMultiBoot->sendFlag)
    {
        pMultiBoot->sendFlag = FALSE;
        control = read16(REG_SIO) & (u8)~(SIO_SHIFT_INTERNAL_CLOCK_FLAG | SIO_SHIFT_INTERNAL_CLOCK_2MHZ);

        if (control != SIO_HIGH_DURING_INACTIVITY)
        {
            CableLinkResetTransfer(pMultiBoot);
            return control ^ SIO_HIGH_DURING_INACTIVITY;
        }
    }

    if (pMultiBoot->probeCount > 224)
    {
        control = unk_896cc(pMultiBoot);
        if (control)
            return control;

        if (pMultiBoot->serverType != 1 || pMultiBoot->probeCount < 226 || unk_896b8(pMultiBoot))
        {
            if (unk_896b8(pMultiBoot))
                return 0;

            if (pMultiBoot->handshakeTimeout != 0)
            {
                pMultiBoot->handshakeTimeout--;
                return 0;
            }

            CableLinkResetTransfer(pMultiBoot);
            return (0x10 | 0x20 | 0x40 | SIO_SHIFT_INTERNAL_CLOCK_FLAG);
        }
    }
    else
    {
        switch (pMultiBoot->probeCount)
        {
            case 0:
                mask = 0xE;

                for (i = 0; i < 3; i++)
                {
                    mask >>= 1;
                    if (read16(REG_SIO_MULTI + 3 + i) == USHORT_MAX)
                        break;
                }

                pMultiBoot->responseBit = mask & 0xE;
                break;

            case 1:
                break;

            case 2:
                break;

            case 208:
                break;

            case 209:
                break;
        }
    }
}

/**
 * @brief 89590 | 4c | Starts a data transfer
 * 
 * @param pMultiBoot Multi boot param pointer
 * @param data Data
 * @return u16 bool, could start? (to document)
 */
u32 CableLinkStartTransfer(struct MultiBootData* pMultiBoot, u16 data)
{
    u16 control = read16(REG_SIO) & (SIO_STATE_HIGH_OR_NONE | SIO_HIGH_DURING_INACTIVITY | SIO_START_BIT_ACTIVE);
    if (control != SIO_HIGH_DURING_INACTIVITY)
    {
        CableLinkResetTransfer(pMultiBoot);
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
void unk_895dc(struct MultiBootData* pMultiBoot)
{
    if (pMultiBoot->probeCount != 0)
    {
        CableLinkResetTransfer(pMultiBoot);
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
 * @param param_4 To document
 * @param param_5 To document
 */
void unk_89600(struct MultiBootData* pMultiBoot, const u8* src, i32 length, u8 param_4, u8 param_5)
{
    i32 size;
    i32 paletteData;
    u32 var_0;
    i8 var_1;
    i32 var_2;

    var_2 = (i8)param_5;
    
    if (pMultiBoot->probeCount != 0 || pMultiBoot->clientBit == 0 || pMultiBoot->checkWait)
    {
        CableLinkResetTransfer(pMultiBoot);
        return;
    }

    pMultiBoot->bootSourcePointer = src;
    size = ((length + 15) & -16);

    var_0 = size - 0x100;
    if (var_0 > 0x3FF00)
    {
        CableLinkResetTransfer(pMultiBoot);
        return;
    }

    pMultiBoot->bootEndPointer = src + size;

    var_1 = var_2 + 4;
    switch (var_1)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            paletteData = param_4 << 3;
            paletteData = paletteData | (3 - var_2);
            break;

        case 4:
            paletteData = param_4 | 0x38;
            break;

        case 5:
        case 6:
        case 7:
        case 8:
            paletteData = param_4 << 3;
            paletteData = paletteData | (var_2 - 1);
            break;
    }

    pMultiBoot->paletteData = ((paletteData & 0x3F) << 1) | -0x7F;
    pMultiBoot->probeCount = 0xD0;
}

/**
 * @brief 896b8 | 14 | To document
 * 
 * @param pMultiBoot Multi boot param pointer
 * @return u8 To document
 */
u32 unk_896b8(struct MultiBootData* pMultiBoot)
{
    if (pMultiBoot->probeCount == 0xE9)
        return TRUE;
    else
        return FALSE;
}

u32 unk_896cc(struct MultiBootData* pMultiBoot)
{
    // https://decomp.me/scratch/6M5KZ

    i32 i;
    u32 value;
    u16 var_0;

    switch (pMultiBoot->probeCount)
    {
        case 224:
        c_224:
            pMultiBoot->probeCount = 225;
            pMultiBoot->systemWork_1[1] = 0;
            pMultiBoot->systemWork_1[0] = 0x100000;

            return CableLinkStartTransfer(pMultiBoot, 0);
        
        default:
            for (i = 3; i != 0; i--)
            {
                var_0 = read16((u16*)REG_SIO_MULTI + i);
                if ((pMultiBoot->clientBit >> i) & 1 && var_0 != pMultiBoot->systemWork_1[1])
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
                value = pMultiBoot->dataSentPointer[0xAC];
                value |= pMultiBoot->dataSentPointer[0xAD] << 8;

                pMultiBoot->systemWork_1[1] = value;
                value <<= 5;
                pMultiBoot->systemWork_1[0] = value;
            }

            pMultiBoot->systemWork_1[0] /= 32;
            
            return CableLinkStartTransfer(pMultiBoot, pMultiBoot->systemWork_1[0]);

        case 231:
        case 232:
            for (i = 3; i != 0; i--)
            {
                var_0 = read16((u16*)REG_SIO_MULTI + i);
                if ((pMultiBoot->clientBit >> i) & 1 && var_0 != pMultiBoot->systemWork_1[1])
                {
                    CableLinkResetTransfer(pMultiBoot);
                    return (0x10 | 0x20 | 0x40 | SIO_SHIFT_INTERNAL_CLOCK_FLAG);
                }
            }

            pMultiBoot->probeCount++;
            if (pMultiBoot->probeCount == 233)
                return 0;
            
            value = pMultiBoot->dataSentPointer[0xAE];
            value |= pMultiBoot->dataSentPointer[0xAF] << 8;

            pMultiBoot->systemWork_1[0] = value;
            pMultiBoot->systemWork_1[1] = value;
            
            return CableLinkStartTransfer(pMultiBoot, pMultiBoot->systemWork_1[0]);
    }
}

/**
 * @brief 897b8 | 18 | Checks for the current memory region (where execution is)
 * 
 * @param param_1 To document
 */
NAKED_FUNCTION
void CableLinkCheckCurrentMemoryRegion(i32 param_1)
{
    // Assumed to be hand written due to the use of PC and no cmp before the bgt
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
 * @brief 897d0 | 3c | To document
 * 
 */
void unk_897d0(void)
{
    i32 i;

    i = 0;
    if (read16(REG_SIO) & SIO_START_BIT_ACTIVE)
    {
        while (++i < 0x795D && read16(REG_SIO) & SIO_START_BIT_ACTIVE);
    }

    CableLinkCheckCurrentMemoryRegion(0x258);
}

u32 unk_8980c(u32 data, const u8* pData)
{

}

void unk_898b8(void)
{

}

/**
 * @brief 8990c | 40 | To document
 * 
 */
void unk_8990c(void)
{
    write16(REG_IME, FALSE);
    write16(REG_IE, read16(REG_IE) & ~(IF_TIMER3 | IF_SERIAL));
    write16(REG_IME, TRUE);

    write16(REG_SIO, 0);
    write16(REG_TM3CNT_H, 0);
    write16(REG_IF, IF_TIMER3 | IF_SERIAL);
}

/**
 * @brief 8994c | 58 | To document
 * 
 */
void unk_8994c(void)
{
    write16(REG_IME, FALSE);
    write16(REG_IE, read16(REG_IE) & ~(IF_TIMER3 | IF_SERIAL));
    write16(REG_IME, TRUE);

    write16(REG_RNCT, 0);
    write16(REG_SIO, SIO_NON_NORMAL_MODE);

    write16(REG_SIO, read16(REG_SIO) | SIO_SHIFT_INTERNAL_CLOCK_FLAG | SIO_SHIFT_INTERNAL_CLOCK_2MHZ | SIO_IRQ_ENABLE);

    write16(REG_IME, FALSE);
    write16(REG_IE, read16(REG_IE) | IF_SERIAL);
    write16(REG_IME, TRUE);
}

/**
 * @brief 899a4 | 24 | To document
 * 
 */
void unk_899a4(void)
{
    write16(REG_RNCT, 0);
    write16(REG_SIO, SIO_32BIT_TRANSFER | SIO_IRQ_ENABLE);
    write16(REG_SIO, read16(REG_SIO) | SIO_HIGH_DURING_INACTIVITY);
}

u16 unk_899c8(u32 param_1, u32 data, const u8* pData)
{

}

u16 unk_89b3c(u32 param_1)
{

}

u16 unk_89b70(u32 data, u8* param_2)
{

}

/**
 * @brief 89ba0 | 34 | To document
 * 
 */
void unk_89ba0(void)
{
    write16(REG_TM3CNT_L, -101);
    write16(REG_TM3CNT_H, TIMER_CONTROL_IRQ_ENABLE);

    write16(REG_IME, FALSE);
    write16(REG_IE, read16(REG_IE) | IF_TIMER3);
    write16(REG_IME, TRUE);
}

/**
 * @brief 89bd4 | 10 | To document
 * 
 */
void unk_89bd4(void)
{
    unk_89d74();
    CableLinkSetSioCntStartBitActive();
}

void unk_89be4(void)
{

}

/**
 * @brief 89d64 | 10 | Sets the start bit of the SIO control register
 * 
 */
void CableLinkSetSioCntStartBitActive(void)
{
    write16(REG_SIO, read16(REG_SIO) | SIO_START_BIT_ACTIVE);
}

/**
 * @brief 89d74 | 24 | To document
 * 
 */
void unk_89d74(void)
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

u8 unk_89e30(void)
{

}

u8* CableLinkCheckError(void)
{

}

void unk_8a12c(u16 param_1)
{

}

void unk_8a1d4(void)
{

}

void unk_8a260(void)
{

}

void unk_8a2c8(void)
{

}

/**
 * @brief 8a39c | 10 | To document
 * 
 */
void unk_8a39c(void)
{
    unk_8a2c8();
    unk_8a260();
}

u32 CableLinkDetectError(u8* param_1, u8* param_2, u16* param_3)
{

}

/**
 * @brief 8a4cc | 2c | To document
 * 
 */
void unk_8a4cc(void)
{
    if ((read32(REG_SIO) & (SIO_STATE_HIGH_OR_NONE | SIO_HIGH_DURING_INACTIVITY)) == SIO_HIGH_DURING_INACTIVITY && gUnk_3005b60.unk_2 == 0)
        gUnk_3005b60.unk_0 = 8;
    else
        gUnk_3005b60.unk_0 = 0;
}

/**
 * @brief 8a4f8 | 50 | To document
 * 
 */
void unk_8a4f8(void)
{
    if (gUnk_3005b60.unk_0 != 0)
    {
        write16(REG_TM3CNT_L, -132);
        write16(REG_TM3CNT_H, TIMER_CONTROL_IRQ_ENABLE | 1);

        gUnk_30058d0 = read16(REG_IME);
        write16(REG_IME, FALSE);
        write16(REG_IE, read16(REG_IE) | IF_TIMER3);
        write16(REG_IME, gUnk_30058d0);
    }
}

void unk_8a548(u16* param_1)
{

}

void unk_8a628(u16* param_1)
{

}

/**
 * @brief 8a730 | 70 | To document
 * 
 */
void unk_8a730(void)
{
    if (gUnk_3005b60.unk_0)
    {
        if (gUnk_3005b60.unk_1 != 2)
        {
            if (gUnk_3005b60.unk_1 != 4)
                return;

            if (gUnk_3005b60.unk_D < 3)
            {
                if (gUnk_3005b60.unk_12 == 0)
                    gUnk_3005b60.unk_15 = 1;
                else
                    CableLinkSetSioCntStartBitActive_Duplicate();

                return;
            }

            if (gUnk_3005b60.unk_15 == 0)
            {
                gUnk_3005b60.unk_D = 0;
                CableLinkSetSioCntStartBitActive_Duplicate();
            }
            return;
        }

        CableLinkSetSioCntStartBitActive_Duplicate();
        return;
    }
    
    if (gUnk_3005b60.unk_1 != 4 && gUnk_3005b60.unk_1 != 2)
        return;

    gUnk_30058d2++;
    if (gUnk_30058d2 <= 10)
        return;

    if (gUnk_3005b60.unk_1 == 4)
    {
        gUnk_3005b60.unk_15 = 2;
    }
    
    if (gUnk_3005b60.unk_1 == 2)
    {
        gUnk_3005b60.unk_2 = 0;
        gUnk_3005b60.unk_3 = 0;
        gUnk_3005b60.unk_11 = 0;
    }
}

/**
 * @brief 8a7a0 | 10 | To document
 * 
 */
void unk_8a7a0(void)
{
    unk_8aaf0();
    CableLinkSetSioCntStartBitActive_Duplicate();
}

/**
 * @brief 8a7b0 | 90 | To document
 * 
 */
void unk_8a7b0(void)
{
    u32 control;

    control = read32(REG_SIO);
    gUnk_3005b60.unk_2 = control << 0x1A >> 0x1E;

    switch (gUnk_3005b60.unk_1)
    {
        case 4:
            if (control & 0x40)
                gUnk_3005b60.unk_12 = TRUE;

            unk_8a94c();
            unk_8aa54();
            unk_8ab24();
            break;

        case 2:
            if (!unk_8a850())
                break;

            if (gUnk_3005b60.unk_0)
            {
                gUnk_3005b60.unk_1 = 3;
                gUnk_3005b60.unk_D = 2;
            }
            else
            {
                gUnk_3005b60.unk_1 = 4;
            }
            break;
    }

    gUnk_3005b60.unk_D++;
    gUnk_30058d2 = FALSE;

    if (gUnk_3005b60.unk_D == 2)
        gUnk_3005b54 = gUnk_3005b60.unk_1A1;
}

/**
 * @brief 8a840 | 10 | Sets the start bit of the SIO control register
 * 
 */
void CableLinkSetSioCntStartBitActive_Duplicate(void)
{
    write16(REG_SIO, read16(REG_SIO) | SIO_START_BIT_ACTIVE);
}

u8 unk_8a850(void)
{
    // https://decomp.me/scratch/nQQf8

    u16 data8;
    u16 data;
    u8 i;
    u8 var_0;
    u32 data_0;
    u32 data_1;
    u32* ptr;

    var_0 = 0;

    data8 = USHORT_MAX;

    if (gUnk_3005b60.unk_10 == 1)
        write16(REG_SIO_DATA8, 0x8FFF);
    else
        write16(REG_SIO_DATA8, 0x7C40);

    gUnk_3005b60.unk_10 = 0;

    ptr = REG_SIO_MULTI;
    data_1 = ptr[1];
    data_0 = ptr[0];

    *(u32*)&gUnk_3005b60.sioIncomingData[0] = data_0;
    *(u32*)&gUnk_3005b60.sioIncomingData[2] = data_1;

    for (i = 0; i < 2; i++)
    {
        data = gUnk_3005b60.sioIncomingData[i];
    
        if ((data & -4) == 0x7C40 || data == 0x8FFF)
        {
            var_0++;

            if (data8 > data && data)
                data8 = data;
        }
        else if (data != 0xFFFF)
        {
            var_0 = 0;
            break;
        }
        else if (i == gUnk_3005b60.unk_2)
            var_0 = 0;
    }

    gUnk_3005b60.unk_3 = var_0;

    if (gUnk_3005b60.unk_3 > 1)
    {
        if (gUnk_3005b60.unk_3 == gUnk_30058d5 && gUnk_3005b60.sioIncomingData[0] == 0x8FFF)
            return TRUE;
    
        if (gUnk_3005b60.unk_3 > 1)
        {
            data &= 3;
            gUnk_3005b60.unk_11 = data + 1;
        }
        else
        {
            gUnk_3005b60.unk_11 = 0;
        }
    }
    else
    {
        gUnk_3005b60.unk_11 = 0;
    }

    gUnk_30058d5 = gUnk_3005b60.unk_3;

    return FALSE;
}

void unk_8a94c(void)
{

}

/**
 * @brief 8aa54 | 9c | To document
 * 
 */
void unk_8aa54(void)
{
    if (gUnk_3005b60.unk_18 == 2)
    {
        write16(REG_SIO_DATA8, gUnk_3005b60.unk_16);

        if (!gUnk_30058d3)
        {
            gUnk_3005b60.unk_9D--;
            gUnk_3005b60.unk_9C++;

            if (gUnk_3005b60.unk_9C > 31)
                gUnk_3005b60.unk_9C = 0;
        }
        else
        {
            gUnk_30058d3 = FALSE;
        }
    }
    else
    {
        if (gUnk_3005b60.unk_18 == 0 && gUnk_3005b60.unk_9D == 0)
            gUnk_30058d3 = TRUE;

        if (gUnk_30058d3)
        {
            write16(REG_SIO_DATA8, 0);
        }
        else
        {
            write16(REG_SIO_DATA8, gUnk_3005b60.unk_1C[gUnk_3005b60.unk_18][gUnk_3005b60.unk_9C]);
        }

        gUnk_3005b60.unk_18++;
    }
}

/**
 * @brief 8aaf0 | 34 | To document
 * 
 */
void unk_8aaf0(void)
{
    if (gUnk_3005b60.unk_0)
    {
        write16(REG_TM3CNT_H, read16(REG_TM3CNT_H) & ~TIMER_CONTROL_ACTIVE);
        write16(REG_TM3CNT_L, -132);
    }
}

/**
 * @brief 8ab24 | 30 | To document
 * 
 */
void unk_8ab24(void)
{
    if (gUnk_3005b60.unk_19 == 2)
    {
        gUnk_3005b60.unk_18 = 0;
        gUnk_3005b60.unk_19 = 0;
    }
    else if (gUnk_3005b60.unk_0)
    {
        write16(REG_TM3CNT_H, read16(REG_TM3CNT_H) | TIMER_CONTROL_ACTIVE);
    }
}

/**
 * @brief 8ab54 | 48 | To document
 * 
 */
void unk_8ab54(void)
{
    u8 i;
    u8 j;

    gUnk_3005b60.unk_9D = 0;
    gUnk_3005b60.unk_9C = 0;

    for (i = 0; i < ARRAY_SIZE(gUnk_3005b60.unk_1C); i++)
    {
        for (j = 0; j < ARRAY_SIZE(gUnk_3005b60.unk_1C[0]); j++)
        {
            gUnk_3005b60.unk_1C[i][j] = 0xEFFF;
        }
    }
}

/**
 * @brief 8ab9c | 5c | To document
 * 
 */
void unk_8ab9c(void)
{
    u8 i;
    u8 j;
    u8 k;

    gUnk_3005b60.unk_1A1 = 0;
    gUnk_3005b60.unk_1A0 = 0;

    for (i = 0; i < ARRAY_SIZE(gUnk_3005b60.unk_A0); i++)
    {
        for (j = 0; j < ARRAY_SIZE(gUnk_3005b60.unk_A0[0]); j++)
        {
            for (k = 0; k < ARRAY_SIZE(gUnk_3005b60.unk_A0[0][0]); k++)
            {
                gUnk_3005b60.unk_A0[i][j][k] = 0xEFFF;
            }
        }
    }
}
