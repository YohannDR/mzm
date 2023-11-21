    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start get_chararcter_width
get_chararcter_width: @ 0x0806e460
    push {lr}
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldr r0, lbl_0806e474 @ =0x0000049f
    cmp r1, r0
    bhi lbl_0806e47c
    ldr r0, lbl_0806e478 @ =0x0840d7b0
    adds r0, r1, r0
    ldrb r0, [r0]
    b lbl_0806e47e
    .align 2, 0
lbl_0806e474: .4byte 0x0000049f
lbl_0806e478: .4byte 0x0840d7b0
lbl_0806e47c:
    movs r0, #0xa
lbl_0806e47e:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start draw_character_for_text
draw_character_for_text: @ 0x0806e484
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x2c
    str r1, [sp, #8]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #4]
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    str r2, [sp, #0xc]
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    str r3, [sp, #0x10]
    ldr r2, lbl_0806e550 @ =0x02027700
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x80
    bl BitFill
    ldr r0, [sp, #4]
    bl get_chararcter_width
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0x18]
    movs r0, #0
    mov sl, r0
lbl_0806e4c4:
    ldr r5, lbl_0806e550 @ =0x02027700
    mov r1, sl
    cmp r1, #0
    beq lbl_0806e4ce
    adds r5, #0x40
lbl_0806e4ce:
    ldr r2, [sp, #4]
    lsls r0, r2, #5
    mov r3, sl
    lsls r1, r3, #0xa
    adds r4, r0, r1
    ldr r0, lbl_0806e554 @ =0x08415460
    adds r6, r4, r0
    movs r0, #8
    str r0, [sp, #0x14]
    str r1, [sp, #0x24]
    ldr r1, [sp, #0x18]
    cmp r1, #8
    bls lbl_0806e4ec
    movs r2, #0x10
    str r2, [sp, #0x14]
lbl_0806e4ec:
    ldr r3, [sp, #0x10]
    cmp r3, #0
    bne lbl_0806e4f4
    b lbl_0806e614
lbl_0806e4f4:
    ldr r0, [sp, #0xc]
    lsrs r0, r0, #8
    mov ip, r0
    mov r1, sl
    adds r1, #1
    str r1, [sp, #0x28]
    ldr r2, [sp, #0x14]
    cmp r2, #0
    bgt lbl_0806e508
    b lbl_0806e632
lbl_0806e508:
    ldr r3, lbl_0806e558 @ =0x08760338
    mov r8, r3
    ldr r7, lbl_0806e55c @ =0x08760398
    mov sb, r2
lbl_0806e510:
    ldr r4, [r6]
    cmp r4, #0
    beq lbl_0806e600
    movs r1, #0
    movs r3, #4
    ldr r0, [sp, #0x10]
    cmp r0, #0
    beq lbl_0806e522
    adds r3, r0, #0
lbl_0806e522:
    mov r0, r8
    ldr r2, [r0]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e538
    ldr r0, [r7]
    ands r0, r2
    adds r1, r2, #0
    cmp r0, #0
    beq lbl_0806e538
    adds r1, r3, #0
lbl_0806e538:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #4]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e562
    ldr r0, [r7, #4]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e560
    orrs r1, r3
    b lbl_0806e562
    .align 2, 0
lbl_0806e550: .4byte 0x02027700
lbl_0806e554: .4byte 0x08415460
lbl_0806e558: .4byte 0x08760338
lbl_0806e55c: .4byte 0x08760398
lbl_0806e560:
    orrs r1, r2
lbl_0806e562:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #8]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e57c
    ldr r0, [r7, #8]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e57a
    orrs r1, r3
    b lbl_0806e57c
lbl_0806e57a:
    orrs r1, r2
lbl_0806e57c:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #0xc]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e596
    ldr r0, [r7, #0xc]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e594
    orrs r1, r3
    b lbl_0806e596
lbl_0806e594:
    orrs r1, r2
lbl_0806e596:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #0x10]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e5b0
    ldr r0, [r7, #0x10]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e5ae
    orrs r1, r3
    b lbl_0806e5b0
lbl_0806e5ae:
    orrs r1, r2
lbl_0806e5b0:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #0x14]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e5ca
    ldr r0, [r7, #0x14]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e5c8
    orrs r1, r3
    b lbl_0806e5ca
lbl_0806e5c8:
    orrs r1, r2
lbl_0806e5ca:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #0x18]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e5e4
    ldr r0, [r7, #0x18]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e5e2
    orrs r1, r3
    b lbl_0806e5e4
lbl_0806e5e2:
    orrs r1, r2
lbl_0806e5e4:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #0x1c]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e5fe
    ldr r0, [r7, #0x1c]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e5fc
    orrs r1, r3
    b lbl_0806e5fe
lbl_0806e5fc:
    orrs r1, r2
lbl_0806e5fe:
    str r1, [r5]
lbl_0806e600:
    movs r1, #1
    rsbs r1, r1, #0
    add sb, r1
    adds r5, #4
    adds r6, #4
    mov r2, sb
    cmp r2, #0
    beq lbl_0806e612
    b lbl_0806e510
lbl_0806e612:
    b lbl_0806e632
lbl_0806e614:
    ldr r0, [sp, #0x14]
    lsls r3, r0, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r2, r5, #0
    bl DmaTransfer
    ldr r1, [sp, #0xc]
    lsrs r1, r1, #8
    mov ip, r1
    mov r2, sl
    adds r2, #1
    str r2, [sp, #0x28]
lbl_0806e632:
    movs r0, #0xff
    ldr r3, [sp, #0xc]
    ands r0, r3
    lsrs r0, r0, #3
    lsls r0, r0, #5
    ldr r1, [sp, #8]
    adds r0, r1, r0
    ldr r2, [sp, #0x24]
    adds r5, r0, r2
    mov r3, ip
    lsls r0, r3, #0xb
    adds r5, r5, r0
    ldr r6, lbl_0806e7f8 @ =0x02027700
    mov r0, sl
    cmp r0, #0
    beq lbl_0806e654
    adds r6, #0x40
lbl_0806e654:
    movs r3, #7
    ldr r1, [sp, #0xc]
    ands r3, r1
    cmp r3, #0
    bne lbl_0806e660
    b lbl_0806e89a
lbl_0806e660:
    lsls r4, r3, #2
    movs r0, #0x20
    subs r0, r0, r4
    str r0, [sp, #0x14]
    ldr r2, [sp, #0x18]
    adds r3, r3, r2
    str r3, [sp, #0x1c]
    cmp r3, #8
    bgt lbl_0806e674
    b lbl_0806e848
lbl_0806e674:
    ldr r2, [r6]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5]
    orrs r0, r1
    str r0, [r5]
    ldr r3, [sp, #0x14]
    lsrs r2, r3
    ldr r3, [r5, #0x20]
    orrs r3, r2
    str r3, [r5, #0x20]
    ldr r2, [r6, #4]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #4]
    orrs r0, r1
    str r0, [r5, #4]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r7, [r5, #0x24]
    orrs r7, r2
    str r7, [r5, #0x24]
    ldr r2, [r6, #8]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #8]
    orrs r0, r1
    str r0, [r5, #8]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r5, #0x28]
    mov ip, r0
    mov r1, ip
    orrs r1, r2
    mov ip, r1
    str r1, [r5, #0x28]
    ldr r2, [r6, #0xc]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #0xc]
    orrs r0, r1
    str r0, [r5, #0xc]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r1, [r5, #0x2c]
    mov r8, r1
    mov r0, r8
    orrs r0, r2
    mov r8, r0
    str r0, [r5, #0x2c]
    ldr r2, [r6, #0x10]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #0x10]
    orrs r0, r1
    str r0, [r5, #0x10]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r5, #0x30]
    mov sb, r0
    mov r1, sb
    orrs r1, r2
    mov sb, r1
    str r1, [r5, #0x30]
    ldr r2, [r6, #0x14]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #0x14]
    orrs r0, r1
    str r0, [r5, #0x14]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r1, [r5, #0x34]
    mov sl, r1
    mov r0, sl
    orrs r0, r2
    mov sl, r0
    str r0, [r5, #0x34]
    ldr r2, [r6, #0x18]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #0x18]
    orrs r0, r1
    str r0, [r5, #0x18]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r5, #0x38]
    orrs r0, r2
    str r0, [sp, #0x20]
    str r0, [r5, #0x38]
    ldr r2, [r6, #0x1c]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #0x1c]
    orrs r0, r1
    str r0, [r5, #0x1c]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r1, [r5, #0x3c]
    orrs r1, r2
    str r1, [r5, #0x3c]
    ldr r2, [sp, #0x18]
    cmp r2, #8
    bhi lbl_0806e746
    b lbl_0806e920
lbl_0806e746:
    ldr r0, [sp, #0x1c]
    cmp r0, #0x10
    ble lbl_0806e7fc
    ldr r2, [r6, #0x20]
    adds r0, r2, #0
    lsls r0, r4
    orrs r3, r0
    str r3, [r5, #0x20]
    ldr r3, [sp, #0x14]
    lsrs r2, r3
    ldr r0, [r5, #0x40]
    orrs r0, r2
    str r0, [r5, #0x40]
    ldr r2, [r6, #0x24]
    adds r0, r2, #0
    lsls r0, r4
    orrs r7, r0
    str r7, [r5, #0x24]
    lsrs r2, r3
    ldr r0, [r5, #0x44]
    orrs r0, r2
    str r0, [r5, #0x44]
    ldr r2, [r6, #0x28]
    adds r0, r2, #0
    lsls r0, r4
    mov r3, ip
    orrs r3, r0
    str r3, [r5, #0x28]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r5, #0x48]
    orrs r0, r2
    str r0, [r5, #0x48]
    ldr r2, [r6, #0x2c]
    adds r0, r2, #0
    lsls r0, r4
    mov r3, r8
    orrs r3, r0
    str r3, [r5, #0x2c]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r5, #0x4c]
    orrs r0, r2
    str r0, [r5, #0x4c]
    ldr r2, [r6, #0x30]
    adds r0, r2, #0
    lsls r0, r4
    mov r3, sb
    orrs r3, r0
    str r3, [r5, #0x30]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r5, #0x50]
    orrs r0, r2
    str r0, [r5, #0x50]
    ldr r2, [r6, #0x34]
    adds r0, r2, #0
    lsls r0, r4
    mov r3, sl
    orrs r3, r0
    str r3, [r5, #0x34]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r5, #0x54]
    orrs r0, r2
    str r0, [r5, #0x54]
    ldr r2, [r6, #0x38]
    adds r0, r2, #0
    lsls r0, r4
    ldr r3, [sp, #0x20]
    orrs r3, r0
    str r3, [r5, #0x38]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r5, #0x58]
    orrs r0, r2
    str r0, [r5, #0x58]
    ldr r2, [r6, #0x3c]
    adds r0, r2, #0
    lsls r0, r4
    orrs r1, r0
    str r1, [r5, #0x3c]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r5, #0x5c]
    orrs r0, r2
    str r0, [r5, #0x5c]
    b lbl_0806e920
    .align 2, 0
lbl_0806e7f8: .4byte 0x02027700
lbl_0806e7fc:
    ldr r0, [r6, #0x20]
    lsls r0, r4
    orrs r3, r0
    str r3, [r5, #0x20]
    ldr r0, [r6, #0x24]
    lsls r0, r4
    orrs r7, r0
    str r7, [r5, #0x24]
    ldr r0, [r6, #0x28]
    lsls r0, r4
    mov r2, ip
    orrs r2, r0
    str r2, [r5, #0x28]
    ldr r0, [r6, #0x2c]
    lsls r0, r4
    mov r3, r8
    orrs r3, r0
    str r3, [r5, #0x2c]
    ldr r0, [r6, #0x30]
    lsls r0, r4
    mov r2, sb
    orrs r2, r0
    str r2, [r5, #0x30]
    ldr r0, [r6, #0x34]
    lsls r0, r4
    mov r3, sl
    orrs r3, r0
    str r3, [r5, #0x34]
    ldr r0, [r6, #0x38]
    lsls r0, r4
    ldr r2, [sp, #0x20]
    orrs r2, r0
    str r2, [r5, #0x38]
    ldr r0, [r6, #0x3c]
    lsls r0, r4
    orrs r1, r0
    str r1, [r5, #0x3c]
    b lbl_0806e920
lbl_0806e848:
    ldr r1, [r6]
    lsls r1, r4
    ldr r0, [r5]
    orrs r0, r1
    str r0, [r5]
    ldr r1, [r6, #4]
    lsls r1, r4
    ldr r0, [r5, #4]
    orrs r0, r1
    str r0, [r5, #4]
    ldr r1, [r6, #8]
    lsls r1, r4
    ldr r0, [r5, #8]
    orrs r0, r1
    str r0, [r5, #8]
    ldr r1, [r6, #0xc]
    lsls r1, r4
    ldr r0, [r5, #0xc]
    orrs r0, r1
    str r0, [r5, #0xc]
    ldr r1, [r6, #0x10]
    lsls r1, r4
    ldr r0, [r5, #0x10]
    orrs r0, r1
    str r0, [r5, #0x10]
    ldr r1, [r6, #0x14]
    lsls r1, r4
    ldr r0, [r5, #0x14]
    orrs r0, r1
    str r0, [r5, #0x14]
    ldr r1, [r6, #0x18]
    lsls r1, r4
    ldr r0, [r5, #0x18]
    orrs r0, r1
    str r0, [r5, #0x18]
    ldr r1, [r6, #0x1c]
    lsls r1, r4
    ldr r0, [r5, #0x1c]
    orrs r0, r1
    str r0, [r5, #0x1c]
    b lbl_0806e920
lbl_0806e89a:
    ldr r0, [r5]
    ldr r1, [r6]
    orrs r0, r1
    str r0, [r5]
    ldr r0, [r5, #4]
    ldr r1, [r6, #4]
    orrs r0, r1
    str r0, [r5, #4]
    ldr r0, [r5, #8]
    ldr r1, [r6, #8]
    orrs r0, r1
    str r0, [r5, #8]
    ldr r0, [r5, #0xc]
    ldr r1, [r6, #0xc]
    orrs r0, r1
    str r0, [r5, #0xc]
    ldr r0, [r5, #0x10]
    ldr r1, [r6, #0x10]
    orrs r0, r1
    str r0, [r5, #0x10]
    ldr r0, [r5, #0x14]
    ldr r1, [r6, #0x14]
    orrs r0, r1
    str r0, [r5, #0x14]
    ldr r0, [r5, #0x18]
    ldr r1, [r6, #0x18]
    orrs r0, r1
    str r0, [r5, #0x18]
    ldr r0, [r5, #0x1c]
    ldr r1, [r6, #0x1c]
    orrs r0, r1
    str r0, [r5, #0x1c]
    ldr r3, [sp, #0x18]
    cmp r3, #8
    bls lbl_0806e920
    ldr r0, [r5, #0x20]
    ldr r1, [r6, #0x20]
    orrs r0, r1
    str r0, [r5, #0x20]
    ldr r0, [r5, #0x24]
    ldr r1, [r6, #0x24]
    orrs r0, r1
    str r0, [r5, #0x24]
    ldr r0, [r5, #0x28]
    ldr r1, [r6, #0x28]
    orrs r0, r1
    str r0, [r5, #0x28]
    ldr r0, [r5, #0x2c]
    ldr r1, [r6, #0x2c]
    orrs r0, r1
    str r0, [r5, #0x2c]
    ldr r0, [r5, #0x30]
    ldr r1, [r6, #0x30]
    orrs r0, r1
    str r0, [r5, #0x30]
    ldr r0, [r5, #0x34]
    ldr r1, [r6, #0x34]
    orrs r0, r1
    str r0, [r5, #0x34]
    ldr r0, [r5, #0x38]
    ldr r1, [r6, #0x38]
    orrs r0, r1
    str r0, [r5, #0x38]
    ldr r0, [r5, #0x3c]
    ldr r1, [r6, #0x3c]
    orrs r0, r1
    str r0, [r5, #0x3c]
lbl_0806e920:
    ldr r0, [sp, #0x28]
    mov sl, r0
    cmp r0, #1
    bgt lbl_0806e92a
    b lbl_0806e4c4
lbl_0806e92a:
    add sp, #0x2c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start draw_character_for_message
draw_character_for_message: @ 0x0806e93c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x3c
    str r1, [sp, #8]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #4]
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    str r2, [sp, #0xc]
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    str r3, [sp, #0x10]
    ldr r2, lbl_0806e9e8 @ =0x02027700
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x80
    bl BitFill
    ldr r0, [sp, #4]
    bl get_chararcter_width
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0x18]
    movs r0, #0
    mov ip, r0
lbl_0806e97c:
    ldr r4, lbl_0806e9e8 @ =0x02027700
    mov r1, ip
    cmp r1, #0
    beq lbl_0806e986
    adds r4, #0x40
lbl_0806e986:
    ldr r2, [sp, #4]
    lsls r0, r2, #5
    mov r3, ip
    lsls r1, r3, #0xa
    adds r3, r0, r1
    ldr r0, lbl_0806e9ec @ =0x08415460
    adds r5, r3, r0
    movs r6, #8
    str r6, [sp, #0x14]
    str r1, [sp, #0x34]
    ldr r7, [sp, #0x18]
    cmp r7, #8
    bls lbl_0806e9a4
    movs r0, #0x10
    str r0, [sp, #0x14]
lbl_0806e9a4:
    ldr r1, [sp, #0xc]
    lsrs r1, r1, #8
    str r1, [sp, #0x30]
    mov r2, ip
    adds r2, #1
    str r2, [sp, #0x38]
    ldr r3, [sp, #0x14]
    cmp r3, #0
    bgt lbl_0806e9b8
    b lbl_0806eb28
lbl_0806e9b8:
    ldr r6, lbl_0806e9f0 @ =0x08760338
    mov sb, r6
    ldr r7, lbl_0806e9f4 @ =0x08760398
    mov r8, r7
    mov sl, r3
lbl_0806e9c2:
    ldr r6, [r5]
    movs r1, #4
    ldr r0, [sp, #0x10]
    cmp r0, #0
    beq lbl_0806e9ce
    adds r1, r0, #0
lbl_0806e9ce:
    mov r3, sb
    ldr r2, [r3]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806e9f8
    mov r7, r8
    ldr r0, [r7]
    ands r0, r2
    adds r3, r2, #0
    cmp r0, #0
    beq lbl_0806e9fc
    adds r3, r1, #0
    b lbl_0806e9fc
    .align 2, 0
lbl_0806e9e8: .4byte 0x02027700
lbl_0806e9ec: .4byte 0x08415460
lbl_0806e9f0: .4byte 0x08760338
lbl_0806e9f4: .4byte 0x08760398
lbl_0806e9f8:
    ldr r0, lbl_0806ea18 @ =0x087603b8
    ldr r3, [r0]
lbl_0806e9fc:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #4]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806ea20
    mov r7, r8
    ldr r0, [r7, #4]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806ea1c
    orrs r3, r1
    b lbl_0806ea26
    .align 2, 0
lbl_0806ea18: .4byte 0x087603b8
lbl_0806ea1c:
    orrs r3, r2
    b lbl_0806ea26
lbl_0806ea20:
    ldr r2, lbl_0806ea40 @ =0x087603b8
    ldr r0, [r2, #4]
    orrs r3, r0
lbl_0806ea26:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #8]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806ea48
    mov r7, r8
    ldr r0, [r7, #8]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806ea44
    orrs r3, r1
    b lbl_0806ea4e
    .align 2, 0
lbl_0806ea40: .4byte 0x087603b8
lbl_0806ea44:
    orrs r3, r2
    b lbl_0806ea4e
lbl_0806ea48:
    ldr r2, lbl_0806ea68 @ =0x087603b8
    ldr r0, [r2, #8]
    orrs r3, r0
lbl_0806ea4e:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #0xc]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806ea70
    mov r7, r8
    ldr r0, [r7, #0xc]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806ea6c
    orrs r3, r1
    b lbl_0806ea76
    .align 2, 0
lbl_0806ea68: .4byte 0x087603b8
lbl_0806ea6c:
    orrs r3, r2
    b lbl_0806ea76
lbl_0806ea70:
    ldr r2, lbl_0806ea90 @ =0x087603b8
    ldr r0, [r2, #0xc]
    orrs r3, r0
lbl_0806ea76:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #0x10]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806ea98
    mov r7, r8
    ldr r0, [r7, #0x10]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806ea94
    orrs r3, r1
    b lbl_0806ea9e
    .align 2, 0
lbl_0806ea90: .4byte 0x087603b8
lbl_0806ea94:
    orrs r3, r2
    b lbl_0806ea9e
lbl_0806ea98:
    ldr r2, lbl_0806eab8 @ =0x087603b8
    ldr r0, [r2, #0x10]
    orrs r3, r0
lbl_0806ea9e:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #0x14]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806eac0
    mov r7, r8
    ldr r0, [r7, #0x14]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806eabc
    orrs r3, r1
    b lbl_0806eac6
    .align 2, 0
lbl_0806eab8: .4byte 0x087603b8
lbl_0806eabc:
    orrs r3, r2
    b lbl_0806eac6
lbl_0806eac0:
    ldr r2, lbl_0806eae0 @ =0x087603b8
    ldr r0, [r2, #0x14]
    orrs r3, r0
lbl_0806eac6:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #0x18]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806eae8
    mov r7, r8
    ldr r0, [r7, #0x18]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806eae4
    orrs r3, r1
    b lbl_0806eaee
    .align 2, 0
lbl_0806eae0: .4byte 0x087603b8
lbl_0806eae4:
    orrs r3, r2
    b lbl_0806eaee
lbl_0806eae8:
    ldr r2, lbl_0806eb08 @ =0x087603b8
    ldr r0, [r2, #0x18]
    orrs r3, r0
lbl_0806eaee:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #0x1c]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806eb10
    mov r6, r8
    ldr r0, [r6, #0x1c]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806eb0c
    orrs r3, r1
    b lbl_0806eb16
    .align 2, 0
lbl_0806eb08: .4byte 0x087603b8
lbl_0806eb0c:
    orrs r3, r2
    b lbl_0806eb16
lbl_0806eb10:
    ldr r7, lbl_0806ed90 @ =0x087603b8
    ldr r0, [r7, #0x1c]
    orrs r3, r0
lbl_0806eb16:
    stm r4!, {r3}
    movs r0, #1
    rsbs r0, r0, #0
    add sl, r0
    adds r5, #4
    mov r1, sl
    cmp r1, #0
    beq lbl_0806eb28
    b lbl_0806e9c2
lbl_0806eb28:
    movs r0, #0xff
    ldr r2, [sp, #0xc]
    ands r0, r2
    lsrs r0, r0, #3
    lsls r0, r0, #5
    ldr r3, [sp, #8]
    adds r0, r3, r0
    ldr r6, [sp, #0x34]
    adds r4, r0, r6
    ldr r7, [sp, #0x30]
    lsls r0, r7, #0xb
    adds r4, r4, r0
    ldr r5, lbl_0806ed94 @ =0x02027700
    mov r0, ip
    cmp r0, #0
    beq lbl_0806eb4a
    adds r5, #0x40
lbl_0806eb4a:
    movs r1, #7
    ldr r2, [sp, #0xc]
    ands r1, r2
    cmp r1, #0
    bne lbl_0806eb56
    b lbl_0806ee8c
lbl_0806eb56:
    lsls r3, r1, #2
    movs r0, #8
    subs r0, r0, r1
    mov sl, r0
    movs r0, #0x20
    subs r0, r0, r3
    str r0, [sp, #0x14]
    ldr r6, [sp, #0x18]
    adds r1, r1, r6
    str r1, [sp, #0x1c]
    cmp r1, #8
    bgt lbl_0806eb70
    b lbl_0806ee12
lbl_0806eb70:
    ldr r2, [r5]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, lbl_0806ed98 @ =0x087602f0
    adds r6, r3, r0
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4]
    ands r0, r1
    str r0, [r4]
    ldr r7, [sp, #0x14]
    lsrs r2, r7
    ldr r1, lbl_0806ed9c @ =0x08760314
    mov r7, sl
    lsls r0, r7, #2
    adds r7, r0, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x20]
    mov ip, r0
    mov r1, ip
    ands r1, r2
    mov ip, r1
    str r1, [r4, #0x20]
    ldr r2, [r5, #4]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #4]
    ands r0, r1
    str r0, [r4, #4]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r1, [r4, #0x24]
    mov r8, r1
    mov r0, r8
    ands r0, r2
    mov r8, r0
    str r0, [r4, #0x24]
    ldr r2, [r5, #8]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #8]
    ands r0, r1
    str r0, [r4, #8]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x28]
    mov sb, r0
    mov r1, sb
    ands r1, r2
    mov sb, r1
    str r1, [r4, #0x28]
    ldr r2, [r5, #0xc]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #0xc]
    ands r0, r1
    str r0, [r4, #0xc]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r1, [r4, #0x2c]
    mov sl, r1
    mov r0, sl
    ands r0, r2
    mov sl, r0
    str r0, [r4, #0x2c]
    ldr r2, [r5, #0x10]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #0x10]
    ands r0, r1
    str r0, [r4, #0x10]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x30]
    ands r0, r2
    str r0, [sp, #0x20]
    str r0, [r4, #0x30]
    ldr r2, [r5, #0x14]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #0x14]
    ands r0, r1
    str r0, [r4, #0x14]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x34]
    ands r0, r2
    str r0, [sp, #0x24]
    str r0, [r4, #0x34]
    ldr r2, [r5, #0x18]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #0x18]
    ands r0, r1
    str r0, [r4, #0x18]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x38]
    ands r0, r2
    str r0, [sp, #0x28]
    str r0, [r4, #0x38]
    ldr r2, [r5, #0x1c]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #0x1c]
    ands r0, r1
    str r0, [r4, #0x1c]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x3c]
    ands r0, r2
    str r0, [sp, #0x2c]
    str r0, [r4, #0x3c]
    ldr r1, [sp, #0x18]
    cmp r1, #8
    bhi lbl_0806ec94
    b lbl_0806ef12
lbl_0806ec94:
    ldr r2, [sp, #0x1c]
    cmp r2, #0x10
    bgt lbl_0806ec9c
    b lbl_0806eda0
lbl_0806ec9c:
    ldr r2, [r5, #0x20]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r1, ip
    ands r1, r0
    str r1, [r4, #0x20]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x40]
    ands r0, r2
    str r0, [r4, #0x40]
    ldr r2, [r5, #0x24]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r1, r8
    ands r1, r0
    str r1, [r4, #0x24]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x44]
    ands r0, r2
    str r0, [r4, #0x44]
    ldr r2, [r5, #0x28]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r1, sb
    ands r1, r0
    str r1, [r4, #0x28]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x48]
    ands r0, r2
    str r0, [r4, #0x48]
    ldr r2, [r5, #0x2c]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r1, sl
    ands r1, r0
    str r1, [r4, #0x2c]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x4c]
    ands r0, r2
    str r0, [r4, #0x4c]
    ldr r2, [r5, #0x30]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x20]
    ands r1, r0
    str r1, [r4, #0x30]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x50]
    ands r0, r2
    str r0, [r4, #0x50]
    ldr r2, [r5, #0x34]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x24]
    ands r1, r0
    str r1, [r4, #0x34]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x54]
    ands r0, r2
    str r0, [r4, #0x54]
    ldr r2, [r5, #0x38]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x28]
    ands r1, r0
    str r1, [r4, #0x38]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x58]
    ands r0, r2
    str r0, [r4, #0x58]
    ldr r2, [r5, #0x3c]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x2c]
    ands r1, r0
    str r1, [r4, #0x3c]
    ldr r3, [sp, #0x14]
    lsrs r2, r3
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x5c]
    ands r0, r2
    str r0, [r4, #0x5c]
    b lbl_0806ef12
    .align 2, 0
lbl_0806ed90: .4byte 0x087603b8
lbl_0806ed94: .4byte 0x02027700
lbl_0806ed98: .4byte 0x087602f0
lbl_0806ed9c: .4byte 0x08760314
lbl_0806eda0:
    ldr r0, [r5, #0x20]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r7, ip
    ands r7, r0
    str r7, [r4, #0x20]
    ldr r0, [r5, #0x24]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r1, r8
    ands r1, r0
    str r1, [r4, #0x24]
    ldr r0, [r5, #0x28]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r2, sb
    ands r2, r0
    str r2, [r4, #0x28]
    ldr r0, [r5, #0x2c]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r7, sl
    ands r7, r0
    str r7, [r4, #0x2c]
    ldr r0, [r5, #0x30]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x20]
    ands r1, r0
    str r1, [r4, #0x30]
    ldr r0, [r5, #0x34]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r2, [sp, #0x24]
    ands r2, r0
    str r2, [r4, #0x34]
    ldr r0, [r5, #0x38]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r7, [sp, #0x28]
    ands r7, r0
    str r7, [r4, #0x38]
    ldr r0, [r5, #0x3c]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x2c]
    ands r1, r0
    str r1, [r4, #0x3c]
    b lbl_0806ef12
lbl_0806ee12:
    ldr r1, [r5]
    lsls r1, r3
    ldr r2, lbl_0806ee88 @ =0x087602f0
    adds r2, r3, r2
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4]
    ands r0, r1
    str r0, [r4]
    ldr r1, [r5, #4]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #4]
    ands r0, r1
    str r0, [r4, #4]
    ldr r1, [r5, #8]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #8]
    ands r0, r1
    str r0, [r4, #8]
    ldr r1, [r5, #0xc]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #0xc]
    ands r0, r1
    str r0, [r4, #0xc]
    ldr r1, [r5, #0x10]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #0x10]
    ands r0, r1
    str r0, [r4, #0x10]
    ldr r1, [r5, #0x14]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #0x14]
    ands r0, r1
    str r0, [r4, #0x14]
    ldr r1, [r5, #0x18]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #0x18]
    ands r0, r1
    str r0, [r4, #0x18]
    ldr r1, [r5, #0x1c]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #0x1c]
    ands r0, r1
    str r0, [r4, #0x1c]
    b lbl_0806ef12
    .align 2, 0
lbl_0806ee88: .4byte 0x087602f0
lbl_0806ee8c:
    ldr r0, [r4]
    ldr r1, [r5]
    ands r0, r1
    str r0, [r4]
    ldr r0, [r4, #4]
    ldr r1, [r5, #4]
    ands r0, r1
    str r0, [r4, #4]
    ldr r0, [r4, #8]
    ldr r1, [r5, #8]
    ands r0, r1
    str r0, [r4, #8]
    ldr r0, [r4, #0xc]
    ldr r1, [r5, #0xc]
    ands r0, r1
    str r0, [r4, #0xc]
    ldr r0, [r4, #0x10]
    ldr r1, [r5, #0x10]
    ands r0, r1
    str r0, [r4, #0x10]
    ldr r0, [r4, #0x14]
    ldr r1, [r5, #0x14]
    ands r0, r1
    str r0, [r4, #0x14]
    ldr r0, [r4, #0x18]
    ldr r1, [r5, #0x18]
    ands r0, r1
    str r0, [r4, #0x18]
    ldr r0, [r4, #0x1c]
    ldr r1, [r5, #0x1c]
    ands r0, r1
    str r0, [r4, #0x1c]
    ldr r2, [sp, #0x18]
    cmp r2, #8
    bls lbl_0806ef12
    ldr r0, [r4, #0x20]
    ldr r1, [r5, #0x20]
    ands r0, r1
    str r0, [r4, #0x20]
    ldr r0, [r4, #0x24]
    ldr r1, [r5, #0x24]
    ands r0, r1
    str r0, [r4, #0x24]
    ldr r0, [r4, #0x28]
    ldr r1, [r5, #0x28]
    ands r0, r1
    str r0, [r4, #0x28]
    ldr r0, [r4, #0x2c]
    ldr r1, [r5, #0x2c]
    ands r0, r1
    str r0, [r4, #0x2c]
    ldr r0, [r4, #0x30]
    ldr r1, [r5, #0x30]
    ands r0, r1
    str r0, [r4, #0x30]
    ldr r0, [r4, #0x34]
    ldr r1, [r5, #0x34]
    ands r0, r1
    str r0, [r4, #0x34]
    ldr r0, [r4, #0x38]
    ldr r1, [r5, #0x38]
    ands r0, r1
    str r0, [r4, #0x38]
    ldr r0, [r4, #0x3c]
    ldr r1, [r5, #0x3c]
    ands r0, r1
    str r0, [r4, #0x3c]
lbl_0806ef12:
    ldr r3, [sp, #0x38]
    mov ip, r3
    cmp r3, #1
    bgt lbl_0806ef1c
    b lbl_0806e97c
lbl_0806ef1c:
    add sp, #0x3c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start draw_location_text_characters
draw_location_text_characters: @ 0x0806ef2c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    adds r6, r1, #0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_0806ef48
    movs r0, #0x80
    lsls r0, r0, #0x12
    mov sl, r0
    b lbl_0806ef72
lbl_0806ef48:
    cmp r0, #2
    bne lbl_0806f00a
    ldr r1, lbl_0806efa8 @ =0x02000800
    mov sl, r1
    ldr r2, [r6]
    ldrh r0, [r2]
    movs r1, #0xfe
    lsls r1, r1, #8
    cmp r0, r1
    beq lbl_0806ef6c
    adds r3, r1, #0
lbl_0806ef5e:
    adds r0, r2, #0
    adds r1, r0, #2
    adds r2, r1, #0
    ldrh r0, [r0, #2]
    cmp r0, r3
    bne lbl_0806ef5e
    str r1, [r6]
lbl_0806ef6c:
    ldr r0, [r6]
    adds r0, #2
    str r0, [r6]
lbl_0806ef72:
    movs r7, #0
    movs r0, #0
    mov r8, r0
    ldr r3, [r6]
    movs r1, #0xff
    lsls r1, r1, #8
    mov ip, r1
    ldrh r1, [r3]
    cmp r1, ip
    beq lbl_0806f00a
    movs r0, #0xfe
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806f00a
    movs r0, #0xff
    mov sb, r0
lbl_0806ef92:
    movs r5, #1
    ldrh r2, [r3]
    mov r1, ip
    ands r1, r2
    movs r0, #0x80
    lsls r0, r0, #8
    cmp r1, r0
    bne lbl_0806efac
    mov r4, sb
    ands r4, r2
    b lbl_0806efec
    .align 2, 0
lbl_0806efa8: .4byte 0x02000800
lbl_0806efac:
    movs r0, #0x83
    lsls r0, r0, #8
    cmp r1, r0
    bne lbl_0806efbc
    movs r4, #0
    mov r7, sb
    ands r7, r2
    b lbl_0806efec
lbl_0806efbc:
    movs r0, #0x81
    lsls r0, r0, #8
    cmp r1, r0
    bne lbl_0806efd0
    movs r4, #0
    mov r8, sb
    mov r1, r8
    ands r1, r2
    mov r8, r1
    movs r5, #0
lbl_0806efd0:
    cmp r5, #0
    beq lbl_0806efec
    ldrh r0, [r3]
    bl get_chararcter_width
    adds r4, r0, #0
    ldr r0, [r6]
    ldrh r0, [r0]
    lsls r2, r7, #0x10
    lsrs r2, r2, #0x10
    mov r3, r8
    mov r1, sl
    bl draw_character_for_message
lbl_0806efec:
    ldr r0, [r6]
    adds r2, r0, #2
    str r2, [r6]
    adds r7, r7, r4
    movs r1, #0xff
    lsls r1, r1, #8
    mov ip, r1
    ldrh r1, [r0, #2]
    cmp r1, ip
    beq lbl_0806f00a
    adds r3, r2, #0
    movs r0, #0xfe
    lsls r0, r0, #8
    cmp r1, r0
    bne lbl_0806ef92
lbl_0806f00a:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start TextDrawLocationText
TextDrawLocationText: @ 0x0806f018
    push {r4, r5, r6, lr}
    sub sp, #8
    adds r4, r0, #0
    adds r5, r1, #0
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    lsls r5, r5, #0x18
    lsrs r5, r5, #0x18
    ldr r1, lbl_0806f088 @ =0x0000ffff
    movs r6, #0x80
    lsls r6, r6, #0x12
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r6, #0
    bl BitFill
    ldr r1, lbl_0806f08c @ =0x08760764
    ldr r0, lbl_0806f090 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    lsls r4, r4, #2
    adds r4, r4, r0
    ldr r0, [r4]
    str r0, [sp, #4]
    movs r0, #1
    add r1, sp, #4
    bl draw_location_text_characters
    ldr r0, lbl_0806f094 @ =0x040000d4
    str r6, [r0]
    lsls r5, r5, #0xb
    ldr r2, lbl_0806f098 @ =0x06014000
    adds r1, r5, r2
    str r1, [r0, #4]
    ldr r2, lbl_0806f09c @ =0x840000e0
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0806f0a0 @ =0x02000400
    str r1, [r0]
    ldr r1, lbl_0806f0a4 @ =0x06014400
    adds r5, r5, r1
    str r5, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    add sp, #8
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806f088: .4byte 0x0000ffff
lbl_0806f08c: .4byte 0x08760764
lbl_0806f090: .4byte gLanguage
lbl_0806f094: .4byte 0x040000d4
lbl_0806f098: .4byte 0x06014000
lbl_0806f09c: .4byte 0x840000e0
lbl_0806f0a0: .4byte 0x02000400
lbl_0806f0a4: .4byte 0x06014400

    thumb_func_start sub_0806f0a8
sub_0806f0a8: @ 0x0806f0a8
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    mov ip, r1
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    ldr r7, lbl_0806f0ec @ =gCurrentMessage
    cmp r2, #0xf
    bne lbl_0806f0da
    adds r0, r7, #0
    ldr r1, lbl_0806f0f0 @ =0x0840dc50
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
    adds r0, r3, #0
    cmp r3, #0x23
    bls lbl_0806f0d4
    movs r0, #0x23
lbl_0806f0d4:
    strb r0, [r7, #0xa]
    mov r0, ip
    strb r0, [r7, #0xb]
lbl_0806f0da:
    ldrb r0, [r7, #0xc]
    cmp r0, #4
    bls lbl_0806f0e2
    b lbl_0806f23e
lbl_0806f0e2:
    lsls r0, r0, #2
    ldr r1, lbl_0806f0f4 @ =lbl_0806f0f8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806f0ec: .4byte gCurrentMessage
lbl_0806f0f0: .4byte 0x0840dc50
lbl_0806f0f4: .4byte lbl_0806f0f8
lbl_0806f0f8: @ jump table
    .4byte lbl_0806f10c @ case 0
    .4byte lbl_0806f13c @ case 1
    .4byte lbl_0806f180 @ case 2
    .4byte lbl_0806f218 @ case 3
    .4byte lbl_0806f23e @ case 4
lbl_0806f10c:
    movs r6, #1
    rsbs r6, r6, #0
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r3, lbl_0806f134 @ =0x06014000
    adds r2, r2, r3
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r0, lbl_0806f138 @ =0x06014400
    b lbl_0806f160
    .align 2, 0
lbl_0806f134: .4byte 0x06014000
lbl_0806f138: .4byte 0x06014400
lbl_0806f13c:
    movs r6, #1
    rsbs r6, r6, #0
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r3, lbl_0806f178 @ =0x06014800
    adds r2, r2, r3
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r0, lbl_0806f17c @ =0x06014c00
lbl_0806f160:
    adds r2, r2, r0
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r0, [r7, #0xc]
    adds r0, #1
    strb r0, [r7, #0xc]
    b lbl_0806f24c
    .align 2, 0
lbl_0806f178: .4byte 0x06014800
lbl_0806f17c: .4byte 0x06014c00
lbl_0806f180:
    movs r5, #8
    ldrb r0, [r7, #7]
    cmp r0, #1
    bhi lbl_0806f18e
    ldrb r0, [r7, #0xe]
    cmp r0, #0
    beq lbl_0806f196
lbl_0806f18e:
    ldrb r0, [r7, #0xc]
    adds r0, #1
    strb r0, [r7, #0xc]
    movs r5, #0
lbl_0806f196:
    cmp r2, #1
    bne lbl_0806f1a2
    ldrb r0, [r7, #0xc]
    adds r0, #1
    strb r0, [r7, #0xc]
    movs r5, #0
lbl_0806f1a2:
    cmp r5, #0
    beq lbl_0806f24c
    ldr r4, lbl_0806f1e8 @ =gCurrentMessage
    ldr r6, lbl_0806f1ec @ =0x08760780
lbl_0806f1aa:
    ldr r0, lbl_0806f1f0 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r1, [r4, #0xa]
    ldr r0, [r0]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r1, [r1]
    ldrb r2, [r4, #0xb]
    lsls r2, r2, #0xb
    ldrb r0, [r4, #7]
    lsls r0, r0, #0xb
    ldr r3, lbl_0806f1f4 @ =0x06014000
    adds r0, r0, r3
    adds r2, r2, r0
    adds r0, r4, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0806f1fe
    cmp r0, #2
    bgt lbl_0806f1f8
    cmp r0, #1
    beq lbl_0806f204
    b lbl_0806f20a
    .align 2, 0
lbl_0806f1e8: .4byte gCurrentMessage
lbl_0806f1ec: .4byte 0x08760780
lbl_0806f1f0: .4byte gLanguage
lbl_0806f1f4: .4byte 0x06014000
lbl_0806f1f8:
    cmp r0, #4
    beq lbl_0806f204
    b lbl_0806f20a
lbl_0806f1fe:
    ldrb r0, [r4, #0xc]
    adds r0, #1
    strb r0, [r4, #0xc]
lbl_0806f204:
    movs r0, #0
    strh r0, [r4, #2]
    b lbl_0806f24c
lbl_0806f20a:
    ldrb r0, [r4, #7]
    cmp r0, #1
    bhi lbl_0806f24c
    subs r5, #1
    cmp r5, #0
    bne lbl_0806f1aa
    b lbl_0806f24c
lbl_0806f218:
    ldr r1, lbl_0806f244 @ =gCurrentMessage
    ldrb r0, [r1, #7]
    adds r0, #1
    strb r0, [r1, #7]
    ldrb r2, [r1, #0xa]
    adds r1, r2, #0
    cmp r1, #0x15
    bhi lbl_0806f234
    ldr r0, lbl_0806f248 @ =gCurrentItemBeingAcquired
    strb r2, [r0]
    cmp r1, #7
    bls lbl_0806f234
    bl BgClipFinishCollectingAbility
lbl_0806f234:
    ldr r1, lbl_0806f244 @ =gCurrentMessage
    ldrb r0, [r1, #0xc]
    adds r0, #1
    strb r0, [r1, #0xc]
    adds r7, r1, #0
lbl_0806f23e:
    ldrb r0, [r7, #7]
    b lbl_0806f24e
    .align 2, 0
lbl_0806f244: .4byte gCurrentMessage
lbl_0806f248: .4byte gCurrentItemBeingAcquired
lbl_0806f24c:
    movs r0, #0
lbl_0806f24e:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start TextStartMessage
TextStartMessage: @ 0x0806f258
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    ldr r3, lbl_0806f284 @ =gCurrentMessage
    adds r2, r3, #0
    ldr r1, lbl_0806f288 @ =0x0840dc50
    ldm r1!, {r5, r6, r7}
    stm r2!, {r5, r6, r7}
    ldr r1, [r1]
    str r1, [r2]
    adds r1, r0, #0
    cmp r0, #0x23
    bls lbl_0806f278
    movs r1, #0x23
lbl_0806f278:
    strb r1, [r3, #0xa]
    strb r4, [r3, #0xb]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806f284: .4byte gCurrentMessage
lbl_0806f288: .4byte 0x0840dc50

    thumb_func_start TextProcessItemBanner
TextProcessItemBanner: @ 0x0806f28c
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r0, lbl_0806f2a8 @ =gCurrentMessage
    ldrb r2, [r0, #0xc]
    adds r7, r0, #0
    cmp r2, #4
    bls lbl_0806f29c
    b lbl_0806f3ea
lbl_0806f29c:
    lsls r0, r2, #2
    ldr r1, lbl_0806f2ac @ =lbl_0806f2b0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806f2a8: .4byte gCurrentMessage
lbl_0806f2ac: .4byte lbl_0806f2b0
lbl_0806f2b0: @ jump table
    .4byte lbl_0806f2c4 @ case 0
    .4byte lbl_0806f2f4 @ case 1
    .4byte lbl_0806f338 @ case 2
    .4byte lbl_0806f3c4 @ case 3
    .4byte lbl_0806f3ea @ case 4
lbl_0806f2c4:
    movs r6, #1
    rsbs r6, r6, #0
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r0, lbl_0806f2ec @ =0x06014000
    adds r2, r2, r0
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r3, lbl_0806f2f0 @ =0x06014400
    b lbl_0806f318
    .align 2, 0
lbl_0806f2ec: .4byte 0x06014000
lbl_0806f2f0: .4byte 0x06014400
lbl_0806f2f4:
    movs r6, #1
    rsbs r6, r6, #0
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r0, lbl_0806f330 @ =0x06014800
    adds r2, r2, r0
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r3, lbl_0806f334 @ =0x06014c00
lbl_0806f318:
    adds r2, r2, r3
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r0, [r7, #0xc]
    adds r0, #1
    strb r0, [r7, #0xc]
    b lbl_0806f3f8
    .align 2, 0
lbl_0806f330: .4byte 0x06014800
lbl_0806f334: .4byte 0x06014c00
lbl_0806f338:
    movs r5, #8
    ldrb r0, [r7, #7]
    cmp r0, #1
    bhi lbl_0806f346
    ldrb r0, [r7, #0xe]
    cmp r0, #0
    beq lbl_0806f34e
lbl_0806f346:
    ldrb r0, [r7, #0xc]
    adds r0, #1
    strb r0, [r7, #0xc]
    movs r5, #0
lbl_0806f34e:
    cmp r5, #0
    beq lbl_0806f3f8
    ldr r4, lbl_0806f394 @ =gCurrentMessage
    ldr r6, lbl_0806f398 @ =0x08760780
lbl_0806f356:
    ldr r0, lbl_0806f39c @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r1, [r4, #0xa]
    ldr r0, [r0]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r1, [r1]
    ldrb r2, [r4, #0xb]
    lsls r2, r2, #0xb
    ldrb r0, [r4, #7]
    lsls r0, r0, #0xb
    ldr r3, lbl_0806f3a0 @ =0x06014000
    adds r0, r0, r3
    adds r2, r2, r0
    adds r0, r4, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0806f3aa
    cmp r0, #2
    bgt lbl_0806f3a4
    cmp r0, #1
    beq lbl_0806f3b0
    b lbl_0806f3b6
    .align 2, 0
lbl_0806f394: .4byte gCurrentMessage
lbl_0806f398: .4byte 0x08760780
lbl_0806f39c: .4byte gLanguage
lbl_0806f3a0: .4byte 0x06014000
lbl_0806f3a4:
    cmp r0, #4
    beq lbl_0806f3b0
    b lbl_0806f3b6
lbl_0806f3aa:
    ldrb r0, [r4, #0xc]
    adds r0, #1
    strb r0, [r4, #0xc]
lbl_0806f3b0:
    movs r0, #0
    strh r0, [r4, #2]
    b lbl_0806f3f8
lbl_0806f3b6:
    ldrb r0, [r4, #7]
    cmp r0, #1
    bhi lbl_0806f3f8
    subs r5, #1
    cmp r5, #0
    bne lbl_0806f356
    b lbl_0806f3f8
lbl_0806f3c4:
    ldr r1, lbl_0806f3f0 @ =gCurrentMessage
    ldrb r0, [r1, #7]
    adds r0, #1
    strb r0, [r1, #7]
    ldrb r2, [r1, #0xa]
    adds r1, r2, #0
    cmp r1, #0x15
    bhi lbl_0806f3e0
    ldr r0, lbl_0806f3f4 @ =gCurrentItemBeingAcquired
    strb r2, [r0]
    cmp r1, #7
    bls lbl_0806f3e0
    bl BgClipFinishCollectingAbility
lbl_0806f3e0:
    ldr r1, lbl_0806f3f0 @ =gCurrentMessage
    ldrb r0, [r1, #0xc]
    adds r0, #1
    strb r0, [r1, #0xc]
    adds r7, r1, #0
lbl_0806f3ea:
    ldrb r0, [r7, #7]
    b lbl_0806f3fa
    .align 2, 0
lbl_0806f3f0: .4byte gCurrentMessage
lbl_0806f3f4: .4byte gCurrentItemBeingAcquired
lbl_0806f3f8:
    movs r0, #0
lbl_0806f3fa:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start TextStartStory
TextStartStory: @ 0x0806f404
    push {r4, r5, r6, lr}
    ldr r3, lbl_0806f41c @ =gCurrentMessage
    adds r2, r3, #0
    ldr r1, lbl_0806f420 @ =0x0840dc60
    ldm r1!, {r4, r5, r6}
    stm r2!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r2]
    strb r0, [r3, #0xa]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806f41c: .4byte gCurrentMessage
lbl_0806f420: .4byte 0x0840dc60

    thumb_func_start TextProcessStory
TextProcessStory: @ 0x0806f424
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r0, lbl_0806f440 @ =gCurrentMessage
    ldrb r1, [r0, #0xc]
    adds r6, r0, #0
    cmp r1, #4
    bls lbl_0806f434
    b lbl_0806f594
lbl_0806f434:
    lsls r0, r1, #2
    ldr r1, lbl_0806f444 @ =lbl_0806f448
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806f440: .4byte gCurrentMessage
lbl_0806f444: .4byte lbl_0806f448
lbl_0806f448: @ jump table
    .4byte lbl_0806f45c @ case 0
    .4byte lbl_0806f49c @ case 1
    .4byte lbl_0806f4d4 @ case 2
    .4byte lbl_0806f588 @ case 3
    .4byte lbl_0806f594 @ case 4
lbl_0806f45c:
    ldrb r1, [r6, #0xa]
    cmp r1, #1
    bne lbl_0806f46a
    movs r0, #2
    strb r0, [r6, #0xc]
    strb r1, [r6, #0xb]
    b lbl_0806f598
lbl_0806f46a:
    ldr r2, lbl_0806f494 @ =0x06007000
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r5, #0
    bl BitFill
    ldr r2, lbl_0806f498 @ =0x06007400
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r5, #0
    bl BitFill
    movs r0, #1
    strb r0, [r6, #0xc]
    b lbl_0806f598
    .align 2, 0
lbl_0806f494: .4byte 0x06007000
lbl_0806f498: .4byte 0x06007400
lbl_0806f49c:
    ldr r2, lbl_0806f4c8 @ =0x06007800
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r5, #0
    bl BitFill
    ldr r2, lbl_0806f4cc @ =0x06007c00
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r5, #0
    bl BitFill
    ldr r1, lbl_0806f4d0 @ =gCurrentMessage
    ldrb r0, [r1, #0xc]
    adds r0, #1
    strb r0, [r1, #0xc]
    b lbl_0806f598
    .align 2, 0
lbl_0806f4c8: .4byte 0x06007800
lbl_0806f4cc: .4byte 0x06007c00
lbl_0806f4d0: .4byte gCurrentMessage
lbl_0806f4d4:
    movs r7, #6
    ldrb r0, [r6, #0xb]
    cmp r0, #0
    beq lbl_0806f4f4
    ldrb r0, [r6, #7]
    cmp r0, #9
    bhi lbl_0806f50c
    ldrb r0, [r6, #0xe]
    cmp r0, #0
    bne lbl_0806f50c
    ldrb r0, [r6, #7]
    lsls r0, r0, #0xb
    ldr r1, lbl_0806f4f0 @ =0x06013000
    b lbl_0806f506
    .align 2, 0
lbl_0806f4f0: .4byte 0x06013000
lbl_0806f4f4:
    ldrb r0, [r6, #7]
    cmp r0, #1
    bhi lbl_0806f50c
    ldrb r0, [r6, #0xe]
    cmp r0, #0
    bne lbl_0806f50c
    ldrb r0, [r6, #7]
    lsls r0, r0, #0xb
    ldr r1, lbl_0806f514 @ =0x06007000
lbl_0806f506:
    adds r5, r0, r1
    cmp r7, #0
    bne lbl_0806f518
lbl_0806f50c:
    movs r0, #3
    strb r0, [r6, #0xc]
    b lbl_0806f598
    .align 2, 0
lbl_0806f514: .4byte 0x06007000
lbl_0806f518:
    ldr r4, lbl_0806f54c @ =gCurrentMessage
    ldr r6, lbl_0806f550 @ =0x0875fee0
lbl_0806f51c:
    ldr r0, lbl_0806f554 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r1, [r4, #0xa]
    ldr r0, [r0]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r1, [r1]
    adds r0, r4, #0
    adds r2, r5, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #2
    beq lbl_0806f55e
    cmp r1, #2
    bgt lbl_0806f558
    cmp r1, #1
    beq lbl_0806f564
    b lbl_0806f56a
    .align 2, 0
lbl_0806f54c: .4byte gCurrentMessage
lbl_0806f550: .4byte 0x0875fee0
lbl_0806f554: .4byte gLanguage
lbl_0806f558:
    cmp r1, #4
    beq lbl_0806f564
    b lbl_0806f56a
lbl_0806f55e:
    ldrb r0, [r4, #0xc]
    adds r0, #1
    strb r0, [r4, #0xc]
lbl_0806f564:
    movs r0, #0
    strh r0, [r4, #2]
    b lbl_0806f598
lbl_0806f56a:
    ldr r2, lbl_0806f584 @ =gCurrentMessage
    ldrb r0, [r2, #0xb]
    movs r1, #2
    cmp r0, #0
    beq lbl_0806f576
    movs r1, #0xa
lbl_0806f576:
    ldrb r0, [r2, #7]
    cmp r0, r1
    bge lbl_0806f598
    subs r7, #1
    cmp r7, #0
    bne lbl_0806f51c
    b lbl_0806f598
    .align 2, 0
lbl_0806f584: .4byte gCurrentMessage
lbl_0806f588:
    ldrb r0, [r6, #7]
    adds r0, #1
    strb r0, [r6, #7]
    ldrb r0, [r6, #0xc]
    adds r0, #1
    strb r0, [r6, #0xc]
lbl_0806f594:
    ldrb r0, [r6, #7]
    b lbl_0806f59a
lbl_0806f598:
    movs r0, #0
lbl_0806f59a:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start start_file_screen_text
start_file_screen_text: @ 0x0806f5a4
    push {r4, r5, r6, lr}
    ldr r3, lbl_0806f5bc @ =gCurrentMessage
    adds r2, r3, #0
    ldr r1, lbl_0806f5c0 @ =0x0840dc70
    ldm r1!, {r4, r5, r6}
    stm r2!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r2]
    strb r0, [r3, #0xa]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806f5bc: .4byte gCurrentMessage
lbl_0806f5c0: .4byte 0x0840dc70

    thumb_func_start sub_0806f5c4
sub_0806f5c4: @ 0x0806f5c4
    push {r4, r5, r6, lr}
    ldr r0, lbl_0806f5ec @ =gCurrentMessage
    ldrb r1, [r0, #0xc]
    adds r2, r0, #0
    cmp r1, #1
    beq lbl_0806f668
    cmp r1, #1
    bgt lbl_0806f674
    cmp r1, #0
    bne lbl_0806f674
    movs r5, #8
    ldrb r0, [r2, #7]
    cmp r0, #3
    bhi lbl_0806f5e6
    ldrb r0, [r2, #0xe]
    cmp r0, #0
    beq lbl_0806f5f0
lbl_0806f5e6:
    movs r0, #1
    strb r0, [r2, #0xc]
    b lbl_0806f678
    .align 2, 0
lbl_0806f5ec: .4byte gCurrentMessage
lbl_0806f5f0:
    ldrb r0, [r2, #7]
    lsls r0, r0, #0xb
    movs r1, #0xc0
    lsls r1, r1, #0x13
    adds r6, r0, r1
lbl_0806f5fa:
    ldr r4, lbl_0806f630 @ =gCurrentMessage
    ldr r1, lbl_0806f634 @ =0x0876079c
    ldr r0, lbl_0806f638 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r1, [r4, #0xa]
    ldr r0, [r0]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r1, [r1]
    adds r0, r4, #0
    adds r2, r6, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0806f642
    cmp r0, #2
    bgt lbl_0806f63c
    cmp r0, #1
    beq lbl_0806f648
    b lbl_0806f654
    .align 2, 0
lbl_0806f630: .4byte gCurrentMessage
lbl_0806f634: .4byte 0x0876079c
lbl_0806f638: .4byte gLanguage
lbl_0806f63c:
    cmp r0, #4
    beq lbl_0806f648
    b lbl_0806f654
lbl_0806f642:
    ldrb r0, [r4, #0xc]
    adds r0, #1
    strb r0, [r4, #0xc]
lbl_0806f648:
    ldr r1, lbl_0806f650 @ =gCurrentMessage
    movs r0, #0
    strh r0, [r1, #2]
    b lbl_0806f678
    .align 2, 0
lbl_0806f650: .4byte gCurrentMessage
lbl_0806f654:
    ldr r0, lbl_0806f664 @ =gCurrentMessage
    ldrb r0, [r0, #7]
    cmp r0, #3
    bhi lbl_0806f678
    subs r5, #1
    cmp r5, #0
    bne lbl_0806f5fa
    b lbl_0806f678
    .align 2, 0
lbl_0806f664: .4byte gCurrentMessage
lbl_0806f668:
    ldrb r0, [r2, #7]
    adds r0, #1
    strb r0, [r2, #7]
    ldrb r0, [r2, #0xc]
    adds r0, #1
    strb r0, [r2, #0xc]
lbl_0806f674:
    ldrb r0, [r2, #7]
    b lbl_0806f67a
lbl_0806f678:
    movs r0, #0
lbl_0806f67a:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start sub_0806f680
sub_0806f680: @ 0x0806f680
    push {r4, r5, r6, lr}
    sub sp, #4
    ldr r1, lbl_0806f6e4 @ =sNonGameplayRamPointer
    ldr r3, [r1]
    adds r0, r3, #0
    adds r0, #0x57
    adds r2, r3, #0
    adds r2, #0xc1
    ldrb r0, [r0]
    adds r6, r1, #0
    ldrb r2, [r2]
    cmp r0, r2
    beq lbl_0806f6cc
    ldr r0, lbl_0806f6e8 @ =0x00000123
    adds r2, r3, r0
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r2]
    ldr r0, [r6]
    adds r0, #0x56
    movs r2, #0
    strb r2, [r0]
    ldr r0, [r6]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r1, [r1]
    adds r0, #0x57
    strb r1, [r0]
    ldr r0, [r6]
    adds r0, #0x58
    strb r2, [r0]
    ldr r1, lbl_0806f6ec @ =gCurrentMessage
    ldr r0, lbl_0806f6f0 @ =0x0840dc80
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldr r0, [r0]
    str r0, [r1]
lbl_0806f6cc:
    ldr r0, [r6]
    adds r0, #0x56
    ldrb r0, [r0]
    cmp r0, #6
    bls lbl_0806f6d8
    b lbl_0806f974
lbl_0806f6d8:
    lsls r0, r0, #2
    ldr r1, lbl_0806f6f4 @ =lbl_0806f6f8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806f6e4: .4byte sNonGameplayRamPointer
lbl_0806f6e8: .4byte 0x00000123
lbl_0806f6ec: .4byte gCurrentMessage
lbl_0806f6f0: .4byte 0x0840dc80
lbl_0806f6f4: .4byte lbl_0806f6f8
lbl_0806f6f8: @ jump table
    .4byte lbl_0806f714 @ case 0
    .4byte lbl_0806f758 @ case 1
    .4byte lbl_0806f794 @ case 2
    .4byte lbl_0806f87e @ case 3
    .4byte lbl_0806f8dc @ case 4
    .4byte lbl_0806f930 @ case 5
    .4byte lbl_0806f974 @ case 6
lbl_0806f714:
    ldr r0, [r6]
    adds r0, #0x57
    ldrb r0, [r0]
    bl get_current_equipment_selected
    ldr r1, [r6]
    adds r1, #0x58
    strb r0, [r1]
    ldr r2, lbl_0806f74c @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r1, [r6]
    adds r0, r1, #0
    adds r0, #0x58
    ldrb r0, [r0]
    cmp r0, #0x12
    bhi lbl_0806f750
    adds r1, #0x56
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0806f974
    .align 2, 0
lbl_0806f74c: .4byte 0x06007800
lbl_0806f750:
    adds r1, #0x56
    movs r0, #0x80
    strb r0, [r1]
    b lbl_0806f974
lbl_0806f758:
    ldr r2, lbl_0806f78c @ =gCurrentMessage
    ldrh r0, [r2, #4]
    adds r0, #1
    strh r0, [r2, #4]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrb r5, [r2, #9]
    cmp r0, r5
    bhi lbl_0806f778
    ldr r0, lbl_0806f790 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0806f778
    b lbl_0806f974
lbl_0806f778:
    movs r0, #0
    strb r0, [r2, #9]
    ldr r1, [r6]
    adds r1, #0x56
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    movs r0, #0
    strh r0, [r2, #4]
    b lbl_0806f974
    .align 2, 0
lbl_0806f78c: .4byte gCurrentMessage
lbl_0806f790: .4byte gChangedInput
lbl_0806f794:
    ldr r5, lbl_0806f7d4 @ =gCurrentMessage
    ldr r2, lbl_0806f7d8 @ =0x087602d4
    ldr r0, lbl_0806f7dc @ =gLanguage
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r1, r1, #2
    adds r1, r1, r2
    ldr r0, [r6]
    adds r0, #0x58
    ldrb r0, [r0]
    ldr r1, [r1]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r1, [r0]
    ldr r2, lbl_0806f7e0 @ =0x06007800
    adds r0, r5, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #2
    bne lbl_0806f7f0
    ldrb r0, [r5, #7]
    cmp r0, #0
    beq lbl_0806f7e4
    movs r4, #5
    ldr r0, [r6]
    adds r0, #0x56
    movs r1, #4
    strb r1, [r0]
    b lbl_0806f81c
    .align 2, 0
lbl_0806f7d4: .4byte gCurrentMessage
lbl_0806f7d8: .4byte 0x087602d4
lbl_0806f7dc: .4byte gLanguage
lbl_0806f7e0: .4byte 0x06007800
lbl_0806f7e4:
    movs r4, #0
    ldr r0, [r6]
    adds r0, #0x56
    movs r1, #6
    strb r1, [r0]
    b lbl_0806f81c
lbl_0806f7f0:
    cmp r4, #1
    bne lbl_0806f81a
    movs r4, #4
    movs r0, #0
    strh r0, [r5, #4]
    ldr r0, lbl_0806f80c @ =gDemoState
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0806f810
    ldr r0, [r6]
    adds r0, #0x56
    movs r1, #5
    strb r1, [r0]
    b lbl_0806f81c
    .align 2, 0
lbl_0806f80c: .4byte gDemoState
lbl_0806f810:
    ldr r0, [r6]
    adds r0, #0x56
    movs r1, #3
    strb r1, [r0]
    b lbl_0806f81c
lbl_0806f81a:
    movs r4, #0
lbl_0806f81c:
    cmp r4, #0
    bne lbl_0806f822
    b lbl_0806f974
lbl_0806f822:
    ldr r1, lbl_0806f84c @ =sNonGameplayRamPointer
    ldr r3, [r1]
    ldr r0, lbl_0806f850 @ =gCurrentMessage
    ldrh r0, [r0, #2]
    adds r0, #0xa
    lsls r0, r0, #2
    movs r5, #0x8d
    lsls r5, r5, #1
    adds r2, r3, r5
    strh r0, [r2]
    adds r6, r1, #0
    cmp r4, #4
    bne lbl_0806f854
    movs r0, #0x8c
    lsls r0, r0, #1
    adds r1, r3, r0
    movs r0, #0x90
    lsls r0, r0, #2
    strh r0, [r1]
    b lbl_0806f86e
    .align 2, 0
lbl_0806f84c: .4byte sNonGameplayRamPointer
lbl_0806f850: .4byte gCurrentMessage
lbl_0806f854:
    movs r2, #0x8c
    lsls r2, r2, #1
    adds r1, r3, r2
    movs r0, #0x89
    lsls r0, r0, #2
    strh r0, [r1]
    ldrh r1, [r3]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806f86e
    movs r4, #0
lbl_0806f86e:
    ldr r0, [r6]
    movs r3, #0x8c
    lsls r3, r3, #1
    adds r0, r0, r3
    adds r1, r4, #0
    bl UpdateMenuOamDataID
    b lbl_0806f974
lbl_0806f87e:
    ldr r0, lbl_0806f8c4 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0806f892
    ldr r0, lbl_0806f8c8 @ =gDemoState
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0806f974
lbl_0806f892:
    ldr r2, lbl_0806f8cc @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r3, lbl_0806f8d0 @ =sNonGameplayRamPointer
    ldr r0, [r3]
    adds r0, #0x56
    movs r2, #0
    movs r1, #1
    strb r1, [r0]
    ldr r0, lbl_0806f8d4 @ =gCurrentMessage
    strh r2, [r0, #4]
    strh r2, [r0, #2]
    movs r1, #0xa
    strb r1, [r0, #9]
    ldr r0, [r3]
    ldr r4, lbl_0806f8d8 @ =0x00000123
    adds r2, r0, r4
    b lbl_0806f96c
    .align 2, 0
lbl_0806f8c4: .4byte gChangedInput
lbl_0806f8c8: .4byte gDemoState
lbl_0806f8cc: .4byte 0x06007800
lbl_0806f8d0: .4byte sNonGameplayRamPointer
lbl_0806f8d4: .4byte gCurrentMessage
lbl_0806f8d8: .4byte 0x00000123
lbl_0806f8dc:
    ldr r0, lbl_0806f918 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806f974
    ldr r2, lbl_0806f91c @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r2, lbl_0806f920 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0x56
    movs r1, #1
    strb r1, [r0]
    ldr r1, lbl_0806f924 @ =gCurrentMessage
    ldr r0, lbl_0806f928 @ =0x0840dc80
    ldm r0!, {r3, r4, r5}
    stm r1!, {r3, r4, r5}
    ldr r0, [r0]
    str r0, [r1]
    ldr r0, [r2]
    ldr r5, lbl_0806f92c @ =0x00000123
    adds r2, r0, r5
    b lbl_0806f96c
    .align 2, 0
lbl_0806f918: .4byte gChangedInput
lbl_0806f91c: .4byte 0x06007800
lbl_0806f920: .4byte sNonGameplayRamPointer
lbl_0806f924: .4byte gCurrentMessage
lbl_0806f928: .4byte 0x0840dc80
lbl_0806f92c: .4byte 0x00000123
lbl_0806f930:
    ldr r4, lbl_0806f97c @ =gCurrentMessage
    ldrh r0, [r4, #4]
    adds r0, #1
    movs r5, #0
    strh r0, [r4, #4]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x1e
    bls lbl_0806f974
    ldr r2, lbl_0806f980 @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r2, lbl_0806f984 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0x56
    movs r1, #1
    strb r1, [r0]
    strh r5, [r4, #4]
    strh r5, [r4, #2]
    movs r0, #0xa
    strb r0, [r4, #9]
    ldr r0, [r2]
    ldr r1, lbl_0806f988 @ =0x00000123
    adds r2, r0, r1
lbl_0806f96c:
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r2]
lbl_0806f974:
    add sp, #4
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806f97c: .4byte gCurrentMessage
lbl_0806f980: .4byte 0x06007800
lbl_0806f984: .4byte sNonGameplayRamPointer
lbl_0806f988: .4byte 0x00000123

    thumb_func_start TextProcessCurrentMessage
TextProcessCurrentMessage: @ 0x0806f98c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    adds r4, r0, #0
    adds r6, r1, #0
    mov r8, r2
    movs r5, #1
    rsbs r5, r5, #0
    ldrh r0, [r4, #4]
    adds r2, r0, #1
    strh r2, [r4, #4]
    ldr r0, lbl_0806fa04 @ =gButtonInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0806f9c4
    ldrb r1, [r4, #9]
    lsls r0, r2, #0x10
    lsrs r2, r0, #0x10
    cmp r1, r2
    bls lbl_0806f9bc
    movs r5, #0
lbl_0806f9bc:
    ldrb r0, [r4, #8]
    cmp r0, r2
    bls lbl_0806f9c4
    movs r5, #0
lbl_0806f9c4:
    cmp r5, #0
    bge lbl_0806faba
    movs r0, #0
    strb r0, [r4, #9]
    strh r0, [r4, #4]
    ldrh r0, [r4]
    lsls r0, r0, #1
    adds r6, r6, r0
    movs r0, #0xff
    lsls r0, r0, #8
    mov sb, r0
lbl_0806f9da:
    movs r7, #0
    ldrh r2, [r6]
    mov r1, sb
    ands r1, r2
    movs r0, #0xe1
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa48
    cmp r1, r0
    bgt lbl_0806fa12
    movs r0, #0x81
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa44
    cmp r1, r0
    bgt lbl_0806fa08
    movs r0, #0x80
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa36
    b lbl_0806fa60
    .align 2, 0
lbl_0806fa04: .4byte gButtonInput
lbl_0806fa08:
    movs r0, #0x83
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa3c
    b lbl_0806fa60
lbl_0806fa12:
    movs r0, #0xfd
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa50
    cmp r1, r0
    bgt lbl_0806fa28
    movs r0, #0xfc
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa54
    b lbl_0806fa60
lbl_0806fa28:
    movs r0, #0xfe
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa4c
    cmp r1, sb
    beq lbl_0806fa58
    b lbl_0806fa60
lbl_0806fa36:
    movs r7, #0xff
    ands r7, r2
    b lbl_0806fa6a
lbl_0806fa3c:
    movs r0, #0xff
    ands r0, r2
    strh r0, [r4, #2]
    b lbl_0806fa6a
lbl_0806fa44:
    strb r2, [r4, #6]
    b lbl_0806fa6a
lbl_0806fa48:
    strb r2, [r4, #9]
    b lbl_0806fa6a
lbl_0806fa4c:
    movs r5, #1
    b lbl_0806fa6a
lbl_0806fa50:
    movs r5, #4
    b lbl_0806fa6a
lbl_0806fa54:
    movs r5, #3
    b lbl_0806fa6a
lbl_0806fa58:
    movs r0, #1
    strb r0, [r4, #0xe]
    movs r5, #2
    b lbl_0806fa6a
lbl_0806fa60:
    ldrh r0, [r6]
    bl get_chararcter_width
    adds r7, r0, #0
    movs r5, #0
lbl_0806fa6a:
    ldrh r2, [r4, #2]
    adds r0, r2, r7
    cmp r0, #0xe0
    ble lbl_0806fa76
    movs r5, #1
    b lbl_0806faba
lbl_0806fa76:
    cmp r5, #0
    bge lbl_0806fa7e
    adds r6, #2
    b lbl_0806faaa
lbl_0806fa7e:
    cmp r5, #0
    bne lbl_0806faa0
    ldrb r0, [r4, #0xd]
    cmp r0, #0
    beq lbl_0806fa94
    ldrh r0, [r6]
    ldrb r3, [r4, #6]
    mov r1, r8
    bl draw_character_for_message
    b lbl_0806faaa
lbl_0806fa94:
    ldrh r0, [r6]
    ldrb r3, [r4, #6]
    mov r1, r8
    bl draw_character_for_text
    b lbl_0806faaa
lbl_0806faa0:
    cmp r5, #2
    beq lbl_0806faaa
    ldrb r0, [r4, #7]
    adds r0, #1
    strb r0, [r4, #7]
lbl_0806faaa:
    ldrh r0, [r4, #2]
    adds r0, r0, r7
    strh r0, [r4, #2]
    ldrh r0, [r4]
    adds r0, #1
    strh r0, [r4]
    cmp r5, #0
    blt lbl_0806f9da
lbl_0806faba:
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start TextDrawYesNoEasySleep
TextDrawYesNoEasySleep: @ 0x0806facc
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r1, lbl_0806fb48 @ =0x0000ffff
    ldr r0, lbl_0806fb4c @ =sEwramPointer
    ldr r2, [r0]
    movs r0, #0x80
    lsls r0, r0, #7
    adds r2, r2, r0
    movs r3, #0xa0
    lsls r3, r3, #6
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl BitFill
    ldr r0, lbl_0806fb50 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xe9
    movs r1, #0
    strb r1, [r0]
    ldr r1, lbl_0806fb54 @ =0x08760780
    ldr r0, lbl_0806fb58 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    adds r0, #0x98
    ldr r4, [r0]
    ldr r5, lbl_0806fb5c @ =gCurrentMessage
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r5, #0
    movs r3, #0x10
    bl BitFill
    ldrh r1, [r4]
    movs r0, #0xff
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fba8
    movs r2, #0xfe
    lsls r2, r2, #8
    mov r8, r2
    adds r7, r0, #0
    movs r6, #0x81
    lsls r6, r6, #8
lbl_0806fb34:
    movs r2, #1
    cmp r1, r8
    bne lbl_0806fb60
    ldr r1, lbl_0806fb5c @ =gCurrentMessage
    ldrh r0, [r1, #2]
    cmp r0, #0x70
    bhi lbl_0806fba8
    movs r0, #0x70
    strh r0, [r1, #2]
    b lbl_0806fba0
    .align 2, 0
lbl_0806fb48: .4byte 0x0000ffff
lbl_0806fb4c: .4byte sEwramPointer
lbl_0806fb50: .4byte sNonGameplayRamPointer
lbl_0806fb54: .4byte 0x08760780
lbl_0806fb58: .4byte gLanguage
lbl_0806fb5c: .4byte gCurrentMessage
lbl_0806fb60:
    movs r3, #0x80
    lsls r3, r3, #8
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0806fb7c
    movs r2, #0xff
    lsls r2, r2, #8
    adds r0, r2, #0
    ands r0, r1
    cmp r0, r6
    bne lbl_0806fb7a
    strb r1, [r5, #6]
lbl_0806fb7a:
    movs r2, #0
lbl_0806fb7c:
    cmp r2, #0
    beq lbl_0806fba0
    ldrh r0, [r4]
    ldr r1, lbl_0806fbb4 @ =sEwramPointer
    ldr r1, [r1]
    movs r3, #0xc0
    lsls r3, r3, #7
    adds r1, r1, r3
    ldrh r2, [r5, #2]
    ldrb r3, [r5, #6]
    bl draw_character_for_message
    ldrh r0, [r4]
    bl get_chararcter_width
    ldrh r1, [r5, #2]
    adds r1, r1, r0
    strh r1, [r5, #2]
lbl_0806fba0:
    adds r4, #2
    ldrh r1, [r4]
    cmp r1, r7
    bne lbl_0806fb34
lbl_0806fba8:
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806fbb4: .4byte sEwramPointer

    thumb_func_start TextDrawEasySleep
TextDrawEasySleep: @ 0x0806fbb8
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r5, lbl_0806fbd4 @ =sNonGameplayRamPointer
    ldr r0, [r5]
    adds r0, #0xe9
    ldrb r0, [r0]
    cmp r0, #1
    beq lbl_0806fc02
    cmp r0, #1
    bgt lbl_0806fbd8
    cmp r0, #0
    beq lbl_0806fbe2
    b lbl_0806fce8
    .align 2, 0
lbl_0806fbd4: .4byte sNonGameplayRamPointer
lbl_0806fbd8:
    cmp r0, #2
    beq lbl_0806fc80
    cmp r0, #3
    beq lbl_0806fca0
    b lbl_0806fce8
lbl_0806fbe2:
    ldr r4, lbl_0806fc4c @ =gCurrentMessage
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r4, #0
    movs r3, #0x10
    bl BitFill
    movs r0, #1
    strb r0, [r4, #0xd]
    ldr r1, [r5]
    adds r1, #0xe9
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_0806fc02:
    movs r5, #3
    ldr r4, lbl_0806fc4c @ =gCurrentMessage
    ldr r7, lbl_0806fc50 @ =0x08760780
    ldr r6, lbl_0806fc54 @ =sEwramPointer
lbl_0806fc0a:
    ldr r0, lbl_0806fc58 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r7
    ldr r0, [r0]
    adds r0, #0x90
    ldr r1, [r0]
    ldrb r0, [r4, #7]
    lsls r0, r0, #0xb
    movs r2, #0x80
    lsls r2, r2, #7
    adds r0, r0, r2
    ldr r2, [r6]
    adds r2, r2, r0
    adds r0, r4, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0806fc40
    movs r0, #0
    strh r0, [r4, #2]
    ldrb r0, [r4, #0xe]
    cmp r0, #0
    bne lbl_0806fc5c
lbl_0806fc40:
    subs r5, #1
    movs r0, #1
    rsbs r0, r0, #0
    cmp r5, r0
    bne lbl_0806fc0a
    b lbl_0806fce8
    .align 2, 0
lbl_0806fc4c: .4byte gCurrentMessage
lbl_0806fc50: .4byte 0x08760780
lbl_0806fc54: .4byte sEwramPointer
lbl_0806fc58: .4byte gLanguage
lbl_0806fc5c:
    ldr r0, lbl_0806fc6c @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r1, #0xe9
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0806fce8
    .align 2, 0
lbl_0806fc6c: .4byte sNonGameplayRamPointer
lbl_0806fc70:
    ldr r0, lbl_0806fc7c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xe9
    movs r1, #0x80
    strb r1, [r0]
    b lbl_0806fce8
    .align 2, 0
lbl_0806fc7c: .4byte sNonGameplayRamPointer
lbl_0806fc80:
    ldr r4, lbl_0806fcf0 @ =gCurrentMessage
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r4, #0
    movs r3, #0x10
    bl BitFill
    movs r0, #1
    strb r0, [r4, #0xd]
    ldr r1, [r5]
    adds r1, #0xe9
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_0806fca0:
    movs r5, #3
    ldr r4, lbl_0806fcf0 @ =gCurrentMessage
    ldr r7, lbl_0806fcf4 @ =0x08760780
    ldr r6, lbl_0806fcf8 @ =sEwramPointer
lbl_0806fca8:
    ldr r0, lbl_0806fcfc @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r7
    ldr r0, [r0]
    adds r0, #0x94
    ldr r1, [r0]
    ldrb r0, [r4, #7]
    lsls r0, r0, #0xb
    movs r2, #0xa0
    lsls r2, r2, #7
    adds r0, r0, r2
    ldr r2, [r6]
    adds r2, r2, r0
    adds r0, r4, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0806fcde
    movs r0, #0
    strh r0, [r4, #2]
    ldrb r0, [r4, #0xe]
    cmp r0, #0
    bne lbl_0806fc70
lbl_0806fcde:
    subs r5, #1
    movs r0, #1
    rsbs r0, r0, #0
    cmp r5, r0
    bne lbl_0806fca8
lbl_0806fce8:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806fcf0: .4byte gCurrentMessage
lbl_0806fcf4: .4byte 0x08760780
lbl_0806fcf8: .4byte sEwramPointer
lbl_0806fcfc: .4byte gLanguage

    thumb_func_start UpdateMinimapAnimatedPalette
UpdateMinimapAnimatedPalette: @ 0x0806fd00
    push {r4, r5, lr}
    ldr r0, lbl_0806fdf4 @ =sNonGameplayRamPointer
    ldr r3, [r0]
    ldrb r4, [r3, #0x11]
    adds r5, r0, #0
    cmp r4, #0
    bne lbl_0806fd86
    ldrh r0, [r3, #0x18]
    adds r0, #1
    strh r0, [r3, #0x18]
    ldr r2, lbl_0806fdf8 @ =0x0840dcf0
    movs r1, #0x1a
    ldrsb r1, [r3, r1]
    adds r1, r1, r2
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrb r1, [r1]
    cmp r0, r1
    blo lbl_0806fd86
    strh r4, [r3, #0x18]
    ldrb r0, [r3, #0x1a]
    adds r0, #1
    strb r0, [r3, #0x1a]
    ldr r1, [r5]
    ldrb r0, [r1, #0x1a]
    cmp r0, #3
    bls lbl_0806fd3a
    movs r0, #0
    strb r0, [r1, #0x1a]
lbl_0806fd3a:
    ldr r1, lbl_0806fdfc @ =0x0840dcb0
    ldr r2, [r5]
    movs r0, #0x1a
    ldrsb r0, [r2, r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r3, [r0]
    ldr r0, lbl_0806fe00 @ =0x08754bb8
    ldr r0, [r0]
    mov ip, r0
    strh r3, [r0, #0x24]
    strh r3, [r0, #0x26]
    ldr r1, lbl_0806fe04 @ =0x0840dc90
    movs r0, #0x1a
    ldrsb r0, [r2, r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r3, [r0]
    mov r0, ip
    adds r0, #0x64
    strh r3, [r0]
    adds r0, #2
    strh r3, [r0]
    ldr r1, lbl_0806fe08 @ =0x0840dcd0
    movs r0, #0x1a
    ldrsb r0, [r2, r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r3, [r0]
    mov r0, ip
    adds r0, #0x44
    strh r3, [r0]
    adds r0, #2
    strh r3, [r0]
    adds r0, #0x3e
    strh r3, [r0]
    adds r0, #2
    strh r3, [r0]
lbl_0806fd86:
    adds r4, r5, #0
    ldr r2, [r4]
    ldrb r0, [r2, #0x12]
    cmp r0, #7
    bhi lbl_0806fdee
    ldrh r0, [r2, #0x1c]
    adds r0, #1
    strh r0, [r2, #0x1c]
    movs r3, #0x1e
    ldrsb r3, [r2, r3]
    cmp r3, #0
    bge lbl_0806fda0
    rsbs r3, r3, #0
lbl_0806fda0:
    ldr r1, lbl_0806fe0c @ =0x0840dcf4
    adds r1, r3, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrb r1, [r1]
    cmp r0, r1
    blo lbl_0806fdee
    movs r0, #0
    strh r0, [r2, #0x1c]
    ldrb r0, [r2, #0x1e]
    adds r0, #1
    strb r0, [r2, #0x1e]
    ldr r1, [r4]
    movs r0, #0x1e
    ldrsb r0, [r1, r0]
    cmp r0, #0x10
    blt lbl_0806fdc8
    movs r0, #0xe
    rsbs r0, r0, #0
    strb r0, [r1, #0x1e]
lbl_0806fdc8:
    ldr r0, [r5]
    movs r3, #0x1e
    ldrsb r3, [r0, r3]
    cmp r3, #0
    bge lbl_0806fdd4
    rsbs r3, r3, #0
lbl_0806fdd4:
    ldr r1, lbl_0806fe10 @ =0x0840dd04
    ldrb r0, [r0, #0x12]
    adds r0, r0, r1
    ldrb r1, [r0]
    ldr r0, lbl_0806fe00 @ =0x08754bb8
    ldr r0, [r0]
    lsls r1, r1, #1
    adds r1, r1, r0
    ldr r2, lbl_0806fe14 @ =0x083fd2f0
    lsls r0, r3, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r1]
lbl_0806fdee:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806fdf4: .4byte sNonGameplayRamPointer
lbl_0806fdf8: .4byte 0x0840dcf0
lbl_0806fdfc: .4byte 0x0840dcb0
lbl_0806fe00: .4byte 0x08754bb8
lbl_0806fe04: .4byte 0x0840dc90
lbl_0806fe08: .4byte 0x0840dcd0
lbl_0806fe0c: .4byte 0x0840dcf4
lbl_0806fe10: .4byte 0x0840dd04
lbl_0806fe14: .4byte 0x083fd2f0

    thumb_func_start LoadPauseScreenBgPalette
LoadPauseScreenBgPalette: @ 0x0806fe18
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r0, lbl_0806fecc @ =0x083fcef0
    adds r0, #0x9e
    ldrh r1, [r0]
    ldr r3, lbl_0806fed0 @ =sEwramPointer
    ldr r0, lbl_0806fed4 @ =0x0840dd04
    ldrb r0, [r0, #8]
    lsls r0, r0, #1
    movs r2, #0xd8
    lsls r2, r2, #7
    adds r0, r0, r2
    ldr r2, [r3]
    adds r2, r2, r0
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x12
    bl BitFill
    movs r3, #0
    ldr r0, lbl_0806fed8 @ =sNonGameplayRamPointer
    mov ip, r0
    movs r5, #1
lbl_0806fe48:
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0xba
    ldrb r2, [r0]
    asrs r2, r3
    ands r2, r5
    ldr r4, lbl_0806fed0 @ =sEwramPointer
    ldr r6, lbl_0806fed4 @ =0x0840dd04
    cmp r2, #0
    bne lbl_0806fe6e
    ldr r0, [r4]
    adds r1, r3, r6
    ldrb r1, [r1]
    lsls r1, r1, #1
    movs r7, #0xd8
    lsls r7, r7, #7
    adds r0, r0, r7
    adds r0, r0, r1
    strh r2, [r0]
lbl_0806fe6e:
    adds r3, #1
    cmp r3, #6
    ble lbl_0806fe48
    ldr r2, lbl_0806fedc @ =gCurrentArea
    ldrb r0, [r2]
    cmp r0, #7
    bhi lbl_0806fe92
    ldr r1, [r4]
    adds r0, r0, r6
    ldrb r0, [r0]
    lsls r0, r0, #1
    movs r2, #0xd8
    lsls r2, r2, #7
    adds r1, r1, r2
    adds r1, r1, r0
    ldr r0, lbl_0806fee0 @ =0x083fd2f0
    ldrh r0, [r0]
    strh r0, [r1]
lbl_0806fe92:
    ldr r1, [r4]
    ldrb r0, [r6, #7]
    lsls r0, r0, #1
    movs r4, #0xd8
    lsls r4, r4, #7
    adds r3, r1, r4
    adds r0, r3, r0
    movs r5, #0
    strh r5, [r0]
    ldrb r2, [r6, #8]
    lsls r2, r2, #1
    adds r3, r3, r2
    strh r5, [r3]
    adds r4, r2, r4
    adds r1, r1, r4
    movs r0, #0xa0
    lsls r0, r0, #0x13
    adds r2, r2, r0
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x12
    bl DmaTransfer
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806fecc: .4byte 0x083fcef0
lbl_0806fed0: .4byte sEwramPointer
lbl_0806fed4: .4byte 0x0840dd04
lbl_0806fed8: .4byte sNonGameplayRamPointer
lbl_0806fedc: .4byte gCurrentArea
lbl_0806fee0: .4byte 0x083fd2f0

    thumb_func_start UpdateSuitType
UpdateSuitType: @ 0x0806fee4
    push {lr}
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    ldr r2, lbl_0806ff04 @ =gEquipment
    ldrb r0, [r2, #0x12]
    cmp r0, r1
    beq lbl_0806fef4
    strb r1, [r2, #0x12]
lbl_0806fef4:
    ldrb r0, [r2, #0x12]
    cmp r0, #1
    beq lbl_0806ff24
    cmp r0, #1
    bgt lbl_0806ff08
    cmp r0, #0
    beq lbl_0806ff0e
    b lbl_0806ff48
    .align 2, 0
lbl_0806ff04: .4byte gEquipment
lbl_0806ff08:
    cmp r0, #2
    beq lbl_0806ff3c
    b lbl_0806ff48
lbl_0806ff0e:
    ldrh r0, [r2]
    strh r0, [r2, #6]
    ldrb r1, [r2, #0xc]
    movs r0, #0xf7
    ands r0, r1
    strb r0, [r2, #0xd]
    ldrb r1, [r2, #0xe]
    movs r0, #0xdb
    ands r0, r1
    strb r0, [r2, #0xf]
    b lbl_0806ff48
lbl_0806ff24:
    ldrh r0, [r2]
    movs r1, #0
    strh r0, [r2, #6]
    ldrh r0, [r2, #2]
    strh r0, [r2, #8]
    ldrb r0, [r2, #4]
    strb r0, [r2, #0xa]
    ldrb r0, [r2, #5]
    strb r0, [r2, #0xb]
    strb r1, [r2, #0xd]
    strb r1, [r2, #0xf]
    b lbl_0806ff48
lbl_0806ff3c:
    movs r0, #0x63
    strh r0, [r2, #6]
    movs r0, #0x80
    strb r0, [r2, #0xf]
    movs r0, #0x11
    strb r0, [r2, #0xd]
lbl_0806ff48:
    pop {r0}
    bx r0

    thumb_func_start StatusScreenDrawItems
StatusScreenDrawItems: @ 0x0806ff4c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #7
    bls lbl_0806ff64
    movs r0, #1
    b lbl_0806fff4
lbl_0806ff64:
    movs r4, #0
    ldr r0, lbl_08070004 @ =0x087603d8
    mov sb, r0
    ldr r1, lbl_08070008 @ =0x0840de50
    mov sl, r1
lbl_0806ff6e:
    lsls r1, r4, #1
    cmp r7, #0
    bne lbl_0806ff80
    adds r0, r1, r4
    add r0, sb
    ldrb r0, [r0]
    adds r6, r4, #1
    cmp r0, #2
    beq lbl_0806ffe4
lbl_0806ff80:
    adds r2, r1, r4
    mov r3, sb
    adds r0, r2, r3
    ldrb r0, [r0]
    lsls r1, r0, #2
    adds r1, r1, r0
    mov r5, sl
    adds r0, r1, r5
    ldrb r0, [r0]
    adds r0, r0, r7
    ldr r3, lbl_0807000c @ =0x0840de52
    adds r1, r1, r3
    lsls r0, r0, #5
    ldrb r1, [r1]
    adds r3, r0, r1
    ldr r5, lbl_08070010 @ =0x087603d9
    adds r0, r2, r5
    ldrb r0, [r0]
    adds r6, r4, #1
    cmp r0, r7
    bls lbl_0806ffe4
    movs r4, #0
    ldr r1, lbl_08070014 @ =0x087603da
    adds r0, r2, r1
    ldrb r5, [r0]
    cmp r4, r5
    bge lbl_0806ffe4
    ldr r1, lbl_08070018 @ =sEwramPointer
    mov r8, r1
    movs r5, #0xe0
    lsls r5, r5, #7
    mov ip, r5
    str r0, [sp]
    lsls r0, r3, #1
    ldr r1, lbl_0807001c @ =0x0600c000
    adds r2, r0, r1
lbl_0806ffc8:
    lsls r0, r3, #1
    mov r5, r8
    ldr r1, [r5]
    add r1, ip
    adds r1, r1, r0
    ldrh r0, [r1]
    strh r0, [r2]
    adds r4, #1
    adds r2, #2
    adds r3, #1
    ldr r0, [sp]
    ldrb r0, [r0]
    cmp r4, r0
    blt lbl_0806ffc8
lbl_0806ffe4:
    adds r4, r6, #0
    cmp r4, #5
    ble lbl_0806ff6e
    movs r4, #0
    cmp r7, #6
    bls lbl_0806fff2
    movs r4, #1
lbl_0806fff2:
    adds r0, r4, #0
lbl_0806fff4:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08070004: .4byte 0x087603d8
lbl_08070008: .4byte 0x0840de50
lbl_0807000c: .4byte 0x0840de52
lbl_08070010: .4byte 0x087603d9
lbl_08070014: .4byte 0x087603da
lbl_08070018: .4byte sEwramPointer
lbl_0807001c: .4byte 0x0600c000

    thumb_func_start StatusScreenGetSlotForNewItem
StatusScreenGetSlotForNewItem: @ 0x08070020
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov ip, r0
    lsls r1, r1, #0x18
    lsrs r2, r1, #0x18
    cmp r2, #0x15
    bhi lbl_08070062
    mov r0, ip
    cmp r0, #0
    bne lbl_0807004c
    ldr r0, lbl_08070048 @ =0x0840df0c
    lsls r1, r2, #2
    adds r1, r1, r0
    ldrb r0, [r1]
    b lbl_08070172
    .align 2, 0
lbl_08070048: .4byte 0x0840df0c
lbl_0807004c:
    mov r0, ip
    cmp r0, #1
    bne lbl_0807006c
    ldr r1, lbl_08070068 @ =0x0840df0c
    lsls r2, r2, #2
    adds r0, r2, r1
    ldrb r0, [r0]
    mov sb, r1
    adds r7, r2, #0
    cmp r0, #1
    bhi lbl_08070084
lbl_08070062:
    movs r0, #0
    b lbl_08070172
    .align 2, 0
lbl_08070068: .4byte 0x0840df0c
lbl_0807006c:
    ldr r0, lbl_08070080 @ =0x0840df0c
    lsls r1, r2, #2
    adds r3, r1, r0
    ldrb r2, [r3]
    mov sb, r0
    adds r7, r1, #0
    cmp r2, #3
    beq lbl_08070084
    ldrb r0, [r3, #3]
    b lbl_08070172
    .align 2, 0
lbl_08070080: .4byte 0x0840df0c
lbl_08070084:
    movs r5, #0
    mov r0, sb
    adds r2, r7, r0
    ldrb r6, [r2, #3]
    ldrb r0, [r2, #1]
    cmp r0, #1
    beq lbl_080700c8
    cmp r0, #1
    bgt lbl_0807009c
    cmp r0, #0
    beq lbl_080700a6
    b lbl_08070120
lbl_0807009c:
    cmp r0, #2
    beq lbl_080700e8
    cmp r0, #3
    beq lbl_0807010c
    b lbl_08070120
lbl_080700a6:
    ldr r1, lbl_080700bc @ =0x0840d0f0
    ldrb r0, [r2, #2]
    adds r0, r0, r1
    ldrb r5, [r0]
    ldr r0, lbl_080700c0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r4, r0, #0
    adds r4, #0xc4
    ldr r2, lbl_080700c4 @ =gEquipment+0xD
    mov r8, r2
    b lbl_08070120
    .align 2, 0
lbl_080700bc: .4byte 0x0840d0f0
lbl_080700c0: .4byte sNonGameplayRamPointer
lbl_080700c4: .4byte gEquipment+0xD
lbl_080700c8:
    ldr r1, lbl_080700dc @ =0x0840d0f5
    ldrb r0, [r2, #2]
    adds r0, r0, r1
    ldrb r5, [r0]
    ldr r0, lbl_080700e0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r4, r0, #0
    adds r4, #0xd1
    ldr r0, lbl_080700e4 @ =gEquipment+0xD
    b lbl_0807011e
    .align 2, 0
lbl_080700dc: .4byte 0x0840d0f5
lbl_080700e0: .4byte sNonGameplayRamPointer
lbl_080700e4: .4byte gEquipment+0xD
lbl_080700e8:
    ldr r1, lbl_08070100 @ =0x0840d0f6
    ldrb r0, [r2, #2]
    adds r0, r0, r1
    ldrb r5, [r0]
    ldr r0, lbl_08070104 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r4, r0, #0
    adds r4, #0xc9
    ldr r2, lbl_08070108 @ =gEquipment+0xF
    mov r8, r2
    b lbl_08070120
    .align 2, 0
lbl_08070100: .4byte 0x0840d0f6
lbl_08070104: .4byte sNonGameplayRamPointer
lbl_08070108: .4byte gEquipment+0xF
lbl_0807010c:
    ldr r1, lbl_0807013c @ =0x0840d0f8
    ldrb r0, [r2, #2]
    adds r0, r0, r1
    ldrb r5, [r0]
    ldr r0, lbl_08070140 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r4, r0, #0
    adds r4, #0xcb
    ldr r0, lbl_08070144 @ =gEquipment+0xF
lbl_0807011e:
    mov r8, r0
lbl_08070120:
    mov r2, ip
    cmp r2, #1
    bne lbl_08070148
    mov r0, r8
    ldrb r2, [r0]
    adds r1, r5, #0
    ands r1, r2
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r6, r0, #0x1f
    bics r2, r5
    mov r0, r8
    strb r2, [r0]
    b lbl_08070170
    .align 2, 0
lbl_0807013c: .4byte 0x0840d0f8
lbl_08070140: .4byte sNonGameplayRamPointer
lbl_08070144: .4byte gEquipment+0xF
lbl_08070148:
    movs r3, #0
    ldr r1, lbl_08070158 @ =0x0840d0fe
    mov r2, sb
    adds r0, r7, r2
    ldrb r0, [r0, #1]
    adds r0, r0, r1
    ldrb r1, [r0]
    b lbl_08070166
    .align 2, 0
lbl_08070158: .4byte 0x0840d0fe
lbl_0807015c:
    adds r4, #1
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    adds r3, #1
lbl_08070166:
    cmp r3, r1
    bge lbl_08070170
    ldrb r0, [r4]
    cmp r0, r5
    bne lbl_0807015c
lbl_08070170:
    adds r0, r6, #0
lbl_08070172:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start StatusScreenDraw
StatusScreenDraw: @ 0x08070180
    push {r4, r5, r6, r7, lr}
    sub sp, #8
    ldr r6, lbl_080701e0 @ =gEquipment
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_080701ec
    ldr r5, lbl_080701e4 @ =sEwramPointer
    ldr r2, [r5]
    movs r0, #0x80
    lsls r0, r0, #8
    adds r1, r2, r0
    movs r4, #0xe0
    lsls r4, r4, #7
    adds r2, r2, r4
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
    ldr r0, lbl_080701e8 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    adds r2, #0xc0
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x18
    bl BitFill
    ldr r0, [r5]
    adds r0, r0, r4
    bl sub_08070324
    ldrh r1, [r6, #6]
    movs r0, #5
    movs r2, #0xb
    movs r3, #0
    bl draw_status_screen_single_tank_amount
    ldrh r1, [r6]
    movs r0, #6
    movs r2, #0xb
    movs r3, #1
    bl draw_status_screen_single_tank_amount
    b lbl_08070314
    .align 2, 0
lbl_080701e0: .4byte gEquipment
lbl_080701e4: .4byte sEwramPointer
lbl_080701e8: .4byte sNonGameplayRamPointer
lbl_080701ec:
    ldr r5, lbl_0807031c @ =sEwramPointer
    ldr r2, [r5]
    movs r0, #0xf0
    lsls r0, r0, #7
    adds r1, r2, r0
    movs r4, #0xe0
    lsls r4, r4, #7
    adds r2, r2, r4
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
    add r1, sp, #4
    ldr r7, lbl_08070320 @ =sNonGameplayRamPointer
    ldr r2, [r7]
    adds r0, r2, #0
    adds r0, #0xc1
    ldrb r0, [r0]
    strb r0, [r1]
    adds r0, r2, #0
    adds r0, #0xc2
    ldrb r0, [r0]
    strb r0, [r1, #1]
    adds r0, r2, #0
    adds r0, #0xc3
    ldrb r0, [r0]
    strb r0, [r1, #2]
    adds r2, #0xc0
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x18
    bl BitFill
    ldr r0, [r5]
    adds r0, r0, r4
    bl sub_08070534
    ldr r0, [r5]
    adds r0, r0, r4
    bl sub_080706a4
    ldr r0, [r5]
    adds r0, r0, r4
    bl set_status_screen_bomb_visibilty
    ldr r0, [r5]
    adds r0, r0, r4
    bl sub_08070810
    ldr r0, [r5]
    adds r0, r0, r4
    bl sub_08070c2c
    ldrh r1, [r6, #6]
    movs r0, #5
    movs r2, #0xb
    movs r3, #0
    bl draw_status_screen_single_tank_amount
    ldrh r1, [r6]
    movs r0, #6
    movs r2, #0xb
    movs r3, #1
    bl draw_status_screen_single_tank_amount
    ldrh r0, [r6, #2]
    cmp r0, #0
    beq lbl_08070296
    ldrh r1, [r6, #8]
    movs r0, #7
    movs r2, #0xb
    movs r3, #0
    bl draw_status_screen_single_tank_amount
    ldrh r1, [r6, #2]
    movs r0, #8
    movs r2, #0xb
    movs r3, #1
    bl draw_status_screen_single_tank_amount
lbl_08070296:
    ldrb r0, [r6, #4]
    cmp r0, #0
    beq lbl_080702b4
    ldrb r1, [r6, #0xa]
    movs r0, #9
    movs r2, #0xb
    movs r3, #0
    bl draw_status_screen_single_tank_amount
    ldrb r1, [r6, #4]
    movs r0, #0xa
    movs r2, #0xb
    movs r3, #1
    bl draw_status_screen_single_tank_amount
lbl_080702b4:
    ldrb r0, [r6, #5]
    cmp r0, #0
    beq lbl_080702d2
    ldrb r1, [r6, #0xb]
    movs r0, #0xb
    movs r2, #0xb
    movs r3, #0
    bl draw_status_screen_single_tank_amount
    ldrb r1, [r6, #5]
    movs r0, #0xc
    movs r2, #0xb
    movs r3, #1
    bl draw_status_screen_single_tank_amount
lbl_080702d2:
    add r0, sp, #4
    ldrb r0, [r0]
    bl sub_08071a8c
    cmp r0, #0
    beq lbl_080702e8
    ldr r0, [r7]
    add r1, sp, #4
    ldrb r1, [r1]
    adds r0, #0xc1
    strb r1, [r0]
lbl_080702e8:
    add r0, sp, #4
    ldrb r0, [r0, #1]
    bl sub_08071a8c
    cmp r0, #0
    beq lbl_080702fe
    ldr r0, [r7]
    add r1, sp, #4
    ldrb r1, [r1, #1]
    adds r0, #0xc2
    strb r1, [r0]
lbl_080702fe:
    add r0, sp, #4
    ldrb r0, [r0, #2]
    bl sub_08071a8c
    cmp r0, #0
    beq lbl_08070314
    ldr r0, [r7]
    add r1, sp, #4
    ldrb r1, [r1, #2]
    adds r0, #0xc3
    strb r1, [r0]
lbl_08070314:
    add sp, #8
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807031c: .4byte sEwramPointer
lbl_08070320: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08070324
sub_08070324: @ 0x08070324
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    mov r8, r0
    movs r0, #0
    mov ip, r0
    ldr r5, lbl_08070404 @ =sNonGameplayRamPointer
    ldr r3, [r5]
    adds r3, #0xc4
    ldr r2, lbl_08070408 @ =0x0840de50
    ldrb r0, [r2]
    adds r0, #1
    lsls r0, r0, #5
    ldrb r4, [r2, #2]
    adds r7, r0, r4
    ldr r1, lbl_0807040c @ =0x0840de91
    ldrb r0, [r1]
    lsls r0, r0, #5
    ldrb r1, [r1, #2]
    adds r6, r0, r1
    ldr r0, lbl_08070410 @ =0x087601dc
    ldr r0, [r0]
    ldrb r0, [r0]
    strb r0, [r3]
    ldrb r0, [r2, #3]
    subs r1, r0, r4
    mov sb, r5
    cmp r1, #0
    blt lbl_0807037a
    lsls r0, r6, #1
    mov r2, r8
    adds r3, r0, r2
    lsls r0, r7, #1
    adds r2, r0, r2
    adds r1, #1
lbl_0807036c:
    ldrh r0, [r3]
    strh r0, [r2]
    adds r3, #2
    adds r2, #2
    subs r1, #1
    cmp r1, #0
    bne lbl_0807036c
lbl_0807037a:
    mov r5, sb
    ldr r0, [r5]
    ldrh r0, [r0]
    lsrs r0, r0, #9
    movs r6, #1
    mov r4, ip
    adds r4, #1
    lsls r1, r4, #0x18
    lsrs r1, r1, #0x18
    adds r2, r6, #0
    bics r2, r0
    movs r0, #0
    movs r3, #0
    bl sub_08070e1c
    mov ip, r4
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0xc0
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_080703aa
    movs r0, #0x80
    strb r0, [r1]
lbl_080703aa:
    mov r3, sb
    ldr r0, [r3]
    adds r5, r0, #0
    adds r5, #0xc1
    ldrb r0, [r5]
    cmp r0, #0
    bne lbl_080703ba
    strb r6, [r5]
lbl_080703ba:
    ldr r2, lbl_08070408 @ =0x0840de50
    mov r0, ip
    adds r0, #1
    ldrb r4, [r2]
    adds r0, r0, r4
    lsls r0, r0, #5
    ldrb r3, [r2, #2]
    adds r7, r0, r3
    ldr r1, lbl_0807040c @ =0x0840de91
    ldrb r0, [r1]
    adds r0, #1
    lsls r0, r0, #5
    ldrb r1, [r1, #2]
    adds r6, r0, r1
    ldrb r0, [r2, #3]
    subs r1, r0, r3
    cmp r1, #0
    blt lbl_080703f8
    lsls r0, r6, #1
    mov r3, r8
    adds r2, r0, r3
    lsls r0, r7, #1
    adds r4, r0, r3
    adds r1, #1
lbl_080703ea:
    ldrh r0, [r2]
    strh r0, [r4]
    adds r2, #2
    adds r4, #2
    subs r1, #1
    cmp r1, #0
    bne lbl_080703ea
lbl_080703f8:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070404: .4byte sNonGameplayRamPointer
lbl_08070408: .4byte 0x0840de50
lbl_0807040c: .4byte 0x0840de91
lbl_08070410: .4byte 0x087601dc

    thumb_func_start draw_status_screen_single_tank_amount
draw_status_screen_single_tank_amount: @ 0x08070414
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    adds r4, r0, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    str r1, [sp]
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    mov sb, r2
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    str r3, [sp, #4]
    subs r0, r4, #5
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r1, lbl_080704c0 @ =0x0000b08c
    str r1, [sp, #8]
    cmp r0, #1
    bhi lbl_0807044a
    ldr r2, lbl_080704c4 @ =0x0000b2e0
    str r2, [sp, #8]
lbl_0807044a:
    ldr r0, lbl_080704c8 @ =sEwramPointer
    ldr r0, [r0]
    movs r3, #0xe0
    lsls r3, r3, #7
    adds r7, r0, r3
    ldr r3, lbl_080704cc @ =0x0840de50
    lsls r2, r4, #2
    adds r2, r2, r4
    adds r0, r2, r3
    ldrb r1, [r0]
    lsls r1, r1, #5
    adds r0, r3, #2
    adds r0, r2, r0
    ldrb r4, [r0]
    adds r1, r1, r4
    lsls r1, r1, #1
    adds r7, r7, r1
    adds r3, #3
    adds r2, r2, r3
    ldrb r0, [r2]
    subs r6, r0, r4
    ldr r1, lbl_080704d0 @ =0x0840d102
    lsls r0, r6, #1
    adds r0, r0, r1
    ldrh r4, [r0]
    adds r6, #1
    movs r0, #0
    mov r8, r0
    movs r5, #0
    cmp r4, #0
    ble lbl_08070502
    ldr r2, lbl_080704d4 @ =0x00000fff
    adds r1, r2, #0
    ldr r0, [sp, #8]
    ands r0, r1
    lsls r0, r0, #0x10
    mov sl, r0
lbl_08070494:
    ldr r0, [sp]
    adds r1, r4, #0
    bl __divsi3
    movs r1, #0xa
    bl __modsi3
    adds r2, r0, #0
    cmp r2, #0
    bne lbl_080704d8
    movs r2, #0x80
    cmp r4, #1
    beq lbl_080704de
    mov r3, r8
    cmp r3, #0
    bne lbl_080704de
    ldr r0, [sp, #4]
    cmp r0, #0
    bne lbl_080704f0
    mov r1, sl
    lsrs r2, r1, #0x10
    b lbl_080704de
    .align 2, 0
lbl_080704c0: .4byte 0x0000b08c
lbl_080704c4: .4byte 0x0000b2e0
lbl_080704c8: .4byte sEwramPointer
lbl_080704cc: .4byte 0x0840de50
lbl_080704d0: .4byte 0x0840d102
lbl_080704d4: .4byte 0x00000fff
lbl_080704d8:
    movs r3, #1
    mov r8, r3
    adds r2, #0x80
lbl_080704de:
    cmp r2, #0
    beq lbl_080704f0
    lsls r1, r5, #1
    adds r1, r1, r7
    mov r3, sb
    lsls r0, r3, #0xc
    orrs r0, r2
    strh r0, [r1]
    b lbl_080704f2
lbl_080704f0:
    subs r5, #1
lbl_080704f2:
    adds r0, r4, #0
    movs r1, #0xa
    bl __divsi3
    adds r4, r0, #0
    adds r5, #1
    cmp r4, #0
    bgt lbl_08070494
lbl_08070502:
    cmp r6, r5
    beq lbl_08070520
    ldr r1, lbl_08070530 @ =0x00000fff
    ldr r0, [sp, #8]
    ands r1, r0
    mov r2, sb
    lsls r0, r2, #0xc
    orrs r1, r0
    lsls r0, r5, #1
    adds r0, r0, r7
lbl_08070516:
    strh r1, [r0]
    adds r0, #2
    adds r5, #1
    cmp r6, r5
    bne lbl_08070516
lbl_08070520:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070530: .4byte 0x00000fff

    thumb_func_start sub_08070534
sub_08070534: @ 0x08070534
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    mov sl, r0
    ldr r0, lbl_08070684 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xc4
    mov sb, r0
    movs r4, #0
    ldr r0, lbl_08070688 @ =0x0840d0fe
    ldrb r1, [r0]
    adds r3, r0, #0
    cmp r1, #0
    beq lbl_08070562
    movs r2, #0
lbl_08070556:
    mov r5, sb
    adds r0, r5, r4
    strb r2, [r0]
    adds r4, #1
    cmp r4, r1
    blt lbl_08070556
lbl_08070562:
    movs r4, #0
    mov ip, r4
    ldrb r3, [r3]
    cmp ip, r3
    bge lbl_08070612
lbl_0807056c:
    adds r3, r4, #0
    movs r7, #0
    ldr r0, lbl_0807068c @ =0x087601dc
    ldr r0, [r0]
    adds r0, r0, r3
    ldrb r0, [r0]
    ldr r5, lbl_08070690 @ =gEquipment
    cmp r0, #8
    bne lbl_08070594
    ldrb r0, [r5, #0x12]
    cmp r0, #1
    bne lbl_08070590
    ldr r0, lbl_08070694 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #8
    bne lbl_08070594
lbl_08070590:
    movs r3, #9
    movs r7, #0xa
lbl_08070594:
    ldr r1, lbl_08070698 @ =0x0840de91
    ldrb r0, [r1]
    adds r0, r0, r3
    lsls r0, r0, #5
    ldrb r1, [r1, #2]
    adds r0, r0, r1
    adds r7, r7, r0
    ldr r3, lbl_0807069c @ =0x0840de50
    ldrb r0, [r3]
    adds r0, #1
    add r0, ip
    lsls r0, r0, #5
    ldrb r2, [r3, #2]
    adds r6, r0, r2
    ldr r1, lbl_0807068c @ =0x087601dc
    ldr r0, [r1]
    adds r0, r0, r4
    ldrb r1, [r5, #0xc]
    ldrb r0, [r0]
    ands r1, r0
    adds r4, #1
    mov r8, r4
    cmp r1, #0
    beq lbl_08070608
    mov r1, sb
    add r1, ip
    strb r0, [r1]
    ldrb r0, [r3, #3]
    subs r3, r0, r2
    adds r5, r1, #0
    mov r4, ip
    adds r4, #1
    cmp r3, #0
    blt lbl_080705f2
    lsls r0, r7, #1
    mov r1, sl
    adds r2, r0, r1
    lsls r0, r6, #1
    adds r1, r0, r1
    adds r3, #1
lbl_080705e4:
    ldrh r0, [r2]
    strh r0, [r1]
    adds r2, #2
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_080705e4
lbl_080705f2:
    lsls r1, r4, #0x18
    lsrs r1, r1, #0x18
    ldr r2, lbl_080706a0 @ =gEquipment+0xD
    ldrb r0, [r2]
    ldrb r2, [r5]
    ands r2, r0
    movs r0, #0
    movs r3, #0
    bl sub_08070e1c
    mov ip, r4
lbl_08070608:
    mov r4, r8
    ldr r0, lbl_08070688 @ =0x0840d0fe
    ldrb r0, [r0]
    cmp r4, r0
    blt lbl_0807056c
lbl_08070612:
    mov r4, ip
    cmp r4, #0
    beq lbl_08070676
    ldr r2, lbl_08070684 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc0
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807062a
    movs r0, #0x80
    strb r0, [r1]
lbl_0807062a:
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807063a
    movs r0, #1
    strb r0, [r1]
lbl_0807063a:
    ldr r2, lbl_0807069c @ =0x0840de50
    mov r0, ip
    adds r0, #1
    ldrb r5, [r2]
    adds r0, r0, r5
    lsls r0, r0, #5
    ldrb r3, [r2, #2]
    adds r6, r0, r3
    ldr r1, lbl_08070698 @ =0x0840de91
    ldrb r0, [r1, #1]
    lsls r0, r0, #5
    ldrb r1, [r1, #2]
    adds r7, r0, r1
    ldrb r0, [r2, #3]
    subs r3, r0, r3
    cmp r3, #0
    blt lbl_08070676
    lsls r0, r7, #1
    mov r1, sl
    adds r2, r0, r1
    lsls r0, r6, #1
    adds r1, r0, r1
    adds r3, #1
lbl_08070668:
    ldrh r0, [r2]
    strh r0, [r1]
    adds r2, #2
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_08070668
lbl_08070676:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070684: .4byte sNonGameplayRamPointer
lbl_08070688: .4byte 0x0840d0fe
lbl_0807068c: .4byte 0x087601dc
lbl_08070690: .4byte gEquipment
lbl_08070694: .4byte gPauseScreenFlag
lbl_08070698: .4byte 0x0840de91
lbl_0807069c: .4byte 0x0840de50
lbl_080706a0: .4byte gEquipment+0xD

    thumb_func_start sub_080706a4
sub_080706a4: @ 0x080706a4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    mov sl, r0
    ldr r0, lbl_080707f0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xc9
    mov sb, r0
    movs r4, #0
    ldr r0, lbl_080707f4 @ =0x0840d0fe
    ldrb r1, [r0, #2]
    adds r3, r0, #0
    cmp r1, #0
    beq lbl_080706d2
    movs r2, #0
lbl_080706c6:
    mov r5, sb
    adds r0, r5, r4
    strb r2, [r0]
    adds r4, #1
    cmp r4, r1
    blt lbl_080706c6
lbl_080706d2:
    movs r4, #0
    mov ip, r4
    ldrb r3, [r3, #2]
    cmp ip, r3
    bge lbl_0807077c
lbl_080706dc:
    adds r3, r4, #0
    ldr r0, lbl_080707f8 @ =0x087601dc
    ldr r0, [r0, #8]
    adds r0, r0, r3
    ldrb r0, [r0]
    ldr r5, lbl_080707fc @ =gEquipment
    cmp r0, #0x20
    bne lbl_08070700
    ldrb r0, [r5, #0x12]
    cmp r0, #1
    bne lbl_080706fe
    ldr r0, lbl_08070800 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #8
    bne lbl_08070700
lbl_080706fe:
    movs r3, #3
lbl_08070700:
    ldr r1, lbl_08070804 @ =0x0840de91
    ldrb r0, [r1, #0xa]
    adds r0, r0, r3
    lsls r0, r0, #5
    ldrb r1, [r1, #0xc]
    adds r6, r0, r1
    ldr r3, lbl_08070808 @ =0x0840de50
    ldrb r0, [r3, #0xa]
    adds r0, #1
    add r0, ip
    lsls r0, r0, #5
    ldrb r2, [r3, #0xc]
    adds r7, r0, r2
    ldr r1, lbl_080707f8 @ =0x087601dc
    ldr r0, [r1, #8]
    adds r0, r0, r4
    ldrb r1, [r5, #0xe]
    ldrb r0, [r0]
    ands r1, r0
    adds r4, #1
    mov r8, r4
    cmp r1, #0
    beq lbl_08070772
    mov r1, sb
    add r1, ip
    strb r0, [r1]
    ldrb r0, [r3, #0xd]
    subs r3, r0, r2
    adds r5, r1, #0
    mov r4, ip
    adds r4, #1
    cmp r3, #0
    blt lbl_0807075c
    lsls r0, r6, #1
    mov r6, sl
    adds r2, r0, r6
    lsls r0, r7, #1
    adds r1, r0, r6
    adds r3, #1
lbl_0807074e:
    ldrh r0, [r2]
    strh r0, [r1]
    adds r2, #2
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_0807074e
lbl_0807075c:
    lsls r1, r4, #0x18
    lsrs r1, r1, #0x18
    ldr r2, lbl_0807080c @ =gEquipment+0xF
    ldrb r0, [r2]
    ldrb r2, [r5]
    ands r2, r0
    movs r0, #2
    movs r3, #0
    bl sub_08070e1c
    mov ip, r4
lbl_08070772:
    mov r4, r8
    ldr r0, lbl_080707f4 @ =0x0840d0fe
    ldrb r0, [r0, #2]
    cmp r4, r0
    blt lbl_080706dc
lbl_0807077c:
    mov r4, ip
    cmp r4, #0
    beq lbl_080707e0
    ldr r2, lbl_080707f0 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc0
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08070794
    movs r0, #0x82
    strb r0, [r1]
lbl_08070794:
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_080707a4
    movs r0, #0xa
    strb r0, [r1]
lbl_080707a4:
    ldr r2, lbl_08070808 @ =0x0840de50
    mov r0, ip
    adds r0, #1
    ldrb r5, [r2, #0xa]
    adds r0, r0, r5
    lsls r0, r0, #5
    ldrb r3, [r2, #0xc]
    adds r7, r0, r3
    ldr r1, lbl_08070804 @ =0x0840de91
    ldrb r0, [r1, #0xb]
    lsls r0, r0, #5
    ldrb r1, [r1, #0xc]
    adds r6, r0, r1
    ldrb r0, [r2, #0xd]
    subs r3, r0, r3
    cmp r3, #0
    blt lbl_080707e0
    lsls r0, r6, #1
    mov r6, sl
    adds r2, r0, r6
    lsls r0, r7, #1
    adds r1, r0, r6
    adds r3, #1
lbl_080707d2:
    ldrh r0, [r2]
    strh r0, [r1]
    adds r2, #2
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_080707d2
lbl_080707e0:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080707f0: .4byte sNonGameplayRamPointer
lbl_080707f4: .4byte 0x0840d0fe
lbl_080707f8: .4byte 0x087601dc
lbl_080707fc: .4byte gEquipment
lbl_08070800: .4byte gPauseScreenFlag
lbl_08070804: .4byte 0x0840de91
lbl_08070808: .4byte 0x0840de50
lbl_0807080c: .4byte gEquipment+0xF

    thumb_func_start sub_08070810
sub_08070810: @ 0x08070810
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    mov sb, r0
    movs r3, #0
    ldr r0, lbl_080709a4 @ =0x0840d0fe
    ldrb r1, [r0, #3]
    adds r5, r0, #0
    cmp r3, r1
    bge lbl_0807083c
    ldr r4, lbl_080709a8 @ =sNonGameplayRamPointer
    movs r2, #0
lbl_0807082e:
    ldr r0, [r4]
    adds r0, #0xcb
    adds r0, r0, r3
    strb r2, [r0]
    adds r3, #1
    cmp r3, r1
    blt lbl_0807082e
lbl_0807083c:
    movs r3, #0
    mov ip, r3
    ldrb r5, [r5, #3]
    cmp ip, r5
    bge lbl_080708f4
lbl_08070846:
    adds r2, r3, #1
    ldr r0, lbl_080709ac @ =0x087601dc
    ldr r0, [r0, #0xc]
    adds r0, r0, r3
    ldrb r0, [r0]
    str r2, [sp]
    ldr r1, lbl_080709b0 @ =gEquipment
    mov sl, r1
    cmp r0, #4
    bne lbl_08070870
    ldrb r0, [r1, #0x12]
    cmp r0, #1
    bne lbl_0807086c
    ldr r0, lbl_080709b4 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #8
    bne lbl_08070870
lbl_0807086c:
    movs r2, #1
    rsbs r2, r2, #0
lbl_08070870:
    ldr r1, lbl_080709b8 @ =0x0840de91
    ldrb r0, [r1, #0xf]
    adds r0, r0, r2
    lsls r0, r0, #5
    ldrb r1, [r1, #0x11]
    adds r5, r0, r1
    ldr r2, lbl_080709bc @ =0x0840de50
    ldrb r0, [r2, #0xf]
    adds r0, #1
    add r0, ip
    lsls r0, r0, #5
    ldrb r4, [r2, #0x11]
    adds r7, r0, r4
    ldr r1, lbl_080709ac @ =0x087601dc
    ldr r0, [r1, #0xc]
    adds r0, r0, r3
    mov r3, sl
    ldrb r1, [r3, #0xe]
    ldrb r3, [r0]
    ands r1, r3
    cmp r1, #0
    beq lbl_080708ea
    ldr r0, lbl_080709a8 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r1, #0xcb
    add r1, ip
    strb r3, [r1]
    ldrb r1, [r2, #0x12]
    subs r2, r1, r4
    adds r6, r0, #0
    mov r4, ip
    adds r4, #1
    cmp r2, #0
    blt lbl_080708ce
    lsls r0, r5, #1
    mov r5, sb
    adds r1, r0, r5
    lsls r0, r7, #1
    adds r3, r0, r5
    adds r2, #1
lbl_080708c0:
    ldrh r0, [r1]
    strh r0, [r3]
    adds r1, #2
    adds r3, #2
    subs r2, #1
    cmp r2, #0
    bne lbl_080708c0
lbl_080708ce:
    lsls r1, r4, #0x18
    lsrs r1, r1, #0x18
    ldr r0, [r6]
    adds r0, #0xcb
    add r0, ip
    mov r2, sl
    ldrb r3, [r2, #0xf]
    ldrb r2, [r0]
    ands r2, r3
    movs r0, #3
    movs r3, #0
    bl sub_08070e1c
    mov ip, r4
lbl_080708ea:
    ldr r3, [sp]
    ldr r0, lbl_080709a4 @ =0x0840d0fe
    ldrb r0, [r0, #3]
    cmp r3, r0
    blt lbl_08070846
lbl_080708f4:
    mov r3, ip
    cmp r3, #0
    beq lbl_08070994
    ldr r2, lbl_080709a8 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc0
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807090c
    movs r0, #0x83
    strb r0, [r1]
lbl_0807090c:
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807091c
    movs r0, #0xc
    strb r0, [r1]
lbl_0807091c:
    ldr r2, lbl_080709bc @ =0x0840de50
    ldrb r0, [r2, #0xf]
    lsls r0, r0, #5
    ldrb r3, [r2, #0x11]
    adds r7, r0, r3
    ldr r1, lbl_080709b8 @ =0x0840de91
    ldrb r0, [r1, #0xf]
    lsls r0, r0, #5
    ldrb r4, [r1, #0x11]
    adds r5, r0, r4
    ldrb r0, [r2, #0x12]
    subs r6, r0, r3
    mov sl, r1
    mov r8, r2
    mov r4, ip
    adds r4, #1
    cmp r6, #0
    blt lbl_0807095a
    lsls r0, r5, #1
    mov r5, sb
    adds r3, r0, r5
    lsls r0, r7, #1
    adds r1, r0, r5
    adds r2, r6, #1
lbl_0807094c:
    ldrh r0, [r3]
    strh r0, [r1]
    adds r3, #2
    adds r1, #2
    subs r2, #1
    cmp r2, #0
    bne lbl_0807094c
lbl_0807095a:
    mov r1, r8
    ldrb r0, [r1, #0xf]
    adds r0, r0, r4
    lsls r0, r0, #5
    ldrb r1, [r1, #0x11]
    adds r7, r0, r1
    mov r2, sl
    ldrb r0, [r2, #0x10]
    lsls r0, r0, #5
    ldrb r3, [r2, #0x11]
    adds r5, r0, r3
    mov r4, r8
    ldrb r0, [r4, #0x12]
    subs r2, r0, r1
    cmp r2, #0
    blt lbl_08070994
    lsls r0, r5, #1
    mov r5, sb
    adds r3, r0, r5
    lsls r0, r7, #1
    adds r1, r0, r5
    adds r2, #1
lbl_08070986:
    ldrh r0, [r3]
    strh r0, [r1]
    adds r3, #2
    adds r1, #2
    subs r2, #1
    cmp r2, #0
    bne lbl_08070986
lbl_08070994:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080709a4: .4byte 0x0840d0fe
lbl_080709a8: .4byte sNonGameplayRamPointer
lbl_080709ac: .4byte 0x087601dc
lbl_080709b0: .4byte gEquipment
lbl_080709b4: .4byte gPauseScreenFlag
lbl_080709b8: .4byte 0x0840de91
lbl_080709bc: .4byte 0x0840de50

    thumb_func_start set_status_screen_bomb_visibilty
set_status_screen_bomb_visibilty: @ 0x080709c0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    str r0, [sp]
    str r0, [sp, #4]
    ldr r2, lbl_08070ae8 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0xd1
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0xd2
    strb r1, [r0]
    movs r7, #0
    ldr r3, lbl_08070aec @ =gEquipment
    ldr r0, lbl_08070af0 @ =0x087601dc
    ldr r0, [r0, #4]
    ldrb r1, [r3, #0xc]
    ldrb r0, [r0]
    ands r0, r1
    mov ip, r2
    cmp r0, #0
    beq lbl_08070a02
    movs r7, #2
    ldr r0, [r2]
    adds r0, #0xd1
    ldrb r1, [r0]
    movs r2, #1
    orrs r1, r2
    strb r1, [r0]
lbl_08070a02:
    cmp r7, #0
    bne lbl_08070a08
    b lbl_08070bfe
lbl_08070a08:
    ldrb r0, [r3, #5]
    cmp r0, #0
    beq lbl_08070a1e
    movs r7, #3
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0xd2
    ldrb r1, [r0]
    movs r2, #1
    orrs r1, r2
    strb r1, [r0]
lbl_08070a1e:
    movs r6, #0
    cmp r6, r7
    blt lbl_08070a26
    b lbl_08070ba6
lbl_08070a26:
    ldr r2, lbl_08070af4 @ =0x0840de50
    mov r8, r2
    ldrb r3, [r2, #7]
    mov sl, r3
    ldrb r0, [r2, #8]
    subs r3, r0, r3
    str r3, [sp, #0xc]
    ldr r4, lbl_08070af8 @ =0x0840de91
    ldrb r4, [r4, #7]
    str r4, [sp, #8]
lbl_08070a3a:
    mov r1, r8
    ldrb r0, [r1, #5]
    adds r0, r0, r6
    lsls r0, r0, #5
    mov r2, sl
    adds r5, r0, r2
    ldr r3, lbl_08070af8 @ =0x0840de91
    ldrb r1, [r3, #5]
    ldr r0, lbl_08070afc @ =0x087603ea
    adds r0, r6, r0
    ldrb r0, [r0]
    adds r1, r1, r0
    lsls r3, r1, #5
    ldr r4, [sp, #8]
    adds r3, r3, r4
    adds r0, r6, #1
    mov sb, r0
    ldr r1, [sp, #0xc]
    cmp r1, #0
    blt lbl_08070a86
    mov r2, r8
    ldrb r1, [r2, #8]
    ldrb r0, [r2, #7]
    subs r1, r1, r0
    lsls r0, r3, #1
    ldr r3, [sp, #4]
    adds r4, r0, r3
    lsls r0, r5, #1
    ldr r2, [sp]
    adds r3, r0, r2
    adds r2, r1, #1
lbl_08070a78:
    ldrh r0, [r4]
    strh r0, [r3]
    adds r4, #2
    adds r3, #2
    subs r2, #1
    cmp r2, #0
    bne lbl_08070a78
lbl_08070a86:
    movs r2, #0
    cmp r6, #1
    bne lbl_08070b00
    ldr r0, lbl_08070ae8 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0xd1
    ldrb r2, [r3]
    adds r1, r6, #0
    ands r1, r2
    mov ip, r0
    cmp r1, #0
    beq lbl_08070ade
    ldr r4, lbl_08070aec @ =gEquipment
    ldr r0, lbl_08070af0 @ =0x087601dc
    ldr r0, [r0, #4]
    ldrb r1, [r4, #0xd]
    ldrb r0, [r0]
    ands r0, r1
    cmp r0, #0
    beq lbl_08070ab6
    movs r0, #2
    orrs r0, r2
    strb r0, [r3]
lbl_08070ab6:
    mov r3, ip
    ldr r1, [r3]
    adds r1, #0xd1
    ldrb r2, [r1]
    movs r0, #4
    movs r3, #0
    orrs r0, r2
    strb r0, [r1]
    ldrb r1, [r4, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08070ade
    mov r4, ip
    ldr r0, [r4]
    adds r0, #0xd1
    ldrb r1, [r0]
    movs r2, #8
    orrs r1, r2
    strb r1, [r0]
lbl_08070ade:
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0xd1
    b lbl_08070b60
    .align 2, 0
lbl_08070ae8: .4byte sNonGameplayRamPointer
lbl_08070aec: .4byte gEquipment
lbl_08070af0: .4byte 0x087601dc
lbl_08070af4: .4byte 0x0840de50
lbl_08070af8: .4byte 0x0840de91
lbl_08070afc: .4byte 0x087603ea
lbl_08070b00:
    cmp r6, #2
    bne lbl_08070b62
    ldr r0, lbl_08070c10 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0xd2
    ldrb r2, [r3]
    movs r1, #1
    ands r1, r2
    mov ip, r0
    cmp r1, #0
    beq lbl_08070b5a
    ldr r4, lbl_08070c14 @ =gEquipment
    ldr r0, lbl_08070c18 @ =0x087601dc
    ldr r0, [r0, #4]
    ldrb r1, [r4, #0xd]
    ldrb r0, [r0]
    ands r0, r1
    cmp r0, #0
    beq lbl_08070b2e
    movs r0, #2
    orrs r0, r2
    strb r0, [r3]
lbl_08070b2e:
    ldrb r0, [r4, #0xb]
    cmp r0, #0
    beq lbl_08070b42
    mov r2, ip
    ldr r0, [r2]
    adds r0, #0xd2
    ldrb r2, [r0]
    movs r1, #4
    orrs r1, r2
    strb r1, [r0]
lbl_08070b42:
    ldrb r1, [r4, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08070b5a
    mov r3, ip
    ldr r0, [r3]
    adds r0, #0xd2
    ldrb r2, [r0]
    movs r1, #8
    orrs r1, r2
    strb r1, [r0]
lbl_08070b5a:
    mov r4, ip
    ldr r0, [r4]
    adds r0, #0xd2
lbl_08070b60:
    ldrb r2, [r0]
lbl_08070b62:
    cmp r2, #0
    beq lbl_08070b9e
    movs r0, #0
    cmp r2, #0xf
    bne lbl_08070b6e
    movs r0, #1
lbl_08070b6e:
    adds r2, r0, #0
    ldr r0, lbl_08070c1c @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #6
    bne lbl_08070b8e
    ldr r0, lbl_08070c20 @ =gCurrentItemBeingAcquired
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #7
    bne lbl_08070b8e
    cmp r6, #2
    bne lbl_08070b8e
    movs r2, #0
lbl_08070b8e:
    lsls r1, r6, #0x18
    lsrs r1, r1, #0x18
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r0, #1
    movs r3, #0
    bl sub_08070e1c
lbl_08070b9e:
    mov r6, sb
    cmp r6, r7
    bge lbl_08070ba6
    b lbl_08070a3a
lbl_08070ba6:
    ldr r2, lbl_08070c24 @ =0x0840de50
    ldrb r0, [r2, #5]
    adds r0, r0, r7
    lsls r0, r0, #5
    ldrb r4, [r2, #7]
    adds r5, r0, r4
    cmp r7, #2
    beq lbl_08070bb8
    adds r7, #1
lbl_08070bb8:
    ldr r0, lbl_08070c28 @ =0x0840de91
    ldrb r1, [r0, #5]
    adds r1, r1, r7
    lsls r1, r1, #5
    ldrb r0, [r0, #7]
    adds r3, r1, r0
    ldrb r0, [r2, #8]
    subs r2, r0, r4
    ldr r0, lbl_08070c10 @ =sNonGameplayRamPointer
    mov ip, r0
    cmp r2, #0
    blt lbl_08070bec
    lsls r0, r3, #1
    ldr r3, [sp, #4]
    adds r1, r0, r3
    lsls r0, r5, #1
    ldr r4, [sp]
    adds r3, r0, r4
    adds r2, #1
lbl_08070bde:
    ldrh r0, [r1]
    strh r0, [r3]
    adds r1, #2
    adds r3, #2
    subs r2, #1
    cmp r2, #0
    bne lbl_08070bde
lbl_08070bec:
    mov r1, ip
    ldr r0, [r1]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08070bfe
    movs r0, #8
    strb r0, [r1]
lbl_08070bfe:
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070c10: .4byte sNonGameplayRamPointer
lbl_08070c14: .4byte gEquipment
lbl_08070c18: .4byte 0x087601dc
lbl_08070c1c: .4byte gPauseScreenFlag
lbl_08070c20: .4byte gCurrentItemBeingAcquired
lbl_08070c24: .4byte 0x0840de50
lbl_08070c28: .4byte 0x0840de91

    thumb_func_start sub_08070c2c
sub_08070c2c: @ 0x08070c2c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    mov r8, r0
    movs r0, #0
    mov sl, r0
    ldr r3, lbl_08070d08 @ =gEquipment
    ldrh r0, [r3, #2]
    cmp r0, #0
    beq lbl_08070c58
    movs r1, #3
    mov sl, r1
    ldr r0, lbl_08070d0c @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r1, #0xd3
    ldrb r2, [r1]
    movs r0, #1
    orrs r0, r2
    strb r0, [r1]
lbl_08070c58:
    ldrb r0, [r3, #4]
    cmp r0, #0
    beq lbl_08070c7a
    movs r3, #5
    mov sl, r3
    ldr r3, lbl_08070d0c @ =sNonGameplayRamPointer
    ldr r0, [r3]
    adds r0, #0xd4
    ldrb r1, [r0]
    movs r2, #1
    orrs r1, r2
    strb r1, [r0]
    ldr r0, [r3]
    adds r0, #0xd3
    ldrb r1, [r0]
    orrs r2, r1
    strb r2, [r0]
lbl_08070c7a:
    mov r4, sl
    cmp r4, #0
    bne lbl_08070c82
    b lbl_08070e00
lbl_08070c82:
    movs r5, #0
    cmp r5, sl
    blt lbl_08070c8a
    b lbl_08070db2
lbl_08070c8a:
    ldr r7, lbl_08070d10 @ =0x0840de50
    ldrb r0, [r7, #0x16]
    str r0, [sp]
    ldrb r0, [r7, #0x17]
    ldr r1, [sp]
    subs r0, r0, r1
    str r0, [sp, #4]
lbl_08070c98:
    ldrb r0, [r7, #0x14]
    adds r0, r0, r5
    lsls r0, r0, #5
    ldr r3, [sp]
    adds r6, r0, r3
    ldr r1, lbl_08070d14 @ =0x0840de91
    ldrb r0, [r1, #0x14]
    adds r0, r0, r5
    lsls r0, r0, #5
    ldrb r1, [r1, #0x16]
    adds r4, r0, r1
    adds r0, r5, #1
    mov sb, r0
    ldr r1, [sp, #4]
    cmp r1, #0
    blt lbl_08070cd8
    ldrb r1, [r7, #0x17]
    ldrb r0, [r7, #0x16]
    subs r1, r1, r0
    lsls r0, r4, #1
    mov r3, r8
    adds r2, r0, r3
    lsls r0, r6, #1
    adds r3, r0, r3
    adds r4, r1, #1
lbl_08070cca:
    ldrh r0, [r2]
    strh r0, [r3]
    adds r2, #2
    adds r3, #2
    subs r4, #1
    cmp r4, #0
    bne lbl_08070cca
lbl_08070cd8:
    movs r4, #0
    cmp r5, #1
    bne lbl_08070d18
    ldr r0, lbl_08070d0c @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0xd3
    ldrb r2, [r3]
    adds r1, r5, #0
    ands r1, r2
    mov ip, r0
    cmp r1, #0
    beq lbl_08070d00
    ldr r0, lbl_08070d08 @ =gEquipment
    ldrh r0, [r0, #8]
    cmp r0, #0
    beq lbl_08070d00
    movs r0, #2
    orrs r0, r2
    strb r0, [r3]
lbl_08070d00:
    mov r4, ip
    ldr r0, [r4]
    adds r0, #0xd3
    b lbl_08070d44
    .align 2, 0
lbl_08070d08: .4byte gEquipment
lbl_08070d0c: .4byte sNonGameplayRamPointer
lbl_08070d10: .4byte 0x0840de50
lbl_08070d14: .4byte 0x0840de91
lbl_08070d18:
    cmp r5, #3
    bne lbl_08070d46
    ldr r0, lbl_08070d84 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0xd4
    ldrb r2, [r3]
    movs r1, #1
    ands r1, r2
    mov ip, r0
    cmp r1, #0
    beq lbl_08070d3e
    ldr r0, lbl_08070d88 @ =gEquipment
    ldrb r0, [r0, #0xa]
    cmp r0, #0
    beq lbl_08070d3e
    movs r0, #2
    orrs r0, r2
    strb r0, [r3]
lbl_08070d3e:
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0xd4
lbl_08070d44:
    ldrb r4, [r0]
lbl_08070d46:
    cmp r4, #0
    beq lbl_08070daa
    movs r0, #0
    cmp r4, #3
    bne lbl_08070d52
    movs r0, #1
lbl_08070d52:
    adds r4, r0, #0
    ldr r0, lbl_08070d8c @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #6
    bne lbl_08070d94
    cmp r5, #1
    bne lbl_08070d70
    ldr r0, lbl_08070d90 @ =gCurrentItemBeingAcquired
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #3
    beq lbl_08070d98
lbl_08070d70:
    cmp r5, #3
    bne lbl_08070d9a
    ldr r0, lbl_08070d90 @ =gCurrentItemBeingAcquired
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #5
    bne lbl_08070d9a
    b lbl_08070d98
    .align 2, 0
lbl_08070d84: .4byte sNonGameplayRamPointer
lbl_08070d88: .4byte gEquipment
lbl_08070d8c: .4byte gPauseScreenFlag
lbl_08070d90: .4byte gCurrentItemBeingAcquired
lbl_08070d94:
    cmp r0, #8
    bne lbl_08070d9a
lbl_08070d98:
    movs r4, #0
lbl_08070d9a:
    lsls r1, r5, #0x18
    lsrs r1, r1, #0x18
    lsls r2, r4, #0x18
    lsrs r2, r2, #0x18
    movs r0, #4
    movs r3, #0
    bl sub_08070e1c
lbl_08070daa:
    mov r5, sb
    cmp r5, sl
    bge lbl_08070db2
    b lbl_08070c98
lbl_08070db2:
    ldr r2, lbl_08070e10 @ =0x0840de50
    ldrb r0, [r2, #0x14]
    add r0, sl
    lsls r0, r0, #5
    ldrb r3, [r2, #0x16]
    adds r6, r0, r3
    ldr r1, lbl_08070e14 @ =0x0840de91
    ldrb r0, [r1, #0x15]
    lsls r0, r0, #5
    ldrb r1, [r1, #0x16]
    adds r4, r0, r1
    ldrb r0, [r2, #0x17]
    subs r2, r0, r3
    ldr r3, lbl_08070e18 @ =sNonGameplayRamPointer
    mov ip, r3
    cmp r2, #0
    blt lbl_08070dee
    lsls r0, r4, #1
    mov r4, r8
    adds r1, r0, r4
    lsls r0, r6, #1
    adds r3, r0, r4
    adds r4, r2, #1
lbl_08070de0:
    ldrh r0, [r1]
    strh r0, [r3]
    adds r1, #2
    adds r3, #2
    subs r4, #1
    cmp r4, #0
    bne lbl_08070de0
lbl_08070dee:
    mov r1, ip
    ldr r0, [r1]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08070e00
    movs r0, #6
    strb r0, [r1]
lbl_08070e00:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070e10: .4byte 0x0840de50
lbl_08070e14: .4byte 0x0840de91
lbl_08070e18: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08070e1c
sub_08070e1c: @ 0x08070e1c
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r1, #0x18
    lsls r2, r2, #0x18
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    mov ip, r3
    ldr r4, lbl_08070eac @ =0x0840de50
    lsls r3, r0, #2
    adds r3, r3, r0
    adds r0, r3, r4
    lsrs r1, r1, #0x18
    ldrb r0, [r0]
    adds r1, r1, r0
    lsls r1, r1, #5
    adds r0, r4, #2
    adds r0, r3, r0
    ldrb r5, [r0]
    adds r1, r1, r5
    adds r4, #3
    adds r3, r3, r4
    ldrb r0, [r3]
    subs r4, r0, r5
    movs r0, #0xc0
    lsls r0, r0, #8
    cmp r2, #0
    beq lbl_08070e58
    movs r0, #0xb0
    lsls r0, r0, #8
lbl_08070e58:
    adds r5, r0, #0
    ldr r0, lbl_08070eb0 @ =sEwramPointer
    ldr r0, [r0]
    lsls r1, r1, #1
    adds r0, r1, r0
    ldr r3, lbl_08070eb4 @ =0x00007002
    adds r2, r0, r3
    adds r7, r1, #0
    cmp r4, #1
    ble lbl_08070e82
    ldr r6, lbl_08070eb8 @ =0x00000fff
    subs r3, r4, #1
lbl_08070e70:
    ldrh r1, [r2]
    adds r0, r6, #0
    ands r0, r1
    orrs r0, r5
    strh r0, [r2]
    subs r3, #1
    adds r2, #2
    cmp r3, #0
    bne lbl_08070e70
lbl_08070e82:
    mov r0, ip
    cmp r0, #0
    beq lbl_08070ea6
    ldr r3, lbl_08070ebc @ =0x0600c002
    adds r2, r7, r3
    cmp r4, #1
    ble lbl_08070ea6
    ldr r6, lbl_08070eb8 @ =0x00000fff
    subs r3, r4, #1
lbl_08070e94:
    ldrh r1, [r2]
    adds r0, r6, #0
    ands r0, r1
    orrs r0, r5
    strh r0, [r2]
    subs r3, #1
    adds r2, #2
    cmp r3, #0
    bne lbl_08070e94
lbl_08070ea6:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070eac: .4byte 0x0840de50
lbl_08070eb0: .4byte sEwramPointer
lbl_08070eb4: .4byte 0x00007002
lbl_08070eb8: .4byte 0x00000fff
lbl_08070ebc: .4byte 0x0600c002

    thumb_func_start sub_08070ec0
sub_08070ec0: @ 0x08070ec0
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r6, r1, #0x18
    cmp r4, #0
    beq lbl_08070eda
    cmp r4, #0
    blt lbl_08070ef8
    cmp r4, #3
    bgt lbl_08070ef8
    cmp r4, #2
    blt lbl_08070ef8
lbl_08070eda:
    ldr r2, lbl_08070ef4 @ =0x0840de91
    lsls r1, r4, #2
    adds r1, r1, r4
    adds r0, r2, #1
    adds r0, r1, r0
    ldrb r0, [r0]
    subs r0, #1
    adds r2, #2
    adds r1, r1, r2
    lsls r0, r0, #5
    ldrb r1, [r1]
    adds r5, r0, r1
    b lbl_08070efa
    .align 2, 0
lbl_08070ef4: .4byte 0x0840de91
lbl_08070ef8:
    movs r5, #0
lbl_08070efa:
    cmp r5, #0
    beq lbl_08070f46
    ldr r3, lbl_08070f4c @ =0x0840de50
    lsls r1, r4, #2
    adds r1, r1, r4
    adds r0, r1, r3
    ldrb r2, [r0]
    adds r2, r2, r6
    lsls r2, r2, #5
    adds r0, r3, #2
    adds r0, r1, r0
    ldrb r4, [r0]
    adds r2, r2, r4
    adds r3, #3
    adds r1, r1, r3
    ldrb r0, [r1]
    subs r1, r0, r4
    lsls r0, r2, #1
    ldr r2, lbl_08070f50 @ =0x0600c002
    adds r3, r0, r2
    adds r5, #1
    cmp r1, #1
    ble lbl_08070f46
    ldr r6, lbl_08070f54 @ =sEwramPointer
    movs r4, #0xe0
    lsls r4, r4, #7
    subs r2, r1, #1
lbl_08070f30:
    ldr r0, [r6]
    lsls r1, r5, #1
    adds r0, r0, r4
    adds r0, r0, r1
    ldrh r0, [r0]
    strh r0, [r3]
    subs r2, #1
    adds r3, #2
    adds r5, #1
    cmp r2, #0
    bne lbl_08070f30
lbl_08070f46:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070f4c: .4byte 0x0840de50
lbl_08070f50: .4byte 0x0600c002
lbl_08070f54: .4byte sEwramPointer

    thumb_func_start check_select_pressed_on_status_screen
check_select_pressed_on_status_screen: @ 0x08070f58
    ldr r1, lbl_08070f68 @ =gChangedInput
    ldrh r1, [r1]
    ands r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r0, r0, #0x1f
    bx lr
    .align 2, 0
lbl_08070f68: .4byte gChangedInput

    thumb_func_start StatusScreenInitCursorAndItems
StatusScreenInitCursorAndItems: @ 0x08070f6c
    push {r4, lr}
    ldr r4, lbl_08070fac @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08070fa6
    bl sub_08071a3c
    ldr r2, [r4]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_08070f9a
    movs r1, #0x84
    lsls r1, r1, #1
    adds r0, r2, r1
    movs r1, #6
    bl UpdateMenuOamDataID
lbl_08070f9a:
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r0, [r0]
    movs r1, #0
    bl sub_08071b2c
lbl_08070fa6:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070fac: .4byte sNonGameplayRamPointer

    thumb_func_start StatusScreenSuitlessItems
StatusScreenSuitlessItems: @ 0x08070fb0
    push {r4, r5, lr}
    movs r5, #0
    ldr r0, lbl_08070fdc @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrb r1, [r2, #8]
    adds r4, r0, #0
    cmp r1, #5
    bls lbl_08070fca
    ldr r0, lbl_08070fe0 @ =gUnk_3005804
    ldrh r1, [r0]
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r5, r0, #0x1f
lbl_08070fca:
    cmp r5, #0
    beq lbl_08070fd0
    b lbl_080711c8
lbl_08070fd0:
    ldrb r0, [r2, #0xc]
    cmp r0, #0
    beq lbl_08070fe4
    bl unk_68ec0
    b lbl_080711c8
    .align 2, 0
lbl_08070fdc: .4byte sNonGameplayRamPointer
lbl_08070fe0: .4byte gUnk_3005804
lbl_08070fe4:
    ldrb r0, [r2, #8]
    cmp r0, #7
    bls lbl_08070fec
    b lbl_080711c8
lbl_08070fec:
    lsls r0, r0, #2
    ldr r1, lbl_08070ff8 @ =lbl_08070ffc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08070ff8: .4byte lbl_08070ffc
lbl_08070ffc: @ jump table
    .4byte lbl_0807101c @ case 0
    .4byte lbl_08071098 @ case 1
    .4byte lbl_08071158 @ case 2
    .4byte lbl_0807117a @ case 3
    .4byte lbl_0807119a @ case 4
    .4byte lbl_080711a6 @ case 5
    .4byte lbl_080711c4 @ case 6
    .4byte lbl_080711c8 @ case 7
lbl_0807101c:
    ldr r2, [r4]
    ldrh r0, [r2, #0xa]
    cmp r0, #0x10
    bhi lbl_08071026
    b lbl_080711c8
lbl_08071026:
    adds r0, r2, #0
    adds r0, #0xc1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08071080
    movs r1, #0x84
    lsls r1, r1, #1
    adds r0, r2, r1
    movs r1, #6
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r0, [r0]
    movs r1, #2
    bl sub_08071b2c
    cmp r0, #0
    bge lbl_08071066
    ldr r0, lbl_0807105c @ =gDemoState
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08071060
    ldr r1, [r4]
    movs r0, #3
    b lbl_0807106a
    .align 2, 0
lbl_0807105c: .4byte gDemoState
lbl_08071060:
    ldr r1, [r4]
    movs r0, #5
    b lbl_0807106a
lbl_08071066:
    ldr r1, [r4]
    movs r0, #1
lbl_0807106a:
    strb r0, [r1, #8]
    ldr r1, lbl_08071078 @ =gCurrentMessage
    movs r0, #0
    strb r0, [r1, #0xe]
    ldr r4, lbl_0807107c @ =sNonGameplayRamPointer
    b lbl_0807108a
    .align 2, 0
lbl_08071078: .4byte gCurrentMessage
lbl_0807107c: .4byte sNonGameplayRamPointer
lbl_08071080:
    ldr r0, lbl_08071094 @ =gCurrentMessage
    movs r1, #1
    strb r1, [r0, #0xe]
    movs r0, #7
    strb r0, [r2, #8]
lbl_0807108a:
    ldr r1, [r4]
    movs r0, #0
    strh r0, [r1, #0xa]
    b lbl_080711c8
    .align 2, 0
lbl_08071094: .4byte gCurrentMessage
lbl_08071098:
    ldr r1, [r4]
    ldrh r0, [r1, #0xa]
    cmp r0, #8
    bhi lbl_080710a2
    b lbl_080711c8
lbl_080710a2:
    adds r0, r1, #0
    adds r0, #0xc1
    ldrb r0, [r0]
    movs r1, #1
    bl sub_08071b2c
    ldr r0, lbl_080710c8 @ =gCurrentItemBeingAcquired
    ldrb r0, [r0]
    subs r0, #3
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0x11
    bhi lbl_0807113e
    lsls r0, r0, #2
    ldr r1, lbl_080710cc @ =lbl_080710d0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080710c8: .4byte gCurrentItemBeingAcquired
lbl_080710cc: .4byte lbl_080710d0
lbl_080710d0: @ jump table
    .4byte lbl_08071124 @ case 0
    .4byte lbl_0807113e @ case 1
    .4byte lbl_08071124 @ case 2
    .4byte lbl_0807113e @ case 3
    .4byte lbl_08071124 @ case 4
    .4byte lbl_0807113e @ case 5
    .4byte lbl_0807113e @ case 6
    .4byte lbl_0807113e @ case 7
    .4byte lbl_0807113e @ case 8
    .4byte lbl_08071118 @ case 9
    .4byte lbl_0807113e @ case 10
    .4byte lbl_0807113e @ case 11
    .4byte lbl_08071118 @ case 12
    .4byte lbl_0807113e @ case 13
    .4byte lbl_0807113e @ case 14
    .4byte lbl_0807113e @ case 15
    .4byte lbl_0807113e @ case 16
    .4byte lbl_08071118 @ case 17
lbl_08071118:
    ldr r0, lbl_08071120 @ =0x0000020f
    bl SoundPlay
    b lbl_08071144
    .align 2, 0
lbl_08071120: .4byte 0x0000020f
lbl_08071124:
    ldr r2, lbl_0807114c @ =0x0840dec4
    ldr r0, lbl_08071150 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xc1
    ldrb r1, [r0]
    lsls r1, r1, #2
    adds r1, r1, r2
    ldrb r0, [r1]
    ldrb r1, [r1, #2]
    movs r2, #1
    movs r3, #1
    bl sub_08070e1c
lbl_0807113e:
    ldr r0, lbl_08071154 @ =0x000001f7
    bl SoundPlay
lbl_08071144:
    ldr r0, lbl_08071150 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    b lbl_08071184
    .align 2, 0
lbl_0807114c: .4byte 0x0840dec4
lbl_08071150: .4byte sNonGameplayRamPointer
lbl_08071154: .4byte 0x000001f7
lbl_08071158:
    ldr r1, [r4]
    ldrb r0, [r1, #0xc]
    cmp r0, #0
    bne lbl_080711c8
    strh r0, [r1, #0xa]
    ldr r0, lbl_08071170 @ =gDemoState
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08071174
    movs r0, #3
    strb r0, [r1, #8]
    b lbl_080711c8
    .align 2, 0
lbl_08071170: .4byte gDemoState
lbl_08071174:
    movs r0, #5
    strb r0, [r1, #8]
    b lbl_080711c8
lbl_0807117a:
    ldr r0, lbl_08071190 @ =gCurrentMessage
    ldrb r0, [r0, #0xe]
    cmp r0, #0
    beq lbl_08071194
    ldr r1, [r4]
lbl_08071184:
    movs r0, #0
    strh r0, [r1, #0xa]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    b lbl_080711c8
    .align 2, 0
lbl_08071190: .4byte gCurrentMessage
lbl_08071194:
    bl sub_0806f680
    b lbl_080711c8
lbl_0807119a:
    ldr r0, [r4]
    ldrh r0, [r0, #0xa]
    cmp r0, #0x1e
    bls lbl_080711c8
    movs r5, #1
    b lbl_080711c8
lbl_080711a6:
    bl sub_0806f680
    ldr r0, lbl_080711bc @ =gCurrentMessage
    ldrb r0, [r0, #0xe]
    cmp r0, #0
    beq lbl_080711c8
    ldr r0, lbl_080711c0 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #7
    strb r0, [r1, #8]
    b lbl_080711c8
    .align 2, 0
lbl_080711bc: .4byte gCurrentMessage
lbl_080711c0: .4byte sNonGameplayRamPointer
lbl_080711c4:
    bl sub_0806f680
lbl_080711c8:
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start sub_080711d0
sub_080711d0: @ 0x080711d0
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    ldr r3, lbl_080711e8 @ =sNonGameplayRamPointer
lbl_080711d8:
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xc1
    ldrb r0, [r2]
    cmp r0, #0x11
    bls lbl_080711ec
    movs r0, #2
    b lbl_0807128a
    .align 2, 0
lbl_080711e8: .4byte sNonGameplayRamPointer
lbl_080711ec:
    ldr r1, lbl_08071208 @ =0x0840dec4
    ldrb r0, [r2]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r0, [r0]
    adds r4, r1, #0
    cmp r0, #4
    bhi lbl_08071256
    lsls r0, r0, #2
    ldr r1, lbl_0807120c @ =lbl_08071210
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08071208: .4byte 0x0840dec4
lbl_0807120c: .4byte lbl_08071210
lbl_08071210: @ jump table
    .4byte lbl_08071224 @ case 0
    .4byte lbl_08071238 @ case 1
    .4byte lbl_08071242 @ case 2
    .4byte lbl_0807124c @ case 3
    .4byte lbl_0807122e @ case 4
lbl_08071224:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0xc4
    movs r2, #8
    b lbl_0807125a
lbl_0807122e:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0xd3
    movs r2, #0xff
    b lbl_0807125a
lbl_08071238:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0xd1
    movs r2, #0xff
    b lbl_0807125a
lbl_08071242:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0xc9
    movs r2, #0x20
    b lbl_0807125a
lbl_0807124c:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0xcb
    movs r2, #4
    b lbl_0807125a
lbl_08071256:
    movs r0, #0
    b lbl_0807128a
lbl_0807125a:
    ldr r0, [r3]
    adds r0, #0xc1
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r4
    ldrb r0, [r0, #1]
    adds r0, r1, r0
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807127e
    cmp r5, #0
    bne lbl_0807127a
    cmp r0, r2
    beq lbl_0807127e
lbl_08071276:
    movs r0, #1
    b lbl_0807128a
lbl_0807127a:
    cmp r0, r2
    beq lbl_08071276
lbl_0807127e:
    ldr r1, [r3]
    adds r1, #0xc1
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_080711d8
lbl_0807128a:
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start sub_08071290
sub_08071290: @ 0x08071290
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    adds r4, r2, #0
    movs r6, #0
    ldr r5, lbl_080712b8 @ =sNonGameplayRamPointer
    ldr r1, [r5]
    ldrh r0, [r1, #0x20]
    adds r3, r0, #1
    movs r7, #0
    strh r3, [r1, #0x20]
    cmp r2, #1
    beq lbl_080712d8
    cmp r2, #1
    bgt lbl_080712bc
    cmp r2, #0
    beq lbl_080712c8
    b lbl_08071414
    .align 2, 0
lbl_080712b8: .4byte sNonGameplayRamPointer
lbl_080712bc:
    cmp r4, #2
    beq lbl_08071368
    cmp r4, #3
    bne lbl_080712c6
    b lbl_080713c8
lbl_080712c6:
    b lbl_08071414
lbl_080712c8:
    strh r6, [r1, #0x20]
    adds r0, r1, #0
    adds r0, #0x22
    strb r7, [r0]
    ldr r0, [r5]
    adds r0, #0x23
    strb r7, [r0]
    b lbl_08071414
lbl_080712d8:
    movs r2, #0
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r0, [r0]
    cmp r0, #1
    bhi lbl_0807131c
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #3
    bls lbl_0807135c
    strh r6, [r1, #0x20]
    adds r0, r1, #0
    adds r0, #0x22
    ldrb r1, [r0]
    adds r1, #1
    strb r1, [r0]
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x22
    ldrb r0, [r0]
    cmp r0, #7
    bls lbl_08071314
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r1, [r0]
    adds r1, #1
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0x22
    strb r7, [r0]
lbl_08071314:
    ldr r1, lbl_08071318 @ =0x0840df64
    b lbl_0807134c
    .align 2, 0
lbl_08071318: .4byte 0x0840df64
lbl_0807131c:
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #2
    bls lbl_0807135c
    strh r6, [r1, #0x20]
    adds r1, #0x22
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x22
    ldrb r0, [r1]
    cmp r0, #5
    bls lbl_0807134a
    movs r0, #5
    strb r0, [r1]
    ldr r1, [r5]
    adds r1, #0x23
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    movs r6, #1
lbl_0807134a:
    ldr r1, lbl_08071364 @ =0x0840df6c
lbl_0807134c:
    ldr r0, [r5]
    adds r0, #0x22
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    adds r0, r0, r1
    ldrb r0, [r0]
    lsls r2, r0, #4
lbl_0807135c:
    cmp r2, #0
    beq lbl_08071414
    lsls r1, r2, #1
    b lbl_0807139e
    .align 2, 0
lbl_08071364: .4byte 0x0840df6c
lbl_08071368:
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #1
    bls lbl_08071414
    strh r6, [r1, #0x20]
    adds r1, #0x22
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x22
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r0, #0
    bne lbl_0807138c
    strb r7, [r1]
    movs r6, #1
lbl_0807138c:
    ldr r1, lbl_080713bc @ =0x0840df6c
    ldr r0, [r5]
    adds r0, #0x22
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    adds r0, r0, r1
    ldrb r1, [r0]
    lsls r1, r1, #5
lbl_0807139e:
    ldr r0, lbl_080713c0 @ =0x0840dd10
    adds r1, r1, r0
    ldr r0, lbl_080713c4 @ =0x08754bbc
    ldr r2, [r0]
    movs r0, #0xc0
    lsls r0, r0, #1
    adds r2, r2, r0
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DmaTransfer
    b lbl_08071414
    .align 2, 0
lbl_080713bc: .4byte 0x0840df6c
lbl_080713c0: .4byte 0x0840dd10
lbl_080713c4: .4byte 0x08754bbc
lbl_080713c8:
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #3
    bls lbl_08071414
    strh r6, [r1, #0x20]
    adds r1, #0x22
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x22
    ldrb r0, [r1]
    cmp r0, #3
    bls lbl_080713e8
    strb r7, [r1]
lbl_080713e8:
    ldr r1, lbl_08071420 @ =0x0840df72
    ldr r0, [r5]
    adds r0, #0x22
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    adds r0, r0, r1
    ldrb r1, [r0]
    lsls r1, r1, #5
    ldr r0, lbl_08071424 @ =0x0840ddd0
    adds r1, r1, r0
    ldr r0, lbl_08071428 @ =0x08754bbc
    ldr r2, [r0]
    movs r0, #0xc0
    lsls r0, r0, #1
    adds r2, r2, r0
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DmaTransfer
lbl_08071414:
    adds r0, r6, #0
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08071420: .4byte 0x0840df72
lbl_08071424: .4byte 0x0840ddd0
lbl_08071428: .4byte 0x08754bbc

    thumb_func_start StatusScreenFullyPoweredItems
StatusScreenFullyPoweredItems: @ 0x0807142c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r0, lbl_08071448 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrb r1, [r2, #0xc]
    adds r7, r0, #0
    cmp r1, #0
    beq lbl_0807144c
    bl unk_68ec0
    b lbl_080717f0
    .align 2, 0
lbl_08071448: .4byte sNonGameplayRamPointer
lbl_0807144c:
    ldrb r0, [r2, #8]
    cmp r0, #0xb
    bls lbl_08071454
    b lbl_080717ec
lbl_08071454:
    lsls r0, r0, #2
    ldr r1, lbl_08071460 @ =lbl_08071464
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08071460: .4byte lbl_08071464
lbl_08071464: @ jump table
    .4byte lbl_08071494 @ case 0
    .4byte lbl_080714ac @ case 1
    .4byte lbl_080714d2 @ case 2
    .4byte lbl_0807150c @ case 3
    .4byte lbl_0807159c @ case 4
    .4byte lbl_080715e4 @ case 5
    .4byte lbl_08071680 @ case 6
    .4byte lbl_08071724 @ case 7
    .4byte lbl_08071684 @ case 8
    .4byte lbl_08071744 @ case 9
    .4byte lbl_080717a6 @ case 10
    .4byte lbl_080717ec @ case 11
lbl_08071494:
    ldr r0, [r7]
    ldrh r0, [r0, #0xa]
    cmp r0, #0x32
    bhi lbl_0807149e
    b lbl_080717f0
lbl_0807149e:
    movs r0, #2
    bl PauseScreenUpdateWireframeSamus
    ldr r1, [r7]
    movs r0, #0
    strh r0, [r1, #0xa]
    b lbl_080714ca
lbl_080714ac:
    ldr r1, [r7]
    ldrh r0, [r1, #0xa]
    cmp r0, #0x1e
    bhi lbl_080714b6
    b lbl_080717f0
lbl_080714b6:
    adds r0, r1, #0
    adds r0, #0xc1
    movs r2, #0
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r7]
    adds r0, #0xea
    strb r1, [r0]
    ldr r1, [r7]
    strh r2, [r1, #0xa]
lbl_080714ca:
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    b lbl_080717f0
lbl_080714d2:
    movs r0, #0
    bl sub_080711d0
    adds r5, r0, #0
    cmp r5, #2
    bne lbl_080714fa
    ldr r2, lbl_08071504 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0xc1
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0xea
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080714fa
    ldr r0, lbl_08071508 @ =0x00000215
    movs r1, #0xf
    bl SoundFade
lbl_080714fa:
    ldr r3, lbl_08071504 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldrb r0, [r1, #8]
    adds r0, r0, r5
    b lbl_08071736
    .align 2, 0
lbl_08071504: .4byte sNonGameplayRamPointer
lbl_08071508: .4byte 0x00000215
lbl_0807150c:
    ldr r1, [r7]
    ldrh r0, [r1, #0xa]
    cmp r0, #6
    bhi lbl_08071516
    b lbl_080717f0
lbl_08071516:
    ldr r2, lbl_08071558 @ =0x0840dec4
    adds r0, r1, #0
    adds r0, #0xc1
    ldrb r1, [r0]
    lsls r1, r1, #2
    adds r1, r1, r2
    ldrb r0, [r1]
    ldrb r1, [r1, #2]
    movs r2, #1
    movs r3, #1
    bl sub_08070e1c
    ldr r0, [r7]
    adds r0, #0xc1
    ldrb r0, [r0]
    bl sub_08071a3c
    ldr r0, [r7]
    movs r1, #0x84
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #0xd
    bl UpdateMenuOamDataID
    ldr r0, [r7]
    adds r2, r0, #0
    adds r2, #0xc1
    ldrb r1, [r2]
    cmp r1, #7
    bls lbl_0807155c
    adds r0, #0xc3
    b lbl_0807155e
    .align 2, 0
lbl_08071558: .4byte 0x0840dec4
lbl_0807155c:
    adds r0, #0xc2
lbl_0807155e:
    strb r1, [r0]
    ldr r4, lbl_08071594 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0xea
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807157a
    ldr r0, lbl_08071598 @ =0x00000215
    bl SoundPlay
    ldr r0, [r4]
    adds r0, #0xea
    movs r1, #0
    strb r1, [r0]
lbl_0807157a:
    ldr r1, [r4]
    adds r1, #0xc1
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r1, [r4]
    ldrb r0, [r1, #8]
    subs r0, #1
    strb r0, [r1, #8]
    ldr r0, [r4]
    strh r2, [r0, #0xa]
    b lbl_080717f0
    .align 2, 0
lbl_08071594: .4byte sNonGameplayRamPointer
lbl_08071598: .4byte 0x00000215
lbl_0807159c:
    movs r0, #1
    bl sub_080711d0
    adds r5, r0, #0
    cmp r5, #1
    bne lbl_080715cc
    ldr r2, lbl_080715c4 @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r0, lbl_080715c8 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrb r0, [r1, #8]
    adds r0, #1
    b lbl_080715d2
    .align 2, 0
lbl_080715c4: .4byte 0x06007800
lbl_080715c8: .4byte sNonGameplayRamPointer
lbl_080715cc:
    ldr r0, lbl_080715e0 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #0xa
lbl_080715d2:
    strb r0, [r1, #8]
    ldr r0, lbl_080715e0 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #0
    strh r0, [r1, #0xa]
    b lbl_080717f0
    .align 2, 0
lbl_080715e0: .4byte sNonGameplayRamPointer
lbl_080715e4:
    ldr r0, lbl_08071678 @ =0x0840dec4
    ldr r1, [r7]
    adds r1, #0xc1
    ldrb r1, [r1]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldrb r0, [r1]
    movs r5, #0x2f
    cmp r0, #0
    beq lbl_08071600
    movs r5, #0x31
    cmp r0, #2
    bne lbl_08071600
    movs r5, #0x33
lbl_08071600:
    ldr r0, [r7]
    movs r4, #0xd4
    lsls r4, r4, #1
    adds r0, r0, r4
    adds r1, r5, #0
    bl UpdateMenuOamDataID
    ldr r5, [r7]
    ldr r3, lbl_0807167c @ =0x0840de50
    ldr r6, lbl_08071678 @ =0x0840dec4
    movs r2, #0xc1
    adds r2, r2, r5
    mov ip, r2
    ldrb r1, [r2]
    lsls r1, r1, #2
    adds r1, r1, r6
    ldrb r2, [r1]
    lsls r0, r2, #2
    adds r0, r0, r2
    adds r0, r0, r3
    ldrb r0, [r0]
    ldrb r1, [r1, #2]
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r4, r5, r4
    movs r1, #0
    mov r8, r1
    strh r0, [r4]
    mov r2, ip
    ldrb r0, [r2]
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r1, [r0]
    lsls r0, r1, #2
    adds r0, r0, r1
    adds r3, #2
    adds r0, r0, r3
    ldrb r0, [r0]
    adds r0, #1
    lsls r0, r0, #5
    movs r2, #0xd5
    lsls r2, r2, #1
    adds r1, r5, r2
    strh r0, [r1]
    movs r0, #0
    bl sub_08071290
    movs r0, #0x85
    lsls r0, r0, #2
    bl SoundPlay
    ldr r1, [r7]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    ldr r0, [r7]
    mov r1, r8
    strh r1, [r0, #0xa]
    b lbl_080717f0
    .align 2, 0
lbl_08071678: .4byte 0x0840dec4
lbl_0807167c: .4byte 0x0840de50
lbl_08071680:
    movs r0, #1
    b lbl_08071726
lbl_08071684:
    ldr r2, lbl_080716c8 @ =0x0840dec4
    ldr r4, lbl_080716cc @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r1, [r0]
    lsls r1, r1, #2
    adds r1, r1, r2
    ldrb r0, [r1]
    ldrb r1, [r1, #2]
    bl sub_08070ec0
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r0, [r0]
    bl sub_08071a3c
    ldr r0, [r4]
    movs r2, #0x84
    lsls r2, r2, #1
    adds r0, r0, r2
    movs r1, #6
    bl UpdateMenuOamDataID
    ldr r0, lbl_080716d0 @ =0x000001f7
    bl SoundPlay
    ldr r0, [r4]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r1, [r1]
    cmp r1, #7
    bls lbl_080716d4
    adds r0, #0xc3
    b lbl_080716d6
    .align 2, 0
lbl_080716c8: .4byte 0x0840dec4
lbl_080716cc: .4byte sNonGameplayRamPointer
lbl_080716d0: .4byte 0x000001f7
lbl_080716d4:
    adds r0, #0xc2
lbl_080716d6:
    strb r1, [r0]
    ldr r3, lbl_08071718 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldrb r0, [r1, #8]
    adds r0, #1
    movs r2, #0
    strb r0, [r1, #8]
    ldr r0, [r3]
    strh r2, [r0, #0xa]
    movs r2, #0xd9
    lsls r2, r2, #1
    adds r1, r0, r2
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r1, lbl_0807171c @ =0x0840dec4
    ldr r0, [r3]
    adds r0, #0xc1
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_080717f0
    ldr r0, lbl_08071720 @ =gEquipment
    ldrb r1, [r0, #0xf]
    movs r2, #0x20
    orrs r1, r2
    strb r1, [r0, #0xf]
    movs r0, #2
    bl PauseScreenUpdateWireframeSamus
    b lbl_080717f0
    .align 2, 0
lbl_08071718: .4byte sNonGameplayRamPointer
lbl_0807171c: .4byte 0x0840dec4
lbl_08071720: .4byte gEquipment
lbl_08071724:
    movs r0, #2
lbl_08071726:
    bl sub_08071290
    cmp r0, #0
    beq lbl_080717f0
    ldr r3, lbl_08071740 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldrb r0, [r1, #8]
    adds r0, #1
lbl_08071736:
    movs r2, #0
    strb r0, [r1, #8]
    ldr r0, [r3]
    strh r2, [r0, #0xa]
    b lbl_080717f0
    .align 2, 0
lbl_08071740: .4byte sNonGameplayRamPointer
lbl_08071744:
    movs r0, #3
    bl sub_08071290
    ldr r3, lbl_08071794 @ =gCurrentMessage
    ldrb r0, [r3, #0xe]
    cmp r0, #0
    beq lbl_080717a0
    ldr r0, lbl_08071798 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080717f0
    ldr r4, lbl_0807179c @ =sNonGameplayRamPointer
    ldr r1, [r4]
    adds r1, #0xc1
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    strb r2, [r3, #0xe]
    ldr r0, [r4]
    movs r1, #0xd4
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #0
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    movs r2, #0x84
    lsls r2, r2, #1
    adds r0, r0, r2
    movs r1, #0
    bl UpdateMenuOamDataID
    ldr r1, [r4]
    movs r0, #4
    strb r0, [r1, #8]
    b lbl_080717f0
    .align 2, 0
lbl_08071794: .4byte gCurrentMessage
lbl_08071798: .4byte gChangedInput
lbl_0807179c: .4byte sNonGameplayRamPointer
lbl_080717a0:
    bl sub_0806f680
    b lbl_080717f0
lbl_080717a6:
    ldr r0, lbl_080717c0 @ =gEquipment
    ldrb r1, [r0, #0xc]
    strb r1, [r0, #0xd]
    ldrb r1, [r0, #0xe]
    strb r1, [r0, #0xf]
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0xc3
    ldrb r2, [r0]
    cmp r2, #0
    beq lbl_080717c4
    subs r0, #2
    b lbl_080717da
    .align 2, 0
lbl_080717c0: .4byte gEquipment
lbl_080717c4:
    adds r0, r1, #0
    adds r0, #0xc2
    ldrb r3, [r0]
    adds r2, r3, #0
    cmp r2, #0
    beq lbl_080717d6
    subs r0, #1
    strb r3, [r0]
    b lbl_080717dc
lbl_080717d6:
    adds r0, r1, #0
    adds r0, #0xc1
lbl_080717da:
    strb r2, [r0]
lbl_080717dc:
    ldr r1, [r7]
    ldrb r0, [r1, #8]
    adds r0, #1
    movs r2, #0
    strb r0, [r1, #8]
    ldr r0, [r7]
    strh r2, [r0, #0xa]
    b lbl_080717f0
lbl_080717ec:
    movs r0, #1
    b lbl_080717f2
lbl_080717f0:
    movs r0, #0
lbl_080717f2:
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start StatusScreenSubroutine
StatusScreenSubroutine: @ 0x08071800
    push {r4, lr}
    ldr r0, lbl_0807182c @ =gChangedInput
    ldrh r1, [r0]
    ldr r0, lbl_08071830 @ =0x00000302
    ands r0, r1
    ldr r4, lbl_08071834 @ =sNonGameplayRamPointer
    cmp r0, #0
    beq lbl_08071838
    ldr r1, [r4]
    ldrb r0, [r1, #8]
    cmp r0, #0
    bne lbl_08071838
    ldrb r2, [r1, #0xc]
    cmp r2, #0
    bne lbl_08071840
    movs r0, #0xc
    strb r0, [r1, #4]
    ldr r0, [r4]
    movs r1, #0
    strh r2, [r0, #0xa]
    strb r1, [r0, #8]
    b lbl_0807188e
    .align 2, 0
lbl_0807182c: .4byte gChangedInput
lbl_08071830: .4byte 0x00000302
lbl_08071834: .4byte sNonGameplayRamPointer
lbl_08071838:
    ldr r1, [r4]
    ldrb r0, [r1, #0xc]
    cmp r0, #0
    beq lbl_08071846
lbl_08071840:
    bl unk_68ec0
    b lbl_0807188a
lbl_08071846:
    adds r0, r1, #0
    adds r0, #0xc1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807188a
    movs r0, #4
    bl check_select_pressed_on_status_screen
    cmp r0, #0
    beq lbl_08071886
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r0, [r0]
    movs r1, #1
    bl sub_08071b2c
    cmp r0, #1
    bne lbl_08071878
    ldr r0, lbl_08071874 @ =0x000001f7
    bl SoundPlay
    b lbl_0807188a
    .align 2, 0
lbl_08071874: .4byte 0x000001f7
lbl_08071878:
    cmp r0, #0
    bne lbl_0807188a
    movs r0, #0xfc
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0807188a
lbl_08071886:
    bl sub_08071dc0
lbl_0807188a:
    bl sub_0806f680
lbl_0807188e:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start get_current_equipment_selected
get_current_equipment_selected: @ 0x08071894
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    movs r3, #0x80
    lsrs r2, r0, #0x18
    movs r1, #0xff
    lsls r1, r1, #0x18
    adds r0, r0, r1
    lsrs r0, r0, #0x18
    cmp r0, #0x10
    bls lbl_080718ac
    movs r0, #0x80
    b lbl_08071a34
lbl_080718ac:
    ldr r0, lbl_080718d4 @ =gEquipment
    ldrb r1, [r0, #0x12]
    adds r5, r0, #0
    cmp r1, #2
    bne lbl_080718b8
    b lbl_08071a30
lbl_080718b8:
    ldr r0, lbl_080718d8 @ =0x0840dec4
    lsls r2, r2, #2
    adds r1, r2, r0
    ldrb r1, [r1]
    adds r4, r0, #0
    cmp r1, #4
    bls lbl_080718c8
    b lbl_08071a32
lbl_080718c8:
    lsls r0, r1, #2
    ldr r1, lbl_080718dc @ =lbl_080718e0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080718d4: .4byte gEquipment
lbl_080718d8: .4byte 0x0840dec4
lbl_080718dc: .4byte lbl_080718e0
lbl_080718e0: @ jump table
    .4byte lbl_080718f4 @ case 0
    .4byte lbl_08071970 @ case 1
    .4byte lbl_08071990 @ case 2
    .4byte lbl_080719c8 @ case 3
    .4byte lbl_08071950 @ case 4
lbl_080718f4:
    ldr r0, lbl_08071914 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r1, r2, r4
    adds r0, #0xc4
    ldrb r1, [r1, #1]
    adds r0, r0, r1
    ldrb r1, [r0]
    cmp r1, #0
    bne lbl_08071908
    b lbl_08071a32
lbl_08071908:
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08071918
    movs r3, #0
    b lbl_08071a32
    .align 2, 0
lbl_08071914: .4byte sNonGameplayRamPointer
lbl_08071918:
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08071924
    movs r3, #1
    b lbl_08071a32
lbl_08071924:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08071930
    movs r3, #2
    b lbl_08071a32
lbl_08071930:
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0807193c
    movs r3, #3
    b lbl_08071a32
lbl_0807193c:
    movs r0, #8
    ands r1, r0
    cmp r1, #0
    beq lbl_08071a32
    ldrb r0, [r5, #0x12]
    movs r3, #0x11
    cmp r0, #1
    bne lbl_08071a32
    movs r3, #4
    b lbl_08071a32
lbl_08071950:
    ldr r0, lbl_0807196c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r1, r2, r4
    ldrb r2, [r1, #1]
    adds r0, #0xd3
    adds r0, r0, r2
    ldrb r1, [r0]
    cmp r1, #0
    beq lbl_08071a32
    movs r3, #6
    cmp r2, #0
    bne lbl_08071a32
    movs r3, #5
    b lbl_08071a32
    .align 2, 0
lbl_0807196c: .4byte sNonGameplayRamPointer
lbl_08071970:
    ldr r0, lbl_0807198c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r1, r2, r4
    ldrb r2, [r1, #1]
    adds r0, #0xd1
    adds r0, r0, r2
    ldrb r1, [r0]
    cmp r1, #0
    beq lbl_08071a32
    movs r3, #8
    cmp r2, #0
    bne lbl_08071a32
    movs r3, #7
    b lbl_08071a32
    .align 2, 0
lbl_0807198c: .4byte sNonGameplayRamPointer
lbl_08071990:
    ldr r0, lbl_080719b0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r1, r2, r4
    adds r0, #0xc9
    ldrb r1, [r1, #1]
    adds r0, r0, r1
    ldrb r1, [r0]
    cmp r1, #0
    beq lbl_08071a32
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_080719b4
    movs r3, #9
    b lbl_08071a32
    .align 2, 0
lbl_080719b0: .4byte sNonGameplayRamPointer
lbl_080719b4:
    movs r0, #0x20
    ands r1, r0
    cmp r1, #0
    beq lbl_08071a32
    ldrb r0, [r5, #0x12]
    movs r3, #0x11
    cmp r0, #1
    bne lbl_08071a32
    movs r3, #0xa
    b lbl_08071a32
lbl_080719c8:
    ldr r0, lbl_080719e8 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r1, r2, r4
    adds r0, #0xcb
    ldrb r1, [r1, #1]
    adds r0, r0, r1
    ldrb r1, [r0]
    cmp r1, #0
    beq lbl_08071a32
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_080719ec
    movs r3, #0xb
    b lbl_08071a32
    .align 2, 0
lbl_080719e8: .4byte sNonGameplayRamPointer
lbl_080719ec:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_080719f8
    movs r3, #0xc
    b lbl_08071a32
lbl_080719f8:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08071a04
    movs r3, #0xd
    b lbl_08071a32
lbl_08071a04:
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08071a10
    movs r3, #0xe
    b lbl_08071a32
lbl_08071a10:
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08071a1c
    movs r3, #0xf
    b lbl_08071a32
lbl_08071a1c:
    movs r0, #4
    ands r1, r0
    cmp r1, #0
    beq lbl_08071a32
    ldrb r0, [r5, #0x12]
    movs r3, #0x11
    cmp r0, #1
    bne lbl_08071a32
    movs r3, #0x10
    b lbl_08071a32
lbl_08071a30:
    movs r3, #0x12
lbl_08071a32:
    adds r0, r3, #0
lbl_08071a34:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_08071a3c
sub_08071a3c: @ 0x08071a3c
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    ldr r3, lbl_08071a80 @ =0x0840de50
    ldr r1, lbl_08071a84 @ =0x0840dec4
    lsrs r0, r0, #0x16
    adds r0, r0, r1
    ldrb r1, [r0]
    lsls r2, r1, #2
    adds r2, r2, r1
    adds r1, r2, r3
    ldrb r4, [r1]
    ldrb r0, [r0, #2]
    adds r4, r4, r0
    adds r3, #2
    adds r2, r2, r3
    ldrb r0, [r2]
    adds r0, #1
    ldr r1, lbl_08071a88 @ =sNonGameplayRamPointer
    ldr r3, [r1]
    lsls r2, r4, #5
    movs r5, #0x84
    lsls r5, r5, #1
    adds r1, r3, r5
    strh r2, [r1]
    lsls r1, r0, #5
    adds r5, #2
    adds r2, r3, r5
    strh r1, [r2]
    lsls r0, r0, #0x10
    orrs r0, r4
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08071a80: .4byte 0x0840de50
lbl_08071a84: .4byte 0x0840dec4
lbl_08071a88: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08071a8c
sub_08071a8c: @ 0x08071a8c
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    movs r4, #0
    ldr r1, lbl_08071aac @ =0x0840dec4
    lsls r0, r2, #2
    adds r0, r0, r1
    ldrb r0, [r0]
    adds r3, r1, #0
    cmp r0, #4
    bhi lbl_08071b1e
    lsls r0, r0, #2
    ldr r1, lbl_08071ab0 @ =lbl_08071ab4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08071aac: .4byte 0x0840dec4
lbl_08071ab0: .4byte lbl_08071ab4
lbl_08071ab4: @ jump table
    .4byte lbl_08071ac8 @ case 0
    .4byte lbl_08071ae8 @ case 1
    .4byte lbl_08071af8 @ case 2
    .4byte lbl_08071b08 @ case 3
    .4byte lbl_08071ad8 @ case 4
lbl_08071ac8:
    ldr r0, lbl_08071ad4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    lsls r0, r2, #2
    adds r0, r0, r3
    adds r1, #0xc4
    b lbl_08071b12
    .align 2, 0
lbl_08071ad4: .4byte sNonGameplayRamPointer
lbl_08071ad8:
    ldr r0, lbl_08071ae4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    lsls r0, r2, #2
    adds r0, r0, r3
    adds r1, #0xd3
    b lbl_08071b12
    .align 2, 0
lbl_08071ae4: .4byte sNonGameplayRamPointer
lbl_08071ae8:
    ldr r0, lbl_08071af4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    lsls r0, r2, #2
    adds r0, r0, r3
    adds r1, #0xd1
    b lbl_08071b12
    .align 2, 0
lbl_08071af4: .4byte sNonGameplayRamPointer
lbl_08071af8:
    ldr r0, lbl_08071b04 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    lsls r0, r2, #2
    adds r0, r0, r3
    adds r1, #0xc9
    b lbl_08071b12
    .align 2, 0
lbl_08071b04: .4byte sNonGameplayRamPointer
lbl_08071b08:
    ldr r0, lbl_08071b28 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    lsls r0, r2, #2
    adds r0, r0, r3
    adds r1, #0xcb
lbl_08071b12:
    ldrb r0, [r0, #1]
    adds r1, r1, r0
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08071b1e
    movs r4, #1
lbl_08071b1e:
    adds r0, r4, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08071b28: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08071b2c
sub_08071b2c: @ 0x08071b2c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r7, r1, #0x18
    movs r6, #0
    ldr r1, lbl_08071b58 @ =0x0840dec4
    lsls r0, r4, #2
    adds r0, r0, r1
    ldrb r0, [r0]
    mov ip, r1
    ldr r2, lbl_08071b5c @ =sNonGameplayRamPointer
    cmp r0, #4
    bhi lbl_08071c1a
    lsls r0, r0, #2
    ldr r1, lbl_08071b60 @ =lbl_08071b64
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08071b58: .4byte 0x0840dec4
lbl_08071b5c: .4byte sNonGameplayRamPointer
lbl_08071b60: .4byte lbl_08071b64
lbl_08071b64: @ jump table
    .4byte lbl_08071b78 @ case 0
    .4byte lbl_08071b9c @ case 1
    .4byte lbl_08071bc8 @ case 2
    .4byte lbl_08071bfc @ case 3
    .4byte lbl_08071c1a @ case 4
lbl_08071b78:
    ldr r2, lbl_08071b94 @ =sNonGameplayRamPointer
    ldr r1, [r2]
    lsls r0, r4, #2
    add r0, ip
    adds r1, #0xc4
    ldrb r0, [r0, #1]
    adds r1, r1, r0
    ldrb r6, [r1]
    ldr r5, lbl_08071b98 @ =gEquipment+0xD
    cmp r6, #8
    bne lbl_08071c1a
    ldrb r0, [r5, #5]
    b lbl_08071c14
    .align 2, 0
lbl_08071b94: .4byte sNonGameplayRamPointer
lbl_08071b98: .4byte gEquipment+0xD
lbl_08071b9c:
    ldr r2, lbl_08071bc0 @ =sNonGameplayRamPointer
    cmp r4, #8
    bne lbl_08071c1a
    ldr r3, lbl_08071bc4 @ =gEquipment
    ldrb r1, [r3, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08071c1a
    ldrb r1, [r3, #0xd]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_08071c1a
    movs r6, #0x80
    adds r5, r3, #0
    adds r5, #0xd
    b lbl_08071c1a
    .align 2, 0
lbl_08071bc0: .4byte sNonGameplayRamPointer
lbl_08071bc4: .4byte gEquipment
lbl_08071bc8:
    ldr r2, lbl_08071bf4 @ =sNonGameplayRamPointer
    ldr r1, [r2]
    lsls r0, r4, #2
    add r0, ip
    adds r1, #0xc9
    ldrb r0, [r0, #1]
    adds r1, r1, r0
    ldrb r6, [r1]
    ldr r5, lbl_08071bf8 @ =gEquipment+0xF
    cmp r6, #0x20
    bne lbl_08071be6
    ldrb r0, [r5, #3]
    cmp r0, #1
    beq lbl_08071be6
    movs r6, #0
lbl_08071be6:
    cmp r6, #0
    beq lbl_08071c1a
    ldrb r0, [r5]
    ands r0, r6
    cmp r0, #0
    beq lbl_08071c1a
    b lbl_08071c18
    .align 2, 0
lbl_08071bf4: .4byte sNonGameplayRamPointer
lbl_08071bf8: .4byte gEquipment+0xF
lbl_08071bfc:
    ldr r2, lbl_08071c40 @ =sNonGameplayRamPointer
    ldr r1, [r2]
    lsls r0, r4, #2
    add r0, ip
    adds r1, #0xcb
    ldrb r0, [r0, #1]
    adds r1, r1, r0
    ldrb r6, [r1]
    ldr r5, lbl_08071c44 @ =gEquipment+0xF
    cmp r6, #4
    bne lbl_08071c1a
    ldrb r0, [r5, #3]
lbl_08071c14:
    cmp r0, #1
    beq lbl_08071c1a
lbl_08071c18:
    movs r6, #0
lbl_08071c1a:
    ldr r0, [r2]
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_08071c36
    ldr r0, lbl_08071c48 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #6
    beq lbl_08071c36
    movs r6, #0
lbl_08071c36:
    cmp r6, #0
    bne lbl_08071c4c
    movs r3, #0
    movs r7, #0xff
    b lbl_08071d8a
    .align 2, 0
lbl_08071c40: .4byte sNonGameplayRamPointer
lbl_08071c44: .4byte gEquipment+0xF
lbl_08071c48: .4byte gPauseScreenFlag
lbl_08071c4c:
    cmp r7, #0
    beq lbl_08071c54
    cmp r7, #2
    bne lbl_08071c64
lbl_08071c54:
    ldrb r1, [r5]
    ands r1, r6
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r7, r0, #0x1f
    lsls r4, r4, #2
    mov r8, r4
    b lbl_08071d5a
lbl_08071c64:
    ldrb r1, [r5]
    adds r0, r6, #0
    eors r0, r1
    strb r0, [r5]
    adds r1, r6, #0
    ands r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r7, r0, #0x1f
    lsls r4, r4, #2
    mov r1, ip
    adds r0, r4, r1
    ldrb r5, [r0]
    ldrb r1, [r0, #2]
    adds r0, r5, #0
    adds r2, r7, #0
    movs r3, #1
    bl sub_08070e1c
    mov r8, r4
    cmp r5, #2
    beq lbl_08071cfc
    cmp r5, #2
    bgt lbl_08071c9a
    cmp r5, #1
    beq lbl_08071d04
    b lbl_08071d5a
lbl_08071c9a:
    cmp r5, #3
    bne lbl_08071d5a
    movs r0, #0x40
    ands r0, r6
    cmp r0, #0
    beq lbl_08071d5a
    movs r3, #0
    ldr r4, lbl_08071cf8 @ =sNonGameplayRamPointer
lbl_08071caa:
    ldr r0, [r4]
    adds r0, #0xd1
    adds r2, r0, r3
    ldrb r1, [r2]
    movs r0, #1
    ands r0, r1
    adds r5, r3, #1
    cmp r0, #0
    beq lbl_08071cec
    movs r0, #7
    ands r0, r1
    strb r0, [r2]
    ldr r2, [r4]
    adds r2, #0xd1
    adds r2, r2, r3
    lsls r0, r7, #3
    ldrb r1, [r2]
    orrs r0, r1
    strb r0, [r2]
    movs r2, #0
    ldr r0, [r4]
    adds r0, #0xd1
    adds r0, r0, r3
    ldrb r0, [r0]
    cmp r0, #0xf
    bne lbl_08071ce0
    movs r2, #1
lbl_08071ce0:
    lsls r1, r5, #0x18
    lsrs r1, r1, #0x18
    movs r0, #1
    movs r3, #1
    bl sub_08070e1c
lbl_08071cec:
    lsls r0, r5, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #1
    bls lbl_08071caa
    b lbl_08071d5a
    .align 2, 0
lbl_08071cf8: .4byte sNonGameplayRamPointer
lbl_08071cfc:
    movs r0, #2
    bl PauseScreenUpdateWireframeSamus
    b lbl_08071d5a
lbl_08071d04:
    ldr r3, lbl_08071db4 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    adds r1, #0xd1
    ldrb r2, [r1]
    movs r0, #0xd
    mov ip, r0
    ands r0, r2
    strb r0, [r1]
    ldr r1, [r3]
    adds r1, #0xd1
    lsls r4, r7, #1
    ldrb r2, [r1]
    adds r0, r4, #0
    orrs r0, r2
    strb r0, [r1]
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xd2
    ldrb r1, [r2]
    ands r5, r1
    cmp r5, #0
    beq lbl_08071d5a
    mov r0, ip
    ands r0, r1
    strb r0, [r2]
    ldr r1, [r3]
    adds r1, #0xd2
    ldrb r2, [r1]
    adds r0, r4, #0
    orrs r0, r2
    strb r0, [r1]
    movs r2, #0
    ldr r0, [r3]
    adds r0, #0xd2
    ldrb r0, [r0]
    cmp r0, #0xf
    bne lbl_08071d50
    movs r2, #1
lbl_08071d50:
    movs r0, #1
    movs r1, #2
    movs r3, #1
    bl sub_08070e1c
lbl_08071d5a:
    ldr r0, lbl_08071db8 @ =0x0840dec4
    add r0, r8
    ldrb r0, [r0]
    cmp r0, #1
    blt lbl_08071d7a
    cmp r0, #2
    ble lbl_08071d78
    cmp r0, #3
    bne lbl_08071d7a
    cmp r6, #4
    bne lbl_08071d7a
    ldr r0, lbl_08071dbc @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #1
    beq lbl_08071d7a
lbl_08071d78:
    movs r7, #0xff
lbl_08071d7a:
    movs r3, #0x11
    ldr r2, lbl_08071db4 @ =sNonGameplayRamPointer
    cmp r7, #1
    beq lbl_08071d8a
    movs r3, #0
    cmp r7, #0
    bne lbl_08071d8a
    movs r3, #0x12
lbl_08071d8a:
    ldr r2, [r2]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08071d9a
    movs r3, #0
lbl_08071d9a:
    movs r1, #0x8b
    lsls r1, r1, #3
    adds r0, r2, r1
    adds r1, r3, #0
    bl UpdateMenuOamDataID
    adds r0, r7, #0
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08071db4: .4byte sNonGameplayRamPointer
lbl_08071db8: .4byte 0x0840dec4
lbl_08071dbc: .4byte gEquipment

    thumb_func_start sub_08071dc0
sub_08071dc0: @ 0x08071dc0
    push {r4, lr}
    ldr r0, lbl_08071dec @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r2, #0x89
    lsls r2, r2, #1
    adds r0, r1, r2
    ldrb r0, [r0]
    cmp r0, #6
    beq lbl_08071e70
    adds r0, r1, #0
    adds r0, #0xc1
    ldrb r2, [r0]
    ldr r0, lbl_08071df0 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08071df4
    movs r3, #1
    rsbs r3, r3, #0
    b lbl_08071e26
    .align 2, 0
lbl_08071dec: .4byte sNonGameplayRamPointer
lbl_08071df0: .4byte gChangedInput
lbl_08071df4:
    movs r0, #0x80
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    rsbs r0, r0, #0
    lsrs r3, r0, #0x1f
    cmp r3, #0
    bne lbl_08071e26
    lsls r0, r2, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #7
    bhi lbl_08071e18
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08071e22
    movs r3, #2
    b lbl_08071e26
lbl_08071e18:
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08071e22
    movs r3, #2
lbl_08071e22:
    cmp r3, #0
    beq lbl_08071e36
lbl_08071e26:
    ldr r0, lbl_08071e78 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xc1
    ldrb r1, [r0]
    adds r0, r3, #0
    bl sub_08071e7c
    adds r2, r0, #0
lbl_08071e36:
    ldr r4, lbl_08071e78 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, r2
    beq lbl_08071e70
    strb r2, [r1]
    lsls r0, r2, #0x18
    lsrs r0, r0, #0x18
    bl sub_08071a3c
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r0, [r0]
    movs r1, #0
    bl sub_08071b2c
    ldr r0, [r4]
    movs r1, #0x84
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #6
    bl UpdateMenuOamDataID
    movs r0, #0xfb
    lsls r0, r0, #1
    bl SoundPlay
lbl_08071e70:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08071e78: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08071e7c
sub_08071e7c: @ 0x08071e7c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    lsls r0, r0, #0x18
    asrs r5, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    mov r8, r4
    cmp r5, #0
    beq lbl_08071f62
    cmp r5, #1
    ble lbl_08071f26
    cmp r4, #7
    bls lbl_08071ea8
    ldr r1, lbl_08071ea4 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    adds r0, #0xc3
    b lbl_08071eae
    .align 2, 0
lbl_08071ea4: .4byte sNonGameplayRamPointer
lbl_08071ea8:
    ldr r1, lbl_08071ed4 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    adds r0, #0xc2
lbl_08071eae:
    strb r4, [r0]
    mov r0, r8
    cmp r0, #7
    bls lbl_08071edc
    ldr r0, [r1]
    adds r0, #0xc2
    ldrb r4, [r0]
    cmp r4, #0
    bne lbl_08071f62
    movs r1, #7
    movs r7, #1
    mov r0, r8
    cmp r0, #0xb
    bls lbl_08071ed8
    movs r4, #6
    movs r5, #1
    rsbs r5, r5, #0
    b lbl_08071efc
    .align 2, 0
lbl_08071ed4: .4byte sNonGameplayRamPointer
lbl_08071ed8:
    movs r4, #1
    b lbl_08071efa
lbl_08071edc:
    ldr r0, [r1]
    adds r0, #0xc3
    ldrb r4, [r0]
    cmp r4, #0
    bne lbl_08071f62
    movs r1, #0x11
    movs r7, #8
    mov r0, r8
    cmp r0, #5
    bls lbl_08071ef8
    movs r4, #0xc
    movs r5, #1
    rsbs r5, r5, #0
    b lbl_08071efc
lbl_08071ef8:
    movs r4, #8
lbl_08071efa:
    movs r5, #1
lbl_08071efc:
    adds r6, r4, #0
lbl_08071efe:
    lsls r0, r4, #0x18
    lsrs r0, r0, #0x18
    str r1, [sp]
    bl sub_08071a8c
    ldr r1, [sp]
    cmp r0, #0
    bne lbl_08071f62
    adds r4, r4, r5
    cmp r4, r7
    bge lbl_08071f18
    adds r4, r1, #0
    b lbl_08071f1e
lbl_08071f18:
    cmp r4, r1
    ble lbl_08071f1e
    adds r4, r7, #0
lbl_08071f1e:
    cmp r4, r6
    bne lbl_08071efe
lbl_08071f22:
    mov r4, r8
    b lbl_08071f62
lbl_08071f26:
    cmp r4, #7
    bls lbl_08071f30
    movs r1, #0x11
    movs r7, #8
    b lbl_08071f34
lbl_08071f30:
    movs r1, #7
    movs r7, #1
lbl_08071f34:
    cmp r5, #1
    beq lbl_08071f3c
    movs r0, #1
    rsbs r0, r0, #0
lbl_08071f3c:
    adds r6, r4, #0
lbl_08071f3e:
    adds r4, r4, r5
    cmp r4, r7
    bge lbl_08071f48
    adds r4, r1, #0
    b lbl_08071f4e
lbl_08071f48:
    cmp r4, r1
    ble lbl_08071f4e
    adds r4, r7, #0
lbl_08071f4e:
    cmp r4, r6
    beq lbl_08071f22
    lsls r0, r4, #0x18
    lsrs r0, r0, #0x18
    str r1, [sp]
    bl sub_08071a8c
    ldr r1, [sp]
    cmp r0, #0
    beq lbl_08071f3e
lbl_08071f62:
    adds r0, r4, #0
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
