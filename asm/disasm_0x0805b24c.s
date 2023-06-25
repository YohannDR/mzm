    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start unk_5b24c
unk_5b24c: @ 0x0805b24c
    push {r4, r5, lr}
    sub sp, #4
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r2, lbl_0805b27c @ =0x02035400
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805b280 @ =0x05000200
    ldr r2, lbl_0805b284 @ =0x02035600
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b27c: .4byte 0x02035400
lbl_0805b280: .4byte 0x05000200
lbl_0805b284: .4byte 0x02035600

    thumb_func_start sub_0805b288
sub_0805b288: @ 0x0805b288
    push {r4, r5, lr}
    sub sp, #4
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r2, lbl_0805b2b8 @ =0x02035000
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805b2bc @ =0x05000200
    ldr r2, lbl_0805b2c0 @ =0x02035200
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b2b8: .4byte 0x02035000
lbl_0805b2bc: .4byte 0x05000200
lbl_0805b2c0: .4byte 0x02035200

    thumb_func_start unk_5b2c4
unk_5b2c4: @ 0x0805b2c4
    push {r4, r5, lr}
    sub sp, #4
    ldr r1, lbl_0805b2f4 @ =0x02035400
    ldr r2, lbl_0805b2f8 @ =0x02035000
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805b2fc @ =0x02035600
    ldr r2, lbl_0805b300 @ =0x02035200
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b2f4: .4byte 0x02035400
lbl_0805b2f8: .4byte 0x02035000
lbl_0805b2fc: .4byte 0x02035600
lbl_0805b300: .4byte 0x02035200

    thumb_func_start unk_5b304
unk_5b304: @ 0x0805b304
    push {r4, r5, lr}
    sub sp, #4
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r2, lbl_0805b334 @ =0x02035800
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805b338 @ =0x05000200
    ldr r2, lbl_0805b33c @ =0x02035a00
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b334: .4byte 0x02035800
lbl_0805b338: .4byte 0x05000200
lbl_0805b33c: .4byte 0x02035a00

    thumb_func_start unk_5b340
unk_5b340: @ 0x0805b340
    push {lr}
    bl unk_5b24c
    bl sub_0805b288
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0805b350
sub_0805b350: @ 0x0805b350
    push {r4, r5, lr}
    sub sp, #4
    ldr r1, lbl_0805b380 @ =0x02035400
    ldr r2, lbl_0805b384 @ =0x02035800
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805b388 @ =0x02035600
    ldr r2, lbl_0805b38c @ =0x02035a00
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b380: .4byte 0x02035400
lbl_0805b384: .4byte 0x02035800
lbl_0805b388: .4byte 0x02035600
lbl_0805b38c: .4byte 0x02035a00

    thumb_func_start sub_0805b390
sub_0805b390: @ 0x0805b390
    push {r4, lr}
    sub sp, #4
    ldr r4, lbl_0805b3ec @ =gColorFading
    ldrb r1, [r4, #4]
    cmp r1, #0
    beq lbl_0805b3e4
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b3c0
    ldr r1, lbl_0805b3f0 @ =0x02035000
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r1, [r4, #4]
    movs r0, #0xfe
    ands r0, r1
    strb r0, [r4, #4]
lbl_0805b3c0:
    ldrb r1, [r4, #4]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b3e4
    ldr r1, lbl_0805b3f4 @ =0x02035200
    ldr r2, lbl_0805b3f8 @ =0x05000200
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r1, [r4, #4]
    movs r0, #0xfd
    ands r0, r1
    strb r0, [r4, #4]
lbl_0805b3e4:
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b3ec: .4byte gColorFading
lbl_0805b3f0: .4byte 0x02035000
lbl_0805b3f4: .4byte 0x02035200
lbl_0805b3f8: .4byte 0x05000200

    thumb_func_start CheckTransferFadedPalette
CheckTransferFadedPalette: @ 0x0805b3fc
    push {r4, r5, lr}
    sub sp, #4
    ldr r0, lbl_0805b45c @ =gGameModeSub1
    movs r1, #0
    ldrsh r4, [r0, r1]
    cmp r4, #2
    bne lbl_0805b470
    ldr r5, lbl_0805b460 @ =gColorFading
    ldrb r1, [r5, #4]
    cmp r1, #0
    beq lbl_0805b4c0
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b436
    ldr r1, lbl_0805b464 @ =0x02035000
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r0, [r5, #4]
    movs r1, #1
    eors r0, r1
    strb r0, [r5, #4]
lbl_0805b436:
    ldrb r0, [r5, #4]
    ands r4, r0
    cmp r4, #0
    beq lbl_0805b4c0
    ldr r1, lbl_0805b468 @ =0x02035240
    ldr r2, lbl_0805b46c @ =0x05000240
    movs r3, #0xe0
    lsls r3, r3, #1
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r0, [r5, #4]
    movs r1, #2
    eors r0, r1
    strb r0, [r5, #4]
    b lbl_0805b4c0
    .align 2, 0
lbl_0805b45c: .4byte gGameModeSub1
lbl_0805b460: .4byte gColorFading
lbl_0805b464: .4byte 0x02035000
lbl_0805b468: .4byte 0x02035240
lbl_0805b46c: .4byte 0x05000240
lbl_0805b470:
    ldr r4, lbl_0805b4c8 @ =gColorFading
    ldrb r1, [r4, #4]
    cmp r1, #0
    beq lbl_0805b4c0
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b49c
    ldr r1, lbl_0805b4cc @ =0x02035000
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r1, [r4, #4]
    movs r0, #0xfe
    ands r0, r1
    strb r0, [r4, #4]
lbl_0805b49c:
    ldrb r1, [r4, #4]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b4c0
    ldr r1, lbl_0805b4d0 @ =0x02035200
    ldr r2, lbl_0805b4d4 @ =0x05000200
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r1, [r4, #4]
    movs r0, #0xfd
    ands r0, r1
    strb r0, [r4, #4]
lbl_0805b4c0:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b4c8: .4byte gColorFading
lbl_0805b4cc: .4byte 0x02035000
lbl_0805b4d0: .4byte 0x02035200
lbl_0805b4d4: .4byte 0x05000200

    thumb_func_start CallApplySpecialBackgroundFadingColor
CallApplySpecialBackgroundFadingColor: @ 0x0805b4d8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    ldr r2, lbl_0805b508 @ =0x08345d00
    ldr r3, lbl_0805b50c @ =gColorFading
    ldrb r1, [r3]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0]
    mov r8, r2
    adds r6, r3, #0
    cmp r0, #0
    beq lbl_0805b510
    ldrb r0, [r6, #5]
    movs r5, #3
    cmp r0, #0
    bne lbl_0805b51c
    movs r5, #1
    b lbl_0805b51c
    .align 2, 0
lbl_0805b508: .4byte 0x08345d00
lbl_0805b50c: .4byte gColorFading
lbl_0805b510:
    ldrb r1, [r6, #5]
    movs r5, #2
    rsbs r0, r1, #0
    orrs r0, r1
    asrs r0, r0, #0x1f
    ands r5, r0
lbl_0805b51c:
    ldr r0, lbl_0805b574 @ =0x02035000
    str r0, [sp, #8]
    ldr r0, lbl_0805b578 @ =0x02035400
    str r0, [sp, #4]
    ldrb r1, [r6]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    add r0, r8
    ldrh r0, [r0, #0x12]
    add r4, sp, #8
    str r0, [sp]
    adds r0, r5, #0
    adds r1, r7, #0
    add r2, sp, #4
    adds r3, r4, #0
    bl ApplySpecialBackgroundFadingColor
    ldr r0, lbl_0805b57c @ =0x02035200
    str r0, [sp, #8]
    ldr r0, lbl_0805b580 @ =0x02035600
    str r0, [sp, #4]
    ldrb r1, [r6]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    add r0, r8
    ldrh r0, [r0, #0x14]
    str r0, [sp]
    adds r0, r5, #0
    adds r1, r7, #0
    add r2, sp, #4
    adds r3, r4, #0
    bl ApplySpecialBackgroundFadingColor
    movs r0, #3
    strb r0, [r6, #4]
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b574: .4byte 0x02035000
lbl_0805b578: .4byte 0x02035400
lbl_0805b57c: .4byte 0x02035200
lbl_0805b580: .4byte 0x02035600

    thumb_func_start PowerBombYellowTint
PowerBombYellowTint: @ 0x0805b584
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    ldr r0, lbl_0805b618 @ =gAnimatedGraphicsEntry
    ldrb r0, [r0]
    movs r7, #0xf0
    cmp r0, #0
    bne lbl_0805b598
    adds r7, #0x10
lbl_0805b598:
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r4, lbl_0805b61c @ =0x02035000
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl DMATransfer
    lsls r0, r6, #5
    adds r5, r0, r4
    lsls r4, r6, #4
    cmp r4, r7
    bge lbl_0805b604
    movs r0, #0xf8
    lsls r0, r0, #2
    mov ip, r0
    movs r6, #0xf8
    lsls r6, r6, #7
lbl_0805b5c2:
    movs r0, #0xf
    ands r0, r4
    cmp r0, #0
    beq lbl_0805b5fc
    ldrh r2, [r5]
    movs r3, #0x1f
    ands r3, r2
    mov r1, ip
    ands r1, r2
    adds r0, r6, #0
    ands r0, r2
    lsrs r0, r0, #0xa
    adds r3, #5
    lsls r1, r1, #0x13
    movs r2, #0xa0
    lsls r2, r2, #0x13
    adds r1, r1, r2
    lsrs r1, r1, #0x18
    cmp r3, #0x1f
    bls lbl_0805b5ec
    movs r3, #0x1f
lbl_0805b5ec:
    cmp r1, #0x1f
    bls lbl_0805b5f2
    movs r1, #0x1f
lbl_0805b5f2:
    lsls r0, r0, #0xa
    lsls r1, r1, #5
    orrs r0, r1
    orrs r0, r3
    strh r0, [r5]
lbl_0805b5fc:
    adds r4, #1
    adds r5, #2
    cmp r4, r7
    blt lbl_0805b5c2
lbl_0805b604:
    ldr r2, lbl_0805b620 @ =gColorFading
    ldrb r1, [r2, #4]
    movs r0, #1
    orrs r0, r1
    strb r0, [r2, #4]
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b618: .4byte gAnimatedGraphicsEntry
lbl_0805b61c: .4byte 0x02035000
lbl_0805b620: .4byte gColorFading

    thumb_func_start ApplyMonochromeToPalette
ApplyMonochromeToPalette: @ 0x0805b624
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r5, r0, #0
    adds r4, r1, #0
    lsls r2, r2, #0x18
    asrs r2, r2, #0x18
    mov r8, r2
    movs r6, #0xff
lbl_0805b636:
    ldrh r2, [r5]
    movs r0, #0x1f
    ands r0, r2
    movs r3, #0xf8
    lsls r3, r3, #2
    adds r1, r3, #0
    adds r3, r2, #0
    ands r3, r1
    lsrs r3, r3, #5
    movs r7, #0xf8
    lsls r7, r7, #7
    adds r1, r7, #0
    ands r2, r1
    lsrs r2, r2, #0xa
    adds r0, r0, r3
    adds r0, r0, r2
    movs r1, #3
    bl __divsi3
    mov r1, r8
    adds r2, r0, r1
    cmp r2, #0
    bge lbl_0805b668
    movs r2, #0
    b lbl_0805b66e
lbl_0805b668:
    cmp r2, #0x1f
    ble lbl_0805b66e
    movs r2, #0x1f
lbl_0805b66e:
    lsls r0, r2, #0xa
    lsls r1, r2, #5
    orrs r0, r1
    orrs r0, r2
    strh r0, [r4]
    subs r6, #1
    adds r5, #2
    adds r4, #2
    cmp r6, #0
    bge lbl_0805b636
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start ApplySmoothMonochromeToPalette
ApplySmoothMonochromeToPalette: @ 0x0805b68c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    mov sl, r0
    mov r8, r1
    mov ip, r2
    lsls r3, r3, #0x18
    lsrs r7, r3, #0x18
    cmp r7, #0
    bne lbl_0805b6b8
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    mov r1, sl
    bl DMATransfer
    b lbl_0805b752
lbl_0805b6b8:
    cmp r7, #0x1e
    bls lbl_0805b6d0
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    mov r1, r8
    mov r2, ip
    bl DMATransfer
    b lbl_0805b752
lbl_0805b6d0:
    movs r0, #0x1f
    mov sb, r0
    movs r1, #0xff
    str r1, [sp, #4]
lbl_0805b6d8:
    mov r2, r8
    ldrh r1, [r2]
    adds r0, r1, #0
    mov r4, sb
    ands r0, r4
    asrs r1, r1, #5
    adds r5, r1, #0
    ands r5, r4
    asrs r6, r1, #5
    ands r6, r4
    mov r2, sl
    ldrh r1, [r2]
    adds r3, r1, #0
    ands r3, r4
    asrs r1, r1, #5
    adds r2, r1, #0
    ands r2, r4
    asrs r4, r1, #5
    mov r1, sb
    ands r4, r1
    subs r0, r0, r3
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b70a
    adds r0, #0x1f
lbl_0805b70a:
    asrs r1, r0, #5
    adds r0, r3, r1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    subs r0, r5, r2
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b71c
    adds r0, #0x1f
lbl_0805b71c:
    asrs r1, r0, #5
    adds r0, r2, r1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    subs r0, r6, r4
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b72e
    adds r0, #0x1f
lbl_0805b72e:
    asrs r1, r0, #5
    adds r0, r4, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0xe
    lsls r1, r2, #5
    orrs r0, r1
    orrs r0, r3
    mov r2, ip
    strh r0, [r2]
    ldr r4, [sp, #4]
    subs r4, #1
    str r4, [sp, #4]
    movs r0, #2
    add sl, r0
    add ip, r0
    add r8, r0
    cmp r4, #0
    bge lbl_0805b6d8
lbl_0805b752:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start ApplySmoothPaletteTransition
ApplySmoothPaletteTransition: @ 0x0805b764
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    mov sb, r0
    mov r8, r1
    mov ip, r2
    lsls r3, r3, #0x18
    lsrs r7, r3, #0x18
    cmp r7, #0
    bne lbl_0805b788
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    mov r1, sb
    b lbl_0805b796
lbl_0805b788:
    cmp r7, #0x1e
    bls lbl_0805b79e
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    mov r1, r8
    mov r2, ip
lbl_0805b796:
    movs r3, #0x20
    bl DMATransfer
    b lbl_0805b820
lbl_0805b79e:
    movs r0, #0x1f
    mov sl, r0
    movs r1, #0x1f
    str r1, [sp, #4]
lbl_0805b7a6:
    mov r2, r8
    ldrh r1, [r2]
    adds r0, r1, #0
    mov r4, sl
    ands r0, r4
    asrs r1, r1, #5
    adds r5, r1, #0
    ands r5, r4
    asrs r6, r1, #5
    ands r6, r4
    mov r2, sb
    ldrh r1, [r2]
    adds r3, r1, #0
    ands r3, r4
    asrs r1, r1, #5
    adds r2, r1, #0
    ands r2, r4
    asrs r4, r1, #5
    mov r1, sl
    ands r4, r1
    subs r0, r0, r3
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b7d8
    adds r0, #0x1f
lbl_0805b7d8:
    asrs r1, r0, #5
    adds r0, r3, r1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    subs r0, r5, r2
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b7ea
    adds r0, #0x1f
lbl_0805b7ea:
    asrs r1, r0, #5
    adds r0, r2, r1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    subs r0, r6, r4
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b7fc
    adds r0, #0x1f
lbl_0805b7fc:
    asrs r1, r0, #5
    adds r0, r4, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0xe
    lsls r1, r2, #5
    orrs r0, r1
    orrs r0, r3
    mov r2, ip
    strh r0, [r2]
    ldr r4, [sp, #4]
    subs r4, #1
    str r4, [sp, #4]
    movs r0, #2
    add sb, r0
    add ip, r0
    add r8, r0
    cmp r4, #0
    bge lbl_0805b7a6
lbl_0805b820:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start ApplySpecialBackgroundEffectColorOnBG
ApplySpecialBackgroundEffectColorOnBG: @ 0x0805b830
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #4]
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    lsls r2, r2, #0x18
    lsrs r7, r2, #0x18
    cmp r7, #0
    bne lbl_0805b880
    ldr r5, lbl_0805b878 @ =0x02035800
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r6, #0xf0
    lsls r6, r6, #1
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    ldr r2, lbl_0805b87c @ =0x02035400
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    b lbl_0805b94e
    .align 2, 0
lbl_0805b878: .4byte 0x02035800
lbl_0805b87c: .4byte 0x02035400
lbl_0805b880:
    ldr r1, lbl_0805b960 @ =0x02035800
    ldr r4, lbl_0805b964 @ =0x02035000
    movs r3, #0xf0
    lsls r3, r3, #1
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl DMATransfer
    movs r0, #0x1f
    ands r0, r5
    str r0, [sp, #8]
    movs r0, #0xf8
    lsls r0, r0, #2
    ands r0, r5
    lsrs r0, r0, #5
    mov r8, r0
    movs r0, #0xf8
    lsls r0, r0, #7
    ands r0, r5
    lsrs r0, r0, #0xa
    mov ip, r0
    movs r2, #0
lbl_0805b8b0:
    ldr r1, [sp, #4]
    asrs r1, r2
    movs r0, #1
    ands r1, r0
    adds r4, r2, #1
    str r4, [sp, #0xc]
    cmp r1, #0
    beq lbl_0805b93c
    lsls r3, r2, #4
    adds r1, r3, #0
    adds r1, #0x10
    cmp r3, r1
    bge lbl_0805b93c
    movs r0, #0xf8
    lsls r0, r0, #2
    mov sl, r0
    movs r4, #0xf8
    lsls r4, r4, #7
    mov sb, r4
    lsls r0, r2, #5
    ldr r2, lbl_0805b964 @ =0x02035000
    adds r6, r0, r2
    subs r3, r1, r3
lbl_0805b8de:
    ldrh r1, [r6]
    movs r5, #0x1f
    ands r5, r1
    mov r0, sl
    ands r0, r1
    lsrs r2, r0, #5
    mov r0, sb
    ands r0, r1
    lsrs r1, r0, #0xa
    ldr r4, [sp, #8]
    subs r0, r4, r5
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b8fc
    adds r0, #0xf
lbl_0805b8fc:
    asrs r0, r0, #4
    adds r0, r5, r0
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    mov r4, r8
    subs r0, r4, r2
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b910
    adds r0, #0xf
lbl_0805b910:
    asrs r0, r0, #4
    adds r0, r2, r0
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    mov r4, ip
    subs r0, r4, r1
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b924
    adds r0, #0xf
lbl_0805b924:
    asrs r0, r0, #4
    adds r0, r1, r0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0xe
    lsls r1, r2, #5
    orrs r0, r1
    orrs r0, r5
    strh r0, [r6]
    adds r6, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_0805b8de
lbl_0805b93c:
    ldr r2, [sp, #0xc]
    cmp r2, #0xf
    ble lbl_0805b8b0
    ldr r0, lbl_0805b968 @ =gColorFading
    ldrb r1, [r0, #4]
    movs r0, #1
    orrs r0, r1
    ldr r1, lbl_0805b968 @ =gColorFading
    strb r0, [r1, #4]
lbl_0805b94e:
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b960: .4byte 0x02035800
lbl_0805b964: .4byte 0x02035000
lbl_0805b968: .4byte gColorFading

    thumb_func_start ApplySpecialBackgroundEffectColorOnOBJ
ApplySpecialBackgroundEffectColorOnOBJ: @ 0x0805b96c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #4]
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    lsls r2, r2, #0x18
    lsrs r6, r2, #0x18
    cmp r6, #0
    bne lbl_0805b9bc
    ldr r5, lbl_0805b9b0 @ =0x02035a40
    ldr r2, lbl_0805b9b4 @ =0x05000240
    movs r6, #0xe0
    lsls r6, r6, #1
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    ldr r2, lbl_0805b9b8 @ =0x02035640
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    b lbl_0805ba8a
    .align 2, 0
lbl_0805b9b0: .4byte 0x02035a40
lbl_0805b9b4: .4byte 0x05000240
lbl_0805b9b8: .4byte 0x02035640
lbl_0805b9bc:
    ldr r1, lbl_0805ba9c @ =0x02035a40
    ldr r2, lbl_0805baa0 @ =0x02035240
    movs r3, #0xe0
    lsls r3, r3, #1
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    movs r0, #0x1f
    ands r0, r4
    str r0, [sp, #8]
    movs r0, #0xf8
    lsls r0, r0, #2
    ands r0, r4
    lsrs r0, r0, #5
    mov r8, r0
    movs r0, #0xf8
    lsls r0, r0, #7
    ands r0, r4
    lsrs r0, r0, #0xa
    mov ip, r0
    movs r2, #0
lbl_0805b9ea:
    ldr r1, [sp, #4]
    asrs r1, r2
    movs r0, #1
    ands r1, r0
    adds r7, r2, #1
    str r7, [sp, #0xc]
    cmp r1, #0
    beq lbl_0805ba78
    lsls r0, r2, #4
    adds r3, r0, #1
    adds r1, r0, #0
    adds r1, #0x10
    cmp r3, r1
    bge lbl_0805ba78
    movs r0, #0xf8
    lsls r0, r0, #2
    mov sl, r0
    movs r2, #0xf8
    lsls r2, r2, #7
    mov sb, r2
    lsls r0, r3, #1
    ldr r7, lbl_0805baa4 @ =0x02035200
    adds r5, r0, r7
    subs r3, r1, r3
lbl_0805ba1a:
    ldrh r1, [r5]
    movs r4, #0x1f
    ands r4, r1
    mov r0, sl
    ands r0, r1
    lsrs r2, r0, #5
    mov r0, sb
    ands r0, r1
    lsrs r1, r0, #0xa
    ldr r7, [sp, #8]
    subs r0, r7, r4
    muls r0, r6, r0
    cmp r0, #0
    bge lbl_0805ba38
    adds r0, #0xf
lbl_0805ba38:
    asrs r0, r0, #4
    adds r0, r4, r0
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    mov r7, r8
    subs r0, r7, r2
    muls r0, r6, r0
    cmp r0, #0
    bge lbl_0805ba4c
    adds r0, #0xf
lbl_0805ba4c:
    asrs r0, r0, #4
    adds r0, r2, r0
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    mov r7, ip
    subs r0, r7, r1
    muls r0, r6, r0
    cmp r0, #0
    bge lbl_0805ba60
    adds r0, #0xf
lbl_0805ba60:
    asrs r0, r0, #4
    adds r0, r1, r0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0xe
    lsls r1, r2, #5
    orrs r0, r1
    orrs r0, r4
    strh r0, [r5]
    adds r5, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_0805ba1a
lbl_0805ba78:
    ldr r2, [sp, #0xc]
    cmp r2, #0xf
    ble lbl_0805b9ea
    ldr r0, lbl_0805baa8 @ =gColorFading
    ldrb r1, [r0, #4]
    movs r0, #2
    orrs r0, r1
    ldr r1, lbl_0805baa8 @ =gColorFading
    strb r0, [r1, #4]
lbl_0805ba8a:
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805ba9c: .4byte 0x02035a40
lbl_0805baa0: .4byte 0x02035240
lbl_0805baa4: .4byte 0x02035200
lbl_0805baa8: .4byte gColorFading

    thumb_func_start ApplySpecialBackgroundFadingColor
ApplySpecialBackgroundFadingColor: @ 0x0805baac
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    mov sb, r2
    mov r8, r3
    ldr r2, [sp, #0x28]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov ip, r0
    lsls r1, r1, #0x18
    lsrs r7, r1, #0x18
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    str r2, [sp]
    movs r2, #0
lbl_0805bad0:
    ldr r0, [sp]
    asrs r0, r2
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0805baf2
    mov r1, sb
    ldr r0, [r1]
    adds r0, #0x20
    str r0, [r1]
    mov r1, r8
    ldr r0, [r1]
    adds r0, #0x20
    str r0, [r1]
    adds r2, #1
    str r2, [sp, #4]
    b lbl_0805bbcc
lbl_0805baf2:
    adds r2, #1
    str r2, [sp, #4]
    movs r6, #0x1f
    movs r0, #0xf
    mov sl, r0
lbl_0805bafc:
    mov r1, sb
    ldr r2, [r1]
    ldrh r1, [r2]
    adds r3, r6, #0
    ands r3, r1
    movs r0, #0xf8
    lsls r0, r0, #2
    ands r0, r1
    lsrs r5, r0, #5
    movs r0, #0xf8
    lsls r0, r0, #7
    ands r0, r1
    lsrs r4, r0, #0xa
    mov r0, ip
    cmp r0, #1
    beq lbl_0805bb4a
    cmp r0, #1
    bgt lbl_0805bb26
    cmp r0, #0
    beq lbl_0805bb32
    b lbl_0805bba4
lbl_0805bb26:
    mov r1, ip
    cmp r1, #2
    beq lbl_0805bb68
    cmp r1, #3
    beq lbl_0805bb86
    b lbl_0805bba4
lbl_0805bb32:
    adds r0, r3, #0
    muls r0, r7, r0
    asrs r3, r0, #5
    ands r3, r6
    adds r0, r5, #0
    muls r0, r7, r0
    asrs r5, r0, #5
    ands r5, r6
    adds r0, r4, #0
    muls r0, r7, r0
    asrs r4, r0, #5
    b lbl_0805bba2
lbl_0805bb4a:
    subs r0, r6, r3
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r3, r6, r0
    ands r3, r6
    subs r0, r6, r5
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r5, r6, r0
    ands r5, r6
    subs r0, r6, r4
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r4, r6, r0
    b lbl_0805bba2
lbl_0805bb68:
    adds r0, r3, #0
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r3, r3, r0
    ands r3, r6
    adds r0, r5, #0
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r5, r5, r0
    ands r5, r6
    adds r0, r4, #0
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r4, r4, r0
    b lbl_0805bba2
lbl_0805bb86:
    subs r0, r6, r3
    muls r0, r7, r0
    asrs r0, r0, #5
    adds r3, r3, r0
    ands r3, r6
    subs r0, r6, r5
    muls r0, r7, r0
    asrs r0, r0, #5
    adds r5, r5, r0
    ands r5, r6
    subs r0, r6, r4
    muls r0, r7, r0
    asrs r0, r0, #5
    adds r4, r4, r0
lbl_0805bba2:
    ands r4, r6
lbl_0805bba4:
    mov r0, r8
    ldr r1, [r0]
    lsls r0, r5, #5
    orrs r3, r0
    lsls r0, r4, #0xa
    orrs r3, r0
    strh r3, [r1]
    movs r1, #1
    rsbs r1, r1, #0
    add sl, r1
    adds r0, r2, #2
    mov r1, sb
    str r0, [r1]
    mov r1, r8
    ldr r0, [r1]
    adds r0, #2
    str r0, [r1]
    mov r0, sl
    cmp r0, #0
    bge lbl_0805bafc
lbl_0805bbcc:
    ldr r2, [sp, #4]
    cmp r2, #0xf
    bgt lbl_0805bbd4
    b lbl_0805bad0
lbl_0805bbd4:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_0805bbe4
sub_0805bbe4: @ 0x0805bbe4
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    mov ip, r6
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    lsls r2, r2, #0x18
    lsrs r5, r2, #0x18
    movs r7, #0x1f
    adds r3, r1, #0
    ands r3, r7
    movs r0, #0xf8
    lsls r0, r0, #2
    ands r0, r1
    lsrs r4, r0, #5
    movs r0, #0xf8
    lsls r0, r0, #7
    ands r0, r1
    lsrs r2, r0, #0xa
    cmp r6, #1
    beq lbl_0805bc3e
    cmp r6, #1
    bgt lbl_0805bc18
    cmp r6, #0
    beq lbl_0805bc24
    b lbl_0805bc9e
lbl_0805bc18:
    mov r0, ip
    cmp r0, #2
    beq lbl_0805bc5e
    cmp r0, #3
    beq lbl_0805bc7e
    b lbl_0805bc9e
lbl_0805bc24:
    adds r0, r3, #0
    muls r0, r5, r0
    asrs r3, r0, #5
    movs r1, #0x1f
    ands r3, r1
    adds r0, r4, #0
    muls r0, r5, r0
    asrs r4, r0, #5
    ands r4, r1
    adds r0, r2, #0
    muls r0, r5, r0
    asrs r2, r0, #5
    b lbl_0805bc9c
lbl_0805bc3e:
    subs r0, r7, r3
    muls r0, r5, r0
    asrs r0, r0, #5
    movs r1, #0x1f
    subs r3, r1, r0
    ands r3, r1
    subs r0, r7, r4
    muls r0, r5, r0
    asrs r0, r0, #5
    subs r4, r1, r0
    ands r4, r1
    subs r0, r7, r2
    muls r0, r5, r0
    asrs r0, r0, #5
    subs r2, r1, r0
    b lbl_0805bc9c
lbl_0805bc5e:
    adds r0, r3, #0
    muls r0, r5, r0
    asrs r0, r0, #5
    subs r3, r3, r0
    movs r1, #0x1f
    ands r3, r1
    adds r0, r4, #0
    muls r0, r5, r0
    asrs r0, r0, #5
    subs r4, r4, r0
    ands r4, r1
    adds r0, r2, #0
    muls r0, r5, r0
    asrs r0, r0, #5
    subs r2, r2, r0
    b lbl_0805bc9c
lbl_0805bc7e:
    subs r0, r7, r3
    muls r0, r5, r0
    asrs r0, r0, #5
    adds r3, r3, r0
    movs r1, #0x1f
    ands r3, r1
    subs r0, r7, r4
    muls r0, r5, r0
    asrs r0, r0, #5
    adds r4, r4, r0
    ands r4, r1
    subs r0, r7, r2
    muls r0, r5, r0
    asrs r0, r0, #5
    adds r2, r2, r0
lbl_0805bc9c:
    ands r2, r1
lbl_0805bc9e:
    lsls r0, r4, #5
    orrs r3, r0
    lsls r0, r2, #0xa
    orrs r3, r0
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
