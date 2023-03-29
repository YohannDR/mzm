#include "cable_link.h"
#include "macros.h"
#include "gba.h"
#include "callbacks.h"
#include "music_wrappers.h"

#include "data/cable_link_data.h"

#include "structs/audio.h"
#include "structs/game_state.h"

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
        if (*str > 0x2F)
        {
            if (*str < 0x3A)
                letter = *str - 0x30;
            else if (*str < 0x5B)
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

}

/**
 * @brief 89590 | 4c | Starts a data transfer
 * 
 * @param pMultiBoot Multi boot param pointer
 * @param data Data
 * @return u16 bool, could start? (to document)
 */
u16 CableLinkStartTransfer(struct MultiBootData* pMultiBoot, u16 data)
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

u16 unk_896cc(struct MultiBootData* pMultiBoot)
{

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

void unk_8a39c(void)
{

}

u32 CableLinkDetectError(u8* param_1, u8* param_2, u16* param_3)
{

}

void unk_8a4cc(void)
{

}

void unk_8a4f8(void)
{

}

void unk_8a548(u16* param_1)
{

}

void unk_8a628(u16* param_1)
{

}

void unk_8a730(void)
{

}

void unk_8a7a0(void)
{

}

void unk_8a7b0(void)
{

}

void CableLinkSetSioCntStartBitActive_Duplicate(void)
{

}

u8 unk_8a850(void)
{

}

void unk_8a94c(void)
{

}

void unk_8aa54(void)
{

}

void unk_8aaf0(void)
{

}

void unk_8ab24(void)
{

}

void unk_8ab54(void)
{

}

void unk_8ab9c(void)
{

}
