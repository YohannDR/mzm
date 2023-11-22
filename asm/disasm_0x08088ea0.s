    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start CableLinkProcess
CableLinkProcess: @ 0x08088ea0
    push {r4, lr}
    sub sp, #4
    ldr r0, lbl_08088ec0 @ =gIoTransferInfo
    movs r1, #0
    strb r1, [r0, #0xb]
    ldrb r1, [r0, #9]
    adds r2, r0, #0
    cmp r1, #0xc
    bls lbl_08088eb4
    b lbl_08089100
lbl_08088eb4:
    lsls r0, r1, #2
    ldr r1, lbl_08088ec4 @ =lbl_08088ec8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08088ec0: .4byte gIoTransferInfo
lbl_08088ec4: .4byte lbl_08088ec8
lbl_08088ec8: @ jump table
    .4byte lbl_08088efc @ case 0
    .4byte lbl_08088f14 @ case 1
    .4byte lbl_08088f48 @ case 2
    .4byte lbl_08088f98 @ case 3
    .4byte lbl_08089058 @ case 4
    .4byte lbl_08089088 @ case 5
    .4byte lbl_080890ae @ case 6
    .4byte lbl_080890c8 @ case 7
    .4byte lbl_080890bc @ case 8
    .4byte lbl_080890d4 @ case 9
    .4byte lbl_080890e4 @ case 10
    .4byte lbl_080890ea @ case 11
    .4byte lbl_08089100 @ case 12
lbl_08088efc:
    ldr r4, lbl_08088f10 @ =gIoTransferInfo
    movs r0, #0
    strh r0, [r4, #6]
    movs r0, #0x14
    bl FadeMusic
    ldrb r0, [r4, #9]
    adds r0, #1
    b lbl_080890fe
    .align 2, 0
lbl_08088f10: .4byte gIoTransferInfo
lbl_08088f14:
    ldr r4, lbl_08088f40 @ =gIoTransferInfo
    ldrh r0, [r4, #6]
    adds r0, #1
    strh r0, [r4, #6]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x1e
    bhi lbl_08088f26
    b lbl_08089100
lbl_08088f26:
    bl sub_08003458
    ldr r0, lbl_08088f44 @ =gMusicInfo
    ldrh r1, [r0, #0x1c]
    strh r1, [r4, #0x12]
    adds r0, #0x21
    ldrb r0, [r0]
    strh r0, [r4, #0x14]
    movs r0, #0
    strh r0, [r4, #6]
    ldrb r0, [r4, #9]
    adds r0, #1
    b lbl_080890fe
    .align 2, 0
lbl_08088f40: .4byte gIoTransferInfo
lbl_08088f44: .4byte gMusicInfo
lbl_08088f48:
    ldr r0, lbl_08088f78 @ =serial_communication_code_connecting
    bl CallbackSetSerialCommunication
    ldr r0, lbl_08088f7c @ =sub_08089bd4
    bl CallbackSetTimer3
    ldr r0, lbl_08088f80 @ =gDataSentPointer
    ldr r1, lbl_08088f84 @ =0x08754bd0
    str r1, [r0]
    ldr r2, lbl_08088f88 @ =gDataSentSize
    ldr r0, lbl_08088f8c @ =0x087566c4
    subs r0, r0, r1
    str r0, [r2]
    ldr r0, lbl_08088f90 @ =gMultiBootParamData
    str r1, [r0, #0x28]
    adds r1, r0, #0
    adds r1, #0x4b
    movs r4, #0
    strb r4, [r1]
    bl sub_08089164
    ldr r1, lbl_08088f94 @ =gIoTransferInfo
    strh r4, [r1, #6]
    b lbl_08089068
    .align 2, 0
lbl_08088f78: .4byte serial_communication_code_connecting
lbl_08088f7c: .4byte sub_08089bd4
lbl_08088f80: .4byte gDataSentPointer
lbl_08088f84: .4byte 0x08754bd0
lbl_08088f88: .4byte gDataSentSize
lbl_08088f8c: .4byte 0x087566c4
lbl_08088f90: .4byte gMultiBootParamData
lbl_08088f94: .4byte gIoTransferInfo
lbl_08088f98:
    ldr r3, lbl_08089004 @ =gIoTransferInfo
    ldrh r0, [r3, #6]
    adds r0, #1
    movs r4, #0
    strh r0, [r3, #6]
    ldr r2, lbl_08089008 @ =gMultiBootParamData
    ldrb r1, [r2, #0x1e]
    movs r0, #0xe
    ands r0, r1
    cmp r0, #0
    beq lbl_08088fbe
    ldrb r0, [r2, #0x18]
    cmp r0, #0xd1
    bne lbl_08088fb6
    strh r4, [r3, #6]
lbl_08088fb6:
    ldrb r0, [r2, #0x18]
    cmp r0, #0xdf
    bls lbl_08088fbe
    strh r4, [r3, #6]
lbl_08088fbe:
    ldr r3, lbl_08089008 @ =gMultiBootParamData
    ldrb r0, [r3, #0x18]
    cmp r0, #0
    bne lbl_08088fe4
    ldrb r0, [r3, #0x1e]
    cmp r0, #0
    beq lbl_08088fe4
    ldr r0, lbl_0808900c @ =gDataSentPointer
    ldr r1, [r0]
    adds r1, #0xc0
    ldr r0, lbl_08089010 @ =gDataSentSize
    ldr r2, [r0]
    subs r2, #0xc0
    movs r0, #1
    str r0, [sp]
    adds r0, r3, #0
    movs r3, #4
    bl sub_08089600
lbl_08088fe4:
    ldr r4, lbl_08089008 @ =gMultiBootParamData
    adds r0, r4, #0
    bl sub_080891a0
    ldr r1, lbl_08089014 @ =gUnk_3005874
    str r0, [r1]
    adds r0, r4, #0
    bl sub_080896b8
    cmp r0, #0
    beq lbl_0808901c
    ldr r1, lbl_08089018 @ =gUnk_3005884
    movs r0, #0
    strb r0, [r1]
    b lbl_08089066
    .align 2, 0
lbl_08089004: .4byte gIoTransferInfo
lbl_08089008: .4byte gMultiBootParamData
lbl_0808900c: .4byte gDataSentPointer
lbl_08089010: .4byte gDataSentSize
lbl_08089014: .4byte gUnk_3005874
lbl_08089018: .4byte gUnk_3005884
lbl_0808901c:
    ldrb r2, [r4, #0x18]
    cmp r2, #0xd1
    beq lbl_08089044
    ldr r0, lbl_0808903c @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08089044
    cmp r2, #0xdf
    bhi lbl_08089044
    ldr r1, lbl_08089040 @ =gIoTransferInfo
    movs r0, #8
    strb r0, [r1, #9]
    b lbl_08089100
    .align 2, 0
lbl_0808903c: .4byte gChangedInput
lbl_08089040: .4byte gIoTransferInfo
lbl_08089044:
    ldr r1, lbl_08089054 @ =gIoTransferInfo
    ldrh r0, [r1, #6]
    cmp r0, #0xb4
    bls lbl_08089100
    movs r0, #7
    strb r0, [r1, #9]
    b lbl_08089100
    .align 2, 0
lbl_08089054: .4byte gIoTransferInfo
lbl_08089058:
    ldr r0, lbl_08089070 @ =0x0875e6a8
    ldr r1, lbl_08089074 @ =0x087566c4
    subs r0, r0, r1
    bl sub_0808980c
    cmp r0, #0
    bne lbl_0808907c
lbl_08089066:
    ldr r1, lbl_08089078 @ =gIoTransferInfo
lbl_08089068:
    ldrb r0, [r1, #9]
    adds r0, #1
    strb r0, [r1, #9]
    b lbl_08089100
    .align 2, 0
lbl_08089070: .4byte 0x0875e6a8
lbl_08089074: .4byte 0x087566c4
lbl_08089078: .4byte gIoTransferInfo
lbl_0808907c:
    ldr r1, lbl_08089084 @ =gIoTransferInfo
    movs r0, #9
    strb r0, [r1, #9]
    b lbl_08089100
    .align 2, 0
lbl_08089084: .4byte gIoTransferInfo
lbl_08089088:
    ldr r0, lbl_0808909c @ =gUnk_3005880
    ldr r0, [r0]
    cmp r0, #1
    beq lbl_080890a6
    cmp r0, #1
    blo lbl_080890a0
    cmp r0, #2
    beq lbl_080890aa
    b lbl_080890ae
    .align 2, 0
lbl_0808909c: .4byte gUnk_3005880
lbl_080890a0:
    ldrb r0, [r2, #9]
    adds r0, #1
    b lbl_080890ac
lbl_080890a6:
    movs r0, #8
    b lbl_080890ac
lbl_080890aa:
    movs r0, #9
lbl_080890ac:
    strb r0, [r2, #9]
lbl_080890ae:
    ldr r1, lbl_080890b8 @ =gIoTransferInfo
    movs r0, #0xa
    strb r0, [r1, #9]
    b lbl_08089100
    .align 2, 0
lbl_080890b8: .4byte gIoTransferInfo
lbl_080890bc:
    ldr r0, lbl_080890c4 @ =gIoTransferInfo
    movs r1, #2
    b lbl_080890d8
    .align 2, 0
lbl_080890c4: .4byte gIoTransferInfo
lbl_080890c8:
    ldr r0, lbl_080890d0 @ =gIoTransferInfo
    movs r1, #3
    b lbl_080890d8
    .align 2, 0
lbl_080890d0: .4byte gIoTransferInfo
lbl_080890d4:
    ldr r0, lbl_080890e0 @ =gIoTransferInfo
    movs r1, #4
lbl_080890d8:
    strb r1, [r0, #0xb]
    movs r1, #0xb
    strb r1, [r0, #9]
    b lbl_08089100
    .align 2, 0
lbl_080890e0: .4byte gIoTransferInfo
lbl_080890e4:
    ldr r1, lbl_0808910c @ =gIoTransferInfo
    movs r0, #2
    strb r0, [r1, #8]
lbl_080890ea:
    bl InitializeAudio
    bl FileSelectApplyStereo
    ldr r4, lbl_0808910c @ =gIoTransferInfo
    ldrh r0, [r4, #0x12]
    ldrb r1, [r4, #0x14]
    bl PlayMusic
    movs r0, #0xc
lbl_080890fe:
    strb r0, [r4, #9]
lbl_08089100:
    ldr r0, lbl_0808910c @ =gIoTransferInfo
    ldrb r0, [r0, #0xb]
    add sp, #4
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0808910c: .4byte gIoTransferInfo

    thumb_func_start sub_08089110
sub_08089110: @ 0x08089110
    push {r4, lr}
    adds r4, r0, #0
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    ldr r0, lbl_08089124 @ =gSramErrorFlag
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08089158
    b lbl_08089152
    .align 2, 0
lbl_08089124: .4byte gSramErrorFlag
lbl_08089128:
    movs r3, #0x28
    cmp r0, #0x2f
    bls lbl_08089148
    cmp r0, #0x39
    bhi lbl_08089138
    ldrb r0, [r4]
    subs r0, #0x30
    b lbl_08089144
lbl_08089138:
    cmp r0, #0x5a
    bhi lbl_08089148
    ldr r3, lbl_08089160 @ =0x0000ffc9
    adds r0, r3, #0
    ldrb r3, [r4]
    adds r0, r0, r3
lbl_08089144:
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
lbl_08089148:
    lsls r0, r2, #0xc
    orrs r3, r0
    strh r3, [r1]
    adds r1, #2
    adds r4, #1
lbl_08089152:
    ldrb r0, [r4]
    cmp r0, #0
    bne lbl_08089128
lbl_08089158:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08089160: .4byte 0x0000ffc9

    thumb_func_start sub_08089164
sub_08089164: @ 0x08089164
    adds r2, r0, #0
    movs r1, #0
    strb r1, [r2, #0x1e]
    strb r1, [r2, #0x18]
    strb r1, [r2, #0x1d]
    adds r3, r2, #0
    adds r3, #0x4a
    movs r0, #0xf
    strb r0, [r3]
    adds r0, r2, #0
    adds r0, #0x48
    strb r1, [r0]
    strh r1, [r2, #0x16]
    ldr r0, lbl_08089190 @ =0x04000134
    strh r1, [r0]
    ldr r2, lbl_08089194 @ =0x04000128
    ldr r3, lbl_08089198 @ =0x00002003
    adds r0, r3, #0
    strh r0, [r2]
    ldr r0, lbl_0808919c @ =0x0400012a
    strh r1, [r0]
    bx lr
    .align 2, 0
lbl_08089190: .4byte 0x04000134
lbl_08089194: .4byte 0x04000128
lbl_08089198: .4byte 0x00002003
lbl_0808919c: .4byte 0x0400012a

    thumb_func_start sub_080891a0
sub_080891a0: @ 0x080891a0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    adds r7, r0, #0
    bl sub_080896b8
    cmp r0, #0
    beq lbl_080891b6
    b lbl_0808957e
lbl_080891b6:
    adds r0, r7, #0
    adds r0, #0x4a
    ldrb r1, [r0]
    mov sl, r0
    cmp r1, #0xf
    bls lbl_080891ca
    subs r0, r1, #1
    mov r1, sl
    strb r0, [r1]
    b lbl_0808957e
lbl_080891ca:
    adds r1, r7, #0
    adds r1, #0x48
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_080891f4
    movs r0, #0
    strb r0, [r1]
    ldr r0, lbl_080891f0 @ =0x04000128
    ldrh r0, [r0]
    movs r5, #0xfc
    ands r5, r0
    cmp r5, #8
    beq lbl_080891f4
    adds r0, r7, #0
    bl sub_08089164
    movs r0, #8
    eors r0, r5
    b lbl_08089580
    .align 2, 0
lbl_080891f0: .4byte 0x04000128
lbl_080891f4:
    ldrb r0, [r7, #0x18]
    cmp r0, #0xdf
    bls lbl_08089246
    adds r0, r7, #0
    bl sub_080896cc
    adds r5, r0, #0
    cmp r5, #0
    beq lbl_08089208
    b lbl_08089580
lbl_08089208:
    adds r0, r7, #0
    adds r0, #0x4b
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_08089224
    ldrb r0, [r7, #0x18]
    cmp r0, #0xe1
    bls lbl_08089224
    adds r0, r7, #0
    bl sub_080896b8
    cmp r0, #0
    bne lbl_08089224
    b lbl_0808956e
lbl_08089224:
    adds r0, r7, #0
    bl sub_080896b8
    cmp r0, #0
    beq lbl_08089230
    b lbl_0808957e
lbl_08089230:
    ldrh r0, [r7, #0x16]
    cmp r0, #0
    bne lbl_08089240
    adds r0, r7, #0
    bl sub_08089164
    movs r0, #0x71
    b lbl_08089580
lbl_08089240:
    subs r0, #1
    strh r0, [r7, #0x16]
    b lbl_0808957e
lbl_08089246:
    ldrb r0, [r7, #0x18]
    cmp r0, #2
    bne lbl_0808924e
    b lbl_08089384
lbl_0808924e:
    cmp r0, #2
    bgt lbl_0808925c
    cmp r0, #0
    beq lbl_0808926a
    cmp r0, #1
    beq lbl_08089326
    b lbl_080894bc
lbl_0808925c:
    cmp r0, #0xd0
    bne lbl_08089262
    b lbl_080893d0
lbl_08089262:
    cmp r0, #0xd1
    bne lbl_08089268
    b lbl_0808946a
lbl_08089268:
    b lbl_080894bc
lbl_0808926a:
    movs r3, #0xe
    movs r5, #3
    ldr r0, lbl_080892b0 @ =0x04000120
    ldrh r0, [r0, #6]
    adds r1, r0, #0
    ldr r0, lbl_080892b4 @ =0x0000ffff
    ldrb r2, [r7, #0x1e]
    adds r6, r2, #0
    cmp r1, r0
    bne lbl_08089292
    adds r4, r1, #0
    ldr r1, lbl_080892b8 @ =0x04000126
lbl_08089282:
    asrs r3, r3, #1
    subs r1, #2
    subs r5, #1
    cmp r5, #0
    beq lbl_08089292
    ldrh r0, [r1]
    cmp r0, r4
    beq lbl_08089282
lbl_08089292:
    movs r0, #0xe
    ands r3, r0
    strb r3, [r7, #0x1d]
    movs r5, #3
    ldr r0, lbl_080892b0 @ =0x04000120
    ldrh r0, [r0, #6]
    adds r4, r0, #0
    asrs r0, r2, #3
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080892c0
    ldr r0, lbl_080892bc @ =0x00007208
    b lbl_080892e6
    .align 2, 0
lbl_080892b0: .4byte 0x04000120
lbl_080892b4: .4byte 0x0000ffff
lbl_080892b8: .4byte 0x04000126
lbl_080892bc: .4byte 0x00007208
lbl_080892c0:
    subs r5, #1
    cmp r5, #0
    beq lbl_080892ec
    lsls r0, r5, #1
    ldr r1, lbl_08089314 @ =0x04000120
    adds r0, r0, r1
    ldrh r0, [r0]
    adds r4, r0, #0
    adds r0, r2, #0
    asrs r0, r5
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080892c0
    adds r0, r1, #0
    lsls r0, r5
    movs r1, #0xe4
    lsls r1, r1, #7
    orrs r0, r1
lbl_080892e6:
    cmp r4, r0
    beq lbl_080892c0
    movs r3, #0
lbl_080892ec:
    adds r0, r3, #0
    ands r0, r6
    strb r0, [r7, #0x1e]
    cmp r3, #0
    bne lbl_080892fc
    movs r0, #0xf
    mov r2, sl
    strb r0, [r2]
lbl_080892fc:
    mov r1, sl
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08089318
    ldrb r0, [r7, #0x1d]
    ldrb r2, [r7, #0x1e]
    cmp r0, r2
    beq lbl_0808931e
    adds r0, r7, #0
    bl sub_080895dc
    b lbl_08089326
    .align 2, 0
lbl_08089314: .4byte 0x04000120
lbl_08089318:
    subs r0, #1
    mov r1, sl
    strb r0, [r1]
lbl_0808931e:
    ldrb r1, [r7, #0x1e]
    movs r2, #0xc4
    lsls r2, r2, #7
    b lbl_08089426
lbl_08089326:
    adds r1, r7, #0
    adds r1, #0x49
    movs r0, #0
    strb r0, [r1]
    movs r5, #3
    mov ip, r1
    ldr r3, lbl_0808937c @ =gUnk_3005888
lbl_08089334:
    lsls r0, r5, #1
    ldr r2, lbl_08089380 @ =0x04000120
    adds r0, r0, r2
    ldrh r0, [r0]
    adds r4, r0, #0
    asrs r0, r4, #8
    subs r2, r5, #1
    cmp r0, #0x72
    bne lbl_0808935e
    lsls r0, r2, #1
    adds r0, r0, r3
    strh r4, [r0]
    movs r0, #0xff
    ands r4, r0
    movs r0, #1
    lsls r0, r5
    cmp r4, r0
    bne lbl_0808935e
    ldrb r0, [r1]
    orrs r4, r0
    strb r4, [r1]
lbl_0808935e:
    adds r5, r2, #0
    cmp r5, #0
    bne lbl_08089334
    ldrb r0, [r7, #0x1d]
    mov r1, ip
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_0808931e
    movs r0, #2
    strb r0, [r7, #0x18]
    mov r2, ip
    ldrb r1, [r2]
    movs r2, #0xc2
    lsls r2, r2, #7
    b lbl_08089426
    .align 2, 0
lbl_0808937c: .4byte gUnk_3005888
lbl_08089380: .4byte 0x04000120
lbl_08089384:
    movs r5, #3
    movs r0, #0x49
    adds r0, r0, r7
    mov ip, r0
    mov r4, ip
    movs r6, #1
    ldr r1, lbl_080893c8 @ =gUnk_3005888
    mov sb, r1
    ldr r2, lbl_080893cc @ =0x04000120
    mov r8, r2
lbl_08089398:
    ldrb r3, [r4]
    adds r0, r3, #0
    asrs r0, r5
    ands r0, r6
    subs r2, r5, #1
    cmp r0, #0
    beq lbl_080893be
    lsls r0, r5, #1
    add r0, r8
    ldrh r1, [r0]
    lsls r0, r2, #1
    add r0, sb
    ldrh r0, [r0]
    cmp r1, r0
    beq lbl_080893be
    adds r0, r6, #0
    lsls r0, r5
    eors r3, r0
    strb r3, [r4]
lbl_080893be:
    adds r5, r2, #0
    cmp r5, #0
    bne lbl_08089398
    b lbl_08089524
    .align 2, 0
lbl_080893c8: .4byte gUnk_3005888
lbl_080893cc: .4byte 0x04000120
lbl_080893d0:
    movs r3, #1
    movs r5, #3
    movs r0, #0x49
    adds r0, r0, r7
    mov ip, r0
    adds r6, r7, #0
    adds r6, #0x19
    ldr r1, lbl_08089434 @ =gUnk_3005888
    mov r8, r1
lbl_080893e2:
    lsls r0, r5, #1
    ldr r2, lbl_08089438 @ =0x04000120
    adds r0, r0, r2
    ldrh r0, [r0]
    adds r4, r0, #0
    subs r2, r5, #1
    adds r0, r6, r2
    strb r4, [r0]
    mov r0, ip
    ldrb r1, [r0]
    asrs r1, r5
    movs r0, #1
    ands r1, r0
    cmp r1, #0
    beq lbl_08089416
    asrs r0, r4, #8
    subs r0, #0x72
    cmp r0, #1
    bls lbl_0808940a
    b lbl_08089574
lbl_0808940a:
    lsls r0, r2, #1
    add r0, r8
    ldrh r0, [r0]
    cmp r4, r0
    bne lbl_08089416
    movs r3, #0
lbl_08089416:
    adds r5, r2, #0
    cmp r5, #0
    bne lbl_080893e2
    cmp r3, #0
    bne lbl_0808943c
    ldrb r1, [r7, #0x1c]
    movs r2, #0xc6
    lsls r2, r2, #7
lbl_08089426:
    adds r0, r2, #0
    orrs r1, r0
    adds r0, r7, #0
    bl sub_08089590
    b lbl_08089580
    .align 2, 0
lbl_08089434: .4byte gUnk_3005888
lbl_08089438: .4byte 0x04000120
lbl_0808943c:
    movs r0, #0xd1
    strb r0, [r7, #0x18]
    movs r3, #0x11
    movs r5, #3
    adds r1, r6, #2
lbl_08089446:
    ldrb r0, [r1]
    adds r3, r3, r0
    subs r1, #1
    subs r5, #1
    cmp r5, #0
    bne lbl_08089446
    strb r3, [r7, #0x14]
    movs r0, #0xff
    ands r3, r0
    movs r1, #0xc8
    lsls r1, r1, #7
    adds r0, r1, #0
    orrs r3, r0
    adds r0, r7, #0
    adds r1, r3, #0
    bl sub_08089590
    b lbl_08089580
lbl_0808946a:
    movs r5, #3
    movs r2, #0x49
    ldrb r1, [r2, r7]
    ldr r2, lbl_080894a8 @ =0x04000126
    movs r3, #1
lbl_08089474:
    ldrh r0, [r2]
    adds r4, r0, #0
    adds r0, r1, #0
    asrs r0, r5
    ands r0, r3
    cmp r0, #0
    beq lbl_08089488
    asrs r0, r4, #8
    cmp r0, #0x73
    bne lbl_08089574
lbl_08089488:
    subs r2, #2
    subs r5, #1
    cmp r5, #0
    bne lbl_08089474
    adds r0, r7, #0
    bl Multiboot
    adds r5, r0, #0
    cmp r5, #0
    bne lbl_080894ac
    movs r0, #0xe0
    strb r0, [r7, #0x18]
    adds r0, #0xb0
    strh r0, [r7, #0x16]
    b lbl_0808957e
    .align 2, 0
lbl_080894a8: .4byte 0x04000126
lbl_080894ac:
    adds r0, r7, #0
    bl sub_08089164
    movs r0, #0x1e
    mov r1, sl
    strb r0, [r1]
    movs r0, #0x70
    b lbl_08089580
lbl_080894bc:
    movs r5, #3
    movs r2, #0x49
    adds r2, r2, r7
    mov ip, r2
    mov r8, ip
    movs r0, #1
    mov sb, r0
lbl_080894ca:
    mov r1, r8
    ldrb r6, [r1]
    adds r0, r6, #0
    asrs r0, r5
    mov r2, sb
    ands r0, r2
    cmp r0, #0
    beq lbl_08089504
    lsls r0, r5, #1
    ldr r1, lbl_08089520 @ =0x04000120
    adds r0, r0, r1
    ldrh r0, [r0]
    adds r4, r0, #0
    asrs r2, r4, #8
    ldrb r0, [r7, #0x18]
    lsrs r0, r0, #1
    movs r1, #0x62
    subs r1, r1, r0
    mov r3, sb
    lsls r3, r5
    cmp r2, r1
    bne lbl_080894fe
    movs r0, #0xff
    ands r4, r0
    cmp r4, r3
    beq lbl_08089504
lbl_080894fe:
    eors r6, r3
    mov r2, r8
    strb r6, [r2]
lbl_08089504:
    subs r5, #1
    cmp r5, #0
    bne lbl_080894ca
    ldrb r0, [r7, #0x18]
    cmp r0, #0xc4
    bne lbl_08089524
    mov r0, ip
    ldrb r1, [r0]
    movs r0, #0xe
    ands r0, r1
    strb r0, [r7, #0x1e]
    strb r5, [r7, #0x18]
    b lbl_0808931e
    .align 2, 0
lbl_08089520: .4byte 0x04000120
lbl_08089524:
    mov r1, ip
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08089536
    adds r0, r7, #0
    bl sub_08089164
    movs r0, #0x50
    b lbl_08089580
lbl_08089536:
    ldrb r0, [r7, #0x18]
    adds r0, #2
    strb r0, [r7, #0x18]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xc4
    bne lbl_08089546
    b lbl_0808931e
lbl_08089546:
    ldrb r0, [r7, #0x18]
    ldr r1, [r7, #0x28]
    adds r0, r0, r1
    subs r1, r0, #3
    ldrb r2, [r1]
    lsls r2, r2, #8
    subs r0, #4
    ldrb r1, [r0]
    orrs r1, r2
    adds r0, r7, #0
    bl sub_08089590
    adds r5, r0, #0
    cmp r5, #0
    bne lbl_08089580
    adds r0, r7, #0
    adds r0, #0x4b
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_0808957e
lbl_0808956e:
    bl sub_080897d0
    b lbl_080891ca
lbl_08089574:
    adds r0, r7, #0
    bl sub_08089164
    movs r0, #0x60
    b lbl_08089580
lbl_0808957e:
    movs r0, #0
lbl_08089580:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_08089590
sub_08089590: @ 0x08089590
    push {r4, lr}
    adds r2, r0, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    ldr r3, lbl_080895bc @ =0x04000128
    ldrh r0, [r3]
    movs r4, #0x8c
    ands r4, r0
    cmp r4, #8
    bne lbl_080895c8
    ldr r0, lbl_080895c0 @ =0x0400012a
    strh r1, [r0]
    ldr r1, lbl_080895c4 @ =0x00002083
    adds r0, r1, #0
    strh r0, [r3]
    adds r1, r2, #0
    adds r1, #0x48
    movs r0, #1
    strb r0, [r1]
    movs r0, #0
    b lbl_080895d4
    .align 2, 0
lbl_080895bc: .4byte 0x04000128
lbl_080895c0: .4byte 0x0400012a
lbl_080895c4: .4byte 0x00002083
lbl_080895c8:
    adds r0, r2, #0
    bl sub_08089164
    movs r0, #8
    eors r4, r0
    adds r0, r4, #0
lbl_080895d4:
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_080895dc
sub_080895dc: @ 0x080895dc
    push {lr}
    adds r1, r0, #0
    ldrb r0, [r1, #0x18]
    cmp r0, #0
    beq lbl_080895ee
    adds r0, r1, #0
    bl sub_08089164
    b lbl_080895fa
lbl_080895ee:
    adds r2, r1, #0
    adds r2, #0x4a
    strb r0, [r2]
    strb r0, [r1, #0x1e]
    movs r0, #1
    strb r0, [r1, #0x18]
lbl_080895fa:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08089600
sub_08089600: @ 0x08089600
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    adds r7, r1, #0
    ldr r0, [sp, #0x14]
    lsls r3, r3, #0x18
    lsrs r6, r3, #0x18
    lsls r0, r0, #0x18
    asrs r3, r0, #0x18
    ldrb r0, [r5, #0x18]
    cmp r0, #0
    bne lbl_0808963a
    ldrb r0, [r5, #0x1e]
    cmp r0, #0
    beq lbl_0808963a
    adds r0, r5, #0
    adds r0, #0x4a
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0808963a
    str r7, [r5, #0x20]
    adds r2, #0xf
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r2, r0
    subs r0, #0xf0
    adds r1, r2, r0
    ldr r0, lbl_08089644 @ =0x0003ff00
    cmp r1, r0
    bls lbl_08089648
lbl_0808963a:
    adds r0, r5, #0
    bl sub_08089164
    b lbl_080896b0
    .align 2, 0
lbl_08089644: .4byte 0x0003ff00
lbl_08089648:
    adds r0, r7, r2
    str r0, [r5, #0x24]
    adds r0, r3, #4
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #8
    bhi lbl_0808969c
    lsls r0, r0, #2
    ldr r1, lbl_08089660 @ =lbl_08089664
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08089660: .4byte lbl_08089664
lbl_08089664: @ jump table
    .4byte lbl_08089688 @ case 0
    .4byte lbl_08089688 @ case 1
    .4byte lbl_08089688 @ case 2
    .4byte lbl_08089688 @ case 3
    .4byte lbl_08089690 @ case 4
    .4byte lbl_08089696 @ case 5
    .4byte lbl_08089696 @ case 6
    .4byte lbl_08089696 @ case 7
    .4byte lbl_08089696 @ case 8
lbl_08089688:
    lsls r4, r6, #3
    movs r0, #3
    subs r0, r0, r3
    b lbl_0808969a
lbl_08089690:
    movs r0, #0x38
    adds r4, r6, #0
    b lbl_0808969a
lbl_08089696:
    lsls r4, r6, #3
    subs r0, r3, #1
lbl_0808969a:
    orrs r4, r0
lbl_0808969c:
    movs r0, #0x3f
    ands r4, r0
    lsls r0, r4, #1
    movs r2, #0x7f
    rsbs r2, r2, #0
    adds r1, r2, #0
    orrs r0, r1
    strb r0, [r5, #0x1c]
    movs r0, #0xd0
    strb r0, [r5, #0x18]
lbl_080896b0:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_080896b8
sub_080896b8: @ 0x080896b8
    push {lr}
    ldrb r0, [r0, #0x18]
    cmp r0, #0xe9
    beq lbl_080896c4
    movs r0, #0
    b lbl_080896c6
lbl_080896c4:
    movs r0, #1
lbl_080896c6:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_080896cc
sub_080896cc: @ 0x080896cc
    push {r4, r5, r6, lr}
    adds r3, r0, #0
    ldrb r0, [r3, #0x18]
    cmp r0, #0xe0
    beq lbl_080896e8
    cmp r0, #0xe0
    blt lbl_080896f8
    cmp r0, #0xe8
    bgt lbl_080896f8
    cmp r0, #0xe7
    blt lbl_080896f8
    movs r4, #3
    ldrb r5, [r3, #0x1e]
    b lbl_08089758
lbl_080896e8:
    movs r1, #0
    movs r0, #0xe1
    strb r0, [r3, #0x18]
    str r1, [r3, #4]
    movs r0, #0x80
    lsls r0, r0, #0xd
    str r0, [r3]
    b lbl_0808974a
lbl_080896f8:
    movs r4, #3
    ldrb r5, [r3, #0x1e]
    movs r6, #1
    ldr r1, lbl_08089754 @ =0x04000126
lbl_08089700:
    ldrh r0, [r1]
    adds r2, r0, #0
    adds r0, r5, #0
    asrs r0, r4
    ands r0, r6
    cmp r0, #0
    beq lbl_08089714
    ldr r0, [r3, #4]
    cmp r2, r0
    bne lbl_080896e8
lbl_08089714:
    subs r1, #2
    subs r4, #1
    cmp r4, #0
    bne lbl_08089700
    ldrb r0, [r3, #0x18]
    adds r0, #1
    strb r0, [r3, #0x18]
    ldr r1, [r3]
    ldrh r0, [r3]
    str r0, [r3, #4]
    cmp r1, #0
    bne lbl_08089742
    ldr r0, [r3, #0x28]
    adds r1, r0, #0
    adds r1, #0xac
    ldrb r1, [r1]
    adds r0, #0xad
    ldrb r0, [r0]
    lsls r0, r0, #8
    orrs r1, r0
    str r1, [r3, #4]
    lsls r1, r1, #5
    str r1, [r3]
lbl_08089742:
    ldr r0, [r3]
    lsrs r0, r0, #5
    str r0, [r3]
lbl_08089748:
    ldrh r1, [r3]
lbl_0808974a:
    adds r0, r3, #0
    bl sub_08089590
    b lbl_080897b0
    .align 2, 0
lbl_08089754: .4byte 0x04000126
lbl_08089758:
    lsls r0, r4, #1
    ldr r1, lbl_080897a0 @ =0x04000120
    adds r0, r0, r1
    ldrh r0, [r0]
    adds r2, r0, #0
    adds r0, r5, #0
    asrs r0, r4
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08089774
    ldr r0, [r3, #4]
    cmp r2, r0
    bne lbl_080897a4
lbl_08089774:
    subs r4, #1
    cmp r4, #0
    bne lbl_08089758
    ldrb r0, [r3, #0x18]
    adds r0, #1
    strb r0, [r3, #0x18]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xe9
    beq lbl_080897ae
    ldr r0, [r3, #0x28]
    adds r1, r0, #0
    adds r1, #0xae
    ldrb r1, [r1]
    adds r0, #0xaf
    ldrb r0, [r0]
    lsls r0, r0, #8
    orrs r1, r0
    str r1, [r3]
    str r1, [r3, #4]
    b lbl_08089748
    .align 2, 0
lbl_080897a0: .4byte 0x04000120
lbl_080897a4:
    adds r0, r3, #0
    bl sub_08089164
    movs r0, #0x71
    b lbl_080897b0
lbl_080897ae:
    movs r0, #0
lbl_080897b0:
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_080897b8
sub_080897b8: @ 0x080897b8
    mov r2, pc
    lsrs r2, r2, #0x18
    movs r1, #0xc
    cmp r2, #2
    beq lbl_080897ca
    movs r1, #0xd
    cmp r2, #8
    beq lbl_080897ca
    movs r1, #4
lbl_080897ca:
    subs r0, r0, r1
    bgt lbl_080897ca
    bx lr

    thumb_func_start sub_080897d0
sub_080897d0: @ 0x080897d0
    push {r4, r5, lr}
    movs r2, #0
    ldr r3, lbl_08089804 @ =0x04000128
    ldrh r1, [r3]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_080897f4
    ldr r5, lbl_08089808 @ =0x0000795c
    movs r4, #0x80
lbl_080897e4:
    adds r2, #1
    cmp r2, r5
    bgt lbl_080897f4
    ldrh r1, [r3]
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_080897e4
lbl_080897f4:
    movs r0, #0x96
    lsls r0, r0, #2
    bl sub_080897b8
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08089804: .4byte 0x04000128
lbl_08089808: .4byte 0x0000795c

    thumb_func_start sub_0808980c
sub_0808980c: @ 0x0808980c
    push {r4, r5, lr}
    sub sp, #4
    adds r5, r0, #0
    adds r4, r1, #0
    bl sub_08089d98
lbl_08089818:
    movs r0, #1
    adds r1, r5, #0
    adds r2, r4, #0
    movs r3, #0
    bl sub_080899c8
    adds r1, r0, #0
    ldr r0, lbl_08089840 @ =gUnk_30058a8
    strh r1, [r0]
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_08089844
    movs r0, #0xc
    ands r0, r1
    cmp r0, #0
    beq lbl_08089844
    movs r4, #0
    b lbl_08089894
    .align 2, 0
lbl_08089840: .4byte gUnk_30058a8
lbl_08089844:
    ldr r0, lbl_08089854 @ =gUnk_30058a8
    ldrh r1, [r0]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08089858
    movs r4, #1
    b lbl_08089894
    .align 2, 0
lbl_08089854: .4byte gUnk_30058a8
lbl_08089858:
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08089864
    movs r4, #2
    b lbl_08089894
lbl_08089864:
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08089870
    movs r4, #3
    b lbl_08089894
lbl_08089870:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0808987c
    movs r4, #4
    b lbl_08089894
lbl_0808987c:
    ldr r0, lbl_08089890 @ =gIoTransferInfo
    ldr r0, [r0]
    cmp r0, #0
    beq lbl_08089888
    bl _call_via_r0
lbl_08089888:
    bl VBlankIntrWait
    b lbl_08089818
    .align 2, 0
lbl_08089890: .4byte gIoTransferInfo
lbl_08089894:
    movs r0, #0
    str r0, [sp]
    ldr r1, lbl_080898b0 @ =gUnk_3005890
    ldr r2, lbl_080898b4 @ =0x05000006
    mov r0, sp
    bl CpuSet
    bl sub_08089dec
    adds r0, r4, #0
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080898b0: .4byte gUnk_3005890
lbl_080898b4: .4byte 0x05000006

    thumb_func_start sub_080898b8
sub_080898b8: @ 0x080898b8
    push {lr}
    sub sp, #4
    ldr r1, lbl_080898ec @ =gUnk_30058aa
    movs r0, #0
    strb r0, [r1]
    ldr r0, lbl_080898f0 @ =gUnk_30058ac
    movs r1, #0
    strh r1, [r0]
    ldr r0, lbl_080898f4 @ =gUnk_30058ae
    strb r1, [r0]
    ldr r0, lbl_080898f8 @ =gUnk_30058af
    strb r1, [r0]
    ldr r0, lbl_080898fc @ =gUnk_30058b0
    strb r1, [r0]
    ldr r0, lbl_08089900 @ =gUnk_30058b1
    strb r1, [r0]
    movs r0, #0
    str r0, [sp]
    ldr r1, lbl_08089904 @ =gUnk_3005890
    ldr r2, lbl_08089908 @ =0x05000006
    mov r0, sp
    bl CpuSet
    add sp, #4
    pop {r0}
    bx r0
    .align 2, 0
lbl_080898ec: .4byte gUnk_30058aa
lbl_080898f0: .4byte gUnk_30058ac
lbl_080898f4: .4byte gUnk_30058ae
lbl_080898f8: .4byte gUnk_30058af
lbl_080898fc: .4byte gUnk_30058b0
lbl_08089900: .4byte gUnk_30058b1
lbl_08089904: .4byte gUnk_3005890
lbl_08089908: .4byte 0x05000006

    thumb_func_start sub_0808990c
sub_0808990c: @ 0x0808990c
    push {r4, lr}
    ldr r4, lbl_08089938 @ =0x04000208
    movs r3, #0
    strh r3, [r4]
    ldr r2, lbl_0808993c @ =0x04000200
    ldrh r1, [r2]
    ldr r0, lbl_08089940 @ =0x0000ff3f
    ands r0, r1
    strh r0, [r2]
    movs r0, #1
    strh r0, [r4]
    ldr r0, lbl_08089944 @ =0x04000128
    strh r3, [r0]
    subs r0, #0x1a
    strh r3, [r0]
    ldr r1, lbl_08089948 @ =0x04000202
    movs r0, #0xc0
    strh r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08089938: .4byte 0x04000208
lbl_0808993c: .4byte 0x04000200
lbl_08089940: .4byte 0x0000ff3f
lbl_08089944: .4byte 0x04000128
lbl_08089948: .4byte 0x04000202

    thumb_func_start sub_0808994c
sub_0808994c: @ 0x0808994c
    push {r4, r5, r6, r7, lr}
    ldr r5, lbl_0808998c @ =0x04000208
    movs r4, #0
    strh r4, [r5]
    ldr r3, lbl_08089990 @ =0x04000200
    ldrh r1, [r3]
    ldr r0, lbl_08089994 @ =0x0000ff3f
    ands r0, r1
    strh r0, [r3]
    movs r6, #1
    strh r6, [r5]
    ldr r0, lbl_08089998 @ =0x04000134
    strh r4, [r0]
    ldr r2, lbl_0808999c @ =0x04000128
    movs r1, #0x80
    lsls r1, r1, #6
    adds r0, r1, #0
    strh r0, [r2]
    ldrh r0, [r2]
    ldr r7, lbl_080899a0 @ =0x00004003
    adds r1, r7, #0
    orrs r0, r1
    strh r0, [r2]
    strh r4, [r5]
    ldrh r0, [r3]
    movs r1, #0x80
    orrs r0, r1
    strh r0, [r3]
    strh r6, [r5]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808998c: .4byte 0x04000208
lbl_08089990: .4byte 0x04000200
lbl_08089994: .4byte 0x0000ff3f
lbl_08089998: .4byte 0x04000134
lbl_0808999c: .4byte 0x04000128
lbl_080899a0: .4byte 0x00004003

    thumb_func_start sub_080899a4
sub_080899a4: @ 0x080899a4
    ldr r1, lbl_080899c0 @ =0x04000134
    movs r0, #0
    strh r0, [r1]
    ldr r2, lbl_080899c4 @ =0x04000128
    movs r1, #0xa0
    lsls r1, r1, #7
    adds r0, r1, #0
    strh r0, [r2]
    ldrh r0, [r2]
    movs r1, #8
    orrs r0, r1
    strh r0, [r2]
    bx lr
    .align 2, 0
lbl_080899c0: .4byte 0x04000134
lbl_080899c4: .4byte 0x04000128

    thumb_func_start sub_080899c8
sub_080899c8: @ 0x080899c8
    push {r4, r5, r6, lr}
    adds r4, r1, #0
    adds r5, r2, #0
    adds r6, r3, #0
    ldr r0, lbl_080899e4 @ =gUnk_3005890
    ldrb r0, [r0, #1]
    cmp r0, #6
    bls lbl_080899da
    b lbl_08089b0c
lbl_080899da:
    lsls r0, r0, #2
    ldr r1, lbl_080899e8 @ =lbl_080899ec
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080899e4: .4byte gUnk_3005890
lbl_080899e8: .4byte lbl_080899ec
lbl_080899ec: @ jump table
    .4byte lbl_08089a08 @ case 0
    .4byte lbl_08089a20 @ case 1
    .4byte lbl_08089a60 @ case 2
    .4byte lbl_08089a74 @ case 3
    .4byte lbl_08089ab4 @ case 4
    .4byte lbl_08089ac4 @ case 5
    .4byte lbl_08089afc @ case 6
lbl_08089a08:
    bl sub_080898b8
    bl sub_0808994c
    ldr r1, lbl_08089a1c @ =gUnk_3005890
    movs r0, #1
    strb r0, [r1, #3]
    strb r0, [r1, #1]
    b lbl_08089b0c
    .align 2, 0
lbl_08089a1c: .4byte gUnk_3005890
lbl_08089a20:
    movs r0, #1
    bl sub_08089b3c
    lsls r0, r0, #0x10
    cmp r0, #0
    beq lbl_08089a30
    bl set_siocnt_start_bit_active
lbl_08089a30:
    ldr r2, lbl_08089a58 @ =gUnk_3005890
    ldrb r0, [r2, #5]
    cmp r0, #0
    beq lbl_08089a3c
    movs r0, #6
    strb r0, [r2, #1]
lbl_08089a3c:
    ldr r1, lbl_08089a5c @ =gUnk_30058ae
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x1e
    bls lbl_08089b0c
    movs r0, #4
    strb r0, [r2, #5]
    movs r0, #6
    strb r0, [r2, #1]
    b lbl_08089b0c
    .align 2, 0
lbl_08089a58: .4byte gUnk_3005890
lbl_08089a5c: .4byte gUnk_30058ae
lbl_08089a60:
    bl sub_080899a4
    adds r0, r4, #0
    adds r1, r5, #0
    adds r2, r6, #0
    bl sub_08089b70
    ldr r1, lbl_08089a9c @ =gUnk_3005890
    movs r0, #3
    strb r0, [r1, #1]
lbl_08089a74:
    ldr r4, lbl_08089a9c @ =gUnk_3005890
    ldrb r0, [r4, #3]
    cmp r0, #2
    beq lbl_08089b0c
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_08089aa4
    ldr r1, lbl_08089aa0 @ =gUnk_30058ac
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #9
    bls lbl_08089aa4
    bl set_siocnt_start_bit_active
    movs r0, #2
    b lbl_08089b0a
    .align 2, 0
lbl_08089a9c: .4byte gUnk_3005890
lbl_08089aa0: .4byte gUnk_30058ac
lbl_08089aa4:
    bl set_siocnt_start_bit_active
    ldr r1, lbl_08089ab0 @ =gUnk_3005890
    movs r0, #2
    strb r0, [r1, #3]
    b lbl_08089b0c
    .align 2, 0
lbl_08089ab0: .4byte gUnk_3005890
lbl_08089ab4:
    bl sub_0808994c
    ldr r1, lbl_08089ac0 @ =gUnk_3005890
    movs r0, #5
    strb r0, [r1, #1]
    b lbl_08089b0c
    .align 2, 0
lbl_08089ac0: .4byte gUnk_3005890
lbl_08089ac4:
    ldr r0, lbl_08089af4 @ =gUnk_3005890
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_08089ad8
    ldr r0, lbl_08089af8 @ =gUnk_30058ac
    ldrh r0, [r0]
    cmp r0, #9
    bls lbl_08089ad8
    bl set_siocnt_start_bit_active
lbl_08089ad8:
    ldr r1, lbl_08089af8 @ =gUnk_30058ac
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x1e
    bls lbl_08089b0c
    ldr r0, lbl_08089af4 @ =gUnk_3005890
    movs r1, #1
    strb r1, [r0, #5]
    movs r1, #6
    strb r1, [r0, #1]
    b lbl_08089b0c
    .align 2, 0
lbl_08089af4: .4byte gUnk_3005890
lbl_08089af8: .4byte gUnk_30058ac
lbl_08089afc:
    ldr r4, lbl_08089b38 @ =gUnk_3005890
    ldrb r0, [r4, #3]
    cmp r0, #0
    beq lbl_08089b0c
    bl sub_0808990c
    movs r0, #0
lbl_08089b0a:
    strb r0, [r4, #3]
lbl_08089b0c:
    ldr r4, lbl_08089b38 @ =gUnk_3005890
    ldr r1, [r4, #0xc]
    movs r0, #0x64
    muls r0, r1, r0
    ldr r1, [r4, #0x10]
    bl __divsi3
    strb r0, [r4, #2]
    ldrb r0, [r4, #3]
    ldrb r1, [r4, #4]
    lsls r1, r1, #2
    orrs r0, r1
    ldrb r1, [r4, #5]
    lsls r1, r1, #4
    orrs r0, r1
    ldrb r1, [r4, #2]
    lsls r1, r1, #8
    orrs r0, r1
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08089b38: .4byte gUnk_3005890

    thumb_func_start sub_08089b3c
sub_08089b3c: @ 0x08089b3c
    push {lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    ldr r0, lbl_08089b58 @ =0x04000128
    ldr r0, [r0]
    movs r1, #0xc
    ands r0, r1
    cmp r0, #8
    bne lbl_08089b60
    cmp r2, #0
    beq lbl_08089b60
    ldr r1, lbl_08089b5c @ =gUnk_3005890
    movs r0, #1
    b lbl_08089b64
    .align 2, 0
lbl_08089b58: .4byte 0x04000128
lbl_08089b5c: .4byte gUnk_3005890
lbl_08089b60:
    ldr r1, lbl_08089b6c @ =gUnk_3005890
    movs r0, #0
lbl_08089b64:
    strb r0, [r1]
    pop {r1}
    bx r1
    .align 2, 0
lbl_08089b6c: .4byte gUnk_3005890

    thumb_func_start sub_08089b70
sub_08089b70: @ 0x08089b70
    push {r4, lr}
    ldr r4, lbl_08089b94 @ =0x04000128
    ldrh r2, [r4]
    movs r3, #1
    orrs r2, r3
    strh r2, [r4]
    ldr r2, lbl_08089b98 @ =gUnk_3005890
    str r1, [r2, #8]
    ldr r1, lbl_08089b9c @ =0x04000120
    str r0, [r1]
    lsrs r0, r0, #2
    adds r0, #1
    str r0, [r2, #0x10]
    bl sub_08089ba0
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08089b94: .4byte 0x04000128
lbl_08089b98: .4byte gUnk_3005890
lbl_08089b9c: .4byte 0x04000120

    thumb_func_start sub_08089ba0
sub_08089ba0: @ 0x08089ba0
    ldr r1, lbl_08089bc4 @ =0x0400010c
    ldr r2, lbl_08089bc8 @ =0x0000ff9b
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_08089bcc @ =0x0400010e
    movs r2, #0x40
    strh r2, [r0]
    ldr r3, lbl_08089bd0 @ =0x04000208
    movs r0, #0
    strh r0, [r3]
    adds r1, #0xf4
    ldrh r0, [r1]
    orrs r0, r2
    strh r0, [r1]
    movs r0, #1
    strh r0, [r3]
    bx lr
    .align 2, 0
lbl_08089bc4: .4byte 0x0400010c
lbl_08089bc8: .4byte 0x0000ff9b
lbl_08089bcc: .4byte 0x0400010e
lbl_08089bd0: .4byte 0x04000208

    thumb_func_start sub_08089bd4
sub_08089bd4: @ 0x08089bd4
    push {lr}
    bl sub_08089d74
    bl set_siocnt_start_bit_active
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start serial_communication_code_connecting
serial_communication_code_connecting: @ 0x08089be4
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #8
    ldr r0, lbl_08089c04 @ =0x04000128
    ldr r6, [r0]
    ldr r2, lbl_08089c08 @ =gUnk_3005890
    ldrb r0, [r2, #1]
    adds r4, r2, #0
    cmp r0, #3
    beq lbl_08089c98
    cmp r0, #3
    bgt lbl_08089c0c
    cmp r0, #1
    beq lbl_08089c12
    b lbl_08089d56
    .align 2, 0
lbl_08089c04: .4byte 0x04000128
lbl_08089c08: .4byte gUnk_3005890
lbl_08089c0c:
    cmp r0, #5
    beq lbl_08089d00
    b lbl_08089d56
lbl_08089c12:
    ldr r1, lbl_08089c4c @ =0x0400012a
    ldr r2, lbl_08089c50 @ =0x00007c40
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_08089c54 @ =0x04000120
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [sp]
    str r1, [sp, #4]
    movs r1, #0
    movs r3, #0
    movs r2, #0
    ldr r5, lbl_08089c58 @ =gUnk_30058b0
    ldr r0, lbl_08089c5c @ =gUnk_30058b1
    mov r8, r0
    lsls r6, r6, #0x1a
    ldr r0, lbl_08089c50 @ =0x00007c40
    mov ip, r0
    ldr r7, lbl_08089c60 @ =0x0000ffff
lbl_08089c38:
    lsls r0, r1, #1
    add r0, sp
    ldrh r0, [r0]
    cmp r0, ip
    bne lbl_08089c64
    adds r0, r3, #1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    b lbl_08089c6e
    .align 2, 0
lbl_08089c4c: .4byte 0x0400012a
lbl_08089c50: .4byte 0x00007c40
lbl_08089c54: .4byte 0x04000120
lbl_08089c58: .4byte gUnk_30058b0
lbl_08089c5c: .4byte gUnk_30058b1
lbl_08089c60: .4byte 0x0000ffff
lbl_08089c64:
    cmp r0, r7
    beq lbl_08089c6e
    adds r0, r2, #1
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
lbl_08089c6e:
    adds r0, r1, #1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #3
    bls lbl_08089c38
    strb r3, [r5]
    lsrs r0, r6, #0x1e
    mov r1, r8
    strb r0, [r1]
    cmp r3, #2
    bhi lbl_08089c92
    cmp r3, #1
    bls lbl_08089d56
    cmp r2, #0
    bne lbl_08089d56
    movs r0, #2
    strb r0, [r4, #1]
    b lbl_08089d56
lbl_08089c92:
    movs r0, #8
    strb r0, [r4, #5]
    b lbl_08089d56
lbl_08089c98:
    ldr r2, lbl_08089cb8 @ =0x04000120
    ldr r0, [r2]
    ldr r1, [r4, #0xc]
    ldr r0, [r4, #0x10]
    cmp r1, r0
    bge lbl_08089cbc
    ldr r0, [r4, #8]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r0, [r1]
    str r0, [r2]
    ldr r0, [r4, #0x14]
    ldr r1, [r1]
    adds r0, r0, r1
    str r0, [r4, #0x14]
    b lbl_08089cc8
    .align 2, 0
lbl_08089cb8: .4byte 0x04000120
lbl_08089cbc:
    cmp r1, r0
    bne lbl_08089cc4
    ldr r0, [r4, #0x14]
    b lbl_08089cc6
lbl_08089cc4:
    movs r0, #0
lbl_08089cc6:
    str r0, [r2]
lbl_08089cc8:
    ldr r1, [r4, #0xc]
    adds r1, #1
    str r1, [r4, #0xc]
    ldr r0, lbl_08089ce8 @ =gUnk_30058b0
    ldrb r2, [r0]
    ldr r0, [r4, #0x10]
    adds r0, r0, r2
    cmp r1, r0
    bge lbl_08089cf0
    ldr r0, lbl_08089cec @ =0x0400010e
    ldrh r1, [r0]
    movs r2, #0x80
    orrs r1, r2
    strh r1, [r0]
    b lbl_08089d56
    .align 2, 0
lbl_08089ce8: .4byte gUnk_30058b0
lbl_08089cec: .4byte 0x0400010e
lbl_08089cf0:
    movs r0, #0
    movs r1, #4
    strb r1, [r4, #1]
    ldr r1, lbl_08089cfc @ =gUnk_30058ac
    strh r0, [r1]
    b lbl_08089d56
    .align 2, 0
lbl_08089cfc: .4byte gUnk_30058ac
lbl_08089d00:
    ldr r0, lbl_08089d30 @ =0x04000120
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [sp]
    str r1, [sp, #4]
    movs r1, #1
    movs r3, #1
    ldr r0, lbl_08089d34 @ =gUnk_30058b0
    adds r5, r0, #0
    ldrb r0, [r5]
    cmp r1, r0
    bhs lbl_08089d56
    movs r4, #6
lbl_08089d1a:
    lsls r0, r1, #1
    add r0, sp
    ldrh r0, [r0]
    cmp r0, #1
    beq lbl_08089d38
    cmp r0, #2
    bne lbl_08089d3e
    strb r0, [r2, #4]
    strb r4, [r2, #1]
    b lbl_08089d56
    .align 2, 0
lbl_08089d30: .4byte 0x04000120
lbl_08089d34: .4byte gUnk_30058b0
lbl_08089d38:
    adds r0, r3, #1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
lbl_08089d3e:
    ldrb r0, [r5]
    cmp r3, r0
    bne lbl_08089d4a
    movs r0, #1
    strb r0, [r2, #4]
    strb r4, [r2, #1]
lbl_08089d4a:
    adds r0, r1, #1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldrb r0, [r5]
    cmp r1, r0
    blo lbl_08089d1a
lbl_08089d56:
    add sp, #8
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start set_siocnt_start_bit_active
set_siocnt_start_bit_active: @ 0x08089d64
    ldr r0, lbl_08089d70 @ =0x04000128
    ldrh r1, [r0]
    movs r2, #0x80
    orrs r1, r2
    strh r1, [r0]
    bx lr
    .align 2, 0
lbl_08089d70: .4byte 0x04000128

    thumb_func_start sub_08089d74
sub_08089d74: @ 0x08089d74
    ldr r2, lbl_08089d88 @ =0x0400010e
    ldrh r1, [r2]
    ldr r0, lbl_08089d8c @ =0x0000ff7f
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_08089d90 @ =0x0400010c
    ldr r2, lbl_08089d94 @ =0x0000ff9b
    adds r0, r2, #0
    strh r0, [r1]
    bx lr
    .align 2, 0
lbl_08089d88: .4byte 0x0400010e
lbl_08089d8c: .4byte 0x0000ff7f
lbl_08089d90: .4byte 0x0400010c
lbl_08089d94: .4byte 0x0000ff9b

    thumb_func_start sub_08089d98
sub_08089d98: @ 0x08089d98
    ldr r1, lbl_08089dc4 @ =gRegIme_Backup
    ldr r0, lbl_08089dc8 @ =0x04000208
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_08089dcc @ =gRegIe_Backup
    ldr r0, lbl_08089dd0 @ =0x04000200
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_08089dd4 @ =gRegTm3Cnt_H_Backup
    ldr r0, lbl_08089dd8 @ =0x0400010e
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_08089ddc @ =gRegSiocnt_Backup
    ldr r0, lbl_08089de0 @ =0x04000128
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_08089de4 @ =gRegRcnt_Backup
    ldr r0, lbl_08089de8 @ =0x04000134
    ldrh r0, [r0]
    strh r0, [r1]
    bx lr
    .align 2, 0
lbl_08089dc4: .4byte gRegIme_Backup
lbl_08089dc8: .4byte 0x04000208
lbl_08089dcc: .4byte gRegIe_Backup
lbl_08089dd0: .4byte 0x04000200
lbl_08089dd4: .4byte gRegTm3Cnt_H_Backup
lbl_08089dd8: .4byte 0x0400010e
lbl_08089ddc: .4byte gRegSiocnt_Backup
lbl_08089de0: .4byte 0x04000128
lbl_08089de4: .4byte gRegRcnt_Backup
lbl_08089de8: .4byte 0x04000134

    thumb_func_start sub_08089dec
sub_08089dec: @ 0x08089dec
    ldr r1, lbl_08089e18 @ =0x04000208
    ldr r0, lbl_08089e1c @ =gRegIme_Backup
    ldrh r0, [r0]
    strh r0, [r1]
    subs r1, #8
    ldr r0, lbl_08089e20 @ =gRegIe_Backup
    ldrh r0, [r0]
    strh r0, [r1]
    subs r1, #0xf2
    ldr r0, lbl_08089e24 @ =gRegTm3Cnt_H_Backup
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #0x1a
    ldr r0, lbl_08089e28 @ =gRegSiocnt_Backup
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #0xc
    ldr r0, lbl_08089e2c @ =gRegRcnt_Backup
    ldrh r0, [r0]
    strh r0, [r1]
    bx lr
    .align 2, 0
lbl_08089e18: .4byte 0x04000208
lbl_08089e1c: .4byte gRegIme_Backup
lbl_08089e20: .4byte gRegIe_Backup
lbl_08089e24: .4byte gRegTm3Cnt_H_Backup
lbl_08089e28: .4byte gRegSiocnt_Backup
lbl_08089e2c: .4byte gRegRcnt_Backup

    thumb_func_start unk_89e30
unk_89e30: @ 0x08089e30
    push {r4, r5, lr}
    sub sp, #4
    ldr r1, lbl_08089e54 @ =gIoTransferInfo
    movs r0, #0
    strb r0, [r1, #0xb]
    ldrh r0, [r1, #6]
    adds r0, #1
    strh r0, [r1, #6]
    ldrb r0, [r1, #0xa]
    cmp r0, #5
    bls lbl_08089e48
    b lbl_08089f82
lbl_08089e48:
    lsls r0, r0, #2
    ldr r1, lbl_08089e58 @ =lbl_08089e5c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08089e54: .4byte gIoTransferInfo
lbl_08089e58: .4byte lbl_08089e5c
lbl_08089e5c: @ jump table
    .4byte lbl_08089e74 @ case 0
    .4byte lbl_08089f10 @ case 1
    .4byte lbl_08089f66 @ case 2
    .4byte lbl_08089f7c @ case 3
    .4byte lbl_08089f7c @ case 4
    .4byte lbl_08089f82 @ case 5
lbl_08089e74:
    mov r0, sp
    movs r4, #0
    strh r4, [r0]
    ldr r1, lbl_08089edc @ =0x040000d4
    str r0, [r1]
    ldr r0, lbl_08089ee0 @ =gUnk_30058c0
    str r0, [r1, #4]
    ldr r0, lbl_08089ee4 @ =0x81000002
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    mov r0, sp
    strh r4, [r0]
    str r0, [r1]
    ldr r0, lbl_08089ee8 @ =gUnk_30058c4
    str r0, [r1, #4]
    ldr r0, lbl_08089eec @ =0x81000004
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, lbl_08089ef0 @ =gErrorFlag
    movs r5, #0
    str r5, [r0]
    ldr r0, lbl_08089ef4 @ =gUnk_30058cc
    strb r4, [r0]
    ldr r0, lbl_08089ef8 @ =gUnk_30058cd
    strb r4, [r0]
    ldr r0, lbl_08089efc @ =gUnk_30058ce
    strb r4, [r0]
    ldr r0, lbl_08089f00 @ =gUnk_30058cf
    strb r4, [r0]
    ldr r0, lbl_08089f04 @ =sub_0808a7b0
    bl CallbackSetSerialCommunication
    ldr r0, lbl_08089f08 @ =sub_0808a7a0
    bl CallbackSetTimer3
    bl sub_0808a39c
    ldr r1, lbl_08089f0c @ =gIoTransferInfo
    movs r0, #0xaa
    lsls r0, r0, #7
    strh r0, [r1, #0xe]
    movs r0, #0xff
    strb r0, [r1, #0x11]
    movs r0, #1
    rsbs r0, r0, #0
    strb r0, [r1, #0x10]
    strb r4, [r1, #0xc]
    strh r5, [r1, #6]
    ldrb r0, [r1, #0xa]
    adds r0, #1
    strb r0, [r1, #0xa]
    b lbl_08089f82
    .align 2, 0
lbl_08089edc: .4byte 0x040000d4
lbl_08089ee0: .4byte gUnk_30058c0
lbl_08089ee4: .4byte 0x81000002
lbl_08089ee8: .4byte gUnk_30058c4
lbl_08089eec: .4byte 0x81000004
lbl_08089ef0: .4byte gErrorFlag
lbl_08089ef4: .4byte gUnk_30058cc
lbl_08089ef8: .4byte gUnk_30058cd
lbl_08089efc: .4byte gUnk_30058ce
lbl_08089f00: .4byte gUnk_30058cf
lbl_08089f04: .4byte sub_0808a7b0
lbl_08089f08: .4byte sub_0808a7a0
lbl_08089f0c: .4byte gIoTransferInfo
lbl_08089f10:
    ldr r4, lbl_08089f2c @ =gIoTransferInfo
    ldrb r0, [r4, #4]
    cmp r0, #0
    bne lbl_08089f42
    bl sub_0808a260
    ldrh r1, [r4, #0xe]
    movs r0, #0xcc
    lsls r0, r0, #6
    cmp r1, r0
    bne lbl_08089f30
    movs r0, #2
    strb r0, [r4, #0xa]
    b lbl_08089f82
    .align 2, 0
lbl_08089f2c: .4byte gIoTransferInfo
lbl_08089f30:
    ldrb r0, [r4, #0xc]
    cmp r0, #0
    beq lbl_08089f3c
    movs r0, #3
    strb r0, [r4, #0xa]
    b lbl_08089f82
lbl_08089f3c:
    movs r0, #4
    strb r0, [r4, #0xa]
    b lbl_08089f82
lbl_08089f42:
    bl check_error
    ldrh r1, [r4, #0xe]
    movs r0, #0xcc
    lsls r0, r0, #6
    cmp r1, r0
    beq lbl_08089f56
    ldrb r1, [r4, #0xc]
    cmp r1, #0
    beq lbl_08089f5c
lbl_08089f56:
    movs r0, #0
    strb r0, [r4, #4]
    b lbl_08089f82
lbl_08089f5c:
    ldrh r0, [r4, #6]
    cmp r0, #0xb4
    bls lbl_08089f82
    strb r1, [r4, #4]
    b lbl_08089f82
lbl_08089f66:
    ldr r2, lbl_08089f74 @ =gFileScreenOptionsUnlocked
    ldr r1, lbl_08089f78 @ =gIoTransferInfo
    movs r0, #0x10
    ldrsb r0, [r1, r0]
    strh r0, [r2, #2]
    movs r0, #1
    b lbl_08089f80
    .align 2, 0
lbl_08089f74: .4byte gFileScreenOptionsUnlocked
lbl_08089f78: .4byte gIoTransferInfo
lbl_08089f7c:
    ldr r1, lbl_08089f90 @ =gIoTransferInfo
    movs r0, #4
lbl_08089f80:
    strb r0, [r1, #0xb]
lbl_08089f82:
    ldr r0, lbl_08089f90 @ =gIoTransferInfo
    ldrb r0, [r0, #0xb]
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08089f90: .4byte gIoTransferInfo

    thumb_func_start check_error
check_error: @ 0x08089f94
    push {r4, lr}
    sub sp, #4
    ldr r0, lbl_0808a0d0 @ =gUnk_30058cc
    ldr r1, lbl_0808a0d4 @ =gFrameCounter8Bit
    ldrb r2, [r1]
    movs r1, #1
    ands r1, r2
    strb r1, [r0]
    ldr r4, lbl_0808a0d8 @ =gErrorFlag
    ldr r1, lbl_0808a0dc @ =gUnk_30058c0
    ldr r2, lbl_0808a0e0 @ =gUnk_30058c4
    bl detect_error
    adds r2, r0, #0
    str r2, [r4]
    ldr r3, lbl_0808a0e4 @ =gUnk_30058ce
    movs r1, #3
    ands r1, r2
    strb r1, [r3]
    ldr r3, lbl_0808a0e8 @ =gUnk_30058cd
    movs r1, #0x1c
    ands r1, r2
    lsrs r1, r1, #2
    strb r1, [r3]
    ldr r3, lbl_0808a0ec @ =gUnk_30058cf
    movs r1, #0xe0
    lsls r1, r1, #4
    ands r1, r2
    lsrs r1, r1, #9
    strb r1, [r3]
    movs r1, #0x40
    ands r2, r1
    cmp r2, #0
    beq lbl_08089fe8
    ldr r0, lbl_0808a0f0 @ =gIoTransferInfo
    movs r1, #0
    strh r1, [r0, #6]
    ldrh r0, [r0, #0xe]
    bl sub_0808a12c
    bl sub_0808a1d4
lbl_08089fe8:
    ldr r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #0xf
    ands r1, r2
    cmp r1, #0
    beq lbl_0808a008
    ldr r2, lbl_0808a0f0 @ =gIoTransferInfo
    ldrb r0, [r2, #0xc]
    movs r1, #1
    orrs r0, r1
    strb r0, [r2, #0xc]
    ldr r0, lbl_0808a0f4 @ =0x085d9174
    ldr r1, lbl_0808a0f8 @ =0x0600e304
    movs r2, #0xc
    bl sub_08089110
lbl_0808a008:
    ldr r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #0xa
    ands r1, r2
    cmp r1, #0
    beq lbl_0808a028
    ldr r2, lbl_0808a0f0 @ =gIoTransferInfo
    ldrb r1, [r2, #0xc]
    movs r0, #2
    orrs r0, r1
    strb r0, [r2, #0xc]
    ldr r0, lbl_0808a0fc @ =0x085d9184
    ldr r1, lbl_0808a100 @ =0x0600e344
    movs r2, #0xc
    bl sub_08089110
lbl_0808a028:
    ldr r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #9
    ands r1, r2
    cmp r1, #0
    beq lbl_0808a048
    ldr r2, lbl_0808a0f0 @ =gIoTransferInfo
    ldrb r1, [r2, #0xc]
    movs r0, #4
    orrs r0, r1
    strb r0, [r2, #0xc]
    ldr r0, lbl_0808a104 @ =0x085d9198
    ldr r1, lbl_0808a108 @ =0x0600e384
    movs r2, #0xc
    bl sub_08089110
lbl_0808a048:
    ldr r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #0xb
    ands r1, r2
    cmp r1, #0
    beq lbl_0808a068
    ldr r2, lbl_0808a0f0 @ =gIoTransferInfo
    ldrb r1, [r2, #0xc]
    movs r0, #8
    orrs r0, r1
    strb r0, [r2, #0xc]
    ldr r0, lbl_0808a10c @ =0x085d91ac
    ldr r1, lbl_0808a110 @ =0x0600e3c4
    movs r2, #0xc
    bl sub_08089110
lbl_0808a068:
    ldr r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #0xc
    ands r1, r2
    cmp r1, #0
    beq lbl_0808a088
    ldr r2, lbl_0808a0f0 @ =gIoTransferInfo
    ldrb r1, [r2, #0xc]
    movs r0, #0x10
    orrs r0, r1
    strb r0, [r2, #0xc]
    ldr r0, lbl_0808a114 @ =0x085d91c0
    ldr r1, lbl_0808a118 @ =0x0600e404
    movs r2, #0xc
    bl sub_08089110
lbl_0808a088:
    ldr r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #0xd
    ands r1, r2
    cmp r1, #0
    beq lbl_0808a0a8
    ldr r2, lbl_0808a0f0 @ =gIoTransferInfo
    ldrb r1, [r2, #0xc]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r2, #0xc]
    ldr r0, lbl_0808a11c @ =0x085d91d4
    ldr r1, lbl_0808a120 @ =0x0600e444
    movs r2, #0xc
    bl sub_08089110
lbl_0808a0a8:
    ldr r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #0xe
    ands r1, r2
    cmp r1, #0
    beq lbl_0808a0c8
    ldr r2, lbl_0808a0f0 @ =gIoTransferInfo
    ldrb r1, [r2, #0xc]
    movs r0, #0x40
    orrs r0, r1
    strb r0, [r2, #0xc]
    ldr r0, lbl_0808a124 @ =0x085d91e8
    ldr r1, lbl_0808a128 @ =0x0600e484
    movs r2, #0xc
    bl sub_08089110
lbl_0808a0c8:
    add sp, #4
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0808a0d0: .4byte gUnk_30058cc
lbl_0808a0d4: .4byte gFrameCounter8Bit
lbl_0808a0d8: .4byte gErrorFlag
lbl_0808a0dc: .4byte gUnk_30058c0
lbl_0808a0e0: .4byte gUnk_30058c4
lbl_0808a0e4: .4byte gUnk_30058ce
lbl_0808a0e8: .4byte gUnk_30058cd
lbl_0808a0ec: .4byte gUnk_30058cf
lbl_0808a0f0: .4byte gIoTransferInfo
lbl_0808a0f4: .4byte 0x085d9174
lbl_0808a0f8: .4byte 0x0600e304
lbl_0808a0fc: .4byte 0x085d9184
lbl_0808a100: .4byte 0x0600e344
lbl_0808a104: .4byte 0x085d9198
lbl_0808a108: .4byte 0x0600e384
lbl_0808a10c: .4byte 0x085d91ac
lbl_0808a110: .4byte 0x0600e3c4
lbl_0808a114: .4byte 0x085d91c0
lbl_0808a118: .4byte 0x0600e404
lbl_0808a11c: .4byte 0x085d91d4
lbl_0808a120: .4byte 0x0600e444
lbl_0808a124: .4byte 0x085d91e8
lbl_0808a128: .4byte 0x0600e484

    thumb_func_start sub_0808a12c
sub_0808a12c: @ 0x0808a12c
    push {lr}
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    movs r0, #0x88
    lsls r0, r0, #7
    cmp r3, r0
    beq lbl_0808a1a8
    cmp r3, r0
    bgt lbl_0808a148
    movs r0, #0x88
    lsls r0, r0, #6
    cmp r3, r0
    beq lbl_0808a1bc
    b lbl_0808a1ca
lbl_0808a148:
    movs r0, #0xaa
    lsls r0, r0, #7
    cmp r3, r0
    beq lbl_0808a18c
    movs r0, #0x88
    lsls r0, r0, #8
    cmp r3, r0
    bne lbl_0808a1ca
    ldr r2, lbl_0808a17c @ =gUnk_30058c0
    ldrh r1, [r2]
    adds r0, r3, #0
    orrs r0, r1
    strh r0, [r2]
    ldr r0, lbl_0808a180 @ =gButtonInput
    ldrh r0, [r0]
    strh r0, [r2, #2]
    ldr r0, lbl_0808a184 @ =gChangedInput
    ldrh r1, [r0]
    ldr r0, lbl_0808a188 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    strh r0, [r2, #6]
    strh r1, [r2, #4]
    b lbl_0808a1ca
    .align 2, 0
lbl_0808a17c: .4byte gUnk_30058c0
lbl_0808a180: .4byte gButtonInput
lbl_0808a184: .4byte gChangedInput
lbl_0808a188: .4byte gLanguage
lbl_0808a18c:
    ldr r1, lbl_0808a1a0 @ =gUnk_30058c0
    ldrh r2, [r1]
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    ldr r0, lbl_0808a1a4 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    b lbl_0808a1c8
    .align 2, 0
lbl_0808a1a0: .4byte gUnk_30058c0
lbl_0808a1a4: .4byte gLanguage
lbl_0808a1a8:
    ldr r1, lbl_0808a1b8 @ =gUnk_30058c0
    ldrh r2, [r1]
    adds r0, r3, #0
    orrs r0, r2
    movs r2, #0
    strh r0, [r1]
    strh r2, [r1, #2]
    b lbl_0808a1ca
    .align 2, 0
lbl_0808a1b8: .4byte gUnk_30058c0
lbl_0808a1bc:
    ldr r1, lbl_0808a1d0 @ =gUnk_30058c0
    ldrh r2, [r1]
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    movs r0, #1
lbl_0808a1c8:
    strh r0, [r1, #2]
lbl_0808a1ca:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a1d0: .4byte gUnk_30058c0

    thumb_func_start sub_0808a1d4
sub_0808a1d4: @ 0x0808a1d4
    push {lr}
    ldr r0, lbl_0808a230 @ =gErrorFlag
    ldr r0, [r0]
    movs r1, #0x80
    lsls r1, r1, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0808a256
    ldr r0, lbl_0808a234 @ =gUnk_30058c4
    ldrh r2, [r0, #2]
    movs r1, #0xaa
    lsls r1, r1, #7
    adds r3, r0, #0
    cmp r2, r1
    bne lbl_0808a20e
    ldr r2, lbl_0808a238 @ =gIoTransferInfo
    ldrh r0, [r3, #6]
    strb r0, [r2, #0x11]
    ldr r1, lbl_0808a23c @ =gLanguage
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    cmp r0, r1
    bne lbl_0808a20e
    movs r0, #0x88
    lsls r0, r0, #7
    strh r0, [r2, #0xe]
lbl_0808a20e:
    ldrh r1, [r3, #2]
    movs r0, #0xcc
    lsls r0, r0, #7
    cmp r1, r0
    bne lbl_0808a248
    ldr r1, lbl_0808a238 @ =gIoTransferInfo
    ldrh r0, [r3, #6]
    strb r0, [r1, #0x10]
    subs r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bhi lbl_0808a240
    movs r0, #0x88
    lsls r0, r0, #6
    strh r0, [r1, #0xe]
    b lbl_0808a248
    .align 2, 0
lbl_0808a230: .4byte gErrorFlag
lbl_0808a234: .4byte gUnk_30058c4
lbl_0808a238: .4byte gIoTransferInfo
lbl_0808a23c: .4byte gLanguage
lbl_0808a240:
    movs r0, #0
    strh r0, [r1, #0xe]
    movs r0, #5
    strb r0, [r1, #0xb]
lbl_0808a248:
    ldrh r1, [r3, #2]
    movs r0, #0xcc
    lsls r0, r0, #6
    cmp r1, r0
    bne lbl_0808a256
    ldr r0, lbl_0808a25c @ =gIoTransferInfo
    strh r1, [r0, #0xe]
lbl_0808a256:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a25c: .4byte gIoTransferInfo

    thumb_func_start sub_0808a260
sub_0808a260: @ 0x0808a260
    push {r4, r5, lr}
    sub sp, #4
    ldr r0, lbl_0808a2a8 @ =gUnk_30058d0
    ldr r2, lbl_0808a2ac @ =0x04000208
    ldrh r4, [r2]
    strh r4, [r0]
    movs r5, #0
    strh r5, [r2]
    ldr r3, lbl_0808a2b0 @ =0x04000200
    ldrh r1, [r3]
    ldr r0, lbl_0808a2b4 @ =0x0000ff3f
    ands r0, r1
    strh r0, [r3]
    strh r4, [r2]
    ldr r1, lbl_0808a2b8 @ =0x04000128
    movs r2, #0x80
    lsls r2, r2, #6
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_0808a2bc @ =0x0400010e
    strh r5, [r0]
    adds r1, #0xda
    movs r0, #0xc0
    strh r0, [r1]
    movs r0, #0
    str r0, [sp]
    ldr r1, lbl_0808a2c0 @ =gCableLinkInfo
    ldr r2, lbl_0808a2c4 @ =0x05000069
    mov r0, sp
    bl CpuSet
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a2a8: .4byte gUnk_30058d0
lbl_0808a2ac: .4byte 0x04000208
lbl_0808a2b0: .4byte 0x04000200
lbl_0808a2b4: .4byte 0x0000ff3f
lbl_0808a2b8: .4byte 0x04000128
lbl_0808a2bc: .4byte 0x0400010e
lbl_0808a2c0: .4byte gCableLinkInfo
lbl_0808a2c4: .4byte 0x05000069

    thumb_func_start sub_0808a2c8
sub_0808a2c8: @ 0x0808a2c8
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r6, lbl_0808a350 @ =gUnk_30058d0
    ldr r3, lbl_0808a354 @ =0x04000208
    ldrh r2, [r3]
    movs r4, #0
    strh r4, [r3]
    ldr r5, lbl_0808a358 @ =0x04000200
    ldrh r1, [r5]
    ldr r0, lbl_0808a35c @ =0x0000ff3f
    ands r0, r1
    strh r0, [r5]
    strh r2, [r3]
    ldr r0, lbl_0808a360 @ =0x04000134
    strh r4, [r0]
    ldr r2, lbl_0808a364 @ =0x04000128
    movs r1, #0x80
    lsls r1, r1, #6
    adds r0, r1, #0
    strh r0, [r2]
    ldrh r0, [r2]
    ldr r7, lbl_0808a368 @ =0x00004003
    adds r1, r7, #0
    orrs r0, r1
    strh r0, [r2]
    ldrh r2, [r3]
    strh r2, [r6]
    strh r4, [r3]
    ldrh r0, [r5]
    movs r1, #0x80
    orrs r0, r1
    strh r0, [r5]
    strh r2, [r3]
    ldr r0, lbl_0808a36c @ =0x0400012a
    strh r4, [r0]
    ldr r2, lbl_0808a370 @ =0x04000120
    movs r0, #0
    movs r1, #0
    str r0, [r2]
    str r1, [r2, #4]
    movs r5, #0
    str r5, [sp]
    ldr r1, lbl_0808a374 @ =gCableLinkInfo
    ldr r2, lbl_0808a378 @ =0x05000069
    mov r0, sp
    bl CpuSet
    ldr r0, lbl_0808a37c @ =gUnk_30058d2
    strb r4, [r0]
    ldr r0, lbl_0808a380 @ =gUnk_30058d3
    strb r4, [r0]
    ldr r0, lbl_0808a384 @ =gUnk_30058d5
    strb r4, [r0]
    ldr r0, lbl_0808a388 @ =gUnk_3005b50
    strb r4, [r0]
    ldr r0, lbl_0808a38c @ =gUnk_3005b54
    strb r4, [r0]
    ldr r0, lbl_0808a390 @ =gUnk_30058d6
    strb r4, [r0]
    ldr r0, lbl_0808a394 @ =gUnk_30058d8
    strh r5, [r0]
    ldr r0, lbl_0808a398 @ =gUnk_30058da
    strh r5, [r0]
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a350: .4byte gUnk_30058d0
lbl_0808a354: .4byte 0x04000208
lbl_0808a358: .4byte 0x04000200
lbl_0808a35c: .4byte 0x0000ff3f
lbl_0808a360: .4byte 0x04000134
lbl_0808a364: .4byte 0x04000128
lbl_0808a368: .4byte 0x00004003
lbl_0808a36c: .4byte 0x0400012a
lbl_0808a370: .4byte 0x04000120
lbl_0808a374: .4byte gCableLinkInfo
lbl_0808a378: .4byte 0x05000069
lbl_0808a37c: .4byte gUnk_30058d2
lbl_0808a380: .4byte gUnk_30058d3
lbl_0808a384: .4byte gUnk_30058d5
lbl_0808a388: .4byte gUnk_3005b50
lbl_0808a38c: .4byte gUnk_3005b54
lbl_0808a390: .4byte gUnk_30058d6
lbl_0808a394: .4byte gUnk_30058d8
lbl_0808a398: .4byte gUnk_30058da

    thumb_func_start sub_0808a39c
sub_0808a39c: @ 0x0808a39c
    push {lr}
    bl sub_0808a2c8
    bl sub_0808a260
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start detect_error
detect_error: @ 0x0808a3ac
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    ldr r0, lbl_0808a3c8 @ =gCableLinkInfo
    ldrb r0, [r0, #1]
    cmp r0, #4
    bhi lbl_0808a45e
    lsls r0, r0, #2
    ldr r1, lbl_0808a3cc @ =lbl_0808a3d0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0808a3c8: .4byte gCableLinkInfo
lbl_0808a3cc: .4byte lbl_0808a3d0
lbl_0808a3d0: @ jump table
    .4byte lbl_0808a3e4 @ case 0
    .4byte lbl_0808a3f4 @ case 1
    .4byte lbl_0808a40c @ case 2
    .4byte lbl_0808a448 @ case 3
    .4byte lbl_0808a452 @ case 4
lbl_0808a3e4:
    bl sub_0808a260
    ldr r1, lbl_0808a3f0 @ =gCableLinkInfo
    movs r0, #1
    strb r0, [r1, #1]
    b lbl_0808a45e
    .align 2, 0
lbl_0808a3f0: .4byte gCableLinkInfo
lbl_0808a3f4:
    ldrb r0, [r4]
    cmp r0, #1
    bne lbl_0808a45e
    bl sub_0808a2c8
    ldr r1, lbl_0808a408 @ =gCableLinkInfo
    movs r0, #2
    strb r0, [r1, #1]
    b lbl_0808a45e
    .align 2, 0
lbl_0808a408: .4byte gCableLinkInfo
lbl_0808a40c:
    ldrb r1, [r4]
    cmp r1, #1
    beq lbl_0808a41c
    cmp r1, #2
    beq lbl_0808a434
    bl sub_0808a4cc
    b lbl_0808a45e
lbl_0808a41c:
    ldr r2, lbl_0808a430 @ =gCableLinkInfo
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_0808a45e
    ldrb r0, [r2, #3]
    cmp r0, #1
    bls lbl_0808a45e
    strb r1, [r2, #0x10]
    b lbl_0808a45e
    .align 2, 0
lbl_0808a430: .4byte gCableLinkInfo
lbl_0808a434:
    ldr r0, lbl_0808a440 @ =gCableLinkInfo
    movs r1, #0
    strb r1, [r0, #1]
    ldr r0, lbl_0808a444 @ =0x0400012a
    strh r1, [r0]
    b lbl_0808a45e
    .align 2, 0
lbl_0808a440: .4byte gCableLinkInfo
lbl_0808a444: .4byte 0x0400012a
lbl_0808a448:
    bl sub_0808a4f8
    ldr r1, lbl_0808a4a0 @ =gCableLinkInfo
    movs r0, #4
    strb r0, [r1, #1]
lbl_0808a452:
    adds r0, r5, #0
    bl sub_0808a548
    adds r0, r6, #0
    bl sub_0808a628
lbl_0808a45e:
    movs r0, #0
    strb r0, [r4]
    ldr r1, lbl_0808a4a0 @ =gCableLinkInfo
    ldrb r2, [r1, #2]
    ldrb r0, [r1, #3]
    lsls r0, r0, #2
    orrs r2, r0
    ldrb r0, [r1]
    cmp r0, #8
    bne lbl_0808a476
    movs r0, #0x20
    orrs r2, r0
lbl_0808a476:
    ldrb r0, [r1, #0xc]
    lsls r3, r0, #8
    ldrb r0, [r1, #0x11]
    lsls r4, r0, #9
    ldrb r0, [r1, #0x12]
    lsls r5, r0, #0x10
    ldrb r0, [r1, #0x13]
    lsls r6, r0, #0x11
    ldrb r0, [r1, #0x14]
    lsls r7, r0, #0x12
    ldrb r0, [r1, #0x15]
    lsls r0, r0, #0x14
    mov ip, r0
    ldrb r0, [r1, #1]
    cmp r0, #4
    bne lbl_0808a4a4
    movs r0, #0x40
    orrs r0, r3
    orrs r0, r2
    b lbl_0808a4a8
    .align 2, 0
lbl_0808a4a0: .4byte gCableLinkInfo
lbl_0808a4a4:
    adds r0, r2, #0
    orrs r0, r3
lbl_0808a4a8:
    orrs r0, r4
    orrs r0, r5
    orrs r0, r6
    orrs r0, r7
    mov r2, ip
    orrs r0, r2
    adds r2, r0, #0
    ldrb r0, [r1, #2]
    cmp r0, #1
    bls lbl_0808a4c2
    movs r0, #0x80
    lsls r0, r0, #0xf
    orrs r2, r0
lbl_0808a4c2:
    adds r0, r2, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0808a4cc
sub_0808a4cc: @ 0x0808a4cc
    push {lr}
    ldr r0, lbl_0808a4e8 @ =0x04000128
    ldr r1, [r0]
    movs r0, #0xc
    ands r1, r0
    ldr r2, lbl_0808a4ec @ =gCableLinkInfo
    cmp r1, #8
    bne lbl_0808a4f0
    ldrb r0, [r2, #2]
    cmp r0, #0
    bne lbl_0808a4f0
    strb r1, [r2]
    b lbl_0808a4f4
    .align 2, 0
lbl_0808a4e8: .4byte 0x04000128
lbl_0808a4ec: .4byte gCableLinkInfo
lbl_0808a4f0:
    movs r0, #0
    strb r0, [r2]
lbl_0808a4f4:
    pop {r0}
    bx r0

    thumb_func_start sub_0808a4f8
sub_0808a4f8: @ 0x0808a4f8
    push {r4, lr}
    ldr r0, lbl_0808a530 @ =gCableLinkInfo
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0808a528
    ldr r1, lbl_0808a534 @ =0x0400010c
    ldr r2, lbl_0808a538 @ =0x0000ff7c
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    movs r0, #0x41
    strh r0, [r1]
    ldr r0, lbl_0808a53c @ =gUnk_30058d0
    ldr r2, lbl_0808a540 @ =0x04000208
    ldrh r4, [r2]
    strh r4, [r0]
    movs r0, #0
    strh r0, [r2]
    ldr r3, lbl_0808a544 @ =0x04000200
    ldrh r0, [r3]
    movs r1, #0x40
    orrs r0, r1
    strh r0, [r3]
    strh r4, [r2]
lbl_0808a528:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a530: .4byte gCableLinkInfo
lbl_0808a534: .4byte 0x0400010c
lbl_0808a538: .4byte 0x0000ff7c
lbl_0808a53c: .4byte gUnk_30058d0
lbl_0808a540: .4byte 0x04000208
lbl_0808a544: .4byte 0x04000200

    thumb_func_start sub_0808a548
sub_0808a548: @ 0x0808a548
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    adds r4, r0, #0
    ldr r2, lbl_0808a5bc @ =gUnk_30058d0
    ldr r1, lbl_0808a5c0 @ =0x04000208
    ldrh r0, [r1]
    strh r0, [r2]
    movs r0, #0
    strh r0, [r1]
    ldr r1, lbl_0808a5c4 @ =gCableLinkInfo
    adds r0, r1, #0
    adds r0, #0x9d
    ldrb r3, [r0]
    mov sl, r2
    mov ip, r1
    cmp r3, #0x1f
    bhi lbl_0808a5d0
    mov r0, ip
    adds r0, #0x9c
    ldrb r0, [r0]
    adds r0, r3, r0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x1f
    bls lbl_0808a586
    subs r0, #0x20
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
lbl_0808a586:
    movs r3, #0
    ldr r1, lbl_0808a5c8 @ =gUnk_30058d8
    mov r8, r1
    ldr r2, lbl_0808a5cc @ =gUnk_3005b50
    mov sb, r2
    mov r2, r8
    lsls r5, r0, #1
    mov r7, ip
    adds r7, #0x1c
    movs r6, #0
lbl_0808a59a:
    ldrh r0, [r2]
    ldrh r1, [r4]
    orrs r0, r1
    strh r0, [r2]
    lsls r0, r3, #6
    adds r0, r5, r0
    adds r0, r0, r7
    strh r1, [r0]
    strh r6, [r4]
    adds r4, #2
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #1
    bls lbl_0808a59a
    b lbl_0808a5e4
    .align 2, 0
lbl_0808a5bc: .4byte gUnk_30058d0
lbl_0808a5c0: .4byte 0x04000208
lbl_0808a5c4: .4byte gCableLinkInfo
lbl_0808a5c8: .4byte gUnk_30058d8
lbl_0808a5cc: .4byte gUnk_3005b50
lbl_0808a5d0:
    mov r0, ip
    ldrb r1, [r0, #0x14]
    movs r0, #1
    orrs r0, r1
    mov r1, ip
    strb r0, [r1, #0x14]
    ldr r2, lbl_0808a61c @ =gUnk_30058d8
    mov r8, r2
    ldr r0, lbl_0808a620 @ =gUnk_3005b50
    mov sb, r0
lbl_0808a5e4:
    mov r1, r8
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_0808a5fc
    mov r3, ip
    adds r3, #0x9d
    ldrb r0, [r3]
    adds r0, #1
    movs r1, #0
    strb r0, [r3]
    mov r2, r8
    strh r1, [r2]
lbl_0808a5fc:
    ldr r1, lbl_0808a624 @ =0x04000208
    mov r2, sl
    ldrh r0, [r2]
    strh r0, [r1]
    mov r0, ip
    adds r0, #0x9d
    ldrb r0, [r0]
    mov r1, sb
    strb r0, [r1]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a61c: .4byte gUnk_30058d8
lbl_0808a620: .4byte gUnk_3005b50
lbl_0808a624: .4byte 0x04000208

    thumb_func_start sub_0808a628
sub_0808a628: @ 0x0808a628
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    mov ip, r0
    ldr r2, lbl_0808a68c @ =gUnk_30058d0
    ldr r1, lbl_0808a690 @ =0x04000208
    ldrh r0, [r1]
    strh r0, [r2]
    movs r0, #0
    strh r0, [r1]
    ldr r0, lbl_0808a694 @ =gCableLinkInfo
    ldr r3, lbl_0808a698 @ =0x000001a1
    adds r1, r0, r3
    ldrb r1, [r1]
    mov sl, r2
    mov sb, r0
    cmp r1, #0
    bne lbl_0808a69c
    movs r1, #0
    mov r7, sb
    mov r4, sb
    ldrb r5, [r4, #3]
lbl_0808a658:
    movs r3, #0
    adds r6, r1, #1
    cmp r3, r5
    bhs lbl_0808a67a
    lsls r0, r1, #2
    mov r2, ip
    adds r1, r0, r2
    movs r4, #0
    ldrb r2, [r7, #3]
lbl_0808a66a:
    lsls r0, r3, #1
    adds r0, r0, r1
    strh r4, [r0]
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, r2
    blo lbl_0808a66a
lbl_0808a67a:
    lsls r0, r6, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #1
    bls lbl_0808a658
    movs r0, #1
    mov r3, sb
    strb r0, [r3, #0xc]
    b lbl_0808a70e
    .align 2, 0
lbl_0808a68c: .4byte gUnk_30058d0
lbl_0808a690: .4byte 0x04000208
lbl_0808a694: .4byte gCableLinkInfo
lbl_0808a698: .4byte 0x000001a1
lbl_0808a69c:
    movs r1, #0
    mov r4, sb
    ldrb r4, [r4, #3]
    mov r8, r4
lbl_0808a6a4:
    movs r3, #0
    adds r6, r1, #1
    cmp r3, r8
    bhs lbl_0808a6de
    lsls r0, r1, #2
    mov r2, ip
    adds r7, r0, r2
    ldr r2, lbl_0808a724 @ =gCableLinkInfo
    movs r4, #0xd0
    lsls r4, r4, #1
    adds r0, r2, r4
    ldrb r0, [r0]
    lsls r0, r0, #1
    lsls r1, r1, #6
    adds r5, r0, r1
    ldrb r4, [r2, #3]
    adds r2, #0xa0
lbl_0808a6c6:
    lsls r1, r3, #1
    adds r1, r1, r7
    lsls r0, r3, #7
    adds r0, r5, r0
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r1]
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, r4
    blo lbl_0808a6c6
lbl_0808a6de:
    lsls r0, r6, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #1
    bls lbl_0808a6a4
    mov r2, sb
    ldr r0, lbl_0808a728 @ =0x000001a1
    adds r1, r2, r0
    ldrb r0, [r1]
    subs r0, #1
    movs r3, #0
    strb r0, [r1]
    movs r4, #0xd0
    lsls r4, r4, #1
    adds r1, r2, r4
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x1f
    bls lbl_0808a70a
    strb r3, [r1]
lbl_0808a70a:
    mov r0, sb
    strb r3, [r0, #0xc]
lbl_0808a70e:
    ldr r1, lbl_0808a72c @ =0x04000208
    mov r2, sl
    ldrh r0, [r2]
    strh r0, [r1]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a724: .4byte gCableLinkInfo
lbl_0808a728: .4byte 0x000001a1
lbl_0808a72c: .4byte 0x04000208

    thumb_func_start unk_8a730
unk_8a730: @ 0x0808a730
    push {r4, lr}
    ldr r4, lbl_0808a758 @ =gCableLinkInfo
    ldrb r3, [r4]
    cmp r3, #0
    beq lbl_0808a76a
    ldrb r0, [r4, #1]
    cmp r0, #2
    beq lbl_0808a764
    cmp r0, #4
    bne lbl_0808a796
    ldrb r0, [r4, #0xd]
    cmp r0, #2
    bhi lbl_0808a75c
    ldrb r0, [r4, #0x12]
    cmp r0, #0
    bne lbl_0808a764
    movs r0, #1
    strb r0, [r4, #0x15]
    b lbl_0808a796
    .align 2, 0
lbl_0808a758: .4byte gCableLinkInfo
lbl_0808a75c:
    ldrb r0, [r4, #0x15]
    cmp r0, #0
    bne lbl_0808a796
    strb r0, [r4, #0xd]
lbl_0808a764:
    bl set_siocnt_start_bit_active_duplicate
    b lbl_0808a796
lbl_0808a76a:
    ldrb r2, [r4, #1]
    cmp r2, #4
    beq lbl_0808a774
    cmp r2, #2
    bne lbl_0808a796
lbl_0808a774:
    ldr r1, lbl_0808a79c @ =gUnk_30058d2
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xa
    bls lbl_0808a796
    cmp r2, #4
    bne lbl_0808a78c
    movs r0, #2
    strb r0, [r4, #0x15]
lbl_0808a78c:
    cmp r2, #2
    bne lbl_0808a796
    strb r3, [r4, #2]
    strb r3, [r4, #3]
    strb r3, [r4, #0x11]
lbl_0808a796:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a79c: .4byte gUnk_30058d2

    thumb_func_start sub_0808a7a0
sub_0808a7a0: @ 0x0808a7a0
    push {lr}
    bl sub_0808aaf0
    bl set_siocnt_start_bit_active_duplicate
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0808a7b0
sub_0808a7b0: @ 0x0808a7b0
    push {r4, r5, lr}
    ldr r0, lbl_0808a7e4 @ =0x04000128
    ldr r1, [r0]
    ldr r5, lbl_0808a7e8 @ =gCableLinkInfo
    lsls r0, r1, #0x1a
    lsrs r0, r0, #0x1e
    strb r0, [r5, #2]
    ldrb r4, [r5, #1]
    cmp r4, #2
    beq lbl_0808a7ec
    cmp r4, #4
    bne lbl_0808a808
    movs r0, #0x40
    ands r1, r0
    cmp r1, #0
    beq lbl_0808a7d4
    movs r0, #1
    strb r0, [r5, #0x12]
lbl_0808a7d4:
    bl sub_0808a94c
    bl sub_0808aa54
    bl sub_0808ab24
    b lbl_0808a808
    .align 2, 0
lbl_0808a7e4: .4byte 0x04000128
lbl_0808a7e8: .4byte gCableLinkInfo
lbl_0808a7ec:
    bl sub_0808a850
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0808a808
    ldrb r0, [r5]
    cmp r0, #0
    beq lbl_0808a804
    movs r0, #3
    strb r0, [r5, #1]
    strb r4, [r5, #0xd]
    b lbl_0808a808
lbl_0808a804:
    movs r0, #4
    strb r0, [r5, #1]
lbl_0808a808:
    ldr r3, lbl_0808a830 @ =gCableLinkInfo
    ldrb r0, [r3, #0xd]
    adds r0, #1
    movs r2, #0
    strb r0, [r3, #0xd]
    ldr r1, lbl_0808a834 @ =gUnk_30058d2
    strb r2, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_0808a828
    ldr r1, lbl_0808a838 @ =gUnk_3005b54
    ldr r2, lbl_0808a83c @ =0x000001a1
    adds r0, r3, r2
    ldrb r0, [r0]
    strb r0, [r1]
lbl_0808a828:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a830: .4byte gCableLinkInfo
lbl_0808a834: .4byte gUnk_30058d2
lbl_0808a838: .4byte gUnk_3005b54
lbl_0808a83c: .4byte 0x000001a1

    thumb_func_start set_siocnt_start_bit_active_duplicate
set_siocnt_start_bit_active_duplicate: @ 0x0808a840
    ldr r0, lbl_0808a84c @ =0x04000128
    ldrh r1, [r0]
    movs r2, #0x80
    orrs r1, r2
    strh r1, [r0]
    bx lr
    .align 2, 0
lbl_0808a84c: .4byte 0x04000128

    thumb_func_start sub_0808a850
sub_0808a850: @ 0x0808a850
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    movs r7, #0
    ldr r5, lbl_0808a86c @ =0x0000ffff
    ldr r0, lbl_0808a870 @ =gCableLinkInfo
    ldrb r1, [r0, #0x10]
    adds r4, r0, #0
    cmp r1, #1
    bne lbl_0808a880
    ldr r1, lbl_0808a874 @ =0x0400012a
    ldr r2, lbl_0808a878 @ =0x00008fff
    b lbl_0808a884
    .align 2, 0
lbl_0808a86c: .4byte 0x0000ffff
lbl_0808a870: .4byte gCableLinkInfo
lbl_0808a874: .4byte 0x0400012a
lbl_0808a878: .4byte 0x00008fff
lbl_0808a87c:
    movs r7, #0
    b lbl_0808a902
lbl_0808a880:
    ldr r1, lbl_0808a8d4 @ =0x0400012a
    ldr r2, lbl_0808a8d8 @ =0x00007c40
lbl_0808a884:
    adds r0, r2, #0
    strh r0, [r1]
    movs r0, #0
    strb r0, [r4, #0x10]
    ldr r0, lbl_0808a8dc @ =0x04000120
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r4, #4]
    str r1, [r4, #8]
    movs r3, #0
    ldr r0, lbl_0808a8e0 @ =gUnk_30058d5
    mov sb, r0
    adds r6, r4, #0
    ldr r1, lbl_0808a8e4 @ =0x00008fff
    mov r8, r1
    ldr r2, lbl_0808a8e8 @ =0x0000ffff
    mov ip, r2
lbl_0808a8a6:
    lsls r0, r3, #1
    adds r1, r6, #4
    adds r0, r0, r1
    ldrh r2, [r0]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    ldr r1, lbl_0808a8d8 @ =0x00007c40
    cmp r0, r1
    beq lbl_0808a8c0
    adds r0, r2, #0
    cmp r0, r8
    bne lbl_0808a8ec
lbl_0808a8c0:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    adds r0, r2, #0
    cmp r5, r0
    bls lbl_0808a8f8
    cmp r0, #0
    beq lbl_0808a8f8
    adds r5, r2, #0
    b lbl_0808a8f8
    .align 2, 0
lbl_0808a8d4: .4byte 0x0400012a
lbl_0808a8d8: .4byte 0x00007c40
lbl_0808a8dc: .4byte 0x04000120
lbl_0808a8e0: .4byte gUnk_30058d5
lbl_0808a8e4: .4byte 0x00008fff
lbl_0808a8e8: .4byte 0x0000ffff
lbl_0808a8ec:
    cmp r0, ip
    bne lbl_0808a87c
    ldrb r0, [r6, #2]
    cmp r3, r0
    bne lbl_0808a8f8
    movs r7, #0
lbl_0808a8f8:
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #1
    bls lbl_0808a8a6
lbl_0808a902:
    strb r7, [r4, #3]
    adds r0, r7, #0
    cmp r0, #1
    bls lbl_0808a932
    mov r1, sb
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_0808a924
    ldrh r1, [r4, #4]
    ldr r0, lbl_0808a920 @ =0x00008fff
    cmp r1, r0
    bne lbl_0808a924
    movs r0, #1
    b lbl_0808a93e
    .align 2, 0
lbl_0808a920: .4byte 0x00008fff
lbl_0808a924:
    ldrb r0, [r4, #3]
    cmp r0, #1
    bls lbl_0808a932
    movs r0, #3
    ands r5, r0
    adds r0, r5, #1
    b lbl_0808a934
lbl_0808a932:
    movs r0, #0
lbl_0808a934:
    strb r0, [r4, #0x11]
    ldrb r0, [r4, #3]
    mov r2, sb
    strb r0, [r2]
    movs r0, #0
lbl_0808a93e:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0808a94c
sub_0808a94c: @ 0x0808a94c
    push {r4, r5, r6, r7, lr}
    sub sp, #8
    ldr r0, lbl_0808a9a0 @ =0x04000120
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [sp]
    str r1, [sp, #4]
    ldr r0, lbl_0808a9a4 @ =gCableLinkInfo
    ldrb r1, [r0, #0x18]
    adds r5, r0, #0
    cmp r1, #0
    bne lbl_0808a9ac
    movs r3, #0
    ldr r7, lbl_0808a9a8 @ =gUnk_30058d6
    ldrb r0, [r5, #3]
    cmp r3, r0
    bhs lbl_0808a996
    adds r6, r5, #0
    ldrh r1, [r5, #0x16]
    adds r4, r7, #0
    adds r2, r5, #0
lbl_0808a976:
    lsls r0, r3, #1
    add r0, sp
    ldrh r0, [r0]
    cmp r1, r0
    beq lbl_0808a98a
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_0808a98a
    movs r0, #1
    strb r0, [r6, #0x13]
lbl_0808a98a:
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    ldrb r0, [r2, #3]
    cmp r3, r0
    blo lbl_0808a976
lbl_0808a996:
    movs r0, #0
    strh r0, [r5, #0x16]
    movs r0, #1
    strb r0, [r7]
    b lbl_0808aa44
    .align 2, 0
lbl_0808a9a0: .4byte 0x04000120
lbl_0808a9a4: .4byte gCableLinkInfo
lbl_0808a9a8: .4byte gUnk_30058d6
lbl_0808a9ac:
    movs r1, #0xd0
    lsls r1, r1, #1
    adds r0, r5, r1
    ldr r2, lbl_0808aa10 @ =0x000001a1
    adds r1, r5, r2
    ldrb r1, [r1]
    ldrb r0, [r0]
    adds r0, r1, r0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x1f
    bls lbl_0808a9ca
    subs r0, #0x20
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
lbl_0808a9ca:
    cmp r1, #0x1f
    bhi lbl_0808aa18
    movs r3, #0
    ldrb r1, [r5, #3]
    cmp r3, r1
    bhs lbl_0808aa20
    adds r4, r5, #0
    ldr r6, lbl_0808aa14 @ =gUnk_30058da
    lsls r7, r0, #1
    movs r2, #0xa0
    adds r2, r2, r5
    mov ip, r2
lbl_0808a9e2:
    lsls r0, r3, #1
    add r0, sp
    ldrh r2, [r0]
    ldrh r1, [r4, #0x16]
    adds r0, r2, r1
    strh r0, [r4, #0x16]
    ldrh r0, [r6]
    orrs r0, r2
    strh r0, [r6]
    ldrb r0, [r4, #0x19]
    lsls r0, r0, #6
    adds r0, r7, r0
    lsls r1, r3, #7
    adds r0, r0, r1
    add r0, ip
    strh r2, [r0]
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    ldrb r2, [r4, #3]
    cmp r3, r2
    blo lbl_0808a9e2
    b lbl_0808aa20
    .align 2, 0
lbl_0808aa10: .4byte 0x000001a1
lbl_0808aa14: .4byte gUnk_30058da
lbl_0808aa18:
    ldrb r1, [r5, #0x14]
    movs r0, #2
    orrs r0, r1
    strb r0, [r5, #0x14]
lbl_0808aa20:
    ldrb r0, [r5, #0x19]
    adds r0, #1
    strb r0, [r5, #0x19]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_0808aa44
    ldr r2, lbl_0808aa4c @ =gUnk_30058da
    ldrh r0, [r2]
    cmp r0, #0
    beq lbl_0808aa44
    ldr r0, lbl_0808aa50 @ =0x000001a1
    adds r1, r5, r0
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    movs r0, #0
    strh r0, [r2]
lbl_0808aa44:
    add sp, #8
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808aa4c: .4byte gUnk_30058da
lbl_0808aa50: .4byte 0x000001a1

    thumb_func_start sub_0808aa54
sub_0808aa54: @ 0x0808aa54
    push {lr}
    ldr r0, lbl_0808aa8c @ =gCableLinkInfo
    ldrb r1, [r0, #0x18]
    adds r3, r0, #0
    cmp r1, #2
    bne lbl_0808aa9e
    ldr r1, lbl_0808aa90 @ =0x0400012a
    ldrh r0, [r3, #0x16]
    strh r0, [r1]
    ldr r1, lbl_0808aa94 @ =gUnk_30058d3
    ldrb r2, [r1]
    cmp r2, #0
    bne lbl_0808aa98
    adds r1, r3, #0
    adds r1, #0x9d
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    subs r1, #1
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x1f
    bls lbl_0808aae8
    strb r2, [r1]
    b lbl_0808aae8
    .align 2, 0
lbl_0808aa8c: .4byte gCableLinkInfo
lbl_0808aa90: .4byte 0x0400012a
lbl_0808aa94: .4byte gUnk_30058d3
lbl_0808aa98:
    movs r0, #0
    strb r0, [r1]
    b lbl_0808aae8
lbl_0808aa9e:
    ldr r2, lbl_0808aac0 @ =gUnk_30058d3
    cmp r1, #0
    bne lbl_0808aab2
    adds r0, r3, #0
    adds r0, #0x9d
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0808aab2
    movs r0, #1
    strb r0, [r2]
lbl_0808aab2:
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_0808aac8
    ldr r1, lbl_0808aac4 @ =0x0400012a
    movs r0, #0
    strh r0, [r1]
    b lbl_0808aae2
    .align 2, 0
lbl_0808aac0: .4byte gUnk_30058d3
lbl_0808aac4: .4byte 0x0400012a
lbl_0808aac8:
    ldr r2, lbl_0808aaec @ =0x0400012a
    adds r0, r3, #0
    adds r0, #0x9c
    ldrb r1, [r0]
    lsls r1, r1, #1
    ldrb r0, [r3, #0x18]
    lsls r0, r0, #6
    adds r1, r1, r0
    adds r0, r3, #0
    adds r0, #0x1c
    adds r1, r1, r0
    ldrh r0, [r1]
    strh r0, [r2]
lbl_0808aae2:
    ldrb r0, [r3, #0x18]
    adds r0, #1
    strb r0, [r3, #0x18]
lbl_0808aae8:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808aaec: .4byte 0x0400012a

    thumb_func_start sub_0808aaf0
sub_0808aaf0: @ 0x0808aaf0
    push {lr}
    ldr r0, lbl_0808ab10 @ =gCableLinkInfo
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0808ab0c
    ldr r2, lbl_0808ab14 @ =0x0400010e
    ldrh r1, [r2]
    ldr r0, lbl_0808ab18 @ =0x0000ff7f
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_0808ab1c @ =0x0400010c
    ldr r2, lbl_0808ab20 @ =0x0000ff7c
    adds r0, r2, #0
    strh r0, [r1]
lbl_0808ab0c:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808ab10: .4byte gCableLinkInfo
lbl_0808ab14: .4byte 0x0400010e
lbl_0808ab18: .4byte 0x0000ff7f
lbl_0808ab1c: .4byte 0x0400010c
lbl_0808ab20: .4byte 0x0000ff7c

    thumb_func_start sub_0808ab24
sub_0808ab24: @ 0x0808ab24
    push {lr}
    ldr r1, lbl_0808ab38 @ =gCableLinkInfo
    ldrb r0, [r1, #0x19]
    cmp r0, #2
    bne lbl_0808ab3c
    movs r0, #0
    strb r0, [r1, #0x18]
    strb r0, [r1, #0x19]
    b lbl_0808ab4c
    .align 2, 0
lbl_0808ab38: .4byte gCableLinkInfo
lbl_0808ab3c:
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0808ab4c
    ldr r0, lbl_0808ab50 @ =0x0400010e
    ldrh r1, [r0]
    movs r2, #0x80
    orrs r1, r2
    strh r1, [r0]
lbl_0808ab4c:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808ab50: .4byte 0x0400010e

    thumb_func_start sub_0808ab54
sub_0808ab54: @ 0x0808ab54
    push {r4, r5, lr}
    ldr r2, lbl_0808ab94 @ =gCableLinkInfo
    adds r0, r2, #0
    adds r0, #0x9d
    movs r1, #0
    strb r1, [r0]
    subs r0, #1
    strb r1, [r0]
    movs r0, #0
    adds r5, r2, #0
    adds r5, #0x1c
    ldr r4, lbl_0808ab98 @ =0x0000efff
lbl_0808ab6c:
    movs r1, #0
    adds r3, r0, #1
    lsls r2, r0, #6
lbl_0808ab72:
    lsls r0, r1, #1
    adds r0, r0, r2
    adds r0, r0, r5
    strh r4, [r0]
    adds r0, r1, #1
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0x1f
    bls lbl_0808ab72
    lsls r0, r3, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bls lbl_0808ab6c
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808ab94: .4byte gCableLinkInfo
lbl_0808ab98: .4byte 0x0000efff

    thumb_func_start sub_0808ab9c
sub_0808ab9c: @ 0x0808ab9c
    push {r4, r5, r6, r7, lr}
    ldr r2, lbl_0808abec @ =gCableLinkInfo
    ldr r1, lbl_0808abf0 @ =0x000001a1
    adds r0, r2, r1
    movs r1, #0
    strb r1, [r0]
    movs r3, #0xd0
    lsls r3, r3, #1
    adds r0, r2, r3
    strb r1, [r0]
    adds r7, r2, #0
    adds r7, #0xa0
    ldr r6, lbl_0808abf4 @ =0x0000efff
lbl_0808abb6:
    movs r0, #0
    adds r5, r1, #1
    lsls r4, r1, #7
lbl_0808abbc:
    movs r1, #0
    adds r3, r0, #1
    lsls r2, r0, #6
lbl_0808abc2:
    lsls r0, r1, #1
    adds r0, r0, r2
    adds r0, r0, r4
    adds r0, r0, r7
    strh r6, [r0]
    adds r0, r1, #1
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0x1f
    bls lbl_0808abc2
    lsls r0, r3, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bls lbl_0808abbc
    lsls r0, r5, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #1
    bls lbl_0808abb6
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808abec: .4byte gCableLinkInfo
lbl_0808abf0: .4byte 0x000001a1
lbl_0808abf4: .4byte 0x0000efff
