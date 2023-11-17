    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start vblank_code_during_intro
vblank_code_during_intro: @ 0x08081248
    push {lr}
    ldr r1, lbl_080812e4 @ =0x040000d4
    ldr r0, lbl_080812e8 @ =gOamData
    str r0, [r1]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_080812ec @ =0x84000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r2, #0x80
    lsls r2, r2, #0x13
    ldr r0, lbl_080812f0 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0xc0
    ldrh r0, [r0]
    strh r0, [r2]
    adds r2, #0x50
    adds r1, #0xc2
    ldrh r0, [r1]
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_080812f4 @ =gIoRegistersBackup
    ldrb r1, [r0, #5]
    lsls r1, r1, #8
    ldrb r0, [r0, #4]
    orrs r0, r1
    strh r0, [r2]
    ldr r1, lbl_080812f8 @ =0x04000054
    ldr r0, lbl_080812fc @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r0]
    strh r0, [r1]
    subs r1, #0x44
    ldr r0, lbl_08081300 @ =gBg0XPosition
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_08081304 @ =gBg0YPosition
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_08081308 @ =gBg1XPosition
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_0808130c @ =gBg1YPosition
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_08081310 @ =gBg2XPosition
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_08081314 @ =gBg2YPosition
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_08081318 @ =gBg3XPosition
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_0808131c @ =gBg3YPosition
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1]
    bl AnimatedGraphicsTransfer
    pop {r0}
    bx r0
    .align 2, 0
lbl_080812e4: .4byte 0x040000d4
lbl_080812e8: .4byte gOamData
lbl_080812ec: .4byte 0x84000100
lbl_080812f0: .4byte sNonGameplayRamPointer
lbl_080812f4: .4byte gIoRegistersBackup
lbl_080812f8: .4byte 0x04000054
lbl_080812fc: .4byte gWrittenToBLDY_NonGameplay
lbl_08081300: .4byte gBg0XPosition
lbl_08081304: .4byte gBg0YPosition
lbl_08081308: .4byte gBg1XPosition
lbl_0808130c: .4byte gBg1YPosition
lbl_08081310: .4byte gBg2XPosition
lbl_08081314: .4byte gBg2YPosition
lbl_08081318: .4byte gBg3XPosition
lbl_0808131c: .4byte gBg3YPosition

    thumb_func_start sub_08081320
sub_08081320: @ 0x08081320
    ldr r1, lbl_080813c8 @ =0x040000d4
    ldr r0, lbl_080813cc @ =gOamData
    str r0, [r1]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_080813d0 @ =0x84000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    subs r1, #0xd4
    ldr r0, lbl_080813d4 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    mov ip, r0
    adds r0, #0xc0
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #0x50
    mov r0, ip
    adds r0, #0xc2
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r2, lbl_080813d8 @ =0x04000052
    ldr r0, lbl_080813dc @ =gWrittenToBLDALPHA_H
    ldrh r0, [r0]
    lsls r0, r0, #8
    ldr r1, lbl_080813e0 @ =gWrittenToBLDALPHA_L
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r2]
    ldr r1, lbl_080813e4 @ =0x04000054
    ldr r0, lbl_080813e8 @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r3, lbl_080813ec @ =0x04000010
    ldr r0, lbl_080813f0 @ =gBg0XPosition
    ldrh r2, [r0]
    ldr r1, lbl_080813f4 @ =0x000001ff
    adds r0, r1, #0
    ands r0, r2
    strh r0, [r3]
    ldr r2, lbl_080813f8 @ =0x04000012
    ldr r0, lbl_080813fc @ =gBg0YPosition
    ldrb r0, [r0]
    strh r0, [r2]
    adds r3, #4
    ldr r0, lbl_08081400 @ =gBg1XPosition
    ldrh r2, [r0]
    adds r0, r1, #0
    ands r0, r2
    strh r0, [r3]
    ldr r2, lbl_08081404 @ =0x04000016
    ldr r0, lbl_08081408 @ =gBg1YPosition
    ldrb r0, [r0]
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0808140c @ =gBg2XPosition
    ldrh r0, [r0]
    ands r1, r0
    strh r1, [r2]
    ldr r1, lbl_08081410 @ =0x0400001a
    ldr r0, lbl_08081414 @ =gBg2YPosition
    ldrb r0, [r0]
    strh r0, [r1]
    adds r2, #0x28
    mov r0, ip
    adds r0, #0xc4
    ldrh r0, [r0]
    lsls r0, r0, #8
    mov r1, ip
    adds r1, #0xc6
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r2]
    adds r2, #4
    mov r0, ip
    adds r0, #0xc8
    ldrh r0, [r0]
    lsls r0, r0, #8
    mov r1, ip
    adds r1, #0xca
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r2]
    bx lr
    .align 2, 0
lbl_080813c8: .4byte 0x040000d4
lbl_080813cc: .4byte gOamData
lbl_080813d0: .4byte 0x84000100
lbl_080813d4: .4byte sNonGameplayRamPointer
lbl_080813d8: .4byte 0x04000052
lbl_080813dc: .4byte gWrittenToBLDALPHA_H
lbl_080813e0: .4byte gWrittenToBLDALPHA_L
lbl_080813e4: .4byte 0x04000054
lbl_080813e8: .4byte gWrittenToBLDY_NonGameplay
lbl_080813ec: .4byte 0x04000010
lbl_080813f0: .4byte gBg0XPosition
lbl_080813f4: .4byte 0x000001ff
lbl_080813f8: .4byte 0x04000012
lbl_080813fc: .4byte gBg0YPosition
lbl_08081400: .4byte gBg1XPosition
lbl_08081404: .4byte 0x04000016
lbl_08081408: .4byte gBg1YPosition
lbl_0808140c: .4byte gBg2XPosition
lbl_08081410: .4byte 0x0400001a
lbl_08081414: .4byte gBg2YPosition

    thumb_func_start sub_08081418
sub_08081418: @ 0x08081418
    movs r2, #0x80
    lsls r2, r2, #0x13
    ldr r0, lbl_080814c0 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0xc0
    ldrh r0, [r0]
    strh r0, [r2]
    adds r2, #0x50
    adds r1, #0xc2
    ldrh r0, [r1]
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_080814c4 @ =gWrittenToBLDALPHA_H
    ldrh r0, [r0]
    lsls r0, r0, #8
    ldr r1, lbl_080814c8 @ =gWrittenToBLDALPHA_L
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r2]
    ldr r1, lbl_080814cc @ =0x04000020
    ldr r0, lbl_080814d0 @ =gWrittenToBG2PA
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_080814d4 @ =gWrittenToBG2PB
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_080814d8 @ =gWrittenToBG2PC
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_080814dc @ =gWrittenToBG2PD
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_080814e0 @ =gWrittenToBG2X
    ldr r0, [r0]
    strh r0, [r1]
    adds r1, #2
    ldr r2, lbl_080814e4 @ =0x0fff0000
    ands r0, r2
    asrs r0, r0, #0x10
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_080814e8 @ =gWrittenToBG2Y
    ldr r0, [r0]
    strh r0, [r1]
    adds r1, #2
    ands r0, r2
    asrs r0, r0, #0x10
    strh r0, [r1]
    ldr r3, lbl_080814ec @ =0x04000010
    ldr r0, lbl_080814f0 @ =gBg0XPosition
    ldrh r2, [r0]
    ldr r1, lbl_080814f4 @ =0x000001ff
    adds r0, r1, #0
    ands r0, r2
    strh r0, [r3]
    ldr r2, lbl_080814f8 @ =0x04000012
    ldr r0, lbl_080814fc @ =gBg0YPosition
    ldrb r0, [r0]
    strh r0, [r2]
    adds r3, #4
    ldr r0, lbl_08081500 @ =gBg1XPosition
    ldrh r2, [r0]
    adds r0, r1, #0
    ands r0, r2
    strh r0, [r3]
    ldr r2, lbl_08081504 @ =0x04000016
    ldr r0, lbl_08081508 @ =gBg1YPosition
    ldrb r0, [r0]
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0808150c @ =gBg2XPosition
    ldrh r0, [r0]
    ands r1, r0
    strh r1, [r2]
    ldr r1, lbl_08081510 @ =0x0400001a
    ldr r0, lbl_08081514 @ =gBg2YPosition
    ldrb r0, [r0]
    strh r0, [r1]
    bx lr
    .align 2, 0
lbl_080814c0: .4byte sNonGameplayRamPointer
lbl_080814c4: .4byte gWrittenToBLDALPHA_H
lbl_080814c8: .4byte gWrittenToBLDALPHA_L
lbl_080814cc: .4byte 0x04000020
lbl_080814d0: .4byte gWrittenToBG2PA
lbl_080814d4: .4byte gWrittenToBG2PB
lbl_080814d8: .4byte gWrittenToBG2PC
lbl_080814dc: .4byte gWrittenToBG2PD
lbl_080814e0: .4byte gWrittenToBG2X
lbl_080814e4: .4byte 0x0fff0000
lbl_080814e8: .4byte gWrittenToBG2Y
lbl_080814ec: .4byte 0x04000010
lbl_080814f0: .4byte gBg0XPosition
lbl_080814f4: .4byte 0x000001ff
lbl_080814f8: .4byte 0x04000012
lbl_080814fc: .4byte gBg0YPosition
lbl_08081500: .4byte gBg1XPosition
lbl_08081504: .4byte 0x04000016
lbl_08081508: .4byte gBg1YPosition
lbl_0808150c: .4byte gBg2XPosition
lbl_08081510: .4byte 0x0400001a
lbl_08081514: .4byte gBg2YPosition

    thumb_func_start tourian_escape_process_oam
tourian_escape_process_oam: @ 0x08081518
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r5, lbl_0808166c @ =gOamData
    movs r0, #0
    mov ip, r0
    movs r7, #0
    ldr r0, lbl_08081670 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xbe
    ldrb r0, [r0]
    cmp r0, #2
    bls lbl_080815a2
    ldr r4, lbl_08081674 @ =0x08375cc4
    ldrh r1, [r4]
    adds r4, #2
    movs r0, #0xff
    ands r1, r0
    mov ip, r1
    movs r0, #0x80
    mov sb, r0
    movs r1, #0x50
    mov r8, r1
    cmp r7, ip
    bhs lbl_080815a2
    ldr r0, lbl_08081678 @ =0xfffffe00
    mov sl, r0
    ldr r6, lbl_0808167c @ =0x000001ff
lbl_08081556:
    ldrh r2, [r4]
    adds r4, #2
    strh r2, [r5]
    adds r5, #2
    lsls r3, r7, #3
    ldr r1, lbl_0808166c @ =gOamData
    adds r3, r3, r1
    ldrb r1, [r3, #1]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #4
    orrs r0, r1
    strb r0, [r3, #1]
    mov r1, r8
    adds r0, r2, r1
    strb r0, [r3]
    ldrh r2, [r4]
    adds r4, #2
    strh r2, [r5]
    adds r5, #2
    mov r0, sb
    adds r1, r2, r0
    ands r1, r6
    ldrh r2, [r3, #2]
    mov r0, sl
    ands r0, r2
    orrs r0, r1
    strh r0, [r3, #2]
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    adds r5, #4
    adds r0, r7, #1
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    cmp r7, ip
    blo lbl_08081556
lbl_080815a2:
    movs r6, #0
lbl_080815a4:
    ldr r1, lbl_08081670 @ =sNonGameplayRamPointer
    ldr r3, [r1]
    adds r0, r3, #0
    adds r0, #8
    adds r0, r0, r6
    ldrb r0, [r0]
    adds r1, r6, #1
    str r1, [sp]
    cmp r0, #0
    beq lbl_0808164c
    lsls r1, r6, #2
    adds r0, r3, #0
    adds r0, #0x14
    adds r0, r0, r1
    ldr r4, [r0]
    ldrh r2, [r4]
    adds r4, #2
    movs r0, #0xff
    ands r2, r0
    mov r1, ip
    adds r0, r1, r2
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov ip, r0
    lsls r1, r6, #1
    adds r0, r3, #0
    adds r0, #0x50
    adds r0, r0, r1
    ldrh r0, [r0]
    mov sb, r0
    adds r0, r3, #0
    adds r0, #0x64
    adds r0, r0, r1
    ldrh r0, [r0]
    mov r8, r0
    cmp r7, ip
    bhs lbl_0808164c
    ldr r0, lbl_0808167c @ =0x000001ff
    mov sl, r0
lbl_080815f2:
    ldrh r2, [r4]
    adds r4, #2
    strh r2, [r5]
    adds r5, #2
    lsls r3, r7, #3
    ldr r1, lbl_0808166c @ =gOamData
    adds r3, r3, r1
    mov r1, r8
    adds r0, r2, r1
    strb r0, [r3]
    ldrh r2, [r4]
    adds r4, #2
    strh r2, [r5]
    adds r5, #2
    mov r0, sb
    adds r1, r2, r0
    mov r0, sl
    ands r1, r0
    ldrh r2, [r3, #2]
    ldr r0, lbl_08081678 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r3, #2]
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    ldr r1, lbl_08081670 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    adds r0, #0x78
    adds r0, r0, r6
    ldrb r1, [r0]
    movs r0, #3
    ands r1, r0
    lsls r1, r1, #2
    ldrb r2, [r3, #5]
    subs r0, #0x10
    ands r0, r2
    orrs r0, r1
    strb r0, [r3, #5]
    adds r5, #4
    adds r0, r7, #1
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    cmp r7, ip
    blo lbl_080815f2
lbl_0808164c:
    ldr r1, [sp]
    lsls r0, r1, #0x10
    lsrs r6, r0, #0x10
    cmp r6, #9
    bls lbl_080815a4
    ldr r0, lbl_08081680 @ =gNextOamSlot
    strb r7, [r0]
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808166c: .4byte gOamData
lbl_08081670: .4byte sNonGameplayRamPointer
lbl_08081674: .4byte 0x08375cc4
lbl_08081678: .4byte 0xfffffe00
lbl_0808167c: .4byte 0x000001ff
lbl_08081680: .4byte gNextOamSlot

    thumb_func_start TourianEscapeSamusSurrounded_calculate_bg2_pos
TourianEscapeSamusSurrounded_calculate_bg2_pos: @ 0x08081684
    push {r4, r5, r6, lr}
    mov r6, sb
    mov r5, r8
    push {r5, r6}
    ldr r6, lbl_08081760 @ =0x0808c71c
    ldr r5, lbl_08081764 @ =gBg2Rotation
    ldrh r0, [r5]
    adds r0, #0x40
    lsls r0, r0, #1
    adds r0, r0, r6
    movs r1, #0
    ldrsh r4, [r0, r1]
    ldr r2, lbl_08081768 @ =gBg2Scaling
    mov r8, r2
    movs r1, #0
    ldrsh r0, [r2, r1]
    bl FixedInverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r4, #0
    bl FixedMultiplication
    ldr r2, lbl_0808176c @ =gWrittenToBG2PA
    mov sb, r2
    strh r0, [r2]
    ldrh r0, [r5]
    lsls r0, r0, #1
    adds r0, r0, r6
    movs r1, #0
    ldrsh r4, [r0, r1]
    mov r2, r8
    movs r1, #0
    ldrsh r0, [r2, r1]
    bl FixedInverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r4, #0
    bl FixedMultiplication
    ldr r2, lbl_08081770 @ =gWrittenToBG2PB
    mov r8, r2
    strh r0, [r2]
    ldrh r0, [r5]
    lsls r0, r0, #1
    adds r0, r0, r6
    ldrh r4, [r0]
    rsbs r4, r4, #0
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    ldr r0, lbl_08081774 @ =gUnk_30013a2
    movs r6, #0
    ldrsh r0, [r0, r6]
    bl FixedInverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r4, #0
    bl FixedMultiplication
    ldr r5, lbl_08081778 @ =gWrittenToBG2PC
    strh r0, [r5]
    ldr r3, lbl_0808177c @ =gWrittenToBG2PD
    mov r1, sb
    ldrh r0, [r1]
    strh r0, [r3]
    ldr r4, lbl_08081780 @ =gWrittenToBG2X
    mov r2, r8
    movs r6, #0
    ldrsh r1, [r2, r6]
    lsls r0, r1, #2
    adds r0, r0, r1
    lsls r0, r0, #4
    movs r1, #0xf0
    lsls r1, r1, #7
    subs r1, r1, r0
    mov r0, sb
    movs r6, #0
    ldrsh r2, [r0, r6]
    lsls r0, r2, #4
    subs r0, r0, r2
    lsls r0, r0, #3
    subs r1, r1, r0
    str r1, [r4]
    ldr r4, lbl_08081784 @ =gWrittenToBG2Y
    movs r0, #0
    ldrsh r1, [r3, r0]
    lsls r0, r1, #2
    adds r0, r0, r1
    lsls r0, r0, #4
    movs r1, #0xa0
    lsls r1, r1, #7
    subs r1, r1, r0
    movs r6, #0
    ldrsh r2, [r5, r6]
    lsls r0, r2, #4
    subs r0, r0, r2
    lsls r0, r0, #3
    subs r1, r1, r0
    str r1, [r4]
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08081760: .4byte 0x0808c71c
lbl_08081764: .4byte gBg2Rotation
lbl_08081768: .4byte gBg2Scaling
lbl_0808176c: .4byte gWrittenToBG2PA
lbl_08081770: .4byte gWrittenToBG2PB
lbl_08081774: .4byte gUnk_30013a2
lbl_08081778: .4byte gWrittenToBG2PC
lbl_0808177c: .4byte gWrittenToBG2PD
lbl_08081780: .4byte gWrittenToBG2X
lbl_08081784: .4byte gWrittenToBG2Y

    thumb_func_start sub_08081788
sub_08081788: @ 0x08081788
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov sl, r0
    movs r5, #4
    ldr r7, lbl_080817cc @ =sNonGameplayRamPointer
    ldr r0, lbl_080817d0 @ =0x0847ce20
    mov sb, r0
    movs r4, #8
    movs r1, #0x10
    mov r8, r1
lbl_080817a6:
    ldr r2, [r7]
    adds r0, r2, #0
    adds r0, #0x46
    adds r0, r0, r5
    ldrb r0, [r0]
    lsrs r3, r0, #2
    adds r0, r2, #0
    adds r0, #8
    adds r0, r0, r5
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080817d8
    adds r1, r2, #0
    adds r1, #0x14
    add r1, r8
    ldr r2, lbl_080817d4 @ =0x0847ce00
    b lbl_080817e0
    .align 2, 0
lbl_080817cc: .4byte sNonGameplayRamPointer
lbl_080817d0: .4byte 0x0847ce20
lbl_080817d4: .4byte 0x0847ce00
lbl_080817d8:
    adds r1, r2, #0
    adds r1, #0x14
    add r1, r8
    ldr r2, lbl_0808180c @ =0x0847ce10
lbl_080817e0:
    lsls r0, r3, #2
    adds r0, r0, r2
    ldr r0, [r0]
    str r0, [r1]
    movs r6, #0
    mov r0, sl
    cmp r0, #0
    bne lbl_08081810
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0x50
    adds r3, r0, r4
    ldrh r2, [r3]
    cmp r2, #0xff
    bhi lbl_08081830
    adds r0, #0x46
    adds r0, r0, r4
    ldrh r0, [r0]
    adds r0, r2, r0
    strh r0, [r3]
    b lbl_0808182c
    .align 2, 0
lbl_0808180c: .4byte 0x0847ce10
lbl_08081810:
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0x64
    adds r3, r0, r4
    ldrh r2, [r3]
    cmp r2, #0xfb
    bhi lbl_0808182a
    adds r0, #0x32
    adds r0, r0, r4
    ldrh r0, [r0]
    subs r0, r2, r0
    strh r0, [r3]
    b lbl_0808182c
lbl_0808182a:
    movs r6, #1
lbl_0808182c:
    cmp r6, #0
    beq lbl_0808189a
lbl_08081830:
    ldr r2, [r7]
    adds r2, #8
    adds r2, r2, r5
    ldrb r0, [r2]
    movs r1, #3
    eors r0, r1
    strb r0, [r2]
    ldr r2, [r7]
    adds r2, #0x3c
    adds r2, r2, r5
    ldrb r0, [r2]
    adds r0, #1
    movs r1, #0xf
    ands r0, r1
    strb r0, [r2]
    ldr r1, [r7]
    mov ip, r1
    mov r2, ip
    adds r2, #0x50
    adds r2, r2, r4
    mov r3, ip
    adds r3, #0x3c
    adds r3, r3, r5
    ldrb r1, [r3]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    add r0, sb
    ldrh r0, [r0]
    strh r0, [r2]
    mov r2, ip
    adds r2, #0x64
    adds r2, r2, r4
    ldrb r1, [r3]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    mov r1, sb
    adds r1, #2
    adds r0, r0, r1
    ldrh r0, [r0]
    strh r0, [r2]
    mov r2, ip
    adds r2, #0x96
    adds r2, r2, r4
    ldrb r1, [r3]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    ldr r1, lbl_080818c8 @ =0x0847ce24
    adds r0, r0, r1
    ldrh r0, [r0]
    strh r0, [r2]
lbl_0808189a:
    ldr r0, [r7]
    adds r0, #0x46
    adds r0, r0, r5
    ldrb r1, [r0]
    adds r1, #1
    movs r2, #0xf
    ands r1, r2
    strb r1, [r0]
    adds r4, #2
    movs r0, #4
    add r8, r0
    adds r5, #1
    cmp r5, #9
    bgt lbl_080818b8
    b lbl_080817a6
lbl_080818b8:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080818c8: .4byte 0x0847ce24

    thumb_func_start sub_080818cc
sub_080818cc: @ 0x080818cc
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    ldr r5, lbl_08081ac4 @ =gOamData
    ldr r0, lbl_08081ac8 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrb r0, [r1, #8]
    cmp r0, #0
    beq lbl_08081966
    ldr r4, [r1, #0x14]
    ldrh r0, [r4]
    mov sb, r0
    adds r4, #2
    movs r0, #0xff
    mov r2, sb
    ands r2, r0
    mov sb, r2
    adds r0, r1, #0
    adds r0, #0x64
    ldrh r0, [r0]
    mov ip, r0
    adds r0, r1, #0
    adds r0, #0x50
    ldrh r6, [r0]
    movs r7, #0
    cmp r7, sb
    bhs lbl_08081954
    lsls r6, r6, #0x10
    mov r8, r6
    mov r3, ip
    lsls r6, r3, #0x10
lbl_08081910:
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    adds r5, #4
    ldr r0, lbl_08081ac8 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x82
    movs r1, #0
    ldrsh r0, [r0, r1]
    str r0, [sp]
    movs r0, #1
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    adds r0, r7, #0
    mov r2, r8
    asrs r1, r2, #0x10
    asrs r2, r6, #0x10
    movs r3, #0
    bl ProcessComplexOam
    adds r0, r7, #1
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    cmp r7, sb
    blo lbl_08081910
lbl_08081954:
    ldr r0, lbl_08081ac8 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x82
    movs r3, #0
    ldrsh r1, [r0, r3]
    movs r0, #0
    movs r2, #0
    bl CalculateOamPart4
lbl_08081966:
    ldr r0, lbl_08081ac8 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrb r0, [r2, #9]
    cmp r0, #0
    beq lbl_080819f4
    ldr r4, [r2, #0x18]
    ldrh r1, [r4]
    adds r4, #2
    movs r0, #0xff
    ands r1, r0
    mov r3, sb
    adds r0, r3, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sb, r0
    adds r0, r2, #0
    adds r0, #0x66
    ldrh r0, [r0]
    mov ip, r0
    adds r0, r2, #0
    adds r0, #0x52
    ldrh r6, [r0]
    cmp r7, sb
    bhs lbl_080819e2
    lsls r6, r6, #0x10
    mov r8, r6
    mov r0, ip
    lsls r6, r0, #0x10
lbl_0808199e:
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    adds r5, #4
    ldr r0, lbl_08081ac8 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x84
    movs r1, #0
    ldrsh r0, [r0, r1]
    str r0, [sp]
    movs r0, #1
    str r0, [sp, #4]
    movs r0, #4
    str r0, [sp, #8]
    adds r0, r7, #0
    mov r2, r8
    asrs r1, r2, #0x10
    asrs r2, r6, #0x10
    movs r3, #0
    bl ProcessComplexOam
    adds r0, r7, #1
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    cmp r7, sb
    blo lbl_0808199e
lbl_080819e2:
    ldr r0, lbl_08081ac8 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x84
    movs r3, #0
    ldrsh r1, [r0, r3]
    movs r0, #0
    movs r2, #0x10
    bl CalculateOamPart4
lbl_080819f4:
    movs r0, #4
    mov r8, r0
lbl_080819f8:
    ldr r1, lbl_08081ac8 @ =sNonGameplayRamPointer
    ldr r2, [r1]
    adds r0, r2, #0
    adds r0, #8
    add r0, r8
    ldrb r0, [r0]
    mov r3, r8
    adds r3, #1
    str r3, [sp, #0xc]
    cmp r0, #0
    beq lbl_08081aa4
    mov r0, r8
    lsls r1, r0, #2
    adds r0, r2, #0
    adds r0, #0x14
    adds r0, r0, r1
    ldr r4, [r0]
    ldrh r1, [r4]
    adds r4, #2
    movs r0, #0xff
    ands r1, r0
    mov r3, sb
    adds r0, r3, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sb, r0
    mov r0, r8
    lsls r1, r0, #1
    adds r0, r2, #0
    adds r0, #0x64
    adds r0, r0, r1
    ldrh r0, [r0]
    mov ip, r0
    adds r0, r2, #0
    adds r0, #0x50
    adds r0, r0, r1
    ldrh r6, [r0]
    cmp r7, sb
    bhs lbl_08081aa4
    ldr r1, lbl_08081acc @ =0x000001ff
    mov sl, r1
lbl_08081a4a:
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    lsls r3, r7, #3
    ldr r2, lbl_08081ac4 @ =gOamData
    adds r3, r3, r2
    mov r2, ip
    adds r0, r1, r2
    strb r0, [r3]
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    adds r1, r1, r6
    mov r0, sl
    ands r1, r0
    ldrh r2, [r3, #2]
    ldr r0, lbl_08081ad0 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r3, #2]
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    ldr r1, lbl_08081ac8 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    adds r0, #0x78
    add r0, r8
    ldrb r1, [r0]
    movs r2, #3
    ands r1, r2
    lsls r1, r1, #2
    ldrb r2, [r3, #5]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r3, #5]
    adds r5, #4
    adds r0, r7, #1
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    cmp r7, sb
    blo lbl_08081a4a
lbl_08081aa4:
    ldr r3, [sp, #0xc]
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    cmp r0, #9
    bls lbl_080819f8
    ldr r0, lbl_08081ad4 @ =gNextOamSlot
    strb r7, [r0]
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08081ac4: .4byte gOamData
lbl_08081ac8: .4byte sNonGameplayRamPointer
lbl_08081acc: .4byte 0x000001ff
lbl_08081ad0: .4byte 0xfffffe00
lbl_08081ad4: .4byte gNextOamSlot

    thumb_func_start sub_08081ad8
sub_08081ad8: @ 0x08081ad8
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r2, lbl_08081b04 @ =sNonGameplayRamPointer
    ldr r3, [r2]
    adds r0, r3, #0
    adds r0, #0x46
    ldrb r1, [r0]
    movs r0, #3
    ands r0, r1
    cmp r0, #1
    bhi lbl_08081b08
    adds r1, r3, #0
    adds r1, #0x50
    movs r0, #0x6d
    strh r0, [r1]
    adds r1, #0x14
    movs r0, #0x46
    b lbl_08081b14
    .align 2, 0
lbl_08081b04: .4byte sNonGameplayRamPointer
lbl_08081b08:
    adds r1, r3, #0
    adds r1, #0x50
    movs r0, #0x6c
    strh r0, [r1]
    adds r1, #0x14
    movs r0, #0x47
lbl_08081b14:
    strh r0, [r1]
    ldr r1, lbl_08081cd4 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    adds r0, #0x46
    ldrb r1, [r0]
    adds r1, #1
    strb r1, [r0]
    ldr r4, lbl_08081cd4 @ =sNonGameplayRamPointer
    ldr r1, [r4]
    ldrb r0, [r1, #9]
    cmp r0, #0
    beq lbl_08081b88
    adds r0, r1, #0
    adds r0, #0x47
    ldrb r1, [r0]
    adds r2, r1, #1
    strb r2, [r0]
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x1a
    cmp r4, #7
    bls lbl_08081b5a
    ldr r7, lbl_08081cd4 @ =sNonGameplayRamPointer
    ldr r0, [r7]
    adds r0, #0x47
    movs r1, #0
    strb r1, [r0]
    ldr r1, [r7]
    adds r2, r1, #0
    adds r2, #0x52
    movs r0, #0x6d
    strh r0, [r2]
    adds r1, #0x66
    movs r0, #0x46
    strh r0, [r1]
    movs r4, #0
lbl_08081b5a:
    ldr r0, lbl_08081cd4 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldr r1, lbl_08081cd8 @ =0x0847cea0
    lsls r0, r4, #2
    adds r0, r0, r1
    ldr r0, [r0]
    str r0, [r2, #0x18]
    adds r3, r2, #0
    adds r3, #0x52
    ldr r0, lbl_08081cdc @ =0x0847ce80
    lsls r1, r4, #1
    adds r0, r1, r0
    ldrh r0, [r0]
    ldrh r4, [r3]
    adds r0, r0, r4
    strh r0, [r3]
    adds r2, #0x66
    ldr r0, lbl_08081ce0 @ =0x0847ce90
    adds r1, r1, r0
    ldrh r0, [r1]
    ldrh r7, [r2]
    adds r0, r0, r7
    strh r0, [r2]
lbl_08081b88:
    ldr r0, lbl_08081cd4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrb r0, [r1, #0xa]
    cmp r0, #0
    beq lbl_08081bf0
    adds r0, r1, #0
    adds r0, #0x48
    ldrb r1, [r0]
    adds r2, r1, #1
    strb r2, [r0]
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x1a
    cmp r4, #7
    bls lbl_08081bc2
    ldr r1, lbl_08081cd4 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    adds r0, #0x48
    movs r1, #0
    strb r1, [r0]
    ldr r4, lbl_08081cd4 @ =sNonGameplayRamPointer
    ldr r1, [r4]
    adds r2, r1, #0
    adds r2, #0x54
    movs r0, #0x6d
    strh r0, [r2]
    adds r1, #0x68
    movs r0, #0x46
    strh r0, [r1]
    movs r4, #0
lbl_08081bc2:
    ldr r7, lbl_08081cd4 @ =sNonGameplayRamPointer
    ldr r2, [r7]
    ldr r1, lbl_08081cd8 @ =0x0847cea0
    lsls r0, r4, #2
    adds r0, r0, r1
    ldr r0, [r0]
    str r0, [r2, #0x1c]
    adds r3, r2, #0
    adds r3, #0x54
    ldr r0, lbl_08081cdc @ =0x0847ce80
    lsls r1, r4, #1
    adds r0, r1, r0
    ldrh r0, [r0]
    ldrh r4, [r3]
    adds r0, r0, r4
    strh r0, [r3]
    adds r2, #0x68
    ldr r0, lbl_08081ce0 @ =0x0847ce90
    adds r1, r1, r0
    ldrh r0, [r2]
    ldrh r1, [r1]
    subs r0, r0, r1
    strh r0, [r2]
lbl_08081bf0:
    ldr r7, lbl_08081cd4 @ =sNonGameplayRamPointer
    ldr r0, [r7]
    ldrh r1, [r0, #6]
    movs r0, #7
    ands r0, r1
    ldr r2, lbl_08081ce4 @ =0x08479f00
    cmp r0, #3
    bhi lbl_08081c02
    subs r2, #0x20
lbl_08081c02:
    ldr r1, lbl_08081ce8 @ =0x040000d4
    str r2, [r1]
    ldr r0, lbl_08081cec @ =0x050002a0
    str r0, [r1, #4]
    ldr r0, lbl_08081cf0 @ =0x80000010
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r5, lbl_08081cf4 @ =gOamData
    movs r0, #0
    mov r8, r0
    movs r6, #0
    movs r3, #0
lbl_08081c1a:
    ldr r1, lbl_08081cd4 @ =sNonGameplayRamPointer
    ldr r2, [r1]
    adds r0, r2, #0
    adds r0, #8
    adds r0, r0, r3
    ldrb r0, [r0]
    adds r4, r3, #1
    str r4, [sp]
    cmp r0, #0
    beq lbl_08081cb4
    lsls r1, r3, #2
    adds r0, r2, #0
    adds r0, #0x14
    adds r0, r0, r1
    ldr r4, [r0]
    ldrh r1, [r4]
    adds r4, #2
    movs r0, #0xff
    ands r1, r0
    mov r7, r8
    adds r0, r7, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    lsls r1, r3, #1
    adds r0, r2, #0
    adds r0, #0x50
    adds r0, r0, r1
    ldrh r0, [r0]
    mov ip, r0
    adds r0, r2, #0
    adds r0, #0x64
    adds r0, r0, r1
    ldrh r7, [r0]
    cmp r6, r8
    bhs lbl_08081cb4
    ldr r0, lbl_08081cf8 @ =0xfffffe00
    mov sl, r0
    ldr r1, lbl_08081cfc @ =0x000001ff
    mov sb, r1
lbl_08081c6a:
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    lsls r3, r6, #3
    ldr r0, lbl_08081cf4 @ =gOamData
    adds r3, r3, r0
    adds r0, r1, r7
    strb r0, [r3]
    ldrb r1, [r3, #1]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #4
    orrs r0, r1
    strb r0, [r3, #1]
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    add r1, ip
    mov r0, sb
    ands r1, r0
    ldrh r2, [r3, #2]
    mov r0, sl
    ands r0, r2
    orrs r0, r1
    strh r0, [r3, #2]
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    adds r5, #4
    adds r0, r6, #1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    cmp r6, r8
    blo lbl_08081c6a
lbl_08081cb4:
    ldr r1, [sp]
    lsls r0, r1, #0x10
    lsrs r3, r0, #0x10
    cmp r3, #3
    bls lbl_08081c1a
    ldr r4, lbl_08081d00 @ =gNextOamSlot
    strb r6, [r4]
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08081cd4: .4byte sNonGameplayRamPointer
lbl_08081cd8: .4byte 0x0847cea0
lbl_08081cdc: .4byte 0x0847ce80
lbl_08081ce0: .4byte 0x0847ce90
lbl_08081ce4: .4byte 0x08479f00
lbl_08081ce8: .4byte 0x040000d4
lbl_08081cec: .4byte 0x050002a0
lbl_08081cf0: .4byte 0x80000010
lbl_08081cf4: .4byte gOamData
lbl_08081cf8: .4byte 0xfffffe00
lbl_08081cfc: .4byte 0x000001ff
lbl_08081d00: .4byte gNextOamSlot

    thumb_func_start tourian_escape_init
tourian_escape_init: @ 0x08081d04
    push {r4, r5, r6, lr}
    mov r6, sb
    mov r5, r8
    push {r5, r6}
    sub sp, #4
    ldr r6, lbl_08081dd8 @ =0x04000208
    movs r5, #0
    strh r5, [r6]
    ldr r2, lbl_08081ddc @ =0x04000004
    ldrh r1, [r2]
    ldr r0, lbl_08081de0 @ =0x0000ffef
    ands r0, r1
    strh r0, [r2]
    ldr r2, lbl_08081de4 @ =0x04000200
    ldrh r1, [r2]
    ldr r0, lbl_08081de8 @ =0x0000fffd
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_08081dec @ =0x04000202
    movs r0, #2
    strh r0, [r1]
    movs r0, #1
    mov r8, r0
    strh r0, [r6]
    movs r0, #0x80
    lsls r0, r0, #0x13
    strh r5, [r0]
    adds r0, #0x50
    strh r5, [r0]
    ldr r1, lbl_08081df0 @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_08081df4 @ =gWrittenToBLDALPHA_H
    strh r5, [r0]
    ldr r0, lbl_08081df8 @ =gWrittenToBLDY_NonGameplay
    strh r5, [r0]
    strh r5, [r6]
    movs r0, #0
    bl CallbackSetVBlank
    mov r0, r8
    strh r0, [r6]
    movs r0, #0
    mov sb, r0
    str r0, [sp]
    ldr r4, lbl_08081dfc @ =0x040000d4
    mov r0, sp
    str r0, [r4]
    ldr r0, lbl_08081e00 @ =gNonGameplayRAM
    str r0, [r4, #4]
    ldr r0, lbl_08081e04 @ =0x8500018a
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    bl ClearGfxRam
    ldr r0, lbl_08081e08 @ =0x08480148
    ldr r1, lbl_08081e0c @ =0x06010000
    bl LZ77UncompVRAM
    ldr r0, lbl_08081e10 @ =0x0847cd7c
    ldr r1, lbl_08081e14 @ =0x06013000
    bl LZ77UncompVRAM
    ldr r0, lbl_08081e18 @ =0x08479520
    str r0, [r4]
    ldr r0, lbl_08081e1c @ =0x05000200
    str r0, [r4, #4]
    ldr r0, lbl_08081e20 @ =0x80000060
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    movs r2, #0xa0
    lsls r2, r2, #1
    movs r3, #0xa0
    lsls r3, r3, #2
    movs r0, #4
    movs r1, #5
    bl LoadRoomCutscene
    mov r0, sb
    strh r0, [r6]
    ldr r4, lbl_08081e24 @ =vblank_code_during_intro
    adds r0, r4, #0
    bl CallbackSetVBlank
    mov r0, r8
    strh r0, [r6]
    ldr r0, lbl_08081e28 @ =gNextOamSlot
    strb r5, [r0]
    bl ResetFreeOam
    ldr r0, lbl_08081e2c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xc0
    movs r1, #0xf0
    lsls r1, r1, #5
    strh r1, [r0]
    bl _call_via_r4
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08081dd8: .4byte 0x04000208
lbl_08081ddc: .4byte 0x04000004
lbl_08081de0: .4byte 0x0000ffef
lbl_08081de4: .4byte 0x04000200
lbl_08081de8: .4byte 0x0000fffd
lbl_08081dec: .4byte 0x04000202
lbl_08081df0: .4byte gWrittenToBLDALPHA_L
lbl_08081df4: .4byte gWrittenToBLDALPHA_H
lbl_08081df8: .4byte gWrittenToBLDY_NonGameplay
lbl_08081dfc: .4byte 0x040000d4
lbl_08081e00: .4byte gNonGameplayRAM
lbl_08081e04: .4byte 0x8500018a
lbl_08081e08: .4byte 0x08480148
lbl_08081e0c: .4byte 0x06010000
lbl_08081e10: .4byte 0x0847cd7c
lbl_08081e14: .4byte 0x06013000
lbl_08081e18: .4byte 0x08479520
lbl_08081e1c: .4byte 0x05000200
lbl_08081e20: .4byte 0x80000060
lbl_08081e24: .4byte vblank_code_during_intro
lbl_08081e28: .4byte gNextOamSlot
lbl_08081e2c: .4byte sNonGameplayRamPointer

    thumb_func_start TourianEscapeZebesExploding
TourianEscapeZebesExploding: @ 0x08081e30
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    movs r0, #0
    mov sb, r0
    mov r8, r0
    ldr r0, lbl_08081e70 @ =sNonGameplayRamPointer
    ldr r4, [r0]
    ldrh r1, [r4, #6]
    adds r2, r1, #1
    strh r2, [r4, #6]
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    adds r6, r0, #0
    cmp r1, #0xb0
    bne lbl_08081e54
    b lbl_08082048
lbl_08081e54:
    cmp r1, #0xb0
    bgt lbl_08081e8e
    cmp r1, #0x41
    bne lbl_08081e5e
    b lbl_08081fb4
lbl_08081e5e:
    cmp r1, #0x41
    bgt lbl_08081e74
    cmp r1, #0
    beq lbl_08081ed0
    cmp r1, #0x40
    bne lbl_08081e6c
    b lbl_08081f9c
lbl_08081e6c:
    b lbl_0808222a
    .align 2, 0
lbl_08081e70: .4byte sNonGameplayRamPointer
lbl_08081e74:
    cmp r1, #0x88
    bne lbl_08081e7a
    b lbl_08081f9c
lbl_08081e7a:
    cmp r1, #0x88
    bgt lbl_08081e86
    cmp r1, #0x68
    bne lbl_08081e84
    b lbl_08081fd8
lbl_08081e84:
    b lbl_0808222a
lbl_08081e86:
    cmp r1, #0x89
    bne lbl_08081e8c
    b lbl_08081fc0
lbl_08081e8c:
    b lbl_0808222a
lbl_08081e8e:
    cmp r1, #0xf7
    bne lbl_08081e94
    b lbl_080820e8
lbl_08081e94:
    cmp r1, #0xf7
    bgt lbl_08081eb0
    cmp r1, #0xd1
    bne lbl_08081e9e
    b lbl_08081fcc
lbl_08081e9e:
    cmp r1, #0xd1
    bgt lbl_08081ea8
    cmp r1, #0xd0
    beq lbl_08081f9c
    b lbl_0808222a
lbl_08081ea8:
    cmp r1, #0xf6
    bne lbl_08081eae
    b lbl_080820c0
lbl_08081eae:
    b lbl_0808222a
lbl_08081eb0:
    movs r0, #0xb0
    lsls r0, r0, #1
    cmp r1, r0
    beq lbl_08081f9c
    cmp r1, r0
    bgt lbl_08081ec4
    cmp r1, #0xf8
    bne lbl_08081ec2
    b lbl_080821a4
lbl_08081ec2:
    b lbl_0808222a
lbl_08081ec4:
    movs r0, #0x80
    lsls r0, r0, #2
    cmp r1, r0
    bne lbl_08081ece
    b lbl_0808221c
lbl_08081ece:
    b lbl_0808222a
lbl_08081ed0:
    movs r3, #1
    strb r3, [r4, #8]
    ldr r4, [r6]
    ldr r2, lbl_08081f84 @ =0x0847ced0
    ldrh r1, [r2]
    adds r0, r4, #0
    adds r0, #0x50
    strh r1, [r0]
    ldrh r1, [r2, #2]
    adds r0, #0x14
    strh r1, [r0]
    strb r3, [r4, #9]
    ldr r4, [r6]
    ldr r1, lbl_08081f88 @ =0x0847cef0
    ldrh r0, [r1]
    adds r2, r4, #0
    adds r2, #0x52
    strh r0, [r2]
    ldrh r0, [r1, #2]
    adds r1, r4, #0
    adds r1, #0x66
    strh r0, [r1]
    strb r3, [r4, #0xa]
    ldr r4, [r6]
    ldr r2, lbl_08081f8c @ =0x0847cf10
    ldrh r1, [r2]
    adds r0, r4, #0
    adds r0, #0x54
    strh r1, [r0]
    ldrh r1, [r2, #2]
    adds r0, #0x14
    strh r1, [r0]
    strb r3, [r4, #0xb]
    ldr r0, [r6]
    adds r0, #0x3f
    movs r1, #8
    strb r1, [r0]
    ldr r0, [r6]
    ldr r2, lbl_08081f90 @ =0x0847cf30
    ldrh r1, [r2]
    adds r3, r0, #0
    adds r3, #0x56
    strh r1, [r3]
    ldrh r1, [r2, #2]
    adds r0, #0x6a
    strh r1, [r0]
    movs r4, #4
    adds r5, r6, #0
    ldr r6, lbl_08081f94 @ =0x0847cf50
    adds r7, r6, #2
lbl_08081f34:
    ldr r0, [r5]
    adds r0, #8
    adds r0, r0, r4
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0x3c
    adds r0, r0, r4
    strb r4, [r0]
    ldr r1, [r5]
    mov ip, r1
    lsls r3, r4, #1
    adds r1, #0x50
    adds r1, r1, r3
    mov r2, ip
    adds r2, #0x3c
    adds r2, r2, r4
    ldrb r0, [r2]
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrh r0, [r0]
    strh r0, [r1]
    mov r1, ip
    adds r1, #0x64
    adds r1, r1, r3
    ldrb r0, [r2]
    lsls r0, r0, #2
    adds r0, r0, r7
    ldrh r0, [r0]
    strh r0, [r1]
    adds r0, r4, #1
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #8
    bls lbl_08081f34
    ldr r0, lbl_08081f98 @ =0x0000023e
    bl SoundPlay
    b lbl_0808222a
    .align 2, 0
lbl_08081f84: .4byte 0x0847ced0
lbl_08081f88: .4byte 0x0847cef0
lbl_08081f8c: .4byte 0x0847cf10
lbl_08081f90: .4byte 0x0847cf30
lbl_08081f94: .4byte 0x0847cf50
lbl_08081f98: .4byte 0x0000023e
lbl_08081f9c:
    ldr r0, lbl_08081fb0 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r2, r1, #0
    adds r2, #0xc2
    movs r0, #0xbf
    strh r0, [r2]
    ldrb r0, [r1, #1]
    adds r0, #1
    strb r0, [r1, #1]
    b lbl_0808222a
    .align 2, 0
lbl_08081fb0: .4byte sNonGameplayRamPointer
lbl_08081fb4:
    ldr r0, lbl_08081fbc @ =0x0000023f
    bl SoundPlay
    b lbl_0808222a
    .align 2, 0
lbl_08081fbc: .4byte 0x0000023f
lbl_08081fc0:
    ldr r0, lbl_08081fc8 @ =0x00000241
    bl SoundPlay
    b lbl_0808222a
    .align 2, 0
lbl_08081fc8: .4byte 0x00000241
lbl_08081fcc:
    ldr r0, lbl_08081fd4 @ =0x00000243
    bl SoundPlay
    b lbl_0808222a
    .align 2, 0
lbl_08081fd4: .4byte 0x00000243
lbl_08081fd8:
    movs r3, #0xc0
    lsls r3, r3, #2
    movs r0, #4
    movs r1, #6
    movs r2, #0x80
    bl LoadRoomCutscene
    movs r4, #4
    movs r2, #1
    mov r8, r2
    adds r5, r6, #0
    ldr r6, lbl_08082044 @ =0x0847cf50
    adds r7, r6, #2
lbl_08081ff2:
    ldr r0, [r5]
    adds r0, #0x46
    adds r0, r0, r4
    movs r1, #0
    strb r1, [r0]
    ldr r2, [r5]
    adds r2, #0x3c
    adds r2, r2, r4
    ldrb r0, [r2]
    adds r0, #1
    movs r1, #7
    ands r0, r1
    strb r0, [r2]
    ldr r0, [r5]
    mov ip, r0
    lsls r3, r4, #1
    mov r1, ip
    adds r1, #0x50
    adds r1, r1, r3
    mov r2, ip
    adds r2, #0x3c
    adds r2, r2, r4
    ldrb r0, [r2]
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrh r0, [r0]
    strh r0, [r1]
    mov r1, ip
    adds r1, #0x64
    adds r1, r1, r3
    ldrb r0, [r2]
    lsls r0, r0, #2
    adds r0, r0, r7
    ldrh r0, [r0]
    strh r0, [r1]
    adds r0, r4, #1
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #8
    bls lbl_08081ff2
    b lbl_080820b0
    .align 2, 0
lbl_08082044: .4byte 0x0847cf50
lbl_08082048:
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #5
    movs r1, #2
    movs r2, #0x80
    bl LoadRoomCutscene
    movs r4, #4
    movs r1, #1
    mov r8, r1
    adds r5, r6, #0
    ldr r6, lbl_080820bc @ =0x0847cf50
    adds r7, r6, #2
lbl_08082062:
    ldr r0, [r5]
    adds r0, #0x46
    adds r0, r0, r4
    movs r1, #0
    strb r1, [r0]
    ldr r2, [r5]
    adds r2, #0x3c
    adds r2, r2, r4
    ldrb r0, [r2]
    adds r0, #1
    movs r1, #7
    ands r0, r1
    strb r0, [r2]
    ldr r2, [r5]
    mov ip, r2
    lsls r3, r4, #1
    mov r1, ip
    adds r1, #0x50
    adds r1, r1, r3
    adds r2, #0x3c
    adds r2, r2, r4
    ldrb r0, [r2]
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrh r0, [r0]
    strh r0, [r1]
    mov r1, ip
    adds r1, #0x64
    adds r1, r1, r3
    ldrb r0, [r2]
    lsls r0, r0, #2
    adds r0, r0, r7
    ldrh r0, [r0]
    strh r0, [r1]
    adds r0, r4, #1
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #8
    bls lbl_08082062
lbl_080820b0:
    movs r0, #0x90
    lsls r0, r0, #2
    bl SoundPlay
    b lbl_0808222a
    .align 2, 0
lbl_080820bc: .4byte 0x0847cf50
lbl_080820c0:
    ldr r4, lbl_080820dc @ =0x04000208
    mov r0, sb
    strh r0, [r4]
    ldr r0, lbl_080820e0 @ =sub_08081320
    bl CallbackSetVBlank
    movs r0, #1
    strh r0, [r4]
    ldr r0, lbl_080820e4 @ =0x0848a17c
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    b lbl_0808222a
    .align 2, 0
lbl_080820dc: .4byte 0x04000208
lbl_080820e0: .4byte sub_08081320
lbl_080820e4: .4byte 0x0848a17c
lbl_080820e8:
    ldr r0, lbl_08082184 @ =0x0848e048
    ldr r1, lbl_08082188 @ =0x06010000
    bl LZ77UncompVRAM
    ldr r1, [r6]
    ldrb r0, [r1, #2]
    adds r0, #1
    strb r0, [r1, #2]
    ldr r0, [r6]
    mov r1, sb
    strb r1, [r0, #5]
    ldr r0, [r6]
    movs r2, #1
    strb r2, [r0, #8]
    ldr r4, [r6]
    adds r1, r4, #0
    adds r1, #0x50
    movs r3, #0
    movs r0, #0xc0
    strh r0, [r1]
    adds r0, r4, #0
    adds r0, #0x64
    movs r1, #0x40
    strh r1, [r0]
    subs r0, #0x1e
    strb r3, [r0]
    ldr r0, [r6]
    strb r2, [r0, #9]
    ldr r2, [r6]
    adds r0, r2, #0
    adds r0, #0x52
    strh r1, [r0]
    adds r1, r2, #0
    adds r1, #0x66
    movs r0, #0x59
    strh r0, [r1]
    adds r0, r2, #0
    adds r0, #0x47
    strb r3, [r0]
    movs r4, #2
    adds r2, r6, #0
    movs r1, #0
lbl_0808213c:
    ldr r0, [r2]
    adds r0, #8
    adds r0, r0, r4
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0x3c
    adds r0, r0, r4
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0x46
    adds r0, r0, r4
    strb r1, [r0]
    adds r0, r4, #1
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #8
    bls lbl_0808213c
    ldr r0, lbl_0808218c @ =gBg0XPosition
    movs r1, #0
    strh r1, [r0]
    ldr r0, lbl_08082190 @ =gBg0YPosition
    strh r1, [r0]
    ldr r0, lbl_08082194 @ =gBg1XPosition
    strh r1, [r0]
    ldr r0, lbl_08082198 @ =gBg1YPosition
    strh r1, [r0]
    ldr r0, lbl_0808219c @ =gBg2XPosition
    strh r1, [r0]
    ldr r0, lbl_080821a0 @ =gBg2YPosition
    strh r1, [r0]
    movs r0, #0
    movs r1, #0x14
    movs r2, #0
    bl sub_08003b30
    b lbl_0808222a
    .align 2, 0
lbl_08082184: .4byte 0x0848e048
lbl_08082188: .4byte 0x06010000
lbl_0808218c: .4byte gBg0XPosition
lbl_08082190: .4byte gBg0YPosition
lbl_08082194: .4byte gBg1XPosition
lbl_08082198: .4byte gBg1YPosition
lbl_0808219c: .4byte gBg2XPosition
lbl_080821a0: .4byte gBg2YPosition
lbl_080821a4:
    ldr r0, lbl_080821f8 @ =0x0848d744
    ldr r1, lbl_080821fc @ =0x0600f000
    bl LZ77UncompVRAM
    ldr r0, lbl_08082200 @ =0x040000d4
    ldr r3, lbl_08082204 @ =0x08479400
    str r3, [r0]
    movs r1, #0xa0
    lsls r1, r1, #0x13
    str r1, [r0, #4]
    ldr r2, lbl_08082208 @ =0x80000090
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    str r3, [r0]
    ldr r1, lbl_0808220c @ =0x05000200
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    ldr r1, lbl_08082210 @ =0x04000008
    movs r2, #0xf0
    lsls r2, r2, #5
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, [r6]
    adds r0, #0xc0
    movs r1, #0x88
    lsls r1, r1, #5
    strh r1, [r0]
    ldr r1, lbl_08082214 @ =gWrittenToBLDALPHA_L
    movs r0, #0xa
    strh r0, [r1]
    ldr r1, lbl_08082218 @ =gWrittenToBLDALPHA_H
    movs r0, #6
    strh r0, [r1]
    movs r0, #2
    mov r8, r0
    movs r0, #0x91
    lsls r0, r0, #2
    bl SoundPlay
    b lbl_0808222a
    .align 2, 0
lbl_080821f8: .4byte 0x0848d744
lbl_080821fc: .4byte 0x0600f000
lbl_08082200: .4byte 0x040000d4
lbl_08082204: .4byte 0x08479400
lbl_08082208: .4byte 0x80000090
lbl_0808220c: .4byte 0x05000200
lbl_08082210: .4byte 0x04000008
lbl_08082214: .4byte gWrittenToBLDALPHA_L
lbl_08082218: .4byte gWrittenToBLDALPHA_H
lbl_0808221c:
    ldr r0, lbl_08082284 @ =gBg0XPosition
    mov r1, sb
    strh r1, [r0]
    ldr r0, lbl_08082288 @ =gBg0YPosition
    strh r1, [r0]
    movs r2, #1
    mov sb, r2
lbl_0808222a:
    ldr r5, lbl_0808228c @ =sNonGameplayRamPointer
    ldr r0, [r5]
    ldrh r0, [r0, #6]
    cmp r0, #0xef
    bhi lbl_08082238
    bl AnimatedGraphicsUpdate
lbl_08082238:
    mov r0, r8
    cmp r0, #0
    beq lbl_08082254
    ldr r2, [r5]
    adds r4, r2, #0
    adds r4, #0xc2
    movs r3, #0
    movs r1, #0
    movs r0, #0xfc
    lsls r0, r0, #6
    strh r0, [r4]
    ldr r0, lbl_08082290 @ =gWrittenToBLDY_NonGameplay
    strh r1, [r0]
    strb r3, [r2, #1]
lbl_08082254:
    ldr r2, [r5]
    ldrb r0, [r2, #1]
    cmp r0, #0
    beq lbl_080822ae
    ldrh r0, [r2, #6]
    cmp r0, #0xff
    bls lbl_08082294
    ldrb r0, [r2, #5]
    adds r1, r0, #1
    strb r1, [r2, #5]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #5
    bls lbl_080822ae
    ldr r1, lbl_08082290 @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_0808227c
    adds r0, #1
    strh r0, [r1]
lbl_0808227c:
    ldr r1, [r5]
    movs r0, #0
    strb r0, [r1, #5]
    b lbl_080822ae
    .align 2, 0
lbl_08082284: .4byte gBg0XPosition
lbl_08082288: .4byte gBg0YPosition
lbl_0808228c: .4byte sNonGameplayRamPointer
lbl_08082290: .4byte gWrittenToBLDY_NonGameplay
lbl_08082294:
    ldrb r1, [r2, #5]
    adds r0, r1, #1
    strb r0, [r2, #5]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080822ae
    ldr r1, lbl_080822c8 @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_080822ae
    adds r0, #1
    strh r0, [r1]
lbl_080822ae:
    ldr r0, lbl_080822cc @ =sNonGameplayRamPointer
    ldr r3, [r0]
    ldrb r5, [r3, #2]
    adds r6, r0, #0
    cmp r5, #0
    beq lbl_0808232c
    ldrh r1, [r3, #6]
    movs r0, #7
    ands r0, r1
    cmp r0, #3
    bhi lbl_080822d4
    ldr r0, lbl_080822d0 @ =0x0847a4e0
    b lbl_080822d6
    .align 2, 0
lbl_080822c8: .4byte gWrittenToBLDY_NonGameplay
lbl_080822cc: .4byte sNonGameplayRamPointer
lbl_080822d0: .4byte 0x0847a4e0
lbl_080822d4:
    ldr r0, lbl_080822e8 @ =0x0847a506
lbl_080822d6:
    str r0, [r3, #0x14]
    ldr r2, [r6]
    ldrh r1, [r2, #6]
    movs r0, #3
    ands r0, r1
    cmp r0, #1
    bhi lbl_080822f0
    ldr r0, lbl_080822ec @ =0x0847a52c
    b lbl_080822f2
    .align 2, 0
lbl_080822e8: .4byte 0x0847a506
lbl_080822ec: .4byte 0x0847a52c
lbl_080822f0:
    ldr r0, lbl_0808231c @ =0x0847a540
lbl_080822f2:
    str r0, [r2, #0x18]
    ldr r2, [r6]
    movs r1, #0x47
    adds r1, r1, r2
    mov ip, r1
    ldrb r0, [r1]
    cmp r0, #0xb
    bls lbl_08082324
    ldr r1, lbl_08082320 @ =gBg0XPosition
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    adds r2, #0x52
    ldrh r0, [r2]
    subs r0, #1
    movs r1, #0
    strh r0, [r2]
    mov r2, ip
    strb r1, [r2]
    b lbl_08082610
    .align 2, 0
lbl_0808231c: .4byte 0x0847a540
lbl_08082320: .4byte gBg0XPosition
lbl_08082324:
    adds r0, #1
    mov r1, ip
    strb r0, [r1]
    b lbl_08082610
lbl_0808232c:
    adds r4, r3, #0
    adds r4, #0x46
    ldr r2, lbl_08082624 @ =0x0847cbe4
    adds r0, r3, #0
    adds r0, #0x3c
    ldrb r0, [r0]
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r1, [r4]
    adds r7, r2, #0
    ldrb r0, [r0, #4]
    cmp r1, r0
    blo lbl_08082394
    strb r5, [r4]
    ldr r1, [r6]
    adds r1, #0x3c
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r6]
    adds r1, r0, #0
    adds r1, #0x3c
    ldrb r0, [r1]
    lsls r0, r0, #3
    adds r0, r0, r7
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08082394
    strb r0, [r1]
    ldr r2, [r6]
    ldrb r0, [r2, #8]
    adds r0, #1
    movs r1, #7
    ands r0, r1
    adds r0, #1
    strb r0, [r2, #8]
    ldr r4, [r6]
    ldrb r0, [r4, #8]
    subs r0, #1
    lsls r0, r0, #0x18
    ldr r2, lbl_08082628 @ =0x0847ced0
    lsrs r0, r0, #0x16
    adds r1, r0, r2
    ldrh r3, [r1]
    adds r1, r4, #0
    adds r1, #0x50
    strh r3, [r1]
    adds r2, #2
    adds r0, r0, r2
    ldrh r0, [r0]
    adds r4, #0x64
    strh r0, [r4]
lbl_08082394:
    ldr r0, [r6]
    adds r3, r0, #0
    adds r3, #0x47
    ldr r2, lbl_0808262c @ =0x0847cc64
    adds r0, #0x3d
    ldrb r0, [r0]
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r1, [r3]
    mov r8, r2
    ldrb r0, [r0, #4]
    cmp r1, r0
    blo lbl_080823fe
    movs r0, #0
    strb r0, [r3]
    ldr r1, [r6]
    adds r1, #0x3d
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r6]
    adds r1, r0, #0
    adds r1, #0x3d
    ldrb r0, [r1]
    lsls r0, r0, #3
    add r0, r8
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_080823fe
    strb r0, [r1]
    ldr r2, [r6]
    ldrb r0, [r2, #9]
    adds r0, #1
    movs r1, #7
    ands r0, r1
    adds r0, #1
    strb r0, [r2, #9]
    ldr r3, [r6]
    ldrb r0, [r3, #9]
    subs r0, #1
    lsls r0, r0, #0x18
    ldr r2, lbl_08082630 @ =0x0847cef0
    lsrs r0, r0, #0x16
    adds r1, r0, r2
    ldrh r1, [r1]
    adds r4, r3, #0
    adds r4, #0x52
    strh r1, [r4]
    adds r2, #2
    adds r0, r0, r2
    ldrh r0, [r0]
    adds r3, #0x66
    strh r0, [r3]
lbl_080823fe:
    ldr r0, [r6]
    adds r3, r0, #0
    adds r3, #0x48
    ldr r2, lbl_08082634 @ =0x0847ccbc
    adds r0, #0x3e
    ldrb r0, [r0]
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r1, [r3]
    adds r5, r2, #0
    ldrb r0, [r0, #4]
    cmp r1, r0
    blo lbl_08082468
    movs r0, #0
    strb r0, [r3]
    ldr r1, [r6]
    adds r1, #0x3e
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r6]
    adds r1, r0, #0
    adds r1, #0x3e
    ldrb r0, [r1]
    lsls r0, r0, #3
    adds r0, r0, r5
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08082468
    strb r0, [r1]
    ldr r2, [r6]
    ldrb r0, [r2, #0xa]
    adds r0, #1
    movs r1, #7
    ands r0, r1
    adds r0, #1
    strb r0, [r2, #0xa]
    ldr r4, [r6]
    ldrb r0, [r4, #0xa]
    subs r0, #1
    lsls r0, r0, #0x18
    ldr r2, lbl_08082638 @ =0x0847cf10
    lsrs r0, r0, #0x16
    adds r1, r0, r2
    ldrh r3, [r1]
    adds r1, r4, #0
    adds r1, #0x54
    strh r3, [r1]
    adds r2, #2
    adds r0, r0, r2
    ldrh r0, [r0]
    adds r4, #0x68
    strh r0, [r4]
lbl_08082468:
    ldr r0, [r6]
    adds r2, r0, #0
    adds r2, #0x49
    adds r0, #0x3f
    ldrb r0, [r0]
    lsls r0, r0, #3
    adds r0, r0, r7
    ldrb r1, [r2]
    ldrb r0, [r0, #4]
    cmp r1, r0
    blo lbl_080824ce
    movs r0, #0
    strb r0, [r2]
    ldr r1, [r6]
    adds r1, #0x3f
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r6]
    adds r1, r0, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    lsls r0, r0, #3
    adds r0, r0, r7
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_080824ce
    strb r0, [r1]
    ldr r2, [r6]
    ldrb r0, [r2, #0xb]
    adds r0, #1
    movs r1, #7
    ands r0, r1
    adds r0, #1
    strb r0, [r2, #0xb]
    ldr r3, [r6]
    ldrb r0, [r3, #0xb]
    subs r0, #1
    lsls r0, r0, #0x18
    ldr r2, lbl_0808263c @ =0x0847cf30
    lsrs r0, r0, #0x16
    adds r1, r0, r2
    ldrh r1, [r1]
    adds r4, r3, #0
    adds r4, #0x56
    strh r1, [r4]
    adds r2, #2
    adds r0, r0, r2
    ldrh r0, [r0]
    adds r3, #0x6a
    strh r0, [r3]
lbl_080824ce:
    ldr r1, [r6]
    adds r0, r1, #0
    adds r0, #0x3c
    ldrb r0, [r0]
    lsls r0, r0, #3
    adds r0, r0, r7
    ldr r0, [r0]
    str r0, [r1, #0x14]
    adds r0, r1, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    lsls r0, r0, #3
    add r0, r8
    ldr r0, [r0]
    str r0, [r1, #0x18]
    adds r0, r1, #0
    adds r0, #0x3e
    ldrb r0, [r0]
    lsls r0, r0, #3
    adds r0, r0, r5
    ldr r0, [r0]
    str r0, [r1, #0x1c]
    adds r0, r1, #0
    adds r0, #0x3f
    ldrb r0, [r0]
    lsls r0, r0, #3
    adds r0, r0, r7
    ldr r0, [r0]
    str r0, [r1, #0x20]
    adds r1, #0x46
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r1, [r6]
    adds r1, #0x47
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r1, [r6]
    adds r1, #0x48
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r1, [r6]
    adds r1, #0x49
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    movs r4, #4
    adds r5, r6, #0
    ldr r7, lbl_08082640 @ =0x0847cec0
lbl_08082534:
    ldr r0, [r5]
    adds r0, #0x46
    adds r1, r0, r4
    ldrb r0, [r1]
    cmp r0, #0xe
    bhi lbl_08082544
    adds r0, #1
    strb r0, [r1]
lbl_08082544:
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x46
    adds r0, r0, r4
    ldrb r0, [r0]
    lsrs r3, r0, #2
    lsls r0, r4, #2
    adds r1, r2, #0
    adds r1, #0x14
    adds r1, r1, r0
    lsls r0, r3, #2
    adds r0, r0, r7
    ldr r0, [r0]
    str r0, [r1]
    lsls r0, r4, #1
    adds r1, r2, #0
    adds r1, #0x64
    adds r1, r1, r0
    ldrh r0, [r1]
    adds r0, #4
    strh r0, [r1]
    adds r0, r4, #1
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #8
    bls lbl_08082534
    ldr r0, [r6]
    ldrh r0, [r0, #6]
    movs r4, #7
    ands r4, r0
    cmp r4, #1
    bne lbl_080825b4
    ldr r1, lbl_08082644 @ =gBg0XPosition
    ldrh r0, [r1]
    adds r0, #8
    strh r0, [r1]
    ldr r1, lbl_08082648 @ =gBg0YPosition
    ldrh r0, [r1]
    subs r0, #8
    strh r0, [r1]
    ldr r1, lbl_0808264c @ =gBg1XPosition
    ldrh r0, [r1]
    adds r0, #8
    strh r0, [r1]
    ldr r1, lbl_08082650 @ =gBg1YPosition
    ldrh r0, [r1]
    subs r0, #8
    strh r0, [r1]
    ldr r1, lbl_08082654 @ =gBg2XPosition
    ldrh r0, [r1]
    adds r0, #8
    strh r0, [r1]
    ldr r1, lbl_08082658 @ =gBg2YPosition
    ldrh r0, [r1]
    subs r0, #8
    strh r0, [r1]
lbl_080825b4:
    cmp r4, #3
    bne lbl_080825c8
    ldr r1, lbl_0808265c @ =gBg3XPosition
    ldrh r0, [r1]
    adds r0, #8
    strh r0, [r1]
    ldr r1, lbl_08082660 @ =gBg3YPosition
    ldrh r0, [r1]
    subs r0, #8
    strh r0, [r1]
lbl_080825c8:
    cmp r4, #4
    bne lbl_080825fc
    ldr r1, lbl_08082644 @ =gBg0XPosition
    ldrh r0, [r1]
    subs r0, #8
    strh r0, [r1]
    ldr r1, lbl_08082648 @ =gBg0YPosition
    ldrh r0, [r1]
    adds r0, #8
    strh r0, [r1]
    ldr r1, lbl_0808264c @ =gBg1XPosition
    ldrh r0, [r1]
    subs r0, #8
    strh r0, [r1]
    ldr r1, lbl_08082650 @ =gBg1YPosition
    ldrh r0, [r1]
    adds r0, #8
    strh r0, [r1]
    ldr r1, lbl_08082654 @ =gBg2XPosition
    ldrh r0, [r1]
    subs r0, #8
    strh r0, [r1]
    ldr r1, lbl_08082658 @ =gBg2YPosition
    ldrh r0, [r1]
    adds r0, #8
    strh r0, [r1]
lbl_080825fc:
    cmp r4, #6
    bne lbl_08082610
    ldr r1, lbl_0808265c @ =gBg3XPosition
    ldrh r0, [r1]
    subs r0, #8
    strh r0, [r1]
    ldr r1, lbl_08082660 @ =gBg3YPosition
    ldrh r0, [r1]
    adds r0, #8
    strh r0, [r1]
lbl_08082610:
    bl tourian_escape_process_oam
    mov r0, sb
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08082624: .4byte 0x0847cbe4
lbl_08082628: .4byte 0x0847ced0
lbl_0808262c: .4byte 0x0847cc64
lbl_08082630: .4byte 0x0847cef0
lbl_08082634: .4byte 0x0847ccbc
lbl_08082638: .4byte 0x0847cf10
lbl_0808263c: .4byte 0x0847cf30
lbl_08082640: .4byte 0x0847cec0
lbl_08082644: .4byte gBg0XPosition
lbl_08082648: .4byte gBg0YPosition
lbl_0808264c: .4byte gBg1XPosition
lbl_08082650: .4byte gBg1YPosition
lbl_08082654: .4byte gBg2XPosition
lbl_08082658: .4byte gBg2YPosition
lbl_0808265c: .4byte gBg3XPosition
lbl_08082660: .4byte gBg3YPosition

    thumb_func_start TourianEscapeSamusInHerShip
TourianEscapeSamusInHerShip: @ 0x08082664
    push {r4, r5, lr}
    movs r5, #0
    ldr r0, lbl_08082694 @ =sNonGameplayRamPointer
    ldr r3, [r0]
    ldrh r0, [r3, #6]
    adds r1, r0, #1
    strh r1, [r3, #6]
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0xa0
    bne lbl_0808267c
    b lbl_08082800
lbl_0808267c:
    cmp r1, #0xa0
    bgt lbl_080826a4
    cmp r1, #2
    beq lbl_080826ec
    cmp r1, #2
    bgt lbl_08082698
    cmp r1, #0
    beq lbl_080826d0
    cmp r1, #1
    beq lbl_080826d8
    b lbl_080828be
    .align 2, 0
lbl_08082694: .4byte sNonGameplayRamPointer
lbl_08082698:
    cmp r1, #3
    beq lbl_08082754
    cmp r1, #0x38
    bne lbl_080826a2
    b lbl_080827a0
lbl_080826a2:
    b lbl_080828be
lbl_080826a4:
    cmp r1, #0xc8
    bne lbl_080826aa
    b lbl_0808286c
lbl_080826aa:
    cmp r1, #0xc8
    bgt lbl_080826bc
    cmp r1, #0xa1
    bne lbl_080826b4
    b lbl_08082810
lbl_080826b4:
    cmp r1, #0xa2
    bne lbl_080826ba
    b lbl_08082850
lbl_080826ba:
    b lbl_080828be
lbl_080826bc:
    movs r0, #0xb0
    lsls r0, r0, #1
    cmp r1, r0
    bne lbl_080826c6
    b lbl_08082894
lbl_080826c6:
    adds r0, #0x14
    cmp r1, r0
    bne lbl_080826ce
    b lbl_080828a4
lbl_080826ce:
    b lbl_080828be
lbl_080826d0:
    ldr r0, lbl_080826d4 @ =0x08481ccc
    b lbl_08082802
    .align 2, 0
lbl_080826d4: .4byte 0x08481ccc
lbl_080826d8:
    ldr r0, lbl_080826e4 @ =0x0847d014
    ldr r1, lbl_080826e8 @ =0x06008000
    bl LZ77UncompVRAM
    b lbl_080828be
    .align 2, 0
lbl_080826e4: .4byte 0x0847d014
lbl_080826e8: .4byte 0x06008000
lbl_080826ec:
    ldr r0, lbl_08082718 @ =0x08484d5c
    ldr r1, lbl_0808271c @ =0x06007000
    bl LZ77UncompVRAM
    ldr r0, lbl_08082720 @ =0x0847f884
    ldr r1, lbl_08082724 @ =0x0600f000
    bl LZ77UncompVRAM
    ldr r0, lbl_08082728 @ =gEquipment
    ldrb r1, [r0, #0xf]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08082738
    ldr r1, lbl_0808272c @ =0x040000d4
    ldr r0, lbl_08082730 @ =0x084796c0
    str r0, [r1]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_08082734 @ =0x80000070
    b lbl_0808282e
    .align 2, 0
lbl_08082718: .4byte 0x08484d5c
lbl_0808271c: .4byte 0x06007000
lbl_08082720: .4byte 0x0847f884
lbl_08082724: .4byte 0x0600f000
lbl_08082728: .4byte gEquipment
lbl_0808272c: .4byte 0x040000d4
lbl_08082730: .4byte 0x084796c0
lbl_08082734: .4byte 0x80000070
lbl_08082738:
    ldr r1, lbl_08082748 @ =0x040000d4
    ldr r0, lbl_0808274c @ =0x084795e0
    str r0, [r1]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_08082750 @ =0x80000070
    b lbl_0808282e
    .align 2, 0
lbl_08082748: .4byte 0x040000d4
lbl_0808274c: .4byte 0x084795e0
lbl_08082750: .4byte 0x80000070
lbl_08082754:
    ldr r1, lbl_08082788 @ =0x04000008
    ldr r2, lbl_0808278c @ =0x00001e08
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    ldr r4, lbl_08082790 @ =0x00000e01
    adds r0, r4, #0
    strh r0, [r1]
    adds r1, r3, #0
    adds r1, #0xc0
    movs r0, #0x90
    lsls r0, r0, #5
    strh r0, [r1]
    adds r1, #2
    movs r0, #0xfc
    lsls r0, r0, #6
    strh r0, [r1]
    ldr r1, lbl_08082794 @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_08082798 @ =gWrittenToBLDALPHA_H
    strh r5, [r0]
    ldr r0, lbl_0808279c @ =gWrittenToBLDY_NonGameplay
    strh r5, [r0]
    b lbl_080828be
    .align 2, 0
lbl_08082788: .4byte 0x04000008
lbl_0808278c: .4byte 0x00001e08
lbl_08082790: .4byte 0x00000e01
lbl_08082794: .4byte gWrittenToBLDALPHA_L
lbl_08082798: .4byte gWrittenToBLDALPHA_H
lbl_0808279c: .4byte gWrittenToBLDY_NonGameplay
lbl_080827a0:
    adds r2, r3, #0
    adds r2, #0xc0
    ldrh r1, [r2]
    movs r4, #0x80
    lsls r4, r4, #6
    adds r0, r4, #0
    orrs r0, r1
    strh r0, [r2]
    adds r1, r3, #0
    adds r1, #0xc2
    movs r0, #0xbf
    strh r0, [r1]
    ldr r1, lbl_080827f4 @ =gWrittenToBLDY_NonGameplay
    movs r0, #0xa
    strh r0, [r1]
    ldr r1, lbl_080827f8 @ =0x04000048
    movs r0, #0x3f
    strh r0, [r1]
    adds r1, #2
    movs r0, #0x1f
    strh r0, [r1]
    adds r1, r3, #0
    adds r1, #0xc4
    movs r0, #0x77
    strh r0, [r1]
    adds r1, #2
    movs r0, #0x79
    strh r0, [r1]
    adds r1, #2
    movs r0, #0x4f
    strh r0, [r1]
    adds r1, #2
    movs r0, #0x51
    strh r0, [r1]
    ldrb r0, [r3, #2]
    adds r0, #1
    strb r0, [r3, #2]
    ldr r0, lbl_080827fc @ =0x00000245
    bl SoundPlay
    b lbl_080828be
    .align 2, 0
lbl_080827f4: .4byte gWrittenToBLDY_NonGameplay
lbl_080827f8: .4byte 0x04000048
lbl_080827fc: .4byte 0x00000245
lbl_08082800:
    ldr r0, lbl_0808280c @ =0x0848531c
lbl_08082802:
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    b lbl_080828be
    .align 2, 0
lbl_0808280c: .4byte 0x0848531c
lbl_08082810:
    ldr r0, lbl_08082834 @ =0x084895fc
    ldr r1, lbl_08082838 @ =0x06007000
    bl LZ77UncompVRAM
    ldr r0, lbl_0808283c @ =0x08489bbc
    ldr r1, lbl_08082840 @ =0x06007800
    bl LZ77UncompVRAM
    ldr r1, lbl_08082844 @ =0x040000d4
    ldr r0, lbl_08082848 @ =0x084797a0
    str r0, [r1]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_0808284c @ =0x80000080
lbl_0808282e:
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    b lbl_080828be
    .align 2, 0
lbl_08082834: .4byte 0x084895fc
lbl_08082838: .4byte 0x06007000
lbl_0808283c: .4byte 0x08489bbc
lbl_08082840: .4byte 0x06007800
lbl_08082844: .4byte 0x040000d4
lbl_08082848: .4byte 0x084797a0
lbl_0808284c: .4byte 0x80000080
lbl_08082850:
    adds r1, r3, #0
    adds r1, #0xc0
    movs r0, #0x98
    lsls r0, r0, #5
    strh r0, [r1]
    ldrb r0, [r3, #2]
    adds r0, #1
    strb r0, [r3, #2]
    ldr r0, lbl_08082868 @ =0x00000246
    bl SoundPlay
    b lbl_080828be
    .align 2, 0
lbl_08082868: .4byte 0x00000246
lbl_0808286c:
    adds r1, r3, #0
    adds r1, #0xc2
    ldr r0, lbl_08082888 @ =0x00000241
    strh r0, [r1]
    ldr r1, lbl_0808288c @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
    ldrb r0, [r3, #2]
    adds r0, #1
    strb r0, [r3, #2]
    ldr r0, lbl_08082890 @ =0x00000247
    bl SoundPlay
    b lbl_080828be
    .align 2, 0
lbl_08082888: .4byte 0x00000241
lbl_0808288c: .4byte gWrittenToBLDALPHA_L
lbl_08082890: .4byte 0x00000247
lbl_08082894:
    ldr r1, lbl_080828a0 @ =0x0400000a
    movs r2, #0xf0
    lsls r2, r2, #4
    adds r0, r2, #0
    strh r0, [r1]
    b lbl_080828be
    .align 2, 0
lbl_080828a0: .4byte 0x0400000a
lbl_080828a4:
    adds r0, r3, #0
    adds r0, #0xc0
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    ldr r1, lbl_080828ec @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_080828f0 @ =gWrittenToBLDALPHA_H
    strh r5, [r0]
    ldr r0, lbl_080828f4 @ =gWrittenToBLDY_NonGameplay
    strh r5, [r0]
    movs r5, #1
lbl_080828be:
    ldr r0, lbl_080828f8 @ =sNonGameplayRamPointer
    ldr r3, [r0]
    ldrb r2, [r3, #2]
    adds r4, r0, #0
    cmp r2, #1
    bne lbl_0808297c
    ldrb r0, [r3, #5]
    adds r1, r0, #1
    strb r1, [r3, #5]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x27
    bhi lbl_080828fc
    ldr r1, [r4]
    adds r2, r1, #0
    adds r2, #0xc8
    ldrh r0, [r2]
    subs r0, #3
    strh r0, [r2]
    adds r1, #0xca
    ldrh r0, [r1]
    adds r0, #3
    b lbl_0808290e
    .align 2, 0
lbl_080828ec: .4byte gWrittenToBLDALPHA_L
lbl_080828f0: .4byte gWrittenToBLDALPHA_H
lbl_080828f4: .4byte gWrittenToBLDY_NonGameplay
lbl_080828f8: .4byte sNonGameplayRamPointer
lbl_080828fc:
    ldr r1, [r4]
    adds r2, r1, #0
    adds r2, #0xc4
    ldrh r0, [r2]
    subs r0, #4
    strh r0, [r2]
    adds r1, #0xc6
    ldrh r0, [r1]
    adds r0, #4
lbl_0808290e:
    strh r0, [r1]
    adds r2, r4, #0
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc8
    movs r3, #0
    ldrsh r0, [r1, r3]
    cmp r0, #0
    bge lbl_08082924
    movs r0, #0
    strh r0, [r1]
lbl_08082924:
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xca
    movs r3, #0
    ldrsh r0, [r1, r3]
    cmp r0, #0xa0
    ble lbl_08082936
    movs r0, #0xa0
    strh r0, [r1]
lbl_08082936:
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc4
    movs r3, #0
    ldrsh r0, [r1, r3]
    cmp r0, #0
    bge lbl_08082948
    movs r0, #0
    strh r0, [r1]
lbl_08082948:
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc6
    movs r2, #0
    ldrsh r0, [r1, r2]
    cmp r0, #0xf0
    ble lbl_0808295a
    movs r0, #0xf0
    strh r0, [r1]
lbl_0808295a:
    ldr r0, [r4]
    ldrh r1, [r0, #6]
    cmp r1, #0x7f
    bls lbl_080829be
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080829be
    ldr r1, lbl_08082978 @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_080829be
    adds r0, #1
    strh r0, [r1]
    b lbl_080829be
    .align 2, 0
lbl_08082978: .4byte gWrittenToBLDY_NonGameplay
lbl_0808297c:
    cmp r2, #2
    bne lbl_0808299c
    ldrh r1, [r3, #6]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080829be
    ldr r1, lbl_08082998 @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_080829be
    subs r0, #1
    strh r0, [r1]
    b lbl_080829be
    .align 2, 0
lbl_08082998: .4byte gWrittenToBLDY_NonGameplay
lbl_0808299c:
    cmp r2, #0
    beq lbl_080829be
    ldrh r1, [r3, #6]
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_080829be
    ldr r1, lbl_080829c8 @ =gWrittenToBLDALPHA_L
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_080829be
    subs r0, #1
    strh r0, [r1]
    ldr r2, lbl_080829cc @ =gWrittenToBLDALPHA_H
    movs r1, #0x10
    subs r1, r1, r0
    strh r1, [r2]
lbl_080829be:
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080829c8: .4byte gWrittenToBLDALPHA_L
lbl_080829cc: .4byte gWrittenToBLDALPHA_H

    thumb_func_start TourianEscapeSamusLookingAround
TourianEscapeSamusLookingAround: @ 0x080829d0
    push {r4, r5, lr}
    movs r5, #0
    ldr r0, lbl_080829f4 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrh r0, [r2, #6]
    adds r1, r0, #1
    strh r1, [r2, #6]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x38
    bls lbl_080829e8
    b lbl_08082c1c
lbl_080829e8:
    lsls r0, r0, #2
    ldr r1, lbl_080829f8 @ =lbl_080829fc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080829f4: .4byte sNonGameplayRamPointer
lbl_080829f8: .4byte lbl_080829fc
lbl_080829fc: @ jump table
    .4byte lbl_08082ae0 @ case 0
    .4byte lbl_08082af0 @ case 1
    .4byte lbl_08082b58 @ case 2
    .4byte lbl_08082ba8 @ case 3
    .4byte lbl_08082c1c @ case 4
    .4byte lbl_08082c1c @ case 5
    .4byte lbl_08082c1c @ case 6
    .4byte lbl_08082c1c @ case 7
    .4byte lbl_08082c1c @ case 8
    .4byte lbl_08082c1c @ case 9
    .4byte lbl_08082c1c @ case 10
    .4byte lbl_08082c1c @ case 11
    .4byte lbl_08082c1c @ case 12
    .4byte lbl_08082c1c @ case 13
    .4byte lbl_08082c1c @ case 14
    .4byte lbl_08082c1c @ case 15
    .4byte lbl_08082bd4 @ case 16
    .4byte lbl_08082c1c @ case 17
    .4byte lbl_08082c1c @ case 18
    .4byte lbl_08082c1c @ case 19
    .4byte lbl_08082c1c @ case 20
    .4byte lbl_08082c1c @ case 21
    .4byte lbl_08082c1c @ case 22
    .4byte lbl_08082c1c @ case 23
    .4byte lbl_08082c1c @ case 24
    .4byte lbl_08082c1c @ case 25
    .4byte lbl_08082c1c @ case 26
    .4byte lbl_08082c1c @ case 27
    .4byte lbl_08082c1c @ case 28
    .4byte lbl_08082c1c @ case 29
    .4byte lbl_08082c1c @ case 30
    .4byte lbl_08082c1c @ case 31
    .4byte lbl_08082be4 @ case 32
    .4byte lbl_08082c1c @ case 33
    .4byte lbl_08082c1c @ case 34
    .4byte lbl_08082c1c @ case 35
    .4byte lbl_08082c1c @ case 36
    .4byte lbl_08082c1c @ case 37
    .4byte lbl_08082c1c @ case 38
    .4byte lbl_08082c1c @ case 39
    .4byte lbl_08082c1c @ case 40
    .4byte lbl_08082c1c @ case 41
    .4byte lbl_08082c1c @ case 42
    .4byte lbl_08082c1c @ case 43
    .4byte lbl_08082c1c @ case 44
    .4byte lbl_08082c1c @ case 45
    .4byte lbl_08082c1c @ case 46
    .4byte lbl_08082c1c @ case 47
    .4byte lbl_08082c1c @ case 48
    .4byte lbl_08082c1c @ case 49
    .4byte lbl_08082c1c @ case 50
    .4byte lbl_08082c1c @ case 51
    .4byte lbl_08082c1c @ case 52
    .4byte lbl_08082c1c @ case 53
    .4byte lbl_08082c1c @ case 54
    .4byte lbl_08082c1c @ case 55
    .4byte lbl_08082bf4 @ case 56
lbl_08082ae0:
    ldr r0, lbl_08082aec @ =0x08498028
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    b lbl_08082c1c
    .align 2, 0
lbl_08082aec: .4byte 0x08498028
lbl_08082af0:
    ldr r0, lbl_08082b3c @ =0x08498028
    ldr r1, lbl_08082b40 @ =0x06010000
    bl LZ77UncompVRAM
    ldr r0, lbl_08082b44 @ =gWrittenToBLDALPHA_L
    movs r1, #8
    strh r1, [r0]
    ldr r0, lbl_08082b48 @ =gWrittenToBLDALPHA_H
    strh r1, [r0]
    ldr r1, lbl_08082b4c @ =sNonGameplayRamPointer
    ldr r0, [r1]
    movs r4, #0
    movs r3, #1
    strb r3, [r0, #8]
    ldr r0, [r1]
    mov ip, r0
    ldr r0, lbl_08082b50 @ =0x0847a554
    mov r2, ip
    str r0, [r2, #0x14]
    mov r0, ip
    adds r0, #0x50
    movs r2, #0x80
    strh r2, [r0]
    adds r0, #0x14
    strh r4, [r0]
    mov r0, ip
    strb r3, [r0, #9]
    ldr r1, [r1]
    ldr r0, lbl_08082b54 @ =0x0847a56e
    str r0, [r1, #0x18]
    adds r0, r1, #0
    adds r0, #0x52
    strh r2, [r0]
    adds r1, #0x66
    movs r0, #0xa0
    strh r0, [r1]
    b lbl_08082c1c
    .align 2, 0
lbl_08082b3c: .4byte 0x08498028
lbl_08082b40: .4byte 0x06010000
lbl_08082b44: .4byte gWrittenToBLDALPHA_L
lbl_08082b48: .4byte gWrittenToBLDALPHA_H
lbl_08082b4c: .4byte sNonGameplayRamPointer
lbl_08082b50: .4byte 0x0847a554
lbl_08082b54: .4byte 0x0847a56e
lbl_08082b58:
    ldr r0, lbl_08082b88 @ =0x0849c010
    ldr r1, lbl_08082b8c @ =0x06008000
    bl LZ77UncompVRAM
    ldr r0, lbl_08082b90 @ =0x0849c5d0
    ldr r1, lbl_08082b94 @ =0x06008800
    bl LZ77UncompVRAM
    ldr r0, lbl_08082b98 @ =0x040000d4
    ldr r3, lbl_08082b9c @ =0x084798a0
    str r3, [r0]
    movs r1, #0xa0
    lsls r1, r1, #0x13
    str r1, [r0, #4]
    ldr r2, lbl_08082ba0 @ =0x80000070
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    str r3, [r0]
    ldr r1, lbl_08082ba4 @ =0x05000200
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    b lbl_08082c1c
    .align 2, 0
lbl_08082b88: .4byte 0x0849c010
lbl_08082b8c: .4byte 0x06008000
lbl_08082b90: .4byte 0x0849c5d0
lbl_08082b94: .4byte 0x06008800
lbl_08082b98: .4byte 0x040000d4
lbl_08082b9c: .4byte 0x084798a0
lbl_08082ba0: .4byte 0x80000070
lbl_08082ba4: .4byte 0x05000200
lbl_08082ba8:
    ldr r1, lbl_08082bcc @ =0x04000008
    movs r2, #0x80
    lsls r2, r2, #5
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_08082bd0 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r2, r1, #0
    adds r2, #0xc0
    movs r0, #0x88
    lsls r0, r0, #5
    strh r0, [r2]
    adds r1, #0xc2
    movs r0, #0xa8
    lsls r0, r0, #1
    strh r0, [r1]
    b lbl_08082c1c
    .align 2, 0
lbl_08082bcc: .4byte 0x04000008
lbl_08082bd0: .4byte sNonGameplayRamPointer
lbl_08082bd4:
    ldr r0, lbl_08082be0 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrb r0, [r1, #2]
    adds r0, #1
    strb r0, [r1, #2]
    b lbl_08082c1c
    .align 2, 0
lbl_08082be0: .4byte sNonGameplayRamPointer
lbl_08082be4:
    ldr r1, lbl_08082bf0 @ =0x04000008
    movs r2, #0x88
    lsls r2, r2, #5
    adds r0, r2, #0
    strh r0, [r1]
    b lbl_08082c1c
    .align 2, 0
lbl_08082bf0: .4byte 0x04000008
lbl_08082bf4:
    ldr r0, lbl_08082c48 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r2, r0, #0
    adds r2, #0xc0
    movs r1, #0
    strh r1, [r2]
    adds r0, #0xc2
    strh r1, [r0]
    ldr r0, lbl_08082c4c @ =gBg2Rotation
    strh r1, [r0]
    ldr r0, lbl_08082c50 @ =gBg2Scaling
    movs r2, #0xc0
    lsls r2, r2, #3
    adds r1, r2, #0
    strh r1, [r0]
    ldr r0, lbl_08082c54 @ =gUnk_30013a2
    strh r1, [r0]
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_08082c1c:
    ldr r0, lbl_08082c48 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrb r0, [r1, #2]
    cmp r0, #0
    beq lbl_08082c3c
    adds r2, r1, #0
    adds r2, #0x64
    ldrh r0, [r2]
    cmp r0, #0x4f
    bhi lbl_08082c3c
    adds r0, #8
    strh r0, [r2]
    adds r1, #0x66
    ldrh r0, [r1]
    subs r0, #8
    strh r0, [r1]
lbl_08082c3c:
    bl tourian_escape_process_oam
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08082c48: .4byte sNonGameplayRamPointer
lbl_08082c4c: .4byte gBg2Rotation
lbl_08082c50: .4byte gBg2Scaling
lbl_08082c54: .4byte gUnk_30013a2

    thumb_func_start TourianEscapeSamusSurrounded
TourianEscapeSamusSurrounded: @ 0x08082c58
    push {r4, r5, lr}
    movs r5, #0
    ldr r0, lbl_08082c80 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrh r0, [r2, #6]
    adds r1, r0, #1
    strh r1, [r2, #6]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #3
    beq lbl_08082d20
    cmp r0, #3
    bgt lbl_08082c84
    cmp r0, #1
    beq lbl_08082ca8
    cmp r0, #1
    bgt lbl_08082cbc
    cmp r0, #0
    beq lbl_08082c98
    b lbl_08082d86
    .align 2, 0
lbl_08082c80: .4byte sNonGameplayRamPointer
lbl_08082c84:
    cmp r0, #0x20
    beq lbl_08082d6c
    cmp r0, #0x20
    bgt lbl_08082c92
    cmp r0, #4
    beq lbl_08082d38
    b lbl_08082d86
lbl_08082c92:
    cmp r0, #0x70
    beq lbl_08082d74
    b lbl_08082d86
lbl_08082c98:
    ldr r0, lbl_08082ca4 @ =0x08495308
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    b lbl_08082d86
    .align 2, 0
lbl_08082ca4: .4byte 0x08495308
lbl_08082ca8:
    ldr r0, lbl_08082cb4 @ =0x0849cb90
    ldr r1, lbl_08082cb8 @ =0x06008000
    bl LZ77UncompVRAM
    b lbl_08082d86
    .align 2, 0
lbl_08082cb4: .4byte 0x0849cb90
lbl_08082cb8: .4byte 0x06008000
lbl_08082cbc:
    ldr r0, lbl_08082cf4 @ =0x0849778c
    ldr r1, lbl_08082cf8 @ =0x06007000
    bl LZ77UncompVRAM
    ldr r0, lbl_08082cfc @ =0x0849fb70
    ldr r1, lbl_08082d00 @ =0x06007800
    bl LZ77UncompVRAM
    ldr r1, lbl_08082d04 @ =0x040000d4
    ldr r0, lbl_08082d08 @ =0x08479ac0
    str r0, [r1]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_08082d0c @ =0x80000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, lbl_08082d10 @ =gBg0XPosition
    strh r5, [r0]
    ldr r0, lbl_08082d14 @ =gBg0YPosition
    strh r5, [r0]
    ldr r1, lbl_08082d18 @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_08082d1c @ =gWrittenToBLDALPHA_H
    strh r5, [r0]
    b lbl_08082d86
    .align 2, 0
lbl_08082cf4: .4byte 0x0849778c
lbl_08082cf8: .4byte 0x06007000
lbl_08082cfc: .4byte 0x0849fb70
lbl_08082d00: .4byte 0x06007800
lbl_08082d04: .4byte 0x040000d4
lbl_08082d08: .4byte 0x08479ac0
lbl_08082d0c: .4byte 0x80000100
lbl_08082d10: .4byte gBg0XPosition
lbl_08082d14: .4byte gBg0YPosition
lbl_08082d18: .4byte gWrittenToBLDALPHA_L
lbl_08082d1c: .4byte gWrittenToBLDALPHA_H
lbl_08082d20:
    ldr r4, lbl_08082d30 @ =0x04000208
    strh r5, [r4]
    ldr r0, lbl_08082d34 @ =sub_08081418
    bl CallbackSetVBlank
    movs r0, #1
    strh r0, [r4]
    b lbl_08082d86
    .align 2, 0
lbl_08082d30: .4byte 0x04000208
lbl_08082d34: .4byte sub_08081418
lbl_08082d38:
    ldr r1, lbl_08082d5c @ =0x04000008
    ldr r3, lbl_08082d60 @ =0x00000e01
    adds r0, r3, #0
    strh r0, [r1]
    adds r1, #2
    adds r3, #1
    adds r0, r3, #0
    strh r0, [r1]
    adds r1, #2
    ldr r3, lbl_08082d64 @ =0x00004f88
    adds r0, r3, #0
    strh r0, [r1]
    adds r1, r2, #0
    adds r1, #0xc0
    ldr r0, lbl_08082d68 @ =0x00001501
    strh r0, [r1]
    b lbl_08082d86
    .align 2, 0
lbl_08082d5c: .4byte 0x04000008
lbl_08082d60: .4byte 0x00000e01
lbl_08082d64: .4byte 0x00004f88
lbl_08082d68: .4byte 0x00001501
lbl_08082d6c:
    ldrb r0, [r2, #2]
    adds r0, #1
    strb r0, [r2, #2]
    b lbl_08082d86
lbl_08082d74:
    adds r0, r2, #0
    adds r0, #0xc0
    strh r5, [r0]
    adds r1, r2, #0
    adds r1, #0xc2
    movs r0, #0xfc
    lsls r0, r0, #6
    strh r0, [r1]
    movs r5, #1
lbl_08082d86:
    ldr r0, lbl_08082dac @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrb r0, [r0, #2]
    cmp r0, #0
    beq lbl_08082dbe
    ldr r2, lbl_08082db0 @ =gBg2Scaling
    ldrh r0, [r2]
    movs r1, #0x80
    lsls r1, r1, #1
    cmp r0, r1
    bls lbl_08082db8
    subs r0, #0x50
    strh r0, [r2]
    ldr r1, lbl_08082db4 @ =gUnk_30013a2
    ldrh r0, [r1]
    subs r0, #0x50
    strh r0, [r1]
    b lbl_08082dbe
    .align 2, 0
lbl_08082dac: .4byte sNonGameplayRamPointer
lbl_08082db0: .4byte gBg2Scaling
lbl_08082db4: .4byte gUnk_30013a2
lbl_08082db8:
    strh r1, [r2]
    ldr r0, lbl_08082dcc @ =gUnk_30013a2
    strh r1, [r0]
lbl_08082dbe:
    bl TourianEscapeSamusSurrounded_calculate_bg2_pos
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08082dcc: .4byte gUnk_30013a2

    thumb_func_start TourianEscapeSamusFlyingIn
TourianEscapeSamusFlyingIn: @ 0x08082dd0
    push {r4, r5, lr}
    movs r5, #0
    ldr r4, lbl_08082df0 @ =sNonGameplayRamPointer
    ldr r2, [r4]
    ldrh r0, [r2, #6]
    adds r1, r0, #1
    strh r1, [r2, #6]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #1
    beq lbl_08082e30
    cmp r0, #1
    bgt lbl_08082df4
    cmp r0, #0
    beq lbl_08082dfe
    b lbl_08082edc
    .align 2, 0
lbl_08082df0: .4byte sNonGameplayRamPointer
lbl_08082df4:
    cmp r0, #2
    beq lbl_08082e40
    cmp r0, #0x20
    beq lbl_08082ed0
    b lbl_08082edc
lbl_08082dfe:
    ldr r4, lbl_08082e1c @ =0x04000208
    strh r5, [r4]
    ldr r0, lbl_08082e20 @ =sub_08081320
    bl CallbackSetVBlank
    movs r0, #1
    strh r0, [r4]
    ldr r0, lbl_08082e24 @ =0x0845fdb4
    ldr r1, lbl_08082e28 @ =0x06010000
    bl LZ77UncompVRAM
    ldr r0, lbl_08082e2c @ =0x00000235
    bl SoundPlay
    b lbl_08082edc
    .align 2, 0
lbl_08082e1c: .4byte 0x04000208
lbl_08082e20: .4byte sub_08081320
lbl_08082e24: .4byte 0x0845fdb4
lbl_08082e28: .4byte 0x06010000
lbl_08082e2c: .4byte 0x00000235
lbl_08082e30:
    ldr r0, lbl_08082e3c @ =0x0846122c
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    b lbl_08082edc
    .align 2, 0
lbl_08082e3c: .4byte 0x0846122c
lbl_08082e40:
    ldr r0, lbl_08082eac @ =0x084643e0
    ldr r1, lbl_08082eb0 @ =0x0600f000
    bl LZ77UncompVRAM
    ldr r0, lbl_08082eb4 @ =0x040000d4
    ldr r3, lbl_08082eb8 @ =0x0845f914
    str r3, [r0]
    movs r1, #0xa0
    lsls r1, r1, #0x13
    str r1, [r0, #4]
    ldr r2, lbl_08082ebc @ =0x80000070
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    str r3, [r0]
    ldr r1, lbl_08082ec0 @ =0x05000200
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    ldr r1, lbl_08082ec4 @ =0x04000008
    movs r2, #0xf0
    lsls r2, r2, #5
    adds r0, r2, #0
    strh r0, [r1]
    ldr r2, [r4]
    adds r1, r2, #0
    adds r1, #0xc0
    movs r3, #0
    movs r0, #0x88
    lsls r0, r0, #5
    strh r0, [r1]
    ldr r1, lbl_08082ec8 @ =gWrittenToBLDALPHA_L
    movs r0, #9
    strh r0, [r1]
    ldr r1, lbl_08082ecc @ =gWrittenToBLDALPHA_H
    movs r0, #7
    strh r0, [r1]
    movs r0, #1
    strb r0, [r2, #8]
    ldr r2, [r4]
    adds r1, r2, #0
    adds r1, #0x82
    movs r0, #0x20
    strh r0, [r1]
    subs r1, #0x32
    movs r0, #0x78
    strh r0, [r1]
    adds r1, #0x14
    movs r0, #0x1c
    strh r0, [r1]
    adds r0, r2, #0
    adds r0, #0x46
    strb r3, [r0]
    b lbl_08082edc
    .align 2, 0
lbl_08082eac: .4byte 0x084643e0
lbl_08082eb0: .4byte 0x0600f000
lbl_08082eb4: .4byte 0x040000d4
lbl_08082eb8: .4byte 0x0845f914
lbl_08082ebc: .4byte 0x80000070
lbl_08082ec0: .4byte 0x05000200
lbl_08082ec4: .4byte 0x04000008
lbl_08082ec8: .4byte gWrittenToBLDALPHA_L
lbl_08082ecc: .4byte gWrittenToBLDALPHA_H
lbl_08082ed0:
    adds r0, r2, #0
    adds r0, #0xc0
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    movs r5, #1
lbl_08082edc:
    ldr r0, lbl_08082efc @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrb r1, [r2, #8]
    adds r4, r0, #0
    cmp r1, #0
    beq lbl_08082f8e
    adds r0, r2, #0
    adds r0, #0x46
    ldrb r0, [r0]
    cmp r0, #3
    bhi lbl_08082f00
    adds r1, r2, #0
    adds r1, #0x64
    ldrh r0, [r1]
    adds r0, #8
    b lbl_08082f36
    .align 2, 0
lbl_08082efc: .4byte sNonGameplayRamPointer
lbl_08082f00:
    cmp r0, #7
    bhi lbl_08082f0e
    adds r1, r2, #0
    adds r1, #0x64
    ldrh r0, [r1]
    adds r0, #6
    b lbl_08082f36
lbl_08082f0e:
    cmp r0, #0xf
    bhi lbl_08082f1c
    adds r1, r2, #0
    adds r1, #0x64
    ldrh r0, [r1]
    adds r0, #3
    b lbl_08082f36
lbl_08082f1c:
    cmp r0, #0x13
    bhi lbl_08082f2a
    adds r1, r2, #0
    adds r1, #0x64
    ldrh r0, [r1]
    adds r0, #1
    b lbl_08082f36
lbl_08082f2a:
    cmp r0, #0x1b
    bhi lbl_08082f38
    adds r1, r2, #0
    adds r1, #0x64
    ldrh r0, [r1]
    subs r0, #1
lbl_08082f36:
    strh r0, [r1]
lbl_08082f38:
    ldr r0, [r4]
    adds r3, r0, #0
    adds r3, #0x82
    ldrh r2, [r3]
    adds r1, r2, #0
    cmp r1, #0x7f
    bhi lbl_08082f4c
    adds r0, r2, #0
    adds r0, #8
    b lbl_08082f66
lbl_08082f4c:
    ldr r0, lbl_08082f58 @ =0x0000013f
    cmp r1, r0
    bhi lbl_08082f5c
    adds r0, r2, #0
    adds r0, #0x10
    b lbl_08082f66
    .align 2, 0
lbl_08082f58: .4byte 0x0000013f
lbl_08082f5c:
    ldr r0, lbl_08082f80 @ =0x000001df
    cmp r1, r0
    bhi lbl_08082f68
    adds r0, r2, #0
    adds r0, #0x20
lbl_08082f66:
    strh r0, [r3]
lbl_08082f68:
    ldr r0, [r4]
    adds r0, #0x46
    ldrb r2, [r0]
    adds r1, r2, #1
    strb r1, [r0]
    movs r0, #7
    ands r0, r2
    cmp r0, #3
    bhi lbl_08082f88
    ldr r1, [r4]
    ldr r0, lbl_08082f84 @ =0x0845f758
    b lbl_08082f8c
    .align 2, 0
lbl_08082f80: .4byte 0x000001df
lbl_08082f84: .4byte 0x0845f758
lbl_08082f88:
    ldr r1, [r4]
    ldr r0, lbl_08082f9c @ =0x0845f77e
lbl_08082f8c:
    str r0, [r1, #0x14]
lbl_08082f8e:
    bl sub_080818cc
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08082f9c: .4byte 0x0845f77e

    thumb_func_start TourianEscapeSamusChasedByPirates
TourianEscapeSamusChasedByPirates: @ 0x08082fa0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    movs r7, #0
    ldr r5, lbl_08082fd8 @ =sNonGameplayRamPointer
    ldr r2, [r5]
    ldrh r0, [r2, #6]
    adds r1, r0, #1
    strh r1, [r2, #6]
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0x77
    bne lbl_08082fbc
    b lbl_08083298
lbl_08082fbc:
    cmp r1, #0x77
    bgt lbl_08082ffc
    cmp r1, #3
    bne lbl_08082fc6
    b lbl_08083204
lbl_08082fc6:
    cmp r1, #3
    bgt lbl_08082fdc
    cmp r1, #1
    beq lbl_0808305c
    cmp r1, #1
    bgt lbl_08083070
    cmp r1, #0
    beq lbl_0808304a
    b lbl_080832fc
    .align 2, 0
lbl_08082fd8: .4byte sNonGameplayRamPointer
lbl_08082fdc:
    cmp r1, #0x40
    bne lbl_08082fe2
    b lbl_08083230
lbl_08082fe2:
    cmp r1, #0x40
    bgt lbl_08082fee
    cmp r1, #0x28
    bne lbl_08082fec
    b lbl_08083220
lbl_08082fec:
    b lbl_080832fc
lbl_08082fee:
    cmp r1, #0x48
    bne lbl_08082ff4
    b lbl_08083248
lbl_08082ff4:
    cmp r1, #0x74
    bne lbl_08082ffa
    b lbl_0808325a
lbl_08082ffa:
    b lbl_080832fc
lbl_08082ffc:
    cmp r1, #0xb8
    bne lbl_08083002
    b lbl_080832de
lbl_08083002:
    cmp r1, #0xb8
    bgt lbl_08083026
    cmp r1, #0xb0
    bne lbl_0808300c
    b lbl_080832c6
lbl_0808300c:
    cmp r1, #0xb0
    bgt lbl_08083018
    cmp r1, #0xa0
    bne lbl_08083016
    b lbl_080832b8
lbl_08083016:
    b lbl_080832fc
lbl_08083018:
    cmp r1, #0xb1
    bne lbl_0808301e
    b lbl_080832e4
lbl_0808301e:
    cmp r1, #0xb6
    bne lbl_08083024
    b lbl_080832d8
lbl_08083024:
    b lbl_080832fc
lbl_08083026:
    cmp r1, #0xc6
    bne lbl_0808302c
    b lbl_080832ec
lbl_0808302c:
    cmp r1, #0xc6
    bgt lbl_08083038
    cmp r1, #0xc0
    bne lbl_08083036
    b lbl_080832e8
lbl_08083036:
    b lbl_080832fc
lbl_08083038:
    cmp r1, #0xc8
    bne lbl_0808303e
    b lbl_080832f0
lbl_0808303e:
    movs r0, #0x80
    lsls r0, r0, #1
    cmp r1, r0
    bne lbl_08083048
    b lbl_080832f4
lbl_08083048:
    b lbl_080832fc
lbl_0808304a:
    ldr r0, lbl_08083058 @ =0x0848f48c
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    b lbl_080832fc
    .align 2, 0
lbl_08083058: .4byte 0x0848f48c
lbl_0808305c:
    ldr r0, lbl_08083068 @ =0x0849fd34
    ldr r1, lbl_0808306c @ =0x06010000
    bl LZ77UncompVRAM
    b lbl_080832fc
    .align 2, 0
lbl_08083068: .4byte 0x0849fd34
lbl_0808306c: .4byte 0x06010000
lbl_08083070:
    ldr r0, lbl_080831c4 @ =0x08494a04
    ldr r1, lbl_080831c8 @ =0x0600e000
    bl LZ77UncompVRAM
    ldr r1, lbl_080831cc @ =0x040000d4
    ldr r0, lbl_080831d0 @ =0x08479980
    str r0, [r1]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_080831d4 @ =0x80000050
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, lbl_080831d8 @ =0x08479cc0
    str r0, [r1]
    ldr r0, lbl_080831dc @ =0x05000200
    str r0, [r1, #4]
    ldr r0, lbl_080831e0 @ =0x80000060
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, [r5]
    strb r7, [r0, #8]
    ldr r3, [r5]
    ldr r0, lbl_080831e4 @ =0x0847a602
    str r0, [r3, #0x14]
    adds r0, r3, #0
    adds r0, #0x50
    movs r2, #0
    movs r1, #0xdc
    strh r1, [r0]
    adds r0, #0x14
    strh r1, [r0]
    adds r0, #0x14
    strb r2, [r0]
    ldr r0, [r5]
    strb r2, [r0, #9]
    ldr r1, [r5]
    ldr r0, lbl_080831e8 @ =0x0847a622
    str r0, [r1, #0x18]
    adds r3, r1, #0
    adds r3, #0x52
    movs r0, #0x80
    lsls r0, r0, #1
    strh r0, [r3]
    adds r0, r1, #0
    adds r0, #0x66
    movs r3, #0xf0
    strh r3, [r0]
    adds r0, #0x13
    strb r2, [r0]
    ldr r0, [r5]
    strb r2, [r0, #0xa]
    ldr r4, [r5]
    ldr r0, lbl_080831ec @ =0x0847a642
    str r0, [r4, #0x1c]
    adds r1, r4, #0
    adds r1, #0x54
    movs r0, #0xb4
    strh r0, [r1]
    adds r0, r4, #0
    adds r0, #0x68
    strh r3, [r0]
    adds r0, #0x12
    strb r2, [r0]
    ldr r0, [r5]
    strb r2, [r0, #0xb]
    ldr r1, [r5]
    ldr r0, lbl_080831f0 @ =0x0847a662
    str r0, [r1, #0x20]
    adds r3, r1, #0
    adds r3, #0x56
    movs r0, #0xd4
    strh r0, [r3]
    adds r3, #0x14
    movs r0, #0xbe
    strh r0, [r3]
    adds r0, r1, #0
    adds r0, #0x7b
    strb r2, [r0]
    ldr r0, [r5]
    movs r3, #1
    strb r3, [r0, #0xc]
    ldr r0, [r5]
    adds r0, #0x40
    strb r2, [r0]
    ldr r0, [r5]
    movs r2, #2
    strb r2, [r0, #0xd]
    ldr r0, [r5]
    adds r0, #0x41
    movs r1, #6
    strb r1, [r0]
    ldr r0, [r5]
    strb r3, [r0, #0xe]
    ldr r0, [r5]
    adds r0, #0x42
    movs r1, #0xe
    strb r1, [r0]
    ldr r0, [r5]
    strb r3, [r0, #0xf]
    ldr r0, [r5]
    adds r0, #0x43
    movs r1, #9
    strb r1, [r0]
    ldr r0, [r5]
    strb r2, [r0, #0x10]
    ldr r0, [r5]
    adds r0, #0x44
    movs r1, #3
    strb r1, [r0]
    ldr r0, [r5]
    strb r2, [r0, #0x11]
    ldr r0, [r5]
    adds r0, #0x45
    movs r1, #0xb
    strb r1, [r0]
    movs r5, #4
    ldr r6, lbl_080831f4 @ =0x0847ce20
    adds r0, r6, #4
    mov r8, r0
lbl_08083160:
    ldr r0, lbl_080831f8 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    mov ip, r0
    lsls r4, r5, #1
    mov r2, ip
    adds r2, #0x50
    adds r2, r2, r4
    mov r3, ip
    adds r3, #0x3c
    adds r3, r3, r5
    ldrb r1, [r3]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r6
    ldrh r0, [r0]
    strh r0, [r2]
    mov r2, ip
    adds r2, #0x64
    adds r2, r2, r4
    ldrb r1, [r3]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r1, r6, #2
    adds r0, r0, r1
    ldrh r0, [r0]
    strh r0, [r2]
    mov r2, ip
    adds r2, #0x96
    adds r2, r2, r4
    ldrb r1, [r3]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    add r0, r8
    ldrh r0, [r0]
    strh r0, [r2]
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #9
    bls lbl_08083160
    ldr r0, lbl_080831fc @ =gBg0XPosition
    movs r1, #0
    strh r1, [r0]
    ldr r0, lbl_08083200 @ =gBg0YPosition
    strh r1, [r0]
    b lbl_080832fc
    .align 2, 0
lbl_080831c4: .4byte 0x08494a04
lbl_080831c8: .4byte 0x0600e000
lbl_080831cc: .4byte 0x040000d4
lbl_080831d0: .4byte 0x08479980
lbl_080831d4: .4byte 0x80000050
lbl_080831d8: .4byte 0x08479cc0
lbl_080831dc: .4byte 0x05000200
lbl_080831e0: .4byte 0x80000060
lbl_080831e4: .4byte 0x0847a602
lbl_080831e8: .4byte 0x0847a622
lbl_080831ec: .4byte 0x0847a642
lbl_080831f0: .4byte 0x0847a662
lbl_080831f4: .4byte 0x0847ce20
lbl_080831f8: .4byte sNonGameplayRamPointer
lbl_080831fc: .4byte gBg0XPosition
lbl_08083200: .4byte gBg0YPosition
lbl_08083204:
    ldr r1, lbl_0808321c @ =0x04000008
    movs r3, #0xe0
    lsls r3, r3, #5
    adds r0, r3, #0
    strh r0, [r1]
    adds r1, r2, #0
    adds r1, #0xc0
    movs r0, #0x88
    lsls r0, r0, #5
    strh r0, [r1]
    b lbl_080832fc
    .align 2, 0
lbl_0808321c: .4byte 0x04000008
lbl_08083220:
    movs r0, #1
    strb r0, [r2, #8]
    ldr r0, lbl_0808322c @ =0x00000236
    bl SoundPlay
    b lbl_080832fc
    .align 2, 0
lbl_0808322c: .4byte 0x00000236
lbl_08083230:
    movs r1, #1
    strb r1, [r2, #9]
    ldr r0, [r5]
    strb r1, [r0, #0xa]
    ldr r0, [r5]
    strb r1, [r0, #0xb]
    ldr r0, lbl_08083244 @ =0x00000237
    bl SoundPlay
    b lbl_080832fc
    .align 2, 0
lbl_08083244: .4byte 0x00000237
lbl_08083248:
    strb r7, [r2, #8]
    ldr r1, [r5]
    adds r2, r1, #0
    adds r2, #0x50
    movs r0, #0xe8
    lsls r0, r0, #1
    strh r0, [r2]
    adds r1, #0x64
    b lbl_080832ac
lbl_0808325a:
    strb r7, [r2, #9]
    ldr r2, [r5]
    ldr r0, lbl_08083290 @ =0x0847a5d4
    str r0, [r2, #0x18]
    adds r3, r2, #0
    adds r3, #0x52
    movs r1, #0
    movs r0, #0xd8
    lsls r0, r0, #1
    strh r0, [r3]
    adds r0, r2, #0
    adds r0, #0x66
    movs r3, #0xe0
    strh r3, [r0]
    strb r1, [r2, #0xa]
    ldr r1, [r5]
    ldr r0, lbl_08083294 @ =0x0847a5f4
    str r0, [r1, #0x1c]
    adds r2, r1, #0
    adds r2, #0x54
    movs r0, #0xf8
    lsls r0, r0, #1
    strh r0, [r2]
    adds r1, #0x68
    strh r3, [r1]
    b lbl_080832fc
    .align 2, 0
lbl_08083290: .4byte 0x0847a5d4
lbl_08083294: .4byte 0x0847a5f4
lbl_08083298:
    strb r7, [r2, #0xb]
    ldr r1, [r5]
    ldr r0, lbl_080832b4 @ =0x0847a5f4
    str r0, [r1, #0x20]
    adds r2, r1, #0
    adds r2, #0x56
    movs r0, #0xd8
    lsls r0, r0, #1
    strh r0, [r2]
    adds r1, #0x6a
lbl_080832ac:
    movs r0, #0xe0
    strh r0, [r1]
    b lbl_080832fc
    .align 2, 0
lbl_080832b4: .4byte 0x0847a5f4
lbl_080832b8:
    movs r0, #2
    strb r0, [r2, #8]
    movs r0, #0x8e
    lsls r0, r0, #2
    bl SoundPlay
    b lbl_080832fc
lbl_080832c6:
    movs r0, #2
    strb r0, [r2, #9]
    ldr r0, lbl_080832d4 @ =0x00000239
    bl SoundPlay
    b lbl_080832fc
    .align 2, 0
lbl_080832d4: .4byte 0x00000239
lbl_080832d8:
    movs r0, #2
    strb r0, [r2, #0xa]
    b lbl_080832fc
lbl_080832de:
    movs r0, #2
    strb r0, [r2, #0xb]
    b lbl_080832fc
lbl_080832e4:
    strb r7, [r2, #8]
    b lbl_080832fc
lbl_080832e8:
    strb r7, [r2, #9]
    b lbl_080832fc
lbl_080832ec:
    strb r7, [r2, #0xa]
    b lbl_080832fc
lbl_080832f0:
    strb r7, [r2, #0xb]
    b lbl_080832fc
lbl_080832f4:
    adds r0, r2, #0
    adds r0, #0xc0
    strh r7, [r0]
    movs r7, #1
lbl_080832fc:
    ldr r2, lbl_08083340 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    ldrh r1, [r0, #6]
    movs r0, #7
    ands r0, r1
    adds r4, r2, #0
    cmp r0, #0
    bne lbl_08083314
    ldr r1, lbl_08083344 @ =gBg0XPosition
    ldrh r0, [r1]
    subs r0, #1
    strh r0, [r1]
lbl_08083314:
    movs r5, #0
lbl_08083316:
    ldr r3, [r4]
    adds r0, r3, #0
    adds r0, #8
    adds r0, r0, r5
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_08083348
    lsls r2, r5, #1
    adds r1, r3, #0
    adds r1, #0x50
    adds r1, r1, r2
    ldrh r0, [r1]
    subs r0, #6
    strh r0, [r1]
    adds r1, r3, #0
    adds r1, #0x64
    adds r1, r1, r2
    ldrh r0, [r1]
    adds r0, #6
    b lbl_08083364
    .align 2, 0
lbl_08083340: .4byte sNonGameplayRamPointer
lbl_08083344: .4byte gBg0XPosition
lbl_08083348:
    cmp r0, #2
    bne lbl_08083366
    lsls r2, r5, #1
    adds r1, r3, #0
    adds r1, #0x50
    adds r1, r1, r2
    ldrh r0, [r1]
    adds r0, #0xe
    strh r0, [r1]
    adds r1, r3, #0
    adds r1, #0x64
    adds r1, r1, r2
    ldrh r0, [r1]
    subs r0, #0xe
lbl_08083364:
    strh r0, [r1]
lbl_08083366:
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #3
    bls lbl_08083316
    ldr r0, [r4]
    ldrb r0, [r0, #0xc]
    cmp r0, #0
    beq lbl_0808337e
    movs r0, #0
    bl sub_08081788
lbl_0808337e:
    ldr r2, [r4]
    ldrb r0, [r2, #8]
    cmp r0, #2
    bne lbl_080833ac
    adds r0, r2, #0
    adds r0, #0x46
    ldrb r0, [r0]
    cmp r0, #3
    bhi lbl_08083398
    ldr r0, lbl_08083394 @ =0x0847a588
    b lbl_0808339a
    .align 2, 0
lbl_08083394: .4byte 0x0847a588
lbl_08083398:
    ldr r0, lbl_080833bc @ =0x0847a5ae
lbl_0808339a:
    str r0, [r2, #0x14]
    ldr r0, lbl_080833c0 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    adds r2, #0x46
    ldrb r0, [r2]
    adds r0, #1
    movs r1, #7
    ands r0, r1
    strb r0, [r2]
lbl_080833ac:
    bl tourian_escape_process_oam
    adds r0, r7, #0
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080833bc: .4byte 0x0847a5ae
lbl_080833c0: .4byte sNonGameplayRamPointer

    thumb_func_start TourianEscapeSamusChasedByPiratesFiring
TourianEscapeSamusChasedByPiratesFiring: @ 0x080833c4
    push {r4, r5, r6, lr}
    movs r6, #0
    ldr r4, lbl_080833f0 @ =sNonGameplayRamPointer
    ldr r2, [r4]
    ldrh r0, [r2, #6]
    adds r1, r0, #1
    strh r1, [r2, #6]
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    cmp r3, #0x7e
    bne lbl_080833dc
    b lbl_08083564
lbl_080833dc:
    cmp r3, #0x7e
    bgt lbl_08083402
    cmp r3, #1
    beq lbl_0808343c
    cmp r3, #1
    bgt lbl_080833f4
    cmp r3, #0
    beq lbl_08083428
    b lbl_0808358a
    .align 2, 0
lbl_080833f0: .4byte sNonGameplayRamPointer
lbl_080833f4:
    cmp r3, #2
    bne lbl_080833fa
    b lbl_08083530
lbl_080833fa:
    cmp r3, #0x78
    bne lbl_08083400
    b lbl_08083550
lbl_08083400:
    b lbl_0808358a
lbl_08083402:
    cmp r3, #0xc0
    bne lbl_08083408
    b lbl_08083574
lbl_08083408:
    cmp r3, #0xc0
    bgt lbl_08083414
    cmp r3, #0xa0
    bne lbl_08083412
    b lbl_08083558
lbl_08083412:
    b lbl_0808358a
lbl_08083414:
    movs r0, #0xb8
    lsls r0, r0, #1
    cmp r3, r0
    bne lbl_0808341e
    b lbl_0808357c
lbl_0808341e:
    adds r0, #0x10
    cmp r3, r0
    bne lbl_08083426
    b lbl_08083588
lbl_08083426:
    b lbl_0808358a
lbl_08083428:
    ldr r0, lbl_08083434 @ =0x084a2460
    ldr r1, lbl_08083438 @ =0x06010000
    bl LZ77UncompVRAM
    b lbl_0808358a
    .align 2, 0
lbl_08083434: .4byte 0x084a2460
lbl_08083438: .4byte 0x06010000
lbl_0808343c:
    ldr r1, lbl_08083508 @ =0x040000d4
    ldr r0, lbl_0808350c @ =0x08479d80
    str r0, [r1]
    ldr r0, lbl_08083510 @ =0x05000200
    str r0, [r1, #4]
    ldr r0, lbl_08083514 @ =0x80000040
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    strb r3, [r2, #8]
    ldr r0, [r4]
    mov ip, r0
    adds r0, #0x50
    movs r2, #0x78
    strh r2, [r0]
    mov r1, ip
    adds r1, #0x64
    movs r0, #0x60
    strh r0, [r1]
    adds r1, #0x1e
    movs r0, #0xc0
    strh r0, [r1]
    mov r1, ip
    strb r3, [r1, #9]
    ldr r0, [r4]
    mov ip, r0
    adds r0, #0x52
    strh r2, [r0]
    mov r1, ip
    adds r1, #0x66
    movs r0, #0x20
    strh r0, [r1]
    adds r1, #0x1e
    adds r0, #0xe0
    strh r0, [r1]
    mov r1, ip
    strb r3, [r1, #0xc]
    ldr r0, [r4]
    movs r1, #2
    strb r1, [r0, #0xd]
    ldr r0, [r4]
    strb r1, [r0, #0xe]
    ldr r0, [r4]
    strb r3, [r0, #0xf]
    ldr r0, [r4]
    strb r1, [r0, #0x10]
    ldr r0, [r4]
    strb r3, [r0, #0x11]
    ldr r2, [r4]
    adds r0, r2, #0
    adds r0, #0x50
    ldrh r0, [r0]
    lsls r0, r0, #3
    adds r1, r2, #0
    adds r1, #0x54
    strh r0, [r1]
    adds r0, r2, #0
    adds r0, #0x64
    ldrh r0, [r0]
    lsls r0, r0, #3
    adds r1, #0x14
    strh r0, [r1]
    ldr r1, lbl_08083518 @ =0x0847cfa4
    adds r3, r2, #0
    adds r3, #0x3f
    ldrb r0, [r3]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    adds r1, r2, #0
    adds r1, #0x9a
    strh r0, [r1]
    ldr r1, lbl_0808351c @ =0x0847cfb4
    ldrb r0, [r3]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    adds r1, r2, #0
    adds r1, #0xae
    strh r0, [r1]
    ldr r1, lbl_08083520 @ =0x0847cfc4
    ldrb r0, [r3]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r1, [r0]
    adds r0, r2, #0
    adds r0, #0x9c
    strh r1, [r0]
    ldr r1, lbl_08083524 @ =0x0847cfd4
    ldrb r0, [r3]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r1, [r0]
    adds r0, r2, #0
    adds r0, #0xb0
    strh r1, [r0]
    ldr r1, lbl_08083528 @ =gBg0XPosition
    movs r0, #0x30
    strh r0, [r1]
    ldr r1, lbl_0808352c @ =gBg0YPosition
    movs r0, #0x50
    strh r0, [r1]
    b lbl_0808358a
    .align 2, 0
lbl_08083508: .4byte 0x040000d4
lbl_0808350c: .4byte 0x08479d80
lbl_08083510: .4byte 0x05000200
lbl_08083514: .4byte 0x80000040
lbl_08083518: .4byte 0x0847cfa4
lbl_0808351c: .4byte 0x0847cfb4
lbl_08083520: .4byte 0x0847cfc4
lbl_08083524: .4byte 0x0847cfd4
lbl_08083528: .4byte gBg0XPosition
lbl_0808352c: .4byte gBg0YPosition
lbl_08083530:
    adds r1, r2, #0
    adds r1, #0xc0
    movs r0, #0x88
    lsls r0, r0, #5
    strh r0, [r1]
    ldr r0, lbl_0808354c @ =0x0000023a
    bl SoundPlay
    movs r0, #0x92
    lsls r0, r0, #2
    bl SoundPlay
    b lbl_0808358a
    .align 2, 0
lbl_0808354c: .4byte 0x0000023a
lbl_08083550:
    ldrb r0, [r2, #9]
    adds r0, #1
    strb r0, [r2, #9]
    b lbl_0808358a
lbl_08083558:
    adds r0, r2, #0
    adds r0, #0x46
    strb r6, [r0]
    ldr r0, [r4]
    adds r0, #0x3c
    strb r6, [r0]
lbl_08083564:
    ldr r0, lbl_08083570 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    b lbl_0808358a
    .align 2, 0
lbl_08083570: .4byte sNonGameplayRamPointer
lbl_08083574:
    adds r0, r2, #0
    adds r0, #0xc0
    strh r6, [r0]
    b lbl_0808358a
lbl_0808357c:
    ldr r0, lbl_08083584 @ =0x0000023b
    bl SoundPlay
    b lbl_0808358a
    .align 2, 0
lbl_08083584: .4byte 0x0000023b
lbl_08083588:
    movs r6, #1
lbl_0808358a:
    ldr r2, lbl_0808363c @ =sNonGameplayRamPointer
    ldr r0, [r2]
    ldrh r1, [r0, #6]
    movs r0, #7
    ands r0, r1
    adds r5, r2, #0
    cmp r0, #0
    bne lbl_080835a2
    ldr r1, lbl_08083640 @ =gBg0YPosition
    ldrh r0, [r1]
    subs r0, #1
    strh r0, [r1]
lbl_080835a2:
    ldr r3, [r5]
    ldrb r0, [r3, #8]
    cmp r0, #0
    bne lbl_080835ac
    b lbl_080837c0
lbl_080835ac:
    cmp r0, #1
    beq lbl_080835b2
    b lbl_0808372c
lbl_080835b2:
    movs r2, #0x9a
    adds r2, r2, r3
    mov ip, r2
    movs r0, #0
    ldrsh r2, [r2, r0]
    cmp r2, #0x30
    ble lbl_080835c2
    movs r2, #0x30
lbl_080835c2:
    movs r0, #0x30
    rsbs r0, r0, #0
    cmp r2, r0
    bge lbl_080835cc
    adds r2, r0, #0
lbl_080835cc:
    adds r0, r3, #0
    adds r0, #0x54
    ldrh r1, [r0]
    adds r1, r1, r2
    strh r1, [r0]
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x13
    subs r0, #4
    strh r1, [r0]
    adds r4, r3, #0
    adds r4, #0xae
    movs r1, #0
    ldrsh r2, [r4, r1]
    cmp r2, #0x18
    ble lbl_080835ec
    movs r2, #0x18
lbl_080835ec:
    movs r0, #0x18
    rsbs r0, r0, #0
    cmp r2, r0
    bge lbl_080835f6
    adds r2, r0, #0
lbl_080835f6:
    adds r1, r3, #0
    adds r1, #0x68
    ldrh r0, [r1]
    adds r0, r0, r2
    strh r0, [r1]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x13
    subs r1, #4
    strh r0, [r1]
    adds r0, r3, #0
    adds r0, #0x9c
    ldrh r0, [r0]
    mov r2, ip
    ldrh r2, [r2]
    adds r0, r0, r2
    mov r1, ip
    strh r0, [r1]
    adds r0, r3, #0
    adds r0, #0xb0
    ldrh r0, [r0]
    ldrh r2, [r4]
    adds r0, r0, r2
    strh r0, [r4]
    movs r4, #0
    adds r0, r3, #0
    adds r0, #0x3e
    ldrb r0, [r0]
    cmp r0, #1
    beq lbl_0808365a
    cmp r0, #1
    bgt lbl_08083644
    cmp r0, #0
    beq lbl_0808364e
    b lbl_08083684
    .align 2, 0
lbl_0808363c: .4byte sNonGameplayRamPointer
lbl_08083640: .4byte gBg0YPosition
lbl_08083644:
    cmp r0, #2
    beq lbl_08083678
    cmp r0, #3
    beq lbl_0808365a
    b lbl_08083684
lbl_0808364e:
    mov r1, ip
    movs r2, #0
    ldrsh r0, [r1, r2]
    cmp r0, #0
    blt lbl_08083684
    b lbl_08083682
lbl_0808365a:
    ldr r0, [r5]
    adds r0, #0x48
    ldrb r1, [r0]
    adds r2, r1, #1
    strb r2, [r0]
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    cmp r1, #0x13
    bls lbl_08083684
    ldr r0, [r5]
    adds r0, #0x48
    movs r1, #0
    strb r1, [r0]
    movs r4, #2
    b lbl_08083684
lbl_08083678:
    mov r1, ip
    movs r2, #0
    ldrsh r0, [r1, r2]
    cmp r0, #0
    bgt lbl_08083684
lbl_08083682:
    movs r4, #1
lbl_08083684:
    cmp r4, #1
    bne lbl_080836a0
    ldr r1, [r5]
    adds r1, #0x3e
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x9c
    strh r2, [r1]
    adds r0, #0xb0
    strh r2, [r0]
lbl_080836a0:
    cmp r4, #2
    bne lbl_08083712
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x3e
    ldrb r0, [r1]
    cmp r0, #2
    bhi lbl_080836b4
    adds r0, #1
    b lbl_080836b6
lbl_080836b4:
    movs r0, #0
lbl_080836b6:
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x3f
    ldrb r0, [r1]
    cmp r0, #6
    bhi lbl_080836c8
    adds r0, #1
    b lbl_080836ca
lbl_080836c8:
    movs r0, #0
lbl_080836ca:
    strb r0, [r1]
    ldr r3, [r5]
    ldr r1, lbl_08083744 @ =0x0847cfa4
    adds r2, r3, #0
    adds r2, #0x3f
    ldrb r0, [r2]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    adds r1, r3, #0
    adds r1, #0x9a
    strh r0, [r1]
    ldr r1, lbl_08083748 @ =0x0847cfb4
    ldrb r0, [r2]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    adds r1, r3, #0
    adds r1, #0xae
    strh r0, [r1]
    ldr r1, lbl_0808374c @ =0x0847cfc4
    ldrb r0, [r2]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r1, [r0]
    adds r0, r3, #0
    adds r0, #0x9c
    strh r1, [r0]
    ldr r1, lbl_08083750 @ =0x0847cfd4
    ldrb r0, [r2]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r1, [r0]
    adds r0, r3, #0
    adds r0, #0xb0
    strh r1, [r0]
lbl_08083712:
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x46
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0808372c
    adds r1, r2, #0
    adds r1, #0x82
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
lbl_0808372c:
    ldr r1, [r5]
    ldrb r0, [r1, #8]
    cmp r0, #2
    bhi lbl_08083754
    adds r1, #0x3c
    ldrb r0, [r1]
    cmp r0, #0xe
    bls lbl_0808379c
    movs r0, #0
    strb r0, [r1]
    b lbl_0808379c
    .align 2, 0
lbl_08083744: .4byte 0x0847cfa4
lbl_08083748: .4byte 0x0847cfb4
lbl_0808374c: .4byte 0x0847cfc4
lbl_08083750: .4byte 0x0847cfd4
lbl_08083754:
    adds r1, #0x3c
    ldrb r0, [r1]
    cmp r0, #0x16
    bls lbl_08083760
    movs r0, #0x17
    strb r0, [r1]
lbl_08083760:
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x46
    ldrb r0, [r0]
    cmp r0, #3
    bhi lbl_08083774
    adds r1, #0x64
    ldrh r0, [r1]
    adds r0, #4
    b lbl_08083786
lbl_08083774:
    cmp r0, #7
    bhi lbl_08083780
    adds r1, #0x64
    ldrh r0, [r1]
    adds r0, #2
    b lbl_08083786
lbl_08083780:
    adds r1, #0x64
    ldrh r0, [r1]
    adds r0, #1
lbl_08083786:
    strh r0, [r1]
    ldr r0, [r5]
    adds r2, r0, #0
    adds r2, #0x82
    ldrh r1, [r2]
    ldr r0, lbl_08083814 @ =0x000001f7
    cmp r1, r0
    bhi lbl_0808379c
    adds r0, r1, #0
    adds r0, #8
    strh r0, [r2]
lbl_0808379c:
    ldr r3, [r5]
    adds r2, r3, #0
    adds r2, #0x3c
    ldrb r0, [r2]
    lsrs r4, r0, #2
    ldr r1, lbl_08083818 @ =0x0847cf70
    lsls r0, r4, #2
    adds r0, r0, r1
    ldr r0, [r0]
    str r0, [r3, #0x14]
    ldrb r0, [r2]
    adds r0, #1
    strb r0, [r2]
    ldr r1, [r5]
    adds r1, #0x46
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_080837c0:
    ldr r0, [r5]
    ldrb r0, [r0, #0xc]
    cmp r0, #0
    beq lbl_080837ce
    movs r0, #1
    bl sub_08081788
lbl_080837ce:
    ldr r1, [r5]
    ldrb r0, [r1, #9]
    cmp r0, #0
    beq lbl_08083852
    movs r4, #0
    adds r0, r1, #0
    adds r0, #0x84
    ldrh r0, [r0]
    cmp r0, #0xa0
    bls lbl_080837f4
    adds r1, #0x3d
    ldrb r0, [r1]
    cmp r0, #0x1a
    bls lbl_080837ec
    strb r4, [r1]
lbl_080837ec:
    ldr r0, [r5]
    adds r0, #0x3d
    ldrb r0, [r0]
    lsrs r4, r0, #2
lbl_080837f4:
    ldr r2, lbl_0808381c @ =sNonGameplayRamPointer
    ldr r3, [r2]
    ldr r1, lbl_08083820 @ =0x0847cf88
    lsls r0, r4, #2
    adds r0, r0, r1
    ldr r0, [r0]
    str r0, [r3, #0x18]
    ldrb r0, [r3, #9]
    adds r5, r2, #0
    cmp r0, #1
    bne lbl_08083824
    adds r1, r3, #0
    adds r1, #0x84
    ldrh r0, [r1]
    subs r0, #1
    b lbl_0808382c
    .align 2, 0
lbl_08083814: .4byte 0x000001f7
lbl_08083818: .4byte 0x0847cf70
lbl_0808381c: .4byte sNonGameplayRamPointer
lbl_08083820: .4byte 0x0847cf88
lbl_08083824:
    adds r1, r3, #0
    adds r1, #0x84
    ldrh r0, [r1]
    subs r0, #2
lbl_0808382c:
    strh r0, [r1]
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x84
    ldrh r0, [r0]
    cmp r0, #7
    bhi lbl_0808383e
    movs r0, #0
    strb r0, [r1, #9]
lbl_0808383e:
    ldr r1, [r5]
    adds r1, #0x3d
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r1, [r5]
    adds r1, #0x47
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_08083852:
    bl sub_080818cc
    adds r0, r6, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start TourianEscapeSamusGettingShot
TourianEscapeSamusGettingShot: @ 0x08083860
    push {r4, r5, r6, r7, lr}
    movs r6, #0
    ldr r4, lbl_0808388c @ =sNonGameplayRamPointer
    ldr r3, [r4]
    ldrh r0, [r3, #6]
    adds r1, r0, #1
    strh r1, [r3, #6]
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0x18
    bne lbl_08083878
    b lbl_0808397c
lbl_08083878:
    cmp r1, #0x18
    bgt lbl_0808389a
    cmp r1, #1
    beq lbl_080838d4
    cmp r1, #1
    bgt lbl_08083890
    cmp r1, #0
    beq lbl_080838c0
    b lbl_08083a38
    .align 2, 0
lbl_0808388c: .4byte sNonGameplayRamPointer
lbl_08083890:
    cmp r1, #2
    beq lbl_080838f8
    cmp r1, #3
    beq lbl_08083948
    b lbl_08083a38
lbl_0808389a:
    cmp r1, #0x88
    bne lbl_080838a0
    b lbl_080839da
lbl_080838a0:
    cmp r1, #0x88
    bgt lbl_080838ac
    cmp r1, #0x80
    bne lbl_080838aa
    b lbl_080839d0
lbl_080838aa:
    b lbl_08083a38
lbl_080838ac:
    movs r0, #0xa8
    lsls r0, r0, #1
    cmp r1, r0
    bne lbl_080838b6
    b lbl_080839ec
lbl_080838b6:
    adds r0, #0x40
    cmp r1, r0
    bne lbl_080838be
    b lbl_08083a30
lbl_080838be:
    b lbl_08083a38
lbl_080838c0:
    ldr r0, lbl_080838cc @ =0x084a4400
    ldr r1, lbl_080838d0 @ =0x06008000
    bl LZ77UncompVRAM
    b lbl_08083a38
    .align 2, 0
lbl_080838cc: .4byte 0x084a4400
lbl_080838d0: .4byte 0x06008000
lbl_080838d4:
    ldr r0, lbl_080838ec @ =0x084a3b34
    ldr r1, lbl_080838f0 @ =0x06010000
    bl LZ77UncompVRAM
    ldr r0, [r4]
    adds r0, #0xc2
    movs r1, #0xff
    strh r1, [r0]
    ldr r1, lbl_080838f4 @ =gWrittenToBLDY_NonGameplay
    movs r0, #0x10
    strh r0, [r1]
    b lbl_08083a38
    .align 2, 0
lbl_080838ec: .4byte 0x084a3b34
lbl_080838f0: .4byte 0x06010000
lbl_080838f4: .4byte gWrittenToBLDY_NonGameplay
lbl_080838f8:
    ldr r0, lbl_08083928 @ =0x084a72dc
    ldr r1, lbl_0808392c @ =0x0600f000
    bl LZ77UncompVRAM
    ldr r1, lbl_08083930 @ =0x040000d4
    ldr r0, lbl_08083934 @ =0x08479a20
    str r0, [r1]
    ldr r0, lbl_08083938 @ =0x05000200
    str r0, [r1, #4]
    ldr r0, lbl_0808393c @ =0x80000050
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r1, lbl_08083940 @ =gBg0XPosition
    movs r0, #0x60
    strh r0, [r1]
    ldr r1, lbl_08083944 @ =gBg0YPosition
    movs r0, #0x30
    strh r0, [r1]
    ldr r1, [r4]
    ldrb r0, [r1, #1]
    adds r0, #1
    strb r0, [r1, #1]
    b lbl_08083a38
    .align 2, 0
lbl_08083928: .4byte 0x084a72dc
lbl_0808392c: .4byte 0x0600f000
lbl_08083930: .4byte 0x040000d4
lbl_08083934: .4byte 0x08479a20
lbl_08083938: .4byte 0x05000200
lbl_0808393c: .4byte 0x80000050
lbl_08083940: .4byte gBg0XPosition
lbl_08083944: .4byte gBg0YPosition
lbl_08083948:
    ldr r1, lbl_08083978 @ =0x04000008
    movs r2, #0xe0
    lsls r2, r2, #5
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, r3, #0
    adds r1, #0xc0
    movs r0, #0x88
    lsls r0, r0, #5
    strh r0, [r1]
    movs r2, #1
    strb r2, [r3, #0xc]
    ldr r0, [r4]
    movs r1, #2
    strb r1, [r0, #0xd]
    ldr r0, [r4]
    strb r1, [r0, #0xe]
    ldr r0, [r4]
    strb r2, [r0, #0xf]
    ldr r0, [r4]
    strb r1, [r0, #0x10]
    ldr r0, [r4]
    strb r2, [r0, #0x11]
    b lbl_08083a38
    .align 2, 0
lbl_08083978: .4byte 0x04000008
lbl_0808397c:
    ldrb r0, [r3, #8]
    adds r0, #1
    strb r0, [r3, #8]
    ldr r3, [r4]
    ldr r0, lbl_080839c8 @ =0x0847a904
    str r0, [r3, #0x14]
    adds r1, r3, #0
    adds r1, #0x50
    movs r2, #0
    ldr r0, lbl_080839cc @ =0x0000012d
    strh r0, [r1]
    adds r1, #0x14
    movs r0, #0xae
    strh r0, [r1]
    adds r0, r3, #0
    adds r0, #0x78
    strb r2, [r0]
    ldr r2, [r4]
    adds r0, r2, #0
    adds r0, #0x50
    ldrh r0, [r0]
    lsls r0, r0, #5
    adds r1, r2, #0
    adds r1, #0x52
    strh r0, [r1]
    adds r0, r2, #0
    adds r0, #0x64
    ldrh r0, [r0]
    lsls r0, r0, #5
    adds r1, #2
    strh r0, [r1]
    adds r1, #0x44
    movs r0, #0x38
    strh r0, [r1]
    adds r1, #2
    movs r0, #0x1c
    strh r0, [r1]
    b lbl_08083a38
    .align 2, 0
lbl_080839c8: .4byte 0x0847a904
lbl_080839cc: .4byte 0x0000012d
lbl_080839d0:
    adds r0, r3, #0
    adds r0, #0x98
    strh r6, [r0]
    adds r0, #2
    strh r6, [r0]
lbl_080839da:
    ldr r0, lbl_080839e8 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    b lbl_08083a38
    .align 2, 0
lbl_080839e8: .4byte sNonGameplayRamPointer
lbl_080839ec:
    ldr r1, lbl_08083a20 @ =0x040000d4
    ldr r0, lbl_08083a24 @ =0x08479a20
    str r0, [r1]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_08083a28 @ =0x80000050
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    subs r1, #0xca
    ldr r2, lbl_08083a2c @ =0x00001e09
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, r3, #0
    adds r1, #0xc0
    movs r2, #0
    movs r0, #0x90
    lsls r0, r0, #5
    strh r0, [r1]
    strb r2, [r3, #8]
    movs r0, #0x8f
    lsls r0, r0, #2
    bl SoundPlay
    b lbl_08083a38
    .align 2, 0
lbl_08083a20: .4byte 0x040000d4
lbl_08083a24: .4byte 0x08479a20
lbl_08083a28: .4byte 0x80000050
lbl_08083a2c: .4byte 0x00001e09
lbl_08083a30:
    adds r0, r3, #0
    adds r0, #0xc0
    strh r6, [r0]
    movs r6, #1
lbl_08083a38:
    ldr r0, lbl_08083a60 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrb r1, [r2, #1]
    adds r7, r0, #0
    cmp r1, #0
    beq lbl_08083a72
    ldr r5, lbl_08083a64 @ =gWrittenToBLDY_NonGameplay
    ldrh r4, [r5]
    adds r3, r4, #0
    cmp r3, #0
    beq lbl_08083a68
    ldrh r1, [r2, #6]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08083a86
    subs r0, r4, #1
    strh r0, [r5]
    b lbl_08083a72
    .align 2, 0
lbl_08083a60: .4byte sNonGameplayRamPointer
lbl_08083a64: .4byte gWrittenToBLDY_NonGameplay
lbl_08083a68:
    adds r1, r2, #0
    adds r1, #0xc2
    movs r0, #0
    strh r3, [r1]
    strb r0, [r2, #1]
lbl_08083a72:
    ldr r0, [r7]
    ldrh r1, [r0, #6]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08083a86
    ldr r1, lbl_08083afc @ =gBg0XPosition
    ldrh r0, [r1]
    subs r0, #1
    strh r0, [r1]
lbl_08083a86:
    ldr r0, [r7]
    ldrb r0, [r0, #0xc]
    cmp r0, #0
    beq lbl_08083a94
    movs r0, #0
    bl sub_08081788
lbl_08083a94:
    ldr r3, [r7]
    ldrb r2, [r3, #8]
    cmp r2, #1
    bne lbl_08083b04
    ldrh r0, [r3, #6]
    cmp r0, #0x6f
    bls lbl_08083abe
    adds r0, r3, #0
    adds r0, #0x98
    ldrh r1, [r0]
    subs r1, #1
    strh r1, [r0]
    ldrh r0, [r3, #6]
    ands r2, r0
    cmp r2, #0
    beq lbl_08083abe
    adds r1, r3, #0
    adds r1, #0x9a
    ldrh r0, [r1]
    subs r0, #1
    strh r0, [r1]
lbl_08083abe:
    ldr r0, lbl_08083b00 @ =sNonGameplayRamPointer
    ldr r3, [r0]
    movs r0, #0x52
    adds r0, r0, r3
    mov ip, r0
    adds r1, r3, #0
    adds r1, #0x98
    ldrh r0, [r0]
    ldrh r1, [r1]
    subs r0, r0, r1
    mov r1, ip
    strh r0, [r1]
    adds r2, r3, #0
    adds r2, #0x54
    adds r1, r3, #0
    adds r1, #0x9a
    ldrh r0, [r2]
    ldrh r1, [r1]
    subs r0, r0, r1
    strh r0, [r2]
    mov r1, ip
    ldrh r0, [r1]
    lsrs r0, r0, #5
    adds r1, r3, #0
    adds r1, #0x50
    strh r0, [r1]
    ldrh r0, [r2]
    lsrs r0, r0, #5
    adds r1, #0x14
    strh r0, [r1]
    b lbl_08083d04
    .align 2, 0
lbl_08083afc: .4byte gBg0XPosition
lbl_08083b00: .4byte sNonGameplayRamPointer
lbl_08083b04:
    cmp r2, #3
    beq lbl_08083b0a
    b lbl_08083d04
lbl_08083b0a:
    adds r0, r3, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    cmp r0, #5
    bhi lbl_08083bee
    lsls r0, r0, #2
    ldr r1, lbl_08083b20 @ =lbl_08083b24
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08083b20: .4byte lbl_08083b24
lbl_08083b24: @ jump table
    .4byte lbl_08083b3c @ case 0
    .4byte lbl_08083b64 @ case 1
    .4byte lbl_08083b78 @ case 2
    .4byte lbl_08083bb2 @ case 3
    .4byte lbl_08083bd0 @ case 4
    .4byte lbl_08083b78 @ case 5
lbl_08083b3c:
    ldr r2, lbl_08083b5c @ =sNonGameplayRamPointer
    ldr r4, [r2]
    adds r1, r4, #0
    adds r1, #0x98
    ldrh r0, [r1]
    subs r0, #1
    strh r0, [r1]
    lsls r0, r0, #0x10
    ldr r1, lbl_08083b60 @ =0xffe50000
    adds r7, r2, #0
    cmp r0, r1
    bge lbl_08083bee
    adds r1, r4, #0
    adds r1, #0x3d
    b lbl_08083be8
    .align 2, 0
lbl_08083b5c: .4byte sNonGameplayRamPointer
lbl_08083b60: .4byte 0xffe50000
lbl_08083b64:
    ldr r2, lbl_08083b74 @ =sNonGameplayRamPointer
    ldr r3, [r2]
    adds r1, r3, #0
    adds r1, #0x98
    ldrh r0, [r1]
    adds r0, #1
    b lbl_08083bdc
    .align 2, 0
lbl_08083b74: .4byte sNonGameplayRamPointer
lbl_08083b78:
    ldr r3, lbl_08083ba0 @ =sNonGameplayRamPointer
    ldr r0, [r3]
    adds r0, #0x49
    ldrb r1, [r0]
    adds r2, r1, #1
    strb r2, [r0]
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    adds r7, r3, #0
    cmp r1, #3
    bls lbl_08083bee
    ldr r0, [r7]
    adds r1, r0, #0
    adds r1, #0x3d
    ldrb r0, [r1]
    cmp r0, #2
    bne lbl_08083ba4
    adds r0, #1
    b lbl_08083ba6
    .align 2, 0
lbl_08083ba0: .4byte sNonGameplayRamPointer
lbl_08083ba4:
    movs r0, #0
lbl_08083ba6:
    strb r0, [r1]
    ldr r0, [r7]
    adds r0, #0x49
    movs r1, #0
    strb r1, [r0]
    b lbl_08083bee
lbl_08083bb2:
    ldr r2, lbl_08083bcc @ =sNonGameplayRamPointer
    ldr r3, [r2]
    adds r1, r3, #0
    adds r1, #0x98
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    adds r7, r2, #0
    cmp r0, #0x27
    ble lbl_08083bee
    b lbl_08083be6
    .align 2, 0
lbl_08083bcc: .4byte sNonGameplayRamPointer
lbl_08083bd0:
    ldr r2, lbl_08083c30 @ =sNonGameplayRamPointer
    ldr r3, [r2]
    adds r1, r3, #0
    adds r1, #0x98
    ldrh r0, [r1]
    subs r0, #1
lbl_08083bdc:
    strh r0, [r1]
    lsls r0, r0, #0x10
    adds r7, r2, #0
    cmp r0, #0
    bne lbl_08083bee
lbl_08083be6:
    subs r1, #0x5b
lbl_08083be8:
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_08083bee:
    ldr r3, [r7]
    adds r0, r3, #0
    adds r0, #0x98
    movs r1, #0
    ldrsh r2, [r0, r1]
    cmp r2, #0x10
    ble lbl_08083bfe
    movs r2, #0x10
lbl_08083bfe:
    movs r0, #0x10
    rsbs r0, r0, #0
    cmp r2, r0
    bge lbl_08083c08
    adds r2, r0, #0
lbl_08083c08:
    adds r1, r3, #0
    adds r1, #0x52
    ldrh r0, [r1]
    adds r0, r0, r2
    strh r0, [r1]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x15
    subs r1, #2
    strh r0, [r1]
    adds r0, r3, #0
    adds r0, #0x3e
    ldrb r0, [r0]
    cmp r0, #5
    bhi lbl_08083cd8
    lsls r0, r0, #2
    ldr r1, lbl_08083c34 @ =lbl_08083c38
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08083c30: .4byte sNonGameplayRamPointer
lbl_08083c34: .4byte lbl_08083c38
lbl_08083c38: @ jump table
    .4byte lbl_08083c50 @ case 0
    .4byte lbl_08083c6c @ case 1
    .4byte lbl_08083c78 @ case 2
    .4byte lbl_08083ca8 @ case 3
    .4byte lbl_08083cbe @ case 4
    .4byte lbl_08083c78 @ case 5
lbl_08083c50:
    ldr r2, [r7]
    adds r1, r2, #0
    adds r1, #0x9a
    ldrh r0, [r1]
    subs r0, #1
    strh r0, [r1]
    lsls r0, r0, #0x10
    ldr r1, lbl_08083c68 @ =0xffed0000
    cmp r0, r1
    bge lbl_08083cd8
    adds r1, r2, #0
    b lbl_08083cd0
    .align 2, 0
lbl_08083c68: .4byte 0xffed0000
lbl_08083c6c:
    ldr r1, [r7]
    adds r2, r1, #0
    adds r2, #0x9a
    ldrh r0, [r2]
    adds r0, #1
    b lbl_08083cc8
lbl_08083c78:
    ldr r0, [r7]
    adds r0, #0x4a
    ldrb r1, [r0]
    adds r2, r1, #1
    strb r2, [r0]
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    cmp r1, #3
    bls lbl_08083cd8
    ldr r0, [r7]
    adds r1, r0, #0
    adds r1, #0x3e
    ldrb r0, [r1]
    cmp r0, #2
    bne lbl_08083c9a
    adds r0, #1
    b lbl_08083c9c
lbl_08083c9a:
    movs r0, #0
lbl_08083c9c:
    strb r0, [r1]
    ldr r0, [r7]
    adds r0, #0x4a
    movs r1, #0
    strb r1, [r0]
    b lbl_08083cd8
lbl_08083ca8:
    ldr r1, [r7]
    adds r2, r1, #0
    adds r2, #0x9a
    ldrh r0, [r2]
    adds r0, #1
    strh r0, [r2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0x13
    ble lbl_08083cd8
    b lbl_08083cd0
lbl_08083cbe:
    ldr r1, [r7]
    adds r2, r1, #0
    adds r2, #0x9a
    ldrh r0, [r2]
    subs r0, #1
lbl_08083cc8:
    strh r0, [r2]
    lsls r0, r0, #0x10
    cmp r0, #0
    bne lbl_08083cd8
lbl_08083cd0:
    adds r1, #0x3e
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_08083cd8:
    ldr r3, [r7]
    adds r0, r3, #0
    adds r0, #0x9a
    movs r1, #0
    ldrsh r2, [r0, r1]
    cmp r2, #8
    ble lbl_08083ce8
    movs r2, #8
lbl_08083ce8:
    movs r0, #8
    rsbs r0, r0, #0
    cmp r2, r0
    bge lbl_08083cf2
    adds r2, r0, #0
lbl_08083cf2:
    adds r0, r3, #0
    adds r0, #0x54
    ldrh r1, [r0]
    adds r1, r1, r2
    strh r1, [r0]
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x15
    adds r0, #0x10
    strh r1, [r0]
lbl_08083d04:
    bl tourian_escape_process_oam
    adds r0, r6, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start TourianEscapeSamusGoingToCrash
TourianEscapeSamusGoingToCrash: @ 0x08083d10
    push {r4, r5, lr}
    movs r5, #0
    ldr r4, lbl_08083d38 @ =sNonGameplayRamPointer
    ldr r2, [r4]
    ldrh r0, [r2, #6]
    adds r1, r0, #1
    strh r1, [r2, #6]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #3
    beq lbl_08083e14
    cmp r0, #3
    bgt lbl_08083d3c
    cmp r0, #1
    beq lbl_08083d68
    cmp r0, #1
    bgt lbl_08083da0
    cmp r0, #0
    beq lbl_08083d56
    b lbl_08083e74
    .align 2, 0
lbl_08083d38: .4byte sNonGameplayRamPointer
lbl_08083d3c:
    cmp r0, #0xc
    bne lbl_08083d42
    b lbl_08083e52
lbl_08083d42:
    cmp r0, #0xc
    bgt lbl_08083d4e
    cmp r0, #6
    bne lbl_08083d4c
    b lbl_08083e40
lbl_08083d4c:
    b lbl_08083e74
lbl_08083d4e:
    cmp r0, #0x50
    bne lbl_08083d54
    b lbl_08083e68
lbl_08083d54:
    b lbl_08083e74
lbl_08083d56:
    ldr r0, lbl_08083d64 @ =0x0848a17c
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    b lbl_08083e74
    .align 2, 0
lbl_08083d64: .4byte 0x0848a17c
lbl_08083d68:
    ldr r0, lbl_08083d88 @ =0x084ad56c
    ldr r1, lbl_08083d8c @ =0x06010000
    bl LZ77UncompVRAM
    ldr r1, lbl_08083d90 @ =gBg0XPosition
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_08083d94 @ =gBg0YPosition
    strh r5, [r0]
    ldr r1, lbl_08083d98 @ =gWrittenToBLDALPHA_L
    movs r0, #9
    strh r0, [r1]
    ldr r1, lbl_08083d9c @ =gWrittenToBLDALPHA_H
    movs r0, #7
    strh r0, [r1]
    b lbl_08083e74
    .align 2, 0
lbl_08083d88: .4byte 0x084ad56c
lbl_08083d8c: .4byte 0x06010000
lbl_08083d90: .4byte gBg0XPosition
lbl_08083d94: .4byte gBg0YPosition
lbl_08083d98: .4byte gWrittenToBLDALPHA_L
lbl_08083d9c: .4byte gWrittenToBLDALPHA_H
lbl_08083da0:
    ldr r0, lbl_08083dec @ =0x0848d744
    ldr r1, lbl_08083df0 @ =0x0600f000
    bl LZ77UncompVRAM
    ldr r1, lbl_08083df4 @ =0x040000d4
    ldr r0, lbl_08083df8 @ =0x08479400
    str r0, [r1]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_08083dfc @ =0x80000090
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, lbl_08083e00 @ =0x08479e00
    str r0, [r1]
    ldr r0, lbl_08083e04 @ =0x05000200
    str r0, [r1, #4]
    ldr r0, lbl_08083e08 @ =0x80000070
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, [r4]
    movs r2, #1
    strb r2, [r0, #8]
    ldr r1, [r4]
    ldr r0, lbl_08083e0c @ =0x0847a98a
    str r0, [r1, #0x14]
    strb r2, [r1, #0xb]
    ldr r1, [r4]
    ldr r0, lbl_08083e10 @ =0x0847a958
    str r0, [r1, #0x20]
    adds r2, r1, #0
    adds r2, #0x56
    movs r0, #0x88
    strh r0, [r2]
    adds r1, #0x6a
    movs r0, #0x58
    strh r0, [r1]
    b lbl_08083e74
    .align 2, 0
lbl_08083dec: .4byte 0x0848d744
lbl_08083df0: .4byte 0x0600f000
lbl_08083df4: .4byte 0x040000d4
lbl_08083df8: .4byte 0x08479400
lbl_08083dfc: .4byte 0x80000090
lbl_08083e00: .4byte 0x08479e00
lbl_08083e04: .4byte 0x05000200
lbl_08083e08: .4byte 0x80000070
lbl_08083e0c: .4byte 0x0847a98a
lbl_08083e10: .4byte 0x0847a958
lbl_08083e14:
    ldr r1, lbl_08083e38 @ =0x04000008
    movs r3, #0xf0
    lsls r3, r3, #5
    adds r0, r3, #0
    strh r0, [r1]
    adds r1, r2, #0
    adds r1, #0xc0
    movs r0, #0x88
    lsls r0, r0, #5
    strh r0, [r1]
    adds r1, #2
    movs r0, #0xfd
    lsls r0, r0, #6
    strh r0, [r1]
    ldr r0, lbl_08083e3c @ =0x0000023d
    bl SoundPlay
    b lbl_08083e74
    .align 2, 0
lbl_08083e38: .4byte 0x04000008
lbl_08083e3c: .4byte 0x0000023d
lbl_08083e40:
    movs r0, #1
    strb r0, [r2, #9]
    ldr r1, [r4]
    adds r2, r1, #0
    adds r2, #0x52
    movs r0, #0x6d
    strh r0, [r2]
    adds r1, #0x66
    b lbl_08083e62
lbl_08083e52:
    movs r0, #1
    strb r0, [r2, #0xa]
    ldr r1, [r4]
    adds r2, r1, #0
    adds r2, #0x54
    movs r0, #0x6d
    strh r0, [r2]
    adds r1, #0x68
lbl_08083e62:
    movs r0, #0x46
    strh r0, [r1]
    b lbl_08083e74
lbl_08083e68:
    adds r0, r2, #0
    adds r0, #0xc0
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    movs r5, #1
lbl_08083e74:
    ldr r3, lbl_08083ea0 @ =sNonGameplayRamPointer
    ldr r0, [r3]
    ldrb r1, [r0, #5]
    adds r2, r1, #1
    strb r2, [r0, #5]
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    cmp r1, #4
    bls lbl_08083e94
    ldr r1, [r3]
    movs r0, #0
    strb r0, [r1, #5]
    ldr r1, lbl_08083ea4 @ =gBg0XPosition
    ldrh r0, [r1]
    subs r0, #1
    strh r0, [r1]
lbl_08083e94:
    bl sub_08081ad8
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08083ea0: .4byte sNonGameplayRamPointer
lbl_08083ea4: .4byte gBg0XPosition

    thumb_func_start TourianEscapeSamusCrashing
TourianEscapeSamusCrashing: @ 0x08083ea8
    push {r4, r5, lr}
    movs r5, #0
    ldr r4, lbl_08083ed0 @ =sNonGameplayRamPointer
    ldr r3, [r4]
    ldrh r0, [r3, #6]
    adds r1, r0, #1
    strh r1, [r3, #6]
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #4
    beq lbl_08083f80
    cmp r1, #4
    bgt lbl_08083ede
    cmp r1, #1
    beq lbl_08083f18
    cmp r1, #1
    bgt lbl_08083ed4
    cmp r1, #0
    beq lbl_08083f08
    b lbl_0808407a
    .align 2, 0
lbl_08083ed0: .4byte sNonGameplayRamPointer
lbl_08083ed4:
    cmp r1, #2
    beq lbl_08083f2c
    cmp r1, #3
    beq lbl_08083f40
    b lbl_0808407a
lbl_08083ede:
    cmp r1, #0x40
    bne lbl_08083ee4
    b lbl_08084024
lbl_08083ee4:
    cmp r1, #0x40
    bgt lbl_08083ef6
    cmp r1, #5
    bne lbl_08083eee
    b lbl_08083fe0
lbl_08083eee:
    cmp r1, #0xa
    bne lbl_08083ef4
    b lbl_08084008
lbl_08083ef4:
    b lbl_0808407a
lbl_08083ef6:
    cmp r1, #0x68
    bne lbl_08083efc
    b lbl_08084028
lbl_08083efc:
    movs r0, #0x90
    lsls r0, r0, #1
    cmp r1, r0
    bne lbl_08083f06
    b lbl_08084078
lbl_08083f06:
    b lbl_0808407a
lbl_08083f08:
    ldr r0, lbl_08083f14 @ =0x084aae80
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    b lbl_0808407a
    .align 2, 0
lbl_08083f14: .4byte 0x084aae80
lbl_08083f18:
    ldr r0, lbl_08083f24 @ =0x084ae878
    ldr r1, lbl_08083f28 @ =0x06008000
    bl LZ77UncompVRAM
    b lbl_0808407a
    .align 2, 0
lbl_08083f24: .4byte 0x084ae878
lbl_08083f28: .4byte 0x06008000
lbl_08083f2c:
    ldr r0, lbl_08083f38 @ =0x084a7bb4
    ldr r1, lbl_08083f3c @ =0x06010000
    bl LZ77UncompVRAM
    b lbl_0808407a
    .align 2, 0
lbl_08083f38: .4byte 0x084a7bb4
lbl_08083f3c: .4byte 0x06010000
lbl_08083f40:
    ldr r0, lbl_08083f64 @ =0x084acc68
    ldr r1, lbl_08083f68 @ =0x06007000
    bl LZ77UncompVRAM
    ldr r0, lbl_08083f6c @ =0x084b0500
    ldr r1, lbl_08083f70 @ =0x0600f000
    bl LZ77UncompVRAM
    ldr r1, lbl_08083f74 @ =0x040000d4
    ldr r0, lbl_08083f78 @ =0x08479f20
    str r0, [r1]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_08083f7c @ =0x80000030
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    b lbl_0808407a
    .align 2, 0
lbl_08083f64: .4byte 0x084acc68
lbl_08083f68: .4byte 0x06007000
lbl_08083f6c: .4byte 0x084b0500
lbl_08083f70: .4byte 0x0600f000
lbl_08083f74: .4byte 0x040000d4
lbl_08083f78: .4byte 0x08479f20
lbl_08083f7c: .4byte 0x80000030
lbl_08083f80:
    ldr r1, lbl_08083fc0 @ =0x040000d4
    ldr r0, lbl_08083fc4 @ =0x0847a060
    str r0, [r1]
    ldr r0, lbl_08083fc8 @ =0x05000200
    str r0, [r1, #4]
    ldr r0, lbl_08083fcc @ =0x80000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #1
    strb r0, [r3, #9]
    ldr r1, [r4]
    ldr r0, lbl_08083fd0 @ =0x0847aa96
    str r0, [r1, #0x18]
    adds r2, r1, #0
    adds r2, #0x52
    movs r0, #0x78
    strh r0, [r2]
    adds r2, #0x14
    movs r0, #0x68
    strh r0, [r2]
    adds r1, #0x79
    movs r0, #2
    strb r0, [r1]
    ldr r0, lbl_08083fd4 @ =gBg0XPosition
    strh r5, [r0]
    ldr r0, lbl_08083fd8 @ =gBg0YPosition
    strh r5, [r0]
    ldr r0, lbl_08083fdc @ =0x00000249
    bl SoundPlay
    b lbl_0808407a
    .align 2, 0
lbl_08083fc0: .4byte 0x040000d4
lbl_08083fc4: .4byte 0x0847a060
lbl_08083fc8: .4byte 0x05000200
lbl_08083fcc: .4byte 0x80000100
lbl_08083fd0: .4byte 0x0847aa96
lbl_08083fd4: .4byte gBg0XPosition
lbl_08083fd8: .4byte gBg0YPosition
lbl_08083fdc: .4byte 0x00000249
lbl_08083fe0:
    ldr r1, lbl_08084000 @ =0x04000008
    movs r2, #0xe0
    lsls r2, r2, #4
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    ldr r2, lbl_08084004 @ =0x00001e09
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, r3, #0
    adds r1, #0xc0
    movs r0, #0x88
    lsls r0, r0, #5
    strh r0, [r1]
    b lbl_0808407a
    .align 2, 0
lbl_08084000: .4byte 0x04000008
lbl_08084004: .4byte 0x00001e09
lbl_08084008:
    movs r0, #1
    strb r0, [r3, #8]
    ldr r2, [r4]
    adds r1, r2, #0
    adds r1, #0x50
    movs r0, #0xfa
    strh r0, [r1]
    adds r1, #0x14
    movs r0, #0x10
    strh r0, [r1]
    adds r1, #0x14
    movs r0, #2
    strb r0, [r1]
    b lbl_0808407a
lbl_08084024:
    strb r5, [r3, #8]
    b lbl_0808407a
lbl_08084028:
    ldr r1, lbl_08084064 @ =0x040000d4
    ldr r0, lbl_08084068 @ =0x08479f80
    str r0, [r1]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_0808406c @ =0x80000070
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    adds r1, r3, #0
    adds r1, #0xc0
    movs r2, #0
    movs r0, #0x98
    lsls r0, r0, #5
    strh r0, [r1]
    strb r2, [r3, #8]
    ldr r1, [r4]
    ldr r0, lbl_08084070 @ =0x0847ab28
    str r0, [r1, #0x18]
    ldrb r0, [r1, #2]
    adds r0, #1
    strb r0, [r1, #2]
    ldr r0, [r4]
    adds r0, #0xc2
    movs r1, #0xbf
    strh r1, [r0]
    ldr r0, lbl_08084074 @ =0x0000024a
    bl SoundPlay
    b lbl_0808407a
    .align 2, 0
lbl_08084064: .4byte 0x040000d4
lbl_08084068: .4byte 0x08479f80
lbl_0808406c: .4byte 0x80000070
lbl_08084070: .4byte 0x0847ab28
lbl_08084074: .4byte 0x0000024a
lbl_08084078:
    movs r5, #1
lbl_0808407a:
    ldr r0, lbl_080840f8 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrb r1, [r2, #2]
    adds r3, r0, #0
    cmp r1, #0
    beq lbl_080840a4
    ldrb r1, [r2, #5]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0808409c
    ldr r1, lbl_080840fc @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_0808409c
    adds r0, #1
    strh r0, [r1]
lbl_0808409c:
    ldr r1, [r3]
    ldrb r0, [r1, #5]
    adds r0, #1
    strb r0, [r1, #5]
lbl_080840a4:
    ldr r2, [r3]
    ldrb r0, [r2, #8]
    cmp r0, #0
    beq lbl_080840ea
    adds r0, r2, #0
    adds r0, #0x46
    ldrb r1, [r0]
    movs r0, #0x1f
    ands r0, r1
    lsrs r0, r0, #3
    adds r1, r2, #0
    adds r1, #0x3c
    strb r0, [r1]
    ldr r2, [r3]
    ldr r1, lbl_08084100 @ =0x0847cfe4
    adds r0, r2, #0
    adds r0, #0x3c
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    str r0, [r2, #0x14]
    adds r1, r2, #0
    adds r1, #0x50
    ldrh r0, [r1]
    subs r0, #4
    strh r0, [r1]
    adds r1, #0x14
    ldrh r0, [r1]
    adds r0, #2
    strh r0, [r1]
    subs r1, #0x1e
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_080840ea:
    bl tourian_escape_process_oam
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080840f8: .4byte sNonGameplayRamPointer
lbl_080840fc: .4byte gWrittenToBLDY_NonGameplay
lbl_08084100: .4byte 0x0847cfe4

    thumb_func_start TourianEscapeSamusLookingAtSky
TourianEscapeSamusLookingAtSky: @ 0x08084104
    push {r4, r5, r6, lr}
    movs r5, #0
    ldr r3, lbl_08084134 @ =sNonGameplayRamPointer
    ldr r2, [r3]
    ldrh r0, [r2, #6]
    adds r1, r0, #1
    strh r1, [r2, #6]
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0x10
    bne lbl_0808411c
    b lbl_0808425c
lbl_0808411c:
    cmp r1, #0x10
    bgt lbl_08084142
    cmp r1, #2
    beq lbl_08084190
    cmp r1, #2
    bgt lbl_08084138
    cmp r1, #0
    beq lbl_0808416a
    cmp r1, #1
    beq lbl_0808417c
    b lbl_080842ce
    .align 2, 0
lbl_08084134: .4byte sNonGameplayRamPointer
lbl_08084138:
    cmp r1, #3
    beq lbl_080841a4
    cmp r1, #4
    beq lbl_0808421c
    b lbl_080842ce
lbl_08084142:
    cmp r1, #0x68
    bne lbl_08084148
    b lbl_080842b4
lbl_08084148:
    cmp r1, #0x68
    bgt lbl_0808415a
    cmp r1, #0x18
    bne lbl_08084152
    b lbl_0808428c
lbl_08084152:
    cmp r1, #0x60
    bne lbl_08084158
    b lbl_080842b0
lbl_08084158:
    b lbl_080842ce
lbl_0808415a:
    cmp r1, #0xa0
    beq lbl_0808423e
    movs r0, #0xd8
    lsls r0, r0, #1
    cmp r1, r0
    bne lbl_08084168
    b lbl_080842b8
lbl_08084168:
    b lbl_080842ce
lbl_0808416a:
    ldr r0, lbl_08084178 @ =0x084b518c
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    b lbl_080842ce
    .align 2, 0
lbl_08084178: .4byte 0x084b518c
lbl_0808417c:
    ldr r0, lbl_08084188 @ =0x084b1b90
    ldr r1, lbl_0808418c @ =0x06008000
    bl LZ77UncompVRAM
    b lbl_080842ce
    .align 2, 0
lbl_08084188: .4byte 0x084b1b90
lbl_0808418c: .4byte 0x06008000
lbl_08084190:
    ldr r0, lbl_0808419c @ =0x084b0e04
    ldr r1, lbl_080841a0 @ =0x06010000
    bl LZ77UncompVRAM
    b lbl_080842ce
    .align 2, 0
lbl_0808419c: .4byte 0x084b0e04
lbl_080841a0: .4byte 0x06010000
lbl_080841a4:
    ldr r0, lbl_080841e8 @ =0x084b4b50
    ldr r1, lbl_080841ec @ =0x0600e000
    bl LZ77UncompVRAM
    ldr r0, lbl_080841f0 @ =0x084b90fc
    ldr r1, lbl_080841f4 @ =0x0600f000
    bl LZ77UncompVRAM
    ldr r0, lbl_080841f8 @ =0x084b97b4
    ldr r1, lbl_080841fc @ =0x0600f800
    bl LZ77UncompVRAM
    ldr r0, lbl_08084200 @ =0x040000d4
    ldr r3, lbl_08084204 @ =0x0847a260
    str r3, [r0]
    movs r1, #0xa0
    lsls r1, r1, #0x13
    str r1, [r0, #4]
    ldr r2, lbl_08084208 @ =0x800000a0
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    str r3, [r0]
    ldr r1, lbl_0808420c @ =0x05000200
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    ldr r0, lbl_08084210 @ =gBg0YPosition
    strh r5, [r0]
    ldr r0, lbl_08084214 @ =gBg1YPosition
    strh r5, [r0]
    ldr r1, lbl_08084218 @ =gBg2YPosition
    movs r0, #0x60
    strh r0, [r1]
    b lbl_080842ce
    .align 2, 0
lbl_080841e8: .4byte 0x084b4b50
lbl_080841ec: .4byte 0x0600e000
lbl_080841f0: .4byte 0x084b90fc
lbl_080841f4: .4byte 0x0600f000
lbl_080841f8: .4byte 0x084b97b4
lbl_080841fc: .4byte 0x0600f800
lbl_08084200: .4byte 0x040000d4
lbl_08084204: .4byte 0x0847a260
lbl_08084208: .4byte 0x800000a0
lbl_0808420c: .4byte 0x05000200
lbl_08084210: .4byte gBg0YPosition
lbl_08084214: .4byte gBg1YPosition
lbl_08084218: .4byte gBg2YPosition
lbl_0808421c:
    ldr r1, lbl_0808424c @ =0x04000008
    ldr r3, lbl_08084250 @ =0x00001c0a
    adds r0, r3, #0
    strh r0, [r1]
    adds r1, #2
    ldr r3, lbl_08084254 @ =0x00001e01
    adds r0, r3, #0
    strh r0, [r1]
    adds r1, #2
    adds r3, #0xff
    adds r0, r3, #0
    strh r0, [r1]
    adds r1, r2, #0
    adds r1, #0xc0
    movs r0, #0xb8
    lsls r0, r0, #5
    strh r0, [r1]
lbl_0808423e:
    ldr r0, lbl_08084258 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrb r0, [r1, #2]
    adds r0, #1
    strb r0, [r1, #2]
    b lbl_080842ce
    .align 2, 0
lbl_0808424c: .4byte 0x04000008
lbl_08084250: .4byte 0x00001c0a
lbl_08084254: .4byte 0x00001e01
lbl_08084258: .4byte sNonGameplayRamPointer
lbl_0808425c:
    movs r0, #1
    strb r0, [r2, #8]
    ldr r2, [r3]
    ldr r0, lbl_08084284 @ =0x0847abba
    str r0, [r2, #0x14]
    adds r1, r2, #0
    adds r1, #0x50
    movs r0, #0x70
    strh r0, [r1]
    adds r1, #0x14
    movs r0, #0xd0
    strh r0, [r1]
    adds r1, #0x14
    movs r0, #2
    strb r0, [r1]
    ldr r0, lbl_08084288 @ =0x0000024b
    bl SoundPlay
    b lbl_080842ce
    .align 2, 0
lbl_08084284: .4byte 0x0847abba
lbl_08084288: .4byte 0x0000024b
lbl_0808428c:
    movs r0, #1
    strb r0, [r2, #9]
    ldr r1, [r3]
    ldr r0, lbl_080842ac @ =0x0847abc8
    str r0, [r1, #0x18]
    adds r2, r1, #0
    adds r2, #0x52
    movs r0, #0x20
    strh r0, [r2]
    adds r2, #0x14
    movs r0, #0xd0
    strh r0, [r2]
    adds r1, #0x79
    movs r0, #2
    strb r0, [r1]
    b lbl_080842ce
    .align 2, 0
lbl_080842ac: .4byte 0x0847abc8
lbl_080842b0:
    strb r5, [r2, #8]
    b lbl_080842ce
lbl_080842b4:
    strb r5, [r2, #9]
    b lbl_080842ce
lbl_080842b8:
    movs r0, #0xa0
    lsls r0, r0, #0x13
    strh r5, [r0]
    adds r0, r2, #0
    adds r0, #0xc0
    strh r5, [r0]
    ldr r0, lbl_080842f0 @ =gBg0YPosition
    strh r5, [r0]
    ldr r0, lbl_080842f4 @ =gBg1YPosition
    strh r5, [r0]
    movs r5, #1
lbl_080842ce:
    ldr r3, lbl_080842f8 @ =sNonGameplayRamPointer
    ldr r2, [r3]
    ldrb r1, [r2, #2]
    cmp r1, #1
    bne lbl_08084308
    ldrh r0, [r2, #6]
    ands r1, r0
    cmp r1, #0
    beq lbl_08084338
    ldr r3, lbl_080842fc @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r3]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_08084300
    subs r0, #1
    strh r0, [r3]
    b lbl_08084338
    .align 2, 0
lbl_080842f0: .4byte gBg0YPosition
lbl_080842f4: .4byte gBg1YPosition
lbl_080842f8: .4byte sNonGameplayRamPointer
lbl_080842fc: .4byte gWrittenToBLDY_NonGameplay
lbl_08084300:
    adds r0, r2, #0
    adds r0, #0xc2
    strh r1, [r0]
    b lbl_08084338
lbl_08084308:
    cmp r1, #2
    bne lbl_08084338
    ldr r0, lbl_0808437c @ =gBg0YPosition
    ldrh r1, [r0]
    adds r1, #1
    strh r1, [r0]
    ldr r2, lbl_08084380 @ =gBg1YPosition
    ldrh r0, [r2]
    adds r0, #1
    strh r0, [r2]
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    ldr r2, lbl_08084384 @ =gBg2YPosition
    cmp r1, #0x5f
    bls lbl_0808432c
    ldrh r0, [r2]
    adds r0, #1
    strh r0, [r2]
lbl_0808432c:
    ldrb r0, [r2]
    cmp r0, #0xa0
    bne lbl_08084338
    ldr r1, [r3]
    movs r0, #0
    strb r0, [r1, #2]
lbl_08084338:
    movs r4, #0
    ldr r6, lbl_08084388 @ =sNonGameplayRamPointer
lbl_0808433c:
    ldr r3, [r6]
    adds r0, r3, #0
    adds r0, #8
    adds r0, r0, r4
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08084364
    lsls r2, r4, #1
    adds r1, r3, #0
    adds r1, #0x50
    adds r1, r1, r2
    ldrh r0, [r1]
    adds r0, #2
    strh r0, [r1]
    adds r1, r3, #0
    adds r1, #0x64
    adds r1, r1, r2
    ldrh r0, [r1]
    subs r0, #3
    strh r0, [r1]
lbl_08084364:
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #1
    bls lbl_0808433c
    bl tourian_escape_process_oam
    adds r0, r5, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0808437c: .4byte gBg0YPosition
lbl_08084380: .4byte gBg1YPosition
lbl_08084384: .4byte gBg2YPosition
lbl_08084388: .4byte sNonGameplayRamPointer

    thumb_func_start TourianEscapeSamusLookingAtMotherShip
TourianEscapeSamusLookingAtMotherShip: @ 0x0808438c
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    movs r7, #0
    ldr r6, lbl_080843bc @ =sNonGameplayRamPointer
    ldr r3, [r6]
    ldrh r2, [r3, #6]
    adds r0, r2, #1
    strh r0, [r3, #6]
    lsls r0, r2, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #5
    bne lbl_080843a6
    b lbl_0808457c
lbl_080843a6:
    cmp r1, #5
    bgt lbl_080843cc
    cmp r1, #2
    beq lbl_0808441c
    cmp r1, #2
    bgt lbl_080843c0
    cmp r1, #0
    beq lbl_080843f6
    cmp r1, #1
    beq lbl_08084408
    b lbl_0808459a
    .align 2, 0
lbl_080843bc: .4byte sNonGameplayRamPointer
lbl_080843c0:
    cmp r1, #3
    beq lbl_08084470
    cmp r1, #4
    bne lbl_080843ca
    b lbl_0808453c
lbl_080843ca:
    b lbl_0808459a
lbl_080843cc:
    cmp r1, #0xa0
    bne lbl_080843d2
    b lbl_0808455e
lbl_080843d2:
    cmp r1, #0xa0
    bgt lbl_080843e4
    cmp r1, #6
    bne lbl_080843dc
    b lbl_08084584
lbl_080843dc:
    cmp r1, #0x60
    bne lbl_080843e2
    b lbl_0808455e
lbl_080843e2:
    b lbl_0808459a
lbl_080843e4:
    cmp r1, #0xe0
    bne lbl_080843ea
    b lbl_08084584
lbl_080843ea:
    movs r0, #0xe0
    lsls r0, r0, #1
    cmp r1, r0
    bne lbl_080843f4
    b lbl_08084598
lbl_080843f4:
    b lbl_0808459a
lbl_080843f6:
    ldr r0, lbl_08084404 @ =0x084b9a98
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    b lbl_0808459a
    .align 2, 0
lbl_08084404: .4byte 0x084b9a98
lbl_08084408:
    ldr r0, lbl_08084414 @ =0x084bc540
    ldr r1, lbl_08084418 @ =0x06008000
    bl LZ77UncompVRAM
    b lbl_0808459a
    .align 2, 0
lbl_08084414: .4byte 0x084bc540
lbl_08084418: .4byte 0x06008000
lbl_0808441c:
    ldr r0, lbl_0808444c @ =0x084bbc3c
    ldr r1, lbl_08084450 @ =0x06007000
    bl LZ77UncompVRAM
    ldr r0, lbl_08084454 @ =0x084bf5e0
    ldr r1, lbl_08084458 @ =0x0600f000
    bl LZ77UncompVRAM
    ldr r1, lbl_0808445c @ =0x040000d4
    ldr r0, lbl_08084460 @ =0x0847a3a0
    str r0, [r1]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_08084464 @ =0x800000a0
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r1, lbl_08084468 @ =gBg0XPosition
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_0808446c @ =gBg1XPosition
    strh r7, [r0]
    b lbl_0808459a
    .align 2, 0
lbl_0808444c: .4byte 0x084bbc3c
lbl_08084450: .4byte 0x06007000
lbl_08084454: .4byte 0x084bf5e0
lbl_08084458: .4byte 0x0600f000
lbl_0808445c: .4byte 0x040000d4
lbl_08084460: .4byte 0x0847a3a0
lbl_08084464: .4byte 0x800000a0
lbl_08084468: .4byte gBg0XPosition
lbl_0808446c: .4byte gBg1XPosition
lbl_08084470:
    ldr r4, lbl_08084508 @ =0x06010000
    movs r3, #0x80
    lsls r3, r3, #8
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r4, #0
    bl BitFill
    ldr r0, lbl_0808450c @ =0x0847abd8
    adds r1, r4, #0
    bl LZ77UncompVRAM
    ldr r0, lbl_08084510 @ =0x040000d4
    ldr r1, lbl_08084514 @ =0x0847ac26
    str r1, [r0]
    ldr r1, lbl_08084518 @ =0x05000200
    str r1, [r0, #4]
    ldr r2, lbl_0808451c @ =0x80000010
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_08084520 @ =0x08375738
    str r1, [r0]
    ldr r1, lbl_08084524 @ =0x050003e0
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    movs r5, #0
    adds r4, r6, #0
    movs r6, #0
lbl_080844ae:
    ldr r0, [r4]
    adds r0, #8
    adds r0, r0, r5
    movs r1, #1
    strb r1, [r0]
    ldr r1, [r4]
    adds r1, #0x46
    adds r1, r1, r5
    ldr r0, lbl_08084528 @ =0x0847cff4
    adds r0, r5, r0
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r3, [r4]
    lsls r2, r5, #1
    adds r1, r3, #0
    adds r1, #0x50
    adds r1, r1, r2
    ldr r0, lbl_0808452c @ =0x0847cffe
    adds r0, r2, r0
    ldrh r0, [r0]
    strh r0, [r1]
    adds r0, r3, #0
    adds r0, #0x64
    adds r0, r0, r2
    movs r1, #0xfc
    strh r1, [r0]
    adds r0, r3, #0
    adds r0, #0x78
    adds r0, r0, r5
    strb r6, [r0]
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #9
    bls lbl_080844ae
    ldr r0, lbl_08084530 @ =gWrittenToBLDALPHA_L
    movs r2, #0
    strh r2, [r0]
    ldr r1, lbl_08084534 @ =gWrittenToBLDALPHA_H
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_08084538 @ =gWrittenToBLDY_NonGameplay
    strh r2, [r0]
    b lbl_0808459a
    .align 2, 0
lbl_08084508: .4byte 0x06010000
lbl_0808450c: .4byte 0x0847abd8
lbl_08084510: .4byte 0x040000d4
lbl_08084514: .4byte 0x0847ac26
lbl_08084518: .4byte 0x05000200
lbl_0808451c: .4byte 0x80000010
lbl_08084520: .4byte 0x08375738
lbl_08084524: .4byte 0x050003e0
lbl_08084528: .4byte 0x0847cff4
lbl_0808452c: .4byte 0x0847cffe
lbl_08084530: .4byte gWrittenToBLDALPHA_L
lbl_08084534: .4byte gWrittenToBLDALPHA_H
lbl_08084538: .4byte gWrittenToBLDY_NonGameplay
lbl_0808453c:
    ldr r1, lbl_0808456c @ =0x04000008
    movs r2, #0xe0
    lsls r2, r2, #4
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    ldr r2, lbl_08084570 @ =0x00001e09
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, r3, #0
    adds r1, #0xc0
    movs r0, #0x98
    lsls r0, r0, #5
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_08084574 @ =0x00000fcf
    strh r0, [r1]
lbl_0808455e:
    ldr r0, lbl_08084578 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrb r0, [r1, #2]
    adds r0, #1
    strb r0, [r1, #2]
    b lbl_0808459a
    .align 2, 0
lbl_0808456c: .4byte 0x04000008
lbl_08084570: .4byte 0x00001e09
lbl_08084574: .4byte 0x00000fcf
lbl_08084578: .4byte sNonGameplayRamPointer
lbl_0808457c:
    movs r0, #1
    bl TextStartStory
    b lbl_0808459a
lbl_08084584:
    ldr r0, lbl_08084594 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r1, #0xbe
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0808459a
    .align 2, 0
lbl_08084594: .4byte sNonGameplayRamPointer
lbl_08084598:
    strh r2, [r3, #6]
lbl_0808459a:
    ldr r0, lbl_080845d8 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrh r1, [r0, #6]
    ldr r0, lbl_080845dc @ =0x000001bf
    cmp r1, r0
    bls lbl_080845b4
    ldr r0, lbl_080845e0 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_080845b4
    movs r7, #2
lbl_080845b4:
    ldr r4, lbl_080845d8 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r1, r0, #0
    adds r1, #0xbe
    ldrb r3, [r1]
    cmp r3, #1
    bne lbl_080845e4
    bl TextProcessStory
    cmp r0, #0
    beq lbl_0808460a
    ldr r1, [r4]
    adds r1, #0xbe
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0808460a
    .align 2, 0
lbl_080845d8: .4byte sNonGameplayRamPointer
lbl_080845dc: .4byte 0x000001bf
lbl_080845e0: .4byte gChangedInput
lbl_080845e4:
    cmp r3, #3
    bne lbl_0808460a
    adds r0, #0xbf
    ldrb r2, [r0]
    adds r1, r2, #1
    strb r1, [r0]
    ands r3, r2
    cmp r3, #0
    bne lbl_0808460a
    ldr r1, lbl_08084684 @ =gWrittenToBLDALPHA_L
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_0808460a
    adds r0, #1
    strh r0, [r1]
    ldr r2, lbl_08084688 @ =gWrittenToBLDALPHA_H
    movs r1, #0x10
    subs r1, r1, r0
    strh r1, [r2]
lbl_0808460a:
    ldr r0, lbl_0808468c @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrb r1, [r2, #2]
    adds r3, r0, #0
    cmp r1, #1
    bhi lbl_08084640
    ldrb r1, [r2, #5]
    adds r0, r1, #1
    strb r0, [r2, #5]
    movs r5, #0xf
    ands r5, r1
    cmp r5, #0
    bne lbl_08084634
    ldr r1, lbl_08084690 @ =gBg0XPosition
    ldrh r0, [r1]
    subs r0, #1
    strh r0, [r1]
    ldr r1, lbl_08084694 @ =gBg1XPosition
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
lbl_08084634:
    cmp r5, #8
    bne lbl_08084640
    ldr r1, lbl_08084694 @ =gBg1XPosition
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
lbl_08084640:
    ldr r1, [r3]
    ldrb r0, [r1, #2]
    cmp r0, #3
    bne lbl_0808465e
    ldrh r1, [r1, #6]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0808465e
    ldr r1, lbl_08084698 @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r1]
    cmp r0, #3
    bhi lbl_0808465e
    adds r0, #1
    strh r0, [r1]
lbl_0808465e:
    movs r5, #0
    ldr r6, lbl_0808468c @ =sNonGameplayRamPointer
lbl_08084662:
    ldr r2, [r6]
    adds r0, r2, #0
    adds r0, #8
    adds r0, r0, r5
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080846f8
    adds r0, r2, #0
    adds r0, #0x46
    adds r1, r0, r5
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0808469c
    subs r0, #1
    strb r0, [r1]
    b lbl_080846f8
    .align 2, 0
lbl_08084684: .4byte gWrittenToBLDALPHA_L
lbl_08084688: .4byte gWrittenToBLDALPHA_H
lbl_0808468c: .4byte sNonGameplayRamPointer
lbl_08084690: .4byte gBg0XPosition
lbl_08084694: .4byte gBg1XPosition
lbl_08084698: .4byte gWrittenToBLDY_NonGameplay
lbl_0808469c:
    lsls r3, r5, #1
    adds r0, r2, #0
    adds r0, #0x50
    adds r4, r0, r3
    ldrh r0, [r4]
    subs r0, #2
    strh r0, [r4]
    adds r0, r2, #0
    adds r0, #0x64
    adds r2, r0, r3
    ldrh r0, [r2]
    adds r1, r0, #4
    strh r1, [r2]
    subs r0, #0xa0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0xc
    bhi lbl_080846cc
    ldr r0, lbl_080846e4 @ =0x0847cffe
    adds r0, r3, r0
    ldrh r0, [r0]
    strh r0, [r4]
    movs r0, #0xfc
    strh r0, [r2]
lbl_080846cc:
    ldr r2, [r6]
    ldrh r1, [r2, #6]
    movs r0, #7
    ands r0, r1
    cmp r0, #3
    bhi lbl_080846ec
    lsls r0, r5, #2
    adds r1, r2, #0
    adds r1, #0x14
    adds r1, r1, r0
    ldr r0, lbl_080846e8 @ =0x0847ac10
    b lbl_080846f6
    .align 2, 0
lbl_080846e4: .4byte 0x0847cffe
lbl_080846e8: .4byte 0x0847ac10
lbl_080846ec:
    lsls r0, r5, #2
    adds r1, r2, #0
    adds r1, #0x14
    adds r1, r1, r0
    ldr r0, lbl_08084710 @ =0x0847ac18
lbl_080846f6:
    str r0, [r1]
lbl_080846f8:
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #9
    bls lbl_08084662
    bl tourian_escape_process_oam
    adds r0, r7, #0
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08084710: .4byte 0x0847ac18

    thumb_func_start TourianEscapeCallSubroutines
TourianEscapeCallSubroutines: @ 0x08084714
    push {r4, r5, r6, lr}
    movs r6, #0
    ldr r0, lbl_08084730 @ =gNextOamSlot
    strb r6, [r0]
    ldr r5, lbl_08084734 @ =gGameModeSub1
    movs r1, #0
    ldrsh r0, [r5, r1]
    cmp r0, #1
    beq lbl_08084748
    cmp r0, #1
    bgt lbl_08084738
    cmp r0, #0
    beq lbl_08084742
    b lbl_080847ee
    .align 2, 0
lbl_08084730: .4byte gNextOamSlot
lbl_08084734: .4byte gGameModeSub1
lbl_08084738:
    cmp r0, #2
    beq lbl_08084770
    cmp r0, #3
    beq lbl_080847ec
    b lbl_080847ee
lbl_08084742:
    bl tourian_escape_init
    b lbl_08084764
lbl_08084748:
    ldr r1, lbl_08084758 @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_0808475c
    subs r0, #1
    strh r0, [r1]
    b lbl_080847ee
    .align 2, 0
lbl_08084758: .4byte gWrittenToBLDY_NonGameplay
lbl_0808475c:
    ldr r0, lbl_0808476c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xc2
    strh r6, [r0]
lbl_08084764:
    ldrh r0, [r5]
    adds r0, #1
    strh r0, [r5]
    b lbl_080847ee
    .align 2, 0
lbl_0808476c: .4byte sNonGameplayRamPointer
lbl_08084770:
    ldr r1, lbl_080847d4 @ =0x08760cc8
    ldr r4, lbl_080847d8 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    bl _call_via_r0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_080847dc
    ldr r1, [r4]
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r4]
    strb r6, [r0, #2]
    ldr r0, [r4]
    strb r6, [r0, #5]
    ldr r0, [r4]
    movs r1, #0
    strh r6, [r0, #6]
    strb r1, [r0, #1]
    movs r1, #0
    adds r3, r4, #0
    movs r2, #0
lbl_080847a8:
    ldr r0, [r3]
    adds r0, #8
    adds r0, r0, r1
    strb r2, [r0]
    ldr r0, [r3]
    adds r0, #0x46
    adds r0, r0, r1
    strb r2, [r0]
    ldr r0, [r3]
    adds r0, #0x78
    adds r0, r0, r1
    strb r2, [r0]
    cmp r1, #3
    bgt lbl_080847cc
    ldr r0, [r4]
    adds r0, #0x3c
    adds r0, r0, r1
    strb r2, [r0]
lbl_080847cc:
    adds r1, #1
    cmp r1, #9
    ble lbl_080847a8
    b lbl_080847e6
    .align 2, 0
lbl_080847d4: .4byte 0x08760cc8
lbl_080847d8: .4byte sNonGameplayRamPointer
lbl_080847dc:
    cmp r0, #0
    beq lbl_080847e6
    ldrh r0, [r5]
    adds r0, #1
    strh r0, [r5]
lbl_080847e6:
    bl ResetFreeOam
    b lbl_080847ee
lbl_080847ec:
    movs r6, #1
lbl_080847ee:
    adds r0, r6, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
