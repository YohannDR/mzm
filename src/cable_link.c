#include "cable_link.h"
#include "macros.h"
#include "gba.h"
#include "callbacks.h"
#include "music_wrappers.h"

#include "data/cable_link_data.h"
#include "data/io_transfer_data.h"

#include "constants/cable_link.h"

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
                ClearSoundData();
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
            if (!unk_8980c(sTransferRom_After - sTransferRom, (const u32*)sTransferRom))
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

        case 8:
            gIoTransferInfo.result = 2;
            gIoTransferInfo.unk_9 = 11;
            break;

        case 7:
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

#ifdef NON_MATCHING
u32 unk_891a0(struct MultiBootData* pMultiBoot)
{
    // https://decomp.me/scratch/fqhAa

    s32 mask;
    s32 i;
    s32 value;

    if (unk_896b8(pMultiBoot))
        return 0;

    if (pMultiBoot->checkWait > 15)
    {
        pMultiBoot->checkWait--;
        return 0;
    }

    while (TRUE)
    {
        if (pMultiBoot->sendFlag)
        {
            pMultiBoot->sendFlag = FALSE;
            i = read16(REG_SIO) & (u8)~(SIO_SHIFT_INTERNAL_CLOCK_FLAG | SIO_SHIFT_INTERNAL_CLOCK_2MHZ);

            if (i != SIO_HIGH_DURING_INACTIVITY)
            {
                CableLinkResetTransfer(pMultiBoot);
                return i ^ SIO_HIGH_DURING_INACTIVITY;
            }
        }

        if (pMultiBoot->probeCount > 223)
        {
            i = unk_896cc(pMultiBoot);
            if (i)
                return i;

            if (pMultiBoot->serverType != 1 || pMultiBoot->probeCount < 226 || unk_896b8(pMultiBoot))
            {
                if (unk_896b8(pMultiBoot))
                    return 0;

                if (pMultiBoot->handshakeTimeout == 0)
                {
                    CableLinkResetTransfer(pMultiBoot);
                    return (0x10 | 0x20 | 0x40 | SIO_SHIFT_INTERNAL_CLOCK_FLAG);
                }

                pMultiBoot->handshakeTimeout--;
                return 0;
            }
            else
                unk_897d0();
        }
        else
        {
            switch (pMultiBoot->probeCount)
            {
                case 0:
                    mask = 0xE;

                    for (i = 3; i != 0; i--)
                    {
                        value = READ_SIO_MULTI(i);
                        if (value != USHORT_MAX)
                            break;
                        
                        mask >>= 1;
                    }

                    mask &= 0xE;
                    pMultiBoot->responseBit = mask;

                    for (i = 3; i != 0; i--)
                    {
                        value = READ_SIO_MULTI(i);
                        if ((pMultiBoot->clientBit >> i) & 1)
                        {
                            if (value != (0x7200 | (1 << i)))
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

                    if (pMultiBoot->checkWait == 0)
                    {
                        if (pMultiBoot->responseBit != pMultiBoot->clientBit)
                        {
                            return CableLinkStartTransfer(pMultiBoot, pMultiBoot->clientBit | 0x6200);
                        }
                        
                        unk_895dc(pMultiBoot);
                    }
                    else
                    {
                        pMultiBoot->checkWait--;
                        return CableLinkStartTransfer(pMultiBoot, pMultiBoot->clientBit | 0x6200);
                    }

                case 1:
                    pMultiBoot->probeTargetBit = 0;

                    for (i = 3; i != 0; i--)
                    {
                        value = READ_SIO_MULTI(i);
                        if ((value >> 8) == 0x72)
                        {
                            gUnk_3005888[i - 1] = value;

                            value &= 0xFF;

                            if (value == 1 << i)
                            {
                                pMultiBoot->probeTargetBit |= value;
                            }
                        }
                    }

                    if (pMultiBoot->responseBit != pMultiBoot->probeTargetBit)
                    {
                        pMultiBoot->probeCount = 2;
                        return CableLinkStartTransfer(pMultiBoot, pMultiBoot->probeTargetBit | 0x6100);
                    }

                    return CableLinkStartTransfer(pMultiBoot, pMultiBoot->clientBit | 0x6200);

                case 2:
                    for (i = 3; i != 0; i--)
                    {
                        if ((pMultiBoot->probeTargetBit >> i) & 1)
                        {
                            value = READ_SIO_MULTI(i);
                            if (value != gUnk_3005888[i - 1])
                            {
                                pMultiBoot->probeTargetBit ^= 1 << i;
                            }
                        }
                    }
                    break;

                case 208:
                    mask = 1;
                    for (i = 3; i != 0; i--)
                    {
                        value = READ_SIO_MULTI(i);
                        pMultiBoot->clientData[i - 1] = value;

                        if ((pMultiBoot->probeTargetBit >> i) & 1)
                        {
                            if ((u32)((value >> 8) - 0x72) > 1)
                            {
                                CableLinkResetTransfer(pMultiBoot);
                                return 0x60;
                            }

                            if (value == gUnk_3005888[i - 1])
                                mask = 0;
                        }
                    }

                    if (mask == 0)
                    {
                        return CableLinkStartTransfer(pMultiBoot, pMultiBoot->paletteData | 0x6300);
                    }

                    pMultiBoot->probeCount = 209;
                    mask = 0x11;

                    for (i = 3; i != 0; i--)
                        mask += pMultiBoot->clientData[i - 1];

                    pMultiBoot->handshakeData = mask;

                    return CableLinkStartTransfer(pMultiBoot, (mask & 0xFF) | 0x6400);

                case 209:
                    for (i = 3; i != 0; i--)
                    {
                        value = READ_SIO_MULTI(i);

                        if ((pMultiBoot->probeTargetBit >> i) & 1)
                        {
                            if (value >> 8 != 0x73)
                            {
                                CableLinkResetTransfer(pMultiBoot);
                                return 0x60;
                            }
                        }
                    }

                    i = MultiBoot(pMultiBoot);

                    if (i == FALSE)
                    {
                        pMultiBoot->probeCount = 224;
                        pMultiBoot->handshakeTimeout = 400;
                        return 0;
                    }

                    CableLinkResetTransfer(pMultiBoot);
                    pMultiBoot->checkWait = 30;
                    return 0x70;

                default:
                    for (i = 3; i != 0; i--)
                    {
                        if ((pMultiBoot->probeTargetBit >> i) & 1)
                        {
                            value = READ_SIO_MULTI(i);

                            if (value >> 8 == 0x62 - (pMultiBoot->probeCount >> 1))
                            {
                                if ((value & 0xFF) == (1 << i))
                                    continue;
                            }

                            pMultiBoot->probeTargetBit ^= 1 << i;
                        }
                    }

                    if (pMultiBoot->probeCount == 196)
                    {
                        pMultiBoot->clientBit = pMultiBoot->probeTargetBit & 0xE;
                        pMultiBoot->probeCount = 0;
                        return CableLinkStartTransfer(pMultiBoot, pMultiBoot->clientBit | 0x6200);
                    }
            }
            
            if (pMultiBoot->probeTargetBit == 0)
            {
                CableLinkResetTransfer(pMultiBoot);
                return 0x50;
            }

            pMultiBoot->probeCount += 2;
            if (pMultiBoot->probeCount == 196)
            {
                return CableLinkStartTransfer(pMultiBoot, pMultiBoot->clientBit | 0x6200);
            }

            i = CableLinkStartTransfer(pMultiBoot, pMultiBoot->dataSentPointer[pMultiBoot->probeCount - 3] << 8 |
                pMultiBoot->dataSentPointer[pMultiBoot->probeCount - 4]);

            if (i != 0)
                return i;

            if (pMultiBoot->serverType == 1)
                unk_897d0();
            else
                return 0;
        }
    }
}
#else
NAKED_FUNCTION
u32 unk_891a0(struct MultiBootData* pMultiBoot)
{
    asm(" \n\
    push {r4, r5, r6, r7, lr} \n\
    mov r7, sl \n\
    mov r6, sb \n\
    mov r5, r8 \n\
    push {r5, r6, r7} \n\
    add r7, r0, #0 \n\
    bl unk_896b8 \n\
    cmp r0, #0 \n\
    beq lbl_080891b6 \n\
    b lbl_0808957e \n\
lbl_080891b6: \n\
    add r0, r7, #0 \n\
    add r0, #0x4a \n\
    ldrb r1, [r0] \n\
    mov sl, r0 \n\
    cmp r1, #0xf \n\
    bls lbl_080891ca \n\
    sub r0, r1, #1 \n\
    mov r1, sl \n\
    strb r0, [r1] \n\
    b lbl_0808957e \n\
lbl_080891ca: \n\
    add r1, r7, #0 \n\
    add r1, #0x48 \n\
    ldrb r0, [r1] \n\
    cmp r0, #0 \n\
    beq lbl_080891f4 \n\
    movs r0, #0 \n\
    strb r0, [r1] \n\
    ldr r0, lbl_080891f0 @ =0x04000128 \n\
    ldrh r0, [r0] \n\
    movs r5, #0xfc \n\
    and r5, r0 \n\
    cmp r5, #8 \n\
    beq lbl_080891f4 \n\
    add r0, r7, #0 \n\
    bl CableLinkResetTransfer \n\
    movs r0, #8 \n\
    eor r0, r5 \n\
    b lbl_08089580 \n\
    .align 2, 0 \n\
lbl_080891f0: .4byte 0x04000128 \n\
lbl_080891f4: \n\
    ldrb r0, [r7, #0x18] \n\
    cmp r0, #0xdf \n\
    bls lbl_08089246 \n\
    add r0, r7, #0 \n\
    bl unk_896cc \n\
    add r5, r0, #0 \n\
    cmp r5, #0 \n\
    beq lbl_08089208 \n\
    b lbl_08089580 \n\
lbl_08089208: \n\
    add r0, r7, #0 \n\
    add r0, #0x4b \n\
    ldrb r0, [r0] \n\
    cmp r0, #1 \n\
    bne lbl_08089224 \n\
    ldrb r0, [r7, #0x18] \n\
    cmp r0, #0xe1 \n\
    bls lbl_08089224 \n\
    add r0, r7, #0 \n\
    bl unk_896b8 \n\
    cmp r0, #0 \n\
    bne lbl_08089224 \n\
    b lbl_0808956e \n\
lbl_08089224: \n\
    add r0, r7, #0 \n\
    bl unk_896b8 \n\
    cmp r0, #0 \n\
    beq lbl_08089230 \n\
    b lbl_0808957e \n\
lbl_08089230: \n\
    ldrh r0, [r7, #0x16] \n\
    cmp r0, #0 \n\
    bne lbl_08089240 \n\
    add r0, r7, #0 \n\
    bl CableLinkResetTransfer \n\
    movs r0, #0x71 \n\
    b lbl_08089580 \n\
lbl_08089240: \n\
    sub r0, #1 \n\
    strh r0, [r7, #0x16] \n\
    b lbl_0808957e \n\
lbl_08089246: \n\
    ldrb r0, [r7, #0x18] \n\
    cmp r0, #2 \n\
    bne lbl_0808924e \n\
    b lbl_08089384 \n\
lbl_0808924e: \n\
    cmp r0, #2 \n\
    bgt lbl_0808925c \n\
    cmp r0, #0 \n\
    beq lbl_0808926a \n\
    cmp r0, #1 \n\
    beq lbl_08089326 \n\
    b lbl_080894bc \n\
lbl_0808925c: \n\
    cmp r0, #0xd0 \n\
    bne lbl_08089262 \n\
    b lbl_080893d0 \n\
lbl_08089262: \n\
    cmp r0, #0xd1 \n\
    bne lbl_08089268 \n\
    b lbl_0808946a \n\
lbl_08089268: \n\
    b lbl_080894bc \n\
lbl_0808926a: \n\
    movs r3, #0xe \n\
    movs r5, #3 \n\
    ldr r0, lbl_080892b0 @ =0x04000120 \n\
    ldrh r0, [r0, #6] \n\
    add r1, r0, #0 \n\
    ldr r0, lbl_080892b4 @ =0x0000ffff \n\
    ldrb r2, [r7, #0x1e] \n\
    add r6, r2, #0 \n\
    cmp r1, r0 \n\
    bne lbl_08089292 \n\
    add r4, r1, #0 \n\
    ldr r1, lbl_080892b8 @ =0x04000126 \n\
lbl_08089282: \n\
    asr r3, r3, #1 \n\
    sub r1, #2 \n\
    sub r5, #1 \n\
    cmp r5, #0 \n\
    beq lbl_08089292 \n\
    ldrh r0, [r1] \n\
    cmp r0, r4 \n\
    beq lbl_08089282 \n\
lbl_08089292: \n\
    movs r0, #0xe \n\
    and r3, r0 \n\
    strb r3, [r7, #0x1d] \n\
    movs r5, #3 \n\
    ldr r0, lbl_080892b0 @ =0x04000120 \n\
    ldrh r0, [r0, #6] \n\
    add r4, r0, #0 \n\
    asr r0, r2, #3 \n\
    movs r1, #1 \n\
    and r0, r1 \n\
    cmp r0, #0 \n\
    beq lbl_080892c0 \n\
    ldr r0, lbl_080892bc @ =0x00007208 \n\
    b lbl_080892e6 \n\
    .align 2, 0 \n\
lbl_080892b0: .4byte 0x04000120 \n\
lbl_080892b4: .4byte 0x0000ffff \n\
lbl_080892b8: .4byte 0x04000126 \n\
lbl_080892bc: .4byte 0x00007208 \n\
lbl_080892c0: \n\
    sub r5, #1 \n\
    cmp r5, #0 \n\
    beq lbl_080892ec \n\
    lsl r0, r5, #1 \n\
    ldr r1, lbl_08089314 @ =0x04000120 \n\
    add r0, r0, r1 \n\
    ldrh r0, [r0] \n\
    add r4, r0, #0 \n\
    add r0, r2, #0 \n\
    asr r0, r5 \n\
    movs r1, #1 \n\
    and r0, r1 \n\
    cmp r0, #0 \n\
    beq lbl_080892c0 \n\
    add r0, r1, #0 \n\
    lsl r0, r5 \n\
    movs r1, #0xe4 \n\
    lsl r1, r1, #7 \n\
    orr r0, r1 \n\
lbl_080892e6: \n\
    cmp r4, r0 \n\
    beq lbl_080892c0 \n\
    movs r3, #0 \n\
lbl_080892ec: \n\
    add r0, r3, #0 \n\
    and r0, r6 \n\
    strb r0, [r7, #0x1e] \n\
    cmp r3, #0 \n\
    bne lbl_080892fc \n\
    movs r0, #0xf \n\
    mov r2, sl \n\
    strb r0, [r2] \n\
lbl_080892fc: \n\
    mov r1, sl \n\
    ldrb r0, [r1] \n\
    cmp r0, #0 \n\
    bne lbl_08089318 \n\
    ldrb r0, [r7, #0x1d] \n\
    ldrb r2, [r7, #0x1e] \n\
    cmp r0, r2 \n\
    beq lbl_0808931e \n\
    add r0, r7, #0 \n\
    bl unk_895dc \n\
    b lbl_08089326 \n\
    .align 2, 0 \n\
lbl_08089314: .4byte 0x04000120 \n\
lbl_08089318: \n\
    sub r0, #1 \n\
    mov r1, sl \n\
    strb r0, [r1] \n\
lbl_0808931e: \n\
    ldrb r1, [r7, #0x1e] \n\
    movs r2, #0xc4 \n\
    lsl r2, r2, #7 \n\
    b lbl_08089426 \n\
lbl_08089326: \n\
    add r1, r7, #0 \n\
    add r1, #0x49 \n\
    movs r0, #0 \n\
    strb r0, [r1] \n\
    movs r5, #3 \n\
    mov ip, r1 \n\
    ldr r3, lbl_0808937c @ =gUnk_3005888 \n\
lbl_08089334: \n\
    lsl r0, r5, #1 \n\
    ldr r2, lbl_08089380 @ =0x04000120 \n\
    add r0, r0, r2 \n\
    ldrh r0, [r0] \n\
    add r4, r0, #0 \n\
    asr r0, r4, #8 \n\
    sub r2, r5, #1 \n\
    cmp r0, #0x72 \n\
    bne lbl_0808935e \n\
    lsl r0, r2, #1 \n\
    add r0, r0, r3 \n\
    strh r4, [r0] \n\
    movs r0, #0xff \n\
    and r4, r0 \n\
    movs r0, #1 \n\
    lsl r0, r5 \n\
    cmp r4, r0 \n\
    bne lbl_0808935e \n\
    ldrb r0, [r1] \n\
    orr r4, r0 \n\
    strb r4, [r1] \n\
lbl_0808935e: \n\
    add r5, r2, #0 \n\
    cmp r5, #0 \n\
    bne lbl_08089334 \n\
    ldrb r0, [r7, #0x1d] \n\
    mov r1, ip \n\
    ldrb r1, [r1] \n\
    cmp r0, r1 \n\
    bne lbl_0808931e \n\
    movs r0, #2 \n\
    strb r0, [r7, #0x18] \n\
    mov r2, ip \n\
    ldrb r1, [r2] \n\
    movs r2, #0xc2 \n\
    lsl r2, r2, #7 \n\
    b lbl_08089426 \n\
    .align 2, 0 \n\
lbl_0808937c: .4byte gUnk_3005888 \n\
lbl_08089380: .4byte 0x04000120 \n\
lbl_08089384: \n\
    movs r5, #3 \n\
    movs r0, #0x49 \n\
    add r0, r0, r7 \n\
    mov ip, r0 \n\
    mov r4, ip \n\
    movs r6, #1 \n\
    ldr r1, lbl_080893c8 @ =gUnk_3005888 \n\
    mov sb, r1 \n\
    ldr r2, lbl_080893cc @ =0x04000120 \n\
    mov r8, r2 \n\
lbl_08089398: \n\
    ldrb r3, [r4] \n\
    add r0, r3, #0 \n\
    asr r0, r5 \n\
    and r0, r6 \n\
    sub r2, r5, #1 \n\
    cmp r0, #0 \n\
    beq lbl_080893be \n\
    lsl r0, r5, #1 \n\
    add r0, r8 \n\
    ldrh r1, [r0] \n\
    lsl r0, r2, #1 \n\
    add r0, sb \n\
    ldrh r0, [r0] \n\
    cmp r1, r0 \n\
    beq lbl_080893be \n\
    add r0, r6, #0 \n\
    lsl r0, r5 \n\
    eor r3, r0 \n\
    strb r3, [r4] \n\
lbl_080893be: \n\
    add r5, r2, #0 \n\
    cmp r5, #0 \n\
    bne lbl_08089398 \n\
    b lbl_08089524 \n\
    .align 2, 0 \n\
lbl_080893c8: .4byte gUnk_3005888 \n\
lbl_080893cc: .4byte 0x04000120 \n\
lbl_080893d0: \n\
    movs r3, #1 \n\
    movs r5, #3 \n\
    movs r0, #0x49 \n\
    add r0, r0, r7 \n\
    mov ip, r0 \n\
    add r6, r7, #0 \n\
    add r6, #0x19 \n\
    ldr r1, lbl_08089434 @ =gUnk_3005888 \n\
    mov r8, r1 \n\
lbl_080893e2: \n\
    lsl r0, r5, #1 \n\
    ldr r2, lbl_08089438 @ =0x04000120 \n\
    add r0, r0, r2 \n\
    ldrh r0, [r0] \n\
    add r4, r0, #0 \n\
    sub r2, r5, #1 \n\
    add r0, r6, r2 \n\
    strb r4, [r0] \n\
    mov r0, ip \n\
    ldrb r1, [r0] \n\
    asr r1, r5 \n\
    movs r0, #1 \n\
    and r1, r0 \n\
    cmp r1, #0 \n\
    beq lbl_08089416 \n\
    asr r0, r4, #8 \n\
    sub r0, #0x72 \n\
    cmp r0, #1 \n\
    bls lbl_0808940a \n\
    b lbl_08089574 \n\
lbl_0808940a: \n\
    lsl r0, r2, #1 \n\
    add r0, r8 \n\
    ldrh r0, [r0] \n\
    cmp r4, r0 \n\
    bne lbl_08089416 \n\
    movs r3, #0 \n\
lbl_08089416: \n\
    add r5, r2, #0 \n\
    cmp r5, #0 \n\
    bne lbl_080893e2 \n\
    cmp r3, #0 \n\
    bne lbl_0808943c \n\
    ldrb r1, [r7, #0x1c] \n\
    movs r2, #0xc6 \n\
    lsl r2, r2, #7 \n\
lbl_08089426: \n\
    add r0, r2, #0 \n\
    orr r1, r0 \n\
    add r0, r7, #0 \n\
    bl CableLinkStartTransfer \n\
    b lbl_08089580 \n\
    .align 2, 0 \n\
lbl_08089434: .4byte gUnk_3005888 \n\
lbl_08089438: .4byte 0x04000120 \n\
lbl_0808943c: \n\
    movs r0, #0xd1 \n\
    strb r0, [r7, #0x18] \n\
    movs r3, #0x11 \n\
    movs r5, #3 \n\
    add r1, r6, #2 \n\
lbl_08089446: \n\
    ldrb r0, [r1] \n\
    add r3, r3, r0 \n\
    sub r1, #1 \n\
    sub r5, #1 \n\
    cmp r5, #0 \n\
    bne lbl_08089446 \n\
    strb r3, [r7, #0x14] \n\
    movs r0, #0xff \n\
    and r3, r0 \n\
    movs r1, #0xc8 \n\
    lsl r1, r1, #7 \n\
    add r0, r1, #0 \n\
    orr r3, r0 \n\
    add r0, r7, #0 \n\
    add r1, r3, #0 \n\
    bl CableLinkStartTransfer \n\
    b lbl_08089580 \n\
lbl_0808946a: \n\
    movs r5, #3 \n\
    movs r2, #0x49 \n\
    ldrb r1, [r2, r7] \n\
    ldr r2, lbl_080894a8 @ =0x04000126 \n\
    movs r3, #1 \n\
lbl_08089474: \n\
    ldrh r0, [r2] \n\
    add r4, r0, #0 \n\
    add r0, r1, #0 \n\
    asr r0, r5 \n\
    and r0, r3 \n\
    cmp r0, #0 \n\
    beq lbl_08089488 \n\
    asr r0, r4, #8 \n\
    cmp r0, #0x73 \n\
    bne lbl_08089574 \n\
lbl_08089488: \n\
    sub r2, #2 \n\
    sub r5, #1 \n\
    cmp r5, #0 \n\
    bne lbl_08089474 \n\
    add r0, r7, #0 \n\
    bl Multiboot \n\
    add r5, r0, #0 \n\
    cmp r5, #0 \n\
    bne lbl_080894ac \n\
    movs r0, #0xe0 \n\
    strb r0, [r7, #0x18] \n\
    add r0, #0xb0 \n\
    strh r0, [r7, #0x16] \n\
    b lbl_0808957e \n\
    .align 2, 0 \n\
lbl_080894a8: .4byte 0x04000126 \n\
lbl_080894ac: \n\
    add r0, r7, #0 \n\
    bl CableLinkResetTransfer \n\
    movs r0, #0x1e \n\
    mov r1, sl \n\
    strb r0, [r1] \n\
    movs r0, #0x70 \n\
    b lbl_08089580 \n\
lbl_080894bc: \n\
    movs r5, #3 \n\
    movs r2, #0x49 \n\
    add r2, r2, r7 \n\
    mov ip, r2 \n\
    mov r8, ip \n\
    movs r0, #1 \n\
    mov sb, r0 \n\
lbl_080894ca: \n\
    mov r1, r8 \n\
    ldrb r6, [r1] \n\
    add r0, r6, #0 \n\
    asr r0, r5 \n\
    mov r2, sb \n\
    and r0, r2 \n\
    cmp r0, #0 \n\
    beq lbl_08089504 \n\
    lsl r0, r5, #1 \n\
    ldr r1, lbl_08089520 @ =0x04000120 \n\
    add r0, r0, r1 \n\
    ldrh r0, [r0] \n\
    add r4, r0, #0 \n\
    asr r2, r4, #8 \n\
    ldrb r0, [r7, #0x18] \n\
    lsr r0, r0, #1 \n\
    movs r1, #0x62 \n\
    sub r1, r1, r0 \n\
    mov r3, sb \n\
    lsl r3, r5 \n\
    cmp r2, r1 \n\
    bne lbl_080894fe \n\
    movs r0, #0xff \n\
    and r4, r0 \n\
    cmp r4, r3 \n\
    beq lbl_08089504 \n\
lbl_080894fe: \n\
    eor r6, r3 \n\
    mov r2, r8 \n\
    strb r6, [r2] \n\
lbl_08089504: \n\
    sub r5, #1 \n\
    cmp r5, #0 \n\
    bne lbl_080894ca \n\
    ldrb r0, [r7, #0x18] \n\
    cmp r0, #0xc4 \n\
    bne lbl_08089524 \n\
    mov r0, ip \n\
    ldrb r1, [r0] \n\
    movs r0, #0xe \n\
    and r0, r1 \n\
    strb r0, [r7, #0x1e] \n\
    strb r5, [r7, #0x18] \n\
    b lbl_0808931e \n\
    .align 2, 0 \n\
lbl_08089520: .4byte 0x04000120 \n\
lbl_08089524: \n\
    mov r1, ip \n\
    ldrb r0, [r1] \n\
    cmp r0, #0 \n\
    bne lbl_08089536 \n\
    add r0, r7, #0 \n\
    bl CableLinkResetTransfer \n\
    movs r0, #0x50 \n\
    b lbl_08089580 \n\
lbl_08089536: \n\
    ldrb r0, [r7, #0x18] \n\
    add r0, #2 \n\
    strb r0, [r7, #0x18] \n\
    lsl r0, r0, #0x18 \n\
    lsr r0, r0, #0x18 \n\
    cmp r0, #0xc4 \n\
    bne lbl_08089546 \n\
    b lbl_0808931e \n\
lbl_08089546: \n\
    ldrb r0, [r7, #0x18] \n\
    ldr r1, [r7, #0x28] \n\
    add r0, r0, r1 \n\
    sub r1, r0, #3 \n\
    ldrb r2, [r1] \n\
    lsl r2, r2, #8 \n\
    sub r0, #4 \n\
    ldrb r1, [r0] \n\
    orr r1, r2 \n\
    add r0, r7, #0 \n\
    bl CableLinkStartTransfer \n\
    add r5, r0, #0 \n\
    cmp r5, #0 \n\
    bne lbl_08089580 \n\
    add r0, r7, #0 \n\
    add r0, #0x4b \n\
    ldrb r0, [r0] \n\
    cmp r0, #1 \n\
    bne lbl_0808957e \n\
lbl_0808956e: \n\
    bl unk_897d0 \n\
    b lbl_080891ca \n\
lbl_08089574: \n\
    add r0, r7, #0 \n\
    bl CableLinkResetTransfer \n\
    movs r0, #0x60 \n\
    b lbl_08089580 \n\
lbl_0808957e: \n\
    movs r0, #0 \n\
lbl_08089580: \n\
    pop {r3, r4, r5} \n\
    mov r8, r3 \n\
    mov sb, r4 \n\
    mov sl, r5 \n\
    pop {r4, r5, r6, r7} \n\
    pop {r1} \n\
    bx r1 \n\
    ");
}
#endif

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
void unk_89600(struct MultiBootData* pMultiBoot, const u8* src, s32 length, u8 param_4, u8 param_5)
{
    s32 size;
    s32 paletteData;
    u32 var_0;
    s8 var_1;
    s32 var_2;

    var_2 = (s8)param_5;
    
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
 * @return u32 To document
 */
u32 unk_896b8(struct MultiBootData* pMultiBoot)
{
    if (pMultiBoot->probeCount == 0xE9)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief 896cc | ec | To document
 * 
 * @param pMultiBoot Multi boot param pointer
 * @return u32 SIOCNT
 */
u32 unk_896cc(struct MultiBootData* pMultiBoot)
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

            return_in_default_case:
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

            #ifndef NON_MATCHING
            goto return_in_default_case;
            #else // NON_MATCHING
            return CableLinkStartTransfer(pMultiBoot, pMultiBoot->systemWork_1[0]);
            #endif // NON_MATCHING
    }
}

/**
 * @brief 897b8 | 18 | Checks for the current memory region (where execution is)
 * 
 * @param param_1 To document
 */
NAKED_FUNCTION
void CableLinkCheckCurrentMemoryRegion(s32 param_1)
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
    s32 i;

    i = 0;
    if (read16(REG_SIO) & SIO_START_BIT_ACTIVE)
    {
        while (++i < 0x795D && read16(REG_SIO) & SIO_START_BIT_ACTIVE);
    }

    CableLinkCheckCurrentMemoryRegion(0x258);
}

/**
 * @brief 8980c | ac | To document
 * 
 * @param size Data size
 * @param pData Pointer to data
 * @return u32 To document
 */
u32 unk_8980c(u32 size, const u32* pData)
{
    u32 result;
    u32 buffer;
    s32 i;

    CableLinkBackupIoRegs();

    while (TRUE)
    {
        gUnk_30058a8 = unk_899c8(1, size, pData, 0);

        if (!(gUnk_30058a8 & 3) && gUnk_30058a8 & 0xC)
        {
            result = 0;
            break;
        }

        if (gUnk_30058a8 & 0x20)
        {
            result = 1;
            break;
        }

        if (gUnk_30058a8 & 0x10)
        {
            result = 2;
            break;
        }

        if (gUnk_30058a8 & 0x40)
        {
            result = 3;
            break;
        }

        if (gUnk_30058a8 & 0x80)
        {
            result = 4;
            break;
        }

        if (gIoTransferInfo.pFunction)
            gIoTransferInfo.pFunction();

        VBlankIntrWait();
    }

    buffer = 0;
    CpuSet(&buffer, &gUnk_3005890, (CPU_SET_32BIT | CPU_SET_SRC_FIXED) << 16 | sizeof(gUnk_3005890) / sizeof(u32));

    CableLinkRetrieveIoRegs();

    return result;
}

/**
 * @brief 898b8 | 54 | To document
 * 
 */
void unk_898b8(void)
{
    u32 buffer;

    gUnk_30058aa = 0;
    gUnk_30058ac = 0;
    gUnk_30058ae = 0;
    gUnk_30058af = 0;
    gUnk_30058b0 = 0;
    gUnk_30058b1 = 0;

    buffer = 0;
    CpuSet(&buffer, &gUnk_3005890, (CPU_SET_32BIT | CPU_SET_SRC_FIXED) << 16 | sizeof(gUnk_3005890) / sizeof(u32));
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

/**
 * @brief 899c8 | 174 | To document
 * 
 * @param param_1 To document
 * @param Size Data size
 * @param pData Pointer to data
 * @param param_3 To document
 * @return u16 To document
 */
u16 unk_899c8(u32 param_1, u32 size, const u32* pData, u32 param_3)
{
    switch (gUnk_3005890.unk_1)
    {
        case 0:
            unk_898b8();
            unk_8994c();
            gUnk_3005890.unk_3 = TRUE;
            gUnk_3005890.unk_1 = 1;
            break;

        case 1:
            if (unk_89b3c(TRUE))
                CableLinkSetSioCntStartBitActive();

            if (gUnk_3005890.unk_5 != 0)
                gUnk_3005890.unk_1 = 6;

            gUnk_30058ae++;
            if (gUnk_30058ae > 30)
            {
                gUnk_3005890.unk_5 = 4;
                gUnk_3005890.unk_1 = 6;
            }
            break;

        case 2:
            unk_899a4();
            unk_89b70(size, pData, param_3);
            gUnk_3005890.unk_1 = 3;

        case 3:
            if (gUnk_3005890.unk_3 == 2)
                break;

            if (gUnk_3005890.unk_0 != 0)
            {
                gUnk_30058ac++;
                if (gUnk_30058ac > 9)
                {
                    CableLinkSetSioCntStartBitActive();
                    gUnk_3005890.unk_3 = 2;
                    break;
                }
            }
            
            CableLinkSetSioCntStartBitActive();
            gUnk_3005890.unk_3 = 2;
            break;

        case 4:
            unk_8994c();
            gUnk_3005890.unk_1 = 5;
            break;

        case 5:
            if (gUnk_3005890.unk_0 == 1 && gUnk_30058ac > 9)
                CableLinkSetSioCntStartBitActive();

            gUnk_30058ac++;
            if (gUnk_30058ac > 30)
            {
                gUnk_3005890.unk_5 = 1;
                gUnk_3005890.unk_1 = 6;
            }
            break;

        case 6:
            if (gUnk_3005890.unk_3)
            {
                unk_8990c();
                gUnk_3005890.unk_3 = FALSE;
            }
            break;
    }

    gUnk_3005890.unk_2 = gUnk_3005890.dataCursor * 100 / gUnk_3005890.dataSizeInt;

    return gUnk_3005890.unk_3 | gUnk_3005890.unk_4 << 2 | gUnk_3005890.unk_5 << 4 | gUnk_3005890.unk_2 << 8;
}

/**
 * @brief 89b3c | 34 | To document
 * 
 * @param param_1 To document
 * @return u16 To document
 */
u16 unk_89b3c(u8 param_1)
{
    u32 result;

    if ((read32(REG_SIO) & (SIO_HIGH_DURING_INACTIVITY | SIO_STATE_HIGH_OR_NONE)) == SIO_HIGH_DURING_INACTIVITY && param_1)
    {
        gUnk_3005890.unk_0 = TRUE;
        return gUnk_3005890.unk_0;
    }
    else
    {
        gUnk_3005890.unk_0 = FALSE;
        return gUnk_3005890.unk_0;
    }
}

/**
 * @brief 89b70 | 30 | To document
 * 
 * @param size Data size
 * @param pData Data pointer
 */
void unk_89b70(u32 size, const u32* pData, u32 param_3)
{
    write16(REG_SIO, read16(REG_SIO) | SIO_SHIFT_INTERNAL_CLOCK_FLAG);
    
    gUnk_3005890.pData = pData;
    write32(REG_SIO_MULTI, size);

    gUnk_3005890.dataSizeInt = (size / sizeof(u32)) + 1;

    unk_89ba0();
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

/**
 * @brief 89be4 | 180 | To document
 * 
 */
void unk_89be4(void)
{
    u16 buffer[4];
    u32 control;
    u16 i;
    u32 data_1;
    u32 data_2;
    u32* ptr;
    u16 var_0;
    u16 var_1;

    control = read32(REG_SIO);

    switch (gUnk_3005890.unk_1)
    {
        case 1:
            write16(REG_SIO_DATA8, 0x7C40);
            ptr = REG_SIO_MULTI;
            data_2 = read32(&ptr[1]);
            data_1 = read32(&ptr[0]);
            write32(&buffer[0], data_1);
            write32(&buffer[2], data_2);

            i = 0;
            var_0 = 0;
            var_1 = 0;

            for (; i < ARRAY_SIZE(buffer); i++)
            {
                if (buffer[i] == 0x7C40)
                    var_0++;
                else if (buffer[i] != USHORT_MAX)
                    var_1++;
            }

            gUnk_30058b0 = var_0;
            gUnk_30058b1 = control << 0x1A >> 0x1E;

            if (var_0 < 3)
            {
                if (var_0 > 1 && var_1 == 0)
                    gUnk_3005890.unk_1 = 2;
            }
            else
                gUnk_3005890.unk_5 = 8;
            break;

        case 3:
            read32(REG_SIO_MULTI);

            if (gUnk_3005890.dataCursor < gUnk_3005890.dataSizeInt)
            {
                write32(REG_SIO_MULTI, gUnk_3005890.pData[gUnk_3005890.dataCursor]);
                gUnk_3005890.dataChecksum += gUnk_3005890.pData[gUnk_3005890.dataCursor];
            }
            else if (gUnk_3005890.dataCursor == gUnk_3005890.dataSizeInt)
            {
                write32(REG_SIO_MULTI, gUnk_3005890.dataChecksum);
            }
            else
            {
                write32(REG_SIO_MULTI, 0);
            }

            gUnk_3005890.dataCursor++;

            if (gUnk_3005890.dataCursor < gUnk_3005890.dataSizeInt + gUnk_30058b0)
            {
                write16(REG_TM3CNT_H, read16(REG_TM3CNT_H) | TIMER_CONTROL_ACTIVE);
            }
            else
            {
                gUnk_3005890.unk_1 = 4;
                gUnk_30058ac = 0;
            }
            break;

        case 5:
            ptr = REG_SIO_MULTI;
            data_2 = read32(&ptr[1]);
            data_1 = read32(&ptr[0]);
            write32(&buffer[0], data_1);
            write32(&buffer[2], data_2);

            i = 1;
            var_0 = 1;

            for (i; i < gUnk_30058b0; i++)
            {
                if (buffer[i] == 1)
                    var_0++;
                else if (buffer[i] == 2)
                {
                    gUnk_3005890.unk_4 = 2;
                    gUnk_3005890.unk_1 = 6;
                    break;
                }

                if (var_0 == gUnk_30058b0)
                {
                    gUnk_3005890.unk_4 = 1;
                    gUnk_3005890.unk_1 = 6;
                }
            }
            break;
    }
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

/**
 * @brief 89e30 | 164 | To document
 * 
 * @return u8 To document
 */
u8 unk_89e30(void)
{
    u16 buffer;
    u16* ptr;

    gIoTransferInfo.result = 0;
    gIoTransferInfo.timer++;

    switch (gIoTransferInfo.unk_A)
    {
        case 0:
            ptr = &buffer;
            buffer = 0;
            DMA_SET(3, ptr, gUnk_30058c0, (DMA_ENABLE | DMA_SRC_FIXED) << 16 | ARRAY_SIZE(gUnk_30058c0));

            buffer = 0;
            DMA_SET(3, ptr, gUnk_30058c4, (DMA_ENABLE | DMA_SRC_FIXED) << 16 | (ARRAY_SIZE(gUnk_30058c4) * ARRAY_SIZE(gUnk_30058c4[0])));

            gErrorFlag = 0;
            gUnk_30058cc = 0;
            gUnk_30058cd = 0;
            gUnk_30058ce = 0;
            gUnk_30058cf = 0;

            CallbackSetSerialCommunication(unk_8a7b0);
            CallbackSetTimer3(unk_8a7a0);

            unk_8a39c();

            gIoTransferInfo.unk_E = 0x5500;
            gIoTransferInfo.language = -1;
            gIoTransferInfo.fusionGalleryImages = -1;
            gIoTransferInfo.errorFlag = 0;
            gIoTransferInfo.timer = 0;
            gIoTransferInfo.unk_A++;
            break;

        case 1:
            if (gIoTransferInfo.unk_4 == 0)
            {
                unk_8a260();
                if (gIoTransferInfo.unk_E == 0x3300)
                    gIoTransferInfo.unk_A = 2;
                else if (gIoTransferInfo.errorFlag)
                    gIoTransferInfo.unk_A = 3;
                else
                    gIoTransferInfo.unk_A = 4;
            }
            else
            {
                CableLinkCheckError();
                if (gIoTransferInfo.unk_E == 0x3300 || gIoTransferInfo.errorFlag != 0)
                    gIoTransferInfo.unk_4 = 0;
                else if (gIoTransferInfo.timer > 60 * 3)
                    gIoTransferInfo.unk_4 = gIoTransferInfo.errorFlag;
            }
            break;

        case 2:
            gFileScreenOptionsUnlocked.fusionGalleryImages = gIoTransferInfo.fusionGalleryImages;
            gIoTransferInfo.result = 1;
            break;

        case 3:
        case 4:
            gIoTransferInfo.result = 4;
            break;

        case 5:
            break;
    }

    return gIoTransferInfo.result;
}

/**
 * @brief 89f94 | 198 | Checks if an error has occured
 * 
 * @return u8* Garbage, contains no value/undefined behavior
 */
u8* CableLinkCheckError(void)
{
    vu32 c;
    u32* pError;
    
    gUnk_30058cc = gFrameCounter8Bit & 1;
    pError = &gErrorFlag;
    *pError = CableLinkDetectError(&gUnk_30058cc, gUnk_30058c0, gUnk_30058c4);
    gUnk_30058ce = *pError & 3;
    gUnk_30058cd = (*pError & 0x1C) >> 2;
    gUnk_30058cf = (*pError & 0xE00) >> 9;

    if (*pError & 0x40)
    {
        gIoTransferInfo.timer = 0;
        unk_8a12c(gIoTransferInfo.unk_E);
        unk_8a1d4();
    }

    if (*pError & CABLE_LINK_ERROR_ID_OVER)
    {
        gIoTransferInfo.errorFlag |= 1;
        CableLinkDrawErrorStr(sErrorString_IdOver, VRAM_BASE + 0xE304, 12);
    }

    if (*pError & CABLE_LINK_ERROR_CHECKSUM)
    {
        gIoTransferInfo.errorFlag |= 2;
        CableLinkDrawErrorStr(sErrorString_ChecksumError, VRAM_BASE + 0xE344, 12);
    }

    if (*pError & CABLE_LINK_ERROR_HARDWARE)
    {
        gIoTransferInfo.errorFlag |= 4;
        CableLinkDrawErrorStr(sErrorString_HardwareError, VRAM_BASE + 0xE384, 12);
    }

    if (*pError & CABLE_LINK_ERROR_SEND_OVERFLOW)
    {
        gIoTransferInfo.errorFlag |= 8;
        CableLinkDrawErrorStr(sErrorString_SendOverflow, VRAM_BASE + 0xE3C4, 12);
    }

    if (*pError & CABLE_LINK_ERROR_RECEIVE_OVERFLOW)
    {
        gIoTransferInfo.errorFlag |= 16;
        CableLinkDrawErrorStr(sErrorString_ReceiveOverflow, VRAM_BASE + 0xE404, 12);
    }

    if (*pError & CABLE_LINK_ERROR_SIO_INTERNAL)
    {
        gIoTransferInfo.errorFlag |= 32;
        CableLinkDrawErrorStr(sErrorString_SioInternal, VRAM_BASE + 0xE444, 12);
    }

    if (*pError & CABLE_LINK_ERROR_SIO_STOP)
    {
        gIoTransferInfo.errorFlag |= 64;
        CableLinkDrawErrorStr(sErrorString_SioStop, VRAM_BASE + 0xE484, 12);
    }
}

/**
 * @brief 8a12c | a8 | To document
 * 
 * @param param_1 To document
 */
void unk_8a12c(u16 param_1)
{
    u32 value;
    
    switch (param_1)
    {
        case 0x8800:
            gUnk_30058c0[0] |= param_1;
            gUnk_30058c0[1] = gButtonInput;

            // Buffer overflow
            value = gChangedInput;
            gUnk_30058c0[3] = gLanguage;
            gUnk_30058c0[2] = value;
            break;

        case 0x5500:
            gUnk_30058c0[0] |= param_1;
            gUnk_30058c0[1] = gLanguage;
            break;

        case 0x4400:
            gUnk_30058c0[0] |= param_1;
            gUnk_30058c0[1] = 0;
            break;

        case 0x2200:
            gUnk_30058c0[0] |= param_1;
            gUnk_30058c0[1] = 1;
            break;
    }
}

/**
 * @brief 8a1d4 | 8c | To document
 * 
 */
void unk_8a1d4(void)
{
    u8 var;

    if (gErrorFlag & 0x100)
        return;

    if (gUnk_30058c4[0][1] == 0x5500)
    {
        gIoTransferInfo.language = gUnk_30058c4[1][1];
        if (gIoTransferInfo.language == gLanguage)
            gIoTransferInfo.unk_E = 0x4400;
    }

    if (gUnk_30058c4[0][1] == 0x6600)
    {
        gIoTransferInfo.fusionGalleryImages = gUnk_30058c4[1][1];

        var = gIoTransferInfo.fusionGalleryImages - 1;
        if (var < 3)
        {
            gIoTransferInfo.unk_E = 0x2200;
        }
        else
        {
            gIoTransferInfo.unk_E = 0;
            gIoTransferInfo.result = 5;
        }
    }

    if (gUnk_30058c4[0][1] == 0x3300)
        gIoTransferInfo.unk_E = 0x3300;
}

/**
 * @brief 8a260 | 68 | To document
 * 
 */
void unk_8a260(void)
{
    u32 buffer;
    
    gUnk_30058d0 = read16(REG_IME);
    write16(REG_IME, FALSE);
    write16(REG_IE, read16(REG_IE) & ~(IF_TIMER3 | IF_SERIAL));
    write16(REG_IME, gUnk_30058d0);

    write16(REG_SIO, SIO_NON_NORMAL_MODE);
    write16(REG_TM3CNT_H, 0);
    write16(REG_IF, IF_TIMER3 | IF_SERIAL);

    buffer = 0;
    CpuSet(&buffer, &gCableLinkInfo, (CPU_SET_32BIT | CPU_SET_SRC_FIXED) << 16 | sizeof(gCableLinkInfo) / sizeof(u32));
}

#ifdef NON_MATCHING
void unk_8a2c8(void)
{
    // https://decomp.me/scratch/YaVig

    u32 buffer;
    u32* ptr;
    
    gUnk_30058d0 = read16(REG_IME);
    write16(REG_IME, FALSE);
    write16(REG_IE, read16(REG_IE) & ~(IF_TIMER3 | IF_SERIAL));
    write16(REG_IME, gUnk_30058d0);

    write16(REG_RNCT, 0);
    write16(REG_SIO, SIO_NON_NORMAL_MODE);
    write16(REG_SIO, read16(REG_SIO) | SIO_SHIFT_INTERNAL_CLOCK_FLAG | SIO_SHIFT_INTERNAL_CLOCK_2MHZ | SIO_IRQ_ENABLE);

    gUnk_30058d0 = read16(REG_IME);

    write16(REG_IME, FALSE);
    write16(REG_IE, read16(REG_IE) | IF_SERIAL);
    write16(REG_IME, gUnk_30058d0);

    write16(REG_SIO_DATA8, 0);

    ptr = REG_SIO_MULTI;
    write32(&ptr[0], 0);
    write32(&ptr[1], 0);

    buffer = 0;
    CpuSet(&buffer, &gCableLinkInfo, (CPU_SET_32BIT | CPU_SET_SRC_FIXED) << 16 | sizeof(gCableLinkInfo) / sizeof(u32));

    gUnk_30058d2 = 0;
    gUnk_30058d3 = 0;
    gUnk_30058d5 = 0;
    gUnk_3005b50 = 0;
    gUnk_3005b54 = 0;
    gUnk_30058d6 = 0;
    gUnk_30058d8 = 0;
    gUnk_30058da = 0;
}
#else
NAKED_FUNCTION
void unk_8a2c8(void)
{
    asm(" \n\
    push {r4, r5, r6, r7, lr} \n\
    sub sp, #4 \n\
    ldr r6, lbl_0808a350 @ =gUnk_30058d0 \n\
    ldr r3, lbl_0808a354 @ =0x04000208 \n\
    ldrh r2, [r3] \n\
    movs r4, #0 \n\
    strh r4, [r3] \n\
    ldr r5, lbl_0808a358 @ =0x04000200 \n\
    ldrh r1, [r5] \n\
    ldr r0, lbl_0808a35c @ =0x0000ff3f \n\
    and r0, r1 \n\
    strh r0, [r5] \n\
    strh r2, [r3] \n\
    ldr r0, lbl_0808a360 @ =0x04000134 \n\
    strh r4, [r0] \n\
    ldr r2, lbl_0808a364 @ =0x04000128 \n\
    movs r1, #0x80 \n\
    lsl r1, r1, #6 \n\
    add r0, r1, #0 \n\
    strh r0, [r2] \n\
    ldrh r0, [r2] \n\
    ldr r7, lbl_0808a368 @ =0x00004003 \n\
    add r1, r7, #0 \n\
    orr r0, r1 \n\
    strh r0, [r2] \n\
    ldrh r2, [r3] \n\
    strh r2, [r6] \n\
    strh r4, [r3] \n\
    ldrh r0, [r5] \n\
    movs r1, #0x80 \n\
    orr r0, r1 \n\
    strh r0, [r5] \n\
    strh r2, [r3] \n\
    ldr r0, lbl_0808a36c @ =0x0400012a \n\
    strh r4, [r0] \n\
    ldr r2, lbl_0808a370 @ =0x04000120 \n\
    movs r0, #0 \n\
    movs r1, #0 \n\
    str r0, [r2] \n\
    str r1, [r2, #4] \n\
    movs r5, #0 \n\
    str r5, [sp] \n\
    ldr r1, lbl_0808a374 @ =gCableLinkInfo \n\
    ldr r2, lbl_0808a378 @ =0x05000069 \n\
    mov r0, sp \n\
    bl CpuSet \n\
    ldr r0, lbl_0808a37c @ =gUnk_30058d2 \n\
    strb r4, [r0] \n\
    ldr r0, lbl_0808a380 @ =gUnk_30058d3 \n\
    strb r4, [r0] \n\
    ldr r0, lbl_0808a384 @ =gUnk_30058d5 \n\
    strb r4, [r0] \n\
    ldr r0, lbl_0808a388 @ =gUnk_3005b50 \n\
    strb r4, [r0] \n\
    ldr r0, lbl_0808a38c @ =gUnk_3005b54 \n\
    strb r4, [r0] \n\
    ldr r0, lbl_0808a390 @ =gUnk_30058d6 \n\
    strb r4, [r0] \n\
    ldr r0, lbl_0808a394 @ =gUnk_30058d8 \n\
    strh r5, [r0] \n\
    ldr r0, lbl_0808a398 @ =gUnk_30058da \n\
    strh r5, [r0] \n\
    add sp, #4 \n\
    pop {r4, r5, r6, r7} \n\
    pop {r0} \n\
    bx r0 \n\
    .align 2, 0 \n\
lbl_0808a350: .4byte gUnk_30058d0 \n\
lbl_0808a354: .4byte 0x04000208 \n\
lbl_0808a358: .4byte 0x04000200 \n\
lbl_0808a35c: .4byte 0x0000ff3f \n\
lbl_0808a360: .4byte 0x04000134 \n\
lbl_0808a364: .4byte 0x04000128 \n\
lbl_0808a368: .4byte 0x00004003 \n\
lbl_0808a36c: .4byte 0x0400012a \n\
lbl_0808a370: .4byte 0x04000120 \n\
lbl_0808a374: .4byte gCableLinkInfo \n\
lbl_0808a378: .4byte 0x05000069 \n\
lbl_0808a37c: .4byte gUnk_30058d2 \n\
lbl_0808a380: .4byte gUnk_30058d3 \n\
lbl_0808a384: .4byte gUnk_30058d5 \n\
lbl_0808a388: .4byte gUnk_3005b50 \n\
lbl_0808a38c: .4byte gUnk_3005b54 \n\
lbl_0808a390: .4byte gUnk_30058d6 \n\
lbl_0808a394: .4byte gUnk_30058d8 \n\
lbl_0808a398: .4byte gUnk_30058da \n\
    ");
}
#endif

/**
 * @brief 8a39c | 10 | To document
 * 
 */
void unk_8a39c(void)
{
    unk_8a2c8();
    unk_8a260();
}

/**
 * @brief 8a3ac | 120 | Checks for errors
 * 
 * @param param_1 To document
 * @param param_2 To document
 * @param param_3 To document
 * @return u32 Error flags
 */
u32 CableLinkDetectError(u8* param_1, u16* param_2, CableLinkBuffer1_T param_3)
{
    u32 error;
    u32 errorFlag_0;
    u32 errorFlag_1;
    u32 errorFlag_hardware;
    u32 errorFlag_checksum;
    u32 errorFlag_overflow;
    u32 errorFlag_sioInternal;
    u32 temp;

    switch (gCableLinkInfo.unk_1)
    {
        case 0:
            unk_8a260();
            gCableLinkInfo.unk_1 = 1;
            break;

        case 1:
            if (*param_1 == 1)
            {
                unk_8a2c8();
                gCableLinkInfo.unk_1 = 2;
            }
            break;

        case 2:
            switch (*param_1)
            {
                case 1:
                    if (gCableLinkInfo.unk_0 != 0 && gCableLinkInfo.unk_3 > 1)
                        gCableLinkInfo.unk_10 = 1;
                    break;

                case 2:
                    gCableLinkInfo.unk_1 = 0;
                    write16(REG_SIO_DATA8, 0);
                    break;

                default:
                    unk_8a4cc();
            }
            break;

        case 3:
            unk_8a4f8();
            gCableLinkInfo.unk_1 = 4;

        case 4:
            unk_8a548(param_2);
            unk_8a628(param_3);
            break;
    }

    *param_1 = 0;

    error = gCableLinkInfo.unk_2 | (gCableLinkInfo.unk_3 << 2);
    if (gCableLinkInfo.unk_0 == 8)
        error |= 0x20;

    errorFlag_0 = gCableLinkInfo.unk_C << 0x8;
    errorFlag_1 = gCableLinkInfo.unk_11 << 0x9;
    errorFlag_hardware = gCableLinkInfo.hardwareErrorFlag << CABLE_LINK_ERROR_SHIFT_HARDWARE;
    errorFlag_checksum = gCableLinkInfo.checksumErrorFlag << CABLE_LINK_ERROR_SHIFT_CHECKSUM;
    errorFlag_overflow = gCableLinkInfo.overflowErrorFlags << CABLE_LINK_ERROR_SHIFT_OVERFLOW;
    errorFlag_sioInternal = gCableLinkInfo.sioErrorFlags << CABLE_LINK_ERROR_SHIFT_SIO;

    if (gCableLinkInfo.unk_1 == 4)
    {
        temp = error | 0x40 | errorFlag_0;

        temp |= errorFlag_1;
        temp |= errorFlag_hardware;
        temp |= errorFlag_checksum;
        temp |= errorFlag_overflow;
        temp |= errorFlag_sioInternal;
    }
    else
    {
        temp = error | errorFlag_0;

        temp |= errorFlag_1;
        temp |= errorFlag_hardware;
        temp |= errorFlag_checksum;
        temp |= errorFlag_overflow;
        temp |= errorFlag_sioInternal;
    }
    error = temp;

    if (gCableLinkInfo.unk_2 > 1)
        error |= CABLE_LINK_ERROR_ID_OVER;

    return error;
}

/**
 * @brief 8a4cc | 2c | To document
 * 
 */
void unk_8a4cc(void)
{
    if ((read32(REG_SIO) & (SIO_STATE_HIGH_OR_NONE | SIO_HIGH_DURING_INACTIVITY)) == SIO_HIGH_DURING_INACTIVITY && gCableLinkInfo.unk_2 == 0)
        gCableLinkInfo.unk_0 = 8;
    else
        gCableLinkInfo.unk_0 = 0;
}

/**
 * @brief 8a4f8 | 50 | To document
 * 
 */
void unk_8a4f8(void)
{
    if (gCableLinkInfo.unk_0 != 0)
    {
        write16(REG_TM3CNT_L, -132);
        write16(REG_TM3CNT_H, TIMER_CONTROL_IRQ_ENABLE | 1);

        gUnk_30058d0 = read16(REG_IME);
        write16(REG_IME, FALSE);
        write16(REG_IE, read16(REG_IE) | IF_TIMER3);
        write16(REG_IME, gUnk_30058d0);
    }
}

/**
 * @brief 8a548 | e0 | To document
 * 
 * @param param_1 To document
 */
void unk_8a548(u16* param_1)
{
    u8 offset;
    u8 i;

    gUnk_30058d0 = read16(REG_IME);
    write16(REG_IME, FALSE);

    if (gCableLinkInfo.unk_9D < ARRAY_SIZE(gCableLinkInfo.unk_A0[0][0]))
    {
        offset = gCableLinkInfo.unk_9C + gCableLinkInfo.unk_9D;
        if (offset >= ARRAY_SIZE(gCableLinkInfo.unk_A0[0][0]))
            offset -= ARRAY_SIZE(gCableLinkInfo.unk_A0[0][0]);

        for (i = 0; i < ARRAY_SIZE(gCableLinkInfo.unk_A0); i++)
        {
            gUnk_30058d8 |= *param_1;
            gCableLinkInfo.unk_1C[i][offset] = *param_1;
            *param_1++ = 0;
        }
    }
    else
    {
        // Send overflow error
        gCableLinkInfo.overflowErrorFlags |= 1;
    }

    if (gUnk_30058d8)
    {
        gCableLinkInfo.unk_9D++;
        gUnk_30058d8 = 0;
    }

    write16(REG_IME, gUnk_30058d0);
    gUnk_3005b50 = gCableLinkInfo.unk_9D;
}

/**
 * @brief 8a628 | 108 | To document
 * 
 * @param param_1 To document
 */
void unk_8a628(CableLinkBuffer1_T param_1)
{
    u8 i;
    u8 j;

    gUnk_30058d0 = read16(REG_IME);
    write16(REG_IME, FALSE);

    if (gCableLinkInfo.unk_1A1 == 0)
    {
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < gCableLinkInfo.unk_3; j++)
            {
                param_1[i][j] = 0;
            }
        }

        gCableLinkInfo.unk_C = TRUE;
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < gCableLinkInfo.unk_3; j++)
            {
                param_1[i][j] = gCableLinkInfo.unk_A0[j][i][gCableLinkInfo.unk_1A0];
            }
        }

        gCableLinkInfo.unk_1A1--;
        gCableLinkInfo.unk_1A0++;

        if (gCableLinkInfo.unk_1A0 >= ARRAY_SIZE(gCableLinkInfo.unk_A0[0][0]))
            gCableLinkInfo.unk_1A0 = 0;

        gCableLinkInfo.unk_C = FALSE;
    }

    write16(REG_IME, gUnk_30058d0);
}

/**
 * @brief 8a730 | 70 | To document
 * 
 */
void unk_8a730(void)
{
    if (gCableLinkInfo.unk_0)
    {
        if (gCableLinkInfo.unk_1 != 2)
        {
            if (gCableLinkInfo.unk_1 != 4)
                return;

            if (gCableLinkInfo.unk_D < 3)
            {
                if (gCableLinkInfo.hardwareErrorFlag == 0)
                    gCableLinkInfo.sioErrorFlags = 1;
                else
                    CableLinkSetSioCntStartBitActive_Duplicate();

                return;
            }

            if (gCableLinkInfo.sioErrorFlags == 0)
            {
                gCableLinkInfo.unk_D = 0;
                CableLinkSetSioCntStartBitActive_Duplicate();
            }
            return;
        }

        CableLinkSetSioCntStartBitActive_Duplicate();
        return;
    }
    
    if (gCableLinkInfo.unk_1 != 4 && gCableLinkInfo.unk_1 != 2)
        return;

    gUnk_30058d2++;
    if (gUnk_30058d2 <= 10)
        return;

    if (gCableLinkInfo.unk_1 == 4)
    {
        gCableLinkInfo.sioErrorFlags = 2;
    }
    
    if (gCableLinkInfo.unk_1 == 2)
    {
        gCableLinkInfo.unk_2 = 0;
        gCableLinkInfo.unk_3 = 0;
        gCableLinkInfo.unk_11 = 0;
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
    gCableLinkInfo.unk_2 = control << 0x1A >> 0x1E;

    switch (gCableLinkInfo.unk_1)
    {
        case 4:
            if (control & 0x40)
                gCableLinkInfo.hardwareErrorFlag = TRUE;

            unk_8a94c();
            unk_8aa54();
            unk_8ab24();
            break;

        case 2:
            if (!unk_8a850())
                break;

            if (gCableLinkInfo.unk_0)
            {
                gCableLinkInfo.unk_1 = 3;
                gCableLinkInfo.unk_D = 2;
            }
            else
            {
                gCableLinkInfo.unk_1 = 4;
            }
            break;
    }

    gCableLinkInfo.unk_D++;
    gUnk_30058d2 = FALSE;

    if (gCableLinkInfo.unk_D == 2)
        gUnk_3005b54 = gCableLinkInfo.unk_1A1;
}

/**
 * @brief 8a840 | 10 | Sets the start bit of the SIO control register
 * 
 */
void CableLinkSetSioCntStartBitActive_Duplicate(void)
{
    write16(REG_SIO, read16(REG_SIO) | SIO_START_BIT_ACTIVE);
}

/**
 * @brief 8a850 | fc | To document
 * 
 * @return u8 To document
 */
u8 unk_8a850(void)
{
    u16 data8;
    u8 i;
    u8 var_0;
    u32 data_0;
    u32 data_1;
    u32* ptr;

    var_0 = 0;

    data8 = USHORT_MAX;

    if (gCableLinkInfo.unk_10 == 1)
        write16(REG_SIO_DATA8, 0x8FFF);
    else
        write16(REG_SIO_DATA8, 0x7C40);

    gCableLinkInfo.unk_10 = 0;

    ptr = REG_SIO_MULTI;
    data_1 = ptr[1];
    data_0 = ptr[0];

    write32(&gCableLinkInfo.sioIncomingData[0], data_0);
    write32(&gCableLinkInfo.sioIncomingData[2], data_1);

    for (i = 0; i < 2; i++)
    {    
        if ((gCableLinkInfo.sioIncomingData[i] & -4) == 0x7C40 || gCableLinkInfo.sioIncomingData[i] == 0x8FFF)
        {
            var_0++;

            if (data8 > gCableLinkInfo.sioIncomingData[i] && gCableLinkInfo.sioIncomingData[i])
                data8 = gCableLinkInfo.sioIncomingData[i];
        }
        else if (gCableLinkInfo.sioIncomingData[i] != 0xFFFF)
        {
            var_0 = 0;
            break;
        }
        else if (i == gCableLinkInfo.unk_2)
            var_0 = 0;
    }

    gCableLinkInfo.unk_3 = var_0;

    if (gCableLinkInfo.unk_3 > 1)
    {
        if (gCableLinkInfo.unk_3 == gUnk_30058d5 && gCableLinkInfo.sioIncomingData[0] == 0x8FFF)
            return TRUE;
    
        if (gCableLinkInfo.unk_3 > 1)
        {
            gCableLinkInfo.unk_11 = (data8 & 3) + 1;
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

    gUnk_30058d5 = gCableLinkInfo.unk_3;

    return FALSE;
}

/**
 * @brief 8a94c | 108 | To document
 * 
 */
void unk_8a94c(void)
{
    u16 buffer[4];
    u32 data_0;
    u32 data_1;
    u32* ptr;
    u8 i;
    u8 offset;

    ptr = REG_SIO_MULTI;
    data_1 = ptr[1];
    data_0 = ptr[0];

    *(u32*)&buffer[0] = data_0;
    *(u32*)&buffer[2] = data_1;

    if (gCableLinkInfo.unk_18 == 0)
    {
        for (i = 0; i < gCableLinkInfo.unk_3; i++)
        {
            if (gCableLinkInfo.unk_16 != buffer[i] && gUnk_30058d6)
                gCableLinkInfo.checksumErrorFlag = TRUE;
        }

        gCableLinkInfo.unk_16 = 0;
        gUnk_30058d6 = TRUE;
    }
    else
    {
        offset = gCableLinkInfo.unk_1A0 + gCableLinkInfo.unk_1A1;
        if (offset >= ARRAY_SIZE(gCableLinkInfo.unk_A0[0][0]))
            offset = offset - ARRAY_SIZE(gCableLinkInfo.unk_A0[0][0]);

        if (gCableLinkInfo.unk_1A1 < ARRAY_SIZE(gCableLinkInfo.unk_A0[0][0]))
        {
            for (i = 0; i < gCableLinkInfo.unk_3; i++)
            {
                gCableLinkInfo.unk_16 += buffer[i];
                gUnk_30058da |= buffer[i];

                gCableLinkInfo.unk_A0[i][gCableLinkInfo.unk_19][offset] = buffer[i];
            }
        }
        else
        {
            gCableLinkInfo.overflowErrorFlags |= 2;
        }

        gCableLinkInfo.unk_19++;
        if (gCableLinkInfo.unk_19 == 2 && gUnk_30058da != 0)
        {
            gCableLinkInfo.unk_1A1++;
            gUnk_30058da = 0;
        }
    }
}

/**
 * @brief 8aa54 | 9c | To document
 * 
 */
void unk_8aa54(void)
{
    if (gCableLinkInfo.unk_18 == 2)
    {
        write16(REG_SIO_DATA8, gCableLinkInfo.unk_16);

        if (!gUnk_30058d3)
        {
            gCableLinkInfo.unk_9D--;
            gCableLinkInfo.unk_9C++;

            if (gCableLinkInfo.unk_9C > 31)
                gCableLinkInfo.unk_9C = 0;
        }
        else
        {
            gUnk_30058d3 = FALSE;
        }
    }
    else
    {
        if (gCableLinkInfo.unk_18 == 0 && gCableLinkInfo.unk_9D == 0)
            gUnk_30058d3 = TRUE;

        if (gUnk_30058d3)
        {
            write16(REG_SIO_DATA8, 0);
        }
        else
        {
            write16(REG_SIO_DATA8, gCableLinkInfo.unk_1C[gCableLinkInfo.unk_18][gCableLinkInfo.unk_9C]);
        }

        gCableLinkInfo.unk_18++;
    }
}

/**
 * @brief 8aaf0 | 34 | To document
 * 
 */
void unk_8aaf0(void)
{
    if (gCableLinkInfo.unk_0)
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
    if (gCableLinkInfo.unk_19 == 2)
    {
        gCableLinkInfo.unk_18 = 0;
        gCableLinkInfo.unk_19 = 0;
    }
    else if (gCableLinkInfo.unk_0)
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

    gCableLinkInfo.unk_9D = 0;
    gCableLinkInfo.unk_9C = 0;

    for (i = 0; i < ARRAY_SIZE(gCableLinkInfo.unk_1C); i++)
    {
        for (j = 0; j < ARRAY_SIZE(gCableLinkInfo.unk_1C[0]); j++)
        {
            gCableLinkInfo.unk_1C[i][j] = 0xEFFF;
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

    gCableLinkInfo.unk_1A1 = 0;
    gCableLinkInfo.unk_1A0 = 0;

    for (i = 0; i < ARRAY_SIZE(gCableLinkInfo.unk_A0); i++)
    {
        for (j = 0; j < ARRAY_SIZE(gCableLinkInfo.unk_A0[0]); j++)
        {
            for (k = 0; k < ARRAY_SIZE(gCableLinkInfo.unk_A0[0][0]); k++)
            {
                gCableLinkInfo.unk_A0[i][j][k] = 0xEFFF;
            }
        }
    }
}
